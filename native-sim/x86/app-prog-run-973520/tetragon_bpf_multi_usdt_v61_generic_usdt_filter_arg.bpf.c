extern char addr4lpm_maps;
extern char addr6lpm_maps;
extern char argfilter_maps;
extern char filter_map;
extern char heap_ro_zero;
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
extern char usdt_calls;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_multi_usdt_v61_generic_usdt_filter_arg_x86_chunk_0(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 0ULL: goto x86_l_0;
	case 1ULL: goto x86_l_1;
	case 3ULL: goto x86_l_3;
	case 7ULL: goto x86_l_7;
	case 10ULL: goto x86_l_a;
	case 18ULL: goto x86_l_12;
	case 23ULL: goto x86_l_17;
	case 30ULL: goto x86_l_1e;
	case 35ULL: goto x86_l_23;
	case 37ULL: goto x86_l_25;
	case 40ULL: goto x86_l_28;
	case 46ULL: goto x86_l_2e;
	case 49ULL: goto x86_l_31;
	case 56ULL: goto x86_l_38;
	case 63ULL: goto x86_l_3f;
	case 68ULL: goto x86_l_44;
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
	case 939ULL: goto x86_l_3ab;
	case 946ULL: goto x86_l_3b2;
	case 949ULL: goto x86_l_3b5;
	case 954ULL: goto x86_l_3ba;
	case 956ULL: goto x86_l_3bc;
	case 961ULL: goto x86_l_3c1;
	case 968ULL: goto x86_l_3c8;
	case 971ULL: goto x86_l_3cb;
	case 976ULL: goto x86_l_3d0;
	case 978ULL: goto x86_l_3d2;
	case 980ULL: goto x86_l_3d4;
	case 984ULL: goto x86_l_3d8;
	case 986ULL: goto x86_l_3da;
	case 987ULL: goto x86_l_3db;
	case 992ULL: goto x86_l_3e0;
	case 995ULL: goto x86_l_3e3;
	case 1003ULL: goto x86_l_3eb;
	case 1005ULL: goto x86_l_3ed;
	case 1011ULL: goto x86_l_3f3;
	case 1019ULL: goto x86_l_3fb;
	case 1021ULL: goto x86_l_3fd;
	case 1027ULL: goto x86_l_403;
	case 1035ULL: goto x86_l_40b;
	case 1037ULL: goto x86_l_40d;
	case 1043ULL: goto x86_l_413;
	case 1051ULL: goto x86_l_41b;
	case 1053ULL: goto x86_l_41d;
	case 1059ULL: goto x86_l_423;
	case 1067ULL: goto x86_l_42b;
	case 1069ULL: goto x86_l_42d;
	case 1075ULL: goto x86_l_433;
	case 1083ULL: goto x86_l_43b;
	case 1085ULL: goto x86_l_43d;
	case 1092ULL: goto x86_l_444;
	case 1097ULL: goto x86_l_449;
	case 1104ULL: goto x86_l_450;
	case 1107ULL: goto x86_l_453;
	case 1112ULL: goto x86_l_458;
	case 1114ULL: goto x86_l_45a;
	case 1118ULL: goto x86_l_45e;
	case 1123ULL: goto x86_l_463;
	case 1125ULL: goto x86_l_465;
	case 1130ULL: goto x86_l_46a;
	case 1135ULL: goto x86_l_46f;
	case 1140ULL: goto x86_l_474;
	case 1147ULL: goto x86_l_47b;
	case 1152ULL: goto x86_l_480;
	case 1154ULL: goto x86_l_482;
	case 1157ULL: goto x86_l_485;
	case 1163ULL: goto x86_l_48b;
	case 1168ULL: goto x86_l_490;
	case 1175ULL: goto x86_l_497;
	case 1180ULL: goto x86_l_49c;
	case 1182ULL: goto x86_l_49e;
	case 1187ULL: goto x86_l_4a3;
	case 1188ULL: goto x86_l_4a4;
	case 1191ULL: goto x86_l_4a7;
	case 1193ULL: goto x86_l_4a9;
	case 1196ULL: goto x86_l_4ac;
	case 1198ULL: goto x86_l_4ae;
	case 1200ULL: goto x86_l_4b0;
	case 1202ULL: goto x86_l_4b2;
	case 1205ULL: goto x86_l_4b5;
	case 1208ULL: goto x86_l_4b8;
	case 1210ULL: goto x86_l_4ba;
	case 1212ULL: goto x86_l_4bc;
	case 1213ULL: goto x86_l_4bd;
	case 1214ULL: goto x86_l_4be;
	case 1217ULL: goto x86_l_4c1;
	case 1219ULL: goto x86_l_4c3;
	case 1221ULL: goto x86_l_4c5;
	case 1226ULL: goto x86_l_4ca;
	case 1230ULL: goto x86_l_4ce;
	case 1232ULL: goto x86_l_4d0;
	case 1237ULL: goto x86_l_4d5;
	case 1241ULL: goto x86_l_4d9;
	case 1243ULL: goto x86_l_4db;
	case 1253ULL: goto x86_l_4e5;
	case 1257ULL: goto x86_l_4e9;
	case 1259ULL: goto x86_l_4eb;
	case 1262ULL: goto x86_l_4ee;
	case 1267ULL: goto x86_l_4f3;
	case 1270ULL: goto x86_l_4f6;
	case 1273ULL: goto x86_l_4f9;
	case 1275ULL: goto x86_l_4fb;
	case 1277ULL: goto x86_l_4fd;
	case 1280ULL: goto x86_l_500;
	case 1283ULL: goto x86_l_503;
	case 1285ULL: goto x86_l_505;
	case 1289ULL: goto x86_l_509;
	case 1292ULL: goto x86_l_50c;
	case 1297ULL: goto x86_l_511;
	case 1300ULL: goto x86_l_514;
	case 1303ULL: goto x86_l_517;
	case 1305ULL: goto x86_l_519;
	case 1307ULL: goto x86_l_51b;
	case 1311ULL: goto x86_l_51f;
	case 1314ULL: goto x86_l_522;
	case 1319ULL: goto x86_l_527;
	case 1322ULL: goto x86_l_52a;
	case 1325ULL: goto x86_l_52d;
	case 1327ULL: goto x86_l_52f;
	case 1329ULL: goto x86_l_531;
	case 1333ULL: goto x86_l_535;
	case 1336ULL: goto x86_l_538;
	case 1341ULL: goto x86_l_53d;
	case 1344ULL: goto x86_l_540;
	case 1347ULL: goto x86_l_543;
	case 1349ULL: goto x86_l_545;
	case 1351ULL: goto x86_l_547;
	case 1353ULL: goto x86_l_549;
	case 1356ULL: goto x86_l_54c;
	case 1358ULL: goto x86_l_54e;
	case 1360ULL: goto x86_l_550;
	case 1370ULL: goto x86_l_55a;
	case 1374ULL: goto x86_l_55e;
	case 1376ULL: goto x86_l_560;
	case 1380ULL: goto x86_l_564;
	case 1381ULL: goto x86_l_565;
	case 1382ULL: goto x86_l_566;
	case 1383ULL: goto x86_l_567;
	case 1386ULL: goto x86_l_56a;
	case 1388ULL: goto x86_l_56c;
	case 1392ULL: goto x86_l_570;
	case 1394ULL: goto x86_l_572;
	case 1399ULL: goto x86_l_577;
	case 1403ULL: goto x86_l_57b;
	case 1405ULL: goto x86_l_57d;
	case 1410ULL: goto x86_l_582;
	case 1411ULL: goto x86_l_583;
	case 1412ULL: goto x86_l_584;
	case 1417ULL: goto x86_l_589;
	case 1421ULL: goto x86_l_58d;
	case 1423ULL: goto x86_l_58f;
	case 1433ULL: goto x86_l_599;
	case 1437ULL: goto x86_l_59d;
	case 1439ULL: goto x86_l_59f;
	case 1444ULL: goto x86_l_5a4;
	case 1445ULL: goto x86_l_5a5;
	case 1446ULL: goto x86_l_5a6;
	case 1451ULL: goto x86_l_5ab;
	case 1452ULL: goto x86_l_5ac;
	case 1453ULL: goto x86_l_5ad;
	case 1455ULL: goto x86_l_5af;
	case 1457ULL: goto x86_l_5b1;
	case 1459ULL: goto x86_l_5b3;
	case 1460ULL: goto x86_l_5b4;
	case 1464ULL: goto x86_l_5b8;
	case 1473ULL: goto x86_l_5c1;
	case 1482ULL: goto x86_l_5ca;
	case 1491ULL: goto x86_l_5d3;
	case 1500ULL: goto x86_l_5dc;
	case 1509ULL: goto x86_l_5e5;
	case 1516ULL: goto x86_l_5ec;
	case 1524ULL: goto x86_l_5f4;
	case 1527ULL: goto x86_l_5f7;
	case 1529ULL: goto x86_l_5f9;
	case 1532ULL: goto x86_l_5fc;
	case 1534ULL: goto x86_l_5fe;
	case 1537ULL: goto x86_l_601;
	case 1543ULL: goto x86_l_607;
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
	/* 0x12: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_17:
	/* 0x17: mov    rdi,QWORD PTR [rip+0x5987] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_1e:
	/* 0x1e: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_23:
	/* 0x23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25:
	/* 0x25: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_28:
	/* 0x28: je     3d2 <generic_usdt_filter_arg+0x3d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3d2;
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
	/* 0x3f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_44:
	/* 0x44: mov    rdi,QWORD PTR [rip+0x5987] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&filter_map)));
x86_l_4b:
	/* 0x4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d:
	/* 0x4d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_50:
	/* 0x50: je     3bc <generic_usdt_filter_arg+0x3bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3bc;
	}
x86_l_56:
	/* 0x56: cmp    BYTE PTR [r14+0x5ee0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104316165685248ULL);
x86_l_5e:
	/* 0x5e: je     3bc <generic_usdt_filter_arg+0x3bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3bc;
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
	/* 0x76: je     105 <generic_usdt_filter_arg+0x105> */
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
	/* 0xed: jae    15a <generic_usdt_filter_arg+0x15a> */
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
	/* 0xf7: je     3bc <generic_usdt_filter_arg+0x3bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3bc;
	}
x86_l_fd:
	/* 0xfd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ff:
	/* 0xff: jne    39b <generic_usdt_filter_arg+0x39b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_39b;
	}
x86_l_105:
	/* 0x105: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_109:
	/* 0x109: jg     12a <generic_usdt_filter_arg+0x12a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_12a;
	}
x86_l_10b:
	/* 0x10b: cmp    r12d,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4294967295ULL);
x86_l_10f:
	/* 0x10f: je     3e0 <generic_usdt_filter_arg+0x3e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e0;
	}
x86_l_115:
	/* 0x115: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_118:
	/* 0x118: je     3ed <generic_usdt_filter_arg+0x3ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ed;
	}
x86_l_11e:
	/* 0x11e: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_122:
	/* 0x122: je     3fd <generic_usdt_filter_arg+0x3fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3fd;
	}
x86_l_128:
	/* 0x128: jmp    148 <generic_usdt_filter_arg+0x148> */
	goto x86_l_148;
x86_l_12a:
	/* 0x12a: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_12e:
	/* 0x12e: je     40d <generic_usdt_filter_arg+0x40d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40d;
	}
x86_l_134:
	/* 0x134: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_138:
	/* 0x138: je     41d <generic_usdt_filter_arg+0x41d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_41d;
	}
x86_l_13e:
	/* 0x13e: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_142:
	/* 0x142: je     42d <generic_usdt_filter_arg+0x42d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_42d;
	}
x86_l_148:
	/* 0x148: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_14c:
	/* 0x14c: jg     45a <generic_usdt_filter_arg+0x45a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_45a;
	}
x86_l_152:
	/* 0x152: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_155:
	/* 0x155: jmp    43d <generic_usdt_filter_arg+0x43d> */
	goto x86_l_43d;
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
	/* 0x17b: je     ef <generic_usdt_filter_arg+0xef> */
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
	/* 0x191: je     105 <generic_usdt_filter_arg+0x105> */
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
	/* 0x1a0: ja     105 <generic_usdt_filter_arg+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_105;
	}
x86_l_1a6:
	/* 0x1a6: cmp    DWORD PTR [r14+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_1af:
	/* 0x1af: jne    105 <generic_usdt_filter_arg+0x105> */
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
	/* 0x1d3: jle    1f4 <generic_usdt_filter_arg+0x1f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1f4;
	}
x86_l_1d5:
	/* 0x1d5: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_1d8:
	/* 0x1d8: jg     224 <generic_usdt_filter_arg+0x224> */
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
	/* 0x1e0: jb     26a <generic_usdt_filter_arg+0x26a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_26a;
	}
x86_l_1e6:
	/* 0x1e6: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_1e9:
	/* 0x1e9: je     34d <generic_usdt_filter_arg+0x34d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_34d;
	}
x86_l_1ef:
	/* 0x1ef: jmp    389 <generic_usdt_filter_arg+0x389> */
	goto x86_l_389;
x86_l_1f4:
	/* 0x1f4: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_1f7:
	/* 0x1f7: jle    24a <generic_usdt_filter_arg+0x24a> */
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
	/* 0x1ff: jb     26a <generic_usdt_filter_arg+0x26a> */
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
	/* 0x207: jb     34d <generic_usdt_filter_arg+0x34d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_34d;
	}
x86_l_20d:
	/* 0x20d: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_210:
	/* 0x210: jne    389 <generic_usdt_filter_arg+0x389> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_389;
	}
x86_l_216:
	/* 0x216: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_21a:
	/* 0x21a: call   0 <generic_usdt_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 543ULL);
	__x86_sim_call_depth++;
	goto x86_l_4a3;
x86_l_21f:
	/* 0x21f: jmp    380 <generic_usdt_filter_arg+0x380> */
	goto x86_l_380;
x86_l_224:
	/* 0x224: cmp    eax,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 41ULL);
x86_l_227:
	/* 0x227: jg     33c <generic_usdt_filter_arg+0x33c> */
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
	/* 0x233: jb     2f7 <generic_usdt_filter_arg+0x2f7> */
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
	/* 0x23f: jb     2ed <generic_usdt_filter_arg+0x2ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2ed;
	}
x86_l_245:
	/* 0x245: jmp    389 <generic_usdt_filter_arg+0x389> */
	goto x86_l_389;
x86_l_24a:
	/* 0x24a: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_24d:
	/* 0x24d: jg     2da <generic_usdt_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2da;
	}
x86_l_253:
	/* 0x253: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_256:
	/* 0x256: je     26a <generic_usdt_filter_arg+0x26a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26a;
	}
x86_l_258:
	/* 0x258: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_25b:
	/* 0x25b: je     36a <generic_usdt_filter_arg+0x36a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36a;
	}
x86_l_261:
	/* 0x261: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_264:
	/* 0x264: jne    389 <generic_usdt_filter_arg+0x389> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_389;
	}
x86_l_26a:
	/* 0x26a: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_26d:
	/* 0x26d: jle    2b7 <generic_usdt_filter_arg+0x2b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2b7;
	}
x86_l_26f:
	/* 0x26f: cmp    eax,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 36ULL);
x86_l_272:
	/* 0x272: ja     354 <generic_usdt_filter_arg+0x354> */
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
	/* 0x288: jb     2fe <generic_usdt_filter_arg+0x2fe> */
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
	/* 0x293: jb     363 <generic_usdt_filter_arg+0x363> */
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
	/* 0x2a7: jae    354 <generic_usdt_filter_arg+0x354> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_354;
	}
x86_l_2ad:
	/* 0x2ad: call   0 <generic_usdt_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 690ULL);
	__x86_sim_call_depth++;
	goto x86_l_566;
x86_l_2b2:
	/* 0x2b2: jmp    380 <generic_usdt_filter_arg+0x380> */
	goto x86_l_380;
x86_l_2b7:
	/* 0x2b7: lea    ecx,[rax-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_2ba:
	/* 0x2ba: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2bd:
	/* 0x2bd: jb     37b <generic_usdt_filter_arg+0x37b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_37b;
	}
x86_l_2c3:
	/* 0x2c3: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c6:
	/* 0x2c6: je     35c <generic_usdt_filter_arg+0x35c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35c;
	}
x86_l_2cc:
	/* 0x2cc: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2cf:
	/* 0x2cf: je     35c <generic_usdt_filter_arg+0x35c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35c;
	}
x86_l_2d5:
	/* 0x2d5: jmp    389 <generic_usdt_filter_arg+0x389> */
	goto x86_l_389;
x86_l_2da:
	/* 0x2da: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_2dd:
	/* 0x2dd: je     2ed <generic_usdt_filter_arg+0x2ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ed;
	}
x86_l_2df:
	/* 0x2df: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_2e2:
	/* 0x2e2: je     2f7 <generic_usdt_filter_arg+0x2f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f7;
	}
x86_l_2e4:
	/* 0x2e4: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_2e7:
	/* 0x2e7: jne    389 <generic_usdt_filter_arg+0x389> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_389;
	}
x86_l_2ed:
	/* 0x2ed: call   0 <generic_usdt_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 754ULL);
	__x86_sim_call_depth++;
	goto x86_l_5ad;
x86_l_2f2:
	/* 0x2f2: jmp    380 <generic_usdt_filter_arg+0x380> */
	goto x86_l_380;
x86_l_2f7:
	/* 0x2f7: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_2fc:
	/* 0x2fc: jmp    36f <generic_usdt_filter_arg+0x36f> */
	goto x86_l_36f;
x86_l_2fe:
	/* 0x2fe: cmp    ecx,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 30ULL);
x86_l_301:
	/* 0x301: jne    37b <generic_usdt_filter_arg+0x37b> */
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
	/* 0x314: jne    105 <generic_usdt_filter_arg+0x105> */
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
	/* 0x33a: jmp    380 <generic_usdt_filter_arg+0x380> */
	goto x86_l_380;
x86_l_33c:
	/* 0x33c: cmp    eax,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 42ULL);
x86_l_33f:
	/* 0x33f: je     34d <generic_usdt_filter_arg+0x34d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_34d;
	}
x86_l_341:
	/* 0x341: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_344:
	/* 0x344: jne    389 <generic_usdt_filter_arg+0x389> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_389;
	}
x86_l_346:
	/* 0x346: call   0 <generic_usdt_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 843ULL);
	__x86_sim_call_depth++;
	return 2283ULL;
x86_l_34b:
	/* 0x34b: jmp    380 <generic_usdt_filter_arg+0x380> */
	goto x86_l_380;
x86_l_34d:
	/* 0x34d: call   0 <generic_usdt_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 850ULL);
	__x86_sim_call_depth++;
	goto x86_l_4a3;
x86_l_352:
	/* 0x352: jmp    380 <generic_usdt_filter_arg+0x380> */
	goto x86_l_380;
x86_l_354:
	/* 0x354: lea    ecx,[rax-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_357:
	/* 0x357: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_35a:
	/* 0x35a: jae    376 <generic_usdt_filter_arg+0x376> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_376;
	}
x86_l_35c:
	/* 0x35c: call   0 <generic_usdt_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 865ULL);
	__x86_sim_call_depth++;
	return 2454ULL;
x86_l_361:
	/* 0x361: jmp    380 <generic_usdt_filter_arg+0x380> */
	goto x86_l_380;
x86_l_363:
	/* 0x363: call   0 <generic_usdt_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 872ULL);
	__x86_sim_call_depth++;
	return 2525ULL;
x86_l_368:
	/* 0x368: jmp    380 <generic_usdt_filter_arg+0x380> */
	goto x86_l_380;
x86_l_36a:
	/* 0x36a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_36f:
	/* 0x36f: call   0 <generic_usdt_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 884ULL);
	__x86_sim_call_depth++;
	return 2596ULL;
x86_l_374:
	/* 0x374: jmp    380 <generic_usdt_filter_arg+0x380> */
	goto x86_l_380;
x86_l_376:
	/* 0x376: cmp    eax,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_379:
	/* 0x379: jne    389 <generic_usdt_filter_arg+0x389> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_389;
	}
x86_l_37b:
	/* 0x37b: call   0 <generic_usdt_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 896ULL);
	__x86_sim_call_depth++;
	return 2759ULL;
x86_l_380:
	/* 0x380: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_383:
	/* 0x383: je     105 <generic_usdt_filter_arg+0x105> */
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
	/* 0x390: jne    16c <generic_usdt_filter_arg+0x16c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_16c;
	}
x86_l_396:
	/* 0x396: jmp    ef <generic_usdt_filter_arg+0xef> */
	goto x86_l_ef;
x86_l_39b:
	/* 0x39b: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_39f:
	/* 0x39f: mov    DWORD PTR [r14+0x5f04],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24324ULL);
x86_l_3a6:
	/* 0x3a6: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_3ab:
	/* 0x3ab: mov    rsi,QWORD PTR [rip+0x59a0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&usdt_calls)));
x86_l_3b2:
	/* 0x3b2: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3b5:
	/* 0x3b5: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_3ba:
	/* 0x3ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3bc:
	/* 0x3bc: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_3c1:
	/* 0x3c1: mov    rsi,QWORD PTR [rip+0x59a0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&usdt_calls)));
x86_l_3c8:
	/* 0x3c8: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3cb:
	/* 0x3cb: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_3d0:
	/* 0x3d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d2:
	/* 0x3d2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3d4:
	/* 0x3d4: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_3d8:
	/* 0x3d8: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_3da:
	/* 0x3da: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_3db:
	/* 0x3db: jmp    2458 <filter_file_type+0x91> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_3e0:
	/* 0x3e0: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3e3:
	/* 0x3e3: cmp    BYTE PTR [r14+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104183021699072ULL);
x86_l_3eb:
	/* 0x3eb: jne    43d <generic_usdt_filter_arg+0x43d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_43d;
	}
x86_l_3ed:
	/* 0x3ed: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_3f3:
	/* 0x3f3: cmp    BYTE PTR [r14+0x5ec2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104187316666368ULL);
x86_l_3fb:
	/* 0x3fb: jne    43d <generic_usdt_filter_arg+0x43d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_43d;
	}
x86_l_3fd:
	/* 0x3fd: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_403:
	/* 0x403: cmp    BYTE PTR [r14+0x5ec3],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104191611633664ULL);
x86_l_40b:
	/* 0x40b: jne    43d <generic_usdt_filter_arg+0x43d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_43d;
	}
x86_l_40d:
	/* 0x40d: mov    r12d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 3ULL);
x86_l_413:
	/* 0x413: cmp    BYTE PTR [r14+0x5ec4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104195906600960ULL);
x86_l_41b:
	/* 0x41b: jne    43d <generic_usdt_filter_arg+0x43d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_43d;
	}
x86_l_41d:
	/* 0x41d: mov    r12d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4ULL);
x86_l_423:
	/* 0x423: cmp    BYTE PTR [r14+0x5ec5],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104200201568256ULL);
x86_l_42b:
	/* 0x42b: jne    43d <generic_usdt_filter_arg+0x43d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_43d;
	}
x86_l_42d:
	/* 0x42d: mov    r12d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 5ULL);
x86_l_433:
	/* 0x433: cmp    BYTE PTR [r14+0x5ec6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104204496535552ULL);
x86_l_43b:
	/* 0x43b: je     45a <generic_usdt_filter_arg+0x45a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_45a;
	}
x86_l_43d:
	/* 0x43d: mov    DWORD PTR [r14+0x5f00],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24320ULL);
x86_l_444:
	/* 0x444: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_449:
	/* 0x449: mov    rsi,QWORD PTR [rip+0x59a3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&usdt_calls)));
x86_l_450:
	/* 0x450: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_453:
	/* 0x453: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_458:
	/* 0x458: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45a:
	/* 0x45a: mov    rbx,QWORD PTR [r14+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_45e:
	/* 0x45e: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_463:
	/* 0x463: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_465:
	/* 0x465: mov    QWORD PTR [rsp+0x18],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_46a:
	/* 0x46a: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_46f:
	/* 0x46f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_474:
	/* 0x474: mov    rdi,QWORD PTR [rip+0x59a3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_47b:
	/* 0x47b: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_480:
	/* 0x480: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_482:
	/* 0x482: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_485:
	/* 0x485: je     3d2 <generic_usdt_filter_arg+0x3d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3d2;
	}
x86_l_48b:
	/* 0x48b: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_490:
	/* 0x490: mov    rdi,QWORD PTR [rip+0x59a3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_497:
	/* 0x497: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_49c:
	/* 0x49c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49e:
	/* 0x49e: jmp    3d2 <generic_usdt_filter_arg+0x3d2> */
	goto x86_l_3d2;
x86_l_4a3:
	/* 0x4a3: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_4a4:
	/* 0x4a4: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_4a7:
	/* 0x4a7: mov    edx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a9:
	/* 0x4a9: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4ac:
	/* 0x4ac: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_4ae:
	/* 0x4ae: jne    4be <filter_file_buf+0x1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4be;
	}
x86_l_4b0:
	/* 0x4b0: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_4b2:
	/* 0x4b2: and    eax,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_4b5:
	/* 0x4b5: cmp    eax,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 36ULL);
x86_l_4b8:
	/* 0x4b8: je     4be <filter_file_buf+0x1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4be;
	}
x86_l_4ba:
	/* 0x4ba: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4bc:
	/* 0x4bc: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_4bd:
	/* 0x4bd: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_4be:
	/* 0x4be: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_4c1:
	/* 0x4c1: ja     4fd <filter_file_buf+0x5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_4fd;
	}
x86_l_4c3:
	/* 0x4c3: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_4c5:
	/* 0x4c5: mov    edi,0x4000100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 67109120ULL);
x86_l_4ca:
	/* 0x4ca: bt     rdi,rax */
	X86_SIM_L_EXEC_BT(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_4ce:
	/* 0x4ce: jb     531 <filter_file_buf+0x8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_531;
	}
x86_l_4d0:
	/* 0x4d0: mov    edi,0x8000200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 134218240ULL);
x86_l_4d5:
	/* 0x4d5: bt     rdi,rax */
	X86_SIM_L_EXEC_BT(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_4d9:
	/* 0x4d9: jb     51b <filter_file_buf+0x78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_51b;
	}
x86_l_4db:
	/* 0x4db: movabs rdi,0x3000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_64, 206158430208ULL);
x86_l_4e5:
	/* 0x4e5: bt     rdi,rax */
	X86_SIM_L_EXEC_BT(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_4e9:
	/* 0x4e9: jae    4fd <filter_file_buf+0x5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_4fd;
	}
x86_l_4eb:
	/* 0x4eb: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4ee:
	/* 0x4ee: call   23c7 <filter_file_type> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 1267ULL);
	__x86_sim_call_depth++;
	return 9159ULL;
x86_l_4f3:
	/* 0x4f3: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4f6:
	/* 0x4f6: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_4f9:
	/* 0x4f9: jbe    54e <filter_file_buf+0xab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_54e;
	}
x86_l_4fb:
	/* 0x4fb: jmp    564 <filter_file_buf+0xc1> */
	goto x86_l_564;
x86_l_4fd:
	/* 0x4fd: lea    eax,[rcx-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_500:
	/* 0x500: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_503:
	/* 0x503: jae    547 <filter_file_buf+0xa4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_547;
	}
x86_l_505:
	/* 0x505: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_509:
	/* 0x509: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_50c:
	/* 0x50c: call   117d <filter_char_buf_equal> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 1297ULL);
	__x86_sim_call_depth++;
	return 4477ULL;
x86_l_511:
	/* 0x511: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_514:
	/* 0x514: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_517:
	/* 0x517: jbe    54e <filter_file_buf+0xab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_54e;
	}
x86_l_519:
	/* 0x519: jmp    564 <filter_file_buf+0xc1> */
	goto x86_l_564;
x86_l_51b:
	/* 0x51b: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_51f:
	/* 0x51f: mov    edi,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_522:
	/* 0x522: call   f93 <filter_char_buf_postfix> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 1319ULL);
	__x86_sim_call_depth++;
	return 3987ULL;
x86_l_527:
	/* 0x527: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_52a:
	/* 0x52a: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_52d:
	/* 0x52d: jbe    54e <filter_file_buf+0xab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_54e;
	}
x86_l_52f:
	/* 0x52f: jmp    564 <filter_file_buf+0xc1> */
	goto x86_l_564;
x86_l_531:
	/* 0x531: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_535:
	/* 0x535: mov    edi,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_538:
	/* 0x538: call   10db <filter_char_buf_prefix> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 1341ULL);
	__x86_sim_call_depth++;
	return 4315ULL;
x86_l_53d:
	/* 0x53d: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_540:
	/* 0x540: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_543:
	/* 0x543: jbe    54e <filter_file_buf+0xab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_54e;
	}
x86_l_545:
	/* 0x545: jmp    564 <filter_file_buf+0xc1> */
	goto x86_l_564;
x86_l_547:
	/* 0x547: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_549:
	/* 0x549: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_54c:
	/* 0x54c: ja     564 <filter_file_buf+0xc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_564;
	}
x86_l_54e:
	/* 0x54e: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_550:
	/* 0x550: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_55a:
	/* 0x55a: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_55e:
	/* 0x55e: jae    564 <filter_file_buf+0xc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_564;
	}
x86_l_560:
	/* 0x560: xor    rax,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 1ULL);
x86_l_564:
	/* 0x564: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_565:
	/* 0x565: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_566:
	/* 0x566: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_567:
	/* 0x567: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_56a:
	/* 0x56a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_56c:
	/* 0x56c: cmp    rcx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 32ULL);
x86_l_570:
	/* 0x570: ja     5ab <filter_8ty+0x45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_5ab;
	}
x86_l_572:
	/* 0x572: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_577:
	/* 0x577: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_57b:
	/* 0x57b: jae    584 <filter_8ty+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_584;
	}
x86_l_57d:
	/* 0x57d: call   1f6f <filter_8ty_selector_val> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 1410ULL);
	__x86_sim_call_depth++;
	return 8047ULL;
x86_l_582:
	/* 0x582: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_583:
	/* 0x583: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_584:
	/* 0x584: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_589:
	/* 0x589: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_58d:
	/* 0x58d: jb     5a6 <filter_8ty+0x40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_5a6;
	}
x86_l_58f:
	/* 0x58f: movabs rdx,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 6442450944ULL);
x86_l_599:
	/* 0x599: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_59d:
	/* 0x59d: jae    5ab <filter_8ty+0x45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_5ab;
	}
x86_l_59f:
	/* 0x59f: call   2189 <filter_8ty_range> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 1444ULL);
	__x86_sim_call_depth++;
	return 8585ULL;
x86_l_5a4:
	/* 0x5a4: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_5a5:
	/* 0x5a5: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_5a6:
	/* 0x5a6: call   2341 <filter_8ty_map> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 1451ULL);
	__x86_sim_call_depth++;
	return 9025ULL;
x86_l_5ab:
	/* 0x5ab: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_5ac:
	/* 0x5ac: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_5ad:
	/* 0x5ad: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_5af:
	/* 0x5af: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_5b1:
	/* 0x5b1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_5b3:
	/* 0x5b3: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_5b4:
	/* 0x5b4: sub    rsp,0x48 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 72ULL);
x86_l_5b8:
	/* 0x5b8: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_5c1:
	/* 0x5c1: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_5ca:
	/* 0x5ca: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_5d3:
	/* 0x5d3: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_5dc:
	/* 0x5dc: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_5e5:
	/* 0x5e5: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5ec:
	/* 0x5ec: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_5f4:
	/* 0x5f4: mov    edx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_5f7:
	/* 0x5f7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5f9:
	/* 0x5f9: cmp    edx,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 39ULL);
x86_l_5fc:
	/* 0x5fc: jg     614 <filter_inet+0x67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 1556ULL;
	}
x86_l_5fe:
	/* 0x5fe: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_601:
	/* 0x601: je     699 <filter_inet+0xec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1689ULL;
	}
x86_l_607:
	/* 0x607: mov    r8,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_64);
	return 1546ULL;
}

static __noinline __u64 tetragon_bpf_multi_usdt_v61_generic_usdt_filter_arg_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1546ULL: goto x86_l_60a;
	case 1549ULL: goto x86_l_60d;
	case 1551ULL: goto x86_l_60f;
	case 1556ULL: goto x86_l_614;
	case 1559ULL: goto x86_l_617;
	case 1561ULL: goto x86_l_619;
	case 1564ULL: goto x86_l_61c;
	case 1567ULL: goto x86_l_61f;
	case 1573ULL: goto x86_l_625;
	case 1576ULL: goto x86_l_628;
	case 1578ULL: goto x86_l_62a;
	case 1581ULL: goto x86_l_62d;
	case 1583ULL: goto x86_l_62f;
	case 1586ULL: goto x86_l_632;
	case 1588ULL: goto x86_l_634;
	case 1591ULL: goto x86_l_637;
	case 1594ULL: goto x86_l_63a;
	case 1600ULL: goto x86_l_640;
	case 1603ULL: goto x86_l_643;
	case 1606ULL: goto x86_l_646;
	case 1612ULL: goto x86_l_64c;
	case 1617ULL: goto x86_l_651;
	case 1620ULL: goto x86_l_654;
	case 1626ULL: goto x86_l_65a;
	case 1629ULL: goto x86_l_65d;
	case 1635ULL: goto x86_l_663;
	case 1638ULL: goto x86_l_666;
	case 1644ULL: goto x86_l_66c;
	case 1649ULL: goto x86_l_671;
	case 1652ULL: goto x86_l_674;
	case 1657ULL: goto x86_l_679;
	case 1661ULL: goto x86_l_67d;
	case 1666ULL: goto x86_l_682;
	case 1670ULL: goto x86_l_686;
	case 1675ULL: goto x86_l_68b;
	case 1679ULL: goto x86_l_68f;
	case 1684ULL: goto x86_l_694;
	case 1689ULL: goto x86_l_699;
	case 1692ULL: goto x86_l_69c;
	case 1695ULL: goto x86_l_69f;
	case 1697ULL: goto x86_l_6a1;
	case 1700ULL: goto x86_l_6a4;
	case 1702ULL: goto x86_l_6a6;
	case 1705ULL: goto x86_l_6a9;
	case 1707ULL: goto x86_l_6ab;
	case 1710ULL: goto x86_l_6ae;
	case 1712ULL: goto x86_l_6b0;
	case 1715ULL: goto x86_l_6b3;
	case 1717ULL: goto x86_l_6b5;
	case 1720ULL: goto x86_l_6b8;
	case 1726ULL: goto x86_l_6be;
	case 1730ULL: goto x86_l_6c2;
	case 1735ULL: goto x86_l_6c7;
	case 1738ULL: goto x86_l_6ca;
	case 1744ULL: goto x86_l_6d0;
	case 1747ULL: goto x86_l_6d3;
	case 1753ULL: goto x86_l_6d9;
	case 1756ULL: goto x86_l_6dc;
	case 1758ULL: goto x86_l_6de;
	case 1763ULL: goto x86_l_6e3;
	case 1766ULL: goto x86_l_6e6;
	case 1768ULL: goto x86_l_6e8;
	case 1771ULL: goto x86_l_6eb;
	case 1777ULL: goto x86_l_6f1;
	case 1781ULL: goto x86_l_6f5;
	case 1783ULL: goto x86_l_6f7;
	case 1787ULL: goto x86_l_6fb;
	case 1791ULL: goto x86_l_6ff;
	case 1793ULL: goto x86_l_701;
	case 1796ULL: goto x86_l_704;
	case 1799ULL: goto x86_l_707;
	case 1801ULL: goto x86_l_709;
	case 1804ULL: goto x86_l_70c;
	case 1806ULL: goto x86_l_70e;
	case 1809ULL: goto x86_l_711;
	case 1812ULL: goto x86_l_714;
	case 1818ULL: goto x86_l_71a;
	case 1821ULL: goto x86_l_71d;
	case 1824ULL: goto x86_l_720;
	case 1830ULL: goto x86_l_726;
	case 1833ULL: goto x86_l_729;
	case 1839ULL: goto x86_l_72f;
	case 1844ULL: goto x86_l_734;
	case 1847ULL: goto x86_l_737;
	case 1853ULL: goto x86_l_73d;
	case 1856ULL: goto x86_l_740;
	case 1862ULL: goto x86_l_746;
	case 1865ULL: goto x86_l_749;
	case 1871ULL: goto x86_l_74f;
	case 1874ULL: goto x86_l_752;
	case 1880ULL: goto x86_l_758;
	case 1885ULL: goto x86_l_75d;
	case 1889ULL: goto x86_l_761;
	case 1893ULL: goto x86_l_765;
	case 1895ULL: goto x86_l_767;
	case 1898ULL: goto x86_l_76a;
	case 1902ULL: goto x86_l_76e;
	case 1905ULL: goto x86_l_771;
	case 1909ULL: goto x86_l_775;
	case 1911ULL: goto x86_l_777;
	case 1913ULL: goto x86_l_779;
	case 1916ULL: goto x86_l_77c;
	case 1918ULL: goto x86_l_77e;
	case 1921ULL: goto x86_l_781;
	case 1923ULL: goto x86_l_783;
	case 1929ULL: goto x86_l_789;
	case 1933ULL: goto x86_l_78d;
	case 1935ULL: goto x86_l_78f;
	case 1941ULL: goto x86_l_795;
	case 1945ULL: goto x86_l_799;
	case 1947ULL: goto x86_l_79b;
	case 1952ULL: goto x86_l_7a0;
	case 1955ULL: goto x86_l_7a3;
	case 1957ULL: goto x86_l_7a5;
	case 1961ULL: goto x86_l_7a9;
	case 1964ULL: goto x86_l_7ac;
	case 1966ULL: goto x86_l_7ae;
	case 1969ULL: goto x86_l_7b1;
	case 1975ULL: goto x86_l_7b7;
	case 1978ULL: goto x86_l_7ba;
	case 1981ULL: goto x86_l_7bd;
	case 1985ULL: goto x86_l_7c1;
	case 1990ULL: goto x86_l_7c6;
	case 1997ULL: goto x86_l_7cd;
	case 2002ULL: goto x86_l_7d2;
	case 2004ULL: goto x86_l_7d4;
	case 2007ULL: goto x86_l_7d7;
	case 2013ULL: goto x86_l_7dd;
	case 2021ULL: goto x86_l_7e5;
	case 2025ULL: goto x86_l_7e9;
	case 2027ULL: goto x86_l_7eb;
	case 2030ULL: goto x86_l_7ee;
	case 2033ULL: goto x86_l_7f1;
	case 2039ULL: goto x86_l_7f7;
	case 2044ULL: goto x86_l_7fc;
	case 2049ULL: goto x86_l_801;
	case 2051ULL: goto x86_l_803;
	case 2057ULL: goto x86_l_809;
	case 2060ULL: goto x86_l_80c;
	case 2065ULL: goto x86_l_811;
	case 2067ULL: goto x86_l_813;
	case 2073ULL: goto x86_l_819;
	case 2076ULL: goto x86_l_81c;
	case 2081ULL: goto x86_l_821;
	case 2084ULL: goto x86_l_824;
	case 2087ULL: goto x86_l_827;
	case 2091ULL: goto x86_l_82b;
	case 2096ULL: goto x86_l_830;
	case 2103ULL: goto x86_l_837;
	case 2108ULL: goto x86_l_83c;
	case 2110ULL: goto x86_l_83e;
	case 2113ULL: goto x86_l_841;
	case 2115ULL: goto x86_l_843;
	case 2123ULL: goto x86_l_84b;
	case 2127ULL: goto x86_l_84f;
	case 2132ULL: goto x86_l_854;
	case 2137ULL: goto x86_l_859;
	case 2141ULL: goto x86_l_85d;
	case 2146ULL: goto x86_l_862;
	case 2151ULL: goto x86_l_867;
	case 2156ULL: goto x86_l_86c;
	case 2159ULL: goto x86_l_86f;
	case 2161ULL: goto x86_l_871;
	case 2166ULL: goto x86_l_876;
	case 2169ULL: goto x86_l_879;
	case 2172ULL: goto x86_l_87c;
	case 2174ULL: goto x86_l_87e;
	case 2177ULL: goto x86_l_881;
	case 2180ULL: goto x86_l_884;
	case 2182ULL: goto x86_l_886;
	case 2185ULL: goto x86_l_889;
	case 2188ULL: goto x86_l_88c;
	case 2191ULL: goto x86_l_88f;
	case 2193ULL: goto x86_l_891;
	case 2195ULL: goto x86_l_893;
	case 2198ULL: goto x86_l_896;
	case 2200ULL: goto x86_l_898;
	case 2204ULL: goto x86_l_89c;
	case 2207ULL: goto x86_l_89f;
	case 2210ULL: goto x86_l_8a2;
	case 2215ULL: goto x86_l_8a7;
	case 2219ULL: goto x86_l_8ab;
	case 2220ULL: goto x86_l_8ac;
	case 2222ULL: goto x86_l_8ae;
	case 2224ULL: goto x86_l_8b0;
	case 2226ULL: goto x86_l_8b2;
	case 2227ULL: goto x86_l_8b3;
	case 2232ULL: goto x86_l_8b8;
	case 2235ULL: goto x86_l_8bb;
	case 2238ULL: goto x86_l_8be;
	case 2240ULL: goto x86_l_8c0;
	case 2243ULL: goto x86_l_8c3;
	case 2246ULL: goto x86_l_8c6;
	case 2249ULL: goto x86_l_8c9;
	case 2251ULL: goto x86_l_8cb;
	case 2254ULL: goto x86_l_8ce;
	case 2256ULL: goto x86_l_8d0;
	case 2259ULL: goto x86_l_8d3;
	case 2261ULL: goto x86_l_8d5;
	case 2266ULL: goto x86_l_8da;
	case 2269ULL: goto x86_l_8dd;
	case 2272ULL: goto x86_l_8e0;
	case 2274ULL: goto x86_l_8e2;
	case 2277ULL: goto x86_l_8e5;
	case 2279ULL: goto x86_l_8e7;
	case 2281ULL: goto x86_l_8e9;
	case 2283ULL: goto x86_l_8eb;
	case 2284ULL: goto x86_l_8ec;
	case 2288ULL: goto x86_l_8f0;
	case 2291ULL: goto x86_l_8f3;
	case 2295ULL: goto x86_l_8f7;
	case 2299ULL: goto x86_l_8fb;
	case 2303ULL: goto x86_l_8ff;
	case 2305ULL: goto x86_l_901;
	case 2309ULL: goto x86_l_905;
	case 2311ULL: goto x86_l_907;
	case 2315ULL: goto x86_l_90b;
	case 2318ULL: goto x86_l_90e;
	case 2320ULL: goto x86_l_910;
	case 2323ULL: goto x86_l_913;
	case 2328ULL: goto x86_l_918;
	case 2331ULL: goto x86_l_91b;
	case 2335ULL: goto x86_l_91f;
	case 2337ULL: goto x86_l_921;
	case 2347ULL: goto x86_l_92b;
	case 2351ULL: goto x86_l_92f;
	case 2353ULL: goto x86_l_931;
	case 2357ULL: goto x86_l_935;
	case 2361ULL: goto x86_l_939;
	case 2362ULL: goto x86_l_93a;
	case 2363ULL: goto x86_l_93b;
	case 2367ULL: goto x86_l_93f;
	case 2369ULL: goto x86_l_941;
	case 2373ULL: goto x86_l_945;
	case 2375ULL: goto x86_l_947;
	case 2377ULL: goto x86_l_949;
	case 2381ULL: goto x86_l_94d;
	case 2383ULL: goto x86_l_94f;
	case 2386ULL: goto x86_l_952;
	case 2389ULL: goto x86_l_955;
	case 2391ULL: goto x86_l_957;
	case 2396ULL: goto x86_l_95c;
	case 2399ULL: goto x86_l_95f;
	case 2403ULL: goto x86_l_963;
	case 2405ULL: goto x86_l_965;
	case 2415ULL: goto x86_l_96f;
	case 2419ULL: goto x86_l_973;
	case 2421ULL: goto x86_l_975;
	case 2425ULL: goto x86_l_979;
	case 2429ULL: goto x86_l_97d;
	case 2430ULL: goto x86_l_97e;
	case 2431ULL: goto x86_l_97f;
	case 2434ULL: goto x86_l_982;
	case 2438ULL: goto x86_l_986;
	case 2443ULL: goto x86_l_98b;
	case 2448ULL: goto x86_l_990;
	case 2452ULL: goto x86_l_994;
	case 2453ULL: goto x86_l_995;
	case 2454ULL: goto x86_l_996;
	case 2455ULL: goto x86_l_997;
	case 2458ULL: goto x86_l_99a;
	case 2460ULL: goto x86_l_99c;
	case 2464ULL: goto x86_l_9a0;
	case 2466ULL: goto x86_l_9a2;
	case 2471ULL: goto x86_l_9a7;
	case 2475ULL: goto x86_l_9ab;
	case 2477ULL: goto x86_l_9ad;
	case 2482ULL: goto x86_l_9b2;
	case 2483ULL: goto x86_l_9b3;
	case 2484ULL: goto x86_l_9b4;
	case 2489ULL: goto x86_l_9b9;
	case 2493ULL: goto x86_l_9bd;
	case 2495ULL: goto x86_l_9bf;
	case 2505ULL: goto x86_l_9c9;
	case 2509ULL: goto x86_l_9cd;
	case 2511ULL: goto x86_l_9cf;
	case 2516ULL: goto x86_l_9d4;
	case 2517ULL: goto x86_l_9d5;
	case 2518ULL: goto x86_l_9d6;
	case 2523ULL: goto x86_l_9db;
	case 2524ULL: goto x86_l_9dc;
	case 2525ULL: goto x86_l_9dd;
	case 2526ULL: goto x86_l_9de;
	case 2529ULL: goto x86_l_9e1;
	case 2531ULL: goto x86_l_9e3;
	case 2535ULL: goto x86_l_9e7;
	case 2537ULL: goto x86_l_9e9;
	case 2542ULL: goto x86_l_9ee;
	case 2546ULL: goto x86_l_9f2;
	case 2548ULL: goto x86_l_9f4;
	case 2553ULL: goto x86_l_9f9;
	case 2554ULL: goto x86_l_9fa;
	case 2555ULL: goto x86_l_9fb;
	case 2560ULL: goto x86_l_a00;
	case 2564ULL: goto x86_l_a04;
	case 2566ULL: goto x86_l_a06;
	case 2576ULL: goto x86_l_a10;
	case 2580ULL: goto x86_l_a14;
	case 2582ULL: goto x86_l_a16;
	case 2587ULL: goto x86_l_a1b;
	case 2588ULL: goto x86_l_a1c;
	case 2589ULL: goto x86_l_a1d;
	case 2594ULL: goto x86_l_a22;
	case 2595ULL: goto x86_l_a23;
	case 2596ULL: goto x86_l_a24;
	case 2597ULL: goto x86_l_a25;
	case 2600ULL: goto x86_l_a28;
	case 2603ULL: goto x86_l_a2b;
	case 2606ULL: goto x86_l_a2e;
	case 2610ULL: goto x86_l_a32;
	case 2612ULL: goto x86_l_a34;
	case 2615ULL: goto x86_l_a37;
	case 2618ULL: goto x86_l_a3a;
	case 2620ULL: goto x86_l_a3c;
	case 2623ULL: goto x86_l_a3f;
	case 2625ULL: goto x86_l_a41;
	case 2628ULL: goto x86_l_a44;
	case 2631ULL: goto x86_l_a47;
	case 2633ULL: goto x86_l_a49;
	case 2636ULL: goto x86_l_a4c;
	case 2638ULL: goto x86_l_a4e;
	case 2641ULL: goto x86_l_a51;
	case 2643ULL: goto x86_l_a53;
	case 2645ULL: goto x86_l_a55;
	case 2648ULL: goto x86_l_a58;
	case 2650ULL: goto x86_l_a5a;
	case 2653ULL: goto x86_l_a5d;
	case 2655ULL: goto x86_l_a5f;
	case 2658ULL: goto x86_l_a62;
	case 2660ULL: goto x86_l_a64;
	case 2663ULL: goto x86_l_a67;
	case 2668ULL: goto x86_l_a6c;
	case 2670ULL: goto x86_l_a6e;
	case 2673ULL: goto x86_l_a71;
	case 2675ULL: goto x86_l_a73;
	case 2678ULL: goto x86_l_a76;
	case 2680ULL: goto x86_l_a78;
	case 2683ULL: goto x86_l_a7b;
	case 2688ULL: goto x86_l_a80;
	case 2690ULL: goto x86_l_a82;
	case 2693ULL: goto x86_l_a85;
	case 2698ULL: goto x86_l_a8a;
	case 2700ULL: goto x86_l_a8c;
	case 2703ULL: goto x86_l_a8f;
	case 2708ULL: goto x86_l_a94;
	case 2710ULL: goto x86_l_a96;
	case 2713ULL: goto x86_l_a99;
	case 2715ULL: goto x86_l_a9b;
	case 2720ULL: goto x86_l_aa0;
	case 2723ULL: goto x86_l_aa3;
	case 2726ULL: goto x86_l_aa6;
	case 2728ULL: goto x86_l_aa8;
	case 2730ULL: goto x86_l_aaa;
	case 2740ULL: goto x86_l_ab4;
	case 2744ULL: goto x86_l_ab8;
	case 2746ULL: goto x86_l_aba;
	case 2748ULL: goto x86_l_abc;
	case 2751ULL: goto x86_l_abf;
	case 2754ULL: goto x86_l_ac2;
	case 2757ULL: goto x86_l_ac5;
	case 2758ULL: goto x86_l_ac6;
	case 2759ULL: goto x86_l_ac7;
	case 2760ULL: goto x86_l_ac8;
	case 2763ULL: goto x86_l_acb;
	case 2765ULL: goto x86_l_acd;
	case 2769ULL: goto x86_l_ad1;
	case 2771ULL: goto x86_l_ad3;
	case 2776ULL: goto x86_l_ad8;
	case 2780ULL: goto x86_l_adc;
	case 2782ULL: goto x86_l_ade;
	case 2787ULL: goto x86_l_ae3;
	case 2788ULL: goto x86_l_ae4;
	case 2789ULL: goto x86_l_ae5;
	case 2794ULL: goto x86_l_aea;
	case 2798ULL: goto x86_l_aee;
	case 2800ULL: goto x86_l_af0;
	case 2810ULL: goto x86_l_afa;
	case 2814ULL: goto x86_l_afe;
	case 2816ULL: goto x86_l_b00;
	case 2821ULL: goto x86_l_b05;
	case 2822ULL: goto x86_l_b06;
	case 2823ULL: goto x86_l_b07;
	case 2828ULL: goto x86_l_b0c;
	case 2829ULL: goto x86_l_b0d;
	default: return 0xffffffffffffffffULL;
	}
x86_l_60a:
	/* 0x60a: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_60d:
	/* 0x60d: je     625 <filter_inet+0x78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_625;
	}
x86_l_60f:
	/* 0x60f: jmp    8a7 <filter_inet+0x2fa> */
	goto x86_l_8a7;
x86_l_614:
	/* 0x614: cmp    edx,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 40ULL);
x86_l_617:
	/* 0x617: je     671 <filter_inet+0xc4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_671;
	}
x86_l_619:
	/* 0x619: mov    r8,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_64);
x86_l_61c:
	/* 0x61c: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_61f:
	/* 0x61f: jne    8a7 <filter_inet+0x2fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8a7;
	}
x86_l_625:
	/* 0x625: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_628:
	/* 0x628: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_62a:
	/* 0x62a: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_62d:
	/* 0x62d: jle    6a6 <filter_inet+0xf9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_6a6;
	}
x86_l_62f:
	/* 0x62f: cmp    ecx,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 23ULL);
x86_l_632:
	/* 0x632: jg     651 <filter_inet+0xa4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_651;
	}
x86_l_634:
	/* 0x634: lea    edx,[rcx-0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551596ULL);
x86_l_637:
	/* 0x637: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_63a:
	/* 0x63a: jb     6f7 <filter_inet+0x14a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_6f7;
	}
x86_l_640:
	/* 0x640: lea    edx,[rcx-0x16] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_643:
	/* 0x643: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_646:
	/* 0x646: jb     6f1 <filter_inet+0x144> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_6f1;
	}
x86_l_64c:
	/* 0x64c: jmp    8a7 <filter_inet+0x2fa> */
	goto x86_l_8a7;
x86_l_651:
	/* 0x651: cmp    ecx,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 27ULL);
x86_l_654:
	/* 0x654: jg     734 <filter_inet+0x187> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_734;
	}
x86_l_65a:
	/* 0x65a: cmp    ecx,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 24ULL);
x86_l_65d:
	/* 0x65d: je     767 <filter_inet+0x1ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_767;
	}
x86_l_663:
	/* 0x663: cmp    ecx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 25ULL);
x86_l_666:
	/* 0x666: je     75d <filter_inet+0x1b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_75d;
	}
x86_l_66c:
	/* 0x66c: jmp    8a7 <filter_inet+0x2fa> */
	goto x86_l_8a7;
x86_l_671:
	/* 0x671: movzx  eax,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_674:
	/* 0x674: mov    WORD PTR [rsp+0x46],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 70ULL);
x86_l_679:
	/* 0x679: movzx  eax,WORD PTR [rsi+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_67d:
	/* 0x67d: mov    WORD PTR [rsp+0x40],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_682:
	/* 0x682: mov    rax,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_686:
	/* 0x686: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_68b:
	/* 0x68b: mov    rax,QWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_68f:
	/* 0x68f: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_694:
	/* 0x694: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_699:
	/* 0x699: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_69c:
	/* 0x69c: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_69f:
	/* 0x69f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6a1:
	/* 0x6a1: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_6a4:
	/* 0x6a4: jg     62f <filter_inet+0x82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_62f;
	}
x86_l_6a6:
	/* 0x6a6: cmp    ecx,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 15ULL);
x86_l_6a9:
	/* 0x6a9: jle    6c7 <filter_inet+0x11a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_6c7;
	}
x86_l_6ab:
	/* 0x6ab: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_6ae:
	/* 0x6ae: jg     6e3 <filter_inet+0x136> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_6e3;
	}
x86_l_6b0:
	/* 0x6b0: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_6b3:
	/* 0x6b3: je     6f1 <filter_inet+0x144> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6f1;
	}
x86_l_6b5:
	/* 0x6b5: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_6b8:
	/* 0x6b8: jne    8a7 <filter_inet+0x2fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8a7;
	}
x86_l_6be:
	/* 0x6be: movzx  eax,WORD PTR [rsi+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_6c2:
	/* 0x6c2: jmp    89c <filter_inet+0x2ef> */
	goto x86_l_89c;
x86_l_6c7:
	/* 0x6c7: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_6ca:
	/* 0x6ca: je     767 <filter_inet+0x1ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_767;
	}
x86_l_6d0:
	/* 0x6d0: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_6d3:
	/* 0x6d3: je     75d <filter_inet+0x1b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_75d;
	}
x86_l_6d9:
	/* 0x6d9: cmp    ecx,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 15ULL);
x86_l_6dc:
	/* 0x6dc: je     6f7 <filter_inet+0x14a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6f7;
	}
x86_l_6de:
	/* 0x6de: jmp    8a7 <filter_inet+0x2fa> */
	goto x86_l_8a7;
x86_l_6e3:
	/* 0x6e3: cmp    ecx,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 18ULL);
x86_l_6e6:
	/* 0x6e6: je     6f7 <filter_inet+0x14a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6f7;
	}
x86_l_6e8:
	/* 0x6e8: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_6eb:
	/* 0x6eb: jne    8a7 <filter_inet+0x2fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8a7;
	}
x86_l_6f1:
	/* 0x6f1: movzx  edx,WORD PTR [rsi+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_6f5:
	/* 0x6f5: jmp    6fb <filter_inet+0x14e> */
	goto x86_l_6fb;
x86_l_6f7:
	/* 0x6f7: movzx  edx,WORD PTR [rsi+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_6fb:
	/* 0x6fb: mov    DWORD PTR [rsp+0x4],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_6ff:
	/* 0x6ff: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_701:
	/* 0x701: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_704:
	/* 0x704: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_707:
	/* 0x707: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_709:
	/* 0x709: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_70c:
	/* 0x70c: jg     77e <filter_inet+0x1d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_77e;
	}
x86_l_70e:
	/* 0x70e: lea    edx,[rcx-0xd] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551603ULL);
x86_l_711:
	/* 0x711: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_714:
	/* 0x714: jb     7a5 <filter_inet+0x1f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_7a5;
	}
x86_l_71a:
	/* 0x71a: lea    edx,[rcx-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_71d:
	/* 0x71d: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_720:
	/* 0x720: jb     7f7 <filter_inet+0x24a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_7f7;
	}
x86_l_726:
	/* 0x726: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_729:
	/* 0x729: je     89f <filter_inet+0x2f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_89f;
	}
x86_l_72f:
	/* 0x72f: jmp    8a7 <filter_inet+0x2fa> */
	goto x86_l_8a7;
x86_l_734:
	/* 0x734: cmp    ecx,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 28ULL);
x86_l_737:
	/* 0x737: je     898 <filter_inet+0x2eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_898;
	}
x86_l_73d:
	/* 0x73d: cmp    ecx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 29ULL);
x86_l_740:
	/* 0x740: jne    8a7 <filter_inet+0x2fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8a7;
	}
x86_l_746:
	/* 0x746: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_749:
	/* 0x749: jne    8cb <filter_inet+0x31e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8cb;
	}
x86_l_74f:
	/* 0x74f: test   r8,r8 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_64);
x86_l_752:
	/* 0x752: jne    8d5 <filter_inet+0x328> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8d5;
	}
x86_l_758:
	/* 0x758: jmp    89f <filter_inet+0x2f2> */
	goto x86_l_89f;
x86_l_75d:
	/* 0x75d: mov    rbx,QWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_761:
	/* 0x761: mov    r14,QWORD PTR [rsi+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_765:
	/* 0x765: jmp    76e <filter_inet+0x1c1> */
	goto x86_l_76e;
x86_l_767:
	/* 0x767: mov    rbx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_76a:
	/* 0x76a: mov    r14,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_76e:
	/* 0x76e: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_771:
	/* 0x771: shr    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_775:
	/* 0x775: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_777:
	/* 0x777: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_779:
	/* 0x779: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_77c:
	/* 0x77c: jle    70e <filter_inet+0x161> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_70e;
	}
x86_l_77e:
	/* 0x77e: cmp    ecx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 25ULL);
x86_l_781:
	/* 0x781: ja     7eb <filter_inet+0x23e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_7eb;
	}
x86_l_783:
	/* 0x783: mov    r8d,0x500000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5242880ULL);
x86_l_789:
	/* 0x789: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_78d:
	/* 0x78d: jb     801 <filter_inet+0x254> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_801;
	}
x86_l_78f:
	/* 0x78f: mov    r8d,0xa00000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 10485760ULL);
x86_l_795:
	/* 0x795: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_799:
	/* 0x799: jb     811 <filter_inet+0x264> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_811;
	}
x86_l_79b:
	/* 0x79b: mov    edx,0x3000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 50331648ULL);
x86_l_7a0:
	/* 0x7a0: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_7a3:
	/* 0x7a3: jae    7eb <filter_inet+0x23e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_7eb;
	}
x86_l_7a5:
	/* 0x7a5: movzx  eax,WORD PTR [rsi+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_7a9:
	/* 0x7a9: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_7ac:
	/* 0x7ac: je     821 <filter_inet+0x274> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_821;
	}
x86_l_7ae:
	/* 0x7ae: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_7b1:
	/* 0x7b1: jne    891 <filter_inet+0x2e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_891;
	}
x86_l_7b7:
	/* 0x7b7: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_7ba:
	/* 0x7ba: mov    eax,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7bd:
	/* 0x7bd: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7c1:
	/* 0x7c1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7c6:
	/* 0x7c6: mov    rdi,QWORD PTR [rip+0x1ad0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr4lpm_maps)));
x86_l_7cd:
	/* 0x7cd: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7d2:
	/* 0x7d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7d4:
	/* 0x7d4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7d7:
	/* 0x7d7: je     8b3 <filter_inet+0x306> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8b3;
	}
x86_l_7dd:
	/* 0x7dd: mov    DWORD PTR [rsp+0xc],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607584ULL);
x86_l_7e5:
	/* 0x7e5: mov    DWORD PTR [rsp+0x10],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7e9:
	/* 0x7e9: jmp    862 <filter_inet+0x2b5> */
	goto x86_l_862;
x86_l_7eb:
	/* 0x7eb: add    ecx,0xffffffee */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 4294967278ULL);
x86_l_7ee:
	/* 0x7ee: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_7f1:
	/* 0x7f1: jae    8a7 <filter_inet+0x2fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_8a7;
	}
x86_l_7f7:
	/* 0x7f7: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_7fc:
	/* 0x7fc: jmp    8a2 <filter_inet+0x2f5> */
	goto x86_l_8a2;
x86_l_801:
	/* 0x801: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_803:
	/* 0x803: cmp    edx,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1024ULL);
x86_l_809:
	/* 0x809: setb   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_B);
x86_l_80c:
	/* 0x80c: jmp    8a7 <filter_inet+0x2fa> */
	goto x86_l_8a7;
x86_l_811:
	/* 0x811: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_813:
	/* 0x813: cmp    edx,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1024ULL);
x86_l_819:
	/* 0x819: setae  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_AE);
x86_l_81c:
	/* 0x81c: jmp    8a7 <filter_inet+0x2fa> */
	goto x86_l_8a7;
x86_l_821:
	/* 0x821: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_824:
	/* 0x824: mov    eax,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_827:
	/* 0x827: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_82b:
	/* 0x82b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_830:
	/* 0x830: mov    rdi,QWORD PTR [rip+0x1ad0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr6lpm_maps)));
x86_l_837:
	/* 0x837: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_83c:
	/* 0x83c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_83e:
	/* 0x83e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_841:
	/* 0x841: je     8b3 <filter_inet+0x306> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8b3;
	}
x86_l_843:
	/* 0x843: mov    DWORD PTR [rsp+0xc],0x80 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607680ULL);
x86_l_84b:
	/* 0x84b: mov    DWORD PTR [rsp+0x10],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_84f:
	/* 0x84f: mov    DWORD PTR [rsp+0x14],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_854:
	/* 0x854: mov    DWORD PTR [rsp+0x18],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_859:
	/* 0x859: shr    r14,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_85d:
	/* 0x85d: mov    DWORD PTR [rsp+0x1c],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_862:
	/* 0x862: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_867:
	/* 0x867: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_86c:
	/* 0x86c: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_86f:
	/* 0x86f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_871:
	/* 0x871: mov    ecx,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_876:
	/* 0x876: lea    edx,[rcx-0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551592ULL);
x86_l_879:
	/* 0x879: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_87c:
	/* 0x87c: jb     8c0 <filter_inet+0x313> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_8c0;
	}
x86_l_87e:
	/* 0x87e: add    ecx,0xfffffff3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 4294967283ULL);
x86_l_881:
	/* 0x881: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_884:
	/* 0x884: ja     891 <filter_inet+0x2e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_891;
	}
x86_l_886:
	/* 0x886: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_889:
	/* 0x889: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_88c:
	/* 0x88c: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_88f:
	/* 0x88f: jmp    8a7 <filter_inet+0x2fa> */
	goto x86_l_8a7;
x86_l_891:
	/* 0x891: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_893:
	/* 0x893: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_896:
	/* 0x896: jmp    8a7 <filter_inet+0x2fa> */
	goto x86_l_8a7;
x86_l_898:
	/* 0x898: movzx  eax,WORD PTR [rsi+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_89c:
	/* 0x89c: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_89f:
	/* 0x89f: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_8a2:
	/* 0x8a2: call   1eea <filter_32ty_map> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2215ULL);
	__x86_sim_call_depth++;
	return 7914ULL;
x86_l_8a7:
	/* 0x8a7: add    rsp,0x48 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 72ULL);
x86_l_8ab:
	/* 0x8ab: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_8ac:
	/* 0x8ac: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_8ae:
	/* 0x8ae: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_8b0:
	/* 0x8b0: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_8b2:
	/* 0x8b2: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_8b3:
	/* 0x8b3: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_8b8:
	/* 0x8b8: and    eax,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_8bb:
	/* 0x8bb: cmp    eax,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_8be:
	/* 0x8be: jmp    8c3 <filter_inet+0x316> */
	goto x86_l_8c3;
x86_l_8c0:
	/* 0x8c0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8c3:
	/* 0x8c3: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_8c6:
	/* 0x8c6: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_8c9:
	/* 0x8c9: jmp    8a7 <filter_inet+0x2fa> */
	goto x86_l_8a7;
x86_l_8cb:
	/* 0x8cb: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_8ce:
	/* 0x8ce: jne    8dd <filter_inet+0x330> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8dd;
	}
x86_l_8d0:
	/* 0x8d0: test   r8,r8 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_64);
x86_l_8d3:
	/* 0x8d3: je     8dd <filter_inet+0x330> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8dd;
	}
x86_l_8d5:
	/* 0x8d5: movzx  eax,BYTE PTR [r8+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 58ULL);
x86_l_8da:
	/* 0x8da: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8dd:
	/* 0x8dd: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_8e0:
	/* 0x8e0: je     89f <filter_inet+0x2f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_89f;
	}
x86_l_8e2:
	/* 0x8e2: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_8e5:
	/* 0x8e5: je     89f <filter_inet+0x2f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_89f;
	}
x86_l_8e7:
	/* 0x8e7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8e9:
	/* 0x8e9: jmp    8a7 <filter_inet+0x2fa> */
	goto x86_l_8a7;
x86_l_8eb:
	/* 0x8eb: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_8ec:
	/* 0x8ec: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_8f0:
	/* 0x8f0: mov    rcx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_64);
x86_l_8f3:
	/* 0x8f3: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_8f7:
	/* 0x8f7: movzx  edx,BYTE PTR [rcx+0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 3ULL);
x86_l_8fb:
	/* 0x8fb: mov    r8d,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_8ff:
	/* 0x8ff: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_901:
	/* 0x901: cmp    r8d,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 25ULL);
x86_l_905:
	/* 0x905: jg     93b <filter_sockaddr_un+0x50> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_93b;
	}
x86_l_907:
	/* 0x907: lea    ecx,[r8-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_90b:
	/* 0x90b: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_90e:
	/* 0x90e: jae    949 <filter_sockaddr_un+0x5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_949;
	}
x86_l_910:
	/* 0x910: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_913:
	/* 0x913: call   117d <filter_char_buf_equal> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2328ULL);
	__x86_sim_call_depth++;
	return 4477ULL;
x86_l_918:
	/* 0x918: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_91b:
	/* 0x91b: cmp    rcx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 37ULL);
x86_l_91f:
	/* 0x91f: ja     935 <filter_sockaddr_un+0x4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_935;
	}
x86_l_921:
	/* 0x921: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_92b:
	/* 0x92b: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_92f:
	/* 0x92f: jae    935 <filter_sockaddr_un+0x4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_935;
	}
x86_l_931:
	/* 0x931: xor    rax,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 1ULL);
x86_l_935:
	/* 0x935: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_939:
	/* 0x939: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_93a:
	/* 0x93a: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_93b:
	/* 0x93b: cmp    r8d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 28ULL);
x86_l_93f:
	/* 0x93f: je     97f <filter_sockaddr_un+0x94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_97f;
	}
x86_l_941:
	/* 0x941: cmp    r8d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 26ULL);
x86_l_945:
	/* 0x945: je     94f <filter_sockaddr_un+0x64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_94f;
	}
x86_l_947:
	/* 0x947: jmp    935 <filter_sockaddr_un+0x4a> */
	goto x86_l_935;
x86_l_949:
	/* 0x949: cmp    r8d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 8ULL);
x86_l_94d:
	/* 0x94d: jne    935 <filter_sockaddr_un+0x4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_935;
	}
x86_l_94f:
	/* 0x94f: mov    eax,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_952:
	/* 0x952: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_955:
	/* 0x955: mov    edi,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_957:
	/* 0x957: call   10db <filter_char_buf_prefix> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2396ULL);
	__x86_sim_call_depth++;
	return 4315ULL;
x86_l_95c:
	/* 0x95c: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_95f:
	/* 0x95f: cmp    rcx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 37ULL);
x86_l_963:
	/* 0x963: ja     935 <filter_sockaddr_un+0x4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_935;
	}
x86_l_965:
	/* 0x965: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_96f:
	/* 0x96f: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_973:
	/* 0x973: jae    935 <filter_sockaddr_un+0x4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_935;
	}
x86_l_975:
	/* 0x975: xor    rax,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 1ULL);
x86_l_979:
	/* 0x979: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_97d:
	/* 0x97d: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_97e:
	/* 0x97e: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_97f:
	/* 0x97f: movzx  eax,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_982:
	/* 0x982: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_986:
	/* 0x986: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_98b:
	/* 0x98b: call   1eea <filter_32ty_map> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2448ULL);
	__x86_sim_call_depth++;
	return 7914ULL;
x86_l_990:
	/* 0x990: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_994:
	/* 0x994: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_995:
	/* 0x995: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_996:
	/* 0x996: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_997:
	/* 0x997: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_99a:
	/* 0x99a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_99c:
	/* 0x99c: cmp    rcx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 32ULL);
x86_l_9a0:
	/* 0x9a0: ja     9db <filter_32ty+0x45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_9db;
	}
x86_l_9a2:
	/* 0x9a2: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_9a7:
	/* 0x9a7: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_9ab:
	/* 0x9ab: jae    9b4 <filter_32ty+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_9b4;
	}
x86_l_9ad:
	/* 0x9ad: call   1b20 <filter_32ty_selector_val> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2482ULL);
	__x86_sim_call_depth++;
	return 6944ULL;
x86_l_9b2:
	/* 0x9b2: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_9b3:
	/* 0x9b3: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_9b4:
	/* 0x9b4: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_9b9:
	/* 0x9b9: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_9bd:
	/* 0x9bd: jb     9d6 <filter_32ty+0x40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_9d6;
	}
x86_l_9bf:
	/* 0x9bf: movabs rdx,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 6442450944ULL);
x86_l_9c9:
	/* 0x9c9: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_9cd:
	/* 0x9cd: jae    9db <filter_32ty+0x45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_9db;
	}
x86_l_9cf:
	/* 0x9cf: call   1d34 <filter_32ty_range> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2516ULL);
	__x86_sim_call_depth++;
	return 7476ULL;
x86_l_9d4:
	/* 0x9d4: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_9d5:
	/* 0x9d5: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_9d6:
	/* 0x9d6: call   1eea <filter_32ty_map> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2523ULL);
	__x86_sim_call_depth++;
	return 7914ULL;
x86_l_9db:
	/* 0x9db: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_9dc:
	/* 0x9dc: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_9dd:
	/* 0x9dd: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_9de:
	/* 0x9de: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_9e1:
	/* 0x9e1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9e3:
	/* 0x9e3: cmp    rcx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 32ULL);
x86_l_9e7:
	/* 0x9e7: ja     a22 <filter_16ty+0x45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_a22;
	}
x86_l_9e9:
	/* 0x9e9: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_9ee:
	/* 0x9ee: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_9f2:
	/* 0x9f2: jae    9fb <filter_16ty+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_9fb;
	}
x86_l_9f4:
	/* 0x9f4: call   16c8 <filter_16ty_selector_val> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2553ULL);
	__x86_sim_call_depth++;
	return 5832ULL;
x86_l_9f9:
	/* 0x9f9: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_9fa:
	/* 0x9fa: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_9fb:
	/* 0x9fb: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_a00:
	/* 0xa00: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_a04:
	/* 0xa04: jb     a1d <filter_16ty+0x40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_a1d;
	}
x86_l_a06:
	/* 0xa06: movabs rdx,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 6442450944ULL);
x86_l_a10:
	/* 0xa10: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_a14:
	/* 0xa14: jae    a22 <filter_16ty+0x45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_a22;
	}
x86_l_a16:
	/* 0xa16: call   18e2 <filter_16ty_range> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2587ULL);
	__x86_sim_call_depth++;
	return 6370ULL;
x86_l_a1b:
	/* 0xa1b: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_a1c:
	/* 0xa1c: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_a1d:
	/* 0xa1d: call   1a9a <filter_16ty_map> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2594ULL);
	__x86_sim_call_depth++;
	return 6810ULL;
x86_l_a22:
	/* 0xa22: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_a23:
	/* 0xa23: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_a24:
	/* 0xa24: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_a25:
	/* 0xa25: mov    rax,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_a28:
	/* 0xa28: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_a2b:
	/* 0xa2b: movsxd rcx,edx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_a2e:
	/* 0xa2e: mov    edx,DWORD PTR [rsi+rcx*1-0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 18446744073709551612ULL);
x86_l_a32:
	/* 0xa32: mov    esi,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_a34:
	/* 0xa34: add    rsi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_a37:
	/* 0xa37: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_a3a:
	/* 0xa3a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a3c:
	/* 0xa3c: cmp    ecx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 25ULL);
x86_l_a3f:
	/* 0xa3f: jg     a55 <filter_char_buf+0x31> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_a55;
	}
x86_l_a41:
	/* 0xa41: lea    edi,[rcx-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_a44:
	/* 0xa44: cmp    edi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_a47:
	/* 0xa47: jb     a8c <filter_char_buf+0x68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_a8c;
	}
x86_l_a49:
	/* 0xa49: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a4c:
	/* 0xa4c: je     a82 <filter_char_buf+0x5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a82;
	}
x86_l_a4e:
	/* 0xa4e: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_a51:
	/* 0xa51: je     a64 <filter_char_buf+0x40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a64;
	}
x86_l_a53:
	/* 0xa53: jmp    aa3 <filter_char_buf+0x7f> */
	goto x86_l_aa3;
x86_l_a55:
	/* 0xa55: cmp    ecx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 32ULL);
x86_l_a58:
	/* 0xa58: jg     a6e <filter_char_buf+0x4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_a6e;
	}
x86_l_a5a:
	/* 0xa5a: cmp    ecx,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 26ULL);
x86_l_a5d:
	/* 0xa5d: je     a82 <filter_char_buf+0x5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a82;
	}
x86_l_a5f:
	/* 0xa5f: cmp    ecx,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 27ULL);
x86_l_a62:
	/* 0xa62: jne    aa3 <filter_char_buf+0x7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_aa3;
	}
x86_l_a64:
	/* 0xa64: mov    edi,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a67:
	/* 0xa67: call   f93 <filter_char_buf_postfix> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2668ULL);
	__x86_sim_call_depth++;
	return 3987ULL;
x86_l_a6c:
	/* 0xa6c: jmp    aa0 <filter_char_buf+0x7c> */
	goto x86_l_aa0;
x86_l_a6e:
	/* 0xa6e: cmp    ecx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 33ULL);
x86_l_a71:
	/* 0xa71: je     a96 <filter_char_buf+0x72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a96;
	}
x86_l_a73:
	/* 0xa73: cmp    ecx,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 34ULL);
x86_l_a76:
	/* 0xa76: jne    aa3 <filter_char_buf+0x7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_aa3;
	}
x86_l_a78:
	/* 0xa78: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_a7b:
	/* 0xa7b: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_a80:
	/* 0xa80: jmp    a9b <filter_char_buf+0x77> */
	goto x86_l_a9b;
x86_l_a82:
	/* 0xa82: mov    edi,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a85:
	/* 0xa85: call   10db <filter_char_buf_prefix> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2698ULL);
	__x86_sim_call_depth++;
	return 4315ULL;
x86_l_a8a:
	/* 0xa8a: jmp    aa0 <filter_char_buf+0x7c> */
	goto x86_l_aa0;
x86_l_a8c:
	/* 0xa8c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_a8f:
	/* 0xa8f: call   117d <filter_char_buf_equal> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2708ULL);
	__x86_sim_call_depth++;
	return 4477ULL;
x86_l_a94:
	/* 0xa94: jmp    aa0 <filter_char_buf+0x7c> */
	goto x86_l_aa0;
x86_l_a96:
	/* 0xa96: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_a99:
	/* 0xa99: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a9b:
	/* 0xa9b: call   14b2 <filter_char_substring> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2720ULL);
	__x86_sim_call_depth++;
	return 5298ULL;
x86_l_aa0:
	/* 0xaa0: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_aa3:
	/* 0xaa3: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_aa6:
	/* 0xaa6: ja     ac5 <filter_char_buf+0xa1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_ac5;
	}
x86_l_aa8:
	/* 0xaa8: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_aaa:
	/* 0xaaa: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_ab4:
	/* 0xab4: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_ab8:
	/* 0xab8: jae    ac5 <filter_char_buf+0xa1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_ac5;
	}
x86_l_aba:
	/* 0xaba: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_abc:
	/* 0xabc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_abf:
	/* 0xabf: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_ac2:
	/* 0xac2: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_ac5:
	/* 0xac5: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_ac6:
	/* 0xac6: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_ac7:
	/* 0xac7: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_ac8:
	/* 0xac8: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_acb:
	/* 0xacb: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_acd:
	/* 0xacd: cmp    rcx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 32ULL);
x86_l_ad1:
	/* 0xad1: ja     b0c <filter_64ty+0x45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_b0c;
	}
x86_l_ad3:
	/* 0xad3: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_ad8:
	/* 0xad8: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_adc:
	/* 0xadc: jae    ae5 <filter_64ty+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_ae5;
	}
x86_l_ade:
	/* 0xade: call   b0e <filter_64ty_selector_val> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2787ULL);
	__x86_sim_call_depth++;
	return 2830ULL;
x86_l_ae3:
	/* 0xae3: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_ae4:
	/* 0xae4: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_ae5:
	/* 0xae5: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_aea:
	/* 0xaea: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_aee:
	/* 0xaee: jb     b07 <filter_64ty+0x40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_b07;
	}
x86_l_af0:
	/* 0xaf0: movabs rdx,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 6442450944ULL);
x86_l_afa:
	/* 0xafa: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_afe:
	/* 0xafe: jae    b0c <filter_64ty+0x45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_b0c;
	}
x86_l_b00:
	/* 0xb00: call   d40 <filter_64ty_range> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2821ULL);
	__x86_sim_call_depth++;
	return 3392ULL;
x86_l_b05:
	/* 0xb05: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_b06:
	/* 0xb06: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_b07:
	/* 0xb07: call   f1b <filter_64ty_map> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2828ULL);
	__x86_sim_call_depth++;
	return 3867ULL;
x86_l_b0c:
	/* 0xb0c: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_b0d:
	/* 0xb0d: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
	return 0xffffffffffffffffULL;
}

static __noinline __u64 tetragon_bpf_multi_usdt_v61_generic_usdt_filter_arg_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 2830ULL: goto x86_l_b0e;
	case 2833ULL: goto x86_l_b11;
	case 2838ULL: goto x86_l_b16;
	case 2842ULL: goto x86_l_b1a;
	case 2844ULL: goto x86_l_b1c;
	case 2854ULL: goto x86_l_b26;
	case 2858ULL: goto x86_l_b2a;
	case 2860ULL: goto x86_l_b2c;
	case 2861ULL: goto x86_l_b2d;
	case 2866ULL: goto x86_l_b32;
	case 2870ULL: goto x86_l_b36;
	case 2872ULL: goto x86_l_b38;
	case 2875ULL: goto x86_l_b3b;
	case 2879ULL: goto x86_l_b3f;
	case 2885ULL: goto x86_l_b45;
	case 2887ULL: goto x86_l_b47;
	case 2890ULL: goto x86_l_b4a;
	case 2893ULL: goto x86_l_b4d;
	case 2894ULL: goto x86_l_b4e;
	case 2898ULL: goto x86_l_b52;
	case 2900ULL: goto x86_l_b54;
	case 2903ULL: goto x86_l_b57;
	case 2907ULL: goto x86_l_b5b;
	case 2909ULL: goto x86_l_b5d;
	case 2912ULL: goto x86_l_b60;
	case 2915ULL: goto x86_l_b63;
	case 2921ULL: goto x86_l_b69;
	case 2925ULL: goto x86_l_b6d;
	case 2927ULL: goto x86_l_b6f;
	case 2930ULL: goto x86_l_b72;
	case 2936ULL: goto x86_l_b78;
	case 2940ULL: goto x86_l_b7c;
	case 2942ULL: goto x86_l_b7e;
	case 2945ULL: goto x86_l_b81;
	case 2951ULL: goto x86_l_b87;
	case 2955ULL: goto x86_l_b8b;
	case 2957ULL: goto x86_l_b8d;
	case 2962ULL: goto x86_l_b92;
	case 2965ULL: goto x86_l_b95;
	case 2967ULL: goto x86_l_b97;
	case 2970ULL: goto x86_l_b9a;
	case 2976ULL: goto x86_l_ba0;
	case 2979ULL: goto x86_l_ba3;
	case 2982ULL: goto x86_l_ba6;
	case 2988ULL: goto x86_l_bac;
	case 2993ULL: goto x86_l_bb1;
	case 2996ULL: goto x86_l_bb4;
	case 3002ULL: goto x86_l_bba;
	case 3005ULL: goto x86_l_bbd;
	case 3009ULL: goto x86_l_bc1;
	case 3015ULL: goto x86_l_bc7;
	case 3018ULL: goto x86_l_bca;
	case 3021ULL: goto x86_l_bcd;
	case 3027ULL: goto x86_l_bd3;
	case 3031ULL: goto x86_l_bd7;
	case 3037ULL: goto x86_l_bdd;
	case 3040ULL: goto x86_l_be0;
	case 3046ULL: goto x86_l_be6;
	case 3050ULL: goto x86_l_bea;
	case 3056ULL: goto x86_l_bf0;
	case 3059ULL: goto x86_l_bf3;
	case 3065ULL: goto x86_l_bf9;
	case 3069ULL: goto x86_l_bfd;
	case 3075ULL: goto x86_l_c03;
	case 3080ULL: goto x86_l_c08;
	case 3083ULL: goto x86_l_c0b;
	case 3086ULL: goto x86_l_c0e;
	case 3092ULL: goto x86_l_c14;
	case 3097ULL: goto x86_l_c19;
	case 3100ULL: goto x86_l_c1c;
	case 3106ULL: goto x86_l_c22;
	case 3109ULL: goto x86_l_c25;
	case 3113ULL: goto x86_l_c29;
	case 3119ULL: goto x86_l_c2f;
	case 3122ULL: goto x86_l_c32;
	case 3125ULL: goto x86_l_c35;
	case 3131ULL: goto x86_l_c3b;
	case 3135ULL: goto x86_l_c3f;
	case 3141ULL: goto x86_l_c45;
	case 3144ULL: goto x86_l_c48;
	case 3150ULL: goto x86_l_c4e;
	case 3154ULL: goto x86_l_c52;
	case 3160ULL: goto x86_l_c58;
	case 3163ULL: goto x86_l_c5b;
	case 3169ULL: goto x86_l_c61;
	case 3173ULL: goto x86_l_c65;
	case 3179ULL: goto x86_l_c6b;
	case 3184ULL: goto x86_l_c70;
	case 3187ULL: goto x86_l_c73;
	case 3190ULL: goto x86_l_c76;
	case 3192ULL: goto x86_l_c78;
	case 3196ULL: goto x86_l_c7c;
	case 3202ULL: goto x86_l_c82;
	case 3205ULL: goto x86_l_c85;
	case 3207ULL: goto x86_l_c87;
	case 3211ULL: goto x86_l_c8b;
	case 3217ULL: goto x86_l_c91;
	case 3220ULL: goto x86_l_c94;
	case 3222ULL: goto x86_l_c96;
	case 3226ULL: goto x86_l_c9a;
	case 3232ULL: goto x86_l_ca0;
	case 3235ULL: goto x86_l_ca3;
	case 3241ULL: goto x86_l_ca9;
	case 3243ULL: goto x86_l_cab;
	case 3253ULL: goto x86_l_cb5;
	case 3257ULL: goto x86_l_cb9;
	case 3263ULL: goto x86_l_cbf;
	case 3265ULL: goto x86_l_cc1;
	case 3268ULL: goto x86_l_cc4;
	case 3272ULL: goto x86_l_cc8;
	case 3278ULL: goto x86_l_cce;
	case 3281ULL: goto x86_l_cd1;
	case 3284ULL: goto x86_l_cd4;
	case 3286ULL: goto x86_l_cd6;
	case 3290ULL: goto x86_l_cda;
	case 3296ULL: goto x86_l_ce0;
	case 3299ULL: goto x86_l_ce3;
	case 3301ULL: goto x86_l_ce5;
	case 3305ULL: goto x86_l_ce9;
	case 3311ULL: goto x86_l_cef;
	case 3314ULL: goto x86_l_cf2;
	case 3316ULL: goto x86_l_cf4;
	case 3320ULL: goto x86_l_cf8;
	case 3326ULL: goto x86_l_cfe;
	case 3328ULL: goto x86_l_d00;
	case 3331ULL: goto x86_l_d03;
	case 3335ULL: goto x86_l_d07;
	case 3341ULL: goto x86_l_d0d;
	case 3344ULL: goto x86_l_d10;
	case 3347ULL: goto x86_l_d13;
	case 3349ULL: goto x86_l_d15;
	case 3353ULL: goto x86_l_d19;
	case 3359ULL: goto x86_l_d1f;
	case 3362ULL: goto x86_l_d22;
	case 3364ULL: goto x86_l_d24;
	case 3368ULL: goto x86_l_d28;
	case 3374ULL: goto x86_l_d2e;
	case 3377ULL: goto x86_l_d31;
	case 3379ULL: goto x86_l_d33;
	case 3383ULL: goto x86_l_d37;
	case 3389ULL: goto x86_l_d3d;
	case 3391ULL: goto x86_l_d3f;
	case 3392ULL: goto x86_l_d40;
	case 3395ULL: goto x86_l_d43;
	case 3398ULL: goto x86_l_d46;
	case 3401ULL: goto x86_l_d49;
	case 3407ULL: goto x86_l_d4f;
	case 3412ULL: goto x86_l_d54;
	case 3415ULL: goto x86_l_d57;
	case 3421ULL: goto x86_l_d5d;
	case 3424ULL: goto x86_l_d60;
	case 3427ULL: goto x86_l_d63;
	case 3429ULL: goto x86_l_d65;
	case 3434ULL: goto x86_l_d6a;
	case 3438ULL: goto x86_l_d6e;
	case 3440ULL: goto x86_l_d70;
	case 3444ULL: goto x86_l_d74;
	case 3450ULL: goto x86_l_d7a;
	case 3453ULL: goto x86_l_d7d;
	case 3456ULL: goto x86_l_d80;
	case 3462ULL: goto x86_l_d86;
	case 3466ULL: goto x86_l_d8a;
	case 3468ULL: goto x86_l_d8c;
	case 3472ULL: goto x86_l_d90;
	case 3478ULL: goto x86_l_d96;
	case 3481ULL: goto x86_l_d99;
	case 3487ULL: goto x86_l_d9f;
	case 3491ULL: goto x86_l_da3;
	case 3493ULL: goto x86_l_da5;
	case 3497ULL: goto x86_l_da9;
	case 3503ULL: goto x86_l_daf;
	case 3506ULL: goto x86_l_db2;
	case 3512ULL: goto x86_l_db8;
	case 3514ULL: goto x86_l_dba;
	case 3518ULL: goto x86_l_dbe;
	case 3524ULL: goto x86_l_dc4;
	case 3528ULL: goto x86_l_dc8;
	case 3534ULL: goto x86_l_dce;
	case 3539ULL: goto x86_l_dd3;
	case 3542ULL: goto x86_l_dd6;
	case 3546ULL: goto x86_l_dda;
	case 3550ULL: goto x86_l_dde;
	case 3554ULL: goto x86_l_de2;
	case 3557ULL: goto x86_l_de5;
	case 3560ULL: goto x86_l_de8;
	case 3563ULL: goto x86_l_deb;
	case 3569ULL: goto x86_l_df1;
	case 3573ULL: goto x86_l_df5;
	case 3577ULL: goto x86_l_df9;
	case 3581ULL: goto x86_l_dfd;
	case 3585ULL: goto x86_l_e01;
	case 3588ULL: goto x86_l_e04;
	case 3591ULL: goto x86_l_e07;
	case 3594ULL: goto x86_l_e0a;
	case 3600ULL: goto x86_l_e10;
	case 3604ULL: goto x86_l_e14;
	case 3608ULL: goto x86_l_e18;
	case 3612ULL: goto x86_l_e1c;
	case 3616ULL: goto x86_l_e20;
	case 3619ULL: goto x86_l_e23;
	case 3622ULL: goto x86_l_e26;
	case 3625ULL: goto x86_l_e29;
	case 3631ULL: goto x86_l_e2f;
	case 3635ULL: goto x86_l_e33;
	case 3638ULL: goto x86_l_e36;
	case 3642ULL: goto x86_l_e3a;
	case 3646ULL: goto x86_l_e3e;
	case 3651ULL: goto x86_l_e43;
	case 3654ULL: goto x86_l_e46;
	case 3657ULL: goto x86_l_e49;
	case 3659ULL: goto x86_l_e4b;
	case 3664ULL: goto x86_l_e50;
	case 3668ULL: goto x86_l_e54;
	case 3670ULL: goto x86_l_e56;
	case 3674ULL: goto x86_l_e5a;
	case 3676ULL: goto x86_l_e5c;
	case 3677ULL: goto x86_l_e5d;
	case 3680ULL: goto x86_l_e60;
	case 3684ULL: goto x86_l_e64;
	case 3688ULL: goto x86_l_e68;
	case 3692ULL: goto x86_l_e6c;
	case 3695ULL: goto x86_l_e6f;
	case 3698ULL: goto x86_l_e72;
	case 3701ULL: goto x86_l_e75;
	case 3707ULL: goto x86_l_e7b;
	case 3711ULL: goto x86_l_e7f;
	case 3715ULL: goto x86_l_e83;
	case 3719ULL: goto x86_l_e87;
	case 3723ULL: goto x86_l_e8b;
	case 3726ULL: goto x86_l_e8e;
	case 3729ULL: goto x86_l_e91;
	case 3732ULL: goto x86_l_e94;
	case 3734ULL: goto x86_l_e96;
	case 3738ULL: goto x86_l_e9a;
	case 3742ULL: goto x86_l_e9e;
	case 3746ULL: goto x86_l_ea2;
	case 3750ULL: goto x86_l_ea6;
	case 3753ULL: goto x86_l_ea9;
	case 3756ULL: goto x86_l_eac;
	case 3759ULL: goto x86_l_eaf;
	case 3761ULL: goto x86_l_eb1;
	case 3765ULL: goto x86_l_eb5;
	case 3768ULL: goto x86_l_eb8;
	case 3772ULL: goto x86_l_ebc;
	case 3776ULL: goto x86_l_ec0;
	case 3779ULL: goto x86_l_ec3;
	case 3782ULL: goto x86_l_ec6;
	case 3784ULL: goto x86_l_ec8;
	case 3787ULL: goto x86_l_ecb;
	case 3790ULL: goto x86_l_ece;
	case 3792ULL: goto x86_l_ed0;
	case 3796ULL: goto x86_l_ed4;
	case 3798ULL: goto x86_l_ed6;
	case 3802ULL: goto x86_l_eda;
	case 3804ULL: goto x86_l_edc;
	case 3807ULL: goto x86_l_edf;
	case 3809ULL: goto x86_l_ee1;
	case 3813ULL: goto x86_l_ee5;
	case 3815ULL: goto x86_l_ee7;
	case 3819ULL: goto x86_l_eeb;
	case 3825ULL: goto x86_l_ef1;
	case 3828ULL: goto x86_l_ef4;
	case 3830ULL: goto x86_l_ef6;
	case 3832ULL: goto x86_l_ef8;
	case 3836ULL: goto x86_l_efc;
	case 3838ULL: goto x86_l_efe;
	case 3842ULL: goto x86_l_f02;
	case 3848ULL: goto x86_l_f08;
	case 3850ULL: goto x86_l_f0a;
	case 3852ULL: goto x86_l_f0c;
	case 3855ULL: goto x86_l_f0f;
	case 3858ULL: goto x86_l_f12;
	case 3861ULL: goto x86_l_f15;
	case 3863ULL: goto x86_l_f17;
	case 3866ULL: goto x86_l_f1a;
	case 3867ULL: goto x86_l_f1b;
	case 3869ULL: goto x86_l_f1d;
	case 3870ULL: goto x86_l_f1e;
	case 3874ULL: goto x86_l_f22;
	case 3877ULL: goto x86_l_f25;
	case 3880ULL: goto x86_l_f28;
	case 3884ULL: goto x86_l_f2c;
	case 3888ULL: goto x86_l_f30;
	case 3893ULL: goto x86_l_f35;
	case 3900ULL: goto x86_l_f3c;
	case 3905ULL: goto x86_l_f41;
	case 3907ULL: goto x86_l_f43;
	case 3910ULL: goto x86_l_f46;
	case 3912ULL: goto x86_l_f48;
	case 3915ULL: goto x86_l_f4b;
	case 3920ULL: goto x86_l_f50;
	case 3925ULL: goto x86_l_f55;
	case 3930ULL: goto x86_l_f5a;
	case 3933ULL: goto x86_l_f5d;
	case 3935ULL: goto x86_l_f5f;
	case 3938ULL: goto x86_l_f62;
	case 3941ULL: goto x86_l_f65;
	case 3943ULL: goto x86_l_f67;
	case 3946ULL: goto x86_l_f6a;
	case 3948ULL: goto x86_l_f6c;
	case 3951ULL: goto x86_l_f6f;
	case 3954ULL: goto x86_l_f72;
	case 3956ULL: goto x86_l_f74;
	case 3958ULL: goto x86_l_f76;
	case 3962ULL: goto x86_l_f7a;
	case 3963ULL: goto x86_l_f7b;
	case 3965ULL: goto x86_l_f7d;
	case 3966ULL: goto x86_l_f7e;
	case 3969ULL: goto x86_l_f81;
	case 3972ULL: goto x86_l_f84;
	case 3974ULL: goto x86_l_f86;
	case 3976ULL: goto x86_l_f88;
	case 3979ULL: goto x86_l_f8b;
	case 3983ULL: goto x86_l_f8f;
	case 3984ULL: goto x86_l_f90;
	case 3986ULL: goto x86_l_f92;
	case 3987ULL: goto x86_l_f93;
	case 3989ULL: goto x86_l_f95;
	case 3991ULL: goto x86_l_f97;
	case 3992ULL: goto x86_l_f98;
	case 3996ULL: goto x86_l_f9c;
	case 3998ULL: goto x86_l_f9e;
	case 4001ULL: goto x86_l_fa1;
	case 4005ULL: goto x86_l_fa5;
	case 4013ULL: goto x86_l_fad;
	case 4018ULL: goto x86_l_fb2;
	case 4025ULL: goto x86_l_fb9;
	case 4030ULL: goto x86_l_fbe;
	case 4032ULL: goto x86_l_fc0;
	case 4035ULL: goto x86_l_fc3;
	case 4037ULL: goto x86_l_fc5;
	case 4039ULL: goto x86_l_fc7;
	case 4045ULL: goto x86_l_fcd;
	case 4048ULL: goto x86_l_fd0;
	case 4054ULL: goto x86_l_fd6;
	case 4059ULL: goto x86_l_fdb;
	case 4066ULL: goto x86_l_fe2;
	case 4071ULL: goto x86_l_fe7;
	case 4073ULL: goto x86_l_fe9;
	case 4076ULL: goto x86_l_fec;
	case 4082ULL: goto x86_l_ff2;
	case 4085ULL: goto x86_l_ff5;
	case 4090ULL: goto x86_l_ffa;
	case 4093ULL: goto x86_l_ffd;
	case 4096ULL: goto x86_l_1000;
	case 4098ULL: goto x86_l_1002;
	case 4100ULL: goto x86_l_1004;
	case 4103ULL: goto x86_l_1007;
	case 4106ULL: goto x86_l_100a;
	case 4110ULL: goto x86_l_100e;
	case 4113ULL: goto x86_l_1011;
	case 4117ULL: goto x86_l_1015;
	case 4119ULL: goto x86_l_1017;
	case 4126ULL: goto x86_l_101e;
	case 4130ULL: goto x86_l_1022;
	case 4134ULL: goto x86_l_1026;
	case 4141ULL: goto x86_l_102d;
	case 4146ULL: goto x86_l_1032;
	case 4150ULL: goto x86_l_1036;
	case 4154ULL: goto x86_l_103a;
	case 4158ULL: goto x86_l_103e;
	case 4160ULL: goto x86_l_1040;
	case 4164ULL: goto x86_l_1044;
	case 4168ULL: goto x86_l_1048;
	case 4175ULL: goto x86_l_104f;
	case 4180ULL: goto x86_l_1054;
	case 4184ULL: goto x86_l_1058;
	case 4188ULL: goto x86_l_105c;
	case 4190ULL: goto x86_l_105e;
	case 4194ULL: goto x86_l_1062;
	case 4198ULL: goto x86_l_1066;
	case 4205ULL: goto x86_l_106d;
	case 4210ULL: goto x86_l_1072;
	case 4214ULL: goto x86_l_1076;
	case 4217ULL: goto x86_l_1079;
	case 4220ULL: goto x86_l_107c;
	case 4222ULL: goto x86_l_107e;
	case 4226ULL: goto x86_l_1082;
	case 4228ULL: goto x86_l_1084;
	case 4232ULL: goto x86_l_1088;
	case 4236ULL: goto x86_l_108c;
	case 4243ULL: goto x86_l_1093;
	case 4248ULL: goto x86_l_1098;
	case 4251ULL: goto x86_l_109b;
	default: return 0xffffffffffffffffULL;
	}
x86_l_b0e:
	/* 0xb0e: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_b11:
	/* 0xb11: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b16:
	/* 0xb16: cmp    rcx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 37ULL);
x86_l_b1a:
	/* 0xb1a: ja     b92 <filter_64ty_selector_val+0x84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_b92;
	}
x86_l_b1c:
	/* 0xb1c: movabs rdx,0x200c000040 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280128ULL);
x86_l_b26:
	/* 0xb26: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_b2a:
	/* 0xb2a: jae    b2d <filter_64ty_selector_val+0x1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_b2d;
	}
x86_l_b2c:
	/* 0xb2c: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_b2d:
	/* 0xb2d: mov    edx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 24ULL);
x86_l_b32:
	/* 0xb32: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_b36:
	/* 0xb36: jae    b4e <filter_64ty_selector_val+0x40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_b4e;
	}
x86_l_b38:
	/* 0xb38: mov    rdx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b3b:
	/* 0xb3b: cmp    rdx,QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_b3f:
	/* 0xb3f: jne    c70 <filter_64ty_selector_val+0x162> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_c70;
	}
x86_l_b45:
	/* 0xb45: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b47:
	/* 0xb47: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_b4a:
	/* 0xb4a: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_b4d:
	/* 0xb4d: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_b4e:
	/* 0xb4e: cmp    rcx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 12ULL);
x86_l_b52:
	/* 0xb52: jne    b92 <filter_64ty_selector_val+0x84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b92;
	}
x86_l_b54:
	/* 0xb54: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b57:
	/* 0xb57: test   QWORD PTR [rdi+0x10],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b5b:
	/* 0xb5b: jne    b2c <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b2c;
	}
x86_l_b5d:
	/* 0xb5d: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b60:
	/* 0xb60: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_b63:
	/* 0xb63: jb     d3d <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d3d;
	}
x86_l_b69:
	/* 0xb69: test   QWORD PTR [rdi+0x18],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b6d:
	/* 0xb6d: jne    b2c <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b2c;
	}
x86_l_b6f:
	/* 0xb6f: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_b72:
	/* 0xb72: jb     d3d <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d3d;
	}
x86_l_b78:
	/* 0xb78: test   QWORD PTR [rdi+0x20],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b7c:
	/* 0xb7c: jne    b2c <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b2c;
	}
x86_l_b7e:
	/* 0xb7e: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_b81:
	/* 0xb81: jb     d3d <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d3d;
	}
x86_l_b87:
	/* 0xb87: test   QWORD PTR [rdi+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b8b:
	/* 0xb8b: jne    b2c <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b2c;
	}
x86_l_b8d:
	/* 0xb8d: jmp    d3d <filter_64ty_selector_val+0x22f> */
	goto x86_l_d3d;
x86_l_b92:
	/* 0xb92: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_b95:
	/* 0xb95: je     c08 <filter_64ty_selector_val+0xfa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c08;
	}
x86_l_b97:
	/* 0xb97: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_b9a:
	/* 0xb9a: jne    d3d <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_d3d;
	}
x86_l_ba0:
	/* 0xba0: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_ba3:
	/* 0xba3: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_ba6:
	/* 0xba6: ja     d00 <filter_64ty_selector_val+0x1f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_d00;
	}
x86_l_bac:
	/* 0xbac: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_bb1:
	/* 0xbb1: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_bb4:
	/* 0xbb4: jae    d00 <filter_64ty_selector_val+0x1f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_d00;
	}
x86_l_bba:
	/* 0xbba: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bbd:
	/* 0xbbd: cmp    rcx,QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_bc1:
	/* 0xbc1: jl     b2c <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_b2c;
	}
x86_l_bc7:
	/* 0xbc7: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bca:
	/* 0xbca: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_bcd:
	/* 0xbcd: jb     d3d <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d3d;
	}
x86_l_bd3:
	/* 0xbd3: cmp    rcx,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_bd7:
	/* 0xbd7: jl     b2c <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_b2c;
	}
x86_l_bdd:
	/* 0xbdd: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_be0:
	/* 0xbe0: jb     d3d <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d3d;
	}
x86_l_be6:
	/* 0xbe6: cmp    rcx,QWORD PTR [rdi+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_bea:
	/* 0xbea: jl     b2c <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_b2c;
	}
x86_l_bf0:
	/* 0xbf0: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_bf3:
	/* 0xbf3: jb     d3d <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d3d;
	}
x86_l_bf9:
	/* 0xbf9: cmp    rcx,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_bfd:
	/* 0xbfd: jl     b2c <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_b2c;
	}
x86_l_c03:
	/* 0xc03: jmp    d3d <filter_64ty_selector_val+0x22f> */
	goto x86_l_d3d;
x86_l_c08:
	/* 0xc08: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_c0b:
	/* 0xc0b: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_c0e:
	/* 0xc0e: ja     cc1 <filter_64ty_selector_val+0x1b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_cc1;
	}
x86_l_c14:
	/* 0xc14: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_c19:
	/* 0xc19: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_c1c:
	/* 0xc1c: jae    cc1 <filter_64ty_selector_val+0x1b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_cc1;
	}
x86_l_c22:
	/* 0xc22: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c25:
	/* 0xc25: cmp    rcx,QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_c29:
	/* 0xc29: jg     b2c <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_b2c;
	}
x86_l_c2f:
	/* 0xc2f: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c32:
	/* 0xc32: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_c35:
	/* 0xc35: jb     d3d <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d3d;
	}
x86_l_c3b:
	/* 0xc3b: cmp    rcx,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_c3f:
	/* 0xc3f: jg     b2c <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_b2c;
	}
x86_l_c45:
	/* 0xc45: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_c48:
	/* 0xc48: jb     d3d <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d3d;
	}
x86_l_c4e:
	/* 0xc4e: cmp    rcx,QWORD PTR [rdi+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_c52:
	/* 0xc52: jg     b2c <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_b2c;
	}
x86_l_c58:
	/* 0xc58: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_c5b:
	/* 0xc5b: jb     d3d <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d3d;
	}
x86_l_c61:
	/* 0xc61: cmp    rcx,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_c65:
	/* 0xc65: jg     b2c <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_b2c;
	}
x86_l_c6b:
	/* 0xc6b: jmp    d3d <filter_64ty_selector_val+0x22f> */
	goto x86_l_d3d;
x86_l_c70:
	/* 0xc70: mov    esi,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c73:
	/* 0xc73: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_c76:
	/* 0xc76: jb     ca0 <filter_64ty_selector_val+0x192> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_ca0;
	}
x86_l_c78:
	/* 0xc78: cmp    rdx,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_c7c:
	/* 0xc7c: je     b45 <filter_64ty_selector_val+0x37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b45;
	}
x86_l_c82:
	/* 0xc82: cmp    esi,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 25ULL);
x86_l_c85:
	/* 0xc85: jb     ca0 <filter_64ty_selector_val+0x192> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_ca0;
	}
x86_l_c87:
	/* 0xc87: cmp    rdx,QWORD PTR [rdi+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_c8b:
	/* 0xc8b: je     b45 <filter_64ty_selector_val+0x37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b45;
	}
x86_l_c91:
	/* 0xc91: cmp    esi,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 33ULL);
x86_l_c94:
	/* 0xc94: jb     ca0 <filter_64ty_selector_val+0x192> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_ca0;
	}
x86_l_c96:
	/* 0xc96: cmp    rdx,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_c9a:
	/* 0xc9a: je     b45 <filter_64ty_selector_val+0x37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b45;
	}
x86_l_ca0:
	/* 0xca0: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_ca3:
	/* 0xca3: ja     d3d <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_d3d;
	}
x86_l_ca9:
	/* 0xca9: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_cab:
	/* 0xcab: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_cb5:
	/* 0xcb5: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_cb9:
	/* 0xcb9: jb     b2c <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_b2c;
	}
x86_l_cbf:
	/* 0xcbf: jmp    d3d <filter_64ty_selector_val+0x22f> */
	goto x86_l_d3d;
x86_l_cc1:
	/* 0xcc1: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cc4:
	/* 0xcc4: cmp    rcx,QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_cc8:
	/* 0xcc8: ja     b2c <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_b2c;
	}
x86_l_cce:
	/* 0xcce: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cd1:
	/* 0xcd1: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_cd4:
	/* 0xcd4: jb     d3d <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d3d;
	}
x86_l_cd6:
	/* 0xcd6: cmp    rcx,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_cda:
	/* 0xcda: ja     b2c <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_b2c;
	}
x86_l_ce0:
	/* 0xce0: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_ce3:
	/* 0xce3: jb     d3d <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d3d;
	}
x86_l_ce5:
	/* 0xce5: cmp    rcx,QWORD PTR [rdi+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_ce9:
	/* 0xce9: ja     b2c <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_b2c;
	}
x86_l_cef:
	/* 0xcef: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_cf2:
	/* 0xcf2: jb     d3d <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d3d;
	}
x86_l_cf4:
	/* 0xcf4: cmp    rcx,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_cf8:
	/* 0xcf8: ja     b2c <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_b2c;
	}
x86_l_cfe:
	/* 0xcfe: jmp    d3d <filter_64ty_selector_val+0x22f> */
	goto x86_l_d3d;
x86_l_d00:
	/* 0xd00: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d03:
	/* 0xd03: cmp    rcx,QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_d07:
	/* 0xd07: jb     b2c <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_b2c;
	}
x86_l_d0d:
	/* 0xd0d: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d10:
	/* 0xd10: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_d13:
	/* 0xd13: jb     d3d <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d3d;
	}
x86_l_d15:
	/* 0xd15: cmp    rcx,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_d19:
	/* 0xd19: jb     b2c <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_b2c;
	}
x86_l_d1f:
	/* 0xd1f: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_d22:
	/* 0xd22: jb     d3d <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d3d;
	}
x86_l_d24:
	/* 0xd24: cmp    rcx,QWORD PTR [rdi+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_d28:
	/* 0xd28: jb     b2c <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_b2c;
	}
x86_l_d2e:
	/* 0xd2e: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_d31:
	/* 0xd31: jb     d3d <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d3d;
	}
x86_l_d33:
	/* 0xd33: cmp    rcx,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_d37:
	/* 0xd37: jb     b2c <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_b2c;
	}
x86_l_d3d:
	/* 0xd3d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d3f:
	/* 0xd3f: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_d40:
	/* 0xd40: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_d43:
	/* 0xd43: mov    eax,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_d46:
	/* 0xd46: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_d49:
	/* 0xd49: ja     e43 <filter_64ty_range+0x103> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_e43;
	}
x86_l_d4f:
	/* 0xd4f: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_d54:
	/* 0xd54: bt     edx,eax */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_d57:
	/* 0xd57: jae    e43 <filter_64ty_range+0x103> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_e43;
	}
x86_l_d5d:
	/* 0xd5d: mov    rsi,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d60:
	/* 0xd60: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_d63:
	/* 0xd63: jne    dd3 <filter_64ty_range+0x93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_dd3;
	}
x86_l_d65:
	/* 0xd65: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d6a:
	/* 0xd6a: cmp    QWORD PTR [rdi+0x10],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d6e:
	/* 0xd6e: jg     d7a <filter_64ty_range+0x3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_d7a;
	}
x86_l_d70:
	/* 0xd70: cmp    rsi,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_d74:
	/* 0xd74: jle    e5c <filter_64ty_range+0x11c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_e5c;
	}
x86_l_d7a:
	/* 0xd7a: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d7d:
	/* 0xd7d: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_d80:
	/* 0xd80: jb     f0a <filter_64ty_range+0x1ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f0a;
	}
x86_l_d86:
	/* 0xd86: cmp    QWORD PTR [rdi+0x20],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d8a:
	/* 0xd8a: jg     d96 <filter_64ty_range+0x56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_d96;
	}
x86_l_d8c:
	/* 0xd8c: cmp    rsi,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_d90:
	/* 0xd90: jle    e5c <filter_64ty_range+0x11c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_e5c;
	}
x86_l_d96:
	/* 0xd96: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_d99:
	/* 0xd99: jb     f0a <filter_64ty_range+0x1ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f0a;
	}
x86_l_d9f:
	/* 0xd9f: cmp    QWORD PTR [rdi+0x30],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_da3:
	/* 0xda3: jg     daf <filter_64ty_range+0x6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_daf;
	}
x86_l_da5:
	/* 0xda5: cmp    rsi,QWORD PTR [rdi+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_da9:
	/* 0xda9: jle    e5c <filter_64ty_range+0x11c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_e5c;
	}
x86_l_daf:
	/* 0xdaf: cmp    edx,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 57ULL);
x86_l_db2:
	/* 0xdb2: jb     f0a <filter_64ty_range+0x1ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f0a;
	}
x86_l_db8:
	/* 0xdb8: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_dba:
	/* 0xdba: cmp    QWORD PTR [rdi+0x40],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_dbe:
	/* 0xdbe: jg     f0c <filter_64ty_range+0x1cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_f0c;
	}
x86_l_dc4:
	/* 0xdc4: cmp    rsi,QWORD PTR [rdi+0x48] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 72ULL);
x86_l_dc8:
	/* 0xdc8: jle    e5c <filter_64ty_range+0x11c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_e5c;
	}
x86_l_dce:
	/* 0xdce: jmp    f0c <filter_64ty_range+0x1cc> */
	goto x86_l_f0c;
x86_l_dd3:
	/* 0xdd3: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dd6:
	/* 0xdd6: cmp    QWORD PTR [rdi+0x10],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dda:
	/* 0xdda: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_dde:
	/* 0xdde: cmp    rsi,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_de2:
	/* 0xde2: setle  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_LE);
x86_l_de5:
	/* 0xde5: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_de8:
	/* 0xde8: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_deb:
	/* 0xdeb: jb     f0c <filter_64ty_range+0x1cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f0c;
	}
x86_l_df1:
	/* 0xdf1: cmp    QWORD PTR [rdi+0x20],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_df5:
	/* 0xdf5: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_df9:
	/* 0xdf9: cmp    rsi,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_dfd:
	/* 0xdfd: setle  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_LE);
x86_l_e01:
	/* 0xe01: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_e04:
	/* 0xe04: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_e07:
	/* 0xe07: cmp    eax,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 41ULL);
x86_l_e0a:
	/* 0xe0a: jb     f0c <filter_64ty_range+0x1cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f0c;
	}
x86_l_e10:
	/* 0xe10: cmp    QWORD PTR [rdi+0x30],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e14:
	/* 0xe14: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_e18:
	/* 0xe18: cmp    rsi,QWORD PTR [rdi+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_e1c:
	/* 0xe1c: setle  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_LE);
x86_l_e20:
	/* 0xe20: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_e23:
	/* 0xe23: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_e26:
	/* 0xe26: cmp    eax,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 57ULL);
x86_l_e29:
	/* 0xe29: jb     f0c <filter_64ty_range+0x1cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f0c;
	}
x86_l_e2f:
	/* 0xe2f: cmp    QWORD PTR [rdi+0x40],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_e33:
	/* 0xe33: setle  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_LE);
x86_l_e36:
	/* 0xe36: cmp    rsi,QWORD PTR [rdi+0x48] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 72ULL);
x86_l_e3a:
	/* 0xe3a: setle  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_LE);
x86_l_e3e:
	/* 0xe3e: jmp    ec0 <filter_64ty_range+0x180> */
	goto x86_l_ec0;
x86_l_e43:
	/* 0xe43: mov    rsi,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e46:
	/* 0xe46: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_e49:
	/* 0xe49: jne    e5d <filter_64ty_range+0x11d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_e5d;
	}
x86_l_e4b:
	/* 0xe4b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e50:
	/* 0xe50: cmp    QWORD PTR [rdi+0x10],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e54:
	/* 0xe54: ja     ec8 <filter_64ty_range+0x188> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_ec8;
	}
x86_l_e56:
	/* 0xe56: cmp    rsi,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_e5a:
	/* 0xe5a: ja     ec8 <filter_64ty_range+0x188> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_ec8;
	}
x86_l_e5c:
	/* 0xe5c: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_e5d:
	/* 0xe5d: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e60:
	/* 0xe60: cmp    QWORD PTR [rdi+0x10],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e64:
	/* 0xe64: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_e68:
	/* 0xe68: cmp    rsi,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_e6c:
	/* 0xe6c: setbe  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_BE);
x86_l_e6f:
	/* 0xe6f: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_e72:
	/* 0xe72: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_e75:
	/* 0xe75: jb     f0c <filter_64ty_range+0x1cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f0c;
	}
x86_l_e7b:
	/* 0xe7b: cmp    QWORD PTR [rdi+0x20],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e7f:
	/* 0xe7f: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_e83:
	/* 0xe83: cmp    rsi,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_e87:
	/* 0xe87: setbe  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_BE);
x86_l_e8b:
	/* 0xe8b: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_e8e:
	/* 0xe8e: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_e91:
	/* 0xe91: cmp    eax,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 41ULL);
x86_l_e94:
	/* 0xe94: jb     f0c <filter_64ty_range+0x1cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f0c;
	}
x86_l_e96:
	/* 0xe96: cmp    QWORD PTR [rdi+0x30],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e9a:
	/* 0xe9a: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_e9e:
	/* 0xe9e: cmp    rsi,QWORD PTR [rdi+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_ea2:
	/* 0xea2: setbe  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_BE);
x86_l_ea6:
	/* 0xea6: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_ea9:
	/* 0xea9: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_eac:
	/* 0xeac: cmp    eax,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 57ULL);
x86_l_eaf:
	/* 0xeaf: jb     f0c <filter_64ty_range+0x1cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f0c;
	}
x86_l_eb1:
	/* 0xeb1: cmp    QWORD PTR [rdi+0x40],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_eb5:
	/* 0xeb5: setbe  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_BE);
x86_l_eb8:
	/* 0xeb8: cmp    rsi,QWORD PTR [rdi+0x48] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 72ULL);
x86_l_ebc:
	/* 0xebc: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_ec0:
	/* 0xec0: and    sil,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_ec3:
	/* 0xec3: or     dl,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_8, X86_ALU_OR);
x86_l_ec6:
	/* 0xec6: jmp    f0c <filter_64ty_range+0x1cc> */
	goto x86_l_f0c;
x86_l_ec8:
	/* 0xec8: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ecb:
	/* 0xecb: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_ece:
	/* 0xece: jb     f0a <filter_64ty_range+0x1ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f0a;
	}
x86_l_ed0:
	/* 0xed0: cmp    QWORD PTR [rdi+0x20],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ed4:
	/* 0xed4: ja     edc <filter_64ty_range+0x19c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_edc;
	}
x86_l_ed6:
	/* 0xed6: cmp    rsi,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_eda:
	/* 0xeda: jbe    e5c <filter_64ty_range+0x11c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_e5c;
	}
x86_l_edc:
	/* 0xedc: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_edf:
	/* 0xedf: jb     f0a <filter_64ty_range+0x1ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f0a;
	}
x86_l_ee1:
	/* 0xee1: cmp    QWORD PTR [rdi+0x30],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ee5:
	/* 0xee5: ja     ef1 <filter_64ty_range+0x1b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_ef1;
	}
x86_l_ee7:
	/* 0xee7: cmp    rsi,QWORD PTR [rdi+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_eeb:
	/* 0xeeb: jbe    e5c <filter_64ty_range+0x11c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_e5c;
	}
x86_l_ef1:
	/* 0xef1: cmp    edx,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 57ULL);
x86_l_ef4:
	/* 0xef4: jb     f0a <filter_64ty_range+0x1ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f0a;
	}
x86_l_ef6:
	/* 0xef6: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ef8:
	/* 0xef8: cmp    QWORD PTR [rdi+0x40],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_efc:
	/* 0xefc: ja     f0c <filter_64ty_range+0x1cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_f0c;
	}
x86_l_efe:
	/* 0xefe: cmp    rsi,QWORD PTR [rdi+0x48] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 72ULL);
x86_l_f02:
	/* 0xf02: jbe    e5c <filter_64ty_range+0x11c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_e5c;
	}
x86_l_f08:
	/* 0xf08: jmp    f0c <filter_64ty_range+0x1cc> */
	goto x86_l_f0c;
x86_l_f0a:
	/* 0xf0a: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f0c:
	/* 0xf0c: cmp    ecx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 32ULL);
x86_l_f0f:
	/* 0xf0f: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_f12:
	/* 0xf12: xor    dl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_f15:
	/* 0xf15: and    dl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_f17:
	/* 0xf17: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_f1a:
	/* 0xf1a: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_f1b:
	/* 0xf1b: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_f1d:
	/* 0xf1d: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_f1e:
	/* 0xf1e: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_f22:
	/* 0xf22: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_f25:
	/* 0xf25: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_f28:
	/* 0xf28: movzx  eax,BYTE PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_f2c:
	/* 0xf2c: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_f30:
	/* 0xf30: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f35:
	/* 0xf35: mov    rdi,QWORD PTR [rip+0x9a0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_f3c:
	/* 0xf3c: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_f41:
	/* 0xf41: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f43:
	/* 0xf43: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f46:
	/* 0xf46: je     f74 <filter_64ty_map+0x59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f74;
	}
x86_l_f48:
	/* 0xf48: mov    rcx,QWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f4b:
	/* 0xf4b: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f50:
	/* 0xf50: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_f55:
	/* 0xf55: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f5a:
	/* 0xf5a: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_f5d:
	/* 0xf5d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_f5f:
	/* 0xf5f: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_f62:
	/* 0xf62: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_f65:
	/* 0xf65: je     f7e <filter_64ty_map+0x63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f7e;
	}
x86_l_f67:
	/* 0xf67: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_f6a:
	/* 0xf6a: jne    f86 <filter_64ty_map+0x6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_f86;
	}
x86_l_f6c:
	/* 0xf6c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f6f:
	/* 0xf6f: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_f72:
	/* 0xf72: jmp    f88 <filter_64ty_map+0x6d> */
	goto x86_l_f88;
x86_l_f74:
	/* 0xf74: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f76:
	/* 0xf76: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_f7a:
	/* 0xf7a: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_f7b:
	/* 0xf7b: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_f7d:
	/* 0xf7d: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_f7e:
	/* 0xf7e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f81:
	/* 0xf81: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_f84:
	/* 0xf84: jmp    f88 <filter_64ty_map+0x6d> */
	goto x86_l_f88;
x86_l_f86:
	/* 0xf86: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f88:
	/* 0xf88: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_f8b:
	/* 0xf8b: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_f8f:
	/* 0xf8f: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_f90:
	/* 0xf90: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_f92:
	/* 0xf92: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_f93:
	/* 0xf93: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_f95:
	/* 0xf95: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_f97:
	/* 0xf97: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_f98:
	/* 0xf98: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_f9c:
	/* 0xf9c: mov    ebx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDX, X86_WIDTH_32);
x86_l_f9e:
	/* 0xf9e: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_fa1:
	/* 0xfa1: mov    DWORD PTR [rsp+0xc],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_fa5:
	/* 0xfa5: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_fad:
	/* 0xfad: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fb2:
	/* 0xfb2: mov    rdi,QWORD PTR [rip+0x22b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_fb9:
	/* 0xfb9: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_fbe:
	/* 0xfbe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fc0:
	/* 0xfc0: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_fc3:
	/* 0xfc3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fc5:
	/* 0xfc5: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_fc7:
	/* 0xfc7: je     10d1 <filter_char_buf_postfix+0x13e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4305ULL;
	}
x86_l_fcd:
	/* 0xfcd: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_fd0:
	/* 0xfd0: je     10d1 <filter_char_buf_postfix+0x13e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4305ULL;
	}
x86_l_fd6:
	/* 0xfd6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fdb:
	/* 0xfdb: mov    rdi,QWORD PTR [rip+0x22b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_fe2:
	/* 0xfe2: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fe7:
	/* 0xfe7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fe9:
	/* 0xfe9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fec:
	/* 0xfec: je     10cf <filter_char_buf_postfix+0x13c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4303ULL;
	}
x86_l_ff2:
	/* 0xff2: cmp    ebx,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 127ULL);
x86_l_ff5:
	/* 0xff5: mov    ecx,0x7f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 127ULL);
x86_l_ffa:
	/* 0xffa: cmovb  ecx,ebx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RBX, X86_WIDTH_32, X86_CC_B);
x86_l_ffd:
	/* 0xffd: shl    ecx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_1000:
	/* 0x1000: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1002:
	/* 0x1002: mov    ecx,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_32);
x86_l_1004:
	/* 0x1004: lea    edx,[rbx-0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_1007:
	/* 0x1007: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_100a:
	/* 0x100a: add    rsi,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 7ULL);
x86_l_100e:
	/* 0x100e: lea    edi,[rbx-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1011:
	/* 0x1011: lea    r8d,[rbx-0x2] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_1015:
	/* 0x1015: dec    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_1017:
	/* 0x1017: mov    r9,0xfffffffffffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 18446744073709551613ULL);
x86_l_101e:
	/* 0x101e: lea    r10d,[rbx+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_1022:
	/* 0x1022: add    r10d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_1026:
	/* 0x1026: and    r10d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_102d:
	/* 0x102d: movzx  r10d,BYTE PTR [r14+r10*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R10, 0, X86_WIDTH_8), 0ULL);
x86_l_1032:
	/* 0x1032: mov    BYTE PTR [rsi-0x3],r10b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_R10, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1036:
	/* 0x1036: lea    r10,[rcx+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_103a:
	/* 0x103a: cmp    r10,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_103e:
	/* 0x103e: je     10b5 <filter_char_buf_postfix+0x122> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4277ULL;
	}
x86_l_1040:
	/* 0x1040: lea    r11d,[r8+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_1044:
	/* 0x1044: add    r11d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_1048:
	/* 0x1048: and    r11d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_104f:
	/* 0x104f: movzx  r11d,BYTE PTR [r14+r11*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R11, 0, X86_WIDTH_8), 0ULL);
x86_l_1054:
	/* 0x1054: mov    BYTE PTR [rsi-0x2],r11b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_R11, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_1058:
	/* 0x1058: cmp    r10,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_105c:
	/* 0x105c: je     10b5 <filter_char_buf_postfix+0x122> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4277ULL;
	}
x86_l_105e:
	/* 0x105e: lea    r10d,[rdi+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_1062:
	/* 0x1062: add    r10d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_1066:
	/* 0x1066: and    r10d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_106d:
	/* 0x106d: movzx  r10d,BYTE PTR [r14+r10*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R10, 0, X86_WIDTH_8), 0ULL);
x86_l_1072:
	/* 0x1072: mov    BYTE PTR [rsi-0x1],r10b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_R10, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1076:
	/* 0x1076: mov    r10,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_RCX, X86_WIDTH_64);
x86_l_1079:
	/* 0x1079: add    r10,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R9, X86_WIDTH_64, X86_ALU_ADD);
x86_l_107c:
	/* 0x107c: je     10b5 <filter_char_buf_postfix+0x122> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4277ULL;
	}
x86_l_107e:
	/* 0x107e: cmp    r9,0xffffffffffffff81 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_64, 18446744073709551489ULL);
x86_l_1082:
	/* 0x1082: je     10b5 <filter_char_buf_postfix+0x122> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4277ULL;
	}
x86_l_1084:
	/* 0x1084: lea    r10d,[rdx+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_1088:
	/* 0x1088: add    r10d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_108c:
	/* 0x108c: and    r10d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1093:
	/* 0x1093: movzx  r10d,BYTE PTR [r14+r10*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R10, 0, X86_WIDTH_8), 0ULL);
x86_l_1098:
	/* 0x1098: mov    BYTE PTR [rsi],r10b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_R10, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_109b:
	/* 0x109b: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
	return 4255ULL;
}

static __noinline __u64 tetragon_bpf_multi_usdt_v61_generic_usdt_filter_arg_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 4255ULL: goto x86_l_109f;
	case 4259ULL: goto x86_l_10a3;
	case 4263ULL: goto x86_l_10a7;
	case 4267ULL: goto x86_l_10ab;
	case 4271ULL: goto x86_l_10af;
	case 4277ULL: goto x86_l_10b5;
	case 4282ULL: goto x86_l_10ba;
	case 4285ULL: goto x86_l_10bd;
	case 4288ULL: goto x86_l_10c0;
	case 4290ULL: goto x86_l_10c2;
	case 4293ULL: goto x86_l_10c5;
	case 4295ULL: goto x86_l_10c7;
	case 4298ULL: goto x86_l_10ca;
	case 4301ULL: goto x86_l_10cd;
	case 4303ULL: goto x86_l_10cf;
	case 4305ULL: goto x86_l_10d1;
	case 4309ULL: goto x86_l_10d5;
	case 4310ULL: goto x86_l_10d6;
	case 4312ULL: goto x86_l_10d8;
	case 4314ULL: goto x86_l_10da;
	case 4315ULL: goto x86_l_10db;
	case 4316ULL: goto x86_l_10dc;
	case 4318ULL: goto x86_l_10de;
	case 4319ULL: goto x86_l_10df;
	case 4323ULL: goto x86_l_10e3;
	case 4325ULL: goto x86_l_10e5;
	case 4328ULL: goto x86_l_10e8;
	case 4332ULL: goto x86_l_10ec;
	case 4340ULL: goto x86_l_10f4;
	case 4345ULL: goto x86_l_10f9;
	case 4352ULL: goto x86_l_1100;
	case 4357ULL: goto x86_l_1105;
	case 4359ULL: goto x86_l_1107;
	case 4362ULL: goto x86_l_110a;
	case 4364ULL: goto x86_l_110c;
	case 4366ULL: goto x86_l_110e;
	case 4368ULL: goto x86_l_1110;
	case 4371ULL: goto x86_l_1113;
	case 4373ULL: goto x86_l_1115;
	case 4378ULL: goto x86_l_111a;
	case 4385ULL: goto x86_l_1121;
	case 4390ULL: goto x86_l_1126;
	case 4392ULL: goto x86_l_1128;
	case 4395ULL: goto x86_l_112b;
	case 4397ULL: goto x86_l_112d;
	case 4403ULL: goto x86_l_1133;
	case 4408ULL: goto x86_l_1138;
	case 4411ULL: goto x86_l_113b;
	case 4418ULL: goto x86_l_1142;
	case 4420ULL: goto x86_l_1144;
	case 4423ULL: goto x86_l_1147;
	case 4427ULL: goto x86_l_114b;
	case 4432ULL: goto x86_l_1150;
	case 4435ULL: goto x86_l_1153;
	case 4438ULL: goto x86_l_1156;
	case 4440ULL: goto x86_l_1158;
	case 4445ULL: goto x86_l_115d;
	case 4448ULL: goto x86_l_1160;
	case 4451ULL: goto x86_l_1163;
	case 4453ULL: goto x86_l_1165;
	case 4456ULL: goto x86_l_1168;
	case 4458ULL: goto x86_l_116a;
	case 4461ULL: goto x86_l_116d;
	case 4464ULL: goto x86_l_1170;
	case 4466ULL: goto x86_l_1172;
	case 4468ULL: goto x86_l_1174;
	case 4472ULL: goto x86_l_1178;
	case 4473ULL: goto x86_l_1179;
	case 4475ULL: goto x86_l_117b;
	case 4476ULL: goto x86_l_117c;
	case 4477ULL: goto x86_l_117d;
	case 4478ULL: goto x86_l_117e;
	case 4480ULL: goto x86_l_1180;
	case 4482ULL: goto x86_l_1182;
	case 4484ULL: goto x86_l_1184;
	case 4486ULL: goto x86_l_1186;
	case 4487ULL: goto x86_l_1187;
	case 4491ULL: goto x86_l_118b;
	case 4499ULL: goto x86_l_1193;
	case 4505ULL: goto x86_l_1199;
	case 4511ULL: goto x86_l_119f;
	case 4513ULL: goto x86_l_11a1;
	case 4516ULL: goto x86_l_11a4;
	case 4521ULL: goto x86_l_11a9;
	case 4523ULL: goto x86_l_11ab;
	case 4527ULL: goto x86_l_11af;
	case 4533ULL: goto x86_l_11b5;
	case 4536ULL: goto x86_l_11b8;
	case 4539ULL: goto x86_l_11bb;
	case 4542ULL: goto x86_l_11be;
	case 4544ULL: goto x86_l_11c0;
	case 4547ULL: goto x86_l_11c3;
	case 4549ULL: goto x86_l_11c5;
	case 4551ULL: goto x86_l_11c7;
	case 4554ULL: goto x86_l_11ca;
	case 4556ULL: goto x86_l_11cc;
	case 4558ULL: goto x86_l_11ce;
	case 4561ULL: goto x86_l_11d1;
	case 4563ULL: goto x86_l_11d3;
	case 4565ULL: goto x86_l_11d5;
	case 4567ULL: goto x86_l_11d7;
	case 4570ULL: goto x86_l_11da;
	case 4574ULL: goto x86_l_11de;
	case 4578ULL: goto x86_l_11e2;
	case 4580ULL: goto x86_l_11e4;
	case 4583ULL: goto x86_l_11e7;
	case 4586ULL: goto x86_l_11ea;
	case 4593ULL: goto x86_l_11f1;
	case 4597ULL: goto x86_l_11f5;
	case 4600ULL: goto x86_l_11f8;
	case 4605ULL: goto x86_l_11fd;
	case 4611ULL: goto x86_l_1203;
	case 4616ULL: goto x86_l_1208;
	case 4618ULL: goto x86_l_120a;
	case 4624ULL: goto x86_l_1210;
	case 4629ULL: goto x86_l_1215;
	case 4631ULL: goto x86_l_1217;
	case 4637ULL: goto x86_l_121d;
	case 4642ULL: goto x86_l_1222;
	case 4644ULL: goto x86_l_1224;
	case 4647ULL: goto x86_l_1227;
	case 4652ULL: goto x86_l_122c;
	case 4656ULL: goto x86_l_1230;
	case 4660ULL: goto x86_l_1234;
	case 4667ULL: goto x86_l_123b;
	case 4674ULL: goto x86_l_1242;
	case 4680ULL: goto x86_l_1248;
	case 4683ULL: goto x86_l_124b;
	case 4685ULL: goto x86_l_124d;
	case 4687ULL: goto x86_l_124f;
	case 4689ULL: goto x86_l_1251;
	case 4692ULL: goto x86_l_1254;
	case 4694ULL: goto x86_l_1256;
	case 4700ULL: goto x86_l_125c;
	case 4702ULL: goto x86_l_125e;
	case 4705ULL: goto x86_l_1261;
	case 4707ULL: goto x86_l_1263;
	case 4710ULL: goto x86_l_1266;
	case 4712ULL: goto x86_l_1268;
	case 4718ULL: goto x86_l_126e;
	case 4720ULL: goto x86_l_1270;
	case 4726ULL: goto x86_l_1276;
	case 4728ULL: goto x86_l_1278;
	case 4734ULL: goto x86_l_127e;
	case 4736ULL: goto x86_l_1280;
	case 4742ULL: goto x86_l_1286;
	case 4745ULL: goto x86_l_1289;
	case 4748ULL: goto x86_l_128c;
	case 4752ULL: goto x86_l_1290;
	case 4755ULL: goto x86_l_1293;
	case 4761ULL: goto x86_l_1299;
	case 4766ULL: goto x86_l_129e;
	case 4771ULL: goto x86_l_12a3;
	case 4778ULL: goto x86_l_12aa;
	case 4783ULL: goto x86_l_12af;
	case 4786ULL: goto x86_l_12b2;
	case 4788ULL: goto x86_l_12b4;
	case 4791ULL: goto x86_l_12b7;
	case 4796ULL: goto x86_l_12bc;
	case 4803ULL: goto x86_l_12c3;
	case 4806ULL: goto x86_l_12c6;
	case 4808ULL: goto x86_l_12c8;
	case 4811ULL: goto x86_l_12cb;
	case 4813ULL: goto x86_l_12cd;
	case 4817ULL: goto x86_l_12d1;
	case 4820ULL: goto x86_l_12d4;
	case 4826ULL: goto x86_l_12da;
	case 4829ULL: goto x86_l_12dd;
	case 4835ULL: goto x86_l_12e3;
	case 4839ULL: goto x86_l_12e7;
	case 4841ULL: goto x86_l_12e9;
	case 4845ULL: goto x86_l_12ed;
	case 4848ULL: goto x86_l_12f0;
	case 4852ULL: goto x86_l_12f4;
	case 4857ULL: goto x86_l_12f9;
	case 4859ULL: goto x86_l_12fb;
	case 4864ULL: goto x86_l_1300;
	case 4866ULL: goto x86_l_1302;
	case 4869ULL: goto x86_l_1305;
	case 4871ULL: goto x86_l_1307;
	case 4873ULL: goto x86_l_1309;
	case 4877ULL: goto x86_l_130d;
	case 4881ULL: goto x86_l_1311;
	case 4884ULL: goto x86_l_1314;
	case 4891ULL: goto x86_l_131b;
	case 4896ULL: goto x86_l_1320;
	case 4898ULL: goto x86_l_1322;
	case 4902ULL: goto x86_l_1326;
	case 4905ULL: goto x86_l_1329;
	case 4909ULL: goto x86_l_132d;
	case 4914ULL: goto x86_l_1332;
	case 4916ULL: goto x86_l_1334;
	case 4921ULL: goto x86_l_1339;
	case 4923ULL: goto x86_l_133b;
	case 4926ULL: goto x86_l_133e;
	case 4928ULL: goto x86_l_1340;
	case 4930ULL: goto x86_l_1342;
	case 4934ULL: goto x86_l_1346;
	case 4938ULL: goto x86_l_134a;
	case 4942ULL: goto x86_l_134e;
	case 4949ULL: goto x86_l_1355;
	case 4954ULL: goto x86_l_135a;
	case 4957ULL: goto x86_l_135d;
	case 4960ULL: goto x86_l_1360;
	case 4962ULL: goto x86_l_1362;
	case 4966ULL: goto x86_l_1366;
	case 4970ULL: goto x86_l_136a;
	case 4972ULL: goto x86_l_136c;
	case 4976ULL: goto x86_l_1370;
	case 4978ULL: goto x86_l_1372;
	case 4982ULL: goto x86_l_1376;
	case 4988ULL: goto x86_l_137c;
	case 4992ULL: goto x86_l_1380;
	case 4998ULL: goto x86_l_1386;
	case 5002ULL: goto x86_l_138a;
	case 5008ULL: goto x86_l_1390;
	case 5013ULL: goto x86_l_1395;
	case 5020ULL: goto x86_l_139c;
	case 5025ULL: goto x86_l_13a1;
	case 5029ULL: goto x86_l_13a5;
	case 5031ULL: goto x86_l_13a7;
	case 5035ULL: goto x86_l_13ab;
	case 5041ULL: goto x86_l_13b1;
	case 5045ULL: goto x86_l_13b5;
	case 5047ULL: goto x86_l_13b7;
	case 5051ULL: goto x86_l_13bb;
	case 5057ULL: goto x86_l_13c1;
	case 5062ULL: goto x86_l_13c6;
	case 5069ULL: goto x86_l_13cd;
	case 5074ULL: goto x86_l_13d2;
	case 5078ULL: goto x86_l_13d6;
	case 5084ULL: goto x86_l_13dc;
	case 5088ULL: goto x86_l_13e0;
	case 5090ULL: goto x86_l_13e2;
	case 5094ULL: goto x86_l_13e6;
	case 5100ULL: goto x86_l_13ec;
	case 5105ULL: goto x86_l_13f1;
	case 5112ULL: goto x86_l_13f8;
	case 5117ULL: goto x86_l_13fd;
	case 5120ULL: goto x86_l_1400;
	case 5122ULL: goto x86_l_1402;
	case 5126ULL: goto x86_l_1406;
	case 5132ULL: goto x86_l_140c;
	case 5137ULL: goto x86_l_1411;
	case 5144ULL: goto x86_l_1418;
	case 5146ULL: goto x86_l_141a;
	case 5151ULL: goto x86_l_141f;
	case 5158ULL: goto x86_l_1426;
	case 5160ULL: goto x86_l_1428;
	case 5165ULL: goto x86_l_142d;
	case 5172ULL: goto x86_l_1434;
	case 5174ULL: goto x86_l_1436;
	case 5179ULL: goto x86_l_143b;
	case 5186ULL: goto x86_l_1442;
	case 5188ULL: goto x86_l_1444;
	case 5193ULL: goto x86_l_1449;
	case 5200ULL: goto x86_l_1450;
	case 5202ULL: goto x86_l_1452;
	case 5207ULL: goto x86_l_1457;
	case 5214ULL: goto x86_l_145e;
	case 5216ULL: goto x86_l_1460;
	case 5221ULL: goto x86_l_1465;
	case 5228ULL: goto x86_l_146c;
	case 5230ULL: goto x86_l_146e;
	case 5235ULL: goto x86_l_1473;
	case 5242ULL: goto x86_l_147a;
	case 5247ULL: goto x86_l_147f;
	case 5249ULL: goto x86_l_1481;
	case 5252ULL: goto x86_l_1484;
	case 5254ULL: goto x86_l_1486;
	case 5259ULL: goto x86_l_148b;
	case 5262ULL: goto x86_l_148e;
	case 5266ULL: goto x86_l_1492;
	case 5268ULL: goto x86_l_1494;
	case 5271ULL: goto x86_l_1497;
	case 5273ULL: goto x86_l_1499;
	case 5276ULL: goto x86_l_149c;
	case 5279ULL: goto x86_l_149f;
	case 5281ULL: goto x86_l_14a1;
	case 5283ULL: goto x86_l_14a3;
	case 5287ULL: goto x86_l_14a7;
	case 5288ULL: goto x86_l_14a8;
	case 5290ULL: goto x86_l_14aa;
	case 5292ULL: goto x86_l_14ac;
	case 5294ULL: goto x86_l_14ae;
	case 5296ULL: goto x86_l_14b0;
	case 5297ULL: goto x86_l_14b1;
	case 5298ULL: goto x86_l_14b2;
	case 5299ULL: goto x86_l_14b3;
	case 5301ULL: goto x86_l_14b5;
	case 5303ULL: goto x86_l_14b7;
	case 5305ULL: goto x86_l_14b9;
	case 5307ULL: goto x86_l_14bb;
	case 5308ULL: goto x86_l_14bc;
	case 5309ULL: goto x86_l_14bd;
	case 5312ULL: goto x86_l_14c0;
	case 5315ULL: goto x86_l_14c3;
	case 5317ULL: goto x86_l_14c5;
	case 5319ULL: goto x86_l_14c7;
	case 5325ULL: goto x86_l_14cd;
	case 5327ULL: goto x86_l_14cf;
	case 5333ULL: goto x86_l_14d5;
	case 5338ULL: goto x86_l_14da;
	case 5340ULL: goto x86_l_14dc;
	case 5343ULL: goto x86_l_14df;
	case 5348ULL: goto x86_l_14e4;
	case 5352ULL: goto x86_l_14e8;
	case 5357ULL: goto x86_l_14ed;
	case 5364ULL: goto x86_l_14f4;
	case 5367ULL: goto x86_l_14f7;
	case 5369ULL: goto x86_l_14f9;
	case 5372ULL: goto x86_l_14fc;
	case 5378ULL: goto x86_l_1502;
	case 5381ULL: goto x86_l_1505;
	case 5383ULL: goto x86_l_1507;
	case 5385ULL: goto x86_l_1509;
	case 5388ULL: goto x86_l_150c;
	case 5391ULL: goto x86_l_150f;
	case 5394ULL: goto x86_l_1512;
	case 5396ULL: goto x86_l_1514;
	case 5398ULL: goto x86_l_1516;
	case 5402ULL: goto x86_l_151a;
	case 5405ULL: goto x86_l_151d;
	case 5407ULL: goto x86_l_151f;
	case 5411ULL: goto x86_l_1523;
	case 5413ULL: goto x86_l_1525;
	case 5415ULL: goto x86_l_1527;
	case 5420ULL: goto x86_l_152c;
	case 5424ULL: goto x86_l_1530;
	case 5427ULL: goto x86_l_1533;
	case 5431ULL: goto x86_l_1537;
	case 5435ULL: goto x86_l_153b;
	case 5439ULL: goto x86_l_153f;
	case 5443ULL: goto x86_l_1543;
	case 5446ULL: goto x86_l_1546;
	case 5450ULL: goto x86_l_154a;
	case 5454ULL: goto x86_l_154e;
	case 5458ULL: goto x86_l_1552;
	case 5462ULL: goto x86_l_1556;
	case 5464ULL: goto x86_l_1558;
	case 5467ULL: goto x86_l_155b;
	case 5470ULL: goto x86_l_155e;
	case 5472ULL: goto x86_l_1560;
	case 5474ULL: goto x86_l_1562;
	case 5476ULL: goto x86_l_1564;
	case 5482ULL: goto x86_l_156a;
	case 5487ULL: goto x86_l_156f;
	case 5491ULL: goto x86_l_1573;
	case 5497ULL: goto x86_l_1579;
	case 5501ULL: goto x86_l_157d;
	case 5504ULL: goto x86_l_1580;
	case 5508ULL: goto x86_l_1584;
	case 5514ULL: goto x86_l_158a;
	case 5519ULL: goto x86_l_158f;
	case 5521ULL: goto x86_l_1591;
	case 5527ULL: goto x86_l_1597;
	case 5532ULL: goto x86_l_159c;
	case 5534ULL: goto x86_l_159e;
	case 5537ULL: goto x86_l_15a1;
	case 5542ULL: goto x86_l_15a6;
	case 5546ULL: goto x86_l_15aa;
	case 5551ULL: goto x86_l_15af;
	case 5558ULL: goto x86_l_15b6;
	case 5561ULL: goto x86_l_15b9;
	case 5563ULL: goto x86_l_15bb;
	case 5566ULL: goto x86_l_15be;
	case 5572ULL: goto x86_l_15c4;
	case 5575ULL: goto x86_l_15c7;
	case 5577ULL: goto x86_l_15c9;
	case 5579ULL: goto x86_l_15cb;
	case 5582ULL: goto x86_l_15ce;
	case 5585ULL: goto x86_l_15d1;
	case 5588ULL: goto x86_l_15d4;
	case 5590ULL: goto x86_l_15d6;
	case 5592ULL: goto x86_l_15d8;
	case 5596ULL: goto x86_l_15dc;
	case 5599ULL: goto x86_l_15df;
	case 5601ULL: goto x86_l_15e1;
	case 5605ULL: goto x86_l_15e5;
	case 5608ULL: goto x86_l_15e8;
	case 5610ULL: goto x86_l_15ea;
	case 5614ULL: goto x86_l_15ee;
	case 5616ULL: goto x86_l_15f0;
	case 5620ULL: goto x86_l_15f4;
	default: return 0xffffffffffffffffULL;
	}
x86_l_109f:
	/* 0x109f: lea    r10,[rcx+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_10a3:
	/* 0x10a3: add    r10,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_10a7:
	/* 0x10a7: add    r9,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_10ab:
	/* 0x10ab: cmp    r10,0xfffffffffffffffd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_64, 18446744073709551613ULL);
x86_l_10af:
	/* 0x10af: jne    101e <filter_char_buf_postfix+0x8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4126ULL;
	}
x86_l_10b5:
	/* 0x10b5: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_10ba:
	/* 0x10ba: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_10bd:
	/* 0x10bd: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_10c0:
	/* 0x10c0: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_10c2:
	/* 0x10c2: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_10c5:
	/* 0x10c5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10c7:
	/* 0x10c7: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_10ca:
	/* 0x10ca: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_10cd:
	/* 0x10cd: jmp    10d1 <filter_char_buf_postfix+0x13e> */
	goto x86_l_10d1;
x86_l_10cf:
	/* 0x10cf: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10d1:
	/* 0x10d1: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_10d5:
	/* 0x10d5: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_10d6:
	/* 0x10d6: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_10d8:
	/* 0x10d8: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_10da:
	/* 0x10da: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_10db:
	/* 0x10db: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_10dc:
	/* 0x10dc: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_10de:
	/* 0x10de: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_10df:
	/* 0x10df: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_10e3:
	/* 0x10e3: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_10e5:
	/* 0x10e5: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_10e8:
	/* 0x10e8: mov    DWORD PTR [rsp+0xc],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_10ec:
	/* 0x10ec: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_10f4:
	/* 0x10f4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10f9:
	/* 0x10f9: mov    rdi,QWORD PTR [rip+0x2200] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_1100:
	/* 0x1100: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1105:
	/* 0x1105: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1107:
	/* 0x1107: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_110a:
	/* 0x110a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_110c:
	/* 0x110c: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_110e:
	/* 0x110e: je     1174 <filter_char_buf_prefix+0x99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1174;
	}
x86_l_1110:
	/* 0x1110: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_1113:
	/* 0x1113: je     1174 <filter_char_buf_prefix+0x99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1174;
	}
x86_l_1115:
	/* 0x1115: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_111a:
	/* 0x111a: mov    rdi,QWORD PTR [rip+0x2200] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_1121:
	/* 0x1121: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1126:
	/* 0x1126: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1128:
	/* 0x1128: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_112b:
	/* 0x112b: je     1172 <filter_char_buf_prefix+0x97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1172;
	}
x86_l_112d:
	/* 0x112d: cmp    ebp,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 255ULL);
x86_l_1133:
	/* 0x1133: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_1138:
	/* 0x1138: cmovb  esi,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RBP, X86_WIDTH_32, X86_CC_B);
x86_l_113b:
	/* 0x113b: lea    ecx,[rsi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_1142:
	/* 0x1142: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1144:
	/* 0x1144: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1147:
	/* 0x1147: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_114b:
	/* 0x114b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1150:
	/* 0x1150: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1153:
	/* 0x1153: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1156:
	/* 0x1156: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1158:
	/* 0x1158: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_115d:
	/* 0x115d: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_1160:
	/* 0x1160: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_1163:
	/* 0x1163: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1165:
	/* 0x1165: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1168:
	/* 0x1168: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_116a:
	/* 0x116a: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_116d:
	/* 0x116d: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_1170:
	/* 0x1170: jmp    1174 <filter_char_buf_prefix+0x99> */
	goto x86_l_1174;
x86_l_1172:
	/* 0x1172: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1174:
	/* 0x1174: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1178:
	/* 0x1178: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1179:
	/* 0x1179: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_117b:
	/* 0x117b: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_117c:
	/* 0x117c: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_117d:
	/* 0x117d: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_117e:
	/* 0x117e: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_1180:
	/* 0x1180: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_1182:
	/* 0x1182: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_1184:
	/* 0x1184: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_1186:
	/* 0x1186: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_1187:
	/* 0x1187: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_118b:
	/* 0x118b: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1193:
	/* 0x1193: cmp    edx,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4096ULL);
x86_l_1199:
	/* 0x1199: ja     14a1 <filter_char_buf_equal+0x324> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_14a1;
	}
x86_l_119f:
	/* 0x119f: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_11a1:
	/* 0x11a1: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_11a4:
	/* 0x11a4: cmp    eax,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_11a9:
	/* 0x11a9: ja     11fd <filter_char_buf_equal+0x80> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_11fd;
	}
x86_l_11ab:
	/* 0x11ab: movzx  eax,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_11af:
	/* 0x11af: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_11b5:
	/* 0x11b5: shr    ecx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_11b8:
	/* 0x11b8: and    ecx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_11bb:
	/* 0x11bb: lea    ecx,[rcx+rcx*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 1), 0ULL);
x86_l_11be:
	/* 0x11be: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_11c0:
	/* 0x11c0: test   bp,bp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_16);
x86_l_11c3:
	/* 0x11c3: je     11ce <filter_char_buf_equal+0x51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11ce;
	}
x86_l_11c5:
	/* 0x11c5: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_11c7:
	/* 0x11c7: mov    r14d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_32);
x86_l_11ca:
	/* 0x11ca: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_11cc:
	/* 0x11cc: je     11e7 <filter_char_buf_equal+0x6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11e7;
	}
x86_l_11ce:
	/* 0x11ce: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_11d1:
	/* 0x11d1: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_11d3:
	/* 0x11d3: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_11d5:
	/* 0x11d5: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_11d7:
	/* 0x11d7: add    eax,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_11da:
	/* 0x11da: movzx  r14d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_11de:
	/* 0x11de: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_11e2:
	/* 0x11e2: ja     123b <filter_char_buf_equal+0xbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_123b;
	}
x86_l_11e4:
	/* 0x11e4: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_11e7:
	/* 0x11e7: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_11ea:
	/* 0x11ea: imul   r13d,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_R13, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_11f1:
	/* 0x11f1: shr    r13d,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_11f5:
	/* 0x11f5: dec    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_11f8:
	/* 0x11f8: jmp    1286 <filter_char_buf_equal+0x109> */
	goto x86_l_1286;
x86_l_11fd:
	/* 0x11fd: mov    r14d,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 256ULL);
x86_l_1203:
	/* 0x1203: cmp    eax,0x101 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 257ULL);
x86_l_1208:
	/* 0x1208: jb     123b <filter_char_buf_equal+0xbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_123b;
	}
x86_l_120a:
	/* 0x120a: mov    r14d,0x200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 512ULL);
x86_l_1210:
	/* 0x1210: cmp    eax,0x201 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 513ULL);
x86_l_1215:
	/* 0x1215: jb     123b <filter_char_buf_equal+0xbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_123b;
	}
x86_l_1217:
	/* 0x1217: mov    r14d,0x400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1024ULL);
x86_l_121d:
	/* 0x121d: cmp    eax,0x401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1025ULL);
x86_l_1222:
	/* 0x1222: jb     123b <filter_char_buf_equal+0xbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_123b;
	}
x86_l_1224:
	/* 0x1224: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1227:
	/* 0x1227: cmp    eax,0x801 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2049ULL);
x86_l_122c:
	/* 0x122c: setae  r14b */
	X86_SIM_L_EXEC_SETCC(X86_R14, X86_CC_AE);
x86_l_1230:
	/* 0x1230: shl    r14d,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHL, 11ULL);
x86_l_1234:
	/* 0x1234: add    r14d,0x800 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 2048ULL);
x86_l_123b:
	/* 0x123b: lea    eax,[r14-0x100] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551360ULL);
x86_l_1242:
	/* 0x1242: rorx   eax,eax,0x8 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 8ULL);
x86_l_1248:
	/* 0x1248: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_124b:
	/* 0x124b: jg     125e <filter_char_buf_equal+0xe1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_125e;
	}
x86_l_124d:
	/* 0x124d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_124f:
	/* 0x124f: je     1278 <filter_char_buf_equal+0xfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1278;
	}
x86_l_1251:
	/* 0x1251: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1254:
	/* 0x1254: jne    1270 <filter_char_buf_equal+0xf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1270;
	}
x86_l_1256:
	/* 0x1256: mov    r13d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 7ULL);
x86_l_125c:
	/* 0x125c: jmp    1286 <filter_char_buf_equal+0x109> */
	goto x86_l_1286;
x86_l_125e:
	/* 0x125e: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1261:
	/* 0x1261: je     1280 <filter_char_buf_equal+0x103> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1280;
	}
x86_l_1263:
	/* 0x1263: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_1266:
	/* 0x1266: jne    1270 <filter_char_buf_equal+0xf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1270;
	}
x86_l_1268:
	/* 0x1268: mov    r13d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 9ULL);
x86_l_126e:
	/* 0x126e: jmp    1286 <filter_char_buf_equal+0x109> */
	goto x86_l_1286;
x86_l_1270:
	/* 0x1270: mov    r13d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 10ULL);
x86_l_1276:
	/* 0x1276: jmp    1286 <filter_char_buf_equal+0x109> */
	goto x86_l_1286;
x86_l_1278:
	/* 0x1278: mov    r13d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 6ULL);
x86_l_127e:
	/* 0x127e: jmp    1286 <filter_char_buf_equal+0x109> */
	goto x86_l_1286;
x86_l_1280:
	/* 0x1280: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_1286:
	/* 0x1286: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_1289:
	/* 0x1289: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_128c:
	/* 0x128c: mov    ebx,DWORD PTR [rdi+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_1290:
	/* 0x1290: cmp    ebx,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4294967295ULL);
x86_l_1293:
	/* 0x1293: je     14a1 <filter_char_buf_equal+0x324> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14a1;
	}
x86_l_1299:
	/* 0x1299: mov    QWORD PTR [rsp+0x10],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_129e:
	/* 0x129e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12a3:
	/* 0x12a3: mov    rdi,QWORD PTR [rip+0x1ec0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_12aa:
	/* 0x12aa: lea    r15,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12af:
	/* 0x12af: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_12b2:
	/* 0x12b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12b4:
	/* 0x12b4: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_12b7:
	/* 0x12b7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12bc:
	/* 0x12bc: mov    rdi,QWORD PTR [rip+0x1ec0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_12c3:
	/* 0x12c3: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_12c6:
	/* 0x12c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12c8:
	/* 0x12c8: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_12cb:
	/* 0x12cb: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12cd:
	/* 0x12cd: mov    QWORD PTR [rsp],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12d1:
	/* 0x12d1: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_12d4:
	/* 0x12d4: je     14a3 <filter_char_buf_equal+0x326> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14a3;
	}
x86_l_12da:
	/* 0x12da: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_12dd:
	/* 0x12dd: je     14a3 <filter_char_buf_equal+0x326> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14a3;
	}
x86_l_12e3:
	/* 0x12e3: cmp    r13d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 5ULL);
x86_l_12e7:
	/* 0x12e7: jg     1322 <filter_char_buf_equal+0x1a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1322;
	}
x86_l_12e9:
	/* 0x12e9: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12ed:
	/* 0x12ed: mov    BYTE PTR [rax],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12f0:
	/* 0x12f0: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_12f4:
	/* 0x12f4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12f9:
	/* 0x12f9: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_12fb:
	/* 0x12fb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1300:
	/* 0x1300: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1302:
	/* 0x1302: sub    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1305:
	/* 0x1305: jbe    1362 <filter_char_buf_equal+0x1e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1362;
	}
x86_l_1307:
	/* 0x1307: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_1309:
	/* 0x1309: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_130d:
	/* 0x130d: lea    rdi,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1311:
	/* 0x1311: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1314:
	/* 0x1314: and    r14d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_131b:
	/* 0x131b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1320:
	/* 0x1320: jmp    135a <filter_char_buf_equal+0x1dd> */
	goto x86_l_135a;
x86_l_1322:
	/* 0x1322: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1326:
	/* 0x1326: mov    WORD PTR [rax],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1329:
	/* 0x1329: lea    rdi,[rax+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_132d:
	/* 0x132d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1332:
	/* 0x1332: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_1334:
	/* 0x1334: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1339:
	/* 0x1339: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_133b:
	/* 0x133b: sub    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_133e:
	/* 0x133e: jbe    1362 <filter_char_buf_equal+0x1e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1362;
	}
x86_l_1340:
	/* 0x1340: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_1342:
	/* 0x1342: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1346:
	/* 0x1346: lea    rdi,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_134a:
	/* 0x134a: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_134e:
	/* 0x134e: and    r14d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1355:
	/* 0x1355: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_135a:
	/* 0x135a: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_135d:
	/* 0x135d: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1360:
	/* 0x1360: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1362:
	/* 0x1362: mov    DWORD PTR [rsp+0xc],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1366:
	/* 0x1366: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_136a:
	/* 0x136a: jle    13a1 <filter_char_buf_equal+0x224> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_13a1;
	}
x86_l_136c:
	/* 0x136c: cmp    r13d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 7ULL);
x86_l_1370:
	/* 0x1370: jg     13d2 <filter_char_buf_equal+0x255> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_13d2;
	}
x86_l_1372:
	/* 0x1372: cmp    r13d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 5ULL);
x86_l_1376:
	/* 0x1376: je     1460 <filter_char_buf_equal+0x2e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1460;
	}
x86_l_137c:
	/* 0x137c: cmp    r13d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 6ULL);
x86_l_1380:
	/* 0x1380: je     1436 <filter_char_buf_equal+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1436;
	}
x86_l_1386:
	/* 0x1386: cmp    r13d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 7ULL);
x86_l_138a:
	/* 0x138a: jne    14a1 <filter_char_buf_equal+0x324> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_14a1;
	}
x86_l_1390:
	/* 0x1390: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1395:
	/* 0x1395: mov    rdi,QWORD PTR [rip+0x1ec0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_7)));
x86_l_139c:
	/* 0x139c: jmp    147a <filter_char_buf_equal+0x2fd> */
	goto x86_l_147a;
x86_l_13a1:
	/* 0x13a1: cmp    r13d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1ULL);
x86_l_13a5:
	/* 0x13a5: jle    13fd <filter_char_buf_equal+0x280> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_13fd;
	}
x86_l_13a7:
	/* 0x13a7: cmp    r13d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 2ULL);
x86_l_13ab:
	/* 0x13ab: je     1452 <filter_char_buf_equal+0x2d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1452;
	}
x86_l_13b1:
	/* 0x13b1: cmp    r13d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 3ULL);
x86_l_13b5:
	/* 0x13b5: je     1428 <filter_char_buf_equal+0x2ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1428;
	}
x86_l_13b7:
	/* 0x13b7: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_13bb:
	/* 0x13bb: jne    14a1 <filter_char_buf_equal+0x324> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_14a1;
	}
x86_l_13c1:
	/* 0x13c1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13c6:
	/* 0x13c6: mov    rdi,QWORD PTR [rip+0x1ec0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_13cd:
	/* 0x13cd: jmp    147a <filter_char_buf_equal+0x2fd> */
	goto x86_l_147a;
x86_l_13d2:
	/* 0x13d2: cmp    r13d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 8ULL);
x86_l_13d6:
	/* 0x13d6: je     146e <filter_char_buf_equal+0x2f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_146e;
	}
x86_l_13dc:
	/* 0x13dc: cmp    r13d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 9ULL);
x86_l_13e0:
	/* 0x13e0: je     1444 <filter_char_buf_equal+0x2c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1444;
	}
x86_l_13e2:
	/* 0x13e2: cmp    r13d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 10ULL);
x86_l_13e6:
	/* 0x13e6: jne    14a1 <filter_char_buf_equal+0x324> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_14a1;
	}
x86_l_13ec:
	/* 0x13ec: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13f1:
	/* 0x13f1: mov    rdi,QWORD PTR [rip+0x1ec0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_10)));
x86_l_13f8:
	/* 0x13f8: jmp    147a <filter_char_buf_equal+0x2fd> */
	goto x86_l_147a;
x86_l_13fd:
	/* 0x13fd: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_1400:
	/* 0x1400: je     141a <filter_char_buf_equal+0x29d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_141a;
	}
x86_l_1402:
	/* 0x1402: cmp    r13d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1ULL);
x86_l_1406:
	/* 0x1406: jne    14a1 <filter_char_buf_equal+0x324> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_14a1;
	}
x86_l_140c:
	/* 0x140c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1411:
	/* 0x1411: mov    rdi,QWORD PTR [rip+0x1ebd] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_1418:
	/* 0x1418: jmp    147a <filter_char_buf_equal+0x2fd> */
	goto x86_l_147a;
x86_l_141a:
	/* 0x141a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_141f:
	/* 0x141f: mov    rdi,QWORD PTR [rip+0x1ebd] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_1426:
	/* 0x1426: jmp    147a <filter_char_buf_equal+0x2fd> */
	goto x86_l_147a;
x86_l_1428:
	/* 0x1428: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_142d:
	/* 0x142d: mov    rdi,QWORD PTR [rip+0x1ebd] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_1434:
	/* 0x1434: jmp    147a <filter_char_buf_equal+0x2fd> */
	goto x86_l_147a;
x86_l_1436:
	/* 0x1436: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_143b:
	/* 0x143b: mov    rdi,QWORD PTR [rip+0x1ebd] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_6)));
x86_l_1442:
	/* 0x1442: jmp    147a <filter_char_buf_equal+0x2fd> */
	goto x86_l_147a;
x86_l_1444:
	/* 0x1444: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1449:
	/* 0x1449: mov    rdi,QWORD PTR [rip+0x1ebd] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_9)));
x86_l_1450:
	/* 0x1450: jmp    147a <filter_char_buf_equal+0x2fd> */
	goto x86_l_147a;
x86_l_1452:
	/* 0x1452: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1457:
	/* 0x1457: mov    rdi,QWORD PTR [rip+0x1ebd] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_145e:
	/* 0x145e: jmp    147a <filter_char_buf_equal+0x2fd> */
	goto x86_l_147a;
x86_l_1460:
	/* 0x1460: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1465:
	/* 0x1465: mov    rdi,QWORD PTR [rip+0x1ebd] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_146c:
	/* 0x146c: jmp    147a <filter_char_buf_equal+0x2fd> */
	goto x86_l_147a;
x86_l_146e:
	/* 0x146e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1473:
	/* 0x1473: mov    rdi,QWORD PTR [rip+0x1ebd] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_8)));
x86_l_147a:
	/* 0x147a: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_147f:
	/* 0x147f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1481:
	/* 0x1481: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1484:
	/* 0x1484: je     14a1 <filter_char_buf_equal+0x324> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14a1;
	}
x86_l_1486:
	/* 0x1486: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_148b:
	/* 0x148b: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_148e:
	/* 0x148e: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1492:
	/* 0x1492: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1494:
	/* 0x1494: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1497:
	/* 0x1497: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1499:
	/* 0x1499: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_149c:
	/* 0x149c: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_149f:
	/* 0x149f: jmp    14a3 <filter_char_buf_equal+0x326> */
	goto x86_l_14a3;
x86_l_14a1:
	/* 0x14a1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14a3:
	/* 0x14a3: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_14a7:
	/* 0x14a7: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_14a8:
	/* 0x14a8: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_14aa:
	/* 0x14aa: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_14ac:
	/* 0x14ac: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_14ae:
	/* 0x14ae: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_14b0:
	/* 0x14b0: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_14b1:
	/* 0x14b1: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_14b2:
	/* 0x14b2: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_14b3:
	/* 0x14b3: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_14b5:
	/* 0x14b5: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_14b7:
	/* 0x14b7: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_14b9:
	/* 0x14b9: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_14bb:
	/* 0x14bb: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_14bc:
	/* 0x14bc: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_14bd:
	/* 0x14bd: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_14c0:
	/* 0x14c0: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_14c3:
	/* 0x14c3: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_14c5:
	/* 0x14c5: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_14c7:
	/* 0x14c7: je     158f <filter_char_substring+0xdd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_158f;
	}
x86_l_14cd:
	/* 0x14cd: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_14cf:
	/* 0x14cf: je     162c <filter_char_substring+0x17a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5676ULL;
	}
x86_l_14d5:
	/* 0x14d5: lea    r13,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_14da:
	/* 0x14da: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14dc:
	/* 0x14dc: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14df:
	/* 0x14df: mov    eax,DWORD PTR [r14+rbx*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_14e4:
	/* 0x14e4: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_14e8:
	/* 0x14e8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14ed:
	/* 0x14ed: mov    rdi,QWORD PTR [rip+0x24a3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_14f4:
	/* 0x14f4: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_14f7:
	/* 0x14f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14f9:
	/* 0x14f9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14fc:
	/* 0x14fc: je     16b0 <filter_char_substring+0x1fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5808ULL;
	}
x86_l_1502:
	/* 0x1502: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1505:
	/* 0x1505: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1507:
	/* 0x1507: jmp    1514 <filter_char_substring+0x62> */
	goto x86_l_1514;
x86_l_1509:
	/* 0x1509: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_150c:
	/* 0x150c: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_150f:
	/* 0x150f: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_1512:
	/* 0x1512: je     156a <filter_char_substring+0xb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_156a;
	}
x86_l_1514:
	/* 0x1514: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1516:
	/* 0x1516: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_151a:
	/* 0x151a: cmp    rdi,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_151d:
	/* 0x151d: jae    1509 <filter_char_substring+0x57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1509;
	}
x86_l_151f:
	/* 0x151f: movsx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_1523:
	/* 0x1523: test   edi,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_32);
x86_l_1525:
	/* 0x1525: je     1562 <filter_char_substring+0xb0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1562;
	}
x86_l_1527:
	/* 0x1527: movsx  r9d,BYTE PTR [rdx+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R9, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_152c:
	/* 0x152c: lea    r10d,[r9-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_1530:
	/* 0x1530: mov    r8d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R9, X86_WIDTH_32);
x86_l_1533:
	/* 0x1533: or     r8d,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_1537:
	/* 0x1537: cmp    r10d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 26ULL);
x86_l_153b:
	/* 0x153b: cmovae r8d,r9d */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_R9, X86_WIDTH_32, X86_CC_AE);
x86_l_153f:
	/* 0x153f: lea    r10d,[rdi-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_1543:
	/* 0x1543: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_1546:
	/* 0x1546: or     r9d,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_154a:
	/* 0x154a: cmp    r10d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 26ULL);
x86_l_154e:
	/* 0x154e: cmovae r9d,edi */
	X86_SIM_L_EXEC_CMOV(X86_R9, X86_RDI, X86_WIDTH_32, X86_CC_AE);
x86_l_1552:
	/* 0x1552: cmp    rsi,0x62 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 98ULL);
x86_l_1556:
	/* 0x1556: ja     1509 <filter_char_substring+0x57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1509;
	}
x86_l_1558:
	/* 0x1558: inc    rsi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_155b:
	/* 0x155b: cmp    r8d,r9d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_R9, X86_WIDTH_32);
x86_l_155e:
	/* 0x155e: je     1516 <filter_char_substring+0x64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1516;
	}
x86_l_1560:
	/* 0x1560: jmp    1509 <filter_char_substring+0x57> */
	goto x86_l_1509;
x86_l_1562:
	/* 0x1562: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1564:
	/* 0x1564: jns    16c1 <filter_char_substring+0x20f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 5825ULL;
	}
x86_l_156a:
	/* 0x156a: lea    eax,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_156f:
	/* 0x156f: cmp    eax,DWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_1573:
	/* 0x1573: jae    16b0 <filter_char_substring+0x1fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 5808ULL;
	}
x86_l_1579:
	/* 0x1579: add    r12d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_157d:
	/* 0x157d: inc    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1580:
	/* 0x1580: cmp    rbx,0x64 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 100ULL);
x86_l_1584:
	/* 0x1584: jne    14df <filter_char_substring+0x2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_14df;
	}
x86_l_158a:
	/* 0x158a: jmp    16b0 <filter_char_substring+0x1fe> */
	return 5808ULL;
x86_l_158f:
	/* 0x158f: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_1591:
	/* 0x1591: je     166f <filter_char_substring+0x1bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5743ULL;
	}
x86_l_1597:
	/* 0x1597: lea    r13,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_159c:
	/* 0x159c: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_159e:
	/* 0x159e: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15a1:
	/* 0x15a1: mov    eax,DWORD PTR [r14+rbx*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_15a6:
	/* 0x15a6: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_15aa:
	/* 0x15aa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15af:
	/* 0x15af: mov    rdi,QWORD PTR [rip+0x24b1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_15b6:
	/* 0x15b6: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_15b9:
	/* 0x15b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15bb:
	/* 0x15bb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15be:
	/* 0x15be: je     16b0 <filter_char_substring+0x1fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5808ULL;
	}
x86_l_15c4:
	/* 0x15c4: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_15c7:
	/* 0x15c7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15c9:
	/* 0x15c9: jmp    15d6 <filter_char_substring+0x124> */
	goto x86_l_15d6;
x86_l_15cb:
	/* 0x15cb: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_15ce:
	/* 0x15ce: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_15d1:
	/* 0x15d1: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_15d4:
	/* 0x15d4: je     1607 <filter_char_substring+0x155> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5639ULL;
	}
x86_l_15d6:
	/* 0x15d6: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15d8:
	/* 0x15d8: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_15dc:
	/* 0x15dc: cmp    rdi,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_15df:
	/* 0x15df: jae    15cb <filter_char_substring+0x119> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_15cb;
	}
x86_l_15e1:
	/* 0x15e1: movzx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_15e5:
	/* 0x15e5: test   dil,dil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_8);
x86_l_15e8:
	/* 0x15e8: je     15ff <filter_char_substring+0x14d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5631ULL;
	}
x86_l_15ea:
	/* 0x15ea: cmp    rsi,0x62 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 98ULL);
x86_l_15ee:
	/* 0x15ee: ja     15cb <filter_char_substring+0x119> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_15cb;
	}
x86_l_15f0:
	/* 0x15f0: lea    r8,[rsi+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_15f4:
	/* 0x15f4: cmp    BYTE PTR [rdx+rsi*1],dil */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDX, X86_RDI, X86_WIDTH_8, X86_MEM_AUX(X86_RSI, 0), 0ULL);
	return 5624ULL;
}

static __noinline __u64 tetragon_bpf_multi_usdt_v61_generic_usdt_filter_arg_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5624ULL: goto x86_l_15f8;
	case 5627ULL: goto x86_l_15fb;
	case 5629ULL: goto x86_l_15fd;
	case 5631ULL: goto x86_l_15ff;
	case 5633ULL: goto x86_l_1601;
	case 5639ULL: goto x86_l_1607;
	case 5644ULL: goto x86_l_160c;
	case 5648ULL: goto x86_l_1610;
	case 5654ULL: goto x86_l_1616;
	case 5658ULL: goto x86_l_161a;
	case 5661ULL: goto x86_l_161d;
	case 5665ULL: goto x86_l_1621;
	case 5671ULL: goto x86_l_1627;
	case 5676ULL: goto x86_l_162c;
	case 5681ULL: goto x86_l_1631;
	case 5688ULL: goto x86_l_1638;
	case 5693ULL: goto x86_l_163d;
	case 5697ULL: goto x86_l_1641;
	case 5701ULL: goto x86_l_1645;
	case 5706ULL: goto x86_l_164a;
	case 5709ULL: goto x86_l_164d;
	case 5712ULL: goto x86_l_1650;
	case 5714ULL: goto x86_l_1652;
	case 5717ULL: goto x86_l_1655;
	case 5719ULL: goto x86_l_1657;
	case 5723ULL: goto x86_l_165b;
	case 5726ULL: goto x86_l_165e;
	case 5730ULL: goto x86_l_1662;
	case 5732ULL: goto x86_l_1664;
	case 5739ULL: goto x86_l_166b;
	case 5741ULL: goto x86_l_166d;
	case 5743ULL: goto x86_l_166f;
	case 5748ULL: goto x86_l_1674;
	case 5755ULL: goto x86_l_167b;
	case 5760ULL: goto x86_l_1680;
	case 5764ULL: goto x86_l_1684;
	case 5768ULL: goto x86_l_1688;
	case 5773ULL: goto x86_l_168d;
	case 5776ULL: goto x86_l_1690;
	case 5779ULL: goto x86_l_1693;
	case 5781ULL: goto x86_l_1695;
	case 5784ULL: goto x86_l_1698;
	case 5786ULL: goto x86_l_169a;
	case 5790ULL: goto x86_l_169e;
	case 5793ULL: goto x86_l_16a1;
	case 5797ULL: goto x86_l_16a5;
	case 5799ULL: goto x86_l_16a7;
	case 5806ULL: goto x86_l_16ae;
	case 5808ULL: goto x86_l_16b0;
	case 5810ULL: goto x86_l_16b2;
	case 5814ULL: goto x86_l_16b6;
	case 5815ULL: goto x86_l_16b7;
	case 5817ULL: goto x86_l_16b9;
	case 5819ULL: goto x86_l_16bb;
	case 5821ULL: goto x86_l_16bd;
	case 5823ULL: goto x86_l_16bf;
	case 5824ULL: goto x86_l_16c0;
	case 5825ULL: goto x86_l_16c1;
	case 5830ULL: goto x86_l_16c6;
	case 5832ULL: goto x86_l_16c8;
	case 5835ULL: goto x86_l_16cb;
	case 5840ULL: goto x86_l_16d0;
	case 5844ULL: goto x86_l_16d4;
	case 5846ULL: goto x86_l_16d6;
	case 5856ULL: goto x86_l_16e0;
	case 5860ULL: goto x86_l_16e4;
	case 5862ULL: goto x86_l_16e6;
	case 5863ULL: goto x86_l_16e7;
	case 5868ULL: goto x86_l_16ec;
	case 5872ULL: goto x86_l_16f0;
	case 5874ULL: goto x86_l_16f2;
	case 5877ULL: goto x86_l_16f5;
	case 5880ULL: goto x86_l_16f8;
	case 5886ULL: goto x86_l_16fe;
	case 5888ULL: goto x86_l_1700;
	case 5891ULL: goto x86_l_1703;
	case 5894ULL: goto x86_l_1706;
	case 5895ULL: goto x86_l_1707;
	case 5899ULL: goto x86_l_170b;
	case 5901ULL: goto x86_l_170d;
	case 5904ULL: goto x86_l_1710;
	case 5907ULL: goto x86_l_1713;
	case 5909ULL: goto x86_l_1715;
	case 5912ULL: goto x86_l_1718;
	case 5915ULL: goto x86_l_171b;
	case 5921ULL: goto x86_l_1721;
	case 5924ULL: goto x86_l_1724;
	case 5926ULL: goto x86_l_1726;
	case 5929ULL: goto x86_l_1729;
	case 5935ULL: goto x86_l_172f;
	case 5938ULL: goto x86_l_1732;
	case 5940ULL: goto x86_l_1734;
	case 5943ULL: goto x86_l_1737;
	case 5949ULL: goto x86_l_173d;
	case 5952ULL: goto x86_l_1740;
	case 5954ULL: goto x86_l_1742;
	case 5959ULL: goto x86_l_1747;
	case 5962ULL: goto x86_l_174a;
	case 5964ULL: goto x86_l_174c;
	case 5967ULL: goto x86_l_174f;
	case 5973ULL: goto x86_l_1755;
	case 5976ULL: goto x86_l_1758;
	case 5979ULL: goto x86_l_175b;
	case 5985ULL: goto x86_l_1761;
	case 5990ULL: goto x86_l_1766;
	case 5993ULL: goto x86_l_1769;
	case 5999ULL: goto x86_l_176f;
	case 6002ULL: goto x86_l_1772;
	case 6005ULL: goto x86_l_1775;
	case 6011ULL: goto x86_l_177b;
	case 6014ULL: goto x86_l_177e;
	case 6017ULL: goto x86_l_1781;
	case 6023ULL: goto x86_l_1787;
	case 6026ULL: goto x86_l_178a;
	case 6032ULL: goto x86_l_1790;
	case 6035ULL: goto x86_l_1793;
	case 6041ULL: goto x86_l_1799;
	case 6044ULL: goto x86_l_179c;
	case 6050ULL: goto x86_l_17a2;
	case 6053ULL: goto x86_l_17a5;
	case 6059ULL: goto x86_l_17ab;
	case 6062ULL: goto x86_l_17ae;
	case 6068ULL: goto x86_l_17b4;
	case 6073ULL: goto x86_l_17b9;
	case 6076ULL: goto x86_l_17bc;
	case 6079ULL: goto x86_l_17bf;
	case 6085ULL: goto x86_l_17c5;
	case 6090ULL: goto x86_l_17ca;
	case 6093ULL: goto x86_l_17cd;
	case 6099ULL: goto x86_l_17d3;
	case 6102ULL: goto x86_l_17d6;
	case 6105ULL: goto x86_l_17d9;
	case 6111ULL: goto x86_l_17df;
	case 6114ULL: goto x86_l_17e2;
	case 6117ULL: goto x86_l_17e5;
	case 6123ULL: goto x86_l_17eb;
	case 6126ULL: goto x86_l_17ee;
	case 6132ULL: goto x86_l_17f4;
	case 6135ULL: goto x86_l_17f7;
	case 6141ULL: goto x86_l_17fd;
	case 6144ULL: goto x86_l_1800;
	case 6150ULL: goto x86_l_1806;
	case 6153ULL: goto x86_l_1809;
	case 6159ULL: goto x86_l_180f;
	case 6162ULL: goto x86_l_1812;
	case 6168ULL: goto x86_l_1818;
	case 6173ULL: goto x86_l_181d;
	case 6176ULL: goto x86_l_1820;
	case 6179ULL: goto x86_l_1823;
	case 6181ULL: goto x86_l_1825;
	case 6184ULL: goto x86_l_1828;
	case 6190ULL: goto x86_l_182e;
	case 6193ULL: goto x86_l_1831;
	case 6195ULL: goto x86_l_1833;
	case 6198ULL: goto x86_l_1836;
	case 6204ULL: goto x86_l_183c;
	case 6207ULL: goto x86_l_183f;
	case 6209ULL: goto x86_l_1841;
	case 6212ULL: goto x86_l_1844;
	case 6218ULL: goto x86_l_184a;
	case 6221ULL: goto x86_l_184d;
	case 6227ULL: goto x86_l_1853;
	case 6229ULL: goto x86_l_1855;
	case 6239ULL: goto x86_l_185f;
	case 6243ULL: goto x86_l_1863;
	case 6249ULL: goto x86_l_1869;
	case 6251ULL: goto x86_l_186b;
	case 6254ULL: goto x86_l_186e;
	case 6257ULL: goto x86_l_1871;
	case 6263ULL: goto x86_l_1877;
	case 6266ULL: goto x86_l_187a;
	case 6269ULL: goto x86_l_187d;
	case 6271ULL: goto x86_l_187f;
	case 6274ULL: goto x86_l_1882;
	case 6280ULL: goto x86_l_1888;
	case 6283ULL: goto x86_l_188b;
	case 6285ULL: goto x86_l_188d;
	case 6288ULL: goto x86_l_1890;
	case 6294ULL: goto x86_l_1896;
	case 6297ULL: goto x86_l_1899;
	case 6299ULL: goto x86_l_189b;
	case 6302ULL: goto x86_l_189e;
	case 6308ULL: goto x86_l_18a4;
	case 6310ULL: goto x86_l_18a6;
	case 6313ULL: goto x86_l_18a9;
	case 6316ULL: goto x86_l_18ac;
	case 6322ULL: goto x86_l_18b2;
	case 6325ULL: goto x86_l_18b5;
	case 6328ULL: goto x86_l_18b8;
	case 6330ULL: goto x86_l_18ba;
	case 6333ULL: goto x86_l_18bd;
	case 6339ULL: goto x86_l_18c3;
	case 6342ULL: goto x86_l_18c6;
	case 6344ULL: goto x86_l_18c8;
	case 6347ULL: goto x86_l_18cb;
	case 6353ULL: goto x86_l_18d1;
	case 6356ULL: goto x86_l_18d4;
	case 6358ULL: goto x86_l_18d6;
	case 6361ULL: goto x86_l_18d9;
	case 6367ULL: goto x86_l_18df;
	case 6369ULL: goto x86_l_18e1;
	case 6370ULL: goto x86_l_18e2;
	case 6373ULL: goto x86_l_18e5;
	case 6376ULL: goto x86_l_18e8;
	case 6379ULL: goto x86_l_18eb;
	case 6385ULL: goto x86_l_18f1;
	case 6390ULL: goto x86_l_18f6;
	case 6393ULL: goto x86_l_18f9;
	case 6399ULL: goto x86_l_18ff;
	case 6402ULL: goto x86_l_1902;
	case 6405ULL: goto x86_l_1905;
	case 6407ULL: goto x86_l_1907;
	case 6412ULL: goto x86_l_190c;
	case 6415ULL: goto x86_l_190f;
	case 6417ULL: goto x86_l_1911;
	case 6420ULL: goto x86_l_1914;
	case 6426ULL: goto x86_l_191a;
	case 6429ULL: goto x86_l_191d;
	case 6432ULL: goto x86_l_1920;
	case 6438ULL: goto x86_l_1926;
	case 6441ULL: goto x86_l_1929;
	case 6443ULL: goto x86_l_192b;
	case 6446ULL: goto x86_l_192e;
	case 6452ULL: goto x86_l_1934;
	case 6455ULL: goto x86_l_1937;
	case 6461ULL: goto x86_l_193d;
	case 6464ULL: goto x86_l_1940;
	case 6466ULL: goto x86_l_1942;
	case 6469ULL: goto x86_l_1945;
	case 6475ULL: goto x86_l_194b;
	case 6478ULL: goto x86_l_194e;
	case 6484ULL: goto x86_l_1954;
	case 6486ULL: goto x86_l_1956;
	case 6489ULL: goto x86_l_1959;
	case 6495ULL: goto x86_l_195f;
	case 6498ULL: goto x86_l_1962;
	case 6504ULL: goto x86_l_1968;
	case 6509ULL: goto x86_l_196d;
	case 6512ULL: goto x86_l_1970;
	case 6515ULL: goto x86_l_1973;
	case 6519ULL: goto x86_l_1977;
	case 6522ULL: goto x86_l_197a;
	case 6525ULL: goto x86_l_197d;
	case 6528ULL: goto x86_l_1980;
	case 6531ULL: goto x86_l_1983;
	case 6537ULL: goto x86_l_1989;
	case 6540ULL: goto x86_l_198c;
	case 6544ULL: goto x86_l_1990;
	case 6547ULL: goto x86_l_1993;
	case 6551ULL: goto x86_l_1997;
	case 6554ULL: goto x86_l_199a;
	case 6557ULL: goto x86_l_199d;
	case 6560ULL: goto x86_l_19a0;
	case 6566ULL: goto x86_l_19a6;
	case 6569ULL: goto x86_l_19a9;
	case 6573ULL: goto x86_l_19ad;
	case 6576ULL: goto x86_l_19b0;
	case 6580ULL: goto x86_l_19b4;
	case 6583ULL: goto x86_l_19b7;
	case 6586ULL: goto x86_l_19ba;
	case 6589ULL: goto x86_l_19bd;
	case 6595ULL: goto x86_l_19c3;
	case 6598ULL: goto x86_l_19c6;
	case 6601ULL: goto x86_l_19c9;
	case 6604ULL: goto x86_l_19cc;
	case 6608ULL: goto x86_l_19d0;
	case 6610ULL: goto x86_l_19d2;
	case 6613ULL: goto x86_l_19d5;
	case 6616ULL: goto x86_l_19d8;
	case 6618ULL: goto x86_l_19da;
	case 6623ULL: goto x86_l_19df;
	case 6626ULL: goto x86_l_19e2;
	case 6628ULL: goto x86_l_19e4;
	case 6631ULL: goto x86_l_19e7;
	case 6633ULL: goto x86_l_19e9;
	case 6634ULL: goto x86_l_19ea;
	case 6637ULL: goto x86_l_19ed;
	case 6640ULL: goto x86_l_19f0;
	case 6644ULL: goto x86_l_19f4;
	case 6647ULL: goto x86_l_19f7;
	case 6650ULL: goto x86_l_19fa;
	case 6653ULL: goto x86_l_19fd;
	case 6656ULL: goto x86_l_1a00;
	case 6662ULL: goto x86_l_1a06;
	case 6665ULL: goto x86_l_1a09;
	case 6669ULL: goto x86_l_1a0d;
	case 6672ULL: goto x86_l_1a10;
	case 6676ULL: goto x86_l_1a14;
	case 6679ULL: goto x86_l_1a17;
	case 6682ULL: goto x86_l_1a1a;
	case 6685ULL: goto x86_l_1a1d;
	case 6687ULL: goto x86_l_1a1f;
	case 6690ULL: goto x86_l_1a22;
	case 6694ULL: goto x86_l_1a26;
	case 6697ULL: goto x86_l_1a29;
	case 6701ULL: goto x86_l_1a2d;
	case 6704ULL: goto x86_l_1a30;
	case 6707ULL: goto x86_l_1a33;
	case 6710ULL: goto x86_l_1a36;
	case 6712ULL: goto x86_l_1a38;
	case 6715ULL: goto x86_l_1a3b;
	case 6718ULL: goto x86_l_1a3e;
	case 6721ULL: goto x86_l_1a41;
	case 6725ULL: goto x86_l_1a45;
	case 6728ULL: goto x86_l_1a48;
	case 6731ULL: goto x86_l_1a4b;
	case 6733ULL: goto x86_l_1a4d;
	case 6736ULL: goto x86_l_1a50;
	case 6739ULL: goto x86_l_1a53;
	case 6741ULL: goto x86_l_1a55;
	case 6744ULL: goto x86_l_1a58;
	case 6746ULL: goto x86_l_1a5a;
	case 6749ULL: goto x86_l_1a5d;
	case 6751ULL: goto x86_l_1a5f;
	case 6754ULL: goto x86_l_1a62;
	case 6756ULL: goto x86_l_1a64;
	case 6759ULL: goto x86_l_1a67;
	case 6761ULL: goto x86_l_1a69;
	case 6764ULL: goto x86_l_1a6c;
	case 6770ULL: goto x86_l_1a72;
	case 6773ULL: goto x86_l_1a75;
	case 6775ULL: goto x86_l_1a77;
	case 6777ULL: goto x86_l_1a79;
	case 6780ULL: goto x86_l_1a7c;
	case 6782ULL: goto x86_l_1a7e;
	case 6785ULL: goto x86_l_1a81;
	case 6791ULL: goto x86_l_1a87;
	case 6793ULL: goto x86_l_1a89;
	case 6795ULL: goto x86_l_1a8b;
	case 6798ULL: goto x86_l_1a8e;
	case 6801ULL: goto x86_l_1a91;
	case 6804ULL: goto x86_l_1a94;
	case 6806ULL: goto x86_l_1a96;
	case 6809ULL: goto x86_l_1a99;
	case 6810ULL: goto x86_l_1a9a;
	case 6812ULL: goto x86_l_1a9c;
	case 6813ULL: goto x86_l_1a9d;
	case 6817ULL: goto x86_l_1aa1;
	case 6820ULL: goto x86_l_1aa4;
	case 6823ULL: goto x86_l_1aa7;
	case 6827ULL: goto x86_l_1aab;
	case 6831ULL: goto x86_l_1aaf;
	case 6836ULL: goto x86_l_1ab4;
	case 6843ULL: goto x86_l_1abb;
	case 6848ULL: goto x86_l_1ac0;
	case 6850ULL: goto x86_l_1ac2;
	case 6853ULL: goto x86_l_1ac5;
	case 6855ULL: goto x86_l_1ac7;
	case 6859ULL: goto x86_l_1acb;
	case 6864ULL: goto x86_l_1ad0;
	case 6869ULL: goto x86_l_1ad5;
	case 6874ULL: goto x86_l_1ada;
	case 6877ULL: goto x86_l_1add;
	case 6879ULL: goto x86_l_1adf;
	case 6882ULL: goto x86_l_1ae2;
	case 6884ULL: goto x86_l_1ae4;
	case 6887ULL: goto x86_l_1ae7;
	case 6889ULL: goto x86_l_1ae9;
	case 6894ULL: goto x86_l_1aee;
	case 6897ULL: goto x86_l_1af1;
	case 6899ULL: goto x86_l_1af3;
	case 6902ULL: goto x86_l_1af6;
	case 6905ULL: goto x86_l_1af9;
	case 6907ULL: goto x86_l_1afb;
	case 6909ULL: goto x86_l_1afd;
	case 6913ULL: goto x86_l_1b01;
	case 6914ULL: goto x86_l_1b02;
	case 6916ULL: goto x86_l_1b04;
	case 6917ULL: goto x86_l_1b05;
	case 6922ULL: goto x86_l_1b0a;
	case 6925ULL: goto x86_l_1b0d;
	case 6927ULL: goto x86_l_1b0f;
	case 6930ULL: goto x86_l_1b12;
	case 6933ULL: goto x86_l_1b15;
	case 6936ULL: goto x86_l_1b18;
	case 6940ULL: goto x86_l_1b1c;
	case 6941ULL: goto x86_l_1b1d;
	case 6943ULL: goto x86_l_1b1f;
	case 6944ULL: goto x86_l_1b20;
	case 6947ULL: goto x86_l_1b23;
	case 6952ULL: goto x86_l_1b28;
	case 6956ULL: goto x86_l_1b2c;
	case 6958ULL: goto x86_l_1b2e;
	case 6968ULL: goto x86_l_1b38;
	default: return 0xffffffffffffffffULL;
	}
x86_l_15f8:
	/* 0x15f8: mov    rsi,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R8, X86_WIDTH_64);
x86_l_15fb:
	/* 0x15fb: je     15d8 <filter_char_substring+0x126> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5592ULL;
	}
x86_l_15fd:
	/* 0x15fd: jmp    15cb <filter_char_substring+0x119> */
	return 5579ULL;
x86_l_15ff:
	/* 0x15ff: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1601:
	/* 0x1601: jns    16c1 <filter_char_substring+0x20f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_16c1;
	}
x86_l_1607:
	/* 0x1607: lea    eax,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_160c:
	/* 0x160c: cmp    eax,DWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_1610:
	/* 0x1610: jae    16b0 <filter_char_substring+0x1fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_16b0;
	}
x86_l_1616:
	/* 0x1616: add    r12d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_161a:
	/* 0x161a: inc    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_161d:
	/* 0x161d: cmp    rbx,0x64 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 100ULL);
x86_l_1621:
	/* 0x1621: jne    15a1 <filter_char_substring+0xef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5537ULL;
	}
x86_l_1627:
	/* 0x1627: jmp    16b0 <filter_char_substring+0x1fe> */
	goto x86_l_16b0;
x86_l_162c:
	/* 0x162c: mov    ebx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 16ULL);
x86_l_1631:
	/* 0x1631: mov    r15,QWORD PTR [rip+0x24c3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_1638:
	/* 0x1638: lea    r12,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_163d:
	/* 0x163d: mov    eax,DWORD PTR [r14+rbx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_1641:
	/* 0x1641: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1645:
	/* 0x1645: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_164a:
	/* 0x164a: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_164d:
	/* 0x164d: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1650:
	/* 0x1650: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1652:
	/* 0x1652: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1655:
	/* 0x1655: je     16b0 <filter_char_substring+0x1fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16b0;
	}
x86_l_1657:
	/* 0x1657: add    rbx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_165b:
	/* 0x165b: lea    eax,[rbx-0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551608ULL);
x86_l_165e:
	/* 0x165e: cmp    eax,DWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_1662:
	/* 0x1662: jae    16b0 <filter_char_substring+0x1fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_16b0;
	}
x86_l_1664:
	/* 0x1664: cmp    rbx,0x1a0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 416ULL);
x86_l_166b:
	/* 0x166b: jne    163d <filter_char_substring+0x18b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_163d;
	}
x86_l_166d:
	/* 0x166d: jmp    16b0 <filter_char_substring+0x1fe> */
	goto x86_l_16b0;
x86_l_166f:
	/* 0x166f: mov    ebx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 16ULL);
x86_l_1674:
	/* 0x1674: mov    r15,QWORD PTR [rip+0x24c5] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_167b:
	/* 0x167b: lea    r12,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1680:
	/* 0x1680: mov    eax,DWORD PTR [r14+rbx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_1684:
	/* 0x1684: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1688:
	/* 0x1688: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_168d:
	/* 0x168d: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1690:
	/* 0x1690: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1693:
	/* 0x1693: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1695:
	/* 0x1695: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1698:
	/* 0x1698: je     16b0 <filter_char_substring+0x1fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16b0;
	}
x86_l_169a:
	/* 0x169a: add    rbx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_169e:
	/* 0x169e: lea    eax,[rbx-0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551608ULL);
x86_l_16a1:
	/* 0x16a1: cmp    eax,DWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_16a5:
	/* 0x16a5: jae    16b0 <filter_char_substring+0x1fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_16b0;
	}
x86_l_16a7:
	/* 0x16a7: cmp    rbx,0x1a0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 416ULL);
x86_l_16ae:
	/* 0x16ae: jne    1680 <filter_char_substring+0x1ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1680;
	}
x86_l_16b0:
	/* 0x16b0: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16b2:
	/* 0x16b2: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_16b6:
	/* 0x16b6: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_16b7:
	/* 0x16b7: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_16b9:
	/* 0x16b9: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_16bb:
	/* 0x16bb: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_16bd:
	/* 0x16bd: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_16bf:
	/* 0x16bf: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_16c0:
	/* 0x16c0: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_16c1:
	/* 0x16c1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16c6:
	/* 0x16c6: jmp    16b2 <filter_char_substring+0x200> */
	goto x86_l_16b2;
x86_l_16c8:
	/* 0x16c8: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_16cb:
	/* 0x16cb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16d0:
	/* 0x16d0: cmp    rcx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 37ULL);
x86_l_16d4:
	/* 0x16d4: ja     1747 <filter_16ty_selector_val+0x7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1747;
	}
x86_l_16d6:
	/* 0x16d6: movabs rdx,0x200c000040 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280128ULL);
x86_l_16e0:
	/* 0x16e0: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_16e4:
	/* 0x16e4: jae    16e7 <filter_16ty_selector_val+0x1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_16e7;
	}
x86_l_16e6:
	/* 0x16e6: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_16e7:
	/* 0x16e7: mov    edx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 24ULL);
x86_l_16ec:
	/* 0x16ec: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_16f0:
	/* 0x16f0: jae    1707 <filter_16ty_selector_val+0x3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1707;
	}
x86_l_16f2:
	/* 0x16f2: movzx  edx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_16f5:
	/* 0x16f5: cmp    DWORD PTR [rdi+0x10],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16f8:
	/* 0x16f8: jne    181d <filter_16ty_selector_val+0x155> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_181d;
	}
x86_l_16fe:
	/* 0x16fe: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1700:
	/* 0x1700: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1703:
	/* 0x1703: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_1706:
	/* 0x1706: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1707:
	/* 0x1707: cmp    rcx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 12ULL);
x86_l_170b:
	/* 0x170b: jne    1747 <filter_16ty_selector_val+0x7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1747;
	}
x86_l_170d:
	/* 0x170d: movzx  ecx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1710:
	/* 0x1710: test   DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1713:
	/* 0x1713: jne    16e6 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_16e6;
	}
x86_l_1715:
	/* 0x1715: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1718:
	/* 0x1718: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_171b:
	/* 0x171b: jb     18df <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18df;
	}
x86_l_1721:
	/* 0x1721: test   DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1724:
	/* 0x1724: jne    16e6 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_16e6;
	}
x86_l_1726:
	/* 0x1726: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1729:
	/* 0x1729: jb     18df <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18df;
	}
x86_l_172f:
	/* 0x172f: test   DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1732:
	/* 0x1732: jne    16e6 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_16e6;
	}
x86_l_1734:
	/* 0x1734: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_1737:
	/* 0x1737: jb     18df <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18df;
	}
x86_l_173d:
	/* 0x173d: test   DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1740:
	/* 0x1740: jne    16e6 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_16e6;
	}
x86_l_1742:
	/* 0x1742: jmp    18df <filter_16ty_selector_val+0x217> */
	goto x86_l_18df;
x86_l_1747:
	/* 0x1747: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_174a:
	/* 0x174a: je     17b9 <filter_16ty_selector_val+0xf1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17b9;
	}
x86_l_174c:
	/* 0x174c: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_174f:
	/* 0x174f: jne    18df <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_18df;
	}
x86_l_1755:
	/* 0x1755: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1758:
	/* 0x1758: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_175b:
	/* 0x175b: ja     18a6 <filter_16ty_selector_val+0x1de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_18a6;
	}
x86_l_1761:
	/* 0x1761: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_1766:
	/* 0x1766: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_1769:
	/* 0x1769: jae    18a6 <filter_16ty_selector_val+0x1de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_18a6;
	}
x86_l_176f:
	/* 0x176f: movsx  ecx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1772:
	/* 0x1772: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1775:
	/* 0x1775: jg     16e6 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_16e6;
	}
x86_l_177b:
	/* 0x177b: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_177e:
	/* 0x177e: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1781:
	/* 0x1781: jb     18df <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18df;
	}
x86_l_1787:
	/* 0x1787: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_178a:
	/* 0x178a: jg     16e6 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_16e6;
	}
x86_l_1790:
	/* 0x1790: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1793:
	/* 0x1793: jb     18df <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18df;
	}
x86_l_1799:
	/* 0x1799: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_179c:
	/* 0x179c: jg     16e6 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_16e6;
	}
x86_l_17a2:
	/* 0x17a2: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_17a5:
	/* 0x17a5: jb     18df <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18df;
	}
x86_l_17ab:
	/* 0x17ab: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_17ae:
	/* 0x17ae: jg     16e6 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_16e6;
	}
x86_l_17b4:
	/* 0x17b4: jmp    18df <filter_16ty_selector_val+0x217> */
	goto x86_l_18df;
x86_l_17b9:
	/* 0x17b9: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_17bc:
	/* 0x17bc: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_17bf:
	/* 0x17bf: ja     186b <filter_16ty_selector_val+0x1a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_186b;
	}
x86_l_17c5:
	/* 0x17c5: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_17ca:
	/* 0x17ca: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_17cd:
	/* 0x17cd: jae    186b <filter_16ty_selector_val+0x1a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_186b;
	}
x86_l_17d3:
	/* 0x17d3: movsx  ecx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_17d6:
	/* 0x17d6: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17d9:
	/* 0x17d9: jl     16e6 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_16e6;
	}
x86_l_17df:
	/* 0x17df: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17e2:
	/* 0x17e2: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_17e5:
	/* 0x17e5: jb     18df <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18df;
	}
x86_l_17eb:
	/* 0x17eb: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_17ee:
	/* 0x17ee: jl     16e6 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_16e6;
	}
x86_l_17f4:
	/* 0x17f4: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_17f7:
	/* 0x17f7: jb     18df <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18df;
	}
x86_l_17fd:
	/* 0x17fd: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1800:
	/* 0x1800: jl     16e6 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_16e6;
	}
x86_l_1806:
	/* 0x1806: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_1809:
	/* 0x1809: jb     18df <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18df;
	}
x86_l_180f:
	/* 0x180f: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1812:
	/* 0x1812: jl     16e6 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_16e6;
	}
x86_l_1818:
	/* 0x1818: jmp    18df <filter_16ty_selector_val+0x217> */
	goto x86_l_18df;
x86_l_181d:
	/* 0x181d: mov    esi,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1820:
	/* 0x1820: cmp    esi,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 13ULL);
x86_l_1823:
	/* 0x1823: jb     184a <filter_16ty_selector_val+0x182> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_184a;
	}
x86_l_1825:
	/* 0x1825: cmp    DWORD PTR [rdi+0x14],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1828:
	/* 0x1828: je     16fe <filter_16ty_selector_val+0x36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16fe;
	}
x86_l_182e:
	/* 0x182e: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_1831:
	/* 0x1831: jb     184a <filter_16ty_selector_val+0x182> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_184a;
	}
x86_l_1833:
	/* 0x1833: cmp    DWORD PTR [rdi+0x18],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1836:
	/* 0x1836: je     16fe <filter_16ty_selector_val+0x36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16fe;
	}
x86_l_183c:
	/* 0x183c: cmp    esi,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 21ULL);
x86_l_183f:
	/* 0x183f: jb     184a <filter_16ty_selector_val+0x182> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_184a;
	}
x86_l_1841:
	/* 0x1841: cmp    DWORD PTR [rdi+0x1c],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1844:
	/* 0x1844: je     16fe <filter_16ty_selector_val+0x36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16fe;
	}
x86_l_184a:
	/* 0x184a: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_184d:
	/* 0x184d: ja     18df <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_18df;
	}
x86_l_1853:
	/* 0x1853: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1855:
	/* 0x1855: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_185f:
	/* 0x185f: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1863:
	/* 0x1863: jb     16e6 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_16e6;
	}
x86_l_1869:
	/* 0x1869: jmp    18df <filter_16ty_selector_val+0x217> */
	goto x86_l_18df;
x86_l_186b:
	/* 0x186b: movzx  ecx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_186e:
	/* 0x186e: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1871:
	/* 0x1871: jb     16e6 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_16e6;
	}
x86_l_1877:
	/* 0x1877: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_187a:
	/* 0x187a: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_187d:
	/* 0x187d: jb     18df <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18df;
	}
x86_l_187f:
	/* 0x187f: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1882:
	/* 0x1882: jb     16e6 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_16e6;
	}
x86_l_1888:
	/* 0x1888: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_188b:
	/* 0x188b: jb     18df <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18df;
	}
x86_l_188d:
	/* 0x188d: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1890:
	/* 0x1890: jb     16e6 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_16e6;
	}
x86_l_1896:
	/* 0x1896: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_1899:
	/* 0x1899: jb     18df <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18df;
	}
x86_l_189b:
	/* 0x189b: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_189e:
	/* 0x189e: jb     16e6 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_16e6;
	}
x86_l_18a4:
	/* 0x18a4: jmp    18df <filter_16ty_selector_val+0x217> */
	goto x86_l_18df;
x86_l_18a6:
	/* 0x18a6: movzx  ecx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_18a9:
	/* 0x18a9: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18ac:
	/* 0x18ac: ja     16e6 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_16e6;
	}
x86_l_18b2:
	/* 0x18b2: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18b5:
	/* 0x18b5: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_18b8:
	/* 0x18b8: jb     18df <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18df;
	}
x86_l_18ba:
	/* 0x18ba: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_18bd:
	/* 0x18bd: ja     16e6 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_16e6;
	}
x86_l_18c3:
	/* 0x18c3: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_18c6:
	/* 0x18c6: jb     18df <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18df;
	}
x86_l_18c8:
	/* 0x18c8: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18cb:
	/* 0x18cb: ja     16e6 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_16e6;
	}
x86_l_18d1:
	/* 0x18d1: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_18d4:
	/* 0x18d4: jb     18df <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18df;
	}
x86_l_18d6:
	/* 0x18d6: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_18d9:
	/* 0x18d9: ja     16e6 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_16e6;
	}
x86_l_18df:
	/* 0x18df: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18e1:
	/* 0x18e1: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_18e2:
	/* 0x18e2: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_18e5:
	/* 0x18e5: mov    eax,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_18e8:
	/* 0x18e8: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_18eb:
	/* 0x18eb: ja     19d2 <filter_16ty_range+0xf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_19d2;
	}
x86_l_18f1:
	/* 0x18f1: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_18f6:
	/* 0x18f6: bt     edx,eax */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_18f9:
	/* 0x18f9: jae    19d2 <filter_16ty_range+0xf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_19d2;
	}
x86_l_18ff:
	/* 0x18ff: movsx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1902:
	/* 0x1902: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_1905:
	/* 0x1905: jne    196d <filter_16ty_range+0x8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_196d;
	}
x86_l_1907:
	/* 0x1907: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_190c:
	/* 0x190c: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_190f:
	/* 0x190f: jg     191a <filter_16ty_range+0x38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_191a;
	}
x86_l_1911:
	/* 0x1911: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1914:
	/* 0x1914: jge    19e9 <filter_16ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_GE)) {
		goto x86_l_19e9;
	}
x86_l_191a:
	/* 0x191a: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_191d:
	/* 0x191d: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1920:
	/* 0x1920: jb     1a89 <filter_16ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1a89;
	}
x86_l_1926:
	/* 0x1926: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1929:
	/* 0x1929: jg     1934 <filter_16ty_range+0x52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1934;
	}
x86_l_192b:
	/* 0x192b: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_192e:
	/* 0x192e: jge    19e9 <filter_16ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_GE)) {
		goto x86_l_19e9;
	}
x86_l_1934:
	/* 0x1934: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_1937:
	/* 0x1937: jb     1a89 <filter_16ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1a89;
	}
x86_l_193d:
	/* 0x193d: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1940:
	/* 0x1940: jg     194b <filter_16ty_range+0x69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_194b;
	}
x86_l_1942:
	/* 0x1942: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1945:
	/* 0x1945: jge    19e9 <filter_16ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_GE)) {
		goto x86_l_19e9;
	}
x86_l_194b:
	/* 0x194b: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_194e:
	/* 0x194e: jb     1a89 <filter_16ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1a89;
	}
x86_l_1954:
	/* 0x1954: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1956:
	/* 0x1956: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1959:
	/* 0x1959: jg     1a8b <filter_16ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1a8b;
	}
x86_l_195f:
	/* 0x195f: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1962:
	/* 0x1962: jge    19e9 <filter_16ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_GE)) {
		goto x86_l_19e9;
	}
x86_l_1968:
	/* 0x1968: jmp    1a8b <filter_16ty_range+0x1a9> */
	goto x86_l_1a8b;
x86_l_196d:
	/* 0x196d: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1970:
	/* 0x1970: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1973:
	/* 0x1973: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_1977:
	/* 0x1977: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_197a:
	/* 0x197a: setge  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_GE);
x86_l_197d:
	/* 0x197d: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1980:
	/* 0x1980: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1983:
	/* 0x1983: jb     1a8b <filter_16ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1a8b;
	}
x86_l_1989:
	/* 0x1989: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_198c:
	/* 0x198c: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_1990:
	/* 0x1990: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1993:
	/* 0x1993: setge  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_GE);
x86_l_1997:
	/* 0x1997: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_199a:
	/* 0x199a: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_199d:
	/* 0x199d: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_19a0:
	/* 0x19a0: jb     1a8b <filter_16ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1a8b;
	}
x86_l_19a6:
	/* 0x19a6: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_19a9:
	/* 0x19a9: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_19ad:
	/* 0x19ad: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_19b0:
	/* 0x19b0: setge  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_GE);
x86_l_19b4:
	/* 0x19b4: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_19b7:
	/* 0x19b7: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_19ba:
	/* 0x19ba: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_19bd:
	/* 0x19bd: jb     1a8b <filter_16ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1a8b;
	}
x86_l_19c3:
	/* 0x19c3: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_19c6:
	/* 0x19c6: setle  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_LE);
x86_l_19c9:
	/* 0x19c9: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_19cc:
	/* 0x19cc: setge  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_GE);
x86_l_19d0:
	/* 0x19d0: jmp    1a45 <filter_16ty_range+0x163> */
	goto x86_l_1a45;
x86_l_19d2:
	/* 0x19d2: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_19d5:
	/* 0x19d5: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_19d8:
	/* 0x19d8: jne    19ea <filter_16ty_range+0x108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_19ea;
	}
x86_l_19da:
	/* 0x19da: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_19df:
	/* 0x19df: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19e2:
	/* 0x19e2: ja     1a4d <filter_16ty_range+0x16b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1a4d;
	}
x86_l_19e4:
	/* 0x19e4: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_19e7:
	/* 0x19e7: jb     1a4d <filter_16ty_range+0x16b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1a4d;
	}
x86_l_19e9:
	/* 0x19e9: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_19ea:
	/* 0x19ea: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19ed:
	/* 0x19ed: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19f0:
	/* 0x19f0: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_19f4:
	/* 0x19f4: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_19f7:
	/* 0x19f7: setae  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_AE);
x86_l_19fa:
	/* 0x19fa: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_19fd:
	/* 0x19fd: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1a00:
	/* 0x1a00: jb     1a8b <filter_16ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1a8b;
	}
x86_l_1a06:
	/* 0x1a06: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a09:
	/* 0x1a09: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_1a0d:
	/* 0x1a0d: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1a10:
	/* 0x1a10: setae  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_AE);
x86_l_1a14:
	/* 0x1a14: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1a17:
	/* 0x1a17: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_1a1a:
	/* 0x1a1a: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1a1d:
	/* 0x1a1d: jb     1a8b <filter_16ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1a8b;
	}
x86_l_1a1f:
	/* 0x1a1f: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a22:
	/* 0x1a22: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_1a26:
	/* 0x1a26: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1a29:
	/* 0x1a29: setae  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_AE);
x86_l_1a2d:
	/* 0x1a2d: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1a30:
	/* 0x1a30: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_1a33:
	/* 0x1a33: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_1a36:
	/* 0x1a36: jb     1a8b <filter_16ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1a8b;
	}
x86_l_1a38:
	/* 0x1a38: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1a3b:
	/* 0x1a3b: setbe  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_BE);
x86_l_1a3e:
	/* 0x1a3e: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1a41:
	/* 0x1a41: setae  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_AE);
x86_l_1a45:
	/* 0x1a45: and    sil,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_1a48:
	/* 0x1a48: or     dl,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_8, X86_ALU_OR);
x86_l_1a4b:
	/* 0x1a4b: jmp    1a8b <filter_16ty_range+0x1a9> */
	goto x86_l_1a8b;
x86_l_1a4d:
	/* 0x1a4d: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a50:
	/* 0x1a50: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1a53:
	/* 0x1a53: jb     1a89 <filter_16ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1a89;
	}
x86_l_1a55:
	/* 0x1a55: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a58:
	/* 0x1a58: ja     1a5f <filter_16ty_range+0x17d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1a5f;
	}
x86_l_1a5a:
	/* 0x1a5a: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1a5d:
	/* 0x1a5d: jae    19e9 <filter_16ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_19e9;
	}
x86_l_1a5f:
	/* 0x1a5f: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_1a62:
	/* 0x1a62: jb     1a89 <filter_16ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1a89;
	}
x86_l_1a64:
	/* 0x1a64: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a67:
	/* 0x1a67: ja     1a72 <filter_16ty_range+0x190> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1a72;
	}
x86_l_1a69:
	/* 0x1a69: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1a6c:
	/* 0x1a6c: jae    19e9 <filter_16ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_19e9;
	}
x86_l_1a72:
	/* 0x1a72: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_1a75:
	/* 0x1a75: jb     1a89 <filter_16ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1a89;
	}
x86_l_1a77:
	/* 0x1a77: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a79:
	/* 0x1a79: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1a7c:
	/* 0x1a7c: ja     1a8b <filter_16ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1a8b;
	}
x86_l_1a7e:
	/* 0x1a7e: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1a81:
	/* 0x1a81: jae    19e9 <filter_16ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_19e9;
	}
x86_l_1a87:
	/* 0x1a87: jmp    1a8b <filter_16ty_range+0x1a9> */
	goto x86_l_1a8b;
x86_l_1a89:
	/* 0x1a89: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a8b:
	/* 0x1a8b: cmp    ecx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 32ULL);
x86_l_1a8e:
	/* 0x1a8e: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_1a91:
	/* 0x1a91: xor    dl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_1a94:
	/* 0x1a94: and    dl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_1a96:
	/* 0x1a96: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1a99:
	/* 0x1a99: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1a9a:
	/* 0x1a9a: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_1a9c:
	/* 0x1a9c: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_1a9d:
	/* 0x1a9d: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_1aa1:
	/* 0x1aa1: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_1aa4:
	/* 0x1aa4: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_1aa7:
	/* 0x1aa7: movzx  eax,BYTE PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1aab:
	/* 0x1aab: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1aaf:
	/* 0x1aaf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ab4:
	/* 0x1ab4: mov    rdi,QWORD PTR [rip+0x1290] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_1abb:
	/* 0x1abb: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1ac0:
	/* 0x1ac0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ac2:
	/* 0x1ac2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ac5:
	/* 0x1ac5: je     1afb <filter_16ty_map+0x61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1afb;
	}
x86_l_1ac7:
	/* 0x1ac7: movzx  ecx,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1acb:
	/* 0x1acb: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ad0:
	/* 0x1ad0: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1ad5:
	/* 0x1ad5: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ada:
	/* 0x1ada: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1add:
	/* 0x1add: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1adf:
	/* 0x1adf: mov    edx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1ae2:
	/* 0x1ae2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ae4:
	/* 0x1ae4: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_1ae7:
	/* 0x1ae7: ja     1b15 <filter_16ty_map+0x7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1b15;
	}
x86_l_1ae9:
	/* 0x1ae9: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_1aee:
	/* 0x1aee: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1af1:
	/* 0x1af1: jae    1b05 <filter_16ty_map+0x6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1b05;
	}
x86_l_1af3:
	/* 0x1af3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1af6:
	/* 0x1af6: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_1af9:
	/* 0x1af9: jmp    1b15 <filter_16ty_map+0x7b> */
	goto x86_l_1b15;
x86_l_1afb:
	/* 0x1afb: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1afd:
	/* 0x1afd: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1b01:
	/* 0x1b01: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1b02:
	/* 0x1b02: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_1b04:
	/* 0x1b04: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1b05:
	/* 0x1b05: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_1b0a:
	/* 0x1b0a: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1b0d:
	/* 0x1b0d: jae    1b15 <filter_16ty_map+0x7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1b15;
	}
x86_l_1b0f:
	/* 0x1b0f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b12:
	/* 0x1b12: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_1b15:
	/* 0x1b15: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1b18:
	/* 0x1b18: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1b1c:
	/* 0x1b1c: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1b1d:
	/* 0x1b1d: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_1b1f:
	/* 0x1b1f: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1b20:
	/* 0x1b20: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1b23:
	/* 0x1b23: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b28:
	/* 0x1b28: cmp    rcx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 37ULL);
x86_l_1b2c:
	/* 0x1b2c: ja     1b9d <filter_32ty_selector_val+0x7d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7069ULL;
	}
x86_l_1b2e:
	/* 0x1b2e: movabs rdx,0x200c000040 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280128ULL);
x86_l_1b38:
	/* 0x1b38: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
	return 6972ULL;
}

static __noinline __u64 tetragon_bpf_multi_usdt_v61_generic_usdt_filter_arg_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 6972ULL: goto x86_l_1b3c;
	case 6974ULL: goto x86_l_1b3e;
	case 6975ULL: goto x86_l_1b3f;
	case 6980ULL: goto x86_l_1b44;
	case 6984ULL: goto x86_l_1b48;
	case 6986ULL: goto x86_l_1b4a;
	case 6988ULL: goto x86_l_1b4c;
	case 6991ULL: goto x86_l_1b4f;
	case 6997ULL: goto x86_l_1b55;
	case 6999ULL: goto x86_l_1b57;
	case 7002ULL: goto x86_l_1b5a;
	case 7005ULL: goto x86_l_1b5d;
	case 7006ULL: goto x86_l_1b5e;
	case 7010ULL: goto x86_l_1b62;
	case 7012ULL: goto x86_l_1b64;
	case 7014ULL: goto x86_l_1b66;
	case 7017ULL: goto x86_l_1b69;
	case 7019ULL: goto x86_l_1b6b;
	case 7022ULL: goto x86_l_1b6e;
	case 7025ULL: goto x86_l_1b71;
	case 7031ULL: goto x86_l_1b77;
	case 7034ULL: goto x86_l_1b7a;
	case 7036ULL: goto x86_l_1b7c;
	case 7039ULL: goto x86_l_1b7f;
	case 7045ULL: goto x86_l_1b85;
	case 7048ULL: goto x86_l_1b88;
	case 7050ULL: goto x86_l_1b8a;
	case 7053ULL: goto x86_l_1b8d;
	case 7059ULL: goto x86_l_1b93;
	case 7062ULL: goto x86_l_1b96;
	case 7064ULL: goto x86_l_1b98;
	case 7069ULL: goto x86_l_1b9d;
	case 7072ULL: goto x86_l_1ba0;
	case 7074ULL: goto x86_l_1ba2;
	case 7077ULL: goto x86_l_1ba5;
	case 7083ULL: goto x86_l_1bab;
	case 7086ULL: goto x86_l_1bae;
	case 7089ULL: goto x86_l_1bb1;
	case 7095ULL: goto x86_l_1bb7;
	case 7100ULL: goto x86_l_1bbc;
	case 7103ULL: goto x86_l_1bbf;
	case 7109ULL: goto x86_l_1bc5;
	case 7111ULL: goto x86_l_1bc7;
	case 7114ULL: goto x86_l_1bca;
	case 7120ULL: goto x86_l_1bd0;
	case 7123ULL: goto x86_l_1bd3;
	case 7126ULL: goto x86_l_1bd6;
	case 7132ULL: goto x86_l_1bdc;
	case 7135ULL: goto x86_l_1bdf;
	case 7141ULL: goto x86_l_1be5;
	case 7144ULL: goto x86_l_1be8;
	case 7150ULL: goto x86_l_1bee;
	case 7153ULL: goto x86_l_1bf1;
	case 7159ULL: goto x86_l_1bf7;
	case 7162ULL: goto x86_l_1bfa;
	case 7168ULL: goto x86_l_1c00;
	case 7171ULL: goto x86_l_1c03;
	case 7177ULL: goto x86_l_1c09;
	case 7182ULL: goto x86_l_1c0e;
	case 7185ULL: goto x86_l_1c11;
	case 7188ULL: goto x86_l_1c14;
	case 7194ULL: goto x86_l_1c1a;
	case 7199ULL: goto x86_l_1c1f;
	case 7202ULL: goto x86_l_1c22;
	case 7208ULL: goto x86_l_1c28;
	case 7210ULL: goto x86_l_1c2a;
	case 7213ULL: goto x86_l_1c2d;
	case 7219ULL: goto x86_l_1c33;
	case 7222ULL: goto x86_l_1c36;
	case 7225ULL: goto x86_l_1c39;
	case 7231ULL: goto x86_l_1c3f;
	case 7234ULL: goto x86_l_1c42;
	case 7240ULL: goto x86_l_1c48;
	case 7243ULL: goto x86_l_1c4b;
	case 7249ULL: goto x86_l_1c51;
	case 7252ULL: goto x86_l_1c54;
	case 7258ULL: goto x86_l_1c5a;
	case 7261ULL: goto x86_l_1c5d;
	case 7267ULL: goto x86_l_1c63;
	case 7270ULL: goto x86_l_1c66;
	case 7276ULL: goto x86_l_1c6c;
	case 7281ULL: goto x86_l_1c71;
	case 7284ULL: goto x86_l_1c74;
	case 7287ULL: goto x86_l_1c77;
	case 7289ULL: goto x86_l_1c79;
	case 7292ULL: goto x86_l_1c7c;
	case 7298ULL: goto x86_l_1c82;
	case 7301ULL: goto x86_l_1c85;
	case 7303ULL: goto x86_l_1c87;
	case 7306ULL: goto x86_l_1c8a;
	case 7312ULL: goto x86_l_1c90;
	case 7315ULL: goto x86_l_1c93;
	case 7317ULL: goto x86_l_1c95;
	case 7320ULL: goto x86_l_1c98;
	case 7326ULL: goto x86_l_1c9e;
	case 7329ULL: goto x86_l_1ca1;
	case 7335ULL: goto x86_l_1ca7;
	case 7337ULL: goto x86_l_1ca9;
	case 7347ULL: goto x86_l_1cb3;
	case 7351ULL: goto x86_l_1cb7;
	case 7357ULL: goto x86_l_1cbd;
	case 7359ULL: goto x86_l_1cbf;
	case 7361ULL: goto x86_l_1cc1;
	case 7364ULL: goto x86_l_1cc4;
	case 7370ULL: goto x86_l_1cca;
	case 7373ULL: goto x86_l_1ccd;
	case 7376ULL: goto x86_l_1cd0;
	case 7378ULL: goto x86_l_1cd2;
	case 7381ULL: goto x86_l_1cd5;
	case 7387ULL: goto x86_l_1cdb;
	case 7390ULL: goto x86_l_1cde;
	case 7392ULL: goto x86_l_1ce0;
	case 7395ULL: goto x86_l_1ce3;
	case 7401ULL: goto x86_l_1ce9;
	case 7404ULL: goto x86_l_1cec;
	case 7406ULL: goto x86_l_1cee;
	case 7409ULL: goto x86_l_1cf1;
	case 7415ULL: goto x86_l_1cf7;
	case 7417ULL: goto x86_l_1cf9;
	case 7419ULL: goto x86_l_1cfb;
	case 7422ULL: goto x86_l_1cfe;
	case 7428ULL: goto x86_l_1d04;
	case 7431ULL: goto x86_l_1d07;
	case 7434ULL: goto x86_l_1d0a;
	case 7436ULL: goto x86_l_1d0c;
	case 7439ULL: goto x86_l_1d0f;
	case 7445ULL: goto x86_l_1d15;
	case 7448ULL: goto x86_l_1d18;
	case 7450ULL: goto x86_l_1d1a;
	case 7453ULL: goto x86_l_1d1d;
	case 7459ULL: goto x86_l_1d23;
	case 7462ULL: goto x86_l_1d26;
	case 7464ULL: goto x86_l_1d28;
	case 7467ULL: goto x86_l_1d2b;
	case 7473ULL: goto x86_l_1d31;
	case 7475ULL: goto x86_l_1d33;
	case 7476ULL: goto x86_l_1d34;
	case 7479ULL: goto x86_l_1d37;
	case 7482ULL: goto x86_l_1d3a;
	case 7485ULL: goto x86_l_1d3d;
	case 7491ULL: goto x86_l_1d43;
	case 7496ULL: goto x86_l_1d48;
	case 7499ULL: goto x86_l_1d4b;
	case 7505ULL: goto x86_l_1d51;
	case 7507ULL: goto x86_l_1d53;
	case 7510ULL: goto x86_l_1d56;
	case 7512ULL: goto x86_l_1d58;
	case 7517ULL: goto x86_l_1d5d;
	case 7520ULL: goto x86_l_1d60;
	case 7522ULL: goto x86_l_1d62;
	case 7525ULL: goto x86_l_1d65;
	case 7531ULL: goto x86_l_1d6b;
	case 7534ULL: goto x86_l_1d6e;
	case 7537ULL: goto x86_l_1d71;
	case 7543ULL: goto x86_l_1d77;
	case 7546ULL: goto x86_l_1d7a;
	case 7548ULL: goto x86_l_1d7c;
	case 7551ULL: goto x86_l_1d7f;
	case 7557ULL: goto x86_l_1d85;
	case 7560ULL: goto x86_l_1d88;
	case 7566ULL: goto x86_l_1d8e;
	case 7569ULL: goto x86_l_1d91;
	case 7571ULL: goto x86_l_1d93;
	case 7574ULL: goto x86_l_1d96;
	case 7580ULL: goto x86_l_1d9c;
	case 7583ULL: goto x86_l_1d9f;
	case 7589ULL: goto x86_l_1da5;
	case 7591ULL: goto x86_l_1da7;
	case 7594ULL: goto x86_l_1daa;
	case 7600ULL: goto x86_l_1db0;
	case 7603ULL: goto x86_l_1db3;
	case 7609ULL: goto x86_l_1db9;
	case 7614ULL: goto x86_l_1dbe;
	case 7617ULL: goto x86_l_1dc1;
	case 7620ULL: goto x86_l_1dc4;
	case 7624ULL: goto x86_l_1dc8;
	case 7627ULL: goto x86_l_1dcb;
	case 7630ULL: goto x86_l_1dce;
	case 7633ULL: goto x86_l_1dd1;
	case 7636ULL: goto x86_l_1dd4;
	case 7642ULL: goto x86_l_1dda;
	case 7645ULL: goto x86_l_1ddd;
	case 7649ULL: goto x86_l_1de1;
	case 7652ULL: goto x86_l_1de4;
	case 7656ULL: goto x86_l_1de8;
	case 7659ULL: goto x86_l_1deb;
	case 7662ULL: goto x86_l_1dee;
	case 7665ULL: goto x86_l_1df1;
	case 7671ULL: goto x86_l_1df7;
	case 7674ULL: goto x86_l_1dfa;
	case 7678ULL: goto x86_l_1dfe;
	case 7681ULL: goto x86_l_1e01;
	case 7685ULL: goto x86_l_1e05;
	case 7688ULL: goto x86_l_1e08;
	case 7691ULL: goto x86_l_1e0b;
	case 7694ULL: goto x86_l_1e0e;
	case 7700ULL: goto x86_l_1e14;
	case 7703ULL: goto x86_l_1e17;
	case 7706ULL: goto x86_l_1e1a;
	case 7709ULL: goto x86_l_1e1d;
	case 7713ULL: goto x86_l_1e21;
	case 7715ULL: goto x86_l_1e23;
	case 7717ULL: goto x86_l_1e25;
	case 7720ULL: goto x86_l_1e28;
	case 7722ULL: goto x86_l_1e2a;
	case 7727ULL: goto x86_l_1e2f;
	case 7730ULL: goto x86_l_1e32;
	case 7732ULL: goto x86_l_1e34;
	case 7735ULL: goto x86_l_1e37;
	case 7737ULL: goto x86_l_1e39;
	case 7738ULL: goto x86_l_1e3a;
	case 7741ULL: goto x86_l_1e3d;
	case 7744ULL: goto x86_l_1e40;
	case 7748ULL: goto x86_l_1e44;
	case 7751ULL: goto x86_l_1e47;
	case 7754ULL: goto x86_l_1e4a;
	case 7757ULL: goto x86_l_1e4d;
	case 7760ULL: goto x86_l_1e50;
	case 7766ULL: goto x86_l_1e56;
	case 7769ULL: goto x86_l_1e59;
	case 7773ULL: goto x86_l_1e5d;
	case 7776ULL: goto x86_l_1e60;
	case 7780ULL: goto x86_l_1e64;
	case 7783ULL: goto x86_l_1e67;
	case 7786ULL: goto x86_l_1e6a;
	case 7789ULL: goto x86_l_1e6d;
	case 7791ULL: goto x86_l_1e6f;
	case 7794ULL: goto x86_l_1e72;
	case 7798ULL: goto x86_l_1e76;
	case 7801ULL: goto x86_l_1e79;
	case 7805ULL: goto x86_l_1e7d;
	case 7808ULL: goto x86_l_1e80;
	case 7811ULL: goto x86_l_1e83;
	case 7814ULL: goto x86_l_1e86;
	case 7816ULL: goto x86_l_1e88;
	case 7819ULL: goto x86_l_1e8b;
	case 7822ULL: goto x86_l_1e8e;
	case 7825ULL: goto x86_l_1e91;
	case 7829ULL: goto x86_l_1e95;
	case 7832ULL: goto x86_l_1e98;
	case 7835ULL: goto x86_l_1e9b;
	case 7837ULL: goto x86_l_1e9d;
	case 7840ULL: goto x86_l_1ea0;
	case 7843ULL: goto x86_l_1ea3;
	case 7845ULL: goto x86_l_1ea5;
	case 7848ULL: goto x86_l_1ea8;
	case 7850ULL: goto x86_l_1eaa;
	case 7853ULL: goto x86_l_1ead;
	case 7855ULL: goto x86_l_1eaf;
	case 7858ULL: goto x86_l_1eb2;
	case 7860ULL: goto x86_l_1eb4;
	case 7863ULL: goto x86_l_1eb7;
	case 7865ULL: goto x86_l_1eb9;
	case 7868ULL: goto x86_l_1ebc;
	case 7874ULL: goto x86_l_1ec2;
	case 7877ULL: goto x86_l_1ec5;
	case 7879ULL: goto x86_l_1ec7;
	case 7881ULL: goto x86_l_1ec9;
	case 7884ULL: goto x86_l_1ecc;
	case 7886ULL: goto x86_l_1ece;
	case 7889ULL: goto x86_l_1ed1;
	case 7895ULL: goto x86_l_1ed7;
	case 7897ULL: goto x86_l_1ed9;
	case 7899ULL: goto x86_l_1edb;
	case 7902ULL: goto x86_l_1ede;
	case 7905ULL: goto x86_l_1ee1;
	case 7908ULL: goto x86_l_1ee4;
	case 7910ULL: goto x86_l_1ee6;
	case 7913ULL: goto x86_l_1ee9;
	case 7914ULL: goto x86_l_1eea;
	case 7916ULL: goto x86_l_1eec;
	case 7917ULL: goto x86_l_1eed;
	case 7921ULL: goto x86_l_1ef1;
	case 7924ULL: goto x86_l_1ef4;
	case 7927ULL: goto x86_l_1ef7;
	case 7931ULL: goto x86_l_1efb;
	case 7935ULL: goto x86_l_1eff;
	case 7940ULL: goto x86_l_1f04;
	case 7947ULL: goto x86_l_1f0b;
	case 7952ULL: goto x86_l_1f10;
	case 7954ULL: goto x86_l_1f12;
	case 7957ULL: goto x86_l_1f15;
	case 7959ULL: goto x86_l_1f17;
	case 7962ULL: goto x86_l_1f1a;
	case 7967ULL: goto x86_l_1f1f;
	case 7972ULL: goto x86_l_1f24;
	case 7977ULL: goto x86_l_1f29;
	case 7980ULL: goto x86_l_1f2c;
	case 7982ULL: goto x86_l_1f2e;
	case 7985ULL: goto x86_l_1f31;
	case 7987ULL: goto x86_l_1f33;
	case 7990ULL: goto x86_l_1f36;
	case 7992ULL: goto x86_l_1f38;
	case 7997ULL: goto x86_l_1f3d;
	case 8000ULL: goto x86_l_1f40;
	case 8002ULL: goto x86_l_1f42;
	case 8005ULL: goto x86_l_1f45;
	case 8008ULL: goto x86_l_1f48;
	case 8010ULL: goto x86_l_1f4a;
	case 8012ULL: goto x86_l_1f4c;
	case 8016ULL: goto x86_l_1f50;
	case 8017ULL: goto x86_l_1f51;
	case 8019ULL: goto x86_l_1f53;
	case 8020ULL: goto x86_l_1f54;
	case 8025ULL: goto x86_l_1f59;
	case 8028ULL: goto x86_l_1f5c;
	case 8030ULL: goto x86_l_1f5e;
	case 8033ULL: goto x86_l_1f61;
	case 8036ULL: goto x86_l_1f64;
	case 8039ULL: goto x86_l_1f67;
	case 8043ULL: goto x86_l_1f6b;
	case 8044ULL: goto x86_l_1f6c;
	case 8046ULL: goto x86_l_1f6e;
	case 8047ULL: goto x86_l_1f6f;
	case 8050ULL: goto x86_l_1f72;
	case 8055ULL: goto x86_l_1f77;
	case 8059ULL: goto x86_l_1f7b;
	case 8061ULL: goto x86_l_1f7d;
	case 8071ULL: goto x86_l_1f87;
	case 8075ULL: goto x86_l_1f8b;
	case 8077ULL: goto x86_l_1f8d;
	case 8078ULL: goto x86_l_1f8e;
	case 8083ULL: goto x86_l_1f93;
	case 8087ULL: goto x86_l_1f97;
	case 8089ULL: goto x86_l_1f99;
	case 8092ULL: goto x86_l_1f9c;
	case 8095ULL: goto x86_l_1f9f;
	case 8101ULL: goto x86_l_1fa5;
	case 8103ULL: goto x86_l_1fa7;
	case 8106ULL: goto x86_l_1faa;
	case 8109ULL: goto x86_l_1fad;
	case 8110ULL: goto x86_l_1fae;
	case 8114ULL: goto x86_l_1fb2;
	case 8116ULL: goto x86_l_1fb4;
	case 8119ULL: goto x86_l_1fb7;
	case 8122ULL: goto x86_l_1fba;
	case 8124ULL: goto x86_l_1fbc;
	case 8127ULL: goto x86_l_1fbf;
	case 8130ULL: goto x86_l_1fc2;
	case 8136ULL: goto x86_l_1fc8;
	case 8139ULL: goto x86_l_1fcb;
	case 8141ULL: goto x86_l_1fcd;
	case 8144ULL: goto x86_l_1fd0;
	case 8150ULL: goto x86_l_1fd6;
	case 8153ULL: goto x86_l_1fd9;
	case 8155ULL: goto x86_l_1fdb;
	case 8158ULL: goto x86_l_1fde;
	case 8164ULL: goto x86_l_1fe4;
	case 8167ULL: goto x86_l_1fe7;
	case 8169ULL: goto x86_l_1fe9;
	case 8174ULL: goto x86_l_1fee;
	case 8177ULL: goto x86_l_1ff1;
	case 8179ULL: goto x86_l_1ff3;
	case 8182ULL: goto x86_l_1ff6;
	case 8188ULL: goto x86_l_1ffc;
	case 8191ULL: goto x86_l_1fff;
	case 8194ULL: goto x86_l_2002;
	case 8200ULL: goto x86_l_2008;
	case 8205ULL: goto x86_l_200d;
	case 8208ULL: goto x86_l_2010;
	case 8214ULL: goto x86_l_2016;
	case 8217ULL: goto x86_l_2019;
	case 8220ULL: goto x86_l_201c;
	case 8226ULL: goto x86_l_2022;
	case 8229ULL: goto x86_l_2025;
	case 8232ULL: goto x86_l_2028;
	case 8238ULL: goto x86_l_202e;
	case 8241ULL: goto x86_l_2031;
	case 8247ULL: goto x86_l_2037;
	case 8250ULL: goto x86_l_203a;
	case 8256ULL: goto x86_l_2040;
	case 8259ULL: goto x86_l_2043;
	case 8265ULL: goto x86_l_2049;
	case 8268ULL: goto x86_l_204c;
	case 8274ULL: goto x86_l_2052;
	case 8277ULL: goto x86_l_2055;
	case 8283ULL: goto x86_l_205b;
	case 8288ULL: goto x86_l_2060;
	case 8291ULL: goto x86_l_2063;
	case 8294ULL: goto x86_l_2066;
	case 8300ULL: goto x86_l_206c;
	case 8305ULL: goto x86_l_2071;
	case 8308ULL: goto x86_l_2074;
	case 8314ULL: goto x86_l_207a;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1b3c:
	/* 0x1b3c: jae    1b3f <filter_32ty_selector_val+0x1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1b3f;
	}
x86_l_1b3e:
	/* 0x1b3e: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1b3f:
	/* 0x1b3f: mov    edx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 24ULL);
x86_l_1b44:
	/* 0x1b44: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1b48:
	/* 0x1b48: jae    1b5e <filter_32ty_selector_val+0x3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1b5e;
	}
x86_l_1b4a:
	/* 0x1b4a: mov    edx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b4c:
	/* 0x1b4c: cmp    edx,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_1b4f:
	/* 0x1b4f: jne    1c71 <filter_32ty_selector_val+0x151> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1c71;
	}
x86_l_1b55:
	/* 0x1b55: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b57:
	/* 0x1b57: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1b5a:
	/* 0x1b5a: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_1b5d:
	/* 0x1b5d: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1b5e:
	/* 0x1b5e: cmp    rcx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 12ULL);
x86_l_1b62:
	/* 0x1b62: jne    1b9d <filter_32ty_selector_val+0x7d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1b9d;
	}
x86_l_1b64:
	/* 0x1b64: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b66:
	/* 0x1b66: test   DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b69:
	/* 0x1b69: jne    1b3e <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1b3e;
	}
x86_l_1b6b:
	/* 0x1b6b: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b6e:
	/* 0x1b6e: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1b71:
	/* 0x1b71: jb     1d31 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d31;
	}
x86_l_1b77:
	/* 0x1b77: test   DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1b7a:
	/* 0x1b7a: jne    1b3e <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1b3e;
	}
x86_l_1b7c:
	/* 0x1b7c: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1b7f:
	/* 0x1b7f: jb     1d31 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d31;
	}
x86_l_1b85:
	/* 0x1b85: test   DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b88:
	/* 0x1b88: jne    1b3e <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1b3e;
	}
x86_l_1b8a:
	/* 0x1b8a: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_1b8d:
	/* 0x1b8d: jb     1d31 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d31;
	}
x86_l_1b93:
	/* 0x1b93: test   DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1b96:
	/* 0x1b96: jne    1b3e <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1b3e;
	}
x86_l_1b98:
	/* 0x1b98: jmp    1d31 <filter_32ty_selector_val+0x211> */
	goto x86_l_1d31;
x86_l_1b9d:
	/* 0x1b9d: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1ba0:
	/* 0x1ba0: je     1c0e <filter_32ty_selector_val+0xee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c0e;
	}
x86_l_1ba2:
	/* 0x1ba2: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1ba5:
	/* 0x1ba5: jne    1d31 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d31;
	}
x86_l_1bab:
	/* 0x1bab: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1bae:
	/* 0x1bae: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1bb1:
	/* 0x1bb1: ja     1cf9 <filter_32ty_selector_val+0x1d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1cf9;
	}
x86_l_1bb7:
	/* 0x1bb7: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_1bbc:
	/* 0x1bbc: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_1bbf:
	/* 0x1bbf: jae    1cf9 <filter_32ty_selector_val+0x1d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1cf9;
	}
x86_l_1bc5:
	/* 0x1bc5: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bc7:
	/* 0x1bc7: cmp    ecx,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_1bca:
	/* 0x1bca: jl     1b3e <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_1b3e;
	}
x86_l_1bd0:
	/* 0x1bd0: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bd3:
	/* 0x1bd3: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1bd6:
	/* 0x1bd6: jb     1d31 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d31;
	}
x86_l_1bdc:
	/* 0x1bdc: cmp    ecx,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1bdf:
	/* 0x1bdf: jl     1b3e <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_1b3e;
	}
x86_l_1be5:
	/* 0x1be5: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1be8:
	/* 0x1be8: jb     1d31 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d31;
	}
x86_l_1bee:
	/* 0x1bee: cmp    ecx,DWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 24ULL);
x86_l_1bf1:
	/* 0x1bf1: jl     1b3e <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_1b3e;
	}
x86_l_1bf7:
	/* 0x1bf7: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_1bfa:
	/* 0x1bfa: jb     1d31 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d31;
	}
x86_l_1c00:
	/* 0x1c00: cmp    ecx,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1c03:
	/* 0x1c03: jl     1b3e <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_1b3e;
	}
x86_l_1c09:
	/* 0x1c09: jmp    1d31 <filter_32ty_selector_val+0x211> */
	goto x86_l_1d31;
x86_l_1c0e:
	/* 0x1c0e: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1c11:
	/* 0x1c11: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1c14:
	/* 0x1c14: ja     1cbf <filter_32ty_selector_val+0x19f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1cbf;
	}
x86_l_1c1a:
	/* 0x1c1a: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_1c1f:
	/* 0x1c1f: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_1c22:
	/* 0x1c22: jae    1cbf <filter_32ty_selector_val+0x19f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1cbf;
	}
x86_l_1c28:
	/* 0x1c28: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c2a:
	/* 0x1c2a: cmp    ecx,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_1c2d:
	/* 0x1c2d: jg     1b3e <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1b3e;
	}
x86_l_1c33:
	/* 0x1c33: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c36:
	/* 0x1c36: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1c39:
	/* 0x1c39: jb     1d31 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d31;
	}
x86_l_1c3f:
	/* 0x1c3f: cmp    ecx,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1c42:
	/* 0x1c42: jg     1b3e <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1b3e;
	}
x86_l_1c48:
	/* 0x1c48: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1c4b:
	/* 0x1c4b: jb     1d31 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d31;
	}
x86_l_1c51:
	/* 0x1c51: cmp    ecx,DWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 24ULL);
x86_l_1c54:
	/* 0x1c54: jg     1b3e <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1b3e;
	}
x86_l_1c5a:
	/* 0x1c5a: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_1c5d:
	/* 0x1c5d: jb     1d31 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d31;
	}
x86_l_1c63:
	/* 0x1c63: cmp    ecx,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1c66:
	/* 0x1c66: jg     1b3e <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1b3e;
	}
x86_l_1c6c:
	/* 0x1c6c: jmp    1d31 <filter_32ty_selector_val+0x211> */
	goto x86_l_1d31;
x86_l_1c71:
	/* 0x1c71: mov    esi,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c74:
	/* 0x1c74: cmp    esi,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 13ULL);
x86_l_1c77:
	/* 0x1c77: jb     1c9e <filter_32ty_selector_val+0x17e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1c9e;
	}
x86_l_1c79:
	/* 0x1c79: cmp    edx,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1c7c:
	/* 0x1c7c: je     1b55 <filter_32ty_selector_val+0x35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b55;
	}
x86_l_1c82:
	/* 0x1c82: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_1c85:
	/* 0x1c85: jb     1c9e <filter_32ty_selector_val+0x17e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1c9e;
	}
x86_l_1c87:
	/* 0x1c87: cmp    edx,DWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 24ULL);
x86_l_1c8a:
	/* 0x1c8a: je     1b55 <filter_32ty_selector_val+0x35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b55;
	}
x86_l_1c90:
	/* 0x1c90: cmp    esi,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 21ULL);
x86_l_1c93:
	/* 0x1c93: jb     1c9e <filter_32ty_selector_val+0x17e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1c9e;
	}
x86_l_1c95:
	/* 0x1c95: cmp    edx,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1c98:
	/* 0x1c98: je     1b55 <filter_32ty_selector_val+0x35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b55;
	}
x86_l_1c9e:
	/* 0x1c9e: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_1ca1:
	/* 0x1ca1: ja     1d31 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1d31;
	}
x86_l_1ca7:
	/* 0x1ca7: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1ca9:
	/* 0x1ca9: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_1cb3:
	/* 0x1cb3: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1cb7:
	/* 0x1cb7: jb     1b3e <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1b3e;
	}
x86_l_1cbd:
	/* 0x1cbd: jmp    1d31 <filter_32ty_selector_val+0x211> */
	goto x86_l_1d31;
x86_l_1cbf:
	/* 0x1cbf: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cc1:
	/* 0x1cc1: cmp    ecx,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_1cc4:
	/* 0x1cc4: ja     1b3e <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1b3e;
	}
x86_l_1cca:
	/* 0x1cca: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ccd:
	/* 0x1ccd: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1cd0:
	/* 0x1cd0: jb     1d31 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d31;
	}
x86_l_1cd2:
	/* 0x1cd2: cmp    ecx,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1cd5:
	/* 0x1cd5: ja     1b3e <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1b3e;
	}
x86_l_1cdb:
	/* 0x1cdb: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1cde:
	/* 0x1cde: jb     1d31 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d31;
	}
x86_l_1ce0:
	/* 0x1ce0: cmp    ecx,DWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 24ULL);
x86_l_1ce3:
	/* 0x1ce3: ja     1b3e <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1b3e;
	}
x86_l_1ce9:
	/* 0x1ce9: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_1cec:
	/* 0x1cec: jb     1d31 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d31;
	}
x86_l_1cee:
	/* 0x1cee: cmp    ecx,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1cf1:
	/* 0x1cf1: ja     1b3e <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1b3e;
	}
x86_l_1cf7:
	/* 0x1cf7: jmp    1d31 <filter_32ty_selector_val+0x211> */
	goto x86_l_1d31;
x86_l_1cf9:
	/* 0x1cf9: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cfb:
	/* 0x1cfb: cmp    ecx,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_1cfe:
	/* 0x1cfe: jb     1b3e <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1b3e;
	}
x86_l_1d04:
	/* 0x1d04: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d07:
	/* 0x1d07: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1d0a:
	/* 0x1d0a: jb     1d31 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d31;
	}
x86_l_1d0c:
	/* 0x1d0c: cmp    ecx,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1d0f:
	/* 0x1d0f: jb     1b3e <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1b3e;
	}
x86_l_1d15:
	/* 0x1d15: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1d18:
	/* 0x1d18: jb     1d31 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d31;
	}
x86_l_1d1a:
	/* 0x1d1a: cmp    ecx,DWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 24ULL);
x86_l_1d1d:
	/* 0x1d1d: jb     1b3e <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1b3e;
	}
x86_l_1d23:
	/* 0x1d23: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_1d26:
	/* 0x1d26: jb     1d31 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d31;
	}
x86_l_1d28:
	/* 0x1d28: cmp    ecx,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1d2b:
	/* 0x1d2b: jb     1b3e <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1b3e;
	}
x86_l_1d31:
	/* 0x1d31: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d33:
	/* 0x1d33: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1d34:
	/* 0x1d34: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d37:
	/* 0x1d37: mov    eax,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1d3a:
	/* 0x1d3a: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1d3d:
	/* 0x1d3d: ja     1e23 <filter_32ty_range+0xef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1e23;
	}
x86_l_1d43:
	/* 0x1d43: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_1d48:
	/* 0x1d48: bt     edx,eax */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_1d4b:
	/* 0x1d4b: jae    1e23 <filter_32ty_range+0xef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1e23;
	}
x86_l_1d51:
	/* 0x1d51: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d53:
	/* 0x1d53: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_1d56:
	/* 0x1d56: jne    1dbe <filter_32ty_range+0x8a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1dbe;
	}
x86_l_1d58:
	/* 0x1d58: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d5d:
	/* 0x1d5d: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d60:
	/* 0x1d60: jg     1d6b <filter_32ty_range+0x37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1d6b;
	}
x86_l_1d62:
	/* 0x1d62: cmp    esi,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1d65:
	/* 0x1d65: jle    1e39 <filter_32ty_range+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1e39;
	}
x86_l_1d6b:
	/* 0x1d6b: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d6e:
	/* 0x1d6e: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1d71:
	/* 0x1d71: jb     1ed9 <filter_32ty_range+0x1a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1ed9;
	}
x86_l_1d77:
	/* 0x1d77: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d7a:
	/* 0x1d7a: jg     1d85 <filter_32ty_range+0x51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1d85;
	}
x86_l_1d7c:
	/* 0x1d7c: cmp    esi,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1d7f:
	/* 0x1d7f: jle    1e39 <filter_32ty_range+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1e39;
	}
x86_l_1d85:
	/* 0x1d85: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_1d88:
	/* 0x1d88: jb     1ed9 <filter_32ty_range+0x1a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1ed9;
	}
x86_l_1d8e:
	/* 0x1d8e: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d91:
	/* 0x1d91: jg     1d9c <filter_32ty_range+0x68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1d9c;
	}
x86_l_1d93:
	/* 0x1d93: cmp    esi,DWORD PTR [rdi+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_1d96:
	/* 0x1d96: jle    1e39 <filter_32ty_range+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1e39;
	}
x86_l_1d9c:
	/* 0x1d9c: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_1d9f:
	/* 0x1d9f: jb     1ed9 <filter_32ty_range+0x1a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1ed9;
	}
x86_l_1da5:
	/* 0x1da5: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1da7:
	/* 0x1da7: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1daa:
	/* 0x1daa: jg     1edb <filter_32ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1edb;
	}
x86_l_1db0:
	/* 0x1db0: cmp    esi,DWORD PTR [rdi+0x2c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 44ULL);
x86_l_1db3:
	/* 0x1db3: jle    1e39 <filter_32ty_range+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1e39;
	}
x86_l_1db9:
	/* 0x1db9: jmp    1edb <filter_32ty_range+0x1a7> */
	goto x86_l_1edb;
x86_l_1dbe:
	/* 0x1dbe: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1dc1:
	/* 0x1dc1: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1dc4:
	/* 0x1dc4: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_1dc8:
	/* 0x1dc8: cmp    esi,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1dcb:
	/* 0x1dcb: setle  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_LE);
x86_l_1dce:
	/* 0x1dce: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1dd1:
	/* 0x1dd1: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1dd4:
	/* 0x1dd4: jb     1edb <filter_32ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1edb;
	}
x86_l_1dda:
	/* 0x1dda: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ddd:
	/* 0x1ddd: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_1de1:
	/* 0x1de1: cmp    esi,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1de4:
	/* 0x1de4: setle  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_LE);
x86_l_1de8:
	/* 0x1de8: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1deb:
	/* 0x1deb: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_1dee:
	/* 0x1dee: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1df1:
	/* 0x1df1: jb     1edb <filter_32ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1edb;
	}
x86_l_1df7:
	/* 0x1df7: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1dfa:
	/* 0x1dfa: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_1dfe:
	/* 0x1dfe: cmp    esi,DWORD PTR [rdi+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_1e01:
	/* 0x1e01: setle  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_LE);
x86_l_1e05:
	/* 0x1e05: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1e08:
	/* 0x1e08: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_1e0b:
	/* 0x1e0b: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_1e0e:
	/* 0x1e0e: jb     1edb <filter_32ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1edb;
	}
x86_l_1e14:
	/* 0x1e14: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1e17:
	/* 0x1e17: setle  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_LE);
x86_l_1e1a:
	/* 0x1e1a: cmp    esi,DWORD PTR [rdi+0x2c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 44ULL);
x86_l_1e1d:
	/* 0x1e1d: setle  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_LE);
x86_l_1e21:
	/* 0x1e21: jmp    1e95 <filter_32ty_range+0x161> */
	goto x86_l_1e95;
x86_l_1e23:
	/* 0x1e23: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e25:
	/* 0x1e25: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_1e28:
	/* 0x1e28: jne    1e3a <filter_32ty_range+0x106> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e3a;
	}
x86_l_1e2a:
	/* 0x1e2a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1e2f:
	/* 0x1e2f: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e32:
	/* 0x1e32: ja     1e9d <filter_32ty_range+0x169> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1e9d;
	}
x86_l_1e34:
	/* 0x1e34: cmp    esi,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1e37:
	/* 0x1e37: ja     1e9d <filter_32ty_range+0x169> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1e9d;
	}
x86_l_1e39:
	/* 0x1e39: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1e3a:
	/* 0x1e3a: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e3d:
	/* 0x1e3d: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e40:
	/* 0x1e40: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_1e44:
	/* 0x1e44: cmp    esi,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1e47:
	/* 0x1e47: setbe  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_BE);
x86_l_1e4a:
	/* 0x1e4a: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1e4d:
	/* 0x1e4d: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1e50:
	/* 0x1e50: jb     1edb <filter_32ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1edb;
	}
x86_l_1e56:
	/* 0x1e56: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1e59:
	/* 0x1e59: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_1e5d:
	/* 0x1e5d: cmp    esi,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1e60:
	/* 0x1e60: setbe  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_BE);
x86_l_1e64:
	/* 0x1e64: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1e67:
	/* 0x1e67: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_1e6a:
	/* 0x1e6a: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1e6d:
	/* 0x1e6d: jb     1edb <filter_32ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1edb;
	}
x86_l_1e6f:
	/* 0x1e6f: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e72:
	/* 0x1e72: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_1e76:
	/* 0x1e76: cmp    esi,DWORD PTR [rdi+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_1e79:
	/* 0x1e79: setbe  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_BE);
x86_l_1e7d:
	/* 0x1e7d: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1e80:
	/* 0x1e80: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_1e83:
	/* 0x1e83: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_1e86:
	/* 0x1e86: jb     1edb <filter_32ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1edb;
	}
x86_l_1e88:
	/* 0x1e88: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1e8b:
	/* 0x1e8b: setbe  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_BE);
x86_l_1e8e:
	/* 0x1e8e: cmp    esi,DWORD PTR [rdi+0x2c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 44ULL);
x86_l_1e91:
	/* 0x1e91: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_1e95:
	/* 0x1e95: and    sil,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_1e98:
	/* 0x1e98: or     dl,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_8, X86_ALU_OR);
x86_l_1e9b:
	/* 0x1e9b: jmp    1edb <filter_32ty_range+0x1a7> */
	goto x86_l_1edb;
x86_l_1e9d:
	/* 0x1e9d: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ea0:
	/* 0x1ea0: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1ea3:
	/* 0x1ea3: jb     1ed9 <filter_32ty_range+0x1a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1ed9;
	}
x86_l_1ea5:
	/* 0x1ea5: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ea8:
	/* 0x1ea8: ja     1eaf <filter_32ty_range+0x17b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1eaf;
	}
x86_l_1eaa:
	/* 0x1eaa: cmp    esi,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1ead:
	/* 0x1ead: jbe    1e39 <filter_32ty_range+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1e39;
	}
x86_l_1eaf:
	/* 0x1eaf: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_1eb2:
	/* 0x1eb2: jb     1ed9 <filter_32ty_range+0x1a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1ed9;
	}
x86_l_1eb4:
	/* 0x1eb4: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1eb7:
	/* 0x1eb7: ja     1ec2 <filter_32ty_range+0x18e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ec2;
	}
x86_l_1eb9:
	/* 0x1eb9: cmp    esi,DWORD PTR [rdi+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_1ebc:
	/* 0x1ebc: jbe    1e39 <filter_32ty_range+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1e39;
	}
x86_l_1ec2:
	/* 0x1ec2: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_1ec5:
	/* 0x1ec5: jb     1ed9 <filter_32ty_range+0x1a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1ed9;
	}
x86_l_1ec7:
	/* 0x1ec7: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ec9:
	/* 0x1ec9: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1ecc:
	/* 0x1ecc: ja     1edb <filter_32ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1edb;
	}
x86_l_1ece:
	/* 0x1ece: cmp    esi,DWORD PTR [rdi+0x2c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 44ULL);
x86_l_1ed1:
	/* 0x1ed1: jbe    1e39 <filter_32ty_range+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1e39;
	}
x86_l_1ed7:
	/* 0x1ed7: jmp    1edb <filter_32ty_range+0x1a7> */
	goto x86_l_1edb;
x86_l_1ed9:
	/* 0x1ed9: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1edb:
	/* 0x1edb: cmp    ecx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 32ULL);
x86_l_1ede:
	/* 0x1ede: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_1ee1:
	/* 0x1ee1: xor    dl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_1ee4:
	/* 0x1ee4: and    dl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_1ee6:
	/* 0x1ee6: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1ee9:
	/* 0x1ee9: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1eea:
	/* 0x1eea: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_1eec:
	/* 0x1eec: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_1eed:
	/* 0x1eed: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_1ef1:
	/* 0x1ef1: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_1ef4:
	/* 0x1ef4: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_1ef7:
	/* 0x1ef7: movzx  eax,BYTE PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1efb:
	/* 0x1efb: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1eff:
	/* 0x1eff: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f04:
	/* 0x1f04: mov    rdi,QWORD PTR [rip+0xe20] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_1f0b:
	/* 0x1f0b: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1f10:
	/* 0x1f10: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f12:
	/* 0x1f12: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f15:
	/* 0x1f15: je     1f4a <filter_32ty_map+0x60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f4a;
	}
x86_l_1f17:
	/* 0x1f17: mov    ecx,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f1a:
	/* 0x1f1a: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f1f:
	/* 0x1f1f: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1f24:
	/* 0x1f24: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f29:
	/* 0x1f29: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1f2c:
	/* 0x1f2c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1f2e:
	/* 0x1f2e: mov    edx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1f31:
	/* 0x1f31: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f33:
	/* 0x1f33: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_1f36:
	/* 0x1f36: ja     1f64 <filter_32ty_map+0x7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1f64;
	}
x86_l_1f38:
	/* 0x1f38: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_1f3d:
	/* 0x1f3d: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1f40:
	/* 0x1f40: jae    1f54 <filter_32ty_map+0x6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1f54;
	}
x86_l_1f42:
	/* 0x1f42: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f45:
	/* 0x1f45: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_1f48:
	/* 0x1f48: jmp    1f64 <filter_32ty_map+0x7a> */
	goto x86_l_1f64;
x86_l_1f4a:
	/* 0x1f4a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f4c:
	/* 0x1f4c: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1f50:
	/* 0x1f50: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1f51:
	/* 0x1f51: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_1f53:
	/* 0x1f53: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1f54:
	/* 0x1f54: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_1f59:
	/* 0x1f59: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1f5c:
	/* 0x1f5c: jae    1f64 <filter_32ty_map+0x7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1f64;
	}
x86_l_1f5e:
	/* 0x1f5e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f61:
	/* 0x1f61: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_1f64:
	/* 0x1f64: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1f67:
	/* 0x1f67: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1f6b:
	/* 0x1f6b: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1f6c:
	/* 0x1f6c: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_1f6e:
	/* 0x1f6e: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1f6f:
	/* 0x1f6f: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1f72:
	/* 0x1f72: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f77:
	/* 0x1f77: cmp    rcx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 37ULL);
x86_l_1f7b:
	/* 0x1f7b: ja     1fee <filter_8ty_selector_val+0x7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1fee;
	}
x86_l_1f7d:
	/* 0x1f7d: movabs rdx,0x200c000040 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280128ULL);
x86_l_1f87:
	/* 0x1f87: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1f8b:
	/* 0x1f8b: jae    1f8e <filter_8ty_selector_val+0x1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1f8e;
	}
x86_l_1f8d:
	/* 0x1f8d: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1f8e:
	/* 0x1f8e: mov    edx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 24ULL);
x86_l_1f93:
	/* 0x1f93: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1f97:
	/* 0x1f97: jae    1fae <filter_8ty_selector_val+0x3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1fae;
	}
x86_l_1f99:
	/* 0x1f99: movzx  edx,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1f9c:
	/* 0x1f9c: cmp    DWORD PTR [rdi+0x10],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f9f:
	/* 0x1f9f: jne    20c4 <filter_8ty_selector_val+0x155> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8388ULL;
	}
x86_l_1fa5:
	/* 0x1fa5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fa7:
	/* 0x1fa7: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1faa:
	/* 0x1faa: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_1fad:
	/* 0x1fad: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1fae:
	/* 0x1fae: cmp    rcx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 12ULL);
x86_l_1fb2:
	/* 0x1fb2: jne    1fee <filter_8ty_selector_val+0x7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1fee;
	}
x86_l_1fb4:
	/* 0x1fb4: movzx  ecx,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1fb7:
	/* 0x1fb7: test   DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fba:
	/* 0x1fba: jne    1f8d <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f8d;
	}
x86_l_1fbc:
	/* 0x1fbc: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1fbf:
	/* 0x1fbf: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1fc2:
	/* 0x1fc2: jb     2186 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8582ULL;
	}
x86_l_1fc8:
	/* 0x1fc8: test   DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1fcb:
	/* 0x1fcb: jne    1f8d <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f8d;
	}
x86_l_1fcd:
	/* 0x1fcd: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1fd0:
	/* 0x1fd0: jb     2186 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8582ULL;
	}
x86_l_1fd6:
	/* 0x1fd6: test   DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1fd9:
	/* 0x1fd9: jne    1f8d <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f8d;
	}
x86_l_1fdb:
	/* 0x1fdb: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_1fde:
	/* 0x1fde: jb     2186 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8582ULL;
	}
x86_l_1fe4:
	/* 0x1fe4: test   DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1fe7:
	/* 0x1fe7: jne    1f8d <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f8d;
	}
x86_l_1fe9:
	/* 0x1fe9: jmp    2186 <filter_8ty_selector_val+0x217> */
	return 8582ULL;
x86_l_1fee:
	/* 0x1fee: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1ff1:
	/* 0x1ff1: je     2060 <filter_8ty_selector_val+0xf1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2060;
	}
x86_l_1ff3:
	/* 0x1ff3: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1ff6:
	/* 0x1ff6: jne    2186 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8582ULL;
	}
x86_l_1ffc:
	/* 0x1ffc: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1fff:
	/* 0x1fff: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2002:
	/* 0x2002: ja     214d <filter_8ty_selector_val+0x1de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8525ULL;
	}
x86_l_2008:
	/* 0x2008: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_200d:
	/* 0x200d: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_2010:
	/* 0x2010: jae    214d <filter_8ty_selector_val+0x1de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8525ULL;
	}
x86_l_2016:
	/* 0x2016: movsx  ecx,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2019:
	/* 0x2019: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_201c:
	/* 0x201c: jg     1f8d <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1f8d;
	}
x86_l_2022:
	/* 0x2022: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2025:
	/* 0x2025: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_2028:
	/* 0x2028: jb     2186 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8582ULL;
	}
x86_l_202e:
	/* 0x202e: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2031:
	/* 0x2031: jg     1f8d <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1f8d;
	}
x86_l_2037:
	/* 0x2037: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_203a:
	/* 0x203a: jb     2186 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8582ULL;
	}
x86_l_2040:
	/* 0x2040: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2043:
	/* 0x2043: jg     1f8d <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1f8d;
	}
x86_l_2049:
	/* 0x2049: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_204c:
	/* 0x204c: jb     2186 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8582ULL;
	}
x86_l_2052:
	/* 0x2052: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2055:
	/* 0x2055: jg     1f8d <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1f8d;
	}
x86_l_205b:
	/* 0x205b: jmp    2186 <filter_8ty_selector_val+0x217> */
	return 8582ULL;
x86_l_2060:
	/* 0x2060: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2063:
	/* 0x2063: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2066:
	/* 0x2066: ja     2112 <filter_8ty_selector_val+0x1a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8466ULL;
	}
x86_l_206c:
	/* 0x206c: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_2071:
	/* 0x2071: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_2074:
	/* 0x2074: jae    2112 <filter_8ty_selector_val+0x1a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8466ULL;
	}
x86_l_207a:
	/* 0x207a: movsx  ecx,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
	return 8317ULL;
}

static __noinline __u64 tetragon_bpf_multi_usdt_v61_generic_usdt_filter_arg_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8317ULL: goto x86_l_207d;
	case 8320ULL: goto x86_l_2080;
	case 8326ULL: goto x86_l_2086;
	case 8329ULL: goto x86_l_2089;
	case 8332ULL: goto x86_l_208c;
	case 8338ULL: goto x86_l_2092;
	case 8341ULL: goto x86_l_2095;
	case 8347ULL: goto x86_l_209b;
	case 8350ULL: goto x86_l_209e;
	case 8356ULL: goto x86_l_20a4;
	case 8359ULL: goto x86_l_20a7;
	case 8365ULL: goto x86_l_20ad;
	case 8368ULL: goto x86_l_20b0;
	case 8374ULL: goto x86_l_20b6;
	case 8377ULL: goto x86_l_20b9;
	case 8383ULL: goto x86_l_20bf;
	case 8388ULL: goto x86_l_20c4;
	case 8391ULL: goto x86_l_20c7;
	case 8394ULL: goto x86_l_20ca;
	case 8396ULL: goto x86_l_20cc;
	case 8399ULL: goto x86_l_20cf;
	case 8405ULL: goto x86_l_20d5;
	case 8408ULL: goto x86_l_20d8;
	case 8410ULL: goto x86_l_20da;
	case 8413ULL: goto x86_l_20dd;
	case 8419ULL: goto x86_l_20e3;
	case 8422ULL: goto x86_l_20e6;
	case 8424ULL: goto x86_l_20e8;
	case 8427ULL: goto x86_l_20eb;
	case 8433ULL: goto x86_l_20f1;
	case 8436ULL: goto x86_l_20f4;
	case 8442ULL: goto x86_l_20fa;
	case 8444ULL: goto x86_l_20fc;
	case 8454ULL: goto x86_l_2106;
	case 8458ULL: goto x86_l_210a;
	case 8464ULL: goto x86_l_2110;
	case 8466ULL: goto x86_l_2112;
	case 8469ULL: goto x86_l_2115;
	case 8472ULL: goto x86_l_2118;
	case 8478ULL: goto x86_l_211e;
	case 8481ULL: goto x86_l_2121;
	case 8484ULL: goto x86_l_2124;
	case 8486ULL: goto x86_l_2126;
	case 8489ULL: goto x86_l_2129;
	case 8495ULL: goto x86_l_212f;
	case 8498ULL: goto x86_l_2132;
	case 8500ULL: goto x86_l_2134;
	case 8503ULL: goto x86_l_2137;
	case 8509ULL: goto x86_l_213d;
	case 8512ULL: goto x86_l_2140;
	case 8514ULL: goto x86_l_2142;
	case 8517ULL: goto x86_l_2145;
	case 8523ULL: goto x86_l_214b;
	case 8525ULL: goto x86_l_214d;
	case 8528ULL: goto x86_l_2150;
	case 8531ULL: goto x86_l_2153;
	case 8537ULL: goto x86_l_2159;
	case 8540ULL: goto x86_l_215c;
	case 8543ULL: goto x86_l_215f;
	case 8545ULL: goto x86_l_2161;
	case 8548ULL: goto x86_l_2164;
	case 8554ULL: goto x86_l_216a;
	case 8557ULL: goto x86_l_216d;
	case 8559ULL: goto x86_l_216f;
	case 8562ULL: goto x86_l_2172;
	case 8568ULL: goto x86_l_2178;
	case 8571ULL: goto x86_l_217b;
	case 8573ULL: goto x86_l_217d;
	case 8576ULL: goto x86_l_2180;
	case 8582ULL: goto x86_l_2186;
	case 8584ULL: goto x86_l_2188;
	case 8585ULL: goto x86_l_2189;
	case 8588ULL: goto x86_l_218c;
	case 8591ULL: goto x86_l_218f;
	case 8594ULL: goto x86_l_2192;
	case 8600ULL: goto x86_l_2198;
	case 8605ULL: goto x86_l_219d;
	case 8608ULL: goto x86_l_21a0;
	case 8614ULL: goto x86_l_21a6;
	case 8617ULL: goto x86_l_21a9;
	case 8620ULL: goto x86_l_21ac;
	case 8622ULL: goto x86_l_21ae;
	case 8627ULL: goto x86_l_21b3;
	case 8630ULL: goto x86_l_21b6;
	case 8632ULL: goto x86_l_21b8;
	case 8635ULL: goto x86_l_21bb;
	case 8641ULL: goto x86_l_21c1;
	case 8644ULL: goto x86_l_21c4;
	case 8647ULL: goto x86_l_21c7;
	case 8653ULL: goto x86_l_21cd;
	case 8656ULL: goto x86_l_21d0;
	case 8658ULL: goto x86_l_21d2;
	case 8661ULL: goto x86_l_21d5;
	case 8667ULL: goto x86_l_21db;
	case 8670ULL: goto x86_l_21de;
	case 8676ULL: goto x86_l_21e4;
	case 8679ULL: goto x86_l_21e7;
	case 8681ULL: goto x86_l_21e9;
	case 8684ULL: goto x86_l_21ec;
	case 8690ULL: goto x86_l_21f2;
	case 8693ULL: goto x86_l_21f5;
	case 8699ULL: goto x86_l_21fb;
	case 8701ULL: goto x86_l_21fd;
	case 8704ULL: goto x86_l_2200;
	case 8710ULL: goto x86_l_2206;
	case 8713ULL: goto x86_l_2209;
	case 8719ULL: goto x86_l_220f;
	case 8724ULL: goto x86_l_2214;
	case 8727ULL: goto x86_l_2217;
	case 8730ULL: goto x86_l_221a;
	case 8734ULL: goto x86_l_221e;
	case 8737ULL: goto x86_l_2221;
	case 8740ULL: goto x86_l_2224;
	case 8743ULL: goto x86_l_2227;
	case 8746ULL: goto x86_l_222a;
	case 8752ULL: goto x86_l_2230;
	case 8755ULL: goto x86_l_2233;
	case 8759ULL: goto x86_l_2237;
	case 8762ULL: goto x86_l_223a;
	case 8766ULL: goto x86_l_223e;
	case 8769ULL: goto x86_l_2241;
	case 8772ULL: goto x86_l_2244;
	case 8775ULL: goto x86_l_2247;
	case 8781ULL: goto x86_l_224d;
	case 8784ULL: goto x86_l_2250;
	case 8788ULL: goto x86_l_2254;
	case 8791ULL: goto x86_l_2257;
	case 8795ULL: goto x86_l_225b;
	case 8798ULL: goto x86_l_225e;
	case 8801ULL: goto x86_l_2261;
	case 8804ULL: goto x86_l_2264;
	case 8810ULL: goto x86_l_226a;
	case 8813ULL: goto x86_l_226d;
	case 8816ULL: goto x86_l_2270;
	case 8819ULL: goto x86_l_2273;
	case 8823ULL: goto x86_l_2277;
	case 8825ULL: goto x86_l_2279;
	case 8828ULL: goto x86_l_227c;
	case 8831ULL: goto x86_l_227f;
	case 8833ULL: goto x86_l_2281;
	case 8838ULL: goto x86_l_2286;
	case 8841ULL: goto x86_l_2289;
	case 8843ULL: goto x86_l_228b;
	case 8846ULL: goto x86_l_228e;
	case 8848ULL: goto x86_l_2290;
	case 8849ULL: goto x86_l_2291;
	case 8852ULL: goto x86_l_2294;
	case 8855ULL: goto x86_l_2297;
	case 8859ULL: goto x86_l_229b;
	case 8862ULL: goto x86_l_229e;
	case 8865ULL: goto x86_l_22a1;
	case 8868ULL: goto x86_l_22a4;
	case 8871ULL: goto x86_l_22a7;
	case 8877ULL: goto x86_l_22ad;
	case 8880ULL: goto x86_l_22b0;
	case 8884ULL: goto x86_l_22b4;
	case 8887ULL: goto x86_l_22b7;
	case 8891ULL: goto x86_l_22bb;
	case 8894ULL: goto x86_l_22be;
	case 8897ULL: goto x86_l_22c1;
	case 8900ULL: goto x86_l_22c4;
	case 8902ULL: goto x86_l_22c6;
	case 8905ULL: goto x86_l_22c9;
	case 8909ULL: goto x86_l_22cd;
	case 8912ULL: goto x86_l_22d0;
	case 8916ULL: goto x86_l_22d4;
	case 8919ULL: goto x86_l_22d7;
	case 8922ULL: goto x86_l_22da;
	case 8925ULL: goto x86_l_22dd;
	case 8927ULL: goto x86_l_22df;
	case 8930ULL: goto x86_l_22e2;
	case 8933ULL: goto x86_l_22e5;
	case 8936ULL: goto x86_l_22e8;
	case 8940ULL: goto x86_l_22ec;
	case 8943ULL: goto x86_l_22ef;
	case 8946ULL: goto x86_l_22f2;
	case 8948ULL: goto x86_l_22f4;
	case 8951ULL: goto x86_l_22f7;
	case 8954ULL: goto x86_l_22fa;
	case 8956ULL: goto x86_l_22fc;
	case 8959ULL: goto x86_l_22ff;
	case 8961ULL: goto x86_l_2301;
	case 8964ULL: goto x86_l_2304;
	case 8966ULL: goto x86_l_2306;
	case 8969ULL: goto x86_l_2309;
	case 8971ULL: goto x86_l_230b;
	case 8974ULL: goto x86_l_230e;
	case 8976ULL: goto x86_l_2310;
	case 8979ULL: goto x86_l_2313;
	case 8985ULL: goto x86_l_2319;
	case 8988ULL: goto x86_l_231c;
	case 8990ULL: goto x86_l_231e;
	case 8992ULL: goto x86_l_2320;
	case 8995ULL: goto x86_l_2323;
	case 8997ULL: goto x86_l_2325;
	case 9000ULL: goto x86_l_2328;
	case 9006ULL: goto x86_l_232e;
	case 9008ULL: goto x86_l_2330;
	case 9010ULL: goto x86_l_2332;
	case 9013ULL: goto x86_l_2335;
	case 9016ULL: goto x86_l_2338;
	case 9019ULL: goto x86_l_233b;
	case 9021ULL: goto x86_l_233d;
	case 9024ULL: goto x86_l_2340;
	case 9025ULL: goto x86_l_2341;
	case 9027ULL: goto x86_l_2343;
	case 9028ULL: goto x86_l_2344;
	case 9032ULL: goto x86_l_2348;
	case 9035ULL: goto x86_l_234b;
	case 9038ULL: goto x86_l_234e;
	case 9042ULL: goto x86_l_2352;
	case 9046ULL: goto x86_l_2356;
	case 9051ULL: goto x86_l_235b;
	case 9058ULL: goto x86_l_2362;
	case 9063ULL: goto x86_l_2367;
	case 9065ULL: goto x86_l_2369;
	case 9068ULL: goto x86_l_236c;
	case 9070ULL: goto x86_l_236e;
	case 9074ULL: goto x86_l_2372;
	case 9079ULL: goto x86_l_2377;
	case 9084ULL: goto x86_l_237c;
	case 9089ULL: goto x86_l_2381;
	case 9092ULL: goto x86_l_2384;
	case 9094ULL: goto x86_l_2386;
	case 9097ULL: goto x86_l_2389;
	case 9099ULL: goto x86_l_238b;
	case 9102ULL: goto x86_l_238e;
	case 9104ULL: goto x86_l_2390;
	case 9109ULL: goto x86_l_2395;
	case 9112ULL: goto x86_l_2398;
	case 9114ULL: goto x86_l_239a;
	case 9117ULL: goto x86_l_239d;
	case 9120ULL: goto x86_l_23a0;
	case 9122ULL: goto x86_l_23a2;
	case 9124ULL: goto x86_l_23a4;
	case 9128ULL: goto x86_l_23a8;
	case 9129ULL: goto x86_l_23a9;
	case 9131ULL: goto x86_l_23ab;
	case 9132ULL: goto x86_l_23ac;
	case 9137ULL: goto x86_l_23b1;
	case 9140ULL: goto x86_l_23b4;
	case 9142ULL: goto x86_l_23b6;
	case 9145ULL: goto x86_l_23b9;
	case 9148ULL: goto x86_l_23bc;
	case 9151ULL: goto x86_l_23bf;
	case 9155ULL: goto x86_l_23c3;
	case 9156ULL: goto x86_l_23c4;
	case 9158ULL: goto x86_l_23c6;
	case 9159ULL: goto x86_l_23c7;
	case 9160ULL: goto x86_l_23c8;
	case 9164ULL: goto x86_l_23cc;
	case 9171ULL: goto x86_l_23d3;
	case 9177ULL: goto x86_l_23d9;
	case 9179ULL: goto x86_l_23db;
	case 9182ULL: goto x86_l_23de;
	case 9187ULL: goto x86_l_23e3;
	case 9189ULL: goto x86_l_23e5;
	case 9193ULL: goto x86_l_23e9;
	case 9197ULL: goto x86_l_23ed;
	case 9202ULL: goto x86_l_23f2;
	case 9207ULL: goto x86_l_23f7;
	case 9209ULL: goto x86_l_23f9;
	case 9212ULL: goto x86_l_23fc;
	case 9214ULL: goto x86_l_23fe;
	case 9216ULL: goto x86_l_2400;
	case 9221ULL: goto x86_l_2405;
	case 9227ULL: goto x86_l_240b;
	case 9232ULL: goto x86_l_2410;
	case 9234ULL: goto x86_l_2412;
	case 9236ULL: goto x86_l_2414;
	case 9239ULL: goto x86_l_2417;
	case 9242ULL: goto x86_l_241a;
	case 9244ULL: goto x86_l_241c;
	case 9247ULL: goto x86_l_241f;
	case 9249ULL: goto x86_l_2421;
	case 9251ULL: goto x86_l_2423;
	case 9253ULL: goto x86_l_2425;
	case 9255ULL: goto x86_l_2427;
	case 9258ULL: goto x86_l_242a;
	case 9260ULL: goto x86_l_242c;
	case 9263ULL: goto x86_l_242f;
	case 9265ULL: goto x86_l_2431;
	case 9267ULL: goto x86_l_2433;
	case 9269ULL: goto x86_l_2435;
	case 9271ULL: goto x86_l_2437;
	case 9274ULL: goto x86_l_243a;
	case 9276ULL: goto x86_l_243c;
	case 9279ULL: goto x86_l_243f;
	case 9281ULL: goto x86_l_2441;
	case 9283ULL: goto x86_l_2443;
	case 9285ULL: goto x86_l_2445;
	case 9287ULL: goto x86_l_2447;
	case 9290ULL: goto x86_l_244a;
	case 9294ULL: goto x86_l_244e;
	case 9295ULL: goto x86_l_244f;
	case 9296ULL: goto x86_l_2450;
	case 9298ULL: goto x86_l_2452;
	case 9302ULL: goto x86_l_2456;
	case 9303ULL: goto x86_l_2457;
	default: return 0xffffffffffffffffULL;
	}
x86_l_207d:
	/* 0x207d: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2080:
	/* 0x2080: jl     1f8d <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 8077ULL;
	}
x86_l_2086:
	/* 0x2086: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2089:
	/* 0x2089: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_208c:
	/* 0x208c: jb     2186 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2186;
	}
x86_l_2092:
	/* 0x2092: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2095:
	/* 0x2095: jl     1f8d <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 8077ULL;
	}
x86_l_209b:
	/* 0x209b: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_209e:
	/* 0x209e: jb     2186 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2186;
	}
x86_l_20a4:
	/* 0x20a4: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_20a7:
	/* 0x20a7: jl     1f8d <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 8077ULL;
	}
x86_l_20ad:
	/* 0x20ad: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_20b0:
	/* 0x20b0: jb     2186 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2186;
	}
x86_l_20b6:
	/* 0x20b6: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_20b9:
	/* 0x20b9: jl     1f8d <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 8077ULL;
	}
x86_l_20bf:
	/* 0x20bf: jmp    2186 <filter_8ty_selector_val+0x217> */
	goto x86_l_2186;
x86_l_20c4:
	/* 0x20c4: mov    esi,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20c7:
	/* 0x20c7: cmp    esi,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 13ULL);
x86_l_20ca:
	/* 0x20ca: jb     20f1 <filter_8ty_selector_val+0x182> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_20f1;
	}
x86_l_20cc:
	/* 0x20cc: cmp    DWORD PTR [rdi+0x14],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_20cf:
	/* 0x20cf: je     1fa5 <filter_8ty_selector_val+0x36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8101ULL;
	}
x86_l_20d5:
	/* 0x20d5: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_20d8:
	/* 0x20d8: jb     20f1 <filter_8ty_selector_val+0x182> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_20f1;
	}
x86_l_20da:
	/* 0x20da: cmp    DWORD PTR [rdi+0x18],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_20dd:
	/* 0x20dd: je     1fa5 <filter_8ty_selector_val+0x36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8101ULL;
	}
x86_l_20e3:
	/* 0x20e3: cmp    esi,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 21ULL);
x86_l_20e6:
	/* 0x20e6: jb     20f1 <filter_8ty_selector_val+0x182> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_20f1;
	}
x86_l_20e8:
	/* 0x20e8: cmp    DWORD PTR [rdi+0x1c],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_20eb:
	/* 0x20eb: je     1fa5 <filter_8ty_selector_val+0x36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8101ULL;
	}
x86_l_20f1:
	/* 0x20f1: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_20f4:
	/* 0x20f4: ja     2186 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2186;
	}
x86_l_20fa:
	/* 0x20fa: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_20fc:
	/* 0x20fc: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_2106:
	/* 0x2106: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_210a:
	/* 0x210a: jb     1f8d <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8077ULL;
	}
x86_l_2110:
	/* 0x2110: jmp    2186 <filter_8ty_selector_val+0x217> */
	goto x86_l_2186;
x86_l_2112:
	/* 0x2112: movzx  ecx,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2115:
	/* 0x2115: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2118:
	/* 0x2118: jb     1f8d <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8077ULL;
	}
x86_l_211e:
	/* 0x211e: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2121:
	/* 0x2121: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_2124:
	/* 0x2124: jb     2186 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2186;
	}
x86_l_2126:
	/* 0x2126: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2129:
	/* 0x2129: jb     1f8d <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8077ULL;
	}
x86_l_212f:
	/* 0x212f: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_2132:
	/* 0x2132: jb     2186 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2186;
	}
x86_l_2134:
	/* 0x2134: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2137:
	/* 0x2137: jb     1f8d <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8077ULL;
	}
x86_l_213d:
	/* 0x213d: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_2140:
	/* 0x2140: jb     2186 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2186;
	}
x86_l_2142:
	/* 0x2142: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2145:
	/* 0x2145: jb     1f8d <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8077ULL;
	}
x86_l_214b:
	/* 0x214b: jmp    2186 <filter_8ty_selector_val+0x217> */
	goto x86_l_2186;
x86_l_214d:
	/* 0x214d: movzx  ecx,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2150:
	/* 0x2150: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2153:
	/* 0x2153: ja     1f8d <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8077ULL;
	}
x86_l_2159:
	/* 0x2159: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_215c:
	/* 0x215c: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_215f:
	/* 0x215f: jb     2186 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2186;
	}
x86_l_2161:
	/* 0x2161: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2164:
	/* 0x2164: ja     1f8d <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8077ULL;
	}
x86_l_216a:
	/* 0x216a: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_216d:
	/* 0x216d: jb     2186 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2186;
	}
x86_l_216f:
	/* 0x216f: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2172:
	/* 0x2172: ja     1f8d <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8077ULL;
	}
x86_l_2178:
	/* 0x2178: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_217b:
	/* 0x217b: jb     2186 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2186;
	}
x86_l_217d:
	/* 0x217d: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2180:
	/* 0x2180: ja     1f8d <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8077ULL;
	}
x86_l_2186:
	/* 0x2186: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2188:
	/* 0x2188: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_2189:
	/* 0x2189: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_218c:
	/* 0x218c: mov    eax,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_218f:
	/* 0x218f: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2192:
	/* 0x2192: ja     2279 <filter_8ty_range+0xf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2279;
	}
x86_l_2198:
	/* 0x2198: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_219d:
	/* 0x219d: bt     edx,eax */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_21a0:
	/* 0x21a0: jae    2279 <filter_8ty_range+0xf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2279;
	}
x86_l_21a6:
	/* 0x21a6: movsx  esi,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_21a9:
	/* 0x21a9: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_21ac:
	/* 0x21ac: jne    2214 <filter_8ty_range+0x8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2214;
	}
x86_l_21ae:
	/* 0x21ae: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_21b3:
	/* 0x21b3: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21b6:
	/* 0x21b6: jg     21c1 <filter_8ty_range+0x38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_21c1;
	}
x86_l_21b8:
	/* 0x21b8: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_21bb:
	/* 0x21bb: jge    2290 <filter_8ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_GE)) {
		goto x86_l_2290;
	}
x86_l_21c1:
	/* 0x21c1: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21c4:
	/* 0x21c4: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_21c7:
	/* 0x21c7: jb     2330 <filter_8ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2330;
	}
x86_l_21cd:
	/* 0x21cd: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_21d0:
	/* 0x21d0: jg     21db <filter_8ty_range+0x52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_21db;
	}
x86_l_21d2:
	/* 0x21d2: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_21d5:
	/* 0x21d5: jge    2290 <filter_8ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_GE)) {
		goto x86_l_2290;
	}
x86_l_21db:
	/* 0x21db: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_21de:
	/* 0x21de: jb     2330 <filter_8ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2330;
	}
x86_l_21e4:
	/* 0x21e4: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_21e7:
	/* 0x21e7: jg     21f2 <filter_8ty_range+0x69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_21f2;
	}
x86_l_21e9:
	/* 0x21e9: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_21ec:
	/* 0x21ec: jge    2290 <filter_8ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_GE)) {
		goto x86_l_2290;
	}
x86_l_21f2:
	/* 0x21f2: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_21f5:
	/* 0x21f5: jb     2330 <filter_8ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2330;
	}
x86_l_21fb:
	/* 0x21fb: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_21fd:
	/* 0x21fd: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2200:
	/* 0x2200: jg     2332 <filter_8ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2332;
	}
x86_l_2206:
	/* 0x2206: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2209:
	/* 0x2209: jge    2290 <filter_8ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_GE)) {
		goto x86_l_2290;
	}
x86_l_220f:
	/* 0x220f: jmp    2332 <filter_8ty_range+0x1a9> */
	goto x86_l_2332;
x86_l_2214:
	/* 0x2214: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2217:
	/* 0x2217: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_221a:
	/* 0x221a: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_221e:
	/* 0x221e: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2221:
	/* 0x2221: setge  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_GE);
x86_l_2224:
	/* 0x2224: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_2227:
	/* 0x2227: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_222a:
	/* 0x222a: jb     2332 <filter_8ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2332;
	}
x86_l_2230:
	/* 0x2230: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2233:
	/* 0x2233: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_2237:
	/* 0x2237: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_223a:
	/* 0x223a: setge  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_GE);
x86_l_223e:
	/* 0x223e: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_2241:
	/* 0x2241: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_2244:
	/* 0x2244: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_2247:
	/* 0x2247: jb     2332 <filter_8ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2332;
	}
x86_l_224d:
	/* 0x224d: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2250:
	/* 0x2250: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_2254:
	/* 0x2254: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2257:
	/* 0x2257: setge  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_GE);
x86_l_225b:
	/* 0x225b: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_225e:
	/* 0x225e: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_2261:
	/* 0x2261: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_2264:
	/* 0x2264: jb     2332 <filter_8ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2332;
	}
x86_l_226a:
	/* 0x226a: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_226d:
	/* 0x226d: setle  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_LE);
x86_l_2270:
	/* 0x2270: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2273:
	/* 0x2273: setge  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_GE);
x86_l_2277:
	/* 0x2277: jmp    22ec <filter_8ty_range+0x163> */
	goto x86_l_22ec;
x86_l_2279:
	/* 0x2279: movzx  esi,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_227c:
	/* 0x227c: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_227f:
	/* 0x227f: jne    2291 <filter_8ty_range+0x108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2291;
	}
x86_l_2281:
	/* 0x2281: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2286:
	/* 0x2286: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2289:
	/* 0x2289: ja     22f4 <filter_8ty_range+0x16b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_22f4;
	}
x86_l_228b:
	/* 0x228b: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_228e:
	/* 0x228e: jb     22f4 <filter_8ty_range+0x16b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_22f4;
	}
x86_l_2290:
	/* 0x2290: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_2291:
	/* 0x2291: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2294:
	/* 0x2294: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2297:
	/* 0x2297: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_229b:
	/* 0x229b: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_229e:
	/* 0x229e: setae  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_AE);
x86_l_22a1:
	/* 0x22a1: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_22a4:
	/* 0x22a4: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_22a7:
	/* 0x22a7: jb     2332 <filter_8ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2332;
	}
x86_l_22ad:
	/* 0x22ad: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_22b0:
	/* 0x22b0: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_22b4:
	/* 0x22b4: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_22b7:
	/* 0x22b7: setae  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_AE);
x86_l_22bb:
	/* 0x22bb: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_22be:
	/* 0x22be: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_22c1:
	/* 0x22c1: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_22c4:
	/* 0x22c4: jb     2332 <filter_8ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2332;
	}
x86_l_22c6:
	/* 0x22c6: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_22c9:
	/* 0x22c9: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_22cd:
	/* 0x22cd: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_22d0:
	/* 0x22d0: setae  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_AE);
x86_l_22d4:
	/* 0x22d4: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_22d7:
	/* 0x22d7: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_22da:
	/* 0x22da: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_22dd:
	/* 0x22dd: jb     2332 <filter_8ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2332;
	}
x86_l_22df:
	/* 0x22df: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_22e2:
	/* 0x22e2: setbe  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_BE);
x86_l_22e5:
	/* 0x22e5: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_22e8:
	/* 0x22e8: setae  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_AE);
x86_l_22ec:
	/* 0x22ec: and    sil,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_22ef:
	/* 0x22ef: or     dl,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_8, X86_ALU_OR);
x86_l_22f2:
	/* 0x22f2: jmp    2332 <filter_8ty_range+0x1a9> */
	goto x86_l_2332;
x86_l_22f4:
	/* 0x22f4: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22f7:
	/* 0x22f7: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_22fa:
	/* 0x22fa: jb     2330 <filter_8ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2330;
	}
x86_l_22fc:
	/* 0x22fc: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_22ff:
	/* 0x22ff: ja     2306 <filter_8ty_range+0x17d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2306;
	}
x86_l_2301:
	/* 0x2301: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2304:
	/* 0x2304: jae    2290 <filter_8ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2290;
	}
x86_l_2306:
	/* 0x2306: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_2309:
	/* 0x2309: jb     2330 <filter_8ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2330;
	}
x86_l_230b:
	/* 0x230b: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_230e:
	/* 0x230e: ja     2319 <filter_8ty_range+0x190> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2319;
	}
x86_l_2310:
	/* 0x2310: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2313:
	/* 0x2313: jae    2290 <filter_8ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2290;
	}
x86_l_2319:
	/* 0x2319: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_231c:
	/* 0x231c: jb     2330 <filter_8ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2330;
	}
x86_l_231e:
	/* 0x231e: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2320:
	/* 0x2320: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2323:
	/* 0x2323: ja     2332 <filter_8ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2332;
	}
x86_l_2325:
	/* 0x2325: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2328:
	/* 0x2328: jae    2290 <filter_8ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2290;
	}
x86_l_232e:
	/* 0x232e: jmp    2332 <filter_8ty_range+0x1a9> */
	goto x86_l_2332;
x86_l_2330:
	/* 0x2330: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2332:
	/* 0x2332: cmp    ecx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 32ULL);
x86_l_2335:
	/* 0x2335: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_2338:
	/* 0x2338: xor    dl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_233b:
	/* 0x233b: and    dl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_233d:
	/* 0x233d: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2340:
	/* 0x2340: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_2341:
	/* 0x2341: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_2343:
	/* 0x2343: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_2344:
	/* 0x2344: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_2348:
	/* 0x2348: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_234b:
	/* 0x234b: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_234e:
	/* 0x234e: movzx  eax,BYTE PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_2352:
	/* 0x2352: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2356:
	/* 0x2356: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_235b:
	/* 0x235b: mov    rdi,QWORD PTR [rip+0x1700] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_2362:
	/* 0x2362: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2367:
	/* 0x2367: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2369:
	/* 0x2369: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_236c:
	/* 0x236c: je     23a2 <filter_8ty_map+0x61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23a2;
	}
x86_l_236e:
	/* 0x236e: movzx  ecx,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2372:
	/* 0x2372: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2377:
	/* 0x2377: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_237c:
	/* 0x237c: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2381:
	/* 0x2381: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2384:
	/* 0x2384: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2386:
	/* 0x2386: mov    edx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2389:
	/* 0x2389: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_238b:
	/* 0x238b: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_238e:
	/* 0x238e: ja     23bc <filter_8ty_map+0x7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_23bc;
	}
x86_l_2390:
	/* 0x2390: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_2395:
	/* 0x2395: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_2398:
	/* 0x2398: jae    23ac <filter_8ty_map+0x6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_23ac;
	}
x86_l_239a:
	/* 0x239a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_239d:
	/* 0x239d: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_23a0:
	/* 0x23a0: jmp    23bc <filter_8ty_map+0x7b> */
	goto x86_l_23bc;
x86_l_23a2:
	/* 0x23a2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_23a4:
	/* 0x23a4: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_23a8:
	/* 0x23a8: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_23a9:
	/* 0x23a9: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_23ab:
	/* 0x23ab: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_23ac:
	/* 0x23ac: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_23b1:
	/* 0x23b1: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_23b4:
	/* 0x23b4: jae    23bc <filter_8ty_map+0x7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_23bc;
	}
x86_l_23b6:
	/* 0x23b6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_23b9:
	/* 0x23b9: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_23bc:
	/* 0x23bc: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_23bf:
	/* 0x23bf: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_23c3:
	/* 0x23c3: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_23c4:
	/* 0x23c4: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_23c6:
	/* 0x23c6: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_23c7:
	/* 0x23c7: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_23c8:
	/* 0x23c8: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_23cc:
	/* 0x23cc: mov    WORD PTR [rsp+0xe],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 60129542144ULL);
x86_l_23d3:
	/* 0x23d3: cmp    DWORD PTR [rsi],0x1000 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4096ULL);
x86_l_23d9:
	/* 0x23d9: ja     2450 <filter_file_type+0x89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2450;
	}
x86_l_23db:
	/* 0x23db: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_23de:
	/* 0x23de: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23e3:
	/* 0x23e3: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23e5:
	/* 0x23e5: lea    rdx,[rsi+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_23e9:
	/* 0x23e9: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_23ed:
	/* 0x23ed: lea    rdi,[rsp+0xe] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_23f2:
	/* 0x23f2: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_23f7:
	/* 0x23f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23f9:
	/* 0x23f9: mov    edx,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23fc:
	/* 0x23fc: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_23fe:
	/* 0x23fe: je     2450 <filter_file_type+0x89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2450;
	}
x86_l_2400:
	/* 0x2400: movzx  ecx,WORD PTR [rsp+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_2405:
	/* 0x2405: and    ecx,0xf000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 61440ULL);
x86_l_240b:
	/* 0x240b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2410:
	/* 0x2410: cmp    edx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_2412:
	/* 0x2412: je     2452 <filter_file_type+0x8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2452;
	}
x86_l_2414:
	/* 0x2414: mov    edx,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2417:
	/* 0x2417: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_241a:
	/* 0x241a: jbe    2450 <filter_file_type+0x89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2450;
	}
x86_l_241c:
	/* 0x241c: mov    esi,DWORD PTR [rbx+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_241f:
	/* 0x241f: test   esi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_32);
x86_l_2421:
	/* 0x2421: je     2450 <filter_file_type+0x89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2450;
	}
x86_l_2423:
	/* 0x2423: cmp    esi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_2425:
	/* 0x2425: je     2452 <filter_file_type+0x8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2452;
	}
x86_l_2427:
	/* 0x2427: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_242a:
	/* 0x242a: jb     2450 <filter_file_type+0x89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2450;
	}
x86_l_242c:
	/* 0x242c: mov    esi,DWORD PTR [rbx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_242f:
	/* 0x242f: test   esi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_32);
x86_l_2431:
	/* 0x2431: je     2450 <filter_file_type+0x89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2450;
	}
x86_l_2433:
	/* 0x2433: cmp    esi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_2435:
	/* 0x2435: je     2452 <filter_file_type+0x8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2452;
	}
x86_l_2437:
	/* 0x2437: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_243a:
	/* 0x243a: jb     2450 <filter_file_type+0x89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2450;
	}
x86_l_243c:
	/* 0x243c: mov    edx,DWORD PTR [rbx+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_243f:
	/* 0x243f: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_2441:
	/* 0x2441: je     2450 <filter_file_type+0x89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2450;
	}
x86_l_2443:
	/* 0x2443: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2445:
	/* 0x2445: cmp    edx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_2447:
	/* 0x2447: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_244a:
	/* 0x244a: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_244e:
	/* 0x244e: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_244f:
	/* 0x244f: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_2450:
	/* 0x2450: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2452:
	/* 0x2452: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2456:
	/* 0x2456: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_2457:
	/* 0x2457: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_multi_usdt_v61_generic_usdt_filter_arg_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 10412U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1543ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v61_generic_usdt_filter_arg_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1546ULL && __x86_pc <= 2829ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v61_generic_usdt_filter_arg_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 2830ULL && __x86_pc <= 4251ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v61_generic_usdt_filter_arg_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 4255ULL && __x86_pc <= 5620ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v61_generic_usdt_filter_arg_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 5624ULL && __x86_pc <= 6968ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v61_generic_usdt_filter_arg_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 6972ULL && __x86_pc <= 8314ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v61_generic_usdt_filter_arg_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 8317ULL && __x86_pc <= 9303ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v61_generic_usdt_filter_arg_x86_chunk_6(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

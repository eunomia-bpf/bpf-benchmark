extern char addr4lpm_maps;
extern char addr6lpm_maps;
extern char argfilter_maps;
extern char filter_map;
extern char heap_ro_zero;
extern char process_call_heap;
extern char retprobe_map;
extern char retuprobe_calls;
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

static __noinline __u64 tetragon_bpf_generic_retuprobe_v61_generic_retuprobe_filter_arg_x86_chunk_0(
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
	case 14ULL: goto x86_l_e;
	case 17ULL: goto x86_l_11;
	case 25ULL: goto x86_l_19;
	case 32ULL: goto x86_l_20;
	case 37ULL: goto x86_l_25;
	case 42ULL: goto x86_l_2a;
	case 44ULL: goto x86_l_2c;
	case 47ULL: goto x86_l_2f;
	case 53ULL: goto x86_l_35;
	case 56ULL: goto x86_l_38;
	case 63ULL: goto x86_l_3f;
	case 70ULL: goto x86_l_46;
	case 77ULL: goto x86_l_4d;
	case 82ULL: goto x86_l_52;
	case 84ULL: goto x86_l_54;
	case 87ULL: goto x86_l_57;
	case 93ULL: goto x86_l_5d;
	case 101ULL: goto x86_l_65;
	case 107ULL: goto x86_l_6b;
	case 110ULL: goto x86_l_6e;
	case 113ULL: goto x86_l_71;
	case 116ULL: goto x86_l_74;
	case 125ULL: goto x86_l_7d;
	case 127ULL: goto x86_l_7f;
	case 129ULL: goto x86_l_81;
	case 134ULL: goto x86_l_86;
	case 138ULL: goto x86_l_8a;
	case 142ULL: goto x86_l_8e;
	case 145ULL: goto x86_l_91;
	case 150ULL: goto x86_l_96;
	case 157ULL: goto x86_l_9d;
	case 162ULL: goto x86_l_a2;
	case 164ULL: goto x86_l_a4;
	case 168ULL: goto x86_l_a8;
	case 174ULL: goto x86_l_ae;
	case 177ULL: goto x86_l_b1;
	case 183ULL: goto x86_l_b7;
	case 187ULL: goto x86_l_bb;
	case 189ULL: goto x86_l_bd;
	case 193ULL: goto x86_l_c1;
	case 199ULL: goto x86_l_c7;
	case 202ULL: goto x86_l_ca;
	case 208ULL: goto x86_l_d0;
	case 212ULL: goto x86_l_d4;
	case 218ULL: goto x86_l_da;
	case 220ULL: goto x86_l_dc;
	case 224ULL: goto x86_l_e0;
	case 230ULL: goto x86_l_e6;
	case 234ULL: goto x86_l_ea;
	case 240ULL: goto x86_l_f0;
	case 244ULL: goto x86_l_f4;
	case 250ULL: goto x86_l_fa;
	case 254ULL: goto x86_l_fe;
	case 260ULL: goto x86_l_104;
	case 263ULL: goto x86_l_107;
	case 268ULL: goto x86_l_10c;
	case 272ULL: goto x86_l_110;
	case 277ULL: goto x86_l_115;
	case 282ULL: goto x86_l_11a;
	case 287ULL: goto x86_l_11f;
	case 290ULL: goto x86_l_122;
	case 296ULL: goto x86_l_128;
	case 302ULL: goto x86_l_12e;
	case 306ULL: goto x86_l_132;
	case 312ULL: goto x86_l_138;
	case 317ULL: goto x86_l_13d;
	case 320ULL: goto x86_l_140;
	case 326ULL: goto x86_l_146;
	case 329ULL: goto x86_l_149;
	case 331ULL: goto x86_l_14b;
	case 335ULL: goto x86_l_14f;
	case 341ULL: goto x86_l_155;
	case 350ULL: goto x86_l_15e;
	case 356ULL: goto x86_l_164;
	case 364ULL: goto x86_l_16c;
	case 369ULL: goto x86_l_171;
	case 373ULL: goto x86_l_175;
	case 380ULL: goto x86_l_17c;
	case 383ULL: goto x86_l_17f;
	case 386ULL: goto x86_l_182;
	case 388ULL: goto x86_l_184;
	case 391ULL: goto x86_l_187;
	case 393ULL: goto x86_l_189;
	case 396ULL: goto x86_l_18c;
	case 399ULL: goto x86_l_18f;
	case 405ULL: goto x86_l_195;
	case 408ULL: goto x86_l_198;
	case 414ULL: goto x86_l_19e;
	case 419ULL: goto x86_l_1a3;
	case 422ULL: goto x86_l_1a6;
	case 424ULL: goto x86_l_1a8;
	case 427ULL: goto x86_l_1ab;
	case 430ULL: goto x86_l_1ae;
	case 432ULL: goto x86_l_1b0;
	case 435ULL: goto x86_l_1b3;
	case 438ULL: goto x86_l_1b6;
	case 444ULL: goto x86_l_1bc;
	case 447ULL: goto x86_l_1bf;
	case 453ULL: goto x86_l_1c5;
	case 457ULL: goto x86_l_1c9;
	case 462ULL: goto x86_l_1ce;
	case 467ULL: goto x86_l_1d3;
	case 470ULL: goto x86_l_1d6;
	case 476ULL: goto x86_l_1dc;
	case 479ULL: goto x86_l_1df;
	case 482ULL: goto x86_l_1e2;
	case 488ULL: goto x86_l_1e8;
	case 491ULL: goto x86_l_1eb;
	case 494ULL: goto x86_l_1ee;
	case 500ULL: goto x86_l_1f4;
	case 505ULL: goto x86_l_1f9;
	case 508ULL: goto x86_l_1fc;
	case 514ULL: goto x86_l_202;
	case 517ULL: goto x86_l_205;
	case 519ULL: goto x86_l_207;
	case 522ULL: goto x86_l_20a;
	case 528ULL: goto x86_l_210;
	case 531ULL: goto x86_l_213;
	case 537ULL: goto x86_l_219;
	case 540ULL: goto x86_l_21c;
	case 542ULL: goto x86_l_21e;
	case 545ULL: goto x86_l_221;
	case 551ULL: goto x86_l_227;
	case 553ULL: goto x86_l_229;
	case 563ULL: goto x86_l_233;
	case 567ULL: goto x86_l_237;
	case 569ULL: goto x86_l_239;
	case 574ULL: goto x86_l_23e;
	case 578ULL: goto x86_l_242;
	case 584ULL: goto x86_l_248;
	case 594ULL: goto x86_l_252;
	case 598ULL: goto x86_l_256;
	case 604ULL: goto x86_l_25c;
	case 609ULL: goto x86_l_261;
	case 614ULL: goto x86_l_266;
	case 617ULL: goto x86_l_269;
	case 620ULL: goto x86_l_26c;
	case 626ULL: goto x86_l_272;
	case 629ULL: goto x86_l_275;
	case 635ULL: goto x86_l_27b;
	case 638ULL: goto x86_l_27e;
	case 644ULL: goto x86_l_284;
	case 649ULL: goto x86_l_289;
	case 652ULL: goto x86_l_28c;
	case 654ULL: goto x86_l_28e;
	case 657ULL: goto x86_l_291;
	case 659ULL: goto x86_l_293;
	case 662ULL: goto x86_l_296;
	case 668ULL: goto x86_l_29c;
	case 673ULL: goto x86_l_2a1;
	case 678ULL: goto x86_l_2a6;
	case 683ULL: goto x86_l_2ab;
	case 685ULL: goto x86_l_2ad;
	case 688ULL: goto x86_l_2b0;
	case 690ULL: goto x86_l_2b2;
	case 693ULL: goto x86_l_2b5;
	case 696ULL: goto x86_l_2b8;
	case 698ULL: goto x86_l_2ba;
	case 707ULL: goto x86_l_2c3;
	case 713ULL: goto x86_l_2c9;
	case 716ULL: goto x86_l_2cc;
	case 724ULL: goto x86_l_2d4;
	case 730ULL: goto x86_l_2da;
	case 732ULL: goto x86_l_2dc;
	case 742ULL: goto x86_l_2e6;
	case 745ULL: goto x86_l_2e9;
	case 747ULL: goto x86_l_2eb;
	case 750ULL: goto x86_l_2ee;
	case 752ULL: goto x86_l_2f0;
	case 755ULL: goto x86_l_2f3;
	case 757ULL: goto x86_l_2f5;
	case 762ULL: goto x86_l_2fa;
	case 764ULL: goto x86_l_2fc;
	case 769ULL: goto x86_l_301;
	case 771ULL: goto x86_l_303;
	case 774ULL: goto x86_l_306;
	case 777ULL: goto x86_l_309;
	case 779ULL: goto x86_l_30b;
	case 784ULL: goto x86_l_310;
	case 786ULL: goto x86_l_312;
	case 791ULL: goto x86_l_317;
	case 793ULL: goto x86_l_319;
	case 798ULL: goto x86_l_31e;
	case 803ULL: goto x86_l_323;
	case 805ULL: goto x86_l_325;
	case 808ULL: goto x86_l_328;
	case 810ULL: goto x86_l_32a;
	case 815ULL: goto x86_l_32f;
	case 818ULL: goto x86_l_332;
	case 824ULL: goto x86_l_338;
	case 827ULL: goto x86_l_33b;
	case 831ULL: goto x86_l_33f;
	case 837ULL: goto x86_l_345;
	case 842ULL: goto x86_l_34a;
	case 849ULL: goto x86_l_351;
	case 856ULL: goto x86_l_358;
	case 861ULL: goto x86_l_35d;
	case 866ULL: goto x86_l_362;
	case 869ULL: goto x86_l_365;
	case 874ULL: goto x86_l_36a;
	case 876ULL: goto x86_l_36c;
	case 883ULL: goto x86_l_373;
	case 888ULL: goto x86_l_378;
	case 893ULL: goto x86_l_37d;
	case 896ULL: goto x86_l_380;
	case 901ULL: goto x86_l_385;
	case 903ULL: goto x86_l_387;
	case 905ULL: goto x86_l_389;
	case 909ULL: goto x86_l_38d;
	case 910ULL: goto x86_l_38e;
	case 912ULL: goto x86_l_390;
	case 914ULL: goto x86_l_392;
	case 916ULL: goto x86_l_394;
	case 918ULL: goto x86_l_396;
	case 919ULL: goto x86_l_397;
	case 924ULL: goto x86_l_39c;
	case 927ULL: goto x86_l_39f;
	case 935ULL: goto x86_l_3a7;
	case 937ULL: goto x86_l_3a9;
	case 943ULL: goto x86_l_3af;
	case 951ULL: goto x86_l_3b7;
	case 953ULL: goto x86_l_3b9;
	case 959ULL: goto x86_l_3bf;
	case 967ULL: goto x86_l_3c7;
	case 969ULL: goto x86_l_3c9;
	case 975ULL: goto x86_l_3cf;
	case 983ULL: goto x86_l_3d7;
	case 985ULL: goto x86_l_3d9;
	case 991ULL: goto x86_l_3df;
	case 999ULL: goto x86_l_3e7;
	case 1001ULL: goto x86_l_3e9;
	case 1007ULL: goto x86_l_3ef;
	case 1015ULL: goto x86_l_3f7;
	case 1017ULL: goto x86_l_3f9;
	case 1024ULL: goto x86_l_400;
	case 1031ULL: goto x86_l_407;
	case 1036ULL: goto x86_l_40c;
	case 1041ULL: goto x86_l_411;
	case 1044ULL: goto x86_l_414;
	case 1049ULL: goto x86_l_419;
	case 1051ULL: goto x86_l_41b;
	case 1055ULL: goto x86_l_41f;
	case 1060ULL: goto x86_l_424;
	case 1062ULL: goto x86_l_426;
	case 1067ULL: goto x86_l_42b;
	case 1072ULL: goto x86_l_430;
	case 1079ULL: goto x86_l_437;
	case 1084ULL: goto x86_l_43c;
	case 1089ULL: goto x86_l_441;
	case 1091ULL: goto x86_l_443;
	case 1094ULL: goto x86_l_446;
	case 1100ULL: goto x86_l_44c;
	case 1107ULL: goto x86_l_453;
	case 1112ULL: goto x86_l_458;
	case 1117ULL: goto x86_l_45d;
	case 1119ULL: goto x86_l_45f;
	case 1124ULL: goto x86_l_464;
	case 1125ULL: goto x86_l_465;
	case 1128ULL: goto x86_l_468;
	case 1130ULL: goto x86_l_46a;
	case 1133ULL: goto x86_l_46d;
	case 1135ULL: goto x86_l_46f;
	case 1137ULL: goto x86_l_471;
	case 1139ULL: goto x86_l_473;
	case 1142ULL: goto x86_l_476;
	case 1145ULL: goto x86_l_479;
	case 1147ULL: goto x86_l_47b;
	case 1149ULL: goto x86_l_47d;
	case 1150ULL: goto x86_l_47e;
	case 1151ULL: goto x86_l_47f;
	case 1154ULL: goto x86_l_482;
	case 1156ULL: goto x86_l_484;
	case 1158ULL: goto x86_l_486;
	case 1163ULL: goto x86_l_48b;
	case 1167ULL: goto x86_l_48f;
	case 1169ULL: goto x86_l_491;
	case 1174ULL: goto x86_l_496;
	case 1178ULL: goto x86_l_49a;
	case 1180ULL: goto x86_l_49c;
	case 1190ULL: goto x86_l_4a6;
	case 1194ULL: goto x86_l_4aa;
	case 1196ULL: goto x86_l_4ac;
	case 1199ULL: goto x86_l_4af;
	case 1204ULL: goto x86_l_4b4;
	case 1207ULL: goto x86_l_4b7;
	case 1210ULL: goto x86_l_4ba;
	case 1212ULL: goto x86_l_4bc;
	case 1214ULL: goto x86_l_4be;
	case 1217ULL: goto x86_l_4c1;
	case 1220ULL: goto x86_l_4c4;
	case 1222ULL: goto x86_l_4c6;
	case 1226ULL: goto x86_l_4ca;
	case 1229ULL: goto x86_l_4cd;
	case 1234ULL: goto x86_l_4d2;
	case 1237ULL: goto x86_l_4d5;
	case 1240ULL: goto x86_l_4d8;
	case 1242ULL: goto x86_l_4da;
	case 1244ULL: goto x86_l_4dc;
	case 1248ULL: goto x86_l_4e0;
	case 1251ULL: goto x86_l_4e3;
	case 1256ULL: goto x86_l_4e8;
	case 1259ULL: goto x86_l_4eb;
	case 1262ULL: goto x86_l_4ee;
	case 1264ULL: goto x86_l_4f0;
	case 1266ULL: goto x86_l_4f2;
	case 1270ULL: goto x86_l_4f6;
	case 1273ULL: goto x86_l_4f9;
	case 1278ULL: goto x86_l_4fe;
	case 1281ULL: goto x86_l_501;
	case 1284ULL: goto x86_l_504;
	case 1286ULL: goto x86_l_506;
	case 1288ULL: goto x86_l_508;
	case 1290ULL: goto x86_l_50a;
	case 1293ULL: goto x86_l_50d;
	case 1295ULL: goto x86_l_50f;
	case 1297ULL: goto x86_l_511;
	case 1307ULL: goto x86_l_51b;
	case 1311ULL: goto x86_l_51f;
	case 1313ULL: goto x86_l_521;
	case 1317ULL: goto x86_l_525;
	case 1318ULL: goto x86_l_526;
	case 1319ULL: goto x86_l_527;
	case 1320ULL: goto x86_l_528;
	case 1323ULL: goto x86_l_52b;
	case 1325ULL: goto x86_l_52d;
	case 1329ULL: goto x86_l_531;
	case 1331ULL: goto x86_l_533;
	case 1336ULL: goto x86_l_538;
	case 1340ULL: goto x86_l_53c;
	case 1342ULL: goto x86_l_53e;
	case 1347ULL: goto x86_l_543;
	case 1348ULL: goto x86_l_544;
	case 1349ULL: goto x86_l_545;
	case 1354ULL: goto x86_l_54a;
	case 1358ULL: goto x86_l_54e;
	case 1360ULL: goto x86_l_550;
	case 1370ULL: goto x86_l_55a;
	case 1374ULL: goto x86_l_55e;
	case 1376ULL: goto x86_l_560;
	case 1381ULL: goto x86_l_565;
	case 1382ULL: goto x86_l_566;
	case 1383ULL: goto x86_l_567;
	case 1388ULL: goto x86_l_56c;
	case 1389ULL: goto x86_l_56d;
	case 1390ULL: goto x86_l_56e;
	case 1392ULL: goto x86_l_570;
	case 1394ULL: goto x86_l_572;
	case 1396ULL: goto x86_l_574;
	case 1397ULL: goto x86_l_575;
	case 1401ULL: goto x86_l_579;
	case 1410ULL: goto x86_l_582;
	case 1419ULL: goto x86_l_58b;
	case 1428ULL: goto x86_l_594;
	case 1437ULL: goto x86_l_59d;
	case 1446ULL: goto x86_l_5a6;
	case 1453ULL: goto x86_l_5ad;
	case 1461ULL: goto x86_l_5b5;
	case 1464ULL: goto x86_l_5b8;
	case 1466ULL: goto x86_l_5ba;
	case 1469ULL: goto x86_l_5bd;
	case 1471ULL: goto x86_l_5bf;
	case 1474ULL: goto x86_l_5c2;
	case 1480ULL: goto x86_l_5c8;
	case 1483ULL: goto x86_l_5cb;
	case 1486ULL: goto x86_l_5ce;
	case 1488ULL: goto x86_l_5d0;
	case 1493ULL: goto x86_l_5d5;
	case 1496ULL: goto x86_l_5d8;
	case 1498ULL: goto x86_l_5da;
	case 1501ULL: goto x86_l_5dd;
	case 1504ULL: goto x86_l_5e0;
	case 1510ULL: goto x86_l_5e6;
	case 1513ULL: goto x86_l_5e9;
	case 1515ULL: goto x86_l_5eb;
	case 1518ULL: goto x86_l_5ee;
	case 1520ULL: goto x86_l_5f0;
	case 1523ULL: goto x86_l_5f3;
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
	/* 0xa: sub    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 40ULL);
x86_l_e:
	/* 0xe: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_11:
	/* 0x11: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_19:
	/* 0x19: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_20:
	/* 0x20: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_25:
	/* 0x25: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a:
	/* 0x2a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c:
	/* 0x2c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2f:
	/* 0x2f: je     387 <generic_retuprobe_filter_arg+0x387> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_387;
	}
x86_l_35:
	/* 0x35: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_38:
	/* 0x38: mov    r12d,DWORD PTR [rax+0x5f00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24320ULL);
x86_l_3f:
	/* 0x3f: lea    rsi,[rax+0x5ef8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24312ULL);
x86_l_46:
	/* 0x46: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&filter_map)));
x86_l_4d:
	/* 0x4d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_52:
	/* 0x52: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_54:
	/* 0x54: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_57:
	/* 0x57: je     36c <generic_retuprobe_filter_arg+0x36c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36c;
	}
x86_l_5d:
	/* 0x5d: cmp    BYTE PTR [r14+0x5ee0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104316165685248ULL);
x86_l_65:
	/* 0x65: je     36c <generic_retuprobe_filter_arg+0x36c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36c;
	}
x86_l_6b:
	/* 0x6b: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_6e:
	/* 0x6e: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_71:
	/* 0x71: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_74:
	/* 0x74: cmp    BYTE PTR [r14+rax*1+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 104183021699072ULL);
x86_l_7d:
	/* 0x7d: je     b7 <generic_retuprobe_filter_arg+0xb7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b7;
	}
x86_l_7f:
	/* 0x7f: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_81:
	/* 0x81: mov    ecx,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_86:
	/* 0x86: lea    r13,[rcx+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_8a:
	/* 0x8a: add    r13,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_8e:
	/* 0x8e: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_91:
	/* 0x91: mov    QWORD PTR [rsp+0x10],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_96:
	/* 0x96: and    r13d,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_9d:
	/* 0x9d: cmp    DWORD PTR [r15+r13*1],0x19 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 25ULL);
x86_l_a2:
	/* 0xa2: jae    10c <generic_retuprobe_filter_arg+0x10c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_10c;
	}
x86_l_a4:
	/* 0xa4: cmp    r13,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 1ULL);
x86_l_a8:
	/* 0xa8: je     36c <generic_retuprobe_filter_arg+0x36c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36c;
	}
x86_l_ae:
	/* 0xae: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_b1:
	/* 0xb1: jne    34a <generic_retuprobe_filter_arg+0x34a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_34a;
	}
x86_l_b7:
	/* 0xb7: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_bb:
	/* 0xbb: jg     dc <generic_retuprobe_filter_arg+0xdc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_dc;
	}
x86_l_bd:
	/* 0xbd: cmp    r12d,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4294967295ULL);
x86_l_c1:
	/* 0xc1: je     39c <generic_retuprobe_filter_arg+0x39c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_39c;
	}
x86_l_c7:
	/* 0xc7: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_ca:
	/* 0xca: je     3a9 <generic_retuprobe_filter_arg+0x3a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a9;
	}
x86_l_d0:
	/* 0xd0: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_d4:
	/* 0xd4: je     3b9 <generic_retuprobe_filter_arg+0x3b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3b9;
	}
x86_l_da:
	/* 0xda: jmp    fa <generic_retuprobe_filter_arg+0xfa> */
	goto x86_l_fa;
x86_l_dc:
	/* 0xdc: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_e0:
	/* 0xe0: je     3c9 <generic_retuprobe_filter_arg+0x3c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c9;
	}
x86_l_e6:
	/* 0xe6: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_ea:
	/* 0xea: je     3d9 <generic_retuprobe_filter_arg+0x3d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3d9;
	}
x86_l_f0:
	/* 0xf0: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_f4:
	/* 0xf4: je     3e9 <generic_retuprobe_filter_arg+0x3e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e9;
	}
x86_l_fa:
	/* 0xfa: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_fe:
	/* 0xfe: jg     41b <generic_retuprobe_filter_arg+0x41b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_41b;
	}
x86_l_104:
	/* 0x104: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_107:
	/* 0x107: jmp    3f9 <generic_retuprobe_filter_arg+0x3f9> */
	goto x86_l_3f9;
x86_l_10c:
	/* 0x10c: lea    rax,[r15+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_110:
	/* 0x110: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_115:
	/* 0x115: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_11a:
	/* 0x11a: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11f:
	/* 0x11f: mov    edi,DWORD PTR [rax+rbp*4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 2), 0ULL);
x86_l_122:
	/* 0x122: test   edi,0x3ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDI, X86_WIDTH_32, 1023ULL);
x86_l_128:
	/* 0x128: je     a4 <generic_retuprobe_filter_arg+0xa4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a4;
	}
x86_l_12e:
	/* 0x12e: add    edi,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_132:
	/* 0x132: and    edi,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_138:
	/* 0x138: mov    ecx,DWORD PTR [r15+rdi*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 0), 4ULL);
x86_l_13d:
	/* 0x13d: cmp    ecx,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 35ULL);
x86_l_140:
	/* 0x140: je     b7 <generic_retuprobe_filter_arg+0xb7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b7;
	}
x86_l_146:
	/* 0x146: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_149:
	/* 0x149: mov    eax,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14b:
	/* 0x14b: cmp    rax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4ULL);
x86_l_14f:
	/* 0x14f: ja     b7 <generic_retuprobe_filter_arg+0xb7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_b7;
	}
x86_l_155:
	/* 0x155: cmp    DWORD PTR [r14+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_15e:
	/* 0x15e: jne    b7 <generic_retuprobe_filter_arg+0xb7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b7;
	}
x86_l_164:
	/* 0x164: mov    rax,QWORD PTR [r14+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_16c:
	/* 0x16c: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_171:
	/* 0x171: lea    rsi,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_175:
	/* 0x175: add    rsi,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_17c:
	/* 0x17c: mov    eax,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_17f:
	/* 0x17f: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_182:
	/* 0x182: jle    1a3 <generic_retuprobe_filter_arg+0x1a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1a3;
	}
x86_l_184:
	/* 0x184: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_187:
	/* 0x187: jg     1d3 <generic_retuprobe_filter_arg+0x1d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1d3;
	}
x86_l_189:
	/* 0x189: lea    edx,[rax-0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551588ULL);
x86_l_18c:
	/* 0x18c: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_18f:
	/* 0x18f: jb     219 <generic_retuprobe_filter_arg+0x219> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_219;
	}
x86_l_195:
	/* 0x195: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_198:
	/* 0x198: je     2fc <generic_retuprobe_filter_arg+0x2fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fc;
	}
x86_l_19e:
	/* 0x19e: jmp    338 <generic_retuprobe_filter_arg+0x338> */
	goto x86_l_338;
x86_l_1a3:
	/* 0x1a3: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_1a6:
	/* 0x1a6: jle    1f9 <generic_retuprobe_filter_arg+0x1f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1f9;
	}
x86_l_1a8:
	/* 0x1a8: lea    edx,[rax-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_1ab:
	/* 0x1ab: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1ae:
	/* 0x1ae: jb     219 <generic_retuprobe_filter_arg+0x219> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_219;
	}
x86_l_1b0:
	/* 0x1b0: lea    ecx,[rax-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_1b3:
	/* 0x1b3: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1b6:
	/* 0x1b6: jb     2fc <generic_retuprobe_filter_arg+0x2fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2fc;
	}
x86_l_1bc:
	/* 0x1bc: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1bf:
	/* 0x1bf: jne    338 <generic_retuprobe_filter_arg+0x338> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_338;
	}
x86_l_1c5:
	/* 0x1c5: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1c9:
	/* 0x1c9: call   0 <generic_retuprobe_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 462ULL);
	__x86_sim_call_depth++;
	goto x86_l_464;
x86_l_1ce:
	/* 0x1ce: jmp    32f <generic_retuprobe_filter_arg+0x32f> */
	goto x86_l_32f;
x86_l_1d3:
	/* 0x1d3: cmp    eax,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 41ULL);
x86_l_1d6:
	/* 0x1d6: jg     2eb <generic_retuprobe_filter_arg+0x2eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2eb;
	}
x86_l_1dc:
	/* 0x1dc: lea    ecx,[rax-0x26] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551578ULL);
x86_l_1df:
	/* 0x1df: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1e2:
	/* 0x1e2: jb     2a6 <generic_retuprobe_filter_arg+0x2a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2a6;
	}
x86_l_1e8:
	/* 0x1e8: add    eax,0xffffffd8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4294967256ULL);
x86_l_1eb:
	/* 0x1eb: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1ee:
	/* 0x1ee: jb     29c <generic_retuprobe_filter_arg+0x29c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_29c;
	}
x86_l_1f4:
	/* 0x1f4: jmp    338 <generic_retuprobe_filter_arg+0x338> */
	goto x86_l_338;
x86_l_1f9:
	/* 0x1f9: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1fc:
	/* 0x1fc: jg     289 <generic_retuprobe_filter_arg+0x289> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_289;
	}
x86_l_202:
	/* 0x202: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_205:
	/* 0x205: je     219 <generic_retuprobe_filter_arg+0x219> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_219;
	}
x86_l_207:
	/* 0x207: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_20a:
	/* 0x20a: je     319 <generic_retuprobe_filter_arg+0x319> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_319;
	}
x86_l_210:
	/* 0x210: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_213:
	/* 0x213: jne    338 <generic_retuprobe_filter_arg+0x338> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_338;
	}
x86_l_219:
	/* 0x219: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_21c:
	/* 0x21c: jle    266 <generic_retuprobe_filter_arg+0x266> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_266;
	}
x86_l_21e:
	/* 0x21e: cmp    eax,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 36ULL);
x86_l_221:
	/* 0x221: ja     303 <generic_retuprobe_filter_arg+0x303> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_303;
	}
x86_l_227:
	/* 0x227: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_229:
	/* 0x229: movabs r8,0x1e00000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_64, 128849018880ULL);
x86_l_233:
	/* 0x233: bt     r8,rdx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RDX, X86_WIDTH_64);
x86_l_237:
	/* 0x237: jb     2ad <generic_retuprobe_filter_arg+0x2ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2ad;
	}
x86_l_239:
	/* 0x239: mov    ecx,0x60000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1610612736ULL);
x86_l_23e:
	/* 0x23e: bt     rcx,rdx */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_242:
	/* 0x242: jb     312 <generic_retuprobe_filter_arg+0x312> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_312;
	}
x86_l_248:
	/* 0x248: movabs rcx,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 6442450944ULL);
x86_l_252:
	/* 0x252: bt     rcx,rdx */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_256:
	/* 0x256: jae    303 <generic_retuprobe_filter_arg+0x303> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_303;
	}
x86_l_25c:
	/* 0x25c: call   0 <generic_retuprobe_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 609ULL);
	__x86_sim_call_depth++;
	goto x86_l_527;
x86_l_261:
	/* 0x261: jmp    32f <generic_retuprobe_filter_arg+0x32f> */
	goto x86_l_32f;
x86_l_266:
	/* 0x266: lea    ecx,[rax-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_269:
	/* 0x269: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_26c:
	/* 0x26c: jb     32a <generic_retuprobe_filter_arg+0x32a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_32a;
	}
x86_l_272:
	/* 0x272: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_275:
	/* 0x275: je     30b <generic_retuprobe_filter_arg+0x30b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30b;
	}
x86_l_27b:
	/* 0x27b: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_27e:
	/* 0x27e: je     30b <generic_retuprobe_filter_arg+0x30b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30b;
	}
x86_l_284:
	/* 0x284: jmp    338 <generic_retuprobe_filter_arg+0x338> */
	goto x86_l_338;
x86_l_289:
	/* 0x289: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_28c:
	/* 0x28c: je     29c <generic_retuprobe_filter_arg+0x29c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29c;
	}
x86_l_28e:
	/* 0x28e: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_291:
	/* 0x291: je     2a6 <generic_retuprobe_filter_arg+0x2a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a6;
	}
x86_l_293:
	/* 0x293: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_296:
	/* 0x296: jne    338 <generic_retuprobe_filter_arg+0x338> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_338;
	}
x86_l_29c:
	/* 0x29c: call   0 <generic_retuprobe_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 673ULL);
	__x86_sim_call_depth++;
	goto x86_l_56e;
x86_l_2a1:
	/* 0x2a1: jmp    32f <generic_retuprobe_filter_arg+0x32f> */
	goto x86_l_32f;
x86_l_2a6:
	/* 0x2a6: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_2ab:
	/* 0x2ab: jmp    31e <generic_retuprobe_filter_arg+0x31e> */
	goto x86_l_31e;
x86_l_2ad:
	/* 0x2ad: cmp    ecx,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 30ULL);
x86_l_2b0:
	/* 0x2b0: jne    32a <generic_retuprobe_filter_arg+0x32a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_32a;
	}
x86_l_2b2:
	/* 0x2b2: mov    eax,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b5:
	/* 0x2b5: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_2b8:
	/* 0x2b8: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_2ba:
	/* 0x2ba: cmp    DWORD PTR [r14+rcx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 104041287778304ULL);
x86_l_2c3:
	/* 0x2c3: jne    b7 <generic_retuprobe_filter_arg+0xb7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b7;
	}
x86_l_2c9:
	/* 0x2c9: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cc:
	/* 0x2cc: mov    rdx,QWORD PTR [r14+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_2d4:
	/* 0x2d4: and    edx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_2da:
	/* 0x2da: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2dc:
	/* 0x2dc: andn   rcx,rcx,QWORD PTR [r14+rdx*1+0x90] */
	X86_SIM_L_EXEC_ANDN_MEM(X86_RCX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RDX, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_R14)), 144ULL);
x86_l_2e6:
	/* 0x2e6: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_2e9:
	/* 0x2e9: jmp    32f <generic_retuprobe_filter_arg+0x32f> */
	goto x86_l_32f;
x86_l_2eb:
	/* 0x2eb: cmp    eax,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 42ULL);
x86_l_2ee:
	/* 0x2ee: je     2fc <generic_retuprobe_filter_arg+0x2fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fc;
	}
x86_l_2f0:
	/* 0x2f0: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2f3:
	/* 0x2f3: jne    338 <generic_retuprobe_filter_arg+0x338> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_338;
	}
x86_l_2f5:
	/* 0x2f5: call   0 <generic_retuprobe_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 762ULL);
	__x86_sim_call_depth++;
	return 2223ULL;
x86_l_2fa:
	/* 0x2fa: jmp    32f <generic_retuprobe_filter_arg+0x32f> */
	goto x86_l_32f;
x86_l_2fc:
	/* 0x2fc: call   0 <generic_retuprobe_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 769ULL);
	__x86_sim_call_depth++;
	goto x86_l_464;
x86_l_301:
	/* 0x301: jmp    32f <generic_retuprobe_filter_arg+0x32f> */
	goto x86_l_32f;
x86_l_303:
	/* 0x303: lea    ecx,[rax-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_306:
	/* 0x306: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_309:
	/* 0x309: jae    325 <generic_retuprobe_filter_arg+0x325> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_325;
	}
x86_l_30b:
	/* 0x30b: call   0 <generic_retuprobe_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 784ULL);
	__x86_sim_call_depth++;
	return 2394ULL;
x86_l_310:
	/* 0x310: jmp    32f <generic_retuprobe_filter_arg+0x32f> */
	goto x86_l_32f;
x86_l_312:
	/* 0x312: call   0 <generic_retuprobe_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 791ULL);
	__x86_sim_call_depth++;
	return 2465ULL;
x86_l_317:
	/* 0x317: jmp    32f <generic_retuprobe_filter_arg+0x32f> */
	goto x86_l_32f;
x86_l_319:
	/* 0x319: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_31e:
	/* 0x31e: call   0 <generic_retuprobe_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 803ULL);
	__x86_sim_call_depth++;
	return 2536ULL;
x86_l_323:
	/* 0x323: jmp    32f <generic_retuprobe_filter_arg+0x32f> */
	goto x86_l_32f;
x86_l_325:
	/* 0x325: cmp    eax,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_328:
	/* 0x328: jne    338 <generic_retuprobe_filter_arg+0x338> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_338;
	}
x86_l_32a:
	/* 0x32a: call   0 <generic_retuprobe_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 815ULL);
	__x86_sim_call_depth++;
	return 2699ULL;
x86_l_32f:
	/* 0x32f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_332:
	/* 0x332: je     b7 <generic_retuprobe_filter_arg+0xb7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b7;
	}
x86_l_338:
	/* 0x338: inc    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_33b:
	/* 0x33b: cmp    rbp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 6ULL);
x86_l_33f:
	/* 0x33f: jne    11a <generic_retuprobe_filter_arg+0x11a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_11a;
	}
x86_l_345:
	/* 0x345: jmp    a4 <generic_retuprobe_filter_arg+0xa4> */
	goto x86_l_a4;
x86_l_34a:
	/* 0x34a: mov    DWORD PTR [r14+0x5f04],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24324ULL);
x86_l_351:
	/* 0x351: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&retuprobe_calls)));
x86_l_358:
	/* 0x358: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_35d:
	/* 0x35d: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_362:
	/* 0x362: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_365:
	/* 0x365: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_36a:
	/* 0x36a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36c:
	/* 0x36c: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&retuprobe_calls)));
x86_l_373:
	/* 0x373: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_378:
	/* 0x378: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_37d:
	/* 0x37d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_380:
	/* 0x380: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_385:
	/* 0x385: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_387:
	/* 0x387: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_389:
	/* 0x389: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_38d:
	/* 0x38d: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_38e:
	/* 0x38e: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_390:
	/* 0x390: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_392:
	/* 0x392: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_394:
	/* 0x394: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_396:
	/* 0x396: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_397:
	/* 0x397: jmp    2485 <filter_file_type+0xa4> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_39c:
	/* 0x39c: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_39f:
	/* 0x39f: cmp    BYTE PTR [r14+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104183021699072ULL);
x86_l_3a7:
	/* 0x3a7: jne    3f9 <generic_retuprobe_filter_arg+0x3f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3f9;
	}
x86_l_3a9:
	/* 0x3a9: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_3af:
	/* 0x3af: cmp    BYTE PTR [r14+0x5ec2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104187316666368ULL);
x86_l_3b7:
	/* 0x3b7: jne    3f9 <generic_retuprobe_filter_arg+0x3f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3f9;
	}
x86_l_3b9:
	/* 0x3b9: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_3bf:
	/* 0x3bf: cmp    BYTE PTR [r14+0x5ec3],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104191611633664ULL);
x86_l_3c7:
	/* 0x3c7: jne    3f9 <generic_retuprobe_filter_arg+0x3f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3f9;
	}
x86_l_3c9:
	/* 0x3c9: mov    r12d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 3ULL);
x86_l_3cf:
	/* 0x3cf: cmp    BYTE PTR [r14+0x5ec4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104195906600960ULL);
x86_l_3d7:
	/* 0x3d7: jne    3f9 <generic_retuprobe_filter_arg+0x3f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3f9;
	}
x86_l_3d9:
	/* 0x3d9: mov    r12d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4ULL);
x86_l_3df:
	/* 0x3df: cmp    BYTE PTR [r14+0x5ec5],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104200201568256ULL);
x86_l_3e7:
	/* 0x3e7: jne    3f9 <generic_retuprobe_filter_arg+0x3f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3f9;
	}
x86_l_3e9:
	/* 0x3e9: mov    r12d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 5ULL);
x86_l_3ef:
	/* 0x3ef: cmp    BYTE PTR [r14+0x5ec6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104204496535552ULL);
x86_l_3f7:
	/* 0x3f7: je     41b <generic_retuprobe_filter_arg+0x41b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_41b;
	}
x86_l_3f9:
	/* 0x3f9: mov    DWORD PTR [r14+0x5f00],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24320ULL);
x86_l_400:
	/* 0x400: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&retuprobe_calls)));
x86_l_407:
	/* 0x407: mov    ecx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_40c:
	/* 0x40c: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_411:
	/* 0x411: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_414:
	/* 0x414: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_419:
	/* 0x419: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41b:
	/* 0x41b: mov    rbx,QWORD PTR [r14+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_41f:
	/* 0x41f: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_424:
	/* 0x424: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_426:
	/* 0x426: mov    QWORD PTR [rsp+0x18],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_42b:
	/* 0x42b: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_430:
	/* 0x430: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_437:
	/* 0x437: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_43c:
	/* 0x43c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_441:
	/* 0x441: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_443:
	/* 0x443: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_446:
	/* 0x446: je     387 <generic_retuprobe_filter_arg+0x387> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_387;
	}
x86_l_44c:
	/* 0x44c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_453:
	/* 0x453: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_458:
	/* 0x458: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_45d:
	/* 0x45d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45f:
	/* 0x45f: jmp    387 <generic_retuprobe_filter_arg+0x387> */
	goto x86_l_387;
x86_l_464:
	/* 0x464: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_465:
	/* 0x465: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_468:
	/* 0x468: mov    edx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_46a:
	/* 0x46a: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_46d:
	/* 0x46d: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_46f:
	/* 0x46f: jne    47f <filter_file_buf+0x1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_47f;
	}
x86_l_471:
	/* 0x471: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_473:
	/* 0x473: and    eax,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_476:
	/* 0x476: cmp    eax,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 36ULL);
x86_l_479:
	/* 0x479: je     47f <filter_file_buf+0x1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_47f;
	}
x86_l_47b:
	/* 0x47b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_47d:
	/* 0x47d: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_47e:
	/* 0x47e: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_47f:
	/* 0x47f: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_482:
	/* 0x482: ja     4be <filter_file_buf+0x5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_4be;
	}
x86_l_484:
	/* 0x484: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_486:
	/* 0x486: mov    edi,0x4000100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 67109120ULL);
x86_l_48b:
	/* 0x48b: bt     rdi,rax */
	X86_SIM_L_EXEC_BT(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_48f:
	/* 0x48f: jb     4f2 <filter_file_buf+0x8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_4f2;
	}
x86_l_491:
	/* 0x491: mov    edi,0x8000200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 134218240ULL);
x86_l_496:
	/* 0x496: bt     rdi,rax */
	X86_SIM_L_EXEC_BT(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_49a:
	/* 0x49a: jb     4dc <filter_file_buf+0x78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_4dc;
	}
x86_l_49c:
	/* 0x49c: movabs rdi,0x3000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_64, 206158430208ULL);
x86_l_4a6:
	/* 0x4a6: bt     rdi,rax */
	X86_SIM_L_EXEC_BT(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_4aa:
	/* 0x4aa: jae    4be <filter_file_buf+0x5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_4be;
	}
x86_l_4ac:
	/* 0x4ac: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4af:
	/* 0x4af: call   23e1 <filter_file_type> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 1204ULL);
	__x86_sim_call_depth++;
	return 9185ULL;
x86_l_4b4:
	/* 0x4b4: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4b7:
	/* 0x4b7: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_4ba:
	/* 0x4ba: jbe    50f <filter_file_buf+0xab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_50f;
	}
x86_l_4bc:
	/* 0x4bc: jmp    525 <filter_file_buf+0xc1> */
	goto x86_l_525;
x86_l_4be:
	/* 0x4be: lea    eax,[rcx-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_4c1:
	/* 0x4c1: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4c4:
	/* 0x4c4: jae    508 <filter_file_buf+0xa4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_508;
	}
x86_l_4c6:
	/* 0x4c6: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_4ca:
	/* 0x4ca: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4cd:
	/* 0x4cd: call   113f <filter_char_buf_equal> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 1234ULL);
	__x86_sim_call_depth++;
	return 4415ULL;
x86_l_4d2:
	/* 0x4d2: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4d5:
	/* 0x4d5: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_4d8:
	/* 0x4d8: jbe    50f <filter_file_buf+0xab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_50f;
	}
x86_l_4da:
	/* 0x4da: jmp    525 <filter_file_buf+0xc1> */
	goto x86_l_525;
x86_l_4dc:
	/* 0x4dc: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_4e0:
	/* 0x4e0: mov    edi,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4e3:
	/* 0x4e3: call   f57 <filter_char_buf_postfix> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 1256ULL);
	__x86_sim_call_depth++;
	return 3927ULL;
x86_l_4e8:
	/* 0x4e8: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4eb:
	/* 0x4eb: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_4ee:
	/* 0x4ee: jbe    50f <filter_file_buf+0xab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_50f;
	}
x86_l_4f0:
	/* 0x4f0: jmp    525 <filter_file_buf+0xc1> */
	goto x86_l_525;
x86_l_4f2:
	/* 0x4f2: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_4f6:
	/* 0x4f6: mov    edi,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4f9:
	/* 0x4f9: call   109f <filter_char_buf_prefix> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 1278ULL);
	__x86_sim_call_depth++;
	return 4255ULL;
x86_l_4fe:
	/* 0x4fe: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_501:
	/* 0x501: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_504:
	/* 0x504: jbe    50f <filter_file_buf+0xab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_50f;
	}
x86_l_506:
	/* 0x506: jmp    525 <filter_file_buf+0xc1> */
	goto x86_l_525;
x86_l_508:
	/* 0x508: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_50a:
	/* 0x50a: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_50d:
	/* 0x50d: ja     525 <filter_file_buf+0xc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_525;
	}
x86_l_50f:
	/* 0x50f: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_511:
	/* 0x511: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_51b:
	/* 0x51b: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_51f:
	/* 0x51f: jae    525 <filter_file_buf+0xc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_525;
	}
x86_l_521:
	/* 0x521: xor    rax,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 1ULL);
x86_l_525:
	/* 0x525: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_526:
	/* 0x526: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_527:
	/* 0x527: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_528:
	/* 0x528: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_52b:
	/* 0x52b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_52d:
	/* 0x52d: cmp    rcx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 32ULL);
x86_l_531:
	/* 0x531: ja     56c <filter_8ty+0x45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_56c;
	}
x86_l_533:
	/* 0x533: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_538:
	/* 0x538: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_53c:
	/* 0x53c: jae    545 <filter_8ty+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_545;
	}
x86_l_53e:
	/* 0x53e: call   1f89 <filter_8ty_selector_val> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 1347ULL);
	__x86_sim_call_depth++;
	return 8073ULL;
x86_l_543:
	/* 0x543: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_544:
	/* 0x544: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_545:
	/* 0x545: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_54a:
	/* 0x54a: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_54e:
	/* 0x54e: jb     567 <filter_8ty+0x40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_567;
	}
x86_l_550:
	/* 0x550: movabs rdx,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 6442450944ULL);
x86_l_55a:
	/* 0x55a: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_55e:
	/* 0x55e: jae    56c <filter_8ty+0x45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_56c;
	}
x86_l_560:
	/* 0x560: call   21a3 <filter_8ty_range> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 1381ULL);
	__x86_sim_call_depth++;
	return 8611ULL;
x86_l_565:
	/* 0x565: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_566:
	/* 0x566: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_567:
	/* 0x567: call   235b <filter_8ty_map> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 1388ULL);
	__x86_sim_call_depth++;
	return 9051ULL;
x86_l_56c:
	/* 0x56c: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_56d:
	/* 0x56d: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_56e:
	/* 0x56e: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_570:
	/* 0x570: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_572:
	/* 0x572: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_574:
	/* 0x574: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_575:
	/* 0x575: sub    rsp,0x48 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 72ULL);
x86_l_579:
	/* 0x579: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_582:
	/* 0x582: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_58b:
	/* 0x58b: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_594:
	/* 0x594: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_59d:
	/* 0x59d: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_5a6:
	/* 0x5a6: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5ad:
	/* 0x5ad: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_5b5:
	/* 0x5b5: mov    edx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_5b8:
	/* 0x5b8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5ba:
	/* 0x5ba: cmp    edx,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 39ULL);
x86_l_5bd:
	/* 0x5bd: jg     5d5 <filter_inet+0x67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_5d5;
	}
x86_l_5bf:
	/* 0x5bf: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_5c2:
	/* 0x5c2: je     65a <filter_inet+0xec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1626ULL;
	}
x86_l_5c8:
	/* 0x5c8: mov    r8,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_64);
x86_l_5cb:
	/* 0x5cb: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_5ce:
	/* 0x5ce: je     5e6 <filter_inet+0x78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5e6;
	}
x86_l_5d0:
	/* 0x5d0: jmp    86b <filter_inet+0x2fd> */
	return 2155ULL;
x86_l_5d5:
	/* 0x5d5: cmp    edx,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 40ULL);
x86_l_5d8:
	/* 0x5d8: je     632 <filter_inet+0xc4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1586ULL;
	}
x86_l_5da:
	/* 0x5da: mov    r8,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_64);
x86_l_5dd:
	/* 0x5dd: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_5e0:
	/* 0x5e0: jne    86b <filter_inet+0x2fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2155ULL;
	}
x86_l_5e6:
	/* 0x5e6: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5e9:
	/* 0x5e9: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5eb:
	/* 0x5eb: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_5ee:
	/* 0x5ee: jle    667 <filter_inet+0xf9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 1639ULL;
	}
x86_l_5f0:
	/* 0x5f0: cmp    ecx,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 23ULL);
x86_l_5f3:
	/* 0x5f3: jg     612 <filter_inet+0xa4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 1554ULL;
	}
	return 1525ULL;
}

static __noinline __u64 tetragon_bpf_generic_retuprobe_v61_generic_retuprobe_filter_arg_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1525ULL: goto x86_l_5f5;
	case 1528ULL: goto x86_l_5f8;
	case 1531ULL: goto x86_l_5fb;
	case 1537ULL: goto x86_l_601;
	case 1540ULL: goto x86_l_604;
	case 1543ULL: goto x86_l_607;
	case 1549ULL: goto x86_l_60d;
	case 1554ULL: goto x86_l_612;
	case 1557ULL: goto x86_l_615;
	case 1563ULL: goto x86_l_61b;
	case 1566ULL: goto x86_l_61e;
	case 1572ULL: goto x86_l_624;
	case 1575ULL: goto x86_l_627;
	case 1581ULL: goto x86_l_62d;
	case 1586ULL: goto x86_l_632;
	case 1589ULL: goto x86_l_635;
	case 1594ULL: goto x86_l_63a;
	case 1598ULL: goto x86_l_63e;
	case 1603ULL: goto x86_l_643;
	case 1607ULL: goto x86_l_647;
	case 1612ULL: goto x86_l_64c;
	case 1616ULL: goto x86_l_650;
	case 1621ULL: goto x86_l_655;
	case 1626ULL: goto x86_l_65a;
	case 1629ULL: goto x86_l_65d;
	case 1632ULL: goto x86_l_660;
	case 1634ULL: goto x86_l_662;
	case 1637ULL: goto x86_l_665;
	case 1639ULL: goto x86_l_667;
	case 1642ULL: goto x86_l_66a;
	case 1644ULL: goto x86_l_66c;
	case 1647ULL: goto x86_l_66f;
	case 1649ULL: goto x86_l_671;
	case 1652ULL: goto x86_l_674;
	case 1654ULL: goto x86_l_676;
	case 1657ULL: goto x86_l_679;
	case 1663ULL: goto x86_l_67f;
	case 1667ULL: goto x86_l_683;
	case 1672ULL: goto x86_l_688;
	case 1675ULL: goto x86_l_68b;
	case 1681ULL: goto x86_l_691;
	case 1684ULL: goto x86_l_694;
	case 1690ULL: goto x86_l_69a;
	case 1693ULL: goto x86_l_69d;
	case 1695ULL: goto x86_l_69f;
	case 1700ULL: goto x86_l_6a4;
	case 1703ULL: goto x86_l_6a7;
	case 1705ULL: goto x86_l_6a9;
	case 1708ULL: goto x86_l_6ac;
	case 1714ULL: goto x86_l_6b2;
	case 1718ULL: goto x86_l_6b6;
	case 1720ULL: goto x86_l_6b8;
	case 1724ULL: goto x86_l_6bc;
	case 1728ULL: goto x86_l_6c0;
	case 1730ULL: goto x86_l_6c2;
	case 1733ULL: goto x86_l_6c5;
	case 1736ULL: goto x86_l_6c8;
	case 1738ULL: goto x86_l_6ca;
	case 1741ULL: goto x86_l_6cd;
	case 1743ULL: goto x86_l_6cf;
	case 1746ULL: goto x86_l_6d2;
	case 1749ULL: goto x86_l_6d5;
	case 1755ULL: goto x86_l_6db;
	case 1758ULL: goto x86_l_6de;
	case 1761ULL: goto x86_l_6e1;
	case 1767ULL: goto x86_l_6e7;
	case 1770ULL: goto x86_l_6ea;
	case 1776ULL: goto x86_l_6f0;
	case 1781ULL: goto x86_l_6f5;
	case 1784ULL: goto x86_l_6f8;
	case 1790ULL: goto x86_l_6fe;
	case 1793ULL: goto x86_l_701;
	case 1799ULL: goto x86_l_707;
	case 1802ULL: goto x86_l_70a;
	case 1808ULL: goto x86_l_710;
	case 1811ULL: goto x86_l_713;
	case 1817ULL: goto x86_l_719;
	case 1822ULL: goto x86_l_71e;
	case 1826ULL: goto x86_l_722;
	case 1830ULL: goto x86_l_726;
	case 1832ULL: goto x86_l_728;
	case 1835ULL: goto x86_l_72b;
	case 1839ULL: goto x86_l_72f;
	case 1842ULL: goto x86_l_732;
	case 1846ULL: goto x86_l_736;
	case 1848ULL: goto x86_l_738;
	case 1850ULL: goto x86_l_73a;
	case 1853ULL: goto x86_l_73d;
	case 1855ULL: goto x86_l_73f;
	case 1858ULL: goto x86_l_742;
	case 1860ULL: goto x86_l_744;
	case 1866ULL: goto x86_l_74a;
	case 1870ULL: goto x86_l_74e;
	case 1872ULL: goto x86_l_750;
	case 1878ULL: goto x86_l_756;
	case 1882ULL: goto x86_l_75a;
	case 1884ULL: goto x86_l_75c;
	case 1889ULL: goto x86_l_761;
	case 1892ULL: goto x86_l_764;
	case 1894ULL: goto x86_l_766;
	case 1898ULL: goto x86_l_76a;
	case 1901ULL: goto x86_l_76d;
	case 1903ULL: goto x86_l_76f;
	case 1906ULL: goto x86_l_772;
	case 1912ULL: goto x86_l_778;
	case 1915ULL: goto x86_l_77b;
	case 1918ULL: goto x86_l_77e;
	case 1922ULL: goto x86_l_782;
	case 1929ULL: goto x86_l_789;
	case 1934ULL: goto x86_l_78e;
	case 1939ULL: goto x86_l_793;
	case 1941ULL: goto x86_l_795;
	case 1944ULL: goto x86_l_798;
	case 1950ULL: goto x86_l_79e;
	case 1953ULL: goto x86_l_7a1;
	case 1961ULL: goto x86_l_7a9;
	case 1965ULL: goto x86_l_7ad;
	case 1967ULL: goto x86_l_7af;
	case 1970ULL: goto x86_l_7b2;
	case 1973ULL: goto x86_l_7b5;
	case 1979ULL: goto x86_l_7bb;
	case 1984ULL: goto x86_l_7c0;
	case 1989ULL: goto x86_l_7c5;
	case 1991ULL: goto x86_l_7c7;
	case 1997ULL: goto x86_l_7cd;
	case 2000ULL: goto x86_l_7d0;
	case 2005ULL: goto x86_l_7d5;
	case 2007ULL: goto x86_l_7d7;
	case 2013ULL: goto x86_l_7dd;
	case 2016ULL: goto x86_l_7e0;
	case 2021ULL: goto x86_l_7e5;
	case 2024ULL: goto x86_l_7e8;
	case 2027ULL: goto x86_l_7eb;
	case 2031ULL: goto x86_l_7ef;
	case 2038ULL: goto x86_l_7f6;
	case 2043ULL: goto x86_l_7fb;
	case 2048ULL: goto x86_l_800;
	case 2050ULL: goto x86_l_802;
	case 2053ULL: goto x86_l_805;
	case 2055ULL: goto x86_l_807;
	case 2058ULL: goto x86_l_80a;
	case 2066ULL: goto x86_l_812;
	case 2070ULL: goto x86_l_816;
	case 2075ULL: goto x86_l_81b;
	case 2080ULL: goto x86_l_820;
	case 2084ULL: goto x86_l_824;
	case 2089ULL: goto x86_l_829;
	case 2094ULL: goto x86_l_82e;
	case 2099ULL: goto x86_l_833;
	case 2101ULL: goto x86_l_835;
	case 2106ULL: goto x86_l_83a;
	case 2109ULL: goto x86_l_83d;
	case 2112ULL: goto x86_l_840;
	case 2114ULL: goto x86_l_842;
	case 2117ULL: goto x86_l_845;
	case 2120ULL: goto x86_l_848;
	case 2122ULL: goto x86_l_84a;
	case 2125ULL: goto x86_l_84d;
	case 2128ULL: goto x86_l_850;
	case 2131ULL: goto x86_l_853;
	case 2133ULL: goto x86_l_855;
	case 2135ULL: goto x86_l_857;
	case 2138ULL: goto x86_l_85a;
	case 2140ULL: goto x86_l_85c;
	case 2144ULL: goto x86_l_860;
	case 2147ULL: goto x86_l_863;
	case 2150ULL: goto x86_l_866;
	case 2155ULL: goto x86_l_86b;
	case 2159ULL: goto x86_l_86f;
	case 2160ULL: goto x86_l_870;
	case 2162ULL: goto x86_l_872;
	case 2164ULL: goto x86_l_874;
	case 2166ULL: goto x86_l_876;
	case 2167ULL: goto x86_l_877;
	case 2172ULL: goto x86_l_87c;
	case 2175ULL: goto x86_l_87f;
	case 2178ULL: goto x86_l_882;
	case 2180ULL: goto x86_l_884;
	case 2183ULL: goto x86_l_887;
	case 2186ULL: goto x86_l_88a;
	case 2189ULL: goto x86_l_88d;
	case 2191ULL: goto x86_l_88f;
	case 2194ULL: goto x86_l_892;
	case 2196ULL: goto x86_l_894;
	case 2199ULL: goto x86_l_897;
	case 2201ULL: goto x86_l_899;
	case 2206ULL: goto x86_l_89e;
	case 2209ULL: goto x86_l_8a1;
	case 2212ULL: goto x86_l_8a4;
	case 2214ULL: goto x86_l_8a6;
	case 2217ULL: goto x86_l_8a9;
	case 2219ULL: goto x86_l_8ab;
	case 2221ULL: goto x86_l_8ad;
	case 2223ULL: goto x86_l_8af;
	case 2224ULL: goto x86_l_8b0;
	case 2228ULL: goto x86_l_8b4;
	case 2231ULL: goto x86_l_8b7;
	case 2235ULL: goto x86_l_8bb;
	case 2239ULL: goto x86_l_8bf;
	case 2243ULL: goto x86_l_8c3;
	case 2245ULL: goto x86_l_8c5;
	case 2249ULL: goto x86_l_8c9;
	case 2251ULL: goto x86_l_8cb;
	case 2255ULL: goto x86_l_8cf;
	case 2258ULL: goto x86_l_8d2;
	case 2260ULL: goto x86_l_8d4;
	case 2263ULL: goto x86_l_8d7;
	case 2268ULL: goto x86_l_8dc;
	case 2271ULL: goto x86_l_8df;
	case 2275ULL: goto x86_l_8e3;
	case 2277ULL: goto x86_l_8e5;
	case 2287ULL: goto x86_l_8ef;
	case 2291ULL: goto x86_l_8f3;
	case 2293ULL: goto x86_l_8f5;
	case 2297ULL: goto x86_l_8f9;
	case 2301ULL: goto x86_l_8fd;
	case 2302ULL: goto x86_l_8fe;
	case 2303ULL: goto x86_l_8ff;
	case 2307ULL: goto x86_l_903;
	case 2309ULL: goto x86_l_905;
	case 2313ULL: goto x86_l_909;
	case 2315ULL: goto x86_l_90b;
	case 2317ULL: goto x86_l_90d;
	case 2321ULL: goto x86_l_911;
	case 2323ULL: goto x86_l_913;
	case 2326ULL: goto x86_l_916;
	case 2329ULL: goto x86_l_919;
	case 2331ULL: goto x86_l_91b;
	case 2336ULL: goto x86_l_920;
	case 2339ULL: goto x86_l_923;
	case 2343ULL: goto x86_l_927;
	case 2345ULL: goto x86_l_929;
	case 2355ULL: goto x86_l_933;
	case 2359ULL: goto x86_l_937;
	case 2361ULL: goto x86_l_939;
	case 2365ULL: goto x86_l_93d;
	case 2369ULL: goto x86_l_941;
	case 2370ULL: goto x86_l_942;
	case 2371ULL: goto x86_l_943;
	case 2374ULL: goto x86_l_946;
	case 2378ULL: goto x86_l_94a;
	case 2383ULL: goto x86_l_94f;
	case 2388ULL: goto x86_l_954;
	case 2392ULL: goto x86_l_958;
	case 2393ULL: goto x86_l_959;
	case 2394ULL: goto x86_l_95a;
	case 2395ULL: goto x86_l_95b;
	case 2398ULL: goto x86_l_95e;
	case 2400ULL: goto x86_l_960;
	case 2404ULL: goto x86_l_964;
	case 2406ULL: goto x86_l_966;
	case 2411ULL: goto x86_l_96b;
	case 2415ULL: goto x86_l_96f;
	case 2417ULL: goto x86_l_971;
	case 2422ULL: goto x86_l_976;
	case 2423ULL: goto x86_l_977;
	case 2424ULL: goto x86_l_978;
	case 2429ULL: goto x86_l_97d;
	case 2433ULL: goto x86_l_981;
	case 2435ULL: goto x86_l_983;
	case 2445ULL: goto x86_l_98d;
	case 2449ULL: goto x86_l_991;
	case 2451ULL: goto x86_l_993;
	case 2456ULL: goto x86_l_998;
	case 2457ULL: goto x86_l_999;
	case 2458ULL: goto x86_l_99a;
	case 2463ULL: goto x86_l_99f;
	case 2464ULL: goto x86_l_9a0;
	case 2465ULL: goto x86_l_9a1;
	case 2466ULL: goto x86_l_9a2;
	case 2469ULL: goto x86_l_9a5;
	case 2471ULL: goto x86_l_9a7;
	case 2475ULL: goto x86_l_9ab;
	case 2477ULL: goto x86_l_9ad;
	case 2482ULL: goto x86_l_9b2;
	case 2486ULL: goto x86_l_9b6;
	case 2488ULL: goto x86_l_9b8;
	case 2493ULL: goto x86_l_9bd;
	case 2494ULL: goto x86_l_9be;
	case 2495ULL: goto x86_l_9bf;
	case 2500ULL: goto x86_l_9c4;
	case 2504ULL: goto x86_l_9c8;
	case 2506ULL: goto x86_l_9ca;
	case 2516ULL: goto x86_l_9d4;
	case 2520ULL: goto x86_l_9d8;
	case 2522ULL: goto x86_l_9da;
	case 2527ULL: goto x86_l_9df;
	case 2528ULL: goto x86_l_9e0;
	case 2529ULL: goto x86_l_9e1;
	case 2534ULL: goto x86_l_9e6;
	case 2535ULL: goto x86_l_9e7;
	case 2536ULL: goto x86_l_9e8;
	case 2537ULL: goto x86_l_9e9;
	case 2540ULL: goto x86_l_9ec;
	case 2543ULL: goto x86_l_9ef;
	case 2546ULL: goto x86_l_9f2;
	case 2550ULL: goto x86_l_9f6;
	case 2552ULL: goto x86_l_9f8;
	case 2555ULL: goto x86_l_9fb;
	case 2558ULL: goto x86_l_9fe;
	case 2560ULL: goto x86_l_a00;
	case 2563ULL: goto x86_l_a03;
	case 2565ULL: goto x86_l_a05;
	case 2568ULL: goto x86_l_a08;
	case 2571ULL: goto x86_l_a0b;
	case 2573ULL: goto x86_l_a0d;
	case 2576ULL: goto x86_l_a10;
	case 2578ULL: goto x86_l_a12;
	case 2581ULL: goto x86_l_a15;
	case 2583ULL: goto x86_l_a17;
	case 2585ULL: goto x86_l_a19;
	case 2588ULL: goto x86_l_a1c;
	case 2590ULL: goto x86_l_a1e;
	case 2593ULL: goto x86_l_a21;
	case 2595ULL: goto x86_l_a23;
	case 2598ULL: goto x86_l_a26;
	case 2600ULL: goto x86_l_a28;
	case 2603ULL: goto x86_l_a2b;
	case 2608ULL: goto x86_l_a30;
	case 2610ULL: goto x86_l_a32;
	case 2613ULL: goto x86_l_a35;
	case 2615ULL: goto x86_l_a37;
	case 2618ULL: goto x86_l_a3a;
	case 2620ULL: goto x86_l_a3c;
	case 2623ULL: goto x86_l_a3f;
	case 2628ULL: goto x86_l_a44;
	case 2630ULL: goto x86_l_a46;
	case 2633ULL: goto x86_l_a49;
	case 2638ULL: goto x86_l_a4e;
	case 2640ULL: goto x86_l_a50;
	case 2643ULL: goto x86_l_a53;
	case 2648ULL: goto x86_l_a58;
	case 2650ULL: goto x86_l_a5a;
	case 2653ULL: goto x86_l_a5d;
	case 2655ULL: goto x86_l_a5f;
	case 2660ULL: goto x86_l_a64;
	case 2663ULL: goto x86_l_a67;
	case 2666ULL: goto x86_l_a6a;
	case 2668ULL: goto x86_l_a6c;
	case 2670ULL: goto x86_l_a6e;
	case 2680ULL: goto x86_l_a78;
	case 2684ULL: goto x86_l_a7c;
	case 2686ULL: goto x86_l_a7e;
	case 2688ULL: goto x86_l_a80;
	case 2691ULL: goto x86_l_a83;
	case 2694ULL: goto x86_l_a86;
	case 2697ULL: goto x86_l_a89;
	case 2698ULL: goto x86_l_a8a;
	case 2699ULL: goto x86_l_a8b;
	case 2700ULL: goto x86_l_a8c;
	case 2703ULL: goto x86_l_a8f;
	case 2705ULL: goto x86_l_a91;
	case 2709ULL: goto x86_l_a95;
	case 2711ULL: goto x86_l_a97;
	case 2716ULL: goto x86_l_a9c;
	case 2720ULL: goto x86_l_aa0;
	case 2722ULL: goto x86_l_aa2;
	case 2727ULL: goto x86_l_aa7;
	case 2728ULL: goto x86_l_aa8;
	case 2729ULL: goto x86_l_aa9;
	case 2734ULL: goto x86_l_aae;
	case 2738ULL: goto x86_l_ab2;
	case 2740ULL: goto x86_l_ab4;
	case 2750ULL: goto x86_l_abe;
	case 2754ULL: goto x86_l_ac2;
	case 2756ULL: goto x86_l_ac4;
	case 2761ULL: goto x86_l_ac9;
	case 2762ULL: goto x86_l_aca;
	case 2763ULL: goto x86_l_acb;
	case 2768ULL: goto x86_l_ad0;
	case 2769ULL: goto x86_l_ad1;
	case 2770ULL: goto x86_l_ad2;
	case 2773ULL: goto x86_l_ad5;
	case 2778ULL: goto x86_l_ada;
	case 2782ULL: goto x86_l_ade;
	case 2784ULL: goto x86_l_ae0;
	case 2794ULL: goto x86_l_aea;
	case 2798ULL: goto x86_l_aee;
	case 2800ULL: goto x86_l_af0;
	case 2801ULL: goto x86_l_af1;
	case 2806ULL: goto x86_l_af6;
	case 2810ULL: goto x86_l_afa;
	case 2812ULL: goto x86_l_afc;
	case 2815ULL: goto x86_l_aff;
	default: return 0xffffffffffffffffULL;
	}
x86_l_5f5:
	/* 0x5f5: lea    edx,[rcx-0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551596ULL);
x86_l_5f8:
	/* 0x5f8: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_5fb:
	/* 0x5fb: jb     6b8 <filter_inet+0x14a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_6b8;
	}
x86_l_601:
	/* 0x601: lea    edx,[rcx-0x16] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_604:
	/* 0x604: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_607:
	/* 0x607: jb     6b2 <filter_inet+0x144> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_6b2;
	}
x86_l_60d:
	/* 0x60d: jmp    86b <filter_inet+0x2fd> */
	goto x86_l_86b;
x86_l_612:
	/* 0x612: cmp    ecx,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 27ULL);
x86_l_615:
	/* 0x615: jg     6f5 <filter_inet+0x187> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_6f5;
	}
x86_l_61b:
	/* 0x61b: cmp    ecx,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 24ULL);
x86_l_61e:
	/* 0x61e: je     728 <filter_inet+0x1ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_728;
	}
x86_l_624:
	/* 0x624: cmp    ecx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 25ULL);
x86_l_627:
	/* 0x627: je     71e <filter_inet+0x1b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_71e;
	}
x86_l_62d:
	/* 0x62d: jmp    86b <filter_inet+0x2fd> */
	goto x86_l_86b;
x86_l_632:
	/* 0x632: movzx  eax,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_635:
	/* 0x635: mov    WORD PTR [rsp+0x46],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 70ULL);
x86_l_63a:
	/* 0x63a: movzx  eax,WORD PTR [rsi+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_63e:
	/* 0x63e: mov    WORD PTR [rsp+0x40],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_643:
	/* 0x643: mov    rax,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_647:
	/* 0x647: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_64c:
	/* 0x64c: mov    rax,QWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_650:
	/* 0x650: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_655:
	/* 0x655: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_65a:
	/* 0x65a: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_65d:
	/* 0x65d: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_660:
	/* 0x660: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_662:
	/* 0x662: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_665:
	/* 0x665: jg     5f0 <filter_inet+0x82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 1520ULL;
	}
x86_l_667:
	/* 0x667: cmp    ecx,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 15ULL);
x86_l_66a:
	/* 0x66a: jle    688 <filter_inet+0x11a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_688;
	}
x86_l_66c:
	/* 0x66c: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_66f:
	/* 0x66f: jg     6a4 <filter_inet+0x136> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_6a4;
	}
x86_l_671:
	/* 0x671: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_674:
	/* 0x674: je     6b2 <filter_inet+0x144> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6b2;
	}
x86_l_676:
	/* 0x676: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_679:
	/* 0x679: jne    86b <filter_inet+0x2fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_86b;
	}
x86_l_67f:
	/* 0x67f: movzx  eax,WORD PTR [rsi+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_683:
	/* 0x683: jmp    860 <filter_inet+0x2f2> */
	goto x86_l_860;
x86_l_688:
	/* 0x688: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_68b:
	/* 0x68b: je     728 <filter_inet+0x1ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_728;
	}
x86_l_691:
	/* 0x691: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_694:
	/* 0x694: je     71e <filter_inet+0x1b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_71e;
	}
x86_l_69a:
	/* 0x69a: cmp    ecx,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 15ULL);
x86_l_69d:
	/* 0x69d: je     6b8 <filter_inet+0x14a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6b8;
	}
x86_l_69f:
	/* 0x69f: jmp    86b <filter_inet+0x2fd> */
	goto x86_l_86b;
x86_l_6a4:
	/* 0x6a4: cmp    ecx,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 18ULL);
x86_l_6a7:
	/* 0x6a7: je     6b8 <filter_inet+0x14a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6b8;
	}
x86_l_6a9:
	/* 0x6a9: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_6ac:
	/* 0x6ac: jne    86b <filter_inet+0x2fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_86b;
	}
x86_l_6b2:
	/* 0x6b2: movzx  edx,WORD PTR [rsi+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_6b6:
	/* 0x6b6: jmp    6bc <filter_inet+0x14e> */
	goto x86_l_6bc;
x86_l_6b8:
	/* 0x6b8: movzx  edx,WORD PTR [rsi+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_6bc:
	/* 0x6bc: mov    DWORD PTR [rsp+0x4],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_6c0:
	/* 0x6c0: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6c2:
	/* 0x6c2: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6c5:
	/* 0x6c5: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6c8:
	/* 0x6c8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6ca:
	/* 0x6ca: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_6cd:
	/* 0x6cd: jg     73f <filter_inet+0x1d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_73f;
	}
x86_l_6cf:
	/* 0x6cf: lea    edx,[rcx-0xd] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551603ULL);
x86_l_6d2:
	/* 0x6d2: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_6d5:
	/* 0x6d5: jb     766 <filter_inet+0x1f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_766;
	}
x86_l_6db:
	/* 0x6db: lea    edx,[rcx-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_6de:
	/* 0x6de: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_6e1:
	/* 0x6e1: jb     7bb <filter_inet+0x24d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_7bb;
	}
x86_l_6e7:
	/* 0x6e7: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_6ea:
	/* 0x6ea: je     863 <filter_inet+0x2f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_863;
	}
x86_l_6f0:
	/* 0x6f0: jmp    86b <filter_inet+0x2fd> */
	goto x86_l_86b;
x86_l_6f5:
	/* 0x6f5: cmp    ecx,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 28ULL);
x86_l_6f8:
	/* 0x6f8: je     85c <filter_inet+0x2ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_85c;
	}
x86_l_6fe:
	/* 0x6fe: cmp    ecx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 29ULL);
x86_l_701:
	/* 0x701: jne    86b <filter_inet+0x2fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_86b;
	}
x86_l_707:
	/* 0x707: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_70a:
	/* 0x70a: jne    88f <filter_inet+0x321> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_88f;
	}
x86_l_710:
	/* 0x710: test   r8,r8 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_64);
x86_l_713:
	/* 0x713: jne    899 <filter_inet+0x32b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_899;
	}
x86_l_719:
	/* 0x719: jmp    863 <filter_inet+0x2f5> */
	goto x86_l_863;
x86_l_71e:
	/* 0x71e: mov    rbx,QWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_722:
	/* 0x722: mov    r14,QWORD PTR [rsi+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_726:
	/* 0x726: jmp    72f <filter_inet+0x1c1> */
	goto x86_l_72f;
x86_l_728:
	/* 0x728: mov    rbx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_72b:
	/* 0x72b: mov    r14,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_72f:
	/* 0x72f: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_732:
	/* 0x732: shr    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_736:
	/* 0x736: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_738:
	/* 0x738: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_73a:
	/* 0x73a: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_73d:
	/* 0x73d: jle    6cf <filter_inet+0x161> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_6cf;
	}
x86_l_73f:
	/* 0x73f: cmp    ecx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 25ULL);
x86_l_742:
	/* 0x742: ja     7af <filter_inet+0x241> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_7af;
	}
x86_l_744:
	/* 0x744: mov    r8d,0x500000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5242880ULL);
x86_l_74a:
	/* 0x74a: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_74e:
	/* 0x74e: jb     7c5 <filter_inet+0x257> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_7c5;
	}
x86_l_750:
	/* 0x750: mov    r8d,0xa00000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 10485760ULL);
x86_l_756:
	/* 0x756: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_75a:
	/* 0x75a: jb     7d5 <filter_inet+0x267> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_7d5;
	}
x86_l_75c:
	/* 0x75c: mov    edx,0x3000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 50331648ULL);
x86_l_761:
	/* 0x761: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_764:
	/* 0x764: jae    7af <filter_inet+0x241> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_7af;
	}
x86_l_766:
	/* 0x766: movzx  eax,WORD PTR [rsi+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_76a:
	/* 0x76a: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_76d:
	/* 0x76d: je     7e5 <filter_inet+0x277> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7e5;
	}
x86_l_76f:
	/* 0x76f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_772:
	/* 0x772: jne    855 <filter_inet+0x2e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_855;
	}
x86_l_778:
	/* 0x778: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_77b:
	/* 0x77b: mov    eax,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_77e:
	/* 0x77e: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_782:
	/* 0x782: mov    rdi,QWORD PTR [rip+0x1660] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr4lpm_maps)));
x86_l_789:
	/* 0x789: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_78e:
	/* 0x78e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_793:
	/* 0x793: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_795:
	/* 0x795: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_798:
	/* 0x798: je     877 <filter_inet+0x309> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_877;
	}
x86_l_79e:
	/* 0x79e: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_7a1:
	/* 0x7a1: mov    DWORD PTR [rsp+0xc],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607584ULL);
x86_l_7a9:
	/* 0x7a9: mov    DWORD PTR [rsp+0x10],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7ad:
	/* 0x7ad: jmp    829 <filter_inet+0x2bb> */
	goto x86_l_829;
x86_l_7af:
	/* 0x7af: add    ecx,0xffffffee */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 4294967278ULL);
x86_l_7b2:
	/* 0x7b2: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_7b5:
	/* 0x7b5: jae    86b <filter_inet+0x2fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_86b;
	}
x86_l_7bb:
	/* 0x7bb: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_7c0:
	/* 0x7c0: jmp    866 <filter_inet+0x2f8> */
	goto x86_l_866;
x86_l_7c5:
	/* 0x7c5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7c7:
	/* 0x7c7: cmp    edx,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1024ULL);
x86_l_7cd:
	/* 0x7cd: setb   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_B);
x86_l_7d0:
	/* 0x7d0: jmp    86b <filter_inet+0x2fd> */
	goto x86_l_86b;
x86_l_7d5:
	/* 0x7d5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7d7:
	/* 0x7d7: cmp    edx,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1024ULL);
x86_l_7dd:
	/* 0x7dd: setae  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_AE);
x86_l_7e0:
	/* 0x7e0: jmp    86b <filter_inet+0x2fd> */
	goto x86_l_86b;
x86_l_7e5:
	/* 0x7e5: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_7e8:
	/* 0x7e8: mov    eax,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_7eb:
	/* 0x7eb: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7ef:
	/* 0x7ef: mov    rdi,QWORD PTR [rip+0x1660] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr6lpm_maps)));
x86_l_7f6:
	/* 0x7f6: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7fb:
	/* 0x7fb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_800:
	/* 0x800: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_802:
	/* 0x802: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_805:
	/* 0x805: je     877 <filter_inet+0x309> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_877;
	}
x86_l_807:
	/* 0x807: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_80a:
	/* 0x80a: mov    DWORD PTR [rsp+0xc],0x80 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607680ULL);
x86_l_812:
	/* 0x812: mov    DWORD PTR [rsp+0x10],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_816:
	/* 0x816: mov    DWORD PTR [rsp+0x14],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_81b:
	/* 0x81b: mov    DWORD PTR [rsp+0x18],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_820:
	/* 0x820: shr    r14,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_824:
	/* 0x824: mov    DWORD PTR [rsp+0x1c],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_829:
	/* 0x829: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_82e:
	/* 0x82e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_833:
	/* 0x833: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_835:
	/* 0x835: mov    ecx,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_83a:
	/* 0x83a: lea    edx,[rcx-0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551592ULL);
x86_l_83d:
	/* 0x83d: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_840:
	/* 0x840: jb     884 <filter_inet+0x316> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_884;
	}
x86_l_842:
	/* 0x842: add    ecx,0xfffffff3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 4294967283ULL);
x86_l_845:
	/* 0x845: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_848:
	/* 0x848: ja     855 <filter_inet+0x2e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_855;
	}
x86_l_84a:
	/* 0x84a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_84d:
	/* 0x84d: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_850:
	/* 0x850: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_853:
	/* 0x853: jmp    86b <filter_inet+0x2fd> */
	goto x86_l_86b;
x86_l_855:
	/* 0x855: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_857:
	/* 0x857: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_85a:
	/* 0x85a: jmp    86b <filter_inet+0x2fd> */
	goto x86_l_86b;
x86_l_85c:
	/* 0x85c: movzx  eax,WORD PTR [rsi+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_860:
	/* 0x860: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_863:
	/* 0x863: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_866:
	/* 0x866: call   1f04 <filter_32ty_map> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2155ULL);
	__x86_sim_call_depth++;
	return 7940ULL;
x86_l_86b:
	/* 0x86b: add    rsp,0x48 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 72ULL);
x86_l_86f:
	/* 0x86f: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_870:
	/* 0x870: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_872:
	/* 0x872: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_874:
	/* 0x874: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_876:
	/* 0x876: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_877:
	/* 0x877: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_87c:
	/* 0x87c: and    eax,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_87f:
	/* 0x87f: cmp    eax,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_882:
	/* 0x882: jmp    887 <filter_inet+0x319> */
	goto x86_l_887;
x86_l_884:
	/* 0x884: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_887:
	/* 0x887: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_88a:
	/* 0x88a: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_88d:
	/* 0x88d: jmp    86b <filter_inet+0x2fd> */
	goto x86_l_86b;
x86_l_88f:
	/* 0x88f: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_892:
	/* 0x892: jne    8a1 <filter_inet+0x333> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8a1;
	}
x86_l_894:
	/* 0x894: test   r8,r8 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_64);
x86_l_897:
	/* 0x897: je     8a1 <filter_inet+0x333> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8a1;
	}
x86_l_899:
	/* 0x899: movzx  eax,BYTE PTR [r8+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 58ULL);
x86_l_89e:
	/* 0x89e: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8a1:
	/* 0x8a1: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_8a4:
	/* 0x8a4: je     863 <filter_inet+0x2f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_863;
	}
x86_l_8a6:
	/* 0x8a6: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_8a9:
	/* 0x8a9: je     863 <filter_inet+0x2f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_863;
	}
x86_l_8ab:
	/* 0x8ab: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8ad:
	/* 0x8ad: jmp    86b <filter_inet+0x2fd> */
	goto x86_l_86b;
x86_l_8af:
	/* 0x8af: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_8b0:
	/* 0x8b0: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_8b4:
	/* 0x8b4: mov    rcx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_64);
x86_l_8b7:
	/* 0x8b7: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_8bb:
	/* 0x8bb: movzx  edx,BYTE PTR [rcx+0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 3ULL);
x86_l_8bf:
	/* 0x8bf: mov    r8d,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_8c3:
	/* 0x8c3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8c5:
	/* 0x8c5: cmp    r8d,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 25ULL);
x86_l_8c9:
	/* 0x8c9: jg     8ff <filter_sockaddr_un+0x50> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_8ff;
	}
x86_l_8cb:
	/* 0x8cb: lea    ecx,[r8-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_8cf:
	/* 0x8cf: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_8d2:
	/* 0x8d2: jae    90d <filter_sockaddr_un+0x5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_90d;
	}
x86_l_8d4:
	/* 0x8d4: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_8d7:
	/* 0x8d7: call   113f <filter_char_buf_equal> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2268ULL);
	__x86_sim_call_depth++;
	return 4415ULL;
x86_l_8dc:
	/* 0x8dc: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_8df:
	/* 0x8df: cmp    rcx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 37ULL);
x86_l_8e3:
	/* 0x8e3: ja     8f9 <filter_sockaddr_un+0x4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_8f9;
	}
x86_l_8e5:
	/* 0x8e5: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_8ef:
	/* 0x8ef: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_8f3:
	/* 0x8f3: jae    8f9 <filter_sockaddr_un+0x4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_8f9;
	}
x86_l_8f5:
	/* 0x8f5: xor    rax,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 1ULL);
x86_l_8f9:
	/* 0x8f9: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_8fd:
	/* 0x8fd: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_8fe:
	/* 0x8fe: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_8ff:
	/* 0x8ff: cmp    r8d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 28ULL);
x86_l_903:
	/* 0x903: je     943 <filter_sockaddr_un+0x94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_943;
	}
x86_l_905:
	/* 0x905: cmp    r8d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 26ULL);
x86_l_909:
	/* 0x909: je     913 <filter_sockaddr_un+0x64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_913;
	}
x86_l_90b:
	/* 0x90b: jmp    8f9 <filter_sockaddr_un+0x4a> */
	goto x86_l_8f9;
x86_l_90d:
	/* 0x90d: cmp    r8d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 8ULL);
x86_l_911:
	/* 0x911: jne    8f9 <filter_sockaddr_un+0x4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8f9;
	}
x86_l_913:
	/* 0x913: mov    eax,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_916:
	/* 0x916: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_919:
	/* 0x919: mov    edi,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_91b:
	/* 0x91b: call   109f <filter_char_buf_prefix> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2336ULL);
	__x86_sim_call_depth++;
	return 4255ULL;
x86_l_920:
	/* 0x920: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_923:
	/* 0x923: cmp    rcx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 37ULL);
x86_l_927:
	/* 0x927: ja     8f9 <filter_sockaddr_un+0x4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_8f9;
	}
x86_l_929:
	/* 0x929: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_933:
	/* 0x933: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_937:
	/* 0x937: jae    8f9 <filter_sockaddr_un+0x4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_8f9;
	}
x86_l_939:
	/* 0x939: xor    rax,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 1ULL);
x86_l_93d:
	/* 0x93d: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_941:
	/* 0x941: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_942:
	/* 0x942: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_943:
	/* 0x943: movzx  eax,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_946:
	/* 0x946: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_94a:
	/* 0x94a: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_94f:
	/* 0x94f: call   1f04 <filter_32ty_map> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2388ULL);
	__x86_sim_call_depth++;
	return 7940ULL;
x86_l_954:
	/* 0x954: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_958:
	/* 0x958: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_959:
	/* 0x959: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_95a:
	/* 0x95a: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_95b:
	/* 0x95b: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_95e:
	/* 0x95e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_960:
	/* 0x960: cmp    rcx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 32ULL);
x86_l_964:
	/* 0x964: ja     99f <filter_32ty+0x45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_99f;
	}
x86_l_966:
	/* 0x966: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_96b:
	/* 0x96b: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_96f:
	/* 0x96f: jae    978 <filter_32ty+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_978;
	}
x86_l_971:
	/* 0x971: call   1b3a <filter_32ty_selector_val> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2422ULL);
	__x86_sim_call_depth++;
	return 6970ULL;
x86_l_976:
	/* 0x976: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_977:
	/* 0x977: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_978:
	/* 0x978: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_97d:
	/* 0x97d: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_981:
	/* 0x981: jb     99a <filter_32ty+0x40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_99a;
	}
x86_l_983:
	/* 0x983: movabs rdx,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 6442450944ULL);
x86_l_98d:
	/* 0x98d: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_991:
	/* 0x991: jae    99f <filter_32ty+0x45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_99f;
	}
x86_l_993:
	/* 0x993: call   1d4e <filter_32ty_range> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2456ULL);
	__x86_sim_call_depth++;
	return 7502ULL;
x86_l_998:
	/* 0x998: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_999:
	/* 0x999: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_99a:
	/* 0x99a: call   1f04 <filter_32ty_map> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2463ULL);
	__x86_sim_call_depth++;
	return 7940ULL;
x86_l_99f:
	/* 0x99f: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_9a0:
	/* 0x9a0: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_9a1:
	/* 0x9a1: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_9a2:
	/* 0x9a2: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_9a5:
	/* 0x9a5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9a7:
	/* 0x9a7: cmp    rcx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 32ULL);
x86_l_9ab:
	/* 0x9ab: ja     9e6 <filter_16ty+0x45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_9e6;
	}
x86_l_9ad:
	/* 0x9ad: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_9b2:
	/* 0x9b2: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_9b6:
	/* 0x9b6: jae    9bf <filter_16ty+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_9bf;
	}
x86_l_9b8:
	/* 0x9b8: call   16e2 <filter_16ty_selector_val> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2493ULL);
	__x86_sim_call_depth++;
	return 5858ULL;
x86_l_9bd:
	/* 0x9bd: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_9be:
	/* 0x9be: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_9bf:
	/* 0x9bf: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_9c4:
	/* 0x9c4: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_9c8:
	/* 0x9c8: jb     9e1 <filter_16ty+0x40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_9e1;
	}
x86_l_9ca:
	/* 0x9ca: movabs rdx,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 6442450944ULL);
x86_l_9d4:
	/* 0x9d4: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_9d8:
	/* 0x9d8: jae    9e6 <filter_16ty+0x45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_9e6;
	}
x86_l_9da:
	/* 0x9da: call   18fc <filter_16ty_range> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2527ULL);
	__x86_sim_call_depth++;
	return 6396ULL;
x86_l_9df:
	/* 0x9df: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_9e0:
	/* 0x9e0: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_9e1:
	/* 0x9e1: call   1ab4 <filter_16ty_map> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2534ULL);
	__x86_sim_call_depth++;
	return 6836ULL;
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
	/* 0x9e8: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_9e9:
	/* 0x9e9: mov    rax,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_9ec:
	/* 0x9ec: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_9ef:
	/* 0x9ef: movsxd rcx,edx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_9f2:
	/* 0x9f2: mov    edx,DWORD PTR [rsi+rcx*1-0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 18446744073709551612ULL);
x86_l_9f6:
	/* 0x9f6: mov    esi,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_9f8:
	/* 0x9f8: add    rsi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_9fb:
	/* 0x9fb: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_9fe:
	/* 0x9fe: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a00:
	/* 0xa00: cmp    ecx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 25ULL);
x86_l_a03:
	/* 0xa03: jg     a19 <filter_char_buf+0x31> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_a19;
	}
x86_l_a05:
	/* 0xa05: lea    edi,[rcx-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_a08:
	/* 0xa08: cmp    edi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_a0b:
	/* 0xa0b: jb     a50 <filter_char_buf+0x68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_a50;
	}
x86_l_a0d:
	/* 0xa0d: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a10:
	/* 0xa10: je     a46 <filter_char_buf+0x5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a46;
	}
x86_l_a12:
	/* 0xa12: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_a15:
	/* 0xa15: je     a28 <filter_char_buf+0x40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a28;
	}
x86_l_a17:
	/* 0xa17: jmp    a67 <filter_char_buf+0x7f> */
	goto x86_l_a67;
x86_l_a19:
	/* 0xa19: cmp    ecx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 32ULL);
x86_l_a1c:
	/* 0xa1c: jg     a32 <filter_char_buf+0x4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_a32;
	}
x86_l_a1e:
	/* 0xa1e: cmp    ecx,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 26ULL);
x86_l_a21:
	/* 0xa21: je     a46 <filter_char_buf+0x5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a46;
	}
x86_l_a23:
	/* 0xa23: cmp    ecx,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 27ULL);
x86_l_a26:
	/* 0xa26: jne    a67 <filter_char_buf+0x7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_a67;
	}
x86_l_a28:
	/* 0xa28: mov    edi,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a2b:
	/* 0xa2b: call   f57 <filter_char_buf_postfix> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2608ULL);
	__x86_sim_call_depth++;
	return 3927ULL;
x86_l_a30:
	/* 0xa30: jmp    a64 <filter_char_buf+0x7c> */
	goto x86_l_a64;
x86_l_a32:
	/* 0xa32: cmp    ecx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 33ULL);
x86_l_a35:
	/* 0xa35: je     a5a <filter_char_buf+0x72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a5a;
	}
x86_l_a37:
	/* 0xa37: cmp    ecx,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 34ULL);
x86_l_a3a:
	/* 0xa3a: jne    a67 <filter_char_buf+0x7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_a67;
	}
x86_l_a3c:
	/* 0xa3c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_a3f:
	/* 0xa3f: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_a44:
	/* 0xa44: jmp    a5f <filter_char_buf+0x77> */
	goto x86_l_a5f;
x86_l_a46:
	/* 0xa46: mov    edi,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a49:
	/* 0xa49: call   109f <filter_char_buf_prefix> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2638ULL);
	__x86_sim_call_depth++;
	return 4255ULL;
x86_l_a4e:
	/* 0xa4e: jmp    a64 <filter_char_buf+0x7c> */
	goto x86_l_a64;
x86_l_a50:
	/* 0xa50: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_a53:
	/* 0xa53: call   113f <filter_char_buf_equal> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2648ULL);
	__x86_sim_call_depth++;
	return 4415ULL;
x86_l_a58:
	/* 0xa58: jmp    a64 <filter_char_buf+0x7c> */
	goto x86_l_a64;
x86_l_a5a:
	/* 0xa5a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_a5d:
	/* 0xa5d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a5f:
	/* 0xa5f: call   14cc <filter_char_substring> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2660ULL);
	__x86_sim_call_depth++;
	return 5324ULL;
x86_l_a64:
	/* 0xa64: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_a67:
	/* 0xa67: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_a6a:
	/* 0xa6a: ja     a89 <filter_char_buf+0xa1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_a89;
	}
x86_l_a6c:
	/* 0xa6c: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_a6e:
	/* 0xa6e: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_a78:
	/* 0xa78: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_a7c:
	/* 0xa7c: jae    a89 <filter_char_buf+0xa1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_a89;
	}
x86_l_a7e:
	/* 0xa7e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a80:
	/* 0xa80: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a83:
	/* 0xa83: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_a86:
	/* 0xa86: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_a89:
	/* 0xa89: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_a8a:
	/* 0xa8a: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_a8b:
	/* 0xa8b: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_a8c:
	/* 0xa8c: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_a8f:
	/* 0xa8f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a91:
	/* 0xa91: cmp    rcx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 32ULL);
x86_l_a95:
	/* 0xa95: ja     ad0 <filter_64ty+0x45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_ad0;
	}
x86_l_a97:
	/* 0xa97: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_a9c:
	/* 0xa9c: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_aa0:
	/* 0xaa0: jae    aa9 <filter_64ty+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_aa9;
	}
x86_l_aa2:
	/* 0xaa2: call   ad2 <filter_64ty_selector_val> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2727ULL);
	__x86_sim_call_depth++;
	goto x86_l_ad2;
x86_l_aa7:
	/* 0xaa7: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_aa8:
	/* 0xaa8: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_aa9:
	/* 0xaa9: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_aae:
	/* 0xaae: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_ab2:
	/* 0xab2: jb     acb <filter_64ty+0x40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_acb;
	}
x86_l_ab4:
	/* 0xab4: movabs rdx,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 6442450944ULL);
x86_l_abe:
	/* 0xabe: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_ac2:
	/* 0xac2: jae    ad0 <filter_64ty+0x45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_ad0;
	}
x86_l_ac4:
	/* 0xac4: call   d04 <filter_64ty_range> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2761ULL);
	__x86_sim_call_depth++;
	return 3332ULL;
x86_l_ac9:
	/* 0xac9: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_aca:
	/* 0xaca: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_acb:
	/* 0xacb: call   edf <filter_64ty_map> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2768ULL);
	__x86_sim_call_depth++;
	return 3807ULL;
x86_l_ad0:
	/* 0xad0: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_ad1:
	/* 0xad1: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_ad2:
	/* 0xad2: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ad5:
	/* 0xad5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ada:
	/* 0xada: cmp    rcx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 37ULL);
x86_l_ade:
	/* 0xade: ja     b56 <filter_64ty_selector_val+0x84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2902ULL;
	}
x86_l_ae0:
	/* 0xae0: movabs rdx,0x200c000040 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280128ULL);
x86_l_aea:
	/* 0xaea: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_aee:
	/* 0xaee: jae    af1 <filter_64ty_selector_val+0x1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_af1;
	}
x86_l_af0:
	/* 0xaf0: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_af1:
	/* 0xaf1: mov    edx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 24ULL);
x86_l_af6:
	/* 0xaf6: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_afa:
	/* 0xafa: jae    b12 <filter_64ty_selector_val+0x40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 2834ULL;
	}
x86_l_afc:
	/* 0xafc: mov    rdx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_aff:
	/* 0xaff: cmp    rdx,QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
	return 2819ULL;
}

static __noinline __u64 tetragon_bpf_generic_retuprobe_v61_generic_retuprobe_filter_arg_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 2819ULL: goto x86_l_b03;
	case 2825ULL: goto x86_l_b09;
	case 2827ULL: goto x86_l_b0b;
	case 2830ULL: goto x86_l_b0e;
	case 2833ULL: goto x86_l_b11;
	case 2834ULL: goto x86_l_b12;
	case 2838ULL: goto x86_l_b16;
	case 2840ULL: goto x86_l_b18;
	case 2843ULL: goto x86_l_b1b;
	case 2847ULL: goto x86_l_b1f;
	case 2849ULL: goto x86_l_b21;
	case 2852ULL: goto x86_l_b24;
	case 2855ULL: goto x86_l_b27;
	case 2861ULL: goto x86_l_b2d;
	case 2865ULL: goto x86_l_b31;
	case 2867ULL: goto x86_l_b33;
	case 2870ULL: goto x86_l_b36;
	case 2876ULL: goto x86_l_b3c;
	case 2880ULL: goto x86_l_b40;
	case 2882ULL: goto x86_l_b42;
	case 2885ULL: goto x86_l_b45;
	case 2891ULL: goto x86_l_b4b;
	case 2895ULL: goto x86_l_b4f;
	case 2897ULL: goto x86_l_b51;
	case 2902ULL: goto x86_l_b56;
	case 2905ULL: goto x86_l_b59;
	case 2907ULL: goto x86_l_b5b;
	case 2910ULL: goto x86_l_b5e;
	case 2916ULL: goto x86_l_b64;
	case 2919ULL: goto x86_l_b67;
	case 2922ULL: goto x86_l_b6a;
	case 2928ULL: goto x86_l_b70;
	case 2933ULL: goto x86_l_b75;
	case 2936ULL: goto x86_l_b78;
	case 2942ULL: goto x86_l_b7e;
	case 2945ULL: goto x86_l_b81;
	case 2949ULL: goto x86_l_b85;
	case 2955ULL: goto x86_l_b8b;
	case 2958ULL: goto x86_l_b8e;
	case 2961ULL: goto x86_l_b91;
	case 2967ULL: goto x86_l_b97;
	case 2971ULL: goto x86_l_b9b;
	case 2977ULL: goto x86_l_ba1;
	case 2980ULL: goto x86_l_ba4;
	case 2986ULL: goto x86_l_baa;
	case 2990ULL: goto x86_l_bae;
	case 2996ULL: goto x86_l_bb4;
	case 2999ULL: goto x86_l_bb7;
	case 3005ULL: goto x86_l_bbd;
	case 3009ULL: goto x86_l_bc1;
	case 3015ULL: goto x86_l_bc7;
	case 3020ULL: goto x86_l_bcc;
	case 3023ULL: goto x86_l_bcf;
	case 3026ULL: goto x86_l_bd2;
	case 3032ULL: goto x86_l_bd8;
	case 3037ULL: goto x86_l_bdd;
	case 3040ULL: goto x86_l_be0;
	case 3046ULL: goto x86_l_be6;
	case 3049ULL: goto x86_l_be9;
	case 3053ULL: goto x86_l_bed;
	case 3059ULL: goto x86_l_bf3;
	case 3062ULL: goto x86_l_bf6;
	case 3065ULL: goto x86_l_bf9;
	case 3071ULL: goto x86_l_bff;
	case 3075ULL: goto x86_l_c03;
	case 3081ULL: goto x86_l_c09;
	case 3084ULL: goto x86_l_c0c;
	case 3090ULL: goto x86_l_c12;
	case 3094ULL: goto x86_l_c16;
	case 3100ULL: goto x86_l_c1c;
	case 3103ULL: goto x86_l_c1f;
	case 3109ULL: goto x86_l_c25;
	case 3113ULL: goto x86_l_c29;
	case 3119ULL: goto x86_l_c2f;
	case 3124ULL: goto x86_l_c34;
	case 3127ULL: goto x86_l_c37;
	case 3130ULL: goto x86_l_c3a;
	case 3132ULL: goto x86_l_c3c;
	case 3136ULL: goto x86_l_c40;
	case 3142ULL: goto x86_l_c46;
	case 3145ULL: goto x86_l_c49;
	case 3147ULL: goto x86_l_c4b;
	case 3151ULL: goto x86_l_c4f;
	case 3157ULL: goto x86_l_c55;
	case 3160ULL: goto x86_l_c58;
	case 3162ULL: goto x86_l_c5a;
	case 3166ULL: goto x86_l_c5e;
	case 3172ULL: goto x86_l_c64;
	case 3175ULL: goto x86_l_c67;
	case 3181ULL: goto x86_l_c6d;
	case 3183ULL: goto x86_l_c6f;
	case 3193ULL: goto x86_l_c79;
	case 3197ULL: goto x86_l_c7d;
	case 3203ULL: goto x86_l_c83;
	case 3205ULL: goto x86_l_c85;
	case 3208ULL: goto x86_l_c88;
	case 3212ULL: goto x86_l_c8c;
	case 3218ULL: goto x86_l_c92;
	case 3221ULL: goto x86_l_c95;
	case 3224ULL: goto x86_l_c98;
	case 3226ULL: goto x86_l_c9a;
	case 3230ULL: goto x86_l_c9e;
	case 3236ULL: goto x86_l_ca4;
	case 3239ULL: goto x86_l_ca7;
	case 3241ULL: goto x86_l_ca9;
	case 3245ULL: goto x86_l_cad;
	case 3251ULL: goto x86_l_cb3;
	case 3254ULL: goto x86_l_cb6;
	case 3256ULL: goto x86_l_cb8;
	case 3260ULL: goto x86_l_cbc;
	case 3266ULL: goto x86_l_cc2;
	case 3268ULL: goto x86_l_cc4;
	case 3271ULL: goto x86_l_cc7;
	case 3275ULL: goto x86_l_ccb;
	case 3281ULL: goto x86_l_cd1;
	case 3284ULL: goto x86_l_cd4;
	case 3287ULL: goto x86_l_cd7;
	case 3289ULL: goto x86_l_cd9;
	case 3293ULL: goto x86_l_cdd;
	case 3299ULL: goto x86_l_ce3;
	case 3302ULL: goto x86_l_ce6;
	case 3304ULL: goto x86_l_ce8;
	case 3308ULL: goto x86_l_cec;
	case 3314ULL: goto x86_l_cf2;
	case 3317ULL: goto x86_l_cf5;
	case 3319ULL: goto x86_l_cf7;
	case 3323ULL: goto x86_l_cfb;
	case 3329ULL: goto x86_l_d01;
	case 3331ULL: goto x86_l_d03;
	case 3332ULL: goto x86_l_d04;
	case 3335ULL: goto x86_l_d07;
	case 3338ULL: goto x86_l_d0a;
	case 3341ULL: goto x86_l_d0d;
	case 3347ULL: goto x86_l_d13;
	case 3352ULL: goto x86_l_d18;
	case 3355ULL: goto x86_l_d1b;
	case 3361ULL: goto x86_l_d21;
	case 3364ULL: goto x86_l_d24;
	case 3367ULL: goto x86_l_d27;
	case 3369ULL: goto x86_l_d29;
	case 3374ULL: goto x86_l_d2e;
	case 3378ULL: goto x86_l_d32;
	case 3380ULL: goto x86_l_d34;
	case 3384ULL: goto x86_l_d38;
	case 3390ULL: goto x86_l_d3e;
	case 3393ULL: goto x86_l_d41;
	case 3396ULL: goto x86_l_d44;
	case 3402ULL: goto x86_l_d4a;
	case 3406ULL: goto x86_l_d4e;
	case 3408ULL: goto x86_l_d50;
	case 3412ULL: goto x86_l_d54;
	case 3418ULL: goto x86_l_d5a;
	case 3421ULL: goto x86_l_d5d;
	case 3427ULL: goto x86_l_d63;
	case 3431ULL: goto x86_l_d67;
	case 3433ULL: goto x86_l_d69;
	case 3437ULL: goto x86_l_d6d;
	case 3443ULL: goto x86_l_d73;
	case 3446ULL: goto x86_l_d76;
	case 3452ULL: goto x86_l_d7c;
	case 3454ULL: goto x86_l_d7e;
	case 3458ULL: goto x86_l_d82;
	case 3464ULL: goto x86_l_d88;
	case 3468ULL: goto x86_l_d8c;
	case 3474ULL: goto x86_l_d92;
	case 3479ULL: goto x86_l_d97;
	case 3482ULL: goto x86_l_d9a;
	case 3486ULL: goto x86_l_d9e;
	case 3490ULL: goto x86_l_da2;
	case 3494ULL: goto x86_l_da6;
	case 3497ULL: goto x86_l_da9;
	case 3500ULL: goto x86_l_dac;
	case 3503ULL: goto x86_l_daf;
	case 3509ULL: goto x86_l_db5;
	case 3513ULL: goto x86_l_db9;
	case 3517ULL: goto x86_l_dbd;
	case 3521ULL: goto x86_l_dc1;
	case 3525ULL: goto x86_l_dc5;
	case 3528ULL: goto x86_l_dc8;
	case 3531ULL: goto x86_l_dcb;
	case 3534ULL: goto x86_l_dce;
	case 3540ULL: goto x86_l_dd4;
	case 3544ULL: goto x86_l_dd8;
	case 3548ULL: goto x86_l_ddc;
	case 3552ULL: goto x86_l_de0;
	case 3556ULL: goto x86_l_de4;
	case 3559ULL: goto x86_l_de7;
	case 3562ULL: goto x86_l_dea;
	case 3565ULL: goto x86_l_ded;
	case 3571ULL: goto x86_l_df3;
	case 3575ULL: goto x86_l_df7;
	case 3578ULL: goto x86_l_dfa;
	case 3582ULL: goto x86_l_dfe;
	case 3586ULL: goto x86_l_e02;
	case 3591ULL: goto x86_l_e07;
	case 3594ULL: goto x86_l_e0a;
	case 3597ULL: goto x86_l_e0d;
	case 3599ULL: goto x86_l_e0f;
	case 3604ULL: goto x86_l_e14;
	case 3608ULL: goto x86_l_e18;
	case 3610ULL: goto x86_l_e1a;
	case 3614ULL: goto x86_l_e1e;
	case 3616ULL: goto x86_l_e20;
	case 3617ULL: goto x86_l_e21;
	case 3620ULL: goto x86_l_e24;
	case 3624ULL: goto x86_l_e28;
	case 3628ULL: goto x86_l_e2c;
	case 3632ULL: goto x86_l_e30;
	case 3635ULL: goto x86_l_e33;
	case 3638ULL: goto x86_l_e36;
	case 3641ULL: goto x86_l_e39;
	case 3647ULL: goto x86_l_e3f;
	case 3651ULL: goto x86_l_e43;
	case 3655ULL: goto x86_l_e47;
	case 3659ULL: goto x86_l_e4b;
	case 3663ULL: goto x86_l_e4f;
	case 3666ULL: goto x86_l_e52;
	case 3669ULL: goto x86_l_e55;
	case 3672ULL: goto x86_l_e58;
	case 3674ULL: goto x86_l_e5a;
	case 3678ULL: goto x86_l_e5e;
	case 3682ULL: goto x86_l_e62;
	case 3686ULL: goto x86_l_e66;
	case 3690ULL: goto x86_l_e6a;
	case 3693ULL: goto x86_l_e6d;
	case 3696ULL: goto x86_l_e70;
	case 3699ULL: goto x86_l_e73;
	case 3701ULL: goto x86_l_e75;
	case 3705ULL: goto x86_l_e79;
	case 3708ULL: goto x86_l_e7c;
	case 3712ULL: goto x86_l_e80;
	case 3716ULL: goto x86_l_e84;
	case 3719ULL: goto x86_l_e87;
	case 3722ULL: goto x86_l_e8a;
	case 3724ULL: goto x86_l_e8c;
	case 3727ULL: goto x86_l_e8f;
	case 3730ULL: goto x86_l_e92;
	case 3732ULL: goto x86_l_e94;
	case 3736ULL: goto x86_l_e98;
	case 3738ULL: goto x86_l_e9a;
	case 3742ULL: goto x86_l_e9e;
	case 3744ULL: goto x86_l_ea0;
	case 3747ULL: goto x86_l_ea3;
	case 3749ULL: goto x86_l_ea5;
	case 3753ULL: goto x86_l_ea9;
	case 3755ULL: goto x86_l_eab;
	case 3759ULL: goto x86_l_eaf;
	case 3765ULL: goto x86_l_eb5;
	case 3768ULL: goto x86_l_eb8;
	case 3770ULL: goto x86_l_eba;
	case 3772ULL: goto x86_l_ebc;
	case 3776ULL: goto x86_l_ec0;
	case 3778ULL: goto x86_l_ec2;
	case 3782ULL: goto x86_l_ec6;
	case 3788ULL: goto x86_l_ecc;
	case 3790ULL: goto x86_l_ece;
	case 3792ULL: goto x86_l_ed0;
	case 3795ULL: goto x86_l_ed3;
	case 3798ULL: goto x86_l_ed6;
	case 3801ULL: goto x86_l_ed9;
	case 3803ULL: goto x86_l_edb;
	case 3806ULL: goto x86_l_ede;
	case 3807ULL: goto x86_l_edf;
	case 3809ULL: goto x86_l_ee1;
	case 3810ULL: goto x86_l_ee2;
	case 3814ULL: goto x86_l_ee6;
	case 3817ULL: goto x86_l_ee9;
	case 3820ULL: goto x86_l_eec;
	case 3824ULL: goto x86_l_ef0;
	case 3828ULL: goto x86_l_ef4;
	case 3835ULL: goto x86_l_efb;
	case 3840ULL: goto x86_l_f00;
	case 3845ULL: goto x86_l_f05;
	case 3847ULL: goto x86_l_f07;
	case 3850ULL: goto x86_l_f0a;
	case 3852ULL: goto x86_l_f0c;
	case 3855ULL: goto x86_l_f0f;
	case 3858ULL: goto x86_l_f12;
	case 3863ULL: goto x86_l_f17;
	case 3868ULL: goto x86_l_f1c;
	case 3873ULL: goto x86_l_f21;
	case 3875ULL: goto x86_l_f23;
	case 3878ULL: goto x86_l_f26;
	case 3881ULL: goto x86_l_f29;
	case 3883ULL: goto x86_l_f2b;
	case 3886ULL: goto x86_l_f2e;
	case 3888ULL: goto x86_l_f30;
	case 3891ULL: goto x86_l_f33;
	case 3894ULL: goto x86_l_f36;
	case 3896ULL: goto x86_l_f38;
	case 3898ULL: goto x86_l_f3a;
	case 3902ULL: goto x86_l_f3e;
	case 3903ULL: goto x86_l_f3f;
	case 3905ULL: goto x86_l_f41;
	case 3906ULL: goto x86_l_f42;
	case 3909ULL: goto x86_l_f45;
	case 3912ULL: goto x86_l_f48;
	case 3914ULL: goto x86_l_f4a;
	case 3916ULL: goto x86_l_f4c;
	case 3919ULL: goto x86_l_f4f;
	case 3923ULL: goto x86_l_f53;
	case 3924ULL: goto x86_l_f54;
	case 3926ULL: goto x86_l_f56;
	case 3927ULL: goto x86_l_f57;
	case 3929ULL: goto x86_l_f59;
	case 3931ULL: goto x86_l_f5b;
	case 3932ULL: goto x86_l_f5c;
	case 3936ULL: goto x86_l_f60;
	case 3938ULL: goto x86_l_f62;
	case 3941ULL: goto x86_l_f65;
	case 3945ULL: goto x86_l_f69;
	case 3953ULL: goto x86_l_f71;
	case 3960ULL: goto x86_l_f78;
	case 3965ULL: goto x86_l_f7d;
	case 3970ULL: goto x86_l_f82;
	case 3972ULL: goto x86_l_f84;
	case 3975ULL: goto x86_l_f87;
	case 3977ULL: goto x86_l_f89;
	case 3979ULL: goto x86_l_f8b;
	case 3985ULL: goto x86_l_f91;
	case 3988ULL: goto x86_l_f94;
	case 3994ULL: goto x86_l_f9a;
	case 4001ULL: goto x86_l_fa1;
	case 4006ULL: goto x86_l_fa6;
	case 4011ULL: goto x86_l_fab;
	case 4013ULL: goto x86_l_fad;
	case 4016ULL: goto x86_l_fb0;
	case 4022ULL: goto x86_l_fb6;
	case 4025ULL: goto x86_l_fb9;
	case 4028ULL: goto x86_l_fbc;
	case 4033ULL: goto x86_l_fc1;
	case 4036ULL: goto x86_l_fc4;
	case 4039ULL: goto x86_l_fc7;
	case 4041ULL: goto x86_l_fc9;
	case 4043ULL: goto x86_l_fcb;
	case 4046ULL: goto x86_l_fce;
	case 4049ULL: goto x86_l_fd1;
	case 4053ULL: goto x86_l_fd5;
	case 4056ULL: goto x86_l_fd8;
	case 4060ULL: goto x86_l_fdc;
	case 4062ULL: goto x86_l_fde;
	case 4069ULL: goto x86_l_fe5;
	case 4073ULL: goto x86_l_fe9;
	case 4077ULL: goto x86_l_fed;
	case 4084ULL: goto x86_l_ff4;
	case 4089ULL: goto x86_l_ff9;
	case 4093ULL: goto x86_l_ffd;
	case 4097ULL: goto x86_l_1001;
	case 4101ULL: goto x86_l_1005;
	case 4103ULL: goto x86_l_1007;
	case 4107ULL: goto x86_l_100b;
	case 4111ULL: goto x86_l_100f;
	case 4118ULL: goto x86_l_1016;
	case 4123ULL: goto x86_l_101b;
	case 4127ULL: goto x86_l_101f;
	case 4131ULL: goto x86_l_1023;
	case 4133ULL: goto x86_l_1025;
	case 4137ULL: goto x86_l_1029;
	case 4141ULL: goto x86_l_102d;
	case 4148ULL: goto x86_l_1034;
	case 4153ULL: goto x86_l_1039;
	case 4157ULL: goto x86_l_103d;
	case 4160ULL: goto x86_l_1040;
	case 4163ULL: goto x86_l_1043;
	case 4165ULL: goto x86_l_1045;
	case 4169ULL: goto x86_l_1049;
	case 4171ULL: goto x86_l_104b;
	case 4175ULL: goto x86_l_104f;
	case 4179ULL: goto x86_l_1053;
	case 4186ULL: goto x86_l_105a;
	case 4191ULL: goto x86_l_105f;
	case 4194ULL: goto x86_l_1062;
	case 4198ULL: goto x86_l_1066;
	case 4202ULL: goto x86_l_106a;
	case 4206ULL: goto x86_l_106e;
	case 4210ULL: goto x86_l_1072;
	case 4214ULL: goto x86_l_1076;
	case 4220ULL: goto x86_l_107c;
	case 4225ULL: goto x86_l_1081;
	case 4228ULL: goto x86_l_1084;
	case 4230ULL: goto x86_l_1086;
	case 4233ULL: goto x86_l_1089;
	case 4235ULL: goto x86_l_108b;
	case 4238ULL: goto x86_l_108e;
	default: return 0xffffffffffffffffULL;
	}
x86_l_b03:
	/* 0xb03: jne    c34 <filter_64ty_selector_val+0x162> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_c34;
	}
x86_l_b09:
	/* 0xb09: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b0b:
	/* 0xb0b: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_b0e:
	/* 0xb0e: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_b11:
	/* 0xb11: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_b12:
	/* 0xb12: cmp    rcx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 12ULL);
x86_l_b16:
	/* 0xb16: jne    b56 <filter_64ty_selector_val+0x84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b56;
	}
x86_l_b18:
	/* 0xb18: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b1b:
	/* 0xb1b: test   QWORD PTR [rdi+0x10],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b1f:
	/* 0xb1f: jne    af0 <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2800ULL;
	}
x86_l_b21:
	/* 0xb21: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b24:
	/* 0xb24: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_b27:
	/* 0xb27: jb     d01 <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d01;
	}
x86_l_b2d:
	/* 0xb2d: test   QWORD PTR [rdi+0x18],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b31:
	/* 0xb31: jne    af0 <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2800ULL;
	}
x86_l_b33:
	/* 0xb33: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_b36:
	/* 0xb36: jb     d01 <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d01;
	}
x86_l_b3c:
	/* 0xb3c: test   QWORD PTR [rdi+0x20],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b40:
	/* 0xb40: jne    af0 <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2800ULL;
	}
x86_l_b42:
	/* 0xb42: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_b45:
	/* 0xb45: jb     d01 <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d01;
	}
x86_l_b4b:
	/* 0xb4b: test   QWORD PTR [rdi+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b4f:
	/* 0xb4f: jne    af0 <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2800ULL;
	}
x86_l_b51:
	/* 0xb51: jmp    d01 <filter_64ty_selector_val+0x22f> */
	goto x86_l_d01;
x86_l_b56:
	/* 0xb56: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_b59:
	/* 0xb59: je     bcc <filter_64ty_selector_val+0xfa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bcc;
	}
x86_l_b5b:
	/* 0xb5b: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_b5e:
	/* 0xb5e: jne    d01 <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_d01;
	}
x86_l_b64:
	/* 0xb64: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_b67:
	/* 0xb67: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_b6a:
	/* 0xb6a: ja     cc4 <filter_64ty_selector_val+0x1f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_cc4;
	}
x86_l_b70:
	/* 0xb70: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_b75:
	/* 0xb75: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_b78:
	/* 0xb78: jae    cc4 <filter_64ty_selector_val+0x1f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_cc4;
	}
x86_l_b7e:
	/* 0xb7e: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b81:
	/* 0xb81: cmp    rcx,QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_b85:
	/* 0xb85: jl     af0 <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 2800ULL;
	}
x86_l_b8b:
	/* 0xb8b: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b8e:
	/* 0xb8e: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_b91:
	/* 0xb91: jb     d01 <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d01;
	}
x86_l_b97:
	/* 0xb97: cmp    rcx,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_b9b:
	/* 0xb9b: jl     af0 <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 2800ULL;
	}
x86_l_ba1:
	/* 0xba1: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_ba4:
	/* 0xba4: jb     d01 <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d01;
	}
x86_l_baa:
	/* 0xbaa: cmp    rcx,QWORD PTR [rdi+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_bae:
	/* 0xbae: jl     af0 <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 2800ULL;
	}
x86_l_bb4:
	/* 0xbb4: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_bb7:
	/* 0xbb7: jb     d01 <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d01;
	}
x86_l_bbd:
	/* 0xbbd: cmp    rcx,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_bc1:
	/* 0xbc1: jl     af0 <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 2800ULL;
	}
x86_l_bc7:
	/* 0xbc7: jmp    d01 <filter_64ty_selector_val+0x22f> */
	goto x86_l_d01;
x86_l_bcc:
	/* 0xbcc: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_bcf:
	/* 0xbcf: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_bd2:
	/* 0xbd2: ja     c85 <filter_64ty_selector_val+0x1b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_c85;
	}
x86_l_bd8:
	/* 0xbd8: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_bdd:
	/* 0xbdd: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_be0:
	/* 0xbe0: jae    c85 <filter_64ty_selector_val+0x1b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_c85;
	}
x86_l_be6:
	/* 0xbe6: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_be9:
	/* 0xbe9: cmp    rcx,QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_bed:
	/* 0xbed: jg     af0 <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 2800ULL;
	}
x86_l_bf3:
	/* 0xbf3: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bf6:
	/* 0xbf6: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_bf9:
	/* 0xbf9: jb     d01 <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d01;
	}
x86_l_bff:
	/* 0xbff: cmp    rcx,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_c03:
	/* 0xc03: jg     af0 <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 2800ULL;
	}
x86_l_c09:
	/* 0xc09: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_c0c:
	/* 0xc0c: jb     d01 <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d01;
	}
x86_l_c12:
	/* 0xc12: cmp    rcx,QWORD PTR [rdi+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_c16:
	/* 0xc16: jg     af0 <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 2800ULL;
	}
x86_l_c1c:
	/* 0xc1c: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_c1f:
	/* 0xc1f: jb     d01 <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d01;
	}
x86_l_c25:
	/* 0xc25: cmp    rcx,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_c29:
	/* 0xc29: jg     af0 <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 2800ULL;
	}
x86_l_c2f:
	/* 0xc2f: jmp    d01 <filter_64ty_selector_val+0x22f> */
	goto x86_l_d01;
x86_l_c34:
	/* 0xc34: mov    esi,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c37:
	/* 0xc37: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_c3a:
	/* 0xc3a: jb     c64 <filter_64ty_selector_val+0x192> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_c64;
	}
x86_l_c3c:
	/* 0xc3c: cmp    rdx,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_c40:
	/* 0xc40: je     b09 <filter_64ty_selector_val+0x37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b09;
	}
x86_l_c46:
	/* 0xc46: cmp    esi,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 25ULL);
x86_l_c49:
	/* 0xc49: jb     c64 <filter_64ty_selector_val+0x192> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_c64;
	}
x86_l_c4b:
	/* 0xc4b: cmp    rdx,QWORD PTR [rdi+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_c4f:
	/* 0xc4f: je     b09 <filter_64ty_selector_val+0x37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b09;
	}
x86_l_c55:
	/* 0xc55: cmp    esi,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 33ULL);
x86_l_c58:
	/* 0xc58: jb     c64 <filter_64ty_selector_val+0x192> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_c64;
	}
x86_l_c5a:
	/* 0xc5a: cmp    rdx,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_c5e:
	/* 0xc5e: je     b09 <filter_64ty_selector_val+0x37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b09;
	}
x86_l_c64:
	/* 0xc64: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_c67:
	/* 0xc67: ja     d01 <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_d01;
	}
x86_l_c6d:
	/* 0xc6d: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_c6f:
	/* 0xc6f: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_c79:
	/* 0xc79: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_c7d:
	/* 0xc7d: jb     af0 <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2800ULL;
	}
x86_l_c83:
	/* 0xc83: jmp    d01 <filter_64ty_selector_val+0x22f> */
	goto x86_l_d01;
x86_l_c85:
	/* 0xc85: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c88:
	/* 0xc88: cmp    rcx,QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_c8c:
	/* 0xc8c: ja     af0 <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2800ULL;
	}
x86_l_c92:
	/* 0xc92: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c95:
	/* 0xc95: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_c98:
	/* 0xc98: jb     d01 <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d01;
	}
x86_l_c9a:
	/* 0xc9a: cmp    rcx,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_c9e:
	/* 0xc9e: ja     af0 <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2800ULL;
	}
x86_l_ca4:
	/* 0xca4: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_ca7:
	/* 0xca7: jb     d01 <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d01;
	}
x86_l_ca9:
	/* 0xca9: cmp    rcx,QWORD PTR [rdi+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_cad:
	/* 0xcad: ja     af0 <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2800ULL;
	}
x86_l_cb3:
	/* 0xcb3: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_cb6:
	/* 0xcb6: jb     d01 <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d01;
	}
x86_l_cb8:
	/* 0xcb8: cmp    rcx,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_cbc:
	/* 0xcbc: ja     af0 <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2800ULL;
	}
x86_l_cc2:
	/* 0xcc2: jmp    d01 <filter_64ty_selector_val+0x22f> */
	goto x86_l_d01;
x86_l_cc4:
	/* 0xcc4: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cc7:
	/* 0xcc7: cmp    rcx,QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_ccb:
	/* 0xccb: jb     af0 <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2800ULL;
	}
x86_l_cd1:
	/* 0xcd1: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cd4:
	/* 0xcd4: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_cd7:
	/* 0xcd7: jb     d01 <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d01;
	}
x86_l_cd9:
	/* 0xcd9: cmp    rcx,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_cdd:
	/* 0xcdd: jb     af0 <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2800ULL;
	}
x86_l_ce3:
	/* 0xce3: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_ce6:
	/* 0xce6: jb     d01 <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d01;
	}
x86_l_ce8:
	/* 0xce8: cmp    rcx,QWORD PTR [rdi+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_cec:
	/* 0xcec: jb     af0 <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2800ULL;
	}
x86_l_cf2:
	/* 0xcf2: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_cf5:
	/* 0xcf5: jb     d01 <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d01;
	}
x86_l_cf7:
	/* 0xcf7: cmp    rcx,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_cfb:
	/* 0xcfb: jb     af0 <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2800ULL;
	}
x86_l_d01:
	/* 0xd01: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d03:
	/* 0xd03: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_d04:
	/* 0xd04: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_d07:
	/* 0xd07: mov    eax,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_d0a:
	/* 0xd0a: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_d0d:
	/* 0xd0d: ja     e07 <filter_64ty_range+0x103> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_e07;
	}
x86_l_d13:
	/* 0xd13: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_d18:
	/* 0xd18: bt     edx,eax */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_d1b:
	/* 0xd1b: jae    e07 <filter_64ty_range+0x103> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_e07;
	}
x86_l_d21:
	/* 0xd21: mov    rsi,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d24:
	/* 0xd24: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_d27:
	/* 0xd27: jne    d97 <filter_64ty_range+0x93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_d97;
	}
x86_l_d29:
	/* 0xd29: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d2e:
	/* 0xd2e: cmp    QWORD PTR [rdi+0x10],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d32:
	/* 0xd32: jg     d3e <filter_64ty_range+0x3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_d3e;
	}
x86_l_d34:
	/* 0xd34: cmp    rsi,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_d38:
	/* 0xd38: jle    e20 <filter_64ty_range+0x11c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_e20;
	}
x86_l_d3e:
	/* 0xd3e: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d41:
	/* 0xd41: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_d44:
	/* 0xd44: jb     ece <filter_64ty_range+0x1ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_ece;
	}
x86_l_d4a:
	/* 0xd4a: cmp    QWORD PTR [rdi+0x20],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d4e:
	/* 0xd4e: jg     d5a <filter_64ty_range+0x56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_d5a;
	}
x86_l_d50:
	/* 0xd50: cmp    rsi,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_d54:
	/* 0xd54: jle    e20 <filter_64ty_range+0x11c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_e20;
	}
x86_l_d5a:
	/* 0xd5a: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_d5d:
	/* 0xd5d: jb     ece <filter_64ty_range+0x1ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_ece;
	}
x86_l_d63:
	/* 0xd63: cmp    QWORD PTR [rdi+0x30],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d67:
	/* 0xd67: jg     d73 <filter_64ty_range+0x6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_d73;
	}
x86_l_d69:
	/* 0xd69: cmp    rsi,QWORD PTR [rdi+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_d6d:
	/* 0xd6d: jle    e20 <filter_64ty_range+0x11c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_e20;
	}
x86_l_d73:
	/* 0xd73: cmp    edx,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 57ULL);
x86_l_d76:
	/* 0xd76: jb     ece <filter_64ty_range+0x1ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_ece;
	}
x86_l_d7c:
	/* 0xd7c: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d7e:
	/* 0xd7e: cmp    QWORD PTR [rdi+0x40],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_d82:
	/* 0xd82: jg     ed0 <filter_64ty_range+0x1cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_ed0;
	}
x86_l_d88:
	/* 0xd88: cmp    rsi,QWORD PTR [rdi+0x48] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 72ULL);
x86_l_d8c:
	/* 0xd8c: jle    e20 <filter_64ty_range+0x11c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_e20;
	}
x86_l_d92:
	/* 0xd92: jmp    ed0 <filter_64ty_range+0x1cc> */
	goto x86_l_ed0;
x86_l_d97:
	/* 0xd97: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d9a:
	/* 0xd9a: cmp    QWORD PTR [rdi+0x10],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d9e:
	/* 0xd9e: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_da2:
	/* 0xda2: cmp    rsi,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_da6:
	/* 0xda6: setle  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_LE);
x86_l_da9:
	/* 0xda9: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_dac:
	/* 0xdac: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_daf:
	/* 0xdaf: jb     ed0 <filter_64ty_range+0x1cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_ed0;
	}
x86_l_db5:
	/* 0xdb5: cmp    QWORD PTR [rdi+0x20],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_db9:
	/* 0xdb9: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_dbd:
	/* 0xdbd: cmp    rsi,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_dc1:
	/* 0xdc1: setle  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_LE);
x86_l_dc5:
	/* 0xdc5: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_dc8:
	/* 0xdc8: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_dcb:
	/* 0xdcb: cmp    eax,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 41ULL);
x86_l_dce:
	/* 0xdce: jb     ed0 <filter_64ty_range+0x1cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_ed0;
	}
x86_l_dd4:
	/* 0xdd4: cmp    QWORD PTR [rdi+0x30],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_dd8:
	/* 0xdd8: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_ddc:
	/* 0xddc: cmp    rsi,QWORD PTR [rdi+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_de0:
	/* 0xde0: setle  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_LE);
x86_l_de4:
	/* 0xde4: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_de7:
	/* 0xde7: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_dea:
	/* 0xdea: cmp    eax,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 57ULL);
x86_l_ded:
	/* 0xded: jb     ed0 <filter_64ty_range+0x1cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_ed0;
	}
x86_l_df3:
	/* 0xdf3: cmp    QWORD PTR [rdi+0x40],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_df7:
	/* 0xdf7: setle  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_LE);
x86_l_dfa:
	/* 0xdfa: cmp    rsi,QWORD PTR [rdi+0x48] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 72ULL);
x86_l_dfe:
	/* 0xdfe: setle  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_LE);
x86_l_e02:
	/* 0xe02: jmp    e84 <filter_64ty_range+0x180> */
	goto x86_l_e84;
x86_l_e07:
	/* 0xe07: mov    rsi,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e0a:
	/* 0xe0a: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_e0d:
	/* 0xe0d: jne    e21 <filter_64ty_range+0x11d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_e21;
	}
x86_l_e0f:
	/* 0xe0f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e14:
	/* 0xe14: cmp    QWORD PTR [rdi+0x10],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e18:
	/* 0xe18: ja     e8c <filter_64ty_range+0x188> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_e8c;
	}
x86_l_e1a:
	/* 0xe1a: cmp    rsi,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_e1e:
	/* 0xe1e: ja     e8c <filter_64ty_range+0x188> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_e8c;
	}
x86_l_e20:
	/* 0xe20: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_e21:
	/* 0xe21: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e24:
	/* 0xe24: cmp    QWORD PTR [rdi+0x10],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e28:
	/* 0xe28: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_e2c:
	/* 0xe2c: cmp    rsi,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_e30:
	/* 0xe30: setbe  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_BE);
x86_l_e33:
	/* 0xe33: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_e36:
	/* 0xe36: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_e39:
	/* 0xe39: jb     ed0 <filter_64ty_range+0x1cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_ed0;
	}
x86_l_e3f:
	/* 0xe3f: cmp    QWORD PTR [rdi+0x20],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e43:
	/* 0xe43: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_e47:
	/* 0xe47: cmp    rsi,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_e4b:
	/* 0xe4b: setbe  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_BE);
x86_l_e4f:
	/* 0xe4f: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_e52:
	/* 0xe52: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_e55:
	/* 0xe55: cmp    eax,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 41ULL);
x86_l_e58:
	/* 0xe58: jb     ed0 <filter_64ty_range+0x1cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_ed0;
	}
x86_l_e5a:
	/* 0xe5a: cmp    QWORD PTR [rdi+0x30],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e5e:
	/* 0xe5e: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_e62:
	/* 0xe62: cmp    rsi,QWORD PTR [rdi+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_e66:
	/* 0xe66: setbe  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_BE);
x86_l_e6a:
	/* 0xe6a: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_e6d:
	/* 0xe6d: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_e70:
	/* 0xe70: cmp    eax,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 57ULL);
x86_l_e73:
	/* 0xe73: jb     ed0 <filter_64ty_range+0x1cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_ed0;
	}
x86_l_e75:
	/* 0xe75: cmp    QWORD PTR [rdi+0x40],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_e79:
	/* 0xe79: setbe  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_BE);
x86_l_e7c:
	/* 0xe7c: cmp    rsi,QWORD PTR [rdi+0x48] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 72ULL);
x86_l_e80:
	/* 0xe80: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_e84:
	/* 0xe84: and    sil,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_e87:
	/* 0xe87: or     dl,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_8, X86_ALU_OR);
x86_l_e8a:
	/* 0xe8a: jmp    ed0 <filter_64ty_range+0x1cc> */
	goto x86_l_ed0;
x86_l_e8c:
	/* 0xe8c: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e8f:
	/* 0xe8f: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_e92:
	/* 0xe92: jb     ece <filter_64ty_range+0x1ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_ece;
	}
x86_l_e94:
	/* 0xe94: cmp    QWORD PTR [rdi+0x20],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e98:
	/* 0xe98: ja     ea0 <filter_64ty_range+0x19c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_ea0;
	}
x86_l_e9a:
	/* 0xe9a: cmp    rsi,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_e9e:
	/* 0xe9e: jbe    e20 <filter_64ty_range+0x11c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_e20;
	}
x86_l_ea0:
	/* 0xea0: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_ea3:
	/* 0xea3: jb     ece <filter_64ty_range+0x1ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_ece;
	}
x86_l_ea5:
	/* 0xea5: cmp    QWORD PTR [rdi+0x30],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ea9:
	/* 0xea9: ja     eb5 <filter_64ty_range+0x1b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_eb5;
	}
x86_l_eab:
	/* 0xeab: cmp    rsi,QWORD PTR [rdi+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_eaf:
	/* 0xeaf: jbe    e20 <filter_64ty_range+0x11c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_e20;
	}
x86_l_eb5:
	/* 0xeb5: cmp    edx,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 57ULL);
x86_l_eb8:
	/* 0xeb8: jb     ece <filter_64ty_range+0x1ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_ece;
	}
x86_l_eba:
	/* 0xeba: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ebc:
	/* 0xebc: cmp    QWORD PTR [rdi+0x40],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_ec0:
	/* 0xec0: ja     ed0 <filter_64ty_range+0x1cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_ed0;
	}
x86_l_ec2:
	/* 0xec2: cmp    rsi,QWORD PTR [rdi+0x48] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 72ULL);
x86_l_ec6:
	/* 0xec6: jbe    e20 <filter_64ty_range+0x11c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_e20;
	}
x86_l_ecc:
	/* 0xecc: jmp    ed0 <filter_64ty_range+0x1cc> */
	goto x86_l_ed0;
x86_l_ece:
	/* 0xece: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ed0:
	/* 0xed0: cmp    ecx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 32ULL);
x86_l_ed3:
	/* 0xed3: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_ed6:
	/* 0xed6: xor    dl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_ed9:
	/* 0xed9: and    dl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_edb:
	/* 0xedb: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_ede:
	/* 0xede: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_edf:
	/* 0xedf: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_ee1:
	/* 0xee1: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_ee2:
	/* 0xee2: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_ee6:
	/* 0xee6: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_ee9:
	/* 0xee9: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_eec:
	/* 0xeec: movzx  eax,BYTE PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_ef0:
	/* 0xef0: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_ef4:
	/* 0xef4: mov    rdi,QWORD PTR [rip+0x530] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_efb:
	/* 0xefb: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_f00:
	/* 0xf00: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f05:
	/* 0xf05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f07:
	/* 0xf07: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f0a:
	/* 0xf0a: je     f38 <filter_64ty_map+0x59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f38;
	}
x86_l_f0c:
	/* 0xf0c: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_f0f:
	/* 0xf0f: mov    rax,QWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f12:
	/* 0xf12: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f17:
	/* 0xf17: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f1c:
	/* 0xf1c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f21:
	/* 0xf21: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f23:
	/* 0xf23: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_f26:
	/* 0xf26: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_f29:
	/* 0xf29: je     f42 <filter_64ty_map+0x63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f42;
	}
x86_l_f2b:
	/* 0xf2b: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_f2e:
	/* 0xf2e: jne    f4a <filter_64ty_map+0x6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_f4a;
	}
x86_l_f30:
	/* 0xf30: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f33:
	/* 0xf33: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_f36:
	/* 0xf36: jmp    f4c <filter_64ty_map+0x6d> */
	goto x86_l_f4c;
x86_l_f38:
	/* 0xf38: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f3a:
	/* 0xf3a: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_f3e:
	/* 0xf3e: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_f3f:
	/* 0xf3f: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_f41:
	/* 0xf41: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_f42:
	/* 0xf42: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f45:
	/* 0xf45: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_f48:
	/* 0xf48: jmp    f4c <filter_64ty_map+0x6d> */
	goto x86_l_f4c;
x86_l_f4a:
	/* 0xf4a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f4c:
	/* 0xf4c: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_f4f:
	/* 0xf4f: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_f53:
	/* 0xf53: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_f54:
	/* 0xf54: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_f56:
	/* 0xf56: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_f57:
	/* 0xf57: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_f59:
	/* 0xf59: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_f5b:
	/* 0xf5b: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_f5c:
	/* 0xf5c: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_f60:
	/* 0xf60: mov    ebx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDX, X86_WIDTH_32);
x86_l_f62:
	/* 0xf62: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_f65:
	/* 0xf65: mov    DWORD PTR [rsp+0xc],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_f69:
	/* 0xf69: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_f71:
	/* 0xf71: mov    rdi,QWORD PTR [rip+0x1e90] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_f78:
	/* 0xf78: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_f7d:
	/* 0xf7d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f82:
	/* 0xf82: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f84:
	/* 0xf84: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_f87:
	/* 0xf87: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f89:
	/* 0xf89: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_f8b:
	/* 0xf8b: je     1095 <filter_char_buf_postfix+0x13e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4245ULL;
	}
x86_l_f91:
	/* 0xf91: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_f94:
	/* 0xf94: je     1095 <filter_char_buf_postfix+0x13e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4245ULL;
	}
x86_l_f9a:
	/* 0xf9a: mov    rdi,QWORD PTR [rip+0x1e90] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_fa1:
	/* 0xfa1: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fa6:
	/* 0xfa6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fab:
	/* 0xfab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fad:
	/* 0xfad: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fb0:
	/* 0xfb0: je     1093 <filter_char_buf_postfix+0x13c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4243ULL;
	}
x86_l_fb6:
	/* 0xfb6: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_fb9:
	/* 0xfb9: cmp    ebx,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 127ULL);
x86_l_fbc:
	/* 0xfbc: mov    eax,0x7f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 127ULL);
x86_l_fc1:
	/* 0xfc1: cmovb  eax,ebx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RBX, X86_WIDTH_32, X86_CC_B);
x86_l_fc4:
	/* 0xfc4: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_fc7:
	/* 0xfc7: mov    DWORD PTR [rsi],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fc9:
	/* 0xfc9: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_fcb:
	/* 0xfcb: lea    ecx,[rbx-0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_fce:
	/* 0xfce: mov    rdx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_fd1:
	/* 0xfd1: add    rdx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 7ULL);
x86_l_fd5:
	/* 0xfd5: lea    edi,[rbx-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_fd8:
	/* 0xfd8: lea    r8d,[rbx-0x2] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_fdc:
	/* 0xfdc: dec    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_fde:
	/* 0xfde: mov    r9,0xfffffffffffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 18446744073709551613ULL);
x86_l_fe5:
	/* 0xfe5: lea    r10d,[rbx+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_fe9:
	/* 0xfe9: add    r10d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_fed:
	/* 0xfed: and    r10d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_ff4:
	/* 0xff4: movzx  r10d,BYTE PTR [r14+r10*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R10, 0, X86_WIDTH_8), 0ULL);
x86_l_ff9:
	/* 0xff9: mov    BYTE PTR [rdx-0x3],r10b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_R10, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_ffd:
	/* 0xffd: lea    r10,[rax+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_1001:
	/* 0x1001: cmp    r10,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_1005:
	/* 0x1005: je     107c <filter_char_buf_postfix+0x125> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_107c;
	}
x86_l_1007:
	/* 0x1007: lea    r11d,[r8+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_100b:
	/* 0x100b: add    r11d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_100f:
	/* 0x100f: and    r11d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1016:
	/* 0x1016: movzx  r11d,BYTE PTR [r14+r11*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R11, 0, X86_WIDTH_8), 0ULL);
x86_l_101b:
	/* 0x101b: mov    BYTE PTR [rdx-0x2],r11b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_R11, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_101f:
	/* 0x101f: cmp    r10,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1023:
	/* 0x1023: je     107c <filter_char_buf_postfix+0x125> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_107c;
	}
x86_l_1025:
	/* 0x1025: lea    r10d,[rdi+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_1029:
	/* 0x1029: add    r10d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_102d:
	/* 0x102d: and    r10d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1034:
	/* 0x1034: movzx  r10d,BYTE PTR [r14+r10*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R10, 0, X86_WIDTH_8), 0ULL);
x86_l_1039:
	/* 0x1039: mov    BYTE PTR [rdx-0x1],r10b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_R10, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_103d:
	/* 0x103d: mov    r10,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_RAX, X86_WIDTH_64);
x86_l_1040:
	/* 0x1040: add    r10,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R9, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1043:
	/* 0x1043: je     107c <filter_char_buf_postfix+0x125> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_107c;
	}
x86_l_1045:
	/* 0x1045: cmp    r9,0xffffffffffffff81 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_64, 18446744073709551489ULL);
x86_l_1049:
	/* 0x1049: je     107c <filter_char_buf_postfix+0x125> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_107c;
	}
x86_l_104b:
	/* 0x104b: lea    r10d,[rcx+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_104f:
	/* 0x104f: add    r10d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_1053:
	/* 0x1053: and    r10d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_105a:
	/* 0x105a: movzx  r10d,BYTE PTR [r14+r10*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R10, 0, X86_WIDTH_8), 0ULL);
x86_l_105f:
	/* 0x105f: mov    BYTE PTR [rdx],r10b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_R10, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1062:
	/* 0x1062: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1066:
	/* 0x1066: lea    r10,[rax+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_106a:
	/* 0x106a: add    r10,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_106e:
	/* 0x106e: add    r9,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_1072:
	/* 0x1072: cmp    r10,0xfffffffffffffffd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_64, 18446744073709551613ULL);
x86_l_1076:
	/* 0x1076: jne    fe5 <filter_char_buf_postfix+0x8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_fe5;
	}
x86_l_107c:
	/* 0x107c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1081:
	/* 0x1081: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1084:
	/* 0x1084: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1086:
	/* 0x1086: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1089:
	/* 0x1089: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_108b:
	/* 0x108b: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_108e:
	/* 0x108e: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
	return 4241ULL;
}

static __noinline __u64 tetragon_bpf_generic_retuprobe_v61_generic_retuprobe_filter_arg_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 4241ULL: goto x86_l_1091;
	case 4243ULL: goto x86_l_1093;
	case 4245ULL: goto x86_l_1095;
	case 4249ULL: goto x86_l_1099;
	case 4250ULL: goto x86_l_109a;
	case 4252ULL: goto x86_l_109c;
	case 4254ULL: goto x86_l_109e;
	case 4255ULL: goto x86_l_109f;
	case 4256ULL: goto x86_l_10a0;
	case 4258ULL: goto x86_l_10a2;
	case 4260ULL: goto x86_l_10a4;
	case 4261ULL: goto x86_l_10a5;
	case 4262ULL: goto x86_l_10a6;
	case 4264ULL: goto x86_l_10a8;
	case 4267ULL: goto x86_l_10ab;
	case 4271ULL: goto x86_l_10af;
	case 4278ULL: goto x86_l_10b6;
	case 4285ULL: goto x86_l_10bd;
	case 4290ULL: goto x86_l_10c2;
	case 4295ULL: goto x86_l_10c7;
	case 4297ULL: goto x86_l_10c9;
	case 4300ULL: goto x86_l_10cc;
	case 4302ULL: goto x86_l_10ce;
	case 4304ULL: goto x86_l_10d0;
	case 4306ULL: goto x86_l_10d2;
	case 4309ULL: goto x86_l_10d5;
	case 4311ULL: goto x86_l_10d7;
	case 4318ULL: goto x86_l_10de;
	case 4321ULL: goto x86_l_10e1;
	case 4326ULL: goto x86_l_10e6;
	case 4328ULL: goto x86_l_10e8;
	case 4331ULL: goto x86_l_10eb;
	case 4333ULL: goto x86_l_10ed;
	case 4339ULL: goto x86_l_10f3;
	case 4344ULL: goto x86_l_10f8;
	case 4347ULL: goto x86_l_10fb;
	case 4354ULL: goto x86_l_1102;
	case 4356ULL: goto x86_l_1104;
	case 4359ULL: goto x86_l_1107;
	case 4363ULL: goto x86_l_110b;
	case 4366ULL: goto x86_l_110e;
	case 4371ULL: goto x86_l_1113;
	case 4374ULL: goto x86_l_1116;
	case 4376ULL: goto x86_l_1118;
	case 4381ULL: goto x86_l_111d;
	case 4384ULL: goto x86_l_1120;
	case 4387ULL: goto x86_l_1123;
	case 4389ULL: goto x86_l_1125;
	case 4392ULL: goto x86_l_1128;
	case 4394ULL: goto x86_l_112a;
	case 4397ULL: goto x86_l_112d;
	case 4400ULL: goto x86_l_1130;
	case 4402ULL: goto x86_l_1132;
	case 4404ULL: goto x86_l_1134;
	case 4408ULL: goto x86_l_1138;
	case 4409ULL: goto x86_l_1139;
	case 4411ULL: goto x86_l_113b;
	case 4413ULL: goto x86_l_113d;
	case 4414ULL: goto x86_l_113e;
	case 4415ULL: goto x86_l_113f;
	case 4416ULL: goto x86_l_1140;
	case 4418ULL: goto x86_l_1142;
	case 4420ULL: goto x86_l_1144;
	case 4422ULL: goto x86_l_1146;
	case 4424ULL: goto x86_l_1148;
	case 4425ULL: goto x86_l_1149;
	case 4429ULL: goto x86_l_114d;
	case 4437ULL: goto x86_l_1155;
	case 4443ULL: goto x86_l_115b;
	case 4449ULL: goto x86_l_1161;
	case 4452ULL: goto x86_l_1164;
	case 4457ULL: goto x86_l_1169;
	case 4459ULL: goto x86_l_116b;
	case 4462ULL: goto x86_l_116e;
	case 4468ULL: goto x86_l_1174;
	case 4471ULL: goto x86_l_1177;
	case 4474ULL: goto x86_l_117a;
	case 4477ULL: goto x86_l_117d;
	case 4479ULL: goto x86_l_117f;
	case 4482ULL: goto x86_l_1182;
	case 4484ULL: goto x86_l_1184;
	case 4486ULL: goto x86_l_1186;
	case 4489ULL: goto x86_l_1189;
	case 4491ULL: goto x86_l_118b;
	case 4493ULL: goto x86_l_118d;
	case 4496ULL: goto x86_l_1190;
	case 4498ULL: goto x86_l_1192;
	case 4500ULL: goto x86_l_1194;
	case 4502ULL: goto x86_l_1196;
	case 4505ULL: goto x86_l_1199;
	case 4509ULL: goto x86_l_119d;
	case 4513ULL: goto x86_l_11a1;
	case 4515ULL: goto x86_l_11a3;
	case 4518ULL: goto x86_l_11a6;
	case 4521ULL: goto x86_l_11a9;
	case 4528ULL: goto x86_l_11b0;
	case 4532ULL: goto x86_l_11b4;
	case 4535ULL: goto x86_l_11b7;
	case 4540ULL: goto x86_l_11bc;
	case 4546ULL: goto x86_l_11c2;
	case 4551ULL: goto x86_l_11c7;
	case 4553ULL: goto x86_l_11c9;
	case 4559ULL: goto x86_l_11cf;
	case 4564ULL: goto x86_l_11d4;
	case 4566ULL: goto x86_l_11d6;
	case 4572ULL: goto x86_l_11dc;
	case 4577ULL: goto x86_l_11e1;
	case 4579ULL: goto x86_l_11e3;
	case 4582ULL: goto x86_l_11e6;
	case 4587ULL: goto x86_l_11eb;
	case 4591ULL: goto x86_l_11ef;
	case 4595ULL: goto x86_l_11f3;
	case 4602ULL: goto x86_l_11fa;
	case 4609ULL: goto x86_l_1201;
	case 4615ULL: goto x86_l_1207;
	case 4618ULL: goto x86_l_120a;
	case 4620ULL: goto x86_l_120c;
	case 4622ULL: goto x86_l_120e;
	case 4624ULL: goto x86_l_1210;
	case 4627ULL: goto x86_l_1213;
	case 4629ULL: goto x86_l_1215;
	case 4635ULL: goto x86_l_121b;
	case 4637ULL: goto x86_l_121d;
	case 4640ULL: goto x86_l_1220;
	case 4642ULL: goto x86_l_1222;
	case 4645ULL: goto x86_l_1225;
	case 4647ULL: goto x86_l_1227;
	case 4653ULL: goto x86_l_122d;
	case 4655ULL: goto x86_l_122f;
	case 4661ULL: goto x86_l_1235;
	case 4663ULL: goto x86_l_1237;
	case 4669ULL: goto x86_l_123d;
	case 4671ULL: goto x86_l_123f;
	case 4677ULL: goto x86_l_1245;
	case 4680ULL: goto x86_l_1248;
	case 4683ULL: goto x86_l_124b;
	case 4688ULL: goto x86_l_1250;
	case 4692ULL: goto x86_l_1254;
	case 4698ULL: goto x86_l_125a;
	case 4703ULL: goto x86_l_125f;
	case 4705ULL: goto x86_l_1261;
	case 4712ULL: goto x86_l_1268;
	case 4717ULL: goto x86_l_126d;
	case 4722ULL: goto x86_l_1272;
	case 4725ULL: goto x86_l_1275;
	case 4727ULL: goto x86_l_1277;
	case 4730ULL: goto x86_l_127a;
	case 4737ULL: goto x86_l_1281;
	case 4742ULL: goto x86_l_1286;
	case 4745ULL: goto x86_l_1289;
	case 4747ULL: goto x86_l_128b;
	case 4750ULL: goto x86_l_128e;
	case 4752ULL: goto x86_l_1290;
	case 4757ULL: goto x86_l_1295;
	case 4760ULL: goto x86_l_1298;
	case 4766ULL: goto x86_l_129e;
	case 4769ULL: goto x86_l_12a1;
	case 4775ULL: goto x86_l_12a7;
	case 4780ULL: goto x86_l_12ac;
	case 4784ULL: goto x86_l_12b0;
	case 4786ULL: goto x86_l_12b2;
	case 4791ULL: goto x86_l_12b7;
	case 4794ULL: goto x86_l_12ba;
	case 4798ULL: goto x86_l_12be;
	case 4801ULL: goto x86_l_12c1;
	case 4806ULL: goto x86_l_12c6;
	case 4811ULL: goto x86_l_12cb;
	case 4813ULL: goto x86_l_12cd;
	case 4815ULL: goto x86_l_12cf;
	case 4818ULL: goto x86_l_12d2;
	case 4820ULL: goto x86_l_12d4;
	case 4825ULL: goto x86_l_12d9;
	case 4829ULL: goto x86_l_12dd;
	case 4832ULL: goto x86_l_12e0;
	case 4839ULL: goto x86_l_12e7;
	case 4844ULL: goto x86_l_12ec;
	case 4849ULL: goto x86_l_12f1;
	case 4851ULL: goto x86_l_12f3;
	case 4856ULL: goto x86_l_12f8;
	case 4859ULL: goto x86_l_12fb;
	case 4863ULL: goto x86_l_12ff;
	case 4866ULL: goto x86_l_1302;
	case 4871ULL: goto x86_l_1307;
	case 4876ULL: goto x86_l_130c;
	case 4878ULL: goto x86_l_130e;
	case 4880ULL: goto x86_l_1310;
	case 4883ULL: goto x86_l_1313;
	case 4885ULL: goto x86_l_1315;
	case 4890ULL: goto x86_l_131a;
	case 4894ULL: goto x86_l_131e;
	case 4898ULL: goto x86_l_1322;
	case 4905ULL: goto x86_l_1329;
	case 4910ULL: goto x86_l_132e;
	case 4915ULL: goto x86_l_1333;
	case 4918ULL: goto x86_l_1336;
	case 4920ULL: goto x86_l_1338;
	case 4925ULL: goto x86_l_133d;
	case 4929ULL: goto x86_l_1341;
	case 4931ULL: goto x86_l_1343;
	case 4935ULL: goto x86_l_1347;
	case 4937ULL: goto x86_l_1349;
	case 4941ULL: goto x86_l_134d;
	case 4947ULL: goto x86_l_1353;
	case 4951ULL: goto x86_l_1357;
	case 4957ULL: goto x86_l_135d;
	case 4961ULL: goto x86_l_1361;
	case 4967ULL: goto x86_l_1367;
	case 4974ULL: goto x86_l_136e;
	case 4979ULL: goto x86_l_1373;
	case 4984ULL: goto x86_l_1378;
	case 4989ULL: goto x86_l_137d;
	case 4993ULL: goto x86_l_1381;
	case 4995ULL: goto x86_l_1383;
	case 4999ULL: goto x86_l_1387;
	case 5005ULL: goto x86_l_138d;
	case 5009ULL: goto x86_l_1391;
	case 5015ULL: goto x86_l_1397;
	case 5019ULL: goto x86_l_139b;
	case 5025ULL: goto x86_l_13a1;
	case 5032ULL: goto x86_l_13a8;
	case 5037ULL: goto x86_l_13ad;
	case 5042ULL: goto x86_l_13b2;
	case 5047ULL: goto x86_l_13b7;
	case 5051ULL: goto x86_l_13bb;
	case 5057ULL: goto x86_l_13c1;
	case 5061ULL: goto x86_l_13c5;
	case 5067ULL: goto x86_l_13cb;
	case 5071ULL: goto x86_l_13cf;
	case 5077ULL: goto x86_l_13d5;
	case 5084ULL: goto x86_l_13dc;
	case 5089ULL: goto x86_l_13e1;
	case 5094ULL: goto x86_l_13e6;
	case 5099ULL: goto x86_l_13eb;
	case 5102ULL: goto x86_l_13ee;
	case 5104ULL: goto x86_l_13f0;
	case 5108ULL: goto x86_l_13f4;
	case 5114ULL: goto x86_l_13fa;
	case 5121ULL: goto x86_l_1401;
	case 5126ULL: goto x86_l_1406;
	case 5131ULL: goto x86_l_140b;
	case 5136ULL: goto x86_l_1410;
	case 5143ULL: goto x86_l_1417;
	case 5148ULL: goto x86_l_141c;
	case 5153ULL: goto x86_l_1421;
	case 5155ULL: goto x86_l_1423;
	case 5162ULL: goto x86_l_142a;
	case 5167ULL: goto x86_l_142f;
	case 5172ULL: goto x86_l_1434;
	case 5174ULL: goto x86_l_1436;
	case 5181ULL: goto x86_l_143d;
	case 5186ULL: goto x86_l_1442;
	case 5191ULL: goto x86_l_1447;
	case 5193ULL: goto x86_l_1449;
	case 5200ULL: goto x86_l_1450;
	case 5205ULL: goto x86_l_1455;
	case 5210ULL: goto x86_l_145a;
	case 5212ULL: goto x86_l_145c;
	case 5219ULL: goto x86_l_1463;
	case 5224ULL: goto x86_l_1468;
	case 5229ULL: goto x86_l_146d;
	case 5231ULL: goto x86_l_146f;
	case 5238ULL: goto x86_l_1476;
	case 5243ULL: goto x86_l_147b;
	case 5248ULL: goto x86_l_1480;
	case 5250ULL: goto x86_l_1482;
	case 5257ULL: goto x86_l_1489;
	case 5262ULL: goto x86_l_148e;
	case 5267ULL: goto x86_l_1493;
	case 5272ULL: goto x86_l_1498;
	case 5274ULL: goto x86_l_149a;
	case 5277ULL: goto x86_l_149d;
	case 5279ULL: goto x86_l_149f;
	case 5282ULL: goto x86_l_14a2;
	case 5287ULL: goto x86_l_14a7;
	case 5292ULL: goto x86_l_14ac;
	case 5294ULL: goto x86_l_14ae;
	case 5297ULL: goto x86_l_14b1;
	case 5299ULL: goto x86_l_14b3;
	case 5302ULL: goto x86_l_14b6;
	case 5305ULL: goto x86_l_14b9;
	case 5307ULL: goto x86_l_14bb;
	case 5309ULL: goto x86_l_14bd;
	case 5313ULL: goto x86_l_14c1;
	case 5314ULL: goto x86_l_14c2;
	case 5316ULL: goto x86_l_14c4;
	case 5318ULL: goto x86_l_14c6;
	case 5320ULL: goto x86_l_14c8;
	case 5322ULL: goto x86_l_14ca;
	case 5323ULL: goto x86_l_14cb;
	case 5324ULL: goto x86_l_14cc;
	case 5325ULL: goto x86_l_14cd;
	case 5327ULL: goto x86_l_14cf;
	case 5329ULL: goto x86_l_14d1;
	case 5331ULL: goto x86_l_14d3;
	case 5333ULL: goto x86_l_14d5;
	case 5334ULL: goto x86_l_14d6;
	case 5335ULL: goto x86_l_14d7;
	case 5338ULL: goto x86_l_14da;
	case 5341ULL: goto x86_l_14dd;
	case 5343ULL: goto x86_l_14df;
	case 5345ULL: goto x86_l_14e1;
	case 5351ULL: goto x86_l_14e7;
	case 5353ULL: goto x86_l_14e9;
	case 5359ULL: goto x86_l_14ef;
	case 5364ULL: goto x86_l_14f4;
	case 5366ULL: goto x86_l_14f6;
	case 5369ULL: goto x86_l_14f9;
	case 5374ULL: goto x86_l_14fe;
	case 5378ULL: goto x86_l_1502;
	case 5383ULL: goto x86_l_1507;
	case 5390ULL: goto x86_l_150e;
	case 5393ULL: goto x86_l_1511;
	case 5395ULL: goto x86_l_1513;
	case 5398ULL: goto x86_l_1516;
	case 5404ULL: goto x86_l_151c;
	case 5407ULL: goto x86_l_151f;
	case 5409ULL: goto x86_l_1521;
	case 5411ULL: goto x86_l_1523;
	case 5414ULL: goto x86_l_1526;
	case 5417ULL: goto x86_l_1529;
	case 5420ULL: goto x86_l_152c;
	case 5422ULL: goto x86_l_152e;
	case 5424ULL: goto x86_l_1530;
	case 5428ULL: goto x86_l_1534;
	case 5431ULL: goto x86_l_1537;
	case 5433ULL: goto x86_l_1539;
	case 5437ULL: goto x86_l_153d;
	case 5439ULL: goto x86_l_153f;
	case 5441ULL: goto x86_l_1541;
	case 5446ULL: goto x86_l_1546;
	case 5450ULL: goto x86_l_154a;
	case 5453ULL: goto x86_l_154d;
	case 5457ULL: goto x86_l_1551;
	case 5461ULL: goto x86_l_1555;
	case 5465ULL: goto x86_l_1559;
	case 5469ULL: goto x86_l_155d;
	case 5472ULL: goto x86_l_1560;
	case 5476ULL: goto x86_l_1564;
	case 5480ULL: goto x86_l_1568;
	case 5484ULL: goto x86_l_156c;
	case 5488ULL: goto x86_l_1570;
	case 5490ULL: goto x86_l_1572;
	case 5493ULL: goto x86_l_1575;
	case 5496ULL: goto x86_l_1578;
	case 5498ULL: goto x86_l_157a;
	case 5500ULL: goto x86_l_157c;
	case 5502ULL: goto x86_l_157e;
	case 5508ULL: goto x86_l_1584;
	case 5513ULL: goto x86_l_1589;
	case 5517ULL: goto x86_l_158d;
	case 5523ULL: goto x86_l_1593;
	case 5527ULL: goto x86_l_1597;
	case 5530ULL: goto x86_l_159a;
	case 5534ULL: goto x86_l_159e;
	case 5540ULL: goto x86_l_15a4;
	case 5545ULL: goto x86_l_15a9;
	case 5547ULL: goto x86_l_15ab;
	case 5553ULL: goto x86_l_15b1;
	case 5558ULL: goto x86_l_15b6;
	case 5560ULL: goto x86_l_15b8;
	case 5563ULL: goto x86_l_15bb;
	case 5568ULL: goto x86_l_15c0;
	case 5572ULL: goto x86_l_15c4;
	case 5577ULL: goto x86_l_15c9;
	case 5584ULL: goto x86_l_15d0;
	case 5587ULL: goto x86_l_15d3;
	case 5589ULL: goto x86_l_15d5;
	case 5592ULL: goto x86_l_15d8;
	case 5598ULL: goto x86_l_15de;
	case 5601ULL: goto x86_l_15e1;
	case 5603ULL: goto x86_l_15e3;
	case 5605ULL: goto x86_l_15e5;
	case 5608ULL: goto x86_l_15e8;
	case 5611ULL: goto x86_l_15eb;
	case 5614ULL: goto x86_l_15ee;
	case 5616ULL: goto x86_l_15f0;
	case 5618ULL: goto x86_l_15f2;
	case 5622ULL: goto x86_l_15f6;
	case 5625ULL: goto x86_l_15f9;
	case 5627ULL: goto x86_l_15fb;
	case 5631ULL: goto x86_l_15ff;
	case 5634ULL: goto x86_l_1602;
	case 5636ULL: goto x86_l_1604;
	case 5640ULL: goto x86_l_1608;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1091:
	/* 0x1091: jmp    1095 <filter_char_buf_postfix+0x13e> */
	goto x86_l_1095;
x86_l_1093:
	/* 0x1093: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1095:
	/* 0x1095: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1099:
	/* 0x1099: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_109a:
	/* 0x109a: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_109c:
	/* 0x109c: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_109e:
	/* 0x109e: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_109f:
	/* 0x109f: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_10a0:
	/* 0x10a0: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_10a2:
	/* 0x10a2: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_10a4:
	/* 0x10a4: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_10a5:
	/* 0x10a5: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_10a6:
	/* 0x10a6: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_10a8:
	/* 0x10a8: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_10ab:
	/* 0x10ab: mov    DWORD PTR [rsp+0x4],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_10af:
	/* 0x10af: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10b6:
	/* 0x10b6: mov    rdi,QWORD PTR [rip+0x1df0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_10bd:
	/* 0x10bd: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_10c2:
	/* 0x10c2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10c7:
	/* 0x10c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10c9:
	/* 0x10c9: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_10cc:
	/* 0x10cc: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10ce:
	/* 0x10ce: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_10d0:
	/* 0x10d0: je     1134 <filter_char_buf_prefix+0x95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1134;
	}
x86_l_10d2:
	/* 0x10d2: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_10d5:
	/* 0x10d5: je     1134 <filter_char_buf_prefix+0x95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1134;
	}
x86_l_10d7:
	/* 0x10d7: mov    rdi,QWORD PTR [rip+0x1df0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_10de:
	/* 0x10de: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_10e1:
	/* 0x10e1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10e6:
	/* 0x10e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10e8:
	/* 0x10e8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10eb:
	/* 0x10eb: je     1132 <filter_char_buf_prefix+0x93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1132;
	}
x86_l_10ed:
	/* 0x10ed: cmp    ebp,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 255ULL);
x86_l_10f3:
	/* 0x10f3: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_10f8:
	/* 0x10f8: cmovb  esi,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RBP, X86_WIDTH_32, X86_CC_B);
x86_l_10fb:
	/* 0x10fb: lea    ecx,[rsi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_1102:
	/* 0x1102: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1104:
	/* 0x1104: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1107:
	/* 0x1107: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_110b:
	/* 0x110b: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_110e:
	/* 0x110e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1113:
	/* 0x1113: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1116:
	/* 0x1116: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1118:
	/* 0x1118: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_111d:
	/* 0x111d: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_1120:
	/* 0x1120: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_1123:
	/* 0x1123: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1125:
	/* 0x1125: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1128:
	/* 0x1128: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_112a:
	/* 0x112a: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_112d:
	/* 0x112d: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_1130:
	/* 0x1130: jmp    1134 <filter_char_buf_prefix+0x95> */
	goto x86_l_1134;
x86_l_1132:
	/* 0x1132: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1134:
	/* 0x1134: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1138:
	/* 0x1138: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1139:
	/* 0x1139: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_113b:
	/* 0x113b: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_113d:
	/* 0x113d: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_113e:
	/* 0x113e: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_113f:
	/* 0x113f: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1140:
	/* 0x1140: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_1142:
	/* 0x1142: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_1144:
	/* 0x1144: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_1146:
	/* 0x1146: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_1148:
	/* 0x1148: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_1149:
	/* 0x1149: sub    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 40ULL);
x86_l_114d:
	/* 0x114d: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_1155:
	/* 0x1155: cmp    edx,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4096ULL);
x86_l_115b:
	/* 0x115b: ja     14bb <filter_char_buf_equal+0x37c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_14bb;
	}
x86_l_1161:
	/* 0x1161: movzx  eax,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1164:
	/* 0x1164: cmp    eax,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_1169:
	/* 0x1169: ja     11bc <filter_char_buf_equal+0x7d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_11bc;
	}
x86_l_116b:
	/* 0x116b: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_116e:
	/* 0x116e: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_1174:
	/* 0x1174: shr    ecx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_1177:
	/* 0x1177: and    ecx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_117a:
	/* 0x117a: lea    ecx,[rcx+rcx*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 1), 0ULL);
x86_l_117d:
	/* 0x117d: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_117f:
	/* 0x117f: test   dx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_16);
x86_l_1182:
	/* 0x1182: je     118d <filter_char_buf_equal+0x4e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_118d;
	}
x86_l_1184:
	/* 0x1184: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1186:
	/* 0x1186: mov    r14d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_32);
x86_l_1189:
	/* 0x1189: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_118b:
	/* 0x118b: je     11a6 <filter_char_buf_equal+0x67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11a6;
	}
x86_l_118d:
	/* 0x118d: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1190:
	/* 0x1190: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1192:
	/* 0x1192: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1194:
	/* 0x1194: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_1196:
	/* 0x1196: add    eax,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_1199:
	/* 0x1199: movzx  r14d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_119d:
	/* 0x119d: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_11a1:
	/* 0x11a1: ja     11fa <filter_char_buf_equal+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_11fa;
	}
x86_l_11a3:
	/* 0x11a3: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_11a6:
	/* 0x11a6: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_11a9:
	/* 0x11a9: imul   r12d,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_R12, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_11b0:
	/* 0x11b0: shr    r12d,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_11b4:
	/* 0x11b4: dec    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_11b7:
	/* 0x11b7: jmp    1245 <filter_char_buf_equal+0x106> */
	goto x86_l_1245;
x86_l_11bc:
	/* 0x11bc: mov    r14d,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 256ULL);
x86_l_11c2:
	/* 0x11c2: cmp    eax,0x101 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 257ULL);
x86_l_11c7:
	/* 0x11c7: jb     11fa <filter_char_buf_equal+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_11fa;
	}
x86_l_11c9:
	/* 0x11c9: mov    r14d,0x200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 512ULL);
x86_l_11cf:
	/* 0x11cf: cmp    eax,0x201 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 513ULL);
x86_l_11d4:
	/* 0x11d4: jb     11fa <filter_char_buf_equal+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_11fa;
	}
x86_l_11d6:
	/* 0x11d6: mov    r14d,0x400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1024ULL);
x86_l_11dc:
	/* 0x11dc: cmp    eax,0x401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1025ULL);
x86_l_11e1:
	/* 0x11e1: jb     11fa <filter_char_buf_equal+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_11fa;
	}
x86_l_11e3:
	/* 0x11e3: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11e6:
	/* 0x11e6: cmp    eax,0x801 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2049ULL);
x86_l_11eb:
	/* 0x11eb: setae  r14b */
	X86_SIM_L_EXEC_SETCC(X86_R14, X86_CC_AE);
x86_l_11ef:
	/* 0x11ef: shl    r14d,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHL, 11ULL);
x86_l_11f3:
	/* 0x11f3: add    r14d,0x800 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 2048ULL);
x86_l_11fa:
	/* 0x11fa: lea    eax,[r14-0x100] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551360ULL);
x86_l_1201:
	/* 0x1201: rorx   eax,eax,0x8 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 8ULL);
x86_l_1207:
	/* 0x1207: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_120a:
	/* 0x120a: jg     121d <filter_char_buf_equal+0xde> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_121d;
	}
x86_l_120c:
	/* 0x120c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_120e:
	/* 0x120e: je     1237 <filter_char_buf_equal+0xf8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1237;
	}
x86_l_1210:
	/* 0x1210: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1213:
	/* 0x1213: jne    122f <filter_char_buf_equal+0xf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_122f;
	}
x86_l_1215:
	/* 0x1215: mov    r12d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 7ULL);
x86_l_121b:
	/* 0x121b: jmp    1245 <filter_char_buf_equal+0x106> */
	goto x86_l_1245;
x86_l_121d:
	/* 0x121d: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1220:
	/* 0x1220: je     123f <filter_char_buf_equal+0x100> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_123f;
	}
x86_l_1222:
	/* 0x1222: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_1225:
	/* 0x1225: jne    122f <filter_char_buf_equal+0xf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_122f;
	}
x86_l_1227:
	/* 0x1227: mov    r12d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 9ULL);
x86_l_122d:
	/* 0x122d: jmp    1245 <filter_char_buf_equal+0x106> */
	goto x86_l_1245;
x86_l_122f:
	/* 0x122f: mov    r12d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 10ULL);
x86_l_1235:
	/* 0x1235: jmp    1245 <filter_char_buf_equal+0x106> */
	goto x86_l_1245;
x86_l_1237:
	/* 0x1237: mov    r12d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 6ULL);
x86_l_123d:
	/* 0x123d: jmp    1245 <filter_char_buf_equal+0x106> */
	goto x86_l_1245;
x86_l_123f:
	/* 0x123f: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_1245:
	/* 0x1245: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_1248:
	/* 0x1248: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_124b:
	/* 0x124b: mov    r13d,DWORD PTR [rdi+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_1250:
	/* 0x1250: cmp    r13d,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4294967295ULL);
x86_l_1254:
	/* 0x1254: je     14bb <filter_char_buf_equal+0x37c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14bb;
	}
x86_l_125a:
	/* 0x125a: mov    QWORD PTR [rsp+0x20],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_125f:
	/* 0x125f: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_1261:
	/* 0x1261: mov    rdi,QWORD PTR [rip+0x1a60] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_1268:
	/* 0x1268: lea    r15,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_126d:
	/* 0x126d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1272:
	/* 0x1272: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_1275:
	/* 0x1275: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1277:
	/* 0x1277: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_127a:
	/* 0x127a: mov    rdi,QWORD PTR [rip+0x1a60] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_1281:
	/* 0x1281: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1286:
	/* 0x1286: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_1289:
	/* 0x1289: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_128b:
	/* 0x128b: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_128e:
	/* 0x128e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1290:
	/* 0x1290: mov    QWORD PTR [rsp+0x8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1295:
	/* 0x1295: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1298:
	/* 0x1298: je     14bd <filter_char_buf_equal+0x37e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14bd;
	}
x86_l_129e:
	/* 0x129e: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_12a1:
	/* 0x12a1: je     14bd <filter_char_buf_equal+0x37e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14bd;
	}
x86_l_12a7:
	/* 0x12a7: mov    QWORD PTR [rsp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_12ac:
	/* 0x12ac: cmp    r12d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 5ULL);
x86_l_12b0:
	/* 0x12b0: jg     12f3 <filter_char_buf_equal+0x1b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_12f3;
	}
x86_l_12b2:
	/* 0x12b2: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12b7:
	/* 0x12b7: mov    BYTE PTR [rax],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12ba:
	/* 0x12ba: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_12be:
	/* 0x12be: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_12c1:
	/* 0x12c1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12c6:
	/* 0x12c6: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_12cb:
	/* 0x12cb: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_12cd:
	/* 0x12cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12cf:
	/* 0x12cf: sub    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_12d2:
	/* 0x12d2: jbe    1338 <filter_char_buf_equal+0x1f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1338;
	}
x86_l_12d4:
	/* 0x12d4: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12d9:
	/* 0x12d9: lea    rdi,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_12dd:
	/* 0x12dd: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_12e0:
	/* 0x12e0: and    r14d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_12e7:
	/* 0x12e7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12ec:
	/* 0x12ec: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_12f1:
	/* 0x12f1: jmp    1333 <filter_char_buf_equal+0x1f4> */
	goto x86_l_1333;
x86_l_12f3:
	/* 0x12f3: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12f8:
	/* 0x12f8: mov    WORD PTR [rax],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12fb:
	/* 0x12fb: lea    rdi,[rax+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_12ff:
	/* 0x12ff: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_1302:
	/* 0x1302: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1307:
	/* 0x1307: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_130c:
	/* 0x130c: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_130e:
	/* 0x130e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1310:
	/* 0x1310: sub    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1313:
	/* 0x1313: jbe    1338 <filter_char_buf_equal+0x1f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1338;
	}
x86_l_1315:
	/* 0x1315: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_131a:
	/* 0x131a: lea    rdi,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_131e:
	/* 0x131e: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1322:
	/* 0x1322: and    r14d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1329:
	/* 0x1329: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_132e:
	/* 0x132e: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1333:
	/* 0x1333: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_1336:
	/* 0x1336: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1338:
	/* 0x1338: mov    DWORD PTR [rsp+0x4],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_133d:
	/* 0x133d: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_1341:
	/* 0x1341: jle    137d <filter_char_buf_equal+0x23e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_137d;
	}
x86_l_1343:
	/* 0x1343: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_1347:
	/* 0x1347: jg     13b7 <filter_char_buf_equal+0x278> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_13b7;
	}
x86_l_1349:
	/* 0x1349: cmp    r12d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 5ULL);
x86_l_134d:
	/* 0x134d: je     146f <filter_char_buf_equal+0x330> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_146f;
	}
x86_l_1353:
	/* 0x1353: cmp    r12d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 6ULL);
x86_l_1357:
	/* 0x1357: je     1436 <filter_char_buf_equal+0x2f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1436;
	}
x86_l_135d:
	/* 0x135d: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_1361:
	/* 0x1361: jne    14bb <filter_char_buf_equal+0x37c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_14bb;
	}
x86_l_1367:
	/* 0x1367: mov    rdi,QWORD PTR [rip+0x1a60] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_7)));
x86_l_136e:
	/* 0x136e: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1373:
	/* 0x1373: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1378:
	/* 0x1378: jmp    1493 <filter_char_buf_equal+0x354> */
	goto x86_l_1493;
x86_l_137d:
	/* 0x137d: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_1381:
	/* 0x1381: jle    13eb <filter_char_buf_equal+0x2ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_13eb;
	}
x86_l_1383:
	/* 0x1383: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_1387:
	/* 0x1387: je     145c <filter_char_buf_equal+0x31d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_145c;
	}
x86_l_138d:
	/* 0x138d: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_1391:
	/* 0x1391: je     1423 <filter_char_buf_equal+0x2e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1423;
	}
x86_l_1397:
	/* 0x1397: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_139b:
	/* 0x139b: jne    14bb <filter_char_buf_equal+0x37c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_14bb;
	}
x86_l_13a1:
	/* 0x13a1: mov    rdi,QWORD PTR [rip+0x1a60] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_13a8:
	/* 0x13a8: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_13ad:
	/* 0x13ad: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13b2:
	/* 0x13b2: jmp    1493 <filter_char_buf_equal+0x354> */
	goto x86_l_1493;
x86_l_13b7:
	/* 0x13b7: cmp    r12d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 8ULL);
x86_l_13bb:
	/* 0x13bb: je     1482 <filter_char_buf_equal+0x343> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1482;
	}
x86_l_13c1:
	/* 0x13c1: cmp    r12d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 9ULL);
x86_l_13c5:
	/* 0x13c5: je     1449 <filter_char_buf_equal+0x30a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1449;
	}
x86_l_13cb:
	/* 0x13cb: cmp    r12d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 10ULL);
x86_l_13cf:
	/* 0x13cf: jne    14bb <filter_char_buf_equal+0x37c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_14bb;
	}
x86_l_13d5:
	/* 0x13d5: mov    rdi,QWORD PTR [rip+0x1a5c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_10)));
x86_l_13dc:
	/* 0x13dc: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_13e1:
	/* 0x13e1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13e6:
	/* 0x13e6: jmp    1493 <filter_char_buf_equal+0x354> */
	goto x86_l_1493;
x86_l_13eb:
	/* 0x13eb: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_13ee:
	/* 0x13ee: je     1410 <filter_char_buf_equal+0x2d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1410;
	}
x86_l_13f0:
	/* 0x13f0: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_13f4:
	/* 0x13f4: jne    14bb <filter_char_buf_equal+0x37c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_14bb;
	}
x86_l_13fa:
	/* 0x13fa: mov    rdi,QWORD PTR [rip+0x1a5c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_1401:
	/* 0x1401: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1406:
	/* 0x1406: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_140b:
	/* 0x140b: jmp    1493 <filter_char_buf_equal+0x354> */
	goto x86_l_1493;
x86_l_1410:
	/* 0x1410: mov    rdi,QWORD PTR [rip+0x1a5c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_1417:
	/* 0x1417: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_141c:
	/* 0x141c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1421:
	/* 0x1421: jmp    1493 <filter_char_buf_equal+0x354> */
	goto x86_l_1493;
x86_l_1423:
	/* 0x1423: mov    rdi,QWORD PTR [rip+0x1a5c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_142a:
	/* 0x142a: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_142f:
	/* 0x142f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1434:
	/* 0x1434: jmp    1493 <filter_char_buf_equal+0x354> */
	goto x86_l_1493;
x86_l_1436:
	/* 0x1436: mov    rdi,QWORD PTR [rip+0x1a5c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_6)));
x86_l_143d:
	/* 0x143d: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1442:
	/* 0x1442: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1447:
	/* 0x1447: jmp    1493 <filter_char_buf_equal+0x354> */
	goto x86_l_1493;
x86_l_1449:
	/* 0x1449: mov    rdi,QWORD PTR [rip+0x1a5c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_9)));
x86_l_1450:
	/* 0x1450: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1455:
	/* 0x1455: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_145a:
	/* 0x145a: jmp    1493 <filter_char_buf_equal+0x354> */
	goto x86_l_1493;
x86_l_145c:
	/* 0x145c: mov    rdi,QWORD PTR [rip+0x1a5c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_1463:
	/* 0x1463: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1468:
	/* 0x1468: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_146d:
	/* 0x146d: jmp    1493 <filter_char_buf_equal+0x354> */
	goto x86_l_1493;
x86_l_146f:
	/* 0x146f: mov    rdi,QWORD PTR [rip+0x1a5c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_1476:
	/* 0x1476: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_147b:
	/* 0x147b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1480:
	/* 0x1480: jmp    1493 <filter_char_buf_equal+0x354> */
	goto x86_l_1493;
x86_l_1482:
	/* 0x1482: mov    rdi,QWORD PTR [rip+0x1a5c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_8)));
x86_l_1489:
	/* 0x1489: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_148e:
	/* 0x148e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1493:
	/* 0x1493: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1498:
	/* 0x1498: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_149a:
	/* 0x149a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_149d:
	/* 0x149d: je     14bb <filter_char_buf_equal+0x37c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14bb;
	}
x86_l_149f:
	/* 0x149f: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_14a2:
	/* 0x14a2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14a7:
	/* 0x14a7: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14ac:
	/* 0x14ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14ae:
	/* 0x14ae: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_14b1:
	/* 0x14b1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14b3:
	/* 0x14b3: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_14b6:
	/* 0x14b6: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_14b9:
	/* 0x14b9: jmp    14bd <filter_char_buf_equal+0x37e> */
	goto x86_l_14bd;
x86_l_14bb:
	/* 0x14bb: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14bd:
	/* 0x14bd: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_14c1:
	/* 0x14c1: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_14c2:
	/* 0x14c2: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_14c4:
	/* 0x14c4: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_14c6:
	/* 0x14c6: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_14c8:
	/* 0x14c8: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_14ca:
	/* 0x14ca: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_14cb:
	/* 0x14cb: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_14cc:
	/* 0x14cc: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_14cd:
	/* 0x14cd: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_14cf:
	/* 0x14cf: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_14d1:
	/* 0x14d1: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_14d3:
	/* 0x14d3: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_14d5:
	/* 0x14d5: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_14d6:
	/* 0x14d6: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_14d7:
	/* 0x14d7: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_14da:
	/* 0x14da: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_14dd:
	/* 0x14dd: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_14df:
	/* 0x14df: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_14e1:
	/* 0x14e1: je     15a9 <filter_char_substring+0xdd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15a9;
	}
x86_l_14e7:
	/* 0x14e7: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_14e9:
	/* 0x14e9: je     1646 <filter_char_substring+0x17a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5702ULL;
	}
x86_l_14ef:
	/* 0x14ef: lea    r13,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_14f4:
	/* 0x14f4: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14f6:
	/* 0x14f6: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14f9:
	/* 0x14f9: mov    eax,DWORD PTR [r14+rbx*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_14fe:
	/* 0x14fe: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1502:
	/* 0x1502: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1507:
	/* 0x1507: mov    rdi,QWORD PTR [rip+0x2093] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_150e:
	/* 0x150e: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1511:
	/* 0x1511: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1513:
	/* 0x1513: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1516:
	/* 0x1516: je     16ca <filter_char_substring+0x1fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5834ULL;
	}
x86_l_151c:
	/* 0x151c: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_151f:
	/* 0x151f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1521:
	/* 0x1521: jmp    152e <filter_char_substring+0x62> */
	goto x86_l_152e;
x86_l_1523:
	/* 0x1523: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1526:
	/* 0x1526: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1529:
	/* 0x1529: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_152c:
	/* 0x152c: je     1584 <filter_char_substring+0xb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1584;
	}
x86_l_152e:
	/* 0x152e: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1530:
	/* 0x1530: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_1534:
	/* 0x1534: cmp    rdi,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1537:
	/* 0x1537: jae    1523 <filter_char_substring+0x57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1523;
	}
x86_l_1539:
	/* 0x1539: movsx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_153d:
	/* 0x153d: test   edi,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_32);
x86_l_153f:
	/* 0x153f: je     157c <filter_char_substring+0xb0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_157c;
	}
x86_l_1541:
	/* 0x1541: movsx  r9d,BYTE PTR [rdx+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R9, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_1546:
	/* 0x1546: lea    r10d,[r9-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_154a:
	/* 0x154a: mov    r8d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R9, X86_WIDTH_32);
x86_l_154d:
	/* 0x154d: or     r8d,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_1551:
	/* 0x1551: cmp    r10d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 26ULL);
x86_l_1555:
	/* 0x1555: cmovae r8d,r9d */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_R9, X86_WIDTH_32, X86_CC_AE);
x86_l_1559:
	/* 0x1559: lea    r10d,[rdi-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_155d:
	/* 0x155d: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_1560:
	/* 0x1560: or     r9d,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_1564:
	/* 0x1564: cmp    r10d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 26ULL);
x86_l_1568:
	/* 0x1568: cmovae r9d,edi */
	X86_SIM_L_EXEC_CMOV(X86_R9, X86_RDI, X86_WIDTH_32, X86_CC_AE);
x86_l_156c:
	/* 0x156c: cmp    rsi,0x62 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 98ULL);
x86_l_1570:
	/* 0x1570: ja     1523 <filter_char_substring+0x57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1523;
	}
x86_l_1572:
	/* 0x1572: inc    rsi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1575:
	/* 0x1575: cmp    r8d,r9d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_R9, X86_WIDTH_32);
x86_l_1578:
	/* 0x1578: je     1530 <filter_char_substring+0x64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1530;
	}
x86_l_157a:
	/* 0x157a: jmp    1523 <filter_char_substring+0x57> */
	goto x86_l_1523;
x86_l_157c:
	/* 0x157c: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_157e:
	/* 0x157e: jns    16db <filter_char_substring+0x20f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 5851ULL;
	}
x86_l_1584:
	/* 0x1584: lea    eax,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1589:
	/* 0x1589: cmp    eax,DWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_158d:
	/* 0x158d: jae    16ca <filter_char_substring+0x1fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 5834ULL;
	}
x86_l_1593:
	/* 0x1593: add    r12d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1597:
	/* 0x1597: inc    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_159a:
	/* 0x159a: cmp    rbx,0x64 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 100ULL);
x86_l_159e:
	/* 0x159e: jne    14f9 <filter_char_substring+0x2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_14f9;
	}
x86_l_15a4:
	/* 0x15a4: jmp    16ca <filter_char_substring+0x1fe> */
	return 5834ULL;
x86_l_15a9:
	/* 0x15a9: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_15ab:
	/* 0x15ab: je     1689 <filter_char_substring+0x1bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5769ULL;
	}
x86_l_15b1:
	/* 0x15b1: lea    r13,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_15b6:
	/* 0x15b6: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15b8:
	/* 0x15b8: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15bb:
	/* 0x15bb: mov    eax,DWORD PTR [r14+rbx*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_15c0:
	/* 0x15c0: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_15c4:
	/* 0x15c4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15c9:
	/* 0x15c9: mov    rdi,QWORD PTR [rip+0x20a1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_15d0:
	/* 0x15d0: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_15d3:
	/* 0x15d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15d5:
	/* 0x15d5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15d8:
	/* 0x15d8: je     16ca <filter_char_substring+0x1fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5834ULL;
	}
x86_l_15de:
	/* 0x15de: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_15e1:
	/* 0x15e1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15e3:
	/* 0x15e3: jmp    15f0 <filter_char_substring+0x124> */
	goto x86_l_15f0;
x86_l_15e5:
	/* 0x15e5: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_15e8:
	/* 0x15e8: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_15eb:
	/* 0x15eb: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_15ee:
	/* 0x15ee: je     1621 <filter_char_substring+0x155> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5665ULL;
	}
x86_l_15f0:
	/* 0x15f0: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15f2:
	/* 0x15f2: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_15f6:
	/* 0x15f6: cmp    rdi,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_15f9:
	/* 0x15f9: jae    15e5 <filter_char_substring+0x119> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_15e5;
	}
x86_l_15fb:
	/* 0x15fb: movzx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_15ff:
	/* 0x15ff: test   dil,dil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_8);
x86_l_1602:
	/* 0x1602: je     1619 <filter_char_substring+0x14d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5657ULL;
	}
x86_l_1604:
	/* 0x1604: cmp    rsi,0x62 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 98ULL);
x86_l_1608:
	/* 0x1608: ja     15e5 <filter_char_substring+0x119> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_15e5;
	}
	return 5642ULL;
}

static __noinline __u64 tetragon_bpf_generic_retuprobe_v61_generic_retuprobe_filter_arg_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5642ULL: goto x86_l_160a;
	case 5646ULL: goto x86_l_160e;
	case 5650ULL: goto x86_l_1612;
	case 5653ULL: goto x86_l_1615;
	case 5655ULL: goto x86_l_1617;
	case 5657ULL: goto x86_l_1619;
	case 5659ULL: goto x86_l_161b;
	case 5665ULL: goto x86_l_1621;
	case 5670ULL: goto x86_l_1626;
	case 5674ULL: goto x86_l_162a;
	case 5680ULL: goto x86_l_1630;
	case 5684ULL: goto x86_l_1634;
	case 5687ULL: goto x86_l_1637;
	case 5691ULL: goto x86_l_163b;
	case 5697ULL: goto x86_l_1641;
	case 5702ULL: goto x86_l_1646;
	case 5707ULL: goto x86_l_164b;
	case 5714ULL: goto x86_l_1652;
	case 5719ULL: goto x86_l_1657;
	case 5723ULL: goto x86_l_165b;
	case 5727ULL: goto x86_l_165f;
	case 5732ULL: goto x86_l_1664;
	case 5735ULL: goto x86_l_1667;
	case 5738ULL: goto x86_l_166a;
	case 5740ULL: goto x86_l_166c;
	case 5743ULL: goto x86_l_166f;
	case 5745ULL: goto x86_l_1671;
	case 5749ULL: goto x86_l_1675;
	case 5752ULL: goto x86_l_1678;
	case 5756ULL: goto x86_l_167c;
	case 5758ULL: goto x86_l_167e;
	case 5765ULL: goto x86_l_1685;
	case 5767ULL: goto x86_l_1687;
	case 5769ULL: goto x86_l_1689;
	case 5774ULL: goto x86_l_168e;
	case 5781ULL: goto x86_l_1695;
	case 5786ULL: goto x86_l_169a;
	case 5790ULL: goto x86_l_169e;
	case 5794ULL: goto x86_l_16a2;
	case 5799ULL: goto x86_l_16a7;
	case 5802ULL: goto x86_l_16aa;
	case 5805ULL: goto x86_l_16ad;
	case 5807ULL: goto x86_l_16af;
	case 5810ULL: goto x86_l_16b2;
	case 5812ULL: goto x86_l_16b4;
	case 5816ULL: goto x86_l_16b8;
	case 5819ULL: goto x86_l_16bb;
	case 5823ULL: goto x86_l_16bf;
	case 5825ULL: goto x86_l_16c1;
	case 5832ULL: goto x86_l_16c8;
	case 5834ULL: goto x86_l_16ca;
	case 5836ULL: goto x86_l_16cc;
	case 5840ULL: goto x86_l_16d0;
	case 5841ULL: goto x86_l_16d1;
	case 5843ULL: goto x86_l_16d3;
	case 5845ULL: goto x86_l_16d5;
	case 5847ULL: goto x86_l_16d7;
	case 5849ULL: goto x86_l_16d9;
	case 5850ULL: goto x86_l_16da;
	case 5851ULL: goto x86_l_16db;
	case 5856ULL: goto x86_l_16e0;
	case 5858ULL: goto x86_l_16e2;
	case 5861ULL: goto x86_l_16e5;
	case 5866ULL: goto x86_l_16ea;
	case 5870ULL: goto x86_l_16ee;
	case 5872ULL: goto x86_l_16f0;
	case 5882ULL: goto x86_l_16fa;
	case 5886ULL: goto x86_l_16fe;
	case 5888ULL: goto x86_l_1700;
	case 5889ULL: goto x86_l_1701;
	case 5894ULL: goto x86_l_1706;
	case 5898ULL: goto x86_l_170a;
	case 5900ULL: goto x86_l_170c;
	case 5903ULL: goto x86_l_170f;
	case 5906ULL: goto x86_l_1712;
	case 5912ULL: goto x86_l_1718;
	case 5914ULL: goto x86_l_171a;
	case 5917ULL: goto x86_l_171d;
	case 5920ULL: goto x86_l_1720;
	case 5921ULL: goto x86_l_1721;
	case 5925ULL: goto x86_l_1725;
	case 5927ULL: goto x86_l_1727;
	case 5930ULL: goto x86_l_172a;
	case 5933ULL: goto x86_l_172d;
	case 5935ULL: goto x86_l_172f;
	case 5938ULL: goto x86_l_1732;
	case 5941ULL: goto x86_l_1735;
	case 5947ULL: goto x86_l_173b;
	case 5950ULL: goto x86_l_173e;
	case 5952ULL: goto x86_l_1740;
	case 5955ULL: goto x86_l_1743;
	case 5961ULL: goto x86_l_1749;
	case 5964ULL: goto x86_l_174c;
	case 5966ULL: goto x86_l_174e;
	case 5969ULL: goto x86_l_1751;
	case 5975ULL: goto x86_l_1757;
	case 5978ULL: goto x86_l_175a;
	case 5980ULL: goto x86_l_175c;
	case 5985ULL: goto x86_l_1761;
	case 5988ULL: goto x86_l_1764;
	case 5990ULL: goto x86_l_1766;
	case 5993ULL: goto x86_l_1769;
	case 5999ULL: goto x86_l_176f;
	case 6002ULL: goto x86_l_1772;
	case 6005ULL: goto x86_l_1775;
	case 6011ULL: goto x86_l_177b;
	case 6016ULL: goto x86_l_1780;
	case 6019ULL: goto x86_l_1783;
	case 6025ULL: goto x86_l_1789;
	case 6028ULL: goto x86_l_178c;
	case 6031ULL: goto x86_l_178f;
	case 6037ULL: goto x86_l_1795;
	case 6040ULL: goto x86_l_1798;
	case 6043ULL: goto x86_l_179b;
	case 6049ULL: goto x86_l_17a1;
	case 6052ULL: goto x86_l_17a4;
	case 6058ULL: goto x86_l_17aa;
	case 6061ULL: goto x86_l_17ad;
	case 6067ULL: goto x86_l_17b3;
	case 6070ULL: goto x86_l_17b6;
	case 6076ULL: goto x86_l_17bc;
	case 6079ULL: goto x86_l_17bf;
	case 6085ULL: goto x86_l_17c5;
	case 6088ULL: goto x86_l_17c8;
	case 6094ULL: goto x86_l_17ce;
	case 6099ULL: goto x86_l_17d3;
	case 6102ULL: goto x86_l_17d6;
	case 6105ULL: goto x86_l_17d9;
	case 6111ULL: goto x86_l_17df;
	case 6116ULL: goto x86_l_17e4;
	case 6119ULL: goto x86_l_17e7;
	case 6125ULL: goto x86_l_17ed;
	case 6128ULL: goto x86_l_17f0;
	case 6131ULL: goto x86_l_17f3;
	case 6137ULL: goto x86_l_17f9;
	case 6140ULL: goto x86_l_17fc;
	case 6143ULL: goto x86_l_17ff;
	case 6149ULL: goto x86_l_1805;
	case 6152ULL: goto x86_l_1808;
	case 6158ULL: goto x86_l_180e;
	case 6161ULL: goto x86_l_1811;
	case 6167ULL: goto x86_l_1817;
	case 6170ULL: goto x86_l_181a;
	case 6176ULL: goto x86_l_1820;
	case 6179ULL: goto x86_l_1823;
	case 6185ULL: goto x86_l_1829;
	case 6188ULL: goto x86_l_182c;
	case 6194ULL: goto x86_l_1832;
	case 6199ULL: goto x86_l_1837;
	case 6202ULL: goto x86_l_183a;
	case 6205ULL: goto x86_l_183d;
	case 6207ULL: goto x86_l_183f;
	case 6210ULL: goto x86_l_1842;
	case 6216ULL: goto x86_l_1848;
	case 6219ULL: goto x86_l_184b;
	case 6221ULL: goto x86_l_184d;
	case 6224ULL: goto x86_l_1850;
	case 6230ULL: goto x86_l_1856;
	case 6233ULL: goto x86_l_1859;
	case 6235ULL: goto x86_l_185b;
	case 6238ULL: goto x86_l_185e;
	case 6244ULL: goto x86_l_1864;
	case 6247ULL: goto x86_l_1867;
	case 6253ULL: goto x86_l_186d;
	case 6255ULL: goto x86_l_186f;
	case 6265ULL: goto x86_l_1879;
	case 6269ULL: goto x86_l_187d;
	case 6275ULL: goto x86_l_1883;
	case 6277ULL: goto x86_l_1885;
	case 6280ULL: goto x86_l_1888;
	case 6283ULL: goto x86_l_188b;
	case 6289ULL: goto x86_l_1891;
	case 6292ULL: goto x86_l_1894;
	case 6295ULL: goto x86_l_1897;
	case 6297ULL: goto x86_l_1899;
	case 6300ULL: goto x86_l_189c;
	case 6306ULL: goto x86_l_18a2;
	case 6309ULL: goto x86_l_18a5;
	case 6311ULL: goto x86_l_18a7;
	case 6314ULL: goto x86_l_18aa;
	case 6320ULL: goto x86_l_18b0;
	case 6323ULL: goto x86_l_18b3;
	case 6325ULL: goto x86_l_18b5;
	case 6328ULL: goto x86_l_18b8;
	case 6334ULL: goto x86_l_18be;
	case 6336ULL: goto x86_l_18c0;
	case 6339ULL: goto x86_l_18c3;
	case 6342ULL: goto x86_l_18c6;
	case 6348ULL: goto x86_l_18cc;
	case 6351ULL: goto x86_l_18cf;
	case 6354ULL: goto x86_l_18d2;
	case 6356ULL: goto x86_l_18d4;
	case 6359ULL: goto x86_l_18d7;
	case 6365ULL: goto x86_l_18dd;
	case 6368ULL: goto x86_l_18e0;
	case 6370ULL: goto x86_l_18e2;
	case 6373ULL: goto x86_l_18e5;
	case 6379ULL: goto x86_l_18eb;
	case 6382ULL: goto x86_l_18ee;
	case 6384ULL: goto x86_l_18f0;
	case 6387ULL: goto x86_l_18f3;
	case 6393ULL: goto x86_l_18f9;
	case 6395ULL: goto x86_l_18fb;
	case 6396ULL: goto x86_l_18fc;
	case 6399ULL: goto x86_l_18ff;
	case 6402ULL: goto x86_l_1902;
	case 6405ULL: goto x86_l_1905;
	case 6411ULL: goto x86_l_190b;
	case 6416ULL: goto x86_l_1910;
	case 6419ULL: goto x86_l_1913;
	case 6425ULL: goto x86_l_1919;
	case 6428ULL: goto x86_l_191c;
	case 6431ULL: goto x86_l_191f;
	case 6433ULL: goto x86_l_1921;
	case 6438ULL: goto x86_l_1926;
	case 6441ULL: goto x86_l_1929;
	case 6443ULL: goto x86_l_192b;
	case 6446ULL: goto x86_l_192e;
	case 6452ULL: goto x86_l_1934;
	case 6455ULL: goto x86_l_1937;
	case 6458ULL: goto x86_l_193a;
	case 6464ULL: goto x86_l_1940;
	case 6467ULL: goto x86_l_1943;
	case 6469ULL: goto x86_l_1945;
	case 6472ULL: goto x86_l_1948;
	case 6478ULL: goto x86_l_194e;
	case 6481ULL: goto x86_l_1951;
	case 6487ULL: goto x86_l_1957;
	case 6490ULL: goto x86_l_195a;
	case 6492ULL: goto x86_l_195c;
	case 6495ULL: goto x86_l_195f;
	case 6501ULL: goto x86_l_1965;
	case 6504ULL: goto x86_l_1968;
	case 6510ULL: goto x86_l_196e;
	case 6512ULL: goto x86_l_1970;
	case 6515ULL: goto x86_l_1973;
	case 6521ULL: goto x86_l_1979;
	case 6524ULL: goto x86_l_197c;
	case 6530ULL: goto x86_l_1982;
	case 6535ULL: goto x86_l_1987;
	case 6538ULL: goto x86_l_198a;
	case 6541ULL: goto x86_l_198d;
	case 6545ULL: goto x86_l_1991;
	case 6548ULL: goto x86_l_1994;
	case 6551ULL: goto x86_l_1997;
	case 6554ULL: goto x86_l_199a;
	case 6557ULL: goto x86_l_199d;
	case 6563ULL: goto x86_l_19a3;
	case 6566ULL: goto x86_l_19a6;
	case 6570ULL: goto x86_l_19aa;
	case 6573ULL: goto x86_l_19ad;
	case 6577ULL: goto x86_l_19b1;
	case 6580ULL: goto x86_l_19b4;
	case 6583ULL: goto x86_l_19b7;
	case 6586ULL: goto x86_l_19ba;
	case 6592ULL: goto x86_l_19c0;
	case 6595ULL: goto x86_l_19c3;
	case 6599ULL: goto x86_l_19c7;
	case 6602ULL: goto x86_l_19ca;
	case 6606ULL: goto x86_l_19ce;
	case 6609ULL: goto x86_l_19d1;
	case 6612ULL: goto x86_l_19d4;
	case 6615ULL: goto x86_l_19d7;
	case 6621ULL: goto x86_l_19dd;
	case 6624ULL: goto x86_l_19e0;
	case 6627ULL: goto x86_l_19e3;
	case 6630ULL: goto x86_l_19e6;
	case 6634ULL: goto x86_l_19ea;
	case 6636ULL: goto x86_l_19ec;
	case 6639ULL: goto x86_l_19ef;
	case 6642ULL: goto x86_l_19f2;
	case 6644ULL: goto x86_l_19f4;
	case 6649ULL: goto x86_l_19f9;
	case 6652ULL: goto x86_l_19fc;
	case 6654ULL: goto x86_l_19fe;
	case 6657ULL: goto x86_l_1a01;
	case 6659ULL: goto x86_l_1a03;
	case 6660ULL: goto x86_l_1a04;
	case 6663ULL: goto x86_l_1a07;
	case 6666ULL: goto x86_l_1a0a;
	case 6670ULL: goto x86_l_1a0e;
	case 6673ULL: goto x86_l_1a11;
	case 6676ULL: goto x86_l_1a14;
	case 6679ULL: goto x86_l_1a17;
	case 6682ULL: goto x86_l_1a1a;
	case 6688ULL: goto x86_l_1a20;
	case 6691ULL: goto x86_l_1a23;
	case 6695ULL: goto x86_l_1a27;
	case 6698ULL: goto x86_l_1a2a;
	case 6702ULL: goto x86_l_1a2e;
	case 6705ULL: goto x86_l_1a31;
	case 6708ULL: goto x86_l_1a34;
	case 6711ULL: goto x86_l_1a37;
	case 6713ULL: goto x86_l_1a39;
	case 6716ULL: goto x86_l_1a3c;
	case 6720ULL: goto x86_l_1a40;
	case 6723ULL: goto x86_l_1a43;
	case 6727ULL: goto x86_l_1a47;
	case 6730ULL: goto x86_l_1a4a;
	case 6733ULL: goto x86_l_1a4d;
	case 6736ULL: goto x86_l_1a50;
	case 6738ULL: goto x86_l_1a52;
	case 6741ULL: goto x86_l_1a55;
	case 6744ULL: goto x86_l_1a58;
	case 6747ULL: goto x86_l_1a5b;
	case 6751ULL: goto x86_l_1a5f;
	case 6754ULL: goto x86_l_1a62;
	case 6757ULL: goto x86_l_1a65;
	case 6759ULL: goto x86_l_1a67;
	case 6762ULL: goto x86_l_1a6a;
	case 6765ULL: goto x86_l_1a6d;
	case 6767ULL: goto x86_l_1a6f;
	case 6770ULL: goto x86_l_1a72;
	case 6772ULL: goto x86_l_1a74;
	case 6775ULL: goto x86_l_1a77;
	case 6777ULL: goto x86_l_1a79;
	case 6780ULL: goto x86_l_1a7c;
	case 6782ULL: goto x86_l_1a7e;
	case 6785ULL: goto x86_l_1a81;
	case 6787ULL: goto x86_l_1a83;
	case 6790ULL: goto x86_l_1a86;
	case 6796ULL: goto x86_l_1a8c;
	case 6799ULL: goto x86_l_1a8f;
	case 6801ULL: goto x86_l_1a91;
	case 6803ULL: goto x86_l_1a93;
	case 6806ULL: goto x86_l_1a96;
	case 6808ULL: goto x86_l_1a98;
	case 6811ULL: goto x86_l_1a9b;
	case 6817ULL: goto x86_l_1aa1;
	case 6819ULL: goto x86_l_1aa3;
	case 6821ULL: goto x86_l_1aa5;
	case 6824ULL: goto x86_l_1aa8;
	case 6827ULL: goto x86_l_1aab;
	case 6830ULL: goto x86_l_1aae;
	case 6832ULL: goto x86_l_1ab0;
	case 6835ULL: goto x86_l_1ab3;
	case 6836ULL: goto x86_l_1ab4;
	case 6838ULL: goto x86_l_1ab6;
	case 6839ULL: goto x86_l_1ab7;
	case 6843ULL: goto x86_l_1abb;
	case 6846ULL: goto x86_l_1abe;
	case 6849ULL: goto x86_l_1ac1;
	case 6853ULL: goto x86_l_1ac5;
	case 6857ULL: goto x86_l_1ac9;
	case 6864ULL: goto x86_l_1ad0;
	case 6869ULL: goto x86_l_1ad5;
	case 6874ULL: goto x86_l_1ada;
	case 6876ULL: goto x86_l_1adc;
	case 6879ULL: goto x86_l_1adf;
	case 6881ULL: goto x86_l_1ae1;
	case 6884ULL: goto x86_l_1ae4;
	case 6888ULL: goto x86_l_1ae8;
	case 6893ULL: goto x86_l_1aed;
	case 6898ULL: goto x86_l_1af2;
	case 6903ULL: goto x86_l_1af7;
	case 6905ULL: goto x86_l_1af9;
	case 6908ULL: goto x86_l_1afc;
	case 6910ULL: goto x86_l_1afe;
	case 6913ULL: goto x86_l_1b01;
	case 6915ULL: goto x86_l_1b03;
	case 6920ULL: goto x86_l_1b08;
	case 6923ULL: goto x86_l_1b0b;
	case 6925ULL: goto x86_l_1b0d;
	case 6928ULL: goto x86_l_1b10;
	case 6931ULL: goto x86_l_1b13;
	case 6933ULL: goto x86_l_1b15;
	case 6935ULL: goto x86_l_1b17;
	case 6939ULL: goto x86_l_1b1b;
	case 6940ULL: goto x86_l_1b1c;
	case 6942ULL: goto x86_l_1b1e;
	case 6943ULL: goto x86_l_1b1f;
	case 6948ULL: goto x86_l_1b24;
	case 6951ULL: goto x86_l_1b27;
	case 6953ULL: goto x86_l_1b29;
	case 6956ULL: goto x86_l_1b2c;
	case 6959ULL: goto x86_l_1b2f;
	case 6962ULL: goto x86_l_1b32;
	case 6966ULL: goto x86_l_1b36;
	case 6967ULL: goto x86_l_1b37;
	case 6969ULL: goto x86_l_1b39;
	case 6970ULL: goto x86_l_1b3a;
	case 6973ULL: goto x86_l_1b3d;
	case 6978ULL: goto x86_l_1b42;
	case 6982ULL: goto x86_l_1b46;
	default: return 0xffffffffffffffffULL;
	}
x86_l_160a:
	/* 0x160a: lea    r8,[rsi+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_160e:
	/* 0x160e: cmp    BYTE PTR [rdx+rsi*1],dil */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDX, X86_RDI, X86_WIDTH_8, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_1612:
	/* 0x1612: mov    rsi,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R8, X86_WIDTH_64);
x86_l_1615:
	/* 0x1615: je     15f2 <filter_char_substring+0x126> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5618ULL;
	}
x86_l_1617:
	/* 0x1617: jmp    15e5 <filter_char_substring+0x119> */
	return 5605ULL;
x86_l_1619:
	/* 0x1619: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_161b:
	/* 0x161b: jns    16db <filter_char_substring+0x20f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_16db;
	}
x86_l_1621:
	/* 0x1621: lea    eax,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1626:
	/* 0x1626: cmp    eax,DWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_162a:
	/* 0x162a: jae    16ca <filter_char_substring+0x1fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_16ca;
	}
x86_l_1630:
	/* 0x1630: add    r12d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1634:
	/* 0x1634: inc    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1637:
	/* 0x1637: cmp    rbx,0x64 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 100ULL);
x86_l_163b:
	/* 0x163b: jne    15bb <filter_char_substring+0xef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5563ULL;
	}
x86_l_1641:
	/* 0x1641: jmp    16ca <filter_char_substring+0x1fe> */
	goto x86_l_16ca;
x86_l_1646:
	/* 0x1646: mov    ebx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 16ULL);
x86_l_164b:
	/* 0x164b: mov    r15,QWORD PTR [rip+0x20b3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_1652:
	/* 0x1652: lea    r12,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1657:
	/* 0x1657: mov    eax,DWORD PTR [r14+rbx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_165b:
	/* 0x165b: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_165f:
	/* 0x165f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1664:
	/* 0x1664: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1667:
	/* 0x1667: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_166a:
	/* 0x166a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_166c:
	/* 0x166c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_166f:
	/* 0x166f: je     16ca <filter_char_substring+0x1fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16ca;
	}
x86_l_1671:
	/* 0x1671: add    rbx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1675:
	/* 0x1675: lea    eax,[rbx-0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551608ULL);
x86_l_1678:
	/* 0x1678: cmp    eax,DWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_167c:
	/* 0x167c: jae    16ca <filter_char_substring+0x1fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_16ca;
	}
x86_l_167e:
	/* 0x167e: cmp    rbx,0x1a0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 416ULL);
x86_l_1685:
	/* 0x1685: jne    1657 <filter_char_substring+0x18b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1657;
	}
x86_l_1687:
	/* 0x1687: jmp    16ca <filter_char_substring+0x1fe> */
	goto x86_l_16ca;
x86_l_1689:
	/* 0x1689: mov    ebx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 16ULL);
x86_l_168e:
	/* 0x168e: mov    r15,QWORD PTR [rip+0x20b5] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_1695:
	/* 0x1695: lea    r12,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_169a:
	/* 0x169a: mov    eax,DWORD PTR [r14+rbx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_169e:
	/* 0x169e: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_16a2:
	/* 0x16a2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16a7:
	/* 0x16a7: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_16aa:
	/* 0x16aa: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_16ad:
	/* 0x16ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16af:
	/* 0x16af: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16b2:
	/* 0x16b2: je     16ca <filter_char_substring+0x1fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16ca;
	}
x86_l_16b4:
	/* 0x16b4: add    rbx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_16b8:
	/* 0x16b8: lea    eax,[rbx-0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551608ULL);
x86_l_16bb:
	/* 0x16bb: cmp    eax,DWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_16bf:
	/* 0x16bf: jae    16ca <filter_char_substring+0x1fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_16ca;
	}
x86_l_16c1:
	/* 0x16c1: cmp    rbx,0x1a0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 416ULL);
x86_l_16c8:
	/* 0x16c8: jne    169a <filter_char_substring+0x1ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_169a;
	}
x86_l_16ca:
	/* 0x16ca: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16cc:
	/* 0x16cc: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_16d0:
	/* 0x16d0: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_16d1:
	/* 0x16d1: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_16d3:
	/* 0x16d3: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_16d5:
	/* 0x16d5: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_16d7:
	/* 0x16d7: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_16d9:
	/* 0x16d9: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_16da:
	/* 0x16da: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_16db:
	/* 0x16db: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16e0:
	/* 0x16e0: jmp    16cc <filter_char_substring+0x200> */
	goto x86_l_16cc;
x86_l_16e2:
	/* 0x16e2: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_16e5:
	/* 0x16e5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16ea:
	/* 0x16ea: cmp    rcx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 37ULL);
x86_l_16ee:
	/* 0x16ee: ja     1761 <filter_16ty_selector_val+0x7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1761;
	}
x86_l_16f0:
	/* 0x16f0: movabs rdx,0x200c000040 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280128ULL);
x86_l_16fa:
	/* 0x16fa: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_16fe:
	/* 0x16fe: jae    1701 <filter_16ty_selector_val+0x1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1701;
	}
x86_l_1700:
	/* 0x1700: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1701:
	/* 0x1701: mov    edx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 24ULL);
x86_l_1706:
	/* 0x1706: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_170a:
	/* 0x170a: jae    1721 <filter_16ty_selector_val+0x3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1721;
	}
x86_l_170c:
	/* 0x170c: movzx  edx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_170f:
	/* 0x170f: cmp    DWORD PTR [rdi+0x10],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1712:
	/* 0x1712: jne    1837 <filter_16ty_selector_val+0x155> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1837;
	}
x86_l_1718:
	/* 0x1718: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_171a:
	/* 0x171a: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_171d:
	/* 0x171d: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_1720:
	/* 0x1720: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1721:
	/* 0x1721: cmp    rcx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 12ULL);
x86_l_1725:
	/* 0x1725: jne    1761 <filter_16ty_selector_val+0x7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1761;
	}
x86_l_1727:
	/* 0x1727: movzx  ecx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_172a:
	/* 0x172a: test   DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_172d:
	/* 0x172d: jne    1700 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1700;
	}
x86_l_172f:
	/* 0x172f: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1732:
	/* 0x1732: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1735:
	/* 0x1735: jb     18f9 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18f9;
	}
x86_l_173b:
	/* 0x173b: test   DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_173e:
	/* 0x173e: jne    1700 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1700;
	}
x86_l_1740:
	/* 0x1740: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1743:
	/* 0x1743: jb     18f9 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18f9;
	}
x86_l_1749:
	/* 0x1749: test   DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_174c:
	/* 0x174c: jne    1700 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1700;
	}
x86_l_174e:
	/* 0x174e: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_1751:
	/* 0x1751: jb     18f9 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18f9;
	}
x86_l_1757:
	/* 0x1757: test   DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_175a:
	/* 0x175a: jne    1700 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1700;
	}
x86_l_175c:
	/* 0x175c: jmp    18f9 <filter_16ty_selector_val+0x217> */
	goto x86_l_18f9;
x86_l_1761:
	/* 0x1761: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1764:
	/* 0x1764: je     17d3 <filter_16ty_selector_val+0xf1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17d3;
	}
x86_l_1766:
	/* 0x1766: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1769:
	/* 0x1769: jne    18f9 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_18f9;
	}
x86_l_176f:
	/* 0x176f: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1772:
	/* 0x1772: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1775:
	/* 0x1775: ja     18c0 <filter_16ty_selector_val+0x1de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_18c0;
	}
x86_l_177b:
	/* 0x177b: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_1780:
	/* 0x1780: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_1783:
	/* 0x1783: jae    18c0 <filter_16ty_selector_val+0x1de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_18c0;
	}
x86_l_1789:
	/* 0x1789: movsx  ecx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_178c:
	/* 0x178c: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_178f:
	/* 0x178f: jg     1700 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1700;
	}
x86_l_1795:
	/* 0x1795: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1798:
	/* 0x1798: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_179b:
	/* 0x179b: jb     18f9 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18f9;
	}
x86_l_17a1:
	/* 0x17a1: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_17a4:
	/* 0x17a4: jg     1700 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1700;
	}
x86_l_17aa:
	/* 0x17aa: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_17ad:
	/* 0x17ad: jb     18f9 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18f9;
	}
x86_l_17b3:
	/* 0x17b3: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_17b6:
	/* 0x17b6: jg     1700 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1700;
	}
x86_l_17bc:
	/* 0x17bc: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_17bf:
	/* 0x17bf: jb     18f9 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18f9;
	}
x86_l_17c5:
	/* 0x17c5: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_17c8:
	/* 0x17c8: jg     1700 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1700;
	}
x86_l_17ce:
	/* 0x17ce: jmp    18f9 <filter_16ty_selector_val+0x217> */
	goto x86_l_18f9;
x86_l_17d3:
	/* 0x17d3: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_17d6:
	/* 0x17d6: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_17d9:
	/* 0x17d9: ja     1885 <filter_16ty_selector_val+0x1a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1885;
	}
x86_l_17df:
	/* 0x17df: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_17e4:
	/* 0x17e4: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_17e7:
	/* 0x17e7: jae    1885 <filter_16ty_selector_val+0x1a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1885;
	}
x86_l_17ed:
	/* 0x17ed: movsx  ecx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_17f0:
	/* 0x17f0: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17f3:
	/* 0x17f3: jl     1700 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_1700;
	}
x86_l_17f9:
	/* 0x17f9: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17fc:
	/* 0x17fc: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_17ff:
	/* 0x17ff: jb     18f9 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18f9;
	}
x86_l_1805:
	/* 0x1805: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1808:
	/* 0x1808: jl     1700 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_1700;
	}
x86_l_180e:
	/* 0x180e: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1811:
	/* 0x1811: jb     18f9 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18f9;
	}
x86_l_1817:
	/* 0x1817: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_181a:
	/* 0x181a: jl     1700 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_1700;
	}
x86_l_1820:
	/* 0x1820: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_1823:
	/* 0x1823: jb     18f9 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18f9;
	}
x86_l_1829:
	/* 0x1829: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_182c:
	/* 0x182c: jl     1700 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_1700;
	}
x86_l_1832:
	/* 0x1832: jmp    18f9 <filter_16ty_selector_val+0x217> */
	goto x86_l_18f9;
x86_l_1837:
	/* 0x1837: mov    esi,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_183a:
	/* 0x183a: cmp    esi,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 13ULL);
x86_l_183d:
	/* 0x183d: jb     1864 <filter_16ty_selector_val+0x182> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1864;
	}
x86_l_183f:
	/* 0x183f: cmp    DWORD PTR [rdi+0x14],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1842:
	/* 0x1842: je     1718 <filter_16ty_selector_val+0x36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1718;
	}
x86_l_1848:
	/* 0x1848: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_184b:
	/* 0x184b: jb     1864 <filter_16ty_selector_val+0x182> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1864;
	}
x86_l_184d:
	/* 0x184d: cmp    DWORD PTR [rdi+0x18],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1850:
	/* 0x1850: je     1718 <filter_16ty_selector_val+0x36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1718;
	}
x86_l_1856:
	/* 0x1856: cmp    esi,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 21ULL);
x86_l_1859:
	/* 0x1859: jb     1864 <filter_16ty_selector_val+0x182> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1864;
	}
x86_l_185b:
	/* 0x185b: cmp    DWORD PTR [rdi+0x1c],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_185e:
	/* 0x185e: je     1718 <filter_16ty_selector_val+0x36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1718;
	}
x86_l_1864:
	/* 0x1864: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_1867:
	/* 0x1867: ja     18f9 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_18f9;
	}
x86_l_186d:
	/* 0x186d: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_186f:
	/* 0x186f: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_1879:
	/* 0x1879: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_187d:
	/* 0x187d: jb     1700 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1700;
	}
x86_l_1883:
	/* 0x1883: jmp    18f9 <filter_16ty_selector_val+0x217> */
	goto x86_l_18f9;
x86_l_1885:
	/* 0x1885: movzx  ecx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1888:
	/* 0x1888: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_188b:
	/* 0x188b: jb     1700 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1700;
	}
x86_l_1891:
	/* 0x1891: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1894:
	/* 0x1894: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1897:
	/* 0x1897: jb     18f9 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18f9;
	}
x86_l_1899:
	/* 0x1899: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_189c:
	/* 0x189c: jb     1700 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1700;
	}
x86_l_18a2:
	/* 0x18a2: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_18a5:
	/* 0x18a5: jb     18f9 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18f9;
	}
x86_l_18a7:
	/* 0x18a7: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18aa:
	/* 0x18aa: jb     1700 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1700;
	}
x86_l_18b0:
	/* 0x18b0: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_18b3:
	/* 0x18b3: jb     18f9 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18f9;
	}
x86_l_18b5:
	/* 0x18b5: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_18b8:
	/* 0x18b8: jb     1700 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1700;
	}
x86_l_18be:
	/* 0x18be: jmp    18f9 <filter_16ty_selector_val+0x217> */
	goto x86_l_18f9;
x86_l_18c0:
	/* 0x18c0: movzx  ecx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_18c3:
	/* 0x18c3: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18c6:
	/* 0x18c6: ja     1700 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1700;
	}
x86_l_18cc:
	/* 0x18cc: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18cf:
	/* 0x18cf: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_18d2:
	/* 0x18d2: jb     18f9 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18f9;
	}
x86_l_18d4:
	/* 0x18d4: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_18d7:
	/* 0x18d7: ja     1700 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1700;
	}
x86_l_18dd:
	/* 0x18dd: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_18e0:
	/* 0x18e0: jb     18f9 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18f9;
	}
x86_l_18e2:
	/* 0x18e2: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18e5:
	/* 0x18e5: ja     1700 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1700;
	}
x86_l_18eb:
	/* 0x18eb: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_18ee:
	/* 0x18ee: jb     18f9 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18f9;
	}
x86_l_18f0:
	/* 0x18f0: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_18f3:
	/* 0x18f3: ja     1700 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1700;
	}
x86_l_18f9:
	/* 0x18f9: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18fb:
	/* 0x18fb: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_18fc:
	/* 0x18fc: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_18ff:
	/* 0x18ff: mov    eax,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1902:
	/* 0x1902: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1905:
	/* 0x1905: ja     19ec <filter_16ty_range+0xf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_19ec;
	}
x86_l_190b:
	/* 0x190b: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_1910:
	/* 0x1910: bt     edx,eax */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_1913:
	/* 0x1913: jae    19ec <filter_16ty_range+0xf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_19ec;
	}
x86_l_1919:
	/* 0x1919: movsx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_191c:
	/* 0x191c: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_191f:
	/* 0x191f: jne    1987 <filter_16ty_range+0x8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1987;
	}
x86_l_1921:
	/* 0x1921: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1926:
	/* 0x1926: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1929:
	/* 0x1929: jg     1934 <filter_16ty_range+0x38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1934;
	}
x86_l_192b:
	/* 0x192b: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_192e:
	/* 0x192e: jge    1a03 <filter_16ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_GE)) {
		goto x86_l_1a03;
	}
x86_l_1934:
	/* 0x1934: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1937:
	/* 0x1937: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_193a:
	/* 0x193a: jb     1aa3 <filter_16ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1aa3;
	}
x86_l_1940:
	/* 0x1940: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1943:
	/* 0x1943: jg     194e <filter_16ty_range+0x52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_194e;
	}
x86_l_1945:
	/* 0x1945: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1948:
	/* 0x1948: jge    1a03 <filter_16ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_GE)) {
		goto x86_l_1a03;
	}
x86_l_194e:
	/* 0x194e: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_1951:
	/* 0x1951: jb     1aa3 <filter_16ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1aa3;
	}
x86_l_1957:
	/* 0x1957: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_195a:
	/* 0x195a: jg     1965 <filter_16ty_range+0x69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1965;
	}
x86_l_195c:
	/* 0x195c: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_195f:
	/* 0x195f: jge    1a03 <filter_16ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_GE)) {
		goto x86_l_1a03;
	}
x86_l_1965:
	/* 0x1965: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_1968:
	/* 0x1968: jb     1aa3 <filter_16ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1aa3;
	}
x86_l_196e:
	/* 0x196e: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1970:
	/* 0x1970: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1973:
	/* 0x1973: jg     1aa5 <filter_16ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1aa5;
	}
x86_l_1979:
	/* 0x1979: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_197c:
	/* 0x197c: jge    1a03 <filter_16ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_GE)) {
		goto x86_l_1a03;
	}
x86_l_1982:
	/* 0x1982: jmp    1aa5 <filter_16ty_range+0x1a9> */
	goto x86_l_1aa5;
x86_l_1987:
	/* 0x1987: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_198a:
	/* 0x198a: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_198d:
	/* 0x198d: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_1991:
	/* 0x1991: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1994:
	/* 0x1994: setge  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_GE);
x86_l_1997:
	/* 0x1997: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_199a:
	/* 0x199a: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_199d:
	/* 0x199d: jb     1aa5 <filter_16ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1aa5;
	}
x86_l_19a3:
	/* 0x19a3: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_19a6:
	/* 0x19a6: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_19aa:
	/* 0x19aa: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_19ad:
	/* 0x19ad: setge  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_GE);
x86_l_19b1:
	/* 0x19b1: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_19b4:
	/* 0x19b4: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_19b7:
	/* 0x19b7: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_19ba:
	/* 0x19ba: jb     1aa5 <filter_16ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1aa5;
	}
x86_l_19c0:
	/* 0x19c0: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_19c3:
	/* 0x19c3: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_19c7:
	/* 0x19c7: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_19ca:
	/* 0x19ca: setge  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_GE);
x86_l_19ce:
	/* 0x19ce: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_19d1:
	/* 0x19d1: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_19d4:
	/* 0x19d4: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_19d7:
	/* 0x19d7: jb     1aa5 <filter_16ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1aa5;
	}
x86_l_19dd:
	/* 0x19dd: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_19e0:
	/* 0x19e0: setle  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_LE);
x86_l_19e3:
	/* 0x19e3: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_19e6:
	/* 0x19e6: setge  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_GE);
x86_l_19ea:
	/* 0x19ea: jmp    1a5f <filter_16ty_range+0x163> */
	goto x86_l_1a5f;
x86_l_19ec:
	/* 0x19ec: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_19ef:
	/* 0x19ef: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_19f2:
	/* 0x19f2: jne    1a04 <filter_16ty_range+0x108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1a04;
	}
x86_l_19f4:
	/* 0x19f4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_19f9:
	/* 0x19f9: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19fc:
	/* 0x19fc: ja     1a67 <filter_16ty_range+0x16b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1a67;
	}
x86_l_19fe:
	/* 0x19fe: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1a01:
	/* 0x1a01: jb     1a67 <filter_16ty_range+0x16b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1a67;
	}
x86_l_1a03:
	/* 0x1a03: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1a04:
	/* 0x1a04: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a07:
	/* 0x1a07: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a0a:
	/* 0x1a0a: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_1a0e:
	/* 0x1a0e: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1a11:
	/* 0x1a11: setae  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_AE);
x86_l_1a14:
	/* 0x1a14: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1a17:
	/* 0x1a17: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1a1a:
	/* 0x1a1a: jb     1aa5 <filter_16ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1aa5;
	}
x86_l_1a20:
	/* 0x1a20: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a23:
	/* 0x1a23: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_1a27:
	/* 0x1a27: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1a2a:
	/* 0x1a2a: setae  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_AE);
x86_l_1a2e:
	/* 0x1a2e: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1a31:
	/* 0x1a31: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_1a34:
	/* 0x1a34: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1a37:
	/* 0x1a37: jb     1aa5 <filter_16ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1aa5;
	}
x86_l_1a39:
	/* 0x1a39: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a3c:
	/* 0x1a3c: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_1a40:
	/* 0x1a40: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1a43:
	/* 0x1a43: setae  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_AE);
x86_l_1a47:
	/* 0x1a47: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1a4a:
	/* 0x1a4a: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_1a4d:
	/* 0x1a4d: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_1a50:
	/* 0x1a50: jb     1aa5 <filter_16ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1aa5;
	}
x86_l_1a52:
	/* 0x1a52: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1a55:
	/* 0x1a55: setbe  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_BE);
x86_l_1a58:
	/* 0x1a58: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1a5b:
	/* 0x1a5b: setae  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_AE);
x86_l_1a5f:
	/* 0x1a5f: and    sil,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_1a62:
	/* 0x1a62: or     dl,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_8, X86_ALU_OR);
x86_l_1a65:
	/* 0x1a65: jmp    1aa5 <filter_16ty_range+0x1a9> */
	goto x86_l_1aa5;
x86_l_1a67:
	/* 0x1a67: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a6a:
	/* 0x1a6a: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1a6d:
	/* 0x1a6d: jb     1aa3 <filter_16ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1aa3;
	}
x86_l_1a6f:
	/* 0x1a6f: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a72:
	/* 0x1a72: ja     1a79 <filter_16ty_range+0x17d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1a79;
	}
x86_l_1a74:
	/* 0x1a74: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1a77:
	/* 0x1a77: jae    1a03 <filter_16ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1a03;
	}
x86_l_1a79:
	/* 0x1a79: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_1a7c:
	/* 0x1a7c: jb     1aa3 <filter_16ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1aa3;
	}
x86_l_1a7e:
	/* 0x1a7e: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a81:
	/* 0x1a81: ja     1a8c <filter_16ty_range+0x190> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1a8c;
	}
x86_l_1a83:
	/* 0x1a83: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1a86:
	/* 0x1a86: jae    1a03 <filter_16ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1a03;
	}
x86_l_1a8c:
	/* 0x1a8c: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_1a8f:
	/* 0x1a8f: jb     1aa3 <filter_16ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1aa3;
	}
x86_l_1a91:
	/* 0x1a91: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a93:
	/* 0x1a93: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1a96:
	/* 0x1a96: ja     1aa5 <filter_16ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1aa5;
	}
x86_l_1a98:
	/* 0x1a98: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1a9b:
	/* 0x1a9b: jae    1a03 <filter_16ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1a03;
	}
x86_l_1aa1:
	/* 0x1aa1: jmp    1aa5 <filter_16ty_range+0x1a9> */
	goto x86_l_1aa5;
x86_l_1aa3:
	/* 0x1aa3: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1aa5:
	/* 0x1aa5: cmp    ecx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 32ULL);
x86_l_1aa8:
	/* 0x1aa8: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_1aab:
	/* 0x1aab: xor    dl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_1aae:
	/* 0x1aae: and    dl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_1ab0:
	/* 0x1ab0: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1ab3:
	/* 0x1ab3: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1ab4:
	/* 0x1ab4: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_1ab6:
	/* 0x1ab6: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_1ab7:
	/* 0x1ab7: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_1abb:
	/* 0x1abb: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_1abe:
	/* 0x1abe: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_1ac1:
	/* 0x1ac1: movzx  eax,BYTE PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1ac5:
	/* 0x1ac5: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1ac9:
	/* 0x1ac9: mov    rdi,QWORD PTR [rip+0xe20] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_1ad0:
	/* 0x1ad0: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1ad5:
	/* 0x1ad5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ada:
	/* 0x1ada: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1adc:
	/* 0x1adc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1adf:
	/* 0x1adf: je     1b15 <filter_16ty_map+0x61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b15;
	}
x86_l_1ae1:
	/* 0x1ae1: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1ae4:
	/* 0x1ae4: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1ae8:
	/* 0x1ae8: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1aed:
	/* 0x1aed: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1af2:
	/* 0x1af2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1af7:
	/* 0x1af7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1af9:
	/* 0x1af9: mov    edx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1afc:
	/* 0x1afc: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1afe:
	/* 0x1afe: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_1b01:
	/* 0x1b01: ja     1b2f <filter_16ty_map+0x7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1b2f;
	}
x86_l_1b03:
	/* 0x1b03: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_1b08:
	/* 0x1b08: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1b0b:
	/* 0x1b0b: jae    1b1f <filter_16ty_map+0x6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1b1f;
	}
x86_l_1b0d:
	/* 0x1b0d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b10:
	/* 0x1b10: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_1b13:
	/* 0x1b13: jmp    1b2f <filter_16ty_map+0x7b> */
	goto x86_l_1b2f;
x86_l_1b15:
	/* 0x1b15: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b17:
	/* 0x1b17: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1b1b:
	/* 0x1b1b: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1b1c:
	/* 0x1b1c: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_1b1e:
	/* 0x1b1e: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1b1f:
	/* 0x1b1f: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_1b24:
	/* 0x1b24: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1b27:
	/* 0x1b27: jae    1b2f <filter_16ty_map+0x7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1b2f;
	}
x86_l_1b29:
	/* 0x1b29: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b2c:
	/* 0x1b2c: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_1b2f:
	/* 0x1b2f: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1b32:
	/* 0x1b32: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1b36:
	/* 0x1b36: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1b37:
	/* 0x1b37: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_1b39:
	/* 0x1b39: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1b3a:
	/* 0x1b3a: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1b3d:
	/* 0x1b3d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b42:
	/* 0x1b42: cmp    rcx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 37ULL);
x86_l_1b46:
	/* 0x1b46: ja     1bb7 <filter_32ty_selector_val+0x7d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7095ULL;
	}
	return 6984ULL;
}

static __noinline __u64 tetragon_bpf_generic_retuprobe_v61_generic_retuprobe_filter_arg_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 6984ULL: goto x86_l_1b48;
	case 6994ULL: goto x86_l_1b52;
	case 6998ULL: goto x86_l_1b56;
	case 7000ULL: goto x86_l_1b58;
	case 7001ULL: goto x86_l_1b59;
	case 7006ULL: goto x86_l_1b5e;
	case 7010ULL: goto x86_l_1b62;
	case 7012ULL: goto x86_l_1b64;
	case 7014ULL: goto x86_l_1b66;
	case 7017ULL: goto x86_l_1b69;
	case 7023ULL: goto x86_l_1b6f;
	case 7025ULL: goto x86_l_1b71;
	case 7028ULL: goto x86_l_1b74;
	case 7031ULL: goto x86_l_1b77;
	case 7032ULL: goto x86_l_1b78;
	case 7036ULL: goto x86_l_1b7c;
	case 7038ULL: goto x86_l_1b7e;
	case 7040ULL: goto x86_l_1b80;
	case 7043ULL: goto x86_l_1b83;
	case 7045ULL: goto x86_l_1b85;
	case 7048ULL: goto x86_l_1b88;
	case 7051ULL: goto x86_l_1b8b;
	case 7057ULL: goto x86_l_1b91;
	case 7060ULL: goto x86_l_1b94;
	case 7062ULL: goto x86_l_1b96;
	case 7065ULL: goto x86_l_1b99;
	case 7071ULL: goto x86_l_1b9f;
	case 7074ULL: goto x86_l_1ba2;
	case 7076ULL: goto x86_l_1ba4;
	case 7079ULL: goto x86_l_1ba7;
	case 7085ULL: goto x86_l_1bad;
	case 7088ULL: goto x86_l_1bb0;
	case 7090ULL: goto x86_l_1bb2;
	case 7095ULL: goto x86_l_1bb7;
	case 7098ULL: goto x86_l_1bba;
	case 7100ULL: goto x86_l_1bbc;
	case 7103ULL: goto x86_l_1bbf;
	case 7109ULL: goto x86_l_1bc5;
	case 7112ULL: goto x86_l_1bc8;
	case 7115ULL: goto x86_l_1bcb;
	case 7121ULL: goto x86_l_1bd1;
	case 7126ULL: goto x86_l_1bd6;
	case 7129ULL: goto x86_l_1bd9;
	case 7135ULL: goto x86_l_1bdf;
	case 7137ULL: goto x86_l_1be1;
	case 7140ULL: goto x86_l_1be4;
	case 7146ULL: goto x86_l_1bea;
	case 7149ULL: goto x86_l_1bed;
	case 7152ULL: goto x86_l_1bf0;
	case 7158ULL: goto x86_l_1bf6;
	case 7161ULL: goto x86_l_1bf9;
	case 7167ULL: goto x86_l_1bff;
	case 7170ULL: goto x86_l_1c02;
	case 7176ULL: goto x86_l_1c08;
	case 7179ULL: goto x86_l_1c0b;
	case 7185ULL: goto x86_l_1c11;
	case 7188ULL: goto x86_l_1c14;
	case 7194ULL: goto x86_l_1c1a;
	case 7197ULL: goto x86_l_1c1d;
	case 7203ULL: goto x86_l_1c23;
	case 7208ULL: goto x86_l_1c28;
	case 7211ULL: goto x86_l_1c2b;
	case 7214ULL: goto x86_l_1c2e;
	case 7220ULL: goto x86_l_1c34;
	case 7225ULL: goto x86_l_1c39;
	case 7228ULL: goto x86_l_1c3c;
	case 7234ULL: goto x86_l_1c42;
	case 7236ULL: goto x86_l_1c44;
	case 7239ULL: goto x86_l_1c47;
	case 7245ULL: goto x86_l_1c4d;
	case 7248ULL: goto x86_l_1c50;
	case 7251ULL: goto x86_l_1c53;
	case 7257ULL: goto x86_l_1c59;
	case 7260ULL: goto x86_l_1c5c;
	case 7266ULL: goto x86_l_1c62;
	case 7269ULL: goto x86_l_1c65;
	case 7275ULL: goto x86_l_1c6b;
	case 7278ULL: goto x86_l_1c6e;
	case 7284ULL: goto x86_l_1c74;
	case 7287ULL: goto x86_l_1c77;
	case 7293ULL: goto x86_l_1c7d;
	case 7296ULL: goto x86_l_1c80;
	case 7302ULL: goto x86_l_1c86;
	case 7307ULL: goto x86_l_1c8b;
	case 7310ULL: goto x86_l_1c8e;
	case 7313ULL: goto x86_l_1c91;
	case 7315ULL: goto x86_l_1c93;
	case 7318ULL: goto x86_l_1c96;
	case 7324ULL: goto x86_l_1c9c;
	case 7327ULL: goto x86_l_1c9f;
	case 7329ULL: goto x86_l_1ca1;
	case 7332ULL: goto x86_l_1ca4;
	case 7338ULL: goto x86_l_1caa;
	case 7341ULL: goto x86_l_1cad;
	case 7343ULL: goto x86_l_1caf;
	case 7346ULL: goto x86_l_1cb2;
	case 7352ULL: goto x86_l_1cb8;
	case 7355ULL: goto x86_l_1cbb;
	case 7361ULL: goto x86_l_1cc1;
	case 7363ULL: goto x86_l_1cc3;
	case 7373ULL: goto x86_l_1ccd;
	case 7377ULL: goto x86_l_1cd1;
	case 7383ULL: goto x86_l_1cd7;
	case 7385ULL: goto x86_l_1cd9;
	case 7387ULL: goto x86_l_1cdb;
	case 7390ULL: goto x86_l_1cde;
	case 7396ULL: goto x86_l_1ce4;
	case 7399ULL: goto x86_l_1ce7;
	case 7402ULL: goto x86_l_1cea;
	case 7404ULL: goto x86_l_1cec;
	case 7407ULL: goto x86_l_1cef;
	case 7413ULL: goto x86_l_1cf5;
	case 7416ULL: goto x86_l_1cf8;
	case 7418ULL: goto x86_l_1cfa;
	case 7421ULL: goto x86_l_1cfd;
	case 7427ULL: goto x86_l_1d03;
	case 7430ULL: goto x86_l_1d06;
	case 7432ULL: goto x86_l_1d08;
	case 7435ULL: goto x86_l_1d0b;
	case 7441ULL: goto x86_l_1d11;
	case 7443ULL: goto x86_l_1d13;
	case 7445ULL: goto x86_l_1d15;
	case 7448ULL: goto x86_l_1d18;
	case 7454ULL: goto x86_l_1d1e;
	case 7457ULL: goto x86_l_1d21;
	case 7460ULL: goto x86_l_1d24;
	case 7462ULL: goto x86_l_1d26;
	case 7465ULL: goto x86_l_1d29;
	case 7471ULL: goto x86_l_1d2f;
	case 7474ULL: goto x86_l_1d32;
	case 7476ULL: goto x86_l_1d34;
	case 7479ULL: goto x86_l_1d37;
	case 7485ULL: goto x86_l_1d3d;
	case 7488ULL: goto x86_l_1d40;
	case 7490ULL: goto x86_l_1d42;
	case 7493ULL: goto x86_l_1d45;
	case 7499ULL: goto x86_l_1d4b;
	case 7501ULL: goto x86_l_1d4d;
	case 7502ULL: goto x86_l_1d4e;
	case 7505ULL: goto x86_l_1d51;
	case 7508ULL: goto x86_l_1d54;
	case 7511ULL: goto x86_l_1d57;
	case 7517ULL: goto x86_l_1d5d;
	case 7522ULL: goto x86_l_1d62;
	case 7525ULL: goto x86_l_1d65;
	case 7531ULL: goto x86_l_1d6b;
	case 7533ULL: goto x86_l_1d6d;
	case 7536ULL: goto x86_l_1d70;
	case 7538ULL: goto x86_l_1d72;
	case 7543ULL: goto x86_l_1d77;
	case 7546ULL: goto x86_l_1d7a;
	case 7548ULL: goto x86_l_1d7c;
	case 7551ULL: goto x86_l_1d7f;
	case 7557ULL: goto x86_l_1d85;
	case 7560ULL: goto x86_l_1d88;
	case 7563ULL: goto x86_l_1d8b;
	case 7569ULL: goto x86_l_1d91;
	case 7572ULL: goto x86_l_1d94;
	case 7574ULL: goto x86_l_1d96;
	case 7577ULL: goto x86_l_1d99;
	case 7583ULL: goto x86_l_1d9f;
	case 7586ULL: goto x86_l_1da2;
	case 7592ULL: goto x86_l_1da8;
	case 7595ULL: goto x86_l_1dab;
	case 7597ULL: goto x86_l_1dad;
	case 7600ULL: goto x86_l_1db0;
	case 7606ULL: goto x86_l_1db6;
	case 7609ULL: goto x86_l_1db9;
	case 7615ULL: goto x86_l_1dbf;
	case 7617ULL: goto x86_l_1dc1;
	case 7620ULL: goto x86_l_1dc4;
	case 7626ULL: goto x86_l_1dca;
	case 7629ULL: goto x86_l_1dcd;
	case 7635ULL: goto x86_l_1dd3;
	case 7640ULL: goto x86_l_1dd8;
	case 7643ULL: goto x86_l_1ddb;
	case 7646ULL: goto x86_l_1dde;
	case 7650ULL: goto x86_l_1de2;
	case 7653ULL: goto x86_l_1de5;
	case 7656ULL: goto x86_l_1de8;
	case 7659ULL: goto x86_l_1deb;
	case 7662ULL: goto x86_l_1dee;
	case 7668ULL: goto x86_l_1df4;
	case 7671ULL: goto x86_l_1df7;
	case 7675ULL: goto x86_l_1dfb;
	case 7678ULL: goto x86_l_1dfe;
	case 7682ULL: goto x86_l_1e02;
	case 7685ULL: goto x86_l_1e05;
	case 7688ULL: goto x86_l_1e08;
	case 7691ULL: goto x86_l_1e0b;
	case 7697ULL: goto x86_l_1e11;
	case 7700ULL: goto x86_l_1e14;
	case 7704ULL: goto x86_l_1e18;
	case 7707ULL: goto x86_l_1e1b;
	case 7711ULL: goto x86_l_1e1f;
	case 7714ULL: goto x86_l_1e22;
	case 7717ULL: goto x86_l_1e25;
	case 7720ULL: goto x86_l_1e28;
	case 7726ULL: goto x86_l_1e2e;
	case 7729ULL: goto x86_l_1e31;
	case 7732ULL: goto x86_l_1e34;
	case 7735ULL: goto x86_l_1e37;
	case 7739ULL: goto x86_l_1e3b;
	case 7741ULL: goto x86_l_1e3d;
	case 7743ULL: goto x86_l_1e3f;
	case 7746ULL: goto x86_l_1e42;
	case 7748ULL: goto x86_l_1e44;
	case 7753ULL: goto x86_l_1e49;
	case 7756ULL: goto x86_l_1e4c;
	case 7758ULL: goto x86_l_1e4e;
	case 7761ULL: goto x86_l_1e51;
	case 7763ULL: goto x86_l_1e53;
	case 7764ULL: goto x86_l_1e54;
	case 7767ULL: goto x86_l_1e57;
	case 7770ULL: goto x86_l_1e5a;
	case 7774ULL: goto x86_l_1e5e;
	case 7777ULL: goto x86_l_1e61;
	case 7780ULL: goto x86_l_1e64;
	case 7783ULL: goto x86_l_1e67;
	case 7786ULL: goto x86_l_1e6a;
	case 7792ULL: goto x86_l_1e70;
	case 7795ULL: goto x86_l_1e73;
	case 7799ULL: goto x86_l_1e77;
	case 7802ULL: goto x86_l_1e7a;
	case 7806ULL: goto x86_l_1e7e;
	case 7809ULL: goto x86_l_1e81;
	case 7812ULL: goto x86_l_1e84;
	case 7815ULL: goto x86_l_1e87;
	case 7817ULL: goto x86_l_1e89;
	case 7820ULL: goto x86_l_1e8c;
	case 7824ULL: goto x86_l_1e90;
	case 7827ULL: goto x86_l_1e93;
	case 7831ULL: goto x86_l_1e97;
	case 7834ULL: goto x86_l_1e9a;
	case 7837ULL: goto x86_l_1e9d;
	case 7840ULL: goto x86_l_1ea0;
	case 7842ULL: goto x86_l_1ea2;
	case 7845ULL: goto x86_l_1ea5;
	case 7848ULL: goto x86_l_1ea8;
	case 7851ULL: goto x86_l_1eab;
	case 7855ULL: goto x86_l_1eaf;
	case 7858ULL: goto x86_l_1eb2;
	case 7861ULL: goto x86_l_1eb5;
	case 7863ULL: goto x86_l_1eb7;
	case 7866ULL: goto x86_l_1eba;
	case 7869ULL: goto x86_l_1ebd;
	case 7871ULL: goto x86_l_1ebf;
	case 7874ULL: goto x86_l_1ec2;
	case 7876ULL: goto x86_l_1ec4;
	case 7879ULL: goto x86_l_1ec7;
	case 7881ULL: goto x86_l_1ec9;
	case 7884ULL: goto x86_l_1ecc;
	case 7886ULL: goto x86_l_1ece;
	case 7889ULL: goto x86_l_1ed1;
	case 7891ULL: goto x86_l_1ed3;
	case 7894ULL: goto x86_l_1ed6;
	case 7900ULL: goto x86_l_1edc;
	case 7903ULL: goto x86_l_1edf;
	case 7905ULL: goto x86_l_1ee1;
	case 7907ULL: goto x86_l_1ee3;
	case 7910ULL: goto x86_l_1ee6;
	case 7912ULL: goto x86_l_1ee8;
	case 7915ULL: goto x86_l_1eeb;
	case 7921ULL: goto x86_l_1ef1;
	case 7923ULL: goto x86_l_1ef3;
	case 7925ULL: goto x86_l_1ef5;
	case 7928ULL: goto x86_l_1ef8;
	case 7931ULL: goto x86_l_1efb;
	case 7934ULL: goto x86_l_1efe;
	case 7936ULL: goto x86_l_1f00;
	case 7939ULL: goto x86_l_1f03;
	case 7940ULL: goto x86_l_1f04;
	case 7942ULL: goto x86_l_1f06;
	case 7943ULL: goto x86_l_1f07;
	case 7947ULL: goto x86_l_1f0b;
	case 7950ULL: goto x86_l_1f0e;
	case 7953ULL: goto x86_l_1f11;
	case 7957ULL: goto x86_l_1f15;
	case 7961ULL: goto x86_l_1f19;
	case 7968ULL: goto x86_l_1f20;
	case 7973ULL: goto x86_l_1f25;
	case 7978ULL: goto x86_l_1f2a;
	case 7980ULL: goto x86_l_1f2c;
	case 7983ULL: goto x86_l_1f2f;
	case 7985ULL: goto x86_l_1f31;
	case 7988ULL: goto x86_l_1f34;
	case 7991ULL: goto x86_l_1f37;
	case 7996ULL: goto x86_l_1f3c;
	case 8001ULL: goto x86_l_1f41;
	case 8006ULL: goto x86_l_1f46;
	case 8008ULL: goto x86_l_1f48;
	case 8011ULL: goto x86_l_1f4b;
	case 8013ULL: goto x86_l_1f4d;
	case 8016ULL: goto x86_l_1f50;
	case 8018ULL: goto x86_l_1f52;
	case 8023ULL: goto x86_l_1f57;
	case 8026ULL: goto x86_l_1f5a;
	case 8028ULL: goto x86_l_1f5c;
	case 8031ULL: goto x86_l_1f5f;
	case 8034ULL: goto x86_l_1f62;
	case 8036ULL: goto x86_l_1f64;
	case 8038ULL: goto x86_l_1f66;
	case 8042ULL: goto x86_l_1f6a;
	case 8043ULL: goto x86_l_1f6b;
	case 8045ULL: goto x86_l_1f6d;
	case 8046ULL: goto x86_l_1f6e;
	case 8051ULL: goto x86_l_1f73;
	case 8054ULL: goto x86_l_1f76;
	case 8056ULL: goto x86_l_1f78;
	case 8059ULL: goto x86_l_1f7b;
	case 8062ULL: goto x86_l_1f7e;
	case 8065ULL: goto x86_l_1f81;
	case 8069ULL: goto x86_l_1f85;
	case 8070ULL: goto x86_l_1f86;
	case 8072ULL: goto x86_l_1f88;
	case 8073ULL: goto x86_l_1f89;
	case 8076ULL: goto x86_l_1f8c;
	case 8081ULL: goto x86_l_1f91;
	case 8085ULL: goto x86_l_1f95;
	case 8087ULL: goto x86_l_1f97;
	case 8097ULL: goto x86_l_1fa1;
	case 8101ULL: goto x86_l_1fa5;
	case 8103ULL: goto x86_l_1fa7;
	case 8104ULL: goto x86_l_1fa8;
	case 8109ULL: goto x86_l_1fad;
	case 8113ULL: goto x86_l_1fb1;
	case 8115ULL: goto x86_l_1fb3;
	case 8118ULL: goto x86_l_1fb6;
	case 8121ULL: goto x86_l_1fb9;
	case 8127ULL: goto x86_l_1fbf;
	case 8129ULL: goto x86_l_1fc1;
	case 8132ULL: goto x86_l_1fc4;
	case 8135ULL: goto x86_l_1fc7;
	case 8136ULL: goto x86_l_1fc8;
	case 8140ULL: goto x86_l_1fcc;
	case 8142ULL: goto x86_l_1fce;
	case 8145ULL: goto x86_l_1fd1;
	case 8148ULL: goto x86_l_1fd4;
	case 8150ULL: goto x86_l_1fd6;
	case 8153ULL: goto x86_l_1fd9;
	case 8156ULL: goto x86_l_1fdc;
	case 8162ULL: goto x86_l_1fe2;
	case 8165ULL: goto x86_l_1fe5;
	case 8167ULL: goto x86_l_1fe7;
	case 8170ULL: goto x86_l_1fea;
	case 8176ULL: goto x86_l_1ff0;
	case 8179ULL: goto x86_l_1ff3;
	case 8181ULL: goto x86_l_1ff5;
	case 8184ULL: goto x86_l_1ff8;
	case 8190ULL: goto x86_l_1ffe;
	case 8193ULL: goto x86_l_2001;
	case 8195ULL: goto x86_l_2003;
	case 8200ULL: goto x86_l_2008;
	case 8203ULL: goto x86_l_200b;
	case 8205ULL: goto x86_l_200d;
	case 8208ULL: goto x86_l_2010;
	case 8214ULL: goto x86_l_2016;
	case 8217ULL: goto x86_l_2019;
	case 8220ULL: goto x86_l_201c;
	case 8226ULL: goto x86_l_2022;
	case 8231ULL: goto x86_l_2027;
	case 8234ULL: goto x86_l_202a;
	case 8240ULL: goto x86_l_2030;
	case 8243ULL: goto x86_l_2033;
	case 8246ULL: goto x86_l_2036;
	case 8252ULL: goto x86_l_203c;
	case 8255ULL: goto x86_l_203f;
	case 8258ULL: goto x86_l_2042;
	case 8264ULL: goto x86_l_2048;
	case 8267ULL: goto x86_l_204b;
	case 8273ULL: goto x86_l_2051;
	case 8276ULL: goto x86_l_2054;
	case 8282ULL: goto x86_l_205a;
	case 8285ULL: goto x86_l_205d;
	case 8291ULL: goto x86_l_2063;
	case 8294ULL: goto x86_l_2066;
	case 8300ULL: goto x86_l_206c;
	case 8303ULL: goto x86_l_206f;
	case 8309ULL: goto x86_l_2075;
	case 8314ULL: goto x86_l_207a;
	case 8317ULL: goto x86_l_207d;
	case 8320ULL: goto x86_l_2080;
	case 8326ULL: goto x86_l_2086;
	case 8331ULL: goto x86_l_208b;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1b48:
	/* 0x1b48: movabs rdx,0x200c000040 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280128ULL);
x86_l_1b52:
	/* 0x1b52: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1b56:
	/* 0x1b56: jae    1b59 <filter_32ty_selector_val+0x1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1b59;
	}
x86_l_1b58:
	/* 0x1b58: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1b59:
	/* 0x1b59: mov    edx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 24ULL);
x86_l_1b5e:
	/* 0x1b5e: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1b62:
	/* 0x1b62: jae    1b78 <filter_32ty_selector_val+0x3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1b78;
	}
x86_l_1b64:
	/* 0x1b64: mov    edx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b66:
	/* 0x1b66: cmp    edx,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_1b69:
	/* 0x1b69: jne    1c8b <filter_32ty_selector_val+0x151> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1c8b;
	}
x86_l_1b6f:
	/* 0x1b6f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b71:
	/* 0x1b71: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1b74:
	/* 0x1b74: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_1b77:
	/* 0x1b77: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1b78:
	/* 0x1b78: cmp    rcx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 12ULL);
x86_l_1b7c:
	/* 0x1b7c: jne    1bb7 <filter_32ty_selector_val+0x7d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1bb7;
	}
x86_l_1b7e:
	/* 0x1b7e: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b80:
	/* 0x1b80: test   DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b83:
	/* 0x1b83: jne    1b58 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1b58;
	}
x86_l_1b85:
	/* 0x1b85: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b88:
	/* 0x1b88: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1b8b:
	/* 0x1b8b: jb     1d4b <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d4b;
	}
x86_l_1b91:
	/* 0x1b91: test   DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1b94:
	/* 0x1b94: jne    1b58 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1b58;
	}
x86_l_1b96:
	/* 0x1b96: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1b99:
	/* 0x1b99: jb     1d4b <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d4b;
	}
x86_l_1b9f:
	/* 0x1b9f: test   DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ba2:
	/* 0x1ba2: jne    1b58 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1b58;
	}
x86_l_1ba4:
	/* 0x1ba4: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_1ba7:
	/* 0x1ba7: jb     1d4b <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d4b;
	}
x86_l_1bad:
	/* 0x1bad: test   DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1bb0:
	/* 0x1bb0: jne    1b58 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1b58;
	}
x86_l_1bb2:
	/* 0x1bb2: jmp    1d4b <filter_32ty_selector_val+0x211> */
	goto x86_l_1d4b;
x86_l_1bb7:
	/* 0x1bb7: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1bba:
	/* 0x1bba: je     1c28 <filter_32ty_selector_val+0xee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c28;
	}
x86_l_1bbc:
	/* 0x1bbc: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1bbf:
	/* 0x1bbf: jne    1d4b <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d4b;
	}
x86_l_1bc5:
	/* 0x1bc5: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1bc8:
	/* 0x1bc8: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1bcb:
	/* 0x1bcb: ja     1d13 <filter_32ty_selector_val+0x1d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1d13;
	}
x86_l_1bd1:
	/* 0x1bd1: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_1bd6:
	/* 0x1bd6: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_1bd9:
	/* 0x1bd9: jae    1d13 <filter_32ty_selector_val+0x1d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1d13;
	}
x86_l_1bdf:
	/* 0x1bdf: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1be1:
	/* 0x1be1: cmp    ecx,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_1be4:
	/* 0x1be4: jl     1b58 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_1b58;
	}
x86_l_1bea:
	/* 0x1bea: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bed:
	/* 0x1bed: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1bf0:
	/* 0x1bf0: jb     1d4b <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d4b;
	}
x86_l_1bf6:
	/* 0x1bf6: cmp    ecx,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1bf9:
	/* 0x1bf9: jl     1b58 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_1b58;
	}
x86_l_1bff:
	/* 0x1bff: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1c02:
	/* 0x1c02: jb     1d4b <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d4b;
	}
x86_l_1c08:
	/* 0x1c08: cmp    ecx,DWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 24ULL);
x86_l_1c0b:
	/* 0x1c0b: jl     1b58 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_1b58;
	}
x86_l_1c11:
	/* 0x1c11: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_1c14:
	/* 0x1c14: jb     1d4b <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d4b;
	}
x86_l_1c1a:
	/* 0x1c1a: cmp    ecx,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1c1d:
	/* 0x1c1d: jl     1b58 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_1b58;
	}
x86_l_1c23:
	/* 0x1c23: jmp    1d4b <filter_32ty_selector_val+0x211> */
	goto x86_l_1d4b;
x86_l_1c28:
	/* 0x1c28: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1c2b:
	/* 0x1c2b: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1c2e:
	/* 0x1c2e: ja     1cd9 <filter_32ty_selector_val+0x19f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1cd9;
	}
x86_l_1c34:
	/* 0x1c34: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_1c39:
	/* 0x1c39: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_1c3c:
	/* 0x1c3c: jae    1cd9 <filter_32ty_selector_val+0x19f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1cd9;
	}
x86_l_1c42:
	/* 0x1c42: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c44:
	/* 0x1c44: cmp    ecx,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_1c47:
	/* 0x1c47: jg     1b58 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1b58;
	}
x86_l_1c4d:
	/* 0x1c4d: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c50:
	/* 0x1c50: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1c53:
	/* 0x1c53: jb     1d4b <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d4b;
	}
x86_l_1c59:
	/* 0x1c59: cmp    ecx,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1c5c:
	/* 0x1c5c: jg     1b58 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1b58;
	}
x86_l_1c62:
	/* 0x1c62: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1c65:
	/* 0x1c65: jb     1d4b <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d4b;
	}
x86_l_1c6b:
	/* 0x1c6b: cmp    ecx,DWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 24ULL);
x86_l_1c6e:
	/* 0x1c6e: jg     1b58 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1b58;
	}
x86_l_1c74:
	/* 0x1c74: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_1c77:
	/* 0x1c77: jb     1d4b <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d4b;
	}
x86_l_1c7d:
	/* 0x1c7d: cmp    ecx,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1c80:
	/* 0x1c80: jg     1b58 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1b58;
	}
x86_l_1c86:
	/* 0x1c86: jmp    1d4b <filter_32ty_selector_val+0x211> */
	goto x86_l_1d4b;
x86_l_1c8b:
	/* 0x1c8b: mov    esi,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c8e:
	/* 0x1c8e: cmp    esi,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 13ULL);
x86_l_1c91:
	/* 0x1c91: jb     1cb8 <filter_32ty_selector_val+0x17e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1cb8;
	}
x86_l_1c93:
	/* 0x1c93: cmp    edx,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1c96:
	/* 0x1c96: je     1b6f <filter_32ty_selector_val+0x35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b6f;
	}
x86_l_1c9c:
	/* 0x1c9c: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_1c9f:
	/* 0x1c9f: jb     1cb8 <filter_32ty_selector_val+0x17e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1cb8;
	}
x86_l_1ca1:
	/* 0x1ca1: cmp    edx,DWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 24ULL);
x86_l_1ca4:
	/* 0x1ca4: je     1b6f <filter_32ty_selector_val+0x35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b6f;
	}
x86_l_1caa:
	/* 0x1caa: cmp    esi,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 21ULL);
x86_l_1cad:
	/* 0x1cad: jb     1cb8 <filter_32ty_selector_val+0x17e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1cb8;
	}
x86_l_1caf:
	/* 0x1caf: cmp    edx,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1cb2:
	/* 0x1cb2: je     1b6f <filter_32ty_selector_val+0x35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b6f;
	}
x86_l_1cb8:
	/* 0x1cb8: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_1cbb:
	/* 0x1cbb: ja     1d4b <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1d4b;
	}
x86_l_1cc1:
	/* 0x1cc1: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1cc3:
	/* 0x1cc3: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_1ccd:
	/* 0x1ccd: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1cd1:
	/* 0x1cd1: jb     1b58 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1b58;
	}
x86_l_1cd7:
	/* 0x1cd7: jmp    1d4b <filter_32ty_selector_val+0x211> */
	goto x86_l_1d4b;
x86_l_1cd9:
	/* 0x1cd9: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cdb:
	/* 0x1cdb: cmp    ecx,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_1cde:
	/* 0x1cde: ja     1b58 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1b58;
	}
x86_l_1ce4:
	/* 0x1ce4: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ce7:
	/* 0x1ce7: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1cea:
	/* 0x1cea: jb     1d4b <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d4b;
	}
x86_l_1cec:
	/* 0x1cec: cmp    ecx,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1cef:
	/* 0x1cef: ja     1b58 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1b58;
	}
x86_l_1cf5:
	/* 0x1cf5: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1cf8:
	/* 0x1cf8: jb     1d4b <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d4b;
	}
x86_l_1cfa:
	/* 0x1cfa: cmp    ecx,DWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 24ULL);
x86_l_1cfd:
	/* 0x1cfd: ja     1b58 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1b58;
	}
x86_l_1d03:
	/* 0x1d03: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_1d06:
	/* 0x1d06: jb     1d4b <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d4b;
	}
x86_l_1d08:
	/* 0x1d08: cmp    ecx,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1d0b:
	/* 0x1d0b: ja     1b58 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1b58;
	}
x86_l_1d11:
	/* 0x1d11: jmp    1d4b <filter_32ty_selector_val+0x211> */
	goto x86_l_1d4b;
x86_l_1d13:
	/* 0x1d13: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d15:
	/* 0x1d15: cmp    ecx,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_1d18:
	/* 0x1d18: jb     1b58 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1b58;
	}
x86_l_1d1e:
	/* 0x1d1e: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d21:
	/* 0x1d21: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1d24:
	/* 0x1d24: jb     1d4b <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d4b;
	}
x86_l_1d26:
	/* 0x1d26: cmp    ecx,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1d29:
	/* 0x1d29: jb     1b58 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1b58;
	}
x86_l_1d2f:
	/* 0x1d2f: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1d32:
	/* 0x1d32: jb     1d4b <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d4b;
	}
x86_l_1d34:
	/* 0x1d34: cmp    ecx,DWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 24ULL);
x86_l_1d37:
	/* 0x1d37: jb     1b58 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1b58;
	}
x86_l_1d3d:
	/* 0x1d3d: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_1d40:
	/* 0x1d40: jb     1d4b <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d4b;
	}
x86_l_1d42:
	/* 0x1d42: cmp    ecx,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1d45:
	/* 0x1d45: jb     1b58 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1b58;
	}
x86_l_1d4b:
	/* 0x1d4b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d4d:
	/* 0x1d4d: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1d4e:
	/* 0x1d4e: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d51:
	/* 0x1d51: mov    eax,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1d54:
	/* 0x1d54: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1d57:
	/* 0x1d57: ja     1e3d <filter_32ty_range+0xef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1e3d;
	}
x86_l_1d5d:
	/* 0x1d5d: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_1d62:
	/* 0x1d62: bt     edx,eax */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_1d65:
	/* 0x1d65: jae    1e3d <filter_32ty_range+0xef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1e3d;
	}
x86_l_1d6b:
	/* 0x1d6b: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d6d:
	/* 0x1d6d: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_1d70:
	/* 0x1d70: jne    1dd8 <filter_32ty_range+0x8a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1dd8;
	}
x86_l_1d72:
	/* 0x1d72: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d77:
	/* 0x1d77: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d7a:
	/* 0x1d7a: jg     1d85 <filter_32ty_range+0x37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1d85;
	}
x86_l_1d7c:
	/* 0x1d7c: cmp    esi,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1d7f:
	/* 0x1d7f: jle    1e53 <filter_32ty_range+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1e53;
	}
x86_l_1d85:
	/* 0x1d85: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d88:
	/* 0x1d88: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1d8b:
	/* 0x1d8b: jb     1ef3 <filter_32ty_range+0x1a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1ef3;
	}
x86_l_1d91:
	/* 0x1d91: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d94:
	/* 0x1d94: jg     1d9f <filter_32ty_range+0x51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1d9f;
	}
x86_l_1d96:
	/* 0x1d96: cmp    esi,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1d99:
	/* 0x1d99: jle    1e53 <filter_32ty_range+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1e53;
	}
x86_l_1d9f:
	/* 0x1d9f: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_1da2:
	/* 0x1da2: jb     1ef3 <filter_32ty_range+0x1a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1ef3;
	}
x86_l_1da8:
	/* 0x1da8: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1dab:
	/* 0x1dab: jg     1db6 <filter_32ty_range+0x68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1db6;
	}
x86_l_1dad:
	/* 0x1dad: cmp    esi,DWORD PTR [rdi+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_1db0:
	/* 0x1db0: jle    1e53 <filter_32ty_range+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1e53;
	}
x86_l_1db6:
	/* 0x1db6: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_1db9:
	/* 0x1db9: jb     1ef3 <filter_32ty_range+0x1a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1ef3;
	}
x86_l_1dbf:
	/* 0x1dbf: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1dc1:
	/* 0x1dc1: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1dc4:
	/* 0x1dc4: jg     1ef5 <filter_32ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1ef5;
	}
x86_l_1dca:
	/* 0x1dca: cmp    esi,DWORD PTR [rdi+0x2c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 44ULL);
x86_l_1dcd:
	/* 0x1dcd: jle    1e53 <filter_32ty_range+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1e53;
	}
x86_l_1dd3:
	/* 0x1dd3: jmp    1ef5 <filter_32ty_range+0x1a7> */
	goto x86_l_1ef5;
x86_l_1dd8:
	/* 0x1dd8: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ddb:
	/* 0x1ddb: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1dde:
	/* 0x1dde: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_1de2:
	/* 0x1de2: cmp    esi,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1de5:
	/* 0x1de5: setle  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_LE);
x86_l_1de8:
	/* 0x1de8: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1deb:
	/* 0x1deb: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1dee:
	/* 0x1dee: jb     1ef5 <filter_32ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1ef5;
	}
x86_l_1df4:
	/* 0x1df4: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1df7:
	/* 0x1df7: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_1dfb:
	/* 0x1dfb: cmp    esi,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1dfe:
	/* 0x1dfe: setle  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_LE);
x86_l_1e02:
	/* 0x1e02: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1e05:
	/* 0x1e05: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_1e08:
	/* 0x1e08: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1e0b:
	/* 0x1e0b: jb     1ef5 <filter_32ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1ef5;
	}
x86_l_1e11:
	/* 0x1e11: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e14:
	/* 0x1e14: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_1e18:
	/* 0x1e18: cmp    esi,DWORD PTR [rdi+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_1e1b:
	/* 0x1e1b: setle  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_LE);
x86_l_1e1f:
	/* 0x1e1f: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1e22:
	/* 0x1e22: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_1e25:
	/* 0x1e25: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_1e28:
	/* 0x1e28: jb     1ef5 <filter_32ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1ef5;
	}
x86_l_1e2e:
	/* 0x1e2e: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1e31:
	/* 0x1e31: setle  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_LE);
x86_l_1e34:
	/* 0x1e34: cmp    esi,DWORD PTR [rdi+0x2c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 44ULL);
x86_l_1e37:
	/* 0x1e37: setle  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_LE);
x86_l_1e3b:
	/* 0x1e3b: jmp    1eaf <filter_32ty_range+0x161> */
	goto x86_l_1eaf;
x86_l_1e3d:
	/* 0x1e3d: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e3f:
	/* 0x1e3f: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_1e42:
	/* 0x1e42: jne    1e54 <filter_32ty_range+0x106> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e54;
	}
x86_l_1e44:
	/* 0x1e44: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1e49:
	/* 0x1e49: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e4c:
	/* 0x1e4c: ja     1eb7 <filter_32ty_range+0x169> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1eb7;
	}
x86_l_1e4e:
	/* 0x1e4e: cmp    esi,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1e51:
	/* 0x1e51: ja     1eb7 <filter_32ty_range+0x169> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1eb7;
	}
x86_l_1e53:
	/* 0x1e53: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1e54:
	/* 0x1e54: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e57:
	/* 0x1e57: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e5a:
	/* 0x1e5a: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_1e5e:
	/* 0x1e5e: cmp    esi,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1e61:
	/* 0x1e61: setbe  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_BE);
x86_l_1e64:
	/* 0x1e64: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1e67:
	/* 0x1e67: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1e6a:
	/* 0x1e6a: jb     1ef5 <filter_32ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1ef5;
	}
x86_l_1e70:
	/* 0x1e70: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1e73:
	/* 0x1e73: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_1e77:
	/* 0x1e77: cmp    esi,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1e7a:
	/* 0x1e7a: setbe  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_BE);
x86_l_1e7e:
	/* 0x1e7e: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1e81:
	/* 0x1e81: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_1e84:
	/* 0x1e84: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1e87:
	/* 0x1e87: jb     1ef5 <filter_32ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1ef5;
	}
x86_l_1e89:
	/* 0x1e89: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e8c:
	/* 0x1e8c: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_1e90:
	/* 0x1e90: cmp    esi,DWORD PTR [rdi+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_1e93:
	/* 0x1e93: setbe  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_BE);
x86_l_1e97:
	/* 0x1e97: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1e9a:
	/* 0x1e9a: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_1e9d:
	/* 0x1e9d: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_1ea0:
	/* 0x1ea0: jb     1ef5 <filter_32ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1ef5;
	}
x86_l_1ea2:
	/* 0x1ea2: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1ea5:
	/* 0x1ea5: setbe  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_BE);
x86_l_1ea8:
	/* 0x1ea8: cmp    esi,DWORD PTR [rdi+0x2c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 44ULL);
x86_l_1eab:
	/* 0x1eab: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_1eaf:
	/* 0x1eaf: and    sil,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_1eb2:
	/* 0x1eb2: or     dl,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_8, X86_ALU_OR);
x86_l_1eb5:
	/* 0x1eb5: jmp    1ef5 <filter_32ty_range+0x1a7> */
	goto x86_l_1ef5;
x86_l_1eb7:
	/* 0x1eb7: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1eba:
	/* 0x1eba: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1ebd:
	/* 0x1ebd: jb     1ef3 <filter_32ty_range+0x1a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1ef3;
	}
x86_l_1ebf:
	/* 0x1ebf: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ec2:
	/* 0x1ec2: ja     1ec9 <filter_32ty_range+0x17b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ec9;
	}
x86_l_1ec4:
	/* 0x1ec4: cmp    esi,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1ec7:
	/* 0x1ec7: jbe    1e53 <filter_32ty_range+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1e53;
	}
x86_l_1ec9:
	/* 0x1ec9: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_1ecc:
	/* 0x1ecc: jb     1ef3 <filter_32ty_range+0x1a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1ef3;
	}
x86_l_1ece:
	/* 0x1ece: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ed1:
	/* 0x1ed1: ja     1edc <filter_32ty_range+0x18e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1edc;
	}
x86_l_1ed3:
	/* 0x1ed3: cmp    esi,DWORD PTR [rdi+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_1ed6:
	/* 0x1ed6: jbe    1e53 <filter_32ty_range+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1e53;
	}
x86_l_1edc:
	/* 0x1edc: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_1edf:
	/* 0x1edf: jb     1ef3 <filter_32ty_range+0x1a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1ef3;
	}
x86_l_1ee1:
	/* 0x1ee1: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ee3:
	/* 0x1ee3: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1ee6:
	/* 0x1ee6: ja     1ef5 <filter_32ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ef5;
	}
x86_l_1ee8:
	/* 0x1ee8: cmp    esi,DWORD PTR [rdi+0x2c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 44ULL);
x86_l_1eeb:
	/* 0x1eeb: jbe    1e53 <filter_32ty_range+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1e53;
	}
x86_l_1ef1:
	/* 0x1ef1: jmp    1ef5 <filter_32ty_range+0x1a7> */
	goto x86_l_1ef5;
x86_l_1ef3:
	/* 0x1ef3: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ef5:
	/* 0x1ef5: cmp    ecx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 32ULL);
x86_l_1ef8:
	/* 0x1ef8: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_1efb:
	/* 0x1efb: xor    dl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_1efe:
	/* 0x1efe: and    dl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_1f00:
	/* 0x1f00: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1f03:
	/* 0x1f03: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1f04:
	/* 0x1f04: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_1f06:
	/* 0x1f06: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_1f07:
	/* 0x1f07: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_1f0b:
	/* 0x1f0b: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_1f0e:
	/* 0x1f0e: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_1f11:
	/* 0x1f11: movzx  eax,BYTE PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1f15:
	/* 0x1f15: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1f19:
	/* 0x1f19: mov    rdi,QWORD PTR [rip+0x9b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_1f20:
	/* 0x1f20: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1f25:
	/* 0x1f25: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f2a:
	/* 0x1f2a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f2c:
	/* 0x1f2c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f2f:
	/* 0x1f2f: je     1f64 <filter_32ty_map+0x60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f64;
	}
x86_l_1f31:
	/* 0x1f31: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1f34:
	/* 0x1f34: mov    eax,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f37:
	/* 0x1f37: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f3c:
	/* 0x1f3c: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f41:
	/* 0x1f41: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f46:
	/* 0x1f46: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f48:
	/* 0x1f48: mov    edx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1f4b:
	/* 0x1f4b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f4d:
	/* 0x1f4d: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_1f50:
	/* 0x1f50: ja     1f7e <filter_32ty_map+0x7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1f7e;
	}
x86_l_1f52:
	/* 0x1f52: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_1f57:
	/* 0x1f57: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1f5a:
	/* 0x1f5a: jae    1f6e <filter_32ty_map+0x6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1f6e;
	}
x86_l_1f5c:
	/* 0x1f5c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f5f:
	/* 0x1f5f: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_1f62:
	/* 0x1f62: jmp    1f7e <filter_32ty_map+0x7a> */
	goto x86_l_1f7e;
x86_l_1f64:
	/* 0x1f64: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f66:
	/* 0x1f66: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1f6a:
	/* 0x1f6a: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1f6b:
	/* 0x1f6b: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_1f6d:
	/* 0x1f6d: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1f6e:
	/* 0x1f6e: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_1f73:
	/* 0x1f73: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1f76:
	/* 0x1f76: jae    1f7e <filter_32ty_map+0x7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1f7e;
	}
x86_l_1f78:
	/* 0x1f78: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f7b:
	/* 0x1f7b: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_1f7e:
	/* 0x1f7e: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1f81:
	/* 0x1f81: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1f85:
	/* 0x1f85: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1f86:
	/* 0x1f86: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_1f88:
	/* 0x1f88: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1f89:
	/* 0x1f89: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1f8c:
	/* 0x1f8c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f91:
	/* 0x1f91: cmp    rcx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 37ULL);
x86_l_1f95:
	/* 0x1f95: ja     2008 <filter_8ty_selector_val+0x7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2008;
	}
x86_l_1f97:
	/* 0x1f97: movabs rdx,0x200c000040 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280128ULL);
x86_l_1fa1:
	/* 0x1fa1: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1fa5:
	/* 0x1fa5: jae    1fa8 <filter_8ty_selector_val+0x1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1fa8;
	}
x86_l_1fa7:
	/* 0x1fa7: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1fa8:
	/* 0x1fa8: mov    edx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 24ULL);
x86_l_1fad:
	/* 0x1fad: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1fb1:
	/* 0x1fb1: jae    1fc8 <filter_8ty_selector_val+0x3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1fc8;
	}
x86_l_1fb3:
	/* 0x1fb3: movzx  edx,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1fb6:
	/* 0x1fb6: cmp    DWORD PTR [rdi+0x10],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fb9:
	/* 0x1fb9: jne    20de <filter_8ty_selector_val+0x155> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8414ULL;
	}
x86_l_1fbf:
	/* 0x1fbf: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fc1:
	/* 0x1fc1: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1fc4:
	/* 0x1fc4: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_1fc7:
	/* 0x1fc7: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1fc8:
	/* 0x1fc8: cmp    rcx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 12ULL);
x86_l_1fcc:
	/* 0x1fcc: jne    2008 <filter_8ty_selector_val+0x7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2008;
	}
x86_l_1fce:
	/* 0x1fce: movzx  ecx,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1fd1:
	/* 0x1fd1: test   DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fd4:
	/* 0x1fd4: jne    1fa7 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1fa7;
	}
x86_l_1fd6:
	/* 0x1fd6: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1fd9:
	/* 0x1fd9: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1fdc:
	/* 0x1fdc: jb     21a0 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8608ULL;
	}
x86_l_1fe2:
	/* 0x1fe2: test   DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1fe5:
	/* 0x1fe5: jne    1fa7 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1fa7;
	}
x86_l_1fe7:
	/* 0x1fe7: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1fea:
	/* 0x1fea: jb     21a0 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8608ULL;
	}
x86_l_1ff0:
	/* 0x1ff0: test   DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ff3:
	/* 0x1ff3: jne    1fa7 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1fa7;
	}
x86_l_1ff5:
	/* 0x1ff5: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_1ff8:
	/* 0x1ff8: jb     21a0 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8608ULL;
	}
x86_l_1ffe:
	/* 0x1ffe: test   DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2001:
	/* 0x2001: jne    1fa7 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1fa7;
	}
x86_l_2003:
	/* 0x2003: jmp    21a0 <filter_8ty_selector_val+0x217> */
	return 8608ULL;
x86_l_2008:
	/* 0x2008: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_200b:
	/* 0x200b: je     207a <filter_8ty_selector_val+0xf1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_207a;
	}
x86_l_200d:
	/* 0x200d: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2010:
	/* 0x2010: jne    21a0 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8608ULL;
	}
x86_l_2016:
	/* 0x2016: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2019:
	/* 0x2019: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_201c:
	/* 0x201c: ja     2167 <filter_8ty_selector_val+0x1de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8551ULL;
	}
x86_l_2022:
	/* 0x2022: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_2027:
	/* 0x2027: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_202a:
	/* 0x202a: jae    2167 <filter_8ty_selector_val+0x1de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8551ULL;
	}
x86_l_2030:
	/* 0x2030: movsx  ecx,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2033:
	/* 0x2033: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2036:
	/* 0x2036: jg     1fa7 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1fa7;
	}
x86_l_203c:
	/* 0x203c: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_203f:
	/* 0x203f: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_2042:
	/* 0x2042: jb     21a0 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8608ULL;
	}
x86_l_2048:
	/* 0x2048: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_204b:
	/* 0x204b: jg     1fa7 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1fa7;
	}
x86_l_2051:
	/* 0x2051: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_2054:
	/* 0x2054: jb     21a0 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8608ULL;
	}
x86_l_205a:
	/* 0x205a: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_205d:
	/* 0x205d: jg     1fa7 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1fa7;
	}
x86_l_2063:
	/* 0x2063: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_2066:
	/* 0x2066: jb     21a0 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8608ULL;
	}
x86_l_206c:
	/* 0x206c: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_206f:
	/* 0x206f: jg     1fa7 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1fa7;
	}
x86_l_2075:
	/* 0x2075: jmp    21a0 <filter_8ty_selector_val+0x217> */
	return 8608ULL;
x86_l_207a:
	/* 0x207a: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_207d:
	/* 0x207d: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2080:
	/* 0x2080: ja     212c <filter_8ty_selector_val+0x1a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8492ULL;
	}
x86_l_2086:
	/* 0x2086: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_208b:
	/* 0x208b: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
	return 8334ULL;
}

static __noinline __u64 tetragon_bpf_generic_retuprobe_v61_generic_retuprobe_filter_arg_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8334ULL: goto x86_l_208e;
	case 8340ULL: goto x86_l_2094;
	case 8343ULL: goto x86_l_2097;
	case 8346ULL: goto x86_l_209a;
	case 8352ULL: goto x86_l_20a0;
	case 8355ULL: goto x86_l_20a3;
	case 8358ULL: goto x86_l_20a6;
	case 8364ULL: goto x86_l_20ac;
	case 8367ULL: goto x86_l_20af;
	case 8373ULL: goto x86_l_20b5;
	case 8376ULL: goto x86_l_20b8;
	case 8382ULL: goto x86_l_20be;
	case 8385ULL: goto x86_l_20c1;
	case 8391ULL: goto x86_l_20c7;
	case 8394ULL: goto x86_l_20ca;
	case 8400ULL: goto x86_l_20d0;
	case 8403ULL: goto x86_l_20d3;
	case 8409ULL: goto x86_l_20d9;
	case 8414ULL: goto x86_l_20de;
	case 8417ULL: goto x86_l_20e1;
	case 8420ULL: goto x86_l_20e4;
	case 8422ULL: goto x86_l_20e6;
	case 8425ULL: goto x86_l_20e9;
	case 8431ULL: goto x86_l_20ef;
	case 8434ULL: goto x86_l_20f2;
	case 8436ULL: goto x86_l_20f4;
	case 8439ULL: goto x86_l_20f7;
	case 8445ULL: goto x86_l_20fd;
	case 8448ULL: goto x86_l_2100;
	case 8450ULL: goto x86_l_2102;
	case 8453ULL: goto x86_l_2105;
	case 8459ULL: goto x86_l_210b;
	case 8462ULL: goto x86_l_210e;
	case 8468ULL: goto x86_l_2114;
	case 8470ULL: goto x86_l_2116;
	case 8480ULL: goto x86_l_2120;
	case 8484ULL: goto x86_l_2124;
	case 8490ULL: goto x86_l_212a;
	case 8492ULL: goto x86_l_212c;
	case 8495ULL: goto x86_l_212f;
	case 8498ULL: goto x86_l_2132;
	case 8504ULL: goto x86_l_2138;
	case 8507ULL: goto x86_l_213b;
	case 8510ULL: goto x86_l_213e;
	case 8512ULL: goto x86_l_2140;
	case 8515ULL: goto x86_l_2143;
	case 8521ULL: goto x86_l_2149;
	case 8524ULL: goto x86_l_214c;
	case 8526ULL: goto x86_l_214e;
	case 8529ULL: goto x86_l_2151;
	case 8535ULL: goto x86_l_2157;
	case 8538ULL: goto x86_l_215a;
	case 8540ULL: goto x86_l_215c;
	case 8543ULL: goto x86_l_215f;
	case 8549ULL: goto x86_l_2165;
	case 8551ULL: goto x86_l_2167;
	case 8554ULL: goto x86_l_216a;
	case 8557ULL: goto x86_l_216d;
	case 8563ULL: goto x86_l_2173;
	case 8566ULL: goto x86_l_2176;
	case 8569ULL: goto x86_l_2179;
	case 8571ULL: goto x86_l_217b;
	case 8574ULL: goto x86_l_217e;
	case 8580ULL: goto x86_l_2184;
	case 8583ULL: goto x86_l_2187;
	case 8585ULL: goto x86_l_2189;
	case 8588ULL: goto x86_l_218c;
	case 8594ULL: goto x86_l_2192;
	case 8597ULL: goto x86_l_2195;
	case 8599ULL: goto x86_l_2197;
	case 8602ULL: goto x86_l_219a;
	case 8608ULL: goto x86_l_21a0;
	case 8610ULL: goto x86_l_21a2;
	case 8611ULL: goto x86_l_21a3;
	case 8614ULL: goto x86_l_21a6;
	case 8617ULL: goto x86_l_21a9;
	case 8620ULL: goto x86_l_21ac;
	case 8626ULL: goto x86_l_21b2;
	case 8631ULL: goto x86_l_21b7;
	case 8634ULL: goto x86_l_21ba;
	case 8640ULL: goto x86_l_21c0;
	case 8643ULL: goto x86_l_21c3;
	case 8646ULL: goto x86_l_21c6;
	case 8648ULL: goto x86_l_21c8;
	case 8653ULL: goto x86_l_21cd;
	case 8656ULL: goto x86_l_21d0;
	case 8658ULL: goto x86_l_21d2;
	case 8661ULL: goto x86_l_21d5;
	case 8667ULL: goto x86_l_21db;
	case 8670ULL: goto x86_l_21de;
	case 8673ULL: goto x86_l_21e1;
	case 8679ULL: goto x86_l_21e7;
	case 8682ULL: goto x86_l_21ea;
	case 8684ULL: goto x86_l_21ec;
	case 8687ULL: goto x86_l_21ef;
	case 8693ULL: goto x86_l_21f5;
	case 8696ULL: goto x86_l_21f8;
	case 8702ULL: goto x86_l_21fe;
	case 8705ULL: goto x86_l_2201;
	case 8707ULL: goto x86_l_2203;
	case 8710ULL: goto x86_l_2206;
	case 8716ULL: goto x86_l_220c;
	case 8719ULL: goto x86_l_220f;
	case 8725ULL: goto x86_l_2215;
	case 8727ULL: goto x86_l_2217;
	case 8730ULL: goto x86_l_221a;
	case 8736ULL: goto x86_l_2220;
	case 8739ULL: goto x86_l_2223;
	case 8745ULL: goto x86_l_2229;
	case 8750ULL: goto x86_l_222e;
	case 8753ULL: goto x86_l_2231;
	case 8756ULL: goto x86_l_2234;
	case 8760ULL: goto x86_l_2238;
	case 8763ULL: goto x86_l_223b;
	case 8766ULL: goto x86_l_223e;
	case 8769ULL: goto x86_l_2241;
	case 8772ULL: goto x86_l_2244;
	case 8778ULL: goto x86_l_224a;
	case 8781ULL: goto x86_l_224d;
	case 8785ULL: goto x86_l_2251;
	case 8788ULL: goto x86_l_2254;
	case 8792ULL: goto x86_l_2258;
	case 8795ULL: goto x86_l_225b;
	case 8798ULL: goto x86_l_225e;
	case 8801ULL: goto x86_l_2261;
	case 8807ULL: goto x86_l_2267;
	case 8810ULL: goto x86_l_226a;
	case 8814ULL: goto x86_l_226e;
	case 8817ULL: goto x86_l_2271;
	case 8821ULL: goto x86_l_2275;
	case 8824ULL: goto x86_l_2278;
	case 8827ULL: goto x86_l_227b;
	case 8830ULL: goto x86_l_227e;
	case 8836ULL: goto x86_l_2284;
	case 8839ULL: goto x86_l_2287;
	case 8842ULL: goto x86_l_228a;
	case 8845ULL: goto x86_l_228d;
	case 8849ULL: goto x86_l_2291;
	case 8851ULL: goto x86_l_2293;
	case 8854ULL: goto x86_l_2296;
	case 8857ULL: goto x86_l_2299;
	case 8859ULL: goto x86_l_229b;
	case 8864ULL: goto x86_l_22a0;
	case 8867ULL: goto x86_l_22a3;
	case 8869ULL: goto x86_l_22a5;
	case 8872ULL: goto x86_l_22a8;
	case 8874ULL: goto x86_l_22aa;
	case 8875ULL: goto x86_l_22ab;
	case 8878ULL: goto x86_l_22ae;
	case 8881ULL: goto x86_l_22b1;
	case 8885ULL: goto x86_l_22b5;
	case 8888ULL: goto x86_l_22b8;
	case 8891ULL: goto x86_l_22bb;
	case 8894ULL: goto x86_l_22be;
	case 8897ULL: goto x86_l_22c1;
	case 8903ULL: goto x86_l_22c7;
	case 8906ULL: goto x86_l_22ca;
	case 8910ULL: goto x86_l_22ce;
	case 8913ULL: goto x86_l_22d1;
	case 8917ULL: goto x86_l_22d5;
	case 8920ULL: goto x86_l_22d8;
	case 8923ULL: goto x86_l_22db;
	case 8926ULL: goto x86_l_22de;
	case 8928ULL: goto x86_l_22e0;
	case 8931ULL: goto x86_l_22e3;
	case 8935ULL: goto x86_l_22e7;
	case 8938ULL: goto x86_l_22ea;
	case 8942ULL: goto x86_l_22ee;
	case 8945ULL: goto x86_l_22f1;
	case 8948ULL: goto x86_l_22f4;
	case 8951ULL: goto x86_l_22f7;
	case 8953ULL: goto x86_l_22f9;
	case 8956ULL: goto x86_l_22fc;
	case 8959ULL: goto x86_l_22ff;
	case 8962ULL: goto x86_l_2302;
	case 8966ULL: goto x86_l_2306;
	case 8969ULL: goto x86_l_2309;
	case 8972ULL: goto x86_l_230c;
	case 8974ULL: goto x86_l_230e;
	case 8977ULL: goto x86_l_2311;
	case 8980ULL: goto x86_l_2314;
	case 8982ULL: goto x86_l_2316;
	case 8985ULL: goto x86_l_2319;
	case 8987ULL: goto x86_l_231b;
	case 8990ULL: goto x86_l_231e;
	case 8992ULL: goto x86_l_2320;
	case 8995ULL: goto x86_l_2323;
	case 8997ULL: goto x86_l_2325;
	case 9000ULL: goto x86_l_2328;
	case 9002ULL: goto x86_l_232a;
	case 9005ULL: goto x86_l_232d;
	case 9011ULL: goto x86_l_2333;
	case 9014ULL: goto x86_l_2336;
	case 9016ULL: goto x86_l_2338;
	case 9018ULL: goto x86_l_233a;
	case 9021ULL: goto x86_l_233d;
	case 9023ULL: goto x86_l_233f;
	case 9026ULL: goto x86_l_2342;
	case 9032ULL: goto x86_l_2348;
	case 9034ULL: goto x86_l_234a;
	case 9036ULL: goto x86_l_234c;
	case 9039ULL: goto x86_l_234f;
	case 9042ULL: goto x86_l_2352;
	case 9045ULL: goto x86_l_2355;
	case 9047ULL: goto x86_l_2357;
	case 9050ULL: goto x86_l_235a;
	case 9051ULL: goto x86_l_235b;
	case 9053ULL: goto x86_l_235d;
	case 9054ULL: goto x86_l_235e;
	case 9058ULL: goto x86_l_2362;
	case 9061ULL: goto x86_l_2365;
	case 9064ULL: goto x86_l_2368;
	case 9068ULL: goto x86_l_236c;
	case 9072ULL: goto x86_l_2370;
	case 9079ULL: goto x86_l_2377;
	case 9084ULL: goto x86_l_237c;
	case 9089ULL: goto x86_l_2381;
	case 9091ULL: goto x86_l_2383;
	case 9094ULL: goto x86_l_2386;
	case 9096ULL: goto x86_l_2388;
	case 9099ULL: goto x86_l_238b;
	case 9103ULL: goto x86_l_238f;
	case 9108ULL: goto x86_l_2394;
	case 9113ULL: goto x86_l_2399;
	case 9118ULL: goto x86_l_239e;
	case 9120ULL: goto x86_l_23a0;
	case 9123ULL: goto x86_l_23a3;
	case 9125ULL: goto x86_l_23a5;
	case 9128ULL: goto x86_l_23a8;
	case 9130ULL: goto x86_l_23aa;
	case 9135ULL: goto x86_l_23af;
	case 9138ULL: goto x86_l_23b2;
	case 9140ULL: goto x86_l_23b4;
	case 9143ULL: goto x86_l_23b7;
	case 9146ULL: goto x86_l_23ba;
	case 9148ULL: goto x86_l_23bc;
	case 9150ULL: goto x86_l_23be;
	case 9154ULL: goto x86_l_23c2;
	case 9155ULL: goto x86_l_23c3;
	case 9157ULL: goto x86_l_23c5;
	case 9158ULL: goto x86_l_23c6;
	case 9163ULL: goto x86_l_23cb;
	case 9166ULL: goto x86_l_23ce;
	case 9168ULL: goto x86_l_23d0;
	case 9171ULL: goto x86_l_23d3;
	case 9174ULL: goto x86_l_23d6;
	case 9177ULL: goto x86_l_23d9;
	case 9181ULL: goto x86_l_23dd;
	case 9182ULL: goto x86_l_23de;
	case 9184ULL: goto x86_l_23e0;
	case 9185ULL: goto x86_l_23e1;
	case 9186ULL: goto x86_l_23e2;
	case 9190ULL: goto x86_l_23e6;
	case 9197ULL: goto x86_l_23ed;
	case 9199ULL: goto x86_l_23ef;
	case 9205ULL: goto x86_l_23f5;
	case 9211ULL: goto x86_l_23fb;
	case 9214ULL: goto x86_l_23fe;
	case 9218ULL: goto x86_l_2402;
	case 9222ULL: goto x86_l_2406;
	case 9227ULL: goto x86_l_240b;
	case 9232ULL: goto x86_l_2410;
	case 9237ULL: goto x86_l_2415;
	case 9239ULL: goto x86_l_2417;
	case 9243ULL: goto x86_l_241b;
	case 9247ULL: goto x86_l_241f;
	case 9252ULL: goto x86_l_2424;
	case 9254ULL: goto x86_l_2426;
	case 9257ULL: goto x86_l_2429;
	case 9259ULL: goto x86_l_242b;
	case 9261ULL: goto x86_l_242d;
	case 9266ULL: goto x86_l_2432;
	case 9272ULL: goto x86_l_2438;
	case 9277ULL: goto x86_l_243d;
	case 9279ULL: goto x86_l_243f;
	case 9281ULL: goto x86_l_2441;
	case 9284ULL: goto x86_l_2444;
	case 9287ULL: goto x86_l_2447;
	case 9289ULL: goto x86_l_2449;
	case 9292ULL: goto x86_l_244c;
	case 9294ULL: goto x86_l_244e;
	case 9296ULL: goto x86_l_2450;
	case 9298ULL: goto x86_l_2452;
	case 9300ULL: goto x86_l_2454;
	case 9303ULL: goto x86_l_2457;
	case 9305ULL: goto x86_l_2459;
	case 9308ULL: goto x86_l_245c;
	case 9310ULL: goto x86_l_245e;
	case 9312ULL: goto x86_l_2460;
	case 9314ULL: goto x86_l_2462;
	case 9316ULL: goto x86_l_2464;
	case 9319ULL: goto x86_l_2467;
	case 9321ULL: goto x86_l_2469;
	case 9324ULL: goto x86_l_246c;
	case 9326ULL: goto x86_l_246e;
	case 9328ULL: goto x86_l_2470;
	case 9330ULL: goto x86_l_2472;
	case 9332ULL: goto x86_l_2474;
	case 9335ULL: goto x86_l_2477;
	case 9339ULL: goto x86_l_247b;
	case 9340ULL: goto x86_l_247c;
	case 9341ULL: goto x86_l_247d;
	case 9343ULL: goto x86_l_247f;
	case 9347ULL: goto x86_l_2483;
	case 9348ULL: goto x86_l_2484;
	default: return 0xffffffffffffffffULL;
	}
x86_l_208e:
	/* 0x208e: jae    212c <filter_8ty_selector_val+0x1a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_212c;
	}
x86_l_2094:
	/* 0x2094: movsx  ecx,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2097:
	/* 0x2097: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_209a:
	/* 0x209a: jl     1fa7 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 8103ULL;
	}
x86_l_20a0:
	/* 0x20a0: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20a3:
	/* 0x20a3: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_20a6:
	/* 0x20a6: jb     21a0 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_21a0;
	}
x86_l_20ac:
	/* 0x20ac: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_20af:
	/* 0x20af: jl     1fa7 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 8103ULL;
	}
x86_l_20b5:
	/* 0x20b5: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_20b8:
	/* 0x20b8: jb     21a0 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_21a0;
	}
x86_l_20be:
	/* 0x20be: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_20c1:
	/* 0x20c1: jl     1fa7 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 8103ULL;
	}
x86_l_20c7:
	/* 0x20c7: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_20ca:
	/* 0x20ca: jb     21a0 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_21a0;
	}
x86_l_20d0:
	/* 0x20d0: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_20d3:
	/* 0x20d3: jl     1fa7 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 8103ULL;
	}
x86_l_20d9:
	/* 0x20d9: jmp    21a0 <filter_8ty_selector_val+0x217> */
	goto x86_l_21a0;
x86_l_20de:
	/* 0x20de: mov    esi,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20e1:
	/* 0x20e1: cmp    esi,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 13ULL);
x86_l_20e4:
	/* 0x20e4: jb     210b <filter_8ty_selector_val+0x182> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_210b;
	}
x86_l_20e6:
	/* 0x20e6: cmp    DWORD PTR [rdi+0x14],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_20e9:
	/* 0x20e9: je     1fbf <filter_8ty_selector_val+0x36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8127ULL;
	}
x86_l_20ef:
	/* 0x20ef: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_20f2:
	/* 0x20f2: jb     210b <filter_8ty_selector_val+0x182> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_210b;
	}
x86_l_20f4:
	/* 0x20f4: cmp    DWORD PTR [rdi+0x18],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_20f7:
	/* 0x20f7: je     1fbf <filter_8ty_selector_val+0x36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8127ULL;
	}
x86_l_20fd:
	/* 0x20fd: cmp    esi,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 21ULL);
x86_l_2100:
	/* 0x2100: jb     210b <filter_8ty_selector_val+0x182> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_210b;
	}
x86_l_2102:
	/* 0x2102: cmp    DWORD PTR [rdi+0x1c],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2105:
	/* 0x2105: je     1fbf <filter_8ty_selector_val+0x36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8127ULL;
	}
x86_l_210b:
	/* 0x210b: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_210e:
	/* 0x210e: ja     21a0 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_21a0;
	}
x86_l_2114:
	/* 0x2114: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2116:
	/* 0x2116: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_2120:
	/* 0x2120: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_2124:
	/* 0x2124: jb     1fa7 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8103ULL;
	}
x86_l_212a:
	/* 0x212a: jmp    21a0 <filter_8ty_selector_val+0x217> */
	goto x86_l_21a0;
x86_l_212c:
	/* 0x212c: movzx  ecx,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_212f:
	/* 0x212f: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2132:
	/* 0x2132: jb     1fa7 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8103ULL;
	}
x86_l_2138:
	/* 0x2138: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_213b:
	/* 0x213b: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_213e:
	/* 0x213e: jb     21a0 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_21a0;
	}
x86_l_2140:
	/* 0x2140: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2143:
	/* 0x2143: jb     1fa7 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8103ULL;
	}
x86_l_2149:
	/* 0x2149: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_214c:
	/* 0x214c: jb     21a0 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_21a0;
	}
x86_l_214e:
	/* 0x214e: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2151:
	/* 0x2151: jb     1fa7 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8103ULL;
	}
x86_l_2157:
	/* 0x2157: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_215a:
	/* 0x215a: jb     21a0 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_21a0;
	}
x86_l_215c:
	/* 0x215c: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_215f:
	/* 0x215f: jb     1fa7 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8103ULL;
	}
x86_l_2165:
	/* 0x2165: jmp    21a0 <filter_8ty_selector_val+0x217> */
	goto x86_l_21a0;
x86_l_2167:
	/* 0x2167: movzx  ecx,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_216a:
	/* 0x216a: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_216d:
	/* 0x216d: ja     1fa7 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8103ULL;
	}
x86_l_2173:
	/* 0x2173: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2176:
	/* 0x2176: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_2179:
	/* 0x2179: jb     21a0 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_21a0;
	}
x86_l_217b:
	/* 0x217b: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_217e:
	/* 0x217e: ja     1fa7 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8103ULL;
	}
x86_l_2184:
	/* 0x2184: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_2187:
	/* 0x2187: jb     21a0 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_21a0;
	}
x86_l_2189:
	/* 0x2189: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_218c:
	/* 0x218c: ja     1fa7 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8103ULL;
	}
x86_l_2192:
	/* 0x2192: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_2195:
	/* 0x2195: jb     21a0 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_21a0;
	}
x86_l_2197:
	/* 0x2197: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_219a:
	/* 0x219a: ja     1fa7 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8103ULL;
	}
x86_l_21a0:
	/* 0x21a0: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_21a2:
	/* 0x21a2: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_21a3:
	/* 0x21a3: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_21a6:
	/* 0x21a6: mov    eax,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_21a9:
	/* 0x21a9: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_21ac:
	/* 0x21ac: ja     2293 <filter_8ty_range+0xf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2293;
	}
x86_l_21b2:
	/* 0x21b2: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_21b7:
	/* 0x21b7: bt     edx,eax */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_21ba:
	/* 0x21ba: jae    2293 <filter_8ty_range+0xf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2293;
	}
x86_l_21c0:
	/* 0x21c0: movsx  esi,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_21c3:
	/* 0x21c3: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_21c6:
	/* 0x21c6: jne    222e <filter_8ty_range+0x8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_222e;
	}
x86_l_21c8:
	/* 0x21c8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_21cd:
	/* 0x21cd: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21d0:
	/* 0x21d0: jg     21db <filter_8ty_range+0x38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_21db;
	}
x86_l_21d2:
	/* 0x21d2: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_21d5:
	/* 0x21d5: jge    22aa <filter_8ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_GE)) {
		goto x86_l_22aa;
	}
x86_l_21db:
	/* 0x21db: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21de:
	/* 0x21de: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_21e1:
	/* 0x21e1: jb     234a <filter_8ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_234a;
	}
x86_l_21e7:
	/* 0x21e7: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_21ea:
	/* 0x21ea: jg     21f5 <filter_8ty_range+0x52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_21f5;
	}
x86_l_21ec:
	/* 0x21ec: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_21ef:
	/* 0x21ef: jge    22aa <filter_8ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_GE)) {
		goto x86_l_22aa;
	}
x86_l_21f5:
	/* 0x21f5: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_21f8:
	/* 0x21f8: jb     234a <filter_8ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_234a;
	}
x86_l_21fe:
	/* 0x21fe: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2201:
	/* 0x2201: jg     220c <filter_8ty_range+0x69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_220c;
	}
x86_l_2203:
	/* 0x2203: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2206:
	/* 0x2206: jge    22aa <filter_8ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_GE)) {
		goto x86_l_22aa;
	}
x86_l_220c:
	/* 0x220c: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_220f:
	/* 0x220f: jb     234a <filter_8ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_234a;
	}
x86_l_2215:
	/* 0x2215: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2217:
	/* 0x2217: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_221a:
	/* 0x221a: jg     234c <filter_8ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_234c;
	}
x86_l_2220:
	/* 0x2220: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2223:
	/* 0x2223: jge    22aa <filter_8ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_GE)) {
		goto x86_l_22aa;
	}
x86_l_2229:
	/* 0x2229: jmp    234c <filter_8ty_range+0x1a9> */
	goto x86_l_234c;
x86_l_222e:
	/* 0x222e: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2231:
	/* 0x2231: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2234:
	/* 0x2234: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_2238:
	/* 0x2238: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_223b:
	/* 0x223b: setge  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_GE);
x86_l_223e:
	/* 0x223e: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_2241:
	/* 0x2241: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_2244:
	/* 0x2244: jb     234c <filter_8ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_234c;
	}
x86_l_224a:
	/* 0x224a: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_224d:
	/* 0x224d: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_2251:
	/* 0x2251: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2254:
	/* 0x2254: setge  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_GE);
x86_l_2258:
	/* 0x2258: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_225b:
	/* 0x225b: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_225e:
	/* 0x225e: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_2261:
	/* 0x2261: jb     234c <filter_8ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_234c;
	}
x86_l_2267:
	/* 0x2267: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_226a:
	/* 0x226a: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_226e:
	/* 0x226e: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2271:
	/* 0x2271: setge  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_GE);
x86_l_2275:
	/* 0x2275: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_2278:
	/* 0x2278: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_227b:
	/* 0x227b: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_227e:
	/* 0x227e: jb     234c <filter_8ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_234c;
	}
x86_l_2284:
	/* 0x2284: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2287:
	/* 0x2287: setle  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_LE);
x86_l_228a:
	/* 0x228a: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_228d:
	/* 0x228d: setge  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_GE);
x86_l_2291:
	/* 0x2291: jmp    2306 <filter_8ty_range+0x163> */
	goto x86_l_2306;
x86_l_2293:
	/* 0x2293: movzx  esi,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2296:
	/* 0x2296: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_2299:
	/* 0x2299: jne    22ab <filter_8ty_range+0x108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_22ab;
	}
x86_l_229b:
	/* 0x229b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_22a0:
	/* 0x22a0: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22a3:
	/* 0x22a3: ja     230e <filter_8ty_range+0x16b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_230e;
	}
x86_l_22a5:
	/* 0x22a5: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_22a8:
	/* 0x22a8: jb     230e <filter_8ty_range+0x16b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_230e;
	}
x86_l_22aa:
	/* 0x22aa: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_22ab:
	/* 0x22ab: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22ae:
	/* 0x22ae: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22b1:
	/* 0x22b1: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_22b5:
	/* 0x22b5: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_22b8:
	/* 0x22b8: setae  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_AE);
x86_l_22bb:
	/* 0x22bb: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_22be:
	/* 0x22be: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_22c1:
	/* 0x22c1: jb     234c <filter_8ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_234c;
	}
x86_l_22c7:
	/* 0x22c7: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_22ca:
	/* 0x22ca: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_22ce:
	/* 0x22ce: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_22d1:
	/* 0x22d1: setae  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_AE);
x86_l_22d5:
	/* 0x22d5: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_22d8:
	/* 0x22d8: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_22db:
	/* 0x22db: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_22de:
	/* 0x22de: jb     234c <filter_8ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_234c;
	}
x86_l_22e0:
	/* 0x22e0: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_22e3:
	/* 0x22e3: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_22e7:
	/* 0x22e7: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_22ea:
	/* 0x22ea: setae  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_AE);
x86_l_22ee:
	/* 0x22ee: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_22f1:
	/* 0x22f1: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_22f4:
	/* 0x22f4: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_22f7:
	/* 0x22f7: jb     234c <filter_8ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_234c;
	}
x86_l_22f9:
	/* 0x22f9: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_22fc:
	/* 0x22fc: setbe  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_BE);
x86_l_22ff:
	/* 0x22ff: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2302:
	/* 0x2302: setae  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_AE);
x86_l_2306:
	/* 0x2306: and    sil,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_2309:
	/* 0x2309: or     dl,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_8, X86_ALU_OR);
x86_l_230c:
	/* 0x230c: jmp    234c <filter_8ty_range+0x1a9> */
	goto x86_l_234c;
x86_l_230e:
	/* 0x230e: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2311:
	/* 0x2311: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_2314:
	/* 0x2314: jb     234a <filter_8ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_234a;
	}
x86_l_2316:
	/* 0x2316: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2319:
	/* 0x2319: ja     2320 <filter_8ty_range+0x17d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2320;
	}
x86_l_231b:
	/* 0x231b: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_231e:
	/* 0x231e: jae    22aa <filter_8ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_22aa;
	}
x86_l_2320:
	/* 0x2320: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_2323:
	/* 0x2323: jb     234a <filter_8ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_234a;
	}
x86_l_2325:
	/* 0x2325: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2328:
	/* 0x2328: ja     2333 <filter_8ty_range+0x190> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2333;
	}
x86_l_232a:
	/* 0x232a: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_232d:
	/* 0x232d: jae    22aa <filter_8ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_22aa;
	}
x86_l_2333:
	/* 0x2333: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_2336:
	/* 0x2336: jb     234a <filter_8ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_234a;
	}
x86_l_2338:
	/* 0x2338: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_233a:
	/* 0x233a: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_233d:
	/* 0x233d: ja     234c <filter_8ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_234c;
	}
x86_l_233f:
	/* 0x233f: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2342:
	/* 0x2342: jae    22aa <filter_8ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_22aa;
	}
x86_l_2348:
	/* 0x2348: jmp    234c <filter_8ty_range+0x1a9> */
	goto x86_l_234c;
x86_l_234a:
	/* 0x234a: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_234c:
	/* 0x234c: cmp    ecx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 32ULL);
x86_l_234f:
	/* 0x234f: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_2352:
	/* 0x2352: xor    dl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_2355:
	/* 0x2355: and    dl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_2357:
	/* 0x2357: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_235a:
	/* 0x235a: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_235b:
	/* 0x235b: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_235d:
	/* 0x235d: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_235e:
	/* 0x235e: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_2362:
	/* 0x2362: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_2365:
	/* 0x2365: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_2368:
	/* 0x2368: movzx  eax,BYTE PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_236c:
	/* 0x236c: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2370:
	/* 0x2370: mov    rdi,QWORD PTR [rip+0x1290] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_2377:
	/* 0x2377: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_237c:
	/* 0x237c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2381:
	/* 0x2381: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2383:
	/* 0x2383: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2386:
	/* 0x2386: je     23bc <filter_8ty_map+0x61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23bc;
	}
x86_l_2388:
	/* 0x2388: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_238b:
	/* 0x238b: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_238f:
	/* 0x238f: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2394:
	/* 0x2394: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2399:
	/* 0x2399: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_239e:
	/* 0x239e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23a0:
	/* 0x23a0: mov    edx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_23a3:
	/* 0x23a3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_23a5:
	/* 0x23a5: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_23a8:
	/* 0x23a8: ja     23d6 <filter_8ty_map+0x7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_23d6;
	}
x86_l_23aa:
	/* 0x23aa: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_23af:
	/* 0x23af: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_23b2:
	/* 0x23b2: jae    23c6 <filter_8ty_map+0x6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_23c6;
	}
x86_l_23b4:
	/* 0x23b4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_23b7:
	/* 0x23b7: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_23ba:
	/* 0x23ba: jmp    23d6 <filter_8ty_map+0x7b> */
	goto x86_l_23d6;
x86_l_23bc:
	/* 0x23bc: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_23be:
	/* 0x23be: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_23c2:
	/* 0x23c2: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_23c3:
	/* 0x23c3: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_23c5:
	/* 0x23c5: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_23c6:
	/* 0x23c6: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_23cb:
	/* 0x23cb: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_23ce:
	/* 0x23ce: jae    23d6 <filter_8ty_map+0x7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_23d6;
	}
x86_l_23d0:
	/* 0x23d0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_23d3:
	/* 0x23d3: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_23d6:
	/* 0x23d6: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_23d9:
	/* 0x23d9: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_23dd:
	/* 0x23dd: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_23de:
	/* 0x23de: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_23e0:
	/* 0x23e0: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_23e1:
	/* 0x23e1: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_23e2:
	/* 0x23e2: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_23e6:
	/* 0x23e6: mov    WORD PTR [rsp+0xe],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 60129542144ULL);
x86_l_23ed:
	/* 0x23ed: mov    eax,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23ef:
	/* 0x23ef: cmp    rax,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4096ULL);
x86_l_23f5:
	/* 0x23f5: ja     247d <filter_file_type+0x9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_247d;
	}
x86_l_23fb:
	/* 0x23fb: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_23fe:
	/* 0x23fe: lea    rcx,[rsi+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2402:
	/* 0x2402: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2406:
	/* 0x2406: lea    rdi,[rsp+0xe] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_240b:
	/* 0x240b: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2410:
	/* 0x2410: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2415:
	/* 0x2415: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2417:
	/* 0x2417: lea    rdx,[rsi+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_241b:
	/* 0x241b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_241f:
	/* 0x241f: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2424:
	/* 0x2424: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2426:
	/* 0x2426: mov    edx,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2429:
	/* 0x2429: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_242b:
	/* 0x242b: je     247d <filter_file_type+0x9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_247d;
	}
x86_l_242d:
	/* 0x242d: movzx  ecx,WORD PTR [rsp+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_2432:
	/* 0x2432: and    ecx,0xf000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 61440ULL);
x86_l_2438:
	/* 0x2438: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_243d:
	/* 0x243d: cmp    edx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_243f:
	/* 0x243f: je     247f <filter_file_type+0x9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_247f;
	}
x86_l_2441:
	/* 0x2441: mov    edx,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2444:
	/* 0x2444: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_2447:
	/* 0x2447: jbe    247d <filter_file_type+0x9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_247d;
	}
x86_l_2449:
	/* 0x2449: mov    esi,DWORD PTR [rbx+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_244c:
	/* 0x244c: test   esi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_32);
x86_l_244e:
	/* 0x244e: je     247d <filter_file_type+0x9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_247d;
	}
x86_l_2450:
	/* 0x2450: cmp    esi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_2452:
	/* 0x2452: je     247f <filter_file_type+0x9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_247f;
	}
x86_l_2454:
	/* 0x2454: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_2457:
	/* 0x2457: jb     247d <filter_file_type+0x9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_247d;
	}
x86_l_2459:
	/* 0x2459: mov    esi,DWORD PTR [rbx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_245c:
	/* 0x245c: test   esi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_32);
x86_l_245e:
	/* 0x245e: je     247d <filter_file_type+0x9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_247d;
	}
x86_l_2460:
	/* 0x2460: cmp    esi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_2462:
	/* 0x2462: je     247f <filter_file_type+0x9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_247f;
	}
x86_l_2464:
	/* 0x2464: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_2467:
	/* 0x2467: jb     247d <filter_file_type+0x9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_247d;
	}
x86_l_2469:
	/* 0x2469: mov    edx,DWORD PTR [rbx+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_246c:
	/* 0x246c: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_246e:
	/* 0x246e: je     247d <filter_file_type+0x9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_247d;
	}
x86_l_2470:
	/* 0x2470: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2472:
	/* 0x2472: cmp    edx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_2474:
	/* 0x2474: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_2477:
	/* 0x2477: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_247b:
	/* 0x247b: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_247c:
	/* 0x247c: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_247d:
	/* 0x247d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_247f:
	/* 0x247f: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2483:
	/* 0x2483: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_2484:
	/* 0x2484: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_retuprobe_v61_generic_retuprobe_filter_arg_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 10436U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1523ULL)
			__x86_pc = tetragon_bpf_generic_retuprobe_v61_generic_retuprobe_filter_arg_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1525ULL && __x86_pc <= 2815ULL)
			__x86_pc = tetragon_bpf_generic_retuprobe_v61_generic_retuprobe_filter_arg_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 2819ULL && __x86_pc <= 4238ULL)
			__x86_pc = tetragon_bpf_generic_retuprobe_v61_generic_retuprobe_filter_arg_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 4241ULL && __x86_pc <= 5640ULL)
			__x86_pc = tetragon_bpf_generic_retuprobe_v61_generic_retuprobe_filter_arg_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 5642ULL && __x86_pc <= 6982ULL)
			__x86_pc = tetragon_bpf_generic_retuprobe_v61_generic_retuprobe_filter_arg_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 6984ULL && __x86_pc <= 8331ULL)
			__x86_pc = tetragon_bpf_generic_retuprobe_v61_generic_retuprobe_filter_arg_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 8334ULL && __x86_pc <= 9348ULL)
			__x86_pc = tetragon_bpf_generic_retuprobe_v61_generic_retuprobe_filter_arg_x86_chunk_6(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

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
extern char uprobe_calls;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_generic_uprobe_v61_generic_uprobe_filter_arg_x86_chunk_0(
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
	case 131ULL: goto x86_l_83;
	case 133ULL: goto x86_l_85;
	case 138ULL: goto x86_l_8a;
	case 142ULL: goto x86_l_8e;
	case 146ULL: goto x86_l_92;
	case 150ULL: goto x86_l_96;
	case 154ULL: goto x86_l_9a;
	case 159ULL: goto x86_l_9f;
	case 163ULL: goto x86_l_a3;
	case 166ULL: goto x86_l_a6;
	case 170ULL: goto x86_l_aa;
	case 172ULL: goto x86_l_ac;
	case 178ULL: goto x86_l_b2;
	case 182ULL: goto x86_l_b6;
	case 185ULL: goto x86_l_b9;
	case 187ULL: goto x86_l_bb;
	case 192ULL: goto x86_l_c0;
	case 196ULL: goto x86_l_c4;
	case 199ULL: goto x86_l_c7;
	case 201ULL: goto x86_l_c9;
	case 207ULL: goto x86_l_cf;
	case 211ULL: goto x86_l_d3;
	case 214ULL: goto x86_l_d6;
	case 216ULL: goto x86_l_d8;
	case 221ULL: goto x86_l_dd;
	case 225ULL: goto x86_l_e1;
	case 228ULL: goto x86_l_e4;
	case 230ULL: goto x86_l_e6;
	case 235ULL: goto x86_l_eb;
	case 239ULL: goto x86_l_ef;
	case 244ULL: goto x86_l_f4;
	case 246ULL: goto x86_l_f6;
	case 250ULL: goto x86_l_fa;
	case 254ULL: goto x86_l_fe;
	case 260ULL: goto x86_l_104;
	case 262ULL: goto x86_l_106;
	case 268ULL: goto x86_l_10c;
	case 272ULL: goto x86_l_110;
	case 274ULL: goto x86_l_112;
	case 278ULL: goto x86_l_116;
	case 284ULL: goto x86_l_11c;
	case 287ULL: goto x86_l_11f;
	case 293ULL: goto x86_l_125;
	case 297ULL: goto x86_l_129;
	case 303ULL: goto x86_l_12f;
	case 305ULL: goto x86_l_131;
	case 309ULL: goto x86_l_135;
	case 315ULL: goto x86_l_13b;
	case 319ULL: goto x86_l_13f;
	case 325ULL: goto x86_l_145;
	case 329ULL: goto x86_l_149;
	case 335ULL: goto x86_l_14f;
	case 339ULL: goto x86_l_153;
	case 345ULL: goto x86_l_159;
	case 348ULL: goto x86_l_15c;
	case 353ULL: goto x86_l_161;
	case 357ULL: goto x86_l_165;
	case 360ULL: goto x86_l_168;
	case 365ULL: goto x86_l_16d;
	case 371ULL: goto x86_l_173;
	case 376ULL: goto x86_l_178;
	case 380ULL: goto x86_l_17c;
	case 386ULL: goto x86_l_182;
	case 392ULL: goto x86_l_188;
	case 394ULL: goto x86_l_18a;
	case 400ULL: goto x86_l_190;
	case 405ULL: goto x86_l_195;
	case 408ULL: goto x86_l_198;
	case 414ULL: goto x86_l_19e;
	case 417ULL: goto x86_l_1a1;
	case 419ULL: goto x86_l_1a3;
	case 423ULL: goto x86_l_1a7;
	case 429ULL: goto x86_l_1ad;
	case 438ULL: goto x86_l_1b6;
	case 444ULL: goto x86_l_1bc;
	case 452ULL: goto x86_l_1c4;
	case 457ULL: goto x86_l_1c9;
	case 461ULL: goto x86_l_1cd;
	case 468ULL: goto x86_l_1d4;
	case 471ULL: goto x86_l_1d7;
	case 474ULL: goto x86_l_1da;
	case 476ULL: goto x86_l_1dc;
	case 479ULL: goto x86_l_1df;
	case 481ULL: goto x86_l_1e1;
	case 484ULL: goto x86_l_1e4;
	case 487ULL: goto x86_l_1e7;
	case 493ULL: goto x86_l_1ed;
	case 496ULL: goto x86_l_1f0;
	case 502ULL: goto x86_l_1f6;
	case 507ULL: goto x86_l_1fb;
	case 510ULL: goto x86_l_1fe;
	case 512ULL: goto x86_l_200;
	case 515ULL: goto x86_l_203;
	case 518ULL: goto x86_l_206;
	case 520ULL: goto x86_l_208;
	case 523ULL: goto x86_l_20b;
	case 526ULL: goto x86_l_20e;
	case 532ULL: goto x86_l_214;
	case 535ULL: goto x86_l_217;
	case 541ULL: goto x86_l_21d;
	case 545ULL: goto x86_l_221;
	case 550ULL: goto x86_l_226;
	case 555ULL: goto x86_l_22b;
	case 558ULL: goto x86_l_22e;
	case 564ULL: goto x86_l_234;
	case 567ULL: goto x86_l_237;
	case 570ULL: goto x86_l_23a;
	case 576ULL: goto x86_l_240;
	case 579ULL: goto x86_l_243;
	case 582ULL: goto x86_l_246;
	case 588ULL: goto x86_l_24c;
	case 593ULL: goto x86_l_251;
	case 596ULL: goto x86_l_254;
	case 602ULL: goto x86_l_25a;
	case 605ULL: goto x86_l_25d;
	case 607ULL: goto x86_l_25f;
	case 610ULL: goto x86_l_262;
	case 616ULL: goto x86_l_268;
	case 619ULL: goto x86_l_26b;
	case 625ULL: goto x86_l_271;
	case 628ULL: goto x86_l_274;
	case 630ULL: goto x86_l_276;
	case 633ULL: goto x86_l_279;
	case 639ULL: goto x86_l_27f;
	case 641ULL: goto x86_l_281;
	case 651ULL: goto x86_l_28b;
	case 655ULL: goto x86_l_28f;
	case 657ULL: goto x86_l_291;
	case 662ULL: goto x86_l_296;
	case 666ULL: goto x86_l_29a;
	case 672ULL: goto x86_l_2a0;
	case 682ULL: goto x86_l_2aa;
	case 686ULL: goto x86_l_2ae;
	case 692ULL: goto x86_l_2b4;
	case 697ULL: goto x86_l_2b9;
	case 702ULL: goto x86_l_2be;
	case 705ULL: goto x86_l_2c1;
	case 708ULL: goto x86_l_2c4;
	case 714ULL: goto x86_l_2ca;
	case 717ULL: goto x86_l_2cd;
	case 723ULL: goto x86_l_2d3;
	case 726ULL: goto x86_l_2d6;
	case 732ULL: goto x86_l_2dc;
	case 737ULL: goto x86_l_2e1;
	case 740ULL: goto x86_l_2e4;
	case 742ULL: goto x86_l_2e6;
	case 745ULL: goto x86_l_2e9;
	case 747ULL: goto x86_l_2eb;
	case 750ULL: goto x86_l_2ee;
	case 756ULL: goto x86_l_2f4;
	case 761ULL: goto x86_l_2f9;
	case 766ULL: goto x86_l_2fe;
	case 771ULL: goto x86_l_303;
	case 773ULL: goto x86_l_305;
	case 776ULL: goto x86_l_308;
	case 778ULL: goto x86_l_30a;
	case 781ULL: goto x86_l_30d;
	case 784ULL: goto x86_l_310;
	case 786ULL: goto x86_l_312;
	case 795ULL: goto x86_l_31b;
	case 801ULL: goto x86_l_321;
	case 804ULL: goto x86_l_324;
	case 812ULL: goto x86_l_32c;
	case 818ULL: goto x86_l_332;
	case 820ULL: goto x86_l_334;
	case 830ULL: goto x86_l_33e;
	case 833ULL: goto x86_l_341;
	case 835ULL: goto x86_l_343;
	case 838ULL: goto x86_l_346;
	case 840ULL: goto x86_l_348;
	case 843ULL: goto x86_l_34b;
	case 845ULL: goto x86_l_34d;
	case 850ULL: goto x86_l_352;
	case 852ULL: goto x86_l_354;
	case 857ULL: goto x86_l_359;
	case 859ULL: goto x86_l_35b;
	case 862ULL: goto x86_l_35e;
	case 865ULL: goto x86_l_361;
	case 867ULL: goto x86_l_363;
	case 872ULL: goto x86_l_368;
	case 874ULL: goto x86_l_36a;
	case 879ULL: goto x86_l_36f;
	case 881ULL: goto x86_l_371;
	case 886ULL: goto x86_l_376;
	case 891ULL: goto x86_l_37b;
	case 893ULL: goto x86_l_37d;
	case 896ULL: goto x86_l_380;
	case 898ULL: goto x86_l_382;
	case 903ULL: goto x86_l_387;
	case 906ULL: goto x86_l_38a;
	case 912ULL: goto x86_l_390;
	case 915ULL: goto x86_l_393;
	case 919ULL: goto x86_l_397;
	case 925ULL: goto x86_l_39d;
	case 930ULL: goto x86_l_3a2;
	case 934ULL: goto x86_l_3a6;
	case 941ULL: goto x86_l_3ad;
	case 948ULL: goto x86_l_3b4;
	case 953ULL: goto x86_l_3b9;
	case 958ULL: goto x86_l_3be;
	case 961ULL: goto x86_l_3c1;
	case 966ULL: goto x86_l_3c6;
	case 968ULL: goto x86_l_3c8;
	case 975ULL: goto x86_l_3cf;
	case 980ULL: goto x86_l_3d4;
	case 985ULL: goto x86_l_3d9;
	case 988ULL: goto x86_l_3dc;
	case 993ULL: goto x86_l_3e1;
	case 995ULL: goto x86_l_3e3;
	case 997ULL: goto x86_l_3e5;
	case 1001ULL: goto x86_l_3e9;
	case 1002ULL: goto x86_l_3ea;
	case 1004ULL: goto x86_l_3ec;
	case 1006ULL: goto x86_l_3ee;
	case 1008ULL: goto x86_l_3f0;
	case 1010ULL: goto x86_l_3f2;
	case 1011ULL: goto x86_l_3f3;
	case 1016ULL: goto x86_l_3f8;
	case 1019ULL: goto x86_l_3fb;
	case 1027ULL: goto x86_l_403;
	case 1029ULL: goto x86_l_405;
	case 1035ULL: goto x86_l_40b;
	case 1043ULL: goto x86_l_413;
	case 1045ULL: goto x86_l_415;
	case 1051ULL: goto x86_l_41b;
	case 1059ULL: goto x86_l_423;
	case 1061ULL: goto x86_l_425;
	case 1067ULL: goto x86_l_42b;
	case 1075ULL: goto x86_l_433;
	case 1077ULL: goto x86_l_435;
	case 1083ULL: goto x86_l_43b;
	case 1091ULL: goto x86_l_443;
	case 1093ULL: goto x86_l_445;
	case 1099ULL: goto x86_l_44b;
	case 1107ULL: goto x86_l_453;
	case 1109ULL: goto x86_l_455;
	case 1116ULL: goto x86_l_45c;
	case 1123ULL: goto x86_l_463;
	case 1128ULL: goto x86_l_468;
	case 1133ULL: goto x86_l_46d;
	case 1136ULL: goto x86_l_470;
	case 1141ULL: goto x86_l_475;
	case 1143ULL: goto x86_l_477;
	case 1147ULL: goto x86_l_47b;
	case 1152ULL: goto x86_l_480;
	case 1154ULL: goto x86_l_482;
	case 1159ULL: goto x86_l_487;
	case 1164ULL: goto x86_l_48c;
	case 1171ULL: goto x86_l_493;
	case 1176ULL: goto x86_l_498;
	case 1181ULL: goto x86_l_49d;
	case 1183ULL: goto x86_l_49f;
	case 1186ULL: goto x86_l_4a2;
	case 1192ULL: goto x86_l_4a8;
	case 1199ULL: goto x86_l_4af;
	case 1204ULL: goto x86_l_4b4;
	case 1209ULL: goto x86_l_4b9;
	case 1211ULL: goto x86_l_4bb;
	case 1216ULL: goto x86_l_4c0;
	case 1217ULL: goto x86_l_4c1;
	case 1220ULL: goto x86_l_4c4;
	case 1222ULL: goto x86_l_4c6;
	case 1225ULL: goto x86_l_4c9;
	case 1227ULL: goto x86_l_4cb;
	case 1229ULL: goto x86_l_4cd;
	case 1231ULL: goto x86_l_4cf;
	case 1234ULL: goto x86_l_4d2;
	case 1237ULL: goto x86_l_4d5;
	case 1239ULL: goto x86_l_4d7;
	case 1241ULL: goto x86_l_4d9;
	case 1242ULL: goto x86_l_4da;
	case 1243ULL: goto x86_l_4db;
	case 1246ULL: goto x86_l_4de;
	case 1248ULL: goto x86_l_4e0;
	case 1250ULL: goto x86_l_4e2;
	case 1255ULL: goto x86_l_4e7;
	case 1259ULL: goto x86_l_4eb;
	case 1261ULL: goto x86_l_4ed;
	case 1266ULL: goto x86_l_4f2;
	case 1270ULL: goto x86_l_4f6;
	case 1272ULL: goto x86_l_4f8;
	case 1282ULL: goto x86_l_502;
	case 1286ULL: goto x86_l_506;
	case 1288ULL: goto x86_l_508;
	case 1291ULL: goto x86_l_50b;
	case 1296ULL: goto x86_l_510;
	case 1299ULL: goto x86_l_513;
	case 1302ULL: goto x86_l_516;
	case 1304ULL: goto x86_l_518;
	case 1306ULL: goto x86_l_51a;
	case 1309ULL: goto x86_l_51d;
	case 1312ULL: goto x86_l_520;
	case 1314ULL: goto x86_l_522;
	case 1318ULL: goto x86_l_526;
	case 1321ULL: goto x86_l_529;
	case 1326ULL: goto x86_l_52e;
	case 1329ULL: goto x86_l_531;
	case 1332ULL: goto x86_l_534;
	case 1334ULL: goto x86_l_536;
	case 1336ULL: goto x86_l_538;
	case 1340ULL: goto x86_l_53c;
	case 1343ULL: goto x86_l_53f;
	case 1348ULL: goto x86_l_544;
	case 1351ULL: goto x86_l_547;
	case 1354ULL: goto x86_l_54a;
	case 1356ULL: goto x86_l_54c;
	case 1358ULL: goto x86_l_54e;
	case 1362ULL: goto x86_l_552;
	case 1365ULL: goto x86_l_555;
	case 1370ULL: goto x86_l_55a;
	case 1373ULL: goto x86_l_55d;
	case 1376ULL: goto x86_l_560;
	case 1378ULL: goto x86_l_562;
	case 1380ULL: goto x86_l_564;
	case 1382ULL: goto x86_l_566;
	case 1385ULL: goto x86_l_569;
	case 1387ULL: goto x86_l_56b;
	case 1389ULL: goto x86_l_56d;
	case 1399ULL: goto x86_l_577;
	case 1403ULL: goto x86_l_57b;
	case 1405ULL: goto x86_l_57d;
	case 1409ULL: goto x86_l_581;
	case 1410ULL: goto x86_l_582;
	case 1411ULL: goto x86_l_583;
	case 1412ULL: goto x86_l_584;
	case 1415ULL: goto x86_l_587;
	case 1417ULL: goto x86_l_589;
	case 1421ULL: goto x86_l_58d;
	case 1423ULL: goto x86_l_58f;
	case 1428ULL: goto x86_l_594;
	case 1432ULL: goto x86_l_598;
	case 1434ULL: goto x86_l_59a;
	case 1439ULL: goto x86_l_59f;
	case 1440ULL: goto x86_l_5a0;
	case 1441ULL: goto x86_l_5a1;
	case 1446ULL: goto x86_l_5a6;
	case 1450ULL: goto x86_l_5aa;
	case 1452ULL: goto x86_l_5ac;
	case 1462ULL: goto x86_l_5b6;
	case 1466ULL: goto x86_l_5ba;
	case 1468ULL: goto x86_l_5bc;
	case 1473ULL: goto x86_l_5c1;
	case 1474ULL: goto x86_l_5c2;
	case 1475ULL: goto x86_l_5c3;
	case 1480ULL: goto x86_l_5c8;
	case 1481ULL: goto x86_l_5c9;
	case 1482ULL: goto x86_l_5ca;
	case 1484ULL: goto x86_l_5cc;
	case 1486ULL: goto x86_l_5ce;
	case 1488ULL: goto x86_l_5d0;
	case 1489ULL: goto x86_l_5d1;
	case 1493ULL: goto x86_l_5d5;
	case 1502ULL: goto x86_l_5de;
	case 1511ULL: goto x86_l_5e7;
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
	/* 0x11: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_19:
	/* 0x19: mov    rdi,QWORD PTR [rip+0x5a40] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_20:
	/* 0x20: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
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
	/* 0x2f: je     3e3 <generic_uprobe_filter_arg+0x3e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e3;
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
	/* 0x46: mov    rdi,QWORD PTR [rip+0x5a40] */
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
	/* 0x57: je     3c8 <generic_uprobe_filter_arg+0x3c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c8;
	}
x86_l_5d:
	/* 0x5d: cmp    BYTE PTR [r14+0x5ee0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104316165685248ULL);
x86_l_65:
	/* 0x65: je     3c8 <generic_uprobe_filter_arg+0x3c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c8;
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
	/* 0x7d: je     10c <generic_uprobe_filter_arg+0x10c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10c;
	}
x86_l_83:
	/* 0x83: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_85:
	/* 0x85: mov    ecx,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_8a:
	/* 0x8a: lea    rdx,[rcx+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_8e:
	/* 0x8e: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_92:
	/* 0x92: lea    rax,[rcx+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_96:
	/* 0x96: add    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_9a:
	/* 0x9a: and    eax,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_9f:
	/* 0x9f: mov    eax,DWORD PTR [rax+r15*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_a3:
	/* 0xa3: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_a6:
	/* 0xa6: add    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_aa:
	/* 0xaa: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_ac:
	/* 0xac: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_b2:
	/* 0xb2: mov    ecx,DWORD PTR [rcx+r15*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_b6:
	/* 0xb6: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_b9:
	/* 0xb9: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_bb:
	/* 0xbb: and    eax,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_c0:
	/* 0xc0: mov    eax,DWORD PTR [rax+r15*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_c4:
	/* 0xc4: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_c7:
	/* 0xc7: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_c9:
	/* 0xc9: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_cf:
	/* 0xcf: mov    ecx,DWORD PTR [rcx+r15*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_d3:
	/* 0xd3: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_d6:
	/* 0xd6: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_d8:
	/* 0xd8: and    eax,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_dd:
	/* 0xdd: mov    ebp,DWORD PTR [rax+r15*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_e1:
	/* 0xe1: add    rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_e4:
	/* 0xe4: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_e6:
	/* 0xe6: and    eax,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_eb:
	/* 0xeb: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ef:
	/* 0xef: cmp    DWORD PTR [r15+rax*1],0x19 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 25ULL);
x86_l_f4:
	/* 0xf4: jae    161 <generic_uprobe_filter_arg+0x161> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_161;
	}
x86_l_f6:
	/* 0xf6: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fa:
	/* 0xfa: cmp    rax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 1ULL);
x86_l_fe:
	/* 0xfe: je     3c8 <generic_uprobe_filter_arg+0x3c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c8;
	}
x86_l_104:
	/* 0x104: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_106:
	/* 0x106: jne    3a2 <generic_uprobe_filter_arg+0x3a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3a2;
	}
x86_l_10c:
	/* 0x10c: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_110:
	/* 0x110: jg     131 <generic_uprobe_filter_arg+0x131> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_131;
	}
x86_l_112:
	/* 0x112: cmp    r12d,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4294967295ULL);
x86_l_116:
	/* 0x116: je     3f8 <generic_uprobe_filter_arg+0x3f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3f8;
	}
x86_l_11c:
	/* 0x11c: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_11f:
	/* 0x11f: je     405 <generic_uprobe_filter_arg+0x405> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_405;
	}
x86_l_125:
	/* 0x125: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_129:
	/* 0x129: je     415 <generic_uprobe_filter_arg+0x415> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_415;
	}
x86_l_12f:
	/* 0x12f: jmp    14f <generic_uprobe_filter_arg+0x14f> */
	goto x86_l_14f;
x86_l_131:
	/* 0x131: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_135:
	/* 0x135: je     425 <generic_uprobe_filter_arg+0x425> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_425;
	}
x86_l_13b:
	/* 0x13b: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_13f:
	/* 0x13f: je     435 <generic_uprobe_filter_arg+0x435> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_435;
	}
x86_l_145:
	/* 0x145: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_149:
	/* 0x149: je     445 <generic_uprobe_filter_arg+0x445> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_445;
	}
x86_l_14f:
	/* 0x14f: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_153:
	/* 0x153: jg     477 <generic_uprobe_filter_arg+0x477> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_477;
	}
x86_l_159:
	/* 0x159: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_15c:
	/* 0x15c: jmp    455 <generic_uprobe_filter_arg+0x455> */
	goto x86_l_455;
x86_l_161:
	/* 0x161: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_165:
	/* 0x165: add    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_168:
	/* 0x168: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16d:
	/* 0x16d: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_173:
	/* 0x173: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_178:
	/* 0x178: mov    edi,DWORD PTR [rax+r13*4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 0ULL);
x86_l_17c:
	/* 0x17c: test   edi,0x3ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDI, X86_WIDTH_32, 1023ULL);
x86_l_182:
	/* 0x182: je     f6 <generic_uprobe_filter_arg+0xf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f6;
	}
x86_l_188:
	/* 0x188: add    edi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_18a:
	/* 0x18a: and    edi,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_190:
	/* 0x190: mov    ecx,DWORD PTR [r15+rdi*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 0), 4ULL);
x86_l_195:
	/* 0x195: cmp    ecx,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 35ULL);
x86_l_198:
	/* 0x198: je     10c <generic_uprobe_filter_arg+0x10c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10c;
	}
x86_l_19e:
	/* 0x19e: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1a1:
	/* 0x1a1: mov    eax,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a3:
	/* 0x1a3: cmp    rax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4ULL);
x86_l_1a7:
	/* 0x1a7: ja     10c <generic_uprobe_filter_arg+0x10c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_10c;
	}
x86_l_1ad:
	/* 0x1ad: cmp    DWORD PTR [r14+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_1b6:
	/* 0x1b6: jne    10c <generic_uprobe_filter_arg+0x10c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_10c;
	}
x86_l_1bc:
	/* 0x1bc: mov    rax,QWORD PTR [r14+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_1c4:
	/* 0x1c4: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_1c9:
	/* 0x1c9: lea    rsi,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1cd:
	/* 0x1cd: add    rsi,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_1d4:
	/* 0x1d4: mov    eax,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1d7:
	/* 0x1d7: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_1da:
	/* 0x1da: jle    1fb <generic_uprobe_filter_arg+0x1fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1fb;
	}
x86_l_1dc:
	/* 0x1dc: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_1df:
	/* 0x1df: jg     22b <generic_uprobe_filter_arg+0x22b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_22b;
	}
x86_l_1e1:
	/* 0x1e1: lea    edx,[rax-0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551588ULL);
x86_l_1e4:
	/* 0x1e4: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_1e7:
	/* 0x1e7: jb     271 <generic_uprobe_filter_arg+0x271> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_271;
	}
x86_l_1ed:
	/* 0x1ed: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_1f0:
	/* 0x1f0: je     354 <generic_uprobe_filter_arg+0x354> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354;
	}
x86_l_1f6:
	/* 0x1f6: jmp    390 <generic_uprobe_filter_arg+0x390> */
	goto x86_l_390;
x86_l_1fb:
	/* 0x1fb: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_1fe:
	/* 0x1fe: jle    251 <generic_uprobe_filter_arg+0x251> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_251;
	}
x86_l_200:
	/* 0x200: lea    edx,[rax-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_203:
	/* 0x203: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_206:
	/* 0x206: jb     271 <generic_uprobe_filter_arg+0x271> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_271;
	}
x86_l_208:
	/* 0x208: lea    ecx,[rax-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_20b:
	/* 0x20b: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_20e:
	/* 0x20e: jb     354 <generic_uprobe_filter_arg+0x354> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_354;
	}
x86_l_214:
	/* 0x214: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_217:
	/* 0x217: jne    390 <generic_uprobe_filter_arg+0x390> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_390;
	}
x86_l_21d:
	/* 0x21d: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_221:
	/* 0x221: call   0 <generic_uprobe_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 550ULL);
	__x86_sim_call_depth++;
	goto x86_l_4c0;
x86_l_226:
	/* 0x226: jmp    387 <generic_uprobe_filter_arg+0x387> */
	goto x86_l_387;
x86_l_22b:
	/* 0x22b: cmp    eax,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 41ULL);
x86_l_22e:
	/* 0x22e: jg     343 <generic_uprobe_filter_arg+0x343> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_343;
	}
x86_l_234:
	/* 0x234: lea    ecx,[rax-0x26] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551578ULL);
x86_l_237:
	/* 0x237: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_23a:
	/* 0x23a: jb     2fe <generic_uprobe_filter_arg+0x2fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2fe;
	}
x86_l_240:
	/* 0x240: add    eax,0xffffffd8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4294967256ULL);
x86_l_243:
	/* 0x243: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_246:
	/* 0x246: jb     2f4 <generic_uprobe_filter_arg+0x2f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2f4;
	}
x86_l_24c:
	/* 0x24c: jmp    390 <generic_uprobe_filter_arg+0x390> */
	goto x86_l_390;
x86_l_251:
	/* 0x251: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_254:
	/* 0x254: jg     2e1 <generic_uprobe_filter_arg+0x2e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2e1;
	}
x86_l_25a:
	/* 0x25a: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_25d:
	/* 0x25d: je     271 <generic_uprobe_filter_arg+0x271> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_271;
	}
x86_l_25f:
	/* 0x25f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_262:
	/* 0x262: je     371 <generic_uprobe_filter_arg+0x371> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_371;
	}
x86_l_268:
	/* 0x268: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_26b:
	/* 0x26b: jne    390 <generic_uprobe_filter_arg+0x390> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_390;
	}
x86_l_271:
	/* 0x271: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_274:
	/* 0x274: jle    2be <generic_uprobe_filter_arg+0x2be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2be;
	}
x86_l_276:
	/* 0x276: cmp    eax,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 36ULL);
x86_l_279:
	/* 0x279: ja     35b <generic_uprobe_filter_arg+0x35b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_35b;
	}
x86_l_27f:
	/* 0x27f: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_281:
	/* 0x281: movabs r8,0x1e00000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_64, 128849018880ULL);
x86_l_28b:
	/* 0x28b: bt     r8,rdx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RDX, X86_WIDTH_64);
x86_l_28f:
	/* 0x28f: jb     305 <generic_uprobe_filter_arg+0x305> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_305;
	}
x86_l_291:
	/* 0x291: mov    ecx,0x60000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1610612736ULL);
x86_l_296:
	/* 0x296: bt     rcx,rdx */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_29a:
	/* 0x29a: jb     36a <generic_uprobe_filter_arg+0x36a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_36a;
	}
x86_l_2a0:
	/* 0x2a0: movabs rcx,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 6442450944ULL);
x86_l_2aa:
	/* 0x2aa: bt     rcx,rdx */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2ae:
	/* 0x2ae: jae    35b <generic_uprobe_filter_arg+0x35b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_35b;
	}
x86_l_2b4:
	/* 0x2b4: call   0 <generic_uprobe_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 697ULL);
	__x86_sim_call_depth++;
	goto x86_l_583;
x86_l_2b9:
	/* 0x2b9: jmp    387 <generic_uprobe_filter_arg+0x387> */
	goto x86_l_387;
x86_l_2be:
	/* 0x2be: lea    ecx,[rax-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_2c1:
	/* 0x2c1: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2c4:
	/* 0x2c4: jb     382 <generic_uprobe_filter_arg+0x382> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_382;
	}
x86_l_2ca:
	/* 0x2ca: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2cd:
	/* 0x2cd: je     363 <generic_uprobe_filter_arg+0x363> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_363;
	}
x86_l_2d3:
	/* 0x2d3: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d6:
	/* 0x2d6: je     363 <generic_uprobe_filter_arg+0x363> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_363;
	}
x86_l_2dc:
	/* 0x2dc: jmp    390 <generic_uprobe_filter_arg+0x390> */
	goto x86_l_390;
x86_l_2e1:
	/* 0x2e1: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_2e4:
	/* 0x2e4: je     2f4 <generic_uprobe_filter_arg+0x2f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f4;
	}
x86_l_2e6:
	/* 0x2e6: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_2e9:
	/* 0x2e9: je     2fe <generic_uprobe_filter_arg+0x2fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fe;
	}
x86_l_2eb:
	/* 0x2eb: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_2ee:
	/* 0x2ee: jne    390 <generic_uprobe_filter_arg+0x390> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_390;
	}
x86_l_2f4:
	/* 0x2f4: call   0 <generic_uprobe_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 761ULL);
	__x86_sim_call_depth++;
	goto x86_l_5ca;
x86_l_2f9:
	/* 0x2f9: jmp    387 <generic_uprobe_filter_arg+0x387> */
	goto x86_l_387;
x86_l_2fe:
	/* 0x2fe: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_303:
	/* 0x303: jmp    376 <generic_uprobe_filter_arg+0x376> */
	goto x86_l_376;
x86_l_305:
	/* 0x305: cmp    ecx,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 30ULL);
x86_l_308:
	/* 0x308: jne    382 <generic_uprobe_filter_arg+0x382> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_382;
	}
x86_l_30a:
	/* 0x30a: mov    eax,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_30d:
	/* 0x30d: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_310:
	/* 0x310: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_312:
	/* 0x312: cmp    DWORD PTR [r14+rcx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 104041287778304ULL);
x86_l_31b:
	/* 0x31b: jne    10c <generic_uprobe_filter_arg+0x10c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_10c;
	}
x86_l_321:
	/* 0x321: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_324:
	/* 0x324: mov    rdx,QWORD PTR [r14+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_32c:
	/* 0x32c: and    edx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_332:
	/* 0x332: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_334:
	/* 0x334: andn   rcx,rcx,QWORD PTR [r14+rdx*1+0x90] */
	X86_SIM_L_EXEC_ANDN_MEM(X86_RCX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RDX, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_R14)), 144ULL);
x86_l_33e:
	/* 0x33e: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_341:
	/* 0x341: jmp    387 <generic_uprobe_filter_arg+0x387> */
	goto x86_l_387;
x86_l_343:
	/* 0x343: cmp    eax,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 42ULL);
x86_l_346:
	/* 0x346: je     354 <generic_uprobe_filter_arg+0x354> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354;
	}
x86_l_348:
	/* 0x348: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_34b:
	/* 0x34b: jne    390 <generic_uprobe_filter_arg+0x390> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_390;
	}
x86_l_34d:
	/* 0x34d: call   0 <generic_uprobe_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 850ULL);
	__x86_sim_call_depth++;
	return 2315ULL;
x86_l_352:
	/* 0x352: jmp    387 <generic_uprobe_filter_arg+0x387> */
	goto x86_l_387;
x86_l_354:
	/* 0x354: call   0 <generic_uprobe_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 857ULL);
	__x86_sim_call_depth++;
	goto x86_l_4c0;
x86_l_359:
	/* 0x359: jmp    387 <generic_uprobe_filter_arg+0x387> */
	goto x86_l_387;
x86_l_35b:
	/* 0x35b: lea    ecx,[rax-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_35e:
	/* 0x35e: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_361:
	/* 0x361: jae    37d <generic_uprobe_filter_arg+0x37d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_37d;
	}
x86_l_363:
	/* 0x363: call   0 <generic_uprobe_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 872ULL);
	__x86_sim_call_depth++;
	return 2486ULL;
x86_l_368:
	/* 0x368: jmp    387 <generic_uprobe_filter_arg+0x387> */
	goto x86_l_387;
x86_l_36a:
	/* 0x36a: call   0 <generic_uprobe_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 879ULL);
	__x86_sim_call_depth++;
	return 2557ULL;
x86_l_36f:
	/* 0x36f: jmp    387 <generic_uprobe_filter_arg+0x387> */
	goto x86_l_387;
x86_l_371:
	/* 0x371: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_376:
	/* 0x376: call   0 <generic_uprobe_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 891ULL);
	__x86_sim_call_depth++;
	return 2628ULL;
x86_l_37b:
	/* 0x37b: jmp    387 <generic_uprobe_filter_arg+0x387> */
	goto x86_l_387;
x86_l_37d:
	/* 0x37d: cmp    eax,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_380:
	/* 0x380: jne    390 <generic_uprobe_filter_arg+0x390> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_390;
	}
x86_l_382:
	/* 0x382: call   0 <generic_uprobe_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 903ULL);
	__x86_sim_call_depth++;
	return 2791ULL;
x86_l_387:
	/* 0x387: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_38a:
	/* 0x38a: je     10c <generic_uprobe_filter_arg+0x10c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10c;
	}
x86_l_390:
	/* 0x390: inc    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_393:
	/* 0x393: cmp    r13,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 6ULL);
x86_l_397:
	/* 0x397: jne    173 <generic_uprobe_filter_arg+0x173> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_173;
	}
x86_l_39d:
	/* 0x39d: jmp    f6 <generic_uprobe_filter_arg+0xf6> */
	goto x86_l_f6;
x86_l_3a2:
	/* 0x3a2: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a6:
	/* 0x3a6: mov    DWORD PTR [r14+0x5f04],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24324ULL);
x86_l_3ad:
	/* 0x3ad: mov    rsi,QWORD PTR [rip+0x5a59] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&uprobe_calls)));
x86_l_3b4:
	/* 0x3b4: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3b9:
	/* 0x3b9: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_3be:
	/* 0x3be: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3c1:
	/* 0x3c1: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_3c6:
	/* 0x3c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c8:
	/* 0x3c8: mov    rsi,QWORD PTR [rip+0x5a59] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&uprobe_calls)));
x86_l_3cf:
	/* 0x3cf: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_3d4:
	/* 0x3d4: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_3d9:
	/* 0x3d9: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3dc:
	/* 0x3dc: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_3e1:
	/* 0x3e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e3:
	/* 0x3e3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3e5:
	/* 0x3e5: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_3e9:
	/* 0x3e9: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_3ea:
	/* 0x3ea: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_3ec:
	/* 0x3ec: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_3ee:
	/* 0x3ee: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_3f0:
	/* 0x3f0: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_3f2:
	/* 0x3f2: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_3f3:
	/* 0x3f3: jmp    24e1 <filter_file_type+0xa4> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_3f8:
	/* 0x3f8: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3fb:
	/* 0x3fb: cmp    BYTE PTR [r14+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104183021699072ULL);
x86_l_403:
	/* 0x403: jne    455 <generic_uprobe_filter_arg+0x455> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_455;
	}
x86_l_405:
	/* 0x405: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_40b:
	/* 0x40b: cmp    BYTE PTR [r14+0x5ec2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104187316666368ULL);
x86_l_413:
	/* 0x413: jne    455 <generic_uprobe_filter_arg+0x455> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_455;
	}
x86_l_415:
	/* 0x415: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_41b:
	/* 0x41b: cmp    BYTE PTR [r14+0x5ec3],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104191611633664ULL);
x86_l_423:
	/* 0x423: jne    455 <generic_uprobe_filter_arg+0x455> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_455;
	}
x86_l_425:
	/* 0x425: mov    r12d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 3ULL);
x86_l_42b:
	/* 0x42b: cmp    BYTE PTR [r14+0x5ec4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104195906600960ULL);
x86_l_433:
	/* 0x433: jne    455 <generic_uprobe_filter_arg+0x455> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_455;
	}
x86_l_435:
	/* 0x435: mov    r12d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4ULL);
x86_l_43b:
	/* 0x43b: cmp    BYTE PTR [r14+0x5ec5],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104200201568256ULL);
x86_l_443:
	/* 0x443: jne    455 <generic_uprobe_filter_arg+0x455> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_455;
	}
x86_l_445:
	/* 0x445: mov    r12d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 5ULL);
x86_l_44b:
	/* 0x44b: cmp    BYTE PTR [r14+0x5ec6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104204496535552ULL);
x86_l_453:
	/* 0x453: je     477 <generic_uprobe_filter_arg+0x477> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_477;
	}
x86_l_455:
	/* 0x455: mov    DWORD PTR [r14+0x5f00],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24320ULL);
x86_l_45c:
	/* 0x45c: mov    rsi,QWORD PTR [rip+0x5a55] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&uprobe_calls)));
x86_l_463:
	/* 0x463: mov    ecx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_468:
	/* 0x468: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_46d:
	/* 0x46d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_470:
	/* 0x470: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_475:
	/* 0x475: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_477:
	/* 0x477: mov    rbx,QWORD PTR [r14+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_47b:
	/* 0x47b: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_480:
	/* 0x480: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_482:
	/* 0x482: mov    QWORD PTR [rsp+0x18],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_487:
	/* 0x487: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_48c:
	/* 0x48c: mov    rdi,QWORD PTR [rip+0x5a55] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_493:
	/* 0x493: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_498:
	/* 0x498: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_49d:
	/* 0x49d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49f:
	/* 0x49f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4a2:
	/* 0x4a2: je     3e3 <generic_uprobe_filter_arg+0x3e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e3;
	}
x86_l_4a8:
	/* 0x4a8: mov    rdi,QWORD PTR [rip+0x5a55] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_4af:
	/* 0x4af: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4b4:
	/* 0x4b4: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_4b9:
	/* 0x4b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4bb:
	/* 0x4bb: jmp    3e3 <generic_uprobe_filter_arg+0x3e3> */
	goto x86_l_3e3;
x86_l_4c0:
	/* 0x4c0: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_4c1:
	/* 0x4c1: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_4c4:
	/* 0x4c4: mov    edx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c6:
	/* 0x4c6: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4c9:
	/* 0x4c9: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_4cb:
	/* 0x4cb: jne    4db <filter_file_buf+0x1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4db;
	}
x86_l_4cd:
	/* 0x4cd: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_4cf:
	/* 0x4cf: and    eax,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_4d2:
	/* 0x4d2: cmp    eax,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 36ULL);
x86_l_4d5:
	/* 0x4d5: je     4db <filter_file_buf+0x1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4db;
	}
x86_l_4d7:
	/* 0x4d7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4d9:
	/* 0x4d9: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_4da:
	/* 0x4da: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_4db:
	/* 0x4db: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_4de:
	/* 0x4de: ja     51a <filter_file_buf+0x5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_51a;
	}
x86_l_4e0:
	/* 0x4e0: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_4e2:
	/* 0x4e2: mov    edi,0x4000100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 67109120ULL);
x86_l_4e7:
	/* 0x4e7: bt     rdi,rax */
	X86_SIM_L_EXEC_BT(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_4eb:
	/* 0x4eb: jb     54e <filter_file_buf+0x8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_54e;
	}
x86_l_4ed:
	/* 0x4ed: mov    edi,0x8000200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 134218240ULL);
x86_l_4f2:
	/* 0x4f2: bt     rdi,rax */
	X86_SIM_L_EXEC_BT(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_4f6:
	/* 0x4f6: jb     538 <filter_file_buf+0x78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_538;
	}
x86_l_4f8:
	/* 0x4f8: movabs rdi,0x3000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_64, 206158430208ULL);
x86_l_502:
	/* 0x502: bt     rdi,rax */
	X86_SIM_L_EXEC_BT(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_506:
	/* 0x506: jae    51a <filter_file_buf+0x5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_51a;
	}
x86_l_508:
	/* 0x508: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_50b:
	/* 0x50b: call   243d <filter_file_type> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 1296ULL);
	__x86_sim_call_depth++;
	return 9277ULL;
x86_l_510:
	/* 0x510: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_513:
	/* 0x513: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_516:
	/* 0x516: jbe    56b <filter_file_buf+0xab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_56b;
	}
x86_l_518:
	/* 0x518: jmp    581 <filter_file_buf+0xc1> */
	goto x86_l_581;
x86_l_51a:
	/* 0x51a: lea    eax,[rcx-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_51d:
	/* 0x51d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_520:
	/* 0x520: jae    564 <filter_file_buf+0xa4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_564;
	}
x86_l_522:
	/* 0x522: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_526:
	/* 0x526: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_529:
	/* 0x529: call   119b <filter_char_buf_equal> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 1326ULL);
	__x86_sim_call_depth++;
	return 4507ULL;
x86_l_52e:
	/* 0x52e: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_531:
	/* 0x531: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_534:
	/* 0x534: jbe    56b <filter_file_buf+0xab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_56b;
	}
x86_l_536:
	/* 0x536: jmp    581 <filter_file_buf+0xc1> */
	goto x86_l_581;
x86_l_538:
	/* 0x538: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_53c:
	/* 0x53c: mov    edi,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_53f:
	/* 0x53f: call   fb3 <filter_char_buf_postfix> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 1348ULL);
	__x86_sim_call_depth++;
	return 4019ULL;
x86_l_544:
	/* 0x544: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_547:
	/* 0x547: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_54a:
	/* 0x54a: jbe    56b <filter_file_buf+0xab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_56b;
	}
x86_l_54c:
	/* 0x54c: jmp    581 <filter_file_buf+0xc1> */
	goto x86_l_581;
x86_l_54e:
	/* 0x54e: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_552:
	/* 0x552: mov    edi,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_555:
	/* 0x555: call   10fb <filter_char_buf_prefix> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 1370ULL);
	__x86_sim_call_depth++;
	return 4347ULL;
x86_l_55a:
	/* 0x55a: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_55d:
	/* 0x55d: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_560:
	/* 0x560: jbe    56b <filter_file_buf+0xab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_56b;
	}
x86_l_562:
	/* 0x562: jmp    581 <filter_file_buf+0xc1> */
	goto x86_l_581;
x86_l_564:
	/* 0x564: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_566:
	/* 0x566: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_569:
	/* 0x569: ja     581 <filter_file_buf+0xc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_581;
	}
x86_l_56b:
	/* 0x56b: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_56d:
	/* 0x56d: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_577:
	/* 0x577: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_57b:
	/* 0x57b: jae    581 <filter_file_buf+0xc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_581;
	}
x86_l_57d:
	/* 0x57d: xor    rax,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 1ULL);
x86_l_581:
	/* 0x581: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_582:
	/* 0x582: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_583:
	/* 0x583: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_584:
	/* 0x584: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_587:
	/* 0x587: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_589:
	/* 0x589: cmp    rcx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 32ULL);
x86_l_58d:
	/* 0x58d: ja     5c8 <filter_8ty+0x45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_5c8;
	}
x86_l_58f:
	/* 0x58f: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_594:
	/* 0x594: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_598:
	/* 0x598: jae    5a1 <filter_8ty+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_5a1;
	}
x86_l_59a:
	/* 0x59a: call   1fe5 <filter_8ty_selector_val> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 1439ULL);
	__x86_sim_call_depth++;
	return 8165ULL;
x86_l_59f:
	/* 0x59f: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_5a0:
	/* 0x5a0: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_5a1:
	/* 0x5a1: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_5a6:
	/* 0x5a6: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_5aa:
	/* 0x5aa: jb     5c3 <filter_8ty+0x40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_5c3;
	}
x86_l_5ac:
	/* 0x5ac: movabs rdx,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 6442450944ULL);
x86_l_5b6:
	/* 0x5b6: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_5ba:
	/* 0x5ba: jae    5c8 <filter_8ty+0x45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_5c8;
	}
x86_l_5bc:
	/* 0x5bc: call   21ff <filter_8ty_range> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 1473ULL);
	__x86_sim_call_depth++;
	return 8703ULL;
x86_l_5c1:
	/* 0x5c1: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_5c2:
	/* 0x5c2: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_5c3:
	/* 0x5c3: call   23b7 <filter_8ty_map> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 1480ULL);
	__x86_sim_call_depth++;
	return 9143ULL;
x86_l_5c8:
	/* 0x5c8: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_5c9:
	/* 0x5c9: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_5ca:
	/* 0x5ca: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_5cc:
	/* 0x5cc: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_5ce:
	/* 0x5ce: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_5d0:
	/* 0x5d0: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_5d1:
	/* 0x5d1: sub    rsp,0x48 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 72ULL);
x86_l_5d5:
	/* 0x5d5: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_5de:
	/* 0x5de: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_5e7:
	/* 0x5e7: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
	return 1520ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v61_generic_uprobe_filter_arg_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1520ULL: goto x86_l_5f0;
	case 1529ULL: goto x86_l_5f9;
	case 1538ULL: goto x86_l_602;
	case 1545ULL: goto x86_l_609;
	case 1553ULL: goto x86_l_611;
	case 1556ULL: goto x86_l_614;
	case 1558ULL: goto x86_l_616;
	case 1561ULL: goto x86_l_619;
	case 1563ULL: goto x86_l_61b;
	case 1566ULL: goto x86_l_61e;
	case 1572ULL: goto x86_l_624;
	case 1575ULL: goto x86_l_627;
	case 1578ULL: goto x86_l_62a;
	case 1580ULL: goto x86_l_62c;
	case 1585ULL: goto x86_l_631;
	case 1588ULL: goto x86_l_634;
	case 1590ULL: goto x86_l_636;
	case 1593ULL: goto x86_l_639;
	case 1596ULL: goto x86_l_63c;
	case 1602ULL: goto x86_l_642;
	case 1605ULL: goto x86_l_645;
	case 1607ULL: goto x86_l_647;
	case 1610ULL: goto x86_l_64a;
	case 1612ULL: goto x86_l_64c;
	case 1615ULL: goto x86_l_64f;
	case 1617ULL: goto x86_l_651;
	case 1620ULL: goto x86_l_654;
	case 1623ULL: goto x86_l_657;
	case 1629ULL: goto x86_l_65d;
	case 1632ULL: goto x86_l_660;
	case 1635ULL: goto x86_l_663;
	case 1641ULL: goto x86_l_669;
	case 1646ULL: goto x86_l_66e;
	case 1649ULL: goto x86_l_671;
	case 1655ULL: goto x86_l_677;
	case 1658ULL: goto x86_l_67a;
	case 1664ULL: goto x86_l_680;
	case 1667ULL: goto x86_l_683;
	case 1673ULL: goto x86_l_689;
	case 1678ULL: goto x86_l_68e;
	case 1681ULL: goto x86_l_691;
	case 1686ULL: goto x86_l_696;
	case 1690ULL: goto x86_l_69a;
	case 1695ULL: goto x86_l_69f;
	case 1699ULL: goto x86_l_6a3;
	case 1704ULL: goto x86_l_6a8;
	case 1708ULL: goto x86_l_6ac;
	case 1713ULL: goto x86_l_6b1;
	case 1718ULL: goto x86_l_6b6;
	case 1721ULL: goto x86_l_6b9;
	case 1724ULL: goto x86_l_6bc;
	case 1726ULL: goto x86_l_6be;
	case 1729ULL: goto x86_l_6c1;
	case 1731ULL: goto x86_l_6c3;
	case 1734ULL: goto x86_l_6c6;
	case 1736ULL: goto x86_l_6c8;
	case 1739ULL: goto x86_l_6cb;
	case 1741ULL: goto x86_l_6cd;
	case 1744ULL: goto x86_l_6d0;
	case 1746ULL: goto x86_l_6d2;
	case 1749ULL: goto x86_l_6d5;
	case 1755ULL: goto x86_l_6db;
	case 1759ULL: goto x86_l_6df;
	case 1764ULL: goto x86_l_6e4;
	case 1767ULL: goto x86_l_6e7;
	case 1773ULL: goto x86_l_6ed;
	case 1776ULL: goto x86_l_6f0;
	case 1782ULL: goto x86_l_6f6;
	case 1785ULL: goto x86_l_6f9;
	case 1787ULL: goto x86_l_6fb;
	case 1792ULL: goto x86_l_700;
	case 1795ULL: goto x86_l_703;
	case 1797ULL: goto x86_l_705;
	case 1800ULL: goto x86_l_708;
	case 1806ULL: goto x86_l_70e;
	case 1810ULL: goto x86_l_712;
	case 1812ULL: goto x86_l_714;
	case 1816ULL: goto x86_l_718;
	case 1820ULL: goto x86_l_71c;
	case 1822ULL: goto x86_l_71e;
	case 1825ULL: goto x86_l_721;
	case 1828ULL: goto x86_l_724;
	case 1830ULL: goto x86_l_726;
	case 1833ULL: goto x86_l_729;
	case 1835ULL: goto x86_l_72b;
	case 1838ULL: goto x86_l_72e;
	case 1841ULL: goto x86_l_731;
	case 1847ULL: goto x86_l_737;
	case 1850ULL: goto x86_l_73a;
	case 1853ULL: goto x86_l_73d;
	case 1859ULL: goto x86_l_743;
	case 1862ULL: goto x86_l_746;
	case 1868ULL: goto x86_l_74c;
	case 1873ULL: goto x86_l_751;
	case 1876ULL: goto x86_l_754;
	case 1882ULL: goto x86_l_75a;
	case 1885ULL: goto x86_l_75d;
	case 1891ULL: goto x86_l_763;
	case 1894ULL: goto x86_l_766;
	case 1900ULL: goto x86_l_76c;
	case 1903ULL: goto x86_l_76f;
	case 1909ULL: goto x86_l_775;
	case 1914ULL: goto x86_l_77a;
	case 1918ULL: goto x86_l_77e;
	case 1922ULL: goto x86_l_782;
	case 1924ULL: goto x86_l_784;
	case 1927ULL: goto x86_l_787;
	case 1931ULL: goto x86_l_78b;
	case 1934ULL: goto x86_l_78e;
	case 1938ULL: goto x86_l_792;
	case 1940ULL: goto x86_l_794;
	case 1942ULL: goto x86_l_796;
	case 1945ULL: goto x86_l_799;
	case 1947ULL: goto x86_l_79b;
	case 1950ULL: goto x86_l_79e;
	case 1952ULL: goto x86_l_7a0;
	case 1958ULL: goto x86_l_7a6;
	case 1962ULL: goto x86_l_7aa;
	case 1964ULL: goto x86_l_7ac;
	case 1970ULL: goto x86_l_7b2;
	case 1974ULL: goto x86_l_7b6;
	case 1976ULL: goto x86_l_7b8;
	case 1981ULL: goto x86_l_7bd;
	case 1984ULL: goto x86_l_7c0;
	case 1986ULL: goto x86_l_7c2;
	case 1990ULL: goto x86_l_7c6;
	case 1993ULL: goto x86_l_7c9;
	case 1995ULL: goto x86_l_7cb;
	case 1998ULL: goto x86_l_7ce;
	case 2004ULL: goto x86_l_7d4;
	case 2007ULL: goto x86_l_7d7;
	case 2010ULL: goto x86_l_7da;
	case 2014ULL: goto x86_l_7de;
	case 2021ULL: goto x86_l_7e5;
	case 2026ULL: goto x86_l_7ea;
	case 2031ULL: goto x86_l_7ef;
	case 2033ULL: goto x86_l_7f1;
	case 2036ULL: goto x86_l_7f4;
	case 2042ULL: goto x86_l_7fa;
	case 2045ULL: goto x86_l_7fd;
	case 2053ULL: goto x86_l_805;
	case 2057ULL: goto x86_l_809;
	case 2059ULL: goto x86_l_80b;
	case 2062ULL: goto x86_l_80e;
	case 2065ULL: goto x86_l_811;
	case 2071ULL: goto x86_l_817;
	case 2076ULL: goto x86_l_81c;
	case 2081ULL: goto x86_l_821;
	case 2083ULL: goto x86_l_823;
	case 2089ULL: goto x86_l_829;
	case 2092ULL: goto x86_l_82c;
	case 2097ULL: goto x86_l_831;
	case 2099ULL: goto x86_l_833;
	case 2105ULL: goto x86_l_839;
	case 2108ULL: goto x86_l_83c;
	case 2113ULL: goto x86_l_841;
	case 2116ULL: goto x86_l_844;
	case 2119ULL: goto x86_l_847;
	case 2123ULL: goto x86_l_84b;
	case 2130ULL: goto x86_l_852;
	case 2135ULL: goto x86_l_857;
	case 2140ULL: goto x86_l_85c;
	case 2142ULL: goto x86_l_85e;
	case 2145ULL: goto x86_l_861;
	case 2147ULL: goto x86_l_863;
	case 2150ULL: goto x86_l_866;
	case 2158ULL: goto x86_l_86e;
	case 2162ULL: goto x86_l_872;
	case 2167ULL: goto x86_l_877;
	case 2172ULL: goto x86_l_87c;
	case 2176ULL: goto x86_l_880;
	case 2181ULL: goto x86_l_885;
	case 2186ULL: goto x86_l_88a;
	case 2191ULL: goto x86_l_88f;
	case 2193ULL: goto x86_l_891;
	case 2198ULL: goto x86_l_896;
	case 2201ULL: goto x86_l_899;
	case 2204ULL: goto x86_l_89c;
	case 2206ULL: goto x86_l_89e;
	case 2209ULL: goto x86_l_8a1;
	case 2212ULL: goto x86_l_8a4;
	case 2214ULL: goto x86_l_8a6;
	case 2217ULL: goto x86_l_8a9;
	case 2220ULL: goto x86_l_8ac;
	case 2223ULL: goto x86_l_8af;
	case 2225ULL: goto x86_l_8b1;
	case 2227ULL: goto x86_l_8b3;
	case 2230ULL: goto x86_l_8b6;
	case 2232ULL: goto x86_l_8b8;
	case 2236ULL: goto x86_l_8bc;
	case 2239ULL: goto x86_l_8bf;
	case 2242ULL: goto x86_l_8c2;
	case 2247ULL: goto x86_l_8c7;
	case 2251ULL: goto x86_l_8cb;
	case 2252ULL: goto x86_l_8cc;
	case 2254ULL: goto x86_l_8ce;
	case 2256ULL: goto x86_l_8d0;
	case 2258ULL: goto x86_l_8d2;
	case 2259ULL: goto x86_l_8d3;
	case 2264ULL: goto x86_l_8d8;
	case 2267ULL: goto x86_l_8db;
	case 2270ULL: goto x86_l_8de;
	case 2272ULL: goto x86_l_8e0;
	case 2275ULL: goto x86_l_8e3;
	case 2278ULL: goto x86_l_8e6;
	case 2281ULL: goto x86_l_8e9;
	case 2283ULL: goto x86_l_8eb;
	case 2286ULL: goto x86_l_8ee;
	case 2288ULL: goto x86_l_8f0;
	case 2291ULL: goto x86_l_8f3;
	case 2293ULL: goto x86_l_8f5;
	case 2298ULL: goto x86_l_8fa;
	case 2301ULL: goto x86_l_8fd;
	case 2304ULL: goto x86_l_900;
	case 2306ULL: goto x86_l_902;
	case 2309ULL: goto x86_l_905;
	case 2311ULL: goto x86_l_907;
	case 2313ULL: goto x86_l_909;
	case 2315ULL: goto x86_l_90b;
	case 2316ULL: goto x86_l_90c;
	case 2320ULL: goto x86_l_910;
	case 2323ULL: goto x86_l_913;
	case 2327ULL: goto x86_l_917;
	case 2331ULL: goto x86_l_91b;
	case 2335ULL: goto x86_l_91f;
	case 2337ULL: goto x86_l_921;
	case 2341ULL: goto x86_l_925;
	case 2343ULL: goto x86_l_927;
	case 2347ULL: goto x86_l_92b;
	case 2350ULL: goto x86_l_92e;
	case 2352ULL: goto x86_l_930;
	case 2355ULL: goto x86_l_933;
	case 2360ULL: goto x86_l_938;
	case 2363ULL: goto x86_l_93b;
	case 2367ULL: goto x86_l_93f;
	case 2369ULL: goto x86_l_941;
	case 2379ULL: goto x86_l_94b;
	case 2383ULL: goto x86_l_94f;
	case 2385ULL: goto x86_l_951;
	case 2389ULL: goto x86_l_955;
	case 2393ULL: goto x86_l_959;
	case 2394ULL: goto x86_l_95a;
	case 2395ULL: goto x86_l_95b;
	case 2399ULL: goto x86_l_95f;
	case 2401ULL: goto x86_l_961;
	case 2405ULL: goto x86_l_965;
	case 2407ULL: goto x86_l_967;
	case 2409ULL: goto x86_l_969;
	case 2413ULL: goto x86_l_96d;
	case 2415ULL: goto x86_l_96f;
	case 2418ULL: goto x86_l_972;
	case 2421ULL: goto x86_l_975;
	case 2423ULL: goto x86_l_977;
	case 2428ULL: goto x86_l_97c;
	case 2431ULL: goto x86_l_97f;
	case 2435ULL: goto x86_l_983;
	case 2437ULL: goto x86_l_985;
	case 2447ULL: goto x86_l_98f;
	case 2451ULL: goto x86_l_993;
	case 2453ULL: goto x86_l_995;
	case 2457ULL: goto x86_l_999;
	case 2461ULL: goto x86_l_99d;
	case 2462ULL: goto x86_l_99e;
	case 2463ULL: goto x86_l_99f;
	case 2466ULL: goto x86_l_9a2;
	case 2470ULL: goto x86_l_9a6;
	case 2475ULL: goto x86_l_9ab;
	case 2480ULL: goto x86_l_9b0;
	case 2484ULL: goto x86_l_9b4;
	case 2485ULL: goto x86_l_9b5;
	case 2486ULL: goto x86_l_9b6;
	case 2487ULL: goto x86_l_9b7;
	case 2490ULL: goto x86_l_9ba;
	case 2492ULL: goto x86_l_9bc;
	case 2496ULL: goto x86_l_9c0;
	case 2498ULL: goto x86_l_9c2;
	case 2503ULL: goto x86_l_9c7;
	case 2507ULL: goto x86_l_9cb;
	case 2509ULL: goto x86_l_9cd;
	case 2514ULL: goto x86_l_9d2;
	case 2515ULL: goto x86_l_9d3;
	case 2516ULL: goto x86_l_9d4;
	case 2521ULL: goto x86_l_9d9;
	case 2525ULL: goto x86_l_9dd;
	case 2527ULL: goto x86_l_9df;
	case 2537ULL: goto x86_l_9e9;
	case 2541ULL: goto x86_l_9ed;
	case 2543ULL: goto x86_l_9ef;
	case 2548ULL: goto x86_l_9f4;
	case 2549ULL: goto x86_l_9f5;
	case 2550ULL: goto x86_l_9f6;
	case 2555ULL: goto x86_l_9fb;
	case 2556ULL: goto x86_l_9fc;
	case 2557ULL: goto x86_l_9fd;
	case 2558ULL: goto x86_l_9fe;
	case 2561ULL: goto x86_l_a01;
	case 2563ULL: goto x86_l_a03;
	case 2567ULL: goto x86_l_a07;
	case 2569ULL: goto x86_l_a09;
	case 2574ULL: goto x86_l_a0e;
	case 2578ULL: goto x86_l_a12;
	case 2580ULL: goto x86_l_a14;
	case 2585ULL: goto x86_l_a19;
	case 2586ULL: goto x86_l_a1a;
	case 2587ULL: goto x86_l_a1b;
	case 2592ULL: goto x86_l_a20;
	case 2596ULL: goto x86_l_a24;
	case 2598ULL: goto x86_l_a26;
	case 2608ULL: goto x86_l_a30;
	case 2612ULL: goto x86_l_a34;
	case 2614ULL: goto x86_l_a36;
	case 2619ULL: goto x86_l_a3b;
	case 2620ULL: goto x86_l_a3c;
	case 2621ULL: goto x86_l_a3d;
	case 2626ULL: goto x86_l_a42;
	case 2627ULL: goto x86_l_a43;
	case 2628ULL: goto x86_l_a44;
	case 2629ULL: goto x86_l_a45;
	case 2632ULL: goto x86_l_a48;
	case 2635ULL: goto x86_l_a4b;
	case 2638ULL: goto x86_l_a4e;
	case 2642ULL: goto x86_l_a52;
	case 2644ULL: goto x86_l_a54;
	case 2647ULL: goto x86_l_a57;
	case 2650ULL: goto x86_l_a5a;
	case 2652ULL: goto x86_l_a5c;
	case 2655ULL: goto x86_l_a5f;
	case 2657ULL: goto x86_l_a61;
	case 2660ULL: goto x86_l_a64;
	case 2663ULL: goto x86_l_a67;
	case 2665ULL: goto x86_l_a69;
	case 2668ULL: goto x86_l_a6c;
	case 2670ULL: goto x86_l_a6e;
	case 2673ULL: goto x86_l_a71;
	case 2675ULL: goto x86_l_a73;
	case 2677ULL: goto x86_l_a75;
	case 2680ULL: goto x86_l_a78;
	case 2682ULL: goto x86_l_a7a;
	case 2685ULL: goto x86_l_a7d;
	case 2687ULL: goto x86_l_a7f;
	case 2690ULL: goto x86_l_a82;
	case 2692ULL: goto x86_l_a84;
	case 2695ULL: goto x86_l_a87;
	case 2700ULL: goto x86_l_a8c;
	case 2702ULL: goto x86_l_a8e;
	case 2705ULL: goto x86_l_a91;
	case 2707ULL: goto x86_l_a93;
	case 2710ULL: goto x86_l_a96;
	case 2712ULL: goto x86_l_a98;
	case 2715ULL: goto x86_l_a9b;
	case 2720ULL: goto x86_l_aa0;
	case 2722ULL: goto x86_l_aa2;
	case 2725ULL: goto x86_l_aa5;
	case 2730ULL: goto x86_l_aaa;
	case 2732ULL: goto x86_l_aac;
	case 2735ULL: goto x86_l_aaf;
	case 2740ULL: goto x86_l_ab4;
	case 2742ULL: goto x86_l_ab6;
	case 2745ULL: goto x86_l_ab9;
	case 2747ULL: goto x86_l_abb;
	case 2752ULL: goto x86_l_ac0;
	case 2755ULL: goto x86_l_ac3;
	case 2758ULL: goto x86_l_ac6;
	case 2760ULL: goto x86_l_ac8;
	case 2762ULL: goto x86_l_aca;
	case 2772ULL: goto x86_l_ad4;
	case 2776ULL: goto x86_l_ad8;
	case 2778ULL: goto x86_l_ada;
	case 2780ULL: goto x86_l_adc;
	case 2783ULL: goto x86_l_adf;
	case 2786ULL: goto x86_l_ae2;
	case 2789ULL: goto x86_l_ae5;
	case 2790ULL: goto x86_l_ae6;
	case 2791ULL: goto x86_l_ae7;
	case 2792ULL: goto x86_l_ae8;
	case 2795ULL: goto x86_l_aeb;
	case 2797ULL: goto x86_l_aed;
	case 2801ULL: goto x86_l_af1;
	case 2803ULL: goto x86_l_af3;
	case 2808ULL: goto x86_l_af8;
	case 2812ULL: goto x86_l_afc;
	case 2814ULL: goto x86_l_afe;
	case 2819ULL: goto x86_l_b03;
	case 2820ULL: goto x86_l_b04;
	default: return 0xffffffffffffffffULL;
	}
x86_l_5f0:
	/* 0x5f0: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_5f9:
	/* 0x5f9: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_602:
	/* 0x602: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_609:
	/* 0x609: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_611:
	/* 0x611: mov    edx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_614:
	/* 0x614: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_616:
	/* 0x616: cmp    edx,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 39ULL);
x86_l_619:
	/* 0x619: jg     631 <filter_inet+0x67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_631;
	}
x86_l_61b:
	/* 0x61b: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_61e:
	/* 0x61e: je     6b6 <filter_inet+0xec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6b6;
	}
x86_l_624:
	/* 0x624: mov    r8,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_64);
x86_l_627:
	/* 0x627: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_62a:
	/* 0x62a: je     642 <filter_inet+0x78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_642;
	}
x86_l_62c:
	/* 0x62c: jmp    8c7 <filter_inet+0x2fd> */
	goto x86_l_8c7;
x86_l_631:
	/* 0x631: cmp    edx,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 40ULL);
x86_l_634:
	/* 0x634: je     68e <filter_inet+0xc4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_68e;
	}
x86_l_636:
	/* 0x636: mov    r8,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_64);
x86_l_639:
	/* 0x639: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_63c:
	/* 0x63c: jne    8c7 <filter_inet+0x2fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8c7;
	}
x86_l_642:
	/* 0x642: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_645:
	/* 0x645: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_647:
	/* 0x647: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_64a:
	/* 0x64a: jle    6c3 <filter_inet+0xf9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_6c3;
	}
x86_l_64c:
	/* 0x64c: cmp    ecx,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 23ULL);
x86_l_64f:
	/* 0x64f: jg     66e <filter_inet+0xa4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_66e;
	}
x86_l_651:
	/* 0x651: lea    edx,[rcx-0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551596ULL);
x86_l_654:
	/* 0x654: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_657:
	/* 0x657: jb     714 <filter_inet+0x14a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_714;
	}
x86_l_65d:
	/* 0x65d: lea    edx,[rcx-0x16] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_660:
	/* 0x660: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_663:
	/* 0x663: jb     70e <filter_inet+0x144> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_70e;
	}
x86_l_669:
	/* 0x669: jmp    8c7 <filter_inet+0x2fd> */
	goto x86_l_8c7;
x86_l_66e:
	/* 0x66e: cmp    ecx,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 27ULL);
x86_l_671:
	/* 0x671: jg     751 <filter_inet+0x187> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_751;
	}
x86_l_677:
	/* 0x677: cmp    ecx,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 24ULL);
x86_l_67a:
	/* 0x67a: je     784 <filter_inet+0x1ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_784;
	}
x86_l_680:
	/* 0x680: cmp    ecx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 25ULL);
x86_l_683:
	/* 0x683: je     77a <filter_inet+0x1b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_77a;
	}
x86_l_689:
	/* 0x689: jmp    8c7 <filter_inet+0x2fd> */
	goto x86_l_8c7;
x86_l_68e:
	/* 0x68e: movzx  eax,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_691:
	/* 0x691: mov    WORD PTR [rsp+0x46],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 70ULL);
x86_l_696:
	/* 0x696: movzx  eax,WORD PTR [rsi+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_69a:
	/* 0x69a: mov    WORD PTR [rsp+0x40],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_69f:
	/* 0x69f: mov    rax,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6a3:
	/* 0x6a3: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6a8:
	/* 0x6a8: mov    rax,QWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6ac:
	/* 0x6ac: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6b1:
	/* 0x6b1: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6b6:
	/* 0x6b6: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6b9:
	/* 0x6b9: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_6bc:
	/* 0x6bc: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6be:
	/* 0x6be: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_6c1:
	/* 0x6c1: jg     64c <filter_inet+0x82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_64c;
	}
x86_l_6c3:
	/* 0x6c3: cmp    ecx,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 15ULL);
x86_l_6c6:
	/* 0x6c6: jle    6e4 <filter_inet+0x11a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_6e4;
	}
x86_l_6c8:
	/* 0x6c8: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_6cb:
	/* 0x6cb: jg     700 <filter_inet+0x136> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_700;
	}
x86_l_6cd:
	/* 0x6cd: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_6d0:
	/* 0x6d0: je     70e <filter_inet+0x144> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_70e;
	}
x86_l_6d2:
	/* 0x6d2: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_6d5:
	/* 0x6d5: jne    8c7 <filter_inet+0x2fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8c7;
	}
x86_l_6db:
	/* 0x6db: movzx  eax,WORD PTR [rsi+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_6df:
	/* 0x6df: jmp    8bc <filter_inet+0x2f2> */
	goto x86_l_8bc;
x86_l_6e4:
	/* 0x6e4: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_6e7:
	/* 0x6e7: je     784 <filter_inet+0x1ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_784;
	}
x86_l_6ed:
	/* 0x6ed: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_6f0:
	/* 0x6f0: je     77a <filter_inet+0x1b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_77a;
	}
x86_l_6f6:
	/* 0x6f6: cmp    ecx,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 15ULL);
x86_l_6f9:
	/* 0x6f9: je     714 <filter_inet+0x14a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_714;
	}
x86_l_6fb:
	/* 0x6fb: jmp    8c7 <filter_inet+0x2fd> */
	goto x86_l_8c7;
x86_l_700:
	/* 0x700: cmp    ecx,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 18ULL);
x86_l_703:
	/* 0x703: je     714 <filter_inet+0x14a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_714;
	}
x86_l_705:
	/* 0x705: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_708:
	/* 0x708: jne    8c7 <filter_inet+0x2fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8c7;
	}
x86_l_70e:
	/* 0x70e: movzx  edx,WORD PTR [rsi+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_712:
	/* 0x712: jmp    718 <filter_inet+0x14e> */
	goto x86_l_718;
x86_l_714:
	/* 0x714: movzx  edx,WORD PTR [rsi+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_718:
	/* 0x718: mov    DWORD PTR [rsp+0x4],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_71c:
	/* 0x71c: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_71e:
	/* 0x71e: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_721:
	/* 0x721: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_724:
	/* 0x724: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_726:
	/* 0x726: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_729:
	/* 0x729: jg     79b <filter_inet+0x1d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_79b;
	}
x86_l_72b:
	/* 0x72b: lea    edx,[rcx-0xd] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551603ULL);
x86_l_72e:
	/* 0x72e: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_731:
	/* 0x731: jb     7c2 <filter_inet+0x1f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_7c2;
	}
x86_l_737:
	/* 0x737: lea    edx,[rcx-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_73a:
	/* 0x73a: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_73d:
	/* 0x73d: jb     817 <filter_inet+0x24d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_817;
	}
x86_l_743:
	/* 0x743: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_746:
	/* 0x746: je     8bf <filter_inet+0x2f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8bf;
	}
x86_l_74c:
	/* 0x74c: jmp    8c7 <filter_inet+0x2fd> */
	goto x86_l_8c7;
x86_l_751:
	/* 0x751: cmp    ecx,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 28ULL);
x86_l_754:
	/* 0x754: je     8b8 <filter_inet+0x2ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8b8;
	}
x86_l_75a:
	/* 0x75a: cmp    ecx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 29ULL);
x86_l_75d:
	/* 0x75d: jne    8c7 <filter_inet+0x2fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8c7;
	}
x86_l_763:
	/* 0x763: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_766:
	/* 0x766: jne    8eb <filter_inet+0x321> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8eb;
	}
x86_l_76c:
	/* 0x76c: test   r8,r8 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_64);
x86_l_76f:
	/* 0x76f: jne    8f5 <filter_inet+0x32b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8f5;
	}
x86_l_775:
	/* 0x775: jmp    8bf <filter_inet+0x2f5> */
	goto x86_l_8bf;
x86_l_77a:
	/* 0x77a: mov    rbx,QWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_77e:
	/* 0x77e: mov    r14,QWORD PTR [rsi+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_782:
	/* 0x782: jmp    78b <filter_inet+0x1c1> */
	goto x86_l_78b;
x86_l_784:
	/* 0x784: mov    rbx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_787:
	/* 0x787: mov    r14,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_78b:
	/* 0x78b: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_78e:
	/* 0x78e: shr    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_792:
	/* 0x792: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_794:
	/* 0x794: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_796:
	/* 0x796: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_799:
	/* 0x799: jle    72b <filter_inet+0x161> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_72b;
	}
x86_l_79b:
	/* 0x79b: cmp    ecx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 25ULL);
x86_l_79e:
	/* 0x79e: ja     80b <filter_inet+0x241> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_80b;
	}
x86_l_7a0:
	/* 0x7a0: mov    r8d,0x500000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5242880ULL);
x86_l_7a6:
	/* 0x7a6: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_7aa:
	/* 0x7aa: jb     821 <filter_inet+0x257> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_821;
	}
x86_l_7ac:
	/* 0x7ac: mov    r8d,0xa00000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 10485760ULL);
x86_l_7b2:
	/* 0x7b2: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_7b6:
	/* 0x7b6: jb     831 <filter_inet+0x267> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_831;
	}
x86_l_7b8:
	/* 0x7b8: mov    edx,0x3000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 50331648ULL);
x86_l_7bd:
	/* 0x7bd: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_7c0:
	/* 0x7c0: jae    80b <filter_inet+0x241> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_80b;
	}
x86_l_7c2:
	/* 0x7c2: movzx  eax,WORD PTR [rsi+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_7c6:
	/* 0x7c6: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_7c9:
	/* 0x7c9: je     841 <filter_inet+0x277> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_841;
	}
x86_l_7cb:
	/* 0x7cb: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_7ce:
	/* 0x7ce: jne    8b1 <filter_inet+0x2e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8b1;
	}
x86_l_7d4:
	/* 0x7d4: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_7d7:
	/* 0x7d7: mov    eax,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7da:
	/* 0x7da: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7de:
	/* 0x7de: mov    rdi,QWORD PTR [rip+0x1810] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr4lpm_maps)));
x86_l_7e5:
	/* 0x7e5: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7ea:
	/* 0x7ea: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7ef:
	/* 0x7ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7f1:
	/* 0x7f1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7f4:
	/* 0x7f4: je     8d3 <filter_inet+0x309> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8d3;
	}
x86_l_7fa:
	/* 0x7fa: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_7fd:
	/* 0x7fd: mov    DWORD PTR [rsp+0xc],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607584ULL);
x86_l_805:
	/* 0x805: mov    DWORD PTR [rsp+0x10],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_809:
	/* 0x809: jmp    885 <filter_inet+0x2bb> */
	goto x86_l_885;
x86_l_80b:
	/* 0x80b: add    ecx,0xffffffee */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 4294967278ULL);
x86_l_80e:
	/* 0x80e: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_811:
	/* 0x811: jae    8c7 <filter_inet+0x2fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_8c7;
	}
x86_l_817:
	/* 0x817: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_81c:
	/* 0x81c: jmp    8c2 <filter_inet+0x2f8> */
	goto x86_l_8c2;
x86_l_821:
	/* 0x821: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_823:
	/* 0x823: cmp    edx,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1024ULL);
x86_l_829:
	/* 0x829: setb   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_B);
x86_l_82c:
	/* 0x82c: jmp    8c7 <filter_inet+0x2fd> */
	goto x86_l_8c7;
x86_l_831:
	/* 0x831: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_833:
	/* 0x833: cmp    edx,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1024ULL);
x86_l_839:
	/* 0x839: setae  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_AE);
x86_l_83c:
	/* 0x83c: jmp    8c7 <filter_inet+0x2fd> */
	goto x86_l_8c7;
x86_l_841:
	/* 0x841: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_844:
	/* 0x844: mov    eax,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_847:
	/* 0x847: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_84b:
	/* 0x84b: mov    rdi,QWORD PTR [rip+0x1810] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr6lpm_maps)));
x86_l_852:
	/* 0x852: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_857:
	/* 0x857: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_85c:
	/* 0x85c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_85e:
	/* 0x85e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_861:
	/* 0x861: je     8d3 <filter_inet+0x309> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8d3;
	}
x86_l_863:
	/* 0x863: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_866:
	/* 0x866: mov    DWORD PTR [rsp+0xc],0x80 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607680ULL);
x86_l_86e:
	/* 0x86e: mov    DWORD PTR [rsp+0x10],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_872:
	/* 0x872: mov    DWORD PTR [rsp+0x14],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_877:
	/* 0x877: mov    DWORD PTR [rsp+0x18],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_87c:
	/* 0x87c: shr    r14,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_880:
	/* 0x880: mov    DWORD PTR [rsp+0x1c],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_885:
	/* 0x885: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_88a:
	/* 0x88a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_88f:
	/* 0x88f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_891:
	/* 0x891: mov    ecx,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_896:
	/* 0x896: lea    edx,[rcx-0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551592ULL);
x86_l_899:
	/* 0x899: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_89c:
	/* 0x89c: jb     8e0 <filter_inet+0x316> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_8e0;
	}
x86_l_89e:
	/* 0x89e: add    ecx,0xfffffff3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 4294967283ULL);
x86_l_8a1:
	/* 0x8a1: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_8a4:
	/* 0x8a4: ja     8b1 <filter_inet+0x2e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_8b1;
	}
x86_l_8a6:
	/* 0x8a6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8a9:
	/* 0x8a9: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_8ac:
	/* 0x8ac: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_8af:
	/* 0x8af: jmp    8c7 <filter_inet+0x2fd> */
	goto x86_l_8c7;
x86_l_8b1:
	/* 0x8b1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8b3:
	/* 0x8b3: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_8b6:
	/* 0x8b6: jmp    8c7 <filter_inet+0x2fd> */
	goto x86_l_8c7;
x86_l_8b8:
	/* 0x8b8: movzx  eax,WORD PTR [rsi+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_8bc:
	/* 0x8bc: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8bf:
	/* 0x8bf: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_8c2:
	/* 0x8c2: call   1f60 <filter_32ty_map> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2247ULL);
	__x86_sim_call_depth++;
	return 8032ULL;
x86_l_8c7:
	/* 0x8c7: add    rsp,0x48 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 72ULL);
x86_l_8cb:
	/* 0x8cb: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_8cc:
	/* 0x8cc: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_8ce:
	/* 0x8ce: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_8d0:
	/* 0x8d0: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_8d2:
	/* 0x8d2: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_8d3:
	/* 0x8d3: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_8d8:
	/* 0x8d8: and    eax,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_8db:
	/* 0x8db: cmp    eax,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_8de:
	/* 0x8de: jmp    8e3 <filter_inet+0x319> */
	goto x86_l_8e3;
x86_l_8e0:
	/* 0x8e0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8e3:
	/* 0x8e3: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_8e6:
	/* 0x8e6: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_8e9:
	/* 0x8e9: jmp    8c7 <filter_inet+0x2fd> */
	goto x86_l_8c7;
x86_l_8eb:
	/* 0x8eb: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_8ee:
	/* 0x8ee: jne    8fd <filter_inet+0x333> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8fd;
	}
x86_l_8f0:
	/* 0x8f0: test   r8,r8 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_64);
x86_l_8f3:
	/* 0x8f3: je     8fd <filter_inet+0x333> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8fd;
	}
x86_l_8f5:
	/* 0x8f5: movzx  eax,BYTE PTR [r8+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 58ULL);
x86_l_8fa:
	/* 0x8fa: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8fd:
	/* 0x8fd: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_900:
	/* 0x900: je     8bf <filter_inet+0x2f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8bf;
	}
x86_l_902:
	/* 0x902: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_905:
	/* 0x905: je     8bf <filter_inet+0x2f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8bf;
	}
x86_l_907:
	/* 0x907: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_909:
	/* 0x909: jmp    8c7 <filter_inet+0x2fd> */
	goto x86_l_8c7;
x86_l_90b:
	/* 0x90b: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_90c:
	/* 0x90c: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_910:
	/* 0x910: mov    rcx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_64);
x86_l_913:
	/* 0x913: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_917:
	/* 0x917: movzx  edx,BYTE PTR [rcx+0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 3ULL);
x86_l_91b:
	/* 0x91b: mov    r8d,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_91f:
	/* 0x91f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_921:
	/* 0x921: cmp    r8d,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 25ULL);
x86_l_925:
	/* 0x925: jg     95b <filter_sockaddr_un+0x50> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_95b;
	}
x86_l_927:
	/* 0x927: lea    ecx,[r8-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_92b:
	/* 0x92b: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_92e:
	/* 0x92e: jae    969 <filter_sockaddr_un+0x5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_969;
	}
x86_l_930:
	/* 0x930: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_933:
	/* 0x933: call   119b <filter_char_buf_equal> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2360ULL);
	__x86_sim_call_depth++;
	return 4507ULL;
x86_l_938:
	/* 0x938: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_93b:
	/* 0x93b: cmp    rcx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 37ULL);
x86_l_93f:
	/* 0x93f: ja     955 <filter_sockaddr_un+0x4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_955;
	}
x86_l_941:
	/* 0x941: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_94b:
	/* 0x94b: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_94f:
	/* 0x94f: jae    955 <filter_sockaddr_un+0x4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_955;
	}
x86_l_951:
	/* 0x951: xor    rax,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 1ULL);
x86_l_955:
	/* 0x955: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_959:
	/* 0x959: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_95a:
	/* 0x95a: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_95b:
	/* 0x95b: cmp    r8d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 28ULL);
x86_l_95f:
	/* 0x95f: je     99f <filter_sockaddr_un+0x94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_99f;
	}
x86_l_961:
	/* 0x961: cmp    r8d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 26ULL);
x86_l_965:
	/* 0x965: je     96f <filter_sockaddr_un+0x64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_96f;
	}
x86_l_967:
	/* 0x967: jmp    955 <filter_sockaddr_un+0x4a> */
	goto x86_l_955;
x86_l_969:
	/* 0x969: cmp    r8d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 8ULL);
x86_l_96d:
	/* 0x96d: jne    955 <filter_sockaddr_un+0x4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_955;
	}
x86_l_96f:
	/* 0x96f: mov    eax,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_972:
	/* 0x972: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_975:
	/* 0x975: mov    edi,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_977:
	/* 0x977: call   10fb <filter_char_buf_prefix> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2428ULL);
	__x86_sim_call_depth++;
	return 4347ULL;
x86_l_97c:
	/* 0x97c: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_97f:
	/* 0x97f: cmp    rcx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 37ULL);
x86_l_983:
	/* 0x983: ja     955 <filter_sockaddr_un+0x4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_955;
	}
x86_l_985:
	/* 0x985: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_98f:
	/* 0x98f: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_993:
	/* 0x993: jae    955 <filter_sockaddr_un+0x4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_955;
	}
x86_l_995:
	/* 0x995: xor    rax,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 1ULL);
x86_l_999:
	/* 0x999: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_99d:
	/* 0x99d: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_99e:
	/* 0x99e: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_99f:
	/* 0x99f: movzx  eax,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_9a2:
	/* 0x9a2: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_9a6:
	/* 0x9a6: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_9ab:
	/* 0x9ab: call   1f60 <filter_32ty_map> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2480ULL);
	__x86_sim_call_depth++;
	return 8032ULL;
x86_l_9b0:
	/* 0x9b0: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_9b4:
	/* 0x9b4: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_9b5:
	/* 0x9b5: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_9b6:
	/* 0x9b6: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_9b7:
	/* 0x9b7: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_9ba:
	/* 0x9ba: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9bc:
	/* 0x9bc: cmp    rcx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 32ULL);
x86_l_9c0:
	/* 0x9c0: ja     9fb <filter_32ty+0x45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_9fb;
	}
x86_l_9c2:
	/* 0x9c2: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_9c7:
	/* 0x9c7: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_9cb:
	/* 0x9cb: jae    9d4 <filter_32ty+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_9d4;
	}
x86_l_9cd:
	/* 0x9cd: call   1b96 <filter_32ty_selector_val> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2514ULL);
	__x86_sim_call_depth++;
	return 7062ULL;
x86_l_9d2:
	/* 0x9d2: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_9d3:
	/* 0x9d3: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_9d4:
	/* 0x9d4: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_9d9:
	/* 0x9d9: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_9dd:
	/* 0x9dd: jb     9f6 <filter_32ty+0x40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_9f6;
	}
x86_l_9df:
	/* 0x9df: movabs rdx,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 6442450944ULL);
x86_l_9e9:
	/* 0x9e9: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_9ed:
	/* 0x9ed: jae    9fb <filter_32ty+0x45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_9fb;
	}
x86_l_9ef:
	/* 0x9ef: call   1daa <filter_32ty_range> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2548ULL);
	__x86_sim_call_depth++;
	return 7594ULL;
x86_l_9f4:
	/* 0x9f4: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_9f5:
	/* 0x9f5: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_9f6:
	/* 0x9f6: call   1f60 <filter_32ty_map> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2555ULL);
	__x86_sim_call_depth++;
	return 8032ULL;
x86_l_9fb:
	/* 0x9fb: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_9fc:
	/* 0x9fc: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_9fd:
	/* 0x9fd: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_9fe:
	/* 0x9fe: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_a01:
	/* 0xa01: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a03:
	/* 0xa03: cmp    rcx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 32ULL);
x86_l_a07:
	/* 0xa07: ja     a42 <filter_16ty+0x45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_a42;
	}
x86_l_a09:
	/* 0xa09: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_a0e:
	/* 0xa0e: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_a12:
	/* 0xa12: jae    a1b <filter_16ty+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_a1b;
	}
x86_l_a14:
	/* 0xa14: call   173e <filter_16ty_selector_val> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2585ULL);
	__x86_sim_call_depth++;
	return 5950ULL;
x86_l_a19:
	/* 0xa19: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_a1a:
	/* 0xa1a: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_a1b:
	/* 0xa1b: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_a20:
	/* 0xa20: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_a24:
	/* 0xa24: jb     a3d <filter_16ty+0x40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_a3d;
	}
x86_l_a26:
	/* 0xa26: movabs rdx,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 6442450944ULL);
x86_l_a30:
	/* 0xa30: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_a34:
	/* 0xa34: jae    a42 <filter_16ty+0x45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_a42;
	}
x86_l_a36:
	/* 0xa36: call   1958 <filter_16ty_range> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2619ULL);
	__x86_sim_call_depth++;
	return 6488ULL;
x86_l_a3b:
	/* 0xa3b: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_a3c:
	/* 0xa3c: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_a3d:
	/* 0xa3d: call   1b10 <filter_16ty_map> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2626ULL);
	__x86_sim_call_depth++;
	return 6928ULL;
x86_l_a42:
	/* 0xa42: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_a43:
	/* 0xa43: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_a44:
	/* 0xa44: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_a45:
	/* 0xa45: mov    rax,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_a48:
	/* 0xa48: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_a4b:
	/* 0xa4b: movsxd rcx,edx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_a4e:
	/* 0xa4e: mov    edx,DWORD PTR [rsi+rcx*1-0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 18446744073709551612ULL);
x86_l_a52:
	/* 0xa52: mov    esi,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_a54:
	/* 0xa54: add    rsi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_a57:
	/* 0xa57: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_a5a:
	/* 0xa5a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a5c:
	/* 0xa5c: cmp    ecx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 25ULL);
x86_l_a5f:
	/* 0xa5f: jg     a75 <filter_char_buf+0x31> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_a75;
	}
x86_l_a61:
	/* 0xa61: lea    edi,[rcx-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_a64:
	/* 0xa64: cmp    edi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_a67:
	/* 0xa67: jb     aac <filter_char_buf+0x68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_aac;
	}
x86_l_a69:
	/* 0xa69: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a6c:
	/* 0xa6c: je     aa2 <filter_char_buf+0x5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_aa2;
	}
x86_l_a6e:
	/* 0xa6e: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_a71:
	/* 0xa71: je     a84 <filter_char_buf+0x40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a84;
	}
x86_l_a73:
	/* 0xa73: jmp    ac3 <filter_char_buf+0x7f> */
	goto x86_l_ac3;
x86_l_a75:
	/* 0xa75: cmp    ecx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 32ULL);
x86_l_a78:
	/* 0xa78: jg     a8e <filter_char_buf+0x4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_a8e;
	}
x86_l_a7a:
	/* 0xa7a: cmp    ecx,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 26ULL);
x86_l_a7d:
	/* 0xa7d: je     aa2 <filter_char_buf+0x5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_aa2;
	}
x86_l_a7f:
	/* 0xa7f: cmp    ecx,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 27ULL);
x86_l_a82:
	/* 0xa82: jne    ac3 <filter_char_buf+0x7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_ac3;
	}
x86_l_a84:
	/* 0xa84: mov    edi,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a87:
	/* 0xa87: call   fb3 <filter_char_buf_postfix> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2700ULL);
	__x86_sim_call_depth++;
	return 4019ULL;
x86_l_a8c:
	/* 0xa8c: jmp    ac0 <filter_char_buf+0x7c> */
	goto x86_l_ac0;
x86_l_a8e:
	/* 0xa8e: cmp    ecx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 33ULL);
x86_l_a91:
	/* 0xa91: je     ab6 <filter_char_buf+0x72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ab6;
	}
x86_l_a93:
	/* 0xa93: cmp    ecx,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 34ULL);
x86_l_a96:
	/* 0xa96: jne    ac3 <filter_char_buf+0x7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_ac3;
	}
x86_l_a98:
	/* 0xa98: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_a9b:
	/* 0xa9b: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_aa0:
	/* 0xaa0: jmp    abb <filter_char_buf+0x77> */
	goto x86_l_abb;
x86_l_aa2:
	/* 0xaa2: mov    edi,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_aa5:
	/* 0xaa5: call   10fb <filter_char_buf_prefix> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2730ULL);
	__x86_sim_call_depth++;
	return 4347ULL;
x86_l_aaa:
	/* 0xaaa: jmp    ac0 <filter_char_buf+0x7c> */
	goto x86_l_ac0;
x86_l_aac:
	/* 0xaac: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_aaf:
	/* 0xaaf: call   119b <filter_char_buf_equal> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2740ULL);
	__x86_sim_call_depth++;
	return 4507ULL;
x86_l_ab4:
	/* 0xab4: jmp    ac0 <filter_char_buf+0x7c> */
	goto x86_l_ac0;
x86_l_ab6:
	/* 0xab6: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_ab9:
	/* 0xab9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_abb:
	/* 0xabb: call   1528 <filter_char_substring> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2752ULL);
	__x86_sim_call_depth++;
	return 5416ULL;
x86_l_ac0:
	/* 0xac0: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ac3:
	/* 0xac3: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_ac6:
	/* 0xac6: ja     ae5 <filter_char_buf+0xa1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_ae5;
	}
x86_l_ac8:
	/* 0xac8: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_aca:
	/* 0xaca: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_ad4:
	/* 0xad4: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_ad8:
	/* 0xad8: jae    ae5 <filter_char_buf+0xa1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_ae5;
	}
x86_l_ada:
	/* 0xada: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_adc:
	/* 0xadc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_adf:
	/* 0xadf: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_ae2:
	/* 0xae2: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_ae5:
	/* 0xae5: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_ae6:
	/* 0xae6: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_ae7:
	/* 0xae7: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_ae8:
	/* 0xae8: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_aeb:
	/* 0xaeb: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_aed:
	/* 0xaed: cmp    rcx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 32ULL);
x86_l_af1:
	/* 0xaf1: ja     b2c <filter_64ty+0x45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2860ULL;
	}
x86_l_af3:
	/* 0xaf3: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_af8:
	/* 0xaf8: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_afc:
	/* 0xafc: jae    b05 <filter_64ty+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 2821ULL;
	}
x86_l_afe:
	/* 0xafe: call   b2e <filter_64ty_selector_val> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2819ULL);
	__x86_sim_call_depth++;
	return 2862ULL;
x86_l_b03:
	/* 0xb03: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_b04:
	/* 0xb04: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
	return 2821ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v61_generic_uprobe_filter_arg_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 2821ULL: goto x86_l_b05;
	case 2826ULL: goto x86_l_b0a;
	case 2830ULL: goto x86_l_b0e;
	case 2832ULL: goto x86_l_b10;
	case 2842ULL: goto x86_l_b1a;
	case 2846ULL: goto x86_l_b1e;
	case 2848ULL: goto x86_l_b20;
	case 2853ULL: goto x86_l_b25;
	case 2854ULL: goto x86_l_b26;
	case 2855ULL: goto x86_l_b27;
	case 2860ULL: goto x86_l_b2c;
	case 2861ULL: goto x86_l_b2d;
	case 2862ULL: goto x86_l_b2e;
	case 2865ULL: goto x86_l_b31;
	case 2870ULL: goto x86_l_b36;
	case 2874ULL: goto x86_l_b3a;
	case 2876ULL: goto x86_l_b3c;
	case 2886ULL: goto x86_l_b46;
	case 2890ULL: goto x86_l_b4a;
	case 2892ULL: goto x86_l_b4c;
	case 2893ULL: goto x86_l_b4d;
	case 2898ULL: goto x86_l_b52;
	case 2902ULL: goto x86_l_b56;
	case 2904ULL: goto x86_l_b58;
	case 2907ULL: goto x86_l_b5b;
	case 2911ULL: goto x86_l_b5f;
	case 2917ULL: goto x86_l_b65;
	case 2919ULL: goto x86_l_b67;
	case 2922ULL: goto x86_l_b6a;
	case 2925ULL: goto x86_l_b6d;
	case 2926ULL: goto x86_l_b6e;
	case 2930ULL: goto x86_l_b72;
	case 2932ULL: goto x86_l_b74;
	case 2935ULL: goto x86_l_b77;
	case 2939ULL: goto x86_l_b7b;
	case 2941ULL: goto x86_l_b7d;
	case 2944ULL: goto x86_l_b80;
	case 2947ULL: goto x86_l_b83;
	case 2953ULL: goto x86_l_b89;
	case 2957ULL: goto x86_l_b8d;
	case 2959ULL: goto x86_l_b8f;
	case 2962ULL: goto x86_l_b92;
	case 2968ULL: goto x86_l_b98;
	case 2972ULL: goto x86_l_b9c;
	case 2974ULL: goto x86_l_b9e;
	case 2977ULL: goto x86_l_ba1;
	case 2983ULL: goto x86_l_ba7;
	case 2987ULL: goto x86_l_bab;
	case 2989ULL: goto x86_l_bad;
	case 2994ULL: goto x86_l_bb2;
	case 2997ULL: goto x86_l_bb5;
	case 2999ULL: goto x86_l_bb7;
	case 3002ULL: goto x86_l_bba;
	case 3008ULL: goto x86_l_bc0;
	case 3011ULL: goto x86_l_bc3;
	case 3014ULL: goto x86_l_bc6;
	case 3020ULL: goto x86_l_bcc;
	case 3025ULL: goto x86_l_bd1;
	case 3028ULL: goto x86_l_bd4;
	case 3034ULL: goto x86_l_bda;
	case 3037ULL: goto x86_l_bdd;
	case 3041ULL: goto x86_l_be1;
	case 3047ULL: goto x86_l_be7;
	case 3050ULL: goto x86_l_bea;
	case 3053ULL: goto x86_l_bed;
	case 3059ULL: goto x86_l_bf3;
	case 3063ULL: goto x86_l_bf7;
	case 3069ULL: goto x86_l_bfd;
	case 3072ULL: goto x86_l_c00;
	case 3078ULL: goto x86_l_c06;
	case 3082ULL: goto x86_l_c0a;
	case 3088ULL: goto x86_l_c10;
	case 3091ULL: goto x86_l_c13;
	case 3097ULL: goto x86_l_c19;
	case 3101ULL: goto x86_l_c1d;
	case 3107ULL: goto x86_l_c23;
	case 3112ULL: goto x86_l_c28;
	case 3115ULL: goto x86_l_c2b;
	case 3118ULL: goto x86_l_c2e;
	case 3124ULL: goto x86_l_c34;
	case 3129ULL: goto x86_l_c39;
	case 3132ULL: goto x86_l_c3c;
	case 3138ULL: goto x86_l_c42;
	case 3141ULL: goto x86_l_c45;
	case 3145ULL: goto x86_l_c49;
	case 3151ULL: goto x86_l_c4f;
	case 3154ULL: goto x86_l_c52;
	case 3157ULL: goto x86_l_c55;
	case 3163ULL: goto x86_l_c5b;
	case 3167ULL: goto x86_l_c5f;
	case 3173ULL: goto x86_l_c65;
	case 3176ULL: goto x86_l_c68;
	case 3182ULL: goto x86_l_c6e;
	case 3186ULL: goto x86_l_c72;
	case 3192ULL: goto x86_l_c78;
	case 3195ULL: goto x86_l_c7b;
	case 3201ULL: goto x86_l_c81;
	case 3205ULL: goto x86_l_c85;
	case 3211ULL: goto x86_l_c8b;
	case 3216ULL: goto x86_l_c90;
	case 3219ULL: goto x86_l_c93;
	case 3222ULL: goto x86_l_c96;
	case 3224ULL: goto x86_l_c98;
	case 3228ULL: goto x86_l_c9c;
	case 3234ULL: goto x86_l_ca2;
	case 3237ULL: goto x86_l_ca5;
	case 3239ULL: goto x86_l_ca7;
	case 3243ULL: goto x86_l_cab;
	case 3249ULL: goto x86_l_cb1;
	case 3252ULL: goto x86_l_cb4;
	case 3254ULL: goto x86_l_cb6;
	case 3258ULL: goto x86_l_cba;
	case 3264ULL: goto x86_l_cc0;
	case 3267ULL: goto x86_l_cc3;
	case 3273ULL: goto x86_l_cc9;
	case 3275ULL: goto x86_l_ccb;
	case 3285ULL: goto x86_l_cd5;
	case 3289ULL: goto x86_l_cd9;
	case 3295ULL: goto x86_l_cdf;
	case 3297ULL: goto x86_l_ce1;
	case 3300ULL: goto x86_l_ce4;
	case 3304ULL: goto x86_l_ce8;
	case 3310ULL: goto x86_l_cee;
	case 3313ULL: goto x86_l_cf1;
	case 3316ULL: goto x86_l_cf4;
	case 3318ULL: goto x86_l_cf6;
	case 3322ULL: goto x86_l_cfa;
	case 3328ULL: goto x86_l_d00;
	case 3331ULL: goto x86_l_d03;
	case 3333ULL: goto x86_l_d05;
	case 3337ULL: goto x86_l_d09;
	case 3343ULL: goto x86_l_d0f;
	case 3346ULL: goto x86_l_d12;
	case 3348ULL: goto x86_l_d14;
	case 3352ULL: goto x86_l_d18;
	case 3358ULL: goto x86_l_d1e;
	case 3360ULL: goto x86_l_d20;
	case 3363ULL: goto x86_l_d23;
	case 3367ULL: goto x86_l_d27;
	case 3373ULL: goto x86_l_d2d;
	case 3376ULL: goto x86_l_d30;
	case 3379ULL: goto x86_l_d33;
	case 3381ULL: goto x86_l_d35;
	case 3385ULL: goto x86_l_d39;
	case 3391ULL: goto x86_l_d3f;
	case 3394ULL: goto x86_l_d42;
	case 3396ULL: goto x86_l_d44;
	case 3400ULL: goto x86_l_d48;
	case 3406ULL: goto x86_l_d4e;
	case 3409ULL: goto x86_l_d51;
	case 3411ULL: goto x86_l_d53;
	case 3415ULL: goto x86_l_d57;
	case 3421ULL: goto x86_l_d5d;
	case 3423ULL: goto x86_l_d5f;
	case 3424ULL: goto x86_l_d60;
	case 3427ULL: goto x86_l_d63;
	case 3430ULL: goto x86_l_d66;
	case 3433ULL: goto x86_l_d69;
	case 3439ULL: goto x86_l_d6f;
	case 3444ULL: goto x86_l_d74;
	case 3447ULL: goto x86_l_d77;
	case 3453ULL: goto x86_l_d7d;
	case 3456ULL: goto x86_l_d80;
	case 3459ULL: goto x86_l_d83;
	case 3461ULL: goto x86_l_d85;
	case 3466ULL: goto x86_l_d8a;
	case 3470ULL: goto x86_l_d8e;
	case 3472ULL: goto x86_l_d90;
	case 3476ULL: goto x86_l_d94;
	case 3482ULL: goto x86_l_d9a;
	case 3485ULL: goto x86_l_d9d;
	case 3488ULL: goto x86_l_da0;
	case 3494ULL: goto x86_l_da6;
	case 3498ULL: goto x86_l_daa;
	case 3500ULL: goto x86_l_dac;
	case 3504ULL: goto x86_l_db0;
	case 3510ULL: goto x86_l_db6;
	case 3513ULL: goto x86_l_db9;
	case 3519ULL: goto x86_l_dbf;
	case 3523ULL: goto x86_l_dc3;
	case 3525ULL: goto x86_l_dc5;
	case 3529ULL: goto x86_l_dc9;
	case 3535ULL: goto x86_l_dcf;
	case 3538ULL: goto x86_l_dd2;
	case 3544ULL: goto x86_l_dd8;
	case 3546ULL: goto x86_l_dda;
	case 3550ULL: goto x86_l_dde;
	case 3556ULL: goto x86_l_de4;
	case 3560ULL: goto x86_l_de8;
	case 3566ULL: goto x86_l_dee;
	case 3571ULL: goto x86_l_df3;
	case 3574ULL: goto x86_l_df6;
	case 3578ULL: goto x86_l_dfa;
	case 3582ULL: goto x86_l_dfe;
	case 3586ULL: goto x86_l_e02;
	case 3589ULL: goto x86_l_e05;
	case 3592ULL: goto x86_l_e08;
	case 3595ULL: goto x86_l_e0b;
	case 3601ULL: goto x86_l_e11;
	case 3605ULL: goto x86_l_e15;
	case 3609ULL: goto x86_l_e19;
	case 3613ULL: goto x86_l_e1d;
	case 3617ULL: goto x86_l_e21;
	case 3620ULL: goto x86_l_e24;
	case 3623ULL: goto x86_l_e27;
	case 3626ULL: goto x86_l_e2a;
	case 3632ULL: goto x86_l_e30;
	case 3636ULL: goto x86_l_e34;
	case 3640ULL: goto x86_l_e38;
	case 3644ULL: goto x86_l_e3c;
	case 3648ULL: goto x86_l_e40;
	case 3651ULL: goto x86_l_e43;
	case 3654ULL: goto x86_l_e46;
	case 3657ULL: goto x86_l_e49;
	case 3663ULL: goto x86_l_e4f;
	case 3667ULL: goto x86_l_e53;
	case 3670ULL: goto x86_l_e56;
	case 3674ULL: goto x86_l_e5a;
	case 3678ULL: goto x86_l_e5e;
	case 3683ULL: goto x86_l_e63;
	case 3686ULL: goto x86_l_e66;
	case 3689ULL: goto x86_l_e69;
	case 3691ULL: goto x86_l_e6b;
	case 3696ULL: goto x86_l_e70;
	case 3700ULL: goto x86_l_e74;
	case 3702ULL: goto x86_l_e76;
	case 3706ULL: goto x86_l_e7a;
	case 3708ULL: goto x86_l_e7c;
	case 3709ULL: goto x86_l_e7d;
	case 3712ULL: goto x86_l_e80;
	case 3716ULL: goto x86_l_e84;
	case 3720ULL: goto x86_l_e88;
	case 3724ULL: goto x86_l_e8c;
	case 3727ULL: goto x86_l_e8f;
	case 3730ULL: goto x86_l_e92;
	case 3733ULL: goto x86_l_e95;
	case 3739ULL: goto x86_l_e9b;
	case 3743ULL: goto x86_l_e9f;
	case 3747ULL: goto x86_l_ea3;
	case 3751ULL: goto x86_l_ea7;
	case 3755ULL: goto x86_l_eab;
	case 3758ULL: goto x86_l_eae;
	case 3761ULL: goto x86_l_eb1;
	case 3764ULL: goto x86_l_eb4;
	case 3766ULL: goto x86_l_eb6;
	case 3770ULL: goto x86_l_eba;
	case 3774ULL: goto x86_l_ebe;
	case 3778ULL: goto x86_l_ec2;
	case 3782ULL: goto x86_l_ec6;
	case 3785ULL: goto x86_l_ec9;
	case 3788ULL: goto x86_l_ecc;
	case 3791ULL: goto x86_l_ecf;
	case 3793ULL: goto x86_l_ed1;
	case 3797ULL: goto x86_l_ed5;
	case 3800ULL: goto x86_l_ed8;
	case 3804ULL: goto x86_l_edc;
	case 3808ULL: goto x86_l_ee0;
	case 3811ULL: goto x86_l_ee3;
	case 3814ULL: goto x86_l_ee6;
	case 3816ULL: goto x86_l_ee8;
	case 3819ULL: goto x86_l_eeb;
	case 3822ULL: goto x86_l_eee;
	case 3824ULL: goto x86_l_ef0;
	case 3828ULL: goto x86_l_ef4;
	case 3830ULL: goto x86_l_ef6;
	case 3834ULL: goto x86_l_efa;
	case 3836ULL: goto x86_l_efc;
	case 3839ULL: goto x86_l_eff;
	case 3841ULL: goto x86_l_f01;
	case 3845ULL: goto x86_l_f05;
	case 3847ULL: goto x86_l_f07;
	case 3851ULL: goto x86_l_f0b;
	case 3857ULL: goto x86_l_f11;
	case 3860ULL: goto x86_l_f14;
	case 3862ULL: goto x86_l_f16;
	case 3864ULL: goto x86_l_f18;
	case 3868ULL: goto x86_l_f1c;
	case 3870ULL: goto x86_l_f1e;
	case 3874ULL: goto x86_l_f22;
	case 3880ULL: goto x86_l_f28;
	case 3882ULL: goto x86_l_f2a;
	case 3884ULL: goto x86_l_f2c;
	case 3887ULL: goto x86_l_f2f;
	case 3890ULL: goto x86_l_f32;
	case 3893ULL: goto x86_l_f35;
	case 3895ULL: goto x86_l_f37;
	case 3898ULL: goto x86_l_f3a;
	case 3899ULL: goto x86_l_f3b;
	case 3901ULL: goto x86_l_f3d;
	case 3902ULL: goto x86_l_f3e;
	case 3906ULL: goto x86_l_f42;
	case 3909ULL: goto x86_l_f45;
	case 3912ULL: goto x86_l_f48;
	case 3916ULL: goto x86_l_f4c;
	case 3920ULL: goto x86_l_f50;
	case 3927ULL: goto x86_l_f57;
	case 3932ULL: goto x86_l_f5c;
	case 3937ULL: goto x86_l_f61;
	case 3939ULL: goto x86_l_f63;
	case 3942ULL: goto x86_l_f66;
	case 3944ULL: goto x86_l_f68;
	case 3947ULL: goto x86_l_f6b;
	case 3950ULL: goto x86_l_f6e;
	case 3955ULL: goto x86_l_f73;
	case 3960ULL: goto x86_l_f78;
	case 3965ULL: goto x86_l_f7d;
	case 3967ULL: goto x86_l_f7f;
	case 3970ULL: goto x86_l_f82;
	case 3973ULL: goto x86_l_f85;
	case 3975ULL: goto x86_l_f87;
	case 3978ULL: goto x86_l_f8a;
	case 3980ULL: goto x86_l_f8c;
	case 3983ULL: goto x86_l_f8f;
	case 3986ULL: goto x86_l_f92;
	case 3988ULL: goto x86_l_f94;
	case 3990ULL: goto x86_l_f96;
	case 3994ULL: goto x86_l_f9a;
	case 3995ULL: goto x86_l_f9b;
	case 3997ULL: goto x86_l_f9d;
	case 3998ULL: goto x86_l_f9e;
	case 4001ULL: goto x86_l_fa1;
	case 4004ULL: goto x86_l_fa4;
	case 4006ULL: goto x86_l_fa6;
	case 4008ULL: goto x86_l_fa8;
	case 4011ULL: goto x86_l_fab;
	case 4015ULL: goto x86_l_faf;
	case 4016ULL: goto x86_l_fb0;
	case 4018ULL: goto x86_l_fb2;
	case 4019ULL: goto x86_l_fb3;
	case 4021ULL: goto x86_l_fb5;
	case 4023ULL: goto x86_l_fb7;
	case 4024ULL: goto x86_l_fb8;
	case 4028ULL: goto x86_l_fbc;
	case 4030ULL: goto x86_l_fbe;
	case 4033ULL: goto x86_l_fc1;
	case 4037ULL: goto x86_l_fc5;
	case 4045ULL: goto x86_l_fcd;
	case 4052ULL: goto x86_l_fd4;
	case 4057ULL: goto x86_l_fd9;
	case 4062ULL: goto x86_l_fde;
	case 4064ULL: goto x86_l_fe0;
	case 4067ULL: goto x86_l_fe3;
	case 4069ULL: goto x86_l_fe5;
	case 4071ULL: goto x86_l_fe7;
	case 4077ULL: goto x86_l_fed;
	case 4080ULL: goto x86_l_ff0;
	case 4086ULL: goto x86_l_ff6;
	case 4093ULL: goto x86_l_ffd;
	case 4098ULL: goto x86_l_1002;
	case 4103ULL: goto x86_l_1007;
	case 4105ULL: goto x86_l_1009;
	case 4108ULL: goto x86_l_100c;
	case 4114ULL: goto x86_l_1012;
	case 4117ULL: goto x86_l_1015;
	case 4120ULL: goto x86_l_1018;
	case 4125ULL: goto x86_l_101d;
	case 4128ULL: goto x86_l_1020;
	case 4131ULL: goto x86_l_1023;
	case 4133ULL: goto x86_l_1025;
	case 4135ULL: goto x86_l_1027;
	case 4138ULL: goto x86_l_102a;
	case 4141ULL: goto x86_l_102d;
	case 4145ULL: goto x86_l_1031;
	case 4148ULL: goto x86_l_1034;
	case 4152ULL: goto x86_l_1038;
	case 4154ULL: goto x86_l_103a;
	case 4161ULL: goto x86_l_1041;
	case 4165ULL: goto x86_l_1045;
	case 4169ULL: goto x86_l_1049;
	case 4176ULL: goto x86_l_1050;
	case 4181ULL: goto x86_l_1055;
	case 4185ULL: goto x86_l_1059;
	case 4189ULL: goto x86_l_105d;
	case 4193ULL: goto x86_l_1061;
	case 4195ULL: goto x86_l_1063;
	case 4199ULL: goto x86_l_1067;
	case 4203ULL: goto x86_l_106b;
	case 4210ULL: goto x86_l_1072;
	case 4215ULL: goto x86_l_1077;
	case 4219ULL: goto x86_l_107b;
	case 4223ULL: goto x86_l_107f;
	case 4225ULL: goto x86_l_1081;
	case 4229ULL: goto x86_l_1085;
	case 4233ULL: goto x86_l_1089;
	default: return 0xffffffffffffffffULL;
	}
x86_l_b05:
	/* 0xb05: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_b0a:
	/* 0xb0a: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_b0e:
	/* 0xb0e: jb     b27 <filter_64ty+0x40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_b27;
	}
x86_l_b10:
	/* 0xb10: movabs rdx,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 6442450944ULL);
x86_l_b1a:
	/* 0xb1a: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_b1e:
	/* 0xb1e: jae    b2c <filter_64ty+0x45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_b2c;
	}
x86_l_b20:
	/* 0xb20: call   d60 <filter_64ty_range> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2853ULL);
	__x86_sim_call_depth++;
	goto x86_l_d60;
x86_l_b25:
	/* 0xb25: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_b26:
	/* 0xb26: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_b27:
	/* 0xb27: call   f3b <filter_64ty_map> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2860ULL);
	__x86_sim_call_depth++;
	goto x86_l_f3b;
x86_l_b2c:
	/* 0xb2c: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_b2d:
	/* 0xb2d: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_b2e:
	/* 0xb2e: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_b31:
	/* 0xb31: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b36:
	/* 0xb36: cmp    rcx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 37ULL);
x86_l_b3a:
	/* 0xb3a: ja     bb2 <filter_64ty_selector_val+0x84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_bb2;
	}
x86_l_b3c:
	/* 0xb3c: movabs rdx,0x200c000040 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280128ULL);
x86_l_b46:
	/* 0xb46: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_b4a:
	/* 0xb4a: jae    b4d <filter_64ty_selector_val+0x1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_b4d;
	}
x86_l_b4c:
	/* 0xb4c: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_b4d:
	/* 0xb4d: mov    edx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 24ULL);
x86_l_b52:
	/* 0xb52: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_b56:
	/* 0xb56: jae    b6e <filter_64ty_selector_val+0x40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_b6e;
	}
x86_l_b58:
	/* 0xb58: mov    rdx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b5b:
	/* 0xb5b: cmp    rdx,QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_b5f:
	/* 0xb5f: jne    c90 <filter_64ty_selector_val+0x162> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_c90;
	}
x86_l_b65:
	/* 0xb65: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b67:
	/* 0xb67: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_b6a:
	/* 0xb6a: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_b6d:
	/* 0xb6d: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_b6e:
	/* 0xb6e: cmp    rcx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 12ULL);
x86_l_b72:
	/* 0xb72: jne    bb2 <filter_64ty_selector_val+0x84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_bb2;
	}
x86_l_b74:
	/* 0xb74: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b77:
	/* 0xb77: test   QWORD PTR [rdi+0x10],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b7b:
	/* 0xb7b: jne    b4c <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b4c;
	}
x86_l_b7d:
	/* 0xb7d: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b80:
	/* 0xb80: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_b83:
	/* 0xb83: jb     d5d <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d5d;
	}
x86_l_b89:
	/* 0xb89: test   QWORD PTR [rdi+0x18],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b8d:
	/* 0xb8d: jne    b4c <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b4c;
	}
x86_l_b8f:
	/* 0xb8f: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_b92:
	/* 0xb92: jb     d5d <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d5d;
	}
x86_l_b98:
	/* 0xb98: test   QWORD PTR [rdi+0x20],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b9c:
	/* 0xb9c: jne    b4c <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b4c;
	}
x86_l_b9e:
	/* 0xb9e: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_ba1:
	/* 0xba1: jb     d5d <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d5d;
	}
x86_l_ba7:
	/* 0xba7: test   QWORD PTR [rdi+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_bab:
	/* 0xbab: jne    b4c <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b4c;
	}
x86_l_bad:
	/* 0xbad: jmp    d5d <filter_64ty_selector_val+0x22f> */
	goto x86_l_d5d;
x86_l_bb2:
	/* 0xbb2: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_bb5:
	/* 0xbb5: je     c28 <filter_64ty_selector_val+0xfa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c28;
	}
x86_l_bb7:
	/* 0xbb7: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_bba:
	/* 0xbba: jne    d5d <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_d5d;
	}
x86_l_bc0:
	/* 0xbc0: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_bc3:
	/* 0xbc3: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_bc6:
	/* 0xbc6: ja     d20 <filter_64ty_selector_val+0x1f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_d20;
	}
x86_l_bcc:
	/* 0xbcc: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_bd1:
	/* 0xbd1: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_bd4:
	/* 0xbd4: jae    d20 <filter_64ty_selector_val+0x1f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_d20;
	}
x86_l_bda:
	/* 0xbda: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bdd:
	/* 0xbdd: cmp    rcx,QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_be1:
	/* 0xbe1: jl     b4c <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_b4c;
	}
x86_l_be7:
	/* 0xbe7: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bea:
	/* 0xbea: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_bed:
	/* 0xbed: jb     d5d <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d5d;
	}
x86_l_bf3:
	/* 0xbf3: cmp    rcx,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_bf7:
	/* 0xbf7: jl     b4c <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_b4c;
	}
x86_l_bfd:
	/* 0xbfd: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_c00:
	/* 0xc00: jb     d5d <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d5d;
	}
x86_l_c06:
	/* 0xc06: cmp    rcx,QWORD PTR [rdi+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_c0a:
	/* 0xc0a: jl     b4c <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_b4c;
	}
x86_l_c10:
	/* 0xc10: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_c13:
	/* 0xc13: jb     d5d <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d5d;
	}
x86_l_c19:
	/* 0xc19: cmp    rcx,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_c1d:
	/* 0xc1d: jl     b4c <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_b4c;
	}
x86_l_c23:
	/* 0xc23: jmp    d5d <filter_64ty_selector_val+0x22f> */
	goto x86_l_d5d;
x86_l_c28:
	/* 0xc28: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_c2b:
	/* 0xc2b: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_c2e:
	/* 0xc2e: ja     ce1 <filter_64ty_selector_val+0x1b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_ce1;
	}
x86_l_c34:
	/* 0xc34: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_c39:
	/* 0xc39: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_c3c:
	/* 0xc3c: jae    ce1 <filter_64ty_selector_val+0x1b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_ce1;
	}
x86_l_c42:
	/* 0xc42: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c45:
	/* 0xc45: cmp    rcx,QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_c49:
	/* 0xc49: jg     b4c <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_b4c;
	}
x86_l_c4f:
	/* 0xc4f: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c52:
	/* 0xc52: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_c55:
	/* 0xc55: jb     d5d <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d5d;
	}
x86_l_c5b:
	/* 0xc5b: cmp    rcx,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_c5f:
	/* 0xc5f: jg     b4c <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_b4c;
	}
x86_l_c65:
	/* 0xc65: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_c68:
	/* 0xc68: jb     d5d <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d5d;
	}
x86_l_c6e:
	/* 0xc6e: cmp    rcx,QWORD PTR [rdi+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_c72:
	/* 0xc72: jg     b4c <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_b4c;
	}
x86_l_c78:
	/* 0xc78: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_c7b:
	/* 0xc7b: jb     d5d <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d5d;
	}
x86_l_c81:
	/* 0xc81: cmp    rcx,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_c85:
	/* 0xc85: jg     b4c <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_b4c;
	}
x86_l_c8b:
	/* 0xc8b: jmp    d5d <filter_64ty_selector_val+0x22f> */
	goto x86_l_d5d;
x86_l_c90:
	/* 0xc90: mov    esi,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c93:
	/* 0xc93: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_c96:
	/* 0xc96: jb     cc0 <filter_64ty_selector_val+0x192> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_cc0;
	}
x86_l_c98:
	/* 0xc98: cmp    rdx,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_c9c:
	/* 0xc9c: je     b65 <filter_64ty_selector_val+0x37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b65;
	}
x86_l_ca2:
	/* 0xca2: cmp    esi,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 25ULL);
x86_l_ca5:
	/* 0xca5: jb     cc0 <filter_64ty_selector_val+0x192> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_cc0;
	}
x86_l_ca7:
	/* 0xca7: cmp    rdx,QWORD PTR [rdi+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_cab:
	/* 0xcab: je     b65 <filter_64ty_selector_val+0x37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b65;
	}
x86_l_cb1:
	/* 0xcb1: cmp    esi,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 33ULL);
x86_l_cb4:
	/* 0xcb4: jb     cc0 <filter_64ty_selector_val+0x192> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_cc0;
	}
x86_l_cb6:
	/* 0xcb6: cmp    rdx,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_cba:
	/* 0xcba: je     b65 <filter_64ty_selector_val+0x37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b65;
	}
x86_l_cc0:
	/* 0xcc0: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_cc3:
	/* 0xcc3: ja     d5d <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_d5d;
	}
x86_l_cc9:
	/* 0xcc9: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_ccb:
	/* 0xccb: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_cd5:
	/* 0xcd5: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_cd9:
	/* 0xcd9: jb     b4c <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_b4c;
	}
x86_l_cdf:
	/* 0xcdf: jmp    d5d <filter_64ty_selector_val+0x22f> */
	goto x86_l_d5d;
x86_l_ce1:
	/* 0xce1: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ce4:
	/* 0xce4: cmp    rcx,QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_ce8:
	/* 0xce8: ja     b4c <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_b4c;
	}
x86_l_cee:
	/* 0xcee: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cf1:
	/* 0xcf1: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_cf4:
	/* 0xcf4: jb     d5d <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d5d;
	}
x86_l_cf6:
	/* 0xcf6: cmp    rcx,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_cfa:
	/* 0xcfa: ja     b4c <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_b4c;
	}
x86_l_d00:
	/* 0xd00: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_d03:
	/* 0xd03: jb     d5d <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d5d;
	}
x86_l_d05:
	/* 0xd05: cmp    rcx,QWORD PTR [rdi+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_d09:
	/* 0xd09: ja     b4c <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_b4c;
	}
x86_l_d0f:
	/* 0xd0f: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_d12:
	/* 0xd12: jb     d5d <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d5d;
	}
x86_l_d14:
	/* 0xd14: cmp    rcx,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_d18:
	/* 0xd18: ja     b4c <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_b4c;
	}
x86_l_d1e:
	/* 0xd1e: jmp    d5d <filter_64ty_selector_val+0x22f> */
	goto x86_l_d5d;
x86_l_d20:
	/* 0xd20: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d23:
	/* 0xd23: cmp    rcx,QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_d27:
	/* 0xd27: jb     b4c <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_b4c;
	}
x86_l_d2d:
	/* 0xd2d: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d30:
	/* 0xd30: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_d33:
	/* 0xd33: jb     d5d <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d5d;
	}
x86_l_d35:
	/* 0xd35: cmp    rcx,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_d39:
	/* 0xd39: jb     b4c <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_b4c;
	}
x86_l_d3f:
	/* 0xd3f: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_d42:
	/* 0xd42: jb     d5d <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d5d;
	}
x86_l_d44:
	/* 0xd44: cmp    rcx,QWORD PTR [rdi+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_d48:
	/* 0xd48: jb     b4c <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_b4c;
	}
x86_l_d4e:
	/* 0xd4e: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_d51:
	/* 0xd51: jb     d5d <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d5d;
	}
x86_l_d53:
	/* 0xd53: cmp    rcx,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_d57:
	/* 0xd57: jb     b4c <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_b4c;
	}
x86_l_d5d:
	/* 0xd5d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d5f:
	/* 0xd5f: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_d60:
	/* 0xd60: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_d63:
	/* 0xd63: mov    eax,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_d66:
	/* 0xd66: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_d69:
	/* 0xd69: ja     e63 <filter_64ty_range+0x103> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_e63;
	}
x86_l_d6f:
	/* 0xd6f: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_d74:
	/* 0xd74: bt     edx,eax */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_d77:
	/* 0xd77: jae    e63 <filter_64ty_range+0x103> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_e63;
	}
x86_l_d7d:
	/* 0xd7d: mov    rsi,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d80:
	/* 0xd80: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_d83:
	/* 0xd83: jne    df3 <filter_64ty_range+0x93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_df3;
	}
x86_l_d85:
	/* 0xd85: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d8a:
	/* 0xd8a: cmp    QWORD PTR [rdi+0x10],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d8e:
	/* 0xd8e: jg     d9a <filter_64ty_range+0x3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_d9a;
	}
x86_l_d90:
	/* 0xd90: cmp    rsi,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_d94:
	/* 0xd94: jle    e7c <filter_64ty_range+0x11c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_e7c;
	}
x86_l_d9a:
	/* 0xd9a: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d9d:
	/* 0xd9d: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_da0:
	/* 0xda0: jb     f2a <filter_64ty_range+0x1ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f2a;
	}
x86_l_da6:
	/* 0xda6: cmp    QWORD PTR [rdi+0x20],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_daa:
	/* 0xdaa: jg     db6 <filter_64ty_range+0x56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_db6;
	}
x86_l_dac:
	/* 0xdac: cmp    rsi,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_db0:
	/* 0xdb0: jle    e7c <filter_64ty_range+0x11c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_e7c;
	}
x86_l_db6:
	/* 0xdb6: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_db9:
	/* 0xdb9: jb     f2a <filter_64ty_range+0x1ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f2a;
	}
x86_l_dbf:
	/* 0xdbf: cmp    QWORD PTR [rdi+0x30],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_dc3:
	/* 0xdc3: jg     dcf <filter_64ty_range+0x6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_dcf;
	}
x86_l_dc5:
	/* 0xdc5: cmp    rsi,QWORD PTR [rdi+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_dc9:
	/* 0xdc9: jle    e7c <filter_64ty_range+0x11c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_e7c;
	}
x86_l_dcf:
	/* 0xdcf: cmp    edx,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 57ULL);
x86_l_dd2:
	/* 0xdd2: jb     f2a <filter_64ty_range+0x1ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f2a;
	}
x86_l_dd8:
	/* 0xdd8: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_dda:
	/* 0xdda: cmp    QWORD PTR [rdi+0x40],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_dde:
	/* 0xdde: jg     f2c <filter_64ty_range+0x1cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_f2c;
	}
x86_l_de4:
	/* 0xde4: cmp    rsi,QWORD PTR [rdi+0x48] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 72ULL);
x86_l_de8:
	/* 0xde8: jle    e7c <filter_64ty_range+0x11c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_e7c;
	}
x86_l_dee:
	/* 0xdee: jmp    f2c <filter_64ty_range+0x1cc> */
	goto x86_l_f2c;
x86_l_df3:
	/* 0xdf3: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_df6:
	/* 0xdf6: cmp    QWORD PTR [rdi+0x10],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dfa:
	/* 0xdfa: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_dfe:
	/* 0xdfe: cmp    rsi,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_e02:
	/* 0xe02: setle  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_LE);
x86_l_e05:
	/* 0xe05: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_e08:
	/* 0xe08: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_e0b:
	/* 0xe0b: jb     f2c <filter_64ty_range+0x1cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f2c;
	}
x86_l_e11:
	/* 0xe11: cmp    QWORD PTR [rdi+0x20],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e15:
	/* 0xe15: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_e19:
	/* 0xe19: cmp    rsi,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_e1d:
	/* 0xe1d: setle  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_LE);
x86_l_e21:
	/* 0xe21: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_e24:
	/* 0xe24: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_e27:
	/* 0xe27: cmp    eax,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 41ULL);
x86_l_e2a:
	/* 0xe2a: jb     f2c <filter_64ty_range+0x1cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f2c;
	}
x86_l_e30:
	/* 0xe30: cmp    QWORD PTR [rdi+0x30],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e34:
	/* 0xe34: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_e38:
	/* 0xe38: cmp    rsi,QWORD PTR [rdi+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_e3c:
	/* 0xe3c: setle  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_LE);
x86_l_e40:
	/* 0xe40: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_e43:
	/* 0xe43: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_e46:
	/* 0xe46: cmp    eax,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 57ULL);
x86_l_e49:
	/* 0xe49: jb     f2c <filter_64ty_range+0x1cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f2c;
	}
x86_l_e4f:
	/* 0xe4f: cmp    QWORD PTR [rdi+0x40],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_e53:
	/* 0xe53: setle  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_LE);
x86_l_e56:
	/* 0xe56: cmp    rsi,QWORD PTR [rdi+0x48] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 72ULL);
x86_l_e5a:
	/* 0xe5a: setle  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_LE);
x86_l_e5e:
	/* 0xe5e: jmp    ee0 <filter_64ty_range+0x180> */
	goto x86_l_ee0;
x86_l_e63:
	/* 0xe63: mov    rsi,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e66:
	/* 0xe66: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_e69:
	/* 0xe69: jne    e7d <filter_64ty_range+0x11d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_e7d;
	}
x86_l_e6b:
	/* 0xe6b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e70:
	/* 0xe70: cmp    QWORD PTR [rdi+0x10],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e74:
	/* 0xe74: ja     ee8 <filter_64ty_range+0x188> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_ee8;
	}
x86_l_e76:
	/* 0xe76: cmp    rsi,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_e7a:
	/* 0xe7a: ja     ee8 <filter_64ty_range+0x188> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_ee8;
	}
x86_l_e7c:
	/* 0xe7c: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_e7d:
	/* 0xe7d: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e80:
	/* 0xe80: cmp    QWORD PTR [rdi+0x10],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e84:
	/* 0xe84: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_e88:
	/* 0xe88: cmp    rsi,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_e8c:
	/* 0xe8c: setbe  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_BE);
x86_l_e8f:
	/* 0xe8f: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_e92:
	/* 0xe92: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_e95:
	/* 0xe95: jb     f2c <filter_64ty_range+0x1cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f2c;
	}
x86_l_e9b:
	/* 0xe9b: cmp    QWORD PTR [rdi+0x20],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e9f:
	/* 0xe9f: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_ea3:
	/* 0xea3: cmp    rsi,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_ea7:
	/* 0xea7: setbe  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_BE);
x86_l_eab:
	/* 0xeab: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_eae:
	/* 0xeae: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_eb1:
	/* 0xeb1: cmp    eax,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 41ULL);
x86_l_eb4:
	/* 0xeb4: jb     f2c <filter_64ty_range+0x1cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f2c;
	}
x86_l_eb6:
	/* 0xeb6: cmp    QWORD PTR [rdi+0x30],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_eba:
	/* 0xeba: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_ebe:
	/* 0xebe: cmp    rsi,QWORD PTR [rdi+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_ec2:
	/* 0xec2: setbe  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_BE);
x86_l_ec6:
	/* 0xec6: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_ec9:
	/* 0xec9: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_ecc:
	/* 0xecc: cmp    eax,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 57ULL);
x86_l_ecf:
	/* 0xecf: jb     f2c <filter_64ty_range+0x1cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f2c;
	}
x86_l_ed1:
	/* 0xed1: cmp    QWORD PTR [rdi+0x40],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_ed5:
	/* 0xed5: setbe  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_BE);
x86_l_ed8:
	/* 0xed8: cmp    rsi,QWORD PTR [rdi+0x48] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 72ULL);
x86_l_edc:
	/* 0xedc: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_ee0:
	/* 0xee0: and    sil,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_ee3:
	/* 0xee3: or     dl,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_8, X86_ALU_OR);
x86_l_ee6:
	/* 0xee6: jmp    f2c <filter_64ty_range+0x1cc> */
	goto x86_l_f2c;
x86_l_ee8:
	/* 0xee8: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_eeb:
	/* 0xeeb: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_eee:
	/* 0xeee: jb     f2a <filter_64ty_range+0x1ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f2a;
	}
x86_l_ef0:
	/* 0xef0: cmp    QWORD PTR [rdi+0x20],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ef4:
	/* 0xef4: ja     efc <filter_64ty_range+0x19c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_efc;
	}
x86_l_ef6:
	/* 0xef6: cmp    rsi,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_efa:
	/* 0xefa: jbe    e7c <filter_64ty_range+0x11c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_e7c;
	}
x86_l_efc:
	/* 0xefc: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_eff:
	/* 0xeff: jb     f2a <filter_64ty_range+0x1ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f2a;
	}
x86_l_f01:
	/* 0xf01: cmp    QWORD PTR [rdi+0x30],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f05:
	/* 0xf05: ja     f11 <filter_64ty_range+0x1b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_f11;
	}
x86_l_f07:
	/* 0xf07: cmp    rsi,QWORD PTR [rdi+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_f0b:
	/* 0xf0b: jbe    e7c <filter_64ty_range+0x11c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_e7c;
	}
x86_l_f11:
	/* 0xf11: cmp    edx,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 57ULL);
x86_l_f14:
	/* 0xf14: jb     f2a <filter_64ty_range+0x1ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f2a;
	}
x86_l_f16:
	/* 0xf16: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f18:
	/* 0xf18: cmp    QWORD PTR [rdi+0x40],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_f1c:
	/* 0xf1c: ja     f2c <filter_64ty_range+0x1cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_f2c;
	}
x86_l_f1e:
	/* 0xf1e: cmp    rsi,QWORD PTR [rdi+0x48] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 72ULL);
x86_l_f22:
	/* 0xf22: jbe    e7c <filter_64ty_range+0x11c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_e7c;
	}
x86_l_f28:
	/* 0xf28: jmp    f2c <filter_64ty_range+0x1cc> */
	goto x86_l_f2c;
x86_l_f2a:
	/* 0xf2a: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f2c:
	/* 0xf2c: cmp    ecx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 32ULL);
x86_l_f2f:
	/* 0xf2f: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_f32:
	/* 0xf32: xor    dl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_f35:
	/* 0xf35: and    dl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_f37:
	/* 0xf37: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_f3a:
	/* 0xf3a: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_f3b:
	/* 0xf3b: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_f3d:
	/* 0xf3d: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_f3e:
	/* 0xf3e: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_f42:
	/* 0xf42: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_f45:
	/* 0xf45: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_f48:
	/* 0xf48: movzx  eax,BYTE PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_f4c:
	/* 0xf4c: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_f50:
	/* 0xf50: mov    rdi,QWORD PTR [rip+0x6e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_f57:
	/* 0xf57: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_f5c:
	/* 0xf5c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f61:
	/* 0xf61: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f63:
	/* 0xf63: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f66:
	/* 0xf66: je     f94 <filter_64ty_map+0x59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f94;
	}
x86_l_f68:
	/* 0xf68: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_f6b:
	/* 0xf6b: mov    rax,QWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f6e:
	/* 0xf6e: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f73:
	/* 0xf73: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f78:
	/* 0xf78: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f7d:
	/* 0xf7d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f7f:
	/* 0xf7f: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_f82:
	/* 0xf82: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_f85:
	/* 0xf85: je     f9e <filter_64ty_map+0x63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f9e;
	}
x86_l_f87:
	/* 0xf87: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_f8a:
	/* 0xf8a: jne    fa6 <filter_64ty_map+0x6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_fa6;
	}
x86_l_f8c:
	/* 0xf8c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f8f:
	/* 0xf8f: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_f92:
	/* 0xf92: jmp    fa8 <filter_64ty_map+0x6d> */
	goto x86_l_fa8;
x86_l_f94:
	/* 0xf94: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f96:
	/* 0xf96: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_f9a:
	/* 0xf9a: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_f9b:
	/* 0xf9b: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_f9d:
	/* 0xf9d: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_f9e:
	/* 0xf9e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fa1:
	/* 0xfa1: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_fa4:
	/* 0xfa4: jmp    fa8 <filter_64ty_map+0x6d> */
	goto x86_l_fa8;
x86_l_fa6:
	/* 0xfa6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fa8:
	/* 0xfa8: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_fab:
	/* 0xfab: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_faf:
	/* 0xfaf: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_fb0:
	/* 0xfb0: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_fb2:
	/* 0xfb2: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_fb3:
	/* 0xfb3: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_fb5:
	/* 0xfb5: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_fb7:
	/* 0xfb7: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_fb8:
	/* 0xfb8: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_fbc:
	/* 0xfbc: mov    ebx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDX, X86_WIDTH_32);
x86_l_fbe:
	/* 0xfbe: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_fc1:
	/* 0xfc1: mov    DWORD PTR [rsp+0xc],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_fc5:
	/* 0xfc5: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_fcd:
	/* 0xfcd: mov    rdi,QWORD PTR [rip+0x2040] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_fd4:
	/* 0xfd4: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_fd9:
	/* 0xfd9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fde:
	/* 0xfde: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fe0:
	/* 0xfe0: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_fe3:
	/* 0xfe3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fe5:
	/* 0xfe5: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_fe7:
	/* 0xfe7: je     10f1 <filter_char_buf_postfix+0x13e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4337ULL;
	}
x86_l_fed:
	/* 0xfed: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_ff0:
	/* 0xff0: je     10f1 <filter_char_buf_postfix+0x13e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4337ULL;
	}
x86_l_ff6:
	/* 0xff6: mov    rdi,QWORD PTR [rip+0x2040] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_ffd:
	/* 0xffd: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1002:
	/* 0x1002: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1007:
	/* 0x1007: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1009:
	/* 0x1009: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_100c:
	/* 0x100c: je     10ef <filter_char_buf_postfix+0x13c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4335ULL;
	}
x86_l_1012:
	/* 0x1012: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1015:
	/* 0x1015: cmp    ebx,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 127ULL);
x86_l_1018:
	/* 0x1018: mov    eax,0x7f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 127ULL);
x86_l_101d:
	/* 0x101d: cmovb  eax,ebx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RBX, X86_WIDTH_32, X86_CC_B);
x86_l_1020:
	/* 0x1020: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_1023:
	/* 0x1023: mov    DWORD PTR [rsi],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1025:
	/* 0x1025: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_1027:
	/* 0x1027: lea    ecx,[rbx-0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_102a:
	/* 0x102a: mov    rdx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_102d:
	/* 0x102d: add    rdx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 7ULL);
x86_l_1031:
	/* 0x1031: lea    edi,[rbx-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1034:
	/* 0x1034: lea    r8d,[rbx-0x2] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_1038:
	/* 0x1038: dec    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_103a:
	/* 0x103a: mov    r9,0xfffffffffffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 18446744073709551613ULL);
x86_l_1041:
	/* 0x1041: lea    r10d,[rbx+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_1045:
	/* 0x1045: add    r10d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_1049:
	/* 0x1049: and    r10d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1050:
	/* 0x1050: movzx  r10d,BYTE PTR [r14+r10*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R10, 0, X86_WIDTH_8), 0ULL);
x86_l_1055:
	/* 0x1055: mov    BYTE PTR [rdx-0x3],r10b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_R10, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1059:
	/* 0x1059: lea    r10,[rax+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_105d:
	/* 0x105d: cmp    r10,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_1061:
	/* 0x1061: je     10d8 <filter_char_buf_postfix+0x125> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4312ULL;
	}
x86_l_1063:
	/* 0x1063: lea    r11d,[r8+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_1067:
	/* 0x1067: add    r11d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_106b:
	/* 0x106b: and    r11d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1072:
	/* 0x1072: movzx  r11d,BYTE PTR [r14+r11*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R11, 0, X86_WIDTH_8), 0ULL);
x86_l_1077:
	/* 0x1077: mov    BYTE PTR [rdx-0x2],r11b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_R11, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_107b:
	/* 0x107b: cmp    r10,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_107f:
	/* 0x107f: je     10d8 <filter_char_buf_postfix+0x125> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4312ULL;
	}
x86_l_1081:
	/* 0x1081: lea    r10d,[rdi+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_1085:
	/* 0x1085: add    r10d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_1089:
	/* 0x1089: and    r10d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
	return 4240ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v61_generic_uprobe_filter_arg_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 4240ULL: goto x86_l_1090;
	case 4245ULL: goto x86_l_1095;
	case 4249ULL: goto x86_l_1099;
	case 4252ULL: goto x86_l_109c;
	case 4255ULL: goto x86_l_109f;
	case 4257ULL: goto x86_l_10a1;
	case 4261ULL: goto x86_l_10a5;
	case 4263ULL: goto x86_l_10a7;
	case 4267ULL: goto x86_l_10ab;
	case 4271ULL: goto x86_l_10af;
	case 4278ULL: goto x86_l_10b6;
	case 4283ULL: goto x86_l_10bb;
	case 4286ULL: goto x86_l_10be;
	case 4290ULL: goto x86_l_10c2;
	case 4294ULL: goto x86_l_10c6;
	case 4298ULL: goto x86_l_10ca;
	case 4302ULL: goto x86_l_10ce;
	case 4306ULL: goto x86_l_10d2;
	case 4312ULL: goto x86_l_10d8;
	case 4317ULL: goto x86_l_10dd;
	case 4320ULL: goto x86_l_10e0;
	case 4322ULL: goto x86_l_10e2;
	case 4325ULL: goto x86_l_10e5;
	case 4327ULL: goto x86_l_10e7;
	case 4330ULL: goto x86_l_10ea;
	case 4333ULL: goto x86_l_10ed;
	case 4335ULL: goto x86_l_10ef;
	case 4337ULL: goto x86_l_10f1;
	case 4341ULL: goto x86_l_10f5;
	case 4342ULL: goto x86_l_10f6;
	case 4344ULL: goto x86_l_10f8;
	case 4346ULL: goto x86_l_10fa;
	case 4347ULL: goto x86_l_10fb;
	case 4348ULL: goto x86_l_10fc;
	case 4350ULL: goto x86_l_10fe;
	case 4352ULL: goto x86_l_1100;
	case 4353ULL: goto x86_l_1101;
	case 4354ULL: goto x86_l_1102;
	case 4356ULL: goto x86_l_1104;
	case 4359ULL: goto x86_l_1107;
	case 4363ULL: goto x86_l_110b;
	case 4370ULL: goto x86_l_1112;
	case 4377ULL: goto x86_l_1119;
	case 4382ULL: goto x86_l_111e;
	case 4387ULL: goto x86_l_1123;
	case 4389ULL: goto x86_l_1125;
	case 4392ULL: goto x86_l_1128;
	case 4394ULL: goto x86_l_112a;
	case 4396ULL: goto x86_l_112c;
	case 4398ULL: goto x86_l_112e;
	case 4401ULL: goto x86_l_1131;
	case 4403ULL: goto x86_l_1133;
	case 4410ULL: goto x86_l_113a;
	case 4413ULL: goto x86_l_113d;
	case 4418ULL: goto x86_l_1142;
	case 4420ULL: goto x86_l_1144;
	case 4423ULL: goto x86_l_1147;
	case 4425ULL: goto x86_l_1149;
	case 4431ULL: goto x86_l_114f;
	case 4436ULL: goto x86_l_1154;
	case 4439ULL: goto x86_l_1157;
	case 4446ULL: goto x86_l_115e;
	case 4448ULL: goto x86_l_1160;
	case 4451ULL: goto x86_l_1163;
	case 4455ULL: goto x86_l_1167;
	case 4458ULL: goto x86_l_116a;
	case 4463ULL: goto x86_l_116f;
	case 4466ULL: goto x86_l_1172;
	case 4468ULL: goto x86_l_1174;
	case 4473ULL: goto x86_l_1179;
	case 4476ULL: goto x86_l_117c;
	case 4479ULL: goto x86_l_117f;
	case 4481ULL: goto x86_l_1181;
	case 4484ULL: goto x86_l_1184;
	case 4486ULL: goto x86_l_1186;
	case 4489ULL: goto x86_l_1189;
	case 4492ULL: goto x86_l_118c;
	case 4494ULL: goto x86_l_118e;
	case 4496ULL: goto x86_l_1190;
	case 4500ULL: goto x86_l_1194;
	case 4501ULL: goto x86_l_1195;
	case 4503ULL: goto x86_l_1197;
	case 4505ULL: goto x86_l_1199;
	case 4506ULL: goto x86_l_119a;
	case 4507ULL: goto x86_l_119b;
	case 4508ULL: goto x86_l_119c;
	case 4510ULL: goto x86_l_119e;
	case 4512ULL: goto x86_l_11a0;
	case 4514ULL: goto x86_l_11a2;
	case 4516ULL: goto x86_l_11a4;
	case 4517ULL: goto x86_l_11a5;
	case 4521ULL: goto x86_l_11a9;
	case 4529ULL: goto x86_l_11b1;
	case 4535ULL: goto x86_l_11b7;
	case 4541ULL: goto x86_l_11bd;
	case 4544ULL: goto x86_l_11c0;
	case 4549ULL: goto x86_l_11c5;
	case 4551ULL: goto x86_l_11c7;
	case 4554ULL: goto x86_l_11ca;
	case 4560ULL: goto x86_l_11d0;
	case 4563ULL: goto x86_l_11d3;
	case 4566ULL: goto x86_l_11d6;
	case 4569ULL: goto x86_l_11d9;
	case 4571ULL: goto x86_l_11db;
	case 4574ULL: goto x86_l_11de;
	case 4576ULL: goto x86_l_11e0;
	case 4578ULL: goto x86_l_11e2;
	case 4581ULL: goto x86_l_11e5;
	case 4583ULL: goto x86_l_11e7;
	case 4585ULL: goto x86_l_11e9;
	case 4588ULL: goto x86_l_11ec;
	case 4590ULL: goto x86_l_11ee;
	case 4592ULL: goto x86_l_11f0;
	case 4594ULL: goto x86_l_11f2;
	case 4597ULL: goto x86_l_11f5;
	case 4601ULL: goto x86_l_11f9;
	case 4605ULL: goto x86_l_11fd;
	case 4607ULL: goto x86_l_11ff;
	case 4610ULL: goto x86_l_1202;
	case 4613ULL: goto x86_l_1205;
	case 4620ULL: goto x86_l_120c;
	case 4624ULL: goto x86_l_1210;
	case 4627ULL: goto x86_l_1213;
	case 4632ULL: goto x86_l_1218;
	case 4638ULL: goto x86_l_121e;
	case 4643ULL: goto x86_l_1223;
	case 4645ULL: goto x86_l_1225;
	case 4651ULL: goto x86_l_122b;
	case 4656ULL: goto x86_l_1230;
	case 4658ULL: goto x86_l_1232;
	case 4664ULL: goto x86_l_1238;
	case 4669ULL: goto x86_l_123d;
	case 4671ULL: goto x86_l_123f;
	case 4674ULL: goto x86_l_1242;
	case 4679ULL: goto x86_l_1247;
	case 4683ULL: goto x86_l_124b;
	case 4687ULL: goto x86_l_124f;
	case 4694ULL: goto x86_l_1256;
	case 4701ULL: goto x86_l_125d;
	case 4707ULL: goto x86_l_1263;
	case 4710ULL: goto x86_l_1266;
	case 4712ULL: goto x86_l_1268;
	case 4714ULL: goto x86_l_126a;
	case 4716ULL: goto x86_l_126c;
	case 4719ULL: goto x86_l_126f;
	case 4721ULL: goto x86_l_1271;
	case 4727ULL: goto x86_l_1277;
	case 4729ULL: goto x86_l_1279;
	case 4732ULL: goto x86_l_127c;
	case 4734ULL: goto x86_l_127e;
	case 4737ULL: goto x86_l_1281;
	case 4739ULL: goto x86_l_1283;
	case 4745ULL: goto x86_l_1289;
	case 4747ULL: goto x86_l_128b;
	case 4753ULL: goto x86_l_1291;
	case 4755ULL: goto x86_l_1293;
	case 4761ULL: goto x86_l_1299;
	case 4763ULL: goto x86_l_129b;
	case 4769ULL: goto x86_l_12a1;
	case 4772ULL: goto x86_l_12a4;
	case 4775ULL: goto x86_l_12a7;
	case 4780ULL: goto x86_l_12ac;
	case 4784ULL: goto x86_l_12b0;
	case 4790ULL: goto x86_l_12b6;
	case 4795ULL: goto x86_l_12bb;
	case 4797ULL: goto x86_l_12bd;
	case 4804ULL: goto x86_l_12c4;
	case 4809ULL: goto x86_l_12c9;
	case 4814ULL: goto x86_l_12ce;
	case 4817ULL: goto x86_l_12d1;
	case 4819ULL: goto x86_l_12d3;
	case 4822ULL: goto x86_l_12d6;
	case 4829ULL: goto x86_l_12dd;
	case 4834ULL: goto x86_l_12e2;
	case 4837ULL: goto x86_l_12e5;
	case 4839ULL: goto x86_l_12e7;
	case 4842ULL: goto x86_l_12ea;
	case 4844ULL: goto x86_l_12ec;
	case 4849ULL: goto x86_l_12f1;
	case 4852ULL: goto x86_l_12f4;
	case 4858ULL: goto x86_l_12fa;
	case 4861ULL: goto x86_l_12fd;
	case 4867ULL: goto x86_l_1303;
	case 4872ULL: goto x86_l_1308;
	case 4876ULL: goto x86_l_130c;
	case 4878ULL: goto x86_l_130e;
	case 4883ULL: goto x86_l_1313;
	case 4886ULL: goto x86_l_1316;
	case 4890ULL: goto x86_l_131a;
	case 4893ULL: goto x86_l_131d;
	case 4898ULL: goto x86_l_1322;
	case 4903ULL: goto x86_l_1327;
	case 4905ULL: goto x86_l_1329;
	case 4907ULL: goto x86_l_132b;
	case 4910ULL: goto x86_l_132e;
	case 4912ULL: goto x86_l_1330;
	case 4917ULL: goto x86_l_1335;
	case 4921ULL: goto x86_l_1339;
	case 4924ULL: goto x86_l_133c;
	case 4931ULL: goto x86_l_1343;
	case 4936ULL: goto x86_l_1348;
	case 4941ULL: goto x86_l_134d;
	case 4943ULL: goto x86_l_134f;
	case 4948ULL: goto x86_l_1354;
	case 4951ULL: goto x86_l_1357;
	case 4955ULL: goto x86_l_135b;
	case 4958ULL: goto x86_l_135e;
	case 4963ULL: goto x86_l_1363;
	case 4968ULL: goto x86_l_1368;
	case 4970ULL: goto x86_l_136a;
	case 4972ULL: goto x86_l_136c;
	case 4975ULL: goto x86_l_136f;
	case 4977ULL: goto x86_l_1371;
	case 4982ULL: goto x86_l_1376;
	case 4986ULL: goto x86_l_137a;
	case 4990ULL: goto x86_l_137e;
	case 4997ULL: goto x86_l_1385;
	case 5002ULL: goto x86_l_138a;
	case 5007ULL: goto x86_l_138f;
	case 5010ULL: goto x86_l_1392;
	case 5012ULL: goto x86_l_1394;
	case 5017ULL: goto x86_l_1399;
	case 5021ULL: goto x86_l_139d;
	case 5023ULL: goto x86_l_139f;
	case 5027ULL: goto x86_l_13a3;
	case 5029ULL: goto x86_l_13a5;
	case 5033ULL: goto x86_l_13a9;
	case 5039ULL: goto x86_l_13af;
	case 5043ULL: goto x86_l_13b3;
	case 5049ULL: goto x86_l_13b9;
	case 5053ULL: goto x86_l_13bd;
	case 5059ULL: goto x86_l_13c3;
	case 5066ULL: goto x86_l_13ca;
	case 5071ULL: goto x86_l_13cf;
	case 5076ULL: goto x86_l_13d4;
	case 5081ULL: goto x86_l_13d9;
	case 5085ULL: goto x86_l_13dd;
	case 5087ULL: goto x86_l_13df;
	case 5091ULL: goto x86_l_13e3;
	case 5097ULL: goto x86_l_13e9;
	case 5101ULL: goto x86_l_13ed;
	case 5107ULL: goto x86_l_13f3;
	case 5111ULL: goto x86_l_13f7;
	case 5117ULL: goto x86_l_13fd;
	case 5124ULL: goto x86_l_1404;
	case 5129ULL: goto x86_l_1409;
	case 5134ULL: goto x86_l_140e;
	case 5139ULL: goto x86_l_1413;
	case 5143ULL: goto x86_l_1417;
	case 5149ULL: goto x86_l_141d;
	case 5153ULL: goto x86_l_1421;
	case 5159ULL: goto x86_l_1427;
	case 5163ULL: goto x86_l_142b;
	case 5169ULL: goto x86_l_1431;
	case 5176ULL: goto x86_l_1438;
	case 5181ULL: goto x86_l_143d;
	case 5186ULL: goto x86_l_1442;
	case 5191ULL: goto x86_l_1447;
	case 5194ULL: goto x86_l_144a;
	case 5196ULL: goto x86_l_144c;
	case 5200ULL: goto x86_l_1450;
	case 5206ULL: goto x86_l_1456;
	case 5213ULL: goto x86_l_145d;
	case 5218ULL: goto x86_l_1462;
	case 5223ULL: goto x86_l_1467;
	case 5228ULL: goto x86_l_146c;
	case 5235ULL: goto x86_l_1473;
	case 5240ULL: goto x86_l_1478;
	case 5245ULL: goto x86_l_147d;
	case 5247ULL: goto x86_l_147f;
	case 5254ULL: goto x86_l_1486;
	case 5259ULL: goto x86_l_148b;
	case 5264ULL: goto x86_l_1490;
	case 5266ULL: goto x86_l_1492;
	case 5273ULL: goto x86_l_1499;
	case 5278ULL: goto x86_l_149e;
	case 5283ULL: goto x86_l_14a3;
	case 5285ULL: goto x86_l_14a5;
	case 5292ULL: goto x86_l_14ac;
	case 5297ULL: goto x86_l_14b1;
	case 5302ULL: goto x86_l_14b6;
	case 5304ULL: goto x86_l_14b8;
	case 5311ULL: goto x86_l_14bf;
	case 5316ULL: goto x86_l_14c4;
	case 5321ULL: goto x86_l_14c9;
	case 5323ULL: goto x86_l_14cb;
	case 5330ULL: goto x86_l_14d2;
	case 5335ULL: goto x86_l_14d7;
	case 5340ULL: goto x86_l_14dc;
	case 5342ULL: goto x86_l_14de;
	case 5349ULL: goto x86_l_14e5;
	case 5354ULL: goto x86_l_14ea;
	case 5359ULL: goto x86_l_14ef;
	case 5364ULL: goto x86_l_14f4;
	case 5366ULL: goto x86_l_14f6;
	case 5369ULL: goto x86_l_14f9;
	case 5371ULL: goto x86_l_14fb;
	case 5374ULL: goto x86_l_14fe;
	case 5379ULL: goto x86_l_1503;
	case 5384ULL: goto x86_l_1508;
	case 5386ULL: goto x86_l_150a;
	case 5389ULL: goto x86_l_150d;
	case 5391ULL: goto x86_l_150f;
	case 5394ULL: goto x86_l_1512;
	case 5397ULL: goto x86_l_1515;
	case 5399ULL: goto x86_l_1517;
	case 5401ULL: goto x86_l_1519;
	case 5405ULL: goto x86_l_151d;
	case 5406ULL: goto x86_l_151e;
	case 5408ULL: goto x86_l_1520;
	case 5410ULL: goto x86_l_1522;
	case 5412ULL: goto x86_l_1524;
	case 5414ULL: goto x86_l_1526;
	case 5415ULL: goto x86_l_1527;
	case 5416ULL: goto x86_l_1528;
	case 5417ULL: goto x86_l_1529;
	case 5419ULL: goto x86_l_152b;
	case 5421ULL: goto x86_l_152d;
	case 5423ULL: goto x86_l_152f;
	case 5425ULL: goto x86_l_1531;
	case 5426ULL: goto x86_l_1532;
	case 5427ULL: goto x86_l_1533;
	case 5430ULL: goto x86_l_1536;
	case 5433ULL: goto x86_l_1539;
	case 5435ULL: goto x86_l_153b;
	case 5437ULL: goto x86_l_153d;
	case 5443ULL: goto x86_l_1543;
	case 5445ULL: goto x86_l_1545;
	case 5451ULL: goto x86_l_154b;
	case 5456ULL: goto x86_l_1550;
	case 5458ULL: goto x86_l_1552;
	case 5461ULL: goto x86_l_1555;
	case 5466ULL: goto x86_l_155a;
	case 5470ULL: goto x86_l_155e;
	case 5475ULL: goto x86_l_1563;
	case 5482ULL: goto x86_l_156a;
	case 5485ULL: goto x86_l_156d;
	case 5487ULL: goto x86_l_156f;
	case 5490ULL: goto x86_l_1572;
	case 5496ULL: goto x86_l_1578;
	case 5499ULL: goto x86_l_157b;
	case 5501ULL: goto x86_l_157d;
	case 5503ULL: goto x86_l_157f;
	case 5506ULL: goto x86_l_1582;
	case 5509ULL: goto x86_l_1585;
	case 5512ULL: goto x86_l_1588;
	case 5514ULL: goto x86_l_158a;
	case 5516ULL: goto x86_l_158c;
	case 5520ULL: goto x86_l_1590;
	case 5523ULL: goto x86_l_1593;
	case 5525ULL: goto x86_l_1595;
	case 5529ULL: goto x86_l_1599;
	case 5531ULL: goto x86_l_159b;
	case 5533ULL: goto x86_l_159d;
	case 5538ULL: goto x86_l_15a2;
	case 5542ULL: goto x86_l_15a6;
	case 5545ULL: goto x86_l_15a9;
	case 5549ULL: goto x86_l_15ad;
	case 5553ULL: goto x86_l_15b1;
	case 5557ULL: goto x86_l_15b5;
	case 5561ULL: goto x86_l_15b9;
	case 5564ULL: goto x86_l_15bc;
	case 5568ULL: goto x86_l_15c0;
	case 5572ULL: goto x86_l_15c4;
	case 5576ULL: goto x86_l_15c8;
	case 5580ULL: goto x86_l_15cc;
	case 5582ULL: goto x86_l_15ce;
	case 5585ULL: goto x86_l_15d1;
	case 5588ULL: goto x86_l_15d4;
	case 5590ULL: goto x86_l_15d6;
	case 5592ULL: goto x86_l_15d8;
	case 5594ULL: goto x86_l_15da;
	case 5600ULL: goto x86_l_15e0;
	case 5605ULL: goto x86_l_15e5;
	case 5609ULL: goto x86_l_15e9;
	case 5615ULL: goto x86_l_15ef;
	case 5619ULL: goto x86_l_15f3;
	case 5622ULL: goto x86_l_15f6;
	case 5626ULL: goto x86_l_15fa;
	case 5632ULL: goto x86_l_1600;
	case 5637ULL: goto x86_l_1605;
	case 5639ULL: goto x86_l_1607;
	case 5645ULL: goto x86_l_160d;
	case 5650ULL: goto x86_l_1612;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1090:
	/* 0x1090: movzx  r10d,BYTE PTR [r14+r10*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R10, 0, X86_WIDTH_8), 0ULL);
x86_l_1095:
	/* 0x1095: mov    BYTE PTR [rdx-0x1],r10b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_R10, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1099:
	/* 0x1099: mov    r10,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_RAX, X86_WIDTH_64);
x86_l_109c:
	/* 0x109c: add    r10,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R9, X86_WIDTH_64, X86_ALU_ADD);
x86_l_109f:
	/* 0x109f: je     10d8 <filter_char_buf_postfix+0x125> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10d8;
	}
x86_l_10a1:
	/* 0x10a1: cmp    r9,0xffffffffffffff81 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_64, 18446744073709551489ULL);
x86_l_10a5:
	/* 0x10a5: je     10d8 <filter_char_buf_postfix+0x125> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10d8;
	}
x86_l_10a7:
	/* 0x10a7: lea    r10d,[rcx+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_10ab:
	/* 0x10ab: add    r10d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_10af:
	/* 0x10af: and    r10d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_10b6:
	/* 0x10b6: movzx  r10d,BYTE PTR [r14+r10*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R10, 0, X86_WIDTH_8), 0ULL);
x86_l_10bb:
	/* 0x10bb: mov    BYTE PTR [rdx],r10b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_R10, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10be:
	/* 0x10be: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_10c2:
	/* 0x10c2: lea    r10,[rax+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_10c6:
	/* 0x10c6: add    r10,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_10ca:
	/* 0x10ca: add    r9,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_10ce:
	/* 0x10ce: cmp    r10,0xfffffffffffffffd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_64, 18446744073709551613ULL);
x86_l_10d2:
	/* 0x10d2: jne    1041 <filter_char_buf_postfix+0x8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4161ULL;
	}
x86_l_10d8:
	/* 0x10d8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10dd:
	/* 0x10dd: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_10e0:
	/* 0x10e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10e2:
	/* 0x10e2: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_10e5:
	/* 0x10e5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10e7:
	/* 0x10e7: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_10ea:
	/* 0x10ea: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_10ed:
	/* 0x10ed: jmp    10f1 <filter_char_buf_postfix+0x13e> */
	goto x86_l_10f1;
x86_l_10ef:
	/* 0x10ef: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10f1:
	/* 0x10f1: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_10f5:
	/* 0x10f5: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_10f6:
	/* 0x10f6: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_10f8:
	/* 0x10f8: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_10fa:
	/* 0x10fa: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_10fb:
	/* 0x10fb: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_10fc:
	/* 0x10fc: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_10fe:
	/* 0x10fe: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_1100:
	/* 0x1100: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_1101:
	/* 0x1101: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_1102:
	/* 0x1102: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_1104:
	/* 0x1104: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_1107:
	/* 0x1107: mov    DWORD PTR [rsp+0x4],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_110b:
	/* 0x110b: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1112:
	/* 0x1112: mov    rdi,QWORD PTR [rip+0x1fa0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_1119:
	/* 0x1119: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_111e:
	/* 0x111e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1123:
	/* 0x1123: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1125:
	/* 0x1125: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_1128:
	/* 0x1128: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_112a:
	/* 0x112a: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_112c:
	/* 0x112c: je     1190 <filter_char_buf_prefix+0x95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1190;
	}
x86_l_112e:
	/* 0x112e: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_1131:
	/* 0x1131: je     1190 <filter_char_buf_prefix+0x95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1190;
	}
x86_l_1133:
	/* 0x1133: mov    rdi,QWORD PTR [rip+0x1fa0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_113a:
	/* 0x113a: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_113d:
	/* 0x113d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1142:
	/* 0x1142: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1144:
	/* 0x1144: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1147:
	/* 0x1147: je     118e <filter_char_buf_prefix+0x93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_118e;
	}
x86_l_1149:
	/* 0x1149: cmp    ebp,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 255ULL);
x86_l_114f:
	/* 0x114f: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_1154:
	/* 0x1154: cmovb  esi,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RBP, X86_WIDTH_32, X86_CC_B);
x86_l_1157:
	/* 0x1157: lea    ecx,[rsi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_115e:
	/* 0x115e: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1160:
	/* 0x1160: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1163:
	/* 0x1163: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1167:
	/* 0x1167: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_116a:
	/* 0x116a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_116f:
	/* 0x116f: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1172:
	/* 0x1172: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1174:
	/* 0x1174: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1179:
	/* 0x1179: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_117c:
	/* 0x117c: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_117f:
	/* 0x117f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1181:
	/* 0x1181: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1184:
	/* 0x1184: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1186:
	/* 0x1186: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_1189:
	/* 0x1189: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_118c:
	/* 0x118c: jmp    1190 <filter_char_buf_prefix+0x95> */
	goto x86_l_1190;
x86_l_118e:
	/* 0x118e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1190:
	/* 0x1190: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1194:
	/* 0x1194: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1195:
	/* 0x1195: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_1197:
	/* 0x1197: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_1199:
	/* 0x1199: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_119a:
	/* 0x119a: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_119b:
	/* 0x119b: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_119c:
	/* 0x119c: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_119e:
	/* 0x119e: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_11a0:
	/* 0x11a0: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_11a2:
	/* 0x11a2: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_11a4:
	/* 0x11a4: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_11a5:
	/* 0x11a5: sub    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 40ULL);
x86_l_11a9:
	/* 0x11a9: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_11b1:
	/* 0x11b1: cmp    edx,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4096ULL);
x86_l_11b7:
	/* 0x11b7: ja     1517 <filter_char_buf_equal+0x37c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1517;
	}
x86_l_11bd:
	/* 0x11bd: movzx  eax,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_11c0:
	/* 0x11c0: cmp    eax,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_11c5:
	/* 0x11c5: ja     1218 <filter_char_buf_equal+0x7d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1218;
	}
x86_l_11c7:
	/* 0x11c7: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_11ca:
	/* 0x11ca: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_11d0:
	/* 0x11d0: shr    ecx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_11d3:
	/* 0x11d3: and    ecx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_11d6:
	/* 0x11d6: lea    ecx,[rcx+rcx*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 1), 0ULL);
x86_l_11d9:
	/* 0x11d9: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_11db:
	/* 0x11db: test   dx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_16);
x86_l_11de:
	/* 0x11de: je     11e9 <filter_char_buf_equal+0x4e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11e9;
	}
x86_l_11e0:
	/* 0x11e0: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_11e2:
	/* 0x11e2: mov    r14d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_32);
x86_l_11e5:
	/* 0x11e5: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_11e7:
	/* 0x11e7: je     1202 <filter_char_buf_equal+0x67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1202;
	}
x86_l_11e9:
	/* 0x11e9: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_11ec:
	/* 0x11ec: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_11ee:
	/* 0x11ee: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_11f0:
	/* 0x11f0: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_11f2:
	/* 0x11f2: add    eax,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_11f5:
	/* 0x11f5: movzx  r14d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_11f9:
	/* 0x11f9: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_11fd:
	/* 0x11fd: ja     1256 <filter_char_buf_equal+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1256;
	}
x86_l_11ff:
	/* 0x11ff: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_1202:
	/* 0x1202: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1205:
	/* 0x1205: imul   r12d,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_R12, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_120c:
	/* 0x120c: shr    r12d,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_1210:
	/* 0x1210: dec    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_1213:
	/* 0x1213: jmp    12a1 <filter_char_buf_equal+0x106> */
	goto x86_l_12a1;
x86_l_1218:
	/* 0x1218: mov    r14d,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 256ULL);
x86_l_121e:
	/* 0x121e: cmp    eax,0x101 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 257ULL);
x86_l_1223:
	/* 0x1223: jb     1256 <filter_char_buf_equal+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1256;
	}
x86_l_1225:
	/* 0x1225: mov    r14d,0x200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 512ULL);
x86_l_122b:
	/* 0x122b: cmp    eax,0x201 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 513ULL);
x86_l_1230:
	/* 0x1230: jb     1256 <filter_char_buf_equal+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1256;
	}
x86_l_1232:
	/* 0x1232: mov    r14d,0x400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1024ULL);
x86_l_1238:
	/* 0x1238: cmp    eax,0x401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1025ULL);
x86_l_123d:
	/* 0x123d: jb     1256 <filter_char_buf_equal+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1256;
	}
x86_l_123f:
	/* 0x123f: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1242:
	/* 0x1242: cmp    eax,0x801 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2049ULL);
x86_l_1247:
	/* 0x1247: setae  r14b */
	X86_SIM_L_EXEC_SETCC(X86_R14, X86_CC_AE);
x86_l_124b:
	/* 0x124b: shl    r14d,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHL, 11ULL);
x86_l_124f:
	/* 0x124f: add    r14d,0x800 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 2048ULL);
x86_l_1256:
	/* 0x1256: lea    eax,[r14-0x100] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551360ULL);
x86_l_125d:
	/* 0x125d: rorx   eax,eax,0x8 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 8ULL);
x86_l_1263:
	/* 0x1263: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1266:
	/* 0x1266: jg     1279 <filter_char_buf_equal+0xde> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1279;
	}
x86_l_1268:
	/* 0x1268: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_126a:
	/* 0x126a: je     1293 <filter_char_buf_equal+0xf8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1293;
	}
x86_l_126c:
	/* 0x126c: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_126f:
	/* 0x126f: jne    128b <filter_char_buf_equal+0xf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_128b;
	}
x86_l_1271:
	/* 0x1271: mov    r12d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 7ULL);
x86_l_1277:
	/* 0x1277: jmp    12a1 <filter_char_buf_equal+0x106> */
	goto x86_l_12a1;
x86_l_1279:
	/* 0x1279: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_127c:
	/* 0x127c: je     129b <filter_char_buf_equal+0x100> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_129b;
	}
x86_l_127e:
	/* 0x127e: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_1281:
	/* 0x1281: jne    128b <filter_char_buf_equal+0xf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_128b;
	}
x86_l_1283:
	/* 0x1283: mov    r12d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 9ULL);
x86_l_1289:
	/* 0x1289: jmp    12a1 <filter_char_buf_equal+0x106> */
	goto x86_l_12a1;
x86_l_128b:
	/* 0x128b: mov    r12d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 10ULL);
x86_l_1291:
	/* 0x1291: jmp    12a1 <filter_char_buf_equal+0x106> */
	goto x86_l_12a1;
x86_l_1293:
	/* 0x1293: mov    r12d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 6ULL);
x86_l_1299:
	/* 0x1299: jmp    12a1 <filter_char_buf_equal+0x106> */
	goto x86_l_12a1;
x86_l_129b:
	/* 0x129b: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_12a1:
	/* 0x12a1: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_12a4:
	/* 0x12a4: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_12a7:
	/* 0x12a7: mov    r13d,DWORD PTR [rdi+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_12ac:
	/* 0x12ac: cmp    r13d,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4294967295ULL);
x86_l_12b0:
	/* 0x12b0: je     1517 <filter_char_buf_equal+0x37c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1517;
	}
x86_l_12b6:
	/* 0x12b6: mov    QWORD PTR [rsp+0x20],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_12bb:
	/* 0x12bb: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_12bd:
	/* 0x12bd: mov    rdi,QWORD PTR [rip+0x1c10] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_12c4:
	/* 0x12c4: lea    r15,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_12c9:
	/* 0x12c9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12ce:
	/* 0x12ce: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_12d1:
	/* 0x12d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12d3:
	/* 0x12d3: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_12d6:
	/* 0x12d6: mov    rdi,QWORD PTR [rip+0x1c10] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_12dd:
	/* 0x12dd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12e2:
	/* 0x12e2: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_12e5:
	/* 0x12e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12e7:
	/* 0x12e7: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_12ea:
	/* 0x12ea: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12ec:
	/* 0x12ec: mov    QWORD PTR [rsp+0x8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12f1:
	/* 0x12f1: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_12f4:
	/* 0x12f4: je     1519 <filter_char_buf_equal+0x37e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1519;
	}
x86_l_12fa:
	/* 0x12fa: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_12fd:
	/* 0x12fd: je     1519 <filter_char_buf_equal+0x37e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1519;
	}
x86_l_1303:
	/* 0x1303: mov    QWORD PTR [rsp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1308:
	/* 0x1308: cmp    r12d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 5ULL);
x86_l_130c:
	/* 0x130c: jg     134f <filter_char_buf_equal+0x1b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_134f;
	}
x86_l_130e:
	/* 0x130e: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1313:
	/* 0x1313: mov    BYTE PTR [rax],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1316:
	/* 0x1316: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_131a:
	/* 0x131a: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_131d:
	/* 0x131d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1322:
	/* 0x1322: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1327:
	/* 0x1327: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_1329:
	/* 0x1329: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_132b:
	/* 0x132b: sub    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_132e:
	/* 0x132e: jbe    1394 <filter_char_buf_equal+0x1f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1394;
	}
x86_l_1330:
	/* 0x1330: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1335:
	/* 0x1335: lea    rdi,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_1339:
	/* 0x1339: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_133c:
	/* 0x133c: and    r14d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1343:
	/* 0x1343: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1348:
	/* 0x1348: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_134d:
	/* 0x134d: jmp    138f <filter_char_buf_equal+0x1f4> */
	goto x86_l_138f;
x86_l_134f:
	/* 0x134f: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1354:
	/* 0x1354: mov    WORD PTR [rax],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1357:
	/* 0x1357: lea    rdi,[rax+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_135b:
	/* 0x135b: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_135e:
	/* 0x135e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1363:
	/* 0x1363: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1368:
	/* 0x1368: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_136a:
	/* 0x136a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_136c:
	/* 0x136c: sub    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_136f:
	/* 0x136f: jbe    1394 <filter_char_buf_equal+0x1f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1394;
	}
x86_l_1371:
	/* 0x1371: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1376:
	/* 0x1376: lea    rdi,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_137a:
	/* 0x137a: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_137e:
	/* 0x137e: and    r14d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1385:
	/* 0x1385: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_138a:
	/* 0x138a: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_138f:
	/* 0x138f: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_1392:
	/* 0x1392: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1394:
	/* 0x1394: mov    DWORD PTR [rsp+0x4],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1399:
	/* 0x1399: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_139d:
	/* 0x139d: jle    13d9 <filter_char_buf_equal+0x23e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_13d9;
	}
x86_l_139f:
	/* 0x139f: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_13a3:
	/* 0x13a3: jg     1413 <filter_char_buf_equal+0x278> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1413;
	}
x86_l_13a5:
	/* 0x13a5: cmp    r12d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 5ULL);
x86_l_13a9:
	/* 0x13a9: je     14cb <filter_char_buf_equal+0x330> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14cb;
	}
x86_l_13af:
	/* 0x13af: cmp    r12d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 6ULL);
x86_l_13b3:
	/* 0x13b3: je     1492 <filter_char_buf_equal+0x2f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1492;
	}
x86_l_13b9:
	/* 0x13b9: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_13bd:
	/* 0x13bd: jne    1517 <filter_char_buf_equal+0x37c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1517;
	}
x86_l_13c3:
	/* 0x13c3: mov    rdi,QWORD PTR [rip+0x1c10] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_7)));
x86_l_13ca:
	/* 0x13ca: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_13cf:
	/* 0x13cf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13d4:
	/* 0x13d4: jmp    14ef <filter_char_buf_equal+0x354> */
	goto x86_l_14ef;
x86_l_13d9:
	/* 0x13d9: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_13dd:
	/* 0x13dd: jle    1447 <filter_char_buf_equal+0x2ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1447;
	}
x86_l_13df:
	/* 0x13df: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_13e3:
	/* 0x13e3: je     14b8 <filter_char_buf_equal+0x31d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14b8;
	}
x86_l_13e9:
	/* 0x13e9: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_13ed:
	/* 0x13ed: je     147f <filter_char_buf_equal+0x2e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_147f;
	}
x86_l_13f3:
	/* 0x13f3: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_13f7:
	/* 0x13f7: jne    1517 <filter_char_buf_equal+0x37c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1517;
	}
x86_l_13fd:
	/* 0x13fd: mov    rdi,QWORD PTR [rip+0x1c10] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_1404:
	/* 0x1404: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1409:
	/* 0x1409: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_140e:
	/* 0x140e: jmp    14ef <filter_char_buf_equal+0x354> */
	goto x86_l_14ef;
x86_l_1413:
	/* 0x1413: cmp    r12d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 8ULL);
x86_l_1417:
	/* 0x1417: je     14de <filter_char_buf_equal+0x343> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14de;
	}
x86_l_141d:
	/* 0x141d: cmp    r12d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 9ULL);
x86_l_1421:
	/* 0x1421: je     14a5 <filter_char_buf_equal+0x30a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14a5;
	}
x86_l_1427:
	/* 0x1427: cmp    r12d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 10ULL);
x86_l_142b:
	/* 0x142b: jne    1517 <filter_char_buf_equal+0x37c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1517;
	}
x86_l_1431:
	/* 0x1431: mov    rdi,QWORD PTR [rip+0x1c0c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_10)));
x86_l_1438:
	/* 0x1438: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_143d:
	/* 0x143d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1442:
	/* 0x1442: jmp    14ef <filter_char_buf_equal+0x354> */
	goto x86_l_14ef;
x86_l_1447:
	/* 0x1447: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_144a:
	/* 0x144a: je     146c <filter_char_buf_equal+0x2d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_146c;
	}
x86_l_144c:
	/* 0x144c: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_1450:
	/* 0x1450: jne    1517 <filter_char_buf_equal+0x37c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1517;
	}
x86_l_1456:
	/* 0x1456: mov    rdi,QWORD PTR [rip+0x1c0c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_145d:
	/* 0x145d: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1462:
	/* 0x1462: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1467:
	/* 0x1467: jmp    14ef <filter_char_buf_equal+0x354> */
	goto x86_l_14ef;
x86_l_146c:
	/* 0x146c: mov    rdi,QWORD PTR [rip+0x1c0c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_1473:
	/* 0x1473: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1478:
	/* 0x1478: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_147d:
	/* 0x147d: jmp    14ef <filter_char_buf_equal+0x354> */
	goto x86_l_14ef;
x86_l_147f:
	/* 0x147f: mov    rdi,QWORD PTR [rip+0x1c0c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_1486:
	/* 0x1486: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_148b:
	/* 0x148b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1490:
	/* 0x1490: jmp    14ef <filter_char_buf_equal+0x354> */
	goto x86_l_14ef;
x86_l_1492:
	/* 0x1492: mov    rdi,QWORD PTR [rip+0x1c0c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_6)));
x86_l_1499:
	/* 0x1499: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_149e:
	/* 0x149e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14a3:
	/* 0x14a3: jmp    14ef <filter_char_buf_equal+0x354> */
	goto x86_l_14ef;
x86_l_14a5:
	/* 0x14a5: mov    rdi,QWORD PTR [rip+0x1c0c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_9)));
x86_l_14ac:
	/* 0x14ac: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_14b1:
	/* 0x14b1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14b6:
	/* 0x14b6: jmp    14ef <filter_char_buf_equal+0x354> */
	goto x86_l_14ef;
x86_l_14b8:
	/* 0x14b8: mov    rdi,QWORD PTR [rip+0x1c0c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_14bf:
	/* 0x14bf: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_14c4:
	/* 0x14c4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14c9:
	/* 0x14c9: jmp    14ef <filter_char_buf_equal+0x354> */
	goto x86_l_14ef;
x86_l_14cb:
	/* 0x14cb: mov    rdi,QWORD PTR [rip+0x1c0c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_14d2:
	/* 0x14d2: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_14d7:
	/* 0x14d7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14dc:
	/* 0x14dc: jmp    14ef <filter_char_buf_equal+0x354> */
	goto x86_l_14ef;
x86_l_14de:
	/* 0x14de: mov    rdi,QWORD PTR [rip+0x1c0c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_8)));
x86_l_14e5:
	/* 0x14e5: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_14ea:
	/* 0x14ea: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14ef:
	/* 0x14ef: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_14f4:
	/* 0x14f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14f6:
	/* 0x14f6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14f9:
	/* 0x14f9: je     1517 <filter_char_buf_equal+0x37c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1517;
	}
x86_l_14fb:
	/* 0x14fb: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_14fe:
	/* 0x14fe: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1503:
	/* 0x1503: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1508:
	/* 0x1508: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_150a:
	/* 0x150a: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_150d:
	/* 0x150d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_150f:
	/* 0x150f: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_1512:
	/* 0x1512: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_1515:
	/* 0x1515: jmp    1519 <filter_char_buf_equal+0x37e> */
	goto x86_l_1519;
x86_l_1517:
	/* 0x1517: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1519:
	/* 0x1519: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_151d:
	/* 0x151d: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_151e:
	/* 0x151e: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1520:
	/* 0x1520: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_1522:
	/* 0x1522: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_1524:
	/* 0x1524: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_1526:
	/* 0x1526: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1527:
	/* 0x1527: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1528:
	/* 0x1528: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1529:
	/* 0x1529: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_152b:
	/* 0x152b: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_152d:
	/* 0x152d: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_152f:
	/* 0x152f: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_1531:
	/* 0x1531: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_1532:
	/* 0x1532: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_1533:
	/* 0x1533: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_1536:
	/* 0x1536: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_1539:
	/* 0x1539: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_153b:
	/* 0x153b: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_153d:
	/* 0x153d: je     1605 <filter_char_substring+0xdd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1605;
	}
x86_l_1543:
	/* 0x1543: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_1545:
	/* 0x1545: je     16a2 <filter_char_substring+0x17a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5794ULL;
	}
x86_l_154b:
	/* 0x154b: lea    r13,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1550:
	/* 0x1550: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1552:
	/* 0x1552: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1555:
	/* 0x1555: mov    eax,DWORD PTR [r14+rbx*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_155a:
	/* 0x155a: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_155e:
	/* 0x155e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1563:
	/* 0x1563: mov    rdi,QWORD PTR [rip+0x2243] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_156a:
	/* 0x156a: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_156d:
	/* 0x156d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_156f:
	/* 0x156f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1572:
	/* 0x1572: je     1726 <filter_char_substring+0x1fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5926ULL;
	}
x86_l_1578:
	/* 0x1578: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_157b:
	/* 0x157b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_157d:
	/* 0x157d: jmp    158a <filter_char_substring+0x62> */
	goto x86_l_158a;
x86_l_157f:
	/* 0x157f: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1582:
	/* 0x1582: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1585:
	/* 0x1585: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_1588:
	/* 0x1588: je     15e0 <filter_char_substring+0xb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15e0;
	}
x86_l_158a:
	/* 0x158a: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_158c:
	/* 0x158c: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_1590:
	/* 0x1590: cmp    rdi,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1593:
	/* 0x1593: jae    157f <filter_char_substring+0x57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_157f;
	}
x86_l_1595:
	/* 0x1595: movsx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_1599:
	/* 0x1599: test   edi,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_32);
x86_l_159b:
	/* 0x159b: je     15d8 <filter_char_substring+0xb0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15d8;
	}
x86_l_159d:
	/* 0x159d: movsx  r9d,BYTE PTR [rdx+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R9, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_15a2:
	/* 0x15a2: lea    r10d,[r9-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_15a6:
	/* 0x15a6: mov    r8d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R9, X86_WIDTH_32);
x86_l_15a9:
	/* 0x15a9: or     r8d,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_15ad:
	/* 0x15ad: cmp    r10d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 26ULL);
x86_l_15b1:
	/* 0x15b1: cmovae r8d,r9d */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_R9, X86_WIDTH_32, X86_CC_AE);
x86_l_15b5:
	/* 0x15b5: lea    r10d,[rdi-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_15b9:
	/* 0x15b9: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_15bc:
	/* 0x15bc: or     r9d,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_15c0:
	/* 0x15c0: cmp    r10d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 26ULL);
x86_l_15c4:
	/* 0x15c4: cmovae r9d,edi */
	X86_SIM_L_EXEC_CMOV(X86_R9, X86_RDI, X86_WIDTH_32, X86_CC_AE);
x86_l_15c8:
	/* 0x15c8: cmp    rsi,0x62 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 98ULL);
x86_l_15cc:
	/* 0x15cc: ja     157f <filter_char_substring+0x57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_157f;
	}
x86_l_15ce:
	/* 0x15ce: inc    rsi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_15d1:
	/* 0x15d1: cmp    r8d,r9d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_R9, X86_WIDTH_32);
x86_l_15d4:
	/* 0x15d4: je     158c <filter_char_substring+0x64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_158c;
	}
x86_l_15d6:
	/* 0x15d6: jmp    157f <filter_char_substring+0x57> */
	goto x86_l_157f;
x86_l_15d8:
	/* 0x15d8: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_15da:
	/* 0x15da: jns    1737 <filter_char_substring+0x20f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 5943ULL;
	}
x86_l_15e0:
	/* 0x15e0: lea    eax,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_15e5:
	/* 0x15e5: cmp    eax,DWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_15e9:
	/* 0x15e9: jae    1726 <filter_char_substring+0x1fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 5926ULL;
	}
x86_l_15ef:
	/* 0x15ef: add    r12d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_15f3:
	/* 0x15f3: inc    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_15f6:
	/* 0x15f6: cmp    rbx,0x64 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 100ULL);
x86_l_15fa:
	/* 0x15fa: jne    1555 <filter_char_substring+0x2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1555;
	}
x86_l_1600:
	/* 0x1600: jmp    1726 <filter_char_substring+0x1fe> */
	return 5926ULL;
x86_l_1605:
	/* 0x1605: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_1607:
	/* 0x1607: je     16e5 <filter_char_substring+0x1bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5861ULL;
	}
x86_l_160d:
	/* 0x160d: lea    r13,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1612:
	/* 0x1612: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
	return 5652ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v61_generic_uprobe_filter_arg_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5652ULL: goto x86_l_1614;
	case 5655ULL: goto x86_l_1617;
	case 5660ULL: goto x86_l_161c;
	case 5664ULL: goto x86_l_1620;
	case 5669ULL: goto x86_l_1625;
	case 5676ULL: goto x86_l_162c;
	case 5679ULL: goto x86_l_162f;
	case 5681ULL: goto x86_l_1631;
	case 5684ULL: goto x86_l_1634;
	case 5690ULL: goto x86_l_163a;
	case 5693ULL: goto x86_l_163d;
	case 5695ULL: goto x86_l_163f;
	case 5697ULL: goto x86_l_1641;
	case 5700ULL: goto x86_l_1644;
	case 5703ULL: goto x86_l_1647;
	case 5706ULL: goto x86_l_164a;
	case 5708ULL: goto x86_l_164c;
	case 5710ULL: goto x86_l_164e;
	case 5714ULL: goto x86_l_1652;
	case 5717ULL: goto x86_l_1655;
	case 5719ULL: goto x86_l_1657;
	case 5723ULL: goto x86_l_165b;
	case 5726ULL: goto x86_l_165e;
	case 5728ULL: goto x86_l_1660;
	case 5732ULL: goto x86_l_1664;
	case 5734ULL: goto x86_l_1666;
	case 5738ULL: goto x86_l_166a;
	case 5742ULL: goto x86_l_166e;
	case 5745ULL: goto x86_l_1671;
	case 5747ULL: goto x86_l_1673;
	case 5749ULL: goto x86_l_1675;
	case 5751ULL: goto x86_l_1677;
	case 5757ULL: goto x86_l_167d;
	case 5762ULL: goto x86_l_1682;
	case 5766ULL: goto x86_l_1686;
	case 5772ULL: goto x86_l_168c;
	case 5776ULL: goto x86_l_1690;
	case 5779ULL: goto x86_l_1693;
	case 5783ULL: goto x86_l_1697;
	case 5789ULL: goto x86_l_169d;
	case 5794ULL: goto x86_l_16a2;
	case 5799ULL: goto x86_l_16a7;
	case 5806ULL: goto x86_l_16ae;
	case 5811ULL: goto x86_l_16b3;
	case 5815ULL: goto x86_l_16b7;
	case 5819ULL: goto x86_l_16bb;
	case 5824ULL: goto x86_l_16c0;
	case 5827ULL: goto x86_l_16c3;
	case 5830ULL: goto x86_l_16c6;
	case 5832ULL: goto x86_l_16c8;
	case 5835ULL: goto x86_l_16cb;
	case 5837ULL: goto x86_l_16cd;
	case 5841ULL: goto x86_l_16d1;
	case 5844ULL: goto x86_l_16d4;
	case 5848ULL: goto x86_l_16d8;
	case 5850ULL: goto x86_l_16da;
	case 5857ULL: goto x86_l_16e1;
	case 5859ULL: goto x86_l_16e3;
	case 5861ULL: goto x86_l_16e5;
	case 5866ULL: goto x86_l_16ea;
	case 5873ULL: goto x86_l_16f1;
	case 5878ULL: goto x86_l_16f6;
	case 5882ULL: goto x86_l_16fa;
	case 5886ULL: goto x86_l_16fe;
	case 5891ULL: goto x86_l_1703;
	case 5894ULL: goto x86_l_1706;
	case 5897ULL: goto x86_l_1709;
	case 5899ULL: goto x86_l_170b;
	case 5902ULL: goto x86_l_170e;
	case 5904ULL: goto x86_l_1710;
	case 5908ULL: goto x86_l_1714;
	case 5911ULL: goto x86_l_1717;
	case 5915ULL: goto x86_l_171b;
	case 5917ULL: goto x86_l_171d;
	case 5924ULL: goto x86_l_1724;
	case 5926ULL: goto x86_l_1726;
	case 5928ULL: goto x86_l_1728;
	case 5932ULL: goto x86_l_172c;
	case 5933ULL: goto x86_l_172d;
	case 5935ULL: goto x86_l_172f;
	case 5937ULL: goto x86_l_1731;
	case 5939ULL: goto x86_l_1733;
	case 5941ULL: goto x86_l_1735;
	case 5942ULL: goto x86_l_1736;
	case 5943ULL: goto x86_l_1737;
	case 5948ULL: goto x86_l_173c;
	case 5950ULL: goto x86_l_173e;
	case 5953ULL: goto x86_l_1741;
	case 5958ULL: goto x86_l_1746;
	case 5962ULL: goto x86_l_174a;
	case 5964ULL: goto x86_l_174c;
	case 5974ULL: goto x86_l_1756;
	case 5978ULL: goto x86_l_175a;
	case 5980ULL: goto x86_l_175c;
	case 5981ULL: goto x86_l_175d;
	case 5986ULL: goto x86_l_1762;
	case 5990ULL: goto x86_l_1766;
	case 5992ULL: goto x86_l_1768;
	case 5995ULL: goto x86_l_176b;
	case 5998ULL: goto x86_l_176e;
	case 6004ULL: goto x86_l_1774;
	case 6006ULL: goto x86_l_1776;
	case 6009ULL: goto x86_l_1779;
	case 6012ULL: goto x86_l_177c;
	case 6013ULL: goto x86_l_177d;
	case 6017ULL: goto x86_l_1781;
	case 6019ULL: goto x86_l_1783;
	case 6022ULL: goto x86_l_1786;
	case 6025ULL: goto x86_l_1789;
	case 6027ULL: goto x86_l_178b;
	case 6030ULL: goto x86_l_178e;
	case 6033ULL: goto x86_l_1791;
	case 6039ULL: goto x86_l_1797;
	case 6042ULL: goto x86_l_179a;
	case 6044ULL: goto x86_l_179c;
	case 6047ULL: goto x86_l_179f;
	case 6053ULL: goto x86_l_17a5;
	case 6056ULL: goto x86_l_17a8;
	case 6058ULL: goto x86_l_17aa;
	case 6061ULL: goto x86_l_17ad;
	case 6067ULL: goto x86_l_17b3;
	case 6070ULL: goto x86_l_17b6;
	case 6072ULL: goto x86_l_17b8;
	case 6077ULL: goto x86_l_17bd;
	case 6080ULL: goto x86_l_17c0;
	case 6082ULL: goto x86_l_17c2;
	case 6085ULL: goto x86_l_17c5;
	case 6091ULL: goto x86_l_17cb;
	case 6094ULL: goto x86_l_17ce;
	case 6097ULL: goto x86_l_17d1;
	case 6103ULL: goto x86_l_17d7;
	case 6108ULL: goto x86_l_17dc;
	case 6111ULL: goto x86_l_17df;
	case 6117ULL: goto x86_l_17e5;
	case 6120ULL: goto x86_l_17e8;
	case 6123ULL: goto x86_l_17eb;
	case 6129ULL: goto x86_l_17f1;
	case 6132ULL: goto x86_l_17f4;
	case 6135ULL: goto x86_l_17f7;
	case 6141ULL: goto x86_l_17fd;
	case 6144ULL: goto x86_l_1800;
	case 6150ULL: goto x86_l_1806;
	case 6153ULL: goto x86_l_1809;
	case 6159ULL: goto x86_l_180f;
	case 6162ULL: goto x86_l_1812;
	case 6168ULL: goto x86_l_1818;
	case 6171ULL: goto x86_l_181b;
	case 6177ULL: goto x86_l_1821;
	case 6180ULL: goto x86_l_1824;
	case 6186ULL: goto x86_l_182a;
	case 6191ULL: goto x86_l_182f;
	case 6194ULL: goto x86_l_1832;
	case 6197ULL: goto x86_l_1835;
	case 6203ULL: goto x86_l_183b;
	case 6208ULL: goto x86_l_1840;
	case 6211ULL: goto x86_l_1843;
	case 6217ULL: goto x86_l_1849;
	case 6220ULL: goto x86_l_184c;
	case 6223ULL: goto x86_l_184f;
	case 6229ULL: goto x86_l_1855;
	case 6232ULL: goto x86_l_1858;
	case 6235ULL: goto x86_l_185b;
	case 6241ULL: goto x86_l_1861;
	case 6244ULL: goto x86_l_1864;
	case 6250ULL: goto x86_l_186a;
	case 6253ULL: goto x86_l_186d;
	case 6259ULL: goto x86_l_1873;
	case 6262ULL: goto x86_l_1876;
	case 6268ULL: goto x86_l_187c;
	case 6271ULL: goto x86_l_187f;
	case 6277ULL: goto x86_l_1885;
	case 6280ULL: goto x86_l_1888;
	case 6286ULL: goto x86_l_188e;
	case 6291ULL: goto x86_l_1893;
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
	case 6327ULL: goto x86_l_18b7;
	case 6330ULL: goto x86_l_18ba;
	case 6336ULL: goto x86_l_18c0;
	case 6339ULL: goto x86_l_18c3;
	case 6345ULL: goto x86_l_18c9;
	case 6347ULL: goto x86_l_18cb;
	case 6357ULL: goto x86_l_18d5;
	case 6361ULL: goto x86_l_18d9;
	case 6367ULL: goto x86_l_18df;
	case 6369ULL: goto x86_l_18e1;
	case 6372ULL: goto x86_l_18e4;
	case 6375ULL: goto x86_l_18e7;
	case 6381ULL: goto x86_l_18ed;
	case 6384ULL: goto x86_l_18f0;
	case 6387ULL: goto x86_l_18f3;
	case 6389ULL: goto x86_l_18f5;
	case 6392ULL: goto x86_l_18f8;
	case 6398ULL: goto x86_l_18fe;
	case 6401ULL: goto x86_l_1901;
	case 6403ULL: goto x86_l_1903;
	case 6406ULL: goto x86_l_1906;
	case 6412ULL: goto x86_l_190c;
	case 6415ULL: goto x86_l_190f;
	case 6417ULL: goto x86_l_1911;
	case 6420ULL: goto x86_l_1914;
	case 6426ULL: goto x86_l_191a;
	case 6428ULL: goto x86_l_191c;
	case 6431ULL: goto x86_l_191f;
	case 6434ULL: goto x86_l_1922;
	case 6440ULL: goto x86_l_1928;
	case 6443ULL: goto x86_l_192b;
	case 6446ULL: goto x86_l_192e;
	case 6448ULL: goto x86_l_1930;
	case 6451ULL: goto x86_l_1933;
	case 6457ULL: goto x86_l_1939;
	case 6460ULL: goto x86_l_193c;
	case 6462ULL: goto x86_l_193e;
	case 6465ULL: goto x86_l_1941;
	case 6471ULL: goto x86_l_1947;
	case 6474ULL: goto x86_l_194a;
	case 6476ULL: goto x86_l_194c;
	case 6479ULL: goto x86_l_194f;
	case 6485ULL: goto x86_l_1955;
	case 6487ULL: goto x86_l_1957;
	case 6488ULL: goto x86_l_1958;
	case 6491ULL: goto x86_l_195b;
	case 6494ULL: goto x86_l_195e;
	case 6497ULL: goto x86_l_1961;
	case 6503ULL: goto x86_l_1967;
	case 6508ULL: goto x86_l_196c;
	case 6511ULL: goto x86_l_196f;
	case 6517ULL: goto x86_l_1975;
	case 6520ULL: goto x86_l_1978;
	case 6523ULL: goto x86_l_197b;
	case 6525ULL: goto x86_l_197d;
	case 6530ULL: goto x86_l_1982;
	case 6533ULL: goto x86_l_1985;
	case 6535ULL: goto x86_l_1987;
	case 6538ULL: goto x86_l_198a;
	case 6544ULL: goto x86_l_1990;
	case 6547ULL: goto x86_l_1993;
	case 6550ULL: goto x86_l_1996;
	case 6556ULL: goto x86_l_199c;
	case 6559ULL: goto x86_l_199f;
	case 6561ULL: goto x86_l_19a1;
	case 6564ULL: goto x86_l_19a4;
	case 6570ULL: goto x86_l_19aa;
	case 6573ULL: goto x86_l_19ad;
	case 6579ULL: goto x86_l_19b3;
	case 6582ULL: goto x86_l_19b6;
	case 6584ULL: goto x86_l_19b8;
	case 6587ULL: goto x86_l_19bb;
	case 6593ULL: goto x86_l_19c1;
	case 6596ULL: goto x86_l_19c4;
	case 6602ULL: goto x86_l_19ca;
	case 6604ULL: goto x86_l_19cc;
	case 6607ULL: goto x86_l_19cf;
	case 6613ULL: goto x86_l_19d5;
	case 6616ULL: goto x86_l_19d8;
	case 6622ULL: goto x86_l_19de;
	case 6627ULL: goto x86_l_19e3;
	case 6630ULL: goto x86_l_19e6;
	case 6633ULL: goto x86_l_19e9;
	case 6637ULL: goto x86_l_19ed;
	case 6640ULL: goto x86_l_19f0;
	case 6643ULL: goto x86_l_19f3;
	case 6646ULL: goto x86_l_19f6;
	case 6649ULL: goto x86_l_19f9;
	case 6655ULL: goto x86_l_19ff;
	case 6658ULL: goto x86_l_1a02;
	case 6662ULL: goto x86_l_1a06;
	case 6665ULL: goto x86_l_1a09;
	case 6669ULL: goto x86_l_1a0d;
	case 6672ULL: goto x86_l_1a10;
	case 6675ULL: goto x86_l_1a13;
	case 6678ULL: goto x86_l_1a16;
	case 6684ULL: goto x86_l_1a1c;
	case 6687ULL: goto x86_l_1a1f;
	case 6691ULL: goto x86_l_1a23;
	case 6694ULL: goto x86_l_1a26;
	case 6698ULL: goto x86_l_1a2a;
	case 6701ULL: goto x86_l_1a2d;
	case 6704ULL: goto x86_l_1a30;
	case 6707ULL: goto x86_l_1a33;
	case 6713ULL: goto x86_l_1a39;
	case 6716ULL: goto x86_l_1a3c;
	case 6719ULL: goto x86_l_1a3f;
	case 6722ULL: goto x86_l_1a42;
	case 6726ULL: goto x86_l_1a46;
	case 6728ULL: goto x86_l_1a48;
	case 6731ULL: goto x86_l_1a4b;
	case 6734ULL: goto x86_l_1a4e;
	case 6736ULL: goto x86_l_1a50;
	case 6741ULL: goto x86_l_1a55;
	case 6744ULL: goto x86_l_1a58;
	case 6746ULL: goto x86_l_1a5a;
	case 6749ULL: goto x86_l_1a5d;
	case 6751ULL: goto x86_l_1a5f;
	case 6752ULL: goto x86_l_1a60;
	case 6755ULL: goto x86_l_1a63;
	case 6758ULL: goto x86_l_1a66;
	case 6762ULL: goto x86_l_1a6a;
	case 6765ULL: goto x86_l_1a6d;
	case 6768ULL: goto x86_l_1a70;
	case 6771ULL: goto x86_l_1a73;
	case 6774ULL: goto x86_l_1a76;
	case 6780ULL: goto x86_l_1a7c;
	case 6783ULL: goto x86_l_1a7f;
	case 6787ULL: goto x86_l_1a83;
	case 6790ULL: goto x86_l_1a86;
	case 6794ULL: goto x86_l_1a8a;
	case 6797ULL: goto x86_l_1a8d;
	case 6800ULL: goto x86_l_1a90;
	case 6803ULL: goto x86_l_1a93;
	case 6805ULL: goto x86_l_1a95;
	case 6808ULL: goto x86_l_1a98;
	case 6812ULL: goto x86_l_1a9c;
	case 6815ULL: goto x86_l_1a9f;
	case 6819ULL: goto x86_l_1aa3;
	case 6822ULL: goto x86_l_1aa6;
	case 6825ULL: goto x86_l_1aa9;
	case 6828ULL: goto x86_l_1aac;
	case 6830ULL: goto x86_l_1aae;
	case 6833ULL: goto x86_l_1ab1;
	case 6836ULL: goto x86_l_1ab4;
	case 6839ULL: goto x86_l_1ab7;
	case 6843ULL: goto x86_l_1abb;
	case 6846ULL: goto x86_l_1abe;
	case 6849ULL: goto x86_l_1ac1;
	case 6851ULL: goto x86_l_1ac3;
	case 6854ULL: goto x86_l_1ac6;
	case 6857ULL: goto x86_l_1ac9;
	case 6859ULL: goto x86_l_1acb;
	case 6862ULL: goto x86_l_1ace;
	case 6864ULL: goto x86_l_1ad0;
	case 6867ULL: goto x86_l_1ad3;
	case 6869ULL: goto x86_l_1ad5;
	case 6872ULL: goto x86_l_1ad8;
	case 6874ULL: goto x86_l_1ada;
	case 6877ULL: goto x86_l_1add;
	case 6879ULL: goto x86_l_1adf;
	case 6882ULL: goto x86_l_1ae2;
	case 6888ULL: goto x86_l_1ae8;
	case 6891ULL: goto x86_l_1aeb;
	case 6893ULL: goto x86_l_1aed;
	case 6895ULL: goto x86_l_1aef;
	case 6898ULL: goto x86_l_1af2;
	case 6900ULL: goto x86_l_1af4;
	case 6903ULL: goto x86_l_1af7;
	case 6909ULL: goto x86_l_1afd;
	case 6911ULL: goto x86_l_1aff;
	case 6913ULL: goto x86_l_1b01;
	case 6916ULL: goto x86_l_1b04;
	case 6919ULL: goto x86_l_1b07;
	case 6922ULL: goto x86_l_1b0a;
	case 6924ULL: goto x86_l_1b0c;
	case 6927ULL: goto x86_l_1b0f;
	case 6928ULL: goto x86_l_1b10;
	case 6930ULL: goto x86_l_1b12;
	case 6931ULL: goto x86_l_1b13;
	case 6935ULL: goto x86_l_1b17;
	case 6938ULL: goto x86_l_1b1a;
	case 6941ULL: goto x86_l_1b1d;
	case 6945ULL: goto x86_l_1b21;
	case 6949ULL: goto x86_l_1b25;
	case 6956ULL: goto x86_l_1b2c;
	case 6961ULL: goto x86_l_1b31;
	case 6966ULL: goto x86_l_1b36;
	case 6968ULL: goto x86_l_1b38;
	case 6971ULL: goto x86_l_1b3b;
	case 6973ULL: goto x86_l_1b3d;
	case 6976ULL: goto x86_l_1b40;
	case 6980ULL: goto x86_l_1b44;
	case 6985ULL: goto x86_l_1b49;
	case 6990ULL: goto x86_l_1b4e;
	case 6995ULL: goto x86_l_1b53;
	case 6997ULL: goto x86_l_1b55;
	case 7000ULL: goto x86_l_1b58;
	case 7002ULL: goto x86_l_1b5a;
	case 7005ULL: goto x86_l_1b5d;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1614:
	/* 0x1614: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1617:
	/* 0x1617: mov    eax,DWORD PTR [r14+rbx*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_161c:
	/* 0x161c: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1620:
	/* 0x1620: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1625:
	/* 0x1625: mov    rdi,QWORD PTR [rip+0x2251] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_162c:
	/* 0x162c: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_162f:
	/* 0x162f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1631:
	/* 0x1631: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1634:
	/* 0x1634: je     1726 <filter_char_substring+0x1fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1726;
	}
x86_l_163a:
	/* 0x163a: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_163d:
	/* 0x163d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_163f:
	/* 0x163f: jmp    164c <filter_char_substring+0x124> */
	goto x86_l_164c;
x86_l_1641:
	/* 0x1641: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1644:
	/* 0x1644: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1647:
	/* 0x1647: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_164a:
	/* 0x164a: je     167d <filter_char_substring+0x155> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_167d;
	}
x86_l_164c:
	/* 0x164c: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_164e:
	/* 0x164e: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_1652:
	/* 0x1652: cmp    rdi,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1655:
	/* 0x1655: jae    1641 <filter_char_substring+0x119> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1641;
	}
x86_l_1657:
	/* 0x1657: movzx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_165b:
	/* 0x165b: test   dil,dil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_8);
x86_l_165e:
	/* 0x165e: je     1675 <filter_char_substring+0x14d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1675;
	}
x86_l_1660:
	/* 0x1660: cmp    rsi,0x62 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 98ULL);
x86_l_1664:
	/* 0x1664: ja     1641 <filter_char_substring+0x119> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1641;
	}
x86_l_1666:
	/* 0x1666: lea    r8,[rsi+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_166a:
	/* 0x166a: cmp    BYTE PTR [rdx+rsi*1],dil */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDX, X86_RDI, X86_WIDTH_8, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_166e:
	/* 0x166e: mov    rsi,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R8, X86_WIDTH_64);
x86_l_1671:
	/* 0x1671: je     164e <filter_char_substring+0x126> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_164e;
	}
x86_l_1673:
	/* 0x1673: jmp    1641 <filter_char_substring+0x119> */
	goto x86_l_1641;
x86_l_1675:
	/* 0x1675: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1677:
	/* 0x1677: jns    1737 <filter_char_substring+0x20f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_1737;
	}
x86_l_167d:
	/* 0x167d: lea    eax,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1682:
	/* 0x1682: cmp    eax,DWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_1686:
	/* 0x1686: jae    1726 <filter_char_substring+0x1fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1726;
	}
x86_l_168c:
	/* 0x168c: add    r12d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1690:
	/* 0x1690: inc    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1693:
	/* 0x1693: cmp    rbx,0x64 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 100ULL);
x86_l_1697:
	/* 0x1697: jne    1617 <filter_char_substring+0xef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1617;
	}
x86_l_169d:
	/* 0x169d: jmp    1726 <filter_char_substring+0x1fe> */
	goto x86_l_1726;
x86_l_16a2:
	/* 0x16a2: mov    ebx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 16ULL);
x86_l_16a7:
	/* 0x16a7: mov    r15,QWORD PTR [rip+0x2263] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_16ae:
	/* 0x16ae: lea    r12,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_16b3:
	/* 0x16b3: mov    eax,DWORD PTR [r14+rbx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_16b7:
	/* 0x16b7: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_16bb:
	/* 0x16bb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16c0:
	/* 0x16c0: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_16c3:
	/* 0x16c3: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_16c6:
	/* 0x16c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16c8:
	/* 0x16c8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16cb:
	/* 0x16cb: je     1726 <filter_char_substring+0x1fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1726;
	}
x86_l_16cd:
	/* 0x16cd: add    rbx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_16d1:
	/* 0x16d1: lea    eax,[rbx-0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551608ULL);
x86_l_16d4:
	/* 0x16d4: cmp    eax,DWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_16d8:
	/* 0x16d8: jae    1726 <filter_char_substring+0x1fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1726;
	}
x86_l_16da:
	/* 0x16da: cmp    rbx,0x1a0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 416ULL);
x86_l_16e1:
	/* 0x16e1: jne    16b3 <filter_char_substring+0x18b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_16b3;
	}
x86_l_16e3:
	/* 0x16e3: jmp    1726 <filter_char_substring+0x1fe> */
	goto x86_l_1726;
x86_l_16e5:
	/* 0x16e5: mov    ebx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 16ULL);
x86_l_16ea:
	/* 0x16ea: mov    r15,QWORD PTR [rip+0x2265] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_16f1:
	/* 0x16f1: lea    r12,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_16f6:
	/* 0x16f6: mov    eax,DWORD PTR [r14+rbx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_16fa:
	/* 0x16fa: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_16fe:
	/* 0x16fe: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1703:
	/* 0x1703: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1706:
	/* 0x1706: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1709:
	/* 0x1709: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_170b:
	/* 0x170b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_170e:
	/* 0x170e: je     1726 <filter_char_substring+0x1fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1726;
	}
x86_l_1710:
	/* 0x1710: add    rbx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1714:
	/* 0x1714: lea    eax,[rbx-0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551608ULL);
x86_l_1717:
	/* 0x1717: cmp    eax,DWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_171b:
	/* 0x171b: jae    1726 <filter_char_substring+0x1fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1726;
	}
x86_l_171d:
	/* 0x171d: cmp    rbx,0x1a0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 416ULL);
x86_l_1724:
	/* 0x1724: jne    16f6 <filter_char_substring+0x1ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_16f6;
	}
x86_l_1726:
	/* 0x1726: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1728:
	/* 0x1728: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_172c:
	/* 0x172c: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_172d:
	/* 0x172d: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_172f:
	/* 0x172f: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_1731:
	/* 0x1731: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_1733:
	/* 0x1733: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_1735:
	/* 0x1735: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1736:
	/* 0x1736: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1737:
	/* 0x1737: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_173c:
	/* 0x173c: jmp    1728 <filter_char_substring+0x200> */
	goto x86_l_1728;
x86_l_173e:
	/* 0x173e: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1741:
	/* 0x1741: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1746:
	/* 0x1746: cmp    rcx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 37ULL);
x86_l_174a:
	/* 0x174a: ja     17bd <filter_16ty_selector_val+0x7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_17bd;
	}
x86_l_174c:
	/* 0x174c: movabs rdx,0x200c000040 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280128ULL);
x86_l_1756:
	/* 0x1756: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_175a:
	/* 0x175a: jae    175d <filter_16ty_selector_val+0x1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_175d;
	}
x86_l_175c:
	/* 0x175c: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_175d:
	/* 0x175d: mov    edx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 24ULL);
x86_l_1762:
	/* 0x1762: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1766:
	/* 0x1766: jae    177d <filter_16ty_selector_val+0x3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_177d;
	}
x86_l_1768:
	/* 0x1768: movzx  edx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_176b:
	/* 0x176b: cmp    DWORD PTR [rdi+0x10],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_176e:
	/* 0x176e: jne    1893 <filter_16ty_selector_val+0x155> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1893;
	}
x86_l_1774:
	/* 0x1774: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1776:
	/* 0x1776: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1779:
	/* 0x1779: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_177c:
	/* 0x177c: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_177d:
	/* 0x177d: cmp    rcx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 12ULL);
x86_l_1781:
	/* 0x1781: jne    17bd <filter_16ty_selector_val+0x7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_17bd;
	}
x86_l_1783:
	/* 0x1783: movzx  ecx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1786:
	/* 0x1786: test   DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1789:
	/* 0x1789: jne    175c <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_175c;
	}
x86_l_178b:
	/* 0x178b: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_178e:
	/* 0x178e: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1791:
	/* 0x1791: jb     1955 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1955;
	}
x86_l_1797:
	/* 0x1797: test   DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_179a:
	/* 0x179a: jne    175c <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_175c;
	}
x86_l_179c:
	/* 0x179c: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_179f:
	/* 0x179f: jb     1955 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1955;
	}
x86_l_17a5:
	/* 0x17a5: test   DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_17a8:
	/* 0x17a8: jne    175c <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_175c;
	}
x86_l_17aa:
	/* 0x17aa: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_17ad:
	/* 0x17ad: jb     1955 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1955;
	}
x86_l_17b3:
	/* 0x17b3: test   DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_17b6:
	/* 0x17b6: jne    175c <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_175c;
	}
x86_l_17b8:
	/* 0x17b8: jmp    1955 <filter_16ty_selector_val+0x217> */
	goto x86_l_1955;
x86_l_17bd:
	/* 0x17bd: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_17c0:
	/* 0x17c0: je     182f <filter_16ty_selector_val+0xf1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_182f;
	}
x86_l_17c2:
	/* 0x17c2: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_17c5:
	/* 0x17c5: jne    1955 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1955;
	}
x86_l_17cb:
	/* 0x17cb: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_17ce:
	/* 0x17ce: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_17d1:
	/* 0x17d1: ja     191c <filter_16ty_selector_val+0x1de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_191c;
	}
x86_l_17d7:
	/* 0x17d7: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_17dc:
	/* 0x17dc: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_17df:
	/* 0x17df: jae    191c <filter_16ty_selector_val+0x1de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_191c;
	}
x86_l_17e5:
	/* 0x17e5: movsx  ecx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_17e8:
	/* 0x17e8: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17eb:
	/* 0x17eb: jg     175c <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_175c;
	}
x86_l_17f1:
	/* 0x17f1: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17f4:
	/* 0x17f4: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_17f7:
	/* 0x17f7: jb     1955 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1955;
	}
x86_l_17fd:
	/* 0x17fd: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1800:
	/* 0x1800: jg     175c <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_175c;
	}
x86_l_1806:
	/* 0x1806: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1809:
	/* 0x1809: jb     1955 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1955;
	}
x86_l_180f:
	/* 0x180f: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1812:
	/* 0x1812: jg     175c <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_175c;
	}
x86_l_1818:
	/* 0x1818: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_181b:
	/* 0x181b: jb     1955 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1955;
	}
x86_l_1821:
	/* 0x1821: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1824:
	/* 0x1824: jg     175c <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_175c;
	}
x86_l_182a:
	/* 0x182a: jmp    1955 <filter_16ty_selector_val+0x217> */
	goto x86_l_1955;
x86_l_182f:
	/* 0x182f: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1832:
	/* 0x1832: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1835:
	/* 0x1835: ja     18e1 <filter_16ty_selector_val+0x1a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_18e1;
	}
x86_l_183b:
	/* 0x183b: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_1840:
	/* 0x1840: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_1843:
	/* 0x1843: jae    18e1 <filter_16ty_selector_val+0x1a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_18e1;
	}
x86_l_1849:
	/* 0x1849: movsx  ecx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_184c:
	/* 0x184c: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_184f:
	/* 0x184f: jl     175c <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_175c;
	}
x86_l_1855:
	/* 0x1855: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1858:
	/* 0x1858: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_185b:
	/* 0x185b: jb     1955 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1955;
	}
x86_l_1861:
	/* 0x1861: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1864:
	/* 0x1864: jl     175c <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_175c;
	}
x86_l_186a:
	/* 0x186a: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_186d:
	/* 0x186d: jb     1955 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1955;
	}
x86_l_1873:
	/* 0x1873: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1876:
	/* 0x1876: jl     175c <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_175c;
	}
x86_l_187c:
	/* 0x187c: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_187f:
	/* 0x187f: jb     1955 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1955;
	}
x86_l_1885:
	/* 0x1885: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1888:
	/* 0x1888: jl     175c <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_175c;
	}
x86_l_188e:
	/* 0x188e: jmp    1955 <filter_16ty_selector_val+0x217> */
	goto x86_l_1955;
x86_l_1893:
	/* 0x1893: mov    esi,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1896:
	/* 0x1896: cmp    esi,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 13ULL);
x86_l_1899:
	/* 0x1899: jb     18c0 <filter_16ty_selector_val+0x182> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18c0;
	}
x86_l_189b:
	/* 0x189b: cmp    DWORD PTR [rdi+0x14],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_189e:
	/* 0x189e: je     1774 <filter_16ty_selector_val+0x36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1774;
	}
x86_l_18a4:
	/* 0x18a4: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_18a7:
	/* 0x18a7: jb     18c0 <filter_16ty_selector_val+0x182> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18c0;
	}
x86_l_18a9:
	/* 0x18a9: cmp    DWORD PTR [rdi+0x18],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18ac:
	/* 0x18ac: je     1774 <filter_16ty_selector_val+0x36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1774;
	}
x86_l_18b2:
	/* 0x18b2: cmp    esi,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 21ULL);
x86_l_18b5:
	/* 0x18b5: jb     18c0 <filter_16ty_selector_val+0x182> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18c0;
	}
x86_l_18b7:
	/* 0x18b7: cmp    DWORD PTR [rdi+0x1c],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_18ba:
	/* 0x18ba: je     1774 <filter_16ty_selector_val+0x36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1774;
	}
x86_l_18c0:
	/* 0x18c0: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_18c3:
	/* 0x18c3: ja     1955 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1955;
	}
x86_l_18c9:
	/* 0x18c9: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_18cb:
	/* 0x18cb: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_18d5:
	/* 0x18d5: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_18d9:
	/* 0x18d9: jb     175c <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_175c;
	}
x86_l_18df:
	/* 0x18df: jmp    1955 <filter_16ty_selector_val+0x217> */
	goto x86_l_1955;
x86_l_18e1:
	/* 0x18e1: movzx  ecx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_18e4:
	/* 0x18e4: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18e7:
	/* 0x18e7: jb     175c <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_175c;
	}
x86_l_18ed:
	/* 0x18ed: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18f0:
	/* 0x18f0: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_18f3:
	/* 0x18f3: jb     1955 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1955;
	}
x86_l_18f5:
	/* 0x18f5: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_18f8:
	/* 0x18f8: jb     175c <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_175c;
	}
x86_l_18fe:
	/* 0x18fe: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1901:
	/* 0x1901: jb     1955 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1955;
	}
x86_l_1903:
	/* 0x1903: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1906:
	/* 0x1906: jb     175c <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_175c;
	}
x86_l_190c:
	/* 0x190c: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_190f:
	/* 0x190f: jb     1955 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1955;
	}
x86_l_1911:
	/* 0x1911: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1914:
	/* 0x1914: jb     175c <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_175c;
	}
x86_l_191a:
	/* 0x191a: jmp    1955 <filter_16ty_selector_val+0x217> */
	goto x86_l_1955;
x86_l_191c:
	/* 0x191c: movzx  ecx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_191f:
	/* 0x191f: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1922:
	/* 0x1922: ja     175c <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_175c;
	}
x86_l_1928:
	/* 0x1928: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_192b:
	/* 0x192b: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_192e:
	/* 0x192e: jb     1955 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1955;
	}
x86_l_1930:
	/* 0x1930: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1933:
	/* 0x1933: ja     175c <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_175c;
	}
x86_l_1939:
	/* 0x1939: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_193c:
	/* 0x193c: jb     1955 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1955;
	}
x86_l_193e:
	/* 0x193e: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1941:
	/* 0x1941: ja     175c <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_175c;
	}
x86_l_1947:
	/* 0x1947: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_194a:
	/* 0x194a: jb     1955 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1955;
	}
x86_l_194c:
	/* 0x194c: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_194f:
	/* 0x194f: ja     175c <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_175c;
	}
x86_l_1955:
	/* 0x1955: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1957:
	/* 0x1957: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1958:
	/* 0x1958: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_195b:
	/* 0x195b: mov    eax,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_195e:
	/* 0x195e: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1961:
	/* 0x1961: ja     1a48 <filter_16ty_range+0xf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1a48;
	}
x86_l_1967:
	/* 0x1967: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_196c:
	/* 0x196c: bt     edx,eax */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_196f:
	/* 0x196f: jae    1a48 <filter_16ty_range+0xf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1a48;
	}
x86_l_1975:
	/* 0x1975: movsx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1978:
	/* 0x1978: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_197b:
	/* 0x197b: jne    19e3 <filter_16ty_range+0x8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_19e3;
	}
x86_l_197d:
	/* 0x197d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1982:
	/* 0x1982: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1985:
	/* 0x1985: jg     1990 <filter_16ty_range+0x38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1990;
	}
x86_l_1987:
	/* 0x1987: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_198a:
	/* 0x198a: jge    1a5f <filter_16ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_GE)) {
		goto x86_l_1a5f;
	}
x86_l_1990:
	/* 0x1990: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1993:
	/* 0x1993: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1996:
	/* 0x1996: jb     1aff <filter_16ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1aff;
	}
x86_l_199c:
	/* 0x199c: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_199f:
	/* 0x199f: jg     19aa <filter_16ty_range+0x52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_19aa;
	}
x86_l_19a1:
	/* 0x19a1: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_19a4:
	/* 0x19a4: jge    1a5f <filter_16ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_GE)) {
		goto x86_l_1a5f;
	}
x86_l_19aa:
	/* 0x19aa: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_19ad:
	/* 0x19ad: jb     1aff <filter_16ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1aff;
	}
x86_l_19b3:
	/* 0x19b3: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_19b6:
	/* 0x19b6: jg     19c1 <filter_16ty_range+0x69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_19c1;
	}
x86_l_19b8:
	/* 0x19b8: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_19bb:
	/* 0x19bb: jge    1a5f <filter_16ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_GE)) {
		goto x86_l_1a5f;
	}
x86_l_19c1:
	/* 0x19c1: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_19c4:
	/* 0x19c4: jb     1aff <filter_16ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1aff;
	}
x86_l_19ca:
	/* 0x19ca: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19cc:
	/* 0x19cc: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_19cf:
	/* 0x19cf: jg     1b01 <filter_16ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1b01;
	}
x86_l_19d5:
	/* 0x19d5: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_19d8:
	/* 0x19d8: jge    1a5f <filter_16ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_GE)) {
		goto x86_l_1a5f;
	}
x86_l_19de:
	/* 0x19de: jmp    1b01 <filter_16ty_range+0x1a9> */
	goto x86_l_1b01;
x86_l_19e3:
	/* 0x19e3: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19e6:
	/* 0x19e6: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19e9:
	/* 0x19e9: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_19ed:
	/* 0x19ed: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_19f0:
	/* 0x19f0: setge  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_GE);
x86_l_19f3:
	/* 0x19f3: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_19f6:
	/* 0x19f6: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_19f9:
	/* 0x19f9: jb     1b01 <filter_16ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1b01;
	}
x86_l_19ff:
	/* 0x19ff: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a02:
	/* 0x1a02: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_1a06:
	/* 0x1a06: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1a09:
	/* 0x1a09: setge  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_GE);
x86_l_1a0d:
	/* 0x1a0d: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1a10:
	/* 0x1a10: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_1a13:
	/* 0x1a13: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1a16:
	/* 0x1a16: jb     1b01 <filter_16ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1b01;
	}
x86_l_1a1c:
	/* 0x1a1c: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a1f:
	/* 0x1a1f: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_1a23:
	/* 0x1a23: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1a26:
	/* 0x1a26: setge  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_GE);
x86_l_1a2a:
	/* 0x1a2a: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1a2d:
	/* 0x1a2d: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_1a30:
	/* 0x1a30: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_1a33:
	/* 0x1a33: jb     1b01 <filter_16ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1b01;
	}
x86_l_1a39:
	/* 0x1a39: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1a3c:
	/* 0x1a3c: setle  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_LE);
x86_l_1a3f:
	/* 0x1a3f: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1a42:
	/* 0x1a42: setge  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_GE);
x86_l_1a46:
	/* 0x1a46: jmp    1abb <filter_16ty_range+0x163> */
	goto x86_l_1abb;
x86_l_1a48:
	/* 0x1a48: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1a4b:
	/* 0x1a4b: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_1a4e:
	/* 0x1a4e: jne    1a60 <filter_16ty_range+0x108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1a60;
	}
x86_l_1a50:
	/* 0x1a50: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a55:
	/* 0x1a55: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a58:
	/* 0x1a58: ja     1ac3 <filter_16ty_range+0x16b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ac3;
	}
x86_l_1a5a:
	/* 0x1a5a: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1a5d:
	/* 0x1a5d: jb     1ac3 <filter_16ty_range+0x16b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1ac3;
	}
x86_l_1a5f:
	/* 0x1a5f: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1a60:
	/* 0x1a60: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a63:
	/* 0x1a63: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a66:
	/* 0x1a66: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_1a6a:
	/* 0x1a6a: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1a6d:
	/* 0x1a6d: setae  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_AE);
x86_l_1a70:
	/* 0x1a70: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1a73:
	/* 0x1a73: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1a76:
	/* 0x1a76: jb     1b01 <filter_16ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1b01;
	}
x86_l_1a7c:
	/* 0x1a7c: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a7f:
	/* 0x1a7f: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_1a83:
	/* 0x1a83: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1a86:
	/* 0x1a86: setae  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_AE);
x86_l_1a8a:
	/* 0x1a8a: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1a8d:
	/* 0x1a8d: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_1a90:
	/* 0x1a90: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1a93:
	/* 0x1a93: jb     1b01 <filter_16ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1b01;
	}
x86_l_1a95:
	/* 0x1a95: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a98:
	/* 0x1a98: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_1a9c:
	/* 0x1a9c: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1a9f:
	/* 0x1a9f: setae  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_AE);
x86_l_1aa3:
	/* 0x1aa3: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1aa6:
	/* 0x1aa6: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_1aa9:
	/* 0x1aa9: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_1aac:
	/* 0x1aac: jb     1b01 <filter_16ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1b01;
	}
x86_l_1aae:
	/* 0x1aae: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1ab1:
	/* 0x1ab1: setbe  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_BE);
x86_l_1ab4:
	/* 0x1ab4: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1ab7:
	/* 0x1ab7: setae  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_AE);
x86_l_1abb:
	/* 0x1abb: and    sil,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_1abe:
	/* 0x1abe: or     dl,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_8, X86_ALU_OR);
x86_l_1ac1:
	/* 0x1ac1: jmp    1b01 <filter_16ty_range+0x1a9> */
	goto x86_l_1b01;
x86_l_1ac3:
	/* 0x1ac3: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ac6:
	/* 0x1ac6: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1ac9:
	/* 0x1ac9: jb     1aff <filter_16ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1aff;
	}
x86_l_1acb:
	/* 0x1acb: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ace:
	/* 0x1ace: ja     1ad5 <filter_16ty_range+0x17d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ad5;
	}
x86_l_1ad0:
	/* 0x1ad0: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1ad3:
	/* 0x1ad3: jae    1a5f <filter_16ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1a5f;
	}
x86_l_1ad5:
	/* 0x1ad5: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_1ad8:
	/* 0x1ad8: jb     1aff <filter_16ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1aff;
	}
x86_l_1ada:
	/* 0x1ada: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1add:
	/* 0x1add: ja     1ae8 <filter_16ty_range+0x190> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ae8;
	}
x86_l_1adf:
	/* 0x1adf: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1ae2:
	/* 0x1ae2: jae    1a5f <filter_16ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1a5f;
	}
x86_l_1ae8:
	/* 0x1ae8: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_1aeb:
	/* 0x1aeb: jb     1aff <filter_16ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1aff;
	}
x86_l_1aed:
	/* 0x1aed: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1aef:
	/* 0x1aef: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1af2:
	/* 0x1af2: ja     1b01 <filter_16ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1b01;
	}
x86_l_1af4:
	/* 0x1af4: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1af7:
	/* 0x1af7: jae    1a5f <filter_16ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1a5f;
	}
x86_l_1afd:
	/* 0x1afd: jmp    1b01 <filter_16ty_range+0x1a9> */
	goto x86_l_1b01;
x86_l_1aff:
	/* 0x1aff: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b01:
	/* 0x1b01: cmp    ecx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 32ULL);
x86_l_1b04:
	/* 0x1b04: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_1b07:
	/* 0x1b07: xor    dl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_1b0a:
	/* 0x1b0a: and    dl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_1b0c:
	/* 0x1b0c: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1b0f:
	/* 0x1b0f: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1b10:
	/* 0x1b10: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_1b12:
	/* 0x1b12: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_1b13:
	/* 0x1b13: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_1b17:
	/* 0x1b17: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_1b1a:
	/* 0x1b1a: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_1b1d:
	/* 0x1b1d: movzx  eax,BYTE PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1b21:
	/* 0x1b21: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1b25:
	/* 0x1b25: mov    rdi,QWORD PTR [rip+0xfd0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_1b2c:
	/* 0x1b2c: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1b31:
	/* 0x1b31: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b36:
	/* 0x1b36: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b38:
	/* 0x1b38: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b3b:
	/* 0x1b3b: je     1b71 <filter_16ty_map+0x61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7025ULL;
	}
x86_l_1b3d:
	/* 0x1b3d: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1b40:
	/* 0x1b40: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1b44:
	/* 0x1b44: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b49:
	/* 0x1b49: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b4e:
	/* 0x1b4e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b53:
	/* 0x1b53: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b55:
	/* 0x1b55: mov    edx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1b58:
	/* 0x1b58: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b5a:
	/* 0x1b5a: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_1b5d:
	/* 0x1b5d: ja     1b8b <filter_16ty_map+0x7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7051ULL;
	}
	return 7007ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v61_generic_uprobe_filter_arg_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7007ULL: goto x86_l_1b5f;
	case 7012ULL: goto x86_l_1b64;
	case 7015ULL: goto x86_l_1b67;
	case 7017ULL: goto x86_l_1b69;
	case 7020ULL: goto x86_l_1b6c;
	case 7023ULL: goto x86_l_1b6f;
	case 7025ULL: goto x86_l_1b71;
	case 7027ULL: goto x86_l_1b73;
	case 7031ULL: goto x86_l_1b77;
	case 7032ULL: goto x86_l_1b78;
	case 7034ULL: goto x86_l_1b7a;
	case 7035ULL: goto x86_l_1b7b;
	case 7040ULL: goto x86_l_1b80;
	case 7043ULL: goto x86_l_1b83;
	case 7045ULL: goto x86_l_1b85;
	case 7048ULL: goto x86_l_1b88;
	case 7051ULL: goto x86_l_1b8b;
	case 7054ULL: goto x86_l_1b8e;
	case 7058ULL: goto x86_l_1b92;
	case 7059ULL: goto x86_l_1b93;
	case 7061ULL: goto x86_l_1b95;
	case 7062ULL: goto x86_l_1b96;
	case 7065ULL: goto x86_l_1b99;
	case 7070ULL: goto x86_l_1b9e;
	case 7074ULL: goto x86_l_1ba2;
	case 7076ULL: goto x86_l_1ba4;
	case 7086ULL: goto x86_l_1bae;
	case 7090ULL: goto x86_l_1bb2;
	case 7092ULL: goto x86_l_1bb4;
	case 7093ULL: goto x86_l_1bb5;
	case 7098ULL: goto x86_l_1bba;
	case 7102ULL: goto x86_l_1bbe;
	case 7104ULL: goto x86_l_1bc0;
	case 7106ULL: goto x86_l_1bc2;
	case 7109ULL: goto x86_l_1bc5;
	case 7115ULL: goto x86_l_1bcb;
	case 7117ULL: goto x86_l_1bcd;
	case 7120ULL: goto x86_l_1bd0;
	case 7123ULL: goto x86_l_1bd3;
	case 7124ULL: goto x86_l_1bd4;
	case 7128ULL: goto x86_l_1bd8;
	case 7130ULL: goto x86_l_1bda;
	case 7132ULL: goto x86_l_1bdc;
	case 7135ULL: goto x86_l_1bdf;
	case 7137ULL: goto x86_l_1be1;
	case 7140ULL: goto x86_l_1be4;
	case 7143ULL: goto x86_l_1be7;
	case 7149ULL: goto x86_l_1bed;
	case 7152ULL: goto x86_l_1bf0;
	case 7154ULL: goto x86_l_1bf2;
	case 7157ULL: goto x86_l_1bf5;
	case 7163ULL: goto x86_l_1bfb;
	case 7166ULL: goto x86_l_1bfe;
	case 7168ULL: goto x86_l_1c00;
	case 7171ULL: goto x86_l_1c03;
	case 7177ULL: goto x86_l_1c09;
	case 7180ULL: goto x86_l_1c0c;
	case 7182ULL: goto x86_l_1c0e;
	case 7187ULL: goto x86_l_1c13;
	case 7190ULL: goto x86_l_1c16;
	case 7192ULL: goto x86_l_1c18;
	case 7195ULL: goto x86_l_1c1b;
	case 7201ULL: goto x86_l_1c21;
	case 7204ULL: goto x86_l_1c24;
	case 7207ULL: goto x86_l_1c27;
	case 7213ULL: goto x86_l_1c2d;
	case 7218ULL: goto x86_l_1c32;
	case 7221ULL: goto x86_l_1c35;
	case 7227ULL: goto x86_l_1c3b;
	case 7229ULL: goto x86_l_1c3d;
	case 7232ULL: goto x86_l_1c40;
	case 7238ULL: goto x86_l_1c46;
	case 7241ULL: goto x86_l_1c49;
	case 7244ULL: goto x86_l_1c4c;
	case 7250ULL: goto x86_l_1c52;
	case 7253ULL: goto x86_l_1c55;
	case 7259ULL: goto x86_l_1c5b;
	case 7262ULL: goto x86_l_1c5e;
	case 7268ULL: goto x86_l_1c64;
	case 7271ULL: goto x86_l_1c67;
	case 7277ULL: goto x86_l_1c6d;
	case 7280ULL: goto x86_l_1c70;
	case 7286ULL: goto x86_l_1c76;
	case 7289ULL: goto x86_l_1c79;
	case 7295ULL: goto x86_l_1c7f;
	case 7300ULL: goto x86_l_1c84;
	case 7303ULL: goto x86_l_1c87;
	case 7306ULL: goto x86_l_1c8a;
	case 7312ULL: goto x86_l_1c90;
	case 7317ULL: goto x86_l_1c95;
	case 7320ULL: goto x86_l_1c98;
	case 7326ULL: goto x86_l_1c9e;
	case 7328ULL: goto x86_l_1ca0;
	case 7331ULL: goto x86_l_1ca3;
	case 7337ULL: goto x86_l_1ca9;
	case 7340ULL: goto x86_l_1cac;
	case 7343ULL: goto x86_l_1caf;
	case 7349ULL: goto x86_l_1cb5;
	case 7352ULL: goto x86_l_1cb8;
	case 7358ULL: goto x86_l_1cbe;
	case 7361ULL: goto x86_l_1cc1;
	case 7367ULL: goto x86_l_1cc7;
	case 7370ULL: goto x86_l_1cca;
	case 7376ULL: goto x86_l_1cd0;
	case 7379ULL: goto x86_l_1cd3;
	case 7385ULL: goto x86_l_1cd9;
	case 7388ULL: goto x86_l_1cdc;
	case 7394ULL: goto x86_l_1ce2;
	case 7399ULL: goto x86_l_1ce7;
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
	case 7435ULL: goto x86_l_1d0b;
	case 7438ULL: goto x86_l_1d0e;
	case 7444ULL: goto x86_l_1d14;
	case 7447ULL: goto x86_l_1d17;
	case 7453ULL: goto x86_l_1d1d;
	case 7455ULL: goto x86_l_1d1f;
	case 7465ULL: goto x86_l_1d29;
	case 7469ULL: goto x86_l_1d2d;
	case 7475ULL: goto x86_l_1d33;
	case 7477ULL: goto x86_l_1d35;
	case 7479ULL: goto x86_l_1d37;
	case 7482ULL: goto x86_l_1d3a;
	case 7488ULL: goto x86_l_1d40;
	case 7491ULL: goto x86_l_1d43;
	case 7494ULL: goto x86_l_1d46;
	case 7496ULL: goto x86_l_1d48;
	case 7499ULL: goto x86_l_1d4b;
	case 7505ULL: goto x86_l_1d51;
	case 7508ULL: goto x86_l_1d54;
	case 7510ULL: goto x86_l_1d56;
	case 7513ULL: goto x86_l_1d59;
	case 7519ULL: goto x86_l_1d5f;
	case 7522ULL: goto x86_l_1d62;
	case 7524ULL: goto x86_l_1d64;
	case 7527ULL: goto x86_l_1d67;
	case 7533ULL: goto x86_l_1d6d;
	case 7535ULL: goto x86_l_1d6f;
	case 7537ULL: goto x86_l_1d71;
	case 7540ULL: goto x86_l_1d74;
	case 7546ULL: goto x86_l_1d7a;
	case 7549ULL: goto x86_l_1d7d;
	case 7552ULL: goto x86_l_1d80;
	case 7554ULL: goto x86_l_1d82;
	case 7557ULL: goto x86_l_1d85;
	case 7563ULL: goto x86_l_1d8b;
	case 7566ULL: goto x86_l_1d8e;
	case 7568ULL: goto x86_l_1d90;
	case 7571ULL: goto x86_l_1d93;
	case 7577ULL: goto x86_l_1d99;
	case 7580ULL: goto x86_l_1d9c;
	case 7582ULL: goto x86_l_1d9e;
	case 7585ULL: goto x86_l_1da1;
	case 7591ULL: goto x86_l_1da7;
	case 7593ULL: goto x86_l_1da9;
	case 7594ULL: goto x86_l_1daa;
	case 7597ULL: goto x86_l_1dad;
	case 7600ULL: goto x86_l_1db0;
	case 7603ULL: goto x86_l_1db3;
	case 7609ULL: goto x86_l_1db9;
	case 7614ULL: goto x86_l_1dbe;
	case 7617ULL: goto x86_l_1dc1;
	case 7623ULL: goto x86_l_1dc7;
	case 7625ULL: goto x86_l_1dc9;
	case 7628ULL: goto x86_l_1dcc;
	case 7630ULL: goto x86_l_1dce;
	case 7635ULL: goto x86_l_1dd3;
	case 7638ULL: goto x86_l_1dd6;
	case 7640ULL: goto x86_l_1dd8;
	case 7643ULL: goto x86_l_1ddb;
	case 7649ULL: goto x86_l_1de1;
	case 7652ULL: goto x86_l_1de4;
	case 7655ULL: goto x86_l_1de7;
	case 7661ULL: goto x86_l_1ded;
	case 7664ULL: goto x86_l_1df0;
	case 7666ULL: goto x86_l_1df2;
	case 7669ULL: goto x86_l_1df5;
	case 7675ULL: goto x86_l_1dfb;
	case 7678ULL: goto x86_l_1dfe;
	case 7684ULL: goto x86_l_1e04;
	case 7687ULL: goto x86_l_1e07;
	case 7689ULL: goto x86_l_1e09;
	case 7692ULL: goto x86_l_1e0c;
	case 7698ULL: goto x86_l_1e12;
	case 7701ULL: goto x86_l_1e15;
	case 7707ULL: goto x86_l_1e1b;
	case 7709ULL: goto x86_l_1e1d;
	case 7712ULL: goto x86_l_1e20;
	case 7718ULL: goto x86_l_1e26;
	case 7721ULL: goto x86_l_1e29;
	case 7727ULL: goto x86_l_1e2f;
	case 7732ULL: goto x86_l_1e34;
	case 7735ULL: goto x86_l_1e37;
	case 7738ULL: goto x86_l_1e3a;
	case 7742ULL: goto x86_l_1e3e;
	case 7745ULL: goto x86_l_1e41;
	case 7748ULL: goto x86_l_1e44;
	case 7751ULL: goto x86_l_1e47;
	case 7754ULL: goto x86_l_1e4a;
	case 7760ULL: goto x86_l_1e50;
	case 7763ULL: goto x86_l_1e53;
	case 7767ULL: goto x86_l_1e57;
	case 7770ULL: goto x86_l_1e5a;
	case 7774ULL: goto x86_l_1e5e;
	case 7777ULL: goto x86_l_1e61;
	case 7780ULL: goto x86_l_1e64;
	case 7783ULL: goto x86_l_1e67;
	case 7789ULL: goto x86_l_1e6d;
	case 7792ULL: goto x86_l_1e70;
	case 7796ULL: goto x86_l_1e74;
	case 7799ULL: goto x86_l_1e77;
	case 7803ULL: goto x86_l_1e7b;
	case 7806ULL: goto x86_l_1e7e;
	case 7809ULL: goto x86_l_1e81;
	case 7812ULL: goto x86_l_1e84;
	case 7818ULL: goto x86_l_1e8a;
	case 7821ULL: goto x86_l_1e8d;
	case 7824ULL: goto x86_l_1e90;
	case 7827ULL: goto x86_l_1e93;
	case 7831ULL: goto x86_l_1e97;
	case 7833ULL: goto x86_l_1e99;
	case 7835ULL: goto x86_l_1e9b;
	case 7838ULL: goto x86_l_1e9e;
	case 7840ULL: goto x86_l_1ea0;
	case 7845ULL: goto x86_l_1ea5;
	case 7848ULL: goto x86_l_1ea8;
	case 7850ULL: goto x86_l_1eaa;
	case 7853ULL: goto x86_l_1ead;
	case 7855ULL: goto x86_l_1eaf;
	case 7856ULL: goto x86_l_1eb0;
	case 7859ULL: goto x86_l_1eb3;
	case 7862ULL: goto x86_l_1eb6;
	case 7866ULL: goto x86_l_1eba;
	case 7869ULL: goto x86_l_1ebd;
	case 7872ULL: goto x86_l_1ec0;
	case 7875ULL: goto x86_l_1ec3;
	case 7878ULL: goto x86_l_1ec6;
	case 7884ULL: goto x86_l_1ecc;
	case 7887ULL: goto x86_l_1ecf;
	case 7891ULL: goto x86_l_1ed3;
	case 7894ULL: goto x86_l_1ed6;
	case 7898ULL: goto x86_l_1eda;
	case 7901ULL: goto x86_l_1edd;
	case 7904ULL: goto x86_l_1ee0;
	case 7907ULL: goto x86_l_1ee3;
	case 7909ULL: goto x86_l_1ee5;
	case 7912ULL: goto x86_l_1ee8;
	case 7916ULL: goto x86_l_1eec;
	case 7919ULL: goto x86_l_1eef;
	case 7923ULL: goto x86_l_1ef3;
	case 7926ULL: goto x86_l_1ef6;
	case 7929ULL: goto x86_l_1ef9;
	case 7932ULL: goto x86_l_1efc;
	case 7934ULL: goto x86_l_1efe;
	case 7937ULL: goto x86_l_1f01;
	case 7940ULL: goto x86_l_1f04;
	case 7943ULL: goto x86_l_1f07;
	case 7947ULL: goto x86_l_1f0b;
	case 7950ULL: goto x86_l_1f0e;
	case 7953ULL: goto x86_l_1f11;
	case 7955ULL: goto x86_l_1f13;
	case 7958ULL: goto x86_l_1f16;
	case 7961ULL: goto x86_l_1f19;
	case 7963ULL: goto x86_l_1f1b;
	case 7966ULL: goto x86_l_1f1e;
	case 7968ULL: goto x86_l_1f20;
	case 7971ULL: goto x86_l_1f23;
	case 7973ULL: goto x86_l_1f25;
	case 7976ULL: goto x86_l_1f28;
	case 7978ULL: goto x86_l_1f2a;
	case 7981ULL: goto x86_l_1f2d;
	case 7983ULL: goto x86_l_1f2f;
	case 7986ULL: goto x86_l_1f32;
	case 7992ULL: goto x86_l_1f38;
	case 7995ULL: goto x86_l_1f3b;
	case 7997ULL: goto x86_l_1f3d;
	case 7999ULL: goto x86_l_1f3f;
	case 8002ULL: goto x86_l_1f42;
	case 8004ULL: goto x86_l_1f44;
	case 8007ULL: goto x86_l_1f47;
	case 8013ULL: goto x86_l_1f4d;
	case 8015ULL: goto x86_l_1f4f;
	case 8017ULL: goto x86_l_1f51;
	case 8020ULL: goto x86_l_1f54;
	case 8023ULL: goto x86_l_1f57;
	case 8026ULL: goto x86_l_1f5a;
	case 8028ULL: goto x86_l_1f5c;
	case 8031ULL: goto x86_l_1f5f;
	case 8032ULL: goto x86_l_1f60;
	case 8034ULL: goto x86_l_1f62;
	case 8035ULL: goto x86_l_1f63;
	case 8039ULL: goto x86_l_1f67;
	case 8042ULL: goto x86_l_1f6a;
	case 8045ULL: goto x86_l_1f6d;
	case 8049ULL: goto x86_l_1f71;
	case 8053ULL: goto x86_l_1f75;
	case 8060ULL: goto x86_l_1f7c;
	case 8065ULL: goto x86_l_1f81;
	case 8070ULL: goto x86_l_1f86;
	case 8072ULL: goto x86_l_1f88;
	case 8075ULL: goto x86_l_1f8b;
	case 8077ULL: goto x86_l_1f8d;
	case 8080ULL: goto x86_l_1f90;
	case 8083ULL: goto x86_l_1f93;
	case 8088ULL: goto x86_l_1f98;
	case 8093ULL: goto x86_l_1f9d;
	case 8098ULL: goto x86_l_1fa2;
	case 8100ULL: goto x86_l_1fa4;
	case 8103ULL: goto x86_l_1fa7;
	case 8105ULL: goto x86_l_1fa9;
	case 8108ULL: goto x86_l_1fac;
	case 8110ULL: goto x86_l_1fae;
	case 8115ULL: goto x86_l_1fb3;
	case 8118ULL: goto x86_l_1fb6;
	case 8120ULL: goto x86_l_1fb8;
	case 8123ULL: goto x86_l_1fbb;
	case 8126ULL: goto x86_l_1fbe;
	case 8128ULL: goto x86_l_1fc0;
	case 8130ULL: goto x86_l_1fc2;
	case 8134ULL: goto x86_l_1fc6;
	case 8135ULL: goto x86_l_1fc7;
	case 8137ULL: goto x86_l_1fc9;
	case 8138ULL: goto x86_l_1fca;
	case 8143ULL: goto x86_l_1fcf;
	case 8146ULL: goto x86_l_1fd2;
	case 8148ULL: goto x86_l_1fd4;
	case 8151ULL: goto x86_l_1fd7;
	case 8154ULL: goto x86_l_1fda;
	case 8157ULL: goto x86_l_1fdd;
	case 8161ULL: goto x86_l_1fe1;
	case 8162ULL: goto x86_l_1fe2;
	case 8164ULL: goto x86_l_1fe4;
	case 8165ULL: goto x86_l_1fe5;
	case 8168ULL: goto x86_l_1fe8;
	case 8173ULL: goto x86_l_1fed;
	case 8177ULL: goto x86_l_1ff1;
	case 8179ULL: goto x86_l_1ff3;
	case 8189ULL: goto x86_l_1ffd;
	case 8193ULL: goto x86_l_2001;
	case 8195ULL: goto x86_l_2003;
	case 8196ULL: goto x86_l_2004;
	case 8201ULL: goto x86_l_2009;
	case 8205ULL: goto x86_l_200d;
	case 8207ULL: goto x86_l_200f;
	case 8210ULL: goto x86_l_2012;
	case 8213ULL: goto x86_l_2015;
	case 8219ULL: goto x86_l_201b;
	case 8221ULL: goto x86_l_201d;
	case 8224ULL: goto x86_l_2020;
	case 8227ULL: goto x86_l_2023;
	case 8228ULL: goto x86_l_2024;
	case 8232ULL: goto x86_l_2028;
	case 8234ULL: goto x86_l_202a;
	case 8237ULL: goto x86_l_202d;
	case 8240ULL: goto x86_l_2030;
	case 8242ULL: goto x86_l_2032;
	case 8245ULL: goto x86_l_2035;
	case 8248ULL: goto x86_l_2038;
	case 8254ULL: goto x86_l_203e;
	case 8257ULL: goto x86_l_2041;
	case 8259ULL: goto x86_l_2043;
	case 8262ULL: goto x86_l_2046;
	case 8268ULL: goto x86_l_204c;
	case 8271ULL: goto x86_l_204f;
	case 8273ULL: goto x86_l_2051;
	case 8276ULL: goto x86_l_2054;
	case 8282ULL: goto x86_l_205a;
	case 8285ULL: goto x86_l_205d;
	case 8287ULL: goto x86_l_205f;
	case 8292ULL: goto x86_l_2064;
	case 8295ULL: goto x86_l_2067;
	case 8297ULL: goto x86_l_2069;
	case 8300ULL: goto x86_l_206c;
	case 8306ULL: goto x86_l_2072;
	case 8309ULL: goto x86_l_2075;
	case 8312ULL: goto x86_l_2078;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1b5f:
	/* 0x1b5f: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_1b64:
	/* 0x1b64: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1b67:
	/* 0x1b67: jae    1b7b <filter_16ty_map+0x6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1b7b;
	}
x86_l_1b69:
	/* 0x1b69: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b6c:
	/* 0x1b6c: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_1b6f:
	/* 0x1b6f: jmp    1b8b <filter_16ty_map+0x7b> */
	goto x86_l_1b8b;
x86_l_1b71:
	/* 0x1b71: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b73:
	/* 0x1b73: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1b77:
	/* 0x1b77: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1b78:
	/* 0x1b78: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_1b7a:
	/* 0x1b7a: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1b7b:
	/* 0x1b7b: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_1b80:
	/* 0x1b80: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1b83:
	/* 0x1b83: jae    1b8b <filter_16ty_map+0x7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1b8b;
	}
x86_l_1b85:
	/* 0x1b85: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b88:
	/* 0x1b88: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_1b8b:
	/* 0x1b8b: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1b8e:
	/* 0x1b8e: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1b92:
	/* 0x1b92: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1b93:
	/* 0x1b93: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_1b95:
	/* 0x1b95: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1b96:
	/* 0x1b96: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1b99:
	/* 0x1b99: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b9e:
	/* 0x1b9e: cmp    rcx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 37ULL);
x86_l_1ba2:
	/* 0x1ba2: ja     1c13 <filter_32ty_selector_val+0x7d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1c13;
	}
x86_l_1ba4:
	/* 0x1ba4: movabs rdx,0x200c000040 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280128ULL);
x86_l_1bae:
	/* 0x1bae: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1bb2:
	/* 0x1bb2: jae    1bb5 <filter_32ty_selector_val+0x1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1bb5;
	}
x86_l_1bb4:
	/* 0x1bb4: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1bb5:
	/* 0x1bb5: mov    edx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 24ULL);
x86_l_1bba:
	/* 0x1bba: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1bbe:
	/* 0x1bbe: jae    1bd4 <filter_32ty_selector_val+0x3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1bd4;
	}
x86_l_1bc0:
	/* 0x1bc0: mov    edx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bc2:
	/* 0x1bc2: cmp    edx,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_1bc5:
	/* 0x1bc5: jne    1ce7 <filter_32ty_selector_val+0x151> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ce7;
	}
x86_l_1bcb:
	/* 0x1bcb: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bcd:
	/* 0x1bcd: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1bd0:
	/* 0x1bd0: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_1bd3:
	/* 0x1bd3: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1bd4:
	/* 0x1bd4: cmp    rcx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 12ULL);
x86_l_1bd8:
	/* 0x1bd8: jne    1c13 <filter_32ty_selector_val+0x7d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1c13;
	}
x86_l_1bda:
	/* 0x1bda: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bdc:
	/* 0x1bdc: test   DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bdf:
	/* 0x1bdf: jne    1bb4 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1bb4;
	}
x86_l_1be1:
	/* 0x1be1: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1be4:
	/* 0x1be4: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1be7:
	/* 0x1be7: jb     1da7 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1da7;
	}
x86_l_1bed:
	/* 0x1bed: test   DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1bf0:
	/* 0x1bf0: jne    1bb4 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1bb4;
	}
x86_l_1bf2:
	/* 0x1bf2: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1bf5:
	/* 0x1bf5: jb     1da7 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1da7;
	}
x86_l_1bfb:
	/* 0x1bfb: test   DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1bfe:
	/* 0x1bfe: jne    1bb4 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1bb4;
	}
x86_l_1c00:
	/* 0x1c00: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_1c03:
	/* 0x1c03: jb     1da7 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1da7;
	}
x86_l_1c09:
	/* 0x1c09: test   DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1c0c:
	/* 0x1c0c: jne    1bb4 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1bb4;
	}
x86_l_1c0e:
	/* 0x1c0e: jmp    1da7 <filter_32ty_selector_val+0x211> */
	goto x86_l_1da7;
x86_l_1c13:
	/* 0x1c13: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1c16:
	/* 0x1c16: je     1c84 <filter_32ty_selector_val+0xee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c84;
	}
x86_l_1c18:
	/* 0x1c18: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1c1b:
	/* 0x1c1b: jne    1da7 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1da7;
	}
x86_l_1c21:
	/* 0x1c21: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1c24:
	/* 0x1c24: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1c27:
	/* 0x1c27: ja     1d6f <filter_32ty_selector_val+0x1d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1d6f;
	}
x86_l_1c2d:
	/* 0x1c2d: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_1c32:
	/* 0x1c32: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_1c35:
	/* 0x1c35: jae    1d6f <filter_32ty_selector_val+0x1d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1d6f;
	}
x86_l_1c3b:
	/* 0x1c3b: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c3d:
	/* 0x1c3d: cmp    ecx,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_1c40:
	/* 0x1c40: jl     1bb4 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_1bb4;
	}
x86_l_1c46:
	/* 0x1c46: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c49:
	/* 0x1c49: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1c4c:
	/* 0x1c4c: jb     1da7 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1da7;
	}
x86_l_1c52:
	/* 0x1c52: cmp    ecx,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1c55:
	/* 0x1c55: jl     1bb4 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_1bb4;
	}
x86_l_1c5b:
	/* 0x1c5b: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1c5e:
	/* 0x1c5e: jb     1da7 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1da7;
	}
x86_l_1c64:
	/* 0x1c64: cmp    ecx,DWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 24ULL);
x86_l_1c67:
	/* 0x1c67: jl     1bb4 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_1bb4;
	}
x86_l_1c6d:
	/* 0x1c6d: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_1c70:
	/* 0x1c70: jb     1da7 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1da7;
	}
x86_l_1c76:
	/* 0x1c76: cmp    ecx,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1c79:
	/* 0x1c79: jl     1bb4 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_1bb4;
	}
x86_l_1c7f:
	/* 0x1c7f: jmp    1da7 <filter_32ty_selector_val+0x211> */
	goto x86_l_1da7;
x86_l_1c84:
	/* 0x1c84: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1c87:
	/* 0x1c87: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1c8a:
	/* 0x1c8a: ja     1d35 <filter_32ty_selector_val+0x19f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1d35;
	}
x86_l_1c90:
	/* 0x1c90: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_1c95:
	/* 0x1c95: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_1c98:
	/* 0x1c98: jae    1d35 <filter_32ty_selector_val+0x19f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1d35;
	}
x86_l_1c9e:
	/* 0x1c9e: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ca0:
	/* 0x1ca0: cmp    ecx,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_1ca3:
	/* 0x1ca3: jg     1bb4 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1bb4;
	}
x86_l_1ca9:
	/* 0x1ca9: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cac:
	/* 0x1cac: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1caf:
	/* 0x1caf: jb     1da7 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1da7;
	}
x86_l_1cb5:
	/* 0x1cb5: cmp    ecx,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1cb8:
	/* 0x1cb8: jg     1bb4 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1bb4;
	}
x86_l_1cbe:
	/* 0x1cbe: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1cc1:
	/* 0x1cc1: jb     1da7 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1da7;
	}
x86_l_1cc7:
	/* 0x1cc7: cmp    ecx,DWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 24ULL);
x86_l_1cca:
	/* 0x1cca: jg     1bb4 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1bb4;
	}
x86_l_1cd0:
	/* 0x1cd0: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_1cd3:
	/* 0x1cd3: jb     1da7 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1da7;
	}
x86_l_1cd9:
	/* 0x1cd9: cmp    ecx,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1cdc:
	/* 0x1cdc: jg     1bb4 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1bb4;
	}
x86_l_1ce2:
	/* 0x1ce2: jmp    1da7 <filter_32ty_selector_val+0x211> */
	goto x86_l_1da7;
x86_l_1ce7:
	/* 0x1ce7: mov    esi,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cea:
	/* 0x1cea: cmp    esi,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 13ULL);
x86_l_1ced:
	/* 0x1ced: jb     1d14 <filter_32ty_selector_val+0x17e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d14;
	}
x86_l_1cef:
	/* 0x1cef: cmp    edx,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1cf2:
	/* 0x1cf2: je     1bcb <filter_32ty_selector_val+0x35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bcb;
	}
x86_l_1cf8:
	/* 0x1cf8: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_1cfb:
	/* 0x1cfb: jb     1d14 <filter_32ty_selector_val+0x17e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d14;
	}
x86_l_1cfd:
	/* 0x1cfd: cmp    edx,DWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 24ULL);
x86_l_1d00:
	/* 0x1d00: je     1bcb <filter_32ty_selector_val+0x35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bcb;
	}
x86_l_1d06:
	/* 0x1d06: cmp    esi,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 21ULL);
x86_l_1d09:
	/* 0x1d09: jb     1d14 <filter_32ty_selector_val+0x17e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d14;
	}
x86_l_1d0b:
	/* 0x1d0b: cmp    edx,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1d0e:
	/* 0x1d0e: je     1bcb <filter_32ty_selector_val+0x35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bcb;
	}
x86_l_1d14:
	/* 0x1d14: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_1d17:
	/* 0x1d17: ja     1da7 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1da7;
	}
x86_l_1d1d:
	/* 0x1d1d: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1d1f:
	/* 0x1d1f: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_1d29:
	/* 0x1d29: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1d2d:
	/* 0x1d2d: jb     1bb4 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1bb4;
	}
x86_l_1d33:
	/* 0x1d33: jmp    1da7 <filter_32ty_selector_val+0x211> */
	goto x86_l_1da7;
x86_l_1d35:
	/* 0x1d35: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d37:
	/* 0x1d37: cmp    ecx,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_1d3a:
	/* 0x1d3a: ja     1bb4 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1bb4;
	}
x86_l_1d40:
	/* 0x1d40: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d43:
	/* 0x1d43: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1d46:
	/* 0x1d46: jb     1da7 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1da7;
	}
x86_l_1d48:
	/* 0x1d48: cmp    ecx,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1d4b:
	/* 0x1d4b: ja     1bb4 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1bb4;
	}
x86_l_1d51:
	/* 0x1d51: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1d54:
	/* 0x1d54: jb     1da7 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1da7;
	}
x86_l_1d56:
	/* 0x1d56: cmp    ecx,DWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 24ULL);
x86_l_1d59:
	/* 0x1d59: ja     1bb4 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1bb4;
	}
x86_l_1d5f:
	/* 0x1d5f: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_1d62:
	/* 0x1d62: jb     1da7 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1da7;
	}
x86_l_1d64:
	/* 0x1d64: cmp    ecx,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1d67:
	/* 0x1d67: ja     1bb4 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1bb4;
	}
x86_l_1d6d:
	/* 0x1d6d: jmp    1da7 <filter_32ty_selector_val+0x211> */
	goto x86_l_1da7;
x86_l_1d6f:
	/* 0x1d6f: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d71:
	/* 0x1d71: cmp    ecx,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_1d74:
	/* 0x1d74: jb     1bb4 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1bb4;
	}
x86_l_1d7a:
	/* 0x1d7a: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d7d:
	/* 0x1d7d: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1d80:
	/* 0x1d80: jb     1da7 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1da7;
	}
x86_l_1d82:
	/* 0x1d82: cmp    ecx,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1d85:
	/* 0x1d85: jb     1bb4 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1bb4;
	}
x86_l_1d8b:
	/* 0x1d8b: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1d8e:
	/* 0x1d8e: jb     1da7 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1da7;
	}
x86_l_1d90:
	/* 0x1d90: cmp    ecx,DWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 24ULL);
x86_l_1d93:
	/* 0x1d93: jb     1bb4 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1bb4;
	}
x86_l_1d99:
	/* 0x1d99: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_1d9c:
	/* 0x1d9c: jb     1da7 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1da7;
	}
x86_l_1d9e:
	/* 0x1d9e: cmp    ecx,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1da1:
	/* 0x1da1: jb     1bb4 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1bb4;
	}
x86_l_1da7:
	/* 0x1da7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1da9:
	/* 0x1da9: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1daa:
	/* 0x1daa: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1dad:
	/* 0x1dad: mov    eax,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1db0:
	/* 0x1db0: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1db3:
	/* 0x1db3: ja     1e99 <filter_32ty_range+0xef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1e99;
	}
x86_l_1db9:
	/* 0x1db9: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_1dbe:
	/* 0x1dbe: bt     edx,eax */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_1dc1:
	/* 0x1dc1: jae    1e99 <filter_32ty_range+0xef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1e99;
	}
x86_l_1dc7:
	/* 0x1dc7: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1dc9:
	/* 0x1dc9: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_1dcc:
	/* 0x1dcc: jne    1e34 <filter_32ty_range+0x8a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e34;
	}
x86_l_1dce:
	/* 0x1dce: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1dd3:
	/* 0x1dd3: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1dd6:
	/* 0x1dd6: jg     1de1 <filter_32ty_range+0x37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1de1;
	}
x86_l_1dd8:
	/* 0x1dd8: cmp    esi,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1ddb:
	/* 0x1ddb: jle    1eaf <filter_32ty_range+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1eaf;
	}
x86_l_1de1:
	/* 0x1de1: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1de4:
	/* 0x1de4: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1de7:
	/* 0x1de7: jb     1f4f <filter_32ty_range+0x1a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1f4f;
	}
x86_l_1ded:
	/* 0x1ded: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1df0:
	/* 0x1df0: jg     1dfb <filter_32ty_range+0x51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1dfb;
	}
x86_l_1df2:
	/* 0x1df2: cmp    esi,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1df5:
	/* 0x1df5: jle    1eaf <filter_32ty_range+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1eaf;
	}
x86_l_1dfb:
	/* 0x1dfb: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_1dfe:
	/* 0x1dfe: jb     1f4f <filter_32ty_range+0x1a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1f4f;
	}
x86_l_1e04:
	/* 0x1e04: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e07:
	/* 0x1e07: jg     1e12 <filter_32ty_range+0x68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1e12;
	}
x86_l_1e09:
	/* 0x1e09: cmp    esi,DWORD PTR [rdi+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_1e0c:
	/* 0x1e0c: jle    1eaf <filter_32ty_range+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1eaf;
	}
x86_l_1e12:
	/* 0x1e12: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_1e15:
	/* 0x1e15: jb     1f4f <filter_32ty_range+0x1a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1f4f;
	}
x86_l_1e1b:
	/* 0x1e1b: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e1d:
	/* 0x1e1d: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1e20:
	/* 0x1e20: jg     1f51 <filter_32ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1f51;
	}
x86_l_1e26:
	/* 0x1e26: cmp    esi,DWORD PTR [rdi+0x2c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 44ULL);
x86_l_1e29:
	/* 0x1e29: jle    1eaf <filter_32ty_range+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1eaf;
	}
x86_l_1e2f:
	/* 0x1e2f: jmp    1f51 <filter_32ty_range+0x1a7> */
	goto x86_l_1f51;
x86_l_1e34:
	/* 0x1e34: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e37:
	/* 0x1e37: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e3a:
	/* 0x1e3a: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_1e3e:
	/* 0x1e3e: cmp    esi,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1e41:
	/* 0x1e41: setle  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_LE);
x86_l_1e44:
	/* 0x1e44: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1e47:
	/* 0x1e47: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1e4a:
	/* 0x1e4a: jb     1f51 <filter_32ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1f51;
	}
x86_l_1e50:
	/* 0x1e50: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1e53:
	/* 0x1e53: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_1e57:
	/* 0x1e57: cmp    esi,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1e5a:
	/* 0x1e5a: setle  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_LE);
x86_l_1e5e:
	/* 0x1e5e: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1e61:
	/* 0x1e61: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_1e64:
	/* 0x1e64: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1e67:
	/* 0x1e67: jb     1f51 <filter_32ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1f51;
	}
x86_l_1e6d:
	/* 0x1e6d: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e70:
	/* 0x1e70: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_1e74:
	/* 0x1e74: cmp    esi,DWORD PTR [rdi+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_1e77:
	/* 0x1e77: setle  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_LE);
x86_l_1e7b:
	/* 0x1e7b: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1e7e:
	/* 0x1e7e: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_1e81:
	/* 0x1e81: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_1e84:
	/* 0x1e84: jb     1f51 <filter_32ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1f51;
	}
x86_l_1e8a:
	/* 0x1e8a: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1e8d:
	/* 0x1e8d: setle  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_LE);
x86_l_1e90:
	/* 0x1e90: cmp    esi,DWORD PTR [rdi+0x2c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 44ULL);
x86_l_1e93:
	/* 0x1e93: setle  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_LE);
x86_l_1e97:
	/* 0x1e97: jmp    1f0b <filter_32ty_range+0x161> */
	goto x86_l_1f0b;
x86_l_1e99:
	/* 0x1e99: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e9b:
	/* 0x1e9b: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_1e9e:
	/* 0x1e9e: jne    1eb0 <filter_32ty_range+0x106> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1eb0;
	}
x86_l_1ea0:
	/* 0x1ea0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ea5:
	/* 0x1ea5: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ea8:
	/* 0x1ea8: ja     1f13 <filter_32ty_range+0x169> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1f13;
	}
x86_l_1eaa:
	/* 0x1eaa: cmp    esi,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1ead:
	/* 0x1ead: ja     1f13 <filter_32ty_range+0x169> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1f13;
	}
x86_l_1eaf:
	/* 0x1eaf: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1eb0:
	/* 0x1eb0: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1eb3:
	/* 0x1eb3: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1eb6:
	/* 0x1eb6: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_1eba:
	/* 0x1eba: cmp    esi,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1ebd:
	/* 0x1ebd: setbe  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_BE);
x86_l_1ec0:
	/* 0x1ec0: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1ec3:
	/* 0x1ec3: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1ec6:
	/* 0x1ec6: jb     1f51 <filter_32ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1f51;
	}
x86_l_1ecc:
	/* 0x1ecc: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ecf:
	/* 0x1ecf: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_1ed3:
	/* 0x1ed3: cmp    esi,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1ed6:
	/* 0x1ed6: setbe  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_BE);
x86_l_1eda:
	/* 0x1eda: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1edd:
	/* 0x1edd: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_1ee0:
	/* 0x1ee0: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1ee3:
	/* 0x1ee3: jb     1f51 <filter_32ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1f51;
	}
x86_l_1ee5:
	/* 0x1ee5: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ee8:
	/* 0x1ee8: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_1eec:
	/* 0x1eec: cmp    esi,DWORD PTR [rdi+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_1eef:
	/* 0x1eef: setbe  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_BE);
x86_l_1ef3:
	/* 0x1ef3: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1ef6:
	/* 0x1ef6: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_1ef9:
	/* 0x1ef9: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_1efc:
	/* 0x1efc: jb     1f51 <filter_32ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1f51;
	}
x86_l_1efe:
	/* 0x1efe: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1f01:
	/* 0x1f01: setbe  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_BE);
x86_l_1f04:
	/* 0x1f04: cmp    esi,DWORD PTR [rdi+0x2c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 44ULL);
x86_l_1f07:
	/* 0x1f07: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_1f0b:
	/* 0x1f0b: and    sil,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_1f0e:
	/* 0x1f0e: or     dl,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_8, X86_ALU_OR);
x86_l_1f11:
	/* 0x1f11: jmp    1f51 <filter_32ty_range+0x1a7> */
	goto x86_l_1f51;
x86_l_1f13:
	/* 0x1f13: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f16:
	/* 0x1f16: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1f19:
	/* 0x1f19: jb     1f4f <filter_32ty_range+0x1a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1f4f;
	}
x86_l_1f1b:
	/* 0x1f1b: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1f1e:
	/* 0x1f1e: ja     1f25 <filter_32ty_range+0x17b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1f25;
	}
x86_l_1f20:
	/* 0x1f20: cmp    esi,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1f23:
	/* 0x1f23: jbe    1eaf <filter_32ty_range+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1eaf;
	}
x86_l_1f25:
	/* 0x1f25: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_1f28:
	/* 0x1f28: jb     1f4f <filter_32ty_range+0x1a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1f4f;
	}
x86_l_1f2a:
	/* 0x1f2a: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f2d:
	/* 0x1f2d: ja     1f38 <filter_32ty_range+0x18e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1f38;
	}
x86_l_1f2f:
	/* 0x1f2f: cmp    esi,DWORD PTR [rdi+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_1f32:
	/* 0x1f32: jbe    1eaf <filter_32ty_range+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1eaf;
	}
x86_l_1f38:
	/* 0x1f38: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_1f3b:
	/* 0x1f3b: jb     1f4f <filter_32ty_range+0x1a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1f4f;
	}
x86_l_1f3d:
	/* 0x1f3d: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f3f:
	/* 0x1f3f: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1f42:
	/* 0x1f42: ja     1f51 <filter_32ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1f51;
	}
x86_l_1f44:
	/* 0x1f44: cmp    esi,DWORD PTR [rdi+0x2c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 44ULL);
x86_l_1f47:
	/* 0x1f47: jbe    1eaf <filter_32ty_range+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1eaf;
	}
x86_l_1f4d:
	/* 0x1f4d: jmp    1f51 <filter_32ty_range+0x1a7> */
	goto x86_l_1f51;
x86_l_1f4f:
	/* 0x1f4f: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f51:
	/* 0x1f51: cmp    ecx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 32ULL);
x86_l_1f54:
	/* 0x1f54: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_1f57:
	/* 0x1f57: xor    dl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_1f5a:
	/* 0x1f5a: and    dl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_1f5c:
	/* 0x1f5c: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1f5f:
	/* 0x1f5f: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1f60:
	/* 0x1f60: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_1f62:
	/* 0x1f62: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_1f63:
	/* 0x1f63: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_1f67:
	/* 0x1f67: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_1f6a:
	/* 0x1f6a: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_1f6d:
	/* 0x1f6d: movzx  eax,BYTE PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1f71:
	/* 0x1f71: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1f75:
	/* 0x1f75: mov    rdi,QWORD PTR [rip+0xb60] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_1f7c:
	/* 0x1f7c: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1f81:
	/* 0x1f81: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f86:
	/* 0x1f86: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f88:
	/* 0x1f88: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f8b:
	/* 0x1f8b: je     1fc0 <filter_32ty_map+0x60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fc0;
	}
x86_l_1f8d:
	/* 0x1f8d: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1f90:
	/* 0x1f90: mov    eax,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f93:
	/* 0x1f93: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f98:
	/* 0x1f98: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f9d:
	/* 0x1f9d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1fa2:
	/* 0x1fa2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fa4:
	/* 0x1fa4: mov    edx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1fa7:
	/* 0x1fa7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fa9:
	/* 0x1fa9: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_1fac:
	/* 0x1fac: ja     1fda <filter_32ty_map+0x7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1fda;
	}
x86_l_1fae:
	/* 0x1fae: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_1fb3:
	/* 0x1fb3: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1fb6:
	/* 0x1fb6: jae    1fca <filter_32ty_map+0x6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1fca;
	}
x86_l_1fb8:
	/* 0x1fb8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1fbb:
	/* 0x1fbb: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_1fbe:
	/* 0x1fbe: jmp    1fda <filter_32ty_map+0x7a> */
	goto x86_l_1fda;
x86_l_1fc0:
	/* 0x1fc0: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fc2:
	/* 0x1fc2: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1fc6:
	/* 0x1fc6: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1fc7:
	/* 0x1fc7: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_1fc9:
	/* 0x1fc9: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1fca:
	/* 0x1fca: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_1fcf:
	/* 0x1fcf: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1fd2:
	/* 0x1fd2: jae    1fda <filter_32ty_map+0x7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1fda;
	}
x86_l_1fd4:
	/* 0x1fd4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1fd7:
	/* 0x1fd7: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_1fda:
	/* 0x1fda: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1fdd:
	/* 0x1fdd: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1fe1:
	/* 0x1fe1: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1fe2:
	/* 0x1fe2: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_1fe4:
	/* 0x1fe4: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1fe5:
	/* 0x1fe5: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1fe8:
	/* 0x1fe8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1fed:
	/* 0x1fed: cmp    rcx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 37ULL);
x86_l_1ff1:
	/* 0x1ff1: ja     2064 <filter_8ty_selector_val+0x7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2064;
	}
x86_l_1ff3:
	/* 0x1ff3: movabs rdx,0x200c000040 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280128ULL);
x86_l_1ffd:
	/* 0x1ffd: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_2001:
	/* 0x2001: jae    2004 <filter_8ty_selector_val+0x1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2004;
	}
x86_l_2003:
	/* 0x2003: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_2004:
	/* 0x2004: mov    edx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 24ULL);
x86_l_2009:
	/* 0x2009: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_200d:
	/* 0x200d: jae    2024 <filter_8ty_selector_val+0x3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2024;
	}
x86_l_200f:
	/* 0x200f: movzx  edx,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2012:
	/* 0x2012: cmp    DWORD PTR [rdi+0x10],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2015:
	/* 0x2015: jne    213a <filter_8ty_selector_val+0x155> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8506ULL;
	}
x86_l_201b:
	/* 0x201b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_201d:
	/* 0x201d: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_2020:
	/* 0x2020: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_2023:
	/* 0x2023: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_2024:
	/* 0x2024: cmp    rcx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 12ULL);
x86_l_2028:
	/* 0x2028: jne    2064 <filter_8ty_selector_val+0x7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2064;
	}
x86_l_202a:
	/* 0x202a: movzx  ecx,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_202d:
	/* 0x202d: test   DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2030:
	/* 0x2030: jne    2003 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2003;
	}
x86_l_2032:
	/* 0x2032: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2035:
	/* 0x2035: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_2038:
	/* 0x2038: jb     21fc <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8700ULL;
	}
x86_l_203e:
	/* 0x203e: test   DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2041:
	/* 0x2041: jne    2003 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2003;
	}
x86_l_2043:
	/* 0x2043: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_2046:
	/* 0x2046: jb     21fc <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8700ULL;
	}
x86_l_204c:
	/* 0x204c: test   DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_204f:
	/* 0x204f: jne    2003 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2003;
	}
x86_l_2051:
	/* 0x2051: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_2054:
	/* 0x2054: jb     21fc <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8700ULL;
	}
x86_l_205a:
	/* 0x205a: test   DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_205d:
	/* 0x205d: jne    2003 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2003;
	}
x86_l_205f:
	/* 0x205f: jmp    21fc <filter_8ty_selector_val+0x217> */
	return 8700ULL;
x86_l_2064:
	/* 0x2064: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2067:
	/* 0x2067: je     20d6 <filter_8ty_selector_val+0xf1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8406ULL;
	}
x86_l_2069:
	/* 0x2069: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_206c:
	/* 0x206c: jne    21fc <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8700ULL;
	}
x86_l_2072:
	/* 0x2072: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2075:
	/* 0x2075: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2078:
	/* 0x2078: ja     21c3 <filter_8ty_selector_val+0x1de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8643ULL;
	}
	return 8318ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v61_generic_uprobe_filter_arg_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8318ULL: goto x86_l_207e;
	case 8323ULL: goto x86_l_2083;
	case 8326ULL: goto x86_l_2086;
	case 8332ULL: goto x86_l_208c;
	case 8335ULL: goto x86_l_208f;
	case 8338ULL: goto x86_l_2092;
	case 8344ULL: goto x86_l_2098;
	case 8347ULL: goto x86_l_209b;
	case 8350ULL: goto x86_l_209e;
	case 8356ULL: goto x86_l_20a4;
	case 8359ULL: goto x86_l_20a7;
	case 8365ULL: goto x86_l_20ad;
	case 8368ULL: goto x86_l_20b0;
	case 8374ULL: goto x86_l_20b6;
	case 8377ULL: goto x86_l_20b9;
	case 8383ULL: goto x86_l_20bf;
	case 8386ULL: goto x86_l_20c2;
	case 8392ULL: goto x86_l_20c8;
	case 8395ULL: goto x86_l_20cb;
	case 8401ULL: goto x86_l_20d1;
	case 8406ULL: goto x86_l_20d6;
	case 8409ULL: goto x86_l_20d9;
	case 8412ULL: goto x86_l_20dc;
	case 8418ULL: goto x86_l_20e2;
	case 8423ULL: goto x86_l_20e7;
	case 8426ULL: goto x86_l_20ea;
	case 8432ULL: goto x86_l_20f0;
	case 8435ULL: goto x86_l_20f3;
	case 8438ULL: goto x86_l_20f6;
	case 8444ULL: goto x86_l_20fc;
	case 8447ULL: goto x86_l_20ff;
	case 8450ULL: goto x86_l_2102;
	case 8456ULL: goto x86_l_2108;
	case 8459ULL: goto x86_l_210b;
	case 8465ULL: goto x86_l_2111;
	case 8468ULL: goto x86_l_2114;
	case 8474ULL: goto x86_l_211a;
	case 8477ULL: goto x86_l_211d;
	case 8483ULL: goto x86_l_2123;
	case 8486ULL: goto x86_l_2126;
	case 8492ULL: goto x86_l_212c;
	case 8495ULL: goto x86_l_212f;
	case 8501ULL: goto x86_l_2135;
	case 8506ULL: goto x86_l_213a;
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
	case 8542ULL: goto x86_l_215e;
	case 8545ULL: goto x86_l_2161;
	case 8551ULL: goto x86_l_2167;
	case 8554ULL: goto x86_l_216a;
	case 8560ULL: goto x86_l_2170;
	case 8562ULL: goto x86_l_2172;
	case 8572ULL: goto x86_l_217c;
	case 8576ULL: goto x86_l_2180;
	case 8582ULL: goto x86_l_2186;
	case 8584ULL: goto x86_l_2188;
	case 8587ULL: goto x86_l_218b;
	case 8590ULL: goto x86_l_218e;
	case 8596ULL: goto x86_l_2194;
	case 8599ULL: goto x86_l_2197;
	case 8602ULL: goto x86_l_219a;
	case 8604ULL: goto x86_l_219c;
	case 8607ULL: goto x86_l_219f;
	case 8613ULL: goto x86_l_21a5;
	case 8616ULL: goto x86_l_21a8;
	case 8618ULL: goto x86_l_21aa;
	case 8621ULL: goto x86_l_21ad;
	case 8627ULL: goto x86_l_21b3;
	case 8630ULL: goto x86_l_21b6;
	case 8632ULL: goto x86_l_21b8;
	case 8635ULL: goto x86_l_21bb;
	case 8641ULL: goto x86_l_21c1;
	case 8643ULL: goto x86_l_21c3;
	case 8646ULL: goto x86_l_21c6;
	case 8649ULL: goto x86_l_21c9;
	case 8655ULL: goto x86_l_21cf;
	case 8658ULL: goto x86_l_21d2;
	case 8661ULL: goto x86_l_21d5;
	case 8663ULL: goto x86_l_21d7;
	case 8666ULL: goto x86_l_21da;
	case 8672ULL: goto x86_l_21e0;
	case 8675ULL: goto x86_l_21e3;
	case 8677ULL: goto x86_l_21e5;
	case 8680ULL: goto x86_l_21e8;
	case 8686ULL: goto x86_l_21ee;
	case 8689ULL: goto x86_l_21f1;
	case 8691ULL: goto x86_l_21f3;
	case 8694ULL: goto x86_l_21f6;
	case 8700ULL: goto x86_l_21fc;
	case 8702ULL: goto x86_l_21fe;
	case 8703ULL: goto x86_l_21ff;
	case 8706ULL: goto x86_l_2202;
	case 8709ULL: goto x86_l_2205;
	case 8712ULL: goto x86_l_2208;
	case 8718ULL: goto x86_l_220e;
	case 8723ULL: goto x86_l_2213;
	case 8726ULL: goto x86_l_2216;
	case 8732ULL: goto x86_l_221c;
	case 8735ULL: goto x86_l_221f;
	case 8738ULL: goto x86_l_2222;
	case 8740ULL: goto x86_l_2224;
	case 8745ULL: goto x86_l_2229;
	case 8748ULL: goto x86_l_222c;
	case 8750ULL: goto x86_l_222e;
	case 8753ULL: goto x86_l_2231;
	case 8759ULL: goto x86_l_2237;
	case 8762ULL: goto x86_l_223a;
	case 8765ULL: goto x86_l_223d;
	case 8771ULL: goto x86_l_2243;
	case 8774ULL: goto x86_l_2246;
	case 8776ULL: goto x86_l_2248;
	case 8779ULL: goto x86_l_224b;
	case 8785ULL: goto x86_l_2251;
	case 8788ULL: goto x86_l_2254;
	case 8794ULL: goto x86_l_225a;
	case 8797ULL: goto x86_l_225d;
	case 8799ULL: goto x86_l_225f;
	case 8802ULL: goto x86_l_2262;
	case 8808ULL: goto x86_l_2268;
	case 8811ULL: goto x86_l_226b;
	case 8817ULL: goto x86_l_2271;
	case 8819ULL: goto x86_l_2273;
	case 8822ULL: goto x86_l_2276;
	case 8828ULL: goto x86_l_227c;
	case 8831ULL: goto x86_l_227f;
	case 8837ULL: goto x86_l_2285;
	case 8842ULL: goto x86_l_228a;
	case 8845ULL: goto x86_l_228d;
	case 8848ULL: goto x86_l_2290;
	case 8852ULL: goto x86_l_2294;
	case 8855ULL: goto x86_l_2297;
	case 8858ULL: goto x86_l_229a;
	case 8861ULL: goto x86_l_229d;
	case 8864ULL: goto x86_l_22a0;
	case 8870ULL: goto x86_l_22a6;
	case 8873ULL: goto x86_l_22a9;
	case 8877ULL: goto x86_l_22ad;
	case 8880ULL: goto x86_l_22b0;
	case 8884ULL: goto x86_l_22b4;
	case 8887ULL: goto x86_l_22b7;
	case 8890ULL: goto x86_l_22ba;
	case 8893ULL: goto x86_l_22bd;
	case 8899ULL: goto x86_l_22c3;
	case 8902ULL: goto x86_l_22c6;
	case 8906ULL: goto x86_l_22ca;
	case 8909ULL: goto x86_l_22cd;
	case 8913ULL: goto x86_l_22d1;
	case 8916ULL: goto x86_l_22d4;
	case 8919ULL: goto x86_l_22d7;
	case 8922ULL: goto x86_l_22da;
	case 8928ULL: goto x86_l_22e0;
	case 8931ULL: goto x86_l_22e3;
	case 8934ULL: goto x86_l_22e6;
	case 8937ULL: goto x86_l_22e9;
	case 8941ULL: goto x86_l_22ed;
	case 8943ULL: goto x86_l_22ef;
	case 8946ULL: goto x86_l_22f2;
	case 8949ULL: goto x86_l_22f5;
	case 8951ULL: goto x86_l_22f7;
	case 8956ULL: goto x86_l_22fc;
	case 8959ULL: goto x86_l_22ff;
	case 8961ULL: goto x86_l_2301;
	case 8964ULL: goto x86_l_2304;
	case 8966ULL: goto x86_l_2306;
	case 8967ULL: goto x86_l_2307;
	case 8970ULL: goto x86_l_230a;
	case 8973ULL: goto x86_l_230d;
	case 8977ULL: goto x86_l_2311;
	case 8980ULL: goto x86_l_2314;
	case 8983ULL: goto x86_l_2317;
	case 8986ULL: goto x86_l_231a;
	case 8989ULL: goto x86_l_231d;
	case 8995ULL: goto x86_l_2323;
	case 8998ULL: goto x86_l_2326;
	case 9002ULL: goto x86_l_232a;
	case 9005ULL: goto x86_l_232d;
	case 9009ULL: goto x86_l_2331;
	case 9012ULL: goto x86_l_2334;
	case 9015ULL: goto x86_l_2337;
	case 9018ULL: goto x86_l_233a;
	case 9020ULL: goto x86_l_233c;
	case 9023ULL: goto x86_l_233f;
	case 9027ULL: goto x86_l_2343;
	case 9030ULL: goto x86_l_2346;
	case 9034ULL: goto x86_l_234a;
	case 9037ULL: goto x86_l_234d;
	case 9040ULL: goto x86_l_2350;
	case 9043ULL: goto x86_l_2353;
	case 9045ULL: goto x86_l_2355;
	case 9048ULL: goto x86_l_2358;
	case 9051ULL: goto x86_l_235b;
	case 9054ULL: goto x86_l_235e;
	case 9058ULL: goto x86_l_2362;
	case 9061ULL: goto x86_l_2365;
	case 9064ULL: goto x86_l_2368;
	case 9066ULL: goto x86_l_236a;
	case 9069ULL: goto x86_l_236d;
	case 9072ULL: goto x86_l_2370;
	case 9074ULL: goto x86_l_2372;
	case 9077ULL: goto x86_l_2375;
	case 9079ULL: goto x86_l_2377;
	case 9082ULL: goto x86_l_237a;
	case 9084ULL: goto x86_l_237c;
	case 9087ULL: goto x86_l_237f;
	case 9089ULL: goto x86_l_2381;
	case 9092ULL: goto x86_l_2384;
	case 9094ULL: goto x86_l_2386;
	case 9097ULL: goto x86_l_2389;
	case 9103ULL: goto x86_l_238f;
	case 9106ULL: goto x86_l_2392;
	case 9108ULL: goto x86_l_2394;
	case 9110ULL: goto x86_l_2396;
	case 9113ULL: goto x86_l_2399;
	case 9115ULL: goto x86_l_239b;
	case 9118ULL: goto x86_l_239e;
	case 9124ULL: goto x86_l_23a4;
	case 9126ULL: goto x86_l_23a6;
	case 9128ULL: goto x86_l_23a8;
	case 9131ULL: goto x86_l_23ab;
	case 9134ULL: goto x86_l_23ae;
	case 9137ULL: goto x86_l_23b1;
	case 9139ULL: goto x86_l_23b3;
	case 9142ULL: goto x86_l_23b6;
	case 9143ULL: goto x86_l_23b7;
	case 9145ULL: goto x86_l_23b9;
	case 9146ULL: goto x86_l_23ba;
	case 9150ULL: goto x86_l_23be;
	case 9153ULL: goto x86_l_23c1;
	case 9156ULL: goto x86_l_23c4;
	case 9160ULL: goto x86_l_23c8;
	case 9164ULL: goto x86_l_23cc;
	case 9171ULL: goto x86_l_23d3;
	case 9176ULL: goto x86_l_23d8;
	case 9181ULL: goto x86_l_23dd;
	case 9183ULL: goto x86_l_23df;
	case 9186ULL: goto x86_l_23e2;
	case 9188ULL: goto x86_l_23e4;
	case 9191ULL: goto x86_l_23e7;
	case 9195ULL: goto x86_l_23eb;
	case 9200ULL: goto x86_l_23f0;
	case 9205ULL: goto x86_l_23f5;
	case 9210ULL: goto x86_l_23fa;
	case 9212ULL: goto x86_l_23fc;
	case 9215ULL: goto x86_l_23ff;
	case 9217ULL: goto x86_l_2401;
	case 9220ULL: goto x86_l_2404;
	case 9222ULL: goto x86_l_2406;
	case 9227ULL: goto x86_l_240b;
	case 9230ULL: goto x86_l_240e;
	case 9232ULL: goto x86_l_2410;
	case 9235ULL: goto x86_l_2413;
	case 9238ULL: goto x86_l_2416;
	case 9240ULL: goto x86_l_2418;
	case 9242ULL: goto x86_l_241a;
	case 9246ULL: goto x86_l_241e;
	case 9247ULL: goto x86_l_241f;
	case 9249ULL: goto x86_l_2421;
	case 9250ULL: goto x86_l_2422;
	case 9255ULL: goto x86_l_2427;
	case 9258ULL: goto x86_l_242a;
	case 9260ULL: goto x86_l_242c;
	case 9263ULL: goto x86_l_242f;
	case 9266ULL: goto x86_l_2432;
	case 9269ULL: goto x86_l_2435;
	case 9273ULL: goto x86_l_2439;
	case 9274ULL: goto x86_l_243a;
	case 9276ULL: goto x86_l_243c;
	case 9277ULL: goto x86_l_243d;
	case 9278ULL: goto x86_l_243e;
	case 9282ULL: goto x86_l_2442;
	case 9289ULL: goto x86_l_2449;
	case 9291ULL: goto x86_l_244b;
	case 9297ULL: goto x86_l_2451;
	case 9303ULL: goto x86_l_2457;
	case 9306ULL: goto x86_l_245a;
	case 9310ULL: goto x86_l_245e;
	case 9314ULL: goto x86_l_2462;
	case 9319ULL: goto x86_l_2467;
	case 9324ULL: goto x86_l_246c;
	case 9329ULL: goto x86_l_2471;
	case 9331ULL: goto x86_l_2473;
	case 9335ULL: goto x86_l_2477;
	case 9339ULL: goto x86_l_247b;
	case 9344ULL: goto x86_l_2480;
	case 9346ULL: goto x86_l_2482;
	case 9349ULL: goto x86_l_2485;
	case 9351ULL: goto x86_l_2487;
	case 9353ULL: goto x86_l_2489;
	case 9358ULL: goto x86_l_248e;
	case 9364ULL: goto x86_l_2494;
	case 9369ULL: goto x86_l_2499;
	case 9371ULL: goto x86_l_249b;
	case 9373ULL: goto x86_l_249d;
	case 9376ULL: goto x86_l_24a0;
	case 9379ULL: goto x86_l_24a3;
	case 9381ULL: goto x86_l_24a5;
	case 9384ULL: goto x86_l_24a8;
	case 9386ULL: goto x86_l_24aa;
	case 9388ULL: goto x86_l_24ac;
	case 9390ULL: goto x86_l_24ae;
	case 9392ULL: goto x86_l_24b0;
	case 9395ULL: goto x86_l_24b3;
	case 9397ULL: goto x86_l_24b5;
	case 9400ULL: goto x86_l_24b8;
	case 9402ULL: goto x86_l_24ba;
	case 9404ULL: goto x86_l_24bc;
	case 9406ULL: goto x86_l_24be;
	case 9408ULL: goto x86_l_24c0;
	case 9411ULL: goto x86_l_24c3;
	case 9413ULL: goto x86_l_24c5;
	case 9416ULL: goto x86_l_24c8;
	case 9418ULL: goto x86_l_24ca;
	case 9420ULL: goto x86_l_24cc;
	case 9422ULL: goto x86_l_24ce;
	case 9424ULL: goto x86_l_24d0;
	case 9427ULL: goto x86_l_24d3;
	case 9431ULL: goto x86_l_24d7;
	case 9432ULL: goto x86_l_24d8;
	case 9433ULL: goto x86_l_24d9;
	case 9435ULL: goto x86_l_24db;
	case 9439ULL: goto x86_l_24df;
	case 9440ULL: goto x86_l_24e0;
	default: return 0xffffffffffffffffULL;
	}
x86_l_207e:
	/* 0x207e: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_2083:
	/* 0x2083: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_2086:
	/* 0x2086: jae    21c3 <filter_8ty_selector_val+0x1de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_21c3;
	}
x86_l_208c:
	/* 0x208c: movsx  ecx,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_208f:
	/* 0x208f: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2092:
	/* 0x2092: jg     2003 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 8195ULL;
	}
x86_l_2098:
	/* 0x2098: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_209b:
	/* 0x209b: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_209e:
	/* 0x209e: jb     21fc <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_21fc;
	}
x86_l_20a4:
	/* 0x20a4: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_20a7:
	/* 0x20a7: jg     2003 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 8195ULL;
	}
x86_l_20ad:
	/* 0x20ad: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_20b0:
	/* 0x20b0: jb     21fc <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_21fc;
	}
x86_l_20b6:
	/* 0x20b6: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_20b9:
	/* 0x20b9: jg     2003 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 8195ULL;
	}
x86_l_20bf:
	/* 0x20bf: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_20c2:
	/* 0x20c2: jb     21fc <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_21fc;
	}
x86_l_20c8:
	/* 0x20c8: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_20cb:
	/* 0x20cb: jg     2003 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 8195ULL;
	}
x86_l_20d1:
	/* 0x20d1: jmp    21fc <filter_8ty_selector_val+0x217> */
	goto x86_l_21fc;
x86_l_20d6:
	/* 0x20d6: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_20d9:
	/* 0x20d9: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_20dc:
	/* 0x20dc: ja     2188 <filter_8ty_selector_val+0x1a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2188;
	}
x86_l_20e2:
	/* 0x20e2: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_20e7:
	/* 0x20e7: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_20ea:
	/* 0x20ea: jae    2188 <filter_8ty_selector_val+0x1a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2188;
	}
x86_l_20f0:
	/* 0x20f0: movsx  ecx,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_20f3:
	/* 0x20f3: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20f6:
	/* 0x20f6: jl     2003 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 8195ULL;
	}
x86_l_20fc:
	/* 0x20fc: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20ff:
	/* 0x20ff: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_2102:
	/* 0x2102: jb     21fc <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_21fc;
	}
x86_l_2108:
	/* 0x2108: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_210b:
	/* 0x210b: jl     2003 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 8195ULL;
	}
x86_l_2111:
	/* 0x2111: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_2114:
	/* 0x2114: jb     21fc <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_21fc;
	}
x86_l_211a:
	/* 0x211a: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_211d:
	/* 0x211d: jl     2003 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 8195ULL;
	}
x86_l_2123:
	/* 0x2123: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_2126:
	/* 0x2126: jb     21fc <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_21fc;
	}
x86_l_212c:
	/* 0x212c: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_212f:
	/* 0x212f: jl     2003 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 8195ULL;
	}
x86_l_2135:
	/* 0x2135: jmp    21fc <filter_8ty_selector_val+0x217> */
	goto x86_l_21fc;
x86_l_213a:
	/* 0x213a: mov    esi,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_213d:
	/* 0x213d: cmp    esi,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 13ULL);
x86_l_2140:
	/* 0x2140: jb     2167 <filter_8ty_selector_val+0x182> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2167;
	}
x86_l_2142:
	/* 0x2142: cmp    DWORD PTR [rdi+0x14],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2145:
	/* 0x2145: je     201b <filter_8ty_selector_val+0x36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8219ULL;
	}
x86_l_214b:
	/* 0x214b: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_214e:
	/* 0x214e: jb     2167 <filter_8ty_selector_val+0x182> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2167;
	}
x86_l_2150:
	/* 0x2150: cmp    DWORD PTR [rdi+0x18],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2153:
	/* 0x2153: je     201b <filter_8ty_selector_val+0x36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8219ULL;
	}
x86_l_2159:
	/* 0x2159: cmp    esi,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 21ULL);
x86_l_215c:
	/* 0x215c: jb     2167 <filter_8ty_selector_val+0x182> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2167;
	}
x86_l_215e:
	/* 0x215e: cmp    DWORD PTR [rdi+0x1c],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2161:
	/* 0x2161: je     201b <filter_8ty_selector_val+0x36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8219ULL;
	}
x86_l_2167:
	/* 0x2167: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_216a:
	/* 0x216a: ja     21fc <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_21fc;
	}
x86_l_2170:
	/* 0x2170: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2172:
	/* 0x2172: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_217c:
	/* 0x217c: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_2180:
	/* 0x2180: jb     2003 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8195ULL;
	}
x86_l_2186:
	/* 0x2186: jmp    21fc <filter_8ty_selector_val+0x217> */
	goto x86_l_21fc;
x86_l_2188:
	/* 0x2188: movzx  ecx,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_218b:
	/* 0x218b: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_218e:
	/* 0x218e: jb     2003 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8195ULL;
	}
x86_l_2194:
	/* 0x2194: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2197:
	/* 0x2197: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_219a:
	/* 0x219a: jb     21fc <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_21fc;
	}
x86_l_219c:
	/* 0x219c: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_219f:
	/* 0x219f: jb     2003 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8195ULL;
	}
x86_l_21a5:
	/* 0x21a5: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_21a8:
	/* 0x21a8: jb     21fc <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_21fc;
	}
x86_l_21aa:
	/* 0x21aa: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_21ad:
	/* 0x21ad: jb     2003 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8195ULL;
	}
x86_l_21b3:
	/* 0x21b3: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_21b6:
	/* 0x21b6: jb     21fc <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_21fc;
	}
x86_l_21b8:
	/* 0x21b8: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_21bb:
	/* 0x21bb: jb     2003 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8195ULL;
	}
x86_l_21c1:
	/* 0x21c1: jmp    21fc <filter_8ty_selector_val+0x217> */
	goto x86_l_21fc;
x86_l_21c3:
	/* 0x21c3: movzx  ecx,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_21c6:
	/* 0x21c6: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21c9:
	/* 0x21c9: ja     2003 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8195ULL;
	}
x86_l_21cf:
	/* 0x21cf: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21d2:
	/* 0x21d2: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_21d5:
	/* 0x21d5: jb     21fc <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_21fc;
	}
x86_l_21d7:
	/* 0x21d7: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_21da:
	/* 0x21da: ja     2003 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8195ULL;
	}
x86_l_21e0:
	/* 0x21e0: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_21e3:
	/* 0x21e3: jb     21fc <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_21fc;
	}
x86_l_21e5:
	/* 0x21e5: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_21e8:
	/* 0x21e8: ja     2003 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8195ULL;
	}
x86_l_21ee:
	/* 0x21ee: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_21f1:
	/* 0x21f1: jb     21fc <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_21fc;
	}
x86_l_21f3:
	/* 0x21f3: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_21f6:
	/* 0x21f6: ja     2003 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8195ULL;
	}
x86_l_21fc:
	/* 0x21fc: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_21fe:
	/* 0x21fe: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_21ff:
	/* 0x21ff: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2202:
	/* 0x2202: mov    eax,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2205:
	/* 0x2205: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2208:
	/* 0x2208: ja     22ef <filter_8ty_range+0xf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_22ef;
	}
x86_l_220e:
	/* 0x220e: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_2213:
	/* 0x2213: bt     edx,eax */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_2216:
	/* 0x2216: jae    22ef <filter_8ty_range+0xf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_22ef;
	}
x86_l_221c:
	/* 0x221c: movsx  esi,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_221f:
	/* 0x221f: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_2222:
	/* 0x2222: jne    228a <filter_8ty_range+0x8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_228a;
	}
x86_l_2224:
	/* 0x2224: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2229:
	/* 0x2229: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_222c:
	/* 0x222c: jg     2237 <filter_8ty_range+0x38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2237;
	}
x86_l_222e:
	/* 0x222e: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2231:
	/* 0x2231: jge    2306 <filter_8ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_GE)) {
		goto x86_l_2306;
	}
x86_l_2237:
	/* 0x2237: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_223a:
	/* 0x223a: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_223d:
	/* 0x223d: jb     23a6 <filter_8ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_23a6;
	}
x86_l_2243:
	/* 0x2243: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2246:
	/* 0x2246: jg     2251 <filter_8ty_range+0x52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2251;
	}
x86_l_2248:
	/* 0x2248: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_224b:
	/* 0x224b: jge    2306 <filter_8ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_GE)) {
		goto x86_l_2306;
	}
x86_l_2251:
	/* 0x2251: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_2254:
	/* 0x2254: jb     23a6 <filter_8ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_23a6;
	}
x86_l_225a:
	/* 0x225a: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_225d:
	/* 0x225d: jg     2268 <filter_8ty_range+0x69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2268;
	}
x86_l_225f:
	/* 0x225f: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2262:
	/* 0x2262: jge    2306 <filter_8ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_GE)) {
		goto x86_l_2306;
	}
x86_l_2268:
	/* 0x2268: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_226b:
	/* 0x226b: jb     23a6 <filter_8ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_23a6;
	}
x86_l_2271:
	/* 0x2271: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2273:
	/* 0x2273: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2276:
	/* 0x2276: jg     23a8 <filter_8ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_23a8;
	}
x86_l_227c:
	/* 0x227c: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_227f:
	/* 0x227f: jge    2306 <filter_8ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_GE)) {
		goto x86_l_2306;
	}
x86_l_2285:
	/* 0x2285: jmp    23a8 <filter_8ty_range+0x1a9> */
	goto x86_l_23a8;
x86_l_228a:
	/* 0x228a: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_228d:
	/* 0x228d: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2290:
	/* 0x2290: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_2294:
	/* 0x2294: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2297:
	/* 0x2297: setge  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_GE);
x86_l_229a:
	/* 0x229a: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_229d:
	/* 0x229d: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_22a0:
	/* 0x22a0: jb     23a8 <filter_8ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_23a8;
	}
x86_l_22a6:
	/* 0x22a6: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_22a9:
	/* 0x22a9: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_22ad:
	/* 0x22ad: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_22b0:
	/* 0x22b0: setge  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_GE);
x86_l_22b4:
	/* 0x22b4: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_22b7:
	/* 0x22b7: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_22ba:
	/* 0x22ba: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_22bd:
	/* 0x22bd: jb     23a8 <filter_8ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_23a8;
	}
x86_l_22c3:
	/* 0x22c3: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_22c6:
	/* 0x22c6: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_22ca:
	/* 0x22ca: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_22cd:
	/* 0x22cd: setge  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_GE);
x86_l_22d1:
	/* 0x22d1: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_22d4:
	/* 0x22d4: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_22d7:
	/* 0x22d7: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_22da:
	/* 0x22da: jb     23a8 <filter_8ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_23a8;
	}
x86_l_22e0:
	/* 0x22e0: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_22e3:
	/* 0x22e3: setle  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_LE);
x86_l_22e6:
	/* 0x22e6: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_22e9:
	/* 0x22e9: setge  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_GE);
x86_l_22ed:
	/* 0x22ed: jmp    2362 <filter_8ty_range+0x163> */
	goto x86_l_2362;
x86_l_22ef:
	/* 0x22ef: movzx  esi,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_22f2:
	/* 0x22f2: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_22f5:
	/* 0x22f5: jne    2307 <filter_8ty_range+0x108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2307;
	}
x86_l_22f7:
	/* 0x22f7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_22fc:
	/* 0x22fc: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22ff:
	/* 0x22ff: ja     236a <filter_8ty_range+0x16b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_236a;
	}
x86_l_2301:
	/* 0x2301: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2304:
	/* 0x2304: jb     236a <filter_8ty_range+0x16b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_236a;
	}
x86_l_2306:
	/* 0x2306: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_2307:
	/* 0x2307: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_230a:
	/* 0x230a: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_230d:
	/* 0x230d: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_2311:
	/* 0x2311: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2314:
	/* 0x2314: setae  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_AE);
x86_l_2317:
	/* 0x2317: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_231a:
	/* 0x231a: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_231d:
	/* 0x231d: jb     23a8 <filter_8ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_23a8;
	}
x86_l_2323:
	/* 0x2323: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2326:
	/* 0x2326: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_232a:
	/* 0x232a: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_232d:
	/* 0x232d: setae  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_AE);
x86_l_2331:
	/* 0x2331: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_2334:
	/* 0x2334: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_2337:
	/* 0x2337: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_233a:
	/* 0x233a: jb     23a8 <filter_8ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_23a8;
	}
x86_l_233c:
	/* 0x233c: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_233f:
	/* 0x233f: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_2343:
	/* 0x2343: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2346:
	/* 0x2346: setae  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_AE);
x86_l_234a:
	/* 0x234a: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_234d:
	/* 0x234d: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_2350:
	/* 0x2350: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_2353:
	/* 0x2353: jb     23a8 <filter_8ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_23a8;
	}
x86_l_2355:
	/* 0x2355: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2358:
	/* 0x2358: setbe  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_BE);
x86_l_235b:
	/* 0x235b: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_235e:
	/* 0x235e: setae  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_AE);
x86_l_2362:
	/* 0x2362: and    sil,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_2365:
	/* 0x2365: or     dl,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_8, X86_ALU_OR);
x86_l_2368:
	/* 0x2368: jmp    23a8 <filter_8ty_range+0x1a9> */
	goto x86_l_23a8;
x86_l_236a:
	/* 0x236a: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_236d:
	/* 0x236d: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_2370:
	/* 0x2370: jb     23a6 <filter_8ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_23a6;
	}
x86_l_2372:
	/* 0x2372: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2375:
	/* 0x2375: ja     237c <filter_8ty_range+0x17d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_237c;
	}
x86_l_2377:
	/* 0x2377: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_237a:
	/* 0x237a: jae    2306 <filter_8ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2306;
	}
x86_l_237c:
	/* 0x237c: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_237f:
	/* 0x237f: jb     23a6 <filter_8ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_23a6;
	}
x86_l_2381:
	/* 0x2381: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2384:
	/* 0x2384: ja     238f <filter_8ty_range+0x190> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_238f;
	}
x86_l_2386:
	/* 0x2386: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2389:
	/* 0x2389: jae    2306 <filter_8ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2306;
	}
x86_l_238f:
	/* 0x238f: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_2392:
	/* 0x2392: jb     23a6 <filter_8ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_23a6;
	}
x86_l_2394:
	/* 0x2394: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2396:
	/* 0x2396: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2399:
	/* 0x2399: ja     23a8 <filter_8ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_23a8;
	}
x86_l_239b:
	/* 0x239b: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_239e:
	/* 0x239e: jae    2306 <filter_8ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2306;
	}
x86_l_23a4:
	/* 0x23a4: jmp    23a8 <filter_8ty_range+0x1a9> */
	goto x86_l_23a8;
x86_l_23a6:
	/* 0x23a6: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_23a8:
	/* 0x23a8: cmp    ecx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 32ULL);
x86_l_23ab:
	/* 0x23ab: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_23ae:
	/* 0x23ae: xor    dl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_23b1:
	/* 0x23b1: and    dl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_23b3:
	/* 0x23b3: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_23b6:
	/* 0x23b6: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_23b7:
	/* 0x23b7: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_23b9:
	/* 0x23b9: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_23ba:
	/* 0x23ba: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_23be:
	/* 0x23be: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_23c1:
	/* 0x23c1: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_23c4:
	/* 0x23c4: movzx  eax,BYTE PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_23c8:
	/* 0x23c8: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_23cc:
	/* 0x23cc: mov    rdi,QWORD PTR [rip+0x1440] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_23d3:
	/* 0x23d3: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_23d8:
	/* 0x23d8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_23dd:
	/* 0x23dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23df:
	/* 0x23df: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_23e2:
	/* 0x23e2: je     2418 <filter_8ty_map+0x61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2418;
	}
x86_l_23e4:
	/* 0x23e4: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_23e7:
	/* 0x23e7: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_23eb:
	/* 0x23eb: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23f0:
	/* 0x23f0: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23f5:
	/* 0x23f5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_23fa:
	/* 0x23fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23fc:
	/* 0x23fc: mov    edx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_23ff:
	/* 0x23ff: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2401:
	/* 0x2401: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_2404:
	/* 0x2404: ja     2432 <filter_8ty_map+0x7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2432;
	}
x86_l_2406:
	/* 0x2406: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_240b:
	/* 0x240b: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_240e:
	/* 0x240e: jae    2422 <filter_8ty_map+0x6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2422;
	}
x86_l_2410:
	/* 0x2410: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2413:
	/* 0x2413: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_2416:
	/* 0x2416: jmp    2432 <filter_8ty_map+0x7b> */
	goto x86_l_2432;
x86_l_2418:
	/* 0x2418: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_241a:
	/* 0x241a: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_241e:
	/* 0x241e: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_241f:
	/* 0x241f: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_2421:
	/* 0x2421: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_2422:
	/* 0x2422: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_2427:
	/* 0x2427: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_242a:
	/* 0x242a: jae    2432 <filter_8ty_map+0x7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2432;
	}
x86_l_242c:
	/* 0x242c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_242f:
	/* 0x242f: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_2432:
	/* 0x2432: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2435:
	/* 0x2435: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2439:
	/* 0x2439: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_243a:
	/* 0x243a: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_243c:
	/* 0x243c: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_243d:
	/* 0x243d: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_243e:
	/* 0x243e: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_2442:
	/* 0x2442: mov    WORD PTR [rsp+0xe],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 60129542144ULL);
x86_l_2449:
	/* 0x2449: mov    eax,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_244b:
	/* 0x244b: cmp    rax,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4096ULL);
x86_l_2451:
	/* 0x2451: ja     24d9 <filter_file_type+0x9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_24d9;
	}
x86_l_2457:
	/* 0x2457: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_245a:
	/* 0x245a: lea    rcx,[rsi+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_245e:
	/* 0x245e: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2462:
	/* 0x2462: lea    rdi,[rsp+0xe] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_2467:
	/* 0x2467: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_246c:
	/* 0x246c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2471:
	/* 0x2471: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2473:
	/* 0x2473: lea    rdx,[rsi+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2477:
	/* 0x2477: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_247b:
	/* 0x247b: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2480:
	/* 0x2480: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2482:
	/* 0x2482: mov    edx,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2485:
	/* 0x2485: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_2487:
	/* 0x2487: je     24d9 <filter_file_type+0x9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24d9;
	}
x86_l_2489:
	/* 0x2489: movzx  ecx,WORD PTR [rsp+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_248e:
	/* 0x248e: and    ecx,0xf000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 61440ULL);
x86_l_2494:
	/* 0x2494: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2499:
	/* 0x2499: cmp    edx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_249b:
	/* 0x249b: je     24db <filter_file_type+0x9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24db;
	}
x86_l_249d:
	/* 0x249d: mov    edx,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24a0:
	/* 0x24a0: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_24a3:
	/* 0x24a3: jbe    24d9 <filter_file_type+0x9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_24d9;
	}
x86_l_24a5:
	/* 0x24a5: mov    esi,DWORD PTR [rbx+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_24a8:
	/* 0x24a8: test   esi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_32);
x86_l_24aa:
	/* 0x24aa: je     24d9 <filter_file_type+0x9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24d9;
	}
x86_l_24ac:
	/* 0x24ac: cmp    esi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_24ae:
	/* 0x24ae: je     24db <filter_file_type+0x9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24db;
	}
x86_l_24b0:
	/* 0x24b0: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_24b3:
	/* 0x24b3: jb     24d9 <filter_file_type+0x9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_24d9;
	}
x86_l_24b5:
	/* 0x24b5: mov    esi,DWORD PTR [rbx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_24b8:
	/* 0x24b8: test   esi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_32);
x86_l_24ba:
	/* 0x24ba: je     24d9 <filter_file_type+0x9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24d9;
	}
x86_l_24bc:
	/* 0x24bc: cmp    esi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_24be:
	/* 0x24be: je     24db <filter_file_type+0x9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24db;
	}
x86_l_24c0:
	/* 0x24c0: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_24c3:
	/* 0x24c3: jb     24d9 <filter_file_type+0x9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_24d9;
	}
x86_l_24c5:
	/* 0x24c5: mov    edx,DWORD PTR [rbx+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_24c8:
	/* 0x24c8: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_24ca:
	/* 0x24ca: je     24d9 <filter_file_type+0x9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24d9;
	}
x86_l_24cc:
	/* 0x24cc: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_24ce:
	/* 0x24ce: cmp    edx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_24d0:
	/* 0x24d0: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_24d3:
	/* 0x24d3: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_24d7:
	/* 0x24d7: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_24d8:
	/* 0x24d8: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_24d9:
	/* 0x24d9: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_24db:
	/* 0x24db: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_24df:
	/* 0x24df: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_24e0:
	/* 0x24e0: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_uprobe_v61_generic_uprobe_filter_arg_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 10536U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1511ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v61_generic_uprobe_filter_arg_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1520ULL && __x86_pc <= 2820ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v61_generic_uprobe_filter_arg_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 2821ULL && __x86_pc <= 4233ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v61_generic_uprobe_filter_arg_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 4240ULL && __x86_pc <= 5650ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v61_generic_uprobe_filter_arg_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 5652ULL && __x86_pc <= 7005ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v61_generic_uprobe_filter_arg_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 7007ULL && __x86_pc <= 8312ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v61_generic_uprobe_filter_arg_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 8318ULL && __x86_pc <= 9440ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v61_generic_uprobe_filter_arg_x86_chunk_6(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

extern char addr4lpm_maps;
extern char addr6lpm_maps;
extern char argfilter_maps;
extern char filter_map;
extern char heap_ro_zero;
extern char process_call_heap;
extern char retkprobe_calls;
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

static __noinline __u64 tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_filter_arg_x86_chunk_0(
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
	case 120ULL: goto x86_l_78;
	case 122ULL: goto x86_l_7a;
	case 127ULL: goto x86_l_7f;
	case 131ULL: goto x86_l_83;
	case 135ULL: goto x86_l_87;
	case 138ULL: goto x86_l_8a;
	case 143ULL: goto x86_l_8f;
	case 150ULL: goto x86_l_96;
	case 155ULL: goto x86_l_9b;
	case 157ULL: goto x86_l_9d;
	case 161ULL: goto x86_l_a1;
	case 167ULL: goto x86_l_a7;
	case 170ULL: goto x86_l_aa;
	case 176ULL: goto x86_l_b0;
	case 180ULL: goto x86_l_b4;
	case 182ULL: goto x86_l_b6;
	case 186ULL: goto x86_l_ba;
	case 192ULL: goto x86_l_c0;
	case 195ULL: goto x86_l_c3;
	case 201ULL: goto x86_l_c9;
	case 205ULL: goto x86_l_cd;
	case 211ULL: goto x86_l_d3;
	case 213ULL: goto x86_l_d5;
	case 217ULL: goto x86_l_d9;
	case 223ULL: goto x86_l_df;
	case 227ULL: goto x86_l_e3;
	case 233ULL: goto x86_l_e9;
	case 237ULL: goto x86_l_ed;
	case 243ULL: goto x86_l_f3;
	case 247ULL: goto x86_l_f7;
	case 253ULL: goto x86_l_fd;
	case 256ULL: goto x86_l_100;
	case 261ULL: goto x86_l_105;
	case 265ULL: goto x86_l_109;
	case 270ULL: goto x86_l_10e;
	case 275ULL: goto x86_l_113;
	case 280ULL: goto x86_l_118;
	case 283ULL: goto x86_l_11b;
	case 289ULL: goto x86_l_121;
	case 295ULL: goto x86_l_127;
	case 299ULL: goto x86_l_12b;
	case 305ULL: goto x86_l_131;
	case 310ULL: goto x86_l_136;
	case 313ULL: goto x86_l_139;
	case 319ULL: goto x86_l_13f;
	case 322ULL: goto x86_l_142;
	case 324ULL: goto x86_l_144;
	case 328ULL: goto x86_l_148;
	case 334ULL: goto x86_l_14e;
	case 343ULL: goto x86_l_157;
	case 349ULL: goto x86_l_15d;
	case 357ULL: goto x86_l_165;
	case 362ULL: goto x86_l_16a;
	case 366ULL: goto x86_l_16e;
	case 373ULL: goto x86_l_175;
	case 376ULL: goto x86_l_178;
	case 379ULL: goto x86_l_17b;
	case 381ULL: goto x86_l_17d;
	case 384ULL: goto x86_l_180;
	case 386ULL: goto x86_l_182;
	case 389ULL: goto x86_l_185;
	case 392ULL: goto x86_l_188;
	case 398ULL: goto x86_l_18e;
	case 401ULL: goto x86_l_191;
	case 407ULL: goto x86_l_197;
	case 412ULL: goto x86_l_19c;
	case 415ULL: goto x86_l_19f;
	case 417ULL: goto x86_l_1a1;
	case 420ULL: goto x86_l_1a4;
	case 423ULL: goto x86_l_1a7;
	case 425ULL: goto x86_l_1a9;
	case 428ULL: goto x86_l_1ac;
	case 431ULL: goto x86_l_1af;
	case 437ULL: goto x86_l_1b5;
	case 440ULL: goto x86_l_1b8;
	case 446ULL: goto x86_l_1be;
	case 450ULL: goto x86_l_1c2;
	case 455ULL: goto x86_l_1c7;
	case 460ULL: goto x86_l_1cc;
	case 463ULL: goto x86_l_1cf;
	case 469ULL: goto x86_l_1d5;
	case 472ULL: goto x86_l_1d8;
	case 475ULL: goto x86_l_1db;
	case 481ULL: goto x86_l_1e1;
	case 484ULL: goto x86_l_1e4;
	case 487ULL: goto x86_l_1e7;
	case 493ULL: goto x86_l_1ed;
	case 498ULL: goto x86_l_1f2;
	case 501ULL: goto x86_l_1f5;
	case 507ULL: goto x86_l_1fb;
	case 510ULL: goto x86_l_1fe;
	case 512ULL: goto x86_l_200;
	case 515ULL: goto x86_l_203;
	case 521ULL: goto x86_l_209;
	case 524ULL: goto x86_l_20c;
	case 530ULL: goto x86_l_212;
	case 533ULL: goto x86_l_215;
	case 535ULL: goto x86_l_217;
	case 538ULL: goto x86_l_21a;
	case 544ULL: goto x86_l_220;
	case 546ULL: goto x86_l_222;
	case 556ULL: goto x86_l_22c;
	case 560ULL: goto x86_l_230;
	case 562ULL: goto x86_l_232;
	case 567ULL: goto x86_l_237;
	case 571ULL: goto x86_l_23b;
	case 577ULL: goto x86_l_241;
	case 587ULL: goto x86_l_24b;
	case 591ULL: goto x86_l_24f;
	case 597ULL: goto x86_l_255;
	case 602ULL: goto x86_l_25a;
	case 607ULL: goto x86_l_25f;
	case 610ULL: goto x86_l_262;
	case 613ULL: goto x86_l_265;
	case 619ULL: goto x86_l_26b;
	case 622ULL: goto x86_l_26e;
	case 628ULL: goto x86_l_274;
	case 631ULL: goto x86_l_277;
	case 637ULL: goto x86_l_27d;
	case 642ULL: goto x86_l_282;
	case 645ULL: goto x86_l_285;
	case 647ULL: goto x86_l_287;
	case 650ULL: goto x86_l_28a;
	case 652ULL: goto x86_l_28c;
	case 655ULL: goto x86_l_28f;
	case 661ULL: goto x86_l_295;
	case 666ULL: goto x86_l_29a;
	case 671ULL: goto x86_l_29f;
	case 676ULL: goto x86_l_2a4;
	case 678ULL: goto x86_l_2a6;
	case 681ULL: goto x86_l_2a9;
	case 683ULL: goto x86_l_2ab;
	case 686ULL: goto x86_l_2ae;
	case 689ULL: goto x86_l_2b1;
	case 691ULL: goto x86_l_2b3;
	case 700ULL: goto x86_l_2bc;
	case 706ULL: goto x86_l_2c2;
	case 709ULL: goto x86_l_2c5;
	case 717ULL: goto x86_l_2cd;
	case 723ULL: goto x86_l_2d3;
	case 725ULL: goto x86_l_2d5;
	case 735ULL: goto x86_l_2df;
	case 738ULL: goto x86_l_2e2;
	case 740ULL: goto x86_l_2e4;
	case 743ULL: goto x86_l_2e7;
	case 745ULL: goto x86_l_2e9;
	case 748ULL: goto x86_l_2ec;
	case 750ULL: goto x86_l_2ee;
	case 755ULL: goto x86_l_2f3;
	case 757ULL: goto x86_l_2f5;
	case 762ULL: goto x86_l_2fa;
	case 764ULL: goto x86_l_2fc;
	case 767ULL: goto x86_l_2ff;
	case 770ULL: goto x86_l_302;
	case 772ULL: goto x86_l_304;
	case 777ULL: goto x86_l_309;
	case 779ULL: goto x86_l_30b;
	case 784ULL: goto x86_l_310;
	case 786ULL: goto x86_l_312;
	case 791ULL: goto x86_l_317;
	case 796ULL: goto x86_l_31c;
	case 798ULL: goto x86_l_31e;
	case 801ULL: goto x86_l_321;
	case 803ULL: goto x86_l_323;
	case 808ULL: goto x86_l_328;
	case 811ULL: goto x86_l_32b;
	case 817ULL: goto x86_l_331;
	case 820ULL: goto x86_l_334;
	case 824ULL: goto x86_l_338;
	case 830ULL: goto x86_l_33e;
	case 835ULL: goto x86_l_343;
	case 842ULL: goto x86_l_34a;
	case 849ULL: goto x86_l_351;
	case 854ULL: goto x86_l_356;
	case 859ULL: goto x86_l_35b;
	case 862ULL: goto x86_l_35e;
	case 867ULL: goto x86_l_363;
	case 869ULL: goto x86_l_365;
	case 876ULL: goto x86_l_36c;
	case 881ULL: goto x86_l_371;
	case 886ULL: goto x86_l_376;
	case 889ULL: goto x86_l_379;
	case 894ULL: goto x86_l_37e;
	case 896ULL: goto x86_l_380;
	case 898ULL: goto x86_l_382;
	case 902ULL: goto x86_l_386;
	case 904ULL: goto x86_l_388;
	case 905ULL: goto x86_l_389;
	case 910ULL: goto x86_l_38e;
	case 913ULL: goto x86_l_391;
	case 921ULL: goto x86_l_399;
	case 923ULL: goto x86_l_39b;
	case 929ULL: goto x86_l_3a1;
	case 937ULL: goto x86_l_3a9;
	case 939ULL: goto x86_l_3ab;
	case 945ULL: goto x86_l_3b1;
	case 953ULL: goto x86_l_3b9;
	case 955ULL: goto x86_l_3bb;
	case 961ULL: goto x86_l_3c1;
	case 969ULL: goto x86_l_3c9;
	case 971ULL: goto x86_l_3cb;
	case 977ULL: goto x86_l_3d1;
	case 985ULL: goto x86_l_3d9;
	case 987ULL: goto x86_l_3db;
	case 993ULL: goto x86_l_3e1;
	case 1001ULL: goto x86_l_3e9;
	case 1003ULL: goto x86_l_3eb;
	case 1010ULL: goto x86_l_3f2;
	case 1017ULL: goto x86_l_3f9;
	case 1022ULL: goto x86_l_3fe;
	case 1027ULL: goto x86_l_403;
	case 1030ULL: goto x86_l_406;
	case 1035ULL: goto x86_l_40b;
	case 1037ULL: goto x86_l_40d;
	case 1041ULL: goto x86_l_411;
	case 1046ULL: goto x86_l_416;
	case 1048ULL: goto x86_l_418;
	case 1053ULL: goto x86_l_41d;
	case 1058ULL: goto x86_l_422;
	case 1065ULL: goto x86_l_429;
	case 1070ULL: goto x86_l_42e;
	case 1075ULL: goto x86_l_433;
	case 1077ULL: goto x86_l_435;
	case 1080ULL: goto x86_l_438;
	case 1086ULL: goto x86_l_43e;
	case 1093ULL: goto x86_l_445;
	case 1098ULL: goto x86_l_44a;
	case 1103ULL: goto x86_l_44f;
	case 1105ULL: goto x86_l_451;
	case 1110ULL: goto x86_l_456;
	case 1111ULL: goto x86_l_457;
	case 1114ULL: goto x86_l_45a;
	case 1116ULL: goto x86_l_45c;
	case 1119ULL: goto x86_l_45f;
	case 1121ULL: goto x86_l_461;
	case 1123ULL: goto x86_l_463;
	case 1125ULL: goto x86_l_465;
	case 1128ULL: goto x86_l_468;
	case 1131ULL: goto x86_l_46b;
	case 1133ULL: goto x86_l_46d;
	case 1135ULL: goto x86_l_46f;
	case 1136ULL: goto x86_l_470;
	case 1137ULL: goto x86_l_471;
	case 1140ULL: goto x86_l_474;
	case 1142ULL: goto x86_l_476;
	case 1144ULL: goto x86_l_478;
	case 1149ULL: goto x86_l_47d;
	case 1153ULL: goto x86_l_481;
	case 1155ULL: goto x86_l_483;
	case 1160ULL: goto x86_l_488;
	case 1164ULL: goto x86_l_48c;
	case 1166ULL: goto x86_l_48e;
	case 1176ULL: goto x86_l_498;
	case 1180ULL: goto x86_l_49c;
	case 1182ULL: goto x86_l_49e;
	case 1185ULL: goto x86_l_4a1;
	case 1190ULL: goto x86_l_4a6;
	case 1193ULL: goto x86_l_4a9;
	case 1196ULL: goto x86_l_4ac;
	case 1198ULL: goto x86_l_4ae;
	case 1200ULL: goto x86_l_4b0;
	case 1203ULL: goto x86_l_4b3;
	case 1206ULL: goto x86_l_4b6;
	case 1208ULL: goto x86_l_4b8;
	case 1212ULL: goto x86_l_4bc;
	case 1215ULL: goto x86_l_4bf;
	case 1220ULL: goto x86_l_4c4;
	case 1223ULL: goto x86_l_4c7;
	case 1226ULL: goto x86_l_4ca;
	case 1228ULL: goto x86_l_4cc;
	case 1230ULL: goto x86_l_4ce;
	case 1234ULL: goto x86_l_4d2;
	case 1237ULL: goto x86_l_4d5;
	case 1242ULL: goto x86_l_4da;
	case 1245ULL: goto x86_l_4dd;
	case 1248ULL: goto x86_l_4e0;
	case 1250ULL: goto x86_l_4e2;
	case 1252ULL: goto x86_l_4e4;
	case 1256ULL: goto x86_l_4e8;
	case 1259ULL: goto x86_l_4eb;
	case 1264ULL: goto x86_l_4f0;
	case 1267ULL: goto x86_l_4f3;
	case 1270ULL: goto x86_l_4f6;
	case 1272ULL: goto x86_l_4f8;
	case 1274ULL: goto x86_l_4fa;
	case 1276ULL: goto x86_l_4fc;
	case 1279ULL: goto x86_l_4ff;
	case 1281ULL: goto x86_l_501;
	case 1283ULL: goto x86_l_503;
	case 1293ULL: goto x86_l_50d;
	case 1297ULL: goto x86_l_511;
	case 1299ULL: goto x86_l_513;
	case 1303ULL: goto x86_l_517;
	case 1304ULL: goto x86_l_518;
	case 1305ULL: goto x86_l_519;
	case 1306ULL: goto x86_l_51a;
	case 1309ULL: goto x86_l_51d;
	case 1311ULL: goto x86_l_51f;
	case 1315ULL: goto x86_l_523;
	case 1317ULL: goto x86_l_525;
	case 1322ULL: goto x86_l_52a;
	case 1326ULL: goto x86_l_52e;
	case 1328ULL: goto x86_l_530;
	case 1333ULL: goto x86_l_535;
	case 1334ULL: goto x86_l_536;
	case 1335ULL: goto x86_l_537;
	case 1340ULL: goto x86_l_53c;
	case 1344ULL: goto x86_l_540;
	case 1346ULL: goto x86_l_542;
	case 1356ULL: goto x86_l_54c;
	case 1360ULL: goto x86_l_550;
	case 1362ULL: goto x86_l_552;
	case 1367ULL: goto x86_l_557;
	case 1368ULL: goto x86_l_558;
	case 1369ULL: goto x86_l_559;
	case 1374ULL: goto x86_l_55e;
	case 1375ULL: goto x86_l_55f;
	case 1376ULL: goto x86_l_560;
	case 1378ULL: goto x86_l_562;
	case 1380ULL: goto x86_l_564;
	case 1382ULL: goto x86_l_566;
	case 1383ULL: goto x86_l_567;
	case 1387ULL: goto x86_l_56b;
	case 1396ULL: goto x86_l_574;
	case 1405ULL: goto x86_l_57d;
	case 1414ULL: goto x86_l_586;
	case 1423ULL: goto x86_l_58f;
	case 1432ULL: goto x86_l_598;
	case 1439ULL: goto x86_l_59f;
	case 1447ULL: goto x86_l_5a7;
	case 1450ULL: goto x86_l_5aa;
	case 1452ULL: goto x86_l_5ac;
	case 1455ULL: goto x86_l_5af;
	case 1457ULL: goto x86_l_5b1;
	case 1460ULL: goto x86_l_5b4;
	case 1466ULL: goto x86_l_5ba;
	case 1469ULL: goto x86_l_5bd;
	case 1472ULL: goto x86_l_5c0;
	case 1474ULL: goto x86_l_5c2;
	case 1479ULL: goto x86_l_5c7;
	case 1482ULL: goto x86_l_5ca;
	case 1484ULL: goto x86_l_5cc;
	case 1487ULL: goto x86_l_5cf;
	case 1490ULL: goto x86_l_5d2;
	case 1496ULL: goto x86_l_5d8;
	case 1499ULL: goto x86_l_5db;
	case 1501ULL: goto x86_l_5dd;
	case 1504ULL: goto x86_l_5e0;
	case 1506ULL: goto x86_l_5e2;
	case 1509ULL: goto x86_l_5e5;
	case 1511ULL: goto x86_l_5e7;
	case 1514ULL: goto x86_l_5ea;
	case 1517ULL: goto x86_l_5ed;
	case 1523ULL: goto x86_l_5f3;
	case 1526ULL: goto x86_l_5f6;
	case 1529ULL: goto x86_l_5f9;
	case 1535ULL: goto x86_l_5ff;
	case 1540ULL: goto x86_l_604;
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
	/* 0xa: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_12:
	/* 0x12: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_19:
	/* 0x19: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
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
	/* 0x28: je     380 <generic_retkprobe_filter_arg+0x380> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_380;
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
	/* 0x3f: mov    rdi,QWORD PTR [rip+0x0] */
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
	/* 0x50: je     365 <generic_retkprobe_filter_arg+0x365> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_365;
	}
x86_l_56:
	/* 0x56: cmp    BYTE PTR [r14+0x5ee0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104316165685248ULL);
x86_l_5e:
	/* 0x5e: je     365 <generic_retkprobe_filter_arg+0x365> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_365;
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
	/* 0x76: je     b0 <generic_retkprobe_filter_arg+0xb0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b0;
	}
x86_l_78:
	/* 0x78: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_7a:
	/* 0x7a: mov    ecx,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_7f:
	/* 0x7f: lea    r13,[rcx+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_83:
	/* 0x83: add    r13,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_87:
	/* 0x87: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_8a:
	/* 0x8a: mov    QWORD PTR [rsp+0x10],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8f:
	/* 0x8f: and    r13d,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_96:
	/* 0x96: cmp    DWORD PTR [r15+r13*1],0x19 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 25ULL);
x86_l_9b:
	/* 0x9b: jae    105 <generic_retkprobe_filter_arg+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_105;
	}
x86_l_9d:
	/* 0x9d: cmp    r13,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 1ULL);
x86_l_a1:
	/* 0xa1: je     365 <generic_retkprobe_filter_arg+0x365> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_365;
	}
x86_l_a7:
	/* 0xa7: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_aa:
	/* 0xaa: jne    343 <generic_retkprobe_filter_arg+0x343> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_343;
	}
x86_l_b0:
	/* 0xb0: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_b4:
	/* 0xb4: jg     d5 <generic_retkprobe_filter_arg+0xd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_d5;
	}
x86_l_b6:
	/* 0xb6: cmp    r12d,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4294967295ULL);
x86_l_ba:
	/* 0xba: je     38e <generic_retkprobe_filter_arg+0x38e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38e;
	}
x86_l_c0:
	/* 0xc0: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_c3:
	/* 0xc3: je     39b <generic_retkprobe_filter_arg+0x39b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_39b;
	}
x86_l_c9:
	/* 0xc9: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_cd:
	/* 0xcd: je     3ab <generic_retkprobe_filter_arg+0x3ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ab;
	}
x86_l_d3:
	/* 0xd3: jmp    f3 <generic_retkprobe_filter_arg+0xf3> */
	goto x86_l_f3;
x86_l_d5:
	/* 0xd5: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_d9:
	/* 0xd9: je     3bb <generic_retkprobe_filter_arg+0x3bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3bb;
	}
x86_l_df:
	/* 0xdf: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_e3:
	/* 0xe3: je     3cb <generic_retkprobe_filter_arg+0x3cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3cb;
	}
x86_l_e9:
	/* 0xe9: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_ed:
	/* 0xed: je     3db <generic_retkprobe_filter_arg+0x3db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3db;
	}
x86_l_f3:
	/* 0xf3: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_f7:
	/* 0xf7: jg     40d <generic_retkprobe_filter_arg+0x40d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_40d;
	}
x86_l_fd:
	/* 0xfd: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_100:
	/* 0x100: jmp    3eb <generic_retkprobe_filter_arg+0x3eb> */
	goto x86_l_3eb;
x86_l_105:
	/* 0x105: lea    rax,[r15+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_109:
	/* 0x109: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10e:
	/* 0x10e: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_113:
	/* 0x113: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_118:
	/* 0x118: mov    edi,DWORD PTR [rax+rbp*4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 2), 0ULL);
x86_l_11b:
	/* 0x11b: test   edi,0x3ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDI, X86_WIDTH_32, 1023ULL);
x86_l_121:
	/* 0x121: je     9d <generic_retkprobe_filter_arg+0x9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9d;
	}
x86_l_127:
	/* 0x127: add    edi,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_12b:
	/* 0x12b: and    edi,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_131:
	/* 0x131: mov    ecx,DWORD PTR [r15+rdi*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 0), 4ULL);
x86_l_136:
	/* 0x136: cmp    ecx,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 35ULL);
x86_l_139:
	/* 0x139: je     b0 <generic_retkprobe_filter_arg+0xb0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b0;
	}
x86_l_13f:
	/* 0x13f: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_142:
	/* 0x142: mov    eax,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_144:
	/* 0x144: cmp    rax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4ULL);
x86_l_148:
	/* 0x148: ja     b0 <generic_retkprobe_filter_arg+0xb0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_b0;
	}
x86_l_14e:
	/* 0x14e: cmp    DWORD PTR [r14+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_157:
	/* 0x157: jne    b0 <generic_retkprobe_filter_arg+0xb0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b0;
	}
x86_l_15d:
	/* 0x15d: mov    rax,QWORD PTR [r14+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_165:
	/* 0x165: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_16a:
	/* 0x16a: lea    rsi,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_16e:
	/* 0x16e: add    rsi,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_175:
	/* 0x175: mov    eax,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_178:
	/* 0x178: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_17b:
	/* 0x17b: jle    19c <generic_retkprobe_filter_arg+0x19c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_19c;
	}
x86_l_17d:
	/* 0x17d: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_180:
	/* 0x180: jg     1cc <generic_retkprobe_filter_arg+0x1cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1cc;
	}
x86_l_182:
	/* 0x182: lea    edx,[rax-0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551588ULL);
x86_l_185:
	/* 0x185: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_188:
	/* 0x188: jb     212 <generic_retkprobe_filter_arg+0x212> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_212;
	}
x86_l_18e:
	/* 0x18e: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_191:
	/* 0x191: je     2f5 <generic_retkprobe_filter_arg+0x2f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f5;
	}
x86_l_197:
	/* 0x197: jmp    331 <generic_retkprobe_filter_arg+0x331> */
	goto x86_l_331;
x86_l_19c:
	/* 0x19c: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_19f:
	/* 0x19f: jle    1f2 <generic_retkprobe_filter_arg+0x1f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1f2;
	}
x86_l_1a1:
	/* 0x1a1: lea    edx,[rax-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_1a4:
	/* 0x1a4: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1a7:
	/* 0x1a7: jb     212 <generic_retkprobe_filter_arg+0x212> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_212;
	}
x86_l_1a9:
	/* 0x1a9: lea    ecx,[rax-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_1ac:
	/* 0x1ac: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1af:
	/* 0x1af: jb     2f5 <generic_retkprobe_filter_arg+0x2f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2f5;
	}
x86_l_1b5:
	/* 0x1b5: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1b8:
	/* 0x1b8: jne    331 <generic_retkprobe_filter_arg+0x331> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_331;
	}
x86_l_1be:
	/* 0x1be: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1c2:
	/* 0x1c2: call   0 <generic_retkprobe_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 455ULL);
	__x86_sim_call_depth++;
	goto x86_l_456;
x86_l_1c7:
	/* 0x1c7: jmp    328 <generic_retkprobe_filter_arg+0x328> */
	goto x86_l_328;
x86_l_1cc:
	/* 0x1cc: cmp    eax,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 41ULL);
x86_l_1cf:
	/* 0x1cf: jg     2e4 <generic_retkprobe_filter_arg+0x2e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2e4;
	}
x86_l_1d5:
	/* 0x1d5: lea    ecx,[rax-0x26] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551578ULL);
x86_l_1d8:
	/* 0x1d8: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1db:
	/* 0x1db: jb     29f <generic_retkprobe_filter_arg+0x29f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_29f;
	}
x86_l_1e1:
	/* 0x1e1: add    eax,0xffffffd8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4294967256ULL);
x86_l_1e4:
	/* 0x1e4: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1e7:
	/* 0x1e7: jb     295 <generic_retkprobe_filter_arg+0x295> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_295;
	}
x86_l_1ed:
	/* 0x1ed: jmp    331 <generic_retkprobe_filter_arg+0x331> */
	goto x86_l_331;
x86_l_1f2:
	/* 0x1f2: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f5:
	/* 0x1f5: jg     282 <generic_retkprobe_filter_arg+0x282> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_282;
	}
x86_l_1fb:
	/* 0x1fb: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1fe:
	/* 0x1fe: je     212 <generic_retkprobe_filter_arg+0x212> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_212;
	}
x86_l_200:
	/* 0x200: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_203:
	/* 0x203: je     312 <generic_retkprobe_filter_arg+0x312> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_312;
	}
x86_l_209:
	/* 0x209: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_20c:
	/* 0x20c: jne    331 <generic_retkprobe_filter_arg+0x331> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_331;
	}
x86_l_212:
	/* 0x212: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_215:
	/* 0x215: jle    25f <generic_retkprobe_filter_arg+0x25f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_25f;
	}
x86_l_217:
	/* 0x217: cmp    eax,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 36ULL);
x86_l_21a:
	/* 0x21a: ja     2fc <generic_retkprobe_filter_arg+0x2fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2fc;
	}
x86_l_220:
	/* 0x220: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_222:
	/* 0x222: movabs r8,0x1e00000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_64, 128849018880ULL);
x86_l_22c:
	/* 0x22c: bt     r8,rdx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RDX, X86_WIDTH_64);
x86_l_230:
	/* 0x230: jb     2a6 <generic_retkprobe_filter_arg+0x2a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2a6;
	}
x86_l_232:
	/* 0x232: mov    ecx,0x60000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1610612736ULL);
x86_l_237:
	/* 0x237: bt     rcx,rdx */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_23b:
	/* 0x23b: jb     30b <generic_retkprobe_filter_arg+0x30b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_30b;
	}
x86_l_241:
	/* 0x241: movabs rcx,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 6442450944ULL);
x86_l_24b:
	/* 0x24b: bt     rcx,rdx */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_24f:
	/* 0x24f: jae    2fc <generic_retkprobe_filter_arg+0x2fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2fc;
	}
x86_l_255:
	/* 0x255: call   0 <generic_retkprobe_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 602ULL);
	__x86_sim_call_depth++;
	goto x86_l_519;
x86_l_25a:
	/* 0x25a: jmp    328 <generic_retkprobe_filter_arg+0x328> */
	goto x86_l_328;
x86_l_25f:
	/* 0x25f: lea    ecx,[rax-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_262:
	/* 0x262: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_265:
	/* 0x265: jb     323 <generic_retkprobe_filter_arg+0x323> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_323;
	}
x86_l_26b:
	/* 0x26b: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_26e:
	/* 0x26e: je     304 <generic_retkprobe_filter_arg+0x304> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_304;
	}
x86_l_274:
	/* 0x274: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_277:
	/* 0x277: je     304 <generic_retkprobe_filter_arg+0x304> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_304;
	}
x86_l_27d:
	/* 0x27d: jmp    331 <generic_retkprobe_filter_arg+0x331> */
	goto x86_l_331;
x86_l_282:
	/* 0x282: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_285:
	/* 0x285: je     295 <generic_retkprobe_filter_arg+0x295> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_295;
	}
x86_l_287:
	/* 0x287: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_28a:
	/* 0x28a: je     29f <generic_retkprobe_filter_arg+0x29f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29f;
	}
x86_l_28c:
	/* 0x28c: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_28f:
	/* 0x28f: jne    331 <generic_retkprobe_filter_arg+0x331> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_331;
	}
x86_l_295:
	/* 0x295: call   0 <generic_retkprobe_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 666ULL);
	__x86_sim_call_depth++;
	goto x86_l_560;
x86_l_29a:
	/* 0x29a: jmp    328 <generic_retkprobe_filter_arg+0x328> */
	goto x86_l_328;
x86_l_29f:
	/* 0x29f: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_2a4:
	/* 0x2a4: jmp    317 <generic_retkprobe_filter_arg+0x317> */
	goto x86_l_317;
x86_l_2a6:
	/* 0x2a6: cmp    ecx,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 30ULL);
x86_l_2a9:
	/* 0x2a9: jne    323 <generic_retkprobe_filter_arg+0x323> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_323;
	}
x86_l_2ab:
	/* 0x2ab: mov    eax,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ae:
	/* 0x2ae: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_2b1:
	/* 0x2b1: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_2b3:
	/* 0x2b3: cmp    DWORD PTR [r14+rcx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 104041287778304ULL);
x86_l_2bc:
	/* 0x2bc: jne    b0 <generic_retkprobe_filter_arg+0xb0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b0;
	}
x86_l_2c2:
	/* 0x2c2: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c5:
	/* 0x2c5: mov    rdx,QWORD PTR [r14+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_2cd:
	/* 0x2cd: and    edx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_2d3:
	/* 0x2d3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d5:
	/* 0x2d5: andn   rcx,rcx,QWORD PTR [r14+rdx*1+0x90] */
	X86_SIM_L_EXEC_ANDN_MEM(X86_RCX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RDX, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_R14)), 144ULL);
x86_l_2df:
	/* 0x2df: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_2e2:
	/* 0x2e2: jmp    328 <generic_retkprobe_filter_arg+0x328> */
	goto x86_l_328;
x86_l_2e4:
	/* 0x2e4: cmp    eax,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 42ULL);
x86_l_2e7:
	/* 0x2e7: je     2f5 <generic_retkprobe_filter_arg+0x2f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f5;
	}
x86_l_2e9:
	/* 0x2e9: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2ec:
	/* 0x2ec: jne    331 <generic_retkprobe_filter_arg+0x331> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_331;
	}
x86_l_2ee:
	/* 0x2ee: call   0 <generic_retkprobe_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 755ULL);
	__x86_sim_call_depth++;
	return 2209ULL;
x86_l_2f3:
	/* 0x2f3: jmp    328 <generic_retkprobe_filter_arg+0x328> */
	goto x86_l_328;
x86_l_2f5:
	/* 0x2f5: call   0 <generic_retkprobe_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 762ULL);
	__x86_sim_call_depth++;
	goto x86_l_456;
x86_l_2fa:
	/* 0x2fa: jmp    328 <generic_retkprobe_filter_arg+0x328> */
	goto x86_l_328;
x86_l_2fc:
	/* 0x2fc: lea    ecx,[rax-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_2ff:
	/* 0x2ff: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_302:
	/* 0x302: jae    31e <generic_retkprobe_filter_arg+0x31e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_31e;
	}
x86_l_304:
	/* 0x304: call   0 <generic_retkprobe_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 777ULL);
	__x86_sim_call_depth++;
	return 2380ULL;
x86_l_309:
	/* 0x309: jmp    328 <generic_retkprobe_filter_arg+0x328> */
	goto x86_l_328;
x86_l_30b:
	/* 0x30b: call   0 <generic_retkprobe_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 784ULL);
	__x86_sim_call_depth++;
	return 2451ULL;
x86_l_310:
	/* 0x310: jmp    328 <generic_retkprobe_filter_arg+0x328> */
	goto x86_l_328;
x86_l_312:
	/* 0x312: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_317:
	/* 0x317: call   0 <generic_retkprobe_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 796ULL);
	__x86_sim_call_depth++;
	return 2522ULL;
x86_l_31c:
	/* 0x31c: jmp    328 <generic_retkprobe_filter_arg+0x328> */
	goto x86_l_328;
x86_l_31e:
	/* 0x31e: cmp    eax,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_321:
	/* 0x321: jne    331 <generic_retkprobe_filter_arg+0x331> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_331;
	}
x86_l_323:
	/* 0x323: call   0 <generic_retkprobe_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 808ULL);
	__x86_sim_call_depth++;
	return 2685ULL;
x86_l_328:
	/* 0x328: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_32b:
	/* 0x32b: je     b0 <generic_retkprobe_filter_arg+0xb0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b0;
	}
x86_l_331:
	/* 0x331: inc    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_334:
	/* 0x334: cmp    rbp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 6ULL);
x86_l_338:
	/* 0x338: jne    113 <generic_retkprobe_filter_arg+0x113> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_113;
	}
x86_l_33e:
	/* 0x33e: jmp    9d <generic_retkprobe_filter_arg+0x9d> */
	goto x86_l_9d;
x86_l_343:
	/* 0x343: mov    DWORD PTR [r14+0x5f04],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24324ULL);
x86_l_34a:
	/* 0x34a: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&retkprobe_calls)));
x86_l_351:
	/* 0x351: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_356:
	/* 0x356: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_35b:
	/* 0x35b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_35e:
	/* 0x35e: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_363:
	/* 0x363: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_365:
	/* 0x365: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&retkprobe_calls)));
x86_l_36c:
	/* 0x36c: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_371:
	/* 0x371: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_376:
	/* 0x376: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_379:
	/* 0x379: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_37e:
	/* 0x37e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_380:
	/* 0x380: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_382:
	/* 0x382: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_386:
	/* 0x386: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_388:
	/* 0x388: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_389:
	/* 0x389: jmp    2477 <filter_file_type+0xa4> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_38e:
	/* 0x38e: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_391:
	/* 0x391: cmp    BYTE PTR [r14+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104183021699072ULL);
x86_l_399:
	/* 0x399: jne    3eb <generic_retkprobe_filter_arg+0x3eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3eb;
	}
x86_l_39b:
	/* 0x39b: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_3a1:
	/* 0x3a1: cmp    BYTE PTR [r14+0x5ec2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104187316666368ULL);
x86_l_3a9:
	/* 0x3a9: jne    3eb <generic_retkprobe_filter_arg+0x3eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3eb;
	}
x86_l_3ab:
	/* 0x3ab: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_3b1:
	/* 0x3b1: cmp    BYTE PTR [r14+0x5ec3],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104191611633664ULL);
x86_l_3b9:
	/* 0x3b9: jne    3eb <generic_retkprobe_filter_arg+0x3eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3eb;
	}
x86_l_3bb:
	/* 0x3bb: mov    r12d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 3ULL);
x86_l_3c1:
	/* 0x3c1: cmp    BYTE PTR [r14+0x5ec4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104195906600960ULL);
x86_l_3c9:
	/* 0x3c9: jne    3eb <generic_retkprobe_filter_arg+0x3eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3eb;
	}
x86_l_3cb:
	/* 0x3cb: mov    r12d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4ULL);
x86_l_3d1:
	/* 0x3d1: cmp    BYTE PTR [r14+0x5ec5],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104200201568256ULL);
x86_l_3d9:
	/* 0x3d9: jne    3eb <generic_retkprobe_filter_arg+0x3eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3eb;
	}
x86_l_3db:
	/* 0x3db: mov    r12d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 5ULL);
x86_l_3e1:
	/* 0x3e1: cmp    BYTE PTR [r14+0x5ec6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104204496535552ULL);
x86_l_3e9:
	/* 0x3e9: je     40d <generic_retkprobe_filter_arg+0x40d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40d;
	}
x86_l_3eb:
	/* 0x3eb: mov    DWORD PTR [r14+0x5f00],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24320ULL);
x86_l_3f2:
	/* 0x3f2: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&retkprobe_calls)));
x86_l_3f9:
	/* 0x3f9: mov    ecx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_3fe:
	/* 0x3fe: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_403:
	/* 0x403: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_406:
	/* 0x406: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_40b:
	/* 0x40b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40d:
	/* 0x40d: mov    rbx,QWORD PTR [r14+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_411:
	/* 0x411: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_416:
	/* 0x416: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_418:
	/* 0x418: mov    QWORD PTR [rsp+0x18],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_41d:
	/* 0x41d: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_422:
	/* 0x422: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_429:
	/* 0x429: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_42e:
	/* 0x42e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_433:
	/* 0x433: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_435:
	/* 0x435: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_438:
	/* 0x438: je     380 <generic_retkprobe_filter_arg+0x380> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_380;
	}
x86_l_43e:
	/* 0x43e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_445:
	/* 0x445: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_44a:
	/* 0x44a: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_44f:
	/* 0x44f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_451:
	/* 0x451: jmp    380 <generic_retkprobe_filter_arg+0x380> */
	goto x86_l_380;
x86_l_456:
	/* 0x456: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_457:
	/* 0x457: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_45a:
	/* 0x45a: mov    edx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_45c:
	/* 0x45c: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_45f:
	/* 0x45f: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_461:
	/* 0x461: jne    471 <filter_file_buf+0x1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_471;
	}
x86_l_463:
	/* 0x463: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_465:
	/* 0x465: and    eax,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_468:
	/* 0x468: cmp    eax,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 36ULL);
x86_l_46b:
	/* 0x46b: je     471 <filter_file_buf+0x1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_471;
	}
x86_l_46d:
	/* 0x46d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_46f:
	/* 0x46f: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_470:
	/* 0x470: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_471:
	/* 0x471: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_474:
	/* 0x474: ja     4b0 <filter_file_buf+0x5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_4b0;
	}
x86_l_476:
	/* 0x476: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_478:
	/* 0x478: mov    edi,0x4000100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 67109120ULL);
x86_l_47d:
	/* 0x47d: bt     rdi,rax */
	X86_SIM_L_EXEC_BT(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_481:
	/* 0x481: jb     4e4 <filter_file_buf+0x8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_4e4;
	}
x86_l_483:
	/* 0x483: mov    edi,0x8000200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 134218240ULL);
x86_l_488:
	/* 0x488: bt     rdi,rax */
	X86_SIM_L_EXEC_BT(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_48c:
	/* 0x48c: jb     4ce <filter_file_buf+0x78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_4ce;
	}
x86_l_48e:
	/* 0x48e: movabs rdi,0x3000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_64, 206158430208ULL);
x86_l_498:
	/* 0x498: bt     rdi,rax */
	X86_SIM_L_EXEC_BT(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_49c:
	/* 0x49c: jae    4b0 <filter_file_buf+0x5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_4b0;
	}
x86_l_49e:
	/* 0x49e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4a1:
	/* 0x4a1: call   23d3 <filter_file_type> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 1190ULL);
	__x86_sim_call_depth++;
	return 9171ULL;
x86_l_4a6:
	/* 0x4a6: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4a9:
	/* 0x4a9: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_4ac:
	/* 0x4ac: jbe    501 <filter_file_buf+0xab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_501;
	}
x86_l_4ae:
	/* 0x4ae: jmp    517 <filter_file_buf+0xc1> */
	goto x86_l_517;
x86_l_4b0:
	/* 0x4b0: lea    eax,[rcx-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_4b3:
	/* 0x4b3: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4b6:
	/* 0x4b6: jae    4fa <filter_file_buf+0xa4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_4fa;
	}
x86_l_4b8:
	/* 0x4b8: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_4bc:
	/* 0x4bc: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4bf:
	/* 0x4bf: call   1131 <filter_char_buf_equal> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 1220ULL);
	__x86_sim_call_depth++;
	return 4401ULL;
x86_l_4c4:
	/* 0x4c4: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4c7:
	/* 0x4c7: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_4ca:
	/* 0x4ca: jbe    501 <filter_file_buf+0xab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_501;
	}
x86_l_4cc:
	/* 0x4cc: jmp    517 <filter_file_buf+0xc1> */
	goto x86_l_517;
x86_l_4ce:
	/* 0x4ce: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_4d2:
	/* 0x4d2: mov    edi,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4d5:
	/* 0x4d5: call   f49 <filter_char_buf_postfix> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 1242ULL);
	__x86_sim_call_depth++;
	return 3913ULL;
x86_l_4da:
	/* 0x4da: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4dd:
	/* 0x4dd: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_4e0:
	/* 0x4e0: jbe    501 <filter_file_buf+0xab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_501;
	}
x86_l_4e2:
	/* 0x4e2: jmp    517 <filter_file_buf+0xc1> */
	goto x86_l_517;
x86_l_4e4:
	/* 0x4e4: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_4e8:
	/* 0x4e8: mov    edi,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4eb:
	/* 0x4eb: call   1091 <filter_char_buf_prefix> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 1264ULL);
	__x86_sim_call_depth++;
	return 4241ULL;
x86_l_4f0:
	/* 0x4f0: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4f3:
	/* 0x4f3: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_4f6:
	/* 0x4f6: jbe    501 <filter_file_buf+0xab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_501;
	}
x86_l_4f8:
	/* 0x4f8: jmp    517 <filter_file_buf+0xc1> */
	goto x86_l_517;
x86_l_4fa:
	/* 0x4fa: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4fc:
	/* 0x4fc: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_4ff:
	/* 0x4ff: ja     517 <filter_file_buf+0xc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_517;
	}
x86_l_501:
	/* 0x501: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_503:
	/* 0x503: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_50d:
	/* 0x50d: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_511:
	/* 0x511: jae    517 <filter_file_buf+0xc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_517;
	}
x86_l_513:
	/* 0x513: xor    rax,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 1ULL);
x86_l_517:
	/* 0x517: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_518:
	/* 0x518: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_519:
	/* 0x519: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_51a:
	/* 0x51a: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_51d:
	/* 0x51d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_51f:
	/* 0x51f: cmp    rcx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 32ULL);
x86_l_523:
	/* 0x523: ja     55e <filter_8ty+0x45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_55e;
	}
x86_l_525:
	/* 0x525: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_52a:
	/* 0x52a: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_52e:
	/* 0x52e: jae    537 <filter_8ty+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_537;
	}
x86_l_530:
	/* 0x530: call   1f7b <filter_8ty_selector_val> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 1333ULL);
	__x86_sim_call_depth++;
	return 8059ULL;
x86_l_535:
	/* 0x535: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_536:
	/* 0x536: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_537:
	/* 0x537: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_53c:
	/* 0x53c: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_540:
	/* 0x540: jb     559 <filter_8ty+0x40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_559;
	}
x86_l_542:
	/* 0x542: movabs rdx,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 6442450944ULL);
x86_l_54c:
	/* 0x54c: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_550:
	/* 0x550: jae    55e <filter_8ty+0x45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_55e;
	}
x86_l_552:
	/* 0x552: call   2195 <filter_8ty_range> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 1367ULL);
	__x86_sim_call_depth++;
	return 8597ULL;
x86_l_557:
	/* 0x557: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_558:
	/* 0x558: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_559:
	/* 0x559: call   234d <filter_8ty_map> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 1374ULL);
	__x86_sim_call_depth++;
	return 9037ULL;
x86_l_55e:
	/* 0x55e: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_55f:
	/* 0x55f: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_560:
	/* 0x560: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_562:
	/* 0x562: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_564:
	/* 0x564: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_566:
	/* 0x566: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_567:
	/* 0x567: sub    rsp,0x48 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 72ULL);
x86_l_56b:
	/* 0x56b: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_574:
	/* 0x574: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_57d:
	/* 0x57d: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_586:
	/* 0x586: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_58f:
	/* 0x58f: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_598:
	/* 0x598: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_59f:
	/* 0x59f: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_5a7:
	/* 0x5a7: mov    edx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_5aa:
	/* 0x5aa: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5ac:
	/* 0x5ac: cmp    edx,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 39ULL);
x86_l_5af:
	/* 0x5af: jg     5c7 <filter_inet+0x67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_5c7;
	}
x86_l_5b1:
	/* 0x5b1: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_5b4:
	/* 0x5b4: je     64c <filter_inet+0xec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1612ULL;
	}
x86_l_5ba:
	/* 0x5ba: mov    r8,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_64);
x86_l_5bd:
	/* 0x5bd: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_5c0:
	/* 0x5c0: je     5d8 <filter_inet+0x78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5d8;
	}
x86_l_5c2:
	/* 0x5c2: jmp    85d <filter_inet+0x2fd> */
	return 2141ULL;
x86_l_5c7:
	/* 0x5c7: cmp    edx,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 40ULL);
x86_l_5ca:
	/* 0x5ca: je     624 <filter_inet+0xc4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1572ULL;
	}
x86_l_5cc:
	/* 0x5cc: mov    r8,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_64);
x86_l_5cf:
	/* 0x5cf: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_5d2:
	/* 0x5d2: jne    85d <filter_inet+0x2fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2141ULL;
	}
x86_l_5d8:
	/* 0x5d8: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5db:
	/* 0x5db: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5dd:
	/* 0x5dd: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_5e0:
	/* 0x5e0: jle    659 <filter_inet+0xf9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 1625ULL;
	}
x86_l_5e2:
	/* 0x5e2: cmp    ecx,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 23ULL);
x86_l_5e5:
	/* 0x5e5: jg     604 <filter_inet+0xa4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_604;
	}
x86_l_5e7:
	/* 0x5e7: lea    edx,[rcx-0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551596ULL);
x86_l_5ea:
	/* 0x5ea: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_5ed:
	/* 0x5ed: jb     6aa <filter_inet+0x14a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 1706ULL;
	}
x86_l_5f3:
	/* 0x5f3: lea    edx,[rcx-0x16] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_5f6:
	/* 0x5f6: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_5f9:
	/* 0x5f9: jb     6a4 <filter_inet+0x144> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 1700ULL;
	}
x86_l_5ff:
	/* 0x5ff: jmp    85d <filter_inet+0x2fd> */
	return 2141ULL;
x86_l_604:
	/* 0x604: cmp    ecx,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 27ULL);
	return 1543ULL;
}

static __noinline __u64 tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_filter_arg_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1543ULL: goto x86_l_607;
	case 1549ULL: goto x86_l_60d;
	case 1552ULL: goto x86_l_610;
	case 1558ULL: goto x86_l_616;
	case 1561ULL: goto x86_l_619;
	case 1567ULL: goto x86_l_61f;
	case 1572ULL: goto x86_l_624;
	case 1575ULL: goto x86_l_627;
	case 1580ULL: goto x86_l_62c;
	case 1584ULL: goto x86_l_630;
	case 1589ULL: goto x86_l_635;
	case 1593ULL: goto x86_l_639;
	case 1598ULL: goto x86_l_63e;
	case 1602ULL: goto x86_l_642;
	case 1607ULL: goto x86_l_647;
	case 1612ULL: goto x86_l_64c;
	case 1615ULL: goto x86_l_64f;
	case 1618ULL: goto x86_l_652;
	case 1620ULL: goto x86_l_654;
	case 1623ULL: goto x86_l_657;
	case 1625ULL: goto x86_l_659;
	case 1628ULL: goto x86_l_65c;
	case 1630ULL: goto x86_l_65e;
	case 1633ULL: goto x86_l_661;
	case 1635ULL: goto x86_l_663;
	case 1638ULL: goto x86_l_666;
	case 1640ULL: goto x86_l_668;
	case 1643ULL: goto x86_l_66b;
	case 1649ULL: goto x86_l_671;
	case 1653ULL: goto x86_l_675;
	case 1658ULL: goto x86_l_67a;
	case 1661ULL: goto x86_l_67d;
	case 1667ULL: goto x86_l_683;
	case 1670ULL: goto x86_l_686;
	case 1676ULL: goto x86_l_68c;
	case 1679ULL: goto x86_l_68f;
	case 1681ULL: goto x86_l_691;
	case 1686ULL: goto x86_l_696;
	case 1689ULL: goto x86_l_699;
	case 1691ULL: goto x86_l_69b;
	case 1694ULL: goto x86_l_69e;
	case 1700ULL: goto x86_l_6a4;
	case 1704ULL: goto x86_l_6a8;
	case 1706ULL: goto x86_l_6aa;
	case 1710ULL: goto x86_l_6ae;
	case 1714ULL: goto x86_l_6b2;
	case 1716ULL: goto x86_l_6b4;
	case 1719ULL: goto x86_l_6b7;
	case 1722ULL: goto x86_l_6ba;
	case 1724ULL: goto x86_l_6bc;
	case 1727ULL: goto x86_l_6bf;
	case 1729ULL: goto x86_l_6c1;
	case 1732ULL: goto x86_l_6c4;
	case 1735ULL: goto x86_l_6c7;
	case 1741ULL: goto x86_l_6cd;
	case 1744ULL: goto x86_l_6d0;
	case 1747ULL: goto x86_l_6d3;
	case 1753ULL: goto x86_l_6d9;
	case 1756ULL: goto x86_l_6dc;
	case 1762ULL: goto x86_l_6e2;
	case 1767ULL: goto x86_l_6e7;
	case 1770ULL: goto x86_l_6ea;
	case 1776ULL: goto x86_l_6f0;
	case 1779ULL: goto x86_l_6f3;
	case 1785ULL: goto x86_l_6f9;
	case 1788ULL: goto x86_l_6fc;
	case 1794ULL: goto x86_l_702;
	case 1797ULL: goto x86_l_705;
	case 1803ULL: goto x86_l_70b;
	case 1808ULL: goto x86_l_710;
	case 1812ULL: goto x86_l_714;
	case 1816ULL: goto x86_l_718;
	case 1818ULL: goto x86_l_71a;
	case 1821ULL: goto x86_l_71d;
	case 1825ULL: goto x86_l_721;
	case 1828ULL: goto x86_l_724;
	case 1832ULL: goto x86_l_728;
	case 1834ULL: goto x86_l_72a;
	case 1836ULL: goto x86_l_72c;
	case 1839ULL: goto x86_l_72f;
	case 1841ULL: goto x86_l_731;
	case 1844ULL: goto x86_l_734;
	case 1846ULL: goto x86_l_736;
	case 1852ULL: goto x86_l_73c;
	case 1856ULL: goto x86_l_740;
	case 1858ULL: goto x86_l_742;
	case 1864ULL: goto x86_l_748;
	case 1868ULL: goto x86_l_74c;
	case 1870ULL: goto x86_l_74e;
	case 1875ULL: goto x86_l_753;
	case 1878ULL: goto x86_l_756;
	case 1880ULL: goto x86_l_758;
	case 1884ULL: goto x86_l_75c;
	case 1887ULL: goto x86_l_75f;
	case 1889ULL: goto x86_l_761;
	case 1892ULL: goto x86_l_764;
	case 1898ULL: goto x86_l_76a;
	case 1901ULL: goto x86_l_76d;
	case 1904ULL: goto x86_l_770;
	case 1908ULL: goto x86_l_774;
	case 1915ULL: goto x86_l_77b;
	case 1920ULL: goto x86_l_780;
	case 1925ULL: goto x86_l_785;
	case 1927ULL: goto x86_l_787;
	case 1930ULL: goto x86_l_78a;
	case 1936ULL: goto x86_l_790;
	case 1939ULL: goto x86_l_793;
	case 1947ULL: goto x86_l_79b;
	case 1951ULL: goto x86_l_79f;
	case 1953ULL: goto x86_l_7a1;
	case 1956ULL: goto x86_l_7a4;
	case 1959ULL: goto x86_l_7a7;
	case 1965ULL: goto x86_l_7ad;
	case 1970ULL: goto x86_l_7b2;
	case 1975ULL: goto x86_l_7b7;
	case 1977ULL: goto x86_l_7b9;
	case 1983ULL: goto x86_l_7bf;
	case 1986ULL: goto x86_l_7c2;
	case 1991ULL: goto x86_l_7c7;
	case 1993ULL: goto x86_l_7c9;
	case 1999ULL: goto x86_l_7cf;
	case 2002ULL: goto x86_l_7d2;
	case 2007ULL: goto x86_l_7d7;
	case 2010ULL: goto x86_l_7da;
	case 2013ULL: goto x86_l_7dd;
	case 2017ULL: goto x86_l_7e1;
	case 2024ULL: goto x86_l_7e8;
	case 2029ULL: goto x86_l_7ed;
	case 2034ULL: goto x86_l_7f2;
	case 2036ULL: goto x86_l_7f4;
	case 2039ULL: goto x86_l_7f7;
	case 2041ULL: goto x86_l_7f9;
	case 2044ULL: goto x86_l_7fc;
	case 2052ULL: goto x86_l_804;
	case 2056ULL: goto x86_l_808;
	case 2061ULL: goto x86_l_80d;
	case 2066ULL: goto x86_l_812;
	case 2070ULL: goto x86_l_816;
	case 2075ULL: goto x86_l_81b;
	case 2080ULL: goto x86_l_820;
	case 2085ULL: goto x86_l_825;
	case 2087ULL: goto x86_l_827;
	case 2092ULL: goto x86_l_82c;
	case 2095ULL: goto x86_l_82f;
	case 2098ULL: goto x86_l_832;
	case 2100ULL: goto x86_l_834;
	case 2103ULL: goto x86_l_837;
	case 2106ULL: goto x86_l_83a;
	case 2108ULL: goto x86_l_83c;
	case 2111ULL: goto x86_l_83f;
	case 2114ULL: goto x86_l_842;
	case 2117ULL: goto x86_l_845;
	case 2119ULL: goto x86_l_847;
	case 2121ULL: goto x86_l_849;
	case 2124ULL: goto x86_l_84c;
	case 2126ULL: goto x86_l_84e;
	case 2130ULL: goto x86_l_852;
	case 2133ULL: goto x86_l_855;
	case 2136ULL: goto x86_l_858;
	case 2141ULL: goto x86_l_85d;
	case 2145ULL: goto x86_l_861;
	case 2146ULL: goto x86_l_862;
	case 2148ULL: goto x86_l_864;
	case 2150ULL: goto x86_l_866;
	case 2152ULL: goto x86_l_868;
	case 2153ULL: goto x86_l_869;
	case 2158ULL: goto x86_l_86e;
	case 2161ULL: goto x86_l_871;
	case 2164ULL: goto x86_l_874;
	case 2166ULL: goto x86_l_876;
	case 2169ULL: goto x86_l_879;
	case 2172ULL: goto x86_l_87c;
	case 2175ULL: goto x86_l_87f;
	case 2177ULL: goto x86_l_881;
	case 2180ULL: goto x86_l_884;
	case 2182ULL: goto x86_l_886;
	case 2185ULL: goto x86_l_889;
	case 2187ULL: goto x86_l_88b;
	case 2192ULL: goto x86_l_890;
	case 2195ULL: goto x86_l_893;
	case 2198ULL: goto x86_l_896;
	case 2200ULL: goto x86_l_898;
	case 2203ULL: goto x86_l_89b;
	case 2205ULL: goto x86_l_89d;
	case 2207ULL: goto x86_l_89f;
	case 2209ULL: goto x86_l_8a1;
	case 2210ULL: goto x86_l_8a2;
	case 2214ULL: goto x86_l_8a6;
	case 2217ULL: goto x86_l_8a9;
	case 2221ULL: goto x86_l_8ad;
	case 2225ULL: goto x86_l_8b1;
	case 2229ULL: goto x86_l_8b5;
	case 2231ULL: goto x86_l_8b7;
	case 2235ULL: goto x86_l_8bb;
	case 2237ULL: goto x86_l_8bd;
	case 2241ULL: goto x86_l_8c1;
	case 2244ULL: goto x86_l_8c4;
	case 2246ULL: goto x86_l_8c6;
	case 2249ULL: goto x86_l_8c9;
	case 2254ULL: goto x86_l_8ce;
	case 2257ULL: goto x86_l_8d1;
	case 2261ULL: goto x86_l_8d5;
	case 2263ULL: goto x86_l_8d7;
	case 2273ULL: goto x86_l_8e1;
	case 2277ULL: goto x86_l_8e5;
	case 2279ULL: goto x86_l_8e7;
	case 2283ULL: goto x86_l_8eb;
	case 2287ULL: goto x86_l_8ef;
	case 2288ULL: goto x86_l_8f0;
	case 2289ULL: goto x86_l_8f1;
	case 2293ULL: goto x86_l_8f5;
	case 2295ULL: goto x86_l_8f7;
	case 2299ULL: goto x86_l_8fb;
	case 2301ULL: goto x86_l_8fd;
	case 2303ULL: goto x86_l_8ff;
	case 2307ULL: goto x86_l_903;
	case 2309ULL: goto x86_l_905;
	case 2312ULL: goto x86_l_908;
	case 2315ULL: goto x86_l_90b;
	case 2317ULL: goto x86_l_90d;
	case 2322ULL: goto x86_l_912;
	case 2325ULL: goto x86_l_915;
	case 2329ULL: goto x86_l_919;
	case 2331ULL: goto x86_l_91b;
	case 2341ULL: goto x86_l_925;
	case 2345ULL: goto x86_l_929;
	case 2347ULL: goto x86_l_92b;
	case 2351ULL: goto x86_l_92f;
	case 2355ULL: goto x86_l_933;
	case 2356ULL: goto x86_l_934;
	case 2357ULL: goto x86_l_935;
	case 2360ULL: goto x86_l_938;
	case 2364ULL: goto x86_l_93c;
	case 2369ULL: goto x86_l_941;
	case 2374ULL: goto x86_l_946;
	case 2378ULL: goto x86_l_94a;
	case 2379ULL: goto x86_l_94b;
	case 2380ULL: goto x86_l_94c;
	case 2381ULL: goto x86_l_94d;
	case 2384ULL: goto x86_l_950;
	case 2386ULL: goto x86_l_952;
	case 2390ULL: goto x86_l_956;
	case 2392ULL: goto x86_l_958;
	case 2397ULL: goto x86_l_95d;
	case 2401ULL: goto x86_l_961;
	case 2403ULL: goto x86_l_963;
	case 2408ULL: goto x86_l_968;
	case 2409ULL: goto x86_l_969;
	case 2410ULL: goto x86_l_96a;
	case 2415ULL: goto x86_l_96f;
	case 2419ULL: goto x86_l_973;
	case 2421ULL: goto x86_l_975;
	case 2431ULL: goto x86_l_97f;
	case 2435ULL: goto x86_l_983;
	case 2437ULL: goto x86_l_985;
	case 2442ULL: goto x86_l_98a;
	case 2443ULL: goto x86_l_98b;
	case 2444ULL: goto x86_l_98c;
	case 2449ULL: goto x86_l_991;
	case 2450ULL: goto x86_l_992;
	case 2451ULL: goto x86_l_993;
	case 2452ULL: goto x86_l_994;
	case 2455ULL: goto x86_l_997;
	case 2457ULL: goto x86_l_999;
	case 2461ULL: goto x86_l_99d;
	case 2463ULL: goto x86_l_99f;
	case 2468ULL: goto x86_l_9a4;
	case 2472ULL: goto x86_l_9a8;
	case 2474ULL: goto x86_l_9aa;
	case 2479ULL: goto x86_l_9af;
	case 2480ULL: goto x86_l_9b0;
	case 2481ULL: goto x86_l_9b1;
	case 2486ULL: goto x86_l_9b6;
	case 2490ULL: goto x86_l_9ba;
	case 2492ULL: goto x86_l_9bc;
	case 2502ULL: goto x86_l_9c6;
	case 2506ULL: goto x86_l_9ca;
	case 2508ULL: goto x86_l_9cc;
	case 2513ULL: goto x86_l_9d1;
	case 2514ULL: goto x86_l_9d2;
	case 2515ULL: goto x86_l_9d3;
	case 2520ULL: goto x86_l_9d8;
	case 2521ULL: goto x86_l_9d9;
	case 2522ULL: goto x86_l_9da;
	case 2523ULL: goto x86_l_9db;
	case 2526ULL: goto x86_l_9de;
	case 2529ULL: goto x86_l_9e1;
	case 2532ULL: goto x86_l_9e4;
	case 2536ULL: goto x86_l_9e8;
	case 2538ULL: goto x86_l_9ea;
	case 2541ULL: goto x86_l_9ed;
	case 2544ULL: goto x86_l_9f0;
	case 2546ULL: goto x86_l_9f2;
	case 2549ULL: goto x86_l_9f5;
	case 2551ULL: goto x86_l_9f7;
	case 2554ULL: goto x86_l_9fa;
	case 2557ULL: goto x86_l_9fd;
	case 2559ULL: goto x86_l_9ff;
	case 2562ULL: goto x86_l_a02;
	case 2564ULL: goto x86_l_a04;
	case 2567ULL: goto x86_l_a07;
	case 2569ULL: goto x86_l_a09;
	case 2571ULL: goto x86_l_a0b;
	case 2574ULL: goto x86_l_a0e;
	case 2576ULL: goto x86_l_a10;
	case 2579ULL: goto x86_l_a13;
	case 2581ULL: goto x86_l_a15;
	case 2584ULL: goto x86_l_a18;
	case 2586ULL: goto x86_l_a1a;
	case 2589ULL: goto x86_l_a1d;
	case 2594ULL: goto x86_l_a22;
	case 2596ULL: goto x86_l_a24;
	case 2599ULL: goto x86_l_a27;
	case 2601ULL: goto x86_l_a29;
	case 2604ULL: goto x86_l_a2c;
	case 2606ULL: goto x86_l_a2e;
	case 2609ULL: goto x86_l_a31;
	case 2614ULL: goto x86_l_a36;
	case 2616ULL: goto x86_l_a38;
	case 2619ULL: goto x86_l_a3b;
	case 2624ULL: goto x86_l_a40;
	case 2626ULL: goto x86_l_a42;
	case 2629ULL: goto x86_l_a45;
	case 2634ULL: goto x86_l_a4a;
	case 2636ULL: goto x86_l_a4c;
	case 2639ULL: goto x86_l_a4f;
	case 2641ULL: goto x86_l_a51;
	case 2646ULL: goto x86_l_a56;
	case 2649ULL: goto x86_l_a59;
	case 2652ULL: goto x86_l_a5c;
	case 2654ULL: goto x86_l_a5e;
	case 2656ULL: goto x86_l_a60;
	case 2666ULL: goto x86_l_a6a;
	case 2670ULL: goto x86_l_a6e;
	case 2672ULL: goto x86_l_a70;
	case 2674ULL: goto x86_l_a72;
	case 2677ULL: goto x86_l_a75;
	case 2680ULL: goto x86_l_a78;
	case 2683ULL: goto x86_l_a7b;
	case 2684ULL: goto x86_l_a7c;
	case 2685ULL: goto x86_l_a7d;
	case 2686ULL: goto x86_l_a7e;
	case 2689ULL: goto x86_l_a81;
	case 2691ULL: goto x86_l_a83;
	case 2695ULL: goto x86_l_a87;
	case 2697ULL: goto x86_l_a89;
	case 2702ULL: goto x86_l_a8e;
	case 2706ULL: goto x86_l_a92;
	case 2708ULL: goto x86_l_a94;
	case 2713ULL: goto x86_l_a99;
	case 2714ULL: goto x86_l_a9a;
	case 2715ULL: goto x86_l_a9b;
	case 2720ULL: goto x86_l_aa0;
	case 2724ULL: goto x86_l_aa4;
	case 2726ULL: goto x86_l_aa6;
	case 2736ULL: goto x86_l_ab0;
	case 2740ULL: goto x86_l_ab4;
	case 2742ULL: goto x86_l_ab6;
	case 2747ULL: goto x86_l_abb;
	case 2748ULL: goto x86_l_abc;
	case 2749ULL: goto x86_l_abd;
	case 2754ULL: goto x86_l_ac2;
	case 2755ULL: goto x86_l_ac3;
	case 2756ULL: goto x86_l_ac4;
	case 2759ULL: goto x86_l_ac7;
	case 2764ULL: goto x86_l_acc;
	case 2768ULL: goto x86_l_ad0;
	case 2770ULL: goto x86_l_ad2;
	case 2780ULL: goto x86_l_adc;
	case 2784ULL: goto x86_l_ae0;
	case 2786ULL: goto x86_l_ae2;
	case 2787ULL: goto x86_l_ae3;
	case 2792ULL: goto x86_l_ae8;
	case 2796ULL: goto x86_l_aec;
	case 2798ULL: goto x86_l_aee;
	case 2801ULL: goto x86_l_af1;
	case 2805ULL: goto x86_l_af5;
	case 2811ULL: goto x86_l_afb;
	case 2813ULL: goto x86_l_afd;
	case 2816ULL: goto x86_l_b00;
	case 2819ULL: goto x86_l_b03;
	case 2820ULL: goto x86_l_b04;
	case 2824ULL: goto x86_l_b08;
	case 2826ULL: goto x86_l_b0a;
	default: return 0xffffffffffffffffULL;
	}
x86_l_607:
	/* 0x607: jg     6e7 <filter_inet+0x187> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_6e7;
	}
x86_l_60d:
	/* 0x60d: cmp    ecx,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 24ULL);
x86_l_610:
	/* 0x610: je     71a <filter_inet+0x1ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_71a;
	}
x86_l_616:
	/* 0x616: cmp    ecx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 25ULL);
x86_l_619:
	/* 0x619: je     710 <filter_inet+0x1b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_710;
	}
x86_l_61f:
	/* 0x61f: jmp    85d <filter_inet+0x2fd> */
	goto x86_l_85d;
x86_l_624:
	/* 0x624: movzx  eax,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_627:
	/* 0x627: mov    WORD PTR [rsp+0x46],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 70ULL);
x86_l_62c:
	/* 0x62c: movzx  eax,WORD PTR [rsi+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_630:
	/* 0x630: mov    WORD PTR [rsp+0x40],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_635:
	/* 0x635: mov    rax,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_639:
	/* 0x639: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_63e:
	/* 0x63e: mov    rax,QWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_642:
	/* 0x642: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_647:
	/* 0x647: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_64c:
	/* 0x64c: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_64f:
	/* 0x64f: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_652:
	/* 0x652: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_654:
	/* 0x654: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_657:
	/* 0x657: jg     5e2 <filter_inet+0x82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 1506ULL;
	}
x86_l_659:
	/* 0x659: cmp    ecx,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 15ULL);
x86_l_65c:
	/* 0x65c: jle    67a <filter_inet+0x11a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_67a;
	}
x86_l_65e:
	/* 0x65e: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_661:
	/* 0x661: jg     696 <filter_inet+0x136> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_696;
	}
x86_l_663:
	/* 0x663: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_666:
	/* 0x666: je     6a4 <filter_inet+0x144> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6a4;
	}
x86_l_668:
	/* 0x668: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_66b:
	/* 0x66b: jne    85d <filter_inet+0x2fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_85d;
	}
x86_l_671:
	/* 0x671: movzx  eax,WORD PTR [rsi+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_675:
	/* 0x675: jmp    852 <filter_inet+0x2f2> */
	goto x86_l_852;
x86_l_67a:
	/* 0x67a: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_67d:
	/* 0x67d: je     71a <filter_inet+0x1ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_71a;
	}
x86_l_683:
	/* 0x683: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_686:
	/* 0x686: je     710 <filter_inet+0x1b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_710;
	}
x86_l_68c:
	/* 0x68c: cmp    ecx,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 15ULL);
x86_l_68f:
	/* 0x68f: je     6aa <filter_inet+0x14a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6aa;
	}
x86_l_691:
	/* 0x691: jmp    85d <filter_inet+0x2fd> */
	goto x86_l_85d;
x86_l_696:
	/* 0x696: cmp    ecx,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 18ULL);
x86_l_699:
	/* 0x699: je     6aa <filter_inet+0x14a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6aa;
	}
x86_l_69b:
	/* 0x69b: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_69e:
	/* 0x69e: jne    85d <filter_inet+0x2fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_85d;
	}
x86_l_6a4:
	/* 0x6a4: movzx  edx,WORD PTR [rsi+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_6a8:
	/* 0x6a8: jmp    6ae <filter_inet+0x14e> */
	goto x86_l_6ae;
x86_l_6aa:
	/* 0x6aa: movzx  edx,WORD PTR [rsi+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_6ae:
	/* 0x6ae: mov    DWORD PTR [rsp+0x4],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_6b2:
	/* 0x6b2: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6b4:
	/* 0x6b4: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6b7:
	/* 0x6b7: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6ba:
	/* 0x6ba: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6bc:
	/* 0x6bc: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_6bf:
	/* 0x6bf: jg     731 <filter_inet+0x1d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_731;
	}
x86_l_6c1:
	/* 0x6c1: lea    edx,[rcx-0xd] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551603ULL);
x86_l_6c4:
	/* 0x6c4: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_6c7:
	/* 0x6c7: jb     758 <filter_inet+0x1f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_758;
	}
x86_l_6cd:
	/* 0x6cd: lea    edx,[rcx-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_6d0:
	/* 0x6d0: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_6d3:
	/* 0x6d3: jb     7ad <filter_inet+0x24d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_7ad;
	}
x86_l_6d9:
	/* 0x6d9: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_6dc:
	/* 0x6dc: je     855 <filter_inet+0x2f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_855;
	}
x86_l_6e2:
	/* 0x6e2: jmp    85d <filter_inet+0x2fd> */
	goto x86_l_85d;
x86_l_6e7:
	/* 0x6e7: cmp    ecx,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 28ULL);
x86_l_6ea:
	/* 0x6ea: je     84e <filter_inet+0x2ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_84e;
	}
x86_l_6f0:
	/* 0x6f0: cmp    ecx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 29ULL);
x86_l_6f3:
	/* 0x6f3: jne    85d <filter_inet+0x2fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_85d;
	}
x86_l_6f9:
	/* 0x6f9: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_6fc:
	/* 0x6fc: jne    881 <filter_inet+0x321> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_881;
	}
x86_l_702:
	/* 0x702: test   r8,r8 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_64);
x86_l_705:
	/* 0x705: jne    88b <filter_inet+0x32b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_88b;
	}
x86_l_70b:
	/* 0x70b: jmp    855 <filter_inet+0x2f5> */
	goto x86_l_855;
x86_l_710:
	/* 0x710: mov    rbx,QWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_714:
	/* 0x714: mov    r14,QWORD PTR [rsi+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_718:
	/* 0x718: jmp    721 <filter_inet+0x1c1> */
	goto x86_l_721;
x86_l_71a:
	/* 0x71a: mov    rbx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_71d:
	/* 0x71d: mov    r14,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_721:
	/* 0x721: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_724:
	/* 0x724: shr    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_728:
	/* 0x728: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_72a:
	/* 0x72a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_72c:
	/* 0x72c: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_72f:
	/* 0x72f: jle    6c1 <filter_inet+0x161> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_6c1;
	}
x86_l_731:
	/* 0x731: cmp    ecx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 25ULL);
x86_l_734:
	/* 0x734: ja     7a1 <filter_inet+0x241> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_7a1;
	}
x86_l_736:
	/* 0x736: mov    r8d,0x500000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5242880ULL);
x86_l_73c:
	/* 0x73c: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_740:
	/* 0x740: jb     7b7 <filter_inet+0x257> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_7b7;
	}
x86_l_742:
	/* 0x742: mov    r8d,0xa00000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 10485760ULL);
x86_l_748:
	/* 0x748: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_74c:
	/* 0x74c: jb     7c7 <filter_inet+0x267> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_7c7;
	}
x86_l_74e:
	/* 0x74e: mov    edx,0x3000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 50331648ULL);
x86_l_753:
	/* 0x753: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_756:
	/* 0x756: jae    7a1 <filter_inet+0x241> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_7a1;
	}
x86_l_758:
	/* 0x758: movzx  eax,WORD PTR [rsi+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_75c:
	/* 0x75c: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_75f:
	/* 0x75f: je     7d7 <filter_inet+0x277> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7d7;
	}
x86_l_761:
	/* 0x761: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_764:
	/* 0x764: jne    847 <filter_inet+0x2e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_847;
	}
x86_l_76a:
	/* 0x76a: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_76d:
	/* 0x76d: mov    eax,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_770:
	/* 0x770: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_774:
	/* 0x774: mov    rdi,QWORD PTR [rip+0x1660] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr4lpm_maps)));
x86_l_77b:
	/* 0x77b: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_780:
	/* 0x780: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_785:
	/* 0x785: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_787:
	/* 0x787: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_78a:
	/* 0x78a: je     869 <filter_inet+0x309> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_869;
	}
x86_l_790:
	/* 0x790: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_793:
	/* 0x793: mov    DWORD PTR [rsp+0xc],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607584ULL);
x86_l_79b:
	/* 0x79b: mov    DWORD PTR [rsp+0x10],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_79f:
	/* 0x79f: jmp    81b <filter_inet+0x2bb> */
	goto x86_l_81b;
x86_l_7a1:
	/* 0x7a1: add    ecx,0xffffffee */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 4294967278ULL);
x86_l_7a4:
	/* 0x7a4: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_7a7:
	/* 0x7a7: jae    85d <filter_inet+0x2fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_85d;
	}
x86_l_7ad:
	/* 0x7ad: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_7b2:
	/* 0x7b2: jmp    858 <filter_inet+0x2f8> */
	goto x86_l_858;
x86_l_7b7:
	/* 0x7b7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7b9:
	/* 0x7b9: cmp    edx,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1024ULL);
x86_l_7bf:
	/* 0x7bf: setb   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_B);
x86_l_7c2:
	/* 0x7c2: jmp    85d <filter_inet+0x2fd> */
	goto x86_l_85d;
x86_l_7c7:
	/* 0x7c7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7c9:
	/* 0x7c9: cmp    edx,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1024ULL);
x86_l_7cf:
	/* 0x7cf: setae  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_AE);
x86_l_7d2:
	/* 0x7d2: jmp    85d <filter_inet+0x2fd> */
	goto x86_l_85d;
x86_l_7d7:
	/* 0x7d7: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_7da:
	/* 0x7da: mov    eax,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_7dd:
	/* 0x7dd: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7e1:
	/* 0x7e1: mov    rdi,QWORD PTR [rip+0x1660] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr6lpm_maps)));
x86_l_7e8:
	/* 0x7e8: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7ed:
	/* 0x7ed: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7f2:
	/* 0x7f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7f4:
	/* 0x7f4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7f7:
	/* 0x7f7: je     869 <filter_inet+0x309> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_869;
	}
x86_l_7f9:
	/* 0x7f9: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_7fc:
	/* 0x7fc: mov    DWORD PTR [rsp+0xc],0x80 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607680ULL);
x86_l_804:
	/* 0x804: mov    DWORD PTR [rsp+0x10],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_808:
	/* 0x808: mov    DWORD PTR [rsp+0x14],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_80d:
	/* 0x80d: mov    DWORD PTR [rsp+0x18],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_812:
	/* 0x812: shr    r14,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_816:
	/* 0x816: mov    DWORD PTR [rsp+0x1c],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_81b:
	/* 0x81b: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_820:
	/* 0x820: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_825:
	/* 0x825: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_827:
	/* 0x827: mov    ecx,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_82c:
	/* 0x82c: lea    edx,[rcx-0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551592ULL);
x86_l_82f:
	/* 0x82f: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_832:
	/* 0x832: jb     876 <filter_inet+0x316> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_876;
	}
x86_l_834:
	/* 0x834: add    ecx,0xfffffff3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 4294967283ULL);
x86_l_837:
	/* 0x837: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_83a:
	/* 0x83a: ja     847 <filter_inet+0x2e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_847;
	}
x86_l_83c:
	/* 0x83c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_83f:
	/* 0x83f: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_842:
	/* 0x842: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_845:
	/* 0x845: jmp    85d <filter_inet+0x2fd> */
	goto x86_l_85d;
x86_l_847:
	/* 0x847: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_849:
	/* 0x849: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_84c:
	/* 0x84c: jmp    85d <filter_inet+0x2fd> */
	goto x86_l_85d;
x86_l_84e:
	/* 0x84e: movzx  eax,WORD PTR [rsi+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_852:
	/* 0x852: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_855:
	/* 0x855: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_858:
	/* 0x858: call   1ef6 <filter_32ty_map> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2141ULL);
	__x86_sim_call_depth++;
	return 7926ULL;
x86_l_85d:
	/* 0x85d: add    rsp,0x48 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 72ULL);
x86_l_861:
	/* 0x861: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_862:
	/* 0x862: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_864:
	/* 0x864: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_866:
	/* 0x866: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_868:
	/* 0x868: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_869:
	/* 0x869: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_86e:
	/* 0x86e: and    eax,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_871:
	/* 0x871: cmp    eax,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_874:
	/* 0x874: jmp    879 <filter_inet+0x319> */
	goto x86_l_879;
x86_l_876:
	/* 0x876: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_879:
	/* 0x879: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_87c:
	/* 0x87c: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_87f:
	/* 0x87f: jmp    85d <filter_inet+0x2fd> */
	goto x86_l_85d;
x86_l_881:
	/* 0x881: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_884:
	/* 0x884: jne    893 <filter_inet+0x333> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_893;
	}
x86_l_886:
	/* 0x886: test   r8,r8 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_64);
x86_l_889:
	/* 0x889: je     893 <filter_inet+0x333> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_893;
	}
x86_l_88b:
	/* 0x88b: movzx  eax,BYTE PTR [r8+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 58ULL);
x86_l_890:
	/* 0x890: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_893:
	/* 0x893: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_896:
	/* 0x896: je     855 <filter_inet+0x2f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_855;
	}
x86_l_898:
	/* 0x898: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_89b:
	/* 0x89b: je     855 <filter_inet+0x2f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_855;
	}
x86_l_89d:
	/* 0x89d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_89f:
	/* 0x89f: jmp    85d <filter_inet+0x2fd> */
	goto x86_l_85d;
x86_l_8a1:
	/* 0x8a1: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_8a2:
	/* 0x8a2: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_8a6:
	/* 0x8a6: mov    rcx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_64);
x86_l_8a9:
	/* 0x8a9: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_8ad:
	/* 0x8ad: movzx  edx,BYTE PTR [rcx+0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 3ULL);
x86_l_8b1:
	/* 0x8b1: mov    r8d,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_8b5:
	/* 0x8b5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8b7:
	/* 0x8b7: cmp    r8d,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 25ULL);
x86_l_8bb:
	/* 0x8bb: jg     8f1 <filter_sockaddr_un+0x50> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_8f1;
	}
x86_l_8bd:
	/* 0x8bd: lea    ecx,[r8-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_8c1:
	/* 0x8c1: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_8c4:
	/* 0x8c4: jae    8ff <filter_sockaddr_un+0x5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_8ff;
	}
x86_l_8c6:
	/* 0x8c6: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_8c9:
	/* 0x8c9: call   1131 <filter_char_buf_equal> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2254ULL);
	__x86_sim_call_depth++;
	return 4401ULL;
x86_l_8ce:
	/* 0x8ce: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_8d1:
	/* 0x8d1: cmp    rcx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 37ULL);
x86_l_8d5:
	/* 0x8d5: ja     8eb <filter_sockaddr_un+0x4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_8eb;
	}
x86_l_8d7:
	/* 0x8d7: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_8e1:
	/* 0x8e1: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_8e5:
	/* 0x8e5: jae    8eb <filter_sockaddr_un+0x4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_8eb;
	}
x86_l_8e7:
	/* 0x8e7: xor    rax,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 1ULL);
x86_l_8eb:
	/* 0x8eb: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_8ef:
	/* 0x8ef: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_8f0:
	/* 0x8f0: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_8f1:
	/* 0x8f1: cmp    r8d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 28ULL);
x86_l_8f5:
	/* 0x8f5: je     935 <filter_sockaddr_un+0x94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_935;
	}
x86_l_8f7:
	/* 0x8f7: cmp    r8d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 26ULL);
x86_l_8fb:
	/* 0x8fb: je     905 <filter_sockaddr_un+0x64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_905;
	}
x86_l_8fd:
	/* 0x8fd: jmp    8eb <filter_sockaddr_un+0x4a> */
	goto x86_l_8eb;
x86_l_8ff:
	/* 0x8ff: cmp    r8d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 8ULL);
x86_l_903:
	/* 0x903: jne    8eb <filter_sockaddr_un+0x4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8eb;
	}
x86_l_905:
	/* 0x905: mov    eax,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_908:
	/* 0x908: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_90b:
	/* 0x90b: mov    edi,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_90d:
	/* 0x90d: call   1091 <filter_char_buf_prefix> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2322ULL);
	__x86_sim_call_depth++;
	return 4241ULL;
x86_l_912:
	/* 0x912: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_915:
	/* 0x915: cmp    rcx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 37ULL);
x86_l_919:
	/* 0x919: ja     8eb <filter_sockaddr_un+0x4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_8eb;
	}
x86_l_91b:
	/* 0x91b: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_925:
	/* 0x925: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_929:
	/* 0x929: jae    8eb <filter_sockaddr_un+0x4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_8eb;
	}
x86_l_92b:
	/* 0x92b: xor    rax,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 1ULL);
x86_l_92f:
	/* 0x92f: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_933:
	/* 0x933: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_934:
	/* 0x934: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_935:
	/* 0x935: movzx  eax,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_938:
	/* 0x938: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_93c:
	/* 0x93c: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_941:
	/* 0x941: call   1ef6 <filter_32ty_map> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2374ULL);
	__x86_sim_call_depth++;
	return 7926ULL;
x86_l_946:
	/* 0x946: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_94a:
	/* 0x94a: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_94b:
	/* 0x94b: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_94c:
	/* 0x94c: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_94d:
	/* 0x94d: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_950:
	/* 0x950: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_952:
	/* 0x952: cmp    rcx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 32ULL);
x86_l_956:
	/* 0x956: ja     991 <filter_32ty+0x45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_991;
	}
x86_l_958:
	/* 0x958: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_95d:
	/* 0x95d: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_961:
	/* 0x961: jae    96a <filter_32ty+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_96a;
	}
x86_l_963:
	/* 0x963: call   1b2c <filter_32ty_selector_val> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2408ULL);
	__x86_sim_call_depth++;
	return 6956ULL;
x86_l_968:
	/* 0x968: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_969:
	/* 0x969: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_96a:
	/* 0x96a: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_96f:
	/* 0x96f: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_973:
	/* 0x973: jb     98c <filter_32ty+0x40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_98c;
	}
x86_l_975:
	/* 0x975: movabs rdx,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 6442450944ULL);
x86_l_97f:
	/* 0x97f: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_983:
	/* 0x983: jae    991 <filter_32ty+0x45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_991;
	}
x86_l_985:
	/* 0x985: call   1d40 <filter_32ty_range> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2442ULL);
	__x86_sim_call_depth++;
	return 7488ULL;
x86_l_98a:
	/* 0x98a: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_98b:
	/* 0x98b: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_98c:
	/* 0x98c: call   1ef6 <filter_32ty_map> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2449ULL);
	__x86_sim_call_depth++;
	return 7926ULL;
x86_l_991:
	/* 0x991: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_992:
	/* 0x992: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_993:
	/* 0x993: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_994:
	/* 0x994: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_997:
	/* 0x997: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_999:
	/* 0x999: cmp    rcx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 32ULL);
x86_l_99d:
	/* 0x99d: ja     9d8 <filter_16ty+0x45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_9d8;
	}
x86_l_99f:
	/* 0x99f: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_9a4:
	/* 0x9a4: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_9a8:
	/* 0x9a8: jae    9b1 <filter_16ty+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_9b1;
	}
x86_l_9aa:
	/* 0x9aa: call   16d4 <filter_16ty_selector_val> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2479ULL);
	__x86_sim_call_depth++;
	return 5844ULL;
x86_l_9af:
	/* 0x9af: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_9b0:
	/* 0x9b0: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_9b1:
	/* 0x9b1: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_9b6:
	/* 0x9b6: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_9ba:
	/* 0x9ba: jb     9d3 <filter_16ty+0x40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_9d3;
	}
x86_l_9bc:
	/* 0x9bc: movabs rdx,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 6442450944ULL);
x86_l_9c6:
	/* 0x9c6: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_9ca:
	/* 0x9ca: jae    9d8 <filter_16ty+0x45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_9d8;
	}
x86_l_9cc:
	/* 0x9cc: call   18ee <filter_16ty_range> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2513ULL);
	__x86_sim_call_depth++;
	return 6382ULL;
x86_l_9d1:
	/* 0x9d1: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_9d2:
	/* 0x9d2: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_9d3:
	/* 0x9d3: call   1aa6 <filter_16ty_map> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2520ULL);
	__x86_sim_call_depth++;
	return 6822ULL;
x86_l_9d8:
	/* 0x9d8: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_9d9:
	/* 0x9d9: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_9da:
	/* 0x9da: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_9db:
	/* 0x9db: mov    rax,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_9de:
	/* 0x9de: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_9e1:
	/* 0x9e1: movsxd rcx,edx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_9e4:
	/* 0x9e4: mov    edx,DWORD PTR [rsi+rcx*1-0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 18446744073709551612ULL);
x86_l_9e8:
	/* 0x9e8: mov    esi,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_9ea:
	/* 0x9ea: add    rsi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_9ed:
	/* 0x9ed: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_9f0:
	/* 0x9f0: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9f2:
	/* 0x9f2: cmp    ecx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 25ULL);
x86_l_9f5:
	/* 0x9f5: jg     a0b <filter_char_buf+0x31> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_a0b;
	}
x86_l_9f7:
	/* 0x9f7: lea    edi,[rcx-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_9fa:
	/* 0x9fa: cmp    edi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_9fd:
	/* 0x9fd: jb     a42 <filter_char_buf+0x68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_a42;
	}
x86_l_9ff:
	/* 0x9ff: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a02:
	/* 0xa02: je     a38 <filter_char_buf+0x5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a38;
	}
x86_l_a04:
	/* 0xa04: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_a07:
	/* 0xa07: je     a1a <filter_char_buf+0x40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a1a;
	}
x86_l_a09:
	/* 0xa09: jmp    a59 <filter_char_buf+0x7f> */
	goto x86_l_a59;
x86_l_a0b:
	/* 0xa0b: cmp    ecx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 32ULL);
x86_l_a0e:
	/* 0xa0e: jg     a24 <filter_char_buf+0x4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_a24;
	}
x86_l_a10:
	/* 0xa10: cmp    ecx,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 26ULL);
x86_l_a13:
	/* 0xa13: je     a38 <filter_char_buf+0x5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a38;
	}
x86_l_a15:
	/* 0xa15: cmp    ecx,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 27ULL);
x86_l_a18:
	/* 0xa18: jne    a59 <filter_char_buf+0x7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_a59;
	}
x86_l_a1a:
	/* 0xa1a: mov    edi,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a1d:
	/* 0xa1d: call   f49 <filter_char_buf_postfix> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2594ULL);
	__x86_sim_call_depth++;
	return 3913ULL;
x86_l_a22:
	/* 0xa22: jmp    a56 <filter_char_buf+0x7c> */
	goto x86_l_a56;
x86_l_a24:
	/* 0xa24: cmp    ecx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 33ULL);
x86_l_a27:
	/* 0xa27: je     a4c <filter_char_buf+0x72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a4c;
	}
x86_l_a29:
	/* 0xa29: cmp    ecx,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 34ULL);
x86_l_a2c:
	/* 0xa2c: jne    a59 <filter_char_buf+0x7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_a59;
	}
x86_l_a2e:
	/* 0xa2e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_a31:
	/* 0xa31: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_a36:
	/* 0xa36: jmp    a51 <filter_char_buf+0x77> */
	goto x86_l_a51;
x86_l_a38:
	/* 0xa38: mov    edi,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a3b:
	/* 0xa3b: call   1091 <filter_char_buf_prefix> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2624ULL);
	__x86_sim_call_depth++;
	return 4241ULL;
x86_l_a40:
	/* 0xa40: jmp    a56 <filter_char_buf+0x7c> */
	goto x86_l_a56;
x86_l_a42:
	/* 0xa42: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_a45:
	/* 0xa45: call   1131 <filter_char_buf_equal> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2634ULL);
	__x86_sim_call_depth++;
	return 4401ULL;
x86_l_a4a:
	/* 0xa4a: jmp    a56 <filter_char_buf+0x7c> */
	goto x86_l_a56;
x86_l_a4c:
	/* 0xa4c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_a4f:
	/* 0xa4f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a51:
	/* 0xa51: call   14be <filter_char_substring> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2646ULL);
	__x86_sim_call_depth++;
	return 5310ULL;
x86_l_a56:
	/* 0xa56: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_a59:
	/* 0xa59: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_a5c:
	/* 0xa5c: ja     a7b <filter_char_buf+0xa1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_a7b;
	}
x86_l_a5e:
	/* 0xa5e: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_a60:
	/* 0xa60: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_a6a:
	/* 0xa6a: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_a6e:
	/* 0xa6e: jae    a7b <filter_char_buf+0xa1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_a7b;
	}
x86_l_a70:
	/* 0xa70: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a72:
	/* 0xa72: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a75:
	/* 0xa75: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_a78:
	/* 0xa78: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_a7b:
	/* 0xa7b: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_a7c:
	/* 0xa7c: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_a7d:
	/* 0xa7d: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_a7e:
	/* 0xa7e: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_a81:
	/* 0xa81: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a83:
	/* 0xa83: cmp    rcx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 32ULL);
x86_l_a87:
	/* 0xa87: ja     ac2 <filter_64ty+0x45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_ac2;
	}
x86_l_a89:
	/* 0xa89: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_a8e:
	/* 0xa8e: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_a92:
	/* 0xa92: jae    a9b <filter_64ty+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_a9b;
	}
x86_l_a94:
	/* 0xa94: call   ac4 <filter_64ty_selector_val> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2713ULL);
	__x86_sim_call_depth++;
	goto x86_l_ac4;
x86_l_a99:
	/* 0xa99: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_a9a:
	/* 0xa9a: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_a9b:
	/* 0xa9b: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_aa0:
	/* 0xaa0: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_aa4:
	/* 0xaa4: jb     abd <filter_64ty+0x40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_abd;
	}
x86_l_aa6:
	/* 0xaa6: movabs rdx,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 6442450944ULL);
x86_l_ab0:
	/* 0xab0: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_ab4:
	/* 0xab4: jae    ac2 <filter_64ty+0x45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_ac2;
	}
x86_l_ab6:
	/* 0xab6: call   cf6 <filter_64ty_range> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2747ULL);
	__x86_sim_call_depth++;
	return 3318ULL;
x86_l_abb:
	/* 0xabb: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_abc:
	/* 0xabc: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_abd:
	/* 0xabd: call   ed1 <filter_64ty_map> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2754ULL);
	__x86_sim_call_depth++;
	return 3793ULL;
x86_l_ac2:
	/* 0xac2: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_ac3:
	/* 0xac3: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_ac4:
	/* 0xac4: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ac7:
	/* 0xac7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_acc:
	/* 0xacc: cmp    rcx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 37ULL);
x86_l_ad0:
	/* 0xad0: ja     b48 <filter_64ty_selector_val+0x84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2888ULL;
	}
x86_l_ad2:
	/* 0xad2: movabs rdx,0x200c000040 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280128ULL);
x86_l_adc:
	/* 0xadc: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_ae0:
	/* 0xae0: jae    ae3 <filter_64ty_selector_val+0x1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_ae3;
	}
x86_l_ae2:
	/* 0xae2: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_ae3:
	/* 0xae3: mov    edx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 24ULL);
x86_l_ae8:
	/* 0xae8: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_aec:
	/* 0xaec: jae    b04 <filter_64ty_selector_val+0x40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_b04;
	}
x86_l_aee:
	/* 0xaee: mov    rdx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_af1:
	/* 0xaf1: cmp    rdx,QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_af5:
	/* 0xaf5: jne    c26 <filter_64ty_selector_val+0x162> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3110ULL;
	}
x86_l_afb:
	/* 0xafb: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_afd:
	/* 0xafd: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_b00:
	/* 0xb00: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_b03:
	/* 0xb03: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_b04:
	/* 0xb04: cmp    rcx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 12ULL);
x86_l_b08:
	/* 0xb08: jne    b48 <filter_64ty_selector_val+0x84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2888ULL;
	}
x86_l_b0a:
	/* 0xb0a: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
	return 2829ULL;
}

static __noinline __u64 tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_filter_arg_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 2829ULL: goto x86_l_b0d;
	case 2833ULL: goto x86_l_b11;
	case 2835ULL: goto x86_l_b13;
	case 2838ULL: goto x86_l_b16;
	case 2841ULL: goto x86_l_b19;
	case 2847ULL: goto x86_l_b1f;
	case 2851ULL: goto x86_l_b23;
	case 2853ULL: goto x86_l_b25;
	case 2856ULL: goto x86_l_b28;
	case 2862ULL: goto x86_l_b2e;
	case 2866ULL: goto x86_l_b32;
	case 2868ULL: goto x86_l_b34;
	case 2871ULL: goto x86_l_b37;
	case 2877ULL: goto x86_l_b3d;
	case 2881ULL: goto x86_l_b41;
	case 2883ULL: goto x86_l_b43;
	case 2888ULL: goto x86_l_b48;
	case 2891ULL: goto x86_l_b4b;
	case 2893ULL: goto x86_l_b4d;
	case 2896ULL: goto x86_l_b50;
	case 2902ULL: goto x86_l_b56;
	case 2905ULL: goto x86_l_b59;
	case 2908ULL: goto x86_l_b5c;
	case 2914ULL: goto x86_l_b62;
	case 2919ULL: goto x86_l_b67;
	case 2922ULL: goto x86_l_b6a;
	case 2928ULL: goto x86_l_b70;
	case 2931ULL: goto x86_l_b73;
	case 2935ULL: goto x86_l_b77;
	case 2941ULL: goto x86_l_b7d;
	case 2944ULL: goto x86_l_b80;
	case 2947ULL: goto x86_l_b83;
	case 2953ULL: goto x86_l_b89;
	case 2957ULL: goto x86_l_b8d;
	case 2963ULL: goto x86_l_b93;
	case 2966ULL: goto x86_l_b96;
	case 2972ULL: goto x86_l_b9c;
	case 2976ULL: goto x86_l_ba0;
	case 2982ULL: goto x86_l_ba6;
	case 2985ULL: goto x86_l_ba9;
	case 2991ULL: goto x86_l_baf;
	case 2995ULL: goto x86_l_bb3;
	case 3001ULL: goto x86_l_bb9;
	case 3006ULL: goto x86_l_bbe;
	case 3009ULL: goto x86_l_bc1;
	case 3012ULL: goto x86_l_bc4;
	case 3018ULL: goto x86_l_bca;
	case 3023ULL: goto x86_l_bcf;
	case 3026ULL: goto x86_l_bd2;
	case 3032ULL: goto x86_l_bd8;
	case 3035ULL: goto x86_l_bdb;
	case 3039ULL: goto x86_l_bdf;
	case 3045ULL: goto x86_l_be5;
	case 3048ULL: goto x86_l_be8;
	case 3051ULL: goto x86_l_beb;
	case 3057ULL: goto x86_l_bf1;
	case 3061ULL: goto x86_l_bf5;
	case 3067ULL: goto x86_l_bfb;
	case 3070ULL: goto x86_l_bfe;
	case 3076ULL: goto x86_l_c04;
	case 3080ULL: goto x86_l_c08;
	case 3086ULL: goto x86_l_c0e;
	case 3089ULL: goto x86_l_c11;
	case 3095ULL: goto x86_l_c17;
	case 3099ULL: goto x86_l_c1b;
	case 3105ULL: goto x86_l_c21;
	case 3110ULL: goto x86_l_c26;
	case 3113ULL: goto x86_l_c29;
	case 3116ULL: goto x86_l_c2c;
	case 3118ULL: goto x86_l_c2e;
	case 3122ULL: goto x86_l_c32;
	case 3128ULL: goto x86_l_c38;
	case 3131ULL: goto x86_l_c3b;
	case 3133ULL: goto x86_l_c3d;
	case 3137ULL: goto x86_l_c41;
	case 3143ULL: goto x86_l_c47;
	case 3146ULL: goto x86_l_c4a;
	case 3148ULL: goto x86_l_c4c;
	case 3152ULL: goto x86_l_c50;
	case 3158ULL: goto x86_l_c56;
	case 3161ULL: goto x86_l_c59;
	case 3167ULL: goto x86_l_c5f;
	case 3169ULL: goto x86_l_c61;
	case 3179ULL: goto x86_l_c6b;
	case 3183ULL: goto x86_l_c6f;
	case 3189ULL: goto x86_l_c75;
	case 3191ULL: goto x86_l_c77;
	case 3194ULL: goto x86_l_c7a;
	case 3198ULL: goto x86_l_c7e;
	case 3204ULL: goto x86_l_c84;
	case 3207ULL: goto x86_l_c87;
	case 3210ULL: goto x86_l_c8a;
	case 3212ULL: goto x86_l_c8c;
	case 3216ULL: goto x86_l_c90;
	case 3222ULL: goto x86_l_c96;
	case 3225ULL: goto x86_l_c99;
	case 3227ULL: goto x86_l_c9b;
	case 3231ULL: goto x86_l_c9f;
	case 3237ULL: goto x86_l_ca5;
	case 3240ULL: goto x86_l_ca8;
	case 3242ULL: goto x86_l_caa;
	case 3246ULL: goto x86_l_cae;
	case 3252ULL: goto x86_l_cb4;
	case 3254ULL: goto x86_l_cb6;
	case 3257ULL: goto x86_l_cb9;
	case 3261ULL: goto x86_l_cbd;
	case 3267ULL: goto x86_l_cc3;
	case 3270ULL: goto x86_l_cc6;
	case 3273ULL: goto x86_l_cc9;
	case 3275ULL: goto x86_l_ccb;
	case 3279ULL: goto x86_l_ccf;
	case 3285ULL: goto x86_l_cd5;
	case 3288ULL: goto x86_l_cd8;
	case 3290ULL: goto x86_l_cda;
	case 3294ULL: goto x86_l_cde;
	case 3300ULL: goto x86_l_ce4;
	case 3303ULL: goto x86_l_ce7;
	case 3305ULL: goto x86_l_ce9;
	case 3309ULL: goto x86_l_ced;
	case 3315ULL: goto x86_l_cf3;
	case 3317ULL: goto x86_l_cf5;
	case 3318ULL: goto x86_l_cf6;
	case 3321ULL: goto x86_l_cf9;
	case 3324ULL: goto x86_l_cfc;
	case 3327ULL: goto x86_l_cff;
	case 3333ULL: goto x86_l_d05;
	case 3338ULL: goto x86_l_d0a;
	case 3341ULL: goto x86_l_d0d;
	case 3347ULL: goto x86_l_d13;
	case 3350ULL: goto x86_l_d16;
	case 3353ULL: goto x86_l_d19;
	case 3355ULL: goto x86_l_d1b;
	case 3360ULL: goto x86_l_d20;
	case 3364ULL: goto x86_l_d24;
	case 3366ULL: goto x86_l_d26;
	case 3370ULL: goto x86_l_d2a;
	case 3376ULL: goto x86_l_d30;
	case 3379ULL: goto x86_l_d33;
	case 3382ULL: goto x86_l_d36;
	case 3388ULL: goto x86_l_d3c;
	case 3392ULL: goto x86_l_d40;
	case 3394ULL: goto x86_l_d42;
	case 3398ULL: goto x86_l_d46;
	case 3404ULL: goto x86_l_d4c;
	case 3407ULL: goto x86_l_d4f;
	case 3413ULL: goto x86_l_d55;
	case 3417ULL: goto x86_l_d59;
	case 3419ULL: goto x86_l_d5b;
	case 3423ULL: goto x86_l_d5f;
	case 3429ULL: goto x86_l_d65;
	case 3432ULL: goto x86_l_d68;
	case 3438ULL: goto x86_l_d6e;
	case 3440ULL: goto x86_l_d70;
	case 3444ULL: goto x86_l_d74;
	case 3450ULL: goto x86_l_d7a;
	case 3454ULL: goto x86_l_d7e;
	case 3460ULL: goto x86_l_d84;
	case 3465ULL: goto x86_l_d89;
	case 3468ULL: goto x86_l_d8c;
	case 3472ULL: goto x86_l_d90;
	case 3476ULL: goto x86_l_d94;
	case 3480ULL: goto x86_l_d98;
	case 3483ULL: goto x86_l_d9b;
	case 3486ULL: goto x86_l_d9e;
	case 3489ULL: goto x86_l_da1;
	case 3495ULL: goto x86_l_da7;
	case 3499ULL: goto x86_l_dab;
	case 3503ULL: goto x86_l_daf;
	case 3507ULL: goto x86_l_db3;
	case 3511ULL: goto x86_l_db7;
	case 3514ULL: goto x86_l_dba;
	case 3517ULL: goto x86_l_dbd;
	case 3520ULL: goto x86_l_dc0;
	case 3526ULL: goto x86_l_dc6;
	case 3530ULL: goto x86_l_dca;
	case 3534ULL: goto x86_l_dce;
	case 3538ULL: goto x86_l_dd2;
	case 3542ULL: goto x86_l_dd6;
	case 3545ULL: goto x86_l_dd9;
	case 3548ULL: goto x86_l_ddc;
	case 3551ULL: goto x86_l_ddf;
	case 3557ULL: goto x86_l_de5;
	case 3561ULL: goto x86_l_de9;
	case 3564ULL: goto x86_l_dec;
	case 3568ULL: goto x86_l_df0;
	case 3572ULL: goto x86_l_df4;
	case 3577ULL: goto x86_l_df9;
	case 3580ULL: goto x86_l_dfc;
	case 3583ULL: goto x86_l_dff;
	case 3585ULL: goto x86_l_e01;
	case 3590ULL: goto x86_l_e06;
	case 3594ULL: goto x86_l_e0a;
	case 3596ULL: goto x86_l_e0c;
	case 3600ULL: goto x86_l_e10;
	case 3602ULL: goto x86_l_e12;
	case 3603ULL: goto x86_l_e13;
	case 3606ULL: goto x86_l_e16;
	case 3610ULL: goto x86_l_e1a;
	case 3614ULL: goto x86_l_e1e;
	case 3618ULL: goto x86_l_e22;
	case 3621ULL: goto x86_l_e25;
	case 3624ULL: goto x86_l_e28;
	case 3627ULL: goto x86_l_e2b;
	case 3633ULL: goto x86_l_e31;
	case 3637ULL: goto x86_l_e35;
	case 3641ULL: goto x86_l_e39;
	case 3645ULL: goto x86_l_e3d;
	case 3649ULL: goto x86_l_e41;
	case 3652ULL: goto x86_l_e44;
	case 3655ULL: goto x86_l_e47;
	case 3658ULL: goto x86_l_e4a;
	case 3660ULL: goto x86_l_e4c;
	case 3664ULL: goto x86_l_e50;
	case 3668ULL: goto x86_l_e54;
	case 3672ULL: goto x86_l_e58;
	case 3676ULL: goto x86_l_e5c;
	case 3679ULL: goto x86_l_e5f;
	case 3682ULL: goto x86_l_e62;
	case 3685ULL: goto x86_l_e65;
	case 3687ULL: goto x86_l_e67;
	case 3691ULL: goto x86_l_e6b;
	case 3694ULL: goto x86_l_e6e;
	case 3698ULL: goto x86_l_e72;
	case 3702ULL: goto x86_l_e76;
	case 3705ULL: goto x86_l_e79;
	case 3708ULL: goto x86_l_e7c;
	case 3710ULL: goto x86_l_e7e;
	case 3713ULL: goto x86_l_e81;
	case 3716ULL: goto x86_l_e84;
	case 3718ULL: goto x86_l_e86;
	case 3722ULL: goto x86_l_e8a;
	case 3724ULL: goto x86_l_e8c;
	case 3728ULL: goto x86_l_e90;
	case 3730ULL: goto x86_l_e92;
	case 3733ULL: goto x86_l_e95;
	case 3735ULL: goto x86_l_e97;
	case 3739ULL: goto x86_l_e9b;
	case 3741ULL: goto x86_l_e9d;
	case 3745ULL: goto x86_l_ea1;
	case 3751ULL: goto x86_l_ea7;
	case 3754ULL: goto x86_l_eaa;
	case 3756ULL: goto x86_l_eac;
	case 3758ULL: goto x86_l_eae;
	case 3762ULL: goto x86_l_eb2;
	case 3764ULL: goto x86_l_eb4;
	case 3768ULL: goto x86_l_eb8;
	case 3774ULL: goto x86_l_ebe;
	case 3776ULL: goto x86_l_ec0;
	case 3778ULL: goto x86_l_ec2;
	case 3781ULL: goto x86_l_ec5;
	case 3784ULL: goto x86_l_ec8;
	case 3787ULL: goto x86_l_ecb;
	case 3789ULL: goto x86_l_ecd;
	case 3792ULL: goto x86_l_ed0;
	case 3793ULL: goto x86_l_ed1;
	case 3795ULL: goto x86_l_ed3;
	case 3796ULL: goto x86_l_ed4;
	case 3800ULL: goto x86_l_ed8;
	case 3803ULL: goto x86_l_edb;
	case 3806ULL: goto x86_l_ede;
	case 3810ULL: goto x86_l_ee2;
	case 3814ULL: goto x86_l_ee6;
	case 3821ULL: goto x86_l_eed;
	case 3826ULL: goto x86_l_ef2;
	case 3831ULL: goto x86_l_ef7;
	case 3833ULL: goto x86_l_ef9;
	case 3836ULL: goto x86_l_efc;
	case 3838ULL: goto x86_l_efe;
	case 3841ULL: goto x86_l_f01;
	case 3844ULL: goto x86_l_f04;
	case 3849ULL: goto x86_l_f09;
	case 3854ULL: goto x86_l_f0e;
	case 3859ULL: goto x86_l_f13;
	case 3861ULL: goto x86_l_f15;
	case 3864ULL: goto x86_l_f18;
	case 3867ULL: goto x86_l_f1b;
	case 3869ULL: goto x86_l_f1d;
	case 3872ULL: goto x86_l_f20;
	case 3874ULL: goto x86_l_f22;
	case 3877ULL: goto x86_l_f25;
	case 3880ULL: goto x86_l_f28;
	case 3882ULL: goto x86_l_f2a;
	case 3884ULL: goto x86_l_f2c;
	case 3888ULL: goto x86_l_f30;
	case 3889ULL: goto x86_l_f31;
	case 3891ULL: goto x86_l_f33;
	case 3892ULL: goto x86_l_f34;
	case 3895ULL: goto x86_l_f37;
	case 3898ULL: goto x86_l_f3a;
	case 3900ULL: goto x86_l_f3c;
	case 3902ULL: goto x86_l_f3e;
	case 3905ULL: goto x86_l_f41;
	case 3909ULL: goto x86_l_f45;
	case 3910ULL: goto x86_l_f46;
	case 3912ULL: goto x86_l_f48;
	case 3913ULL: goto x86_l_f49;
	case 3915ULL: goto x86_l_f4b;
	case 3917ULL: goto x86_l_f4d;
	case 3918ULL: goto x86_l_f4e;
	case 3922ULL: goto x86_l_f52;
	case 3924ULL: goto x86_l_f54;
	case 3927ULL: goto x86_l_f57;
	case 3931ULL: goto x86_l_f5b;
	case 3939ULL: goto x86_l_f63;
	case 3946ULL: goto x86_l_f6a;
	case 3951ULL: goto x86_l_f6f;
	case 3956ULL: goto x86_l_f74;
	case 3958ULL: goto x86_l_f76;
	case 3961ULL: goto x86_l_f79;
	case 3963ULL: goto x86_l_f7b;
	case 3965ULL: goto x86_l_f7d;
	case 3971ULL: goto x86_l_f83;
	case 3974ULL: goto x86_l_f86;
	case 3980ULL: goto x86_l_f8c;
	case 3987ULL: goto x86_l_f93;
	case 3992ULL: goto x86_l_f98;
	case 3997ULL: goto x86_l_f9d;
	case 3999ULL: goto x86_l_f9f;
	case 4002ULL: goto x86_l_fa2;
	case 4008ULL: goto x86_l_fa8;
	case 4011ULL: goto x86_l_fab;
	case 4014ULL: goto x86_l_fae;
	case 4019ULL: goto x86_l_fb3;
	case 4022ULL: goto x86_l_fb6;
	case 4025ULL: goto x86_l_fb9;
	case 4027ULL: goto x86_l_fbb;
	case 4029ULL: goto x86_l_fbd;
	case 4032ULL: goto x86_l_fc0;
	case 4035ULL: goto x86_l_fc3;
	case 4039ULL: goto x86_l_fc7;
	case 4042ULL: goto x86_l_fca;
	case 4046ULL: goto x86_l_fce;
	case 4048ULL: goto x86_l_fd0;
	case 4055ULL: goto x86_l_fd7;
	case 4059ULL: goto x86_l_fdb;
	case 4063ULL: goto x86_l_fdf;
	case 4070ULL: goto x86_l_fe6;
	case 4075ULL: goto x86_l_feb;
	case 4079ULL: goto x86_l_fef;
	case 4083ULL: goto x86_l_ff3;
	case 4087ULL: goto x86_l_ff7;
	case 4089ULL: goto x86_l_ff9;
	case 4093ULL: goto x86_l_ffd;
	case 4097ULL: goto x86_l_1001;
	case 4104ULL: goto x86_l_1008;
	case 4109ULL: goto x86_l_100d;
	case 4113ULL: goto x86_l_1011;
	case 4117ULL: goto x86_l_1015;
	case 4119ULL: goto x86_l_1017;
	case 4123ULL: goto x86_l_101b;
	case 4127ULL: goto x86_l_101f;
	case 4134ULL: goto x86_l_1026;
	case 4139ULL: goto x86_l_102b;
	case 4143ULL: goto x86_l_102f;
	case 4146ULL: goto x86_l_1032;
	case 4149ULL: goto x86_l_1035;
	case 4151ULL: goto x86_l_1037;
	case 4155ULL: goto x86_l_103b;
	case 4157ULL: goto x86_l_103d;
	case 4161ULL: goto x86_l_1041;
	case 4165ULL: goto x86_l_1045;
	case 4172ULL: goto x86_l_104c;
	case 4177ULL: goto x86_l_1051;
	case 4180ULL: goto x86_l_1054;
	case 4184ULL: goto x86_l_1058;
	case 4188ULL: goto x86_l_105c;
	case 4192ULL: goto x86_l_1060;
	case 4196ULL: goto x86_l_1064;
	case 4200ULL: goto x86_l_1068;
	case 4206ULL: goto x86_l_106e;
	case 4211ULL: goto x86_l_1073;
	case 4214ULL: goto x86_l_1076;
	case 4216ULL: goto x86_l_1078;
	case 4219ULL: goto x86_l_107b;
	case 4221ULL: goto x86_l_107d;
	case 4224ULL: goto x86_l_1080;
	case 4227ULL: goto x86_l_1083;
	case 4229ULL: goto x86_l_1085;
	case 4231ULL: goto x86_l_1087;
	case 4235ULL: goto x86_l_108b;
	case 4236ULL: goto x86_l_108c;
	case 4238ULL: goto x86_l_108e;
	case 4240ULL: goto x86_l_1090;
	case 4241ULL: goto x86_l_1091;
	default: return 0xffffffffffffffffULL;
	}
x86_l_b0d:
	/* 0xb0d: test   QWORD PTR [rdi+0x10],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b11:
	/* 0xb11: jne    ae2 <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2786ULL;
	}
x86_l_b13:
	/* 0xb13: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b16:
	/* 0xb16: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_b19:
	/* 0xb19: jb     cf3 <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_cf3;
	}
x86_l_b1f:
	/* 0xb1f: test   QWORD PTR [rdi+0x18],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b23:
	/* 0xb23: jne    ae2 <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2786ULL;
	}
x86_l_b25:
	/* 0xb25: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_b28:
	/* 0xb28: jb     cf3 <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_cf3;
	}
x86_l_b2e:
	/* 0xb2e: test   QWORD PTR [rdi+0x20],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b32:
	/* 0xb32: jne    ae2 <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2786ULL;
	}
x86_l_b34:
	/* 0xb34: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_b37:
	/* 0xb37: jb     cf3 <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_cf3;
	}
x86_l_b3d:
	/* 0xb3d: test   QWORD PTR [rdi+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b41:
	/* 0xb41: jne    ae2 <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2786ULL;
	}
x86_l_b43:
	/* 0xb43: jmp    cf3 <filter_64ty_selector_val+0x22f> */
	goto x86_l_cf3;
x86_l_b48:
	/* 0xb48: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_b4b:
	/* 0xb4b: je     bbe <filter_64ty_selector_val+0xfa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bbe;
	}
x86_l_b4d:
	/* 0xb4d: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_b50:
	/* 0xb50: jne    cf3 <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_cf3;
	}
x86_l_b56:
	/* 0xb56: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_b59:
	/* 0xb59: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_b5c:
	/* 0xb5c: ja     cb6 <filter_64ty_selector_val+0x1f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_cb6;
	}
x86_l_b62:
	/* 0xb62: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_b67:
	/* 0xb67: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_b6a:
	/* 0xb6a: jae    cb6 <filter_64ty_selector_val+0x1f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_cb6;
	}
x86_l_b70:
	/* 0xb70: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b73:
	/* 0xb73: cmp    rcx,QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_b77:
	/* 0xb77: jl     ae2 <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 2786ULL;
	}
x86_l_b7d:
	/* 0xb7d: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b80:
	/* 0xb80: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_b83:
	/* 0xb83: jb     cf3 <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_cf3;
	}
x86_l_b89:
	/* 0xb89: cmp    rcx,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_b8d:
	/* 0xb8d: jl     ae2 <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 2786ULL;
	}
x86_l_b93:
	/* 0xb93: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_b96:
	/* 0xb96: jb     cf3 <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_cf3;
	}
x86_l_b9c:
	/* 0xb9c: cmp    rcx,QWORD PTR [rdi+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_ba0:
	/* 0xba0: jl     ae2 <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 2786ULL;
	}
x86_l_ba6:
	/* 0xba6: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_ba9:
	/* 0xba9: jb     cf3 <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_cf3;
	}
x86_l_baf:
	/* 0xbaf: cmp    rcx,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_bb3:
	/* 0xbb3: jl     ae2 <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 2786ULL;
	}
x86_l_bb9:
	/* 0xbb9: jmp    cf3 <filter_64ty_selector_val+0x22f> */
	goto x86_l_cf3;
x86_l_bbe:
	/* 0xbbe: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_bc1:
	/* 0xbc1: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_bc4:
	/* 0xbc4: ja     c77 <filter_64ty_selector_val+0x1b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_c77;
	}
x86_l_bca:
	/* 0xbca: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_bcf:
	/* 0xbcf: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_bd2:
	/* 0xbd2: jae    c77 <filter_64ty_selector_val+0x1b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_c77;
	}
x86_l_bd8:
	/* 0xbd8: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bdb:
	/* 0xbdb: cmp    rcx,QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_bdf:
	/* 0xbdf: jg     ae2 <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 2786ULL;
	}
x86_l_be5:
	/* 0xbe5: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_be8:
	/* 0xbe8: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_beb:
	/* 0xbeb: jb     cf3 <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_cf3;
	}
x86_l_bf1:
	/* 0xbf1: cmp    rcx,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_bf5:
	/* 0xbf5: jg     ae2 <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 2786ULL;
	}
x86_l_bfb:
	/* 0xbfb: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_bfe:
	/* 0xbfe: jb     cf3 <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_cf3;
	}
x86_l_c04:
	/* 0xc04: cmp    rcx,QWORD PTR [rdi+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_c08:
	/* 0xc08: jg     ae2 <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 2786ULL;
	}
x86_l_c0e:
	/* 0xc0e: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_c11:
	/* 0xc11: jb     cf3 <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_cf3;
	}
x86_l_c17:
	/* 0xc17: cmp    rcx,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_c1b:
	/* 0xc1b: jg     ae2 <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 2786ULL;
	}
x86_l_c21:
	/* 0xc21: jmp    cf3 <filter_64ty_selector_val+0x22f> */
	goto x86_l_cf3;
x86_l_c26:
	/* 0xc26: mov    esi,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c29:
	/* 0xc29: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_c2c:
	/* 0xc2c: jb     c56 <filter_64ty_selector_val+0x192> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_c56;
	}
x86_l_c2e:
	/* 0xc2e: cmp    rdx,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_c32:
	/* 0xc32: je     afb <filter_64ty_selector_val+0x37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2811ULL;
	}
x86_l_c38:
	/* 0xc38: cmp    esi,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 25ULL);
x86_l_c3b:
	/* 0xc3b: jb     c56 <filter_64ty_selector_val+0x192> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_c56;
	}
x86_l_c3d:
	/* 0xc3d: cmp    rdx,QWORD PTR [rdi+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_c41:
	/* 0xc41: je     afb <filter_64ty_selector_val+0x37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2811ULL;
	}
x86_l_c47:
	/* 0xc47: cmp    esi,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 33ULL);
x86_l_c4a:
	/* 0xc4a: jb     c56 <filter_64ty_selector_val+0x192> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_c56;
	}
x86_l_c4c:
	/* 0xc4c: cmp    rdx,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_c50:
	/* 0xc50: je     afb <filter_64ty_selector_val+0x37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2811ULL;
	}
x86_l_c56:
	/* 0xc56: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_c59:
	/* 0xc59: ja     cf3 <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_cf3;
	}
x86_l_c5f:
	/* 0xc5f: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_c61:
	/* 0xc61: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_c6b:
	/* 0xc6b: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_c6f:
	/* 0xc6f: jb     ae2 <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2786ULL;
	}
x86_l_c75:
	/* 0xc75: jmp    cf3 <filter_64ty_selector_val+0x22f> */
	goto x86_l_cf3;
x86_l_c77:
	/* 0xc77: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c7a:
	/* 0xc7a: cmp    rcx,QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_c7e:
	/* 0xc7e: ja     ae2 <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2786ULL;
	}
x86_l_c84:
	/* 0xc84: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c87:
	/* 0xc87: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_c8a:
	/* 0xc8a: jb     cf3 <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_cf3;
	}
x86_l_c8c:
	/* 0xc8c: cmp    rcx,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_c90:
	/* 0xc90: ja     ae2 <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2786ULL;
	}
x86_l_c96:
	/* 0xc96: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_c99:
	/* 0xc99: jb     cf3 <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_cf3;
	}
x86_l_c9b:
	/* 0xc9b: cmp    rcx,QWORD PTR [rdi+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_c9f:
	/* 0xc9f: ja     ae2 <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2786ULL;
	}
x86_l_ca5:
	/* 0xca5: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_ca8:
	/* 0xca8: jb     cf3 <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_cf3;
	}
x86_l_caa:
	/* 0xcaa: cmp    rcx,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_cae:
	/* 0xcae: ja     ae2 <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2786ULL;
	}
x86_l_cb4:
	/* 0xcb4: jmp    cf3 <filter_64ty_selector_val+0x22f> */
	goto x86_l_cf3;
x86_l_cb6:
	/* 0xcb6: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cb9:
	/* 0xcb9: cmp    rcx,QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_cbd:
	/* 0xcbd: jb     ae2 <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2786ULL;
	}
x86_l_cc3:
	/* 0xcc3: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cc6:
	/* 0xcc6: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_cc9:
	/* 0xcc9: jb     cf3 <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_cf3;
	}
x86_l_ccb:
	/* 0xccb: cmp    rcx,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_ccf:
	/* 0xccf: jb     ae2 <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2786ULL;
	}
x86_l_cd5:
	/* 0xcd5: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_cd8:
	/* 0xcd8: jb     cf3 <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_cf3;
	}
x86_l_cda:
	/* 0xcda: cmp    rcx,QWORD PTR [rdi+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_cde:
	/* 0xcde: jb     ae2 <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2786ULL;
	}
x86_l_ce4:
	/* 0xce4: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_ce7:
	/* 0xce7: jb     cf3 <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_cf3;
	}
x86_l_ce9:
	/* 0xce9: cmp    rcx,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_ced:
	/* 0xced: jb     ae2 <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2786ULL;
	}
x86_l_cf3:
	/* 0xcf3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cf5:
	/* 0xcf5: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_cf6:
	/* 0xcf6: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_cf9:
	/* 0xcf9: mov    eax,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_cfc:
	/* 0xcfc: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_cff:
	/* 0xcff: ja     df9 <filter_64ty_range+0x103> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_df9;
	}
x86_l_d05:
	/* 0xd05: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_d0a:
	/* 0xd0a: bt     edx,eax */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_d0d:
	/* 0xd0d: jae    df9 <filter_64ty_range+0x103> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_df9;
	}
x86_l_d13:
	/* 0xd13: mov    rsi,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d16:
	/* 0xd16: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_d19:
	/* 0xd19: jne    d89 <filter_64ty_range+0x93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_d89;
	}
x86_l_d1b:
	/* 0xd1b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d20:
	/* 0xd20: cmp    QWORD PTR [rdi+0x10],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d24:
	/* 0xd24: jg     d30 <filter_64ty_range+0x3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_d30;
	}
x86_l_d26:
	/* 0xd26: cmp    rsi,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_d2a:
	/* 0xd2a: jle    e12 <filter_64ty_range+0x11c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_e12;
	}
x86_l_d30:
	/* 0xd30: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d33:
	/* 0xd33: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_d36:
	/* 0xd36: jb     ec0 <filter_64ty_range+0x1ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_ec0;
	}
x86_l_d3c:
	/* 0xd3c: cmp    QWORD PTR [rdi+0x20],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d40:
	/* 0xd40: jg     d4c <filter_64ty_range+0x56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_d4c;
	}
x86_l_d42:
	/* 0xd42: cmp    rsi,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_d46:
	/* 0xd46: jle    e12 <filter_64ty_range+0x11c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_e12;
	}
x86_l_d4c:
	/* 0xd4c: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_d4f:
	/* 0xd4f: jb     ec0 <filter_64ty_range+0x1ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_ec0;
	}
x86_l_d55:
	/* 0xd55: cmp    QWORD PTR [rdi+0x30],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d59:
	/* 0xd59: jg     d65 <filter_64ty_range+0x6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_d65;
	}
x86_l_d5b:
	/* 0xd5b: cmp    rsi,QWORD PTR [rdi+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_d5f:
	/* 0xd5f: jle    e12 <filter_64ty_range+0x11c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_e12;
	}
x86_l_d65:
	/* 0xd65: cmp    edx,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 57ULL);
x86_l_d68:
	/* 0xd68: jb     ec0 <filter_64ty_range+0x1ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_ec0;
	}
x86_l_d6e:
	/* 0xd6e: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d70:
	/* 0xd70: cmp    QWORD PTR [rdi+0x40],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_d74:
	/* 0xd74: jg     ec2 <filter_64ty_range+0x1cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_ec2;
	}
x86_l_d7a:
	/* 0xd7a: cmp    rsi,QWORD PTR [rdi+0x48] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 72ULL);
x86_l_d7e:
	/* 0xd7e: jle    e12 <filter_64ty_range+0x11c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_e12;
	}
x86_l_d84:
	/* 0xd84: jmp    ec2 <filter_64ty_range+0x1cc> */
	goto x86_l_ec2;
x86_l_d89:
	/* 0xd89: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d8c:
	/* 0xd8c: cmp    QWORD PTR [rdi+0x10],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d90:
	/* 0xd90: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_d94:
	/* 0xd94: cmp    rsi,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_d98:
	/* 0xd98: setle  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_LE);
x86_l_d9b:
	/* 0xd9b: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_d9e:
	/* 0xd9e: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_da1:
	/* 0xda1: jb     ec2 <filter_64ty_range+0x1cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_ec2;
	}
x86_l_da7:
	/* 0xda7: cmp    QWORD PTR [rdi+0x20],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_dab:
	/* 0xdab: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_daf:
	/* 0xdaf: cmp    rsi,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_db3:
	/* 0xdb3: setle  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_LE);
x86_l_db7:
	/* 0xdb7: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_dba:
	/* 0xdba: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_dbd:
	/* 0xdbd: cmp    eax,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 41ULL);
x86_l_dc0:
	/* 0xdc0: jb     ec2 <filter_64ty_range+0x1cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_ec2;
	}
x86_l_dc6:
	/* 0xdc6: cmp    QWORD PTR [rdi+0x30],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_dca:
	/* 0xdca: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_dce:
	/* 0xdce: cmp    rsi,QWORD PTR [rdi+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_dd2:
	/* 0xdd2: setle  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_LE);
x86_l_dd6:
	/* 0xdd6: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_dd9:
	/* 0xdd9: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_ddc:
	/* 0xddc: cmp    eax,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 57ULL);
x86_l_ddf:
	/* 0xddf: jb     ec2 <filter_64ty_range+0x1cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_ec2;
	}
x86_l_de5:
	/* 0xde5: cmp    QWORD PTR [rdi+0x40],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_de9:
	/* 0xde9: setle  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_LE);
x86_l_dec:
	/* 0xdec: cmp    rsi,QWORD PTR [rdi+0x48] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 72ULL);
x86_l_df0:
	/* 0xdf0: setle  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_LE);
x86_l_df4:
	/* 0xdf4: jmp    e76 <filter_64ty_range+0x180> */
	goto x86_l_e76;
x86_l_df9:
	/* 0xdf9: mov    rsi,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dfc:
	/* 0xdfc: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_dff:
	/* 0xdff: jne    e13 <filter_64ty_range+0x11d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_e13;
	}
x86_l_e01:
	/* 0xe01: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e06:
	/* 0xe06: cmp    QWORD PTR [rdi+0x10],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e0a:
	/* 0xe0a: ja     e7e <filter_64ty_range+0x188> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_e7e;
	}
x86_l_e0c:
	/* 0xe0c: cmp    rsi,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_e10:
	/* 0xe10: ja     e7e <filter_64ty_range+0x188> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_e7e;
	}
x86_l_e12:
	/* 0xe12: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_e13:
	/* 0xe13: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e16:
	/* 0xe16: cmp    QWORD PTR [rdi+0x10],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e1a:
	/* 0xe1a: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_e1e:
	/* 0xe1e: cmp    rsi,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_e22:
	/* 0xe22: setbe  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_BE);
x86_l_e25:
	/* 0xe25: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_e28:
	/* 0xe28: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_e2b:
	/* 0xe2b: jb     ec2 <filter_64ty_range+0x1cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_ec2;
	}
x86_l_e31:
	/* 0xe31: cmp    QWORD PTR [rdi+0x20],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e35:
	/* 0xe35: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_e39:
	/* 0xe39: cmp    rsi,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_e3d:
	/* 0xe3d: setbe  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_BE);
x86_l_e41:
	/* 0xe41: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_e44:
	/* 0xe44: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_e47:
	/* 0xe47: cmp    eax,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 41ULL);
x86_l_e4a:
	/* 0xe4a: jb     ec2 <filter_64ty_range+0x1cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_ec2;
	}
x86_l_e4c:
	/* 0xe4c: cmp    QWORD PTR [rdi+0x30],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e50:
	/* 0xe50: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_e54:
	/* 0xe54: cmp    rsi,QWORD PTR [rdi+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_e58:
	/* 0xe58: setbe  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_BE);
x86_l_e5c:
	/* 0xe5c: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_e5f:
	/* 0xe5f: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_e62:
	/* 0xe62: cmp    eax,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 57ULL);
x86_l_e65:
	/* 0xe65: jb     ec2 <filter_64ty_range+0x1cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_ec2;
	}
x86_l_e67:
	/* 0xe67: cmp    QWORD PTR [rdi+0x40],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_e6b:
	/* 0xe6b: setbe  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_BE);
x86_l_e6e:
	/* 0xe6e: cmp    rsi,QWORD PTR [rdi+0x48] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 72ULL);
x86_l_e72:
	/* 0xe72: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_e76:
	/* 0xe76: and    sil,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_e79:
	/* 0xe79: or     dl,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_8, X86_ALU_OR);
x86_l_e7c:
	/* 0xe7c: jmp    ec2 <filter_64ty_range+0x1cc> */
	goto x86_l_ec2;
x86_l_e7e:
	/* 0xe7e: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e81:
	/* 0xe81: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_e84:
	/* 0xe84: jb     ec0 <filter_64ty_range+0x1ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_ec0;
	}
x86_l_e86:
	/* 0xe86: cmp    QWORD PTR [rdi+0x20],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e8a:
	/* 0xe8a: ja     e92 <filter_64ty_range+0x19c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_e92;
	}
x86_l_e8c:
	/* 0xe8c: cmp    rsi,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_e90:
	/* 0xe90: jbe    e12 <filter_64ty_range+0x11c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_e12;
	}
x86_l_e92:
	/* 0xe92: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_e95:
	/* 0xe95: jb     ec0 <filter_64ty_range+0x1ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_ec0;
	}
x86_l_e97:
	/* 0xe97: cmp    QWORD PTR [rdi+0x30],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e9b:
	/* 0xe9b: ja     ea7 <filter_64ty_range+0x1b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_ea7;
	}
x86_l_e9d:
	/* 0xe9d: cmp    rsi,QWORD PTR [rdi+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_ea1:
	/* 0xea1: jbe    e12 <filter_64ty_range+0x11c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_e12;
	}
x86_l_ea7:
	/* 0xea7: cmp    edx,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 57ULL);
x86_l_eaa:
	/* 0xeaa: jb     ec0 <filter_64ty_range+0x1ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_ec0;
	}
x86_l_eac:
	/* 0xeac: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_eae:
	/* 0xeae: cmp    QWORD PTR [rdi+0x40],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_eb2:
	/* 0xeb2: ja     ec2 <filter_64ty_range+0x1cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_ec2;
	}
x86_l_eb4:
	/* 0xeb4: cmp    rsi,QWORD PTR [rdi+0x48] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 72ULL);
x86_l_eb8:
	/* 0xeb8: jbe    e12 <filter_64ty_range+0x11c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_e12;
	}
x86_l_ebe:
	/* 0xebe: jmp    ec2 <filter_64ty_range+0x1cc> */
	goto x86_l_ec2;
x86_l_ec0:
	/* 0xec0: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ec2:
	/* 0xec2: cmp    ecx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 32ULL);
x86_l_ec5:
	/* 0xec5: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_ec8:
	/* 0xec8: xor    dl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_ecb:
	/* 0xecb: and    dl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_ecd:
	/* 0xecd: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_ed0:
	/* 0xed0: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_ed1:
	/* 0xed1: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_ed3:
	/* 0xed3: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_ed4:
	/* 0xed4: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_ed8:
	/* 0xed8: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_edb:
	/* 0xedb: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_ede:
	/* 0xede: movzx  eax,BYTE PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_ee2:
	/* 0xee2: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_ee6:
	/* 0xee6: mov    rdi,QWORD PTR [rip+0x530] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_eed:
	/* 0xeed: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_ef2:
	/* 0xef2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ef7:
	/* 0xef7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ef9:
	/* 0xef9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_efc:
	/* 0xefc: je     f2a <filter_64ty_map+0x59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f2a;
	}
x86_l_efe:
	/* 0xefe: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_f01:
	/* 0xf01: mov    rax,QWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f04:
	/* 0xf04: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f09:
	/* 0xf09: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f0e:
	/* 0xf0e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f13:
	/* 0xf13: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f15:
	/* 0xf15: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_f18:
	/* 0xf18: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_f1b:
	/* 0xf1b: je     f34 <filter_64ty_map+0x63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f34;
	}
x86_l_f1d:
	/* 0xf1d: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_f20:
	/* 0xf20: jne    f3c <filter_64ty_map+0x6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_f3c;
	}
x86_l_f22:
	/* 0xf22: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f25:
	/* 0xf25: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_f28:
	/* 0xf28: jmp    f3e <filter_64ty_map+0x6d> */
	goto x86_l_f3e;
x86_l_f2a:
	/* 0xf2a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f2c:
	/* 0xf2c: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_f30:
	/* 0xf30: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_f31:
	/* 0xf31: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_f33:
	/* 0xf33: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_f34:
	/* 0xf34: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f37:
	/* 0xf37: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_f3a:
	/* 0xf3a: jmp    f3e <filter_64ty_map+0x6d> */
	goto x86_l_f3e;
x86_l_f3c:
	/* 0xf3c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f3e:
	/* 0xf3e: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_f41:
	/* 0xf41: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_f45:
	/* 0xf45: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_f46:
	/* 0xf46: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_f48:
	/* 0xf48: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_f49:
	/* 0xf49: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_f4b:
	/* 0xf4b: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_f4d:
	/* 0xf4d: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_f4e:
	/* 0xf4e: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_f52:
	/* 0xf52: mov    ebx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDX, X86_WIDTH_32);
x86_l_f54:
	/* 0xf54: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_f57:
	/* 0xf57: mov    DWORD PTR [rsp+0xc],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_f5b:
	/* 0xf5b: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_f63:
	/* 0xf63: mov    rdi,QWORD PTR [rip+0x1e90] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_f6a:
	/* 0xf6a: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_f6f:
	/* 0xf6f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f74:
	/* 0xf74: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f76:
	/* 0xf76: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_f79:
	/* 0xf79: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f7b:
	/* 0xf7b: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_f7d:
	/* 0xf7d: je     1087 <filter_char_buf_postfix+0x13e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1087;
	}
x86_l_f83:
	/* 0xf83: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_f86:
	/* 0xf86: je     1087 <filter_char_buf_postfix+0x13e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1087;
	}
x86_l_f8c:
	/* 0xf8c: mov    rdi,QWORD PTR [rip+0x1e90] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_f93:
	/* 0xf93: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f98:
	/* 0xf98: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f9d:
	/* 0xf9d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f9f:
	/* 0xf9f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fa2:
	/* 0xfa2: je     1085 <filter_char_buf_postfix+0x13c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1085;
	}
x86_l_fa8:
	/* 0xfa8: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_fab:
	/* 0xfab: cmp    ebx,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 127ULL);
x86_l_fae:
	/* 0xfae: mov    eax,0x7f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 127ULL);
x86_l_fb3:
	/* 0xfb3: cmovb  eax,ebx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RBX, X86_WIDTH_32, X86_CC_B);
x86_l_fb6:
	/* 0xfb6: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_fb9:
	/* 0xfb9: mov    DWORD PTR [rsi],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fbb:
	/* 0xfbb: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_fbd:
	/* 0xfbd: lea    ecx,[rbx-0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_fc0:
	/* 0xfc0: mov    rdx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_fc3:
	/* 0xfc3: add    rdx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 7ULL);
x86_l_fc7:
	/* 0xfc7: lea    edi,[rbx-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_fca:
	/* 0xfca: lea    r8d,[rbx-0x2] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_fce:
	/* 0xfce: dec    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_fd0:
	/* 0xfd0: mov    r9,0xfffffffffffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 18446744073709551613ULL);
x86_l_fd7:
	/* 0xfd7: lea    r10d,[rbx+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_fdb:
	/* 0xfdb: add    r10d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_fdf:
	/* 0xfdf: and    r10d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_fe6:
	/* 0xfe6: movzx  r10d,BYTE PTR [r14+r10*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R10, 0, X86_WIDTH_8), 0ULL);
x86_l_feb:
	/* 0xfeb: mov    BYTE PTR [rdx-0x3],r10b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_R10, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_fef:
	/* 0xfef: lea    r10,[rax+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_ff3:
	/* 0xff3: cmp    r10,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_ff7:
	/* 0xff7: je     106e <filter_char_buf_postfix+0x125> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_106e;
	}
x86_l_ff9:
	/* 0xff9: lea    r11d,[r8+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_ffd:
	/* 0xffd: add    r11d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_1001:
	/* 0x1001: and    r11d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1008:
	/* 0x1008: movzx  r11d,BYTE PTR [r14+r11*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R11, 0, X86_WIDTH_8), 0ULL);
x86_l_100d:
	/* 0x100d: mov    BYTE PTR [rdx-0x2],r11b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_R11, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_1011:
	/* 0x1011: cmp    r10,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1015:
	/* 0x1015: je     106e <filter_char_buf_postfix+0x125> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_106e;
	}
x86_l_1017:
	/* 0x1017: lea    r10d,[rdi+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_101b:
	/* 0x101b: add    r10d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_101f:
	/* 0x101f: and    r10d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1026:
	/* 0x1026: movzx  r10d,BYTE PTR [r14+r10*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R10, 0, X86_WIDTH_8), 0ULL);
x86_l_102b:
	/* 0x102b: mov    BYTE PTR [rdx-0x1],r10b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_R10, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_102f:
	/* 0x102f: mov    r10,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_RAX, X86_WIDTH_64);
x86_l_1032:
	/* 0x1032: add    r10,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R9, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1035:
	/* 0x1035: je     106e <filter_char_buf_postfix+0x125> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_106e;
	}
x86_l_1037:
	/* 0x1037: cmp    r9,0xffffffffffffff81 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_64, 18446744073709551489ULL);
x86_l_103b:
	/* 0x103b: je     106e <filter_char_buf_postfix+0x125> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_106e;
	}
x86_l_103d:
	/* 0x103d: lea    r10d,[rcx+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_1041:
	/* 0x1041: add    r10d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_1045:
	/* 0x1045: and    r10d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_104c:
	/* 0x104c: movzx  r10d,BYTE PTR [r14+r10*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R10, 0, X86_WIDTH_8), 0ULL);
x86_l_1051:
	/* 0x1051: mov    BYTE PTR [rdx],r10b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_R10, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1054:
	/* 0x1054: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1058:
	/* 0x1058: lea    r10,[rax+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_105c:
	/* 0x105c: add    r10,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_1060:
	/* 0x1060: add    r9,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_1064:
	/* 0x1064: cmp    r10,0xfffffffffffffffd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_64, 18446744073709551613ULL);
x86_l_1068:
	/* 0x1068: jne    fd7 <filter_char_buf_postfix+0x8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_fd7;
	}
x86_l_106e:
	/* 0x106e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1073:
	/* 0x1073: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1076:
	/* 0x1076: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1078:
	/* 0x1078: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_107b:
	/* 0x107b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_107d:
	/* 0x107d: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_1080:
	/* 0x1080: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_1083:
	/* 0x1083: jmp    1087 <filter_char_buf_postfix+0x13e> */
	goto x86_l_1087;
x86_l_1085:
	/* 0x1085: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1087:
	/* 0x1087: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_108b:
	/* 0x108b: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_108c:
	/* 0x108c: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_108e:
	/* 0x108e: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_1090:
	/* 0x1090: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1091:
	/* 0x1091: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
	return 4242ULL;
}

static __noinline __u64 tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_filter_arg_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 4242ULL: goto x86_l_1092;
	case 4244ULL: goto x86_l_1094;
	case 4246ULL: goto x86_l_1096;
	case 4247ULL: goto x86_l_1097;
	case 4248ULL: goto x86_l_1098;
	case 4250ULL: goto x86_l_109a;
	case 4253ULL: goto x86_l_109d;
	case 4257ULL: goto x86_l_10a1;
	case 4264ULL: goto x86_l_10a8;
	case 4271ULL: goto x86_l_10af;
	case 4276ULL: goto x86_l_10b4;
	case 4281ULL: goto x86_l_10b9;
	case 4283ULL: goto x86_l_10bb;
	case 4286ULL: goto x86_l_10be;
	case 4288ULL: goto x86_l_10c0;
	case 4290ULL: goto x86_l_10c2;
	case 4292ULL: goto x86_l_10c4;
	case 4295ULL: goto x86_l_10c7;
	case 4297ULL: goto x86_l_10c9;
	case 4304ULL: goto x86_l_10d0;
	case 4307ULL: goto x86_l_10d3;
	case 4312ULL: goto x86_l_10d8;
	case 4314ULL: goto x86_l_10da;
	case 4317ULL: goto x86_l_10dd;
	case 4319ULL: goto x86_l_10df;
	case 4325ULL: goto x86_l_10e5;
	case 4330ULL: goto x86_l_10ea;
	case 4333ULL: goto x86_l_10ed;
	case 4340ULL: goto x86_l_10f4;
	case 4342ULL: goto x86_l_10f6;
	case 4345ULL: goto x86_l_10f9;
	case 4349ULL: goto x86_l_10fd;
	case 4352ULL: goto x86_l_1100;
	case 4357ULL: goto x86_l_1105;
	case 4360ULL: goto x86_l_1108;
	case 4362ULL: goto x86_l_110a;
	case 4367ULL: goto x86_l_110f;
	case 4370ULL: goto x86_l_1112;
	case 4373ULL: goto x86_l_1115;
	case 4375ULL: goto x86_l_1117;
	case 4378ULL: goto x86_l_111a;
	case 4380ULL: goto x86_l_111c;
	case 4383ULL: goto x86_l_111f;
	case 4386ULL: goto x86_l_1122;
	case 4388ULL: goto x86_l_1124;
	case 4390ULL: goto x86_l_1126;
	case 4394ULL: goto x86_l_112a;
	case 4395ULL: goto x86_l_112b;
	case 4397ULL: goto x86_l_112d;
	case 4399ULL: goto x86_l_112f;
	case 4400ULL: goto x86_l_1130;
	case 4401ULL: goto x86_l_1131;
	case 4402ULL: goto x86_l_1132;
	case 4404ULL: goto x86_l_1134;
	case 4406ULL: goto x86_l_1136;
	case 4408ULL: goto x86_l_1138;
	case 4410ULL: goto x86_l_113a;
	case 4411ULL: goto x86_l_113b;
	case 4415ULL: goto x86_l_113f;
	case 4423ULL: goto x86_l_1147;
	case 4429ULL: goto x86_l_114d;
	case 4435ULL: goto x86_l_1153;
	case 4438ULL: goto x86_l_1156;
	case 4443ULL: goto x86_l_115b;
	case 4445ULL: goto x86_l_115d;
	case 4448ULL: goto x86_l_1160;
	case 4454ULL: goto x86_l_1166;
	case 4457ULL: goto x86_l_1169;
	case 4460ULL: goto x86_l_116c;
	case 4463ULL: goto x86_l_116f;
	case 4465ULL: goto x86_l_1171;
	case 4468ULL: goto x86_l_1174;
	case 4470ULL: goto x86_l_1176;
	case 4472ULL: goto x86_l_1178;
	case 4475ULL: goto x86_l_117b;
	case 4477ULL: goto x86_l_117d;
	case 4479ULL: goto x86_l_117f;
	case 4482ULL: goto x86_l_1182;
	case 4484ULL: goto x86_l_1184;
	case 4486ULL: goto x86_l_1186;
	case 4488ULL: goto x86_l_1188;
	case 4491ULL: goto x86_l_118b;
	case 4495ULL: goto x86_l_118f;
	case 4499ULL: goto x86_l_1193;
	case 4501ULL: goto x86_l_1195;
	case 4504ULL: goto x86_l_1198;
	case 4507ULL: goto x86_l_119b;
	case 4514ULL: goto x86_l_11a2;
	case 4518ULL: goto x86_l_11a6;
	case 4521ULL: goto x86_l_11a9;
	case 4526ULL: goto x86_l_11ae;
	case 4532ULL: goto x86_l_11b4;
	case 4537ULL: goto x86_l_11b9;
	case 4539ULL: goto x86_l_11bb;
	case 4545ULL: goto x86_l_11c1;
	case 4550ULL: goto x86_l_11c6;
	case 4552ULL: goto x86_l_11c8;
	case 4558ULL: goto x86_l_11ce;
	case 4563ULL: goto x86_l_11d3;
	case 4565ULL: goto x86_l_11d5;
	case 4568ULL: goto x86_l_11d8;
	case 4573ULL: goto x86_l_11dd;
	case 4577ULL: goto x86_l_11e1;
	case 4581ULL: goto x86_l_11e5;
	case 4588ULL: goto x86_l_11ec;
	case 4595ULL: goto x86_l_11f3;
	case 4601ULL: goto x86_l_11f9;
	case 4604ULL: goto x86_l_11fc;
	case 4606ULL: goto x86_l_11fe;
	case 4608ULL: goto x86_l_1200;
	case 4610ULL: goto x86_l_1202;
	case 4613ULL: goto x86_l_1205;
	case 4615ULL: goto x86_l_1207;
	case 4621ULL: goto x86_l_120d;
	case 4623ULL: goto x86_l_120f;
	case 4626ULL: goto x86_l_1212;
	case 4628ULL: goto x86_l_1214;
	case 4631ULL: goto x86_l_1217;
	case 4633ULL: goto x86_l_1219;
	case 4639ULL: goto x86_l_121f;
	case 4641ULL: goto x86_l_1221;
	case 4647ULL: goto x86_l_1227;
	case 4649ULL: goto x86_l_1229;
	case 4655ULL: goto x86_l_122f;
	case 4657ULL: goto x86_l_1231;
	case 4663ULL: goto x86_l_1237;
	case 4666ULL: goto x86_l_123a;
	case 4669ULL: goto x86_l_123d;
	case 4674ULL: goto x86_l_1242;
	case 4678ULL: goto x86_l_1246;
	case 4684ULL: goto x86_l_124c;
	case 4689ULL: goto x86_l_1251;
	case 4691ULL: goto x86_l_1253;
	case 4698ULL: goto x86_l_125a;
	case 4703ULL: goto x86_l_125f;
	case 4708ULL: goto x86_l_1264;
	case 4711ULL: goto x86_l_1267;
	case 4713ULL: goto x86_l_1269;
	case 4716ULL: goto x86_l_126c;
	case 4723ULL: goto x86_l_1273;
	case 4728ULL: goto x86_l_1278;
	case 4731ULL: goto x86_l_127b;
	case 4733ULL: goto x86_l_127d;
	case 4736ULL: goto x86_l_1280;
	case 4738ULL: goto x86_l_1282;
	case 4743ULL: goto x86_l_1287;
	case 4746ULL: goto x86_l_128a;
	case 4752ULL: goto x86_l_1290;
	case 4755ULL: goto x86_l_1293;
	case 4761ULL: goto x86_l_1299;
	case 4766ULL: goto x86_l_129e;
	case 4770ULL: goto x86_l_12a2;
	case 4772ULL: goto x86_l_12a4;
	case 4777ULL: goto x86_l_12a9;
	case 4780ULL: goto x86_l_12ac;
	case 4784ULL: goto x86_l_12b0;
	case 4787ULL: goto x86_l_12b3;
	case 4792ULL: goto x86_l_12b8;
	case 4797ULL: goto x86_l_12bd;
	case 4799ULL: goto x86_l_12bf;
	case 4801ULL: goto x86_l_12c1;
	case 4804ULL: goto x86_l_12c4;
	case 4806ULL: goto x86_l_12c6;
	case 4811ULL: goto x86_l_12cb;
	case 4815ULL: goto x86_l_12cf;
	case 4818ULL: goto x86_l_12d2;
	case 4825ULL: goto x86_l_12d9;
	case 4830ULL: goto x86_l_12de;
	case 4835ULL: goto x86_l_12e3;
	case 4837ULL: goto x86_l_12e5;
	case 4842ULL: goto x86_l_12ea;
	case 4845ULL: goto x86_l_12ed;
	case 4849ULL: goto x86_l_12f1;
	case 4852ULL: goto x86_l_12f4;
	case 4857ULL: goto x86_l_12f9;
	case 4862ULL: goto x86_l_12fe;
	case 4864ULL: goto x86_l_1300;
	case 4866ULL: goto x86_l_1302;
	case 4869ULL: goto x86_l_1305;
	case 4871ULL: goto x86_l_1307;
	case 4876ULL: goto x86_l_130c;
	case 4880ULL: goto x86_l_1310;
	case 4884ULL: goto x86_l_1314;
	case 4891ULL: goto x86_l_131b;
	case 4896ULL: goto x86_l_1320;
	case 4901ULL: goto x86_l_1325;
	case 4904ULL: goto x86_l_1328;
	case 4906ULL: goto x86_l_132a;
	case 4911ULL: goto x86_l_132f;
	case 4915ULL: goto x86_l_1333;
	case 4917ULL: goto x86_l_1335;
	case 4921ULL: goto x86_l_1339;
	case 4923ULL: goto x86_l_133b;
	case 4927ULL: goto x86_l_133f;
	case 4933ULL: goto x86_l_1345;
	case 4937ULL: goto x86_l_1349;
	case 4943ULL: goto x86_l_134f;
	case 4947ULL: goto x86_l_1353;
	case 4953ULL: goto x86_l_1359;
	case 4960ULL: goto x86_l_1360;
	case 4965ULL: goto x86_l_1365;
	case 4970ULL: goto x86_l_136a;
	case 4975ULL: goto x86_l_136f;
	case 4979ULL: goto x86_l_1373;
	case 4981ULL: goto x86_l_1375;
	case 4985ULL: goto x86_l_1379;
	case 4991ULL: goto x86_l_137f;
	case 4995ULL: goto x86_l_1383;
	case 5001ULL: goto x86_l_1389;
	case 5005ULL: goto x86_l_138d;
	case 5011ULL: goto x86_l_1393;
	case 5018ULL: goto x86_l_139a;
	case 5023ULL: goto x86_l_139f;
	case 5028ULL: goto x86_l_13a4;
	case 5033ULL: goto x86_l_13a9;
	case 5037ULL: goto x86_l_13ad;
	case 5043ULL: goto x86_l_13b3;
	case 5047ULL: goto x86_l_13b7;
	case 5053ULL: goto x86_l_13bd;
	case 5057ULL: goto x86_l_13c1;
	case 5063ULL: goto x86_l_13c7;
	case 5070ULL: goto x86_l_13ce;
	case 5075ULL: goto x86_l_13d3;
	case 5080ULL: goto x86_l_13d8;
	case 5085ULL: goto x86_l_13dd;
	case 5088ULL: goto x86_l_13e0;
	case 5090ULL: goto x86_l_13e2;
	case 5094ULL: goto x86_l_13e6;
	case 5100ULL: goto x86_l_13ec;
	case 5107ULL: goto x86_l_13f3;
	case 5112ULL: goto x86_l_13f8;
	case 5117ULL: goto x86_l_13fd;
	case 5122ULL: goto x86_l_1402;
	case 5129ULL: goto x86_l_1409;
	case 5134ULL: goto x86_l_140e;
	case 5139ULL: goto x86_l_1413;
	case 5141ULL: goto x86_l_1415;
	case 5148ULL: goto x86_l_141c;
	case 5153ULL: goto x86_l_1421;
	case 5158ULL: goto x86_l_1426;
	case 5160ULL: goto x86_l_1428;
	case 5167ULL: goto x86_l_142f;
	case 5172ULL: goto x86_l_1434;
	case 5177ULL: goto x86_l_1439;
	case 5179ULL: goto x86_l_143b;
	case 5186ULL: goto x86_l_1442;
	case 5191ULL: goto x86_l_1447;
	case 5196ULL: goto x86_l_144c;
	case 5198ULL: goto x86_l_144e;
	case 5205ULL: goto x86_l_1455;
	case 5210ULL: goto x86_l_145a;
	case 5215ULL: goto x86_l_145f;
	case 5217ULL: goto x86_l_1461;
	case 5224ULL: goto x86_l_1468;
	case 5229ULL: goto x86_l_146d;
	case 5234ULL: goto x86_l_1472;
	case 5236ULL: goto x86_l_1474;
	case 5243ULL: goto x86_l_147b;
	case 5248ULL: goto x86_l_1480;
	case 5253ULL: goto x86_l_1485;
	case 5258ULL: goto x86_l_148a;
	case 5260ULL: goto x86_l_148c;
	case 5263ULL: goto x86_l_148f;
	case 5265ULL: goto x86_l_1491;
	case 5268ULL: goto x86_l_1494;
	case 5273ULL: goto x86_l_1499;
	case 5278ULL: goto x86_l_149e;
	case 5280ULL: goto x86_l_14a0;
	case 5283ULL: goto x86_l_14a3;
	case 5285ULL: goto x86_l_14a5;
	case 5288ULL: goto x86_l_14a8;
	case 5291ULL: goto x86_l_14ab;
	case 5293ULL: goto x86_l_14ad;
	case 5295ULL: goto x86_l_14af;
	case 5299ULL: goto x86_l_14b3;
	case 5300ULL: goto x86_l_14b4;
	case 5302ULL: goto x86_l_14b6;
	case 5304ULL: goto x86_l_14b8;
	case 5306ULL: goto x86_l_14ba;
	case 5308ULL: goto x86_l_14bc;
	case 5309ULL: goto x86_l_14bd;
	case 5310ULL: goto x86_l_14be;
	case 5311ULL: goto x86_l_14bf;
	case 5313ULL: goto x86_l_14c1;
	case 5315ULL: goto x86_l_14c3;
	case 5317ULL: goto x86_l_14c5;
	case 5319ULL: goto x86_l_14c7;
	case 5320ULL: goto x86_l_14c8;
	case 5321ULL: goto x86_l_14c9;
	case 5324ULL: goto x86_l_14cc;
	case 5327ULL: goto x86_l_14cf;
	case 5329ULL: goto x86_l_14d1;
	case 5331ULL: goto x86_l_14d3;
	case 5337ULL: goto x86_l_14d9;
	case 5339ULL: goto x86_l_14db;
	case 5345ULL: goto x86_l_14e1;
	case 5350ULL: goto x86_l_14e6;
	case 5352ULL: goto x86_l_14e8;
	case 5355ULL: goto x86_l_14eb;
	case 5360ULL: goto x86_l_14f0;
	case 5364ULL: goto x86_l_14f4;
	case 5369ULL: goto x86_l_14f9;
	case 5376ULL: goto x86_l_1500;
	case 5379ULL: goto x86_l_1503;
	case 5381ULL: goto x86_l_1505;
	case 5384ULL: goto x86_l_1508;
	case 5390ULL: goto x86_l_150e;
	case 5393ULL: goto x86_l_1511;
	case 5395ULL: goto x86_l_1513;
	case 5397ULL: goto x86_l_1515;
	case 5400ULL: goto x86_l_1518;
	case 5403ULL: goto x86_l_151b;
	case 5406ULL: goto x86_l_151e;
	case 5408ULL: goto x86_l_1520;
	case 5410ULL: goto x86_l_1522;
	case 5414ULL: goto x86_l_1526;
	case 5417ULL: goto x86_l_1529;
	case 5419ULL: goto x86_l_152b;
	case 5423ULL: goto x86_l_152f;
	case 5425ULL: goto x86_l_1531;
	case 5427ULL: goto x86_l_1533;
	case 5432ULL: goto x86_l_1538;
	case 5436ULL: goto x86_l_153c;
	case 5439ULL: goto x86_l_153f;
	case 5443ULL: goto x86_l_1543;
	case 5447ULL: goto x86_l_1547;
	case 5451ULL: goto x86_l_154b;
	case 5455ULL: goto x86_l_154f;
	case 5458ULL: goto x86_l_1552;
	case 5462ULL: goto x86_l_1556;
	case 5466ULL: goto x86_l_155a;
	case 5470ULL: goto x86_l_155e;
	case 5474ULL: goto x86_l_1562;
	case 5476ULL: goto x86_l_1564;
	case 5479ULL: goto x86_l_1567;
	case 5482ULL: goto x86_l_156a;
	case 5484ULL: goto x86_l_156c;
	case 5486ULL: goto x86_l_156e;
	case 5488ULL: goto x86_l_1570;
	case 5494ULL: goto x86_l_1576;
	case 5499ULL: goto x86_l_157b;
	case 5503ULL: goto x86_l_157f;
	case 5509ULL: goto x86_l_1585;
	case 5513ULL: goto x86_l_1589;
	case 5516ULL: goto x86_l_158c;
	case 5520ULL: goto x86_l_1590;
	case 5526ULL: goto x86_l_1596;
	case 5531ULL: goto x86_l_159b;
	case 5533ULL: goto x86_l_159d;
	case 5539ULL: goto x86_l_15a3;
	case 5544ULL: goto x86_l_15a8;
	case 5546ULL: goto x86_l_15aa;
	case 5549ULL: goto x86_l_15ad;
	case 5554ULL: goto x86_l_15b2;
	case 5558ULL: goto x86_l_15b6;
	case 5563ULL: goto x86_l_15bb;
	case 5570ULL: goto x86_l_15c2;
	case 5573ULL: goto x86_l_15c5;
	case 5575ULL: goto x86_l_15c7;
	case 5578ULL: goto x86_l_15ca;
	case 5584ULL: goto x86_l_15d0;
	case 5587ULL: goto x86_l_15d3;
	case 5589ULL: goto x86_l_15d5;
	case 5591ULL: goto x86_l_15d7;
	case 5594ULL: goto x86_l_15da;
	case 5597ULL: goto x86_l_15dd;
	case 5600ULL: goto x86_l_15e0;
	case 5602ULL: goto x86_l_15e2;
	case 5604ULL: goto x86_l_15e4;
	case 5608ULL: goto x86_l_15e8;
	case 5611ULL: goto x86_l_15eb;
	case 5613ULL: goto x86_l_15ed;
	case 5617ULL: goto x86_l_15f1;
	case 5620ULL: goto x86_l_15f4;
	case 5622ULL: goto x86_l_15f6;
	case 5626ULL: goto x86_l_15fa;
	case 5628ULL: goto x86_l_15fc;
	case 5632ULL: goto x86_l_1600;
	case 5636ULL: goto x86_l_1604;
	case 5639ULL: goto x86_l_1607;
	case 5641ULL: goto x86_l_1609;
	case 5643ULL: goto x86_l_160b;
	case 5645ULL: goto x86_l_160d;
	case 5651ULL: goto x86_l_1613;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1092:
	/* 0x1092: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_1094:
	/* 0x1094: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_1096:
	/* 0x1096: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_1097:
	/* 0x1097: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_1098:
	/* 0x1098: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_109a:
	/* 0x109a: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_109d:
	/* 0x109d: mov    DWORD PTR [rsp+0x4],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_10a1:
	/* 0x10a1: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10a8:
	/* 0x10a8: mov    rdi,QWORD PTR [rip+0x1df0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_10af:
	/* 0x10af: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_10b4:
	/* 0x10b4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10b9:
	/* 0x10b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10bb:
	/* 0x10bb: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_10be:
	/* 0x10be: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10c0:
	/* 0x10c0: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_10c2:
	/* 0x10c2: je     1126 <filter_char_buf_prefix+0x95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1126;
	}
x86_l_10c4:
	/* 0x10c4: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_10c7:
	/* 0x10c7: je     1126 <filter_char_buf_prefix+0x95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1126;
	}
x86_l_10c9:
	/* 0x10c9: mov    rdi,QWORD PTR [rip+0x1df0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_10d0:
	/* 0x10d0: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_10d3:
	/* 0x10d3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10d8:
	/* 0x10d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10da:
	/* 0x10da: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10dd:
	/* 0x10dd: je     1124 <filter_char_buf_prefix+0x93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1124;
	}
x86_l_10df:
	/* 0x10df: cmp    ebp,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 255ULL);
x86_l_10e5:
	/* 0x10e5: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_10ea:
	/* 0x10ea: cmovb  esi,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RBP, X86_WIDTH_32, X86_CC_B);
x86_l_10ed:
	/* 0x10ed: lea    ecx,[rsi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_10f4:
	/* 0x10f4: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10f6:
	/* 0x10f6: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_10f9:
	/* 0x10f9: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_10fd:
	/* 0x10fd: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1100:
	/* 0x1100: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1105:
	/* 0x1105: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1108:
	/* 0x1108: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_110a:
	/* 0x110a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_110f:
	/* 0x110f: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_1112:
	/* 0x1112: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_1115:
	/* 0x1115: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1117:
	/* 0x1117: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_111a:
	/* 0x111a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_111c:
	/* 0x111c: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_111f:
	/* 0x111f: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_1122:
	/* 0x1122: jmp    1126 <filter_char_buf_prefix+0x95> */
	goto x86_l_1126;
x86_l_1124:
	/* 0x1124: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1126:
	/* 0x1126: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_112a:
	/* 0x112a: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_112b:
	/* 0x112b: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_112d:
	/* 0x112d: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_112f:
	/* 0x112f: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1130:
	/* 0x1130: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1131:
	/* 0x1131: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1132:
	/* 0x1132: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_1134:
	/* 0x1134: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_1136:
	/* 0x1136: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_1138:
	/* 0x1138: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_113a:
	/* 0x113a: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_113b:
	/* 0x113b: sub    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 40ULL);
x86_l_113f:
	/* 0x113f: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_1147:
	/* 0x1147: cmp    edx,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4096ULL);
x86_l_114d:
	/* 0x114d: ja     14ad <filter_char_buf_equal+0x37c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_14ad;
	}
x86_l_1153:
	/* 0x1153: movzx  eax,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1156:
	/* 0x1156: cmp    eax,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_115b:
	/* 0x115b: ja     11ae <filter_char_buf_equal+0x7d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_11ae;
	}
x86_l_115d:
	/* 0x115d: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1160:
	/* 0x1160: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_1166:
	/* 0x1166: shr    ecx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_1169:
	/* 0x1169: and    ecx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_116c:
	/* 0x116c: lea    ecx,[rcx+rcx*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 1), 0ULL);
x86_l_116f:
	/* 0x116f: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1171:
	/* 0x1171: test   dx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_16);
x86_l_1174:
	/* 0x1174: je     117f <filter_char_buf_equal+0x4e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_117f;
	}
x86_l_1176:
	/* 0x1176: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1178:
	/* 0x1178: mov    r14d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_32);
x86_l_117b:
	/* 0x117b: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_117d:
	/* 0x117d: je     1198 <filter_char_buf_equal+0x67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1198;
	}
x86_l_117f:
	/* 0x117f: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1182:
	/* 0x1182: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1184:
	/* 0x1184: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1186:
	/* 0x1186: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_1188:
	/* 0x1188: add    eax,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_118b:
	/* 0x118b: movzx  r14d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_118f:
	/* 0x118f: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_1193:
	/* 0x1193: ja     11ec <filter_char_buf_equal+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_11ec;
	}
x86_l_1195:
	/* 0x1195: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_1198:
	/* 0x1198: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_119b:
	/* 0x119b: imul   r12d,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_R12, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_11a2:
	/* 0x11a2: shr    r12d,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_11a6:
	/* 0x11a6: dec    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_11a9:
	/* 0x11a9: jmp    1237 <filter_char_buf_equal+0x106> */
	goto x86_l_1237;
x86_l_11ae:
	/* 0x11ae: mov    r14d,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 256ULL);
x86_l_11b4:
	/* 0x11b4: cmp    eax,0x101 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 257ULL);
x86_l_11b9:
	/* 0x11b9: jb     11ec <filter_char_buf_equal+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_11ec;
	}
x86_l_11bb:
	/* 0x11bb: mov    r14d,0x200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 512ULL);
x86_l_11c1:
	/* 0x11c1: cmp    eax,0x201 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 513ULL);
x86_l_11c6:
	/* 0x11c6: jb     11ec <filter_char_buf_equal+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_11ec;
	}
x86_l_11c8:
	/* 0x11c8: mov    r14d,0x400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1024ULL);
x86_l_11ce:
	/* 0x11ce: cmp    eax,0x401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1025ULL);
x86_l_11d3:
	/* 0x11d3: jb     11ec <filter_char_buf_equal+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_11ec;
	}
x86_l_11d5:
	/* 0x11d5: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11d8:
	/* 0x11d8: cmp    eax,0x801 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2049ULL);
x86_l_11dd:
	/* 0x11dd: setae  r14b */
	X86_SIM_L_EXEC_SETCC(X86_R14, X86_CC_AE);
x86_l_11e1:
	/* 0x11e1: shl    r14d,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHL, 11ULL);
x86_l_11e5:
	/* 0x11e5: add    r14d,0x800 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 2048ULL);
x86_l_11ec:
	/* 0x11ec: lea    eax,[r14-0x100] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551360ULL);
x86_l_11f3:
	/* 0x11f3: rorx   eax,eax,0x8 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 8ULL);
x86_l_11f9:
	/* 0x11f9: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_11fc:
	/* 0x11fc: jg     120f <filter_char_buf_equal+0xde> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_120f;
	}
x86_l_11fe:
	/* 0x11fe: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1200:
	/* 0x1200: je     1229 <filter_char_buf_equal+0xf8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1229;
	}
x86_l_1202:
	/* 0x1202: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1205:
	/* 0x1205: jne    1221 <filter_char_buf_equal+0xf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1221;
	}
x86_l_1207:
	/* 0x1207: mov    r12d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 7ULL);
x86_l_120d:
	/* 0x120d: jmp    1237 <filter_char_buf_equal+0x106> */
	goto x86_l_1237;
x86_l_120f:
	/* 0x120f: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1212:
	/* 0x1212: je     1231 <filter_char_buf_equal+0x100> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1231;
	}
x86_l_1214:
	/* 0x1214: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_1217:
	/* 0x1217: jne    1221 <filter_char_buf_equal+0xf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1221;
	}
x86_l_1219:
	/* 0x1219: mov    r12d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 9ULL);
x86_l_121f:
	/* 0x121f: jmp    1237 <filter_char_buf_equal+0x106> */
	goto x86_l_1237;
x86_l_1221:
	/* 0x1221: mov    r12d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 10ULL);
x86_l_1227:
	/* 0x1227: jmp    1237 <filter_char_buf_equal+0x106> */
	goto x86_l_1237;
x86_l_1229:
	/* 0x1229: mov    r12d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 6ULL);
x86_l_122f:
	/* 0x122f: jmp    1237 <filter_char_buf_equal+0x106> */
	goto x86_l_1237;
x86_l_1231:
	/* 0x1231: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_1237:
	/* 0x1237: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_123a:
	/* 0x123a: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_123d:
	/* 0x123d: mov    r13d,DWORD PTR [rdi+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_1242:
	/* 0x1242: cmp    r13d,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4294967295ULL);
x86_l_1246:
	/* 0x1246: je     14ad <filter_char_buf_equal+0x37c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14ad;
	}
x86_l_124c:
	/* 0x124c: mov    QWORD PTR [rsp+0x20],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1251:
	/* 0x1251: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_1253:
	/* 0x1253: mov    rdi,QWORD PTR [rip+0x1a60] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_125a:
	/* 0x125a: lea    r15,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_125f:
	/* 0x125f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1264:
	/* 0x1264: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_1267:
	/* 0x1267: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1269:
	/* 0x1269: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_126c:
	/* 0x126c: mov    rdi,QWORD PTR [rip+0x1a60] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_1273:
	/* 0x1273: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1278:
	/* 0x1278: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_127b:
	/* 0x127b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_127d:
	/* 0x127d: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1280:
	/* 0x1280: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1282:
	/* 0x1282: mov    QWORD PTR [rsp+0x8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1287:
	/* 0x1287: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_128a:
	/* 0x128a: je     14af <filter_char_buf_equal+0x37e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14af;
	}
x86_l_1290:
	/* 0x1290: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_1293:
	/* 0x1293: je     14af <filter_char_buf_equal+0x37e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14af;
	}
x86_l_1299:
	/* 0x1299: mov    QWORD PTR [rsp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_129e:
	/* 0x129e: cmp    r12d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 5ULL);
x86_l_12a2:
	/* 0x12a2: jg     12e5 <filter_char_buf_equal+0x1b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_12e5;
	}
x86_l_12a4:
	/* 0x12a4: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12a9:
	/* 0x12a9: mov    BYTE PTR [rax],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12ac:
	/* 0x12ac: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_12b0:
	/* 0x12b0: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_12b3:
	/* 0x12b3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12b8:
	/* 0x12b8: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_12bd:
	/* 0x12bd: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_12bf:
	/* 0x12bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12c1:
	/* 0x12c1: sub    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_12c4:
	/* 0x12c4: jbe    132a <filter_char_buf_equal+0x1f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_132a;
	}
x86_l_12c6:
	/* 0x12c6: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12cb:
	/* 0x12cb: lea    rdi,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_12cf:
	/* 0x12cf: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_12d2:
	/* 0x12d2: and    r14d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_12d9:
	/* 0x12d9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12de:
	/* 0x12de: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_12e3:
	/* 0x12e3: jmp    1325 <filter_char_buf_equal+0x1f4> */
	goto x86_l_1325;
x86_l_12e5:
	/* 0x12e5: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12ea:
	/* 0x12ea: mov    WORD PTR [rax],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12ed:
	/* 0x12ed: lea    rdi,[rax+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_12f1:
	/* 0x12f1: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_12f4:
	/* 0x12f4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12f9:
	/* 0x12f9: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_12fe:
	/* 0x12fe: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_1300:
	/* 0x1300: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1302:
	/* 0x1302: sub    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1305:
	/* 0x1305: jbe    132a <filter_char_buf_equal+0x1f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_132a;
	}
x86_l_1307:
	/* 0x1307: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_130c:
	/* 0x130c: lea    rdi,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_1310:
	/* 0x1310: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1314:
	/* 0x1314: and    r14d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_131b:
	/* 0x131b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1320:
	/* 0x1320: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1325:
	/* 0x1325: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_1328:
	/* 0x1328: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_132a:
	/* 0x132a: mov    DWORD PTR [rsp+0x4],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_132f:
	/* 0x132f: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_1333:
	/* 0x1333: jle    136f <filter_char_buf_equal+0x23e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_136f;
	}
x86_l_1335:
	/* 0x1335: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_1339:
	/* 0x1339: jg     13a9 <filter_char_buf_equal+0x278> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_13a9;
	}
x86_l_133b:
	/* 0x133b: cmp    r12d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 5ULL);
x86_l_133f:
	/* 0x133f: je     1461 <filter_char_buf_equal+0x330> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1461;
	}
x86_l_1345:
	/* 0x1345: cmp    r12d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 6ULL);
x86_l_1349:
	/* 0x1349: je     1428 <filter_char_buf_equal+0x2f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1428;
	}
x86_l_134f:
	/* 0x134f: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_1353:
	/* 0x1353: jne    14ad <filter_char_buf_equal+0x37c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_14ad;
	}
x86_l_1359:
	/* 0x1359: mov    rdi,QWORD PTR [rip+0x1a60] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_7)));
x86_l_1360:
	/* 0x1360: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1365:
	/* 0x1365: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_136a:
	/* 0x136a: jmp    1485 <filter_char_buf_equal+0x354> */
	goto x86_l_1485;
x86_l_136f:
	/* 0x136f: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_1373:
	/* 0x1373: jle    13dd <filter_char_buf_equal+0x2ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_13dd;
	}
x86_l_1375:
	/* 0x1375: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_1379:
	/* 0x1379: je     144e <filter_char_buf_equal+0x31d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_144e;
	}
x86_l_137f:
	/* 0x137f: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_1383:
	/* 0x1383: je     1415 <filter_char_buf_equal+0x2e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1415;
	}
x86_l_1389:
	/* 0x1389: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_138d:
	/* 0x138d: jne    14ad <filter_char_buf_equal+0x37c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_14ad;
	}
x86_l_1393:
	/* 0x1393: mov    rdi,QWORD PTR [rip+0x1a60] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_139a:
	/* 0x139a: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_139f:
	/* 0x139f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13a4:
	/* 0x13a4: jmp    1485 <filter_char_buf_equal+0x354> */
	goto x86_l_1485;
x86_l_13a9:
	/* 0x13a9: cmp    r12d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 8ULL);
x86_l_13ad:
	/* 0x13ad: je     1474 <filter_char_buf_equal+0x343> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1474;
	}
x86_l_13b3:
	/* 0x13b3: cmp    r12d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 9ULL);
x86_l_13b7:
	/* 0x13b7: je     143b <filter_char_buf_equal+0x30a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_143b;
	}
x86_l_13bd:
	/* 0x13bd: cmp    r12d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 10ULL);
x86_l_13c1:
	/* 0x13c1: jne    14ad <filter_char_buf_equal+0x37c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_14ad;
	}
x86_l_13c7:
	/* 0x13c7: mov    rdi,QWORD PTR [rip+0x1a5c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_10)));
x86_l_13ce:
	/* 0x13ce: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_13d3:
	/* 0x13d3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13d8:
	/* 0x13d8: jmp    1485 <filter_char_buf_equal+0x354> */
	goto x86_l_1485;
x86_l_13dd:
	/* 0x13dd: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_13e0:
	/* 0x13e0: je     1402 <filter_char_buf_equal+0x2d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1402;
	}
x86_l_13e2:
	/* 0x13e2: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_13e6:
	/* 0x13e6: jne    14ad <filter_char_buf_equal+0x37c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_14ad;
	}
x86_l_13ec:
	/* 0x13ec: mov    rdi,QWORD PTR [rip+0x1a5c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_13f3:
	/* 0x13f3: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_13f8:
	/* 0x13f8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13fd:
	/* 0x13fd: jmp    1485 <filter_char_buf_equal+0x354> */
	goto x86_l_1485;
x86_l_1402:
	/* 0x1402: mov    rdi,QWORD PTR [rip+0x1a5c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_1409:
	/* 0x1409: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_140e:
	/* 0x140e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1413:
	/* 0x1413: jmp    1485 <filter_char_buf_equal+0x354> */
	goto x86_l_1485;
x86_l_1415:
	/* 0x1415: mov    rdi,QWORD PTR [rip+0x1a5c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_141c:
	/* 0x141c: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1421:
	/* 0x1421: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1426:
	/* 0x1426: jmp    1485 <filter_char_buf_equal+0x354> */
	goto x86_l_1485;
x86_l_1428:
	/* 0x1428: mov    rdi,QWORD PTR [rip+0x1a5c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_6)));
x86_l_142f:
	/* 0x142f: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1434:
	/* 0x1434: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1439:
	/* 0x1439: jmp    1485 <filter_char_buf_equal+0x354> */
	goto x86_l_1485;
x86_l_143b:
	/* 0x143b: mov    rdi,QWORD PTR [rip+0x1a5c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_9)));
x86_l_1442:
	/* 0x1442: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1447:
	/* 0x1447: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_144c:
	/* 0x144c: jmp    1485 <filter_char_buf_equal+0x354> */
	goto x86_l_1485;
x86_l_144e:
	/* 0x144e: mov    rdi,QWORD PTR [rip+0x1a5c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_1455:
	/* 0x1455: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_145a:
	/* 0x145a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_145f:
	/* 0x145f: jmp    1485 <filter_char_buf_equal+0x354> */
	goto x86_l_1485;
x86_l_1461:
	/* 0x1461: mov    rdi,QWORD PTR [rip+0x1a5c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_1468:
	/* 0x1468: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_146d:
	/* 0x146d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1472:
	/* 0x1472: jmp    1485 <filter_char_buf_equal+0x354> */
	goto x86_l_1485;
x86_l_1474:
	/* 0x1474: mov    rdi,QWORD PTR [rip+0x1a5c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_8)));
x86_l_147b:
	/* 0x147b: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1480:
	/* 0x1480: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1485:
	/* 0x1485: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_148a:
	/* 0x148a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_148c:
	/* 0x148c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_148f:
	/* 0x148f: je     14ad <filter_char_buf_equal+0x37c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14ad;
	}
x86_l_1491:
	/* 0x1491: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1494:
	/* 0x1494: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1499:
	/* 0x1499: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_149e:
	/* 0x149e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14a0:
	/* 0x14a0: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_14a3:
	/* 0x14a3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14a5:
	/* 0x14a5: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_14a8:
	/* 0x14a8: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_14ab:
	/* 0x14ab: jmp    14af <filter_char_buf_equal+0x37e> */
	goto x86_l_14af;
x86_l_14ad:
	/* 0x14ad: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14af:
	/* 0x14af: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_14b3:
	/* 0x14b3: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_14b4:
	/* 0x14b4: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_14b6:
	/* 0x14b6: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_14b8:
	/* 0x14b8: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_14ba:
	/* 0x14ba: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_14bc:
	/* 0x14bc: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_14bd:
	/* 0x14bd: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_14be:
	/* 0x14be: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_14bf:
	/* 0x14bf: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_14c1:
	/* 0x14c1: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_14c3:
	/* 0x14c3: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_14c5:
	/* 0x14c5: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_14c7:
	/* 0x14c7: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_14c8:
	/* 0x14c8: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_14c9:
	/* 0x14c9: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_14cc:
	/* 0x14cc: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_14cf:
	/* 0x14cf: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_14d1:
	/* 0x14d1: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_14d3:
	/* 0x14d3: je     159b <filter_char_substring+0xdd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_159b;
	}
x86_l_14d9:
	/* 0x14d9: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_14db:
	/* 0x14db: je     1638 <filter_char_substring+0x17a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5688ULL;
	}
x86_l_14e1:
	/* 0x14e1: lea    r13,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_14e6:
	/* 0x14e6: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14e8:
	/* 0x14e8: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14eb:
	/* 0x14eb: mov    eax,DWORD PTR [r14+rbx*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_14f0:
	/* 0x14f0: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_14f4:
	/* 0x14f4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14f9:
	/* 0x14f9: mov    rdi,QWORD PTR [rip+0x2093] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_1500:
	/* 0x1500: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1503:
	/* 0x1503: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1505:
	/* 0x1505: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1508:
	/* 0x1508: je     16bc <filter_char_substring+0x1fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5820ULL;
	}
x86_l_150e:
	/* 0x150e: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1511:
	/* 0x1511: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1513:
	/* 0x1513: jmp    1520 <filter_char_substring+0x62> */
	goto x86_l_1520;
x86_l_1515:
	/* 0x1515: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1518:
	/* 0x1518: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_151b:
	/* 0x151b: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_151e:
	/* 0x151e: je     1576 <filter_char_substring+0xb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1576;
	}
x86_l_1520:
	/* 0x1520: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1522:
	/* 0x1522: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_1526:
	/* 0x1526: cmp    rdi,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1529:
	/* 0x1529: jae    1515 <filter_char_substring+0x57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1515;
	}
x86_l_152b:
	/* 0x152b: movsx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_152f:
	/* 0x152f: test   edi,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_32);
x86_l_1531:
	/* 0x1531: je     156e <filter_char_substring+0xb0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_156e;
	}
x86_l_1533:
	/* 0x1533: movsx  r9d,BYTE PTR [rdx+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R9, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_1538:
	/* 0x1538: lea    r10d,[r9-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_153c:
	/* 0x153c: mov    r8d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R9, X86_WIDTH_32);
x86_l_153f:
	/* 0x153f: or     r8d,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_1543:
	/* 0x1543: cmp    r10d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 26ULL);
x86_l_1547:
	/* 0x1547: cmovae r8d,r9d */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_R9, X86_WIDTH_32, X86_CC_AE);
x86_l_154b:
	/* 0x154b: lea    r10d,[rdi-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_154f:
	/* 0x154f: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_1552:
	/* 0x1552: or     r9d,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_1556:
	/* 0x1556: cmp    r10d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 26ULL);
x86_l_155a:
	/* 0x155a: cmovae r9d,edi */
	X86_SIM_L_EXEC_CMOV(X86_R9, X86_RDI, X86_WIDTH_32, X86_CC_AE);
x86_l_155e:
	/* 0x155e: cmp    rsi,0x62 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 98ULL);
x86_l_1562:
	/* 0x1562: ja     1515 <filter_char_substring+0x57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1515;
	}
x86_l_1564:
	/* 0x1564: inc    rsi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1567:
	/* 0x1567: cmp    r8d,r9d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_R9, X86_WIDTH_32);
x86_l_156a:
	/* 0x156a: je     1522 <filter_char_substring+0x64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1522;
	}
x86_l_156c:
	/* 0x156c: jmp    1515 <filter_char_substring+0x57> */
	goto x86_l_1515;
x86_l_156e:
	/* 0x156e: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1570:
	/* 0x1570: jns    16cd <filter_char_substring+0x20f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 5837ULL;
	}
x86_l_1576:
	/* 0x1576: lea    eax,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_157b:
	/* 0x157b: cmp    eax,DWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_157f:
	/* 0x157f: jae    16bc <filter_char_substring+0x1fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 5820ULL;
	}
x86_l_1585:
	/* 0x1585: add    r12d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1589:
	/* 0x1589: inc    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_158c:
	/* 0x158c: cmp    rbx,0x64 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 100ULL);
x86_l_1590:
	/* 0x1590: jne    14eb <filter_char_substring+0x2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_14eb;
	}
x86_l_1596:
	/* 0x1596: jmp    16bc <filter_char_substring+0x1fe> */
	return 5820ULL;
x86_l_159b:
	/* 0x159b: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_159d:
	/* 0x159d: je     167b <filter_char_substring+0x1bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5755ULL;
	}
x86_l_15a3:
	/* 0x15a3: lea    r13,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_15a8:
	/* 0x15a8: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15aa:
	/* 0x15aa: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15ad:
	/* 0x15ad: mov    eax,DWORD PTR [r14+rbx*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_15b2:
	/* 0x15b2: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_15b6:
	/* 0x15b6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15bb:
	/* 0x15bb: mov    rdi,QWORD PTR [rip+0x20a1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_15c2:
	/* 0x15c2: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_15c5:
	/* 0x15c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15c7:
	/* 0x15c7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15ca:
	/* 0x15ca: je     16bc <filter_char_substring+0x1fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5820ULL;
	}
x86_l_15d0:
	/* 0x15d0: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_15d3:
	/* 0x15d3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15d5:
	/* 0x15d5: jmp    15e2 <filter_char_substring+0x124> */
	goto x86_l_15e2;
x86_l_15d7:
	/* 0x15d7: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_15da:
	/* 0x15da: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_15dd:
	/* 0x15dd: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_15e0:
	/* 0x15e0: je     1613 <filter_char_substring+0x155> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1613;
	}
x86_l_15e2:
	/* 0x15e2: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15e4:
	/* 0x15e4: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_15e8:
	/* 0x15e8: cmp    rdi,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_15eb:
	/* 0x15eb: jae    15d7 <filter_char_substring+0x119> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_15d7;
	}
x86_l_15ed:
	/* 0x15ed: movzx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_15f1:
	/* 0x15f1: test   dil,dil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_8);
x86_l_15f4:
	/* 0x15f4: je     160b <filter_char_substring+0x14d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_160b;
	}
x86_l_15f6:
	/* 0x15f6: cmp    rsi,0x62 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 98ULL);
x86_l_15fa:
	/* 0x15fa: ja     15d7 <filter_char_substring+0x119> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_15d7;
	}
x86_l_15fc:
	/* 0x15fc: lea    r8,[rsi+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1600:
	/* 0x1600: cmp    BYTE PTR [rdx+rsi*1],dil */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDX, X86_RDI, X86_WIDTH_8, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_1604:
	/* 0x1604: mov    rsi,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R8, X86_WIDTH_64);
x86_l_1607:
	/* 0x1607: je     15e4 <filter_char_substring+0x126> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15e4;
	}
x86_l_1609:
	/* 0x1609: jmp    15d7 <filter_char_substring+0x119> */
	goto x86_l_15d7;
x86_l_160b:
	/* 0x160b: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_160d:
	/* 0x160d: jns    16cd <filter_char_substring+0x20f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 5837ULL;
	}
x86_l_1613:
	/* 0x1613: lea    eax,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
	return 5656ULL;
}

static __noinline __u64 tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_filter_arg_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5656ULL: goto x86_l_1618;
	case 5660ULL: goto x86_l_161c;
	case 5666ULL: goto x86_l_1622;
	case 5670ULL: goto x86_l_1626;
	case 5673ULL: goto x86_l_1629;
	case 5677ULL: goto x86_l_162d;
	case 5683ULL: goto x86_l_1633;
	case 5688ULL: goto x86_l_1638;
	case 5693ULL: goto x86_l_163d;
	case 5700ULL: goto x86_l_1644;
	case 5705ULL: goto x86_l_1649;
	case 5709ULL: goto x86_l_164d;
	case 5713ULL: goto x86_l_1651;
	case 5718ULL: goto x86_l_1656;
	case 5721ULL: goto x86_l_1659;
	case 5724ULL: goto x86_l_165c;
	case 5726ULL: goto x86_l_165e;
	case 5729ULL: goto x86_l_1661;
	case 5731ULL: goto x86_l_1663;
	case 5735ULL: goto x86_l_1667;
	case 5738ULL: goto x86_l_166a;
	case 5742ULL: goto x86_l_166e;
	case 5744ULL: goto x86_l_1670;
	case 5751ULL: goto x86_l_1677;
	case 5753ULL: goto x86_l_1679;
	case 5755ULL: goto x86_l_167b;
	case 5760ULL: goto x86_l_1680;
	case 5767ULL: goto x86_l_1687;
	case 5772ULL: goto x86_l_168c;
	case 5776ULL: goto x86_l_1690;
	case 5780ULL: goto x86_l_1694;
	case 5785ULL: goto x86_l_1699;
	case 5788ULL: goto x86_l_169c;
	case 5791ULL: goto x86_l_169f;
	case 5793ULL: goto x86_l_16a1;
	case 5796ULL: goto x86_l_16a4;
	case 5798ULL: goto x86_l_16a6;
	case 5802ULL: goto x86_l_16aa;
	case 5805ULL: goto x86_l_16ad;
	case 5809ULL: goto x86_l_16b1;
	case 5811ULL: goto x86_l_16b3;
	case 5818ULL: goto x86_l_16ba;
	case 5820ULL: goto x86_l_16bc;
	case 5822ULL: goto x86_l_16be;
	case 5826ULL: goto x86_l_16c2;
	case 5827ULL: goto x86_l_16c3;
	case 5829ULL: goto x86_l_16c5;
	case 5831ULL: goto x86_l_16c7;
	case 5833ULL: goto x86_l_16c9;
	case 5835ULL: goto x86_l_16cb;
	case 5836ULL: goto x86_l_16cc;
	case 5837ULL: goto x86_l_16cd;
	case 5842ULL: goto x86_l_16d2;
	case 5844ULL: goto x86_l_16d4;
	case 5847ULL: goto x86_l_16d7;
	case 5852ULL: goto x86_l_16dc;
	case 5856ULL: goto x86_l_16e0;
	case 5858ULL: goto x86_l_16e2;
	case 5868ULL: goto x86_l_16ec;
	case 5872ULL: goto x86_l_16f0;
	case 5874ULL: goto x86_l_16f2;
	case 5875ULL: goto x86_l_16f3;
	case 5880ULL: goto x86_l_16f8;
	case 5884ULL: goto x86_l_16fc;
	case 5886ULL: goto x86_l_16fe;
	case 5889ULL: goto x86_l_1701;
	case 5892ULL: goto x86_l_1704;
	case 5898ULL: goto x86_l_170a;
	case 5900ULL: goto x86_l_170c;
	case 5903ULL: goto x86_l_170f;
	case 5906ULL: goto x86_l_1712;
	case 5907ULL: goto x86_l_1713;
	case 5911ULL: goto x86_l_1717;
	case 5913ULL: goto x86_l_1719;
	case 5916ULL: goto x86_l_171c;
	case 5919ULL: goto x86_l_171f;
	case 5921ULL: goto x86_l_1721;
	case 5924ULL: goto x86_l_1724;
	case 5927ULL: goto x86_l_1727;
	case 5933ULL: goto x86_l_172d;
	case 5936ULL: goto x86_l_1730;
	case 5938ULL: goto x86_l_1732;
	case 5941ULL: goto x86_l_1735;
	case 5947ULL: goto x86_l_173b;
	case 5950ULL: goto x86_l_173e;
	case 5952ULL: goto x86_l_1740;
	case 5955ULL: goto x86_l_1743;
	case 5961ULL: goto x86_l_1749;
	case 5964ULL: goto x86_l_174c;
	case 5966ULL: goto x86_l_174e;
	case 5971ULL: goto x86_l_1753;
	case 5974ULL: goto x86_l_1756;
	case 5976ULL: goto x86_l_1758;
	case 5979ULL: goto x86_l_175b;
	case 5985ULL: goto x86_l_1761;
	case 5988ULL: goto x86_l_1764;
	case 5991ULL: goto x86_l_1767;
	case 5997ULL: goto x86_l_176d;
	case 6002ULL: goto x86_l_1772;
	case 6005ULL: goto x86_l_1775;
	case 6011ULL: goto x86_l_177b;
	case 6014ULL: goto x86_l_177e;
	case 6017ULL: goto x86_l_1781;
	case 6023ULL: goto x86_l_1787;
	case 6026ULL: goto x86_l_178a;
	case 6029ULL: goto x86_l_178d;
	case 6035ULL: goto x86_l_1793;
	case 6038ULL: goto x86_l_1796;
	case 6044ULL: goto x86_l_179c;
	case 6047ULL: goto x86_l_179f;
	case 6053ULL: goto x86_l_17a5;
	case 6056ULL: goto x86_l_17a8;
	case 6062ULL: goto x86_l_17ae;
	case 6065ULL: goto x86_l_17b1;
	case 6071ULL: goto x86_l_17b7;
	case 6074ULL: goto x86_l_17ba;
	case 6080ULL: goto x86_l_17c0;
	case 6085ULL: goto x86_l_17c5;
	case 6088ULL: goto x86_l_17c8;
	case 6091ULL: goto x86_l_17cb;
	case 6097ULL: goto x86_l_17d1;
	case 6102ULL: goto x86_l_17d6;
	case 6105ULL: goto x86_l_17d9;
	case 6111ULL: goto x86_l_17df;
	case 6114ULL: goto x86_l_17e2;
	case 6117ULL: goto x86_l_17e5;
	case 6123ULL: goto x86_l_17eb;
	case 6126ULL: goto x86_l_17ee;
	case 6129ULL: goto x86_l_17f1;
	case 6135ULL: goto x86_l_17f7;
	case 6138ULL: goto x86_l_17fa;
	case 6144ULL: goto x86_l_1800;
	case 6147ULL: goto x86_l_1803;
	case 6153ULL: goto x86_l_1809;
	case 6156ULL: goto x86_l_180c;
	case 6162ULL: goto x86_l_1812;
	case 6165ULL: goto x86_l_1815;
	case 6171ULL: goto x86_l_181b;
	case 6174ULL: goto x86_l_181e;
	case 6180ULL: goto x86_l_1824;
	case 6185ULL: goto x86_l_1829;
	case 6188ULL: goto x86_l_182c;
	case 6191ULL: goto x86_l_182f;
	case 6193ULL: goto x86_l_1831;
	case 6196ULL: goto x86_l_1834;
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
	case 6239ULL: goto x86_l_185f;
	case 6241ULL: goto x86_l_1861;
	case 6251ULL: goto x86_l_186b;
	case 6255ULL: goto x86_l_186f;
	case 6261ULL: goto x86_l_1875;
	case 6263ULL: goto x86_l_1877;
	case 6266ULL: goto x86_l_187a;
	case 6269ULL: goto x86_l_187d;
	case 6275ULL: goto x86_l_1883;
	case 6278ULL: goto x86_l_1886;
	case 6281ULL: goto x86_l_1889;
	case 6283ULL: goto x86_l_188b;
	case 6286ULL: goto x86_l_188e;
	case 6292ULL: goto x86_l_1894;
	case 6295ULL: goto x86_l_1897;
	case 6297ULL: goto x86_l_1899;
	case 6300ULL: goto x86_l_189c;
	case 6306ULL: goto x86_l_18a2;
	case 6309ULL: goto x86_l_18a5;
	case 6311ULL: goto x86_l_18a7;
	case 6314ULL: goto x86_l_18aa;
	case 6320ULL: goto x86_l_18b0;
	case 6322ULL: goto x86_l_18b2;
	case 6325ULL: goto x86_l_18b5;
	case 6328ULL: goto x86_l_18b8;
	case 6334ULL: goto x86_l_18be;
	case 6337ULL: goto x86_l_18c1;
	case 6340ULL: goto x86_l_18c4;
	case 6342ULL: goto x86_l_18c6;
	case 6345ULL: goto x86_l_18c9;
	case 6351ULL: goto x86_l_18cf;
	case 6354ULL: goto x86_l_18d2;
	case 6356ULL: goto x86_l_18d4;
	case 6359ULL: goto x86_l_18d7;
	case 6365ULL: goto x86_l_18dd;
	case 6368ULL: goto x86_l_18e0;
	case 6370ULL: goto x86_l_18e2;
	case 6373ULL: goto x86_l_18e5;
	case 6379ULL: goto x86_l_18eb;
	case 6381ULL: goto x86_l_18ed;
	case 6382ULL: goto x86_l_18ee;
	case 6385ULL: goto x86_l_18f1;
	case 6388ULL: goto x86_l_18f4;
	case 6391ULL: goto x86_l_18f7;
	case 6397ULL: goto x86_l_18fd;
	case 6402ULL: goto x86_l_1902;
	case 6405ULL: goto x86_l_1905;
	case 6411ULL: goto x86_l_190b;
	case 6414ULL: goto x86_l_190e;
	case 6417ULL: goto x86_l_1911;
	case 6419ULL: goto x86_l_1913;
	case 6424ULL: goto x86_l_1918;
	case 6427ULL: goto x86_l_191b;
	case 6429ULL: goto x86_l_191d;
	case 6432ULL: goto x86_l_1920;
	case 6438ULL: goto x86_l_1926;
	case 6441ULL: goto x86_l_1929;
	case 6444ULL: goto x86_l_192c;
	case 6450ULL: goto x86_l_1932;
	case 6453ULL: goto x86_l_1935;
	case 6455ULL: goto x86_l_1937;
	case 6458ULL: goto x86_l_193a;
	case 6464ULL: goto x86_l_1940;
	case 6467ULL: goto x86_l_1943;
	case 6473ULL: goto x86_l_1949;
	case 6476ULL: goto x86_l_194c;
	case 6478ULL: goto x86_l_194e;
	case 6481ULL: goto x86_l_1951;
	case 6487ULL: goto x86_l_1957;
	case 6490ULL: goto x86_l_195a;
	case 6496ULL: goto x86_l_1960;
	case 6498ULL: goto x86_l_1962;
	case 6501ULL: goto x86_l_1965;
	case 6507ULL: goto x86_l_196b;
	case 6510ULL: goto x86_l_196e;
	case 6516ULL: goto x86_l_1974;
	case 6521ULL: goto x86_l_1979;
	case 6524ULL: goto x86_l_197c;
	case 6527ULL: goto x86_l_197f;
	case 6531ULL: goto x86_l_1983;
	case 6534ULL: goto x86_l_1986;
	case 6537ULL: goto x86_l_1989;
	case 6540ULL: goto x86_l_198c;
	case 6543ULL: goto x86_l_198f;
	case 6549ULL: goto x86_l_1995;
	case 6552ULL: goto x86_l_1998;
	case 6556ULL: goto x86_l_199c;
	case 6559ULL: goto x86_l_199f;
	case 6563ULL: goto x86_l_19a3;
	case 6566ULL: goto x86_l_19a6;
	case 6569ULL: goto x86_l_19a9;
	case 6572ULL: goto x86_l_19ac;
	case 6578ULL: goto x86_l_19b2;
	case 6581ULL: goto x86_l_19b5;
	case 6585ULL: goto x86_l_19b9;
	case 6588ULL: goto x86_l_19bc;
	case 6592ULL: goto x86_l_19c0;
	case 6595ULL: goto x86_l_19c3;
	case 6598ULL: goto x86_l_19c6;
	case 6601ULL: goto x86_l_19c9;
	case 6607ULL: goto x86_l_19cf;
	case 6610ULL: goto x86_l_19d2;
	case 6613ULL: goto x86_l_19d5;
	case 6616ULL: goto x86_l_19d8;
	case 6620ULL: goto x86_l_19dc;
	case 6622ULL: goto x86_l_19de;
	case 6625ULL: goto x86_l_19e1;
	case 6628ULL: goto x86_l_19e4;
	case 6630ULL: goto x86_l_19e6;
	case 6635ULL: goto x86_l_19eb;
	case 6638ULL: goto x86_l_19ee;
	case 6640ULL: goto x86_l_19f0;
	case 6643ULL: goto x86_l_19f3;
	case 6645ULL: goto x86_l_19f5;
	case 6646ULL: goto x86_l_19f6;
	case 6649ULL: goto x86_l_19f9;
	case 6652ULL: goto x86_l_19fc;
	case 6656ULL: goto x86_l_1a00;
	case 6659ULL: goto x86_l_1a03;
	case 6662ULL: goto x86_l_1a06;
	case 6665ULL: goto x86_l_1a09;
	case 6668ULL: goto x86_l_1a0c;
	case 6674ULL: goto x86_l_1a12;
	case 6677ULL: goto x86_l_1a15;
	case 6681ULL: goto x86_l_1a19;
	case 6684ULL: goto x86_l_1a1c;
	case 6688ULL: goto x86_l_1a20;
	case 6691ULL: goto x86_l_1a23;
	case 6694ULL: goto x86_l_1a26;
	case 6697ULL: goto x86_l_1a29;
	case 6699ULL: goto x86_l_1a2b;
	case 6702ULL: goto x86_l_1a2e;
	case 6706ULL: goto x86_l_1a32;
	case 6709ULL: goto x86_l_1a35;
	case 6713ULL: goto x86_l_1a39;
	case 6716ULL: goto x86_l_1a3c;
	case 6719ULL: goto x86_l_1a3f;
	case 6722ULL: goto x86_l_1a42;
	case 6724ULL: goto x86_l_1a44;
	case 6727ULL: goto x86_l_1a47;
	case 6730ULL: goto x86_l_1a4a;
	case 6733ULL: goto x86_l_1a4d;
	case 6737ULL: goto x86_l_1a51;
	case 6740ULL: goto x86_l_1a54;
	case 6743ULL: goto x86_l_1a57;
	case 6745ULL: goto x86_l_1a59;
	case 6748ULL: goto x86_l_1a5c;
	case 6751ULL: goto x86_l_1a5f;
	case 6753ULL: goto x86_l_1a61;
	case 6756ULL: goto x86_l_1a64;
	case 6758ULL: goto x86_l_1a66;
	case 6761ULL: goto x86_l_1a69;
	case 6763ULL: goto x86_l_1a6b;
	case 6766ULL: goto x86_l_1a6e;
	case 6768ULL: goto x86_l_1a70;
	case 6771ULL: goto x86_l_1a73;
	case 6773ULL: goto x86_l_1a75;
	case 6776ULL: goto x86_l_1a78;
	case 6782ULL: goto x86_l_1a7e;
	case 6785ULL: goto x86_l_1a81;
	case 6787ULL: goto x86_l_1a83;
	case 6789ULL: goto x86_l_1a85;
	case 6792ULL: goto x86_l_1a88;
	case 6794ULL: goto x86_l_1a8a;
	case 6797ULL: goto x86_l_1a8d;
	case 6803ULL: goto x86_l_1a93;
	case 6805ULL: goto x86_l_1a95;
	case 6807ULL: goto x86_l_1a97;
	case 6810ULL: goto x86_l_1a9a;
	case 6813ULL: goto x86_l_1a9d;
	case 6816ULL: goto x86_l_1aa0;
	case 6818ULL: goto x86_l_1aa2;
	case 6821ULL: goto x86_l_1aa5;
	case 6822ULL: goto x86_l_1aa6;
	case 6824ULL: goto x86_l_1aa8;
	case 6825ULL: goto x86_l_1aa9;
	case 6829ULL: goto x86_l_1aad;
	case 6832ULL: goto x86_l_1ab0;
	case 6835ULL: goto x86_l_1ab3;
	case 6839ULL: goto x86_l_1ab7;
	case 6843ULL: goto x86_l_1abb;
	case 6850ULL: goto x86_l_1ac2;
	case 6855ULL: goto x86_l_1ac7;
	case 6860ULL: goto x86_l_1acc;
	case 6862ULL: goto x86_l_1ace;
	case 6865ULL: goto x86_l_1ad1;
	case 6867ULL: goto x86_l_1ad3;
	case 6870ULL: goto x86_l_1ad6;
	case 6874ULL: goto x86_l_1ada;
	case 6879ULL: goto x86_l_1adf;
	case 6884ULL: goto x86_l_1ae4;
	case 6889ULL: goto x86_l_1ae9;
	case 6891ULL: goto x86_l_1aeb;
	case 6894ULL: goto x86_l_1aee;
	case 6896ULL: goto x86_l_1af0;
	case 6899ULL: goto x86_l_1af3;
	case 6901ULL: goto x86_l_1af5;
	case 6906ULL: goto x86_l_1afa;
	case 6909ULL: goto x86_l_1afd;
	case 6911ULL: goto x86_l_1aff;
	case 6914ULL: goto x86_l_1b02;
	case 6917ULL: goto x86_l_1b05;
	case 6919ULL: goto x86_l_1b07;
	case 6921ULL: goto x86_l_1b09;
	case 6925ULL: goto x86_l_1b0d;
	case 6926ULL: goto x86_l_1b0e;
	case 6928ULL: goto x86_l_1b10;
	case 6929ULL: goto x86_l_1b11;
	case 6934ULL: goto x86_l_1b16;
	case 6937ULL: goto x86_l_1b19;
	case 6939ULL: goto x86_l_1b1b;
	case 6942ULL: goto x86_l_1b1e;
	case 6945ULL: goto x86_l_1b21;
	case 6948ULL: goto x86_l_1b24;
	case 6952ULL: goto x86_l_1b28;
	case 6953ULL: goto x86_l_1b29;
	case 6955ULL: goto x86_l_1b2b;
	case 6956ULL: goto x86_l_1b2c;
	case 6959ULL: goto x86_l_1b2f;
	case 6964ULL: goto x86_l_1b34;
	case 6968ULL: goto x86_l_1b38;
	case 6970ULL: goto x86_l_1b3a;
	case 6980ULL: goto x86_l_1b44;
	case 6984ULL: goto x86_l_1b48;
	case 6986ULL: goto x86_l_1b4a;
	case 6987ULL: goto x86_l_1b4b;
	case 6992ULL: goto x86_l_1b50;
	case 6996ULL: goto x86_l_1b54;
	case 6998ULL: goto x86_l_1b56;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1618:
	/* 0x1618: cmp    eax,DWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_161c:
	/* 0x161c: jae    16bc <filter_char_substring+0x1fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_16bc;
	}
x86_l_1622:
	/* 0x1622: add    r12d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1626:
	/* 0x1626: inc    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1629:
	/* 0x1629: cmp    rbx,0x64 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 100ULL);
x86_l_162d:
	/* 0x162d: jne    15ad <filter_char_substring+0xef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5549ULL;
	}
x86_l_1633:
	/* 0x1633: jmp    16bc <filter_char_substring+0x1fe> */
	goto x86_l_16bc;
x86_l_1638:
	/* 0x1638: mov    ebx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 16ULL);
x86_l_163d:
	/* 0x163d: mov    r15,QWORD PTR [rip+0x20b3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_1644:
	/* 0x1644: lea    r12,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1649:
	/* 0x1649: mov    eax,DWORD PTR [r14+rbx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_164d:
	/* 0x164d: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1651:
	/* 0x1651: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1656:
	/* 0x1656: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1659:
	/* 0x1659: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_165c:
	/* 0x165c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_165e:
	/* 0x165e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1661:
	/* 0x1661: je     16bc <filter_char_substring+0x1fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16bc;
	}
x86_l_1663:
	/* 0x1663: add    rbx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1667:
	/* 0x1667: lea    eax,[rbx-0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551608ULL);
x86_l_166a:
	/* 0x166a: cmp    eax,DWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_166e:
	/* 0x166e: jae    16bc <filter_char_substring+0x1fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_16bc;
	}
x86_l_1670:
	/* 0x1670: cmp    rbx,0x1a0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 416ULL);
x86_l_1677:
	/* 0x1677: jne    1649 <filter_char_substring+0x18b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1649;
	}
x86_l_1679:
	/* 0x1679: jmp    16bc <filter_char_substring+0x1fe> */
	goto x86_l_16bc;
x86_l_167b:
	/* 0x167b: mov    ebx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 16ULL);
x86_l_1680:
	/* 0x1680: mov    r15,QWORD PTR [rip+0x20b5] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_1687:
	/* 0x1687: lea    r12,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_168c:
	/* 0x168c: mov    eax,DWORD PTR [r14+rbx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_1690:
	/* 0x1690: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1694:
	/* 0x1694: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1699:
	/* 0x1699: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_169c:
	/* 0x169c: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_169f:
	/* 0x169f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16a1:
	/* 0x16a1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16a4:
	/* 0x16a4: je     16bc <filter_char_substring+0x1fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16bc;
	}
x86_l_16a6:
	/* 0x16a6: add    rbx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_16aa:
	/* 0x16aa: lea    eax,[rbx-0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551608ULL);
x86_l_16ad:
	/* 0x16ad: cmp    eax,DWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_16b1:
	/* 0x16b1: jae    16bc <filter_char_substring+0x1fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_16bc;
	}
x86_l_16b3:
	/* 0x16b3: cmp    rbx,0x1a0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 416ULL);
x86_l_16ba:
	/* 0x16ba: jne    168c <filter_char_substring+0x1ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_168c;
	}
x86_l_16bc:
	/* 0x16bc: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16be:
	/* 0x16be: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_16c2:
	/* 0x16c2: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_16c3:
	/* 0x16c3: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_16c5:
	/* 0x16c5: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_16c7:
	/* 0x16c7: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_16c9:
	/* 0x16c9: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_16cb:
	/* 0x16cb: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_16cc:
	/* 0x16cc: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_16cd:
	/* 0x16cd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16d2:
	/* 0x16d2: jmp    16be <filter_char_substring+0x200> */
	goto x86_l_16be;
x86_l_16d4:
	/* 0x16d4: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_16d7:
	/* 0x16d7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16dc:
	/* 0x16dc: cmp    rcx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 37ULL);
x86_l_16e0:
	/* 0x16e0: ja     1753 <filter_16ty_selector_val+0x7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1753;
	}
x86_l_16e2:
	/* 0x16e2: movabs rdx,0x200c000040 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280128ULL);
x86_l_16ec:
	/* 0x16ec: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_16f0:
	/* 0x16f0: jae    16f3 <filter_16ty_selector_val+0x1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_16f3;
	}
x86_l_16f2:
	/* 0x16f2: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_16f3:
	/* 0x16f3: mov    edx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 24ULL);
x86_l_16f8:
	/* 0x16f8: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_16fc:
	/* 0x16fc: jae    1713 <filter_16ty_selector_val+0x3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1713;
	}
x86_l_16fe:
	/* 0x16fe: movzx  edx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1701:
	/* 0x1701: cmp    DWORD PTR [rdi+0x10],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1704:
	/* 0x1704: jne    1829 <filter_16ty_selector_val+0x155> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1829;
	}
x86_l_170a:
	/* 0x170a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_170c:
	/* 0x170c: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_170f:
	/* 0x170f: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_1712:
	/* 0x1712: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1713:
	/* 0x1713: cmp    rcx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 12ULL);
x86_l_1717:
	/* 0x1717: jne    1753 <filter_16ty_selector_val+0x7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1753;
	}
x86_l_1719:
	/* 0x1719: movzx  ecx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_171c:
	/* 0x171c: test   DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_171f:
	/* 0x171f: jne    16f2 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_16f2;
	}
x86_l_1721:
	/* 0x1721: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1724:
	/* 0x1724: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1727:
	/* 0x1727: jb     18eb <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18eb;
	}
x86_l_172d:
	/* 0x172d: test   DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1730:
	/* 0x1730: jne    16f2 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_16f2;
	}
x86_l_1732:
	/* 0x1732: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1735:
	/* 0x1735: jb     18eb <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18eb;
	}
x86_l_173b:
	/* 0x173b: test   DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_173e:
	/* 0x173e: jne    16f2 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_16f2;
	}
x86_l_1740:
	/* 0x1740: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_1743:
	/* 0x1743: jb     18eb <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18eb;
	}
x86_l_1749:
	/* 0x1749: test   DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_174c:
	/* 0x174c: jne    16f2 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_16f2;
	}
x86_l_174e:
	/* 0x174e: jmp    18eb <filter_16ty_selector_val+0x217> */
	goto x86_l_18eb;
x86_l_1753:
	/* 0x1753: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1756:
	/* 0x1756: je     17c5 <filter_16ty_selector_val+0xf1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17c5;
	}
x86_l_1758:
	/* 0x1758: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_175b:
	/* 0x175b: jne    18eb <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_18eb;
	}
x86_l_1761:
	/* 0x1761: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1764:
	/* 0x1764: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1767:
	/* 0x1767: ja     18b2 <filter_16ty_selector_val+0x1de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_18b2;
	}
x86_l_176d:
	/* 0x176d: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_1772:
	/* 0x1772: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_1775:
	/* 0x1775: jae    18b2 <filter_16ty_selector_val+0x1de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_18b2;
	}
x86_l_177b:
	/* 0x177b: movsx  ecx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_177e:
	/* 0x177e: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1781:
	/* 0x1781: jg     16f2 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_16f2;
	}
x86_l_1787:
	/* 0x1787: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_178a:
	/* 0x178a: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_178d:
	/* 0x178d: jb     18eb <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18eb;
	}
x86_l_1793:
	/* 0x1793: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1796:
	/* 0x1796: jg     16f2 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_16f2;
	}
x86_l_179c:
	/* 0x179c: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_179f:
	/* 0x179f: jb     18eb <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18eb;
	}
x86_l_17a5:
	/* 0x17a5: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_17a8:
	/* 0x17a8: jg     16f2 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_16f2;
	}
x86_l_17ae:
	/* 0x17ae: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_17b1:
	/* 0x17b1: jb     18eb <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18eb;
	}
x86_l_17b7:
	/* 0x17b7: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_17ba:
	/* 0x17ba: jg     16f2 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_16f2;
	}
x86_l_17c0:
	/* 0x17c0: jmp    18eb <filter_16ty_selector_val+0x217> */
	goto x86_l_18eb;
x86_l_17c5:
	/* 0x17c5: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_17c8:
	/* 0x17c8: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_17cb:
	/* 0x17cb: ja     1877 <filter_16ty_selector_val+0x1a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1877;
	}
x86_l_17d1:
	/* 0x17d1: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_17d6:
	/* 0x17d6: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_17d9:
	/* 0x17d9: jae    1877 <filter_16ty_selector_val+0x1a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1877;
	}
x86_l_17df:
	/* 0x17df: movsx  ecx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_17e2:
	/* 0x17e2: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17e5:
	/* 0x17e5: jl     16f2 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_16f2;
	}
x86_l_17eb:
	/* 0x17eb: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17ee:
	/* 0x17ee: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_17f1:
	/* 0x17f1: jb     18eb <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18eb;
	}
x86_l_17f7:
	/* 0x17f7: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_17fa:
	/* 0x17fa: jl     16f2 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_16f2;
	}
x86_l_1800:
	/* 0x1800: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1803:
	/* 0x1803: jb     18eb <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18eb;
	}
x86_l_1809:
	/* 0x1809: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_180c:
	/* 0x180c: jl     16f2 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_16f2;
	}
x86_l_1812:
	/* 0x1812: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_1815:
	/* 0x1815: jb     18eb <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18eb;
	}
x86_l_181b:
	/* 0x181b: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_181e:
	/* 0x181e: jl     16f2 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_16f2;
	}
x86_l_1824:
	/* 0x1824: jmp    18eb <filter_16ty_selector_val+0x217> */
	goto x86_l_18eb;
x86_l_1829:
	/* 0x1829: mov    esi,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_182c:
	/* 0x182c: cmp    esi,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 13ULL);
x86_l_182f:
	/* 0x182f: jb     1856 <filter_16ty_selector_val+0x182> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1856;
	}
x86_l_1831:
	/* 0x1831: cmp    DWORD PTR [rdi+0x14],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1834:
	/* 0x1834: je     170a <filter_16ty_selector_val+0x36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_170a;
	}
x86_l_183a:
	/* 0x183a: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_183d:
	/* 0x183d: jb     1856 <filter_16ty_selector_val+0x182> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1856;
	}
x86_l_183f:
	/* 0x183f: cmp    DWORD PTR [rdi+0x18],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1842:
	/* 0x1842: je     170a <filter_16ty_selector_val+0x36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_170a;
	}
x86_l_1848:
	/* 0x1848: cmp    esi,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 21ULL);
x86_l_184b:
	/* 0x184b: jb     1856 <filter_16ty_selector_val+0x182> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1856;
	}
x86_l_184d:
	/* 0x184d: cmp    DWORD PTR [rdi+0x1c],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1850:
	/* 0x1850: je     170a <filter_16ty_selector_val+0x36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_170a;
	}
x86_l_1856:
	/* 0x1856: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_1859:
	/* 0x1859: ja     18eb <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_18eb;
	}
x86_l_185f:
	/* 0x185f: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1861:
	/* 0x1861: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_186b:
	/* 0x186b: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_186f:
	/* 0x186f: jb     16f2 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_16f2;
	}
x86_l_1875:
	/* 0x1875: jmp    18eb <filter_16ty_selector_val+0x217> */
	goto x86_l_18eb;
x86_l_1877:
	/* 0x1877: movzx  ecx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_187a:
	/* 0x187a: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_187d:
	/* 0x187d: jb     16f2 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_16f2;
	}
x86_l_1883:
	/* 0x1883: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1886:
	/* 0x1886: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1889:
	/* 0x1889: jb     18eb <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18eb;
	}
x86_l_188b:
	/* 0x188b: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_188e:
	/* 0x188e: jb     16f2 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_16f2;
	}
x86_l_1894:
	/* 0x1894: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1897:
	/* 0x1897: jb     18eb <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18eb;
	}
x86_l_1899:
	/* 0x1899: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_189c:
	/* 0x189c: jb     16f2 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_16f2;
	}
x86_l_18a2:
	/* 0x18a2: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_18a5:
	/* 0x18a5: jb     18eb <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18eb;
	}
x86_l_18a7:
	/* 0x18a7: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_18aa:
	/* 0x18aa: jb     16f2 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_16f2;
	}
x86_l_18b0:
	/* 0x18b0: jmp    18eb <filter_16ty_selector_val+0x217> */
	goto x86_l_18eb;
x86_l_18b2:
	/* 0x18b2: movzx  ecx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_18b5:
	/* 0x18b5: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18b8:
	/* 0x18b8: ja     16f2 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_16f2;
	}
x86_l_18be:
	/* 0x18be: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18c1:
	/* 0x18c1: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_18c4:
	/* 0x18c4: jb     18eb <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18eb;
	}
x86_l_18c6:
	/* 0x18c6: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_18c9:
	/* 0x18c9: ja     16f2 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_16f2;
	}
x86_l_18cf:
	/* 0x18cf: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_18d2:
	/* 0x18d2: jb     18eb <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18eb;
	}
x86_l_18d4:
	/* 0x18d4: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18d7:
	/* 0x18d7: ja     16f2 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_16f2;
	}
x86_l_18dd:
	/* 0x18dd: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_18e0:
	/* 0x18e0: jb     18eb <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18eb;
	}
x86_l_18e2:
	/* 0x18e2: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_18e5:
	/* 0x18e5: ja     16f2 <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_16f2;
	}
x86_l_18eb:
	/* 0x18eb: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18ed:
	/* 0x18ed: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_18ee:
	/* 0x18ee: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_18f1:
	/* 0x18f1: mov    eax,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_18f4:
	/* 0x18f4: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_18f7:
	/* 0x18f7: ja     19de <filter_16ty_range+0xf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_19de;
	}
x86_l_18fd:
	/* 0x18fd: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_1902:
	/* 0x1902: bt     edx,eax */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_1905:
	/* 0x1905: jae    19de <filter_16ty_range+0xf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_19de;
	}
x86_l_190b:
	/* 0x190b: movsx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_190e:
	/* 0x190e: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_1911:
	/* 0x1911: jne    1979 <filter_16ty_range+0x8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1979;
	}
x86_l_1913:
	/* 0x1913: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1918:
	/* 0x1918: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_191b:
	/* 0x191b: jg     1926 <filter_16ty_range+0x38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1926;
	}
x86_l_191d:
	/* 0x191d: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1920:
	/* 0x1920: jge    19f5 <filter_16ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_GE)) {
		goto x86_l_19f5;
	}
x86_l_1926:
	/* 0x1926: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1929:
	/* 0x1929: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_192c:
	/* 0x192c: jb     1a95 <filter_16ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1a95;
	}
x86_l_1932:
	/* 0x1932: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1935:
	/* 0x1935: jg     1940 <filter_16ty_range+0x52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1940;
	}
x86_l_1937:
	/* 0x1937: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_193a:
	/* 0x193a: jge    19f5 <filter_16ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_GE)) {
		goto x86_l_19f5;
	}
x86_l_1940:
	/* 0x1940: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_1943:
	/* 0x1943: jb     1a95 <filter_16ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1a95;
	}
x86_l_1949:
	/* 0x1949: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_194c:
	/* 0x194c: jg     1957 <filter_16ty_range+0x69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1957;
	}
x86_l_194e:
	/* 0x194e: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1951:
	/* 0x1951: jge    19f5 <filter_16ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_GE)) {
		goto x86_l_19f5;
	}
x86_l_1957:
	/* 0x1957: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_195a:
	/* 0x195a: jb     1a95 <filter_16ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1a95;
	}
x86_l_1960:
	/* 0x1960: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1962:
	/* 0x1962: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1965:
	/* 0x1965: jg     1a97 <filter_16ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1a97;
	}
x86_l_196b:
	/* 0x196b: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_196e:
	/* 0x196e: jge    19f5 <filter_16ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_GE)) {
		goto x86_l_19f5;
	}
x86_l_1974:
	/* 0x1974: jmp    1a97 <filter_16ty_range+0x1a9> */
	goto x86_l_1a97;
x86_l_1979:
	/* 0x1979: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_197c:
	/* 0x197c: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_197f:
	/* 0x197f: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_1983:
	/* 0x1983: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1986:
	/* 0x1986: setge  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_GE);
x86_l_1989:
	/* 0x1989: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_198c:
	/* 0x198c: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_198f:
	/* 0x198f: jb     1a97 <filter_16ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1a97;
	}
x86_l_1995:
	/* 0x1995: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1998:
	/* 0x1998: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_199c:
	/* 0x199c: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_199f:
	/* 0x199f: setge  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_GE);
x86_l_19a3:
	/* 0x19a3: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_19a6:
	/* 0x19a6: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_19a9:
	/* 0x19a9: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_19ac:
	/* 0x19ac: jb     1a97 <filter_16ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1a97;
	}
x86_l_19b2:
	/* 0x19b2: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_19b5:
	/* 0x19b5: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_19b9:
	/* 0x19b9: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_19bc:
	/* 0x19bc: setge  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_GE);
x86_l_19c0:
	/* 0x19c0: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_19c3:
	/* 0x19c3: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_19c6:
	/* 0x19c6: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_19c9:
	/* 0x19c9: jb     1a97 <filter_16ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1a97;
	}
x86_l_19cf:
	/* 0x19cf: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_19d2:
	/* 0x19d2: setle  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_LE);
x86_l_19d5:
	/* 0x19d5: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_19d8:
	/* 0x19d8: setge  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_GE);
x86_l_19dc:
	/* 0x19dc: jmp    1a51 <filter_16ty_range+0x163> */
	goto x86_l_1a51;
x86_l_19de:
	/* 0x19de: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_19e1:
	/* 0x19e1: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_19e4:
	/* 0x19e4: jne    19f6 <filter_16ty_range+0x108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_19f6;
	}
x86_l_19e6:
	/* 0x19e6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_19eb:
	/* 0x19eb: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19ee:
	/* 0x19ee: ja     1a59 <filter_16ty_range+0x16b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1a59;
	}
x86_l_19f0:
	/* 0x19f0: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_19f3:
	/* 0x19f3: jb     1a59 <filter_16ty_range+0x16b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1a59;
	}
x86_l_19f5:
	/* 0x19f5: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_19f6:
	/* 0x19f6: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19f9:
	/* 0x19f9: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19fc:
	/* 0x19fc: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_1a00:
	/* 0x1a00: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1a03:
	/* 0x1a03: setae  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_AE);
x86_l_1a06:
	/* 0x1a06: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1a09:
	/* 0x1a09: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1a0c:
	/* 0x1a0c: jb     1a97 <filter_16ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1a97;
	}
x86_l_1a12:
	/* 0x1a12: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a15:
	/* 0x1a15: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_1a19:
	/* 0x1a19: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1a1c:
	/* 0x1a1c: setae  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_AE);
x86_l_1a20:
	/* 0x1a20: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1a23:
	/* 0x1a23: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_1a26:
	/* 0x1a26: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1a29:
	/* 0x1a29: jb     1a97 <filter_16ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1a97;
	}
x86_l_1a2b:
	/* 0x1a2b: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a2e:
	/* 0x1a2e: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_1a32:
	/* 0x1a32: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1a35:
	/* 0x1a35: setae  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_AE);
x86_l_1a39:
	/* 0x1a39: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1a3c:
	/* 0x1a3c: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_1a3f:
	/* 0x1a3f: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_1a42:
	/* 0x1a42: jb     1a97 <filter_16ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1a97;
	}
x86_l_1a44:
	/* 0x1a44: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1a47:
	/* 0x1a47: setbe  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_BE);
x86_l_1a4a:
	/* 0x1a4a: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1a4d:
	/* 0x1a4d: setae  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_AE);
x86_l_1a51:
	/* 0x1a51: and    sil,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_1a54:
	/* 0x1a54: or     dl,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_8, X86_ALU_OR);
x86_l_1a57:
	/* 0x1a57: jmp    1a97 <filter_16ty_range+0x1a9> */
	goto x86_l_1a97;
x86_l_1a59:
	/* 0x1a59: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a5c:
	/* 0x1a5c: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1a5f:
	/* 0x1a5f: jb     1a95 <filter_16ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1a95;
	}
x86_l_1a61:
	/* 0x1a61: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a64:
	/* 0x1a64: ja     1a6b <filter_16ty_range+0x17d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1a6b;
	}
x86_l_1a66:
	/* 0x1a66: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1a69:
	/* 0x1a69: jae    19f5 <filter_16ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_19f5;
	}
x86_l_1a6b:
	/* 0x1a6b: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_1a6e:
	/* 0x1a6e: jb     1a95 <filter_16ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1a95;
	}
x86_l_1a70:
	/* 0x1a70: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a73:
	/* 0x1a73: ja     1a7e <filter_16ty_range+0x190> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1a7e;
	}
x86_l_1a75:
	/* 0x1a75: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1a78:
	/* 0x1a78: jae    19f5 <filter_16ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_19f5;
	}
x86_l_1a7e:
	/* 0x1a7e: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_1a81:
	/* 0x1a81: jb     1a95 <filter_16ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1a95;
	}
x86_l_1a83:
	/* 0x1a83: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a85:
	/* 0x1a85: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1a88:
	/* 0x1a88: ja     1a97 <filter_16ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1a97;
	}
x86_l_1a8a:
	/* 0x1a8a: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1a8d:
	/* 0x1a8d: jae    19f5 <filter_16ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_19f5;
	}
x86_l_1a93:
	/* 0x1a93: jmp    1a97 <filter_16ty_range+0x1a9> */
	goto x86_l_1a97;
x86_l_1a95:
	/* 0x1a95: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a97:
	/* 0x1a97: cmp    ecx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 32ULL);
x86_l_1a9a:
	/* 0x1a9a: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_1a9d:
	/* 0x1a9d: xor    dl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_1aa0:
	/* 0x1aa0: and    dl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_1aa2:
	/* 0x1aa2: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1aa5:
	/* 0x1aa5: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1aa6:
	/* 0x1aa6: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_1aa8:
	/* 0x1aa8: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_1aa9:
	/* 0x1aa9: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_1aad:
	/* 0x1aad: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_1ab0:
	/* 0x1ab0: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_1ab3:
	/* 0x1ab3: movzx  eax,BYTE PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1ab7:
	/* 0x1ab7: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1abb:
	/* 0x1abb: mov    rdi,QWORD PTR [rip+0xe20] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_1ac2:
	/* 0x1ac2: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1ac7:
	/* 0x1ac7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1acc:
	/* 0x1acc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ace:
	/* 0x1ace: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ad1:
	/* 0x1ad1: je     1b07 <filter_16ty_map+0x61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b07;
	}
x86_l_1ad3:
	/* 0x1ad3: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1ad6:
	/* 0x1ad6: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1ada:
	/* 0x1ada: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1adf:
	/* 0x1adf: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ae4:
	/* 0x1ae4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ae9:
	/* 0x1ae9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aeb:
	/* 0x1aeb: mov    edx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1aee:
	/* 0x1aee: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1af0:
	/* 0x1af0: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_1af3:
	/* 0x1af3: ja     1b21 <filter_16ty_map+0x7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1b21;
	}
x86_l_1af5:
	/* 0x1af5: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_1afa:
	/* 0x1afa: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1afd:
	/* 0x1afd: jae    1b11 <filter_16ty_map+0x6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1b11;
	}
x86_l_1aff:
	/* 0x1aff: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b02:
	/* 0x1b02: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_1b05:
	/* 0x1b05: jmp    1b21 <filter_16ty_map+0x7b> */
	goto x86_l_1b21;
x86_l_1b07:
	/* 0x1b07: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b09:
	/* 0x1b09: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1b0d:
	/* 0x1b0d: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1b0e:
	/* 0x1b0e: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_1b10:
	/* 0x1b10: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1b11:
	/* 0x1b11: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_1b16:
	/* 0x1b16: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1b19:
	/* 0x1b19: jae    1b21 <filter_16ty_map+0x7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1b21;
	}
x86_l_1b1b:
	/* 0x1b1b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b1e:
	/* 0x1b1e: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_1b21:
	/* 0x1b21: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1b24:
	/* 0x1b24: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1b28:
	/* 0x1b28: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1b29:
	/* 0x1b29: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_1b2b:
	/* 0x1b2b: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1b2c:
	/* 0x1b2c: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1b2f:
	/* 0x1b2f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b34:
	/* 0x1b34: cmp    rcx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 37ULL);
x86_l_1b38:
	/* 0x1b38: ja     1ba9 <filter_32ty_selector_val+0x7d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7081ULL;
	}
x86_l_1b3a:
	/* 0x1b3a: movabs rdx,0x200c000040 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280128ULL);
x86_l_1b44:
	/* 0x1b44: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1b48:
	/* 0x1b48: jae    1b4b <filter_32ty_selector_val+0x1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1b4b;
	}
x86_l_1b4a:
	/* 0x1b4a: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1b4b:
	/* 0x1b4b: mov    edx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 24ULL);
x86_l_1b50:
	/* 0x1b50: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1b54:
	/* 0x1b54: jae    1b6a <filter_32ty_selector_val+0x3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 7018ULL;
	}
x86_l_1b56:
	/* 0x1b56: mov    edx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
	return 7000ULL;
}

static __noinline __u64 tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_filter_arg_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7000ULL: goto x86_l_1b58;
	case 7003ULL: goto x86_l_1b5b;
	case 7009ULL: goto x86_l_1b61;
	case 7011ULL: goto x86_l_1b63;
	case 7014ULL: goto x86_l_1b66;
	case 7017ULL: goto x86_l_1b69;
	case 7018ULL: goto x86_l_1b6a;
	case 7022ULL: goto x86_l_1b6e;
	case 7024ULL: goto x86_l_1b70;
	case 7026ULL: goto x86_l_1b72;
	case 7029ULL: goto x86_l_1b75;
	case 7031ULL: goto x86_l_1b77;
	case 7034ULL: goto x86_l_1b7a;
	case 7037ULL: goto x86_l_1b7d;
	case 7043ULL: goto x86_l_1b83;
	case 7046ULL: goto x86_l_1b86;
	case 7048ULL: goto x86_l_1b88;
	case 7051ULL: goto x86_l_1b8b;
	case 7057ULL: goto x86_l_1b91;
	case 7060ULL: goto x86_l_1b94;
	case 7062ULL: goto x86_l_1b96;
	case 7065ULL: goto x86_l_1b99;
	case 7071ULL: goto x86_l_1b9f;
	case 7074ULL: goto x86_l_1ba2;
	case 7076ULL: goto x86_l_1ba4;
	case 7081ULL: goto x86_l_1ba9;
	case 7084ULL: goto x86_l_1bac;
	case 7086ULL: goto x86_l_1bae;
	case 7089ULL: goto x86_l_1bb1;
	case 7095ULL: goto x86_l_1bb7;
	case 7098ULL: goto x86_l_1bba;
	case 7101ULL: goto x86_l_1bbd;
	case 7107ULL: goto x86_l_1bc3;
	case 7112ULL: goto x86_l_1bc8;
	case 7115ULL: goto x86_l_1bcb;
	case 7121ULL: goto x86_l_1bd1;
	case 7123ULL: goto x86_l_1bd3;
	case 7126ULL: goto x86_l_1bd6;
	case 7132ULL: goto x86_l_1bdc;
	case 7135ULL: goto x86_l_1bdf;
	case 7138ULL: goto x86_l_1be2;
	case 7144ULL: goto x86_l_1be8;
	case 7147ULL: goto x86_l_1beb;
	case 7153ULL: goto x86_l_1bf1;
	case 7156ULL: goto x86_l_1bf4;
	case 7162ULL: goto x86_l_1bfa;
	case 7165ULL: goto x86_l_1bfd;
	case 7171ULL: goto x86_l_1c03;
	case 7174ULL: goto x86_l_1c06;
	case 7180ULL: goto x86_l_1c0c;
	case 7183ULL: goto x86_l_1c0f;
	case 7189ULL: goto x86_l_1c15;
	case 7194ULL: goto x86_l_1c1a;
	case 7197ULL: goto x86_l_1c1d;
	case 7200ULL: goto x86_l_1c20;
	case 7206ULL: goto x86_l_1c26;
	case 7211ULL: goto x86_l_1c2b;
	case 7214ULL: goto x86_l_1c2e;
	case 7220ULL: goto x86_l_1c34;
	case 7222ULL: goto x86_l_1c36;
	case 7225ULL: goto x86_l_1c39;
	case 7231ULL: goto x86_l_1c3f;
	case 7234ULL: goto x86_l_1c42;
	case 7237ULL: goto x86_l_1c45;
	case 7243ULL: goto x86_l_1c4b;
	case 7246ULL: goto x86_l_1c4e;
	case 7252ULL: goto x86_l_1c54;
	case 7255ULL: goto x86_l_1c57;
	case 7261ULL: goto x86_l_1c5d;
	case 7264ULL: goto x86_l_1c60;
	case 7270ULL: goto x86_l_1c66;
	case 7273ULL: goto x86_l_1c69;
	case 7279ULL: goto x86_l_1c6f;
	case 7282ULL: goto x86_l_1c72;
	case 7288ULL: goto x86_l_1c78;
	case 7293ULL: goto x86_l_1c7d;
	case 7296ULL: goto x86_l_1c80;
	case 7299ULL: goto x86_l_1c83;
	case 7301ULL: goto x86_l_1c85;
	case 7304ULL: goto x86_l_1c88;
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
	case 7347ULL: goto x86_l_1cb3;
	case 7349ULL: goto x86_l_1cb5;
	case 7359ULL: goto x86_l_1cbf;
	case 7363ULL: goto x86_l_1cc3;
	case 7369ULL: goto x86_l_1cc9;
	case 7371ULL: goto x86_l_1ccb;
	case 7373ULL: goto x86_l_1ccd;
	case 7376ULL: goto x86_l_1cd0;
	case 7382ULL: goto x86_l_1cd6;
	case 7385ULL: goto x86_l_1cd9;
	case 7388ULL: goto x86_l_1cdc;
	case 7390ULL: goto x86_l_1cde;
	case 7393ULL: goto x86_l_1ce1;
	case 7399ULL: goto x86_l_1ce7;
	case 7402ULL: goto x86_l_1cea;
	case 7404ULL: goto x86_l_1cec;
	case 7407ULL: goto x86_l_1cef;
	case 7413ULL: goto x86_l_1cf5;
	case 7416ULL: goto x86_l_1cf8;
	case 7418ULL: goto x86_l_1cfa;
	case 7421ULL: goto x86_l_1cfd;
	case 7427ULL: goto x86_l_1d03;
	case 7429ULL: goto x86_l_1d05;
	case 7431ULL: goto x86_l_1d07;
	case 7434ULL: goto x86_l_1d0a;
	case 7440ULL: goto x86_l_1d10;
	case 7443ULL: goto x86_l_1d13;
	case 7446ULL: goto x86_l_1d16;
	case 7448ULL: goto x86_l_1d18;
	case 7451ULL: goto x86_l_1d1b;
	case 7457ULL: goto x86_l_1d21;
	case 7460ULL: goto x86_l_1d24;
	case 7462ULL: goto x86_l_1d26;
	case 7465ULL: goto x86_l_1d29;
	case 7471ULL: goto x86_l_1d2f;
	case 7474ULL: goto x86_l_1d32;
	case 7476ULL: goto x86_l_1d34;
	case 7479ULL: goto x86_l_1d37;
	case 7485ULL: goto x86_l_1d3d;
	case 7487ULL: goto x86_l_1d3f;
	case 7488ULL: goto x86_l_1d40;
	case 7491ULL: goto x86_l_1d43;
	case 7494ULL: goto x86_l_1d46;
	case 7497ULL: goto x86_l_1d49;
	case 7503ULL: goto x86_l_1d4f;
	case 7508ULL: goto x86_l_1d54;
	case 7511ULL: goto x86_l_1d57;
	case 7517ULL: goto x86_l_1d5d;
	case 7519ULL: goto x86_l_1d5f;
	case 7522ULL: goto x86_l_1d62;
	case 7524ULL: goto x86_l_1d64;
	case 7529ULL: goto x86_l_1d69;
	case 7532ULL: goto x86_l_1d6c;
	case 7534ULL: goto x86_l_1d6e;
	case 7537ULL: goto x86_l_1d71;
	case 7543ULL: goto x86_l_1d77;
	case 7546ULL: goto x86_l_1d7a;
	case 7549ULL: goto x86_l_1d7d;
	case 7555ULL: goto x86_l_1d83;
	case 7558ULL: goto x86_l_1d86;
	case 7560ULL: goto x86_l_1d88;
	case 7563ULL: goto x86_l_1d8b;
	case 7569ULL: goto x86_l_1d91;
	case 7572ULL: goto x86_l_1d94;
	case 7578ULL: goto x86_l_1d9a;
	case 7581ULL: goto x86_l_1d9d;
	case 7583ULL: goto x86_l_1d9f;
	case 7586ULL: goto x86_l_1da2;
	case 7592ULL: goto x86_l_1da8;
	case 7595ULL: goto x86_l_1dab;
	case 7601ULL: goto x86_l_1db1;
	case 7603ULL: goto x86_l_1db3;
	case 7606ULL: goto x86_l_1db6;
	case 7612ULL: goto x86_l_1dbc;
	case 7615ULL: goto x86_l_1dbf;
	case 7621ULL: goto x86_l_1dc5;
	case 7626ULL: goto x86_l_1dca;
	case 7629ULL: goto x86_l_1dcd;
	case 7632ULL: goto x86_l_1dd0;
	case 7636ULL: goto x86_l_1dd4;
	case 7639ULL: goto x86_l_1dd7;
	case 7642ULL: goto x86_l_1dda;
	case 7645ULL: goto x86_l_1ddd;
	case 7648ULL: goto x86_l_1de0;
	case 7654ULL: goto x86_l_1de6;
	case 7657ULL: goto x86_l_1de9;
	case 7661ULL: goto x86_l_1ded;
	case 7664ULL: goto x86_l_1df0;
	case 7668ULL: goto x86_l_1df4;
	case 7671ULL: goto x86_l_1df7;
	case 7674ULL: goto x86_l_1dfa;
	case 7677ULL: goto x86_l_1dfd;
	case 7683ULL: goto x86_l_1e03;
	case 7686ULL: goto x86_l_1e06;
	case 7690ULL: goto x86_l_1e0a;
	case 7693ULL: goto x86_l_1e0d;
	case 7697ULL: goto x86_l_1e11;
	case 7700ULL: goto x86_l_1e14;
	case 7703ULL: goto x86_l_1e17;
	case 7706ULL: goto x86_l_1e1a;
	case 7712ULL: goto x86_l_1e20;
	case 7715ULL: goto x86_l_1e23;
	case 7718ULL: goto x86_l_1e26;
	case 7721ULL: goto x86_l_1e29;
	case 7725ULL: goto x86_l_1e2d;
	case 7727ULL: goto x86_l_1e2f;
	case 7729ULL: goto x86_l_1e31;
	case 7732ULL: goto x86_l_1e34;
	case 7734ULL: goto x86_l_1e36;
	case 7739ULL: goto x86_l_1e3b;
	case 7742ULL: goto x86_l_1e3e;
	case 7744ULL: goto x86_l_1e40;
	case 7747ULL: goto x86_l_1e43;
	case 7749ULL: goto x86_l_1e45;
	case 7750ULL: goto x86_l_1e46;
	case 7753ULL: goto x86_l_1e49;
	case 7756ULL: goto x86_l_1e4c;
	case 7760ULL: goto x86_l_1e50;
	case 7763ULL: goto x86_l_1e53;
	case 7766ULL: goto x86_l_1e56;
	case 7769ULL: goto x86_l_1e59;
	case 7772ULL: goto x86_l_1e5c;
	case 7778ULL: goto x86_l_1e62;
	case 7781ULL: goto x86_l_1e65;
	case 7785ULL: goto x86_l_1e69;
	case 7788ULL: goto x86_l_1e6c;
	case 7792ULL: goto x86_l_1e70;
	case 7795ULL: goto x86_l_1e73;
	case 7798ULL: goto x86_l_1e76;
	case 7801ULL: goto x86_l_1e79;
	case 7803ULL: goto x86_l_1e7b;
	case 7806ULL: goto x86_l_1e7e;
	case 7810ULL: goto x86_l_1e82;
	case 7813ULL: goto x86_l_1e85;
	case 7817ULL: goto x86_l_1e89;
	case 7820ULL: goto x86_l_1e8c;
	case 7823ULL: goto x86_l_1e8f;
	case 7826ULL: goto x86_l_1e92;
	case 7828ULL: goto x86_l_1e94;
	case 7831ULL: goto x86_l_1e97;
	case 7834ULL: goto x86_l_1e9a;
	case 7837ULL: goto x86_l_1e9d;
	case 7841ULL: goto x86_l_1ea1;
	case 7844ULL: goto x86_l_1ea4;
	case 7847ULL: goto x86_l_1ea7;
	case 7849ULL: goto x86_l_1ea9;
	case 7852ULL: goto x86_l_1eac;
	case 7855ULL: goto x86_l_1eaf;
	case 7857ULL: goto x86_l_1eb1;
	case 7860ULL: goto x86_l_1eb4;
	case 7862ULL: goto x86_l_1eb6;
	case 7865ULL: goto x86_l_1eb9;
	case 7867ULL: goto x86_l_1ebb;
	case 7870ULL: goto x86_l_1ebe;
	case 7872ULL: goto x86_l_1ec0;
	case 7875ULL: goto x86_l_1ec3;
	case 7877ULL: goto x86_l_1ec5;
	case 7880ULL: goto x86_l_1ec8;
	case 7886ULL: goto x86_l_1ece;
	case 7889ULL: goto x86_l_1ed1;
	case 7891ULL: goto x86_l_1ed3;
	case 7893ULL: goto x86_l_1ed5;
	case 7896ULL: goto x86_l_1ed8;
	case 7898ULL: goto x86_l_1eda;
	case 7901ULL: goto x86_l_1edd;
	case 7907ULL: goto x86_l_1ee3;
	case 7909ULL: goto x86_l_1ee5;
	case 7911ULL: goto x86_l_1ee7;
	case 7914ULL: goto x86_l_1eea;
	case 7917ULL: goto x86_l_1eed;
	case 7920ULL: goto x86_l_1ef0;
	case 7922ULL: goto x86_l_1ef2;
	case 7925ULL: goto x86_l_1ef5;
	case 7926ULL: goto x86_l_1ef6;
	case 7928ULL: goto x86_l_1ef8;
	case 7929ULL: goto x86_l_1ef9;
	case 7933ULL: goto x86_l_1efd;
	case 7936ULL: goto x86_l_1f00;
	case 7939ULL: goto x86_l_1f03;
	case 7943ULL: goto x86_l_1f07;
	case 7947ULL: goto x86_l_1f0b;
	case 7954ULL: goto x86_l_1f12;
	case 7959ULL: goto x86_l_1f17;
	case 7964ULL: goto x86_l_1f1c;
	case 7966ULL: goto x86_l_1f1e;
	case 7969ULL: goto x86_l_1f21;
	case 7971ULL: goto x86_l_1f23;
	case 7974ULL: goto x86_l_1f26;
	case 7977ULL: goto x86_l_1f29;
	case 7982ULL: goto x86_l_1f2e;
	case 7987ULL: goto x86_l_1f33;
	case 7992ULL: goto x86_l_1f38;
	case 7994ULL: goto x86_l_1f3a;
	case 7997ULL: goto x86_l_1f3d;
	case 7999ULL: goto x86_l_1f3f;
	case 8002ULL: goto x86_l_1f42;
	case 8004ULL: goto x86_l_1f44;
	case 8009ULL: goto x86_l_1f49;
	case 8012ULL: goto x86_l_1f4c;
	case 8014ULL: goto x86_l_1f4e;
	case 8017ULL: goto x86_l_1f51;
	case 8020ULL: goto x86_l_1f54;
	case 8022ULL: goto x86_l_1f56;
	case 8024ULL: goto x86_l_1f58;
	case 8028ULL: goto x86_l_1f5c;
	case 8029ULL: goto x86_l_1f5d;
	case 8031ULL: goto x86_l_1f5f;
	case 8032ULL: goto x86_l_1f60;
	case 8037ULL: goto x86_l_1f65;
	case 8040ULL: goto x86_l_1f68;
	case 8042ULL: goto x86_l_1f6a;
	case 8045ULL: goto x86_l_1f6d;
	case 8048ULL: goto x86_l_1f70;
	case 8051ULL: goto x86_l_1f73;
	case 8055ULL: goto x86_l_1f77;
	case 8056ULL: goto x86_l_1f78;
	case 8058ULL: goto x86_l_1f7a;
	case 8059ULL: goto x86_l_1f7b;
	case 8062ULL: goto x86_l_1f7e;
	case 8067ULL: goto x86_l_1f83;
	case 8071ULL: goto x86_l_1f87;
	case 8073ULL: goto x86_l_1f89;
	case 8083ULL: goto x86_l_1f93;
	case 8087ULL: goto x86_l_1f97;
	case 8089ULL: goto x86_l_1f99;
	case 8090ULL: goto x86_l_1f9a;
	case 8095ULL: goto x86_l_1f9f;
	case 8099ULL: goto x86_l_1fa3;
	case 8101ULL: goto x86_l_1fa5;
	case 8104ULL: goto x86_l_1fa8;
	case 8107ULL: goto x86_l_1fab;
	case 8113ULL: goto x86_l_1fb1;
	case 8115ULL: goto x86_l_1fb3;
	case 8118ULL: goto x86_l_1fb6;
	case 8121ULL: goto x86_l_1fb9;
	case 8122ULL: goto x86_l_1fba;
	case 8126ULL: goto x86_l_1fbe;
	case 8128ULL: goto x86_l_1fc0;
	case 8131ULL: goto x86_l_1fc3;
	case 8134ULL: goto x86_l_1fc6;
	case 8136ULL: goto x86_l_1fc8;
	case 8139ULL: goto x86_l_1fcb;
	case 8142ULL: goto x86_l_1fce;
	case 8148ULL: goto x86_l_1fd4;
	case 8151ULL: goto x86_l_1fd7;
	case 8153ULL: goto x86_l_1fd9;
	case 8156ULL: goto x86_l_1fdc;
	case 8162ULL: goto x86_l_1fe2;
	case 8165ULL: goto x86_l_1fe5;
	case 8167ULL: goto x86_l_1fe7;
	case 8170ULL: goto x86_l_1fea;
	case 8176ULL: goto x86_l_1ff0;
	case 8179ULL: goto x86_l_1ff3;
	case 8181ULL: goto x86_l_1ff5;
	case 8186ULL: goto x86_l_1ffa;
	case 8189ULL: goto x86_l_1ffd;
	case 8191ULL: goto x86_l_1fff;
	case 8194ULL: goto x86_l_2002;
	case 8200ULL: goto x86_l_2008;
	case 8203ULL: goto x86_l_200b;
	case 8206ULL: goto x86_l_200e;
	case 8212ULL: goto x86_l_2014;
	case 8217ULL: goto x86_l_2019;
	case 8220ULL: goto x86_l_201c;
	case 8226ULL: goto x86_l_2022;
	case 8229ULL: goto x86_l_2025;
	case 8232ULL: goto x86_l_2028;
	case 8238ULL: goto x86_l_202e;
	case 8241ULL: goto x86_l_2031;
	case 8244ULL: goto x86_l_2034;
	case 8250ULL: goto x86_l_203a;
	case 8253ULL: goto x86_l_203d;
	case 8259ULL: goto x86_l_2043;
	case 8262ULL: goto x86_l_2046;
	case 8268ULL: goto x86_l_204c;
	case 8271ULL: goto x86_l_204f;
	case 8277ULL: goto x86_l_2055;
	case 8280ULL: goto x86_l_2058;
	case 8286ULL: goto x86_l_205e;
	case 8289ULL: goto x86_l_2061;
	case 8295ULL: goto x86_l_2067;
	case 8300ULL: goto x86_l_206c;
	case 8303ULL: goto x86_l_206f;
	case 8306ULL: goto x86_l_2072;
	case 8312ULL: goto x86_l_2078;
	case 8317ULL: goto x86_l_207d;
	case 8320ULL: goto x86_l_2080;
	case 8326ULL: goto x86_l_2086;
	case 8329ULL: goto x86_l_2089;
	case 8332ULL: goto x86_l_208c;
	case 8338ULL: goto x86_l_2092;
	case 8341ULL: goto x86_l_2095;
	case 8344ULL: goto x86_l_2098;
	case 8350ULL: goto x86_l_209e;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1b58:
	/* 0x1b58: cmp    edx,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_1b5b:
	/* 0x1b5b: jne    1c7d <filter_32ty_selector_val+0x151> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1c7d;
	}
x86_l_1b61:
	/* 0x1b61: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b63:
	/* 0x1b63: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1b66:
	/* 0x1b66: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_1b69:
	/* 0x1b69: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1b6a:
	/* 0x1b6a: cmp    rcx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 12ULL);
x86_l_1b6e:
	/* 0x1b6e: jne    1ba9 <filter_32ty_selector_val+0x7d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ba9;
	}
x86_l_1b70:
	/* 0x1b70: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b72:
	/* 0x1b72: test   DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b75:
	/* 0x1b75: jne    1b4a <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6986ULL;
	}
x86_l_1b77:
	/* 0x1b77: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b7a:
	/* 0x1b7a: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1b7d:
	/* 0x1b7d: jb     1d3d <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d3d;
	}
x86_l_1b83:
	/* 0x1b83: test   DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1b86:
	/* 0x1b86: jne    1b4a <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6986ULL;
	}
x86_l_1b88:
	/* 0x1b88: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1b8b:
	/* 0x1b8b: jb     1d3d <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d3d;
	}
x86_l_1b91:
	/* 0x1b91: test   DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b94:
	/* 0x1b94: jne    1b4a <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6986ULL;
	}
x86_l_1b96:
	/* 0x1b96: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_1b99:
	/* 0x1b99: jb     1d3d <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d3d;
	}
x86_l_1b9f:
	/* 0x1b9f: test   DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1ba2:
	/* 0x1ba2: jne    1b4a <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6986ULL;
	}
x86_l_1ba4:
	/* 0x1ba4: jmp    1d3d <filter_32ty_selector_val+0x211> */
	goto x86_l_1d3d;
x86_l_1ba9:
	/* 0x1ba9: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1bac:
	/* 0x1bac: je     1c1a <filter_32ty_selector_val+0xee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c1a;
	}
x86_l_1bae:
	/* 0x1bae: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1bb1:
	/* 0x1bb1: jne    1d3d <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d3d;
	}
x86_l_1bb7:
	/* 0x1bb7: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1bba:
	/* 0x1bba: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1bbd:
	/* 0x1bbd: ja     1d05 <filter_32ty_selector_val+0x1d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1d05;
	}
x86_l_1bc3:
	/* 0x1bc3: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_1bc8:
	/* 0x1bc8: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_1bcb:
	/* 0x1bcb: jae    1d05 <filter_32ty_selector_val+0x1d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1d05;
	}
x86_l_1bd1:
	/* 0x1bd1: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bd3:
	/* 0x1bd3: cmp    ecx,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_1bd6:
	/* 0x1bd6: jl     1b4a <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6986ULL;
	}
x86_l_1bdc:
	/* 0x1bdc: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bdf:
	/* 0x1bdf: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1be2:
	/* 0x1be2: jb     1d3d <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d3d;
	}
x86_l_1be8:
	/* 0x1be8: cmp    ecx,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1beb:
	/* 0x1beb: jl     1b4a <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6986ULL;
	}
x86_l_1bf1:
	/* 0x1bf1: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1bf4:
	/* 0x1bf4: jb     1d3d <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d3d;
	}
x86_l_1bfa:
	/* 0x1bfa: cmp    ecx,DWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 24ULL);
x86_l_1bfd:
	/* 0x1bfd: jl     1b4a <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6986ULL;
	}
x86_l_1c03:
	/* 0x1c03: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_1c06:
	/* 0x1c06: jb     1d3d <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d3d;
	}
x86_l_1c0c:
	/* 0x1c0c: cmp    ecx,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1c0f:
	/* 0x1c0f: jl     1b4a <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6986ULL;
	}
x86_l_1c15:
	/* 0x1c15: jmp    1d3d <filter_32ty_selector_val+0x211> */
	goto x86_l_1d3d;
x86_l_1c1a:
	/* 0x1c1a: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1c1d:
	/* 0x1c1d: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1c20:
	/* 0x1c20: ja     1ccb <filter_32ty_selector_val+0x19f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ccb;
	}
x86_l_1c26:
	/* 0x1c26: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_1c2b:
	/* 0x1c2b: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_1c2e:
	/* 0x1c2e: jae    1ccb <filter_32ty_selector_val+0x19f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1ccb;
	}
x86_l_1c34:
	/* 0x1c34: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c36:
	/* 0x1c36: cmp    ecx,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_1c39:
	/* 0x1c39: jg     1b4a <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6986ULL;
	}
x86_l_1c3f:
	/* 0x1c3f: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c42:
	/* 0x1c42: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1c45:
	/* 0x1c45: jb     1d3d <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d3d;
	}
x86_l_1c4b:
	/* 0x1c4b: cmp    ecx,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1c4e:
	/* 0x1c4e: jg     1b4a <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6986ULL;
	}
x86_l_1c54:
	/* 0x1c54: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1c57:
	/* 0x1c57: jb     1d3d <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d3d;
	}
x86_l_1c5d:
	/* 0x1c5d: cmp    ecx,DWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 24ULL);
x86_l_1c60:
	/* 0x1c60: jg     1b4a <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6986ULL;
	}
x86_l_1c66:
	/* 0x1c66: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_1c69:
	/* 0x1c69: jb     1d3d <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d3d;
	}
x86_l_1c6f:
	/* 0x1c6f: cmp    ecx,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1c72:
	/* 0x1c72: jg     1b4a <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6986ULL;
	}
x86_l_1c78:
	/* 0x1c78: jmp    1d3d <filter_32ty_selector_val+0x211> */
	goto x86_l_1d3d;
x86_l_1c7d:
	/* 0x1c7d: mov    esi,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c80:
	/* 0x1c80: cmp    esi,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 13ULL);
x86_l_1c83:
	/* 0x1c83: jb     1caa <filter_32ty_selector_val+0x17e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1caa;
	}
x86_l_1c85:
	/* 0x1c85: cmp    edx,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1c88:
	/* 0x1c88: je     1b61 <filter_32ty_selector_val+0x35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b61;
	}
x86_l_1c8e:
	/* 0x1c8e: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_1c91:
	/* 0x1c91: jb     1caa <filter_32ty_selector_val+0x17e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1caa;
	}
x86_l_1c93:
	/* 0x1c93: cmp    edx,DWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 24ULL);
x86_l_1c96:
	/* 0x1c96: je     1b61 <filter_32ty_selector_val+0x35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b61;
	}
x86_l_1c9c:
	/* 0x1c9c: cmp    esi,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 21ULL);
x86_l_1c9f:
	/* 0x1c9f: jb     1caa <filter_32ty_selector_val+0x17e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1caa;
	}
x86_l_1ca1:
	/* 0x1ca1: cmp    edx,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1ca4:
	/* 0x1ca4: je     1b61 <filter_32ty_selector_val+0x35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b61;
	}
x86_l_1caa:
	/* 0x1caa: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_1cad:
	/* 0x1cad: ja     1d3d <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1d3d;
	}
x86_l_1cb3:
	/* 0x1cb3: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1cb5:
	/* 0x1cb5: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_1cbf:
	/* 0x1cbf: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1cc3:
	/* 0x1cc3: jb     1b4a <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6986ULL;
	}
x86_l_1cc9:
	/* 0x1cc9: jmp    1d3d <filter_32ty_selector_val+0x211> */
	goto x86_l_1d3d;
x86_l_1ccb:
	/* 0x1ccb: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ccd:
	/* 0x1ccd: cmp    ecx,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_1cd0:
	/* 0x1cd0: ja     1b4a <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6986ULL;
	}
x86_l_1cd6:
	/* 0x1cd6: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cd9:
	/* 0x1cd9: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1cdc:
	/* 0x1cdc: jb     1d3d <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d3d;
	}
x86_l_1cde:
	/* 0x1cde: cmp    ecx,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1ce1:
	/* 0x1ce1: ja     1b4a <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6986ULL;
	}
x86_l_1ce7:
	/* 0x1ce7: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1cea:
	/* 0x1cea: jb     1d3d <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d3d;
	}
x86_l_1cec:
	/* 0x1cec: cmp    ecx,DWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 24ULL);
x86_l_1cef:
	/* 0x1cef: ja     1b4a <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6986ULL;
	}
x86_l_1cf5:
	/* 0x1cf5: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_1cf8:
	/* 0x1cf8: jb     1d3d <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d3d;
	}
x86_l_1cfa:
	/* 0x1cfa: cmp    ecx,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1cfd:
	/* 0x1cfd: ja     1b4a <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6986ULL;
	}
x86_l_1d03:
	/* 0x1d03: jmp    1d3d <filter_32ty_selector_val+0x211> */
	goto x86_l_1d3d;
x86_l_1d05:
	/* 0x1d05: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d07:
	/* 0x1d07: cmp    ecx,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_1d0a:
	/* 0x1d0a: jb     1b4a <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6986ULL;
	}
x86_l_1d10:
	/* 0x1d10: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d13:
	/* 0x1d13: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1d16:
	/* 0x1d16: jb     1d3d <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d3d;
	}
x86_l_1d18:
	/* 0x1d18: cmp    ecx,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1d1b:
	/* 0x1d1b: jb     1b4a <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6986ULL;
	}
x86_l_1d21:
	/* 0x1d21: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1d24:
	/* 0x1d24: jb     1d3d <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d3d;
	}
x86_l_1d26:
	/* 0x1d26: cmp    ecx,DWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 24ULL);
x86_l_1d29:
	/* 0x1d29: jb     1b4a <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6986ULL;
	}
x86_l_1d2f:
	/* 0x1d2f: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_1d32:
	/* 0x1d32: jb     1d3d <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d3d;
	}
x86_l_1d34:
	/* 0x1d34: cmp    ecx,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1d37:
	/* 0x1d37: jb     1b4a <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6986ULL;
	}
x86_l_1d3d:
	/* 0x1d3d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d3f:
	/* 0x1d3f: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1d40:
	/* 0x1d40: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d43:
	/* 0x1d43: mov    eax,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1d46:
	/* 0x1d46: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1d49:
	/* 0x1d49: ja     1e2f <filter_32ty_range+0xef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1e2f;
	}
x86_l_1d4f:
	/* 0x1d4f: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_1d54:
	/* 0x1d54: bt     edx,eax */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_1d57:
	/* 0x1d57: jae    1e2f <filter_32ty_range+0xef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1e2f;
	}
x86_l_1d5d:
	/* 0x1d5d: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d5f:
	/* 0x1d5f: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_1d62:
	/* 0x1d62: jne    1dca <filter_32ty_range+0x8a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1dca;
	}
x86_l_1d64:
	/* 0x1d64: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d69:
	/* 0x1d69: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d6c:
	/* 0x1d6c: jg     1d77 <filter_32ty_range+0x37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1d77;
	}
x86_l_1d6e:
	/* 0x1d6e: cmp    esi,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1d71:
	/* 0x1d71: jle    1e45 <filter_32ty_range+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1e45;
	}
x86_l_1d77:
	/* 0x1d77: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d7a:
	/* 0x1d7a: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1d7d:
	/* 0x1d7d: jb     1ee5 <filter_32ty_range+0x1a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1ee5;
	}
x86_l_1d83:
	/* 0x1d83: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d86:
	/* 0x1d86: jg     1d91 <filter_32ty_range+0x51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1d91;
	}
x86_l_1d88:
	/* 0x1d88: cmp    esi,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1d8b:
	/* 0x1d8b: jle    1e45 <filter_32ty_range+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1e45;
	}
x86_l_1d91:
	/* 0x1d91: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_1d94:
	/* 0x1d94: jb     1ee5 <filter_32ty_range+0x1a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1ee5;
	}
x86_l_1d9a:
	/* 0x1d9a: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d9d:
	/* 0x1d9d: jg     1da8 <filter_32ty_range+0x68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1da8;
	}
x86_l_1d9f:
	/* 0x1d9f: cmp    esi,DWORD PTR [rdi+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_1da2:
	/* 0x1da2: jle    1e45 <filter_32ty_range+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1e45;
	}
x86_l_1da8:
	/* 0x1da8: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_1dab:
	/* 0x1dab: jb     1ee5 <filter_32ty_range+0x1a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1ee5;
	}
x86_l_1db1:
	/* 0x1db1: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1db3:
	/* 0x1db3: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1db6:
	/* 0x1db6: jg     1ee7 <filter_32ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1ee7;
	}
x86_l_1dbc:
	/* 0x1dbc: cmp    esi,DWORD PTR [rdi+0x2c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 44ULL);
x86_l_1dbf:
	/* 0x1dbf: jle    1e45 <filter_32ty_range+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1e45;
	}
x86_l_1dc5:
	/* 0x1dc5: jmp    1ee7 <filter_32ty_range+0x1a7> */
	goto x86_l_1ee7;
x86_l_1dca:
	/* 0x1dca: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1dcd:
	/* 0x1dcd: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1dd0:
	/* 0x1dd0: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_1dd4:
	/* 0x1dd4: cmp    esi,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1dd7:
	/* 0x1dd7: setle  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_LE);
x86_l_1dda:
	/* 0x1dda: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1ddd:
	/* 0x1ddd: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1de0:
	/* 0x1de0: jb     1ee7 <filter_32ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1ee7;
	}
x86_l_1de6:
	/* 0x1de6: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1de9:
	/* 0x1de9: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_1ded:
	/* 0x1ded: cmp    esi,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1df0:
	/* 0x1df0: setle  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_LE);
x86_l_1df4:
	/* 0x1df4: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1df7:
	/* 0x1df7: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_1dfa:
	/* 0x1dfa: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1dfd:
	/* 0x1dfd: jb     1ee7 <filter_32ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1ee7;
	}
x86_l_1e03:
	/* 0x1e03: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e06:
	/* 0x1e06: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_1e0a:
	/* 0x1e0a: cmp    esi,DWORD PTR [rdi+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_1e0d:
	/* 0x1e0d: setle  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_LE);
x86_l_1e11:
	/* 0x1e11: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1e14:
	/* 0x1e14: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_1e17:
	/* 0x1e17: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_1e1a:
	/* 0x1e1a: jb     1ee7 <filter_32ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1ee7;
	}
x86_l_1e20:
	/* 0x1e20: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1e23:
	/* 0x1e23: setle  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_LE);
x86_l_1e26:
	/* 0x1e26: cmp    esi,DWORD PTR [rdi+0x2c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 44ULL);
x86_l_1e29:
	/* 0x1e29: setle  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_LE);
x86_l_1e2d:
	/* 0x1e2d: jmp    1ea1 <filter_32ty_range+0x161> */
	goto x86_l_1ea1;
x86_l_1e2f:
	/* 0x1e2f: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e31:
	/* 0x1e31: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_1e34:
	/* 0x1e34: jne    1e46 <filter_32ty_range+0x106> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e46;
	}
x86_l_1e36:
	/* 0x1e36: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1e3b:
	/* 0x1e3b: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e3e:
	/* 0x1e3e: ja     1ea9 <filter_32ty_range+0x169> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ea9;
	}
x86_l_1e40:
	/* 0x1e40: cmp    esi,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1e43:
	/* 0x1e43: ja     1ea9 <filter_32ty_range+0x169> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ea9;
	}
x86_l_1e45:
	/* 0x1e45: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1e46:
	/* 0x1e46: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e49:
	/* 0x1e49: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e4c:
	/* 0x1e4c: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_1e50:
	/* 0x1e50: cmp    esi,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1e53:
	/* 0x1e53: setbe  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_BE);
x86_l_1e56:
	/* 0x1e56: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1e59:
	/* 0x1e59: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1e5c:
	/* 0x1e5c: jb     1ee7 <filter_32ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1ee7;
	}
x86_l_1e62:
	/* 0x1e62: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1e65:
	/* 0x1e65: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_1e69:
	/* 0x1e69: cmp    esi,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1e6c:
	/* 0x1e6c: setbe  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_BE);
x86_l_1e70:
	/* 0x1e70: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1e73:
	/* 0x1e73: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_1e76:
	/* 0x1e76: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1e79:
	/* 0x1e79: jb     1ee7 <filter_32ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1ee7;
	}
x86_l_1e7b:
	/* 0x1e7b: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e7e:
	/* 0x1e7e: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_1e82:
	/* 0x1e82: cmp    esi,DWORD PTR [rdi+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_1e85:
	/* 0x1e85: setbe  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_BE);
x86_l_1e89:
	/* 0x1e89: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1e8c:
	/* 0x1e8c: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_1e8f:
	/* 0x1e8f: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_1e92:
	/* 0x1e92: jb     1ee7 <filter_32ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1ee7;
	}
x86_l_1e94:
	/* 0x1e94: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1e97:
	/* 0x1e97: setbe  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_BE);
x86_l_1e9a:
	/* 0x1e9a: cmp    esi,DWORD PTR [rdi+0x2c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 44ULL);
x86_l_1e9d:
	/* 0x1e9d: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_1ea1:
	/* 0x1ea1: and    sil,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_1ea4:
	/* 0x1ea4: or     dl,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_8, X86_ALU_OR);
x86_l_1ea7:
	/* 0x1ea7: jmp    1ee7 <filter_32ty_range+0x1a7> */
	goto x86_l_1ee7;
x86_l_1ea9:
	/* 0x1ea9: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1eac:
	/* 0x1eac: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1eaf:
	/* 0x1eaf: jb     1ee5 <filter_32ty_range+0x1a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1ee5;
	}
x86_l_1eb1:
	/* 0x1eb1: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1eb4:
	/* 0x1eb4: ja     1ebb <filter_32ty_range+0x17b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ebb;
	}
x86_l_1eb6:
	/* 0x1eb6: cmp    esi,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1eb9:
	/* 0x1eb9: jbe    1e45 <filter_32ty_range+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1e45;
	}
x86_l_1ebb:
	/* 0x1ebb: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_1ebe:
	/* 0x1ebe: jb     1ee5 <filter_32ty_range+0x1a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1ee5;
	}
x86_l_1ec0:
	/* 0x1ec0: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ec3:
	/* 0x1ec3: ja     1ece <filter_32ty_range+0x18e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ece;
	}
x86_l_1ec5:
	/* 0x1ec5: cmp    esi,DWORD PTR [rdi+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_1ec8:
	/* 0x1ec8: jbe    1e45 <filter_32ty_range+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1e45;
	}
x86_l_1ece:
	/* 0x1ece: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_1ed1:
	/* 0x1ed1: jb     1ee5 <filter_32ty_range+0x1a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1ee5;
	}
x86_l_1ed3:
	/* 0x1ed3: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ed5:
	/* 0x1ed5: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1ed8:
	/* 0x1ed8: ja     1ee7 <filter_32ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ee7;
	}
x86_l_1eda:
	/* 0x1eda: cmp    esi,DWORD PTR [rdi+0x2c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 44ULL);
x86_l_1edd:
	/* 0x1edd: jbe    1e45 <filter_32ty_range+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1e45;
	}
x86_l_1ee3:
	/* 0x1ee3: jmp    1ee7 <filter_32ty_range+0x1a7> */
	goto x86_l_1ee7;
x86_l_1ee5:
	/* 0x1ee5: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ee7:
	/* 0x1ee7: cmp    ecx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 32ULL);
x86_l_1eea:
	/* 0x1eea: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_1eed:
	/* 0x1eed: xor    dl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_1ef0:
	/* 0x1ef0: and    dl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_1ef2:
	/* 0x1ef2: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1ef5:
	/* 0x1ef5: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1ef6:
	/* 0x1ef6: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_1ef8:
	/* 0x1ef8: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_1ef9:
	/* 0x1ef9: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_1efd:
	/* 0x1efd: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_1f00:
	/* 0x1f00: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_1f03:
	/* 0x1f03: movzx  eax,BYTE PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1f07:
	/* 0x1f07: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1f0b:
	/* 0x1f0b: mov    rdi,QWORD PTR [rip+0x9b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_1f12:
	/* 0x1f12: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1f17:
	/* 0x1f17: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f1c:
	/* 0x1f1c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f1e:
	/* 0x1f1e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f21:
	/* 0x1f21: je     1f56 <filter_32ty_map+0x60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f56;
	}
x86_l_1f23:
	/* 0x1f23: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1f26:
	/* 0x1f26: mov    eax,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f29:
	/* 0x1f29: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f2e:
	/* 0x1f2e: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f33:
	/* 0x1f33: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f38:
	/* 0x1f38: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f3a:
	/* 0x1f3a: mov    edx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1f3d:
	/* 0x1f3d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f3f:
	/* 0x1f3f: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_1f42:
	/* 0x1f42: ja     1f70 <filter_32ty_map+0x7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1f70;
	}
x86_l_1f44:
	/* 0x1f44: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_1f49:
	/* 0x1f49: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1f4c:
	/* 0x1f4c: jae    1f60 <filter_32ty_map+0x6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1f60;
	}
x86_l_1f4e:
	/* 0x1f4e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f51:
	/* 0x1f51: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_1f54:
	/* 0x1f54: jmp    1f70 <filter_32ty_map+0x7a> */
	goto x86_l_1f70;
x86_l_1f56:
	/* 0x1f56: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f58:
	/* 0x1f58: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1f5c:
	/* 0x1f5c: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1f5d:
	/* 0x1f5d: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_1f5f:
	/* 0x1f5f: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1f60:
	/* 0x1f60: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_1f65:
	/* 0x1f65: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1f68:
	/* 0x1f68: jae    1f70 <filter_32ty_map+0x7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1f70;
	}
x86_l_1f6a:
	/* 0x1f6a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f6d:
	/* 0x1f6d: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_1f70:
	/* 0x1f70: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1f73:
	/* 0x1f73: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1f77:
	/* 0x1f77: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1f78:
	/* 0x1f78: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_1f7a:
	/* 0x1f7a: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1f7b:
	/* 0x1f7b: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1f7e:
	/* 0x1f7e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f83:
	/* 0x1f83: cmp    rcx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 37ULL);
x86_l_1f87:
	/* 0x1f87: ja     1ffa <filter_8ty_selector_val+0x7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ffa;
	}
x86_l_1f89:
	/* 0x1f89: movabs rdx,0x200c000040 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280128ULL);
x86_l_1f93:
	/* 0x1f93: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1f97:
	/* 0x1f97: jae    1f9a <filter_8ty_selector_val+0x1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1f9a;
	}
x86_l_1f99:
	/* 0x1f99: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1f9a:
	/* 0x1f9a: mov    edx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 24ULL);
x86_l_1f9f:
	/* 0x1f9f: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1fa3:
	/* 0x1fa3: jae    1fba <filter_8ty_selector_val+0x3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1fba;
	}
x86_l_1fa5:
	/* 0x1fa5: movzx  edx,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1fa8:
	/* 0x1fa8: cmp    DWORD PTR [rdi+0x10],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fab:
	/* 0x1fab: jne    20d0 <filter_8ty_selector_val+0x155> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8400ULL;
	}
x86_l_1fb1:
	/* 0x1fb1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fb3:
	/* 0x1fb3: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1fb6:
	/* 0x1fb6: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_1fb9:
	/* 0x1fb9: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1fba:
	/* 0x1fba: cmp    rcx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 12ULL);
x86_l_1fbe:
	/* 0x1fbe: jne    1ffa <filter_8ty_selector_val+0x7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ffa;
	}
x86_l_1fc0:
	/* 0x1fc0: movzx  ecx,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1fc3:
	/* 0x1fc3: test   DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fc6:
	/* 0x1fc6: jne    1f99 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f99;
	}
x86_l_1fc8:
	/* 0x1fc8: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1fcb:
	/* 0x1fcb: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1fce:
	/* 0x1fce: jb     2192 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8594ULL;
	}
x86_l_1fd4:
	/* 0x1fd4: test   DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1fd7:
	/* 0x1fd7: jne    1f99 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f99;
	}
x86_l_1fd9:
	/* 0x1fd9: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1fdc:
	/* 0x1fdc: jb     2192 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8594ULL;
	}
x86_l_1fe2:
	/* 0x1fe2: test   DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1fe5:
	/* 0x1fe5: jne    1f99 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f99;
	}
x86_l_1fe7:
	/* 0x1fe7: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_1fea:
	/* 0x1fea: jb     2192 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8594ULL;
	}
x86_l_1ff0:
	/* 0x1ff0: test   DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1ff3:
	/* 0x1ff3: jne    1f99 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f99;
	}
x86_l_1ff5:
	/* 0x1ff5: jmp    2192 <filter_8ty_selector_val+0x217> */
	return 8594ULL;
x86_l_1ffa:
	/* 0x1ffa: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1ffd:
	/* 0x1ffd: je     206c <filter_8ty_selector_val+0xf1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_206c;
	}
x86_l_1fff:
	/* 0x1fff: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2002:
	/* 0x2002: jne    2192 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8594ULL;
	}
x86_l_2008:
	/* 0x2008: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_200b:
	/* 0x200b: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_200e:
	/* 0x200e: ja     2159 <filter_8ty_selector_val+0x1de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8537ULL;
	}
x86_l_2014:
	/* 0x2014: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_2019:
	/* 0x2019: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_201c:
	/* 0x201c: jae    2159 <filter_8ty_selector_val+0x1de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8537ULL;
	}
x86_l_2022:
	/* 0x2022: movsx  ecx,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2025:
	/* 0x2025: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2028:
	/* 0x2028: jg     1f99 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1f99;
	}
x86_l_202e:
	/* 0x202e: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2031:
	/* 0x2031: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_2034:
	/* 0x2034: jb     2192 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8594ULL;
	}
x86_l_203a:
	/* 0x203a: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_203d:
	/* 0x203d: jg     1f99 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1f99;
	}
x86_l_2043:
	/* 0x2043: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_2046:
	/* 0x2046: jb     2192 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8594ULL;
	}
x86_l_204c:
	/* 0x204c: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_204f:
	/* 0x204f: jg     1f99 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1f99;
	}
x86_l_2055:
	/* 0x2055: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_2058:
	/* 0x2058: jb     2192 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8594ULL;
	}
x86_l_205e:
	/* 0x205e: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2061:
	/* 0x2061: jg     1f99 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1f99;
	}
x86_l_2067:
	/* 0x2067: jmp    2192 <filter_8ty_selector_val+0x217> */
	return 8594ULL;
x86_l_206c:
	/* 0x206c: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_206f:
	/* 0x206f: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2072:
	/* 0x2072: ja     211e <filter_8ty_selector_val+0x1a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8478ULL;
	}
x86_l_2078:
	/* 0x2078: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_207d:
	/* 0x207d: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_2080:
	/* 0x2080: jae    211e <filter_8ty_selector_val+0x1a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8478ULL;
	}
x86_l_2086:
	/* 0x2086: movsx  ecx,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2089:
	/* 0x2089: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_208c:
	/* 0x208c: jl     1f99 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_1f99;
	}
x86_l_2092:
	/* 0x2092: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2095:
	/* 0x2095: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_2098:
	/* 0x2098: jb     2192 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8594ULL;
	}
x86_l_209e:
	/* 0x209e: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
	return 8353ULL;
}

static __noinline __u64 tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_filter_arg_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8353ULL: goto x86_l_20a1;
	case 8359ULL: goto x86_l_20a7;
	case 8362ULL: goto x86_l_20aa;
	case 8368ULL: goto x86_l_20b0;
	case 8371ULL: goto x86_l_20b3;
	case 8377ULL: goto x86_l_20b9;
	case 8380ULL: goto x86_l_20bc;
	case 8386ULL: goto x86_l_20c2;
	case 8389ULL: goto x86_l_20c5;
	case 8395ULL: goto x86_l_20cb;
	case 8400ULL: goto x86_l_20d0;
	case 8403ULL: goto x86_l_20d3;
	case 8406ULL: goto x86_l_20d6;
	case 8408ULL: goto x86_l_20d8;
	case 8411ULL: goto x86_l_20db;
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
	case 8454ULL: goto x86_l_2106;
	case 8456ULL: goto x86_l_2108;
	case 8466ULL: goto x86_l_2112;
	case 8470ULL: goto x86_l_2116;
	case 8476ULL: goto x86_l_211c;
	case 8478ULL: goto x86_l_211e;
	case 8481ULL: goto x86_l_2121;
	case 8484ULL: goto x86_l_2124;
	case 8490ULL: goto x86_l_212a;
	case 8493ULL: goto x86_l_212d;
	case 8496ULL: goto x86_l_2130;
	case 8498ULL: goto x86_l_2132;
	case 8501ULL: goto x86_l_2135;
	case 8507ULL: goto x86_l_213b;
	case 8510ULL: goto x86_l_213e;
	case 8512ULL: goto x86_l_2140;
	case 8515ULL: goto x86_l_2143;
	case 8521ULL: goto x86_l_2149;
	case 8524ULL: goto x86_l_214c;
	case 8526ULL: goto x86_l_214e;
	case 8529ULL: goto x86_l_2151;
	case 8535ULL: goto x86_l_2157;
	case 8537ULL: goto x86_l_2159;
	case 8540ULL: goto x86_l_215c;
	case 8543ULL: goto x86_l_215f;
	case 8549ULL: goto x86_l_2165;
	case 8552ULL: goto x86_l_2168;
	case 8555ULL: goto x86_l_216b;
	case 8557ULL: goto x86_l_216d;
	case 8560ULL: goto x86_l_2170;
	case 8566ULL: goto x86_l_2176;
	case 8569ULL: goto x86_l_2179;
	case 8571ULL: goto x86_l_217b;
	case 8574ULL: goto x86_l_217e;
	case 8580ULL: goto x86_l_2184;
	case 8583ULL: goto x86_l_2187;
	case 8585ULL: goto x86_l_2189;
	case 8588ULL: goto x86_l_218c;
	case 8594ULL: goto x86_l_2192;
	case 8596ULL: goto x86_l_2194;
	case 8597ULL: goto x86_l_2195;
	case 8600ULL: goto x86_l_2198;
	case 8603ULL: goto x86_l_219b;
	case 8606ULL: goto x86_l_219e;
	case 8612ULL: goto x86_l_21a4;
	case 8617ULL: goto x86_l_21a9;
	case 8620ULL: goto x86_l_21ac;
	case 8626ULL: goto x86_l_21b2;
	case 8629ULL: goto x86_l_21b5;
	case 8632ULL: goto x86_l_21b8;
	case 8634ULL: goto x86_l_21ba;
	case 8639ULL: goto x86_l_21bf;
	case 8642ULL: goto x86_l_21c2;
	case 8644ULL: goto x86_l_21c4;
	case 8647ULL: goto x86_l_21c7;
	case 8653ULL: goto x86_l_21cd;
	case 8656ULL: goto x86_l_21d0;
	case 8659ULL: goto x86_l_21d3;
	case 8665ULL: goto x86_l_21d9;
	case 8668ULL: goto x86_l_21dc;
	case 8670ULL: goto x86_l_21de;
	case 8673ULL: goto x86_l_21e1;
	case 8679ULL: goto x86_l_21e7;
	case 8682ULL: goto x86_l_21ea;
	case 8688ULL: goto x86_l_21f0;
	case 8691ULL: goto x86_l_21f3;
	case 8693ULL: goto x86_l_21f5;
	case 8696ULL: goto x86_l_21f8;
	case 8702ULL: goto x86_l_21fe;
	case 8705ULL: goto x86_l_2201;
	case 8711ULL: goto x86_l_2207;
	case 8713ULL: goto x86_l_2209;
	case 8716ULL: goto x86_l_220c;
	case 8722ULL: goto x86_l_2212;
	case 8725ULL: goto x86_l_2215;
	case 8731ULL: goto x86_l_221b;
	case 8736ULL: goto x86_l_2220;
	case 8739ULL: goto x86_l_2223;
	case 8742ULL: goto x86_l_2226;
	case 8746ULL: goto x86_l_222a;
	case 8749ULL: goto x86_l_222d;
	case 8752ULL: goto x86_l_2230;
	case 8755ULL: goto x86_l_2233;
	case 8758ULL: goto x86_l_2236;
	case 8764ULL: goto x86_l_223c;
	case 8767ULL: goto x86_l_223f;
	case 8771ULL: goto x86_l_2243;
	case 8774ULL: goto x86_l_2246;
	case 8778ULL: goto x86_l_224a;
	case 8781ULL: goto x86_l_224d;
	case 8784ULL: goto x86_l_2250;
	case 8787ULL: goto x86_l_2253;
	case 8793ULL: goto x86_l_2259;
	case 8796ULL: goto x86_l_225c;
	case 8800ULL: goto x86_l_2260;
	case 8803ULL: goto x86_l_2263;
	case 8807ULL: goto x86_l_2267;
	case 8810ULL: goto x86_l_226a;
	case 8813ULL: goto x86_l_226d;
	case 8816ULL: goto x86_l_2270;
	case 8822ULL: goto x86_l_2276;
	case 8825ULL: goto x86_l_2279;
	case 8828ULL: goto x86_l_227c;
	case 8831ULL: goto x86_l_227f;
	case 8835ULL: goto x86_l_2283;
	case 8837ULL: goto x86_l_2285;
	case 8840ULL: goto x86_l_2288;
	case 8843ULL: goto x86_l_228b;
	case 8845ULL: goto x86_l_228d;
	case 8850ULL: goto x86_l_2292;
	case 8853ULL: goto x86_l_2295;
	case 8855ULL: goto x86_l_2297;
	case 8858ULL: goto x86_l_229a;
	case 8860ULL: goto x86_l_229c;
	case 8861ULL: goto x86_l_229d;
	case 8864ULL: goto x86_l_22a0;
	case 8867ULL: goto x86_l_22a3;
	case 8871ULL: goto x86_l_22a7;
	case 8874ULL: goto x86_l_22aa;
	case 8877ULL: goto x86_l_22ad;
	case 8880ULL: goto x86_l_22b0;
	case 8883ULL: goto x86_l_22b3;
	case 8889ULL: goto x86_l_22b9;
	case 8892ULL: goto x86_l_22bc;
	case 8896ULL: goto x86_l_22c0;
	case 8899ULL: goto x86_l_22c3;
	case 8903ULL: goto x86_l_22c7;
	case 8906ULL: goto x86_l_22ca;
	case 8909ULL: goto x86_l_22cd;
	case 8912ULL: goto x86_l_22d0;
	case 8914ULL: goto x86_l_22d2;
	case 8917ULL: goto x86_l_22d5;
	case 8921ULL: goto x86_l_22d9;
	case 8924ULL: goto x86_l_22dc;
	case 8928ULL: goto x86_l_22e0;
	case 8931ULL: goto x86_l_22e3;
	case 8934ULL: goto x86_l_22e6;
	case 8937ULL: goto x86_l_22e9;
	case 8939ULL: goto x86_l_22eb;
	case 8942ULL: goto x86_l_22ee;
	case 8945ULL: goto x86_l_22f1;
	case 8948ULL: goto x86_l_22f4;
	case 8952ULL: goto x86_l_22f8;
	case 8955ULL: goto x86_l_22fb;
	case 8958ULL: goto x86_l_22fe;
	case 8960ULL: goto x86_l_2300;
	case 8963ULL: goto x86_l_2303;
	case 8966ULL: goto x86_l_2306;
	case 8968ULL: goto x86_l_2308;
	case 8971ULL: goto x86_l_230b;
	case 8973ULL: goto x86_l_230d;
	case 8976ULL: goto x86_l_2310;
	case 8978ULL: goto x86_l_2312;
	case 8981ULL: goto x86_l_2315;
	case 8983ULL: goto x86_l_2317;
	case 8986ULL: goto x86_l_231a;
	case 8988ULL: goto x86_l_231c;
	case 8991ULL: goto x86_l_231f;
	case 8997ULL: goto x86_l_2325;
	case 9000ULL: goto x86_l_2328;
	case 9002ULL: goto x86_l_232a;
	case 9004ULL: goto x86_l_232c;
	case 9007ULL: goto x86_l_232f;
	case 9009ULL: goto x86_l_2331;
	case 9012ULL: goto x86_l_2334;
	case 9018ULL: goto x86_l_233a;
	case 9020ULL: goto x86_l_233c;
	case 9022ULL: goto x86_l_233e;
	case 9025ULL: goto x86_l_2341;
	case 9028ULL: goto x86_l_2344;
	case 9031ULL: goto x86_l_2347;
	case 9033ULL: goto x86_l_2349;
	case 9036ULL: goto x86_l_234c;
	case 9037ULL: goto x86_l_234d;
	case 9039ULL: goto x86_l_234f;
	case 9040ULL: goto x86_l_2350;
	case 9044ULL: goto x86_l_2354;
	case 9047ULL: goto x86_l_2357;
	case 9050ULL: goto x86_l_235a;
	case 9054ULL: goto x86_l_235e;
	case 9058ULL: goto x86_l_2362;
	case 9065ULL: goto x86_l_2369;
	case 9070ULL: goto x86_l_236e;
	case 9075ULL: goto x86_l_2373;
	case 9077ULL: goto x86_l_2375;
	case 9080ULL: goto x86_l_2378;
	case 9082ULL: goto x86_l_237a;
	case 9085ULL: goto x86_l_237d;
	case 9089ULL: goto x86_l_2381;
	case 9094ULL: goto x86_l_2386;
	case 9099ULL: goto x86_l_238b;
	case 9104ULL: goto x86_l_2390;
	case 9106ULL: goto x86_l_2392;
	case 9109ULL: goto x86_l_2395;
	case 9111ULL: goto x86_l_2397;
	case 9114ULL: goto x86_l_239a;
	case 9116ULL: goto x86_l_239c;
	case 9121ULL: goto x86_l_23a1;
	case 9124ULL: goto x86_l_23a4;
	case 9126ULL: goto x86_l_23a6;
	case 9129ULL: goto x86_l_23a9;
	case 9132ULL: goto x86_l_23ac;
	case 9134ULL: goto x86_l_23ae;
	case 9136ULL: goto x86_l_23b0;
	case 9140ULL: goto x86_l_23b4;
	case 9141ULL: goto x86_l_23b5;
	case 9143ULL: goto x86_l_23b7;
	case 9144ULL: goto x86_l_23b8;
	case 9149ULL: goto x86_l_23bd;
	case 9152ULL: goto x86_l_23c0;
	case 9154ULL: goto x86_l_23c2;
	case 9157ULL: goto x86_l_23c5;
	case 9160ULL: goto x86_l_23c8;
	case 9163ULL: goto x86_l_23cb;
	case 9167ULL: goto x86_l_23cf;
	case 9168ULL: goto x86_l_23d0;
	case 9170ULL: goto x86_l_23d2;
	case 9171ULL: goto x86_l_23d3;
	case 9172ULL: goto x86_l_23d4;
	case 9176ULL: goto x86_l_23d8;
	case 9183ULL: goto x86_l_23df;
	case 9185ULL: goto x86_l_23e1;
	case 9191ULL: goto x86_l_23e7;
	case 9197ULL: goto x86_l_23ed;
	case 9200ULL: goto x86_l_23f0;
	case 9204ULL: goto x86_l_23f4;
	case 9208ULL: goto x86_l_23f8;
	case 9213ULL: goto x86_l_23fd;
	case 9218ULL: goto x86_l_2402;
	case 9223ULL: goto x86_l_2407;
	case 9225ULL: goto x86_l_2409;
	case 9229ULL: goto x86_l_240d;
	case 9233ULL: goto x86_l_2411;
	case 9238ULL: goto x86_l_2416;
	case 9240ULL: goto x86_l_2418;
	case 9243ULL: goto x86_l_241b;
	case 9245ULL: goto x86_l_241d;
	case 9247ULL: goto x86_l_241f;
	case 9252ULL: goto x86_l_2424;
	case 9258ULL: goto x86_l_242a;
	case 9263ULL: goto x86_l_242f;
	case 9265ULL: goto x86_l_2431;
	case 9267ULL: goto x86_l_2433;
	case 9270ULL: goto x86_l_2436;
	case 9273ULL: goto x86_l_2439;
	case 9275ULL: goto x86_l_243b;
	case 9278ULL: goto x86_l_243e;
	case 9280ULL: goto x86_l_2440;
	case 9282ULL: goto x86_l_2442;
	case 9284ULL: goto x86_l_2444;
	case 9286ULL: goto x86_l_2446;
	case 9289ULL: goto x86_l_2449;
	case 9291ULL: goto x86_l_244b;
	case 9294ULL: goto x86_l_244e;
	case 9296ULL: goto x86_l_2450;
	case 9298ULL: goto x86_l_2452;
	case 9300ULL: goto x86_l_2454;
	case 9302ULL: goto x86_l_2456;
	case 9305ULL: goto x86_l_2459;
	case 9307ULL: goto x86_l_245b;
	case 9310ULL: goto x86_l_245e;
	case 9312ULL: goto x86_l_2460;
	case 9314ULL: goto x86_l_2462;
	case 9316ULL: goto x86_l_2464;
	case 9318ULL: goto x86_l_2466;
	case 9321ULL: goto x86_l_2469;
	case 9325ULL: goto x86_l_246d;
	case 9326ULL: goto x86_l_246e;
	case 9327ULL: goto x86_l_246f;
	case 9329ULL: goto x86_l_2471;
	case 9333ULL: goto x86_l_2475;
	case 9334ULL: goto x86_l_2476;
	default: return 0xffffffffffffffffULL;
	}
x86_l_20a1:
	/* 0x20a1: jl     1f99 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 8089ULL;
	}
x86_l_20a7:
	/* 0x20a7: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_20aa:
	/* 0x20aa: jb     2192 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2192;
	}
x86_l_20b0:
	/* 0x20b0: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_20b3:
	/* 0x20b3: jl     1f99 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 8089ULL;
	}
x86_l_20b9:
	/* 0x20b9: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_20bc:
	/* 0x20bc: jb     2192 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2192;
	}
x86_l_20c2:
	/* 0x20c2: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_20c5:
	/* 0x20c5: jl     1f99 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 8089ULL;
	}
x86_l_20cb:
	/* 0x20cb: jmp    2192 <filter_8ty_selector_val+0x217> */
	goto x86_l_2192;
x86_l_20d0:
	/* 0x20d0: mov    esi,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20d3:
	/* 0x20d3: cmp    esi,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 13ULL);
x86_l_20d6:
	/* 0x20d6: jb     20fd <filter_8ty_selector_val+0x182> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_20fd;
	}
x86_l_20d8:
	/* 0x20d8: cmp    DWORD PTR [rdi+0x14],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_20db:
	/* 0x20db: je     1fb1 <filter_8ty_selector_val+0x36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8113ULL;
	}
x86_l_20e1:
	/* 0x20e1: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_20e4:
	/* 0x20e4: jb     20fd <filter_8ty_selector_val+0x182> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_20fd;
	}
x86_l_20e6:
	/* 0x20e6: cmp    DWORD PTR [rdi+0x18],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_20e9:
	/* 0x20e9: je     1fb1 <filter_8ty_selector_val+0x36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8113ULL;
	}
x86_l_20ef:
	/* 0x20ef: cmp    esi,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 21ULL);
x86_l_20f2:
	/* 0x20f2: jb     20fd <filter_8ty_selector_val+0x182> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_20fd;
	}
x86_l_20f4:
	/* 0x20f4: cmp    DWORD PTR [rdi+0x1c],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_20f7:
	/* 0x20f7: je     1fb1 <filter_8ty_selector_val+0x36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8113ULL;
	}
x86_l_20fd:
	/* 0x20fd: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_2100:
	/* 0x2100: ja     2192 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2192;
	}
x86_l_2106:
	/* 0x2106: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2108:
	/* 0x2108: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_2112:
	/* 0x2112: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_2116:
	/* 0x2116: jb     1f99 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8089ULL;
	}
x86_l_211c:
	/* 0x211c: jmp    2192 <filter_8ty_selector_val+0x217> */
	goto x86_l_2192;
x86_l_211e:
	/* 0x211e: movzx  ecx,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2121:
	/* 0x2121: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2124:
	/* 0x2124: jb     1f99 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8089ULL;
	}
x86_l_212a:
	/* 0x212a: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_212d:
	/* 0x212d: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_2130:
	/* 0x2130: jb     2192 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2192;
	}
x86_l_2132:
	/* 0x2132: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2135:
	/* 0x2135: jb     1f99 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8089ULL;
	}
x86_l_213b:
	/* 0x213b: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_213e:
	/* 0x213e: jb     2192 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2192;
	}
x86_l_2140:
	/* 0x2140: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2143:
	/* 0x2143: jb     1f99 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8089ULL;
	}
x86_l_2149:
	/* 0x2149: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_214c:
	/* 0x214c: jb     2192 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2192;
	}
x86_l_214e:
	/* 0x214e: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2151:
	/* 0x2151: jb     1f99 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8089ULL;
	}
x86_l_2157:
	/* 0x2157: jmp    2192 <filter_8ty_selector_val+0x217> */
	goto x86_l_2192;
x86_l_2159:
	/* 0x2159: movzx  ecx,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_215c:
	/* 0x215c: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_215f:
	/* 0x215f: ja     1f99 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8089ULL;
	}
x86_l_2165:
	/* 0x2165: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2168:
	/* 0x2168: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_216b:
	/* 0x216b: jb     2192 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2192;
	}
x86_l_216d:
	/* 0x216d: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2170:
	/* 0x2170: ja     1f99 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8089ULL;
	}
x86_l_2176:
	/* 0x2176: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_2179:
	/* 0x2179: jb     2192 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2192;
	}
x86_l_217b:
	/* 0x217b: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_217e:
	/* 0x217e: ja     1f99 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8089ULL;
	}
x86_l_2184:
	/* 0x2184: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_2187:
	/* 0x2187: jb     2192 <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2192;
	}
x86_l_2189:
	/* 0x2189: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_218c:
	/* 0x218c: ja     1f99 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8089ULL;
	}
x86_l_2192:
	/* 0x2192: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2194:
	/* 0x2194: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_2195:
	/* 0x2195: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2198:
	/* 0x2198: mov    eax,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_219b:
	/* 0x219b: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_219e:
	/* 0x219e: ja     2285 <filter_8ty_range+0xf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2285;
	}
x86_l_21a4:
	/* 0x21a4: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_21a9:
	/* 0x21a9: bt     edx,eax */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_21ac:
	/* 0x21ac: jae    2285 <filter_8ty_range+0xf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2285;
	}
x86_l_21b2:
	/* 0x21b2: movsx  esi,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_21b5:
	/* 0x21b5: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_21b8:
	/* 0x21b8: jne    2220 <filter_8ty_range+0x8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2220;
	}
x86_l_21ba:
	/* 0x21ba: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_21bf:
	/* 0x21bf: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21c2:
	/* 0x21c2: jg     21cd <filter_8ty_range+0x38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_21cd;
	}
x86_l_21c4:
	/* 0x21c4: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_21c7:
	/* 0x21c7: jge    229c <filter_8ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_GE)) {
		goto x86_l_229c;
	}
x86_l_21cd:
	/* 0x21cd: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21d0:
	/* 0x21d0: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_21d3:
	/* 0x21d3: jb     233c <filter_8ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_233c;
	}
x86_l_21d9:
	/* 0x21d9: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_21dc:
	/* 0x21dc: jg     21e7 <filter_8ty_range+0x52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_21e7;
	}
x86_l_21de:
	/* 0x21de: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_21e1:
	/* 0x21e1: jge    229c <filter_8ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_GE)) {
		goto x86_l_229c;
	}
x86_l_21e7:
	/* 0x21e7: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_21ea:
	/* 0x21ea: jb     233c <filter_8ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_233c;
	}
x86_l_21f0:
	/* 0x21f0: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_21f3:
	/* 0x21f3: jg     21fe <filter_8ty_range+0x69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_21fe;
	}
x86_l_21f5:
	/* 0x21f5: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_21f8:
	/* 0x21f8: jge    229c <filter_8ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_GE)) {
		goto x86_l_229c;
	}
x86_l_21fe:
	/* 0x21fe: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_2201:
	/* 0x2201: jb     233c <filter_8ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_233c;
	}
x86_l_2207:
	/* 0x2207: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2209:
	/* 0x2209: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_220c:
	/* 0x220c: jg     233e <filter_8ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_233e;
	}
x86_l_2212:
	/* 0x2212: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2215:
	/* 0x2215: jge    229c <filter_8ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_GE)) {
		goto x86_l_229c;
	}
x86_l_221b:
	/* 0x221b: jmp    233e <filter_8ty_range+0x1a9> */
	goto x86_l_233e;
x86_l_2220:
	/* 0x2220: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2223:
	/* 0x2223: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2226:
	/* 0x2226: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_222a:
	/* 0x222a: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_222d:
	/* 0x222d: setge  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_GE);
x86_l_2230:
	/* 0x2230: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_2233:
	/* 0x2233: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_2236:
	/* 0x2236: jb     233e <filter_8ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_233e;
	}
x86_l_223c:
	/* 0x223c: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_223f:
	/* 0x223f: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_2243:
	/* 0x2243: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2246:
	/* 0x2246: setge  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_GE);
x86_l_224a:
	/* 0x224a: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_224d:
	/* 0x224d: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_2250:
	/* 0x2250: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_2253:
	/* 0x2253: jb     233e <filter_8ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_233e;
	}
x86_l_2259:
	/* 0x2259: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_225c:
	/* 0x225c: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_2260:
	/* 0x2260: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2263:
	/* 0x2263: setge  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_GE);
x86_l_2267:
	/* 0x2267: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_226a:
	/* 0x226a: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_226d:
	/* 0x226d: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_2270:
	/* 0x2270: jb     233e <filter_8ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_233e;
	}
x86_l_2276:
	/* 0x2276: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2279:
	/* 0x2279: setle  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_LE);
x86_l_227c:
	/* 0x227c: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_227f:
	/* 0x227f: setge  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_GE);
x86_l_2283:
	/* 0x2283: jmp    22f8 <filter_8ty_range+0x163> */
	goto x86_l_22f8;
x86_l_2285:
	/* 0x2285: movzx  esi,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2288:
	/* 0x2288: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_228b:
	/* 0x228b: jne    229d <filter_8ty_range+0x108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_229d;
	}
x86_l_228d:
	/* 0x228d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2292:
	/* 0x2292: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2295:
	/* 0x2295: ja     2300 <filter_8ty_range+0x16b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2300;
	}
x86_l_2297:
	/* 0x2297: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_229a:
	/* 0x229a: jb     2300 <filter_8ty_range+0x16b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2300;
	}
x86_l_229c:
	/* 0x229c: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_229d:
	/* 0x229d: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22a0:
	/* 0x22a0: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22a3:
	/* 0x22a3: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_22a7:
	/* 0x22a7: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_22aa:
	/* 0x22aa: setae  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_AE);
x86_l_22ad:
	/* 0x22ad: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_22b0:
	/* 0x22b0: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_22b3:
	/* 0x22b3: jb     233e <filter_8ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_233e;
	}
x86_l_22b9:
	/* 0x22b9: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_22bc:
	/* 0x22bc: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_22c0:
	/* 0x22c0: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_22c3:
	/* 0x22c3: setae  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_AE);
x86_l_22c7:
	/* 0x22c7: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_22ca:
	/* 0x22ca: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_22cd:
	/* 0x22cd: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_22d0:
	/* 0x22d0: jb     233e <filter_8ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_233e;
	}
x86_l_22d2:
	/* 0x22d2: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_22d5:
	/* 0x22d5: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_22d9:
	/* 0x22d9: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_22dc:
	/* 0x22dc: setae  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_AE);
x86_l_22e0:
	/* 0x22e0: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_22e3:
	/* 0x22e3: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_22e6:
	/* 0x22e6: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_22e9:
	/* 0x22e9: jb     233e <filter_8ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_233e;
	}
x86_l_22eb:
	/* 0x22eb: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_22ee:
	/* 0x22ee: setbe  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_BE);
x86_l_22f1:
	/* 0x22f1: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_22f4:
	/* 0x22f4: setae  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_AE);
x86_l_22f8:
	/* 0x22f8: and    sil,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_22fb:
	/* 0x22fb: or     dl,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_8, X86_ALU_OR);
x86_l_22fe:
	/* 0x22fe: jmp    233e <filter_8ty_range+0x1a9> */
	goto x86_l_233e;
x86_l_2300:
	/* 0x2300: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2303:
	/* 0x2303: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_2306:
	/* 0x2306: jb     233c <filter_8ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_233c;
	}
x86_l_2308:
	/* 0x2308: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_230b:
	/* 0x230b: ja     2312 <filter_8ty_range+0x17d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2312;
	}
x86_l_230d:
	/* 0x230d: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2310:
	/* 0x2310: jae    229c <filter_8ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_229c;
	}
x86_l_2312:
	/* 0x2312: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_2315:
	/* 0x2315: jb     233c <filter_8ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_233c;
	}
x86_l_2317:
	/* 0x2317: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_231a:
	/* 0x231a: ja     2325 <filter_8ty_range+0x190> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2325;
	}
x86_l_231c:
	/* 0x231c: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_231f:
	/* 0x231f: jae    229c <filter_8ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_229c;
	}
x86_l_2325:
	/* 0x2325: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_2328:
	/* 0x2328: jb     233c <filter_8ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_233c;
	}
x86_l_232a:
	/* 0x232a: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_232c:
	/* 0x232c: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_232f:
	/* 0x232f: ja     233e <filter_8ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_233e;
	}
x86_l_2331:
	/* 0x2331: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2334:
	/* 0x2334: jae    229c <filter_8ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_229c;
	}
x86_l_233a:
	/* 0x233a: jmp    233e <filter_8ty_range+0x1a9> */
	goto x86_l_233e;
x86_l_233c:
	/* 0x233c: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_233e:
	/* 0x233e: cmp    ecx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 32ULL);
x86_l_2341:
	/* 0x2341: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_2344:
	/* 0x2344: xor    dl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_2347:
	/* 0x2347: and    dl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_2349:
	/* 0x2349: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_234c:
	/* 0x234c: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_234d:
	/* 0x234d: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_234f:
	/* 0x234f: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_2350:
	/* 0x2350: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_2354:
	/* 0x2354: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_2357:
	/* 0x2357: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_235a:
	/* 0x235a: movzx  eax,BYTE PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_235e:
	/* 0x235e: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2362:
	/* 0x2362: mov    rdi,QWORD PTR [rip+0x1290] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_2369:
	/* 0x2369: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_236e:
	/* 0x236e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2373:
	/* 0x2373: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2375:
	/* 0x2375: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2378:
	/* 0x2378: je     23ae <filter_8ty_map+0x61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23ae;
	}
x86_l_237a:
	/* 0x237a: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_237d:
	/* 0x237d: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2381:
	/* 0x2381: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2386:
	/* 0x2386: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_238b:
	/* 0x238b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2390:
	/* 0x2390: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2392:
	/* 0x2392: mov    edx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2395:
	/* 0x2395: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2397:
	/* 0x2397: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_239a:
	/* 0x239a: ja     23c8 <filter_8ty_map+0x7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_23c8;
	}
x86_l_239c:
	/* 0x239c: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_23a1:
	/* 0x23a1: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_23a4:
	/* 0x23a4: jae    23b8 <filter_8ty_map+0x6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_23b8;
	}
x86_l_23a6:
	/* 0x23a6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_23a9:
	/* 0x23a9: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_23ac:
	/* 0x23ac: jmp    23c8 <filter_8ty_map+0x7b> */
	goto x86_l_23c8;
x86_l_23ae:
	/* 0x23ae: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_23b0:
	/* 0x23b0: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_23b4:
	/* 0x23b4: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_23b5:
	/* 0x23b5: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_23b7:
	/* 0x23b7: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_23b8:
	/* 0x23b8: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_23bd:
	/* 0x23bd: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_23c0:
	/* 0x23c0: jae    23c8 <filter_8ty_map+0x7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_23c8;
	}
x86_l_23c2:
	/* 0x23c2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_23c5:
	/* 0x23c5: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_23c8:
	/* 0x23c8: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_23cb:
	/* 0x23cb: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_23cf:
	/* 0x23cf: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_23d0:
	/* 0x23d0: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_23d2:
	/* 0x23d2: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_23d3:
	/* 0x23d3: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_23d4:
	/* 0x23d4: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_23d8:
	/* 0x23d8: mov    WORD PTR [rsp+0xe],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 60129542144ULL);
x86_l_23df:
	/* 0x23df: mov    eax,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23e1:
	/* 0x23e1: cmp    rax,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4096ULL);
x86_l_23e7:
	/* 0x23e7: ja     246f <filter_file_type+0x9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_246f;
	}
x86_l_23ed:
	/* 0x23ed: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_23f0:
	/* 0x23f0: lea    rcx,[rsi+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_23f4:
	/* 0x23f4: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_23f8:
	/* 0x23f8: lea    rdi,[rsp+0xe] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_23fd:
	/* 0x23fd: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2402:
	/* 0x2402: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2407:
	/* 0x2407: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2409:
	/* 0x2409: lea    rdx,[rsi+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_240d:
	/* 0x240d: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2411:
	/* 0x2411: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2416:
	/* 0x2416: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2418:
	/* 0x2418: mov    edx,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_241b:
	/* 0x241b: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_241d:
	/* 0x241d: je     246f <filter_file_type+0x9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_246f;
	}
x86_l_241f:
	/* 0x241f: movzx  ecx,WORD PTR [rsp+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_2424:
	/* 0x2424: and    ecx,0xf000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 61440ULL);
x86_l_242a:
	/* 0x242a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_242f:
	/* 0x242f: cmp    edx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_2431:
	/* 0x2431: je     2471 <filter_file_type+0x9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2471;
	}
x86_l_2433:
	/* 0x2433: mov    edx,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2436:
	/* 0x2436: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_2439:
	/* 0x2439: jbe    246f <filter_file_type+0x9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_246f;
	}
x86_l_243b:
	/* 0x243b: mov    esi,DWORD PTR [rbx+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_243e:
	/* 0x243e: test   esi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_32);
x86_l_2440:
	/* 0x2440: je     246f <filter_file_type+0x9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_246f;
	}
x86_l_2442:
	/* 0x2442: cmp    esi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_2444:
	/* 0x2444: je     2471 <filter_file_type+0x9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2471;
	}
x86_l_2446:
	/* 0x2446: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_2449:
	/* 0x2449: jb     246f <filter_file_type+0x9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_246f;
	}
x86_l_244b:
	/* 0x244b: mov    esi,DWORD PTR [rbx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_244e:
	/* 0x244e: test   esi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_32);
x86_l_2450:
	/* 0x2450: je     246f <filter_file_type+0x9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_246f;
	}
x86_l_2452:
	/* 0x2452: cmp    esi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_2454:
	/* 0x2454: je     2471 <filter_file_type+0x9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2471;
	}
x86_l_2456:
	/* 0x2456: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_2459:
	/* 0x2459: jb     246f <filter_file_type+0x9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_246f;
	}
x86_l_245b:
	/* 0x245b: mov    edx,DWORD PTR [rbx+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_245e:
	/* 0x245e: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_2460:
	/* 0x2460: je     246f <filter_file_type+0x9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_246f;
	}
x86_l_2462:
	/* 0x2462: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2464:
	/* 0x2464: cmp    edx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_2466:
	/* 0x2466: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_2469:
	/* 0x2469: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_246d:
	/* 0x246d: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_246e:
	/* 0x246e: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_246f:
	/* 0x246f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2471:
	/* 0x2471: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2475:
	/* 0x2475: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_2476:
	/* 0x2476: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_filter_arg_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 10404U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1540ULL)
			__x86_pc = tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_filter_arg_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1543ULL && __x86_pc <= 2826ULL)
			__x86_pc = tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_filter_arg_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 2829ULL && __x86_pc <= 4241ULL)
			__x86_pc = tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_filter_arg_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 4242ULL && __x86_pc <= 5651ULL)
			__x86_pc = tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_filter_arg_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 5656ULL && __x86_pc <= 6998ULL)
			__x86_pc = tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_filter_arg_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 7000ULL && __x86_pc <= 8350ULL)
			__x86_pc = tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_filter_arg_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 8353ULL && __x86_pc <= 9334ULL)
			__x86_pc = tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_filter_arg_x86_chunk_6(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

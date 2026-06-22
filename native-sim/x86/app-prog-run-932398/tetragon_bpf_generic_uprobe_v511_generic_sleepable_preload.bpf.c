extern char CONFIG_ITER_NUM;
extern char config_map;
extern char heap_ro_zero;
extern char sleepable_preload;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_0(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 0ULL: goto x86_l_0;
	case 1ULL: goto x86_l_1;
	case 3ULL: goto x86_l_3;
	case 10ULL: goto x86_l_a;
	case 15ULL: goto x86_l_f;
	case 26ULL: goto x86_l_1a;
	case 31ULL: goto x86_l_1f;
	case 38ULL: goto x86_l_26;
	case 46ULL: goto x86_l_2e;
	case 48ULL: goto x86_l_30;
	case 51ULL: goto x86_l_33;
	case 57ULL: goto x86_l_39;
	case 60ULL: goto x86_l_3c;
	case 67ULL: goto x86_l_43;
	case 72ULL: goto x86_l_48;
	case 79ULL: goto x86_l_4f;
	case 84ULL: goto x86_l_54;
	case 91ULL: goto x86_l_5b;
	case 96ULL: goto x86_l_60;
	case 100ULL: goto x86_l_64;
	case 105ULL: goto x86_l_69;
	case 109ULL: goto x86_l_6d;
	case 114ULL: goto x86_l_72;
	case 118ULL: goto x86_l_76;
	case 123ULL: goto x86_l_7b;
	case 127ULL: goto x86_l_7f;
	case 132ULL: goto x86_l_84;
	case 136ULL: goto x86_l_88;
	case 144ULL: goto x86_l_90;
	case 148ULL: goto x86_l_94;
	case 153ULL: goto x86_l_99;
	case 157ULL: goto x86_l_9d;
	case 165ULL: goto x86_l_a5;
	case 169ULL: goto x86_l_a9;
	case 174ULL: goto x86_l_ae;
	case 178ULL: goto x86_l_b2;
	case 186ULL: goto x86_l_ba;
	case 190ULL: goto x86_l_be;
	case 195ULL: goto x86_l_c3;
	case 199ULL: goto x86_l_c7;
	case 207ULL: goto x86_l_cf;
	case 211ULL: goto x86_l_d3;
	case 216ULL: goto x86_l_d8;
	case 219ULL: goto x86_l_db;
	case 223ULL: goto x86_l_df;
	case 231ULL: goto x86_l_e7;
	case 235ULL: goto x86_l_eb;
	case 240ULL: goto x86_l_f0;
	case 245ULL: goto x86_l_f5;
	case 251ULL: goto x86_l_fb;
	case 254ULL: goto x86_l_fe;
	case 261ULL: goto x86_l_105;
	case 264ULL: goto x86_l_108;
	case 266ULL: goto x86_l_10a;
	case 268ULL: goto x86_l_10c;
	case 273ULL: goto x86_l_111;
	case 276ULL: goto x86_l_114;
	case 280ULL: goto x86_l_118;
	case 284ULL: goto x86_l_11c;
	case 290ULL: goto x86_l_122;
	case 295ULL: goto x86_l_127;
	case 300ULL: goto x86_l_12c;
	case 302ULL: goto x86_l_12e;
	case 304ULL: goto x86_l_130;
	case 306ULL: goto x86_l_132;
	case 311ULL: goto x86_l_137;
	case 314ULL: goto x86_l_13a;
	case 320ULL: goto x86_l_140;
	case 323ULL: goto x86_l_143;
	case 329ULL: goto x86_l_149;
	case 332ULL: goto x86_l_14c;
	case 338ULL: goto x86_l_152;
	case 341ULL: goto x86_l_155;
	case 347ULL: goto x86_l_15b;
	case 352ULL: goto x86_l_160;
	case 357ULL: goto x86_l_165;
	case 366ULL: goto x86_l_16e;
	case 375ULL: goto x86_l_177;
	case 381ULL: goto x86_l_17d;
	case 384ULL: goto x86_l_180;
	case 386ULL: goto x86_l_182;
	case 389ULL: goto x86_l_185;
	case 395ULL: goto x86_l_18b;
	case 398ULL: goto x86_l_18e;
	case 404ULL: goto x86_l_194;
	case 409ULL: goto x86_l_199;
	case 412ULL: goto x86_l_19c;
	case 418ULL: goto x86_l_1a2;
	case 423ULL: goto x86_l_1a7;
	case 426ULL: goto x86_l_1aa;
	case 432ULL: goto x86_l_1b0;
	case 437ULL: goto x86_l_1b5;
	case 440ULL: goto x86_l_1b8;
	case 446ULL: goto x86_l_1be;
	case 451ULL: goto x86_l_1c3;
	case 456ULL: goto x86_l_1c8;
	case 459ULL: goto x86_l_1cb;
	case 461ULL: goto x86_l_1cd;
	case 464ULL: goto x86_l_1d0;
	case 470ULL: goto x86_l_1d6;
	case 475ULL: goto x86_l_1db;
	case 477ULL: goto x86_l_1dd;
	case 483ULL: goto x86_l_1e3;
	case 488ULL: goto x86_l_1e8;
	case 493ULL: goto x86_l_1ed;
	case 496ULL: goto x86_l_1f0;
	case 502ULL: goto x86_l_1f6;
	case 507ULL: goto x86_l_1fb;
	case 509ULL: goto x86_l_1fd;
	case 515ULL: goto x86_l_203;
	case 518ULL: goto x86_l_206;
	case 524ULL: goto x86_l_20c;
	case 529ULL: goto x86_l_211;
	case 531ULL: goto x86_l_213;
	case 534ULL: goto x86_l_216;
	case 540ULL: goto x86_l_21c;
	case 548ULL: goto x86_l_224;
	case 551ULL: goto x86_l_227;
	case 557ULL: goto x86_l_22d;
	case 562ULL: goto x86_l_232;
	case 567ULL: goto x86_l_237;
	case 570ULL: goto x86_l_23a;
	case 576ULL: goto x86_l_240;
	case 581ULL: goto x86_l_245;
	case 584ULL: goto x86_l_248;
	case 590ULL: goto x86_l_24e;
	case 598ULL: goto x86_l_256;
	case 601ULL: goto x86_l_259;
	case 607ULL: goto x86_l_25f;
	case 612ULL: goto x86_l_264;
	case 617ULL: goto x86_l_269;
	case 620ULL: goto x86_l_26c;
	case 626ULL: goto x86_l_272;
	case 631ULL: goto x86_l_277;
	case 636ULL: goto x86_l_27c;
	case 638ULL: goto x86_l_27e;
	case 643ULL: goto x86_l_283;
	case 645ULL: goto x86_l_285;
	case 650ULL: goto x86_l_28a;
	case 653ULL: goto x86_l_28d;
	case 657ULL: goto x86_l_291;
	case 659ULL: goto x86_l_293;
	case 662ULL: goto x86_l_296;
	case 667ULL: goto x86_l_29b;
	case 673ULL: goto x86_l_2a1;
	case 680ULL: goto x86_l_2a8;
	case 683ULL: goto x86_l_2ab;
	case 686ULL: goto x86_l_2ae;
	case 689ULL: goto x86_l_2b1;
	case 693ULL: goto x86_l_2b5;
	case 697ULL: goto x86_l_2b9;
	case 699ULL: goto x86_l_2bb;
	case 705ULL: goto x86_l_2c1;
	case 708ULL: goto x86_l_2c4;
	case 710ULL: goto x86_l_2c6;
	case 715ULL: goto x86_l_2cb;
	case 719ULL: goto x86_l_2cf;
	case 722ULL: goto x86_l_2d2;
	case 727ULL: goto x86_l_2d7;
	case 729ULL: goto x86_l_2d9;
	case 731ULL: goto x86_l_2db;
	case 737ULL: goto x86_l_2e1;
	case 742ULL: goto x86_l_2e6;
	case 748ULL: goto x86_l_2ec;
	case 751ULL: goto x86_l_2ef;
	case 755ULL: goto x86_l_2f3;
	case 760ULL: goto x86_l_2f8;
	case 762ULL: goto x86_l_2fa;
	case 767ULL: goto x86_l_2ff;
	case 771ULL: goto x86_l_303;
	case 774ULL: goto x86_l_306;
	case 779ULL: goto x86_l_30b;
	case 781ULL: goto x86_l_30d;
	case 783ULL: goto x86_l_30f;
	case 789ULL: goto x86_l_315;
	case 794ULL: goto x86_l_31a;
	case 800ULL: goto x86_l_320;
	case 803ULL: goto x86_l_323;
	case 807ULL: goto x86_l_327;
	case 812ULL: goto x86_l_32c;
	case 814ULL: goto x86_l_32e;
	case 819ULL: goto x86_l_333;
	case 823ULL: goto x86_l_337;
	case 826ULL: goto x86_l_33a;
	case 831ULL: goto x86_l_33f;
	case 833ULL: goto x86_l_341;
	case 835ULL: goto x86_l_343;
	case 841ULL: goto x86_l_349;
	case 846ULL: goto x86_l_34e;
	case 852ULL: goto x86_l_354;
	case 855ULL: goto x86_l_357;
	case 859ULL: goto x86_l_35b;
	case 864ULL: goto x86_l_360;
	case 866ULL: goto x86_l_362;
	case 871ULL: goto x86_l_367;
	case 875ULL: goto x86_l_36b;
	case 878ULL: goto x86_l_36e;
	case 883ULL: goto x86_l_373;
	case 885ULL: goto x86_l_375;
	case 887ULL: goto x86_l_377;
	case 893ULL: goto x86_l_37d;
	case 898ULL: goto x86_l_382;
	case 904ULL: goto x86_l_388;
	case 907ULL: goto x86_l_38b;
	case 911ULL: goto x86_l_38f;
	case 916ULL: goto x86_l_394;
	case 918ULL: goto x86_l_396;
	case 923ULL: goto x86_l_39b;
	case 927ULL: goto x86_l_39f;
	case 930ULL: goto x86_l_3a2;
	case 935ULL: goto x86_l_3a7;
	case 937ULL: goto x86_l_3a9;
	case 939ULL: goto x86_l_3ab;
	case 945ULL: goto x86_l_3b1;
	case 950ULL: goto x86_l_3b6;
	case 956ULL: goto x86_l_3bc;
	case 959ULL: goto x86_l_3bf;
	case 963ULL: goto x86_l_3c3;
	case 968ULL: goto x86_l_3c8;
	case 970ULL: goto x86_l_3ca;
	case 975ULL: goto x86_l_3cf;
	case 979ULL: goto x86_l_3d3;
	case 982ULL: goto x86_l_3d6;
	case 987ULL: goto x86_l_3db;
	case 989ULL: goto x86_l_3dd;
	case 991ULL: goto x86_l_3df;
	case 997ULL: goto x86_l_3e5;
	case 1002ULL: goto x86_l_3ea;
	case 1008ULL: goto x86_l_3f0;
	case 1011ULL: goto x86_l_3f3;
	case 1015ULL: goto x86_l_3f7;
	case 1020ULL: goto x86_l_3fc;
	case 1022ULL: goto x86_l_3fe;
	case 1027ULL: goto x86_l_403;
	case 1031ULL: goto x86_l_407;
	case 1034ULL: goto x86_l_40a;
	case 1039ULL: goto x86_l_40f;
	case 1041ULL: goto x86_l_411;
	case 1043ULL: goto x86_l_413;
	case 1049ULL: goto x86_l_419;
	case 1054ULL: goto x86_l_41e;
	case 1060ULL: goto x86_l_424;
	case 1063ULL: goto x86_l_427;
	case 1067ULL: goto x86_l_42b;
	case 1072ULL: goto x86_l_430;
	case 1074ULL: goto x86_l_432;
	case 1079ULL: goto x86_l_437;
	case 1083ULL: goto x86_l_43b;
	case 1086ULL: goto x86_l_43e;
	case 1091ULL: goto x86_l_443;
	case 1093ULL: goto x86_l_445;
	case 1095ULL: goto x86_l_447;
	case 1101ULL: goto x86_l_44d;
	case 1106ULL: goto x86_l_452;
	case 1112ULL: goto x86_l_458;
	case 1115ULL: goto x86_l_45b;
	case 1119ULL: goto x86_l_45f;
	case 1124ULL: goto x86_l_464;
	case 1126ULL: goto x86_l_466;
	case 1131ULL: goto x86_l_46b;
	case 1135ULL: goto x86_l_46f;
	case 1138ULL: goto x86_l_472;
	case 1143ULL: goto x86_l_477;
	case 1145ULL: goto x86_l_479;
	case 1147ULL: goto x86_l_47b;
	case 1153ULL: goto x86_l_481;
	case 1157ULL: goto x86_l_485;
	case 1163ULL: goto x86_l_48b;
	case 1166ULL: goto x86_l_48e;
	case 1170ULL: goto x86_l_492;
	case 1175ULL: goto x86_l_497;
	case 1181ULL: goto x86_l_49d;
	case 1186ULL: goto x86_l_4a2;
	case 1191ULL: goto x86_l_4a7;
	case 1194ULL: goto x86_l_4aa;
	case 1196ULL: goto x86_l_4ac;
	case 1201ULL: goto x86_l_4b1;
	case 1205ULL: goto x86_l_4b5;
	case 1208ULL: goto x86_l_4b8;
	case 1213ULL: goto x86_l_4bd;
	case 1215ULL: goto x86_l_4bf;
	case 1217ULL: goto x86_l_4c1;
	case 1223ULL: goto x86_l_4c7;
	case 1228ULL: goto x86_l_4cc;
	case 1234ULL: goto x86_l_4d2;
	case 1237ULL: goto x86_l_4d5;
	case 1241ULL: goto x86_l_4d9;
	case 1246ULL: goto x86_l_4de;
	case 1248ULL: goto x86_l_4e0;
	case 1253ULL: goto x86_l_4e5;
	case 1257ULL: goto x86_l_4e9;
	case 1260ULL: goto x86_l_4ec;
	case 1265ULL: goto x86_l_4f1;
	case 1267ULL: goto x86_l_4f3;
	case 1269ULL: goto x86_l_4f5;
	case 1275ULL: goto x86_l_4fb;
	case 1280ULL: goto x86_l_500;
	case 1286ULL: goto x86_l_506;
	case 1289ULL: goto x86_l_509;
	case 1293ULL: goto x86_l_50d;
	case 1298ULL: goto x86_l_512;
	case 1300ULL: goto x86_l_514;
	case 1305ULL: goto x86_l_519;
	case 1309ULL: goto x86_l_51d;
	case 1312ULL: goto x86_l_520;
	case 1317ULL: goto x86_l_525;
	case 1319ULL: goto x86_l_527;
	case 1321ULL: goto x86_l_529;
	case 1327ULL: goto x86_l_52f;
	case 1332ULL: goto x86_l_534;
	case 1338ULL: goto x86_l_53a;
	case 1341ULL: goto x86_l_53d;
	case 1345ULL: goto x86_l_541;
	case 1350ULL: goto x86_l_546;
	case 1352ULL: goto x86_l_548;
	case 1357ULL: goto x86_l_54d;
	case 1361ULL: goto x86_l_551;
	case 1364ULL: goto x86_l_554;
	case 1369ULL: goto x86_l_559;
	case 1371ULL: goto x86_l_55b;
	case 1373ULL: goto x86_l_55d;
	case 1379ULL: goto x86_l_563;
	case 1384ULL: goto x86_l_568;
	case 1390ULL: goto x86_l_56e;
	case 1393ULL: goto x86_l_571;
	case 1397ULL: goto x86_l_575;
	case 1402ULL: goto x86_l_57a;
	case 1404ULL: goto x86_l_57c;
	case 1409ULL: goto x86_l_581;
	case 1413ULL: goto x86_l_585;
	case 1416ULL: goto x86_l_588;
	case 1421ULL: goto x86_l_58d;
	case 1423ULL: goto x86_l_58f;
	case 1425ULL: goto x86_l_591;
	case 1431ULL: goto x86_l_597;
	case 1436ULL: goto x86_l_59c;
	case 1442ULL: goto x86_l_5a2;
	case 1445ULL: goto x86_l_5a5;
	case 1449ULL: goto x86_l_5a9;
	case 1454ULL: goto x86_l_5ae;
	case 1456ULL: goto x86_l_5b0;
	case 1461ULL: goto x86_l_5b5;
	case 1465ULL: goto x86_l_5b9;
	case 1468ULL: goto x86_l_5bc;
	case 1473ULL: goto x86_l_5c1;
	case 1475ULL: goto x86_l_5c3;
	case 1477ULL: goto x86_l_5c5;
	case 1483ULL: goto x86_l_5cb;
	case 1488ULL: goto x86_l_5d0;
	case 1494ULL: goto x86_l_5d6;
	case 1497ULL: goto x86_l_5d9;
	case 1501ULL: goto x86_l_5dd;
	case 1506ULL: goto x86_l_5e2;
	case 1508ULL: goto x86_l_5e4;
	case 1513ULL: goto x86_l_5e9;
	case 1517ULL: goto x86_l_5ed;
	case 1520ULL: goto x86_l_5f0;
	case 1525ULL: goto x86_l_5f5;
	case 1527ULL: goto x86_l_5f7;
	case 1529ULL: goto x86_l_5f9;
	case 1535ULL: goto x86_l_5ff;
	case 1540ULL: goto x86_l_604;
	case 1546ULL: goto x86_l_60a;
	case 1549ULL: goto x86_l_60d;
	case 1553ULL: goto x86_l_611;
	case 1558ULL: goto x86_l_616;
	case 1560ULL: goto x86_l_618;
	case 1565ULL: goto x86_l_61d;
	case 1569ULL: goto x86_l_621;
	case 1572ULL: goto x86_l_624;
	case 1577ULL: goto x86_l_629;
	case 1579ULL: goto x86_l_62b;
	case 1581ULL: goto x86_l_62d;
	case 1587ULL: goto x86_l_633;
	case 1592ULL: goto x86_l_638;
	case 1598ULL: goto x86_l_63e;
	case 1601ULL: goto x86_l_641;
	case 1605ULL: goto x86_l_645;
	case 1610ULL: goto x86_l_64a;
	case 1612ULL: goto x86_l_64c;
	case 1617ULL: goto x86_l_651;
	case 1621ULL: goto x86_l_655;
	case 1624ULL: goto x86_l_658;
	case 1629ULL: goto x86_l_65d;
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
	/* 0xa: mov    QWORD PTR [rsp+0x50],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_f:
	/* 0xf: mov    DWORD PTR [rsp+0xb4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_1a:
	/* 0x1a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f:
	/* 0x1f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_26:
	/* 0x26: lea    rsi,[rsp+0xb4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_2e:
	/* 0x2e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30:
	/* 0x30: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_33:
	/* 0x33: je     35ff <generic_sleepable_preload+0x35ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13823ULL;
	}
x86_l_39:
	/* 0x39: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_3c:
	/* 0x3c: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_43:
	/* 0x43: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_48:
	/* 0x48: lea    rdx,[rcx+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_4f:
	/* 0x4f: mov    QWORD PTR [rsp+0x58],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_54:
	/* 0x54: lea    rdx,[rcx+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_5b:
	/* 0x5b: mov    QWORD PTR [rsp+0x78],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_60:
	/* 0x60: lea    rdx,[rcx+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_64:
	/* 0x64: mov    QWORD PTR [rsp+0x40],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_69:
	/* 0x69: lea    rdx,[rcx+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_6d:
	/* 0x6d: mov    QWORD PTR [rsp+0x30],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_72:
	/* 0x72: lea    rdx,[rcx+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_76:
	/* 0x76: mov    QWORD PTR [rsp+0x38],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_7b:
	/* 0x7b: lea    rdx,[rcx+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_7f:
	/* 0x7f: mov    QWORD PTR [rsp+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_84:
	/* 0x84: lea    rdx,[rcx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_88:
	/* 0x88: mov    QWORD PTR [rsp+0xa0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_90:
	/* 0x90: lea    rdx,[rcx+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_94:
	/* 0x94: mov    QWORD PTR [rsp+0x28],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_99:
	/* 0x99: lea    rdx,[rcx+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_9d:
	/* 0x9d: mov    QWORD PTR [rsp+0x98],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_a5:
	/* 0xa5: lea    rdx,[rcx+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_a9:
	/* 0xa9: mov    QWORD PTR [rsp+0x70],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_ae:
	/* 0xae: lea    rdx,[rcx+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b2:
	/* 0xb2: mov    QWORD PTR [rsp+0x90],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_ba:
	/* 0xba: lea    rdx,[rcx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_be:
	/* 0xbe: mov    QWORD PTR [rsp+0x68],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_c3:
	/* 0xc3: lea    rdx,[rcx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c7:
	/* 0xc7: mov    QWORD PTR [rsp+0x88],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_cf:
	/* 0xcf: lea    rdx,[rcx+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d3:
	/* 0xd3: mov    QWORD PTR [rsp+0x60],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_d8:
	/* 0xd8: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_db:
	/* 0xdb: lea    rax,[rcx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_df:
	/* 0xdf: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_e7:
	/* 0xe7: lea    rdi,[rcx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_eb:
	/* 0xeb: mov    QWORD PTR [rsp+0x8],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f0:
	/* 0xf0: mov    QWORD PTR [rsp+0x48],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_f5:
	/* 0xf5: je     d94 <generic_sleepable_preload+0xd94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3476ULL;
	}
x86_l_fb:
	/* 0xfb: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_fe:
	/* 0xfe: add    rbx,0xbe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 190ULL);
x86_l_105:
	/* 0x105: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_108:
	/* 0x108: jmp    122 <generic_sleepable_preload+0x122> */
	goto x86_l_122;
x86_l_10a:
	/* 0x10a: mov    DWORD PTR [rax],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10c:
	/* 0x10c: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_111:
	/* 0x111: inc    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_114:
	/* 0x114: add    rbx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_118:
	/* 0x118: cmp    r14,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 5ULL);
x86_l_11c:
	/* 0x11c: je     35ff <generic_sleepable_preload+0x35ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13823ULL;
	}
x86_l_122:
	/* 0x122: mov    eax,DWORD PTR [r13+r14*4+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 24ULL);
x86_l_127:
	/* 0x127: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_12c:
	/* 0x12c: je     111 <generic_sleepable_preload+0x111> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_111;
	}
x86_l_12e:
	/* 0x12e: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_130:
	/* 0x130: js     165 <generic_sleepable_preload+0x165> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_165;
	}
x86_l_132:
	/* 0x132: mov    ecx,DWORD PTR [r13+r14*4+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 64ULL);
x86_l_137:
	/* 0x137: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_13a:
	/* 0x13a: jle    1fb <generic_sleepable_preload+0x1fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1fb;
	}
x86_l_140:
	/* 0x140: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_143:
	/* 0x143: je     277 <generic_sleepable_preload+0x277> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_277;
	}
x86_l_149:
	/* 0x149: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_14c:
	/* 0x14c: je     27e <generic_sleepable_preload+0x27e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27e;
	}
x86_l_152:
	/* 0x152: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_155:
	/* 0x155: jne    291 <generic_sleepable_preload+0x291> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_291;
	}
x86_l_15b:
	/* 0x15b: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_160:
	/* 0x160: jmp    28a <generic_sleepable_preload+0x28a> */
	goto x86_l_28a;
x86_l_165:
	/* 0x165: movzx  eax,BYTE PTR [r13+r14*4+0x2c2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R14, 2, X86_WIDTH_8), 706ULL);
x86_l_16e:
	/* 0x16e: movzx  ecx,WORD PTR [r13+r14*4+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R14, 2, X86_WIDTH_16), 704ULL);
x86_l_177:
	/* 0x177: rorx   ecx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_17d:
	/* 0x17d: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_180:
	/* 0x180: jle    1c8 <generic_sleepable_preload+0x1c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1c8;
	}
x86_l_182:
	/* 0x182: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_185:
	/* 0x185: jle    213 <generic_sleepable_preload+0x213> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_213;
	}
x86_l_18b:
	/* 0x18b: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_18e:
	/* 0x18e: jle    70c <generic_sleepable_preload+0x70c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 1804ULL;
	}
x86_l_194:
	/* 0x194: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_199:
	/* 0x199: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_19c:
	/* 0x19c: je     725 <generic_sleepable_preload+0x725> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1829ULL;
	}
x86_l_1a2:
	/* 0x1a2: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1a7:
	/* 0x1a7: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1aa:
	/* 0x1aa: je     725 <generic_sleepable_preload+0x725> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1829ULL;
	}
x86_l_1b0:
	/* 0x1b0: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_1b5:
	/* 0x1b5: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_1b8:
	/* 0x1b8: jne    738 <generic_sleepable_preload+0x738> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1848ULL;
	}
x86_l_1be:
	/* 0x1be: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1c3:
	/* 0x1c3: jmp    725 <generic_sleepable_preload+0x725> */
	return 1829ULL;
x86_l_1c8:
	/* 0x1c8: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1cb:
	/* 0x1cb: jg     245 <generic_sleepable_preload+0x245> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_245;
	}
x86_l_1cd:
	/* 0x1cd: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1d0:
	/* 0x1d0: jg     6d0 <generic_sleepable_preload+0x6d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 1744ULL;
	}
x86_l_1d6:
	/* 0x1d6: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1db:
	/* 0x1db: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1dd:
	/* 0x1dd: je     725 <generic_sleepable_preload+0x725> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1829ULL;
	}
x86_l_1e3:
	/* 0x1e3: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1e8:
	/* 0x1e8: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_1ed:
	/* 0x1ed: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1f0:
	/* 0x1f0: je     725 <generic_sleepable_preload+0x725> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1829ULL;
	}
x86_l_1f6:
	/* 0x1f6: jmp    738 <generic_sleepable_preload+0x738> */
	return 1848ULL;
x86_l_1fb:
	/* 0x1fb: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1fd:
	/* 0x1fd: je     285 <generic_sleepable_preload+0x285> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_285;
	}
x86_l_203:
	/* 0x203: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_206:
	/* 0x206: jne    291 <generic_sleepable_preload+0x291> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_291;
	}
x86_l_20c:
	/* 0x20c: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_211:
	/* 0x211: jmp    28a <generic_sleepable_preload+0x28a> */
	goto x86_l_28a;
x86_l_213:
	/* 0x213: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_216:
	/* 0x216: jg     6b2 <generic_sleepable_preload+0x6b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 1714ULL;
	}
x86_l_21c:
	/* 0x21c: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_224:
	/* 0x224: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_227:
	/* 0x227: je     725 <generic_sleepable_preload+0x725> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1829ULL;
	}
x86_l_22d:
	/* 0x22d: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_232:
	/* 0x232: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_237:
	/* 0x237: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_23a:
	/* 0x23a: je     725 <generic_sleepable_preload+0x725> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1829ULL;
	}
x86_l_240:
	/* 0x240: jmp    738 <generic_sleepable_preload+0x738> */
	return 1848ULL;
x86_l_245:
	/* 0x245: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_248:
	/* 0x248: jg     6ee <generic_sleepable_preload+0x6ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 1774ULL;
	}
x86_l_24e:
	/* 0x24e: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_256:
	/* 0x256: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_259:
	/* 0x259: je     725 <generic_sleepable_preload+0x725> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1829ULL;
	}
x86_l_25f:
	/* 0x25f: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_264:
	/* 0x264: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_269:
	/* 0x269: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_26c:
	/* 0x26c: je     725 <generic_sleepable_preload+0x725> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1829ULL;
	}
x86_l_272:
	/* 0x272: jmp    738 <generic_sleepable_preload+0x738> */
	return 1848ULL;
x86_l_277:
	/* 0x277: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_27c:
	/* 0x27c: jmp    28a <generic_sleepable_preload+0x28a> */
	goto x86_l_28a;
x86_l_27e:
	/* 0x27e: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_283:
	/* 0x283: jmp    28a <generic_sleepable_preload+0x28a> */
	goto x86_l_28a;
x86_l_285:
	/* 0x285: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_28a:
	/* 0x28a: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28d:
	/* 0x28d: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_291:
	/* 0x291: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_293:
	/* 0x293: mov    r15b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_8, 1ULL);
x86_l_296:
	/* 0x296: cmp    WORD PTR [rbx-0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743764471906304ULL);
x86_l_29b:
	/* 0x29b: je     bc7 <generic_sleepable_preload+0xbc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3015ULL;
	}
x86_l_2a1:
	/* 0x2a1: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_2a8:
	/* 0x2a8: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2ab:
	/* 0x2ab: mov    edx,DWORD PTR [rbx-0x4e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551538ULL);
x86_l_2ae:
	/* 0x2ae: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2b1:
	/* 0x2b1: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b5:
	/* 0x2b5: movzx  eax,WORD PTR [rbx-0x4a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551542ULL);
x86_l_2b9:
	/* 0x2b9: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_2bb:
	/* 0x2bb: je     4a7 <generic_sleepable_preload+0x4a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4a7;
	}
x86_l_2c1:
	/* 0x2c1: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_2c4:
	/* 0x2c4: je     2e1 <generic_sleepable_preload+0x2e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e1;
	}
x86_l_2c6:
	/* 0x2c6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2cb:
	/* 0x2cb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cf:
	/* 0x2cf: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2d2:
	/* 0x2d2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d7:
	/* 0x2d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d9:
	/* 0x2d9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2db:
	/* 0x2db: js     6a8 <generic_sleepable_preload+0x6a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 1704ULL;
	}
x86_l_2e1:
	/* 0x2e1: cmp    WORD PTR [rbx-0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743798831644672ULL);
x86_l_2e6:
	/* 0x2e6: je     bc7 <generic_sleepable_preload+0xbc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3015ULL;
	}
x86_l_2ec:
	/* 0x2ec: mov    eax,DWORD PTR [rbx-0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551546ULL);
x86_l_2ef:
	/* 0x2ef: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2f3:
	/* 0x2f3: cmp    WORD PTR [rbx-0x42],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743790241710080ULL);
x86_l_2f8:
	/* 0x2f8: je     315 <generic_sleepable_preload+0x315> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_315;
	}
x86_l_2fa:
	/* 0x2fa: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2ff:
	/* 0x2ff: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_303:
	/* 0x303: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_306:
	/* 0x306: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30b:
	/* 0x30b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30d:
	/* 0x30d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_30f:
	/* 0x30f: js     b65 <generic_sleepable_preload+0xb65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 2917ULL;
	}
x86_l_315:
	/* 0x315: cmp    WORD PTR [rbx-0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743833191383040ULL);
x86_l_31a:
	/* 0x31a: je     bc7 <generic_sleepable_preload+0xbc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3015ULL;
	}
x86_l_320:
	/* 0x320: mov    eax,DWORD PTR [rbx-0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551554ULL);
x86_l_323:
	/* 0x323: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_327:
	/* 0x327: cmp    WORD PTR [rbx-0x3a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743824601448448ULL);
x86_l_32c:
	/* 0x32c: je     349 <generic_sleepable_preload+0x349> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_349;
	}
x86_l_32e:
	/* 0x32e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_333:
	/* 0x333: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_337:
	/* 0x337: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_33a:
	/* 0x33a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33f:
	/* 0x33f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_341:
	/* 0x341: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_343:
	/* 0x343: js     b77 <generic_sleepable_preload+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 2935ULL;
	}
x86_l_349:
	/* 0x349: cmp    WORD PTR [rbx-0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743867551121408ULL);
x86_l_34e:
	/* 0x34e: je     bc7 <generic_sleepable_preload+0xbc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3015ULL;
	}
x86_l_354:
	/* 0x354: mov    eax,DWORD PTR [rbx-0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551562ULL);
x86_l_357:
	/* 0x357: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_35b:
	/* 0x35b: cmp    WORD PTR [rbx-0x32],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743858961186816ULL);
x86_l_360:
	/* 0x360: je     37d <generic_sleepable_preload+0x37d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37d;
	}
x86_l_362:
	/* 0x362: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_367:
	/* 0x367: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36b:
	/* 0x36b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_36e:
	/* 0x36e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_373:
	/* 0x373: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_375:
	/* 0x375: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_377:
	/* 0x377: js     b89 <generic_sleepable_preload+0xb89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 2953ULL;
	}
x86_l_37d:
	/* 0x37d: cmp    WORD PTR [rbx-0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743901910859776ULL);
x86_l_382:
	/* 0x382: je     bc7 <generic_sleepable_preload+0xbc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3015ULL;
	}
x86_l_388:
	/* 0x388: mov    eax,DWORD PTR [rbx-0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551570ULL);
x86_l_38b:
	/* 0x38b: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_38f:
	/* 0x38f: cmp    WORD PTR [rbx-0x2a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743893320925184ULL);
x86_l_394:
	/* 0x394: je     3b1 <generic_sleepable_preload+0x3b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3b1;
	}
x86_l_396:
	/* 0x396: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_39b:
	/* 0x39b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_39f:
	/* 0x39f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3a2:
	/* 0x3a2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a7:
	/* 0x3a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a9:
	/* 0x3a9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3ab:
	/* 0x3ab: js     b9b <generic_sleepable_preload+0xb9b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 2971ULL;
	}
x86_l_3b1:
	/* 0x3b1: cmp    WORD PTR [rbx-0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743936270598144ULL);
x86_l_3b6:
	/* 0x3b6: je     bc7 <generic_sleepable_preload+0xbc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3015ULL;
	}
x86_l_3bc:
	/* 0x3bc: mov    eax,DWORD PTR [rbx-0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551578ULL);
x86_l_3bf:
	/* 0x3bf: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3c3:
	/* 0x3c3: cmp    WORD PTR [rbx-0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743927680663552ULL);
x86_l_3c8:
	/* 0x3c8: je     3e5 <generic_sleepable_preload+0x3e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e5;
	}
x86_l_3ca:
	/* 0x3ca: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3cf:
	/* 0x3cf: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3d3:
	/* 0x3d3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3d6:
	/* 0x3d6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3db:
	/* 0x3db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3dd:
	/* 0x3dd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3df:
	/* 0x3df: js     bad <generic_sleepable_preload+0xbad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 2989ULL;
	}
x86_l_3e5:
	/* 0x3e5: cmp    WORD PTR [rbx-0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743970630336512ULL);
x86_l_3ea:
	/* 0x3ea: je     bc7 <generic_sleepable_preload+0xbc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3015ULL;
	}
x86_l_3f0:
	/* 0x3f0: mov    eax,DWORD PTR [rbx-0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551586ULL);
x86_l_3f3:
	/* 0x3f3: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3f7:
	/* 0x3f7: cmp    WORD PTR [rbx-0x1a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743962040401920ULL);
x86_l_3fc:
	/* 0x3fc: je     419 <generic_sleepable_preload+0x419> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_419;
	}
x86_l_3fe:
	/* 0x3fe: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_403:
	/* 0x403: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_407:
	/* 0x407: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_40a:
	/* 0x40a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_40f:
	/* 0x40f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_411:
	/* 0x411: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_413:
	/* 0x413: js     bbf <generic_sleepable_preload+0xbbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3007ULL;
	}
x86_l_419:
	/* 0x419: cmp    WORD PTR [rbx-0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744004990074880ULL);
x86_l_41e:
	/* 0x41e: je     bc7 <generic_sleepable_preload+0xbc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3015ULL;
	}
x86_l_424:
	/* 0x424: mov    eax,DWORD PTR [rbx-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_427:
	/* 0x427: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_42b:
	/* 0x42b: cmp    WORD PTR [rbx-0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743996400140288ULL);
x86_l_430:
	/* 0x430: je     44d <generic_sleepable_preload+0x44d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44d;
	}
x86_l_432:
	/* 0x432: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_437:
	/* 0x437: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_43b:
	/* 0x43b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_43e:
	/* 0x43e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_443:
	/* 0x443: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_445:
	/* 0x445: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_447:
	/* 0x447: js     d5b <generic_sleepable_preload+0xd5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3419ULL;
	}
x86_l_44d:
	/* 0x44d: cmp    WORD PTR [rbx-0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744039349813248ULL);
x86_l_452:
	/* 0x452: je     bc7 <generic_sleepable_preload+0xbc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3015ULL;
	}
x86_l_458:
	/* 0x458: mov    eax,DWORD PTR [rbx-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551602ULL);
x86_l_45b:
	/* 0x45b: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_45f:
	/* 0x45f: cmp    WORD PTR [rbx-0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744030759878656ULL);
x86_l_464:
	/* 0x464: je     481 <generic_sleepable_preload+0x481> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_481;
	}
x86_l_466:
	/* 0x466: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_46b:
	/* 0x46b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_46f:
	/* 0x46f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_472:
	/* 0x472: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_477:
	/* 0x477: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_479:
	/* 0x479: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_47b:
	/* 0x47b: js     d7f <generic_sleepable_preload+0xd7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3455ULL;
	}
x86_l_481:
	/* 0x481: cmp    WORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_485:
	/* 0x485: je     bc7 <generic_sleepable_preload+0xbc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3015ULL;
	}
x86_l_48b:
	/* 0x48b: mov    eax,DWORD PTR [rbx-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_48e:
	/* 0x48e: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_492:
	/* 0x492: cmp    WORD PTR [rbx-0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744065119617024ULL);
x86_l_497:
	/* 0x497: je     bc7 <generic_sleepable_preload+0xbc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3015ULL;
	}
x86_l_49d:
	/* 0x49d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4a2:
	/* 0x4a2: jmp    688 <generic_sleepable_preload+0x688> */
	return 1672ULL;
x86_l_4a7:
	/* 0x4a7: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_4aa:
	/* 0x4aa: je     4c7 <generic_sleepable_preload+0x4c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4c7;
	}
x86_l_4ac:
	/* 0x4ac: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4b1:
	/* 0x4b1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4b5:
	/* 0x4b5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4b8:
	/* 0x4b8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4bd:
	/* 0x4bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4bf:
	/* 0x4bf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4c1:
	/* 0x4c1: js     6a8 <generic_sleepable_preload+0x6a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 1704ULL;
	}
x86_l_4c7:
	/* 0x4c7: cmp    WORD PTR [rbx-0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743798831644672ULL);
x86_l_4cc:
	/* 0x4cc: je     bc7 <generic_sleepable_preload+0xbc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3015ULL;
	}
x86_l_4d2:
	/* 0x4d2: mov    eax,DWORD PTR [rbx-0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551546ULL);
x86_l_4d5:
	/* 0x4d5: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4d9:
	/* 0x4d9: cmp    WORD PTR [rbx-0x42],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743790241710080ULL);
x86_l_4de:
	/* 0x4de: je     4fb <generic_sleepable_preload+0x4fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4fb;
	}
x86_l_4e0:
	/* 0x4e0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4e5:
	/* 0x4e5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e9:
	/* 0x4e9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4ec:
	/* 0x4ec: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f1:
	/* 0x4f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f3:
	/* 0x4f3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4f5:
	/* 0x4f5: js     b65 <generic_sleepable_preload+0xb65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 2917ULL;
	}
x86_l_4fb:
	/* 0x4fb: cmp    WORD PTR [rbx-0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743833191383040ULL);
x86_l_500:
	/* 0x500: je     bc7 <generic_sleepable_preload+0xbc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3015ULL;
	}
x86_l_506:
	/* 0x506: mov    eax,DWORD PTR [rbx-0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551554ULL);
x86_l_509:
	/* 0x509: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_50d:
	/* 0x50d: cmp    WORD PTR [rbx-0x3a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743824601448448ULL);
x86_l_512:
	/* 0x512: je     52f <generic_sleepable_preload+0x52f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_52f;
	}
x86_l_514:
	/* 0x514: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_519:
	/* 0x519: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_51d:
	/* 0x51d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_520:
	/* 0x520: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_525:
	/* 0x525: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_527:
	/* 0x527: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_529:
	/* 0x529: js     b77 <generic_sleepable_preload+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 2935ULL;
	}
x86_l_52f:
	/* 0x52f: cmp    WORD PTR [rbx-0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743867551121408ULL);
x86_l_534:
	/* 0x534: je     bc7 <generic_sleepable_preload+0xbc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3015ULL;
	}
x86_l_53a:
	/* 0x53a: mov    eax,DWORD PTR [rbx-0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551562ULL);
x86_l_53d:
	/* 0x53d: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_541:
	/* 0x541: cmp    WORD PTR [rbx-0x32],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743858961186816ULL);
x86_l_546:
	/* 0x546: je     563 <generic_sleepable_preload+0x563> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_563;
	}
x86_l_548:
	/* 0x548: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_54d:
	/* 0x54d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_551:
	/* 0x551: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_554:
	/* 0x554: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_559:
	/* 0x559: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55b:
	/* 0x55b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_55d:
	/* 0x55d: js     b89 <generic_sleepable_preload+0xb89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 2953ULL;
	}
x86_l_563:
	/* 0x563: cmp    WORD PTR [rbx-0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743901910859776ULL);
x86_l_568:
	/* 0x568: je     bc7 <generic_sleepable_preload+0xbc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3015ULL;
	}
x86_l_56e:
	/* 0x56e: mov    eax,DWORD PTR [rbx-0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551570ULL);
x86_l_571:
	/* 0x571: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_575:
	/* 0x575: cmp    WORD PTR [rbx-0x2a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743893320925184ULL);
x86_l_57a:
	/* 0x57a: je     597 <generic_sleepable_preload+0x597> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_597;
	}
x86_l_57c:
	/* 0x57c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_581:
	/* 0x581: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_585:
	/* 0x585: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_588:
	/* 0x588: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_58d:
	/* 0x58d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58f:
	/* 0x58f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_591:
	/* 0x591: js     b9b <generic_sleepable_preload+0xb9b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 2971ULL;
	}
x86_l_597:
	/* 0x597: cmp    WORD PTR [rbx-0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743936270598144ULL);
x86_l_59c:
	/* 0x59c: je     bc7 <generic_sleepable_preload+0xbc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3015ULL;
	}
x86_l_5a2:
	/* 0x5a2: mov    eax,DWORD PTR [rbx-0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551578ULL);
x86_l_5a5:
	/* 0x5a5: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5a9:
	/* 0x5a9: cmp    WORD PTR [rbx-0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743927680663552ULL);
x86_l_5ae:
	/* 0x5ae: je     5cb <generic_sleepable_preload+0x5cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5cb;
	}
x86_l_5b0:
	/* 0x5b0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5b5:
	/* 0x5b5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b9:
	/* 0x5b9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5bc:
	/* 0x5bc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5c1:
	/* 0x5c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c3:
	/* 0x5c3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5c5:
	/* 0x5c5: js     bad <generic_sleepable_preload+0xbad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 2989ULL;
	}
x86_l_5cb:
	/* 0x5cb: cmp    WORD PTR [rbx-0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743970630336512ULL);
x86_l_5d0:
	/* 0x5d0: je     bc7 <generic_sleepable_preload+0xbc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3015ULL;
	}
x86_l_5d6:
	/* 0x5d6: mov    eax,DWORD PTR [rbx-0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551586ULL);
x86_l_5d9:
	/* 0x5d9: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5dd:
	/* 0x5dd: cmp    WORD PTR [rbx-0x1a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743962040401920ULL);
x86_l_5e2:
	/* 0x5e2: je     5ff <generic_sleepable_preload+0x5ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5ff;
	}
x86_l_5e4:
	/* 0x5e4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5e9:
	/* 0x5e9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5ed:
	/* 0x5ed: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5f0:
	/* 0x5f0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5f5:
	/* 0x5f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f7:
	/* 0x5f7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5f9:
	/* 0x5f9: js     bbf <generic_sleepable_preload+0xbbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3007ULL;
	}
x86_l_5ff:
	/* 0x5ff: cmp    WORD PTR [rbx-0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744004990074880ULL);
x86_l_604:
	/* 0x604: je     bc7 <generic_sleepable_preload+0xbc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3015ULL;
	}
x86_l_60a:
	/* 0x60a: mov    eax,DWORD PTR [rbx-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_60d:
	/* 0x60d: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_611:
	/* 0x611: cmp    WORD PTR [rbx-0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743996400140288ULL);
x86_l_616:
	/* 0x616: je     633 <generic_sleepable_preload+0x633> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_633;
	}
x86_l_618:
	/* 0x618: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_61d:
	/* 0x61d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_621:
	/* 0x621: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_624:
	/* 0x624: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_629:
	/* 0x629: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_62b:
	/* 0x62b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_62d:
	/* 0x62d: js     d5b <generic_sleepable_preload+0xd5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3419ULL;
	}
x86_l_633:
	/* 0x633: cmp    WORD PTR [rbx-0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744039349813248ULL);
x86_l_638:
	/* 0x638: je     bc7 <generic_sleepable_preload+0xbc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3015ULL;
	}
x86_l_63e:
	/* 0x63e: mov    eax,DWORD PTR [rbx-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551602ULL);
x86_l_641:
	/* 0x641: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_645:
	/* 0x645: cmp    WORD PTR [rbx-0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744030759878656ULL);
x86_l_64a:
	/* 0x64a: je     667 <generic_sleepable_preload+0x667> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1639ULL;
	}
x86_l_64c:
	/* 0x64c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_651:
	/* 0x651: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_655:
	/* 0x655: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_658:
	/* 0x658: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_65d:
	/* 0x65d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 1631ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1631ULL: goto x86_l_65f;
	case 1633ULL: goto x86_l_661;
	case 1639ULL: goto x86_l_667;
	case 1643ULL: goto x86_l_66b;
	case 1649ULL: goto x86_l_671;
	case 1652ULL: goto x86_l_674;
	case 1656ULL: goto x86_l_678;
	case 1661ULL: goto x86_l_67d;
	case 1667ULL: goto x86_l_683;
	case 1672ULL: goto x86_l_688;
	case 1676ULL: goto x86_l_68c;
	case 1679ULL: goto x86_l_68f;
	case 1684ULL: goto x86_l_694;
	case 1686ULL: goto x86_l_696;
	case 1688ULL: goto x86_l_698;
	case 1694ULL: goto x86_l_69e;
	case 1699ULL: goto x86_l_6a3;
	case 1704ULL: goto x86_l_6a8;
	case 1709ULL: goto x86_l_6ad;
	case 1714ULL: goto x86_l_6b2;
	case 1722ULL: goto x86_l_6ba;
	case 1725ULL: goto x86_l_6bd;
	case 1727ULL: goto x86_l_6bf;
	case 1732ULL: goto x86_l_6c4;
	case 1737ULL: goto x86_l_6c9;
	case 1740ULL: goto x86_l_6cc;
	case 1742ULL: goto x86_l_6ce;
	case 1744ULL: goto x86_l_6d0;
	case 1752ULL: goto x86_l_6d8;
	case 1755ULL: goto x86_l_6db;
	case 1757ULL: goto x86_l_6dd;
	case 1762ULL: goto x86_l_6e2;
	case 1767ULL: goto x86_l_6e7;
	case 1770ULL: goto x86_l_6ea;
	case 1772ULL: goto x86_l_6ec;
	case 1774ULL: goto x86_l_6ee;
	case 1782ULL: goto x86_l_6f6;
	case 1785ULL: goto x86_l_6f9;
	case 1787ULL: goto x86_l_6fb;
	case 1792ULL: goto x86_l_700;
	case 1797ULL: goto x86_l_705;
	case 1800ULL: goto x86_l_708;
	case 1802ULL: goto x86_l_70a;
	case 1804ULL: goto x86_l_70c;
	case 1809ULL: goto x86_l_711;
	case 1812ULL: goto x86_l_714;
	case 1814ULL: goto x86_l_716;
	case 1819ULL: goto x86_l_71b;
	case 1824ULL: goto x86_l_720;
	case 1827ULL: goto x86_l_723;
	case 1829ULL: goto x86_l_725;
	case 1832ULL: goto x86_l_728;
	case 1834ULL: goto x86_l_72a;
	case 1836ULL: goto x86_l_72c;
	case 1841ULL: goto x86_l_731;
	case 1843ULL: goto x86_l_733;
	case 1848ULL: goto x86_l_738;
	case 1852ULL: goto x86_l_73c;
	case 1857ULL: goto x86_l_741;
	case 1860ULL: goto x86_l_744;
	case 1863ULL: goto x86_l_747;
	case 1868ULL: goto x86_l_74c;
	case 1874ULL: goto x86_l_752;
	case 1881ULL: goto x86_l_759;
	case 1884ULL: goto x86_l_75c;
	case 1887ULL: goto x86_l_75f;
	case 1890ULL: goto x86_l_762;
	case 1894ULL: goto x86_l_766;
	case 1898ULL: goto x86_l_76a;
	case 1900ULL: goto x86_l_76c;
	case 1906ULL: goto x86_l_772;
	case 1909ULL: goto x86_l_775;
	case 1911ULL: goto x86_l_777;
	case 1916ULL: goto x86_l_77c;
	case 1920ULL: goto x86_l_780;
	case 1923ULL: goto x86_l_783;
	case 1928ULL: goto x86_l_788;
	case 1930ULL: goto x86_l_78a;
	case 1932ULL: goto x86_l_78c;
	case 1938ULL: goto x86_l_792;
	case 1943ULL: goto x86_l_797;
	case 1949ULL: goto x86_l_79d;
	case 1952ULL: goto x86_l_7a0;
	case 1956ULL: goto x86_l_7a4;
	case 1961ULL: goto x86_l_7a9;
	case 1963ULL: goto x86_l_7ab;
	case 1968ULL: goto x86_l_7b0;
	case 1972ULL: goto x86_l_7b4;
	case 1975ULL: goto x86_l_7b7;
	case 1980ULL: goto x86_l_7bc;
	case 1982ULL: goto x86_l_7be;
	case 1984ULL: goto x86_l_7c0;
	case 1990ULL: goto x86_l_7c6;
	case 1995ULL: goto x86_l_7cb;
	case 2001ULL: goto x86_l_7d1;
	case 2004ULL: goto x86_l_7d4;
	case 2008ULL: goto x86_l_7d8;
	case 2013ULL: goto x86_l_7dd;
	case 2015ULL: goto x86_l_7df;
	case 2020ULL: goto x86_l_7e4;
	case 2024ULL: goto x86_l_7e8;
	case 2027ULL: goto x86_l_7eb;
	case 2032ULL: goto x86_l_7f0;
	case 2034ULL: goto x86_l_7f2;
	case 2036ULL: goto x86_l_7f4;
	case 2042ULL: goto x86_l_7fa;
	case 2047ULL: goto x86_l_7ff;
	case 2053ULL: goto x86_l_805;
	case 2056ULL: goto x86_l_808;
	case 2060ULL: goto x86_l_80c;
	case 2065ULL: goto x86_l_811;
	case 2067ULL: goto x86_l_813;
	case 2072ULL: goto x86_l_818;
	case 2076ULL: goto x86_l_81c;
	case 2079ULL: goto x86_l_81f;
	case 2084ULL: goto x86_l_824;
	case 2086ULL: goto x86_l_826;
	case 2088ULL: goto x86_l_828;
	case 2094ULL: goto x86_l_82e;
	case 2099ULL: goto x86_l_833;
	case 2105ULL: goto x86_l_839;
	case 2108ULL: goto x86_l_83c;
	case 2112ULL: goto x86_l_840;
	case 2117ULL: goto x86_l_845;
	case 2119ULL: goto x86_l_847;
	case 2124ULL: goto x86_l_84c;
	case 2128ULL: goto x86_l_850;
	case 2131ULL: goto x86_l_853;
	case 2136ULL: goto x86_l_858;
	case 2138ULL: goto x86_l_85a;
	case 2140ULL: goto x86_l_85c;
	case 2146ULL: goto x86_l_862;
	case 2151ULL: goto x86_l_867;
	case 2157ULL: goto x86_l_86d;
	case 2160ULL: goto x86_l_870;
	case 2164ULL: goto x86_l_874;
	case 2169ULL: goto x86_l_879;
	case 2171ULL: goto x86_l_87b;
	case 2176ULL: goto x86_l_880;
	case 2180ULL: goto x86_l_884;
	case 2183ULL: goto x86_l_887;
	case 2188ULL: goto x86_l_88c;
	case 2190ULL: goto x86_l_88e;
	case 2192ULL: goto x86_l_890;
	case 2198ULL: goto x86_l_896;
	case 2203ULL: goto x86_l_89b;
	case 2209ULL: goto x86_l_8a1;
	case 2212ULL: goto x86_l_8a4;
	case 2216ULL: goto x86_l_8a8;
	case 2221ULL: goto x86_l_8ad;
	case 2223ULL: goto x86_l_8af;
	case 2228ULL: goto x86_l_8b4;
	case 2232ULL: goto x86_l_8b8;
	case 2235ULL: goto x86_l_8bb;
	case 2240ULL: goto x86_l_8c0;
	case 2242ULL: goto x86_l_8c2;
	case 2244ULL: goto x86_l_8c4;
	case 2250ULL: goto x86_l_8ca;
	case 2255ULL: goto x86_l_8cf;
	case 2261ULL: goto x86_l_8d5;
	case 2264ULL: goto x86_l_8d8;
	case 2268ULL: goto x86_l_8dc;
	case 2273ULL: goto x86_l_8e1;
	case 2275ULL: goto x86_l_8e3;
	case 2280ULL: goto x86_l_8e8;
	case 2284ULL: goto x86_l_8ec;
	case 2287ULL: goto x86_l_8ef;
	case 2292ULL: goto x86_l_8f4;
	case 2294ULL: goto x86_l_8f6;
	case 2296ULL: goto x86_l_8f8;
	case 2302ULL: goto x86_l_8fe;
	case 2307ULL: goto x86_l_903;
	case 2313ULL: goto x86_l_909;
	case 2316ULL: goto x86_l_90c;
	case 2320ULL: goto x86_l_910;
	case 2325ULL: goto x86_l_915;
	case 2327ULL: goto x86_l_917;
	case 2332ULL: goto x86_l_91c;
	case 2336ULL: goto x86_l_920;
	case 2339ULL: goto x86_l_923;
	case 2344ULL: goto x86_l_928;
	case 2346ULL: goto x86_l_92a;
	case 2348ULL: goto x86_l_92c;
	case 2354ULL: goto x86_l_932;
	case 2358ULL: goto x86_l_936;
	case 2364ULL: goto x86_l_93c;
	case 2367ULL: goto x86_l_93f;
	case 2371ULL: goto x86_l_943;
	case 2376ULL: goto x86_l_948;
	case 2382ULL: goto x86_l_94e;
	case 2387ULL: goto x86_l_953;
	case 2392ULL: goto x86_l_958;
	case 2395ULL: goto x86_l_95b;
	case 2397ULL: goto x86_l_95d;
	case 2402ULL: goto x86_l_962;
	case 2406ULL: goto x86_l_966;
	case 2409ULL: goto x86_l_969;
	case 2414ULL: goto x86_l_96e;
	case 2416ULL: goto x86_l_970;
	case 2418ULL: goto x86_l_972;
	case 2424ULL: goto x86_l_978;
	case 2429ULL: goto x86_l_97d;
	case 2435ULL: goto x86_l_983;
	case 2438ULL: goto x86_l_986;
	case 2442ULL: goto x86_l_98a;
	case 2447ULL: goto x86_l_98f;
	case 2449ULL: goto x86_l_991;
	case 2454ULL: goto x86_l_996;
	case 2458ULL: goto x86_l_99a;
	case 2461ULL: goto x86_l_99d;
	case 2466ULL: goto x86_l_9a2;
	case 2468ULL: goto x86_l_9a4;
	case 2470ULL: goto x86_l_9a6;
	case 2476ULL: goto x86_l_9ac;
	case 2481ULL: goto x86_l_9b1;
	case 2487ULL: goto x86_l_9b7;
	case 2490ULL: goto x86_l_9ba;
	case 2494ULL: goto x86_l_9be;
	case 2499ULL: goto x86_l_9c3;
	case 2501ULL: goto x86_l_9c5;
	case 2506ULL: goto x86_l_9ca;
	case 2510ULL: goto x86_l_9ce;
	case 2513ULL: goto x86_l_9d1;
	case 2518ULL: goto x86_l_9d6;
	case 2520ULL: goto x86_l_9d8;
	case 2522ULL: goto x86_l_9da;
	case 2528ULL: goto x86_l_9e0;
	case 2533ULL: goto x86_l_9e5;
	case 2539ULL: goto x86_l_9eb;
	case 2542ULL: goto x86_l_9ee;
	case 2546ULL: goto x86_l_9f2;
	case 2551ULL: goto x86_l_9f7;
	case 2553ULL: goto x86_l_9f9;
	case 2558ULL: goto x86_l_9fe;
	case 2562ULL: goto x86_l_a02;
	case 2565ULL: goto x86_l_a05;
	case 2570ULL: goto x86_l_a0a;
	case 2572ULL: goto x86_l_a0c;
	case 2574ULL: goto x86_l_a0e;
	case 2580ULL: goto x86_l_a14;
	case 2585ULL: goto x86_l_a19;
	case 2591ULL: goto x86_l_a1f;
	case 2594ULL: goto x86_l_a22;
	case 2598ULL: goto x86_l_a26;
	case 2603ULL: goto x86_l_a2b;
	case 2605ULL: goto x86_l_a2d;
	case 2610ULL: goto x86_l_a32;
	case 2614ULL: goto x86_l_a36;
	case 2617ULL: goto x86_l_a39;
	case 2622ULL: goto x86_l_a3e;
	case 2624ULL: goto x86_l_a40;
	case 2626ULL: goto x86_l_a42;
	case 2632ULL: goto x86_l_a48;
	case 2637ULL: goto x86_l_a4d;
	case 2643ULL: goto x86_l_a53;
	case 2646ULL: goto x86_l_a56;
	case 2650ULL: goto x86_l_a5a;
	case 2655ULL: goto x86_l_a5f;
	case 2657ULL: goto x86_l_a61;
	case 2662ULL: goto x86_l_a66;
	case 2666ULL: goto x86_l_a6a;
	case 2669ULL: goto x86_l_a6d;
	case 2674ULL: goto x86_l_a72;
	case 2676ULL: goto x86_l_a74;
	case 2678ULL: goto x86_l_a76;
	case 2684ULL: goto x86_l_a7c;
	case 2689ULL: goto x86_l_a81;
	case 2695ULL: goto x86_l_a87;
	case 2698ULL: goto x86_l_a8a;
	case 2702ULL: goto x86_l_a8e;
	case 2707ULL: goto x86_l_a93;
	case 2709ULL: goto x86_l_a95;
	case 2714ULL: goto x86_l_a9a;
	case 2718ULL: goto x86_l_a9e;
	case 2721ULL: goto x86_l_aa1;
	case 2726ULL: goto x86_l_aa6;
	case 2728ULL: goto x86_l_aa8;
	case 2730ULL: goto x86_l_aaa;
	case 2736ULL: goto x86_l_ab0;
	case 2741ULL: goto x86_l_ab5;
	case 2747ULL: goto x86_l_abb;
	case 2750ULL: goto x86_l_abe;
	case 2754ULL: goto x86_l_ac2;
	case 2759ULL: goto x86_l_ac7;
	case 2761ULL: goto x86_l_ac9;
	case 2766ULL: goto x86_l_ace;
	case 2770ULL: goto x86_l_ad2;
	case 2773ULL: goto x86_l_ad5;
	case 2778ULL: goto x86_l_ada;
	case 2780ULL: goto x86_l_adc;
	case 2782ULL: goto x86_l_ade;
	case 2788ULL: goto x86_l_ae4;
	case 2793ULL: goto x86_l_ae9;
	case 2799ULL: goto x86_l_aef;
	case 2802ULL: goto x86_l_af2;
	case 2806ULL: goto x86_l_af6;
	case 2811ULL: goto x86_l_afb;
	case 2813ULL: goto x86_l_afd;
	case 2818ULL: goto x86_l_b02;
	case 2822ULL: goto x86_l_b06;
	case 2825ULL: goto x86_l_b09;
	case 2830ULL: goto x86_l_b0e;
	case 2832ULL: goto x86_l_b10;
	case 2834ULL: goto x86_l_b12;
	case 2840ULL: goto x86_l_b18;
	case 2844ULL: goto x86_l_b1c;
	case 2850ULL: goto x86_l_b22;
	case 2853ULL: goto x86_l_b25;
	case 2857ULL: goto x86_l_b29;
	case 2862ULL: goto x86_l_b2e;
	case 2868ULL: goto x86_l_b34;
	case 2873ULL: goto x86_l_b39;
	case 2877ULL: goto x86_l_b3d;
	case 2880ULL: goto x86_l_b40;
	case 2885ULL: goto x86_l_b45;
	case 2887ULL: goto x86_l_b47;
	case 2889ULL: goto x86_l_b49;
	case 2895ULL: goto x86_l_b4f;
	case 2901ULL: goto x86_l_b55;
	case 2906ULL: goto x86_l_b5a;
	case 2912ULL: goto x86_l_b60;
	case 2917ULL: goto x86_l_b65;
	case 2922ULL: goto x86_l_b6a;
	case 2924ULL: goto x86_l_b6c;
	case 2930ULL: goto x86_l_b72;
	case 2935ULL: goto x86_l_b77;
	case 2940ULL: goto x86_l_b7c;
	case 2942ULL: goto x86_l_b7e;
	case 2948ULL: goto x86_l_b84;
	case 2953ULL: goto x86_l_b89;
	case 2958ULL: goto x86_l_b8e;
	case 2960ULL: goto x86_l_b90;
	case 2966ULL: goto x86_l_b96;
	case 2971ULL: goto x86_l_b9b;
	case 2976ULL: goto x86_l_ba0;
	case 2978ULL: goto x86_l_ba2;
	case 2984ULL: goto x86_l_ba8;
	case 2989ULL: goto x86_l_bad;
	case 2994ULL: goto x86_l_bb2;
	case 2996ULL: goto x86_l_bb4;
	case 3002ULL: goto x86_l_bba;
	case 3007ULL: goto x86_l_bbf;
	case 3012ULL: goto x86_l_bc4;
	case 3015ULL: goto x86_l_bc7;
	case 3020ULL: goto x86_l_bcc;
	case 3025ULL: goto x86_l_bd1;
	case 3028ULL: goto x86_l_bd4;
	case 3033ULL: goto x86_l_bd9;
	case 3036ULL: goto x86_l_bdc;
	case 3038ULL: goto x86_l_bde;
	case 3042ULL: goto x86_l_be2;
	case 3048ULL: goto x86_l_be8;
	case 3052ULL: goto x86_l_bec;
	case 3060ULL: goto x86_l_bf4;
	case 3065ULL: goto x86_l_bf9;
	case 3067ULL: goto x86_l_bfb;
	case 3072ULL: goto x86_l_c00;
	case 3080ULL: goto x86_l_c08;
	case 3085ULL: goto x86_l_c0d;
	case 3092ULL: goto x86_l_c14;
	case 3097ULL: goto x86_l_c19;
	case 3099ULL: goto x86_l_c1b;
	case 3102ULL: goto x86_l_c1e;
	case 3108ULL: goto x86_l_c24;
	case 3114ULL: goto x86_l_c2a;
	case 3121ULL: goto x86_l_c31;
	case 3124ULL: goto x86_l_c34;
	case 3127ULL: goto x86_l_c37;
	case 3130ULL: goto x86_l_c3a;
	case 3135ULL: goto x86_l_c3f;
	case 3138ULL: goto x86_l_c42;
	case 3141ULL: goto x86_l_c45;
	case 3143ULL: goto x86_l_c47;
	case 3146ULL: goto x86_l_c4a;
	case 3151ULL: goto x86_l_c4f;
	case 3154ULL: goto x86_l_c52;
	case 3157ULL: goto x86_l_c55;
	case 3160ULL: goto x86_l_c58;
	case 3162ULL: goto x86_l_c5a;
	case 3165ULL: goto x86_l_c5d;
	case 3171ULL: goto x86_l_c63;
	case 3174ULL: goto x86_l_c66;
	case 3180ULL: goto x86_l_c6c;
	case 3184ULL: goto x86_l_c70;
	default: return 0xffffffffffffffffULL;
	}
x86_l_65f:
	/* 0x65f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_661:
	/* 0x661: js     d7f <generic_sleepable_preload+0xd7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3455ULL;
	}
x86_l_667:
	/* 0x667: cmp    WORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_66b:
	/* 0x66b: je     bc7 <generic_sleepable_preload+0xbc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bc7;
	}
x86_l_671:
	/* 0x671: mov    eax,DWORD PTR [rbx-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_674:
	/* 0x674: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_678:
	/* 0x678: cmp    WORD PTR [rbx-0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744065119617024ULL);
x86_l_67d:
	/* 0x67d: je     bc7 <generic_sleepable_preload+0xbc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bc7;
	}
x86_l_683:
	/* 0x683: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_688:
	/* 0x688: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_68c:
	/* 0x68c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_68f:
	/* 0x68f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_694:
	/* 0x694: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_696:
	/* 0x696: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_698:
	/* 0x698: jns    bc7 <generic_sleepable_preload+0xbc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_bc7;
	}
x86_l_69e:
	/* 0x69e: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_6a3:
	/* 0x6a3: jmp    bc4 <generic_sleepable_preload+0xbc4> */
	goto x86_l_bc4;
x86_l_6a8:
	/* 0x6a8: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_6ad:
	/* 0x6ad: jmp    bc4 <generic_sleepable_preload+0xbc4> */
	goto x86_l_bc4;
x86_l_6b2:
	/* 0x6b2: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_6ba:
	/* 0x6ba: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_6bd:
	/* 0x6bd: je     725 <generic_sleepable_preload+0x725> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_725;
	}
x86_l_6bf:
	/* 0x6bf: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6c4:
	/* 0x6c4: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_6c9:
	/* 0x6c9: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_6cc:
	/* 0x6cc: je     725 <generic_sleepable_preload+0x725> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_725;
	}
x86_l_6ce:
	/* 0x6ce: jmp    738 <generic_sleepable_preload+0x738> */
	goto x86_l_738;
x86_l_6d0:
	/* 0x6d0: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_6d8:
	/* 0x6d8: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_6db:
	/* 0x6db: je     725 <generic_sleepable_preload+0x725> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_725;
	}
x86_l_6dd:
	/* 0x6dd: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_6e2:
	/* 0x6e2: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_6e7:
	/* 0x6e7: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_6ea:
	/* 0x6ea: je     725 <generic_sleepable_preload+0x725> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_725;
	}
x86_l_6ec:
	/* 0x6ec: jmp    738 <generic_sleepable_preload+0x738> */
	goto x86_l_738;
x86_l_6ee:
	/* 0x6ee: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_6f6:
	/* 0x6f6: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_6f9:
	/* 0x6f9: je     725 <generic_sleepable_preload+0x725> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_725;
	}
x86_l_6fb:
	/* 0x6fb: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_700:
	/* 0x700: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_705:
	/* 0x705: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_708:
	/* 0x708: je     725 <generic_sleepable_preload+0x725> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_725;
	}
x86_l_70a:
	/* 0x70a: jmp    738 <generic_sleepable_preload+0x738> */
	goto x86_l_738;
x86_l_70c:
	/* 0x70c: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_711:
	/* 0x711: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_714:
	/* 0x714: je     725 <generic_sleepable_preload+0x725> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_725;
	}
x86_l_716:
	/* 0x716: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_71b:
	/* 0x71b: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_720:
	/* 0x720: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_723:
	/* 0x723: jne    738 <generic_sleepable_preload+0x738> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_738;
	}
x86_l_725:
	/* 0x725: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_728:
	/* 0x728: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_72a:
	/* 0x72a: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_72c:
	/* 0x72c: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_731:
	/* 0x731: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_733:
	/* 0x733: bzhi   rsi,QWORD PTR [rdx],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RSI, X86_RDX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_738:
	/* 0x738: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_73c:
	/* 0x73c: mov    ebp,DWORD PTR [r13+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 4ULL);
x86_l_741:
	/* 0x741: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_744:
	/* 0x744: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_747:
	/* 0x747: cmp    WORD PTR [rbx-0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743764471906304ULL);
x86_l_74c:
	/* 0x74c: je     ca7 <generic_sleepable_preload+0xca7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3239ULL;
	}
x86_l_752:
	/* 0x752: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_759:
	/* 0x759: movzx  ecx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_75c:
	/* 0x75c: mov    eax,DWORD PTR [rbx-0x4e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551538ULL);
x86_l_75f:
	/* 0x75f: add    rsi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_762:
	/* 0x762: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_766:
	/* 0x766: movzx  eax,WORD PTR [rbx-0x4a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551542ULL);
x86_l_76a:
	/* 0x76a: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_76c:
	/* 0x76c: je     958 <generic_sleepable_preload+0x958> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_958;
	}
x86_l_772:
	/* 0x772: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_775:
	/* 0x775: je     792 <generic_sleepable_preload+0x792> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_792;
	}
x86_l_777:
	/* 0x777: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_77c:
	/* 0x77c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_780:
	/* 0x780: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_783:
	/* 0x783: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_788:
	/* 0x788: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_78a:
	/* 0x78a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_78c:
	/* 0x78c: js     b5a <generic_sleepable_preload+0xb5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_b5a;
	}
x86_l_792:
	/* 0x792: cmp    WORD PTR [rbx-0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743798831644672ULL);
x86_l_797:
	/* 0x797: je     ca7 <generic_sleepable_preload+0xca7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3239ULL;
	}
x86_l_79d:
	/* 0x79d: mov    eax,DWORD PTR [rbx-0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551546ULL);
x86_l_7a0:
	/* 0x7a0: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_7a4:
	/* 0x7a4: cmp    WORD PTR [rbx-0x42],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743790241710080ULL);
x86_l_7a9:
	/* 0x7a9: je     7c6 <generic_sleepable_preload+0x7c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7c6;
	}
x86_l_7ab:
	/* 0x7ab: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_7b0:
	/* 0x7b0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7b4:
	/* 0x7b4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_7b7:
	/* 0x7b7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7bc:
	/* 0x7bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7be:
	/* 0x7be: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_7c0:
	/* 0x7c0: js     b6c <generic_sleepable_preload+0xb6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_b6c;
	}
x86_l_7c6:
	/* 0x7c6: cmp    WORD PTR [rbx-0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743833191383040ULL);
x86_l_7cb:
	/* 0x7cb: je     ca7 <generic_sleepable_preload+0xca7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3239ULL;
	}
x86_l_7d1:
	/* 0x7d1: mov    eax,DWORD PTR [rbx-0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551554ULL);
x86_l_7d4:
	/* 0x7d4: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_7d8:
	/* 0x7d8: cmp    WORD PTR [rbx-0x3a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743824601448448ULL);
x86_l_7dd:
	/* 0x7dd: je     7fa <generic_sleepable_preload+0x7fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7fa;
	}
x86_l_7df:
	/* 0x7df: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_7e4:
	/* 0x7e4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7e8:
	/* 0x7e8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_7eb:
	/* 0x7eb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7f0:
	/* 0x7f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7f2:
	/* 0x7f2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_7f4:
	/* 0x7f4: js     b7e <generic_sleepable_preload+0xb7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_b7e;
	}
x86_l_7fa:
	/* 0x7fa: cmp    WORD PTR [rbx-0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743867551121408ULL);
x86_l_7ff:
	/* 0x7ff: je     ca7 <generic_sleepable_preload+0xca7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3239ULL;
	}
x86_l_805:
	/* 0x805: mov    eax,DWORD PTR [rbx-0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551562ULL);
x86_l_808:
	/* 0x808: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_80c:
	/* 0x80c: cmp    WORD PTR [rbx-0x32],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743858961186816ULL);
x86_l_811:
	/* 0x811: je     82e <generic_sleepable_preload+0x82e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_82e;
	}
x86_l_813:
	/* 0x813: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_818:
	/* 0x818: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_81c:
	/* 0x81c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_81f:
	/* 0x81f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_824:
	/* 0x824: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_826:
	/* 0x826: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_828:
	/* 0x828: js     b90 <generic_sleepable_preload+0xb90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_b90;
	}
x86_l_82e:
	/* 0x82e: cmp    WORD PTR [rbx-0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743901910859776ULL);
x86_l_833:
	/* 0x833: je     ca7 <generic_sleepable_preload+0xca7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3239ULL;
	}
x86_l_839:
	/* 0x839: mov    eax,DWORD PTR [rbx-0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551570ULL);
x86_l_83c:
	/* 0x83c: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_840:
	/* 0x840: cmp    WORD PTR [rbx-0x2a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743893320925184ULL);
x86_l_845:
	/* 0x845: je     862 <generic_sleepable_preload+0x862> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_862;
	}
x86_l_847:
	/* 0x847: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_84c:
	/* 0x84c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_850:
	/* 0x850: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_853:
	/* 0x853: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_858:
	/* 0x858: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_85a:
	/* 0x85a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_85c:
	/* 0x85c: js     ba2 <generic_sleepable_preload+0xba2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_ba2;
	}
x86_l_862:
	/* 0x862: cmp    WORD PTR [rbx-0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743936270598144ULL);
x86_l_867:
	/* 0x867: je     ca7 <generic_sleepable_preload+0xca7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3239ULL;
	}
x86_l_86d:
	/* 0x86d: mov    eax,DWORD PTR [rbx-0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551578ULL);
x86_l_870:
	/* 0x870: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_874:
	/* 0x874: cmp    WORD PTR [rbx-0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743927680663552ULL);
x86_l_879:
	/* 0x879: je     896 <generic_sleepable_preload+0x896> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_896;
	}
x86_l_87b:
	/* 0x87b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_880:
	/* 0x880: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_884:
	/* 0x884: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_887:
	/* 0x887: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_88c:
	/* 0x88c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_88e:
	/* 0x88e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_890:
	/* 0x890: js     bb4 <generic_sleepable_preload+0xbb4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_bb4;
	}
x86_l_896:
	/* 0x896: cmp    WORD PTR [rbx-0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743970630336512ULL);
x86_l_89b:
	/* 0x89b: je     ca7 <generic_sleepable_preload+0xca7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3239ULL;
	}
x86_l_8a1:
	/* 0x8a1: mov    eax,DWORD PTR [rbx-0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551586ULL);
x86_l_8a4:
	/* 0x8a4: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_8a8:
	/* 0x8a8: cmp    WORD PTR [rbx-0x1a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743962040401920ULL);
x86_l_8ad:
	/* 0x8ad: je     8ca <generic_sleepable_preload+0x8ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8ca;
	}
x86_l_8af:
	/* 0x8af: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_8b4:
	/* 0x8b4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8b8:
	/* 0x8b8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_8bb:
	/* 0x8bb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8c0:
	/* 0x8c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8c2:
	/* 0x8c2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_8c4:
	/* 0x8c4: js     c9e <generic_sleepable_preload+0xc9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3230ULL;
	}
x86_l_8ca:
	/* 0x8ca: cmp    WORD PTR [rbx-0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744004990074880ULL);
x86_l_8cf:
	/* 0x8cf: je     ca7 <generic_sleepable_preload+0xca7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3239ULL;
	}
x86_l_8d5:
	/* 0x8d5: mov    eax,DWORD PTR [rbx-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_8d8:
	/* 0x8d8: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_8dc:
	/* 0x8dc: cmp    WORD PTR [rbx-0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743996400140288ULL);
x86_l_8e1:
	/* 0x8e1: je     8fe <generic_sleepable_preload+0x8fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8fe;
	}
x86_l_8e3:
	/* 0x8e3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_8e8:
	/* 0x8e8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8ec:
	/* 0x8ec: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_8ef:
	/* 0x8ef: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8f4:
	/* 0x8f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8f6:
	/* 0x8f6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_8f8:
	/* 0x8f8: js     d68 <generic_sleepable_preload+0xd68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3432ULL;
	}
x86_l_8fe:
	/* 0x8fe: cmp    WORD PTR [rbx-0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744039349813248ULL);
x86_l_903:
	/* 0x903: je     ca7 <generic_sleepable_preload+0xca7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3239ULL;
	}
x86_l_909:
	/* 0x909: mov    eax,DWORD PTR [rbx-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551602ULL);
x86_l_90c:
	/* 0x90c: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_910:
	/* 0x910: cmp    WORD PTR [rbx-0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744030759878656ULL);
x86_l_915:
	/* 0x915: je     932 <generic_sleepable_preload+0x932> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_932;
	}
x86_l_917:
	/* 0x917: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_91c:
	/* 0x91c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_920:
	/* 0x920: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_923:
	/* 0x923: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_928:
	/* 0x928: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_92a:
	/* 0x92a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_92c:
	/* 0x92c: js     d89 <generic_sleepable_preload+0xd89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3465ULL;
	}
x86_l_932:
	/* 0x932: cmp    WORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_936:
	/* 0x936: je     ca7 <generic_sleepable_preload+0xca7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3239ULL;
	}
x86_l_93c:
	/* 0x93c: mov    eax,DWORD PTR [rbx-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_93f:
	/* 0x93f: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_943:
	/* 0x943: cmp    WORD PTR [rbx-0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744065119617024ULL);
x86_l_948:
	/* 0x948: je     ca7 <generic_sleepable_preload+0xca7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3239ULL;
	}
x86_l_94e:
	/* 0x94e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_953:
	/* 0x953: jmp    b39 <generic_sleepable_preload+0xb39> */
	goto x86_l_b39;
x86_l_958:
	/* 0x958: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_95b:
	/* 0x95b: je     978 <generic_sleepable_preload+0x978> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_978;
	}
x86_l_95d:
	/* 0x95d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_962:
	/* 0x962: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_966:
	/* 0x966: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_969:
	/* 0x969: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_96e:
	/* 0x96e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_970:
	/* 0x970: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_972:
	/* 0x972: js     b5a <generic_sleepable_preload+0xb5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_b5a;
	}
x86_l_978:
	/* 0x978: cmp    WORD PTR [rbx-0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743798831644672ULL);
x86_l_97d:
	/* 0x97d: je     ca7 <generic_sleepable_preload+0xca7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3239ULL;
	}
x86_l_983:
	/* 0x983: mov    eax,DWORD PTR [rbx-0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551546ULL);
x86_l_986:
	/* 0x986: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_98a:
	/* 0x98a: cmp    WORD PTR [rbx-0x42],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743790241710080ULL);
x86_l_98f:
	/* 0x98f: je     9ac <generic_sleepable_preload+0x9ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9ac;
	}
x86_l_991:
	/* 0x991: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_996:
	/* 0x996: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_99a:
	/* 0x99a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_99d:
	/* 0x99d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9a2:
	/* 0x9a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9a4:
	/* 0x9a4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_9a6:
	/* 0x9a6: js     b6c <generic_sleepable_preload+0xb6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_b6c;
	}
x86_l_9ac:
	/* 0x9ac: cmp    WORD PTR [rbx-0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743833191383040ULL);
x86_l_9b1:
	/* 0x9b1: je     ca7 <generic_sleepable_preload+0xca7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3239ULL;
	}
x86_l_9b7:
	/* 0x9b7: mov    eax,DWORD PTR [rbx-0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551554ULL);
x86_l_9ba:
	/* 0x9ba: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_9be:
	/* 0x9be: cmp    WORD PTR [rbx-0x3a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743824601448448ULL);
x86_l_9c3:
	/* 0x9c3: je     9e0 <generic_sleepable_preload+0x9e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9e0;
	}
x86_l_9c5:
	/* 0x9c5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_9ca:
	/* 0x9ca: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9ce:
	/* 0x9ce: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_9d1:
	/* 0x9d1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9d6:
	/* 0x9d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9d8:
	/* 0x9d8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_9da:
	/* 0x9da: js     b7e <generic_sleepable_preload+0xb7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_b7e;
	}
x86_l_9e0:
	/* 0x9e0: cmp    WORD PTR [rbx-0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743867551121408ULL);
x86_l_9e5:
	/* 0x9e5: je     ca7 <generic_sleepable_preload+0xca7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3239ULL;
	}
x86_l_9eb:
	/* 0x9eb: mov    eax,DWORD PTR [rbx-0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551562ULL);
x86_l_9ee:
	/* 0x9ee: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_9f2:
	/* 0x9f2: cmp    WORD PTR [rbx-0x32],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743858961186816ULL);
x86_l_9f7:
	/* 0x9f7: je     a14 <generic_sleepable_preload+0xa14> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a14;
	}
x86_l_9f9:
	/* 0x9f9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_9fe:
	/* 0x9fe: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a02:
	/* 0xa02: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_a05:
	/* 0xa05: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a0a:
	/* 0xa0a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a0c:
	/* 0xa0c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a0e:
	/* 0xa0e: js     b90 <generic_sleepable_preload+0xb90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_b90;
	}
x86_l_a14:
	/* 0xa14: cmp    WORD PTR [rbx-0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743901910859776ULL);
x86_l_a19:
	/* 0xa19: je     ca7 <generic_sleepable_preload+0xca7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3239ULL;
	}
x86_l_a1f:
	/* 0xa1f: mov    eax,DWORD PTR [rbx-0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551570ULL);
x86_l_a22:
	/* 0xa22: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_a26:
	/* 0xa26: cmp    WORD PTR [rbx-0x2a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743893320925184ULL);
x86_l_a2b:
	/* 0xa2b: je     a48 <generic_sleepable_preload+0xa48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a48;
	}
x86_l_a2d:
	/* 0xa2d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_a32:
	/* 0xa32: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a36:
	/* 0xa36: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_a39:
	/* 0xa39: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a3e:
	/* 0xa3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a40:
	/* 0xa40: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a42:
	/* 0xa42: js     ba2 <generic_sleepable_preload+0xba2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_ba2;
	}
x86_l_a48:
	/* 0xa48: cmp    WORD PTR [rbx-0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743936270598144ULL);
x86_l_a4d:
	/* 0xa4d: je     ca7 <generic_sleepable_preload+0xca7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3239ULL;
	}
x86_l_a53:
	/* 0xa53: mov    eax,DWORD PTR [rbx-0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551578ULL);
x86_l_a56:
	/* 0xa56: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_a5a:
	/* 0xa5a: cmp    WORD PTR [rbx-0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743927680663552ULL);
x86_l_a5f:
	/* 0xa5f: je     a7c <generic_sleepable_preload+0xa7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a7c;
	}
x86_l_a61:
	/* 0xa61: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_a66:
	/* 0xa66: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a6a:
	/* 0xa6a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_a6d:
	/* 0xa6d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a72:
	/* 0xa72: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a74:
	/* 0xa74: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a76:
	/* 0xa76: js     bb4 <generic_sleepable_preload+0xbb4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_bb4;
	}
x86_l_a7c:
	/* 0xa7c: cmp    WORD PTR [rbx-0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743970630336512ULL);
x86_l_a81:
	/* 0xa81: je     ca7 <generic_sleepable_preload+0xca7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3239ULL;
	}
x86_l_a87:
	/* 0xa87: mov    eax,DWORD PTR [rbx-0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551586ULL);
x86_l_a8a:
	/* 0xa8a: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_a8e:
	/* 0xa8e: cmp    WORD PTR [rbx-0x1a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743962040401920ULL);
x86_l_a93:
	/* 0xa93: je     ab0 <generic_sleepable_preload+0xab0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ab0;
	}
x86_l_a95:
	/* 0xa95: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_a9a:
	/* 0xa9a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a9e:
	/* 0xa9e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_aa1:
	/* 0xaa1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_aa6:
	/* 0xaa6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aa8:
	/* 0xaa8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_aaa:
	/* 0xaaa: js     c9e <generic_sleepable_preload+0xc9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3230ULL;
	}
x86_l_ab0:
	/* 0xab0: cmp    WORD PTR [rbx-0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744004990074880ULL);
x86_l_ab5:
	/* 0xab5: je     ca7 <generic_sleepable_preload+0xca7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3239ULL;
	}
x86_l_abb:
	/* 0xabb: mov    eax,DWORD PTR [rbx-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_abe:
	/* 0xabe: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_ac2:
	/* 0xac2: cmp    WORD PTR [rbx-0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743996400140288ULL);
x86_l_ac7:
	/* 0xac7: je     ae4 <generic_sleepable_preload+0xae4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ae4;
	}
x86_l_ac9:
	/* 0xac9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_ace:
	/* 0xace: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ad2:
	/* 0xad2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_ad5:
	/* 0xad5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ada:
	/* 0xada: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_adc:
	/* 0xadc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ade:
	/* 0xade: js     d68 <generic_sleepable_preload+0xd68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3432ULL;
	}
x86_l_ae4:
	/* 0xae4: cmp    WORD PTR [rbx-0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744039349813248ULL);
x86_l_ae9:
	/* 0xae9: je     ca7 <generic_sleepable_preload+0xca7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3239ULL;
	}
x86_l_aef:
	/* 0xaef: mov    eax,DWORD PTR [rbx-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551602ULL);
x86_l_af2:
	/* 0xaf2: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_af6:
	/* 0xaf6: cmp    WORD PTR [rbx-0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744030759878656ULL);
x86_l_afb:
	/* 0xafb: je     b18 <generic_sleepable_preload+0xb18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b18;
	}
x86_l_afd:
	/* 0xafd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_b02:
	/* 0xb02: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b06:
	/* 0xb06: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_b09:
	/* 0xb09: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b0e:
	/* 0xb0e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b10:
	/* 0xb10: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b12:
	/* 0xb12: js     d89 <generic_sleepable_preload+0xd89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3465ULL;
	}
x86_l_b18:
	/* 0xb18: cmp    WORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b1c:
	/* 0xb1c: je     ca7 <generic_sleepable_preload+0xca7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3239ULL;
	}
x86_l_b22:
	/* 0xb22: mov    eax,DWORD PTR [rbx-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_b25:
	/* 0xb25: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_b29:
	/* 0xb29: cmp    WORD PTR [rbx-0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744065119617024ULL);
x86_l_b2e:
	/* 0xb2e: je     ca7 <generic_sleepable_preload+0xca7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3239ULL;
	}
x86_l_b34:
	/* 0xb34: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_b39:
	/* 0xb39: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b3d:
	/* 0xb3d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_b40:
	/* 0xb40: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b45:
	/* 0xb45: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b47:
	/* 0xb47: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b49:
	/* 0xb49: jns    ca7 <generic_sleepable_preload+0xca7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 3239ULL;
	}
x86_l_b4f:
	/* 0xb4f: mov    r15d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 10ULL);
x86_l_b55:
	/* 0xb55: jmp    ca4 <generic_sleepable_preload+0xca4> */
	return 3236ULL;
x86_l_b5a:
	/* 0xb5a: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_b60:
	/* 0xb60: jmp    ca4 <generic_sleepable_preload+0xca4> */
	return 3236ULL;
x86_l_b65:
	/* 0xb65: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_b6a:
	/* 0xb6a: jmp    bc4 <generic_sleepable_preload+0xbc4> */
	goto x86_l_bc4;
x86_l_b6c:
	/* 0xb6c: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_b72:
	/* 0xb72: jmp    ca4 <generic_sleepable_preload+0xca4> */
	return 3236ULL;
x86_l_b77:
	/* 0xb77: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_b7c:
	/* 0xb7c: jmp    bc4 <generic_sleepable_preload+0xbc4> */
	goto x86_l_bc4;
x86_l_b7e:
	/* 0xb7e: mov    r15d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 3ULL);
x86_l_b84:
	/* 0xb84: jmp    ca4 <generic_sleepable_preload+0xca4> */
	return 3236ULL;
x86_l_b89:
	/* 0xb89: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_b8e:
	/* 0xb8e: jmp    bc4 <generic_sleepable_preload+0xbc4> */
	goto x86_l_bc4;
x86_l_b90:
	/* 0xb90: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_b96:
	/* 0xb96: jmp    ca4 <generic_sleepable_preload+0xca4> */
	return 3236ULL;
x86_l_b9b:
	/* 0xb9b: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_ba0:
	/* 0xba0: jmp    bc4 <generic_sleepable_preload+0xbc4> */
	goto x86_l_bc4;
x86_l_ba2:
	/* 0xba2: mov    r15d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 5ULL);
x86_l_ba8:
	/* 0xba8: jmp    ca4 <generic_sleepable_preload+0xca4> */
	return 3236ULL;
x86_l_bad:
	/* 0xbad: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_bb2:
	/* 0xbb2: jmp    bc4 <generic_sleepable_preload+0xbc4> */
	goto x86_l_bc4;
x86_l_bb4:
	/* 0xbb4: mov    r15d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 6ULL);
x86_l_bba:
	/* 0xbba: jmp    ca4 <generic_sleepable_preload+0xca4> */
	return 3236ULL;
x86_l_bbf:
	/* 0xbbf: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_bc4:
	/* 0xbc4: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bc7:
	/* 0xbc7: mov    r12d,DWORD PTR [r13+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 4ULL);
x86_l_bcc:
	/* 0xbcc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_bd1:
	/* 0xbd1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_bd4:
	/* 0xbd4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bd9:
	/* 0xbd9: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_bdc:
	/* 0xbdc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bde:
	/* 0xbde: cmp    r12d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 6ULL);
x86_l_be2:
	/* 0xbe2: jne    111 <generic_sleepable_preload+0x111> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 273ULL;
	}
x86_l_be8:
	/* 0xbe8: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bec:
	/* 0xbec: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_bf4:
	/* 0xbf4: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_bf9:
	/* 0xbf9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bfb:
	/* 0xbfb: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c00:
	/* 0xc00: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_c08:
	/* 0xc08: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c0d:
	/* 0xc0d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_c14:
	/* 0xc14: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_c19:
	/* 0xc19: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c1b:
	/* 0xc1b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c1e:
	/* 0xc1e: je     10c <generic_sleepable_preload+0x10c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 268ULL;
	}
x86_l_c24:
	/* 0xc24: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_c2a:
	/* 0xc2a: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_c31:
	/* 0xc31: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_c34:
	/* 0xc34: mov    r13d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_32);
x86_l_c37:
	/* 0xc37: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_c3a:
	/* 0xc3a: lea    rbp,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c3f:
	/* 0xc3f: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_c42:
	/* 0xc42: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_c45:
	/* 0xc45: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c47:
	/* 0xc47: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_c4a:
	/* 0xc4a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c4f:
	/* 0xc4f: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_c52:
	/* 0xc52: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_c55:
	/* 0xc55: mov    ebp,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_32);
x86_l_c58:
	/* 0xc58: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c5a:
	/* 0xc5a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c5d:
	/* 0xc5d: je     10c <generic_sleepable_preload+0x10c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 268ULL;
	}
x86_l_c63:
	/* 0xc63: test   r13b,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_8);
x86_l_c66:
	/* 0xc66: je     10a <generic_sleepable_preload+0x10a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 266ULL;
	}
x86_l_c6c:
	/* 0xc6c: lea    rdi,[rax+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_c70:
	/* 0xc70: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
	return 3189ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3189ULL: goto x86_l_c75;
	case 3197ULL: goto x86_l_c7d;
	case 3199ULL: goto x86_l_c7f;
	case 3202ULL: goto x86_l_c82;
	case 3207ULL: goto x86_l_c87;
	case 3209ULL: goto x86_l_c89;
	case 3212ULL: goto x86_l_c8c;
	case 3214ULL: goto x86_l_c8e;
	case 3220ULL: goto x86_l_c94;
	case 3225ULL: goto x86_l_c99;
	case 3230ULL: goto x86_l_c9e;
	case 3236ULL: goto x86_l_ca4;
	case 3239ULL: goto x86_l_ca7;
	case 3242ULL: goto x86_l_caa;
	case 3248ULL: goto x86_l_cb0;
	case 3252ULL: goto x86_l_cb4;
	case 3260ULL: goto x86_l_cbc;
	case 3265ULL: goto x86_l_cc1;
	case 3267ULL: goto x86_l_cc3;
	case 3272ULL: goto x86_l_cc8;
	case 3280ULL: goto x86_l_cd0;
	case 3285ULL: goto x86_l_cd5;
	case 3292ULL: goto x86_l_cdc;
	case 3297ULL: goto x86_l_ce1;
	case 3299ULL: goto x86_l_ce3;
	case 3302ULL: goto x86_l_ce6;
	case 3308ULL: goto x86_l_cec;
	case 3314ULL: goto x86_l_cf2;
	case 3321ULL: goto x86_l_cf9;
	case 3324ULL: goto x86_l_cfc;
	case 3327ULL: goto x86_l_cff;
	case 3330ULL: goto x86_l_d02;
	case 3335ULL: goto x86_l_d07;
	case 3338ULL: goto x86_l_d0a;
	case 3341ULL: goto x86_l_d0d;
	case 3343ULL: goto x86_l_d0f;
	case 3346ULL: goto x86_l_d12;
	case 3351ULL: goto x86_l_d17;
	case 3354ULL: goto x86_l_d1a;
	case 3357ULL: goto x86_l_d1d;
	case 3359ULL: goto x86_l_d1f;
	case 3362ULL: goto x86_l_d22;
	case 3368ULL: goto x86_l_d28;
	case 3371ULL: goto x86_l_d2b;
	case 3374ULL: goto x86_l_d2e;
	case 3376ULL: goto x86_l_d30;
	case 3380ULL: goto x86_l_d34;
	case 3385ULL: goto x86_l_d39;
	case 3393ULL: goto x86_l_d41;
	case 3395ULL: goto x86_l_d43;
	case 3400ULL: goto x86_l_d48;
	case 3402ULL: goto x86_l_d4a;
	case 3404ULL: goto x86_l_d4c;
	case 3410ULL: goto x86_l_d52;
	case 3414ULL: goto x86_l_d56;
	case 3419ULL: goto x86_l_d5b;
	case 3422ULL: goto x86_l_d5e;
	case 3427ULL: goto x86_l_d63;
	case 3432ULL: goto x86_l_d68;
	case 3435ULL: goto x86_l_d6b;
	case 3441ULL: goto x86_l_d71;
	case 3444ULL: goto x86_l_d74;
	case 3450ULL: goto x86_l_d7a;
	case 3455ULL: goto x86_l_d7f;
	case 3460ULL: goto x86_l_d84;
	case 3465ULL: goto x86_l_d89;
	case 3471ULL: goto x86_l_d8f;
	case 3476ULL: goto x86_l_d94;
	case 3480ULL: goto x86_l_d98;
	case 3485ULL: goto x86_l_d9d;
	case 3487ULL: goto x86_l_d9f;
	case 3491ULL: goto x86_l_da3;
	case 3496ULL: goto x86_l_da8;
	case 3502ULL: goto x86_l_dae;
	case 3506ULL: goto x86_l_db2;
	case 3511ULL: goto x86_l_db7;
	case 3517ULL: goto x86_l_dbd;
	case 3522ULL: goto x86_l_dc2;
	case 3524ULL: goto x86_l_dc4;
	case 3526ULL: goto x86_l_dc6;
	case 3530ULL: goto x86_l_dca;
	case 3533ULL: goto x86_l_dcd;
	case 3539ULL: goto x86_l_dd3;
	case 3542ULL: goto x86_l_dd6;
	case 3548ULL: goto x86_l_ddc;
	case 3551ULL: goto x86_l_ddf;
	case 3557ULL: goto x86_l_de5;
	case 3560ULL: goto x86_l_de8;
	case 3566ULL: goto x86_l_dee;
	case 3571ULL: goto x86_l_df3;
	case 3576ULL: goto x86_l_df8;
	case 3584ULL: goto x86_l_e00;
	case 3592ULL: goto x86_l_e08;
	case 3598ULL: goto x86_l_e0e;
	case 3600ULL: goto x86_l_e10;
	case 3603ULL: goto x86_l_e13;
	case 3605ULL: goto x86_l_e15;
	case 3608ULL: goto x86_l_e18;
	case 3610ULL: goto x86_l_e1a;
	case 3613ULL: goto x86_l_e1d;
	case 3619ULL: goto x86_l_e23;
	case 3624ULL: goto x86_l_e28;
	case 3627ULL: goto x86_l_e2b;
	case 3633ULL: goto x86_l_e31;
	case 3638ULL: goto x86_l_e36;
	case 3641ULL: goto x86_l_e39;
	case 3647ULL: goto x86_l_e3f;
	case 3650ULL: goto x86_l_e42;
	case 3656ULL: goto x86_l_e48;
	case 3661ULL: goto x86_l_e4d;
	case 3666ULL: goto x86_l_e52;
	case 3669ULL: goto x86_l_e55;
	case 3671ULL: goto x86_l_e57;
	case 3674ULL: goto x86_l_e5a;
	case 3680ULL: goto x86_l_e60;
	case 3685ULL: goto x86_l_e65;
	case 3687ULL: goto x86_l_e67;
	case 3693ULL: goto x86_l_e6d;
	case 3696ULL: goto x86_l_e70;
	case 3699ULL: goto x86_l_e73;
	case 3705ULL: goto x86_l_e79;
	case 3710ULL: goto x86_l_e7e;
	case 3712ULL: goto x86_l_e80;
	case 3714ULL: goto x86_l_e82;
	case 3717ULL: goto x86_l_e85;
	case 3719ULL: goto x86_l_e87;
	case 3724ULL: goto x86_l_e8c;
	case 3726ULL: goto x86_l_e8e;
	case 3729ULL: goto x86_l_e91;
	case 3735ULL: goto x86_l_e97;
	case 3743ULL: goto x86_l_e9f;
	case 3746ULL: goto x86_l_ea2;
	case 3752ULL: goto x86_l_ea8;
	case 3757ULL: goto x86_l_ead;
	case 3760ULL: goto x86_l_eb0;
	case 3766ULL: goto x86_l_eb6;
	case 3771ULL: goto x86_l_ebb;
	case 3774ULL: goto x86_l_ebe;
	case 3780ULL: goto x86_l_ec4;
	case 3788ULL: goto x86_l_ecc;
	case 3791ULL: goto x86_l_ecf;
	case 3797ULL: goto x86_l_ed5;
	case 3802ULL: goto x86_l_eda;
	case 3805ULL: goto x86_l_edd;
	case 3811ULL: goto x86_l_ee3;
	case 3816ULL: goto x86_l_ee8;
	case 3821ULL: goto x86_l_eed;
	case 3823ULL: goto x86_l_eef;
	case 3828ULL: goto x86_l_ef4;
	case 3830ULL: goto x86_l_ef6;
	case 3835ULL: goto x86_l_efb;
	case 3838ULL: goto x86_l_efe;
	case 3842ULL: goto x86_l_f02;
	case 3844ULL: goto x86_l_f04;
	case 3847ULL: goto x86_l_f07;
	case 3853ULL: goto x86_l_f0d;
	case 3859ULL: goto x86_l_f13;
	case 3866ULL: goto x86_l_f1a;
	case 3869ULL: goto x86_l_f1d;
	case 3873ULL: goto x86_l_f21;
	case 3876ULL: goto x86_l_f24;
	case 3880ULL: goto x86_l_f28;
	case 3885ULL: goto x86_l_f2d;
	case 3887ULL: goto x86_l_f2f;
	case 3893ULL: goto x86_l_f35;
	case 3896ULL: goto x86_l_f38;
	case 3898ULL: goto x86_l_f3a;
	case 3903ULL: goto x86_l_f3f;
	case 3907ULL: goto x86_l_f43;
	case 3910ULL: goto x86_l_f46;
	case 3915ULL: goto x86_l_f4b;
	case 3917ULL: goto x86_l_f4d;
	case 3919ULL: goto x86_l_f4f;
	case 3925ULL: goto x86_l_f55;
	case 3931ULL: goto x86_l_f5b;
	case 3937ULL: goto x86_l_f61;
	case 3941ULL: goto x86_l_f65;
	case 3945ULL: goto x86_l_f69;
	case 3951ULL: goto x86_l_f6f;
	case 3953ULL: goto x86_l_f71;
	case 3958ULL: goto x86_l_f76;
	case 3962ULL: goto x86_l_f7a;
	case 3965ULL: goto x86_l_f7d;
	case 3970ULL: goto x86_l_f82;
	case 3972ULL: goto x86_l_f84;
	case 3974ULL: goto x86_l_f86;
	case 3980ULL: goto x86_l_f8c;
	case 3989ULL: goto x86_l_f95;
	case 3995ULL: goto x86_l_f9b;
	case 4002ULL: goto x86_l_fa2;
	case 4006ULL: goto x86_l_fa6;
	case 4015ULL: goto x86_l_faf;
	case 4017ULL: goto x86_l_fb1;
	case 4022ULL: goto x86_l_fb6;
	case 4026ULL: goto x86_l_fba;
	case 4029ULL: goto x86_l_fbd;
	case 4034ULL: goto x86_l_fc2;
	case 4036ULL: goto x86_l_fc4;
	case 4038ULL: goto x86_l_fc6;
	case 4044ULL: goto x86_l_fcc;
	case 4053ULL: goto x86_l_fd5;
	case 4059ULL: goto x86_l_fdb;
	case 4066ULL: goto x86_l_fe2;
	case 4070ULL: goto x86_l_fe6;
	case 4079ULL: goto x86_l_fef;
	case 4081ULL: goto x86_l_ff1;
	case 4086ULL: goto x86_l_ff6;
	case 4090ULL: goto x86_l_ffa;
	case 4093ULL: goto x86_l_ffd;
	case 4098ULL: goto x86_l_1002;
	case 4100ULL: goto x86_l_1004;
	case 4102ULL: goto x86_l_1006;
	case 4108ULL: goto x86_l_100c;
	case 4117ULL: goto x86_l_1015;
	case 4123ULL: goto x86_l_101b;
	case 4130ULL: goto x86_l_1022;
	case 4134ULL: goto x86_l_1026;
	case 4143ULL: goto x86_l_102f;
	case 4145ULL: goto x86_l_1031;
	case 4150ULL: goto x86_l_1036;
	case 4154ULL: goto x86_l_103a;
	case 4157ULL: goto x86_l_103d;
	case 4162ULL: goto x86_l_1042;
	case 4164ULL: goto x86_l_1044;
	case 4166ULL: goto x86_l_1046;
	case 4172ULL: goto x86_l_104c;
	case 4181ULL: goto x86_l_1055;
	case 4187ULL: goto x86_l_105b;
	case 4194ULL: goto x86_l_1062;
	case 4198ULL: goto x86_l_1066;
	case 4207ULL: goto x86_l_106f;
	case 4209ULL: goto x86_l_1071;
	case 4214ULL: goto x86_l_1076;
	case 4218ULL: goto x86_l_107a;
	case 4221ULL: goto x86_l_107d;
	case 4226ULL: goto x86_l_1082;
	case 4228ULL: goto x86_l_1084;
	case 4230ULL: goto x86_l_1086;
	case 4236ULL: goto x86_l_108c;
	case 4245ULL: goto x86_l_1095;
	case 4251ULL: goto x86_l_109b;
	case 4258ULL: goto x86_l_10a2;
	case 4262ULL: goto x86_l_10a6;
	case 4271ULL: goto x86_l_10af;
	case 4273ULL: goto x86_l_10b1;
	case 4278ULL: goto x86_l_10b6;
	case 4282ULL: goto x86_l_10ba;
	case 4285ULL: goto x86_l_10bd;
	case 4290ULL: goto x86_l_10c2;
	case 4292ULL: goto x86_l_10c4;
	case 4294ULL: goto x86_l_10c6;
	case 4300ULL: goto x86_l_10cc;
	case 4309ULL: goto x86_l_10d5;
	case 4315ULL: goto x86_l_10db;
	case 4322ULL: goto x86_l_10e2;
	case 4326ULL: goto x86_l_10e6;
	case 4335ULL: goto x86_l_10ef;
	case 4337ULL: goto x86_l_10f1;
	case 4342ULL: goto x86_l_10f6;
	case 4346ULL: goto x86_l_10fa;
	case 4349ULL: goto x86_l_10fd;
	case 4354ULL: goto x86_l_1102;
	case 4356ULL: goto x86_l_1104;
	case 4358ULL: goto x86_l_1106;
	case 4364ULL: goto x86_l_110c;
	case 4373ULL: goto x86_l_1115;
	case 4379ULL: goto x86_l_111b;
	case 4386ULL: goto x86_l_1122;
	case 4390ULL: goto x86_l_1126;
	case 4399ULL: goto x86_l_112f;
	case 4401ULL: goto x86_l_1131;
	case 4406ULL: goto x86_l_1136;
	case 4410ULL: goto x86_l_113a;
	case 4413ULL: goto x86_l_113d;
	case 4418ULL: goto x86_l_1142;
	case 4420ULL: goto x86_l_1144;
	case 4422ULL: goto x86_l_1146;
	case 4428ULL: goto x86_l_114c;
	case 4433ULL: goto x86_l_1151;
	case 4442ULL: goto x86_l_115a;
	case 4448ULL: goto x86_l_1160;
	case 4455ULL: goto x86_l_1167;
	case 4459ULL: goto x86_l_116b;
	case 4468ULL: goto x86_l_1174;
	case 4474ULL: goto x86_l_117a;
	case 4479ULL: goto x86_l_117f;
	case 4484ULL: goto x86_l_1184;
	case 4487ULL: goto x86_l_1187;
	case 4489ULL: goto x86_l_1189;
	case 4494ULL: goto x86_l_118e;
	case 4498ULL: goto x86_l_1192;
	case 4501ULL: goto x86_l_1195;
	case 4506ULL: goto x86_l_119a;
	case 4508ULL: goto x86_l_119c;
	case 4510ULL: goto x86_l_119e;
	case 4516ULL: goto x86_l_11a4;
	case 4522ULL: goto x86_l_11aa;
	case 4528ULL: goto x86_l_11b0;
	case 4532ULL: goto x86_l_11b4;
	case 4536ULL: goto x86_l_11b8;
	case 4542ULL: goto x86_l_11be;
	case 4544ULL: goto x86_l_11c0;
	case 4549ULL: goto x86_l_11c5;
	case 4553ULL: goto x86_l_11c9;
	case 4556ULL: goto x86_l_11cc;
	case 4561ULL: goto x86_l_11d1;
	case 4563ULL: goto x86_l_11d3;
	case 4565ULL: goto x86_l_11d5;
	case 4571ULL: goto x86_l_11db;
	case 4580ULL: goto x86_l_11e4;
	case 4586ULL: goto x86_l_11ea;
	case 4593ULL: goto x86_l_11f1;
	case 4597ULL: goto x86_l_11f5;
	case 4606ULL: goto x86_l_11fe;
	case 4608ULL: goto x86_l_1200;
	case 4613ULL: goto x86_l_1205;
	case 4617ULL: goto x86_l_1209;
	case 4620ULL: goto x86_l_120c;
	case 4625ULL: goto x86_l_1211;
	case 4627ULL: goto x86_l_1213;
	case 4629ULL: goto x86_l_1215;
	case 4635ULL: goto x86_l_121b;
	case 4644ULL: goto x86_l_1224;
	case 4650ULL: goto x86_l_122a;
	case 4657ULL: goto x86_l_1231;
	case 4661ULL: goto x86_l_1235;
	case 4670ULL: goto x86_l_123e;
	case 4672ULL: goto x86_l_1240;
	case 4677ULL: goto x86_l_1245;
	case 4681ULL: goto x86_l_1249;
	case 4684ULL: goto x86_l_124c;
	case 4689ULL: goto x86_l_1251;
	case 4691ULL: goto x86_l_1253;
	case 4693ULL: goto x86_l_1255;
	case 4699ULL: goto x86_l_125b;
	case 4708ULL: goto x86_l_1264;
	case 4714ULL: goto x86_l_126a;
	case 4721ULL: goto x86_l_1271;
	case 4725ULL: goto x86_l_1275;
	case 4734ULL: goto x86_l_127e;
	case 4736ULL: goto x86_l_1280;
	case 4741ULL: goto x86_l_1285;
	case 4745ULL: goto x86_l_1289;
	case 4748ULL: goto x86_l_128c;
	case 4753ULL: goto x86_l_1291;
	case 4755ULL: goto x86_l_1293;
	case 4757ULL: goto x86_l_1295;
	case 4763ULL: goto x86_l_129b;
	case 4772ULL: goto x86_l_12a4;
	case 4778ULL: goto x86_l_12aa;
	case 4785ULL: goto x86_l_12b1;
	case 4789ULL: goto x86_l_12b5;
	case 4798ULL: goto x86_l_12be;
	case 4800ULL: goto x86_l_12c0;
	case 4805ULL: goto x86_l_12c5;
	case 4809ULL: goto x86_l_12c9;
	case 4812ULL: goto x86_l_12cc;
	case 4817ULL: goto x86_l_12d1;
	case 4819ULL: goto x86_l_12d3;
	case 4821ULL: goto x86_l_12d5;
	case 4827ULL: goto x86_l_12db;
	case 4836ULL: goto x86_l_12e4;
	case 4842ULL: goto x86_l_12ea;
	case 4849ULL: goto x86_l_12f1;
	case 4853ULL: goto x86_l_12f5;
	case 4862ULL: goto x86_l_12fe;
	case 4864ULL: goto x86_l_1300;
	case 4869ULL: goto x86_l_1305;
	case 4873ULL: goto x86_l_1309;
	case 4876ULL: goto x86_l_130c;
	case 4881ULL: goto x86_l_1311;
	case 4883ULL: goto x86_l_1313;
	case 4885ULL: goto x86_l_1315;
	case 4891ULL: goto x86_l_131b;
	case 4900ULL: goto x86_l_1324;
	case 4906ULL: goto x86_l_132a;
	case 4913ULL: goto x86_l_1331;
	case 4917ULL: goto x86_l_1335;
	case 4926ULL: goto x86_l_133e;
	case 4928ULL: goto x86_l_1340;
	case 4933ULL: goto x86_l_1345;
	case 4937ULL: goto x86_l_1349;
	case 4940ULL: goto x86_l_134c;
	case 4945ULL: goto x86_l_1351;
	default: return 0xffffffffffffffffULL;
	}
x86_l_c75:
	/* 0xc75: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_c7d:
	/* 0xc7d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c7f:
	/* 0xc7f: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_c82:
	/* 0xc82: call   c87 <generic_sleepable_preload+0xc87> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_c87:
	/* 0xc87: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_c89:
	/* 0xc89: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_c8c:
	/* 0xc8c: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_c8e:
	/* 0xc8e: jns    10a <generic_sleepable_preload+0x10a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 266ULL;
	}
x86_l_c94:
	/* 0xc94: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_c99:
	/* 0xc99: jmp    10a <generic_sleepable_preload+0x10a> */
	return 266ULL;
x86_l_c9e:
	/* 0xc9e: mov    r15d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 7ULL);
x86_l_ca4:
	/* 0xca4: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ca7:
	/* 0xca7: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_caa:
	/* 0xcaa: jne    111 <generic_sleepable_preload+0x111> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 273ULL;
	}
x86_l_cb0:
	/* 0xcb0: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cb4:
	/* 0xcb4: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_cbc:
	/* 0xcbc: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_cc1:
	/* 0xcc1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cc3:
	/* 0xcc3: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_cc8:
	/* 0xcc8: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_cd0:
	/* 0xcd0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_cd5:
	/* 0xcd5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_cdc:
	/* 0xcdc: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_ce1:
	/* 0xce1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ce3:
	/* 0xce3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ce6:
	/* 0xce6: je     10c <generic_sleepable_preload+0x10c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 268ULL;
	}
x86_l_cec:
	/* 0xcec: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_cf2:
	/* 0xcf2: mov    rbp,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBP, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_cf9:
	/* 0xcf9: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_cfc:
	/* 0xcfc: mov    r13d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_32);
x86_l_cff:
	/* 0xcff: mov    r12d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_32);
x86_l_d02:
	/* 0xd02: lea    r15,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d07:
	/* 0xd07: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_d0a:
	/* 0xd0a: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_d0d:
	/* 0xd0d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d0f:
	/* 0xd0f: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_d12:
	/* 0xd12: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d17:
	/* 0xd17: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_d1a:
	/* 0xd1a: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_d1d:
	/* 0xd1d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d1f:
	/* 0xd1f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d22:
	/* 0xd22: je     10c <generic_sleepable_preload+0x10c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 268ULL;
	}
x86_l_d28:
	/* 0xd28: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_d2b:
	/* 0xd2b: test   r13b,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_8);
x86_l_d2e:
	/* 0xd2e: je     d52 <generic_sleepable_preload+0xd52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d52;
	}
x86_l_d30:
	/* 0xd30: lea    rdi,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_d34:
	/* 0xd34: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_d39:
	/* 0xd39: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_d41:
	/* 0xd41: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d43:
	/* 0xd43: call   d48 <generic_sleepable_preload+0xd48> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_d48:
	/* 0xd48: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d4a:
	/* 0xd4a: jns    d52 <generic_sleepable_preload+0xd52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_d52;
	}
x86_l_d4c:
	/* 0xd4c: mov    r12d,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967295ULL);
x86_l_d52:
	/* 0xd52: mov    DWORD PTR [rbp+0x0],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d56:
	/* 0xd56: jmp    10c <generic_sleepable_preload+0x10c> */
	return 268ULL;
x86_l_d5b:
	/* 0xd5b: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d5e:
	/* 0xd5e: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_d63:
	/* 0xd63: jmp    bc7 <generic_sleepable_preload+0xbc7> */
	return 3015ULL;
x86_l_d68:
	/* 0xd68: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d6b:
	/* 0xd6b: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_d71:
	/* 0xd71: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_d74:
	/* 0xd74: jne    111 <generic_sleepable_preload+0x111> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 273ULL;
	}
x86_l_d7a:
	/* 0xd7a: jmp    cb0 <generic_sleepable_preload+0xcb0> */
	goto x86_l_cb0;
x86_l_d7f:
	/* 0xd7f: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_d84:
	/* 0xd84: jmp    bc4 <generic_sleepable_preload+0xbc4> */
	return 3012ULL;
x86_l_d89:
	/* 0xd89: mov    r15d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 9ULL);
x86_l_d8f:
	/* 0xd8f: jmp    ca4 <generic_sleepable_preload+0xca4> */
	goto x86_l_ca4;
x86_l_d94:
	/* 0xd94: mov    eax,DWORD PTR [r13+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d98:
	/* 0xd98: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_d9d:
	/* 0xd9d: jne    dc2 <generic_sleepable_preload+0xdc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_dc2;
	}
x86_l_d9f:
	/* 0xd9f: mov    eax,DWORD PTR [r13+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_da3:
	/* 0xda3: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_da8:
	/* 0xda8: jne    1b03 <generic_sleepable_preload+0x1b03> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6915ULL;
	}
x86_l_dae:
	/* 0xdae: mov    eax,DWORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_db2:
	/* 0xdb2: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_db7:
	/* 0xdb7: jne    2880 <generic_sleepable_preload+0x2880> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10368ULL;
	}
x86_l_dbd:
	/* 0xdbd: jmp    35e9 <generic_sleepable_preload+0x35e9> */
	return 13801ULL;
x86_l_dc2:
	/* 0xdc2: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_dc4:
	/* 0xdc4: js     df8 <generic_sleepable_preload+0xdf8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_df8;
	}
x86_l_dc6:
	/* 0xdc6: mov    ecx,DWORD PTR [r13+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_dca:
	/* 0xdca: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_dcd:
	/* 0xdcd: jle    e7e <generic_sleepable_preload+0xe7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_e7e;
	}
x86_l_dd3:
	/* 0xdd3: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_dd6:
	/* 0xdd6: je     ee8 <generic_sleepable_preload+0xee8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ee8;
	}
x86_l_ddc:
	/* 0xddc: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_ddf:
	/* 0xddf: je     eef <generic_sleepable_preload+0xeef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_eef;
	}
x86_l_de5:
	/* 0xde5: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_de8:
	/* 0xde8: jne    f02 <generic_sleepable_preload+0xf02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_f02;
	}
x86_l_dee:
	/* 0xdee: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_df3:
	/* 0xdf3: jmp    efb <generic_sleepable_preload+0xefb> */
	goto x86_l_efb;
x86_l_df8:
	/* 0xdf8: movzx  ecx,BYTE PTR [r13+0x2c2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 706ULL);
x86_l_e00:
	/* 0xe00: movzx  eax,WORD PTR [r13+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 704ULL);
x86_l_e08:
	/* 0xe08: rorx   edx,eax,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 3ULL);
x86_l_e0e:
	/* 0xe0e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e10:
	/* 0xe10: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_e13:
	/* 0xe13: jle    e52 <generic_sleepable_preload+0xe52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_e52;
	}
x86_l_e15:
	/* 0xe15: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_e18:
	/* 0xe18: jle    e8e <generic_sleepable_preload+0xe8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_e8e;
	}
x86_l_e1a:
	/* 0xe1a: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_e1d:
	/* 0xe1d: jle    1448 <generic_sleepable_preload+0x1448> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5192ULL;
	}
x86_l_e23:
	/* 0xe23: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_e28:
	/* 0xe28: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_e2b:
	/* 0xe2b: je     145c <generic_sleepable_preload+0x145c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5212ULL;
	}
x86_l_e31:
	/* 0xe31: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_e36:
	/* 0xe36: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_e39:
	/* 0xe39: je     145c <generic_sleepable_preload+0x145c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5212ULL;
	}
x86_l_e3f:
	/* 0xe3f: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_e42:
	/* 0xe42: jne    146f <generic_sleepable_preload+0x146f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5231ULL;
	}
x86_l_e48:
	/* 0xe48: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_e4d:
	/* 0xe4d: jmp    145c <generic_sleepable_preload+0x145c> */
	return 5212ULL;
x86_l_e52:
	/* 0xe52: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_e55:
	/* 0xe55: jg     ebb <generic_sleepable_preload+0xebb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_ebb;
	}
x86_l_e57:
	/* 0xe57: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_e5a:
	/* 0xe5a: jg     1416 <generic_sleepable_preload+0x1416> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5142ULL;
	}
x86_l_e60:
	/* 0xe60: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_e65:
	/* 0xe65: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_e67:
	/* 0xe67: je     145c <generic_sleepable_preload+0x145c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5212ULL;
	}
x86_l_e6d:
	/* 0xe6d: mov    rsi,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDI, X86_WIDTH_64);
x86_l_e70:
	/* 0xe70: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_e73:
	/* 0xe73: je     145c <generic_sleepable_preload+0x145c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5212ULL;
	}
x86_l_e79:
	/* 0xe79: jmp    146f <generic_sleepable_preload+0x146f> */
	return 5231ULL;
x86_l_e7e:
	/* 0xe7e: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_e80:
	/* 0xe80: je     ef6 <generic_sleepable_preload+0xef6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ef6;
	}
x86_l_e82:
	/* 0xe82: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_e85:
	/* 0xe85: jne    f02 <generic_sleepable_preload+0xf02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_f02;
	}
x86_l_e87:
	/* 0xe87: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e8c:
	/* 0xe8c: jmp    efb <generic_sleepable_preload+0xefb> */
	goto x86_l_efb;
x86_l_e8e:
	/* 0xe8e: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_e91:
	/* 0xe91: jg     13fd <generic_sleepable_preload+0x13fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5117ULL;
	}
x86_l_e97:
	/* 0xe97: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_e9f:
	/* 0xe9f: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_ea2:
	/* 0xea2: je     145c <generic_sleepable_preload+0x145c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5212ULL;
	}
x86_l_ea8:
	/* 0xea8: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ead:
	/* 0xead: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_eb0:
	/* 0xeb0: je     145c <generic_sleepable_preload+0x145c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5212ULL;
	}
x86_l_eb6:
	/* 0xeb6: jmp    146f <generic_sleepable_preload+0x146f> */
	return 5231ULL;
x86_l_ebb:
	/* 0xebb: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_ebe:
	/* 0xebe: jg     142f <generic_sleepable_preload+0x142f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5167ULL;
	}
x86_l_ec4:
	/* 0xec4: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_ecc:
	/* 0xecc: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_ecf:
	/* 0xecf: je     145c <generic_sleepable_preload+0x145c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5212ULL;
	}
x86_l_ed5:
	/* 0xed5: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_eda:
	/* 0xeda: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_edd:
	/* 0xedd: je     145c <generic_sleepable_preload+0x145c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5212ULL;
	}
x86_l_ee3:
	/* 0xee3: jmp    146f <generic_sleepable_preload+0x146f> */
	return 5231ULL;
x86_l_ee8:
	/* 0xee8: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_eed:
	/* 0xeed: jmp    efb <generic_sleepable_preload+0xefb> */
	goto x86_l_efb;
x86_l_eef:
	/* 0xeef: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ef4:
	/* 0xef4: jmp    efb <generic_sleepable_preload+0xefb> */
	goto x86_l_efb;
x86_l_ef6:
	/* 0xef6: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_efb:
	/* 0xefb: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_efe:
	/* 0xefe: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f02:
	/* 0xf02: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f04:
	/* 0xf04: mov    r14b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_8, 1ULL);
x86_l_f07:
	/* 0xf07: cmp    WORD PTR [r13+0x76],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 506806140928ULL);
x86_l_f0d:
	/* 0xf0d: je     19cf <generic_sleepable_preload+0x19cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6607ULL;
	}
x86_l_f13:
	/* 0xf13: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_f1a:
	/* 0xf1a: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_f1d:
	/* 0xf1d: mov    edx,DWORD PTR [r13+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_f21:
	/* 0xf21: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_f24:
	/* 0xf24: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f28:
	/* 0xf28: movzx  eax,WORD PTR [r13+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 116ULL);
x86_l_f2d:
	/* 0xf2d: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_f2f:
	/* 0xf2f: je     1184 <generic_sleepable_preload+0x1184> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1184;
	}
x86_l_f35:
	/* 0xf35: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_f38:
	/* 0xf38: je     f55 <generic_sleepable_preload+0xf55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f55;
	}
x86_l_f3a:
	/* 0xf3a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_f3f:
	/* 0xf3f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f43:
	/* 0xf43: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_f46:
	/* 0xf46: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f4b:
	/* 0xf4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f4d:
	/* 0xf4d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f4f:
	/* 0xf4f: js     13f3 <generic_sleepable_preload+0x13f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 5107ULL;
	}
x86_l_f55:
	/* 0xf55: cmp    WORD PTR [r13+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_f5b:
	/* 0xf5b: je     19cf <generic_sleepable_preload+0x19cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6607ULL;
	}
x86_l_f61:
	/* 0xf61: mov    eax,DWORD PTR [r13+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_f65:
	/* 0xf65: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_f69:
	/* 0xf69: cmp    WORD PTR [r13+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_f6f:
	/* 0xf6f: je     f8c <generic_sleepable_preload+0xf8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f8c;
	}
x86_l_f71:
	/* 0xf71: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_f76:
	/* 0xf76: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f7a:
	/* 0xf7a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_f7d:
	/* 0xf7d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f82:
	/* 0xf82: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f84:
	/* 0xf84: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f86:
	/* 0xf86: js     1972 <generic_sleepable_preload+0x1972> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 6514ULL;
	}
x86_l_f8c:
	/* 0xf8c: cmp    WORD PTR [r13+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_f95:
	/* 0xf95: je     19cf <generic_sleepable_preload+0x19cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6607ULL;
	}
x86_l_f9b:
	/* 0xf9b: mov    eax,DWORD PTR [r13+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_fa2:
	/* 0xfa2: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_fa6:
	/* 0xfa6: cmp    WORD PTR [r13+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_faf:
	/* 0xfaf: je     fcc <generic_sleepable_preload+0xfcc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fcc;
	}
x86_l_fb1:
	/* 0xfb1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_fb6:
	/* 0xfb6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fba:
	/* 0xfba: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_fbd:
	/* 0xfbd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_fc2:
	/* 0xfc2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fc4:
	/* 0xfc4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_fc6:
	/* 0xfc6: js     1983 <generic_sleepable_preload+0x1983> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 6531ULL;
	}
x86_l_fcc:
	/* 0xfcc: cmp    WORD PTR [r13+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_fd5:
	/* 0xfd5: je     19cf <generic_sleepable_preload+0x19cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6607ULL;
	}
x86_l_fdb:
	/* 0xfdb: mov    eax,DWORD PTR [r13+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_fe2:
	/* 0xfe2: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_fe6:
	/* 0xfe6: cmp    WORD PTR [r13+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_fef:
	/* 0xfef: je     100c <generic_sleepable_preload+0x100c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_100c;
	}
x86_l_ff1:
	/* 0xff1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_ff6:
	/* 0xff6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ffa:
	/* 0xffa: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_ffd:
	/* 0xffd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1002:
	/* 0x1002: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1004:
	/* 0x1004: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1006:
	/* 0x1006: js     1994 <generic_sleepable_preload+0x1994> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 6548ULL;
	}
x86_l_100c:
	/* 0x100c: cmp    WORD PTR [r13+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_1015:
	/* 0x1015: je     19cf <generic_sleepable_preload+0x19cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6607ULL;
	}
x86_l_101b:
	/* 0x101b: mov    eax,DWORD PTR [r13+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1022:
	/* 0x1022: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1026:
	/* 0x1026: cmp    WORD PTR [r13+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_102f:
	/* 0x102f: je     104c <generic_sleepable_preload+0x104c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_104c;
	}
x86_l_1031:
	/* 0x1031: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1036:
	/* 0x1036: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_103a:
	/* 0x103a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_103d:
	/* 0x103d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1042:
	/* 0x1042: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1044:
	/* 0x1044: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1046:
	/* 0x1046: js     19a5 <generic_sleepable_preload+0x19a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 6565ULL;
	}
x86_l_104c:
	/* 0x104c: cmp    WORD PTR [r13+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_1055:
	/* 0x1055: je     19cf <generic_sleepable_preload+0x19cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6607ULL;
	}
x86_l_105b:
	/* 0x105b: mov    eax,DWORD PTR [r13+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1062:
	/* 0x1062: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1066:
	/* 0x1066: cmp    WORD PTR [r13+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_106f:
	/* 0x106f: je     108c <generic_sleepable_preload+0x108c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_108c;
	}
x86_l_1071:
	/* 0x1071: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1076:
	/* 0x1076: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_107a:
	/* 0x107a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_107d:
	/* 0x107d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1082:
	/* 0x1082: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1084:
	/* 0x1084: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1086:
	/* 0x1086: js     19b6 <generic_sleepable_preload+0x19b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 6582ULL;
	}
x86_l_108c:
	/* 0x108c: cmp    WORD PTR [r13+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_1095:
	/* 0x1095: je     19cf <generic_sleepable_preload+0x19cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6607ULL;
	}
x86_l_109b:
	/* 0x109b: mov    eax,DWORD PTR [r13+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_10a2:
	/* 0x10a2: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_10a6:
	/* 0x10a6: cmp    WORD PTR [r13+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_10af:
	/* 0x10af: je     10cc <generic_sleepable_preload+0x10cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10cc;
	}
x86_l_10b1:
	/* 0x10b1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_10b6:
	/* 0x10b6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10ba:
	/* 0x10ba: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_10bd:
	/* 0x10bd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10c2:
	/* 0x10c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10c4:
	/* 0x10c4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_10c6:
	/* 0x10c6: js     19c7 <generic_sleepable_preload+0x19c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 6599ULL;
	}
x86_l_10cc:
	/* 0x10cc: cmp    WORD PTR [r13+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_10d5:
	/* 0x10d5: je     19cf <generic_sleepable_preload+0x19cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6607ULL;
	}
x86_l_10db:
	/* 0x10db: mov    eax,DWORD PTR [r13+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_10e2:
	/* 0x10e2: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_10e6:
	/* 0x10e6: cmp    WORD PTR [r13+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_10ef:
	/* 0x10ef: je     110c <generic_sleepable_preload+0x110c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_110c;
	}
x86_l_10f1:
	/* 0x10f1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_10f6:
	/* 0x10f6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10fa:
	/* 0x10fa: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_10fd:
	/* 0x10fd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1102:
	/* 0x1102: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1104:
	/* 0x1104: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1106:
	/* 0x1106: js     51e0 <generic_sleepable_preload+0x51e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20960ULL;
	}
x86_l_110c:
	/* 0x110c: cmp    WORD PTR [r13+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_1115:
	/* 0x1115: je     19cf <generic_sleepable_preload+0x19cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6607ULL;
	}
x86_l_111b:
	/* 0x111b: mov    eax,DWORD PTR [r13+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1122:
	/* 0x1122: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1126:
	/* 0x1126: cmp    WORD PTR [r13+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_112f:
	/* 0x112f: je     114c <generic_sleepable_preload+0x114c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_114c;
	}
x86_l_1131:
	/* 0x1131: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1136:
	/* 0x1136: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_113a:
	/* 0x113a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_113d:
	/* 0x113d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1142:
	/* 0x1142: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1144:
	/* 0x1144: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1146:
	/* 0x1146: js     5248 <generic_sleepable_preload+0x5248> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21064ULL;
	}
x86_l_114c:
	/* 0x114c: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1151:
	/* 0x1151: cmp    WORD PTR [r13+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_115a:
	/* 0x115a: je     19cf <generic_sleepable_preload+0x19cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6607ULL;
	}
x86_l_1160:
	/* 0x1160: mov    eax,DWORD PTR [r13+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1167:
	/* 0x1167: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_116b:
	/* 0x116b: cmp    WORD PTR [r13+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_1174:
	/* 0x1174: je     19cf <generic_sleepable_preload+0x19cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6607ULL;
	}
x86_l_117a:
	/* 0x117a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_117f:
	/* 0x117f: jmp    13d3 <generic_sleepable_preload+0x13d3> */
	return 5075ULL;
x86_l_1184:
	/* 0x1184: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_1187:
	/* 0x1187: je     11a4 <generic_sleepable_preload+0x11a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11a4;
	}
x86_l_1189:
	/* 0x1189: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_118e:
	/* 0x118e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1192:
	/* 0x1192: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1195:
	/* 0x1195: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_119a:
	/* 0x119a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_119c:
	/* 0x119c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_119e:
	/* 0x119e: js     13f3 <generic_sleepable_preload+0x13f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 5107ULL;
	}
x86_l_11a4:
	/* 0x11a4: cmp    WORD PTR [r13+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_11aa:
	/* 0x11aa: je     19cf <generic_sleepable_preload+0x19cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6607ULL;
	}
x86_l_11b0:
	/* 0x11b0: mov    eax,DWORD PTR [r13+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_11b4:
	/* 0x11b4: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_11b8:
	/* 0x11b8: cmp    WORD PTR [r13+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_11be:
	/* 0x11be: je     11db <generic_sleepable_preload+0x11db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11db;
	}
x86_l_11c0:
	/* 0x11c0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_11c5:
	/* 0x11c5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11c9:
	/* 0x11c9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_11cc:
	/* 0x11cc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11d1:
	/* 0x11d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11d3:
	/* 0x11d3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_11d5:
	/* 0x11d5: js     1972 <generic_sleepable_preload+0x1972> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 6514ULL;
	}
x86_l_11db:
	/* 0x11db: cmp    WORD PTR [r13+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_11e4:
	/* 0x11e4: je     19cf <generic_sleepable_preload+0x19cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6607ULL;
	}
x86_l_11ea:
	/* 0x11ea: mov    eax,DWORD PTR [r13+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_11f1:
	/* 0x11f1: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_11f5:
	/* 0x11f5: cmp    WORD PTR [r13+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_11fe:
	/* 0x11fe: je     121b <generic_sleepable_preload+0x121b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_121b;
	}
x86_l_1200:
	/* 0x1200: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1205:
	/* 0x1205: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1209:
	/* 0x1209: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_120c:
	/* 0x120c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1211:
	/* 0x1211: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1213:
	/* 0x1213: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1215:
	/* 0x1215: js     1983 <generic_sleepable_preload+0x1983> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 6531ULL;
	}
x86_l_121b:
	/* 0x121b: cmp    WORD PTR [r13+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_1224:
	/* 0x1224: je     19cf <generic_sleepable_preload+0x19cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6607ULL;
	}
x86_l_122a:
	/* 0x122a: mov    eax,DWORD PTR [r13+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1231:
	/* 0x1231: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1235:
	/* 0x1235: cmp    WORD PTR [r13+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_123e:
	/* 0x123e: je     125b <generic_sleepable_preload+0x125b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_125b;
	}
x86_l_1240:
	/* 0x1240: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1245:
	/* 0x1245: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1249:
	/* 0x1249: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_124c:
	/* 0x124c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1251:
	/* 0x1251: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1253:
	/* 0x1253: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1255:
	/* 0x1255: js     1994 <generic_sleepable_preload+0x1994> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 6548ULL;
	}
x86_l_125b:
	/* 0x125b: cmp    WORD PTR [r13+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_1264:
	/* 0x1264: je     19cf <generic_sleepable_preload+0x19cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6607ULL;
	}
x86_l_126a:
	/* 0x126a: mov    eax,DWORD PTR [r13+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1271:
	/* 0x1271: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1275:
	/* 0x1275: cmp    WORD PTR [r13+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_127e:
	/* 0x127e: je     129b <generic_sleepable_preload+0x129b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_129b;
	}
x86_l_1280:
	/* 0x1280: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1285:
	/* 0x1285: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1289:
	/* 0x1289: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_128c:
	/* 0x128c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1291:
	/* 0x1291: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1293:
	/* 0x1293: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1295:
	/* 0x1295: js     19a5 <generic_sleepable_preload+0x19a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 6565ULL;
	}
x86_l_129b:
	/* 0x129b: cmp    WORD PTR [r13+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_12a4:
	/* 0x12a4: je     19cf <generic_sleepable_preload+0x19cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6607ULL;
	}
x86_l_12aa:
	/* 0x12aa: mov    eax,DWORD PTR [r13+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_12b1:
	/* 0x12b1: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_12b5:
	/* 0x12b5: cmp    WORD PTR [r13+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_12be:
	/* 0x12be: je     12db <generic_sleepable_preload+0x12db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12db;
	}
x86_l_12c0:
	/* 0x12c0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_12c5:
	/* 0x12c5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12c9:
	/* 0x12c9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_12cc:
	/* 0x12cc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12d1:
	/* 0x12d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12d3:
	/* 0x12d3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_12d5:
	/* 0x12d5: js     19b6 <generic_sleepable_preload+0x19b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 6582ULL;
	}
x86_l_12db:
	/* 0x12db: cmp    WORD PTR [r13+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_12e4:
	/* 0x12e4: je     19cf <generic_sleepable_preload+0x19cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6607ULL;
	}
x86_l_12ea:
	/* 0x12ea: mov    eax,DWORD PTR [r13+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_12f1:
	/* 0x12f1: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_12f5:
	/* 0x12f5: cmp    WORD PTR [r13+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_12fe:
	/* 0x12fe: je     131b <generic_sleepable_preload+0x131b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_131b;
	}
x86_l_1300:
	/* 0x1300: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1305:
	/* 0x1305: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1309:
	/* 0x1309: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_130c:
	/* 0x130c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1311:
	/* 0x1311: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1313:
	/* 0x1313: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1315:
	/* 0x1315: js     19c7 <generic_sleepable_preload+0x19c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 6599ULL;
	}
x86_l_131b:
	/* 0x131b: cmp    WORD PTR [r13+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_1324:
	/* 0x1324: je     19cf <generic_sleepable_preload+0x19cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6607ULL;
	}
x86_l_132a:
	/* 0x132a: mov    eax,DWORD PTR [r13+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1331:
	/* 0x1331: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1335:
	/* 0x1335: cmp    WORD PTR [r13+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_133e:
	/* 0x133e: je     135b <generic_sleepable_preload+0x135b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4955ULL;
	}
x86_l_1340:
	/* 0x1340: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1345:
	/* 0x1345: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1349:
	/* 0x1349: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_134c:
	/* 0x134c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1351:
	/* 0x1351: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 4947ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 4947ULL: goto x86_l_1353;
	case 4949ULL: goto x86_l_1355;
	case 4955ULL: goto x86_l_135b;
	case 4960ULL: goto x86_l_1360;
	case 4969ULL: goto x86_l_1369;
	case 4975ULL: goto x86_l_136f;
	case 4982ULL: goto x86_l_1376;
	case 4986ULL: goto x86_l_137a;
	case 4995ULL: goto x86_l_1383;
	case 4997ULL: goto x86_l_1385;
	case 5002ULL: goto x86_l_138a;
	case 5006ULL: goto x86_l_138e;
	case 5009ULL: goto x86_l_1391;
	case 5014ULL: goto x86_l_1396;
	case 5016ULL: goto x86_l_1398;
	case 5018ULL: goto x86_l_139a;
	case 5024ULL: goto x86_l_13a0;
	case 5029ULL: goto x86_l_13a5;
	case 5038ULL: goto x86_l_13ae;
	case 5044ULL: goto x86_l_13b4;
	case 5051ULL: goto x86_l_13bb;
	case 5055ULL: goto x86_l_13bf;
	case 5064ULL: goto x86_l_13c8;
	case 5070ULL: goto x86_l_13ce;
	case 5075ULL: goto x86_l_13d3;
	case 5079ULL: goto x86_l_13d7;
	case 5082ULL: goto x86_l_13da;
	case 5087ULL: goto x86_l_13df;
	case 5089ULL: goto x86_l_13e1;
	case 5091ULL: goto x86_l_13e3;
	case 5097ULL: goto x86_l_13e9;
	case 5102ULL: goto x86_l_13ee;
	case 5107ULL: goto x86_l_13f3;
	case 5112ULL: goto x86_l_13f8;
	case 5117ULL: goto x86_l_13fd;
	case 5125ULL: goto x86_l_1405;
	case 5128ULL: goto x86_l_1408;
	case 5130ULL: goto x86_l_140a;
	case 5135ULL: goto x86_l_140f;
	case 5138ULL: goto x86_l_1412;
	case 5140ULL: goto x86_l_1414;
	case 5142ULL: goto x86_l_1416;
	case 5150ULL: goto x86_l_141e;
	case 5153ULL: goto x86_l_1421;
	case 5155ULL: goto x86_l_1423;
	case 5160ULL: goto x86_l_1428;
	case 5163ULL: goto x86_l_142b;
	case 5165ULL: goto x86_l_142d;
	case 5167ULL: goto x86_l_142f;
	case 5175ULL: goto x86_l_1437;
	case 5178ULL: goto x86_l_143a;
	case 5180ULL: goto x86_l_143c;
	case 5185ULL: goto x86_l_1441;
	case 5188ULL: goto x86_l_1444;
	case 5190ULL: goto x86_l_1446;
	case 5192ULL: goto x86_l_1448;
	case 5197ULL: goto x86_l_144d;
	case 5200ULL: goto x86_l_1450;
	case 5202ULL: goto x86_l_1452;
	case 5207ULL: goto x86_l_1457;
	case 5210ULL: goto x86_l_145a;
	case 5212ULL: goto x86_l_145c;
	case 5215ULL: goto x86_l_145f;
	case 5217ULL: goto x86_l_1461;
	case 5219ULL: goto x86_l_1463;
	case 5224ULL: goto x86_l_1468;
	case 5226ULL: goto x86_l_146a;
	case 5231ULL: goto x86_l_146f;
	case 5235ULL: goto x86_l_1473;
	case 5239ULL: goto x86_l_1477;
	case 5241ULL: goto x86_l_1479;
	case 5244ULL: goto x86_l_147c;
	case 5250ULL: goto x86_l_1482;
	case 5256ULL: goto x86_l_1488;
	case 5263ULL: goto x86_l_148f;
	case 5266ULL: goto x86_l_1492;
	case 5270ULL: goto x86_l_1496;
	case 5273ULL: goto x86_l_1499;
	case 5277ULL: goto x86_l_149d;
	case 5282ULL: goto x86_l_14a2;
	case 5284ULL: goto x86_l_14a4;
	case 5290ULL: goto x86_l_14aa;
	case 5293ULL: goto x86_l_14ad;
	case 5295ULL: goto x86_l_14af;
	case 5300ULL: goto x86_l_14b4;
	case 5304ULL: goto x86_l_14b8;
	case 5307ULL: goto x86_l_14bb;
	case 5312ULL: goto x86_l_14c0;
	case 5314ULL: goto x86_l_14c2;
	case 5316ULL: goto x86_l_14c4;
	case 5322ULL: goto x86_l_14ca;
	case 5328ULL: goto x86_l_14d0;
	case 5334ULL: goto x86_l_14d6;
	case 5338ULL: goto x86_l_14da;
	case 5342ULL: goto x86_l_14de;
	case 5348ULL: goto x86_l_14e4;
	case 5350ULL: goto x86_l_14e6;
	case 5355ULL: goto x86_l_14eb;
	case 5359ULL: goto x86_l_14ef;
	case 5362ULL: goto x86_l_14f2;
	case 5367ULL: goto x86_l_14f7;
	case 5369ULL: goto x86_l_14f9;
	case 5371ULL: goto x86_l_14fb;
	case 5377ULL: goto x86_l_1501;
	case 5386ULL: goto x86_l_150a;
	case 5392ULL: goto x86_l_1510;
	case 5399ULL: goto x86_l_1517;
	case 5403ULL: goto x86_l_151b;
	case 5412ULL: goto x86_l_1524;
	case 5414ULL: goto x86_l_1526;
	case 5419ULL: goto x86_l_152b;
	case 5423ULL: goto x86_l_152f;
	case 5426ULL: goto x86_l_1532;
	case 5431ULL: goto x86_l_1537;
	case 5433ULL: goto x86_l_1539;
	case 5435ULL: goto x86_l_153b;
	case 5441ULL: goto x86_l_1541;
	case 5450ULL: goto x86_l_154a;
	case 5456ULL: goto x86_l_1550;
	case 5463ULL: goto x86_l_1557;
	case 5467ULL: goto x86_l_155b;
	case 5476ULL: goto x86_l_1564;
	case 5478ULL: goto x86_l_1566;
	case 5483ULL: goto x86_l_156b;
	case 5487ULL: goto x86_l_156f;
	case 5490ULL: goto x86_l_1572;
	case 5495ULL: goto x86_l_1577;
	case 5497ULL: goto x86_l_1579;
	case 5499ULL: goto x86_l_157b;
	case 5505ULL: goto x86_l_1581;
	case 5514ULL: goto x86_l_158a;
	case 5520ULL: goto x86_l_1590;
	case 5527ULL: goto x86_l_1597;
	case 5531ULL: goto x86_l_159b;
	case 5540ULL: goto x86_l_15a4;
	case 5542ULL: goto x86_l_15a6;
	case 5547ULL: goto x86_l_15ab;
	case 5551ULL: goto x86_l_15af;
	case 5554ULL: goto x86_l_15b2;
	case 5559ULL: goto x86_l_15b7;
	case 5561ULL: goto x86_l_15b9;
	case 5563ULL: goto x86_l_15bb;
	case 5569ULL: goto x86_l_15c1;
	case 5578ULL: goto x86_l_15ca;
	case 5584ULL: goto x86_l_15d0;
	case 5591ULL: goto x86_l_15d7;
	case 5595ULL: goto x86_l_15db;
	case 5604ULL: goto x86_l_15e4;
	case 5606ULL: goto x86_l_15e6;
	case 5611ULL: goto x86_l_15eb;
	case 5615ULL: goto x86_l_15ef;
	case 5618ULL: goto x86_l_15f2;
	case 5623ULL: goto x86_l_15f7;
	case 5625ULL: goto x86_l_15f9;
	case 5627ULL: goto x86_l_15fb;
	case 5633ULL: goto x86_l_1601;
	case 5642ULL: goto x86_l_160a;
	case 5648ULL: goto x86_l_1610;
	case 5655ULL: goto x86_l_1617;
	case 5659ULL: goto x86_l_161b;
	case 5668ULL: goto x86_l_1624;
	case 5670ULL: goto x86_l_1626;
	case 5675ULL: goto x86_l_162b;
	case 5679ULL: goto x86_l_162f;
	case 5682ULL: goto x86_l_1632;
	case 5687ULL: goto x86_l_1637;
	case 5689ULL: goto x86_l_1639;
	case 5691ULL: goto x86_l_163b;
	case 5697ULL: goto x86_l_1641;
	case 5706ULL: goto x86_l_164a;
	case 5712ULL: goto x86_l_1650;
	case 5719ULL: goto x86_l_1657;
	case 5723ULL: goto x86_l_165b;
	case 5732ULL: goto x86_l_1664;
	case 5734ULL: goto x86_l_1666;
	case 5739ULL: goto x86_l_166b;
	case 5743ULL: goto x86_l_166f;
	case 5746ULL: goto x86_l_1672;
	case 5751ULL: goto x86_l_1677;
	case 5753ULL: goto x86_l_1679;
	case 5755ULL: goto x86_l_167b;
	case 5761ULL: goto x86_l_1681;
	case 5770ULL: goto x86_l_168a;
	case 5776ULL: goto x86_l_1690;
	case 5783ULL: goto x86_l_1697;
	case 5787ULL: goto x86_l_169b;
	case 5796ULL: goto x86_l_16a4;
	case 5798ULL: goto x86_l_16a6;
	case 5803ULL: goto x86_l_16ab;
	case 5807ULL: goto x86_l_16af;
	case 5810ULL: goto x86_l_16b2;
	case 5815ULL: goto x86_l_16b7;
	case 5817ULL: goto x86_l_16b9;
	case 5819ULL: goto x86_l_16bb;
	case 5825ULL: goto x86_l_16c1;
	case 5830ULL: goto x86_l_16c6;
	case 5839ULL: goto x86_l_16cf;
	case 5845ULL: goto x86_l_16d5;
	case 5852ULL: goto x86_l_16dc;
	case 5856ULL: goto x86_l_16e0;
	case 5865ULL: goto x86_l_16e9;
	case 5871ULL: goto x86_l_16ef;
	case 5876ULL: goto x86_l_16f4;
	case 5881ULL: goto x86_l_16f9;
	case 5884ULL: goto x86_l_16fc;
	case 5886ULL: goto x86_l_16fe;
	case 5891ULL: goto x86_l_1703;
	case 5895ULL: goto x86_l_1707;
	case 5898ULL: goto x86_l_170a;
	case 5903ULL: goto x86_l_170f;
	case 5905ULL: goto x86_l_1711;
	case 5907ULL: goto x86_l_1713;
	case 5913ULL: goto x86_l_1719;
	case 5919ULL: goto x86_l_171f;
	case 5925ULL: goto x86_l_1725;
	case 5929ULL: goto x86_l_1729;
	case 5933ULL: goto x86_l_172d;
	case 5939ULL: goto x86_l_1733;
	case 5941ULL: goto x86_l_1735;
	case 5946ULL: goto x86_l_173a;
	case 5950ULL: goto x86_l_173e;
	case 5953ULL: goto x86_l_1741;
	case 5958ULL: goto x86_l_1746;
	case 5960ULL: goto x86_l_1748;
	case 5962ULL: goto x86_l_174a;
	case 5968ULL: goto x86_l_1750;
	case 5977ULL: goto x86_l_1759;
	case 5983ULL: goto x86_l_175f;
	case 5990ULL: goto x86_l_1766;
	case 5994ULL: goto x86_l_176a;
	case 6003ULL: goto x86_l_1773;
	case 6005ULL: goto x86_l_1775;
	case 6010ULL: goto x86_l_177a;
	case 6014ULL: goto x86_l_177e;
	case 6017ULL: goto x86_l_1781;
	case 6022ULL: goto x86_l_1786;
	case 6024ULL: goto x86_l_1788;
	case 6026ULL: goto x86_l_178a;
	case 6032ULL: goto x86_l_1790;
	case 6041ULL: goto x86_l_1799;
	case 6047ULL: goto x86_l_179f;
	case 6054ULL: goto x86_l_17a6;
	case 6058ULL: goto x86_l_17aa;
	case 6067ULL: goto x86_l_17b3;
	case 6069ULL: goto x86_l_17b5;
	case 6074ULL: goto x86_l_17ba;
	case 6078ULL: goto x86_l_17be;
	case 6081ULL: goto x86_l_17c1;
	case 6086ULL: goto x86_l_17c6;
	case 6088ULL: goto x86_l_17c8;
	case 6090ULL: goto x86_l_17ca;
	case 6096ULL: goto x86_l_17d0;
	case 6105ULL: goto x86_l_17d9;
	case 6111ULL: goto x86_l_17df;
	case 6118ULL: goto x86_l_17e6;
	case 6122ULL: goto x86_l_17ea;
	case 6131ULL: goto x86_l_17f3;
	case 6133ULL: goto x86_l_17f5;
	case 6138ULL: goto x86_l_17fa;
	case 6142ULL: goto x86_l_17fe;
	case 6145ULL: goto x86_l_1801;
	case 6150ULL: goto x86_l_1806;
	case 6152ULL: goto x86_l_1808;
	case 6154ULL: goto x86_l_180a;
	case 6160ULL: goto x86_l_1810;
	case 6169ULL: goto x86_l_1819;
	case 6175ULL: goto x86_l_181f;
	case 6182ULL: goto x86_l_1826;
	case 6186ULL: goto x86_l_182a;
	case 6195ULL: goto x86_l_1833;
	case 6197ULL: goto x86_l_1835;
	case 6202ULL: goto x86_l_183a;
	case 6206ULL: goto x86_l_183e;
	case 6209ULL: goto x86_l_1841;
	case 6214ULL: goto x86_l_1846;
	case 6216ULL: goto x86_l_1848;
	case 6218ULL: goto x86_l_184a;
	case 6224ULL: goto x86_l_1850;
	case 6233ULL: goto x86_l_1859;
	case 6239ULL: goto x86_l_185f;
	case 6246ULL: goto x86_l_1866;
	case 6250ULL: goto x86_l_186a;
	case 6259ULL: goto x86_l_1873;
	case 6261ULL: goto x86_l_1875;
	case 6266ULL: goto x86_l_187a;
	case 6270ULL: goto x86_l_187e;
	case 6273ULL: goto x86_l_1881;
	case 6278ULL: goto x86_l_1886;
	case 6280ULL: goto x86_l_1888;
	case 6282ULL: goto x86_l_188a;
	case 6288ULL: goto x86_l_1890;
	case 6297ULL: goto x86_l_1899;
	case 6303ULL: goto x86_l_189f;
	case 6310ULL: goto x86_l_18a6;
	case 6314ULL: goto x86_l_18aa;
	case 6323ULL: goto x86_l_18b3;
	case 6325ULL: goto x86_l_18b5;
	case 6330ULL: goto x86_l_18ba;
	case 6334ULL: goto x86_l_18be;
	case 6337ULL: goto x86_l_18c1;
	case 6342ULL: goto x86_l_18c6;
	case 6344ULL: goto x86_l_18c8;
	case 6346ULL: goto x86_l_18ca;
	case 6352ULL: goto x86_l_18d0;
	case 6357ULL: goto x86_l_18d5;
	case 6366ULL: goto x86_l_18de;
	case 6372ULL: goto x86_l_18e4;
	case 6379ULL: goto x86_l_18eb;
	case 6383ULL: goto x86_l_18ef;
	case 6392ULL: goto x86_l_18f8;
	case 6394ULL: goto x86_l_18fa;
	case 6399ULL: goto x86_l_18ff;
	case 6403ULL: goto x86_l_1903;
	case 6406ULL: goto x86_l_1906;
	case 6411ULL: goto x86_l_190b;
	case 6413ULL: goto x86_l_190d;
	case 6415ULL: goto x86_l_190f;
	case 6421ULL: goto x86_l_1915;
	case 6426ULL: goto x86_l_191a;
	case 6435ULL: goto x86_l_1923;
	case 6441ULL: goto x86_l_1929;
	case 6448ULL: goto x86_l_1930;
	case 6452ULL: goto x86_l_1934;
	case 6461ULL: goto x86_l_193d;
	case 6467ULL: goto x86_l_1943;
	case 6472ULL: goto x86_l_1948;
	case 6476ULL: goto x86_l_194c;
	case 6479ULL: goto x86_l_194f;
	case 6484ULL: goto x86_l_1954;
	case 6486ULL: goto x86_l_1956;
	case 6488ULL: goto x86_l_1958;
	case 6494ULL: goto x86_l_195e;
	case 6499ULL: goto x86_l_1963;
	case 6504ULL: goto x86_l_1968;
	case 6509ULL: goto x86_l_196d;
	case 6514ULL: goto x86_l_1972;
	case 6519ULL: goto x86_l_1977;
	case 6521ULL: goto x86_l_1979;
	case 6526ULL: goto x86_l_197e;
	case 6531ULL: goto x86_l_1983;
	case 6536ULL: goto x86_l_1988;
	case 6538ULL: goto x86_l_198a;
	case 6543ULL: goto x86_l_198f;
	case 6548ULL: goto x86_l_1994;
	case 6553ULL: goto x86_l_1999;
	case 6555ULL: goto x86_l_199b;
	case 6560ULL: goto x86_l_19a0;
	case 6565ULL: goto x86_l_19a5;
	case 6570ULL: goto x86_l_19aa;
	case 6572ULL: goto x86_l_19ac;
	case 6577ULL: goto x86_l_19b1;
	case 6582ULL: goto x86_l_19b6;
	case 6587ULL: goto x86_l_19bb;
	case 6589ULL: goto x86_l_19bd;
	case 6594ULL: goto x86_l_19c2;
	case 6599ULL: goto x86_l_19c7;
	case 6604ULL: goto x86_l_19cc;
	case 6607ULL: goto x86_l_19cf;
	case 6611ULL: goto x86_l_19d3;
	case 6616ULL: goto x86_l_19d8;
	case 6619ULL: goto x86_l_19db;
	case 6624ULL: goto x86_l_19e0;
	case 6627ULL: goto x86_l_19e3;
	case 6629ULL: goto x86_l_19e5;
	case 6632ULL: goto x86_l_19e8;
	case 6638ULL: goto x86_l_19ee;
	case 6642ULL: goto x86_l_19f2;
	case 6647ULL: goto x86_l_19f7;
	case 6649ULL: goto x86_l_19f9;
	case 6654ULL: goto x86_l_19fe;
	case 6662ULL: goto x86_l_1a06;
	case 6667ULL: goto x86_l_1a0b;
	case 6674ULL: goto x86_l_1a12;
	case 6679ULL: goto x86_l_1a17;
	case 6681ULL: goto x86_l_1a19;
	case 6684ULL: goto x86_l_1a1c;
	case 6690ULL: goto x86_l_1a22;
	case 6696ULL: goto x86_l_1a28;
	case 6703ULL: goto x86_l_1a2f;
	case 6708ULL: goto x86_l_1a34;
	case 6711ULL: goto x86_l_1a37;
	case 6714ULL: goto x86_l_1a3a;
	case 6717ULL: goto x86_l_1a3d;
	case 6719ULL: goto x86_l_1a3f;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1353:
	/* 0x1353: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1355:
	/* 0x1355: js     52ec <generic_sleepable_preload+0x52ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21228ULL;
	}
x86_l_135b:
	/* 0x135b: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1360:
	/* 0x1360: cmp    WORD PTR [r13+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_1369:
	/* 0x1369: je     19cf <generic_sleepable_preload+0x19cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19cf;
	}
x86_l_136f:
	/* 0x136f: mov    eax,DWORD PTR [r13+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1376:
	/* 0x1376: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_137a:
	/* 0x137a: cmp    WORD PTR [r13+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_1383:
	/* 0x1383: je     13a0 <generic_sleepable_preload+0x13a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13a0;
	}
x86_l_1385:
	/* 0x1385: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_138a:
	/* 0x138a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_138e:
	/* 0x138e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1391:
	/* 0x1391: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1396:
	/* 0x1396: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1398:
	/* 0x1398: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_139a:
	/* 0x139a: js     5248 <generic_sleepable_preload+0x5248> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21064ULL;
	}
x86_l_13a0:
	/* 0x13a0: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13a5:
	/* 0x13a5: cmp    WORD PTR [r13+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_13ae:
	/* 0x13ae: je     19cf <generic_sleepable_preload+0x19cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19cf;
	}
x86_l_13b4:
	/* 0x13b4: mov    eax,DWORD PTR [r13+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_13bb:
	/* 0x13bb: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_13bf:
	/* 0x13bf: cmp    WORD PTR [r13+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_13c8:
	/* 0x13c8: je     19cf <generic_sleepable_preload+0x19cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19cf;
	}
x86_l_13ce:
	/* 0x13ce: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_13d3:
	/* 0x13d3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13d7:
	/* 0x13d7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_13da:
	/* 0x13da: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_13df:
	/* 0x13df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13e1:
	/* 0x13e1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_13e3:
	/* 0x13e3: jns    19cf <generic_sleepable_preload+0x19cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_19cf;
	}
x86_l_13e9:
	/* 0x13e9: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_13ee:
	/* 0x13ee: jmp    19cc <generic_sleepable_preload+0x19cc> */
	goto x86_l_19cc;
x86_l_13f3:
	/* 0x13f3: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_13f8:
	/* 0x13f8: jmp    19cc <generic_sleepable_preload+0x19cc> */
	goto x86_l_19cc;
x86_l_13fd:
	/* 0x13fd: mov    rsi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1405:
	/* 0x1405: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_1408:
	/* 0x1408: je     145c <generic_sleepable_preload+0x145c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_145c;
	}
x86_l_140a:
	/* 0x140a: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_140f:
	/* 0x140f: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_1412:
	/* 0x1412: je     145c <generic_sleepable_preload+0x145c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_145c;
	}
x86_l_1414:
	/* 0x1414: jmp    146f <generic_sleepable_preload+0x146f> */
	goto x86_l_146f;
x86_l_1416:
	/* 0x1416: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_141e:
	/* 0x141e: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_1421:
	/* 0x1421: je     145c <generic_sleepable_preload+0x145c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_145c;
	}
x86_l_1423:
	/* 0x1423: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1428:
	/* 0x1428: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_142b:
	/* 0x142b: je     145c <generic_sleepable_preload+0x145c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_145c;
	}
x86_l_142d:
	/* 0x142d: jmp    146f <generic_sleepable_preload+0x146f> */
	goto x86_l_146f;
x86_l_142f:
	/* 0x142f: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1437:
	/* 0x1437: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_143a:
	/* 0x143a: je     145c <generic_sleepable_preload+0x145c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_145c;
	}
x86_l_143c:
	/* 0x143c: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1441:
	/* 0x1441: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_1444:
	/* 0x1444: je     145c <generic_sleepable_preload+0x145c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_145c;
	}
x86_l_1446:
	/* 0x1446: jmp    146f <generic_sleepable_preload+0x146f> */
	goto x86_l_146f;
x86_l_1448:
	/* 0x1448: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_144d:
	/* 0x144d: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_1450:
	/* 0x1450: je     145c <generic_sleepable_preload+0x145c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_145c;
	}
x86_l_1452:
	/* 0x1452: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1457:
	/* 0x1457: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_145a:
	/* 0x145a: jne    146f <generic_sleepable_preload+0x146f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_146f;
	}
x86_l_145c:
	/* 0x145c: shl    cl,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_145f:
	/* 0x145f: mov    al,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 64ULL);
x86_l_1461:
	/* 0x1461: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1463:
	/* 0x1463: mov    ecx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 64ULL);
x86_l_1468:
	/* 0x1468: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_146a:
	/* 0x146a: bzhi   rax,QWORD PTR [rsi],rcx */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RAX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), 0ULL);
x86_l_146f:
	/* 0x146f: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1473:
	/* 0x1473: mov    ebx,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1477:
	/* 0x1477: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1479:
	/* 0x1479: mov    r14b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_8, 1ULL);
x86_l_147c:
	/* 0x147c: cmp    WORD PTR [r13+0x76],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 506806140928ULL);
x86_l_1482:
	/* 0x1482: je     1a51 <generic_sleepable_preload+0x1a51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6737ULL;
	}
x86_l_1488:
	/* 0x1488: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_148f:
	/* 0x148f: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1492:
	/* 0x1492: mov    edx,DWORD PTR [r13+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1496:
	/* 0x1496: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1499:
	/* 0x1499: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_149d:
	/* 0x149d: movzx  eax,WORD PTR [r13+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 116ULL);
x86_l_14a2:
	/* 0x14a2: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_14a4:
	/* 0x14a4: je     16f9 <generic_sleepable_preload+0x16f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16f9;
	}
x86_l_14aa:
	/* 0x14aa: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_14ad:
	/* 0x14ad: je     14ca <generic_sleepable_preload+0x14ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14ca;
	}
x86_l_14af:
	/* 0x14af: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_14b4:
	/* 0x14b4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14b8:
	/* 0x14b8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_14bb:
	/* 0x14bb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14c0:
	/* 0x14c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14c2:
	/* 0x14c2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_14c4:
	/* 0x14c4: js     1968 <generic_sleepable_preload+0x1968> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1968;
	}
x86_l_14ca:
	/* 0x14ca: cmp    WORD PTR [r13+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_14d0:
	/* 0x14d0: je     1a51 <generic_sleepable_preload+0x1a51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6737ULL;
	}
x86_l_14d6:
	/* 0x14d6: mov    eax,DWORD PTR [r13+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_14da:
	/* 0x14da: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_14de:
	/* 0x14de: cmp    WORD PTR [r13+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_14e4:
	/* 0x14e4: je     1501 <generic_sleepable_preload+0x1501> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1501;
	}
x86_l_14e6:
	/* 0x14e6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_14eb:
	/* 0x14eb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14ef:
	/* 0x14ef: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_14f2:
	/* 0x14f2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14f7:
	/* 0x14f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14f9:
	/* 0x14f9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_14fb:
	/* 0x14fb: js     1979 <generic_sleepable_preload+0x1979> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1979;
	}
x86_l_1501:
	/* 0x1501: cmp    WORD PTR [r13+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_150a:
	/* 0x150a: je     1a51 <generic_sleepable_preload+0x1a51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6737ULL;
	}
x86_l_1510:
	/* 0x1510: mov    eax,DWORD PTR [r13+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1517:
	/* 0x1517: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_151b:
	/* 0x151b: cmp    WORD PTR [r13+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_1524:
	/* 0x1524: je     1541 <generic_sleepable_preload+0x1541> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1541;
	}
x86_l_1526:
	/* 0x1526: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_152b:
	/* 0x152b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_152f:
	/* 0x152f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1532:
	/* 0x1532: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1537:
	/* 0x1537: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1539:
	/* 0x1539: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_153b:
	/* 0x153b: js     198a <generic_sleepable_preload+0x198a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_198a;
	}
x86_l_1541:
	/* 0x1541: cmp    WORD PTR [r13+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_154a:
	/* 0x154a: je     1a51 <generic_sleepable_preload+0x1a51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6737ULL;
	}
x86_l_1550:
	/* 0x1550: mov    eax,DWORD PTR [r13+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1557:
	/* 0x1557: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_155b:
	/* 0x155b: cmp    WORD PTR [r13+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_1564:
	/* 0x1564: je     1581 <generic_sleepable_preload+0x1581> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1581;
	}
x86_l_1566:
	/* 0x1566: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_156b:
	/* 0x156b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_156f:
	/* 0x156f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1572:
	/* 0x1572: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1577:
	/* 0x1577: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1579:
	/* 0x1579: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_157b:
	/* 0x157b: js     199b <generic_sleepable_preload+0x199b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_199b;
	}
x86_l_1581:
	/* 0x1581: cmp    WORD PTR [r13+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_158a:
	/* 0x158a: je     1a51 <generic_sleepable_preload+0x1a51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6737ULL;
	}
x86_l_1590:
	/* 0x1590: mov    eax,DWORD PTR [r13+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1597:
	/* 0x1597: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_159b:
	/* 0x159b: cmp    WORD PTR [r13+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_15a4:
	/* 0x15a4: je     15c1 <generic_sleepable_preload+0x15c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15c1;
	}
x86_l_15a6:
	/* 0x15a6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_15ab:
	/* 0x15ab: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15af:
	/* 0x15af: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_15b2:
	/* 0x15b2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_15b7:
	/* 0x15b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15b9:
	/* 0x15b9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_15bb:
	/* 0x15bb: js     19ac <generic_sleepable_preload+0x19ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_19ac;
	}
x86_l_15c1:
	/* 0x15c1: cmp    WORD PTR [r13+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_15ca:
	/* 0x15ca: je     1a51 <generic_sleepable_preload+0x1a51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6737ULL;
	}
x86_l_15d0:
	/* 0x15d0: mov    eax,DWORD PTR [r13+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_15d7:
	/* 0x15d7: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_15db:
	/* 0x15db: cmp    WORD PTR [r13+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_15e4:
	/* 0x15e4: je     1601 <generic_sleepable_preload+0x1601> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1601;
	}
x86_l_15e6:
	/* 0x15e6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_15eb:
	/* 0x15eb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15ef:
	/* 0x15ef: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_15f2:
	/* 0x15f2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_15f7:
	/* 0x15f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15f9:
	/* 0x15f9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_15fb:
	/* 0x15fb: js     19bd <generic_sleepable_preload+0x19bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_19bd;
	}
x86_l_1601:
	/* 0x1601: cmp    WORD PTR [r13+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_160a:
	/* 0x160a: je     1a51 <generic_sleepable_preload+0x1a51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6737ULL;
	}
x86_l_1610:
	/* 0x1610: mov    eax,DWORD PTR [r13+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1617:
	/* 0x1617: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_161b:
	/* 0x161b: cmp    WORD PTR [r13+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_1624:
	/* 0x1624: je     1641 <generic_sleepable_preload+0x1641> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1641;
	}
x86_l_1626:
	/* 0x1626: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_162b:
	/* 0x162b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_162f:
	/* 0x162f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1632:
	/* 0x1632: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1637:
	/* 0x1637: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1639:
	/* 0x1639: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_163b:
	/* 0x163b: js     1a49 <generic_sleepable_preload+0x1a49> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 6729ULL;
	}
x86_l_1641:
	/* 0x1641: cmp    WORD PTR [r13+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_164a:
	/* 0x164a: je     1a51 <generic_sleepable_preload+0x1a51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6737ULL;
	}
x86_l_1650:
	/* 0x1650: mov    eax,DWORD PTR [r13+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1657:
	/* 0x1657: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_165b:
	/* 0x165b: cmp    WORD PTR [r13+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_1664:
	/* 0x1664: je     1681 <generic_sleepable_preload+0x1681> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1681;
	}
x86_l_1666:
	/* 0x1666: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_166b:
	/* 0x166b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_166f:
	/* 0x166f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1672:
	/* 0x1672: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1677:
	/* 0x1677: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1679:
	/* 0x1679: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_167b:
	/* 0x167b: js     51ed <generic_sleepable_preload+0x51ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20973ULL;
	}
x86_l_1681:
	/* 0x1681: cmp    WORD PTR [r13+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_168a:
	/* 0x168a: je     1a51 <generic_sleepable_preload+0x1a51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6737ULL;
	}
x86_l_1690:
	/* 0x1690: mov    eax,DWORD PTR [r13+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1697:
	/* 0x1697: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_169b:
	/* 0x169b: cmp    WORD PTR [r13+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_16a4:
	/* 0x16a4: je     16c1 <generic_sleepable_preload+0x16c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16c1;
	}
x86_l_16a6:
	/* 0x16a6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_16ab:
	/* 0x16ab: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16af:
	/* 0x16af: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_16b2:
	/* 0x16b2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16b7:
	/* 0x16b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16b9:
	/* 0x16b9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_16bb:
	/* 0x16bb: js     525a <generic_sleepable_preload+0x525a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21082ULL;
	}
x86_l_16c1:
	/* 0x16c1: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16c6:
	/* 0x16c6: cmp    WORD PTR [r13+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_16cf:
	/* 0x16cf: je     1a51 <generic_sleepable_preload+0x1a51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6737ULL;
	}
x86_l_16d5:
	/* 0x16d5: mov    eax,DWORD PTR [r13+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_16dc:
	/* 0x16dc: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_16e0:
	/* 0x16e0: cmp    WORD PTR [r13+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_16e9:
	/* 0x16e9: je     1a51 <generic_sleepable_preload+0x1a51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6737ULL;
	}
x86_l_16ef:
	/* 0x16ef: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_16f4:
	/* 0x16f4: jmp    1948 <generic_sleepable_preload+0x1948> */
	goto x86_l_1948;
x86_l_16f9:
	/* 0x16f9: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_16fc:
	/* 0x16fc: je     1719 <generic_sleepable_preload+0x1719> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1719;
	}
x86_l_16fe:
	/* 0x16fe: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1703:
	/* 0x1703: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1707:
	/* 0x1707: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_170a:
	/* 0x170a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_170f:
	/* 0x170f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1711:
	/* 0x1711: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1713:
	/* 0x1713: js     1968 <generic_sleepable_preload+0x1968> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1968;
	}
x86_l_1719:
	/* 0x1719: cmp    WORD PTR [r13+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_171f:
	/* 0x171f: je     1a51 <generic_sleepable_preload+0x1a51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6737ULL;
	}
x86_l_1725:
	/* 0x1725: mov    eax,DWORD PTR [r13+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1729:
	/* 0x1729: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_172d:
	/* 0x172d: cmp    WORD PTR [r13+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_1733:
	/* 0x1733: je     1750 <generic_sleepable_preload+0x1750> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1750;
	}
x86_l_1735:
	/* 0x1735: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_173a:
	/* 0x173a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_173e:
	/* 0x173e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1741:
	/* 0x1741: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1746:
	/* 0x1746: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1748:
	/* 0x1748: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_174a:
	/* 0x174a: js     1979 <generic_sleepable_preload+0x1979> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1979;
	}
x86_l_1750:
	/* 0x1750: cmp    WORD PTR [r13+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_1759:
	/* 0x1759: je     1a51 <generic_sleepable_preload+0x1a51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6737ULL;
	}
x86_l_175f:
	/* 0x175f: mov    eax,DWORD PTR [r13+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1766:
	/* 0x1766: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_176a:
	/* 0x176a: cmp    WORD PTR [r13+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_1773:
	/* 0x1773: je     1790 <generic_sleepable_preload+0x1790> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1790;
	}
x86_l_1775:
	/* 0x1775: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_177a:
	/* 0x177a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_177e:
	/* 0x177e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1781:
	/* 0x1781: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1786:
	/* 0x1786: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1788:
	/* 0x1788: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_178a:
	/* 0x178a: js     198a <generic_sleepable_preload+0x198a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_198a;
	}
x86_l_1790:
	/* 0x1790: cmp    WORD PTR [r13+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_1799:
	/* 0x1799: je     1a51 <generic_sleepable_preload+0x1a51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6737ULL;
	}
x86_l_179f:
	/* 0x179f: mov    eax,DWORD PTR [r13+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_17a6:
	/* 0x17a6: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_17aa:
	/* 0x17aa: cmp    WORD PTR [r13+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_17b3:
	/* 0x17b3: je     17d0 <generic_sleepable_preload+0x17d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17d0;
	}
x86_l_17b5:
	/* 0x17b5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_17ba:
	/* 0x17ba: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17be:
	/* 0x17be: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_17c1:
	/* 0x17c1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17c6:
	/* 0x17c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17c8:
	/* 0x17c8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_17ca:
	/* 0x17ca: js     199b <generic_sleepable_preload+0x199b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_199b;
	}
x86_l_17d0:
	/* 0x17d0: cmp    WORD PTR [r13+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_17d9:
	/* 0x17d9: je     1a51 <generic_sleepable_preload+0x1a51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6737ULL;
	}
x86_l_17df:
	/* 0x17df: mov    eax,DWORD PTR [r13+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_17e6:
	/* 0x17e6: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_17ea:
	/* 0x17ea: cmp    WORD PTR [r13+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_17f3:
	/* 0x17f3: je     1810 <generic_sleepable_preload+0x1810> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1810;
	}
x86_l_17f5:
	/* 0x17f5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_17fa:
	/* 0x17fa: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17fe:
	/* 0x17fe: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1801:
	/* 0x1801: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1806:
	/* 0x1806: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1808:
	/* 0x1808: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_180a:
	/* 0x180a: js     19ac <generic_sleepable_preload+0x19ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_19ac;
	}
x86_l_1810:
	/* 0x1810: cmp    WORD PTR [r13+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_1819:
	/* 0x1819: je     1a51 <generic_sleepable_preload+0x1a51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6737ULL;
	}
x86_l_181f:
	/* 0x181f: mov    eax,DWORD PTR [r13+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1826:
	/* 0x1826: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_182a:
	/* 0x182a: cmp    WORD PTR [r13+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_1833:
	/* 0x1833: je     1850 <generic_sleepable_preload+0x1850> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1850;
	}
x86_l_1835:
	/* 0x1835: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_183a:
	/* 0x183a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_183e:
	/* 0x183e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1841:
	/* 0x1841: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1846:
	/* 0x1846: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1848:
	/* 0x1848: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_184a:
	/* 0x184a: js     19bd <generic_sleepable_preload+0x19bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_19bd;
	}
x86_l_1850:
	/* 0x1850: cmp    WORD PTR [r13+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_1859:
	/* 0x1859: je     1a51 <generic_sleepable_preload+0x1a51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6737ULL;
	}
x86_l_185f:
	/* 0x185f: mov    eax,DWORD PTR [r13+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1866:
	/* 0x1866: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_186a:
	/* 0x186a: cmp    WORD PTR [r13+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_1873:
	/* 0x1873: je     1890 <generic_sleepable_preload+0x1890> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1890;
	}
x86_l_1875:
	/* 0x1875: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_187a:
	/* 0x187a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_187e:
	/* 0x187e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1881:
	/* 0x1881: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1886:
	/* 0x1886: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1888:
	/* 0x1888: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_188a:
	/* 0x188a: js     1a49 <generic_sleepable_preload+0x1a49> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 6729ULL;
	}
x86_l_1890:
	/* 0x1890: cmp    WORD PTR [r13+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_1899:
	/* 0x1899: je     1a51 <generic_sleepable_preload+0x1a51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6737ULL;
	}
x86_l_189f:
	/* 0x189f: mov    eax,DWORD PTR [r13+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_18a6:
	/* 0x18a6: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_18aa:
	/* 0x18aa: cmp    WORD PTR [r13+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_18b3:
	/* 0x18b3: je     18d0 <generic_sleepable_preload+0x18d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18d0;
	}
x86_l_18b5:
	/* 0x18b5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_18ba:
	/* 0x18ba: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18be:
	/* 0x18be: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_18c1:
	/* 0x18c1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18c6:
	/* 0x18c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18c8:
	/* 0x18c8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_18ca:
	/* 0x18ca: js     52fe <generic_sleepable_preload+0x52fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21246ULL;
	}
x86_l_18d0:
	/* 0x18d0: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18d5:
	/* 0x18d5: cmp    WORD PTR [r13+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_18de:
	/* 0x18de: je     1a51 <generic_sleepable_preload+0x1a51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6737ULL;
	}
x86_l_18e4:
	/* 0x18e4: mov    eax,DWORD PTR [r13+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_18eb:
	/* 0x18eb: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_18ef:
	/* 0x18ef: cmp    WORD PTR [r13+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_18f8:
	/* 0x18f8: je     1915 <generic_sleepable_preload+0x1915> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1915;
	}
x86_l_18fa:
	/* 0x18fa: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_18ff:
	/* 0x18ff: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1903:
	/* 0x1903: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1906:
	/* 0x1906: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_190b:
	/* 0x190b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_190d:
	/* 0x190d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_190f:
	/* 0x190f: js     525a <generic_sleepable_preload+0x525a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21082ULL;
	}
x86_l_1915:
	/* 0x1915: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_191a:
	/* 0x191a: cmp    WORD PTR [r13+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_1923:
	/* 0x1923: je     1a51 <generic_sleepable_preload+0x1a51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6737ULL;
	}
x86_l_1929:
	/* 0x1929: mov    eax,DWORD PTR [r13+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1930:
	/* 0x1930: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1934:
	/* 0x1934: cmp    WORD PTR [r13+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_193d:
	/* 0x193d: je     1a51 <generic_sleepable_preload+0x1a51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6737ULL;
	}
x86_l_1943:
	/* 0x1943: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1948:
	/* 0x1948: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_194c:
	/* 0x194c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_194f:
	/* 0x194f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1954:
	/* 0x1954: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1956:
	/* 0x1956: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1958:
	/* 0x1958: jns    1a51 <generic_sleepable_preload+0x1a51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 6737ULL;
	}
x86_l_195e:
	/* 0x195e: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_1963:
	/* 0x1963: jmp    1a4e <generic_sleepable_preload+0x1a4e> */
	return 6734ULL;
x86_l_1968:
	/* 0x1968: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_196d:
	/* 0x196d: jmp    1a4e <generic_sleepable_preload+0x1a4e> */
	return 6734ULL;
x86_l_1972:
	/* 0x1972: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_1977:
	/* 0x1977: jmp    19cc <generic_sleepable_preload+0x19cc> */
	goto x86_l_19cc;
x86_l_1979:
	/* 0x1979: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_197e:
	/* 0x197e: jmp    1a4e <generic_sleepable_preload+0x1a4e> */
	return 6734ULL;
x86_l_1983:
	/* 0x1983: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_1988:
	/* 0x1988: jmp    19cc <generic_sleepable_preload+0x19cc> */
	goto x86_l_19cc;
x86_l_198a:
	/* 0x198a: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_198f:
	/* 0x198f: jmp    1a4e <generic_sleepable_preload+0x1a4e> */
	return 6734ULL;
x86_l_1994:
	/* 0x1994: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_1999:
	/* 0x1999: jmp    19cc <generic_sleepable_preload+0x19cc> */
	goto x86_l_19cc;
x86_l_199b:
	/* 0x199b: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_19a0:
	/* 0x19a0: jmp    1a4e <generic_sleepable_preload+0x1a4e> */
	return 6734ULL;
x86_l_19a5:
	/* 0x19a5: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_19aa:
	/* 0x19aa: jmp    19cc <generic_sleepable_preload+0x19cc> */
	goto x86_l_19cc;
x86_l_19ac:
	/* 0x19ac: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_19b1:
	/* 0x19b1: jmp    1a4e <generic_sleepable_preload+0x1a4e> */
	return 6734ULL;
x86_l_19b6:
	/* 0x19b6: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_19bb:
	/* 0x19bb: jmp    19cc <generic_sleepable_preload+0x19cc> */
	goto x86_l_19cc;
x86_l_19bd:
	/* 0x19bd: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_19c2:
	/* 0x19c2: jmp    1a4e <generic_sleepable_preload+0x1a4e> */
	return 6734ULL;
x86_l_19c7:
	/* 0x19c7: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_19cc:
	/* 0x19cc: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19cf:
	/* 0x19cf: mov    ebx,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_19d3:
	/* 0x19d3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19d8:
	/* 0x19d8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_19db:
	/* 0x19db: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19e0:
	/* 0x19e0: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_19e3:
	/* 0x19e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19e5:
	/* 0x19e5: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_19e8:
	/* 0x19e8: jne    1aef <generic_sleepable_preload+0x1aef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6895ULL;
	}
x86_l_19ee:
	/* 0x19ee: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19f2:
	/* 0x19f2: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_19f7:
	/* 0x19f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19f9:
	/* 0x19f9: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_19fe:
	/* 0x19fe: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_1a06:
	/* 0x1a06: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a0b:
	/* 0x1a0b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_1a12:
	/* 0x1a12: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1a17:
	/* 0x1a17: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a19:
	/* 0x1a19: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a1c:
	/* 0x1a1c: je     1aef <generic_sleepable_preload+0x1aef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6895ULL;
	}
x86_l_1a22:
	/* 0x1a22: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_1a28:
	/* 0x1a28: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_1a2f:
	/* 0x1a2f: lea    r13,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a34:
	/* 0x1a34: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1a37:
	/* 0x1a37: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1a3a:
	/* 0x1a3a: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1a3d:
	/* 0x1a3d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a3f:
	/* 0x1a3f: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
	return 6722ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 6722ULL: goto x86_l_1a42;
	case 6727ULL: goto x86_l_1a47;
	case 6729ULL: goto x86_l_1a49;
	case 6734ULL: goto x86_l_1a4e;
	case 6737ULL: goto x86_l_1a51;
	case 6740ULL: goto x86_l_1a54;
	case 6746ULL: goto x86_l_1a5a;
	case 6750ULL: goto x86_l_1a5e;
	case 6755ULL: goto x86_l_1a63;
	case 6757ULL: goto x86_l_1a65;
	case 6762ULL: goto x86_l_1a6a;
	case 6770ULL: goto x86_l_1a72;
	case 6775ULL: goto x86_l_1a77;
	case 6782ULL: goto x86_l_1a7e;
	case 6787ULL: goto x86_l_1a83;
	case 6789ULL: goto x86_l_1a85;
	case 6792ULL: goto x86_l_1a88;
	case 6794ULL: goto x86_l_1a8a;
	case 6800ULL: goto x86_l_1a90;
	case 6807ULL: goto x86_l_1a97;
	case 6812ULL: goto x86_l_1a9c;
	case 6815ULL: goto x86_l_1a9f;
	case 6818ULL: goto x86_l_1aa2;
	case 6821ULL: goto x86_l_1aa5;
	case 6823ULL: goto x86_l_1aa7;
	case 6826ULL: goto x86_l_1aaa;
	case 6831ULL: goto x86_l_1aaf;
	case 6834ULL: goto x86_l_1ab2;
	case 6837ULL: goto x86_l_1ab5;
	case 6842ULL: goto x86_l_1aba;
	case 6844ULL: goto x86_l_1abc;
	case 6847ULL: goto x86_l_1abf;
	case 6849ULL: goto x86_l_1ac1;
	case 6852ULL: goto x86_l_1ac4;
	case 6854ULL: goto x86_l_1ac6;
	case 6857ULL: goto x86_l_1ac9;
	case 6861ULL: goto x86_l_1acd;
	case 6866ULL: goto x86_l_1ad2;
	case 6869ULL: goto x86_l_1ad5;
	case 6871ULL: goto x86_l_1ad7;
	case 6874ULL: goto x86_l_1ada;
	case 6879ULL: goto x86_l_1adf;
	case 6881ULL: goto x86_l_1ae1;
	case 6884ULL: goto x86_l_1ae4;
	case 6886ULL: goto x86_l_1ae6;
	case 6888ULL: goto x86_l_1ae8;
	case 6893ULL: goto x86_l_1aed;
	case 6895ULL: goto x86_l_1aef;
	case 6900ULL: goto x86_l_1af4;
	case 6904ULL: goto x86_l_1af8;
	case 6909ULL: goto x86_l_1afd;
	case 6915ULL: goto x86_l_1b03;
	case 6917ULL: goto x86_l_1b05;
	case 6919ULL: goto x86_l_1b07;
	case 6923ULL: goto x86_l_1b0b;
	case 6926ULL: goto x86_l_1b0e;
	case 6932ULL: goto x86_l_1b14;
	case 6935ULL: goto x86_l_1b17;
	case 6941ULL: goto x86_l_1b1d;
	case 6944ULL: goto x86_l_1b20;
	case 6950ULL: goto x86_l_1b26;
	case 6953ULL: goto x86_l_1b29;
	case 6959ULL: goto x86_l_1b2f;
	case 6964ULL: goto x86_l_1b34;
	case 6969ULL: goto x86_l_1b39;
	case 6977ULL: goto x86_l_1b41;
	case 6985ULL: goto x86_l_1b49;
	case 6991ULL: goto x86_l_1b4f;
	case 6993ULL: goto x86_l_1b51;
	case 6996ULL: goto x86_l_1b54;
	case 6998ULL: goto x86_l_1b56;
	case 7001ULL: goto x86_l_1b59;
	case 7003ULL: goto x86_l_1b5b;
	case 7006ULL: goto x86_l_1b5e;
	case 7012ULL: goto x86_l_1b64;
	case 7017ULL: goto x86_l_1b69;
	case 7020ULL: goto x86_l_1b6c;
	case 7026ULL: goto x86_l_1b72;
	case 7031ULL: goto x86_l_1b77;
	case 7034ULL: goto x86_l_1b7a;
	case 7040ULL: goto x86_l_1b80;
	case 7045ULL: goto x86_l_1b85;
	case 7048ULL: goto x86_l_1b88;
	case 7054ULL: goto x86_l_1b8e;
	case 7059ULL: goto x86_l_1b93;
	case 7062ULL: goto x86_l_1b96;
	case 7064ULL: goto x86_l_1b98;
	case 7067ULL: goto x86_l_1b9b;
	case 7073ULL: goto x86_l_1ba1;
	case 7075ULL: goto x86_l_1ba3;
	case 7081ULL: goto x86_l_1ba9;
	case 7084ULL: goto x86_l_1bac;
	case 7087ULL: goto x86_l_1baf;
	case 7093ULL: goto x86_l_1bb5;
	case 7098ULL: goto x86_l_1bba;
	case 7100ULL: goto x86_l_1bbc;
	case 7102ULL: goto x86_l_1bbe;
	case 7105ULL: goto x86_l_1bc1;
	case 7107ULL: goto x86_l_1bc3;
	case 7112ULL: goto x86_l_1bc8;
	case 7114ULL: goto x86_l_1bca;
	case 7117ULL: goto x86_l_1bcd;
	case 7123ULL: goto x86_l_1bd3;
	case 7131ULL: goto x86_l_1bdb;
	case 7134ULL: goto x86_l_1bde;
	case 7140ULL: goto x86_l_1be4;
	case 7145ULL: goto x86_l_1be9;
	case 7148ULL: goto x86_l_1bec;
	case 7154ULL: goto x86_l_1bf2;
	case 7159ULL: goto x86_l_1bf7;
	case 7162ULL: goto x86_l_1bfa;
	case 7168ULL: goto x86_l_1c00;
	case 7176ULL: goto x86_l_1c08;
	case 7179ULL: goto x86_l_1c0b;
	case 7185ULL: goto x86_l_1c11;
	case 7190ULL: goto x86_l_1c16;
	case 7193ULL: goto x86_l_1c19;
	case 7199ULL: goto x86_l_1c1f;
	case 7204ULL: goto x86_l_1c24;
	case 7209ULL: goto x86_l_1c29;
	case 7211ULL: goto x86_l_1c2b;
	case 7216ULL: goto x86_l_1c30;
	case 7218ULL: goto x86_l_1c32;
	case 7223ULL: goto x86_l_1c37;
	case 7226ULL: goto x86_l_1c3a;
	case 7230ULL: goto x86_l_1c3e;
	case 7232ULL: goto x86_l_1c40;
	case 7235ULL: goto x86_l_1c43;
	case 7244ULL: goto x86_l_1c4c;
	case 7250ULL: goto x86_l_1c52;
	case 7257ULL: goto x86_l_1c59;
	case 7260ULL: goto x86_l_1c5c;
	case 7267ULL: goto x86_l_1c63;
	case 7270ULL: goto x86_l_1c66;
	case 7274ULL: goto x86_l_1c6a;
	case 7282ULL: goto x86_l_1c72;
	case 7284ULL: goto x86_l_1c74;
	case 7290ULL: goto x86_l_1c7a;
	case 7293ULL: goto x86_l_1c7d;
	case 7295ULL: goto x86_l_1c7f;
	case 7300ULL: goto x86_l_1c84;
	case 7304ULL: goto x86_l_1c88;
	case 7307ULL: goto x86_l_1c8b;
	case 7312ULL: goto x86_l_1c90;
	case 7314ULL: goto x86_l_1c92;
	case 7316ULL: goto x86_l_1c94;
	case 7322ULL: goto x86_l_1c9a;
	case 7331ULL: goto x86_l_1ca3;
	case 7337ULL: goto x86_l_1ca9;
	case 7344ULL: goto x86_l_1cb0;
	case 7348ULL: goto x86_l_1cb4;
	case 7357ULL: goto x86_l_1cbd;
	case 7359ULL: goto x86_l_1cbf;
	case 7364ULL: goto x86_l_1cc4;
	case 7368ULL: goto x86_l_1cc8;
	case 7371ULL: goto x86_l_1ccb;
	case 7376ULL: goto x86_l_1cd0;
	case 7378ULL: goto x86_l_1cd2;
	case 7380ULL: goto x86_l_1cd4;
	case 7386ULL: goto x86_l_1cda;
	case 7395ULL: goto x86_l_1ce3;
	case 7401ULL: goto x86_l_1ce9;
	case 7408ULL: goto x86_l_1cf0;
	case 7412ULL: goto x86_l_1cf4;
	case 7421ULL: goto x86_l_1cfd;
	case 7423ULL: goto x86_l_1cff;
	case 7428ULL: goto x86_l_1d04;
	case 7432ULL: goto x86_l_1d08;
	case 7435ULL: goto x86_l_1d0b;
	case 7440ULL: goto x86_l_1d10;
	case 7442ULL: goto x86_l_1d12;
	case 7444ULL: goto x86_l_1d14;
	case 7450ULL: goto x86_l_1d1a;
	case 7459ULL: goto x86_l_1d23;
	case 7465ULL: goto x86_l_1d29;
	case 7472ULL: goto x86_l_1d30;
	case 7476ULL: goto x86_l_1d34;
	case 7485ULL: goto x86_l_1d3d;
	case 7487ULL: goto x86_l_1d3f;
	case 7492ULL: goto x86_l_1d44;
	case 7496ULL: goto x86_l_1d48;
	case 7499ULL: goto x86_l_1d4b;
	case 7504ULL: goto x86_l_1d50;
	case 7506ULL: goto x86_l_1d52;
	case 7508ULL: goto x86_l_1d54;
	case 7514ULL: goto x86_l_1d5a;
	case 7523ULL: goto x86_l_1d63;
	case 7529ULL: goto x86_l_1d69;
	case 7536ULL: goto x86_l_1d70;
	case 7540ULL: goto x86_l_1d74;
	case 7549ULL: goto x86_l_1d7d;
	case 7551ULL: goto x86_l_1d7f;
	case 7556ULL: goto x86_l_1d84;
	case 7560ULL: goto x86_l_1d88;
	case 7563ULL: goto x86_l_1d8b;
	case 7568ULL: goto x86_l_1d90;
	case 7570ULL: goto x86_l_1d92;
	case 7572ULL: goto x86_l_1d94;
	case 7578ULL: goto x86_l_1d9a;
	case 7587ULL: goto x86_l_1da3;
	case 7593ULL: goto x86_l_1da9;
	case 7600ULL: goto x86_l_1db0;
	case 7604ULL: goto x86_l_1db4;
	case 7613ULL: goto x86_l_1dbd;
	case 7615ULL: goto x86_l_1dbf;
	case 7620ULL: goto x86_l_1dc4;
	case 7624ULL: goto x86_l_1dc8;
	case 7627ULL: goto x86_l_1dcb;
	case 7632ULL: goto x86_l_1dd0;
	case 7634ULL: goto x86_l_1dd2;
	case 7636ULL: goto x86_l_1dd4;
	case 7642ULL: goto x86_l_1dda;
	case 7651ULL: goto x86_l_1de3;
	case 7657ULL: goto x86_l_1de9;
	case 7664ULL: goto x86_l_1df0;
	case 7668ULL: goto x86_l_1df4;
	case 7677ULL: goto x86_l_1dfd;
	case 7679ULL: goto x86_l_1dff;
	case 7684ULL: goto x86_l_1e04;
	case 7688ULL: goto x86_l_1e08;
	case 7691ULL: goto x86_l_1e0b;
	case 7696ULL: goto x86_l_1e10;
	case 7698ULL: goto x86_l_1e12;
	case 7700ULL: goto x86_l_1e14;
	case 7706ULL: goto x86_l_1e1a;
	case 7715ULL: goto x86_l_1e23;
	case 7721ULL: goto x86_l_1e29;
	case 7728ULL: goto x86_l_1e30;
	case 7732ULL: goto x86_l_1e34;
	case 7741ULL: goto x86_l_1e3d;
	case 7743ULL: goto x86_l_1e3f;
	case 7748ULL: goto x86_l_1e44;
	case 7752ULL: goto x86_l_1e48;
	case 7755ULL: goto x86_l_1e4b;
	case 7760ULL: goto x86_l_1e50;
	case 7762ULL: goto x86_l_1e52;
	case 7764ULL: goto x86_l_1e54;
	case 7770ULL: goto x86_l_1e5a;
	case 7779ULL: goto x86_l_1e63;
	case 7785ULL: goto x86_l_1e69;
	case 7792ULL: goto x86_l_1e70;
	case 7796ULL: goto x86_l_1e74;
	case 7805ULL: goto x86_l_1e7d;
	case 7807ULL: goto x86_l_1e7f;
	case 7812ULL: goto x86_l_1e84;
	case 7816ULL: goto x86_l_1e88;
	case 7819ULL: goto x86_l_1e8b;
	case 7824ULL: goto x86_l_1e90;
	case 7826ULL: goto x86_l_1e92;
	case 7828ULL: goto x86_l_1e94;
	case 7834ULL: goto x86_l_1e9a;
	case 7839ULL: goto x86_l_1e9f;
	case 7848ULL: goto x86_l_1ea8;
	case 7854ULL: goto x86_l_1eae;
	case 7861ULL: goto x86_l_1eb5;
	case 7865ULL: goto x86_l_1eb9;
	case 7874ULL: goto x86_l_1ec2;
	case 7880ULL: goto x86_l_1ec8;
	case 7885ULL: goto x86_l_1ecd;
	case 7890ULL: goto x86_l_1ed2;
	case 7893ULL: goto x86_l_1ed5;
	case 7895ULL: goto x86_l_1ed7;
	case 7900ULL: goto x86_l_1edc;
	case 7904ULL: goto x86_l_1ee0;
	case 7907ULL: goto x86_l_1ee3;
	case 7912ULL: goto x86_l_1ee8;
	case 7914ULL: goto x86_l_1eea;
	case 7916ULL: goto x86_l_1eec;
	case 7922ULL: goto x86_l_1ef2;
	case 7931ULL: goto x86_l_1efb;
	case 7937ULL: goto x86_l_1f01;
	case 7944ULL: goto x86_l_1f08;
	case 7948ULL: goto x86_l_1f0c;
	case 7957ULL: goto x86_l_1f15;
	case 7959ULL: goto x86_l_1f17;
	case 7964ULL: goto x86_l_1f1c;
	case 7968ULL: goto x86_l_1f20;
	case 7971ULL: goto x86_l_1f23;
	case 7976ULL: goto x86_l_1f28;
	case 7978ULL: goto x86_l_1f2a;
	case 7980ULL: goto x86_l_1f2c;
	case 7986ULL: goto x86_l_1f32;
	case 7995ULL: goto x86_l_1f3b;
	case 8001ULL: goto x86_l_1f41;
	case 8008ULL: goto x86_l_1f48;
	case 8012ULL: goto x86_l_1f4c;
	case 8021ULL: goto x86_l_1f55;
	case 8023ULL: goto x86_l_1f57;
	case 8028ULL: goto x86_l_1f5c;
	case 8032ULL: goto x86_l_1f60;
	case 8035ULL: goto x86_l_1f63;
	case 8040ULL: goto x86_l_1f68;
	case 8042ULL: goto x86_l_1f6a;
	case 8044ULL: goto x86_l_1f6c;
	case 8050ULL: goto x86_l_1f72;
	case 8059ULL: goto x86_l_1f7b;
	case 8065ULL: goto x86_l_1f81;
	case 8072ULL: goto x86_l_1f88;
	case 8076ULL: goto x86_l_1f8c;
	case 8085ULL: goto x86_l_1f95;
	case 8087ULL: goto x86_l_1f97;
	case 8092ULL: goto x86_l_1f9c;
	case 8096ULL: goto x86_l_1fa0;
	case 8099ULL: goto x86_l_1fa3;
	case 8104ULL: goto x86_l_1fa8;
	case 8106ULL: goto x86_l_1faa;
	case 8108ULL: goto x86_l_1fac;
	case 8114ULL: goto x86_l_1fb2;
	case 8123ULL: goto x86_l_1fbb;
	case 8129ULL: goto x86_l_1fc1;
	case 8136ULL: goto x86_l_1fc8;
	case 8140ULL: goto x86_l_1fcc;
	case 8149ULL: goto x86_l_1fd5;
	case 8151ULL: goto x86_l_1fd7;
	case 8156ULL: goto x86_l_1fdc;
	case 8160ULL: goto x86_l_1fe0;
	case 8163ULL: goto x86_l_1fe3;
	case 8168ULL: goto x86_l_1fe8;
	case 8170ULL: goto x86_l_1fea;
	case 8172ULL: goto x86_l_1fec;
	case 8178ULL: goto x86_l_1ff2;
	case 8187ULL: goto x86_l_1ffb;
	case 8193ULL: goto x86_l_2001;
	case 8200ULL: goto x86_l_2008;
	case 8204ULL: goto x86_l_200c;
	case 8213ULL: goto x86_l_2015;
	case 8215ULL: goto x86_l_2017;
	case 8220ULL: goto x86_l_201c;
	case 8224ULL: goto x86_l_2020;
	case 8227ULL: goto x86_l_2023;
	case 8232ULL: goto x86_l_2028;
	case 8234ULL: goto x86_l_202a;
	case 8236ULL: goto x86_l_202c;
	case 8242ULL: goto x86_l_2032;
	case 8251ULL: goto x86_l_203b;
	case 8257ULL: goto x86_l_2041;
	case 8264ULL: goto x86_l_2048;
	case 8268ULL: goto x86_l_204c;
	case 8277ULL: goto x86_l_2055;
	case 8279ULL: goto x86_l_2057;
	case 8284ULL: goto x86_l_205c;
	case 8288ULL: goto x86_l_2060;
	case 8291ULL: goto x86_l_2063;
	case 8296ULL: goto x86_l_2068;
	case 8298ULL: goto x86_l_206a;
	case 8300ULL: goto x86_l_206c;
	case 8306ULL: goto x86_l_2072;
	case 8315ULL: goto x86_l_207b;
	case 8321ULL: goto x86_l_2081;
	case 8328ULL: goto x86_l_2088;
	case 8332ULL: goto x86_l_208c;
	case 8341ULL: goto x86_l_2095;
	case 8343ULL: goto x86_l_2097;
	case 8348ULL: goto x86_l_209c;
	case 8352ULL: goto x86_l_20a0;
	case 8355ULL: goto x86_l_20a3;
	case 8360ULL: goto x86_l_20a8;
	case 8362ULL: goto x86_l_20aa;
	case 8364ULL: goto x86_l_20ac;
	case 8370ULL: goto x86_l_20b2;
	case 8375ULL: goto x86_l_20b7;
	case 8384ULL: goto x86_l_20c0;
	case 8390ULL: goto x86_l_20c6;
	case 8397ULL: goto x86_l_20cd;
	case 8401ULL: goto x86_l_20d1;
	case 8410ULL: goto x86_l_20da;
	case 8412ULL: goto x86_l_20dc;
	case 8417ULL: goto x86_l_20e1;
	case 8421ULL: goto x86_l_20e5;
	case 8424ULL: goto x86_l_20e8;
	case 8429ULL: goto x86_l_20ed;
	case 8431ULL: goto x86_l_20ef;
	case 8433ULL: goto x86_l_20f1;
	case 8439ULL: goto x86_l_20f7;
	case 8444ULL: goto x86_l_20fc;
	case 8453ULL: goto x86_l_2105;
	case 8459ULL: goto x86_l_210b;
	case 8466ULL: goto x86_l_2112;
	case 8470ULL: goto x86_l_2116;
	case 8479ULL: goto x86_l_211f;
	case 8485ULL: goto x86_l_2125;
	case 8490ULL: goto x86_l_212a;
	case 8494ULL: goto x86_l_212e;
	case 8497ULL: goto x86_l_2131;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1a42:
	/* 0x1a42: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a47:
	/* 0x1a47: jmp    1aaf <generic_sleepable_preload+0x1aaf> */
	goto x86_l_1aaf;
x86_l_1a49:
	/* 0x1a49: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_1a4e:
	/* 0x1a4e: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a51:
	/* 0x1a51: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_1a54:
	/* 0x1a54: jne    1aef <generic_sleepable_preload+0x1aef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1aef;
	}
x86_l_1a5a:
	/* 0x1a5a: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a5e:
	/* 0x1a5e: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1a63:
	/* 0x1a63: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a65:
	/* 0x1a65: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a6a:
	/* 0x1a6a: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_1a72:
	/* 0x1a72: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a77:
	/* 0x1a77: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_1a7e:
	/* 0x1a7e: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1a83:
	/* 0x1a83: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a85:
	/* 0x1a85: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a88:
	/* 0x1a88: je     1aef <generic_sleepable_preload+0x1aef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1aef;
	}
x86_l_1a8a:
	/* 0x1a8a: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_1a90:
	/* 0x1a90: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_1a97:
	/* 0x1a97: lea    r13,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a9c:
	/* 0x1a9c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1a9f:
	/* 0x1a9f: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1aa2:
	/* 0x1aa2: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1aa5:
	/* 0x1aa5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1aa7:
	/* 0x1aa7: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_1aaa:
	/* 0x1aaa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1aaf:
	/* 0x1aaf: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1ab2:
	/* 0x1ab2: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1ab5:
	/* 0x1ab5: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1aba:
	/* 0x1aba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1abc:
	/* 0x1abc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1abf:
	/* 0x1abf: je     1aef <generic_sleepable_preload+0x1aef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1aef;
	}
x86_l_1ac1:
	/* 0x1ac1: test   r14b,r14b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_8);
x86_l_1ac4:
	/* 0x1ac4: je     1aed <generic_sleepable_preload+0x1aed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1aed;
	}
x86_l_1ac6:
	/* 0x1ac6: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1ac9:
	/* 0x1ac9: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1acd:
	/* 0x1acd: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1ad2:
	/* 0x1ad2: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1ad5:
	/* 0x1ad5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ad7:
	/* 0x1ad7: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1ada:
	/* 0x1ada: call   1adf <generic_sleepable_preload+0x1adf> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_1adf:
	/* 0x1adf: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1ae1:
	/* 0x1ae1: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_1ae4:
	/* 0x1ae4: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1ae6:
	/* 0x1ae6: jns    1aed <generic_sleepable_preload+0x1aed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_1aed;
	}
x86_l_1ae8:
	/* 0x1ae8: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_1aed:
	/* 0x1aed: mov    DWORD PTR [rax],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1aef:
	/* 0x1aef: mov    rdi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1af4:
	/* 0x1af4: mov    eax,DWORD PTR [r13+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1af8:
	/* 0x1af8: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_1afd:
	/* 0x1afd: je     dae <generic_sleepable_preload+0xdae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3502ULL;
	}
x86_l_1b03:
	/* 0x1b03: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1b05:
	/* 0x1b05: js     1b39 <generic_sleepable_preload+0x1b39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1b39;
	}
x86_l_1b07:
	/* 0x1b07: mov    ecx,DWORD PTR [r13+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_1b0b:
	/* 0x1b0b: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1b0e:
	/* 0x1b0e: jle    1bba <generic_sleepable_preload+0x1bba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1bba;
	}
x86_l_1b14:
	/* 0x1b14: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1b17:
	/* 0x1b17: je     1c24 <generic_sleepable_preload+0x1c24> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c24;
	}
x86_l_1b1d:
	/* 0x1b1d: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1b20:
	/* 0x1b20: je     1c2b <generic_sleepable_preload+0x1c2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c2b;
	}
x86_l_1b26:
	/* 0x1b26: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1b29:
	/* 0x1b29: jne    1c3e <generic_sleepable_preload+0x1c3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1c3e;
	}
x86_l_1b2f:
	/* 0x1b2f: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b34:
	/* 0x1b34: jmp    1c37 <generic_sleepable_preload+0x1c37> */
	goto x86_l_1c37;
x86_l_1b39:
	/* 0x1b39: movzx  ecx,BYTE PTR [r13+0x2c6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 710ULL);
x86_l_1b41:
	/* 0x1b41: movzx  eax,WORD PTR [r13+0x2c4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 708ULL);
x86_l_1b49:
	/* 0x1b49: rorx   edx,eax,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 3ULL);
x86_l_1b4f:
	/* 0x1b4f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b51:
	/* 0x1b51: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_1b54:
	/* 0x1b54: jle    1b93 <generic_sleepable_preload+0x1b93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1b93;
	}
x86_l_1b56:
	/* 0x1b56: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_1b59:
	/* 0x1b59: jle    1bca <generic_sleepable_preload+0x1bca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1bca;
	}
x86_l_1b5b:
	/* 0x1b5b: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1b5e:
	/* 0x1b5e: jle    219f <generic_sleepable_preload+0x219f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 8607ULL;
	}
x86_l_1b64:
	/* 0x1b64: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1b69:
	/* 0x1b69: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_1b6c:
	/* 0x1b6c: je     21c4 <generic_sleepable_preload+0x21c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8644ULL;
	}
x86_l_1b72:
	/* 0x1b72: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1b77:
	/* 0x1b77: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_1b7a:
	/* 0x1b7a: je     21c4 <generic_sleepable_preload+0x21c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8644ULL;
	}
x86_l_1b80:
	/* 0x1b80: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1b85:
	/* 0x1b85: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_1b88:
	/* 0x1b88: je     21c4 <generic_sleepable_preload+0x21c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8644ULL;
	}
x86_l_1b8e:
	/* 0x1b8e: jmp    21d7 <generic_sleepable_preload+0x21d7> */
	return 8663ULL;
x86_l_1b93:
	/* 0x1b93: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_1b96:
	/* 0x1b96: jg     1bf7 <generic_sleepable_preload+0x1bf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1bf7;
	}
x86_l_1b98:
	/* 0x1b98: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_1b9b:
	/* 0x1b9b: jg     216d <generic_sleepable_preload+0x216d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 8557ULL;
	}
x86_l_1ba1:
	/* 0x1ba1: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_1ba3:
	/* 0x1ba3: je     21bf <generic_sleepable_preload+0x21bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8639ULL;
	}
x86_l_1ba9:
	/* 0x1ba9: mov    rsi,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDI, X86_WIDTH_64);
x86_l_1bac:
	/* 0x1bac: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_1baf:
	/* 0x1baf: je     21c4 <generic_sleepable_preload+0x21c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8644ULL;
	}
x86_l_1bb5:
	/* 0x1bb5: jmp    21d7 <generic_sleepable_preload+0x21d7> */
	return 8663ULL;
x86_l_1bba:
	/* 0x1bba: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1bbc:
	/* 0x1bbc: je     1c32 <generic_sleepable_preload+0x1c32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c32;
	}
x86_l_1bbe:
	/* 0x1bbe: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1bc1:
	/* 0x1bc1: jne    1c3e <generic_sleepable_preload+0x1c3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1c3e;
	}
x86_l_1bc3:
	/* 0x1bc3: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1bc8:
	/* 0x1bc8: jmp    1c37 <generic_sleepable_preload+0x1c37> */
	goto x86_l_1c37;
x86_l_1bca:
	/* 0x1bca: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_1bcd:
	/* 0x1bcd: jg     2154 <generic_sleepable_preload+0x2154> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 8532ULL;
	}
x86_l_1bd3:
	/* 0x1bd3: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1bdb:
	/* 0x1bdb: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1bde:
	/* 0x1bde: je     21c4 <generic_sleepable_preload+0x21c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8644ULL;
	}
x86_l_1be4:
	/* 0x1be4: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1be9:
	/* 0x1be9: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_1bec:
	/* 0x1bec: je     21c4 <generic_sleepable_preload+0x21c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8644ULL;
	}
x86_l_1bf2:
	/* 0x1bf2: jmp    21d7 <generic_sleepable_preload+0x21d7> */
	return 8663ULL;
x86_l_1bf7:
	/* 0x1bf7: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1bfa:
	/* 0x1bfa: jg     2186 <generic_sleepable_preload+0x2186> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 8582ULL;
	}
x86_l_1c00:
	/* 0x1c00: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1c08:
	/* 0x1c08: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1c0b:
	/* 0x1c0b: je     21c4 <generic_sleepable_preload+0x21c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8644ULL;
	}
x86_l_1c11:
	/* 0x1c11: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1c16:
	/* 0x1c16: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1c19:
	/* 0x1c19: je     21c4 <generic_sleepable_preload+0x21c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8644ULL;
	}
x86_l_1c1f:
	/* 0x1c1f: jmp    21d7 <generic_sleepable_preload+0x21d7> */
	return 8663ULL;
x86_l_1c24:
	/* 0x1c24: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1c29:
	/* 0x1c29: jmp    1c37 <generic_sleepable_preload+0x1c37> */
	goto x86_l_1c37;
x86_l_1c2b:
	/* 0x1c2b: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c30:
	/* 0x1c30: jmp    1c37 <generic_sleepable_preload+0x1c37> */
	goto x86_l_1c37;
x86_l_1c32:
	/* 0x1c32: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1c37:
	/* 0x1c37: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c3a:
	/* 0x1c3a: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c3e:
	/* 0x1c3e: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c40:
	/* 0x1c40: mov    r14b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_8, 1ULL);
x86_l_1c43:
	/* 0x1c43: cmp    WORD PTR [r13+0xc6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 850403524608ULL);
x86_l_1c4c:
	/* 0x1c4c: je     274b <generic_sleepable_preload+0x274b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10059ULL;
	}
x86_l_1c52:
	/* 0x1c52: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_1c59:
	/* 0x1c59: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1c5c:
	/* 0x1c5c: mov    edx,DWORD PTR [r13+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1c63:
	/* 0x1c63: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1c66:
	/* 0x1c66: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c6a:
	/* 0x1c6a: movzx  eax,WORD PTR [r13+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 196ULL);
x86_l_1c72:
	/* 0x1c72: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_1c74:
	/* 0x1c74: je     1ed2 <generic_sleepable_preload+0x1ed2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ed2;
	}
x86_l_1c7a:
	/* 0x1c7a: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_1c7d:
	/* 0x1c7d: je     1c9a <generic_sleepable_preload+0x1c9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c9a;
	}
x86_l_1c7f:
	/* 0x1c7f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1c84:
	/* 0x1c84: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c88:
	/* 0x1c88: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1c8b:
	/* 0x1c8b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c90:
	/* 0x1c90: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c92:
	/* 0x1c92: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c94:
	/* 0x1c94: js     214a <generic_sleepable_preload+0x214a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8522ULL;
	}
x86_l_1c9a:
	/* 0x1c9a: cmp    WORD PTR [r13+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_1ca3:
	/* 0x1ca3: je     274b <generic_sleepable_preload+0x274b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10059ULL;
	}
x86_l_1ca9:
	/* 0x1ca9: mov    eax,DWORD PTR [r13+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1cb0:
	/* 0x1cb0: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1cb4:
	/* 0x1cb4: cmp    WORD PTR [r13+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_1cbd:
	/* 0x1cbd: je     1cda <generic_sleepable_preload+0x1cda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1cda;
	}
x86_l_1cbf:
	/* 0x1cbf: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1cc4:
	/* 0x1cc4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cc8:
	/* 0x1cc8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1ccb:
	/* 0x1ccb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1cd0:
	/* 0x1cd0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cd2:
	/* 0x1cd2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1cd4:
	/* 0x1cd4: js     21b5 <generic_sleepable_preload+0x21b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8629ULL;
	}
x86_l_1cda:
	/* 0x1cda: cmp    WORD PTR [r13+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_1ce3:
	/* 0x1ce3: je     274b <generic_sleepable_preload+0x274b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10059ULL;
	}
x86_l_1ce9:
	/* 0x1ce9: mov    eax,DWORD PTR [r13+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1cf0:
	/* 0x1cf0: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1cf4:
	/* 0x1cf4: cmp    WORD PTR [r13+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_1cfd:
	/* 0x1cfd: je     1d1a <generic_sleepable_preload+0x1d1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d1a;
	}
x86_l_1cff:
	/* 0x1cff: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1d04:
	/* 0x1d04: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d08:
	/* 0x1d08: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1d0b:
	/* 0x1d0b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d10:
	/* 0x1d10: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d12:
	/* 0x1d12: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d14:
	/* 0x1d14: js     26ff <generic_sleepable_preload+0x26ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9983ULL;
	}
x86_l_1d1a:
	/* 0x1d1a: cmp    WORD PTR [r13+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_1d23:
	/* 0x1d23: je     274b <generic_sleepable_preload+0x274b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10059ULL;
	}
x86_l_1d29:
	/* 0x1d29: mov    eax,DWORD PTR [r13+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_1d30:
	/* 0x1d30: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1d34:
	/* 0x1d34: cmp    WORD PTR [r13+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_1d3d:
	/* 0x1d3d: je     1d5a <generic_sleepable_preload+0x1d5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d5a;
	}
x86_l_1d3f:
	/* 0x1d3f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1d44:
	/* 0x1d44: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d48:
	/* 0x1d48: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1d4b:
	/* 0x1d4b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d50:
	/* 0x1d50: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d52:
	/* 0x1d52: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d54:
	/* 0x1d54: js     2710 <generic_sleepable_preload+0x2710> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10000ULL;
	}
x86_l_1d5a:
	/* 0x1d5a: cmp    WORD PTR [r13+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_1d63:
	/* 0x1d63: je     274b <generic_sleepable_preload+0x274b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10059ULL;
	}
x86_l_1d69:
	/* 0x1d69: mov    eax,DWORD PTR [r13+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_1d70:
	/* 0x1d70: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1d74:
	/* 0x1d74: cmp    WORD PTR [r13+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_1d7d:
	/* 0x1d7d: je     1d9a <generic_sleepable_preload+0x1d9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d9a;
	}
x86_l_1d7f:
	/* 0x1d7f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1d84:
	/* 0x1d84: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d88:
	/* 0x1d88: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1d8b:
	/* 0x1d8b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d90:
	/* 0x1d90: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d92:
	/* 0x1d92: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d94:
	/* 0x1d94: js     2721 <generic_sleepable_preload+0x2721> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10017ULL;
	}
x86_l_1d9a:
	/* 0x1d9a: cmp    WORD PTR [r13+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_1da3:
	/* 0x1da3: je     274b <generic_sleepable_preload+0x274b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10059ULL;
	}
x86_l_1da9:
	/* 0x1da9: mov    eax,DWORD PTR [r13+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_1db0:
	/* 0x1db0: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1db4:
	/* 0x1db4: cmp    WORD PTR [r13+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_1dbd:
	/* 0x1dbd: je     1dda <generic_sleepable_preload+0x1dda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1dda;
	}
x86_l_1dbf:
	/* 0x1dbf: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1dc4:
	/* 0x1dc4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1dc8:
	/* 0x1dc8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1dcb:
	/* 0x1dcb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1dd0:
	/* 0x1dd0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dd2:
	/* 0x1dd2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1dd4:
	/* 0x1dd4: js     2732 <generic_sleepable_preload+0x2732> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10034ULL;
	}
x86_l_1dda:
	/* 0x1dda: cmp    WORD PTR [r13+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_1de3:
	/* 0x1de3: je     274b <generic_sleepable_preload+0x274b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10059ULL;
	}
x86_l_1de9:
	/* 0x1de9: mov    eax,DWORD PTR [r13+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_1df0:
	/* 0x1df0: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1df4:
	/* 0x1df4: cmp    WORD PTR [r13+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_1dfd:
	/* 0x1dfd: je     1e1a <generic_sleepable_preload+0x1e1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e1a;
	}
x86_l_1dff:
	/* 0x1dff: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1e04:
	/* 0x1e04: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e08:
	/* 0x1e08: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1e0b:
	/* 0x1e0b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e10:
	/* 0x1e10: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e12:
	/* 0x1e12: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e14:
	/* 0x1e14: js     2743 <generic_sleepable_preload+0x2743> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10051ULL;
	}
x86_l_1e1a:
	/* 0x1e1a: cmp    WORD PTR [r13+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_1e23:
	/* 0x1e23: je     274b <generic_sleepable_preload+0x274b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10059ULL;
	}
x86_l_1e29:
	/* 0x1e29: mov    eax,DWORD PTR [r13+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_1e30:
	/* 0x1e30: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1e34:
	/* 0x1e34: cmp    WORD PTR [r13+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_1e3d:
	/* 0x1e3d: je     1e5a <generic_sleepable_preload+0x1e5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e5a;
	}
x86_l_1e3f:
	/* 0x1e3f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1e44:
	/* 0x1e44: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e48:
	/* 0x1e48: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1e4b:
	/* 0x1e4b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e50:
	/* 0x1e50: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e52:
	/* 0x1e52: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e54:
	/* 0x1e54: js     51fa <generic_sleepable_preload+0x51fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20986ULL;
	}
x86_l_1e5a:
	/* 0x1e5a: cmp    WORD PTR [r13+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_1e63:
	/* 0x1e63: je     274b <generic_sleepable_preload+0x274b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10059ULL;
	}
x86_l_1e69:
	/* 0x1e69: mov    eax,DWORD PTR [r13+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_1e70:
	/* 0x1e70: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1e74:
	/* 0x1e74: cmp    WORD PTR [r13+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_1e7d:
	/* 0x1e7d: je     1e9a <generic_sleepable_preload+0x1e9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e9a;
	}
x86_l_1e7f:
	/* 0x1e7f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1e84:
	/* 0x1e84: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e88:
	/* 0x1e88: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1e8b:
	/* 0x1e8b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e90:
	/* 0x1e90: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e92:
	/* 0x1e92: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e94:
	/* 0x1e94: js     526c <generic_sleepable_preload+0x526c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21100ULL;
	}
x86_l_1e9a:
	/* 0x1e9a: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e9f:
	/* 0x1e9f: cmp    WORD PTR [r13+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_1ea8:
	/* 0x1ea8: je     274b <generic_sleepable_preload+0x274b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10059ULL;
	}
x86_l_1eae:
	/* 0x1eae: mov    eax,DWORD PTR [r13+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_1eb5:
	/* 0x1eb5: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1eb9:
	/* 0x1eb9: cmp    WORD PTR [r13+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_1ec2:
	/* 0x1ec2: je     274b <generic_sleepable_preload+0x274b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10059ULL;
	}
x86_l_1ec8:
	/* 0x1ec8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1ecd:
	/* 0x1ecd: jmp    212a <generic_sleepable_preload+0x212a> */
	goto x86_l_212a;
x86_l_1ed2:
	/* 0x1ed2: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_1ed5:
	/* 0x1ed5: je     1ef2 <generic_sleepable_preload+0x1ef2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ef2;
	}
x86_l_1ed7:
	/* 0x1ed7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1edc:
	/* 0x1edc: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ee0:
	/* 0x1ee0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1ee3:
	/* 0x1ee3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ee8:
	/* 0x1ee8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1eea:
	/* 0x1eea: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1eec:
	/* 0x1eec: js     214a <generic_sleepable_preload+0x214a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8522ULL;
	}
x86_l_1ef2:
	/* 0x1ef2: cmp    WORD PTR [r13+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_1efb:
	/* 0x1efb: je     274b <generic_sleepable_preload+0x274b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10059ULL;
	}
x86_l_1f01:
	/* 0x1f01: mov    eax,DWORD PTR [r13+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1f08:
	/* 0x1f08: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1f0c:
	/* 0x1f0c: cmp    WORD PTR [r13+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_1f15:
	/* 0x1f15: je     1f32 <generic_sleepable_preload+0x1f32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f32;
	}
x86_l_1f17:
	/* 0x1f17: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1f1c:
	/* 0x1f1c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f20:
	/* 0x1f20: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1f23:
	/* 0x1f23: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f28:
	/* 0x1f28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f2a:
	/* 0x1f2a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f2c:
	/* 0x1f2c: js     21b5 <generic_sleepable_preload+0x21b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8629ULL;
	}
x86_l_1f32:
	/* 0x1f32: cmp    WORD PTR [r13+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_1f3b:
	/* 0x1f3b: je     274b <generic_sleepable_preload+0x274b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10059ULL;
	}
x86_l_1f41:
	/* 0x1f41: mov    eax,DWORD PTR [r13+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1f48:
	/* 0x1f48: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1f4c:
	/* 0x1f4c: cmp    WORD PTR [r13+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_1f55:
	/* 0x1f55: je     1f72 <generic_sleepable_preload+0x1f72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f72;
	}
x86_l_1f57:
	/* 0x1f57: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1f5c:
	/* 0x1f5c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f60:
	/* 0x1f60: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1f63:
	/* 0x1f63: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f68:
	/* 0x1f68: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f6a:
	/* 0x1f6a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f6c:
	/* 0x1f6c: js     26ff <generic_sleepable_preload+0x26ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9983ULL;
	}
x86_l_1f72:
	/* 0x1f72: cmp    WORD PTR [r13+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_1f7b:
	/* 0x1f7b: je     274b <generic_sleepable_preload+0x274b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10059ULL;
	}
x86_l_1f81:
	/* 0x1f81: mov    eax,DWORD PTR [r13+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_1f88:
	/* 0x1f88: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1f8c:
	/* 0x1f8c: cmp    WORD PTR [r13+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_1f95:
	/* 0x1f95: je     1fb2 <generic_sleepable_preload+0x1fb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fb2;
	}
x86_l_1f97:
	/* 0x1f97: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1f9c:
	/* 0x1f9c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fa0:
	/* 0x1fa0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1fa3:
	/* 0x1fa3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1fa8:
	/* 0x1fa8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1faa:
	/* 0x1faa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1fac:
	/* 0x1fac: js     2710 <generic_sleepable_preload+0x2710> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10000ULL;
	}
x86_l_1fb2:
	/* 0x1fb2: cmp    WORD PTR [r13+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_1fbb:
	/* 0x1fbb: je     274b <generic_sleepable_preload+0x274b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10059ULL;
	}
x86_l_1fc1:
	/* 0x1fc1: mov    eax,DWORD PTR [r13+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_1fc8:
	/* 0x1fc8: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1fcc:
	/* 0x1fcc: cmp    WORD PTR [r13+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_1fd5:
	/* 0x1fd5: je     1ff2 <generic_sleepable_preload+0x1ff2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ff2;
	}
x86_l_1fd7:
	/* 0x1fd7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1fdc:
	/* 0x1fdc: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fe0:
	/* 0x1fe0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1fe3:
	/* 0x1fe3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1fe8:
	/* 0x1fe8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fea:
	/* 0x1fea: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1fec:
	/* 0x1fec: js     2721 <generic_sleepable_preload+0x2721> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10017ULL;
	}
x86_l_1ff2:
	/* 0x1ff2: cmp    WORD PTR [r13+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_1ffb:
	/* 0x1ffb: je     274b <generic_sleepable_preload+0x274b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10059ULL;
	}
x86_l_2001:
	/* 0x2001: mov    eax,DWORD PTR [r13+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_2008:
	/* 0x2008: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_200c:
	/* 0x200c: cmp    WORD PTR [r13+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_2015:
	/* 0x2015: je     2032 <generic_sleepable_preload+0x2032> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2032;
	}
x86_l_2017:
	/* 0x2017: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_201c:
	/* 0x201c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2020:
	/* 0x2020: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2023:
	/* 0x2023: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2028:
	/* 0x2028: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_202a:
	/* 0x202a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_202c:
	/* 0x202c: js     2732 <generic_sleepable_preload+0x2732> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10034ULL;
	}
x86_l_2032:
	/* 0x2032: cmp    WORD PTR [r13+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_203b:
	/* 0x203b: je     274b <generic_sleepable_preload+0x274b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10059ULL;
	}
x86_l_2041:
	/* 0x2041: mov    eax,DWORD PTR [r13+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_2048:
	/* 0x2048: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_204c:
	/* 0x204c: cmp    WORD PTR [r13+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_2055:
	/* 0x2055: je     2072 <generic_sleepable_preload+0x2072> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2072;
	}
x86_l_2057:
	/* 0x2057: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_205c:
	/* 0x205c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2060:
	/* 0x2060: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2063:
	/* 0x2063: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2068:
	/* 0x2068: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_206a:
	/* 0x206a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_206c:
	/* 0x206c: js     2743 <generic_sleepable_preload+0x2743> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10051ULL;
	}
x86_l_2072:
	/* 0x2072: cmp    WORD PTR [r13+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_207b:
	/* 0x207b: je     274b <generic_sleepable_preload+0x274b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10059ULL;
	}
x86_l_2081:
	/* 0x2081: mov    eax,DWORD PTR [r13+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_2088:
	/* 0x2088: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_208c:
	/* 0x208c: cmp    WORD PTR [r13+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_2095:
	/* 0x2095: je     20b2 <generic_sleepable_preload+0x20b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20b2;
	}
x86_l_2097:
	/* 0x2097: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_209c:
	/* 0x209c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20a0:
	/* 0x20a0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_20a3:
	/* 0x20a3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20a8:
	/* 0x20a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20aa:
	/* 0x20aa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20ac:
	/* 0x20ac: js     5310 <generic_sleepable_preload+0x5310> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21264ULL;
	}
x86_l_20b2:
	/* 0x20b2: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20b7:
	/* 0x20b7: cmp    WORD PTR [r13+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_20c0:
	/* 0x20c0: je     274b <generic_sleepable_preload+0x274b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10059ULL;
	}
x86_l_20c6:
	/* 0x20c6: mov    eax,DWORD PTR [r13+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_20cd:
	/* 0x20cd: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_20d1:
	/* 0x20d1: cmp    WORD PTR [r13+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_20da:
	/* 0x20da: je     20f7 <generic_sleepable_preload+0x20f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20f7;
	}
x86_l_20dc:
	/* 0x20dc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_20e1:
	/* 0x20e1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20e5:
	/* 0x20e5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_20e8:
	/* 0x20e8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20ed:
	/* 0x20ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20ef:
	/* 0x20ef: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20f1:
	/* 0x20f1: js     526c <generic_sleepable_preload+0x526c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21100ULL;
	}
x86_l_20f7:
	/* 0x20f7: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20fc:
	/* 0x20fc: cmp    WORD PTR [r13+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_2105:
	/* 0x2105: je     274b <generic_sleepable_preload+0x274b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10059ULL;
	}
x86_l_210b:
	/* 0x210b: mov    eax,DWORD PTR [r13+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_2112:
	/* 0x2112: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2116:
	/* 0x2116: cmp    WORD PTR [r13+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_211f:
	/* 0x211f: je     274b <generic_sleepable_preload+0x274b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10059ULL;
	}
x86_l_2125:
	/* 0x2125: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_212a:
	/* 0x212a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_212e:
	/* 0x212e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2131:
	/* 0x2131: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
	return 8502ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8502ULL: goto x86_l_2136;
	case 8504ULL: goto x86_l_2138;
	case 8506ULL: goto x86_l_213a;
	case 8512ULL: goto x86_l_2140;
	case 8517ULL: goto x86_l_2145;
	case 8522ULL: goto x86_l_214a;
	case 8527ULL: goto x86_l_214f;
	case 8532ULL: goto x86_l_2154;
	case 8540ULL: goto x86_l_215c;
	case 8543ULL: goto x86_l_215f;
	case 8545ULL: goto x86_l_2161;
	case 8550ULL: goto x86_l_2166;
	case 8553ULL: goto x86_l_2169;
	case 8555ULL: goto x86_l_216b;
	case 8557ULL: goto x86_l_216d;
	case 8565ULL: goto x86_l_2175;
	case 8568ULL: goto x86_l_2178;
	case 8570ULL: goto x86_l_217a;
	case 8575ULL: goto x86_l_217f;
	case 8578ULL: goto x86_l_2182;
	case 8580ULL: goto x86_l_2184;
	case 8582ULL: goto x86_l_2186;
	case 8590ULL: goto x86_l_218e;
	case 8593ULL: goto x86_l_2191;
	case 8595ULL: goto x86_l_2193;
	case 8600ULL: goto x86_l_2198;
	case 8603ULL: goto x86_l_219b;
	case 8605ULL: goto x86_l_219d;
	case 8607ULL: goto x86_l_219f;
	case 8612ULL: goto x86_l_21a4;
	case 8615ULL: goto x86_l_21a7;
	case 8617ULL: goto x86_l_21a9;
	case 8622ULL: goto x86_l_21ae;
	case 8625ULL: goto x86_l_21b1;
	case 8627ULL: goto x86_l_21b3;
	case 8629ULL: goto x86_l_21b5;
	case 8634ULL: goto x86_l_21ba;
	case 8639ULL: goto x86_l_21bf;
	case 8644ULL: goto x86_l_21c4;
	case 8647ULL: goto x86_l_21c7;
	case 8649ULL: goto x86_l_21c9;
	case 8651ULL: goto x86_l_21cb;
	case 8656ULL: goto x86_l_21d0;
	case 8658ULL: goto x86_l_21d2;
	case 8663ULL: goto x86_l_21d7;
	case 8667ULL: goto x86_l_21db;
	case 8671ULL: goto x86_l_21df;
	case 8673ULL: goto x86_l_21e1;
	case 8676ULL: goto x86_l_21e4;
	case 8685ULL: goto x86_l_21ed;
	case 8691ULL: goto x86_l_21f3;
	case 8698ULL: goto x86_l_21fa;
	case 8701ULL: goto x86_l_21fd;
	case 8708ULL: goto x86_l_2204;
	case 8711ULL: goto x86_l_2207;
	case 8715ULL: goto x86_l_220b;
	case 8723ULL: goto x86_l_2213;
	case 8725ULL: goto x86_l_2215;
	case 8731ULL: goto x86_l_221b;
	case 8734ULL: goto x86_l_221e;
	case 8736ULL: goto x86_l_2220;
	case 8741ULL: goto x86_l_2225;
	case 8745ULL: goto x86_l_2229;
	case 8748ULL: goto x86_l_222c;
	case 8753ULL: goto x86_l_2231;
	case 8755ULL: goto x86_l_2233;
	case 8757ULL: goto x86_l_2235;
	case 8763ULL: goto x86_l_223b;
	case 8772ULL: goto x86_l_2244;
	case 8778ULL: goto x86_l_224a;
	case 8785ULL: goto x86_l_2251;
	case 8789ULL: goto x86_l_2255;
	case 8798ULL: goto x86_l_225e;
	case 8800ULL: goto x86_l_2260;
	case 8805ULL: goto x86_l_2265;
	case 8809ULL: goto x86_l_2269;
	case 8812ULL: goto x86_l_226c;
	case 8817ULL: goto x86_l_2271;
	case 8819ULL: goto x86_l_2273;
	case 8821ULL: goto x86_l_2275;
	case 8827ULL: goto x86_l_227b;
	case 8836ULL: goto x86_l_2284;
	case 8842ULL: goto x86_l_228a;
	case 8849ULL: goto x86_l_2291;
	case 8853ULL: goto x86_l_2295;
	case 8862ULL: goto x86_l_229e;
	case 8864ULL: goto x86_l_22a0;
	case 8869ULL: goto x86_l_22a5;
	case 8873ULL: goto x86_l_22a9;
	case 8876ULL: goto x86_l_22ac;
	case 8881ULL: goto x86_l_22b1;
	case 8883ULL: goto x86_l_22b3;
	case 8885ULL: goto x86_l_22b5;
	case 8891ULL: goto x86_l_22bb;
	case 8900ULL: goto x86_l_22c4;
	case 8906ULL: goto x86_l_22ca;
	case 8913ULL: goto x86_l_22d1;
	case 8917ULL: goto x86_l_22d5;
	case 8926ULL: goto x86_l_22de;
	case 8928ULL: goto x86_l_22e0;
	case 8933ULL: goto x86_l_22e5;
	case 8937ULL: goto x86_l_22e9;
	case 8940ULL: goto x86_l_22ec;
	case 8945ULL: goto x86_l_22f1;
	case 8947ULL: goto x86_l_22f3;
	case 8949ULL: goto x86_l_22f5;
	case 8955ULL: goto x86_l_22fb;
	case 8964ULL: goto x86_l_2304;
	case 8970ULL: goto x86_l_230a;
	case 8977ULL: goto x86_l_2311;
	case 8981ULL: goto x86_l_2315;
	case 8990ULL: goto x86_l_231e;
	case 8992ULL: goto x86_l_2320;
	case 8997ULL: goto x86_l_2325;
	case 9001ULL: goto x86_l_2329;
	case 9004ULL: goto x86_l_232c;
	case 9009ULL: goto x86_l_2331;
	case 9011ULL: goto x86_l_2333;
	case 9013ULL: goto x86_l_2335;
	case 9019ULL: goto x86_l_233b;
	case 9028ULL: goto x86_l_2344;
	case 9034ULL: goto x86_l_234a;
	case 9041ULL: goto x86_l_2351;
	case 9045ULL: goto x86_l_2355;
	case 9054ULL: goto x86_l_235e;
	case 9056ULL: goto x86_l_2360;
	case 9061ULL: goto x86_l_2365;
	case 9065ULL: goto x86_l_2369;
	case 9068ULL: goto x86_l_236c;
	case 9073ULL: goto x86_l_2371;
	case 9075ULL: goto x86_l_2373;
	case 9077ULL: goto x86_l_2375;
	case 9083ULL: goto x86_l_237b;
	case 9092ULL: goto x86_l_2384;
	case 9098ULL: goto x86_l_238a;
	case 9105ULL: goto x86_l_2391;
	case 9109ULL: goto x86_l_2395;
	case 9118ULL: goto x86_l_239e;
	case 9120ULL: goto x86_l_23a0;
	case 9125ULL: goto x86_l_23a5;
	case 9129ULL: goto x86_l_23a9;
	case 9132ULL: goto x86_l_23ac;
	case 9137ULL: goto x86_l_23b1;
	case 9139ULL: goto x86_l_23b3;
	case 9141ULL: goto x86_l_23b5;
	case 9147ULL: goto x86_l_23bb;
	case 9156ULL: goto x86_l_23c4;
	case 9162ULL: goto x86_l_23ca;
	case 9169ULL: goto x86_l_23d1;
	case 9173ULL: goto x86_l_23d5;
	case 9182ULL: goto x86_l_23de;
	case 9184ULL: goto x86_l_23e0;
	case 9189ULL: goto x86_l_23e5;
	case 9193ULL: goto x86_l_23e9;
	case 9196ULL: goto x86_l_23ec;
	case 9201ULL: goto x86_l_23f1;
	case 9203ULL: goto x86_l_23f3;
	case 9205ULL: goto x86_l_23f5;
	case 9211ULL: goto x86_l_23fb;
	case 9220ULL: goto x86_l_2404;
	case 9226ULL: goto x86_l_240a;
	case 9233ULL: goto x86_l_2411;
	case 9237ULL: goto x86_l_2415;
	case 9246ULL: goto x86_l_241e;
	case 9248ULL: goto x86_l_2420;
	case 9253ULL: goto x86_l_2425;
	case 9257ULL: goto x86_l_2429;
	case 9260ULL: goto x86_l_242c;
	case 9265ULL: goto x86_l_2431;
	case 9267ULL: goto x86_l_2433;
	case 9269ULL: goto x86_l_2435;
	case 9275ULL: goto x86_l_243b;
	case 9280ULL: goto x86_l_2440;
	case 9289ULL: goto x86_l_2449;
	case 9295ULL: goto x86_l_244f;
	case 9302ULL: goto x86_l_2456;
	case 9306ULL: goto x86_l_245a;
	case 9315ULL: goto x86_l_2463;
	case 9321ULL: goto x86_l_2469;
	case 9326ULL: goto x86_l_246e;
	case 9331ULL: goto x86_l_2473;
	case 9334ULL: goto x86_l_2476;
	case 9336ULL: goto x86_l_2478;
	case 9341ULL: goto x86_l_247d;
	case 9345ULL: goto x86_l_2481;
	case 9348ULL: goto x86_l_2484;
	case 9353ULL: goto x86_l_2489;
	case 9355ULL: goto x86_l_248b;
	case 9357ULL: goto x86_l_248d;
	case 9363ULL: goto x86_l_2493;
	case 9372ULL: goto x86_l_249c;
	case 9378ULL: goto x86_l_24a2;
	case 9385ULL: goto x86_l_24a9;
	case 9389ULL: goto x86_l_24ad;
	case 9398ULL: goto x86_l_24b6;
	case 9400ULL: goto x86_l_24b8;
	case 9405ULL: goto x86_l_24bd;
	case 9409ULL: goto x86_l_24c1;
	case 9412ULL: goto x86_l_24c4;
	case 9417ULL: goto x86_l_24c9;
	case 9419ULL: goto x86_l_24cb;
	case 9421ULL: goto x86_l_24cd;
	case 9427ULL: goto x86_l_24d3;
	case 9436ULL: goto x86_l_24dc;
	case 9442ULL: goto x86_l_24e2;
	case 9449ULL: goto x86_l_24e9;
	case 9453ULL: goto x86_l_24ed;
	case 9462ULL: goto x86_l_24f6;
	case 9464ULL: goto x86_l_24f8;
	case 9469ULL: goto x86_l_24fd;
	case 9473ULL: goto x86_l_2501;
	case 9476ULL: goto x86_l_2504;
	case 9481ULL: goto x86_l_2509;
	case 9483ULL: goto x86_l_250b;
	case 9485ULL: goto x86_l_250d;
	case 9491ULL: goto x86_l_2513;
	case 9500ULL: goto x86_l_251c;
	case 9506ULL: goto x86_l_2522;
	case 9513ULL: goto x86_l_2529;
	case 9517ULL: goto x86_l_252d;
	case 9526ULL: goto x86_l_2536;
	case 9528ULL: goto x86_l_2538;
	case 9533ULL: goto x86_l_253d;
	case 9537ULL: goto x86_l_2541;
	case 9540ULL: goto x86_l_2544;
	case 9545ULL: goto x86_l_2549;
	case 9547ULL: goto x86_l_254b;
	case 9549ULL: goto x86_l_254d;
	case 9555ULL: goto x86_l_2553;
	case 9564ULL: goto x86_l_255c;
	case 9570ULL: goto x86_l_2562;
	case 9577ULL: goto x86_l_2569;
	case 9581ULL: goto x86_l_256d;
	case 9590ULL: goto x86_l_2576;
	case 9592ULL: goto x86_l_2578;
	case 9597ULL: goto x86_l_257d;
	case 9601ULL: goto x86_l_2581;
	case 9604ULL: goto x86_l_2584;
	case 9609ULL: goto x86_l_2589;
	case 9611ULL: goto x86_l_258b;
	case 9613ULL: goto x86_l_258d;
	case 9619ULL: goto x86_l_2593;
	case 9628ULL: goto x86_l_259c;
	case 9634ULL: goto x86_l_25a2;
	case 9641ULL: goto x86_l_25a9;
	case 9645ULL: goto x86_l_25ad;
	case 9654ULL: goto x86_l_25b6;
	case 9656ULL: goto x86_l_25b8;
	case 9661ULL: goto x86_l_25bd;
	case 9665ULL: goto x86_l_25c1;
	case 9668ULL: goto x86_l_25c4;
	case 9673ULL: goto x86_l_25c9;
	case 9675ULL: goto x86_l_25cb;
	case 9677ULL: goto x86_l_25cd;
	case 9683ULL: goto x86_l_25d3;
	case 9692ULL: goto x86_l_25dc;
	case 9698ULL: goto x86_l_25e2;
	case 9705ULL: goto x86_l_25e9;
	case 9709ULL: goto x86_l_25ed;
	case 9718ULL: goto x86_l_25f6;
	case 9720ULL: goto x86_l_25f8;
	case 9725ULL: goto x86_l_25fd;
	case 9729ULL: goto x86_l_2601;
	case 9732ULL: goto x86_l_2604;
	case 9737ULL: goto x86_l_2609;
	case 9739ULL: goto x86_l_260b;
	case 9741ULL: goto x86_l_260d;
	case 9747ULL: goto x86_l_2613;
	case 9756ULL: goto x86_l_261c;
	case 9762ULL: goto x86_l_2622;
	case 9769ULL: goto x86_l_2629;
	case 9773ULL: goto x86_l_262d;
	case 9782ULL: goto x86_l_2636;
	case 9784ULL: goto x86_l_2638;
	case 9789ULL: goto x86_l_263d;
	case 9793ULL: goto x86_l_2641;
	case 9796ULL: goto x86_l_2644;
	case 9801ULL: goto x86_l_2649;
	case 9803ULL: goto x86_l_264b;
	case 9805ULL: goto x86_l_264d;
	case 9811ULL: goto x86_l_2653;
	case 9816ULL: goto x86_l_2658;
	case 9825ULL: goto x86_l_2661;
	case 9831ULL: goto x86_l_2667;
	case 9838ULL: goto x86_l_266e;
	case 9842ULL: goto x86_l_2672;
	case 9851ULL: goto x86_l_267b;
	case 9853ULL: goto x86_l_267d;
	case 9858ULL: goto x86_l_2682;
	case 9862ULL: goto x86_l_2686;
	case 9865ULL: goto x86_l_2689;
	case 9870ULL: goto x86_l_268e;
	case 9872ULL: goto x86_l_2690;
	case 9874ULL: goto x86_l_2692;
	case 9880ULL: goto x86_l_2698;
	case 9885ULL: goto x86_l_269d;
	case 9894ULL: goto x86_l_26a6;
	case 9900ULL: goto x86_l_26ac;
	case 9907ULL: goto x86_l_26b3;
	case 9911ULL: goto x86_l_26b7;
	case 9920ULL: goto x86_l_26c0;
	case 9926ULL: goto x86_l_26c6;
	case 9931ULL: goto x86_l_26cb;
	case 9935ULL: goto x86_l_26cf;
	case 9938ULL: goto x86_l_26d2;
	case 9943ULL: goto x86_l_26d7;
	case 9945ULL: goto x86_l_26d9;
	case 9947ULL: goto x86_l_26db;
	case 9953ULL: goto x86_l_26e1;
	case 9958ULL: goto x86_l_26e6;
	case 9963ULL: goto x86_l_26eb;
	case 9968ULL: goto x86_l_26f0;
	case 9973ULL: goto x86_l_26f5;
	case 9978ULL: goto x86_l_26fa;
	case 9983ULL: goto x86_l_26ff;
	case 9988ULL: goto x86_l_2704;
	case 9990ULL: goto x86_l_2706;
	case 9995ULL: goto x86_l_270b;
	case 10000ULL: goto x86_l_2710;
	case 10005ULL: goto x86_l_2715;
	case 10007ULL: goto x86_l_2717;
	case 10012ULL: goto x86_l_271c;
	case 10017ULL: goto x86_l_2721;
	case 10022ULL: goto x86_l_2726;
	case 10024ULL: goto x86_l_2728;
	case 10029ULL: goto x86_l_272d;
	case 10034ULL: goto x86_l_2732;
	case 10039ULL: goto x86_l_2737;
	case 10041ULL: goto x86_l_2739;
	case 10046ULL: goto x86_l_273e;
	case 10051ULL: goto x86_l_2743;
	case 10056ULL: goto x86_l_2748;
	case 10059ULL: goto x86_l_274b;
	case 10063ULL: goto x86_l_274f;
	case 10068ULL: goto x86_l_2754;
	case 10071ULL: goto x86_l_2757;
	case 10076ULL: goto x86_l_275c;
	case 10079ULL: goto x86_l_275f;
	case 10081ULL: goto x86_l_2761;
	case 10084ULL: goto x86_l_2764;
	case 10090ULL: goto x86_l_276a;
	case 10094ULL: goto x86_l_276e;
	case 10099ULL: goto x86_l_2773;
	case 10101ULL: goto x86_l_2775;
	case 10106ULL: goto x86_l_277a;
	case 10114ULL: goto x86_l_2782;
	case 10119ULL: goto x86_l_2787;
	case 10126ULL: goto x86_l_278e;
	case 10131ULL: goto x86_l_2793;
	case 10133ULL: goto x86_l_2795;
	case 10136ULL: goto x86_l_2798;
	case 10142ULL: goto x86_l_279e;
	case 10148ULL: goto x86_l_27a4;
	case 10155ULL: goto x86_l_27ab;
	case 10160ULL: goto x86_l_27b0;
	case 10163ULL: goto x86_l_27b3;
	case 10166ULL: goto x86_l_27b6;
	case 10169ULL: goto x86_l_27b9;
	case 10171ULL: goto x86_l_27bb;
	case 10174ULL: goto x86_l_27be;
	case 10179ULL: goto x86_l_27c3;
	case 10181ULL: goto x86_l_27c5;
	case 10186ULL: goto x86_l_27ca;
	case 10189ULL: goto x86_l_27cd;
	case 10192ULL: goto x86_l_27d0;
	case 10198ULL: goto x86_l_27d6;
	case 10202ULL: goto x86_l_27da;
	case 10207ULL: goto x86_l_27df;
	case 10209ULL: goto x86_l_27e1;
	case 10214ULL: goto x86_l_27e6;
	case 10222ULL: goto x86_l_27ee;
	case 10227ULL: goto x86_l_27f3;
	case 10234ULL: goto x86_l_27fa;
	case 10239ULL: goto x86_l_27ff;
	case 10241ULL: goto x86_l_2801;
	case 10244ULL: goto x86_l_2804;
	case 10246ULL: goto x86_l_2806;
	case 10252ULL: goto x86_l_280c;
	case 10259ULL: goto x86_l_2813;
	case 10264ULL: goto x86_l_2818;
	case 10267ULL: goto x86_l_281b;
	case 10270ULL: goto x86_l_281e;
	case 10273ULL: goto x86_l_2821;
	case 10275ULL: goto x86_l_2823;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2136:
	/* 0x2136: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2138:
	/* 0x2138: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_213a:
	/* 0x213a: jns    274b <generic_sleepable_preload+0x274b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_274b;
	}
x86_l_2140:
	/* 0x2140: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_2145:
	/* 0x2145: jmp    2748 <generic_sleepable_preload+0x2748> */
	goto x86_l_2748;
x86_l_214a:
	/* 0x214a: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_214f:
	/* 0x214f: jmp    2748 <generic_sleepable_preload+0x2748> */
	goto x86_l_2748;
x86_l_2154:
	/* 0x2154: mov    rsi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_215c:
	/* 0x215c: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_215f:
	/* 0x215f: je     21c4 <generic_sleepable_preload+0x21c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21c4;
	}
x86_l_2161:
	/* 0x2161: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2166:
	/* 0x2166: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_2169:
	/* 0x2169: je     21c4 <generic_sleepable_preload+0x21c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21c4;
	}
x86_l_216b:
	/* 0x216b: jmp    21d7 <generic_sleepable_preload+0x21d7> */
	goto x86_l_21d7;
x86_l_216d:
	/* 0x216d: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2175:
	/* 0x2175: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2178:
	/* 0x2178: je     21c4 <generic_sleepable_preload+0x21c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21c4;
	}
x86_l_217a:
	/* 0x217a: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_217f:
	/* 0x217f: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_2182:
	/* 0x2182: je     21c4 <generic_sleepable_preload+0x21c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21c4;
	}
x86_l_2184:
	/* 0x2184: jmp    21d7 <generic_sleepable_preload+0x21d7> */
	goto x86_l_21d7;
x86_l_2186:
	/* 0x2186: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_218e:
	/* 0x218e: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_2191:
	/* 0x2191: je     21c4 <generic_sleepable_preload+0x21c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21c4;
	}
x86_l_2193:
	/* 0x2193: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2198:
	/* 0x2198: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_219b:
	/* 0x219b: je     21c4 <generic_sleepable_preload+0x21c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21c4;
	}
x86_l_219d:
	/* 0x219d: jmp    21d7 <generic_sleepable_preload+0x21d7> */
	goto x86_l_21d7;
x86_l_219f:
	/* 0x219f: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_21a4:
	/* 0x21a4: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_21a7:
	/* 0x21a7: je     21c4 <generic_sleepable_preload+0x21c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21c4;
	}
x86_l_21a9:
	/* 0x21a9: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21ae:
	/* 0x21ae: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_21b1:
	/* 0x21b1: je     21c4 <generic_sleepable_preload+0x21c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21c4;
	}
x86_l_21b3:
	/* 0x21b3: jmp    21d7 <generic_sleepable_preload+0x21d7> */
	goto x86_l_21d7;
x86_l_21b5:
	/* 0x21b5: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_21ba:
	/* 0x21ba: jmp    2748 <generic_sleepable_preload+0x2748> */
	goto x86_l_2748;
x86_l_21bf:
	/* 0x21bf: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_21c4:
	/* 0x21c4: shl    cl,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_21c7:
	/* 0x21c7: mov    al,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 64ULL);
x86_l_21c9:
	/* 0x21c9: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_21cb:
	/* 0x21cb: mov    ecx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 64ULL);
x86_l_21d0:
	/* 0x21d0: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_21d2:
	/* 0x21d2: bzhi   rax,QWORD PTR [rsi],rcx */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RAX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), 0ULL);
x86_l_21d7:
	/* 0x21d7: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21db:
	/* 0x21db: mov    ebx,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21df:
	/* 0x21df: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_21e1:
	/* 0x21e1: mov    r14b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_8, 1ULL);
x86_l_21e4:
	/* 0x21e4: cmp    WORD PTR [r13+0xc6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 850403524608ULL);
x86_l_21ed:
	/* 0x21ed: je     27cd <generic_sleepable_preload+0x27cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27cd;
	}
x86_l_21f3:
	/* 0x21f3: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_21fa:
	/* 0x21fa: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_21fd:
	/* 0x21fd: mov    edx,DWORD PTR [r13+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2204:
	/* 0x2204: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2207:
	/* 0x2207: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_220b:
	/* 0x220b: movzx  eax,WORD PTR [r13+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 196ULL);
x86_l_2213:
	/* 0x2213: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_2215:
	/* 0x2215: je     2473 <generic_sleepable_preload+0x2473> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2473;
	}
x86_l_221b:
	/* 0x221b: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_221e:
	/* 0x221e: je     223b <generic_sleepable_preload+0x223b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_223b;
	}
x86_l_2220:
	/* 0x2220: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2225:
	/* 0x2225: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2229:
	/* 0x2229: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_222c:
	/* 0x222c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2231:
	/* 0x2231: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2233:
	/* 0x2233: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2235:
	/* 0x2235: js     26eb <generic_sleepable_preload+0x26eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_26eb;
	}
x86_l_223b:
	/* 0x223b: cmp    WORD PTR [r13+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_2244:
	/* 0x2244: je     27cd <generic_sleepable_preload+0x27cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27cd;
	}
x86_l_224a:
	/* 0x224a: mov    eax,DWORD PTR [r13+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2251:
	/* 0x2251: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2255:
	/* 0x2255: cmp    WORD PTR [r13+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_225e:
	/* 0x225e: je     227b <generic_sleepable_preload+0x227b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_227b;
	}
x86_l_2260:
	/* 0x2260: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2265:
	/* 0x2265: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2269:
	/* 0x2269: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_226c:
	/* 0x226c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2271:
	/* 0x2271: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2273:
	/* 0x2273: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2275:
	/* 0x2275: js     26f5 <generic_sleepable_preload+0x26f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_26f5;
	}
x86_l_227b:
	/* 0x227b: cmp    WORD PTR [r13+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_2284:
	/* 0x2284: je     27cd <generic_sleepable_preload+0x27cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27cd;
	}
x86_l_228a:
	/* 0x228a: mov    eax,DWORD PTR [r13+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_2291:
	/* 0x2291: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2295:
	/* 0x2295: cmp    WORD PTR [r13+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_229e:
	/* 0x229e: je     22bb <generic_sleepable_preload+0x22bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22bb;
	}
x86_l_22a0:
	/* 0x22a0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_22a5:
	/* 0x22a5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22a9:
	/* 0x22a9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_22ac:
	/* 0x22ac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22b1:
	/* 0x22b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22b3:
	/* 0x22b3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_22b5:
	/* 0x22b5: js     2706 <generic_sleepable_preload+0x2706> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2706;
	}
x86_l_22bb:
	/* 0x22bb: cmp    WORD PTR [r13+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_22c4:
	/* 0x22c4: je     27cd <generic_sleepable_preload+0x27cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27cd;
	}
x86_l_22ca:
	/* 0x22ca: mov    eax,DWORD PTR [r13+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_22d1:
	/* 0x22d1: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_22d5:
	/* 0x22d5: cmp    WORD PTR [r13+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_22de:
	/* 0x22de: je     22fb <generic_sleepable_preload+0x22fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22fb;
	}
x86_l_22e0:
	/* 0x22e0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_22e5:
	/* 0x22e5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22e9:
	/* 0x22e9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_22ec:
	/* 0x22ec: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22f1:
	/* 0x22f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22f3:
	/* 0x22f3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_22f5:
	/* 0x22f5: js     2717 <generic_sleepable_preload+0x2717> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2717;
	}
x86_l_22fb:
	/* 0x22fb: cmp    WORD PTR [r13+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_2304:
	/* 0x2304: je     27cd <generic_sleepable_preload+0x27cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27cd;
	}
x86_l_230a:
	/* 0x230a: mov    eax,DWORD PTR [r13+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_2311:
	/* 0x2311: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2315:
	/* 0x2315: cmp    WORD PTR [r13+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_231e:
	/* 0x231e: je     233b <generic_sleepable_preload+0x233b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_233b;
	}
x86_l_2320:
	/* 0x2320: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2325:
	/* 0x2325: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2329:
	/* 0x2329: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_232c:
	/* 0x232c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2331:
	/* 0x2331: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2333:
	/* 0x2333: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2335:
	/* 0x2335: js     2728 <generic_sleepable_preload+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2728;
	}
x86_l_233b:
	/* 0x233b: cmp    WORD PTR [r13+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_2344:
	/* 0x2344: je     27cd <generic_sleepable_preload+0x27cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27cd;
	}
x86_l_234a:
	/* 0x234a: mov    eax,DWORD PTR [r13+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_2351:
	/* 0x2351: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2355:
	/* 0x2355: cmp    WORD PTR [r13+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_235e:
	/* 0x235e: je     237b <generic_sleepable_preload+0x237b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_237b;
	}
x86_l_2360:
	/* 0x2360: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2365:
	/* 0x2365: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2369:
	/* 0x2369: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_236c:
	/* 0x236c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2371:
	/* 0x2371: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2373:
	/* 0x2373: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2375:
	/* 0x2375: js     2739 <generic_sleepable_preload+0x2739> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2739;
	}
x86_l_237b:
	/* 0x237b: cmp    WORD PTR [r13+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_2384:
	/* 0x2384: je     27cd <generic_sleepable_preload+0x27cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27cd;
	}
x86_l_238a:
	/* 0x238a: mov    eax,DWORD PTR [r13+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_2391:
	/* 0x2391: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2395:
	/* 0x2395: cmp    WORD PTR [r13+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_239e:
	/* 0x239e: je     23bb <generic_sleepable_preload+0x23bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23bb;
	}
x86_l_23a0:
	/* 0x23a0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_23a5:
	/* 0x23a5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23a9:
	/* 0x23a9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_23ac:
	/* 0x23ac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23b1:
	/* 0x23b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23b3:
	/* 0x23b3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_23b5:
	/* 0x23b5: js     27c5 <generic_sleepable_preload+0x27c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_27c5;
	}
x86_l_23bb:
	/* 0x23bb: cmp    WORD PTR [r13+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_23c4:
	/* 0x23c4: je     27cd <generic_sleepable_preload+0x27cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27cd;
	}
x86_l_23ca:
	/* 0x23ca: mov    eax,DWORD PTR [r13+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_23d1:
	/* 0x23d1: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_23d5:
	/* 0x23d5: cmp    WORD PTR [r13+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_23de:
	/* 0x23de: je     23fb <generic_sleepable_preload+0x23fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23fb;
	}
x86_l_23e0:
	/* 0x23e0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_23e5:
	/* 0x23e5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23e9:
	/* 0x23e9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_23ec:
	/* 0x23ec: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23f1:
	/* 0x23f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23f3:
	/* 0x23f3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_23f5:
	/* 0x23f5: js     5207 <generic_sleepable_preload+0x5207> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20999ULL;
	}
x86_l_23fb:
	/* 0x23fb: cmp    WORD PTR [r13+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_2404:
	/* 0x2404: je     27cd <generic_sleepable_preload+0x27cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27cd;
	}
x86_l_240a:
	/* 0x240a: mov    eax,DWORD PTR [r13+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_2411:
	/* 0x2411: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2415:
	/* 0x2415: cmp    WORD PTR [r13+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_241e:
	/* 0x241e: je     243b <generic_sleepable_preload+0x243b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_243b;
	}
x86_l_2420:
	/* 0x2420: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2425:
	/* 0x2425: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2429:
	/* 0x2429: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_242c:
	/* 0x242c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2431:
	/* 0x2431: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2433:
	/* 0x2433: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2435:
	/* 0x2435: js     527e <generic_sleepable_preload+0x527e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21118ULL;
	}
x86_l_243b:
	/* 0x243b: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2440:
	/* 0x2440: cmp    WORD PTR [r13+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_2449:
	/* 0x2449: je     27cd <generic_sleepable_preload+0x27cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27cd;
	}
x86_l_244f:
	/* 0x244f: mov    eax,DWORD PTR [r13+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_2456:
	/* 0x2456: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_245a:
	/* 0x245a: cmp    WORD PTR [r13+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_2463:
	/* 0x2463: je     27cd <generic_sleepable_preload+0x27cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27cd;
	}
x86_l_2469:
	/* 0x2469: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_246e:
	/* 0x246e: jmp    26cb <generic_sleepable_preload+0x26cb> */
	goto x86_l_26cb;
x86_l_2473:
	/* 0x2473: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_2476:
	/* 0x2476: je     2493 <generic_sleepable_preload+0x2493> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2493;
	}
x86_l_2478:
	/* 0x2478: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_247d:
	/* 0x247d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2481:
	/* 0x2481: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2484:
	/* 0x2484: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2489:
	/* 0x2489: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_248b:
	/* 0x248b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_248d:
	/* 0x248d: js     26eb <generic_sleepable_preload+0x26eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_26eb;
	}
x86_l_2493:
	/* 0x2493: cmp    WORD PTR [r13+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_249c:
	/* 0x249c: je     27cd <generic_sleepable_preload+0x27cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27cd;
	}
x86_l_24a2:
	/* 0x24a2: mov    eax,DWORD PTR [r13+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_24a9:
	/* 0x24a9: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_24ad:
	/* 0x24ad: cmp    WORD PTR [r13+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_24b6:
	/* 0x24b6: je     24d3 <generic_sleepable_preload+0x24d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24d3;
	}
x86_l_24b8:
	/* 0x24b8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_24bd:
	/* 0x24bd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24c1:
	/* 0x24c1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_24c4:
	/* 0x24c4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24c9:
	/* 0x24c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24cb:
	/* 0x24cb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24cd:
	/* 0x24cd: js     26f5 <generic_sleepable_preload+0x26f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_26f5;
	}
x86_l_24d3:
	/* 0x24d3: cmp    WORD PTR [r13+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_24dc:
	/* 0x24dc: je     27cd <generic_sleepable_preload+0x27cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27cd;
	}
x86_l_24e2:
	/* 0x24e2: mov    eax,DWORD PTR [r13+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_24e9:
	/* 0x24e9: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_24ed:
	/* 0x24ed: cmp    WORD PTR [r13+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_24f6:
	/* 0x24f6: je     2513 <generic_sleepable_preload+0x2513> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2513;
	}
x86_l_24f8:
	/* 0x24f8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_24fd:
	/* 0x24fd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2501:
	/* 0x2501: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2504:
	/* 0x2504: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2509:
	/* 0x2509: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_250b:
	/* 0x250b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_250d:
	/* 0x250d: js     2706 <generic_sleepable_preload+0x2706> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2706;
	}
x86_l_2513:
	/* 0x2513: cmp    WORD PTR [r13+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_251c:
	/* 0x251c: je     27cd <generic_sleepable_preload+0x27cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27cd;
	}
x86_l_2522:
	/* 0x2522: mov    eax,DWORD PTR [r13+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_2529:
	/* 0x2529: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_252d:
	/* 0x252d: cmp    WORD PTR [r13+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_2536:
	/* 0x2536: je     2553 <generic_sleepable_preload+0x2553> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2553;
	}
x86_l_2538:
	/* 0x2538: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_253d:
	/* 0x253d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2541:
	/* 0x2541: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2544:
	/* 0x2544: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2549:
	/* 0x2549: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_254b:
	/* 0x254b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_254d:
	/* 0x254d: js     2717 <generic_sleepable_preload+0x2717> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2717;
	}
x86_l_2553:
	/* 0x2553: cmp    WORD PTR [r13+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_255c:
	/* 0x255c: je     27cd <generic_sleepable_preload+0x27cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27cd;
	}
x86_l_2562:
	/* 0x2562: mov    eax,DWORD PTR [r13+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_2569:
	/* 0x2569: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_256d:
	/* 0x256d: cmp    WORD PTR [r13+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_2576:
	/* 0x2576: je     2593 <generic_sleepable_preload+0x2593> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2593;
	}
x86_l_2578:
	/* 0x2578: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_257d:
	/* 0x257d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2581:
	/* 0x2581: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2584:
	/* 0x2584: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2589:
	/* 0x2589: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_258b:
	/* 0x258b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_258d:
	/* 0x258d: js     2728 <generic_sleepable_preload+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2728;
	}
x86_l_2593:
	/* 0x2593: cmp    WORD PTR [r13+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_259c:
	/* 0x259c: je     27cd <generic_sleepable_preload+0x27cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27cd;
	}
x86_l_25a2:
	/* 0x25a2: mov    eax,DWORD PTR [r13+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_25a9:
	/* 0x25a9: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_25ad:
	/* 0x25ad: cmp    WORD PTR [r13+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_25b6:
	/* 0x25b6: je     25d3 <generic_sleepable_preload+0x25d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25d3;
	}
x86_l_25b8:
	/* 0x25b8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_25bd:
	/* 0x25bd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25c1:
	/* 0x25c1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_25c4:
	/* 0x25c4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_25c9:
	/* 0x25c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25cb:
	/* 0x25cb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_25cd:
	/* 0x25cd: js     2739 <generic_sleepable_preload+0x2739> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2739;
	}
x86_l_25d3:
	/* 0x25d3: cmp    WORD PTR [r13+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_25dc:
	/* 0x25dc: je     27cd <generic_sleepable_preload+0x27cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27cd;
	}
x86_l_25e2:
	/* 0x25e2: mov    eax,DWORD PTR [r13+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_25e9:
	/* 0x25e9: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_25ed:
	/* 0x25ed: cmp    WORD PTR [r13+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_25f6:
	/* 0x25f6: je     2613 <generic_sleepable_preload+0x2613> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2613;
	}
x86_l_25f8:
	/* 0x25f8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_25fd:
	/* 0x25fd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2601:
	/* 0x2601: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2604:
	/* 0x2604: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2609:
	/* 0x2609: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_260b:
	/* 0x260b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_260d:
	/* 0x260d: js     27c5 <generic_sleepable_preload+0x27c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_27c5;
	}
x86_l_2613:
	/* 0x2613: cmp    WORD PTR [r13+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_261c:
	/* 0x261c: je     27cd <generic_sleepable_preload+0x27cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27cd;
	}
x86_l_2622:
	/* 0x2622: mov    eax,DWORD PTR [r13+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_2629:
	/* 0x2629: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_262d:
	/* 0x262d: cmp    WORD PTR [r13+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_2636:
	/* 0x2636: je     2653 <generic_sleepable_preload+0x2653> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2653;
	}
x86_l_2638:
	/* 0x2638: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_263d:
	/* 0x263d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2641:
	/* 0x2641: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2644:
	/* 0x2644: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2649:
	/* 0x2649: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_264b:
	/* 0x264b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_264d:
	/* 0x264d: js     5322 <generic_sleepable_preload+0x5322> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21282ULL;
	}
x86_l_2653:
	/* 0x2653: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2658:
	/* 0x2658: cmp    WORD PTR [r13+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_2661:
	/* 0x2661: je     27cd <generic_sleepable_preload+0x27cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27cd;
	}
x86_l_2667:
	/* 0x2667: mov    eax,DWORD PTR [r13+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_266e:
	/* 0x266e: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2672:
	/* 0x2672: cmp    WORD PTR [r13+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_267b:
	/* 0x267b: je     2698 <generic_sleepable_preload+0x2698> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2698;
	}
x86_l_267d:
	/* 0x267d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2682:
	/* 0x2682: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2686:
	/* 0x2686: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2689:
	/* 0x2689: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_268e:
	/* 0x268e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2690:
	/* 0x2690: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2692:
	/* 0x2692: js     527e <generic_sleepable_preload+0x527e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21118ULL;
	}
x86_l_2698:
	/* 0x2698: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_269d:
	/* 0x269d: cmp    WORD PTR [r13+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_26a6:
	/* 0x26a6: je     27cd <generic_sleepable_preload+0x27cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27cd;
	}
x86_l_26ac:
	/* 0x26ac: mov    eax,DWORD PTR [r13+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_26b3:
	/* 0x26b3: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_26b7:
	/* 0x26b7: cmp    WORD PTR [r13+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_26c0:
	/* 0x26c0: je     27cd <generic_sleepable_preload+0x27cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27cd;
	}
x86_l_26c6:
	/* 0x26c6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_26cb:
	/* 0x26cb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26cf:
	/* 0x26cf: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_26d2:
	/* 0x26d2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26d7:
	/* 0x26d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26d9:
	/* 0x26d9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_26db:
	/* 0x26db: jns    27cd <generic_sleepable_preload+0x27cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_27cd;
	}
x86_l_26e1:
	/* 0x26e1: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_26e6:
	/* 0x26e6: jmp    27ca <generic_sleepable_preload+0x27ca> */
	goto x86_l_27ca;
x86_l_26eb:
	/* 0x26eb: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_26f0:
	/* 0x26f0: jmp    27ca <generic_sleepable_preload+0x27ca> */
	goto x86_l_27ca;
x86_l_26f5:
	/* 0x26f5: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_26fa:
	/* 0x26fa: jmp    27ca <generic_sleepable_preload+0x27ca> */
	goto x86_l_27ca;
x86_l_26ff:
	/* 0x26ff: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_2704:
	/* 0x2704: jmp    2748 <generic_sleepable_preload+0x2748> */
	goto x86_l_2748;
x86_l_2706:
	/* 0x2706: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_270b:
	/* 0x270b: jmp    27ca <generic_sleepable_preload+0x27ca> */
	goto x86_l_27ca;
x86_l_2710:
	/* 0x2710: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_2715:
	/* 0x2715: jmp    2748 <generic_sleepable_preload+0x2748> */
	goto x86_l_2748;
x86_l_2717:
	/* 0x2717: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_271c:
	/* 0x271c: jmp    27ca <generic_sleepable_preload+0x27ca> */
	goto x86_l_27ca;
x86_l_2721:
	/* 0x2721: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_2726:
	/* 0x2726: jmp    2748 <generic_sleepable_preload+0x2748> */
	goto x86_l_2748;
x86_l_2728:
	/* 0x2728: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_272d:
	/* 0x272d: jmp    27ca <generic_sleepable_preload+0x27ca> */
	goto x86_l_27ca;
x86_l_2732:
	/* 0x2732: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_2737:
	/* 0x2737: jmp    2748 <generic_sleepable_preload+0x2748> */
	goto x86_l_2748;
x86_l_2739:
	/* 0x2739: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_273e:
	/* 0x273e: jmp    27ca <generic_sleepable_preload+0x27ca> */
	goto x86_l_27ca;
x86_l_2743:
	/* 0x2743: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_2748:
	/* 0x2748: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_274b:
	/* 0x274b: mov    ebx,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_274f:
	/* 0x274f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2754:
	/* 0x2754: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2757:
	/* 0x2757: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_275c:
	/* 0x275c: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_275f:
	/* 0x275f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2761:
	/* 0x2761: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_2764:
	/* 0x2764: jne    286c <generic_sleepable_preload+0x286c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10348ULL;
	}
x86_l_276a:
	/* 0x276a: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_276e:
	/* 0x276e: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2773:
	/* 0x2773: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2775:
	/* 0x2775: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_277a:
	/* 0x277a: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_2782:
	/* 0x2782: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2787:
	/* 0x2787: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_278e:
	/* 0x278e: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2793:
	/* 0x2793: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2795:
	/* 0x2795: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2798:
	/* 0x2798: je     286c <generic_sleepable_preload+0x286c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10348ULL;
	}
x86_l_279e:
	/* 0x279e: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_27a4:
	/* 0x27a4: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_27ab:
	/* 0x27ab: lea    r13,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_27b0:
	/* 0x27b0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_27b3:
	/* 0x27b3: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_27b6:
	/* 0x27b6: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_27b9:
	/* 0x27b9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_27bb:
	/* 0x27bb: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_27be:
	/* 0x27be: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_27c3:
	/* 0x27c3: jmp    282b <generic_sleepable_preload+0x282b> */
	return 10283ULL;
x86_l_27c5:
	/* 0x27c5: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_27ca:
	/* 0x27ca: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_27cd:
	/* 0x27cd: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_27d0:
	/* 0x27d0: jne    286c <generic_sleepable_preload+0x286c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10348ULL;
	}
x86_l_27d6:
	/* 0x27d6: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27da:
	/* 0x27da: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_27df:
	/* 0x27df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27e1:
	/* 0x27e1: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_27e6:
	/* 0x27e6: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_27ee:
	/* 0x27ee: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_27f3:
	/* 0x27f3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_27fa:
	/* 0x27fa: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_27ff:
	/* 0x27ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2801:
	/* 0x2801: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2804:
	/* 0x2804: je     286c <generic_sleepable_preload+0x286c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10348ULL;
	}
x86_l_2806:
	/* 0x2806: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_280c:
	/* 0x280c: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_2813:
	/* 0x2813: lea    r13,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2818:
	/* 0x2818: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_281b:
	/* 0x281b: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_281e:
	/* 0x281e: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2821:
	/* 0x2821: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2823:
	/* 0x2823: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
	return 10278ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10278ULL: goto x86_l_2826;
	case 10283ULL: goto x86_l_282b;
	case 10286ULL: goto x86_l_282e;
	case 10289ULL: goto x86_l_2831;
	case 10294ULL: goto x86_l_2836;
	case 10296ULL: goto x86_l_2838;
	case 10299ULL: goto x86_l_283b;
	case 10301ULL: goto x86_l_283d;
	case 10304ULL: goto x86_l_2840;
	case 10306ULL: goto x86_l_2842;
	case 10309ULL: goto x86_l_2845;
	case 10313ULL: goto x86_l_2849;
	case 10318ULL: goto x86_l_284e;
	case 10321ULL: goto x86_l_2851;
	case 10323ULL: goto x86_l_2853;
	case 10326ULL: goto x86_l_2856;
	case 10331ULL: goto x86_l_285b;
	case 10333ULL: goto x86_l_285d;
	case 10336ULL: goto x86_l_2860;
	case 10338ULL: goto x86_l_2862;
	case 10343ULL: goto x86_l_2867;
	case 10346ULL: goto x86_l_286a;
	case 10348ULL: goto x86_l_286c;
	case 10353ULL: goto x86_l_2871;
	case 10357ULL: goto x86_l_2875;
	case 10362ULL: goto x86_l_287a;
	case 10368ULL: goto x86_l_2880;
	case 10370ULL: goto x86_l_2882;
	case 10372ULL: goto x86_l_2884;
	case 10376ULL: goto x86_l_2888;
	case 10379ULL: goto x86_l_288b;
	case 10385ULL: goto x86_l_2891;
	case 10388ULL: goto x86_l_2894;
	case 10394ULL: goto x86_l_289a;
	case 10397ULL: goto x86_l_289d;
	case 10403ULL: goto x86_l_28a3;
	case 10406ULL: goto x86_l_28a6;
	case 10412ULL: goto x86_l_28ac;
	case 10417ULL: goto x86_l_28b1;
	case 10422ULL: goto x86_l_28b6;
	case 10430ULL: goto x86_l_28be;
	case 10438ULL: goto x86_l_28c6;
	case 10444ULL: goto x86_l_28cc;
	case 10446ULL: goto x86_l_28ce;
	case 10449ULL: goto x86_l_28d1;
	case 10451ULL: goto x86_l_28d3;
	case 10454ULL: goto x86_l_28d6;
	case 10456ULL: goto x86_l_28d8;
	case 10459ULL: goto x86_l_28db;
	case 10465ULL: goto x86_l_28e1;
	case 10470ULL: goto x86_l_28e6;
	case 10473ULL: goto x86_l_28e9;
	case 10479ULL: goto x86_l_28ef;
	case 10484ULL: goto x86_l_28f4;
	case 10487ULL: goto x86_l_28f7;
	case 10493ULL: goto x86_l_28fd;
	case 10498ULL: goto x86_l_2902;
	case 10501ULL: goto x86_l_2905;
	case 10507ULL: goto x86_l_290b;
	case 10512ULL: goto x86_l_2910;
	case 10515ULL: goto x86_l_2913;
	case 10517ULL: goto x86_l_2915;
	case 10520ULL: goto x86_l_2918;
	case 10526ULL: goto x86_l_291e;
	case 10528ULL: goto x86_l_2920;
	case 10534ULL: goto x86_l_2926;
	case 10537ULL: goto x86_l_2929;
	case 10540ULL: goto x86_l_292c;
	case 10546ULL: goto x86_l_2932;
	case 10551ULL: goto x86_l_2937;
	case 10553ULL: goto x86_l_2939;
	case 10555ULL: goto x86_l_293b;
	case 10558ULL: goto x86_l_293e;
	case 10560ULL: goto x86_l_2940;
	case 10565ULL: goto x86_l_2945;
	case 10567ULL: goto x86_l_2947;
	case 10570ULL: goto x86_l_294a;
	case 10576ULL: goto x86_l_2950;
	case 10584ULL: goto x86_l_2958;
	case 10587ULL: goto x86_l_295b;
	case 10593ULL: goto x86_l_2961;
	case 10598ULL: goto x86_l_2966;
	case 10601ULL: goto x86_l_2969;
	case 10607ULL: goto x86_l_296f;
	case 10612ULL: goto x86_l_2974;
	case 10615ULL: goto x86_l_2977;
	case 10621ULL: goto x86_l_297d;
	case 10629ULL: goto x86_l_2985;
	case 10632ULL: goto x86_l_2988;
	case 10638ULL: goto x86_l_298e;
	case 10643ULL: goto x86_l_2993;
	case 10646ULL: goto x86_l_2996;
	case 10652ULL: goto x86_l_299c;
	case 10657ULL: goto x86_l_29a1;
	case 10662ULL: goto x86_l_29a6;
	case 10664ULL: goto x86_l_29a8;
	case 10669ULL: goto x86_l_29ad;
	case 10671ULL: goto x86_l_29af;
	case 10676ULL: goto x86_l_29b4;
	case 10679ULL: goto x86_l_29b7;
	case 10683ULL: goto x86_l_29bb;
	case 10685ULL: goto x86_l_29bd;
	case 10688ULL: goto x86_l_29c0;
	case 10697ULL: goto x86_l_29c9;
	case 10703ULL: goto x86_l_29cf;
	case 10710ULL: goto x86_l_29d6;
	case 10713ULL: goto x86_l_29d9;
	case 10720ULL: goto x86_l_29e0;
	case 10723ULL: goto x86_l_29e3;
	case 10727ULL: goto x86_l_29e7;
	case 10735ULL: goto x86_l_29ef;
	case 10737ULL: goto x86_l_29f1;
	case 10743ULL: goto x86_l_29f7;
	case 10746ULL: goto x86_l_29fa;
	case 10748ULL: goto x86_l_29fc;
	case 10753ULL: goto x86_l_2a01;
	case 10757ULL: goto x86_l_2a05;
	case 10760ULL: goto x86_l_2a08;
	case 10765ULL: goto x86_l_2a0d;
	case 10767ULL: goto x86_l_2a0f;
	case 10769ULL: goto x86_l_2a11;
	case 10775ULL: goto x86_l_2a17;
	case 10784ULL: goto x86_l_2a20;
	case 10790ULL: goto x86_l_2a26;
	case 10797ULL: goto x86_l_2a2d;
	case 10801ULL: goto x86_l_2a31;
	case 10810ULL: goto x86_l_2a3a;
	case 10812ULL: goto x86_l_2a3c;
	case 10817ULL: goto x86_l_2a41;
	case 10821ULL: goto x86_l_2a45;
	case 10824ULL: goto x86_l_2a48;
	case 10829ULL: goto x86_l_2a4d;
	case 10831ULL: goto x86_l_2a4f;
	case 10833ULL: goto x86_l_2a51;
	case 10839ULL: goto x86_l_2a57;
	case 10848ULL: goto x86_l_2a60;
	case 10854ULL: goto x86_l_2a66;
	case 10861ULL: goto x86_l_2a6d;
	case 10865ULL: goto x86_l_2a71;
	case 10874ULL: goto x86_l_2a7a;
	case 10876ULL: goto x86_l_2a7c;
	case 10881ULL: goto x86_l_2a81;
	case 10885ULL: goto x86_l_2a85;
	case 10888ULL: goto x86_l_2a88;
	case 10893ULL: goto x86_l_2a8d;
	case 10895ULL: goto x86_l_2a8f;
	case 10897ULL: goto x86_l_2a91;
	case 10903ULL: goto x86_l_2a97;
	case 10912ULL: goto x86_l_2aa0;
	case 10918ULL: goto x86_l_2aa6;
	case 10925ULL: goto x86_l_2aad;
	case 10929ULL: goto x86_l_2ab1;
	case 10938ULL: goto x86_l_2aba;
	case 10940ULL: goto x86_l_2abc;
	case 10945ULL: goto x86_l_2ac1;
	case 10949ULL: goto x86_l_2ac5;
	case 10952ULL: goto x86_l_2ac8;
	case 10957ULL: goto x86_l_2acd;
	case 10959ULL: goto x86_l_2acf;
	case 10961ULL: goto x86_l_2ad1;
	case 10967ULL: goto x86_l_2ad7;
	case 10976ULL: goto x86_l_2ae0;
	case 10982ULL: goto x86_l_2ae6;
	case 10989ULL: goto x86_l_2aed;
	case 10993ULL: goto x86_l_2af1;
	case 11002ULL: goto x86_l_2afa;
	case 11004ULL: goto x86_l_2afc;
	case 11009ULL: goto x86_l_2b01;
	case 11013ULL: goto x86_l_2b05;
	case 11016ULL: goto x86_l_2b08;
	case 11021ULL: goto x86_l_2b0d;
	case 11023ULL: goto x86_l_2b0f;
	case 11025ULL: goto x86_l_2b11;
	case 11031ULL: goto x86_l_2b17;
	case 11040ULL: goto x86_l_2b20;
	case 11046ULL: goto x86_l_2b26;
	case 11053ULL: goto x86_l_2b2d;
	case 11057ULL: goto x86_l_2b31;
	case 11066ULL: goto x86_l_2b3a;
	case 11068ULL: goto x86_l_2b3c;
	case 11073ULL: goto x86_l_2b41;
	case 11077ULL: goto x86_l_2b45;
	case 11080ULL: goto x86_l_2b48;
	case 11085ULL: goto x86_l_2b4d;
	case 11087ULL: goto x86_l_2b4f;
	case 11089ULL: goto x86_l_2b51;
	case 11095ULL: goto x86_l_2b57;
	case 11104ULL: goto x86_l_2b60;
	case 11110ULL: goto x86_l_2b66;
	case 11117ULL: goto x86_l_2b6d;
	case 11121ULL: goto x86_l_2b71;
	case 11130ULL: goto x86_l_2b7a;
	case 11132ULL: goto x86_l_2b7c;
	case 11137ULL: goto x86_l_2b81;
	case 11141ULL: goto x86_l_2b85;
	case 11144ULL: goto x86_l_2b88;
	case 11149ULL: goto x86_l_2b8d;
	case 11151ULL: goto x86_l_2b8f;
	case 11153ULL: goto x86_l_2b91;
	case 11159ULL: goto x86_l_2b97;
	case 11168ULL: goto x86_l_2ba0;
	case 11174ULL: goto x86_l_2ba6;
	case 11181ULL: goto x86_l_2bad;
	case 11185ULL: goto x86_l_2bb1;
	case 11194ULL: goto x86_l_2bba;
	case 11196ULL: goto x86_l_2bbc;
	case 11201ULL: goto x86_l_2bc1;
	case 11205ULL: goto x86_l_2bc5;
	case 11208ULL: goto x86_l_2bc8;
	case 11213ULL: goto x86_l_2bcd;
	case 11215ULL: goto x86_l_2bcf;
	case 11217ULL: goto x86_l_2bd1;
	case 11223ULL: goto x86_l_2bd7;
	case 11232ULL: goto x86_l_2be0;
	case 11238ULL: goto x86_l_2be6;
	case 11245ULL: goto x86_l_2bed;
	case 11249ULL: goto x86_l_2bf1;
	case 11258ULL: goto x86_l_2bfa;
	case 11260ULL: goto x86_l_2bfc;
	case 11265ULL: goto x86_l_2c01;
	case 11269ULL: goto x86_l_2c05;
	case 11272ULL: goto x86_l_2c08;
	case 11277ULL: goto x86_l_2c0d;
	case 11279ULL: goto x86_l_2c0f;
	case 11281ULL: goto x86_l_2c11;
	case 11287ULL: goto x86_l_2c17;
	case 11292ULL: goto x86_l_2c1c;
	case 11301ULL: goto x86_l_2c25;
	case 11307ULL: goto x86_l_2c2b;
	case 11314ULL: goto x86_l_2c32;
	case 11318ULL: goto x86_l_2c36;
	case 11327ULL: goto x86_l_2c3f;
	case 11333ULL: goto x86_l_2c45;
	case 11338ULL: goto x86_l_2c4a;
	case 11343ULL: goto x86_l_2c4f;
	case 11346ULL: goto x86_l_2c52;
	case 11348ULL: goto x86_l_2c54;
	case 11353ULL: goto x86_l_2c59;
	case 11357ULL: goto x86_l_2c5d;
	case 11360ULL: goto x86_l_2c60;
	case 11365ULL: goto x86_l_2c65;
	case 11367ULL: goto x86_l_2c67;
	case 11369ULL: goto x86_l_2c69;
	case 11375ULL: goto x86_l_2c6f;
	case 11384ULL: goto x86_l_2c78;
	case 11390ULL: goto x86_l_2c7e;
	case 11397ULL: goto x86_l_2c85;
	case 11401ULL: goto x86_l_2c89;
	case 11410ULL: goto x86_l_2c92;
	case 11412ULL: goto x86_l_2c94;
	case 11417ULL: goto x86_l_2c99;
	case 11421ULL: goto x86_l_2c9d;
	case 11424ULL: goto x86_l_2ca0;
	case 11429ULL: goto x86_l_2ca5;
	case 11431ULL: goto x86_l_2ca7;
	case 11433ULL: goto x86_l_2ca9;
	case 11439ULL: goto x86_l_2caf;
	case 11448ULL: goto x86_l_2cb8;
	case 11454ULL: goto x86_l_2cbe;
	case 11461ULL: goto x86_l_2cc5;
	case 11465ULL: goto x86_l_2cc9;
	case 11474ULL: goto x86_l_2cd2;
	case 11476ULL: goto x86_l_2cd4;
	case 11481ULL: goto x86_l_2cd9;
	case 11485ULL: goto x86_l_2cdd;
	case 11488ULL: goto x86_l_2ce0;
	case 11493ULL: goto x86_l_2ce5;
	case 11495ULL: goto x86_l_2ce7;
	case 11497ULL: goto x86_l_2ce9;
	case 11503ULL: goto x86_l_2cef;
	case 11512ULL: goto x86_l_2cf8;
	case 11518ULL: goto x86_l_2cfe;
	case 11525ULL: goto x86_l_2d05;
	case 11529ULL: goto x86_l_2d09;
	case 11538ULL: goto x86_l_2d12;
	case 11540ULL: goto x86_l_2d14;
	case 11545ULL: goto x86_l_2d19;
	case 11549ULL: goto x86_l_2d1d;
	case 11552ULL: goto x86_l_2d20;
	case 11557ULL: goto x86_l_2d25;
	case 11559ULL: goto x86_l_2d27;
	case 11561ULL: goto x86_l_2d29;
	case 11567ULL: goto x86_l_2d2f;
	case 11576ULL: goto x86_l_2d38;
	case 11582ULL: goto x86_l_2d3e;
	case 11589ULL: goto x86_l_2d45;
	case 11593ULL: goto x86_l_2d49;
	case 11602ULL: goto x86_l_2d52;
	case 11604ULL: goto x86_l_2d54;
	case 11609ULL: goto x86_l_2d59;
	case 11613ULL: goto x86_l_2d5d;
	case 11616ULL: goto x86_l_2d60;
	case 11621ULL: goto x86_l_2d65;
	case 11623ULL: goto x86_l_2d67;
	case 11625ULL: goto x86_l_2d69;
	case 11631ULL: goto x86_l_2d6f;
	case 11640ULL: goto x86_l_2d78;
	case 11646ULL: goto x86_l_2d7e;
	case 11653ULL: goto x86_l_2d85;
	case 11657ULL: goto x86_l_2d89;
	case 11666ULL: goto x86_l_2d92;
	case 11668ULL: goto x86_l_2d94;
	case 11673ULL: goto x86_l_2d99;
	case 11677ULL: goto x86_l_2d9d;
	case 11680ULL: goto x86_l_2da0;
	case 11685ULL: goto x86_l_2da5;
	case 11687ULL: goto x86_l_2da7;
	case 11689ULL: goto x86_l_2da9;
	case 11695ULL: goto x86_l_2daf;
	case 11704ULL: goto x86_l_2db8;
	case 11710ULL: goto x86_l_2dbe;
	case 11717ULL: goto x86_l_2dc5;
	case 11721ULL: goto x86_l_2dc9;
	case 11730ULL: goto x86_l_2dd2;
	case 11732ULL: goto x86_l_2dd4;
	case 11737ULL: goto x86_l_2dd9;
	case 11741ULL: goto x86_l_2ddd;
	case 11744ULL: goto x86_l_2de0;
	case 11749ULL: goto x86_l_2de5;
	case 11751ULL: goto x86_l_2de7;
	case 11753ULL: goto x86_l_2de9;
	case 11759ULL: goto x86_l_2def;
	case 11768ULL: goto x86_l_2df8;
	case 11774ULL: goto x86_l_2dfe;
	case 11781ULL: goto x86_l_2e05;
	case 11785ULL: goto x86_l_2e09;
	case 11794ULL: goto x86_l_2e12;
	case 11796ULL: goto x86_l_2e14;
	case 11801ULL: goto x86_l_2e19;
	case 11805ULL: goto x86_l_2e1d;
	case 11808ULL: goto x86_l_2e20;
	case 11813ULL: goto x86_l_2e25;
	case 11815ULL: goto x86_l_2e27;
	case 11817ULL: goto x86_l_2e29;
	case 11823ULL: goto x86_l_2e2f;
	case 11828ULL: goto x86_l_2e34;
	case 11837ULL: goto x86_l_2e3d;
	case 11843ULL: goto x86_l_2e43;
	case 11850ULL: goto x86_l_2e4a;
	case 11854ULL: goto x86_l_2e4e;
	case 11863ULL: goto x86_l_2e57;
	case 11865ULL: goto x86_l_2e59;
	case 11870ULL: goto x86_l_2e5e;
	case 11874ULL: goto x86_l_2e62;
	case 11877ULL: goto x86_l_2e65;
	case 11882ULL: goto x86_l_2e6a;
	case 11884ULL: goto x86_l_2e6c;
	case 11886ULL: goto x86_l_2e6e;
	case 11892ULL: goto x86_l_2e74;
	case 11897ULL: goto x86_l_2e79;
	case 11906ULL: goto x86_l_2e82;
	case 11912ULL: goto x86_l_2e88;
	case 11919ULL: goto x86_l_2e8f;
	case 11923ULL: goto x86_l_2e93;
	case 11932ULL: goto x86_l_2e9c;
	case 11938ULL: goto x86_l_2ea2;
	case 11943ULL: goto x86_l_2ea7;
	case 11947ULL: goto x86_l_2eab;
	case 11950ULL: goto x86_l_2eae;
	case 11955ULL: goto x86_l_2eb3;
	case 11957ULL: goto x86_l_2eb5;
	case 11959ULL: goto x86_l_2eb7;
	case 11965ULL: goto x86_l_2ebd;
	case 11970ULL: goto x86_l_2ec2;
	case 11975ULL: goto x86_l_2ec7;
	case 11980ULL: goto x86_l_2ecc;
	case 11985ULL: goto x86_l_2ed1;
	case 11993ULL: goto x86_l_2ed9;
	case 11996ULL: goto x86_l_2edc;
	case 11998ULL: goto x86_l_2ede;
	case 12003ULL: goto x86_l_2ee3;
	case 12006ULL: goto x86_l_2ee6;
	case 12008ULL: goto x86_l_2ee8;
	case 12010ULL: goto x86_l_2eea;
	case 12018ULL: goto x86_l_2ef2;
	case 12021ULL: goto x86_l_2ef5;
	case 12023ULL: goto x86_l_2ef7;
	case 12028ULL: goto x86_l_2efc;
	case 12031ULL: goto x86_l_2eff;
	case 12033ULL: goto x86_l_2f01;
	case 12035ULL: goto x86_l_2f03;
	case 12043ULL: goto x86_l_2f0b;
	case 12046ULL: goto x86_l_2f0e;
	case 12048ULL: goto x86_l_2f10;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2826:
	/* 0x2826: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_282b:
	/* 0x282b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_282e:
	/* 0x282e: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_2831:
	/* 0x2831: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2836:
	/* 0x2836: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2838:
	/* 0x2838: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_283b:
	/* 0x283b: je     286c <generic_sleepable_preload+0x286c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_286c;
	}
x86_l_283d:
	/* 0x283d: test   r14b,r14b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_8);
x86_l_2840:
	/* 0x2840: je     286a <generic_sleepable_preload+0x286a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_286a;
	}
x86_l_2842:
	/* 0x2842: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2845:
	/* 0x2845: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2849:
	/* 0x2849: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_284e:
	/* 0x284e: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2851:
	/* 0x2851: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2853:
	/* 0x2853: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_2856:
	/* 0x2856: call   285b <generic_sleepable_preload+0x285b> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_285b:
	/* 0x285b: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_285d:
	/* 0x285d: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_2860:
	/* 0x2860: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2862:
	/* 0x2862: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_2867:
	/* 0x2867: cmovs  ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_286a:
	/* 0x286a: mov    DWORD PTR [rax],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_286c:
	/* 0x286c: mov    rdi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2871:
	/* 0x2871: mov    eax,DWORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2875:
	/* 0x2875: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_287a:
	/* 0x287a: je     35e9 <generic_sleepable_preload+0x35e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13801ULL;
	}
x86_l_2880:
	/* 0x2880: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_2882:
	/* 0x2882: js     28b6 <generic_sleepable_preload+0x28b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_28b6;
	}
x86_l_2884:
	/* 0x2884: mov    ecx,DWORD PTR [r13+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2888:
	/* 0x2888: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_288b:
	/* 0x288b: jle    2937 <generic_sleepable_preload+0x2937> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2937;
	}
x86_l_2891:
	/* 0x2891: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2894:
	/* 0x2894: je     29a1 <generic_sleepable_preload+0x29a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29a1;
	}
x86_l_289a:
	/* 0x289a: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_289d:
	/* 0x289d: je     29a8 <generic_sleepable_preload+0x29a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29a8;
	}
x86_l_28a3:
	/* 0x28a3: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_28a6:
	/* 0x28a6: jne    29bb <generic_sleepable_preload+0x29bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_29bb;
	}
x86_l_28ac:
	/* 0x28ac: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_28b1:
	/* 0x28b1: jmp    29b4 <generic_sleepable_preload+0x29b4> */
	goto x86_l_29b4;
x86_l_28b6:
	/* 0x28b6: movzx  ecx,BYTE PTR [r13+0x2ca] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 714ULL);
x86_l_28be:
	/* 0x28be: movzx  eax,WORD PTR [r13+0x2c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 712ULL);
x86_l_28c6:
	/* 0x28c6: rorx   edx,eax,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 3ULL);
x86_l_28cc:
	/* 0x28cc: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_28ce:
	/* 0x28ce: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_28d1:
	/* 0x28d1: jle    2910 <generic_sleepable_preload+0x2910> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2910;
	}
x86_l_28d3:
	/* 0x28d3: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_28d6:
	/* 0x28d6: jle    2947 <generic_sleepable_preload+0x2947> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2947;
	}
x86_l_28d8:
	/* 0x28d8: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_28db:
	/* 0x28db: jle    2f1c <generic_sleepable_preload+0x2f1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 12060ULL;
	}
x86_l_28e1:
	/* 0x28e1: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_28e6:
	/* 0x28e6: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_28e9:
	/* 0x28e9: je     2f41 <generic_sleepable_preload+0x2f41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12097ULL;
	}
x86_l_28ef:
	/* 0x28ef: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_28f4:
	/* 0x28f4: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_28f7:
	/* 0x28f7: je     2f41 <generic_sleepable_preload+0x2f41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12097ULL;
	}
x86_l_28fd:
	/* 0x28fd: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2902:
	/* 0x2902: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_2905:
	/* 0x2905: je     2f41 <generic_sleepable_preload+0x2f41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12097ULL;
	}
x86_l_290b:
	/* 0x290b: jmp    2f54 <generic_sleepable_preload+0x2f54> */
	return 12116ULL;
x86_l_2910:
	/* 0x2910: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_2913:
	/* 0x2913: jg     2974 <generic_sleepable_preload+0x2974> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2974;
	}
x86_l_2915:
	/* 0x2915: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_2918:
	/* 0x2918: jg     2eea <generic_sleepable_preload+0x2eea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2eea;
	}
x86_l_291e:
	/* 0x291e: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_2920:
	/* 0x2920: je     2f3c <generic_sleepable_preload+0x2f3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12092ULL;
	}
x86_l_2926:
	/* 0x2926: mov    rsi,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDI, X86_WIDTH_64);
x86_l_2929:
	/* 0x2929: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_292c:
	/* 0x292c: je     2f41 <generic_sleepable_preload+0x2f41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12097ULL;
	}
x86_l_2932:
	/* 0x2932: jmp    2f54 <generic_sleepable_preload+0x2f54> */
	return 12116ULL;
x86_l_2937:
	/* 0x2937: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2939:
	/* 0x2939: je     29af <generic_sleepable_preload+0x29af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29af;
	}
x86_l_293b:
	/* 0x293b: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_293e:
	/* 0x293e: jne    29bb <generic_sleepable_preload+0x29bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_29bb;
	}
x86_l_2940:
	/* 0x2940: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2945:
	/* 0x2945: jmp    29b4 <generic_sleepable_preload+0x29b4> */
	goto x86_l_29b4;
x86_l_2947:
	/* 0x2947: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_294a:
	/* 0x294a: jg     2ed1 <generic_sleepable_preload+0x2ed1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2ed1;
	}
x86_l_2950:
	/* 0x2950: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2958:
	/* 0x2958: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_295b:
	/* 0x295b: je     2f41 <generic_sleepable_preload+0x2f41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12097ULL;
	}
x86_l_2961:
	/* 0x2961: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2966:
	/* 0x2966: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_2969:
	/* 0x2969: je     2f41 <generic_sleepable_preload+0x2f41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12097ULL;
	}
x86_l_296f:
	/* 0x296f: jmp    2f54 <generic_sleepable_preload+0x2f54> */
	return 12116ULL;
x86_l_2974:
	/* 0x2974: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_2977:
	/* 0x2977: jg     2f03 <generic_sleepable_preload+0x2f03> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2f03;
	}
x86_l_297d:
	/* 0x297d: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2985:
	/* 0x2985: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_2988:
	/* 0x2988: je     2f41 <generic_sleepable_preload+0x2f41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12097ULL;
	}
x86_l_298e:
	/* 0x298e: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2993:
	/* 0x2993: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_2996:
	/* 0x2996: je     2f41 <generic_sleepable_preload+0x2f41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12097ULL;
	}
x86_l_299c:
	/* 0x299c: jmp    2f54 <generic_sleepable_preload+0x2f54> */
	return 12116ULL;
x86_l_29a1:
	/* 0x29a1: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_29a6:
	/* 0x29a6: jmp    29b4 <generic_sleepable_preload+0x29b4> */
	goto x86_l_29b4;
x86_l_29a8:
	/* 0x29a8: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_29ad:
	/* 0x29ad: jmp    29b4 <generic_sleepable_preload+0x29b4> */
	goto x86_l_29b4;
x86_l_29af:
	/* 0x29af: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_29b4:
	/* 0x29b4: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29b7:
	/* 0x29b7: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29bb:
	/* 0x29bb: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_29bd:
	/* 0x29bd: mov    r14b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_8, 1ULL);
x86_l_29c0:
	/* 0x29c0: cmp    WORD PTR [r13+0x116],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1194000908288ULL);
x86_l_29c9:
	/* 0x29c9: je     34c8 <generic_sleepable_preload+0x34c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13512ULL;
	}
x86_l_29cf:
	/* 0x29cf: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_29d6:
	/* 0x29d6: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_29d9:
	/* 0x29d9: mov    edx,DWORD PTR [r13+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_29e0:
	/* 0x29e0: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_29e3:
	/* 0x29e3: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29e7:
	/* 0x29e7: movzx  eax,WORD PTR [r13+0x114] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 276ULL);
x86_l_29ef:
	/* 0x29ef: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_29f1:
	/* 0x29f1: je     2c4f <generic_sleepable_preload+0x2c4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c4f;
	}
x86_l_29f7:
	/* 0x29f7: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_29fa:
	/* 0x29fa: je     2a17 <generic_sleepable_preload+0x2a17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a17;
	}
x86_l_29fc:
	/* 0x29fc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2a01:
	/* 0x2a01: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a05:
	/* 0x2a05: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2a08:
	/* 0x2a08: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a0d:
	/* 0x2a0d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a0f:
	/* 0x2a0f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a11:
	/* 0x2a11: js     2ec7 <generic_sleepable_preload+0x2ec7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2ec7;
	}
x86_l_2a17:
	/* 0x2a17: cmp    WORD PTR [r13+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_2a20:
	/* 0x2a20: je     34c8 <generic_sleepable_preload+0x34c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13512ULL;
	}
x86_l_2a26:
	/* 0x2a26: mov    eax,DWORD PTR [r13+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_2a2d:
	/* 0x2a2d: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2a31:
	/* 0x2a31: cmp    WORD PTR [r13+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_2a3a:
	/* 0x2a3a: je     2a57 <generic_sleepable_preload+0x2a57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a57;
	}
x86_l_2a3c:
	/* 0x2a3c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2a41:
	/* 0x2a41: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a45:
	/* 0x2a45: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2a48:
	/* 0x2a48: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a4d:
	/* 0x2a4d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a4f:
	/* 0x2a4f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a51:
	/* 0x2a51: js     2f32 <generic_sleepable_preload+0x2f32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12082ULL;
	}
x86_l_2a57:
	/* 0x2a57: cmp    WORD PTR [r13+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_2a60:
	/* 0x2a60: je     34c8 <generic_sleepable_preload+0x34c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13512ULL;
	}
x86_l_2a66:
	/* 0x2a66: mov    eax,DWORD PTR [r13+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_2a6d:
	/* 0x2a6d: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2a71:
	/* 0x2a71: cmp    WORD PTR [r13+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_2a7a:
	/* 0x2a7a: je     2a97 <generic_sleepable_preload+0x2a97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a97;
	}
x86_l_2a7c:
	/* 0x2a7c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2a81:
	/* 0x2a81: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a85:
	/* 0x2a85: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2a88:
	/* 0x2a88: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a8d:
	/* 0x2a8d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a8f:
	/* 0x2a8f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a91:
	/* 0x2a91: js     347c <generic_sleepable_preload+0x347c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13436ULL;
	}
x86_l_2a97:
	/* 0x2a97: cmp    WORD PTR [r13+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_2aa0:
	/* 0x2aa0: je     34c8 <generic_sleepable_preload+0x34c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13512ULL;
	}
x86_l_2aa6:
	/* 0x2aa6: mov    eax,DWORD PTR [r13+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_2aad:
	/* 0x2aad: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2ab1:
	/* 0x2ab1: cmp    WORD PTR [r13+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_2aba:
	/* 0x2aba: je     2ad7 <generic_sleepable_preload+0x2ad7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ad7;
	}
x86_l_2abc:
	/* 0x2abc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2ac1:
	/* 0x2ac1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ac5:
	/* 0x2ac5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2ac8:
	/* 0x2ac8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2acd:
	/* 0x2acd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2acf:
	/* 0x2acf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ad1:
	/* 0x2ad1: js     348d <generic_sleepable_preload+0x348d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13453ULL;
	}
x86_l_2ad7:
	/* 0x2ad7: cmp    WORD PTR [r13+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_2ae0:
	/* 0x2ae0: je     34c8 <generic_sleepable_preload+0x34c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13512ULL;
	}
x86_l_2ae6:
	/* 0x2ae6: mov    eax,DWORD PTR [r13+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_2aed:
	/* 0x2aed: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2af1:
	/* 0x2af1: cmp    WORD PTR [r13+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_2afa:
	/* 0x2afa: je     2b17 <generic_sleepable_preload+0x2b17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b17;
	}
x86_l_2afc:
	/* 0x2afc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2b01:
	/* 0x2b01: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b05:
	/* 0x2b05: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2b08:
	/* 0x2b08: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b0d:
	/* 0x2b0d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b0f:
	/* 0x2b0f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b11:
	/* 0x2b11: js     349e <generic_sleepable_preload+0x349e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13470ULL;
	}
x86_l_2b17:
	/* 0x2b17: cmp    WORD PTR [r13+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_2b20:
	/* 0x2b20: je     34c8 <generic_sleepable_preload+0x34c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13512ULL;
	}
x86_l_2b26:
	/* 0x2b26: mov    eax,DWORD PTR [r13+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_2b2d:
	/* 0x2b2d: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2b31:
	/* 0x2b31: cmp    WORD PTR [r13+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_2b3a:
	/* 0x2b3a: je     2b57 <generic_sleepable_preload+0x2b57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b57;
	}
x86_l_2b3c:
	/* 0x2b3c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2b41:
	/* 0x2b41: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b45:
	/* 0x2b45: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2b48:
	/* 0x2b48: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b4d:
	/* 0x2b4d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b4f:
	/* 0x2b4f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b51:
	/* 0x2b51: js     34af <generic_sleepable_preload+0x34af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13487ULL;
	}
x86_l_2b57:
	/* 0x2b57: cmp    WORD PTR [r13+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_2b60:
	/* 0x2b60: je     34c8 <generic_sleepable_preload+0x34c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13512ULL;
	}
x86_l_2b66:
	/* 0x2b66: mov    eax,DWORD PTR [r13+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_2b6d:
	/* 0x2b6d: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2b71:
	/* 0x2b71: cmp    WORD PTR [r13+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_2b7a:
	/* 0x2b7a: je     2b97 <generic_sleepable_preload+0x2b97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b97;
	}
x86_l_2b7c:
	/* 0x2b7c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2b81:
	/* 0x2b81: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b85:
	/* 0x2b85: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2b88:
	/* 0x2b88: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b8d:
	/* 0x2b8d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b8f:
	/* 0x2b8f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b91:
	/* 0x2b91: js     34c0 <generic_sleepable_preload+0x34c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13504ULL;
	}
x86_l_2b97:
	/* 0x2b97: cmp    WORD PTR [r13+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_2ba0:
	/* 0x2ba0: je     34c8 <generic_sleepable_preload+0x34c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13512ULL;
	}
x86_l_2ba6:
	/* 0x2ba6: mov    eax,DWORD PTR [r13+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_2bad:
	/* 0x2bad: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2bb1:
	/* 0x2bb1: cmp    WORD PTR [r13+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_2bba:
	/* 0x2bba: je     2bd7 <generic_sleepable_preload+0x2bd7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bd7;
	}
x86_l_2bbc:
	/* 0x2bbc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2bc1:
	/* 0x2bc1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bc5:
	/* 0x2bc5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2bc8:
	/* 0x2bc8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2bcd:
	/* 0x2bcd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bcf:
	/* 0x2bcf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2bd1:
	/* 0x2bd1: js     5214 <generic_sleepable_preload+0x5214> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21012ULL;
	}
x86_l_2bd7:
	/* 0x2bd7: cmp    WORD PTR [r13+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_2be0:
	/* 0x2be0: je     34c8 <generic_sleepable_preload+0x34c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13512ULL;
	}
x86_l_2be6:
	/* 0x2be6: mov    eax,DWORD PTR [r13+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_2bed:
	/* 0x2bed: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2bf1:
	/* 0x2bf1: cmp    WORD PTR [r13+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_2bfa:
	/* 0x2bfa: je     2c17 <generic_sleepable_preload+0x2c17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c17;
	}
x86_l_2bfc:
	/* 0x2bfc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2c01:
	/* 0x2c01: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c05:
	/* 0x2c05: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2c08:
	/* 0x2c08: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c0d:
	/* 0x2c0d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c0f:
	/* 0x2c0f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c11:
	/* 0x2c11: js     5290 <generic_sleepable_preload+0x5290> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21136ULL;
	}
x86_l_2c17:
	/* 0x2c17: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c1c:
	/* 0x2c1c: cmp    WORD PTR [r13+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_2c25:
	/* 0x2c25: je     34c8 <generic_sleepable_preload+0x34c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13512ULL;
	}
x86_l_2c2b:
	/* 0x2c2b: mov    eax,DWORD PTR [r13+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_2c32:
	/* 0x2c32: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2c36:
	/* 0x2c36: cmp    WORD PTR [r13+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_2c3f:
	/* 0x2c3f: je     34c8 <generic_sleepable_preload+0x34c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13512ULL;
	}
x86_l_2c45:
	/* 0x2c45: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2c4a:
	/* 0x2c4a: jmp    2ea7 <generic_sleepable_preload+0x2ea7> */
	goto x86_l_2ea7;
x86_l_2c4f:
	/* 0x2c4f: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_2c52:
	/* 0x2c52: je     2c6f <generic_sleepable_preload+0x2c6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c6f;
	}
x86_l_2c54:
	/* 0x2c54: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2c59:
	/* 0x2c59: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c5d:
	/* 0x2c5d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2c60:
	/* 0x2c60: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c65:
	/* 0x2c65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c67:
	/* 0x2c67: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c69:
	/* 0x2c69: js     2ec7 <generic_sleepable_preload+0x2ec7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2ec7;
	}
x86_l_2c6f:
	/* 0x2c6f: cmp    WORD PTR [r13+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_2c78:
	/* 0x2c78: je     34c8 <generic_sleepable_preload+0x34c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13512ULL;
	}
x86_l_2c7e:
	/* 0x2c7e: mov    eax,DWORD PTR [r13+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_2c85:
	/* 0x2c85: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2c89:
	/* 0x2c89: cmp    WORD PTR [r13+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_2c92:
	/* 0x2c92: je     2caf <generic_sleepable_preload+0x2caf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2caf;
	}
x86_l_2c94:
	/* 0x2c94: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2c99:
	/* 0x2c99: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c9d:
	/* 0x2c9d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2ca0:
	/* 0x2ca0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ca5:
	/* 0x2ca5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ca7:
	/* 0x2ca7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ca9:
	/* 0x2ca9: js     2f32 <generic_sleepable_preload+0x2f32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12082ULL;
	}
x86_l_2caf:
	/* 0x2caf: cmp    WORD PTR [r13+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_2cb8:
	/* 0x2cb8: je     34c8 <generic_sleepable_preload+0x34c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13512ULL;
	}
x86_l_2cbe:
	/* 0x2cbe: mov    eax,DWORD PTR [r13+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_2cc5:
	/* 0x2cc5: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2cc9:
	/* 0x2cc9: cmp    WORD PTR [r13+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_2cd2:
	/* 0x2cd2: je     2cef <generic_sleepable_preload+0x2cef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cef;
	}
x86_l_2cd4:
	/* 0x2cd4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2cd9:
	/* 0x2cd9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cdd:
	/* 0x2cdd: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2ce0:
	/* 0x2ce0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ce5:
	/* 0x2ce5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ce7:
	/* 0x2ce7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ce9:
	/* 0x2ce9: js     347c <generic_sleepable_preload+0x347c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13436ULL;
	}
x86_l_2cef:
	/* 0x2cef: cmp    WORD PTR [r13+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_2cf8:
	/* 0x2cf8: je     34c8 <generic_sleepable_preload+0x34c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13512ULL;
	}
x86_l_2cfe:
	/* 0x2cfe: mov    eax,DWORD PTR [r13+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_2d05:
	/* 0x2d05: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2d09:
	/* 0x2d09: cmp    WORD PTR [r13+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_2d12:
	/* 0x2d12: je     2d2f <generic_sleepable_preload+0x2d2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d2f;
	}
x86_l_2d14:
	/* 0x2d14: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2d19:
	/* 0x2d19: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d1d:
	/* 0x2d1d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2d20:
	/* 0x2d20: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d25:
	/* 0x2d25: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d27:
	/* 0x2d27: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2d29:
	/* 0x2d29: js     348d <generic_sleepable_preload+0x348d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13453ULL;
	}
x86_l_2d2f:
	/* 0x2d2f: cmp    WORD PTR [r13+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_2d38:
	/* 0x2d38: je     34c8 <generic_sleepable_preload+0x34c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13512ULL;
	}
x86_l_2d3e:
	/* 0x2d3e: mov    eax,DWORD PTR [r13+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_2d45:
	/* 0x2d45: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2d49:
	/* 0x2d49: cmp    WORD PTR [r13+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_2d52:
	/* 0x2d52: je     2d6f <generic_sleepable_preload+0x2d6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d6f;
	}
x86_l_2d54:
	/* 0x2d54: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2d59:
	/* 0x2d59: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d5d:
	/* 0x2d5d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2d60:
	/* 0x2d60: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d65:
	/* 0x2d65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d67:
	/* 0x2d67: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2d69:
	/* 0x2d69: js     349e <generic_sleepable_preload+0x349e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13470ULL;
	}
x86_l_2d6f:
	/* 0x2d6f: cmp    WORD PTR [r13+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_2d78:
	/* 0x2d78: je     34c8 <generic_sleepable_preload+0x34c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13512ULL;
	}
x86_l_2d7e:
	/* 0x2d7e: mov    eax,DWORD PTR [r13+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_2d85:
	/* 0x2d85: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2d89:
	/* 0x2d89: cmp    WORD PTR [r13+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_2d92:
	/* 0x2d92: je     2daf <generic_sleepable_preload+0x2daf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2daf;
	}
x86_l_2d94:
	/* 0x2d94: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2d99:
	/* 0x2d99: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d9d:
	/* 0x2d9d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2da0:
	/* 0x2da0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2da5:
	/* 0x2da5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2da7:
	/* 0x2da7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2da9:
	/* 0x2da9: js     34af <generic_sleepable_preload+0x34af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13487ULL;
	}
x86_l_2daf:
	/* 0x2daf: cmp    WORD PTR [r13+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_2db8:
	/* 0x2db8: je     34c8 <generic_sleepable_preload+0x34c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13512ULL;
	}
x86_l_2dbe:
	/* 0x2dbe: mov    eax,DWORD PTR [r13+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_2dc5:
	/* 0x2dc5: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2dc9:
	/* 0x2dc9: cmp    WORD PTR [r13+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_2dd2:
	/* 0x2dd2: je     2def <generic_sleepable_preload+0x2def> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2def;
	}
x86_l_2dd4:
	/* 0x2dd4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2dd9:
	/* 0x2dd9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ddd:
	/* 0x2ddd: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2de0:
	/* 0x2de0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2de5:
	/* 0x2de5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2de7:
	/* 0x2de7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2de9:
	/* 0x2de9: js     34c0 <generic_sleepable_preload+0x34c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13504ULL;
	}
x86_l_2def:
	/* 0x2def: cmp    WORD PTR [r13+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_2df8:
	/* 0x2df8: je     34c8 <generic_sleepable_preload+0x34c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13512ULL;
	}
x86_l_2dfe:
	/* 0x2dfe: mov    eax,DWORD PTR [r13+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_2e05:
	/* 0x2e05: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2e09:
	/* 0x2e09: cmp    WORD PTR [r13+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_2e12:
	/* 0x2e12: je     2e2f <generic_sleepable_preload+0x2e2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e2f;
	}
x86_l_2e14:
	/* 0x2e14: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2e19:
	/* 0x2e19: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e1d:
	/* 0x2e1d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2e20:
	/* 0x2e20: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e25:
	/* 0x2e25: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e27:
	/* 0x2e27: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2e29:
	/* 0x2e29: js     5334 <generic_sleepable_preload+0x5334> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21300ULL;
	}
x86_l_2e2f:
	/* 0x2e2f: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e34:
	/* 0x2e34: cmp    WORD PTR [r13+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_2e3d:
	/* 0x2e3d: je     34c8 <generic_sleepable_preload+0x34c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13512ULL;
	}
x86_l_2e43:
	/* 0x2e43: mov    eax,DWORD PTR [r13+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_2e4a:
	/* 0x2e4a: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2e4e:
	/* 0x2e4e: cmp    WORD PTR [r13+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_2e57:
	/* 0x2e57: je     2e74 <generic_sleepable_preload+0x2e74> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e74;
	}
x86_l_2e59:
	/* 0x2e59: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2e5e:
	/* 0x2e5e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e62:
	/* 0x2e62: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2e65:
	/* 0x2e65: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e6a:
	/* 0x2e6a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e6c:
	/* 0x2e6c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2e6e:
	/* 0x2e6e: js     5290 <generic_sleepable_preload+0x5290> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21136ULL;
	}
x86_l_2e74:
	/* 0x2e74: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e79:
	/* 0x2e79: cmp    WORD PTR [r13+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_2e82:
	/* 0x2e82: je     34c8 <generic_sleepable_preload+0x34c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13512ULL;
	}
x86_l_2e88:
	/* 0x2e88: mov    eax,DWORD PTR [r13+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_2e8f:
	/* 0x2e8f: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2e93:
	/* 0x2e93: cmp    WORD PTR [r13+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_2e9c:
	/* 0x2e9c: je     34c8 <generic_sleepable_preload+0x34c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13512ULL;
	}
x86_l_2ea2:
	/* 0x2ea2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2ea7:
	/* 0x2ea7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2eab:
	/* 0x2eab: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2eae:
	/* 0x2eae: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2eb3:
	/* 0x2eb3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2eb5:
	/* 0x2eb5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2eb7:
	/* 0x2eb7: jns    34c8 <generic_sleepable_preload+0x34c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 13512ULL;
	}
x86_l_2ebd:
	/* 0x2ebd: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_2ec2:
	/* 0x2ec2: jmp    34c5 <generic_sleepable_preload+0x34c5> */
	return 13509ULL;
x86_l_2ec7:
	/* 0x2ec7: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_2ecc:
	/* 0x2ecc: jmp    34c5 <generic_sleepable_preload+0x34c5> */
	return 13509ULL;
x86_l_2ed1:
	/* 0x2ed1: mov    rsi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2ed9:
	/* 0x2ed9: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_2edc:
	/* 0x2edc: je     2f41 <generic_sleepable_preload+0x2f41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12097ULL;
	}
x86_l_2ede:
	/* 0x2ede: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ee3:
	/* 0x2ee3: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_2ee6:
	/* 0x2ee6: je     2f41 <generic_sleepable_preload+0x2f41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12097ULL;
	}
x86_l_2ee8:
	/* 0x2ee8: jmp    2f54 <generic_sleepable_preload+0x2f54> */
	return 12116ULL;
x86_l_2eea:
	/* 0x2eea: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2ef2:
	/* 0x2ef2: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2ef5:
	/* 0x2ef5: je     2f41 <generic_sleepable_preload+0x2f41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12097ULL;
	}
x86_l_2ef7:
	/* 0x2ef7: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2efc:
	/* 0x2efc: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_2eff:
	/* 0x2eff: je     2f41 <generic_sleepable_preload+0x2f41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12097ULL;
	}
x86_l_2f01:
	/* 0x2f01: jmp    2f54 <generic_sleepable_preload+0x2f54> */
	return 12116ULL;
x86_l_2f03:
	/* 0x2f03: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2f0b:
	/* 0x2f0b: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_2f0e:
	/* 0x2f0e: je     2f41 <generic_sleepable_preload+0x2f41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12097ULL;
	}
x86_l_2f10:
	/* 0x2f10: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
	return 12053ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12053ULL: goto x86_l_2f15;
	case 12056ULL: goto x86_l_2f18;
	case 12058ULL: goto x86_l_2f1a;
	case 12060ULL: goto x86_l_2f1c;
	case 12065ULL: goto x86_l_2f21;
	case 12068ULL: goto x86_l_2f24;
	case 12070ULL: goto x86_l_2f26;
	case 12075ULL: goto x86_l_2f2b;
	case 12078ULL: goto x86_l_2f2e;
	case 12080ULL: goto x86_l_2f30;
	case 12082ULL: goto x86_l_2f32;
	case 12087ULL: goto x86_l_2f37;
	case 12092ULL: goto x86_l_2f3c;
	case 12097ULL: goto x86_l_2f41;
	case 12100ULL: goto x86_l_2f44;
	case 12102ULL: goto x86_l_2f46;
	case 12104ULL: goto x86_l_2f48;
	case 12109ULL: goto x86_l_2f4d;
	case 12111ULL: goto x86_l_2f4f;
	case 12116ULL: goto x86_l_2f54;
	case 12120ULL: goto x86_l_2f58;
	case 12124ULL: goto x86_l_2f5c;
	case 12126ULL: goto x86_l_2f5e;
	case 12129ULL: goto x86_l_2f61;
	case 12138ULL: goto x86_l_2f6a;
	case 12144ULL: goto x86_l_2f70;
	case 12151ULL: goto x86_l_2f77;
	case 12154ULL: goto x86_l_2f7a;
	case 12161ULL: goto x86_l_2f81;
	case 12164ULL: goto x86_l_2f84;
	case 12168ULL: goto x86_l_2f88;
	case 12176ULL: goto x86_l_2f90;
	case 12178ULL: goto x86_l_2f92;
	case 12184ULL: goto x86_l_2f98;
	case 12187ULL: goto x86_l_2f9b;
	case 12189ULL: goto x86_l_2f9d;
	case 12194ULL: goto x86_l_2fa2;
	case 12198ULL: goto x86_l_2fa6;
	case 12201ULL: goto x86_l_2fa9;
	case 12206ULL: goto x86_l_2fae;
	case 12208ULL: goto x86_l_2fb0;
	case 12210ULL: goto x86_l_2fb2;
	case 12216ULL: goto x86_l_2fb8;
	case 12225ULL: goto x86_l_2fc1;
	case 12231ULL: goto x86_l_2fc7;
	case 12238ULL: goto x86_l_2fce;
	case 12242ULL: goto x86_l_2fd2;
	case 12251ULL: goto x86_l_2fdb;
	case 12253ULL: goto x86_l_2fdd;
	case 12258ULL: goto x86_l_2fe2;
	case 12262ULL: goto x86_l_2fe6;
	case 12265ULL: goto x86_l_2fe9;
	case 12270ULL: goto x86_l_2fee;
	case 12272ULL: goto x86_l_2ff0;
	case 12274ULL: goto x86_l_2ff2;
	case 12280ULL: goto x86_l_2ff8;
	case 12289ULL: goto x86_l_3001;
	case 12295ULL: goto x86_l_3007;
	case 12302ULL: goto x86_l_300e;
	case 12306ULL: goto x86_l_3012;
	case 12315ULL: goto x86_l_301b;
	case 12317ULL: goto x86_l_301d;
	case 12322ULL: goto x86_l_3022;
	case 12326ULL: goto x86_l_3026;
	case 12329ULL: goto x86_l_3029;
	case 12334ULL: goto x86_l_302e;
	case 12336ULL: goto x86_l_3030;
	case 12338ULL: goto x86_l_3032;
	case 12344ULL: goto x86_l_3038;
	case 12353ULL: goto x86_l_3041;
	case 12359ULL: goto x86_l_3047;
	case 12366ULL: goto x86_l_304e;
	case 12370ULL: goto x86_l_3052;
	case 12379ULL: goto x86_l_305b;
	case 12381ULL: goto x86_l_305d;
	case 12386ULL: goto x86_l_3062;
	case 12390ULL: goto x86_l_3066;
	case 12393ULL: goto x86_l_3069;
	case 12398ULL: goto x86_l_306e;
	case 12400ULL: goto x86_l_3070;
	case 12402ULL: goto x86_l_3072;
	case 12408ULL: goto x86_l_3078;
	case 12417ULL: goto x86_l_3081;
	case 12423ULL: goto x86_l_3087;
	case 12430ULL: goto x86_l_308e;
	case 12434ULL: goto x86_l_3092;
	case 12443ULL: goto x86_l_309b;
	case 12445ULL: goto x86_l_309d;
	case 12450ULL: goto x86_l_30a2;
	case 12454ULL: goto x86_l_30a6;
	case 12457ULL: goto x86_l_30a9;
	case 12462ULL: goto x86_l_30ae;
	case 12464ULL: goto x86_l_30b0;
	case 12466ULL: goto x86_l_30b2;
	case 12472ULL: goto x86_l_30b8;
	case 12481ULL: goto x86_l_30c1;
	case 12487ULL: goto x86_l_30c7;
	case 12494ULL: goto x86_l_30ce;
	case 12498ULL: goto x86_l_30d2;
	case 12507ULL: goto x86_l_30db;
	case 12509ULL: goto x86_l_30dd;
	case 12514ULL: goto x86_l_30e2;
	case 12518ULL: goto x86_l_30e6;
	case 12521ULL: goto x86_l_30e9;
	case 12526ULL: goto x86_l_30ee;
	case 12528ULL: goto x86_l_30f0;
	case 12530ULL: goto x86_l_30f2;
	case 12536ULL: goto x86_l_30f8;
	case 12545ULL: goto x86_l_3101;
	case 12551ULL: goto x86_l_3107;
	case 12558ULL: goto x86_l_310e;
	case 12562ULL: goto x86_l_3112;
	case 12571ULL: goto x86_l_311b;
	case 12573ULL: goto x86_l_311d;
	case 12578ULL: goto x86_l_3122;
	case 12582ULL: goto x86_l_3126;
	case 12585ULL: goto x86_l_3129;
	case 12590ULL: goto x86_l_312e;
	case 12592ULL: goto x86_l_3130;
	case 12594ULL: goto x86_l_3132;
	case 12600ULL: goto x86_l_3138;
	case 12609ULL: goto x86_l_3141;
	case 12615ULL: goto x86_l_3147;
	case 12622ULL: goto x86_l_314e;
	case 12626ULL: goto x86_l_3152;
	case 12635ULL: goto x86_l_315b;
	case 12637ULL: goto x86_l_315d;
	case 12642ULL: goto x86_l_3162;
	case 12646ULL: goto x86_l_3166;
	case 12649ULL: goto x86_l_3169;
	case 12654ULL: goto x86_l_316e;
	case 12656ULL: goto x86_l_3170;
	case 12658ULL: goto x86_l_3172;
	case 12664ULL: goto x86_l_3178;
	case 12673ULL: goto x86_l_3181;
	case 12679ULL: goto x86_l_3187;
	case 12686ULL: goto x86_l_318e;
	case 12690ULL: goto x86_l_3192;
	case 12699ULL: goto x86_l_319b;
	case 12701ULL: goto x86_l_319d;
	case 12706ULL: goto x86_l_31a2;
	case 12710ULL: goto x86_l_31a6;
	case 12713ULL: goto x86_l_31a9;
	case 12718ULL: goto x86_l_31ae;
	case 12720ULL: goto x86_l_31b0;
	case 12722ULL: goto x86_l_31b2;
	case 12728ULL: goto x86_l_31b8;
	case 12733ULL: goto x86_l_31bd;
	case 12742ULL: goto x86_l_31c6;
	case 12748ULL: goto x86_l_31cc;
	case 12755ULL: goto x86_l_31d3;
	case 12759ULL: goto x86_l_31d7;
	case 12768ULL: goto x86_l_31e0;
	case 12774ULL: goto x86_l_31e6;
	case 12779ULL: goto x86_l_31eb;
	case 12784ULL: goto x86_l_31f0;
	case 12787ULL: goto x86_l_31f3;
	case 12789ULL: goto x86_l_31f5;
	case 12794ULL: goto x86_l_31fa;
	case 12798ULL: goto x86_l_31fe;
	case 12801ULL: goto x86_l_3201;
	case 12806ULL: goto x86_l_3206;
	case 12808ULL: goto x86_l_3208;
	case 12810ULL: goto x86_l_320a;
	case 12816ULL: goto x86_l_3210;
	case 12825ULL: goto x86_l_3219;
	case 12831ULL: goto x86_l_321f;
	case 12838ULL: goto x86_l_3226;
	case 12842ULL: goto x86_l_322a;
	case 12851ULL: goto x86_l_3233;
	case 12853ULL: goto x86_l_3235;
	case 12858ULL: goto x86_l_323a;
	case 12862ULL: goto x86_l_323e;
	case 12865ULL: goto x86_l_3241;
	case 12870ULL: goto x86_l_3246;
	case 12872ULL: goto x86_l_3248;
	case 12874ULL: goto x86_l_324a;
	case 12880ULL: goto x86_l_3250;
	case 12889ULL: goto x86_l_3259;
	case 12895ULL: goto x86_l_325f;
	case 12902ULL: goto x86_l_3266;
	case 12906ULL: goto x86_l_326a;
	case 12915ULL: goto x86_l_3273;
	case 12917ULL: goto x86_l_3275;
	case 12922ULL: goto x86_l_327a;
	case 12926ULL: goto x86_l_327e;
	case 12929ULL: goto x86_l_3281;
	case 12934ULL: goto x86_l_3286;
	case 12936ULL: goto x86_l_3288;
	case 12938ULL: goto x86_l_328a;
	case 12944ULL: goto x86_l_3290;
	case 12953ULL: goto x86_l_3299;
	case 12959ULL: goto x86_l_329f;
	case 12966ULL: goto x86_l_32a6;
	case 12970ULL: goto x86_l_32aa;
	case 12979ULL: goto x86_l_32b3;
	case 12981ULL: goto x86_l_32b5;
	case 12986ULL: goto x86_l_32ba;
	case 12990ULL: goto x86_l_32be;
	case 12993ULL: goto x86_l_32c1;
	case 12998ULL: goto x86_l_32c6;
	case 13000ULL: goto x86_l_32c8;
	case 13002ULL: goto x86_l_32ca;
	case 13008ULL: goto x86_l_32d0;
	case 13017ULL: goto x86_l_32d9;
	case 13023ULL: goto x86_l_32df;
	case 13030ULL: goto x86_l_32e6;
	case 13034ULL: goto x86_l_32ea;
	case 13043ULL: goto x86_l_32f3;
	case 13045ULL: goto x86_l_32f5;
	case 13050ULL: goto x86_l_32fa;
	case 13054ULL: goto x86_l_32fe;
	case 13057ULL: goto x86_l_3301;
	case 13062ULL: goto x86_l_3306;
	case 13064ULL: goto x86_l_3308;
	case 13066ULL: goto x86_l_330a;
	case 13072ULL: goto x86_l_3310;
	case 13081ULL: goto x86_l_3319;
	case 13087ULL: goto x86_l_331f;
	case 13094ULL: goto x86_l_3326;
	case 13098ULL: goto x86_l_332a;
	case 13107ULL: goto x86_l_3333;
	case 13109ULL: goto x86_l_3335;
	case 13114ULL: goto x86_l_333a;
	case 13118ULL: goto x86_l_333e;
	case 13121ULL: goto x86_l_3341;
	case 13126ULL: goto x86_l_3346;
	case 13128ULL: goto x86_l_3348;
	case 13130ULL: goto x86_l_334a;
	case 13136ULL: goto x86_l_3350;
	case 13145ULL: goto x86_l_3359;
	case 13151ULL: goto x86_l_335f;
	case 13158ULL: goto x86_l_3366;
	case 13162ULL: goto x86_l_336a;
	case 13171ULL: goto x86_l_3373;
	case 13173ULL: goto x86_l_3375;
	case 13178ULL: goto x86_l_337a;
	case 13182ULL: goto x86_l_337e;
	case 13185ULL: goto x86_l_3381;
	case 13190ULL: goto x86_l_3386;
	case 13192ULL: goto x86_l_3388;
	case 13194ULL: goto x86_l_338a;
	case 13200ULL: goto x86_l_3390;
	case 13209ULL: goto x86_l_3399;
	case 13215ULL: goto x86_l_339f;
	case 13222ULL: goto x86_l_33a6;
	case 13226ULL: goto x86_l_33aa;
	case 13235ULL: goto x86_l_33b3;
	case 13237ULL: goto x86_l_33b5;
	case 13242ULL: goto x86_l_33ba;
	case 13246ULL: goto x86_l_33be;
	case 13249ULL: goto x86_l_33c1;
	case 13254ULL: goto x86_l_33c6;
	case 13256ULL: goto x86_l_33c8;
	case 13258ULL: goto x86_l_33ca;
	case 13264ULL: goto x86_l_33d0;
	case 13269ULL: goto x86_l_33d5;
	case 13278ULL: goto x86_l_33de;
	case 13284ULL: goto x86_l_33e4;
	case 13291ULL: goto x86_l_33eb;
	case 13295ULL: goto x86_l_33ef;
	case 13304ULL: goto x86_l_33f8;
	case 13306ULL: goto x86_l_33fa;
	case 13311ULL: goto x86_l_33ff;
	case 13315ULL: goto x86_l_3403;
	case 13318ULL: goto x86_l_3406;
	case 13323ULL: goto x86_l_340b;
	case 13325ULL: goto x86_l_340d;
	case 13327ULL: goto x86_l_340f;
	case 13333ULL: goto x86_l_3415;
	case 13338ULL: goto x86_l_341a;
	case 13347ULL: goto x86_l_3423;
	case 13353ULL: goto x86_l_3429;
	case 13360ULL: goto x86_l_3430;
	case 13364ULL: goto x86_l_3434;
	case 13373ULL: goto x86_l_343d;
	case 13379ULL: goto x86_l_3443;
	case 13384ULL: goto x86_l_3448;
	case 13388ULL: goto x86_l_344c;
	case 13391ULL: goto x86_l_344f;
	case 13396ULL: goto x86_l_3454;
	case 13398ULL: goto x86_l_3456;
	case 13400ULL: goto x86_l_3458;
	case 13406ULL: goto x86_l_345e;
	case 13411ULL: goto x86_l_3463;
	case 13416ULL: goto x86_l_3468;
	case 13421ULL: goto x86_l_346d;
	case 13426ULL: goto x86_l_3472;
	case 13431ULL: goto x86_l_3477;
	case 13436ULL: goto x86_l_347c;
	case 13441ULL: goto x86_l_3481;
	case 13443ULL: goto x86_l_3483;
	case 13448ULL: goto x86_l_3488;
	case 13453ULL: goto x86_l_348d;
	case 13458ULL: goto x86_l_3492;
	case 13460ULL: goto x86_l_3494;
	case 13465ULL: goto x86_l_3499;
	case 13470ULL: goto x86_l_349e;
	case 13475ULL: goto x86_l_34a3;
	case 13477ULL: goto x86_l_34a5;
	case 13482ULL: goto x86_l_34aa;
	case 13487ULL: goto x86_l_34af;
	case 13492ULL: goto x86_l_34b4;
	case 13494ULL: goto x86_l_34b6;
	case 13499ULL: goto x86_l_34bb;
	case 13504ULL: goto x86_l_34c0;
	case 13509ULL: goto x86_l_34c5;
	case 13512ULL: goto x86_l_34c8;
	case 13516ULL: goto x86_l_34cc;
	case 13521ULL: goto x86_l_34d1;
	case 13524ULL: goto x86_l_34d4;
	case 13529ULL: goto x86_l_34d9;
	case 13532ULL: goto x86_l_34dc;
	case 13534ULL: goto x86_l_34de;
	case 13537ULL: goto x86_l_34e1;
	case 13543ULL: goto x86_l_34e7;
	case 13547ULL: goto x86_l_34eb;
	case 13552ULL: goto x86_l_34f0;
	case 13554ULL: goto x86_l_34f2;
	case 13559ULL: goto x86_l_34f7;
	case 13567ULL: goto x86_l_34ff;
	case 13572ULL: goto x86_l_3504;
	case 13579ULL: goto x86_l_350b;
	case 13584ULL: goto x86_l_3510;
	case 13586ULL: goto x86_l_3512;
	case 13589ULL: goto x86_l_3515;
	case 13595ULL: goto x86_l_351b;
	case 13601ULL: goto x86_l_3521;
	case 13608ULL: goto x86_l_3528;
	case 13613ULL: goto x86_l_352d;
	case 13616ULL: goto x86_l_3530;
	case 13619ULL: goto x86_l_3533;
	case 13622ULL: goto x86_l_3536;
	case 13624ULL: goto x86_l_3538;
	case 13627ULL: goto x86_l_353b;
	case 13632ULL: goto x86_l_3540;
	case 13634ULL: goto x86_l_3542;
	case 13639ULL: goto x86_l_3547;
	case 13642ULL: goto x86_l_354a;
	case 13645ULL: goto x86_l_354d;
	case 13651ULL: goto x86_l_3553;
	case 13655ULL: goto x86_l_3557;
	case 13660ULL: goto x86_l_355c;
	case 13662ULL: goto x86_l_355e;
	case 13667ULL: goto x86_l_3563;
	case 13675ULL: goto x86_l_356b;
	case 13680ULL: goto x86_l_3570;
	case 13687ULL: goto x86_l_3577;
	case 13692ULL: goto x86_l_357c;
	case 13694ULL: goto x86_l_357e;
	case 13697ULL: goto x86_l_3581;
	case 13699ULL: goto x86_l_3583;
	case 13705ULL: goto x86_l_3589;
	case 13712ULL: goto x86_l_3590;
	case 13717ULL: goto x86_l_3595;
	case 13720ULL: goto x86_l_3598;
	case 13723ULL: goto x86_l_359b;
	case 13726ULL: goto x86_l_359e;
	case 13728ULL: goto x86_l_35a0;
	case 13731ULL: goto x86_l_35a3;
	case 13736ULL: goto x86_l_35a8;
	case 13739ULL: goto x86_l_35ab;
	case 13742ULL: goto x86_l_35ae;
	case 13747ULL: goto x86_l_35b3;
	case 13749ULL: goto x86_l_35b5;
	case 13752ULL: goto x86_l_35b8;
	case 13754ULL: goto x86_l_35ba;
	case 13757ULL: goto x86_l_35bd;
	case 13759ULL: goto x86_l_35bf;
	case 13762ULL: goto x86_l_35c2;
	case 13766ULL: goto x86_l_35c6;
	case 13771ULL: goto x86_l_35cb;
	case 13774ULL: goto x86_l_35ce;
	case 13776ULL: goto x86_l_35d0;
	case 13779ULL: goto x86_l_35d3;
	case 13784ULL: goto x86_l_35d8;
	case 13786ULL: goto x86_l_35da;
	case 13789ULL: goto x86_l_35dd;
	case 13791ULL: goto x86_l_35df;
	case 13796ULL: goto x86_l_35e4;
	case 13799ULL: goto x86_l_35e7;
	case 13801ULL: goto x86_l_35e9;
	case 13805ULL: goto x86_l_35ed;
	case 13810ULL: goto x86_l_35f2;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2f15:
	/* 0x2f15: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_2f18:
	/* 0x2f18: je     2f41 <generic_sleepable_preload+0x2f41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f41;
	}
x86_l_2f1a:
	/* 0x2f1a: jmp    2f54 <generic_sleepable_preload+0x2f54> */
	goto x86_l_2f54;
x86_l_2f1c:
	/* 0x2f1c: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2f21:
	/* 0x2f21: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_2f24:
	/* 0x2f24: je     2f41 <generic_sleepable_preload+0x2f41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f41;
	}
x86_l_2f26:
	/* 0x2f26: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2f2b:
	/* 0x2f2b: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_2f2e:
	/* 0x2f2e: je     2f41 <generic_sleepable_preload+0x2f41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f41;
	}
x86_l_2f30:
	/* 0x2f30: jmp    2f54 <generic_sleepable_preload+0x2f54> */
	goto x86_l_2f54;
x86_l_2f32:
	/* 0x2f32: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_2f37:
	/* 0x2f37: jmp    34c5 <generic_sleepable_preload+0x34c5> */
	goto x86_l_34c5;
x86_l_2f3c:
	/* 0x2f3c: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2f41:
	/* 0x2f41: shl    cl,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_2f44:
	/* 0x2f44: mov    al,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 64ULL);
x86_l_2f46:
	/* 0x2f46: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_2f48:
	/* 0x2f48: mov    ecx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 64ULL);
x86_l_2f4d:
	/* 0x2f4d: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2f4f:
	/* 0x2f4f: bzhi   rax,QWORD PTR [rsi],rcx */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RAX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), 0ULL);
x86_l_2f54:
	/* 0x2f54: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f58:
	/* 0x2f58: mov    ebx,DWORD PTR [r13+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2f5c:
	/* 0x2f5c: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f5e:
	/* 0x2f5e: mov    r14b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_8, 1ULL);
x86_l_2f61:
	/* 0x2f61: cmp    WORD PTR [r13+0x116],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1194000908288ULL);
x86_l_2f6a:
	/* 0x2f6a: je     354a <generic_sleepable_preload+0x354a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354a;
	}
x86_l_2f70:
	/* 0x2f70: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_2f77:
	/* 0x2f77: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2f7a:
	/* 0x2f7a: mov    edx,DWORD PTR [r13+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_2f81:
	/* 0x2f81: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2f84:
	/* 0x2f84: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f88:
	/* 0x2f88: movzx  eax,WORD PTR [r13+0x114] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 276ULL);
x86_l_2f90:
	/* 0x2f90: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_2f92:
	/* 0x2f92: je     31f0 <generic_sleepable_preload+0x31f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31f0;
	}
x86_l_2f98:
	/* 0x2f98: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_2f9b:
	/* 0x2f9b: je     2fb8 <generic_sleepable_preload+0x2fb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fb8;
	}
x86_l_2f9d:
	/* 0x2f9d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2fa2:
	/* 0x2fa2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fa6:
	/* 0x2fa6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2fa9:
	/* 0x2fa9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fae:
	/* 0x2fae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fb0:
	/* 0x2fb0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2fb2:
	/* 0x2fb2: js     3468 <generic_sleepable_preload+0x3468> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3468;
	}
x86_l_2fb8:
	/* 0x2fb8: cmp    WORD PTR [r13+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_2fc1:
	/* 0x2fc1: je     354a <generic_sleepable_preload+0x354a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354a;
	}
x86_l_2fc7:
	/* 0x2fc7: mov    eax,DWORD PTR [r13+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_2fce:
	/* 0x2fce: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2fd2:
	/* 0x2fd2: cmp    WORD PTR [r13+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_2fdb:
	/* 0x2fdb: je     2ff8 <generic_sleepable_preload+0x2ff8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ff8;
	}
x86_l_2fdd:
	/* 0x2fdd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2fe2:
	/* 0x2fe2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fe6:
	/* 0x2fe6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2fe9:
	/* 0x2fe9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fee:
	/* 0x2fee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ff0:
	/* 0x2ff0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ff2:
	/* 0x2ff2: js     3472 <generic_sleepable_preload+0x3472> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3472;
	}
x86_l_2ff8:
	/* 0x2ff8: cmp    WORD PTR [r13+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_3001:
	/* 0x3001: je     354a <generic_sleepable_preload+0x354a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354a;
	}
x86_l_3007:
	/* 0x3007: mov    eax,DWORD PTR [r13+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_300e:
	/* 0x300e: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3012:
	/* 0x3012: cmp    WORD PTR [r13+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_301b:
	/* 0x301b: je     3038 <generic_sleepable_preload+0x3038> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3038;
	}
x86_l_301d:
	/* 0x301d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3022:
	/* 0x3022: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3026:
	/* 0x3026: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3029:
	/* 0x3029: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_302e:
	/* 0x302e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3030:
	/* 0x3030: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3032:
	/* 0x3032: js     3483 <generic_sleepable_preload+0x3483> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3483;
	}
x86_l_3038:
	/* 0x3038: cmp    WORD PTR [r13+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_3041:
	/* 0x3041: je     354a <generic_sleepable_preload+0x354a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354a;
	}
x86_l_3047:
	/* 0x3047: mov    eax,DWORD PTR [r13+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_304e:
	/* 0x304e: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3052:
	/* 0x3052: cmp    WORD PTR [r13+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_305b:
	/* 0x305b: je     3078 <generic_sleepable_preload+0x3078> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3078;
	}
x86_l_305d:
	/* 0x305d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3062:
	/* 0x3062: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3066:
	/* 0x3066: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3069:
	/* 0x3069: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_306e:
	/* 0x306e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3070:
	/* 0x3070: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3072:
	/* 0x3072: js     3494 <generic_sleepable_preload+0x3494> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3494;
	}
x86_l_3078:
	/* 0x3078: cmp    WORD PTR [r13+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_3081:
	/* 0x3081: je     354a <generic_sleepable_preload+0x354a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354a;
	}
x86_l_3087:
	/* 0x3087: mov    eax,DWORD PTR [r13+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_308e:
	/* 0x308e: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3092:
	/* 0x3092: cmp    WORD PTR [r13+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_309b:
	/* 0x309b: je     30b8 <generic_sleepable_preload+0x30b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30b8;
	}
x86_l_309d:
	/* 0x309d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_30a2:
	/* 0x30a2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30a6:
	/* 0x30a6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_30a9:
	/* 0x30a9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30ae:
	/* 0x30ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30b0:
	/* 0x30b0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_30b2:
	/* 0x30b2: js     34a5 <generic_sleepable_preload+0x34a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_34a5;
	}
x86_l_30b8:
	/* 0x30b8: cmp    WORD PTR [r13+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_30c1:
	/* 0x30c1: je     354a <generic_sleepable_preload+0x354a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354a;
	}
x86_l_30c7:
	/* 0x30c7: mov    eax,DWORD PTR [r13+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_30ce:
	/* 0x30ce: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_30d2:
	/* 0x30d2: cmp    WORD PTR [r13+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_30db:
	/* 0x30db: je     30f8 <generic_sleepable_preload+0x30f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30f8;
	}
x86_l_30dd:
	/* 0x30dd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_30e2:
	/* 0x30e2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30e6:
	/* 0x30e6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_30e9:
	/* 0x30e9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30ee:
	/* 0x30ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30f0:
	/* 0x30f0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_30f2:
	/* 0x30f2: js     34b6 <generic_sleepable_preload+0x34b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_34b6;
	}
x86_l_30f8:
	/* 0x30f8: cmp    WORD PTR [r13+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_3101:
	/* 0x3101: je     354a <generic_sleepable_preload+0x354a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354a;
	}
x86_l_3107:
	/* 0x3107: mov    eax,DWORD PTR [r13+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_310e:
	/* 0x310e: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3112:
	/* 0x3112: cmp    WORD PTR [r13+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_311b:
	/* 0x311b: je     3138 <generic_sleepable_preload+0x3138> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3138;
	}
x86_l_311d:
	/* 0x311d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3122:
	/* 0x3122: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3126:
	/* 0x3126: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3129:
	/* 0x3129: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_312e:
	/* 0x312e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3130:
	/* 0x3130: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3132:
	/* 0x3132: js     3542 <generic_sleepable_preload+0x3542> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3542;
	}
x86_l_3138:
	/* 0x3138: cmp    WORD PTR [r13+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_3141:
	/* 0x3141: je     354a <generic_sleepable_preload+0x354a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354a;
	}
x86_l_3147:
	/* 0x3147: mov    eax,DWORD PTR [r13+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_314e:
	/* 0x314e: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3152:
	/* 0x3152: cmp    WORD PTR [r13+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_315b:
	/* 0x315b: je     3178 <generic_sleepable_preload+0x3178> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3178;
	}
x86_l_315d:
	/* 0x315d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3162:
	/* 0x3162: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3166:
	/* 0x3166: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3169:
	/* 0x3169: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_316e:
	/* 0x316e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3170:
	/* 0x3170: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3172:
	/* 0x3172: js     5221 <generic_sleepable_preload+0x5221> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21025ULL;
	}
x86_l_3178:
	/* 0x3178: cmp    WORD PTR [r13+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_3181:
	/* 0x3181: je     354a <generic_sleepable_preload+0x354a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354a;
	}
x86_l_3187:
	/* 0x3187: mov    eax,DWORD PTR [r13+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_318e:
	/* 0x318e: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3192:
	/* 0x3192: cmp    WORD PTR [r13+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_319b:
	/* 0x319b: je     31b8 <generic_sleepable_preload+0x31b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31b8;
	}
x86_l_319d:
	/* 0x319d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_31a2:
	/* 0x31a2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31a6:
	/* 0x31a6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_31a9:
	/* 0x31a9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31ae:
	/* 0x31ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31b0:
	/* 0x31b0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_31b2:
	/* 0x31b2: js     52a2 <generic_sleepable_preload+0x52a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21154ULL;
	}
x86_l_31b8:
	/* 0x31b8: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31bd:
	/* 0x31bd: cmp    WORD PTR [r13+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_31c6:
	/* 0x31c6: je     354a <generic_sleepable_preload+0x354a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354a;
	}
x86_l_31cc:
	/* 0x31cc: mov    eax,DWORD PTR [r13+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_31d3:
	/* 0x31d3: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_31d7:
	/* 0x31d7: cmp    WORD PTR [r13+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_31e0:
	/* 0x31e0: je     354a <generic_sleepable_preload+0x354a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354a;
	}
x86_l_31e6:
	/* 0x31e6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_31eb:
	/* 0x31eb: jmp    3448 <generic_sleepable_preload+0x3448> */
	goto x86_l_3448;
x86_l_31f0:
	/* 0x31f0: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_31f3:
	/* 0x31f3: je     3210 <generic_sleepable_preload+0x3210> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3210;
	}
x86_l_31f5:
	/* 0x31f5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_31fa:
	/* 0x31fa: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31fe:
	/* 0x31fe: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3201:
	/* 0x3201: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3206:
	/* 0x3206: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3208:
	/* 0x3208: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_320a:
	/* 0x320a: js     3468 <generic_sleepable_preload+0x3468> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3468;
	}
x86_l_3210:
	/* 0x3210: cmp    WORD PTR [r13+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_3219:
	/* 0x3219: je     354a <generic_sleepable_preload+0x354a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354a;
	}
x86_l_321f:
	/* 0x321f: mov    eax,DWORD PTR [r13+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_3226:
	/* 0x3226: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_322a:
	/* 0x322a: cmp    WORD PTR [r13+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_3233:
	/* 0x3233: je     3250 <generic_sleepable_preload+0x3250> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3250;
	}
x86_l_3235:
	/* 0x3235: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_323a:
	/* 0x323a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_323e:
	/* 0x323e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3241:
	/* 0x3241: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3246:
	/* 0x3246: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3248:
	/* 0x3248: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_324a:
	/* 0x324a: js     3472 <generic_sleepable_preload+0x3472> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3472;
	}
x86_l_3250:
	/* 0x3250: cmp    WORD PTR [r13+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_3259:
	/* 0x3259: je     354a <generic_sleepable_preload+0x354a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354a;
	}
x86_l_325f:
	/* 0x325f: mov    eax,DWORD PTR [r13+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_3266:
	/* 0x3266: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_326a:
	/* 0x326a: cmp    WORD PTR [r13+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_3273:
	/* 0x3273: je     3290 <generic_sleepable_preload+0x3290> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3290;
	}
x86_l_3275:
	/* 0x3275: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_327a:
	/* 0x327a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_327e:
	/* 0x327e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3281:
	/* 0x3281: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3286:
	/* 0x3286: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3288:
	/* 0x3288: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_328a:
	/* 0x328a: js     3483 <generic_sleepable_preload+0x3483> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3483;
	}
x86_l_3290:
	/* 0x3290: cmp    WORD PTR [r13+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_3299:
	/* 0x3299: je     354a <generic_sleepable_preload+0x354a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354a;
	}
x86_l_329f:
	/* 0x329f: mov    eax,DWORD PTR [r13+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_32a6:
	/* 0x32a6: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_32aa:
	/* 0x32aa: cmp    WORD PTR [r13+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_32b3:
	/* 0x32b3: je     32d0 <generic_sleepable_preload+0x32d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32d0;
	}
x86_l_32b5:
	/* 0x32b5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_32ba:
	/* 0x32ba: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32be:
	/* 0x32be: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_32c1:
	/* 0x32c1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32c6:
	/* 0x32c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32c8:
	/* 0x32c8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_32ca:
	/* 0x32ca: js     3494 <generic_sleepable_preload+0x3494> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3494;
	}
x86_l_32d0:
	/* 0x32d0: cmp    WORD PTR [r13+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_32d9:
	/* 0x32d9: je     354a <generic_sleepable_preload+0x354a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354a;
	}
x86_l_32df:
	/* 0x32df: mov    eax,DWORD PTR [r13+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_32e6:
	/* 0x32e6: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_32ea:
	/* 0x32ea: cmp    WORD PTR [r13+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_32f3:
	/* 0x32f3: je     3310 <generic_sleepable_preload+0x3310> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3310;
	}
x86_l_32f5:
	/* 0x32f5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_32fa:
	/* 0x32fa: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32fe:
	/* 0x32fe: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3301:
	/* 0x3301: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3306:
	/* 0x3306: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3308:
	/* 0x3308: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_330a:
	/* 0x330a: js     34a5 <generic_sleepable_preload+0x34a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_34a5;
	}
x86_l_3310:
	/* 0x3310: cmp    WORD PTR [r13+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_3319:
	/* 0x3319: je     354a <generic_sleepable_preload+0x354a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354a;
	}
x86_l_331f:
	/* 0x331f: mov    eax,DWORD PTR [r13+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_3326:
	/* 0x3326: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_332a:
	/* 0x332a: cmp    WORD PTR [r13+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_3333:
	/* 0x3333: je     3350 <generic_sleepable_preload+0x3350> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3350;
	}
x86_l_3335:
	/* 0x3335: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_333a:
	/* 0x333a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_333e:
	/* 0x333e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3341:
	/* 0x3341: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3346:
	/* 0x3346: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3348:
	/* 0x3348: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_334a:
	/* 0x334a: js     34b6 <generic_sleepable_preload+0x34b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_34b6;
	}
x86_l_3350:
	/* 0x3350: cmp    WORD PTR [r13+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_3359:
	/* 0x3359: je     354a <generic_sleepable_preload+0x354a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354a;
	}
x86_l_335f:
	/* 0x335f: mov    eax,DWORD PTR [r13+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_3366:
	/* 0x3366: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_336a:
	/* 0x336a: cmp    WORD PTR [r13+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_3373:
	/* 0x3373: je     3390 <generic_sleepable_preload+0x3390> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3390;
	}
x86_l_3375:
	/* 0x3375: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_337a:
	/* 0x337a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_337e:
	/* 0x337e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3381:
	/* 0x3381: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3386:
	/* 0x3386: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3388:
	/* 0x3388: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_338a:
	/* 0x338a: js     3542 <generic_sleepable_preload+0x3542> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3542;
	}
x86_l_3390:
	/* 0x3390: cmp    WORD PTR [r13+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_3399:
	/* 0x3399: je     354a <generic_sleepable_preload+0x354a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354a;
	}
x86_l_339f:
	/* 0x339f: mov    eax,DWORD PTR [r13+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_33a6:
	/* 0x33a6: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_33aa:
	/* 0x33aa: cmp    WORD PTR [r13+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_33b3:
	/* 0x33b3: je     33d0 <generic_sleepable_preload+0x33d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33d0;
	}
x86_l_33b5:
	/* 0x33b5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_33ba:
	/* 0x33ba: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33be:
	/* 0x33be: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_33c1:
	/* 0x33c1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33c6:
	/* 0x33c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33c8:
	/* 0x33c8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_33ca:
	/* 0x33ca: js     5346 <generic_sleepable_preload+0x5346> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21318ULL;
	}
x86_l_33d0:
	/* 0x33d0: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_33d5:
	/* 0x33d5: cmp    WORD PTR [r13+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_33de:
	/* 0x33de: je     354a <generic_sleepable_preload+0x354a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354a;
	}
x86_l_33e4:
	/* 0x33e4: mov    eax,DWORD PTR [r13+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_33eb:
	/* 0x33eb: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_33ef:
	/* 0x33ef: cmp    WORD PTR [r13+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_33f8:
	/* 0x33f8: je     3415 <generic_sleepable_preload+0x3415> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3415;
	}
x86_l_33fa:
	/* 0x33fa: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_33ff:
	/* 0x33ff: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3403:
	/* 0x3403: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3406:
	/* 0x3406: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_340b:
	/* 0x340b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_340d:
	/* 0x340d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_340f:
	/* 0x340f: js     52a2 <generic_sleepable_preload+0x52a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21154ULL;
	}
x86_l_3415:
	/* 0x3415: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_341a:
	/* 0x341a: cmp    WORD PTR [r13+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_3423:
	/* 0x3423: je     354a <generic_sleepable_preload+0x354a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354a;
	}
x86_l_3429:
	/* 0x3429: mov    eax,DWORD PTR [r13+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_3430:
	/* 0x3430: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3434:
	/* 0x3434: cmp    WORD PTR [r13+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_343d:
	/* 0x343d: je     354a <generic_sleepable_preload+0x354a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354a;
	}
x86_l_3443:
	/* 0x3443: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3448:
	/* 0x3448: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_344c:
	/* 0x344c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_344f:
	/* 0x344f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3454:
	/* 0x3454: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3456:
	/* 0x3456: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3458:
	/* 0x3458: jns    354a <generic_sleepable_preload+0x354a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_354a;
	}
x86_l_345e:
	/* 0x345e: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_3463:
	/* 0x3463: jmp    3547 <generic_sleepable_preload+0x3547> */
	goto x86_l_3547;
x86_l_3468:
	/* 0x3468: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_346d:
	/* 0x346d: jmp    3547 <generic_sleepable_preload+0x3547> */
	goto x86_l_3547;
x86_l_3472:
	/* 0x3472: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_3477:
	/* 0x3477: jmp    3547 <generic_sleepable_preload+0x3547> */
	goto x86_l_3547;
x86_l_347c:
	/* 0x347c: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_3481:
	/* 0x3481: jmp    34c5 <generic_sleepable_preload+0x34c5> */
	goto x86_l_34c5;
x86_l_3483:
	/* 0x3483: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_3488:
	/* 0x3488: jmp    3547 <generic_sleepable_preload+0x3547> */
	goto x86_l_3547;
x86_l_348d:
	/* 0x348d: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_3492:
	/* 0x3492: jmp    34c5 <generic_sleepable_preload+0x34c5> */
	goto x86_l_34c5;
x86_l_3494:
	/* 0x3494: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_3499:
	/* 0x3499: jmp    3547 <generic_sleepable_preload+0x3547> */
	goto x86_l_3547;
x86_l_349e:
	/* 0x349e: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_34a3:
	/* 0x34a3: jmp    34c5 <generic_sleepable_preload+0x34c5> */
	goto x86_l_34c5;
x86_l_34a5:
	/* 0x34a5: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_34aa:
	/* 0x34aa: jmp    3547 <generic_sleepable_preload+0x3547> */
	goto x86_l_3547;
x86_l_34af:
	/* 0x34af: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_34b4:
	/* 0x34b4: jmp    34c5 <generic_sleepable_preload+0x34c5> */
	goto x86_l_34c5;
x86_l_34b6:
	/* 0x34b6: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_34bb:
	/* 0x34bb: jmp    3547 <generic_sleepable_preload+0x3547> */
	goto x86_l_3547;
x86_l_34c0:
	/* 0x34c0: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_34c5:
	/* 0x34c5: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_34c8:
	/* 0x34c8: mov    ebx,DWORD PTR [r13+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_34cc:
	/* 0x34cc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_34d1:
	/* 0x34d1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_34d4:
	/* 0x34d4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_34d9:
	/* 0x34d9: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_34dc:
	/* 0x34dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34de:
	/* 0x34de: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_34e1:
	/* 0x34e1: jne    35e9 <generic_sleepable_preload+0x35e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_35e9;
	}
x86_l_34e7:
	/* 0x34e7: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34eb:
	/* 0x34eb: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_34f0:
	/* 0x34f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34f2:
	/* 0x34f2: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_34f7:
	/* 0x34f7: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_34ff:
	/* 0x34ff: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3504:
	/* 0x3504: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_350b:
	/* 0x350b: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_3510:
	/* 0x3510: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3512:
	/* 0x3512: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3515:
	/* 0x3515: je     35e9 <generic_sleepable_preload+0x35e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35e9;
	}
x86_l_351b:
	/* 0x351b: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_3521:
	/* 0x3521: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_3528:
	/* 0x3528: lea    r13,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_352d:
	/* 0x352d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3530:
	/* 0x3530: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_3533:
	/* 0x3533: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_3536:
	/* 0x3536: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3538:
	/* 0x3538: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_353b:
	/* 0x353b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3540:
	/* 0x3540: jmp    35a8 <generic_sleepable_preload+0x35a8> */
	goto x86_l_35a8;
x86_l_3542:
	/* 0x3542: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_3547:
	/* 0x3547: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_354a:
	/* 0x354a: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_354d:
	/* 0x354d: jne    35e9 <generic_sleepable_preload+0x35e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_35e9;
	}
x86_l_3553:
	/* 0x3553: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3557:
	/* 0x3557: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_355c:
	/* 0x355c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_355e:
	/* 0x355e: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3563:
	/* 0x3563: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_356b:
	/* 0x356b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3570:
	/* 0x3570: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_3577:
	/* 0x3577: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_357c:
	/* 0x357c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_357e:
	/* 0x357e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3581:
	/* 0x3581: je     35e9 <generic_sleepable_preload+0x35e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35e9;
	}
x86_l_3583:
	/* 0x3583: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_3589:
	/* 0x3589: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_3590:
	/* 0x3590: lea    r13,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3595:
	/* 0x3595: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3598:
	/* 0x3598: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_359b:
	/* 0x359b: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_359e:
	/* 0x359e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_35a0:
	/* 0x35a0: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_35a3:
	/* 0x35a3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_35a8:
	/* 0x35a8: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_35ab:
	/* 0x35ab: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_35ae:
	/* 0x35ae: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_35b3:
	/* 0x35b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35b5:
	/* 0x35b5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_35b8:
	/* 0x35b8: je     35e9 <generic_sleepable_preload+0x35e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35e9;
	}
x86_l_35ba:
	/* 0x35ba: test   r14b,r14b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_8);
x86_l_35bd:
	/* 0x35bd: je     35e7 <generic_sleepable_preload+0x35e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35e7;
	}
x86_l_35bf:
	/* 0x35bf: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_35c2:
	/* 0x35c2: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_35c6:
	/* 0x35c6: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_35cb:
	/* 0x35cb: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_35ce:
	/* 0x35ce: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_35d0:
	/* 0x35d0: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_35d3:
	/* 0x35d3: call   35d8 <generic_sleepable_preload+0x35d8> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_35d8:
	/* 0x35d8: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_35da:
	/* 0x35da: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_35dd:
	/* 0x35dd: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_35df:
	/* 0x35df: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_35e4:
	/* 0x35e4: cmovs  ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_35e7:
	/* 0x35e7: mov    DWORD PTR [rax],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35e9:
	/* 0x35e9: mov    eax,DWORD PTR [r13+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_35ed:
	/* 0x35ed: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_35f2:
	/* 0x35f2: jne    3610 <generic_sleepable_preload+0x3610> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13840ULL;
	}
	return 13812ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 13812ULL: goto x86_l_35f4;
	case 13816ULL: goto x86_l_35f8;
	case 13821ULL: goto x86_l_35fd;
	case 13823ULL: goto x86_l_35ff;
	case 13825ULL: goto x86_l_3601;
	case 13832ULL: goto x86_l_3608;
	case 13834ULL: goto x86_l_360a;
	case 13835ULL: goto x86_l_360b;
	case 13840ULL: goto x86_l_3610;
	case 13842ULL: goto x86_l_3612;
	case 13847ULL: goto x86_l_3617;
	case 13849ULL: goto x86_l_3619;
	case 13853ULL: goto x86_l_361d;
	case 13856ULL: goto x86_l_3620;
	case 13862ULL: goto x86_l_3626;
	case 13865ULL: goto x86_l_3629;
	case 13871ULL: goto x86_l_362f;
	case 13874ULL: goto x86_l_3632;
	case 13880ULL: goto x86_l_3638;
	case 13883ULL: goto x86_l_363b;
	case 13889ULL: goto x86_l_3641;
	case 13894ULL: goto x86_l_3646;
	case 13899ULL: goto x86_l_364b;
	case 13901ULL: goto x86_l_364d;
	case 13907ULL: goto x86_l_3653;
	case 13911ULL: goto x86_l_3657;
	case 13914ULL: goto x86_l_365a;
	case 13920ULL: goto x86_l_3660;
	case 13923ULL: goto x86_l_3663;
	case 13929ULL: goto x86_l_3669;
	case 13932ULL: goto x86_l_366c;
	case 13938ULL: goto x86_l_3672;
	case 13941ULL: goto x86_l_3675;
	case 13947ULL: goto x86_l_367b;
	case 13952ULL: goto x86_l_3680;
	case 13957ULL: goto x86_l_3685;
	case 13965ULL: goto x86_l_368d;
	case 13973ULL: goto x86_l_3695;
	case 13979ULL: goto x86_l_369b;
	case 13981ULL: goto x86_l_369d;
	case 13984ULL: goto x86_l_36a0;
	case 13990ULL: goto x86_l_36a6;
	case 13993ULL: goto x86_l_36a9;
	case 13999ULL: goto x86_l_36af;
	case 14002ULL: goto x86_l_36b2;
	case 14008ULL: goto x86_l_36b8;
	case 14013ULL: goto x86_l_36bd;
	case 14016ULL: goto x86_l_36c0;
	case 14022ULL: goto x86_l_36c6;
	case 14027ULL: goto x86_l_36cb;
	case 14030ULL: goto x86_l_36ce;
	case 14036ULL: goto x86_l_36d4;
	case 14041ULL: goto x86_l_36d9;
	case 14044ULL: goto x86_l_36dc;
	case 14050ULL: goto x86_l_36e2;
	case 14055ULL: goto x86_l_36e7;
	case 14063ULL: goto x86_l_36ef;
	case 14071ULL: goto x86_l_36f7;
	case 14077ULL: goto x86_l_36fd;
	case 14079ULL: goto x86_l_36ff;
	case 14082ULL: goto x86_l_3702;
	case 14084ULL: goto x86_l_3704;
	case 14087ULL: goto x86_l_3707;
	case 14093ULL: goto x86_l_370d;
	case 14096ULL: goto x86_l_3710;
	case 14102ULL: goto x86_l_3716;
	case 14107ULL: goto x86_l_371b;
	case 14110ULL: goto x86_l_371e;
	case 14116ULL: goto x86_l_3724;
	case 14121ULL: goto x86_l_3729;
	case 14124ULL: goto x86_l_372c;
	case 14130ULL: goto x86_l_3732;
	case 14135ULL: goto x86_l_3737;
	case 14138ULL: goto x86_l_373a;
	case 14144ULL: goto x86_l_3740;
	case 14149ULL: goto x86_l_3745;
	case 14152ULL: goto x86_l_3748;
	case 14158ULL: goto x86_l_374e;
	case 14161ULL: goto x86_l_3751;
	case 14167ULL: goto x86_l_3757;
	case 14169ULL: goto x86_l_3759;
	case 14175ULL: goto x86_l_375f;
	case 14178ULL: goto x86_l_3762;
	case 14184ULL: goto x86_l_3768;
	case 14189ULL: goto x86_l_376d;
	case 14192ULL: goto x86_l_3770;
	case 14198ULL: goto x86_l_3776;
	case 14201ULL: goto x86_l_3779;
	case 14207ULL: goto x86_l_377f;
	case 14209ULL: goto x86_l_3781;
	case 14215ULL: goto x86_l_3787;
	case 14218ULL: goto x86_l_378a;
	case 14223ULL: goto x86_l_378f;
	case 14229ULL: goto x86_l_3795;
	case 14234ULL: goto x86_l_379a;
	case 14236ULL: goto x86_l_379c;
	case 14242ULL: goto x86_l_37a2;
	case 14245ULL: goto x86_l_37a5;
	case 14251ULL: goto x86_l_37ab;
	case 14256ULL: goto x86_l_37b0;
	case 14261ULL: goto x86_l_37b5;
	case 14263ULL: goto x86_l_37b7;
	case 14269ULL: goto x86_l_37bd;
	case 14272ULL: goto x86_l_37c0;
	case 14278ULL: goto x86_l_37c6;
	case 14283ULL: goto x86_l_37cb;
	case 14288ULL: goto x86_l_37d0;
	case 14291ULL: goto x86_l_37d3;
	case 14297ULL: goto x86_l_37d9;
	case 14305ULL: goto x86_l_37e1;
	case 14308ULL: goto x86_l_37e4;
	case 14314ULL: goto x86_l_37ea;
	case 14319ULL: goto x86_l_37ef;
	case 14322ULL: goto x86_l_37f2;
	case 14328ULL: goto x86_l_37f8;
	case 14333ULL: goto x86_l_37fd;
	case 14336ULL: goto x86_l_3800;
	case 14342ULL: goto x86_l_3806;
	case 14350ULL: goto x86_l_380e;
	case 14353ULL: goto x86_l_3811;
	case 14359ULL: goto x86_l_3817;
	case 14364ULL: goto x86_l_381c;
	case 14367ULL: goto x86_l_381f;
	case 14373ULL: goto x86_l_3825;
	case 14378ULL: goto x86_l_382a;
	case 14381ULL: goto x86_l_382d;
	case 14387ULL: goto x86_l_3833;
	case 14395ULL: goto x86_l_383b;
	case 14398ULL: goto x86_l_383e;
	case 14404ULL: goto x86_l_3844;
	case 14409ULL: goto x86_l_3849;
	case 14412ULL: goto x86_l_384c;
	case 14418ULL: goto x86_l_3852;
	case 14423ULL: goto x86_l_3857;
	case 14426ULL: goto x86_l_385a;
	case 14432ULL: goto x86_l_3860;
	case 14440ULL: goto x86_l_3868;
	case 14443ULL: goto x86_l_386b;
	case 14449ULL: goto x86_l_3871;
	case 14454ULL: goto x86_l_3876;
	case 14457ULL: goto x86_l_3879;
	case 14463ULL: goto x86_l_387f;
	case 14468ULL: goto x86_l_3884;
	case 14473ULL: goto x86_l_3889;
	case 14475ULL: goto x86_l_388b;
	case 14480ULL: goto x86_l_3890;
	case 14485ULL: goto x86_l_3895;
	case 14490ULL: goto x86_l_389a;
	case 14492ULL: goto x86_l_389c;
	case 14497ULL: goto x86_l_38a1;
	case 14502ULL: goto x86_l_38a6;
	case 14507ULL: goto x86_l_38ab;
	case 14510ULL: goto x86_l_38ae;
	case 14514ULL: goto x86_l_38b2;
	case 14516ULL: goto x86_l_38b4;
	case 14519ULL: goto x86_l_38b7;
	case 14528ULL: goto x86_l_38c0;
	case 14534ULL: goto x86_l_38c6;
	case 14541ULL: goto x86_l_38cd;
	case 14544ULL: goto x86_l_38d0;
	case 14551ULL: goto x86_l_38d7;
	case 14554ULL: goto x86_l_38da;
	case 14558ULL: goto x86_l_38de;
	case 14566ULL: goto x86_l_38e6;
	case 14568ULL: goto x86_l_38e8;
	case 14574ULL: goto x86_l_38ee;
	case 14577ULL: goto x86_l_38f1;
	case 14579ULL: goto x86_l_38f3;
	case 14584ULL: goto x86_l_38f8;
	case 14588ULL: goto x86_l_38fc;
	case 14591ULL: goto x86_l_38ff;
	case 14596ULL: goto x86_l_3904;
	case 14598ULL: goto x86_l_3906;
	case 14600ULL: goto x86_l_3908;
	case 14606ULL: goto x86_l_390e;
	case 14615ULL: goto x86_l_3917;
	case 14621ULL: goto x86_l_391d;
	case 14628ULL: goto x86_l_3924;
	case 14632ULL: goto x86_l_3928;
	case 14641ULL: goto x86_l_3931;
	case 14643ULL: goto x86_l_3933;
	case 14648ULL: goto x86_l_3938;
	case 14652ULL: goto x86_l_393c;
	case 14655ULL: goto x86_l_393f;
	case 14660ULL: goto x86_l_3944;
	case 14662ULL: goto x86_l_3946;
	case 14664ULL: goto x86_l_3948;
	case 14670ULL: goto x86_l_394e;
	case 14679ULL: goto x86_l_3957;
	case 14685ULL: goto x86_l_395d;
	case 14692ULL: goto x86_l_3964;
	case 14696ULL: goto x86_l_3968;
	case 14705ULL: goto x86_l_3971;
	case 14707ULL: goto x86_l_3973;
	case 14712ULL: goto x86_l_3978;
	case 14716ULL: goto x86_l_397c;
	case 14719ULL: goto x86_l_397f;
	case 14724ULL: goto x86_l_3984;
	case 14726ULL: goto x86_l_3986;
	case 14728ULL: goto x86_l_3988;
	case 14734ULL: goto x86_l_398e;
	case 14743ULL: goto x86_l_3997;
	case 14749ULL: goto x86_l_399d;
	case 14756ULL: goto x86_l_39a4;
	case 14760ULL: goto x86_l_39a8;
	case 14769ULL: goto x86_l_39b1;
	case 14771ULL: goto x86_l_39b3;
	case 14776ULL: goto x86_l_39b8;
	case 14780ULL: goto x86_l_39bc;
	case 14783ULL: goto x86_l_39bf;
	case 14788ULL: goto x86_l_39c4;
	case 14790ULL: goto x86_l_39c6;
	case 14792ULL: goto x86_l_39c8;
	case 14798ULL: goto x86_l_39ce;
	case 14807ULL: goto x86_l_39d7;
	case 14813ULL: goto x86_l_39dd;
	case 14820ULL: goto x86_l_39e4;
	case 14824ULL: goto x86_l_39e8;
	case 14833ULL: goto x86_l_39f1;
	case 14835ULL: goto x86_l_39f3;
	case 14840ULL: goto x86_l_39f8;
	case 14844ULL: goto x86_l_39fc;
	case 14847ULL: goto x86_l_39ff;
	case 14852ULL: goto x86_l_3a04;
	case 14854ULL: goto x86_l_3a06;
	case 14856ULL: goto x86_l_3a08;
	case 14862ULL: goto x86_l_3a0e;
	case 14871ULL: goto x86_l_3a17;
	case 14877ULL: goto x86_l_3a1d;
	case 14884ULL: goto x86_l_3a24;
	case 14888ULL: goto x86_l_3a28;
	case 14897ULL: goto x86_l_3a31;
	case 14899ULL: goto x86_l_3a33;
	case 14904ULL: goto x86_l_3a38;
	case 14908ULL: goto x86_l_3a3c;
	case 14911ULL: goto x86_l_3a3f;
	case 14916ULL: goto x86_l_3a44;
	case 14918ULL: goto x86_l_3a46;
	case 14920ULL: goto x86_l_3a48;
	case 14926ULL: goto x86_l_3a4e;
	case 14935ULL: goto x86_l_3a57;
	case 14941ULL: goto x86_l_3a5d;
	case 14948ULL: goto x86_l_3a64;
	case 14952ULL: goto x86_l_3a68;
	case 14961ULL: goto x86_l_3a71;
	case 14963ULL: goto x86_l_3a73;
	case 14968ULL: goto x86_l_3a78;
	case 14972ULL: goto x86_l_3a7c;
	case 14975ULL: goto x86_l_3a7f;
	case 14980ULL: goto x86_l_3a84;
	case 14982ULL: goto x86_l_3a86;
	case 14984ULL: goto x86_l_3a88;
	case 14990ULL: goto x86_l_3a8e;
	case 14999ULL: goto x86_l_3a97;
	case 15005ULL: goto x86_l_3a9d;
	case 15012ULL: goto x86_l_3aa4;
	case 15016ULL: goto x86_l_3aa8;
	case 15025ULL: goto x86_l_3ab1;
	case 15027ULL: goto x86_l_3ab3;
	case 15032ULL: goto x86_l_3ab8;
	case 15036ULL: goto x86_l_3abc;
	case 15039ULL: goto x86_l_3abf;
	case 15044ULL: goto x86_l_3ac4;
	case 15046ULL: goto x86_l_3ac6;
	case 15048ULL: goto x86_l_3ac8;
	case 15054ULL: goto x86_l_3ace;
	case 15063ULL: goto x86_l_3ad7;
	case 15069ULL: goto x86_l_3add;
	case 15076ULL: goto x86_l_3ae4;
	case 15080ULL: goto x86_l_3ae8;
	case 15089ULL: goto x86_l_3af1;
	case 15091ULL: goto x86_l_3af3;
	case 15096ULL: goto x86_l_3af8;
	case 15100ULL: goto x86_l_3afc;
	case 15103ULL: goto x86_l_3aff;
	case 15108ULL: goto x86_l_3b04;
	case 15110ULL: goto x86_l_3b06;
	case 15112ULL: goto x86_l_3b08;
	case 15118ULL: goto x86_l_3b0e;
	case 15123ULL: goto x86_l_3b13;
	case 15132ULL: goto x86_l_3b1c;
	case 15138ULL: goto x86_l_3b22;
	case 15145ULL: goto x86_l_3b29;
	case 15149ULL: goto x86_l_3b2d;
	case 15158ULL: goto x86_l_3b36;
	case 15164ULL: goto x86_l_3b3c;
	case 15169ULL: goto x86_l_3b41;
	case 15174ULL: goto x86_l_3b46;
	case 15177ULL: goto x86_l_3b49;
	case 15179ULL: goto x86_l_3b4b;
	case 15184ULL: goto x86_l_3b50;
	case 15188ULL: goto x86_l_3b54;
	case 15191ULL: goto x86_l_3b57;
	case 15196ULL: goto x86_l_3b5c;
	case 15198ULL: goto x86_l_3b5e;
	case 15200ULL: goto x86_l_3b60;
	case 15206ULL: goto x86_l_3b66;
	case 15215ULL: goto x86_l_3b6f;
	case 15221ULL: goto x86_l_3b75;
	case 15228ULL: goto x86_l_3b7c;
	case 15232ULL: goto x86_l_3b80;
	case 15241ULL: goto x86_l_3b89;
	case 15243ULL: goto x86_l_3b8b;
	case 15248ULL: goto x86_l_3b90;
	case 15252ULL: goto x86_l_3b94;
	case 15255ULL: goto x86_l_3b97;
	case 15260ULL: goto x86_l_3b9c;
	case 15262ULL: goto x86_l_3b9e;
	case 15264ULL: goto x86_l_3ba0;
	case 15270ULL: goto x86_l_3ba6;
	case 15279ULL: goto x86_l_3baf;
	case 15285ULL: goto x86_l_3bb5;
	case 15292ULL: goto x86_l_3bbc;
	case 15296ULL: goto x86_l_3bc0;
	case 15305ULL: goto x86_l_3bc9;
	case 15307ULL: goto x86_l_3bcb;
	case 15312ULL: goto x86_l_3bd0;
	case 15316ULL: goto x86_l_3bd4;
	case 15319ULL: goto x86_l_3bd7;
	case 15324ULL: goto x86_l_3bdc;
	case 15326ULL: goto x86_l_3bde;
	case 15328ULL: goto x86_l_3be0;
	case 15334ULL: goto x86_l_3be6;
	case 15343ULL: goto x86_l_3bef;
	case 15349ULL: goto x86_l_3bf5;
	case 15356ULL: goto x86_l_3bfc;
	case 15360ULL: goto x86_l_3c00;
	case 15369ULL: goto x86_l_3c09;
	case 15371ULL: goto x86_l_3c0b;
	case 15376ULL: goto x86_l_3c10;
	case 15380ULL: goto x86_l_3c14;
	case 15383ULL: goto x86_l_3c17;
	case 15388ULL: goto x86_l_3c1c;
	case 15390ULL: goto x86_l_3c1e;
	case 15392ULL: goto x86_l_3c20;
	case 15398ULL: goto x86_l_3c26;
	case 15407ULL: goto x86_l_3c2f;
	case 15413ULL: goto x86_l_3c35;
	case 15420ULL: goto x86_l_3c3c;
	case 15424ULL: goto x86_l_3c40;
	case 15433ULL: goto x86_l_3c49;
	case 15435ULL: goto x86_l_3c4b;
	case 15440ULL: goto x86_l_3c50;
	case 15444ULL: goto x86_l_3c54;
	case 15447ULL: goto x86_l_3c57;
	case 15452ULL: goto x86_l_3c5c;
	case 15454ULL: goto x86_l_3c5e;
	case 15456ULL: goto x86_l_3c60;
	case 15462ULL: goto x86_l_3c66;
	case 15471ULL: goto x86_l_3c6f;
	case 15477ULL: goto x86_l_3c75;
	case 15484ULL: goto x86_l_3c7c;
	case 15488ULL: goto x86_l_3c80;
	case 15497ULL: goto x86_l_3c89;
	case 15499ULL: goto x86_l_3c8b;
	case 15504ULL: goto x86_l_3c90;
	case 15508ULL: goto x86_l_3c94;
	case 15511ULL: goto x86_l_3c97;
	case 15516ULL: goto x86_l_3c9c;
	case 15518ULL: goto x86_l_3c9e;
	case 15520ULL: goto x86_l_3ca0;
	case 15526ULL: goto x86_l_3ca6;
	case 15535ULL: goto x86_l_3caf;
	case 15541ULL: goto x86_l_3cb5;
	case 15548ULL: goto x86_l_3cbc;
	case 15552ULL: goto x86_l_3cc0;
	case 15561ULL: goto x86_l_3cc9;
	case 15563ULL: goto x86_l_3ccb;
	case 15568ULL: goto x86_l_3cd0;
	case 15572ULL: goto x86_l_3cd4;
	case 15575ULL: goto x86_l_3cd7;
	case 15580ULL: goto x86_l_3cdc;
	case 15582ULL: goto x86_l_3cde;
	case 15584ULL: goto x86_l_3ce0;
	case 15590ULL: goto x86_l_3ce6;
	case 15599ULL: goto x86_l_3cef;
	case 15605ULL: goto x86_l_3cf5;
	case 15612ULL: goto x86_l_3cfc;
	case 15616ULL: goto x86_l_3d00;
	case 15625ULL: goto x86_l_3d09;
	case 15627ULL: goto x86_l_3d0b;
	case 15632ULL: goto x86_l_3d10;
	case 15636ULL: goto x86_l_3d14;
	case 15639ULL: goto x86_l_3d17;
	default: return 0xffffffffffffffffULL;
	}
x86_l_35f4:
	/* 0x35f4: mov    eax,DWORD PTR [r13+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_35f8:
	/* 0x35f8: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_35fd:
	/* 0x35fd: jne    364b <generic_sleepable_preload+0x364b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_364b;
	}
x86_l_35ff:
	/* 0x35ff: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3601:
	/* 0x3601: add    rsp,0xb8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 184ULL);
x86_l_3608:
	/* 0x3608: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_360a:
	/* 0x360a: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_360b:
	/* 0x360b: jmp    537c <generic_sleepable_preload+0x537c> ; native-link entry RET */
	return 0xffffffffffffffffULL;
x86_l_3610:
	/* 0x3610: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_3612:
	/* 0x3612: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3617:
	/* 0x3617: js     3685 <generic_sleepable_preload+0x3685> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3685;
	}
x86_l_3619:
	/* 0x3619: mov    ecx,DWORD PTR [r13+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_361d:
	/* 0x361d: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_3620:
	/* 0x3620: jle    379a <generic_sleepable_preload+0x379a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_379a;
	}
x86_l_3626:
	/* 0x3626: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_3629:
	/* 0x3629: je     3884 <generic_sleepable_preload+0x3884> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3884;
	}
x86_l_362f:
	/* 0x362f: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_3632:
	/* 0x3632: je     3895 <generic_sleepable_preload+0x3895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3895;
	}
x86_l_3638:
	/* 0x3638: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_363b:
	/* 0x363b: jne    38b2 <generic_sleepable_preload+0x38b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_38b2;
	}
x86_l_3641:
	/* 0x3641: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3646:
	/* 0x3646: jmp    38ab <generic_sleepable_preload+0x38ab> */
	goto x86_l_38ab;
x86_l_364b:
	/* 0x364b: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_364d:
	/* 0x364d: js     36e7 <generic_sleepable_preload+0x36e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_36e7;
	}
x86_l_3653:
	/* 0x3653: mov    ecx,DWORD PTR [r13+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3657:
	/* 0x3657: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_365a:
	/* 0x365a: jle    37b5 <generic_sleepable_preload+0x37b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_37b5;
	}
x86_l_3660:
	/* 0x3660: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_3663:
	/* 0x3663: je     388b <generic_sleepable_preload+0x388b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_388b;
	}
x86_l_3669:
	/* 0x3669: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_366c:
	/* 0x366c: je     389c <generic_sleepable_preload+0x389c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_389c;
	}
x86_l_3672:
	/* 0x3672: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3675:
	/* 0x3675: jne    3dd4 <generic_sleepable_preload+0x3dd4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 15828ULL;
	}
x86_l_367b:
	/* 0x367b: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3680:
	/* 0x3680: jmp    3dcd <generic_sleepable_preload+0x3dcd> */
	return 15821ULL;
x86_l_3685:
	/* 0x3685: movzx  ecx,BYTE PTR [r13+0x2ce] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 718ULL);
x86_l_368d:
	/* 0x368d: movzx  eax,WORD PTR [r13+0x2cc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 716ULL);
x86_l_3695:
	/* 0x3695: rorx   edx,eax,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 3ULL);
x86_l_369b:
	/* 0x369b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_369d:
	/* 0x369d: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_36a0:
	/* 0x36a0: jle    3745 <generic_sleepable_preload+0x3745> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_3745;
	}
x86_l_36a6:
	/* 0x36a6: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_36a9:
	/* 0x36a9: jle    37d0 <generic_sleepable_preload+0x37d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_37d0;
	}
x86_l_36af:
	/* 0x36af: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_36b2:
	/* 0x36b2: jle    43d5 <generic_sleepable_preload+0x43d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 17365ULL;
	}
x86_l_36b8:
	/* 0x36b8: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_36bd:
	/* 0x36bd: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_36c0:
	/* 0x36c0: je     4425 <generic_sleepable_preload+0x4425> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17445ULL;
	}
x86_l_36c6:
	/* 0x36c6: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_36cb:
	/* 0x36cb: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_36ce:
	/* 0x36ce: je     4425 <generic_sleepable_preload+0x4425> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17445ULL;
	}
x86_l_36d4:
	/* 0x36d4: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_36d9:
	/* 0x36d9: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_36dc:
	/* 0x36dc: je     4425 <generic_sleepable_preload+0x4425> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17445ULL;
	}
x86_l_36e2:
	/* 0x36e2: jmp    4438 <generic_sleepable_preload+0x4438> */
	return 17464ULL;
x86_l_36e7:
	/* 0x36e7: movzx  ecx,BYTE PTR [r13+0x2d2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 722ULL);
x86_l_36ef:
	/* 0x36ef: movzx  eax,WORD PTR [r13+0x2d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 720ULL);
x86_l_36f7:
	/* 0x36f7: rorx   edx,eax,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 3ULL);
x86_l_36fd:
	/* 0x36fd: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_36ff:
	/* 0x36ff: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_3702:
	/* 0x3702: jle    376d <generic_sleepable_preload+0x376d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_376d;
	}
x86_l_3704:
	/* 0x3704: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_3707:
	/* 0x3707: jle    37fd <generic_sleepable_preload+0x37fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_37fd;
	}
x86_l_370d:
	/* 0x370d: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_3710:
	/* 0x3710: jle    43eb <generic_sleepable_preload+0x43eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 17387ULL;
	}
x86_l_3716:
	/* 0x3716: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_371b:
	/* 0x371b: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_371e:
	/* 0x371e: je     4965 <generic_sleepable_preload+0x4965> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18789ULL;
	}
x86_l_3724:
	/* 0x3724: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3729:
	/* 0x3729: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_372c:
	/* 0x372c: je     4965 <generic_sleepable_preload+0x4965> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18789ULL;
	}
x86_l_3732:
	/* 0x3732: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3737:
	/* 0x3737: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_373a:
	/* 0x373a: je     4965 <generic_sleepable_preload+0x4965> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18789ULL;
	}
x86_l_3740:
	/* 0x3740: jmp    4978 <generic_sleepable_preload+0x4978> */
	return 18808ULL;
x86_l_3745:
	/* 0x3745: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_3748:
	/* 0x3748: jg     382a <generic_sleepable_preload+0x382a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_382a;
	}
x86_l_374e:
	/* 0x374e: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_3751:
	/* 0x3751: jg     4349 <generic_sleepable_preload+0x4349> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 17225ULL;
	}
x86_l_3757:
	/* 0x3757: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_3759:
	/* 0x3759: je     4420 <generic_sleepable_preload+0x4420> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17440ULL;
	}
x86_l_375f:
	/* 0x375f: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_3762:
	/* 0x3762: je     4425 <generic_sleepable_preload+0x4425> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17445ULL;
	}
x86_l_3768:
	/* 0x3768: jmp    4438 <generic_sleepable_preload+0x4438> */
	return 17464ULL;
x86_l_376d:
	/* 0x376d: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_3770:
	/* 0x3770: jg     3857 <generic_sleepable_preload+0x3857> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3857;
	}
x86_l_3776:
	/* 0x3776: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_3779:
	/* 0x3779: jg     436d <generic_sleepable_preload+0x436d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 17261ULL;
	}
x86_l_377f:
	/* 0x377f: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_3781:
	/* 0x3781: je     4960 <generic_sleepable_preload+0x4960> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18784ULL;
	}
x86_l_3787:
	/* 0x3787: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_378a:
	/* 0x378a: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_378f:
	/* 0x378f: je     4965 <generic_sleepable_preload+0x4965> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18789ULL;
	}
x86_l_3795:
	/* 0x3795: jmp    4978 <generic_sleepable_preload+0x4978> */
	return 18808ULL;
x86_l_379a:
	/* 0x379a: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_379c:
	/* 0x379c: je     38a6 <generic_sleepable_preload+0x38a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38a6;
	}
x86_l_37a2:
	/* 0x37a2: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_37a5:
	/* 0x37a5: jne    38b2 <generic_sleepable_preload+0x38b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_38b2;
	}
x86_l_37ab:
	/* 0x37ab: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_37b0:
	/* 0x37b0: jmp    38ab <generic_sleepable_preload+0x38ab> */
	goto x86_l_38ab;
x86_l_37b5:
	/* 0x37b5: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_37b7:
	/* 0x37b7: je     3dc8 <generic_sleepable_preload+0x3dc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15816ULL;
	}
x86_l_37bd:
	/* 0x37bd: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_37c0:
	/* 0x37c0: jne    3dd4 <generic_sleepable_preload+0x3dd4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 15828ULL;
	}
x86_l_37c6:
	/* 0x37c6: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_37cb:
	/* 0x37cb: jmp    3dcd <generic_sleepable_preload+0x3dcd> */
	return 15821ULL;
x86_l_37d0:
	/* 0x37d0: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_37d3:
	/* 0x37d3: jg     4301 <generic_sleepable_preload+0x4301> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 17153ULL;
	}
x86_l_37d9:
	/* 0x37d9: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_37e1:
	/* 0x37e1: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_37e4:
	/* 0x37e4: je     4425 <generic_sleepable_preload+0x4425> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17445ULL;
	}
x86_l_37ea:
	/* 0x37ea: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_37ef:
	/* 0x37ef: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_37f2:
	/* 0x37f2: je     4425 <generic_sleepable_preload+0x4425> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17445ULL;
	}
x86_l_37f8:
	/* 0x37f8: jmp    4438 <generic_sleepable_preload+0x4438> */
	return 17464ULL;
x86_l_37fd:
	/* 0x37fd: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_3800:
	/* 0x3800: jg     4325 <generic_sleepable_preload+0x4325> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 17189ULL;
	}
x86_l_3806:
	/* 0x3806: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_380e:
	/* 0x380e: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3811:
	/* 0x3811: je     4965 <generic_sleepable_preload+0x4965> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18789ULL;
	}
x86_l_3817:
	/* 0x3817: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_381c:
	/* 0x381c: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_381f:
	/* 0x381f: je     4965 <generic_sleepable_preload+0x4965> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18789ULL;
	}
x86_l_3825:
	/* 0x3825: jmp    4978 <generic_sleepable_preload+0x4978> */
	return 18808ULL;
x86_l_382a:
	/* 0x382a: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_382d:
	/* 0x382d: jg     4391 <generic_sleepable_preload+0x4391> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 17297ULL;
	}
x86_l_3833:
	/* 0x3833: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_383b:
	/* 0x383b: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_383e:
	/* 0x383e: je     4425 <generic_sleepable_preload+0x4425> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17445ULL;
	}
x86_l_3844:
	/* 0x3844: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3849:
	/* 0x3849: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_384c:
	/* 0x384c: je     4425 <generic_sleepable_preload+0x4425> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17445ULL;
	}
x86_l_3852:
	/* 0x3852: jmp    4438 <generic_sleepable_preload+0x4438> */
	return 17464ULL;
x86_l_3857:
	/* 0x3857: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_385a:
	/* 0x385a: jg     43b1 <generic_sleepable_preload+0x43b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 17329ULL;
	}
x86_l_3860:
	/* 0x3860: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_3868:
	/* 0x3868: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_386b:
	/* 0x386b: je     4965 <generic_sleepable_preload+0x4965> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18789ULL;
	}
x86_l_3871:
	/* 0x3871: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3876:
	/* 0x3876: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_3879:
	/* 0x3879: je     4965 <generic_sleepable_preload+0x4965> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18789ULL;
	}
x86_l_387f:
	/* 0x387f: jmp    4978 <generic_sleepable_preload+0x4978> */
	return 18808ULL;
x86_l_3884:
	/* 0x3884: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3889:
	/* 0x3889: jmp    38ab <generic_sleepable_preload+0x38ab> */
	goto x86_l_38ab;
x86_l_388b:
	/* 0x388b: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3890:
	/* 0x3890: jmp    3dcd <generic_sleepable_preload+0x3dcd> */
	return 15821ULL;
x86_l_3895:
	/* 0x3895: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_389a:
	/* 0x389a: jmp    38ab <generic_sleepable_preload+0x38ab> */
	goto x86_l_38ab;
x86_l_389c:
	/* 0x389c: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_38a1:
	/* 0x38a1: jmp    3dcd <generic_sleepable_preload+0x3dcd> */
	return 15821ULL;
x86_l_38a6:
	/* 0x38a6: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_38ab:
	/* 0x38ab: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_38ae:
	/* 0x38ae: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_38b2:
	/* 0x38b2: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_38b4:
	/* 0x38b4: mov    r14b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_8, 1ULL);
x86_l_38b7:
	/* 0x38b7: cmp    WORD PTR [r13+0x166],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1537598291968ULL);
x86_l_38c0:
	/* 0x38c0: je     4f54 <generic_sleepable_preload+0x4f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20308ULL;
	}
x86_l_38c6:
	/* 0x38c6: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_38cd:
	/* 0x38cd: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_38d0:
	/* 0x38d0: mov    edx,DWORD PTR [r13+0x160] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_38d7:
	/* 0x38d7: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_38da:
	/* 0x38da: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_38de:
	/* 0x38de: movzx  eax,WORD PTR [r13+0x164] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 356ULL);
x86_l_38e6:
	/* 0x38e6: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_38e8:
	/* 0x38e8: je     3b46 <generic_sleepable_preload+0x3b46> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3b46;
	}
x86_l_38ee:
	/* 0x38ee: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_38f1:
	/* 0x38f1: je     390e <generic_sleepable_preload+0x390e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_390e;
	}
x86_l_38f3:
	/* 0x38f3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_38f8:
	/* 0x38f8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_38fc:
	/* 0x38fc: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_38ff:
	/* 0x38ff: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3904:
	/* 0x3904: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3906:
	/* 0x3906: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3908:
	/* 0x3908: js     3dbe <generic_sleepable_preload+0x3dbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15806ULL;
	}
x86_l_390e:
	/* 0x390e: cmp    WORD PTR [r13+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_3917:
	/* 0x3917: je     4f54 <generic_sleepable_preload+0x4f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20308ULL;
	}
x86_l_391d:
	/* 0x391d: mov    eax,DWORD PTR [r13+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_3924:
	/* 0x3924: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3928:
	/* 0x3928: cmp    WORD PTR [r13+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_3931:
	/* 0x3931: je     394e <generic_sleepable_preload+0x394e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_394e;
	}
x86_l_3933:
	/* 0x3933: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3938:
	/* 0x3938: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_393c:
	/* 0x393c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_393f:
	/* 0x393f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3944:
	/* 0x3944: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3946:
	/* 0x3946: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3948:
	/* 0x3948: js     440c <generic_sleepable_preload+0x440c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 17420ULL;
	}
x86_l_394e:
	/* 0x394e: cmp    WORD PTR [r13+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_3957:
	/* 0x3957: je     4f54 <generic_sleepable_preload+0x4f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20308ULL;
	}
x86_l_395d:
	/* 0x395d: mov    eax,DWORD PTR [r13+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_3964:
	/* 0x3964: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3968:
	/* 0x3968: cmp    WORD PTR [r13+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_3971:
	/* 0x3971: je     398e <generic_sleepable_preload+0x398e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_398e;
	}
x86_l_3973:
	/* 0x3973: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3978:
	/* 0x3978: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_397c:
	/* 0x397c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_397f:
	/* 0x397f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3984:
	/* 0x3984: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3986:
	/* 0x3986: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3988:
	/* 0x3988: js     4eb5 <generic_sleepable_preload+0x4eb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20149ULL;
	}
x86_l_398e:
	/* 0x398e: cmp    WORD PTR [r13+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_3997:
	/* 0x3997: je     4f54 <generic_sleepable_preload+0x4f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20308ULL;
	}
x86_l_399d:
	/* 0x399d: mov    eax,DWORD PTR [r13+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_39a4:
	/* 0x39a4: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_39a8:
	/* 0x39a8: cmp    WORD PTR [r13+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_39b1:
	/* 0x39b1: je     39ce <generic_sleepable_preload+0x39ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_39ce;
	}
x86_l_39b3:
	/* 0x39b3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_39b8:
	/* 0x39b8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_39bc:
	/* 0x39bc: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_39bf:
	/* 0x39bf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_39c4:
	/* 0x39c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39c6:
	/* 0x39c6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_39c8:
	/* 0x39c8: js     4edd <generic_sleepable_preload+0x4edd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20189ULL;
	}
x86_l_39ce:
	/* 0x39ce: cmp    WORD PTR [r13+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_39d7:
	/* 0x39d7: je     4f54 <generic_sleepable_preload+0x4f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20308ULL;
	}
x86_l_39dd:
	/* 0x39dd: mov    eax,DWORD PTR [r13+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_39e4:
	/* 0x39e4: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_39e8:
	/* 0x39e8: cmp    WORD PTR [r13+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_39f1:
	/* 0x39f1: je     3a0e <generic_sleepable_preload+0x3a0e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a0e;
	}
x86_l_39f3:
	/* 0x39f3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_39f8:
	/* 0x39f8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_39fc:
	/* 0x39fc: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_39ff:
	/* 0x39ff: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a04:
	/* 0x3a04: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a06:
	/* 0x3a06: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3a08:
	/* 0x3a08: js     4f02 <generic_sleepable_preload+0x4f02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20226ULL;
	}
x86_l_3a0e:
	/* 0x3a0e: cmp    WORD PTR [r13+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_3a17:
	/* 0x3a17: je     4f54 <generic_sleepable_preload+0x4f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20308ULL;
	}
x86_l_3a1d:
	/* 0x3a1d: mov    eax,DWORD PTR [r13+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_3a24:
	/* 0x3a24: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3a28:
	/* 0x3a28: cmp    WORD PTR [r13+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_3a31:
	/* 0x3a31: je     3a4e <generic_sleepable_preload+0x3a4e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a4e;
	}
x86_l_3a33:
	/* 0x3a33: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3a38:
	/* 0x3a38: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a3c:
	/* 0x3a3c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3a3f:
	/* 0x3a3f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a44:
	/* 0x3a44: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a46:
	/* 0x3a46: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3a48:
	/* 0x3a48: js     4f27 <generic_sleepable_preload+0x4f27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20263ULL;
	}
x86_l_3a4e:
	/* 0x3a4e: cmp    WORD PTR [r13+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_3a57:
	/* 0x3a57: je     4f54 <generic_sleepable_preload+0x4f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20308ULL;
	}
x86_l_3a5d:
	/* 0x3a5d: mov    eax,DWORD PTR [r13+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_3a64:
	/* 0x3a64: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3a68:
	/* 0x3a68: cmp    WORD PTR [r13+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_3a71:
	/* 0x3a71: je     3a8e <generic_sleepable_preload+0x3a8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a8e;
	}
x86_l_3a73:
	/* 0x3a73: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3a78:
	/* 0x3a78: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a7c:
	/* 0x3a7c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3a7f:
	/* 0x3a7f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a84:
	/* 0x3a84: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a86:
	/* 0x3a86: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3a88:
	/* 0x3a88: js     4f4c <generic_sleepable_preload+0x4f4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20300ULL;
	}
x86_l_3a8e:
	/* 0x3a8e: cmp    WORD PTR [r13+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_3a97:
	/* 0x3a97: je     4f54 <generic_sleepable_preload+0x4f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20308ULL;
	}
x86_l_3a9d:
	/* 0x3a9d: mov    eax,DWORD PTR [r13+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_3aa4:
	/* 0x3aa4: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3aa8:
	/* 0x3aa8: cmp    WORD PTR [r13+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_3ab1:
	/* 0x3ab1: je     3ace <generic_sleepable_preload+0x3ace> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ace;
	}
x86_l_3ab3:
	/* 0x3ab3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3ab8:
	/* 0x3ab8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3abc:
	/* 0x3abc: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3abf:
	/* 0x3abf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3ac4:
	/* 0x3ac4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ac6:
	/* 0x3ac6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3ac8:
	/* 0x3ac8: js     522e <generic_sleepable_preload+0x522e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21038ULL;
	}
x86_l_3ace:
	/* 0x3ace: cmp    WORD PTR [r13+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_3ad7:
	/* 0x3ad7: je     4f54 <generic_sleepable_preload+0x4f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20308ULL;
	}
x86_l_3add:
	/* 0x3add: mov    eax,DWORD PTR [r13+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_3ae4:
	/* 0x3ae4: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3ae8:
	/* 0x3ae8: cmp    WORD PTR [r13+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_3af1:
	/* 0x3af1: je     3b0e <generic_sleepable_preload+0x3b0e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3b0e;
	}
x86_l_3af3:
	/* 0x3af3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3af8:
	/* 0x3af8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3afc:
	/* 0x3afc: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3aff:
	/* 0x3aff: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b04:
	/* 0x3b04: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b06:
	/* 0x3b06: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3b08:
	/* 0x3b08: js     52b4 <generic_sleepable_preload+0x52b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21172ULL;
	}
x86_l_3b0e:
	/* 0x3b0e: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3b13:
	/* 0x3b13: cmp    WORD PTR [r13+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_3b1c:
	/* 0x3b1c: je     4f54 <generic_sleepable_preload+0x4f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20308ULL;
	}
x86_l_3b22:
	/* 0x3b22: mov    eax,DWORD PTR [r13+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_3b29:
	/* 0x3b29: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3b2d:
	/* 0x3b2d: cmp    WORD PTR [r13+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_3b36:
	/* 0x3b36: je     4f54 <generic_sleepable_preload+0x4f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20308ULL;
	}
x86_l_3b3c:
	/* 0x3b3c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3b41:
	/* 0x3b41: jmp    3d9e <generic_sleepable_preload+0x3d9e> */
	return 15774ULL;
x86_l_3b46:
	/* 0x3b46: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_3b49:
	/* 0x3b49: je     3b66 <generic_sleepable_preload+0x3b66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3b66;
	}
x86_l_3b4b:
	/* 0x3b4b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3b50:
	/* 0x3b50: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3b54:
	/* 0x3b54: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3b57:
	/* 0x3b57: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b5c:
	/* 0x3b5c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b5e:
	/* 0x3b5e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3b60:
	/* 0x3b60: js     3dbe <generic_sleepable_preload+0x3dbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15806ULL;
	}
x86_l_3b66:
	/* 0x3b66: cmp    WORD PTR [r13+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_3b6f:
	/* 0x3b6f: je     4f54 <generic_sleepable_preload+0x4f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20308ULL;
	}
x86_l_3b75:
	/* 0x3b75: mov    eax,DWORD PTR [r13+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_3b7c:
	/* 0x3b7c: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3b80:
	/* 0x3b80: cmp    WORD PTR [r13+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_3b89:
	/* 0x3b89: je     3ba6 <generic_sleepable_preload+0x3ba6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ba6;
	}
x86_l_3b8b:
	/* 0x3b8b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3b90:
	/* 0x3b90: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3b94:
	/* 0x3b94: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3b97:
	/* 0x3b97: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b9c:
	/* 0x3b9c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b9e:
	/* 0x3b9e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3ba0:
	/* 0x3ba0: js     440c <generic_sleepable_preload+0x440c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 17420ULL;
	}
x86_l_3ba6:
	/* 0x3ba6: cmp    WORD PTR [r13+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_3baf:
	/* 0x3baf: je     4f54 <generic_sleepable_preload+0x4f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20308ULL;
	}
x86_l_3bb5:
	/* 0x3bb5: mov    eax,DWORD PTR [r13+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_3bbc:
	/* 0x3bbc: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3bc0:
	/* 0x3bc0: cmp    WORD PTR [r13+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_3bc9:
	/* 0x3bc9: je     3be6 <generic_sleepable_preload+0x3be6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3be6;
	}
x86_l_3bcb:
	/* 0x3bcb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3bd0:
	/* 0x3bd0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3bd4:
	/* 0x3bd4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3bd7:
	/* 0x3bd7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3bdc:
	/* 0x3bdc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3bde:
	/* 0x3bde: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3be0:
	/* 0x3be0: js     4eb5 <generic_sleepable_preload+0x4eb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20149ULL;
	}
x86_l_3be6:
	/* 0x3be6: cmp    WORD PTR [r13+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_3bef:
	/* 0x3bef: je     4f54 <generic_sleepable_preload+0x4f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20308ULL;
	}
x86_l_3bf5:
	/* 0x3bf5: mov    eax,DWORD PTR [r13+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_3bfc:
	/* 0x3bfc: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3c00:
	/* 0x3c00: cmp    WORD PTR [r13+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_3c09:
	/* 0x3c09: je     3c26 <generic_sleepable_preload+0x3c26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c26;
	}
x86_l_3c0b:
	/* 0x3c0b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3c10:
	/* 0x3c10: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c14:
	/* 0x3c14: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3c17:
	/* 0x3c17: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c1c:
	/* 0x3c1c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c1e:
	/* 0x3c1e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3c20:
	/* 0x3c20: js     4edd <generic_sleepable_preload+0x4edd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20189ULL;
	}
x86_l_3c26:
	/* 0x3c26: cmp    WORD PTR [r13+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_3c2f:
	/* 0x3c2f: je     4f54 <generic_sleepable_preload+0x4f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20308ULL;
	}
x86_l_3c35:
	/* 0x3c35: mov    eax,DWORD PTR [r13+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_3c3c:
	/* 0x3c3c: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3c40:
	/* 0x3c40: cmp    WORD PTR [r13+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_3c49:
	/* 0x3c49: je     3c66 <generic_sleepable_preload+0x3c66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c66;
	}
x86_l_3c4b:
	/* 0x3c4b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3c50:
	/* 0x3c50: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c54:
	/* 0x3c54: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3c57:
	/* 0x3c57: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c5c:
	/* 0x3c5c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c5e:
	/* 0x3c5e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3c60:
	/* 0x3c60: js     4f02 <generic_sleepable_preload+0x4f02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20226ULL;
	}
x86_l_3c66:
	/* 0x3c66: cmp    WORD PTR [r13+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_3c6f:
	/* 0x3c6f: je     4f54 <generic_sleepable_preload+0x4f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20308ULL;
	}
x86_l_3c75:
	/* 0x3c75: mov    eax,DWORD PTR [r13+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_3c7c:
	/* 0x3c7c: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3c80:
	/* 0x3c80: cmp    WORD PTR [r13+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_3c89:
	/* 0x3c89: je     3ca6 <generic_sleepable_preload+0x3ca6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ca6;
	}
x86_l_3c8b:
	/* 0x3c8b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3c90:
	/* 0x3c90: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c94:
	/* 0x3c94: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3c97:
	/* 0x3c97: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c9c:
	/* 0x3c9c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c9e:
	/* 0x3c9e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3ca0:
	/* 0x3ca0: js     4f27 <generic_sleepable_preload+0x4f27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20263ULL;
	}
x86_l_3ca6:
	/* 0x3ca6: cmp    WORD PTR [r13+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_3caf:
	/* 0x3caf: je     4f54 <generic_sleepable_preload+0x4f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20308ULL;
	}
x86_l_3cb5:
	/* 0x3cb5: mov    eax,DWORD PTR [r13+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_3cbc:
	/* 0x3cbc: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3cc0:
	/* 0x3cc0: cmp    WORD PTR [r13+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_3cc9:
	/* 0x3cc9: je     3ce6 <generic_sleepable_preload+0x3ce6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ce6;
	}
x86_l_3ccb:
	/* 0x3ccb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3cd0:
	/* 0x3cd0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3cd4:
	/* 0x3cd4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3cd7:
	/* 0x3cd7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3cdc:
	/* 0x3cdc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3cde:
	/* 0x3cde: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3ce0:
	/* 0x3ce0: js     4f4c <generic_sleepable_preload+0x4f4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20300ULL;
	}
x86_l_3ce6:
	/* 0x3ce6: cmp    WORD PTR [r13+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_3cef:
	/* 0x3cef: je     4f54 <generic_sleepable_preload+0x4f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20308ULL;
	}
x86_l_3cf5:
	/* 0x3cf5: mov    eax,DWORD PTR [r13+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_3cfc:
	/* 0x3cfc: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3d00:
	/* 0x3d00: cmp    WORD PTR [r13+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_3d09:
	/* 0x3d09: je     3d26 <generic_sleepable_preload+0x3d26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15654ULL;
	}
x86_l_3d0b:
	/* 0x3d0b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3d10:
	/* 0x3d10: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3d14:
	/* 0x3d14: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3d17:
	/* 0x3d17: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
	return 15644ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_9(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 15644ULL: goto x86_l_3d1c;
	case 15646ULL: goto x86_l_3d1e;
	case 15648ULL: goto x86_l_3d20;
	case 15654ULL: goto x86_l_3d26;
	case 15659ULL: goto x86_l_3d2b;
	case 15668ULL: goto x86_l_3d34;
	case 15674ULL: goto x86_l_3d3a;
	case 15681ULL: goto x86_l_3d41;
	case 15685ULL: goto x86_l_3d45;
	case 15694ULL: goto x86_l_3d4e;
	case 15696ULL: goto x86_l_3d50;
	case 15701ULL: goto x86_l_3d55;
	case 15705ULL: goto x86_l_3d59;
	case 15708ULL: goto x86_l_3d5c;
	case 15713ULL: goto x86_l_3d61;
	case 15715ULL: goto x86_l_3d63;
	case 15717ULL: goto x86_l_3d65;
	case 15723ULL: goto x86_l_3d6b;
	case 15728ULL: goto x86_l_3d70;
	case 15737ULL: goto x86_l_3d79;
	case 15743ULL: goto x86_l_3d7f;
	case 15750ULL: goto x86_l_3d86;
	case 15754ULL: goto x86_l_3d8a;
	case 15763ULL: goto x86_l_3d93;
	case 15769ULL: goto x86_l_3d99;
	case 15774ULL: goto x86_l_3d9e;
	case 15778ULL: goto x86_l_3da2;
	case 15781ULL: goto x86_l_3da5;
	case 15786ULL: goto x86_l_3daa;
	case 15788ULL: goto x86_l_3dac;
	case 15790ULL: goto x86_l_3dae;
	case 15796ULL: goto x86_l_3db4;
	case 15801ULL: goto x86_l_3db9;
	case 15806ULL: goto x86_l_3dbe;
	case 15811ULL: goto x86_l_3dc3;
	case 15816ULL: goto x86_l_3dc8;
	case 15821ULL: goto x86_l_3dcd;
	case 15824ULL: goto x86_l_3dd0;
	case 15828ULL: goto x86_l_3dd4;
	case 15830ULL: goto x86_l_3dd6;
	case 15833ULL: goto x86_l_3dd9;
	case 15838ULL: goto x86_l_3dde;
	case 15846ULL: goto x86_l_3de6;
	case 15852ULL: goto x86_l_3dec;
	case 15859ULL: goto x86_l_3df3;
	case 15862ULL: goto x86_l_3df6;
	case 15868ULL: goto x86_l_3dfc;
	case 15871ULL: goto x86_l_3dff;
	case 15875ULL: goto x86_l_3e03;
	case 15882ULL: goto x86_l_3e0a;
	case 15884ULL: goto x86_l_3e0c;
	case 15890ULL: goto x86_l_3e12;
	case 15893ULL: goto x86_l_3e15;
	case 15895ULL: goto x86_l_3e17;
	case 15900ULL: goto x86_l_3e1c;
	case 15904ULL: goto x86_l_3e20;
	case 15907ULL: goto x86_l_3e23;
	case 15912ULL: goto x86_l_3e28;
	case 15914ULL: goto x86_l_3e2a;
	case 15916ULL: goto x86_l_3e2c;
	case 15922ULL: goto x86_l_3e32;
	case 15927ULL: goto x86_l_3e37;
	case 15935ULL: goto x86_l_3e3f;
	case 15941ULL: goto x86_l_3e45;
	case 15947ULL: goto x86_l_3e4b;
	case 15951ULL: goto x86_l_3e4f;
	case 15959ULL: goto x86_l_3e57;
	case 15961ULL: goto x86_l_3e59;
	case 15966ULL: goto x86_l_3e5e;
	case 15970ULL: goto x86_l_3e62;
	case 15973ULL: goto x86_l_3e65;
	case 15978ULL: goto x86_l_3e6a;
	case 15980ULL: goto x86_l_3e6c;
	case 15982ULL: goto x86_l_3e6e;
	case 15988ULL: goto x86_l_3e74;
	case 15993ULL: goto x86_l_3e79;
	case 16001ULL: goto x86_l_3e81;
	case 16007ULL: goto x86_l_3e87;
	case 16013ULL: goto x86_l_3e8d;
	case 16017ULL: goto x86_l_3e91;
	case 16025ULL: goto x86_l_3e99;
	case 16027ULL: goto x86_l_3e9b;
	case 16032ULL: goto x86_l_3ea0;
	case 16036ULL: goto x86_l_3ea4;
	case 16039ULL: goto x86_l_3ea7;
	case 16044ULL: goto x86_l_3eac;
	case 16046ULL: goto x86_l_3eae;
	case 16048ULL: goto x86_l_3eb0;
	case 16054ULL: goto x86_l_3eb6;
	case 16059ULL: goto x86_l_3ebb;
	case 16067ULL: goto x86_l_3ec3;
	case 16073ULL: goto x86_l_3ec9;
	case 16079ULL: goto x86_l_3ecf;
	case 16083ULL: goto x86_l_3ed3;
	case 16091ULL: goto x86_l_3edb;
	case 16093ULL: goto x86_l_3edd;
	case 16098ULL: goto x86_l_3ee2;
	case 16102ULL: goto x86_l_3ee6;
	case 16105ULL: goto x86_l_3ee9;
	case 16110ULL: goto x86_l_3eee;
	case 16112ULL: goto x86_l_3ef0;
	case 16114ULL: goto x86_l_3ef2;
	case 16120ULL: goto x86_l_3ef8;
	case 16125ULL: goto x86_l_3efd;
	case 16133ULL: goto x86_l_3f05;
	case 16139ULL: goto x86_l_3f0b;
	case 16145ULL: goto x86_l_3f11;
	case 16149ULL: goto x86_l_3f15;
	case 16157ULL: goto x86_l_3f1d;
	case 16159ULL: goto x86_l_3f1f;
	case 16164ULL: goto x86_l_3f24;
	case 16168ULL: goto x86_l_3f28;
	case 16171ULL: goto x86_l_3f2b;
	case 16176ULL: goto x86_l_3f30;
	case 16178ULL: goto x86_l_3f32;
	case 16180ULL: goto x86_l_3f34;
	case 16186ULL: goto x86_l_3f3a;
	case 16191ULL: goto x86_l_3f3f;
	case 16199ULL: goto x86_l_3f47;
	case 16205ULL: goto x86_l_3f4d;
	case 16211ULL: goto x86_l_3f53;
	case 16215ULL: goto x86_l_3f57;
	case 16223ULL: goto x86_l_3f5f;
	case 16225ULL: goto x86_l_3f61;
	case 16230ULL: goto x86_l_3f66;
	case 16234ULL: goto x86_l_3f6a;
	case 16237ULL: goto x86_l_3f6d;
	case 16242ULL: goto x86_l_3f72;
	case 16244ULL: goto x86_l_3f74;
	case 16246ULL: goto x86_l_3f76;
	case 16252ULL: goto x86_l_3f7c;
	case 16257ULL: goto x86_l_3f81;
	case 16265ULL: goto x86_l_3f89;
	case 16271ULL: goto x86_l_3f8f;
	case 16277ULL: goto x86_l_3f95;
	case 16281ULL: goto x86_l_3f99;
	case 16289ULL: goto x86_l_3fa1;
	case 16291ULL: goto x86_l_3fa3;
	case 16296ULL: goto x86_l_3fa8;
	case 16300ULL: goto x86_l_3fac;
	case 16303ULL: goto x86_l_3faf;
	case 16308ULL: goto x86_l_3fb4;
	case 16310ULL: goto x86_l_3fb6;
	case 16312ULL: goto x86_l_3fb8;
	case 16318ULL: goto x86_l_3fbe;
	case 16323ULL: goto x86_l_3fc3;
	case 16331ULL: goto x86_l_3fcb;
	case 16337ULL: goto x86_l_3fd1;
	case 16343ULL: goto x86_l_3fd7;
	case 16347ULL: goto x86_l_3fdb;
	case 16355ULL: goto x86_l_3fe3;
	case 16357ULL: goto x86_l_3fe5;
	case 16362ULL: goto x86_l_3fea;
	case 16366ULL: goto x86_l_3fee;
	case 16369ULL: goto x86_l_3ff1;
	case 16374ULL: goto x86_l_3ff6;
	case 16376ULL: goto x86_l_3ff8;
	case 16378ULL: goto x86_l_3ffa;
	case 16384ULL: goto x86_l_4000;
	case 16389ULL: goto x86_l_4005;
	case 16397ULL: goto x86_l_400d;
	case 16403ULL: goto x86_l_4013;
	case 16409ULL: goto x86_l_4019;
	case 16413ULL: goto x86_l_401d;
	case 16421ULL: goto x86_l_4025;
	case 16423ULL: goto x86_l_4027;
	case 16428ULL: goto x86_l_402c;
	case 16432ULL: goto x86_l_4030;
	case 16435ULL: goto x86_l_4033;
	case 16440ULL: goto x86_l_4038;
	case 16442ULL: goto x86_l_403a;
	case 16444ULL: goto x86_l_403c;
	case 16450ULL: goto x86_l_4042;
	case 16455ULL: goto x86_l_4047;
	case 16463ULL: goto x86_l_404f;
	case 16469ULL: goto x86_l_4055;
	case 16475ULL: goto x86_l_405b;
	case 16479ULL: goto x86_l_405f;
	case 16487ULL: goto x86_l_4067;
	case 16493ULL: goto x86_l_406d;
	case 16498ULL: goto x86_l_4072;
	case 16503ULL: goto x86_l_4077;
	case 16506ULL: goto x86_l_407a;
	case 16508ULL: goto x86_l_407c;
	case 16513ULL: goto x86_l_4081;
	case 16517ULL: goto x86_l_4085;
	case 16520ULL: goto x86_l_4088;
	case 16525ULL: goto x86_l_408d;
	case 16527ULL: goto x86_l_408f;
	case 16529ULL: goto x86_l_4091;
	case 16535ULL: goto x86_l_4097;
	case 16540ULL: goto x86_l_409c;
	case 16548ULL: goto x86_l_40a4;
	case 16554ULL: goto x86_l_40aa;
	case 16560ULL: goto x86_l_40b0;
	case 16564ULL: goto x86_l_40b4;
	case 16572ULL: goto x86_l_40bc;
	case 16574ULL: goto x86_l_40be;
	case 16579ULL: goto x86_l_40c3;
	case 16583ULL: goto x86_l_40c7;
	case 16586ULL: goto x86_l_40ca;
	case 16591ULL: goto x86_l_40cf;
	case 16593ULL: goto x86_l_40d1;
	case 16595ULL: goto x86_l_40d3;
	case 16601ULL: goto x86_l_40d9;
	case 16606ULL: goto x86_l_40de;
	case 16614ULL: goto x86_l_40e6;
	case 16620ULL: goto x86_l_40ec;
	case 16626ULL: goto x86_l_40f2;
	case 16630ULL: goto x86_l_40f6;
	case 16638ULL: goto x86_l_40fe;
	case 16640ULL: goto x86_l_4100;
	case 16645ULL: goto x86_l_4105;
	case 16649ULL: goto x86_l_4109;
	case 16652ULL: goto x86_l_410c;
	case 16657ULL: goto x86_l_4111;
	case 16659ULL: goto x86_l_4113;
	case 16661ULL: goto x86_l_4115;
	case 16667ULL: goto x86_l_411b;
	case 16672ULL: goto x86_l_4120;
	case 16680ULL: goto x86_l_4128;
	case 16686ULL: goto x86_l_412e;
	case 16692ULL: goto x86_l_4134;
	case 16696ULL: goto x86_l_4138;
	case 16704ULL: goto x86_l_4140;
	case 16706ULL: goto x86_l_4142;
	case 16711ULL: goto x86_l_4147;
	case 16715ULL: goto x86_l_414b;
	case 16718ULL: goto x86_l_414e;
	case 16723ULL: goto x86_l_4153;
	case 16725ULL: goto x86_l_4155;
	case 16727ULL: goto x86_l_4157;
	case 16733ULL: goto x86_l_415d;
	case 16738ULL: goto x86_l_4162;
	case 16746ULL: goto x86_l_416a;
	case 16752ULL: goto x86_l_4170;
	case 16758ULL: goto x86_l_4176;
	case 16762ULL: goto x86_l_417a;
	case 16770ULL: goto x86_l_4182;
	case 16772ULL: goto x86_l_4184;
	case 16777ULL: goto x86_l_4189;
	case 16781ULL: goto x86_l_418d;
	case 16784ULL: goto x86_l_4190;
	case 16789ULL: goto x86_l_4195;
	case 16791ULL: goto x86_l_4197;
	case 16793ULL: goto x86_l_4199;
	case 16799ULL: goto x86_l_419f;
	case 16804ULL: goto x86_l_41a4;
	case 16812ULL: goto x86_l_41ac;
	case 16818ULL: goto x86_l_41b2;
	case 16824ULL: goto x86_l_41b8;
	case 16828ULL: goto x86_l_41bc;
	case 16836ULL: goto x86_l_41c4;
	case 16838ULL: goto x86_l_41c6;
	case 16843ULL: goto x86_l_41cb;
	case 16847ULL: goto x86_l_41cf;
	case 16850ULL: goto x86_l_41d2;
	case 16855ULL: goto x86_l_41d7;
	case 16857ULL: goto x86_l_41d9;
	case 16859ULL: goto x86_l_41db;
	case 16865ULL: goto x86_l_41e1;
	case 16870ULL: goto x86_l_41e6;
	case 16878ULL: goto x86_l_41ee;
	case 16884ULL: goto x86_l_41f4;
	case 16890ULL: goto x86_l_41fa;
	case 16894ULL: goto x86_l_41fe;
	case 16902ULL: goto x86_l_4206;
	case 16904ULL: goto x86_l_4208;
	case 16909ULL: goto x86_l_420d;
	case 16913ULL: goto x86_l_4211;
	case 16916ULL: goto x86_l_4214;
	case 16921ULL: goto x86_l_4219;
	case 16923ULL: goto x86_l_421b;
	case 16925ULL: goto x86_l_421d;
	case 16931ULL: goto x86_l_4223;
	case 16936ULL: goto x86_l_4228;
	case 16944ULL: goto x86_l_4230;
	case 16950ULL: goto x86_l_4236;
	case 16956ULL: goto x86_l_423c;
	case 16960ULL: goto x86_l_4240;
	case 16968ULL: goto x86_l_4248;
	case 16970ULL: goto x86_l_424a;
	case 16975ULL: goto x86_l_424f;
	case 16979ULL: goto x86_l_4253;
	case 16982ULL: goto x86_l_4256;
	case 16987ULL: goto x86_l_425b;
	case 16989ULL: goto x86_l_425d;
	case 16991ULL: goto x86_l_425f;
	case 16997ULL: goto x86_l_4265;
	case 17002ULL: goto x86_l_426a;
	case 17010ULL: goto x86_l_4272;
	case 17016ULL: goto x86_l_4278;
	case 17022ULL: goto x86_l_427e;
	case 17026ULL: goto x86_l_4282;
	case 17034ULL: goto x86_l_428a;
	case 17036ULL: goto x86_l_428c;
	case 17041ULL: goto x86_l_4291;
	case 17045ULL: goto x86_l_4295;
	case 17048ULL: goto x86_l_4298;
	case 17053ULL: goto x86_l_429d;
	case 17055ULL: goto x86_l_429f;
	case 17057ULL: goto x86_l_42a1;
	case 17063ULL: goto x86_l_42a7;
	case 17068ULL: goto x86_l_42ac;
	case 17076ULL: goto x86_l_42b4;
	case 17082ULL: goto x86_l_42ba;
	case 17088ULL: goto x86_l_42c0;
	case 17092ULL: goto x86_l_42c4;
	case 17100ULL: goto x86_l_42cc;
	case 17106ULL: goto x86_l_42d2;
	case 17111ULL: goto x86_l_42d7;
	case 17115ULL: goto x86_l_42db;
	case 17118ULL: goto x86_l_42de;
	case 17123ULL: goto x86_l_42e3;
	case 17125ULL: goto x86_l_42e5;
	case 17127ULL: goto x86_l_42e7;
	case 17133ULL: goto x86_l_42ed;
	case 17138ULL: goto x86_l_42f2;
	case 17143ULL: goto x86_l_42f7;
	case 17148ULL: goto x86_l_42fc;
	case 17153ULL: goto x86_l_4301;
	case 17161ULL: goto x86_l_4309;
	case 17164ULL: goto x86_l_430c;
	case 17170ULL: goto x86_l_4312;
	case 17175ULL: goto x86_l_4317;
	case 17178ULL: goto x86_l_431a;
	case 17184ULL: goto x86_l_4320;
	case 17189ULL: goto x86_l_4325;
	case 17197ULL: goto x86_l_432d;
	case 17200ULL: goto x86_l_4330;
	case 17206ULL: goto x86_l_4336;
	case 17211ULL: goto x86_l_433b;
	case 17214ULL: goto x86_l_433e;
	case 17220ULL: goto x86_l_4344;
	case 17225ULL: goto x86_l_4349;
	case 17233ULL: goto x86_l_4351;
	case 17236ULL: goto x86_l_4354;
	case 17242ULL: goto x86_l_435a;
	case 17247ULL: goto x86_l_435f;
	case 17250ULL: goto x86_l_4362;
	case 17256ULL: goto x86_l_4368;
	case 17261ULL: goto x86_l_436d;
	case 17269ULL: goto x86_l_4375;
	case 17272ULL: goto x86_l_4378;
	case 17278ULL: goto x86_l_437e;
	case 17283ULL: goto x86_l_4383;
	case 17286ULL: goto x86_l_4386;
	case 17292ULL: goto x86_l_438c;
	case 17297ULL: goto x86_l_4391;
	case 17305ULL: goto x86_l_4399;
	case 17308ULL: goto x86_l_439c;
	case 17314ULL: goto x86_l_43a2;
	case 17319ULL: goto x86_l_43a7;
	case 17322ULL: goto x86_l_43aa;
	case 17324ULL: goto x86_l_43ac;
	case 17329ULL: goto x86_l_43b1;
	case 17337ULL: goto x86_l_43b9;
	case 17340ULL: goto x86_l_43bc;
	case 17346ULL: goto x86_l_43c2;
	case 17351ULL: goto x86_l_43c7;
	case 17354ULL: goto x86_l_43ca;
	case 17360ULL: goto x86_l_43d0;
	case 17365ULL: goto x86_l_43d5;
	case 17370ULL: goto x86_l_43da;
	case 17373ULL: goto x86_l_43dd;
	case 17375ULL: goto x86_l_43df;
	case 17380ULL: goto x86_l_43e4;
	case 17383ULL: goto x86_l_43e7;
	case 17385ULL: goto x86_l_43e9;
	case 17387ULL: goto x86_l_43eb;
	case 17392ULL: goto x86_l_43f0;
	case 17395ULL: goto x86_l_43f3;
	case 17401ULL: goto x86_l_43f9;
	case 17406ULL: goto x86_l_43fe;
	case 17409ULL: goto x86_l_4401;
	case 17415ULL: goto x86_l_4407;
	case 17420ULL: goto x86_l_440c;
	case 17425ULL: goto x86_l_4411;
	case 17430ULL: goto x86_l_4416;
	case 17435ULL: goto x86_l_441b;
	case 17440ULL: goto x86_l_4420;
	case 17445ULL: goto x86_l_4425;
	case 17448ULL: goto x86_l_4428;
	case 17450ULL: goto x86_l_442a;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3d1c:
	/* 0x3d1c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d1e:
	/* 0x3d1e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3d20:
	/* 0x3d20: js     5358 <generic_sleepable_preload+0x5358> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21336ULL;
	}
x86_l_3d26:
	/* 0x3d26: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d2b:
	/* 0x3d2b: cmp    WORD PTR [r13+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_3d34:
	/* 0x3d34: je     4f54 <generic_sleepable_preload+0x4f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20308ULL;
	}
x86_l_3d3a:
	/* 0x3d3a: mov    eax,DWORD PTR [r13+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_3d41:
	/* 0x3d41: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3d45:
	/* 0x3d45: cmp    WORD PTR [r13+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_3d4e:
	/* 0x3d4e: je     3d6b <generic_sleepable_preload+0x3d6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3d6b;
	}
x86_l_3d50:
	/* 0x3d50: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3d55:
	/* 0x3d55: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3d59:
	/* 0x3d59: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3d5c:
	/* 0x3d5c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d61:
	/* 0x3d61: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d63:
	/* 0x3d63: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3d65:
	/* 0x3d65: js     52b4 <generic_sleepable_preload+0x52b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21172ULL;
	}
x86_l_3d6b:
	/* 0x3d6b: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d70:
	/* 0x3d70: cmp    WORD PTR [r13+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_3d79:
	/* 0x3d79: je     4f54 <generic_sleepable_preload+0x4f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20308ULL;
	}
x86_l_3d7f:
	/* 0x3d7f: mov    eax,DWORD PTR [r13+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_3d86:
	/* 0x3d86: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3d8a:
	/* 0x3d8a: cmp    WORD PTR [r13+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_3d93:
	/* 0x3d93: je     4f54 <generic_sleepable_preload+0x4f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20308ULL;
	}
x86_l_3d99:
	/* 0x3d99: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3d9e:
	/* 0x3d9e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3da2:
	/* 0x3da2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3da5:
	/* 0x3da5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3daa:
	/* 0x3daa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3dac:
	/* 0x3dac: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3dae:
	/* 0x3dae: jns    4f54 <generic_sleepable_preload+0x4f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 20308ULL;
	}
x86_l_3db4:
	/* 0x3db4: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_3db9:
	/* 0x3db9: jmp    4f51 <generic_sleepable_preload+0x4f51> */
	return 20305ULL;
x86_l_3dbe:
	/* 0x3dbe: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_3dc3:
	/* 0x3dc3: jmp    4f51 <generic_sleepable_preload+0x4f51> */
	return 20305ULL;
x86_l_3dc8:
	/* 0x3dc8: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3dcd:
	/* 0x3dcd: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3dd0:
	/* 0x3dd0: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3dd4:
	/* 0x3dd4: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3dd6:
	/* 0x3dd6: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_3dd9:
	/* 0x3dd9: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3dde:
	/* 0x3dde: cmp    WORD PTR [rsi+0x1b6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1881195675648ULL);
x86_l_3de6:
	/* 0x3de6: je     4fd9 <generic_sleepable_preload+0x4fd9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20441ULL;
	}
x86_l_3dec:
	/* 0x3dec: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_3df3:
	/* 0x3df3: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_3df6:
	/* 0x3df6: mov    edx,DWORD PTR [rsi+0x1b0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 432ULL);
x86_l_3dfc:
	/* 0x3dfc: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3dff:
	/* 0x3dff: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e03:
	/* 0x3e03: movzx  eax,WORD PTR [rsi+0x1b4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 436ULL);
x86_l_3e0a:
	/* 0x3e0a: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_3e0c:
	/* 0x3e0c: je     4077 <generic_sleepable_preload+0x4077> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4077;
	}
x86_l_3e12:
	/* 0x3e12: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_3e15:
	/* 0x3e15: je     3e32 <generic_sleepable_preload+0x3e32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e32;
	}
x86_l_3e17:
	/* 0x3e17: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3e1c:
	/* 0x3e1c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e20:
	/* 0x3e20: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3e23:
	/* 0x3e23: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3e28:
	/* 0x3e28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e2a:
	/* 0x3e2a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3e2c:
	/* 0x3e2c: js     42f7 <generic_sleepable_preload+0x42f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_42f7;
	}
x86_l_3e32:
	/* 0x3e32: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3e37:
	/* 0x3e37: cmp    WORD PTR [rcx+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_3e3f:
	/* 0x3e3f: je     4fd9 <generic_sleepable_preload+0x4fd9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20441ULL;
	}
x86_l_3e45:
	/* 0x3e45: mov    eax,DWORD PTR [rcx+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_3e4b:
	/* 0x3e4b: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3e4f:
	/* 0x3e4f: cmp    WORD PTR [rcx+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_3e57:
	/* 0x3e57: je     3e74 <generic_sleepable_preload+0x3e74> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e74;
	}
x86_l_3e59:
	/* 0x3e59: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3e5e:
	/* 0x3e5e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e62:
	/* 0x3e62: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3e65:
	/* 0x3e65: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3e6a:
	/* 0x3e6a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e6c:
	/* 0x3e6c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3e6e:
	/* 0x3e6e: js     4416 <generic_sleepable_preload+0x4416> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4416;
	}
x86_l_3e74:
	/* 0x3e74: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3e79:
	/* 0x3e79: cmp    WORD PTR [rcx+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_3e81:
	/* 0x3e81: je     4fd9 <generic_sleepable_preload+0x4fd9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20441ULL;
	}
x86_l_3e87:
	/* 0x3e87: mov    eax,DWORD PTR [rcx+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_3e8d:
	/* 0x3e8d: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3e91:
	/* 0x3e91: cmp    WORD PTR [rcx+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_3e99:
	/* 0x3e99: je     3eb6 <generic_sleepable_preload+0x3eb6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3eb6;
	}
x86_l_3e9b:
	/* 0x3e9b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3ea0:
	/* 0x3ea0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ea4:
	/* 0x3ea4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3ea7:
	/* 0x3ea7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3eac:
	/* 0x3eac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3eae:
	/* 0x3eae: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3eb0:
	/* 0x3eb0: js     4ebf <generic_sleepable_preload+0x4ebf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20159ULL;
	}
x86_l_3eb6:
	/* 0x3eb6: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ebb:
	/* 0x3ebb: cmp    WORD PTR [rcx+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_3ec3:
	/* 0x3ec3: je     4fd9 <generic_sleepable_preload+0x4fd9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20441ULL;
	}
x86_l_3ec9:
	/* 0x3ec9: mov    eax,DWORD PTR [rcx+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_3ecf:
	/* 0x3ecf: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3ed3:
	/* 0x3ed3: cmp    WORD PTR [rcx+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_3edb:
	/* 0x3edb: je     3ef8 <generic_sleepable_preload+0x3ef8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ef8;
	}
x86_l_3edd:
	/* 0x3edd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3ee2:
	/* 0x3ee2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ee6:
	/* 0x3ee6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3ee9:
	/* 0x3ee9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3eee:
	/* 0x3eee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ef0:
	/* 0x3ef0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3ef2:
	/* 0x3ef2: js     4ee4 <generic_sleepable_preload+0x4ee4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20196ULL;
	}
x86_l_3ef8:
	/* 0x3ef8: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3efd:
	/* 0x3efd: cmp    WORD PTR [rcx+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_3f05:
	/* 0x3f05: je     4fd9 <generic_sleepable_preload+0x4fd9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20441ULL;
	}
x86_l_3f0b:
	/* 0x3f0b: mov    eax,DWORD PTR [rcx+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_3f11:
	/* 0x3f11: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3f15:
	/* 0x3f15: cmp    WORD PTR [rcx+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_3f1d:
	/* 0x3f1d: je     3f3a <generic_sleepable_preload+0x3f3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3f3a;
	}
x86_l_3f1f:
	/* 0x3f1f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3f24:
	/* 0x3f24: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f28:
	/* 0x3f28: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3f2b:
	/* 0x3f2b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3f30:
	/* 0x3f30: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f32:
	/* 0x3f32: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3f34:
	/* 0x3f34: js     4f09 <generic_sleepable_preload+0x4f09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20233ULL;
	}
x86_l_3f3a:
	/* 0x3f3a: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3f3f:
	/* 0x3f3f: cmp    WORD PTR [rcx+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_3f47:
	/* 0x3f47: je     4fd9 <generic_sleepable_preload+0x4fd9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20441ULL;
	}
x86_l_3f4d:
	/* 0x3f4d: mov    eax,DWORD PTR [rcx+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_3f53:
	/* 0x3f53: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3f57:
	/* 0x3f57: cmp    WORD PTR [rcx+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_3f5f:
	/* 0x3f5f: je     3f7c <generic_sleepable_preload+0x3f7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3f7c;
	}
x86_l_3f61:
	/* 0x3f61: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3f66:
	/* 0x3f66: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f6a:
	/* 0x3f6a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3f6d:
	/* 0x3f6d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3f72:
	/* 0x3f72: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f74:
	/* 0x3f74: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3f76:
	/* 0x3f76: js     4f2e <generic_sleepable_preload+0x4f2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20270ULL;
	}
x86_l_3f7c:
	/* 0x3f7c: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3f81:
	/* 0x3f81: cmp    WORD PTR [rcx+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_3f89:
	/* 0x3f89: je     4fd9 <generic_sleepable_preload+0x4fd9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20441ULL;
	}
x86_l_3f8f:
	/* 0x3f8f: mov    eax,DWORD PTR [rcx+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_3f95:
	/* 0x3f95: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3f99:
	/* 0x3f99: cmp    WORD PTR [rcx+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_3fa1:
	/* 0x3fa1: je     3fbe <generic_sleepable_preload+0x3fbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3fbe;
	}
x86_l_3fa3:
	/* 0x3fa3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3fa8:
	/* 0x3fa8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3fac:
	/* 0x3fac: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3faf:
	/* 0x3faf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3fb4:
	/* 0x3fb4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3fb6:
	/* 0x3fb6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3fb8:
	/* 0x3fb8: js     4fd1 <generic_sleepable_preload+0x4fd1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20433ULL;
	}
x86_l_3fbe:
	/* 0x3fbe: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3fc3:
	/* 0x3fc3: cmp    WORD PTR [rcx+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_3fcb:
	/* 0x3fcb: je     4fd9 <generic_sleepable_preload+0x4fd9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20441ULL;
	}
x86_l_3fd1:
	/* 0x3fd1: mov    eax,DWORD PTR [rcx+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_3fd7:
	/* 0x3fd7: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3fdb:
	/* 0x3fdb: cmp    WORD PTR [rcx+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_3fe3:
	/* 0x3fe3: je     4000 <generic_sleepable_preload+0x4000> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4000;
	}
x86_l_3fe5:
	/* 0x3fe5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3fea:
	/* 0x3fea: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3fee:
	/* 0x3fee: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3ff1:
	/* 0x3ff1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3ff6:
	/* 0x3ff6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ff8:
	/* 0x3ff8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3ffa:
	/* 0x3ffa: js     51bd <generic_sleepable_preload+0x51bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20925ULL;
	}
x86_l_4000:
	/* 0x4000: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4005:
	/* 0x4005: cmp    WORD PTR [rcx+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_400d:
	/* 0x400d: je     4fd9 <generic_sleepable_preload+0x4fd9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20441ULL;
	}
x86_l_4013:
	/* 0x4013: mov    eax,DWORD PTR [rcx+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_4019:
	/* 0x4019: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_401d:
	/* 0x401d: cmp    WORD PTR [rcx+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_4025:
	/* 0x4025: je     4042 <generic_sleepable_preload+0x4042> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4042;
	}
x86_l_4027:
	/* 0x4027: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_402c:
	/* 0x402c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4030:
	/* 0x4030: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4033:
	/* 0x4033: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4038:
	/* 0x4038: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_403a:
	/* 0x403a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_403c:
	/* 0x403c: js     52c6 <generic_sleepable_preload+0x52c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21190ULL;
	}
x86_l_4042:
	/* 0x4042: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4047:
	/* 0x4047: cmp    WORD PTR [rcx+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_404f:
	/* 0x404f: je     4fd9 <generic_sleepable_preload+0x4fd9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20441ULL;
	}
x86_l_4055:
	/* 0x4055: mov    eax,DWORD PTR [rcx+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_405b:
	/* 0x405b: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_405f:
	/* 0x405f: cmp    WORD PTR [rcx+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_4067:
	/* 0x4067: je     4fd9 <generic_sleepable_preload+0x4fd9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20441ULL;
	}
x86_l_406d:
	/* 0x406d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4072:
	/* 0x4072: jmp    42d7 <generic_sleepable_preload+0x42d7> */
	goto x86_l_42d7;
x86_l_4077:
	/* 0x4077: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_407a:
	/* 0x407a: je     4097 <generic_sleepable_preload+0x4097> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4097;
	}
x86_l_407c:
	/* 0x407c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4081:
	/* 0x4081: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4085:
	/* 0x4085: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4088:
	/* 0x4088: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_408d:
	/* 0x408d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_408f:
	/* 0x408f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4091:
	/* 0x4091: js     42f7 <generic_sleepable_preload+0x42f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_42f7;
	}
x86_l_4097:
	/* 0x4097: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_409c:
	/* 0x409c: cmp    WORD PTR [rcx+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_40a4:
	/* 0x40a4: je     4fd9 <generic_sleepable_preload+0x4fd9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20441ULL;
	}
x86_l_40aa:
	/* 0x40aa: mov    eax,DWORD PTR [rcx+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_40b0:
	/* 0x40b0: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_40b4:
	/* 0x40b4: cmp    WORD PTR [rcx+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_40bc:
	/* 0x40bc: je     40d9 <generic_sleepable_preload+0x40d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40d9;
	}
x86_l_40be:
	/* 0x40be: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_40c3:
	/* 0x40c3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_40c7:
	/* 0x40c7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_40ca:
	/* 0x40ca: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_40cf:
	/* 0x40cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40d1:
	/* 0x40d1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_40d3:
	/* 0x40d3: js     4416 <generic_sleepable_preload+0x4416> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4416;
	}
x86_l_40d9:
	/* 0x40d9: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_40de:
	/* 0x40de: cmp    WORD PTR [rcx+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_40e6:
	/* 0x40e6: je     4fd9 <generic_sleepable_preload+0x4fd9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20441ULL;
	}
x86_l_40ec:
	/* 0x40ec: mov    eax,DWORD PTR [rcx+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_40f2:
	/* 0x40f2: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_40f6:
	/* 0x40f6: cmp    WORD PTR [rcx+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_40fe:
	/* 0x40fe: je     411b <generic_sleepable_preload+0x411b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_411b;
	}
x86_l_4100:
	/* 0x4100: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4105:
	/* 0x4105: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4109:
	/* 0x4109: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_410c:
	/* 0x410c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4111:
	/* 0x4111: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4113:
	/* 0x4113: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4115:
	/* 0x4115: js     4ebf <generic_sleepable_preload+0x4ebf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20159ULL;
	}
x86_l_411b:
	/* 0x411b: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4120:
	/* 0x4120: cmp    WORD PTR [rcx+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_4128:
	/* 0x4128: je     4fd9 <generic_sleepable_preload+0x4fd9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20441ULL;
	}
x86_l_412e:
	/* 0x412e: mov    eax,DWORD PTR [rcx+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_4134:
	/* 0x4134: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4138:
	/* 0x4138: cmp    WORD PTR [rcx+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_4140:
	/* 0x4140: je     415d <generic_sleepable_preload+0x415d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_415d;
	}
x86_l_4142:
	/* 0x4142: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4147:
	/* 0x4147: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_414b:
	/* 0x414b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_414e:
	/* 0x414e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4153:
	/* 0x4153: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4155:
	/* 0x4155: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4157:
	/* 0x4157: js     4ee4 <generic_sleepable_preload+0x4ee4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20196ULL;
	}
x86_l_415d:
	/* 0x415d: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4162:
	/* 0x4162: cmp    WORD PTR [rcx+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_416a:
	/* 0x416a: je     4fd9 <generic_sleepable_preload+0x4fd9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20441ULL;
	}
x86_l_4170:
	/* 0x4170: mov    eax,DWORD PTR [rcx+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_4176:
	/* 0x4176: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_417a:
	/* 0x417a: cmp    WORD PTR [rcx+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_4182:
	/* 0x4182: je     419f <generic_sleepable_preload+0x419f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_419f;
	}
x86_l_4184:
	/* 0x4184: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4189:
	/* 0x4189: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_418d:
	/* 0x418d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4190:
	/* 0x4190: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4195:
	/* 0x4195: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4197:
	/* 0x4197: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4199:
	/* 0x4199: js     4f09 <generic_sleepable_preload+0x4f09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20233ULL;
	}
x86_l_419f:
	/* 0x419f: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_41a4:
	/* 0x41a4: cmp    WORD PTR [rcx+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_41ac:
	/* 0x41ac: je     4fd9 <generic_sleepable_preload+0x4fd9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20441ULL;
	}
x86_l_41b2:
	/* 0x41b2: mov    eax,DWORD PTR [rcx+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_41b8:
	/* 0x41b8: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_41bc:
	/* 0x41bc: cmp    WORD PTR [rcx+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_41c4:
	/* 0x41c4: je     41e1 <generic_sleepable_preload+0x41e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_41e1;
	}
x86_l_41c6:
	/* 0x41c6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_41cb:
	/* 0x41cb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_41cf:
	/* 0x41cf: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_41d2:
	/* 0x41d2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_41d7:
	/* 0x41d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41d9:
	/* 0x41d9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_41db:
	/* 0x41db: js     4f2e <generic_sleepable_preload+0x4f2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20270ULL;
	}
x86_l_41e1:
	/* 0x41e1: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_41e6:
	/* 0x41e6: cmp    WORD PTR [rcx+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_41ee:
	/* 0x41ee: je     4fd9 <generic_sleepable_preload+0x4fd9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20441ULL;
	}
x86_l_41f4:
	/* 0x41f4: mov    eax,DWORD PTR [rcx+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_41fa:
	/* 0x41fa: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_41fe:
	/* 0x41fe: cmp    WORD PTR [rcx+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_4206:
	/* 0x4206: je     4223 <generic_sleepable_preload+0x4223> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4223;
	}
x86_l_4208:
	/* 0x4208: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_420d:
	/* 0x420d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4211:
	/* 0x4211: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4214:
	/* 0x4214: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4219:
	/* 0x4219: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_421b:
	/* 0x421b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_421d:
	/* 0x421d: js     4fd1 <generic_sleepable_preload+0x4fd1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20433ULL;
	}
x86_l_4223:
	/* 0x4223: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4228:
	/* 0x4228: cmp    WORD PTR [rcx+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_4230:
	/* 0x4230: je     4fd9 <generic_sleepable_preload+0x4fd9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20441ULL;
	}
x86_l_4236:
	/* 0x4236: mov    eax,DWORD PTR [rcx+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_423c:
	/* 0x423c: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4240:
	/* 0x4240: cmp    WORD PTR [rcx+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_4248:
	/* 0x4248: je     4265 <generic_sleepable_preload+0x4265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4265;
	}
x86_l_424a:
	/* 0x424a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_424f:
	/* 0x424f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4253:
	/* 0x4253: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4256:
	/* 0x4256: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_425b:
	/* 0x425b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_425d:
	/* 0x425d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_425f:
	/* 0x425f: js     51bd <generic_sleepable_preload+0x51bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20925ULL;
	}
x86_l_4265:
	/* 0x4265: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_426a:
	/* 0x426a: cmp    WORD PTR [rcx+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_4272:
	/* 0x4272: je     4fd9 <generic_sleepable_preload+0x4fd9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20441ULL;
	}
x86_l_4278:
	/* 0x4278: mov    eax,DWORD PTR [rcx+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_427e:
	/* 0x427e: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4282:
	/* 0x4282: cmp    WORD PTR [rcx+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_428a:
	/* 0x428a: je     42a7 <generic_sleepable_preload+0x42a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_42a7;
	}
x86_l_428c:
	/* 0x428c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4291:
	/* 0x4291: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4295:
	/* 0x4295: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4298:
	/* 0x4298: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_429d:
	/* 0x429d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_429f:
	/* 0x429f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_42a1:
	/* 0x42a1: js     52c6 <generic_sleepable_preload+0x52c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21190ULL;
	}
x86_l_42a7:
	/* 0x42a7: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_42ac:
	/* 0x42ac: cmp    WORD PTR [rcx+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_42b4:
	/* 0x42b4: je     4fd9 <generic_sleepable_preload+0x4fd9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20441ULL;
	}
x86_l_42ba:
	/* 0x42ba: mov    eax,DWORD PTR [rcx+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_42c0:
	/* 0x42c0: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_42c4:
	/* 0x42c4: cmp    WORD PTR [rcx+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_42cc:
	/* 0x42cc: je     4fd9 <generic_sleepable_preload+0x4fd9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20441ULL;
	}
x86_l_42d2:
	/* 0x42d2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_42d7:
	/* 0x42d7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_42db:
	/* 0x42db: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_42de:
	/* 0x42de: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_42e3:
	/* 0x42e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42e5:
	/* 0x42e5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_42e7:
	/* 0x42e7: jns    4fd9 <generic_sleepable_preload+0x4fd9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 20441ULL;
	}
x86_l_42ed:
	/* 0x42ed: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_42f2:
	/* 0x42f2: jmp    4fd6 <generic_sleepable_preload+0x4fd6> */
	return 20438ULL;
x86_l_42f7:
	/* 0x42f7: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_42fc:
	/* 0x42fc: jmp    4fd6 <generic_sleepable_preload+0x4fd6> */
	return 20438ULL;
x86_l_4301:
	/* 0x4301: mov    rsi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_4309:
	/* 0x4309: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_430c:
	/* 0x430c: je     4425 <generic_sleepable_preload+0x4425> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4425;
	}
x86_l_4312:
	/* 0x4312: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4317:
	/* 0x4317: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_431a:
	/* 0x431a: je     4425 <generic_sleepable_preload+0x4425> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4425;
	}
x86_l_4320:
	/* 0x4320: jmp    4438 <generic_sleepable_preload+0x4438> */
	return 17464ULL;
x86_l_4325:
	/* 0x4325: mov    rsi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_432d:
	/* 0x432d: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_4330:
	/* 0x4330: je     4965 <generic_sleepable_preload+0x4965> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18789ULL;
	}
x86_l_4336:
	/* 0x4336: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_433b:
	/* 0x433b: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_433e:
	/* 0x433e: je     4965 <generic_sleepable_preload+0x4965> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18789ULL;
	}
x86_l_4344:
	/* 0x4344: jmp    4978 <generic_sleepable_preload+0x4978> */
	return 18808ULL;
x86_l_4349:
	/* 0x4349: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_4351:
	/* 0x4351: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_4354:
	/* 0x4354: je     4425 <generic_sleepable_preload+0x4425> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4425;
	}
x86_l_435a:
	/* 0x435a: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_435f:
	/* 0x435f: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_4362:
	/* 0x4362: je     4425 <generic_sleepable_preload+0x4425> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4425;
	}
x86_l_4368:
	/* 0x4368: jmp    4438 <generic_sleepable_preload+0x4438> */
	return 17464ULL;
x86_l_436d:
	/* 0x436d: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_4375:
	/* 0x4375: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_4378:
	/* 0x4378: je     4965 <generic_sleepable_preload+0x4965> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18789ULL;
	}
x86_l_437e:
	/* 0x437e: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4383:
	/* 0x4383: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_4386:
	/* 0x4386: je     4965 <generic_sleepable_preload+0x4965> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18789ULL;
	}
x86_l_438c:
	/* 0x438c: jmp    4978 <generic_sleepable_preload+0x4978> */
	return 18808ULL;
x86_l_4391:
	/* 0x4391: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_4399:
	/* 0x4399: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_439c:
	/* 0x439c: je     4425 <generic_sleepable_preload+0x4425> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4425;
	}
x86_l_43a2:
	/* 0x43a2: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_43a7:
	/* 0x43a7: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_43aa:
	/* 0x43aa: je     4425 <generic_sleepable_preload+0x4425> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4425;
	}
x86_l_43ac:
	/* 0x43ac: jmp    4438 <generic_sleepable_preload+0x4438> */
	return 17464ULL;
x86_l_43b1:
	/* 0x43b1: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_43b9:
	/* 0x43b9: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_43bc:
	/* 0x43bc: je     4965 <generic_sleepable_preload+0x4965> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18789ULL;
	}
x86_l_43c2:
	/* 0x43c2: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_43c7:
	/* 0x43c7: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_43ca:
	/* 0x43ca: je     4965 <generic_sleepable_preload+0x4965> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18789ULL;
	}
x86_l_43d0:
	/* 0x43d0: jmp    4978 <generic_sleepable_preload+0x4978> */
	return 18808ULL;
x86_l_43d5:
	/* 0x43d5: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_43da:
	/* 0x43da: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_43dd:
	/* 0x43dd: je     4425 <generic_sleepable_preload+0x4425> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4425;
	}
x86_l_43df:
	/* 0x43df: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_43e4:
	/* 0x43e4: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_43e7:
	/* 0x43e7: je     4425 <generic_sleepable_preload+0x4425> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4425;
	}
x86_l_43e9:
	/* 0x43e9: jmp    4438 <generic_sleepable_preload+0x4438> */
	return 17464ULL;
x86_l_43eb:
	/* 0x43eb: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_43f0:
	/* 0x43f0: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_43f3:
	/* 0x43f3: je     4965 <generic_sleepable_preload+0x4965> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18789ULL;
	}
x86_l_43f9:
	/* 0x43f9: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_43fe:
	/* 0x43fe: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_4401:
	/* 0x4401: je     4965 <generic_sleepable_preload+0x4965> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18789ULL;
	}
x86_l_4407:
	/* 0x4407: jmp    4978 <generic_sleepable_preload+0x4978> */
	return 18808ULL;
x86_l_440c:
	/* 0x440c: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_4411:
	/* 0x4411: jmp    4f51 <generic_sleepable_preload+0x4f51> */
	return 20305ULL;
x86_l_4416:
	/* 0x4416: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_441b:
	/* 0x441b: jmp    4fd6 <generic_sleepable_preload+0x4fd6> */
	return 20438ULL;
x86_l_4420:
	/* 0x4420: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4425:
	/* 0x4425: shl    cl,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_4428:
	/* 0x4428: mov    al,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 64ULL);
x86_l_442a:
	/* 0x442a: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
	return 17452ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_10(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 17452ULL: goto x86_l_442c;
	case 17457ULL: goto x86_l_4431;
	case 17459ULL: goto x86_l_4433;
	case 17464ULL: goto x86_l_4438;
	case 17468ULL: goto x86_l_443c;
	case 17472ULL: goto x86_l_4440;
	case 17474ULL: goto x86_l_4442;
	case 17477ULL: goto x86_l_4445;
	case 17486ULL: goto x86_l_444e;
	case 17492ULL: goto x86_l_4454;
	case 17499ULL: goto x86_l_445b;
	case 17502ULL: goto x86_l_445e;
	case 17509ULL: goto x86_l_4465;
	case 17512ULL: goto x86_l_4468;
	case 17516ULL: goto x86_l_446c;
	case 17524ULL: goto x86_l_4474;
	case 17526ULL: goto x86_l_4476;
	case 17532ULL: goto x86_l_447c;
	case 17535ULL: goto x86_l_447f;
	case 17537ULL: goto x86_l_4481;
	case 17542ULL: goto x86_l_4486;
	case 17546ULL: goto x86_l_448a;
	case 17549ULL: goto x86_l_448d;
	case 17554ULL: goto x86_l_4492;
	case 17556ULL: goto x86_l_4494;
	case 17558ULL: goto x86_l_4496;
	case 17564ULL: goto x86_l_449c;
	case 17573ULL: goto x86_l_44a5;
	case 17579ULL: goto x86_l_44ab;
	case 17586ULL: goto x86_l_44b2;
	case 17590ULL: goto x86_l_44b6;
	case 17599ULL: goto x86_l_44bf;
	case 17601ULL: goto x86_l_44c1;
	case 17606ULL: goto x86_l_44c6;
	case 17610ULL: goto x86_l_44ca;
	case 17613ULL: goto x86_l_44cd;
	case 17618ULL: goto x86_l_44d2;
	case 17620ULL: goto x86_l_44d4;
	case 17622ULL: goto x86_l_44d6;
	case 17628ULL: goto x86_l_44dc;
	case 17637ULL: goto x86_l_44e5;
	case 17643ULL: goto x86_l_44eb;
	case 17650ULL: goto x86_l_44f2;
	case 17654ULL: goto x86_l_44f6;
	case 17663ULL: goto x86_l_44ff;
	case 17665ULL: goto x86_l_4501;
	case 17670ULL: goto x86_l_4506;
	case 17674ULL: goto x86_l_450a;
	case 17677ULL: goto x86_l_450d;
	case 17682ULL: goto x86_l_4512;
	case 17684ULL: goto x86_l_4514;
	case 17686ULL: goto x86_l_4516;
	case 17692ULL: goto x86_l_451c;
	case 17701ULL: goto x86_l_4525;
	case 17707ULL: goto x86_l_452b;
	case 17714ULL: goto x86_l_4532;
	case 17718ULL: goto x86_l_4536;
	case 17727ULL: goto x86_l_453f;
	case 17729ULL: goto x86_l_4541;
	case 17734ULL: goto x86_l_4546;
	case 17738ULL: goto x86_l_454a;
	case 17741ULL: goto x86_l_454d;
	case 17746ULL: goto x86_l_4552;
	case 17748ULL: goto x86_l_4554;
	case 17750ULL: goto x86_l_4556;
	case 17756ULL: goto x86_l_455c;
	case 17765ULL: goto x86_l_4565;
	case 17771ULL: goto x86_l_456b;
	case 17778ULL: goto x86_l_4572;
	case 17782ULL: goto x86_l_4576;
	case 17791ULL: goto x86_l_457f;
	case 17793ULL: goto x86_l_4581;
	case 17798ULL: goto x86_l_4586;
	case 17802ULL: goto x86_l_458a;
	case 17805ULL: goto x86_l_458d;
	case 17810ULL: goto x86_l_4592;
	case 17812ULL: goto x86_l_4594;
	case 17814ULL: goto x86_l_4596;
	case 17820ULL: goto x86_l_459c;
	case 17829ULL: goto x86_l_45a5;
	case 17835ULL: goto x86_l_45ab;
	case 17842ULL: goto x86_l_45b2;
	case 17846ULL: goto x86_l_45b6;
	case 17855ULL: goto x86_l_45bf;
	case 17857ULL: goto x86_l_45c1;
	case 17862ULL: goto x86_l_45c6;
	case 17866ULL: goto x86_l_45ca;
	case 17869ULL: goto x86_l_45cd;
	case 17874ULL: goto x86_l_45d2;
	case 17876ULL: goto x86_l_45d4;
	case 17878ULL: goto x86_l_45d6;
	case 17884ULL: goto x86_l_45dc;
	case 17893ULL: goto x86_l_45e5;
	case 17899ULL: goto x86_l_45eb;
	case 17906ULL: goto x86_l_45f2;
	case 17910ULL: goto x86_l_45f6;
	case 17919ULL: goto x86_l_45ff;
	case 17921ULL: goto x86_l_4601;
	case 17926ULL: goto x86_l_4606;
	case 17930ULL: goto x86_l_460a;
	case 17933ULL: goto x86_l_460d;
	case 17938ULL: goto x86_l_4612;
	case 17940ULL: goto x86_l_4614;
	case 17942ULL: goto x86_l_4616;
	case 17948ULL: goto x86_l_461c;
	case 17957ULL: goto x86_l_4625;
	case 17963ULL: goto x86_l_462b;
	case 17970ULL: goto x86_l_4632;
	case 17974ULL: goto x86_l_4636;
	case 17983ULL: goto x86_l_463f;
	case 17985ULL: goto x86_l_4641;
	case 17990ULL: goto x86_l_4646;
	case 17994ULL: goto x86_l_464a;
	case 17997ULL: goto x86_l_464d;
	case 18002ULL: goto x86_l_4652;
	case 18004ULL: goto x86_l_4654;
	case 18006ULL: goto x86_l_4656;
	case 18012ULL: goto x86_l_465c;
	case 18021ULL: goto x86_l_4665;
	case 18027ULL: goto x86_l_466b;
	case 18034ULL: goto x86_l_4672;
	case 18038ULL: goto x86_l_4676;
	case 18047ULL: goto x86_l_467f;
	case 18049ULL: goto x86_l_4681;
	case 18054ULL: goto x86_l_4686;
	case 18058ULL: goto x86_l_468a;
	case 18061ULL: goto x86_l_468d;
	case 18066ULL: goto x86_l_4692;
	case 18068ULL: goto x86_l_4694;
	case 18070ULL: goto x86_l_4696;
	case 18076ULL: goto x86_l_469c;
	case 18081ULL: goto x86_l_46a1;
	case 18090ULL: goto x86_l_46aa;
	case 18096ULL: goto x86_l_46b0;
	case 18103ULL: goto x86_l_46b7;
	case 18107ULL: goto x86_l_46bb;
	case 18116ULL: goto x86_l_46c4;
	case 18122ULL: goto x86_l_46ca;
	case 18127ULL: goto x86_l_46cf;
	case 18132ULL: goto x86_l_46d4;
	case 18135ULL: goto x86_l_46d7;
	case 18137ULL: goto x86_l_46d9;
	case 18142ULL: goto x86_l_46de;
	case 18146ULL: goto x86_l_46e2;
	case 18149ULL: goto x86_l_46e5;
	case 18154ULL: goto x86_l_46ea;
	case 18156ULL: goto x86_l_46ec;
	case 18158ULL: goto x86_l_46ee;
	case 18164ULL: goto x86_l_46f4;
	case 18173ULL: goto x86_l_46fd;
	case 18179ULL: goto x86_l_4703;
	case 18186ULL: goto x86_l_470a;
	case 18190ULL: goto x86_l_470e;
	case 18199ULL: goto x86_l_4717;
	case 18201ULL: goto x86_l_4719;
	case 18206ULL: goto x86_l_471e;
	case 18210ULL: goto x86_l_4722;
	case 18213ULL: goto x86_l_4725;
	case 18218ULL: goto x86_l_472a;
	case 18220ULL: goto x86_l_472c;
	case 18222ULL: goto x86_l_472e;
	case 18228ULL: goto x86_l_4734;
	case 18237ULL: goto x86_l_473d;
	case 18243ULL: goto x86_l_4743;
	case 18250ULL: goto x86_l_474a;
	case 18254ULL: goto x86_l_474e;
	case 18263ULL: goto x86_l_4757;
	case 18265ULL: goto x86_l_4759;
	case 18270ULL: goto x86_l_475e;
	case 18274ULL: goto x86_l_4762;
	case 18277ULL: goto x86_l_4765;
	case 18282ULL: goto x86_l_476a;
	case 18284ULL: goto x86_l_476c;
	case 18286ULL: goto x86_l_476e;
	case 18292ULL: goto x86_l_4774;
	case 18301ULL: goto x86_l_477d;
	case 18307ULL: goto x86_l_4783;
	case 18314ULL: goto x86_l_478a;
	case 18318ULL: goto x86_l_478e;
	case 18327ULL: goto x86_l_4797;
	case 18329ULL: goto x86_l_4799;
	case 18334ULL: goto x86_l_479e;
	case 18338ULL: goto x86_l_47a2;
	case 18341ULL: goto x86_l_47a5;
	case 18346ULL: goto x86_l_47aa;
	case 18348ULL: goto x86_l_47ac;
	case 18350ULL: goto x86_l_47ae;
	case 18356ULL: goto x86_l_47b4;
	case 18365ULL: goto x86_l_47bd;
	case 18371ULL: goto x86_l_47c3;
	case 18378ULL: goto x86_l_47ca;
	case 18382ULL: goto x86_l_47ce;
	case 18391ULL: goto x86_l_47d7;
	case 18393ULL: goto x86_l_47d9;
	case 18398ULL: goto x86_l_47de;
	case 18402ULL: goto x86_l_47e2;
	case 18405ULL: goto x86_l_47e5;
	case 18410ULL: goto x86_l_47ea;
	case 18412ULL: goto x86_l_47ec;
	case 18414ULL: goto x86_l_47ee;
	case 18420ULL: goto x86_l_47f4;
	case 18429ULL: goto x86_l_47fd;
	case 18435ULL: goto x86_l_4803;
	case 18442ULL: goto x86_l_480a;
	case 18446ULL: goto x86_l_480e;
	case 18455ULL: goto x86_l_4817;
	case 18457ULL: goto x86_l_4819;
	case 18462ULL: goto x86_l_481e;
	case 18466ULL: goto x86_l_4822;
	case 18469ULL: goto x86_l_4825;
	case 18474ULL: goto x86_l_482a;
	case 18476ULL: goto x86_l_482c;
	case 18478ULL: goto x86_l_482e;
	case 18484ULL: goto x86_l_4834;
	case 18493ULL: goto x86_l_483d;
	case 18499ULL: goto x86_l_4843;
	case 18506ULL: goto x86_l_484a;
	case 18510ULL: goto x86_l_484e;
	case 18519ULL: goto x86_l_4857;
	case 18521ULL: goto x86_l_4859;
	case 18526ULL: goto x86_l_485e;
	case 18530ULL: goto x86_l_4862;
	case 18533ULL: goto x86_l_4865;
	case 18538ULL: goto x86_l_486a;
	case 18540ULL: goto x86_l_486c;
	case 18542ULL: goto x86_l_486e;
	case 18548ULL: goto x86_l_4874;
	case 18557ULL: goto x86_l_487d;
	case 18563ULL: goto x86_l_4883;
	case 18570ULL: goto x86_l_488a;
	case 18574ULL: goto x86_l_488e;
	case 18583ULL: goto x86_l_4897;
	case 18585ULL: goto x86_l_4899;
	case 18590ULL: goto x86_l_489e;
	case 18594ULL: goto x86_l_48a2;
	case 18597ULL: goto x86_l_48a5;
	case 18602ULL: goto x86_l_48aa;
	case 18604ULL: goto x86_l_48ac;
	case 18606ULL: goto x86_l_48ae;
	case 18612ULL: goto x86_l_48b4;
	case 18617ULL: goto x86_l_48b9;
	case 18626ULL: goto x86_l_48c2;
	case 18632ULL: goto x86_l_48c8;
	case 18639ULL: goto x86_l_48cf;
	case 18643ULL: goto x86_l_48d3;
	case 18652ULL: goto x86_l_48dc;
	case 18654ULL: goto x86_l_48de;
	case 18659ULL: goto x86_l_48e3;
	case 18663ULL: goto x86_l_48e7;
	case 18666ULL: goto x86_l_48ea;
	case 18671ULL: goto x86_l_48ef;
	case 18673ULL: goto x86_l_48f1;
	case 18675ULL: goto x86_l_48f3;
	case 18681ULL: goto x86_l_48f9;
	case 18686ULL: goto x86_l_48fe;
	case 18695ULL: goto x86_l_4907;
	case 18701ULL: goto x86_l_490d;
	case 18708ULL: goto x86_l_4914;
	case 18712ULL: goto x86_l_4918;
	case 18721ULL: goto x86_l_4921;
	case 18727ULL: goto x86_l_4927;
	case 18732ULL: goto x86_l_492c;
	case 18736ULL: goto x86_l_4930;
	case 18739ULL: goto x86_l_4933;
	case 18744ULL: goto x86_l_4938;
	case 18746ULL: goto x86_l_493a;
	case 18748ULL: goto x86_l_493c;
	case 18754ULL: goto x86_l_4942;
	case 18759ULL: goto x86_l_4947;
	case 18764ULL: goto x86_l_494c;
	case 18769ULL: goto x86_l_4951;
	case 18774ULL: goto x86_l_4956;
	case 18779ULL: goto x86_l_495b;
	case 18784ULL: goto x86_l_4960;
	case 18789ULL: goto x86_l_4965;
	case 18792ULL: goto x86_l_4968;
	case 18794ULL: goto x86_l_496a;
	case 18796ULL: goto x86_l_496c;
	case 18801ULL: goto x86_l_4971;
	case 18803ULL: goto x86_l_4973;
	case 18808ULL: goto x86_l_4978;
	case 18812ULL: goto x86_l_497c;
	case 18816ULL: goto x86_l_4980;
	case 18818ULL: goto x86_l_4982;
	case 18821ULL: goto x86_l_4985;
	case 18824ULL: goto x86_l_4988;
	case 18832ULL: goto x86_l_4990;
	case 18838ULL: goto x86_l_4996;
	case 18845ULL: goto x86_l_499d;
	case 18848ULL: goto x86_l_49a0;
	case 18854ULL: goto x86_l_49a6;
	case 18857ULL: goto x86_l_49a9;
	case 18861ULL: goto x86_l_49ad;
	case 18868ULL: goto x86_l_49b4;
	case 18870ULL: goto x86_l_49b6;
	case 18876ULL: goto x86_l_49bc;
	case 18879ULL: goto x86_l_49bf;
	case 18881ULL: goto x86_l_49c1;
	case 18886ULL: goto x86_l_49c6;
	case 18890ULL: goto x86_l_49ca;
	case 18893ULL: goto x86_l_49cd;
	case 18898ULL: goto x86_l_49d2;
	case 18900ULL: goto x86_l_49d4;
	case 18902ULL: goto x86_l_49d6;
	case 18908ULL: goto x86_l_49dc;
	case 18913ULL: goto x86_l_49e1;
	case 18921ULL: goto x86_l_49e9;
	case 18927ULL: goto x86_l_49ef;
	case 18933ULL: goto x86_l_49f5;
	case 18937ULL: goto x86_l_49f9;
	case 18945ULL: goto x86_l_4a01;
	case 18947ULL: goto x86_l_4a03;
	case 18952ULL: goto x86_l_4a08;
	case 18956ULL: goto x86_l_4a0c;
	case 18959ULL: goto x86_l_4a0f;
	case 18964ULL: goto x86_l_4a14;
	case 18966ULL: goto x86_l_4a16;
	case 18968ULL: goto x86_l_4a18;
	case 18974ULL: goto x86_l_4a1e;
	case 18979ULL: goto x86_l_4a23;
	case 18987ULL: goto x86_l_4a2b;
	case 18993ULL: goto x86_l_4a31;
	case 18999ULL: goto x86_l_4a37;
	case 19003ULL: goto x86_l_4a3b;
	case 19011ULL: goto x86_l_4a43;
	case 19013ULL: goto x86_l_4a45;
	case 19018ULL: goto x86_l_4a4a;
	case 19022ULL: goto x86_l_4a4e;
	case 19025ULL: goto x86_l_4a51;
	case 19030ULL: goto x86_l_4a56;
	case 19032ULL: goto x86_l_4a58;
	case 19034ULL: goto x86_l_4a5a;
	case 19040ULL: goto x86_l_4a60;
	case 19045ULL: goto x86_l_4a65;
	case 19053ULL: goto x86_l_4a6d;
	case 19059ULL: goto x86_l_4a73;
	case 19065ULL: goto x86_l_4a79;
	case 19069ULL: goto x86_l_4a7d;
	case 19077ULL: goto x86_l_4a85;
	case 19079ULL: goto x86_l_4a87;
	case 19084ULL: goto x86_l_4a8c;
	case 19088ULL: goto x86_l_4a90;
	case 19091ULL: goto x86_l_4a93;
	case 19096ULL: goto x86_l_4a98;
	case 19098ULL: goto x86_l_4a9a;
	case 19100ULL: goto x86_l_4a9c;
	case 19106ULL: goto x86_l_4aa2;
	case 19111ULL: goto x86_l_4aa7;
	case 19119ULL: goto x86_l_4aaf;
	case 19125ULL: goto x86_l_4ab5;
	case 19131ULL: goto x86_l_4abb;
	case 19135ULL: goto x86_l_4abf;
	case 19143ULL: goto x86_l_4ac7;
	case 19145ULL: goto x86_l_4ac9;
	case 19150ULL: goto x86_l_4ace;
	case 19154ULL: goto x86_l_4ad2;
	case 19157ULL: goto x86_l_4ad5;
	case 19162ULL: goto x86_l_4ada;
	case 19164ULL: goto x86_l_4adc;
	case 19166ULL: goto x86_l_4ade;
	case 19172ULL: goto x86_l_4ae4;
	case 19177ULL: goto x86_l_4ae9;
	case 19185ULL: goto x86_l_4af1;
	case 19191ULL: goto x86_l_4af7;
	case 19197ULL: goto x86_l_4afd;
	case 19201ULL: goto x86_l_4b01;
	case 19209ULL: goto x86_l_4b09;
	case 19211ULL: goto x86_l_4b0b;
	case 19216ULL: goto x86_l_4b10;
	case 19220ULL: goto x86_l_4b14;
	case 19223ULL: goto x86_l_4b17;
	case 19228ULL: goto x86_l_4b1c;
	case 19230ULL: goto x86_l_4b1e;
	case 19232ULL: goto x86_l_4b20;
	case 19238ULL: goto x86_l_4b26;
	case 19243ULL: goto x86_l_4b2b;
	case 19251ULL: goto x86_l_4b33;
	case 19257ULL: goto x86_l_4b39;
	case 19263ULL: goto x86_l_4b3f;
	case 19267ULL: goto x86_l_4b43;
	case 19275ULL: goto x86_l_4b4b;
	case 19277ULL: goto x86_l_4b4d;
	case 19282ULL: goto x86_l_4b52;
	case 19286ULL: goto x86_l_4b56;
	default: return 0xffffffffffffffffULL;
	}
x86_l_442c:
	/* 0x442c: mov    ecx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 64ULL);
x86_l_4431:
	/* 0x4431: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4433:
	/* 0x4433: bzhi   rax,QWORD PTR [rsi],rcx */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RAX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), 0ULL);
x86_l_4438:
	/* 0x4438: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_443c:
	/* 0x443c: mov    ebx,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4440:
	/* 0x4440: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4442:
	/* 0x4442: mov    r14b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_8, 1ULL);
x86_l_4445:
	/* 0x4445: cmp    WORD PTR [r13+0x166],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1537598291968ULL);
x86_l_444e:
	/* 0x444e: je     5062 <generic_sleepable_preload+0x5062> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20578ULL;
	}
x86_l_4454:
	/* 0x4454: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_445b:
	/* 0x445b: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_445e:
	/* 0x445e: mov    edx,DWORD PTR [r13+0x160] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_4465:
	/* 0x4465: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4468:
	/* 0x4468: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_446c:
	/* 0x446c: movzx  eax,WORD PTR [r13+0x164] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 356ULL);
x86_l_4474:
	/* 0x4474: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_4476:
	/* 0x4476: je     46d4 <generic_sleepable_preload+0x46d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_46d4;
	}
x86_l_447c:
	/* 0x447c: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_447f:
	/* 0x447f: je     449c <generic_sleepable_preload+0x449c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_449c;
	}
x86_l_4481:
	/* 0x4481: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4486:
	/* 0x4486: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_448a:
	/* 0x448a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_448d:
	/* 0x448d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4492:
	/* 0x4492: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4494:
	/* 0x4494: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4496:
	/* 0x4496: js     494c <generic_sleepable_preload+0x494c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_494c;
	}
x86_l_449c:
	/* 0x449c: cmp    WORD PTR [r13+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_44a5:
	/* 0x44a5: je     5062 <generic_sleepable_preload+0x5062> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20578ULL;
	}
x86_l_44ab:
	/* 0x44ab: mov    eax,DWORD PTR [r13+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_44b2:
	/* 0x44b2: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_44b6:
	/* 0x44b6: cmp    WORD PTR [r13+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_44bf:
	/* 0x44bf: je     44dc <generic_sleepable_preload+0x44dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44dc;
	}
x86_l_44c1:
	/* 0x44c1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_44c6:
	/* 0x44c6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_44ca:
	/* 0x44ca: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_44cd:
	/* 0x44cd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_44d2:
	/* 0x44d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44d4:
	/* 0x44d4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_44d6:
	/* 0x44d6: js     4956 <generic_sleepable_preload+0x4956> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4956;
	}
x86_l_44dc:
	/* 0x44dc: cmp    WORD PTR [r13+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_44e5:
	/* 0x44e5: je     5062 <generic_sleepable_preload+0x5062> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20578ULL;
	}
x86_l_44eb:
	/* 0x44eb: mov    eax,DWORD PTR [r13+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_44f2:
	/* 0x44f2: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_44f6:
	/* 0x44f6: cmp    WORD PTR [r13+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_44ff:
	/* 0x44ff: je     451c <generic_sleepable_preload+0x451c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_451c;
	}
x86_l_4501:
	/* 0x4501: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4506:
	/* 0x4506: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_450a:
	/* 0x450a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_450d:
	/* 0x450d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4512:
	/* 0x4512: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4514:
	/* 0x4514: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4516:
	/* 0x4516: js     4ec9 <generic_sleepable_preload+0x4ec9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20169ULL;
	}
x86_l_451c:
	/* 0x451c: cmp    WORD PTR [r13+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_4525:
	/* 0x4525: je     5062 <generic_sleepable_preload+0x5062> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20578ULL;
	}
x86_l_452b:
	/* 0x452b: mov    eax,DWORD PTR [r13+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_4532:
	/* 0x4532: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4536:
	/* 0x4536: cmp    WORD PTR [r13+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_453f:
	/* 0x453f: je     455c <generic_sleepable_preload+0x455c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_455c;
	}
x86_l_4541:
	/* 0x4541: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4546:
	/* 0x4546: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_454a:
	/* 0x454a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_454d:
	/* 0x454d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4552:
	/* 0x4552: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4554:
	/* 0x4554: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4556:
	/* 0x4556: js     4eee <generic_sleepable_preload+0x4eee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20206ULL;
	}
x86_l_455c:
	/* 0x455c: cmp    WORD PTR [r13+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_4565:
	/* 0x4565: je     5062 <generic_sleepable_preload+0x5062> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20578ULL;
	}
x86_l_456b:
	/* 0x456b: mov    eax,DWORD PTR [r13+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_4572:
	/* 0x4572: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4576:
	/* 0x4576: cmp    WORD PTR [r13+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_457f:
	/* 0x457f: je     459c <generic_sleepable_preload+0x459c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_459c;
	}
x86_l_4581:
	/* 0x4581: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4586:
	/* 0x4586: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_458a:
	/* 0x458a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_458d:
	/* 0x458d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4592:
	/* 0x4592: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4594:
	/* 0x4594: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4596:
	/* 0x4596: js     4f13 <generic_sleepable_preload+0x4f13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20243ULL;
	}
x86_l_459c:
	/* 0x459c: cmp    WORD PTR [r13+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_45a5:
	/* 0x45a5: je     5062 <generic_sleepable_preload+0x5062> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20578ULL;
	}
x86_l_45ab:
	/* 0x45ab: mov    eax,DWORD PTR [r13+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_45b2:
	/* 0x45b2: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_45b6:
	/* 0x45b6: cmp    WORD PTR [r13+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_45bf:
	/* 0x45bf: je     45dc <generic_sleepable_preload+0x45dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_45dc;
	}
x86_l_45c1:
	/* 0x45c1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_45c6:
	/* 0x45c6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_45ca:
	/* 0x45ca: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_45cd:
	/* 0x45cd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_45d2:
	/* 0x45d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45d4:
	/* 0x45d4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_45d6:
	/* 0x45d6: js     4f38 <generic_sleepable_preload+0x4f38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20280ULL;
	}
x86_l_45dc:
	/* 0x45dc: cmp    WORD PTR [r13+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_45e5:
	/* 0x45e5: je     5062 <generic_sleepable_preload+0x5062> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20578ULL;
	}
x86_l_45eb:
	/* 0x45eb: mov    eax,DWORD PTR [r13+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_45f2:
	/* 0x45f2: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_45f6:
	/* 0x45f6: cmp    WORD PTR [r13+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_45ff:
	/* 0x45ff: je     461c <generic_sleepable_preload+0x461c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_461c;
	}
x86_l_4601:
	/* 0x4601: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4606:
	/* 0x4606: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_460a:
	/* 0x460a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_460d:
	/* 0x460d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4612:
	/* 0x4612: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4614:
	/* 0x4614: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4616:
	/* 0x4616: js     505a <generic_sleepable_preload+0x505a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20570ULL;
	}
x86_l_461c:
	/* 0x461c: cmp    WORD PTR [r13+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_4625:
	/* 0x4625: je     5062 <generic_sleepable_preload+0x5062> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20578ULL;
	}
x86_l_462b:
	/* 0x462b: mov    eax,DWORD PTR [r13+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_4632:
	/* 0x4632: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4636:
	/* 0x4636: cmp    WORD PTR [r13+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_463f:
	/* 0x463f: je     465c <generic_sleepable_preload+0x465c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_465c;
	}
x86_l_4641:
	/* 0x4641: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4646:
	/* 0x4646: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_464a:
	/* 0x464a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_464d:
	/* 0x464d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4652:
	/* 0x4652: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4654:
	/* 0x4654: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4656:
	/* 0x4656: js     523b <generic_sleepable_preload+0x523b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21051ULL;
	}
x86_l_465c:
	/* 0x465c: cmp    WORD PTR [r13+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_4665:
	/* 0x4665: je     5062 <generic_sleepable_preload+0x5062> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20578ULL;
	}
x86_l_466b:
	/* 0x466b: mov    eax,DWORD PTR [r13+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_4672:
	/* 0x4672: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4676:
	/* 0x4676: cmp    WORD PTR [r13+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_467f:
	/* 0x467f: je     469c <generic_sleepable_preload+0x469c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_469c;
	}
x86_l_4681:
	/* 0x4681: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4686:
	/* 0x4686: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_468a:
	/* 0x468a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_468d:
	/* 0x468d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4692:
	/* 0x4692: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4694:
	/* 0x4694: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4696:
	/* 0x4696: js     52d0 <generic_sleepable_preload+0x52d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21200ULL;
	}
x86_l_469c:
	/* 0x469c: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_46a1:
	/* 0x46a1: cmp    WORD PTR [r13+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_46aa:
	/* 0x46aa: je     5062 <generic_sleepable_preload+0x5062> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20578ULL;
	}
x86_l_46b0:
	/* 0x46b0: mov    eax,DWORD PTR [r13+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_46b7:
	/* 0x46b7: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_46bb:
	/* 0x46bb: cmp    WORD PTR [r13+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_46c4:
	/* 0x46c4: je     5062 <generic_sleepable_preload+0x5062> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20578ULL;
	}
x86_l_46ca:
	/* 0x46ca: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_46cf:
	/* 0x46cf: jmp    492c <generic_sleepable_preload+0x492c> */
	goto x86_l_492c;
x86_l_46d4:
	/* 0x46d4: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_46d7:
	/* 0x46d7: je     46f4 <generic_sleepable_preload+0x46f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_46f4;
	}
x86_l_46d9:
	/* 0x46d9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_46de:
	/* 0x46de: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_46e2:
	/* 0x46e2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_46e5:
	/* 0x46e5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_46ea:
	/* 0x46ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46ec:
	/* 0x46ec: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_46ee:
	/* 0x46ee: js     494c <generic_sleepable_preload+0x494c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_494c;
	}
x86_l_46f4:
	/* 0x46f4: cmp    WORD PTR [r13+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_46fd:
	/* 0x46fd: je     5062 <generic_sleepable_preload+0x5062> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20578ULL;
	}
x86_l_4703:
	/* 0x4703: mov    eax,DWORD PTR [r13+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_470a:
	/* 0x470a: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_470e:
	/* 0x470e: cmp    WORD PTR [r13+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_4717:
	/* 0x4717: je     4734 <generic_sleepable_preload+0x4734> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4734;
	}
x86_l_4719:
	/* 0x4719: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_471e:
	/* 0x471e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4722:
	/* 0x4722: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4725:
	/* 0x4725: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_472a:
	/* 0x472a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_472c:
	/* 0x472c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_472e:
	/* 0x472e: js     4956 <generic_sleepable_preload+0x4956> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4956;
	}
x86_l_4734:
	/* 0x4734: cmp    WORD PTR [r13+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_473d:
	/* 0x473d: je     5062 <generic_sleepable_preload+0x5062> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20578ULL;
	}
x86_l_4743:
	/* 0x4743: mov    eax,DWORD PTR [r13+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_474a:
	/* 0x474a: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_474e:
	/* 0x474e: cmp    WORD PTR [r13+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_4757:
	/* 0x4757: je     4774 <generic_sleepable_preload+0x4774> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4774;
	}
x86_l_4759:
	/* 0x4759: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_475e:
	/* 0x475e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4762:
	/* 0x4762: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4765:
	/* 0x4765: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_476a:
	/* 0x476a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_476c:
	/* 0x476c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_476e:
	/* 0x476e: js     4ec9 <generic_sleepable_preload+0x4ec9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20169ULL;
	}
x86_l_4774:
	/* 0x4774: cmp    WORD PTR [r13+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_477d:
	/* 0x477d: je     5062 <generic_sleepable_preload+0x5062> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20578ULL;
	}
x86_l_4783:
	/* 0x4783: mov    eax,DWORD PTR [r13+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_478a:
	/* 0x478a: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_478e:
	/* 0x478e: cmp    WORD PTR [r13+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_4797:
	/* 0x4797: je     47b4 <generic_sleepable_preload+0x47b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_47b4;
	}
x86_l_4799:
	/* 0x4799: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_479e:
	/* 0x479e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_47a2:
	/* 0x47a2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_47a5:
	/* 0x47a5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_47aa:
	/* 0x47aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_47ac:
	/* 0x47ac: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_47ae:
	/* 0x47ae: js     4eee <generic_sleepable_preload+0x4eee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20206ULL;
	}
x86_l_47b4:
	/* 0x47b4: cmp    WORD PTR [r13+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_47bd:
	/* 0x47bd: je     5062 <generic_sleepable_preload+0x5062> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20578ULL;
	}
x86_l_47c3:
	/* 0x47c3: mov    eax,DWORD PTR [r13+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_47ca:
	/* 0x47ca: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_47ce:
	/* 0x47ce: cmp    WORD PTR [r13+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_47d7:
	/* 0x47d7: je     47f4 <generic_sleepable_preload+0x47f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_47f4;
	}
x86_l_47d9:
	/* 0x47d9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_47de:
	/* 0x47de: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_47e2:
	/* 0x47e2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_47e5:
	/* 0x47e5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_47ea:
	/* 0x47ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_47ec:
	/* 0x47ec: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_47ee:
	/* 0x47ee: js     4f13 <generic_sleepable_preload+0x4f13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20243ULL;
	}
x86_l_47f4:
	/* 0x47f4: cmp    WORD PTR [r13+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_47fd:
	/* 0x47fd: je     5062 <generic_sleepable_preload+0x5062> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20578ULL;
	}
x86_l_4803:
	/* 0x4803: mov    eax,DWORD PTR [r13+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_480a:
	/* 0x480a: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_480e:
	/* 0x480e: cmp    WORD PTR [r13+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_4817:
	/* 0x4817: je     4834 <generic_sleepable_preload+0x4834> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4834;
	}
x86_l_4819:
	/* 0x4819: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_481e:
	/* 0x481e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4822:
	/* 0x4822: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4825:
	/* 0x4825: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_482a:
	/* 0x482a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_482c:
	/* 0x482c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_482e:
	/* 0x482e: js     4f38 <generic_sleepable_preload+0x4f38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20280ULL;
	}
x86_l_4834:
	/* 0x4834: cmp    WORD PTR [r13+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_483d:
	/* 0x483d: je     5062 <generic_sleepable_preload+0x5062> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20578ULL;
	}
x86_l_4843:
	/* 0x4843: mov    eax,DWORD PTR [r13+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_484a:
	/* 0x484a: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_484e:
	/* 0x484e: cmp    WORD PTR [r13+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_4857:
	/* 0x4857: je     4874 <generic_sleepable_preload+0x4874> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4874;
	}
x86_l_4859:
	/* 0x4859: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_485e:
	/* 0x485e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4862:
	/* 0x4862: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4865:
	/* 0x4865: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_486a:
	/* 0x486a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_486c:
	/* 0x486c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_486e:
	/* 0x486e: js     505a <generic_sleepable_preload+0x505a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20570ULL;
	}
x86_l_4874:
	/* 0x4874: cmp    WORD PTR [r13+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_487d:
	/* 0x487d: je     5062 <generic_sleepable_preload+0x5062> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20578ULL;
	}
x86_l_4883:
	/* 0x4883: mov    eax,DWORD PTR [r13+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_488a:
	/* 0x488a: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_488e:
	/* 0x488e: cmp    WORD PTR [r13+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_4897:
	/* 0x4897: je     48b4 <generic_sleepable_preload+0x48b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_48b4;
	}
x86_l_4899:
	/* 0x4899: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_489e:
	/* 0x489e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_48a2:
	/* 0x48a2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_48a5:
	/* 0x48a5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_48aa:
	/* 0x48aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48ac:
	/* 0x48ac: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_48ae:
	/* 0x48ae: js     536a <generic_sleepable_preload+0x536a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21354ULL;
	}
x86_l_48b4:
	/* 0x48b4: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_48b9:
	/* 0x48b9: cmp    WORD PTR [r13+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_48c2:
	/* 0x48c2: je     5062 <generic_sleepable_preload+0x5062> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20578ULL;
	}
x86_l_48c8:
	/* 0x48c8: mov    eax,DWORD PTR [r13+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_48cf:
	/* 0x48cf: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_48d3:
	/* 0x48d3: cmp    WORD PTR [r13+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_48dc:
	/* 0x48dc: je     48f9 <generic_sleepable_preload+0x48f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_48f9;
	}
x86_l_48de:
	/* 0x48de: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_48e3:
	/* 0x48e3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_48e7:
	/* 0x48e7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_48ea:
	/* 0x48ea: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_48ef:
	/* 0x48ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48f1:
	/* 0x48f1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_48f3:
	/* 0x48f3: js     52d0 <generic_sleepable_preload+0x52d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21200ULL;
	}
x86_l_48f9:
	/* 0x48f9: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_48fe:
	/* 0x48fe: cmp    WORD PTR [r13+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_4907:
	/* 0x4907: je     5062 <generic_sleepable_preload+0x5062> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20578ULL;
	}
x86_l_490d:
	/* 0x490d: mov    eax,DWORD PTR [r13+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_4914:
	/* 0x4914: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4918:
	/* 0x4918: cmp    WORD PTR [r13+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_4921:
	/* 0x4921: je     5062 <generic_sleepable_preload+0x5062> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20578ULL;
	}
x86_l_4927:
	/* 0x4927: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_492c:
	/* 0x492c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4930:
	/* 0x4930: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4933:
	/* 0x4933: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4938:
	/* 0x4938: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_493a:
	/* 0x493a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_493c:
	/* 0x493c: jns    5062 <generic_sleepable_preload+0x5062> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 20578ULL;
	}
x86_l_4942:
	/* 0x4942: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_4947:
	/* 0x4947: jmp    505f <generic_sleepable_preload+0x505f> */
	return 20575ULL;
x86_l_494c:
	/* 0x494c: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_4951:
	/* 0x4951: jmp    505f <generic_sleepable_preload+0x505f> */
	return 20575ULL;
x86_l_4956:
	/* 0x4956: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_495b:
	/* 0x495b: jmp    505f <generic_sleepable_preload+0x505f> */
	return 20575ULL;
x86_l_4960:
	/* 0x4960: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4965:
	/* 0x4965: shl    cl,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_4968:
	/* 0x4968: mov    al,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 64ULL);
x86_l_496a:
	/* 0x496a: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_496c:
	/* 0x496c: mov    ecx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 64ULL);
x86_l_4971:
	/* 0x4971: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4973:
	/* 0x4973: bzhi   rax,QWORD PTR [rsi],rcx */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RAX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), 0ULL);
x86_l_4978:
	/* 0x4978: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_497c:
	/* 0x497c: mov    ebx,DWORD PTR [r13+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_4980:
	/* 0x4980: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4982:
	/* 0x4982: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_4985:
	/* 0x4985: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_4988:
	/* 0x4988: cmp    WORD PTR [rsi+0x1b6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1881195675648ULL);
x86_l_4990:
	/* 0x4990: je     5116 <generic_sleepable_preload+0x5116> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20758ULL;
	}
x86_l_4996:
	/* 0x4996: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_499d:
	/* 0x499d: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_49a0:
	/* 0x49a0: mov    edx,DWORD PTR [rsi+0x1b0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 432ULL);
x86_l_49a6:
	/* 0x49a6: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_49a9:
	/* 0x49a9: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49ad:
	/* 0x49ad: movzx  eax,WORD PTR [rsi+0x1b4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 436ULL);
x86_l_49b4:
	/* 0x49b4: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_49b6:
	/* 0x49b6: je     4c21 <generic_sleepable_preload+0x4c21> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19489ULL;
	}
x86_l_49bc:
	/* 0x49bc: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_49bf:
	/* 0x49bf: je     49dc <generic_sleepable_preload+0x49dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_49dc;
	}
x86_l_49c1:
	/* 0x49c1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_49c6:
	/* 0x49c6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49ca:
	/* 0x49ca: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_49cd:
	/* 0x49cd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_49d2:
	/* 0x49d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49d4:
	/* 0x49d4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_49d6:
	/* 0x49d6: js     4ea1 <generic_sleepable_preload+0x4ea1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20129ULL;
	}
x86_l_49dc:
	/* 0x49dc: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49e1:
	/* 0x49e1: cmp    WORD PTR [rcx+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_49e9:
	/* 0x49e9: je     5116 <generic_sleepable_preload+0x5116> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20758ULL;
	}
x86_l_49ef:
	/* 0x49ef: mov    eax,DWORD PTR [rcx+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_49f5:
	/* 0x49f5: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_49f9:
	/* 0x49f9: cmp    WORD PTR [rcx+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_4a01:
	/* 0x4a01: je     4a1e <generic_sleepable_preload+0x4a1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4a1e;
	}
x86_l_4a03:
	/* 0x4a03: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4a08:
	/* 0x4a08: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a0c:
	/* 0x4a0c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4a0f:
	/* 0x4a0f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a14:
	/* 0x4a14: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a16:
	/* 0x4a16: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4a18:
	/* 0x4a18: js     4eab <generic_sleepable_preload+0x4eab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20139ULL;
	}
x86_l_4a1e:
	/* 0x4a1e: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a23:
	/* 0x4a23: cmp    WORD PTR [rcx+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_4a2b:
	/* 0x4a2b: je     5116 <generic_sleepable_preload+0x5116> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20758ULL;
	}
x86_l_4a31:
	/* 0x4a31: mov    eax,DWORD PTR [rcx+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_4a37:
	/* 0x4a37: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4a3b:
	/* 0x4a3b: cmp    WORD PTR [rcx+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_4a43:
	/* 0x4a43: je     4a60 <generic_sleepable_preload+0x4a60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4a60;
	}
x86_l_4a45:
	/* 0x4a45: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4a4a:
	/* 0x4a4a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a4e:
	/* 0x4a4e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4a51:
	/* 0x4a51: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a56:
	/* 0x4a56: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a58:
	/* 0x4a58: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4a5a:
	/* 0x4a5a: js     4ed3 <generic_sleepable_preload+0x4ed3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20179ULL;
	}
x86_l_4a60:
	/* 0x4a60: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a65:
	/* 0x4a65: cmp    WORD PTR [rcx+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_4a6d:
	/* 0x4a6d: je     5116 <generic_sleepable_preload+0x5116> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20758ULL;
	}
x86_l_4a73:
	/* 0x4a73: mov    eax,DWORD PTR [rcx+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_4a79:
	/* 0x4a79: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4a7d:
	/* 0x4a7d: cmp    WORD PTR [rcx+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_4a85:
	/* 0x4a85: je     4aa2 <generic_sleepable_preload+0x4aa2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4aa2;
	}
x86_l_4a87:
	/* 0x4a87: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4a8c:
	/* 0x4a8c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a90:
	/* 0x4a90: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4a93:
	/* 0x4a93: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a98:
	/* 0x4a98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a9a:
	/* 0x4a9a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4a9c:
	/* 0x4a9c: js     4ef8 <generic_sleepable_preload+0x4ef8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20216ULL;
	}
x86_l_4aa2:
	/* 0x4aa2: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4aa7:
	/* 0x4aa7: cmp    WORD PTR [rcx+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_4aaf:
	/* 0x4aaf: je     5116 <generic_sleepable_preload+0x5116> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20758ULL;
	}
x86_l_4ab5:
	/* 0x4ab5: mov    eax,DWORD PTR [rcx+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_4abb:
	/* 0x4abb: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4abf:
	/* 0x4abf: cmp    WORD PTR [rcx+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_4ac7:
	/* 0x4ac7: je     4ae4 <generic_sleepable_preload+0x4ae4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4ae4;
	}
x86_l_4ac9:
	/* 0x4ac9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4ace:
	/* 0x4ace: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ad2:
	/* 0x4ad2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4ad5:
	/* 0x4ad5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4ada:
	/* 0x4ada: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4adc:
	/* 0x4adc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4ade:
	/* 0x4ade: js     4f1d <generic_sleepable_preload+0x4f1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20253ULL;
	}
x86_l_4ae4:
	/* 0x4ae4: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ae9:
	/* 0x4ae9: cmp    WORD PTR [rcx+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_4af1:
	/* 0x4af1: je     5116 <generic_sleepable_preload+0x5116> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20758ULL;
	}
x86_l_4af7:
	/* 0x4af7: mov    eax,DWORD PTR [rcx+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_4afd:
	/* 0x4afd: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4b01:
	/* 0x4b01: cmp    WORD PTR [rcx+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_4b09:
	/* 0x4b09: je     4b26 <generic_sleepable_preload+0x4b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4b26;
	}
x86_l_4b0b:
	/* 0x4b0b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4b10:
	/* 0x4b10: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4b14:
	/* 0x4b14: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4b17:
	/* 0x4b17: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b1c:
	/* 0x4b1c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b1e:
	/* 0x4b1e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4b20:
	/* 0x4b20: js     4f42 <generic_sleepable_preload+0x4f42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20290ULL;
	}
x86_l_4b26:
	/* 0x4b26: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b2b:
	/* 0x4b2b: cmp    WORD PTR [rcx+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_4b33:
	/* 0x4b33: je     5116 <generic_sleepable_preload+0x5116> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20758ULL;
	}
x86_l_4b39:
	/* 0x4b39: mov    eax,DWORD PTR [rcx+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_4b3f:
	/* 0x4b3f: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4b43:
	/* 0x4b43: cmp    WORD PTR [rcx+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_4b4b:
	/* 0x4b4b: je     4b68 <generic_sleepable_preload+0x4b68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19304ULL;
	}
x86_l_4b4d:
	/* 0x4b4d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4b52:
	/* 0x4b52: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4b56:
	/* 0x4b56: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
	return 19289ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_11(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 19289ULL: goto x86_l_4b59;
	case 19294ULL: goto x86_l_4b5e;
	case 19296ULL: goto x86_l_4b60;
	case 19298ULL: goto x86_l_4b62;
	case 19304ULL: goto x86_l_4b68;
	case 19309ULL: goto x86_l_4b6d;
	case 19317ULL: goto x86_l_4b75;
	case 19323ULL: goto x86_l_4b7b;
	case 19329ULL: goto x86_l_4b81;
	case 19333ULL: goto x86_l_4b85;
	case 19341ULL: goto x86_l_4b8d;
	case 19343ULL: goto x86_l_4b8f;
	case 19348ULL: goto x86_l_4b94;
	case 19352ULL: goto x86_l_4b98;
	case 19355ULL: goto x86_l_4b9b;
	case 19360ULL: goto x86_l_4ba0;
	case 19362ULL: goto x86_l_4ba2;
	case 19364ULL: goto x86_l_4ba4;
	case 19370ULL: goto x86_l_4baa;
	case 19375ULL: goto x86_l_4baf;
	case 19383ULL: goto x86_l_4bb7;
	case 19389ULL: goto x86_l_4bbd;
	case 19395ULL: goto x86_l_4bc3;
	case 19399ULL: goto x86_l_4bc7;
	case 19407ULL: goto x86_l_4bcf;
	case 19409ULL: goto x86_l_4bd1;
	case 19414ULL: goto x86_l_4bd6;
	case 19418ULL: goto x86_l_4bda;
	case 19421ULL: goto x86_l_4bdd;
	case 19426ULL: goto x86_l_4be2;
	case 19428ULL: goto x86_l_4be4;
	case 19430ULL: goto x86_l_4be6;
	case 19436ULL: goto x86_l_4bec;
	case 19441ULL: goto x86_l_4bf1;
	case 19449ULL: goto x86_l_4bf9;
	case 19455ULL: goto x86_l_4bff;
	case 19461ULL: goto x86_l_4c05;
	case 19465ULL: goto x86_l_4c09;
	case 19473ULL: goto x86_l_4c11;
	case 19479ULL: goto x86_l_4c17;
	case 19484ULL: goto x86_l_4c1c;
	case 19489ULL: goto x86_l_4c21;
	case 19492ULL: goto x86_l_4c24;
	case 19494ULL: goto x86_l_4c26;
	case 19499ULL: goto x86_l_4c2b;
	case 19503ULL: goto x86_l_4c2f;
	case 19506ULL: goto x86_l_4c32;
	case 19511ULL: goto x86_l_4c37;
	case 19513ULL: goto x86_l_4c39;
	case 19515ULL: goto x86_l_4c3b;
	case 19521ULL: goto x86_l_4c41;
	case 19526ULL: goto x86_l_4c46;
	case 19534ULL: goto x86_l_4c4e;
	case 19540ULL: goto x86_l_4c54;
	case 19546ULL: goto x86_l_4c5a;
	case 19550ULL: goto x86_l_4c5e;
	case 19558ULL: goto x86_l_4c66;
	case 19560ULL: goto x86_l_4c68;
	case 19565ULL: goto x86_l_4c6d;
	case 19569ULL: goto x86_l_4c71;
	case 19572ULL: goto x86_l_4c74;
	case 19577ULL: goto x86_l_4c79;
	case 19579ULL: goto x86_l_4c7b;
	case 19581ULL: goto x86_l_4c7d;
	case 19587ULL: goto x86_l_4c83;
	case 19592ULL: goto x86_l_4c88;
	case 19600ULL: goto x86_l_4c90;
	case 19606ULL: goto x86_l_4c96;
	case 19612ULL: goto x86_l_4c9c;
	case 19616ULL: goto x86_l_4ca0;
	case 19624ULL: goto x86_l_4ca8;
	case 19626ULL: goto x86_l_4caa;
	case 19631ULL: goto x86_l_4caf;
	case 19635ULL: goto x86_l_4cb3;
	case 19638ULL: goto x86_l_4cb6;
	case 19643ULL: goto x86_l_4cbb;
	case 19645ULL: goto x86_l_4cbd;
	case 19647ULL: goto x86_l_4cbf;
	case 19653ULL: goto x86_l_4cc5;
	case 19658ULL: goto x86_l_4cca;
	case 19666ULL: goto x86_l_4cd2;
	case 19672ULL: goto x86_l_4cd8;
	case 19678ULL: goto x86_l_4cde;
	case 19682ULL: goto x86_l_4ce2;
	case 19690ULL: goto x86_l_4cea;
	case 19692ULL: goto x86_l_4cec;
	case 19697ULL: goto x86_l_4cf1;
	case 19701ULL: goto x86_l_4cf5;
	case 19704ULL: goto x86_l_4cf8;
	case 19709ULL: goto x86_l_4cfd;
	case 19711ULL: goto x86_l_4cff;
	case 19713ULL: goto x86_l_4d01;
	case 19719ULL: goto x86_l_4d07;
	case 19724ULL: goto x86_l_4d0c;
	case 19732ULL: goto x86_l_4d14;
	case 19738ULL: goto x86_l_4d1a;
	case 19744ULL: goto x86_l_4d20;
	case 19748ULL: goto x86_l_4d24;
	case 19756ULL: goto x86_l_4d2c;
	case 19758ULL: goto x86_l_4d2e;
	case 19763ULL: goto x86_l_4d33;
	case 19767ULL: goto x86_l_4d37;
	case 19770ULL: goto x86_l_4d3a;
	case 19775ULL: goto x86_l_4d3f;
	case 19777ULL: goto x86_l_4d41;
	case 19779ULL: goto x86_l_4d43;
	case 19785ULL: goto x86_l_4d49;
	case 19790ULL: goto x86_l_4d4e;
	case 19798ULL: goto x86_l_4d56;
	case 19804ULL: goto x86_l_4d5c;
	case 19810ULL: goto x86_l_4d62;
	case 19814ULL: goto x86_l_4d66;
	case 19822ULL: goto x86_l_4d6e;
	case 19824ULL: goto x86_l_4d70;
	case 19829ULL: goto x86_l_4d75;
	case 19833ULL: goto x86_l_4d79;
	case 19836ULL: goto x86_l_4d7c;
	case 19841ULL: goto x86_l_4d81;
	case 19843ULL: goto x86_l_4d83;
	case 19845ULL: goto x86_l_4d85;
	case 19851ULL: goto x86_l_4d8b;
	case 19856ULL: goto x86_l_4d90;
	case 19864ULL: goto x86_l_4d98;
	case 19870ULL: goto x86_l_4d9e;
	case 19876ULL: goto x86_l_4da4;
	case 19880ULL: goto x86_l_4da8;
	case 19888ULL: goto x86_l_4db0;
	case 19890ULL: goto x86_l_4db2;
	case 19895ULL: goto x86_l_4db7;
	case 19899ULL: goto x86_l_4dbb;
	case 19902ULL: goto x86_l_4dbe;
	case 19907ULL: goto x86_l_4dc3;
	case 19909ULL: goto x86_l_4dc5;
	case 19911ULL: goto x86_l_4dc7;
	case 19917ULL: goto x86_l_4dcd;
	case 19922ULL: goto x86_l_4dd2;
	case 19930ULL: goto x86_l_4dda;
	case 19936ULL: goto x86_l_4de0;
	case 19942ULL: goto x86_l_4de6;
	case 19946ULL: goto x86_l_4dea;
	case 19954ULL: goto x86_l_4df2;
	case 19956ULL: goto x86_l_4df4;
	case 19961ULL: goto x86_l_4df9;
	case 19965ULL: goto x86_l_4dfd;
	case 19968ULL: goto x86_l_4e00;
	case 19973ULL: goto x86_l_4e05;
	case 19975ULL: goto x86_l_4e07;
	case 19977ULL: goto x86_l_4e09;
	case 19983ULL: goto x86_l_4e0f;
	case 19988ULL: goto x86_l_4e14;
	case 19996ULL: goto x86_l_4e1c;
	case 20002ULL: goto x86_l_4e22;
	case 20008ULL: goto x86_l_4e28;
	case 20012ULL: goto x86_l_4e2c;
	case 20020ULL: goto x86_l_4e34;
	case 20022ULL: goto x86_l_4e36;
	case 20027ULL: goto x86_l_4e3b;
	case 20031ULL: goto x86_l_4e3f;
	case 20034ULL: goto x86_l_4e42;
	case 20039ULL: goto x86_l_4e47;
	case 20041ULL: goto x86_l_4e49;
	case 20043ULL: goto x86_l_4e4b;
	case 20049ULL: goto x86_l_4e51;
	case 20054ULL: goto x86_l_4e56;
	case 20062ULL: goto x86_l_4e5e;
	case 20068ULL: goto x86_l_4e64;
	case 20074ULL: goto x86_l_4e6a;
	case 20078ULL: goto x86_l_4e6e;
	case 20086ULL: goto x86_l_4e76;
	case 20092ULL: goto x86_l_4e7c;
	case 20097ULL: goto x86_l_4e81;
	case 20101ULL: goto x86_l_4e85;
	case 20104ULL: goto x86_l_4e88;
	case 20109ULL: goto x86_l_4e8d;
	case 20111ULL: goto x86_l_4e8f;
	case 20113ULL: goto x86_l_4e91;
	case 20119ULL: goto x86_l_4e97;
	case 20124ULL: goto x86_l_4e9c;
	case 20129ULL: goto x86_l_4ea1;
	case 20134ULL: goto x86_l_4ea6;
	case 20139ULL: goto x86_l_4eab;
	case 20144ULL: goto x86_l_4eb0;
	case 20149ULL: goto x86_l_4eb5;
	case 20154ULL: goto x86_l_4eba;
	case 20159ULL: goto x86_l_4ebf;
	case 20164ULL: goto x86_l_4ec4;
	case 20169ULL: goto x86_l_4ec9;
	case 20174ULL: goto x86_l_4ece;
	case 20179ULL: goto x86_l_4ed3;
	case 20184ULL: goto x86_l_4ed8;
	case 20189ULL: goto x86_l_4edd;
	case 20194ULL: goto x86_l_4ee2;
	case 20196ULL: goto x86_l_4ee4;
	case 20201ULL: goto x86_l_4ee9;
	case 20206ULL: goto x86_l_4eee;
	case 20211ULL: goto x86_l_4ef3;
	case 20216ULL: goto x86_l_4ef8;
	case 20221ULL: goto x86_l_4efd;
	case 20226ULL: goto x86_l_4f02;
	case 20231ULL: goto x86_l_4f07;
	case 20233ULL: goto x86_l_4f09;
	case 20238ULL: goto x86_l_4f0e;
	case 20243ULL: goto x86_l_4f13;
	case 20248ULL: goto x86_l_4f18;
	case 20253ULL: goto x86_l_4f1d;
	case 20258ULL: goto x86_l_4f22;
	case 20263ULL: goto x86_l_4f27;
	case 20268ULL: goto x86_l_4f2c;
	case 20270ULL: goto x86_l_4f2e;
	case 20275ULL: goto x86_l_4f33;
	case 20280ULL: goto x86_l_4f38;
	case 20285ULL: goto x86_l_4f3d;
	case 20290ULL: goto x86_l_4f42;
	case 20295ULL: goto x86_l_4f47;
	case 20300ULL: goto x86_l_4f4c;
	case 20305ULL: goto x86_l_4f51;
	case 20308ULL: goto x86_l_4f54;
	case 20312ULL: goto x86_l_4f58;
	case 20317ULL: goto x86_l_4f5d;
	case 20320ULL: goto x86_l_4f60;
	case 20325ULL: goto x86_l_4f65;
	case 20328ULL: goto x86_l_4f68;
	case 20330ULL: goto x86_l_4f6a;
	case 20333ULL: goto x86_l_4f6d;
	case 20339ULL: goto x86_l_4f73;
	case 20343ULL: goto x86_l_4f77;
	case 20348ULL: goto x86_l_4f7c;
	case 20350ULL: goto x86_l_4f7e;
	case 20355ULL: goto x86_l_4f83;
	case 20363ULL: goto x86_l_4f8b;
	case 20368ULL: goto x86_l_4f90;
	case 20375ULL: goto x86_l_4f97;
	case 20380ULL: goto x86_l_4f9c;
	case 20382ULL: goto x86_l_4f9e;
	case 20385ULL: goto x86_l_4fa1;
	case 20391ULL: goto x86_l_4fa7;
	case 20397ULL: goto x86_l_4fad;
	case 20404ULL: goto x86_l_4fb4;
	case 20409ULL: goto x86_l_4fb9;
	case 20412ULL: goto x86_l_4fbc;
	case 20415ULL: goto x86_l_4fbf;
	case 20418ULL: goto x86_l_4fc2;
	case 20420ULL: goto x86_l_4fc4;
	case 20423ULL: goto x86_l_4fc7;
	case 20428ULL: goto x86_l_4fcc;
	case 20433ULL: goto x86_l_4fd1;
	case 20438ULL: goto x86_l_4fd6;
	case 20441ULL: goto x86_l_4fd9;
	case 20446ULL: goto x86_l_4fde;
	case 20449ULL: goto x86_l_4fe1;
	case 20454ULL: goto x86_l_4fe6;
	case 20457ULL: goto x86_l_4fe9;
	case 20462ULL: goto x86_l_4fee;
	case 20465ULL: goto x86_l_4ff1;
	case 20467ULL: goto x86_l_4ff3;
	case 20470ULL: goto x86_l_4ff6;
	case 20476ULL: goto x86_l_4ffc;
	case 20480ULL: goto x86_l_5000;
	case 20485ULL: goto x86_l_5005;
	case 20487ULL: goto x86_l_5007;
	case 20492ULL: goto x86_l_500c;
	case 20500ULL: goto x86_l_5014;
	case 20505ULL: goto x86_l_5019;
	case 20512ULL: goto x86_l_5020;
	case 20517ULL: goto x86_l_5025;
	case 20519ULL: goto x86_l_5027;
	case 20522ULL: goto x86_l_502a;
	case 20528ULL: goto x86_l_5030;
	case 20534ULL: goto x86_l_5036;
	case 20541ULL: goto x86_l_503d;
	case 20546ULL: goto x86_l_5042;
	case 20549ULL: goto x86_l_5045;
	case 20552ULL: goto x86_l_5048;
	case 20555ULL: goto x86_l_504b;
	case 20557ULL: goto x86_l_504d;
	case 20560ULL: goto x86_l_5050;
	case 20565ULL: goto x86_l_5055;
	case 20570ULL: goto x86_l_505a;
	case 20575ULL: goto x86_l_505f;
	case 20578ULL: goto x86_l_5062;
	case 20581ULL: goto x86_l_5065;
	case 20587ULL: goto x86_l_506b;
	case 20591ULL: goto x86_l_506f;
	case 20596ULL: goto x86_l_5074;
	case 20598ULL: goto x86_l_5076;
	case 20603ULL: goto x86_l_507b;
	case 20611ULL: goto x86_l_5083;
	case 20616ULL: goto x86_l_5088;
	case 20623ULL: goto x86_l_508f;
	case 20628ULL: goto x86_l_5094;
	case 20630ULL: goto x86_l_5096;
	case 20633ULL: goto x86_l_5099;
	case 20639ULL: goto x86_l_509f;
	case 20645ULL: goto x86_l_50a5;
	case 20652ULL: goto x86_l_50ac;
	case 20657ULL: goto x86_l_50b1;
	case 20660ULL: goto x86_l_50b4;
	case 20663ULL: goto x86_l_50b7;
	case 20666ULL: goto x86_l_50ba;
	case 20668ULL: goto x86_l_50bc;
	case 20671ULL: goto x86_l_50bf;
	case 20676ULL: goto x86_l_50c4;
	case 20679ULL: goto x86_l_50c7;
	case 20682ULL: goto x86_l_50ca;
	case 20687ULL: goto x86_l_50cf;
	case 20689ULL: goto x86_l_50d1;
	case 20692ULL: goto x86_l_50d4;
	case 20698ULL: goto x86_l_50da;
	case 20701ULL: goto x86_l_50dd;
	case 20703ULL: goto x86_l_50df;
	case 20706ULL: goto x86_l_50e2;
	case 20710ULL: goto x86_l_50e6;
	case 20715ULL: goto x86_l_50eb;
	case 20718ULL: goto x86_l_50ee;
	case 20720ULL: goto x86_l_50f0;
	case 20723ULL: goto x86_l_50f3;
	case 20728ULL: goto x86_l_50f8;
	case 20730ULL: goto x86_l_50fa;
	case 20733ULL: goto x86_l_50fd;
	case 20735ULL: goto x86_l_50ff;
	case 20740ULL: goto x86_l_5104;
	case 20743ULL: goto x86_l_5107;
	case 20745ULL: goto x86_l_5109;
	case 20750ULL: goto x86_l_510e;
	case 20755ULL: goto x86_l_5113;
	case 20758ULL: goto x86_l_5116;
	case 20761ULL: goto x86_l_5119;
	case 20767ULL: goto x86_l_511f;
	case 20771ULL: goto x86_l_5123;
	case 20776ULL: goto x86_l_5128;
	case 20778ULL: goto x86_l_512a;
	case 20783ULL: goto x86_l_512f;
	case 20791ULL: goto x86_l_5137;
	case 20796ULL: goto x86_l_513c;
	case 20803ULL: goto x86_l_5143;
	case 20808ULL: goto x86_l_5148;
	case 20810ULL: goto x86_l_514a;
	case 20813ULL: goto x86_l_514d;
	case 20819ULL: goto x86_l_5153;
	case 20825ULL: goto x86_l_5159;
	case 20832ULL: goto x86_l_5160;
	case 20837ULL: goto x86_l_5165;
	case 20840ULL: goto x86_l_5168;
	case 20843ULL: goto x86_l_516b;
	case 20846ULL: goto x86_l_516e;
	case 20848ULL: goto x86_l_5170;
	case 20851ULL: goto x86_l_5173;
	case 20856ULL: goto x86_l_5178;
	case 20859ULL: goto x86_l_517b;
	case 20862ULL: goto x86_l_517e;
	case 20864ULL: goto x86_l_5180;
	case 20867ULL: goto x86_l_5183;
	case 20873ULL: goto x86_l_5189;
	case 20876ULL: goto x86_l_518c;
	case 20878ULL: goto x86_l_518e;
	case 20881ULL: goto x86_l_5191;
	case 20885ULL: goto x86_l_5195;
	case 20890ULL: goto x86_l_519a;
	case 20893ULL: goto x86_l_519d;
	case 20895ULL: goto x86_l_519f;
	case 20898ULL: goto x86_l_51a2;
	case 20903ULL: goto x86_l_51a7;
	case 20905ULL: goto x86_l_51a9;
	case 20908ULL: goto x86_l_51ac;
	case 20910ULL: goto x86_l_51ae;
	case 20915ULL: goto x86_l_51b3;
	case 20918ULL: goto x86_l_51b6;
	case 20920ULL: goto x86_l_51b8;
	case 20925ULL: goto x86_l_51bd;
	case 20928ULL: goto x86_l_51c0;
	case 20933ULL: goto x86_l_51c5;
	case 20938ULL: goto x86_l_51ca;
	case 20941ULL: goto x86_l_51cd;
	case 20946ULL: goto x86_l_51d2;
	case 20949ULL: goto x86_l_51d5;
	case 20955ULL: goto x86_l_51db;
	case 20960ULL: goto x86_l_51e0;
	case 20963ULL: goto x86_l_51e3;
	case 20968ULL: goto x86_l_51e8;
	case 20973ULL: goto x86_l_51ed;
	case 20976ULL: goto x86_l_51f0;
	case 20981ULL: goto x86_l_51f5;
	case 20986ULL: goto x86_l_51fa;
	case 20989ULL: goto x86_l_51fd;
	default: return 0xffffffffffffffffULL;
	}
x86_l_4b59:
	/* 0x4b59: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b5e:
	/* 0x4b5e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b60:
	/* 0x4b60: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4b62:
	/* 0x4b62: js     510e <generic_sleepable_preload+0x510e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_510e;
	}
x86_l_4b68:
	/* 0x4b68: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b6d:
	/* 0x4b6d: cmp    WORD PTR [rcx+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_4b75:
	/* 0x4b75: je     5116 <generic_sleepable_preload+0x5116> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5116;
	}
x86_l_4b7b:
	/* 0x4b7b: mov    eax,DWORD PTR [rcx+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_4b81:
	/* 0x4b81: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4b85:
	/* 0x4b85: cmp    WORD PTR [rcx+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_4b8d:
	/* 0x4b8d: je     4baa <generic_sleepable_preload+0x4baa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4baa;
	}
x86_l_4b8f:
	/* 0x4b8f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4b94:
	/* 0x4b94: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4b98:
	/* 0x4b98: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4b9b:
	/* 0x4b9b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4ba0:
	/* 0x4ba0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ba2:
	/* 0x4ba2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4ba4:
	/* 0x4ba4: js     51ca <generic_sleepable_preload+0x51ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_51ca;
	}
x86_l_4baa:
	/* 0x4baa: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4baf:
	/* 0x4baf: cmp    WORD PTR [rcx+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_4bb7:
	/* 0x4bb7: je     5116 <generic_sleepable_preload+0x5116> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5116;
	}
x86_l_4bbd:
	/* 0x4bbd: mov    eax,DWORD PTR [rcx+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_4bc3:
	/* 0x4bc3: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4bc7:
	/* 0x4bc7: cmp    WORD PTR [rcx+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_4bcf:
	/* 0x4bcf: je     4bec <generic_sleepable_preload+0x4bec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bec;
	}
x86_l_4bd1:
	/* 0x4bd1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4bd6:
	/* 0x4bd6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4bda:
	/* 0x4bda: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4bdd:
	/* 0x4bdd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4be2:
	/* 0x4be2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4be4:
	/* 0x4be4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4be6:
	/* 0x4be6: js     52e2 <generic_sleepable_preload+0x52e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21218ULL;
	}
x86_l_4bec:
	/* 0x4bec: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4bf1:
	/* 0x4bf1: cmp    WORD PTR [rcx+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_4bf9:
	/* 0x4bf9: je     5116 <generic_sleepable_preload+0x5116> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5116;
	}
x86_l_4bff:
	/* 0x4bff: mov    eax,DWORD PTR [rcx+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_4c05:
	/* 0x4c05: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4c09:
	/* 0x4c09: cmp    WORD PTR [rcx+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_4c11:
	/* 0x4c11: je     5116 <generic_sleepable_preload+0x5116> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5116;
	}
x86_l_4c17:
	/* 0x4c17: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4c1c:
	/* 0x4c1c: jmp    4e81 <generic_sleepable_preload+0x4e81> */
	goto x86_l_4e81;
x86_l_4c21:
	/* 0x4c21: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_4c24:
	/* 0x4c24: je     4c41 <generic_sleepable_preload+0x4c41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4c41;
	}
x86_l_4c26:
	/* 0x4c26: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4c2b:
	/* 0x4c2b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c2f:
	/* 0x4c2f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4c32:
	/* 0x4c32: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4c37:
	/* 0x4c37: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c39:
	/* 0x4c39: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4c3b:
	/* 0x4c3b: js     4ea1 <generic_sleepable_preload+0x4ea1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4ea1;
	}
x86_l_4c41:
	/* 0x4c41: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c46:
	/* 0x4c46: cmp    WORD PTR [rcx+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_4c4e:
	/* 0x4c4e: je     5116 <generic_sleepable_preload+0x5116> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5116;
	}
x86_l_4c54:
	/* 0x4c54: mov    eax,DWORD PTR [rcx+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_4c5a:
	/* 0x4c5a: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4c5e:
	/* 0x4c5e: cmp    WORD PTR [rcx+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_4c66:
	/* 0x4c66: je     4c83 <generic_sleepable_preload+0x4c83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4c83;
	}
x86_l_4c68:
	/* 0x4c68: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4c6d:
	/* 0x4c6d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c71:
	/* 0x4c71: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4c74:
	/* 0x4c74: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4c79:
	/* 0x4c79: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c7b:
	/* 0x4c7b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4c7d:
	/* 0x4c7d: js     4eab <generic_sleepable_preload+0x4eab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4eab;
	}
x86_l_4c83:
	/* 0x4c83: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c88:
	/* 0x4c88: cmp    WORD PTR [rcx+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_4c90:
	/* 0x4c90: je     5116 <generic_sleepable_preload+0x5116> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5116;
	}
x86_l_4c96:
	/* 0x4c96: mov    eax,DWORD PTR [rcx+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_4c9c:
	/* 0x4c9c: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4ca0:
	/* 0x4ca0: cmp    WORD PTR [rcx+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_4ca8:
	/* 0x4ca8: je     4cc5 <generic_sleepable_preload+0x4cc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4cc5;
	}
x86_l_4caa:
	/* 0x4caa: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4caf:
	/* 0x4caf: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4cb3:
	/* 0x4cb3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4cb6:
	/* 0x4cb6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4cbb:
	/* 0x4cbb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4cbd:
	/* 0x4cbd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4cbf:
	/* 0x4cbf: js     4ed3 <generic_sleepable_preload+0x4ed3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4ed3;
	}
x86_l_4cc5:
	/* 0x4cc5: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4cca:
	/* 0x4cca: cmp    WORD PTR [rcx+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_4cd2:
	/* 0x4cd2: je     5116 <generic_sleepable_preload+0x5116> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5116;
	}
x86_l_4cd8:
	/* 0x4cd8: mov    eax,DWORD PTR [rcx+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_4cde:
	/* 0x4cde: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4ce2:
	/* 0x4ce2: cmp    WORD PTR [rcx+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_4cea:
	/* 0x4cea: je     4d07 <generic_sleepable_preload+0x4d07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4d07;
	}
x86_l_4cec:
	/* 0x4cec: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4cf1:
	/* 0x4cf1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4cf5:
	/* 0x4cf5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4cf8:
	/* 0x4cf8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4cfd:
	/* 0x4cfd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4cff:
	/* 0x4cff: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4d01:
	/* 0x4d01: js     4ef8 <generic_sleepable_preload+0x4ef8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4ef8;
	}
x86_l_4d07:
	/* 0x4d07: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4d0c:
	/* 0x4d0c: cmp    WORD PTR [rcx+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_4d14:
	/* 0x4d14: je     5116 <generic_sleepable_preload+0x5116> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5116;
	}
x86_l_4d1a:
	/* 0x4d1a: mov    eax,DWORD PTR [rcx+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_4d20:
	/* 0x4d20: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4d24:
	/* 0x4d24: cmp    WORD PTR [rcx+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_4d2c:
	/* 0x4d2c: je     4d49 <generic_sleepable_preload+0x4d49> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4d49;
	}
x86_l_4d2e:
	/* 0x4d2e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4d33:
	/* 0x4d33: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d37:
	/* 0x4d37: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4d3a:
	/* 0x4d3a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4d3f:
	/* 0x4d3f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d41:
	/* 0x4d41: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4d43:
	/* 0x4d43: js     4f1d <generic_sleepable_preload+0x4f1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4f1d;
	}
x86_l_4d49:
	/* 0x4d49: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4d4e:
	/* 0x4d4e: cmp    WORD PTR [rcx+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_4d56:
	/* 0x4d56: je     5116 <generic_sleepable_preload+0x5116> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5116;
	}
x86_l_4d5c:
	/* 0x4d5c: mov    eax,DWORD PTR [rcx+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_4d62:
	/* 0x4d62: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4d66:
	/* 0x4d66: cmp    WORD PTR [rcx+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_4d6e:
	/* 0x4d6e: je     4d8b <generic_sleepable_preload+0x4d8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4d8b;
	}
x86_l_4d70:
	/* 0x4d70: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4d75:
	/* 0x4d75: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d79:
	/* 0x4d79: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4d7c:
	/* 0x4d7c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4d81:
	/* 0x4d81: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d83:
	/* 0x4d83: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4d85:
	/* 0x4d85: js     4f42 <generic_sleepable_preload+0x4f42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4f42;
	}
x86_l_4d8b:
	/* 0x4d8b: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4d90:
	/* 0x4d90: cmp    WORD PTR [rcx+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_4d98:
	/* 0x4d98: je     5116 <generic_sleepable_preload+0x5116> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5116;
	}
x86_l_4d9e:
	/* 0x4d9e: mov    eax,DWORD PTR [rcx+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_4da4:
	/* 0x4da4: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4da8:
	/* 0x4da8: cmp    WORD PTR [rcx+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_4db0:
	/* 0x4db0: je     4dcd <generic_sleepable_preload+0x4dcd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4dcd;
	}
x86_l_4db2:
	/* 0x4db2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4db7:
	/* 0x4db7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4dbb:
	/* 0x4dbb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4dbe:
	/* 0x4dbe: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4dc3:
	/* 0x4dc3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4dc5:
	/* 0x4dc5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4dc7:
	/* 0x4dc7: js     510e <generic_sleepable_preload+0x510e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_510e;
	}
x86_l_4dcd:
	/* 0x4dcd: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4dd2:
	/* 0x4dd2: cmp    WORD PTR [rcx+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_4dda:
	/* 0x4dda: je     5116 <generic_sleepable_preload+0x5116> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5116;
	}
x86_l_4de0:
	/* 0x4de0: mov    eax,DWORD PTR [rcx+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_4de6:
	/* 0x4de6: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4dea:
	/* 0x4dea: cmp    WORD PTR [rcx+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_4df2:
	/* 0x4df2: je     4e0f <generic_sleepable_preload+0x4e0f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4e0f;
	}
x86_l_4df4:
	/* 0x4df4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4df9:
	/* 0x4df9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4dfd:
	/* 0x4dfd: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4e00:
	/* 0x4e00: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e05:
	/* 0x4e05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e07:
	/* 0x4e07: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4e09:
	/* 0x4e09: js     51ca <generic_sleepable_preload+0x51ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_51ca;
	}
x86_l_4e0f:
	/* 0x4e0f: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e14:
	/* 0x4e14: cmp    WORD PTR [rcx+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_4e1c:
	/* 0x4e1c: je     5116 <generic_sleepable_preload+0x5116> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5116;
	}
x86_l_4e22:
	/* 0x4e22: mov    eax,DWORD PTR [rcx+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_4e28:
	/* 0x4e28: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4e2c:
	/* 0x4e2c: cmp    WORD PTR [rcx+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_4e34:
	/* 0x4e34: je     4e51 <generic_sleepable_preload+0x4e51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4e51;
	}
x86_l_4e36:
	/* 0x4e36: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4e3b:
	/* 0x4e3b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e3f:
	/* 0x4e3f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4e42:
	/* 0x4e42: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e47:
	/* 0x4e47: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e49:
	/* 0x4e49: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4e4b:
	/* 0x4e4b: js     52e2 <generic_sleepable_preload+0x52e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21218ULL;
	}
x86_l_4e51:
	/* 0x4e51: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e56:
	/* 0x4e56: cmp    WORD PTR [rcx+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_4e5e:
	/* 0x4e5e: je     5116 <generic_sleepable_preload+0x5116> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5116;
	}
x86_l_4e64:
	/* 0x4e64: mov    eax,DWORD PTR [rcx+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_4e6a:
	/* 0x4e6a: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4e6e:
	/* 0x4e6e: cmp    WORD PTR [rcx+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_4e76:
	/* 0x4e76: je     5116 <generic_sleepable_preload+0x5116> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5116;
	}
x86_l_4e7c:
	/* 0x4e7c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4e81:
	/* 0x4e81: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e85:
	/* 0x4e85: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4e88:
	/* 0x4e88: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e8d:
	/* 0x4e8d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e8f:
	/* 0x4e8f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4e91:
	/* 0x4e91: jns    5116 <generic_sleepable_preload+0x5116> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_5116;
	}
x86_l_4e97:
	/* 0x4e97: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_4e9c:
	/* 0x4e9c: jmp    5113 <generic_sleepable_preload+0x5113> */
	goto x86_l_5113;
x86_l_4ea1:
	/* 0x4ea1: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_4ea6:
	/* 0x4ea6: jmp    5113 <generic_sleepable_preload+0x5113> */
	goto x86_l_5113;
x86_l_4eab:
	/* 0x4eab: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_4eb0:
	/* 0x4eb0: jmp    5113 <generic_sleepable_preload+0x5113> */
	goto x86_l_5113;
x86_l_4eb5:
	/* 0x4eb5: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_4eba:
	/* 0x4eba: jmp    4f51 <generic_sleepable_preload+0x4f51> */
	goto x86_l_4f51;
x86_l_4ebf:
	/* 0x4ebf: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_4ec4:
	/* 0x4ec4: jmp    4fd6 <generic_sleepable_preload+0x4fd6> */
	goto x86_l_4fd6;
x86_l_4ec9:
	/* 0x4ec9: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_4ece:
	/* 0x4ece: jmp    505f <generic_sleepable_preload+0x505f> */
	goto x86_l_505f;
x86_l_4ed3:
	/* 0x4ed3: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_4ed8:
	/* 0x4ed8: jmp    5113 <generic_sleepable_preload+0x5113> */
	goto x86_l_5113;
x86_l_4edd:
	/* 0x4edd: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_4ee2:
	/* 0x4ee2: jmp    4f51 <generic_sleepable_preload+0x4f51> */
	goto x86_l_4f51;
x86_l_4ee4:
	/* 0x4ee4: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_4ee9:
	/* 0x4ee9: jmp    4fd6 <generic_sleepable_preload+0x4fd6> */
	goto x86_l_4fd6;
x86_l_4eee:
	/* 0x4eee: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_4ef3:
	/* 0x4ef3: jmp    505f <generic_sleepable_preload+0x505f> */
	goto x86_l_505f;
x86_l_4ef8:
	/* 0x4ef8: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_4efd:
	/* 0x4efd: jmp    5113 <generic_sleepable_preload+0x5113> */
	goto x86_l_5113;
x86_l_4f02:
	/* 0x4f02: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_4f07:
	/* 0x4f07: jmp    4f51 <generic_sleepable_preload+0x4f51> */
	goto x86_l_4f51;
x86_l_4f09:
	/* 0x4f09: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_4f0e:
	/* 0x4f0e: jmp    4fd6 <generic_sleepable_preload+0x4fd6> */
	goto x86_l_4fd6;
x86_l_4f13:
	/* 0x4f13: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_4f18:
	/* 0x4f18: jmp    505f <generic_sleepable_preload+0x505f> */
	goto x86_l_505f;
x86_l_4f1d:
	/* 0x4f1d: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_4f22:
	/* 0x4f22: jmp    5113 <generic_sleepable_preload+0x5113> */
	goto x86_l_5113;
x86_l_4f27:
	/* 0x4f27: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_4f2c:
	/* 0x4f2c: jmp    4f51 <generic_sleepable_preload+0x4f51> */
	goto x86_l_4f51;
x86_l_4f2e:
	/* 0x4f2e: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_4f33:
	/* 0x4f33: jmp    4fd6 <generic_sleepable_preload+0x4fd6> */
	goto x86_l_4fd6;
x86_l_4f38:
	/* 0x4f38: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_4f3d:
	/* 0x4f3d: jmp    505f <generic_sleepable_preload+0x505f> */
	goto x86_l_505f;
x86_l_4f42:
	/* 0x4f42: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_4f47:
	/* 0x4f47: jmp    5113 <generic_sleepable_preload+0x5113> */
	goto x86_l_5113;
x86_l_4f4c:
	/* 0x4f4c: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_4f51:
	/* 0x4f51: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4f54:
	/* 0x4f54: mov    ebx,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4f58:
	/* 0x4f58: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4f5d:
	/* 0x4f5d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4f60:
	/* 0x4f60: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f65:
	/* 0x4f65: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_4f68:
	/* 0x4f68: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f6a:
	/* 0x4f6a: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_4f6d:
	/* 0x4f6d: jne    35f4 <generic_sleepable_preload+0x35f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13812ULL;
	}
x86_l_4f73:
	/* 0x4f73: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f77:
	/* 0x4f77: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_4f7c:
	/* 0x4f7c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f7e:
	/* 0x4f7e: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4f83:
	/* 0x4f83: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_4f8b:
	/* 0x4f8b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4f90:
	/* 0x4f90: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_4f97:
	/* 0x4f97: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_4f9c:
	/* 0x4f9c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f9e:
	/* 0x4f9e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4fa1:
	/* 0x4fa1: je     35f4 <generic_sleepable_preload+0x35f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13812ULL;
	}
x86_l_4fa7:
	/* 0x4fa7: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_4fad:
	/* 0x4fad: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_4fb4:
	/* 0x4fb4: lea    r13,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4fb9:
	/* 0x4fb9: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4fbc:
	/* 0x4fbc: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_4fbf:
	/* 0x4fbf: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_4fc2:
	/* 0x4fc2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4fc4:
	/* 0x4fc4: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_4fc7:
	/* 0x4fc7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4fcc:
	/* 0x4fcc: jmp    50c4 <generic_sleepable_preload+0x50c4> */
	goto x86_l_50c4;
x86_l_4fd1:
	/* 0x4fd1: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_4fd6:
	/* 0x4fd6: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4fd9:
	/* 0x4fd9: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4fde:
	/* 0x4fde: mov    ebx,DWORD PTR [rax+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_4fe1:
	/* 0x4fe1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4fe6:
	/* 0x4fe6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4fe9:
	/* 0x4fe9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4fee:
	/* 0x4fee: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_4ff1:
	/* 0x4ff1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ff3:
	/* 0x4ff3: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_4ff6:
	/* 0x4ff6: jne    35ff <generic_sleepable_preload+0x35ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13823ULL;
	}
x86_l_4ffc:
	/* 0x4ffc: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5000:
	/* 0x5000: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_5005:
	/* 0x5005: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5007:
	/* 0x5007: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_500c:
	/* 0x500c: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_5014:
	/* 0x5014: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5019:
	/* 0x5019: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_5020:
	/* 0x5020: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5025:
	/* 0x5025: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5027:
	/* 0x5027: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_502a:
	/* 0x502a: je     35ff <generic_sleepable_preload+0x35ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13823ULL;
	}
x86_l_5030:
	/* 0x5030: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_5036:
	/* 0x5036: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_503d:
	/* 0x503d: lea    r15,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5042:
	/* 0x5042: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_5045:
	/* 0x5045: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_5048:
	/* 0x5048: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_504b:
	/* 0x504b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_504d:
	/* 0x504d: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5050:
	/* 0x5050: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5055:
	/* 0x5055: jmp    5178 <generic_sleepable_preload+0x5178> */
	goto x86_l_5178;
x86_l_505a:
	/* 0x505a: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_505f:
	/* 0x505f: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5062:
	/* 0x5062: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_5065:
	/* 0x5065: jne    35f4 <generic_sleepable_preload+0x35f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13812ULL;
	}
x86_l_506b:
	/* 0x506b: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_506f:
	/* 0x506f: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_5074:
	/* 0x5074: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5076:
	/* 0x5076: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_507b:
	/* 0x507b: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_5083:
	/* 0x5083: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5088:
	/* 0x5088: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_508f:
	/* 0x508f: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5094:
	/* 0x5094: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5096:
	/* 0x5096: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5099:
	/* 0x5099: je     35f4 <generic_sleepable_preload+0x35f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13812ULL;
	}
x86_l_509f:
	/* 0x509f: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_50a5:
	/* 0x50a5: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_50ac:
	/* 0x50ac: lea    r13,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_50b1:
	/* 0x50b1: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_50b4:
	/* 0x50b4: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_50b7:
	/* 0x50b7: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_50ba:
	/* 0x50ba: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_50bc:
	/* 0x50bc: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_50bf:
	/* 0x50bf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_50c4:
	/* 0x50c4: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_50c7:
	/* 0x50c7: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_50ca:
	/* 0x50ca: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_50cf:
	/* 0x50cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50d1:
	/* 0x50d1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_50d4:
	/* 0x50d4: je     35f4 <generic_sleepable_preload+0x35f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13812ULL;
	}
x86_l_50da:
	/* 0x50da: test   r14b,r14b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_8);
x86_l_50dd:
	/* 0x50dd: je     5107 <generic_sleepable_preload+0x5107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5107;
	}
x86_l_50df:
	/* 0x50df: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_50e2:
	/* 0x50e2: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_50e6:
	/* 0x50e6: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_50eb:
	/* 0x50eb: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_50ee:
	/* 0x50ee: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_50f0:
	/* 0x50f0: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_50f3:
	/* 0x50f3: call   50f8 <generic_sleepable_preload+0x50f8> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_50f8:
	/* 0x50f8: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_50fa:
	/* 0x50fa: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_50fd:
	/* 0x50fd: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_50ff:
	/* 0x50ff: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_5104:
	/* 0x5104: cmovs  ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_5107:
	/* 0x5107: mov    DWORD PTR [rax],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5109:
	/* 0x5109: jmp    35f4 <generic_sleepable_preload+0x35f4> */
	return 13812ULL;
x86_l_510e:
	/* 0x510e: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_5113:
	/* 0x5113: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5116:
	/* 0x5116: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_5119:
	/* 0x5119: jne    35ff <generic_sleepable_preload+0x35ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13823ULL;
	}
x86_l_511f:
	/* 0x511f: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5123:
	/* 0x5123: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_5128:
	/* 0x5128: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_512a:
	/* 0x512a: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_512f:
	/* 0x512f: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_5137:
	/* 0x5137: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_513c:
	/* 0x513c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_5143:
	/* 0x5143: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5148:
	/* 0x5148: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_514a:
	/* 0x514a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_514d:
	/* 0x514d: je     35ff <generic_sleepable_preload+0x35ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13823ULL;
	}
x86_l_5153:
	/* 0x5153: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_5159:
	/* 0x5159: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_5160:
	/* 0x5160: lea    r15,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5165:
	/* 0x5165: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_5168:
	/* 0x5168: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_516b:
	/* 0x516b: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_516e:
	/* 0x516e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5170:
	/* 0x5170: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5173:
	/* 0x5173: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5178:
	/* 0x5178: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_517b:
	/* 0x517b: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_517e:
	/* 0x517e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5180:
	/* 0x5180: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5183:
	/* 0x5183: je     35ff <generic_sleepable_preload+0x35ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13823ULL;
	}
x86_l_5189:
	/* 0x5189: test   r13b,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_8);
x86_l_518c:
	/* 0x518c: je     51b6 <generic_sleepable_preload+0x51b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_51b6;
	}
x86_l_518e:
	/* 0x518e: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_5191:
	/* 0x5191: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_5195:
	/* 0x5195: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_519a:
	/* 0x519a: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_519d:
	/* 0x519d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_519f:
	/* 0x519f: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_51a2:
	/* 0x51a2: call   51a7 <generic_sleepable_preload+0x51a7> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_51a7:
	/* 0x51a7: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_51a9:
	/* 0x51a9: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_51ac:
	/* 0x51ac: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_51ae:
	/* 0x51ae: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_51b3:
	/* 0x51b3: cmovs  ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_51b6:
	/* 0x51b6: mov    DWORD PTR [rax],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_51b8:
	/* 0x51b8: jmp    35ff <generic_sleepable_preload+0x35ff> */
	return 13823ULL;
x86_l_51bd:
	/* 0x51bd: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_51c0:
	/* 0x51c0: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_51c5:
	/* 0x51c5: jmp    4fd9 <generic_sleepable_preload+0x4fd9> */
	goto x86_l_4fd9;
x86_l_51ca:
	/* 0x51ca: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_51cd:
	/* 0x51cd: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_51d2:
	/* 0x51d2: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_51d5:
	/* 0x51d5: jne    35ff <generic_sleepable_preload+0x35ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13823ULL;
	}
x86_l_51db:
	/* 0x51db: jmp    511f <generic_sleepable_preload+0x511f> */
	goto x86_l_511f;
x86_l_51e0:
	/* 0x51e0: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_51e3:
	/* 0x51e3: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_51e8:
	/* 0x51e8: jmp    19cf <generic_sleepable_preload+0x19cf> */
	return 6607ULL;
x86_l_51ed:
	/* 0x51ed: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_51f0:
	/* 0x51f0: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_51f5:
	/* 0x51f5: jmp    1a51 <generic_sleepable_preload+0x1a51> */
	return 6737ULL;
x86_l_51fa:
	/* 0x51fa: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_51fd:
	/* 0x51fd: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
	return 20994ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_12(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 20994ULL: goto x86_l_5202;
	case 20999ULL: goto x86_l_5207;
	case 21002ULL: goto x86_l_520a;
	case 21007ULL: goto x86_l_520f;
	case 21012ULL: goto x86_l_5214;
	case 21015ULL: goto x86_l_5217;
	case 21020ULL: goto x86_l_521c;
	case 21025ULL: goto x86_l_5221;
	case 21028ULL: goto x86_l_5224;
	case 21033ULL: goto x86_l_5229;
	case 21038ULL: goto x86_l_522e;
	case 21041ULL: goto x86_l_5231;
	case 21046ULL: goto x86_l_5236;
	case 21051ULL: goto x86_l_523b;
	case 21054ULL: goto x86_l_523e;
	case 21059ULL: goto x86_l_5243;
	case 21064ULL: goto x86_l_5248;
	case 21069ULL: goto x86_l_524d;
	case 21072ULL: goto x86_l_5250;
	case 21077ULL: goto x86_l_5255;
	case 21082ULL: goto x86_l_525a;
	case 21087ULL: goto x86_l_525f;
	case 21090ULL: goto x86_l_5262;
	case 21095ULL: goto x86_l_5267;
	case 21100ULL: goto x86_l_526c;
	case 21105ULL: goto x86_l_5271;
	case 21108ULL: goto x86_l_5274;
	case 21113ULL: goto x86_l_5279;
	case 21118ULL: goto x86_l_527e;
	case 21123ULL: goto x86_l_5283;
	case 21126ULL: goto x86_l_5286;
	case 21131ULL: goto x86_l_528b;
	case 21136ULL: goto x86_l_5290;
	case 21141ULL: goto x86_l_5295;
	case 21144ULL: goto x86_l_5298;
	case 21149ULL: goto x86_l_529d;
	case 21154ULL: goto x86_l_52a2;
	case 21159ULL: goto x86_l_52a7;
	case 21162ULL: goto x86_l_52aa;
	case 21167ULL: goto x86_l_52af;
	case 21172ULL: goto x86_l_52b4;
	case 21177ULL: goto x86_l_52b9;
	case 21180ULL: goto x86_l_52bc;
	case 21185ULL: goto x86_l_52c1;
	case 21190ULL: goto x86_l_52c6;
	case 21195ULL: goto x86_l_52cb;
	case 21200ULL: goto x86_l_52d0;
	case 21205ULL: goto x86_l_52d5;
	case 21208ULL: goto x86_l_52d8;
	case 21213ULL: goto x86_l_52dd;
	case 21218ULL: goto x86_l_52e2;
	case 21223ULL: goto x86_l_52e7;
	case 21228ULL: goto x86_l_52ec;
	case 21231ULL: goto x86_l_52ef;
	case 21236ULL: goto x86_l_52f4;
	case 21241ULL: goto x86_l_52f9;
	case 21246ULL: goto x86_l_52fe;
	case 21249ULL: goto x86_l_5301;
	case 21254ULL: goto x86_l_5306;
	case 21259ULL: goto x86_l_530b;
	case 21264ULL: goto x86_l_5310;
	case 21267ULL: goto x86_l_5313;
	case 21272ULL: goto x86_l_5318;
	case 21277ULL: goto x86_l_531d;
	case 21282ULL: goto x86_l_5322;
	case 21285ULL: goto x86_l_5325;
	case 21290ULL: goto x86_l_532a;
	case 21295ULL: goto x86_l_532f;
	case 21300ULL: goto x86_l_5334;
	case 21303ULL: goto x86_l_5337;
	case 21308ULL: goto x86_l_533c;
	case 21313ULL: goto x86_l_5341;
	case 21318ULL: goto x86_l_5346;
	case 21321ULL: goto x86_l_5349;
	case 21326ULL: goto x86_l_534e;
	case 21331ULL: goto x86_l_5353;
	case 21336ULL: goto x86_l_5358;
	case 21339ULL: goto x86_l_535b;
	case 21344ULL: goto x86_l_5360;
	case 21349ULL: goto x86_l_5365;
	case 21354ULL: goto x86_l_536a;
	case 21357ULL: goto x86_l_536d;
	case 21362ULL: goto x86_l_5372;
	case 21367ULL: goto x86_l_5377;
	default: return 0xffffffffffffffffULL;
	}
x86_l_5202:
	/* 0x5202: jmp    274b <generic_sleepable_preload+0x274b> */
	return 10059ULL;
x86_l_5207:
	/* 0x5207: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_520a:
	/* 0x520a: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_520f:
	/* 0x520f: jmp    27cd <generic_sleepable_preload+0x27cd> */
	return 10189ULL;
x86_l_5214:
	/* 0x5214: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5217:
	/* 0x5217: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_521c:
	/* 0x521c: jmp    34c8 <generic_sleepable_preload+0x34c8> */
	return 13512ULL;
x86_l_5221:
	/* 0x5221: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5224:
	/* 0x5224: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5229:
	/* 0x5229: jmp    354a <generic_sleepable_preload+0x354a> */
	return 13642ULL;
x86_l_522e:
	/* 0x522e: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5231:
	/* 0x5231: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5236:
	/* 0x5236: jmp    4f54 <generic_sleepable_preload+0x4f54> */
	return 20308ULL;
x86_l_523b:
	/* 0x523b: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_523e:
	/* 0x523e: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5243:
	/* 0x5243: jmp    5062 <generic_sleepable_preload+0x5062> */
	return 20578ULL;
x86_l_5248:
	/* 0x5248: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_524d:
	/* 0x524d: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5250:
	/* 0x5250: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5255:
	/* 0x5255: jmp    19cf <generic_sleepable_preload+0x19cf> */
	return 6607ULL;
x86_l_525a:
	/* 0x525a: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_525f:
	/* 0x525f: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5262:
	/* 0x5262: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5267:
	/* 0x5267: jmp    1a51 <generic_sleepable_preload+0x1a51> */
	return 6737ULL;
x86_l_526c:
	/* 0x526c: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_5271:
	/* 0x5271: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5274:
	/* 0x5274: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5279:
	/* 0x5279: jmp    274b <generic_sleepable_preload+0x274b> */
	return 10059ULL;
x86_l_527e:
	/* 0x527e: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_5283:
	/* 0x5283: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5286:
	/* 0x5286: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_528b:
	/* 0x528b: jmp    27cd <generic_sleepable_preload+0x27cd> */
	return 10189ULL;
x86_l_5290:
	/* 0x5290: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_5295:
	/* 0x5295: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5298:
	/* 0x5298: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_529d:
	/* 0x529d: jmp    34c8 <generic_sleepable_preload+0x34c8> */
	return 13512ULL;
x86_l_52a2:
	/* 0x52a2: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_52a7:
	/* 0x52a7: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_52aa:
	/* 0x52aa: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52af:
	/* 0x52af: jmp    354a <generic_sleepable_preload+0x354a> */
	return 13642ULL;
x86_l_52b4:
	/* 0x52b4: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_52b9:
	/* 0x52b9: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_52bc:
	/* 0x52bc: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52c1:
	/* 0x52c1: jmp    4f54 <generic_sleepable_preload+0x4f54> */
	return 20308ULL;
x86_l_52c6:
	/* 0x52c6: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_52cb:
	/* 0x52cb: jmp    4fd6 <generic_sleepable_preload+0x4fd6> */
	return 20438ULL;
x86_l_52d0:
	/* 0x52d0: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_52d5:
	/* 0x52d5: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_52d8:
	/* 0x52d8: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52dd:
	/* 0x52dd: jmp    5062 <generic_sleepable_preload+0x5062> */
	return 20578ULL;
x86_l_52e2:
	/* 0x52e2: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_52e7:
	/* 0x52e7: jmp    5113 <generic_sleepable_preload+0x5113> */
	return 20755ULL;
x86_l_52ec:
	/* 0x52ec: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_52ef:
	/* 0x52ef: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_52f4:
	/* 0x52f4: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52f9:
	/* 0x52f9: jmp    19cf <generic_sleepable_preload+0x19cf> */
	return 6607ULL;
x86_l_52fe:
	/* 0x52fe: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5301:
	/* 0x5301: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5306:
	/* 0x5306: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_530b:
	/* 0x530b: jmp    1a51 <generic_sleepable_preload+0x1a51> */
	return 6737ULL;
x86_l_5310:
	/* 0x5310: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5313:
	/* 0x5313: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5318:
	/* 0x5318: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_531d:
	/* 0x531d: jmp    274b <generic_sleepable_preload+0x274b> */
	return 10059ULL;
x86_l_5322:
	/* 0x5322: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5325:
	/* 0x5325: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_532a:
	/* 0x532a: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_532f:
	/* 0x532f: jmp    27cd <generic_sleepable_preload+0x27cd> */
	return 10189ULL;
x86_l_5334:
	/* 0x5334: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5337:
	/* 0x5337: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_533c:
	/* 0x533c: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5341:
	/* 0x5341: jmp    34c8 <generic_sleepable_preload+0x34c8> */
	return 13512ULL;
x86_l_5346:
	/* 0x5346: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5349:
	/* 0x5349: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_534e:
	/* 0x534e: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5353:
	/* 0x5353: jmp    354a <generic_sleepable_preload+0x354a> */
	return 13642ULL;
x86_l_5358:
	/* 0x5358: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_535b:
	/* 0x535b: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5360:
	/* 0x5360: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5365:
	/* 0x5365: jmp    4f54 <generic_sleepable_preload+0x4f54> */
	return 20308ULL;
x86_l_536a:
	/* 0x536a: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_536d:
	/* 0x536d: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5372:
	/* 0x5372: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5377:
	/* 0x5377: jmp    5062 <generic_sleepable_preload+0x5062> */
	return 20578ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 18768U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1629ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1631ULL && __x86_pc <= 3184ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3189ULL && __x86_pc <= 4945ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 4947ULL && __x86_pc <= 6719ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 6722ULL && __x86_pc <= 8497ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8502ULL && __x86_pc <= 10275ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10278ULL && __x86_pc <= 12048ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12053ULL && __x86_pc <= 13810ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 13812ULL && __x86_pc <= 15639ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_8(__x86_state, __x86_pc);
		else if (__x86_pc >= 15644ULL && __x86_pc <= 17450ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_9(__x86_state, __x86_pc);
		else if (__x86_pc >= 17452ULL && __x86_pc <= 19286ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_10(__x86_state, __x86_pc);
		else if (__x86_pc >= 19289ULL && __x86_pc <= 20989ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_11(__x86_state, __x86_pc);
		else if (__x86_pc >= 20994ULL && __x86_pc <= 21367ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_12(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

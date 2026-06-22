extern char CONFIG_ITER_NUM;
extern char config_map;
extern char heap_ro_zero;
extern char sleepable_preload;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_0(
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
	case 17ULL: goto x86_l_11;
	case 22ULL: goto x86_l_16;
	case 27ULL: goto x86_l_1b;
	case 29ULL: goto x86_l_1d;
	case 36ULL: goto x86_l_24;
	case 43ULL: goto x86_l_2b;
	case 51ULL: goto x86_l_33;
	case 56ULL: goto x86_l_38;
	case 58ULL: goto x86_l_3a;
	case 61ULL: goto x86_l_3d;
	case 67ULL: goto x86_l_43;
	case 70ULL: goto x86_l_46;
	case 77ULL: goto x86_l_4d;
	case 82ULL: goto x86_l_52;
	case 89ULL: goto x86_l_59;
	case 94ULL: goto x86_l_5e;
	case 101ULL: goto x86_l_65;
	case 106ULL: goto x86_l_6a;
	case 110ULL: goto x86_l_6e;
	case 118ULL: goto x86_l_76;
	case 122ULL: goto x86_l_7a;
	case 127ULL: goto x86_l_7f;
	case 131ULL: goto x86_l_83;
	case 139ULL: goto x86_l_8b;
	case 143ULL: goto x86_l_8f;
	case 148ULL: goto x86_l_94;
	case 152ULL: goto x86_l_98;
	case 160ULL: goto x86_l_a0;
	case 164ULL: goto x86_l_a4;
	case 169ULL: goto x86_l_a9;
	case 173ULL: goto x86_l_ad;
	case 181ULL: goto x86_l_b5;
	case 185ULL: goto x86_l_b9;
	case 190ULL: goto x86_l_be;
	case 194ULL: goto x86_l_c2;
	case 202ULL: goto x86_l_ca;
	case 206ULL: goto x86_l_ce;
	case 211ULL: goto x86_l_d3;
	case 215ULL: goto x86_l_d7;
	case 223ULL: goto x86_l_df;
	case 227ULL: goto x86_l_e3;
	case 232ULL: goto x86_l_e8;
	case 235ULL: goto x86_l_eb;
	case 239ULL: goto x86_l_ef;
	case 247ULL: goto x86_l_f7;
	case 251ULL: goto x86_l_fb;
	case 256ULL: goto x86_l_100;
	case 261ULL: goto x86_l_105;
	case 267ULL: goto x86_l_10b;
	case 271ULL: goto x86_l_10f;
	case 274ULL: goto x86_l_112;
	case 281ULL: goto x86_l_119;
	case 287ULL: goto x86_l_11f;
	case 292ULL: goto x86_l_124;
	case 294ULL: goto x86_l_126;
	case 297ULL: goto x86_l_129;
	case 302ULL: goto x86_l_12e;
	case 307ULL: goto x86_l_133;
	case 311ULL: goto x86_l_137;
	case 315ULL: goto x86_l_13b;
	case 319ULL: goto x86_l_13f;
	case 326ULL: goto x86_l_146;
	case 332ULL: goto x86_l_14c;
	case 336ULL: goto x86_l_150;
	case 341ULL: goto x86_l_155;
	case 343ULL: goto x86_l_157;
	case 345ULL: goto x86_l_159;
	case 347ULL: goto x86_l_15b;
	case 351ULL: goto x86_l_15f;
	case 354ULL: goto x86_l_162;
	case 360ULL: goto x86_l_168;
	case 363ULL: goto x86_l_16b;
	case 369ULL: goto x86_l_171;
	case 374ULL: goto x86_l_176;
	case 377ULL: goto x86_l_179;
	case 383ULL: goto x86_l_17f;
	case 386ULL: goto x86_l_182;
	case 392ULL: goto x86_l_188;
	case 397ULL: goto x86_l_18d;
	case 402ULL: goto x86_l_192;
	case 407ULL: goto x86_l_197;
	case 410ULL: goto x86_l_19a;
	case 415ULL: goto x86_l_19f;
	case 417ULL: goto x86_l_1a1;
	case 419ULL: goto x86_l_1a3;
	case 425ULL: goto x86_l_1a9;
	case 427ULL: goto x86_l_1ab;
	case 432ULL: goto x86_l_1b0;
	case 440ULL: goto x86_l_1b8;
	case 448ULL: goto x86_l_1c0;
	case 454ULL: goto x86_l_1c6;
	case 457ULL: goto x86_l_1c9;
	case 463ULL: goto x86_l_1cf;
	case 466ULL: goto x86_l_1d2;
	case 472ULL: goto x86_l_1d8;
	case 475ULL: goto x86_l_1db;
	case 481ULL: goto x86_l_1e1;
	case 489ULL: goto x86_l_1e9;
	case 492ULL: goto x86_l_1ec;
	case 498ULL: goto x86_l_1f2;
	case 503ULL: goto x86_l_1f7;
	case 506ULL: goto x86_l_1fa;
	case 512ULL: goto x86_l_200;
	case 517ULL: goto x86_l_205;
	case 520ULL: goto x86_l_208;
	case 526ULL: goto x86_l_20e;
	case 531ULL: goto x86_l_213;
	case 536ULL: goto x86_l_218;
	case 539ULL: goto x86_l_21b;
	case 545ULL: goto x86_l_221;
	case 550ULL: goto x86_l_226;
	case 553ULL: goto x86_l_229;
	case 559ULL: goto x86_l_22f;
	case 562ULL: goto x86_l_232;
	case 568ULL: goto x86_l_238;
	case 573ULL: goto x86_l_23d;
	case 576ULL: goto x86_l_240;
	case 581ULL: goto x86_l_245;
	case 586ULL: goto x86_l_24a;
	case 589ULL: goto x86_l_24d;
	case 594ULL: goto x86_l_252;
	case 596ULL: goto x86_l_254;
	case 598ULL: goto x86_l_256;
	case 604ULL: goto x86_l_25c;
	case 607ULL: goto x86_l_25f;
	case 613ULL: goto x86_l_265;
	case 616ULL: goto x86_l_268;
	case 621ULL: goto x86_l_26d;
	case 626ULL: goto x86_l_272;
	case 632ULL: goto x86_l_278;
	case 637ULL: goto x86_l_27d;
	case 639ULL: goto x86_l_27f;
	case 641ULL: goto x86_l_281;
	case 647ULL: goto x86_l_287;
	case 651ULL: goto x86_l_28b;
	case 658ULL: goto x86_l_292;
	case 661ULL: goto x86_l_295;
	case 666ULL: goto x86_l_29a;
	case 669ULL: goto x86_l_29d;
	case 674ULL: goto x86_l_2a2;
	case 678ULL: goto x86_l_2a6;
	case 685ULL: goto x86_l_2ad;
	case 688ULL: goto x86_l_2b0;
	case 693ULL: goto x86_l_2b5;
	case 696ULL: goto x86_l_2b8;
	case 701ULL: goto x86_l_2bd;
	case 704ULL: goto x86_l_2c0;
	case 706ULL: goto x86_l_2c2;
	case 709ULL: goto x86_l_2c5;
	case 715ULL: goto x86_l_2cb;
	case 720ULL: goto x86_l_2d0;
	case 722ULL: goto x86_l_2d2;
	case 728ULL: goto x86_l_2d8;
	case 733ULL: goto x86_l_2dd;
	case 738ULL: goto x86_l_2e2;
	case 741ULL: goto x86_l_2e5;
	case 747ULL: goto x86_l_2eb;
	case 752ULL: goto x86_l_2f0;
	case 755ULL: goto x86_l_2f3;
	case 761ULL: goto x86_l_2f9;
	case 769ULL: goto x86_l_301;
	case 772ULL: goto x86_l_304;
	case 778ULL: goto x86_l_30a;
	case 783ULL: goto x86_l_30f;
	case 788ULL: goto x86_l_314;
	case 791ULL: goto x86_l_317;
	case 797ULL: goto x86_l_31d;
	case 802ULL: goto x86_l_322;
	case 805ULL: goto x86_l_325;
	case 811ULL: goto x86_l_32b;
	case 819ULL: goto x86_l_333;
	case 822ULL: goto x86_l_336;
	case 828ULL: goto x86_l_33c;
	case 833ULL: goto x86_l_341;
	case 838ULL: goto x86_l_346;
	case 841ULL: goto x86_l_349;
	case 847ULL: goto x86_l_34f;
	case 852ULL: goto x86_l_354;
	case 855ULL: goto x86_l_357;
	case 860ULL: goto x86_l_35c;
	case 864ULL: goto x86_l_360;
	case 871ULL: goto x86_l_367;
	case 876ULL: goto x86_l_36c;
	case 880ULL: goto x86_l_370;
	case 885ULL: goto x86_l_375;
	case 890ULL: goto x86_l_37a;
	case 894ULL: goto x86_l_37e;
	case 896ULL: goto x86_l_380;
	case 899ULL: goto x86_l_383;
	case 905ULL: goto x86_l_389;
	case 910ULL: goto x86_l_38e;
	case 915ULL: goto x86_l_393;
	case 921ULL: goto x86_l_399;
	case 924ULL: goto x86_l_39c;
	case 929ULL: goto x86_l_3a1;
	case 931ULL: goto x86_l_3a3;
	case 933ULL: goto x86_l_3a5;
	case 935ULL: goto x86_l_3a7;
	case 940ULL: goto x86_l_3ac;
	case 943ULL: goto x86_l_3af;
	case 948ULL: goto x86_l_3b4;
	case 953ULL: goto x86_l_3b9;
	case 956ULL: goto x86_l_3bc;
	case 959ULL: goto x86_l_3bf;
	case 964ULL: goto x86_l_3c4;
	case 966ULL: goto x86_l_3c6;
	case 968ULL: goto x86_l_3c8;
	case 970ULL: goto x86_l_3ca;
	case 973ULL: goto x86_l_3cd;
	case 978ULL: goto x86_l_3d2;
	case 981ULL: goto x86_l_3d5;
	case 983ULL: goto x86_l_3d7;
	case 987ULL: goto x86_l_3db;
	case 994ULL: goto x86_l_3e2;
	case 1000ULL: goto x86_l_3e8;
	case 1007ULL: goto x86_l_3ef;
	case 1010ULL: goto x86_l_3f2;
	case 1015ULL: goto x86_l_3f7;
	case 1018ULL: goto x86_l_3fa;
	case 1023ULL: goto x86_l_3ff;
	case 1029ULL: goto x86_l_405;
	case 1031ULL: goto x86_l_407;
	case 1036ULL: goto x86_l_40c;
	case 1042ULL: goto x86_l_412;
	case 1045ULL: goto x86_l_415;
	case 1047ULL: goto x86_l_417;
	case 1052ULL: goto x86_l_41c;
	case 1057ULL: goto x86_l_421;
	case 1062ULL: goto x86_l_426;
	case 1067ULL: goto x86_l_42b;
	case 1069ULL: goto x86_l_42d;
	case 1071ULL: goto x86_l_42f;
	case 1077ULL: goto x86_l_435;
	case 1084ULL: goto x86_l_43c;
	case 1090ULL: goto x86_l_442;
	case 1095ULL: goto x86_l_447;
	case 1100ULL: goto x86_l_44c;
	case 1105ULL: goto x86_l_451;
	case 1112ULL: goto x86_l_458;
	case 1114ULL: goto x86_l_45a;
	case 1119ULL: goto x86_l_45f;
	case 1124ULL: goto x86_l_464;
	case 1129ULL: goto x86_l_469;
	case 1134ULL: goto x86_l_46e;
	case 1136ULL: goto x86_l_470;
	case 1138ULL: goto x86_l_472;
	case 1144ULL: goto x86_l_478;
	case 1151ULL: goto x86_l_47f;
	case 1157ULL: goto x86_l_485;
	case 1162ULL: goto x86_l_48a;
	case 1167ULL: goto x86_l_48f;
	case 1172ULL: goto x86_l_494;
	case 1179ULL: goto x86_l_49b;
	case 1181ULL: goto x86_l_49d;
	case 1186ULL: goto x86_l_4a2;
	case 1191ULL: goto x86_l_4a7;
	case 1196ULL: goto x86_l_4ac;
	case 1201ULL: goto x86_l_4b1;
	case 1203ULL: goto x86_l_4b3;
	case 1205ULL: goto x86_l_4b5;
	case 1211ULL: goto x86_l_4bb;
	case 1218ULL: goto x86_l_4c2;
	case 1224ULL: goto x86_l_4c8;
	case 1229ULL: goto x86_l_4cd;
	case 1234ULL: goto x86_l_4d2;
	case 1239ULL: goto x86_l_4d7;
	case 1246ULL: goto x86_l_4de;
	case 1248ULL: goto x86_l_4e0;
	case 1253ULL: goto x86_l_4e5;
	case 1258ULL: goto x86_l_4ea;
	case 1263ULL: goto x86_l_4ef;
	case 1268ULL: goto x86_l_4f4;
	case 1270ULL: goto x86_l_4f6;
	case 1272ULL: goto x86_l_4f8;
	case 1278ULL: goto x86_l_4fe;
	case 1285ULL: goto x86_l_505;
	case 1291ULL: goto x86_l_50b;
	case 1296ULL: goto x86_l_510;
	case 1301ULL: goto x86_l_515;
	case 1306ULL: goto x86_l_51a;
	case 1313ULL: goto x86_l_521;
	case 1315ULL: goto x86_l_523;
	case 1320ULL: goto x86_l_528;
	case 1325ULL: goto x86_l_52d;
	case 1330ULL: goto x86_l_532;
	case 1335ULL: goto x86_l_537;
	case 1337ULL: goto x86_l_539;
	case 1339ULL: goto x86_l_53b;
	case 1345ULL: goto x86_l_541;
	case 1352ULL: goto x86_l_548;
	case 1358ULL: goto x86_l_54e;
	case 1363ULL: goto x86_l_553;
	case 1368ULL: goto x86_l_558;
	case 1373ULL: goto x86_l_55d;
	case 1380ULL: goto x86_l_564;
	case 1382ULL: goto x86_l_566;
	case 1387ULL: goto x86_l_56b;
	case 1392ULL: goto x86_l_570;
	case 1397ULL: goto x86_l_575;
	case 1402ULL: goto x86_l_57a;
	case 1404ULL: goto x86_l_57c;
	case 1406ULL: goto x86_l_57e;
	case 1412ULL: goto x86_l_584;
	case 1419ULL: goto x86_l_58b;
	case 1425ULL: goto x86_l_591;
	case 1430ULL: goto x86_l_596;
	case 1435ULL: goto x86_l_59b;
	case 1440ULL: goto x86_l_5a0;
	case 1447ULL: goto x86_l_5a7;
	case 1449ULL: goto x86_l_5a9;
	case 1454ULL: goto x86_l_5ae;
	case 1459ULL: goto x86_l_5b3;
	case 1464ULL: goto x86_l_5b8;
	case 1469ULL: goto x86_l_5bd;
	case 1471ULL: goto x86_l_5bf;
	case 1473ULL: goto x86_l_5c1;
	case 1479ULL: goto x86_l_5c7;
	case 1486ULL: goto x86_l_5ce;
	case 1492ULL: goto x86_l_5d4;
	case 1497ULL: goto x86_l_5d9;
	case 1502ULL: goto x86_l_5de;
	case 1507ULL: goto x86_l_5e3;
	case 1514ULL: goto x86_l_5ea;
	case 1516ULL: goto x86_l_5ec;
	case 1521ULL: goto x86_l_5f1;
	case 1526ULL: goto x86_l_5f6;
	case 1531ULL: goto x86_l_5fb;
	case 1536ULL: goto x86_l_600;
	case 1538ULL: goto x86_l_602;
	case 1540ULL: goto x86_l_604;
	case 1546ULL: goto x86_l_60a;
	case 1553ULL: goto x86_l_611;
	case 1559ULL: goto x86_l_617;
	case 1564ULL: goto x86_l_61c;
	case 1569ULL: goto x86_l_621;
	case 1574ULL: goto x86_l_626;
	case 1581ULL: goto x86_l_62d;
	case 1583ULL: goto x86_l_62f;
	case 1588ULL: goto x86_l_634;
	case 1593ULL: goto x86_l_639;
	case 1598ULL: goto x86_l_63e;
	case 1603ULL: goto x86_l_643;
	case 1605ULL: goto x86_l_645;
	case 1607ULL: goto x86_l_647;
	case 1613ULL: goto x86_l_64d;
	case 1620ULL: goto x86_l_654;
	case 1626ULL: goto x86_l_65a;
	case 1631ULL: goto x86_l_65f;
	case 1636ULL: goto x86_l_664;
	case 1641ULL: goto x86_l_669;
	case 1648ULL: goto x86_l_670;
	case 1654ULL: goto x86_l_676;
	case 1659ULL: goto x86_l_67b;
	case 1664ULL: goto x86_l_680;
	case 1669ULL: goto x86_l_685;
	case 1674ULL: goto x86_l_68a;
	case 1679ULL: goto x86_l_68f;
	case 1682ULL: goto x86_l_692;
	case 1684ULL: goto x86_l_694;
	case 1689ULL: goto x86_l_699;
	case 1694ULL: goto x86_l_69e;
	case 1699ULL: goto x86_l_6a3;
	case 1704ULL: goto x86_l_6a8;
	case 1706ULL: goto x86_l_6aa;
	case 1708ULL: goto x86_l_6ac;
	case 1714ULL: goto x86_l_6b2;
	case 1721ULL: goto x86_l_6b9;
	case 1727ULL: goto x86_l_6bf;
	case 1732ULL: goto x86_l_6c4;
	case 1737ULL: goto x86_l_6c9;
	case 1742ULL: goto x86_l_6ce;
	case 1749ULL: goto x86_l_6d5;
	case 1751ULL: goto x86_l_6d7;
	case 1756ULL: goto x86_l_6dc;
	case 1761ULL: goto x86_l_6e1;
	case 1766ULL: goto x86_l_6e6;
	case 1771ULL: goto x86_l_6eb;
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
	/* 0xa: sub    rsp,0xc8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 200ULL);
x86_l_11:
	/* 0x11: mov    eax,0xae */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 174ULL);
x86_l_16:
	/* 0x16: mov    QWORD PTR [rsp+0x30],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b:
	/* 0x1b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d:
	/* 0x1d: mov    DWORD PTR [rsp+0xc4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_24:
	/* 0x24: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_2b:
	/* 0x2b: lea    rsi,[rsp+0xc4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_33:
	/* 0x33: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_38:
	/* 0x38: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a:
	/* 0x3a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3d:
	/* 0x3d: je     11fd <generic_sleepable_preload+0x11fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4605ULL;
	}
x86_l_43:
	/* 0x43: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_46:
	/* 0x46: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_4d:
	/* 0x4d: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_52:
	/* 0x52: lea    rcx,[r15+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_59:
	/* 0x59: mov    QWORD PTR [rsp+0x40],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5e:
	/* 0x5e: lea    rcx,[r15+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_65:
	/* 0x65: mov    QWORD PTR [rsp+0x78],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_6a:
	/* 0x6a: lea    rcx,[r15+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6e:
	/* 0x6e: mov    QWORD PTR [rsp+0xb0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_76:
	/* 0x76: lea    rcx,[r15+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_7a:
	/* 0x7a: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_7f:
	/* 0x7f: lea    rcx,[r15+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_83:
	/* 0x83: mov    QWORD PTR [rsp+0xa8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_8b:
	/* 0x8b: lea    rcx,[r15+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_8f:
	/* 0x8f: mov    QWORD PTR [rsp+0x68],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_94:
	/* 0x94: lea    rcx,[r15+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_98:
	/* 0x98: mov    QWORD PTR [rsp+0xa0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_a0:
	/* 0xa0: lea    rcx,[r15+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_a4:
	/* 0xa4: mov    QWORD PTR [rsp+0x60],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_a9:
	/* 0xa9: lea    rcx,[r15+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_ad:
	/* 0xad: mov    QWORD PTR [rsp+0x98],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_b5:
	/* 0xb5: lea    rcx,[r15+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_b9:
	/* 0xb9: mov    QWORD PTR [rsp+0x58],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_be:
	/* 0xbe: lea    rcx,[r15+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c2:
	/* 0xc2: mov    QWORD PTR [rsp+0x90],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_ca:
	/* 0xca: lea    rcx,[r15+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ce:
	/* 0xce: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_d3:
	/* 0xd3: lea    rcx,[r15+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d7:
	/* 0xd7: mov    QWORD PTR [rsp+0x88],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_df:
	/* 0xdf: lea    rcx,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e3:
	/* 0xe3: mov    QWORD PTR [rsp+0x48],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_e8:
	/* 0xe8: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_eb:
	/* 0xeb: lea    rax,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ef:
	/* 0xef: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_f7:
	/* 0xf7: lea    rax,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fb:
	/* 0xfb: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_100:
	/* 0x100: mov    QWORD PTR [rsp+0x28],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_105:
	/* 0x105: je     11b1 <generic_sleepable_preload+0x11b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4529ULL;
	}
x86_l_10b:
	/* 0x10b: lea    r14,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_10f:
	/* 0x10f: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_112:
	/* 0x112: add    rbx,0x200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 512ULL);
x86_l_119:
	/* 0x119: mov    r15d,0xbe */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 190ULL);
x86_l_11f:
	/* 0x11f: lea    rbp,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_124:
	/* 0x124: jmp    14c <generic_sleepable_preload+0x14c> */
	goto x86_l_14c;
x86_l_126:
	/* 0x126: mov    DWORD PTR [rax],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_129:
	/* 0x129: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_12e:
	/* 0x12e: lea    rbp,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_133:
	/* 0x133: add    r14,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_137:
	/* 0x137: add    rbx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_13b:
	/* 0x13b: add    r15,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_13f:
	/* 0x13f: cmp    r15,0x24e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 590ULL);
x86_l_146:
	/* 0x146: je     11fd <generic_sleepable_preload+0x11fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4605ULL;
	}
x86_l_14c:
	/* 0x14c: mov    eax,DWORD PTR [r14+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_150:
	/* 0x150: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_155:
	/* 0x155: je     133 <generic_sleepable_preload+0x133> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_133;
	}
x86_l_157:
	/* 0x157: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_159:
	/* 0x159: js     1b0 <generic_sleepable_preload+0x1b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1b0;
	}
x86_l_15b:
	/* 0x15b: movzx  eax,BYTE PTR [rbx+0x11] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 17ULL);
x86_l_15f:
	/* 0x15f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_162:
	/* 0x162: jg     218 <generic_sleepable_preload+0x218> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_218;
	}
x86_l_168:
	/* 0x168: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16b:
	/* 0x16b: je     354 <generic_sleepable_preload+0x354> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354;
	}
x86_l_171:
	/* 0x171: mov    ecx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 0ULL);
x86_l_176:
	/* 0x176: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_179:
	/* 0x179: jne    3cd <generic_sleepable_preload+0x3cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3cd;
	}
x86_l_17f:
	/* 0x17f: mov    edx,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_182:
	/* 0x182: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_188:
	/* 0x188: add    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_18d:
	/* 0x18d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_192:
	/* 0x192: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_197:
	/* 0x197: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_19a:
	/* 0x19a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19f:
	/* 0x19f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a1:
	/* 0x1a1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a3:
	/* 0x1a3: je     35c <generic_sleepable_preload+0x35c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35c;
	}
x86_l_1a9:
	/* 0x1a9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ab:
	/* 0x1ab: jmp    3cd <generic_sleepable_preload+0x3cd> */
	goto x86_l_3cd;
x86_l_1b0:
	/* 0x1b0: movzx  eax,BYTE PTR [r14+0x2be] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 702ULL);
x86_l_1b8:
	/* 0x1b8: movzx  ecx,WORD PTR [r14+0x2bc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 700ULL);
x86_l_1c0:
	/* 0x1c0: rorx   ecx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_1c6:
	/* 0x1c6: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_1c9:
	/* 0x1c9: jle    2bd <generic_sleepable_preload+0x2bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2bd;
	}
x86_l_1cf:
	/* 0x1cf: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_1d2:
	/* 0x1d2: jle    2f0 <generic_sleepable_preload+0x2f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2f0;
	}
x86_l_1d8:
	/* 0x1d8: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_1db:
	/* 0x1db: jle    981 <generic_sleepable_preload+0x981> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2433ULL;
	}
x86_l_1e1:
	/* 0x1e1: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1e9:
	/* 0x1e9: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_1ec:
	/* 0x1ec: je     99d <generic_sleepable_preload+0x99d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2461ULL;
	}
x86_l_1f2:
	/* 0x1f2: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1f7:
	/* 0x1f7: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1fa:
	/* 0x1fa: je     99d <generic_sleepable_preload+0x99d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2461ULL;
	}
x86_l_200:
	/* 0x200: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_205:
	/* 0x205: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_208:
	/* 0x208: jne    9b0 <generic_sleepable_preload+0x9b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2480ULL;
	}
x86_l_20e:
	/* 0x20e: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_213:
	/* 0x213: jmp    99d <generic_sleepable_preload+0x99d> */
	return 2461ULL;
x86_l_218:
	/* 0x218: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_21b:
	/* 0x21b: je     380 <generic_sleepable_preload+0x380> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_380;
	}
x86_l_221:
	/* 0x221: mov    ecx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 0ULL);
x86_l_226:
	/* 0x226: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_229:
	/* 0x229: jne    3cd <generic_sleepable_preload+0x3cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3cd;
	}
x86_l_22f:
	/* 0x22f: mov    edx,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_232:
	/* 0x232: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_238:
	/* 0x238: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_23d:
	/* 0x23d: add    rdx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_240:
	/* 0x240: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_245:
	/* 0x245: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_24a:
	/* 0x24a: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_24d:
	/* 0x24d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_252:
	/* 0x252: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_254:
	/* 0x254: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_256:
	/* 0x256: jne    3ca <generic_sleepable_preload+0x3ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3ca;
	}
x86_l_25c:
	/* 0x25c: mov    edx,DWORD PTR [rbx+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_25f:
	/* 0x25f: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_265:
	/* 0x265: add    rdx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_268:
	/* 0x268: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_26d:
	/* 0x26d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_272:
	/* 0x272: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_278:
	/* 0x278: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27d:
	/* 0x27d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27f:
	/* 0x27f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_281:
	/* 0x281: jne    3ca <generic_sleepable_preload+0x3ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3ca;
	}
x86_l_287:
	/* 0x287: movzx  eax,BYTE PTR [rbx+0x13] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 19ULL);
x86_l_28b:
	/* 0x28b: shlx   rax,QWORD PTR [rsp+0x8],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_292:
	/* 0x292: mov    rcx,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_295:
	/* 0x295: add    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_29a:
	/* 0x29a: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_29d:
	/* 0x29d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2a2:
	/* 0x2a2: movzx  ecx,BYTE PTR [rbx+0x13] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 19ULL);
x86_l_2a6:
	/* 0x2a6: shlx   rcx,QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_2ad:
	/* 0x2ad: mov    rdx,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b0:
	/* 0x2b0: add    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_2b5:
	/* 0x2b5: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2b8:
	/* 0x2b8: jmp    3bc <generic_sleepable_preload+0x3bc> */
	goto x86_l_3bc;
x86_l_2bd:
	/* 0x2bd: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_2c0:
	/* 0x2c0: jg     322 <generic_sleepable_preload+0x322> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_322;
	}
x86_l_2c2:
	/* 0x2c2: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2c5:
	/* 0x2c5: jg     945 <generic_sleepable_preload+0x945> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 2373ULL;
	}
x86_l_2cb:
	/* 0x2cb: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d0:
	/* 0x2d0: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2d2:
	/* 0x2d2: je     99d <generic_sleepable_preload+0x99d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2461ULL;
	}
x86_l_2d8:
	/* 0x2d8: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2dd:
	/* 0x2dd: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_2e2:
	/* 0x2e2: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2e5:
	/* 0x2e5: je     99d <generic_sleepable_preload+0x99d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2461ULL;
	}
x86_l_2eb:
	/* 0x2eb: jmp    9b0 <generic_sleepable_preload+0x9b0> */
	return 2480ULL;
x86_l_2f0:
	/* 0x2f0: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_2f3:
	/* 0x2f3: jg     927 <generic_sleepable_preload+0x927> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 2343ULL;
	}
x86_l_2f9:
	/* 0x2f9: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_301:
	/* 0x301: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_304:
	/* 0x304: je     99d <generic_sleepable_preload+0x99d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2461ULL;
	}
x86_l_30a:
	/* 0x30a: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_30f:
	/* 0x30f: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_314:
	/* 0x314: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_317:
	/* 0x317: je     99d <generic_sleepable_preload+0x99d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2461ULL;
	}
x86_l_31d:
	/* 0x31d: jmp    9b0 <generic_sleepable_preload+0x9b0> */
	return 2480ULL;
x86_l_322:
	/* 0x322: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_325:
	/* 0x325: jg     963 <generic_sleepable_preload+0x963> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 2403ULL;
	}
x86_l_32b:
	/* 0x32b: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_333:
	/* 0x333: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_336:
	/* 0x336: je     99d <generic_sleepable_preload+0x99d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2461ULL;
	}
x86_l_33c:
	/* 0x33c: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_341:
	/* 0x341: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_346:
	/* 0x346: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_349:
	/* 0x349: je     99d <generic_sleepable_preload+0x99d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2461ULL;
	}
x86_l_34f:
	/* 0x34f: jmp    9b0 <generic_sleepable_preload+0x9b0> */
	return 2480ULL;
x86_l_354:
	/* 0x354: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_357:
	/* 0x357: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_35c:
	/* 0x35c: movzx  eax,BYTE PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_360:
	/* 0x360: shlx   rcx,QWORD PTR [rsp+0x18],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((24ULL << 32) | X86_ALU_SHL));
x86_l_367:
	/* 0x367: mov    QWORD PTR [rsp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_36c:
	/* 0x36c: cmp    BYTE PTR [rbx+0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 77309411328ULL);
x86_l_370:
	/* 0x370: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_375:
	/* 0x375: sarx   rcx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RCX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_37a:
	/* 0x37a: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_37e:
	/* 0x37e: jmp    3cd <generic_sleepable_preload+0x3cd> */
	goto x86_l_3cd;
x86_l_380:
	/* 0x380: mov    edx,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_383:
	/* 0x383: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_389:
	/* 0x389: add    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_38e:
	/* 0x38e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_393:
	/* 0x393: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_399:
	/* 0x399: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_39c:
	/* 0x39c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a1:
	/* 0x3a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a3:
	/* 0x3a3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3a5:
	/* 0x3a5: jne    3ca <generic_sleepable_preload+0x3ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3ca;
	}
x86_l_3a7:
	/* 0x3a7: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3ac:
	/* 0x3ac: add    rcx,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3af:
	/* 0x3af: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3b4:
	/* 0x3b4: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3b9:
	/* 0x3b9: add    rdx,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3bc:
	/* 0x3bc: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_3bf:
	/* 0x3bf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c4:
	/* 0x3c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c6:
	/* 0x3c6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3c8:
	/* 0x3c8: je     35c <generic_sleepable_preload+0x35c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35c;
	}
x86_l_3ca:
	/* 0x3ca: movsxd rcx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_3cd:
	/* 0x3cd: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d2:
	/* 0x3d2: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3d5:
	/* 0x3d5: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_3d7:
	/* 0x3d7: mov    DWORD PTR [rsp+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_3db:
	/* 0x3db: cmp    WORD PTR [r13+r15*1-0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743764471906304ULL);
x86_l_3e2:
	/* 0x3e2: je     685 <generic_sleepable_preload+0x685> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_685;
	}
x86_l_3e8:
	/* 0x3e8: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_3ef:
	/* 0x3ef: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_3f2:
	/* 0x3f2: mov    eax,DWORD PTR [r13+r15*1-0x4e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551538ULL);
x86_l_3f7:
	/* 0x3f7: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3fa:
	/* 0x3fa: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ff:
	/* 0x3ff: movzx  eax,WORD PTR [r13+r15*1-0x4a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R15, 0, X86_WIDTH_16), 18446744073709551542ULL);
x86_l_405:
	/* 0x405: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_407:
	/* 0x407: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_40c:
	/* 0x40c: je     68f <generic_sleepable_preload+0x68f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_68f;
	}
x86_l_412:
	/* 0x412: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_415:
	/* 0x415: je     435 <generic_sleepable_preload+0x435> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_435;
	}
x86_l_417:
	/* 0x417: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_41c:
	/* 0x41c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_421:
	/* 0x421: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_426:
	/* 0x426: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_42b:
	/* 0x42b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42d:
	/* 0x42d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_42f:
	/* 0x42f: js     91c <generic_sleepable_preload+0x91c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 2332ULL;
	}
x86_l_435:
	/* 0x435: cmp    WORD PTR [r13+r15*1-0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743798831644672ULL);
x86_l_43c:
	/* 0x43c: je     fcf <generic_sleepable_preload+0xfcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4047ULL;
	}
x86_l_442:
	/* 0x442: mov    ecx,DWORD PTR [r13+r15*1-0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551546ULL);
x86_l_447:
	/* 0x447: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_44c:
	/* 0x44c: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_451:
	/* 0x451: cmp    WORD PTR [r13+r15*1-0x42],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743790241710080ULL);
x86_l_458:
	/* 0x458: je     478 <generic_sleepable_preload+0x478> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_478;
	}
x86_l_45a:
	/* 0x45a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_45f:
	/* 0x45f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_464:
	/* 0x464: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_469:
	/* 0x469: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_46e:
	/* 0x46e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_470:
	/* 0x470: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_472:
	/* 0x472: js     f62 <generic_sleepable_preload+0xf62> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3938ULL;
	}
x86_l_478:
	/* 0x478: cmp    WORD PTR [r13+r15*1-0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743833191383040ULL);
x86_l_47f:
	/* 0x47f: je     fcf <generic_sleepable_preload+0xfcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4047ULL;
	}
x86_l_485:
	/* 0x485: mov    ecx,DWORD PTR [r13+r15*1-0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551554ULL);
x86_l_48a:
	/* 0x48a: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_48f:
	/* 0x48f: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_494:
	/* 0x494: cmp    WORD PTR [r13+r15*1-0x3a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743824601448448ULL);
x86_l_49b:
	/* 0x49b: je     4bb <generic_sleepable_preload+0x4bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bb;
	}
x86_l_49d:
	/* 0x49d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4a2:
	/* 0x4a2: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a7:
	/* 0x4a7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ac:
	/* 0x4ac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b1:
	/* 0x4b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b3:
	/* 0x4b3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4b5:
	/* 0x4b5: js     f75 <generic_sleepable_preload+0xf75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3957ULL;
	}
x86_l_4bb:
	/* 0x4bb: cmp    WORD PTR [r13+r15*1-0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743867551121408ULL);
x86_l_4c2:
	/* 0x4c2: je     fcf <generic_sleepable_preload+0xfcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4047ULL;
	}
x86_l_4c8:
	/* 0x4c8: mov    ecx,DWORD PTR [r13+r15*1-0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551562ULL);
x86_l_4cd:
	/* 0x4cd: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4d2:
	/* 0x4d2: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4d7:
	/* 0x4d7: cmp    WORD PTR [r13+r15*1-0x32],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743858961186816ULL);
x86_l_4de:
	/* 0x4de: je     4fe <generic_sleepable_preload+0x4fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4fe;
	}
x86_l_4e0:
	/* 0x4e0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4e5:
	/* 0x4e5: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ea:
	/* 0x4ea: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ef:
	/* 0x4ef: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f4:
	/* 0x4f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f6:
	/* 0x4f6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4f8:
	/* 0x4f8: js     f88 <generic_sleepable_preload+0xf88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3976ULL;
	}
x86_l_4fe:
	/* 0x4fe: cmp    WORD PTR [r13+r15*1-0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743901910859776ULL);
x86_l_505:
	/* 0x505: je     fcf <generic_sleepable_preload+0xfcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4047ULL;
	}
x86_l_50b:
	/* 0x50b: mov    ecx,DWORD PTR [r13+r15*1-0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551570ULL);
x86_l_510:
	/* 0x510: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_515:
	/* 0x515: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_51a:
	/* 0x51a: cmp    WORD PTR [r13+r15*1-0x2a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743893320925184ULL);
x86_l_521:
	/* 0x521: je     541 <generic_sleepable_preload+0x541> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_541;
	}
x86_l_523:
	/* 0x523: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_528:
	/* 0x528: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52d:
	/* 0x52d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_532:
	/* 0x532: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_537:
	/* 0x537: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_539:
	/* 0x539: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_53b:
	/* 0x53b: js     f9b <generic_sleepable_preload+0xf9b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3995ULL;
	}
x86_l_541:
	/* 0x541: cmp    WORD PTR [r13+r15*1-0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743936270598144ULL);
x86_l_548:
	/* 0x548: je     fcf <generic_sleepable_preload+0xfcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4047ULL;
	}
x86_l_54e:
	/* 0x54e: mov    ecx,DWORD PTR [r13+r15*1-0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551578ULL);
x86_l_553:
	/* 0x553: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_558:
	/* 0x558: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_55d:
	/* 0x55d: cmp    WORD PTR [r13+r15*1-0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743927680663552ULL);
x86_l_564:
	/* 0x564: je     584 <generic_sleepable_preload+0x584> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_584;
	}
x86_l_566:
	/* 0x566: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_56b:
	/* 0x56b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_570:
	/* 0x570: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_575:
	/* 0x575: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_57a:
	/* 0x57a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_57c:
	/* 0x57c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_57e:
	/* 0x57e: js     fae <generic_sleepable_preload+0xfae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4014ULL;
	}
x86_l_584:
	/* 0x584: cmp    WORD PTR [r13+r15*1-0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743970630336512ULL);
x86_l_58b:
	/* 0x58b: je     fcf <generic_sleepable_preload+0xfcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4047ULL;
	}
x86_l_591:
	/* 0x591: mov    ecx,DWORD PTR [r13+r15*1-0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551586ULL);
x86_l_596:
	/* 0x596: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_59b:
	/* 0x59b: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a0:
	/* 0x5a0: cmp    WORD PTR [r13+r15*1-0x1a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743962040401920ULL);
x86_l_5a7:
	/* 0x5a7: je     5c7 <generic_sleepable_preload+0x5c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5c7;
	}
x86_l_5a9:
	/* 0x5a9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5ae:
	/* 0x5ae: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b3:
	/* 0x5b3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b8:
	/* 0x5b8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5bd:
	/* 0x5bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5bf:
	/* 0x5bf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5c1:
	/* 0x5c1: js     fc1 <generic_sleepable_preload+0xfc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4033ULL;
	}
x86_l_5c7:
	/* 0x5c7: cmp    WORD PTR [r13+r15*1-0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744004990074880ULL);
x86_l_5ce:
	/* 0x5ce: je     fcf <generic_sleepable_preload+0xfcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4047ULL;
	}
x86_l_5d4:
	/* 0x5d4: mov    ecx,DWORD PTR [r13+r15*1-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551594ULL);
x86_l_5d9:
	/* 0x5d9: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5de:
	/* 0x5de: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e3:
	/* 0x5e3: cmp    WORD PTR [r13+r15*1-0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743996400140288ULL);
x86_l_5ea:
	/* 0x5ea: je     60a <generic_sleepable_preload+0x60a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_60a;
	}
x86_l_5ec:
	/* 0x5ec: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5f1:
	/* 0x5f1: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f6:
	/* 0x5f6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5fb:
	/* 0x5fb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_600:
	/* 0x600: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_602:
	/* 0x602: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_604:
	/* 0x604: js     116c <generic_sleepable_preload+0x116c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4460ULL;
	}
x86_l_60a:
	/* 0x60a: cmp    WORD PTR [r13+r15*1-0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744039349813248ULL);
x86_l_611:
	/* 0x611: je     fcf <generic_sleepable_preload+0xfcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4047ULL;
	}
x86_l_617:
	/* 0x617: mov    ecx,DWORD PTR [r13+r15*1-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551602ULL);
x86_l_61c:
	/* 0x61c: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_621:
	/* 0x621: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_626:
	/* 0x626: cmp    WORD PTR [r13+r15*1-0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744030759878656ULL);
x86_l_62d:
	/* 0x62d: je     64d <generic_sleepable_preload+0x64d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_64d;
	}
x86_l_62f:
	/* 0x62f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_634:
	/* 0x634: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_639:
	/* 0x639: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_63e:
	/* 0x63e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_643:
	/* 0x643: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_645:
	/* 0x645: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_647:
	/* 0x647: js     119b <generic_sleepable_preload+0x119b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4507ULL;
	}
x86_l_64d:
	/* 0x64d: cmp    WORD PTR [r13+r15*1+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_654:
	/* 0x654: je     fcf <generic_sleepable_preload+0xfcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4047ULL;
	}
x86_l_65a:
	/* 0x65a: mov    ecx,DWORD PTR [r13+r15*1-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551610ULL);
x86_l_65f:
	/* 0x65f: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_664:
	/* 0x664: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_669:
	/* 0x669: cmp    WORD PTR [r13+r15*1-0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744065119617024ULL);
x86_l_670:
	/* 0x670: je     fcf <generic_sleepable_preload+0xfcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4047ULL;
	}
x86_l_676:
	/* 0x676: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_67b:
	/* 0x67b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_680:
	/* 0x680: jmp    8fd <generic_sleepable_preload+0x8fd> */
	return 2301ULL;
x86_l_685:
	/* 0x685: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_68a:
	/* 0x68a: jmp    fcf <generic_sleepable_preload+0xfcf> */
	return 4047ULL;
x86_l_68f:
	/* 0x68f: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_692:
	/* 0x692: je     6b2 <generic_sleepable_preload+0x6b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6b2;
	}
x86_l_694:
	/* 0x694: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_699:
	/* 0x699: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_69e:
	/* 0x69e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6a3:
	/* 0x6a3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6a8:
	/* 0x6a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6aa:
	/* 0x6aa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_6ac:
	/* 0x6ac: js     91c <generic_sleepable_preload+0x91c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 2332ULL;
	}
x86_l_6b2:
	/* 0x6b2: cmp    WORD PTR [r13+r15*1-0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743798831644672ULL);
x86_l_6b9:
	/* 0x6b9: je     fcf <generic_sleepable_preload+0xfcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4047ULL;
	}
x86_l_6bf:
	/* 0x6bf: mov    ecx,DWORD PTR [r13+r15*1-0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551546ULL);
x86_l_6c4:
	/* 0x6c4: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_6c9:
	/* 0x6c9: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6ce:
	/* 0x6ce: cmp    WORD PTR [r13+r15*1-0x42],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743790241710080ULL);
x86_l_6d5:
	/* 0x6d5: je     6f5 <generic_sleepable_preload+0x6f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1781ULL;
	}
x86_l_6d7:
	/* 0x6d7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_6dc:
	/* 0x6dc: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6e1:
	/* 0x6e1: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6e6:
	/* 0x6e6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6eb:
	/* 0x6eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 1773ULL;
}

static __noinline __u64 tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1773ULL: goto x86_l_6ed;
	case 1775ULL: goto x86_l_6ef;
	case 1781ULL: goto x86_l_6f5;
	case 1788ULL: goto x86_l_6fc;
	case 1794ULL: goto x86_l_702;
	case 1799ULL: goto x86_l_707;
	case 1804ULL: goto x86_l_70c;
	case 1809ULL: goto x86_l_711;
	case 1816ULL: goto x86_l_718;
	case 1818ULL: goto x86_l_71a;
	case 1823ULL: goto x86_l_71f;
	case 1828ULL: goto x86_l_724;
	case 1833ULL: goto x86_l_729;
	case 1838ULL: goto x86_l_72e;
	case 1840ULL: goto x86_l_730;
	case 1842ULL: goto x86_l_732;
	case 1848ULL: goto x86_l_738;
	case 1855ULL: goto x86_l_73f;
	case 1861ULL: goto x86_l_745;
	case 1866ULL: goto x86_l_74a;
	case 1871ULL: goto x86_l_74f;
	case 1876ULL: goto x86_l_754;
	case 1883ULL: goto x86_l_75b;
	case 1885ULL: goto x86_l_75d;
	case 1890ULL: goto x86_l_762;
	case 1895ULL: goto x86_l_767;
	case 1900ULL: goto x86_l_76c;
	case 1905ULL: goto x86_l_771;
	case 1907ULL: goto x86_l_773;
	case 1909ULL: goto x86_l_775;
	case 1915ULL: goto x86_l_77b;
	case 1922ULL: goto x86_l_782;
	case 1928ULL: goto x86_l_788;
	case 1933ULL: goto x86_l_78d;
	case 1938ULL: goto x86_l_792;
	case 1943ULL: goto x86_l_797;
	case 1950ULL: goto x86_l_79e;
	case 1952ULL: goto x86_l_7a0;
	case 1957ULL: goto x86_l_7a5;
	case 1962ULL: goto x86_l_7aa;
	case 1967ULL: goto x86_l_7af;
	case 1972ULL: goto x86_l_7b4;
	case 1974ULL: goto x86_l_7b6;
	case 1976ULL: goto x86_l_7b8;
	case 1982ULL: goto x86_l_7be;
	case 1989ULL: goto x86_l_7c5;
	case 1995ULL: goto x86_l_7cb;
	case 2000ULL: goto x86_l_7d0;
	case 2005ULL: goto x86_l_7d5;
	case 2010ULL: goto x86_l_7da;
	case 2017ULL: goto x86_l_7e1;
	case 2019ULL: goto x86_l_7e3;
	case 2024ULL: goto x86_l_7e8;
	case 2029ULL: goto x86_l_7ed;
	case 2034ULL: goto x86_l_7f2;
	case 2039ULL: goto x86_l_7f7;
	case 2041ULL: goto x86_l_7f9;
	case 2043ULL: goto x86_l_7fb;
	case 2049ULL: goto x86_l_801;
	case 2056ULL: goto x86_l_808;
	case 2062ULL: goto x86_l_80e;
	case 2067ULL: goto x86_l_813;
	case 2072ULL: goto x86_l_818;
	case 2077ULL: goto x86_l_81d;
	case 2084ULL: goto x86_l_824;
	case 2086ULL: goto x86_l_826;
	case 2091ULL: goto x86_l_82b;
	case 2096ULL: goto x86_l_830;
	case 2101ULL: goto x86_l_835;
	case 2106ULL: goto x86_l_83a;
	case 2108ULL: goto x86_l_83c;
	case 2110ULL: goto x86_l_83e;
	case 2116ULL: goto x86_l_844;
	case 2123ULL: goto x86_l_84b;
	case 2129ULL: goto x86_l_851;
	case 2134ULL: goto x86_l_856;
	case 2139ULL: goto x86_l_85b;
	case 2144ULL: goto x86_l_860;
	case 2151ULL: goto x86_l_867;
	case 2153ULL: goto x86_l_869;
	case 2158ULL: goto x86_l_86e;
	case 2163ULL: goto x86_l_873;
	case 2168ULL: goto x86_l_878;
	case 2173ULL: goto x86_l_87d;
	case 2175ULL: goto x86_l_87f;
	case 2177ULL: goto x86_l_881;
	case 2183ULL: goto x86_l_887;
	case 2190ULL: goto x86_l_88e;
	case 2196ULL: goto x86_l_894;
	case 2201ULL: goto x86_l_899;
	case 2206ULL: goto x86_l_89e;
	case 2211ULL: goto x86_l_8a3;
	case 2218ULL: goto x86_l_8aa;
	case 2220ULL: goto x86_l_8ac;
	case 2225ULL: goto x86_l_8b1;
	case 2230ULL: goto x86_l_8b6;
	case 2235ULL: goto x86_l_8bb;
	case 2240ULL: goto x86_l_8c0;
	case 2242ULL: goto x86_l_8c2;
	case 2244ULL: goto x86_l_8c4;
	case 2250ULL: goto x86_l_8ca;
	case 2257ULL: goto x86_l_8d1;
	case 2263ULL: goto x86_l_8d7;
	case 2268ULL: goto x86_l_8dc;
	case 2273ULL: goto x86_l_8e1;
	case 2278ULL: goto x86_l_8e6;
	case 2285ULL: goto x86_l_8ed;
	case 2291ULL: goto x86_l_8f3;
	case 2296ULL: goto x86_l_8f8;
	case 2301ULL: goto x86_l_8fd;
	case 2306ULL: goto x86_l_902;
	case 2311ULL: goto x86_l_907;
	case 2313ULL: goto x86_l_909;
	case 2315ULL: goto x86_l_90b;
	case 2321ULL: goto x86_l_911;
	case 2327ULL: goto x86_l_917;
	case 2332ULL: goto x86_l_91c;
	case 2338ULL: goto x86_l_922;
	case 2343ULL: goto x86_l_927;
	case 2351ULL: goto x86_l_92f;
	case 2354ULL: goto x86_l_932;
	case 2356ULL: goto x86_l_934;
	case 2361ULL: goto x86_l_939;
	case 2366ULL: goto x86_l_93e;
	case 2369ULL: goto x86_l_941;
	case 2371ULL: goto x86_l_943;
	case 2373ULL: goto x86_l_945;
	case 2381ULL: goto x86_l_94d;
	case 2384ULL: goto x86_l_950;
	case 2386ULL: goto x86_l_952;
	case 2391ULL: goto x86_l_957;
	case 2396ULL: goto x86_l_95c;
	case 2399ULL: goto x86_l_95f;
	case 2401ULL: goto x86_l_961;
	case 2403ULL: goto x86_l_963;
	case 2411ULL: goto x86_l_96b;
	case 2414ULL: goto x86_l_96e;
	case 2416ULL: goto x86_l_970;
	case 2421ULL: goto x86_l_975;
	case 2426ULL: goto x86_l_97a;
	case 2429ULL: goto x86_l_97d;
	case 2431ULL: goto x86_l_97f;
	case 2433ULL: goto x86_l_981;
	case 2441ULL: goto x86_l_989;
	case 2444ULL: goto x86_l_98c;
	case 2446ULL: goto x86_l_98e;
	case 2451ULL: goto x86_l_993;
	case 2456ULL: goto x86_l_998;
	case 2459ULL: goto x86_l_99b;
	case 2461ULL: goto x86_l_99d;
	case 2464ULL: goto x86_l_9a0;
	case 2466ULL: goto x86_l_9a2;
	case 2468ULL: goto x86_l_9a4;
	case 2473ULL: goto x86_l_9a9;
	case 2475ULL: goto x86_l_9ab;
	case 2480ULL: goto x86_l_9b0;
	case 2485ULL: goto x86_l_9b5;
	case 2488ULL: goto x86_l_9b8;
	case 2491ULL: goto x86_l_9bb;
	case 2493ULL: goto x86_l_9bd;
	case 2497ULL: goto x86_l_9c1;
	case 2504ULL: goto x86_l_9c8;
	case 2510ULL: goto x86_l_9ce;
	case 2517ULL: goto x86_l_9d5;
	case 2520ULL: goto x86_l_9d8;
	case 2525ULL: goto x86_l_9dd;
	case 2528ULL: goto x86_l_9e0;
	case 2533ULL: goto x86_l_9e5;
	case 2539ULL: goto x86_l_9eb;
	case 2541ULL: goto x86_l_9ed;
	case 2547ULL: goto x86_l_9f3;
	case 2550ULL: goto x86_l_9f6;
	case 2552ULL: goto x86_l_9f8;
	case 2557ULL: goto x86_l_9fd;
	case 2562ULL: goto x86_l_a02;
	case 2567ULL: goto x86_l_a07;
	case 2572ULL: goto x86_l_a0c;
	case 2577ULL: goto x86_l_a11;
	case 2579ULL: goto x86_l_a13;
	case 2581ULL: goto x86_l_a15;
	case 2587ULL: goto x86_l_a1b;
	case 2594ULL: goto x86_l_a22;
	case 2600ULL: goto x86_l_a28;
	case 2605ULL: goto x86_l_a2d;
	case 2610ULL: goto x86_l_a32;
	case 2615ULL: goto x86_l_a37;
	case 2622ULL: goto x86_l_a3e;
	case 2624ULL: goto x86_l_a40;
	case 2629ULL: goto x86_l_a45;
	case 2634ULL: goto x86_l_a4a;
	case 2639ULL: goto x86_l_a4f;
	case 2644ULL: goto x86_l_a54;
	case 2649ULL: goto x86_l_a59;
	case 2651ULL: goto x86_l_a5b;
	case 2653ULL: goto x86_l_a5d;
	case 2659ULL: goto x86_l_a63;
	case 2666ULL: goto x86_l_a6a;
	case 2672ULL: goto x86_l_a70;
	case 2677ULL: goto x86_l_a75;
	case 2682ULL: goto x86_l_a7a;
	case 2687ULL: goto x86_l_a7f;
	case 2694ULL: goto x86_l_a86;
	case 2696ULL: goto x86_l_a88;
	case 2701ULL: goto x86_l_a8d;
	case 2706ULL: goto x86_l_a92;
	case 2711ULL: goto x86_l_a97;
	case 2716ULL: goto x86_l_a9c;
	case 2721ULL: goto x86_l_aa1;
	case 2723ULL: goto x86_l_aa3;
	case 2725ULL: goto x86_l_aa5;
	case 2731ULL: goto x86_l_aab;
	case 2738ULL: goto x86_l_ab2;
	case 2744ULL: goto x86_l_ab8;
	case 2749ULL: goto x86_l_abd;
	case 2754ULL: goto x86_l_ac2;
	case 2759ULL: goto x86_l_ac7;
	case 2766ULL: goto x86_l_ace;
	case 2768ULL: goto x86_l_ad0;
	case 2773ULL: goto x86_l_ad5;
	case 2778ULL: goto x86_l_ada;
	case 2783ULL: goto x86_l_adf;
	case 2788ULL: goto x86_l_ae4;
	case 2793ULL: goto x86_l_ae9;
	case 2795ULL: goto x86_l_aeb;
	case 2797ULL: goto x86_l_aed;
	case 2803ULL: goto x86_l_af3;
	case 2810ULL: goto x86_l_afa;
	case 2816ULL: goto x86_l_b00;
	case 2821ULL: goto x86_l_b05;
	case 2826ULL: goto x86_l_b0a;
	case 2831ULL: goto x86_l_b0f;
	case 2838ULL: goto x86_l_b16;
	case 2840ULL: goto x86_l_b18;
	case 2845ULL: goto x86_l_b1d;
	case 2850ULL: goto x86_l_b22;
	case 2855ULL: goto x86_l_b27;
	case 2860ULL: goto x86_l_b2c;
	case 2865ULL: goto x86_l_b31;
	case 2867ULL: goto x86_l_b33;
	case 2869ULL: goto x86_l_b35;
	case 2875ULL: goto x86_l_b3b;
	case 2882ULL: goto x86_l_b42;
	case 2888ULL: goto x86_l_b48;
	case 2893ULL: goto x86_l_b4d;
	case 2898ULL: goto x86_l_b52;
	case 2903ULL: goto x86_l_b57;
	case 2910ULL: goto x86_l_b5e;
	case 2912ULL: goto x86_l_b60;
	case 2917ULL: goto x86_l_b65;
	case 2922ULL: goto x86_l_b6a;
	case 2927ULL: goto x86_l_b6f;
	case 2932ULL: goto x86_l_b74;
	case 2937ULL: goto x86_l_b79;
	case 2939ULL: goto x86_l_b7b;
	case 2941ULL: goto x86_l_b7d;
	case 2947ULL: goto x86_l_b83;
	case 2954ULL: goto x86_l_b8a;
	case 2960ULL: goto x86_l_b90;
	case 2965ULL: goto x86_l_b95;
	case 2970ULL: goto x86_l_b9a;
	case 2975ULL: goto x86_l_b9f;
	case 2982ULL: goto x86_l_ba6;
	case 2984ULL: goto x86_l_ba8;
	case 2989ULL: goto x86_l_bad;
	case 2994ULL: goto x86_l_bb2;
	case 2999ULL: goto x86_l_bb7;
	case 3004ULL: goto x86_l_bbc;
	case 3009ULL: goto x86_l_bc1;
	case 3011ULL: goto x86_l_bc3;
	case 3013ULL: goto x86_l_bc5;
	case 3019ULL: goto x86_l_bcb;
	case 3026ULL: goto x86_l_bd2;
	case 3032ULL: goto x86_l_bd8;
	case 3037ULL: goto x86_l_bdd;
	case 3042ULL: goto x86_l_be2;
	case 3047ULL: goto x86_l_be7;
	case 3054ULL: goto x86_l_bee;
	case 3056ULL: goto x86_l_bf0;
	case 3061ULL: goto x86_l_bf5;
	case 3066ULL: goto x86_l_bfa;
	case 3071ULL: goto x86_l_bff;
	case 3076ULL: goto x86_l_c04;
	case 3081ULL: goto x86_l_c09;
	case 3083ULL: goto x86_l_c0b;
	case 3085ULL: goto x86_l_c0d;
	case 3091ULL: goto x86_l_c13;
	case 3098ULL: goto x86_l_c1a;
	case 3104ULL: goto x86_l_c20;
	case 3109ULL: goto x86_l_c25;
	case 3114ULL: goto x86_l_c2a;
	case 3119ULL: goto x86_l_c2f;
	case 3126ULL: goto x86_l_c36;
	case 3128ULL: goto x86_l_c38;
	case 3133ULL: goto x86_l_c3d;
	case 3138ULL: goto x86_l_c42;
	case 3143ULL: goto x86_l_c47;
	case 3148ULL: goto x86_l_c4c;
	case 3153ULL: goto x86_l_c51;
	case 3155ULL: goto x86_l_c53;
	case 3157ULL: goto x86_l_c55;
	case 3163ULL: goto x86_l_c5b;
	case 3170ULL: goto x86_l_c62;
	case 3176ULL: goto x86_l_c68;
	case 3181ULL: goto x86_l_c6d;
	case 3186ULL: goto x86_l_c72;
	case 3191ULL: goto x86_l_c77;
	case 3198ULL: goto x86_l_c7e;
	case 3204ULL: goto x86_l_c84;
	case 3209ULL: goto x86_l_c89;
	case 3214ULL: goto x86_l_c8e;
	case 3219ULL: goto x86_l_c93;
	case 3224ULL: goto x86_l_c98;
	case 3227ULL: goto x86_l_c9b;
	case 3229ULL: goto x86_l_c9d;
	case 3234ULL: goto x86_l_ca2;
	case 3239ULL: goto x86_l_ca7;
	case 3244ULL: goto x86_l_cac;
	case 3249ULL: goto x86_l_cb1;
	case 3254ULL: goto x86_l_cb6;
	case 3256ULL: goto x86_l_cb8;
	case 3258ULL: goto x86_l_cba;
	case 3264ULL: goto x86_l_cc0;
	case 3271ULL: goto x86_l_cc7;
	case 3277ULL: goto x86_l_ccd;
	case 3282ULL: goto x86_l_cd2;
	case 3287ULL: goto x86_l_cd7;
	case 3292ULL: goto x86_l_cdc;
	case 3299ULL: goto x86_l_ce3;
	case 3301ULL: goto x86_l_ce5;
	case 3306ULL: goto x86_l_cea;
	case 3311ULL: goto x86_l_cef;
	case 3316ULL: goto x86_l_cf4;
	case 3321ULL: goto x86_l_cf9;
	case 3326ULL: goto x86_l_cfe;
	case 3328ULL: goto x86_l_d00;
	case 3330ULL: goto x86_l_d02;
	case 3336ULL: goto x86_l_d08;
	case 3343ULL: goto x86_l_d0f;
	case 3349ULL: goto x86_l_d15;
	case 3354ULL: goto x86_l_d1a;
	case 3359ULL: goto x86_l_d1f;
	case 3364ULL: goto x86_l_d24;
	case 3371ULL: goto x86_l_d2b;
	case 3373ULL: goto x86_l_d2d;
	case 3378ULL: goto x86_l_d32;
	case 3383ULL: goto x86_l_d37;
	case 3388ULL: goto x86_l_d3c;
	case 3393ULL: goto x86_l_d41;
	case 3398ULL: goto x86_l_d46;
	case 3400ULL: goto x86_l_d48;
	case 3402ULL: goto x86_l_d4a;
	case 3408ULL: goto x86_l_d50;
	case 3415ULL: goto x86_l_d57;
	case 3421ULL: goto x86_l_d5d;
	case 3426ULL: goto x86_l_d62;
	case 3431ULL: goto x86_l_d67;
	case 3436ULL: goto x86_l_d6c;
	case 3443ULL: goto x86_l_d73;
	case 3445ULL: goto x86_l_d75;
	case 3450ULL: goto x86_l_d7a;
	case 3455ULL: goto x86_l_d7f;
	case 3460ULL: goto x86_l_d84;
	case 3465ULL: goto x86_l_d89;
	case 3470ULL: goto x86_l_d8e;
	case 3472ULL: goto x86_l_d90;
	case 3474ULL: goto x86_l_d92;
	case 3480ULL: goto x86_l_d98;
	case 3487ULL: goto x86_l_d9f;
	case 3493ULL: goto x86_l_da5;
	case 3498ULL: goto x86_l_daa;
	case 3503ULL: goto x86_l_daf;
	case 3508ULL: goto x86_l_db4;
	case 3515ULL: goto x86_l_dbb;
	case 3517ULL: goto x86_l_dbd;
	case 3522ULL: goto x86_l_dc2;
	case 3527ULL: goto x86_l_dc7;
	case 3532ULL: goto x86_l_dcc;
	case 3537ULL: goto x86_l_dd1;
	case 3542ULL: goto x86_l_dd6;
	case 3544ULL: goto x86_l_dd8;
	case 3546ULL: goto x86_l_dda;
	case 3552ULL: goto x86_l_de0;
	case 3559ULL: goto x86_l_de7;
	case 3565ULL: goto x86_l_ded;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6ed:
	/* 0x6ed: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_6ef:
	/* 0x6ef: js     f62 <generic_sleepable_preload+0xf62> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3938ULL;
	}
x86_l_6f5:
	/* 0x6f5: cmp    WORD PTR [r13+r15*1-0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743833191383040ULL);
x86_l_6fc:
	/* 0x6fc: je     fcf <generic_sleepable_preload+0xfcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4047ULL;
	}
x86_l_702:
	/* 0x702: mov    ecx,DWORD PTR [r13+r15*1-0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551554ULL);
x86_l_707:
	/* 0x707: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_70c:
	/* 0x70c: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_711:
	/* 0x711: cmp    WORD PTR [r13+r15*1-0x3a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743824601448448ULL);
x86_l_718:
	/* 0x718: je     738 <generic_sleepable_preload+0x738> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_738;
	}
x86_l_71a:
	/* 0x71a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_71f:
	/* 0x71f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_724:
	/* 0x724: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_729:
	/* 0x729: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_72e:
	/* 0x72e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_730:
	/* 0x730: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_732:
	/* 0x732: js     f75 <generic_sleepable_preload+0xf75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3957ULL;
	}
x86_l_738:
	/* 0x738: cmp    WORD PTR [r13+r15*1-0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743867551121408ULL);
x86_l_73f:
	/* 0x73f: je     fcf <generic_sleepable_preload+0xfcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4047ULL;
	}
x86_l_745:
	/* 0x745: mov    ecx,DWORD PTR [r13+r15*1-0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551562ULL);
x86_l_74a:
	/* 0x74a: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_74f:
	/* 0x74f: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_754:
	/* 0x754: cmp    WORD PTR [r13+r15*1-0x32],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743858961186816ULL);
x86_l_75b:
	/* 0x75b: je     77b <generic_sleepable_preload+0x77b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_77b;
	}
x86_l_75d:
	/* 0x75d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_762:
	/* 0x762: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_767:
	/* 0x767: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_76c:
	/* 0x76c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_771:
	/* 0x771: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_773:
	/* 0x773: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_775:
	/* 0x775: js     f88 <generic_sleepable_preload+0xf88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3976ULL;
	}
x86_l_77b:
	/* 0x77b: cmp    WORD PTR [r13+r15*1-0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743901910859776ULL);
x86_l_782:
	/* 0x782: je     fcf <generic_sleepable_preload+0xfcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4047ULL;
	}
x86_l_788:
	/* 0x788: mov    ecx,DWORD PTR [r13+r15*1-0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551570ULL);
x86_l_78d:
	/* 0x78d: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_792:
	/* 0x792: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_797:
	/* 0x797: cmp    WORD PTR [r13+r15*1-0x2a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743893320925184ULL);
x86_l_79e:
	/* 0x79e: je     7be <generic_sleepable_preload+0x7be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7be;
	}
x86_l_7a0:
	/* 0x7a0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_7a5:
	/* 0x7a5: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7aa:
	/* 0x7aa: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7af:
	/* 0x7af: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7b4:
	/* 0x7b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7b6:
	/* 0x7b6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_7b8:
	/* 0x7b8: js     f9b <generic_sleepable_preload+0xf9b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3995ULL;
	}
x86_l_7be:
	/* 0x7be: cmp    WORD PTR [r13+r15*1-0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743936270598144ULL);
x86_l_7c5:
	/* 0x7c5: je     fcf <generic_sleepable_preload+0xfcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4047ULL;
	}
x86_l_7cb:
	/* 0x7cb: mov    ecx,DWORD PTR [r13+r15*1-0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551578ULL);
x86_l_7d0:
	/* 0x7d0: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_7d5:
	/* 0x7d5: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7da:
	/* 0x7da: cmp    WORD PTR [r13+r15*1-0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743927680663552ULL);
x86_l_7e1:
	/* 0x7e1: je     801 <generic_sleepable_preload+0x801> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_801;
	}
x86_l_7e3:
	/* 0x7e3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_7e8:
	/* 0x7e8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7ed:
	/* 0x7ed: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7f2:
	/* 0x7f2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7f7:
	/* 0x7f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7f9:
	/* 0x7f9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_7fb:
	/* 0x7fb: js     fae <generic_sleepable_preload+0xfae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4014ULL;
	}
x86_l_801:
	/* 0x801: cmp    WORD PTR [r13+r15*1-0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743970630336512ULL);
x86_l_808:
	/* 0x808: je     fcf <generic_sleepable_preload+0xfcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4047ULL;
	}
x86_l_80e:
	/* 0x80e: mov    ecx,DWORD PTR [r13+r15*1-0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551586ULL);
x86_l_813:
	/* 0x813: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_818:
	/* 0x818: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_81d:
	/* 0x81d: cmp    WORD PTR [r13+r15*1-0x1a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743962040401920ULL);
x86_l_824:
	/* 0x824: je     844 <generic_sleepable_preload+0x844> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_844;
	}
x86_l_826:
	/* 0x826: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_82b:
	/* 0x82b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_830:
	/* 0x830: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_835:
	/* 0x835: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_83a:
	/* 0x83a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_83c:
	/* 0x83c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_83e:
	/* 0x83e: js     fc1 <generic_sleepable_preload+0xfc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4033ULL;
	}
x86_l_844:
	/* 0x844: cmp    WORD PTR [r13+r15*1-0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744004990074880ULL);
x86_l_84b:
	/* 0x84b: je     fcf <generic_sleepable_preload+0xfcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4047ULL;
	}
x86_l_851:
	/* 0x851: mov    ecx,DWORD PTR [r13+r15*1-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551594ULL);
x86_l_856:
	/* 0x856: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_85b:
	/* 0x85b: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_860:
	/* 0x860: cmp    WORD PTR [r13+r15*1-0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743996400140288ULL);
x86_l_867:
	/* 0x867: je     887 <generic_sleepable_preload+0x887> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_887;
	}
x86_l_869:
	/* 0x869: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_86e:
	/* 0x86e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_873:
	/* 0x873: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_878:
	/* 0x878: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_87d:
	/* 0x87d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_87f:
	/* 0x87f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_881:
	/* 0x881: js     116c <generic_sleepable_preload+0x116c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4460ULL;
	}
x86_l_887:
	/* 0x887: cmp    WORD PTR [r13+r15*1-0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744039349813248ULL);
x86_l_88e:
	/* 0x88e: je     fcf <generic_sleepable_preload+0xfcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4047ULL;
	}
x86_l_894:
	/* 0x894: mov    ecx,DWORD PTR [r13+r15*1-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551602ULL);
x86_l_899:
	/* 0x899: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_89e:
	/* 0x89e: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8a3:
	/* 0x8a3: cmp    WORD PTR [r13+r15*1-0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744030759878656ULL);
x86_l_8aa:
	/* 0x8aa: je     8ca <generic_sleepable_preload+0x8ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8ca;
	}
x86_l_8ac:
	/* 0x8ac: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_8b1:
	/* 0x8b1: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8b6:
	/* 0x8b6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
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
	/* 0x8c4: js     119b <generic_sleepable_preload+0x119b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4507ULL;
	}
x86_l_8ca:
	/* 0x8ca: cmp    WORD PTR [r13+r15*1+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_8d1:
	/* 0x8d1: je     fcf <generic_sleepable_preload+0xfcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4047ULL;
	}
x86_l_8d7:
	/* 0x8d7: mov    ecx,DWORD PTR [r13+r15*1-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551610ULL);
x86_l_8dc:
	/* 0x8dc: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_8e1:
	/* 0x8e1: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8e6:
	/* 0x8e6: cmp    WORD PTR [r13+r15*1-0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744065119617024ULL);
x86_l_8ed:
	/* 0x8ed: je     fcf <generic_sleepable_preload+0xfcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4047ULL;
	}
x86_l_8f3:
	/* 0x8f3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_8f8:
	/* 0x8f8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8fd:
	/* 0x8fd: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_902:
	/* 0x902: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_907:
	/* 0x907: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_909:
	/* 0x909: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_90b:
	/* 0x90b: jns    fcf <generic_sleepable_preload+0xfcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 4047ULL;
	}
x86_l_911:
	/* 0x911: mov    r12d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 10ULL);
x86_l_917:
	/* 0x917: jmp    fc7 <generic_sleepable_preload+0xfc7> */
	return 4039ULL;
x86_l_91c:
	/* 0x91c: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_922:
	/* 0x922: jmp    fc7 <generic_sleepable_preload+0xfc7> */
	return 4039ULL;
x86_l_927:
	/* 0x927: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_92f:
	/* 0x92f: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_932:
	/* 0x932: je     99d <generic_sleepable_preload+0x99d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_99d;
	}
x86_l_934:
	/* 0x934: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_939:
	/* 0x939: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_93e:
	/* 0x93e: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_941:
	/* 0x941: je     99d <generic_sleepable_preload+0x99d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_99d;
	}
x86_l_943:
	/* 0x943: jmp    9b0 <generic_sleepable_preload+0x9b0> */
	goto x86_l_9b0;
x86_l_945:
	/* 0x945: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_94d:
	/* 0x94d: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_950:
	/* 0x950: je     99d <generic_sleepable_preload+0x99d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_99d;
	}
x86_l_952:
	/* 0x952: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_957:
	/* 0x957: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_95c:
	/* 0x95c: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_95f:
	/* 0x95f: je     99d <generic_sleepable_preload+0x99d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_99d;
	}
x86_l_961:
	/* 0x961: jmp    9b0 <generic_sleepable_preload+0x9b0> */
	goto x86_l_9b0;
x86_l_963:
	/* 0x963: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_96b:
	/* 0x96b: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_96e:
	/* 0x96e: je     99d <generic_sleepable_preload+0x99d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_99d;
	}
x86_l_970:
	/* 0x970: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_975:
	/* 0x975: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_97a:
	/* 0x97a: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_97d:
	/* 0x97d: je     99d <generic_sleepable_preload+0x99d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_99d;
	}
x86_l_97f:
	/* 0x97f: jmp    9b0 <generic_sleepable_preload+0x9b0> */
	goto x86_l_9b0;
x86_l_981:
	/* 0x981: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_989:
	/* 0x989: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_98c:
	/* 0x98c: je     99d <generic_sleepable_preload+0x99d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_99d;
	}
x86_l_98e:
	/* 0x98e: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_993:
	/* 0x993: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_998:
	/* 0x998: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_99b:
	/* 0x99b: jne    9b0 <generic_sleepable_preload+0x9b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_9b0;
	}
x86_l_99d:
	/* 0x99d: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_9a0:
	/* 0x9a0: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_9a2:
	/* 0x9a2: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_9a4:
	/* 0x9a4: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_9a9:
	/* 0x9a9: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_9ab:
	/* 0x9ab: bzhi   rsi,QWORD PTR [rdx],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RSI, X86_RDX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_9b0:
	/* 0x9b0: mov    QWORD PTR [rsp+0x8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9b5:
	/* 0x9b5: mov    ebp,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9b8:
	/* 0x9b8: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9bb:
	/* 0x9bb: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_9bd:
	/* 0x9bd: mov    DWORD PTR [rsp+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_9c1:
	/* 0x9c1: cmp    WORD PTR [r13+r15*1-0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743764471906304ULL);
x86_l_9c8:
	/* 0x9c8: je     10b8 <generic_sleepable_preload+0x10b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4280ULL;
	}
x86_l_9ce:
	/* 0x9ce: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_9d5:
	/* 0x9d5: movzx  ecx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_9d8:
	/* 0x9d8: mov    eax,DWORD PTR [r13+r15*1-0x4e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551538ULL);
x86_l_9dd:
	/* 0x9dd: add    rsi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_9e0:
	/* 0x9e0: mov    QWORD PTR [rsp+0x8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9e5:
	/* 0x9e5: movzx  eax,WORD PTR [r13+r15*1-0x4a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R15, 0, X86_WIDTH_16), 18446744073709551542ULL);
x86_l_9eb:
	/* 0x9eb: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_9ed:
	/* 0x9ed: je     c98 <generic_sleepable_preload+0xc98> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c98;
	}
x86_l_9f3:
	/* 0x9f3: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_9f6:
	/* 0x9f6: je     a1b <generic_sleepable_preload+0xa1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a1b;
	}
x86_l_9f8:
	/* 0x9f8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_9fd:
	/* 0x9fd: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a02:
	/* 0xa02: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a07:
	/* 0xa07: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a0c:
	/* 0xa0c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a11:
	/* 0xa11: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a13:
	/* 0xa13: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a15:
	/* 0xa15: js     f57 <generic_sleepable_preload+0xf57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3927ULL;
	}
x86_l_a1b:
	/* 0xa1b: cmp    WORD PTR [r13+r15*1-0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743798831644672ULL);
x86_l_a22:
	/* 0xa22: je     10b8 <generic_sleepable_preload+0x10b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4280ULL;
	}
x86_l_a28:
	/* 0xa28: mov    ecx,DWORD PTR [r13+r15*1-0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551546ULL);
x86_l_a2d:
	/* 0xa2d: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_a32:
	/* 0xa32: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a37:
	/* 0xa37: cmp    WORD PTR [r13+r15*1-0x42],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743790241710080ULL);
x86_l_a3e:
	/* 0xa3e: je     a63 <generic_sleepable_preload+0xa63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a63;
	}
x86_l_a40:
	/* 0xa40: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_a45:
	/* 0xa45: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_a4a:
	/* 0xa4a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a4f:
	/* 0xa4f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a54:
	/* 0xa54: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a59:
	/* 0xa59: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a5b:
	/* 0xa5b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a5d:
	/* 0xa5d: js     f6a <generic_sleepable_preload+0xf6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3946ULL;
	}
x86_l_a63:
	/* 0xa63: cmp    WORD PTR [r13+r15*1-0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743833191383040ULL);
x86_l_a6a:
	/* 0xa6a: je     10b8 <generic_sleepable_preload+0x10b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4280ULL;
	}
x86_l_a70:
	/* 0xa70: mov    ecx,DWORD PTR [r13+r15*1-0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551554ULL);
x86_l_a75:
	/* 0xa75: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_a7a:
	/* 0xa7a: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a7f:
	/* 0xa7f: cmp    WORD PTR [r13+r15*1-0x3a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743824601448448ULL);
x86_l_a86:
	/* 0xa86: je     aab <generic_sleepable_preload+0xaab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_aab;
	}
x86_l_a88:
	/* 0xa88: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_a8d:
	/* 0xa8d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_a92:
	/* 0xa92: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a97:
	/* 0xa97: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a9c:
	/* 0xa9c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_aa1:
	/* 0xaa1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aa3:
	/* 0xaa3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_aa5:
	/* 0xaa5: js     f7d <generic_sleepable_preload+0xf7d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3965ULL;
	}
x86_l_aab:
	/* 0xaab: cmp    WORD PTR [r13+r15*1-0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743867551121408ULL);
x86_l_ab2:
	/* 0xab2: je     10b8 <generic_sleepable_preload+0x10b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4280ULL;
	}
x86_l_ab8:
	/* 0xab8: mov    ecx,DWORD PTR [r13+r15*1-0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551562ULL);
x86_l_abd:
	/* 0xabd: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_ac2:
	/* 0xac2: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ac7:
	/* 0xac7: cmp    WORD PTR [r13+r15*1-0x32],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743858961186816ULL);
x86_l_ace:
	/* 0xace: je     af3 <generic_sleepable_preload+0xaf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_af3;
	}
x86_l_ad0:
	/* 0xad0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_ad5:
	/* 0xad5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_ada:
	/* 0xada: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_adf:
	/* 0xadf: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ae4:
	/* 0xae4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ae9:
	/* 0xae9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aeb:
	/* 0xaeb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_aed:
	/* 0xaed: js     f90 <generic_sleepable_preload+0xf90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3984ULL;
	}
x86_l_af3:
	/* 0xaf3: cmp    WORD PTR [r13+r15*1-0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743901910859776ULL);
x86_l_afa:
	/* 0xafa: je     10b8 <generic_sleepable_preload+0x10b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4280ULL;
	}
x86_l_b00:
	/* 0xb00: mov    ecx,DWORD PTR [r13+r15*1-0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551570ULL);
x86_l_b05:
	/* 0xb05: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_b0a:
	/* 0xb0a: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b0f:
	/* 0xb0f: cmp    WORD PTR [r13+r15*1-0x2a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743893320925184ULL);
x86_l_b16:
	/* 0xb16: je     b3b <generic_sleepable_preload+0xb3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b3b;
	}
x86_l_b18:
	/* 0xb18: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_b1d:
	/* 0xb1d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_b22:
	/* 0xb22: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b27:
	/* 0xb27: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b2c:
	/* 0xb2c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b31:
	/* 0xb31: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b33:
	/* 0xb33: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b35:
	/* 0xb35: js     fa3 <generic_sleepable_preload+0xfa3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4003ULL;
	}
x86_l_b3b:
	/* 0xb3b: cmp    WORD PTR [r13+r15*1-0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743936270598144ULL);
x86_l_b42:
	/* 0xb42: je     10b8 <generic_sleepable_preload+0x10b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4280ULL;
	}
x86_l_b48:
	/* 0xb48: mov    ecx,DWORD PTR [r13+r15*1-0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551578ULL);
x86_l_b4d:
	/* 0xb4d: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_b52:
	/* 0xb52: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b57:
	/* 0xb57: cmp    WORD PTR [r13+r15*1-0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743927680663552ULL);
x86_l_b5e:
	/* 0xb5e: je     b83 <generic_sleepable_preload+0xb83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b83;
	}
x86_l_b60:
	/* 0xb60: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_b65:
	/* 0xb65: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_b6a:
	/* 0xb6a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b6f:
	/* 0xb6f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b74:
	/* 0xb74: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b79:
	/* 0xb79: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b7b:
	/* 0xb7b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b7d:
	/* 0xb7d: js     fb6 <generic_sleepable_preload+0xfb6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4022ULL;
	}
x86_l_b83:
	/* 0xb83: cmp    WORD PTR [r13+r15*1-0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743970630336512ULL);
x86_l_b8a:
	/* 0xb8a: je     10b8 <generic_sleepable_preload+0x10b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4280ULL;
	}
x86_l_b90:
	/* 0xb90: mov    ecx,DWORD PTR [r13+r15*1-0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551586ULL);
x86_l_b95:
	/* 0xb95: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_b9a:
	/* 0xb9a: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b9f:
	/* 0xb9f: cmp    WORD PTR [r13+r15*1-0x1a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743962040401920ULL);
x86_l_ba6:
	/* 0xba6: je     bcb <generic_sleepable_preload+0xbcb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bcb;
	}
x86_l_ba8:
	/* 0xba8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_bad:
	/* 0xbad: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_bb2:
	/* 0xbb2: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bb7:
	/* 0xbb7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bbc:
	/* 0xbbc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bc1:
	/* 0xbc1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bc3:
	/* 0xbc3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_bc5:
	/* 0xbc5: js     10aa <generic_sleepable_preload+0x10aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4266ULL;
	}
x86_l_bcb:
	/* 0xbcb: cmp    WORD PTR [r13+r15*1-0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744004990074880ULL);
x86_l_bd2:
	/* 0xbd2: je     10b8 <generic_sleepable_preload+0x10b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4280ULL;
	}
x86_l_bd8:
	/* 0xbd8: mov    ecx,DWORD PTR [r13+r15*1-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551594ULL);
x86_l_bdd:
	/* 0xbdd: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_be2:
	/* 0xbe2: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_be7:
	/* 0xbe7: cmp    WORD PTR [r13+r15*1-0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743996400140288ULL);
x86_l_bee:
	/* 0xbee: je     c13 <generic_sleepable_preload+0xc13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c13;
	}
x86_l_bf0:
	/* 0xbf0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_bf5:
	/* 0xbf5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_bfa:
	/* 0xbfa: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bff:
	/* 0xbff: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c04:
	/* 0xc04: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c09:
	/* 0xc09: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c0b:
	/* 0xc0b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c0d:
	/* 0xc0d: js     117f <generic_sleepable_preload+0x117f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4479ULL;
	}
x86_l_c13:
	/* 0xc13: cmp    WORD PTR [r13+r15*1-0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744039349813248ULL);
x86_l_c1a:
	/* 0xc1a: je     10b8 <generic_sleepable_preload+0x10b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4280ULL;
	}
x86_l_c20:
	/* 0xc20: mov    ecx,DWORD PTR [r13+r15*1-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551602ULL);
x86_l_c25:
	/* 0xc25: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_c2a:
	/* 0xc2a: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c2f:
	/* 0xc2f: cmp    WORD PTR [r13+r15*1-0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744030759878656ULL);
x86_l_c36:
	/* 0xc36: je     c5b <generic_sleepable_preload+0xc5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c5b;
	}
x86_l_c38:
	/* 0xc38: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_c3d:
	/* 0xc3d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_c42:
	/* 0xc42: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c47:
	/* 0xc47: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c4c:
	/* 0xc4c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c51:
	/* 0xc51: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c53:
	/* 0xc53: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c55:
	/* 0xc55: js     11a6 <generic_sleepable_preload+0x11a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4518ULL;
	}
x86_l_c5b:
	/* 0xc5b: cmp    WORD PTR [r13+r15*1+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_c62:
	/* 0xc62: je     10b8 <generic_sleepable_preload+0x10b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4280ULL;
	}
x86_l_c68:
	/* 0xc68: mov    ecx,DWORD PTR [r13+r15*1-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551610ULL);
x86_l_c6d:
	/* 0xc6d: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_c72:
	/* 0xc72: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c77:
	/* 0xc77: cmp    WORD PTR [r13+r15*1-0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744065119617024ULL);
x86_l_c7e:
	/* 0xc7e: je     10b8 <generic_sleepable_preload+0x10b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4280ULL;
	}
x86_l_c84:
	/* 0xc84: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_c89:
	/* 0xc89: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_c8e:
	/* 0xc8e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c93:
	/* 0xc93: jmp    f38 <generic_sleepable_preload+0xf38> */
	return 3896ULL;
x86_l_c98:
	/* 0xc98: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_c9b:
	/* 0xc9b: je     cc0 <generic_sleepable_preload+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc0;
	}
x86_l_c9d:
	/* 0xc9d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_ca2:
	/* 0xca2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_ca7:
	/* 0xca7: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cac:
	/* 0xcac: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cb1:
	/* 0xcb1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_cb6:
	/* 0xcb6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cb8:
	/* 0xcb8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_cba:
	/* 0xcba: js     f57 <generic_sleepable_preload+0xf57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3927ULL;
	}
x86_l_cc0:
	/* 0xcc0: cmp    WORD PTR [r13+r15*1-0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743798831644672ULL);
x86_l_cc7:
	/* 0xcc7: je     10b8 <generic_sleepable_preload+0x10b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4280ULL;
	}
x86_l_ccd:
	/* 0xccd: mov    ecx,DWORD PTR [r13+r15*1-0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551546ULL);
x86_l_cd2:
	/* 0xcd2: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_cd7:
	/* 0xcd7: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cdc:
	/* 0xcdc: cmp    WORD PTR [r13+r15*1-0x42],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743790241710080ULL);
x86_l_ce3:
	/* 0xce3: je     d08 <generic_sleepable_preload+0xd08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d08;
	}
x86_l_ce5:
	/* 0xce5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_cea:
	/* 0xcea: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_cef:
	/* 0xcef: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cf4:
	/* 0xcf4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cf9:
	/* 0xcf9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_cfe:
	/* 0xcfe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d00:
	/* 0xd00: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d02:
	/* 0xd02: js     f6a <generic_sleepable_preload+0xf6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3946ULL;
	}
x86_l_d08:
	/* 0xd08: cmp    WORD PTR [r13+r15*1-0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743833191383040ULL);
x86_l_d0f:
	/* 0xd0f: je     10b8 <generic_sleepable_preload+0x10b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4280ULL;
	}
x86_l_d15:
	/* 0xd15: mov    ecx,DWORD PTR [r13+r15*1-0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551554ULL);
x86_l_d1a:
	/* 0xd1a: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_d1f:
	/* 0xd1f: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d24:
	/* 0xd24: cmp    WORD PTR [r13+r15*1-0x3a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743824601448448ULL);
x86_l_d2b:
	/* 0xd2b: je     d50 <generic_sleepable_preload+0xd50> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d50;
	}
x86_l_d2d:
	/* 0xd2d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_d32:
	/* 0xd32: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_d37:
	/* 0xd37: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d3c:
	/* 0xd3c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d41:
	/* 0xd41: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d46:
	/* 0xd46: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d48:
	/* 0xd48: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d4a:
	/* 0xd4a: js     f7d <generic_sleepable_preload+0xf7d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3965ULL;
	}
x86_l_d50:
	/* 0xd50: cmp    WORD PTR [r13+r15*1-0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743867551121408ULL);
x86_l_d57:
	/* 0xd57: je     10b8 <generic_sleepable_preload+0x10b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4280ULL;
	}
x86_l_d5d:
	/* 0xd5d: mov    ecx,DWORD PTR [r13+r15*1-0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551562ULL);
x86_l_d62:
	/* 0xd62: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_d67:
	/* 0xd67: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d6c:
	/* 0xd6c: cmp    WORD PTR [r13+r15*1-0x32],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743858961186816ULL);
x86_l_d73:
	/* 0xd73: je     d98 <generic_sleepable_preload+0xd98> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d98;
	}
x86_l_d75:
	/* 0xd75: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_d7a:
	/* 0xd7a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_d7f:
	/* 0xd7f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d84:
	/* 0xd84: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d89:
	/* 0xd89: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d8e:
	/* 0xd8e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d90:
	/* 0xd90: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d92:
	/* 0xd92: js     f90 <generic_sleepable_preload+0xf90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3984ULL;
	}
x86_l_d98:
	/* 0xd98: cmp    WORD PTR [r13+r15*1-0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743901910859776ULL);
x86_l_d9f:
	/* 0xd9f: je     10b8 <generic_sleepable_preload+0x10b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4280ULL;
	}
x86_l_da5:
	/* 0xda5: mov    ecx,DWORD PTR [r13+r15*1-0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551570ULL);
x86_l_daa:
	/* 0xdaa: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_daf:
	/* 0xdaf: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_db4:
	/* 0xdb4: cmp    WORD PTR [r13+r15*1-0x2a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743893320925184ULL);
x86_l_dbb:
	/* 0xdbb: je     de0 <generic_sleepable_preload+0xde0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_de0;
	}
x86_l_dbd:
	/* 0xdbd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_dc2:
	/* 0xdc2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_dc7:
	/* 0xdc7: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dcc:
	/* 0xdcc: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dd1:
	/* 0xdd1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_dd6:
	/* 0xdd6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dd8:
	/* 0xdd8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_dda:
	/* 0xdda: js     fa3 <generic_sleepable_preload+0xfa3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4003ULL;
	}
x86_l_de0:
	/* 0xde0: cmp    WORD PTR [r13+r15*1-0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743936270598144ULL);
x86_l_de7:
	/* 0xde7: je     10b8 <generic_sleepable_preload+0x10b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4280ULL;
	}
x86_l_ded:
	/* 0xded: mov    ecx,DWORD PTR [r13+r15*1-0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551578ULL);
	return 3570ULL;
}

static __noinline __u64 tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3570ULL: goto x86_l_df2;
	case 3575ULL: goto x86_l_df7;
	case 3580ULL: goto x86_l_dfc;
	case 3587ULL: goto x86_l_e03;
	case 3589ULL: goto x86_l_e05;
	case 3594ULL: goto x86_l_e0a;
	case 3599ULL: goto x86_l_e0f;
	case 3604ULL: goto x86_l_e14;
	case 3609ULL: goto x86_l_e19;
	case 3614ULL: goto x86_l_e1e;
	case 3616ULL: goto x86_l_e20;
	case 3618ULL: goto x86_l_e22;
	case 3624ULL: goto x86_l_e28;
	case 3631ULL: goto x86_l_e2f;
	case 3637ULL: goto x86_l_e35;
	case 3642ULL: goto x86_l_e3a;
	case 3647ULL: goto x86_l_e3f;
	case 3652ULL: goto x86_l_e44;
	case 3659ULL: goto x86_l_e4b;
	case 3661ULL: goto x86_l_e4d;
	case 3666ULL: goto x86_l_e52;
	case 3671ULL: goto x86_l_e57;
	case 3676ULL: goto x86_l_e5c;
	case 3681ULL: goto x86_l_e61;
	case 3686ULL: goto x86_l_e66;
	case 3688ULL: goto x86_l_e68;
	case 3690ULL: goto x86_l_e6a;
	case 3696ULL: goto x86_l_e70;
	case 3703ULL: goto x86_l_e77;
	case 3709ULL: goto x86_l_e7d;
	case 3714ULL: goto x86_l_e82;
	case 3719ULL: goto x86_l_e87;
	case 3724ULL: goto x86_l_e8c;
	case 3731ULL: goto x86_l_e93;
	case 3733ULL: goto x86_l_e95;
	case 3738ULL: goto x86_l_e9a;
	case 3743ULL: goto x86_l_e9f;
	case 3748ULL: goto x86_l_ea4;
	case 3753ULL: goto x86_l_ea9;
	case 3758ULL: goto x86_l_eae;
	case 3760ULL: goto x86_l_eb0;
	case 3762ULL: goto x86_l_eb2;
	case 3768ULL: goto x86_l_eb8;
	case 3775ULL: goto x86_l_ebf;
	case 3781ULL: goto x86_l_ec5;
	case 3786ULL: goto x86_l_eca;
	case 3791ULL: goto x86_l_ecf;
	case 3796ULL: goto x86_l_ed4;
	case 3803ULL: goto x86_l_edb;
	case 3805ULL: goto x86_l_edd;
	case 3810ULL: goto x86_l_ee2;
	case 3815ULL: goto x86_l_ee7;
	case 3820ULL: goto x86_l_eec;
	case 3825ULL: goto x86_l_ef1;
	case 3830ULL: goto x86_l_ef6;
	case 3832ULL: goto x86_l_ef8;
	case 3834ULL: goto x86_l_efa;
	case 3840ULL: goto x86_l_f00;
	case 3847ULL: goto x86_l_f07;
	case 3853ULL: goto x86_l_f0d;
	case 3858ULL: goto x86_l_f12;
	case 3863ULL: goto x86_l_f17;
	case 3868ULL: goto x86_l_f1c;
	case 3875ULL: goto x86_l_f23;
	case 3881ULL: goto x86_l_f29;
	case 3886ULL: goto x86_l_f2e;
	case 3891ULL: goto x86_l_f33;
	case 3896ULL: goto x86_l_f38;
	case 3901ULL: goto x86_l_f3d;
	case 3906ULL: goto x86_l_f42;
	case 3908ULL: goto x86_l_f44;
	case 3910ULL: goto x86_l_f46;
	case 3916ULL: goto x86_l_f4c;
	case 3922ULL: goto x86_l_f52;
	case 3927ULL: goto x86_l_f57;
	case 3933ULL: goto x86_l_f5d;
	case 3938ULL: goto x86_l_f62;
	case 3944ULL: goto x86_l_f68;
	case 3946ULL: goto x86_l_f6a;
	case 3952ULL: goto x86_l_f70;
	case 3957ULL: goto x86_l_f75;
	case 3963ULL: goto x86_l_f7b;
	case 3965ULL: goto x86_l_f7d;
	case 3971ULL: goto x86_l_f83;
	case 3976ULL: goto x86_l_f88;
	case 3982ULL: goto x86_l_f8e;
	case 3984ULL: goto x86_l_f90;
	case 3990ULL: goto x86_l_f96;
	case 3995ULL: goto x86_l_f9b;
	case 4001ULL: goto x86_l_fa1;
	case 4003ULL: goto x86_l_fa3;
	case 4009ULL: goto x86_l_fa9;
	case 4014ULL: goto x86_l_fae;
	case 4020ULL: goto x86_l_fb4;
	case 4022ULL: goto x86_l_fb6;
	case 4028ULL: goto x86_l_fbc;
	case 4033ULL: goto x86_l_fc1;
	case 4039ULL: goto x86_l_fc7;
	case 4047ULL: goto x86_l_fcf;
	case 4050ULL: goto x86_l_fd2;
	case 4055ULL: goto x86_l_fd7;
	case 4060ULL: goto x86_l_fdc;
	case 4065ULL: goto x86_l_fe1;
	case 4068ULL: goto x86_l_fe4;
	case 4070ULL: goto x86_l_fe6;
	case 4074ULL: goto x86_l_fea;
	case 4080ULL: goto x86_l_ff0;
	case 4085ULL: goto x86_l_ff5;
	case 4093ULL: goto x86_l_ffd;
	case 4098ULL: goto x86_l_1002;
	case 4100ULL: goto x86_l_1004;
	case 4105ULL: goto x86_l_1009;
	case 4113ULL: goto x86_l_1011;
	case 4118ULL: goto x86_l_1016;
	case 4125ULL: goto x86_l_101d;
	case 4130ULL: goto x86_l_1022;
	case 4132ULL: goto x86_l_1024;
	case 4135ULL: goto x86_l_1027;
	case 4141ULL: goto x86_l_102d;
	case 4144ULL: goto x86_l_1030;
	case 4149ULL: goto x86_l_1035;
	case 4151ULL: goto x86_l_1037;
	case 4156ULL: goto x86_l_103c;
	case 4159ULL: goto x86_l_103f;
	case 4166ULL: goto x86_l_1046;
	case 4169ULL: goto x86_l_1049;
	case 4172ULL: goto x86_l_104c;
	case 4174ULL: goto x86_l_104e;
	case 4176ULL: goto x86_l_1050;
	case 4181ULL: goto x86_l_1055;
	case 4184ULL: goto x86_l_1058;
	case 4187ULL: goto x86_l_105b;
	case 4190ULL: goto x86_l_105e;
	case 4192ULL: goto x86_l_1060;
	case 4195ULL: goto x86_l_1063;
	case 4201ULL: goto x86_l_1069;
	case 4206ULL: goto x86_l_106e;
	case 4212ULL: goto x86_l_1074;
	case 4216ULL: goto x86_l_1078;
	case 4221ULL: goto x86_l_107d;
	case 4229ULL: goto x86_l_1085;
	case 4231ULL: goto x86_l_1087;
	case 4234ULL: goto x86_l_108a;
	case 4239ULL: goto x86_l_108f;
	case 4241ULL: goto x86_l_1091;
	case 4244ULL: goto x86_l_1094;
	case 4247ULL: goto x86_l_1097;
	case 4249ULL: goto x86_l_1099;
	case 4255ULL: goto x86_l_109f;
	case 4261ULL: goto x86_l_10a5;
	case 4266ULL: goto x86_l_10aa;
	case 4272ULL: goto x86_l_10b0;
	case 4280ULL: goto x86_l_10b8;
	case 4283ULL: goto x86_l_10bb;
	case 4289ULL: goto x86_l_10c1;
	case 4294ULL: goto x86_l_10c6;
	case 4302ULL: goto x86_l_10ce;
	case 4307ULL: goto x86_l_10d3;
	case 4309ULL: goto x86_l_10d5;
	case 4314ULL: goto x86_l_10da;
	case 4322ULL: goto x86_l_10e2;
	case 4327ULL: goto x86_l_10e7;
	case 4334ULL: goto x86_l_10ee;
	case 4339ULL: goto x86_l_10f3;
	case 4341ULL: goto x86_l_10f5;
	case 4344ULL: goto x86_l_10f8;
	case 4350ULL: goto x86_l_10fe;
	case 4353ULL: goto x86_l_1101;
	case 4358ULL: goto x86_l_1106;
	case 4360ULL: goto x86_l_1108;
	case 4365ULL: goto x86_l_110d;
	case 4368ULL: goto x86_l_1110;
	case 4375ULL: goto x86_l_1117;
	case 4378ULL: goto x86_l_111a;
	case 4381ULL: goto x86_l_111d;
	case 4383ULL: goto x86_l_111f;
	case 4385ULL: goto x86_l_1121;
	case 4390ULL: goto x86_l_1126;
	case 4393ULL: goto x86_l_1129;
	case 4396ULL: goto x86_l_112c;
	case 4398ULL: goto x86_l_112e;
	case 4401ULL: goto x86_l_1131;
	case 4407ULL: goto x86_l_1137;
	case 4410ULL: goto x86_l_113a;
	case 4415ULL: goto x86_l_113f;
	case 4417ULL: goto x86_l_1141;
	case 4421ULL: goto x86_l_1145;
	case 4426ULL: goto x86_l_114a;
	case 4434ULL: goto x86_l_1152;
	case 4436ULL: goto x86_l_1154;
	case 4441ULL: goto x86_l_1159;
	case 4443ULL: goto x86_l_115b;
	case 4445ULL: goto x86_l_115d;
	case 4451ULL: goto x86_l_1163;
	case 4455ULL: goto x86_l_1167;
	case 4460ULL: goto x86_l_116c;
	case 4468ULL: goto x86_l_1174;
	case 4474ULL: goto x86_l_117a;
	case 4479ULL: goto x86_l_117f;
	case 4487ULL: goto x86_l_1187;
	case 4493ULL: goto x86_l_118d;
	case 4496ULL: goto x86_l_1190;
	case 4502ULL: goto x86_l_1196;
	case 4507ULL: goto x86_l_119b;
	case 4513ULL: goto x86_l_11a1;
	case 4518ULL: goto x86_l_11a6;
	case 4524ULL: goto x86_l_11ac;
	case 4529ULL: goto x86_l_11b1;
	case 4533ULL: goto x86_l_11b5;
	case 4538ULL: goto x86_l_11ba;
	case 4540ULL: goto x86_l_11bc;
	case 4544ULL: goto x86_l_11c0;
	case 4549ULL: goto x86_l_11c5;
	case 4555ULL: goto x86_l_11cb;
	case 4559ULL: goto x86_l_11cf;
	case 4564ULL: goto x86_l_11d4;
	case 4569ULL: goto x86_l_11d9;
	case 4575ULL: goto x86_l_11df;
	case 4579ULL: goto x86_l_11e3;
	case 4584ULL: goto x86_l_11e8;
	case 4590ULL: goto x86_l_11ee;
	case 4594ULL: goto x86_l_11f2;
	case 4599ULL: goto x86_l_11f7;
	case 4605ULL: goto x86_l_11fd;
	case 4607ULL: goto x86_l_11ff;
	case 4614ULL: goto x86_l_1206;
	case 4615ULL: goto x86_l_1207;
	case 4617ULL: goto x86_l_1209;
	case 4619ULL: goto x86_l_120b;
	case 4621ULL: goto x86_l_120d;
	case 4623ULL: goto x86_l_120f;
	case 4624ULL: goto x86_l_1210;
	case 4629ULL: goto x86_l_1215;
	case 4631ULL: goto x86_l_1217;
	case 4637ULL: goto x86_l_121d;
	case 4645ULL: goto x86_l_1225;
	case 4647ULL: goto x86_l_1227;
	case 4650ULL: goto x86_l_122a;
	case 4656ULL: goto x86_l_1230;
	case 4659ULL: goto x86_l_1233;
	case 4665ULL: goto x86_l_1239;
	case 4668ULL: goto x86_l_123c;
	case 4674ULL: goto x86_l_1242;
	case 4681ULL: goto x86_l_1249;
	case 4687ULL: goto x86_l_124f;
	case 4690ULL: goto x86_l_1252;
	case 4695ULL: goto x86_l_1257;
	case 4700ULL: goto x86_l_125c;
	case 4705ULL: goto x86_l_1261;
	case 4710ULL: goto x86_l_1266;
	case 4712ULL: goto x86_l_1268;
	case 4714ULL: goto x86_l_126a;
	case 4720ULL: goto x86_l_1270;
	case 4722ULL: goto x86_l_1272;
	case 4727ULL: goto x86_l_1277;
	case 4729ULL: goto x86_l_1279;
	case 4735ULL: goto x86_l_127f;
	case 4743ULL: goto x86_l_1287;
	case 4745ULL: goto x86_l_1289;
	case 4748ULL: goto x86_l_128c;
	case 4754ULL: goto x86_l_1292;
	case 4757ULL: goto x86_l_1295;
	case 4763ULL: goto x86_l_129b;
	case 4766ULL: goto x86_l_129e;
	case 4772ULL: goto x86_l_12a4;
	case 4779ULL: goto x86_l_12ab;
	case 4785ULL: goto x86_l_12b1;
	case 4788ULL: goto x86_l_12b4;
	case 4793ULL: goto x86_l_12b9;
	case 4798ULL: goto x86_l_12be;
	case 4803ULL: goto x86_l_12c3;
	case 4808ULL: goto x86_l_12c8;
	case 4810ULL: goto x86_l_12ca;
	case 4812ULL: goto x86_l_12cc;
	case 4818ULL: goto x86_l_12d2;
	case 4820ULL: goto x86_l_12d4;
	case 4825ULL: goto x86_l_12d9;
	case 4827ULL: goto x86_l_12db;
	case 4833ULL: goto x86_l_12e1;
	case 4841ULL: goto x86_l_12e9;
	case 4843ULL: goto x86_l_12eb;
	case 4846ULL: goto x86_l_12ee;
	case 4852ULL: goto x86_l_12f4;
	case 4855ULL: goto x86_l_12f7;
	case 4860ULL: goto x86_l_12fc;
	case 4866ULL: goto x86_l_1302;
	case 4869ULL: goto x86_l_1305;
	case 4875ULL: goto x86_l_130b;
	case 4882ULL: goto x86_l_1312;
	case 4888ULL: goto x86_l_1318;
	case 4891ULL: goto x86_l_131b;
	case 4896ULL: goto x86_l_1320;
	case 4901ULL: goto x86_l_1325;
	case 4906ULL: goto x86_l_132a;
	case 4911ULL: goto x86_l_132f;
	case 4913ULL: goto x86_l_1331;
	case 4915ULL: goto x86_l_1333;
	case 4921ULL: goto x86_l_1339;
	case 4923ULL: goto x86_l_133b;
	case 4928ULL: goto x86_l_1340;
	case 4930ULL: goto x86_l_1342;
	case 4936ULL: goto x86_l_1348;
	case 4944ULL: goto x86_l_1350;
	case 4946ULL: goto x86_l_1352;
	case 4949ULL: goto x86_l_1355;
	case 4954ULL: goto x86_l_135a;
	case 4960ULL: goto x86_l_1360;
	case 4963ULL: goto x86_l_1363;
	case 4969ULL: goto x86_l_1369;
	case 4972ULL: goto x86_l_136c;
	case 4978ULL: goto x86_l_1372;
	case 4985ULL: goto x86_l_1379;
	case 4991ULL: goto x86_l_137f;
	case 4994ULL: goto x86_l_1382;
	case 4999ULL: goto x86_l_1387;
	case 5004ULL: goto x86_l_138c;
	case 5009ULL: goto x86_l_1391;
	case 5014ULL: goto x86_l_1396;
	case 5016ULL: goto x86_l_1398;
	case 5018ULL: goto x86_l_139a;
	case 5024ULL: goto x86_l_13a0;
	case 5026ULL: goto x86_l_13a2;
	case 5031ULL: goto x86_l_13a7;
	case 5033ULL: goto x86_l_13a9;
	case 5039ULL: goto x86_l_13af;
	case 5047ULL: goto x86_l_13b7;
	case 5049ULL: goto x86_l_13b9;
	case 5052ULL: goto x86_l_13bc;
	case 5058ULL: goto x86_l_13c2;
	case 5061ULL: goto x86_l_13c5;
	case 5066ULL: goto x86_l_13ca;
	case 5072ULL: goto x86_l_13d0;
	case 5075ULL: goto x86_l_13d3;
	case 5081ULL: goto x86_l_13d9;
	case 5088ULL: goto x86_l_13e0;
	case 5093ULL: goto x86_l_13e5;
	case 5096ULL: goto x86_l_13e8;
	case 5101ULL: goto x86_l_13ed;
	case 5106ULL: goto x86_l_13f2;
	case 5111ULL: goto x86_l_13f7;
	case 5116ULL: goto x86_l_13fc;
	case 5118ULL: goto x86_l_13fe;
	case 5120ULL: goto x86_l_1400;
	case 5126ULL: goto x86_l_1406;
	case 5128ULL: goto x86_l_1408;
	case 5133ULL: goto x86_l_140d;
	case 5141ULL: goto x86_l_1415;
	case 5149ULL: goto x86_l_141d;
	case 5155ULL: goto x86_l_1423;
	case 5157ULL: goto x86_l_1425;
	case 5160ULL: goto x86_l_1428;
	case 5166ULL: goto x86_l_142e;
	case 5169ULL: goto x86_l_1431;
	case 5175ULL: goto x86_l_1437;
	case 5178ULL: goto x86_l_143a;
	case 5184ULL: goto x86_l_1440;
	case 5192ULL: goto x86_l_1448;
	case 5195ULL: goto x86_l_144b;
	case 5201ULL: goto x86_l_1451;
	case 5206ULL: goto x86_l_1456;
	case 5209ULL: goto x86_l_1459;
	case 5215ULL: goto x86_l_145f;
	case 5218ULL: goto x86_l_1462;
	case 5224ULL: goto x86_l_1468;
	case 5229ULL: goto x86_l_146d;
	case 5234ULL: goto x86_l_1472;
	case 5242ULL: goto x86_l_147a;
	case 5250ULL: goto x86_l_1482;
	case 5256ULL: goto x86_l_1488;
	case 5258ULL: goto x86_l_148a;
	case 5261ULL: goto x86_l_148d;
	case 5267ULL: goto x86_l_1493;
	case 5270ULL: goto x86_l_1496;
	case 5276ULL: goto x86_l_149c;
	case 5279ULL: goto x86_l_149f;
	case 5285ULL: goto x86_l_14a5;
	case 5293ULL: goto x86_l_14ad;
	case 5296ULL: goto x86_l_14b0;
	case 5302ULL: goto x86_l_14b6;
	case 5307ULL: goto x86_l_14bb;
	case 5310ULL: goto x86_l_14be;
	case 5316ULL: goto x86_l_14c4;
	case 5321ULL: goto x86_l_14c9;
	case 5324ULL: goto x86_l_14cc;
	default: return 0xffffffffffffffffULL;
	}
x86_l_df2:
	/* 0xdf2: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_df7:
	/* 0xdf7: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dfc:
	/* 0xdfc: cmp    WORD PTR [r13+r15*1-0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743927680663552ULL);
x86_l_e03:
	/* 0xe03: je     e28 <generic_sleepable_preload+0xe28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e28;
	}
x86_l_e05:
	/* 0xe05: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_e0a:
	/* 0xe0a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_e0f:
	/* 0xe0f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e14:
	/* 0xe14: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e19:
	/* 0xe19: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e1e:
	/* 0xe1e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e20:
	/* 0xe20: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e22:
	/* 0xe22: js     fb6 <generic_sleepable_preload+0xfb6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_fb6;
	}
x86_l_e28:
	/* 0xe28: cmp    WORD PTR [r13+r15*1-0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743970630336512ULL);
x86_l_e2f:
	/* 0xe2f: je     10b8 <generic_sleepable_preload+0x10b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10b8;
	}
x86_l_e35:
	/* 0xe35: mov    ecx,DWORD PTR [r13+r15*1-0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551586ULL);
x86_l_e3a:
	/* 0xe3a: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_e3f:
	/* 0xe3f: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e44:
	/* 0xe44: cmp    WORD PTR [r13+r15*1-0x1a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743962040401920ULL);
x86_l_e4b:
	/* 0xe4b: je     e70 <generic_sleepable_preload+0xe70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e70;
	}
x86_l_e4d:
	/* 0xe4d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_e52:
	/* 0xe52: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_e57:
	/* 0xe57: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e5c:
	/* 0xe5c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e61:
	/* 0xe61: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e66:
	/* 0xe66: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e68:
	/* 0xe68: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e6a:
	/* 0xe6a: js     10aa <generic_sleepable_preload+0x10aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_10aa;
	}
x86_l_e70:
	/* 0xe70: cmp    WORD PTR [r13+r15*1-0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744004990074880ULL);
x86_l_e77:
	/* 0xe77: je     10b8 <generic_sleepable_preload+0x10b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10b8;
	}
x86_l_e7d:
	/* 0xe7d: mov    ecx,DWORD PTR [r13+r15*1-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551594ULL);
x86_l_e82:
	/* 0xe82: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_e87:
	/* 0xe87: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e8c:
	/* 0xe8c: cmp    WORD PTR [r13+r15*1-0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743996400140288ULL);
x86_l_e93:
	/* 0xe93: je     eb8 <generic_sleepable_preload+0xeb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_eb8;
	}
x86_l_e95:
	/* 0xe95: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_e9a:
	/* 0xe9a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_e9f:
	/* 0xe9f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ea4:
	/* 0xea4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ea9:
	/* 0xea9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_eae:
	/* 0xeae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_eb0:
	/* 0xeb0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_eb2:
	/* 0xeb2: js     117f <generic_sleepable_preload+0x117f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_117f;
	}
x86_l_eb8:
	/* 0xeb8: cmp    WORD PTR [r13+r15*1-0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744039349813248ULL);
x86_l_ebf:
	/* 0xebf: je     10b8 <generic_sleepable_preload+0x10b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10b8;
	}
x86_l_ec5:
	/* 0xec5: mov    ecx,DWORD PTR [r13+r15*1-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551602ULL);
x86_l_eca:
	/* 0xeca: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_ecf:
	/* 0xecf: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ed4:
	/* 0xed4: cmp    WORD PTR [r13+r15*1-0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744030759878656ULL);
x86_l_edb:
	/* 0xedb: je     f00 <generic_sleepable_preload+0xf00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f00;
	}
x86_l_edd:
	/* 0xedd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_ee2:
	/* 0xee2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_ee7:
	/* 0xee7: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_eec:
	/* 0xeec: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ef1:
	/* 0xef1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ef6:
	/* 0xef6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ef8:
	/* 0xef8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_efa:
	/* 0xefa: js     11a6 <generic_sleepable_preload+0x11a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_11a6;
	}
x86_l_f00:
	/* 0xf00: cmp    WORD PTR [r13+r15*1+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_f07:
	/* 0xf07: je     10b8 <generic_sleepable_preload+0x10b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10b8;
	}
x86_l_f0d:
	/* 0xf0d: mov    ecx,DWORD PTR [r13+r15*1-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551610ULL);
x86_l_f12:
	/* 0xf12: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_f17:
	/* 0xf17: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f1c:
	/* 0xf1c: cmp    WORD PTR [r13+r15*1-0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744065119617024ULL);
x86_l_f23:
	/* 0xf23: je     10b8 <generic_sleepable_preload+0x10b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10b8;
	}
x86_l_f29:
	/* 0xf29: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_f2e:
	/* 0xf2e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_f33:
	/* 0xf33: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f38:
	/* 0xf38: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f3d:
	/* 0xf3d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f42:
	/* 0xf42: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f44:
	/* 0xf44: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f46:
	/* 0xf46: jns    10b8 <generic_sleepable_preload+0x10b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_10b8;
	}
x86_l_f4c:
	/* 0xf4c: mov    r12d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 10ULL);
x86_l_f52:
	/* 0xf52: jmp    10b0 <generic_sleepable_preload+0x10b0> */
	goto x86_l_10b0;
x86_l_f57:
	/* 0xf57: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_f5d:
	/* 0xf5d: jmp    10b0 <generic_sleepable_preload+0x10b0> */
	goto x86_l_10b0;
x86_l_f62:
	/* 0xf62: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_f68:
	/* 0xf68: jmp    fc7 <generic_sleepable_preload+0xfc7> */
	goto x86_l_fc7;
x86_l_f6a:
	/* 0xf6a: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_f70:
	/* 0xf70: jmp    10b0 <generic_sleepable_preload+0x10b0> */
	goto x86_l_10b0;
x86_l_f75:
	/* 0xf75: mov    r12d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 3ULL);
x86_l_f7b:
	/* 0xf7b: jmp    fc7 <generic_sleepable_preload+0xfc7> */
	goto x86_l_fc7;
x86_l_f7d:
	/* 0xf7d: mov    r12d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 3ULL);
x86_l_f83:
	/* 0xf83: jmp    10b0 <generic_sleepable_preload+0x10b0> */
	goto x86_l_10b0;
x86_l_f88:
	/* 0xf88: mov    r12d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4ULL);
x86_l_f8e:
	/* 0xf8e: jmp    fc7 <generic_sleepable_preload+0xfc7> */
	goto x86_l_fc7;
x86_l_f90:
	/* 0xf90: mov    r12d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4ULL);
x86_l_f96:
	/* 0xf96: jmp    10b0 <generic_sleepable_preload+0x10b0> */
	goto x86_l_10b0;
x86_l_f9b:
	/* 0xf9b: mov    r12d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 5ULL);
x86_l_fa1:
	/* 0xfa1: jmp    fc7 <generic_sleepable_preload+0xfc7> */
	goto x86_l_fc7;
x86_l_fa3:
	/* 0xfa3: mov    r12d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 5ULL);
x86_l_fa9:
	/* 0xfa9: jmp    10b0 <generic_sleepable_preload+0x10b0> */
	goto x86_l_10b0;
x86_l_fae:
	/* 0xfae: mov    r12d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 6ULL);
x86_l_fb4:
	/* 0xfb4: jmp    fc7 <generic_sleepable_preload+0xfc7> */
	goto x86_l_fc7;
x86_l_fb6:
	/* 0xfb6: mov    r12d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 6ULL);
x86_l_fbc:
	/* 0xfbc: jmp    10b0 <generic_sleepable_preload+0x10b0> */
	goto x86_l_10b0;
x86_l_fc1:
	/* 0xfc1: mov    r12d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 7ULL);
x86_l_fc7:
	/* 0xfc7: mov    DWORD PTR [rsp+0x24],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_fcf:
	/* 0xfcf: mov    r13d,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fd2:
	/* 0xfd2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_fd7:
	/* 0xfd7: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fdc:
	/* 0xfdc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_fe1:
	/* 0xfe1: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_fe4:
	/* 0xfe4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fe6:
	/* 0xfe6: cmp    r13d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 6ULL);
x86_l_fea:
	/* 0xfea: jne    129 <generic_sleepable_preload+0x129> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 297ULL;
	}
x86_l_ff0:
	/* 0xff0: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ff5:
	/* 0xff5: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_ffd:
	/* 0xffd: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1002:
	/* 0x1002: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1004:
	/* 0x1004: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1009:
	/* 0x1009: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1011:
	/* 0x1011: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1016:
	/* 0x1016: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_101d:
	/* 0x101d: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1022:
	/* 0x1022: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1024:
	/* 0x1024: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1027:
	/* 0x1027: je     129 <generic_sleepable_preload+0x129> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 297ULL;
	}
x86_l_102d:
	/* 0x102d: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1030:
	/* 0x1030: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1035:
	/* 0x1035: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1037:
	/* 0x1037: lea    rbp,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_103c:
	/* 0x103c: mov    r13d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_32);
x86_l_103f:
	/* 0x103f: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_1046:
	/* 0x1046: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1049:
	/* 0x1049: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_104c:
	/* 0x104c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_104e:
	/* 0x104e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1050:
	/* 0x1050: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1055:
	/* 0x1055: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1058:
	/* 0x1058: mov    r12d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R13, X86_WIDTH_32);
x86_l_105b:
	/* 0x105b: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_105e:
	/* 0x105e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1060:
	/* 0x1060: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1063:
	/* 0x1063: je     129 <generic_sleepable_preload+0x129> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 297ULL;
	}
x86_l_1069:
	/* 0x1069: cmp    BYTE PTR [rsp+0x24],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_106e:
	/* 0x106e: je     126 <generic_sleepable_preload+0x126> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 294ULL;
	}
x86_l_1074:
	/* 0x1074: lea    rdi,[rax+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1078:
	/* 0x1078: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_107d:
	/* 0x107d: mov    rdx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1085:
	/* 0x1085: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1087:
	/* 0x1087: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_108a:
	/* 0x108a: call   108f <generic_sleepable_preload+0x108f> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_108f:
	/* 0x108f: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1091:
	/* 0x1091: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_1094:
	/* 0x1094: mov    r12d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R13, X86_WIDTH_32);
x86_l_1097:
	/* 0x1097: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1099:
	/* 0x1099: jns    126 <generic_sleepable_preload+0x126> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 294ULL;
	}
x86_l_109f:
	/* 0x109f: mov    r12d,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967295ULL);
x86_l_10a5:
	/* 0x10a5: jmp    126 <generic_sleepable_preload+0x126> */
	return 294ULL;
x86_l_10aa:
	/* 0x10aa: mov    r12d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 7ULL);
x86_l_10b0:
	/* 0x10b0: mov    DWORD PTR [rsp+0x24],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_10b8:
	/* 0x10b8: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_10bb:
	/* 0x10bb: jne    12e <generic_sleepable_preload+0x12e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 302ULL;
	}
x86_l_10c1:
	/* 0x10c1: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10c6:
	/* 0x10c6: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_10ce:
	/* 0x10ce: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_10d3:
	/* 0x10d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10d5:
	/* 0x10d5: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_10da:
	/* 0x10da: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_10e2:
	/* 0x10e2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10e7:
	/* 0x10e7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_10ee:
	/* 0x10ee: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10f3:
	/* 0x10f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10f5:
	/* 0x10f5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10f8:
	/* 0x10f8: je     129 <generic_sleepable_preload+0x129> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 297ULL;
	}
x86_l_10fe:
	/* 0x10fe: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1101:
	/* 0x1101: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1106:
	/* 0x1106: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1108:
	/* 0x1108: lea    rbp,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_110d:
	/* 0x110d: mov    r13d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_32);
x86_l_1110:
	/* 0x1110: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_1117:
	/* 0x1117: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_111a:
	/* 0x111a: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_111d:
	/* 0x111d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_111f:
	/* 0x111f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1121:
	/* 0x1121: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1126:
	/* 0x1126: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1129:
	/* 0x1129: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_112c:
	/* 0x112c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_112e:
	/* 0x112e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1131:
	/* 0x1131: je     129 <generic_sleepable_preload+0x129> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 297ULL;
	}
x86_l_1137:
	/* 0x1137: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_113a:
	/* 0x113a: cmp    BYTE PTR [rsp+0x24],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_113f:
	/* 0x113f: je     1163 <generic_sleepable_preload+0x1163> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1163;
	}
x86_l_1141:
	/* 0x1141: lea    rdi,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1145:
	/* 0x1145: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_114a:
	/* 0x114a: mov    rdx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1152:
	/* 0x1152: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1154:
	/* 0x1154: call   1159 <generic_sleepable_preload+0x1159> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_1159:
	/* 0x1159: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_115b:
	/* 0x115b: jns    1163 <generic_sleepable_preload+0x1163> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_1163;
	}
x86_l_115d:
	/* 0x115d: mov    r13d,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967295ULL);
x86_l_1163:
	/* 0x1163: mov    DWORD PTR [rbp+0x0],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1167:
	/* 0x1167: jmp    129 <generic_sleepable_preload+0x129> */
	return 297ULL;
x86_l_116c:
	/* 0x116c: mov    DWORD PTR [rsp+0x24],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_1174:
	/* 0x1174: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_117a:
	/* 0x117a: jmp    fcf <generic_sleepable_preload+0xfcf> */
	goto x86_l_fcf;
x86_l_117f:
	/* 0x117f: mov    DWORD PTR [rsp+0x24],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_1187:
	/* 0x1187: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_118d:
	/* 0x118d: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_1190:
	/* 0x1190: jne    12e <generic_sleepable_preload+0x12e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 302ULL;
	}
x86_l_1196:
	/* 0x1196: jmp    10c1 <generic_sleepable_preload+0x10c1> */
	goto x86_l_10c1;
x86_l_119b:
	/* 0x119b: mov    r12d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 9ULL);
x86_l_11a1:
	/* 0x11a1: jmp    fc7 <generic_sleepable_preload+0xfc7> */
	goto x86_l_fc7;
x86_l_11a6:
	/* 0x11a6: mov    r12d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 9ULL);
x86_l_11ac:
	/* 0x11ac: jmp    10b0 <generic_sleepable_preload+0x10b0> */
	goto x86_l_10b0;
x86_l_11b1:
	/* 0x11b1: mov    eax,DWORD PTR [r13+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11b5:
	/* 0x11b5: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_11ba:
	/* 0x11ba: jne    1215 <generic_sleepable_preload+0x1215> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1215;
	}
x86_l_11bc:
	/* 0x11bc: mov    eax,DWORD PTR [r13+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_11c0:
	/* 0x11c0: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_11c5:
	/* 0x11c5: jne    1277 <generic_sleepable_preload+0x1277> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1277;
	}
x86_l_11cb:
	/* 0x11cb: mov    eax,DWORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11cf:
	/* 0x11cf: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_11d4:
	/* 0x11d4: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_11d9:
	/* 0x11d9: jne    12d9 <generic_sleepable_preload+0x12d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_12d9;
	}
x86_l_11df:
	/* 0x11df: mov    eax,DWORD PTR [r13+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_11e3:
	/* 0x11e3: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_11e8:
	/* 0x11e8: jne    1340 <generic_sleepable_preload+0x1340> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1340;
	}
x86_l_11ee:
	/* 0x11ee: mov    eax,DWORD PTR [r13+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_11f2:
	/* 0x11f2: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_11f7:
	/* 0x11f7: jne    13a7 <generic_sleepable_preload+0x13a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_13a7;
	}
x86_l_11fd:
	/* 0x11fd: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11ff:
	/* 0x11ff: add    rsp,0xc8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 200ULL);
x86_l_1206:
	/* 0x1206: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1207:
	/* 0x1207: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1209:
	/* 0x1209: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_120b:
	/* 0x120b: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_120d:
	/* 0x120d: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_120f:
	/* 0x120f: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1210:
	/* 0x1210: jmp    6a7b <generic_sleepable_preload+0x6a7b> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1215:
	/* 0x1215: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1217:
	/* 0x1217: js     140d <generic_sleepable_preload+0x140d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_140d;
	}
x86_l_121d:
	/* 0x121d: movzx  eax,BYTE PTR [r13+0x211] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 529ULL);
x86_l_1225:
	/* 0x1225: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1227:
	/* 0x1227: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_122a:
	/* 0x122a: jg     1606 <generic_sleepable_preload+0x1606> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5638ULL;
	}
x86_l_1230:
	/* 0x1230: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1233:
	/* 0x1233: je     1b77 <generic_sleepable_preload+0x1b77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7031ULL;
	}
x86_l_1239:
	/* 0x1239: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_123c:
	/* 0x123c: jne    1cf2 <generic_sleepable_preload+0x1cf2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7410ULL;
	}
x86_l_1242:
	/* 0x1242: mov    edx,DWORD PTR [r13+0x208] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_1249:
	/* 0x1249: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_124f:
	/* 0x124f: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1252:
	/* 0x1252: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1257:
	/* 0x1257: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_125c:
	/* 0x125c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1261:
	/* 0x1261: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1266:
	/* 0x1266: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1268:
	/* 0x1268: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_126a:
	/* 0x126a: je     1b83 <generic_sleepable_preload+0x1b83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7043ULL;
	}
x86_l_1270:
	/* 0x1270: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1272:
	/* 0x1272: jmp    1cf2 <generic_sleepable_preload+0x1cf2> */
	return 7410ULL;
x86_l_1277:
	/* 0x1277: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1279:
	/* 0x1279: js     1472 <generic_sleepable_preload+0x1472> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1472;
	}
x86_l_127f:
	/* 0x127f: movzx  eax,BYTE PTR [r13+0x229] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 553ULL);
x86_l_1287:
	/* 0x1287: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1289:
	/* 0x1289: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_128c:
	/* 0x128c: jg     16d3 <generic_sleepable_preload+0x16d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5843ULL;
	}
x86_l_1292:
	/* 0x1292: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1295:
	/* 0x1295: je     1bb2 <generic_sleepable_preload+0x1bb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7090ULL;
	}
x86_l_129b:
	/* 0x129b: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_129e:
	/* 0x129e: jne    23bb <generic_sleepable_preload+0x23bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9147ULL;
	}
x86_l_12a4:
	/* 0x12a4: mov    edx,DWORD PTR [r13+0x220] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 544ULL);
x86_l_12ab:
	/* 0x12ab: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_12b1:
	/* 0x12b1: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_12b4:
	/* 0x12b4: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_12b9:
	/* 0x12b9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_12be:
	/* 0x12be: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_12c3:
	/* 0x12c3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12c8:
	/* 0x12c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12ca:
	/* 0x12ca: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_12cc:
	/* 0x12cc: je     1bbe <generic_sleepable_preload+0x1bbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7102ULL;
	}
x86_l_12d2:
	/* 0x12d2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12d4:
	/* 0x12d4: jmp    23bb <generic_sleepable_preload+0x23bb> */
	return 9147ULL;
x86_l_12d9:
	/* 0x12d9: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_12db:
	/* 0x12db: js     14d7 <generic_sleepable_preload+0x14d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 5335ULL;
	}
x86_l_12e1:
	/* 0x12e1: movzx  eax,BYTE PTR [r13+0x241] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 577ULL);
x86_l_12e9:
	/* 0x12e9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12eb:
	/* 0x12eb: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_12ee:
	/* 0x12ee: jg     174e <generic_sleepable_preload+0x174e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5966ULL;
	}
x86_l_12f4:
	/* 0x12f4: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12f7:
	/* 0x12f7: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12fc:
	/* 0x12fc: je     1bed <generic_sleepable_preload+0x1bed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7149ULL;
	}
x86_l_1302:
	/* 0x1302: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1305:
	/* 0x1305: jne    2a90 <generic_sleepable_preload+0x2a90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10896ULL;
	}
x86_l_130b:
	/* 0x130b: mov    edx,DWORD PTR [r13+0x238] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 568ULL);
x86_l_1312:
	/* 0x1312: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1318:
	/* 0x1318: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_131b:
	/* 0x131b: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1320:
	/* 0x1320: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1325:
	/* 0x1325: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_132a:
	/* 0x132a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_132f:
	/* 0x132f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1331:
	/* 0x1331: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1333:
	/* 0x1333: je     1bf9 <generic_sleepable_preload+0x1bf9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7161ULL;
	}
x86_l_1339:
	/* 0x1339: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_133b:
	/* 0x133b: jmp    2a90 <generic_sleepable_preload+0x2a90> */
	return 10896ULL;
x86_l_1340:
	/* 0x1340: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1342:
	/* 0x1342: js     153c <generic_sleepable_preload+0x153c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 5436ULL;
	}
x86_l_1348:
	/* 0x1348: movzx  eax,BYTE PTR [r13+0x259] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 601ULL);
x86_l_1350:
	/* 0x1350: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1352:
	/* 0x1352: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1355:
	/* 0x1355: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_135a:
	/* 0x135a: jg     17ce <generic_sleepable_preload+0x17ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6094ULL;
	}
x86_l_1360:
	/* 0x1360: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1363:
	/* 0x1363: je     1c23 <generic_sleepable_preload+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7203ULL;
	}
x86_l_1369:
	/* 0x1369: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_136c:
	/* 0x136c: jne    3174 <generic_sleepable_preload+0x3174> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12660ULL;
	}
x86_l_1372:
	/* 0x1372: mov    edx,DWORD PTR [r13+0x250] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 592ULL);
x86_l_1379:
	/* 0x1379: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_137f:
	/* 0x137f: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1382:
	/* 0x1382: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1387:
	/* 0x1387: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_138c:
	/* 0x138c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
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
	/* 0x139a: je     1c2f <generic_sleepable_preload+0x1c2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7215ULL;
	}
x86_l_13a0:
	/* 0x13a0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13a2:
	/* 0x13a2: jmp    3174 <generic_sleepable_preload+0x3174> */
	return 12660ULL;
x86_l_13a7:
	/* 0x13a7: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_13a9:
	/* 0x13a9: js     15a1 <generic_sleepable_preload+0x15a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 5537ULL;
	}
x86_l_13af:
	/* 0x13af: movzx  eax,BYTE PTR [r13+0x271] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 625ULL);
x86_l_13b7:
	/* 0x13b7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13b9:
	/* 0x13b9: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_13bc:
	/* 0x13bc: jg     1849 <generic_sleepable_preload+0x1849> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6217ULL;
	}
x86_l_13c2:
	/* 0x13c2: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13c5:
	/* 0x13c5: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_13ca:
	/* 0x13ca: je     1c59 <generic_sleepable_preload+0x1c59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7257ULL;
	}
x86_l_13d0:
	/* 0x13d0: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_13d3:
	/* 0x13d3: jne    384b <generic_sleepable_preload+0x384b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14411ULL;
	}
x86_l_13d9:
	/* 0x13d9: mov    eax,DWORD PTR [r13+0x268] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 616ULL);
x86_l_13e0:
	/* 0x13e0: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_13e5:
	/* 0x13e5: add    rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_13e8:
	/* 0x13e8: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_13ed:
	/* 0x13ed: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_13f2:
	/* 0x13f2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_13f7:
	/* 0x13f7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_13fc:
	/* 0x13fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13fe:
	/* 0x13fe: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1400:
	/* 0x1400: je     1c65 <generic_sleepable_preload+0x1c65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7269ULL;
	}
x86_l_1406:
	/* 0x1406: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1408:
	/* 0x1408: jmp    384b <generic_sleepable_preload+0x384b> */
	return 14411ULL;
x86_l_140d:
	/* 0x140d: movzx  eax,BYTE PTR [r13+0x2c2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 706ULL);
x86_l_1415:
	/* 0x1415: movzx  ecx,WORD PTR [r13+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 704ULL);
x86_l_141d:
	/* 0x141d: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_1423:
	/* 0x1423: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1425:
	/* 0x1425: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_1428:
	/* 0x1428: jle    18cb <generic_sleepable_preload+0x18cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 6347ULL;
	}
x86_l_142e:
	/* 0x142e: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_1431:
	/* 0x1431: jle    19b5 <generic_sleepable_preload+0x19b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 6581ULL;
	}
x86_l_1437:
	/* 0x1437: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_143a:
	/* 0x143a: jle    40b9 <generic_sleepable_preload+0x40b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 16569ULL;
	}
x86_l_1440:
	/* 0x1440: mov    rsi,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1448:
	/* 0x1448: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_144b:
	/* 0x144b: je     40d0 <generic_sleepable_preload+0x40d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16592ULL;
	}
x86_l_1451:
	/* 0x1451: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1456:
	/* 0x1456: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_1459:
	/* 0x1459: je     40d0 <generic_sleepable_preload+0x40d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16592ULL;
	}
x86_l_145f:
	/* 0x145f: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_1462:
	/* 0x1462: jne    40e3 <generic_sleepable_preload+0x40e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 16611ULL;
	}
x86_l_1468:
	/* 0x1468: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_146d:
	/* 0x146d: jmp    40d0 <generic_sleepable_preload+0x40d0> */
	return 16592ULL;
x86_l_1472:
	/* 0x1472: movzx  eax,BYTE PTR [r13+0x2c6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 710ULL);
x86_l_147a:
	/* 0x147a: movzx  ecx,WORD PTR [r13+0x2c4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 708ULL);
x86_l_1482:
	/* 0x1482: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_1488:
	/* 0x1488: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_148a:
	/* 0x148a: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_148d:
	/* 0x148d: jle    18fb <generic_sleepable_preload+0x18fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 6395ULL;
	}
x86_l_1493:
	/* 0x1493: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_1496:
	/* 0x1496: jle    19e2 <generic_sleepable_preload+0x19e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 6626ULL;
	}
x86_l_149c:
	/* 0x149c: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_149f:
	/* 0x149f: jle    4705 <generic_sleepable_preload+0x4705> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 18181ULL;
	}
x86_l_14a5:
	/* 0x14a5: mov    rsi,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_14ad:
	/* 0x14ad: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_14b0:
	/* 0x14b0: je     545f <generic_sleepable_preload+0x545f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21599ULL;
	}
x86_l_14b6:
	/* 0x14b6: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_14bb:
	/* 0x14bb: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_14be:
	/* 0x14be: je     545f <generic_sleepable_preload+0x545f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21599ULL;
	}
x86_l_14c4:
	/* 0x14c4: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_14c9:
	/* 0x14c9: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_14cc:
	/* 0x14cc: je     545f <generic_sleepable_preload+0x545f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21599ULL;
	}
	return 5330ULL;
}

static __noinline __u64 tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5330ULL: goto x86_l_14d2;
	case 5335ULL: goto x86_l_14d7;
	case 5343ULL: goto x86_l_14df;
	case 5351ULL: goto x86_l_14e7;
	case 5357ULL: goto x86_l_14ed;
	case 5359ULL: goto x86_l_14ef;
	case 5362ULL: goto x86_l_14f2;
	case 5368ULL: goto x86_l_14f8;
	case 5371ULL: goto x86_l_14fb;
	case 5377ULL: goto x86_l_1501;
	case 5380ULL: goto x86_l_1504;
	case 5386ULL: goto x86_l_150a;
	case 5394ULL: goto x86_l_1512;
	case 5397ULL: goto x86_l_1515;
	case 5403ULL: goto x86_l_151b;
	case 5408ULL: goto x86_l_1520;
	case 5411ULL: goto x86_l_1523;
	case 5417ULL: goto x86_l_1529;
	case 5422ULL: goto x86_l_152e;
	case 5425ULL: goto x86_l_1531;
	case 5431ULL: goto x86_l_1537;
	case 5436ULL: goto x86_l_153c;
	case 5444ULL: goto x86_l_1544;
	case 5452ULL: goto x86_l_154c;
	case 5458ULL: goto x86_l_1552;
	case 5460ULL: goto x86_l_1554;
	case 5463ULL: goto x86_l_1557;
	case 5469ULL: goto x86_l_155d;
	case 5472ULL: goto x86_l_1560;
	case 5478ULL: goto x86_l_1566;
	case 5481ULL: goto x86_l_1569;
	case 5487ULL: goto x86_l_156f;
	case 5495ULL: goto x86_l_1577;
	case 5498ULL: goto x86_l_157a;
	case 5504ULL: goto x86_l_1580;
	case 5509ULL: goto x86_l_1585;
	case 5512ULL: goto x86_l_1588;
	case 5518ULL: goto x86_l_158e;
	case 5523ULL: goto x86_l_1593;
	case 5526ULL: goto x86_l_1596;
	case 5532ULL: goto x86_l_159c;
	case 5537ULL: goto x86_l_15a1;
	case 5545ULL: goto x86_l_15a9;
	case 5553ULL: goto x86_l_15b1;
	case 5559ULL: goto x86_l_15b7;
	case 5561ULL: goto x86_l_15b9;
	case 5564ULL: goto x86_l_15bc;
	case 5570ULL: goto x86_l_15c2;
	case 5573ULL: goto x86_l_15c5;
	case 5579ULL: goto x86_l_15cb;
	case 5582ULL: goto x86_l_15ce;
	case 5588ULL: goto x86_l_15d4;
	case 5596ULL: goto x86_l_15dc;
	case 5599ULL: goto x86_l_15df;
	case 5605ULL: goto x86_l_15e5;
	case 5610ULL: goto x86_l_15ea;
	case 5613ULL: goto x86_l_15ed;
	case 5619ULL: goto x86_l_15f3;
	case 5624ULL: goto x86_l_15f8;
	case 5627ULL: goto x86_l_15fb;
	case 5633ULL: goto x86_l_1601;
	case 5638ULL: goto x86_l_1606;
	case 5641ULL: goto x86_l_1609;
	case 5647ULL: goto x86_l_160f;
	case 5650ULL: goto x86_l_1612;
	case 5656ULL: goto x86_l_1618;
	case 5663ULL: goto x86_l_161f;
	case 5669ULL: goto x86_l_1625;
	case 5672ULL: goto x86_l_1628;
	case 5677ULL: goto x86_l_162d;
	case 5682ULL: goto x86_l_1632;
	case 5687ULL: goto x86_l_1637;
	case 5692ULL: goto x86_l_163c;
	case 5694ULL: goto x86_l_163e;
	case 5696ULL: goto x86_l_1640;
	case 5702ULL: goto x86_l_1646;
	case 5709ULL: goto x86_l_164d;
	case 5715ULL: goto x86_l_1653;
	case 5718ULL: goto x86_l_1656;
	case 5723ULL: goto x86_l_165b;
	case 5728ULL: goto x86_l_1660;
	case 5733ULL: goto x86_l_1665;
	case 5738ULL: goto x86_l_166a;
	case 5740ULL: goto x86_l_166c;
	case 5742ULL: goto x86_l_166e;
	case 5748ULL: goto x86_l_1674;
	case 5756ULL: goto x86_l_167c;
	case 5763ULL: goto x86_l_1683;
	case 5770ULL: goto x86_l_168a;
	case 5775ULL: goto x86_l_168f;
	case 5778ULL: goto x86_l_1692;
	case 5783ULL: goto x86_l_1697;
	case 5788ULL: goto x86_l_169c;
	case 5793ULL: goto x86_l_16a1;
	case 5801ULL: goto x86_l_16a9;
	case 5808ULL: goto x86_l_16b0;
	case 5815ULL: goto x86_l_16b7;
	case 5820ULL: goto x86_l_16bc;
	case 5823ULL: goto x86_l_16bf;
	case 5828ULL: goto x86_l_16c4;
	case 5830ULL: goto x86_l_16c6;
	case 5832ULL: goto x86_l_16c8;
	case 5838ULL: goto x86_l_16ce;
	case 5843ULL: goto x86_l_16d3;
	case 5846ULL: goto x86_l_16d6;
	case 5852ULL: goto x86_l_16dc;
	case 5855ULL: goto x86_l_16df;
	case 5861ULL: goto x86_l_16e5;
	case 5868ULL: goto x86_l_16ec;
	case 5874ULL: goto x86_l_16f2;
	case 5877ULL: goto x86_l_16f5;
	case 5882ULL: goto x86_l_16fa;
	case 5887ULL: goto x86_l_16ff;
	case 5892ULL: goto x86_l_1704;
	case 5897ULL: goto x86_l_1709;
	case 5899ULL: goto x86_l_170b;
	case 5901ULL: goto x86_l_170d;
	case 5907ULL: goto x86_l_1713;
	case 5912ULL: goto x86_l_1718;
	case 5919ULL: goto x86_l_171f;
	case 5924ULL: goto x86_l_1724;
	case 5929ULL: goto x86_l_1729;
	case 5934ULL: goto x86_l_172e;
	case 5939ULL: goto x86_l_1733;
	case 5946ULL: goto x86_l_173a;
	case 5951ULL: goto x86_l_173f;
	case 5953ULL: goto x86_l_1741;
	case 5955ULL: goto x86_l_1743;
	case 5961ULL: goto x86_l_1749;
	case 5966ULL: goto x86_l_174e;
	case 5969ULL: goto x86_l_1751;
	case 5974ULL: goto x86_l_1756;
	case 5980ULL: goto x86_l_175c;
	case 5983ULL: goto x86_l_175f;
	case 5989ULL: goto x86_l_1765;
	case 5996ULL: goto x86_l_176c;
	case 6002ULL: goto x86_l_1772;
	case 6005ULL: goto x86_l_1775;
	case 6010ULL: goto x86_l_177a;
	case 6015ULL: goto x86_l_177f;
	case 6020ULL: goto x86_l_1784;
	case 6025ULL: goto x86_l_1789;
	case 6027ULL: goto x86_l_178b;
	case 6029ULL: goto x86_l_178d;
	case 6035ULL: goto x86_l_1793;
	case 6040ULL: goto x86_l_1798;
	case 6047ULL: goto x86_l_179f;
	case 6052ULL: goto x86_l_17a4;
	case 6057ULL: goto x86_l_17a9;
	case 6062ULL: goto x86_l_17ae;
	case 6067ULL: goto x86_l_17b3;
	case 6074ULL: goto x86_l_17ba;
	case 6079ULL: goto x86_l_17bf;
	case 6081ULL: goto x86_l_17c1;
	case 6083ULL: goto x86_l_17c3;
	case 6089ULL: goto x86_l_17c9;
	case 6094ULL: goto x86_l_17ce;
	case 6097ULL: goto x86_l_17d1;
	case 6103ULL: goto x86_l_17d7;
	case 6106ULL: goto x86_l_17da;
	case 6112ULL: goto x86_l_17e0;
	case 6119ULL: goto x86_l_17e7;
	case 6125ULL: goto x86_l_17ed;
	case 6128ULL: goto x86_l_17f0;
	case 6133ULL: goto x86_l_17f5;
	case 6138ULL: goto x86_l_17fa;
	case 6143ULL: goto x86_l_17ff;
	case 6148ULL: goto x86_l_1804;
	case 6150ULL: goto x86_l_1806;
	case 6152ULL: goto x86_l_1808;
	case 6158ULL: goto x86_l_180e;
	case 6163ULL: goto x86_l_1813;
	case 6170ULL: goto x86_l_181a;
	case 6175ULL: goto x86_l_181f;
	case 6180ULL: goto x86_l_1824;
	case 6185ULL: goto x86_l_1829;
	case 6190ULL: goto x86_l_182e;
	case 6197ULL: goto x86_l_1835;
	case 6202ULL: goto x86_l_183a;
	case 6204ULL: goto x86_l_183c;
	case 6206ULL: goto x86_l_183e;
	case 6212ULL: goto x86_l_1844;
	case 6217ULL: goto x86_l_1849;
	case 6220ULL: goto x86_l_184c;
	case 6225ULL: goto x86_l_1851;
	case 6231ULL: goto x86_l_1857;
	case 6234ULL: goto x86_l_185a;
	case 6240ULL: goto x86_l_1860;
	case 6247ULL: goto x86_l_1867;
	case 6252ULL: goto x86_l_186c;
	case 6255ULL: goto x86_l_186f;
	case 6260ULL: goto x86_l_1874;
	case 6265ULL: goto x86_l_1879;
	case 6270ULL: goto x86_l_187e;
	case 6275ULL: goto x86_l_1883;
	case 6278ULL: goto x86_l_1886;
	case 6280ULL: goto x86_l_1888;
	case 6282ULL: goto x86_l_188a;
	case 6288ULL: goto x86_l_1890;
	case 6293ULL: goto x86_l_1895;
	case 6300ULL: goto x86_l_189c;
	case 6305ULL: goto x86_l_18a1;
	case 6310ULL: goto x86_l_18a6;
	case 6315ULL: goto x86_l_18ab;
	case 6320ULL: goto x86_l_18b0;
	case 6327ULL: goto x86_l_18b7;
	case 6332ULL: goto x86_l_18bc;
	case 6334ULL: goto x86_l_18be;
	case 6336ULL: goto x86_l_18c0;
	case 6342ULL: goto x86_l_18c6;
	case 6347ULL: goto x86_l_18cb;
	case 6350ULL: goto x86_l_18ce;
	case 6356ULL: goto x86_l_18d4;
	case 6359ULL: goto x86_l_18d7;
	case 6365ULL: goto x86_l_18dd;
	case 6368ULL: goto x86_l_18e0;
	case 6370ULL: goto x86_l_18e2;
	case 6376ULL: goto x86_l_18e8;
	case 6381ULL: goto x86_l_18ed;
	case 6384ULL: goto x86_l_18f0;
	case 6390ULL: goto x86_l_18f6;
	case 6395ULL: goto x86_l_18fb;
	case 6398ULL: goto x86_l_18fe;
	case 6404ULL: goto x86_l_1904;
	case 6407ULL: goto x86_l_1907;
	case 6413ULL: goto x86_l_190d;
	case 6415ULL: goto x86_l_190f;
	case 6421ULL: goto x86_l_1915;
	case 6426ULL: goto x86_l_191a;
	case 6429ULL: goto x86_l_191d;
	case 6435ULL: goto x86_l_1923;
	case 6440ULL: goto x86_l_1928;
	case 6443ULL: goto x86_l_192b;
	case 6448ULL: goto x86_l_1930;
	case 6454ULL: goto x86_l_1936;
	case 6457ULL: goto x86_l_1939;
	case 6463ULL: goto x86_l_193f;
	case 6465ULL: goto x86_l_1941;
	case 6471ULL: goto x86_l_1947;
	case 6474ULL: goto x86_l_194a;
	case 6477ULL: goto x86_l_194d;
	case 6483ULL: goto x86_l_1953;
	case 6488ULL: goto x86_l_1958;
	case 6491ULL: goto x86_l_195b;
	case 6496ULL: goto x86_l_1960;
	case 6502ULL: goto x86_l_1966;
	case 6505ULL: goto x86_l_1969;
	case 6511ULL: goto x86_l_196f;
	case 6513ULL: goto x86_l_1971;
	case 6519ULL: goto x86_l_1977;
	case 6522ULL: goto x86_l_197a;
	case 6525ULL: goto x86_l_197d;
	case 6531ULL: goto x86_l_1983;
	case 6536ULL: goto x86_l_1988;
	case 6539ULL: goto x86_l_198b;
	case 6545ULL: goto x86_l_1991;
	case 6548ULL: goto x86_l_1994;
	case 6554ULL: goto x86_l_199a;
	case 6556ULL: goto x86_l_199c;
	case 6562ULL: goto x86_l_19a2;
	case 6565ULL: goto x86_l_19a5;
	case 6570ULL: goto x86_l_19aa;
	case 6576ULL: goto x86_l_19b0;
	case 6581ULL: goto x86_l_19b5;
	case 6584ULL: goto x86_l_19b8;
	case 6590ULL: goto x86_l_19be;
	case 6598ULL: goto x86_l_19c6;
	case 6601ULL: goto x86_l_19c9;
	case 6607ULL: goto x86_l_19cf;
	case 6612ULL: goto x86_l_19d4;
	case 6615ULL: goto x86_l_19d7;
	case 6621ULL: goto x86_l_19dd;
	case 6626ULL: goto x86_l_19e2;
	case 6629ULL: goto x86_l_19e5;
	case 6635ULL: goto x86_l_19eb;
	case 6643ULL: goto x86_l_19f3;
	case 6646ULL: goto x86_l_19f6;
	case 6652ULL: goto x86_l_19fc;
	case 6657ULL: goto x86_l_1a01;
	case 6660ULL: goto x86_l_1a04;
	case 6666ULL: goto x86_l_1a0a;
	case 6671ULL: goto x86_l_1a0f;
	case 6674ULL: goto x86_l_1a12;
	case 6680ULL: goto x86_l_1a18;
	case 6688ULL: goto x86_l_1a20;
	case 6691ULL: goto x86_l_1a23;
	case 6697ULL: goto x86_l_1a29;
	case 6702ULL: goto x86_l_1a2e;
	case 6705ULL: goto x86_l_1a31;
	case 6711ULL: goto x86_l_1a37;
	case 6716ULL: goto x86_l_1a3c;
	case 6719ULL: goto x86_l_1a3f;
	case 6725ULL: goto x86_l_1a45;
	case 6733ULL: goto x86_l_1a4d;
	case 6736ULL: goto x86_l_1a50;
	case 6742ULL: goto x86_l_1a56;
	case 6747ULL: goto x86_l_1a5b;
	case 6750ULL: goto x86_l_1a5e;
	case 6756ULL: goto x86_l_1a64;
	case 6761ULL: goto x86_l_1a69;
	case 6764ULL: goto x86_l_1a6c;
	case 6770ULL: goto x86_l_1a72;
	case 6778ULL: goto x86_l_1a7a;
	case 6781ULL: goto x86_l_1a7d;
	case 6787ULL: goto x86_l_1a83;
	case 6792ULL: goto x86_l_1a88;
	case 6795ULL: goto x86_l_1a8b;
	case 6801ULL: goto x86_l_1a91;
	case 6806ULL: goto x86_l_1a96;
	case 6809ULL: goto x86_l_1a99;
	case 6815ULL: goto x86_l_1a9f;
	case 6823ULL: goto x86_l_1aa7;
	case 6826ULL: goto x86_l_1aaa;
	case 6832ULL: goto x86_l_1ab0;
	case 6837ULL: goto x86_l_1ab5;
	case 6840ULL: goto x86_l_1ab8;
	case 6846ULL: goto x86_l_1abe;
	case 6851ULL: goto x86_l_1ac3;
	case 6854ULL: goto x86_l_1ac6;
	case 6860ULL: goto x86_l_1acc;
	case 6868ULL: goto x86_l_1ad4;
	case 6871ULL: goto x86_l_1ad7;
	case 6877ULL: goto x86_l_1add;
	case 6882ULL: goto x86_l_1ae2;
	case 6885ULL: goto x86_l_1ae5;
	case 6891ULL: goto x86_l_1aeb;
	case 6896ULL: goto x86_l_1af0;
	case 6899ULL: goto x86_l_1af3;
	case 6905ULL: goto x86_l_1af9;
	case 6913ULL: goto x86_l_1b01;
	case 6916ULL: goto x86_l_1b04;
	case 6922ULL: goto x86_l_1b0a;
	case 6927ULL: goto x86_l_1b0f;
	case 6930ULL: goto x86_l_1b12;
	case 6936ULL: goto x86_l_1b18;
	case 6941ULL: goto x86_l_1b1d;
	case 6944ULL: goto x86_l_1b20;
	case 6950ULL: goto x86_l_1b26;
	case 6958ULL: goto x86_l_1b2e;
	case 6961ULL: goto x86_l_1b31;
	case 6967ULL: goto x86_l_1b37;
	case 6972ULL: goto x86_l_1b3c;
	case 6975ULL: goto x86_l_1b3f;
	case 6981ULL: goto x86_l_1b45;
	case 6986ULL: goto x86_l_1b4a;
	case 6989ULL: goto x86_l_1b4d;
	case 6995ULL: goto x86_l_1b53;
	case 7003ULL: goto x86_l_1b5b;
	case 7006ULL: goto x86_l_1b5e;
	case 7012ULL: goto x86_l_1b64;
	case 7017ULL: goto x86_l_1b69;
	case 7020ULL: goto x86_l_1b6c;
	case 7026ULL: goto x86_l_1b72;
	case 7031ULL: goto x86_l_1b77;
	case 7038ULL: goto x86_l_1b7e;
	case 7043ULL: goto x86_l_1b83;
	case 7051ULL: goto x86_l_1b8b;
	case 7058ULL: goto x86_l_1b92;
	case 7063ULL: goto x86_l_1b97;
	case 7071ULL: goto x86_l_1b9f;
	case 7076ULL: goto x86_l_1ba4;
	case 7081ULL: goto x86_l_1ba9;
	case 7085ULL: goto x86_l_1bad;
	case 7090ULL: goto x86_l_1bb2;
	case 7097ULL: goto x86_l_1bb9;
	case 7102ULL: goto x86_l_1bbe;
	case 7110ULL: goto x86_l_1bc6;
	case 7117ULL: goto x86_l_1bcd;
	case 7122ULL: goto x86_l_1bd2;
	case 7130ULL: goto x86_l_1bda;
	case 7135ULL: goto x86_l_1bdf;
	case 7140ULL: goto x86_l_1be4;
	case 7144ULL: goto x86_l_1be8;
	case 7149ULL: goto x86_l_1bed;
	case 7156ULL: goto x86_l_1bf4;
	case 7161ULL: goto x86_l_1bf9;
	case 7169ULL: goto x86_l_1c01;
	case 7176ULL: goto x86_l_1c08;
	case 7184ULL: goto x86_l_1c10;
	case 7189ULL: goto x86_l_1c15;
	case 7194ULL: goto x86_l_1c1a;
	case 7198ULL: goto x86_l_1c1e;
	case 7203ULL: goto x86_l_1c23;
	case 7210ULL: goto x86_l_1c2a;
	default: return 0xffffffffffffffffULL;
	}
x86_l_14d2:
	/* 0x14d2: jmp    5472 <generic_sleepable_preload+0x5472> */
	return 21618ULL;
x86_l_14d7:
	/* 0x14d7: movzx  eax,BYTE PTR [r13+0x2ca] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 714ULL);
x86_l_14df:
	/* 0x14df: movzx  ecx,WORD PTR [r13+0x2c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 712ULL);
x86_l_14e7:
	/* 0x14e7: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_14ed:
	/* 0x14ed: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14ef:
	/* 0x14ef: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_14f2:
	/* 0x14f2: jle    1928 <generic_sleepable_preload+0x1928> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1928;
	}
x86_l_14f8:
	/* 0x14f8: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_14fb:
	/* 0x14fb: jle    1a0f <generic_sleepable_preload+0x1a0f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1a0f;
	}
x86_l_1501:
	/* 0x1501: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1504:
	/* 0x1504: jle    4729 <generic_sleepable_preload+0x4729> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 18217ULL;
	}
x86_l_150a:
	/* 0x150a: mov    rsi,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1512:
	/* 0x1512: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_1515:
	/* 0x1515: je     4740 <generic_sleepable_preload+0x4740> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18240ULL;
	}
x86_l_151b:
	/* 0x151b: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1520:
	/* 0x1520: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_1523:
	/* 0x1523: je     4740 <generic_sleepable_preload+0x4740> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18240ULL;
	}
x86_l_1529:
	/* 0x1529: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_152e:
	/* 0x152e: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_1531:
	/* 0x1531: je     4740 <generic_sleepable_preload+0x4740> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18240ULL;
	}
x86_l_1537:
	/* 0x1537: jmp    4753 <generic_sleepable_preload+0x4753> */
	return 18259ULL;
x86_l_153c:
	/* 0x153c: movzx  eax,BYTE PTR [r13+0x2ce] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 718ULL);
x86_l_1544:
	/* 0x1544: movzx  ecx,WORD PTR [r13+0x2cc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 716ULL);
x86_l_154c:
	/* 0x154c: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_1552:
	/* 0x1552: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1554:
	/* 0x1554: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_1557:
	/* 0x1557: jle    1958 <generic_sleepable_preload+0x1958> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1958;
	}
x86_l_155d:
	/* 0x155d: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_1560:
	/* 0x1560: jle    1a3c <generic_sleepable_preload+0x1a3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1a3c;
	}
x86_l_1566:
	/* 0x1566: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1569:
	/* 0x1569: jle    4d90 <generic_sleepable_preload+0x4d90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 19856ULL;
	}
x86_l_156f:
	/* 0x156f: mov    rsi,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1577:
	/* 0x1577: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_157a:
	/* 0x157a: je     4da7 <generic_sleepable_preload+0x4da7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19879ULL;
	}
x86_l_1580:
	/* 0x1580: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1585:
	/* 0x1585: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_1588:
	/* 0x1588: je     4da7 <generic_sleepable_preload+0x4da7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19879ULL;
	}
x86_l_158e:
	/* 0x158e: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1593:
	/* 0x1593: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_1596:
	/* 0x1596: je     4da7 <generic_sleepable_preload+0x4da7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19879ULL;
	}
x86_l_159c:
	/* 0x159c: jmp    4dba <generic_sleepable_preload+0x4dba> */
	return 19898ULL;
x86_l_15a1:
	/* 0x15a1: movzx  eax,BYTE PTR [r13+0x2d2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 722ULL);
x86_l_15a9:
	/* 0x15a9: movzx  ecx,WORD PTR [r13+0x2d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 720ULL);
x86_l_15b1:
	/* 0x15b1: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_15b7:
	/* 0x15b7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15b9:
	/* 0x15b9: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_15bc:
	/* 0x15bc: jle    1988 <generic_sleepable_preload+0x1988> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1988;
	}
x86_l_15c2:
	/* 0x15c2: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_15c5:
	/* 0x15c5: jle    1a69 <generic_sleepable_preload+0x1a69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1a69;
	}
x86_l_15cb:
	/* 0x15cb: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_15ce:
	/* 0x15ce: jle    53e8 <generic_sleepable_preload+0x53e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 21480ULL;
	}
x86_l_15d4:
	/* 0x15d4: mov    rsi,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_15dc:
	/* 0x15dc: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_15df:
	/* 0x15df: je     5aaf <generic_sleepable_preload+0x5aaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23215ULL;
	}
x86_l_15e5:
	/* 0x15e5: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_15ea:
	/* 0x15ea: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_15ed:
	/* 0x15ed: je     5aaf <generic_sleepable_preload+0x5aaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23215ULL;
	}
x86_l_15f3:
	/* 0x15f3: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_15f8:
	/* 0x15f8: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_15fb:
	/* 0x15fb: je     5aaf <generic_sleepable_preload+0x5aaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23215ULL;
	}
x86_l_1601:
	/* 0x1601: jmp    5ac2 <generic_sleepable_preload+0x5ac2> */
	return 23234ULL;
x86_l_1606:
	/* 0x1606: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1609:
	/* 0x1609: je     1c8f <generic_sleepable_preload+0x1c8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7311ULL;
	}
x86_l_160f:
	/* 0x160f: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1612:
	/* 0x1612: jne    1cf2 <generic_sleepable_preload+0x1cf2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7410ULL;
	}
x86_l_1618:
	/* 0x1618: mov    edx,DWORD PTR [r13+0x208] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_161f:
	/* 0x161f: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1625:
	/* 0x1625: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1628:
	/* 0x1628: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_162d:
	/* 0x162d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1632:
	/* 0x1632: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1637:
	/* 0x1637: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_163c:
	/* 0x163c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_163e:
	/* 0x163e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1640:
	/* 0x1640: jne    1cef <generic_sleepable_preload+0x1cef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7407ULL;
	}
x86_l_1646:
	/* 0x1646: mov    edx,DWORD PTR [r13+0x20c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_164d:
	/* 0x164d: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1653:
	/* 0x1653: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1656:
	/* 0x1656: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_165b:
	/* 0x165b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1660:
	/* 0x1660: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1665:
	/* 0x1665: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_166a:
	/* 0x166a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_166c:
	/* 0x166c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_166e:
	/* 0x166e: jne    1cef <generic_sleepable_preload+0x1cef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7407ULL;
	}
x86_l_1674:
	/* 0x1674: movzx  eax,BYTE PTR [r13+0x213] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 531ULL);
x86_l_167c:
	/* 0x167c: shlx   rax,QWORD PTR [rsp+0x8],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_1683:
	/* 0x1683: mov    rcx,QWORD PTR [r13+0x200] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 512ULL);
x86_l_168a:
	/* 0x168a: add    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_168f:
	/* 0x168f: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1692:
	/* 0x1692: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1697:
	/* 0x1697: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_169c:
	/* 0x169c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_16a1:
	/* 0x16a1: movzx  ecx,BYTE PTR [r13+0x213] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 531ULL);
x86_l_16a9:
	/* 0x16a9: shlx   rcx,QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_16b0:
	/* 0x16b0: mov    rdx,QWORD PTR [r13+0x200] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 512ULL);
x86_l_16b7:
	/* 0x16b7: add    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_16bc:
	/* 0x16bc: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_16bf:
	/* 0x16bf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16c4:
	/* 0x16c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16c6:
	/* 0x16c6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_16c8:
	/* 0x16c8: jne    1cef <generic_sleepable_preload+0x1cef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7407ULL;
	}
x86_l_16ce:
	/* 0x16ce: jmp    1b83 <generic_sleepable_preload+0x1b83> */
	goto x86_l_1b83;
x86_l_16d3:
	/* 0x16d3: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16d6:
	/* 0x16d6: je     2306 <generic_sleepable_preload+0x2306> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8966ULL;
	}
x86_l_16dc:
	/* 0x16dc: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_16df:
	/* 0x16df: jne    23bb <generic_sleepable_preload+0x23bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9147ULL;
	}
x86_l_16e5:
	/* 0x16e5: mov    edx,DWORD PTR [r13+0x220] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 544ULL);
x86_l_16ec:
	/* 0x16ec: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_16f2:
	/* 0x16f2: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_16f5:
	/* 0x16f5: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_16fa:
	/* 0x16fa: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_16ff:
	/* 0x16ff: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1704:
	/* 0x1704: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1709:
	/* 0x1709: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_170b:
	/* 0x170b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_170d:
	/* 0x170d: jne    23b8 <generic_sleepable_preload+0x23b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9144ULL;
	}
x86_l_1713:
	/* 0x1713: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1718:
	/* 0x1718: add    rcx,QWORD PTR [r13+0x218] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 536ULL);
x86_l_171f:
	/* 0x171f: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1724:
	/* 0x1724: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1729:
	/* 0x1729: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_172e:
	/* 0x172e: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1733:
	/* 0x1733: add    rdx,QWORD PTR [r13+0x218] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 536ULL);
x86_l_173a:
	/* 0x173a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_173f:
	/* 0x173f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1741:
	/* 0x1741: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1743:
	/* 0x1743: jne    23b8 <generic_sleepable_preload+0x23b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9144ULL;
	}
x86_l_1749:
	/* 0x1749: jmp    1bbe <generic_sleepable_preload+0x1bbe> */
	goto x86_l_1bbe;
x86_l_174e:
	/* 0x174e: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1751:
	/* 0x1751: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1756:
	/* 0x1756: je     29db <generic_sleepable_preload+0x29db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10715ULL;
	}
x86_l_175c:
	/* 0x175c: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_175f:
	/* 0x175f: jne    2a90 <generic_sleepable_preload+0x2a90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10896ULL;
	}
x86_l_1765:
	/* 0x1765: mov    edx,DWORD PTR [r13+0x238] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 568ULL);
x86_l_176c:
	/* 0x176c: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1772:
	/* 0x1772: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1775:
	/* 0x1775: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_177a:
	/* 0x177a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_177f:
	/* 0x177f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1784:
	/* 0x1784: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1789:
	/* 0x1789: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_178b:
	/* 0x178b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_178d:
	/* 0x178d: jne    2a8d <generic_sleepable_preload+0x2a8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10893ULL;
	}
x86_l_1793:
	/* 0x1793: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1798:
	/* 0x1798: add    rcx,QWORD PTR [r13+0x230] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 560ULL);
x86_l_179f:
	/* 0x179f: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_17a4:
	/* 0x17a4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_17a9:
	/* 0x17a9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_17ae:
	/* 0x17ae: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_17b3:
	/* 0x17b3: add    rdx,QWORD PTR [r13+0x230] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 560ULL);
x86_l_17ba:
	/* 0x17ba: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17bf:
	/* 0x17bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17c1:
	/* 0x17c1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_17c3:
	/* 0x17c3: jne    2a8d <generic_sleepable_preload+0x2a8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10893ULL;
	}
x86_l_17c9:
	/* 0x17c9: jmp    1bf9 <generic_sleepable_preload+0x1bf9> */
	goto x86_l_1bf9;
x86_l_17ce:
	/* 0x17ce: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17d1:
	/* 0x17d1: je     30bf <generic_sleepable_preload+0x30bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12479ULL;
	}
x86_l_17d7:
	/* 0x17d7: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_17da:
	/* 0x17da: jne    3174 <generic_sleepable_preload+0x3174> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12660ULL;
	}
x86_l_17e0:
	/* 0x17e0: mov    edx,DWORD PTR [r13+0x250] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 592ULL);
x86_l_17e7:
	/* 0x17e7: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_17ed:
	/* 0x17ed: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_17f0:
	/* 0x17f0: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_17f5:
	/* 0x17f5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_17fa:
	/* 0x17fa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_17ff:
	/* 0x17ff: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1804:
	/* 0x1804: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1806:
	/* 0x1806: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1808:
	/* 0x1808: jne    3171 <generic_sleepable_preload+0x3171> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12657ULL;
	}
x86_l_180e:
	/* 0x180e: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1813:
	/* 0x1813: add    rcx,QWORD PTR [r13+0x248] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 584ULL);
x86_l_181a:
	/* 0x181a: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_181f:
	/* 0x181f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1824:
	/* 0x1824: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1829:
	/* 0x1829: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_182e:
	/* 0x182e: add    rdx,QWORD PTR [r13+0x248] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 584ULL);
x86_l_1835:
	/* 0x1835: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_183a:
	/* 0x183a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_183c:
	/* 0x183c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_183e:
	/* 0x183e: jne    3171 <generic_sleepable_preload+0x3171> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12657ULL;
	}
x86_l_1844:
	/* 0x1844: jmp    1c2f <generic_sleepable_preload+0x1c2f> */
	return 7215ULL;
x86_l_1849:
	/* 0x1849: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_184c:
	/* 0x184c: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1851:
	/* 0x1851: je     3794 <generic_sleepable_preload+0x3794> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14228ULL;
	}
x86_l_1857:
	/* 0x1857: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_185a:
	/* 0x185a: jne    384b <generic_sleepable_preload+0x384b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14411ULL;
	}
x86_l_1860:
	/* 0x1860: mov    eax,DWORD PTR [r13+0x268] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 616ULL);
x86_l_1867:
	/* 0x1867: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_186c:
	/* 0x186c: add    rbx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_186f:
	/* 0x186f: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1874:
	/* 0x1874: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1879:
	/* 0x1879: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_187e:
	/* 0x187e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1883:
	/* 0x1883: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1886:
	/* 0x1886: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1888:
	/* 0x1888: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_188a:
	/* 0x188a: jne    3848 <generic_sleepable_preload+0x3848> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14408ULL;
	}
x86_l_1890:
	/* 0x1890: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1895:
	/* 0x1895: add    rcx,QWORD PTR [r13+0x260] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 608ULL);
x86_l_189c:
	/* 0x189c: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18a1:
	/* 0x18a1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_18a6:
	/* 0x18a6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_18ab:
	/* 0x18ab: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18b0:
	/* 0x18b0: add    rdx,QWORD PTR [r13+0x260] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 608ULL);
x86_l_18b7:
	/* 0x18b7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18bc:
	/* 0x18bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18be:
	/* 0x18be: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_18c0:
	/* 0x18c0: jne    3848 <generic_sleepable_preload+0x3848> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14408ULL;
	}
x86_l_18c6:
	/* 0x18c6: jmp    1c65 <generic_sleepable_preload+0x1c65> */
	return 7269ULL;
x86_l_18cb:
	/* 0x18cb: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_18ce:
	/* 0x18ce: jg     1a96 <generic_sleepable_preload+0x1a96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1a96;
	}
x86_l_18d4:
	/* 0x18d4: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_18d7:
	/* 0x18d7: jg     3f51 <generic_sleepable_preload+0x3f51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16209ULL;
	}
x86_l_18dd:
	/* 0x18dd: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_18e0:
	/* 0x18e0: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_18e2:
	/* 0x18e2: je     40d0 <generic_sleepable_preload+0x40d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16592ULL;
	}
x86_l_18e8:
	/* 0x18e8: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_18ed:
	/* 0x18ed: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_18f0:
	/* 0x18f0: je     40d0 <generic_sleepable_preload+0x40d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16592ULL;
	}
x86_l_18f6:
	/* 0x18f6: jmp    40e3 <generic_sleepable_preload+0x40e3> */
	return 16611ULL;
x86_l_18fb:
	/* 0x18fb: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_18fe:
	/* 0x18fe: jg     1ac3 <generic_sleepable_preload+0x1ac3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1ac3;
	}
x86_l_1904:
	/* 0x1904: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_1907:
	/* 0x1907: jg     3f75 <generic_sleepable_preload+0x3f75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16245ULL;
	}
x86_l_190d:
	/* 0x190d: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_190f:
	/* 0x190f: je     545c <generic_sleepable_preload+0x545c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21596ULL;
	}
x86_l_1915:
	/* 0x1915: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_191a:
	/* 0x191a: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_191d:
	/* 0x191d: je     545f <generic_sleepable_preload+0x545f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21599ULL;
	}
x86_l_1923:
	/* 0x1923: jmp    5472 <generic_sleepable_preload+0x5472> */
	return 21618ULL;
x86_l_1928:
	/* 0x1928: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_192b:
	/* 0x192b: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1930:
	/* 0x1930: jg     1af0 <generic_sleepable_preload+0x1af0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1af0;
	}
x86_l_1936:
	/* 0x1936: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_1939:
	/* 0x1939: jg     3f99 <generic_sleepable_preload+0x3f99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16281ULL;
	}
x86_l_193f:
	/* 0x193f: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_1941:
	/* 0x1941: je     4740 <generic_sleepable_preload+0x4740> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18240ULL;
	}
x86_l_1947:
	/* 0x1947: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_194a:
	/* 0x194a: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_194d:
	/* 0x194d: je     4740 <generic_sleepable_preload+0x4740> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18240ULL;
	}
x86_l_1953:
	/* 0x1953: jmp    4753 <generic_sleepable_preload+0x4753> */
	return 18259ULL;
x86_l_1958:
	/* 0x1958: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_195b:
	/* 0x195b: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1960:
	/* 0x1960: jg     1b1d <generic_sleepable_preload+0x1b1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1b1d;
	}
x86_l_1966:
	/* 0x1966: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_1969:
	/* 0x1969: jg     3fbd <generic_sleepable_preload+0x3fbd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16317ULL;
	}
x86_l_196f:
	/* 0x196f: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_1971:
	/* 0x1971: je     4da7 <generic_sleepable_preload+0x4da7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19879ULL;
	}
x86_l_1977:
	/* 0x1977: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_197a:
	/* 0x197a: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_197d:
	/* 0x197d: je     4da7 <generic_sleepable_preload+0x4da7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19879ULL;
	}
x86_l_1983:
	/* 0x1983: jmp    4dba <generic_sleepable_preload+0x4dba> */
	return 19898ULL;
x86_l_1988:
	/* 0x1988: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_198b:
	/* 0x198b: jg     1b4a <generic_sleepable_preload+0x1b4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1b4a;
	}
x86_l_1991:
	/* 0x1991: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_1994:
	/* 0x1994: jg     3fe1 <generic_sleepable_preload+0x3fe1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16353ULL;
	}
x86_l_199a:
	/* 0x199a: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_199c:
	/* 0x199c: je     5aaa <generic_sleepable_preload+0x5aaa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23210ULL;
	}
x86_l_19a2:
	/* 0x19a2: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_19a5:
	/* 0x19a5: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_19aa:
	/* 0x19aa: je     5aaf <generic_sleepable_preload+0x5aaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23215ULL;
	}
x86_l_19b0:
	/* 0x19b0: jmp    5ac2 <generic_sleepable_preload+0x5ac2> */
	return 23234ULL;
x86_l_19b5:
	/* 0x19b5: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_19b8:
	/* 0x19b8: jg     3e9d <generic_sleepable_preload+0x3e9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16029ULL;
	}
x86_l_19be:
	/* 0x19be: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_19c6:
	/* 0x19c6: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_19c9:
	/* 0x19c9: je     40d0 <generic_sleepable_preload+0x40d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16592ULL;
	}
x86_l_19cf:
	/* 0x19cf: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_19d4:
	/* 0x19d4: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_19d7:
	/* 0x19d7: je     40d0 <generic_sleepable_preload+0x40d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16592ULL;
	}
x86_l_19dd:
	/* 0x19dd: jmp    40e3 <generic_sleepable_preload+0x40e3> */
	return 16611ULL;
x86_l_19e2:
	/* 0x19e2: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_19e5:
	/* 0x19e5: jg     3ec1 <generic_sleepable_preload+0x3ec1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16065ULL;
	}
x86_l_19eb:
	/* 0x19eb: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_19f3:
	/* 0x19f3: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_19f6:
	/* 0x19f6: je     545f <generic_sleepable_preload+0x545f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21599ULL;
	}
x86_l_19fc:
	/* 0x19fc: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1a01:
	/* 0x1a01: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_1a04:
	/* 0x1a04: je     545f <generic_sleepable_preload+0x545f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21599ULL;
	}
x86_l_1a0a:
	/* 0x1a0a: jmp    5472 <generic_sleepable_preload+0x5472> */
	return 21618ULL;
x86_l_1a0f:
	/* 0x1a0f: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_1a12:
	/* 0x1a12: jg     3ee5 <generic_sleepable_preload+0x3ee5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16101ULL;
	}
x86_l_1a18:
	/* 0x1a18: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1a20:
	/* 0x1a20: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1a23:
	/* 0x1a23: je     4740 <generic_sleepable_preload+0x4740> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18240ULL;
	}
x86_l_1a29:
	/* 0x1a29: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1a2e:
	/* 0x1a2e: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_1a31:
	/* 0x1a31: je     4740 <generic_sleepable_preload+0x4740> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18240ULL;
	}
x86_l_1a37:
	/* 0x1a37: jmp    4753 <generic_sleepable_preload+0x4753> */
	return 18259ULL;
x86_l_1a3c:
	/* 0x1a3c: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_1a3f:
	/* 0x1a3f: jg     3f09 <generic_sleepable_preload+0x3f09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16137ULL;
	}
x86_l_1a45:
	/* 0x1a45: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1a4d:
	/* 0x1a4d: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1a50:
	/* 0x1a50: je     4da7 <generic_sleepable_preload+0x4da7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19879ULL;
	}
x86_l_1a56:
	/* 0x1a56: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1a5b:
	/* 0x1a5b: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_1a5e:
	/* 0x1a5e: je     4da7 <generic_sleepable_preload+0x4da7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19879ULL;
	}
x86_l_1a64:
	/* 0x1a64: jmp    4dba <generic_sleepable_preload+0x4dba> */
	return 19898ULL;
x86_l_1a69:
	/* 0x1a69: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_1a6c:
	/* 0x1a6c: jg     3f2d <generic_sleepable_preload+0x3f2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16173ULL;
	}
x86_l_1a72:
	/* 0x1a72: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1a7a:
	/* 0x1a7a: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1a7d:
	/* 0x1a7d: je     5aaf <generic_sleepable_preload+0x5aaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23215ULL;
	}
x86_l_1a83:
	/* 0x1a83: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1a88:
	/* 0x1a88: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_1a8b:
	/* 0x1a8b: je     5aaf <generic_sleepable_preload+0x5aaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23215ULL;
	}
x86_l_1a91:
	/* 0x1a91: jmp    5ac2 <generic_sleepable_preload+0x5ac2> */
	return 23234ULL;
x86_l_1a96:
	/* 0x1a96: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1a99:
	/* 0x1a99: jg     4005 <generic_sleepable_preload+0x4005> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16389ULL;
	}
x86_l_1a9f:
	/* 0x1a9f: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1aa7:
	/* 0x1aa7: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1aaa:
	/* 0x1aaa: je     40d0 <generic_sleepable_preload+0x40d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16592ULL;
	}
x86_l_1ab0:
	/* 0x1ab0: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1ab5:
	/* 0x1ab5: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1ab8:
	/* 0x1ab8: je     40d0 <generic_sleepable_preload+0x40d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16592ULL;
	}
x86_l_1abe:
	/* 0x1abe: jmp    40e3 <generic_sleepable_preload+0x40e3> */
	return 16611ULL;
x86_l_1ac3:
	/* 0x1ac3: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1ac6:
	/* 0x1ac6: jg     4029 <generic_sleepable_preload+0x4029> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16425ULL;
	}
x86_l_1acc:
	/* 0x1acc: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1ad4:
	/* 0x1ad4: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1ad7:
	/* 0x1ad7: je     545f <generic_sleepable_preload+0x545f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21599ULL;
	}
x86_l_1add:
	/* 0x1add: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1ae2:
	/* 0x1ae2: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1ae5:
	/* 0x1ae5: je     545f <generic_sleepable_preload+0x545f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21599ULL;
	}
x86_l_1aeb:
	/* 0x1aeb: jmp    5472 <generic_sleepable_preload+0x5472> */
	return 21618ULL;
x86_l_1af0:
	/* 0x1af0: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1af3:
	/* 0x1af3: jg     404d <generic_sleepable_preload+0x404d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16461ULL;
	}
x86_l_1af9:
	/* 0x1af9: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1b01:
	/* 0x1b01: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1b04:
	/* 0x1b04: je     4740 <generic_sleepable_preload+0x4740> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18240ULL;
	}
x86_l_1b0a:
	/* 0x1b0a: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1b0f:
	/* 0x1b0f: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1b12:
	/* 0x1b12: je     4740 <generic_sleepable_preload+0x4740> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18240ULL;
	}
x86_l_1b18:
	/* 0x1b18: jmp    4753 <generic_sleepable_preload+0x4753> */
	return 18259ULL;
x86_l_1b1d:
	/* 0x1b1d: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1b20:
	/* 0x1b20: jg     4071 <generic_sleepable_preload+0x4071> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16497ULL;
	}
x86_l_1b26:
	/* 0x1b26: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1b2e:
	/* 0x1b2e: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1b31:
	/* 0x1b31: je     4da7 <generic_sleepable_preload+0x4da7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19879ULL;
	}
x86_l_1b37:
	/* 0x1b37: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1b3c:
	/* 0x1b3c: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1b3f:
	/* 0x1b3f: je     4da7 <generic_sleepable_preload+0x4da7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19879ULL;
	}
x86_l_1b45:
	/* 0x1b45: jmp    4dba <generic_sleepable_preload+0x4dba> */
	return 19898ULL;
x86_l_1b4a:
	/* 0x1b4a: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1b4d:
	/* 0x1b4d: jg     4095 <generic_sleepable_preload+0x4095> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16533ULL;
	}
x86_l_1b53:
	/* 0x1b53: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1b5b:
	/* 0x1b5b: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1b5e:
	/* 0x1b5e: je     5aaf <generic_sleepable_preload+0x5aaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23215ULL;
	}
x86_l_1b64:
	/* 0x1b64: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1b69:
	/* 0x1b69: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1b6c:
	/* 0x1b6c: je     5aaf <generic_sleepable_preload+0x5aaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23215ULL;
	}
x86_l_1b72:
	/* 0x1b72: jmp    5ac2 <generic_sleepable_preload+0x5ac2> */
	return 23234ULL;
x86_l_1b77:
	/* 0x1b77: mov    rax,QWORD PTR [r13+0x200] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 512ULL);
x86_l_1b7e:
	/* 0x1b7e: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b83:
	/* 0x1b83: movzx  eax,BYTE PTR [r13+0x210] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 528ULL);
x86_l_1b8b:
	/* 0x1b8b: shlx   rcx,QWORD PTR [rsp+0x18],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((24ULL << 32) | X86_ALU_SHL));
x86_l_1b92:
	/* 0x1b92: mov    QWORD PTR [rsp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b97:
	/* 0x1b97: cmp    BYTE PTR [r13+0x212],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2276332666880ULL);
x86_l_1b9f:
	/* 0x1b9f: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_1ba4:
	/* 0x1ba4: sarx   rcx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RCX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_1ba9:
	/* 0x1ba9: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_1bad:
	/* 0x1bad: jmp    1cf2 <generic_sleepable_preload+0x1cf2> */
	return 7410ULL;
x86_l_1bb2:
	/* 0x1bb2: mov    rax,QWORD PTR [r13+0x218] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 536ULL);
x86_l_1bb9:
	/* 0x1bb9: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1bbe:
	/* 0x1bbe: movzx  eax,BYTE PTR [r13+0x228] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 552ULL);
x86_l_1bc6:
	/* 0x1bc6: shlx   rcx,QWORD PTR [rsp+0x18],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((24ULL << 32) | X86_ALU_SHL));
x86_l_1bcd:
	/* 0x1bcd: mov    QWORD PTR [rsp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1bd2:
	/* 0x1bd2: cmp    BYTE PTR [r13+0x22a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2379411881984ULL);
x86_l_1bda:
	/* 0x1bda: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_1bdf:
	/* 0x1bdf: sarx   rcx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RCX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_1be4:
	/* 0x1be4: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_1be8:
	/* 0x1be8: jmp    23bb <generic_sleepable_preload+0x23bb> */
	return 9147ULL;
x86_l_1bed:
	/* 0x1bed: mov    rax,QWORD PTR [r13+0x230] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 560ULL);
x86_l_1bf4:
	/* 0x1bf4: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1bf9:
	/* 0x1bf9: movzx  eax,BYTE PTR [r13+0x240] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 576ULL);
x86_l_1c01:
	/* 0x1c01: shlx   rcx,QWORD PTR [rsp+0x18],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((24ULL << 32) | X86_ALU_SHL));
x86_l_1c08:
	/* 0x1c08: cmp    BYTE PTR [r13+0x242],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2482491097088ULL);
x86_l_1c10:
	/* 0x1c10: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_1c15:
	/* 0x1c15: sarx   rcx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RCX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_1c1a:
	/* 0x1c1a: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_1c1e:
	/* 0x1c1e: jmp    2a90 <generic_sleepable_preload+0x2a90> */
	return 10896ULL;
x86_l_1c23:
	/* 0x1c23: mov    rax,QWORD PTR [r13+0x248] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584ULL);
x86_l_1c2a:
	/* 0x1c2a: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
	return 7215ULL;
}

static __noinline __u64 tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7215ULL: goto x86_l_1c2f;
	case 7223ULL: goto x86_l_1c37;
	case 7230ULL: goto x86_l_1c3e;
	case 7238ULL: goto x86_l_1c46;
	case 7243ULL: goto x86_l_1c4b;
	case 7248ULL: goto x86_l_1c50;
	case 7252ULL: goto x86_l_1c54;
	case 7257ULL: goto x86_l_1c59;
	case 7264ULL: goto x86_l_1c60;
	case 7269ULL: goto x86_l_1c65;
	case 7277ULL: goto x86_l_1c6d;
	case 7284ULL: goto x86_l_1c74;
	case 7292ULL: goto x86_l_1c7c;
	case 7297ULL: goto x86_l_1c81;
	case 7302ULL: goto x86_l_1c86;
	case 7306ULL: goto x86_l_1c8a;
	case 7311ULL: goto x86_l_1c8f;
	case 7318ULL: goto x86_l_1c96;
	case 7324ULL: goto x86_l_1c9c;
	case 7327ULL: goto x86_l_1c9f;
	case 7332ULL: goto x86_l_1ca4;
	case 7337ULL: goto x86_l_1ca9;
	case 7342ULL: goto x86_l_1cae;
	case 7347ULL: goto x86_l_1cb3;
	case 7349ULL: goto x86_l_1cb5;
	case 7351ULL: goto x86_l_1cb7;
	case 7353ULL: goto x86_l_1cb9;
	case 7358ULL: goto x86_l_1cbe;
	case 7365ULL: goto x86_l_1cc5;
	case 7370ULL: goto x86_l_1cca;
	case 7375ULL: goto x86_l_1ccf;
	case 7380ULL: goto x86_l_1cd4;
	case 7385ULL: goto x86_l_1cd9;
	case 7392ULL: goto x86_l_1ce0;
	case 7397ULL: goto x86_l_1ce5;
	case 7399ULL: goto x86_l_1ce7;
	case 7401ULL: goto x86_l_1ce9;
	case 7407ULL: goto x86_l_1cef;
	case 7410ULL: goto x86_l_1cf2;
	case 7415ULL: goto x86_l_1cf7;
	case 7417ULL: goto x86_l_1cf9;
	case 7420ULL: goto x86_l_1cfc;
	case 7426ULL: goto x86_l_1d02;
	case 7432ULL: goto x86_l_1d08;
	case 7439ULL: goto x86_l_1d0f;
	case 7442ULL: goto x86_l_1d12;
	case 7446ULL: goto x86_l_1d16;
	case 7449ULL: goto x86_l_1d19;
	case 7454ULL: goto x86_l_1d1e;
	case 7459ULL: goto x86_l_1d23;
	case 7461ULL: goto x86_l_1d25;
	case 7467ULL: goto x86_l_1d2b;
	case 7470ULL: goto x86_l_1d2e;
	case 7472ULL: goto x86_l_1d30;
	case 7477ULL: goto x86_l_1d35;
	case 7482ULL: goto x86_l_1d3a;
	case 7487ULL: goto x86_l_1d3f;
	case 7492ULL: goto x86_l_1d44;
	case 7497ULL: goto x86_l_1d49;
	case 7499ULL: goto x86_l_1d4b;
	case 7501ULL: goto x86_l_1d4d;
	case 7507ULL: goto x86_l_1d53;
	case 7513ULL: goto x86_l_1d59;
	case 7519ULL: goto x86_l_1d5f;
	case 7523ULL: goto x86_l_1d63;
	case 7528ULL: goto x86_l_1d68;
	case 7533ULL: goto x86_l_1d6d;
	case 7539ULL: goto x86_l_1d73;
	case 7541ULL: goto x86_l_1d75;
	case 7546ULL: goto x86_l_1d7a;
	case 7551ULL: goto x86_l_1d7f;
	case 7556ULL: goto x86_l_1d84;
	case 7561ULL: goto x86_l_1d89;
	case 7566ULL: goto x86_l_1d8e;
	case 7568ULL: goto x86_l_1d90;
	case 7570ULL: goto x86_l_1d92;
	case 7576ULL: goto x86_l_1d98;
	case 7585ULL: goto x86_l_1da1;
	case 7591ULL: goto x86_l_1da7;
	case 7598ULL: goto x86_l_1dae;
	case 7603ULL: goto x86_l_1db3;
	case 7608ULL: goto x86_l_1db8;
	case 7617ULL: goto x86_l_1dc1;
	case 7619ULL: goto x86_l_1dc3;
	case 7624ULL: goto x86_l_1dc8;
	case 7629ULL: goto x86_l_1dcd;
	case 7634ULL: goto x86_l_1dd2;
	case 7639ULL: goto x86_l_1dd7;
	case 7644ULL: goto x86_l_1ddc;
	case 7646ULL: goto x86_l_1dde;
	case 7648ULL: goto x86_l_1de0;
	case 7654ULL: goto x86_l_1de6;
	case 7663ULL: goto x86_l_1def;
	case 7669ULL: goto x86_l_1df5;
	case 7676ULL: goto x86_l_1dfc;
	case 7681ULL: goto x86_l_1e01;
	case 7686ULL: goto x86_l_1e06;
	case 7695ULL: goto x86_l_1e0f;
	case 7697ULL: goto x86_l_1e11;
	case 7702ULL: goto x86_l_1e16;
	case 7707ULL: goto x86_l_1e1b;
	case 7712ULL: goto x86_l_1e20;
	case 7717ULL: goto x86_l_1e25;
	case 7722ULL: goto x86_l_1e2a;
	case 7724ULL: goto x86_l_1e2c;
	case 7726ULL: goto x86_l_1e2e;
	case 7732ULL: goto x86_l_1e34;
	case 7741ULL: goto x86_l_1e3d;
	case 7747ULL: goto x86_l_1e43;
	case 7754ULL: goto x86_l_1e4a;
	case 7759ULL: goto x86_l_1e4f;
	case 7764ULL: goto x86_l_1e54;
	case 7773ULL: goto x86_l_1e5d;
	case 7775ULL: goto x86_l_1e5f;
	case 7780ULL: goto x86_l_1e64;
	case 7785ULL: goto x86_l_1e69;
	case 7790ULL: goto x86_l_1e6e;
	case 7795ULL: goto x86_l_1e73;
	case 7800ULL: goto x86_l_1e78;
	case 7802ULL: goto x86_l_1e7a;
	case 7804ULL: goto x86_l_1e7c;
	case 7810ULL: goto x86_l_1e82;
	case 7819ULL: goto x86_l_1e8b;
	case 7825ULL: goto x86_l_1e91;
	case 7832ULL: goto x86_l_1e98;
	case 7837ULL: goto x86_l_1e9d;
	case 7842ULL: goto x86_l_1ea2;
	case 7851ULL: goto x86_l_1eab;
	case 7853ULL: goto x86_l_1ead;
	case 7858ULL: goto x86_l_1eb2;
	case 7863ULL: goto x86_l_1eb7;
	case 7868ULL: goto x86_l_1ebc;
	case 7873ULL: goto x86_l_1ec1;
	case 7878ULL: goto x86_l_1ec6;
	case 7880ULL: goto x86_l_1ec8;
	case 7882ULL: goto x86_l_1eca;
	case 7888ULL: goto x86_l_1ed0;
	case 7897ULL: goto x86_l_1ed9;
	case 7903ULL: goto x86_l_1edf;
	case 7910ULL: goto x86_l_1ee6;
	case 7915ULL: goto x86_l_1eeb;
	case 7920ULL: goto x86_l_1ef0;
	case 7929ULL: goto x86_l_1ef9;
	case 7931ULL: goto x86_l_1efb;
	case 7936ULL: goto x86_l_1f00;
	case 7941ULL: goto x86_l_1f05;
	case 7946ULL: goto x86_l_1f0a;
	case 7951ULL: goto x86_l_1f0f;
	case 7956ULL: goto x86_l_1f14;
	case 7958ULL: goto x86_l_1f16;
	case 7960ULL: goto x86_l_1f18;
	case 7966ULL: goto x86_l_1f1e;
	case 7975ULL: goto x86_l_1f27;
	case 7981ULL: goto x86_l_1f2d;
	case 7988ULL: goto x86_l_1f34;
	case 7993ULL: goto x86_l_1f39;
	case 7998ULL: goto x86_l_1f3e;
	case 8007ULL: goto x86_l_1f47;
	case 8009ULL: goto x86_l_1f49;
	case 8014ULL: goto x86_l_1f4e;
	case 8019ULL: goto x86_l_1f53;
	case 8024ULL: goto x86_l_1f58;
	case 8029ULL: goto x86_l_1f5d;
	case 8034ULL: goto x86_l_1f62;
	case 8036ULL: goto x86_l_1f64;
	case 8038ULL: goto x86_l_1f66;
	case 8044ULL: goto x86_l_1f6c;
	case 8053ULL: goto x86_l_1f75;
	case 8059ULL: goto x86_l_1f7b;
	case 8066ULL: goto x86_l_1f82;
	case 8071ULL: goto x86_l_1f87;
	case 8076ULL: goto x86_l_1f8c;
	case 8085ULL: goto x86_l_1f95;
	case 8087ULL: goto x86_l_1f97;
	case 8092ULL: goto x86_l_1f9c;
	case 8097ULL: goto x86_l_1fa1;
	case 8102ULL: goto x86_l_1fa6;
	case 8107ULL: goto x86_l_1fab;
	case 8112ULL: goto x86_l_1fb0;
	case 8114ULL: goto x86_l_1fb2;
	case 8116ULL: goto x86_l_1fb4;
	case 8122ULL: goto x86_l_1fba;
	case 8127ULL: goto x86_l_1fbf;
	case 8136ULL: goto x86_l_1fc8;
	case 8141ULL: goto x86_l_1fcd;
	case 8147ULL: goto x86_l_1fd3;
	case 8154ULL: goto x86_l_1fda;
	case 8159ULL: goto x86_l_1fdf;
	case 8164ULL: goto x86_l_1fe4;
	case 8173ULL: goto x86_l_1fed;
	case 8179ULL: goto x86_l_1ff3;
	case 8184ULL: goto x86_l_1ff8;
	case 8189ULL: goto x86_l_1ffd;
	case 8194ULL: goto x86_l_2002;
	case 8199ULL: goto x86_l_2007;
	case 8202ULL: goto x86_l_200a;
	case 8204ULL: goto x86_l_200c;
	case 8209ULL: goto x86_l_2011;
	case 8214ULL: goto x86_l_2016;
	case 8219ULL: goto x86_l_201b;
	case 8224ULL: goto x86_l_2020;
	case 8229ULL: goto x86_l_2025;
	case 8231ULL: goto x86_l_2027;
	case 8233ULL: goto x86_l_2029;
	case 8239ULL: goto x86_l_202f;
	case 8245ULL: goto x86_l_2035;
	case 8251ULL: goto x86_l_203b;
	case 8255ULL: goto x86_l_203f;
	case 8260ULL: goto x86_l_2044;
	case 8265ULL: goto x86_l_2049;
	case 8271ULL: goto x86_l_204f;
	case 8273ULL: goto x86_l_2051;
	case 8278ULL: goto x86_l_2056;
	case 8283ULL: goto x86_l_205b;
	case 8288ULL: goto x86_l_2060;
	case 8293ULL: goto x86_l_2065;
	case 8298ULL: goto x86_l_206a;
	case 8300ULL: goto x86_l_206c;
	case 8302ULL: goto x86_l_206e;
	case 8308ULL: goto x86_l_2074;
	case 8317ULL: goto x86_l_207d;
	case 8323ULL: goto x86_l_2083;
	case 8330ULL: goto x86_l_208a;
	case 8335ULL: goto x86_l_208f;
	case 8340ULL: goto x86_l_2094;
	case 8349ULL: goto x86_l_209d;
	case 8351ULL: goto x86_l_209f;
	case 8356ULL: goto x86_l_20a4;
	case 8361ULL: goto x86_l_20a9;
	case 8366ULL: goto x86_l_20ae;
	case 8371ULL: goto x86_l_20b3;
	case 8376ULL: goto x86_l_20b8;
	case 8378ULL: goto x86_l_20ba;
	case 8380ULL: goto x86_l_20bc;
	case 8386ULL: goto x86_l_20c2;
	case 8395ULL: goto x86_l_20cb;
	case 8401ULL: goto x86_l_20d1;
	case 8408ULL: goto x86_l_20d8;
	case 8413ULL: goto x86_l_20dd;
	case 8418ULL: goto x86_l_20e2;
	case 8427ULL: goto x86_l_20eb;
	case 8429ULL: goto x86_l_20ed;
	case 8434ULL: goto x86_l_20f2;
	case 8439ULL: goto x86_l_20f7;
	case 8444ULL: goto x86_l_20fc;
	case 8449ULL: goto x86_l_2101;
	case 8454ULL: goto x86_l_2106;
	case 8456ULL: goto x86_l_2108;
	case 8458ULL: goto x86_l_210a;
	case 8464ULL: goto x86_l_2110;
	case 8473ULL: goto x86_l_2119;
	case 8479ULL: goto x86_l_211f;
	case 8486ULL: goto x86_l_2126;
	case 8491ULL: goto x86_l_212b;
	case 8496ULL: goto x86_l_2130;
	case 8505ULL: goto x86_l_2139;
	case 8507ULL: goto x86_l_213b;
	case 8512ULL: goto x86_l_2140;
	case 8517ULL: goto x86_l_2145;
	case 8522ULL: goto x86_l_214a;
	case 8527ULL: goto x86_l_214f;
	case 8532ULL: goto x86_l_2154;
	case 8534ULL: goto x86_l_2156;
	case 8536ULL: goto x86_l_2158;
	case 8542ULL: goto x86_l_215e;
	case 8551ULL: goto x86_l_2167;
	case 8557ULL: goto x86_l_216d;
	case 8564ULL: goto x86_l_2174;
	case 8569ULL: goto x86_l_2179;
	case 8574ULL: goto x86_l_217e;
	case 8583ULL: goto x86_l_2187;
	case 8585ULL: goto x86_l_2189;
	case 8590ULL: goto x86_l_218e;
	case 8595ULL: goto x86_l_2193;
	case 8600ULL: goto x86_l_2198;
	case 8605ULL: goto x86_l_219d;
	case 8610ULL: goto x86_l_21a2;
	case 8612ULL: goto x86_l_21a4;
	case 8614ULL: goto x86_l_21a6;
	case 8620ULL: goto x86_l_21ac;
	case 8629ULL: goto x86_l_21b5;
	case 8635ULL: goto x86_l_21bb;
	case 8642ULL: goto x86_l_21c2;
	case 8647ULL: goto x86_l_21c7;
	case 8652ULL: goto x86_l_21cc;
	case 8661ULL: goto x86_l_21d5;
	case 8663ULL: goto x86_l_21d7;
	case 8668ULL: goto x86_l_21dc;
	case 8673ULL: goto x86_l_21e1;
	case 8678ULL: goto x86_l_21e6;
	case 8683ULL: goto x86_l_21eb;
	case 8688ULL: goto x86_l_21f0;
	case 8690ULL: goto x86_l_21f2;
	case 8692ULL: goto x86_l_21f4;
	case 8698ULL: goto x86_l_21fa;
	case 8707ULL: goto x86_l_2203;
	case 8713ULL: goto x86_l_2209;
	case 8720ULL: goto x86_l_2210;
	case 8725ULL: goto x86_l_2215;
	case 8730ULL: goto x86_l_221a;
	case 8739ULL: goto x86_l_2223;
	case 8741ULL: goto x86_l_2225;
	case 8746ULL: goto x86_l_222a;
	case 8751ULL: goto x86_l_222f;
	case 8756ULL: goto x86_l_2234;
	case 8761ULL: goto x86_l_2239;
	case 8766ULL: goto x86_l_223e;
	case 8768ULL: goto x86_l_2240;
	case 8770ULL: goto x86_l_2242;
	case 8776ULL: goto x86_l_2248;
	case 8781ULL: goto x86_l_224d;
	case 8790ULL: goto x86_l_2256;
	case 8795ULL: goto x86_l_225b;
	case 8801ULL: goto x86_l_2261;
	case 8808ULL: goto x86_l_2268;
	case 8813ULL: goto x86_l_226d;
	case 8818ULL: goto x86_l_2272;
	case 8827ULL: goto x86_l_227b;
	case 8829ULL: goto x86_l_227d;
	case 8834ULL: goto x86_l_2282;
	case 8839ULL: goto x86_l_2287;
	case 8844ULL: goto x86_l_228c;
	case 8849ULL: goto x86_l_2291;
	case 8854ULL: goto x86_l_2296;
	case 8856ULL: goto x86_l_2298;
	case 8858ULL: goto x86_l_229a;
	case 8864ULL: goto x86_l_22a0;
	case 8869ULL: goto x86_l_22a5;
	case 8878ULL: goto x86_l_22ae;
	case 8883ULL: goto x86_l_22b3;
	case 8889ULL: goto x86_l_22b9;
	case 8896ULL: goto x86_l_22c0;
	case 8901ULL: goto x86_l_22c5;
	case 8906ULL: goto x86_l_22ca;
	case 8915ULL: goto x86_l_22d3;
	case 8921ULL: goto x86_l_22d9;
	case 8926ULL: goto x86_l_22de;
	case 8931ULL: goto x86_l_22e3;
	case 8936ULL: goto x86_l_22e8;
	case 8941ULL: goto x86_l_22ed;
	case 8946ULL: goto x86_l_22f2;
	case 8948ULL: goto x86_l_22f4;
	case 8950ULL: goto x86_l_22f6;
	case 8956ULL: goto x86_l_22fc;
	case 8961ULL: goto x86_l_2301;
	case 8966ULL: goto x86_l_2306;
	case 8973ULL: goto x86_l_230d;
	case 8979ULL: goto x86_l_2313;
	case 8982ULL: goto x86_l_2316;
	case 8987ULL: goto x86_l_231b;
	case 8992ULL: goto x86_l_2320;
	case 8997ULL: goto x86_l_2325;
	case 9002ULL: goto x86_l_232a;
	case 9004ULL: goto x86_l_232c;
	case 9006ULL: goto x86_l_232e;
	case 9012ULL: goto x86_l_2334;
	case 9019ULL: goto x86_l_233b;
	case 9025ULL: goto x86_l_2341;
	case 9028ULL: goto x86_l_2344;
	case 9033ULL: goto x86_l_2349;
	case 9038ULL: goto x86_l_234e;
	case 9043ULL: goto x86_l_2353;
	case 9048ULL: goto x86_l_2358;
	case 9050ULL: goto x86_l_235a;
	case 9052ULL: goto x86_l_235c;
	case 9054ULL: goto x86_l_235e;
	case 9062ULL: goto x86_l_2366;
	case 9069ULL: goto x86_l_236d;
	case 9076ULL: goto x86_l_2374;
	case 9081ULL: goto x86_l_2379;
	case 9084ULL: goto x86_l_237c;
	case 9089ULL: goto x86_l_2381;
	case 9094ULL: goto x86_l_2386;
	case 9099ULL: goto x86_l_238b;
	case 9107ULL: goto x86_l_2393;
	case 9114ULL: goto x86_l_239a;
	case 9121ULL: goto x86_l_23a1;
	case 9126ULL: goto x86_l_23a6;
	case 9129ULL: goto x86_l_23a9;
	case 9134ULL: goto x86_l_23ae;
	case 9136ULL: goto x86_l_23b0;
	case 9138ULL: goto x86_l_23b2;
	case 9144ULL: goto x86_l_23b8;
	case 9147ULL: goto x86_l_23bb;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1c2f:
	/* 0x1c2f: movzx  eax,BYTE PTR [r13+0x258] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 600ULL);
x86_l_1c37:
	/* 0x1c37: shlx   rcx,QWORD PTR [rsp+0x18],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((24ULL << 32) | X86_ALU_SHL));
x86_l_1c3e:
	/* 0x1c3e: cmp    BYTE PTR [r13+0x25a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2585570312192ULL);
x86_l_1c46:
	/* 0x1c46: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_1c4b:
	/* 0x1c4b: sarx   rcx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RCX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_1c50:
	/* 0x1c50: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_1c54:
	/* 0x1c54: jmp    3174 <generic_sleepable_preload+0x3174> */
	return 12660ULL;
x86_l_1c59:
	/* 0x1c59: mov    rax,QWORD PTR [r13+0x260] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 608ULL);
x86_l_1c60:
	/* 0x1c60: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c65:
	/* 0x1c65: movzx  eax,BYTE PTR [r13+0x270] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 624ULL);
x86_l_1c6d:
	/* 0x1c6d: shlx   rcx,QWORD PTR [rsp+0x18],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((24ULL << 32) | X86_ALU_SHL));
x86_l_1c74:
	/* 0x1c74: cmp    BYTE PTR [r13+0x272],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2688649527296ULL);
x86_l_1c7c:
	/* 0x1c7c: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_1c81:
	/* 0x1c81: sarx   rcx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RCX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_1c86:
	/* 0x1c86: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_1c8a:
	/* 0x1c8a: jmp    384b <generic_sleepable_preload+0x384b> */
	return 14411ULL;
x86_l_1c8f:
	/* 0x1c8f: mov    edx,DWORD PTR [r13+0x208] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_1c96:
	/* 0x1c96: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1c9c:
	/* 0x1c9c: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1c9f:
	/* 0x1c9f: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ca4:
	/* 0x1ca4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1ca9:
	/* 0x1ca9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1cae:
	/* 0x1cae: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1cb3:
	/* 0x1cb3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cb5:
	/* 0x1cb5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1cb7:
	/* 0x1cb7: jne    1cef <generic_sleepable_preload+0x1cef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1cef;
	}
x86_l_1cb9:
	/* 0x1cb9: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1cbe:
	/* 0x1cbe: add    rcx,QWORD PTR [r13+0x200] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 512ULL);
x86_l_1cc5:
	/* 0x1cc5: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1cca:
	/* 0x1cca: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1ccf:
	/* 0x1ccf: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1cd4:
	/* 0x1cd4: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1cd9:
	/* 0x1cd9: add    rdx,QWORD PTR [r13+0x200] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 512ULL);
x86_l_1ce0:
	/* 0x1ce0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ce5:
	/* 0x1ce5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ce7:
	/* 0x1ce7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1ce9:
	/* 0x1ce9: je     1b83 <generic_sleepable_preload+0x1b83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7043ULL;
	}
x86_l_1cef:
	/* 0x1cef: movsxd rcx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_1cf2:
	/* 0x1cf2: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1cf7:
	/* 0x1cf7: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cf9:
	/* 0x1cf9: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_1cfc:
	/* 0x1cfc: cmp    WORD PTR [r13+0x76],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 506806140928ULL);
x86_l_1d02:
	/* 0x1d02: je     6287 <generic_sleepable_preload+0x6287> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25223ULL;
	}
x86_l_1d08:
	/* 0x1d08: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_1d0f:
	/* 0x1d0f: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1d12:
	/* 0x1d12: mov    eax,DWORD PTR [r13+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1d16:
	/* 0x1d16: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1d19:
	/* 0x1d19: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d1e:
	/* 0x1d1e: movzx  eax,WORD PTR [r13+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 116ULL);
x86_l_1d23:
	/* 0x1d23: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1d25:
	/* 0x1d25: je     2007 <generic_sleepable_preload+0x2007> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2007;
	}
x86_l_1d2b:
	/* 0x1d2b: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_1d2e:
	/* 0x1d2e: je     1d53 <generic_sleepable_preload+0x1d53> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d53;
	}
x86_l_1d30:
	/* 0x1d30: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d35:
	/* 0x1d35: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1d3a:
	/* 0x1d3a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1d3f:
	/* 0x1d3f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d44:
	/* 0x1d44: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d49:
	/* 0x1d49: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d4b:
	/* 0x1d4b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d4d:
	/* 0x1d4d: js     3e6b <generic_sleepable_preload+0x3e6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15979ULL;
	}
x86_l_1d53:
	/* 0x1d53: cmp    WORD PTR [r13+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_1d59:
	/* 0x1d59: je     6287 <generic_sleepable_preload+0x6287> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25223ULL;
	}
x86_l_1d5f:
	/* 0x1d5f: mov    ecx,DWORD PTR [r13+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1d63:
	/* 0x1d63: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1d68:
	/* 0x1d68: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d6d:
	/* 0x1d6d: cmp    WORD PTR [r13+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_1d73:
	/* 0x1d73: je     1d98 <generic_sleepable_preload+0x1d98> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d98;
	}
x86_l_1d75:
	/* 0x1d75: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d7a:
	/* 0x1d7a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1d7f:
	/* 0x1d7f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1d84:
	/* 0x1d84: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d89:
	/* 0x1d89: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d8e:
	/* 0x1d8e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d90:
	/* 0x1d90: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d92:
	/* 0x1d92: js     540c <generic_sleepable_preload+0x540c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21516ULL;
	}
x86_l_1d98:
	/* 0x1d98: cmp    WORD PTR [r13+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_1da1:
	/* 0x1da1: je     6287 <generic_sleepable_preload+0x6287> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25223ULL;
	}
x86_l_1da7:
	/* 0x1da7: mov    ecx,DWORD PTR [r13+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1dae:
	/* 0x1dae: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1db3:
	/* 0x1db3: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1db8:
	/* 0x1db8: cmp    WORD PTR [r13+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_1dc1:
	/* 0x1dc1: je     1de6 <generic_sleepable_preload+0x1de6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1de6;
	}
x86_l_1dc3:
	/* 0x1dc3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1dc8:
	/* 0x1dc8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1dcd:
	/* 0x1dcd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1dd2:
	/* 0x1dd2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1dd7:
	/* 0x1dd7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ddc:
	/* 0x1ddc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dde:
	/* 0x1dde: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1de0:
	/* 0x1de0: js     60f3 <generic_sleepable_preload+0x60f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24819ULL;
	}
x86_l_1de6:
	/* 0x1de6: cmp    WORD PTR [r13+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_1def:
	/* 0x1def: je     6287 <generic_sleepable_preload+0x6287> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25223ULL;
	}
x86_l_1df5:
	/* 0x1df5: mov    ecx,DWORD PTR [r13+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1dfc:
	/* 0x1dfc: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1e01:
	/* 0x1e01: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e06:
	/* 0x1e06: cmp    WORD PTR [r13+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_1e0f:
	/* 0x1e0f: je     1e34 <generic_sleepable_preload+0x1e34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e34;
	}
x86_l_1e11:
	/* 0x1e11: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e16:
	/* 0x1e16: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1e1b:
	/* 0x1e1b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1e20:
	/* 0x1e20: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e25:
	/* 0x1e25: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e2a:
	/* 0x1e2a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e2c:
	/* 0x1e2c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e2e:
	/* 0x1e2e: js     6157 <generic_sleepable_preload+0x6157> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24919ULL;
	}
x86_l_1e34:
	/* 0x1e34: cmp    WORD PTR [r13+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_1e3d:
	/* 0x1e3d: je     6287 <generic_sleepable_preload+0x6287> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25223ULL;
	}
x86_l_1e43:
	/* 0x1e43: mov    ecx,DWORD PTR [r13+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1e4a:
	/* 0x1e4a: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1e4f:
	/* 0x1e4f: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e54:
	/* 0x1e54: cmp    WORD PTR [r13+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_1e5d:
	/* 0x1e5d: je     1e82 <generic_sleepable_preload+0x1e82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e82;
	}
x86_l_1e5f:
	/* 0x1e5f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e64:
	/* 0x1e64: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1e69:
	/* 0x1e69: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1e6e:
	/* 0x1e6e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e73:
	/* 0x1e73: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e78:
	/* 0x1e78: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e7a:
	/* 0x1e7a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e7c:
	/* 0x1e7c: js     61bb <generic_sleepable_preload+0x61bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25019ULL;
	}
x86_l_1e82:
	/* 0x1e82: cmp    WORD PTR [r13+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_1e8b:
	/* 0x1e8b: je     6287 <generic_sleepable_preload+0x6287> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25223ULL;
	}
x86_l_1e91:
	/* 0x1e91: mov    ecx,DWORD PTR [r13+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1e98:
	/* 0x1e98: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1e9d:
	/* 0x1e9d: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ea2:
	/* 0x1ea2: cmp    WORD PTR [r13+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_1eab:
	/* 0x1eab: je     1ed0 <generic_sleepable_preload+0x1ed0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ed0;
	}
x86_l_1ead:
	/* 0x1ead: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1eb2:
	/* 0x1eb2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1eb7:
	/* 0x1eb7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1ebc:
	/* 0x1ebc: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ec1:
	/* 0x1ec1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ec6:
	/* 0x1ec6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ec8:
	/* 0x1ec8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1eca:
	/* 0x1eca: js     621f <generic_sleepable_preload+0x621f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25119ULL;
	}
x86_l_1ed0:
	/* 0x1ed0: cmp    WORD PTR [r13+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_1ed9:
	/* 0x1ed9: je     6287 <generic_sleepable_preload+0x6287> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25223ULL;
	}
x86_l_1edf:
	/* 0x1edf: mov    ecx,DWORD PTR [r13+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1ee6:
	/* 0x1ee6: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1eeb:
	/* 0x1eeb: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ef0:
	/* 0x1ef0: cmp    WORD PTR [r13+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_1ef9:
	/* 0x1ef9: je     1f1e <generic_sleepable_preload+0x1f1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f1e;
	}
x86_l_1efb:
	/* 0x1efb: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f00:
	/* 0x1f00: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1f05:
	/* 0x1f05: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1f0a:
	/* 0x1f0a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f0f:
	/* 0x1f0f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f14:
	/* 0x1f14: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f16:
	/* 0x1f16: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f18:
	/* 0x1f18: js     6280 <generic_sleepable_preload+0x6280> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25216ULL;
	}
x86_l_1f1e:
	/* 0x1f1e: cmp    WORD PTR [r13+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_1f27:
	/* 0x1f27: je     6287 <generic_sleepable_preload+0x6287> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25223ULL;
	}
x86_l_1f2d:
	/* 0x1f2d: mov    ecx,DWORD PTR [r13+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1f34:
	/* 0x1f34: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1f39:
	/* 0x1f39: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f3e:
	/* 0x1f3e: cmp    WORD PTR [r13+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_1f47:
	/* 0x1f47: je     1f6c <generic_sleepable_preload+0x1f6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f6c;
	}
x86_l_1f49:
	/* 0x1f49: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f4e:
	/* 0x1f4e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1f53:
	/* 0x1f53: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1f58:
	/* 0x1f58: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f5d:
	/* 0x1f5d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f62:
	/* 0x1f62: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f64:
	/* 0x1f64: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f66:
	/* 0x1f66: js     68d0 <generic_sleepable_preload+0x68d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26832ULL;
	}
x86_l_1f6c:
	/* 0x1f6c: cmp    WORD PTR [r13+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_1f75:
	/* 0x1f75: je     6287 <generic_sleepable_preload+0x6287> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25223ULL;
	}
x86_l_1f7b:
	/* 0x1f7b: mov    ecx,DWORD PTR [r13+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1f82:
	/* 0x1f82: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1f87:
	/* 0x1f87: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f8c:
	/* 0x1f8c: cmp    WORD PTR [r13+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_1f95:
	/* 0x1f95: je     1fba <generic_sleepable_preload+0x1fba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fba;
	}
x86_l_1f97:
	/* 0x1f97: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f9c:
	/* 0x1f9c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1fa1:
	/* 0x1fa1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1fa6:
	/* 0x1fa6: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fab:
	/* 0x1fab: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1fb0:
	/* 0x1fb0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fb2:
	/* 0x1fb2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1fb4:
	/* 0x1fb4: js     693d <generic_sleepable_preload+0x693d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26941ULL;
	}
x86_l_1fba:
	/* 0x1fba: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1fbf:
	/* 0x1fbf: cmp    WORD PTR [r13+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_1fc8:
	/* 0x1fc8: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1fcd:
	/* 0x1fcd: je     6287 <generic_sleepable_preload+0x6287> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25223ULL;
	}
x86_l_1fd3:
	/* 0x1fd3: mov    ecx,DWORD PTR [r13+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1fda:
	/* 0x1fda: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1fdf:
	/* 0x1fdf: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fe4:
	/* 0x1fe4: cmp    WORD PTR [r13+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_1fed:
	/* 0x1fed: je     6287 <generic_sleepable_preload+0x6287> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25223ULL;
	}
x86_l_1ff3:
	/* 0x1ff3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ff8:
	/* 0x1ff8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1ffd:
	/* 0x1ffd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2002:
	/* 0x2002: jmp    22e8 <generic_sleepable_preload+0x22e8> */
	goto x86_l_22e8;
x86_l_2007:
	/* 0x2007: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_200a:
	/* 0x200a: je     202f <generic_sleepable_preload+0x202f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_202f;
	}
x86_l_200c:
	/* 0x200c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2011:
	/* 0x2011: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2016:
	/* 0x2016: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_201b:
	/* 0x201b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2020:
	/* 0x2020: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2025:
	/* 0x2025: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2027:
	/* 0x2027: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2029:
	/* 0x2029: js     3e6b <generic_sleepable_preload+0x3e6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15979ULL;
	}
x86_l_202f:
	/* 0x202f: cmp    WORD PTR [r13+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_2035:
	/* 0x2035: je     6287 <generic_sleepable_preload+0x6287> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25223ULL;
	}
x86_l_203b:
	/* 0x203b: mov    ecx,DWORD PTR [r13+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_203f:
	/* 0x203f: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2044:
	/* 0x2044: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2049:
	/* 0x2049: cmp    WORD PTR [r13+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_204f:
	/* 0x204f: je     2074 <generic_sleepable_preload+0x2074> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2074;
	}
x86_l_2051:
	/* 0x2051: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2056:
	/* 0x2056: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_205b:
	/* 0x205b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2060:
	/* 0x2060: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2065:
	/* 0x2065: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_206a:
	/* 0x206a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_206c:
	/* 0x206c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_206e:
	/* 0x206e: js     540c <generic_sleepable_preload+0x540c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21516ULL;
	}
x86_l_2074:
	/* 0x2074: cmp    WORD PTR [r13+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_207d:
	/* 0x207d: je     6287 <generic_sleepable_preload+0x6287> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25223ULL;
	}
x86_l_2083:
	/* 0x2083: mov    ecx,DWORD PTR [r13+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_208a:
	/* 0x208a: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_208f:
	/* 0x208f: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2094:
	/* 0x2094: cmp    WORD PTR [r13+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_209d:
	/* 0x209d: je     20c2 <generic_sleepable_preload+0x20c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20c2;
	}
x86_l_209f:
	/* 0x209f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20a4:
	/* 0x20a4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_20a9:
	/* 0x20a9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_20ae:
	/* 0x20ae: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20b3:
	/* 0x20b3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20b8:
	/* 0x20b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20ba:
	/* 0x20ba: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20bc:
	/* 0x20bc: js     60f3 <generic_sleepable_preload+0x60f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24819ULL;
	}
x86_l_20c2:
	/* 0x20c2: cmp    WORD PTR [r13+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_20cb:
	/* 0x20cb: je     6287 <generic_sleepable_preload+0x6287> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25223ULL;
	}
x86_l_20d1:
	/* 0x20d1: mov    ecx,DWORD PTR [r13+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_20d8:
	/* 0x20d8: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_20dd:
	/* 0x20dd: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20e2:
	/* 0x20e2: cmp    WORD PTR [r13+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_20eb:
	/* 0x20eb: je     2110 <generic_sleepable_preload+0x2110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2110;
	}
x86_l_20ed:
	/* 0x20ed: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20f2:
	/* 0x20f2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_20f7:
	/* 0x20f7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_20fc:
	/* 0x20fc: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2101:
	/* 0x2101: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2106:
	/* 0x2106: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2108:
	/* 0x2108: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_210a:
	/* 0x210a: js     6157 <generic_sleepable_preload+0x6157> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24919ULL;
	}
x86_l_2110:
	/* 0x2110: cmp    WORD PTR [r13+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_2119:
	/* 0x2119: je     6287 <generic_sleepable_preload+0x6287> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25223ULL;
	}
x86_l_211f:
	/* 0x211f: mov    ecx,DWORD PTR [r13+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2126:
	/* 0x2126: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_212b:
	/* 0x212b: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2130:
	/* 0x2130: cmp    WORD PTR [r13+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_2139:
	/* 0x2139: je     215e <generic_sleepable_preload+0x215e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_215e;
	}
x86_l_213b:
	/* 0x213b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2140:
	/* 0x2140: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2145:
	/* 0x2145: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_214a:
	/* 0x214a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_214f:
	/* 0x214f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2154:
	/* 0x2154: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2156:
	/* 0x2156: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2158:
	/* 0x2158: js     61bb <generic_sleepable_preload+0x61bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25019ULL;
	}
x86_l_215e:
	/* 0x215e: cmp    WORD PTR [r13+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_2167:
	/* 0x2167: je     6287 <generic_sleepable_preload+0x6287> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25223ULL;
	}
x86_l_216d:
	/* 0x216d: mov    ecx,DWORD PTR [r13+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2174:
	/* 0x2174: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2179:
	/* 0x2179: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_217e:
	/* 0x217e: cmp    WORD PTR [r13+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_2187:
	/* 0x2187: je     21ac <generic_sleepable_preload+0x21ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21ac;
	}
x86_l_2189:
	/* 0x2189: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_218e:
	/* 0x218e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2193:
	/* 0x2193: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2198:
	/* 0x2198: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_219d:
	/* 0x219d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21a2:
	/* 0x21a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21a4:
	/* 0x21a4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_21a6:
	/* 0x21a6: js     621f <generic_sleepable_preload+0x621f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25119ULL;
	}
x86_l_21ac:
	/* 0x21ac: cmp    WORD PTR [r13+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_21b5:
	/* 0x21b5: je     6287 <generic_sleepable_preload+0x6287> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25223ULL;
	}
x86_l_21bb:
	/* 0x21bb: mov    ecx,DWORD PTR [r13+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_21c2:
	/* 0x21c2: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_21c7:
	/* 0x21c7: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21cc:
	/* 0x21cc: cmp    WORD PTR [r13+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_21d5:
	/* 0x21d5: je     21fa <generic_sleepable_preload+0x21fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21fa;
	}
x86_l_21d7:
	/* 0x21d7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21dc:
	/* 0x21dc: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_21e1:
	/* 0x21e1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_21e6:
	/* 0x21e6: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21eb:
	/* 0x21eb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21f0:
	/* 0x21f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21f2:
	/* 0x21f2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_21f4:
	/* 0x21f4: js     6280 <generic_sleepable_preload+0x6280> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25216ULL;
	}
x86_l_21fa:
	/* 0x21fa: cmp    WORD PTR [r13+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_2203:
	/* 0x2203: je     6287 <generic_sleepable_preload+0x6287> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25223ULL;
	}
x86_l_2209:
	/* 0x2209: mov    ecx,DWORD PTR [r13+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2210:
	/* 0x2210: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2215:
	/* 0x2215: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_221a:
	/* 0x221a: cmp    WORD PTR [r13+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_2223:
	/* 0x2223: je     2248 <generic_sleepable_preload+0x2248> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2248;
	}
x86_l_2225:
	/* 0x2225: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_222a:
	/* 0x222a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_222f:
	/* 0x222f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2234:
	/* 0x2234: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2239:
	/* 0x2239: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_223e:
	/* 0x223e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2240:
	/* 0x2240: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2242:
	/* 0x2242: js     69cd <generic_sleepable_preload+0x69cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27085ULL;
	}
x86_l_2248:
	/* 0x2248: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_224d:
	/* 0x224d: cmp    WORD PTR [r13+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_2256:
	/* 0x2256: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_225b:
	/* 0x225b: je     6287 <generic_sleepable_preload+0x6287> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25223ULL;
	}
x86_l_2261:
	/* 0x2261: mov    ecx,DWORD PTR [r13+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2268:
	/* 0x2268: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_226d:
	/* 0x226d: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2272:
	/* 0x2272: cmp    WORD PTR [r13+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_227b:
	/* 0x227b: je     22a0 <generic_sleepable_preload+0x22a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22a0;
	}
x86_l_227d:
	/* 0x227d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2282:
	/* 0x2282: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2287:
	/* 0x2287: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_228c:
	/* 0x228c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2291:
	/* 0x2291: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2296:
	/* 0x2296: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2298:
	/* 0x2298: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_229a:
	/* 0x229a: js     693d <generic_sleepable_preload+0x693d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26941ULL;
	}
x86_l_22a0:
	/* 0x22a0: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_22a5:
	/* 0x22a5: cmp    WORD PTR [r13+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_22ae:
	/* 0x22ae: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_22b3:
	/* 0x22b3: je     6287 <generic_sleepable_preload+0x6287> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25223ULL;
	}
x86_l_22b9:
	/* 0x22b9: mov    ecx,DWORD PTR [r13+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_22c0:
	/* 0x22c0: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_22c5:
	/* 0x22c5: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22ca:
	/* 0x22ca: cmp    WORD PTR [r13+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_22d3:
	/* 0x22d3: je     6287 <generic_sleepable_preload+0x6287> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25223ULL;
	}
x86_l_22d9:
	/* 0x22d9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22de:
	/* 0x22de: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_22e3:
	/* 0x22e3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_22e8:
	/* 0x22e8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22ed:
	/* 0x22ed: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22f2:
	/* 0x22f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22f4:
	/* 0x22f4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_22f6:
	/* 0x22f6: jns    6287 <generic_sleepable_preload+0x6287> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 25223ULL;
	}
x86_l_22fc:
	/* 0x22fc: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_2301:
	/* 0x2301: jmp    6285 <generic_sleepable_preload+0x6285> */
	return 25221ULL;
x86_l_2306:
	/* 0x2306: mov    edx,DWORD PTR [r13+0x220] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 544ULL);
x86_l_230d:
	/* 0x230d: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2313:
	/* 0x2313: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2316:
	/* 0x2316: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_231b:
	/* 0x231b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2320:
	/* 0x2320: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2325:
	/* 0x2325: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_232a:
	/* 0x232a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_232c:
	/* 0x232c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_232e:
	/* 0x232e: jne    23b8 <generic_sleepable_preload+0x23b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_23b8;
	}
x86_l_2334:
	/* 0x2334: mov    edx,DWORD PTR [r13+0x224] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 548ULL);
x86_l_233b:
	/* 0x233b: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2341:
	/* 0x2341: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2344:
	/* 0x2344: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2349:
	/* 0x2349: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_234e:
	/* 0x234e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2353:
	/* 0x2353: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2358:
	/* 0x2358: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_235a:
	/* 0x235a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_235c:
	/* 0x235c: jne    23b8 <generic_sleepable_preload+0x23b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_23b8;
	}
x86_l_235e:
	/* 0x235e: movzx  eax,BYTE PTR [r13+0x22b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 555ULL);
x86_l_2366:
	/* 0x2366: shlx   rax,QWORD PTR [rsp+0x8],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_236d:
	/* 0x236d: mov    rcx,QWORD PTR [r13+0x218] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 536ULL);
x86_l_2374:
	/* 0x2374: add    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_2379:
	/* 0x2379: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_237c:
	/* 0x237c: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2381:
	/* 0x2381: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2386:
	/* 0x2386: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_238b:
	/* 0x238b: movzx  ecx,BYTE PTR [r13+0x22b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 555ULL);
x86_l_2393:
	/* 0x2393: shlx   rcx,QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_239a:
	/* 0x239a: mov    rdx,QWORD PTR [r13+0x218] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 536ULL);
x86_l_23a1:
	/* 0x23a1: add    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_23a6:
	/* 0x23a6: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_23a9:
	/* 0x23a9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23ae:
	/* 0x23ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23b0:
	/* 0x23b0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_23b2:
	/* 0x23b2: je     1bbe <generic_sleepable_preload+0x1bbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7102ULL;
	}
x86_l_23b8:
	/* 0x23b8: movsxd rcx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_23bb:
	/* 0x23bb: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
	return 9152ULL;
}

static __noinline __u64 tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9152ULL: goto x86_l_23c0;
	case 9154ULL: goto x86_l_23c2;
	case 9157ULL: goto x86_l_23c5;
	case 9166ULL: goto x86_l_23ce;
	case 9172ULL: goto x86_l_23d4;
	case 9179ULL: goto x86_l_23db;
	case 9182ULL: goto x86_l_23de;
	case 9189ULL: goto x86_l_23e5;
	case 9192ULL: goto x86_l_23e8;
	case 9197ULL: goto x86_l_23ed;
	case 9205ULL: goto x86_l_23f5;
	case 9207ULL: goto x86_l_23f7;
	case 9213ULL: goto x86_l_23fd;
	case 9216ULL: goto x86_l_2400;
	case 9218ULL: goto x86_l_2402;
	case 9223ULL: goto x86_l_2407;
	case 9228ULL: goto x86_l_240c;
	case 9233ULL: goto x86_l_2411;
	case 9238ULL: goto x86_l_2416;
	case 9243ULL: goto x86_l_241b;
	case 9245ULL: goto x86_l_241d;
	case 9247ULL: goto x86_l_241f;
	case 9253ULL: goto x86_l_2425;
	case 9262ULL: goto x86_l_242e;
	case 9268ULL: goto x86_l_2434;
	case 9275ULL: goto x86_l_243b;
	case 9280ULL: goto x86_l_2440;
	case 9285ULL: goto x86_l_2445;
	case 9294ULL: goto x86_l_244e;
	case 9296ULL: goto x86_l_2450;
	case 9301ULL: goto x86_l_2455;
	case 9306ULL: goto x86_l_245a;
	case 9311ULL: goto x86_l_245f;
	case 9316ULL: goto x86_l_2464;
	case 9321ULL: goto x86_l_2469;
	case 9323ULL: goto x86_l_246b;
	case 9325ULL: goto x86_l_246d;
	case 9331ULL: goto x86_l_2473;
	case 9340ULL: goto x86_l_247c;
	case 9346ULL: goto x86_l_2482;
	case 9353ULL: goto x86_l_2489;
	case 9358ULL: goto x86_l_248e;
	case 9363ULL: goto x86_l_2493;
	case 9372ULL: goto x86_l_249c;
	case 9374ULL: goto x86_l_249e;
	case 9379ULL: goto x86_l_24a3;
	case 9384ULL: goto x86_l_24a8;
	case 9389ULL: goto x86_l_24ad;
	case 9394ULL: goto x86_l_24b2;
	case 9399ULL: goto x86_l_24b7;
	case 9401ULL: goto x86_l_24b9;
	case 9403ULL: goto x86_l_24bb;
	case 9409ULL: goto x86_l_24c1;
	case 9418ULL: goto x86_l_24ca;
	case 9424ULL: goto x86_l_24d0;
	case 9431ULL: goto x86_l_24d7;
	case 9436ULL: goto x86_l_24dc;
	case 9441ULL: goto x86_l_24e1;
	case 9450ULL: goto x86_l_24ea;
	case 9452ULL: goto x86_l_24ec;
	case 9457ULL: goto x86_l_24f1;
	case 9462ULL: goto x86_l_24f6;
	case 9467ULL: goto x86_l_24fb;
	case 9472ULL: goto x86_l_2500;
	case 9477ULL: goto x86_l_2505;
	case 9479ULL: goto x86_l_2507;
	case 9481ULL: goto x86_l_2509;
	case 9487ULL: goto x86_l_250f;
	case 9496ULL: goto x86_l_2518;
	case 9502ULL: goto x86_l_251e;
	case 9509ULL: goto x86_l_2525;
	case 9514ULL: goto x86_l_252a;
	case 9519ULL: goto x86_l_252f;
	case 9528ULL: goto x86_l_2538;
	case 9530ULL: goto x86_l_253a;
	case 9535ULL: goto x86_l_253f;
	case 9540ULL: goto x86_l_2544;
	case 9545ULL: goto x86_l_2549;
	case 9550ULL: goto x86_l_254e;
	case 9555ULL: goto x86_l_2553;
	case 9557ULL: goto x86_l_2555;
	case 9559ULL: goto x86_l_2557;
	case 9565ULL: goto x86_l_255d;
	case 9574ULL: goto x86_l_2566;
	case 9580ULL: goto x86_l_256c;
	case 9587ULL: goto x86_l_2573;
	case 9592ULL: goto x86_l_2578;
	case 9597ULL: goto x86_l_257d;
	case 9606ULL: goto x86_l_2586;
	case 9608ULL: goto x86_l_2588;
	case 9613ULL: goto x86_l_258d;
	case 9618ULL: goto x86_l_2592;
	case 9623ULL: goto x86_l_2597;
	case 9628ULL: goto x86_l_259c;
	case 9633ULL: goto x86_l_25a1;
	case 9635ULL: goto x86_l_25a3;
	case 9637ULL: goto x86_l_25a5;
	case 9643ULL: goto x86_l_25ab;
	case 9652ULL: goto x86_l_25b4;
	case 9658ULL: goto x86_l_25ba;
	case 9665ULL: goto x86_l_25c1;
	case 9670ULL: goto x86_l_25c6;
	case 9675ULL: goto x86_l_25cb;
	case 9684ULL: goto x86_l_25d4;
	case 9686ULL: goto x86_l_25d6;
	case 9691ULL: goto x86_l_25db;
	case 9696ULL: goto x86_l_25e0;
	case 9701ULL: goto x86_l_25e5;
	case 9706ULL: goto x86_l_25ea;
	case 9711ULL: goto x86_l_25ef;
	case 9713ULL: goto x86_l_25f1;
	case 9715ULL: goto x86_l_25f3;
	case 9721ULL: goto x86_l_25f9;
	case 9730ULL: goto x86_l_2602;
	case 9736ULL: goto x86_l_2608;
	case 9743ULL: goto x86_l_260f;
	case 9748ULL: goto x86_l_2614;
	case 9753ULL: goto x86_l_2619;
	case 9762ULL: goto x86_l_2622;
	case 9764ULL: goto x86_l_2624;
	case 9769ULL: goto x86_l_2629;
	case 9774ULL: goto x86_l_262e;
	case 9779ULL: goto x86_l_2633;
	case 9784ULL: goto x86_l_2638;
	case 9789ULL: goto x86_l_263d;
	case 9791ULL: goto x86_l_263f;
	case 9793ULL: goto x86_l_2641;
	case 9799ULL: goto x86_l_2647;
	case 9808ULL: goto x86_l_2650;
	case 9814ULL: goto x86_l_2656;
	case 9821ULL: goto x86_l_265d;
	case 9826ULL: goto x86_l_2662;
	case 9831ULL: goto x86_l_2667;
	case 9840ULL: goto x86_l_2670;
	case 9842ULL: goto x86_l_2672;
	case 9847ULL: goto x86_l_2677;
	case 9852ULL: goto x86_l_267c;
	case 9857ULL: goto x86_l_2681;
	case 9862ULL: goto x86_l_2686;
	case 9867ULL: goto x86_l_268b;
	case 9869ULL: goto x86_l_268d;
	case 9871ULL: goto x86_l_268f;
	case 9877ULL: goto x86_l_2695;
	case 9882ULL: goto x86_l_269a;
	case 9891ULL: goto x86_l_26a3;
	case 9897ULL: goto x86_l_26a9;
	case 9904ULL: goto x86_l_26b0;
	case 9909ULL: goto x86_l_26b5;
	case 9914ULL: goto x86_l_26ba;
	case 9923ULL: goto x86_l_26c3;
	case 9929ULL: goto x86_l_26c9;
	case 9934ULL: goto x86_l_26ce;
	case 9939ULL: goto x86_l_26d3;
	case 9944ULL: goto x86_l_26d8;
	case 9949ULL: goto x86_l_26dd;
	case 9952ULL: goto x86_l_26e0;
	case 9954ULL: goto x86_l_26e2;
	case 9959ULL: goto x86_l_26e7;
	case 9964ULL: goto x86_l_26ec;
	case 9969ULL: goto x86_l_26f1;
	case 9974ULL: goto x86_l_26f6;
	case 9979ULL: goto x86_l_26fb;
	case 9981ULL: goto x86_l_26fd;
	case 9983ULL: goto x86_l_26ff;
	case 9989ULL: goto x86_l_2705;
	case 9998ULL: goto x86_l_270e;
	case 10004ULL: goto x86_l_2714;
	case 10011ULL: goto x86_l_271b;
	case 10016ULL: goto x86_l_2720;
	case 10021ULL: goto x86_l_2725;
	case 10030ULL: goto x86_l_272e;
	case 10032ULL: goto x86_l_2730;
	case 10037ULL: goto x86_l_2735;
	case 10042ULL: goto x86_l_273a;
	case 10047ULL: goto x86_l_273f;
	case 10052ULL: goto x86_l_2744;
	case 10057ULL: goto x86_l_2749;
	case 10059ULL: goto x86_l_274b;
	case 10061ULL: goto x86_l_274d;
	case 10067ULL: goto x86_l_2753;
	case 10076ULL: goto x86_l_275c;
	case 10082ULL: goto x86_l_2762;
	case 10089ULL: goto x86_l_2769;
	case 10094ULL: goto x86_l_276e;
	case 10099ULL: goto x86_l_2773;
	case 10108ULL: goto x86_l_277c;
	case 10110ULL: goto x86_l_277e;
	case 10115ULL: goto x86_l_2783;
	case 10120ULL: goto x86_l_2788;
	case 10125ULL: goto x86_l_278d;
	case 10130ULL: goto x86_l_2792;
	case 10135ULL: goto x86_l_2797;
	case 10137ULL: goto x86_l_2799;
	case 10139ULL: goto x86_l_279b;
	case 10145ULL: goto x86_l_27a1;
	case 10154ULL: goto x86_l_27aa;
	case 10160ULL: goto x86_l_27b0;
	case 10167ULL: goto x86_l_27b7;
	case 10172ULL: goto x86_l_27bc;
	case 10177ULL: goto x86_l_27c1;
	case 10186ULL: goto x86_l_27ca;
	case 10188ULL: goto x86_l_27cc;
	case 10193ULL: goto x86_l_27d1;
	case 10198ULL: goto x86_l_27d6;
	case 10203ULL: goto x86_l_27db;
	case 10208ULL: goto x86_l_27e0;
	case 10213ULL: goto x86_l_27e5;
	case 10215ULL: goto x86_l_27e7;
	case 10217ULL: goto x86_l_27e9;
	case 10223ULL: goto x86_l_27ef;
	case 10232ULL: goto x86_l_27f8;
	case 10238ULL: goto x86_l_27fe;
	case 10245ULL: goto x86_l_2805;
	case 10250ULL: goto x86_l_280a;
	case 10255ULL: goto x86_l_280f;
	case 10264ULL: goto x86_l_2818;
	case 10266ULL: goto x86_l_281a;
	case 10271ULL: goto x86_l_281f;
	case 10276ULL: goto x86_l_2824;
	case 10281ULL: goto x86_l_2829;
	case 10286ULL: goto x86_l_282e;
	case 10291ULL: goto x86_l_2833;
	case 10293ULL: goto x86_l_2835;
	case 10295ULL: goto x86_l_2837;
	case 10301ULL: goto x86_l_283d;
	case 10310ULL: goto x86_l_2846;
	case 10316ULL: goto x86_l_284c;
	case 10323ULL: goto x86_l_2853;
	case 10328ULL: goto x86_l_2858;
	case 10333ULL: goto x86_l_285d;
	case 10342ULL: goto x86_l_2866;
	case 10344ULL: goto x86_l_2868;
	case 10349ULL: goto x86_l_286d;
	case 10354ULL: goto x86_l_2872;
	case 10359ULL: goto x86_l_2877;
	case 10364ULL: goto x86_l_287c;
	case 10369ULL: goto x86_l_2881;
	case 10371ULL: goto x86_l_2883;
	case 10373ULL: goto x86_l_2885;
	case 10379ULL: goto x86_l_288b;
	case 10388ULL: goto x86_l_2894;
	case 10394ULL: goto x86_l_289a;
	case 10401ULL: goto x86_l_28a1;
	case 10406ULL: goto x86_l_28a6;
	case 10411ULL: goto x86_l_28ab;
	case 10420ULL: goto x86_l_28b4;
	case 10422ULL: goto x86_l_28b6;
	case 10427ULL: goto x86_l_28bb;
	case 10432ULL: goto x86_l_28c0;
	case 10437ULL: goto x86_l_28c5;
	case 10442ULL: goto x86_l_28ca;
	case 10447ULL: goto x86_l_28cf;
	case 10449ULL: goto x86_l_28d1;
	case 10451ULL: goto x86_l_28d3;
	case 10457ULL: goto x86_l_28d9;
	case 10466ULL: goto x86_l_28e2;
	case 10472ULL: goto x86_l_28e8;
	case 10479ULL: goto x86_l_28ef;
	case 10484ULL: goto x86_l_28f4;
	case 10489ULL: goto x86_l_28f9;
	case 10498ULL: goto x86_l_2902;
	case 10500ULL: goto x86_l_2904;
	case 10505ULL: goto x86_l_2909;
	case 10510ULL: goto x86_l_290e;
	case 10515ULL: goto x86_l_2913;
	case 10520ULL: goto x86_l_2918;
	case 10525ULL: goto x86_l_291d;
	case 10527ULL: goto x86_l_291f;
	case 10529ULL: goto x86_l_2921;
	case 10535ULL: goto x86_l_2927;
	case 10540ULL: goto x86_l_292c;
	case 10549ULL: goto x86_l_2935;
	case 10555ULL: goto x86_l_293b;
	case 10562ULL: goto x86_l_2942;
	case 10567ULL: goto x86_l_2947;
	case 10572ULL: goto x86_l_294c;
	case 10581ULL: goto x86_l_2955;
	case 10583ULL: goto x86_l_2957;
	case 10588ULL: goto x86_l_295c;
	case 10593ULL: goto x86_l_2961;
	case 10598ULL: goto x86_l_2966;
	case 10603ULL: goto x86_l_296b;
	case 10608ULL: goto x86_l_2970;
	case 10610ULL: goto x86_l_2972;
	case 10612ULL: goto x86_l_2974;
	case 10618ULL: goto x86_l_297a;
	case 10623ULL: goto x86_l_297f;
	case 10632ULL: goto x86_l_2988;
	case 10638ULL: goto x86_l_298e;
	case 10645ULL: goto x86_l_2995;
	case 10650ULL: goto x86_l_299a;
	case 10655ULL: goto x86_l_299f;
	case 10664ULL: goto x86_l_29a8;
	case 10670ULL: goto x86_l_29ae;
	case 10675ULL: goto x86_l_29b3;
	case 10680ULL: goto x86_l_29b8;
	case 10685ULL: goto x86_l_29bd;
	case 10690ULL: goto x86_l_29c2;
	case 10695ULL: goto x86_l_29c7;
	case 10697ULL: goto x86_l_29c9;
	case 10699ULL: goto x86_l_29cb;
	case 10705ULL: goto x86_l_29d1;
	case 10710ULL: goto x86_l_29d6;
	case 10715ULL: goto x86_l_29db;
	case 10722ULL: goto x86_l_29e2;
	case 10728ULL: goto x86_l_29e8;
	case 10731ULL: goto x86_l_29eb;
	case 10736ULL: goto x86_l_29f0;
	case 10741ULL: goto x86_l_29f5;
	case 10746ULL: goto x86_l_29fa;
	case 10751ULL: goto x86_l_29ff;
	case 10753ULL: goto x86_l_2a01;
	case 10755ULL: goto x86_l_2a03;
	case 10761ULL: goto x86_l_2a09;
	case 10768ULL: goto x86_l_2a10;
	case 10774ULL: goto x86_l_2a16;
	case 10777ULL: goto x86_l_2a19;
	case 10782ULL: goto x86_l_2a1e;
	case 10787ULL: goto x86_l_2a23;
	case 10792ULL: goto x86_l_2a28;
	case 10797ULL: goto x86_l_2a2d;
	case 10799ULL: goto x86_l_2a2f;
	case 10801ULL: goto x86_l_2a31;
	case 10803ULL: goto x86_l_2a33;
	case 10811ULL: goto x86_l_2a3b;
	case 10818ULL: goto x86_l_2a42;
	case 10825ULL: goto x86_l_2a49;
	case 10830ULL: goto x86_l_2a4e;
	case 10833ULL: goto x86_l_2a51;
	case 10838ULL: goto x86_l_2a56;
	case 10843ULL: goto x86_l_2a5b;
	case 10848ULL: goto x86_l_2a60;
	case 10856ULL: goto x86_l_2a68;
	case 10863ULL: goto x86_l_2a6f;
	case 10870ULL: goto x86_l_2a76;
	case 10875ULL: goto x86_l_2a7b;
	case 10878ULL: goto x86_l_2a7e;
	case 10883ULL: goto x86_l_2a83;
	case 10885ULL: goto x86_l_2a85;
	case 10887ULL: goto x86_l_2a87;
	case 10893ULL: goto x86_l_2a8d;
	case 10896ULL: goto x86_l_2a90;
	case 10901ULL: goto x86_l_2a95;
	case 10903ULL: goto x86_l_2a97;
	case 10906ULL: goto x86_l_2a9a;
	case 10915ULL: goto x86_l_2aa3;
	case 10921ULL: goto x86_l_2aa9;
	case 10928ULL: goto x86_l_2ab0;
	case 10931ULL: goto x86_l_2ab3;
	case 10938ULL: goto x86_l_2aba;
	case 10941ULL: goto x86_l_2abd;
	case 10946ULL: goto x86_l_2ac2;
	case 10954ULL: goto x86_l_2aca;
	case 10956ULL: goto x86_l_2acc;
	case 10962ULL: goto x86_l_2ad2;
	case 10965ULL: goto x86_l_2ad5;
	case 10967ULL: goto x86_l_2ad7;
	case 10972ULL: goto x86_l_2adc;
	case 10977ULL: goto x86_l_2ae1;
	case 10982ULL: goto x86_l_2ae6;
	case 10987ULL: goto x86_l_2aeb;
	case 10992ULL: goto x86_l_2af0;
	case 10994ULL: goto x86_l_2af2;
	case 10996ULL: goto x86_l_2af4;
	case 11002ULL: goto x86_l_2afa;
	case 11011ULL: goto x86_l_2b03;
	case 11017ULL: goto x86_l_2b09;
	case 11024ULL: goto x86_l_2b10;
	case 11029ULL: goto x86_l_2b15;
	case 11034ULL: goto x86_l_2b1a;
	case 11043ULL: goto x86_l_2b23;
	case 11045ULL: goto x86_l_2b25;
	case 11050ULL: goto x86_l_2b2a;
	case 11055ULL: goto x86_l_2b2f;
	case 11060ULL: goto x86_l_2b34;
	case 11065ULL: goto x86_l_2b39;
	case 11070ULL: goto x86_l_2b3e;
	case 11072ULL: goto x86_l_2b40;
	case 11074ULL: goto x86_l_2b42;
	case 11080ULL: goto x86_l_2b48;
	case 11089ULL: goto x86_l_2b51;
	case 11095ULL: goto x86_l_2b57;
	case 11102ULL: goto x86_l_2b5e;
	case 11107ULL: goto x86_l_2b63;
	default: return 0xffffffffffffffffULL;
	}
x86_l_23c0:
	/* 0x23c0: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_23c2:
	/* 0x23c2: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_23c5:
	/* 0x23c5: cmp    WORD PTR [r13+0xc6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 850403524608ULL);
x86_l_23ce:
	/* 0x23ce: je     6314 <generic_sleepable_preload+0x6314> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25364ULL;
	}
x86_l_23d4:
	/* 0x23d4: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_23db:
	/* 0x23db: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_23de:
	/* 0x23de: mov    eax,DWORD PTR [r13+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_23e5:
	/* 0x23e5: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_23e8:
	/* 0x23e8: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23ed:
	/* 0x23ed: movzx  eax,WORD PTR [r13+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 196ULL);
x86_l_23f5:
	/* 0x23f5: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_23f7:
	/* 0x23f7: je     26dd <generic_sleepable_preload+0x26dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26dd;
	}
x86_l_23fd:
	/* 0x23fd: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_2400:
	/* 0x2400: je     2425 <generic_sleepable_preload+0x2425> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2425;
	}
x86_l_2402:
	/* 0x2402: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2407:
	/* 0x2407: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_240c:
	/* 0x240c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2411:
	/* 0x2411: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2416:
	/* 0x2416: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_241b:
	/* 0x241b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_241d:
	/* 0x241d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_241f:
	/* 0x241f: js     3e75 <generic_sleepable_preload+0x3e75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15989ULL;
	}
x86_l_2425:
	/* 0x2425: cmp    WORD PTR [r13+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_242e:
	/* 0x242e: je     6314 <generic_sleepable_preload+0x6314> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25364ULL;
	}
x86_l_2434:
	/* 0x2434: mov    ecx,DWORD PTR [r13+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_243b:
	/* 0x243b: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2440:
	/* 0x2440: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2445:
	/* 0x2445: cmp    WORD PTR [r13+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_244e:
	/* 0x244e: je     2473 <generic_sleepable_preload+0x2473> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2473;
	}
x86_l_2450:
	/* 0x2450: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2455:
	/* 0x2455: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_245a:
	/* 0x245a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_245f:
	/* 0x245f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2464:
	/* 0x2464: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2469:
	/* 0x2469: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_246b:
	/* 0x246b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_246d:
	/* 0x246d: js     5416 <generic_sleepable_preload+0x5416> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21526ULL;
	}
x86_l_2473:
	/* 0x2473: cmp    WORD PTR [r13+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_247c:
	/* 0x247c: je     6314 <generic_sleepable_preload+0x6314> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25364ULL;
	}
x86_l_2482:
	/* 0x2482: mov    ecx,DWORD PTR [r13+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_2489:
	/* 0x2489: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_248e:
	/* 0x248e: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2493:
	/* 0x2493: cmp    WORD PTR [r13+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_249c:
	/* 0x249c: je     24c1 <generic_sleepable_preload+0x24c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24c1;
	}
x86_l_249e:
	/* 0x249e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24a3:
	/* 0x24a3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_24a8:
	/* 0x24a8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_24ad:
	/* 0x24ad: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24b2:
	/* 0x24b2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24b7:
	/* 0x24b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24b9:
	/* 0x24b9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24bb:
	/* 0x24bb: js     60fd <generic_sleepable_preload+0x60fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24829ULL;
	}
x86_l_24c1:
	/* 0x24c1: cmp    WORD PTR [r13+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_24ca:
	/* 0x24ca: je     6314 <generic_sleepable_preload+0x6314> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25364ULL;
	}
x86_l_24d0:
	/* 0x24d0: mov    ecx,DWORD PTR [r13+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_24d7:
	/* 0x24d7: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_24dc:
	/* 0x24dc: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24e1:
	/* 0x24e1: cmp    WORD PTR [r13+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_24ea:
	/* 0x24ea: je     250f <generic_sleepable_preload+0x250f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_250f;
	}
x86_l_24ec:
	/* 0x24ec: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24f1:
	/* 0x24f1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_24f6:
	/* 0x24f6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_24fb:
	/* 0x24fb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2500:
	/* 0x2500: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2505:
	/* 0x2505: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2507:
	/* 0x2507: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2509:
	/* 0x2509: js     6161 <generic_sleepable_preload+0x6161> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24929ULL;
	}
x86_l_250f:
	/* 0x250f: cmp    WORD PTR [r13+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_2518:
	/* 0x2518: je     6314 <generic_sleepable_preload+0x6314> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25364ULL;
	}
x86_l_251e:
	/* 0x251e: mov    ecx,DWORD PTR [r13+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_2525:
	/* 0x2525: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_252a:
	/* 0x252a: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_252f:
	/* 0x252f: cmp    WORD PTR [r13+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_2538:
	/* 0x2538: je     255d <generic_sleepable_preload+0x255d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_255d;
	}
x86_l_253a:
	/* 0x253a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_253f:
	/* 0x253f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2544:
	/* 0x2544: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2549:
	/* 0x2549: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_254e:
	/* 0x254e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2553:
	/* 0x2553: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2555:
	/* 0x2555: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2557:
	/* 0x2557: js     61c5 <generic_sleepable_preload+0x61c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25029ULL;
	}
x86_l_255d:
	/* 0x255d: cmp    WORD PTR [r13+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_2566:
	/* 0x2566: je     6314 <generic_sleepable_preload+0x6314> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25364ULL;
	}
x86_l_256c:
	/* 0x256c: mov    ecx,DWORD PTR [r13+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_2573:
	/* 0x2573: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2578:
	/* 0x2578: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_257d:
	/* 0x257d: cmp    WORD PTR [r13+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_2586:
	/* 0x2586: je     25ab <generic_sleepable_preload+0x25ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25ab;
	}
x86_l_2588:
	/* 0x2588: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_258d:
	/* 0x258d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2592:
	/* 0x2592: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2597:
	/* 0x2597: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_259c:
	/* 0x259c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_25a1:
	/* 0x25a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25a3:
	/* 0x25a3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_25a5:
	/* 0x25a5: js     6226 <generic_sleepable_preload+0x6226> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25126ULL;
	}
x86_l_25ab:
	/* 0x25ab: cmp    WORD PTR [r13+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_25b4:
	/* 0x25b4: je     6314 <generic_sleepable_preload+0x6314> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25364ULL;
	}
x86_l_25ba:
	/* 0x25ba: mov    ecx,DWORD PTR [r13+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_25c1:
	/* 0x25c1: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_25c6:
	/* 0x25c6: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25cb:
	/* 0x25cb: cmp    WORD PTR [r13+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_25d4:
	/* 0x25d4: je     25f9 <generic_sleepable_preload+0x25f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25f9;
	}
x86_l_25d6:
	/* 0x25d6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25db:
	/* 0x25db: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_25e0:
	/* 0x25e0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_25e5:
	/* 0x25e5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25ea:
	/* 0x25ea: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_25ef:
	/* 0x25ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25f1:
	/* 0x25f1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_25f3:
	/* 0x25f3: js     630d <generic_sleepable_preload+0x630d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25357ULL;
	}
x86_l_25f9:
	/* 0x25f9: cmp    WORD PTR [r13+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_2602:
	/* 0x2602: je     6314 <generic_sleepable_preload+0x6314> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25364ULL;
	}
x86_l_2608:
	/* 0x2608: mov    ecx,DWORD PTR [r13+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_260f:
	/* 0x260f: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2614:
	/* 0x2614: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2619:
	/* 0x2619: cmp    WORD PTR [r13+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_2622:
	/* 0x2622: je     2647 <generic_sleepable_preload+0x2647> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2647;
	}
x86_l_2624:
	/* 0x2624: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2629:
	/* 0x2629: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_262e:
	/* 0x262e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2633:
	/* 0x2633: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2638:
	/* 0x2638: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_263d:
	/* 0x263d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_263f:
	/* 0x263f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2641:
	/* 0x2641: js     68dc <generic_sleepable_preload+0x68dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26844ULL;
	}
x86_l_2647:
	/* 0x2647: cmp    WORD PTR [r13+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_2650:
	/* 0x2650: je     6314 <generic_sleepable_preload+0x6314> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25364ULL;
	}
x86_l_2656:
	/* 0x2656: mov    ecx,DWORD PTR [r13+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_265d:
	/* 0x265d: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2662:
	/* 0x2662: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2667:
	/* 0x2667: cmp    WORD PTR [r13+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_2670:
	/* 0x2670: je     2695 <generic_sleepable_preload+0x2695> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2695;
	}
x86_l_2672:
	/* 0x2672: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2677:
	/* 0x2677: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_267c:
	/* 0x267c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2681:
	/* 0x2681: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2686:
	/* 0x2686: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_268b:
	/* 0x268b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_268d:
	/* 0x268d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_268f:
	/* 0x268f: js     6949 <generic_sleepable_preload+0x6949> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26953ULL;
	}
x86_l_2695:
	/* 0x2695: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_269a:
	/* 0x269a: cmp    WORD PTR [r13+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_26a3:
	/* 0x26a3: je     6314 <generic_sleepable_preload+0x6314> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25364ULL;
	}
x86_l_26a9:
	/* 0x26a9: mov    ecx,DWORD PTR [r13+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_26b0:
	/* 0x26b0: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_26b5:
	/* 0x26b5: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26ba:
	/* 0x26ba: cmp    WORD PTR [r13+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_26c3:
	/* 0x26c3: je     6314 <generic_sleepable_preload+0x6314> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25364ULL;
	}
x86_l_26c9:
	/* 0x26c9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26ce:
	/* 0x26ce: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_26d3:
	/* 0x26d3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_26d8:
	/* 0x26d8: jmp    29bd <generic_sleepable_preload+0x29bd> */
	goto x86_l_29bd;
x86_l_26dd:
	/* 0x26dd: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_26e0:
	/* 0x26e0: je     2705 <generic_sleepable_preload+0x2705> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2705;
	}
x86_l_26e2:
	/* 0x26e2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26e7:
	/* 0x26e7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_26ec:
	/* 0x26ec: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_26f1:
	/* 0x26f1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26f6:
	/* 0x26f6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26fb:
	/* 0x26fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26fd:
	/* 0x26fd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_26ff:
	/* 0x26ff: js     3e75 <generic_sleepable_preload+0x3e75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15989ULL;
	}
x86_l_2705:
	/* 0x2705: cmp    WORD PTR [r13+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_270e:
	/* 0x270e: je     6314 <generic_sleepable_preload+0x6314> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25364ULL;
	}
x86_l_2714:
	/* 0x2714: mov    ecx,DWORD PTR [r13+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_271b:
	/* 0x271b: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2720:
	/* 0x2720: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2725:
	/* 0x2725: cmp    WORD PTR [r13+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_272e:
	/* 0x272e: je     2753 <generic_sleepable_preload+0x2753> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2753;
	}
x86_l_2730:
	/* 0x2730: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2735:
	/* 0x2735: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_273a:
	/* 0x273a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_273f:
	/* 0x273f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2744:
	/* 0x2744: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2749:
	/* 0x2749: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_274b:
	/* 0x274b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_274d:
	/* 0x274d: js     5416 <generic_sleepable_preload+0x5416> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21526ULL;
	}
x86_l_2753:
	/* 0x2753: cmp    WORD PTR [r13+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_275c:
	/* 0x275c: je     6314 <generic_sleepable_preload+0x6314> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25364ULL;
	}
x86_l_2762:
	/* 0x2762: mov    ecx,DWORD PTR [r13+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_2769:
	/* 0x2769: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_276e:
	/* 0x276e: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2773:
	/* 0x2773: cmp    WORD PTR [r13+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_277c:
	/* 0x277c: je     27a1 <generic_sleepable_preload+0x27a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27a1;
	}
x86_l_277e:
	/* 0x277e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2783:
	/* 0x2783: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2788:
	/* 0x2788: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_278d:
	/* 0x278d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2792:
	/* 0x2792: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2797:
	/* 0x2797: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2799:
	/* 0x2799: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_279b:
	/* 0x279b: js     60fd <generic_sleepable_preload+0x60fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24829ULL;
	}
x86_l_27a1:
	/* 0x27a1: cmp    WORD PTR [r13+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_27aa:
	/* 0x27aa: je     6314 <generic_sleepable_preload+0x6314> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25364ULL;
	}
x86_l_27b0:
	/* 0x27b0: mov    ecx,DWORD PTR [r13+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_27b7:
	/* 0x27b7: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_27bc:
	/* 0x27bc: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27c1:
	/* 0x27c1: cmp    WORD PTR [r13+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_27ca:
	/* 0x27ca: je     27ef <generic_sleepable_preload+0x27ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27ef;
	}
x86_l_27cc:
	/* 0x27cc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27d1:
	/* 0x27d1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_27d6:
	/* 0x27d6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_27db:
	/* 0x27db: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27e0:
	/* 0x27e0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27e5:
	/* 0x27e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27e7:
	/* 0x27e7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_27e9:
	/* 0x27e9: js     6161 <generic_sleepable_preload+0x6161> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24929ULL;
	}
x86_l_27ef:
	/* 0x27ef: cmp    WORD PTR [r13+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_27f8:
	/* 0x27f8: je     6314 <generic_sleepable_preload+0x6314> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25364ULL;
	}
x86_l_27fe:
	/* 0x27fe: mov    ecx,DWORD PTR [r13+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_2805:
	/* 0x2805: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_280a:
	/* 0x280a: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_280f:
	/* 0x280f: cmp    WORD PTR [r13+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_2818:
	/* 0x2818: je     283d <generic_sleepable_preload+0x283d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_283d;
	}
x86_l_281a:
	/* 0x281a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_281f:
	/* 0x281f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2824:
	/* 0x2824: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2829:
	/* 0x2829: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_282e:
	/* 0x282e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2833:
	/* 0x2833: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2835:
	/* 0x2835: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2837:
	/* 0x2837: js     61c5 <generic_sleepable_preload+0x61c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25029ULL;
	}
x86_l_283d:
	/* 0x283d: cmp    WORD PTR [r13+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_2846:
	/* 0x2846: je     6314 <generic_sleepable_preload+0x6314> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25364ULL;
	}
x86_l_284c:
	/* 0x284c: mov    ecx,DWORD PTR [r13+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_2853:
	/* 0x2853: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2858:
	/* 0x2858: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_285d:
	/* 0x285d: cmp    WORD PTR [r13+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_2866:
	/* 0x2866: je     288b <generic_sleepable_preload+0x288b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_288b;
	}
x86_l_2868:
	/* 0x2868: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_286d:
	/* 0x286d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2872:
	/* 0x2872: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2877:
	/* 0x2877: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_287c:
	/* 0x287c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2881:
	/* 0x2881: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2883:
	/* 0x2883: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2885:
	/* 0x2885: js     6226 <generic_sleepable_preload+0x6226> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25126ULL;
	}
x86_l_288b:
	/* 0x288b: cmp    WORD PTR [r13+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_2894:
	/* 0x2894: je     6314 <generic_sleepable_preload+0x6314> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25364ULL;
	}
x86_l_289a:
	/* 0x289a: mov    ecx,DWORD PTR [r13+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_28a1:
	/* 0x28a1: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_28a6:
	/* 0x28a6: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28ab:
	/* 0x28ab: cmp    WORD PTR [r13+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_28b4:
	/* 0x28b4: je     28d9 <generic_sleepable_preload+0x28d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28d9;
	}
x86_l_28b6:
	/* 0x28b6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28bb:
	/* 0x28bb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_28c0:
	/* 0x28c0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_28c5:
	/* 0x28c5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28ca:
	/* 0x28ca: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28cf:
	/* 0x28cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28d1:
	/* 0x28d1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_28d3:
	/* 0x28d3: js     630d <generic_sleepable_preload+0x630d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25357ULL;
	}
x86_l_28d9:
	/* 0x28d9: cmp    WORD PTR [r13+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_28e2:
	/* 0x28e2: je     6314 <generic_sleepable_preload+0x6314> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25364ULL;
	}
x86_l_28e8:
	/* 0x28e8: mov    ecx,DWORD PTR [r13+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_28ef:
	/* 0x28ef: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_28f4:
	/* 0x28f4: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28f9:
	/* 0x28f9: cmp    WORD PTR [r13+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_2902:
	/* 0x2902: je     2927 <generic_sleepable_preload+0x2927> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2927;
	}
x86_l_2904:
	/* 0x2904: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2909:
	/* 0x2909: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_290e:
	/* 0x290e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2913:
	/* 0x2913: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2918:
	/* 0x2918: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_291d:
	/* 0x291d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_291f:
	/* 0x291f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2921:
	/* 0x2921: js     69e3 <generic_sleepable_preload+0x69e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27107ULL;
	}
x86_l_2927:
	/* 0x2927: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_292c:
	/* 0x292c: cmp    WORD PTR [r13+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_2935:
	/* 0x2935: je     6314 <generic_sleepable_preload+0x6314> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25364ULL;
	}
x86_l_293b:
	/* 0x293b: mov    ecx,DWORD PTR [r13+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_2942:
	/* 0x2942: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2947:
	/* 0x2947: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_294c:
	/* 0x294c: cmp    WORD PTR [r13+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_2955:
	/* 0x2955: je     297a <generic_sleepable_preload+0x297a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_297a;
	}
x86_l_2957:
	/* 0x2957: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_295c:
	/* 0x295c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2961:
	/* 0x2961: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2966:
	/* 0x2966: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_296b:
	/* 0x296b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2970:
	/* 0x2970: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2972:
	/* 0x2972: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2974:
	/* 0x2974: js     6949 <generic_sleepable_preload+0x6949> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26953ULL;
	}
x86_l_297a:
	/* 0x297a: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_297f:
	/* 0x297f: cmp    WORD PTR [r13+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_2988:
	/* 0x2988: je     6314 <generic_sleepable_preload+0x6314> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25364ULL;
	}
x86_l_298e:
	/* 0x298e: mov    ecx,DWORD PTR [r13+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_2995:
	/* 0x2995: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_299a:
	/* 0x299a: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_299f:
	/* 0x299f: cmp    WORD PTR [r13+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_29a8:
	/* 0x29a8: je     6314 <generic_sleepable_preload+0x6314> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25364ULL;
	}
x86_l_29ae:
	/* 0x29ae: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29b3:
	/* 0x29b3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_29b8:
	/* 0x29b8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_29bd:
	/* 0x29bd: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29c2:
	/* 0x29c2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29c7:
	/* 0x29c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29c9:
	/* 0x29c9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_29cb:
	/* 0x29cb: jns    6314 <generic_sleepable_preload+0x6314> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 25364ULL;
	}
x86_l_29d1:
	/* 0x29d1: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_29d6:
	/* 0x29d6: jmp    6312 <generic_sleepable_preload+0x6312> */
	return 25362ULL;
x86_l_29db:
	/* 0x29db: mov    edx,DWORD PTR [r13+0x238] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 568ULL);
x86_l_29e2:
	/* 0x29e2: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_29e8:
	/* 0x29e8: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_29eb:
	/* 0x29eb: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_29f0:
	/* 0x29f0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_29f5:
	/* 0x29f5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_29fa:
	/* 0x29fa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29ff:
	/* 0x29ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a01:
	/* 0x2a01: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a03:
	/* 0x2a03: jne    2a8d <generic_sleepable_preload+0x2a8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2a8d;
	}
x86_l_2a09:
	/* 0x2a09: mov    edx,DWORD PTR [r13+0x23c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_2a10:
	/* 0x2a10: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2a16:
	/* 0x2a16: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2a19:
	/* 0x2a19: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a1e:
	/* 0x2a1e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2a23:
	/* 0x2a23: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a28:
	/* 0x2a28: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a2d:
	/* 0x2a2d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a2f:
	/* 0x2a2f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a31:
	/* 0x2a31: jne    2a8d <generic_sleepable_preload+0x2a8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2a8d;
	}
x86_l_2a33:
	/* 0x2a33: movzx  eax,BYTE PTR [r13+0x243] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 579ULL);
x86_l_2a3b:
	/* 0x2a3b: shlx   rax,QWORD PTR [rsp+0x8],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_2a42:
	/* 0x2a42: mov    rcx,QWORD PTR [r13+0x230] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 560ULL);
x86_l_2a49:
	/* 0x2a49: add    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_2a4e:
	/* 0x2a4e: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2a51:
	/* 0x2a51: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a56:
	/* 0x2a56: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2a5b:
	/* 0x2a5b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2a60:
	/* 0x2a60: movzx  ecx,BYTE PTR [r13+0x243] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 579ULL);
x86_l_2a68:
	/* 0x2a68: shlx   rcx,QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_2a6f:
	/* 0x2a6f: mov    rdx,QWORD PTR [r13+0x230] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 560ULL);
x86_l_2a76:
	/* 0x2a76: add    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_2a7b:
	/* 0x2a7b: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2a7e:
	/* 0x2a7e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a83:
	/* 0x2a83: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a85:
	/* 0x2a85: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a87:
	/* 0x2a87: je     1bf9 <generic_sleepable_preload+0x1bf9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7161ULL;
	}
x86_l_2a8d:
	/* 0x2a8d: movsxd rcx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_2a90:
	/* 0x2a90: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a95:
	/* 0x2a95: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a97:
	/* 0x2a97: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_2a9a:
	/* 0x2a9a: cmp    WORD PTR [r13+0x116],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1194000908288ULL);
x86_l_2aa3:
	/* 0x2aa3: je     63a1 <generic_sleepable_preload+0x63a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25505ULL;
	}
x86_l_2aa9:
	/* 0x2aa9: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_2ab0:
	/* 0x2ab0: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2ab3:
	/* 0x2ab3: mov    eax,DWORD PTR [r13+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_2aba:
	/* 0x2aba: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2abd:
	/* 0x2abd: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ac2:
	/* 0x2ac2: movzx  eax,WORD PTR [r13+0x114] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 276ULL);
x86_l_2aca:
	/* 0x2aca: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_2acc:
	/* 0x2acc: je     2db7 <generic_sleepable_preload+0x2db7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11703ULL;
	}
x86_l_2ad2:
	/* 0x2ad2: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_2ad5:
	/* 0x2ad5: je     2afa <generic_sleepable_preload+0x2afa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2afa;
	}
x86_l_2ad7:
	/* 0x2ad7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2adc:
	/* 0x2adc: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2ae1:
	/* 0x2ae1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2ae6:
	/* 0x2ae6: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2aeb:
	/* 0x2aeb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2af0:
	/* 0x2af0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2af2:
	/* 0x2af2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2af4:
	/* 0x2af4: js     3e7f <generic_sleepable_preload+0x3e7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15999ULL;
	}
x86_l_2afa:
	/* 0x2afa: cmp    WORD PTR [r13+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_2b03:
	/* 0x2b03: je     63a1 <generic_sleepable_preload+0x63a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25505ULL;
	}
x86_l_2b09:
	/* 0x2b09: mov    ecx,DWORD PTR [r13+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_2b10:
	/* 0x2b10: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2b15:
	/* 0x2b15: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b1a:
	/* 0x2b1a: cmp    WORD PTR [r13+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_2b23:
	/* 0x2b23: je     2b48 <generic_sleepable_preload+0x2b48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b48;
	}
x86_l_2b25:
	/* 0x2b25: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b2a:
	/* 0x2b2a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2b2f:
	/* 0x2b2f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2b34:
	/* 0x2b34: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b39:
	/* 0x2b39: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b3e:
	/* 0x2b3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b40:
	/* 0x2b40: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b42:
	/* 0x2b42: js     5420 <generic_sleepable_preload+0x5420> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21536ULL;
	}
x86_l_2b48:
	/* 0x2b48: cmp    WORD PTR [r13+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_2b51:
	/* 0x2b51: je     63a1 <generic_sleepable_preload+0x63a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25505ULL;
	}
x86_l_2b57:
	/* 0x2b57: mov    ecx,DWORD PTR [r13+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_2b5e:
	/* 0x2b5e: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2b63:
	/* 0x2b63: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
	return 11112ULL;
}

static __noinline __u64 tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 11112ULL: goto x86_l_2b68;
	case 11121ULL: goto x86_l_2b71;
	case 11123ULL: goto x86_l_2b73;
	case 11128ULL: goto x86_l_2b78;
	case 11133ULL: goto x86_l_2b7d;
	case 11138ULL: goto x86_l_2b82;
	case 11143ULL: goto x86_l_2b87;
	case 11148ULL: goto x86_l_2b8c;
	case 11150ULL: goto x86_l_2b8e;
	case 11152ULL: goto x86_l_2b90;
	case 11158ULL: goto x86_l_2b96;
	case 11167ULL: goto x86_l_2b9f;
	case 11173ULL: goto x86_l_2ba5;
	case 11180ULL: goto x86_l_2bac;
	case 11185ULL: goto x86_l_2bb1;
	case 11190ULL: goto x86_l_2bb6;
	case 11199ULL: goto x86_l_2bbf;
	case 11201ULL: goto x86_l_2bc1;
	case 11206ULL: goto x86_l_2bc6;
	case 11211ULL: goto x86_l_2bcb;
	case 11216ULL: goto x86_l_2bd0;
	case 11221ULL: goto x86_l_2bd5;
	case 11226ULL: goto x86_l_2bda;
	case 11228ULL: goto x86_l_2bdc;
	case 11230ULL: goto x86_l_2bde;
	case 11236ULL: goto x86_l_2be4;
	case 11245ULL: goto x86_l_2bed;
	case 11251ULL: goto x86_l_2bf3;
	case 11258ULL: goto x86_l_2bfa;
	case 11263ULL: goto x86_l_2bff;
	case 11268ULL: goto x86_l_2c04;
	case 11277ULL: goto x86_l_2c0d;
	case 11279ULL: goto x86_l_2c0f;
	case 11284ULL: goto x86_l_2c14;
	case 11289ULL: goto x86_l_2c19;
	case 11294ULL: goto x86_l_2c1e;
	case 11299ULL: goto x86_l_2c23;
	case 11304ULL: goto x86_l_2c28;
	case 11306ULL: goto x86_l_2c2a;
	case 11308ULL: goto x86_l_2c2c;
	case 11314ULL: goto x86_l_2c32;
	case 11323ULL: goto x86_l_2c3b;
	case 11329ULL: goto x86_l_2c41;
	case 11336ULL: goto x86_l_2c48;
	case 11341ULL: goto x86_l_2c4d;
	case 11346ULL: goto x86_l_2c52;
	case 11355ULL: goto x86_l_2c5b;
	case 11357ULL: goto x86_l_2c5d;
	case 11362ULL: goto x86_l_2c62;
	case 11367ULL: goto x86_l_2c67;
	case 11372ULL: goto x86_l_2c6c;
	case 11377ULL: goto x86_l_2c71;
	case 11382ULL: goto x86_l_2c76;
	case 11384ULL: goto x86_l_2c78;
	case 11386ULL: goto x86_l_2c7a;
	case 11392ULL: goto x86_l_2c80;
	case 11401ULL: goto x86_l_2c89;
	case 11407ULL: goto x86_l_2c8f;
	case 11414ULL: goto x86_l_2c96;
	case 11419ULL: goto x86_l_2c9b;
	case 11424ULL: goto x86_l_2ca0;
	case 11433ULL: goto x86_l_2ca9;
	case 11435ULL: goto x86_l_2cab;
	case 11440ULL: goto x86_l_2cb0;
	case 11445ULL: goto x86_l_2cb5;
	case 11450ULL: goto x86_l_2cba;
	case 11455ULL: goto x86_l_2cbf;
	case 11460ULL: goto x86_l_2cc4;
	case 11462ULL: goto x86_l_2cc6;
	case 11464ULL: goto x86_l_2cc8;
	case 11470ULL: goto x86_l_2cce;
	case 11479ULL: goto x86_l_2cd7;
	case 11485ULL: goto x86_l_2cdd;
	case 11492ULL: goto x86_l_2ce4;
	case 11497ULL: goto x86_l_2ce9;
	case 11502ULL: goto x86_l_2cee;
	case 11511ULL: goto x86_l_2cf7;
	case 11513ULL: goto x86_l_2cf9;
	case 11518ULL: goto x86_l_2cfe;
	case 11523ULL: goto x86_l_2d03;
	case 11528ULL: goto x86_l_2d08;
	case 11533ULL: goto x86_l_2d0d;
	case 11538ULL: goto x86_l_2d12;
	case 11540ULL: goto x86_l_2d14;
	case 11542ULL: goto x86_l_2d16;
	case 11548ULL: goto x86_l_2d1c;
	case 11557ULL: goto x86_l_2d25;
	case 11563ULL: goto x86_l_2d2b;
	case 11570ULL: goto x86_l_2d32;
	case 11575ULL: goto x86_l_2d37;
	case 11580ULL: goto x86_l_2d3c;
	case 11589ULL: goto x86_l_2d45;
	case 11591ULL: goto x86_l_2d47;
	case 11596ULL: goto x86_l_2d4c;
	case 11601ULL: goto x86_l_2d51;
	case 11606ULL: goto x86_l_2d56;
	case 11611ULL: goto x86_l_2d5b;
	case 11616ULL: goto x86_l_2d60;
	case 11618ULL: goto x86_l_2d62;
	case 11620ULL: goto x86_l_2d64;
	case 11626ULL: goto x86_l_2d6a;
	case 11631ULL: goto x86_l_2d6f;
	case 11640ULL: goto x86_l_2d78;
	case 11645ULL: goto x86_l_2d7d;
	case 11651ULL: goto x86_l_2d83;
	case 11658ULL: goto x86_l_2d8a;
	case 11663ULL: goto x86_l_2d8f;
	case 11668ULL: goto x86_l_2d94;
	case 11677ULL: goto x86_l_2d9d;
	case 11683ULL: goto x86_l_2da3;
	case 11688ULL: goto x86_l_2da8;
	case 11693ULL: goto x86_l_2dad;
	case 11698ULL: goto x86_l_2db2;
	case 11703ULL: goto x86_l_2db7;
	case 11706ULL: goto x86_l_2dba;
	case 11708ULL: goto x86_l_2dbc;
	case 11713ULL: goto x86_l_2dc1;
	case 11718ULL: goto x86_l_2dc6;
	case 11723ULL: goto x86_l_2dcb;
	case 11728ULL: goto x86_l_2dd0;
	case 11733ULL: goto x86_l_2dd5;
	case 11735ULL: goto x86_l_2dd7;
	case 11737ULL: goto x86_l_2dd9;
	case 11743ULL: goto x86_l_2ddf;
	case 11752ULL: goto x86_l_2de8;
	case 11758ULL: goto x86_l_2dee;
	case 11765ULL: goto x86_l_2df5;
	case 11770ULL: goto x86_l_2dfa;
	case 11775ULL: goto x86_l_2dff;
	case 11784ULL: goto x86_l_2e08;
	case 11786ULL: goto x86_l_2e0a;
	case 11791ULL: goto x86_l_2e0f;
	case 11796ULL: goto x86_l_2e14;
	case 11801ULL: goto x86_l_2e19;
	case 11806ULL: goto x86_l_2e1e;
	case 11811ULL: goto x86_l_2e23;
	case 11813ULL: goto x86_l_2e25;
	case 11815ULL: goto x86_l_2e27;
	case 11821ULL: goto x86_l_2e2d;
	case 11830ULL: goto x86_l_2e36;
	case 11836ULL: goto x86_l_2e3c;
	case 11843ULL: goto x86_l_2e43;
	case 11848ULL: goto x86_l_2e48;
	case 11853ULL: goto x86_l_2e4d;
	case 11862ULL: goto x86_l_2e56;
	case 11864ULL: goto x86_l_2e58;
	case 11869ULL: goto x86_l_2e5d;
	case 11874ULL: goto x86_l_2e62;
	case 11879ULL: goto x86_l_2e67;
	case 11884ULL: goto x86_l_2e6c;
	case 11889ULL: goto x86_l_2e71;
	case 11891ULL: goto x86_l_2e73;
	case 11893ULL: goto x86_l_2e75;
	case 11899ULL: goto x86_l_2e7b;
	case 11908ULL: goto x86_l_2e84;
	case 11914ULL: goto x86_l_2e8a;
	case 11921ULL: goto x86_l_2e91;
	case 11926ULL: goto x86_l_2e96;
	case 11931ULL: goto x86_l_2e9b;
	case 11940ULL: goto x86_l_2ea4;
	case 11942ULL: goto x86_l_2ea6;
	case 11947ULL: goto x86_l_2eab;
	case 11952ULL: goto x86_l_2eb0;
	case 11957ULL: goto x86_l_2eb5;
	case 11962ULL: goto x86_l_2eba;
	case 11967ULL: goto x86_l_2ebf;
	case 11969ULL: goto x86_l_2ec1;
	case 11971ULL: goto x86_l_2ec3;
	case 11977ULL: goto x86_l_2ec9;
	case 11986ULL: goto x86_l_2ed2;
	case 11992ULL: goto x86_l_2ed8;
	case 11999ULL: goto x86_l_2edf;
	case 12004ULL: goto x86_l_2ee4;
	case 12009ULL: goto x86_l_2ee9;
	case 12018ULL: goto x86_l_2ef2;
	case 12020ULL: goto x86_l_2ef4;
	case 12025ULL: goto x86_l_2ef9;
	case 12030ULL: goto x86_l_2efe;
	case 12035ULL: goto x86_l_2f03;
	case 12040ULL: goto x86_l_2f08;
	case 12045ULL: goto x86_l_2f0d;
	case 12047ULL: goto x86_l_2f0f;
	case 12049ULL: goto x86_l_2f11;
	case 12055ULL: goto x86_l_2f17;
	case 12064ULL: goto x86_l_2f20;
	case 12070ULL: goto x86_l_2f26;
	case 12077ULL: goto x86_l_2f2d;
	case 12082ULL: goto x86_l_2f32;
	case 12087ULL: goto x86_l_2f37;
	case 12096ULL: goto x86_l_2f40;
	case 12098ULL: goto x86_l_2f42;
	case 12103ULL: goto x86_l_2f47;
	case 12108ULL: goto x86_l_2f4c;
	case 12113ULL: goto x86_l_2f51;
	case 12118ULL: goto x86_l_2f56;
	case 12123ULL: goto x86_l_2f5b;
	case 12125ULL: goto x86_l_2f5d;
	case 12127ULL: goto x86_l_2f5f;
	case 12133ULL: goto x86_l_2f65;
	case 12142ULL: goto x86_l_2f6e;
	case 12148ULL: goto x86_l_2f74;
	case 12155ULL: goto x86_l_2f7b;
	case 12160ULL: goto x86_l_2f80;
	case 12165ULL: goto x86_l_2f85;
	case 12174ULL: goto x86_l_2f8e;
	case 12176ULL: goto x86_l_2f90;
	case 12181ULL: goto x86_l_2f95;
	case 12186ULL: goto x86_l_2f9a;
	case 12191ULL: goto x86_l_2f9f;
	case 12196ULL: goto x86_l_2fa4;
	case 12201ULL: goto x86_l_2fa9;
	case 12203ULL: goto x86_l_2fab;
	case 12205ULL: goto x86_l_2fad;
	case 12211ULL: goto x86_l_2fb3;
	case 12220ULL: goto x86_l_2fbc;
	case 12226ULL: goto x86_l_2fc2;
	case 12233ULL: goto x86_l_2fc9;
	case 12238ULL: goto x86_l_2fce;
	case 12243ULL: goto x86_l_2fd3;
	case 12252ULL: goto x86_l_2fdc;
	case 12254ULL: goto x86_l_2fde;
	case 12259ULL: goto x86_l_2fe3;
	case 12264ULL: goto x86_l_2fe8;
	case 12269ULL: goto x86_l_2fed;
	case 12274ULL: goto x86_l_2ff2;
	case 12279ULL: goto x86_l_2ff7;
	case 12281ULL: goto x86_l_2ff9;
	case 12283ULL: goto x86_l_2ffb;
	case 12289ULL: goto x86_l_3001;
	case 12294ULL: goto x86_l_3006;
	case 12303ULL: goto x86_l_300f;
	case 12308ULL: goto x86_l_3014;
	case 12314ULL: goto x86_l_301a;
	case 12321ULL: goto x86_l_3021;
	case 12326ULL: goto x86_l_3026;
	case 12331ULL: goto x86_l_302b;
	case 12340ULL: goto x86_l_3034;
	case 12342ULL: goto x86_l_3036;
	case 12347ULL: goto x86_l_303b;
	case 12352ULL: goto x86_l_3040;
	case 12357ULL: goto x86_l_3045;
	case 12362ULL: goto x86_l_304a;
	case 12367ULL: goto x86_l_304f;
	case 12369ULL: goto x86_l_3051;
	case 12371ULL: goto x86_l_3053;
	case 12377ULL: goto x86_l_3059;
	case 12382ULL: goto x86_l_305e;
	case 12391ULL: goto x86_l_3067;
	case 12396ULL: goto x86_l_306c;
	case 12402ULL: goto x86_l_3072;
	case 12409ULL: goto x86_l_3079;
	case 12414ULL: goto x86_l_307e;
	case 12419ULL: goto x86_l_3083;
	case 12428ULL: goto x86_l_308c;
	case 12434ULL: goto x86_l_3092;
	case 12439ULL: goto x86_l_3097;
	case 12444ULL: goto x86_l_309c;
	case 12449ULL: goto x86_l_30a1;
	case 12454ULL: goto x86_l_30a6;
	case 12459ULL: goto x86_l_30ab;
	case 12461ULL: goto x86_l_30ad;
	case 12463ULL: goto x86_l_30af;
	case 12469ULL: goto x86_l_30b5;
	case 12474ULL: goto x86_l_30ba;
	case 12479ULL: goto x86_l_30bf;
	case 12486ULL: goto x86_l_30c6;
	case 12492ULL: goto x86_l_30cc;
	case 12495ULL: goto x86_l_30cf;
	case 12500ULL: goto x86_l_30d4;
	case 12505ULL: goto x86_l_30d9;
	case 12510ULL: goto x86_l_30de;
	case 12515ULL: goto x86_l_30e3;
	case 12517ULL: goto x86_l_30e5;
	case 12519ULL: goto x86_l_30e7;
	case 12525ULL: goto x86_l_30ed;
	case 12532ULL: goto x86_l_30f4;
	case 12538ULL: goto x86_l_30fa;
	case 12541ULL: goto x86_l_30fd;
	case 12546ULL: goto x86_l_3102;
	case 12551ULL: goto x86_l_3107;
	case 12556ULL: goto x86_l_310c;
	case 12561ULL: goto x86_l_3111;
	case 12563ULL: goto x86_l_3113;
	case 12565ULL: goto x86_l_3115;
	case 12567ULL: goto x86_l_3117;
	case 12575ULL: goto x86_l_311f;
	case 12582ULL: goto x86_l_3126;
	case 12589ULL: goto x86_l_312d;
	case 12594ULL: goto x86_l_3132;
	case 12597ULL: goto x86_l_3135;
	case 12602ULL: goto x86_l_313a;
	case 12607ULL: goto x86_l_313f;
	case 12612ULL: goto x86_l_3144;
	case 12620ULL: goto x86_l_314c;
	case 12627ULL: goto x86_l_3153;
	case 12634ULL: goto x86_l_315a;
	case 12639ULL: goto x86_l_315f;
	case 12642ULL: goto x86_l_3162;
	case 12647ULL: goto x86_l_3167;
	case 12649ULL: goto x86_l_3169;
	case 12651ULL: goto x86_l_316b;
	case 12657ULL: goto x86_l_3171;
	case 12660ULL: goto x86_l_3174;
	case 12665ULL: goto x86_l_3179;
	case 12667ULL: goto x86_l_317b;
	case 12670ULL: goto x86_l_317e;
	case 12679ULL: goto x86_l_3187;
	case 12685ULL: goto x86_l_318d;
	case 12692ULL: goto x86_l_3194;
	case 12695ULL: goto x86_l_3197;
	case 12702ULL: goto x86_l_319e;
	case 12705ULL: goto x86_l_31a1;
	case 12710ULL: goto x86_l_31a6;
	case 12718ULL: goto x86_l_31ae;
	case 12720ULL: goto x86_l_31b0;
	case 12726ULL: goto x86_l_31b6;
	case 12729ULL: goto x86_l_31b9;
	case 12731ULL: goto x86_l_31bb;
	case 12736ULL: goto x86_l_31c0;
	case 12741ULL: goto x86_l_31c5;
	case 12746ULL: goto x86_l_31ca;
	case 12751ULL: goto x86_l_31cf;
	case 12756ULL: goto x86_l_31d4;
	case 12758ULL: goto x86_l_31d6;
	case 12760ULL: goto x86_l_31d8;
	case 12766ULL: goto x86_l_31de;
	case 12775ULL: goto x86_l_31e7;
	case 12781ULL: goto x86_l_31ed;
	case 12788ULL: goto x86_l_31f4;
	case 12793ULL: goto x86_l_31f9;
	case 12798ULL: goto x86_l_31fe;
	case 12807ULL: goto x86_l_3207;
	case 12809ULL: goto x86_l_3209;
	case 12814ULL: goto x86_l_320e;
	case 12819ULL: goto x86_l_3213;
	case 12824ULL: goto x86_l_3218;
	case 12829ULL: goto x86_l_321d;
	case 12834ULL: goto x86_l_3222;
	case 12836ULL: goto x86_l_3224;
	case 12838ULL: goto x86_l_3226;
	case 12844ULL: goto x86_l_322c;
	case 12853ULL: goto x86_l_3235;
	case 12859ULL: goto x86_l_323b;
	case 12866ULL: goto x86_l_3242;
	case 12871ULL: goto x86_l_3247;
	case 12876ULL: goto x86_l_324c;
	case 12885ULL: goto x86_l_3255;
	case 12887ULL: goto x86_l_3257;
	case 12892ULL: goto x86_l_325c;
	case 12897ULL: goto x86_l_3261;
	case 12902ULL: goto x86_l_3266;
	case 12907ULL: goto x86_l_326b;
	case 12912ULL: goto x86_l_3270;
	case 12914ULL: goto x86_l_3272;
	case 12916ULL: goto x86_l_3274;
	case 12922ULL: goto x86_l_327a;
	case 12931ULL: goto x86_l_3283;
	case 12937ULL: goto x86_l_3289;
	case 12944ULL: goto x86_l_3290;
	case 12949ULL: goto x86_l_3295;
	case 12954ULL: goto x86_l_329a;
	case 12963ULL: goto x86_l_32a3;
	case 12965ULL: goto x86_l_32a5;
	case 12970ULL: goto x86_l_32aa;
	case 12975ULL: goto x86_l_32af;
	case 12980ULL: goto x86_l_32b4;
	case 12985ULL: goto x86_l_32b9;
	case 12990ULL: goto x86_l_32be;
	case 12992ULL: goto x86_l_32c0;
	case 12994ULL: goto x86_l_32c2;
	case 13000ULL: goto x86_l_32c8;
	case 13009ULL: goto x86_l_32d1;
	case 13015ULL: goto x86_l_32d7;
	case 13022ULL: goto x86_l_32de;
	case 13027ULL: goto x86_l_32e3;
	case 13032ULL: goto x86_l_32e8;
	case 13041ULL: goto x86_l_32f1;
	case 13043ULL: goto x86_l_32f3;
	case 13048ULL: goto x86_l_32f8;
	case 13053ULL: goto x86_l_32fd;
	case 13058ULL: goto x86_l_3302;
	case 13063ULL: goto x86_l_3307;
	case 13068ULL: goto x86_l_330c;
	case 13070ULL: goto x86_l_330e;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2b68:
	/* 0x2b68: cmp    WORD PTR [r13+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_2b71:
	/* 0x2b71: je     2b96 <generic_sleepable_preload+0x2b96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b96;
	}
x86_l_2b73:
	/* 0x2b73: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b78:
	/* 0x2b78: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2b7d:
	/* 0x2b7d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2b82:
	/* 0x2b82: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b87:
	/* 0x2b87: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b8c:
	/* 0x2b8c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b8e:
	/* 0x2b8e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b90:
	/* 0x2b90: js     6107 <generic_sleepable_preload+0x6107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24839ULL;
	}
x86_l_2b96:
	/* 0x2b96: cmp    WORD PTR [r13+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_2b9f:
	/* 0x2b9f: je     63a1 <generic_sleepable_preload+0x63a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25505ULL;
	}
x86_l_2ba5:
	/* 0x2ba5: mov    ecx,DWORD PTR [r13+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_2bac:
	/* 0x2bac: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2bb1:
	/* 0x2bb1: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2bb6:
	/* 0x2bb6: cmp    WORD PTR [r13+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_2bbf:
	/* 0x2bbf: je     2be4 <generic_sleepable_preload+0x2be4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2be4;
	}
x86_l_2bc1:
	/* 0x2bc1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2bc6:
	/* 0x2bc6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2bcb:
	/* 0x2bcb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2bd0:
	/* 0x2bd0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2bd5:
	/* 0x2bd5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2bda:
	/* 0x2bda: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bdc:
	/* 0x2bdc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2bde:
	/* 0x2bde: js     616b <generic_sleepable_preload+0x616b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24939ULL;
	}
x86_l_2be4:
	/* 0x2be4: cmp    WORD PTR [r13+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_2bed:
	/* 0x2bed: je     63a1 <generic_sleepable_preload+0x63a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25505ULL;
	}
x86_l_2bf3:
	/* 0x2bf3: mov    ecx,DWORD PTR [r13+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_2bfa:
	/* 0x2bfa: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2bff:
	/* 0x2bff: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c04:
	/* 0x2c04: cmp    WORD PTR [r13+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_2c0d:
	/* 0x2c0d: je     2c32 <generic_sleepable_preload+0x2c32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c32;
	}
x86_l_2c0f:
	/* 0x2c0f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c14:
	/* 0x2c14: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2c19:
	/* 0x2c19: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2c1e:
	/* 0x2c1e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c23:
	/* 0x2c23: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c28:
	/* 0x2c28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c2a:
	/* 0x2c2a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c2c:
	/* 0x2c2c: js     61cf <generic_sleepable_preload+0x61cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25039ULL;
	}
x86_l_2c32:
	/* 0x2c32: cmp    WORD PTR [r13+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_2c3b:
	/* 0x2c3b: je     63a1 <generic_sleepable_preload+0x63a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25505ULL;
	}
x86_l_2c41:
	/* 0x2c41: mov    ecx,DWORD PTR [r13+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_2c48:
	/* 0x2c48: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2c4d:
	/* 0x2c4d: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c52:
	/* 0x2c52: cmp    WORD PTR [r13+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_2c5b:
	/* 0x2c5b: je     2c80 <generic_sleepable_preload+0x2c80> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c80;
	}
x86_l_2c5d:
	/* 0x2c5d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c62:
	/* 0x2c62: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2c67:
	/* 0x2c67: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2c6c:
	/* 0x2c6c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c71:
	/* 0x2c71: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c76:
	/* 0x2c76: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c78:
	/* 0x2c78: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c7a:
	/* 0x2c7a: js     6230 <generic_sleepable_preload+0x6230> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25136ULL;
	}
x86_l_2c80:
	/* 0x2c80: cmp    WORD PTR [r13+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_2c89:
	/* 0x2c89: je     63a1 <generic_sleepable_preload+0x63a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25505ULL;
	}
x86_l_2c8f:
	/* 0x2c8f: mov    ecx,DWORD PTR [r13+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_2c96:
	/* 0x2c96: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2c9b:
	/* 0x2c9b: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ca0:
	/* 0x2ca0: cmp    WORD PTR [r13+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_2ca9:
	/* 0x2ca9: je     2cce <generic_sleepable_preload+0x2cce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cce;
	}
x86_l_2cab:
	/* 0x2cab: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cb0:
	/* 0x2cb0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2cb5:
	/* 0x2cb5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2cba:
	/* 0x2cba: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cbf:
	/* 0x2cbf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2cc4:
	/* 0x2cc4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cc6:
	/* 0x2cc6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2cc8:
	/* 0x2cc8: js     639a <generic_sleepable_preload+0x639a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25498ULL;
	}
x86_l_2cce:
	/* 0x2cce: cmp    WORD PTR [r13+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_2cd7:
	/* 0x2cd7: je     63a1 <generic_sleepable_preload+0x63a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25505ULL;
	}
x86_l_2cdd:
	/* 0x2cdd: mov    ecx,DWORD PTR [r13+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_2ce4:
	/* 0x2ce4: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2ce9:
	/* 0x2ce9: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cee:
	/* 0x2cee: cmp    WORD PTR [r13+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_2cf7:
	/* 0x2cf7: je     2d1c <generic_sleepable_preload+0x2d1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d1c;
	}
x86_l_2cf9:
	/* 0x2cf9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cfe:
	/* 0x2cfe: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2d03:
	/* 0x2d03: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2d08:
	/* 0x2d08: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d0d:
	/* 0x2d0d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d12:
	/* 0x2d12: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d14:
	/* 0x2d14: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2d16:
	/* 0x2d16: js     68e8 <generic_sleepable_preload+0x68e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26856ULL;
	}
x86_l_2d1c:
	/* 0x2d1c: cmp    WORD PTR [r13+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_2d25:
	/* 0x2d25: je     63a1 <generic_sleepable_preload+0x63a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25505ULL;
	}
x86_l_2d2b:
	/* 0x2d2b: mov    ecx,DWORD PTR [r13+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_2d32:
	/* 0x2d32: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2d37:
	/* 0x2d37: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d3c:
	/* 0x2d3c: cmp    WORD PTR [r13+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_2d45:
	/* 0x2d45: je     2d6a <generic_sleepable_preload+0x2d6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d6a;
	}
x86_l_2d47:
	/* 0x2d47: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d4c:
	/* 0x2d4c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2d51:
	/* 0x2d51: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2d56:
	/* 0x2d56: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d5b:
	/* 0x2d5b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d60:
	/* 0x2d60: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d62:
	/* 0x2d62: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2d64:
	/* 0x2d64: js     695a <generic_sleepable_preload+0x695a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26970ULL;
	}
x86_l_2d6a:
	/* 0x2d6a: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2d6f:
	/* 0x2d6f: cmp    WORD PTR [r13+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_2d78:
	/* 0x2d78: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2d7d:
	/* 0x2d7d: je     63a1 <generic_sleepable_preload+0x63a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25505ULL;
	}
x86_l_2d83:
	/* 0x2d83: mov    ecx,DWORD PTR [r13+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_2d8a:
	/* 0x2d8a: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2d8f:
	/* 0x2d8f: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d94:
	/* 0x2d94: cmp    WORD PTR [r13+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_2d9d:
	/* 0x2d9d: je     63a1 <generic_sleepable_preload+0x63a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25505ULL;
	}
x86_l_2da3:
	/* 0x2da3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2da8:
	/* 0x2da8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2dad:
	/* 0x2dad: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2db2:
	/* 0x2db2: jmp    30a1 <generic_sleepable_preload+0x30a1> */
	goto x86_l_30a1;
x86_l_2db7:
	/* 0x2db7: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_2dba:
	/* 0x2dba: je     2ddf <generic_sleepable_preload+0x2ddf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ddf;
	}
x86_l_2dbc:
	/* 0x2dbc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2dc1:
	/* 0x2dc1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2dc6:
	/* 0x2dc6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2dcb:
	/* 0x2dcb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2dd0:
	/* 0x2dd0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2dd5:
	/* 0x2dd5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dd7:
	/* 0x2dd7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2dd9:
	/* 0x2dd9: js     3e7f <generic_sleepable_preload+0x3e7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15999ULL;
	}
x86_l_2ddf:
	/* 0x2ddf: cmp    WORD PTR [r13+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_2de8:
	/* 0x2de8: je     63a1 <generic_sleepable_preload+0x63a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25505ULL;
	}
x86_l_2dee:
	/* 0x2dee: mov    ecx,DWORD PTR [r13+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_2df5:
	/* 0x2df5: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2dfa:
	/* 0x2dfa: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2dff:
	/* 0x2dff: cmp    WORD PTR [r13+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_2e08:
	/* 0x2e08: je     2e2d <generic_sleepable_preload+0x2e2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e2d;
	}
x86_l_2e0a:
	/* 0x2e0a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e0f:
	/* 0x2e0f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2e14:
	/* 0x2e14: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2e19:
	/* 0x2e19: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e1e:
	/* 0x2e1e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e23:
	/* 0x2e23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e25:
	/* 0x2e25: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2e27:
	/* 0x2e27: js     5420 <generic_sleepable_preload+0x5420> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21536ULL;
	}
x86_l_2e2d:
	/* 0x2e2d: cmp    WORD PTR [r13+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_2e36:
	/* 0x2e36: je     63a1 <generic_sleepable_preload+0x63a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25505ULL;
	}
x86_l_2e3c:
	/* 0x2e3c: mov    ecx,DWORD PTR [r13+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_2e43:
	/* 0x2e43: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2e48:
	/* 0x2e48: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e4d:
	/* 0x2e4d: cmp    WORD PTR [r13+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_2e56:
	/* 0x2e56: je     2e7b <generic_sleepable_preload+0x2e7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e7b;
	}
x86_l_2e58:
	/* 0x2e58: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e5d:
	/* 0x2e5d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2e62:
	/* 0x2e62: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2e67:
	/* 0x2e67: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e6c:
	/* 0x2e6c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e71:
	/* 0x2e71: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e73:
	/* 0x2e73: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2e75:
	/* 0x2e75: js     6107 <generic_sleepable_preload+0x6107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24839ULL;
	}
x86_l_2e7b:
	/* 0x2e7b: cmp    WORD PTR [r13+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_2e84:
	/* 0x2e84: je     63a1 <generic_sleepable_preload+0x63a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25505ULL;
	}
x86_l_2e8a:
	/* 0x2e8a: mov    ecx,DWORD PTR [r13+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_2e91:
	/* 0x2e91: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2e96:
	/* 0x2e96: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e9b:
	/* 0x2e9b: cmp    WORD PTR [r13+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_2ea4:
	/* 0x2ea4: je     2ec9 <generic_sleepable_preload+0x2ec9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ec9;
	}
x86_l_2ea6:
	/* 0x2ea6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2eab:
	/* 0x2eab: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2eb0:
	/* 0x2eb0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2eb5:
	/* 0x2eb5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2eba:
	/* 0x2eba: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ebf:
	/* 0x2ebf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ec1:
	/* 0x2ec1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ec3:
	/* 0x2ec3: js     616b <generic_sleepable_preload+0x616b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24939ULL;
	}
x86_l_2ec9:
	/* 0x2ec9: cmp    WORD PTR [r13+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_2ed2:
	/* 0x2ed2: je     63a1 <generic_sleepable_preload+0x63a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25505ULL;
	}
x86_l_2ed8:
	/* 0x2ed8: mov    ecx,DWORD PTR [r13+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_2edf:
	/* 0x2edf: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2ee4:
	/* 0x2ee4: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ee9:
	/* 0x2ee9: cmp    WORD PTR [r13+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_2ef2:
	/* 0x2ef2: je     2f17 <generic_sleepable_preload+0x2f17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f17;
	}
x86_l_2ef4:
	/* 0x2ef4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ef9:
	/* 0x2ef9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2efe:
	/* 0x2efe: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2f03:
	/* 0x2f03: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f08:
	/* 0x2f08: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f0d:
	/* 0x2f0d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f0f:
	/* 0x2f0f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2f11:
	/* 0x2f11: js     61cf <generic_sleepable_preload+0x61cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25039ULL;
	}
x86_l_2f17:
	/* 0x2f17: cmp    WORD PTR [r13+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_2f20:
	/* 0x2f20: je     63a1 <generic_sleepable_preload+0x63a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25505ULL;
	}
x86_l_2f26:
	/* 0x2f26: mov    ecx,DWORD PTR [r13+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_2f2d:
	/* 0x2f2d: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2f32:
	/* 0x2f32: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f37:
	/* 0x2f37: cmp    WORD PTR [r13+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_2f40:
	/* 0x2f40: je     2f65 <generic_sleepable_preload+0x2f65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f65;
	}
x86_l_2f42:
	/* 0x2f42: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f47:
	/* 0x2f47: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2f4c:
	/* 0x2f4c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2f51:
	/* 0x2f51: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f56:
	/* 0x2f56: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f5b:
	/* 0x2f5b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f5d:
	/* 0x2f5d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2f5f:
	/* 0x2f5f: js     6230 <generic_sleepable_preload+0x6230> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25136ULL;
	}
x86_l_2f65:
	/* 0x2f65: cmp    WORD PTR [r13+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_2f6e:
	/* 0x2f6e: je     63a1 <generic_sleepable_preload+0x63a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25505ULL;
	}
x86_l_2f74:
	/* 0x2f74: mov    ecx,DWORD PTR [r13+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_2f7b:
	/* 0x2f7b: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2f80:
	/* 0x2f80: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f85:
	/* 0x2f85: cmp    WORD PTR [r13+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_2f8e:
	/* 0x2f8e: je     2fb3 <generic_sleepable_preload+0x2fb3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fb3;
	}
x86_l_2f90:
	/* 0x2f90: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f95:
	/* 0x2f95: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2f9a:
	/* 0x2f9a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2f9f:
	/* 0x2f9f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2fa4:
	/* 0x2fa4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fa9:
	/* 0x2fa9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fab:
	/* 0x2fab: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2fad:
	/* 0x2fad: js     639a <generic_sleepable_preload+0x639a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25498ULL;
	}
x86_l_2fb3:
	/* 0x2fb3: cmp    WORD PTR [r13+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_2fbc:
	/* 0x2fbc: je     63a1 <generic_sleepable_preload+0x63a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25505ULL;
	}
x86_l_2fc2:
	/* 0x2fc2: mov    ecx,DWORD PTR [r13+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_2fc9:
	/* 0x2fc9: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2fce:
	/* 0x2fce: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2fd3:
	/* 0x2fd3: cmp    WORD PTR [r13+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_2fdc:
	/* 0x2fdc: je     3001 <generic_sleepable_preload+0x3001> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3001;
	}
x86_l_2fde:
	/* 0x2fde: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2fe3:
	/* 0x2fe3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2fe8:
	/* 0x2fe8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2fed:
	/* 0x2fed: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ff2:
	/* 0x2ff2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ff7:
	/* 0x2ff7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ff9:
	/* 0x2ff9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ffb:
	/* 0x2ffb: js     69f4 <generic_sleepable_preload+0x69f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27124ULL;
	}
x86_l_3001:
	/* 0x3001: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3006:
	/* 0x3006: cmp    WORD PTR [r13+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_300f:
	/* 0x300f: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3014:
	/* 0x3014: je     63a1 <generic_sleepable_preload+0x63a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25505ULL;
	}
x86_l_301a:
	/* 0x301a: mov    ecx,DWORD PTR [r13+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_3021:
	/* 0x3021: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3026:
	/* 0x3026: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_302b:
	/* 0x302b: cmp    WORD PTR [r13+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_3034:
	/* 0x3034: je     3059 <generic_sleepable_preload+0x3059> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3059;
	}
x86_l_3036:
	/* 0x3036: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_303b:
	/* 0x303b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3040:
	/* 0x3040: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3045:
	/* 0x3045: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_304a:
	/* 0x304a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_304f:
	/* 0x304f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3051:
	/* 0x3051: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3053:
	/* 0x3053: js     695a <generic_sleepable_preload+0x695a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26970ULL;
	}
x86_l_3059:
	/* 0x3059: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_305e:
	/* 0x305e: cmp    WORD PTR [r13+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_3067:
	/* 0x3067: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_306c:
	/* 0x306c: je     63a1 <generic_sleepable_preload+0x63a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25505ULL;
	}
x86_l_3072:
	/* 0x3072: mov    ecx,DWORD PTR [r13+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_3079:
	/* 0x3079: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_307e:
	/* 0x307e: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3083:
	/* 0x3083: cmp    WORD PTR [r13+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_308c:
	/* 0x308c: je     63a1 <generic_sleepable_preload+0x63a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25505ULL;
	}
x86_l_3092:
	/* 0x3092: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3097:
	/* 0x3097: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_309c:
	/* 0x309c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_30a1:
	/* 0x30a1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_30a6:
	/* 0x30a6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30ab:
	/* 0x30ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30ad:
	/* 0x30ad: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_30af:
	/* 0x30af: jns    63a1 <generic_sleepable_preload+0x63a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 25505ULL;
	}
x86_l_30b5:
	/* 0x30b5: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_30ba:
	/* 0x30ba: jmp    639f <generic_sleepable_preload+0x639f> */
	return 25503ULL;
x86_l_30bf:
	/* 0x30bf: mov    edx,DWORD PTR [r13+0x250] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 592ULL);
x86_l_30c6:
	/* 0x30c6: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_30cc:
	/* 0x30cc: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_30cf:
	/* 0x30cf: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_30d4:
	/* 0x30d4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_30d9:
	/* 0x30d9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_30de:
	/* 0x30de: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30e3:
	/* 0x30e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30e5:
	/* 0x30e5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_30e7:
	/* 0x30e7: jne    3171 <generic_sleepable_preload+0x3171> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3171;
	}
x86_l_30ed:
	/* 0x30ed: mov    edx,DWORD PTR [r13+0x254] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 596ULL);
x86_l_30f4:
	/* 0x30f4: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_30fa:
	/* 0x30fa: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_30fd:
	/* 0x30fd: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3102:
	/* 0x3102: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3107:
	/* 0x3107: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_310c:
	/* 0x310c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3111:
	/* 0x3111: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3113:
	/* 0x3113: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3115:
	/* 0x3115: jne    3171 <generic_sleepable_preload+0x3171> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3171;
	}
x86_l_3117:
	/* 0x3117: movzx  eax,BYTE PTR [r13+0x25b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 603ULL);
x86_l_311f:
	/* 0x311f: shlx   rax,QWORD PTR [rsp+0x8],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_3126:
	/* 0x3126: mov    rcx,QWORD PTR [r13+0x248] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584ULL);
x86_l_312d:
	/* 0x312d: add    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_3132:
	/* 0x3132: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3135:
	/* 0x3135: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_313a:
	/* 0x313a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_313f:
	/* 0x313f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3144:
	/* 0x3144: movzx  ecx,BYTE PTR [r13+0x25b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 603ULL);
x86_l_314c:
	/* 0x314c: shlx   rcx,QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_3153:
	/* 0x3153: mov    rdx,QWORD PTR [r13+0x248] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584ULL);
x86_l_315a:
	/* 0x315a: add    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_315f:
	/* 0x315f: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3162:
	/* 0x3162: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3167:
	/* 0x3167: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3169:
	/* 0x3169: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_316b:
	/* 0x316b: je     1c2f <generic_sleepable_preload+0x1c2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7215ULL;
	}
x86_l_3171:
	/* 0x3171: movsxd rcx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_3174:
	/* 0x3174: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3179:
	/* 0x3179: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_317b:
	/* 0x317b: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_317e:
	/* 0x317e: cmp    WORD PTR [r13+0x166],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1537598291968ULL);
x86_l_3187:
	/* 0x3187: je     642e <generic_sleepable_preload+0x642e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25646ULL;
	}
x86_l_318d:
	/* 0x318d: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_3194:
	/* 0x3194: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_3197:
	/* 0x3197: mov    eax,DWORD PTR [r13+0x160] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_319e:
	/* 0x319e: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_31a1:
	/* 0x31a1: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31a6:
	/* 0x31a6: movzx  eax,WORD PTR [r13+0x164] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 356ULL);
x86_l_31ae:
	/* 0x31ae: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_31b0:
	/* 0x31b0: je     3496 <generic_sleepable_preload+0x3496> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13462ULL;
	}
x86_l_31b6:
	/* 0x31b6: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_31b9:
	/* 0x31b9: je     31de <generic_sleepable_preload+0x31de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31de;
	}
x86_l_31bb:
	/* 0x31bb: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31c0:
	/* 0x31c0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_31c5:
	/* 0x31c5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_31ca:
	/* 0x31ca: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31cf:
	/* 0x31cf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31d4:
	/* 0x31d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31d6:
	/* 0x31d6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_31d8:
	/* 0x31d8: js     3e89 <generic_sleepable_preload+0x3e89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 16009ULL;
	}
x86_l_31de:
	/* 0x31de: cmp    WORD PTR [r13+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_31e7:
	/* 0x31e7: je     642e <generic_sleepable_preload+0x642e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25646ULL;
	}
x86_l_31ed:
	/* 0x31ed: mov    ecx,DWORD PTR [r13+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_31f4:
	/* 0x31f4: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_31f9:
	/* 0x31f9: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31fe:
	/* 0x31fe: cmp    WORD PTR [r13+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_3207:
	/* 0x3207: je     322c <generic_sleepable_preload+0x322c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_322c;
	}
x86_l_3209:
	/* 0x3209: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_320e:
	/* 0x320e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3213:
	/* 0x3213: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3218:
	/* 0x3218: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_321d:
	/* 0x321d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3222:
	/* 0x3222: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3224:
	/* 0x3224: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3226:
	/* 0x3226: js     542a <generic_sleepable_preload+0x542a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21546ULL;
	}
x86_l_322c:
	/* 0x322c: cmp    WORD PTR [r13+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_3235:
	/* 0x3235: je     642e <generic_sleepable_preload+0x642e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25646ULL;
	}
x86_l_323b:
	/* 0x323b: mov    ecx,DWORD PTR [r13+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_3242:
	/* 0x3242: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3247:
	/* 0x3247: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_324c:
	/* 0x324c: cmp    WORD PTR [r13+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_3255:
	/* 0x3255: je     327a <generic_sleepable_preload+0x327a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_327a;
	}
x86_l_3257:
	/* 0x3257: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_325c:
	/* 0x325c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3261:
	/* 0x3261: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3266:
	/* 0x3266: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_326b:
	/* 0x326b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3270:
	/* 0x3270: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3272:
	/* 0x3272: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3274:
	/* 0x3274: js     6111 <generic_sleepable_preload+0x6111> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24849ULL;
	}
x86_l_327a:
	/* 0x327a: cmp    WORD PTR [r13+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_3283:
	/* 0x3283: je     642e <generic_sleepable_preload+0x642e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25646ULL;
	}
x86_l_3289:
	/* 0x3289: mov    ecx,DWORD PTR [r13+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_3290:
	/* 0x3290: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3295:
	/* 0x3295: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_329a:
	/* 0x329a: cmp    WORD PTR [r13+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_32a3:
	/* 0x32a3: je     32c8 <generic_sleepable_preload+0x32c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32c8;
	}
x86_l_32a5:
	/* 0x32a5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32aa:
	/* 0x32aa: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_32af:
	/* 0x32af: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_32b4:
	/* 0x32b4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32b9:
	/* 0x32b9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32be:
	/* 0x32be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32c0:
	/* 0x32c0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_32c2:
	/* 0x32c2: js     6175 <generic_sleepable_preload+0x6175> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24949ULL;
	}
x86_l_32c8:
	/* 0x32c8: cmp    WORD PTR [r13+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_32d1:
	/* 0x32d1: je     642e <generic_sleepable_preload+0x642e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25646ULL;
	}
x86_l_32d7:
	/* 0x32d7: mov    ecx,DWORD PTR [r13+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_32de:
	/* 0x32de: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_32e3:
	/* 0x32e3: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32e8:
	/* 0x32e8: cmp    WORD PTR [r13+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_32f1:
	/* 0x32f1: je     3316 <generic_sleepable_preload+0x3316> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13078ULL;
	}
x86_l_32f3:
	/* 0x32f3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32f8:
	/* 0x32f8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_32fd:
	/* 0x32fd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3302:
	/* 0x3302: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3307:
	/* 0x3307: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_330c:
	/* 0x330c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_330e:
	/* 0x330e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
	return 13072ULL;
}

static __noinline __u64 tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 13072ULL: goto x86_l_3310;
	case 13078ULL: goto x86_l_3316;
	case 13087ULL: goto x86_l_331f;
	case 13093ULL: goto x86_l_3325;
	case 13100ULL: goto x86_l_332c;
	case 13105ULL: goto x86_l_3331;
	case 13110ULL: goto x86_l_3336;
	case 13119ULL: goto x86_l_333f;
	case 13121ULL: goto x86_l_3341;
	case 13126ULL: goto x86_l_3346;
	case 13131ULL: goto x86_l_334b;
	case 13136ULL: goto x86_l_3350;
	case 13141ULL: goto x86_l_3355;
	case 13146ULL: goto x86_l_335a;
	case 13148ULL: goto x86_l_335c;
	case 13150ULL: goto x86_l_335e;
	case 13156ULL: goto x86_l_3364;
	case 13165ULL: goto x86_l_336d;
	case 13171ULL: goto x86_l_3373;
	case 13178ULL: goto x86_l_337a;
	case 13183ULL: goto x86_l_337f;
	case 13188ULL: goto x86_l_3384;
	case 13197ULL: goto x86_l_338d;
	case 13199ULL: goto x86_l_338f;
	case 13204ULL: goto x86_l_3394;
	case 13209ULL: goto x86_l_3399;
	case 13214ULL: goto x86_l_339e;
	case 13219ULL: goto x86_l_33a3;
	case 13224ULL: goto x86_l_33a8;
	case 13226ULL: goto x86_l_33aa;
	case 13228ULL: goto x86_l_33ac;
	case 13234ULL: goto x86_l_33b2;
	case 13243ULL: goto x86_l_33bb;
	case 13249ULL: goto x86_l_33c1;
	case 13256ULL: goto x86_l_33c8;
	case 13261ULL: goto x86_l_33cd;
	case 13266ULL: goto x86_l_33d2;
	case 13275ULL: goto x86_l_33db;
	case 13277ULL: goto x86_l_33dd;
	case 13282ULL: goto x86_l_33e2;
	case 13287ULL: goto x86_l_33e7;
	case 13292ULL: goto x86_l_33ec;
	case 13297ULL: goto x86_l_33f1;
	case 13302ULL: goto x86_l_33f6;
	case 13304ULL: goto x86_l_33f8;
	case 13306ULL: goto x86_l_33fa;
	case 13312ULL: goto x86_l_3400;
	case 13321ULL: goto x86_l_3409;
	case 13327ULL: goto x86_l_340f;
	case 13334ULL: goto x86_l_3416;
	case 13339ULL: goto x86_l_341b;
	case 13344ULL: goto x86_l_3420;
	case 13353ULL: goto x86_l_3429;
	case 13355ULL: goto x86_l_342b;
	case 13360ULL: goto x86_l_3430;
	case 13365ULL: goto x86_l_3435;
	case 13370ULL: goto x86_l_343a;
	case 13375ULL: goto x86_l_343f;
	case 13380ULL: goto x86_l_3444;
	case 13382ULL: goto x86_l_3446;
	case 13384ULL: goto x86_l_3448;
	case 13390ULL: goto x86_l_344e;
	case 13395ULL: goto x86_l_3453;
	case 13404ULL: goto x86_l_345c;
	case 13410ULL: goto x86_l_3462;
	case 13417ULL: goto x86_l_3469;
	case 13422ULL: goto x86_l_346e;
	case 13427ULL: goto x86_l_3473;
	case 13436ULL: goto x86_l_347c;
	case 13442ULL: goto x86_l_3482;
	case 13447ULL: goto x86_l_3487;
	case 13452ULL: goto x86_l_348c;
	case 13457ULL: goto x86_l_3491;
	case 13462ULL: goto x86_l_3496;
	case 13465ULL: goto x86_l_3499;
	case 13467ULL: goto x86_l_349b;
	case 13472ULL: goto x86_l_34a0;
	case 13477ULL: goto x86_l_34a5;
	case 13482ULL: goto x86_l_34aa;
	case 13487ULL: goto x86_l_34af;
	case 13492ULL: goto x86_l_34b4;
	case 13494ULL: goto x86_l_34b6;
	case 13496ULL: goto x86_l_34b8;
	case 13502ULL: goto x86_l_34be;
	case 13511ULL: goto x86_l_34c7;
	case 13517ULL: goto x86_l_34cd;
	case 13524ULL: goto x86_l_34d4;
	case 13529ULL: goto x86_l_34d9;
	case 13534ULL: goto x86_l_34de;
	case 13543ULL: goto x86_l_34e7;
	case 13545ULL: goto x86_l_34e9;
	case 13550ULL: goto x86_l_34ee;
	case 13555ULL: goto x86_l_34f3;
	case 13560ULL: goto x86_l_34f8;
	case 13565ULL: goto x86_l_34fd;
	case 13570ULL: goto x86_l_3502;
	case 13572ULL: goto x86_l_3504;
	case 13574ULL: goto x86_l_3506;
	case 13580ULL: goto x86_l_350c;
	case 13589ULL: goto x86_l_3515;
	case 13595ULL: goto x86_l_351b;
	case 13602ULL: goto x86_l_3522;
	case 13607ULL: goto x86_l_3527;
	case 13612ULL: goto x86_l_352c;
	case 13621ULL: goto x86_l_3535;
	case 13623ULL: goto x86_l_3537;
	case 13628ULL: goto x86_l_353c;
	case 13633ULL: goto x86_l_3541;
	case 13638ULL: goto x86_l_3546;
	case 13643ULL: goto x86_l_354b;
	case 13648ULL: goto x86_l_3550;
	case 13650ULL: goto x86_l_3552;
	case 13652ULL: goto x86_l_3554;
	case 13658ULL: goto x86_l_355a;
	case 13667ULL: goto x86_l_3563;
	case 13673ULL: goto x86_l_3569;
	case 13680ULL: goto x86_l_3570;
	case 13685ULL: goto x86_l_3575;
	case 13690ULL: goto x86_l_357a;
	case 13699ULL: goto x86_l_3583;
	case 13701ULL: goto x86_l_3585;
	case 13706ULL: goto x86_l_358a;
	case 13711ULL: goto x86_l_358f;
	case 13716ULL: goto x86_l_3594;
	case 13721ULL: goto x86_l_3599;
	case 13726ULL: goto x86_l_359e;
	case 13728ULL: goto x86_l_35a0;
	case 13730ULL: goto x86_l_35a2;
	case 13736ULL: goto x86_l_35a8;
	case 13745ULL: goto x86_l_35b1;
	case 13751ULL: goto x86_l_35b7;
	case 13758ULL: goto x86_l_35be;
	case 13763ULL: goto x86_l_35c3;
	case 13768ULL: goto x86_l_35c8;
	case 13777ULL: goto x86_l_35d1;
	case 13779ULL: goto x86_l_35d3;
	case 13784ULL: goto x86_l_35d8;
	case 13789ULL: goto x86_l_35dd;
	case 13794ULL: goto x86_l_35e2;
	case 13799ULL: goto x86_l_35e7;
	case 13804ULL: goto x86_l_35ec;
	case 13806ULL: goto x86_l_35ee;
	case 13808ULL: goto x86_l_35f0;
	case 13814ULL: goto x86_l_35f6;
	case 13823ULL: goto x86_l_35ff;
	case 13829ULL: goto x86_l_3605;
	case 13836ULL: goto x86_l_360c;
	case 13841ULL: goto x86_l_3611;
	case 13846ULL: goto x86_l_3616;
	case 13855ULL: goto x86_l_361f;
	case 13857ULL: goto x86_l_3621;
	case 13862ULL: goto x86_l_3626;
	case 13867ULL: goto x86_l_362b;
	case 13872ULL: goto x86_l_3630;
	case 13877ULL: goto x86_l_3635;
	case 13882ULL: goto x86_l_363a;
	case 13884ULL: goto x86_l_363c;
	case 13886ULL: goto x86_l_363e;
	case 13892ULL: goto x86_l_3644;
	case 13901ULL: goto x86_l_364d;
	case 13907ULL: goto x86_l_3653;
	case 13914ULL: goto x86_l_365a;
	case 13919ULL: goto x86_l_365f;
	case 13924ULL: goto x86_l_3664;
	case 13933ULL: goto x86_l_366d;
	case 13935ULL: goto x86_l_366f;
	case 13940ULL: goto x86_l_3674;
	case 13945ULL: goto x86_l_3679;
	case 13950ULL: goto x86_l_367e;
	case 13955ULL: goto x86_l_3683;
	case 13960ULL: goto x86_l_3688;
	case 13962ULL: goto x86_l_368a;
	case 13964ULL: goto x86_l_368c;
	case 13970ULL: goto x86_l_3692;
	case 13979ULL: goto x86_l_369b;
	case 13985ULL: goto x86_l_36a1;
	case 13992ULL: goto x86_l_36a8;
	case 13997ULL: goto x86_l_36ad;
	case 14002ULL: goto x86_l_36b2;
	case 14011ULL: goto x86_l_36bb;
	case 14013ULL: goto x86_l_36bd;
	case 14018ULL: goto x86_l_36c2;
	case 14023ULL: goto x86_l_36c7;
	case 14028ULL: goto x86_l_36cc;
	case 14033ULL: goto x86_l_36d1;
	case 14038ULL: goto x86_l_36d6;
	case 14040ULL: goto x86_l_36d8;
	case 14042ULL: goto x86_l_36da;
	case 14048ULL: goto x86_l_36e0;
	case 14053ULL: goto x86_l_36e5;
	case 14062ULL: goto x86_l_36ee;
	case 14068ULL: goto x86_l_36f4;
	case 14075ULL: goto x86_l_36fb;
	case 14080ULL: goto x86_l_3700;
	case 14085ULL: goto x86_l_3705;
	case 14094ULL: goto x86_l_370e;
	case 14096ULL: goto x86_l_3710;
	case 14101ULL: goto x86_l_3715;
	case 14106ULL: goto x86_l_371a;
	case 14111ULL: goto x86_l_371f;
	case 14116ULL: goto x86_l_3724;
	case 14121ULL: goto x86_l_3729;
	case 14123ULL: goto x86_l_372b;
	case 14125ULL: goto x86_l_372d;
	case 14131ULL: goto x86_l_3733;
	case 14136ULL: goto x86_l_3738;
	case 14145ULL: goto x86_l_3741;
	case 14151ULL: goto x86_l_3747;
	case 14158ULL: goto x86_l_374e;
	case 14163ULL: goto x86_l_3753;
	case 14168ULL: goto x86_l_3758;
	case 14177ULL: goto x86_l_3761;
	case 14183ULL: goto x86_l_3767;
	case 14188ULL: goto x86_l_376c;
	case 14193ULL: goto x86_l_3771;
	case 14198ULL: goto x86_l_3776;
	case 14203ULL: goto x86_l_377b;
	case 14208ULL: goto x86_l_3780;
	case 14210ULL: goto x86_l_3782;
	case 14212ULL: goto x86_l_3784;
	case 14218ULL: goto x86_l_378a;
	case 14223ULL: goto x86_l_378f;
	case 14228ULL: goto x86_l_3794;
	case 14235ULL: goto x86_l_379b;
	case 14241ULL: goto x86_l_37a1;
	case 14244ULL: goto x86_l_37a4;
	case 14249ULL: goto x86_l_37a9;
	case 14254ULL: goto x86_l_37ae;
	case 14259ULL: goto x86_l_37b3;
	case 14264ULL: goto x86_l_37b8;
	case 14266ULL: goto x86_l_37ba;
	case 14268ULL: goto x86_l_37bc;
	case 14274ULL: goto x86_l_37c2;
	case 14281ULL: goto x86_l_37c9;
	case 14286ULL: goto x86_l_37ce;
	case 14289ULL: goto x86_l_37d1;
	case 14294ULL: goto x86_l_37d6;
	case 14299ULL: goto x86_l_37db;
	case 14304ULL: goto x86_l_37e0;
	case 14309ULL: goto x86_l_37e5;
	case 14312ULL: goto x86_l_37e8;
	case 14314ULL: goto x86_l_37ea;
	case 14316ULL: goto x86_l_37ec;
	case 14318ULL: goto x86_l_37ee;
	case 14326ULL: goto x86_l_37f6;
	case 14333ULL: goto x86_l_37fd;
	case 14340ULL: goto x86_l_3804;
	case 14345ULL: goto x86_l_3809;
	case 14348ULL: goto x86_l_380c;
	case 14353ULL: goto x86_l_3811;
	case 14358ULL: goto x86_l_3816;
	case 14363ULL: goto x86_l_381b;
	case 14371ULL: goto x86_l_3823;
	case 14378ULL: goto x86_l_382a;
	case 14385ULL: goto x86_l_3831;
	case 14390ULL: goto x86_l_3836;
	case 14393ULL: goto x86_l_3839;
	case 14398ULL: goto x86_l_383e;
	case 14400ULL: goto x86_l_3840;
	case 14402ULL: goto x86_l_3842;
	case 14408ULL: goto x86_l_3848;
	case 14411ULL: goto x86_l_384b;
	case 14416ULL: goto x86_l_3850;
	case 14418ULL: goto x86_l_3852;
	case 14421ULL: goto x86_l_3855;
	case 14430ULL: goto x86_l_385e;
	case 14436ULL: goto x86_l_3864;
	case 14443ULL: goto x86_l_386b;
	case 14446ULL: goto x86_l_386e;
	case 14453ULL: goto x86_l_3875;
	case 14456ULL: goto x86_l_3878;
	case 14461ULL: goto x86_l_387d;
	case 14469ULL: goto x86_l_3885;
	case 14471ULL: goto x86_l_3887;
	case 14477ULL: goto x86_l_388d;
	case 14480ULL: goto x86_l_3890;
	case 14482ULL: goto x86_l_3892;
	case 14487ULL: goto x86_l_3897;
	case 14492ULL: goto x86_l_389c;
	case 14497ULL: goto x86_l_38a1;
	case 14502ULL: goto x86_l_38a6;
	case 14507ULL: goto x86_l_38ab;
	case 14509ULL: goto x86_l_38ad;
	case 14511ULL: goto x86_l_38af;
	case 14517ULL: goto x86_l_38b5;
	case 14526ULL: goto x86_l_38be;
	case 14532ULL: goto x86_l_38c4;
	case 14539ULL: goto x86_l_38cb;
	case 14544ULL: goto x86_l_38d0;
	case 14549ULL: goto x86_l_38d5;
	case 14558ULL: goto x86_l_38de;
	case 14560ULL: goto x86_l_38e0;
	case 14565ULL: goto x86_l_38e5;
	case 14570ULL: goto x86_l_38ea;
	case 14575ULL: goto x86_l_38ef;
	case 14580ULL: goto x86_l_38f4;
	case 14585ULL: goto x86_l_38f9;
	case 14587ULL: goto x86_l_38fb;
	case 14589ULL: goto x86_l_38fd;
	case 14595ULL: goto x86_l_3903;
	case 14604ULL: goto x86_l_390c;
	case 14610ULL: goto x86_l_3912;
	case 14617ULL: goto x86_l_3919;
	case 14622ULL: goto x86_l_391e;
	case 14627ULL: goto x86_l_3923;
	case 14636ULL: goto x86_l_392c;
	case 14638ULL: goto x86_l_392e;
	case 14643ULL: goto x86_l_3933;
	case 14648ULL: goto x86_l_3938;
	case 14653ULL: goto x86_l_393d;
	case 14658ULL: goto x86_l_3942;
	case 14663ULL: goto x86_l_3947;
	case 14665ULL: goto x86_l_3949;
	case 14667ULL: goto x86_l_394b;
	case 14673ULL: goto x86_l_3951;
	case 14682ULL: goto x86_l_395a;
	case 14688ULL: goto x86_l_3960;
	case 14695ULL: goto x86_l_3967;
	case 14700ULL: goto x86_l_396c;
	case 14705ULL: goto x86_l_3971;
	case 14714ULL: goto x86_l_397a;
	case 14716ULL: goto x86_l_397c;
	case 14721ULL: goto x86_l_3981;
	case 14726ULL: goto x86_l_3986;
	case 14731ULL: goto x86_l_398b;
	case 14736ULL: goto x86_l_3990;
	case 14741ULL: goto x86_l_3995;
	case 14743ULL: goto x86_l_3997;
	case 14745ULL: goto x86_l_3999;
	case 14751ULL: goto x86_l_399f;
	case 14760ULL: goto x86_l_39a8;
	case 14766ULL: goto x86_l_39ae;
	case 14773ULL: goto x86_l_39b5;
	case 14778ULL: goto x86_l_39ba;
	case 14783ULL: goto x86_l_39bf;
	case 14792ULL: goto x86_l_39c8;
	case 14794ULL: goto x86_l_39ca;
	case 14799ULL: goto x86_l_39cf;
	case 14804ULL: goto x86_l_39d4;
	case 14809ULL: goto x86_l_39d9;
	case 14814ULL: goto x86_l_39de;
	case 14819ULL: goto x86_l_39e3;
	case 14821ULL: goto x86_l_39e5;
	case 14823ULL: goto x86_l_39e7;
	case 14829ULL: goto x86_l_39ed;
	case 14838ULL: goto x86_l_39f6;
	case 14844ULL: goto x86_l_39fc;
	case 14851ULL: goto x86_l_3a03;
	case 14856ULL: goto x86_l_3a08;
	case 14861ULL: goto x86_l_3a0d;
	case 14870ULL: goto x86_l_3a16;
	case 14872ULL: goto x86_l_3a18;
	case 14877ULL: goto x86_l_3a1d;
	case 14882ULL: goto x86_l_3a22;
	case 14887ULL: goto x86_l_3a27;
	case 14892ULL: goto x86_l_3a2c;
	case 14897ULL: goto x86_l_3a31;
	case 14899ULL: goto x86_l_3a33;
	case 14901ULL: goto x86_l_3a35;
	case 14907ULL: goto x86_l_3a3b;
	case 14916ULL: goto x86_l_3a44;
	case 14922ULL: goto x86_l_3a4a;
	case 14929ULL: goto x86_l_3a51;
	case 14934ULL: goto x86_l_3a56;
	case 14939ULL: goto x86_l_3a5b;
	case 14948ULL: goto x86_l_3a64;
	case 14950ULL: goto x86_l_3a66;
	case 14955ULL: goto x86_l_3a6b;
	case 14960ULL: goto x86_l_3a70;
	case 14965ULL: goto x86_l_3a75;
	case 14970ULL: goto x86_l_3a7a;
	case 14975ULL: goto x86_l_3a7f;
	case 14977ULL: goto x86_l_3a81;
	case 14979ULL: goto x86_l_3a83;
	case 14985ULL: goto x86_l_3a89;
	case 14994ULL: goto x86_l_3a92;
	case 15000ULL: goto x86_l_3a98;
	case 15007ULL: goto x86_l_3a9f;
	case 15012ULL: goto x86_l_3aa4;
	case 15017ULL: goto x86_l_3aa9;
	case 15026ULL: goto x86_l_3ab2;
	case 15028ULL: goto x86_l_3ab4;
	case 15033ULL: goto x86_l_3ab9;
	case 15038ULL: goto x86_l_3abe;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3310:
	/* 0x3310: js     61d9 <generic_sleepable_preload+0x61d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25049ULL;
	}
x86_l_3316:
	/* 0x3316: cmp    WORD PTR [r13+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_331f:
	/* 0x331f: je     642e <generic_sleepable_preload+0x642e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25646ULL;
	}
x86_l_3325:
	/* 0x3325: mov    ecx,DWORD PTR [r13+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_332c:
	/* 0x332c: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3331:
	/* 0x3331: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3336:
	/* 0x3336: cmp    WORD PTR [r13+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_333f:
	/* 0x333f: je     3364 <generic_sleepable_preload+0x3364> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3364;
	}
x86_l_3341:
	/* 0x3341: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3346:
	/* 0x3346: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_334b:
	/* 0x334b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3350:
	/* 0x3350: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3355:
	/* 0x3355: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_335a:
	/* 0x335a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_335c:
	/* 0x335c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_335e:
	/* 0x335e: js     623a <generic_sleepable_preload+0x623a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25146ULL;
	}
x86_l_3364:
	/* 0x3364: cmp    WORD PTR [r13+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_336d:
	/* 0x336d: je     642e <generic_sleepable_preload+0x642e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25646ULL;
	}
x86_l_3373:
	/* 0x3373: mov    ecx,DWORD PTR [r13+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_337a:
	/* 0x337a: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_337f:
	/* 0x337f: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3384:
	/* 0x3384: cmp    WORD PTR [r13+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_338d:
	/* 0x338d: je     33b2 <generic_sleepable_preload+0x33b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33b2;
	}
x86_l_338f:
	/* 0x338f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3394:
	/* 0x3394: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3399:
	/* 0x3399: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_339e:
	/* 0x339e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33a3:
	/* 0x33a3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33a8:
	/* 0x33a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33aa:
	/* 0x33aa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_33ac:
	/* 0x33ac: js     6427 <generic_sleepable_preload+0x6427> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25639ULL;
	}
x86_l_33b2:
	/* 0x33b2: cmp    WORD PTR [r13+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_33bb:
	/* 0x33bb: je     642e <generic_sleepable_preload+0x642e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25646ULL;
	}
x86_l_33c1:
	/* 0x33c1: mov    ecx,DWORD PTR [r13+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_33c8:
	/* 0x33c8: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_33cd:
	/* 0x33cd: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33d2:
	/* 0x33d2: cmp    WORD PTR [r13+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_33db:
	/* 0x33db: je     3400 <generic_sleepable_preload+0x3400> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3400;
	}
x86_l_33dd:
	/* 0x33dd: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33e2:
	/* 0x33e2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_33e7:
	/* 0x33e7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_33ec:
	/* 0x33ec: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33f1:
	/* 0x33f1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33f6:
	/* 0x33f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33f8:
	/* 0x33f8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_33fa:
	/* 0x33fa: js     68f4 <generic_sleepable_preload+0x68f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26868ULL;
	}
x86_l_3400:
	/* 0x3400: cmp    WORD PTR [r13+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_3409:
	/* 0x3409: je     642e <generic_sleepable_preload+0x642e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25646ULL;
	}
x86_l_340f:
	/* 0x340f: mov    ecx,DWORD PTR [r13+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_3416:
	/* 0x3416: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_341b:
	/* 0x341b: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3420:
	/* 0x3420: cmp    WORD PTR [r13+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_3429:
	/* 0x3429: je     344e <generic_sleepable_preload+0x344e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_344e;
	}
x86_l_342b:
	/* 0x342b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3430:
	/* 0x3430: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3435:
	/* 0x3435: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_343a:
	/* 0x343a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_343f:
	/* 0x343f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3444:
	/* 0x3444: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3446:
	/* 0x3446: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3448:
	/* 0x3448: js     6966 <generic_sleepable_preload+0x6966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26982ULL;
	}
x86_l_344e:
	/* 0x344e: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3453:
	/* 0x3453: cmp    WORD PTR [r13+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_345c:
	/* 0x345c: je     642e <generic_sleepable_preload+0x642e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25646ULL;
	}
x86_l_3462:
	/* 0x3462: mov    ecx,DWORD PTR [r13+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_3469:
	/* 0x3469: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_346e:
	/* 0x346e: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3473:
	/* 0x3473: cmp    WORD PTR [r13+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_347c:
	/* 0x347c: je     642e <generic_sleepable_preload+0x642e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25646ULL;
	}
x86_l_3482:
	/* 0x3482: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3487:
	/* 0x3487: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_348c:
	/* 0x348c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3491:
	/* 0x3491: jmp    3776 <generic_sleepable_preload+0x3776> */
	goto x86_l_3776;
x86_l_3496:
	/* 0x3496: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_3499:
	/* 0x3499: je     34be <generic_sleepable_preload+0x34be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_34be;
	}
x86_l_349b:
	/* 0x349b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34a0:
	/* 0x34a0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_34a5:
	/* 0x34a5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_34aa:
	/* 0x34aa: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34af:
	/* 0x34af: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_34b4:
	/* 0x34b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34b6:
	/* 0x34b6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_34b8:
	/* 0x34b8: js     3e89 <generic_sleepable_preload+0x3e89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 16009ULL;
	}
x86_l_34be:
	/* 0x34be: cmp    WORD PTR [r13+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_34c7:
	/* 0x34c7: je     642e <generic_sleepable_preload+0x642e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25646ULL;
	}
x86_l_34cd:
	/* 0x34cd: mov    ecx,DWORD PTR [r13+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_34d4:
	/* 0x34d4: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_34d9:
	/* 0x34d9: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34de:
	/* 0x34de: cmp    WORD PTR [r13+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_34e7:
	/* 0x34e7: je     350c <generic_sleepable_preload+0x350c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_350c;
	}
x86_l_34e9:
	/* 0x34e9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34ee:
	/* 0x34ee: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_34f3:
	/* 0x34f3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_34f8:
	/* 0x34f8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34fd:
	/* 0x34fd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3502:
	/* 0x3502: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3504:
	/* 0x3504: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3506:
	/* 0x3506: js     542a <generic_sleepable_preload+0x542a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21546ULL;
	}
x86_l_350c:
	/* 0x350c: cmp    WORD PTR [r13+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_3515:
	/* 0x3515: je     642e <generic_sleepable_preload+0x642e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25646ULL;
	}
x86_l_351b:
	/* 0x351b: mov    ecx,DWORD PTR [r13+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_3522:
	/* 0x3522: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3527:
	/* 0x3527: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_352c:
	/* 0x352c: cmp    WORD PTR [r13+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_3535:
	/* 0x3535: je     355a <generic_sleepable_preload+0x355a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_355a;
	}
x86_l_3537:
	/* 0x3537: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_353c:
	/* 0x353c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3541:
	/* 0x3541: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3546:
	/* 0x3546: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_354b:
	/* 0x354b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3550:
	/* 0x3550: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3552:
	/* 0x3552: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3554:
	/* 0x3554: js     6111 <generic_sleepable_preload+0x6111> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24849ULL;
	}
x86_l_355a:
	/* 0x355a: cmp    WORD PTR [r13+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_3563:
	/* 0x3563: je     642e <generic_sleepable_preload+0x642e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25646ULL;
	}
x86_l_3569:
	/* 0x3569: mov    ecx,DWORD PTR [r13+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_3570:
	/* 0x3570: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3575:
	/* 0x3575: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_357a:
	/* 0x357a: cmp    WORD PTR [r13+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_3583:
	/* 0x3583: je     35a8 <generic_sleepable_preload+0x35a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35a8;
	}
x86_l_3585:
	/* 0x3585: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_358a:
	/* 0x358a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_358f:
	/* 0x358f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3594:
	/* 0x3594: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3599:
	/* 0x3599: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_359e:
	/* 0x359e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35a0:
	/* 0x35a0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_35a2:
	/* 0x35a2: js     6175 <generic_sleepable_preload+0x6175> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24949ULL;
	}
x86_l_35a8:
	/* 0x35a8: cmp    WORD PTR [r13+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_35b1:
	/* 0x35b1: je     642e <generic_sleepable_preload+0x642e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25646ULL;
	}
x86_l_35b7:
	/* 0x35b7: mov    ecx,DWORD PTR [r13+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_35be:
	/* 0x35be: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_35c3:
	/* 0x35c3: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35c8:
	/* 0x35c8: cmp    WORD PTR [r13+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_35d1:
	/* 0x35d1: je     35f6 <generic_sleepable_preload+0x35f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35f6;
	}
x86_l_35d3:
	/* 0x35d3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35d8:
	/* 0x35d8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_35dd:
	/* 0x35dd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_35e2:
	/* 0x35e2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35e7:
	/* 0x35e7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_35ec:
	/* 0x35ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35ee:
	/* 0x35ee: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_35f0:
	/* 0x35f0: js     61d9 <generic_sleepable_preload+0x61d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25049ULL;
	}
x86_l_35f6:
	/* 0x35f6: cmp    WORD PTR [r13+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_35ff:
	/* 0x35ff: je     642e <generic_sleepable_preload+0x642e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25646ULL;
	}
x86_l_3605:
	/* 0x3605: mov    ecx,DWORD PTR [r13+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_360c:
	/* 0x360c: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3611:
	/* 0x3611: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3616:
	/* 0x3616: cmp    WORD PTR [r13+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_361f:
	/* 0x361f: je     3644 <generic_sleepable_preload+0x3644> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3644;
	}
x86_l_3621:
	/* 0x3621: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3626:
	/* 0x3626: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_362b:
	/* 0x362b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3630:
	/* 0x3630: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3635:
	/* 0x3635: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_363a:
	/* 0x363a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_363c:
	/* 0x363c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_363e:
	/* 0x363e: js     623a <generic_sleepable_preload+0x623a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25146ULL;
	}
x86_l_3644:
	/* 0x3644: cmp    WORD PTR [r13+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_364d:
	/* 0x364d: je     642e <generic_sleepable_preload+0x642e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25646ULL;
	}
x86_l_3653:
	/* 0x3653: mov    ecx,DWORD PTR [r13+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_365a:
	/* 0x365a: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_365f:
	/* 0x365f: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3664:
	/* 0x3664: cmp    WORD PTR [r13+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_366d:
	/* 0x366d: je     3692 <generic_sleepable_preload+0x3692> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3692;
	}
x86_l_366f:
	/* 0x366f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3674:
	/* 0x3674: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3679:
	/* 0x3679: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_367e:
	/* 0x367e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3683:
	/* 0x3683: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3688:
	/* 0x3688: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_368a:
	/* 0x368a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_368c:
	/* 0x368c: js     6427 <generic_sleepable_preload+0x6427> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25639ULL;
	}
x86_l_3692:
	/* 0x3692: cmp    WORD PTR [r13+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_369b:
	/* 0x369b: je     642e <generic_sleepable_preload+0x642e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25646ULL;
	}
x86_l_36a1:
	/* 0x36a1: mov    ecx,DWORD PTR [r13+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_36a8:
	/* 0x36a8: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_36ad:
	/* 0x36ad: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_36b2:
	/* 0x36b2: cmp    WORD PTR [r13+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_36bb:
	/* 0x36bb: je     36e0 <generic_sleepable_preload+0x36e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36e0;
	}
x86_l_36bd:
	/* 0x36bd: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_36c2:
	/* 0x36c2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_36c7:
	/* 0x36c7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_36cc:
	/* 0x36cc: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_36d1:
	/* 0x36d1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_36d6:
	/* 0x36d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36d8:
	/* 0x36d8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_36da:
	/* 0x36da: js     6a0a <generic_sleepable_preload+0x6a0a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27146ULL;
	}
x86_l_36e0:
	/* 0x36e0: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_36e5:
	/* 0x36e5: cmp    WORD PTR [r13+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_36ee:
	/* 0x36ee: je     642e <generic_sleepable_preload+0x642e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25646ULL;
	}
x86_l_36f4:
	/* 0x36f4: mov    ecx,DWORD PTR [r13+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_36fb:
	/* 0x36fb: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3700:
	/* 0x3700: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3705:
	/* 0x3705: cmp    WORD PTR [r13+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_370e:
	/* 0x370e: je     3733 <generic_sleepable_preload+0x3733> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3733;
	}
x86_l_3710:
	/* 0x3710: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3715:
	/* 0x3715: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_371a:
	/* 0x371a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_371f:
	/* 0x371f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3724:
	/* 0x3724: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3729:
	/* 0x3729: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_372b:
	/* 0x372b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_372d:
	/* 0x372d: js     6966 <generic_sleepable_preload+0x6966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26982ULL;
	}
x86_l_3733:
	/* 0x3733: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3738:
	/* 0x3738: cmp    WORD PTR [r13+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_3741:
	/* 0x3741: je     642e <generic_sleepable_preload+0x642e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25646ULL;
	}
x86_l_3747:
	/* 0x3747: mov    ecx,DWORD PTR [r13+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_374e:
	/* 0x374e: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3753:
	/* 0x3753: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3758:
	/* 0x3758: cmp    WORD PTR [r13+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_3761:
	/* 0x3761: je     642e <generic_sleepable_preload+0x642e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25646ULL;
	}
x86_l_3767:
	/* 0x3767: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_376c:
	/* 0x376c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3771:
	/* 0x3771: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3776:
	/* 0x3776: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_377b:
	/* 0x377b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3780:
	/* 0x3780: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3782:
	/* 0x3782: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3784:
	/* 0x3784: jns    642e <generic_sleepable_preload+0x642e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 25646ULL;
	}
x86_l_378a:
	/* 0x378a: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_378f:
	/* 0x378f: jmp    642c <generic_sleepable_preload+0x642c> */
	return 25644ULL;
x86_l_3794:
	/* 0x3794: mov    edx,DWORD PTR [r13+0x268] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 616ULL);
x86_l_379b:
	/* 0x379b: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_37a1:
	/* 0x37a1: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_37a4:
	/* 0x37a4: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_37a9:
	/* 0x37a9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_37ae:
	/* 0x37ae: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_37b3:
	/* 0x37b3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_37b8:
	/* 0x37b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37ba:
	/* 0x37ba: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_37bc:
	/* 0x37bc: jne    3848 <generic_sleepable_preload+0x3848> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3848;
	}
x86_l_37c2:
	/* 0x37c2: mov    eax,DWORD PTR [r13+0x26c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 620ULL);
x86_l_37c9:
	/* 0x37c9: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_37ce:
	/* 0x37ce: add    rbx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_37d1:
	/* 0x37d1: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_37d6:
	/* 0x37d6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_37db:
	/* 0x37db: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_37e0:
	/* 0x37e0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_37e5:
	/* 0x37e5: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_37e8:
	/* 0x37e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37ea:
	/* 0x37ea: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_37ec:
	/* 0x37ec: jne    3848 <generic_sleepable_preload+0x3848> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3848;
	}
x86_l_37ee:
	/* 0x37ee: movzx  eax,BYTE PTR [r13+0x273] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 627ULL);
x86_l_37f6:
	/* 0x37f6: shlx   rax,QWORD PTR [rsp+0x8],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_37fd:
	/* 0x37fd: mov    rcx,QWORD PTR [r13+0x260] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 608ULL);
x86_l_3804:
	/* 0x3804: add    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_3809:
	/* 0x3809: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_380c:
	/* 0x380c: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3811:
	/* 0x3811: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3816:
	/* 0x3816: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_381b:
	/* 0x381b: movzx  ecx,BYTE PTR [r13+0x273] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 627ULL);
x86_l_3823:
	/* 0x3823: shlx   rcx,QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_382a:
	/* 0x382a: mov    rdx,QWORD PTR [r13+0x260] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 608ULL);
x86_l_3831:
	/* 0x3831: add    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_3836:
	/* 0x3836: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3839:
	/* 0x3839: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_383e:
	/* 0x383e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3840:
	/* 0x3840: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3842:
	/* 0x3842: je     1c65 <generic_sleepable_preload+0x1c65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7269ULL;
	}
x86_l_3848:
	/* 0x3848: movsxd rcx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_384b:
	/* 0x384b: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3850:
	/* 0x3850: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3852:
	/* 0x3852: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_3855:
	/* 0x3855: cmp    WORD PTR [r13+0x1b6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1881195675648ULL);
x86_l_385e:
	/* 0x385e: je     64bc <generic_sleepable_preload+0x64bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25788ULL;
	}
x86_l_3864:
	/* 0x3864: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_386b:
	/* 0x386b: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_386e:
	/* 0x386e: mov    eax,DWORD PTR [r13+0x1b0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 432ULL);
x86_l_3875:
	/* 0x3875: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3878:
	/* 0x3878: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_387d:
	/* 0x387d: movzx  eax,WORD PTR [r13+0x1b4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 436ULL);
x86_l_3885:
	/* 0x3885: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_3887:
	/* 0x3887: je     3b6d <generic_sleepable_preload+0x3b6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15213ULL;
	}
x86_l_388d:
	/* 0x388d: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_3890:
	/* 0x3890: je     38b5 <generic_sleepable_preload+0x38b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38b5;
	}
x86_l_3892:
	/* 0x3892: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3897:
	/* 0x3897: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_389c:
	/* 0x389c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_38a1:
	/* 0x38a1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_38a6:
	/* 0x38a6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_38ab:
	/* 0x38ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38ad:
	/* 0x38ad: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_38af:
	/* 0x38af: js     3e93 <generic_sleepable_preload+0x3e93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 16019ULL;
	}
x86_l_38b5:
	/* 0x38b5: cmp    WORD PTR [r13+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_38be:
	/* 0x38be: je     64bc <generic_sleepable_preload+0x64bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25788ULL;
	}
x86_l_38c4:
	/* 0x38c4: mov    ecx,DWORD PTR [r13+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_38cb:
	/* 0x38cb: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_38d0:
	/* 0x38d0: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_38d5:
	/* 0x38d5: cmp    WORD PTR [r13+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_38de:
	/* 0x38de: je     3903 <generic_sleepable_preload+0x3903> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3903;
	}
x86_l_38e0:
	/* 0x38e0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_38e5:
	/* 0x38e5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_38ea:
	/* 0x38ea: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_38ef:
	/* 0x38ef: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_38f4:
	/* 0x38f4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_38f9:
	/* 0x38f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38fb:
	/* 0x38fb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_38fd:
	/* 0x38fd: js     5434 <generic_sleepable_preload+0x5434> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21556ULL;
	}
x86_l_3903:
	/* 0x3903: cmp    WORD PTR [r13+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_390c:
	/* 0x390c: je     64bc <generic_sleepable_preload+0x64bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25788ULL;
	}
x86_l_3912:
	/* 0x3912: mov    ecx,DWORD PTR [r13+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_3919:
	/* 0x3919: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_391e:
	/* 0x391e: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3923:
	/* 0x3923: cmp    WORD PTR [r13+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_392c:
	/* 0x392c: je     3951 <generic_sleepable_preload+0x3951> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3951;
	}
x86_l_392e:
	/* 0x392e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3933:
	/* 0x3933: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3938:
	/* 0x3938: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_393d:
	/* 0x393d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3942:
	/* 0x3942: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3947:
	/* 0x3947: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3949:
	/* 0x3949: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_394b:
	/* 0x394b: js     611b <generic_sleepable_preload+0x611b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24859ULL;
	}
x86_l_3951:
	/* 0x3951: cmp    WORD PTR [r13+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_395a:
	/* 0x395a: je     64bc <generic_sleepable_preload+0x64bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25788ULL;
	}
x86_l_3960:
	/* 0x3960: mov    ecx,DWORD PTR [r13+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_3967:
	/* 0x3967: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_396c:
	/* 0x396c: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3971:
	/* 0x3971: cmp    WORD PTR [r13+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_397a:
	/* 0x397a: je     399f <generic_sleepable_preload+0x399f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_399f;
	}
x86_l_397c:
	/* 0x397c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3981:
	/* 0x3981: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3986:
	/* 0x3986: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_398b:
	/* 0x398b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3990:
	/* 0x3990: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3995:
	/* 0x3995: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3997:
	/* 0x3997: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3999:
	/* 0x3999: js     617f <generic_sleepable_preload+0x617f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24959ULL;
	}
x86_l_399f:
	/* 0x399f: cmp    WORD PTR [r13+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_39a8:
	/* 0x39a8: je     64bc <generic_sleepable_preload+0x64bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25788ULL;
	}
x86_l_39ae:
	/* 0x39ae: mov    ecx,DWORD PTR [r13+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_39b5:
	/* 0x39b5: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_39ba:
	/* 0x39ba: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39bf:
	/* 0x39bf: cmp    WORD PTR [r13+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_39c8:
	/* 0x39c8: je     39ed <generic_sleepable_preload+0x39ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_39ed;
	}
x86_l_39ca:
	/* 0x39ca: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39cf:
	/* 0x39cf: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_39d4:
	/* 0x39d4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_39d9:
	/* 0x39d9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39de:
	/* 0x39de: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_39e3:
	/* 0x39e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39e5:
	/* 0x39e5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_39e7:
	/* 0x39e7: js     61e3 <generic_sleepable_preload+0x61e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25059ULL;
	}
x86_l_39ed:
	/* 0x39ed: cmp    WORD PTR [r13+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_39f6:
	/* 0x39f6: je     64bc <generic_sleepable_preload+0x64bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25788ULL;
	}
x86_l_39fc:
	/* 0x39fc: mov    ecx,DWORD PTR [r13+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_3a03:
	/* 0x3a03: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3a08:
	/* 0x3a08: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a0d:
	/* 0x3a0d: cmp    WORD PTR [r13+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_3a16:
	/* 0x3a16: je     3a3b <generic_sleepable_preload+0x3a3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a3b;
	}
x86_l_3a18:
	/* 0x3a18: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a1d:
	/* 0x3a1d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3a22:
	/* 0x3a22: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3a27:
	/* 0x3a27: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a2c:
	/* 0x3a2c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a31:
	/* 0x3a31: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a33:
	/* 0x3a33: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3a35:
	/* 0x3a35: js     6244 <generic_sleepable_preload+0x6244> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25156ULL;
	}
x86_l_3a3b:
	/* 0x3a3b: cmp    WORD PTR [r13+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_3a44:
	/* 0x3a44: je     64bc <generic_sleepable_preload+0x64bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25788ULL;
	}
x86_l_3a4a:
	/* 0x3a4a: mov    ecx,DWORD PTR [r13+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_3a51:
	/* 0x3a51: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3a56:
	/* 0x3a56: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a5b:
	/* 0x3a5b: cmp    WORD PTR [r13+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_3a64:
	/* 0x3a64: je     3a89 <generic_sleepable_preload+0x3a89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a89;
	}
x86_l_3a66:
	/* 0x3a66: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a6b:
	/* 0x3a6b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3a70:
	/* 0x3a70: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3a75:
	/* 0x3a75: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a7a:
	/* 0x3a7a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a7f:
	/* 0x3a7f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a81:
	/* 0x3a81: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3a83:
	/* 0x3a83: js     64b4 <generic_sleepable_preload+0x64b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25780ULL;
	}
x86_l_3a89:
	/* 0x3a89: cmp    WORD PTR [r13+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_3a92:
	/* 0x3a92: je     64bc <generic_sleepable_preload+0x64bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25788ULL;
	}
x86_l_3a98:
	/* 0x3a98: mov    ecx,DWORD PTR [r13+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_3a9f:
	/* 0x3a9f: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3aa4:
	/* 0x3aa4: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3aa9:
	/* 0x3aa9: cmp    WORD PTR [r13+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_3ab2:
	/* 0x3ab2: je     3ad7 <generic_sleepable_preload+0x3ad7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15063ULL;
	}
x86_l_3ab4:
	/* 0x3ab4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3ab9:
	/* 0x3ab9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3abe:
	/* 0x3abe: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
	return 15043ULL;
}

static __noinline __u64 tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 15043ULL: goto x86_l_3ac3;
	case 15048ULL: goto x86_l_3ac8;
	case 15053ULL: goto x86_l_3acd;
	case 15055ULL: goto x86_l_3acf;
	case 15057ULL: goto x86_l_3ad1;
	case 15063ULL: goto x86_l_3ad7;
	case 15072ULL: goto x86_l_3ae0;
	case 15078ULL: goto x86_l_3ae6;
	case 15085ULL: goto x86_l_3aed;
	case 15090ULL: goto x86_l_3af2;
	case 15095ULL: goto x86_l_3af7;
	case 15104ULL: goto x86_l_3b00;
	case 15106ULL: goto x86_l_3b02;
	case 15111ULL: goto x86_l_3b07;
	case 15116ULL: goto x86_l_3b0c;
	case 15121ULL: goto x86_l_3b11;
	case 15126ULL: goto x86_l_3b16;
	case 15131ULL: goto x86_l_3b1b;
	case 15133ULL: goto x86_l_3b1d;
	case 15135ULL: goto x86_l_3b1f;
	case 15141ULL: goto x86_l_3b25;
	case 15146ULL: goto x86_l_3b2a;
	case 15155ULL: goto x86_l_3b33;
	case 15161ULL: goto x86_l_3b39;
	case 15168ULL: goto x86_l_3b40;
	case 15173ULL: goto x86_l_3b45;
	case 15178ULL: goto x86_l_3b4a;
	case 15187ULL: goto x86_l_3b53;
	case 15193ULL: goto x86_l_3b59;
	case 15198ULL: goto x86_l_3b5e;
	case 15203ULL: goto x86_l_3b63;
	case 15208ULL: goto x86_l_3b68;
	case 15213ULL: goto x86_l_3b6d;
	case 15216ULL: goto x86_l_3b70;
	case 15218ULL: goto x86_l_3b72;
	case 15223ULL: goto x86_l_3b77;
	case 15228ULL: goto x86_l_3b7c;
	case 15233ULL: goto x86_l_3b81;
	case 15238ULL: goto x86_l_3b86;
	case 15243ULL: goto x86_l_3b8b;
	case 15245ULL: goto x86_l_3b8d;
	case 15247ULL: goto x86_l_3b8f;
	case 15253ULL: goto x86_l_3b95;
	case 15262ULL: goto x86_l_3b9e;
	case 15268ULL: goto x86_l_3ba4;
	case 15275ULL: goto x86_l_3bab;
	case 15280ULL: goto x86_l_3bb0;
	case 15285ULL: goto x86_l_3bb5;
	case 15294ULL: goto x86_l_3bbe;
	case 15296ULL: goto x86_l_3bc0;
	case 15301ULL: goto x86_l_3bc5;
	case 15306ULL: goto x86_l_3bca;
	case 15311ULL: goto x86_l_3bcf;
	case 15316ULL: goto x86_l_3bd4;
	case 15321ULL: goto x86_l_3bd9;
	case 15323ULL: goto x86_l_3bdb;
	case 15325ULL: goto x86_l_3bdd;
	case 15331ULL: goto x86_l_3be3;
	case 15340ULL: goto x86_l_3bec;
	case 15346ULL: goto x86_l_3bf2;
	case 15353ULL: goto x86_l_3bf9;
	case 15358ULL: goto x86_l_3bfe;
	case 15363ULL: goto x86_l_3c03;
	case 15372ULL: goto x86_l_3c0c;
	case 15374ULL: goto x86_l_3c0e;
	case 15379ULL: goto x86_l_3c13;
	case 15384ULL: goto x86_l_3c18;
	case 15389ULL: goto x86_l_3c1d;
	case 15394ULL: goto x86_l_3c22;
	case 15399ULL: goto x86_l_3c27;
	case 15401ULL: goto x86_l_3c29;
	case 15403ULL: goto x86_l_3c2b;
	case 15409ULL: goto x86_l_3c31;
	case 15418ULL: goto x86_l_3c3a;
	case 15424ULL: goto x86_l_3c40;
	case 15431ULL: goto x86_l_3c47;
	case 15436ULL: goto x86_l_3c4c;
	case 15441ULL: goto x86_l_3c51;
	case 15450ULL: goto x86_l_3c5a;
	case 15452ULL: goto x86_l_3c5c;
	case 15457ULL: goto x86_l_3c61;
	case 15462ULL: goto x86_l_3c66;
	case 15467ULL: goto x86_l_3c6b;
	case 15472ULL: goto x86_l_3c70;
	case 15477ULL: goto x86_l_3c75;
	case 15479ULL: goto x86_l_3c77;
	case 15481ULL: goto x86_l_3c79;
	case 15487ULL: goto x86_l_3c7f;
	case 15496ULL: goto x86_l_3c88;
	case 15502ULL: goto x86_l_3c8e;
	case 15509ULL: goto x86_l_3c95;
	case 15514ULL: goto x86_l_3c9a;
	case 15519ULL: goto x86_l_3c9f;
	case 15528ULL: goto x86_l_3ca8;
	case 15530ULL: goto x86_l_3caa;
	case 15535ULL: goto x86_l_3caf;
	case 15540ULL: goto x86_l_3cb4;
	case 15545ULL: goto x86_l_3cb9;
	case 15550ULL: goto x86_l_3cbe;
	case 15555ULL: goto x86_l_3cc3;
	case 15557ULL: goto x86_l_3cc5;
	case 15559ULL: goto x86_l_3cc7;
	case 15565ULL: goto x86_l_3ccd;
	case 15574ULL: goto x86_l_3cd6;
	case 15580ULL: goto x86_l_3cdc;
	case 15587ULL: goto x86_l_3ce3;
	case 15592ULL: goto x86_l_3ce8;
	case 15597ULL: goto x86_l_3ced;
	case 15606ULL: goto x86_l_3cf6;
	case 15608ULL: goto x86_l_3cf8;
	case 15613ULL: goto x86_l_3cfd;
	case 15618ULL: goto x86_l_3d02;
	case 15623ULL: goto x86_l_3d07;
	case 15628ULL: goto x86_l_3d0c;
	case 15633ULL: goto x86_l_3d11;
	case 15635ULL: goto x86_l_3d13;
	case 15637ULL: goto x86_l_3d15;
	case 15643ULL: goto x86_l_3d1b;
	case 15652ULL: goto x86_l_3d24;
	case 15658ULL: goto x86_l_3d2a;
	case 15665ULL: goto x86_l_3d31;
	case 15670ULL: goto x86_l_3d36;
	case 15675ULL: goto x86_l_3d3b;
	case 15684ULL: goto x86_l_3d44;
	case 15686ULL: goto x86_l_3d46;
	case 15691ULL: goto x86_l_3d4b;
	case 15696ULL: goto x86_l_3d50;
	case 15701ULL: goto x86_l_3d55;
	case 15706ULL: goto x86_l_3d5a;
	case 15711ULL: goto x86_l_3d5f;
	case 15713ULL: goto x86_l_3d61;
	case 15715ULL: goto x86_l_3d63;
	case 15721ULL: goto x86_l_3d69;
	case 15730ULL: goto x86_l_3d72;
	case 15736ULL: goto x86_l_3d78;
	case 15743ULL: goto x86_l_3d7f;
	case 15748ULL: goto x86_l_3d84;
	case 15753ULL: goto x86_l_3d89;
	case 15762ULL: goto x86_l_3d92;
	case 15764ULL: goto x86_l_3d94;
	case 15769ULL: goto x86_l_3d99;
	case 15774ULL: goto x86_l_3d9e;
	case 15779ULL: goto x86_l_3da3;
	case 15784ULL: goto x86_l_3da8;
	case 15789ULL: goto x86_l_3dad;
	case 15791ULL: goto x86_l_3daf;
	case 15793ULL: goto x86_l_3db1;
	case 15799ULL: goto x86_l_3db7;
	case 15804ULL: goto x86_l_3dbc;
	case 15813ULL: goto x86_l_3dc5;
	case 15819ULL: goto x86_l_3dcb;
	case 15826ULL: goto x86_l_3dd2;
	case 15831ULL: goto x86_l_3dd7;
	case 15836ULL: goto x86_l_3ddc;
	case 15845ULL: goto x86_l_3de5;
	case 15847ULL: goto x86_l_3de7;
	case 15852ULL: goto x86_l_3dec;
	case 15857ULL: goto x86_l_3df1;
	case 15862ULL: goto x86_l_3df6;
	case 15867ULL: goto x86_l_3dfb;
	case 15872ULL: goto x86_l_3e00;
	case 15874ULL: goto x86_l_3e02;
	case 15876ULL: goto x86_l_3e04;
	case 15882ULL: goto x86_l_3e0a;
	case 15887ULL: goto x86_l_3e0f;
	case 15896ULL: goto x86_l_3e18;
	case 15902ULL: goto x86_l_3e1e;
	case 15909ULL: goto x86_l_3e25;
	case 15914ULL: goto x86_l_3e2a;
	case 15919ULL: goto x86_l_3e2f;
	case 15928ULL: goto x86_l_3e38;
	case 15934ULL: goto x86_l_3e3e;
	case 15939ULL: goto x86_l_3e43;
	case 15944ULL: goto x86_l_3e48;
	case 15949ULL: goto x86_l_3e4d;
	case 15954ULL: goto x86_l_3e52;
	case 15959ULL: goto x86_l_3e57;
	case 15961ULL: goto x86_l_3e59;
	case 15963ULL: goto x86_l_3e5b;
	case 15969ULL: goto x86_l_3e61;
	case 15974ULL: goto x86_l_3e66;
	case 15979ULL: goto x86_l_3e6b;
	case 15984ULL: goto x86_l_3e70;
	case 15989ULL: goto x86_l_3e75;
	case 15994ULL: goto x86_l_3e7a;
	case 15999ULL: goto x86_l_3e7f;
	case 16004ULL: goto x86_l_3e84;
	case 16009ULL: goto x86_l_3e89;
	case 16014ULL: goto x86_l_3e8e;
	case 16019ULL: goto x86_l_3e93;
	case 16024ULL: goto x86_l_3e98;
	case 16029ULL: goto x86_l_3e9d;
	case 16037ULL: goto x86_l_3ea5;
	case 16040ULL: goto x86_l_3ea8;
	case 16046ULL: goto x86_l_3eae;
	case 16051ULL: goto x86_l_3eb3;
	case 16054ULL: goto x86_l_3eb6;
	case 16060ULL: goto x86_l_3ebc;
	case 16065ULL: goto x86_l_3ec1;
	case 16073ULL: goto x86_l_3ec9;
	case 16076ULL: goto x86_l_3ecc;
	case 16082ULL: goto x86_l_3ed2;
	case 16087ULL: goto x86_l_3ed7;
	case 16090ULL: goto x86_l_3eda;
	case 16096ULL: goto x86_l_3ee0;
	case 16101ULL: goto x86_l_3ee5;
	case 16109ULL: goto x86_l_3eed;
	case 16112ULL: goto x86_l_3ef0;
	case 16118ULL: goto x86_l_3ef6;
	case 16123ULL: goto x86_l_3efb;
	case 16126ULL: goto x86_l_3efe;
	case 16132ULL: goto x86_l_3f04;
	case 16137ULL: goto x86_l_3f09;
	case 16145ULL: goto x86_l_3f11;
	case 16148ULL: goto x86_l_3f14;
	case 16154ULL: goto x86_l_3f1a;
	case 16159ULL: goto x86_l_3f1f;
	case 16162ULL: goto x86_l_3f22;
	case 16168ULL: goto x86_l_3f28;
	case 16173ULL: goto x86_l_3f2d;
	case 16181ULL: goto x86_l_3f35;
	case 16184ULL: goto x86_l_3f38;
	case 16190ULL: goto x86_l_3f3e;
	case 16195ULL: goto x86_l_3f43;
	case 16198ULL: goto x86_l_3f46;
	case 16204ULL: goto x86_l_3f4c;
	case 16209ULL: goto x86_l_3f51;
	case 16217ULL: goto x86_l_3f59;
	case 16220ULL: goto x86_l_3f5c;
	case 16226ULL: goto x86_l_3f62;
	case 16231ULL: goto x86_l_3f67;
	case 16234ULL: goto x86_l_3f6a;
	case 16240ULL: goto x86_l_3f70;
	case 16245ULL: goto x86_l_3f75;
	case 16253ULL: goto x86_l_3f7d;
	case 16256ULL: goto x86_l_3f80;
	case 16262ULL: goto x86_l_3f86;
	case 16267ULL: goto x86_l_3f8b;
	case 16270ULL: goto x86_l_3f8e;
	case 16276ULL: goto x86_l_3f94;
	case 16281ULL: goto x86_l_3f99;
	case 16289ULL: goto x86_l_3fa1;
	case 16292ULL: goto x86_l_3fa4;
	case 16298ULL: goto x86_l_3faa;
	case 16303ULL: goto x86_l_3faf;
	case 16306ULL: goto x86_l_3fb2;
	case 16312ULL: goto x86_l_3fb8;
	case 16317ULL: goto x86_l_3fbd;
	case 16325ULL: goto x86_l_3fc5;
	case 16328ULL: goto x86_l_3fc8;
	case 16334ULL: goto x86_l_3fce;
	case 16339ULL: goto x86_l_3fd3;
	case 16342ULL: goto x86_l_3fd6;
	case 16348ULL: goto x86_l_3fdc;
	case 16353ULL: goto x86_l_3fe1;
	case 16361ULL: goto x86_l_3fe9;
	case 16364ULL: goto x86_l_3fec;
	case 16370ULL: goto x86_l_3ff2;
	case 16375ULL: goto x86_l_3ff7;
	case 16378ULL: goto x86_l_3ffa;
	case 16384ULL: goto x86_l_4000;
	case 16389ULL: goto x86_l_4005;
	case 16397ULL: goto x86_l_400d;
	case 16400ULL: goto x86_l_4010;
	case 16406ULL: goto x86_l_4016;
	case 16411ULL: goto x86_l_401b;
	case 16414ULL: goto x86_l_401e;
	case 16420ULL: goto x86_l_4024;
	case 16425ULL: goto x86_l_4029;
	case 16433ULL: goto x86_l_4031;
	case 16436ULL: goto x86_l_4034;
	case 16442ULL: goto x86_l_403a;
	case 16447ULL: goto x86_l_403f;
	case 16450ULL: goto x86_l_4042;
	case 16456ULL: goto x86_l_4048;
	case 16461ULL: goto x86_l_404d;
	case 16469ULL: goto x86_l_4055;
	case 16472ULL: goto x86_l_4058;
	case 16478ULL: goto x86_l_405e;
	case 16483ULL: goto x86_l_4063;
	case 16486ULL: goto x86_l_4066;
	case 16492ULL: goto x86_l_406c;
	case 16497ULL: goto x86_l_4071;
	case 16505ULL: goto x86_l_4079;
	case 16508ULL: goto x86_l_407c;
	case 16514ULL: goto x86_l_4082;
	case 16519ULL: goto x86_l_4087;
	case 16522ULL: goto x86_l_408a;
	case 16528ULL: goto x86_l_4090;
	case 16533ULL: goto x86_l_4095;
	case 16541ULL: goto x86_l_409d;
	case 16544ULL: goto x86_l_40a0;
	case 16550ULL: goto x86_l_40a6;
	case 16555ULL: goto x86_l_40ab;
	case 16558ULL: goto x86_l_40ae;
	case 16564ULL: goto x86_l_40b4;
	case 16569ULL: goto x86_l_40b9;
	case 16577ULL: goto x86_l_40c1;
	case 16580ULL: goto x86_l_40c4;
	case 16582ULL: goto x86_l_40c6;
	case 16587ULL: goto x86_l_40cb;
	case 16590ULL: goto x86_l_40ce;
	case 16592ULL: goto x86_l_40d0;
	case 16595ULL: goto x86_l_40d3;
	case 16597ULL: goto x86_l_40d5;
	case 16599ULL: goto x86_l_40d7;
	case 16604ULL: goto x86_l_40dc;
	case 16606ULL: goto x86_l_40de;
	case 16611ULL: goto x86_l_40e3;
	case 16616ULL: goto x86_l_40e8;
	case 16620ULL: goto x86_l_40ec;
	case 16622ULL: goto x86_l_40ee;
	case 16625ULL: goto x86_l_40f1;
	case 16631ULL: goto x86_l_40f7;
	case 16637ULL: goto x86_l_40fd;
	case 16644ULL: goto x86_l_4104;
	case 16647ULL: goto x86_l_4107;
	case 16651ULL: goto x86_l_410b;
	case 16654ULL: goto x86_l_410e;
	case 16659ULL: goto x86_l_4113;
	case 16664ULL: goto x86_l_4118;
	case 16666ULL: goto x86_l_411a;
	case 16672ULL: goto x86_l_4120;
	case 16675ULL: goto x86_l_4123;
	case 16677ULL: goto x86_l_4125;
	case 16682ULL: goto x86_l_412a;
	case 16687ULL: goto x86_l_412f;
	case 16692ULL: goto x86_l_4134;
	case 16697ULL: goto x86_l_4139;
	case 16702ULL: goto x86_l_413e;
	case 16704ULL: goto x86_l_4140;
	case 16706ULL: goto x86_l_4142;
	case 16712ULL: goto x86_l_4148;
	case 16718ULL: goto x86_l_414e;
	case 16724ULL: goto x86_l_4154;
	case 16728ULL: goto x86_l_4158;
	case 16733ULL: goto x86_l_415d;
	case 16738ULL: goto x86_l_4162;
	case 16744ULL: goto x86_l_4168;
	case 16746ULL: goto x86_l_416a;
	case 16751ULL: goto x86_l_416f;
	case 16756ULL: goto x86_l_4174;
	case 16761ULL: goto x86_l_4179;
	case 16766ULL: goto x86_l_417e;
	case 16771ULL: goto x86_l_4183;
	case 16773ULL: goto x86_l_4185;
	case 16775ULL: goto x86_l_4187;
	case 16781ULL: goto x86_l_418d;
	case 16790ULL: goto x86_l_4196;
	case 16796ULL: goto x86_l_419c;
	case 16803ULL: goto x86_l_41a3;
	case 16808ULL: goto x86_l_41a8;
	case 16813ULL: goto x86_l_41ad;
	case 16822ULL: goto x86_l_41b6;
	case 16824ULL: goto x86_l_41b8;
	case 16829ULL: goto x86_l_41bd;
	case 16834ULL: goto x86_l_41c2;
	case 16839ULL: goto x86_l_41c7;
	case 16844ULL: goto x86_l_41cc;
	case 16849ULL: goto x86_l_41d1;
	case 16851ULL: goto x86_l_41d3;
	case 16853ULL: goto x86_l_41d5;
	case 16859ULL: goto x86_l_41db;
	case 16868ULL: goto x86_l_41e4;
	case 16874ULL: goto x86_l_41ea;
	case 16881ULL: goto x86_l_41f1;
	case 16886ULL: goto x86_l_41f6;
	case 16891ULL: goto x86_l_41fb;
	case 16900ULL: goto x86_l_4204;
	case 16902ULL: goto x86_l_4206;
	case 16907ULL: goto x86_l_420b;
	case 16912ULL: goto x86_l_4210;
	case 16917ULL: goto x86_l_4215;
	case 16922ULL: goto x86_l_421a;
	case 16927ULL: goto x86_l_421f;
	case 16929ULL: goto x86_l_4221;
	case 16931ULL: goto x86_l_4223;
	case 16937ULL: goto x86_l_4229;
	case 16946ULL: goto x86_l_4232;
	case 16952ULL: goto x86_l_4238;
	case 16959ULL: goto x86_l_423f;
	case 16964ULL: goto x86_l_4244;
	case 16969ULL: goto x86_l_4249;
	case 16978ULL: goto x86_l_4252;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3ac3:
	/* 0x3ac3: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3ac8:
	/* 0x3ac8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3acd:
	/* 0x3acd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3acf:
	/* 0x3acf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3ad1:
	/* 0x3ad1: js     6900 <generic_sleepable_preload+0x6900> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26880ULL;
	}
x86_l_3ad7:
	/* 0x3ad7: cmp    WORD PTR [r13+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_3ae0:
	/* 0x3ae0: je     64bc <generic_sleepable_preload+0x64bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25788ULL;
	}
x86_l_3ae6:
	/* 0x3ae6: mov    ecx,DWORD PTR [r13+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_3aed:
	/* 0x3aed: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3af2:
	/* 0x3af2: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3af7:
	/* 0x3af7: cmp    WORD PTR [r13+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_3b00:
	/* 0x3b00: je     3b25 <generic_sleepable_preload+0x3b25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3b25;
	}
x86_l_3b02:
	/* 0x3b02: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b07:
	/* 0x3b07: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3b0c:
	/* 0x3b0c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3b11:
	/* 0x3b11: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b16:
	/* 0x3b16: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b1b:
	/* 0x3b1b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b1d:
	/* 0x3b1d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3b1f:
	/* 0x3b1f: js     6977 <generic_sleepable_preload+0x6977> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26999ULL;
	}
x86_l_3b25:
	/* 0x3b25: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3b2a:
	/* 0x3b2a: cmp    WORD PTR [r13+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_3b33:
	/* 0x3b33: je     64bc <generic_sleepable_preload+0x64bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25788ULL;
	}
x86_l_3b39:
	/* 0x3b39: mov    ecx,DWORD PTR [r13+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_3b40:
	/* 0x3b40: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3b45:
	/* 0x3b45: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b4a:
	/* 0x3b4a: cmp    WORD PTR [r13+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_3b53:
	/* 0x3b53: je     64bc <generic_sleepable_preload+0x64bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25788ULL;
	}
x86_l_3b59:
	/* 0x3b59: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b5e:
	/* 0x3b5e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3b63:
	/* 0x3b63: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3b68:
	/* 0x3b68: jmp    3e4d <generic_sleepable_preload+0x3e4d> */
	goto x86_l_3e4d;
x86_l_3b6d:
	/* 0x3b6d: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_3b70:
	/* 0x3b70: je     3b95 <generic_sleepable_preload+0x3b95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3b95;
	}
x86_l_3b72:
	/* 0x3b72: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b77:
	/* 0x3b77: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3b7c:
	/* 0x3b7c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3b81:
	/* 0x3b81: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b86:
	/* 0x3b86: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b8b:
	/* 0x3b8b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b8d:
	/* 0x3b8d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3b8f:
	/* 0x3b8f: js     3e93 <generic_sleepable_preload+0x3e93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3e93;
	}
x86_l_3b95:
	/* 0x3b95: cmp    WORD PTR [r13+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_3b9e:
	/* 0x3b9e: je     64bc <generic_sleepable_preload+0x64bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25788ULL;
	}
x86_l_3ba4:
	/* 0x3ba4: mov    ecx,DWORD PTR [r13+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_3bab:
	/* 0x3bab: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3bb0:
	/* 0x3bb0: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3bb5:
	/* 0x3bb5: cmp    WORD PTR [r13+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_3bbe:
	/* 0x3bbe: je     3be3 <generic_sleepable_preload+0x3be3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3be3;
	}
x86_l_3bc0:
	/* 0x3bc0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3bc5:
	/* 0x3bc5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3bca:
	/* 0x3bca: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3bcf:
	/* 0x3bcf: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3bd4:
	/* 0x3bd4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3bd9:
	/* 0x3bd9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3bdb:
	/* 0x3bdb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3bdd:
	/* 0x3bdd: js     5434 <generic_sleepable_preload+0x5434> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21556ULL;
	}
x86_l_3be3:
	/* 0x3be3: cmp    WORD PTR [r13+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_3bec:
	/* 0x3bec: je     64bc <generic_sleepable_preload+0x64bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25788ULL;
	}
x86_l_3bf2:
	/* 0x3bf2: mov    ecx,DWORD PTR [r13+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_3bf9:
	/* 0x3bf9: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3bfe:
	/* 0x3bfe: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c03:
	/* 0x3c03: cmp    WORD PTR [r13+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_3c0c:
	/* 0x3c0c: je     3c31 <generic_sleepable_preload+0x3c31> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c31;
	}
x86_l_3c0e:
	/* 0x3c0e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c13:
	/* 0x3c13: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3c18:
	/* 0x3c18: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3c1d:
	/* 0x3c1d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c22:
	/* 0x3c22: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c27:
	/* 0x3c27: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c29:
	/* 0x3c29: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3c2b:
	/* 0x3c2b: js     611b <generic_sleepable_preload+0x611b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24859ULL;
	}
x86_l_3c31:
	/* 0x3c31: cmp    WORD PTR [r13+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_3c3a:
	/* 0x3c3a: je     64bc <generic_sleepable_preload+0x64bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25788ULL;
	}
x86_l_3c40:
	/* 0x3c40: mov    ecx,DWORD PTR [r13+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_3c47:
	/* 0x3c47: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3c4c:
	/* 0x3c4c: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c51:
	/* 0x3c51: cmp    WORD PTR [r13+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_3c5a:
	/* 0x3c5a: je     3c7f <generic_sleepable_preload+0x3c7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c7f;
	}
x86_l_3c5c:
	/* 0x3c5c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c61:
	/* 0x3c61: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3c66:
	/* 0x3c66: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3c6b:
	/* 0x3c6b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c70:
	/* 0x3c70: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c75:
	/* 0x3c75: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c77:
	/* 0x3c77: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3c79:
	/* 0x3c79: js     617f <generic_sleepable_preload+0x617f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24959ULL;
	}
x86_l_3c7f:
	/* 0x3c7f: cmp    WORD PTR [r13+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_3c88:
	/* 0x3c88: je     64bc <generic_sleepable_preload+0x64bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25788ULL;
	}
x86_l_3c8e:
	/* 0x3c8e: mov    ecx,DWORD PTR [r13+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_3c95:
	/* 0x3c95: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3c9a:
	/* 0x3c9a: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c9f:
	/* 0x3c9f: cmp    WORD PTR [r13+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_3ca8:
	/* 0x3ca8: je     3ccd <generic_sleepable_preload+0x3ccd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ccd;
	}
x86_l_3caa:
	/* 0x3caa: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3caf:
	/* 0x3caf: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3cb4:
	/* 0x3cb4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3cb9:
	/* 0x3cb9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3cbe:
	/* 0x3cbe: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3cc3:
	/* 0x3cc3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3cc5:
	/* 0x3cc5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3cc7:
	/* 0x3cc7: js     61e3 <generic_sleepable_preload+0x61e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25059ULL;
	}
x86_l_3ccd:
	/* 0x3ccd: cmp    WORD PTR [r13+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_3cd6:
	/* 0x3cd6: je     64bc <generic_sleepable_preload+0x64bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25788ULL;
	}
x86_l_3cdc:
	/* 0x3cdc: mov    ecx,DWORD PTR [r13+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_3ce3:
	/* 0x3ce3: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3ce8:
	/* 0x3ce8: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3ced:
	/* 0x3ced: cmp    WORD PTR [r13+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_3cf6:
	/* 0x3cf6: je     3d1b <generic_sleepable_preload+0x3d1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3d1b;
	}
x86_l_3cf8:
	/* 0x3cf8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3cfd:
	/* 0x3cfd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3d02:
	/* 0x3d02: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3d07:
	/* 0x3d07: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d0c:
	/* 0x3d0c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d11:
	/* 0x3d11: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d13:
	/* 0x3d13: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3d15:
	/* 0x3d15: js     6244 <generic_sleepable_preload+0x6244> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25156ULL;
	}
x86_l_3d1b:
	/* 0x3d1b: cmp    WORD PTR [r13+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_3d24:
	/* 0x3d24: je     64bc <generic_sleepable_preload+0x64bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25788ULL;
	}
x86_l_3d2a:
	/* 0x3d2a: mov    ecx,DWORD PTR [r13+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_3d31:
	/* 0x3d31: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3d36:
	/* 0x3d36: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d3b:
	/* 0x3d3b: cmp    WORD PTR [r13+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_3d44:
	/* 0x3d44: je     3d69 <generic_sleepable_preload+0x3d69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3d69;
	}
x86_l_3d46:
	/* 0x3d46: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d4b:
	/* 0x3d4b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3d50:
	/* 0x3d50: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3d55:
	/* 0x3d55: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d5a:
	/* 0x3d5a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d5f:
	/* 0x3d5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d61:
	/* 0x3d61: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3d63:
	/* 0x3d63: js     64b4 <generic_sleepable_preload+0x64b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25780ULL;
	}
x86_l_3d69:
	/* 0x3d69: cmp    WORD PTR [r13+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_3d72:
	/* 0x3d72: je     64bc <generic_sleepable_preload+0x64bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25788ULL;
	}
x86_l_3d78:
	/* 0x3d78: mov    ecx,DWORD PTR [r13+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_3d7f:
	/* 0x3d7f: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3d84:
	/* 0x3d84: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d89:
	/* 0x3d89: cmp    WORD PTR [r13+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_3d92:
	/* 0x3d92: je     3db7 <generic_sleepable_preload+0x3db7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3db7;
	}
x86_l_3d94:
	/* 0x3d94: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d99:
	/* 0x3d99: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3d9e:
	/* 0x3d9e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3da3:
	/* 0x3da3: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3da8:
	/* 0x3da8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3dad:
	/* 0x3dad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3daf:
	/* 0x3daf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3db1:
	/* 0x3db1: js     6a1b <generic_sleepable_preload+0x6a1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27163ULL;
	}
x86_l_3db7:
	/* 0x3db7: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3dbc:
	/* 0x3dbc: cmp    WORD PTR [r13+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_3dc5:
	/* 0x3dc5: je     64bc <generic_sleepable_preload+0x64bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25788ULL;
	}
x86_l_3dcb:
	/* 0x3dcb: mov    ecx,DWORD PTR [r13+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_3dd2:
	/* 0x3dd2: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3dd7:
	/* 0x3dd7: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3ddc:
	/* 0x3ddc: cmp    WORD PTR [r13+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_3de5:
	/* 0x3de5: je     3e0a <generic_sleepable_preload+0x3e0a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e0a;
	}
x86_l_3de7:
	/* 0x3de7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3dec:
	/* 0x3dec: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3df1:
	/* 0x3df1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3df6:
	/* 0x3df6: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3dfb:
	/* 0x3dfb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3e00:
	/* 0x3e00: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e02:
	/* 0x3e02: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3e04:
	/* 0x3e04: js     6977 <generic_sleepable_preload+0x6977> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26999ULL;
	}
x86_l_3e0a:
	/* 0x3e0a: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3e0f:
	/* 0x3e0f: cmp    WORD PTR [r13+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_3e18:
	/* 0x3e18: je     64bc <generic_sleepable_preload+0x64bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25788ULL;
	}
x86_l_3e1e:
	/* 0x3e1e: mov    ecx,DWORD PTR [r13+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_3e25:
	/* 0x3e25: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3e2a:
	/* 0x3e2a: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e2f:
	/* 0x3e2f: cmp    WORD PTR [r13+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_3e38:
	/* 0x3e38: je     64bc <generic_sleepable_preload+0x64bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25788ULL;
	}
x86_l_3e3e:
	/* 0x3e3e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e43:
	/* 0x3e43: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3e48:
	/* 0x3e48: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3e4d:
	/* 0x3e4d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e52:
	/* 0x3e52: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3e57:
	/* 0x3e57: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e59:
	/* 0x3e59: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3e5b:
	/* 0x3e5b: jns    64bc <generic_sleepable_preload+0x64bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 25788ULL;
	}
x86_l_3e61:
	/* 0x3e61: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_3e66:
	/* 0x3e66: jmp    64b9 <generic_sleepable_preload+0x64b9> */
	return 25785ULL;
x86_l_3e6b:
	/* 0x3e6b: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_3e70:
	/* 0x3e70: jmp    6285 <generic_sleepable_preload+0x6285> */
	return 25221ULL;
x86_l_3e75:
	/* 0x3e75: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_3e7a:
	/* 0x3e7a: jmp    6312 <generic_sleepable_preload+0x6312> */
	return 25362ULL;
x86_l_3e7f:
	/* 0x3e7f: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_3e84:
	/* 0x3e84: jmp    639f <generic_sleepable_preload+0x639f> */
	return 25503ULL;
x86_l_3e89:
	/* 0x3e89: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_3e8e:
	/* 0x3e8e: jmp    642c <generic_sleepable_preload+0x642c> */
	return 25644ULL;
x86_l_3e93:
	/* 0x3e93: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_3e98:
	/* 0x3e98: jmp    64b9 <generic_sleepable_preload+0x64b9> */
	return 25785ULL;
x86_l_3e9d:
	/* 0x3e9d: mov    rsi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3ea5:
	/* 0x3ea5: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_3ea8:
	/* 0x3ea8: je     40d0 <generic_sleepable_preload+0x40d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40d0;
	}
x86_l_3eae:
	/* 0x3eae: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3eb3:
	/* 0x3eb3: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_3eb6:
	/* 0x3eb6: je     40d0 <generic_sleepable_preload+0x40d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40d0;
	}
x86_l_3ebc:
	/* 0x3ebc: jmp    40e3 <generic_sleepable_preload+0x40e3> */
	goto x86_l_40e3;
x86_l_3ec1:
	/* 0x3ec1: mov    rsi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3ec9:
	/* 0x3ec9: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_3ecc:
	/* 0x3ecc: je     545f <generic_sleepable_preload+0x545f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21599ULL;
	}
x86_l_3ed2:
	/* 0x3ed2: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3ed7:
	/* 0x3ed7: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_3eda:
	/* 0x3eda: je     545f <generic_sleepable_preload+0x545f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21599ULL;
	}
x86_l_3ee0:
	/* 0x3ee0: jmp    5472 <generic_sleepable_preload+0x5472> */
	return 21618ULL;
x86_l_3ee5:
	/* 0x3ee5: mov    rsi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3eed:
	/* 0x3eed: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_3ef0:
	/* 0x3ef0: je     4740 <generic_sleepable_preload+0x4740> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18240ULL;
	}
x86_l_3ef6:
	/* 0x3ef6: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3efb:
	/* 0x3efb: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_3efe:
	/* 0x3efe: je     4740 <generic_sleepable_preload+0x4740> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18240ULL;
	}
x86_l_3f04:
	/* 0x3f04: jmp    4753 <generic_sleepable_preload+0x4753> */
	return 18259ULL;
x86_l_3f09:
	/* 0x3f09: mov    rsi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3f11:
	/* 0x3f11: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_3f14:
	/* 0x3f14: je     4da7 <generic_sleepable_preload+0x4da7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19879ULL;
	}
x86_l_3f1a:
	/* 0x3f1a: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3f1f:
	/* 0x3f1f: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_3f22:
	/* 0x3f22: je     4da7 <generic_sleepable_preload+0x4da7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19879ULL;
	}
x86_l_3f28:
	/* 0x3f28: jmp    4dba <generic_sleepable_preload+0x4dba> */
	return 19898ULL;
x86_l_3f2d:
	/* 0x3f2d: mov    rsi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3f35:
	/* 0x3f35: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_3f38:
	/* 0x3f38: je     5aaf <generic_sleepable_preload+0x5aaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23215ULL;
	}
x86_l_3f3e:
	/* 0x3f3e: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3f43:
	/* 0x3f43: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_3f46:
	/* 0x3f46: je     5aaf <generic_sleepable_preload+0x5aaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23215ULL;
	}
x86_l_3f4c:
	/* 0x3f4c: jmp    5ac2 <generic_sleepable_preload+0x5ac2> */
	return 23234ULL;
x86_l_3f51:
	/* 0x3f51: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3f59:
	/* 0x3f59: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3f5c:
	/* 0x3f5c: je     40d0 <generic_sleepable_preload+0x40d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40d0;
	}
x86_l_3f62:
	/* 0x3f62: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3f67:
	/* 0x3f67: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_3f6a:
	/* 0x3f6a: je     40d0 <generic_sleepable_preload+0x40d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40d0;
	}
x86_l_3f70:
	/* 0x3f70: jmp    40e3 <generic_sleepable_preload+0x40e3> */
	goto x86_l_40e3;
x86_l_3f75:
	/* 0x3f75: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3f7d:
	/* 0x3f7d: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3f80:
	/* 0x3f80: je     545f <generic_sleepable_preload+0x545f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21599ULL;
	}
x86_l_3f86:
	/* 0x3f86: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3f8b:
	/* 0x3f8b: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_3f8e:
	/* 0x3f8e: je     545f <generic_sleepable_preload+0x545f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21599ULL;
	}
x86_l_3f94:
	/* 0x3f94: jmp    5472 <generic_sleepable_preload+0x5472> */
	return 21618ULL;
x86_l_3f99:
	/* 0x3f99: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3fa1:
	/* 0x3fa1: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3fa4:
	/* 0x3fa4: je     4740 <generic_sleepable_preload+0x4740> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18240ULL;
	}
x86_l_3faa:
	/* 0x3faa: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3faf:
	/* 0x3faf: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_3fb2:
	/* 0x3fb2: je     4740 <generic_sleepable_preload+0x4740> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18240ULL;
	}
x86_l_3fb8:
	/* 0x3fb8: jmp    4753 <generic_sleepable_preload+0x4753> */
	return 18259ULL;
x86_l_3fbd:
	/* 0x3fbd: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3fc5:
	/* 0x3fc5: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3fc8:
	/* 0x3fc8: je     4da7 <generic_sleepable_preload+0x4da7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19879ULL;
	}
x86_l_3fce:
	/* 0x3fce: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3fd3:
	/* 0x3fd3: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_3fd6:
	/* 0x3fd6: je     4da7 <generic_sleepable_preload+0x4da7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19879ULL;
	}
x86_l_3fdc:
	/* 0x3fdc: jmp    4dba <generic_sleepable_preload+0x4dba> */
	return 19898ULL;
x86_l_3fe1:
	/* 0x3fe1: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3fe9:
	/* 0x3fe9: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3fec:
	/* 0x3fec: je     5aaf <generic_sleepable_preload+0x5aaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23215ULL;
	}
x86_l_3ff2:
	/* 0x3ff2: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3ff7:
	/* 0x3ff7: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_3ffa:
	/* 0x3ffa: je     5aaf <generic_sleepable_preload+0x5aaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23215ULL;
	}
x86_l_4000:
	/* 0x4000: jmp    5ac2 <generic_sleepable_preload+0x5ac2> */
	return 23234ULL;
x86_l_4005:
	/* 0x4005: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_400d:
	/* 0x400d: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_4010:
	/* 0x4010: je     40d0 <generic_sleepable_preload+0x40d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40d0;
	}
x86_l_4016:
	/* 0x4016: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_401b:
	/* 0x401b: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_401e:
	/* 0x401e: je     40d0 <generic_sleepable_preload+0x40d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40d0;
	}
x86_l_4024:
	/* 0x4024: jmp    40e3 <generic_sleepable_preload+0x40e3> */
	goto x86_l_40e3;
x86_l_4029:
	/* 0x4029: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_4031:
	/* 0x4031: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_4034:
	/* 0x4034: je     545f <generic_sleepable_preload+0x545f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21599ULL;
	}
x86_l_403a:
	/* 0x403a: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_403f:
	/* 0x403f: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_4042:
	/* 0x4042: je     545f <generic_sleepable_preload+0x545f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21599ULL;
	}
x86_l_4048:
	/* 0x4048: jmp    5472 <generic_sleepable_preload+0x5472> */
	return 21618ULL;
x86_l_404d:
	/* 0x404d: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_4055:
	/* 0x4055: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_4058:
	/* 0x4058: je     4740 <generic_sleepable_preload+0x4740> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18240ULL;
	}
x86_l_405e:
	/* 0x405e: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_4063:
	/* 0x4063: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_4066:
	/* 0x4066: je     4740 <generic_sleepable_preload+0x4740> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18240ULL;
	}
x86_l_406c:
	/* 0x406c: jmp    4753 <generic_sleepable_preload+0x4753> */
	return 18259ULL;
x86_l_4071:
	/* 0x4071: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_4079:
	/* 0x4079: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_407c:
	/* 0x407c: je     4da7 <generic_sleepable_preload+0x4da7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19879ULL;
	}
x86_l_4082:
	/* 0x4082: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_4087:
	/* 0x4087: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_408a:
	/* 0x408a: je     4da7 <generic_sleepable_preload+0x4da7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19879ULL;
	}
x86_l_4090:
	/* 0x4090: jmp    4dba <generic_sleepable_preload+0x4dba> */
	return 19898ULL;
x86_l_4095:
	/* 0x4095: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_409d:
	/* 0x409d: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_40a0:
	/* 0x40a0: je     5aaf <generic_sleepable_preload+0x5aaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23215ULL;
	}
x86_l_40a6:
	/* 0x40a6: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_40ab:
	/* 0x40ab: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_40ae:
	/* 0x40ae: je     5aaf <generic_sleepable_preload+0x5aaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23215ULL;
	}
x86_l_40b4:
	/* 0x40b4: jmp    5ac2 <generic_sleepable_preload+0x5ac2> */
	return 23234ULL;
x86_l_40b9:
	/* 0x40b9: mov    rsi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_40c1:
	/* 0x40c1: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_40c4:
	/* 0x40c4: je     40d0 <generic_sleepable_preload+0x40d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40d0;
	}
x86_l_40c6:
	/* 0x40c6: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_40cb:
	/* 0x40cb: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_40ce:
	/* 0x40ce: jne    40e3 <generic_sleepable_preload+0x40e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_40e3;
	}
x86_l_40d0:
	/* 0x40d0: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_40d3:
	/* 0x40d3: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_40d5:
	/* 0x40d5: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_40d7:
	/* 0x40d7: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_40dc:
	/* 0x40dc: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_40de:
	/* 0x40de: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_40e3:
	/* 0x40e3: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_40e8:
	/* 0x40e8: mov    r14d,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_40ec:
	/* 0x40ec: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_40ee:
	/* 0x40ee: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_40f1:
	/* 0x40f1: cmp    WORD PTR [r13+0x76],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 506806140928ULL);
x86_l_40f7:
	/* 0x40f7: je     6548 <generic_sleepable_preload+0x6548> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25928ULL;
	}
x86_l_40fd:
	/* 0x40fd: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_4104:
	/* 0x4104: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_4107:
	/* 0x4107: mov    eax,DWORD PTR [r13+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_410b:
	/* 0x410b: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_410e:
	/* 0x410e: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4113:
	/* 0x4113: movzx  eax,WORD PTR [r13+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 116ULL);
x86_l_4118:
	/* 0x4118: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_411a:
	/* 0x411a: je     43fc <generic_sleepable_preload+0x43fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17404ULL;
	}
x86_l_4120:
	/* 0x4120: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_4123:
	/* 0x4123: je     4148 <generic_sleepable_preload+0x4148> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4148;
	}
x86_l_4125:
	/* 0x4125: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_412a:
	/* 0x412a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_412f:
	/* 0x412f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4134:
	/* 0x4134: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4139:
	/* 0x4139: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_413e:
	/* 0x413e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4140:
	/* 0x4140: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4142:
	/* 0x4142: js     46fb <generic_sleepable_preload+0x46fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 18171ULL;
	}
x86_l_4148:
	/* 0x4148: cmp    WORD PTR [r13+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_414e:
	/* 0x414e: je     6548 <generic_sleepable_preload+0x6548> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25928ULL;
	}
x86_l_4154:
	/* 0x4154: mov    ecx,DWORD PTR [r13+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4158:
	/* 0x4158: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_415d:
	/* 0x415d: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4162:
	/* 0x4162: cmp    WORD PTR [r13+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_4168:
	/* 0x4168: je     418d <generic_sleepable_preload+0x418d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_418d;
	}
x86_l_416a:
	/* 0x416a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_416f:
	/* 0x416f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4174:
	/* 0x4174: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4179:
	/* 0x4179: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_417e:
	/* 0x417e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4183:
	/* 0x4183: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4185:
	/* 0x4185: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4187:
	/* 0x4187: js     543e <generic_sleepable_preload+0x543e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21566ULL;
	}
x86_l_418d:
	/* 0x418d: cmp    WORD PTR [r13+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_4196:
	/* 0x4196: je     6548 <generic_sleepable_preload+0x6548> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25928ULL;
	}
x86_l_419c:
	/* 0x419c: mov    ecx,DWORD PTR [r13+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_41a3:
	/* 0x41a3: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_41a8:
	/* 0x41a8: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_41ad:
	/* 0x41ad: cmp    WORD PTR [r13+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_41b6:
	/* 0x41b6: je     41db <generic_sleepable_preload+0x41db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_41db;
	}
x86_l_41b8:
	/* 0x41b8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_41bd:
	/* 0x41bd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_41c2:
	/* 0x41c2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_41c7:
	/* 0x41c7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_41cc:
	/* 0x41cc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_41d1:
	/* 0x41d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41d3:
	/* 0x41d3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_41d5:
	/* 0x41d5: js     6125 <generic_sleepable_preload+0x6125> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24869ULL;
	}
x86_l_41db:
	/* 0x41db: cmp    WORD PTR [r13+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_41e4:
	/* 0x41e4: je     6548 <generic_sleepable_preload+0x6548> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25928ULL;
	}
x86_l_41ea:
	/* 0x41ea: mov    ecx,DWORD PTR [r13+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_41f1:
	/* 0x41f1: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_41f6:
	/* 0x41f6: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_41fb:
	/* 0x41fb: cmp    WORD PTR [r13+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_4204:
	/* 0x4204: je     4229 <generic_sleepable_preload+0x4229> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4229;
	}
x86_l_4206:
	/* 0x4206: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_420b:
	/* 0x420b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4210:
	/* 0x4210: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4215:
	/* 0x4215: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_421a:
	/* 0x421a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_421f:
	/* 0x421f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4221:
	/* 0x4221: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4223:
	/* 0x4223: js     6189 <generic_sleepable_preload+0x6189> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24969ULL;
	}
x86_l_4229:
	/* 0x4229: cmp    WORD PTR [r13+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_4232:
	/* 0x4232: je     6548 <generic_sleepable_preload+0x6548> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25928ULL;
	}
x86_l_4238:
	/* 0x4238: mov    ecx,DWORD PTR [r13+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_423f:
	/* 0x423f: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4244:
	/* 0x4244: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4249:
	/* 0x4249: cmp    WORD PTR [r13+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_4252:
	/* 0x4252: je     4277 <generic_sleepable_preload+0x4277> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17015ULL;
	}
	return 16980ULL;
}

static __noinline __u64 tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_9(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 16980ULL: goto x86_l_4254;
	case 16985ULL: goto x86_l_4259;
	case 16990ULL: goto x86_l_425e;
	case 16995ULL: goto x86_l_4263;
	case 17000ULL: goto x86_l_4268;
	case 17005ULL: goto x86_l_426d;
	case 17007ULL: goto x86_l_426f;
	case 17009ULL: goto x86_l_4271;
	case 17015ULL: goto x86_l_4277;
	case 17024ULL: goto x86_l_4280;
	case 17030ULL: goto x86_l_4286;
	case 17037ULL: goto x86_l_428d;
	case 17042ULL: goto x86_l_4292;
	case 17047ULL: goto x86_l_4297;
	case 17056ULL: goto x86_l_42a0;
	case 17058ULL: goto x86_l_42a2;
	case 17063ULL: goto x86_l_42a7;
	case 17068ULL: goto x86_l_42ac;
	case 17073ULL: goto x86_l_42b1;
	case 17078ULL: goto x86_l_42b6;
	case 17083ULL: goto x86_l_42bb;
	case 17085ULL: goto x86_l_42bd;
	case 17087ULL: goto x86_l_42bf;
	case 17093ULL: goto x86_l_42c5;
	case 17102ULL: goto x86_l_42ce;
	case 17108ULL: goto x86_l_42d4;
	case 17115ULL: goto x86_l_42db;
	case 17120ULL: goto x86_l_42e0;
	case 17125ULL: goto x86_l_42e5;
	case 17134ULL: goto x86_l_42ee;
	case 17136ULL: goto x86_l_42f0;
	case 17141ULL: goto x86_l_42f5;
	case 17146ULL: goto x86_l_42fa;
	case 17151ULL: goto x86_l_42ff;
	case 17156ULL: goto x86_l_4304;
	case 17161ULL: goto x86_l_4309;
	case 17163ULL: goto x86_l_430b;
	case 17165ULL: goto x86_l_430d;
	case 17171ULL: goto x86_l_4313;
	case 17180ULL: goto x86_l_431c;
	case 17186ULL: goto x86_l_4322;
	case 17193ULL: goto x86_l_4329;
	case 17198ULL: goto x86_l_432e;
	case 17203ULL: goto x86_l_4333;
	case 17212ULL: goto x86_l_433c;
	case 17214ULL: goto x86_l_433e;
	case 17219ULL: goto x86_l_4343;
	case 17224ULL: goto x86_l_4348;
	case 17229ULL: goto x86_l_434d;
	case 17234ULL: goto x86_l_4352;
	case 17239ULL: goto x86_l_4357;
	case 17241ULL: goto x86_l_4359;
	case 17243ULL: goto x86_l_435b;
	case 17249ULL: goto x86_l_4361;
	case 17258ULL: goto x86_l_436a;
	case 17264ULL: goto x86_l_4370;
	case 17271ULL: goto x86_l_4377;
	case 17276ULL: goto x86_l_437c;
	case 17281ULL: goto x86_l_4381;
	case 17290ULL: goto x86_l_438a;
	case 17292ULL: goto x86_l_438c;
	case 17297ULL: goto x86_l_4391;
	case 17302ULL: goto x86_l_4396;
	case 17307ULL: goto x86_l_439b;
	case 17312ULL: goto x86_l_43a0;
	case 17317ULL: goto x86_l_43a5;
	case 17319ULL: goto x86_l_43a7;
	case 17321ULL: goto x86_l_43a9;
	case 17327ULL: goto x86_l_43af;
	case 17332ULL: goto x86_l_43b4;
	case 17341ULL: goto x86_l_43bd;
	case 17346ULL: goto x86_l_43c2;
	case 17352ULL: goto x86_l_43c8;
	case 17359ULL: goto x86_l_43cf;
	case 17364ULL: goto x86_l_43d4;
	case 17369ULL: goto x86_l_43d9;
	case 17378ULL: goto x86_l_43e2;
	case 17384ULL: goto x86_l_43e8;
	case 17389ULL: goto x86_l_43ed;
	case 17394ULL: goto x86_l_43f2;
	case 17399ULL: goto x86_l_43f7;
	case 17404ULL: goto x86_l_43fc;
	case 17407ULL: goto x86_l_43ff;
	case 17409ULL: goto x86_l_4401;
	case 17414ULL: goto x86_l_4406;
	case 17419ULL: goto x86_l_440b;
	case 17424ULL: goto x86_l_4410;
	case 17429ULL: goto x86_l_4415;
	case 17434ULL: goto x86_l_441a;
	case 17436ULL: goto x86_l_441c;
	case 17438ULL: goto x86_l_441e;
	case 17444ULL: goto x86_l_4424;
	case 17450ULL: goto x86_l_442a;
	case 17456ULL: goto x86_l_4430;
	case 17460ULL: goto x86_l_4434;
	case 17465ULL: goto x86_l_4439;
	case 17470ULL: goto x86_l_443e;
	case 17476ULL: goto x86_l_4444;
	case 17478ULL: goto x86_l_4446;
	case 17483ULL: goto x86_l_444b;
	case 17488ULL: goto x86_l_4450;
	case 17493ULL: goto x86_l_4455;
	case 17498ULL: goto x86_l_445a;
	case 17503ULL: goto x86_l_445f;
	case 17505ULL: goto x86_l_4461;
	case 17507ULL: goto x86_l_4463;
	case 17513ULL: goto x86_l_4469;
	case 17522ULL: goto x86_l_4472;
	case 17528ULL: goto x86_l_4478;
	case 17535ULL: goto x86_l_447f;
	case 17540ULL: goto x86_l_4484;
	case 17545ULL: goto x86_l_4489;
	case 17554ULL: goto x86_l_4492;
	case 17556ULL: goto x86_l_4494;
	case 17561ULL: goto x86_l_4499;
	case 17566ULL: goto x86_l_449e;
	case 17571ULL: goto x86_l_44a3;
	case 17576ULL: goto x86_l_44a8;
	case 17581ULL: goto x86_l_44ad;
	case 17583ULL: goto x86_l_44af;
	case 17585ULL: goto x86_l_44b1;
	case 17591ULL: goto x86_l_44b7;
	case 17600ULL: goto x86_l_44c0;
	case 17606ULL: goto x86_l_44c6;
	case 17613ULL: goto x86_l_44cd;
	case 17618ULL: goto x86_l_44d2;
	case 17623ULL: goto x86_l_44d7;
	case 17632ULL: goto x86_l_44e0;
	case 17634ULL: goto x86_l_44e2;
	case 17639ULL: goto x86_l_44e7;
	case 17644ULL: goto x86_l_44ec;
	case 17649ULL: goto x86_l_44f1;
	case 17654ULL: goto x86_l_44f6;
	case 17659ULL: goto x86_l_44fb;
	case 17661ULL: goto x86_l_44fd;
	case 17663ULL: goto x86_l_44ff;
	case 17669ULL: goto x86_l_4505;
	case 17678ULL: goto x86_l_450e;
	case 17684ULL: goto x86_l_4514;
	case 17691ULL: goto x86_l_451b;
	case 17696ULL: goto x86_l_4520;
	case 17701ULL: goto x86_l_4525;
	case 17710ULL: goto x86_l_452e;
	case 17712ULL: goto x86_l_4530;
	case 17717ULL: goto x86_l_4535;
	case 17722ULL: goto x86_l_453a;
	case 17727ULL: goto x86_l_453f;
	case 17732ULL: goto x86_l_4544;
	case 17737ULL: goto x86_l_4549;
	case 17739ULL: goto x86_l_454b;
	case 17741ULL: goto x86_l_454d;
	case 17747ULL: goto x86_l_4553;
	case 17756ULL: goto x86_l_455c;
	case 17762ULL: goto x86_l_4562;
	case 17769ULL: goto x86_l_4569;
	case 17774ULL: goto x86_l_456e;
	case 17779ULL: goto x86_l_4573;
	case 17788ULL: goto x86_l_457c;
	case 17790ULL: goto x86_l_457e;
	case 17795ULL: goto x86_l_4583;
	case 17800ULL: goto x86_l_4588;
	case 17805ULL: goto x86_l_458d;
	case 17810ULL: goto x86_l_4592;
	case 17815ULL: goto x86_l_4597;
	case 17817ULL: goto x86_l_4599;
	case 17819ULL: goto x86_l_459b;
	case 17825ULL: goto x86_l_45a1;
	case 17834ULL: goto x86_l_45aa;
	case 17840ULL: goto x86_l_45b0;
	case 17847ULL: goto x86_l_45b7;
	case 17852ULL: goto x86_l_45bc;
	case 17857ULL: goto x86_l_45c1;
	case 17866ULL: goto x86_l_45ca;
	case 17868ULL: goto x86_l_45cc;
	case 17873ULL: goto x86_l_45d1;
	case 17878ULL: goto x86_l_45d6;
	case 17883ULL: goto x86_l_45db;
	case 17888ULL: goto x86_l_45e0;
	case 17893ULL: goto x86_l_45e5;
	case 17895ULL: goto x86_l_45e7;
	case 17897ULL: goto x86_l_45e9;
	case 17903ULL: goto x86_l_45ef;
	case 17912ULL: goto x86_l_45f8;
	case 17918ULL: goto x86_l_45fe;
	case 17925ULL: goto x86_l_4605;
	case 17930ULL: goto x86_l_460a;
	case 17935ULL: goto x86_l_460f;
	case 17944ULL: goto x86_l_4618;
	case 17946ULL: goto x86_l_461a;
	case 17951ULL: goto x86_l_461f;
	case 17956ULL: goto x86_l_4624;
	case 17961ULL: goto x86_l_4629;
	case 17966ULL: goto x86_l_462e;
	case 17971ULL: goto x86_l_4633;
	case 17973ULL: goto x86_l_4635;
	case 17975ULL: goto x86_l_4637;
	case 17981ULL: goto x86_l_463d;
	case 17986ULL: goto x86_l_4642;
	case 17995ULL: goto x86_l_464b;
	case 18000ULL: goto x86_l_4650;
	case 18006ULL: goto x86_l_4656;
	case 18013ULL: goto x86_l_465d;
	case 18018ULL: goto x86_l_4662;
	case 18023ULL: goto x86_l_4667;
	case 18032ULL: goto x86_l_4670;
	case 18034ULL: goto x86_l_4672;
	case 18039ULL: goto x86_l_4677;
	case 18044ULL: goto x86_l_467c;
	case 18049ULL: goto x86_l_4681;
	case 18054ULL: goto x86_l_4686;
	case 18059ULL: goto x86_l_468b;
	case 18061ULL: goto x86_l_468d;
	case 18063ULL: goto x86_l_468f;
	case 18069ULL: goto x86_l_4695;
	case 18074ULL: goto x86_l_469a;
	case 18083ULL: goto x86_l_46a3;
	case 18088ULL: goto x86_l_46a8;
	case 18094ULL: goto x86_l_46ae;
	case 18101ULL: goto x86_l_46b5;
	case 18106ULL: goto x86_l_46ba;
	case 18111ULL: goto x86_l_46bf;
	case 18120ULL: goto x86_l_46c8;
	case 18126ULL: goto x86_l_46ce;
	case 18131ULL: goto x86_l_46d3;
	case 18136ULL: goto x86_l_46d8;
	case 18141ULL: goto x86_l_46dd;
	case 18146ULL: goto x86_l_46e2;
	case 18151ULL: goto x86_l_46e7;
	case 18153ULL: goto x86_l_46e9;
	case 18155ULL: goto x86_l_46eb;
	case 18161ULL: goto x86_l_46f1;
	case 18166ULL: goto x86_l_46f6;
	case 18171ULL: goto x86_l_46fb;
	case 18176ULL: goto x86_l_4700;
	case 18181ULL: goto x86_l_4705;
	case 18189ULL: goto x86_l_470d;
	case 18192ULL: goto x86_l_4710;
	case 18198ULL: goto x86_l_4716;
	case 18203ULL: goto x86_l_471b;
	case 18206ULL: goto x86_l_471e;
	case 18212ULL: goto x86_l_4724;
	case 18217ULL: goto x86_l_4729;
	case 18225ULL: goto x86_l_4731;
	case 18228ULL: goto x86_l_4734;
	case 18230ULL: goto x86_l_4736;
	case 18235ULL: goto x86_l_473b;
	case 18238ULL: goto x86_l_473e;
	case 18240ULL: goto x86_l_4740;
	case 18243ULL: goto x86_l_4743;
	case 18245ULL: goto x86_l_4745;
	case 18247ULL: goto x86_l_4747;
	case 18252ULL: goto x86_l_474c;
	case 18254ULL: goto x86_l_474e;
	case 18259ULL: goto x86_l_4753;
	case 18264ULL: goto x86_l_4758;
	case 18268ULL: goto x86_l_475c;
	case 18270ULL: goto x86_l_475e;
	case 18273ULL: goto x86_l_4761;
	case 18282ULL: goto x86_l_476a;
	case 18288ULL: goto x86_l_4770;
	case 18295ULL: goto x86_l_4777;
	case 18298ULL: goto x86_l_477a;
	case 18305ULL: goto x86_l_4781;
	case 18308ULL: goto x86_l_4784;
	case 18313ULL: goto x86_l_4789;
	case 18321ULL: goto x86_l_4791;
	case 18323ULL: goto x86_l_4793;
	case 18329ULL: goto x86_l_4799;
	case 18332ULL: goto x86_l_479c;
	case 18334ULL: goto x86_l_479e;
	case 18339ULL: goto x86_l_47a3;
	case 18344ULL: goto x86_l_47a8;
	case 18349ULL: goto x86_l_47ad;
	case 18354ULL: goto x86_l_47b2;
	case 18359ULL: goto x86_l_47b7;
	case 18361ULL: goto x86_l_47b9;
	case 18363ULL: goto x86_l_47bb;
	case 18369ULL: goto x86_l_47c1;
	case 18378ULL: goto x86_l_47ca;
	case 18384ULL: goto x86_l_47d0;
	case 18391ULL: goto x86_l_47d7;
	case 18396ULL: goto x86_l_47dc;
	case 18401ULL: goto x86_l_47e1;
	case 18410ULL: goto x86_l_47ea;
	case 18412ULL: goto x86_l_47ec;
	case 18417ULL: goto x86_l_47f1;
	case 18422ULL: goto x86_l_47f6;
	case 18427ULL: goto x86_l_47fb;
	case 18432ULL: goto x86_l_4800;
	case 18437ULL: goto x86_l_4805;
	case 18439ULL: goto x86_l_4807;
	case 18441ULL: goto x86_l_4809;
	case 18447ULL: goto x86_l_480f;
	case 18456ULL: goto x86_l_4818;
	case 18462ULL: goto x86_l_481e;
	case 18469ULL: goto x86_l_4825;
	case 18474ULL: goto x86_l_482a;
	case 18479ULL: goto x86_l_482f;
	case 18488ULL: goto x86_l_4838;
	case 18490ULL: goto x86_l_483a;
	case 18495ULL: goto x86_l_483f;
	case 18500ULL: goto x86_l_4844;
	case 18505ULL: goto x86_l_4849;
	case 18510ULL: goto x86_l_484e;
	case 18515ULL: goto x86_l_4853;
	case 18517ULL: goto x86_l_4855;
	case 18519ULL: goto x86_l_4857;
	case 18525ULL: goto x86_l_485d;
	case 18534ULL: goto x86_l_4866;
	case 18540ULL: goto x86_l_486c;
	case 18547ULL: goto x86_l_4873;
	case 18552ULL: goto x86_l_4878;
	case 18557ULL: goto x86_l_487d;
	case 18566ULL: goto x86_l_4886;
	case 18568ULL: goto x86_l_4888;
	case 18573ULL: goto x86_l_488d;
	case 18578ULL: goto x86_l_4892;
	case 18583ULL: goto x86_l_4897;
	case 18588ULL: goto x86_l_489c;
	case 18593ULL: goto x86_l_48a1;
	case 18595ULL: goto x86_l_48a3;
	case 18597ULL: goto x86_l_48a5;
	case 18603ULL: goto x86_l_48ab;
	case 18612ULL: goto x86_l_48b4;
	case 18618ULL: goto x86_l_48ba;
	case 18625ULL: goto x86_l_48c1;
	case 18630ULL: goto x86_l_48c6;
	case 18635ULL: goto x86_l_48cb;
	case 18644ULL: goto x86_l_48d4;
	case 18646ULL: goto x86_l_48d6;
	case 18651ULL: goto x86_l_48db;
	case 18656ULL: goto x86_l_48e0;
	case 18661ULL: goto x86_l_48e5;
	case 18666ULL: goto x86_l_48ea;
	case 18671ULL: goto x86_l_48ef;
	case 18673ULL: goto x86_l_48f1;
	case 18675ULL: goto x86_l_48f3;
	case 18681ULL: goto x86_l_48f9;
	case 18690ULL: goto x86_l_4902;
	case 18696ULL: goto x86_l_4908;
	case 18703ULL: goto x86_l_490f;
	case 18708ULL: goto x86_l_4914;
	case 18713ULL: goto x86_l_4919;
	case 18722ULL: goto x86_l_4922;
	case 18724ULL: goto x86_l_4924;
	case 18729ULL: goto x86_l_4929;
	case 18734ULL: goto x86_l_492e;
	case 18739ULL: goto x86_l_4933;
	case 18744ULL: goto x86_l_4938;
	case 18749ULL: goto x86_l_493d;
	case 18751ULL: goto x86_l_493f;
	case 18753ULL: goto x86_l_4941;
	case 18759ULL: goto x86_l_4947;
	case 18768ULL: goto x86_l_4950;
	case 18774ULL: goto x86_l_4956;
	case 18781ULL: goto x86_l_495d;
	case 18786ULL: goto x86_l_4962;
	case 18791ULL: goto x86_l_4967;
	case 18800ULL: goto x86_l_4970;
	case 18802ULL: goto x86_l_4972;
	case 18807ULL: goto x86_l_4977;
	case 18812ULL: goto x86_l_497c;
	case 18817ULL: goto x86_l_4981;
	case 18822ULL: goto x86_l_4986;
	case 18827ULL: goto x86_l_498b;
	case 18829ULL: goto x86_l_498d;
	case 18831ULL: goto x86_l_498f;
	case 18837ULL: goto x86_l_4995;
	case 18846ULL: goto x86_l_499e;
	case 18852ULL: goto x86_l_49a4;
	case 18859ULL: goto x86_l_49ab;
	case 18864ULL: goto x86_l_49b0;
	case 18869ULL: goto x86_l_49b5;
	case 18878ULL: goto x86_l_49be;
	case 18880ULL: goto x86_l_49c0;
	case 18885ULL: goto x86_l_49c5;
	case 18890ULL: goto x86_l_49ca;
	case 18895ULL: goto x86_l_49cf;
	case 18900ULL: goto x86_l_49d4;
	case 18905ULL: goto x86_l_49d9;
	case 18907ULL: goto x86_l_49db;
	case 18909ULL: goto x86_l_49dd;
	case 18915ULL: goto x86_l_49e3;
	case 18924ULL: goto x86_l_49ec;
	default: return 0xffffffffffffffffULL;
	}
x86_l_4254:
	/* 0x4254: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4259:
	/* 0x4259: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_425e:
	/* 0x425e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4263:
	/* 0x4263: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4268:
	/* 0x4268: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_426d:
	/* 0x426d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_426f:
	/* 0x426f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4271:
	/* 0x4271: js     61ed <generic_sleepable_preload+0x61ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25069ULL;
	}
x86_l_4277:
	/* 0x4277: cmp    WORD PTR [r13+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_4280:
	/* 0x4280: je     6548 <generic_sleepable_preload+0x6548> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25928ULL;
	}
x86_l_4286:
	/* 0x4286: mov    ecx,DWORD PTR [r13+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_428d:
	/* 0x428d: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4292:
	/* 0x4292: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4297:
	/* 0x4297: cmp    WORD PTR [r13+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_42a0:
	/* 0x42a0: je     42c5 <generic_sleepable_preload+0x42c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_42c5;
	}
x86_l_42a2:
	/* 0x42a2: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_42a7:
	/* 0x42a7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_42ac:
	/* 0x42ac: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_42b1:
	/* 0x42b1: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_42b6:
	/* 0x42b6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_42bb:
	/* 0x42bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42bd:
	/* 0x42bd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_42bf:
	/* 0x42bf: js     624e <generic_sleepable_preload+0x624e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25166ULL;
	}
x86_l_42c5:
	/* 0x42c5: cmp    WORD PTR [r13+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_42ce:
	/* 0x42ce: je     6548 <generic_sleepable_preload+0x6548> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25928ULL;
	}
x86_l_42d4:
	/* 0x42d4: mov    ecx,DWORD PTR [r13+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_42db:
	/* 0x42db: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_42e0:
	/* 0x42e0: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_42e5:
	/* 0x42e5: cmp    WORD PTR [r13+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_42ee:
	/* 0x42ee: je     4313 <generic_sleepable_preload+0x4313> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4313;
	}
x86_l_42f0:
	/* 0x42f0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_42f5:
	/* 0x42f5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_42fa:
	/* 0x42fa: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_42ff:
	/* 0x42ff: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4304:
	/* 0x4304: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4309:
	/* 0x4309: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_430b:
	/* 0x430b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_430d:
	/* 0x430d: js     6541 <generic_sleepable_preload+0x6541> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25921ULL;
	}
x86_l_4313:
	/* 0x4313: cmp    WORD PTR [r13+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_431c:
	/* 0x431c: je     6548 <generic_sleepable_preload+0x6548> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25928ULL;
	}
x86_l_4322:
	/* 0x4322: mov    ecx,DWORD PTR [r13+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_4329:
	/* 0x4329: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_432e:
	/* 0x432e: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4333:
	/* 0x4333: cmp    WORD PTR [r13+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_433c:
	/* 0x433c: je     4361 <generic_sleepable_preload+0x4361> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4361;
	}
x86_l_433e:
	/* 0x433e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4343:
	/* 0x4343: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4348:
	/* 0x4348: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_434d:
	/* 0x434d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4352:
	/* 0x4352: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4357:
	/* 0x4357: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4359:
	/* 0x4359: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_435b:
	/* 0x435b: js     690d <generic_sleepable_preload+0x690d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26893ULL;
	}
x86_l_4361:
	/* 0x4361: cmp    WORD PTR [r13+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_436a:
	/* 0x436a: je     6548 <generic_sleepable_preload+0x6548> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25928ULL;
	}
x86_l_4370:
	/* 0x4370: mov    ecx,DWORD PTR [r13+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_4377:
	/* 0x4377: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_437c:
	/* 0x437c: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4381:
	/* 0x4381: cmp    WORD PTR [r13+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_438a:
	/* 0x438a: je     43af <generic_sleepable_preload+0x43af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_43af;
	}
x86_l_438c:
	/* 0x438c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4391:
	/* 0x4391: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4396:
	/* 0x4396: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_439b:
	/* 0x439b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_43a0:
	/* 0x43a0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_43a5:
	/* 0x43a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_43a7:
	/* 0x43a7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_43a9:
	/* 0x43a9: js     6989 <generic_sleepable_preload+0x6989> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27017ULL;
	}
x86_l_43af:
	/* 0x43af: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_43b4:
	/* 0x43b4: cmp    WORD PTR [r13+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_43bd:
	/* 0x43bd: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_43c2:
	/* 0x43c2: je     6548 <generic_sleepable_preload+0x6548> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25928ULL;
	}
x86_l_43c8:
	/* 0x43c8: mov    ecx,DWORD PTR [r13+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_43cf:
	/* 0x43cf: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_43d4:
	/* 0x43d4: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_43d9:
	/* 0x43d9: cmp    WORD PTR [r13+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_43e2:
	/* 0x43e2: je     6548 <generic_sleepable_preload+0x6548> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25928ULL;
	}
x86_l_43e8:
	/* 0x43e8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_43ed:
	/* 0x43ed: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_43f2:
	/* 0x43f2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_43f7:
	/* 0x43f7: jmp    46dd <generic_sleepable_preload+0x46dd> */
	goto x86_l_46dd;
x86_l_43fc:
	/* 0x43fc: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_43ff:
	/* 0x43ff: je     4424 <generic_sleepable_preload+0x4424> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4424;
	}
x86_l_4401:
	/* 0x4401: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4406:
	/* 0x4406: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_440b:
	/* 0x440b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4410:
	/* 0x4410: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4415:
	/* 0x4415: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_441a:
	/* 0x441a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_441c:
	/* 0x441c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_441e:
	/* 0x441e: js     46fb <generic_sleepable_preload+0x46fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_46fb;
	}
x86_l_4424:
	/* 0x4424: cmp    WORD PTR [r13+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_442a:
	/* 0x442a: je     6548 <generic_sleepable_preload+0x6548> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25928ULL;
	}
x86_l_4430:
	/* 0x4430: mov    ecx,DWORD PTR [r13+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4434:
	/* 0x4434: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4439:
	/* 0x4439: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_443e:
	/* 0x443e: cmp    WORD PTR [r13+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_4444:
	/* 0x4444: je     4469 <generic_sleepable_preload+0x4469> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4469;
	}
x86_l_4446:
	/* 0x4446: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_444b:
	/* 0x444b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4450:
	/* 0x4450: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4455:
	/* 0x4455: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_445a:
	/* 0x445a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_445f:
	/* 0x445f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4461:
	/* 0x4461: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4463:
	/* 0x4463: js     543e <generic_sleepable_preload+0x543e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21566ULL;
	}
x86_l_4469:
	/* 0x4469: cmp    WORD PTR [r13+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_4472:
	/* 0x4472: je     6548 <generic_sleepable_preload+0x6548> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25928ULL;
	}
x86_l_4478:
	/* 0x4478: mov    ecx,DWORD PTR [r13+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_447f:
	/* 0x447f: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4484:
	/* 0x4484: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4489:
	/* 0x4489: cmp    WORD PTR [r13+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_4492:
	/* 0x4492: je     44b7 <generic_sleepable_preload+0x44b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44b7;
	}
x86_l_4494:
	/* 0x4494: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4499:
	/* 0x4499: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_449e:
	/* 0x449e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_44a3:
	/* 0x44a3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_44a8:
	/* 0x44a8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_44ad:
	/* 0x44ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44af:
	/* 0x44af: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_44b1:
	/* 0x44b1: js     6125 <generic_sleepable_preload+0x6125> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24869ULL;
	}
x86_l_44b7:
	/* 0x44b7: cmp    WORD PTR [r13+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_44c0:
	/* 0x44c0: je     6548 <generic_sleepable_preload+0x6548> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25928ULL;
	}
x86_l_44c6:
	/* 0x44c6: mov    ecx,DWORD PTR [r13+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_44cd:
	/* 0x44cd: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_44d2:
	/* 0x44d2: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_44d7:
	/* 0x44d7: cmp    WORD PTR [r13+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_44e0:
	/* 0x44e0: je     4505 <generic_sleepable_preload+0x4505> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4505;
	}
x86_l_44e2:
	/* 0x44e2: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_44e7:
	/* 0x44e7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_44ec:
	/* 0x44ec: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_44f1:
	/* 0x44f1: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_44f6:
	/* 0x44f6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_44fb:
	/* 0x44fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44fd:
	/* 0x44fd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_44ff:
	/* 0x44ff: js     6189 <generic_sleepable_preload+0x6189> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24969ULL;
	}
x86_l_4505:
	/* 0x4505: cmp    WORD PTR [r13+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_450e:
	/* 0x450e: je     6548 <generic_sleepable_preload+0x6548> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25928ULL;
	}
x86_l_4514:
	/* 0x4514: mov    ecx,DWORD PTR [r13+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_451b:
	/* 0x451b: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4520:
	/* 0x4520: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4525:
	/* 0x4525: cmp    WORD PTR [r13+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_452e:
	/* 0x452e: je     4553 <generic_sleepable_preload+0x4553> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4553;
	}
x86_l_4530:
	/* 0x4530: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4535:
	/* 0x4535: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_453a:
	/* 0x453a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_453f:
	/* 0x453f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4544:
	/* 0x4544: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4549:
	/* 0x4549: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_454b:
	/* 0x454b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_454d:
	/* 0x454d: js     61ed <generic_sleepable_preload+0x61ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25069ULL;
	}
x86_l_4553:
	/* 0x4553: cmp    WORD PTR [r13+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_455c:
	/* 0x455c: je     6548 <generic_sleepable_preload+0x6548> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25928ULL;
	}
x86_l_4562:
	/* 0x4562: mov    ecx,DWORD PTR [r13+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_4569:
	/* 0x4569: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_456e:
	/* 0x456e: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4573:
	/* 0x4573: cmp    WORD PTR [r13+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_457c:
	/* 0x457c: je     45a1 <generic_sleepable_preload+0x45a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_45a1;
	}
x86_l_457e:
	/* 0x457e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4583:
	/* 0x4583: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4588:
	/* 0x4588: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_458d:
	/* 0x458d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4592:
	/* 0x4592: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4597:
	/* 0x4597: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4599:
	/* 0x4599: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_459b:
	/* 0x459b: js     624e <generic_sleepable_preload+0x624e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25166ULL;
	}
x86_l_45a1:
	/* 0x45a1: cmp    WORD PTR [r13+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_45aa:
	/* 0x45aa: je     6548 <generic_sleepable_preload+0x6548> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25928ULL;
	}
x86_l_45b0:
	/* 0x45b0: mov    ecx,DWORD PTR [r13+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_45b7:
	/* 0x45b7: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_45bc:
	/* 0x45bc: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_45c1:
	/* 0x45c1: cmp    WORD PTR [r13+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_45ca:
	/* 0x45ca: je     45ef <generic_sleepable_preload+0x45ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_45ef;
	}
x86_l_45cc:
	/* 0x45cc: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_45d1:
	/* 0x45d1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_45d6:
	/* 0x45d6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_45db:
	/* 0x45db: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_45e0:
	/* 0x45e0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_45e5:
	/* 0x45e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45e7:
	/* 0x45e7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_45e9:
	/* 0x45e9: js     6541 <generic_sleepable_preload+0x6541> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25921ULL;
	}
x86_l_45ef:
	/* 0x45ef: cmp    WORD PTR [r13+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_45f8:
	/* 0x45f8: je     6548 <generic_sleepable_preload+0x6548> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25928ULL;
	}
x86_l_45fe:
	/* 0x45fe: mov    ecx,DWORD PTR [r13+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_4605:
	/* 0x4605: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_460a:
	/* 0x460a: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_460f:
	/* 0x460f: cmp    WORD PTR [r13+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_4618:
	/* 0x4618: je     463d <generic_sleepable_preload+0x463d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_463d;
	}
x86_l_461a:
	/* 0x461a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_461f:
	/* 0x461f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4624:
	/* 0x4624: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4629:
	/* 0x4629: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_462e:
	/* 0x462e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4633:
	/* 0x4633: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4635:
	/* 0x4635: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4637:
	/* 0x4637: js     6a2d <generic_sleepable_preload+0x6a2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27181ULL;
	}
x86_l_463d:
	/* 0x463d: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4642:
	/* 0x4642: cmp    WORD PTR [r13+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_464b:
	/* 0x464b: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4650:
	/* 0x4650: je     6548 <generic_sleepable_preload+0x6548> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25928ULL;
	}
x86_l_4656:
	/* 0x4656: mov    ecx,DWORD PTR [r13+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_465d:
	/* 0x465d: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4662:
	/* 0x4662: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4667:
	/* 0x4667: cmp    WORD PTR [r13+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_4670:
	/* 0x4670: je     4695 <generic_sleepable_preload+0x4695> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4695;
	}
x86_l_4672:
	/* 0x4672: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4677:
	/* 0x4677: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_467c:
	/* 0x467c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4681:
	/* 0x4681: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4686:
	/* 0x4686: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_468b:
	/* 0x468b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_468d:
	/* 0x468d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_468f:
	/* 0x468f: js     6989 <generic_sleepable_preload+0x6989> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27017ULL;
	}
x86_l_4695:
	/* 0x4695: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_469a:
	/* 0x469a: cmp    WORD PTR [r13+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_46a3:
	/* 0x46a3: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_46a8:
	/* 0x46a8: je     6548 <generic_sleepable_preload+0x6548> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25928ULL;
	}
x86_l_46ae:
	/* 0x46ae: mov    ecx,DWORD PTR [r13+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_46b5:
	/* 0x46b5: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_46ba:
	/* 0x46ba: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_46bf:
	/* 0x46bf: cmp    WORD PTR [r13+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_46c8:
	/* 0x46c8: je     6548 <generic_sleepable_preload+0x6548> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25928ULL;
	}
x86_l_46ce:
	/* 0x46ce: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_46d3:
	/* 0x46d3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_46d8:
	/* 0x46d8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_46dd:
	/* 0x46dd: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_46e2:
	/* 0x46e2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_46e7:
	/* 0x46e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46e9:
	/* 0x46e9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_46eb:
	/* 0x46eb: jns    6548 <generic_sleepable_preload+0x6548> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 25928ULL;
	}
x86_l_46f1:
	/* 0x46f1: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_46f6:
	/* 0x46f6: jmp    6546 <generic_sleepable_preload+0x6546> */
	return 25926ULL;
x86_l_46fb:
	/* 0x46fb: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_4700:
	/* 0x4700: jmp    6546 <generic_sleepable_preload+0x6546> */
	return 25926ULL;
x86_l_4705:
	/* 0x4705: mov    rsi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_470d:
	/* 0x470d: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_4710:
	/* 0x4710: je     545f <generic_sleepable_preload+0x545f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21599ULL;
	}
x86_l_4716:
	/* 0x4716: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_471b:
	/* 0x471b: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_471e:
	/* 0x471e: je     545f <generic_sleepable_preload+0x545f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21599ULL;
	}
x86_l_4724:
	/* 0x4724: jmp    5472 <generic_sleepable_preload+0x5472> */
	return 21618ULL;
x86_l_4729:
	/* 0x4729: mov    rsi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_4731:
	/* 0x4731: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_4734:
	/* 0x4734: je     4740 <generic_sleepable_preload+0x4740> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4740;
	}
x86_l_4736:
	/* 0x4736: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_473b:
	/* 0x473b: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_473e:
	/* 0x473e: jne    4753 <generic_sleepable_preload+0x4753> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4753;
	}
x86_l_4740:
	/* 0x4740: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_4743:
	/* 0x4743: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_4745:
	/* 0x4745: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_4747:
	/* 0x4747: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_474c:
	/* 0x474c: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_474e:
	/* 0x474e: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_4753:
	/* 0x4753: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4758:
	/* 0x4758: mov    r14d,DWORD PTR [r13+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_475c:
	/* 0x475c: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_475e:
	/* 0x475e: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_4761:
	/* 0x4761: cmp    WORD PTR [r13+0x116],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1194000908288ULL);
x86_l_476a:
	/* 0x476a: je     65fc <generic_sleepable_preload+0x65fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26108ULL;
	}
x86_l_4770:
	/* 0x4770: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_4777:
	/* 0x4777: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_477a:
	/* 0x477a: mov    eax,DWORD PTR [r13+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_4781:
	/* 0x4781: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4784:
	/* 0x4784: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4789:
	/* 0x4789: movzx  eax,WORD PTR [r13+0x114] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 276ULL);
x86_l_4791:
	/* 0x4791: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_4793:
	/* 0x4793: je     4a7e <generic_sleepable_preload+0x4a7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19070ULL;
	}
x86_l_4799:
	/* 0x4799: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_479c:
	/* 0x479c: je     47c1 <generic_sleepable_preload+0x47c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_47c1;
	}
x86_l_479e:
	/* 0x479e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_47a3:
	/* 0x47a3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_47a8:
	/* 0x47a8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_47ad:
	/* 0x47ad: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_47b2:
	/* 0x47b2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_47b7:
	/* 0x47b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_47b9:
	/* 0x47b9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_47bb:
	/* 0x47bb: js     4d86 <generic_sleepable_preload+0x4d86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19846ULL;
	}
x86_l_47c1:
	/* 0x47c1: cmp    WORD PTR [r13+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_47ca:
	/* 0x47ca: je     65fc <generic_sleepable_preload+0x65fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26108ULL;
	}
x86_l_47d0:
	/* 0x47d0: mov    ecx,DWORD PTR [r13+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_47d7:
	/* 0x47d7: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_47dc:
	/* 0x47dc: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_47e1:
	/* 0x47e1: cmp    WORD PTR [r13+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_47ea:
	/* 0x47ea: je     480f <generic_sleepable_preload+0x480f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_480f;
	}
x86_l_47ec:
	/* 0x47ec: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_47f1:
	/* 0x47f1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_47f6:
	/* 0x47f6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_47fb:
	/* 0x47fb: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4800:
	/* 0x4800: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4805:
	/* 0x4805: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4807:
	/* 0x4807: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4809:
	/* 0x4809: js     5448 <generic_sleepable_preload+0x5448> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21576ULL;
	}
x86_l_480f:
	/* 0x480f: cmp    WORD PTR [r13+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_4818:
	/* 0x4818: je     65fc <generic_sleepable_preload+0x65fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26108ULL;
	}
x86_l_481e:
	/* 0x481e: mov    ecx,DWORD PTR [r13+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_4825:
	/* 0x4825: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_482a:
	/* 0x482a: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_482f:
	/* 0x482f: cmp    WORD PTR [r13+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_4838:
	/* 0x4838: je     485d <generic_sleepable_preload+0x485d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_485d;
	}
x86_l_483a:
	/* 0x483a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_483f:
	/* 0x483f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4844:
	/* 0x4844: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4849:
	/* 0x4849: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_484e:
	/* 0x484e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4853:
	/* 0x4853: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4855:
	/* 0x4855: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4857:
	/* 0x4857: js     612f <generic_sleepable_preload+0x612f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24879ULL;
	}
x86_l_485d:
	/* 0x485d: cmp    WORD PTR [r13+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_4866:
	/* 0x4866: je     65fc <generic_sleepable_preload+0x65fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26108ULL;
	}
x86_l_486c:
	/* 0x486c: mov    ecx,DWORD PTR [r13+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_4873:
	/* 0x4873: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4878:
	/* 0x4878: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_487d:
	/* 0x487d: cmp    WORD PTR [r13+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_4886:
	/* 0x4886: je     48ab <generic_sleepable_preload+0x48ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_48ab;
	}
x86_l_4888:
	/* 0x4888: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_488d:
	/* 0x488d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4892:
	/* 0x4892: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4897:
	/* 0x4897: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_489c:
	/* 0x489c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_48a1:
	/* 0x48a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48a3:
	/* 0x48a3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_48a5:
	/* 0x48a5: js     6193 <generic_sleepable_preload+0x6193> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24979ULL;
	}
x86_l_48ab:
	/* 0x48ab: cmp    WORD PTR [r13+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_48b4:
	/* 0x48b4: je     65fc <generic_sleepable_preload+0x65fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26108ULL;
	}
x86_l_48ba:
	/* 0x48ba: mov    ecx,DWORD PTR [r13+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_48c1:
	/* 0x48c1: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_48c6:
	/* 0x48c6: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_48cb:
	/* 0x48cb: cmp    WORD PTR [r13+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_48d4:
	/* 0x48d4: je     48f9 <generic_sleepable_preload+0x48f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_48f9;
	}
x86_l_48d6:
	/* 0x48d6: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_48db:
	/* 0x48db: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_48e0:
	/* 0x48e0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_48e5:
	/* 0x48e5: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
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
	/* 0x48f3: js     61f7 <generic_sleepable_preload+0x61f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25079ULL;
	}
x86_l_48f9:
	/* 0x48f9: cmp    WORD PTR [r13+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_4902:
	/* 0x4902: je     65fc <generic_sleepable_preload+0x65fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26108ULL;
	}
x86_l_4908:
	/* 0x4908: mov    ecx,DWORD PTR [r13+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_490f:
	/* 0x490f: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4914:
	/* 0x4914: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4919:
	/* 0x4919: cmp    WORD PTR [r13+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_4922:
	/* 0x4922: je     4947 <generic_sleepable_preload+0x4947> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4947;
	}
x86_l_4924:
	/* 0x4924: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4929:
	/* 0x4929: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_492e:
	/* 0x492e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4933:
	/* 0x4933: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4938:
	/* 0x4938: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_493d:
	/* 0x493d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_493f:
	/* 0x493f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4941:
	/* 0x4941: js     6258 <generic_sleepable_preload+0x6258> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25176ULL;
	}
x86_l_4947:
	/* 0x4947: cmp    WORD PTR [r13+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_4950:
	/* 0x4950: je     65fc <generic_sleepable_preload+0x65fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26108ULL;
	}
x86_l_4956:
	/* 0x4956: mov    ecx,DWORD PTR [r13+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_495d:
	/* 0x495d: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4962:
	/* 0x4962: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4967:
	/* 0x4967: cmp    WORD PTR [r13+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_4970:
	/* 0x4970: je     4995 <generic_sleepable_preload+0x4995> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4995;
	}
x86_l_4972:
	/* 0x4972: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4977:
	/* 0x4977: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_497c:
	/* 0x497c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4981:
	/* 0x4981: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4986:
	/* 0x4986: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_498b:
	/* 0x498b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_498d:
	/* 0x498d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_498f:
	/* 0x498f: js     65f5 <generic_sleepable_preload+0x65f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26101ULL;
	}
x86_l_4995:
	/* 0x4995: cmp    WORD PTR [r13+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_499e:
	/* 0x499e: je     65fc <generic_sleepable_preload+0x65fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26108ULL;
	}
x86_l_49a4:
	/* 0x49a4: mov    ecx,DWORD PTR [r13+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_49ab:
	/* 0x49ab: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_49b0:
	/* 0x49b0: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49b5:
	/* 0x49b5: cmp    WORD PTR [r13+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_49be:
	/* 0x49be: je     49e3 <generic_sleepable_preload+0x49e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_49e3;
	}
x86_l_49c0:
	/* 0x49c0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49c5:
	/* 0x49c5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_49ca:
	/* 0x49ca: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_49cf:
	/* 0x49cf: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49d4:
	/* 0x49d4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_49d9:
	/* 0x49d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49db:
	/* 0x49db: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_49dd:
	/* 0x49dd: js     6919 <generic_sleepable_preload+0x6919> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26905ULL;
	}
x86_l_49e3:
	/* 0x49e3: cmp    WORD PTR [r13+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_49ec:
	/* 0x49ec: je     65fc <generic_sleepable_preload+0x65fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26108ULL;
	}
	return 18930ULL;
}

static __noinline __u64 tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_10(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 18930ULL: goto x86_l_49f2;
	case 18937ULL: goto x86_l_49f9;
	case 18942ULL: goto x86_l_49fe;
	case 18947ULL: goto x86_l_4a03;
	case 18956ULL: goto x86_l_4a0c;
	case 18958ULL: goto x86_l_4a0e;
	case 18963ULL: goto x86_l_4a13;
	case 18968ULL: goto x86_l_4a18;
	case 18973ULL: goto x86_l_4a1d;
	case 18978ULL: goto x86_l_4a22;
	case 18983ULL: goto x86_l_4a27;
	case 18985ULL: goto x86_l_4a29;
	case 18987ULL: goto x86_l_4a2b;
	case 18993ULL: goto x86_l_4a31;
	case 18998ULL: goto x86_l_4a36;
	case 19007ULL: goto x86_l_4a3f;
	case 19012ULL: goto x86_l_4a44;
	case 19018ULL: goto x86_l_4a4a;
	case 19025ULL: goto x86_l_4a51;
	case 19030ULL: goto x86_l_4a56;
	case 19035ULL: goto x86_l_4a5b;
	case 19044ULL: goto x86_l_4a64;
	case 19050ULL: goto x86_l_4a6a;
	case 19055ULL: goto x86_l_4a6f;
	case 19060ULL: goto x86_l_4a74;
	case 19065ULL: goto x86_l_4a79;
	case 19070ULL: goto x86_l_4a7e;
	case 19073ULL: goto x86_l_4a81;
	case 19075ULL: goto x86_l_4a83;
	case 19080ULL: goto x86_l_4a88;
	case 19085ULL: goto x86_l_4a8d;
	case 19090ULL: goto x86_l_4a92;
	case 19095ULL: goto x86_l_4a97;
	case 19100ULL: goto x86_l_4a9c;
	case 19102ULL: goto x86_l_4a9e;
	case 19104ULL: goto x86_l_4aa0;
	case 19110ULL: goto x86_l_4aa6;
	case 19119ULL: goto x86_l_4aaf;
	case 19125ULL: goto x86_l_4ab5;
	case 19132ULL: goto x86_l_4abc;
	case 19137ULL: goto x86_l_4ac1;
	case 19142ULL: goto x86_l_4ac6;
	case 19151ULL: goto x86_l_4acf;
	case 19153ULL: goto x86_l_4ad1;
	case 19158ULL: goto x86_l_4ad6;
	case 19163ULL: goto x86_l_4adb;
	case 19168ULL: goto x86_l_4ae0;
	case 19173ULL: goto x86_l_4ae5;
	case 19178ULL: goto x86_l_4aea;
	case 19180ULL: goto x86_l_4aec;
	case 19182ULL: goto x86_l_4aee;
	case 19188ULL: goto x86_l_4af4;
	case 19197ULL: goto x86_l_4afd;
	case 19203ULL: goto x86_l_4b03;
	case 19210ULL: goto x86_l_4b0a;
	case 19215ULL: goto x86_l_4b0f;
	case 19220ULL: goto x86_l_4b14;
	case 19229ULL: goto x86_l_4b1d;
	case 19231ULL: goto x86_l_4b1f;
	case 19236ULL: goto x86_l_4b24;
	case 19241ULL: goto x86_l_4b29;
	case 19246ULL: goto x86_l_4b2e;
	case 19251ULL: goto x86_l_4b33;
	case 19256ULL: goto x86_l_4b38;
	case 19258ULL: goto x86_l_4b3a;
	case 19260ULL: goto x86_l_4b3c;
	case 19266ULL: goto x86_l_4b42;
	case 19275ULL: goto x86_l_4b4b;
	case 19281ULL: goto x86_l_4b51;
	case 19288ULL: goto x86_l_4b58;
	case 19293ULL: goto x86_l_4b5d;
	case 19298ULL: goto x86_l_4b62;
	case 19307ULL: goto x86_l_4b6b;
	case 19309ULL: goto x86_l_4b6d;
	case 19314ULL: goto x86_l_4b72;
	case 19319ULL: goto x86_l_4b77;
	case 19324ULL: goto x86_l_4b7c;
	case 19329ULL: goto x86_l_4b81;
	case 19334ULL: goto x86_l_4b86;
	case 19336ULL: goto x86_l_4b88;
	case 19338ULL: goto x86_l_4b8a;
	case 19344ULL: goto x86_l_4b90;
	case 19353ULL: goto x86_l_4b99;
	case 19359ULL: goto x86_l_4b9f;
	case 19366ULL: goto x86_l_4ba6;
	case 19371ULL: goto x86_l_4bab;
	case 19376ULL: goto x86_l_4bb0;
	case 19385ULL: goto x86_l_4bb9;
	case 19387ULL: goto x86_l_4bbb;
	case 19392ULL: goto x86_l_4bc0;
	case 19397ULL: goto x86_l_4bc5;
	case 19402ULL: goto x86_l_4bca;
	case 19407ULL: goto x86_l_4bcf;
	case 19412ULL: goto x86_l_4bd4;
	case 19414ULL: goto x86_l_4bd6;
	case 19416ULL: goto x86_l_4bd8;
	case 19422ULL: goto x86_l_4bde;
	case 19431ULL: goto x86_l_4be7;
	case 19437ULL: goto x86_l_4bed;
	case 19444ULL: goto x86_l_4bf4;
	case 19449ULL: goto x86_l_4bf9;
	case 19454ULL: goto x86_l_4bfe;
	case 19463ULL: goto x86_l_4c07;
	case 19465ULL: goto x86_l_4c09;
	case 19470ULL: goto x86_l_4c0e;
	case 19475ULL: goto x86_l_4c13;
	case 19480ULL: goto x86_l_4c18;
	case 19485ULL: goto x86_l_4c1d;
	case 19490ULL: goto x86_l_4c22;
	case 19492ULL: goto x86_l_4c24;
	case 19494ULL: goto x86_l_4c26;
	case 19500ULL: goto x86_l_4c2c;
	case 19509ULL: goto x86_l_4c35;
	case 19515ULL: goto x86_l_4c3b;
	case 19522ULL: goto x86_l_4c42;
	case 19527ULL: goto x86_l_4c47;
	case 19532ULL: goto x86_l_4c4c;
	case 19541ULL: goto x86_l_4c55;
	case 19543ULL: goto x86_l_4c57;
	case 19548ULL: goto x86_l_4c5c;
	case 19553ULL: goto x86_l_4c61;
	case 19558ULL: goto x86_l_4c66;
	case 19563ULL: goto x86_l_4c6b;
	case 19568ULL: goto x86_l_4c70;
	case 19570ULL: goto x86_l_4c72;
	case 19572ULL: goto x86_l_4c74;
	case 19578ULL: goto x86_l_4c7a;
	case 19587ULL: goto x86_l_4c83;
	case 19593ULL: goto x86_l_4c89;
	case 19600ULL: goto x86_l_4c90;
	case 19605ULL: goto x86_l_4c95;
	case 19610ULL: goto x86_l_4c9a;
	case 19619ULL: goto x86_l_4ca3;
	case 19621ULL: goto x86_l_4ca5;
	case 19626ULL: goto x86_l_4caa;
	case 19631ULL: goto x86_l_4caf;
	case 19636ULL: goto x86_l_4cb4;
	case 19641ULL: goto x86_l_4cb9;
	case 19646ULL: goto x86_l_4cbe;
	case 19648ULL: goto x86_l_4cc0;
	case 19650ULL: goto x86_l_4cc2;
	case 19656ULL: goto x86_l_4cc8;
	case 19661ULL: goto x86_l_4ccd;
	case 19670ULL: goto x86_l_4cd6;
	case 19675ULL: goto x86_l_4cdb;
	case 19681ULL: goto x86_l_4ce1;
	case 19688ULL: goto x86_l_4ce8;
	case 19693ULL: goto x86_l_4ced;
	case 19698ULL: goto x86_l_4cf2;
	case 19707ULL: goto x86_l_4cfb;
	case 19709ULL: goto x86_l_4cfd;
	case 19714ULL: goto x86_l_4d02;
	case 19719ULL: goto x86_l_4d07;
	case 19724ULL: goto x86_l_4d0c;
	case 19729ULL: goto x86_l_4d11;
	case 19734ULL: goto x86_l_4d16;
	case 19736ULL: goto x86_l_4d18;
	case 19738ULL: goto x86_l_4d1a;
	case 19744ULL: goto x86_l_4d20;
	case 19749ULL: goto x86_l_4d25;
	case 19758ULL: goto x86_l_4d2e;
	case 19763ULL: goto x86_l_4d33;
	case 19769ULL: goto x86_l_4d39;
	case 19776ULL: goto x86_l_4d40;
	case 19781ULL: goto x86_l_4d45;
	case 19786ULL: goto x86_l_4d4a;
	case 19795ULL: goto x86_l_4d53;
	case 19801ULL: goto x86_l_4d59;
	case 19806ULL: goto x86_l_4d5e;
	case 19811ULL: goto x86_l_4d63;
	case 19816ULL: goto x86_l_4d68;
	case 19821ULL: goto x86_l_4d6d;
	case 19826ULL: goto x86_l_4d72;
	case 19828ULL: goto x86_l_4d74;
	case 19830ULL: goto x86_l_4d76;
	case 19836ULL: goto x86_l_4d7c;
	case 19841ULL: goto x86_l_4d81;
	case 19846ULL: goto x86_l_4d86;
	case 19851ULL: goto x86_l_4d8b;
	case 19856ULL: goto x86_l_4d90;
	case 19864ULL: goto x86_l_4d98;
	case 19867ULL: goto x86_l_4d9b;
	case 19869ULL: goto x86_l_4d9d;
	case 19874ULL: goto x86_l_4da2;
	case 19877ULL: goto x86_l_4da5;
	case 19879ULL: goto x86_l_4da7;
	case 19882ULL: goto x86_l_4daa;
	case 19884ULL: goto x86_l_4dac;
	case 19886ULL: goto x86_l_4dae;
	case 19891ULL: goto x86_l_4db3;
	case 19893ULL: goto x86_l_4db5;
	case 19898ULL: goto x86_l_4dba;
	case 19903ULL: goto x86_l_4dbf;
	case 19907ULL: goto x86_l_4dc3;
	case 19909ULL: goto x86_l_4dc5;
	case 19912ULL: goto x86_l_4dc8;
	case 19921ULL: goto x86_l_4dd1;
	case 19927ULL: goto x86_l_4dd7;
	case 19934ULL: goto x86_l_4dde;
	case 19937ULL: goto x86_l_4de1;
	case 19944ULL: goto x86_l_4de8;
	case 19947ULL: goto x86_l_4deb;
	case 19952ULL: goto x86_l_4df0;
	case 19960ULL: goto x86_l_4df8;
	case 19962ULL: goto x86_l_4dfa;
	case 19968ULL: goto x86_l_4e00;
	case 19971ULL: goto x86_l_4e03;
	case 19973ULL: goto x86_l_4e05;
	case 19978ULL: goto x86_l_4e0a;
	case 19983ULL: goto x86_l_4e0f;
	case 19988ULL: goto x86_l_4e14;
	case 19993ULL: goto x86_l_4e19;
	case 19998ULL: goto x86_l_4e1e;
	case 20000ULL: goto x86_l_4e20;
	case 20002ULL: goto x86_l_4e22;
	case 20008ULL: goto x86_l_4e28;
	case 20017ULL: goto x86_l_4e31;
	case 20023ULL: goto x86_l_4e37;
	case 20030ULL: goto x86_l_4e3e;
	case 20035ULL: goto x86_l_4e43;
	case 20040ULL: goto x86_l_4e48;
	case 20049ULL: goto x86_l_4e51;
	case 20051ULL: goto x86_l_4e53;
	case 20056ULL: goto x86_l_4e58;
	case 20061ULL: goto x86_l_4e5d;
	case 20066ULL: goto x86_l_4e62;
	case 20071ULL: goto x86_l_4e67;
	case 20076ULL: goto x86_l_4e6c;
	case 20078ULL: goto x86_l_4e6e;
	case 20080ULL: goto x86_l_4e70;
	case 20086ULL: goto x86_l_4e76;
	case 20095ULL: goto x86_l_4e7f;
	case 20101ULL: goto x86_l_4e85;
	case 20108ULL: goto x86_l_4e8c;
	case 20113ULL: goto x86_l_4e91;
	case 20118ULL: goto x86_l_4e96;
	case 20127ULL: goto x86_l_4e9f;
	case 20129ULL: goto x86_l_4ea1;
	case 20134ULL: goto x86_l_4ea6;
	case 20139ULL: goto x86_l_4eab;
	case 20144ULL: goto x86_l_4eb0;
	case 20149ULL: goto x86_l_4eb5;
	case 20154ULL: goto x86_l_4eba;
	case 20156ULL: goto x86_l_4ebc;
	case 20158ULL: goto x86_l_4ebe;
	case 20164ULL: goto x86_l_4ec4;
	case 20173ULL: goto x86_l_4ecd;
	case 20179ULL: goto x86_l_4ed3;
	case 20186ULL: goto x86_l_4eda;
	case 20191ULL: goto x86_l_4edf;
	case 20196ULL: goto x86_l_4ee4;
	case 20205ULL: goto x86_l_4eed;
	case 20207ULL: goto x86_l_4eef;
	case 20212ULL: goto x86_l_4ef4;
	case 20217ULL: goto x86_l_4ef9;
	case 20222ULL: goto x86_l_4efe;
	case 20227ULL: goto x86_l_4f03;
	case 20232ULL: goto x86_l_4f08;
	case 20234ULL: goto x86_l_4f0a;
	case 20236ULL: goto x86_l_4f0c;
	case 20242ULL: goto x86_l_4f12;
	case 20251ULL: goto x86_l_4f1b;
	case 20257ULL: goto x86_l_4f21;
	case 20264ULL: goto x86_l_4f28;
	case 20269ULL: goto x86_l_4f2d;
	case 20274ULL: goto x86_l_4f32;
	case 20283ULL: goto x86_l_4f3b;
	case 20285ULL: goto x86_l_4f3d;
	case 20290ULL: goto x86_l_4f42;
	case 20295ULL: goto x86_l_4f47;
	case 20300ULL: goto x86_l_4f4c;
	case 20305ULL: goto x86_l_4f51;
	case 20310ULL: goto x86_l_4f56;
	case 20312ULL: goto x86_l_4f58;
	case 20314ULL: goto x86_l_4f5a;
	case 20320ULL: goto x86_l_4f60;
	case 20329ULL: goto x86_l_4f69;
	case 20335ULL: goto x86_l_4f6f;
	case 20342ULL: goto x86_l_4f76;
	case 20347ULL: goto x86_l_4f7b;
	case 20352ULL: goto x86_l_4f80;
	case 20361ULL: goto x86_l_4f89;
	case 20363ULL: goto x86_l_4f8b;
	case 20368ULL: goto x86_l_4f90;
	case 20373ULL: goto x86_l_4f95;
	case 20378ULL: goto x86_l_4f9a;
	case 20383ULL: goto x86_l_4f9f;
	case 20388ULL: goto x86_l_4fa4;
	case 20390ULL: goto x86_l_4fa6;
	case 20392ULL: goto x86_l_4fa8;
	case 20398ULL: goto x86_l_4fae;
	case 20407ULL: goto x86_l_4fb7;
	case 20413ULL: goto x86_l_4fbd;
	case 20420ULL: goto x86_l_4fc4;
	case 20425ULL: goto x86_l_4fc9;
	case 20430ULL: goto x86_l_4fce;
	case 20439ULL: goto x86_l_4fd7;
	case 20441ULL: goto x86_l_4fd9;
	case 20446ULL: goto x86_l_4fde;
	case 20451ULL: goto x86_l_4fe3;
	case 20456ULL: goto x86_l_4fe8;
	case 20461ULL: goto x86_l_4fed;
	case 20466ULL: goto x86_l_4ff2;
	case 20468ULL: goto x86_l_4ff4;
	case 20470ULL: goto x86_l_4ff6;
	case 20476ULL: goto x86_l_4ffc;
	case 20485ULL: goto x86_l_5005;
	case 20491ULL: goto x86_l_500b;
	case 20498ULL: goto x86_l_5012;
	case 20503ULL: goto x86_l_5017;
	case 20508ULL: goto x86_l_501c;
	case 20517ULL: goto x86_l_5025;
	case 20519ULL: goto x86_l_5027;
	case 20524ULL: goto x86_l_502c;
	case 20529ULL: goto x86_l_5031;
	case 20534ULL: goto x86_l_5036;
	case 20539ULL: goto x86_l_503b;
	case 20544ULL: goto x86_l_5040;
	case 20546ULL: goto x86_l_5042;
	case 20548ULL: goto x86_l_5044;
	case 20554ULL: goto x86_l_504a;
	case 20563ULL: goto x86_l_5053;
	case 20569ULL: goto x86_l_5059;
	case 20576ULL: goto x86_l_5060;
	case 20581ULL: goto x86_l_5065;
	case 20586ULL: goto x86_l_506a;
	case 20595ULL: goto x86_l_5073;
	case 20597ULL: goto x86_l_5075;
	case 20602ULL: goto x86_l_507a;
	case 20607ULL: goto x86_l_507f;
	case 20612ULL: goto x86_l_5084;
	case 20617ULL: goto x86_l_5089;
	case 20622ULL: goto x86_l_508e;
	case 20624ULL: goto x86_l_5090;
	case 20626ULL: goto x86_l_5092;
	case 20632ULL: goto x86_l_5098;
	case 20637ULL: goto x86_l_509d;
	case 20646ULL: goto x86_l_50a6;
	case 20652ULL: goto x86_l_50ac;
	case 20659ULL: goto x86_l_50b3;
	case 20664ULL: goto x86_l_50b8;
	case 20669ULL: goto x86_l_50bd;
	case 20678ULL: goto x86_l_50c6;
	case 20684ULL: goto x86_l_50cc;
	case 20689ULL: goto x86_l_50d1;
	case 20694ULL: goto x86_l_50d6;
	case 20699ULL: goto x86_l_50db;
	case 20704ULL: goto x86_l_50e0;
	case 20707ULL: goto x86_l_50e3;
	case 20709ULL: goto x86_l_50e5;
	case 20714ULL: goto x86_l_50ea;
	case 20719ULL: goto x86_l_50ef;
	case 20724ULL: goto x86_l_50f4;
	case 20729ULL: goto x86_l_50f9;
	case 20734ULL: goto x86_l_50fe;
	case 20736ULL: goto x86_l_5100;
	case 20738ULL: goto x86_l_5102;
	case 20744ULL: goto x86_l_5108;
	case 20753ULL: goto x86_l_5111;
	case 20759ULL: goto x86_l_5117;
	case 20766ULL: goto x86_l_511e;
	case 20771ULL: goto x86_l_5123;
	case 20776ULL: goto x86_l_5128;
	case 20785ULL: goto x86_l_5131;
	case 20787ULL: goto x86_l_5133;
	case 20792ULL: goto x86_l_5138;
	case 20797ULL: goto x86_l_513d;
	case 20802ULL: goto x86_l_5142;
	case 20807ULL: goto x86_l_5147;
	case 20812ULL: goto x86_l_514c;
	case 20814ULL: goto x86_l_514e;
	case 20816ULL: goto x86_l_5150;
	case 20822ULL: goto x86_l_5156;
	case 20831ULL: goto x86_l_515f;
	case 20837ULL: goto x86_l_5165;
	case 20844ULL: goto x86_l_516c;
	case 20849ULL: goto x86_l_5171;
	case 20854ULL: goto x86_l_5176;
	case 20863ULL: goto x86_l_517f;
	case 20865ULL: goto x86_l_5181;
	case 20870ULL: goto x86_l_5186;
	case 20875ULL: goto x86_l_518b;
	case 20880ULL: goto x86_l_5190;
	case 20885ULL: goto x86_l_5195;
	default: return 0xffffffffffffffffULL;
	}
x86_l_49f2:
	/* 0x49f2: mov    ecx,DWORD PTR [r13+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_49f9:
	/* 0x49f9: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_49fe:
	/* 0x49fe: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a03:
	/* 0x4a03: cmp    WORD PTR [r13+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_4a0c:
	/* 0x4a0c: je     4a31 <generic_sleepable_preload+0x4a31> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4a31;
	}
x86_l_4a0e:
	/* 0x4a0e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a13:
	/* 0x4a13: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4a18:
	/* 0x4a18: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4a1d:
	/* 0x4a1d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a22:
	/* 0x4a22: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a27:
	/* 0x4a27: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a29:
	/* 0x4a29: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4a2b:
	/* 0x4a2b: js     6995 <generic_sleepable_preload+0x6995> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27029ULL;
	}
x86_l_4a31:
	/* 0x4a31: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4a36:
	/* 0x4a36: cmp    WORD PTR [r13+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_4a3f:
	/* 0x4a3f: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4a44:
	/* 0x4a44: je     65fc <generic_sleepable_preload+0x65fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26108ULL;
	}
x86_l_4a4a:
	/* 0x4a4a: mov    ecx,DWORD PTR [r13+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_4a51:
	/* 0x4a51: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4a56:
	/* 0x4a56: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a5b:
	/* 0x4a5b: cmp    WORD PTR [r13+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_4a64:
	/* 0x4a64: je     65fc <generic_sleepable_preload+0x65fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26108ULL;
	}
x86_l_4a6a:
	/* 0x4a6a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a6f:
	/* 0x4a6f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4a74:
	/* 0x4a74: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4a79:
	/* 0x4a79: jmp    4d68 <generic_sleepable_preload+0x4d68> */
	goto x86_l_4d68;
x86_l_4a7e:
	/* 0x4a7e: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_4a81:
	/* 0x4a81: je     4aa6 <generic_sleepable_preload+0x4aa6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4aa6;
	}
x86_l_4a83:
	/* 0x4a83: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a88:
	/* 0x4a88: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4a8d:
	/* 0x4a8d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4a92:
	/* 0x4a92: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a97:
	/* 0x4a97: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a9c:
	/* 0x4a9c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a9e:
	/* 0x4a9e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4aa0:
	/* 0x4aa0: js     4d86 <generic_sleepable_preload+0x4d86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4d86;
	}
x86_l_4aa6:
	/* 0x4aa6: cmp    WORD PTR [r13+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_4aaf:
	/* 0x4aaf: je     65fc <generic_sleepable_preload+0x65fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26108ULL;
	}
x86_l_4ab5:
	/* 0x4ab5: mov    ecx,DWORD PTR [r13+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_4abc:
	/* 0x4abc: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4ac1:
	/* 0x4ac1: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ac6:
	/* 0x4ac6: cmp    WORD PTR [r13+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_4acf:
	/* 0x4acf: je     4af4 <generic_sleepable_preload+0x4af4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4af4;
	}
x86_l_4ad1:
	/* 0x4ad1: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ad6:
	/* 0x4ad6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4adb:
	/* 0x4adb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4ae0:
	/* 0x4ae0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ae5:
	/* 0x4ae5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4aea:
	/* 0x4aea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4aec:
	/* 0x4aec: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4aee:
	/* 0x4aee: js     5448 <generic_sleepable_preload+0x5448> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21576ULL;
	}
x86_l_4af4:
	/* 0x4af4: cmp    WORD PTR [r13+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_4afd:
	/* 0x4afd: je     65fc <generic_sleepable_preload+0x65fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26108ULL;
	}
x86_l_4b03:
	/* 0x4b03: mov    ecx,DWORD PTR [r13+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_4b0a:
	/* 0x4b0a: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4b0f:
	/* 0x4b0f: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b14:
	/* 0x4b14: cmp    WORD PTR [r13+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_4b1d:
	/* 0x4b1d: je     4b42 <generic_sleepable_preload+0x4b42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4b42;
	}
x86_l_4b1f:
	/* 0x4b1f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b24:
	/* 0x4b24: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4b29:
	/* 0x4b29: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4b2e:
	/* 0x4b2e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b33:
	/* 0x4b33: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b38:
	/* 0x4b38: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b3a:
	/* 0x4b3a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4b3c:
	/* 0x4b3c: js     612f <generic_sleepable_preload+0x612f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24879ULL;
	}
x86_l_4b42:
	/* 0x4b42: cmp    WORD PTR [r13+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_4b4b:
	/* 0x4b4b: je     65fc <generic_sleepable_preload+0x65fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26108ULL;
	}
x86_l_4b51:
	/* 0x4b51: mov    ecx,DWORD PTR [r13+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_4b58:
	/* 0x4b58: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4b5d:
	/* 0x4b5d: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b62:
	/* 0x4b62: cmp    WORD PTR [r13+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_4b6b:
	/* 0x4b6b: je     4b90 <generic_sleepable_preload+0x4b90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4b90;
	}
x86_l_4b6d:
	/* 0x4b6d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b72:
	/* 0x4b72: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4b77:
	/* 0x4b77: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4b7c:
	/* 0x4b7c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b81:
	/* 0x4b81: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b86:
	/* 0x4b86: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b88:
	/* 0x4b88: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4b8a:
	/* 0x4b8a: js     6193 <generic_sleepable_preload+0x6193> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24979ULL;
	}
x86_l_4b90:
	/* 0x4b90: cmp    WORD PTR [r13+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_4b99:
	/* 0x4b99: je     65fc <generic_sleepable_preload+0x65fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26108ULL;
	}
x86_l_4b9f:
	/* 0x4b9f: mov    ecx,DWORD PTR [r13+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_4ba6:
	/* 0x4ba6: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4bab:
	/* 0x4bab: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4bb0:
	/* 0x4bb0: cmp    WORD PTR [r13+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_4bb9:
	/* 0x4bb9: je     4bde <generic_sleepable_preload+0x4bde> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bde;
	}
x86_l_4bbb:
	/* 0x4bbb: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4bc0:
	/* 0x4bc0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4bc5:
	/* 0x4bc5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4bca:
	/* 0x4bca: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4bcf:
	/* 0x4bcf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4bd4:
	/* 0x4bd4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4bd6:
	/* 0x4bd6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4bd8:
	/* 0x4bd8: js     61f7 <generic_sleepable_preload+0x61f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25079ULL;
	}
x86_l_4bde:
	/* 0x4bde: cmp    WORD PTR [r13+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_4be7:
	/* 0x4be7: je     65fc <generic_sleepable_preload+0x65fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26108ULL;
	}
x86_l_4bed:
	/* 0x4bed: mov    ecx,DWORD PTR [r13+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_4bf4:
	/* 0x4bf4: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4bf9:
	/* 0x4bf9: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4bfe:
	/* 0x4bfe: cmp    WORD PTR [r13+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_4c07:
	/* 0x4c07: je     4c2c <generic_sleepable_preload+0x4c2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4c2c;
	}
x86_l_4c09:
	/* 0x4c09: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c0e:
	/* 0x4c0e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4c13:
	/* 0x4c13: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4c18:
	/* 0x4c18: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c1d:
	/* 0x4c1d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4c22:
	/* 0x4c22: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c24:
	/* 0x4c24: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4c26:
	/* 0x4c26: js     6258 <generic_sleepable_preload+0x6258> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25176ULL;
	}
x86_l_4c2c:
	/* 0x4c2c: cmp    WORD PTR [r13+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_4c35:
	/* 0x4c35: je     65fc <generic_sleepable_preload+0x65fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26108ULL;
	}
x86_l_4c3b:
	/* 0x4c3b: mov    ecx,DWORD PTR [r13+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_4c42:
	/* 0x4c42: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4c47:
	/* 0x4c47: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c4c:
	/* 0x4c4c: cmp    WORD PTR [r13+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_4c55:
	/* 0x4c55: je     4c7a <generic_sleepable_preload+0x4c7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4c7a;
	}
x86_l_4c57:
	/* 0x4c57: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c5c:
	/* 0x4c5c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4c61:
	/* 0x4c61: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4c66:
	/* 0x4c66: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c6b:
	/* 0x4c6b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4c70:
	/* 0x4c70: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c72:
	/* 0x4c72: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4c74:
	/* 0x4c74: js     65f5 <generic_sleepable_preload+0x65f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26101ULL;
	}
x86_l_4c7a:
	/* 0x4c7a: cmp    WORD PTR [r13+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_4c83:
	/* 0x4c83: je     65fc <generic_sleepable_preload+0x65fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26108ULL;
	}
x86_l_4c89:
	/* 0x4c89: mov    ecx,DWORD PTR [r13+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_4c90:
	/* 0x4c90: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4c95:
	/* 0x4c95: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c9a:
	/* 0x4c9a: cmp    WORD PTR [r13+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_4ca3:
	/* 0x4ca3: je     4cc8 <generic_sleepable_preload+0x4cc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4cc8;
	}
x86_l_4ca5:
	/* 0x4ca5: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4caa:
	/* 0x4caa: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4caf:
	/* 0x4caf: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4cb4:
	/* 0x4cb4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4cb9:
	/* 0x4cb9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4cbe:
	/* 0x4cbe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4cc0:
	/* 0x4cc0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4cc2:
	/* 0x4cc2: js     6a43 <generic_sleepable_preload+0x6a43> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27203ULL;
	}
x86_l_4cc8:
	/* 0x4cc8: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4ccd:
	/* 0x4ccd: cmp    WORD PTR [r13+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_4cd6:
	/* 0x4cd6: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4cdb:
	/* 0x4cdb: je     65fc <generic_sleepable_preload+0x65fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26108ULL;
	}
x86_l_4ce1:
	/* 0x4ce1: mov    ecx,DWORD PTR [r13+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_4ce8:
	/* 0x4ce8: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4ced:
	/* 0x4ced: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4cf2:
	/* 0x4cf2: cmp    WORD PTR [r13+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_4cfb:
	/* 0x4cfb: je     4d20 <generic_sleepable_preload+0x4d20> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4d20;
	}
x86_l_4cfd:
	/* 0x4cfd: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4d02:
	/* 0x4d02: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4d07:
	/* 0x4d07: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4d0c:
	/* 0x4d0c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4d11:
	/* 0x4d11: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4d16:
	/* 0x4d16: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d18:
	/* 0x4d18: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4d1a:
	/* 0x4d1a: js     6995 <generic_sleepable_preload+0x6995> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27029ULL;
	}
x86_l_4d20:
	/* 0x4d20: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4d25:
	/* 0x4d25: cmp    WORD PTR [r13+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_4d2e:
	/* 0x4d2e: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4d33:
	/* 0x4d33: je     65fc <generic_sleepable_preload+0x65fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26108ULL;
	}
x86_l_4d39:
	/* 0x4d39: mov    ecx,DWORD PTR [r13+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_4d40:
	/* 0x4d40: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4d45:
	/* 0x4d45: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4d4a:
	/* 0x4d4a: cmp    WORD PTR [r13+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_4d53:
	/* 0x4d53: je     65fc <generic_sleepable_preload+0x65fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26108ULL;
	}
x86_l_4d59:
	/* 0x4d59: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4d5e:
	/* 0x4d5e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4d63:
	/* 0x4d63: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4d68:
	/* 0x4d68: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4d6d:
	/* 0x4d6d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4d72:
	/* 0x4d72: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d74:
	/* 0x4d74: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4d76:
	/* 0x4d76: jns    65fc <generic_sleepable_preload+0x65fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 26108ULL;
	}
x86_l_4d7c:
	/* 0x4d7c: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_4d81:
	/* 0x4d81: jmp    65fa <generic_sleepable_preload+0x65fa> */
	return 26106ULL;
x86_l_4d86:
	/* 0x4d86: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_4d8b:
	/* 0x4d8b: jmp    65fa <generic_sleepable_preload+0x65fa> */
	return 26106ULL;
x86_l_4d90:
	/* 0x4d90: mov    rsi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_4d98:
	/* 0x4d98: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_4d9b:
	/* 0x4d9b: je     4da7 <generic_sleepable_preload+0x4da7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4da7;
	}
x86_l_4d9d:
	/* 0x4d9d: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4da2:
	/* 0x4da2: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_4da5:
	/* 0x4da5: jne    4dba <generic_sleepable_preload+0x4dba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4dba;
	}
x86_l_4da7:
	/* 0x4da7: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_4daa:
	/* 0x4daa: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_4dac:
	/* 0x4dac: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_4dae:
	/* 0x4dae: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_4db3:
	/* 0x4db3: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4db5:
	/* 0x4db5: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_4dba:
	/* 0x4dba: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4dbf:
	/* 0x4dbf: mov    r14d,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4dc3:
	/* 0x4dc3: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4dc5:
	/* 0x4dc5: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_4dc8:
	/* 0x4dc8: cmp    WORD PTR [r13+0x166],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1537598291968ULL);
x86_l_4dd1:
	/* 0x4dd1: je     66b1 <generic_sleepable_preload+0x66b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26289ULL;
	}
x86_l_4dd7:
	/* 0x4dd7: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_4dde:
	/* 0x4dde: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_4de1:
	/* 0x4de1: mov    eax,DWORD PTR [r13+0x160] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_4de8:
	/* 0x4de8: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4deb:
	/* 0x4deb: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4df0:
	/* 0x4df0: movzx  eax,WORD PTR [r13+0x164] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 356ULL);
x86_l_4df8:
	/* 0x4df8: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_4dfa:
	/* 0x4dfa: je     50e0 <generic_sleepable_preload+0x50e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_50e0;
	}
x86_l_4e00:
	/* 0x4e00: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_4e03:
	/* 0x4e03: je     4e28 <generic_sleepable_preload+0x4e28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4e28;
	}
x86_l_4e05:
	/* 0x4e05: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e0a:
	/* 0x4e0a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4e0f:
	/* 0x4e0f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4e14:
	/* 0x4e14: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e19:
	/* 0x4e19: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e1e:
	/* 0x4e1e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e20:
	/* 0x4e20: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4e22:
	/* 0x4e22: js     53de <generic_sleepable_preload+0x53de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21470ULL;
	}
x86_l_4e28:
	/* 0x4e28: cmp    WORD PTR [r13+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_4e31:
	/* 0x4e31: je     66b1 <generic_sleepable_preload+0x66b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26289ULL;
	}
x86_l_4e37:
	/* 0x4e37: mov    ecx,DWORD PTR [r13+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_4e3e:
	/* 0x4e3e: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4e43:
	/* 0x4e43: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e48:
	/* 0x4e48: cmp    WORD PTR [r13+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_4e51:
	/* 0x4e51: je     4e76 <generic_sleepable_preload+0x4e76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4e76;
	}
x86_l_4e53:
	/* 0x4e53: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e58:
	/* 0x4e58: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4e5d:
	/* 0x4e5d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4e62:
	/* 0x4e62: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e67:
	/* 0x4e67: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e6c:
	/* 0x4e6c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e6e:
	/* 0x4e6e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4e70:
	/* 0x4e70: js     5452 <generic_sleepable_preload+0x5452> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21586ULL;
	}
x86_l_4e76:
	/* 0x4e76: cmp    WORD PTR [r13+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_4e7f:
	/* 0x4e7f: je     66b1 <generic_sleepable_preload+0x66b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26289ULL;
	}
x86_l_4e85:
	/* 0x4e85: mov    ecx,DWORD PTR [r13+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_4e8c:
	/* 0x4e8c: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4e91:
	/* 0x4e91: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e96:
	/* 0x4e96: cmp    WORD PTR [r13+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_4e9f:
	/* 0x4e9f: je     4ec4 <generic_sleepable_preload+0x4ec4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4ec4;
	}
x86_l_4ea1:
	/* 0x4ea1: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ea6:
	/* 0x4ea6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4eab:
	/* 0x4eab: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4eb0:
	/* 0x4eb0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4eb5:
	/* 0x4eb5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4eba:
	/* 0x4eba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ebc:
	/* 0x4ebc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4ebe:
	/* 0x4ebe: js     6139 <generic_sleepable_preload+0x6139> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24889ULL;
	}
x86_l_4ec4:
	/* 0x4ec4: cmp    WORD PTR [r13+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_4ecd:
	/* 0x4ecd: je     66b1 <generic_sleepable_preload+0x66b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26289ULL;
	}
x86_l_4ed3:
	/* 0x4ed3: mov    ecx,DWORD PTR [r13+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_4eda:
	/* 0x4eda: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4edf:
	/* 0x4edf: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ee4:
	/* 0x4ee4: cmp    WORD PTR [r13+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_4eed:
	/* 0x4eed: je     4f12 <generic_sleepable_preload+0x4f12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4f12;
	}
x86_l_4eef:
	/* 0x4eef: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ef4:
	/* 0x4ef4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4ef9:
	/* 0x4ef9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4efe:
	/* 0x4efe: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f03:
	/* 0x4f03: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f08:
	/* 0x4f08: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f0a:
	/* 0x4f0a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4f0c:
	/* 0x4f0c: js     619d <generic_sleepable_preload+0x619d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24989ULL;
	}
x86_l_4f12:
	/* 0x4f12: cmp    WORD PTR [r13+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_4f1b:
	/* 0x4f1b: je     66b1 <generic_sleepable_preload+0x66b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26289ULL;
	}
x86_l_4f21:
	/* 0x4f21: mov    ecx,DWORD PTR [r13+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_4f28:
	/* 0x4f28: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4f2d:
	/* 0x4f2d: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f32:
	/* 0x4f32: cmp    WORD PTR [r13+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_4f3b:
	/* 0x4f3b: je     4f60 <generic_sleepable_preload+0x4f60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4f60;
	}
x86_l_4f3d:
	/* 0x4f3d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f42:
	/* 0x4f42: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4f47:
	/* 0x4f47: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4f4c:
	/* 0x4f4c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f51:
	/* 0x4f51: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f56:
	/* 0x4f56: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f58:
	/* 0x4f58: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4f5a:
	/* 0x4f5a: js     6201 <generic_sleepable_preload+0x6201> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25089ULL;
	}
x86_l_4f60:
	/* 0x4f60: cmp    WORD PTR [r13+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_4f69:
	/* 0x4f69: je     66b1 <generic_sleepable_preload+0x66b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26289ULL;
	}
x86_l_4f6f:
	/* 0x4f6f: mov    ecx,DWORD PTR [r13+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_4f76:
	/* 0x4f76: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4f7b:
	/* 0x4f7b: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f80:
	/* 0x4f80: cmp    WORD PTR [r13+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_4f89:
	/* 0x4f89: je     4fae <generic_sleepable_preload+0x4fae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4fae;
	}
x86_l_4f8b:
	/* 0x4f8b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f90:
	/* 0x4f90: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4f95:
	/* 0x4f95: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4f9a:
	/* 0x4f9a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f9f:
	/* 0x4f9f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4fa4:
	/* 0x4fa4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4fa6:
	/* 0x4fa6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4fa8:
	/* 0x4fa8: js     6262 <generic_sleepable_preload+0x6262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25186ULL;
	}
x86_l_4fae:
	/* 0x4fae: cmp    WORD PTR [r13+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_4fb7:
	/* 0x4fb7: je     66b1 <generic_sleepable_preload+0x66b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26289ULL;
	}
x86_l_4fbd:
	/* 0x4fbd: mov    ecx,DWORD PTR [r13+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_4fc4:
	/* 0x4fc4: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4fc9:
	/* 0x4fc9: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4fce:
	/* 0x4fce: cmp    WORD PTR [r13+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_4fd7:
	/* 0x4fd7: je     4ffc <generic_sleepable_preload+0x4ffc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4ffc;
	}
x86_l_4fd9:
	/* 0x4fd9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4fde:
	/* 0x4fde: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4fe3:
	/* 0x4fe3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4fe8:
	/* 0x4fe8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4fed:
	/* 0x4fed: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4ff2:
	/* 0x4ff2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ff4:
	/* 0x4ff4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4ff6:
	/* 0x4ff6: js     66aa <generic_sleepable_preload+0x66aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26282ULL;
	}
x86_l_4ffc:
	/* 0x4ffc: cmp    WORD PTR [r13+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_5005:
	/* 0x5005: je     66b1 <generic_sleepable_preload+0x66b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26289ULL;
	}
x86_l_500b:
	/* 0x500b: mov    ecx,DWORD PTR [r13+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_5012:
	/* 0x5012: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5017:
	/* 0x5017: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_501c:
	/* 0x501c: cmp    WORD PTR [r13+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_5025:
	/* 0x5025: je     504a <generic_sleepable_preload+0x504a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_504a;
	}
x86_l_5027:
	/* 0x5027: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_502c:
	/* 0x502c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5031:
	/* 0x5031: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5036:
	/* 0x5036: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_503b:
	/* 0x503b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5040:
	/* 0x5040: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5042:
	/* 0x5042: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5044:
	/* 0x5044: js     6925 <generic_sleepable_preload+0x6925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26917ULL;
	}
x86_l_504a:
	/* 0x504a: cmp    WORD PTR [r13+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_5053:
	/* 0x5053: je     66b1 <generic_sleepable_preload+0x66b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26289ULL;
	}
x86_l_5059:
	/* 0x5059: mov    ecx,DWORD PTR [r13+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_5060:
	/* 0x5060: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5065:
	/* 0x5065: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_506a:
	/* 0x506a: cmp    WORD PTR [r13+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_5073:
	/* 0x5073: je     5098 <generic_sleepable_preload+0x5098> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5098;
	}
x86_l_5075:
	/* 0x5075: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_507a:
	/* 0x507a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_507f:
	/* 0x507f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5084:
	/* 0x5084: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5089:
	/* 0x5089: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_508e:
	/* 0x508e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5090:
	/* 0x5090: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5092:
	/* 0x5092: js     69a1 <generic_sleepable_preload+0x69a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27041ULL;
	}
x86_l_5098:
	/* 0x5098: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_509d:
	/* 0x509d: cmp    WORD PTR [r13+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_50a6:
	/* 0x50a6: je     66b1 <generic_sleepable_preload+0x66b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26289ULL;
	}
x86_l_50ac:
	/* 0x50ac: mov    ecx,DWORD PTR [r13+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_50b3:
	/* 0x50b3: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_50b8:
	/* 0x50b8: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_50bd:
	/* 0x50bd: cmp    WORD PTR [r13+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_50c6:
	/* 0x50c6: je     66b1 <generic_sleepable_preload+0x66b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26289ULL;
	}
x86_l_50cc:
	/* 0x50cc: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_50d1:
	/* 0x50d1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_50d6:
	/* 0x50d6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_50db:
	/* 0x50db: jmp    53c0 <generic_sleepable_preload+0x53c0> */
	return 21440ULL;
x86_l_50e0:
	/* 0x50e0: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_50e3:
	/* 0x50e3: je     5108 <generic_sleepable_preload+0x5108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5108;
	}
x86_l_50e5:
	/* 0x50e5: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_50ea:
	/* 0x50ea: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_50ef:
	/* 0x50ef: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_50f4:
	/* 0x50f4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_50f9:
	/* 0x50f9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_50fe:
	/* 0x50fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5100:
	/* 0x5100: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5102:
	/* 0x5102: js     53de <generic_sleepable_preload+0x53de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21470ULL;
	}
x86_l_5108:
	/* 0x5108: cmp    WORD PTR [r13+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_5111:
	/* 0x5111: je     66b1 <generic_sleepable_preload+0x66b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26289ULL;
	}
x86_l_5117:
	/* 0x5117: mov    ecx,DWORD PTR [r13+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_511e:
	/* 0x511e: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5123:
	/* 0x5123: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5128:
	/* 0x5128: cmp    WORD PTR [r13+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_5131:
	/* 0x5131: je     5156 <generic_sleepable_preload+0x5156> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5156;
	}
x86_l_5133:
	/* 0x5133: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5138:
	/* 0x5138: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_513d:
	/* 0x513d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5142:
	/* 0x5142: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5147:
	/* 0x5147: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_514c:
	/* 0x514c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_514e:
	/* 0x514e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5150:
	/* 0x5150: js     5452 <generic_sleepable_preload+0x5452> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21586ULL;
	}
x86_l_5156:
	/* 0x5156: cmp    WORD PTR [r13+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_515f:
	/* 0x515f: je     66b1 <generic_sleepable_preload+0x66b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26289ULL;
	}
x86_l_5165:
	/* 0x5165: mov    ecx,DWORD PTR [r13+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_516c:
	/* 0x516c: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5171:
	/* 0x5171: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5176:
	/* 0x5176: cmp    WORD PTR [r13+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_517f:
	/* 0x517f: je     51a4 <generic_sleepable_preload+0x51a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20900ULL;
	}
x86_l_5181:
	/* 0x5181: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5186:
	/* 0x5186: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_518b:
	/* 0x518b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5190:
	/* 0x5190: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5195:
	/* 0x5195: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
	return 20890ULL;
}

static __noinline __u64 tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_11(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 20890ULL: goto x86_l_519a;
	case 20892ULL: goto x86_l_519c;
	case 20894ULL: goto x86_l_519e;
	case 20900ULL: goto x86_l_51a4;
	case 20909ULL: goto x86_l_51ad;
	case 20915ULL: goto x86_l_51b3;
	case 20922ULL: goto x86_l_51ba;
	case 20927ULL: goto x86_l_51bf;
	case 20932ULL: goto x86_l_51c4;
	case 20941ULL: goto x86_l_51cd;
	case 20943ULL: goto x86_l_51cf;
	case 20948ULL: goto x86_l_51d4;
	case 20953ULL: goto x86_l_51d9;
	case 20958ULL: goto x86_l_51de;
	case 20963ULL: goto x86_l_51e3;
	case 20968ULL: goto x86_l_51e8;
	case 20970ULL: goto x86_l_51ea;
	case 20972ULL: goto x86_l_51ec;
	case 20978ULL: goto x86_l_51f2;
	case 20987ULL: goto x86_l_51fb;
	case 20993ULL: goto x86_l_5201;
	case 21000ULL: goto x86_l_5208;
	case 21005ULL: goto x86_l_520d;
	case 21010ULL: goto x86_l_5212;
	case 21019ULL: goto x86_l_521b;
	case 21021ULL: goto x86_l_521d;
	case 21026ULL: goto x86_l_5222;
	case 21031ULL: goto x86_l_5227;
	case 21036ULL: goto x86_l_522c;
	case 21041ULL: goto x86_l_5231;
	case 21046ULL: goto x86_l_5236;
	case 21048ULL: goto x86_l_5238;
	case 21050ULL: goto x86_l_523a;
	case 21056ULL: goto x86_l_5240;
	case 21065ULL: goto x86_l_5249;
	case 21071ULL: goto x86_l_524f;
	case 21078ULL: goto x86_l_5256;
	case 21083ULL: goto x86_l_525b;
	case 21088ULL: goto x86_l_5260;
	case 21097ULL: goto x86_l_5269;
	case 21099ULL: goto x86_l_526b;
	case 21104ULL: goto x86_l_5270;
	case 21109ULL: goto x86_l_5275;
	case 21114ULL: goto x86_l_527a;
	case 21119ULL: goto x86_l_527f;
	case 21124ULL: goto x86_l_5284;
	case 21126ULL: goto x86_l_5286;
	case 21128ULL: goto x86_l_5288;
	case 21134ULL: goto x86_l_528e;
	case 21143ULL: goto x86_l_5297;
	case 21149ULL: goto x86_l_529d;
	case 21156ULL: goto x86_l_52a4;
	case 21161ULL: goto x86_l_52a9;
	case 21166ULL: goto x86_l_52ae;
	case 21175ULL: goto x86_l_52b7;
	case 21177ULL: goto x86_l_52b9;
	case 21182ULL: goto x86_l_52be;
	case 21187ULL: goto x86_l_52c3;
	case 21192ULL: goto x86_l_52c8;
	case 21197ULL: goto x86_l_52cd;
	case 21202ULL: goto x86_l_52d2;
	case 21204ULL: goto x86_l_52d4;
	case 21206ULL: goto x86_l_52d6;
	case 21212ULL: goto x86_l_52dc;
	case 21221ULL: goto x86_l_52e5;
	case 21227ULL: goto x86_l_52eb;
	case 21234ULL: goto x86_l_52f2;
	case 21239ULL: goto x86_l_52f7;
	case 21244ULL: goto x86_l_52fc;
	case 21253ULL: goto x86_l_5305;
	case 21255ULL: goto x86_l_5307;
	case 21260ULL: goto x86_l_530c;
	case 21265ULL: goto x86_l_5311;
	case 21270ULL: goto x86_l_5316;
	case 21275ULL: goto x86_l_531b;
	case 21280ULL: goto x86_l_5320;
	case 21282ULL: goto x86_l_5322;
	case 21284ULL: goto x86_l_5324;
	case 21290ULL: goto x86_l_532a;
	case 21295ULL: goto x86_l_532f;
	case 21304ULL: goto x86_l_5338;
	case 21310ULL: goto x86_l_533e;
	case 21317ULL: goto x86_l_5345;
	case 21322ULL: goto x86_l_534a;
	case 21327ULL: goto x86_l_534f;
	case 21336ULL: goto x86_l_5358;
	case 21338ULL: goto x86_l_535a;
	case 21343ULL: goto x86_l_535f;
	case 21348ULL: goto x86_l_5364;
	case 21353ULL: goto x86_l_5369;
	case 21358ULL: goto x86_l_536e;
	case 21363ULL: goto x86_l_5373;
	case 21365ULL: goto x86_l_5375;
	case 21367ULL: goto x86_l_5377;
	case 21373ULL: goto x86_l_537d;
	case 21378ULL: goto x86_l_5382;
	case 21387ULL: goto x86_l_538b;
	case 21393ULL: goto x86_l_5391;
	case 21400ULL: goto x86_l_5398;
	case 21405ULL: goto x86_l_539d;
	case 21410ULL: goto x86_l_53a2;
	case 21419ULL: goto x86_l_53ab;
	case 21425ULL: goto x86_l_53b1;
	case 21430ULL: goto x86_l_53b6;
	case 21435ULL: goto x86_l_53bb;
	case 21440ULL: goto x86_l_53c0;
	case 21445ULL: goto x86_l_53c5;
	case 21450ULL: goto x86_l_53ca;
	case 21452ULL: goto x86_l_53cc;
	case 21454ULL: goto x86_l_53ce;
	case 21460ULL: goto x86_l_53d4;
	case 21465ULL: goto x86_l_53d9;
	case 21470ULL: goto x86_l_53de;
	case 21475ULL: goto x86_l_53e3;
	case 21480ULL: goto x86_l_53e8;
	case 21488ULL: goto x86_l_53f0;
	case 21491ULL: goto x86_l_53f3;
	case 21497ULL: goto x86_l_53f9;
	case 21502ULL: goto x86_l_53fe;
	case 21505ULL: goto x86_l_5401;
	case 21511ULL: goto x86_l_5407;
	case 21516ULL: goto x86_l_540c;
	case 21521ULL: goto x86_l_5411;
	case 21526ULL: goto x86_l_5416;
	case 21531ULL: goto x86_l_541b;
	case 21536ULL: goto x86_l_5420;
	case 21541ULL: goto x86_l_5425;
	case 21546ULL: goto x86_l_542a;
	case 21551ULL: goto x86_l_542f;
	case 21556ULL: goto x86_l_5434;
	case 21561ULL: goto x86_l_5439;
	case 21566ULL: goto x86_l_543e;
	case 21571ULL: goto x86_l_5443;
	case 21576ULL: goto x86_l_5448;
	case 21581ULL: goto x86_l_544d;
	case 21586ULL: goto x86_l_5452;
	case 21591ULL: goto x86_l_5457;
	case 21596ULL: goto x86_l_545c;
	case 21599ULL: goto x86_l_545f;
	case 21602ULL: goto x86_l_5462;
	case 21604ULL: goto x86_l_5464;
	case 21606ULL: goto x86_l_5466;
	case 21611ULL: goto x86_l_546b;
	case 21613ULL: goto x86_l_546d;
	case 21618ULL: goto x86_l_5472;
	case 21623ULL: goto x86_l_5477;
	case 21627ULL: goto x86_l_547b;
	case 21629ULL: goto x86_l_547d;
	case 21632ULL: goto x86_l_5480;
	case 21641ULL: goto x86_l_5489;
	case 21647ULL: goto x86_l_548f;
	case 21654ULL: goto x86_l_5496;
	case 21657ULL: goto x86_l_5499;
	case 21664ULL: goto x86_l_54a0;
	case 21667ULL: goto x86_l_54a3;
	case 21672ULL: goto x86_l_54a8;
	case 21680ULL: goto x86_l_54b0;
	case 21682ULL: goto x86_l_54b2;
	case 21688ULL: goto x86_l_54b8;
	case 21691ULL: goto x86_l_54bb;
	case 21693ULL: goto x86_l_54bd;
	case 21698ULL: goto x86_l_54c2;
	case 21703ULL: goto x86_l_54c7;
	case 21708ULL: goto x86_l_54cc;
	case 21713ULL: goto x86_l_54d1;
	case 21718ULL: goto x86_l_54d6;
	case 21720ULL: goto x86_l_54d8;
	case 21722ULL: goto x86_l_54da;
	case 21728ULL: goto x86_l_54e0;
	case 21737ULL: goto x86_l_54e9;
	case 21743ULL: goto x86_l_54ef;
	case 21750ULL: goto x86_l_54f6;
	case 21755ULL: goto x86_l_54fb;
	case 21760ULL: goto x86_l_5500;
	case 21769ULL: goto x86_l_5509;
	case 21771ULL: goto x86_l_550b;
	case 21776ULL: goto x86_l_5510;
	case 21781ULL: goto x86_l_5515;
	case 21786ULL: goto x86_l_551a;
	case 21791ULL: goto x86_l_551f;
	case 21796ULL: goto x86_l_5524;
	case 21798ULL: goto x86_l_5526;
	case 21800ULL: goto x86_l_5528;
	case 21806ULL: goto x86_l_552e;
	case 21815ULL: goto x86_l_5537;
	case 21821ULL: goto x86_l_553d;
	case 21828ULL: goto x86_l_5544;
	case 21833ULL: goto x86_l_5549;
	case 21838ULL: goto x86_l_554e;
	case 21847ULL: goto x86_l_5557;
	case 21849ULL: goto x86_l_5559;
	case 21854ULL: goto x86_l_555e;
	case 21859ULL: goto x86_l_5563;
	case 21864ULL: goto x86_l_5568;
	case 21869ULL: goto x86_l_556d;
	case 21874ULL: goto x86_l_5572;
	case 21876ULL: goto x86_l_5574;
	case 21878ULL: goto x86_l_5576;
	case 21884ULL: goto x86_l_557c;
	case 21893ULL: goto x86_l_5585;
	case 21899ULL: goto x86_l_558b;
	case 21906ULL: goto x86_l_5592;
	case 21911ULL: goto x86_l_5597;
	case 21916ULL: goto x86_l_559c;
	case 21925ULL: goto x86_l_55a5;
	case 21927ULL: goto x86_l_55a7;
	case 21932ULL: goto x86_l_55ac;
	case 21937ULL: goto x86_l_55b1;
	case 21942ULL: goto x86_l_55b6;
	case 21947ULL: goto x86_l_55bb;
	case 21952ULL: goto x86_l_55c0;
	case 21954ULL: goto x86_l_55c2;
	case 21956ULL: goto x86_l_55c4;
	case 21962ULL: goto x86_l_55ca;
	case 21971ULL: goto x86_l_55d3;
	case 21977ULL: goto x86_l_55d9;
	case 21984ULL: goto x86_l_55e0;
	case 21989ULL: goto x86_l_55e5;
	case 21994ULL: goto x86_l_55ea;
	case 22003ULL: goto x86_l_55f3;
	case 22005ULL: goto x86_l_55f5;
	case 22010ULL: goto x86_l_55fa;
	case 22015ULL: goto x86_l_55ff;
	case 22020ULL: goto x86_l_5604;
	case 22025ULL: goto x86_l_5609;
	case 22030ULL: goto x86_l_560e;
	case 22032ULL: goto x86_l_5610;
	case 22034ULL: goto x86_l_5612;
	case 22040ULL: goto x86_l_5618;
	case 22049ULL: goto x86_l_5621;
	case 22055ULL: goto x86_l_5627;
	case 22062ULL: goto x86_l_562e;
	case 22067ULL: goto x86_l_5633;
	case 22072ULL: goto x86_l_5638;
	case 22081ULL: goto x86_l_5641;
	case 22083ULL: goto x86_l_5643;
	case 22088ULL: goto x86_l_5648;
	case 22093ULL: goto x86_l_564d;
	case 22098ULL: goto x86_l_5652;
	case 22103ULL: goto x86_l_5657;
	case 22108ULL: goto x86_l_565c;
	case 22110ULL: goto x86_l_565e;
	case 22112ULL: goto x86_l_5660;
	case 22118ULL: goto x86_l_5666;
	case 22127ULL: goto x86_l_566f;
	case 22133ULL: goto x86_l_5675;
	case 22140ULL: goto x86_l_567c;
	case 22145ULL: goto x86_l_5681;
	case 22150ULL: goto x86_l_5686;
	case 22159ULL: goto x86_l_568f;
	case 22161ULL: goto x86_l_5691;
	case 22166ULL: goto x86_l_5696;
	case 22171ULL: goto x86_l_569b;
	case 22176ULL: goto x86_l_56a0;
	case 22181ULL: goto x86_l_56a5;
	case 22186ULL: goto x86_l_56aa;
	case 22188ULL: goto x86_l_56ac;
	case 22190ULL: goto x86_l_56ae;
	case 22196ULL: goto x86_l_56b4;
	case 22205ULL: goto x86_l_56bd;
	case 22211ULL: goto x86_l_56c3;
	case 22218ULL: goto x86_l_56ca;
	case 22223ULL: goto x86_l_56cf;
	case 22228ULL: goto x86_l_56d4;
	case 22237ULL: goto x86_l_56dd;
	case 22239ULL: goto x86_l_56df;
	case 22244ULL: goto x86_l_56e4;
	case 22249ULL: goto x86_l_56e9;
	case 22254ULL: goto x86_l_56ee;
	case 22259ULL: goto x86_l_56f3;
	case 22264ULL: goto x86_l_56f8;
	case 22266ULL: goto x86_l_56fa;
	case 22268ULL: goto x86_l_56fc;
	case 22274ULL: goto x86_l_5702;
	case 22283ULL: goto x86_l_570b;
	case 22289ULL: goto x86_l_5711;
	case 22296ULL: goto x86_l_5718;
	case 22301ULL: goto x86_l_571d;
	case 22306ULL: goto x86_l_5722;
	case 22315ULL: goto x86_l_572b;
	case 22317ULL: goto x86_l_572d;
	case 22322ULL: goto x86_l_5732;
	case 22327ULL: goto x86_l_5737;
	case 22332ULL: goto x86_l_573c;
	case 22337ULL: goto x86_l_5741;
	case 22342ULL: goto x86_l_5746;
	case 22344ULL: goto x86_l_5748;
	case 22346ULL: goto x86_l_574a;
	case 22352ULL: goto x86_l_5750;
	case 22357ULL: goto x86_l_5755;
	case 22366ULL: goto x86_l_575e;
	case 22372ULL: goto x86_l_5764;
	case 22379ULL: goto x86_l_576b;
	case 22384ULL: goto x86_l_5770;
	case 22389ULL: goto x86_l_5775;
	case 22398ULL: goto x86_l_577e;
	case 22404ULL: goto x86_l_5784;
	case 22409ULL: goto x86_l_5789;
	case 22414ULL: goto x86_l_578e;
	case 22419ULL: goto x86_l_5793;
	case 22424ULL: goto x86_l_5798;
	case 22427ULL: goto x86_l_579b;
	case 22429ULL: goto x86_l_579d;
	case 22434ULL: goto x86_l_57a2;
	case 22439ULL: goto x86_l_57a7;
	case 22444ULL: goto x86_l_57ac;
	case 22449ULL: goto x86_l_57b1;
	case 22454ULL: goto x86_l_57b6;
	case 22456ULL: goto x86_l_57b8;
	case 22458ULL: goto x86_l_57ba;
	case 22464ULL: goto x86_l_57c0;
	case 22473ULL: goto x86_l_57c9;
	case 22479ULL: goto x86_l_57cf;
	case 22486ULL: goto x86_l_57d6;
	case 22491ULL: goto x86_l_57db;
	case 22496ULL: goto x86_l_57e0;
	case 22505ULL: goto x86_l_57e9;
	case 22507ULL: goto x86_l_57eb;
	case 22512ULL: goto x86_l_57f0;
	case 22517ULL: goto x86_l_57f5;
	case 22522ULL: goto x86_l_57fa;
	case 22527ULL: goto x86_l_57ff;
	case 22532ULL: goto x86_l_5804;
	case 22534ULL: goto x86_l_5806;
	case 22536ULL: goto x86_l_5808;
	case 22542ULL: goto x86_l_580e;
	case 22551ULL: goto x86_l_5817;
	case 22557ULL: goto x86_l_581d;
	case 22564ULL: goto x86_l_5824;
	case 22569ULL: goto x86_l_5829;
	case 22574ULL: goto x86_l_582e;
	case 22583ULL: goto x86_l_5837;
	case 22585ULL: goto x86_l_5839;
	case 22590ULL: goto x86_l_583e;
	case 22595ULL: goto x86_l_5843;
	case 22600ULL: goto x86_l_5848;
	case 22605ULL: goto x86_l_584d;
	case 22610ULL: goto x86_l_5852;
	case 22612ULL: goto x86_l_5854;
	case 22614ULL: goto x86_l_5856;
	case 22620ULL: goto x86_l_585c;
	case 22629ULL: goto x86_l_5865;
	case 22635ULL: goto x86_l_586b;
	case 22642ULL: goto x86_l_5872;
	case 22647ULL: goto x86_l_5877;
	case 22652ULL: goto x86_l_587c;
	case 22661ULL: goto x86_l_5885;
	case 22663ULL: goto x86_l_5887;
	case 22668ULL: goto x86_l_588c;
	case 22673ULL: goto x86_l_5891;
	case 22678ULL: goto x86_l_5896;
	case 22683ULL: goto x86_l_589b;
	case 22688ULL: goto x86_l_58a0;
	case 22690ULL: goto x86_l_58a2;
	case 22692ULL: goto x86_l_58a4;
	case 22698ULL: goto x86_l_58aa;
	case 22707ULL: goto x86_l_58b3;
	case 22713ULL: goto x86_l_58b9;
	case 22720ULL: goto x86_l_58c0;
	case 22725ULL: goto x86_l_58c5;
	case 22730ULL: goto x86_l_58ca;
	case 22739ULL: goto x86_l_58d3;
	case 22741ULL: goto x86_l_58d5;
	case 22746ULL: goto x86_l_58da;
	case 22751ULL: goto x86_l_58df;
	case 22756ULL: goto x86_l_58e4;
	case 22761ULL: goto x86_l_58e9;
	case 22766ULL: goto x86_l_58ee;
	case 22768ULL: goto x86_l_58f0;
	case 22770ULL: goto x86_l_58f2;
	case 22776ULL: goto x86_l_58f8;
	case 22785ULL: goto x86_l_5901;
	case 22791ULL: goto x86_l_5907;
	case 22798ULL: goto x86_l_590e;
	case 22803ULL: goto x86_l_5913;
	case 22808ULL: goto x86_l_5918;
	case 22817ULL: goto x86_l_5921;
	case 22819ULL: goto x86_l_5923;
	case 22824ULL: goto x86_l_5928;
	case 22829ULL: goto x86_l_592d;
	case 22834ULL: goto x86_l_5932;
	case 22839ULL: goto x86_l_5937;
	case 22844ULL: goto x86_l_593c;
	case 22846ULL: goto x86_l_593e;
	default: return 0xffffffffffffffffULL;
	}
x86_l_519a:
	/* 0x519a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_519c:
	/* 0x519c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_519e:
	/* 0x519e: js     6139 <generic_sleepable_preload+0x6139> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24889ULL;
	}
x86_l_51a4:
	/* 0x51a4: cmp    WORD PTR [r13+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_51ad:
	/* 0x51ad: je     66b1 <generic_sleepable_preload+0x66b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26289ULL;
	}
x86_l_51b3:
	/* 0x51b3: mov    ecx,DWORD PTR [r13+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_51ba:
	/* 0x51ba: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_51bf:
	/* 0x51bf: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_51c4:
	/* 0x51c4: cmp    WORD PTR [r13+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_51cd:
	/* 0x51cd: je     51f2 <generic_sleepable_preload+0x51f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_51f2;
	}
x86_l_51cf:
	/* 0x51cf: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_51d4:
	/* 0x51d4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_51d9:
	/* 0x51d9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_51de:
	/* 0x51de: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_51e3:
	/* 0x51e3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_51e8:
	/* 0x51e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_51ea:
	/* 0x51ea: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_51ec:
	/* 0x51ec: js     619d <generic_sleepable_preload+0x619d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24989ULL;
	}
x86_l_51f2:
	/* 0x51f2: cmp    WORD PTR [r13+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_51fb:
	/* 0x51fb: je     66b1 <generic_sleepable_preload+0x66b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26289ULL;
	}
x86_l_5201:
	/* 0x5201: mov    ecx,DWORD PTR [r13+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_5208:
	/* 0x5208: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_520d:
	/* 0x520d: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5212:
	/* 0x5212: cmp    WORD PTR [r13+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_521b:
	/* 0x521b: je     5240 <generic_sleepable_preload+0x5240> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5240;
	}
x86_l_521d:
	/* 0x521d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5222:
	/* 0x5222: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5227:
	/* 0x5227: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_522c:
	/* 0x522c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5231:
	/* 0x5231: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5236:
	/* 0x5236: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5238:
	/* 0x5238: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_523a:
	/* 0x523a: js     6201 <generic_sleepable_preload+0x6201> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25089ULL;
	}
x86_l_5240:
	/* 0x5240: cmp    WORD PTR [r13+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_5249:
	/* 0x5249: je     66b1 <generic_sleepable_preload+0x66b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26289ULL;
	}
x86_l_524f:
	/* 0x524f: mov    ecx,DWORD PTR [r13+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_5256:
	/* 0x5256: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_525b:
	/* 0x525b: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5260:
	/* 0x5260: cmp    WORD PTR [r13+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_5269:
	/* 0x5269: je     528e <generic_sleepable_preload+0x528e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_528e;
	}
x86_l_526b:
	/* 0x526b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5270:
	/* 0x5270: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5275:
	/* 0x5275: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_527a:
	/* 0x527a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_527f:
	/* 0x527f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5284:
	/* 0x5284: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5286:
	/* 0x5286: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5288:
	/* 0x5288: js     6262 <generic_sleepable_preload+0x6262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25186ULL;
	}
x86_l_528e:
	/* 0x528e: cmp    WORD PTR [r13+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_5297:
	/* 0x5297: je     66b1 <generic_sleepable_preload+0x66b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26289ULL;
	}
x86_l_529d:
	/* 0x529d: mov    ecx,DWORD PTR [r13+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_52a4:
	/* 0x52a4: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_52a9:
	/* 0x52a9: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52ae:
	/* 0x52ae: cmp    WORD PTR [r13+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_52b7:
	/* 0x52b7: je     52dc <generic_sleepable_preload+0x52dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_52dc;
	}
x86_l_52b9:
	/* 0x52b9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52be:
	/* 0x52be: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_52c3:
	/* 0x52c3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_52c8:
	/* 0x52c8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52cd:
	/* 0x52cd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_52d2:
	/* 0x52d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52d4:
	/* 0x52d4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_52d6:
	/* 0x52d6: js     66aa <generic_sleepable_preload+0x66aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26282ULL;
	}
x86_l_52dc:
	/* 0x52dc: cmp    WORD PTR [r13+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_52e5:
	/* 0x52e5: je     66b1 <generic_sleepable_preload+0x66b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26289ULL;
	}
x86_l_52eb:
	/* 0x52eb: mov    ecx,DWORD PTR [r13+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_52f2:
	/* 0x52f2: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_52f7:
	/* 0x52f7: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52fc:
	/* 0x52fc: cmp    WORD PTR [r13+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_5305:
	/* 0x5305: je     532a <generic_sleepable_preload+0x532a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_532a;
	}
x86_l_5307:
	/* 0x5307: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_530c:
	/* 0x530c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5311:
	/* 0x5311: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5316:
	/* 0x5316: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_531b:
	/* 0x531b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5320:
	/* 0x5320: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5322:
	/* 0x5322: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5324:
	/* 0x5324: js     6a59 <generic_sleepable_preload+0x6a59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27225ULL;
	}
x86_l_532a:
	/* 0x532a: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_532f:
	/* 0x532f: cmp    WORD PTR [r13+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_5338:
	/* 0x5338: je     66b1 <generic_sleepable_preload+0x66b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26289ULL;
	}
x86_l_533e:
	/* 0x533e: mov    ecx,DWORD PTR [r13+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_5345:
	/* 0x5345: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_534a:
	/* 0x534a: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_534f:
	/* 0x534f: cmp    WORD PTR [r13+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_5358:
	/* 0x5358: je     537d <generic_sleepable_preload+0x537d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_537d;
	}
x86_l_535a:
	/* 0x535a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_535f:
	/* 0x535f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5364:
	/* 0x5364: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5369:
	/* 0x5369: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_536e:
	/* 0x536e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5373:
	/* 0x5373: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5375:
	/* 0x5375: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5377:
	/* 0x5377: js     69a1 <generic_sleepable_preload+0x69a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27041ULL;
	}
x86_l_537d:
	/* 0x537d: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5382:
	/* 0x5382: cmp    WORD PTR [r13+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_538b:
	/* 0x538b: je     66b1 <generic_sleepable_preload+0x66b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26289ULL;
	}
x86_l_5391:
	/* 0x5391: mov    ecx,DWORD PTR [r13+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_5398:
	/* 0x5398: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_539d:
	/* 0x539d: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_53a2:
	/* 0x53a2: cmp    WORD PTR [r13+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_53ab:
	/* 0x53ab: je     66b1 <generic_sleepable_preload+0x66b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26289ULL;
	}
x86_l_53b1:
	/* 0x53b1: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_53b6:
	/* 0x53b6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_53bb:
	/* 0x53bb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_53c0:
	/* 0x53c0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_53c5:
	/* 0x53c5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_53ca:
	/* 0x53ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_53cc:
	/* 0x53cc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_53ce:
	/* 0x53ce: jns    66b1 <generic_sleepable_preload+0x66b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 26289ULL;
	}
x86_l_53d4:
	/* 0x53d4: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_53d9:
	/* 0x53d9: jmp    66af <generic_sleepable_preload+0x66af> */
	return 26287ULL;
x86_l_53de:
	/* 0x53de: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_53e3:
	/* 0x53e3: jmp    66af <generic_sleepable_preload+0x66af> */
	return 26287ULL;
x86_l_53e8:
	/* 0x53e8: mov    rsi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_53f0:
	/* 0x53f0: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_53f3:
	/* 0x53f3: je     5aaf <generic_sleepable_preload+0x5aaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23215ULL;
	}
x86_l_53f9:
	/* 0x53f9: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_53fe:
	/* 0x53fe: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_5401:
	/* 0x5401: je     5aaf <generic_sleepable_preload+0x5aaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23215ULL;
	}
x86_l_5407:
	/* 0x5407: jmp    5ac2 <generic_sleepable_preload+0x5ac2> */
	return 23234ULL;
x86_l_540c:
	/* 0x540c: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_5411:
	/* 0x5411: jmp    6285 <generic_sleepable_preload+0x6285> */
	return 25221ULL;
x86_l_5416:
	/* 0x5416: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_541b:
	/* 0x541b: jmp    6312 <generic_sleepable_preload+0x6312> */
	return 25362ULL;
x86_l_5420:
	/* 0x5420: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_5425:
	/* 0x5425: jmp    639f <generic_sleepable_preload+0x639f> */
	return 25503ULL;
x86_l_542a:
	/* 0x542a: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_542f:
	/* 0x542f: jmp    642c <generic_sleepable_preload+0x642c> */
	return 25644ULL;
x86_l_5434:
	/* 0x5434: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_5439:
	/* 0x5439: jmp    64b9 <generic_sleepable_preload+0x64b9> */
	return 25785ULL;
x86_l_543e:
	/* 0x543e: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_5443:
	/* 0x5443: jmp    6546 <generic_sleepable_preload+0x6546> */
	return 25926ULL;
x86_l_5448:
	/* 0x5448: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_544d:
	/* 0x544d: jmp    65fa <generic_sleepable_preload+0x65fa> */
	return 26106ULL;
x86_l_5452:
	/* 0x5452: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_5457:
	/* 0x5457: jmp    66af <generic_sleepable_preload+0x66af> */
	return 26287ULL;
x86_l_545c:
	/* 0x545c: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_545f:
	/* 0x545f: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_5462:
	/* 0x5462: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_5464:
	/* 0x5464: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_5466:
	/* 0x5466: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_546b:
	/* 0x546b: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_546d:
	/* 0x546d: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_5472:
	/* 0x5472: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5477:
	/* 0x5477: mov    r14d,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_547b:
	/* 0x547b: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_547d:
	/* 0x547d: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_5480:
	/* 0x5480: cmp    WORD PTR [r13+0xc6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 850403524608ULL);
x86_l_5489:
	/* 0x5489: je     6761 <generic_sleepable_preload+0x6761> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26465ULL;
	}
x86_l_548f:
	/* 0x548f: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_5496:
	/* 0x5496: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_5499:
	/* 0x5499: mov    eax,DWORD PTR [r13+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_54a0:
	/* 0x54a0: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_54a3:
	/* 0x54a3: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_54a8:
	/* 0x54a8: movzx  eax,WORD PTR [r13+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 196ULL);
x86_l_54b0:
	/* 0x54b0: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_54b2:
	/* 0x54b2: je     5798 <generic_sleepable_preload+0x5798> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5798;
	}
x86_l_54b8:
	/* 0x54b8: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_54bb:
	/* 0x54bb: je     54e0 <generic_sleepable_preload+0x54e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_54e0;
	}
x86_l_54bd:
	/* 0x54bd: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_54c2:
	/* 0x54c2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_54c7:
	/* 0x54c7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_54cc:
	/* 0x54cc: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_54d1:
	/* 0x54d1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_54d6:
	/* 0x54d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_54d8:
	/* 0x54d8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_54da:
	/* 0x54da: js     5a96 <generic_sleepable_preload+0x5a96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23190ULL;
	}
x86_l_54e0:
	/* 0x54e0: cmp    WORD PTR [r13+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_54e9:
	/* 0x54e9: je     6761 <generic_sleepable_preload+0x6761> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26465ULL;
	}
x86_l_54ef:
	/* 0x54ef: mov    ecx,DWORD PTR [r13+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_54f6:
	/* 0x54f6: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_54fb:
	/* 0x54fb: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5500:
	/* 0x5500: cmp    WORD PTR [r13+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_5509:
	/* 0x5509: je     552e <generic_sleepable_preload+0x552e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_552e;
	}
x86_l_550b:
	/* 0x550b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5510:
	/* 0x5510: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5515:
	/* 0x5515: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_551a:
	/* 0x551a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_551f:
	/* 0x551f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5524:
	/* 0x5524: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5526:
	/* 0x5526: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5528:
	/* 0x5528: js     5aa0 <generic_sleepable_preload+0x5aa0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23200ULL;
	}
x86_l_552e:
	/* 0x552e: cmp    WORD PTR [r13+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_5537:
	/* 0x5537: je     6761 <generic_sleepable_preload+0x6761> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26465ULL;
	}
x86_l_553d:
	/* 0x553d: mov    ecx,DWORD PTR [r13+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_5544:
	/* 0x5544: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5549:
	/* 0x5549: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_554e:
	/* 0x554e: cmp    WORD PTR [r13+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_5557:
	/* 0x5557: je     557c <generic_sleepable_preload+0x557c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_557c;
	}
x86_l_5559:
	/* 0x5559: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_555e:
	/* 0x555e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5563:
	/* 0x5563: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5568:
	/* 0x5568: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_556d:
	/* 0x556d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5572:
	/* 0x5572: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5574:
	/* 0x5574: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5576:
	/* 0x5576: js     6143 <generic_sleepable_preload+0x6143> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24899ULL;
	}
x86_l_557c:
	/* 0x557c: cmp    WORD PTR [r13+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_5585:
	/* 0x5585: je     6761 <generic_sleepable_preload+0x6761> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26465ULL;
	}
x86_l_558b:
	/* 0x558b: mov    ecx,DWORD PTR [r13+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_5592:
	/* 0x5592: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5597:
	/* 0x5597: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_559c:
	/* 0x559c: cmp    WORD PTR [r13+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_55a5:
	/* 0x55a5: je     55ca <generic_sleepable_preload+0x55ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_55ca;
	}
x86_l_55a7:
	/* 0x55a7: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_55ac:
	/* 0x55ac: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_55b1:
	/* 0x55b1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_55b6:
	/* 0x55b6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_55bb:
	/* 0x55bb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_55c0:
	/* 0x55c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55c2:
	/* 0x55c2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_55c4:
	/* 0x55c4: js     61a7 <generic_sleepable_preload+0x61a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24999ULL;
	}
x86_l_55ca:
	/* 0x55ca: cmp    WORD PTR [r13+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_55d3:
	/* 0x55d3: je     6761 <generic_sleepable_preload+0x6761> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26465ULL;
	}
x86_l_55d9:
	/* 0x55d9: mov    ecx,DWORD PTR [r13+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_55e0:
	/* 0x55e0: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_55e5:
	/* 0x55e5: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_55ea:
	/* 0x55ea: cmp    WORD PTR [r13+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_55f3:
	/* 0x55f3: je     5618 <generic_sleepable_preload+0x5618> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5618;
	}
x86_l_55f5:
	/* 0x55f5: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_55fa:
	/* 0x55fa: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_55ff:
	/* 0x55ff: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5604:
	/* 0x5604: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5609:
	/* 0x5609: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_560e:
	/* 0x560e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5610:
	/* 0x5610: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5612:
	/* 0x5612: js     620b <generic_sleepable_preload+0x620b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25099ULL;
	}
x86_l_5618:
	/* 0x5618: cmp    WORD PTR [r13+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_5621:
	/* 0x5621: je     6761 <generic_sleepable_preload+0x6761> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26465ULL;
	}
x86_l_5627:
	/* 0x5627: mov    ecx,DWORD PTR [r13+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_562e:
	/* 0x562e: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5633:
	/* 0x5633: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5638:
	/* 0x5638: cmp    WORD PTR [r13+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_5641:
	/* 0x5641: je     5666 <generic_sleepable_preload+0x5666> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5666;
	}
x86_l_5643:
	/* 0x5643: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5648:
	/* 0x5648: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_564d:
	/* 0x564d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5652:
	/* 0x5652: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5657:
	/* 0x5657: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_565c:
	/* 0x565c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_565e:
	/* 0x565e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5660:
	/* 0x5660: js     626c <generic_sleepable_preload+0x626c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25196ULL;
	}
x86_l_5666:
	/* 0x5666: cmp    WORD PTR [r13+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_566f:
	/* 0x566f: je     6761 <generic_sleepable_preload+0x6761> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26465ULL;
	}
x86_l_5675:
	/* 0x5675: mov    ecx,DWORD PTR [r13+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_567c:
	/* 0x567c: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5681:
	/* 0x5681: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5686:
	/* 0x5686: cmp    WORD PTR [r13+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_568f:
	/* 0x568f: je     56b4 <generic_sleepable_preload+0x56b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_56b4;
	}
x86_l_5691:
	/* 0x5691: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5696:
	/* 0x5696: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_569b:
	/* 0x569b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_56a0:
	/* 0x56a0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_56a5:
	/* 0x56a5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_56aa:
	/* 0x56aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_56ac:
	/* 0x56ac: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_56ae:
	/* 0x56ae: js     675a <generic_sleepable_preload+0x675a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26458ULL;
	}
x86_l_56b4:
	/* 0x56b4: cmp    WORD PTR [r13+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_56bd:
	/* 0x56bd: je     6761 <generic_sleepable_preload+0x6761> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26465ULL;
	}
x86_l_56c3:
	/* 0x56c3: mov    ecx,DWORD PTR [r13+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_56ca:
	/* 0x56ca: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_56cf:
	/* 0x56cf: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_56d4:
	/* 0x56d4: cmp    WORD PTR [r13+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_56dd:
	/* 0x56dd: je     5702 <generic_sleepable_preload+0x5702> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5702;
	}
x86_l_56df:
	/* 0x56df: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_56e4:
	/* 0x56e4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_56e9:
	/* 0x56e9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_56ee:
	/* 0x56ee: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_56f3:
	/* 0x56f3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_56f8:
	/* 0x56f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_56fa:
	/* 0x56fa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_56fc:
	/* 0x56fc: js     6931 <generic_sleepable_preload+0x6931> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26929ULL;
	}
x86_l_5702:
	/* 0x5702: cmp    WORD PTR [r13+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_570b:
	/* 0x570b: je     6761 <generic_sleepable_preload+0x6761> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26465ULL;
	}
x86_l_5711:
	/* 0x5711: mov    ecx,DWORD PTR [r13+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_5718:
	/* 0x5718: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_571d:
	/* 0x571d: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5722:
	/* 0x5722: cmp    WORD PTR [r13+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_572b:
	/* 0x572b: je     5750 <generic_sleepable_preload+0x5750> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5750;
	}
x86_l_572d:
	/* 0x572d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5732:
	/* 0x5732: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5737:
	/* 0x5737: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_573c:
	/* 0x573c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5741:
	/* 0x5741: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5746:
	/* 0x5746: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5748:
	/* 0x5748: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_574a:
	/* 0x574a: js     69b2 <generic_sleepable_preload+0x69b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27058ULL;
	}
x86_l_5750:
	/* 0x5750: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5755:
	/* 0x5755: cmp    WORD PTR [r13+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_575e:
	/* 0x575e: je     6761 <generic_sleepable_preload+0x6761> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26465ULL;
	}
x86_l_5764:
	/* 0x5764: mov    ecx,DWORD PTR [r13+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_576b:
	/* 0x576b: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5770:
	/* 0x5770: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5775:
	/* 0x5775: cmp    WORD PTR [r13+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_577e:
	/* 0x577e: je     6761 <generic_sleepable_preload+0x6761> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26465ULL;
	}
x86_l_5784:
	/* 0x5784: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5789:
	/* 0x5789: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_578e:
	/* 0x578e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5793:
	/* 0x5793: jmp    5a78 <generic_sleepable_preload+0x5a78> */
	return 23160ULL;
x86_l_5798:
	/* 0x5798: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_579b:
	/* 0x579b: je     57c0 <generic_sleepable_preload+0x57c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_57c0;
	}
x86_l_579d:
	/* 0x579d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_57a2:
	/* 0x57a2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_57a7:
	/* 0x57a7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_57ac:
	/* 0x57ac: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_57b1:
	/* 0x57b1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_57b6:
	/* 0x57b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_57b8:
	/* 0x57b8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_57ba:
	/* 0x57ba: js     5a96 <generic_sleepable_preload+0x5a96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23190ULL;
	}
x86_l_57c0:
	/* 0x57c0: cmp    WORD PTR [r13+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_57c9:
	/* 0x57c9: je     6761 <generic_sleepable_preload+0x6761> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26465ULL;
	}
x86_l_57cf:
	/* 0x57cf: mov    ecx,DWORD PTR [r13+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_57d6:
	/* 0x57d6: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_57db:
	/* 0x57db: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_57e0:
	/* 0x57e0: cmp    WORD PTR [r13+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_57e9:
	/* 0x57e9: je     580e <generic_sleepable_preload+0x580e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_580e;
	}
x86_l_57eb:
	/* 0x57eb: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_57f0:
	/* 0x57f0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_57f5:
	/* 0x57f5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_57fa:
	/* 0x57fa: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_57ff:
	/* 0x57ff: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5804:
	/* 0x5804: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5806:
	/* 0x5806: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5808:
	/* 0x5808: js     5aa0 <generic_sleepable_preload+0x5aa0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23200ULL;
	}
x86_l_580e:
	/* 0x580e: cmp    WORD PTR [r13+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_5817:
	/* 0x5817: je     6761 <generic_sleepable_preload+0x6761> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26465ULL;
	}
x86_l_581d:
	/* 0x581d: mov    ecx,DWORD PTR [r13+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_5824:
	/* 0x5824: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5829:
	/* 0x5829: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_582e:
	/* 0x582e: cmp    WORD PTR [r13+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_5837:
	/* 0x5837: je     585c <generic_sleepable_preload+0x585c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_585c;
	}
x86_l_5839:
	/* 0x5839: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_583e:
	/* 0x583e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5843:
	/* 0x5843: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5848:
	/* 0x5848: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_584d:
	/* 0x584d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5852:
	/* 0x5852: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5854:
	/* 0x5854: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5856:
	/* 0x5856: js     6143 <generic_sleepable_preload+0x6143> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24899ULL;
	}
x86_l_585c:
	/* 0x585c: cmp    WORD PTR [r13+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_5865:
	/* 0x5865: je     6761 <generic_sleepable_preload+0x6761> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26465ULL;
	}
x86_l_586b:
	/* 0x586b: mov    ecx,DWORD PTR [r13+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_5872:
	/* 0x5872: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5877:
	/* 0x5877: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_587c:
	/* 0x587c: cmp    WORD PTR [r13+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_5885:
	/* 0x5885: je     58aa <generic_sleepable_preload+0x58aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_58aa;
	}
x86_l_5887:
	/* 0x5887: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_588c:
	/* 0x588c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5891:
	/* 0x5891: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5896:
	/* 0x5896: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_589b:
	/* 0x589b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_58a0:
	/* 0x58a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58a2:
	/* 0x58a2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_58a4:
	/* 0x58a4: js     61a7 <generic_sleepable_preload+0x61a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24999ULL;
	}
x86_l_58aa:
	/* 0x58aa: cmp    WORD PTR [r13+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_58b3:
	/* 0x58b3: je     6761 <generic_sleepable_preload+0x6761> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26465ULL;
	}
x86_l_58b9:
	/* 0x58b9: mov    ecx,DWORD PTR [r13+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_58c0:
	/* 0x58c0: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_58c5:
	/* 0x58c5: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_58ca:
	/* 0x58ca: cmp    WORD PTR [r13+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_58d3:
	/* 0x58d3: je     58f8 <generic_sleepable_preload+0x58f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_58f8;
	}
x86_l_58d5:
	/* 0x58d5: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_58da:
	/* 0x58da: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_58df:
	/* 0x58df: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_58e4:
	/* 0x58e4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_58e9:
	/* 0x58e9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_58ee:
	/* 0x58ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58f0:
	/* 0x58f0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_58f2:
	/* 0x58f2: js     620b <generic_sleepable_preload+0x620b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25099ULL;
	}
x86_l_58f8:
	/* 0x58f8: cmp    WORD PTR [r13+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_5901:
	/* 0x5901: je     6761 <generic_sleepable_preload+0x6761> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26465ULL;
	}
x86_l_5907:
	/* 0x5907: mov    ecx,DWORD PTR [r13+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_590e:
	/* 0x590e: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5913:
	/* 0x5913: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5918:
	/* 0x5918: cmp    WORD PTR [r13+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_5921:
	/* 0x5921: je     5946 <generic_sleepable_preload+0x5946> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22854ULL;
	}
x86_l_5923:
	/* 0x5923: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5928:
	/* 0x5928: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_592d:
	/* 0x592d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5932:
	/* 0x5932: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5937:
	/* 0x5937: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_593c:
	/* 0x593c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_593e:
	/* 0x593e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
	return 22848ULL;
}

static __noinline __u64 tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_12(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 22848ULL: goto x86_l_5940;
	case 22854ULL: goto x86_l_5946;
	case 22863ULL: goto x86_l_594f;
	case 22869ULL: goto x86_l_5955;
	case 22876ULL: goto x86_l_595c;
	case 22881ULL: goto x86_l_5961;
	case 22886ULL: goto x86_l_5966;
	case 22895ULL: goto x86_l_596f;
	case 22897ULL: goto x86_l_5971;
	case 22902ULL: goto x86_l_5976;
	case 22907ULL: goto x86_l_597b;
	case 22912ULL: goto x86_l_5980;
	case 22917ULL: goto x86_l_5985;
	case 22922ULL: goto x86_l_598a;
	case 22924ULL: goto x86_l_598c;
	case 22926ULL: goto x86_l_598e;
	case 22932ULL: goto x86_l_5994;
	case 22941ULL: goto x86_l_599d;
	case 22947ULL: goto x86_l_59a3;
	case 22954ULL: goto x86_l_59aa;
	case 22959ULL: goto x86_l_59af;
	case 22964ULL: goto x86_l_59b4;
	case 22973ULL: goto x86_l_59bd;
	case 22975ULL: goto x86_l_59bf;
	case 22980ULL: goto x86_l_59c4;
	case 22985ULL: goto x86_l_59c9;
	case 22990ULL: goto x86_l_59ce;
	case 22995ULL: goto x86_l_59d3;
	case 23000ULL: goto x86_l_59d8;
	case 23002ULL: goto x86_l_59da;
	case 23004ULL: goto x86_l_59dc;
	case 23010ULL: goto x86_l_59e2;
	case 23015ULL: goto x86_l_59e7;
	case 23024ULL: goto x86_l_59f0;
	case 23030ULL: goto x86_l_59f6;
	case 23037ULL: goto x86_l_59fd;
	case 23042ULL: goto x86_l_5a02;
	case 23047ULL: goto x86_l_5a07;
	case 23056ULL: goto x86_l_5a10;
	case 23058ULL: goto x86_l_5a12;
	case 23063ULL: goto x86_l_5a17;
	case 23068ULL: goto x86_l_5a1c;
	case 23073ULL: goto x86_l_5a21;
	case 23078ULL: goto x86_l_5a26;
	case 23083ULL: goto x86_l_5a2b;
	case 23085ULL: goto x86_l_5a2d;
	case 23087ULL: goto x86_l_5a2f;
	case 23093ULL: goto x86_l_5a35;
	case 23098ULL: goto x86_l_5a3a;
	case 23107ULL: goto x86_l_5a43;
	case 23113ULL: goto x86_l_5a49;
	case 23120ULL: goto x86_l_5a50;
	case 23125ULL: goto x86_l_5a55;
	case 23130ULL: goto x86_l_5a5a;
	case 23139ULL: goto x86_l_5a63;
	case 23145ULL: goto x86_l_5a69;
	case 23150ULL: goto x86_l_5a6e;
	case 23155ULL: goto x86_l_5a73;
	case 23160ULL: goto x86_l_5a78;
	case 23165ULL: goto x86_l_5a7d;
	case 23170ULL: goto x86_l_5a82;
	case 23172ULL: goto x86_l_5a84;
	case 23174ULL: goto x86_l_5a86;
	case 23180ULL: goto x86_l_5a8c;
	case 23185ULL: goto x86_l_5a91;
	case 23190ULL: goto x86_l_5a96;
	case 23195ULL: goto x86_l_5a9b;
	case 23200ULL: goto x86_l_5aa0;
	case 23205ULL: goto x86_l_5aa5;
	case 23210ULL: goto x86_l_5aaa;
	case 23215ULL: goto x86_l_5aaf;
	case 23218ULL: goto x86_l_5ab2;
	case 23220ULL: goto x86_l_5ab4;
	case 23222ULL: goto x86_l_5ab6;
	case 23227ULL: goto x86_l_5abb;
	case 23229ULL: goto x86_l_5abd;
	case 23234ULL: goto x86_l_5ac2;
	case 23239ULL: goto x86_l_5ac7;
	case 23243ULL: goto x86_l_5acb;
	case 23245ULL: goto x86_l_5acd;
	case 23248ULL: goto x86_l_5ad0;
	case 23257ULL: goto x86_l_5ad9;
	case 23263ULL: goto x86_l_5adf;
	case 23270ULL: goto x86_l_5ae6;
	case 23273ULL: goto x86_l_5ae9;
	case 23280ULL: goto x86_l_5af0;
	case 23283ULL: goto x86_l_5af3;
	case 23288ULL: goto x86_l_5af8;
	case 23296ULL: goto x86_l_5b00;
	case 23298ULL: goto x86_l_5b02;
	case 23304ULL: goto x86_l_5b08;
	case 23307ULL: goto x86_l_5b0b;
	case 23309ULL: goto x86_l_5b0d;
	case 23314ULL: goto x86_l_5b12;
	case 23319ULL: goto x86_l_5b17;
	case 23324ULL: goto x86_l_5b1c;
	case 23329ULL: goto x86_l_5b21;
	case 23334ULL: goto x86_l_5b26;
	case 23336ULL: goto x86_l_5b28;
	case 23338ULL: goto x86_l_5b2a;
	case 23344ULL: goto x86_l_5b30;
	case 23353ULL: goto x86_l_5b39;
	case 23359ULL: goto x86_l_5b3f;
	case 23366ULL: goto x86_l_5b46;
	case 23371ULL: goto x86_l_5b4b;
	case 23376ULL: goto x86_l_5b50;
	case 23385ULL: goto x86_l_5b59;
	case 23387ULL: goto x86_l_5b5b;
	case 23392ULL: goto x86_l_5b60;
	case 23397ULL: goto x86_l_5b65;
	case 23402ULL: goto x86_l_5b6a;
	case 23407ULL: goto x86_l_5b6f;
	case 23412ULL: goto x86_l_5b74;
	case 23414ULL: goto x86_l_5b76;
	case 23416ULL: goto x86_l_5b78;
	case 23422ULL: goto x86_l_5b7e;
	case 23431ULL: goto x86_l_5b87;
	case 23437ULL: goto x86_l_5b8d;
	case 23444ULL: goto x86_l_5b94;
	case 23449ULL: goto x86_l_5b99;
	case 23454ULL: goto x86_l_5b9e;
	case 23463ULL: goto x86_l_5ba7;
	case 23465ULL: goto x86_l_5ba9;
	case 23470ULL: goto x86_l_5bae;
	case 23475ULL: goto x86_l_5bb3;
	case 23480ULL: goto x86_l_5bb8;
	case 23485ULL: goto x86_l_5bbd;
	case 23490ULL: goto x86_l_5bc2;
	case 23492ULL: goto x86_l_5bc4;
	case 23494ULL: goto x86_l_5bc6;
	case 23500ULL: goto x86_l_5bcc;
	case 23509ULL: goto x86_l_5bd5;
	case 23515ULL: goto x86_l_5bdb;
	case 23522ULL: goto x86_l_5be2;
	case 23527ULL: goto x86_l_5be7;
	case 23532ULL: goto x86_l_5bec;
	case 23541ULL: goto x86_l_5bf5;
	case 23543ULL: goto x86_l_5bf7;
	case 23548ULL: goto x86_l_5bfc;
	case 23553ULL: goto x86_l_5c01;
	case 23558ULL: goto x86_l_5c06;
	case 23563ULL: goto x86_l_5c0b;
	case 23568ULL: goto x86_l_5c10;
	case 23570ULL: goto x86_l_5c12;
	case 23572ULL: goto x86_l_5c14;
	case 23578ULL: goto x86_l_5c1a;
	case 23587ULL: goto x86_l_5c23;
	case 23593ULL: goto x86_l_5c29;
	case 23600ULL: goto x86_l_5c30;
	case 23605ULL: goto x86_l_5c35;
	case 23610ULL: goto x86_l_5c3a;
	case 23619ULL: goto x86_l_5c43;
	case 23621ULL: goto x86_l_5c45;
	case 23626ULL: goto x86_l_5c4a;
	case 23631ULL: goto x86_l_5c4f;
	case 23636ULL: goto x86_l_5c54;
	case 23641ULL: goto x86_l_5c59;
	case 23646ULL: goto x86_l_5c5e;
	case 23648ULL: goto x86_l_5c60;
	case 23650ULL: goto x86_l_5c62;
	case 23656ULL: goto x86_l_5c68;
	case 23665ULL: goto x86_l_5c71;
	case 23671ULL: goto x86_l_5c77;
	case 23678ULL: goto x86_l_5c7e;
	case 23683ULL: goto x86_l_5c83;
	case 23688ULL: goto x86_l_5c88;
	case 23697ULL: goto x86_l_5c91;
	case 23699ULL: goto x86_l_5c93;
	case 23704ULL: goto x86_l_5c98;
	case 23709ULL: goto x86_l_5c9d;
	case 23714ULL: goto x86_l_5ca2;
	case 23719ULL: goto x86_l_5ca7;
	case 23724ULL: goto x86_l_5cac;
	case 23726ULL: goto x86_l_5cae;
	case 23728ULL: goto x86_l_5cb0;
	case 23734ULL: goto x86_l_5cb6;
	case 23743ULL: goto x86_l_5cbf;
	case 23749ULL: goto x86_l_5cc5;
	case 23756ULL: goto x86_l_5ccc;
	case 23761ULL: goto x86_l_5cd1;
	case 23766ULL: goto x86_l_5cd6;
	case 23775ULL: goto x86_l_5cdf;
	case 23777ULL: goto x86_l_5ce1;
	case 23782ULL: goto x86_l_5ce6;
	case 23787ULL: goto x86_l_5ceb;
	case 23792ULL: goto x86_l_5cf0;
	case 23797ULL: goto x86_l_5cf5;
	case 23802ULL: goto x86_l_5cfa;
	case 23804ULL: goto x86_l_5cfc;
	case 23806ULL: goto x86_l_5cfe;
	case 23812ULL: goto x86_l_5d04;
	case 23821ULL: goto x86_l_5d0d;
	case 23827ULL: goto x86_l_5d13;
	case 23834ULL: goto x86_l_5d1a;
	case 23839ULL: goto x86_l_5d1f;
	case 23844ULL: goto x86_l_5d24;
	case 23853ULL: goto x86_l_5d2d;
	case 23855ULL: goto x86_l_5d2f;
	case 23860ULL: goto x86_l_5d34;
	case 23865ULL: goto x86_l_5d39;
	case 23870ULL: goto x86_l_5d3e;
	case 23875ULL: goto x86_l_5d43;
	case 23880ULL: goto x86_l_5d48;
	case 23882ULL: goto x86_l_5d4a;
	case 23884ULL: goto x86_l_5d4c;
	case 23890ULL: goto x86_l_5d52;
	case 23895ULL: goto x86_l_5d57;
	case 23903ULL: goto x86_l_5d5f;
	case 23909ULL: goto x86_l_5d65;
	case 23915ULL: goto x86_l_5d6b;
	case 23920ULL: goto x86_l_5d70;
	case 23925ULL: goto x86_l_5d75;
	case 23933ULL: goto x86_l_5d7d;
	case 23935ULL: goto x86_l_5d7f;
	case 23940ULL: goto x86_l_5d84;
	case 23945ULL: goto x86_l_5d89;
	case 23950ULL: goto x86_l_5d8e;
	case 23955ULL: goto x86_l_5d93;
	case 23960ULL: goto x86_l_5d98;
	case 23962ULL: goto x86_l_5d9a;
	case 23964ULL: goto x86_l_5d9c;
	case 23970ULL: goto x86_l_5da2;
	case 23975ULL: goto x86_l_5da7;
	case 23983ULL: goto x86_l_5daf;
	case 23989ULL: goto x86_l_5db5;
	case 23995ULL: goto x86_l_5dbb;
	case 24000ULL: goto x86_l_5dc0;
	case 24005ULL: goto x86_l_5dc5;
	case 24013ULL: goto x86_l_5dcd;
	case 24019ULL: goto x86_l_5dd3;
	case 24024ULL: goto x86_l_5dd8;
	case 24029ULL: goto x86_l_5ddd;
	case 24034ULL: goto x86_l_5de2;
	case 24039ULL: goto x86_l_5de7;
	case 24042ULL: goto x86_l_5dea;
	case 24044ULL: goto x86_l_5dec;
	case 24049ULL: goto x86_l_5df1;
	case 24054ULL: goto x86_l_5df6;
	case 24059ULL: goto x86_l_5dfb;
	case 24064ULL: goto x86_l_5e00;
	case 24069ULL: goto x86_l_5e05;
	case 24071ULL: goto x86_l_5e07;
	case 24073ULL: goto x86_l_5e09;
	case 24079ULL: goto x86_l_5e0f;
	case 24088ULL: goto x86_l_5e18;
	case 24094ULL: goto x86_l_5e1e;
	case 24101ULL: goto x86_l_5e25;
	case 24106ULL: goto x86_l_5e2a;
	case 24111ULL: goto x86_l_5e2f;
	case 24120ULL: goto x86_l_5e38;
	case 24122ULL: goto x86_l_5e3a;
	case 24127ULL: goto x86_l_5e3f;
	case 24132ULL: goto x86_l_5e44;
	case 24137ULL: goto x86_l_5e49;
	case 24142ULL: goto x86_l_5e4e;
	case 24147ULL: goto x86_l_5e53;
	case 24149ULL: goto x86_l_5e55;
	case 24151ULL: goto x86_l_5e57;
	case 24157ULL: goto x86_l_5e5d;
	case 24166ULL: goto x86_l_5e66;
	case 24172ULL: goto x86_l_5e6c;
	case 24179ULL: goto x86_l_5e73;
	case 24184ULL: goto x86_l_5e78;
	case 24189ULL: goto x86_l_5e7d;
	case 24198ULL: goto x86_l_5e86;
	case 24200ULL: goto x86_l_5e88;
	case 24205ULL: goto x86_l_5e8d;
	case 24210ULL: goto x86_l_5e92;
	case 24215ULL: goto x86_l_5e97;
	case 24220ULL: goto x86_l_5e9c;
	case 24225ULL: goto x86_l_5ea1;
	case 24227ULL: goto x86_l_5ea3;
	case 24229ULL: goto x86_l_5ea5;
	case 24235ULL: goto x86_l_5eab;
	case 24244ULL: goto x86_l_5eb4;
	case 24250ULL: goto x86_l_5eba;
	case 24257ULL: goto x86_l_5ec1;
	case 24262ULL: goto x86_l_5ec6;
	case 24267ULL: goto x86_l_5ecb;
	case 24276ULL: goto x86_l_5ed4;
	case 24278ULL: goto x86_l_5ed6;
	case 24283ULL: goto x86_l_5edb;
	case 24288ULL: goto x86_l_5ee0;
	case 24293ULL: goto x86_l_5ee5;
	case 24298ULL: goto x86_l_5eea;
	case 24303ULL: goto x86_l_5eef;
	case 24305ULL: goto x86_l_5ef1;
	case 24307ULL: goto x86_l_5ef3;
	case 24313ULL: goto x86_l_5ef9;
	case 24322ULL: goto x86_l_5f02;
	case 24328ULL: goto x86_l_5f08;
	case 24335ULL: goto x86_l_5f0f;
	case 24340ULL: goto x86_l_5f14;
	case 24345ULL: goto x86_l_5f19;
	case 24354ULL: goto x86_l_5f22;
	case 24356ULL: goto x86_l_5f24;
	case 24361ULL: goto x86_l_5f29;
	case 24366ULL: goto x86_l_5f2e;
	case 24371ULL: goto x86_l_5f33;
	case 24376ULL: goto x86_l_5f38;
	case 24381ULL: goto x86_l_5f3d;
	case 24383ULL: goto x86_l_5f3f;
	case 24385ULL: goto x86_l_5f41;
	case 24391ULL: goto x86_l_5f47;
	case 24400ULL: goto x86_l_5f50;
	case 24406ULL: goto x86_l_5f56;
	case 24413ULL: goto x86_l_5f5d;
	case 24418ULL: goto x86_l_5f62;
	case 24423ULL: goto x86_l_5f67;
	case 24432ULL: goto x86_l_5f70;
	case 24434ULL: goto x86_l_5f72;
	case 24439ULL: goto x86_l_5f77;
	case 24444ULL: goto x86_l_5f7c;
	case 24449ULL: goto x86_l_5f81;
	case 24454ULL: goto x86_l_5f86;
	case 24459ULL: goto x86_l_5f8b;
	case 24461ULL: goto x86_l_5f8d;
	case 24463ULL: goto x86_l_5f8f;
	case 24469ULL: goto x86_l_5f95;
	case 24478ULL: goto x86_l_5f9e;
	case 24484ULL: goto x86_l_5fa4;
	case 24491ULL: goto x86_l_5fab;
	case 24496ULL: goto x86_l_5fb0;
	case 24501ULL: goto x86_l_5fb5;
	case 24510ULL: goto x86_l_5fbe;
	case 24512ULL: goto x86_l_5fc0;
	case 24517ULL: goto x86_l_5fc5;
	case 24522ULL: goto x86_l_5fca;
	case 24527ULL: goto x86_l_5fcf;
	case 24532ULL: goto x86_l_5fd4;
	case 24537ULL: goto x86_l_5fd9;
	case 24539ULL: goto x86_l_5fdb;
	case 24541ULL: goto x86_l_5fdd;
	case 24547ULL: goto x86_l_5fe3;
	case 24556ULL: goto x86_l_5fec;
	case 24562ULL: goto x86_l_5ff2;
	case 24569ULL: goto x86_l_5ff9;
	case 24574ULL: goto x86_l_5ffe;
	case 24579ULL: goto x86_l_6003;
	case 24588ULL: goto x86_l_600c;
	case 24590ULL: goto x86_l_600e;
	case 24595ULL: goto x86_l_6013;
	case 24600ULL: goto x86_l_6018;
	case 24605ULL: goto x86_l_601d;
	case 24610ULL: goto x86_l_6022;
	case 24615ULL: goto x86_l_6027;
	case 24617ULL: goto x86_l_6029;
	case 24619ULL: goto x86_l_602b;
	case 24625ULL: goto x86_l_6031;
	case 24630ULL: goto x86_l_6036;
	case 24638ULL: goto x86_l_603e;
	case 24644ULL: goto x86_l_6044;
	case 24650ULL: goto x86_l_604a;
	case 24655ULL: goto x86_l_604f;
	case 24660ULL: goto x86_l_6054;
	case 24668ULL: goto x86_l_605c;
	case 24670ULL: goto x86_l_605e;
	case 24675ULL: goto x86_l_6063;
	case 24680ULL: goto x86_l_6068;
	case 24685ULL: goto x86_l_606d;
	case 24690ULL: goto x86_l_6072;
	case 24695ULL: goto x86_l_6077;
	case 24697ULL: goto x86_l_6079;
	case 24699ULL: goto x86_l_607b;
	case 24705ULL: goto x86_l_6081;
	case 24710ULL: goto x86_l_6086;
	case 24718ULL: goto x86_l_608e;
	case 24724ULL: goto x86_l_6094;
	case 24730ULL: goto x86_l_609a;
	case 24735ULL: goto x86_l_609f;
	case 24740ULL: goto x86_l_60a4;
	case 24748ULL: goto x86_l_60ac;
	case 24754ULL: goto x86_l_60b2;
	case 24759ULL: goto x86_l_60b7;
	case 24764ULL: goto x86_l_60bc;
	case 24769ULL: goto x86_l_60c1;
	case 24774ULL: goto x86_l_60c6;
	case 24779ULL: goto x86_l_60cb;
	case 24781ULL: goto x86_l_60cd;
	case 24783ULL: goto x86_l_60cf;
	case 24789ULL: goto x86_l_60d5;
	case 24794ULL: goto x86_l_60da;
	case 24799ULL: goto x86_l_60df;
	case 24804ULL: goto x86_l_60e4;
	default: return 0xffffffffffffffffULL;
	}
x86_l_5940:
	/* 0x5940: js     626c <generic_sleepable_preload+0x626c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25196ULL;
	}
x86_l_5946:
	/* 0x5946: cmp    WORD PTR [r13+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_594f:
	/* 0x594f: je     6761 <generic_sleepable_preload+0x6761> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26465ULL;
	}
x86_l_5955:
	/* 0x5955: mov    ecx,DWORD PTR [r13+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_595c:
	/* 0x595c: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5961:
	/* 0x5961: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5966:
	/* 0x5966: cmp    WORD PTR [r13+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_596f:
	/* 0x596f: je     5994 <generic_sleepable_preload+0x5994> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5994;
	}
x86_l_5971:
	/* 0x5971: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5976:
	/* 0x5976: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_597b:
	/* 0x597b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5980:
	/* 0x5980: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5985:
	/* 0x5985: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_598a:
	/* 0x598a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_598c:
	/* 0x598c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_598e:
	/* 0x598e: js     675a <generic_sleepable_preload+0x675a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26458ULL;
	}
x86_l_5994:
	/* 0x5994: cmp    WORD PTR [r13+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_599d:
	/* 0x599d: je     6761 <generic_sleepable_preload+0x6761> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26465ULL;
	}
x86_l_59a3:
	/* 0x59a3: mov    ecx,DWORD PTR [r13+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_59aa:
	/* 0x59aa: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_59af:
	/* 0x59af: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_59b4:
	/* 0x59b4: cmp    WORD PTR [r13+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_59bd:
	/* 0x59bd: je     59e2 <generic_sleepable_preload+0x59e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_59e2;
	}
x86_l_59bf:
	/* 0x59bf: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_59c4:
	/* 0x59c4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_59c9:
	/* 0x59c9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_59ce:
	/* 0x59ce: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_59d3:
	/* 0x59d3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_59d8:
	/* 0x59d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_59da:
	/* 0x59da: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_59dc:
	/* 0x59dc: js     6a6a <generic_sleepable_preload+0x6a6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27242ULL;
	}
x86_l_59e2:
	/* 0x59e2: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_59e7:
	/* 0x59e7: cmp    WORD PTR [r13+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_59f0:
	/* 0x59f0: je     6761 <generic_sleepable_preload+0x6761> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26465ULL;
	}
x86_l_59f6:
	/* 0x59f6: mov    ecx,DWORD PTR [r13+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_59fd:
	/* 0x59fd: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5a02:
	/* 0x5a02: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a07:
	/* 0x5a07: cmp    WORD PTR [r13+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_5a10:
	/* 0x5a10: je     5a35 <generic_sleepable_preload+0x5a35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5a35;
	}
x86_l_5a12:
	/* 0x5a12: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a17:
	/* 0x5a17: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5a1c:
	/* 0x5a1c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5a21:
	/* 0x5a21: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a26:
	/* 0x5a26: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5a2b:
	/* 0x5a2b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a2d:
	/* 0x5a2d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5a2f:
	/* 0x5a2f: js     69b2 <generic_sleepable_preload+0x69b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27058ULL;
	}
x86_l_5a35:
	/* 0x5a35: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5a3a:
	/* 0x5a3a: cmp    WORD PTR [r13+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_5a43:
	/* 0x5a43: je     6761 <generic_sleepable_preload+0x6761> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26465ULL;
	}
x86_l_5a49:
	/* 0x5a49: mov    ecx,DWORD PTR [r13+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_5a50:
	/* 0x5a50: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5a55:
	/* 0x5a55: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a5a:
	/* 0x5a5a: cmp    WORD PTR [r13+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_5a63:
	/* 0x5a63: je     6761 <generic_sleepable_preload+0x6761> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26465ULL;
	}
x86_l_5a69:
	/* 0x5a69: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a6e:
	/* 0x5a6e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5a73:
	/* 0x5a73: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5a78:
	/* 0x5a78: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a7d:
	/* 0x5a7d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5a82:
	/* 0x5a82: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a84:
	/* 0x5a84: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5a86:
	/* 0x5a86: jns    6761 <generic_sleepable_preload+0x6761> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 26465ULL;
	}
x86_l_5a8c:
	/* 0x5a8c: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_5a91:
	/* 0x5a91: jmp    675f <generic_sleepable_preload+0x675f> */
	return 26463ULL;
x86_l_5a96:
	/* 0x5a96: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_5a9b:
	/* 0x5a9b: jmp    675f <generic_sleepable_preload+0x675f> */
	return 26463ULL;
x86_l_5aa0:
	/* 0x5aa0: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_5aa5:
	/* 0x5aa5: jmp    675f <generic_sleepable_preload+0x675f> */
	return 26463ULL;
x86_l_5aaa:
	/* 0x5aaa: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5aaf:
	/* 0x5aaf: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_5ab2:
	/* 0x5ab2: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_5ab4:
	/* 0x5ab4: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_5ab6:
	/* 0x5ab6: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_5abb:
	/* 0x5abb: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5abd:
	/* 0x5abd: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_5ac2:
	/* 0x5ac2: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ac7:
	/* 0x5ac7: mov    ebx,DWORD PTR [r13+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5acb:
	/* 0x5acb: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5acd:
	/* 0x5acd: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_5ad0:
	/* 0x5ad0: cmp    WORD PTR [r13+0x1b6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1881195675648ULL);
x86_l_5ad9:
	/* 0x5ad9: je     6812 <generic_sleepable_preload+0x6812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26642ULL;
	}
x86_l_5adf:
	/* 0x5adf: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_5ae6:
	/* 0x5ae6: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_5ae9:
	/* 0x5ae9: mov    eax,DWORD PTR [r13+0x1b0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 432ULL);
x86_l_5af0:
	/* 0x5af0: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5af3:
	/* 0x5af3: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5af8:
	/* 0x5af8: movzx  eax,WORD PTR [r13+0x1b4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 436ULL);
x86_l_5b00:
	/* 0x5b00: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_5b02:
	/* 0x5b02: je     5de7 <generic_sleepable_preload+0x5de7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5de7;
	}
x86_l_5b08:
	/* 0x5b08: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_5b0b:
	/* 0x5b0b: je     5b30 <generic_sleepable_preload+0x5b30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5b30;
	}
x86_l_5b0d:
	/* 0x5b0d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b12:
	/* 0x5b12: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5b17:
	/* 0x5b17: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5b1c:
	/* 0x5b1c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b21:
	/* 0x5b21: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5b26:
	/* 0x5b26: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b28:
	/* 0x5b28: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5b2a:
	/* 0x5b2a: js     60df <generic_sleepable_preload+0x60df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_60df;
	}
x86_l_5b30:
	/* 0x5b30: cmp    WORD PTR [r13+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_5b39:
	/* 0x5b39: je     6812 <generic_sleepable_preload+0x6812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26642ULL;
	}
x86_l_5b3f:
	/* 0x5b3f: mov    ecx,DWORD PTR [r13+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_5b46:
	/* 0x5b46: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5b4b:
	/* 0x5b4b: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b50:
	/* 0x5b50: cmp    WORD PTR [r13+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_5b59:
	/* 0x5b59: je     5b7e <generic_sleepable_preload+0x5b7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5b7e;
	}
x86_l_5b5b:
	/* 0x5b5b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b60:
	/* 0x5b60: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5b65:
	/* 0x5b65: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5b6a:
	/* 0x5b6a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b6f:
	/* 0x5b6f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5b74:
	/* 0x5b74: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b76:
	/* 0x5b76: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5b78:
	/* 0x5b78: js     60e9 <generic_sleepable_preload+0x60e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24809ULL;
	}
x86_l_5b7e:
	/* 0x5b7e: cmp    WORD PTR [r13+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_5b87:
	/* 0x5b87: je     6812 <generic_sleepable_preload+0x6812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26642ULL;
	}
x86_l_5b8d:
	/* 0x5b8d: mov    ecx,DWORD PTR [r13+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_5b94:
	/* 0x5b94: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5b99:
	/* 0x5b99: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b9e:
	/* 0x5b9e: cmp    WORD PTR [r13+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_5ba7:
	/* 0x5ba7: je     5bcc <generic_sleepable_preload+0x5bcc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5bcc;
	}
x86_l_5ba9:
	/* 0x5ba9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5bae:
	/* 0x5bae: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5bb3:
	/* 0x5bb3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5bb8:
	/* 0x5bb8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5bbd:
	/* 0x5bbd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5bc2:
	/* 0x5bc2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5bc4:
	/* 0x5bc4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5bc6:
	/* 0x5bc6: js     614d <generic_sleepable_preload+0x614d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24909ULL;
	}
x86_l_5bcc:
	/* 0x5bcc: cmp    WORD PTR [r13+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_5bd5:
	/* 0x5bd5: je     6812 <generic_sleepable_preload+0x6812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26642ULL;
	}
x86_l_5bdb:
	/* 0x5bdb: mov    ecx,DWORD PTR [r13+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_5be2:
	/* 0x5be2: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5be7:
	/* 0x5be7: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5bec:
	/* 0x5bec: cmp    WORD PTR [r13+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_5bf5:
	/* 0x5bf5: je     5c1a <generic_sleepable_preload+0x5c1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5c1a;
	}
x86_l_5bf7:
	/* 0x5bf7: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5bfc:
	/* 0x5bfc: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5c01:
	/* 0x5c01: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5c06:
	/* 0x5c06: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c0b:
	/* 0x5c0b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5c10:
	/* 0x5c10: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c12:
	/* 0x5c12: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5c14:
	/* 0x5c14: js     61b1 <generic_sleepable_preload+0x61b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25009ULL;
	}
x86_l_5c1a:
	/* 0x5c1a: cmp    WORD PTR [r13+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_5c23:
	/* 0x5c23: je     6812 <generic_sleepable_preload+0x6812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26642ULL;
	}
x86_l_5c29:
	/* 0x5c29: mov    ecx,DWORD PTR [r13+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_5c30:
	/* 0x5c30: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5c35:
	/* 0x5c35: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c3a:
	/* 0x5c3a: cmp    WORD PTR [r13+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_5c43:
	/* 0x5c43: je     5c68 <generic_sleepable_preload+0x5c68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5c68;
	}
x86_l_5c45:
	/* 0x5c45: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c4a:
	/* 0x5c4a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5c4f:
	/* 0x5c4f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5c54:
	/* 0x5c54: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c59:
	/* 0x5c59: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5c5e:
	/* 0x5c5e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c60:
	/* 0x5c60: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5c62:
	/* 0x5c62: js     6215 <generic_sleepable_preload+0x6215> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25109ULL;
	}
x86_l_5c68:
	/* 0x5c68: cmp    WORD PTR [r13+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_5c71:
	/* 0x5c71: je     6812 <generic_sleepable_preload+0x6812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26642ULL;
	}
x86_l_5c77:
	/* 0x5c77: mov    ecx,DWORD PTR [r13+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_5c7e:
	/* 0x5c7e: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5c83:
	/* 0x5c83: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c88:
	/* 0x5c88: cmp    WORD PTR [r13+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_5c91:
	/* 0x5c91: je     5cb6 <generic_sleepable_preload+0x5cb6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5cb6;
	}
x86_l_5c93:
	/* 0x5c93: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c98:
	/* 0x5c98: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5c9d:
	/* 0x5c9d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5ca2:
	/* 0x5ca2: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ca7:
	/* 0x5ca7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5cac:
	/* 0x5cac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5cae:
	/* 0x5cae: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5cb0:
	/* 0x5cb0: js     6276 <generic_sleepable_preload+0x6276> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25206ULL;
	}
x86_l_5cb6:
	/* 0x5cb6: cmp    WORD PTR [r13+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_5cbf:
	/* 0x5cbf: je     6812 <generic_sleepable_preload+0x6812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26642ULL;
	}
x86_l_5cc5:
	/* 0x5cc5: mov    ecx,DWORD PTR [r13+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_5ccc:
	/* 0x5ccc: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5cd1:
	/* 0x5cd1: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5cd6:
	/* 0x5cd6: cmp    WORD PTR [r13+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_5cdf:
	/* 0x5cdf: je     5d04 <generic_sleepable_preload+0x5d04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5d04;
	}
x86_l_5ce1:
	/* 0x5ce1: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ce6:
	/* 0x5ce6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5ceb:
	/* 0x5ceb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5cf0:
	/* 0x5cf0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5cf5:
	/* 0x5cf5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5cfa:
	/* 0x5cfa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5cfc:
	/* 0x5cfc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5cfe:
	/* 0x5cfe: js     680a <generic_sleepable_preload+0x680a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26634ULL;
	}
x86_l_5d04:
	/* 0x5d04: cmp    WORD PTR [r13+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_5d0d:
	/* 0x5d0d: je     6812 <generic_sleepable_preload+0x6812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26642ULL;
	}
x86_l_5d13:
	/* 0x5d13: mov    ecx,DWORD PTR [r13+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_5d1a:
	/* 0x5d1a: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5d1f:
	/* 0x5d1f: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d24:
	/* 0x5d24: cmp    WORD PTR [r13+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_5d2d:
	/* 0x5d2d: je     5d52 <generic_sleepable_preload+0x5d52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5d52;
	}
x86_l_5d2f:
	/* 0x5d2f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d34:
	/* 0x5d34: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5d39:
	/* 0x5d39: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5d3e:
	/* 0x5d3e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d43:
	/* 0x5d43: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5d48:
	/* 0x5d48: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d4a:
	/* 0x5d4a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5d4c:
	/* 0x5d4c: js     68ba <generic_sleepable_preload+0x68ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26810ULL;
	}
x86_l_5d52:
	/* 0x5d52: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5d57:
	/* 0x5d57: cmp    WORD PTR [rax+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_5d5f:
	/* 0x5d5f: je     6812 <generic_sleepable_preload+0x6812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26642ULL;
	}
x86_l_5d65:
	/* 0x5d65: mov    ecx,DWORD PTR [rax+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_5d6b:
	/* 0x5d6b: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5d70:
	/* 0x5d70: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d75:
	/* 0x5d75: cmp    WORD PTR [rax+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_5d7d:
	/* 0x5d7d: je     5da2 <generic_sleepable_preload+0x5da2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5da2;
	}
x86_l_5d7f:
	/* 0x5d7f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d84:
	/* 0x5d84: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5d89:
	/* 0x5d89: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5d8e:
	/* 0x5d8e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d93:
	/* 0x5d93: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5d98:
	/* 0x5d98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d9a:
	/* 0x5d9a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5d9c:
	/* 0x5d9c: js     69c3 <generic_sleepable_preload+0x69c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27075ULL;
	}
x86_l_5da2:
	/* 0x5da2: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5da7:
	/* 0x5da7: cmp    WORD PTR [rax+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_5daf:
	/* 0x5daf: je     6812 <generic_sleepable_preload+0x6812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26642ULL;
	}
x86_l_5db5:
	/* 0x5db5: mov    ecx,DWORD PTR [rax+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_5dbb:
	/* 0x5dbb: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5dc0:
	/* 0x5dc0: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5dc5:
	/* 0x5dc5: cmp    WORD PTR [rax+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_5dcd:
	/* 0x5dcd: je     6812 <generic_sleepable_preload+0x6812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26642ULL;
	}
x86_l_5dd3:
	/* 0x5dd3: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5dd8:
	/* 0x5dd8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5ddd:
	/* 0x5ddd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5de2:
	/* 0x5de2: jmp    60c1 <generic_sleepable_preload+0x60c1> */
	goto x86_l_60c1;
x86_l_5de7:
	/* 0x5de7: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_5dea:
	/* 0x5dea: je     5e0f <generic_sleepable_preload+0x5e0f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5e0f;
	}
x86_l_5dec:
	/* 0x5dec: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5df1:
	/* 0x5df1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5df6:
	/* 0x5df6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5dfb:
	/* 0x5dfb: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e00:
	/* 0x5e00: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5e05:
	/* 0x5e05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e07:
	/* 0x5e07: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5e09:
	/* 0x5e09: js     60df <generic_sleepable_preload+0x60df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_60df;
	}
x86_l_5e0f:
	/* 0x5e0f: cmp    WORD PTR [r13+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_5e18:
	/* 0x5e18: je     6812 <generic_sleepable_preload+0x6812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26642ULL;
	}
x86_l_5e1e:
	/* 0x5e1e: mov    ecx,DWORD PTR [r13+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_5e25:
	/* 0x5e25: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5e2a:
	/* 0x5e2a: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e2f:
	/* 0x5e2f: cmp    WORD PTR [r13+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_5e38:
	/* 0x5e38: je     5e5d <generic_sleepable_preload+0x5e5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5e5d;
	}
x86_l_5e3a:
	/* 0x5e3a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e3f:
	/* 0x5e3f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5e44:
	/* 0x5e44: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5e49:
	/* 0x5e49: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e4e:
	/* 0x5e4e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5e53:
	/* 0x5e53: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e55:
	/* 0x5e55: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5e57:
	/* 0x5e57: js     60e9 <generic_sleepable_preload+0x60e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24809ULL;
	}
x86_l_5e5d:
	/* 0x5e5d: cmp    WORD PTR [r13+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_5e66:
	/* 0x5e66: je     6812 <generic_sleepable_preload+0x6812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26642ULL;
	}
x86_l_5e6c:
	/* 0x5e6c: mov    ecx,DWORD PTR [r13+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_5e73:
	/* 0x5e73: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5e78:
	/* 0x5e78: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e7d:
	/* 0x5e7d: cmp    WORD PTR [r13+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_5e86:
	/* 0x5e86: je     5eab <generic_sleepable_preload+0x5eab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5eab;
	}
x86_l_5e88:
	/* 0x5e88: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e8d:
	/* 0x5e8d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5e92:
	/* 0x5e92: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5e97:
	/* 0x5e97: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e9c:
	/* 0x5e9c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5ea1:
	/* 0x5ea1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ea3:
	/* 0x5ea3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5ea5:
	/* 0x5ea5: js     614d <generic_sleepable_preload+0x614d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24909ULL;
	}
x86_l_5eab:
	/* 0x5eab: cmp    WORD PTR [r13+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_5eb4:
	/* 0x5eb4: je     6812 <generic_sleepable_preload+0x6812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26642ULL;
	}
x86_l_5eba:
	/* 0x5eba: mov    ecx,DWORD PTR [r13+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_5ec1:
	/* 0x5ec1: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5ec6:
	/* 0x5ec6: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ecb:
	/* 0x5ecb: cmp    WORD PTR [r13+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_5ed4:
	/* 0x5ed4: je     5ef9 <generic_sleepable_preload+0x5ef9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5ef9;
	}
x86_l_5ed6:
	/* 0x5ed6: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5edb:
	/* 0x5edb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5ee0:
	/* 0x5ee0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5ee5:
	/* 0x5ee5: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5eea:
	/* 0x5eea: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5eef:
	/* 0x5eef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ef1:
	/* 0x5ef1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5ef3:
	/* 0x5ef3: js     61b1 <generic_sleepable_preload+0x61b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25009ULL;
	}
x86_l_5ef9:
	/* 0x5ef9: cmp    WORD PTR [r13+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_5f02:
	/* 0x5f02: je     6812 <generic_sleepable_preload+0x6812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26642ULL;
	}
x86_l_5f08:
	/* 0x5f08: mov    ecx,DWORD PTR [r13+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_5f0f:
	/* 0x5f0f: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5f14:
	/* 0x5f14: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f19:
	/* 0x5f19: cmp    WORD PTR [r13+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_5f22:
	/* 0x5f22: je     5f47 <generic_sleepable_preload+0x5f47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5f47;
	}
x86_l_5f24:
	/* 0x5f24: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f29:
	/* 0x5f29: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5f2e:
	/* 0x5f2e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5f33:
	/* 0x5f33: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f38:
	/* 0x5f38: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5f3d:
	/* 0x5f3d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f3f:
	/* 0x5f3f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5f41:
	/* 0x5f41: js     6215 <generic_sleepable_preload+0x6215> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25109ULL;
	}
x86_l_5f47:
	/* 0x5f47: cmp    WORD PTR [r13+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_5f50:
	/* 0x5f50: je     6812 <generic_sleepable_preload+0x6812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26642ULL;
	}
x86_l_5f56:
	/* 0x5f56: mov    ecx,DWORD PTR [r13+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_5f5d:
	/* 0x5f5d: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5f62:
	/* 0x5f62: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f67:
	/* 0x5f67: cmp    WORD PTR [r13+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_5f70:
	/* 0x5f70: je     5f95 <generic_sleepable_preload+0x5f95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5f95;
	}
x86_l_5f72:
	/* 0x5f72: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f77:
	/* 0x5f77: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5f7c:
	/* 0x5f7c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5f81:
	/* 0x5f81: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f86:
	/* 0x5f86: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5f8b:
	/* 0x5f8b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f8d:
	/* 0x5f8d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5f8f:
	/* 0x5f8f: js     6276 <generic_sleepable_preload+0x6276> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25206ULL;
	}
x86_l_5f95:
	/* 0x5f95: cmp    WORD PTR [r13+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_5f9e:
	/* 0x5f9e: je     6812 <generic_sleepable_preload+0x6812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26642ULL;
	}
x86_l_5fa4:
	/* 0x5fa4: mov    ecx,DWORD PTR [r13+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_5fab:
	/* 0x5fab: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5fb0:
	/* 0x5fb0: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5fb5:
	/* 0x5fb5: cmp    WORD PTR [r13+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_5fbe:
	/* 0x5fbe: je     5fe3 <generic_sleepable_preload+0x5fe3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5fe3;
	}
x86_l_5fc0:
	/* 0x5fc0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5fc5:
	/* 0x5fc5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5fca:
	/* 0x5fca: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5fcf:
	/* 0x5fcf: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5fd4:
	/* 0x5fd4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5fd9:
	/* 0x5fd9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5fdb:
	/* 0x5fdb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5fdd:
	/* 0x5fdd: js     680a <generic_sleepable_preload+0x680a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26634ULL;
	}
x86_l_5fe3:
	/* 0x5fe3: cmp    WORD PTR [r13+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_5fec:
	/* 0x5fec: je     6812 <generic_sleepable_preload+0x6812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26642ULL;
	}
x86_l_5ff2:
	/* 0x5ff2: mov    ecx,DWORD PTR [r13+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_5ff9:
	/* 0x5ff9: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5ffe:
	/* 0x5ffe: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6003:
	/* 0x6003: cmp    WORD PTR [r13+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_600c:
	/* 0x600c: je     6031 <generic_sleepable_preload+0x6031> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6031;
	}
x86_l_600e:
	/* 0x600e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6013:
	/* 0x6013: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_6018:
	/* 0x6018: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_601d:
	/* 0x601d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6022:
	/* 0x6022: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6027:
	/* 0x6027: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6029:
	/* 0x6029: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_602b:
	/* 0x602b: js     68ba <generic_sleepable_preload+0x68ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26810ULL;
	}
x86_l_6031:
	/* 0x6031: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6036:
	/* 0x6036: cmp    WORD PTR [rax+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_603e:
	/* 0x603e: je     6812 <generic_sleepable_preload+0x6812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26642ULL;
	}
x86_l_6044:
	/* 0x6044: mov    ecx,DWORD PTR [rax+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_604a:
	/* 0x604a: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_604f:
	/* 0x604f: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6054:
	/* 0x6054: cmp    WORD PTR [rax+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_605c:
	/* 0x605c: je     6081 <generic_sleepable_preload+0x6081> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6081;
	}
x86_l_605e:
	/* 0x605e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6063:
	/* 0x6063: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_6068:
	/* 0x6068: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_606d:
	/* 0x606d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6072:
	/* 0x6072: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6077:
	/* 0x6077: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6079:
	/* 0x6079: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_607b:
	/* 0x607b: js     69c3 <generic_sleepable_preload+0x69c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27075ULL;
	}
x86_l_6081:
	/* 0x6081: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6086:
	/* 0x6086: cmp    WORD PTR [rax+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_608e:
	/* 0x608e: je     6812 <generic_sleepable_preload+0x6812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26642ULL;
	}
x86_l_6094:
	/* 0x6094: mov    ecx,DWORD PTR [rax+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_609a:
	/* 0x609a: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_609f:
	/* 0x609f: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_60a4:
	/* 0x60a4: cmp    WORD PTR [rax+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_60ac:
	/* 0x60ac: je     6812 <generic_sleepable_preload+0x6812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26642ULL;
	}
x86_l_60b2:
	/* 0x60b2: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_60b7:
	/* 0x60b7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_60bc:
	/* 0x60bc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_60c1:
	/* 0x60c1: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_60c6:
	/* 0x60c6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_60cb:
	/* 0x60cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_60cd:
	/* 0x60cd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_60cf:
	/* 0x60cf: jns    6812 <generic_sleepable_preload+0x6812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 26642ULL;
	}
x86_l_60d5:
	/* 0x60d5: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_60da:
	/* 0x60da: jmp    680f <generic_sleepable_preload+0x680f> */
	return 26639ULL;
x86_l_60df:
	/* 0x60df: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_60e4:
	/* 0x60e4: jmp    680f <generic_sleepable_preload+0x680f> */
	return 26639ULL;
	return 24809ULL;
}

static __noinline __u64 tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_13(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 24809ULL: goto x86_l_60e9;
	case 24814ULL: goto x86_l_60ee;
	case 24819ULL: goto x86_l_60f3;
	case 24824ULL: goto x86_l_60f8;
	case 24829ULL: goto x86_l_60fd;
	case 24834ULL: goto x86_l_6102;
	case 24839ULL: goto x86_l_6107;
	case 24844ULL: goto x86_l_610c;
	case 24849ULL: goto x86_l_6111;
	case 24854ULL: goto x86_l_6116;
	case 24859ULL: goto x86_l_611b;
	case 24864ULL: goto x86_l_6120;
	case 24869ULL: goto x86_l_6125;
	case 24874ULL: goto x86_l_612a;
	case 24879ULL: goto x86_l_612f;
	case 24884ULL: goto x86_l_6134;
	case 24889ULL: goto x86_l_6139;
	case 24894ULL: goto x86_l_613e;
	case 24899ULL: goto x86_l_6143;
	case 24904ULL: goto x86_l_6148;
	case 24909ULL: goto x86_l_614d;
	case 24914ULL: goto x86_l_6152;
	case 24919ULL: goto x86_l_6157;
	case 24924ULL: goto x86_l_615c;
	case 24929ULL: goto x86_l_6161;
	case 24934ULL: goto x86_l_6166;
	case 24939ULL: goto x86_l_616b;
	case 24944ULL: goto x86_l_6170;
	case 24949ULL: goto x86_l_6175;
	case 24954ULL: goto x86_l_617a;
	case 24959ULL: goto x86_l_617f;
	case 24964ULL: goto x86_l_6184;
	case 24969ULL: goto x86_l_6189;
	case 24974ULL: goto x86_l_618e;
	case 24979ULL: goto x86_l_6193;
	case 24984ULL: goto x86_l_6198;
	case 24989ULL: goto x86_l_619d;
	case 24994ULL: goto x86_l_61a2;
	case 24999ULL: goto x86_l_61a7;
	case 25004ULL: goto x86_l_61ac;
	case 25009ULL: goto x86_l_61b1;
	case 25014ULL: goto x86_l_61b6;
	case 25019ULL: goto x86_l_61bb;
	case 25024ULL: goto x86_l_61c0;
	case 25029ULL: goto x86_l_61c5;
	case 25034ULL: goto x86_l_61ca;
	case 25039ULL: goto x86_l_61cf;
	case 25044ULL: goto x86_l_61d4;
	case 25049ULL: goto x86_l_61d9;
	case 25054ULL: goto x86_l_61de;
	case 25059ULL: goto x86_l_61e3;
	case 25064ULL: goto x86_l_61e8;
	case 25069ULL: goto x86_l_61ed;
	case 25074ULL: goto x86_l_61f2;
	case 25079ULL: goto x86_l_61f7;
	case 25084ULL: goto x86_l_61fc;
	case 25089ULL: goto x86_l_6201;
	case 25094ULL: goto x86_l_6206;
	case 25099ULL: goto x86_l_620b;
	case 25104ULL: goto x86_l_6210;
	case 25109ULL: goto x86_l_6215;
	case 25114ULL: goto x86_l_621a;
	case 25119ULL: goto x86_l_621f;
	case 25124ULL: goto x86_l_6224;
	case 25126ULL: goto x86_l_6226;
	case 25131ULL: goto x86_l_622b;
	case 25136ULL: goto x86_l_6230;
	case 25141ULL: goto x86_l_6235;
	case 25146ULL: goto x86_l_623a;
	case 25151ULL: goto x86_l_623f;
	case 25156ULL: goto x86_l_6244;
	case 25161ULL: goto x86_l_6249;
	case 25166ULL: goto x86_l_624e;
	case 25171ULL: goto x86_l_6253;
	case 25176ULL: goto x86_l_6258;
	case 25181ULL: goto x86_l_625d;
	case 25186ULL: goto x86_l_6262;
	case 25191ULL: goto x86_l_6267;
	case 25196ULL: goto x86_l_626c;
	case 25201ULL: goto x86_l_6271;
	case 25206ULL: goto x86_l_6276;
	case 25211ULL: goto x86_l_627b;
	case 25216ULL: goto x86_l_6280;
	case 25221ULL: goto x86_l_6285;
	case 25223ULL: goto x86_l_6287;
	case 25227ULL: goto x86_l_628b;
	case 25232ULL: goto x86_l_6290;
	case 25237ULL: goto x86_l_6295;
	case 25242ULL: goto x86_l_629a;
	case 25247ULL: goto x86_l_629f;
	case 25250ULL: goto x86_l_62a2;
	case 25252ULL: goto x86_l_62a4;
	case 25256ULL: goto x86_l_62a8;
	case 25262ULL: goto x86_l_62ae;
	case 25267ULL: goto x86_l_62b3;
	case 25272ULL: goto x86_l_62b8;
	case 25274ULL: goto x86_l_62ba;
	case 25279ULL: goto x86_l_62bf;
	case 25287ULL: goto x86_l_62c7;
	case 25294ULL: goto x86_l_62ce;
	case 25299ULL: goto x86_l_62d3;
	case 25304ULL: goto x86_l_62d8;
	case 25306ULL: goto x86_l_62da;
	case 25309ULL: goto x86_l_62dd;
	case 25315ULL: goto x86_l_62e3;
	case 25318ULL: goto x86_l_62e6;
	case 25325ULL: goto x86_l_62ed;
	case 25327ULL: goto x86_l_62ef;
	case 25332ULL: goto x86_l_62f4;
	case 25337ULL: goto x86_l_62f9;
	case 25340ULL: goto x86_l_62fc;
	case 25343ULL: goto x86_l_62ff;
	case 25345ULL: goto x86_l_6301;
	case 25347ULL: goto x86_l_6303;
	case 25352ULL: goto x86_l_6308;
	case 25357ULL: goto x86_l_630d;
	case 25362ULL: goto x86_l_6312;
	case 25364ULL: goto x86_l_6314;
	case 25368ULL: goto x86_l_6318;
	case 25373ULL: goto x86_l_631d;
	case 25378ULL: goto x86_l_6322;
	case 25383ULL: goto x86_l_6327;
	case 25388ULL: goto x86_l_632c;
	case 25391ULL: goto x86_l_632f;
	case 25393ULL: goto x86_l_6331;
	case 25397ULL: goto x86_l_6335;
	case 25403ULL: goto x86_l_633b;
	case 25408ULL: goto x86_l_6340;
	case 25413ULL: goto x86_l_6345;
	case 25415ULL: goto x86_l_6347;
	case 25420ULL: goto x86_l_634c;
	case 25428ULL: goto x86_l_6354;
	case 25435ULL: goto x86_l_635b;
	case 25440ULL: goto x86_l_6360;
	case 25445ULL: goto x86_l_6365;
	case 25447ULL: goto x86_l_6367;
	case 25450ULL: goto x86_l_636a;
	case 25456ULL: goto x86_l_6370;
	case 25459ULL: goto x86_l_6373;
	case 25466ULL: goto x86_l_637a;
	case 25468ULL: goto x86_l_637c;
	case 25473ULL: goto x86_l_6381;
	case 25478ULL: goto x86_l_6386;
	case 25481ULL: goto x86_l_6389;
	case 25484ULL: goto x86_l_638c;
	case 25486ULL: goto x86_l_638e;
	case 25488ULL: goto x86_l_6390;
	case 25493ULL: goto x86_l_6395;
	case 25498ULL: goto x86_l_639a;
	case 25503ULL: goto x86_l_639f;
	case 25505ULL: goto x86_l_63a1;
	case 25509ULL: goto x86_l_63a5;
	case 25514ULL: goto x86_l_63aa;
	case 25519ULL: goto x86_l_63af;
	case 25524ULL: goto x86_l_63b4;
	case 25529ULL: goto x86_l_63b9;
	case 25532ULL: goto x86_l_63bc;
	case 25534ULL: goto x86_l_63be;
	case 25538ULL: goto x86_l_63c2;
	case 25544ULL: goto x86_l_63c8;
	case 25549ULL: goto x86_l_63cd;
	case 25554ULL: goto x86_l_63d2;
	case 25556ULL: goto x86_l_63d4;
	case 25561ULL: goto x86_l_63d9;
	case 25569ULL: goto x86_l_63e1;
	case 25576ULL: goto x86_l_63e8;
	case 25581ULL: goto x86_l_63ed;
	case 25586ULL: goto x86_l_63f2;
	case 25588ULL: goto x86_l_63f4;
	case 25591ULL: goto x86_l_63f7;
	case 25597ULL: goto x86_l_63fd;
	case 25600ULL: goto x86_l_6400;
	case 25607ULL: goto x86_l_6407;
	case 25609ULL: goto x86_l_6409;
	case 25614ULL: goto x86_l_640e;
	case 25619ULL: goto x86_l_6413;
	case 25622ULL: goto x86_l_6416;
	case 25625ULL: goto x86_l_6419;
	case 25627ULL: goto x86_l_641b;
	case 25629ULL: goto x86_l_641d;
	case 25634ULL: goto x86_l_6422;
	case 25639ULL: goto x86_l_6427;
	case 25644ULL: goto x86_l_642c;
	case 25646ULL: goto x86_l_642e;
	case 25650ULL: goto x86_l_6432;
	case 25655ULL: goto x86_l_6437;
	case 25660ULL: goto x86_l_643c;
	case 25665ULL: goto x86_l_6441;
	case 25670ULL: goto x86_l_6446;
	case 25673ULL: goto x86_l_6449;
	case 25675ULL: goto x86_l_644b;
	case 25679ULL: goto x86_l_644f;
	case 25685ULL: goto x86_l_6455;
	case 25690ULL: goto x86_l_645a;
	case 25695ULL: goto x86_l_645f;
	case 25697ULL: goto x86_l_6461;
	case 25702ULL: goto x86_l_6466;
	case 25710ULL: goto x86_l_646e;
	case 25717ULL: goto x86_l_6475;
	case 25722ULL: goto x86_l_647a;
	case 25727ULL: goto x86_l_647f;
	case 25729ULL: goto x86_l_6481;
	case 25732ULL: goto x86_l_6484;
	case 25738ULL: goto x86_l_648a;
	case 25741ULL: goto x86_l_648d;
	case 25748ULL: goto x86_l_6494;
	case 25750ULL: goto x86_l_6496;
	case 25755ULL: goto x86_l_649b;
	case 25760ULL: goto x86_l_64a0;
	case 25763ULL: goto x86_l_64a3;
	case 25766ULL: goto x86_l_64a6;
	case 25768ULL: goto x86_l_64a8;
	case 25770ULL: goto x86_l_64aa;
	case 25775ULL: goto x86_l_64af;
	case 25780ULL: goto x86_l_64b4;
	case 25785ULL: goto x86_l_64b9;
	case 25788ULL: goto x86_l_64bc;
	case 25792ULL: goto x86_l_64c0;
	case 25797ULL: goto x86_l_64c5;
	case 25802ULL: goto x86_l_64ca;
	case 25807ULL: goto x86_l_64cf;
	case 25812ULL: goto x86_l_64d4;
	case 25815ULL: goto x86_l_64d7;
	case 25817ULL: goto x86_l_64d9;
	case 25820ULL: goto x86_l_64dc;
	case 25826ULL: goto x86_l_64e2;
	case 25831ULL: goto x86_l_64e7;
	case 25836ULL: goto x86_l_64ec;
	case 25838ULL: goto x86_l_64ee;
	case 25843ULL: goto x86_l_64f3;
	case 25851ULL: goto x86_l_64fb;
	case 25858ULL: goto x86_l_6502;
	case 25863ULL: goto x86_l_6507;
	case 25868ULL: goto x86_l_650c;
	case 25870ULL: goto x86_l_650e;
	case 25873ULL: goto x86_l_6511;
	case 25879ULL: goto x86_l_6517;
	case 25882ULL: goto x86_l_651a;
	case 25889ULL: goto x86_l_6521;
	case 25891ULL: goto x86_l_6523;
	case 25896ULL: goto x86_l_6528;
	case 25901ULL: goto x86_l_652d;
	case 25904ULL: goto x86_l_6530;
	case 25907ULL: goto x86_l_6533;
	case 25909ULL: goto x86_l_6535;
	case 25911ULL: goto x86_l_6537;
	case 25916ULL: goto x86_l_653c;
	case 25921ULL: goto x86_l_6541;
	case 25926ULL: goto x86_l_6546;
	case 25928ULL: goto x86_l_6548;
	case 25932ULL: goto x86_l_654c;
	case 25938ULL: goto x86_l_6552;
	case 25943ULL: goto x86_l_6557;
	case 25948ULL: goto x86_l_655c;
	case 25950ULL: goto x86_l_655e;
	case 25955ULL: goto x86_l_6563;
	case 25963ULL: goto x86_l_656b;
	case 25970ULL: goto x86_l_6572;
	case 25975ULL: goto x86_l_6577;
	case 25980ULL: goto x86_l_657c;
	case 25982ULL: goto x86_l_657e;
	case 25985ULL: goto x86_l_6581;
	case 25991ULL: goto x86_l_6587;
	case 25994ULL: goto x86_l_658a;
	case 26001ULL: goto x86_l_6591;
	case 26003ULL: goto x86_l_6593;
	case 26008ULL: goto x86_l_6598;
	case 26013ULL: goto x86_l_659d;
	case 26016ULL: goto x86_l_65a0;
	case 26019ULL: goto x86_l_65a3;
	case 26021ULL: goto x86_l_65a5;
	case 26023ULL: goto x86_l_65a7;
	case 26028ULL: goto x86_l_65ac;
	case 26031ULL: goto x86_l_65af;
	case 26036ULL: goto x86_l_65b4;
	case 26039ULL: goto x86_l_65b7;
	case 26041ULL: goto x86_l_65b9;
	case 26044ULL: goto x86_l_65bc;
	case 26050ULL: goto x86_l_65c2;
	case 26053ULL: goto x86_l_65c5;
	case 26055ULL: goto x86_l_65c7;
	case 26058ULL: goto x86_l_65ca;
	case 26062ULL: goto x86_l_65ce;
	case 26067ULL: goto x86_l_65d3;
	case 26070ULL: goto x86_l_65d6;
	case 26072ULL: goto x86_l_65d8;
	case 26075ULL: goto x86_l_65db;
	case 26080ULL: goto x86_l_65e0;
	case 26082ULL: goto x86_l_65e2;
	case 26085ULL: goto x86_l_65e5;
	case 26087ULL: goto x86_l_65e7;
	case 26089ULL: goto x86_l_65e9;
	case 26094ULL: goto x86_l_65ee;
	case 26096ULL: goto x86_l_65f0;
	case 26101ULL: goto x86_l_65f5;
	case 26106ULL: goto x86_l_65fa;
	case 26108ULL: goto x86_l_65fc;
	case 26112ULL: goto x86_l_6600;
	case 26118ULL: goto x86_l_6606;
	case 26123ULL: goto x86_l_660b;
	case 26128ULL: goto x86_l_6610;
	case 26130ULL: goto x86_l_6612;
	case 26135ULL: goto x86_l_6617;
	case 26143ULL: goto x86_l_661f;
	case 26150ULL: goto x86_l_6626;
	case 26155ULL: goto x86_l_662b;
	case 26160ULL: goto x86_l_6630;
	case 26162ULL: goto x86_l_6632;
	case 26165ULL: goto x86_l_6635;
	case 26171ULL: goto x86_l_663b;
	case 26174ULL: goto x86_l_663e;
	case 26181ULL: goto x86_l_6645;
	case 26183ULL: goto x86_l_6647;
	case 26188ULL: goto x86_l_664c;
	case 26193ULL: goto x86_l_6651;
	case 26196ULL: goto x86_l_6654;
	case 26199ULL: goto x86_l_6657;
	case 26201ULL: goto x86_l_6659;
	case 26203ULL: goto x86_l_665b;
	case 26208ULL: goto x86_l_6660;
	case 26211ULL: goto x86_l_6663;
	case 26216ULL: goto x86_l_6668;
	case 26219ULL: goto x86_l_666b;
	case 26221ULL: goto x86_l_666d;
	case 26224ULL: goto x86_l_6670;
	case 26230ULL: goto x86_l_6676;
	case 26233ULL: goto x86_l_6679;
	case 26235ULL: goto x86_l_667b;
	case 26238ULL: goto x86_l_667e;
	case 26242ULL: goto x86_l_6682;
	case 26247ULL: goto x86_l_6687;
	case 26250ULL: goto x86_l_668a;
	case 26252ULL: goto x86_l_668c;
	case 26255ULL: goto x86_l_668f;
	case 26260ULL: goto x86_l_6694;
	case 26262ULL: goto x86_l_6696;
	case 26265ULL: goto x86_l_6699;
	case 26267ULL: goto x86_l_669b;
	case 26272ULL: goto x86_l_66a0;
	case 26275ULL: goto x86_l_66a3;
	case 26277ULL: goto x86_l_66a5;
	case 26282ULL: goto x86_l_66aa;
	case 26287ULL: goto x86_l_66af;
	case 26289ULL: goto x86_l_66b1;
	case 26293ULL: goto x86_l_66b5;
	case 26299ULL: goto x86_l_66bb;
	case 26304ULL: goto x86_l_66c0;
	case 26309ULL: goto x86_l_66c5;
	case 26311ULL: goto x86_l_66c7;
	case 26316ULL: goto x86_l_66cc;
	case 26324ULL: goto x86_l_66d4;
	case 26331ULL: goto x86_l_66db;
	case 26336ULL: goto x86_l_66e0;
	case 26341ULL: goto x86_l_66e5;
	case 26343ULL: goto x86_l_66e7;
	case 26346ULL: goto x86_l_66ea;
	case 26352ULL: goto x86_l_66f0;
	case 26355ULL: goto x86_l_66f3;
	case 26362ULL: goto x86_l_66fa;
	case 26364ULL: goto x86_l_66fc;
	case 26369ULL: goto x86_l_6701;
	case 26374ULL: goto x86_l_6706;
	case 26377ULL: goto x86_l_6709;
	case 26380ULL: goto x86_l_670c;
	case 26382ULL: goto x86_l_670e;
	case 26384ULL: goto x86_l_6710;
	case 26389ULL: goto x86_l_6715;
	case 26392ULL: goto x86_l_6718;
	case 26395ULL: goto x86_l_671b;
	case 26397ULL: goto x86_l_671d;
	case 26400ULL: goto x86_l_6720;
	case 26406ULL: goto x86_l_6726;
	case 26409ULL: goto x86_l_6729;
	case 26411ULL: goto x86_l_672b;
	case 26414ULL: goto x86_l_672e;
	case 26418ULL: goto x86_l_6732;
	case 26423ULL: goto x86_l_6737;
	case 26426ULL: goto x86_l_673a;
	case 26428ULL: goto x86_l_673c;
	case 26431ULL: goto x86_l_673f;
	case 26436ULL: goto x86_l_6744;
	case 26438ULL: goto x86_l_6746;
	case 26441ULL: goto x86_l_6749;
	case 26443ULL: goto x86_l_674b;
	default: return 0xffffffffffffffffULL;
	}
x86_l_60e9:
	/* 0x60e9: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_60ee:
	/* 0x60ee: jmp    680f <generic_sleepable_preload+0x680f> */
	return 26639ULL;
x86_l_60f3:
	/* 0x60f3: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_60f8:
	/* 0x60f8: jmp    6285 <generic_sleepable_preload+0x6285> */
	goto x86_l_6285;
x86_l_60fd:
	/* 0x60fd: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_6102:
	/* 0x6102: jmp    6312 <generic_sleepable_preload+0x6312> */
	goto x86_l_6312;
x86_l_6107:
	/* 0x6107: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_610c:
	/* 0x610c: jmp    639f <generic_sleepable_preload+0x639f> */
	goto x86_l_639f;
x86_l_6111:
	/* 0x6111: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_6116:
	/* 0x6116: jmp    642c <generic_sleepable_preload+0x642c> */
	goto x86_l_642c;
x86_l_611b:
	/* 0x611b: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_6120:
	/* 0x6120: jmp    64b9 <generic_sleepable_preload+0x64b9> */
	goto x86_l_64b9;
x86_l_6125:
	/* 0x6125: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_612a:
	/* 0x612a: jmp    6546 <generic_sleepable_preload+0x6546> */
	goto x86_l_6546;
x86_l_612f:
	/* 0x612f: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_6134:
	/* 0x6134: jmp    65fa <generic_sleepable_preload+0x65fa> */
	goto x86_l_65fa;
x86_l_6139:
	/* 0x6139: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_613e:
	/* 0x613e: jmp    66af <generic_sleepable_preload+0x66af> */
	goto x86_l_66af;
x86_l_6143:
	/* 0x6143: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_6148:
	/* 0x6148: jmp    675f <generic_sleepable_preload+0x675f> */
	return 26463ULL;
x86_l_614d:
	/* 0x614d: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_6152:
	/* 0x6152: jmp    680f <generic_sleepable_preload+0x680f> */
	return 26639ULL;
x86_l_6157:
	/* 0x6157: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_615c:
	/* 0x615c: jmp    6285 <generic_sleepable_preload+0x6285> */
	goto x86_l_6285;
x86_l_6161:
	/* 0x6161: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_6166:
	/* 0x6166: jmp    6312 <generic_sleepable_preload+0x6312> */
	goto x86_l_6312;
x86_l_616b:
	/* 0x616b: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_6170:
	/* 0x6170: jmp    639f <generic_sleepable_preload+0x639f> */
	goto x86_l_639f;
x86_l_6175:
	/* 0x6175: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_617a:
	/* 0x617a: jmp    642c <generic_sleepable_preload+0x642c> */
	goto x86_l_642c;
x86_l_617f:
	/* 0x617f: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_6184:
	/* 0x6184: jmp    64b9 <generic_sleepable_preload+0x64b9> */
	goto x86_l_64b9;
x86_l_6189:
	/* 0x6189: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_618e:
	/* 0x618e: jmp    6546 <generic_sleepable_preload+0x6546> */
	goto x86_l_6546;
x86_l_6193:
	/* 0x6193: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_6198:
	/* 0x6198: jmp    65fa <generic_sleepable_preload+0x65fa> */
	goto x86_l_65fa;
x86_l_619d:
	/* 0x619d: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_61a2:
	/* 0x61a2: jmp    66af <generic_sleepable_preload+0x66af> */
	goto x86_l_66af;
x86_l_61a7:
	/* 0x61a7: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_61ac:
	/* 0x61ac: jmp    675f <generic_sleepable_preload+0x675f> */
	return 26463ULL;
x86_l_61b1:
	/* 0x61b1: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_61b6:
	/* 0x61b6: jmp    680f <generic_sleepable_preload+0x680f> */
	return 26639ULL;
x86_l_61bb:
	/* 0x61bb: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_61c0:
	/* 0x61c0: jmp    6285 <generic_sleepable_preload+0x6285> */
	goto x86_l_6285;
x86_l_61c5:
	/* 0x61c5: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_61ca:
	/* 0x61ca: jmp    6312 <generic_sleepable_preload+0x6312> */
	goto x86_l_6312;
x86_l_61cf:
	/* 0x61cf: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_61d4:
	/* 0x61d4: jmp    639f <generic_sleepable_preload+0x639f> */
	goto x86_l_639f;
x86_l_61d9:
	/* 0x61d9: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_61de:
	/* 0x61de: jmp    642c <generic_sleepable_preload+0x642c> */
	goto x86_l_642c;
x86_l_61e3:
	/* 0x61e3: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_61e8:
	/* 0x61e8: jmp    64b9 <generic_sleepable_preload+0x64b9> */
	goto x86_l_64b9;
x86_l_61ed:
	/* 0x61ed: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_61f2:
	/* 0x61f2: jmp    6546 <generic_sleepable_preload+0x6546> */
	goto x86_l_6546;
x86_l_61f7:
	/* 0x61f7: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_61fc:
	/* 0x61fc: jmp    65fa <generic_sleepable_preload+0x65fa> */
	goto x86_l_65fa;
x86_l_6201:
	/* 0x6201: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_6206:
	/* 0x6206: jmp    66af <generic_sleepable_preload+0x66af> */
	goto x86_l_66af;
x86_l_620b:
	/* 0x620b: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_6210:
	/* 0x6210: jmp    675f <generic_sleepable_preload+0x675f> */
	return 26463ULL;
x86_l_6215:
	/* 0x6215: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_621a:
	/* 0x621a: jmp    680f <generic_sleepable_preload+0x680f> */
	return 26639ULL;
x86_l_621f:
	/* 0x621f: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_6224:
	/* 0x6224: jmp    6285 <generic_sleepable_preload+0x6285> */
	goto x86_l_6285;
x86_l_6226:
	/* 0x6226: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_622b:
	/* 0x622b: jmp    6312 <generic_sleepable_preload+0x6312> */
	goto x86_l_6312;
x86_l_6230:
	/* 0x6230: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_6235:
	/* 0x6235: jmp    639f <generic_sleepable_preload+0x639f> */
	goto x86_l_639f;
x86_l_623a:
	/* 0x623a: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_623f:
	/* 0x623f: jmp    642c <generic_sleepable_preload+0x642c> */
	goto x86_l_642c;
x86_l_6244:
	/* 0x6244: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_6249:
	/* 0x6249: jmp    64b9 <generic_sleepable_preload+0x64b9> */
	goto x86_l_64b9;
x86_l_624e:
	/* 0x624e: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_6253:
	/* 0x6253: jmp    6546 <generic_sleepable_preload+0x6546> */
	goto x86_l_6546;
x86_l_6258:
	/* 0x6258: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_625d:
	/* 0x625d: jmp    65fa <generic_sleepable_preload+0x65fa> */
	goto x86_l_65fa;
x86_l_6262:
	/* 0x6262: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_6267:
	/* 0x6267: jmp    66af <generic_sleepable_preload+0x66af> */
	goto x86_l_66af;
x86_l_626c:
	/* 0x626c: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_6271:
	/* 0x6271: jmp    675f <generic_sleepable_preload+0x675f> */
	return 26463ULL;
x86_l_6276:
	/* 0x6276: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_627b:
	/* 0x627b: jmp    680f <generic_sleepable_preload+0x680f> */
	return 26639ULL;
x86_l_6280:
	/* 0x6280: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_6285:
	/* 0x6285: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6287:
	/* 0x6287: mov    r14d,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_628b:
	/* 0x628b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6290:
	/* 0x6290: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6295:
	/* 0x6295: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_629a:
	/* 0x629a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_629f:
	/* 0x629f: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_62a2:
	/* 0x62a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_62a4:
	/* 0x62a4: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_62a8:
	/* 0x62a8: jne    11bc <generic_sleepable_preload+0x11bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4540ULL;
	}
x86_l_62ae:
	/* 0x62ae: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_62b3:
	/* 0x62b3: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_62b8:
	/* 0x62b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_62ba:
	/* 0x62ba: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_62bf:
	/* 0x62bf: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_62c7:
	/* 0x62c7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_62ce:
	/* 0x62ce: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_62d3:
	/* 0x62d3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_62d8:
	/* 0x62d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_62da:
	/* 0x62da: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_62dd:
	/* 0x62dd: je     11bc <generic_sleepable_preload+0x11bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4540ULL;
	}
x86_l_62e3:
	/* 0x62e3: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_62e6:
	/* 0x62e6: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_62ed:
	/* 0x62ed: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_62ef:
	/* 0x62ef: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_62f4:
	/* 0x62f4: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_62f9:
	/* 0x62f9: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_62fc:
	/* 0x62fc: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_62ff:
	/* 0x62ff: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6301:
	/* 0x6301: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6303:
	/* 0x6303: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6308:
	/* 0x6308: jmp    65ac <generic_sleepable_preload+0x65ac> */
	goto x86_l_65ac;
x86_l_630d:
	/* 0x630d: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_6312:
	/* 0x6312: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6314:
	/* 0x6314: mov    r14d,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6318:
	/* 0x6318: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_631d:
	/* 0x631d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6322:
	/* 0x6322: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6327:
	/* 0x6327: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_632c:
	/* 0x632c: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_632f:
	/* 0x632f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6331:
	/* 0x6331: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_6335:
	/* 0x6335: jne    11cb <generic_sleepable_preload+0x11cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4555ULL;
	}
x86_l_633b:
	/* 0x633b: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6340:
	/* 0x6340: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_6345:
	/* 0x6345: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6347:
	/* 0x6347: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_634c:
	/* 0x634c: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_6354:
	/* 0x6354: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_635b:
	/* 0x635b: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6360:
	/* 0x6360: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6365:
	/* 0x6365: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6367:
	/* 0x6367: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_636a:
	/* 0x636a: je     11cb <generic_sleepable_preload+0x11cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4555ULL;
	}
x86_l_6370:
	/* 0x6370: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_6373:
	/* 0x6373: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_637a:
	/* 0x637a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_637c:
	/* 0x637c: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6381:
	/* 0x6381: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6386:
	/* 0x6386: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_6389:
	/* 0x6389: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_638c:
	/* 0x638c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_638e:
	/* 0x638e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6390:
	/* 0x6390: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6395:
	/* 0x6395: jmp    67c5 <generic_sleepable_preload+0x67c5> */
	return 26565ULL;
x86_l_639a:
	/* 0x639a: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_639f:
	/* 0x639f: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_63a1:
	/* 0x63a1: mov    r14d,DWORD PTR [r13+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_63a5:
	/* 0x63a5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_63aa:
	/* 0x63aa: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_63af:
	/* 0x63af: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_63b4:
	/* 0x63b4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_63b9:
	/* 0x63b9: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_63bc:
	/* 0x63bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_63be:
	/* 0x63be: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_63c2:
	/* 0x63c2: jne    11df <generic_sleepable_preload+0x11df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4575ULL;
	}
x86_l_63c8:
	/* 0x63c8: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_63cd:
	/* 0x63cd: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_63d2:
	/* 0x63d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_63d4:
	/* 0x63d4: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_63d9:
	/* 0x63d9: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_63e1:
	/* 0x63e1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_63e8:
	/* 0x63e8: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_63ed:
	/* 0x63ed: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_63f2:
	/* 0x63f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_63f4:
	/* 0x63f4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_63f7:
	/* 0x63f7: je     11df <generic_sleepable_preload+0x11df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4575ULL;
	}
x86_l_63fd:
	/* 0x63fd: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_6400:
	/* 0x6400: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_6407:
	/* 0x6407: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6409:
	/* 0x6409: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_640e:
	/* 0x640e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6413:
	/* 0x6413: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_6416:
	/* 0x6416: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_6419:
	/* 0x6419: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_641b:
	/* 0x641b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_641d:
	/* 0x641d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6422:
	/* 0x6422: jmp    6660 <generic_sleepable_preload+0x6660> */
	goto x86_l_6660;
x86_l_6427:
	/* 0x6427: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_642c:
	/* 0x642c: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_642e:
	/* 0x642e: mov    r14d,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6432:
	/* 0x6432: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6437:
	/* 0x6437: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_643c:
	/* 0x643c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6441:
	/* 0x6441: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6446:
	/* 0x6446: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_6449:
	/* 0x6449: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_644b:
	/* 0x644b: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_644f:
	/* 0x644f: jne    11ee <generic_sleepable_preload+0x11ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4590ULL;
	}
x86_l_6455:
	/* 0x6455: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_645a:
	/* 0x645a: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_645f:
	/* 0x645f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6461:
	/* 0x6461: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6466:
	/* 0x6466: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_646e:
	/* 0x646e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_6475:
	/* 0x6475: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_647a:
	/* 0x647a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_647f:
	/* 0x647f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6481:
	/* 0x6481: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6484:
	/* 0x6484: je     11ee <generic_sleepable_preload+0x11ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4590ULL;
	}
x86_l_648a:
	/* 0x648a: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_648d:
	/* 0x648d: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_6494:
	/* 0x6494: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6496:
	/* 0x6496: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_649b:
	/* 0x649b: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_64a0:
	/* 0x64a0: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_64a3:
	/* 0x64a3: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_64a6:
	/* 0x64a6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_64a8:
	/* 0x64a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_64aa:
	/* 0x64aa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_64af:
	/* 0x64af: jmp    6715 <generic_sleepable_preload+0x6715> */
	goto x86_l_6715;
x86_l_64b4:
	/* 0x64b4: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_64b9:
	/* 0x64b9: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_64bc:
	/* 0x64bc: mov    ebx,DWORD PTR [r13+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_64c0:
	/* 0x64c0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_64c5:
	/* 0x64c5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_64ca:
	/* 0x64ca: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_64cf:
	/* 0x64cf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_64d4:
	/* 0x64d4: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_64d7:
	/* 0x64d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_64d9:
	/* 0x64d9: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_64dc:
	/* 0x64dc: jne    11fd <generic_sleepable_preload+0x11fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4605ULL;
	}
x86_l_64e2:
	/* 0x64e2: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_64e7:
	/* 0x64e7: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_64ec:
	/* 0x64ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_64ee:
	/* 0x64ee: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_64f3:
	/* 0x64f3: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_64fb:
	/* 0x64fb: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_6502:
	/* 0x6502: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6507:
	/* 0x6507: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_650c:
	/* 0x650c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_650e:
	/* 0x650e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6511:
	/* 0x6511: je     11fd <generic_sleepable_preload+0x11fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4605ULL;
	}
x86_l_6517:
	/* 0x6517: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_651a:
	/* 0x651a: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_6521:
	/* 0x6521: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6523:
	/* 0x6523: lea    r15,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6528:
	/* 0x6528: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_652d:
	/* 0x652d: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_6530:
	/* 0x6530: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_6533:
	/* 0x6533: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6535:
	/* 0x6535: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6537:
	/* 0x6537: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_653c:
	/* 0x653c: jmp    6875 <generic_sleepable_preload+0x6875> */
	return 26741ULL;
x86_l_6541:
	/* 0x6541: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_6546:
	/* 0x6546: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6548:
	/* 0x6548: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_654c:
	/* 0x654c: jne    11bc <generic_sleepable_preload+0x11bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4540ULL;
	}
x86_l_6552:
	/* 0x6552: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6557:
	/* 0x6557: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_655c:
	/* 0x655c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_655e:
	/* 0x655e: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6563:
	/* 0x6563: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_656b:
	/* 0x656b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_6572:
	/* 0x6572: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6577:
	/* 0x6577: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_657c:
	/* 0x657c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_657e:
	/* 0x657e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6581:
	/* 0x6581: je     11bc <generic_sleepable_preload+0x11bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4540ULL;
	}
x86_l_6587:
	/* 0x6587: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_658a:
	/* 0x658a: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_6591:
	/* 0x6591: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6593:
	/* 0x6593: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6598:
	/* 0x6598: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_659d:
	/* 0x659d: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_65a0:
	/* 0x65a0: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_65a3:
	/* 0x65a3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_65a5:
	/* 0x65a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_65a7:
	/* 0x65a7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_65ac:
	/* 0x65ac: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_65af:
	/* 0x65af: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_65b4:
	/* 0x65b4: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_65b7:
	/* 0x65b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_65b9:
	/* 0x65b9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_65bc:
	/* 0x65bc: je     11bc <generic_sleepable_preload+0x11bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4540ULL;
	}
x86_l_65c2:
	/* 0x65c2: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_65c5:
	/* 0x65c5: je     65ee <generic_sleepable_preload+0x65ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_65ee;
	}
x86_l_65c7:
	/* 0x65c7: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_65ca:
	/* 0x65ca: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_65ce:
	/* 0x65ce: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_65d3:
	/* 0x65d3: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_65d6:
	/* 0x65d6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_65d8:
	/* 0x65d8: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_65db:
	/* 0x65db: call   65e0 <generic_sleepable_preload+0x65e0> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_65e0:
	/* 0x65e0: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_65e2:
	/* 0x65e2: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_65e5:
	/* 0x65e5: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_65e7:
	/* 0x65e7: jns    65ee <generic_sleepable_preload+0x65ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_65ee;
	}
x86_l_65e9:
	/* 0x65e9: mov    ebx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4294967295ULL);
x86_l_65ee:
	/* 0x65ee: mov    DWORD PTR [rax],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_65f0:
	/* 0x65f0: jmp    11bc <generic_sleepable_preload+0x11bc> */
	return 4540ULL;
x86_l_65f5:
	/* 0x65f5: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_65fa:
	/* 0x65fa: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_65fc:
	/* 0x65fc: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_6600:
	/* 0x6600: jne    11df <generic_sleepable_preload+0x11df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4575ULL;
	}
x86_l_6606:
	/* 0x6606: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_660b:
	/* 0x660b: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_6610:
	/* 0x6610: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6612:
	/* 0x6612: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6617:
	/* 0x6617: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_661f:
	/* 0x661f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_6626:
	/* 0x6626: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_662b:
	/* 0x662b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6630:
	/* 0x6630: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6632:
	/* 0x6632: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6635:
	/* 0x6635: je     11df <generic_sleepable_preload+0x11df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4575ULL;
	}
x86_l_663b:
	/* 0x663b: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_663e:
	/* 0x663e: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_6645:
	/* 0x6645: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6647:
	/* 0x6647: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_664c:
	/* 0x664c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6651:
	/* 0x6651: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_6654:
	/* 0x6654: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_6657:
	/* 0x6657: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6659:
	/* 0x6659: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_665b:
	/* 0x665b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6660:
	/* 0x6660: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_6663:
	/* 0x6663: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_6668:
	/* 0x6668: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_666b:
	/* 0x666b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_666d:
	/* 0x666d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6670:
	/* 0x6670: je     11df <generic_sleepable_preload+0x11df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4575ULL;
	}
x86_l_6676:
	/* 0x6676: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_6679:
	/* 0x6679: je     66a3 <generic_sleepable_preload+0x66a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_66a3;
	}
x86_l_667b:
	/* 0x667b: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_667e:
	/* 0x667e: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_6682:
	/* 0x6682: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_6687:
	/* 0x6687: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_668a:
	/* 0x668a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_668c:
	/* 0x668c: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_668f:
	/* 0x668f: call   6694 <generic_sleepable_preload+0x6694> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_6694:
	/* 0x6694: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_6696:
	/* 0x6696: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_6699:
	/* 0x6699: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_669b:
	/* 0x669b: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_66a0:
	/* 0x66a0: cmovs  ebx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_66a3:
	/* 0x66a3: mov    DWORD PTR [rax],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_66a5:
	/* 0x66a5: jmp    11df <generic_sleepable_preload+0x11df> */
	return 4575ULL;
x86_l_66aa:
	/* 0x66aa: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_66af:
	/* 0x66af: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_66b1:
	/* 0x66b1: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_66b5:
	/* 0x66b5: jne    11ee <generic_sleepable_preload+0x11ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4590ULL;
	}
x86_l_66bb:
	/* 0x66bb: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_66c0:
	/* 0x66c0: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_66c5:
	/* 0x66c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_66c7:
	/* 0x66c7: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_66cc:
	/* 0x66cc: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_66d4:
	/* 0x66d4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_66db:
	/* 0x66db: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_66e0:
	/* 0x66e0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_66e5:
	/* 0x66e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_66e7:
	/* 0x66e7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_66ea:
	/* 0x66ea: je     11ee <generic_sleepable_preload+0x11ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4590ULL;
	}
x86_l_66f0:
	/* 0x66f0: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_66f3:
	/* 0x66f3: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_66fa:
	/* 0x66fa: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_66fc:
	/* 0x66fc: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6701:
	/* 0x6701: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6706:
	/* 0x6706: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_6709:
	/* 0x6709: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_670c:
	/* 0x670c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_670e:
	/* 0x670e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6710:
	/* 0x6710: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6715:
	/* 0x6715: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_6718:
	/* 0x6718: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_671b:
	/* 0x671b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_671d:
	/* 0x671d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6720:
	/* 0x6720: je     11ee <generic_sleepable_preload+0x11ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4590ULL;
	}
x86_l_6726:
	/* 0x6726: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_6729:
	/* 0x6729: je     6753 <generic_sleepable_preload+0x6753> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26451ULL;
	}
x86_l_672b:
	/* 0x672b: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_672e:
	/* 0x672e: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_6732:
	/* 0x6732: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_6737:
	/* 0x6737: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_673a:
	/* 0x673a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_673c:
	/* 0x673c: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_673f:
	/* 0x673f: call   6744 <generic_sleepable_preload+0x6744> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_6744:
	/* 0x6744: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_6746:
	/* 0x6746: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_6749:
	/* 0x6749: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_674b:
	/* 0x674b: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
	return 26448ULL;
}

static __noinline __u64 tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_14(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 26448ULL: goto x86_l_6750;
	case 26451ULL: goto x86_l_6753;
	case 26453ULL: goto x86_l_6755;
	case 26458ULL: goto x86_l_675a;
	case 26463ULL: goto x86_l_675f;
	case 26465ULL: goto x86_l_6761;
	case 26469ULL: goto x86_l_6765;
	case 26475ULL: goto x86_l_676b;
	case 26480ULL: goto x86_l_6770;
	case 26485ULL: goto x86_l_6775;
	case 26487ULL: goto x86_l_6777;
	case 26492ULL: goto x86_l_677c;
	case 26500ULL: goto x86_l_6784;
	case 26507ULL: goto x86_l_678b;
	case 26512ULL: goto x86_l_6790;
	case 26517ULL: goto x86_l_6795;
	case 26519ULL: goto x86_l_6797;
	case 26522ULL: goto x86_l_679a;
	case 26528ULL: goto x86_l_67a0;
	case 26531ULL: goto x86_l_67a3;
	case 26538ULL: goto x86_l_67aa;
	case 26540ULL: goto x86_l_67ac;
	case 26545ULL: goto x86_l_67b1;
	case 26550ULL: goto x86_l_67b6;
	case 26553ULL: goto x86_l_67b9;
	case 26556ULL: goto x86_l_67bc;
	case 26558ULL: goto x86_l_67be;
	case 26560ULL: goto x86_l_67c0;
	case 26565ULL: goto x86_l_67c5;
	case 26568ULL: goto x86_l_67c8;
	case 26571ULL: goto x86_l_67cb;
	case 26573ULL: goto x86_l_67cd;
	case 26576ULL: goto x86_l_67d0;
	case 26582ULL: goto x86_l_67d6;
	case 26585ULL: goto x86_l_67d9;
	case 26587ULL: goto x86_l_67db;
	case 26590ULL: goto x86_l_67de;
	case 26594ULL: goto x86_l_67e2;
	case 26599ULL: goto x86_l_67e7;
	case 26602ULL: goto x86_l_67ea;
	case 26604ULL: goto x86_l_67ec;
	case 26607ULL: goto x86_l_67ef;
	case 26612ULL: goto x86_l_67f4;
	case 26614ULL: goto x86_l_67f6;
	case 26617ULL: goto x86_l_67f9;
	case 26619ULL: goto x86_l_67fb;
	case 26624ULL: goto x86_l_6800;
	case 26627ULL: goto x86_l_6803;
	case 26629ULL: goto x86_l_6805;
	case 26634ULL: goto x86_l_680a;
	case 26639ULL: goto x86_l_680f;
	case 26642ULL: goto x86_l_6812;
	case 26645ULL: goto x86_l_6815;
	case 26651ULL: goto x86_l_681b;
	case 26656ULL: goto x86_l_6820;
	case 26661ULL: goto x86_l_6825;
	case 26663ULL: goto x86_l_6827;
	case 26668ULL: goto x86_l_682c;
	case 26676ULL: goto x86_l_6834;
	case 26683ULL: goto x86_l_683b;
	case 26688ULL: goto x86_l_6840;
	case 26693ULL: goto x86_l_6845;
	case 26695ULL: goto x86_l_6847;
	case 26698ULL: goto x86_l_684a;
	case 26704ULL: goto x86_l_6850;
	case 26707ULL: goto x86_l_6853;
	case 26714ULL: goto x86_l_685a;
	case 26716ULL: goto x86_l_685c;
	case 26721ULL: goto x86_l_6861;
	case 26726ULL: goto x86_l_6866;
	case 26729ULL: goto x86_l_6869;
	case 26732ULL: goto x86_l_686c;
	case 26734ULL: goto x86_l_686e;
	case 26736ULL: goto x86_l_6870;
	case 26741ULL: goto x86_l_6875;
	case 26744ULL: goto x86_l_6878;
	case 26747ULL: goto x86_l_687b;
	case 26749ULL: goto x86_l_687d;
	case 26752ULL: goto x86_l_6880;
	case 26758ULL: goto x86_l_6886;
	case 26761ULL: goto x86_l_6889;
	case 26763ULL: goto x86_l_688b;
	case 26766ULL: goto x86_l_688e;
	case 26770ULL: goto x86_l_6892;
	case 26775ULL: goto x86_l_6897;
	case 26778ULL: goto x86_l_689a;
	case 26780ULL: goto x86_l_689c;
	case 26783ULL: goto x86_l_689f;
	case 26788ULL: goto x86_l_68a4;
	case 26790ULL: goto x86_l_68a6;
	case 26793ULL: goto x86_l_68a9;
	case 26795ULL: goto x86_l_68ab;
	case 26800ULL: goto x86_l_68b0;
	case 26803ULL: goto x86_l_68b3;
	case 26805ULL: goto x86_l_68b5;
	case 26810ULL: goto x86_l_68ba;
	case 26813ULL: goto x86_l_68bd;
	case 26818ULL: goto x86_l_68c2;
	case 26821ULL: goto x86_l_68c5;
	case 26827ULL: goto x86_l_68cb;
	case 26832ULL: goto x86_l_68d0;
	case 26834ULL: goto x86_l_68d2;
	case 26839ULL: goto x86_l_68d7;
	case 26844ULL: goto x86_l_68dc;
	case 26846ULL: goto x86_l_68de;
	case 26851ULL: goto x86_l_68e3;
	case 26856ULL: goto x86_l_68e8;
	case 26858ULL: goto x86_l_68ea;
	case 26863ULL: goto x86_l_68ef;
	case 26868ULL: goto x86_l_68f4;
	case 26870ULL: goto x86_l_68f6;
	case 26875ULL: goto x86_l_68fb;
	case 26880ULL: goto x86_l_6900;
	case 26883ULL: goto x86_l_6903;
	case 26888ULL: goto x86_l_6908;
	case 26893ULL: goto x86_l_690d;
	case 26895ULL: goto x86_l_690f;
	case 26900ULL: goto x86_l_6914;
	case 26905ULL: goto x86_l_6919;
	case 26907ULL: goto x86_l_691b;
	case 26912ULL: goto x86_l_6920;
	case 26917ULL: goto x86_l_6925;
	case 26919ULL: goto x86_l_6927;
	case 26924ULL: goto x86_l_692c;
	case 26929ULL: goto x86_l_6931;
	case 26931ULL: goto x86_l_6933;
	case 26936ULL: goto x86_l_6938;
	case 26941ULL: goto x86_l_693d;
	case 26946ULL: goto x86_l_6942;
	case 26948ULL: goto x86_l_6944;
	case 26953ULL: goto x86_l_6949;
	case 26958ULL: goto x86_l_694e;
	case 26960ULL: goto x86_l_6950;
	case 26965ULL: goto x86_l_6955;
	case 26970ULL: goto x86_l_695a;
	case 26975ULL: goto x86_l_695f;
	case 26977ULL: goto x86_l_6961;
	case 26982ULL: goto x86_l_6966;
	case 26987ULL: goto x86_l_696b;
	case 26989ULL: goto x86_l_696d;
	case 26994ULL: goto x86_l_6972;
	case 26999ULL: goto x86_l_6977;
	case 27004ULL: goto x86_l_697c;
	case 27007ULL: goto x86_l_697f;
	case 27012ULL: goto x86_l_6984;
	case 27017ULL: goto x86_l_6989;
	case 27022ULL: goto x86_l_698e;
	case 27024ULL: goto x86_l_6990;
	case 27029ULL: goto x86_l_6995;
	case 27034ULL: goto x86_l_699a;
	case 27036ULL: goto x86_l_699c;
	case 27041ULL: goto x86_l_69a1;
	case 27046ULL: goto x86_l_69a6;
	case 27048ULL: goto x86_l_69a8;
	case 27053ULL: goto x86_l_69ad;
	case 27058ULL: goto x86_l_69b2;
	case 27063ULL: goto x86_l_69b7;
	case 27065ULL: goto x86_l_69b9;
	case 27070ULL: goto x86_l_69be;
	case 27075ULL: goto x86_l_69c3;
	case 27080ULL: goto x86_l_69c8;
	case 27085ULL: goto x86_l_69cd;
	case 27087ULL: goto x86_l_69cf;
	case 27092ULL: goto x86_l_69d4;
	case 27097ULL: goto x86_l_69d9;
	case 27102ULL: goto x86_l_69de;
	case 27107ULL: goto x86_l_69e3;
	case 27109ULL: goto x86_l_69e5;
	case 27114ULL: goto x86_l_69ea;
	case 27119ULL: goto x86_l_69ef;
	case 27124ULL: goto x86_l_69f4;
	case 27126ULL: goto x86_l_69f6;
	case 27131ULL: goto x86_l_69fb;
	case 27136ULL: goto x86_l_6a00;
	case 27141ULL: goto x86_l_6a05;
	case 27146ULL: goto x86_l_6a0a;
	case 27148ULL: goto x86_l_6a0c;
	case 27153ULL: goto x86_l_6a11;
	case 27158ULL: goto x86_l_6a16;
	case 27163ULL: goto x86_l_6a1b;
	case 27166ULL: goto x86_l_6a1e;
	case 27171ULL: goto x86_l_6a23;
	case 27176ULL: goto x86_l_6a28;
	case 27181ULL: goto x86_l_6a2d;
	case 27183ULL: goto x86_l_6a2f;
	case 27188ULL: goto x86_l_6a34;
	case 27193ULL: goto x86_l_6a39;
	case 27198ULL: goto x86_l_6a3e;
	case 27203ULL: goto x86_l_6a43;
	case 27205ULL: goto x86_l_6a45;
	case 27210ULL: goto x86_l_6a4a;
	case 27215ULL: goto x86_l_6a4f;
	case 27220ULL: goto x86_l_6a54;
	case 27225ULL: goto x86_l_6a59;
	case 27227ULL: goto x86_l_6a5b;
	case 27232ULL: goto x86_l_6a60;
	case 27237ULL: goto x86_l_6a65;
	case 27242ULL: goto x86_l_6a6a;
	case 27244ULL: goto x86_l_6a6c;
	case 27249ULL: goto x86_l_6a71;
	case 27254ULL: goto x86_l_6a76;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6750:
	/* 0x6750: cmovs  ebx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_6753:
	/* 0x6753: mov    DWORD PTR [rax],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6755:
	/* 0x6755: jmp    11ee <generic_sleepable_preload+0x11ee> */
	return 4590ULL;
x86_l_675a:
	/* 0x675a: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_675f:
	/* 0x675f: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6761:
	/* 0x6761: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_6765:
	/* 0x6765: jne    11cb <generic_sleepable_preload+0x11cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4555ULL;
	}
x86_l_676b:
	/* 0x676b: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6770:
	/* 0x6770: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_6775:
	/* 0x6775: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6777:
	/* 0x6777: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_677c:
	/* 0x677c: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_6784:
	/* 0x6784: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_678b:
	/* 0x678b: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6790:
	/* 0x6790: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6795:
	/* 0x6795: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6797:
	/* 0x6797: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_679a:
	/* 0x679a: je     11cb <generic_sleepable_preload+0x11cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4555ULL;
	}
x86_l_67a0:
	/* 0x67a0: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_67a3:
	/* 0x67a3: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_67aa:
	/* 0x67aa: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_67ac:
	/* 0x67ac: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_67b1:
	/* 0x67b1: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_67b6:
	/* 0x67b6: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_67b9:
	/* 0x67b9: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_67bc:
	/* 0x67bc: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_67be:
	/* 0x67be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_67c0:
	/* 0x67c0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_67c5:
	/* 0x67c5: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_67c8:
	/* 0x67c8: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_67cb:
	/* 0x67cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_67cd:
	/* 0x67cd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_67d0:
	/* 0x67d0: je     11cb <generic_sleepable_preload+0x11cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4555ULL;
	}
x86_l_67d6:
	/* 0x67d6: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_67d9:
	/* 0x67d9: je     6803 <generic_sleepable_preload+0x6803> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6803;
	}
x86_l_67db:
	/* 0x67db: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_67de:
	/* 0x67de: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_67e2:
	/* 0x67e2: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_67e7:
	/* 0x67e7: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_67ea:
	/* 0x67ea: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_67ec:
	/* 0x67ec: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_67ef:
	/* 0x67ef: call   67f4 <generic_sleepable_preload+0x67f4> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_67f4:
	/* 0x67f4: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_67f6:
	/* 0x67f6: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_67f9:
	/* 0x67f9: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_67fb:
	/* 0x67fb: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_6800:
	/* 0x6800: cmovs  ebx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_6803:
	/* 0x6803: mov    DWORD PTR [rax],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6805:
	/* 0x6805: jmp    11cb <generic_sleepable_preload+0x11cb> */
	return 4555ULL;
x86_l_680a:
	/* 0x680a: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_680f:
	/* 0x680f: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6812:
	/* 0x6812: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_6815:
	/* 0x6815: jne    11fd <generic_sleepable_preload+0x11fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4605ULL;
	}
x86_l_681b:
	/* 0x681b: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6820:
	/* 0x6820: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_6825:
	/* 0x6825: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6827:
	/* 0x6827: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_682c:
	/* 0x682c: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_6834:
	/* 0x6834: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_683b:
	/* 0x683b: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6840:
	/* 0x6840: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6845:
	/* 0x6845: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6847:
	/* 0x6847: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_684a:
	/* 0x684a: je     11fd <generic_sleepable_preload+0x11fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4605ULL;
	}
x86_l_6850:
	/* 0x6850: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_6853:
	/* 0x6853: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_685a:
	/* 0x685a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_685c:
	/* 0x685c: lea    r15,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6861:
	/* 0x6861: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6866:
	/* 0x6866: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_6869:
	/* 0x6869: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_686c:
	/* 0x686c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_686e:
	/* 0x686e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6870:
	/* 0x6870: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6875:
	/* 0x6875: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_6878:
	/* 0x6878: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_687b:
	/* 0x687b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_687d:
	/* 0x687d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6880:
	/* 0x6880: je     11fd <generic_sleepable_preload+0x11fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4605ULL;
	}
x86_l_6886:
	/* 0x6886: test   r12b,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8);
x86_l_6889:
	/* 0x6889: je     68b3 <generic_sleepable_preload+0x68b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_68b3;
	}
x86_l_688b:
	/* 0x688b: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_688e:
	/* 0x688e: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_6892:
	/* 0x6892: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_6897:
	/* 0x6897: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_689a:
	/* 0x689a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_689c:
	/* 0x689c: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_689f:
	/* 0x689f: call   68a4 <generic_sleepable_preload+0x68a4> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_68a4:
	/* 0x68a4: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_68a6:
	/* 0x68a6: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_68a9:
	/* 0x68a9: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_68ab:
	/* 0x68ab: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_68b0:
	/* 0x68b0: cmovs  ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_68b3:
	/* 0x68b3: mov    DWORD PTR [rax],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_68b5:
	/* 0x68b5: jmp    11fd <generic_sleepable_preload+0x11fd> */
	return 4605ULL;
x86_l_68ba:
	/* 0x68ba: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_68bd:
	/* 0x68bd: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_68c2:
	/* 0x68c2: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_68c5:
	/* 0x68c5: jne    11fd <generic_sleepable_preload+0x11fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4605ULL;
	}
x86_l_68cb:
	/* 0x68cb: jmp    681b <generic_sleepable_preload+0x681b> */
	goto x86_l_681b;
x86_l_68d0:
	/* 0x68d0: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_68d2:
	/* 0x68d2: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_68d7:
	/* 0x68d7: jmp    6287 <generic_sleepable_preload+0x6287> */
	return 25223ULL;
x86_l_68dc:
	/* 0x68dc: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_68de:
	/* 0x68de: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_68e3:
	/* 0x68e3: jmp    6314 <generic_sleepable_preload+0x6314> */
	return 25364ULL;
x86_l_68e8:
	/* 0x68e8: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_68ea:
	/* 0x68ea: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_68ef:
	/* 0x68ef: jmp    63a1 <generic_sleepable_preload+0x63a1> */
	return 25505ULL;
x86_l_68f4:
	/* 0x68f4: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_68f6:
	/* 0x68f6: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_68fb:
	/* 0x68fb: jmp    642e <generic_sleepable_preload+0x642e> */
	return 25646ULL;
x86_l_6900:
	/* 0x6900: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6903:
	/* 0x6903: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_6908:
	/* 0x6908: jmp    64bc <generic_sleepable_preload+0x64bc> */
	return 25788ULL;
x86_l_690d:
	/* 0x690d: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_690f:
	/* 0x690f: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_6914:
	/* 0x6914: jmp    6548 <generic_sleepable_preload+0x6548> */
	return 25928ULL;
x86_l_6919:
	/* 0x6919: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_691b:
	/* 0x691b: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_6920:
	/* 0x6920: jmp    65fc <generic_sleepable_preload+0x65fc> */
	return 26108ULL;
x86_l_6925:
	/* 0x6925: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6927:
	/* 0x6927: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_692c:
	/* 0x692c: jmp    66b1 <generic_sleepable_preload+0x66b1> */
	return 26289ULL;
x86_l_6931:
	/* 0x6931: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6933:
	/* 0x6933: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_6938:
	/* 0x6938: jmp    6761 <generic_sleepable_preload+0x6761> */
	goto x86_l_6761;
x86_l_693d:
	/* 0x693d: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_6942:
	/* 0x6942: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6944:
	/* 0x6944: jmp    69d4 <generic_sleepable_preload+0x69d4> */
	goto x86_l_69d4;
x86_l_6949:
	/* 0x6949: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_694e:
	/* 0x694e: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6950:
	/* 0x6950: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6955:
	/* 0x6955: jmp    6314 <generic_sleepable_preload+0x6314> */
	return 25364ULL;
x86_l_695a:
	/* 0x695a: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_695f:
	/* 0x695f: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6961:
	/* 0x6961: jmp    69fb <generic_sleepable_preload+0x69fb> */
	goto x86_l_69fb;
x86_l_6966:
	/* 0x6966: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_696b:
	/* 0x696b: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_696d:
	/* 0x696d: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6972:
	/* 0x6972: jmp    642e <generic_sleepable_preload+0x642e> */
	return 25646ULL;
x86_l_6977:
	/* 0x6977: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_697c:
	/* 0x697c: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_697f:
	/* 0x697f: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6984:
	/* 0x6984: jmp    64bc <generic_sleepable_preload+0x64bc> */
	return 25788ULL;
x86_l_6989:
	/* 0x6989: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_698e:
	/* 0x698e: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6990:
	/* 0x6990: jmp    6a34 <generic_sleepable_preload+0x6a34> */
	goto x86_l_6a34;
x86_l_6995:
	/* 0x6995: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_699a:
	/* 0x699a: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_699c:
	/* 0x699c: jmp    6a4a <generic_sleepable_preload+0x6a4a> */
	goto x86_l_6a4a;
x86_l_69a1:
	/* 0x69a1: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_69a6:
	/* 0x69a6: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_69a8:
	/* 0x69a8: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_69ad:
	/* 0x69ad: jmp    66b1 <generic_sleepable_preload+0x66b1> */
	return 26289ULL;
x86_l_69b2:
	/* 0x69b2: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_69b7:
	/* 0x69b7: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_69b9:
	/* 0x69b9: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_69be:
	/* 0x69be: jmp    6761 <generic_sleepable_preload+0x6761> */
	goto x86_l_6761;
x86_l_69c3:
	/* 0x69c3: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_69c8:
	/* 0x69c8: jmp    680f <generic_sleepable_preload+0x680f> */
	goto x86_l_680f;
x86_l_69cd:
	/* 0x69cd: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_69cf:
	/* 0x69cf: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_69d4:
	/* 0x69d4: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_69d9:
	/* 0x69d9: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_69de:
	/* 0x69de: jmp    6287 <generic_sleepable_preload+0x6287> */
	return 25223ULL;
x86_l_69e3:
	/* 0x69e3: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_69e5:
	/* 0x69e5: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_69ea:
	/* 0x69ea: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_69ef:
	/* 0x69ef: jmp    6314 <generic_sleepable_preload+0x6314> */
	return 25364ULL;
x86_l_69f4:
	/* 0x69f4: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_69f6:
	/* 0x69f6: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_69fb:
	/* 0x69fb: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6a00:
	/* 0x6a00: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_6a05:
	/* 0x6a05: jmp    63a1 <generic_sleepable_preload+0x63a1> */
	return 25505ULL;
x86_l_6a0a:
	/* 0x6a0a: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6a0c:
	/* 0x6a0c: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_6a11:
	/* 0x6a11: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6a16:
	/* 0x6a16: jmp    642e <generic_sleepable_preload+0x642e> */
	return 25646ULL;
x86_l_6a1b:
	/* 0x6a1b: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6a1e:
	/* 0x6a1e: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_6a23:
	/* 0x6a23: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6a28:
	/* 0x6a28: jmp    64bc <generic_sleepable_preload+0x64bc> */
	return 25788ULL;
x86_l_6a2d:
	/* 0x6a2d: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6a2f:
	/* 0x6a2f: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_6a34:
	/* 0x6a34: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6a39:
	/* 0x6a39: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6a3e:
	/* 0x6a3e: jmp    6548 <generic_sleepable_preload+0x6548> */
	return 25928ULL;
x86_l_6a43:
	/* 0x6a43: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6a45:
	/* 0x6a45: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_6a4a:
	/* 0x6a4a: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6a4f:
	/* 0x6a4f: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_6a54:
	/* 0x6a54: jmp    65fc <generic_sleepable_preload+0x65fc> */
	return 26108ULL;
x86_l_6a59:
	/* 0x6a59: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6a5b:
	/* 0x6a5b: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_6a60:
	/* 0x6a60: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6a65:
	/* 0x6a65: jmp    66b1 <generic_sleepable_preload+0x66b1> */
	return 26289ULL;
x86_l_6a6a:
	/* 0x6a6a: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6a6c:
	/* 0x6a6c: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_6a71:
	/* 0x6a71: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6a76:
	/* 0x6a76: jmp    6761 <generic_sleepable_preload+0x6761> */
	goto x86_l_6761;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 22308U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1771ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1773ULL && __x86_pc <= 3565ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3570ULL && __x86_pc <= 5324ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5330ULL && __x86_pc <= 7210ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7215ULL && __x86_pc <= 9147ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 9152ULL && __x86_pc <= 11107ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 11112ULL && __x86_pc <= 13070ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 13072ULL && __x86_pc <= 15038ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 15043ULL && __x86_pc <= 16978ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_8(__x86_state, __x86_pc);
		else if (__x86_pc >= 16980ULL && __x86_pc <= 18924ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_9(__x86_state, __x86_pc);
		else if (__x86_pc >= 18930ULL && __x86_pc <= 20885ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_10(__x86_state, __x86_pc);
		else if (__x86_pc >= 20890ULL && __x86_pc <= 22846ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_11(__x86_state, __x86_pc);
		else if (__x86_pc >= 22848ULL && __x86_pc <= 24804ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_12(__x86_state, __x86_pc);
		else if (__x86_pc >= 24809ULL && __x86_pc <= 26443ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_13(__x86_state, __x86_pc);
		else if (__x86_pc >= 26448ULL && __x86_pc <= 27254ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_14(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

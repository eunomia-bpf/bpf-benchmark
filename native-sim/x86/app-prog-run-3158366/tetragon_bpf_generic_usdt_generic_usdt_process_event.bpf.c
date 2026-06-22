extern char buffer_heap_map;
extern char config_map;
extern char fdinstall_map;
extern char process_call_heap;
extern char retprobe_map;
extern char sleepable_preload;
extern char tg_errmetrics_map;
extern char tg_ipv6_ext_heap;
extern char usdt_calls;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_generic_usdt_generic_usdt_process_event_x86_chunk_0(
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
	case 174ULL: goto x86_l_ae;
	case 178ULL: goto x86_l_b2;
	case 181ULL: goto x86_l_b5;
	case 189ULL: goto x86_l_bd;
	case 192ULL: goto x86_l_c0;
	case 197ULL: goto x86_l_c5;
	case 202ULL: goto x86_l_ca;
	case 214ULL: goto x86_l_d6;
	case 221ULL: goto x86_l_dd;
	case 223ULL: goto x86_l_df;
	case 231ULL: goto x86_l_e7;
	case 239ULL: goto x86_l_ef;
	case 245ULL: goto x86_l_f5;
	case 249ULL: goto x86_l_f9;
	case 255ULL: goto x86_l_ff;
	case 259ULL: goto x86_l_103;
	case 265ULL: goto x86_l_109;
	case 269ULL: goto x86_l_10d;
	case 275ULL: goto x86_l_113;
	case 279ULL: goto x86_l_117;
	case 282ULL: goto x86_l_11a;
	case 288ULL: goto x86_l_120;
	case 292ULL: goto x86_l_124;
	case 298ULL: goto x86_l_12a;
	case 303ULL: goto x86_l_12f;
	case 312ULL: goto x86_l_138;
	case 317ULL: goto x86_l_13d;
	case 319ULL: goto x86_l_13f;
	case 324ULL: goto x86_l_144;
	case 331ULL: goto x86_l_14b;
	case 336ULL: goto x86_l_150;
	case 341ULL: goto x86_l_155;
	case 343ULL: goto x86_l_157;
	case 346ULL: goto x86_l_15a;
	case 348ULL: goto x86_l_15c;
	case 350ULL: goto x86_l_15e;
	case 358ULL: goto x86_l_166;
	case 366ULL: goto x86_l_16e;
	case 370ULL: goto x86_l_172;
	case 372ULL: goto x86_l_174;
	case 376ULL: goto x86_l_178;
	case 381ULL: goto x86_l_17d;
	case 386ULL: goto x86_l_182;
	case 391ULL: goto x86_l_187;
	case 396ULL: goto x86_l_18c;
	case 401ULL: goto x86_l_191;
	case 404ULL: goto x86_l_194;
	case 406ULL: goto x86_l_196;
	case 411ULL: goto x86_l_19b;
	case 419ULL: goto x86_l_1a3;
	case 425ULL: goto x86_l_1a9;
	case 429ULL: goto x86_l_1ad;
	case 435ULL: goto x86_l_1b3;
	case 439ULL: goto x86_l_1b7;
	case 441ULL: goto x86_l_1b9;
	case 445ULL: goto x86_l_1bd;
	case 451ULL: goto x86_l_1c3;
	case 455ULL: goto x86_l_1c7;
	case 461ULL: goto x86_l_1cd;
	case 465ULL: goto x86_l_1d1;
	case 468ULL: goto x86_l_1d4;
	case 474ULL: goto x86_l_1da;
	case 478ULL: goto x86_l_1de;
	case 484ULL: goto x86_l_1e4;
	case 489ULL: goto x86_l_1e9;
	case 493ULL: goto x86_l_1ed;
	case 499ULL: goto x86_l_1f3;
	case 503ULL: goto x86_l_1f7;
	case 506ULL: goto x86_l_1fa;
	case 512ULL: goto x86_l_200;
	case 516ULL: goto x86_l_204;
	case 519ULL: goto x86_l_207;
	case 525ULL: goto x86_l_20d;
	case 530ULL: goto x86_l_212;
	case 534ULL: goto x86_l_216;
	case 540ULL: goto x86_l_21c;
	case 544ULL: goto x86_l_220;
	case 550ULL: goto x86_l_226;
	case 554ULL: goto x86_l_22a;
	case 560ULL: goto x86_l_230;
	case 564ULL: goto x86_l_234;
	case 570ULL: goto x86_l_23a;
	case 575ULL: goto x86_l_23f;
	case 579ULL: goto x86_l_243;
	case 585ULL: goto x86_l_249;
	case 589ULL: goto x86_l_24d;
	case 595ULL: goto x86_l_253;
	case 599ULL: goto x86_l_257;
	case 605ULL: goto x86_l_25d;
	case 609ULL: goto x86_l_261;
	case 615ULL: goto x86_l_267;
	case 620ULL: goto x86_l_26c;
	case 624ULL: goto x86_l_270;
	case 626ULL: goto x86_l_272;
	case 630ULL: goto x86_l_276;
	case 632ULL: goto x86_l_278;
	case 636ULL: goto x86_l_27c;
	case 642ULL: goto x86_l_282;
	case 646ULL: goto x86_l_286;
	case 648ULL: goto x86_l_288;
	case 653ULL: goto x86_l_28d;
	case 657ULL: goto x86_l_291;
	case 659ULL: goto x86_l_293;
	case 662ULL: goto x86_l_296;
	case 666ULL: goto x86_l_29a;
	case 672ULL: goto x86_l_2a0;
	case 676ULL: goto x86_l_2a4;
	case 678ULL: goto x86_l_2a6;
	case 680ULL: goto x86_l_2a8;
	case 684ULL: goto x86_l_2ac;
	case 687ULL: goto x86_l_2af;
	case 689ULL: goto x86_l_2b1;
	case 695ULL: goto x86_l_2b7;
	case 697ULL: goto x86_l_2b9;
	case 701ULL: goto x86_l_2bd;
	case 703ULL: goto x86_l_2bf;
	case 707ULL: goto x86_l_2c3;
	case 709ULL: goto x86_l_2c5;
	case 715ULL: goto x86_l_2cb;
	case 717ULL: goto x86_l_2cd;
	case 721ULL: goto x86_l_2d1;
	case 723ULL: goto x86_l_2d3;
	case 727ULL: goto x86_l_2d7;
	case 729ULL: goto x86_l_2d9;
	case 735ULL: goto x86_l_2df;
	case 737ULL: goto x86_l_2e1;
	case 743ULL: goto x86_l_2e7;
	case 745ULL: goto x86_l_2e9;
	case 749ULL: goto x86_l_2ed;
	case 751ULL: goto x86_l_2ef;
	case 755ULL: goto x86_l_2f3;
	case 757ULL: goto x86_l_2f5;
	case 763ULL: goto x86_l_2fb;
	case 765ULL: goto x86_l_2fd;
	case 771ULL: goto x86_l_303;
	case 773ULL: goto x86_l_305;
	case 779ULL: goto x86_l_30b;
	case 781ULL: goto x86_l_30d;
	case 785ULL: goto x86_l_311;
	case 787ULL: goto x86_l_313;
	case 793ULL: goto x86_l_319;
	case 795ULL: goto x86_l_31b;
	case 798ULL: goto x86_l_31e;
	case 809ULL: goto x86_l_329;
	case 816ULL: goto x86_l_330;
	case 824ULL: goto x86_l_338;
	case 829ULL: goto x86_l_33d;
	case 831ULL: goto x86_l_33f;
	case 834ULL: goto x86_l_342;
	case 836ULL: goto x86_l_344;
	case 841ULL: goto x86_l_349;
	case 844ULL: goto x86_l_34c;
	case 847ULL: goto x86_l_34f;
	case 849ULL: goto x86_l_351;
	case 857ULL: goto x86_l_359;
	case 864ULL: goto x86_l_360;
	case 871ULL: goto x86_l_367;
	case 875ULL: goto x86_l_36b;
	case 883ULL: goto x86_l_373;
	case 888ULL: goto x86_l_378;
	case 890ULL: goto x86_l_37a;
	case 896ULL: goto x86_l_380;
	case 904ULL: goto x86_l_388;
	case 909ULL: goto x86_l_38d;
	case 917ULL: goto x86_l_395;
	case 921ULL: goto x86_l_399;
	case 925ULL: goto x86_l_39d;
	case 931ULL: goto x86_l_3a3;
	case 939ULL: goto x86_l_3ab;
	case 946ULL: goto x86_l_3b2;
	case 951ULL: goto x86_l_3b7;
	case 956ULL: goto x86_l_3bc;
	case 958ULL: goto x86_l_3be;
	case 961ULL: goto x86_l_3c1;
	case 967ULL: goto x86_l_3c7;
	case 970ULL: goto x86_l_3ca;
	case 977ULL: goto x86_l_3d1;
	case 984ULL: goto x86_l_3d8;
	case 989ULL: goto x86_l_3dd;
	case 991ULL: goto x86_l_3df;
	case 994ULL: goto x86_l_3e2;
	case 1000ULL: goto x86_l_3e8;
	case 1003ULL: goto x86_l_3eb;
	case 1006ULL: goto x86_l_3ee;
	case 1009ULL: goto x86_l_3f1;
	case 1014ULL: goto x86_l_3f6;
	case 1020ULL: goto x86_l_3fc;
	case 1027ULL: goto x86_l_403;
	case 1034ULL: goto x86_l_40a;
	case 1039ULL: goto x86_l_40f;
	case 1044ULL: goto x86_l_414;
	case 1047ULL: goto x86_l_417;
	case 1052ULL: goto x86_l_41c;
	case 1054ULL: goto x86_l_41e;
	case 1059ULL: goto x86_l_423;
	case 1062ULL: goto x86_l_426;
	case 1069ULL: goto x86_l_42d;
	case 1072ULL: goto x86_l_430;
	case 1077ULL: goto x86_l_435;
	case 1085ULL: goto x86_l_43d;
	case 1090ULL: goto x86_l_442;
	case 1099ULL: goto x86_l_44b;
	case 1103ULL: goto x86_l_44f;
	case 1108ULL: goto x86_l_454;
	case 1110ULL: goto x86_l_456;
	case 1114ULL: goto x86_l_45a;
	case 1120ULL: goto x86_l_460;
	case 1124ULL: goto x86_l_464;
	case 1126ULL: goto x86_l_466;
	case 1131ULL: goto x86_l_46b;
	case 1136ULL: goto x86_l_470;
	case 1140ULL: goto x86_l_474;
	case 1146ULL: goto x86_l_47a;
	case 1150ULL: goto x86_l_47e;
	case 1152ULL: goto x86_l_480;
	case 1164ULL: goto x86_l_48c;
	case 1172ULL: goto x86_l_494;
	case 1180ULL: goto x86_l_49c;
	case 1185ULL: goto x86_l_4a1;
	case 1193ULL: goto x86_l_4a9;
	case 1197ULL: goto x86_l_4ad;
	case 1203ULL: goto x86_l_4b3;
	case 1206ULL: goto x86_l_4b6;
	case 1216ULL: goto x86_l_4c0;
	case 1220ULL: goto x86_l_4c4;
	case 1226ULL: goto x86_l_4ca;
	case 1231ULL: goto x86_l_4cf;
	case 1242ULL: goto x86_l_4da;
	case 1249ULL: goto x86_l_4e1;
	case 1257ULL: goto x86_l_4e9;
	case 1262ULL: goto x86_l_4ee;
	case 1264ULL: goto x86_l_4f0;
	case 1266ULL: goto x86_l_4f2;
	case 1269ULL: goto x86_l_4f5;
	case 1275ULL: goto x86_l_4fb;
	case 1279ULL: goto x86_l_4ff;
	case 1285ULL: goto x86_l_505;
	case 1289ULL: goto x86_l_509;
	case 1295ULL: goto x86_l_50f;
	case 1299ULL: goto x86_l_513;
	case 1305ULL: goto x86_l_519;
	case 1309ULL: goto x86_l_51d;
	case 1315ULL: goto x86_l_523;
	case 1319ULL: goto x86_l_527;
	case 1325ULL: goto x86_l_52d;
	case 1329ULL: goto x86_l_531;
	case 1334ULL: goto x86_l_536;
	case 1339ULL: goto x86_l_53b;
	case 1345ULL: goto x86_l_541;
	case 1350ULL: goto x86_l_546;
	case 1358ULL: goto x86_l_54e;
	case 1363ULL: goto x86_l_553;
	case 1368ULL: goto x86_l_558;
	case 1373ULL: goto x86_l_55d;
	case 1378ULL: goto x86_l_562;
	case 1383ULL: goto x86_l_567;
	case 1385ULL: goto x86_l_569;
	case 1390ULL: goto x86_l_56e;
	case 1395ULL: goto x86_l_573;
	case 1398ULL: goto x86_l_576;
	case 1404ULL: goto x86_l_57c;
	case 1415ULL: goto x86_l_587;
	case 1422ULL: goto x86_l_58e;
	case 1430ULL: goto x86_l_596;
	case 1435ULL: goto x86_l_59b;
	case 1437ULL: goto x86_l_59d;
	case 1439ULL: goto x86_l_59f;
	case 1442ULL: goto x86_l_5a2;
	case 1448ULL: goto x86_l_5a8;
	case 1452ULL: goto x86_l_5ac;
	case 1458ULL: goto x86_l_5b2;
	case 1462ULL: goto x86_l_5b6;
	case 1468ULL: goto x86_l_5bc;
	case 1472ULL: goto x86_l_5c0;
	case 1478ULL: goto x86_l_5c6;
	case 1482ULL: goto x86_l_5ca;
	case 1488ULL: goto x86_l_5d0;
	case 1492ULL: goto x86_l_5d4;
	case 1498ULL: goto x86_l_5da;
	case 1502ULL: goto x86_l_5de;
	case 1507ULL: goto x86_l_5e3;
	case 1512ULL: goto x86_l_5e8;
	case 1518ULL: goto x86_l_5ee;
	case 1523ULL: goto x86_l_5f3;
	case 1530ULL: goto x86_l_5fa;
	case 1533ULL: goto x86_l_5fd;
	case 1538ULL: goto x86_l_602;
	case 1543ULL: goto x86_l_607;
	case 1546ULL: goto x86_l_60a;
	case 1551ULL: goto x86_l_60f;
	case 1556ULL: goto x86_l_614;
	case 1561ULL: goto x86_l_619;
	case 1566ULL: goto x86_l_61e;
	case 1569ULL: goto x86_l_621;
	case 1574ULL: goto x86_l_626;
	case 1576ULL: goto x86_l_628;
	case 1581ULL: goto x86_l_62d;
	case 1586ULL: goto x86_l_632;
	case 1591ULL: goto x86_l_637;
	case 1596ULL: goto x86_l_63c;
	case 1601ULL: goto x86_l_641;
	case 1606ULL: goto x86_l_646;
	case 1611ULL: goto x86_l_64b;
	case 1613ULL: goto x86_l_64d;
	case 1618ULL: goto x86_l_652;
	case 1622ULL: goto x86_l_656;
	case 1627ULL: goto x86_l_65b;
	case 1638ULL: goto x86_l_666;
	case 1645ULL: goto x86_l_66d;
	case 1653ULL: goto x86_l_675;
	case 1658ULL: goto x86_l_67a;
	case 1660ULL: goto x86_l_67c;
	case 1663ULL: goto x86_l_67f;
	case 1669ULL: goto x86_l_685;
	case 1672ULL: goto x86_l_688;
	case 1678ULL: goto x86_l_68e;
	case 1686ULL: goto x86_l_696;
	case 1691ULL: goto x86_l_69b;
	case 1693ULL: goto x86_l_69d;
	case 1700ULL: goto x86_l_6a4;
	case 1708ULL: goto x86_l_6ac;
	case 1713ULL: goto x86_l_6b1;
	case 1718ULL: goto x86_l_6b6;
	case 1723ULL: goto x86_l_6bb;
	case 1725ULL: goto x86_l_6bd;
	case 1733ULL: goto x86_l_6c5;
	case 1738ULL: goto x86_l_6ca;
	case 1742ULL: goto x86_l_6ce;
	case 1750ULL: goto x86_l_6d6;
	case 1755ULL: goto x86_l_6db;
	case 1760ULL: goto x86_l_6e0;
	case 1764ULL: goto x86_l_6e4;
	case 1772ULL: goto x86_l_6ec;
	case 1777ULL: goto x86_l_6f1;
	case 1785ULL: goto x86_l_6f9;
	case 1787ULL: goto x86_l_6fb;
	case 1795ULL: goto x86_l_703;
	case 1800ULL: goto x86_l_708;
	case 1805ULL: goto x86_l_70d;
	case 1810ULL: goto x86_l_712;
	case 1815ULL: goto x86_l_717;
	case 1820ULL: goto x86_l_71c;
	case 1822ULL: goto x86_l_71e;
	case 1828ULL: goto x86_l_724;
	case 1833ULL: goto x86_l_729;
	case 1835ULL: goto x86_l_72b;
	case 1843ULL: goto x86_l_733;
	case 1845ULL: goto x86_l_735;
	case 1847ULL: goto x86_l_737;
	case 1855ULL: goto x86_l_73f;
	case 1860ULL: goto x86_l_744;
	default: return 0xffffffffffffffffULL;
	}
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0xf8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 248ULL);
x86_l_a:
	/* 0xa: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    DWORD PTR [rsp+0xdc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_18:
	/* 0x18: mov    rdi,QWORD PTR [rip+0x9e7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_1f:
	/* 0x1f: lea    rsi,[rsp+0xdc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 220ULL);
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
	/* 0x31: je     3953 <generic_usdt_process_event+0x3953> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14675ULL;
	}
x86_l_37:
	/* 0x37: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_3a:
	/* 0x3a: mov    r13d,DWORD PTR [rax+0x5eec] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24300ULL);
x86_l_41:
	/* 0x41: mov    ebp,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_44:
	/* 0x44: cmp    rbp,0x2327 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 8999ULL);
x86_l_4b:
	/* 0x4b: ja     395 <generic_usdt_process_event+0x395> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_395;
	}
x86_l_51:
	/* 0x51: mov    DWORD PTR [rsp+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_5c:
	/* 0x5c: mov    rdi,QWORD PTR [rip+0x9e7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_63:
	/* 0x63: lea    rsi,[rsp+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
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
	/* 0x75: je     395 <generic_usdt_process_event+0x395> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_395;
	}
x86_l_7b:
	/* 0x7b: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_7e:
	/* 0x7e: lea    rsi,[rax+0x5ee8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24296ULL);
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
	/* 0x93: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_97:
	/* 0x97: jg     395 <generic_usdt_process_event+0x395> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_395;
	}
x86_l_9d:
	/* 0x9d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a0:
	/* 0xa0: je     395 <generic_usdt_process_event+0x395> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_395;
	}
x86_l_a6:
	/* 0xa6: mov    QWORD PTR [rsp+0xb8],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_ae:
	/* 0xae: and    r13d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_b2:
	/* 0xb2: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_b5:
	/* 0xb5: mov    QWORD PTR [rsp+0xd0],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_bd:
	/* 0xbd: mov    ecx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_32);
x86_l_c0:
	/* 0xc0: mov    r13d,DWORD PTR [rax+rcx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 4ULL);
x86_l_c5:
	/* 0xc5: movsxd r12,DWORD PTR [rax+rcx*4+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_RCX, 2, X86_WIDTH_32), 24ULL);
x86_l_ca:
	/* 0xca: mov    DWORD PTR [r15+rcx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 104041287778304ULL);
x86_l_d6:
	/* 0xd6: test   r12d,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R12, X86_WIDTH_32, 256ULL);
x86_l_dd:
	/* 0xdd: jne    12f <generic_usdt_process_event+0x12f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_12f;
	}
x86_l_df:
	/* 0xdf: mov    rax,QWORD PTR [r15+rcx*8+0x5e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 3), 24144ULL);
x86_l_e7:
	/* 0xe7: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_ef:
	/* 0xef: mov    r15d,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 144ULL);
x86_l_f5:
	/* 0xf5: cmp    r13d,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 21ULL);
x86_l_f9:
	/* 0xf9: jle    1b3 <generic_usdt_process_event+0x1b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1b3;
	}
x86_l_ff:
	/* 0xff: cmp    r13d,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 32ULL);
x86_l_103:
	/* 0x103: jle    212 <generic_usdt_process_event+0x212> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_212;
	}
x86_l_109:
	/* 0x109: cmp    r13d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 38ULL);
x86_l_10d:
	/* 0x10d: jg     26c <generic_usdt_process_event+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_26c;
	}
x86_l_113:
	/* 0x113: lea    eax,[r13-0x21] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551583ULL);
x86_l_117:
	/* 0x117: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_11a:
	/* 0x11a: jb     2e1 <generic_usdt_process_event+0x2e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2e1;
	}
x86_l_120:
	/* 0x120: cmp    r13d,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 37ULL);
x86_l_124:
	/* 0x124: je     31e <generic_usdt_process_event+0x31e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31e;
	}
x86_l_12a:
	/* 0x12a: jmp    31b <generic_usdt_process_event+0x31b> */
	goto x86_l_31b;
x86_l_12f:
	/* 0x12f: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_138:
	/* 0x138: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_13d:
	/* 0x13d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13f:
	/* 0x13f: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_144:
	/* 0x144: mov    rdi,QWORD PTR [rip+0x9ec] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_14b:
	/* 0x14b: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_150:
	/* 0x150: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_155:
	/* 0x155: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_157:
	/* 0x157: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15a:
	/* 0x15a: je     196 <generic_usdt_process_event+0x196> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_196;
	}
x86_l_15c:
	/* 0x15c: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15e:
	/* 0x15e: mov    rdx,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_166:
	/* 0x166: mov    DWORD PTR [r15+rdx*4+0x5ea0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 24224ULL);
x86_l_16e:
	/* 0x16e: cmp    r13d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 6ULL);
x86_l_172:
	/* 0x172: jne    196 <generic_usdt_process_event+0x196> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_196;
	}
x86_l_174:
	/* 0x174: add    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_178:
	/* 0x178: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_17d:
	/* 0x17d: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_182:
	/* 0x182: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_187:
	/* 0x187: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18c:
	/* 0x18c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_191:
	/* 0x191: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_194:
	/* 0x194: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_196:
	/* 0x196: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_19b:
	/* 0x19b: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1a3:
	/* 0x1a3: mov    r15d,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 144ULL);
x86_l_1a9:
	/* 0x1a9: cmp    r13d,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 21ULL);
x86_l_1ad:
	/* 0x1ad: jg     ff <generic_usdt_process_event+0xff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_ff;
	}
x86_l_1b3:
	/* 0x1b3: cmp    r13d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 11ULL);
x86_l_1b7:
	/* 0x1b7: jg     1e9 <generic_usdt_process_event+0x1e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1e9;
	}
x86_l_1b9:
	/* 0x1b9: cmp    r13d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 5ULL);
x86_l_1bd:
	/* 0x1bd: jg     23f <generic_usdt_process_event+0x23f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_23f;
	}
x86_l_1c3:
	/* 0x1c3: cmp    r13d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 3ULL);
x86_l_1c7:
	/* 0x1c7: jg     2cd <generic_usdt_process_event+0x2cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2cd;
	}
x86_l_1cd:
	/* 0x1cd: lea    eax,[r13-0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_1d1:
	/* 0x1d1: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1d4:
	/* 0x1d4: jb     2b1 <generic_usdt_process_event+0x2b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2b1;
	}
x86_l_1da:
	/* 0x1da: cmp    r13d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1ULL);
x86_l_1de:
	/* 0x1de: je     2b1 <generic_usdt_process_event+0x2b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b1;
	}
x86_l_1e4:
	/* 0x1e4: jmp    31b <generic_usdt_process_event+0x31b> */
	goto x86_l_31b;
x86_l_1e9:
	/* 0x1e9: cmp    r13d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 17ULL);
x86_l_1ed:
	/* 0x1ed: jg     28d <generic_usdt_process_event+0x28d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_28d;
	}
x86_l_1f3:
	/* 0x1f3: lea    eax,[r13-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_1f7:
	/* 0x1f7: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1fa:
	/* 0x1fa: jb     31e <generic_usdt_process_event+0x31e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_31e;
	}
x86_l_200:
	/* 0x200: lea    eax,[r13-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_204:
	/* 0x204: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_207:
	/* 0x207: jb     2b1 <generic_usdt_process_event+0x2b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2b1;
	}
x86_l_20d:
	/* 0x20d: jmp    31b <generic_usdt_process_event+0x31b> */
	goto x86_l_31b;
x86_l_212:
	/* 0x212: cmp    r13d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 26ULL);
x86_l_216:
	/* 0x216: jg     2a8 <generic_usdt_process_event+0x2a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2a8;
	}
x86_l_21c:
	/* 0x21c: cmp    r13d,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 22ULL);
x86_l_220:
	/* 0x220: je     2fd <generic_usdt_process_event+0x2fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fd;
	}
x86_l_226:
	/* 0x226: cmp    r13d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 23ULL);
x86_l_22a:
	/* 0x22a: je     2e1 <generic_usdt_process_event+0x2e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e1;
	}
x86_l_230:
	/* 0x230: cmp    r13d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 26ULL);
x86_l_234:
	/* 0x234: je     313 <generic_usdt_process_event+0x313> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_313;
	}
x86_l_23a:
	/* 0x23a: jmp    31b <generic_usdt_process_event+0x31b> */
	goto x86_l_31b;
x86_l_23f:
	/* 0x23f: cmp    r13d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 9ULL);
x86_l_243:
	/* 0x243: jg     2e1 <generic_usdt_process_event+0x2e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2e1;
	}
x86_l_249:
	/* 0x249: cmp    r13d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 6ULL);
x86_l_24d:
	/* 0x24d: je     31e <generic_usdt_process_event+0x31e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31e;
	}
x86_l_253:
	/* 0x253: cmp    r13d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 7ULL);
x86_l_257:
	/* 0x257: je     2d9 <generic_usdt_process_event+0x2d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d9;
	}
x86_l_25d:
	/* 0x25d: cmp    r13d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 8ULL);
x86_l_261:
	/* 0x261: je     313 <generic_usdt_process_event+0x313> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_313;
	}
x86_l_267:
	/* 0x267: jmp    31b <generic_usdt_process_event+0x31b> */
	goto x86_l_31b;
x86_l_26c:
	/* 0x26c: cmp    r13d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 40ULL);
x86_l_270:
	/* 0x270: jle    2e9 <generic_usdt_process_event+0x2e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2e9;
	}
x86_l_272:
	/* 0x272: cmp    r13d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 41ULL);
x86_l_276:
	/* 0x276: je     2d9 <generic_usdt_process_event+0x2d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d9;
	}
x86_l_278:
	/* 0x278: cmp    r13d,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 42ULL);
x86_l_27c:
	/* 0x27c: je     31e <generic_usdt_process_event+0x31e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31e;
	}
x86_l_282:
	/* 0x282: cmp    r13d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 43ULL);
x86_l_286:
	/* 0x286: je     2f5 <generic_usdt_process_event+0x2f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f5;
	}
x86_l_288:
	/* 0x288: jmp    31b <generic_usdt_process_event+0x31b> */
	goto x86_l_31b;
x86_l_28d:
	/* 0x28d: cmp    r13d,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 19ULL);
x86_l_291:
	/* 0x291: jg     2b9 <generic_usdt_process_event+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2b9;
	}
x86_l_293:
	/* 0x293: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_296:
	/* 0x296: cmp    r13d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 18ULL);
x86_l_29a:
	/* 0x29a: je     31e <generic_usdt_process_event+0x31e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31e;
	}
x86_l_2a0:
	/* 0x2a0: cmp    r13d,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 19ULL);
x86_l_2a4:
	/* 0x2a4: je     2f5 <generic_usdt_process_event+0x2f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f5;
	}
x86_l_2a6:
	/* 0x2a6: jmp    31b <generic_usdt_process_event+0x31b> */
	goto x86_l_31b;
x86_l_2a8:
	/* 0x2a8: lea    eax,[r13-0x1d] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551587ULL);
x86_l_2ac:
	/* 0x2ac: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2af:
	/* 0x2af: jae    30d <generic_usdt_process_event+0x30d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_30d;
	}
x86_l_2b1:
	/* 0x2b1: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2b7:
	/* 0x2b7: jmp    31e <generic_usdt_process_event+0x31e> */
	goto x86_l_31e;
x86_l_2b9:
	/* 0x2b9: cmp    r13d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 20ULL);
x86_l_2bd:
	/* 0x2bd: je     305 <generic_usdt_process_event+0x305> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_305;
	}
x86_l_2bf:
	/* 0x2bf: cmp    r13d,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 21ULL);
x86_l_2c3:
	/* 0x2c3: jne    31b <generic_usdt_process_event+0x31b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_31b;
	}
x86_l_2c5:
	/* 0x2c5: mov    r15d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 32ULL);
x86_l_2cb:
	/* 0x2cb: jmp    31e <generic_usdt_process_event+0x31e> */
	goto x86_l_31e;
x86_l_2cd:
	/* 0x2cd: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_2d1:
	/* 0x2d1: je     2e1 <generic_usdt_process_event+0x2e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e1;
	}
x86_l_2d3:
	/* 0x2d3: cmp    r13d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 5ULL);
x86_l_2d7:
	/* 0x2d7: jne    31b <generic_usdt_process_event+0x31b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_31b;
	}
x86_l_2d9:
	/* 0x2d9: mov    r15d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 64ULL);
x86_l_2df:
	/* 0x2df: jmp    31e <generic_usdt_process_event+0x31e> */
	goto x86_l_31e;
x86_l_2e1:
	/* 0x2e1: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_2e7:
	/* 0x2e7: jmp    31e <generic_usdt_process_event+0x31e> */
	goto x86_l_31e;
x86_l_2e9:
	/* 0x2e9: cmp    r13d,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 39ULL);
x86_l_2ed:
	/* 0x2ed: je     2fd <generic_usdt_process_event+0x2fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fd;
	}
x86_l_2ef:
	/* 0x2ef: cmp    r13d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 40ULL);
x86_l_2f3:
	/* 0x2f3: jne    31b <generic_usdt_process_event+0x31b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_31b;
	}
x86_l_2f5:
	/* 0x2f5: mov    r15d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 24ULL);
x86_l_2fb:
	/* 0x2fb: jmp    31e <generic_usdt_process_event+0x31e> */
	goto x86_l_31e;
x86_l_2fd:
	/* 0x2fd: mov    r15d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 16ULL);
x86_l_303:
	/* 0x303: jmp    31e <generic_usdt_process_event+0x31e> */
	goto x86_l_31e;
x86_l_305:
	/* 0x305: mov    r15d,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 152ULL);
x86_l_30b:
	/* 0x30b: jmp    31e <generic_usdt_process_event+0x31e> */
	goto x86_l_31e;
x86_l_30d:
	/* 0x30d: cmp    r13d,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 27ULL);
x86_l_311:
	/* 0x311: jne    31b <generic_usdt_process_event+0x31b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_31b;
	}
x86_l_313:
	/* 0x313: mov    r15d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 80ULL);
x86_l_319:
	/* 0x319: jmp    31e <generic_usdt_process_event+0x31e> */
	goto x86_l_31e;
x86_l_31b:
	/* 0x31b: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_31e:
	/* 0x31e: mov    DWORD PTR [rsp+0xe4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_329:
	/* 0x329: mov    rdi,QWORD PTR [rip+0x9db] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_330:
	/* 0x330: lea    rsi,[rsp+0xe4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 228ULL);
x86_l_338:
	/* 0x338: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_33d:
	/* 0x33d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33f:
	/* 0x33f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_342:
	/* 0x342: je     38d <generic_usdt_process_event+0x38d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38d;
	}
x86_l_344:
	/* 0x344: mov    ecx,0x3ffb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16379ULL);
x86_l_349:
	/* 0x349: sub    rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_34c:
	/* 0x34c: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_34f:
	/* 0x34f: jbe    38d <generic_usdt_process_event+0x38d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_38d;
	}
x86_l_351:
	/* 0x351: mov    rdx,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_359:
	/* 0x359: mov    ecx,DWORD PTR [rax+rdx*4+0x5ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 24224ULL);
x86_l_360:
	/* 0x360: mov    DWORD PTR [rax+rbp*1+0x90],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 144ULL);
x86_l_367:
	/* 0x367: lea    rsi,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_36b:
	/* 0x36b: mov    QWORD PTR [rax+rdx*8+0x5e78],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 3), 24184ULL);
x86_l_373:
	/* 0x373: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_378:
	/* 0x378: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_37a:
	/* 0x37a: je     423 <generic_usdt_process_event+0x423> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_423;
	}
x86_l_380:
	/* 0x380: mov    r13,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_388:
	/* 0x388: jmp    391b <generic_usdt_process_event+0x391b> */
	return 14619ULL;
x86_l_38d:
	/* 0x38d: mov    r13,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_395:
	/* 0x395: mov    DWORD PTR [r14+0x4],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_399:
	/* 0x399: cmp    r13d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 3ULL);
x86_l_39d:
	/* 0x39d: jg     392d <generic_usdt_process_event+0x392d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 14637ULL;
	}
x86_l_3a3:
	/* 0x3a3: mov    DWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_3ab:
	/* 0x3ab: mov    rdi,QWORD PTR [rip+0x9db] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_3b2:
	/* 0x3b2: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3b7:
	/* 0x3b7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3bc:
	/* 0x3bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3be:
	/* 0x3be: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3c1:
	/* 0x3c1: je     392d <generic_usdt_process_event+0x392d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14637ULL;
	}
x86_l_3c7:
	/* 0x3c7: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_3ca:
	/* 0x3ca: add    rsi,0x5ee8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24296ULL);
x86_l_3d1:
	/* 0x3d1: mov    rdi,QWORD PTR [rip+0x9db] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_3d8:
	/* 0x3d8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3dd:
	/* 0x3dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3df:
	/* 0x3df: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3e2:
	/* 0x3e2: je     392d <generic_usdt_process_event+0x392d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14637ULL;
	}
x86_l_3e8:
	/* 0x3e8: inc    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3eb:
	/* 0x3eb: mov    ecx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_32);
x86_l_3ee:
	/* 0x3ee: and    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_3f1:
	/* 0x3f1: cmp    DWORD PTR [rax+rcx*4+0x40],0xffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 279172874239ULL);
x86_l_3f6:
	/* 0x3f6: je     392d <generic_usdt_process_event+0x392d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14637ULL;
	}
x86_l_3fc:
	/* 0x3fc: mov    DWORD PTR [r14+0x5eec],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24300ULL);
x86_l_403:
	/* 0x403: mov    rsi,QWORD PTR [rip+0x9db] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&usdt_calls)));
x86_l_40a:
	/* 0x40a: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_40f:
	/* 0x40f: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_414:
	/* 0x414: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_417:
	/* 0x417: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_41c:
	/* 0x41c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41e:
	/* 0x41e: jmp    392d <generic_usdt_process_event+0x392d> */
	return 14637ULL;
x86_l_423:
	/* 0x423: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_426:
	/* 0x426: add    rcx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_42d:
	/* 0x42d: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_430:
	/* 0x430: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_435:
	/* 0x435: mov    r15,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_43d:
	/* 0x43d: mov    QWORD PTR [rsp+0x38],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_442:
	/* 0x442: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_44b:
	/* 0x44b: cmp    r13d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 23ULL);
x86_l_44f:
	/* 0x44f: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_454:
	/* 0x454: jg     470 <generic_usdt_process_event+0x470> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_470;
	}
x86_l_456:
	/* 0x456: cmp    r13d,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 15ULL);
x86_l_45a:
	/* 0x45a: je     546 <generic_usdt_process_event+0x546> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_546;
	}
x86_l_460:
	/* 0x460: cmp    r13d,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 16ULL);
x86_l_464:
	/* 0x464: jne    4a1 <generic_usdt_process_event+0x4a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4a1;
	}
x86_l_466:
	/* 0x466: lea    r15,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_46b:
	/* 0x46b: jmp    632 <generic_usdt_process_event+0x632> */
	goto x86_l_632;
x86_l_470:
	/* 0x470: cmp    r13d,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 24ULL);
x86_l_474:
	/* 0x474: je     607 <generic_usdt_process_event+0x607> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_607;
	}
x86_l_47a:
	/* 0x47a: cmp    r13d,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 42ULL);
x86_l_47e:
	/* 0x47e: jne    4a1 <generic_usdt_process_event+0x4a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4a1;
	}
x86_l_480:
	/* 0x480: mov    QWORD PTR [rsp+0xe8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 996432412672ULL);
x86_l_48c:
	/* 0x48c: mov    QWORD PTR [rsp+0xf0],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_494:
	/* 0x494: lea    rax,[rsp+0xe8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_49c:
	/* 0x49c: jmp    656 <generic_usdt_process_event+0x656> */
	goto x86_l_656;
x86_l_4a1:
	/* 0x4a1: mov    QWORD PTR [rsp+0x98],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_4a9:
	/* 0x4a9: cmp    r13d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 40ULL);
x86_l_4ad:
	/* 0x4ad: ja     57c <generic_usdt_process_event+0x57c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_57c;
	}
x86_l_4b3:
	/* 0x4b3: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_4b6:
	/* 0x4b6: movabs rcx,0x1c1f2027cf2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1932500565234ULL);
x86_l_4c0:
	/* 0x4c0: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_4c4:
	/* 0x4c4: jae    57c <generic_usdt_process_event+0x57c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_57c;
	}
x86_l_4ca:
	/* 0x4ca: mov    QWORD PTR [rsp+0x28],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4cf:
	/* 0x4cf: mov    DWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_4da:
	/* 0x4da: mov    rdi,QWORD PTR [rip+0x9db] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_4e1:
	/* 0x4e1: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_4e9:
	/* 0x4e9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4ee:
	/* 0x4ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f0:
	/* 0x4f0: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4f2:
	/* 0x4f2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4f5:
	/* 0x4f5: je     38da <generic_usdt_process_event+0x38da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14554ULL;
	}
x86_l_4fb:
	/* 0x4fb: cmp    r13d,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 13ULL);
x86_l_4ff:
	/* 0x4ff: jle    c60 <generic_usdt_process_event+0xc60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3168ULL;
	}
x86_l_505:
	/* 0x505: cmp    r13d,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 30ULL);
x86_l_509:
	/* 0x509: jg     dbe <generic_usdt_process_event+0xdbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3518ULL;
	}
x86_l_50f:
	/* 0x50f: cmp    r13d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 28ULL);
x86_l_513:
	/* 0x513: jg     1050 <generic_usdt_process_event+0x1050> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 4176ULL;
	}
x86_l_519:
	/* 0x519: cmp    r13d,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 14ULL);
x86_l_51d:
	/* 0x51d: je     1975 <generic_usdt_process_event+0x1975> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6517ULL;
	}
x86_l_523:
	/* 0x523: cmp    r13d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 17ULL);
x86_l_527:
	/* 0x527: je     18b3 <generic_usdt_process_event+0x18b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6323ULL;
	}
x86_l_52d:
	/* 0x52d: cmp    r13d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 28ULL);
x86_l_531:
	/* 0x531: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_536:
	/* 0x536: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_53b:
	/* 0x53b: je     fa8 <generic_usdt_process_event+0xfa8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4008ULL;
	}
x86_l_541:
	/* 0x541: jmp    38e4 <generic_usdt_process_event+0x38e4> */
	return 14564ULL;
x86_l_546:
	/* 0x546: mov    QWORD PTR [rsp+0x98],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_54e:
	/* 0x54e: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_553:
	/* 0x553: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_558:
	/* 0x558: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_55d:
	/* 0x55d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_562:
	/* 0x562: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_567:
	/* 0x567: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_569:
	/* 0x569: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_56e:
	/* 0x56e: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_573:
	/* 0x573: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_576:
	/* 0x576: jne    65b <generic_usdt_process_event+0x65b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_65b;
	}
x86_l_57c:
	/* 0x57c: mov    DWORD PTR [rsp+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_587:
	/* 0x587: mov    rdi,QWORD PTR [rip+0x9db] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_58e:
	/* 0x58e: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_596:
	/* 0x596: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_59b:
	/* 0x59b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_59d:
	/* 0x59d: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_59f:
	/* 0x59f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5a2:
	/* 0x5a2: je     38da <generic_usdt_process_event+0x38da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14554ULL;
	}
x86_l_5a8:
	/* 0x5a8: cmp    r13d,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 25ULL);
x86_l_5ac:
	/* 0x5ac: jg     fcd <generic_usdt_process_event+0xfcd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 4045ULL;
	}
x86_l_5b2:
	/* 0x5b2: cmp    r13d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 18ULL);
x86_l_5b6:
	/* 0x5b6: jle    1128 <generic_usdt_process_event+0x1128> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 4392ULL;
	}
x86_l_5bc:
	/* 0x5bc: cmp    r13d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 20ULL);
x86_l_5c0:
	/* 0x5c0: jle    15f8 <generic_usdt_process_event+0x15f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5624ULL;
	}
x86_l_5c6:
	/* 0x5c6: cmp    r13d,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 21ULL);
x86_l_5ca:
	/* 0x5ca: je     1d28 <generic_usdt_process_event+0x1d28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7464ULL;
	}
x86_l_5d0:
	/* 0x5d0: cmp    r13d,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 22ULL);
x86_l_5d4:
	/* 0x5d4: je     1c9f <generic_usdt_process_event+0x1c9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7327ULL;
	}
x86_l_5da:
	/* 0x5da: cmp    r13d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 23ULL);
x86_l_5de:
	/* 0x5de: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5e3:
	/* 0x5e3: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_5e8:
	/* 0x5e8: jne    38e4 <generic_usdt_process_event+0x38e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14564ULL;
	}
x86_l_5ee:
	/* 0x5ee: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f3:
	/* 0x5f3: mov    DWORD PTR [rcx+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_5fa:
	/* 0x5fa: mov    DWORD PTR [rcx],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5fd:
	/* 0x5fd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_602:
	/* 0x602: jmp    38e4 <generic_usdt_process_event+0x38e4> */
	return 14564ULL;
x86_l_607:
	/* 0x607: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_60a:
	/* 0x60a: lea    r15,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_60f:
	/* 0x60f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_614:
	/* 0x614: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_619:
	/* 0x619: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_61e:
	/* 0x61e: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_621:
	/* 0x621: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_626:
	/* 0x626: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_628:
	/* 0x628: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_62d:
	/* 0x62d: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_632:
	/* 0x632: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_637:
	/* 0x637: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_63c:
	/* 0x63c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_641:
	/* 0x641: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_646:
	/* 0x646: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_64b:
	/* 0x64b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_64d:
	/* 0x64d: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_652:
	/* 0x652: add    rax,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_656:
	/* 0x656: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_65b:
	/* 0x65b: mov    DWORD PTR [rsp+0xa4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_666:
	/* 0x666: mov    rdi,QWORD PTR [rip+0x9db] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&buffer_heap_map)));
x86_l_66d:
	/* 0x66d: lea    rsi,[rsp+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_675:
	/* 0x675: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_67a:
	/* 0x67a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_67c:
	/* 0x67c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_67f:
	/* 0x67f: je     735 <generic_usdt_process_event+0x735> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_735;
	}
x86_l_685:
	/* 0x685: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_688:
	/* 0x688: add    rax,0x1000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 4096ULL);
x86_l_68e:
	/* 0x68e: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_696:
	/* 0x696: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_69b:
	/* 0x69b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_69d:
	/* 0x69d: lea    rdx,[rax+0xd30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3376ULL);
x86_l_6a4:
	/* 0x6a4: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_6ac:
	/* 0x6ac: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6b1:
	/* 0x6b1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6b6:
	/* 0x6b6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6bb:
	/* 0x6bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6bd:
	/* 0x6bd: mov    r15,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_6c5:
	/* 0x6c5: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6ca:
	/* 0x6ca: lea    rdx,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6ce:
	/* 0x6ce: lea    rdi,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_6d6:
	/* 0x6d6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6db:
	/* 0x6db: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6e0:
	/* 0x6e0: lea    rcx,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6e4:
	/* 0x6e4: mov    QWORD PTR [rsp+0xa8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_6ec:
	/* 0x6ec: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6f1:
	/* 0x6f1: mov    QWORD PTR [rsp+0x98],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_6f9:
	/* 0x6f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6fb:
	/* 0x6fb: mov    r12,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_703:
	/* 0x703: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_708:
	/* 0x708: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_70d:
	/* 0x70d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_712:
	/* 0x712: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_717:
	/* 0x717: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_71c:
	/* 0x71c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_71e:
	/* 0x71e: cmp    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_724:
	/* 0x724: mov    eax,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4096ULL);
x86_l_729:
	/* 0x729: je     744 <generic_usdt_process_event+0x744> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_744;
	}
x86_l_72b:
	/* 0x72b: mov    rcx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_733:
	/* 0x733: jmp    79d <generic_usdt_process_event+0x79d> */
	return 1949ULL;
x86_l_735:
	/* 0x735: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_737:
	/* 0x737: mov    r13,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_73f:
	/* 0x73f: jmp    38f0 <generic_usdt_process_event+0x38f0> */
	return 14576ULL;
x86_l_744:
	/* 0x744: lea    rdx,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
	return 1865ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_generic_usdt_process_event_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1865ULL: goto x86_l_749;
	case 1870ULL: goto x86_l_74e;
	case 1875ULL: goto x86_l_753;
	case 1880ULL: goto x86_l_758;
	case 1885ULL: goto x86_l_75d;
	case 1887ULL: goto x86_l_75f;
	case 1892ULL: goto x86_l_764;
	case 1897ULL: goto x86_l_769;
	case 1905ULL: goto x86_l_771;
	case 1907ULL: goto x86_l_773;
	case 1910ULL: goto x86_l_776;
	case 1917ULL: goto x86_l_77d;
	case 1927ULL: goto x86_l_787;
	case 1934ULL: goto x86_l_78e;
	case 1944ULL: goto x86_l_798;
	case 1949ULL: goto x86_l_79d;
	case 1958ULL: goto x86_l_7a6;
	case 1967ULL: goto x86_l_7af;
	case 1972ULL: goto x86_l_7b4;
	case 1981ULL: goto x86_l_7bd;
	case 1990ULL: goto x86_l_7c6;
	case 1999ULL: goto x86_l_7cf;
	case 2007ULL: goto x86_l_7d7;
	case 2012ULL: goto x86_l_7dc;
	case 2016ULL: goto x86_l_7e0;
	case 2021ULL: goto x86_l_7e5;
	case 2025ULL: goto x86_l_7e9;
	case 2030ULL: goto x86_l_7ee;
	case 2035ULL: goto x86_l_7f3;
	case 2040ULL: goto x86_l_7f8;
	case 2045ULL: goto x86_l_7fd;
	case 2050ULL: goto x86_l_802;
	case 2055ULL: goto x86_l_807;
	case 2058ULL: goto x86_l_80a;
	case 2060ULL: goto x86_l_80c;
	case 2065ULL: goto x86_l_811;
	case 2070ULL: goto x86_l_816;
	case 2078ULL: goto x86_l_81e;
	case 2081ULL: goto x86_l_821;
	case 2086ULL: goto x86_l_826;
	case 2088ULL: goto x86_l_828;
	case 2093ULL: goto x86_l_82d;
	case 2098ULL: goto x86_l_832;
	case 2106ULL: goto x86_l_83a;
	case 2109ULL: goto x86_l_83d;
	case 2114ULL: goto x86_l_842;
	case 2116ULL: goto x86_l_844;
	case 2121ULL: goto x86_l_849;
	case 2126ULL: goto x86_l_84e;
	case 2131ULL: goto x86_l_853;
	case 2136ULL: goto x86_l_858;
	case 2141ULL: goto x86_l_85d;
	case 2143ULL: goto x86_l_85f;
	case 2148ULL: goto x86_l_864;
	case 2152ULL: goto x86_l_868;
	case 2157ULL: goto x86_l_86d;
	case 2162ULL: goto x86_l_872;
	case 2167ULL: goto x86_l_877;
	case 2169ULL: goto x86_l_879;
	case 2174ULL: goto x86_l_87e;
	case 2176ULL: goto x86_l_880;
	case 2181ULL: goto x86_l_885;
	case 2186ULL: goto x86_l_88a;
	case 2194ULL: goto x86_l_892;
	case 2197ULL: goto x86_l_895;
	case 2205ULL: goto x86_l_89d;
	case 2211ULL: goto x86_l_8a3;
	case 2213ULL: goto x86_l_8a5;
	case 2218ULL: goto x86_l_8aa;
	case 2221ULL: goto x86_l_8ad;
	case 2225ULL: goto x86_l_8b1;
	case 2231ULL: goto x86_l_8b7;
	case 2234ULL: goto x86_l_8ba;
	case 2236ULL: goto x86_l_8bc;
	case 2240ULL: goto x86_l_8c0;
	case 2243ULL: goto x86_l_8c3;
	case 2249ULL: goto x86_l_8c9;
	case 2252ULL: goto x86_l_8cc;
	case 2254ULL: goto x86_l_8ce;
	case 2258ULL: goto x86_l_8d2;
	case 2261ULL: goto x86_l_8d5;
	case 2266ULL: goto x86_l_8da;
	case 2274ULL: goto x86_l_8e2;
	case 2279ULL: goto x86_l_8e7;
	case 2284ULL: goto x86_l_8ec;
	case 2289ULL: goto x86_l_8f1;
	case 2292ULL: goto x86_l_8f4;
	case 2294ULL: goto x86_l_8f6;
	case 2302ULL: goto x86_l_8fe;
	case 2308ULL: goto x86_l_904;
	case 2313ULL: goto x86_l_909;
	case 2318ULL: goto x86_l_90e;
	case 2323ULL: goto x86_l_913;
	case 2328ULL: goto x86_l_918;
	case 2333ULL: goto x86_l_91d;
	case 2336ULL: goto x86_l_920;
	case 2338ULL: goto x86_l_922;
	case 2343ULL: goto x86_l_927;
	case 2349ULL: goto x86_l_92d;
	case 2354ULL: goto x86_l_932;
	case 2359ULL: goto x86_l_937;
	case 2364ULL: goto x86_l_93c;
	case 2369ULL: goto x86_l_941;
	case 2372ULL: goto x86_l_944;
	case 2374ULL: goto x86_l_946;
	case 2378ULL: goto x86_l_94a;
	case 2383ULL: goto x86_l_94f;
	case 2388ULL: goto x86_l_954;
	case 2393ULL: goto x86_l_959;
	case 2398ULL: goto x86_l_95e;
	case 2401ULL: goto x86_l_961;
	case 2403ULL: goto x86_l_963;
	case 2408ULL: goto x86_l_968;
	case 2413ULL: goto x86_l_96d;
	case 2418ULL: goto x86_l_972;
	case 2421ULL: goto x86_l_975;
	case 2426ULL: goto x86_l_97a;
	case 2428ULL: goto x86_l_97c;
	case 2431ULL: goto x86_l_97f;
	case 2434ULL: goto x86_l_982;
	case 2437ULL: goto x86_l_985;
	case 2445ULL: goto x86_l_98d;
	case 2447ULL: goto x86_l_98f;
	case 2450ULL: goto x86_l_992;
	case 2454ULL: goto x86_l_996;
	case 2457ULL: goto x86_l_999;
	case 2461ULL: goto x86_l_99d;
	case 2463ULL: goto x86_l_99f;
	case 2466ULL: goto x86_l_9a2;
	case 2468ULL: goto x86_l_9a4;
	case 2472ULL: goto x86_l_9a8;
	case 2475ULL: goto x86_l_9ab;
	case 2481ULL: goto x86_l_9b1;
	case 2487ULL: goto x86_l_9b7;
	case 2493ULL: goto x86_l_9bd;
	case 2496ULL: goto x86_l_9c0;
	case 2498ULL: goto x86_l_9c2;
	case 2503ULL: goto x86_l_9c7;
	case 2505ULL: goto x86_l_9c9;
	case 2508ULL: goto x86_l_9cc;
	case 2512ULL: goto x86_l_9d0;
	case 2515ULL: goto x86_l_9d3;
	case 2518ULL: goto x86_l_9d6;
	case 2521ULL: goto x86_l_9d9;
	case 2526ULL: goto x86_l_9de;
	case 2528ULL: goto x86_l_9e0;
	case 2533ULL: goto x86_l_9e5;
	case 2536ULL: goto x86_l_9e8;
	case 2542ULL: goto x86_l_9ee;
	case 2547ULL: goto x86_l_9f3;
	case 2552ULL: goto x86_l_9f8;
	case 2557ULL: goto x86_l_9fd;
	case 2562ULL: goto x86_l_a02;
	case 2567ULL: goto x86_l_a07;
	case 2575ULL: goto x86_l_a0f;
	case 2578ULL: goto x86_l_a12;
	case 2583ULL: goto x86_l_a17;
	case 2587ULL: goto x86_l_a1b;
	case 2594ULL: goto x86_l_a22;
	case 2599ULL: goto x86_l_a27;
	case 2602ULL: goto x86_l_a2a;
	case 2604ULL: goto x86_l_a2c;
	case 2607ULL: goto x86_l_a2f;
	case 2612ULL: goto x86_l_a34;
	case 2617ULL: goto x86_l_a39;
	case 2622ULL: goto x86_l_a3e;
	case 2630ULL: goto x86_l_a46;
	case 2635ULL: goto x86_l_a4b;
	case 2637ULL: goto x86_l_a4d;
	case 2642ULL: goto x86_l_a52;
	case 2646ULL: goto x86_l_a56;
	case 2651ULL: goto x86_l_a5b;
	case 2656ULL: goto x86_l_a60;
	case 2661ULL: goto x86_l_a65;
	case 2666ULL: goto x86_l_a6a;
	case 2670ULL: goto x86_l_a6e;
	case 2675ULL: goto x86_l_a73;
	case 2677ULL: goto x86_l_a75;
	case 2682ULL: goto x86_l_a7a;
	case 2687ULL: goto x86_l_a7f;
	case 2692ULL: goto x86_l_a84;
	case 2697ULL: goto x86_l_a89;
	case 2702ULL: goto x86_l_a8e;
	case 2707ULL: goto x86_l_a93;
	case 2709ULL: goto x86_l_a95;
	case 2712ULL: goto x86_l_a98;
	case 2716ULL: goto x86_l_a9c;
	case 2721ULL: goto x86_l_aa1;
	case 2726ULL: goto x86_l_aa6;
	case 2732ULL: goto x86_l_aac;
	case 2735ULL: goto x86_l_aaf;
	case 2740ULL: goto x86_l_ab4;
	case 2745ULL: goto x86_l_ab9;
	case 2750ULL: goto x86_l_abe;
	case 2754ULL: goto x86_l_ac2;
	case 2759ULL: goto x86_l_ac7;
	case 2764ULL: goto x86_l_acc;
	case 2769ULL: goto x86_l_ad1;
	case 2774ULL: goto x86_l_ad6;
	case 2776ULL: goto x86_l_ad8;
	case 2781ULL: goto x86_l_add;
	case 2786ULL: goto x86_l_ae2;
	case 2792ULL: goto x86_l_ae8;
	case 2796ULL: goto x86_l_aec;
	case 2801ULL: goto x86_l_af1;
	case 2806ULL: goto x86_l_af6;
	case 2811ULL: goto x86_l_afb;
	case 2816ULL: goto x86_l_b00;
	case 2819ULL: goto x86_l_b03;
	case 2821ULL: goto x86_l_b05;
	case 2826ULL: goto x86_l_b0a;
	case 2831ULL: goto x86_l_b0f;
	case 2835ULL: goto x86_l_b13;
	case 2840ULL: goto x86_l_b18;
	case 2845ULL: goto x86_l_b1d;
	case 2850ULL: goto x86_l_b22;
	case 2852ULL: goto x86_l_b24;
	case 2857ULL: goto x86_l_b29;
	case 2863ULL: goto x86_l_b2f;
	case 2871ULL: goto x86_l_b37;
	case 2876ULL: goto x86_l_b3c;
	case 2881ULL: goto x86_l_b41;
	case 2886ULL: goto x86_l_b46;
	case 2888ULL: goto x86_l_b48;
	case 2896ULL: goto x86_l_b50;
	case 2902ULL: goto x86_l_b56;
	case 2907ULL: goto x86_l_b5b;
	case 2912ULL: goto x86_l_b60;
	case 2917ULL: goto x86_l_b65;
	case 2922ULL: goto x86_l_b6a;
	case 2927ULL: goto x86_l_b6f;
	case 2930ULL: goto x86_l_b72;
	case 2932ULL: goto x86_l_b74;
	case 2937ULL: goto x86_l_b79;
	case 2943ULL: goto x86_l_b7f;
	case 2948ULL: goto x86_l_b84;
	case 2953ULL: goto x86_l_b89;
	case 2958ULL: goto x86_l_b8e;
	case 2963ULL: goto x86_l_b93;
	case 2966ULL: goto x86_l_b96;
	case 2968ULL: goto x86_l_b98;
	case 2972ULL: goto x86_l_b9c;
	case 2977ULL: goto x86_l_ba1;
	case 2982ULL: goto x86_l_ba6;
	case 2987ULL: goto x86_l_bab;
	case 2992ULL: goto x86_l_bb0;
	case 2995ULL: goto x86_l_bb3;
	case 2997ULL: goto x86_l_bb5;
	case 3002ULL: goto x86_l_bba;
	case 3007ULL: goto x86_l_bbf;
	case 3012ULL: goto x86_l_bc4;
	case 3015ULL: goto x86_l_bc7;
	case 3020ULL: goto x86_l_bcc;
	case 3022ULL: goto x86_l_bce;
	case 3025ULL: goto x86_l_bd1;
	case 3028ULL: goto x86_l_bd4;
	case 3031ULL: goto x86_l_bd7;
	case 3039ULL: goto x86_l_bdf;
	case 3041ULL: goto x86_l_be1;
	case 3044ULL: goto x86_l_be4;
	case 3048ULL: goto x86_l_be8;
	case 3051ULL: goto x86_l_beb;
	case 3055ULL: goto x86_l_bef;
	case 3057ULL: goto x86_l_bf1;
	case 3060ULL: goto x86_l_bf4;
	case 3062ULL: goto x86_l_bf6;
	case 3066ULL: goto x86_l_bfa;
	case 3069ULL: goto x86_l_bfd;
	case 3075ULL: goto x86_l_c03;
	case 3081ULL: goto x86_l_c09;
	case 3087ULL: goto x86_l_c0f;
	case 3090ULL: goto x86_l_c12;
	case 3092ULL: goto x86_l_c14;
	case 3097ULL: goto x86_l_c19;
	case 3099ULL: goto x86_l_c1b;
	case 3102ULL: goto x86_l_c1e;
	case 3106ULL: goto x86_l_c22;
	case 3109ULL: goto x86_l_c25;
	case 3112ULL: goto x86_l_c28;
	case 3115ULL: goto x86_l_c2b;
	case 3120ULL: goto x86_l_c30;
	case 3122ULL: goto x86_l_c32;
	case 3127ULL: goto x86_l_c37;
	case 3130ULL: goto x86_l_c3a;
	case 3136ULL: goto x86_l_c40;
	case 3141ULL: goto x86_l_c45;
	case 3146ULL: goto x86_l_c4a;
	case 3151ULL: goto x86_l_c4f;
	case 3156ULL: goto x86_l_c54;
	case 3161ULL: goto x86_l_c59;
	case 3163ULL: goto x86_l_c5b;
	case 3168ULL: goto x86_l_c60;
	case 3172ULL: goto x86_l_c64;
	case 3177ULL: goto x86_l_c69;
	case 3182ULL: goto x86_l_c6e;
	case 3188ULL: goto x86_l_c74;
	case 3192ULL: goto x86_l_c78;
	case 3195ULL: goto x86_l_c7b;
	case 3201ULL: goto x86_l_c81;
	case 3205ULL: goto x86_l_c85;
	case 3208ULL: goto x86_l_c88;
	case 3214ULL: goto x86_l_c8e;
	case 3218ULL: goto x86_l_c92;
	case 3224ULL: goto x86_l_c98;
	case 3229ULL: goto x86_l_c9d;
	case 3234ULL: goto x86_l_ca2;
	case 3238ULL: goto x86_l_ca6;
	case 3242ULL: goto x86_l_caa;
	case 3247ULL: goto x86_l_caf;
	case 3252ULL: goto x86_l_cb4;
	case 3257ULL: goto x86_l_cb9;
	case 3262ULL: goto x86_l_cbe;
	case 3264ULL: goto x86_l_cc0;
	case 3268ULL: goto x86_l_cc4;
	case 3273ULL: goto x86_l_cc9;
	case 3278ULL: goto x86_l_cce;
	case 3283ULL: goto x86_l_cd3;
	case 3288ULL: goto x86_l_cd8;
	case 3290ULL: goto x86_l_cda;
	case 3294ULL: goto x86_l_cde;
	case 3302ULL: goto x86_l_ce6;
	case 3307ULL: goto x86_l_ceb;
	case 3312ULL: goto x86_l_cf0;
	case 3317ULL: goto x86_l_cf5;
	case 3319ULL: goto x86_l_cf7;
	case 3323ULL: goto x86_l_cfb;
	case 3331ULL: goto x86_l_d03;
	case 3336ULL: goto x86_l_d08;
	case 3341ULL: goto x86_l_d0d;
	case 3346ULL: goto x86_l_d12;
	case 3348ULL: goto x86_l_d14;
	case 3352ULL: goto x86_l_d18;
	case 3360ULL: goto x86_l_d20;
	case 3365ULL: goto x86_l_d25;
	case 3370ULL: goto x86_l_d2a;
	case 3375ULL: goto x86_l_d2f;
	case 3377ULL: goto x86_l_d31;
	case 3381ULL: goto x86_l_d35;
	case 3389ULL: goto x86_l_d3d;
	case 3394ULL: goto x86_l_d42;
	case 3399ULL: goto x86_l_d47;
	case 3404ULL: goto x86_l_d4c;
	case 3406ULL: goto x86_l_d4e;
	case 3410ULL: goto x86_l_d52;
	case 3418ULL: goto x86_l_d5a;
	case 3426ULL: goto x86_l_d62;
	case 3434ULL: goto x86_l_d6a;
	case 3442ULL: goto x86_l_d72;
	case 3447ULL: goto x86_l_d77;
	case 3450ULL: goto x86_l_d7a;
	case 3456ULL: goto x86_l_d80;
	case 3459ULL: goto x86_l_d83;
	case 3465ULL: goto x86_l_d89;
	case 3470ULL: goto x86_l_d8e;
	case 3475ULL: goto x86_l_d93;
	case 3480ULL: goto x86_l_d98;
	case 3485ULL: goto x86_l_d9d;
	case 3490ULL: goto x86_l_da2;
	case 3492ULL: goto x86_l_da4;
	case 3497ULL: goto x86_l_da9;
	case 3502ULL: goto x86_l_dae;
	case 3505ULL: goto x86_l_db1;
	case 3510ULL: goto x86_l_db6;
	case 3513ULL: goto x86_l_db9;
	case 3518ULL: goto x86_l_dbe;
	case 3522ULL: goto x86_l_dc2;
	case 3528ULL: goto x86_l_dc8;
	case 3532ULL: goto x86_l_dcc;
	case 3535ULL: goto x86_l_dcf;
	case 3541ULL: goto x86_l_dd5;
	case 3546ULL: goto x86_l_dda;
	case 3551ULL: goto x86_l_ddf;
	case 3556ULL: goto x86_l_de4;
	case 3561ULL: goto x86_l_de9;
	case 3566ULL: goto x86_l_dee;
	case 3571ULL: goto x86_l_df3;
	case 3575ULL: goto x86_l_df7;
	case 3580ULL: goto x86_l_dfc;
	case 3585ULL: goto x86_l_e01;
	case 3590ULL: goto x86_l_e06;
	case 3595ULL: goto x86_l_e0b;
	case 3597ULL: goto x86_l_e0d;
	case 3602ULL: goto x86_l_e12;
	case 3607ULL: goto x86_l_e17;
	default: return 0xffffffffffffffffULL;
	}
x86_l_749:
	/* 0x749: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_74e:
	/* 0x74e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_753:
	/* 0x753: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_758:
	/* 0x758: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_75d:
	/* 0x75d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_75f:
	/* 0x75f: mov    eax,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4096ULL);
x86_l_764:
	/* 0x764: cmp    QWORD PTR [rsp+0x38],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_769:
	/* 0x769: mov    rcx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_771:
	/* 0x771: je     79d <generic_usdt_process_event+0x79d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_79d;
	}
x86_l_773:
	/* 0x773: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_776:
	/* 0x776: add    rcx,0xff6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4086ULL);
x86_l_77d:
	/* 0x77d: movabs rax,0x6574656c65642820 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310579611361093664ULL);
x86_l_787:
	/* 0x787: mov    QWORD PTR [r13+0xff6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_78e:
	/* 0x78e: mov    WORD PTR [r13+0xffe],0x2964 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17583596120420ULL);
x86_l_798:
	/* 0x798: mov    eax,0xff6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4086ULL);
x86_l_79d:
	/* 0x79d: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_7a6:
	/* 0x7a6: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_7af:
	/* 0x7af: mov    QWORD PTR [rsp+0x48],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_7b4:
	/* 0x7b4: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_7bd:
	/* 0x7bd: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_7c6:
	/* 0x7c6: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_7cf:
	/* 0x7cf: mov    QWORD PTR [rsp+0x88],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_7d7:
	/* 0x7d7: mov    QWORD PTR [rsp+0x68],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_7dc:
	/* 0x7dc: mov    DWORD PTR [rsp+0x70],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_7e0:
	/* 0x7e0: mov    BYTE PTR [rsp+0x74],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 498216206336ULL);
x86_l_7e5:
	/* 0x7e5: add    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_7e9:
	/* 0x7e9: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_7ee:
	/* 0x7ee: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_7f3:
	/* 0x7f3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_7f8:
	/* 0x7f8: lea    r13,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_7fd:
	/* 0x7fd: lea    r12,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_802:
	/* 0x802: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_807:
	/* 0x807: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_80a:
	/* 0x80a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_80c:
	/* 0x80c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_811:
	/* 0x811: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_816:
	/* 0x816: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_81e:
	/* 0x81e: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_821:
	/* 0x821: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_826:
	/* 0x826: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_828:
	/* 0x828: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_82d:
	/* 0x82d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_832:
	/* 0x832: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_83a:
	/* 0x83a: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_83d:
	/* 0x83d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_842:
	/* 0x842: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_844:
	/* 0x844: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_849:
	/* 0x849: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_84e:
	/* 0x84e: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_853:
	/* 0x853: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_858:
	/* 0x858: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_85d:
	/* 0x85d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_85f:
	/* 0x85f: mov    r15,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_864:
	/* 0x864: lea    rax,[r15-0x20] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551584ULL);
x86_l_868:
	/* 0x868: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_86d:
	/* 0x86d: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_872:
	/* 0x872: cmp    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_877:
	/* 0x877: jne    8da <generic_usdt_process_event+0x8da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8da;
	}
x86_l_879:
	/* 0x879: cmp    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_87e:
	/* 0x87e: jne    8da <generic_usdt_process_event+0x8da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8da;
	}
x86_l_880:
	/* 0x880: mov    BYTE PTR [rsp+0x74],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 498216206337ULL);
x86_l_885:
	/* 0x885: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_88a:
	/* 0x88a: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_892:
	/* 0x892: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_895:
	/* 0x895: mov    r13,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_89d:
	/* 0x89d: je     a07 <generic_usdt_process_event+0xa07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a07;
	}
x86_l_8a3:
	/* 0x8a3: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8a5:
	/* 0x8a5: cmp    BYTE PTR [rsp+0x74],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 498216206336ULL);
x86_l_8aa:
	/* 0x8aa: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_8ad:
	/* 0x8ad: mov    edx,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_8b1:
	/* 0x8b1: mov    r12d,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4096ULL);
x86_l_8b7:
	/* 0x8b7: sub    r12d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_8ba:
	/* 0x8ba: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_8bc:
	/* 0x8bc: cmovle r12d,edx */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RDX, X86_WIDTH_32, X86_CC_LE);
x86_l_8c0:
	/* 0x8c0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8c3:
	/* 0x8c3: je     c59 <generic_usdt_process_event+0xc59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c59;
	}
x86_l_8c9:
	/* 0x8c9: mov    sil,cl */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RCX, X86_WIDTH_8);
x86_l_8cc:
	/* 0x8cc: add    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_8ce:
	/* 0x8ce: mov    DWORD PTR [rsp+0x30],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8d2:
	/* 0x8d2: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_8d5:
	/* 0x8d5: jmp    a12 <generic_usdt_process_event+0xa12> */
	goto x86_l_a12;
x86_l_8da:
	/* 0x8da: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_8e2:
	/* 0x8e2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_8e7:
	/* 0x8e7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_8ec:
	/* 0x8ec: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8f1:
	/* 0x8f1: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_8f4:
	/* 0x8f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8f6:
	/* 0x8f6: cmp    r12,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 144ULL);
x86_l_8fe:
	/* 0x8fe: je     abe <generic_usdt_process_event+0xabe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_abe;
	}
x86_l_904:
	/* 0x904: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_909:
	/* 0x909: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_90e:
	/* 0x90e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_913:
	/* 0x913: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_918:
	/* 0x918: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_91d:
	/* 0x91d: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_920:
	/* 0x920: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_922:
	/* 0x922: cmp    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_927:
	/* 0x927: je     abe <generic_usdt_process_event+0xabe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_abe;
	}
x86_l_92d:
	/* 0x92d: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_932:
	/* 0x932: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_937:
	/* 0x937: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_93c:
	/* 0x93c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_941:
	/* 0x941: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_944:
	/* 0x944: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_946:
	/* 0x946: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_94a:
	/* 0x94a: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_94f:
	/* 0x94f: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_954:
	/* 0x954: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_959:
	/* 0x959: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_95e:
	/* 0x95e: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_961:
	/* 0x961: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_963:
	/* 0x963: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_968:
	/* 0x968: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_96d:
	/* 0x96d: mov    r12d,DWORD PTR [rsp+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_972:
	/* 0x972: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_975:
	/* 0x975: mov    r13d,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_97a:
	/* 0x97a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_97c:
	/* 0x97c: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_97f:
	/* 0x97f: sub    edx,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R13, X86_WIDTH_32, X86_ALU_SUB);
x86_l_982:
	/* 0x982: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_985:
	/* 0x985: add    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 128ULL);
x86_l_98d:
	/* 0x98d: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_98f:
	/* 0x98f: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_992:
	/* 0x992: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_996:
	/* 0x996: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_999:
	/* 0x999: cmovb  ecx,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_99d:
	/* 0x99d: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_99f:
	/* 0x99f: mov    edi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_32);
x86_l_9a2:
	/* 0x9a2: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_9a4:
	/* 0x9a4: mov    DWORD PTR [rsp+0x70],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_9a8:
	/* 0x9a8: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_9ab:
	/* 0x9ab: jb     885 <generic_usdt_process_event+0x885> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_885;
	}
x86_l_9b1:
	/* 0x9b1: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_9b7:
	/* 0x9b7: ja     885 <generic_usdt_process_event+0x885> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_885;
	}
x86_l_9bd:
	/* 0x9bd: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_9c0:
	/* 0x9c0: jbe    9c7 <generic_usdt_process_event+0x9c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_9c7;
	}
x86_l_9c2:
	/* 0x9c2: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_9c7:
	/* 0x9c7: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9c9:
	/* 0x9c9: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_9cc:
	/* 0x9cc: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_9d0:
	/* 0x9d0: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_9d3:
	/* 0x9d3: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_9d6:
	/* 0x9d6: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_9d9:
	/* 0x9d9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_9de:
	/* 0x9de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9e0:
	/* 0x9e0: mov    QWORD PTR [rsp+0x68],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_9e5:
	/* 0x9e5: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_9e8:
	/* 0x9e8: jbe    885 <generic_usdt_process_event+0x885> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_885;
	}
x86_l_9ee:
	/* 0x9ee: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_9f3:
	/* 0x9f3: mov    QWORD PTR [rsp+0x50],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_9f8:
	/* 0x9f8: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_9fd:
	/* 0x9fd: mov    r15,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_a02:
	/* 0xa02: jmp    b1d <generic_usdt_process_event+0xb1d> */
	goto x86_l_b1d;
x86_l_a07:
	/* 0xa07: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_a0f:
	/* 0xa0f: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a12:
	/* 0xa12: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a17:
	/* 0xa17: lea    rdi,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_a1b:
	/* 0xa1b: and    r12d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a22:
	/* 0xa22: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a27:
	/* 0xa27: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_a2a:
	/* 0xa2a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a2c:
	/* 0xa2c: mov    DWORD PTR [r15],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a2f:
	/* 0xa2f: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_a34:
	/* 0xa34: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a39:
	/* 0xa39: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a3e:
	/* 0xa3e: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_a46:
	/* 0xa46: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a4b:
	/* 0xa4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a4d:
	/* 0xa4d: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_a52:
	/* 0xa52: add    rcx,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_a56:
	/* 0xa56: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_a5b:
	/* 0xa5b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_a60:
	/* 0xa60: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a65:
	/* 0xa65: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_a6a:
	/* 0xa6a: add    rdx,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_a6e:
	/* 0xa6e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a73:
	/* 0xa73: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a75:
	/* 0xa75: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_a7a:
	/* 0xa7a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a7f:
	/* 0xa7f: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_a84:
	/* 0xa84: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a89:
	/* 0xa89: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_a8e:
	/* 0xa8e: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_a93:
	/* 0xa93: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a95:
	/* 0xa95: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_a98:
	/* 0xa98: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a9c:
	/* 0xa9c: mov    DWORD PTR [r15+r12*1+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 4ULL);
x86_l_aa1:
	/* 0xaa1: movzx  eax,WORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_aa6:
	/* 0xaa6: mov    WORD PTR [r15+r12*1+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 8ULL);
x86_l_aac:
	/* 0xaac: add    esi,0xa */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 10ULL);
x86_l_aaf:
	/* 0xaaf: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ab4:
	/* 0xab4: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_ab9:
	/* 0xab9: jmp    38ec <generic_usdt_process_event+0x38ec> */
	return 14572ULL;
x86_l_abe:
	/* 0xabe: lea    rdx,[r15-0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551600ULL);
x86_l_ac2:
	/* 0xac2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ac7:
	/* 0xac7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_acc:
	/* 0xacc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ad1:
	/* 0xad1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ad6:
	/* 0xad6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ad8:
	/* 0xad8: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_add:
	/* 0xadd: cmp    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_ae2:
	/* 0xae2: je     880 <generic_usdt_process_event+0x880> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_880;
	}
x86_l_ae8:
	/* 0xae8: add    r15,0xfffffffffffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551608ULL);
x86_l_aec:
	/* 0xaec: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_af1:
	/* 0xaf1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_af6:
	/* 0xaf6: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_afb:
	/* 0xafb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b00:
	/* 0xb00: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_b03:
	/* 0xb03: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b05:
	/* 0xb05: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b0a:
	/* 0xb0a: mov    QWORD PTR [rsp+0x60],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_b0f:
	/* 0xb0f: lea    rdx,[r15+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b13:
	/* 0xb13: mov    QWORD PTR [rsp+0x58],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_b18:
	/* 0xb18: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_b1d:
	/* 0xb1d: cmp    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_b22:
	/* 0xb22: jne    b2f <generic_usdt_process_event+0xb2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b2f;
	}
x86_l_b24:
	/* 0xb24: cmp    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_b29:
	/* 0xb29: je     880 <generic_usdt_process_event+0x880> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_880;
	}
x86_l_b2f:
	/* 0xb2f: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_b37:
	/* 0xb37: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b3c:
	/* 0xb3c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b41:
	/* 0xb41: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b46:
	/* 0xb46: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b48:
	/* 0xb48: cmp    r12,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 144ULL);
x86_l_b50:
	/* 0xb50: je     df3 <generic_usdt_process_event+0xdf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_df3;
	}
x86_l_b56:
	/* 0xb56: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b5b:
	/* 0xb5b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b60:
	/* 0xb60: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b65:
	/* 0xb65: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b6a:
	/* 0xb6a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b6f:
	/* 0xb6f: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_b72:
	/* 0xb72: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b74:
	/* 0xb74: cmp    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b79:
	/* 0xb79: je     df3 <generic_usdt_process_event+0xdf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_df3;
	}
x86_l_b7f:
	/* 0xb7f: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b84:
	/* 0xb84: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b89:
	/* 0xb89: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b8e:
	/* 0xb8e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b93:
	/* 0xb93: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_b96:
	/* 0xb96: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b98:
	/* 0xb98: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_b9c:
	/* 0xb9c: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_ba1:
	/* 0xba1: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_ba6:
	/* 0xba6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_bab:
	/* 0xbab: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_bb0:
	/* 0xbb0: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_bb3:
	/* 0xbb3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bb5:
	/* 0xbb5: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_bba:
	/* 0xbba: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_bbf:
	/* 0xbbf: mov    r12d,DWORD PTR [rsp+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_bc4:
	/* 0xbc4: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_bc7:
	/* 0xbc7: mov    r13d,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_bcc:
	/* 0xbcc: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bce:
	/* 0xbce: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_bd1:
	/* 0xbd1: sub    edx,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R13, X86_WIDTH_32, X86_ALU_SUB);
x86_l_bd4:
	/* 0xbd4: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_bd7:
	/* 0xbd7: add    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 128ULL);
x86_l_bdf:
	/* 0xbdf: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_be1:
	/* 0xbe1: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_be4:
	/* 0xbe4: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_be8:
	/* 0xbe8: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_beb:
	/* 0xbeb: cmovb  ecx,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_bef:
	/* 0xbef: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_bf1:
	/* 0xbf1: mov    edi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_32);
x86_l_bf4:
	/* 0xbf4: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_bf6:
	/* 0xbf6: mov    DWORD PTR [rsp+0x70],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_bfa:
	/* 0xbfa: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_bfd:
	/* 0xbfd: jb     885 <generic_usdt_process_event+0x885> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_885;
	}
x86_l_c03:
	/* 0xc03: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_c09:
	/* 0xc09: ja     885 <generic_usdt_process_event+0x885> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_885;
	}
x86_l_c0f:
	/* 0xc0f: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_c12:
	/* 0xc12: jbe    c19 <generic_usdt_process_event+0xc19> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_c19;
	}
x86_l_c14:
	/* 0xc14: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_c19:
	/* 0xc19: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c1b:
	/* 0xc1b: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_c1e:
	/* 0xc1e: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_c22:
	/* 0xc22: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_c25:
	/* 0xc25: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_c28:
	/* 0xc28: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_c2b:
	/* 0xc2b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c30:
	/* 0xc30: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c32:
	/* 0xc32: mov    QWORD PTR [rsp+0x68],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_c37:
	/* 0xc37: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_c3a:
	/* 0xc3a: jbe    885 <generic_usdt_process_event+0x885> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_885;
	}
x86_l_c40:
	/* 0xc40: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c45:
	/* 0xc45: mov    QWORD PTR [rsp+0x50],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_c4a:
	/* 0xc4a: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_c4f:
	/* 0xc4f: mov    r15,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_c54:
	/* 0xc54: jmp    e52 <generic_usdt_process_event+0xe52> */
	return 3666ULL;
x86_l_c59:
	/* 0xc59: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c5b:
	/* 0xc5b: jmp    38f0 <generic_usdt_process_event+0x38f0> */
	return 14576ULL;
x86_l_c60:
	/* 0xc60: cmp    r13d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 6ULL);
x86_l_c64:
	/* 0xc64: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c69:
	/* 0xc69: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_c6e:
	/* 0xc6e: jle    f8e <generic_usdt_process_event+0xf8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3982ULL;
	}
x86_l_c74:
	/* 0xc74: lea    ecx,[r13-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_c78:
	/* 0xc78: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_c7b:
	/* 0xc7b: jb     fa8 <generic_usdt_process_event+0xfa8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 4008ULL;
	}
x86_l_c81:
	/* 0xc81: lea    ecx,[r13-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_c85:
	/* 0xc85: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_c88:
	/* 0xc88: jb     1007 <generic_usdt_process_event+0x1007> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 4103ULL;
	}
x86_l_c8e:
	/* 0xc8e: cmp    r13d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 7ULL);
x86_l_c92:
	/* 0xc92: jne    38e4 <generic_usdt_process_event+0x38e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14564ULL;
	}
x86_l_c98:
	/* 0xc98: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c9d:
	/* 0xc9d: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ca2:
	/* 0xca2: mov    QWORD PTR [r13+0x28],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ca6:
	/* 0xca6: lea    rdi,[r13+0x26] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_caa:
	/* 0xcaa: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_caf:
	/* 0xcaf: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_cb4:
	/* 0xcb4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_cb9:
	/* 0xcb9: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_cbe:
	/* 0xcbe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cc0:
	/* 0xcc0: lea    rdi,[r13+0x3a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_cc4:
	/* 0xcc4: lea    rdx,[r12+0x12] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_cc9:
	/* 0xcc9: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_cce:
	/* 0xcce: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_cd3:
	/* 0xcd3: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_cd8:
	/* 0xcd8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cda:
	/* 0xcda: lea    rdi,[r13+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_cde:
	/* 0xcde: lea    rdx,[r12+0x23c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_ce6:
	/* 0xce6: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_ceb:
	/* 0xceb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_cf0:
	/* 0xcf0: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_cf5:
	/* 0xcf5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cf7:
	/* 0xcf7: lea    rdi,[r13+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_cfb:
	/* 0xcfb: lea    rdx,[r12+0x23e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 574ULL);
x86_l_d03:
	/* 0xd03: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_d08:
	/* 0xd08: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d0d:
	/* 0xd0d: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_d12:
	/* 0xd12: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d14:
	/* 0xd14: lea    rdi,[r13+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d18:
	/* 0xd18: lea    rdx,[r12+0x20c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_d20:
	/* 0xd20: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_d25:
	/* 0xd25: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d2a:
	/* 0xd2a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d2f:
	/* 0xd2f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d31:
	/* 0xd31: lea    rdi,[r13+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_d35:
	/* 0xd35: lea    rdx,[r12+0x208] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_d3d:
	/* 0xd3d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_d42:
	/* 0xd42: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d47:
	/* 0xd47: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d4c:
	/* 0xd4c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d4e:
	/* 0xd4e: lea    r15,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d52:
	/* 0xd52: mov    QWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d5a:
	/* 0xd5a: mov    QWORD PTR [r13+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_d62:
	/* 0xd62: mov    QWORD PTR [r13+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_d6a:
	/* 0xd6a: mov    QWORD PTR [r13+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_d72:
	/* 0xd72: movzx  eax,WORD PTR [r13+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_d77:
	/* 0xd77: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_d7a:
	/* 0xd7a: je     1ff5 <generic_usdt_process_event+0x1ff5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8181ULL;
	}
x86_l_d80:
	/* 0xd80: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d83:
	/* 0xd83: jne    2029 <generic_usdt_process_event+0x2029> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8233ULL;
	}
x86_l_d89:
	/* 0xd89: lea    rdx,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_d8e:
	/* 0xd8e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_d93:
	/* 0xd93: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d98:
	/* 0xd98: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d9d:
	/* 0xd9d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_da2:
	/* 0xda2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_da4:
	/* 0xda4: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_da9:
	/* 0xda9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_dae:
	/* 0xdae: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_db1:
	/* 0xdb1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_db6:
	/* 0xdb6: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_db9:
	/* 0xdb9: jmp    2027 <generic_usdt_process_event+0x2027> */
	return 8231ULL;
x86_l_dbe:
	/* 0xdbe: cmp    r13d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 38ULL);
x86_l_dc2:
	/* 0xdc2: jg     1075 <generic_usdt_process_event+0x1075> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 4213ULL;
	}
x86_l_dc8:
	/* 0xdc8: lea    eax,[r13-0x1f] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551585ULL);
x86_l_dcc:
	/* 0xdcc: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_dcf:
	/* 0xdcf: jae    1195 <generic_usdt_process_event+0x1195> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4501ULL;
	}
x86_l_dd5:
	/* 0xdd5: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_dda:
	/* 0xdda: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_ddf:
	/* 0xddf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_de4:
	/* 0xde4: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_de9:
	/* 0xde9: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_dee:
	/* 0xdee: jmp    1069 <generic_usdt_process_event+0x1069> */
	return 4201ULL;
x86_l_df3:
	/* 0xdf3: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_df7:
	/* 0xdf7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dfc:
	/* 0xdfc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_e01:
	/* 0xe01: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e06:
	/* 0xe06: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e0b:
	/* 0xe0b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e0d:
	/* 0xe0d: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_e12:
	/* 0xe12: cmp    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_e17:
	/* 0xe17: je     880 <generic_usdt_process_event+0x880> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_880;
	}
	return 3613ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_generic_usdt_process_event_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3613ULL: goto x86_l_e1d;
	case 3617ULL: goto x86_l_e21;
	case 3622ULL: goto x86_l_e26;
	case 3627ULL: goto x86_l_e2b;
	case 3632ULL: goto x86_l_e30;
	case 3637ULL: goto x86_l_e35;
	case 3640ULL: goto x86_l_e38;
	case 3642ULL: goto x86_l_e3a;
	case 3647ULL: goto x86_l_e3f;
	case 3652ULL: goto x86_l_e44;
	case 3656ULL: goto x86_l_e48;
	case 3661ULL: goto x86_l_e4d;
	case 3666ULL: goto x86_l_e52;
	case 3671ULL: goto x86_l_e57;
	case 3673ULL: goto x86_l_e59;
	case 3678ULL: goto x86_l_e5e;
	case 3684ULL: goto x86_l_e64;
	case 3692ULL: goto x86_l_e6c;
	case 3697ULL: goto x86_l_e71;
	case 3702ULL: goto x86_l_e76;
	case 3707ULL: goto x86_l_e7b;
	case 3709ULL: goto x86_l_e7d;
	case 3717ULL: goto x86_l_e85;
	case 3723ULL: goto x86_l_e8b;
	case 3728ULL: goto x86_l_e90;
	case 3733ULL: goto x86_l_e95;
	case 3738ULL: goto x86_l_e9a;
	case 3743ULL: goto x86_l_e9f;
	case 3748ULL: goto x86_l_ea4;
	case 3751ULL: goto x86_l_ea7;
	case 3753ULL: goto x86_l_ea9;
	case 3758ULL: goto x86_l_eae;
	case 3764ULL: goto x86_l_eb4;
	case 3769ULL: goto x86_l_eb9;
	case 3774ULL: goto x86_l_ebe;
	case 3779ULL: goto x86_l_ec3;
	case 3784ULL: goto x86_l_ec8;
	case 3787ULL: goto x86_l_ecb;
	case 3789ULL: goto x86_l_ecd;
	case 3793ULL: goto x86_l_ed1;
	case 3798ULL: goto x86_l_ed6;
	case 3803ULL: goto x86_l_edb;
	case 3808ULL: goto x86_l_ee0;
	case 3813ULL: goto x86_l_ee5;
	case 3816ULL: goto x86_l_ee8;
	case 3818ULL: goto x86_l_eea;
	case 3823ULL: goto x86_l_eef;
	case 3828ULL: goto x86_l_ef4;
	case 3833ULL: goto x86_l_ef9;
	case 3836ULL: goto x86_l_efc;
	case 3841ULL: goto x86_l_f01;
	case 3843ULL: goto x86_l_f03;
	case 3846ULL: goto x86_l_f06;
	case 3849ULL: goto x86_l_f09;
	case 3852ULL: goto x86_l_f0c;
	case 3860ULL: goto x86_l_f14;
	case 3862ULL: goto x86_l_f16;
	case 3865ULL: goto x86_l_f19;
	case 3869ULL: goto x86_l_f1d;
	case 3872ULL: goto x86_l_f20;
	case 3876ULL: goto x86_l_f24;
	case 3878ULL: goto x86_l_f26;
	case 3881ULL: goto x86_l_f29;
	case 3883ULL: goto x86_l_f2b;
	case 3887ULL: goto x86_l_f2f;
	case 3890ULL: goto x86_l_f32;
	case 3896ULL: goto x86_l_f38;
	case 3902ULL: goto x86_l_f3e;
	case 3908ULL: goto x86_l_f44;
	case 3911ULL: goto x86_l_f47;
	case 3913ULL: goto x86_l_f49;
	case 3918ULL: goto x86_l_f4e;
	case 3920ULL: goto x86_l_f50;
	case 3923ULL: goto x86_l_f53;
	case 3927ULL: goto x86_l_f57;
	case 3930ULL: goto x86_l_f5a;
	case 3933ULL: goto x86_l_f5d;
	case 3936ULL: goto x86_l_f60;
	case 3941ULL: goto x86_l_f65;
	case 3943ULL: goto x86_l_f67;
	case 3948ULL: goto x86_l_f6c;
	case 3951ULL: goto x86_l_f6f;
	case 3957ULL: goto x86_l_f75;
	case 3962ULL: goto x86_l_f7a;
	case 3967ULL: goto x86_l_f7f;
	case 3972ULL: goto x86_l_f84;
	case 3977ULL: goto x86_l_f89;
	case 3982ULL: goto x86_l_f8e;
	case 3986ULL: goto x86_l_f92;
	case 3992ULL: goto x86_l_f98;
	case 3996ULL: goto x86_l_f9c;
	case 3998ULL: goto x86_l_f9e;
	case 4002ULL: goto x86_l_fa2;
	case 4008ULL: goto x86_l_fa8;
	case 4013ULL: goto x86_l_fad;
	case 4018ULL: goto x86_l_fb2;
	case 4021ULL: goto x86_l_fb5;
	case 4026ULL: goto x86_l_fba;
	case 4031ULL: goto x86_l_fbf;
	case 4036ULL: goto x86_l_fc4;
	case 4038ULL: goto x86_l_fc6;
	case 4043ULL: goto x86_l_fcb;
	case 4045ULL: goto x86_l_fcd;
	case 4049ULL: goto x86_l_fd1;
	case 4055ULL: goto x86_l_fd7;
	case 4059ULL: goto x86_l_fdb;
	case 4062ULL: goto x86_l_fde;
	case 4068ULL: goto x86_l_fe4;
	case 4073ULL: goto x86_l_fe9;
	case 4078ULL: goto x86_l_fee;
	case 4083ULL: goto x86_l_ff3;
	case 4088ULL: goto x86_l_ff8;
	case 4091ULL: goto x86_l_ffb;
	case 4093ULL: goto x86_l_ffd;
	case 4098ULL: goto x86_l_1002;
	case 4103ULL: goto x86_l_1007;
	case 4108ULL: goto x86_l_100c;
	case 4113ULL: goto x86_l_1011;
	case 4116ULL: goto x86_l_1014;
	case 4121ULL: goto x86_l_1019;
	case 4126ULL: goto x86_l_101e;
	case 4131ULL: goto x86_l_1023;
	case 4133ULL: goto x86_l_1025;
	case 4138ULL: goto x86_l_102a;
	case 4143ULL: goto x86_l_102f;
	case 4146ULL: goto x86_l_1032;
	case 4151ULL: goto x86_l_1037;
	case 4155ULL: goto x86_l_103b;
	case 4161ULL: goto x86_l_1041;
	case 4165ULL: goto x86_l_1045;
	case 4171ULL: goto x86_l_104b;
	case 4176ULL: goto x86_l_1050;
	case 4181ULL: goto x86_l_1055;
	case 4186ULL: goto x86_l_105a;
	case 4191ULL: goto x86_l_105f;
	case 4196ULL: goto x86_l_1064;
	case 4201ULL: goto x86_l_1069;
	case 4203ULL: goto x86_l_106b;
	case 4208ULL: goto x86_l_1070;
	case 4213ULL: goto x86_l_1075;
	case 4217ULL: goto x86_l_1079;
	case 4223ULL: goto x86_l_107f;
	case 4227ULL: goto x86_l_1083;
	case 4232ULL: goto x86_l_1088;
	case 4237ULL: goto x86_l_108d;
	case 4243ULL: goto x86_l_1093;
	case 4246ULL: goto x86_l_1096;
	case 4251ULL: goto x86_l_109b;
	case 4256ULL: goto x86_l_10a0;
	case 4264ULL: goto x86_l_10a8;
	case 4272ULL: goto x86_l_10b0;
	case 4280ULL: goto x86_l_10b8;
	case 4285ULL: goto x86_l_10bd;
	case 4290ULL: goto x86_l_10c2;
	case 4293ULL: goto x86_l_10c5;
	case 4298ULL: goto x86_l_10ca;
	case 4301ULL: goto x86_l_10cd;
	case 4303ULL: goto x86_l_10cf;
	case 4306ULL: goto x86_l_10d2;
	case 4312ULL: goto x86_l_10d8;
	case 4317ULL: goto x86_l_10dd;
	case 4320ULL: goto x86_l_10e0;
	case 4326ULL: goto x86_l_10e6;
	case 4329ULL: goto x86_l_10e9;
	case 4335ULL: goto x86_l_10ef;
	case 4339ULL: goto x86_l_10f3;
	case 4344ULL: goto x86_l_10f8;
	case 4349ULL: goto x86_l_10fd;
	case 4354ULL: goto x86_l_1102;
	case 4359ULL: goto x86_l_1107;
	case 4361ULL: goto x86_l_1109;
	case 4365ULL: goto x86_l_110d;
	case 4369ULL: goto x86_l_1111;
	case 4373ULL: goto x86_l_1115;
	case 4377ULL: goto x86_l_1119;
	case 4382ULL: goto x86_l_111e;
	case 4387ULL: goto x86_l_1123;
	case 4392ULL: goto x86_l_1128;
	case 4395ULL: goto x86_l_112b;
	case 4399ULL: goto x86_l_112f;
	case 4405ULL: goto x86_l_1135;
	case 4409ULL: goto x86_l_1139;
	case 4415ULL: goto x86_l_113f;
	case 4418ULL: goto x86_l_1142;
	case 4422ULL: goto x86_l_1146;
	case 4427ULL: goto x86_l_114b;
	case 4432ULL: goto x86_l_1150;
	case 4438ULL: goto x86_l_1156;
	case 4446ULL: goto x86_l_115e;
	case 4448ULL: goto x86_l_1160;
	case 4451ULL: goto x86_l_1163;
	case 4454ULL: goto x86_l_1166;
	case 4460ULL: goto x86_l_116c;
	case 4463ULL: goto x86_l_116f;
	case 4469ULL: goto x86_l_1175;
	case 4472ULL: goto x86_l_1178;
	case 4478ULL: goto x86_l_117e;
	case 4481ULL: goto x86_l_1181;
	case 4487ULL: goto x86_l_1187;
	case 4490ULL: goto x86_l_118a;
	case 4496ULL: goto x86_l_1190;
	case 4501ULL: goto x86_l_1195;
	case 4505ULL: goto x86_l_1199;
	case 4510ULL: goto x86_l_119e;
	case 4515ULL: goto x86_l_11a3;
	case 4521ULL: goto x86_l_11a9;
	case 4524ULL: goto x86_l_11ac;
	case 4529ULL: goto x86_l_11b1;
	case 4532ULL: goto x86_l_11b4;
	case 4535ULL: goto x86_l_11b7;
	case 4538ULL: goto x86_l_11ba;
	case 4544ULL: goto x86_l_11c0;
	case 4549ULL: goto x86_l_11c5;
	case 4553ULL: goto x86_l_11c9;
	case 4555ULL: goto x86_l_11cb;
	case 4560ULL: goto x86_l_11d0;
	case 4565ULL: goto x86_l_11d5;
	case 4569ULL: goto x86_l_11d9;
	case 4575ULL: goto x86_l_11df;
	case 4579ULL: goto x86_l_11e3;
	case 4584ULL: goto x86_l_11e8;
	case 4589ULL: goto x86_l_11ed;
	case 4595ULL: goto x86_l_11f3;
	case 4599ULL: goto x86_l_11f7;
	case 4604ULL: goto x86_l_11fc;
	case 4607ULL: goto x86_l_11ff;
	case 4613ULL: goto x86_l_1205;
	case 4618ULL: goto x86_l_120a;
	case 4623ULL: goto x86_l_120f;
	case 4628ULL: goto x86_l_1214;
	case 4630ULL: goto x86_l_1216;
	case 4635ULL: goto x86_l_121b;
	case 4638ULL: goto x86_l_121e;
	case 4644ULL: goto x86_l_1224;
	case 4649ULL: goto x86_l_1229;
	case 4653ULL: goto x86_l_122d;
	case 4657ULL: goto x86_l_1231;
	case 4662ULL: goto x86_l_1236;
	case 4667ULL: goto x86_l_123b;
	case 4672ULL: goto x86_l_1240;
	case 4677ULL: goto x86_l_1245;
	case 4679ULL: goto x86_l_1247;
	case 4683ULL: goto x86_l_124b;
	case 4688ULL: goto x86_l_1250;
	case 4693ULL: goto x86_l_1255;
	case 4698ULL: goto x86_l_125a;
	case 4703ULL: goto x86_l_125f;
	case 4705ULL: goto x86_l_1261;
	case 4709ULL: goto x86_l_1265;
	case 4717ULL: goto x86_l_126d;
	case 4722ULL: goto x86_l_1272;
	case 4727ULL: goto x86_l_1277;
	case 4732ULL: goto x86_l_127c;
	case 4734ULL: goto x86_l_127e;
	case 4738ULL: goto x86_l_1282;
	case 4746ULL: goto x86_l_128a;
	case 4751ULL: goto x86_l_128f;
	case 4756ULL: goto x86_l_1294;
	case 4761ULL: goto x86_l_1299;
	case 4763ULL: goto x86_l_129b;
	case 4767ULL: goto x86_l_129f;
	case 4775ULL: goto x86_l_12a7;
	case 4780ULL: goto x86_l_12ac;
	case 4785ULL: goto x86_l_12b1;
	case 4787ULL: goto x86_l_12b3;
	case 4791ULL: goto x86_l_12b7;
	case 4799ULL: goto x86_l_12bf;
	case 4804ULL: goto x86_l_12c4;
	case 4809ULL: goto x86_l_12c9;
	case 4811ULL: goto x86_l_12cb;
	case 4815ULL: goto x86_l_12cf;
	case 4823ULL: goto x86_l_12d7;
	case 4831ULL: goto x86_l_12df;
	case 4839ULL: goto x86_l_12e7;
	case 4847ULL: goto x86_l_12ef;
	case 4852ULL: goto x86_l_12f4;
	case 4855ULL: goto x86_l_12f7;
	case 4861ULL: goto x86_l_12fd;
	case 4864ULL: goto x86_l_1300;
	case 4870ULL: goto x86_l_1306;
	case 4875ULL: goto x86_l_130b;
	case 4880ULL: goto x86_l_1310;
	case 4885ULL: goto x86_l_1315;
	case 4890ULL: goto x86_l_131a;
	case 4895ULL: goto x86_l_131f;
	case 4897ULL: goto x86_l_1321;
	case 4902ULL: goto x86_l_1326;
	case 4907ULL: goto x86_l_132b;
	case 4910ULL: goto x86_l_132e;
	case 4915ULL: goto x86_l_1333;
	case 4918ULL: goto x86_l_1336;
	case 4923ULL: goto x86_l_133b;
	case 4927ULL: goto x86_l_133f;
	case 4933ULL: goto x86_l_1345;
	case 4937ULL: goto x86_l_1349;
	case 4942ULL: goto x86_l_134e;
	case 4947ULL: goto x86_l_1353;
	case 4953ULL: goto x86_l_1359;
	case 4956ULL: goto x86_l_135c;
	case 4961ULL: goto x86_l_1361;
	case 4969ULL: goto x86_l_1369;
	case 4977ULL: goto x86_l_1371;
	case 4985ULL: goto x86_l_1379;
	case 4993ULL: goto x86_l_1381;
	case 5001ULL: goto x86_l_1389;
	case 5009ULL: goto x86_l_1391;
	case 5017ULL: goto x86_l_1399;
	case 5025ULL: goto x86_l_13a1;
	case 5033ULL: goto x86_l_13a9;
	case 5040ULL: goto x86_l_13b0;
	case 5044ULL: goto x86_l_13b4;
	case 5048ULL: goto x86_l_13b8;
	case 5053ULL: goto x86_l_13bd;
	case 5058ULL: goto x86_l_13c2;
	case 5063ULL: goto x86_l_13c7;
	case 5065ULL: goto x86_l_13c9;
	case 5068ULL: goto x86_l_13cc;
	case 5074ULL: goto x86_l_13d2;
	case 5079ULL: goto x86_l_13d7;
	case 5083ULL: goto x86_l_13db;
	case 5091ULL: goto x86_l_13e3;
	case 5098ULL: goto x86_l_13ea;
	case 5103ULL: goto x86_l_13ef;
	case 5108ULL: goto x86_l_13f4;
	case 5113ULL: goto x86_l_13f9;
	case 5115ULL: goto x86_l_13fb;
	case 5120ULL: goto x86_l_1400;
	case 5123ULL: goto x86_l_1403;
	case 5128ULL: goto x86_l_1408;
	case 5132ULL: goto x86_l_140c;
	case 5137ULL: goto x86_l_1411;
	case 5142ULL: goto x86_l_1416;
	case 5147ULL: goto x86_l_141b;
	case 5152ULL: goto x86_l_1420;
	case 5154ULL: goto x86_l_1422;
	case 5159ULL: goto x86_l_1427;
	case 5164ULL: goto x86_l_142c;
	case 5170ULL: goto x86_l_1432;
	case 5174ULL: goto x86_l_1436;
	case 5179ULL: goto x86_l_143b;
	case 5184ULL: goto x86_l_1440;
	case 5189ULL: goto x86_l_1445;
	case 5194ULL: goto x86_l_144a;
	case 5197ULL: goto x86_l_144d;
	case 5199ULL: goto x86_l_144f;
	case 5204ULL: goto x86_l_1454;
	case 5209ULL: goto x86_l_1459;
	case 5213ULL: goto x86_l_145d;
	case 5218ULL: goto x86_l_1462;
	case 5223ULL: goto x86_l_1467;
	case 5228ULL: goto x86_l_146c;
	case 5230ULL: goto x86_l_146e;
	case 5235ULL: goto x86_l_1473;
	case 5241ULL: goto x86_l_1479;
	case 5249ULL: goto x86_l_1481;
	case 5254ULL: goto x86_l_1486;
	case 5259ULL: goto x86_l_148b;
	case 5264ULL: goto x86_l_1490;
	case 5266ULL: goto x86_l_1492;
	case 5274ULL: goto x86_l_149a;
	case 5280ULL: goto x86_l_14a0;
	case 5285ULL: goto x86_l_14a5;
	case 5290ULL: goto x86_l_14aa;
	case 5295ULL: goto x86_l_14af;
	case 5300ULL: goto x86_l_14b4;
	case 5305ULL: goto x86_l_14b9;
	case 5308ULL: goto x86_l_14bc;
	case 5310ULL: goto x86_l_14be;
	case 5315ULL: goto x86_l_14c3;
	case 5321ULL: goto x86_l_14c9;
	case 5326ULL: goto x86_l_14ce;
	case 5331ULL: goto x86_l_14d3;
	case 5336ULL: goto x86_l_14d8;
	case 5341ULL: goto x86_l_14dd;
	case 5344ULL: goto x86_l_14e0;
	case 5346ULL: goto x86_l_14e2;
	case 5350ULL: goto x86_l_14e6;
	case 5355ULL: goto x86_l_14eb;
	case 5360ULL: goto x86_l_14f0;
	case 5365ULL: goto x86_l_14f5;
	case 5370ULL: goto x86_l_14fa;
	case 5373ULL: goto x86_l_14fd;
	case 5375ULL: goto x86_l_14ff;
	case 5380ULL: goto x86_l_1504;
	default: return 0xffffffffffffffffULL;
	}
x86_l_e1d:
	/* 0xe1d: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_e21:
	/* 0xe21: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_e26:
	/* 0xe26: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e2b:
	/* 0xe2b: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_e30:
	/* 0xe30: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e35:
	/* 0xe35: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_e38:
	/* 0xe38: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e3a:
	/* 0xe3a: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e3f:
	/* 0xe3f: mov    QWORD PTR [rsp+0x60],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_e44:
	/* 0xe44: lea    rdx,[r15+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e48:
	/* 0xe48: mov    QWORD PTR [rsp+0x58],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_e4d:
	/* 0xe4d: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_e52:
	/* 0xe52: cmp    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_e57:
	/* 0xe57: jne    e64 <generic_usdt_process_event+0xe64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_e64;
	}
x86_l_e59:
	/* 0xe59: cmp    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_e5e:
	/* 0xe5e: je     880 <generic_usdt_process_event+0x880> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2176ULL;
	}
x86_l_e64:
	/* 0xe64: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_e6c:
	/* 0xe6c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_e71:
	/* 0xe71: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e76:
	/* 0xe76: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e7b:
	/* 0xe7b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e7d:
	/* 0xe7d: cmp    r12,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 144ULL);
x86_l_e85:
	/* 0xe85: je     1408 <generic_usdt_process_event+0x1408> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1408;
	}
x86_l_e8b:
	/* 0xe8b: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e90:
	/* 0xe90: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e95:
	/* 0xe95: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_e9a:
	/* 0xe9a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e9f:
	/* 0xe9f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ea4:
	/* 0xea4: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_ea7:
	/* 0xea7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ea9:
	/* 0xea9: cmp    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_eae:
	/* 0xeae: je     1408 <generic_usdt_process_event+0x1408> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1408;
	}
x86_l_eb4:
	/* 0xeb4: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_eb9:
	/* 0xeb9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_ebe:
	/* 0xebe: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ec3:
	/* 0xec3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ec8:
	/* 0xec8: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_ecb:
	/* 0xecb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ecd:
	/* 0xecd: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_ed1:
	/* 0xed1: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_ed6:
	/* 0xed6: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_edb:
	/* 0xedb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ee0:
	/* 0xee0: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_ee5:
	/* 0xee5: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_ee8:
	/* 0xee8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_eea:
	/* 0xeea: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_eef:
	/* 0xeef: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_ef4:
	/* 0xef4: mov    r12d,DWORD PTR [rsp+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_ef9:
	/* 0xef9: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_efc:
	/* 0xefc: mov    r13d,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_f01:
	/* 0xf01: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f03:
	/* 0xf03: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_f06:
	/* 0xf06: sub    edx,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R13, X86_WIDTH_32, X86_ALU_SUB);
x86_l_f09:
	/* 0xf09: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_f0c:
	/* 0xf0c: add    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 128ULL);
x86_l_f14:
	/* 0xf14: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f16:
	/* 0xf16: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_f19:
	/* 0xf19: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_f1d:
	/* 0xf1d: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_f20:
	/* 0xf20: cmovb  ecx,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_f24:
	/* 0xf24: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_f26:
	/* 0xf26: mov    edi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_32);
x86_l_f29:
	/* 0xf29: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_f2b:
	/* 0xf2b: mov    DWORD PTR [rsp+0x70],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_f2f:
	/* 0xf2f: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_f32:
	/* 0xf32: jb     885 <generic_usdt_process_event+0x885> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2181ULL;
	}
x86_l_f38:
	/* 0xf38: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_f3e:
	/* 0xf3e: ja     885 <generic_usdt_process_event+0x885> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2181ULL;
	}
x86_l_f44:
	/* 0xf44: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_f47:
	/* 0xf47: jbe    f4e <generic_usdt_process_event+0xf4e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_f4e;
	}
x86_l_f49:
	/* 0xf49: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_f4e:
	/* 0xf4e: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f50:
	/* 0xf50: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_f53:
	/* 0xf53: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_f57:
	/* 0xf57: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_f5a:
	/* 0xf5a: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_f5d:
	/* 0xf5d: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_f60:
	/* 0xf60: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f65:
	/* 0xf65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f67:
	/* 0xf67: mov    QWORD PTR [rsp+0x68],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_f6c:
	/* 0xf6c: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_f6f:
	/* 0xf6f: jbe    885 <generic_usdt_process_event+0x885> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 2181ULL;
	}
x86_l_f75:
	/* 0xf75: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f7a:
	/* 0xf7a: mov    QWORD PTR [rsp+0x50],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_f7f:
	/* 0xf7f: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_f84:
	/* 0xf84: mov    r15,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_f89:
	/* 0xf89: jmp    1467 <generic_usdt_process_event+0x1467> */
	goto x86_l_1467;
x86_l_f8e:
	/* 0xf8e: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_f92:
	/* 0xf92: jg     1037 <generic_usdt_process_event+0x1037> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1037;
	}
x86_l_f98:
	/* 0xf98: cmp    r13d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1ULL);
x86_l_f9c:
	/* 0xf9c: je     1007 <generic_usdt_process_event+0x1007> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1007;
	}
x86_l_f9e:
	/* 0xf9e: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_fa2:
	/* 0xfa2: jne    38e4 <generic_usdt_process_event+0x38e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14564ULL;
	}
x86_l_fa8:
	/* 0xfa8: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_fad:
	/* 0xfad: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_fb2:
	/* 0xfb2: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_fb5:
	/* 0xfb5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_fba:
	/* 0xfba: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fbf:
	/* 0xfbf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_fc4:
	/* 0xfc4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fc6:
	/* 0xfc6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_fcb:
	/* 0xfcb: jmp    102a <generic_usdt_process_event+0x102a> */
	goto x86_l_102a;
x86_l_fcd:
	/* 0xfcd: cmp    r13d,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 32ULL);
x86_l_fd1:
	/* 0xfd1: jle    133b <generic_usdt_process_event+0x133b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_133b;
	}
x86_l_fd7:
	/* 0xfd7: lea    eax,[r13-0x21] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551583ULL);
x86_l_fdb:
	/* 0xfdb: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_fde:
	/* 0xfde: jae    11d5 <generic_usdt_process_event+0x11d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_11d5;
	}
x86_l_fe4:
	/* 0xfe4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_fe9:
	/* 0xfe9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_fee:
	/* 0xfee: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ff3:
	/* 0xff3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ff8:
	/* 0xff8: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_ffb:
	/* 0xffb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ffd:
	/* 0xffd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1002:
	/* 0x1002: jmp    38da <generic_usdt_process_event+0x38da> */
	return 14554ULL;
x86_l_1007:
	/* 0x1007: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_100c:
	/* 0x100c: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1011:
	/* 0x1011: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1014:
	/* 0x1014: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1019:
	/* 0x1019: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_101e:
	/* 0x101e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1023:
	/* 0x1023: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1025:
	/* 0x1025: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_102a:
	/* 0x102a: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_102f:
	/* 0x102f: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_1032:
	/* 0x1032: jmp    38e4 <generic_usdt_process_event+0x38e4> */
	return 14564ULL;
x86_l_1037:
	/* 0x1037: cmp    r13d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 5ULL);
x86_l_103b:
	/* 0x103b: je     16e4 <generic_usdt_process_event+0x16e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5860ULL;
	}
x86_l_1041:
	/* 0x1041: cmp    r13d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 6ULL);
x86_l_1045:
	/* 0x1045: je     19b6 <generic_usdt_process_event+0x19b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6582ULL;
	}
x86_l_104b:
	/* 0x104b: jmp    38e4 <generic_usdt_process_event+0x38e4> */
	return 14564ULL;
x86_l_1050:
	/* 0x1050: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1055:
	/* 0x1055: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_105a:
	/* 0x105a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_105f:
	/* 0x105f: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1064:
	/* 0x1064: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1069:
	/* 0x1069: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_106b:
	/* 0x106b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1070:
	/* 0x1070: jmp    38da <generic_usdt_process_event+0x38da> */
	return 14554ULL;
x86_l_1075:
	/* 0x1075: cmp    r13d,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 39ULL);
x86_l_1079:
	/* 0x1079: je     19f6 <generic_usdt_process_event+0x19f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6646ULL;
	}
x86_l_107f:
	/* 0x107f: cmp    r13d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 40ULL);
x86_l_1083:
	/* 0x1083: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1088:
	/* 0x1088: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_108d:
	/* 0x108d: jne    38e4 <generic_usdt_process_event+0x38e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14564ULL;
	}
x86_l_1093:
	/* 0x1093: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1096:
	/* 0x1096: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_109b:
	/* 0x109b: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10a0:
	/* 0x10a0: mov    QWORD PTR [r13+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_10a8:
	/* 0x10a8: mov    QWORD PTR [r13+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_10b0:
	/* 0x10b0: mov    QWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10b8:
	/* 0x10b8: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_10bd:
	/* 0x10bd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_10c2:
	/* 0x10c2: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_10c5:
	/* 0x10c5: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_10ca:
	/* 0x10ca: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_10cd:
	/* 0x10cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10cf:
	/* 0x10cf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10d2:
	/* 0x10d2: js     22ff <generic_usdt_process_event+0x22ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8959ULL;
	}
x86_l_10d8:
	/* 0x10d8: movzx  eax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_10dd:
	/* 0x10dd: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_10e0:
	/* 0x10e0: je     22be <generic_usdt_process_event+0x22be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8894ULL;
	}
x86_l_10e6:
	/* 0x10e6: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_10e9:
	/* 0x10e9: jne    22f3 <generic_usdt_process_event+0x22f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8947ULL;
	}
x86_l_10ef:
	/* 0x10ef: lea    rdx,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_10f3:
	/* 0x10f3: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_10f8:
	/* 0x10f8: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_10fd:
	/* 0x10fd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1102:
	/* 0x1102: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1107:
	/* 0x1107: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1109:
	/* 0x1109: mov    eax,DWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_110d:
	/* 0x110d: mov    QWORD PTR [r13+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1111:
	/* 0x1111: lea    rdi,[r13+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_1115:
	/* 0x1115: add    r15,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1119:
	/* 0x1119: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_111e:
	/* 0x111e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1123:
	/* 0x1123: jmp    22e9 <generic_usdt_process_event+0x22e9> */
	return 8937ULL;
x86_l_1128:
	/* 0x1128: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_112b:
	/* 0x112b: cmp    r13d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 7ULL);
x86_l_112f:
	/* 0x112f: jg     15a3 <generic_usdt_process_event+0x15a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5539ULL;
	}
x86_l_1135:
	/* 0x1135: cmp    r13d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 2ULL);
x86_l_1139:
	/* 0x1139: je     1a35 <generic_usdt_process_event+0x1a35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6709ULL;
	}
x86_l_113f:
	/* 0x113f: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1142:
	/* 0x1142: cmp    r13d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 3ULL);
x86_l_1146:
	/* 0x1146: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_114b:
	/* 0x114b: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1150:
	/* 0x1150: jne    38e4 <generic_usdt_process_event+0x38e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14564ULL;
	}
x86_l_1156:
	/* 0x1156: lea    r15,[r12+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_115e:
	/* 0x115e: mov    eax,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDI, X86_WIDTH_32);
x86_l_1160:
	/* 0x1160: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1163:
	/* 0x1163: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1166:
	/* 0x1166: jle    230c <generic_usdt_process_event+0x230c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 8972ULL;
	}
x86_l_116c:
	/* 0x116c: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_116f:
	/* 0x116f: je     2495 <generic_usdt_process_event+0x2495> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9365ULL;
	}
x86_l_1175:
	/* 0x1175: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1178:
	/* 0x1178: je     24a0 <generic_usdt_process_event+0x24a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9376ULL;
	}
x86_l_117e:
	/* 0x117e: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_1181:
	/* 0x1181: jne    28d0 <generic_usdt_process_event+0x28d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10448ULL;
	}
x86_l_1187:
	/* 0x1187: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_118a:
	/* 0x118a: add    rax,0x5e70 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24176ULL);
x86_l_1190:
	/* 0x1190: jmp    24b4 <generic_usdt_process_event+0x24b4> */
	return 9396ULL;
x86_l_1195:
	/* 0x1195: cmp    r13d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 38ULL);
x86_l_1199:
	/* 0x1199: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_119e:
	/* 0x119e: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_11a3:
	/* 0x11a3: jne    38e4 <generic_usdt_process_event+0x38e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14564ULL;
	}
x86_l_11a9:
	/* 0x11a9: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_11ac:
	/* 0x11ac: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_11b1:
	/* 0x11b1: movzx  edx,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_11b4:
	/* 0x11b4: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_11b7:
	/* 0x11b7: shr    esi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_11ba:
	/* 0x11ba: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_11c0:
	/* 0x11c0: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11c5:
	/* 0x11c5: lea    rdi,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_11c9:
	/* 0x11c9: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_11cb:
	/* 0x11cb: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_11d0:
	/* 0x11d0: jmp    19d6 <generic_usdt_process_event+0x19d6> */
	return 6614ULL;
x86_l_11d5:
	/* 0x11d5: cmp    r13d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 43ULL);
x86_l_11d9:
	/* 0x11d9: je     1e1f <generic_usdt_process_event+0x1e1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7711ULL;
	}
x86_l_11df:
	/* 0x11df: cmp    r13d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 41ULL);
x86_l_11e3:
	/* 0x11e3: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11e8:
	/* 0x11e8: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_11ed:
	/* 0x11ed: jne    38e4 <generic_usdt_process_event+0x38e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14564ULL;
	}
x86_l_11f3:
	/* 0x11f3: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_11f7:
	/* 0x11f7: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_11fc:
	/* 0x11fc: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_11ff:
	/* 0x11ff: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_1205:
	/* 0x1205: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_120a:
	/* 0x120a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_120f:
	/* 0x120f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1214:
	/* 0x1214: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1216:
	/* 0x1216: mov    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_121b:
	/* 0x121b: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_121e:
	/* 0x121e: je     38d5 <generic_usdt_process_event+0x38d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14549ULL;
	}
x86_l_1224:
	/* 0x1224: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1229:
	/* 0x1229: mov    QWORD PTR [r13+0x28],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_122d:
	/* 0x122d: lea    rdi,[r13+0x26] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_1231:
	/* 0x1231: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1236:
	/* 0x1236: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_123b:
	/* 0x123b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1240:
	/* 0x1240: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1245:
	/* 0x1245: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1247:
	/* 0x1247: lea    rdi,[r13+0x3a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_124b:
	/* 0x124b: lea    rdx,[r12+0x12] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_1250:
	/* 0x1250: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1255:
	/* 0x1255: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_125a:
	/* 0x125a: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_125f:
	/* 0x125f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1261:
	/* 0x1261: lea    rdi,[r13+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1265:
	/* 0x1265: lea    rdx,[r12+0x23c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_126d:
	/* 0x126d: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1272:
	/* 0x1272: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1277:
	/* 0x1277: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_127c:
	/* 0x127c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_127e:
	/* 0x127e: lea    rdi,[r13+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1282:
	/* 0x1282: lea    rdx,[r12+0x23e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 574ULL);
x86_l_128a:
	/* 0x128a: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_128f:
	/* 0x128f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1294:
	/* 0x1294: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1299:
	/* 0x1299: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_129b:
	/* 0x129b: lea    rdi,[r13+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_129f:
	/* 0x129f: lea    rdx,[r12+0x20c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_12a7:
	/* 0x12a7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12ac:
	/* 0x12ac: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_12b1:
	/* 0x12b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12b3:
	/* 0x12b3: lea    rdi,[r13+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_12b7:
	/* 0x12b7: lea    rdx,[r12+0x208] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_12bf:
	/* 0x12bf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12c4:
	/* 0x12c4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_12c9:
	/* 0x12c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12cb:
	/* 0x12cb: lea    r15,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12cf:
	/* 0x12cf: mov    QWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12d7:
	/* 0x12d7: mov    QWORD PTR [r13+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_12df:
	/* 0x12df: mov    QWORD PTR [r13+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_12e7:
	/* 0x12e7: mov    QWORD PTR [r13+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_12ef:
	/* 0x12ef: movzx  eax,WORD PTR [r13+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_12f4:
	/* 0x12f4: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_12f7:
	/* 0x12f7: je     2412 <generic_usdt_process_event+0x2412> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9234ULL;
	}
x86_l_12fd:
	/* 0x12fd: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1300:
	/* 0x1300: jne    2446 <generic_usdt_process_event+0x2446> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9286ULL;
	}
x86_l_1306:
	/* 0x1306: lea    rdx,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_130b:
	/* 0x130b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1310:
	/* 0x1310: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1315:
	/* 0x1315: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_131a:
	/* 0x131a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_131f:
	/* 0x131f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1321:
	/* 0x1321: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1326:
	/* 0x1326: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_132b:
	/* 0x132b: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_132e:
	/* 0x132e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1333:
	/* 0x1333: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1336:
	/* 0x1336: jmp    2444 <generic_usdt_process_event+0x2444> */
	return 9284ULL;
x86_l_133b:
	/* 0x133b: cmp    r13d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 26ULL);
x86_l_133f:
	/* 0x133f: je     1ebc <generic_usdt_process_event+0x1ebc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7868ULL;
	}
x86_l_1345:
	/* 0x1345: cmp    r13d,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 27ULL);
x86_l_1349:
	/* 0x1349: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_134e:
	/* 0x134e: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1353:
	/* 0x1353: jne    38e4 <generic_usdt_process_event+0x38e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14564ULL;
	}
x86_l_1359:
	/* 0x1359: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_135c:
	/* 0x135c: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1361:
	/* 0x1361: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1369:
	/* 0x1369: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1371:
	/* 0x1371: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1379:
	/* 0x1379: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1381:
	/* 0x1381: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1389:
	/* 0x1389: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1391:
	/* 0x1391: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1399:
	/* 0x1399: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_13a1:
	/* 0x13a1: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_13a9:
	/* 0x13a9: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13b0:
	/* 0x13b0: lea    rdi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13b4:
	/* 0x13b4: lea    rdx,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_13b8:
	/* 0x13b8: mov    ecx,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 63ULL);
x86_l_13bd:
	/* 0x13bd: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_13c2:
	/* 0x13c2: mov    esi,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 63ULL);
x86_l_13c7:
	/* 0x13c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13c9:
	/* 0x13c9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13cc:
	/* 0x13cc: js     23e8 <generic_usdt_process_event+0x23e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9192ULL;
	}
x86_l_13d2:
	/* 0x13d2: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13d7:
	/* 0x13d7: add    rdi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_13db:
	/* 0x13db: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_13e3:
	/* 0x13e3: add    rdx,0x348 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 840ULL);
x86_l_13ea:
	/* 0x13ea: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_13ef:
	/* 0x13ef: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13f4:
	/* 0x13f4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_13f9:
	/* 0x13f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13fb:
	/* 0x13fb: mov    esi,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 80ULL);
x86_l_1400:
	/* 0x1400: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_1403:
	/* 0x1403: jmp    38df <generic_usdt_process_event+0x38df> */
	return 14559ULL;
x86_l_1408:
	/* 0x1408: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_140c:
	/* 0x140c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1411:
	/* 0x1411: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1416:
	/* 0x1416: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_141b:
	/* 0x141b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1420:
	/* 0x1420: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1422:
	/* 0x1422: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1427:
	/* 0x1427: cmp    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_142c:
	/* 0x142c: je     880 <generic_usdt_process_event+0x880> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2176ULL;
	}
x86_l_1432:
	/* 0x1432: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1436:
	/* 0x1436: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_143b:
	/* 0x143b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1440:
	/* 0x1440: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1445:
	/* 0x1445: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_144a:
	/* 0x144a: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_144d:
	/* 0x144d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_144f:
	/* 0x144f: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1454:
	/* 0x1454: mov    QWORD PTR [rsp+0x60],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1459:
	/* 0x1459: lea    rdx,[r15+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_145d:
	/* 0x145d: mov    QWORD PTR [rsp+0x58],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1462:
	/* 0x1462: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1467:
	/* 0x1467: cmp    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_146c:
	/* 0x146c: jne    1479 <generic_usdt_process_event+0x1479> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1479;
	}
x86_l_146e:
	/* 0x146e: cmp    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_1473:
	/* 0x1473: je     880 <generic_usdt_process_event+0x880> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2176ULL;
	}
x86_l_1479:
	/* 0x1479: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1481:
	/* 0x1481: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1486:
	/* 0x1486: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_148b:
	/* 0x148b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1490:
	/* 0x1490: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1492:
	/* 0x1492: cmp    r12,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 144ULL);
x86_l_149a:
	/* 0x149a: je     2123 <generic_usdt_process_event+0x2123> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8483ULL;
	}
x86_l_14a0:
	/* 0x14a0: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_14a5:
	/* 0x14a5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14aa:
	/* 0x14aa: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_14af:
	/* 0x14af: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14b4:
	/* 0x14b4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14b9:
	/* 0x14b9: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_14bc:
	/* 0x14bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14be:
	/* 0x14be: cmp    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14c3:
	/* 0x14c3: je     2123 <generic_usdt_process_event+0x2123> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8483ULL;
	}
x86_l_14c9:
	/* 0x14c9: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_14ce:
	/* 0x14ce: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_14d3:
	/* 0x14d3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14d8:
	/* 0x14d8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14dd:
	/* 0x14dd: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_14e0:
	/* 0x14e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14e2:
	/* 0x14e2: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_14e6:
	/* 0x14e6: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_14eb:
	/* 0x14eb: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_14f0:
	/* 0x14f0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14f5:
	/* 0x14f5: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_14fa:
	/* 0x14fa: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_14fd:
	/* 0x14fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14ff:
	/* 0x14ff: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1504:
	/* 0x1504: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
	return 5385ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_generic_usdt_process_event_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5385ULL: goto x86_l_1509;
	case 5390ULL: goto x86_l_150e;
	case 5393ULL: goto x86_l_1511;
	case 5398ULL: goto x86_l_1516;
	case 5400ULL: goto x86_l_1518;
	case 5403ULL: goto x86_l_151b;
	case 5406ULL: goto x86_l_151e;
	case 5409ULL: goto x86_l_1521;
	case 5417ULL: goto x86_l_1529;
	case 5419ULL: goto x86_l_152b;
	case 5422ULL: goto x86_l_152e;
	case 5426ULL: goto x86_l_1532;
	case 5429ULL: goto x86_l_1535;
	case 5433ULL: goto x86_l_1539;
	case 5435ULL: goto x86_l_153b;
	case 5438ULL: goto x86_l_153e;
	case 5440ULL: goto x86_l_1540;
	case 5444ULL: goto x86_l_1544;
	case 5447ULL: goto x86_l_1547;
	case 5453ULL: goto x86_l_154d;
	case 5459ULL: goto x86_l_1553;
	case 5465ULL: goto x86_l_1559;
	case 5468ULL: goto x86_l_155c;
	case 5470ULL: goto x86_l_155e;
	case 5475ULL: goto x86_l_1563;
	case 5477ULL: goto x86_l_1565;
	case 5480ULL: goto x86_l_1568;
	case 5484ULL: goto x86_l_156c;
	case 5487ULL: goto x86_l_156f;
	case 5490ULL: goto x86_l_1572;
	case 5493ULL: goto x86_l_1575;
	case 5498ULL: goto x86_l_157a;
	case 5500ULL: goto x86_l_157c;
	case 5505ULL: goto x86_l_1581;
	case 5508ULL: goto x86_l_1584;
	case 5514ULL: goto x86_l_158a;
	case 5519ULL: goto x86_l_158f;
	case 5524ULL: goto x86_l_1594;
	case 5529ULL: goto x86_l_1599;
	case 5534ULL: goto x86_l_159e;
	case 5539ULL: goto x86_l_15a3;
	case 5543ULL: goto x86_l_15a7;
	case 5549ULL: goto x86_l_15ad;
	case 5553ULL: goto x86_l_15b1;
	case 5558ULL: goto x86_l_15b6;
	case 5563ULL: goto x86_l_15bb;
	case 5571ULL: goto x86_l_15c3;
	case 5577ULL: goto x86_l_15c9;
	case 5580ULL: goto x86_l_15cc;
	case 5587ULL: goto x86_l_15d3;
	case 5590ULL: goto x86_l_15d6;
	case 5593ULL: goto x86_l_15d9;
	case 5598ULL: goto x86_l_15de;
	case 5603ULL: goto x86_l_15e3;
	case 5606ULL: goto x86_l_15e6;
	case 5608ULL: goto x86_l_15e8;
	case 5613ULL: goto x86_l_15ed;
	case 5616ULL: goto x86_l_15f0;
	case 5619ULL: goto x86_l_15f3;
	case 5624ULL: goto x86_l_15f8;
	case 5628ULL: goto x86_l_15fc;
	case 5634ULL: goto x86_l_1602;
	case 5638ULL: goto x86_l_1606;
	case 5643ULL: goto x86_l_160b;
	case 5648ULL: goto x86_l_1610;
	case 5656ULL: goto x86_l_1618;
	case 5662ULL: goto x86_l_161e;
	case 5671ULL: goto x86_l_1627;
	case 5679ULL: goto x86_l_162f;
	case 5684ULL: goto x86_l_1634;
	case 5689ULL: goto x86_l_1639;
	case 5694ULL: goto x86_l_163e;
	case 5702ULL: goto x86_l_1646;
	case 5707ULL: goto x86_l_164b;
	case 5709ULL: goto x86_l_164d;
	case 5714ULL: goto x86_l_1652;
	case 5719ULL: goto x86_l_1657;
	case 5724ULL: goto x86_l_165c;
	case 5729ULL: goto x86_l_1661;
	case 5734ULL: goto x86_l_1666;
	case 5737ULL: goto x86_l_1669;
	case 5742ULL: goto x86_l_166e;
	case 5744ULL: goto x86_l_1670;
	case 5751ULL: goto x86_l_1677;
	case 5756ULL: goto x86_l_167c;
	case 5761ULL: goto x86_l_1681;
	case 5766ULL: goto x86_l_1686;
	case 5769ULL: goto x86_l_1689;
	case 5771ULL: goto x86_l_168b;
	case 5778ULL: goto x86_l_1692;
	case 5786ULL: goto x86_l_169a;
	case 5791ULL: goto x86_l_169f;
	case 5796ULL: goto x86_l_16a4;
	case 5801ULL: goto x86_l_16a9;
	case 5803ULL: goto x86_l_16ab;
	case 5810ULL: goto x86_l_16b2;
	case 5817ULL: goto x86_l_16b9;
	case 5822ULL: goto x86_l_16be;
	case 5827ULL: goto x86_l_16c3;
	case 5830ULL: goto x86_l_16c6;
	case 5835ULL: goto x86_l_16cb;
	case 5838ULL: goto x86_l_16ce;
	case 5840ULL: goto x86_l_16d0;
	case 5845ULL: goto x86_l_16d5;
	case 5850ULL: goto x86_l_16da;
	case 5855ULL: goto x86_l_16df;
	case 5860ULL: goto x86_l_16e4;
	case 5865ULL: goto x86_l_16e9;
	case 5870ULL: goto x86_l_16ee;
	case 5874ULL: goto x86_l_16f2;
	case 5882ULL: goto x86_l_16fa;
	case 5887ULL: goto x86_l_16ff;
	case 5892ULL: goto x86_l_1704;
	case 5897ULL: goto x86_l_1709;
	case 5899ULL: goto x86_l_170b;
	case 5903ULL: goto x86_l_170f;
	case 5908ULL: goto x86_l_1714;
	case 5913ULL: goto x86_l_1719;
	case 5918ULL: goto x86_l_171e;
	case 5923ULL: goto x86_l_1723;
	case 5925ULL: goto x86_l_1725;
	case 5929ULL: goto x86_l_1729;
	case 5937ULL: goto x86_l_1731;
	case 5942ULL: goto x86_l_1736;
	case 5947ULL: goto x86_l_173b;
	case 5952ULL: goto x86_l_1740;
	case 5954ULL: goto x86_l_1742;
	case 5958ULL: goto x86_l_1746;
	case 5966ULL: goto x86_l_174e;
	case 5971ULL: goto x86_l_1753;
	case 5976ULL: goto x86_l_1758;
	case 5981ULL: goto x86_l_175d;
	case 5983ULL: goto x86_l_175f;
	case 5992ULL: goto x86_l_1768;
	case 6000ULL: goto x86_l_1770;
	case 6005ULL: goto x86_l_1775;
	case 6010ULL: goto x86_l_177a;
	case 6015ULL: goto x86_l_177f;
	case 6020ULL: goto x86_l_1784;
	case 6022ULL: goto x86_l_1786;
	case 6030ULL: goto x86_l_178e;
	case 6038ULL: goto x86_l_1796;
	case 6046ULL: goto x86_l_179e;
	case 6051ULL: goto x86_l_17a3;
	case 6056ULL: goto x86_l_17a8;
	case 6061ULL: goto x86_l_17ad;
	case 6063ULL: goto x86_l_17af;
	case 6072ULL: goto x86_l_17b8;
	case 6077ULL: goto x86_l_17bd;
	case 6085ULL: goto x86_l_17c5;
	case 6090ULL: goto x86_l_17ca;
	case 6095ULL: goto x86_l_17cf;
	case 6100ULL: goto x86_l_17d4;
	case 6103ULL: goto x86_l_17d7;
	case 6105ULL: goto x86_l_17d9;
	case 6113ULL: goto x86_l_17e1;
	case 6116ULL: goto x86_l_17e4;
	case 6119ULL: goto x86_l_17e7;
	case 6125ULL: goto x86_l_17ed;
	case 6128ULL: goto x86_l_17f0;
	case 6134ULL: goto x86_l_17f6;
	case 6138ULL: goto x86_l_17fa;
	case 6146ULL: goto x86_l_1802;
	case 6151ULL: goto x86_l_1807;
	case 6156ULL: goto x86_l_180c;
	case 6161ULL: goto x86_l_1811;
	case 6163ULL: goto x86_l_1813;
	case 6171ULL: goto x86_l_181b;
	case 6176ULL: goto x86_l_1820;
	case 6180ULL: goto x86_l_1824;
	case 6186ULL: goto x86_l_182a;
	case 6190ULL: goto x86_l_182e;
	case 6197ULL: goto x86_l_1835;
	case 6205ULL: goto x86_l_183d;
	case 6213ULL: goto x86_l_1845;
	case 6221ULL: goto x86_l_184d;
	case 6226ULL: goto x86_l_1852;
	case 6231ULL: goto x86_l_1857;
	case 6235ULL: goto x86_l_185b;
	case 6240ULL: goto x86_l_1860;
	case 6242ULL: goto x86_l_1862;
	case 6246ULL: goto x86_l_1866;
	case 6251ULL: goto x86_l_186b;
	case 6256ULL: goto x86_l_1870;
	case 6259ULL: goto x86_l_1873;
	case 6264ULL: goto x86_l_1878;
	case 6267ULL: goto x86_l_187b;
	case 6269ULL: goto x86_l_187d;
	case 6277ULL: goto x86_l_1885;
	case 6284ULL: goto x86_l_188c;
	case 6292ULL: goto x86_l_1894;
	case 6297ULL: goto x86_l_1899;
	case 6302ULL: goto x86_l_189e;
	case 6307ULL: goto x86_l_18a3;
	case 6309ULL: goto x86_l_18a5;
	case 6318ULL: goto x86_l_18ae;
	case 6323ULL: goto x86_l_18b3;
	case 6332ULL: goto x86_l_18bc;
	case 6337ULL: goto x86_l_18c1;
	case 6339ULL: goto x86_l_18c3;
	case 6343ULL: goto x86_l_18c7;
	case 6348ULL: goto x86_l_18cc;
	case 6353ULL: goto x86_l_18d1;
	case 6358ULL: goto x86_l_18d6;
	case 6363ULL: goto x86_l_18db;
	case 6368ULL: goto x86_l_18e0;
	case 6373ULL: goto x86_l_18e5;
	case 6375ULL: goto x86_l_18e7;
	case 6379ULL: goto x86_l_18eb;
	case 6383ULL: goto x86_l_18ef;
	case 6390ULL: goto x86_l_18f6;
	case 6395ULL: goto x86_l_18fb;
	case 6400ULL: goto x86_l_1900;
	case 6402ULL: goto x86_l_1902;
	case 6405ULL: goto x86_l_1905;
	case 6411ULL: goto x86_l_190b;
	case 6414ULL: goto x86_l_190e;
	case 6419ULL: goto x86_l_1913;
	case 6422ULL: goto x86_l_1916;
	case 6427ULL: goto x86_l_191b;
	case 6432ULL: goto x86_l_1920;
	case 6437ULL: goto x86_l_1925;
	case 6440ULL: goto x86_l_1928;
	case 6445ULL: goto x86_l_192d;
	case 6447ULL: goto x86_l_192f;
	case 6454ULL: goto x86_l_1936;
	case 6458ULL: goto x86_l_193a;
	case 6462ULL: goto x86_l_193e;
	case 6467ULL: goto x86_l_1943;
	case 6470ULL: goto x86_l_1946;
	case 6472ULL: goto x86_l_1948;
	case 6476ULL: goto x86_l_194c;
	case 6480ULL: goto x86_l_1950;
	case 6484ULL: goto x86_l_1954;
	case 6488ULL: goto x86_l_1958;
	case 6493ULL: goto x86_l_195d;
	case 6498ULL: goto x86_l_1962;
	case 6503ULL: goto x86_l_1967;
	case 6505ULL: goto x86_l_1969;
	case 6508ULL: goto x86_l_196c;
	case 6512ULL: goto x86_l_1970;
	case 6517ULL: goto x86_l_1975;
	case 6522ULL: goto x86_l_197a;
	case 6527ULL: goto x86_l_197f;
	case 6532ULL: goto x86_l_1984;
	case 6537ULL: goto x86_l_1989;
	case 6542ULL: goto x86_l_198e;
	case 6545ULL: goto x86_l_1991;
	case 6547ULL: goto x86_l_1993;
	case 6552ULL: goto x86_l_1998;
	case 6557ULL: goto x86_l_199d;
	case 6562ULL: goto x86_l_19a2;
	case 6567ULL: goto x86_l_19a7;
	case 6570ULL: goto x86_l_19aa;
	case 6575ULL: goto x86_l_19af;
	case 6577ULL: goto x86_l_19b1;
	case 6582ULL: goto x86_l_19b6;
	case 6585ULL: goto x86_l_19b9;
	case 6590ULL: goto x86_l_19be;
	case 6595ULL: goto x86_l_19c3;
	case 6599ULL: goto x86_l_19c7;
	case 6604ULL: goto x86_l_19cc;
	case 6609ULL: goto x86_l_19d1;
	case 6614ULL: goto x86_l_19d6;
	case 6616ULL: goto x86_l_19d8;
	case 6619ULL: goto x86_l_19db;
	case 6622ULL: goto x86_l_19de;
	case 6628ULL: goto x86_l_19e4;
	case 6631ULL: goto x86_l_19e7;
	case 6634ULL: goto x86_l_19ea;
	case 6638ULL: goto x86_l_19ee;
	case 6641ULL: goto x86_l_19f1;
	case 6646ULL: goto x86_l_19f6;
	case 6651ULL: goto x86_l_19fb;
	case 6656ULL: goto x86_l_1a00;
	case 6661ULL: goto x86_l_1a05;
	case 6665ULL: goto x86_l_1a09;
	case 6670ULL: goto x86_l_1a0e;
	case 6675ULL: goto x86_l_1a13;
	case 6680ULL: goto x86_l_1a18;
	case 6682ULL: goto x86_l_1a1a;
	case 6685ULL: goto x86_l_1a1d;
	case 6688ULL: goto x86_l_1a20;
	case 6694ULL: goto x86_l_1a26;
	case 6697ULL: goto x86_l_1a29;
	case 6700ULL: goto x86_l_1a2c;
	case 6704ULL: goto x86_l_1a30;
	case 6709ULL: goto x86_l_1a35;
	case 6712ULL: goto x86_l_1a38;
	case 6720ULL: goto x86_l_1a40;
	case 6723ULL: goto x86_l_1a43;
	case 6729ULL: goto x86_l_1a49;
	case 6734ULL: goto x86_l_1a4e;
	case 6746ULL: goto x86_l_1a5a;
	case 6750ULL: goto x86_l_1a5e;
	case 6756ULL: goto x86_l_1a64;
	case 6760ULL: goto x86_l_1a68;
	case 6762ULL: goto x86_l_1a6a;
	case 6766ULL: goto x86_l_1a6e;
	case 6772ULL: goto x86_l_1a74;
	case 6776ULL: goto x86_l_1a78;
	case 6782ULL: goto x86_l_1a7e;
	case 6786ULL: goto x86_l_1a82;
	case 6792ULL: goto x86_l_1a88;
	case 6796ULL: goto x86_l_1a8c;
	case 6802ULL: goto x86_l_1a92;
	case 6809ULL: goto x86_l_1a99;
	case 6814ULL: goto x86_l_1a9e;
	case 6819ULL: goto x86_l_1aa3;
	case 6824ULL: goto x86_l_1aa8;
	case 6829ULL: goto x86_l_1aad;
	case 6834ULL: goto x86_l_1ab2;
	case 6842ULL: goto x86_l_1aba;
	case 6846ULL: goto x86_l_1abe;
	case 6851ULL: goto x86_l_1ac3;
	case 6856ULL: goto x86_l_1ac8;
	case 6859ULL: goto x86_l_1acb;
	case 6864ULL: goto x86_l_1ad0;
	case 6866ULL: goto x86_l_1ad2;
	case 6871ULL: goto x86_l_1ad7;
	case 6875ULL: goto x86_l_1adb;
	case 6880ULL: goto x86_l_1ae0;
	case 6885ULL: goto x86_l_1ae5;
	case 6890ULL: goto x86_l_1aea;
	case 6892ULL: goto x86_l_1aec;
	case 6897ULL: goto x86_l_1af1;
	case 6901ULL: goto x86_l_1af5;
	case 6906ULL: goto x86_l_1afa;
	case 6911ULL: goto x86_l_1aff;
	case 6916ULL: goto x86_l_1b04;
	case 6918ULL: goto x86_l_1b06;
	case 6923ULL: goto x86_l_1b0b;
	case 6927ULL: goto x86_l_1b0f;
	case 6932ULL: goto x86_l_1b14;
	case 6937ULL: goto x86_l_1b19;
	case 6942ULL: goto x86_l_1b1e;
	case 6944ULL: goto x86_l_1b20;
	case 6949ULL: goto x86_l_1b25;
	case 6953ULL: goto x86_l_1b29;
	case 6958ULL: goto x86_l_1b2e;
	case 6963ULL: goto x86_l_1b33;
	case 6968ULL: goto x86_l_1b38;
	case 6970ULL: goto x86_l_1b3a;
	case 6975ULL: goto x86_l_1b3f;
	case 6979ULL: goto x86_l_1b43;
	case 6984ULL: goto x86_l_1b48;
	case 6989ULL: goto x86_l_1b4d;
	case 6994ULL: goto x86_l_1b52;
	case 6996ULL: goto x86_l_1b54;
	case 7001ULL: goto x86_l_1b59;
	case 7005ULL: goto x86_l_1b5d;
	case 7010ULL: goto x86_l_1b62;
	case 7015ULL: goto x86_l_1b67;
	case 7020ULL: goto x86_l_1b6c;
	case 7022ULL: goto x86_l_1b6e;
	case 7027ULL: goto x86_l_1b73;
	case 7031ULL: goto x86_l_1b77;
	case 7036ULL: goto x86_l_1b7c;
	case 7041ULL: goto x86_l_1b81;
	case 7046ULL: goto x86_l_1b86;
	case 7048ULL: goto x86_l_1b88;
	case 7057ULL: goto x86_l_1b91;
	case 7062ULL: goto x86_l_1b96;
	case 7066ULL: goto x86_l_1b9a;
	case 7071ULL: goto x86_l_1b9f;
	case 7076ULL: goto x86_l_1ba4;
	case 7081ULL: goto x86_l_1ba9;
	case 7083ULL: goto x86_l_1bab;
	case 7088ULL: goto x86_l_1bb0;
	case 7092ULL: goto x86_l_1bb4;
	case 7097ULL: goto x86_l_1bb9;
	case 7102ULL: goto x86_l_1bbe;
	case 7107ULL: goto x86_l_1bc3;
	case 7109ULL: goto x86_l_1bc5;
	case 7114ULL: goto x86_l_1bca;
	case 7118ULL: goto x86_l_1bce;
	case 7123ULL: goto x86_l_1bd3;
	case 7128ULL: goto x86_l_1bd8;
	case 7133ULL: goto x86_l_1bdd;
	case 7135ULL: goto x86_l_1bdf;
	case 7139ULL: goto x86_l_1be3;
	case 7144ULL: goto x86_l_1be8;
	case 7149ULL: goto x86_l_1bed;
	case 7152ULL: goto x86_l_1bf0;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1509:
	/* 0x1509: mov    r12d,DWORD PTR [rsp+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_150e:
	/* 0x150e: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1511:
	/* 0x1511: mov    r13d,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1516:
	/* 0x1516: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1518:
	/* 0x1518: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_151b:
	/* 0x151b: sub    edx,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R13, X86_WIDTH_32, X86_ALU_SUB);
x86_l_151e:
	/* 0x151e: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_1521:
	/* 0x1521: add    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 128ULL);
x86_l_1529:
	/* 0x1529: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_152b:
	/* 0x152b: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_152e:
	/* 0x152e: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_1532:
	/* 0x1532: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_1535:
	/* 0x1535: cmovb  ecx,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_1539:
	/* 0x1539: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_153b:
	/* 0x153b: mov    edi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_32);
x86_l_153e:
	/* 0x153e: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1540:
	/* 0x1540: mov    DWORD PTR [rsp+0x70],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1544:
	/* 0x1544: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1547:
	/* 0x1547: jb     885 <generic_usdt_process_event+0x885> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2181ULL;
	}
x86_l_154d:
	/* 0x154d: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_1553:
	/* 0x1553: ja     885 <generic_usdt_process_event+0x885> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2181ULL;
	}
x86_l_1559:
	/* 0x1559: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_155c:
	/* 0x155c: jbe    1563 <generic_usdt_process_event+0x1563> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1563;
	}
x86_l_155e:
	/* 0x155e: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_1563:
	/* 0x1563: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1565:
	/* 0x1565: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_1568:
	/* 0x1568: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_156c:
	/* 0x156c: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_156f:
	/* 0x156f: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1572:
	/* 0x1572: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1575:
	/* 0x1575: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_157a:
	/* 0x157a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_157c:
	/* 0x157c: mov    QWORD PTR [rsp+0x68],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1581:
	/* 0x1581: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_1584:
	/* 0x1584: jbe    885 <generic_usdt_process_event+0x885> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 2181ULL;
	}
x86_l_158a:
	/* 0x158a: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_158f:
	/* 0x158f: mov    QWORD PTR [rsp+0x50],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1594:
	/* 0x1594: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1599:
	/* 0x1599: mov    r15,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_159e:
	/* 0x159e: jmp    2182 <generic_usdt_process_event+0x2182> */
	return 8578ULL;
x86_l_15a3:
	/* 0x15a3: cmp    r13d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 8ULL);
x86_l_15a7:
	/* 0x15a7: je     1a9e <generic_usdt_process_event+0x1a9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a9e;
	}
x86_l_15ad:
	/* 0x15ad: cmp    r13d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 18ULL);
x86_l_15b1:
	/* 0x15b1: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15b6:
	/* 0x15b6: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_15bb:
	/* 0x15bb: mov    rcx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_15c3:
	/* 0x15c3: jne    38e4 <generic_usdt_process_event+0x38e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14564ULL;
	}
x86_l_15c9:
	/* 0x15c9: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_15cc:
	/* 0x15cc: and    r12d,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_15d3:
	/* 0x15d3: mov    rdx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_15d6:
	/* 0x15d6: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_15d9:
	/* 0x15d9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15de:
	/* 0x15de: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15e3:
	/* 0x15e3: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_15e6:
	/* 0x15e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15e8:
	/* 0x15e8: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_15ed:
	/* 0x15ed: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_15f0:
	/* 0x15f0: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_15f3:
	/* 0x15f3: jmp    38e4 <generic_usdt_process_event+0x38e4> */
	return 14564ULL;
x86_l_15f8:
	/* 0x15f8: cmp    r13d,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 19ULL);
x86_l_15fc:
	/* 0x15fc: je     1dbf <generic_usdt_process_event+0x1dbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7615ULL;
	}
x86_l_1602:
	/* 0x1602: cmp    r13d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 20ULL);
x86_l_1606:
	/* 0x1606: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_160b:
	/* 0x160b: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1610:
	/* 0x1610: mov    r12,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1618:
	/* 0x1618: jne    38e4 <generic_usdt_process_event+0x38e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14564ULL;
	}
x86_l_161e:
	/* 0x161e: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1627:
	/* 0x1627: lea    rdx,[r12+0x110] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_162f:
	/* 0x162f: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1634:
	/* 0x1634: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1639:
	/* 0x1639: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_163e:
	/* 0x163e: lea    r15,[r12+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_1646:
	/* 0x1646: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_164b:
	/* 0x164b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_164d:
	/* 0x164d: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1652:
	/* 0x1652: mov    edx,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 128ULL);
x86_l_1657:
	/* 0x1657: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_165c:
	/* 0x165c: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1661:
	/* 0x1661: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1666:
	/* 0x1666: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1669:
	/* 0x1669: mov    esi,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 128ULL);
x86_l_166e:
	/* 0x166e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1670:
	/* 0x1670: lea    rdi,[r13+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1677:
	/* 0x1677: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_167c:
	/* 0x167c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1681:
	/* 0x1681: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1686:
	/* 0x1686: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1689:
	/* 0x1689: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_168b:
	/* 0x168b: lea    rdi,[r13+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1692:
	/* 0x1692: lea    rdx,[r12+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_169a:
	/* 0x169a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_169f:
	/* 0x169f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16a4:
	/* 0x16a4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16a9:
	/* 0x16a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16ab:
	/* 0x16ab: add    r13,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_16b2:
	/* 0x16b2: add    r12,0x118 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 280ULL);
x86_l_16b9:
	/* 0x16b9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_16be:
	/* 0x16be: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16c3:
	/* 0x16c3: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_16c6:
	/* 0x16c6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16cb:
	/* 0x16cb: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_16ce:
	/* 0x16ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16d0:
	/* 0x16d0: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_16d5:
	/* 0x16d5: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_16da:
	/* 0x16da: mov    esi,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 152ULL);
x86_l_16df:
	/* 0x16df: jmp    38e4 <generic_usdt_process_event+0x38e4> */
	return 14564ULL;
x86_l_16e4:
	/* 0x16e4: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_16e9:
	/* 0x16e9: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16ee:
	/* 0x16ee: lea    rdi,[r15+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_16f2:
	/* 0x16f2: lea    rdx,[r12+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_16fa:
	/* 0x16fa: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_16ff:
	/* 0x16ff: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1704:
	/* 0x1704: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1709:
	/* 0x1709: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_170b:
	/* 0x170b: lea    rdi,[r15+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_170f:
	/* 0x170f: lea    rdx,[r12+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1714:
	/* 0x1714: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1719:
	/* 0x1719: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_171e:
	/* 0x171e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1723:
	/* 0x1723: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1725:
	/* 0x1725: lea    rdi,[r15+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1729:
	/* 0x1729: lea    rdx,[r12+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1731:
	/* 0x1731: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1736:
	/* 0x1736: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_173b:
	/* 0x173b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1740:
	/* 0x1740: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1742:
	/* 0x1742: lea    rdi,[r15+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1746:
	/* 0x1746: lea    rdx,[r12+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_174e:
	/* 0x174e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1753:
	/* 0x1753: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1758:
	/* 0x1758: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_175d:
	/* 0x175d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_175f:
	/* 0x175f: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1768:
	/* 0x1768: lea    rdx,[r12+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1770:
	/* 0x1770: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1775:
	/* 0x1775: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_177a:
	/* 0x177a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_177f:
	/* 0x177f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1784:
	/* 0x1784: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1786:
	/* 0x1786: mov    QWORD PTR [rsp+0x88],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_178e:
	/* 0x178e: lea    rdx,[r12+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1796:
	/* 0x1796: lea    rdi,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_179e:
	/* 0x179e: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_17a3:
	/* 0x17a3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17a8:
	/* 0x17a8: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_17ad:
	/* 0x17ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17af:
	/* 0x17af: movzx  r15d,WORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 192ULL);
x86_l_17b8:
	/* 0x17b8: add    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_17bd:
	/* 0x17bd: lea    rdi,[rsp+0xa3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 163ULL);
x86_l_17c5:
	/* 0x17c5: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_17ca:
	/* 0x17ca: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17cf:
	/* 0x17cf: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_17d4:
	/* 0x17d4: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_17d7:
	/* 0x17d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17d9:
	/* 0x17d9: movzx  eax,BYTE PTR [rsp+0xa3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 163ULL);
x86_l_17e1:
	/* 0x17e1: shr    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 4ULL);
x86_l_17e4:
	/* 0x17e4: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_17e7:
	/* 0x17e7: je     1f45 <generic_usdt_process_event+0x1f45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8005ULL;
	}
x86_l_17ed:
	/* 0x17ed: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17f0:
	/* 0x17f0: jne    38d5 <generic_usdt_process_event+0x38d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14549ULL;
	}
x86_l_17f6:
	/* 0x17f6: lea    rdx,[r15+0x9] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_17fa:
	/* 0x17fa: lea    rdi,[rsp+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_1802:
	/* 0x1802: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1807:
	/* 0x1807: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_180c:
	/* 0x180c: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1811:
	/* 0x1811: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1813:
	/* 0x1813: movzx  eax,BYTE PTR [rsp+0xa4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 164ULL);
x86_l_181b:
	/* 0x181b: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1820:
	/* 0x1820: mov    WORD PTR [rdi+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1824:
	/* 0x1824: mov    WORD PTR [rdi+0x26],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757250ULL);
x86_l_182a:
	/* 0x182a: lea    rdx,[r15+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_182e:
	/* 0x182e: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1835:
	/* 0x1835: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_183d:
	/* 0x183d: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1845:
	/* 0x1845: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_184d:
	/* 0x184d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1852:
	/* 0x1852: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1857:
	/* 0x1857: lea    r13,[rdi+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_185b:
	/* 0x185b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1860:
	/* 0x1860: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1862:
	/* 0x1862: add    r15,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1866:
	/* 0x1866: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_186b:
	/* 0x186b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1870:
	/* 0x1870: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1873:
	/* 0x1873: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1878:
	/* 0x1878: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_187b:
	/* 0x187b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_187d:
	/* 0x187d: mov    rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1885:
	/* 0x1885: lea    rdx,[rax+0xb6] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 182ULL);
x86_l_188c:
	/* 0x188c: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1894:
	/* 0x1894: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1899:
	/* 0x1899: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_189e:
	/* 0x189e: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_18a3:
	/* 0x18a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18a5:
	/* 0x18a5: movzx  r13d,BYTE PTR [rsp+0xa4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 164ULL);
x86_l_18ae:
	/* 0x18ae: jmp    376b <generic_usdt_process_event+0x376b> */
	return 14187ULL;
x86_l_18b3:
	/* 0x18b3: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_18bc:
	/* 0x18bc: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_18c1:
	/* 0x18c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18c3:
	/* 0x18c3: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_18c7:
	/* 0x18c7: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_18cc:
	/* 0x18cc: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_18d1:
	/* 0x18d1: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_18d6:
	/* 0x18d6: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_18db:
	/* 0x18db: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18e0:
	/* 0x18e0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18e5:
	/* 0x18e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18e7:
	/* 0x18e7: mov    eax,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_18eb:
	/* 0x18eb: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_18ef:
	/* 0x18ef: mov    rdi,QWORD PTR [rip+0x9db] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_18f6:
	/* 0x18f6: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_18fb:
	/* 0x18fb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1900:
	/* 0x1900: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1902:
	/* 0x1902: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1905:
	/* 0x1905: je     1f39 <generic_usdt_process_event+0x1f39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7993ULL;
	}
x86_l_190b:
	/* 0x190b: mov    r15d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_190e:
	/* 0x190e: lea    rdx,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1913:
	/* 0x1913: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1916:
	/* 0x1916: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_191b:
	/* 0x191b: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1920:
	/* 0x1920: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1925:
	/* 0x1925: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1928:
	/* 0x1928: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_192d:
	/* 0x192d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_192f:
	/* 0x192f: and    r15d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1936:
	/* 0x1936: lea    rdi,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_193a:
	/* 0x193a: lea    rsi,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_193e:
	/* 0x193e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1943:
	/* 0x1943: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1946:
	/* 0x1946: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1948:
	/* 0x1948: lea    rdi,[r15+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_194c:
	/* 0x194c: add    rdi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1950:
	/* 0x1950: lea    rdx,[r15+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_1954:
	/* 0x1954: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1958:
	/* 0x1958: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_195d:
	/* 0x195d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1962:
	/* 0x1962: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1967:
	/* 0x1967: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1969:
	/* 0x1969: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_196c:
	/* 0x196c: add    rsi,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1970:
	/* 0x1970: jmp    38da <generic_usdt_process_event+0x38da> */
	return 14554ULL;
x86_l_1975:
	/* 0x1975: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_197a:
	/* 0x197a: lea    r15,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_197f:
	/* 0x197f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1984:
	/* 0x1984: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1989:
	/* 0x1989: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_198e:
	/* 0x198e: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1991:
	/* 0x1991: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1993:
	/* 0x1993: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1998:
	/* 0x1998: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_199d:
	/* 0x199d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19a2:
	/* 0x19a2: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_19a7:
	/* 0x19a7: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_19aa:
	/* 0x19aa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19af:
	/* 0x19af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19b1:
	/* 0x19b1: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_19b6:
	/* 0x19b6: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_19b9:
	/* 0x19b9: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_19be:
	/* 0x19be: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19c3:
	/* 0x19c3: lea    rdi,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_19c7:
	/* 0x19c7: mov    ecx,0x91 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 145ULL);
x86_l_19cc:
	/* 0x19cc: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_19d1:
	/* 0x19d1: mov    esi,0x91 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 145ULL);
x86_l_19d6:
	/* 0x19d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19d8:
	/* 0x19d8: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_19db:
	/* 0x19db: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_19de:
	/* 0x19de: js     2304 <generic_usdt_process_event+0x2304> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8964ULL;
	}
x86_l_19e4:
	/* 0x19e4: lea    eax,[rsi-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_19e7:
	/* 0x19e7: mov    DWORD PTR [r15],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19ea:
	/* 0x19ea: add    rsi,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_19ee:
	/* 0x19ee: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_19f1:
	/* 0x19f1: jmp    38df <generic_usdt_process_event+0x38df> */
	return 14559ULL;
x86_l_19f6:
	/* 0x19f6: mov    edx,0x120 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 288ULL);
x86_l_19fb:
	/* 0x19fb: add    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_1a00:
	/* 0x1a00: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a05:
	/* 0x1a05: lea    rdi,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1a09:
	/* 0x1a09: mov    ecx,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_1a0e:
	/* 0x1a0e: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1a13:
	/* 0x1a13: mov    esi,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_1a18:
	/* 0x1a18: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a1a:
	/* 0x1a1a: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1a1d:
	/* 0x1a1d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a20:
	/* 0x1a20: js     38da <generic_usdt_process_event+0x38da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14554ULL;
	}
x86_l_1a26:
	/* 0x1a26: lea    eax,[rsi-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1a29:
	/* 0x1a29: mov    DWORD PTR [r15],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a2c:
	/* 0x1a2c: add    rsi,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_1a30:
	/* 0x1a30: jmp    38da <generic_usdt_process_event+0x38da> */
	return 14554ULL;
x86_l_1a35:
	/* 0x1a35: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1a38:
	/* 0x1a38: mov    rcx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1a40:
	/* 0x1a40: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1a43:
	/* 0x1a43: add    rax,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_1a49:
	/* 0x1a49: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a4e:
	/* 0x1a4e: mov    QWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_1a5a:
	/* 0x1a5a: test   r12b,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R12, X86_WIDTH_8, 16ULL);
x86_l_1a5e:
	/* 0x1a5e: jne    207d <generic_usdt_process_event+0x207d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8317ULL;
	}
x86_l_1a64:
	/* 0x1a64: and    r12d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1a68:
	/* 0x1a68: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a6a:
	/* 0x1a6a: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_1a6e:
	/* 0x1a6e: jle    23f2 <generic_usdt_process_event+0x23f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 9202ULL;
	}
x86_l_1a74:
	/* 0x1a74: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_1a78:
	/* 0x1a78: je     2bfd <generic_usdt_process_event+0x2bfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11261ULL;
	}
x86_l_1a7e:
	/* 0x1a7e: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_1a82:
	/* 0x1a82: je     2c06 <generic_usdt_process_event+0x2c06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11270ULL;
	}
x86_l_1a88:
	/* 0x1a88: cmp    r12d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 5ULL);
x86_l_1a8c:
	/* 0x1a8c: jne    2c19 <generic_usdt_process_event+0x2c19> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11289ULL;
	}
x86_l_1a92:
	/* 0x1a92: add    r15,0x5e70 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24176ULL);
x86_l_1a99:
	/* 0x1a99: jmp    2c16 <generic_usdt_process_event+0x2c16> */
	return 11286ULL;
x86_l_1a9e:
	/* 0x1a9e: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1aa3:
	/* 0x1aa3: lea    r15,[r12+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1aa8:
	/* 0x1aa8: lea    rax,[r12+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1aad:
	/* 0x1aad: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ab2:
	/* 0x1ab2: mov    r13,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1aba:
	/* 0x1aba: lea    rdx,[r13+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1abe:
	/* 0x1abe: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1ac3:
	/* 0x1ac3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ac8:
	/* 0x1ac8: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1acb:
	/* 0x1acb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ad0:
	/* 0x1ad0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ad2:
	/* 0x1ad2: lea    rdi,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1ad7:
	/* 0x1ad7: lea    rdx,[r13+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1adb:
	/* 0x1adb: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1ae0:
	/* 0x1ae0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ae5:
	/* 0x1ae5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1aea:
	/* 0x1aea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aec:
	/* 0x1aec: lea    rdi,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1af1:
	/* 0x1af1: lea    rdx,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1af5:
	/* 0x1af5: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1afa:
	/* 0x1afa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1aff:
	/* 0x1aff: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b04:
	/* 0x1b04: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b06:
	/* 0x1b06: lea    rdi,[r12+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1b0b:
	/* 0x1b0b: lea    rdx,[r13+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1b0f:
	/* 0x1b0f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1b14:
	/* 0x1b14: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b19:
	/* 0x1b19: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b1e:
	/* 0x1b1e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b20:
	/* 0x1b20: lea    rdi,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b25:
	/* 0x1b25: lea    rdx,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b29:
	/* 0x1b29: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1b2e:
	/* 0x1b2e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b33:
	/* 0x1b33: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b38:
	/* 0x1b38: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b3a:
	/* 0x1b3a: lea    rdi,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1b3f:
	/* 0x1b3f: lea    rdx,[r13+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1b43:
	/* 0x1b43: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1b48:
	/* 0x1b48: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b4d:
	/* 0x1b4d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b52:
	/* 0x1b52: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b54:
	/* 0x1b54: lea    rdi,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b59:
	/* 0x1b59: lea    rdx,[r13+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b5d:
	/* 0x1b5d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1b62:
	/* 0x1b62: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b67:
	/* 0x1b67: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b6c:
	/* 0x1b6c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b6e:
	/* 0x1b6e: lea    rdi,[r12+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1b73:
	/* 0x1b73: lea    rdx,[r13+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1b77:
	/* 0x1b77: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1b7c:
	/* 0x1b7c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b81:
	/* 0x1b81: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b86:
	/* 0x1b86: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b88:
	/* 0x1b88: mov    DWORD PTR [r12+0x24],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_1b91:
	/* 0x1b91: lea    rdi,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b96:
	/* 0x1b96: lea    rdx,[r13+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b9a:
	/* 0x1b9a: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1b9f:
	/* 0x1b9f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ba4:
	/* 0x1ba4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ba9:
	/* 0x1ba9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bab:
	/* 0x1bab: lea    rdi,[r12+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1bb0:
	/* 0x1bb0: lea    rdx,[r13+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1bb4:
	/* 0x1bb4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1bb9:
	/* 0x1bb9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1bbe:
	/* 0x1bbe: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bc3:
	/* 0x1bc3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bc5:
	/* 0x1bc5: lea    rdi,[r12+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1bca:
	/* 0x1bca: lea    rdx,[r13+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1bce:
	/* 0x1bce: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1bd3:
	/* 0x1bd3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1bd8:
	/* 0x1bd8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bdd:
	/* 0x1bdd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bdf:
	/* 0x1bdf: lea    rdx,[r13+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1be3:
	/* 0x1be3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1be8:
	/* 0x1be8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1bed:
	/* 0x1bed: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1bf0:
	/* 0x1bf0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
	return 7157ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_generic_usdt_process_event_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7157ULL: goto x86_l_1bf5;
	case 7159ULL: goto x86_l_1bf7;
	case 7166ULL: goto x86_l_1bfe;
	case 7171ULL: goto x86_l_1c03;
	case 7176ULL: goto x86_l_1c08;
	case 7181ULL: goto x86_l_1c0d;
	case 7186ULL: goto x86_l_1c12;
	case 7189ULL: goto x86_l_1c15;
	case 7191ULL: goto x86_l_1c17;
	case 7196ULL: goto x86_l_1c1c;
	case 7203ULL: goto x86_l_1c23;
	case 7208ULL: goto x86_l_1c28;
	case 7213ULL: goto x86_l_1c2d;
	case 7218ULL: goto x86_l_1c32;
	case 7223ULL: goto x86_l_1c37;
	case 7225ULL: goto x86_l_1c39;
	case 7230ULL: goto x86_l_1c3e;
	case 7237ULL: goto x86_l_1c45;
	case 7242ULL: goto x86_l_1c4a;
	case 7247ULL: goto x86_l_1c4f;
	case 7252ULL: goto x86_l_1c54;
	case 7254ULL: goto x86_l_1c56;
	case 7259ULL: goto x86_l_1c5b;
	case 7266ULL: goto x86_l_1c62;
	case 7271ULL: goto x86_l_1c67;
	case 7276ULL: goto x86_l_1c6c;
	case 7281ULL: goto x86_l_1c71;
	case 7283ULL: goto x86_l_1c73;
	case 7287ULL: goto x86_l_1c77;
	case 7294ULL: goto x86_l_1c7e;
	case 7299ULL: goto x86_l_1c83;
	case 7304ULL: goto x86_l_1c88;
	case 7307ULL: goto x86_l_1c8b;
	case 7312ULL: goto x86_l_1c90;
	case 7315ULL: goto x86_l_1c93;
	case 7317ULL: goto x86_l_1c95;
	case 7322ULL: goto x86_l_1c9a;
	case 7327ULL: goto x86_l_1c9f;
	case 7334ULL: goto x86_l_1ca6;
	case 7339ULL: goto x86_l_1cab;
	case 7344ULL: goto x86_l_1cb0;
	case 7347ULL: goto x86_l_1cb3;
	case 7352ULL: goto x86_l_1cb8;
	case 7355ULL: goto x86_l_1cbb;
	case 7360ULL: goto x86_l_1cc0;
	case 7362ULL: goto x86_l_1cc2;
	case 7366ULL: goto x86_l_1cc6;
	case 7374ULL: goto x86_l_1cce;
	case 7379ULL: goto x86_l_1cd3;
	case 7384ULL: goto x86_l_1cd8;
	case 7389ULL: goto x86_l_1cdd;
	case 7391ULL: goto x86_l_1cdf;
	case 7395ULL: goto x86_l_1ce3;
	case 7403ULL: goto x86_l_1ceb;
	case 7408ULL: goto x86_l_1cf0;
	case 7413ULL: goto x86_l_1cf5;
	case 7418ULL: goto x86_l_1cfa;
	case 7420ULL: goto x86_l_1cfc;
	case 7424ULL: goto x86_l_1d00;
	case 7431ULL: goto x86_l_1d07;
	case 7436ULL: goto x86_l_1d0c;
	case 7441ULL: goto x86_l_1d11;
	case 7444ULL: goto x86_l_1d14;
	case 7449ULL: goto x86_l_1d19;
	case 7452ULL: goto x86_l_1d1c;
	case 7454ULL: goto x86_l_1d1e;
	case 7459ULL: goto x86_l_1d23;
	case 7464ULL: goto x86_l_1d28;
	case 7468ULL: goto x86_l_1d2c;
	case 7473ULL: goto x86_l_1d31;
	case 7478ULL: goto x86_l_1d36;
	case 7481ULL: goto x86_l_1d39;
	case 7486ULL: goto x86_l_1d3e;
	case 7489ULL: goto x86_l_1d41;
	case 7494ULL: goto x86_l_1d46;
	case 7496ULL: goto x86_l_1d48;
	case 7500ULL: goto x86_l_1d4c;
	case 7505ULL: goto x86_l_1d51;
	case 7510ULL: goto x86_l_1d56;
	case 7515ULL: goto x86_l_1d5b;
	case 7520ULL: goto x86_l_1d60;
	case 7522ULL: goto x86_l_1d62;
	case 7526ULL: goto x86_l_1d66;
	case 7531ULL: goto x86_l_1d6b;
	case 7536ULL: goto x86_l_1d70;
	case 7541ULL: goto x86_l_1d75;
	case 7546ULL: goto x86_l_1d7a;
	case 7548ULL: goto x86_l_1d7c;
	case 7552ULL: goto x86_l_1d80;
	case 7557ULL: goto x86_l_1d85;
	case 7562ULL: goto x86_l_1d8a;
	case 7567ULL: goto x86_l_1d8f;
	case 7572ULL: goto x86_l_1d94;
	case 7574ULL: goto x86_l_1d96;
	case 7578ULL: goto x86_l_1d9a;
	case 7582ULL: goto x86_l_1d9e;
	case 7587ULL: goto x86_l_1da3;
	case 7592ULL: goto x86_l_1da8;
	case 7595ULL: goto x86_l_1dab;
	case 7600ULL: goto x86_l_1db0;
	case 7603ULL: goto x86_l_1db3;
	case 7605ULL: goto x86_l_1db5;
	case 7610ULL: goto x86_l_1dba;
	case 7615ULL: goto x86_l_1dbf;
	case 7620ULL: goto x86_l_1dc4;
	case 7625ULL: goto x86_l_1dc9;
	case 7630ULL: goto x86_l_1dce;
	case 7638ULL: goto x86_l_1dd6;
	case 7641ULL: goto x86_l_1dd9;
	case 7646ULL: goto x86_l_1dde;
	case 7649ULL: goto x86_l_1de1;
	case 7651ULL: goto x86_l_1de3;
	case 7655ULL: goto x86_l_1de7;
	case 7660ULL: goto x86_l_1dec;
	case 7665ULL: goto x86_l_1df1;
	case 7670ULL: goto x86_l_1df6;
	case 7675ULL: goto x86_l_1dfb;
	case 7677ULL: goto x86_l_1dfd;
	case 7681ULL: goto x86_l_1e01;
	case 7685ULL: goto x86_l_1e05;
	case 7690ULL: goto x86_l_1e0a;
	case 7695ULL: goto x86_l_1e0f;
	case 7698ULL: goto x86_l_1e12;
	case 7703ULL: goto x86_l_1e17;
	case 7706ULL: goto x86_l_1e1a;
	case 7711ULL: goto x86_l_1e1f;
	case 7715ULL: goto x86_l_1e23;
	case 7720ULL: goto x86_l_1e28;
	case 7725ULL: goto x86_l_1e2d;
	case 7730ULL: goto x86_l_1e32;
	case 7735ULL: goto x86_l_1e37;
	case 7737ULL: goto x86_l_1e39;
	case 7741ULL: goto x86_l_1e3d;
	case 7744ULL: goto x86_l_1e40;
	case 7749ULL: goto x86_l_1e45;
	case 7752ULL: goto x86_l_1e48;
	case 7757ULL: goto x86_l_1e4d;
	case 7762ULL: goto x86_l_1e52;
	case 7767ULL: goto x86_l_1e57;
	case 7772ULL: goto x86_l_1e5c;
	case 7777ULL: goto x86_l_1e61;
	case 7779ULL: goto x86_l_1e63;
	case 7783ULL: goto x86_l_1e67;
	case 7787ULL: goto x86_l_1e6b;
	case 7791ULL: goto x86_l_1e6f;
	case 7796ULL: goto x86_l_1e74;
	case 7801ULL: goto x86_l_1e79;
	case 7806ULL: goto x86_l_1e7e;
	case 7811ULL: goto x86_l_1e83;
	case 7814ULL: goto x86_l_1e86;
	case 7816ULL: goto x86_l_1e88;
	case 7820ULL: goto x86_l_1e8c;
	case 7825ULL: goto x86_l_1e91;
	case 7830ULL: goto x86_l_1e96;
	case 7833ULL: goto x86_l_1e99;
	case 7838ULL: goto x86_l_1e9e;
	case 7843ULL: goto x86_l_1ea3;
	case 7848ULL: goto x86_l_1ea8;
	case 7851ULL: goto x86_l_1eab;
	case 7856ULL: goto x86_l_1eb0;
	case 7858ULL: goto x86_l_1eb2;
	case 7863ULL: goto x86_l_1eb7;
	case 7868ULL: goto x86_l_1ebc;
	case 7873ULL: goto x86_l_1ec1;
	case 7881ULL: goto x86_l_1ec9;
	case 7889ULL: goto x86_l_1ed1;
	case 7897ULL: goto x86_l_1ed9;
	case 7905ULL: goto x86_l_1ee1;
	case 7913ULL: goto x86_l_1ee9;
	case 7921ULL: goto x86_l_1ef1;
	case 7929ULL: goto x86_l_1ef9;
	case 7937ULL: goto x86_l_1f01;
	case 7945ULL: goto x86_l_1f09;
	case 7952ULL: goto x86_l_1f10;
	case 7957ULL: goto x86_l_1f15;
	case 7962ULL: goto x86_l_1f1a;
	case 7967ULL: goto x86_l_1f1f;
	case 7972ULL: goto x86_l_1f24;
	case 7975ULL: goto x86_l_1f27;
	case 7977ULL: goto x86_l_1f29;
	case 7980ULL: goto x86_l_1f2c;
	case 7986ULL: goto x86_l_1f32;
	case 7988ULL: goto x86_l_1f34;
	case 7993ULL: goto x86_l_1f39;
	case 8000ULL: goto x86_l_1f40;
	case 8005ULL: goto x86_l_1f45;
	case 8010ULL: goto x86_l_1f4a;
	case 8018ULL: goto x86_l_1f52;
	case 8027ULL: goto x86_l_1f5b;
	case 8034ULL: goto x86_l_1f62;
	case 8039ULL: goto x86_l_1f67;
	case 8044ULL: goto x86_l_1f6c;
	case 8049ULL: goto x86_l_1f71;
	case 8053ULL: goto x86_l_1f75;
	case 8055ULL: goto x86_l_1f77;
	case 8058ULL: goto x86_l_1f7a;
	case 8064ULL: goto x86_l_1f80;
	case 8067ULL: goto x86_l_1f83;
	case 8071ULL: goto x86_l_1f87;
	case 8075ULL: goto x86_l_1f8b;
	case 8079ULL: goto x86_l_1f8f;
	case 8082ULL: goto x86_l_1f92;
	case 8086ULL: goto x86_l_1f96;
	case 8091ULL: goto x86_l_1f9b;
	case 8096ULL: goto x86_l_1fa0;
	case 8101ULL: goto x86_l_1fa5;
	case 8109ULL: goto x86_l_1fad;
	case 8114ULL: goto x86_l_1fb2;
	case 8116ULL: goto x86_l_1fb4;
	case 8119ULL: goto x86_l_1fb7;
	case 8125ULL: goto x86_l_1fbd;
	case 8130ULL: goto x86_l_1fc2;
	case 8133ULL: goto x86_l_1fc5;
	case 8139ULL: goto x86_l_1fcb;
	case 8141ULL: goto x86_l_1fcd;
	case 8147ULL: goto x86_l_1fd3;
	case 8150ULL: goto x86_l_1fd6;
	case 8156ULL: goto x86_l_1fdc;
	case 8159ULL: goto x86_l_1fdf;
	case 8165ULL: goto x86_l_1fe5;
	case 8172ULL: goto x86_l_1fec;
	case 8176ULL: goto x86_l_1ff0;
	case 8181ULL: goto x86_l_1ff5;
	case 8186ULL: goto x86_l_1ffa;
	case 8191ULL: goto x86_l_1fff;
	case 8196ULL: goto x86_l_2004;
	case 8201ULL: goto x86_l_2009;
	case 8206ULL: goto x86_l_200e;
	case 8208ULL: goto x86_l_2010;
	case 8213ULL: goto x86_l_2015;
	case 8218ULL: goto x86_l_201a;
	case 8223ULL: goto x86_l_201f;
	case 8226ULL: goto x86_l_2022;
	case 8231ULL: goto x86_l_2027;
	case 8233ULL: goto x86_l_2029;
	case 8238ULL: goto x86_l_202e;
	case 8242ULL: goto x86_l_2032;
	case 8247ULL: goto x86_l_2037;
	case 8251ULL: goto x86_l_203b;
	case 8256ULL: goto x86_l_2040;
	case 8261ULL: goto x86_l_2045;
	case 8266ULL: goto x86_l_204a;
	case 8269ULL: goto x86_l_204d;
	case 8271ULL: goto x86_l_204f;
	case 8275ULL: goto x86_l_2053;
	case 8280ULL: goto x86_l_2058;
	case 8285ULL: goto x86_l_205d;
	case 8290ULL: goto x86_l_2062;
	case 8293ULL: goto x86_l_2065;
	case 8295ULL: goto x86_l_2067;
	case 8300ULL: goto x86_l_206c;
	case 8307ULL: goto x86_l_2073;
	case 8312ULL: goto x86_l_2078;
	case 8317ULL: goto x86_l_207d;
	case 8322ULL: goto x86_l_2082;
	case 8324ULL: goto x86_l_2084;
	case 8328ULL: goto x86_l_2088;
	case 8330ULL: goto x86_l_208a;
	case 8334ULL: goto x86_l_208e;
	case 8338ULL: goto x86_l_2092;
	case 8342ULL: goto x86_l_2096;
	case 8347ULL: goto x86_l_209b;
	case 8355ULL: goto x86_l_20a3;
	case 8360ULL: goto x86_l_20a8;
	case 8369ULL: goto x86_l_20b1;
	case 8374ULL: goto x86_l_20b6;
	case 8382ULL: goto x86_l_20be;
	case 8389ULL: goto x86_l_20c5;
	case 8391ULL: goto x86_l_20c7;
	case 8396ULL: goto x86_l_20cc;
	case 8401ULL: goto x86_l_20d1;
	case 8406ULL: goto x86_l_20d6;
	case 8408ULL: goto x86_l_20d8;
	case 8410ULL: goto x86_l_20da;
	case 8413ULL: goto x86_l_20dd;
	case 8419ULL: goto x86_l_20e3;
	case 8421ULL: goto x86_l_20e5;
	case 8426ULL: goto x86_l_20ea;
	case 8433ULL: goto x86_l_20f1;
	case 8443ULL: goto x86_l_20fb;
	case 8448ULL: goto x86_l_2100;
	case 8455ULL: goto x86_l_2107;
	case 8460ULL: goto x86_l_210c;
	case 8465ULL: goto x86_l_2111;
	case 8467ULL: goto x86_l_2113;
	case 8470ULL: goto x86_l_2116;
	case 8476ULL: goto x86_l_211c;
	case 8478ULL: goto x86_l_211e;
	case 8483ULL: goto x86_l_2123;
	case 8487ULL: goto x86_l_2127;
	case 8492ULL: goto x86_l_212c;
	case 8497ULL: goto x86_l_2131;
	case 8502ULL: goto x86_l_2136;
	case 8507ULL: goto x86_l_213b;
	case 8509ULL: goto x86_l_213d;
	case 8514ULL: goto x86_l_2142;
	case 8519ULL: goto x86_l_2147;
	case 8525ULL: goto x86_l_214d;
	case 8529ULL: goto x86_l_2151;
	case 8534ULL: goto x86_l_2156;
	case 8539ULL: goto x86_l_215b;
	case 8544ULL: goto x86_l_2160;
	case 8549ULL: goto x86_l_2165;
	case 8552ULL: goto x86_l_2168;
	case 8554ULL: goto x86_l_216a;
	case 8559ULL: goto x86_l_216f;
	case 8564ULL: goto x86_l_2174;
	case 8568ULL: goto x86_l_2178;
	case 8573ULL: goto x86_l_217d;
	case 8578ULL: goto x86_l_2182;
	case 8583ULL: goto x86_l_2187;
	case 8585ULL: goto x86_l_2189;
	case 8590ULL: goto x86_l_218e;
	case 8596ULL: goto x86_l_2194;
	case 8604ULL: goto x86_l_219c;
	case 8609ULL: goto x86_l_21a1;
	case 8614ULL: goto x86_l_21a6;
	case 8619ULL: goto x86_l_21ab;
	case 8621ULL: goto x86_l_21ad;
	case 8629ULL: goto x86_l_21b5;
	case 8635ULL: goto x86_l_21bb;
	case 8640ULL: goto x86_l_21c0;
	case 8645ULL: goto x86_l_21c5;
	case 8650ULL: goto x86_l_21ca;
	case 8655ULL: goto x86_l_21cf;
	case 8660ULL: goto x86_l_21d4;
	case 8663ULL: goto x86_l_21d7;
	case 8665ULL: goto x86_l_21d9;
	case 8670ULL: goto x86_l_21de;
	case 8676ULL: goto x86_l_21e4;
	case 8681ULL: goto x86_l_21e9;
	case 8686ULL: goto x86_l_21ee;
	case 8691ULL: goto x86_l_21f3;
	case 8696ULL: goto x86_l_21f8;
	case 8699ULL: goto x86_l_21fb;
	case 8701ULL: goto x86_l_21fd;
	case 8705ULL: goto x86_l_2201;
	case 8710ULL: goto x86_l_2206;
	case 8715ULL: goto x86_l_220b;
	case 8720ULL: goto x86_l_2210;
	case 8725ULL: goto x86_l_2215;
	case 8728ULL: goto x86_l_2218;
	case 8730ULL: goto x86_l_221a;
	case 8735ULL: goto x86_l_221f;
	case 8740ULL: goto x86_l_2224;
	case 8745ULL: goto x86_l_2229;
	case 8748ULL: goto x86_l_222c;
	case 8753ULL: goto x86_l_2231;
	case 8755ULL: goto x86_l_2233;
	case 8758ULL: goto x86_l_2236;
	case 8761ULL: goto x86_l_2239;
	case 8764ULL: goto x86_l_223c;
	case 8772ULL: goto x86_l_2244;
	case 8774ULL: goto x86_l_2246;
	case 8777ULL: goto x86_l_2249;
	case 8781ULL: goto x86_l_224d;
	case 8784ULL: goto x86_l_2250;
	case 8788ULL: goto x86_l_2254;
	case 8790ULL: goto x86_l_2256;
	case 8793ULL: goto x86_l_2259;
	case 8795ULL: goto x86_l_225b;
	case 8799ULL: goto x86_l_225f;
	case 8802ULL: goto x86_l_2262;
	case 8808ULL: goto x86_l_2268;
	case 8814ULL: goto x86_l_226e;
	case 8820ULL: goto x86_l_2274;
	case 8823ULL: goto x86_l_2277;
	case 8825ULL: goto x86_l_2279;
	case 8830ULL: goto x86_l_227e;
	case 8832ULL: goto x86_l_2280;
	case 8835ULL: goto x86_l_2283;
	case 8839ULL: goto x86_l_2287;
	case 8842ULL: goto x86_l_228a;
	case 8845ULL: goto x86_l_228d;
	case 8848ULL: goto x86_l_2290;
	case 8853ULL: goto x86_l_2295;
	case 8855ULL: goto x86_l_2297;
	case 8860ULL: goto x86_l_229c;
	case 8863ULL: goto x86_l_229f;
	case 8869ULL: goto x86_l_22a5;
	case 8874ULL: goto x86_l_22aa;
	case 8879ULL: goto x86_l_22af;
	case 8884ULL: goto x86_l_22b4;
	case 8889ULL: goto x86_l_22b9;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1bf5:
	/* 0x1bf5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bf7:
	/* 0x1bf7: add    r13,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_1bfe:
	/* 0x1bfe: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1c03:
	/* 0x1c03: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1c08:
	/* 0x1c08: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c0d:
	/* 0x1c0d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c12:
	/* 0x1c12: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1c15:
	/* 0x1c15: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c17:
	/* 0x1c17: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1c1c:
	/* 0x1c1c: lea    rdx,[r15+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1c23:
	/* 0x1c23: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1c28:
	/* 0x1c28: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c2d:
	/* 0x1c2d: mov    rdi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c32:
	/* 0x1c32: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c37:
	/* 0x1c37: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c39:
	/* 0x1c39: lea    rdi,[r12+0x44] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_1c3e:
	/* 0x1c3e: lea    rdx,[r15+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_1c45:
	/* 0x1c45: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1c4a:
	/* 0x1c4a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c4f:
	/* 0x1c4f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c54:
	/* 0x1c54: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c56:
	/* 0x1c56: lea    rdi,[r12+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1c5b:
	/* 0x1c5b: lea    rdx,[r15+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1c62:
	/* 0x1c62: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1c67:
	/* 0x1c67: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c6c:
	/* 0x1c6c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c71:
	/* 0x1c71: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c73:
	/* 0x1c73: add    r12,0x4c */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 76ULL);
x86_l_1c77:
	/* 0x1c77: add    r15,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_1c7e:
	/* 0x1c7e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1c83:
	/* 0x1c83: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c88:
	/* 0x1c88: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1c8b:
	/* 0x1c8b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c90:
	/* 0x1c90: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1c93:
	/* 0x1c93: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c95:
	/* 0x1c95: mov    esi,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 80ULL);
x86_l_1c9a:
	/* 0x1c9a: jmp    38da <generic_usdt_process_event+0x38da> */
	return 14554ULL;
x86_l_1c9f:
	/* 0x1c9f: lea    rdx,[r15+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1ca6:
	/* 0x1ca6: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1cab:
	/* 0x1cab: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1cb0:
	/* 0x1cb0: mov    r12,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_64);
x86_l_1cb3:
	/* 0x1cb3: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cb8:
	/* 0x1cb8: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1cbb:
	/* 0x1cbb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1cc0:
	/* 0x1cc0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cc2:
	/* 0x1cc2: lea    rdi,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1cc6:
	/* 0x1cc6: lea    rdx,[r12+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_1cce:
	/* 0x1cce: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1cd3:
	/* 0x1cd3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1cd8:
	/* 0x1cd8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1cdd:
	/* 0x1cdd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cdf:
	/* 0x1cdf: lea    rdi,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ce3:
	/* 0x1ce3: lea    rdx,[r12+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1ceb:
	/* 0x1ceb: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1cf0:
	/* 0x1cf0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1cf5:
	/* 0x1cf5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1cfa:
	/* 0x1cfa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cfc:
	/* 0x1cfc: add    r15,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1d00:
	/* 0x1d00: add    r12,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_1d07:
	/* 0x1d07: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d0c:
	/* 0x1d0c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d11:
	/* 0x1d11: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1d14:
	/* 0x1d14: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d19:
	/* 0x1d19: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1d1c:
	/* 0x1d1c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d1e:
	/* 0x1d1e: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1d23:
	/* 0x1d23: jmp    38da <generic_usdt_process_event+0x38da> */
	return 14554ULL;
x86_l_1d28:
	/* 0x1d28: lea    rdx,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d2c:
	/* 0x1d2c: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d31:
	/* 0x1d31: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d36:
	/* 0x1d36: mov    r12,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_64);
x86_l_1d39:
	/* 0x1d39: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d3e:
	/* 0x1d3e: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1d41:
	/* 0x1d41: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d46:
	/* 0x1d46: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d48:
	/* 0x1d48: lea    rdi,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d4c:
	/* 0x1d4c: lea    rdx,[r12+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1d51:
	/* 0x1d51: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d56:
	/* 0x1d56: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d5b:
	/* 0x1d5b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d60:
	/* 0x1d60: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d62:
	/* 0x1d62: lea    rdi,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d66:
	/* 0x1d66: lea    rdx,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d6b:
	/* 0x1d6b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d70:
	/* 0x1d70: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d75:
	/* 0x1d75: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d7a:
	/* 0x1d7a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d7c:
	/* 0x1d7c: lea    rdi,[r15+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1d80:
	/* 0x1d80: lea    rdx,[r12+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1d85:
	/* 0x1d85: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d8a:
	/* 0x1d8a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d8f:
	/* 0x1d8f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d94:
	/* 0x1d94: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d96:
	/* 0x1d96: add    r15,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1d9a:
	/* 0x1d9a: add    r12,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_1d9e:
	/* 0x1d9e: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1da3:
	/* 0x1da3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1da8:
	/* 0x1da8: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1dab:
	/* 0x1dab: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1db0:
	/* 0x1db0: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1db3:
	/* 0x1db3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1db5:
	/* 0x1db5: mov    esi,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 32ULL);
x86_l_1dba:
	/* 0x1dba: jmp    38da <generic_usdt_process_event+0x38da> */
	return 14554ULL;
x86_l_1dbf:
	/* 0x1dbf: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1dc4:
	/* 0x1dc4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1dc9:
	/* 0x1dc9: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1dce:
	/* 0x1dce: mov    r12,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1dd6:
	/* 0x1dd6: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1dd9:
	/* 0x1dd9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1dde:
	/* 0x1dde: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1de1:
	/* 0x1de1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1de3:
	/* 0x1de3: lea    rdi,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1de7:
	/* 0x1de7: lea    rdx,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1dec:
	/* 0x1dec: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1df1:
	/* 0x1df1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1df6:
	/* 0x1df6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1dfb:
	/* 0x1dfb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dfd:
	/* 0x1dfd: add    r15,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1e01:
	/* 0x1e01: add    r12,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_1e05:
	/* 0x1e05: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1e0a:
	/* 0x1e0a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e0f:
	/* 0x1e0f: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1e12:
	/* 0x1e12: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1e17:
	/* 0x1e17: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1e1a:
	/* 0x1e1a: jmp    1eb0 <generic_usdt_process_event+0x1eb0> */
	goto x86_l_1eb0;
x86_l_1e1f:
	/* 0x1e1f: lea    rdx,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1e23:
	/* 0x1e23: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1e28:
	/* 0x1e28: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1e2d:
	/* 0x1e2d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e32:
	/* 0x1e32: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e37:
	/* 0x1e37: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e39:
	/* 0x1e39: mov    eax,DWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1e3d:
	/* 0x1e3d: mov    r12,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_64);
x86_l_1e40:
	/* 0x1e40: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e45:
	/* 0x1e45: mov    DWORD PTR [r15],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e48:
	/* 0x1e48: lea    rdx,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1e4d:
	/* 0x1e4d: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1e52:
	/* 0x1e52: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1e57:
	/* 0x1e57: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e5c:
	/* 0x1e5c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e61:
	/* 0x1e61: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e63:
	/* 0x1e63: mov    eax,DWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1e67:
	/* 0x1e67: mov    DWORD PTR [r15+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1e6b:
	/* 0x1e6b: add    r12,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_1e6f:
	/* 0x1e6f: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1e74:
	/* 0x1e74: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1e79:
	/* 0x1e79: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1e7e:
	/* 0x1e7e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e83:
	/* 0x1e83: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1e86:
	/* 0x1e86: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e88:
	/* 0x1e88: add    r15,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1e8c:
	/* 0x1e8c: mov    edx,0x3e8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1000ULL);
x86_l_1e91:
	/* 0x1e91: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1e96:
	/* 0x1e96: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1e99:
	/* 0x1e99: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1e9e:
	/* 0x1e9e: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1ea3:
	/* 0x1ea3: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_1ea8:
	/* 0x1ea8: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1eab:
	/* 0x1eab: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1eb0:
	/* 0x1eb0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1eb2:
	/* 0x1eb2: mov    esi,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 24ULL);
x86_l_1eb7:
	/* 0x1eb7: jmp    38da <generic_usdt_process_event+0x38da> */
	return 14554ULL;
x86_l_1ebc:
	/* 0x1ebc: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ec1:
	/* 0x1ec1: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1ec9:
	/* 0x1ec9: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1ed1:
	/* 0x1ed1: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1ed9:
	/* 0x1ed9: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1ee1:
	/* 0x1ee1: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1ee9:
	/* 0x1ee9: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1ef1:
	/* 0x1ef1: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1ef9:
	/* 0x1ef9: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1f01:
	/* 0x1f01: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1f09:
	/* 0x1f09: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f10:
	/* 0x1f10: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1f15:
	/* 0x1f15: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1f1a:
	/* 0x1f1a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f1f:
	/* 0x1f1f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f24:
	/* 0x1f24: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1f27:
	/* 0x1f27: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f29:
	/* 0x1f29: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f2c:
	/* 0x1f2c: je     232c <generic_usdt_process_event+0x232c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9004ULL;
	}
x86_l_1f32:
	/* 0x1f32: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f34:
	/* 0x1f34: jmp    38da <generic_usdt_process_event+0x38da> */
	return 14554ULL;
x86_l_1f39:
	/* 0x1f39: mov    rsi,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1f40:
	/* 0x1f40: jmp    38da <generic_usdt_process_event+0x38da> */
	return 14554ULL;
x86_l_1f45:
	/* 0x1f45: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1f4a:
	/* 0x1f4a: mov    DWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_1f52:
	/* 0x1f52: movzx  r13d,WORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 192ULL);
x86_l_1f5b:
	/* 0x1f5b: mov    rdi,QWORD PTR [rip+0x9e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_ipv6_ext_heap)));
x86_l_1f62:
	/* 0x1f62: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1f67:
	/* 0x1f67: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f6c:
	/* 0x1f6c: mov    QWORD PTR [rsp+0x30],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f71:
	/* 0x1f71: lea    r12,[rcx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_1f75:
	/* 0x1f75: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f77:
	/* 0x1f77: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f7a:
	/* 0x1f7a: je     3716 <generic_usdt_process_event+0x3716> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14102ULL;
	}
x86_l_1f80:
	/* 0x1f80: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1f83:
	/* 0x1f83: mov    WORD PTR [rax],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f87:
	/* 0x1f87: mov    BYTE PTR [rax+0x5],0xff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21474836735ULL);
x86_l_1f8b:
	/* 0x1f8b: mov    BYTE PTR [rax+0x7],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30064771072ULL);
x86_l_1f8f:
	/* 0x1f8f: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1f92:
	/* 0x1f92: add    rdi,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 6ULL);
x86_l_1f96:
	/* 0x1f96: lea    rdx,[r12+0x6] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_1f9b:
	/* 0x1f9b: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1fa0:
	/* 0x1fa0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1fa5:
	/* 0x1fa5: mov    QWORD PTR [rsp+0x98],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1fad:
	/* 0x1fad: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1fb2:
	/* 0x1fb2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fb4:
	/* 0x1fb4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1fb7:
	/* 0x1fb7: js     3716 <generic_usdt_process_event+0x3716> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14102ULL;
	}
x86_l_1fbd:
	/* 0x1fbd: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_1fc2:
	/* 0x1fc2: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_1fc5:
	/* 0x1fc5: jg     29b1 <generic_usdt_process_event+0x29b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10673ULL;
	}
x86_l_1fcb:
	/* 0x1fcb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1fcd:
	/* 0x1fcd: je     2a51 <generic_usdt_process_event+0x2a51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10833ULL;
	}
x86_l_1fd3:
	/* 0x1fd3: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_1fd6:
	/* 0x1fd6: je     2a51 <generic_usdt_process_event+0x2a51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10833ULL;
	}
x86_l_1fdc:
	/* 0x1fdc: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_1fdf:
	/* 0x1fdf: jne    2d8a <generic_usdt_process_event+0x2d8a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11658ULL;
	}
x86_l_1fe5:
	/* 0x1fe5: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_1fec:
	/* 0x1fec: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_1ff0:
	/* 0x1ff0: jmp    2cbc <generic_usdt_process_event+0x2cbc> */
	return 11452ULL;
x86_l_1ff5:
	/* 0x1ff5: lea    rdx,[r12+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1ffa:
	/* 0x1ffa: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1fff:
	/* 0x1fff: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2004:
	/* 0x2004: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2009:
	/* 0x2009: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_200e:
	/* 0x200e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2010:
	/* 0x2010: lea    rdx,[r12+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2015:
	/* 0x2015: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_201a:
	/* 0x201a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_201f:
	/* 0x201f: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_2022:
	/* 0x2022: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2027:
	/* 0x2027: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2029:
	/* 0x2029: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_202e:
	/* 0x202e: lea    rdi,[r13+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2032:
	/* 0x2032: lea    r15,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2037:
	/* 0x2037: add    r12,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_203b:
	/* 0x203b: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2040:
	/* 0x2040: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2045:
	/* 0x2045: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_204a:
	/* 0x204a: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_204d:
	/* 0x204d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_204f:
	/* 0x204f: lea    rdi,[r13+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_2053:
	/* 0x2053: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2058:
	/* 0x2058: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_205d:
	/* 0x205d: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2062:
	/* 0x2062: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2065:
	/* 0x2065: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2067:
	/* 0x2067: movzx  eax,WORD PTR [r13+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_206c:
	/* 0x206c: movbe  WORD PTR [r13+0x22],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_2073:
	/* 0x2073: mov    esi,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 64ULL);
x86_l_2078:
	/* 0x2078: jmp    38da <generic_usdt_process_event+0x38da> */
	return 14554ULL;
x86_l_207d:
	/* 0x207d: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2082:
	/* 0x2082: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2084:
	/* 0x2084: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_2088:
	/* 0x2088: jne    208e <generic_usdt_process_event+0x208e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_208e;
	}
x86_l_208a:
	/* 0x208a: mov    rax,QWORD PTR [rbx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_208e:
	/* 0x208e: mov    rcx,QWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2092:
	/* 0x2092: mov    rdx,QWORD PTR [r15+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2096:
	/* 0x2096: mov    QWORD PTR [rsp+0x38],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_209b:
	/* 0x209b: mov    rcx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_20a3:
	/* 0x20a3: mov    QWORD PTR [rsp+0x40],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_20a8:
	/* 0x20a8: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_20b1:
	/* 0x20b1: mov    QWORD PTR [rsp+0x78],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_20b6:
	/* 0x20b6: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_20be:
	/* 0x20be: mov    rdi,QWORD PTR [rip+0x9db] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_20c5:
	/* 0x20c5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20c7:
	/* 0x20c7: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_20cc:
	/* 0x20cc: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_20d1:
	/* 0x20d1: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_20d6:
	/* 0x20d6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20d8:
	/* 0x20d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20da:
	/* 0x20da: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_20dd:
	/* 0x20dd: je     2a08 <generic_usdt_process_event+0x2a08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10760ULL;
	}
x86_l_20e3:
	/* 0x20e3: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_20e5:
	/* 0x20e5: mov    WORD PTR [rsp+0x10],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20ea:
	/* 0x20ea: mov    WORD PTR [rsp+0x12],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 77309411333ULL);
x86_l_20f1:
	/* 0x20f1: movabs rax,0x200000046 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934662ULL);
x86_l_20fb:
	/* 0x20fb: mov    QWORD PTR [rsp+0x14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2100:
	/* 0x2100: mov    rdi,QWORD PTR [rip+0x9db] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2107:
	/* 0x2107: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_210c:
	/* 0x210c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2111:
	/* 0x2111: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2113:
	/* 0x2113: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2116:
	/* 0x2116: je     29de <generic_usdt_process_event+0x29de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10718ULL;
	}
x86_l_211c:
	/* 0x211c: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_211e:
	/* 0x211e: jmp    2a08 <generic_usdt_process_event+0x2a08> */
	return 10760ULL;
x86_l_2123:
	/* 0x2123: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2127:
	/* 0x2127: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_212c:
	/* 0x212c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2131:
	/* 0x2131: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2136:
	/* 0x2136: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_213b:
	/* 0x213b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_213d:
	/* 0x213d: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2142:
	/* 0x2142: cmp    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_2147:
	/* 0x2147: je     880 <generic_usdt_process_event+0x880> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2176ULL;
	}
x86_l_214d:
	/* 0x214d: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2151:
	/* 0x2151: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2156:
	/* 0x2156: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_215b:
	/* 0x215b: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2160:
	/* 0x2160: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2165:
	/* 0x2165: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2168:
	/* 0x2168: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_216a:
	/* 0x216a: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_216f:
	/* 0x216f: mov    QWORD PTR [rsp+0x60],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2174:
	/* 0x2174: lea    rdx,[r15+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2178:
	/* 0x2178: mov    QWORD PTR [rsp+0x58],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_217d:
	/* 0x217d: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2182:
	/* 0x2182: cmp    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_2187:
	/* 0x2187: jne    2194 <generic_usdt_process_event+0x2194> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2194;
	}
x86_l_2189:
	/* 0x2189: cmp    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_218e:
	/* 0x218e: je     880 <generic_usdt_process_event+0x880> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2176ULL;
	}
x86_l_2194:
	/* 0x2194: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_219c:
	/* 0x219c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_21a1:
	/* 0x21a1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_21a6:
	/* 0x21a6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21ab:
	/* 0x21ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21ad:
	/* 0x21ad: cmp    r12,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 144ULL);
x86_l_21b5:
	/* 0x21b5: je     2a62 <generic_usdt_process_event+0x2a62> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10850ULL;
	}
x86_l_21bb:
	/* 0x21bb: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_21c0:
	/* 0x21c0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21c5:
	/* 0x21c5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_21ca:
	/* 0x21ca: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_21cf:
	/* 0x21cf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21d4:
	/* 0x21d4: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_21d7:
	/* 0x21d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21d9:
	/* 0x21d9: cmp    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21de:
	/* 0x21de: je     2a62 <generic_usdt_process_event+0x2a62> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10850ULL;
	}
x86_l_21e4:
	/* 0x21e4: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_21e9:
	/* 0x21e9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_21ee:
	/* 0x21ee: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_21f3:
	/* 0x21f3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21f8:
	/* 0x21f8: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_21fb:
	/* 0x21fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21fd:
	/* 0x21fd: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_2201:
	/* 0x2201: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2206:
	/* 0x2206: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_220b:
	/* 0x220b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2210:
	/* 0x2210: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2215:
	/* 0x2215: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2218:
	/* 0x2218: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_221a:
	/* 0x221a: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_221f:
	/* 0x221f: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2224:
	/* 0x2224: mov    r12d,DWORD PTR [rsp+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_2229:
	/* 0x2229: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_222c:
	/* 0x222c: mov    r13d,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2231:
	/* 0x2231: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2233:
	/* 0x2233: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_2236:
	/* 0x2236: sub    edx,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R13, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2239:
	/* 0x2239: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_223c:
	/* 0x223c: add    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 128ULL);
x86_l_2244:
	/* 0x2244: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2246:
	/* 0x2246: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_2249:
	/* 0x2249: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_224d:
	/* 0x224d: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_2250:
	/* 0x2250: cmovb  ecx,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_2254:
	/* 0x2254: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2256:
	/* 0x2256: mov    edi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_32);
x86_l_2259:
	/* 0x2259: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_225b:
	/* 0x225b: mov    DWORD PTR [rsp+0x70],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_225f:
	/* 0x225f: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2262:
	/* 0x2262: jb     885 <generic_usdt_process_event+0x885> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2181ULL;
	}
x86_l_2268:
	/* 0x2268: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_226e:
	/* 0x226e: ja     885 <generic_usdt_process_event+0x885> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2181ULL;
	}
x86_l_2274:
	/* 0x2274: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_2277:
	/* 0x2277: jbe    227e <generic_usdt_process_event+0x227e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_227e;
	}
x86_l_2279:
	/* 0x2279: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_227e:
	/* 0x227e: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2280:
	/* 0x2280: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_2283:
	/* 0x2283: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_2287:
	/* 0x2287: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_228a:
	/* 0x228a: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_228d:
	/* 0x228d: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2290:
	/* 0x2290: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2295:
	/* 0x2295: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2297:
	/* 0x2297: mov    QWORD PTR [rsp+0x68],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_229c:
	/* 0x229c: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_229f:
	/* 0x229f: jbe    885 <generic_usdt_process_event+0x885> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 2181ULL;
	}
x86_l_22a5:
	/* 0x22a5: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_22aa:
	/* 0x22aa: mov    QWORD PTR [rsp+0x50],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_22af:
	/* 0x22af: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_22b4:
	/* 0x22b4: mov    r15,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_22b9:
	/* 0x22b9: jmp    2ac1 <generic_usdt_process_event+0x2ac1> */
	return 10945ULL;
	return 8894ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_generic_usdt_process_event_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8894ULL: goto x86_l_22be;
	case 8898ULL: goto x86_l_22c2;
	case 8902ULL: goto x86_l_22c6;
	case 8907ULL: goto x86_l_22cb;
	case 8912ULL: goto x86_l_22d0;
	case 8917ULL: goto x86_l_22d5;
	case 8919ULL: goto x86_l_22d7;
	case 8923ULL: goto x86_l_22db;
	case 8927ULL: goto x86_l_22df;
	case 8932ULL: goto x86_l_22e4;
	case 8937ULL: goto x86_l_22e9;
	case 8942ULL: goto x86_l_22ee;
	case 8945ULL: goto x86_l_22f1;
	case 8947ULL: goto x86_l_22f3;
	case 8952ULL: goto x86_l_22f8;
	case 8959ULL: goto x86_l_22ff;
	case 8964ULL: goto x86_l_2304;
	case 8967ULL: goto x86_l_2307;
	case 8972ULL: goto x86_l_230c;
	case 8975ULL: goto x86_l_230f;
	case 8981ULL: goto x86_l_2315;
	case 8984ULL: goto x86_l_2318;
	case 8990ULL: goto x86_l_231e;
	case 8993ULL: goto x86_l_2321;
	case 8999ULL: goto x86_l_2327;
	case 9004ULL: goto x86_l_232c;
	case 9009ULL: goto x86_l_2331;
	case 9013ULL: goto x86_l_2335;
	case 9018ULL: goto x86_l_233a;
	case 9023ULL: goto x86_l_233f;
	case 9028ULL: goto x86_l_2344;
	case 9033ULL: goto x86_l_2349;
	case 9038ULL: goto x86_l_234e;
	case 9040ULL: goto x86_l_2350;
	case 9043ULL: goto x86_l_2353;
	case 9049ULL: goto x86_l_2359;
	case 9057ULL: goto x86_l_2361;
	case 9061ULL: goto x86_l_2365;
	case 9066ULL: goto x86_l_236a;
	case 9071ULL: goto x86_l_236f;
	case 9076ULL: goto x86_l_2374;
	case 9081ULL: goto x86_l_2379;
	case 9083ULL: goto x86_l_237b;
	case 9088ULL: goto x86_l_2380;
	case 9092ULL: goto x86_l_2384;
	case 9097ULL: goto x86_l_2389;
	case 9102ULL: goto x86_l_238e;
	case 9105ULL: goto x86_l_2391;
	case 9110ULL: goto x86_l_2396;
	case 9115ULL: goto x86_l_239b;
	case 9120ULL: goto x86_l_23a0;
	case 9125ULL: goto x86_l_23a5;
	case 9127ULL: goto x86_l_23a7;
	case 9131ULL: goto x86_l_23ab;
	case 9136ULL: goto x86_l_23b0;
	case 9141ULL: goto x86_l_23b5;
	case 9146ULL: goto x86_l_23ba;
	case 9151ULL: goto x86_l_23bf;
	case 9154ULL: goto x86_l_23c2;
	case 9156ULL: goto x86_l_23c4;
	case 9161ULL: goto x86_l_23c9;
	case 9164ULL: goto x86_l_23cc;
	case 9170ULL: goto x86_l_23d2;
	case 9172ULL: goto x86_l_23d4;
	case 9177ULL: goto x86_l_23d9;
	case 9180ULL: goto x86_l_23dc;
	case 9185ULL: goto x86_l_23e1;
	case 9187ULL: goto x86_l_23e3;
	case 9192ULL: goto x86_l_23e8;
	case 9194ULL: goto x86_l_23ea;
	case 9197ULL: goto x86_l_23ed;
	case 9202ULL: goto x86_l_23f2;
	case 9206ULL: goto x86_l_23f6;
	case 9212ULL: goto x86_l_23fc;
	case 9216ULL: goto x86_l_2400;
	case 9222ULL: goto x86_l_2406;
	case 9229ULL: goto x86_l_240d;
	case 9234ULL: goto x86_l_2412;
	case 9239ULL: goto x86_l_2417;
	case 9244ULL: goto x86_l_241c;
	case 9249ULL: goto x86_l_2421;
	case 9254ULL: goto x86_l_2426;
	case 9259ULL: goto x86_l_242b;
	case 9261ULL: goto x86_l_242d;
	case 9266ULL: goto x86_l_2432;
	case 9271ULL: goto x86_l_2437;
	case 9276ULL: goto x86_l_243c;
	case 9279ULL: goto x86_l_243f;
	case 9284ULL: goto x86_l_2444;
	case 9286ULL: goto x86_l_2446;
	case 9291ULL: goto x86_l_244b;
	case 9295ULL: goto x86_l_244f;
	case 9300ULL: goto x86_l_2454;
	case 9304ULL: goto x86_l_2458;
	case 9309ULL: goto x86_l_245d;
	case 9314ULL: goto x86_l_2462;
	case 9319ULL: goto x86_l_2467;
	case 9322ULL: goto x86_l_246a;
	case 9324ULL: goto x86_l_246c;
	case 9328ULL: goto x86_l_2470;
	case 9333ULL: goto x86_l_2475;
	case 9338ULL: goto x86_l_247a;
	case 9343ULL: goto x86_l_247f;
	case 9346ULL: goto x86_l_2482;
	case 9348ULL: goto x86_l_2484;
	case 9353ULL: goto x86_l_2489;
	case 9360ULL: goto x86_l_2490;
	case 9365ULL: goto x86_l_2495;
	case 9368ULL: goto x86_l_2498;
	case 9374ULL: goto x86_l_249e;
	case 9376ULL: goto x86_l_24a0;
	case 9379ULL: goto x86_l_24a3;
	case 9385ULL: goto x86_l_24a9;
	case 9387ULL: goto x86_l_24ab;
	case 9390ULL: goto x86_l_24ae;
	case 9396ULL: goto x86_l_24b4;
	case 9399ULL: goto x86_l_24b7;
	case 9403ULL: goto x86_l_24bb;
	case 9409ULL: goto x86_l_24c1;
	case 9412ULL: goto x86_l_24c4;
	case 9418ULL: goto x86_l_24ca;
	case 9423ULL: goto x86_l_24cf;
	case 9428ULL: goto x86_l_24d4;
	case 9433ULL: goto x86_l_24d9;
	case 9441ULL: goto x86_l_24e1;
	case 9446ULL: goto x86_l_24e6;
	case 9448ULL: goto x86_l_24e8;
	case 9453ULL: goto x86_l_24ed;
	case 9455ULL: goto x86_l_24ef;
	case 9461ULL: goto x86_l_24f5;
	case 9466ULL: goto x86_l_24fa;
	case 9471ULL: goto x86_l_24ff;
	case 9474ULL: goto x86_l_2502;
	case 9479ULL: goto x86_l_2507;
	case 9486ULL: goto x86_l_250e;
	case 9492ULL: goto x86_l_2514;
	case 9496ULL: goto x86_l_2518;
	case 9500ULL: goto x86_l_251c;
	case 9505ULL: goto x86_l_2521;
	case 9510ULL: goto x86_l_2526;
	case 9515ULL: goto x86_l_252b;
	case 9520ULL: goto x86_l_2530;
	case 9522ULL: goto x86_l_2532;
	case 9527ULL: goto x86_l_2537;
	case 9529ULL: goto x86_l_2539;
	case 9535ULL: goto x86_l_253f;
	case 9539ULL: goto x86_l_2543;
	case 9545ULL: goto x86_l_2549;
	case 9553ULL: goto x86_l_2551;
	case 9557ULL: goto x86_l_2555;
	case 9562ULL: goto x86_l_255a;
	case 9567ULL: goto x86_l_255f;
	case 9572ULL: goto x86_l_2564;
	case 9577ULL: goto x86_l_2569;
	case 9579ULL: goto x86_l_256b;
	case 9584ULL: goto x86_l_2570;
	case 9586ULL: goto x86_l_2572;
	case 9592ULL: goto x86_l_2578;
	case 9597ULL: goto x86_l_257d;
	case 9602ULL: goto x86_l_2582;
	case 9607ULL: goto x86_l_2587;
	case 9613ULL: goto x86_l_258d;
	case 9619ULL: goto x86_l_2593;
	case 9624ULL: goto x86_l_2598;
	case 9628ULL: goto x86_l_259c;
	case 9633ULL: goto x86_l_25a1;
	case 9638ULL: goto x86_l_25a6;
	case 9643ULL: goto x86_l_25ab;
	case 9648ULL: goto x86_l_25b0;
	case 9650ULL: goto x86_l_25b2;
	case 9655ULL: goto x86_l_25b7;
	case 9657ULL: goto x86_l_25b9;
	case 9663ULL: goto x86_l_25bf;
	case 9668ULL: goto x86_l_25c4;
	case 9673ULL: goto x86_l_25c9;
	case 9677ULL: goto x86_l_25cd;
	case 9683ULL: goto x86_l_25d3;
	case 9691ULL: goto x86_l_25db;
	case 9695ULL: goto x86_l_25df;
	case 9700ULL: goto x86_l_25e4;
	case 9705ULL: goto x86_l_25e9;
	case 9710ULL: goto x86_l_25ee;
	case 9715ULL: goto x86_l_25f3;
	case 9717ULL: goto x86_l_25f5;
	case 9722ULL: goto x86_l_25fa;
	case 9724ULL: goto x86_l_25fc;
	case 9730ULL: goto x86_l_2602;
	case 9735ULL: goto x86_l_2607;
	case 9740ULL: goto x86_l_260c;
	case 9748ULL: goto x86_l_2614;
	case 9754ULL: goto x86_l_261a;
	case 9760ULL: goto x86_l_2620;
	case 9765ULL: goto x86_l_2625;
	case 9768ULL: goto x86_l_2628;
	case 9771ULL: goto x86_l_262b;
	case 9777ULL: goto x86_l_2631;
	case 9780ULL: goto x86_l_2634;
	case 9785ULL: goto x86_l_2639;
	case 9790ULL: goto x86_l_263e;
	case 9798ULL: goto x86_l_2646;
	case 9803ULL: goto x86_l_264b;
	case 9805ULL: goto x86_l_264d;
	case 9810ULL: goto x86_l_2652;
	case 9812ULL: goto x86_l_2654;
	case 9818ULL: goto x86_l_265a;
	case 9826ULL: goto x86_l_2662;
	case 9831ULL: goto x86_l_2667;
	case 9835ULL: goto x86_l_266b;
	case 9841ULL: goto x86_l_2671;
	case 9849ULL: goto x86_l_2679;
	case 9853ULL: goto x86_l_267d;
	case 9858ULL: goto x86_l_2682;
	case 9863ULL: goto x86_l_2687;
	case 9868ULL: goto x86_l_268c;
	case 9873ULL: goto x86_l_2691;
	case 9875ULL: goto x86_l_2693;
	case 9880ULL: goto x86_l_2698;
	case 9882ULL: goto x86_l_269a;
	case 9888ULL: goto x86_l_26a0;
	case 9893ULL: goto x86_l_26a5;
	case 9898ULL: goto x86_l_26aa;
	case 9903ULL: goto x86_l_26af;
	case 9909ULL: goto x86_l_26b5;
	case 9915ULL: goto x86_l_26bb;
	case 9923ULL: goto x86_l_26c3;
	case 9926ULL: goto x86_l_26c6;
	case 9934ULL: goto x86_l_26ce;
	case 9940ULL: goto x86_l_26d4;
	case 9943ULL: goto x86_l_26d7;
	case 9948ULL: goto x86_l_26dc;
	case 9953ULL: goto x86_l_26e1;
	case 9958ULL: goto x86_l_26e6;
	case 9963ULL: goto x86_l_26eb;
	case 9965ULL: goto x86_l_26ed;
	case 9970ULL: goto x86_l_26f2;
	case 9972ULL: goto x86_l_26f4;
	case 9978ULL: goto x86_l_26fa;
	case 9983ULL: goto x86_l_26ff;
	case 9988ULL: goto x86_l_2704;
	case 9992ULL: goto x86_l_2708;
	case 9998ULL: goto x86_l_270e;
	case 10006ULL: goto x86_l_2716;
	case 10010ULL: goto x86_l_271a;
	case 10015ULL: goto x86_l_271f;
	case 10020ULL: goto x86_l_2724;
	case 10025ULL: goto x86_l_2729;
	case 10030ULL: goto x86_l_272e;
	case 10032ULL: goto x86_l_2730;
	case 10037ULL: goto x86_l_2735;
	case 10039ULL: goto x86_l_2737;
	case 10045ULL: goto x86_l_273d;
	case 10050ULL: goto x86_l_2742;
	case 10055ULL: goto x86_l_2747;
	case 10063ULL: goto x86_l_274f;
	case 10069ULL: goto x86_l_2755;
	case 10075ULL: goto x86_l_275b;
	case 10080ULL: goto x86_l_2760;
	case 10088ULL: goto x86_l_2768;
	case 10091ULL: goto x86_l_276b;
	case 10097ULL: goto x86_l_2771;
	case 10100ULL: goto x86_l_2774;
	case 10105ULL: goto x86_l_2779;
	case 10110ULL: goto x86_l_277e;
	case 10118ULL: goto x86_l_2786;
	case 10123ULL: goto x86_l_278b;
	case 10125ULL: goto x86_l_278d;
	case 10130ULL: goto x86_l_2792;
	case 10132ULL: goto x86_l_2794;
	case 10138ULL: goto x86_l_279a;
	case 10146ULL: goto x86_l_27a2;
	case 10151ULL: goto x86_l_27a7;
	case 10155ULL: goto x86_l_27ab;
	case 10161ULL: goto x86_l_27b1;
	case 10169ULL: goto x86_l_27b9;
	case 10173ULL: goto x86_l_27bd;
	case 10178ULL: goto x86_l_27c2;
	case 10183ULL: goto x86_l_27c7;
	case 10188ULL: goto x86_l_27cc;
	case 10193ULL: goto x86_l_27d1;
	case 10195ULL: goto x86_l_27d3;
	case 10200ULL: goto x86_l_27d8;
	case 10202ULL: goto x86_l_27da;
	case 10208ULL: goto x86_l_27e0;
	case 10213ULL: goto x86_l_27e5;
	case 10218ULL: goto x86_l_27ea;
	case 10223ULL: goto x86_l_27ef;
	case 10229ULL: goto x86_l_27f5;
	case 10235ULL: goto x86_l_27fb;
	case 10243ULL: goto x86_l_2803;
	case 10246ULL: goto x86_l_2806;
	case 10249ULL: goto x86_l_2809;
	case 10255ULL: goto x86_l_280f;
	case 10258ULL: goto x86_l_2812;
	case 10263ULL: goto x86_l_2817;
	case 10268ULL: goto x86_l_281c;
	case 10273ULL: goto x86_l_2821;
	case 10278ULL: goto x86_l_2826;
	case 10280ULL: goto x86_l_2828;
	case 10285ULL: goto x86_l_282d;
	case 10287ULL: goto x86_l_282f;
	case 10293ULL: goto x86_l_2835;
	case 10298ULL: goto x86_l_283a;
	case 10303ULL: goto x86_l_283f;
	case 10307ULL: goto x86_l_2843;
	case 10313ULL: goto x86_l_2849;
	case 10321ULL: goto x86_l_2851;
	case 10325ULL: goto x86_l_2855;
	case 10330ULL: goto x86_l_285a;
	case 10335ULL: goto x86_l_285f;
	case 10340ULL: goto x86_l_2864;
	case 10345ULL: goto x86_l_2869;
	case 10347ULL: goto x86_l_286b;
	case 10352ULL: goto x86_l_2870;
	case 10354ULL: goto x86_l_2872;
	case 10356ULL: goto x86_l_2874;
	case 10361ULL: goto x86_l_2879;
	case 10366ULL: goto x86_l_287e;
	case 10373ULL: goto x86_l_2885;
	case 10375ULL: goto x86_l_2887;
	case 10380ULL: goto x86_l_288c;
	case 10383ULL: goto x86_l_288f;
	case 10389ULL: goto x86_l_2895;
	case 10392ULL: goto x86_l_2898;
	case 10397ULL: goto x86_l_289d;
	case 10402ULL: goto x86_l_28a2;
	case 10407ULL: goto x86_l_28a7;
	case 10410ULL: goto x86_l_28aa;
	case 10412ULL: goto x86_l_28ac;
	case 10417ULL: goto x86_l_28b1;
	case 10419ULL: goto x86_l_28b3;
	case 10421ULL: goto x86_l_28b5;
	case 10426ULL: goto x86_l_28ba;
	case 10431ULL: goto x86_l_28bf;
	case 10439ULL: goto x86_l_28c7;
	case 10443ULL: goto x86_l_28cb;
	case 10448ULL: goto x86_l_28d0;
	case 10451ULL: goto x86_l_28d3;
	case 10456ULL: goto x86_l_28d8;
	case 10461ULL: goto x86_l_28dd;
	case 10465ULL: goto x86_l_28e1;
	case 10471ULL: goto x86_l_28e7;
	case 10476ULL: goto x86_l_28ec;
	case 10478ULL: goto x86_l_28ee;
	case 10482ULL: goto x86_l_28f2;
	case 10484ULL: goto x86_l_28f4;
	case 10488ULL: goto x86_l_28f8;
	case 10493ULL: goto x86_l_28fd;
	case 10498ULL: goto x86_l_2902;
	case 10503ULL: goto x86_l_2907;
	case 10511ULL: goto x86_l_290f;
	case 10516ULL: goto x86_l_2914;
	case 10521ULL: goto x86_l_2919;
	case 10526ULL: goto x86_l_291e;
	case 10534ULL: goto x86_l_2926;
	case 10541ULL: goto x86_l_292d;
	case 10543ULL: goto x86_l_292f;
	case 10548ULL: goto x86_l_2934;
	case 10553ULL: goto x86_l_2939;
	case 10558ULL: goto x86_l_293e;
	case 10560ULL: goto x86_l_2940;
	case 10562ULL: goto x86_l_2942;
	case 10565ULL: goto x86_l_2945;
	case 10571ULL: goto x86_l_294b;
	case 10573ULL: goto x86_l_294d;
	case 10578ULL: goto x86_l_2952;
	case 10585ULL: goto x86_l_2959;
	case 10595ULL: goto x86_l_2963;
	case 10600ULL: goto x86_l_2968;
	case 10607ULL: goto x86_l_296f;
	case 10612ULL: goto x86_l_2974;
	case 10617ULL: goto x86_l_2979;
	case 10619ULL: goto x86_l_297b;
	case 10622ULL: goto x86_l_297e;
	case 10628ULL: goto x86_l_2984;
	case 10630ULL: goto x86_l_2986;
	case 10635ULL: goto x86_l_298b;
	case 10637ULL: goto x86_l_298d;
	case 10642ULL: goto x86_l_2992;
	case 10650ULL: goto x86_l_299a;
	case 10655ULL: goto x86_l_299f;
	case 10659ULL: goto x86_l_29a3;
	case 10664ULL: goto x86_l_29a8;
	case 10668ULL: goto x86_l_29ac;
	case 10673ULL: goto x86_l_29b1;
	default: return 0xffffffffffffffffULL;
	}
x86_l_22be:
	/* 0x22be: lea    rdi,[r13+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22c2:
	/* 0x22c2: lea    rdx,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22c6:
	/* 0x22c6: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_22cb:
	/* 0x22cb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22d0:
	/* 0x22d0: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_22d5:
	/* 0x22d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22d7:
	/* 0x22d7: lea    rdi,[r13+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_22db:
	/* 0x22db: add    r15,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_22df:
	/* 0x22df: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_22e4:
	/* 0x22e4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22e9:
	/* 0x22e9: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_22ee:
	/* 0x22ee: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_22f1:
	/* 0x22f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22f3:
	/* 0x22f3: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_22f8:
	/* 0x22f8: movbe  WORD PTR [r13+0x2],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_22ff:
	/* 0x22ff: mov    esi,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 24ULL);
x86_l_2304:
	/* 0x2304: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_2307:
	/* 0x2307: jmp    38df <generic_usdt_process_event+0x38df> */
	return 14559ULL;
x86_l_230c:
	/* 0x230c: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_230f:
	/* 0x230f: je     24ab <generic_usdt_process_event+0x24ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24ab;
	}
x86_l_2315:
	/* 0x2315: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2318:
	/* 0x2318: jne    28d0 <generic_usdt_process_event+0x28d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_28d0;
	}
x86_l_231e:
	/* 0x231e: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_2321:
	/* 0x2321: add    rax,0x5e58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24152ULL);
x86_l_2327:
	/* 0x2327: jmp    24b4 <generic_usdt_process_event+0x24b4> */
	goto x86_l_24b4;
x86_l_232c:
	/* 0x232c: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2331:
	/* 0x2331: lea    rdi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2335:
	/* 0x2335: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_233a:
	/* 0x233a: mov    edx,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 63ULL);
x86_l_233f:
	/* 0x233f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2344:
	/* 0x2344: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2349:
	/* 0x2349: mov    esi,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 63ULL);
x86_l_234e:
	/* 0x234e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2350:
	/* 0x2350: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2353:
	/* 0x2353: js     1f32 <generic_usdt_process_event+0x1f32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7986ULL;
	}
x86_l_2359:
	/* 0x2359: mov    r15,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2361:
	/* 0x2361: lea    rdx,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2365:
	/* 0x2365: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_236a:
	/* 0x236a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_236f:
	/* 0x236f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2374:
	/* 0x2374: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2379:
	/* 0x2379: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_237b:
	/* 0x237b: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2380:
	/* 0x2380: lea    rdi,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2384:
	/* 0x2384: mov    edx,0x348 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 840ULL);
x86_l_2389:
	/* 0x2389: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_238e:
	/* 0x238e: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2391:
	/* 0x2391: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2396:
	/* 0x2396: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_239b:
	/* 0x239b: add    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 120ULL);
x86_l_23a0:
	/* 0x23a0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23a5:
	/* 0x23a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23a7:
	/* 0x23a7: add    r15,0x58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 88ULL);
x86_l_23ab:
	/* 0x23ab: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_23b0:
	/* 0x23b0: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_23b5:
	/* 0x23b5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23ba:
	/* 0x23ba: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_23bf:
	/* 0x23bf: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_23c2:
	/* 0x23c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23c4:
	/* 0x23c4: mov    esi,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 80ULL);
x86_l_23c9:
	/* 0x23c9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_23cc:
	/* 0x23cc: jne    38da <generic_usdt_process_event+0x38da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14554ULL;
	}
x86_l_23d2:
	/* 0x23d2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_23d4:
	/* 0x23d4: cmp    DWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_23d9:
	/* 0x23d9: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_23dc:
	/* 0x23dc: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23e1:
	/* 0x23e1: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23e3:
	/* 0x23e3: jmp    38da <generic_usdt_process_event+0x38da> */
	return 14554ULL;
x86_l_23e8:
	/* 0x23e8: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_23ea:
	/* 0x23ea: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_23ed:
	/* 0x23ed: jmp    38df <generic_usdt_process_event+0x38df> */
	return 14559ULL;
x86_l_23f2:
	/* 0x23f2: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_23f6:
	/* 0x23f6: je     2c0f <generic_usdt_process_event+0x2c0f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11279ULL;
	}
x86_l_23fc:
	/* 0x23fc: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_2400:
	/* 0x2400: jne    2c19 <generic_usdt_process_event+0x2c19> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11289ULL;
	}
x86_l_2406:
	/* 0x2406: add    r15,0x5e58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24152ULL);
x86_l_240d:
	/* 0x240d: jmp    2c16 <generic_usdt_process_event+0x2c16> */
	return 11286ULL;
x86_l_2412:
	/* 0x2412: lea    rdx,[r12+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2417:
	/* 0x2417: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_241c:
	/* 0x241c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2421:
	/* 0x2421: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2426:
	/* 0x2426: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_242b:
	/* 0x242b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_242d:
	/* 0x242d: lea    rdx,[r12+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2432:
	/* 0x2432: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2437:
	/* 0x2437: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_243c:
	/* 0x243c: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_243f:
	/* 0x243f: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2444:
	/* 0x2444: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2446:
	/* 0x2446: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_244b:
	/* 0x244b: lea    rdi,[r13+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_244f:
	/* 0x244f: lea    r15,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2454:
	/* 0x2454: add    r12,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_2458:
	/* 0x2458: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_245d:
	/* 0x245d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2462:
	/* 0x2462: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2467:
	/* 0x2467: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_246a:
	/* 0x246a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_246c:
	/* 0x246c: lea    rdi,[r13+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_2470:
	/* 0x2470: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2475:
	/* 0x2475: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_247a:
	/* 0x247a: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_247f:
	/* 0x247f: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2482:
	/* 0x2482: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2484:
	/* 0x2484: movzx  eax,WORD PTR [r13+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_2489:
	/* 0x2489: movbe  WORD PTR [r13+0x22],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_2490:
	/* 0x2490: jmp    38d5 <generic_usdt_process_event+0x38d5> */
	return 14549ULL;
x86_l_2495:
	/* 0x2495: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_2498:
	/* 0x2498: add    rax,0x5e60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24160ULL);
x86_l_249e:
	/* 0x249e: jmp    24b4 <generic_usdt_process_event+0x24b4> */
	goto x86_l_24b4;
x86_l_24a0:
	/* 0x24a0: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_24a3:
	/* 0x24a3: add    rax,0x5e68 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24168ULL);
x86_l_24a9:
	/* 0x24a9: jmp    24b4 <generic_usdt_process_event+0x24b4> */
	goto x86_l_24b4;
x86_l_24ab:
	/* 0x24ab: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_24ae:
	/* 0x24ae: add    rax,0x5e50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24144ULL);
x86_l_24b4:
	/* 0x24b4: mov    r13,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24b7:
	/* 0x24b7: test   dil,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDI, X86_WIDTH_8, 16ULL);
x86_l_24bb:
	/* 0x24bb: jne    28e7 <generic_usdt_process_event+0x28e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_28e7;
	}
x86_l_24c1:
	/* 0x24c1: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_24c4:
	/* 0x24c4: je     298b <generic_usdt_process_event+0x298b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_298b;
	}
x86_l_24ca:
	/* 0x24ca: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_24cf:
	/* 0x24cf: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_24d4:
	/* 0x24d4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_24d9:
	/* 0x24d9: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_24e1:
	/* 0x24e1: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_24e6:
	/* 0x24e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24e8:
	/* 0x24e8: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_24ed:
	/* 0x24ed: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24ef:
	/* 0x24ef: js     28bf <generic_usdt_process_event+0x28bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_28bf;
	}
x86_l_24f5:
	/* 0x24f5: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_24fa:
	/* 0x24fa: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_24ff:
	/* 0x24ff: mov    rax,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_2502:
	/* 0x2502: mov    QWORD PTR [rsp+0x30],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2507:
	/* 0x2507: cmp    rdx,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4094ULL);
x86_l_250e:
	/* 0x250e: ja     28bf <generic_usdt_process_event+0x28bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_28bf;
	}
x86_l_2514:
	/* 0x2514: lea    r12,[rbp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2518:
	/* 0x2518: lea    rdi,[r15+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_251c:
	/* 0x251c: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2521:
	/* 0x2521: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2526:
	/* 0x2526: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_252b:
	/* 0x252b: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2530:
	/* 0x2530: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2532:
	/* 0x2532: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2537:
	/* 0x2537: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2539:
	/* 0x2539: js     28bf <generic_usdt_process_event+0x28bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_28bf;
	}
x86_l_253f:
	/* 0x253f: cmp    r13,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 1ULL);
x86_l_2543:
	/* 0x2543: je     2992 <generic_usdt_process_event+0x2992> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2992;
	}
x86_l_2549:
	/* 0x2549: mov    rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2551:
	/* 0x2551: lea    rdx,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2555:
	/* 0x2555: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_255a:
	/* 0x255a: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_255f:
	/* 0x255f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2564:
	/* 0x2564: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2569:
	/* 0x2569: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_256b:
	/* 0x256b: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2570:
	/* 0x2570: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2572:
	/* 0x2572: js     28bf <generic_usdt_process_event+0x28bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_28bf;
	}
x86_l_2578:
	/* 0x2578: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_257d:
	/* 0x257d: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_2582:
	/* 0x2582: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2587:
	/* 0x2587: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_258d:
	/* 0x258d: ja     28bf <generic_usdt_process_event+0x28bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_28bf;
	}
x86_l_2593:
	/* 0x2593: add    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_2598:
	/* 0x2598: lea    rdi,[r15+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_259c:
	/* 0x259c: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_25a1:
	/* 0x25a1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_25a6:
	/* 0x25a6: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25ab:
	/* 0x25ab: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_25b0:
	/* 0x25b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25b2:
	/* 0x25b2: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_25b7:
	/* 0x25b7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_25b9:
	/* 0x25b9: js     28bf <generic_usdt_process_event+0x28bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_28bf;
	}
x86_l_25bf:
	/* 0x25bf: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25c4:
	/* 0x25c4: add    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_25c9:
	/* 0x25c9: cmp    r13,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 3ULL);
x86_l_25cd:
	/* 0x25cd: jb     2992 <generic_usdt_process_event+0x2992> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2992;
	}
x86_l_25d3:
	/* 0x25d3: mov    rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_25db:
	/* 0x25db: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_25df:
	/* 0x25df: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_25e4:
	/* 0x25e4: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_25e9:
	/* 0x25e9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_25ee:
	/* 0x25ee: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_25f3:
	/* 0x25f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25f5:
	/* 0x25f5: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_25fa:
	/* 0x25fa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_25fc:
	/* 0x25fc: js     28bf <generic_usdt_process_event+0x28bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_28bf;
	}
x86_l_2602:
	/* 0x2602: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2607:
	/* 0x2607: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_260c:
	/* 0x260c: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2614:
	/* 0x2614: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_261a:
	/* 0x261a: ja     28bf <generic_usdt_process_event+0x28bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_28bf;
	}
x86_l_2620:
	/* 0x2620: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2625:
	/* 0x2625: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2628:
	/* 0x2628: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_262b:
	/* 0x262b: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2631:
	/* 0x2631: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2634:
	/* 0x2634: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2639:
	/* 0x2639: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_263e:
	/* 0x263e: mov    rsi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2646:
	/* 0x2646: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_264b:
	/* 0x264b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_264d:
	/* 0x264d: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2652:
	/* 0x2652: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2654:
	/* 0x2654: js     28bf <generic_usdt_process_event+0x28bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_28bf;
	}
x86_l_265a:
	/* 0x265a: mov    rax,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2662:
	/* 0x2662: add    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_2667:
	/* 0x2667: cmp    r13,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 3ULL);
x86_l_266b:
	/* 0x266b: je     2992 <generic_usdt_process_event+0x2992> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2992;
	}
x86_l_2671:
	/* 0x2671: mov    rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2679:
	/* 0x2679: lea    rdx,[rax+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_267d:
	/* 0x267d: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2682:
	/* 0x2682: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2687:
	/* 0x2687: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_268c:
	/* 0x268c: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2691:
	/* 0x2691: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2693:
	/* 0x2693: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2698:
	/* 0x2698: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_269a:
	/* 0x269a: js     28bf <generic_usdt_process_event+0x28bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_28bf;
	}
x86_l_26a0:
	/* 0x26a0: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_26a5:
	/* 0x26a5: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_26aa:
	/* 0x26aa: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26af:
	/* 0x26af: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_26b5:
	/* 0x26b5: ja     28bf <generic_usdt_process_event+0x28bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_28bf;
	}
x86_l_26bb:
	/* 0x26bb: mov    rdi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_26c3:
	/* 0x26c3: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_26c6:
	/* 0x26c6: mov    QWORD PTR [rsp+0xa8],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_26ce:
	/* 0x26ce: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_26d4:
	/* 0x26d4: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_26d7:
	/* 0x26d7: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_26dc:
	/* 0x26dc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_26e1:
	/* 0x26e1: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26e6:
	/* 0x26e6: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_26eb:
	/* 0x26eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26ed:
	/* 0x26ed: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_26f2:
	/* 0x26f2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_26f4:
	/* 0x26f4: js     28bf <generic_usdt_process_event+0x28bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_28bf;
	}
x86_l_26fa:
	/* 0x26fa: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26ff:
	/* 0x26ff: add    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_2704:
	/* 0x2704: cmp    r13,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 5ULL);
x86_l_2708:
	/* 0x2708: jb     2992 <generic_usdt_process_event+0x2992> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2992;
	}
x86_l_270e:
	/* 0x270e: mov    rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2716:
	/* 0x2716: lea    rdx,[rax+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_271a:
	/* 0x271a: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_271f:
	/* 0x271f: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2724:
	/* 0x2724: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2729:
	/* 0x2729: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_272e:
	/* 0x272e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2730:
	/* 0x2730: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2735:
	/* 0x2735: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2737:
	/* 0x2737: js     28bf <generic_usdt_process_event+0x28bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_28bf;
	}
x86_l_273d:
	/* 0x273d: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2742:
	/* 0x2742: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_2747:
	/* 0x2747: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_274f:
	/* 0x274f: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_2755:
	/* 0x2755: ja     28bf <generic_usdt_process_event+0x28bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_28bf;
	}
x86_l_275b:
	/* 0x275b: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2760:
	/* 0x2760: add    rdi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 168ULL);
x86_l_2768:
	/* 0x2768: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_276b:
	/* 0x276b: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2771:
	/* 0x2771: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2774:
	/* 0x2774: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2779:
	/* 0x2779: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_277e:
	/* 0x277e: mov    rsi,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2786:
	/* 0x2786: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_278b:
	/* 0x278b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_278d:
	/* 0x278d: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2792:
	/* 0x2792: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2794:
	/* 0x2794: js     28bf <generic_usdt_process_event+0x28bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_28bf;
	}
x86_l_279a:
	/* 0x279a: mov    rax,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_27a2:
	/* 0x27a2: add    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_27a7:
	/* 0x27a7: cmp    r13,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 5ULL);
x86_l_27ab:
	/* 0x27ab: je     2992 <generic_usdt_process_event+0x2992> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2992;
	}
x86_l_27b1:
	/* 0x27b1: mov    rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_27b9:
	/* 0x27b9: lea    rdx,[rax+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_27bd:
	/* 0x27bd: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_27c2:
	/* 0x27c2: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_27c7:
	/* 0x27c7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_27cc:
	/* 0x27cc: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_27d1:
	/* 0x27d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27d3:
	/* 0x27d3: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_27d8:
	/* 0x27d8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_27da:
	/* 0x27da: js     28bf <generic_usdt_process_event+0x28bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_28bf;
	}
x86_l_27e0:
	/* 0x27e0: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_27e5:
	/* 0x27e5: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_27ea:
	/* 0x27ea: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27ef:
	/* 0x27ef: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_27f5:
	/* 0x27f5: ja     28bf <generic_usdt_process_event+0x28bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_28bf;
	}
x86_l_27fb:
	/* 0x27fb: mov    rdi,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2803:
	/* 0x2803: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2806:
	/* 0x2806: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_2809:
	/* 0x2809: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_280f:
	/* 0x280f: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2812:
	/* 0x2812: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2817:
	/* 0x2817: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_281c:
	/* 0x281c: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2821:
	/* 0x2821: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2826:
	/* 0x2826: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2828:
	/* 0x2828: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_282d:
	/* 0x282d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_282f:
	/* 0x282f: js     28bf <generic_usdt_process_event+0x28bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_28bf;
	}
x86_l_2835:
	/* 0x2835: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_283a:
	/* 0x283a: add    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_283f:
	/* 0x283f: cmp    r13,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 7ULL);
x86_l_2843:
	/* 0x2843: jb     2992 <generic_usdt_process_event+0x2992> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2992;
	}
x86_l_2849:
	/* 0x2849: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2851:
	/* 0x2851: add    rdx,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_2855:
	/* 0x2855: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_285a:
	/* 0x285a: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_285f:
	/* 0x285f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2864:
	/* 0x2864: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2869:
	/* 0x2869: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_286b:
	/* 0x286b: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2870:
	/* 0x2870: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2872:
	/* 0x2872: js     28bf <generic_usdt_process_event+0x28bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_28bf;
	}
x86_l_2874:
	/* 0x2874: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2879:
	/* 0x2879: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_287e:
	/* 0x287e: cmp    r13,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4094ULL);
x86_l_2885:
	/* 0x2885: ja     28bf <generic_usdt_process_event+0x28bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_28bf;
	}
x86_l_2887:
	/* 0x2887: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_288c:
	/* 0x288c: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_288f:
	/* 0x288f: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2895:
	/* 0x2895: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2898:
	/* 0x2898: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_289d:
	/* 0x289d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_28a2:
	/* 0x28a2: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_28a7:
	/* 0x28a7: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_28aa:
	/* 0x28aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28ac:
	/* 0x28ac: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_28b1:
	/* 0x28b1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_28b3:
	/* 0x28b3: js     28bf <generic_usdt_process_event+0x28bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_28bf;
	}
x86_l_28b5:
	/* 0x28b5: add    QWORD PTR [rsp+0x30],r13 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_28ba:
	/* 0x28ba: jmp    2992 <generic_usdt_process_event+0x2992> */
	goto x86_l_2992;
x86_l_28bf:
	/* 0x28bf: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_28c7:
	/* 0x28c7: mov    DWORD PTR [r15+rax*1],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_28cb:
	/* 0x28cb: jmp    2c97 <generic_usdt_process_event+0x2c97> */
	return 11415ULL;
x86_l_28d0:
	/* 0x28d0: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_28d3:
	/* 0x28d3: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_28d8:
	/* 0x28d8: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_28dd:
	/* 0x28dd: test   dil,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDI, X86_WIDTH_8, 16ULL);
x86_l_28e1:
	/* 0x28e1: je     2992 <generic_usdt_process_event+0x2992> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2992;
	}
x86_l_28e7:
	/* 0x28e7: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_28ec:
	/* 0x28ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28ee:
	/* 0x28ee: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_28f2:
	/* 0x28f2: jne    28f8 <generic_usdt_process_event+0x28f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_28f8;
	}
x86_l_28f4:
	/* 0x28f4: mov    rax,QWORD PTR [rbx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_28f8:
	/* 0x28f8: mov    rcx,QWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28fd:
	/* 0x28fd: mov    rdx,QWORD PTR [r12+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2902:
	/* 0x2902: mov    QWORD PTR [rsp+0x38],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2907:
	/* 0x2907: mov    rcx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_290f:
	/* 0x290f: mov    QWORD PTR [rsp+0x40],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2914:
	/* 0x2914: mov    QWORD PTR [rsp+0x48],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2919:
	/* 0x2919: mov    QWORD PTR [rsp+0x78],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_291e:
	/* 0x291e: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2926:
	/* 0x2926: mov    rdi,QWORD PTR [rip+0x9e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_292d:
	/* 0x292d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_292f:
	/* 0x292f: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2934:
	/* 0x2934: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2939:
	/* 0x2939: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_293e:
	/* 0x293e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2940:
	/* 0x2940: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2942:
	/* 0x2942: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2945:
	/* 0x2945: je     2a3c <generic_usdt_process_event+0x2a3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10812ULL;
	}
x86_l_294b:
	/* 0x294b: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_294d:
	/* 0x294d: mov    WORD PTR [rsp+0x10],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2952:
	/* 0x2952: mov    WORD PTR [rsp+0x12],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 77309411333ULL);
x86_l_2959:
	/* 0x2959: movabs rax,0x200000057 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934679ULL);
x86_l_2963:
	/* 0x2963: mov    QWORD PTR [rsp+0x14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2968:
	/* 0x2968: mov    rdi,QWORD PTR [rip+0x9db] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_296f:
	/* 0x296f: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2974:
	/* 0x2974: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2979:
	/* 0x2979: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_297b:
	/* 0x297b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_297e:
	/* 0x297e: je     2a18 <generic_usdt_process_event+0x2a18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10776ULL;
	}
x86_l_2984:
	/* 0x2984: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2986:
	/* 0x2986: jmp    2a3c <generic_usdt_process_event+0x2a3c> */
	return 10812ULL;
x86_l_298b:
	/* 0x298b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_298d:
	/* 0x298d: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2992:
	/* 0x2992: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_299a:
	/* 0x299a: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_299f:
	/* 0x299f: mov    DWORD PTR [r15+rax*1],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_29a3:
	/* 0x29a3: mov    DWORD PTR [r15+rax*1+0x4],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 4ULL);
x86_l_29a8:
	/* 0x29a8: add    rsi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_29ac:
	/* 0x29ac: jmp    38da <generic_usdt_process_event+0x38da> */
	return 14554ULL;
x86_l_29b1:
	/* 0x29b1: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
	return 10676ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_generic_usdt_process_event_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10676ULL: goto x86_l_29b4;
	case 10682ULL: goto x86_l_29ba;
	case 10685ULL: goto x86_l_29bd;
	case 10691ULL: goto x86_l_29c3;
	case 10696ULL: goto x86_l_29c8;
	case 10702ULL: goto x86_l_29ce;
	case 10709ULL: goto x86_l_29d5;
	case 10713ULL: goto x86_l_29d9;
	case 10718ULL: goto x86_l_29de;
	case 10729ULL: goto x86_l_29e9;
	case 10736ULL: goto x86_l_29f0;
	case 10738ULL: goto x86_l_29f2;
	case 10743ULL: goto x86_l_29f7;
	case 10751ULL: goto x86_l_29ff;
	case 10756ULL: goto x86_l_2a04;
	case 10758ULL: goto x86_l_2a06;
	case 10760ULL: goto x86_l_2a08;
	case 10765ULL: goto x86_l_2a0d;
	case 10771ULL: goto x86_l_2a13;
	case 10776ULL: goto x86_l_2a18;
	case 10784ULL: goto x86_l_2a20;
	case 10791ULL: goto x86_l_2a27;
	case 10793ULL: goto x86_l_2a29;
	case 10798ULL: goto x86_l_2a2e;
	case 10803ULL: goto x86_l_2a33;
	case 10808ULL: goto x86_l_2a38;
	case 10810ULL: goto x86_l_2a3a;
	case 10812ULL: goto x86_l_2a3c;
	case 10820ULL: goto x86_l_2a44;
	case 10828ULL: goto x86_l_2a4c;
	case 10833ULL: goto x86_l_2a51;
	case 10838ULL: goto x86_l_2a56;
	case 10845ULL: goto x86_l_2a5d;
	case 10850ULL: goto x86_l_2a62;
	case 10854ULL: goto x86_l_2a66;
	case 10859ULL: goto x86_l_2a6b;
	case 10864ULL: goto x86_l_2a70;
	case 10869ULL: goto x86_l_2a75;
	case 10874ULL: goto x86_l_2a7a;
	case 10876ULL: goto x86_l_2a7c;
	case 10881ULL: goto x86_l_2a81;
	case 10886ULL: goto x86_l_2a86;
	case 10892ULL: goto x86_l_2a8c;
	case 10896ULL: goto x86_l_2a90;
	case 10901ULL: goto x86_l_2a95;
	case 10906ULL: goto x86_l_2a9a;
	case 10911ULL: goto x86_l_2a9f;
	case 10916ULL: goto x86_l_2aa4;
	case 10919ULL: goto x86_l_2aa7;
	case 10921ULL: goto x86_l_2aa9;
	case 10926ULL: goto x86_l_2aae;
	case 10931ULL: goto x86_l_2ab3;
	case 10935ULL: goto x86_l_2ab7;
	case 10940ULL: goto x86_l_2abc;
	case 10945ULL: goto x86_l_2ac1;
	case 10950ULL: goto x86_l_2ac6;
	case 10952ULL: goto x86_l_2ac8;
	case 10957ULL: goto x86_l_2acd;
	case 10963ULL: goto x86_l_2ad3;
	case 10971ULL: goto x86_l_2adb;
	case 10976ULL: goto x86_l_2ae0;
	case 10981ULL: goto x86_l_2ae5;
	case 10986ULL: goto x86_l_2aea;
	case 10988ULL: goto x86_l_2aec;
	case 10996ULL: goto x86_l_2af4;
	case 11002ULL: goto x86_l_2afa;
	case 11007ULL: goto x86_l_2aff;
	case 11012ULL: goto x86_l_2b04;
	case 11017ULL: goto x86_l_2b09;
	case 11022ULL: goto x86_l_2b0e;
	case 11027ULL: goto x86_l_2b13;
	case 11030ULL: goto x86_l_2b16;
	case 11032ULL: goto x86_l_2b18;
	case 11037ULL: goto x86_l_2b1d;
	case 11043ULL: goto x86_l_2b23;
	case 11048ULL: goto x86_l_2b28;
	case 11053ULL: goto x86_l_2b2d;
	case 11058ULL: goto x86_l_2b32;
	case 11063ULL: goto x86_l_2b37;
	case 11066ULL: goto x86_l_2b3a;
	case 11068ULL: goto x86_l_2b3c;
	case 11072ULL: goto x86_l_2b40;
	case 11077ULL: goto x86_l_2b45;
	case 11082ULL: goto x86_l_2b4a;
	case 11087ULL: goto x86_l_2b4f;
	case 11092ULL: goto x86_l_2b54;
	case 11095ULL: goto x86_l_2b57;
	case 11097ULL: goto x86_l_2b59;
	case 11102ULL: goto x86_l_2b5e;
	case 11107ULL: goto x86_l_2b63;
	case 11112ULL: goto x86_l_2b68;
	case 11115ULL: goto x86_l_2b6b;
	case 11120ULL: goto x86_l_2b70;
	case 11122ULL: goto x86_l_2b72;
	case 11125ULL: goto x86_l_2b75;
	case 11128ULL: goto x86_l_2b78;
	case 11131ULL: goto x86_l_2b7b;
	case 11139ULL: goto x86_l_2b83;
	case 11141ULL: goto x86_l_2b85;
	case 11144ULL: goto x86_l_2b88;
	case 11148ULL: goto x86_l_2b8c;
	case 11151ULL: goto x86_l_2b8f;
	case 11155ULL: goto x86_l_2b93;
	case 11157ULL: goto x86_l_2b95;
	case 11160ULL: goto x86_l_2b98;
	case 11162ULL: goto x86_l_2b9a;
	case 11166ULL: goto x86_l_2b9e;
	case 11169ULL: goto x86_l_2ba1;
	case 11175ULL: goto x86_l_2ba7;
	case 11181ULL: goto x86_l_2bad;
	case 11187ULL: goto x86_l_2bb3;
	case 11190ULL: goto x86_l_2bb6;
	case 11192ULL: goto x86_l_2bb8;
	case 11197ULL: goto x86_l_2bbd;
	case 11199ULL: goto x86_l_2bbf;
	case 11202ULL: goto x86_l_2bc2;
	case 11206ULL: goto x86_l_2bc6;
	case 11209ULL: goto x86_l_2bc9;
	case 11212ULL: goto x86_l_2bcc;
	case 11215ULL: goto x86_l_2bcf;
	case 11220ULL: goto x86_l_2bd4;
	case 11222ULL: goto x86_l_2bd6;
	case 11227ULL: goto x86_l_2bdb;
	case 11230ULL: goto x86_l_2bde;
	case 11236ULL: goto x86_l_2be4;
	case 11241ULL: goto x86_l_2be9;
	case 11246ULL: goto x86_l_2bee;
	case 11251ULL: goto x86_l_2bf3;
	case 11256ULL: goto x86_l_2bf8;
	case 11261ULL: goto x86_l_2bfd;
	case 11268ULL: goto x86_l_2c04;
	case 11270ULL: goto x86_l_2c06;
	case 11277ULL: goto x86_l_2c0d;
	case 11279ULL: goto x86_l_2c0f;
	case 11286ULL: goto x86_l_2c16;
	case 11289ULL: goto x86_l_2c19;
	case 11294ULL: goto x86_l_2c1e;
	case 11302ULL: goto x86_l_2c26;
	case 11307ULL: goto x86_l_2c2b;
	case 11312ULL: goto x86_l_2c30;
	case 11317ULL: goto x86_l_2c35;
	case 11322ULL: goto x86_l_2c3a;
	case 11324ULL: goto x86_l_2c3c;
	case 11332ULL: goto x86_l_2c44;
	case 11339ULL: goto x86_l_2c4b;
	case 11345ULL: goto x86_l_2c51;
	case 11349ULL: goto x86_l_2c55;
	case 11354ULL: goto x86_l_2c5a;
	case 11358ULL: goto x86_l_2c5e;
	case 11363ULL: goto x86_l_2c63;
	case 11371ULL: goto x86_l_2c6b;
	case 11374ULL: goto x86_l_2c6e;
	case 11376ULL: goto x86_l_2c70;
	case 11378ULL: goto x86_l_2c72;
	case 11380ULL: goto x86_l_2c74;
	case 11385ULL: goto x86_l_2c79;
	case 11388ULL: goto x86_l_2c7c;
	case 11392ULL: goto x86_l_2c80;
	case 11396ULL: goto x86_l_2c84;
	case 11399ULL: goto x86_l_2c87;
	case 11404ULL: goto x86_l_2c8c;
	case 11409ULL: goto x86_l_2c91;
	case 11415ULL: goto x86_l_2c97;
	case 11420ULL: goto x86_l_2c9c;
	case 11425ULL: goto x86_l_2ca1;
	case 11430ULL: goto x86_l_2ca6;
	case 11435ULL: goto x86_l_2cab;
	case 11440ULL: goto x86_l_2cb0;
	case 11447ULL: goto x86_l_2cb7;
	case 11452ULL: goto x86_l_2cbc;
	case 11456ULL: goto x86_l_2cc0;
	case 11460ULL: goto x86_l_2cc4;
	case 11465ULL: goto x86_l_2cc9;
	case 11469ULL: goto x86_l_2ccd;
	case 11475ULL: goto x86_l_2cd3;
	case 11485ULL: goto x86_l_2cdd;
	case 11489ULL: goto x86_l_2ce1;
	case 11495ULL: goto x86_l_2ce7;
	case 11499ULL: goto x86_l_2ceb;
	case 11502ULL: goto x86_l_2cee;
	case 11507ULL: goto x86_l_2cf3;
	case 11510ULL: goto x86_l_2cf6;
	case 11515ULL: goto x86_l_2cfb;
	case 11520ULL: goto x86_l_2d00;
	case 11528ULL: goto x86_l_2d08;
	case 11532ULL: goto x86_l_2d0c;
	case 11535ULL: goto x86_l_2d0f;
	case 11540ULL: goto x86_l_2d14;
	case 11542ULL: goto x86_l_2d16;
	case 11545ULL: goto x86_l_2d19;
	case 11551ULL: goto x86_l_2d1f;
	case 11556ULL: goto x86_l_2d24;
	case 11559ULL: goto x86_l_2d27;
	case 11561ULL: goto x86_l_2d29;
	case 11563ULL: goto x86_l_2d2b;
	case 11565ULL: goto x86_l_2d2d;
	case 11568ULL: goto x86_l_2d30;
	case 11570ULL: goto x86_l_2d32;
	case 11573ULL: goto x86_l_2d35;
	case 11579ULL: goto x86_l_2d3b;
	case 11586ULL: goto x86_l_2d42;
	case 11590ULL: goto x86_l_2d46;
	case 11595ULL: goto x86_l_2d4b;
	case 11598ULL: goto x86_l_2d4e;
	case 11604ULL: goto x86_l_2d54;
	case 11607ULL: goto x86_l_2d57;
	case 11609ULL: goto x86_l_2d59;
	case 11614ULL: goto x86_l_2d5e;
	case 11620ULL: goto x86_l_2d64;
	case 11627ULL: goto x86_l_2d6b;
	case 11631ULL: goto x86_l_2d6f;
	case 11636ULL: goto x86_l_2d74;
	case 11641ULL: goto x86_l_2d79;
	case 11648ULL: goto x86_l_2d80;
	case 11653ULL: goto x86_l_2d85;
	case 11658ULL: goto x86_l_2d8a;
	case 11663ULL: goto x86_l_2d8f;
	case 11668ULL: goto x86_l_2d94;
	case 11672ULL: goto x86_l_2d98;
	case 11677ULL: goto x86_l_2d9d;
	case 11682ULL: goto x86_l_2da2;
	case 11687ULL: goto x86_l_2da7;
	case 11692ULL: goto x86_l_2dac;
	case 11694ULL: goto x86_l_2dae;
	case 11699ULL: goto x86_l_2db3;
	case 11704ULL: goto x86_l_2db8;
	case 11710ULL: goto x86_l_2dbe;
	case 11714ULL: goto x86_l_2dc2;
	case 11719ULL: goto x86_l_2dc7;
	case 11724ULL: goto x86_l_2dcc;
	case 11729ULL: goto x86_l_2dd1;
	case 11734ULL: goto x86_l_2dd6;
	case 11737ULL: goto x86_l_2dd9;
	case 11739ULL: goto x86_l_2ddb;
	case 11744ULL: goto x86_l_2de0;
	case 11749ULL: goto x86_l_2de5;
	case 11753ULL: goto x86_l_2de9;
	case 11758ULL: goto x86_l_2dee;
	case 11763ULL: goto x86_l_2df3;
	case 11768ULL: goto x86_l_2df8;
	case 11770ULL: goto x86_l_2dfa;
	case 11775ULL: goto x86_l_2dff;
	case 11781ULL: goto x86_l_2e05;
	case 11789ULL: goto x86_l_2e0d;
	case 11794ULL: goto x86_l_2e12;
	case 11799ULL: goto x86_l_2e17;
	case 11804ULL: goto x86_l_2e1c;
	case 11806ULL: goto x86_l_2e1e;
	case 11814ULL: goto x86_l_2e26;
	case 11820ULL: goto x86_l_2e2c;
	case 11825ULL: goto x86_l_2e31;
	case 11830ULL: goto x86_l_2e36;
	case 11835ULL: goto x86_l_2e3b;
	case 11840ULL: goto x86_l_2e40;
	case 11845ULL: goto x86_l_2e45;
	case 11848ULL: goto x86_l_2e48;
	case 11850ULL: goto x86_l_2e4a;
	case 11855ULL: goto x86_l_2e4f;
	case 11861ULL: goto x86_l_2e55;
	case 11866ULL: goto x86_l_2e5a;
	case 11871ULL: goto x86_l_2e5f;
	case 11876ULL: goto x86_l_2e64;
	case 11881ULL: goto x86_l_2e69;
	case 11884ULL: goto x86_l_2e6c;
	case 11886ULL: goto x86_l_2e6e;
	case 11890ULL: goto x86_l_2e72;
	case 11895ULL: goto x86_l_2e77;
	case 11900ULL: goto x86_l_2e7c;
	case 11905ULL: goto x86_l_2e81;
	case 11910ULL: goto x86_l_2e86;
	case 11913ULL: goto x86_l_2e89;
	case 11915ULL: goto x86_l_2e8b;
	case 11920ULL: goto x86_l_2e90;
	case 11925ULL: goto x86_l_2e95;
	case 11930ULL: goto x86_l_2e9a;
	case 11933ULL: goto x86_l_2e9d;
	case 11938ULL: goto x86_l_2ea2;
	case 11940ULL: goto x86_l_2ea4;
	case 11943ULL: goto x86_l_2ea7;
	case 11946ULL: goto x86_l_2eaa;
	case 11949ULL: goto x86_l_2ead;
	case 11957ULL: goto x86_l_2eb5;
	case 11959ULL: goto x86_l_2eb7;
	case 11962ULL: goto x86_l_2eba;
	case 11966ULL: goto x86_l_2ebe;
	case 11969ULL: goto x86_l_2ec1;
	case 11973ULL: goto x86_l_2ec5;
	case 11975ULL: goto x86_l_2ec7;
	case 11978ULL: goto x86_l_2eca;
	case 11980ULL: goto x86_l_2ecc;
	case 11984ULL: goto x86_l_2ed0;
	case 11987ULL: goto x86_l_2ed3;
	case 11993ULL: goto x86_l_2ed9;
	case 11999ULL: goto x86_l_2edf;
	case 12005ULL: goto x86_l_2ee5;
	case 12008ULL: goto x86_l_2ee8;
	case 12010ULL: goto x86_l_2eea;
	case 12015ULL: goto x86_l_2eef;
	case 12017ULL: goto x86_l_2ef1;
	case 12020ULL: goto x86_l_2ef4;
	case 12024ULL: goto x86_l_2ef8;
	case 12027ULL: goto x86_l_2efb;
	case 12030ULL: goto x86_l_2efe;
	case 12033ULL: goto x86_l_2f01;
	case 12038ULL: goto x86_l_2f06;
	case 12040ULL: goto x86_l_2f08;
	case 12045ULL: goto x86_l_2f0d;
	case 12048ULL: goto x86_l_2f10;
	case 12054ULL: goto x86_l_2f16;
	case 12059ULL: goto x86_l_2f1b;
	case 12064ULL: goto x86_l_2f20;
	case 12069ULL: goto x86_l_2f25;
	case 12074ULL: goto x86_l_2f2a;
	case 12079ULL: goto x86_l_2f2f;
	case 12084ULL: goto x86_l_2f34;
	case 12091ULL: goto x86_l_2f3b;
	case 12096ULL: goto x86_l_2f40;
	case 12098ULL: goto x86_l_2f42;
	case 12103ULL: goto x86_l_2f47;
	case 12107ULL: goto x86_l_2f4b;
	case 12111ULL: goto x86_l_2f4f;
	case 12116ULL: goto x86_l_2f54;
	case 12120ULL: goto x86_l_2f58;
	case 12126ULL: goto x86_l_2f5e;
	case 12136ULL: goto x86_l_2f68;
	case 12140ULL: goto x86_l_2f6c;
	case 12146ULL: goto x86_l_2f72;
	case 12150ULL: goto x86_l_2f76;
	case 12153ULL: goto x86_l_2f79;
	case 12158ULL: goto x86_l_2f7e;
	case 12161ULL: goto x86_l_2f81;
	case 12166ULL: goto x86_l_2f86;
	case 12171ULL: goto x86_l_2f8b;
	case 12179ULL: goto x86_l_2f93;
	case 12183ULL: goto x86_l_2f97;
	case 12186ULL: goto x86_l_2f9a;
	case 12191ULL: goto x86_l_2f9f;
	case 12193ULL: goto x86_l_2fa1;
	case 12196ULL: goto x86_l_2fa4;
	case 12202ULL: goto x86_l_2faa;
	case 12207ULL: goto x86_l_2faf;
	case 12210ULL: goto x86_l_2fb2;
	case 12212ULL: goto x86_l_2fb4;
	case 12214ULL: goto x86_l_2fb6;
	case 12216ULL: goto x86_l_2fb8;
	case 12219ULL: goto x86_l_2fbb;
	case 12221ULL: goto x86_l_2fbd;
	case 12224ULL: goto x86_l_2fc0;
	case 12226ULL: goto x86_l_2fc2;
	case 12233ULL: goto x86_l_2fc9;
	case 12237ULL: goto x86_l_2fcd;
	case 12239ULL: goto x86_l_2fcf;
	case 12242ULL: goto x86_l_2fd2;
	case 12244ULL: goto x86_l_2fd4;
	case 12247ULL: goto x86_l_2fd7;
	case 12249ULL: goto x86_l_2fd9;
	case 12254ULL: goto x86_l_2fde;
	case 12256ULL: goto x86_l_2fe0;
	case 12263ULL: goto x86_l_2fe7;
	case 12267ULL: goto x86_l_2feb;
	case 12269ULL: goto x86_l_2fed;
	case 12274ULL: goto x86_l_2ff2;
	case 12281ULL: goto x86_l_2ff9;
	case 12286ULL: goto x86_l_2ffe;
	case 12288ULL: goto x86_l_3000;
	case 12293ULL: goto x86_l_3005;
	case 12300ULL: goto x86_l_300c;
	case 12305ULL: goto x86_l_3011;
	case 12307ULL: goto x86_l_3013;
	case 12312ULL: goto x86_l_3018;
	case 12316ULL: goto x86_l_301c;
	case 12320ULL: goto x86_l_3020;
	case 12325ULL: goto x86_l_3025;
	case 12329ULL: goto x86_l_3029;
	case 12335ULL: goto x86_l_302f;
	case 12345ULL: goto x86_l_3039;
	case 12349ULL: goto x86_l_303d;
	case 12355ULL: goto x86_l_3043;
	case 12359ULL: goto x86_l_3047;
	case 12362ULL: goto x86_l_304a;
	case 12367ULL: goto x86_l_304f;
	case 12370ULL: goto x86_l_3052;
	case 12375ULL: goto x86_l_3057;
	case 12380ULL: goto x86_l_305c;
	default: return 0xffffffffffffffffULL;
	}
x86_l_29b4:
	/* 0x29b4: je     2cab <generic_usdt_process_event+0x2cab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cab;
	}
x86_l_29ba:
	/* 0x29ba: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_29bd:
	/* 0x29bd: je     2a51 <generic_usdt_process_event+0x2a51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a51;
	}
x86_l_29c3:
	/* 0x29c3: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_29c8:
	/* 0x29c8: jne    2d8a <generic_usdt_process_event+0x2d8a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2d8a;
	}
x86_l_29ce:
	/* 0x29ce: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_29d5:
	/* 0x29d5: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_29d9:
	/* 0x29d9: jmp    2cbc <generic_usdt_process_event+0x2cbc> */
	goto x86_l_2cbc;
x86_l_29de:
	/* 0x29de: mov    DWORD PTR [rsp+0xc0],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 824633720833ULL);
x86_l_29e9:
	/* 0x29e9: mov    rdi,QWORD PTR [rip+0x9db] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_29f0:
	/* 0x29f0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_29f2:
	/* 0x29f2: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29f7:
	/* 0x29f7: lea    rdx,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_29ff:
	/* 0x29ff: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2a04:
	/* 0x2a04: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a06:
	/* 0x2a06: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a08:
	/* 0x2a08: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a0d:
	/* 0x2a0d: mov    DWORD PTR [rax],0xfffffffc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4294967292ULL);
x86_l_2a13:
	/* 0x2a13: jmp    106b <generic_usdt_process_event+0x106b> */
	return 4203ULL;
x86_l_2a18:
	/* 0x2a18: mov    DWORD PTR [rsp+0x28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_2a20:
	/* 0x2a20: mov    rdi,QWORD PTR [rip+0x9db] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2a27:
	/* 0x2a27: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a29:
	/* 0x2a29: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a2e:
	/* 0x2a2e: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2a33:
	/* 0x2a33: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2a38:
	/* 0x2a38: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a3a:
	/* 0x2a3a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a3c:
	/* 0x2a3c: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2a44:
	/* 0x2a44: mov    DWORD PTR [r15+rax*1],0xfffffffc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 4294967292ULL);
x86_l_2a4c:
	/* 0x2a4c: jmp    106b <generic_usdt_process_event+0x106b> */
	return 4203ULL;
x86_l_2a51:
	/* 0x2a51: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2a56:
	/* 0x2a56: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2a5d:
	/* 0x2a5d: jmp    2cb7 <generic_usdt_process_event+0x2cb7> */
	goto x86_l_2cb7;
x86_l_2a62:
	/* 0x2a62: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a66:
	/* 0x2a66: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a6b:
	/* 0x2a6b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2a70:
	/* 0x2a70: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a75:
	/* 0x2a75: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a7a:
	/* 0x2a7a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a7c:
	/* 0x2a7c: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2a81:
	/* 0x2a81: cmp    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_2a86:
	/* 0x2a86: je     880 <generic_usdt_process_event+0x880> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2176ULL;
	}
x86_l_2a8c:
	/* 0x2a8c: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2a90:
	/* 0x2a90: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2a95:
	/* 0x2a95: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a9a:
	/* 0x2a9a: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2a9f:
	/* 0x2a9f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2aa4:
	/* 0x2aa4: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2aa7:
	/* 0x2aa7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2aa9:
	/* 0x2aa9: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2aae:
	/* 0x2aae: mov    QWORD PTR [rsp+0x60],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2ab3:
	/* 0x2ab3: lea    rdx,[r15+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ab7:
	/* 0x2ab7: mov    QWORD PTR [rsp+0x58],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2abc:
	/* 0x2abc: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2ac1:
	/* 0x2ac1: cmp    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_2ac6:
	/* 0x2ac6: jne    2ad3 <generic_usdt_process_event+0x2ad3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2ad3;
	}
x86_l_2ac8:
	/* 0x2ac8: cmp    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_2acd:
	/* 0x2acd: je     880 <generic_usdt_process_event+0x880> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2176ULL;
	}
x86_l_2ad3:
	/* 0x2ad3: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2adb:
	/* 0x2adb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2ae0:
	/* 0x2ae0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ae5:
	/* 0x2ae5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2aea:
	/* 0x2aea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2aec:
	/* 0x2aec: cmp    r12,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 144ULL);
x86_l_2af4:
	/* 0x2af4: je     2d94 <generic_usdt_process_event+0x2d94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d94;
	}
x86_l_2afa:
	/* 0x2afa: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2aff:
	/* 0x2aff: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b04:
	/* 0x2b04: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2b09:
	/* 0x2b09: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b0e:
	/* 0x2b0e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b13:
	/* 0x2b13: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2b16:
	/* 0x2b16: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b18:
	/* 0x2b18: cmp    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b1d:
	/* 0x2b1d: je     2d94 <generic_usdt_process_event+0x2d94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d94;
	}
x86_l_2b23:
	/* 0x2b23: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2b28:
	/* 0x2b28: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2b2d:
	/* 0x2b2d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b32:
	/* 0x2b32: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b37:
	/* 0x2b37: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2b3a:
	/* 0x2b3a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b3c:
	/* 0x2b3c: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_2b40:
	/* 0x2b40: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2b45:
	/* 0x2b45: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2b4a:
	/* 0x2b4a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b4f:
	/* 0x2b4f: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2b54:
	/* 0x2b54: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2b57:
	/* 0x2b57: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b59:
	/* 0x2b59: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2b5e:
	/* 0x2b5e: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2b63:
	/* 0x2b63: mov    r12d,DWORD PTR [rsp+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_2b68:
	/* 0x2b68: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2b6b:
	/* 0x2b6b: mov    r13d,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2b70:
	/* 0x2b70: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b72:
	/* 0x2b72: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_2b75:
	/* 0x2b75: sub    edx,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R13, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2b78:
	/* 0x2b78: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_2b7b:
	/* 0x2b7b: add    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 128ULL);
x86_l_2b83:
	/* 0x2b83: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b85:
	/* 0x2b85: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_2b88:
	/* 0x2b88: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_2b8c:
	/* 0x2b8c: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_2b8f:
	/* 0x2b8f: cmovb  ecx,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_2b93:
	/* 0x2b93: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2b95:
	/* 0x2b95: mov    edi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_32);
x86_l_2b98:
	/* 0x2b98: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2b9a:
	/* 0x2b9a: mov    DWORD PTR [rsp+0x70],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2b9e:
	/* 0x2b9e: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2ba1:
	/* 0x2ba1: jb     885 <generic_usdt_process_event+0x885> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2181ULL;
	}
x86_l_2ba7:
	/* 0x2ba7: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_2bad:
	/* 0x2bad: ja     885 <generic_usdt_process_event+0x885> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2181ULL;
	}
x86_l_2bb3:
	/* 0x2bb3: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_2bb6:
	/* 0x2bb6: jbe    2bbd <generic_usdt_process_event+0x2bbd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2bbd;
	}
x86_l_2bb8:
	/* 0x2bb8: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_2bbd:
	/* 0x2bbd: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2bbf:
	/* 0x2bbf: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_2bc2:
	/* 0x2bc2: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_2bc6:
	/* 0x2bc6: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2bc9:
	/* 0x2bc9: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2bcc:
	/* 0x2bcc: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2bcf:
	/* 0x2bcf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2bd4:
	/* 0x2bd4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bd6:
	/* 0x2bd6: mov    QWORD PTR [rsp+0x68],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2bdb:
	/* 0x2bdb: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_2bde:
	/* 0x2bde: jbe    885 <generic_usdt_process_event+0x885> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 2181ULL;
	}
x86_l_2be4:
	/* 0x2be4: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2be9:
	/* 0x2be9: mov    QWORD PTR [rsp+0x50],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2bee:
	/* 0x2bee: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2bf3:
	/* 0x2bf3: mov    r15,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2bf8:
	/* 0x2bf8: jmp    2df3 <generic_usdt_process_event+0x2df3> */
	goto x86_l_2df3;
x86_l_2bfd:
	/* 0x2bfd: add    r15,0x5e60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24160ULL);
x86_l_2c04:
	/* 0x2c04: jmp    2c16 <generic_usdt_process_event+0x2c16> */
	goto x86_l_2c16;
x86_l_2c06:
	/* 0x2c06: add    r15,0x5e68 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24168ULL);
x86_l_2c0d:
	/* 0x2c0d: jmp    2c16 <generic_usdt_process_event+0x2c16> */
	goto x86_l_2c16;
x86_l_2c0f:
	/* 0x2c0f: add    r15,0x5e50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24144ULL);
x86_l_2c16:
	/* 0x2c16: mov    rax,QWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c19:
	/* 0x2c19: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2c1e:
	/* 0x2c1e: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2c26:
	/* 0x2c26: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2c2b:
	/* 0x2c2b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2c30:
	/* 0x2c30: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c35:
	/* 0x2c35: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c3a:
	/* 0x2c3a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c3c:
	/* 0x2c3c: mov    r13,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2c44:
	/* 0x2c44: cmp    r13,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4095ULL);
x86_l_2c4b:
	/* 0x2c4b: mov    r12d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4095ULL);
x86_l_2c51:
	/* 0x2c51: cmovb  r12,r13 */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_R13, X86_WIDTH_64, X86_CC_B);
x86_l_2c55:
	/* 0x2c55: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c5a:
	/* 0x2c5a: lea    rdi,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c5e:
	/* 0x2c5e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c63:
	/* 0x2c63: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2c6b:
	/* 0x2c6b: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_2c6e:
	/* 0x2c6e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c70:
	/* 0x2c70: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c72:
	/* 0x2c72: js     2c8c <generic_usdt_process_event+0x2c8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2c8c;
	}
x86_l_2c74:
	/* 0x2c74: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c79:
	/* 0x2c79: mov    DWORD PTR [rax],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c7c:
	/* 0x2c7c: mov    DWORD PTR [rax+0x4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2c80:
	/* 0x2c80: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2c84:
	/* 0x2c84: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2c87:
	/* 0x2c87: jmp    38da <generic_usdt_process_event+0x38da> */
	return 14554ULL;
x86_l_2c8c:
	/* 0x2c8c: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c91:
	/* 0x2c91: mov    DWORD PTR [rax],0xfffffffe */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4294967294ULL);
x86_l_2c97:
	/* 0x2c97: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c9c:
	/* 0x2c9c: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_2ca1:
	/* 0x2ca1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2ca6:
	/* 0x2ca6: jmp    38e4 <generic_usdt_process_event+0x38e4> */
	return 14564ULL;
x86_l_2cab:
	/* 0x2cab: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2cb0:
	/* 0x2cb0: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2cb7:
	/* 0x2cb7: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2cbc:
	/* 0x2cbc: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2cc0:
	/* 0x2cc0: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cc4:
	/* 0x2cc4: movzx  r13d,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2cc9:
	/* 0x2cc9: cmp    r13,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 60ULL);
x86_l_2ccd:
	/* 0x2ccd: ja     3964 <generic_usdt_process_event+0x3964> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 14692ULL;
	}
x86_l_2cd3:
	/* 0x2cd3: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2cdd:
	/* 0x2cdd: bt     rcx,r13 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_2ce1:
	/* 0x2ce1: jae    3964 <generic_usdt_process_event+0x3964> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 14692ULL;
	}
x86_l_2ce7:
	/* 0x2ce7: mov    BYTE PTR [r15+0x5],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2ceb:
	/* 0x2ceb: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2cee:
	/* 0x2cee: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2cf3:
	/* 0x2cf3: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2cf6:
	/* 0x2cf6: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2cfb:
	/* 0x2cfb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d00:
	/* 0x2d00: mov    rdi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2d08:
	/* 0x2d08: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2d0c:
	/* 0x2d0c: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2d0f:
	/* 0x2d0f: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2d14:
	/* 0x2d14: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d16:
	/* 0x2d16: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d19:
	/* 0x2d19: js     3716 <generic_usdt_process_event+0x3716> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14102ULL;
	}
x86_l_2d1f:
	/* 0x2d1f: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2d24:
	/* 0x2d24: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2d27:
	/* 0x2d27: jg     2d4b <generic_usdt_process_event+0x2d4b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2d4b;
	}
x86_l_2d29:
	/* 0x2d29: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2d2b:
	/* 0x2d2b: je     2d74 <generic_usdt_process_event+0x2d74> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d74;
	}
x86_l_2d2d:
	/* 0x2d2d: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2d30:
	/* 0x2d30: je     2d74 <generic_usdt_process_event+0x2d74> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d74;
	}
x86_l_2d32:
	/* 0x2d32: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2d35:
	/* 0x2d35: jne    2f42 <generic_usdt_process_event+0x2f42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2f42;
	}
x86_l_2d3b:
	/* 0x2d3b: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2d42:
	/* 0x2d42: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2d46:
	/* 0x2d46: jmp    2f47 <generic_usdt_process_event+0x2f47> */
	goto x86_l_2f47;
x86_l_2d4b:
	/* 0x2d4b: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2d4e:
	/* 0x2d4e: je     2f2f <generic_usdt_process_event+0x2f2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f2f;
	}
x86_l_2d54:
	/* 0x2d54: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2d57:
	/* 0x2d57: je     2d74 <generic_usdt_process_event+0x2d74> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d74;
	}
x86_l_2d59:
	/* 0x2d59: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2d5e:
	/* 0x2d5e: jne    2f42 <generic_usdt_process_event+0x2f42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2f42;
	}
x86_l_2d64:
	/* 0x2d64: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2d6b:
	/* 0x2d6b: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2d6f:
	/* 0x2d6f: jmp    2f47 <generic_usdt_process_event+0x2f47> */
	goto x86_l_2f47;
x86_l_2d74:
	/* 0x2d74: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2d79:
	/* 0x2d79: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2d80:
	/* 0x2d80: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2d85:
	/* 0x2d85: jmp    2f47 <generic_usdt_process_event+0x2f47> */
	goto x86_l_2f47;
x86_l_2d8a:
	/* 0x2d8a: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2d8f:
	/* 0x2d8f: jmp    2cbc <generic_usdt_process_event+0x2cbc> */
	goto x86_l_2cbc;
x86_l_2d94:
	/* 0x2d94: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d98:
	/* 0x2d98: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d9d:
	/* 0x2d9d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2da2:
	/* 0x2da2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2da7:
	/* 0x2da7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2dac:
	/* 0x2dac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dae:
	/* 0x2dae: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2db3:
	/* 0x2db3: cmp    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_2db8:
	/* 0x2db8: je     880 <generic_usdt_process_event+0x880> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2176ULL;
	}
x86_l_2dbe:
	/* 0x2dbe: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2dc2:
	/* 0x2dc2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2dc7:
	/* 0x2dc7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2dcc:
	/* 0x2dcc: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2dd1:
	/* 0x2dd1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2dd6:
	/* 0x2dd6: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2dd9:
	/* 0x2dd9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ddb:
	/* 0x2ddb: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2de0:
	/* 0x2de0: mov    QWORD PTR [rsp+0x60],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2de5:
	/* 0x2de5: lea    rdx,[r15+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2de9:
	/* 0x2de9: mov    QWORD PTR [rsp+0x58],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2dee:
	/* 0x2dee: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2df3:
	/* 0x2df3: cmp    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_2df8:
	/* 0x2df8: jne    2e05 <generic_usdt_process_event+0x2e05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2e05;
	}
x86_l_2dfa:
	/* 0x2dfa: cmp    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_2dff:
	/* 0x2dff: je     880 <generic_usdt_process_event+0x880> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2176ULL;
	}
x86_l_2e05:
	/* 0x2e05: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2e0d:
	/* 0x2e0d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2e12:
	/* 0x2e12: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e17:
	/* 0x2e17: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e1c:
	/* 0x2e1c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e1e:
	/* 0x2e1e: cmp    r12,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 144ULL);
x86_l_2e26:
	/* 0x2e26: je     31b7 <generic_usdt_process_event+0x31b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12727ULL;
	}
x86_l_2e2c:
	/* 0x2e2c: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2e31:
	/* 0x2e31: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e36:
	/* 0x2e36: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2e3b:
	/* 0x2e3b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e40:
	/* 0x2e40: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e45:
	/* 0x2e45: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2e48:
	/* 0x2e48: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e4a:
	/* 0x2e4a: cmp    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e4f:
	/* 0x2e4f: je     31b7 <generic_usdt_process_event+0x31b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12727ULL;
	}
x86_l_2e55:
	/* 0x2e55: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2e5a:
	/* 0x2e5a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2e5f:
	/* 0x2e5f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e64:
	/* 0x2e64: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e69:
	/* 0x2e69: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2e6c:
	/* 0x2e6c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e6e:
	/* 0x2e6e: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_2e72:
	/* 0x2e72: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2e77:
	/* 0x2e77: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2e7c:
	/* 0x2e7c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e81:
	/* 0x2e81: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2e86:
	/* 0x2e86: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2e89:
	/* 0x2e89: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e8b:
	/* 0x2e8b: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2e90:
	/* 0x2e90: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2e95:
	/* 0x2e95: mov    r12d,DWORD PTR [rsp+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_2e9a:
	/* 0x2e9a: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2e9d:
	/* 0x2e9d: mov    r13d,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2ea2:
	/* 0x2ea2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ea4:
	/* 0x2ea4: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_2ea7:
	/* 0x2ea7: sub    edx,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R13, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2eaa:
	/* 0x2eaa: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_2ead:
	/* 0x2ead: add    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 128ULL);
x86_l_2eb5:
	/* 0x2eb5: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2eb7:
	/* 0x2eb7: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_2eba:
	/* 0x2eba: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_2ebe:
	/* 0x2ebe: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_2ec1:
	/* 0x2ec1: cmovb  ecx,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_2ec5:
	/* 0x2ec5: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2ec7:
	/* 0x2ec7: mov    edi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_32);
x86_l_2eca:
	/* 0x2eca: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2ecc:
	/* 0x2ecc: mov    DWORD PTR [rsp+0x70],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2ed0:
	/* 0x2ed0: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2ed3:
	/* 0x2ed3: jb     885 <generic_usdt_process_event+0x885> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2181ULL;
	}
x86_l_2ed9:
	/* 0x2ed9: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_2edf:
	/* 0x2edf: ja     885 <generic_usdt_process_event+0x885> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2181ULL;
	}
x86_l_2ee5:
	/* 0x2ee5: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_2ee8:
	/* 0x2ee8: jbe    2eef <generic_usdt_process_event+0x2eef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2eef;
	}
x86_l_2eea:
	/* 0x2eea: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_2eef:
	/* 0x2eef: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ef1:
	/* 0x2ef1: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_2ef4:
	/* 0x2ef4: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_2ef8:
	/* 0x2ef8: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2efb:
	/* 0x2efb: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2efe:
	/* 0x2efe: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2f01:
	/* 0x2f01: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f06:
	/* 0x2f06: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f08:
	/* 0x2f08: mov    QWORD PTR [rsp+0x68],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2f0d:
	/* 0x2f0d: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_2f10:
	/* 0x2f10: jbe    885 <generic_usdt_process_event+0x885> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 2181ULL;
	}
x86_l_2f16:
	/* 0x2f16: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2f1b:
	/* 0x2f1b: mov    QWORD PTR [rsp+0x50],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2f20:
	/* 0x2f20: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2f25:
	/* 0x2f25: mov    r15,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2f2a:
	/* 0x2f2a: jmp    3216 <generic_usdt_process_event+0x3216> */
	return 12822ULL;
x86_l_2f2f:
	/* 0x2f2f: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2f34:
	/* 0x2f34: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2f3b:
	/* 0x2f3b: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2f40:
	/* 0x2f40: jmp    2f47 <generic_usdt_process_event+0x2f47> */
	goto x86_l_2f47;
x86_l_2f42:
	/* 0x2f42: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2f47:
	/* 0x2f47: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2f4b:
	/* 0x2f4b: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f4f:
	/* 0x2f4f: movzx  r13d,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2f54:
	/* 0x2f54: cmp    r13,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 60ULL);
x86_l_2f58:
	/* 0x2f58: ja     3964 <generic_usdt_process_event+0x3964> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 14692ULL;
	}
x86_l_2f5e:
	/* 0x2f5e: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2f68:
	/* 0x2f68: bt     rcx,r13 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_2f6c:
	/* 0x2f6c: jae    3964 <generic_usdt_process_event+0x3964> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 14692ULL;
	}
x86_l_2f72:
	/* 0x2f72: mov    BYTE PTR [r15+0x5],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2f76:
	/* 0x2f76: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2f79:
	/* 0x2f79: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2f7e:
	/* 0x2f7e: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2f81:
	/* 0x2f81: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2f86:
	/* 0x2f86: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f8b:
	/* 0x2f8b: mov    rdi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2f93:
	/* 0x2f93: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2f97:
	/* 0x2f97: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2f9a:
	/* 0x2f9a: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2f9f:
	/* 0x2f9f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fa1:
	/* 0x2fa1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2fa4:
	/* 0x2fa4: js     3716 <generic_usdt_process_event+0x3716> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14102ULL;
	}
x86_l_2faa:
	/* 0x2faa: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2faf:
	/* 0x2faf: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2fb2:
	/* 0x2fb2: jg     2fcf <generic_usdt_process_event+0x2fcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2fcf;
	}
x86_l_2fb4:
	/* 0x2fb4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2fb6:
	/* 0x2fb6: je     2fed <generic_usdt_process_event+0x2fed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fed;
	}
x86_l_2fb8:
	/* 0x2fb8: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2fbb:
	/* 0x2fbb: je     2fed <generic_usdt_process_event+0x2fed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fed;
	}
x86_l_2fbd:
	/* 0x2fbd: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2fc0:
	/* 0x2fc0: jne    3013 <generic_usdt_process_event+0x3013> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3013;
	}
x86_l_2fc2:
	/* 0x2fc2: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2fc9:
	/* 0x2fc9: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2fcd:
	/* 0x2fcd: jmp    3018 <generic_usdt_process_event+0x3018> */
	goto x86_l_3018;
x86_l_2fcf:
	/* 0x2fcf: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2fd2:
	/* 0x2fd2: je     3000 <generic_usdt_process_event+0x3000> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3000;
	}
x86_l_2fd4:
	/* 0x2fd4: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2fd7:
	/* 0x2fd7: je     2fed <generic_usdt_process_event+0x2fed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fed;
	}
x86_l_2fd9:
	/* 0x2fd9: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2fde:
	/* 0x2fde: jne    3013 <generic_usdt_process_event+0x3013> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3013;
	}
x86_l_2fe0:
	/* 0x2fe0: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2fe7:
	/* 0x2fe7: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2feb:
	/* 0x2feb: jmp    3018 <generic_usdt_process_event+0x3018> */
	goto x86_l_3018;
x86_l_2fed:
	/* 0x2fed: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2ff2:
	/* 0x2ff2: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2ff9:
	/* 0x2ff9: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2ffe:
	/* 0x2ffe: jmp    3018 <generic_usdt_process_event+0x3018> */
	goto x86_l_3018;
x86_l_3000:
	/* 0x3000: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_3005:
	/* 0x3005: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_300c:
	/* 0x300c: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_3011:
	/* 0x3011: jmp    3018 <generic_usdt_process_event+0x3018> */
	goto x86_l_3018;
x86_l_3013:
	/* 0x3013: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_3018:
	/* 0x3018: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_301c:
	/* 0x301c: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3020:
	/* 0x3020: movzx  r13d,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_3025:
	/* 0x3025: cmp    r13,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 60ULL);
x86_l_3029:
	/* 0x3029: ja     3964 <generic_usdt_process_event+0x3964> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 14692ULL;
	}
x86_l_302f:
	/* 0x302f: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_3039:
	/* 0x3039: bt     rcx,r13 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_303d:
	/* 0x303d: jae    3964 <generic_usdt_process_event+0x3964> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 14692ULL;
	}
x86_l_3043:
	/* 0x3043: mov    BYTE PTR [r15+0x5],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_3047:
	/* 0x3047: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_304a:
	/* 0x304a: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_304f:
	/* 0x304f: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3052:
	/* 0x3052: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3057:
	/* 0x3057: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_305c:
	/* 0x305c: mov    rdi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
	return 12388ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_generic_usdt_process_event_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12388ULL: goto x86_l_3064;
	case 12392ULL: goto x86_l_3068;
	case 12395ULL: goto x86_l_306b;
	case 12400ULL: goto x86_l_3070;
	case 12402ULL: goto x86_l_3072;
	case 12405ULL: goto x86_l_3075;
	case 12411ULL: goto x86_l_307b;
	case 12416ULL: goto x86_l_3080;
	case 12419ULL: goto x86_l_3083;
	case 12421ULL: goto x86_l_3085;
	case 12423ULL: goto x86_l_3087;
	case 12425ULL: goto x86_l_3089;
	case 12428ULL: goto x86_l_308c;
	case 12430ULL: goto x86_l_308e;
	case 12433ULL: goto x86_l_3091;
	case 12435ULL: goto x86_l_3093;
	case 12442ULL: goto x86_l_309a;
	case 12446ULL: goto x86_l_309e;
	case 12448ULL: goto x86_l_30a0;
	case 12451ULL: goto x86_l_30a3;
	case 12453ULL: goto x86_l_30a5;
	case 12456ULL: goto x86_l_30a8;
	case 12458ULL: goto x86_l_30aa;
	case 12463ULL: goto x86_l_30af;
	case 12465ULL: goto x86_l_30b1;
	case 12472ULL: goto x86_l_30b8;
	case 12476ULL: goto x86_l_30bc;
	case 12478ULL: goto x86_l_30be;
	case 12483ULL: goto x86_l_30c3;
	case 12490ULL: goto x86_l_30ca;
	case 12495ULL: goto x86_l_30cf;
	case 12497ULL: goto x86_l_30d1;
	case 12502ULL: goto x86_l_30d6;
	case 12509ULL: goto x86_l_30dd;
	case 12514ULL: goto x86_l_30e2;
	case 12516ULL: goto x86_l_30e4;
	case 12521ULL: goto x86_l_30e9;
	case 12525ULL: goto x86_l_30ed;
	case 12529ULL: goto x86_l_30f1;
	case 12534ULL: goto x86_l_30f6;
	case 12538ULL: goto x86_l_30fa;
	case 12544ULL: goto x86_l_3100;
	case 12554ULL: goto x86_l_310a;
	case 12558ULL: goto x86_l_310e;
	case 12564ULL: goto x86_l_3114;
	case 12568ULL: goto x86_l_3118;
	case 12571ULL: goto x86_l_311b;
	case 12576ULL: goto x86_l_3120;
	case 12579ULL: goto x86_l_3123;
	case 12584ULL: goto x86_l_3128;
	case 12589ULL: goto x86_l_312d;
	case 12597ULL: goto x86_l_3135;
	case 12601ULL: goto x86_l_3139;
	case 12604ULL: goto x86_l_313c;
	case 12609ULL: goto x86_l_3141;
	case 12611ULL: goto x86_l_3143;
	case 12614ULL: goto x86_l_3146;
	case 12620ULL: goto x86_l_314c;
	case 12625ULL: goto x86_l_3151;
	case 12628ULL: goto x86_l_3154;
	case 12630ULL: goto x86_l_3156;
	case 12632ULL: goto x86_l_3158;
	case 12634ULL: goto x86_l_315a;
	case 12637ULL: goto x86_l_315d;
	case 12639ULL: goto x86_l_315f;
	case 12642ULL: goto x86_l_3162;
	case 12648ULL: goto x86_l_3168;
	case 12655ULL: goto x86_l_316f;
	case 12659ULL: goto x86_l_3173;
	case 12664ULL: goto x86_l_3178;
	case 12667ULL: goto x86_l_317b;
	case 12673ULL: goto x86_l_3181;
	case 12676ULL: goto x86_l_3184;
	case 12678ULL: goto x86_l_3186;
	case 12683ULL: goto x86_l_318b;
	case 12689ULL: goto x86_l_3191;
	case 12696ULL: goto x86_l_3198;
	case 12700ULL: goto x86_l_319c;
	case 12705ULL: goto x86_l_31a1;
	case 12710ULL: goto x86_l_31a6;
	case 12717ULL: goto x86_l_31ad;
	case 12722ULL: goto x86_l_31b2;
	case 12727ULL: goto x86_l_31b7;
	case 12731ULL: goto x86_l_31bb;
	case 12736ULL: goto x86_l_31c0;
	case 12741ULL: goto x86_l_31c5;
	case 12746ULL: goto x86_l_31ca;
	case 12751ULL: goto x86_l_31cf;
	case 12753ULL: goto x86_l_31d1;
	case 12758ULL: goto x86_l_31d6;
	case 12763ULL: goto x86_l_31db;
	case 12769ULL: goto x86_l_31e1;
	case 12773ULL: goto x86_l_31e5;
	case 12778ULL: goto x86_l_31ea;
	case 12783ULL: goto x86_l_31ef;
	case 12788ULL: goto x86_l_31f4;
	case 12793ULL: goto x86_l_31f9;
	case 12796ULL: goto x86_l_31fc;
	case 12798ULL: goto x86_l_31fe;
	case 12803ULL: goto x86_l_3203;
	case 12808ULL: goto x86_l_3208;
	case 12812ULL: goto x86_l_320c;
	case 12817ULL: goto x86_l_3211;
	case 12822ULL: goto x86_l_3216;
	case 12827ULL: goto x86_l_321b;
	case 12829ULL: goto x86_l_321d;
	case 12834ULL: goto x86_l_3222;
	case 12840ULL: goto x86_l_3228;
	case 12848ULL: goto x86_l_3230;
	case 12853ULL: goto x86_l_3235;
	case 12858ULL: goto x86_l_323a;
	case 12863ULL: goto x86_l_323f;
	case 12865ULL: goto x86_l_3241;
	case 12873ULL: goto x86_l_3249;
	case 12879ULL: goto x86_l_324f;
	case 12884ULL: goto x86_l_3254;
	case 12889ULL: goto x86_l_3259;
	case 12894ULL: goto x86_l_325e;
	case 12899ULL: goto x86_l_3263;
	case 12904ULL: goto x86_l_3268;
	case 12907ULL: goto x86_l_326b;
	case 12909ULL: goto x86_l_326d;
	case 12914ULL: goto x86_l_3272;
	case 12920ULL: goto x86_l_3278;
	case 12925ULL: goto x86_l_327d;
	case 12930ULL: goto x86_l_3282;
	case 12935ULL: goto x86_l_3287;
	case 12940ULL: goto x86_l_328c;
	case 12943ULL: goto x86_l_328f;
	case 12945ULL: goto x86_l_3291;
	case 12949ULL: goto x86_l_3295;
	case 12954ULL: goto x86_l_329a;
	case 12959ULL: goto x86_l_329f;
	case 12964ULL: goto x86_l_32a4;
	case 12969ULL: goto x86_l_32a9;
	case 12972ULL: goto x86_l_32ac;
	case 12974ULL: goto x86_l_32ae;
	case 12979ULL: goto x86_l_32b3;
	case 12984ULL: goto x86_l_32b8;
	case 12989ULL: goto x86_l_32bd;
	case 12992ULL: goto x86_l_32c0;
	case 12997ULL: goto x86_l_32c5;
	case 12999ULL: goto x86_l_32c7;
	case 13002ULL: goto x86_l_32ca;
	case 13005ULL: goto x86_l_32cd;
	case 13008ULL: goto x86_l_32d0;
	case 13016ULL: goto x86_l_32d8;
	case 13018ULL: goto x86_l_32da;
	case 13021ULL: goto x86_l_32dd;
	case 13025ULL: goto x86_l_32e1;
	case 13028ULL: goto x86_l_32e4;
	case 13032ULL: goto x86_l_32e8;
	case 13034ULL: goto x86_l_32ea;
	case 13037ULL: goto x86_l_32ed;
	case 13039ULL: goto x86_l_32ef;
	case 13043ULL: goto x86_l_32f3;
	case 13046ULL: goto x86_l_32f6;
	case 13052ULL: goto x86_l_32fc;
	case 13058ULL: goto x86_l_3302;
	case 13064ULL: goto x86_l_3308;
	case 13067ULL: goto x86_l_330b;
	case 13069ULL: goto x86_l_330d;
	case 13074ULL: goto x86_l_3312;
	case 13076ULL: goto x86_l_3314;
	case 13079ULL: goto x86_l_3317;
	case 13083ULL: goto x86_l_331b;
	case 13086ULL: goto x86_l_331e;
	case 13089ULL: goto x86_l_3321;
	case 13092ULL: goto x86_l_3324;
	case 13097ULL: goto x86_l_3329;
	case 13099ULL: goto x86_l_332b;
	case 13104ULL: goto x86_l_3330;
	case 13107ULL: goto x86_l_3333;
	case 13113ULL: goto x86_l_3339;
	case 13118ULL: goto x86_l_333e;
	case 13123ULL: goto x86_l_3343;
	case 13128ULL: goto x86_l_3348;
	case 13133ULL: goto x86_l_334d;
	case 13138ULL: goto x86_l_3352;
	case 13143ULL: goto x86_l_3357;
	case 13150ULL: goto x86_l_335e;
	case 13155ULL: goto x86_l_3363;
	case 13157ULL: goto x86_l_3365;
	case 13162ULL: goto x86_l_336a;
	case 13166ULL: goto x86_l_336e;
	case 13170ULL: goto x86_l_3372;
	case 13175ULL: goto x86_l_3377;
	case 13179ULL: goto x86_l_337b;
	case 13185ULL: goto x86_l_3381;
	case 13195ULL: goto x86_l_338b;
	case 13199ULL: goto x86_l_338f;
	case 13205ULL: goto x86_l_3395;
	case 13209ULL: goto x86_l_3399;
	case 13212ULL: goto x86_l_339c;
	case 13217ULL: goto x86_l_33a1;
	case 13220ULL: goto x86_l_33a4;
	case 13225ULL: goto x86_l_33a9;
	case 13230ULL: goto x86_l_33ae;
	case 13238ULL: goto x86_l_33b6;
	case 13242ULL: goto x86_l_33ba;
	case 13245ULL: goto x86_l_33bd;
	case 13250ULL: goto x86_l_33c2;
	case 13252ULL: goto x86_l_33c4;
	case 13255ULL: goto x86_l_33c7;
	case 13261ULL: goto x86_l_33cd;
	case 13266ULL: goto x86_l_33d2;
	case 13269ULL: goto x86_l_33d5;
	case 13271ULL: goto x86_l_33d7;
	case 13273ULL: goto x86_l_33d9;
	case 13275ULL: goto x86_l_33db;
	case 13278ULL: goto x86_l_33de;
	case 13280ULL: goto x86_l_33e0;
	case 13283ULL: goto x86_l_33e3;
	case 13285ULL: goto x86_l_33e5;
	case 13292ULL: goto x86_l_33ec;
	case 13296ULL: goto x86_l_33f0;
	case 13298ULL: goto x86_l_33f2;
	case 13301ULL: goto x86_l_33f5;
	case 13303ULL: goto x86_l_33f7;
	case 13306ULL: goto x86_l_33fa;
	case 13308ULL: goto x86_l_33fc;
	case 13313ULL: goto x86_l_3401;
	case 13315ULL: goto x86_l_3403;
	case 13322ULL: goto x86_l_340a;
	case 13326ULL: goto x86_l_340e;
	case 13328ULL: goto x86_l_3410;
	case 13333ULL: goto x86_l_3415;
	case 13340ULL: goto x86_l_341c;
	case 13345ULL: goto x86_l_3421;
	case 13347ULL: goto x86_l_3423;
	case 13352ULL: goto x86_l_3428;
	case 13359ULL: goto x86_l_342f;
	case 13364ULL: goto x86_l_3434;
	case 13366ULL: goto x86_l_3436;
	case 13371ULL: goto x86_l_343b;
	case 13375ULL: goto x86_l_343f;
	case 13379ULL: goto x86_l_3443;
	case 13384ULL: goto x86_l_3448;
	case 13388ULL: goto x86_l_344c;
	case 13394ULL: goto x86_l_3452;
	case 13404ULL: goto x86_l_345c;
	case 13408ULL: goto x86_l_3460;
	case 13414ULL: goto x86_l_3466;
	case 13418ULL: goto x86_l_346a;
	case 13421ULL: goto x86_l_346d;
	case 13426ULL: goto x86_l_3472;
	case 13429ULL: goto x86_l_3475;
	case 13434ULL: goto x86_l_347a;
	case 13439ULL: goto x86_l_347f;
	case 13447ULL: goto x86_l_3487;
	case 13451ULL: goto x86_l_348b;
	case 13454ULL: goto x86_l_348e;
	case 13459ULL: goto x86_l_3493;
	case 13461ULL: goto x86_l_3495;
	case 13464ULL: goto x86_l_3498;
	case 13470ULL: goto x86_l_349e;
	case 13475ULL: goto x86_l_34a3;
	case 13478ULL: goto x86_l_34a6;
	case 13480ULL: goto x86_l_34a8;
	case 13482ULL: goto x86_l_34aa;
	case 13484ULL: goto x86_l_34ac;
	case 13487ULL: goto x86_l_34af;
	case 13489ULL: goto x86_l_34b1;
	case 13492ULL: goto x86_l_34b4;
	case 13498ULL: goto x86_l_34ba;
	case 13505ULL: goto x86_l_34c1;
	case 13509ULL: goto x86_l_34c5;
	case 13514ULL: goto x86_l_34ca;
	case 13517ULL: goto x86_l_34cd;
	case 13523ULL: goto x86_l_34d3;
	case 13526ULL: goto x86_l_34d6;
	case 13528ULL: goto x86_l_34d8;
	case 13533ULL: goto x86_l_34dd;
	case 13539ULL: goto x86_l_34e3;
	case 13546ULL: goto x86_l_34ea;
	case 13550ULL: goto x86_l_34ee;
	case 13555ULL: goto x86_l_34f3;
	case 13560ULL: goto x86_l_34f8;
	case 13567ULL: goto x86_l_34ff;
	case 13572ULL: goto x86_l_3504;
	case 13577ULL: goto x86_l_3509;
	case 13581ULL: goto x86_l_350d;
	case 13586ULL: goto x86_l_3512;
	case 13591ULL: goto x86_l_3517;
	case 13596ULL: goto x86_l_351c;
	case 13601ULL: goto x86_l_3521;
	case 13603ULL: goto x86_l_3523;
	case 13608ULL: goto x86_l_3528;
	case 13613ULL: goto x86_l_352d;
	case 13619ULL: goto x86_l_3533;
	case 13623ULL: goto x86_l_3537;
	case 13628ULL: goto x86_l_353c;
	case 13633ULL: goto x86_l_3541;
	case 13638ULL: goto x86_l_3546;
	case 13643ULL: goto x86_l_354b;
	case 13646ULL: goto x86_l_354e;
	case 13648ULL: goto x86_l_3550;
	case 13653ULL: goto x86_l_3555;
	case 13658ULL: goto x86_l_355a;
	case 13662ULL: goto x86_l_355e;
	case 13667ULL: goto x86_l_3563;
	case 13672ULL: goto x86_l_3568;
	case 13677ULL: goto x86_l_356d;
	case 13679ULL: goto x86_l_356f;
	case 13684ULL: goto x86_l_3574;
	case 13690ULL: goto x86_l_357a;
	case 13698ULL: goto x86_l_3582;
	case 13703ULL: goto x86_l_3587;
	case 13708ULL: goto x86_l_358c;
	case 13713ULL: goto x86_l_3591;
	case 13715ULL: goto x86_l_3593;
	case 13723ULL: goto x86_l_359b;
	case 13729ULL: goto x86_l_35a1;
	case 13734ULL: goto x86_l_35a6;
	case 13739ULL: goto x86_l_35ab;
	case 13744ULL: goto x86_l_35b0;
	case 13749ULL: goto x86_l_35b5;
	case 13754ULL: goto x86_l_35ba;
	case 13757ULL: goto x86_l_35bd;
	case 13759ULL: goto x86_l_35bf;
	case 13764ULL: goto x86_l_35c4;
	case 13770ULL: goto x86_l_35ca;
	case 13775ULL: goto x86_l_35cf;
	case 13780ULL: goto x86_l_35d4;
	case 13785ULL: goto x86_l_35d9;
	case 13790ULL: goto x86_l_35de;
	case 13793ULL: goto x86_l_35e1;
	case 13795ULL: goto x86_l_35e3;
	case 13799ULL: goto x86_l_35e7;
	case 13804ULL: goto x86_l_35ec;
	case 13809ULL: goto x86_l_35f1;
	case 13814ULL: goto x86_l_35f6;
	case 13819ULL: goto x86_l_35fb;
	case 13822ULL: goto x86_l_35fe;
	case 13824ULL: goto x86_l_3600;
	case 13829ULL: goto x86_l_3605;
	case 13834ULL: goto x86_l_360a;
	case 13839ULL: goto x86_l_360f;
	case 13842ULL: goto x86_l_3612;
	case 13847ULL: goto x86_l_3617;
	case 13849ULL: goto x86_l_3619;
	case 13852ULL: goto x86_l_361c;
	case 13855ULL: goto x86_l_361f;
	case 13858ULL: goto x86_l_3622;
	case 13866ULL: goto x86_l_362a;
	case 13868ULL: goto x86_l_362c;
	case 13871ULL: goto x86_l_362f;
	case 13875ULL: goto x86_l_3633;
	case 13878ULL: goto x86_l_3636;
	case 13882ULL: goto x86_l_363a;
	case 13884ULL: goto x86_l_363c;
	case 13887ULL: goto x86_l_363f;
	case 13889ULL: goto x86_l_3641;
	case 13893ULL: goto x86_l_3645;
	case 13896ULL: goto x86_l_3648;
	case 13902ULL: goto x86_l_364e;
	case 13908ULL: goto x86_l_3654;
	case 13914ULL: goto x86_l_365a;
	case 13917ULL: goto x86_l_365d;
	case 13919ULL: goto x86_l_365f;
	case 13924ULL: goto x86_l_3664;
	case 13926ULL: goto x86_l_3666;
	case 13929ULL: goto x86_l_3669;
	case 13933ULL: goto x86_l_366d;
	case 13936ULL: goto x86_l_3670;
	case 13939ULL: goto x86_l_3673;
	case 13942ULL: goto x86_l_3676;
	case 13947ULL: goto x86_l_367b;
	case 13949ULL: goto x86_l_367d;
	case 13954ULL: goto x86_l_3682;
	case 13957ULL: goto x86_l_3685;
	case 13963ULL: goto x86_l_368b;
	case 13968ULL: goto x86_l_3690;
	case 13973ULL: goto x86_l_3695;
	case 13978ULL: goto x86_l_369a;
	case 13983ULL: goto x86_l_369f;
	case 13988ULL: goto x86_l_36a4;
	case 13993ULL: goto x86_l_36a9;
	case 14000ULL: goto x86_l_36b0;
	case 14005ULL: goto x86_l_36b5;
	case 14007ULL: goto x86_l_36b7;
	case 14012ULL: goto x86_l_36bc;
	case 14016ULL: goto x86_l_36c0;
	case 14020ULL: goto x86_l_36c4;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3064:
	/* 0x3064: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3068:
	/* 0x3068: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_306b:
	/* 0x306b: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_3070:
	/* 0x3070: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3072:
	/* 0x3072: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3075:
	/* 0x3075: js     3716 <generic_usdt_process_event+0x3716> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14102ULL;
	}
x86_l_307b:
	/* 0x307b: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_3080:
	/* 0x3080: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_3083:
	/* 0x3083: jg     30a0 <generic_usdt_process_event+0x30a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_30a0;
	}
x86_l_3085:
	/* 0x3085: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3087:
	/* 0x3087: je     30be <generic_usdt_process_event+0x30be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30be;
	}
x86_l_3089:
	/* 0x3089: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_308c:
	/* 0x308c: je     30be <generic_usdt_process_event+0x30be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30be;
	}
x86_l_308e:
	/* 0x308e: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_3091:
	/* 0x3091: jne    30e4 <generic_usdt_process_event+0x30e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_30e4;
	}
x86_l_3093:
	/* 0x3093: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_309a:
	/* 0x309a: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_309e:
	/* 0x309e: jmp    30e9 <generic_usdt_process_event+0x30e9> */
	goto x86_l_30e9;
x86_l_30a0:
	/* 0x30a0: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_30a3:
	/* 0x30a3: je     30d1 <generic_usdt_process_event+0x30d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30d1;
	}
x86_l_30a5:
	/* 0x30a5: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_30a8:
	/* 0x30a8: je     30be <generic_usdt_process_event+0x30be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30be;
	}
x86_l_30aa:
	/* 0x30aa: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_30af:
	/* 0x30af: jne    30e4 <generic_usdt_process_event+0x30e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_30e4;
	}
x86_l_30b1:
	/* 0x30b1: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_30b8:
	/* 0x30b8: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_30bc:
	/* 0x30bc: jmp    30e9 <generic_usdt_process_event+0x30e9> */
	goto x86_l_30e9;
x86_l_30be:
	/* 0x30be: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_30c3:
	/* 0x30c3: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_30ca:
	/* 0x30ca: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_30cf:
	/* 0x30cf: jmp    30e9 <generic_usdt_process_event+0x30e9> */
	goto x86_l_30e9;
x86_l_30d1:
	/* 0x30d1: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_30d6:
	/* 0x30d6: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_30dd:
	/* 0x30dd: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_30e2:
	/* 0x30e2: jmp    30e9 <generic_usdt_process_event+0x30e9> */
	goto x86_l_30e9;
x86_l_30e4:
	/* 0x30e4: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_30e9:
	/* 0x30e9: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_30ed:
	/* 0x30ed: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30f1:
	/* 0x30f1: movzx  r13d,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_30f6:
	/* 0x30f6: cmp    r13,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 60ULL);
x86_l_30fa:
	/* 0x30fa: ja     3964 <generic_usdt_process_event+0x3964> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 14692ULL;
	}
x86_l_3100:
	/* 0x3100: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_310a:
	/* 0x310a: bt     rcx,r13 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_310e:
	/* 0x310e: jae    3964 <generic_usdt_process_event+0x3964> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 14692ULL;
	}
x86_l_3114:
	/* 0x3114: mov    BYTE PTR [r15+0x5],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_3118:
	/* 0x3118: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_311b:
	/* 0x311b: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3120:
	/* 0x3120: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3123:
	/* 0x3123: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3128:
	/* 0x3128: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_312d:
	/* 0x312d: mov    rdi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_3135:
	/* 0x3135: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3139:
	/* 0x3139: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_313c:
	/* 0x313c: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_3141:
	/* 0x3141: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3143:
	/* 0x3143: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3146:
	/* 0x3146: js     3716 <generic_usdt_process_event+0x3716> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14102ULL;
	}
x86_l_314c:
	/* 0x314c: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_3151:
	/* 0x3151: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_3154:
	/* 0x3154: jg     3178 <generic_usdt_process_event+0x3178> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3178;
	}
x86_l_3156:
	/* 0x3156: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3158:
	/* 0x3158: je     31a1 <generic_usdt_process_event+0x31a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31a1;
	}
x86_l_315a:
	/* 0x315a: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_315d:
	/* 0x315d: je     31a1 <generic_usdt_process_event+0x31a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31a1;
	}
x86_l_315f:
	/* 0x315f: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_3162:
	/* 0x3162: jne    3365 <generic_usdt_process_event+0x3365> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3365;
	}
x86_l_3168:
	/* 0x3168: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_316f:
	/* 0x316f: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_3173:
	/* 0x3173: jmp    336a <generic_usdt_process_event+0x336a> */
	goto x86_l_336a;
x86_l_3178:
	/* 0x3178: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_317b:
	/* 0x317b: je     3352 <generic_usdt_process_event+0x3352> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3352;
	}
x86_l_3181:
	/* 0x3181: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_3184:
	/* 0x3184: je     31a1 <generic_usdt_process_event+0x31a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31a1;
	}
x86_l_3186:
	/* 0x3186: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_318b:
	/* 0x318b: jne    3365 <generic_usdt_process_event+0x3365> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3365;
	}
x86_l_3191:
	/* 0x3191: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_3198:
	/* 0x3198: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_319c:
	/* 0x319c: jmp    336a <generic_usdt_process_event+0x336a> */
	goto x86_l_336a;
x86_l_31a1:
	/* 0x31a1: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_31a6:
	/* 0x31a6: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_31ad:
	/* 0x31ad: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_31b2:
	/* 0x31b2: jmp    336a <generic_usdt_process_event+0x336a> */
	goto x86_l_336a;
x86_l_31b7:
	/* 0x31b7: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31bb:
	/* 0x31bb: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31c0:
	/* 0x31c0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_31c5:
	/* 0x31c5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_31ca:
	/* 0x31ca: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31cf:
	/* 0x31cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31d1:
	/* 0x31d1: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_31d6:
	/* 0x31d6: cmp    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_31db:
	/* 0x31db: je     880 <generic_usdt_process_event+0x880> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2176ULL;
	}
x86_l_31e1:
	/* 0x31e1: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_31e5:
	/* 0x31e5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_31ea:
	/* 0x31ea: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_31ef:
	/* 0x31ef: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_31f4:
	/* 0x31f4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31f9:
	/* 0x31f9: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_31fc:
	/* 0x31fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31fe:
	/* 0x31fe: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3203:
	/* 0x3203: mov    QWORD PTR [rsp+0x60],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3208:
	/* 0x3208: lea    rdx,[r15+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_320c:
	/* 0x320c: mov    QWORD PTR [rsp+0x58],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3211:
	/* 0x3211: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3216:
	/* 0x3216: cmp    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_321b:
	/* 0x321b: jne    3228 <generic_usdt_process_event+0x3228> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3228;
	}
x86_l_321d:
	/* 0x321d: cmp    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_3222:
	/* 0x3222: je     880 <generic_usdt_process_event+0x880> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2176ULL;
	}
x86_l_3228:
	/* 0x3228: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_3230:
	/* 0x3230: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3235:
	/* 0x3235: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_323a:
	/* 0x323a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_323f:
	/* 0x323f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3241:
	/* 0x3241: cmp    r12,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 144ULL);
x86_l_3249:
	/* 0x3249: je     3509 <generic_usdt_process_event+0x3509> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3509;
	}
x86_l_324f:
	/* 0x324f: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3254:
	/* 0x3254: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3259:
	/* 0x3259: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_325e:
	/* 0x325e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3263:
	/* 0x3263: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3268:
	/* 0x3268: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_326b:
	/* 0x326b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_326d:
	/* 0x326d: cmp    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3272:
	/* 0x3272: je     3509 <generic_usdt_process_event+0x3509> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3509;
	}
x86_l_3278:
	/* 0x3278: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_327d:
	/* 0x327d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3282:
	/* 0x3282: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3287:
	/* 0x3287: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_328c:
	/* 0x328c: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_328f:
	/* 0x328f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3291:
	/* 0x3291: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_3295:
	/* 0x3295: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_329a:
	/* 0x329a: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_329f:
	/* 0x329f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_32a4:
	/* 0x32a4: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_32a9:
	/* 0x32a9: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_32ac:
	/* 0x32ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32ae:
	/* 0x32ae: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_32b3:
	/* 0x32b3: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_32b8:
	/* 0x32b8: mov    r12d,DWORD PTR [rsp+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_32bd:
	/* 0x32bd: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_32c0:
	/* 0x32c0: mov    r13d,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_32c5:
	/* 0x32c5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_32c7:
	/* 0x32c7: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_32ca:
	/* 0x32ca: sub    edx,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R13, X86_WIDTH_32, X86_ALU_SUB);
x86_l_32cd:
	/* 0x32cd: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_32d0:
	/* 0x32d0: add    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 128ULL);
x86_l_32d8:
	/* 0x32d8: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_32da:
	/* 0x32da: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_32dd:
	/* 0x32dd: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_32e1:
	/* 0x32e1: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_32e4:
	/* 0x32e4: cmovb  ecx,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_32e8:
	/* 0x32e8: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_32ea:
	/* 0x32ea: mov    edi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_32);
x86_l_32ed:
	/* 0x32ed: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_32ef:
	/* 0x32ef: mov    DWORD PTR [rsp+0x70],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_32f3:
	/* 0x32f3: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_32f6:
	/* 0x32f6: jb     885 <generic_usdt_process_event+0x885> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2181ULL;
	}
x86_l_32fc:
	/* 0x32fc: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_3302:
	/* 0x3302: ja     885 <generic_usdt_process_event+0x885> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2181ULL;
	}
x86_l_3308:
	/* 0x3308: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_330b:
	/* 0x330b: jbe    3312 <generic_usdt_process_event+0x3312> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3312;
	}
x86_l_330d:
	/* 0x330d: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_3312:
	/* 0x3312: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3314:
	/* 0x3314: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_3317:
	/* 0x3317: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_331b:
	/* 0x331b: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_331e:
	/* 0x331e: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3321:
	/* 0x3321: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3324:
	/* 0x3324: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3329:
	/* 0x3329: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_332b:
	/* 0x332b: mov    QWORD PTR [rsp+0x68],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3330:
	/* 0x3330: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_3333:
	/* 0x3333: jbe    885 <generic_usdt_process_event+0x885> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 2181ULL;
	}
x86_l_3339:
	/* 0x3339: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_333e:
	/* 0x333e: mov    QWORD PTR [rsp+0x50],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3343:
	/* 0x3343: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3348:
	/* 0x3348: mov    r15,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_334d:
	/* 0x334d: jmp    3568 <generic_usdt_process_event+0x3568> */
	goto x86_l_3568;
x86_l_3352:
	/* 0x3352: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_3357:
	/* 0x3357: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_335e:
	/* 0x335e: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_3363:
	/* 0x3363: jmp    336a <generic_usdt_process_event+0x336a> */
	goto x86_l_336a;
x86_l_3365:
	/* 0x3365: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_336a:
	/* 0x336a: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_336e:
	/* 0x336e: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3372:
	/* 0x3372: movzx  r13d,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_3377:
	/* 0x3377: cmp    r13,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 60ULL);
x86_l_337b:
	/* 0x337b: ja     3964 <generic_usdt_process_event+0x3964> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 14692ULL;
	}
x86_l_3381:
	/* 0x3381: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_338b:
	/* 0x338b: bt     rcx,r13 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_338f:
	/* 0x338f: jae    3964 <generic_usdt_process_event+0x3964> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 14692ULL;
	}
x86_l_3395:
	/* 0x3395: mov    BYTE PTR [r15+0x5],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_3399:
	/* 0x3399: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_339c:
	/* 0x339c: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_33a1:
	/* 0x33a1: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_33a4:
	/* 0x33a4: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_33a9:
	/* 0x33a9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_33ae:
	/* 0x33ae: mov    rdi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_33b6:
	/* 0x33b6: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_33ba:
	/* 0x33ba: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_33bd:
	/* 0x33bd: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_33c2:
	/* 0x33c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33c4:
	/* 0x33c4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_33c7:
	/* 0x33c7: js     3716 <generic_usdt_process_event+0x3716> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14102ULL;
	}
x86_l_33cd:
	/* 0x33cd: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_33d2:
	/* 0x33d2: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_33d5:
	/* 0x33d5: jg     33f2 <generic_usdt_process_event+0x33f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_33f2;
	}
x86_l_33d7:
	/* 0x33d7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_33d9:
	/* 0x33d9: je     3410 <generic_usdt_process_event+0x3410> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3410;
	}
x86_l_33db:
	/* 0x33db: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_33de:
	/* 0x33de: je     3410 <generic_usdt_process_event+0x3410> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3410;
	}
x86_l_33e0:
	/* 0x33e0: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_33e3:
	/* 0x33e3: jne    3436 <generic_usdt_process_event+0x3436> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3436;
	}
x86_l_33e5:
	/* 0x33e5: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_33ec:
	/* 0x33ec: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_33f0:
	/* 0x33f0: jmp    343b <generic_usdt_process_event+0x343b> */
	goto x86_l_343b;
x86_l_33f2:
	/* 0x33f2: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_33f5:
	/* 0x33f5: je     3423 <generic_usdt_process_event+0x3423> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3423;
	}
x86_l_33f7:
	/* 0x33f7: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_33fa:
	/* 0x33fa: je     3410 <generic_usdt_process_event+0x3410> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3410;
	}
x86_l_33fc:
	/* 0x33fc: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_3401:
	/* 0x3401: jne    3436 <generic_usdt_process_event+0x3436> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3436;
	}
x86_l_3403:
	/* 0x3403: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_340a:
	/* 0x340a: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_340e:
	/* 0x340e: jmp    343b <generic_usdt_process_event+0x343b> */
	goto x86_l_343b;
x86_l_3410:
	/* 0x3410: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_3415:
	/* 0x3415: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_341c:
	/* 0x341c: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_3421:
	/* 0x3421: jmp    343b <generic_usdt_process_event+0x343b> */
	goto x86_l_343b;
x86_l_3423:
	/* 0x3423: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_3428:
	/* 0x3428: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_342f:
	/* 0x342f: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_3434:
	/* 0x3434: jmp    343b <generic_usdt_process_event+0x343b> */
	goto x86_l_343b;
x86_l_3436:
	/* 0x3436: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_343b:
	/* 0x343b: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_343f:
	/* 0x343f: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3443:
	/* 0x3443: movzx  r13d,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_3448:
	/* 0x3448: cmp    r13,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 60ULL);
x86_l_344c:
	/* 0x344c: ja     3964 <generic_usdt_process_event+0x3964> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 14692ULL;
	}
x86_l_3452:
	/* 0x3452: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_345c:
	/* 0x345c: bt     rcx,r13 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_3460:
	/* 0x3460: jae    3964 <generic_usdt_process_event+0x3964> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 14692ULL;
	}
x86_l_3466:
	/* 0x3466: mov    BYTE PTR [r15+0x5],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_346a:
	/* 0x346a: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_346d:
	/* 0x346d: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3472:
	/* 0x3472: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3475:
	/* 0x3475: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_347a:
	/* 0x347a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_347f:
	/* 0x347f: mov    rdi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_3487:
	/* 0x3487: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_348b:
	/* 0x348b: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_348e:
	/* 0x348e: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_3493:
	/* 0x3493: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3495:
	/* 0x3495: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3498:
	/* 0x3498: js     3716 <generic_usdt_process_event+0x3716> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14102ULL;
	}
x86_l_349e:
	/* 0x349e: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_34a3:
	/* 0x34a3: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_34a6:
	/* 0x34a6: jg     34ca <generic_usdt_process_event+0x34ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_34ca;
	}
x86_l_34a8:
	/* 0x34a8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_34aa:
	/* 0x34aa: je     34f3 <generic_usdt_process_event+0x34f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_34f3;
	}
x86_l_34ac:
	/* 0x34ac: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_34af:
	/* 0x34af: je     34f3 <generic_usdt_process_event+0x34f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_34f3;
	}
x86_l_34b1:
	/* 0x34b1: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_34b4:
	/* 0x34b4: jne    36b7 <generic_usdt_process_event+0x36b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_36b7;
	}
x86_l_34ba:
	/* 0x34ba: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_34c1:
	/* 0x34c1: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_34c5:
	/* 0x34c5: jmp    36bc <generic_usdt_process_event+0x36bc> */
	goto x86_l_36bc;
x86_l_34ca:
	/* 0x34ca: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_34cd:
	/* 0x34cd: je     36a4 <generic_usdt_process_event+0x36a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36a4;
	}
x86_l_34d3:
	/* 0x34d3: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_34d6:
	/* 0x34d6: je     34f3 <generic_usdt_process_event+0x34f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_34f3;
	}
x86_l_34d8:
	/* 0x34d8: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_34dd:
	/* 0x34dd: jne    36b7 <generic_usdt_process_event+0x36b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_36b7;
	}
x86_l_34e3:
	/* 0x34e3: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_34ea:
	/* 0x34ea: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_34ee:
	/* 0x34ee: jmp    36bc <generic_usdt_process_event+0x36bc> */
	goto x86_l_36bc;
x86_l_34f3:
	/* 0x34f3: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_34f8:
	/* 0x34f8: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_34ff:
	/* 0x34ff: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_3504:
	/* 0x3504: jmp    36bc <generic_usdt_process_event+0x36bc> */
	goto x86_l_36bc;
x86_l_3509:
	/* 0x3509: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_350d:
	/* 0x350d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3512:
	/* 0x3512: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3517:
	/* 0x3517: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_351c:
	/* 0x351c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3521:
	/* 0x3521: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3523:
	/* 0x3523: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3528:
	/* 0x3528: cmp    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_352d:
	/* 0x352d: je     880 <generic_usdt_process_event+0x880> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2176ULL;
	}
x86_l_3533:
	/* 0x3533: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_3537:
	/* 0x3537: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_353c:
	/* 0x353c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3541:
	/* 0x3541: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3546:
	/* 0x3546: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_354b:
	/* 0x354b: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_354e:
	/* 0x354e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3550:
	/* 0x3550: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3555:
	/* 0x3555: mov    QWORD PTR [rsp+0x60],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_355a:
	/* 0x355a: lea    rdx,[r15+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_355e:
	/* 0x355e: mov    QWORD PTR [rsp+0x58],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3563:
	/* 0x3563: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3568:
	/* 0x3568: cmp    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_356d:
	/* 0x356d: jne    357a <generic_usdt_process_event+0x357a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_357a;
	}
x86_l_356f:
	/* 0x356f: cmp    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_3574:
	/* 0x3574: je     880 <generic_usdt_process_event+0x880> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2176ULL;
	}
x86_l_357a:
	/* 0x357a: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_3582:
	/* 0x3582: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3587:
	/* 0x3587: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_358c:
	/* 0x358c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3591:
	/* 0x3591: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3593:
	/* 0x3593: cmp    r12,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 144ULL);
x86_l_359b:
	/* 0x359b: je     3971 <generic_usdt_process_event+0x3971> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14705ULL;
	}
x86_l_35a1:
	/* 0x35a1: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_35a6:
	/* 0x35a6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35ab:
	/* 0x35ab: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_35b0:
	/* 0x35b0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_35b5:
	/* 0x35b5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_35ba:
	/* 0x35ba: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_35bd:
	/* 0x35bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35bf:
	/* 0x35bf: cmp    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35c4:
	/* 0x35c4: je     3971 <generic_usdt_process_event+0x3971> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14705ULL;
	}
x86_l_35ca:
	/* 0x35ca: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_35cf:
	/* 0x35cf: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_35d4:
	/* 0x35d4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_35d9:
	/* 0x35d9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_35de:
	/* 0x35de: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_35e1:
	/* 0x35e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35e3:
	/* 0x35e3: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_35e7:
	/* 0x35e7: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_35ec:
	/* 0x35ec: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_35f1:
	/* 0x35f1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_35f6:
	/* 0x35f6: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_35fb:
	/* 0x35fb: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_35fe:
	/* 0x35fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3600:
	/* 0x3600: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3605:
	/* 0x3605: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_360a:
	/* 0x360a: mov    r12d,DWORD PTR [rsp+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_360f:
	/* 0x360f: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3612:
	/* 0x3612: mov    r13d,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3617:
	/* 0x3617: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3619:
	/* 0x3619: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_361c:
	/* 0x361c: sub    edx,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R13, X86_WIDTH_32, X86_ALU_SUB);
x86_l_361f:
	/* 0x361f: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_3622:
	/* 0x3622: add    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 128ULL);
x86_l_362a:
	/* 0x362a: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_362c:
	/* 0x362c: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_362f:
	/* 0x362f: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_3633:
	/* 0x3633: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_3636:
	/* 0x3636: cmovb  ecx,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_363a:
	/* 0x363a: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_363c:
	/* 0x363c: mov    edi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_32);
x86_l_363f:
	/* 0x363f: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3641:
	/* 0x3641: mov    DWORD PTR [rsp+0x70],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3645:
	/* 0x3645: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3648:
	/* 0x3648: jb     885 <generic_usdt_process_event+0x885> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2181ULL;
	}
x86_l_364e:
	/* 0x364e: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_3654:
	/* 0x3654: ja     885 <generic_usdt_process_event+0x885> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2181ULL;
	}
x86_l_365a:
	/* 0x365a: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_365d:
	/* 0x365d: jbe    3664 <generic_usdt_process_event+0x3664> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3664;
	}
x86_l_365f:
	/* 0x365f: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_3664:
	/* 0x3664: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3666:
	/* 0x3666: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_3669:
	/* 0x3669: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_366d:
	/* 0x366d: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3670:
	/* 0x3670: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3673:
	/* 0x3673: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3676:
	/* 0x3676: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_367b:
	/* 0x367b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_367d:
	/* 0x367d: mov    QWORD PTR [rsp+0x68],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3682:
	/* 0x3682: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_3685:
	/* 0x3685: jbe    885 <generic_usdt_process_event+0x885> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 2181ULL;
	}
x86_l_368b:
	/* 0x368b: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3690:
	/* 0x3690: mov    QWORD PTR [rsp+0x50],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3695:
	/* 0x3695: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_369a:
	/* 0x369a: mov    r15,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_369f:
	/* 0x369f: jmp    39d0 <generic_usdt_process_event+0x39d0> */
	return 14800ULL;
x86_l_36a4:
	/* 0x36a4: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_36a9:
	/* 0x36a9: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_36b0:
	/* 0x36b0: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_36b5:
	/* 0x36b5: jmp    36bc <generic_usdt_process_event+0x36bc> */
	goto x86_l_36bc;
x86_l_36b7:
	/* 0x36b7: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_36bc:
	/* 0x36bc: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_36c0:
	/* 0x36c0: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36c4:
	/* 0x36c4: movzx  r13d,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
	return 14025ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_generic_usdt_process_event_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 14025ULL: goto x86_l_36c9;
	case 14029ULL: goto x86_l_36cd;
	case 14035ULL: goto x86_l_36d3;
	case 14045ULL: goto x86_l_36dd;
	case 14049ULL: goto x86_l_36e1;
	case 14055ULL: goto x86_l_36e7;
	case 14059ULL: goto x86_l_36eb;
	case 14062ULL: goto x86_l_36ee;
	case 14067ULL: goto x86_l_36f3;
	case 14070ULL: goto x86_l_36f6;
	case 14075ULL: goto x86_l_36fb;
	case 14080ULL: goto x86_l_3700;
	case 14088ULL: goto x86_l_3708;
	case 14092ULL: goto x86_l_370c;
	case 14095ULL: goto x86_l_370f;
	case 14100ULL: goto x86_l_3714;
	case 14102ULL: goto x86_l_3716;
	case 14105ULL: goto x86_l_3719;
	case 14113ULL: goto x86_l_3721;
	case 14117ULL: goto x86_l_3725;
	case 14122ULL: goto x86_l_372a;
	case 14127ULL: goto x86_l_372f;
	case 14134ULL: goto x86_l_3736;
	case 14139ULL: goto x86_l_373b;
	case 14144ULL: goto x86_l_3740;
	case 14149ULL: goto x86_l_3745;
	case 14152ULL: goto x86_l_3748;
	case 14157ULL: goto x86_l_374d;
	case 14159ULL: goto x86_l_374f;
	case 14163ULL: goto x86_l_3753;
	case 14167ULL: goto x86_l_3757;
	case 14172ULL: goto x86_l_375c;
	case 14177ULL: goto x86_l_3761;
	case 14182ULL: goto x86_l_3766;
	case 14185ULL: goto x86_l_3769;
	case 14187ULL: goto x86_l_376b;
	case 14191ULL: goto x86_l_376f;
	case 14193ULL: goto x86_l_3771;
	case 14197ULL: goto x86_l_3775;
	case 14200ULL: goto x86_l_3778;
	case 14206ULL: goto x86_l_377e;
	case 14211ULL: goto x86_l_3783;
	case 14220ULL: goto x86_l_378c;
	case 14224ULL: goto x86_l_3790;
	case 14229ULL: goto x86_l_3795;
	case 14234ULL: goto x86_l_379a;
	case 14239ULL: goto x86_l_379f;
	case 14244ULL: goto x86_l_37a4;
	case 14249ULL: goto x86_l_37a9;
	case 14251ULL: goto x86_l_37ab;
	case 14256ULL: goto x86_l_37b0;
	case 14260ULL: goto x86_l_37b4;
	case 14264ULL: goto x86_l_37b8;
	case 14269ULL: goto x86_l_37bd;
	case 14274ULL: goto x86_l_37c2;
	case 14276ULL: goto x86_l_37c4;
	case 14281ULL: goto x86_l_37c9;
	case 14290ULL: goto x86_l_37d2;
	case 14294ULL: goto x86_l_37d6;
	case 14299ULL: goto x86_l_37db;
	case 14304ULL: goto x86_l_37e0;
	case 14309ULL: goto x86_l_37e5;
	case 14314ULL: goto x86_l_37ea;
	case 14319ULL: goto x86_l_37ef;
	case 14321ULL: goto x86_l_37f1;
	case 14326ULL: goto x86_l_37f6;
	case 14330ULL: goto x86_l_37fa;
	case 14334ULL: goto x86_l_37fe;
	case 14339ULL: goto x86_l_3803;
	case 14344ULL: goto x86_l_3808;
	case 14349ULL: goto x86_l_380d;
	case 14351ULL: goto x86_l_380f;
	case 14353ULL: goto x86_l_3811;
	case 14358ULL: goto x86_l_3816;
	case 14367ULL: goto x86_l_381f;
	case 14373ULL: goto x86_l_3825;
	case 14379ULL: goto x86_l_382b;
	case 14387ULL: goto x86_l_3833;
	case 14395ULL: goto x86_l_383b;
	case 14403ULL: goto x86_l_3843;
	case 14410ULL: goto x86_l_384a;
	case 14415ULL: goto x86_l_384f;
	case 14420ULL: goto x86_l_3854;
	case 14425ULL: goto x86_l_3859;
	case 14430ULL: goto x86_l_385e;
	case 14432ULL: goto x86_l_3860;
	case 14437ULL: goto x86_l_3865;
	case 14440ULL: goto x86_l_3868;
	case 14442ULL: goto x86_l_386a;
	case 14446ULL: goto x86_l_386e;
	case 14451ULL: goto x86_l_3873;
	case 14456ULL: goto x86_l_3878;
	case 14461ULL: goto x86_l_387d;
	case 14466ULL: goto x86_l_3882;
	case 14470ULL: goto x86_l_3886;
	case 14475ULL: goto x86_l_388b;
	case 14477ULL: goto x86_l_388d;
	case 14482ULL: goto x86_l_3892;
	case 14487ULL: goto x86_l_3897;
	case 14491ULL: goto x86_l_389b;
	case 14496ULL: goto x86_l_38a0;
	case 14500ULL: goto x86_l_38a4;
	case 14505ULL: goto x86_l_38a9;
	case 14510ULL: goto x86_l_38ae;
	case 14515ULL: goto x86_l_38b3;
	case 14517ULL: goto x86_l_38b5;
	case 14521ULL: goto x86_l_38b9;
	case 14525ULL: goto x86_l_38bd;
	case 14529ULL: goto x86_l_38c1;
	case 14534ULL: goto x86_l_38c6;
	case 14539ULL: goto x86_l_38cb;
	case 14542ULL: goto x86_l_38ce;
	case 14547ULL: goto x86_l_38d3;
	case 14549ULL: goto x86_l_38d5;
	case 14554ULL: goto x86_l_38da;
	case 14559ULL: goto x86_l_38df;
	case 14564ULL: goto x86_l_38e4;
	case 14572ULL: goto x86_l_38ec;
	case 14574ULL: goto x86_l_38ee;
	case 14576ULL: goto x86_l_38f0;
	case 14582ULL: goto x86_l_38f6;
	case 14585ULL: goto x86_l_38f9;
	case 14587ULL: goto x86_l_38fb;
	case 14589ULL: goto x86_l_38fd;
	case 14597ULL: goto x86_l_3905;
	case 14608ULL: goto x86_l_3910;
	case 14619ULL: goto x86_l_391b;
	case 14621ULL: goto x86_l_391d;
	case 14623ULL: goto x86_l_391f;
	case 14627ULL: goto x86_l_3923;
	case 14631ULL: goto x86_l_3927;
	case 14637ULL: goto x86_l_392d;
	case 14648ULL: goto x86_l_3938;
	case 14655ULL: goto x86_l_393f;
	case 14660ULL: goto x86_l_3944;
	case 14665ULL: goto x86_l_3949;
	case 14668ULL: goto x86_l_394c;
	case 14673ULL: goto x86_l_3951;
	case 14675ULL: goto x86_l_3953;
	case 14677ULL: goto x86_l_3955;
	case 14684ULL: goto x86_l_395c;
	case 14686ULL: goto x86_l_395e;
	case 14687ULL: goto x86_l_395f;
	case 14692ULL: goto x86_l_3964;
	case 14700ULL: goto x86_l_396c;
	case 14705ULL: goto x86_l_3971;
	case 14709ULL: goto x86_l_3975;
	case 14714ULL: goto x86_l_397a;
	case 14719ULL: goto x86_l_397f;
	case 14724ULL: goto x86_l_3984;
	case 14729ULL: goto x86_l_3989;
	case 14731ULL: goto x86_l_398b;
	case 14736ULL: goto x86_l_3990;
	case 14741ULL: goto x86_l_3995;
	case 14747ULL: goto x86_l_399b;
	case 14751ULL: goto x86_l_399f;
	case 14756ULL: goto x86_l_39a4;
	case 14761ULL: goto x86_l_39a9;
	case 14766ULL: goto x86_l_39ae;
	case 14771ULL: goto x86_l_39b3;
	case 14774ULL: goto x86_l_39b6;
	case 14776ULL: goto x86_l_39b8;
	case 14781ULL: goto x86_l_39bd;
	case 14786ULL: goto x86_l_39c2;
	case 14790ULL: goto x86_l_39c6;
	case 14795ULL: goto x86_l_39cb;
	case 14800ULL: goto x86_l_39d0;
	case 14805ULL: goto x86_l_39d5;
	case 14807ULL: goto x86_l_39d7;
	case 14812ULL: goto x86_l_39dc;
	case 14818ULL: goto x86_l_39e2;
	case 14826ULL: goto x86_l_39ea;
	case 14831ULL: goto x86_l_39ef;
	case 14836ULL: goto x86_l_39f4;
	case 14841ULL: goto x86_l_39f9;
	case 14843ULL: goto x86_l_39fb;
	case 14851ULL: goto x86_l_3a03;
	case 14857ULL: goto x86_l_3a09;
	case 14862ULL: goto x86_l_3a0e;
	case 14867ULL: goto x86_l_3a13;
	case 14872ULL: goto x86_l_3a18;
	case 14877ULL: goto x86_l_3a1d;
	case 14882ULL: goto x86_l_3a22;
	case 14885ULL: goto x86_l_3a25;
	case 14887ULL: goto x86_l_3a27;
	case 14892ULL: goto x86_l_3a2c;
	case 14898ULL: goto x86_l_3a32;
	case 14903ULL: goto x86_l_3a37;
	case 14908ULL: goto x86_l_3a3c;
	case 14913ULL: goto x86_l_3a41;
	case 14918ULL: goto x86_l_3a46;
	case 14921ULL: goto x86_l_3a49;
	case 14923ULL: goto x86_l_3a4b;
	case 14927ULL: goto x86_l_3a4f;
	case 14932ULL: goto x86_l_3a54;
	case 14937ULL: goto x86_l_3a59;
	case 14942ULL: goto x86_l_3a5e;
	case 14947ULL: goto x86_l_3a63;
	case 14950ULL: goto x86_l_3a66;
	case 14952ULL: goto x86_l_3a68;
	case 14957ULL: goto x86_l_3a6d;
	case 14962ULL: goto x86_l_3a72;
	case 14967ULL: goto x86_l_3a77;
	case 14970ULL: goto x86_l_3a7a;
	case 14975ULL: goto x86_l_3a7f;
	case 14977ULL: goto x86_l_3a81;
	case 14980ULL: goto x86_l_3a84;
	case 14983ULL: goto x86_l_3a87;
	case 14986ULL: goto x86_l_3a8a;
	case 14994ULL: goto x86_l_3a92;
	case 14996ULL: goto x86_l_3a94;
	case 14999ULL: goto x86_l_3a97;
	case 15003ULL: goto x86_l_3a9b;
	case 15006ULL: goto x86_l_3a9e;
	case 15010ULL: goto x86_l_3aa2;
	case 15012ULL: goto x86_l_3aa4;
	case 15015ULL: goto x86_l_3aa7;
	case 15017ULL: goto x86_l_3aa9;
	case 15021ULL: goto x86_l_3aad;
	case 15024ULL: goto x86_l_3ab0;
	case 15030ULL: goto x86_l_3ab6;
	case 15036ULL: goto x86_l_3abc;
	case 15042ULL: goto x86_l_3ac2;
	case 15045ULL: goto x86_l_3ac5;
	case 15047ULL: goto x86_l_3ac7;
	case 15052ULL: goto x86_l_3acc;
	case 15054ULL: goto x86_l_3ace;
	case 15057ULL: goto x86_l_3ad1;
	case 15061ULL: goto x86_l_3ad5;
	case 15064ULL: goto x86_l_3ad8;
	case 15067ULL: goto x86_l_3adb;
	case 15070ULL: goto x86_l_3ade;
	case 15075ULL: goto x86_l_3ae3;
	case 15077ULL: goto x86_l_3ae5;
	case 15082ULL: goto x86_l_3aea;
	case 15085ULL: goto x86_l_3aed;
	case 15091ULL: goto x86_l_3af3;
	case 15096ULL: goto x86_l_3af8;
	case 15101ULL: goto x86_l_3afd;
	case 15106ULL: goto x86_l_3b02;
	case 15111ULL: goto x86_l_3b07;
	case 15113ULL: goto x86_l_3b09;
	case 15117ULL: goto x86_l_3b0d;
	case 15122ULL: goto x86_l_3b12;
	case 15127ULL: goto x86_l_3b17;
	case 15132ULL: goto x86_l_3b1c;
	case 15137ULL: goto x86_l_3b21;
	case 15139ULL: goto x86_l_3b23;
	case 15144ULL: goto x86_l_3b28;
	case 15149ULL: goto x86_l_3b2d;
	case 15155ULL: goto x86_l_3b33;
	case 15159ULL: goto x86_l_3b37;
	case 15164ULL: goto x86_l_3b3c;
	case 15169ULL: goto x86_l_3b41;
	case 15174ULL: goto x86_l_3b46;
	case 15179ULL: goto x86_l_3b4b;
	case 15182ULL: goto x86_l_3b4e;
	case 15184ULL: goto x86_l_3b50;
	case 15189ULL: goto x86_l_3b55;
	case 15194ULL: goto x86_l_3b5a;
	case 15198ULL: goto x86_l_3b5e;
	case 15203ULL: goto x86_l_3b63;
	case 15208ULL: goto x86_l_3b68;
	case 15213ULL: goto x86_l_3b6d;
	case 15215ULL: goto x86_l_3b6f;
	case 15220ULL: goto x86_l_3b74;
	case 15226ULL: goto x86_l_3b7a;
	case 15234ULL: goto x86_l_3b82;
	case 15239ULL: goto x86_l_3b87;
	case 15244ULL: goto x86_l_3b8c;
	case 15249ULL: goto x86_l_3b91;
	case 15251ULL: goto x86_l_3b93;
	case 15259ULL: goto x86_l_3b9b;
	case 15265ULL: goto x86_l_3ba1;
	case 15270ULL: goto x86_l_3ba6;
	case 15275ULL: goto x86_l_3bab;
	case 15280ULL: goto x86_l_3bb0;
	case 15285ULL: goto x86_l_3bb5;
	case 15290ULL: goto x86_l_3bba;
	case 15293ULL: goto x86_l_3bbd;
	case 15295ULL: goto x86_l_3bbf;
	case 15300ULL: goto x86_l_3bc4;
	case 15306ULL: goto x86_l_3bca;
	case 15311ULL: goto x86_l_3bcf;
	case 15316ULL: goto x86_l_3bd4;
	case 15321ULL: goto x86_l_3bd9;
	case 15326ULL: goto x86_l_3bde;
	case 15329ULL: goto x86_l_3be1;
	case 15331ULL: goto x86_l_3be3;
	case 15335ULL: goto x86_l_3be7;
	case 15340ULL: goto x86_l_3bec;
	case 15345ULL: goto x86_l_3bf1;
	case 15350ULL: goto x86_l_3bf6;
	case 15355ULL: goto x86_l_3bfb;
	case 15358ULL: goto x86_l_3bfe;
	case 15360ULL: goto x86_l_3c00;
	case 15365ULL: goto x86_l_3c05;
	case 15370ULL: goto x86_l_3c0a;
	case 15375ULL: goto x86_l_3c0f;
	case 15378ULL: goto x86_l_3c12;
	case 15383ULL: goto x86_l_3c17;
	case 15385ULL: goto x86_l_3c19;
	case 15388ULL: goto x86_l_3c1c;
	case 15391ULL: goto x86_l_3c1f;
	case 15394ULL: goto x86_l_3c22;
	case 15402ULL: goto x86_l_3c2a;
	case 15404ULL: goto x86_l_3c2c;
	case 15407ULL: goto x86_l_3c2f;
	case 15411ULL: goto x86_l_3c33;
	case 15414ULL: goto x86_l_3c36;
	case 15418ULL: goto x86_l_3c3a;
	case 15420ULL: goto x86_l_3c3c;
	case 15423ULL: goto x86_l_3c3f;
	case 15425ULL: goto x86_l_3c41;
	case 15429ULL: goto x86_l_3c45;
	case 15432ULL: goto x86_l_3c48;
	case 15438ULL: goto x86_l_3c4e;
	case 15444ULL: goto x86_l_3c54;
	case 15450ULL: goto x86_l_3c5a;
	case 15453ULL: goto x86_l_3c5d;
	case 15455ULL: goto x86_l_3c5f;
	case 15460ULL: goto x86_l_3c64;
	case 15462ULL: goto x86_l_3c66;
	case 15465ULL: goto x86_l_3c69;
	case 15469ULL: goto x86_l_3c6d;
	case 15472ULL: goto x86_l_3c70;
	case 15475ULL: goto x86_l_3c73;
	case 15478ULL: goto x86_l_3c76;
	case 15483ULL: goto x86_l_3c7b;
	case 15485ULL: goto x86_l_3c7d;
	case 15490ULL: goto x86_l_3c82;
	case 15493ULL: goto x86_l_3c85;
	case 15499ULL: goto x86_l_3c8b;
	case 15504ULL: goto x86_l_3c90;
	case 15509ULL: goto x86_l_3c95;
	case 15514ULL: goto x86_l_3c9a;
	case 15518ULL: goto x86_l_3c9e;
	case 15523ULL: goto x86_l_3ca3;
	case 15528ULL: goto x86_l_3ca8;
	case 15533ULL: goto x86_l_3cad;
	case 15538ULL: goto x86_l_3cb2;
	case 15540ULL: goto x86_l_3cb4;
	case 15545ULL: goto x86_l_3cb9;
	case 15550ULL: goto x86_l_3cbe;
	case 15556ULL: goto x86_l_3cc4;
	case 15560ULL: goto x86_l_3cc8;
	case 15565ULL: goto x86_l_3ccd;
	case 15570ULL: goto x86_l_3cd2;
	case 15575ULL: goto x86_l_3cd7;
	case 15580ULL: goto x86_l_3cdc;
	case 15583ULL: goto x86_l_3cdf;
	case 15585ULL: goto x86_l_3ce1;
	default: return 0xffffffffffffffffULL;
	}
x86_l_36c9:
	/* 0x36c9: cmp    r13,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 60ULL);
x86_l_36cd:
	/* 0x36cd: ja     3964 <generic_usdt_process_event+0x3964> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3964;
	}
x86_l_36d3:
	/* 0x36d3: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_36dd:
	/* 0x36dd: bt     rcx,r13 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_36e1:
	/* 0x36e1: jae    3964 <generic_usdt_process_event+0x3964> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_3964;
	}
x86_l_36e7:
	/* 0x36e7: mov    BYTE PTR [r15+0x5],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_36eb:
	/* 0x36eb: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_36ee:
	/* 0x36ee: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_36f3:
	/* 0x36f3: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_36f6:
	/* 0x36f6: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_36fb:
	/* 0x36fb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3700:
	/* 0x3700: mov    rdi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_3708:
	/* 0x3708: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_370c:
	/* 0x370c: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_370f:
	/* 0x370f: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_3714:
	/* 0x3714: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3716:
	/* 0x3716: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3719:
	/* 0x3719: mov    BYTE PTR [rsp+0xa4],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_3721:
	/* 0x3721: movzx  eax,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3725:
	/* 0x3725: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_372a:
	/* 0x372a: mov    WORD PTR [r15+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_372f:
	/* 0x372f: mov    WORD PTR [r15+0x26],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757258ULL);
x86_l_3736:
	/* 0x3736: lea    rdx,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_373b:
	/* 0x373b: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3740:
	/* 0x3740: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3745:
	/* 0x3745: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_3748:
	/* 0x3748: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_374d:
	/* 0x374d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_374f:
	/* 0x374f: lea    rdi,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3753:
	/* 0x3753: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_3757:
	/* 0x3757: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_375c:
	/* 0x375c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3761:
	/* 0x3761: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3766:
	/* 0x3766: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3769:
	/* 0x3769: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_376b:
	/* 0x376b: cmp    r13b,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 17ULL);
x86_l_376f:
	/* 0x376f: je     37c4 <generic_usdt_process_event+0x37c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37c4;
	}
x86_l_3771:
	/* 0x3771: movzx  eax,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3775:
	/* 0x3775: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_3778:
	/* 0x3778: jne    3811 <generic_usdt_process_event+0x3811> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3811;
	}
x86_l_377e:
	/* 0x377e: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3783:
	/* 0x3783: movzx  r13d,WORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 176ULL);
x86_l_378c:
	/* 0x378c: lea    rdx,[r15+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_3790:
	/* 0x3790: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3795:
	/* 0x3795: lea    rdi,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_379a:
	/* 0x379a: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_379f:
	/* 0x379f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_37a4:
	/* 0x37a4: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_37a9:
	/* 0x37a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37ab:
	/* 0x37ab: lea    rdi,[r12+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_37b0:
	/* 0x37b0: lea    rdx,[r15+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_37b4:
	/* 0x37b4: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_37b8:
	/* 0x37b8: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_37bd:
	/* 0x37bd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_37c2:
	/* 0x37c2: jmp    3808 <generic_usdt_process_event+0x3808> */
	goto x86_l_3808;
x86_l_37c4:
	/* 0x37c4: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_37c9:
	/* 0x37c9: movzx  r13d,WORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 176ULL);
x86_l_37d2:
	/* 0x37d2: lea    rdx,[r15+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_37d6:
	/* 0x37d6: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_37db:
	/* 0x37db: lea    rdi,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_37e0:
	/* 0x37e0: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_37e5:
	/* 0x37e5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_37ea:
	/* 0x37ea: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_37ef:
	/* 0x37ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37f1:
	/* 0x37f1: lea    rdi,[r12+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_37f6:
	/* 0x37f6: lea    rdx,[r15+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_37fa:
	/* 0x37fa: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_37fe:
	/* 0x37fe: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_3803:
	/* 0x3803: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3808:
	/* 0x3808: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_380d:
	/* 0x380d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_380f:
	/* 0x380f: jmp    381f <generic_usdt_process_event+0x381f> */
	goto x86_l_381f;
x86_l_3811:
	/* 0x3811: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3816:
	/* 0x3816: mov    DWORD PTR [r12+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_381f:
	/* 0x381f: movzx  eax,WORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_3825:
	/* 0x3825: movzx  ecx,WORD PTR [r12+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_382b:
	/* 0x382b: movbe  WORD PTR [r12+0x20],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_3833:
	/* 0x3833: movbe  WORD PTR [r12+0x22],cx */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_R12, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_383b:
	/* 0x383b: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_3843:
	/* 0x3843: add    rdx,0xe0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 224ULL);
x86_l_384a:
	/* 0x384a: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_384f:
	/* 0x384f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3854:
	/* 0x3854: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3859:
	/* 0x3859: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_385e:
	/* 0x385e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3860:
	/* 0x3860: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3865:
	/* 0x3865: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_3868:
	/* 0x3868: je     38d5 <generic_usdt_process_event+0x38d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38d5;
	}
x86_l_386a:
	/* 0x386a: add    rcx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 5ULL);
x86_l_386e:
	/* 0x386e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3873:
	/* 0x3873: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3878:
	/* 0x3878: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_387d:
	/* 0x387d: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3882:
	/* 0x3882: add    rdx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 5ULL);
x86_l_3886:
	/* 0x3886: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_388b:
	/* 0x388b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_388d:
	/* 0x388d: mov    r12,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3892:
	/* 0x3892: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3897:
	/* 0x3897: lea    rdx,[r12+r13*8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 3), 0ULL);
x86_l_389b:
	/* 0x389b: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_38a0:
	/* 0x38a0: lea    rdi,[r15+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_38a4:
	/* 0x38a4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_38a9:
	/* 0x38a9: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_38ae:
	/* 0x38ae: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_38b3:
	/* 0x38b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38b5:
	/* 0x38b5: add    r15,0x3c */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 60ULL);
x86_l_38b9:
	/* 0x38b9: lea    rdx,[r12+r13*8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 3), 0ULL);
x86_l_38bd:
	/* 0x38bd: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_38c1:
	/* 0x38c1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_38c6:
	/* 0x38c6: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_38cb:
	/* 0x38cb: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_38ce:
	/* 0x38ce: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_38d3:
	/* 0x38d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38d5:
	/* 0x38d5: mov    esi,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 64ULL);
x86_l_38da:
	/* 0x38da: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_38df:
	/* 0x38df: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_38e4:
	/* 0x38e4: mov    r13,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_38ec:
	/* 0x38ec: test   esi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_32);
x86_l_38ee:
	/* 0x38ee: js     38fd <generic_usdt_process_event+0x38fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_38fd;
	}
x86_l_38f0:
	/* 0x38f0: and    esi,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_38f6:
	/* 0x38f6: add    esi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_38f9:
	/* 0x38f9: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_38fb:
	/* 0x38fb: jmp    391b <generic_usdt_process_event+0x391b> */
	goto x86_l_391b;
x86_l_38fd:
	/* 0x38fd: mov    rcx,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_3905:
	/* 0x3905: mov    DWORD PTR [rax+rcx*4+0x5ea0],0xffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 104045582745599ULL);
x86_l_3910:
	/* 0x3910: mov    DWORD PTR [rax+rbp*1+0x90],0xffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 622770257919ULL);
x86_l_391b:
	/* 0x391b: add    edx,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_391d:
	/* 0x391d: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_391f:
	/* 0x391f: mov    DWORD PTR [r14+0x4],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3923:
	/* 0x3923: cmp    r13d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 3ULL);
x86_l_3927:
	/* 0x3927: jle    3a3 <generic_usdt_process_event+0x3a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 931ULL;
	}
x86_l_392d:
	/* 0x392d: mov    DWORD PTR [r14+0x5eec],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104367705292800ULL);
x86_l_3938:
	/* 0x3938: mov    rsi,QWORD PTR [rip+0x9db] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&usdt_calls)));
x86_l_393f:
	/* 0x393f: mov    ecx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_3944:
	/* 0x3944: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_3949:
	/* 0x3949: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_394c:
	/* 0x394c: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_3951:
	/* 0x3951: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3953:
	/* 0x3953: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3955:
	/* 0x3955: add    rsp,0xf8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 248ULL);
x86_l_395c:
	/* 0x395c: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_395e:
	/* 0x395e: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_395f:
	/* 0x395f: jmp    3ce6 <generic_usdt_process_event+0x3ce6> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_3964:
	/* 0x3964: mov    WORD PTR [rsp+0xb0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_396c:
	/* 0x396c: jmp    3719 <generic_usdt_process_event+0x3719> */
	goto x86_l_3719;
x86_l_3971:
	/* 0x3971: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3975:
	/* 0x3975: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_397a:
	/* 0x397a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_397f:
	/* 0x397f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3984:
	/* 0x3984: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3989:
	/* 0x3989: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_398b:
	/* 0x398b: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3990:
	/* 0x3990: cmp    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_3995:
	/* 0x3995: je     880 <generic_usdt_process_event+0x880> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2176ULL;
	}
x86_l_399b:
	/* 0x399b: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_399f:
	/* 0x399f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_39a4:
	/* 0x39a4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_39a9:
	/* 0x39a9: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_39ae:
	/* 0x39ae: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_39b3:
	/* 0x39b3: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_39b6:
	/* 0x39b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39b8:
	/* 0x39b8: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39bd:
	/* 0x39bd: mov    QWORD PTR [rsp+0x60],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_39c2:
	/* 0x39c2: lea    rdx,[r15+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_39c6:
	/* 0x39c6: mov    QWORD PTR [rsp+0x58],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_39cb:
	/* 0x39cb: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_39d0:
	/* 0x39d0: cmp    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_39d5:
	/* 0x39d5: jne    39e2 <generic_usdt_process_event+0x39e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_39e2;
	}
x86_l_39d7:
	/* 0x39d7: cmp    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_39dc:
	/* 0x39dc: je     880 <generic_usdt_process_event+0x880> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2176ULL;
	}
x86_l_39e2:
	/* 0x39e2: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_39ea:
	/* 0x39ea: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_39ef:
	/* 0x39ef: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_39f4:
	/* 0x39f4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_39f9:
	/* 0x39f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39fb:
	/* 0x39fb: cmp    r12,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 144ULL);
x86_l_3a03:
	/* 0x3a03: je     3b09 <generic_usdt_process_event+0x3b09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3b09;
	}
x86_l_3a09:
	/* 0x3a09: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3a0e:
	/* 0x3a0e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a13:
	/* 0x3a13: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3a18:
	/* 0x3a18: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3a1d:
	/* 0x3a1d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a22:
	/* 0x3a22: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3a25:
	/* 0x3a25: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a27:
	/* 0x3a27: cmp    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a2c:
	/* 0x3a2c: je     3b09 <generic_usdt_process_event+0x3b09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3b09;
	}
x86_l_3a32:
	/* 0x3a32: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3a37:
	/* 0x3a37: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3a3c:
	/* 0x3a3c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3a41:
	/* 0x3a41: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a46:
	/* 0x3a46: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3a49:
	/* 0x3a49: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a4b:
	/* 0x3a4b: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_3a4f:
	/* 0x3a4f: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3a54:
	/* 0x3a54: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3a59:
	/* 0x3a59: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3a5e:
	/* 0x3a5e: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3a63:
	/* 0x3a63: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3a66:
	/* 0x3a66: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a68:
	/* 0x3a68: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3a6d:
	/* 0x3a6d: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3a72:
	/* 0x3a72: mov    r12d,DWORD PTR [rsp+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_3a77:
	/* 0x3a77: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3a7a:
	/* 0x3a7a: mov    r13d,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3a7f:
	/* 0x3a7f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3a81:
	/* 0x3a81: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_3a84:
	/* 0x3a84: sub    edx,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R13, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3a87:
	/* 0x3a87: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_3a8a:
	/* 0x3a8a: add    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 128ULL);
x86_l_3a92:
	/* 0x3a92: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3a94:
	/* 0x3a94: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_3a97:
	/* 0x3a97: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_3a9b:
	/* 0x3a9b: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_3a9e:
	/* 0x3a9e: cmovb  ecx,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_3aa2:
	/* 0x3aa2: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3aa4:
	/* 0x3aa4: mov    edi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_32);
x86_l_3aa7:
	/* 0x3aa7: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3aa9:
	/* 0x3aa9: mov    DWORD PTR [rsp+0x70],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3aad:
	/* 0x3aad: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3ab0:
	/* 0x3ab0: jb     885 <generic_usdt_process_event+0x885> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2181ULL;
	}
x86_l_3ab6:
	/* 0x3ab6: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_3abc:
	/* 0x3abc: ja     885 <generic_usdt_process_event+0x885> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2181ULL;
	}
x86_l_3ac2:
	/* 0x3ac2: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_3ac5:
	/* 0x3ac5: jbe    3acc <generic_usdt_process_event+0x3acc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3acc;
	}
x86_l_3ac7:
	/* 0x3ac7: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_3acc:
	/* 0x3acc: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3ace:
	/* 0x3ace: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_3ad1:
	/* 0x3ad1: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_3ad5:
	/* 0x3ad5: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3ad8:
	/* 0x3ad8: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3adb:
	/* 0x3adb: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3ade:
	/* 0x3ade: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3ae3:
	/* 0x3ae3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ae5:
	/* 0x3ae5: mov    QWORD PTR [rsp+0x68],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3aea:
	/* 0x3aea: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_3aed:
	/* 0x3aed: jbe    885 <generic_usdt_process_event+0x885> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 2181ULL;
	}
x86_l_3af3:
	/* 0x3af3: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3af8:
	/* 0x3af8: mov    QWORD PTR [rsp+0x50],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3afd:
	/* 0x3afd: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3b02:
	/* 0x3b02: mov    r15,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3b07:
	/* 0x3b07: jmp    3b68 <generic_usdt_process_event+0x3b68> */
	goto x86_l_3b68;
x86_l_3b09:
	/* 0x3b09: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b0d:
	/* 0x3b0d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b12:
	/* 0x3b12: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3b17:
	/* 0x3b17: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3b1c:
	/* 0x3b1c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b21:
	/* 0x3b21: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b23:
	/* 0x3b23: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3b28:
	/* 0x3b28: cmp    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_3b2d:
	/* 0x3b2d: je     880 <generic_usdt_process_event+0x880> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2176ULL;
	}
x86_l_3b33:
	/* 0x3b33: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_3b37:
	/* 0x3b37: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3b3c:
	/* 0x3b3c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3b41:
	/* 0x3b41: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3b46:
	/* 0x3b46: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b4b:
	/* 0x3b4b: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3b4e:
	/* 0x3b4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b50:
	/* 0x3b50: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b55:
	/* 0x3b55: mov    QWORD PTR [rsp+0x60],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3b5a:
	/* 0x3b5a: lea    rdx,[r15+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3b5e:
	/* 0x3b5e: mov    QWORD PTR [rsp+0x58],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3b63:
	/* 0x3b63: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3b68:
	/* 0x3b68: cmp    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_3b6d:
	/* 0x3b6d: jne    3b7a <generic_usdt_process_event+0x3b7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3b7a;
	}
x86_l_3b6f:
	/* 0x3b6f: cmp    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_3b74:
	/* 0x3b74: je     880 <generic_usdt_process_event+0x880> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2176ULL;
	}
x86_l_3b7a:
	/* 0x3b7a: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_3b82:
	/* 0x3b82: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3b87:
	/* 0x3b87: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3b8c:
	/* 0x3b8c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b91:
	/* 0x3b91: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b93:
	/* 0x3b93: cmp    r12,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 144ULL);
x86_l_3b9b:
	/* 0x3b9b: je     3c9a <generic_usdt_process_event+0x3c9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c9a;
	}
x86_l_3ba1:
	/* 0x3ba1: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3ba6:
	/* 0x3ba6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3bab:
	/* 0x3bab: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3bb0:
	/* 0x3bb0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3bb5:
	/* 0x3bb5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3bba:
	/* 0x3bba: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3bbd:
	/* 0x3bbd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3bbf:
	/* 0x3bbf: cmp    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3bc4:
	/* 0x3bc4: je     3c9a <generic_usdt_process_event+0x3c9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c9a;
	}
x86_l_3bca:
	/* 0x3bca: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3bcf:
	/* 0x3bcf: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3bd4:
	/* 0x3bd4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3bd9:
	/* 0x3bd9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3bde:
	/* 0x3bde: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3be1:
	/* 0x3be1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3be3:
	/* 0x3be3: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_3be7:
	/* 0x3be7: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3bec:
	/* 0x3bec: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3bf1:
	/* 0x3bf1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3bf6:
	/* 0x3bf6: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3bfb:
	/* 0x3bfb: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3bfe:
	/* 0x3bfe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c00:
	/* 0x3c00: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3c05:
	/* 0x3c05: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3c0a:
	/* 0x3c0a: mov    r12d,DWORD PTR [rsp+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_3c0f:
	/* 0x3c0f: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3c12:
	/* 0x3c12: mov    r13d,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3c17:
	/* 0x3c17: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3c19:
	/* 0x3c19: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_3c1c:
	/* 0x3c1c: sub    edx,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R13, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3c1f:
	/* 0x3c1f: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_3c22:
	/* 0x3c22: add    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 128ULL);
x86_l_3c2a:
	/* 0x3c2a: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3c2c:
	/* 0x3c2c: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_3c2f:
	/* 0x3c2f: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_3c33:
	/* 0x3c33: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_3c36:
	/* 0x3c36: cmovb  ecx,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_3c3a:
	/* 0x3c3a: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3c3c:
	/* 0x3c3c: mov    edi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_32);
x86_l_3c3f:
	/* 0x3c3f: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3c41:
	/* 0x3c41: mov    DWORD PTR [rsp+0x70],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3c45:
	/* 0x3c45: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3c48:
	/* 0x3c48: jb     885 <generic_usdt_process_event+0x885> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2181ULL;
	}
x86_l_3c4e:
	/* 0x3c4e: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_3c54:
	/* 0x3c54: ja     885 <generic_usdt_process_event+0x885> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2181ULL;
	}
x86_l_3c5a:
	/* 0x3c5a: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_3c5d:
	/* 0x3c5d: jbe    3c64 <generic_usdt_process_event+0x3c64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3c64;
	}
x86_l_3c5f:
	/* 0x3c5f: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_3c64:
	/* 0x3c64: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3c66:
	/* 0x3c66: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_3c69:
	/* 0x3c69: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_3c6d:
	/* 0x3c6d: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3c70:
	/* 0x3c70: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3c73:
	/* 0x3c73: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3c76:
	/* 0x3c76: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3c7b:
	/* 0x3c7b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c7d:
	/* 0x3c7d: mov    QWORD PTR [rsp+0x68],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3c82:
	/* 0x3c82: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_3c85:
	/* 0x3c85: jbe    885 <generic_usdt_process_event+0x885> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 2181ULL;
	}
x86_l_3c8b:
	/* 0x3c8b: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3c90:
	/* 0x3c90: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3c95:
	/* 0x3c95: jmp    885 <generic_usdt_process_event+0x885> */
	return 2181ULL;
x86_l_3c9a:
	/* 0x3c9a: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c9e:
	/* 0x3c9e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3ca3:
	/* 0x3ca3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3ca8:
	/* 0x3ca8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3cad:
	/* 0x3cad: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3cb2:
	/* 0x3cb2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3cb4:
	/* 0x3cb4: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3cb9:
	/* 0x3cb9: cmp    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_3cbe:
	/* 0x3cbe: je     880 <generic_usdt_process_event+0x880> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2176ULL;
	}
x86_l_3cc4:
	/* 0x3cc4: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_3cc8:
	/* 0x3cc8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3ccd:
	/* 0x3ccd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3cd2:
	/* 0x3cd2: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3cd7:
	/* 0x3cd7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3cdc:
	/* 0x3cdc: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3cdf:
	/* 0x3cdf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ce1:
	/* 0x3ce1: jmp    885 <generic_usdt_process_event+0x885> */
	return 2181ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_usdt_generic_usdt_process_event_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 13696U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1860ULL)
			__x86_pc = tetragon_bpf_generic_usdt_generic_usdt_process_event_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1865ULL && __x86_pc <= 3607ULL)
			__x86_pc = tetragon_bpf_generic_usdt_generic_usdt_process_event_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3613ULL && __x86_pc <= 5380ULL)
			__x86_pc = tetragon_bpf_generic_usdt_generic_usdt_process_event_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5385ULL && __x86_pc <= 7152ULL)
			__x86_pc = tetragon_bpf_generic_usdt_generic_usdt_process_event_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7157ULL && __x86_pc <= 8889ULL)
			__x86_pc = tetragon_bpf_generic_usdt_generic_usdt_process_event_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8894ULL && __x86_pc <= 10673ULL)
			__x86_pc = tetragon_bpf_generic_usdt_generic_usdt_process_event_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10676ULL && __x86_pc <= 12380ULL)
			__x86_pc = tetragon_bpf_generic_usdt_generic_usdt_process_event_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12388ULL && __x86_pc <= 14020ULL)
			__x86_pc = tetragon_bpf_generic_usdt_generic_usdt_process_event_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 14025ULL && __x86_pc <= 15585ULL)
			__x86_pc = tetragon_bpf_generic_usdt_generic_usdt_process_event_x86_chunk_8(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

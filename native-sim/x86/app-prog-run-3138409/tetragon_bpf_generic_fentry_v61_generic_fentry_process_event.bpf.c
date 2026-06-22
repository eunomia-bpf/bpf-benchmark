extern char CONFIG_ITER_NUM;
extern char buffer_heap_map;
extern char config_map;
extern char data_heap;
extern char fdinstall_map;
extern char fentry_calls;
extern char process_call_heap;
extern char retprobe_map;
extern char socktrack_map;
extern char tcpmon_map;
extern char tg_conf_map;
extern char tg_errmetrics_map;
extern char tg_ipv6_ext_heap;
extern char tg_rb_events;
extern char tg_stats_map;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_generic_fentry_v61_generic_fentry_process_event_x86_chunk_0(
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
	case 174ULL: goto x86_l_ae;
	case 177ULL: goto x86_l_b1;
	case 179ULL: goto x86_l_b3;
	case 184ULL: goto x86_l_b8;
	case 189ULL: goto x86_l_bd;
	case 191ULL: goto x86_l_bf;
	case 203ULL: goto x86_l_cb;
	case 209ULL: goto x86_l_d1;
	case 213ULL: goto x86_l_d5;
	case 218ULL: goto x86_l_da;
	case 223ULL: goto x86_l_df;
	case 225ULL: goto x86_l_e1;
	case 227ULL: goto x86_l_e3;
	case 229ULL: goto x86_l_e5;
	case 233ULL: goto x86_l_e9;
	case 235ULL: goto x86_l_eb;
	case 239ULL: goto x86_l_ef;
	case 242ULL: goto x86_l_f2;
	case 250ULL: goto x86_l_fa;
	case 252ULL: goto x86_l_fc;
	case 264ULL: goto x86_l_108;
	case 266ULL: goto x86_l_10a;
	case 271ULL: goto x86_l_10f;
	case 283ULL: goto x86_l_11b;
	case 285ULL: goto x86_l_11d;
	case 287ULL: goto x86_l_11f;
	case 292ULL: goto x86_l_124;
	case 295ULL: goto x86_l_127;
	case 298ULL: goto x86_l_12a;
	case 303ULL: goto x86_l_12f;
	case 305ULL: goto x86_l_131;
	case 309ULL: goto x86_l_135;
	case 312ULL: goto x86_l_138;
	case 315ULL: goto x86_l_13b;
	case 318ULL: goto x86_l_13e;
	case 323ULL: goto x86_l_143;
	case 331ULL: goto x86_l_14b;
	case 334ULL: goto x86_l_14e;
	case 340ULL: goto x86_l_154;
	case 344ULL: goto x86_l_158;
	case 347ULL: goto x86_l_15b;
	case 353ULL: goto x86_l_161;
	case 359ULL: goto x86_l_167;
	case 362ULL: goto x86_l_16a;
	case 366ULL: goto x86_l_16e;
	case 371ULL: goto x86_l_173;
	case 379ULL: goto x86_l_17b;
	case 384ULL: goto x86_l_180;
	case 389ULL: goto x86_l_185;
	case 393ULL: goto x86_l_189;
	case 399ULL: goto x86_l_18f;
	case 407ULL: goto x86_l_197;
	case 414ULL: goto x86_l_19e;
	case 417ULL: goto x86_l_1a1;
	case 419ULL: goto x86_l_1a3;
	case 422ULL: goto x86_l_1a6;
	case 427ULL: goto x86_l_1ab;
	case 429ULL: goto x86_l_1ad;
	case 434ULL: goto x86_l_1b2;
	case 439ULL: goto x86_l_1b7;
	case 442ULL: goto x86_l_1ba;
	case 447ULL: goto x86_l_1bf;
	case 449ULL: goto x86_l_1c1;
	case 451ULL: goto x86_l_1c3;
	case 453ULL: goto x86_l_1c5;
	case 456ULL: goto x86_l_1c8;
	case 460ULL: goto x86_l_1cc;
	case 462ULL: goto x86_l_1ce;
	case 467ULL: goto x86_l_1d3;
	case 474ULL: goto x86_l_1da;
	case 476ULL: goto x86_l_1dc;
	case 481ULL: goto x86_l_1e1;
	case 485ULL: goto x86_l_1e5;
	case 488ULL: goto x86_l_1e8;
	case 491ULL: goto x86_l_1eb;
	case 498ULL: goto x86_l_1f2;
	case 500ULL: goto x86_l_1f4;
	case 505ULL: goto x86_l_1f9;
	case 507ULL: goto x86_l_1fb;
	case 512ULL: goto x86_l_200;
	case 514ULL: goto x86_l_202;
	case 521ULL: goto x86_l_209;
	case 523ULL: goto x86_l_20b;
	case 528ULL: goto x86_l_210;
	case 533ULL: goto x86_l_215;
	case 538ULL: goto x86_l_21a;
	case 543ULL: goto x86_l_21f;
	case 545ULL: goto x86_l_221;
	case 547ULL: goto x86_l_223;
	case 549ULL: goto x86_l_225;
	case 552ULL: goto x86_l_228;
	case 560ULL: goto x86_l_230;
	case 563ULL: goto x86_l_233;
	case 571ULL: goto x86_l_23b;
	case 577ULL: goto x86_l_241;
	case 581ULL: goto x86_l_245;
	case 583ULL: goto x86_l_247;
	case 587ULL: goto x86_l_24b;
	case 592ULL: goto x86_l_250;
	case 594ULL: goto x86_l_252;
	case 598ULL: goto x86_l_256;
	case 604ULL: goto x86_l_25c;
	case 608ULL: goto x86_l_260;
	case 614ULL: goto x86_l_266;
	case 618ULL: goto x86_l_26a;
	case 621ULL: goto x86_l_26d;
	case 627ULL: goto x86_l_273;
	case 631ULL: goto x86_l_277;
	case 637ULL: goto x86_l_27d;
	case 642ULL: goto x86_l_282;
	case 646ULL: goto x86_l_286;
	case 651ULL: goto x86_l_28b;
	case 653ULL: goto x86_l_28d;
	case 657ULL: goto x86_l_291;
	case 663ULL: goto x86_l_297;
	case 667ULL: goto x86_l_29b;
	case 670ULL: goto x86_l_29e;
	case 676ULL: goto x86_l_2a4;
	case 680ULL: goto x86_l_2a8;
	case 686ULL: goto x86_l_2ae;
	case 690ULL: goto x86_l_2b2;
	case 696ULL: goto x86_l_2b8;
	case 701ULL: goto x86_l_2bd;
	case 705ULL: goto x86_l_2c1;
	case 711ULL: goto x86_l_2c7;
	case 715ULL: goto x86_l_2cb;
	case 718ULL: goto x86_l_2ce;
	case 724ULL: goto x86_l_2d4;
	case 728ULL: goto x86_l_2d8;
	case 731ULL: goto x86_l_2db;
	case 737ULL: goto x86_l_2e1;
	case 742ULL: goto x86_l_2e6;
	case 746ULL: goto x86_l_2ea;
	case 752ULL: goto x86_l_2f0;
	case 756ULL: goto x86_l_2f4;
	case 762ULL: goto x86_l_2fa;
	case 766ULL: goto x86_l_2fe;
	case 772ULL: goto x86_l_304;
	case 776ULL: goto x86_l_308;
	case 782ULL: goto x86_l_30e;
	case 787ULL: goto x86_l_313;
	case 791ULL: goto x86_l_317;
	case 797ULL: goto x86_l_31d;
	case 801ULL: goto x86_l_321;
	case 807ULL: goto x86_l_327;
	case 811ULL: goto x86_l_32b;
	case 817ULL: goto x86_l_331;
	case 821ULL: goto x86_l_335;
	case 827ULL: goto x86_l_33b;
	case 833ULL: goto x86_l_341;
	case 838ULL: goto x86_l_346;
	case 842ULL: goto x86_l_34a;
	case 848ULL: goto x86_l_350;
	case 852ULL: goto x86_l_354;
	case 858ULL: goto x86_l_35a;
	case 862ULL: goto x86_l_35e;
	case 864ULL: goto x86_l_360;
	case 868ULL: goto x86_l_364;
	case 874ULL: goto x86_l_36a;
	case 879ULL: goto x86_l_36f;
	case 883ULL: goto x86_l_373;
	case 885ULL: goto x86_l_375;
	case 890ULL: goto x86_l_37a;
	case 894ULL: goto x86_l_37e;
	case 900ULL: goto x86_l_384;
	case 904ULL: goto x86_l_388;
	case 906ULL: goto x86_l_38a;
	case 908ULL: goto x86_l_38c;
	case 912ULL: goto x86_l_390;
	case 915ULL: goto x86_l_393;
	case 917ULL: goto x86_l_395;
	case 923ULL: goto x86_l_39b;
	case 925ULL: goto x86_l_39d;
	case 931ULL: goto x86_l_3a3;
	case 933ULL: goto x86_l_3a5;
	case 937ULL: goto x86_l_3a9;
	case 939ULL: goto x86_l_3ab;
	case 943ULL: goto x86_l_3af;
	case 945ULL: goto x86_l_3b1;
	case 951ULL: goto x86_l_3b7;
	case 953ULL: goto x86_l_3b9;
	case 957ULL: goto x86_l_3bd;
	case 959ULL: goto x86_l_3bf;
	case 963ULL: goto x86_l_3c3;
	case 965ULL: goto x86_l_3c5;
	case 967ULL: goto x86_l_3c7;
	case 973ULL: goto x86_l_3cd;
	case 975ULL: goto x86_l_3cf;
	case 979ULL: goto x86_l_3d3;
	case 981ULL: goto x86_l_3d5;
	case 985ULL: goto x86_l_3d9;
	case 987ULL: goto x86_l_3db;
	case 993ULL: goto x86_l_3e1;
	case 995ULL: goto x86_l_3e3;
	case 1001ULL: goto x86_l_3e9;
	case 1003ULL: goto x86_l_3eb;
	case 1009ULL: goto x86_l_3f1;
	case 1011ULL: goto x86_l_3f3;
	case 1015ULL: goto x86_l_3f7;
	case 1017ULL: goto x86_l_3f9;
	case 1023ULL: goto x86_l_3ff;
	case 1025ULL: goto x86_l_401;
	case 1028ULL: goto x86_l_404;
	case 1033ULL: goto x86_l_409;
	case 1044ULL: goto x86_l_414;
	case 1051ULL: goto x86_l_41b;
	case 1059ULL: goto x86_l_423;
	case 1064ULL: goto x86_l_428;
	case 1066ULL: goto x86_l_42a;
	case 1069ULL: goto x86_l_42d;
	case 1075ULL: goto x86_l_433;
	case 1080ULL: goto x86_l_438;
	case 1083ULL: goto x86_l_43b;
	case 1086ULL: goto x86_l_43e;
	case 1092ULL: goto x86_l_444;
	case 1096ULL: goto x86_l_448;
	case 1103ULL: goto x86_l_44f;
	case 1110ULL: goto x86_l_456;
	case 1114ULL: goto x86_l_45a;
	case 1122ULL: goto x86_l_462;
	case 1127ULL: goto x86_l_467;
	case 1129ULL: goto x86_l_469;
	case 1135ULL: goto x86_l_46f;
	case 1138ULL: goto x86_l_472;
	case 1145ULL: goto x86_l_479;
	case 1152ULL: goto x86_l_480;
	case 1155ULL: goto x86_l_483;
	case 1160ULL: goto x86_l_488;
	case 1165ULL: goto x86_l_48d;
	case 1177ULL: goto x86_l_499;
	case 1181ULL: goto x86_l_49d;
	case 1186ULL: goto x86_l_4a2;
	case 1191ULL: goto x86_l_4a7;
	case 1196ULL: goto x86_l_4ac;
	case 1198ULL: goto x86_l_4ae;
	case 1202ULL: goto x86_l_4b2;
	case 1204ULL: goto x86_l_4b4;
	case 1208ULL: goto x86_l_4b8;
	case 1214ULL: goto x86_l_4be;
	case 1218ULL: goto x86_l_4c2;
	case 1224ULL: goto x86_l_4c8;
	case 1236ULL: goto x86_l_4d4;
	case 1244ULL: goto x86_l_4dc;
	case 1252ULL: goto x86_l_4e4;
	case 1257ULL: goto x86_l_4e9;
	case 1261ULL: goto x86_l_4ed;
	case 1267ULL: goto x86_l_4f3;
	case 1271ULL: goto x86_l_4f7;
	case 1277ULL: goto x86_l_4fd;
	case 1282ULL: goto x86_l_502;
	case 1284ULL: goto x86_l_504;
	case 1289ULL: goto x86_l_509;
	case 1294ULL: goto x86_l_50e;
	case 1299ULL: goto x86_l_513;
	case 1304ULL: goto x86_l_518;
	case 1307ULL: goto x86_l_51b;
	case 1312ULL: goto x86_l_520;
	case 1314ULL: goto x86_l_522;
	case 1319ULL: goto x86_l_527;
	case 1324ULL: goto x86_l_52c;
	case 1329ULL: goto x86_l_531;
	case 1334ULL: goto x86_l_536;
	case 1339ULL: goto x86_l_53b;
	case 1344ULL: goto x86_l_540;
	case 1346ULL: goto x86_l_542;
	case 1350ULL: goto x86_l_546;
	case 1355ULL: goto x86_l_54b;
	case 1360ULL: goto x86_l_550;
	case 1365ULL: goto x86_l_555;
	case 1370ULL: goto x86_l_55a;
	case 1375ULL: goto x86_l_55f;
	case 1380ULL: goto x86_l_564;
	case 1382ULL: goto x86_l_566;
	case 1387ULL: goto x86_l_56b;
	case 1391ULL: goto x86_l_56f;
	case 1396ULL: goto x86_l_574;
	case 1407ULL: goto x86_l_57f;
	case 1414ULL: goto x86_l_586;
	case 1422ULL: goto x86_l_58e;
	case 1427ULL: goto x86_l_593;
	case 1429ULL: goto x86_l_595;
	case 1432ULL: goto x86_l_598;
	case 1438ULL: goto x86_l_59e;
	case 1441ULL: goto x86_l_5a1;
	case 1446ULL: goto x86_l_5a6;
	case 1452ULL: goto x86_l_5ac;
	case 1457ULL: goto x86_l_5b1;
	case 1462ULL: goto x86_l_5b6;
	case 1464ULL: goto x86_l_5b8;
	case 1471ULL: goto x86_l_5bf;
	case 1479ULL: goto x86_l_5c7;
	case 1484ULL: goto x86_l_5cc;
	case 1489ULL: goto x86_l_5d1;
	case 1494ULL: goto x86_l_5d6;
	case 1496ULL: goto x86_l_5d8;
	case 1504ULL: goto x86_l_5e0;
	case 1509ULL: goto x86_l_5e5;
	case 1513ULL: goto x86_l_5e9;
	case 1521ULL: goto x86_l_5f1;
	case 1526ULL: goto x86_l_5f6;
	case 1531ULL: goto x86_l_5fb;
	case 1536ULL: goto x86_l_600;
	case 1541ULL: goto x86_l_605;
	case 1546ULL: goto x86_l_60a;
	case 1551ULL: goto x86_l_60f;
	case 1553ULL: goto x86_l_611;
	case 1561ULL: goto x86_l_619;
	case 1565ULL: goto x86_l_61d;
	case 1570ULL: goto x86_l_622;
	case 1575ULL: goto x86_l_627;
	case 1580ULL: goto x86_l_62c;
	case 1585ULL: goto x86_l_631;
	case 1587ULL: goto x86_l_633;
	case 1593ULL: goto x86_l_639;
	case 1598ULL: goto x86_l_63e;
	case 1600ULL: goto x86_l_640;
	case 1605ULL: goto x86_l_645;
	case 1607ULL: goto x86_l_647;
	case 1610ULL: goto x86_l_64a;
	case 1615ULL: goto x86_l_64f;
	case 1620ULL: goto x86_l_654;
	case 1624ULL: goto x86_l_658;
	case 1629ULL: goto x86_l_65d;
	case 1634ULL: goto x86_l_662;
	case 1639ULL: goto x86_l_667;
	case 1644ULL: goto x86_l_66c;
	case 1646ULL: goto x86_l_66e;
	case 1651ULL: goto x86_l_673;
	case 1656ULL: goto x86_l_678;
	case 1658ULL: goto x86_l_67a;
	case 1661ULL: goto x86_l_67d;
	case 1668ULL: goto x86_l_684;
	case 1678ULL: goto x86_l_68e;
	case 1685ULL: goto x86_l_695;
	case 1695ULL: goto x86_l_69f;
	case 1700ULL: goto x86_l_6a4;
	case 1709ULL: goto x86_l_6ad;
	case 1718ULL: goto x86_l_6b6;
	case 1723ULL: goto x86_l_6bb;
	case 1735ULL: goto x86_l_6c7;
	case 1747ULL: goto x86_l_6d3;
	case 1759ULL: goto x86_l_6df;
	case 1764ULL: goto x86_l_6e4;
	case 1772ULL: goto x86_l_6ec;
	case 1779ULL: goto x86_l_6f3;
	case 1787ULL: goto x86_l_6fb;
	case 1791ULL: goto x86_l_6ff;
	case 1796ULL: goto x86_l_704;
	case 1801ULL: goto x86_l_709;
	case 1806ULL: goto x86_l_70e;
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
	/* 0x18: mov    rdi,QWORD PTR [rip+0x2e7] */
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
	/* 0x31: je     d41 <generic_fentry_process_event+0xd41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3393ULL;
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
	/* 0x4b: ja     ca2 <generic_fentry_process_event+0xca2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3234ULL;
	}
x86_l_51:
	/* 0x51: mov    DWORD PTR [rsp+0xf0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1030792151040ULL);
x86_l_5c:
	/* 0x5c: mov    rdi,QWORD PTR [rip+0x2e7] */
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
	/* 0x75: je     ca2 <generic_fentry_process_event+0xca2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3234ULL;
	}
x86_l_7b:
	/* 0x7b: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_7e:
	/* 0x7e: lea    rsi,[rax+0x5ef8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24312ULL);
x86_l_85:
	/* 0x85: mov    rdi,QWORD PTR [rip+0x2e7] */
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
	/* 0x97: jg     ca2 <generic_fentry_process_event+0xca2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3234ULL;
	}
x86_l_9d:
	/* 0x9d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a0:
	/* 0xa0: je     ca2 <generic_fentry_process_event+0xca2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3234ULL;
	}
x86_l_a6:
	/* 0xa6: mov    QWORD PTR [rsp+0x18],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ab:
	/* 0xab: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_ae:
	/* 0xae: and    edx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_b1:
	/* 0xb1: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_b3:
	/* 0xb3: mov    r13d,DWORD PTR [rax+rbp*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 2), 4ULL);
x86_l_b8:
	/* 0xb8: movsxd rsi,DWORD PTR [rax+rbp*4+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_RBP, 2, X86_WIDTH_32), 24ULL);
x86_l_bd:
	/* 0xbd: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_bf:
	/* 0xbf: mov    DWORD PTR [r15+rbp*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 2), 104041287778304ULL);
x86_l_cb:
	/* 0xcb: test   esi,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_d1:
	/* 0xd1: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d5:
	/* 0xd5: mov    QWORD PTR [rsp+0x40],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_da:
	/* 0xda: mov    QWORD PTR [rsp+0x30],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_df:
	/* 0xdf: jne    fc <generic_fentry_process_event+0xfc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_fc;
	}
x86_l_e1:
	/* 0xe1: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_e3:
	/* 0xe3: js     10f <generic_fentry_process_event+0x10f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_10f;
	}
x86_l_e5:
	/* 0xe5: test   sil,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RSI, X86_WIDTH_8, 64ULL);
x86_l_e9:
	/* 0xe9: jne    11f <generic_fentry_process_event+0x11f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_11f;
	}
x86_l_eb:
	/* 0xeb: mov    ecx,DWORD PTR [rax+rdx*4+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 64ULL);
x86_l_ef:
	/* 0xef: and    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_f2:
	/* 0xf2: mov    rsi,QWORD PTR [r15+rcx*8+0x5e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 3), 24144ULL);
x86_l_fa:
	/* 0xfa: jmp    143 <generic_fentry_process_event+0x143> */
	goto x86_l_143;
x86_l_fc:
	/* 0xfc: mov    QWORD PTR [rsp+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_108:
	/* 0x108: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10a:
	/* 0x10a: jmp    23b <generic_fentry_process_event+0x23b> */
	goto x86_l_23b;
x86_l_10f:
	/* 0x10f: mov    QWORD PTR [rsp+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_11b:
	/* 0x11b: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11d:
	/* 0x11d: jmp    14b <generic_fentry_process_event+0x14b> */
	goto x86_l_14b;
x86_l_11f:
	/* 0x11f: mov    QWORD PTR [rsp+0x38],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_124:
	/* 0x124: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_127:
	/* 0x127: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_12a:
	/* 0x12a: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_12f:
	/* 0x12f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_131:
	/* 0x131: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_135:
	/* 0x135: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_138:
	/* 0x138: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_13b:
	/* 0x13b: mov    rbx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R12, X86_WIDTH_64);
x86_l_13e:
	/* 0x13e: mov    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_143:
	/* 0x143: mov    QWORD PTR [rsp+0xd8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_14b:
	/* 0x14b: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_14e:
	/* 0x14e: ja     23b <generic_fentry_process_event+0x23b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_23b;
	}
x86_l_154:
	/* 0x154: lea    rcx,[rdx+rdx*4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 2), 0ULL);
x86_l_158:
	/* 0x158: shl    ecx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 4ULL);
x86_l_15b:
	/* 0x15b: cmp    WORD PTR [rax+rcx*1+0x76],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RCX, 0), 506806140928ULL);
x86_l_161:
	/* 0x161: je     23b <generic_fentry_process_event+0x23b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23b;
	}
x86_l_167:
	/* 0x167: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_16a:
	/* 0x16a: add    rax,0x70 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 112ULL);
x86_l_16e:
	/* 0x16e: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_173:
	/* 0x173: lea    rax,[rsp+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_17b:
	/* 0x17b: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_180:
	/* 0x180: mov    BYTE PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_185:
	/* 0x185: lea    rax,[r15+rbp*4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 2), 0ULL);
x86_l_189:
	/* 0x189: add    rax,0x5ea0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24224ULL);
x86_l_18f:
	/* 0x18f: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_197:
	/* 0x197: mov    rax,QWORD PTR [rip+0x2e7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_19e:
	/* 0x19e: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a1:
	/* 0x1a1: je     202 <generic_fentry_process_event+0x202> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_202;
	}
x86_l_1a3:
	/* 0x1a3: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a6:
	/* 0x1a6: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_1ab:
	/* 0x1ab: jmp    1ce <generic_fentry_process_event+0x1ce> */
	goto x86_l_1ce;
x86_l_1ad:
	/* 0x1ad: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b2:
	/* 0x1b2: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1b7:
	/* 0x1b7: mov    rdx,QWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ba:
	/* 0x1ba: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bf:
	/* 0x1bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c1:
	/* 0x1c1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c3:
	/* 0x1c3: js     225 <generic_fentry_process_event+0x225> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_225;
	}
x86_l_1c5:
	/* 0x1c5: inc    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1c8:
	/* 0x1c8: cmp    r15,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 10ULL);
x86_l_1cc:
	/* 0x1cc: je     233 <generic_fentry_process_event+0x233> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_233;
	}
x86_l_1ce:
	/* 0x1ce: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1d3:
	/* 0x1d3: cmp    WORD PTR [rax+r15*8+0x6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 3), 25769803776ULL);
x86_l_1da:
	/* 0x1da: je     233 <generic_fentry_process_event+0x233> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_233;
	}
x86_l_1dc:
	/* 0x1dc: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1e1:
	/* 0x1e1: mov    edx,DWORD PTR [rax+r15*8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 3), 0ULL);
x86_l_1e5:
	/* 0x1e5: add    rdx,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1e8:
	/* 0x1e8: mov    QWORD PTR [rcx],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1eb:
	/* 0x1eb: cmp    WORD PTR [rax+r15*8+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 3), 17179869184ULL);
x86_l_1f2:
	/* 0x1f2: je     1c5 <generic_fentry_process_event+0x1c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c5;
	}
x86_l_1f4:
	/* 0x1f4: cmp    BYTE PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_1f9:
	/* 0x1f9: je     1ad <generic_fentry_process_event+0x1ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ad;
	}
x86_l_1fb:
	/* 0x1fb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_200:
	/* 0x200: jmp    1b2 <generic_fentry_process_event+0x1b2> */
	goto x86_l_1b2;
x86_l_202:
	/* 0x202: lea    rsi,[rip+0x2e4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 740ULL);
x86_l_209:
	/* 0x209: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20b:
	/* 0x20b: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_210:
	/* 0x210: mov    edi,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 10ULL);
x86_l_215:
	/* 0x215: mov    eax,0xb5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 181ULL);
x86_l_21a:
	/* 0x21a: mov    edi,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 10ULL);
x86_l_21f:
	/* 0x21f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_221:
	/* 0x221: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_223:
	/* 0x223: jmp    233 <generic_fentry_process_event+0x233> */
	goto x86_l_233;
x86_l_225:
	/* 0x225: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_228:
	/* 0x228: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_230:
	/* 0x230: mov    DWORD PTR [rax],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_233:
	/* 0x233: mov    rsi,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_23b:
	/* 0x23b: mov    r15d,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4096ULL);
x86_l_241:
	/* 0x241: cmp    r13d,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 21ULL);
x86_l_245:
	/* 0x245: jg     282 <generic_fentry_process_event+0x282> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_282;
	}
x86_l_247:
	/* 0x247: cmp    r13d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 11ULL);
x86_l_24b:
	/* 0x24b: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_250:
	/* 0x250: jg     2bd <generic_fentry_process_event+0x2bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2bd;
	}
x86_l_252:
	/* 0x252: cmp    r13d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 5ULL);
x86_l_256:
	/* 0x256: jg     346 <generic_fentry_process_event+0x346> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_346;
	}
x86_l_25c:
	/* 0x25c: cmp    r13d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 3ULL);
x86_l_260:
	/* 0x260: jg     3cf <generic_fentry_process_event+0x3cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3cf;
	}
x86_l_266:
	/* 0x266: lea    eax,[r13-0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_26a:
	/* 0x26a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_26d:
	/* 0x26d: jb     395 <generic_fentry_process_event+0x395> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_395;
	}
x86_l_273:
	/* 0x273: cmp    r13d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1ULL);
x86_l_277:
	/* 0x277: je     395 <generic_fentry_process_event+0x395> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_395;
	}
x86_l_27d:
	/* 0x27d: jmp    401 <generic_fentry_process_event+0x401> */
	goto x86_l_401;
x86_l_282:
	/* 0x282: cmp    r13d,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 32ULL);
x86_l_286:
	/* 0x286: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_28b:
	/* 0x28b: jle    2e6 <generic_fentry_process_event+0x2e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2e6;
	}
x86_l_28d:
	/* 0x28d: cmp    r13d,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 39ULL);
x86_l_291:
	/* 0x291: jg     313 <generic_fentry_process_event+0x313> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_313;
	}
x86_l_297:
	/* 0x297: lea    eax,[r13-0x21] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551583ULL);
x86_l_29b:
	/* 0x29b: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_29e:
	/* 0x29e: jb     3e3 <generic_fentry_process_event+0x3e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3e3;
	}
x86_l_2a4:
	/* 0x2a4: cmp    r13d,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 37ULL);
x86_l_2a8:
	/* 0x2a8: je     404 <generic_fentry_process_event+0x404> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_404;
	}
x86_l_2ae:
	/* 0x2ae: cmp    r13d,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 39ULL);
x86_l_2b2:
	/* 0x2b2: je     39d <generic_fentry_process_event+0x39d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_39d;
	}
x86_l_2b8:
	/* 0x2b8: jmp    401 <generic_fentry_process_event+0x401> */
	goto x86_l_401;
x86_l_2bd:
	/* 0x2bd: cmp    r13d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 17ULL);
x86_l_2c1:
	/* 0x2c1: jg     36f <generic_fentry_process_event+0x36f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_36f;
	}
x86_l_2c7:
	/* 0x2c7: lea    eax,[r13-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_2cb:
	/* 0x2cb: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2ce:
	/* 0x2ce: jb     404 <generic_fentry_process_event+0x404> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_404;
	}
x86_l_2d4:
	/* 0x2d4: lea    eax,[r13-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_2d8:
	/* 0x2d8: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2db:
	/* 0x2db: jb     395 <generic_fentry_process_event+0x395> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_395;
	}
x86_l_2e1:
	/* 0x2e1: jmp    401 <generic_fentry_process_event+0x401> */
	goto x86_l_401;
x86_l_2e6:
	/* 0x2e6: cmp    r13d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 26ULL);
x86_l_2ea:
	/* 0x2ea: jg     38c <generic_fentry_process_event+0x38c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_38c;
	}
x86_l_2f0:
	/* 0x2f0: cmp    r13d,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 22ULL);
x86_l_2f4:
	/* 0x2f4: je     39d <generic_fentry_process_event+0x39d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_39d;
	}
x86_l_2fa:
	/* 0x2fa: cmp    r13d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 23ULL);
x86_l_2fe:
	/* 0x2fe: je     3e3 <generic_fentry_process_event+0x3e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e3;
	}
x86_l_304:
	/* 0x304: cmp    r13d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 26ULL);
x86_l_308:
	/* 0x308: je     3f9 <generic_fentry_process_event+0x3f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3f9;
	}
x86_l_30e:
	/* 0x30e: jmp    401 <generic_fentry_process_event+0x401> */
	goto x86_l_401;
x86_l_313:
	/* 0x313: cmp    r13d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 41ULL);
x86_l_317:
	/* 0x317: jle    3b9 <generic_fentry_process_event+0x3b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_3b9;
	}
x86_l_31d:
	/* 0x31d: cmp    r13d,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 42ULL);
x86_l_321:
	/* 0x321: je     404 <generic_fentry_process_event+0x404> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_404;
	}
x86_l_327:
	/* 0x327: cmp    r13d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 43ULL);
x86_l_32b:
	/* 0x32b: je     3c7 <generic_fentry_process_event+0x3c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c7;
	}
x86_l_331:
	/* 0x331: cmp    r13d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 44ULL);
x86_l_335:
	/* 0x335: jne    401 <generic_fentry_process_event+0x401> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_401;
	}
x86_l_33b:
	/* 0x33b: mov    r15d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 112ULL);
x86_l_341:
	/* 0x341: jmp    404 <generic_fentry_process_event+0x404> */
	goto x86_l_404;
x86_l_346:
	/* 0x346: cmp    r13d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 9ULL);
x86_l_34a:
	/* 0x34a: jg     3e3 <generic_fentry_process_event+0x3e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3e3;
	}
x86_l_350:
	/* 0x350: cmp    r13d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 6ULL);
x86_l_354:
	/* 0x354: je     404 <generic_fentry_process_event+0x404> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_404;
	}
x86_l_35a:
	/* 0x35a: cmp    r13d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 7ULL);
x86_l_35e:
	/* 0x35e: je     3db <generic_fentry_process_event+0x3db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3db;
	}
x86_l_360:
	/* 0x360: cmp    r13d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 8ULL);
x86_l_364:
	/* 0x364: je     3f9 <generic_fentry_process_event+0x3f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3f9;
	}
x86_l_36a:
	/* 0x36a: jmp    401 <generic_fentry_process_event+0x401> */
	goto x86_l_401;
x86_l_36f:
	/* 0x36f: cmp    r13d,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 19ULL);
x86_l_373:
	/* 0x373: jg     3a5 <generic_fentry_process_event+0x3a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3a5;
	}
x86_l_375:
	/* 0x375: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_37a:
	/* 0x37a: cmp    r13d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 18ULL);
x86_l_37e:
	/* 0x37e: je     404 <generic_fentry_process_event+0x404> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_404;
	}
x86_l_384:
	/* 0x384: cmp    r13d,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 19ULL);
x86_l_388:
	/* 0x388: je     3c7 <generic_fentry_process_event+0x3c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c7;
	}
x86_l_38a:
	/* 0x38a: jmp    401 <generic_fentry_process_event+0x401> */
	goto x86_l_401;
x86_l_38c:
	/* 0x38c: lea    eax,[r13-0x1d] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551587ULL);
x86_l_390:
	/* 0x390: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_393:
	/* 0x393: jae    3f3 <generic_fentry_process_event+0x3f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_3f3;
	}
x86_l_395:
	/* 0x395: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_39b:
	/* 0x39b: jmp    404 <generic_fentry_process_event+0x404> */
	goto x86_l_404;
x86_l_39d:
	/* 0x39d: mov    r15d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 16ULL);
x86_l_3a3:
	/* 0x3a3: jmp    404 <generic_fentry_process_event+0x404> */
	goto x86_l_404;
x86_l_3a5:
	/* 0x3a5: cmp    r13d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 20ULL);
x86_l_3a9:
	/* 0x3a9: je     3eb <generic_fentry_process_event+0x3eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3eb;
	}
x86_l_3ab:
	/* 0x3ab: cmp    r13d,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 21ULL);
x86_l_3af:
	/* 0x3af: jne    401 <generic_fentry_process_event+0x401> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_401;
	}
x86_l_3b1:
	/* 0x3b1: mov    r15d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 32ULL);
x86_l_3b7:
	/* 0x3b7: jmp    404 <generic_fentry_process_event+0x404> */
	goto x86_l_404;
x86_l_3b9:
	/* 0x3b9: cmp    r13d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 40ULL);
x86_l_3bd:
	/* 0x3bd: je     3c7 <generic_fentry_process_event+0x3c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c7;
	}
x86_l_3bf:
	/* 0x3bf: cmp    r13d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 41ULL);
x86_l_3c3:
	/* 0x3c3: je     3db <generic_fentry_process_event+0x3db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3db;
	}
x86_l_3c5:
	/* 0x3c5: jmp    401 <generic_fentry_process_event+0x401> */
	goto x86_l_401;
x86_l_3c7:
	/* 0x3c7: mov    r15d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 24ULL);
x86_l_3cd:
	/* 0x3cd: jmp    404 <generic_fentry_process_event+0x404> */
	goto x86_l_404;
x86_l_3cf:
	/* 0x3cf: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_3d3:
	/* 0x3d3: je     3e3 <generic_fentry_process_event+0x3e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e3;
	}
x86_l_3d5:
	/* 0x3d5: cmp    r13d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 5ULL);
x86_l_3d9:
	/* 0x3d9: jne    401 <generic_fentry_process_event+0x401> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_401;
	}
x86_l_3db:
	/* 0x3db: mov    r15d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 64ULL);
x86_l_3e1:
	/* 0x3e1: jmp    404 <generic_fentry_process_event+0x404> */
	goto x86_l_404;
x86_l_3e3:
	/* 0x3e3: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_3e9:
	/* 0x3e9: jmp    404 <generic_fentry_process_event+0x404> */
	goto x86_l_404;
x86_l_3eb:
	/* 0x3eb: mov    r15d,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 152ULL);
x86_l_3f1:
	/* 0x3f1: jmp    404 <generic_fentry_process_event+0x404> */
	goto x86_l_404;
x86_l_3f3:
	/* 0x3f3: cmp    r13d,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 27ULL);
x86_l_3f7:
	/* 0x3f7: jne    401 <generic_fentry_process_event+0x401> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_401;
	}
x86_l_3f9:
	/* 0x3f9: mov    r15d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 80ULL);
x86_l_3ff:
	/* 0x3ff: jmp    404 <generic_fentry_process_event+0x404> */
	goto x86_l_404;
x86_l_401:
	/* 0x401: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_404:
	/* 0x404: mov    QWORD PTR [rsp+0x20],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_409:
	/* 0x409: mov    DWORD PTR [rsp+0xf4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_414:
	/* 0x414: mov    rdi,QWORD PTR [rip+0x2e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_41b:
	/* 0x41b: lea    rsi,[rsp+0xf4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 244ULL);
x86_l_423:
	/* 0x423: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_428:
	/* 0x428: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42a:
	/* 0x42a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_42d:
	/* 0x42d: je     ca2 <generic_fentry_process_event+0xca2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3234ULL;
	}
x86_l_433:
	/* 0x433: mov    ecx,0x3ffb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16379ULL);
x86_l_438:
	/* 0x438: sub    rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_43b:
	/* 0x43b: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_43e:
	/* 0x43e: jbe    ca2 <generic_fentry_process_event+0xca2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 3234ULL;
	}
x86_l_444:
	/* 0x444: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_448:
	/* 0x448: mov    ecx,DWORD PTR [rax+rdx*4+0x5ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 24224ULL);
x86_l_44f:
	/* 0x44f: mov    DWORD PTR [rax+rbp*1+0x90],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 144ULL);
x86_l_456:
	/* 0x456: lea    r15,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_45a:
	/* 0x45a: mov    QWORD PTR [rax+rdx*8+0x5e78],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 3), 24184ULL);
x86_l_462:
	/* 0x462: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_467:
	/* 0x467: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_469:
	/* 0x469: jne    c9e <generic_fentry_process_event+0xc9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3230ULL;
	}
x86_l_46f:
	/* 0x46f: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_472:
	/* 0x472: add    rbp,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_479:
	/* 0x479: and    r15d,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_480:
	/* 0x480: add    rbp,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_483:
	/* 0x483: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_488:
	/* 0x488: mov    QWORD PTR [rsp+0x68],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_48d:
	/* 0x48d: mov    QWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_499:
	/* 0x499: cmp    r13d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 23ULL);
x86_l_49d:
	/* 0x49d: mov    QWORD PTR [rsp+0x28],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4a2:
	/* 0x4a2: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4a7:
	/* 0x4a7: mov    QWORD PTR [rsp+0x38],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4ac:
	/* 0x4ac: jle    4e9 <generic_fentry_process_event+0x4e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_4e9;
	}
x86_l_4ae:
	/* 0x4ae: cmp    r13d,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 24ULL);
x86_l_4b2:
	/* 0x4b2: je     504 <generic_fentry_process_event+0x504> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_504;
	}
x86_l_4b4:
	/* 0x4b4: cmp    r13d,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 37ULL);
x86_l_4b8:
	/* 0x4b8: je     542 <generic_fentry_process_event+0x542> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_542;
	}
x86_l_4be:
	/* 0x4be: cmp    r13d,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 42ULL);
x86_l_4c2:
	/* 0x4c2: jne    a85 <generic_fentry_process_event+0xa85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2693ULL;
	}
x86_l_4c8:
	/* 0x4c8: mov    QWORD PTR [rsp+0xf8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1065151889408ULL);
x86_l_4d4:
	/* 0x4d4: mov    QWORD PTR [rsp+0x100],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_4dc:
	/* 0x4dc: lea    rax,[rsp+0xf8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_4e4:
	/* 0x4e4: jmp    56f <generic_fentry_process_event+0x56f> */
	goto x86_l_56f;
x86_l_4e9:
	/* 0x4e9: cmp    r13d,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 15ULL);
x86_l_4ed:
	/* 0x4ed: je     9ad <generic_fentry_process_event+0x9ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2477ULL;
	}
x86_l_4f3:
	/* 0x4f3: cmp    r13d,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 16ULL);
x86_l_4f7:
	/* 0x4f7: jne    a85 <generic_fentry_process_event+0xa85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2693ULL;
	}
x86_l_4fd:
	/* 0x4fd: lea    r15,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_502:
	/* 0x502: jmp    52c <generic_fentry_process_event+0x52c> */
	goto x86_l_52c;
x86_l_504:
	/* 0x504: lea    r15,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_509:
	/* 0x509: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_50e:
	/* 0x50e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_513:
	/* 0x513: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_518:
	/* 0x518: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_51b:
	/* 0x51b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_520:
	/* 0x520: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_522:
	/* 0x522: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_527:
	/* 0x527: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_52c:
	/* 0x52c: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_531:
	/* 0x531: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_536:
	/* 0x536: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_53b:
	/* 0x53b: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_540:
	/* 0x540: jmp    55f <generic_fentry_process_event+0x55f> */
	goto x86_l_55f;
x86_l_542:
	/* 0x542: add    rdx,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_546:
	/* 0x546: mov    QWORD PTR [rsp+0x68],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_54b:
	/* 0x54b: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_550:
	/* 0x550: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_555:
	/* 0x555: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_55a:
	/* 0x55a: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_55f:
	/* 0x55f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_564:
	/* 0x564: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_566:
	/* 0x566: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_56b:
	/* 0x56b: add    rax,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_56f:
	/* 0x56f: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_574:
	/* 0x574: mov    DWORD PTR [rsp+0xbc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_57f:
	/* 0x57f: mov    rdi,QWORD PTR [rip+0x2e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&buffer_heap_map)));
x86_l_586:
	/* 0x586: lea    rsi,[rsp+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_58e:
	/* 0x58e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_593:
	/* 0x593: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_595:
	/* 0x595: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_598:
	/* 0x598: je     647 <generic_fentry_process_event+0x647> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_647;
	}
x86_l_59e:
	/* 0x59e: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_5a1:
	/* 0x5a1: mov    QWORD PTR [rsp+0x8],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a6:
	/* 0x5a6: add    rax,0x1000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 4096ULL);
x86_l_5ac:
	/* 0x5ac: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5b1:
	/* 0x5b1: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_5b6:
	/* 0x5b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b8:
	/* 0x5b8: lea    rdx,[rax+0xd30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3376ULL);
x86_l_5bf:
	/* 0x5bf: lea    rdi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_5c7:
	/* 0x5c7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5cc:
	/* 0x5cc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5d1:
	/* 0x5d1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5d6:
	/* 0x5d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d8:
	/* 0x5d8: mov    r12,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_5e0:
	/* 0x5e0: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_5e5:
	/* 0x5e5: lea    rdx,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e9:
	/* 0x5e9: lea    rdi,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_5f1:
	/* 0x5f1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5f6:
	/* 0x5f6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5fb:
	/* 0x5fb: lea    rcx,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_600:
	/* 0x600: mov    QWORD PTR [rsp+0x40],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_605:
	/* 0x605: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_60a:
	/* 0x60a: mov    QWORD PTR [rsp+0x30],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_60f:
	/* 0x60f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_611:
	/* 0x611: mov    r15,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_619:
	/* 0x619: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_61d:
	/* 0x61d: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_622:
	/* 0x622: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_627:
	/* 0x627: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_62c:
	/* 0x62c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_631:
	/* 0x631: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_633:
	/* 0x633: cmp    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_639:
	/* 0x639: mov    ebp,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4096ULL);
x86_l_63e:
	/* 0x63e: je     654 <generic_fentry_process_event+0x654> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_654;
	}
x86_l_640:
	/* 0x640: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_645:
	/* 0x645: jmp    6a4 <generic_fentry_process_event+0x6a4> */
	goto x86_l_6a4;
x86_l_647:
	/* 0x647: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_64a:
	/* 0x64a: mov    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_64f:
	/* 0x64f: jmp    c8b <generic_fentry_process_event+0xc8b> */
	return 3211ULL;
x86_l_654:
	/* 0x654: lea    rdx,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_658:
	/* 0x658: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_65d:
	/* 0x65d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_662:
	/* 0x662: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_667:
	/* 0x667: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_66c:
	/* 0x66c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_66e:
	/* 0x66e: cmp    QWORD PTR [rsp+0x68],r15 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_673:
	/* 0x673: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_678:
	/* 0x678: je     6a4 <generic_fentry_process_event+0x6a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6a4;
	}
x86_l_67a:
	/* 0x67a: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_67d:
	/* 0x67d: add    rcx,0xff6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4086ULL);
x86_l_684:
	/* 0x684: movabs rax,0x6574656c65642820 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310579611361093664ULL);
x86_l_68e:
	/* 0x68e: mov    QWORD PTR [r13+0xff6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_695:
	/* 0x695: mov    WORD PTR [r13+0xffe],0x2964 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17583596120420ULL);
x86_l_69f:
	/* 0x69f: mov    ebp,0xff6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4086ULL);
x86_l_6a4:
	/* 0x6a4: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_6ad:
	/* 0x6ad: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_6b6:
	/* 0x6b6: mov    QWORD PTR [rsp+0x78],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_6bb:
	/* 0x6bb: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_6c7:
	/* 0x6c7: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_6d3:
	/* 0x6d3: mov    QWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_6df:
	/* 0x6df: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6e4:
	/* 0x6e4: mov    QWORD PTR [rsp+0x98],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_6ec:
	/* 0x6ec: mov    DWORD PTR [rsp+0xa0],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_6f3:
	/* 0x6f3: mov    BYTE PTR [rsp+0xa4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_6fb:
	/* 0x6fb: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_6ff:
	/* 0x6ff: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_704:
	/* 0x704: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_709:
	/* 0x709: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_70e:
	/* 0x70e: lea    r13,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
	return 1811ULL;
}

static __noinline __u64 tetragon_bpf_generic_fentry_v61_generic_fentry_process_event_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1811ULL: goto x86_l_713;
	case 1819ULL: goto x86_l_71b;
	case 1827ULL: goto x86_l_723;
	case 1832ULL: goto x86_l_728;
	case 1835ULL: goto x86_l_72b;
	case 1837ULL: goto x86_l_72d;
	case 1842ULL: goto x86_l_732;
	case 1847ULL: goto x86_l_737;
	case 1852ULL: goto x86_l_73c;
	case 1855ULL: goto x86_l_73f;
	case 1860ULL: goto x86_l_744;
	case 1862ULL: goto x86_l_746;
	case 1867ULL: goto x86_l_74b;
	case 1872ULL: goto x86_l_750;
	case 1877ULL: goto x86_l_755;
	case 1880ULL: goto x86_l_758;
	case 1885ULL: goto x86_l_75d;
	case 1887ULL: goto x86_l_75f;
	case 1892ULL: goto x86_l_764;
	case 1897ULL: goto x86_l_769;
	case 1902ULL: goto x86_l_76e;
	case 1905ULL: goto x86_l_771;
	case 1910ULL: goto x86_l_776;
	case 1912ULL: goto x86_l_778;
	case 1920ULL: goto x86_l_780;
	case 1924ULL: goto x86_l_784;
	case 1932ULL: goto x86_l_78c;
	case 1939ULL: goto x86_l_793;
	case 1942ULL: goto x86_l_796;
	case 1948ULL: goto x86_l_79c;
	case 1953ULL: goto x86_l_7a1;
	case 1959ULL: goto x86_l_7a7;
	case 1967ULL: goto x86_l_7af;
	case 1975ULL: goto x86_l_7b7;
	case 1983ULL: goto x86_l_7bf;
	case 1988ULL: goto x86_l_7c4;
	case 1990ULL: goto x86_l_7c6;
	case 1995ULL: goto x86_l_7cb;
	case 2001ULL: goto x86_l_7d1;
	case 2006ULL: goto x86_l_7d6;
	case 2014ULL: goto x86_l_7de;
	case 2019ULL: goto x86_l_7e3;
	case 2021ULL: goto x86_l_7e5;
	case 2029ULL: goto x86_l_7ed;
	case 2035ULL: goto x86_l_7f3;
	case 2041ULL: goto x86_l_7f9;
	case 2045ULL: goto x86_l_7fd;
	case 2050ULL: goto x86_l_802;
	case 2055ULL: goto x86_l_807;
	case 2060ULL: goto x86_l_80c;
	case 2063ULL: goto x86_l_80f;
	case 2065ULL: goto x86_l_811;
	case 2070ULL: goto x86_l_816;
	case 2076ULL: goto x86_l_81c;
	case 2081ULL: goto x86_l_821;
	case 2086ULL: goto x86_l_826;
	case 2091ULL: goto x86_l_82b;
	case 2094ULL: goto x86_l_82e;
	case 2096ULL: goto x86_l_830;
	case 2100ULL: goto x86_l_834;
	case 2105ULL: goto x86_l_839;
	case 2113ULL: goto x86_l_841;
	case 2118ULL: goto x86_l_846;
	case 2123ULL: goto x86_l_84b;
	case 2126ULL: goto x86_l_84e;
	case 2128ULL: goto x86_l_850;
	case 2133ULL: goto x86_l_855;
	case 2141ULL: goto x86_l_85d;
	case 2149ULL: goto x86_l_865;
	case 2152ULL: goto x86_l_868;
	case 2160ULL: goto x86_l_870;
	case 2163ULL: goto x86_l_873;
	case 2166ULL: goto x86_l_876;
	case 2171ULL: goto x86_l_87b;
	case 2174ULL: goto x86_l_87e;
	case 2182ULL: goto x86_l_886;
	case 2184ULL: goto x86_l_888;
	case 2187ULL: goto x86_l_88b;
	case 2191ULL: goto x86_l_88f;
	case 2194ULL: goto x86_l_892;
	case 2198ULL: goto x86_l_896;
	case 2200ULL: goto x86_l_898;
	case 2203ULL: goto x86_l_89b;
	case 2205ULL: goto x86_l_89d;
	case 2212ULL: goto x86_l_8a4;
	case 2215ULL: goto x86_l_8a7;
	case 2220ULL: goto x86_l_8ac;
	case 2226ULL: goto x86_l_8b2;
	case 2232ULL: goto x86_l_8b8;
	case 2238ULL: goto x86_l_8be;
	case 2241ULL: goto x86_l_8c1;
	case 2243ULL: goto x86_l_8c3;
	case 2248ULL: goto x86_l_8c8;
	case 2250ULL: goto x86_l_8ca;
	case 2253ULL: goto x86_l_8cd;
	case 2257ULL: goto x86_l_8d1;
	case 2260ULL: goto x86_l_8d4;
	case 2263ULL: goto x86_l_8d7;
	case 2266ULL: goto x86_l_8da;
	case 2271ULL: goto x86_l_8df;
	case 2273ULL: goto x86_l_8e1;
	case 2281ULL: goto x86_l_8e9;
	case 2284ULL: goto x86_l_8ec;
	case 2290ULL: goto x86_l_8f2;
	case 2295ULL: goto x86_l_8f7;
	case 2303ULL: goto x86_l_8ff;
	case 2309ULL: goto x86_l_905;
	case 2311ULL: goto x86_l_907;
	case 2317ULL: goto x86_l_90d;
	case 2322ULL: goto x86_l_912;
	case 2327ULL: goto x86_l_917;
	case 2332ULL: goto x86_l_91c;
	case 2337ULL: goto x86_l_921;
	case 2342ULL: goto x86_l_926;
	case 2344ULL: goto x86_l_928;
	case 2352ULL: goto x86_l_930;
	case 2357ULL: goto x86_l_935;
	case 2363ULL: goto x86_l_93b;
	case 2369ULL: goto x86_l_941;
	case 2373ULL: goto x86_l_945;
	case 2378ULL: goto x86_l_94a;
	case 2386ULL: goto x86_l_952;
	case 2391ULL: goto x86_l_957;
	case 2394ULL: goto x86_l_95a;
	case 2396ULL: goto x86_l_95c;
	case 2401ULL: goto x86_l_961;
	case 2409ULL: goto x86_l_969;
	case 2413ULL: goto x86_l_96d;
	case 2421ULL: goto x86_l_975;
	case 2426ULL: goto x86_l_97a;
	case 2428ULL: goto x86_l_97c;
	case 2434ULL: goto x86_l_982;
	case 2439ULL: goto x86_l_987;
	case 2446ULL: goto x86_l_98e;
	case 2448ULL: goto x86_l_990;
	case 2453ULL: goto x86_l_995;
	case 2458ULL: goto x86_l_99a;
	case 2463ULL: goto x86_l_99f;
	case 2468ULL: goto x86_l_9a4;
	case 2470ULL: goto x86_l_9a6;
	case 2472ULL: goto x86_l_9a8;
	case 2477ULL: goto x86_l_9ad;
	case 2485ULL: goto x86_l_9b5;
	case 2490ULL: goto x86_l_9ba;
	case 2495ULL: goto x86_l_9bf;
	case 2500ULL: goto x86_l_9c4;
	case 2505ULL: goto x86_l_9c9;
	case 2507ULL: goto x86_l_9cb;
	case 2515ULL: goto x86_l_9d3;
	case 2520ULL: goto x86_l_9d8;
	case 2523ULL: goto x86_l_9db;
	case 2529ULL: goto x86_l_9e1;
	case 2540ULL: goto x86_l_9ec;
	case 2547ULL: goto x86_l_9f3;
	case 2555ULL: goto x86_l_9fb;
	case 2560ULL: goto x86_l_a00;
	case 2562ULL: goto x86_l_a02;
	case 2565ULL: goto x86_l_a05;
	case 2571ULL: goto x86_l_a0b;
	case 2576ULL: goto x86_l_a10;
	case 2581ULL: goto x86_l_a15;
	case 2584ULL: goto x86_l_a18;
	case 2588ULL: goto x86_l_a1c;
	case 2593ULL: goto x86_l_a21;
	case 2598ULL: goto x86_l_a26;
	case 2604ULL: goto x86_l_a2c;
	case 2608ULL: goto x86_l_a30;
	case 2614ULL: goto x86_l_a36;
	case 2618ULL: goto x86_l_a3a;
	case 2624ULL: goto x86_l_a40;
	case 2628ULL: goto x86_l_a44;
	case 2634ULL: goto x86_l_a4a;
	case 2638ULL: goto x86_l_a4e;
	case 2644ULL: goto x86_l_a54;
	case 2648ULL: goto x86_l_a58;
	case 2653ULL: goto x86_l_a5d;
	case 2657ULL: goto x86_l_a61;
	case 2662ULL: goto x86_l_a66;
	case 2668ULL: goto x86_l_a6c;
	case 2673ULL: goto x86_l_a71;
	case 2680ULL: goto x86_l_a78;
	case 2682ULL: goto x86_l_a7a;
	case 2688ULL: goto x86_l_a80;
	case 2693ULL: goto x86_l_a85;
	case 2697ULL: goto x86_l_a89;
	case 2703ULL: goto x86_l_a8f;
	case 2706ULL: goto x86_l_a92;
	case 2716ULL: goto x86_l_a9c;
	case 2720ULL: goto x86_l_aa0;
	case 2726ULL: goto x86_l_aa6;
	case 2731ULL: goto x86_l_aab;
	case 2742ULL: goto x86_l_ab6;
	case 2749ULL: goto x86_l_abd;
	case 2757ULL: goto x86_l_ac5;
	case 2762ULL: goto x86_l_aca;
	case 2764ULL: goto x86_l_acc;
	case 2767ULL: goto x86_l_acf;
	case 2769ULL: goto x86_l_ad1;
	case 2774ULL: goto x86_l_ad6;
	case 2779ULL: goto x86_l_adb;
	case 2782ULL: goto x86_l_ade;
	case 2786ULL: goto x86_l_ae2;
	case 2791ULL: goto x86_l_ae7;
	case 2797ULL: goto x86_l_aed;
	case 2801ULL: goto x86_l_af1;
	case 2806ULL: goto x86_l_af6;
	case 2811ULL: goto x86_l_afb;
	case 2817ULL: goto x86_l_b01;
	case 2821ULL: goto x86_l_b05;
	case 2827ULL: goto x86_l_b0b;
	case 2831ULL: goto x86_l_b0f;
	case 2834ULL: goto x86_l_b12;
	case 2840ULL: goto x86_l_b18;
	case 2845ULL: goto x86_l_b1d;
	case 2851ULL: goto x86_l_b23;
	case 2856ULL: goto x86_l_b28;
	case 2861ULL: goto x86_l_b2d;
	case 2866ULL: goto x86_l_b32;
	case 2871ULL: goto x86_l_b37;
	case 2876ULL: goto x86_l_b3c;
	case 2879ULL: goto x86_l_b3f;
	case 2884ULL: goto x86_l_b44;
	case 2889ULL: goto x86_l_b49;
	case 2894ULL: goto x86_l_b4e;
	case 2902ULL: goto x86_l_b56;
	case 2904ULL: goto x86_l_b58;
	case 2912ULL: goto x86_l_b60;
	case 2917ULL: goto x86_l_b65;
	case 2925ULL: goto x86_l_b6d;
	case 2930ULL: goto x86_l_b72;
	case 2932ULL: goto x86_l_b74;
	case 2935ULL: goto x86_l_b77;
	case 2937ULL: goto x86_l_b79;
	case 2945ULL: goto x86_l_b81;
	case 2948ULL: goto x86_l_b84;
	case 2955ULL: goto x86_l_b8b;
	case 2961ULL: goto x86_l_b91;
	case 2964ULL: goto x86_l_b94;
	case 2966ULL: goto x86_l_b96;
	case 2970ULL: goto x86_l_b9a;
	case 2973ULL: goto x86_l_b9d;
	case 2978ULL: goto x86_l_ba2;
	case 2984ULL: goto x86_l_ba8;
	case 2987ULL: goto x86_l_bab;
	case 2989ULL: goto x86_l_bad;
	case 2992ULL: goto x86_l_bb0;
	case 2994ULL: goto x86_l_bb2;
	case 2997ULL: goto x86_l_bb5;
	case 3002ULL: goto x86_l_bba;
	case 3007ULL: goto x86_l_bbf;
	case 3011ULL: goto x86_l_bc3;
	case 3018ULL: goto x86_l_bca;
	case 3023ULL: goto x86_l_bcf;
	case 3026ULL: goto x86_l_bd2;
	case 3028ULL: goto x86_l_bd4;
	case 3032ULL: goto x86_l_bd8;
	case 3037ULL: goto x86_l_bdd;
	case 3042ULL: goto x86_l_be2;
	case 3047ULL: goto x86_l_be7;
	case 3052ULL: goto x86_l_bec;
	case 3057ULL: goto x86_l_bf1;
	case 3059ULL: goto x86_l_bf3;
	case 3064ULL: goto x86_l_bf8;
	case 3068ULL: goto x86_l_bfc;
	case 3076ULL: goto x86_l_c04;
	case 3081ULL: goto x86_l_c09;
	case 3086ULL: goto x86_l_c0e;
	case 3091ULL: goto x86_l_c13;
	case 3095ULL: goto x86_l_c17;
	case 3100ULL: goto x86_l_c1c;
	case 3102ULL: goto x86_l_c1e;
	case 3110ULL: goto x86_l_c26;
	case 3115ULL: goto x86_l_c2b;
	case 3120ULL: goto x86_l_c30;
	case 3125ULL: goto x86_l_c35;
	case 3133ULL: goto x86_l_c3d;
	case 3138ULL: goto x86_l_c42;
	case 3140ULL: goto x86_l_c44;
	case 3145ULL: goto x86_l_c49;
	case 3150ULL: goto x86_l_c4e;
	case 3156ULL: goto x86_l_c54;
	case 3160ULL: goto x86_l_c58;
	case 3165ULL: goto x86_l_c5d;
	case 3170ULL: goto x86_l_c62;
	case 3174ULL: goto x86_l_c66;
	case 3177ULL: goto x86_l_c69;
	case 3179ULL: goto x86_l_c6b;
	case 3190ULL: goto x86_l_c76;
	case 3201ULL: goto x86_l_c81;
	case 3206ULL: goto x86_l_c86;
	case 3208ULL: goto x86_l_c88;
	case 3211ULL: goto x86_l_c8b;
	case 3216ULL: goto x86_l_c90;
	case 3223ULL: goto x86_l_c97;
	case 3227ULL: goto x86_l_c9b;
	case 3230ULL: goto x86_l_c9e;
	case 3232ULL: goto x86_l_ca0;
	case 3234ULL: goto x86_l_ca2;
	case 3238ULL: goto x86_l_ca6;
	case 3242ULL: goto x86_l_caa;
	case 3244ULL: goto x86_l_cac;
	case 3252ULL: goto x86_l_cb4;
	case 3259ULL: goto x86_l_cbb;
	case 3264ULL: goto x86_l_cc0;
	case 3269ULL: goto x86_l_cc5;
	case 3271ULL: goto x86_l_cc7;
	case 3274ULL: goto x86_l_cca;
	case 3276ULL: goto x86_l_ccc;
	case 3279ULL: goto x86_l_ccf;
	case 3286ULL: goto x86_l_cd6;
	case 3293ULL: goto x86_l_cdd;
	case 3298ULL: goto x86_l_ce2;
	case 3300ULL: goto x86_l_ce4;
	case 3303ULL: goto x86_l_ce7;
	case 3305ULL: goto x86_l_ce9;
	case 3308ULL: goto x86_l_cec;
	case 3311ULL: goto x86_l_cef;
	case 3314ULL: goto x86_l_cf2;
	case 3319ULL: goto x86_l_cf7;
	case 3321ULL: goto x86_l_cf9;
	case 3328ULL: goto x86_l_d00;
	case 3335ULL: goto x86_l_d07;
	case 3340ULL: goto x86_l_d0c;
	case 3345ULL: goto x86_l_d11;
	case 3348ULL: goto x86_l_d14;
	case 3353ULL: goto x86_l_d19;
	case 3355ULL: goto x86_l_d1b;
	case 3366ULL: goto x86_l_d26;
	case 3373ULL: goto x86_l_d2d;
	case 3378ULL: goto x86_l_d32;
	case 3383ULL: goto x86_l_d37;
	case 3386ULL: goto x86_l_d3a;
	case 3391ULL: goto x86_l_d3f;
	case 3393ULL: goto x86_l_d41;
	case 3395ULL: goto x86_l_d43;
	case 3402ULL: goto x86_l_d4a;
	case 3404ULL: goto x86_l_d4c;
	case 3405ULL: goto x86_l_d4d;
	case 3410ULL: goto x86_l_d52;
	case 3414ULL: goto x86_l_d56;
	case 3419ULL: goto x86_l_d5b;
	case 3424ULL: goto x86_l_d60;
	case 3428ULL: goto x86_l_d64;
	case 3434ULL: goto x86_l_d6a;
	case 3438ULL: goto x86_l_d6e;
	case 3444ULL: goto x86_l_d74;
	case 3448ULL: goto x86_l_d78;
	case 3454ULL: goto x86_l_d7e;
	case 3458ULL: goto x86_l_d82;
	case 3464ULL: goto x86_l_d88;
	case 3469ULL: goto x86_l_d8d;
	case 3473ULL: goto x86_l_d91;
	case 3478ULL: goto x86_l_d96;
	case 3482ULL: goto x86_l_d9a;
	case 3488ULL: goto x86_l_da0;
	case 3493ULL: goto x86_l_da5;
	case 3498ULL: goto x86_l_daa;
	case 3502ULL: goto x86_l_dae;
	case 3506ULL: goto x86_l_db2;
	case 3510ULL: goto x86_l_db6;
	case 3515ULL: goto x86_l_dbb;
	case 3520ULL: goto x86_l_dc0;
	case 3525ULL: goto x86_l_dc5;
	case 3527ULL: goto x86_l_dc7;
	case 3531ULL: goto x86_l_dcb;
	case 3535ULL: goto x86_l_dcf;
	case 3540ULL: goto x86_l_dd4;
	case 3545ULL: goto x86_l_dd9;
	case 3550ULL: goto x86_l_dde;
	case 3552ULL: goto x86_l_de0;
	case 3556ULL: goto x86_l_de4;
	case 3563ULL: goto x86_l_deb;
	case 3568ULL: goto x86_l_df0;
	case 3573ULL: goto x86_l_df5;
	case 3578ULL: goto x86_l_dfa;
	case 3580ULL: goto x86_l_dfc;
	case 3584ULL: goto x86_l_e00;
	case 3591ULL: goto x86_l_e07;
	case 3596ULL: goto x86_l_e0c;
	case 3601ULL: goto x86_l_e11;
	case 3606ULL: goto x86_l_e16;
	case 3608ULL: goto x86_l_e18;
	case 3612ULL: goto x86_l_e1c;
	case 3619ULL: goto x86_l_e23;
	default: return 0xffffffffffffffffULL;
	}
x86_l_713:
	/* 0x713: lea    r15,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_71b:
	/* 0x71b: lea    rbp,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_723:
	/* 0x723: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_728:
	/* 0x728: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_72b:
	/* 0x72b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_72d:
	/* 0x72d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_732:
	/* 0x732: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_737:
	/* 0x737: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_73c:
	/* 0x73c: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_73f:
	/* 0x73f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_744:
	/* 0x744: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_746:
	/* 0x746: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_74b:
	/* 0x74b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_750:
	/* 0x750: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_755:
	/* 0x755: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_758:
	/* 0x758: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_75d:
	/* 0x75d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_75f:
	/* 0x75f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_764:
	/* 0x764: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_769:
	/* 0x769: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_76e:
	/* 0x76e: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_771:
	/* 0x771: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_776:
	/* 0x776: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_778:
	/* 0x778: mov    rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_780:
	/* 0x780: add    rax,0xffffffffffffffe0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551584ULL);
x86_l_784:
	/* 0x784: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_78c:
	/* 0x78c: mov    rax,QWORD PTR [rip+0x2e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_793:
	/* 0x793: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_796:
	/* 0x796: je     987 <generic_fentry_process_event+0x987> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_987;
	}
x86_l_79c:
	/* 0x79c: mov    ebp,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2048ULL);
x86_l_7a1:
	/* 0x7a1: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_7a7:
	/* 0x7a7: mov    r13,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_7af:
	/* 0x7af: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_7b7:
	/* 0x7b7: mov    r12,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_7bf:
	/* 0x7bf: cmp    r13,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 104ULL);
x86_l_7c4:
	/* 0x7c4: jne    7d1 <generic_fentry_process_event+0x7d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_7d1;
	}
x86_l_7c6:
	/* 0x7c6: cmp    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_7cb:
	/* 0x7cb: je     b4e <generic_fentry_process_event+0xb4e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b4e;
	}
x86_l_7d1:
	/* 0x7d1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_7d6:
	/* 0x7d6: lea    rdi,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_7de:
	/* 0x7de: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7e3:
	/* 0x7e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7e5:
	/* 0x7e5: cmp    r13,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 208ULL);
x86_l_7ed:
	/* 0x7ed: mov    r14d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 8ULL);
x86_l_7f3:
	/* 0x7f3: je     912 <generic_fentry_process_event+0x912> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_912;
	}
x86_l_7f9:
	/* 0x7f9: lea    r15,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_7fd:
	/* 0x7fd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_802:
	/* 0x802: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_807:
	/* 0x807: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_80c:
	/* 0x80c: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_80f:
	/* 0x80f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_811:
	/* 0x811: cmp    QWORD PTR [rsp+0x58],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_816:
	/* 0x816: je     912 <generic_fentry_process_event+0x912> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_912;
	}
x86_l_81c:
	/* 0x81c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_821:
	/* 0x821: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_826:
	/* 0x826: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_82b:
	/* 0x82b: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_82e:
	/* 0x82e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_830:
	/* 0x830: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_834:
	/* 0x834: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_839:
	/* 0x839: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_841:
	/* 0x841: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_846:
	/* 0x846: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_84b:
	/* 0x84b: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_84e:
	/* 0x84e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_850:
	/* 0x850: mov    r15,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_855:
	/* 0x855: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_85d:
	/* 0x85d: mov    r12d,DWORD PTR [rsp+0xac] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_865:
	/* 0x865: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_868:
	/* 0x868: mov    r13d,DWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_870:
	/* 0x870: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_873:
	/* 0x873: sub    edx,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R13, X86_WIDTH_32, X86_ALU_SUB);
x86_l_876:
	/* 0x876: mov    ecx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 0ULL);
x86_l_87b:
	/* 0x87b: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_87e:
	/* 0x87e: add    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 176ULL);
x86_l_886:
	/* 0x886: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_888:
	/* 0x888: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_88b:
	/* 0x88b: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_88f:
	/* 0x88f: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_892:
	/* 0x892: cmovb  ecx,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_896:
	/* 0x896: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_898:
	/* 0x898: mov    edi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_32);
x86_l_89b:
	/* 0x89b: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_89d:
	/* 0x89d: mov    DWORD PTR [rsp+0xa0],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_8a4:
	/* 0x8a4: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_8a7:
	/* 0x8a7: mov    r14,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_8ac:
	/* 0x8ac: jb     b65 <generic_fentry_process_event+0xb65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_b65;
	}
x86_l_8b2:
	/* 0x8b2: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_8b8:
	/* 0x8b8: ja     b65 <generic_fentry_process_event+0xb65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_b65;
	}
x86_l_8be:
	/* 0x8be: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_8c1:
	/* 0x8c1: jbe    8c8 <generic_fentry_process_event+0x8c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_8c8;
	}
x86_l_8c3:
	/* 0x8c3: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_8c8:
	/* 0x8c8: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8ca:
	/* 0x8ca: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_8cd:
	/* 0x8cd: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_8d1:
	/* 0x8d1: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_8d4:
	/* 0x8d4: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_8d7:
	/* 0x8d7: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_8da:
	/* 0x8da: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_8df:
	/* 0x8df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8e1:
	/* 0x8e1: mov    QWORD PTR [rsp+0x98],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_8e9:
	/* 0x8e9: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_8ec:
	/* 0x8ec: jbe    b65 <generic_fentry_process_event+0xb65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_b65;
	}
x86_l_8f2:
	/* 0x8f2: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_8f7:
	/* 0x8f7: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_8ff:
	/* 0x8ff: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_905:
	/* 0x905: dec    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_907:
	/* 0x907: jne    7a7 <generic_fentry_process_event+0x7a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_7a7;
	}
x86_l_90d:
	/* 0x90d: jmp    b65 <generic_fentry_process_event+0xb65> */
	goto x86_l_b65;
x86_l_912:
	/* 0x912: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_917:
	/* 0x917: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_91c:
	/* 0x91c: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_921:
	/* 0x921: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_926:
	/* 0x926: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_928:
	/* 0x928: mov    rax,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_930:
	/* 0x930: cmp    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 88ULL);
x86_l_935:
	/* 0x935: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_93b:
	/* 0x93b: je     b58 <generic_fentry_process_event+0xb58> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b58;
	}
x86_l_941:
	/* 0x941: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_945:
	/* 0x945: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_94a:
	/* 0x94a: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_952:
	/* 0x952: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_957:
	/* 0x957: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_95a:
	/* 0x95a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_95c:
	/* 0x95c: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_961:
	/* 0x961: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_969:
	/* 0x969: add    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_96d:
	/* 0x96d: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_975:
	/* 0x975: mov    r14,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_97a:
	/* 0x97a: dec    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_97c:
	/* 0x97c: jne    7a7 <generic_fentry_process_event+0x7a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_7a7;
	}
x86_l_982:
	/* 0x982: jmp    b65 <generic_fentry_process_event+0xb65> */
	goto x86_l_b65;
x86_l_987:
	/* 0x987: lea    rsi,[rip+0x2e3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 739ULL);
x86_l_98e:
	/* 0x98e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_990:
	/* 0x990: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_995:
	/* 0x995: mov    edi,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 2048ULL);
x86_l_99a:
	/* 0x99a: mov    eax,0xb5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 181ULL);
x86_l_99f:
	/* 0x99f: mov    edi,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 2048ULL);
x86_l_9a4:
	/* 0x9a4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9a6:
	/* 0x9a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9a8:
	/* 0x9a8: jmp    b65 <generic_fentry_process_event+0xb65> */
	goto x86_l_b65;
x86_l_9ad:
	/* 0x9ad: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_9b5:
	/* 0x9b5: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_9ba:
	/* 0x9ba: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_9bf:
	/* 0x9bf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_9c4:
	/* 0x9c4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9c9:
	/* 0x9c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9cb:
	/* 0x9cb: mov    rax,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_9d3:
	/* 0x9d3: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_9d8:
	/* 0x9d8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9db:
	/* 0x9db: jne    574 <generic_fentry_process_event+0x574> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1396ULL;
	}
x86_l_9e1:
	/* 0x9e1: mov    DWORD PTR [rsp+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_9ec:
	/* 0x9ec: mov    rdi,QWORD PTR [rip+0x2e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_9f3:
	/* 0x9f3: lea    rsi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_9fb:
	/* 0x9fb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a00:
	/* 0xa00: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a02:
	/* 0xa02: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a05:
	/* 0xa05: je     b3c <generic_fentry_process_event+0xb3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b3c;
	}
x86_l_a0b:
	/* 0xa0b: mov    QWORD PTR [rsp+0x50],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_a10:
	/* 0xa10: mov    QWORD PTR [rsp+0x8],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a15:
	/* 0xa15: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a18:
	/* 0xa18: cmp    r13d,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 25ULL);
x86_l_a1c:
	/* 0xa1c: mov    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_a21:
	/* 0xa21: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a26:
	/* 0xa26: jg     f75 <generic_fentry_process_event+0xf75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3957ULL;
	}
x86_l_a2c:
	/* 0xa2c: cmp    r13d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 18ULL);
x86_l_a30:
	/* 0xa30: jle    10de <generic_fentry_process_event+0x10de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 4318ULL;
	}
x86_l_a36:
	/* 0xa36: cmp    r13d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 20ULL);
x86_l_a3a:
	/* 0xa3a: jle    1467 <generic_fentry_process_event+0x1467> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5223ULL;
	}
x86_l_a40:
	/* 0xa40: cmp    r13d,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 21ULL);
x86_l_a44:
	/* 0xa44: je     1cdb <generic_fentry_process_event+0x1cdb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7387ULL;
	}
x86_l_a4a:
	/* 0xa4a: cmp    r13d,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 22ULL);
x86_l_a4e:
	/* 0xa4e: je     1c51 <generic_fentry_process_event+0x1c51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7249ULL;
	}
x86_l_a54:
	/* 0xa54: cmp    r13d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 23ULL);
x86_l_a58:
	/* 0xa58: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a5d:
	/* 0xa5d: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a61:
	/* 0xa61: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a66:
	/* 0xa66: jne    c66 <generic_fentry_process_event+0xc66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_c66;
	}
x86_l_a6c:
	/* 0xa6c: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a71:
	/* 0xa71: mov    DWORD PTR [rax+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_a78:
	/* 0xa78: mov    DWORD PTR [rax],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a7a:
	/* 0xa7a: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_a80:
	/* 0xa80: jmp    c66 <generic_fentry_process_event+0xc66> */
	goto x86_l_c66;
x86_l_a85:
	/* 0xa85: cmp    r13d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 44ULL);
x86_l_a89:
	/* 0xa89: ja     9e1 <generic_fentry_process_event+0x9e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_9e1;
	}
x86_l_a8f:
	/* 0xa8f: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_a92:
	/* 0xa92: movabs rcx,0x11c1f2027cf2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19524686609650ULL);
x86_l_a9c:
	/* 0xa9c: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_aa0:
	/* 0xaa0: jae    9e1 <generic_fentry_process_event+0x9e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_9e1;
	}
x86_l_aa6:
	/* 0xaa6: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_aab:
	/* 0xaab: mov    DWORD PTR [rsp+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_ab6:
	/* 0xab6: mov    rdi,QWORD PTR [rip+0x2dd] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_abd:
	/* 0xabd: lea    rsi,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_ac5:
	/* 0xac5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_aca:
	/* 0xaca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_acc:
	/* 0xacc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_acf:
	/* 0xacf: je     b3c <generic_fentry_process_event+0xb3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b3c;
	}
x86_l_ad1:
	/* 0xad1: mov    QWORD PTR [rsp+0x50],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_ad6:
	/* 0xad6: mov    QWORD PTR [rsp+0x8],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_adb:
	/* 0xadb: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ade:
	/* 0xade: cmp    r13d,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 16ULL);
x86_l_ae2:
	/* 0xae2: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ae7:
	/* 0xae7: jle    d52 <generic_fentry_process_event+0xd52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_d52;
	}
x86_l_aed:
	/* 0xaed: cmp    r13d,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 30ULL);
x86_l_af1:
	/* 0xaf1: mov    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_af6:
	/* 0xaf6: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_afb:
	/* 0xafb: jle    ebd <generic_fentry_process_event+0xebd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3773ULL;
	}
x86_l_b01:
	/* 0xb01: cmp    r13d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 38ULL);
x86_l_b05:
	/* 0xb05: jg     fb6 <generic_fentry_process_event+0xfb6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 4022ULL;
	}
x86_l_b0b:
	/* 0xb0b: lea    eax,[r13-0x1f] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551585ULL);
x86_l_b0f:
	/* 0xb0f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_b12:
	/* 0xb12: jae    1555 <generic_fentry_process_event+0x1555> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 5461ULL;
	}
x86_l_b18:
	/* 0xb18: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_b1d:
	/* 0xb1d: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_b23:
	/* 0xb23: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_b28:
	/* 0xb28: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b2d:
	/* 0xb2d: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b32:
	/* 0xb32: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_b37:
	/* 0xb37: jmp    1177 <generic_fentry_process_event+0x1177> */
	return 4471ULL;
x86_l_b3c:
	/* 0xb3c: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b3f:
	/* 0xb3f: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b44:
	/* 0xb44: mov    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_b49:
	/* 0xb49: jmp    c5d <generic_fentry_process_event+0xc5d> */
	goto x86_l_c5d;
x86_l_b4e:
	/* 0xb4e: mov    BYTE PTR [rsp+0xa4],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 704374636545ULL);
x86_l_b56:
	/* 0xb56: jmp    b65 <generic_fentry_process_event+0xb65> */
	goto x86_l_b65;
x86_l_b58:
	/* 0xb58: mov    BYTE PTR [rsp+0xa4],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 704374636545ULL);
x86_l_b60:
	/* 0xb60: mov    r14,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b65:
	/* 0xb65: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_b6d:
	/* 0xb6d: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b72:
	/* 0xb72: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b74:
	/* 0xb74: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_b77:
	/* 0xb77: je     bb2 <generic_fentry_process_event+0xbb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bb2;
	}
x86_l_b79:
	/* 0xb79: cmp    BYTE PTR [rsp+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_b81:
	/* 0xb81: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_b84:
	/* 0xb84: mov    edx,DWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_b8b:
	/* 0xb8b: mov    r15d,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4096ULL);
x86_l_b91:
	/* 0xb91: sub    r15d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_b94:
	/* 0xb94: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_b96:
	/* 0xb96: cmovle r15d,edx */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RDX, X86_WIDTH_32, X86_CC_LE);
x86_l_b9a:
	/* 0xb9a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b9d:
	/* 0xb9d: mov    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_ba2:
	/* 0xba2: je     c88 <generic_fentry_process_event+0xc88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c88;
	}
x86_l_ba8:
	/* 0xba8: mov    bpl,cl */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RCX, X86_WIDTH_8);
x86_l_bab:
	/* 0xbab: add    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_bad:
	/* 0xbad: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_bb0:
	/* 0xbb0: jmp    bba <generic_fentry_process_event+0xbba> */
	goto x86_l_bba;
x86_l_bb2:
	/* 0xbb2: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bb5:
	/* 0xbb5: mov    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_bba:
	/* 0xbba: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bbf:
	/* 0xbbf: lea    rdi,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_bc3:
	/* 0xbc3: and    r15d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_bca:
	/* 0xbca: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_bcf:
	/* 0xbcf: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_bd2:
	/* 0xbd2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bd4:
	/* 0xbd4: mov    DWORD PTR [r13+0x0],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bd8:
	/* 0xbd8: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_bdd:
	/* 0xbdd: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_be2:
	/* 0xbe2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_be7:
	/* 0xbe7: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_bec:
	/* 0xbec: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bf1:
	/* 0xbf1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bf3:
	/* 0xbf3: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_bf8:
	/* 0xbf8: add    rcx,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_bfc:
	/* 0xbfc: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_c04:
	/* 0xc04: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_c09:
	/* 0xc09: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c0e:
	/* 0xc0e: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_c13:
	/* 0xc13: add    rdx,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_c17:
	/* 0xc17: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c1c:
	/* 0xc1c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c1e:
	/* 0xc1e: mov    rcx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_c26:
	/* 0xc26: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_c2b:
	/* 0xc2b: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_c30:
	/* 0xc30: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c35:
	/* 0xc35: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_c3d:
	/* 0xc3d: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_c42:
	/* 0xc42: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c44:
	/* 0xc44: mov    DWORD PTR [r13+r15*1+0x4],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 4ULL);
x86_l_c49:
	/* 0xc49: movzx  eax,WORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 88ULL);
x86_l_c4e:
	/* 0xc4e: mov    WORD PTR [r13+r15*1+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 8ULL);
x86_l_c54:
	/* 0xc54: add    r15d,0xa */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 10ULL);
x86_l_c58:
	/* 0xc58: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c5d:
	/* 0xc5d: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c62:
	/* 0xc62: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c66:
	/* 0xc66: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_c69:
	/* 0xc69: jns    c90 <generic_fentry_process_event+0xc90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_c90;
	}
x86_l_c6b:
	/* 0xc6b: mov    DWORD PTR [rcx+rsi*4+0x5ea0],0xffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 104045582745599ULL);
x86_l_c76:
	/* 0xc76: mov    DWORD PTR [rcx+rbp*1+0x90],0xffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 622770257919ULL);
x86_l_c81:
	/* 0xc81: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_c86:
	/* 0xc86: jmp    c9e <generic_fentry_process_event+0xc9e> */
	goto x86_l_c9e;
x86_l_c88:
	/* 0xc88: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c8b:
	/* 0xc8b: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c90:
	/* 0xc90: and    r15d,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_c97:
	/* 0xc97: add    r15d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_c9b:
	/* 0xc9b: mov    edx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_32);
x86_l_c9e:
	/* 0xc9e: add    edx,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_ca0:
	/* 0xca0: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_ca2:
	/* 0xca2: mov    DWORD PTR [r14+0x4],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ca6:
	/* 0xca6: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_caa:
	/* 0xcaa: jg     d1b <generic_fentry_process_event+0xd1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_d1b;
	}
x86_l_cac:
	/* 0xcac: mov    DWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_cb4:
	/* 0xcb4: mov    rdi,QWORD PTR [rip+0x2e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_cbb:
	/* 0xcbb: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_cc0:
	/* 0xcc0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_cc5:
	/* 0xcc5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cc7:
	/* 0xcc7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cca:
	/* 0xcca: je     d1b <generic_fentry_process_event+0xd1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1b;
	}
x86_l_ccc:
	/* 0xccc: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_ccf:
	/* 0xccf: add    rsi,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_cd6:
	/* 0xcd6: mov    rdi,QWORD PTR [rip+0x2dd] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_cdd:
	/* 0xcdd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ce2:
	/* 0xce2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ce4:
	/* 0xce4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ce7:
	/* 0xce7: je     d1b <generic_fentry_process_event+0xd1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1b;
	}
x86_l_ce9:
	/* 0xce9: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_cec:
	/* 0xcec: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_cef:
	/* 0xcef: and    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_cf2:
	/* 0xcf2: cmp    DWORD PTR [rax+rcx*4+0x40],0xffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 279172874239ULL);
x86_l_cf7:
	/* 0xcf7: je     d1b <generic_fentry_process_event+0xd1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1b;
	}
x86_l_cf9:
	/* 0xcf9: mov    DWORD PTR [r14+0x5efc],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24316ULL);
x86_l_d00:
	/* 0xd00: mov    rsi,QWORD PTR [rip+0x2e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&fentry_calls)));
x86_l_d07:
	/* 0xd07: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_d0c:
	/* 0xd0c: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_d11:
	/* 0xd11: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_d14:
	/* 0xd14: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_d19:
	/* 0xd19: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d1b:
	/* 0xd1b: mov    DWORD PTR [r14+0x5efc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104436424769536ULL);
x86_l_d26:
	/* 0xd26: mov    rsi,QWORD PTR [rip+0x2e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&fentry_calls)));
x86_l_d2d:
	/* 0xd2d: mov    ecx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_d32:
	/* 0xd32: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_d37:
	/* 0xd37: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_d3a:
	/* 0xd3a: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_d3f:
	/* 0xd3f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d41:
	/* 0xd41: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d43:
	/* 0xd43: add    rsp,0x108 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 264ULL);
x86_l_d4a:
	/* 0xd4a: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_d4c:
	/* 0xd4c: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_d4d:
	/* 0xd4d: jmp    397d <__do_bytes+0xc4> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_d52:
	/* 0xd52: cmp    r13d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 9ULL);
x86_l_d56:
	/* 0xd56: mov    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_d5b:
	/* 0xd5b: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d60:
	/* 0xd60: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d64:
	/* 0xd64: jg     ef3 <generic_fentry_process_event+0xef3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3827ULL;
	}
x86_l_d6a:
	/* 0xd6a: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_d6e:
	/* 0xd6e: jle    117e <generic_fentry_process_event+0x117e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 4478ULL;
	}
x86_l_d74:
	/* 0xd74: cmp    r13d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 5ULL);
x86_l_d78:
	/* 0xd78: je     1740 <generic_fentry_process_event+0x1740> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5952ULL;
	}
x86_l_d7e:
	/* 0xd7e: cmp    r13d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 6ULL);
x86_l_d82:
	/* 0xd82: je     f53 <generic_fentry_process_event+0xf53> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3923ULL;
	}
x86_l_d88:
	/* 0xd88: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d8d:
	/* 0xd8d: cmp    r13d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 7ULL);
x86_l_d91:
	/* 0xd91: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d96:
	/* 0xd96: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d9a:
	/* 0xd9a: jne    c66 <generic_fentry_process_event+0xc66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_c66;
	}
x86_l_da0:
	/* 0xda0: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_da5:
	/* 0xda5: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_daa:
	/* 0xdaa: mov    QWORD PTR [r13+0x28],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_dae:
	/* 0xdae: lea    rdi,[r13+0x26] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_db2:
	/* 0xdb2: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_db6:
	/* 0xdb6: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_dbb:
	/* 0xdbb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_dc0:
	/* 0xdc0: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_dc5:
	/* 0xdc5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dc7:
	/* 0xdc7: lea    rdi,[r13+0x3a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_dcb:
	/* 0xdcb: lea    rdx,[r15+0x12] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_dcf:
	/* 0xdcf: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_dd4:
	/* 0xdd4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_dd9:
	/* 0xdd9: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_dde:
	/* 0xdde: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_de0:
	/* 0xde0: lea    rdi,[r13+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_de4:
	/* 0xde4: lea    rdx,[r15+0x23c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_deb:
	/* 0xdeb: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_df0:
	/* 0xdf0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_df5:
	/* 0xdf5: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_dfa:
	/* 0xdfa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dfc:
	/* 0xdfc: lea    rdi,[r13+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_e00:
	/* 0xe00: lea    rdx,[r15+0x23e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 574ULL);
x86_l_e07:
	/* 0xe07: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_e0c:
	/* 0xe0c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e11:
	/* 0xe11: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_e16:
	/* 0xe16: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e18:
	/* 0xe18: lea    rdi,[r13+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e1c:
	/* 0xe1c: lea    rdx,[r15+0x20c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_e23:
	/* 0xe23: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
	return 3624ULL;
}

static __noinline __u64 tetragon_bpf_generic_fentry_v61_generic_fentry_process_event_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3624ULL: goto x86_l_e28;
	case 3629ULL: goto x86_l_e2d;
	case 3634ULL: goto x86_l_e32;
	case 3636ULL: goto x86_l_e34;
	case 3640ULL: goto x86_l_e38;
	case 3647ULL: goto x86_l_e3f;
	case 3652ULL: goto x86_l_e44;
	case 3657ULL: goto x86_l_e49;
	case 3662ULL: goto x86_l_e4e;
	case 3664ULL: goto x86_l_e50;
	case 3668ULL: goto x86_l_e54;
	case 3676ULL: goto x86_l_e5c;
	case 3684ULL: goto x86_l_e64;
	case 3692ULL: goto x86_l_e6c;
	case 3700ULL: goto x86_l_e74;
	case 3705ULL: goto x86_l_e79;
	case 3708ULL: goto x86_l_e7c;
	case 3714ULL: goto x86_l_e82;
	case 3717ULL: goto x86_l_e85;
	case 3723ULL: goto x86_l_e8b;
	case 3727ULL: goto x86_l_e8f;
	case 3732ULL: goto x86_l_e94;
	case 3737ULL: goto x86_l_e99;
	case 3740ULL: goto x86_l_e9c;
	case 3745ULL: goto x86_l_ea1;
	case 3747ULL: goto x86_l_ea3;
	case 3752ULL: goto x86_l_ea8;
	case 3757ULL: goto x86_l_ead;
	case 3760ULL: goto x86_l_eb0;
	case 3765ULL: goto x86_l_eb5;
	case 3768ULL: goto x86_l_eb8;
	case 3773ULL: goto x86_l_ebd;
	case 3777ULL: goto x86_l_ec1;
	case 3783ULL: goto x86_l_ec7;
	case 3787ULL: goto x86_l_ecb;
	case 3793ULL: goto x86_l_ed1;
	case 3797ULL: goto x86_l_ed5;
	case 3803ULL: goto x86_l_edb;
	case 3807ULL: goto x86_l_edf;
	case 3812ULL: goto x86_l_ee4;
	case 3816ULL: goto x86_l_ee8;
	case 3822ULL: goto x86_l_eee;
	case 3827ULL: goto x86_l_ef3;
	case 3831ULL: goto x86_l_ef7;
	case 3834ULL: goto x86_l_efa;
	case 3840ULL: goto x86_l_f00;
	case 3844ULL: goto x86_l_f04;
	case 3847ULL: goto x86_l_f07;
	case 3853ULL: goto x86_l_f0d;
	case 3857ULL: goto x86_l_f11;
	case 3863ULL: goto x86_l_f17;
	case 3868ULL: goto x86_l_f1c;
	case 3873ULL: goto x86_l_f21;
	case 3878ULL: goto x86_l_f26;
	case 3883ULL: goto x86_l_f2b;
	case 3888ULL: goto x86_l_f30;
	case 3891ULL: goto x86_l_f33;
	case 3893ULL: goto x86_l_f35;
	case 3898ULL: goto x86_l_f3a;
	case 3903ULL: goto x86_l_f3f;
	case 3908ULL: goto x86_l_f44;
	case 3913ULL: goto x86_l_f49;
	case 3916ULL: goto x86_l_f4c;
	case 3921ULL: goto x86_l_f51;
	case 3923ULL: goto x86_l_f53;
	case 3928ULL: goto x86_l_f58;
	case 3933ULL: goto x86_l_f5d;
	case 3937ULL: goto x86_l_f61;
	case 3942ULL: goto x86_l_f66;
	case 3947ULL: goto x86_l_f6b;
	case 3952ULL: goto x86_l_f70;
	case 3957ULL: goto x86_l_f75;
	case 3961ULL: goto x86_l_f79;
	case 3966ULL: goto x86_l_f7e;
	case 3972ULL: goto x86_l_f84;
	case 3975ULL: goto x86_l_f87;
	case 3979ULL: goto x86_l_f8b;
	case 3982ULL: goto x86_l_f8e;
	case 3988ULL: goto x86_l_f94;
	case 3994ULL: goto x86_l_f9a;
	case 3999ULL: goto x86_l_f9f;
	case 4004ULL: goto x86_l_fa4;
	case 4009ULL: goto x86_l_fa9;
	case 4014ULL: goto x86_l_fae;
	case 4017ULL: goto x86_l_fb1;
	case 4022ULL: goto x86_l_fb6;
	case 4026ULL: goto x86_l_fba;
	case 4032ULL: goto x86_l_fc0;
	case 4036ULL: goto x86_l_fc4;
	case 4042ULL: goto x86_l_fca;
	case 4046ULL: goto x86_l_fce;
	case 4050ULL: goto x86_l_fd2;
	case 4056ULL: goto x86_l_fd8;
	case 4061ULL: goto x86_l_fdd;
	case 4066ULL: goto x86_l_fe2;
	case 4071ULL: goto x86_l_fe7;
	case 4079ULL: goto x86_l_fef;
	case 4087ULL: goto x86_l_ff7;
	case 4095ULL: goto x86_l_fff;
	case 4103ULL: goto x86_l_1007;
	case 4111ULL: goto x86_l_100f;
	case 4119ULL: goto x86_l_1017;
	case 4127ULL: goto x86_l_101f;
	case 4135ULL: goto x86_l_1027;
	case 4143ULL: goto x86_l_102f;
	case 4151ULL: goto x86_l_1037;
	case 4159ULL: goto x86_l_103f;
	case 4167ULL: goto x86_l_1047;
	case 4175ULL: goto x86_l_104f;
	case 4182ULL: goto x86_l_1056;
	case 4187ULL: goto x86_l_105b;
	case 4192ULL: goto x86_l_1060;
	case 4197ULL: goto x86_l_1065;
	case 4200ULL: goto x86_l_1068;
	case 4202ULL: goto x86_l_106a;
	case 4205ULL: goto x86_l_106d;
	case 4211ULL: goto x86_l_1073;
	case 4215ULL: goto x86_l_1077;
	case 4220ULL: goto x86_l_107c;
	case 4225ULL: goto x86_l_1081;
	case 4230ULL: goto x86_l_1086;
	case 4235ULL: goto x86_l_108b;
	case 4238ULL: goto x86_l_108e;
	case 4240ULL: goto x86_l_1090;
	case 4243ULL: goto x86_l_1093;
	case 4249ULL: goto x86_l_1099;
	case 4254ULL: goto x86_l_109e;
	case 4258ULL: goto x86_l_10a2;
	case 4263ULL: goto x86_l_10a7;
	case 4267ULL: goto x86_l_10ab;
	case 4273ULL: goto x86_l_10b1;
	case 4278ULL: goto x86_l_10b6;
	case 4283ULL: goto x86_l_10bb;
	case 4288ULL: goto x86_l_10c0;
	case 4291ULL: goto x86_l_10c3;
	case 4293ULL: goto x86_l_10c5;
	case 4295ULL: goto x86_l_10c7;
	case 4300ULL: goto x86_l_10cc;
	case 4305ULL: goto x86_l_10d1;
	case 4311ULL: goto x86_l_10d7;
	case 4313ULL: goto x86_l_10d9;
	case 4318ULL: goto x86_l_10de;
	case 4322ULL: goto x86_l_10e2;
	case 4328ULL: goto x86_l_10e8;
	case 4331ULL: goto x86_l_10eb;
	case 4335ULL: goto x86_l_10ef;
	case 4341ULL: goto x86_l_10f5;
	case 4346ULL: goto x86_l_10fa;
	case 4350ULL: goto x86_l_10fe;
	case 4355ULL: goto x86_l_1103;
	case 4359ULL: goto x86_l_1107;
	case 4365ULL: goto x86_l_110d;
	case 4368ULL: goto x86_l_1110;
	case 4373ULL: goto x86_l_1115;
	case 4380ULL: goto x86_l_111c;
	case 4385ULL: goto x86_l_1121;
	case 4388ULL: goto x86_l_1124;
	case 4391ULL: goto x86_l_1127;
	case 4397ULL: goto x86_l_112d;
	case 4400ULL: goto x86_l_1130;
	case 4406ULL: goto x86_l_1136;
	case 4409ULL: goto x86_l_1139;
	case 4415ULL: goto x86_l_113f;
	case 4418ULL: goto x86_l_1142;
	case 4424ULL: goto x86_l_1148;
	case 4429ULL: goto x86_l_114d;
	case 4435ULL: goto x86_l_1153;
	case 4440ULL: goto x86_l_1158;
	case 4445ULL: goto x86_l_115d;
	case 4451ULL: goto x86_l_1163;
	case 4456ULL: goto x86_l_1168;
	case 4461ULL: goto x86_l_116d;
	case 4466ULL: goto x86_l_1172;
	case 4471ULL: goto x86_l_1177;
	case 4473ULL: goto x86_l_1179;
	case 4478ULL: goto x86_l_117e;
	case 4482ULL: goto x86_l_1182;
	case 4484ULL: goto x86_l_1184;
	case 4488ULL: goto x86_l_1188;
	case 4494ULL: goto x86_l_118e;
	case 4500ULL: goto x86_l_1194;
	case 4505ULL: goto x86_l_1199;
	case 4510ULL: goto x86_l_119e;
	case 4515ULL: goto x86_l_11a3;
	case 4520ULL: goto x86_l_11a8;
	case 4525ULL: goto x86_l_11ad;
	case 4527ULL: goto x86_l_11af;
	case 4532ULL: goto x86_l_11b4;
	case 4538ULL: goto x86_l_11ba;
	case 4543ULL: goto x86_l_11bf;
	case 4548ULL: goto x86_l_11c4;
	case 4553ULL: goto x86_l_11c9;
	case 4558ULL: goto x86_l_11ce;
	case 4560ULL: goto x86_l_11d0;
	case 4564ULL: goto x86_l_11d4;
	case 4569ULL: goto x86_l_11d9;
	case 4574ULL: goto x86_l_11de;
	case 4579ULL: goto x86_l_11e3;
	case 4583ULL: goto x86_l_11e7;
	case 4589ULL: goto x86_l_11ed;
	case 4593ULL: goto x86_l_11f1;
	case 4598ULL: goto x86_l_11f6;
	case 4602ULL: goto x86_l_11fa;
	case 4608ULL: goto x86_l_1200;
	case 4611ULL: goto x86_l_1203;
	case 4615ULL: goto x86_l_1207;
	case 4620ULL: goto x86_l_120c;
	case 4626ULL: goto x86_l_1212;
	case 4631ULL: goto x86_l_1217;
	case 4636ULL: goto x86_l_121c;
	case 4641ULL: goto x86_l_1221;
	case 4644ULL: goto x86_l_1224;
	case 4646ULL: goto x86_l_1226;
	case 4651ULL: goto x86_l_122b;
	case 4654ULL: goto x86_l_122e;
	case 4660ULL: goto x86_l_1234;
	case 4665ULL: goto x86_l_1239;
	case 4669ULL: goto x86_l_123d;
	case 4673ULL: goto x86_l_1241;
	case 4677ULL: goto x86_l_1245;
	case 4682ULL: goto x86_l_124a;
	case 4687ULL: goto x86_l_124f;
	case 4692ULL: goto x86_l_1254;
	case 4694ULL: goto x86_l_1256;
	case 4698ULL: goto x86_l_125a;
	case 4702ULL: goto x86_l_125e;
	case 4707ULL: goto x86_l_1263;
	case 4712ULL: goto x86_l_1268;
	case 4717ULL: goto x86_l_126d;
	case 4719ULL: goto x86_l_126f;
	case 4723ULL: goto x86_l_1273;
	case 4730ULL: goto x86_l_127a;
	case 4735ULL: goto x86_l_127f;
	case 4740ULL: goto x86_l_1284;
	case 4745ULL: goto x86_l_1289;
	case 4747ULL: goto x86_l_128b;
	case 4751ULL: goto x86_l_128f;
	case 4758ULL: goto x86_l_1296;
	case 4763ULL: goto x86_l_129b;
	case 4768ULL: goto x86_l_12a0;
	case 4773ULL: goto x86_l_12a5;
	case 4775ULL: goto x86_l_12a7;
	case 4779ULL: goto x86_l_12ab;
	case 4786ULL: goto x86_l_12b2;
	case 4791ULL: goto x86_l_12b7;
	case 4796ULL: goto x86_l_12bc;
	case 4798ULL: goto x86_l_12be;
	case 4802ULL: goto x86_l_12c2;
	case 4809ULL: goto x86_l_12c9;
	case 4814ULL: goto x86_l_12ce;
	case 4819ULL: goto x86_l_12d3;
	case 4821ULL: goto x86_l_12d5;
	case 4825ULL: goto x86_l_12d9;
	case 4833ULL: goto x86_l_12e1;
	case 4841ULL: goto x86_l_12e9;
	case 4849ULL: goto x86_l_12f1;
	case 4857ULL: goto x86_l_12f9;
	case 4861ULL: goto x86_l_12fd;
	case 4864ULL: goto x86_l_1300;
	case 4870ULL: goto x86_l_1306;
	case 4873ULL: goto x86_l_1309;
	case 4879ULL: goto x86_l_130f;
	case 4883ULL: goto x86_l_1313;
	case 4888ULL: goto x86_l_1318;
	case 4893ULL: goto x86_l_131d;
	case 4898ULL: goto x86_l_1322;
	case 4903ULL: goto x86_l_1327;
	case 4905ULL: goto x86_l_1329;
	case 4910ULL: goto x86_l_132e;
	case 4915ULL: goto x86_l_1333;
	case 4918ULL: goto x86_l_1336;
	case 4923ULL: goto x86_l_133b;
	case 4926ULL: goto x86_l_133e;
	case 4931ULL: goto x86_l_1343;
	case 4935ULL: goto x86_l_1347;
	case 4941ULL: goto x86_l_134d;
	case 4945ULL: goto x86_l_1351;
	case 4950ULL: goto x86_l_1356;
	case 4954ULL: goto x86_l_135a;
	case 4960ULL: goto x86_l_1360;
	case 4963ULL: goto x86_l_1363;
	case 4966ULL: goto x86_l_1366;
	case 4971ULL: goto x86_l_136b;
	case 4979ULL: goto x86_l_1373;
	case 4987ULL: goto x86_l_137b;
	case 4995ULL: goto x86_l_1383;
	case 5003ULL: goto x86_l_138b;
	case 5011ULL: goto x86_l_1393;
	case 5019ULL: goto x86_l_139b;
	case 5027ULL: goto x86_l_13a3;
	case 5035ULL: goto x86_l_13ab;
	case 5043ULL: goto x86_l_13b3;
	case 5050ULL: goto x86_l_13ba;
	case 5054ULL: goto x86_l_13be;
	case 5058ULL: goto x86_l_13c2;
	case 5063ULL: goto x86_l_13c7;
	case 5068ULL: goto x86_l_13cc;
	case 5073ULL: goto x86_l_13d1;
	case 5075ULL: goto x86_l_13d3;
	case 5078ULL: goto x86_l_13d6;
	case 5084ULL: goto x86_l_13dc;
	case 5089ULL: goto x86_l_13e1;
	case 5093ULL: goto x86_l_13e5;
	case 5098ULL: goto x86_l_13ea;
	case 5105ULL: goto x86_l_13f1;
	case 5110ULL: goto x86_l_13f6;
	case 5115ULL: goto x86_l_13fb;
	case 5120ULL: goto x86_l_1400;
	case 5122ULL: goto x86_l_1402;
	case 5128ULL: goto x86_l_1408;
	case 5133ULL: goto x86_l_140d;
	case 5136ULL: goto x86_l_1410;
	case 5140ULL: goto x86_l_1414;
	case 5146ULL: goto x86_l_141a;
	case 5150ULL: goto x86_l_141e;
	case 5155ULL: goto x86_l_1423;
	case 5158ULL: goto x86_l_1426;
	case 5163ULL: goto x86_l_142b;
	case 5167ULL: goto x86_l_142f;
	case 5172ULL: goto x86_l_1434;
	case 5178ULL: goto x86_l_143a;
	case 5183ULL: goto x86_l_143f;
	case 5190ULL: goto x86_l_1446;
	case 5193ULL: goto x86_l_1449;
	case 5198ULL: goto x86_l_144e;
	case 5203ULL: goto x86_l_1453;
	case 5206ULL: goto x86_l_1456;
	case 5208ULL: goto x86_l_1458;
	case 5212ULL: goto x86_l_145c;
	case 5215ULL: goto x86_l_145f;
	case 5218ULL: goto x86_l_1462;
	case 5223ULL: goto x86_l_1467;
	case 5227ULL: goto x86_l_146b;
	case 5233ULL: goto x86_l_1471;
	case 5237ULL: goto x86_l_1475;
	case 5242ULL: goto x86_l_147a;
	case 5246ULL: goto x86_l_147e;
	case 5251ULL: goto x86_l_1483;
	case 5257ULL: goto x86_l_1489;
	case 5266ULL: goto x86_l_1492;
	case 5273ULL: goto x86_l_1499;
	case 5278ULL: goto x86_l_149e;
	case 5283ULL: goto x86_l_14a3;
	case 5288ULL: goto x86_l_14a8;
	case 5295ULL: goto x86_l_14af;
	case 5300ULL: goto x86_l_14b4;
	case 5303ULL: goto x86_l_14b7;
	case 5305ULL: goto x86_l_14b9;
	case 5310ULL: goto x86_l_14be;
	case 5315ULL: goto x86_l_14c3;
	case 5320ULL: goto x86_l_14c8;
	case 5325ULL: goto x86_l_14cd;
	case 5330ULL: goto x86_l_14d2;
	case 5333ULL: goto x86_l_14d5;
	case 5338ULL: goto x86_l_14da;
	case 5340ULL: goto x86_l_14dc;
	case 5347ULL: goto x86_l_14e3;
	case 5352ULL: goto x86_l_14e8;
	case 5357ULL: goto x86_l_14ed;
	case 5362ULL: goto x86_l_14f2;
	case 5365ULL: goto x86_l_14f5;
	case 5367ULL: goto x86_l_14f7;
	case 5374ULL: goto x86_l_14fe;
	case 5382ULL: goto x86_l_1506;
	case 5387ULL: goto x86_l_150b;
	case 5392ULL: goto x86_l_1510;
	case 5397ULL: goto x86_l_1515;
	case 5399ULL: goto x86_l_1517;
	case 5406ULL: goto x86_l_151e;
	case 5413ULL: goto x86_l_1525;
	case 5418ULL: goto x86_l_152a;
	case 5423ULL: goto x86_l_152f;
	case 5426ULL: goto x86_l_1532;
	case 5431ULL: goto x86_l_1537;
	case 5434ULL: goto x86_l_153a;
	case 5436ULL: goto x86_l_153c;
	case 5440ULL: goto x86_l_1540;
	case 5445ULL: goto x86_l_1545;
	case 5450ULL: goto x86_l_154a;
	case 5456ULL: goto x86_l_1550;
	case 5461ULL: goto x86_l_1555;
	case 5465ULL: goto x86_l_1559;
	case 5469ULL: goto x86_l_155d;
	case 5475ULL: goto x86_l_1563;
	default: return 0xffffffffffffffffULL;
	}
x86_l_e28:
	/* 0xe28: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e2d:
	/* 0xe2d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_e32:
	/* 0xe32: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e34:
	/* 0xe34: lea    rdi,[r13+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_e38:
	/* 0xe38: lea    rdx,[r15+0x208] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_e3f:
	/* 0xe3f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_e44:
	/* 0xe44: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e49:
	/* 0xe49: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_e4e:
	/* 0xe4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e50:
	/* 0xe50: lea    r12,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e54:
	/* 0xe54: mov    QWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e5c:
	/* 0xe5c: mov    QWORD PTR [r13+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_e64:
	/* 0xe64: mov    QWORD PTR [r13+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_e6c:
	/* 0xe6c: mov    QWORD PTR [r13+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_e74:
	/* 0xe74: movzx  eax,WORD PTR [r13+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_e79:
	/* 0xe79: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_e7c:
	/* 0xe7c: je     2038 <generic_fentry_process_event+0x2038> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8248ULL;
	}
x86_l_e82:
	/* 0xe82: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_e85:
	/* 0xe85: jne    2068 <generic_fentry_process_event+0x2068> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8296ULL;
	}
x86_l_e8b:
	/* 0xe8b: lea    rdx,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_e8f:
	/* 0xe8f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_e94:
	/* 0xe94: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e99:
	/* 0xe99: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_e9c:
	/* 0xe9c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ea1:
	/* 0xea1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ea3:
	/* 0xea3: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_ea8:
	/* 0xea8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ead:
	/* 0xead: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_eb0:
	/* 0xeb0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_eb5:
	/* 0xeb5: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_eb8:
	/* 0xeb8: jmp    2066 <generic_fentry_process_event+0x2066> */
	return 8294ULL;
x86_l_ebd:
	/* 0xebd: cmp    r13d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 28ULL);
x86_l_ec1:
	/* 0xec1: jg     1158 <generic_fentry_process_event+0x1158> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1158;
	}
x86_l_ec7:
	/* 0xec7: cmp    r13d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 17ULL);
x86_l_ecb:
	/* 0xecb: je     158c <generic_fentry_process_event+0x158c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5516ULL;
	}
x86_l_ed1:
	/* 0xed1: cmp    r13d,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 25ULL);
x86_l_ed5:
	/* 0xed5: je     1655 <generic_fentry_process_event+0x1655> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5717ULL;
	}
x86_l_edb:
	/* 0xedb: cmp    r13d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 28ULL);
x86_l_edf:
	/* 0xedf: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ee4:
	/* 0xee4: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ee8:
	/* 0xee8: je     118e <generic_fentry_process_event+0x118e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_118e;
	}
x86_l_eee:
	/* 0xeee: jmp    c66 <generic_fentry_process_event+0xc66> */
	return 3174ULL;
x86_l_ef3:
	/* 0xef3: lea    eax,[r13-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_ef7:
	/* 0xef7: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_efa:
	/* 0xefa: jb     118e <generic_fentry_process_event+0x118e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_118e;
	}
x86_l_f00:
	/* 0xf00: lea    eax,[r13-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_f04:
	/* 0xf04: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_f07:
	/* 0xf07: jb     11af <generic_fentry_process_event+0x11af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_11af;
	}
x86_l_f0d:
	/* 0xf0d: cmp    r13d,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 14ULL);
x86_l_f11:
	/* 0xf11: jne    c66 <generic_fentry_process_event+0xc66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3174ULL;
	}
x86_l_f17:
	/* 0xf17: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_f1c:
	/* 0xf1c: lea    r15,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_f21:
	/* 0xf21: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_f26:
	/* 0xf26: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f2b:
	/* 0xf2b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f30:
	/* 0xf30: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_f33:
	/* 0xf33: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f35:
	/* 0xf35: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_f3a:
	/* 0xf3a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_f3f:
	/* 0xf3f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f44:
	/* 0xf44: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_f49:
	/* 0xf49: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_f4c:
	/* 0xf4c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f51:
	/* 0xf51: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f53:
	/* 0xf53: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_f58:
	/* 0xf58: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f5d:
	/* 0xf5d: lea    rdi,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_f61:
	/* 0xf61: mov    ecx,0x1001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4097ULL);
x86_l_f66:
	/* 0xf66: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_f6b:
	/* 0xf6b: mov    esi,0x1001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4097ULL);
x86_l_f70:
	/* 0xf70: jmp    1926 <generic_fentry_process_event+0x1926> */
	return 6438ULL;
x86_l_f75:
	/* 0xf75: cmp    r13d,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 32ULL);
x86_l_f79:
	/* 0xf79: mov    r8,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f7e:
	/* 0xf7e: jle    1343 <generic_fentry_process_event+0x1343> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1343;
	}
x86_l_f84:
	/* 0xf84: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_f87:
	/* 0xf87: lea    eax,[r13-0x21] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551583ULL);
x86_l_f8b:
	/* 0xf8b: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f8e:
	/* 0xf8e: jae    11de <generic_fentry_process_event+0x11de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_11de;
	}
x86_l_f94:
	/* 0xf94: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_f9a:
	/* 0xf9a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_f9f:
	/* 0xf9f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_fa4:
	/* 0xfa4: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fa9:
	/* 0xfa9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_fae:
	/* 0xfae: mov    rdx,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R8, X86_WIDTH_64);
x86_l_fb1:
	/* 0xfb1: jmp    1177 <generic_fentry_process_event+0x1177> */
	goto x86_l_1177;
x86_l_fb6:
	/* 0xfb6: cmp    r13d,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 39ULL);
x86_l_fba:
	/* 0xfba: je     1904 <generic_fentry_process_event+0x1904> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6404ULL;
	}
x86_l_fc0:
	/* 0xfc0: cmp    r13d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 40ULL);
x86_l_fc4:
	/* 0xfc4: je     1945 <generic_fentry_process_event+0x1945> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6469ULL;
	}
x86_l_fca:
	/* 0xfca: cmp    r13d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 44ULL);
x86_l_fce:
	/* 0xfce: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fd2:
	/* 0xfd2: jne    c66 <generic_fentry_process_event+0xc66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3174ULL;
	}
x86_l_fd8:
	/* 0xfd8: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_fdd:
	/* 0xfdd: mov    BYTE PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_fe2:
	/* 0xfe2: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fe7:
	/* 0xfe7: mov    QWORD PTR [rdi+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_fef:
	/* 0xfef: mov    QWORD PTR [rdi+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_ff7:
	/* 0xff7: mov    QWORD PTR [rdi+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_fff:
	/* 0xfff: mov    QWORD PTR [rdi+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_1007:
	/* 0x1007: mov    QWORD PTR [rdi+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_100f:
	/* 0x100f: mov    QWORD PTR [rdi+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1017:
	/* 0x1017: mov    QWORD PTR [rdi+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_101f:
	/* 0x101f: mov    QWORD PTR [rdi+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1027:
	/* 0x1027: mov    QWORD PTR [rdi+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_102f:
	/* 0x102f: mov    QWORD PTR [rdi+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1037:
	/* 0x1037: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_103f:
	/* 0x103f: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1047:
	/* 0x1047: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_104f:
	/* 0x104f: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1056:
	/* 0x1056: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_105b:
	/* 0x105b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1060:
	/* 0x1060: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1065:
	/* 0x1065: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1068:
	/* 0x1068: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_106a:
	/* 0x106a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_106d:
	/* 0x106d: js     235c <generic_fentry_process_event+0x235c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9052ULL;
	}
x86_l_1073:
	/* 0x1073: lea    r12,[r15+0x2] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_1077:
	/* 0x1077: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_107c:
	/* 0x107c: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1081:
	/* 0x1081: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1086:
	/* 0x1086: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_108b:
	/* 0x108b: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_108e:
	/* 0x108e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1090:
	/* 0x1090: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1093:
	/* 0x1093: js     235c <generic_fentry_process_event+0x235c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9052ULL;
	}
x86_l_1099:
	/* 0x1099: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_109e:
	/* 0x109e: lea    rdi,[rax+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_10a2:
	/* 0x10a2: cmp    BYTE PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_10a7:
	/* 0x10a7: sete   BYTE PTR [rax+0x2] */
	X86_SIM_L_EXEC_SETCC_MEM(X86_RAX, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_REG_AUX_SRC_SHIFT(X86_CC_E)), 2ULL);
x86_l_10ab:
	/* 0x10ab: je     2329 <generic_fentry_process_event+0x2329> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9001ULL;
	}
x86_l_10b1:
	/* 0x10b1: mov    ecx,0x6c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 108ULL);
x86_l_10b6:
	/* 0x10b6: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_10bb:
	/* 0x10bb: mov    esi,0x6c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 108ULL);
x86_l_10c0:
	/* 0x10c0: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_10c3:
	/* 0x10c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10c5:
	/* 0x10c5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_10c7:
	/* 0x10c7: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_10cc:
	/* 0x10cc: mov    r14,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_10d1:
	/* 0x10d1: js     235c <generic_fentry_process_event+0x235c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9052ULL;
	}
x86_l_10d7:
	/* 0x10d7: dec    al */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_DEC, 1);
x86_l_10d9:
	/* 0x10d9: jmp    2354 <generic_fentry_process_event+0x2354> */
	return 9044ULL;
x86_l_10de:
	/* 0x10de: cmp    r13d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 7ULL);
x86_l_10e2:
	/* 0x10e2: jg     140d <generic_fentry_process_event+0x140d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_140d;
	}
x86_l_10e8:
	/* 0x10e8: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_10eb:
	/* 0x10eb: cmp    r13d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 2ULL);
x86_l_10ef:
	/* 0x10ef: je     19dc <generic_fentry_process_event+0x19dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6620ULL;
	}
x86_l_10f5:
	/* 0x10f5: mov    QWORD PTR [rsp+0x30],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10fa:
	/* 0x10fa: cmp    r13d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 3ULL);
x86_l_10fe:
	/* 0x10fe: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1103:
	/* 0x1103: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1107:
	/* 0x1107: jne    c66 <generic_fentry_process_event+0xc66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3174ULL;
	}
x86_l_110d:
	/* 0x110d: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_1110:
	/* 0x1110: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1115:
	/* 0x1115: lea    r12,[rax+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_111c:
	/* 0x111c: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1121:
	/* 0x1121: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1124:
	/* 0x1124: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1127:
	/* 0x1127: jle    21c5 <generic_fentry_process_event+0x21c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 8645ULL;
	}
x86_l_112d:
	/* 0x112d: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1130:
	/* 0x1130: je     2454 <generic_fentry_process_event+0x2454> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9300ULL;
	}
x86_l_1136:
	/* 0x1136: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1139:
	/* 0x1139: je     2461 <generic_fentry_process_event+0x2461> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9313ULL;
	}
x86_l_113f:
	/* 0x113f: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_1142:
	/* 0x1142: jne    28ae <generic_fentry_process_event+0x28ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10414ULL;
	}
x86_l_1148:
	/* 0x1148: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_114d:
	/* 0x114d: add    rax,0x5e70 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24176ULL);
x86_l_1153:
	/* 0x1153: jmp    2479 <generic_fentry_process_event+0x2479> */
	return 9337ULL;
x86_l_1158:
	/* 0x1158: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_115d:
	/* 0x115d: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_1163:
	/* 0x1163: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1168:
	/* 0x1168: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_116d:
	/* 0x116d: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1172:
	/* 0x1172: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1177:
	/* 0x1177: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1179:
	/* 0x1179: jmp    2247 <generic_fentry_process_event+0x2247> */
	return 8775ULL;
x86_l_117e:
	/* 0x117e: cmp    r13d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1ULL);
x86_l_1182:
	/* 0x1182: je     11af <generic_fentry_process_event+0x11af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11af;
	}
x86_l_1184:
	/* 0x1184: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_1188:
	/* 0x1188: jne    c66 <generic_fentry_process_event+0xc66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3174ULL;
	}
x86_l_118e:
	/* 0x118e: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_1194:
	/* 0x1194: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1199:
	/* 0x1199: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_119e:
	/* 0x119e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_11a3:
	/* 0x11a3: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11a8:
	/* 0x11a8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11ad:
	/* 0x11ad: jmp    11ce <generic_fentry_process_event+0x11ce> */
	goto x86_l_11ce;
x86_l_11af:
	/* 0x11af: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_11b4:
	/* 0x11b4: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_11ba:
	/* 0x11ba: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_11bf:
	/* 0x11bf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_11c4:
	/* 0x11c4: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11c9:
	/* 0x11c9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_11ce:
	/* 0x11ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11d0:
	/* 0x11d0: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11d4:
	/* 0x11d4: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11d9:
	/* 0x11d9: jmp    c66 <generic_fentry_process_event+0xc66> */
	return 3174ULL;
x86_l_11de:
	/* 0x11de: mov    QWORD PTR [rsp+0x30],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_11e3:
	/* 0x11e3: cmp    r13d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 43ULL);
x86_l_11e7:
	/* 0x11e7: je     1dce <generic_fentry_process_event+0x1dce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7630ULL;
	}
x86_l_11ed:
	/* 0x11ed: cmp    r13d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 41ULL);
x86_l_11f1:
	/* 0x11f1: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11f6:
	/* 0x11f6: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11fa:
	/* 0x11fa: jne    c66 <generic_fentry_process_event+0xc66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3174ULL;
	}
x86_l_1200:
	/* 0x1200: mov    r13,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RCX, X86_WIDTH_64);
x86_l_1203:
	/* 0x1203: add    r8,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1207:
	/* 0x1207: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_120c:
	/* 0x120c: mov    r12d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4ULL);
x86_l_1212:
	/* 0x1212: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1217:
	/* 0x1217: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_121c:
	/* 0x121c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1221:
	/* 0x1221: mov    rdx,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R8, X86_WIDTH_64);
x86_l_1224:
	/* 0x1224: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1226:
	/* 0x1226: mov    r15,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_122b:
	/* 0x122b: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_122e:
	/* 0x122e: je     2408 <generic_fentry_process_event+0x2408> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9224ULL;
	}
x86_l_1234:
	/* 0x1234: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1239:
	/* 0x1239: mov    QWORD PTR [rbp+0x28],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_123d:
	/* 0x123d: lea    rdi,[rbp+0x26] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_1241:
	/* 0x1241: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1245:
	/* 0x1245: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_124a:
	/* 0x124a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_124f:
	/* 0x124f: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1254:
	/* 0x1254: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1256:
	/* 0x1256: lea    rdi,[rbp+0x3a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_125a:
	/* 0x125a: lea    rdx,[r15+0x12] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_125e:
	/* 0x125e: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1263:
	/* 0x1263: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1268:
	/* 0x1268: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_126d:
	/* 0x126d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_126f:
	/* 0x126f: lea    rdi,[rbp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1273:
	/* 0x1273: lea    rdx,[r15+0x23c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_127a:
	/* 0x127a: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_127f:
	/* 0x127f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1284:
	/* 0x1284: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1289:
	/* 0x1289: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_128b:
	/* 0x128b: lea    rdi,[rbp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_128f:
	/* 0x128f: lea    rdx,[r15+0x23e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 574ULL);
x86_l_1296:
	/* 0x1296: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_129b:
	/* 0x129b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12a0:
	/* 0x12a0: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_12a5:
	/* 0x12a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12a7:
	/* 0x12a7: lea    rdi,[rbp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12ab:
	/* 0x12ab: lea    rdx,[r15+0x20c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_12b2:
	/* 0x12b2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12b7:
	/* 0x12b7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_12bc:
	/* 0x12bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12be:
	/* 0x12be: lea    rdi,[rbp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_12c2:
	/* 0x12c2: lea    rdx,[r15+0x208] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_12c9:
	/* 0x12c9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12ce:
	/* 0x12ce: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_12d3:
	/* 0x12d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12d5:
	/* 0x12d5: lea    r12,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12d9:
	/* 0x12d9: mov    QWORD PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12e1:
	/* 0x12e1: mov    QWORD PTR [rbp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_12e9:
	/* 0x12e9: mov    QWORD PTR [rbp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_12f1:
	/* 0x12f1: mov    QWORD PTR [rbp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_12f9:
	/* 0x12f9: movzx  eax,WORD PTR [rbp+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_12fd:
	/* 0x12fd: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_1300:
	/* 0x1300: je     238f <generic_fentry_process_event+0x238f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9103ULL;
	}
x86_l_1306:
	/* 0x1306: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1309:
	/* 0x1309: jne    23c1 <generic_fentry_process_event+0x23c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9153ULL;
	}
x86_l_130f:
	/* 0x130f: lea    rdx,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1313:
	/* 0x1313: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1318:
	/* 0x1318: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_131d:
	/* 0x131d: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1322:
	/* 0x1322: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1327:
	/* 0x1327: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1329:
	/* 0x1329: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_132e:
	/* 0x132e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1333:
	/* 0x1333: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1336:
	/* 0x1336: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_133b:
	/* 0x133b: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_133e:
	/* 0x133e: jmp    23bf <generic_fentry_process_event+0x23bf> */
	return 9151ULL;
x86_l_1343:
	/* 0x1343: cmp    r13d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 26ULL);
x86_l_1347:
	/* 0x1347: je     1e65 <generic_fentry_process_event+0x1e65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7781ULL;
	}
x86_l_134d:
	/* 0x134d: cmp    r13d,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 27ULL);
x86_l_1351:
	/* 0x1351: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1356:
	/* 0x1356: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_135a:
	/* 0x135a: jne    c66 <generic_fentry_process_event+0xc66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3174ULL;
	}
x86_l_1360:
	/* 0x1360: mov    r13,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_64);
x86_l_1363:
	/* 0x1363: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_1366:
	/* 0x1366: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_136b:
	/* 0x136b: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1373:
	/* 0x1373: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_137b:
	/* 0x137b: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1383:
	/* 0x1383: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_138b:
	/* 0x138b: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1393:
	/* 0x1393: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_139b:
	/* 0x139b: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_13a3:
	/* 0x13a3: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_13ab:
	/* 0x13ab: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_13b3:
	/* 0x13b3: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13ba:
	/* 0x13ba: lea    rdi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13be:
	/* 0x13be: lea    rdx,[r8+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_13c2:
	/* 0x13c2: mov    ecx,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 63ULL);
x86_l_13c7:
	/* 0x13c7: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_13cc:
	/* 0x13cc: mov    esi,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 63ULL);
x86_l_13d1:
	/* 0x13d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13d3:
	/* 0x13d3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13d6:
	/* 0x13d6: js     231b <generic_fentry_process_event+0x231b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8987ULL;
	}
x86_l_13dc:
	/* 0x13dc: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13e1:
	/* 0x13e1: add    rdi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_13e5:
	/* 0x13e5: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_13ea:
	/* 0x13ea: add    rdx,0x348 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 840ULL);
x86_l_13f1:
	/* 0x13f1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_13f6:
	/* 0x13f6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13fb:
	/* 0x13fb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1400:
	/* 0x1400: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1402:
	/* 0x1402: mov    r15d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 80ULL);
x86_l_1408:
	/* 0x1408: jmp    231e <generic_fentry_process_event+0x231e> */
	return 8990ULL;
x86_l_140d:
	/* 0x140d: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_1410:
	/* 0x1410: cmp    r13d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 8ULL);
x86_l_1414:
	/* 0x1414: je     1a4a <generic_fentry_process_event+0x1a4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6730ULL;
	}
x86_l_141a:
	/* 0x141a: cmp    r13d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 18ULL);
x86_l_141e:
	/* 0x141e: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1423:
	/* 0x1423: mov    r12,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_1426:
	/* 0x1426: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_142b:
	/* 0x142b: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_142f:
	/* 0x142f: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1434:
	/* 0x1434: jne    c66 <generic_fentry_process_event+0xc66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3174ULL;
	}
x86_l_143a:
	/* 0x143a: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_143f:
	/* 0x143f: and    r13d,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_1446:
	/* 0x1446: mov    r15,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RCX, X86_WIDTH_64);
x86_l_1449:
	/* 0x1449: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_144e:
	/* 0x144e: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1453:
	/* 0x1453: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_1456:
	/* 0x1456: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1458:
	/* 0x1458: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_145c:
	/* 0x145c: mov    rcx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_145f:
	/* 0x145f: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_1462:
	/* 0x1462: jmp    c66 <generic_fentry_process_event+0xc66> */
	return 3174ULL;
x86_l_1467:
	/* 0x1467: cmp    r13d,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 19ULL);
x86_l_146b:
	/* 0x146b: je     1d72 <generic_fentry_process_event+0x1d72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7538ULL;
	}
x86_l_1471:
	/* 0x1471: cmp    r13d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 20ULL);
x86_l_1475:
	/* 0x1475: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_147a:
	/* 0x147a: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_147e:
	/* 0x147e: mov    r8,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1483:
	/* 0x1483: jne    c66 <generic_fentry_process_event+0xc66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3174ULL;
	}
x86_l_1489:
	/* 0x1489: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_1492:
	/* 0x1492: lea    rdx,[r8+0x110] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_1499:
	/* 0x1499: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_149e:
	/* 0x149e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14a3:
	/* 0x14a3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14a8:
	/* 0x14a8: lea    r15,[r8+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_14af:
	/* 0x14af: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14b4:
	/* 0x14b4: mov    r12,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R8, X86_WIDTH_64);
x86_l_14b7:
	/* 0x14b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14b9:
	/* 0x14b9: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_14be:
	/* 0x14be: mov    edx,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 128ULL);
x86_l_14c3:
	/* 0x14c3: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_14c8:
	/* 0x14c8: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14cd:
	/* 0x14cd: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_14d2:
	/* 0x14d2: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_14d5:
	/* 0x14d5: mov    esi,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 128ULL);
x86_l_14da:
	/* 0x14da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14dc:
	/* 0x14dc: lea    rdi,[r13+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_14e3:
	/* 0x14e3: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_14e8:
	/* 0x14e8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14ed:
	/* 0x14ed: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_14f2:
	/* 0x14f2: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_14f5:
	/* 0x14f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14f7:
	/* 0x14f7: lea    rdi,[r13+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_14fe:
	/* 0x14fe: lea    rdx,[r12+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_1506:
	/* 0x1506: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_150b:
	/* 0x150b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1510:
	/* 0x1510: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1515:
	/* 0x1515: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1517:
	/* 0x1517: add    r13,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_151e:
	/* 0x151e: add    r12,0x118 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 280ULL);
x86_l_1525:
	/* 0x1525: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_152a:
	/* 0x152a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_152f:
	/* 0x152f: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1532:
	/* 0x1532: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1537:
	/* 0x1537: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_153a:
	/* 0x153a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_153c:
	/* 0x153c: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1540:
	/* 0x1540: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1545:
	/* 0x1545: mov    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_154a:
	/* 0x154a: mov    r15d,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 152ULL);
x86_l_1550:
	/* 0x1550: jmp    c66 <generic_fentry_process_event+0xc66> */
	return 3174ULL;
x86_l_1555:
	/* 0x1555: cmp    r13d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 38ULL);
x86_l_1559:
	/* 0x1559: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_155d:
	/* 0x155d: jne    c66 <generic_fentry_process_event+0xc66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3174ULL;
	}
x86_l_1563:
	/* 0x1563: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
	return 5480ULL;
}

static __noinline __u64 tetragon_bpf_generic_fentry_v61_generic_fentry_process_event_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5480ULL: goto x86_l_1568;
	case 5483ULL: goto x86_l_156b;
	case 5486ULL: goto x86_l_156e;
	case 5489ULL: goto x86_l_1571;
	case 5495ULL: goto x86_l_1577;
	case 5500ULL: goto x86_l_157c;
	case 5504ULL: goto x86_l_1580;
	case 5506ULL: goto x86_l_1582;
	case 5511ULL: goto x86_l_1587;
	case 5516ULL: goto x86_l_158c;
	case 5525ULL: goto x86_l_1595;
	case 5530ULL: goto x86_l_159a;
	case 5532ULL: goto x86_l_159c;
	case 5536ULL: goto x86_l_15a0;
	case 5541ULL: goto x86_l_15a5;
	case 5549ULL: goto x86_l_15ad;
	case 5554ULL: goto x86_l_15b2;
	case 5559ULL: goto x86_l_15b7;
	case 5564ULL: goto x86_l_15bc;
	case 5570ULL: goto x86_l_15c2;
	case 5575ULL: goto x86_l_15c7;
	case 5577ULL: goto x86_l_15c9;
	case 5584ULL: goto x86_l_15d0;
	case 5588ULL: goto x86_l_15d4;
	case 5595ULL: goto x86_l_15db;
	case 5600ULL: goto x86_l_15e0;
	case 5605ULL: goto x86_l_15e5;
	case 5607ULL: goto x86_l_15e7;
	case 5610ULL: goto x86_l_15ea;
	case 5616ULL: goto x86_l_15f0;
	case 5619ULL: goto x86_l_15f3;
	case 5627ULL: goto x86_l_15fb;
	case 5630ULL: goto x86_l_15fe;
	case 5635ULL: goto x86_l_1603;
	case 5640ULL: goto x86_l_1608;
	case 5643ULL: goto x86_l_160b;
	case 5648ULL: goto x86_l_1610;
	case 5650ULL: goto x86_l_1612;
	case 5657ULL: goto x86_l_1619;
	case 5661ULL: goto x86_l_161d;
	case 5665ULL: goto x86_l_1621;
	case 5670ULL: goto x86_l_1626;
	case 5673ULL: goto x86_l_1629;
	case 5675ULL: goto x86_l_162b;
	case 5679ULL: goto x86_l_162f;
	case 5683ULL: goto x86_l_1633;
	case 5687ULL: goto x86_l_1637;
	case 5691ULL: goto x86_l_163b;
	case 5696ULL: goto x86_l_1640;
	case 5701ULL: goto x86_l_1645;
	case 5703ULL: goto x86_l_1647;
	case 5707ULL: goto x86_l_164b;
	case 5712ULL: goto x86_l_1650;
	case 5717ULL: goto x86_l_1655;
	case 5720ULL: goto x86_l_1658;
	case 5725ULL: goto x86_l_165d;
	case 5733ULL: goto x86_l_1665;
	case 5738ULL: goto x86_l_166a;
	case 5743ULL: goto x86_l_166f;
	case 5748ULL: goto x86_l_1674;
	case 5751ULL: goto x86_l_1677;
	case 5753ULL: goto x86_l_1679;
	case 5761ULL: goto x86_l_1681;
	case 5763ULL: goto x86_l_1683;
	case 5769ULL: goto x86_l_1689;
	case 5772ULL: goto x86_l_168c;
	case 5778ULL: goto x86_l_1692;
	case 5782ULL: goto x86_l_1696;
	case 5787ULL: goto x86_l_169b;
	case 5793ULL: goto x86_l_16a1;
	case 5798ULL: goto x86_l_16a6;
	case 5803ULL: goto x86_l_16ab;
	case 5808ULL: goto x86_l_16b0;
	case 5811ULL: goto x86_l_16b3;
	case 5813ULL: goto x86_l_16b5;
	case 5818ULL: goto x86_l_16ba;
	case 5826ULL: goto x86_l_16c2;
	case 5831ULL: goto x86_l_16c7;
	case 5836ULL: goto x86_l_16cc;
	case 5841ULL: goto x86_l_16d1;
	case 5843ULL: goto x86_l_16d3;
	case 5848ULL: goto x86_l_16d8;
	case 5852ULL: goto x86_l_16dc;
	case 5857ULL: goto x86_l_16e1;
	case 5862ULL: goto x86_l_16e6;
	case 5867ULL: goto x86_l_16eb;
	case 5872ULL: goto x86_l_16f0;
	case 5874ULL: goto x86_l_16f2;
	case 5882ULL: goto x86_l_16fa;
	case 5887ULL: goto x86_l_16ff;
	case 5892ULL: goto x86_l_1704;
	case 5896ULL: goto x86_l_1708;
	case 5903ULL: goto x86_l_170f;
	case 5908ULL: goto x86_l_1714;
	case 5914ULL: goto x86_l_171a;
	case 5921ULL: goto x86_l_1721;
	case 5927ULL: goto x86_l_1727;
	case 5934ULL: goto x86_l_172e;
	case 5938ULL: goto x86_l_1732;
	case 5941ULL: goto x86_l_1735;
	case 5944ULL: goto x86_l_1738;
	case 5947ULL: goto x86_l_173b;
	case 5952ULL: goto x86_l_1740;
	case 5957ULL: goto x86_l_1745;
	case 5962ULL: goto x86_l_174a;
	case 5967ULL: goto x86_l_174f;
	case 5971ULL: goto x86_l_1753;
	case 5979ULL: goto x86_l_175b;
	case 5984ULL: goto x86_l_1760;
	case 5989ULL: goto x86_l_1765;
	case 5994ULL: goto x86_l_176a;
	case 5996ULL: goto x86_l_176c;
	case 6000ULL: goto x86_l_1770;
	case 6005ULL: goto x86_l_1775;
	case 6010ULL: goto x86_l_177a;
	case 6015ULL: goto x86_l_177f;
	case 6020ULL: goto x86_l_1784;
	case 6022ULL: goto x86_l_1786;
	case 6026ULL: goto x86_l_178a;
	case 6034ULL: goto x86_l_1792;
	case 6039ULL: goto x86_l_1797;
	case 6044ULL: goto x86_l_179c;
	case 6049ULL: goto x86_l_17a1;
	case 6051ULL: goto x86_l_17a3;
	case 6055ULL: goto x86_l_17a7;
	case 6063ULL: goto x86_l_17af;
	case 6068ULL: goto x86_l_17b4;
	case 6073ULL: goto x86_l_17b9;
	case 6078ULL: goto x86_l_17be;
	case 6080ULL: goto x86_l_17c0;
	case 6089ULL: goto x86_l_17c9;
	case 6097ULL: goto x86_l_17d1;
	case 6102ULL: goto x86_l_17d6;
	case 6107ULL: goto x86_l_17db;
	case 6112ULL: goto x86_l_17e0;
	case 6117ULL: goto x86_l_17e5;
	case 6119ULL: goto x86_l_17e7;
	case 6127ULL: goto x86_l_17ef;
	case 6135ULL: goto x86_l_17f7;
	case 6140ULL: goto x86_l_17fc;
	case 6145ULL: goto x86_l_1801;
	case 6150ULL: goto x86_l_1806;
	case 6152ULL: goto x86_l_1808;
	case 6161ULL: goto x86_l_1811;
	case 6166ULL: goto x86_l_1816;
	case 6174ULL: goto x86_l_181e;
	case 6179ULL: goto x86_l_1823;
	case 6184ULL: goto x86_l_1828;
	case 6189ULL: goto x86_l_182d;
	case 6192ULL: goto x86_l_1830;
	case 6194ULL: goto x86_l_1832;
	case 6202ULL: goto x86_l_183a;
	case 6205ULL: goto x86_l_183d;
	case 6208ULL: goto x86_l_1840;
	case 6214ULL: goto x86_l_1846;
	case 6217ULL: goto x86_l_1849;
	case 6223ULL: goto x86_l_184f;
	case 6227ULL: goto x86_l_1853;
	case 6235ULL: goto x86_l_185b;
	case 6240ULL: goto x86_l_1860;
	case 6245ULL: goto x86_l_1865;
	case 6250ULL: goto x86_l_186a;
	case 6252ULL: goto x86_l_186c;
	case 6260ULL: goto x86_l_1874;
	case 6265ULL: goto x86_l_1879;
	case 6269ULL: goto x86_l_187d;
	case 6275ULL: goto x86_l_1883;
	case 6279ULL: goto x86_l_1887;
	case 6286ULL: goto x86_l_188e;
	case 6294ULL: goto x86_l_1896;
	case 6302ULL: goto x86_l_189e;
	case 6310ULL: goto x86_l_18a6;
	case 6315ULL: goto x86_l_18ab;
	case 6320ULL: goto x86_l_18b0;
	case 6324ULL: goto x86_l_18b4;
	case 6329ULL: goto x86_l_18b9;
	case 6331ULL: goto x86_l_18bb;
	case 6335ULL: goto x86_l_18bf;
	case 6340ULL: goto x86_l_18c4;
	case 6345ULL: goto x86_l_18c9;
	case 6348ULL: goto x86_l_18cc;
	case 6353ULL: goto x86_l_18d1;
	case 6356ULL: goto x86_l_18d4;
	case 6358ULL: goto x86_l_18d6;
	case 6366ULL: goto x86_l_18de;
	case 6374ULL: goto x86_l_18e6;
	case 6379ULL: goto x86_l_18eb;
	case 6384ULL: goto x86_l_18f0;
	case 6389ULL: goto x86_l_18f5;
	case 6391ULL: goto x86_l_18f7;
	case 6399ULL: goto x86_l_18ff;
	case 6404ULL: goto x86_l_1904;
	case 6409ULL: goto x86_l_1909;
	case 6414ULL: goto x86_l_190e;
	case 6419ULL: goto x86_l_1913;
	case 6423ULL: goto x86_l_1917;
	case 6428ULL: goto x86_l_191c;
	case 6433ULL: goto x86_l_1921;
	case 6438ULL: goto x86_l_1926;
	case 6440ULL: goto x86_l_1928;
	case 6443ULL: goto x86_l_192b;
	case 6446ULL: goto x86_l_192e;
	case 6452ULL: goto x86_l_1934;
	case 6456ULL: goto x86_l_1938;
	case 6460ULL: goto x86_l_193c;
	case 6464ULL: goto x86_l_1940;
	case 6469ULL: goto x86_l_1945;
	case 6474ULL: goto x86_l_194a;
	case 6479ULL: goto x86_l_194f;
	case 6487ULL: goto x86_l_1957;
	case 6495ULL: goto x86_l_195f;
	case 6503ULL: goto x86_l_1967;
	case 6508ULL: goto x86_l_196c;
	case 6513ULL: goto x86_l_1971;
	case 6516ULL: goto x86_l_1974;
	case 6521ULL: goto x86_l_1979;
	case 6524ULL: goto x86_l_197c;
	case 6526ULL: goto x86_l_197e;
	case 6529ULL: goto x86_l_1981;
	case 6535ULL: goto x86_l_1987;
	case 6540ULL: goto x86_l_198c;
	case 6543ULL: goto x86_l_198f;
	case 6549ULL: goto x86_l_1995;
	case 6552ULL: goto x86_l_1998;
	case 6558ULL: goto x86_l_199e;
	case 6562ULL: goto x86_l_19a2;
	case 6567ULL: goto x86_l_19a7;
	case 6572ULL: goto x86_l_19ac;
	case 6577ULL: goto x86_l_19b1;
	case 6582ULL: goto x86_l_19b6;
	case 6584ULL: goto x86_l_19b8;
	case 6588ULL: goto x86_l_19bc;
	case 6593ULL: goto x86_l_19c1;
	case 6597ULL: goto x86_l_19c5;
	case 6601ULL: goto x86_l_19c9;
	case 6605ULL: goto x86_l_19cd;
	case 6610ULL: goto x86_l_19d2;
	case 6615ULL: goto x86_l_19d7;
	case 6620ULL: goto x86_l_19dc;
	case 6625ULL: goto x86_l_19e1;
	case 6630ULL: goto x86_l_19e6;
	case 6633ULL: goto x86_l_19e9;
	case 6637ULL: goto x86_l_19ed;
	case 6644ULL: goto x86_l_19f4;
	case 6656ULL: goto x86_l_1a00;
	case 6661ULL: goto x86_l_1a05;
	case 6667ULL: goto x86_l_1a0b;
	case 6672ULL: goto x86_l_1a10;
	case 6674ULL: goto x86_l_1a12;
	case 6677ULL: goto x86_l_1a15;
	case 6679ULL: goto x86_l_1a17;
	case 6682ULL: goto x86_l_1a1a;
	case 6685ULL: goto x86_l_1a1d;
	case 6691ULL: goto x86_l_1a23;
	case 6694ULL: goto x86_l_1a26;
	case 6700ULL: goto x86_l_1a2c;
	case 6703ULL: goto x86_l_1a2f;
	case 6709ULL: goto x86_l_1a35;
	case 6712ULL: goto x86_l_1a38;
	case 6718ULL: goto x86_l_1a3e;
	case 6725ULL: goto x86_l_1a45;
	case 6730ULL: goto x86_l_1a4a;
	case 6735ULL: goto x86_l_1a4f;
	case 6739ULL: goto x86_l_1a53;
	case 6743ULL: goto x86_l_1a57;
	case 6748ULL: goto x86_l_1a5c;
	case 6753ULL: goto x86_l_1a61;
	case 6758ULL: goto x86_l_1a66;
	case 6763ULL: goto x86_l_1a6b;
	case 6768ULL: goto x86_l_1a70;
	case 6771ULL: goto x86_l_1a73;
	case 6776ULL: goto x86_l_1a78;
	case 6778ULL: goto x86_l_1a7a;
	case 6782ULL: goto x86_l_1a7e;
	case 6787ULL: goto x86_l_1a83;
	case 6792ULL: goto x86_l_1a88;
	case 6797ULL: goto x86_l_1a8d;
	case 6802ULL: goto x86_l_1a92;
	case 6804ULL: goto x86_l_1a94;
	case 6808ULL: goto x86_l_1a98;
	case 6813ULL: goto x86_l_1a9d;
	case 6818ULL: goto x86_l_1aa2;
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
	case 6968ULL: goto x86_l_1b38;
	case 6972ULL: goto x86_l_1b3c;
	case 6977ULL: goto x86_l_1b41;
	case 6982ULL: goto x86_l_1b46;
	case 6987ULL: goto x86_l_1b4b;
	case 6992ULL: goto x86_l_1b50;
	case 6994ULL: goto x86_l_1b52;
	case 6998ULL: goto x86_l_1b56;
	case 7003ULL: goto x86_l_1b5b;
	case 7008ULL: goto x86_l_1b60;
	case 7013ULL: goto x86_l_1b65;
	case 7018ULL: goto x86_l_1b6a;
	case 7020ULL: goto x86_l_1b6c;
	case 7024ULL: goto x86_l_1b70;
	case 7029ULL: goto x86_l_1b75;
	case 7034ULL: goto x86_l_1b7a;
	case 7039ULL: goto x86_l_1b7f;
	case 7044ULL: goto x86_l_1b84;
	case 7046ULL: goto x86_l_1b86;
	case 7051ULL: goto x86_l_1b8b;
	case 7056ULL: goto x86_l_1b90;
	case 7061ULL: goto x86_l_1b95;
	case 7064ULL: goto x86_l_1b98;
	case 7069ULL: goto x86_l_1b9d;
	case 7071ULL: goto x86_l_1b9f;
	case 7078ULL: goto x86_l_1ba6;
	case 7083ULL: goto x86_l_1bab;
	case 7088ULL: goto x86_l_1bb0;
	case 7093ULL: goto x86_l_1bb5;
	case 7098ULL: goto x86_l_1bba;
	case 7101ULL: goto x86_l_1bbd;
	case 7103ULL: goto x86_l_1bbf;
	case 7108ULL: goto x86_l_1bc4;
	case 7116ULL: goto x86_l_1bcc;
	case 7121ULL: goto x86_l_1bd1;
	case 7126ULL: goto x86_l_1bd6;
	case 7131ULL: goto x86_l_1bdb;
	case 7136ULL: goto x86_l_1be0;
	case 7138ULL: goto x86_l_1be2;
	case 7142ULL: goto x86_l_1be6;
	case 7150ULL: goto x86_l_1bee;
	case 7155ULL: goto x86_l_1bf3;
	case 7160ULL: goto x86_l_1bf8;
	case 7165ULL: goto x86_l_1bfd;
	case 7167ULL: goto x86_l_1bff;
	case 7171ULL: goto x86_l_1c03;
	case 7179ULL: goto x86_l_1c0b;
	case 7184ULL: goto x86_l_1c10;
	case 7189ULL: goto x86_l_1c15;
	case 7194ULL: goto x86_l_1c1a;
	case 7196ULL: goto x86_l_1c1c;
	case 7200ULL: goto x86_l_1c20;
	case 7207ULL: goto x86_l_1c27;
	case 7212ULL: goto x86_l_1c2c;
	case 7217ULL: goto x86_l_1c31;
	case 7220ULL: goto x86_l_1c34;
	case 7225ULL: goto x86_l_1c39;
	case 7228ULL: goto x86_l_1c3c;
	case 7230ULL: goto x86_l_1c3e;
	case 7236ULL: goto x86_l_1c44;
	case 7241ULL: goto x86_l_1c49;
	case 7244ULL: goto x86_l_1c4c;
	case 7249ULL: goto x86_l_1c51;
	case 7254ULL: goto x86_l_1c56;
	case 7261ULL: goto x86_l_1c5d;
	case 7266ULL: goto x86_l_1c62;
	case 7271ULL: goto x86_l_1c67;
	case 7276ULL: goto x86_l_1c6c;
	case 7279ULL: goto x86_l_1c6f;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1568:
	/* 0x1568: movzx  edx,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_156b:
	/* 0x156b: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_156e:
	/* 0x156e: shr    esi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1571:
	/* 0x1571: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1577:
	/* 0x1577: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_157c:
	/* 0x157c: lea    rdi,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1580:
	/* 0x1580: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1582:
	/* 0x1582: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1587:
	/* 0x1587: jmp    1926 <generic_fentry_process_event+0x1926> */
	goto x86_l_1926;
x86_l_158c:
	/* 0x158c: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_1595:
	/* 0x1595: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_159a:
	/* 0x159a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_159c:
	/* 0x159c: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_15a0:
	/* 0x15a0: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_15a5:
	/* 0x15a5: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_15ad:
	/* 0x15ad: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_15b2:
	/* 0x15b2: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_15b7:
	/* 0x15b7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15bc:
	/* 0x15bc: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_15c2:
	/* 0x15c2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_15c7:
	/* 0x15c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15c9:
	/* 0x15c9: mov    eax,DWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_15d0:
	/* 0x15d0: mov    DWORD PTR [rsp+0x70],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_15d4:
	/* 0x15d4: mov    rdi,QWORD PTR [rip+0x2e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_15db:
	/* 0x15db: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_15e0:
	/* 0x15e0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15e5:
	/* 0x15e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15e7:
	/* 0x15e7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15ea:
	/* 0x15ea: je     1ee8 <generic_fentry_process_event+0x1ee8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7912ULL;
	}
x86_l_15f0:
	/* 0x15f0: mov    r15d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15f3:
	/* 0x15f3: lea    rdx,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_15fb:
	/* 0x15fb: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_15fe:
	/* 0x15fe: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1603:
	/* 0x1603: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1608:
	/* 0x1608: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_160b:
	/* 0x160b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1610:
	/* 0x1610: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1612:
	/* 0x1612: and    r15d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1619:
	/* 0x1619: lea    rdi,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_161d:
	/* 0x161d: lea    rsi,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1621:
	/* 0x1621: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1626:
	/* 0x1626: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1629:
	/* 0x1629: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_162b:
	/* 0x162b: lea    rdi,[r15+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_162f:
	/* 0x162f: add    rdi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1633:
	/* 0x1633: lea    rdx,[r15+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_1637:
	/* 0x1637: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_163b:
	/* 0x163b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1640:
	/* 0x1640: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1645:
	/* 0x1645: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1647:
	/* 0x1647: add    r15,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_164b:
	/* 0x164b: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1650:
	/* 0x1650: jmp    332f <generic_fentry_process_event+0x332f> */
	return 13103ULL;
x86_l_1655:
	/* 0x1655: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1658:
	/* 0x1658: mov    r12,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_165d:
	/* 0x165d: lea    rdi,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1665:
	/* 0x1665: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_166a:
	/* 0x166a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_166f:
	/* 0x166f: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1674:
	/* 0x1674: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1677:
	/* 0x1677: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1679:
	/* 0x1679: movzx  eax,BYTE PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 192ULL);
x86_l_1681:
	/* 0x1681: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1683:
	/* 0x1683: je     1ef9 <generic_fentry_process_event+0x1ef9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7929ULL;
	}
x86_l_1689:
	/* 0x1689: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_168c:
	/* 0x168c: jne    20f6 <generic_fentry_process_event+0x20f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8438ULL;
	}
x86_l_1692:
	/* 0x1692: add    r12,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1696:
	/* 0x1696: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_169b:
	/* 0x169b: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_16a1:
	/* 0x16a1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_16a6:
	/* 0x16a6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16ab:
	/* 0x16ab: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16b0:
	/* 0x16b0: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_16b3:
	/* 0x16b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16b5:
	/* 0x16b5: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_16ba:
	/* 0x16ba: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_16c2:
	/* 0x16c2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_16c7:
	/* 0x16c7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16cc:
	/* 0x16cc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16d1:
	/* 0x16d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16d3:
	/* 0x16d3: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_16d8:
	/* 0x16d8: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_16dc:
	/* 0x16dc: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_16e1:
	/* 0x16e1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_16e6:
	/* 0x16e6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16eb:
	/* 0x16eb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16f0:
	/* 0x16f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16f2:
	/* 0x16f2: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_16fa:
	/* 0x16fa: mov    r13,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_16ff:
	/* 0x16ff: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1704:
	/* 0x1704: lea    r14,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1708:
	/* 0x1708: add    r14,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_170f:
	/* 0x170f: test   BYTE PTR [rsp+0x30],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430240ULL);
x86_l_1714:
	/* 0x1714: je     29ba <generic_fentry_process_event+0x29ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10682ULL;
	}
x86_l_171a:
	/* 0x171a: cmp    r13,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4096ULL);
x86_l_1721:
	/* 0x1721: jb     2993 <generic_fentry_process_event+0x2993> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10643ULL;
	}
x86_l_1727:
	/* 0x1727: mov    DWORD PTR [r14],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_172e:
	/* 0x172e: add    r14,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1732:
	/* 0x1732: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1735:
	/* 0x1735: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_1738:
	/* 0x1738: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_173b:
	/* 0x173b: jmp    2bbe <generic_fentry_process_event+0x2bbe> */
	return 11198ULL;
x86_l_1740:
	/* 0x1740: mov    QWORD PTR [rsp+0x40],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1745:
	/* 0x1745: mov    r12,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_174a:
	/* 0x174a: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_174f:
	/* 0x174f: lea    rdi,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1753:
	/* 0x1753: lea    rdx,[r12+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_175b:
	/* 0x175b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1760:
	/* 0x1760: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1765:
	/* 0x1765: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_176a:
	/* 0x176a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_176c:
	/* 0x176c: lea    rdi,[rbx+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1770:
	/* 0x1770: lea    rdx,[r12+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1775:
	/* 0x1775: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_177a:
	/* 0x177a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_177f:
	/* 0x177f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1784:
	/* 0x1784: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1786:
	/* 0x1786: lea    rdi,[rbx+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_178a:
	/* 0x178a: lea    rdx,[r12+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1792:
	/* 0x1792: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1797:
	/* 0x1797: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_179c:
	/* 0x179c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_17a1:
	/* 0x17a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17a3:
	/* 0x17a3: lea    rdi,[rbx+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_17a7:
	/* 0x17a7: lea    rdx,[r12+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_17af:
	/* 0x17af: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_17b4:
	/* 0x17b4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17b9:
	/* 0x17b9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_17be:
	/* 0x17be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17c0:
	/* 0x17c0: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_17c9:
	/* 0x17c9: lea    rdx,[r12+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_17d1:
	/* 0x17d1: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_17d6:
	/* 0x17d6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_17db:
	/* 0x17db: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17e0:
	/* 0x17e0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17e5:
	/* 0x17e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17e7:
	/* 0x17e7: lea    rdx,[r12+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_17ef:
	/* 0x17ef: lea    rdi,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_17f7:
	/* 0x17f7: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_17fc:
	/* 0x17fc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1801:
	/* 0x1801: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1806:
	/* 0x1806: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1808:
	/* 0x1808: movzx  r15d,WORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 192ULL);
x86_l_1811:
	/* 0x1811: add    r15,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 104ULL);
x86_l_1816:
	/* 0x1816: lea    rdi,[rsp+0xbb] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 187ULL);
x86_l_181e:
	/* 0x181e: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1823:
	/* 0x1823: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1828:
	/* 0x1828: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_182d:
	/* 0x182d: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1830:
	/* 0x1830: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1832:
	/* 0x1832: movzx  eax,BYTE PTR [rsp+0xbb] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 187ULL);
x86_l_183a:
	/* 0x183a: shr    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 4ULL);
x86_l_183d:
	/* 0x183d: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_1840:
	/* 0x1840: je     1f8d <generic_fentry_process_event+0x1f8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8077ULL;
	}
x86_l_1846:
	/* 0x1846: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1849:
	/* 0x1849: jne    331f <generic_fentry_process_event+0x331f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13087ULL;
	}
x86_l_184f:
	/* 0x184f: lea    rdx,[r15+0x9] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_1853:
	/* 0x1853: lea    rdi,[rsp+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_185b:
	/* 0x185b: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1860:
	/* 0x1860: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1865:
	/* 0x1865: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_186a:
	/* 0x186a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_186c:
	/* 0x186c: movzx  eax,BYTE PTR [rsp+0xbc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 188ULL);
x86_l_1874:
	/* 0x1874: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1879:
	/* 0x1879: mov    WORD PTR [rdi+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_187d:
	/* 0x187d: mov    WORD PTR [rdi+0x26],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757250ULL);
x86_l_1883:
	/* 0x1883: lea    rdx,[r15+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1887:
	/* 0x1887: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_188e:
	/* 0x188e: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1896:
	/* 0x1896: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_189e:
	/* 0x189e: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_18a6:
	/* 0x18a6: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_18ab:
	/* 0x18ab: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18b0:
	/* 0x18b0: lea    r13,[rdi+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18b4:
	/* 0x18b4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18b9:
	/* 0x18b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18bb:
	/* 0x18bb: add    r15,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_18bf:
	/* 0x18bf: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_18c4:
	/* 0x18c4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18c9:
	/* 0x18c9: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_18cc:
	/* 0x18cc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18d1:
	/* 0x18d1: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_18d4:
	/* 0x18d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18d6:
	/* 0x18d6: lea    rdx,[r12+0xb6] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 182ULL);
x86_l_18de:
	/* 0x18de: lea    rdi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_18e6:
	/* 0x18e6: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_18eb:
	/* 0x18eb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18f0:
	/* 0x18f0: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_18f5:
	/* 0x18f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18f7:
	/* 0x18f7: movzx  ebp,BYTE PTR [rsp+0xbc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 188ULL);
x86_l_18ff:
	/* 0x18ff: jmp    31bb <generic_fentry_process_event+0x31bb> */
	return 12731ULL;
x86_l_1904:
	/* 0x1904: mov    edx,0x120 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 288ULL);
x86_l_1909:
	/* 0x1909: add    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_190e:
	/* 0x190e: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1913:
	/* 0x1913: lea    rdi,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1917:
	/* 0x1917: mov    ecx,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_191c:
	/* 0x191c: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1921:
	/* 0x1921: mov    esi,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_1926:
	/* 0x1926: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1928:
	/* 0x1928: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_192b:
	/* 0x192b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_192e:
	/* 0x192e: js     2247 <generic_fentry_process_event+0x2247> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8775ULL;
	}
x86_l_1934:
	/* 0x1934: lea    eax,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1938:
	/* 0x1938: mov    DWORD PTR [r13+0x0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_193c:
	/* 0x193c: add    r15,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_1940:
	/* 0x1940: jmp    2247 <generic_fentry_process_event+0x2247> */
	return 8775ULL;
x86_l_1945:
	/* 0x1945: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_194a:
	/* 0x194a: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_194f:
	/* 0x194f: mov    QWORD PTR [r13+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1957:
	/* 0x1957: mov    QWORD PTR [r13+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_195f:
	/* 0x195f: mov    QWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1967:
	/* 0x1967: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_196c:
	/* 0x196c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1971:
	/* 0x1971: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1974:
	/* 0x1974: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1979:
	/* 0x1979: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_197c:
	/* 0x197c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_197e:
	/* 0x197e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1981:
	/* 0x1981: js     2241 <generic_fentry_process_event+0x2241> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8769ULL;
	}
x86_l_1987:
	/* 0x1987: movzx  eax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_198c:
	/* 0x198c: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_198f:
	/* 0x198f: je     21e7 <generic_fentry_process_event+0x21e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8679ULL;
	}
x86_l_1995:
	/* 0x1995: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1998:
	/* 0x1998: jne    2223 <generic_fentry_process_event+0x2223> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8739ULL;
	}
x86_l_199e:
	/* 0x199e: lea    rdx,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_19a2:
	/* 0x19a2: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_19a7:
	/* 0x19a7: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_19ac:
	/* 0x19ac: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19b1:
	/* 0x19b1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19b6:
	/* 0x19b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19b8:
	/* 0x19b8: mov    eax,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_19bc:
	/* 0x19bc: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19c1:
	/* 0x19c1: mov    QWORD PTR [rcx+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19c5:
	/* 0x19c5: lea    rdi,[rcx+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_19c9:
	/* 0x19c9: add    r15,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_19cd:
	/* 0x19cd: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_19d2:
	/* 0x19d2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19d7:
	/* 0x19d7: jmp    2219 <generic_fentry_process_event+0x2219> */
	return 8729ULL;
x86_l_19dc:
	/* 0x19dc: mov    QWORD PTR [rsp+0x40],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_19e1:
	/* 0x19e1: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_19e6:
	/* 0x19e6: mov    rbp,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RCX, X86_WIDTH_64);
x86_l_19e9:
	/* 0x19e9: lea    r12,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_19ed:
	/* 0x19ed: add    r12,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_19f4:
	/* 0x19f4: mov    QWORD PTR [rsp+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_1a00:
	/* 0x1a00: test   BYTE PTR [rsp+0x30],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430224ULL);
x86_l_1a05:
	/* 0x1a05: jne    2117 <generic_fentry_process_event+0x2117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8471ULL;
	}
x86_l_1a0b:
	/* 0x1a0b: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a10:
	/* 0x1a10: mov    ebx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDX, X86_WIDTH_32);
x86_l_1a12:
	/* 0x1a12: and    edx,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1a15:
	/* 0x1a15: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a17:
	/* 0x1a17: mov    rcx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1a1a:
	/* 0x1a1a: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_1a1d:
	/* 0x1a1d: jle    2371 <generic_fentry_process_event+0x2371> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 9073ULL;
	}
x86_l_1a23:
	/* 0x1a23: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1a26:
	/* 0x1a26: je     2b44 <generic_fentry_process_event+0x2b44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11076ULL;
	}
x86_l_1a2c:
	/* 0x1a2c: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1a2f:
	/* 0x1a2f: je     2b4d <generic_fentry_process_event+0x2b4d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11085ULL;
	}
x86_l_1a35:
	/* 0x1a35: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1a38:
	/* 0x1a38: jne    2b60 <generic_fentry_process_event+0x2b60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11104ULL;
	}
x86_l_1a3e:
	/* 0x1a3e: lea    rax,[rbp+0x5e70] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24176ULL);
x86_l_1a45:
	/* 0x1a45: jmp    2b5d <generic_fentry_process_event+0x2b5d> */
	return 11101ULL;
x86_l_1a4a:
	/* 0x1a4a: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a4f:
	/* 0x1a4f: lea    r13,[r15+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1a53:
	/* 0x1a53: lea    rax,[r15+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1a57:
	/* 0x1a57: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a5c:
	/* 0x1a5c: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a61:
	/* 0x1a61: lea    rdx,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a66:
	/* 0x1a66: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1a6b:
	/* 0x1a6b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a70:
	/* 0x1a70: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1a73:
	/* 0x1a73: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a78:
	/* 0x1a78: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a7a:
	/* 0x1a7a: lea    rdi,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1a7e:
	/* 0x1a7e: lea    rdx,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1a83:
	/* 0x1a83: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1a88:
	/* 0x1a88: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a8d:
	/* 0x1a8d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a92:
	/* 0x1a92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a94:
	/* 0x1a94: lea    rdi,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a98:
	/* 0x1a98: lea    rdx,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a9d:
	/* 0x1a9d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1aa2:
	/* 0x1aa2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1aa7:
	/* 0x1aa7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1aac:
	/* 0x1aac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aae:
	/* 0x1aae: lea    rdi,[r15+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1ab2:
	/* 0x1ab2: lea    rdx,[r12+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
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
	/* 0x1ac8: lea    rdi,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1acc:
	/* 0x1acc: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
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
	/* 0x1ae2: lea    rdi,[r15+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1ae6:
	/* 0x1ae6: lea    rdx,[r12+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
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
	/* 0x1afc: lea    rdi,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b00:
	/* 0x1b00: lea    rdx,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
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
	/* 0x1b16: lea    rdi,[r15+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1b1a:
	/* 0x1b1a: lea    rdx,[r12+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
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
	/* 0x1b30: mov    DWORD PTR [r15+0x24],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_1b38:
	/* 0x1b38: lea    rdi,[r15+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b3c:
	/* 0x1b3c: lea    rdx,[r12+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b41:
	/* 0x1b41: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1b46:
	/* 0x1b46: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b4b:
	/* 0x1b4b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b50:
	/* 0x1b50: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b52:
	/* 0x1b52: lea    rdi,[r15+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b56:
	/* 0x1b56: lea    rdx,[r12+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1b5b:
	/* 0x1b5b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1b60:
	/* 0x1b60: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b65:
	/* 0x1b65: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b6a:
	/* 0x1b6a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b6c:
	/* 0x1b6c: lea    rdi,[r15+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1b70:
	/* 0x1b70: lea    rdx,[r12+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b75:
	/* 0x1b75: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1b7a:
	/* 0x1b7a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b7f:
	/* 0x1b7f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b84:
	/* 0x1b84: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b86:
	/* 0x1b86: lea    rdx,[r12+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1b8b:
	/* 0x1b8b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1b90:
	/* 0x1b90: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b95:
	/* 0x1b95: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1b98:
	/* 0x1b98: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b9d:
	/* 0x1b9d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b9f:
	/* 0x1b9f: add    r12,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_1ba6:
	/* 0x1ba6: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1bab:
	/* 0x1bab: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1bb0:
	/* 0x1bb0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1bb5:
	/* 0x1bb5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bba:
	/* 0x1bba: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1bbd:
	/* 0x1bbd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bbf:
	/* 0x1bbf: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1bc4:
	/* 0x1bc4: lea    rdx,[r12+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1bcc:
	/* 0x1bcc: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1bd1:
	/* 0x1bd1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1bd6:
	/* 0x1bd6: mov    rdi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1bdb:
	/* 0x1bdb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1be0:
	/* 0x1be0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1be2:
	/* 0x1be2: lea    rdi,[r15+0x44] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_1be6:
	/* 0x1be6: lea    rdx,[r12+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_1bee:
	/* 0x1bee: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1bf3:
	/* 0x1bf3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1bf8:
	/* 0x1bf8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1bfd:
	/* 0x1bfd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bff:
	/* 0x1bff: lea    rdi,[r15+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1c03:
	/* 0x1c03: lea    rdx,[r12+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1c0b:
	/* 0x1c0b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1c10:
	/* 0x1c10: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c15:
	/* 0x1c15: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c1a:
	/* 0x1c1a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c1c:
	/* 0x1c1c: add    r15,0x4c */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 76ULL);
x86_l_1c20:
	/* 0x1c20: add    r12,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_1c27:
	/* 0x1c27: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1c2c:
	/* 0x1c2c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c31:
	/* 0x1c31: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1c34:
	/* 0x1c34: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c39:
	/* 0x1c39: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1c3c:
	/* 0x1c3c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c3e:
	/* 0x1c3e: mov    r15d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 80ULL);
x86_l_1c44:
	/* 0x1c44: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c49:
	/* 0x1c49: mov    r12,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_1c4c:
	/* 0x1c4c: jmp    c5d <generic_fentry_process_event+0xc5d> */
	return 3165ULL;
x86_l_1c51:
	/* 0x1c51: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c56:
	/* 0x1c56: lea    rdx,[r13+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1c5d:
	/* 0x1c5d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1c62:
	/* 0x1c62: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c67:
	/* 0x1c67: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c6c:
	/* 0x1c6c: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1c6f:
	/* 0x1c6f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
	return 7284ULL;
}

static __noinline __u64 tetragon_bpf_generic_fentry_v61_generic_fentry_process_event_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7284ULL: goto x86_l_1c74;
	case 7286ULL: goto x86_l_1c76;
	case 7290ULL: goto x86_l_1c7a;
	case 7297ULL: goto x86_l_1c81;
	case 7302ULL: goto x86_l_1c86;
	case 7307ULL: goto x86_l_1c8b;
	case 7312ULL: goto x86_l_1c90;
	case 7314ULL: goto x86_l_1c92;
	case 7318ULL: goto x86_l_1c96;
	case 7325ULL: goto x86_l_1c9d;
	case 7330ULL: goto x86_l_1ca2;
	case 7335ULL: goto x86_l_1ca7;
	case 7340ULL: goto x86_l_1cac;
	case 7342ULL: goto x86_l_1cae;
	case 7346ULL: goto x86_l_1cb2;
	case 7353ULL: goto x86_l_1cb9;
	case 7358ULL: goto x86_l_1cbe;
	case 7363ULL: goto x86_l_1cc3;
	case 7366ULL: goto x86_l_1cc6;
	case 7371ULL: goto x86_l_1ccb;
	case 7374ULL: goto x86_l_1cce;
	case 7376ULL: goto x86_l_1cd0;
	case 7382ULL: goto x86_l_1cd6;
	case 7387ULL: goto x86_l_1cdb;
	case 7392ULL: goto x86_l_1ce0;
	case 7396ULL: goto x86_l_1ce4;
	case 7401ULL: goto x86_l_1ce9;
	case 7406ULL: goto x86_l_1cee;
	case 7411ULL: goto x86_l_1cf3;
	case 7414ULL: goto x86_l_1cf6;
	case 7419ULL: goto x86_l_1cfb;
	case 7421ULL: goto x86_l_1cfd;
	case 7425ULL: goto x86_l_1d01;
	case 7429ULL: goto x86_l_1d05;
	case 7434ULL: goto x86_l_1d0a;
	case 7439ULL: goto x86_l_1d0f;
	case 7444ULL: goto x86_l_1d14;
	case 7446ULL: goto x86_l_1d16;
	case 7450ULL: goto x86_l_1d1a;
	case 7454ULL: goto x86_l_1d1e;
	case 7459ULL: goto x86_l_1d23;
	case 7464ULL: goto x86_l_1d28;
	case 7469ULL: goto x86_l_1d2d;
	case 7471ULL: goto x86_l_1d2f;
	case 7475ULL: goto x86_l_1d33;
	case 7479ULL: goto x86_l_1d37;
	case 7484ULL: goto x86_l_1d3c;
	case 7489ULL: goto x86_l_1d41;
	case 7494ULL: goto x86_l_1d46;
	case 7496ULL: goto x86_l_1d48;
	case 7500ULL: goto x86_l_1d4c;
	case 7504ULL: goto x86_l_1d50;
	case 7509ULL: goto x86_l_1d55;
	case 7514ULL: goto x86_l_1d5a;
	case 7517ULL: goto x86_l_1d5d;
	case 7522ULL: goto x86_l_1d62;
	case 7525ULL: goto x86_l_1d65;
	case 7527ULL: goto x86_l_1d67;
	case 7533ULL: goto x86_l_1d6d;
	case 7538ULL: goto x86_l_1d72;
	case 7543ULL: goto x86_l_1d77;
	case 7548ULL: goto x86_l_1d7c;
	case 7553ULL: goto x86_l_1d81;
	case 7558ULL: goto x86_l_1d86;
	case 7561ULL: goto x86_l_1d89;
	case 7566ULL: goto x86_l_1d8e;
	case 7569ULL: goto x86_l_1d91;
	case 7571ULL: goto x86_l_1d93;
	case 7575ULL: goto x86_l_1d97;
	case 7579ULL: goto x86_l_1d9b;
	case 7584ULL: goto x86_l_1da0;
	case 7589ULL: goto x86_l_1da5;
	case 7594ULL: goto x86_l_1daa;
	case 7596ULL: goto x86_l_1dac;
	case 7600ULL: goto x86_l_1db0;
	case 7604ULL: goto x86_l_1db4;
	case 7609ULL: goto x86_l_1db9;
	case 7614ULL: goto x86_l_1dbe;
	case 7617ULL: goto x86_l_1dc1;
	case 7622ULL: goto x86_l_1dc6;
	case 7625ULL: goto x86_l_1dc9;
	case 7630ULL: goto x86_l_1dce;
	case 7634ULL: goto x86_l_1dd2;
	case 7639ULL: goto x86_l_1dd7;
	case 7644ULL: goto x86_l_1ddc;
	case 7649ULL: goto x86_l_1de1;
	case 7654ULL: goto x86_l_1de6;
	case 7657ULL: goto x86_l_1de9;
	case 7659ULL: goto x86_l_1deb;
	case 7663ULL: goto x86_l_1def;
	case 7668ULL: goto x86_l_1df4;
	case 7671ULL: goto x86_l_1df7;
	case 7675ULL: goto x86_l_1dfb;
	case 7680ULL: goto x86_l_1e00;
	case 7685ULL: goto x86_l_1e05;
	case 7690ULL: goto x86_l_1e0a;
	case 7695ULL: goto x86_l_1e0f;
	case 7697ULL: goto x86_l_1e11;
	case 7701ULL: goto x86_l_1e15;
	case 7705ULL: goto x86_l_1e19;
	case 7709ULL: goto x86_l_1e1d;
	case 7714ULL: goto x86_l_1e22;
	case 7719ULL: goto x86_l_1e27;
	case 7724ULL: goto x86_l_1e2c;
	case 7729ULL: goto x86_l_1e31;
	case 7732ULL: goto x86_l_1e34;
	case 7734ULL: goto x86_l_1e36;
	case 7738ULL: goto x86_l_1e3a;
	case 7743ULL: goto x86_l_1e3f;
	case 7748ULL: goto x86_l_1e44;
	case 7751ULL: goto x86_l_1e47;
	case 7756ULL: goto x86_l_1e4c;
	case 7761ULL: goto x86_l_1e51;
	case 7766ULL: goto x86_l_1e56;
	case 7769ULL: goto x86_l_1e59;
	case 7774ULL: goto x86_l_1e5e;
	case 7776ULL: goto x86_l_1e60;
	case 7781ULL: goto x86_l_1e65;
	case 7786ULL: goto x86_l_1e6a;
	case 7794ULL: goto x86_l_1e72;
	case 7802ULL: goto x86_l_1e7a;
	case 7810ULL: goto x86_l_1e82;
	case 7818ULL: goto x86_l_1e8a;
	case 7826ULL: goto x86_l_1e92;
	case 7834ULL: goto x86_l_1e9a;
	case 7842ULL: goto x86_l_1ea2;
	case 7850ULL: goto x86_l_1eaa;
	case 7858ULL: goto x86_l_1eb2;
	case 7865ULL: goto x86_l_1eb9;
	case 7870ULL: goto x86_l_1ebe;
	case 7875ULL: goto x86_l_1ec3;
	case 7880ULL: goto x86_l_1ec8;
	case 7885ULL: goto x86_l_1ecd;
	case 7888ULL: goto x86_l_1ed0;
	case 7890ULL: goto x86_l_1ed2;
	case 7893ULL: goto x86_l_1ed5;
	case 7899ULL: goto x86_l_1edb;
	case 7902ULL: goto x86_l_1ede;
	case 7907ULL: goto x86_l_1ee3;
	case 7912ULL: goto x86_l_1ee8;
	case 7919ULL: goto x86_l_1eef;
	case 7924ULL: goto x86_l_1ef4;
	case 7929ULL: goto x86_l_1ef9;
	case 7934ULL: goto x86_l_1efe;
	case 7942ULL: goto x86_l_1f06;
	case 7947ULL: goto x86_l_1f0b;
	case 7952ULL: goto x86_l_1f10;
	case 7957ULL: goto x86_l_1f15;
	case 7962ULL: goto x86_l_1f1a;
	case 7967ULL: goto x86_l_1f1f;
	case 7969ULL: goto x86_l_1f21;
	case 7973ULL: goto x86_l_1f25;
	case 7978ULL: goto x86_l_1f2a;
	case 7983ULL: goto x86_l_1f2f;
	case 7988ULL: goto x86_l_1f34;
	case 7993ULL: goto x86_l_1f39;
	case 7996ULL: goto x86_l_1f3c;
	case 7998ULL: goto x86_l_1f3e;
	case 8006ULL: goto x86_l_1f46;
	case 8011ULL: goto x86_l_1f4b;
	case 8016ULL: goto x86_l_1f50;
	case 8020ULL: goto x86_l_1f54;
	case 8027ULL: goto x86_l_1f5b;
	case 8032ULL: goto x86_l_1f60;
	case 8038ULL: goto x86_l_1f66;
	case 8045ULL: goto x86_l_1f6d;
	case 8051ULL: goto x86_l_1f73;
	case 8059ULL: goto x86_l_1f7b;
	case 8063ULL: goto x86_l_1f7f;
	case 8066ULL: goto x86_l_1f82;
	case 8069ULL: goto x86_l_1f85;
	case 8072ULL: goto x86_l_1f88;
	case 8077ULL: goto x86_l_1f8d;
	case 8082ULL: goto x86_l_1f92;
	case 8093ULL: goto x86_l_1f9d;
	case 8101ULL: goto x86_l_1fa5;
	case 8108ULL: goto x86_l_1fac;
	case 8116ULL: goto x86_l_1fb4;
	case 8121ULL: goto x86_l_1fb9;
	case 8125ULL: goto x86_l_1fbd;
	case 8127ULL: goto x86_l_1fbf;
	case 8130ULL: goto x86_l_1fc2;
	case 8136ULL: goto x86_l_1fc8;
	case 8139ULL: goto x86_l_1fcb;
	case 8142ULL: goto x86_l_1fce;
	case 8146ULL: goto x86_l_1fd2;
	case 8150ULL: goto x86_l_1fd6;
	case 8153ULL: goto x86_l_1fd9;
	case 8157ULL: goto x86_l_1fdd;
	case 8161ULL: goto x86_l_1fe1;
	case 8166ULL: goto x86_l_1fe6;
	case 8171ULL: goto x86_l_1feb;
	case 8176ULL: goto x86_l_1ff0;
	case 8181ULL: goto x86_l_1ff5;
	case 8183ULL: goto x86_l_1ff7;
	case 8186ULL: goto x86_l_1ffa;
	case 8192ULL: goto x86_l_2000;
	case 8197ULL: goto x86_l_2005;
	case 8200ULL: goto x86_l_2008;
	case 8206ULL: goto x86_l_200e;
	case 8208ULL: goto x86_l_2010;
	case 8214ULL: goto x86_l_2016;
	case 8217ULL: goto x86_l_2019;
	case 8223ULL: goto x86_l_201f;
	case 8226ULL: goto x86_l_2022;
	case 8232ULL: goto x86_l_2028;
	case 8239ULL: goto x86_l_202f;
	case 8243ULL: goto x86_l_2033;
	case 8248ULL: goto x86_l_2038;
	case 8252ULL: goto x86_l_203c;
	case 8257ULL: goto x86_l_2041;
	case 8262ULL: goto x86_l_2046;
	case 8265ULL: goto x86_l_2049;
	case 8270ULL: goto x86_l_204e;
	case 8272ULL: goto x86_l_2050;
	case 8276ULL: goto x86_l_2054;
	case 8281ULL: goto x86_l_2059;
	case 8286ULL: goto x86_l_205e;
	case 8289ULL: goto x86_l_2061;
	case 8294ULL: goto x86_l_2066;
	case 8296ULL: goto x86_l_2068;
	case 8300ULL: goto x86_l_206c;
	case 8304ULL: goto x86_l_2070;
	case 8308ULL: goto x86_l_2074;
	case 8313ULL: goto x86_l_2079;
	case 8318ULL: goto x86_l_207e;
	case 8323ULL: goto x86_l_2083;
	case 8326ULL: goto x86_l_2086;
	case 8328ULL: goto x86_l_2088;
	case 8332ULL: goto x86_l_208c;
	case 8337ULL: goto x86_l_2091;
	case 8342ULL: goto x86_l_2096;
	case 8347ULL: goto x86_l_209b;
	case 8350ULL: goto x86_l_209e;
	case 8352ULL: goto x86_l_20a0;
	case 8357ULL: goto x86_l_20a5;
	case 8364ULL: goto x86_l_20ac;
	case 8369ULL: goto x86_l_20b1;
	case 8374ULL: goto x86_l_20b6;
	case 8381ULL: goto x86_l_20bd;
	case 8386ULL: goto x86_l_20c2;
	case 8391ULL: goto x86_l_20c7;
	case 8393ULL: goto x86_l_20c9;
	case 8396ULL: goto x86_l_20cc;
	case 8398ULL: goto x86_l_20ce;
	case 8400ULL: goto x86_l_20d0;
	case 8405ULL: goto x86_l_20d5;
	case 8408ULL: goto x86_l_20d8;
	case 8412ULL: goto x86_l_20dc;
	case 8416ULL: goto x86_l_20e0;
	case 8419ULL: goto x86_l_20e3;
	case 8422ULL: goto x86_l_20e6;
	case 8428ULL: goto x86_l_20ec;
	case 8433ULL: goto x86_l_20f1;
	case 8438ULL: goto x86_l_20f6;
	case 8443ULL: goto x86_l_20fb;
	case 8455ULL: goto x86_l_2107;
	case 8461ULL: goto x86_l_210d;
	case 8466ULL: goto x86_l_2112;
	case 8471ULL: goto x86_l_2117;
	case 8476ULL: goto x86_l_211c;
	case 8478ULL: goto x86_l_211e;
	case 8482ULL: goto x86_l_2122;
	case 8484ULL: goto x86_l_2124;
	case 8489ULL: goto x86_l_2129;
	case 8493ULL: goto x86_l_212d;
	case 8497ULL: goto x86_l_2131;
	case 8501ULL: goto x86_l_2135;
	case 8506ULL: goto x86_l_213a;
	case 8511ULL: goto x86_l_213f;
	case 8516ULL: goto x86_l_2144;
	case 8525ULL: goto x86_l_214d;
	case 8533ULL: goto x86_l_2155;
	case 8541ULL: goto x86_l_215d;
	case 8548ULL: goto x86_l_2164;
	case 8550ULL: goto x86_l_2166;
	case 8558ULL: goto x86_l_216e;
	case 8563ULL: goto x86_l_2173;
	case 8568ULL: goto x86_l_2178;
	case 8570ULL: goto x86_l_217a;
	case 8572ULL: goto x86_l_217c;
	case 8575ULL: goto x86_l_217f;
	case 8581ULL: goto x86_l_2185;
	case 8583ULL: goto x86_l_2187;
	case 8588ULL: goto x86_l_218c;
	case 8595ULL: goto x86_l_2193;
	case 8605ULL: goto x86_l_219d;
	case 8610ULL: goto x86_l_21a2;
	case 8617ULL: goto x86_l_21a9;
	case 8622ULL: goto x86_l_21ae;
	case 8627ULL: goto x86_l_21b3;
	case 8629ULL: goto x86_l_21b5;
	case 8632ULL: goto x86_l_21b8;
	case 8638ULL: goto x86_l_21be;
	case 8640ULL: goto x86_l_21c0;
	case 8645ULL: goto x86_l_21c5;
	case 8648ULL: goto x86_l_21c8;
	case 8654ULL: goto x86_l_21ce;
	case 8657ULL: goto x86_l_21d1;
	case 8663ULL: goto x86_l_21d7;
	case 8668ULL: goto x86_l_21dc;
	case 8674ULL: goto x86_l_21e2;
	case 8679ULL: goto x86_l_21e7;
	case 8684ULL: goto x86_l_21ec;
	case 8689ULL: goto x86_l_21f1;
	case 8693ULL: goto x86_l_21f5;
	case 8698ULL: goto x86_l_21fa;
	case 8703ULL: goto x86_l_21ff;
	case 8708ULL: goto x86_l_2204;
	case 8710ULL: goto x86_l_2206;
	case 8715ULL: goto x86_l_220b;
	case 8719ULL: goto x86_l_220f;
	case 8724ULL: goto x86_l_2214;
	case 8729ULL: goto x86_l_2219;
	case 8734ULL: goto x86_l_221e;
	case 8737ULL: goto x86_l_2221;
	case 8739ULL: goto x86_l_2223;
	case 8744ULL: goto x86_l_2228;
	case 8748ULL: goto x86_l_222c;
	case 8754ULL: goto x86_l_2232;
	case 8759ULL: goto x86_l_2237;
	case 8764ULL: goto x86_l_223c;
	case 8769ULL: goto x86_l_2241;
	case 8775ULL: goto x86_l_2247;
	case 8780ULL: goto x86_l_224c;
	case 8785ULL: goto x86_l_2251;
	case 8790ULL: goto x86_l_2256;
	case 8794ULL: goto x86_l_225a;
	case 8799ULL: goto x86_l_225f;
	case 8804ULL: goto x86_l_2264;
	case 8809ULL: goto x86_l_2269;
	case 8814ULL: goto x86_l_226e;
	case 8819ULL: goto x86_l_2273;
	case 8821ULL: goto x86_l_2275;
	case 8824ULL: goto x86_l_2278;
	case 8830ULL: goto x86_l_227e;
	case 8835ULL: goto x86_l_2283;
	case 8839ULL: goto x86_l_2287;
	case 8847ULL: goto x86_l_228f;
	case 8852ULL: goto x86_l_2294;
	case 8857ULL: goto x86_l_2299;
	case 8862ULL: goto x86_l_229e;
	case 8864ULL: goto x86_l_22a0;
	case 8869ULL: goto x86_l_22a5;
	case 8873ULL: goto x86_l_22a9;
	case 8878ULL: goto x86_l_22ae;
	case 8886ULL: goto x86_l_22b6;
	case 8889ULL: goto x86_l_22b9;
	case 8894ULL: goto x86_l_22be;
	case 8899ULL: goto x86_l_22c3;
	case 8907ULL: goto x86_l_22cb;
	case 8912ULL: goto x86_l_22d0;
	case 8914ULL: goto x86_l_22d2;
	case 8918ULL: goto x86_l_22d6;
	case 8926ULL: goto x86_l_22de;
	case 8931ULL: goto x86_l_22e3;
	case 8936ULL: goto x86_l_22e8;
	case 8941ULL: goto x86_l_22ed;
	case 8944ULL: goto x86_l_22f0;
	case 8946ULL: goto x86_l_22f2;
	case 8952ULL: goto x86_l_22f8;
	case 8955ULL: goto x86_l_22fb;
	case 8957ULL: goto x86_l_22fd;
	case 8959ULL: goto x86_l_22ff;
	case 8967ULL: goto x86_l_2307;
	case 8970ULL: goto x86_l_230a;
	case 8975ULL: goto x86_l_230f;
	case 8977ULL: goto x86_l_2311;
	case 8982ULL: goto x86_l_2316;
	case 8987ULL: goto x86_l_231b;
	case 8990ULL: goto x86_l_231e;
	case 8993ULL: goto x86_l_2321;
	case 8996ULL: goto x86_l_2324;
	case 9001ULL: goto x86_l_2329;
	case 9005ULL: goto x86_l_232d;
	case 9010ULL: goto x86_l_2332;
	case 9015ULL: goto x86_l_2337;
	case 9020ULL: goto x86_l_233c;
	case 9023ULL: goto x86_l_233f;
	case 9025ULL: goto x86_l_2341;
	case 9028ULL: goto x86_l_2344;
	case 9030ULL: goto x86_l_2346;
	case 9032ULL: goto x86_l_2348;
	case 9037ULL: goto x86_l_234d;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1c74:
	/* 0x1c74: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c76:
	/* 0x1c76: lea    rdi,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1c7a:
	/* 0x1c7a: lea    rdx,[r13+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_1c81:
	/* 0x1c81: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1c86:
	/* 0x1c86: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c8b:
	/* 0x1c8b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c90:
	/* 0x1c90: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c92:
	/* 0x1c92: lea    rdi,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c96:
	/* 0x1c96: lea    rdx,[r13+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1c9d:
	/* 0x1c9d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1ca2:
	/* 0x1ca2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ca7:
	/* 0x1ca7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1cac:
	/* 0x1cac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cae:
	/* 0x1cae: add    r15,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1cb2:
	/* 0x1cb2: add    r13,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_1cb9:
	/* 0x1cb9: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1cbe:
	/* 0x1cbe: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1cc3:
	/* 0x1cc3: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1cc6:
	/* 0x1cc6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ccb:
	/* 0x1ccb: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1cce:
	/* 0x1cce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cd0:
	/* 0x1cd0: mov    r15d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 16ULL);
x86_l_1cd6:
	/* 0x1cd6: jmp    2247 <generic_fentry_process_event+0x2247> */
	goto x86_l_2247;
x86_l_1cdb:
	/* 0x1cdb: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ce0:
	/* 0x1ce0: lea    rdx,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ce4:
	/* 0x1ce4: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1ce9:
	/* 0x1ce9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1cee:
	/* 0x1cee: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cf3:
	/* 0x1cf3: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1cf6:
	/* 0x1cf6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1cfb:
	/* 0x1cfb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cfd:
	/* 0x1cfd: lea    rdi,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d01:
	/* 0x1d01: lea    rdx,[r13+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1d05:
	/* 0x1d05: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d0a:
	/* 0x1d0a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d0f:
	/* 0x1d0f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d14:
	/* 0x1d14: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d16:
	/* 0x1d16: lea    rdi,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d1a:
	/* 0x1d1a: lea    rdx,[r13+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d1e:
	/* 0x1d1e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d23:
	/* 0x1d23: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d28:
	/* 0x1d28: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d2d:
	/* 0x1d2d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d2f:
	/* 0x1d2f: lea    rdi,[r15+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1d33:
	/* 0x1d33: lea    rdx,[r13+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1d37:
	/* 0x1d37: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d3c:
	/* 0x1d3c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d41:
	/* 0x1d41: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d46:
	/* 0x1d46: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d48:
	/* 0x1d48: add    r15,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1d4c:
	/* 0x1d4c: add    r13,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_1d50:
	/* 0x1d50: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1d55:
	/* 0x1d55: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d5a:
	/* 0x1d5a: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1d5d:
	/* 0x1d5d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1d62:
	/* 0x1d62: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1d65:
	/* 0x1d65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d67:
	/* 0x1d67: mov    r15d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 32ULL);
x86_l_1d6d:
	/* 0x1d6d: jmp    2247 <generic_fentry_process_event+0x2247> */
	goto x86_l_2247;
x86_l_1d72:
	/* 0x1d72: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d77:
	/* 0x1d77: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d7c:
	/* 0x1d7c: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d81:
	/* 0x1d81: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d86:
	/* 0x1d86: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1d89:
	/* 0x1d89: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d8e:
	/* 0x1d8e: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1d91:
	/* 0x1d91: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d93:
	/* 0x1d93: lea    rdi,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d97:
	/* 0x1d97: lea    rdx,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d9b:
	/* 0x1d9b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1da0:
	/* 0x1da0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1da5:
	/* 0x1da5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1daa:
	/* 0x1daa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dac:
	/* 0x1dac: add    r15,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1db0:
	/* 0x1db0: add    r13,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_1db4:
	/* 0x1db4: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1db9:
	/* 0x1db9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1dbe:
	/* 0x1dbe: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1dc1:
	/* 0x1dc1: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1dc6:
	/* 0x1dc6: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1dc9:
	/* 0x1dc9: jmp    1e5e <generic_fentry_process_event+0x1e5e> */
	goto x86_l_1e5e;
x86_l_1dce:
	/* 0x1dce: lea    rdx,[r8+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1dd2:
	/* 0x1dd2: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1dd7:
	/* 0x1dd7: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1ddc:
	/* 0x1ddc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1de1:
	/* 0x1de1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1de6:
	/* 0x1de6: mov    r13,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R8, X86_WIDTH_64);
x86_l_1de9:
	/* 0x1de9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1deb:
	/* 0x1deb: mov    eax,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1def:
	/* 0x1def: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1df4:
	/* 0x1df4: mov    DWORD PTR [r15],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1df7:
	/* 0x1df7: lea    rdx,[r13+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1dfb:
	/* 0x1dfb: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1e00:
	/* 0x1e00: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1e05:
	/* 0x1e05: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e0a:
	/* 0x1e0a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e0f:
	/* 0x1e0f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e11:
	/* 0x1e11: mov    eax,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1e15:
	/* 0x1e15: mov    DWORD PTR [r15+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1e19:
	/* 0x1e19: add    r13,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_1e1d:
	/* 0x1e1d: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1e22:
	/* 0x1e22: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1e27:
	/* 0x1e27: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1e2c:
	/* 0x1e2c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e31:
	/* 0x1e31: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1e34:
	/* 0x1e34: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e36:
	/* 0x1e36: add    r15,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1e3a:
	/* 0x1e3a: mov    edx,0x3e8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1000ULL);
x86_l_1e3f:
	/* 0x1e3f: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1e44:
	/* 0x1e44: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1e47:
	/* 0x1e47: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1e4c:
	/* 0x1e4c: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1e51:
	/* 0x1e51: add    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 104ULL);
x86_l_1e56:
	/* 0x1e56: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1e59:
	/* 0x1e59: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1e5e:
	/* 0x1e5e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e60:
	/* 0x1e60: jmp    2241 <generic_fentry_process_event+0x2241> */
	goto x86_l_2241;
x86_l_1e65:
	/* 0x1e65: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e6a:
	/* 0x1e6a: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1e72:
	/* 0x1e72: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1e7a:
	/* 0x1e7a: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1e82:
	/* 0x1e82: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1e8a:
	/* 0x1e8a: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1e92:
	/* 0x1e92: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1e9a:
	/* 0x1e9a: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1ea2:
	/* 0x1ea2: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1eaa:
	/* 0x1eaa: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1eb2:
	/* 0x1eb2: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1eb9:
	/* 0x1eb9: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1ebe:
	/* 0x1ebe: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1ec3:
	/* 0x1ec3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ec8:
	/* 0x1ec8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ecd:
	/* 0x1ecd: mov    rdx,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R8, X86_WIDTH_64);
x86_l_1ed0:
	/* 0x1ed0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ed2:
	/* 0x1ed2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ed5:
	/* 0x1ed5: je     2251 <generic_fentry_process_event+0x2251> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2251;
	}
x86_l_1edb:
	/* 0x1edb: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ede:
	/* 0x1ede: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ee3:
	/* 0x1ee3: jmp    3334 <generic_fentry_process_event+0x3334> */
	return 13108ULL;
x86_l_1ee8:
	/* 0x1ee8: mov    r15,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1eef:
	/* 0x1eef: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ef4:
	/* 0x1ef4: jmp    332f <generic_fentry_process_event+0x332f> */
	return 13103ULL;
x86_l_1ef9:
	/* 0x1ef9: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1efe:
	/* 0x1efe: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1f06:
	/* 0x1f06: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_1f0b:
	/* 0x1f0b: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f10:
	/* 0x1f10: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1f15:
	/* 0x1f15: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f1a:
	/* 0x1f1a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f1f:
	/* 0x1f1f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f21:
	/* 0x1f21: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1f25:
	/* 0x1f25: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1f2a:
	/* 0x1f2a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1f2f:
	/* 0x1f2f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f34:
	/* 0x1f34: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f39:
	/* 0x1f39: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1f3c:
	/* 0x1f3c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f3e:
	/* 0x1f3e: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1f46:
	/* 0x1f46: mov    r14,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1f4b:
	/* 0x1f4b: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1f50:
	/* 0x1f50: lea    r12,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1f54:
	/* 0x1f54: add    r12,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_1f5b:
	/* 0x1f5b: test   BYTE PTR [rsp+0x40],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 274877906976ULL);
x86_l_1f60:
	/* 0x1f60: je     2a34 <generic_fentry_process_event+0x2a34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10804ULL;
	}
x86_l_1f66:
	/* 0x1f66: cmp    r14,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 4096ULL);
x86_l_1f6d:
	/* 0x1f6d: jb     2a08 <generic_fentry_process_event+0x2a08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10760ULL;
	}
x86_l_1f73:
	/* 0x1f73: mov    DWORD PTR [r12],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1f7b:
	/* 0x1f7b: add    r12,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1f7f:
	/* 0x1f7f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1f82:
	/* 0x1f82: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1f85:
	/* 0x1f85: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_1f88:
	/* 0x1f88: jmp    2bbe <generic_fentry_process_event+0x2bbe> */
	return 11198ULL;
x86_l_1f8d:
	/* 0x1f8d: mov    rbx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1f92:
	/* 0x1f92: mov    DWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_1f9d:
	/* 0x1f9d: movzx  ebp,WORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 192ULL);
x86_l_1fa5:
	/* 0x1fa5: mov    rdi,QWORD PTR [rip+0x2e6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_ipv6_ext_heap)));
x86_l_1fac:
	/* 0x1fac: lea    rsi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1fb4:
	/* 0x1fb4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1fb9:
	/* 0x1fb9: lea    r13,[rbx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1fbd:
	/* 0x1fbd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fbf:
	/* 0x1fbf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1fc2:
	/* 0x1fc2: je     316a <generic_fentry_process_event+0x316a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12650ULL;
	}
x86_l_1fc8:
	/* 0x1fc8: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1fcb:
	/* 0x1fcb: mov    WORD PTR [rax],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fce:
	/* 0x1fce: mov    BYTE PTR [rax+0x5],0xff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21474836735ULL);
x86_l_1fd2:
	/* 0x1fd2: mov    BYTE PTR [rax+0x7],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30064771072ULL);
x86_l_1fd6:
	/* 0x1fd6: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1fd9:
	/* 0x1fd9: add    rdi,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 6ULL);
x86_l_1fdd:
	/* 0x1fdd: lea    rdx,[r13+0x6] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_1fe1:
	/* 0x1fe1: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1fe6:
	/* 0x1fe6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1feb:
	/* 0x1feb: mov    QWORD PTR [rsp+0x20],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ff0:
	/* 0x1ff0: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1ff5:
	/* 0x1ff5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ff7:
	/* 0x1ff7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ffa:
	/* 0x1ffa: js     316a <generic_fentry_process_event+0x316a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12650ULL;
	}
x86_l_2000:
	/* 0x2000: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2005:
	/* 0x2005: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2008:
	/* 0x2008: jg     2a8b <generic_fentry_process_event+0x2a8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10891ULL;
	}
x86_l_200e:
	/* 0x200e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2010:
	/* 0x2010: je     2b33 <generic_fentry_process_event+0x2b33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11059ULL;
	}
x86_l_2016:
	/* 0x2016: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2019:
	/* 0x2019: je     2b33 <generic_fentry_process_event+0x2b33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11059ULL;
	}
x86_l_201f:
	/* 0x201f: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2022:
	/* 0x2022: jne    2d09 <generic_fentry_process_event+0x2d09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11529ULL;
	}
x86_l_2028:
	/* 0x2028: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_202f:
	/* 0x202f: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2033:
	/* 0x2033: jmp    2c58 <generic_fentry_process_event+0x2c58> */
	return 11352ULL;
x86_l_2038:
	/* 0x2038: lea    rdx,[r15+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_203c:
	/* 0x203c: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2041:
	/* 0x2041: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2046:
	/* 0x2046: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_2049:
	/* 0x2049: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_204e:
	/* 0x204e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2050:
	/* 0x2050: lea    rdx,[r15+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2054:
	/* 0x2054: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2059:
	/* 0x2059: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_205e:
	/* 0x205e: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2061:
	/* 0x2061: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2066:
	/* 0x2066: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2068:
	/* 0x2068: lea    rdi,[r13+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_206c:
	/* 0x206c: lea    r12,[r15+0xc] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2070:
	/* 0x2070: add    r15,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_2074:
	/* 0x2074: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2079:
	/* 0x2079: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_207e:
	/* 0x207e: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2083:
	/* 0x2083: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2086:
	/* 0x2086: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2088:
	/* 0x2088: lea    rdi,[r13+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_208c:
	/* 0x208c: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2091:
	/* 0x2091: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2096:
	/* 0x2096: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_209b:
	/* 0x209b: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_209e:
	/* 0x209e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20a0:
	/* 0x20a0: movzx  eax,WORD PTR [r13+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_20a5:
	/* 0x20a5: movbe  WORD PTR [r13+0x22],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_20ac:
	/* 0x20ac: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_20b1:
	/* 0x20b1: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_20b6:
	/* 0x20b6: mov    rdi,QWORD PTR [rip+0x2e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_20bd:
	/* 0x20bd: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_20c2:
	/* 0x20c2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_20c7:
	/* 0x20c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20c9:
	/* 0x20c9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_20cc:
	/* 0x20cc: je     20e6 <generic_fentry_process_event+0x20e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20e6;
	}
x86_l_20ce:
	/* 0x20ce: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20d0:
	/* 0x20d0: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_20d5:
	/* 0x20d5: mov    DWORD PTR [rdx+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20d8:
	/* 0x20d8: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20dc:
	/* 0x20dc: mov    QWORD PTR [rdx+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_20e0:
	/* 0x20e0: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_20e3:
	/* 0x20e3: mov    DWORD PTR [rdx+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_20e6:
	/* 0x20e6: mov    r15d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 64ULL);
x86_l_20ec:
	/* 0x20ec: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20f1:
	/* 0x20f1: jmp    332f <generic_fentry_process_event+0x332f> */
	return 13103ULL;
x86_l_20f6:
	/* 0x20f6: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_20fb:
	/* 0x20fb: mov    QWORD PTR [rbp+rax*1+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 618475290624ULL);
x86_l_2107:
	/* 0x2107: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_210d:
	/* 0x210d: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2112:
	/* 0x2112: jmp    332f <generic_fentry_process_event+0x332f> */
	return 13103ULL;
x86_l_2117:
	/* 0x2117: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_211c:
	/* 0x211c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_211e:
	/* 0x211e: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_2122:
	/* 0x2122: jne    212d <generic_fentry_process_event+0x212d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_212d;
	}
x86_l_2124:
	/* 0x2124: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2129:
	/* 0x2129: mov    rax,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_212d:
	/* 0x212d: mov    rcx,QWORD PTR [rbp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2131:
	/* 0x2131: mov    rdx,QWORD PTR [rbp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2135:
	/* 0x2135: mov    QWORD PTR [rsp+0x68],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_213a:
	/* 0x213a: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_213f:
	/* 0x213f: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2144:
	/* 0x2144: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_214d:
	/* 0x214d: mov    QWORD PTR [rsp+0xa8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2155:
	/* 0x2155: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_215d:
	/* 0x215d: mov    rdi,QWORD PTR [rip+0x2e6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_2164:
	/* 0x2164: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2166:
	/* 0x2166: lea    rsi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_216e:
	/* 0x216e: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2173:
	/* 0x2173: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2178:
	/* 0x2178: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_217a:
	/* 0x217a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_217c:
	/* 0x217c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_217f:
	/* 0x217f: je     2ae2 <generic_fentry_process_event+0x2ae2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10978ULL;
	}
x86_l_2185:
	/* 0x2185: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_2187:
	/* 0x2187: mov    WORD PTR [rsp+0x58],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_218c:
	/* 0x218c: mov    WORD PTR [rsp+0x5a],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 386547056645ULL);
x86_l_2193:
	/* 0x2193: movabs rax,0x200000046 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934662ULL);
x86_l_219d:
	/* 0x219d: mov    QWORD PTR [rsp+0x5c],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_21a2:
	/* 0x21a2: mov    rdi,QWORD PTR [rip+0x2e6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_21a9:
	/* 0x21a9: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_21ae:
	/* 0x21ae: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_21b3:
	/* 0x21b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21b5:
	/* 0x21b5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_21b8:
	/* 0x21b8: je     2ab8 <generic_fentry_process_event+0x2ab8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10936ULL;
	}
x86_l_21be:
	/* 0x21be: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_21c0:
	/* 0x21c0: jmp    2ae2 <generic_fentry_process_event+0x2ae2> */
	return 10978ULL;
x86_l_21c5:
	/* 0x21c5: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_21c8:
	/* 0x21c8: je     246e <generic_fentry_process_event+0x246e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9326ULL;
	}
x86_l_21ce:
	/* 0x21ce: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_21d1:
	/* 0x21d1: jne    28ae <generic_fentry_process_event+0x28ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10414ULL;
	}
x86_l_21d7:
	/* 0x21d7: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21dc:
	/* 0x21dc: add    rax,0x5e58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24152ULL);
x86_l_21e2:
	/* 0x21e2: jmp    2479 <generic_fentry_process_event+0x2479> */
	return 9337ULL;
x86_l_21e7:
	/* 0x21e7: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21ec:
	/* 0x21ec: lea    rdi,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21f1:
	/* 0x21f1: lea    rdx,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21f5:
	/* 0x21f5: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_21fa:
	/* 0x21fa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_21ff:
	/* 0x21ff: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2204:
	/* 0x2204: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2206:
	/* 0x2206: lea    rdi,[r12+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_220b:
	/* 0x220b: add    r15,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_220f:
	/* 0x220f: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2214:
	/* 0x2214: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2219:
	/* 0x2219: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_221e:
	/* 0x221e: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2221:
	/* 0x2221: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2223:
	/* 0x2223: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2228:
	/* 0x2228: movzx  eax,WORD PTR [rcx+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_222c:
	/* 0x222c: movbe  WORD PTR [rcx+0x2],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2232:
	/* 0x2232: mov    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2237:
	/* 0x2237: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_223c:
	/* 0x223c: mov    r14,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2241:
	/* 0x2241: mov    r15d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 24ULL);
x86_l_2247:
	/* 0x2247: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_224c:
	/* 0x224c: jmp    c62 <generic_fentry_process_event+0xc62> */
	return 3170ULL;
x86_l_2251:
	/* 0x2251: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2256:
	/* 0x2256: lea    rdi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_225a:
	/* 0x225a: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_225f:
	/* 0x225f: mov    edx,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 63ULL);
x86_l_2264:
	/* 0x2264: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2269:
	/* 0x2269: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_226e:
	/* 0x226e: mov    esi,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 63ULL);
x86_l_2273:
	/* 0x2273: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2275:
	/* 0x2275: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2278:
	/* 0x2278: js     1edb <generic_fentry_process_event+0x1edb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1edb;
	}
x86_l_227e:
	/* 0x227e: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2283:
	/* 0x2283: lea    rdx,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2287:
	/* 0x2287: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_228f:
	/* 0x228f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2294:
	/* 0x2294: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2299:
	/* 0x2299: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_229e:
	/* 0x229e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22a0:
	/* 0x22a0: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22a5:
	/* 0x22a5: lea    rdi,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22a9:
	/* 0x22a9: mov    edx,0x348 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 840ULL);
x86_l_22ae:
	/* 0x22ae: mov    rcx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_22b6:
	/* 0x22b6: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_22b9:
	/* 0x22b9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22be:
	/* 0x22be: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22c3:
	/* 0x22c3: add    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 168ULL);
x86_l_22cb:
	/* 0x22cb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22d0:
	/* 0x22d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22d2:
	/* 0x22d2: add    r15,0x58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 88ULL);
x86_l_22d6:
	/* 0x22d6: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_22de:
	/* 0x22de: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_22e3:
	/* 0x22e3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22e8:
	/* 0x22e8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_22ed:
	/* 0x22ed: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_22f0:
	/* 0x22f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22f2:
	/* 0x22f2: mov    r15d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 80ULL);
x86_l_22f8:
	/* 0x22f8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_22fb:
	/* 0x22fb: jne    2311 <generic_fentry_process_event+0x2311> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2311;
	}
x86_l_22fd:
	/* 0x22fd: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_22ff:
	/* 0x22ff: cmp    DWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_2307:
	/* 0x2307: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_230a:
	/* 0x230a: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_230f:
	/* 0x230f: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2311:
	/* 0x2311: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2316:
	/* 0x2316: jmp    3334 <generic_fentry_process_event+0x3334> */
	return 13108ULL;
x86_l_231b:
	/* 0x231b: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_231e:
	/* 0x231e: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_2321:
	/* 0x2321: mov    r12,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R13, X86_WIDTH_64);
x86_l_2324:
	/* 0x2324: jmp    3334 <generic_fentry_process_event+0x3334> */
	return 13108ULL;
x86_l_2329:
	/* 0x2329: add    r15,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_232d:
	/* 0x232d: mov    ecx,0x6b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 107ULL);
x86_l_2332:
	/* 0x2332: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2337:
	/* 0x2337: mov    esi,0x6b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 107ULL);
x86_l_233c:
	/* 0x233c: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_233f:
	/* 0x233f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2341:
	/* 0x2341: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_2344:
	/* 0x2344: mov    al,0x6b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 107ULL);
x86_l_2346:
	/* 0x2346: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2348:
	/* 0x2348: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_234d:
	/* 0x234d: mov    r14,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
	return 9042ULL;
}

static __noinline __u64 tetragon_bpf_generic_fentry_v61_generic_fentry_process_event_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9042ULL: goto x86_l_2352;
	case 9044ULL: goto x86_l_2354;
	case 9049ULL: goto x86_l_2359;
	case 9052ULL: goto x86_l_235c;
	case 9058ULL: goto x86_l_2362;
	case 9063ULL: goto x86_l_2367;
	case 9068ULL: goto x86_l_236c;
	case 9073ULL: goto x86_l_2371;
	case 9076ULL: goto x86_l_2374;
	case 9082ULL: goto x86_l_237a;
	case 9085ULL: goto x86_l_237d;
	case 9091ULL: goto x86_l_2383;
	case 9098ULL: goto x86_l_238a;
	case 9103ULL: goto x86_l_238f;
	case 9107ULL: goto x86_l_2393;
	case 9112ULL: goto x86_l_2398;
	case 9117ULL: goto x86_l_239d;
	case 9122ULL: goto x86_l_23a2;
	case 9127ULL: goto x86_l_23a7;
	case 9129ULL: goto x86_l_23a9;
	case 9133ULL: goto x86_l_23ad;
	case 9138ULL: goto x86_l_23b2;
	case 9143ULL: goto x86_l_23b7;
	case 9146ULL: goto x86_l_23ba;
	case 9151ULL: goto x86_l_23bf;
	case 9153ULL: goto x86_l_23c1;
	case 9158ULL: goto x86_l_23c6;
	case 9162ULL: goto x86_l_23ca;
	case 9166ULL: goto x86_l_23ce;
	case 9170ULL: goto x86_l_23d2;
	case 9175ULL: goto x86_l_23d7;
	case 9180ULL: goto x86_l_23dc;
	case 9185ULL: goto x86_l_23e1;
	case 9188ULL: goto x86_l_23e4;
	case 9190ULL: goto x86_l_23e6;
	case 9194ULL: goto x86_l_23ea;
	case 9199ULL: goto x86_l_23ef;
	case 9204ULL: goto x86_l_23f4;
	case 9209ULL: goto x86_l_23f9;
	case 9212ULL: goto x86_l_23fc;
	case 9214ULL: goto x86_l_23fe;
	case 9218ULL: goto x86_l_2402;
	case 9224ULL: goto x86_l_2408;
	case 9229ULL: goto x86_l_240d;
	case 9233ULL: goto x86_l_2411;
	case 9238ULL: goto x86_l_2416;
	case 9245ULL: goto x86_l_241d;
	case 9250ULL: goto x86_l_2422;
	case 9255ULL: goto x86_l_2427;
	case 9257ULL: goto x86_l_2429;
	case 9260ULL: goto x86_l_242c;
	case 9262ULL: goto x86_l_242e;
	case 9264ULL: goto x86_l_2430;
	case 9269ULL: goto x86_l_2435;
	case 9272ULL: goto x86_l_2438;
	case 9276ULL: goto x86_l_243c;
	case 9280ULL: goto x86_l_2440;
	case 9283ULL: goto x86_l_2443;
	case 9286ULL: goto x86_l_2446;
	case 9292ULL: goto x86_l_244c;
	case 9295ULL: goto x86_l_244f;
	case 9300ULL: goto x86_l_2454;
	case 9305ULL: goto x86_l_2459;
	case 9311ULL: goto x86_l_245f;
	case 9313ULL: goto x86_l_2461;
	case 9318ULL: goto x86_l_2466;
	case 9324ULL: goto x86_l_246c;
	case 9326ULL: goto x86_l_246e;
	case 9331ULL: goto x86_l_2473;
	case 9337ULL: goto x86_l_2479;
	case 9340ULL: goto x86_l_247c;
	case 9345ULL: goto x86_l_2481;
	case 9351ULL: goto x86_l_2487;
	case 9354ULL: goto x86_l_248a;
	case 9360ULL: goto x86_l_2490;
	case 9365ULL: goto x86_l_2495;
	case 9371ULL: goto x86_l_249b;
	case 9376ULL: goto x86_l_24a0;
	case 9381ULL: goto x86_l_24a5;
	case 9386ULL: goto x86_l_24aa;
	case 9391ULL: goto x86_l_24af;
	case 9393ULL: goto x86_l_24b1;
	case 9398ULL: goto x86_l_24b6;
	case 9400ULL: goto x86_l_24b8;
	case 9406ULL: goto x86_l_24be;
	case 9411ULL: goto x86_l_24c3;
	case 9416ULL: goto x86_l_24c8;
	case 9419ULL: goto x86_l_24cb;
	case 9424ULL: goto x86_l_24d0;
	case 9431ULL: goto x86_l_24d7;
	case 9437ULL: goto x86_l_24dd;
	case 9442ULL: goto x86_l_24e2;
	case 9446ULL: goto x86_l_24e6;
	case 9449ULL: goto x86_l_24e9;
	case 9455ULL: goto x86_l_24ef;
	case 9458ULL: goto x86_l_24f2;
	case 9463ULL: goto x86_l_24f7;
	case 9468ULL: goto x86_l_24fc;
	case 9473ULL: goto x86_l_2501;
	case 9478ULL: goto x86_l_2506;
	case 9480ULL: goto x86_l_2508;
	case 9485ULL: goto x86_l_250d;
	case 9487ULL: goto x86_l_250f;
	case 9493ULL: goto x86_l_2515;
	case 9497ULL: goto x86_l_2519;
	case 9503ULL: goto x86_l_251f;
	case 9508ULL: goto x86_l_2524;
	case 9512ULL: goto x86_l_2528;
	case 9517ULL: goto x86_l_252d;
	case 9523ULL: goto x86_l_2533;
	case 9528ULL: goto x86_l_2538;
	case 9533ULL: goto x86_l_253d;
	case 9538ULL: goto x86_l_2542;
	case 9540ULL: goto x86_l_2544;
	case 9545ULL: goto x86_l_2549;
	case 9547ULL: goto x86_l_254b;
	case 9553ULL: goto x86_l_2551;
	case 9558ULL: goto x86_l_2556;
	case 9563ULL: goto x86_l_255b;
	case 9568ULL: goto x86_l_2560;
	case 9574ULL: goto x86_l_2566;
	case 9580ULL: goto x86_l_256c;
	case 9585ULL: goto x86_l_2571;
	case 9590ULL: goto x86_l_2576;
	case 9593ULL: goto x86_l_2579;
	case 9599ULL: goto x86_l_257f;
	case 9602ULL: goto x86_l_2582;
	case 9607ULL: goto x86_l_2587;
	case 9612ULL: goto x86_l_258c;
	case 9617ULL: goto x86_l_2591;
	case 9622ULL: goto x86_l_2596;
	case 9624ULL: goto x86_l_2598;
	case 9629ULL: goto x86_l_259d;
	case 9631ULL: goto x86_l_259f;
	case 9637ULL: goto x86_l_25a5;
	case 9642ULL: goto x86_l_25aa;
	case 9647ULL: goto x86_l_25af;
	case 9651ULL: goto x86_l_25b3;
	case 9657ULL: goto x86_l_25b9;
	case 9662ULL: goto x86_l_25be;
	case 9666ULL: goto x86_l_25c2;
	case 9671ULL: goto x86_l_25c7;
	case 9677ULL: goto x86_l_25cd;
	case 9682ULL: goto x86_l_25d2;
	case 9687ULL: goto x86_l_25d7;
	case 9692ULL: goto x86_l_25dc;
	case 9694ULL: goto x86_l_25de;
	case 9699ULL: goto x86_l_25e3;
	case 9701ULL: goto x86_l_25e5;
	case 9707ULL: goto x86_l_25eb;
	case 9712ULL: goto x86_l_25f0;
	case 9717ULL: goto x86_l_25f5;
	case 9725ULL: goto x86_l_25fd;
	case 9731ULL: goto x86_l_2603;
	case 9737ULL: goto x86_l_2609;
	case 9742ULL: goto x86_l_260e;
	case 9747ULL: goto x86_l_2613;
	case 9750ULL: goto x86_l_2616;
	case 9756ULL: goto x86_l_261c;
	case 9759ULL: goto x86_l_261f;
	case 9764ULL: goto x86_l_2624;
	case 9769ULL: goto x86_l_2629;
	case 9777ULL: goto x86_l_2631;
	case 9782ULL: goto x86_l_2636;
	case 9784ULL: goto x86_l_2638;
	case 9789ULL: goto x86_l_263d;
	case 9791ULL: goto x86_l_263f;
	case 9797ULL: goto x86_l_2645;
	case 9805ULL: goto x86_l_264d;
	case 9810ULL: goto x86_l_2652;
	case 9814ULL: goto x86_l_2656;
	case 9820ULL: goto x86_l_265c;
	case 9825ULL: goto x86_l_2661;
	case 9829ULL: goto x86_l_2665;
	case 9834ULL: goto x86_l_266a;
	case 9840ULL: goto x86_l_2670;
	case 9845ULL: goto x86_l_2675;
	case 9850ULL: goto x86_l_267a;
	case 9855ULL: goto x86_l_267f;
	case 9857ULL: goto x86_l_2681;
	case 9862ULL: goto x86_l_2686;
	case 9864ULL: goto x86_l_2688;
	case 9870ULL: goto x86_l_268e;
	case 9875ULL: goto x86_l_2693;
	case 9880ULL: goto x86_l_2698;
	case 9885ULL: goto x86_l_269d;
	case 9891ULL: goto x86_l_26a3;
	case 9897ULL: goto x86_l_26a9;
	case 9905ULL: goto x86_l_26b1;
	case 9908ULL: goto x86_l_26b4;
	case 9911ULL: goto x86_l_26b7;
	case 9917ULL: goto x86_l_26bd;
	case 9920ULL: goto x86_l_26c0;
	case 9925ULL: goto x86_l_26c5;
	case 9930ULL: goto x86_l_26ca;
	case 9935ULL: goto x86_l_26cf;
	case 9940ULL: goto x86_l_26d4;
	case 9942ULL: goto x86_l_26d6;
	case 9947ULL: goto x86_l_26db;
	case 9949ULL: goto x86_l_26dd;
	case 9955ULL: goto x86_l_26e3;
	case 9960ULL: goto x86_l_26e8;
	case 9965ULL: goto x86_l_26ed;
	case 9969ULL: goto x86_l_26f1;
	case 9975ULL: goto x86_l_26f7;
	case 9980ULL: goto x86_l_26fc;
	case 9984ULL: goto x86_l_2700;
	case 9989ULL: goto x86_l_2705;
	case 9995ULL: goto x86_l_270b;
	case 10000ULL: goto x86_l_2710;
	case 10005ULL: goto x86_l_2715;
	case 10010ULL: goto x86_l_271a;
	case 10012ULL: goto x86_l_271c;
	case 10017ULL: goto x86_l_2721;
	case 10019ULL: goto x86_l_2723;
	case 10025ULL: goto x86_l_2729;
	case 10030ULL: goto x86_l_272e;
	case 10035ULL: goto x86_l_2733;
	case 10040ULL: goto x86_l_2738;
	case 10046ULL: goto x86_l_273e;
	case 10052ULL: goto x86_l_2744;
	case 10057ULL: goto x86_l_2749;
	case 10060ULL: goto x86_l_274c;
	case 10063ULL: goto x86_l_274f;
	case 10069ULL: goto x86_l_2755;
	case 10072ULL: goto x86_l_2758;
	case 10077ULL: goto x86_l_275d;
	case 10082ULL: goto x86_l_2762;
	case 10087ULL: goto x86_l_2767;
	case 10092ULL: goto x86_l_276c;
	case 10094ULL: goto x86_l_276e;
	case 10099ULL: goto x86_l_2773;
	case 10101ULL: goto x86_l_2775;
	case 10107ULL: goto x86_l_277b;
	case 10112ULL: goto x86_l_2780;
	case 10117ULL: goto x86_l_2785;
	case 10121ULL: goto x86_l_2789;
	case 10127ULL: goto x86_l_278f;
	case 10132ULL: goto x86_l_2794;
	case 10136ULL: goto x86_l_2798;
	case 10141ULL: goto x86_l_279d;
	case 10147ULL: goto x86_l_27a3;
	case 10152ULL: goto x86_l_27a8;
	case 10157ULL: goto x86_l_27ad;
	case 10162ULL: goto x86_l_27b2;
	case 10164ULL: goto x86_l_27b4;
	case 10169ULL: goto x86_l_27b9;
	case 10171ULL: goto x86_l_27bb;
	case 10177ULL: goto x86_l_27c1;
	case 10182ULL: goto x86_l_27c6;
	case 10187ULL: goto x86_l_27cb;
	case 10192ULL: goto x86_l_27d0;
	case 10198ULL: goto x86_l_27d6;
	case 10204ULL: goto x86_l_27dc;
	case 10209ULL: goto x86_l_27e1;
	case 10212ULL: goto x86_l_27e4;
	case 10215ULL: goto x86_l_27e7;
	case 10221ULL: goto x86_l_27ed;
	case 10224ULL: goto x86_l_27f0;
	case 10229ULL: goto x86_l_27f5;
	case 10234ULL: goto x86_l_27fa;
	case 10239ULL: goto x86_l_27ff;
	case 10244ULL: goto x86_l_2804;
	case 10246ULL: goto x86_l_2806;
	case 10251ULL: goto x86_l_280b;
	case 10253ULL: goto x86_l_280d;
	case 10259ULL: goto x86_l_2813;
	case 10264ULL: goto x86_l_2818;
	case 10269ULL: goto x86_l_281d;
	case 10273ULL: goto x86_l_2821;
	case 10279ULL: goto x86_l_2827;
	case 10284ULL: goto x86_l_282c;
	case 10288ULL: goto x86_l_2830;
	case 10293ULL: goto x86_l_2835;
	case 10299ULL: goto x86_l_283b;
	case 10304ULL: goto x86_l_2840;
	case 10309ULL: goto x86_l_2845;
	case 10314ULL: goto x86_l_284a;
	case 10316ULL: goto x86_l_284c;
	case 10321ULL: goto x86_l_2851;
	case 10323ULL: goto x86_l_2853;
	case 10325ULL: goto x86_l_2855;
	case 10330ULL: goto x86_l_285a;
	case 10335ULL: goto x86_l_285f;
	case 10342ULL: goto x86_l_2866;
	case 10344ULL: goto x86_l_2868;
	case 10349ULL: goto x86_l_286d;
	case 10352ULL: goto x86_l_2870;
	case 10358ULL: goto x86_l_2876;
	case 10361ULL: goto x86_l_2879;
	case 10366ULL: goto x86_l_287e;
	case 10371ULL: goto x86_l_2883;
	case 10376ULL: goto x86_l_2888;
	case 10379ULL: goto x86_l_288b;
	case 10381ULL: goto x86_l_288d;
	case 10386ULL: goto x86_l_2892;
	case 10388ULL: goto x86_l_2894;
	case 10390ULL: goto x86_l_2896;
	case 10395ULL: goto x86_l_289b;
	case 10400ULL: goto x86_l_28a0;
	case 10405ULL: goto x86_l_28a5;
	case 10409ULL: goto x86_l_28a9;
	case 10414ULL: goto x86_l_28ae;
	case 10417ULL: goto x86_l_28b1;
	case 10422ULL: goto x86_l_28b6;
	case 10427ULL: goto x86_l_28bb;
	case 10432ULL: goto x86_l_28c0;
	case 10438ULL: goto x86_l_28c6;
	case 10443ULL: goto x86_l_28cb;
	case 10445ULL: goto x86_l_28cd;
	case 10449ULL: goto x86_l_28d1;
	case 10451ULL: goto x86_l_28d3;
	case 10455ULL: goto x86_l_28d7;
	case 10460ULL: goto x86_l_28dc;
	case 10464ULL: goto x86_l_28e0;
	case 10468ULL: goto x86_l_28e4;
	case 10473ULL: goto x86_l_28e9;
	case 10478ULL: goto x86_l_28ee;
	case 10483ULL: goto x86_l_28f3;
	case 10488ULL: goto x86_l_28f8;
	case 10496ULL: goto x86_l_2900;
	case 10504ULL: goto x86_l_2908;
	case 10511ULL: goto x86_l_290f;
	case 10513ULL: goto x86_l_2911;
	case 10521ULL: goto x86_l_2919;
	case 10526ULL: goto x86_l_291e;
	case 10531ULL: goto x86_l_2923;
	case 10533ULL: goto x86_l_2925;
	case 10535ULL: goto x86_l_2927;
	case 10538ULL: goto x86_l_292a;
	case 10544ULL: goto x86_l_2930;
	case 10546ULL: goto x86_l_2932;
	case 10551ULL: goto x86_l_2937;
	case 10558ULL: goto x86_l_293e;
	case 10568ULL: goto x86_l_2948;
	case 10573ULL: goto x86_l_294d;
	case 10580ULL: goto x86_l_2954;
	case 10585ULL: goto x86_l_2959;
	case 10590ULL: goto x86_l_295e;
	case 10592ULL: goto x86_l_2960;
	case 10595ULL: goto x86_l_2963;
	case 10601ULL: goto x86_l_2969;
	case 10603ULL: goto x86_l_296b;
	case 10608ULL: goto x86_l_2970;
	case 10610ULL: goto x86_l_2972;
	case 10615ULL: goto x86_l_2977;
	case 10620ULL: goto x86_l_297c;
	case 10625ULL: goto x86_l_2981;
	case 10629ULL: goto x86_l_2985;
	case 10634ULL: goto x86_l_298a;
	case 10638ULL: goto x86_l_298e;
	case 10643ULL: goto x86_l_2993;
	case 10650ULL: goto x86_l_299a;
	case 10657ULL: goto x86_l_29a1;
	case 10662ULL: goto x86_l_29a6;
	case 10666ULL: goto x86_l_29aa;
	case 10673ULL: goto x86_l_29b1;
	case 10676ULL: goto x86_l_29b4;
	case 10682ULL: goto x86_l_29ba;
	case 10689ULL: goto x86_l_29c1;
	case 10695ULL: goto x86_l_29c7;
	case 10699ULL: goto x86_l_29cb;
	case 10703ULL: goto x86_l_29cf;
	case 10708ULL: goto x86_l_29d4;
	case 10711ULL: goto x86_l_29d7;
	case 10713ULL: goto x86_l_29d9;
	case 10715ULL: goto x86_l_29db;
	case 10717ULL: goto x86_l_29dd;
	case 10720ULL: goto x86_l_29e0;
	case 10724ULL: goto x86_l_29e4;
	case 10727ULL: goto x86_l_29e7;
	case 10732ULL: goto x86_l_29ec;
	case 10737ULL: goto x86_l_29f1;
	case 10744ULL: goto x86_l_29f8;
	case 10750ULL: goto x86_l_29fe;
	case 10755ULL: goto x86_l_2a03;
	case 10760ULL: goto x86_l_2a08;
	case 10767ULL: goto x86_l_2a0f;
	case 10775ULL: goto x86_l_2a17;
	case 10780ULL: goto x86_l_2a1c;
	case 10784ULL: goto x86_l_2a20;
	case 10791ULL: goto x86_l_2a27;
	case 10794ULL: goto x86_l_2a2a;
	case 10799ULL: goto x86_l_2a2f;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2352:
	/* 0x2352: js     235c <generic_fentry_process_event+0x235c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_235c;
	}
x86_l_2354:
	/* 0x2354: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2359:
	/* 0x2359: mov    BYTE PTR [rcx+0x3],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_235c:
	/* 0x235c: mov    r15d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 112ULL);
x86_l_2362:
	/* 0x2362: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2367:
	/* 0x2367: mov    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_236c:
	/* 0x236c: jmp    c62 <generic_fentry_process_event+0xc62> */
	return 3170ULL;
x86_l_2371:
	/* 0x2371: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2374:
	/* 0x2374: je     2b56 <generic_fentry_process_event+0x2b56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11094ULL;
	}
x86_l_237a:
	/* 0x237a: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_237d:
	/* 0x237d: jne    2b60 <generic_fentry_process_event+0x2b60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11104ULL;
	}
x86_l_2383:
	/* 0x2383: lea    rax,[rbp+0x5e58] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24152ULL);
x86_l_238a:
	/* 0x238a: jmp    2b5d <generic_fentry_process_event+0x2b5d> */
	return 11101ULL;
x86_l_238f:
	/* 0x238f: lea    rdx,[r15+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2393:
	/* 0x2393: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2398:
	/* 0x2398: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_239d:
	/* 0x239d: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23a2:
	/* 0x23a2: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_23a7:
	/* 0x23a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23a9:
	/* 0x23a9: lea    rdx,[r15+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_23ad:
	/* 0x23ad: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_23b2:
	/* 0x23b2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23b7:
	/* 0x23b7: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_23ba:
	/* 0x23ba: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_23bf:
	/* 0x23bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23c1:
	/* 0x23c1: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23c6:
	/* 0x23c6: lea    rdi,[rbp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_23ca:
	/* 0x23ca: lea    r12,[r15+0xc] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_23ce:
	/* 0x23ce: add    r15,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_23d2:
	/* 0x23d2: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_23d7:
	/* 0x23d7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23dc:
	/* 0x23dc: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_23e1:
	/* 0x23e1: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_23e4:
	/* 0x23e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23e6:
	/* 0x23e6: lea    rdi,[rbp+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_23ea:
	/* 0x23ea: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_23ef:
	/* 0x23ef: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23f4:
	/* 0x23f4: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_23f9:
	/* 0x23f9: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_23fc:
	/* 0x23fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23fe:
	/* 0x23fe: movzx  eax,WORD PTR [rbp+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_2402:
	/* 0x2402: movbe  WORD PTR [rbp+0x22],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_2408:
	/* 0x2408: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_240d:
	/* 0x240d: mov    rax,QWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2411:
	/* 0x2411: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2416:
	/* 0x2416: mov    rdi,QWORD PTR [rip+0x2e6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_241d:
	/* 0x241d: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2422:
	/* 0x2422: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2427:
	/* 0x2427: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2429:
	/* 0x2429: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_242c:
	/* 0x242c: je     2446 <generic_fentry_process_event+0x2446> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2446;
	}
x86_l_242e:
	/* 0x242e: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2430:
	/* 0x2430: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2435:
	/* 0x2435: mov    DWORD PTR [rdx+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2438:
	/* 0x2438: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_243c:
	/* 0x243c: mov    QWORD PTR [rdx+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2440:
	/* 0x2440: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2443:
	/* 0x2443: mov    DWORD PTR [rdx+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_2446:
	/* 0x2446: mov    r15d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 64ULL);
x86_l_244c:
	/* 0x244c: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_244f:
	/* 0x244f: jmp    332f <generic_fentry_process_event+0x332f> */
	return 13103ULL;
x86_l_2454:
	/* 0x2454: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2459:
	/* 0x2459: add    rax,0x5e60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24160ULL);
x86_l_245f:
	/* 0x245f: jmp    2479 <generic_fentry_process_event+0x2479> */
	goto x86_l_2479;
x86_l_2461:
	/* 0x2461: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2466:
	/* 0x2466: add    rax,0x5e68 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24168ULL);
x86_l_246c:
	/* 0x246c: jmp    2479 <generic_fentry_process_event+0x2479> */
	goto x86_l_2479;
x86_l_246e:
	/* 0x246e: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2473:
	/* 0x2473: add    rax,0x5e50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24144ULL);
x86_l_2479:
	/* 0x2479: mov    r13,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_247c:
	/* 0x247c: test   BYTE PTR [rsp+0x40],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 274877906960ULL);
x86_l_2481:
	/* 0x2481: jne    28c6 <generic_fentry_process_event+0x28c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_28c6;
	}
x86_l_2487:
	/* 0x2487: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_248a:
	/* 0x248a: je     2970 <generic_fentry_process_event+0x2970> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2970;
	}
x86_l_2490:
	/* 0x2490: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2495:
	/* 0x2495: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_249b:
	/* 0x249b: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_24a0:
	/* 0x24a0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_24a5:
	/* 0x24a5: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_24aa:
	/* 0x24aa: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_24af:
	/* 0x24af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24b1:
	/* 0x24b1: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_24b6:
	/* 0x24b6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24b8:
	/* 0x24b8: js     28a0 <generic_fentry_process_event+0x28a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_28a0;
	}
x86_l_24be:
	/* 0x24be: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_24c3:
	/* 0x24c3: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_24c8:
	/* 0x24c8: mov    rax,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_24cb:
	/* 0x24cb: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24d0:
	/* 0x24d0: cmp    rdx,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4094ULL);
x86_l_24d7:
	/* 0x24d7: ja     28a0 <generic_fentry_process_event+0x28a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_28a0;
	}
x86_l_24dd:
	/* 0x24dd: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_24e2:
	/* 0x24e2: lea    rdi,[rax+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_24e6:
	/* 0x24e6: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_24e9:
	/* 0x24e9: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_24ef:
	/* 0x24ef: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_24f2:
	/* 0x24f2: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_24f7:
	/* 0x24f7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_24fc:
	/* 0x24fc: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2501:
	/* 0x2501: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2506:
	/* 0x2506: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2508:
	/* 0x2508: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_250d:
	/* 0x250d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_250f:
	/* 0x250f: js     28a0 <generic_fentry_process_event+0x28a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_28a0;
	}
x86_l_2515:
	/* 0x2515: cmp    r13,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 1ULL);
x86_l_2519:
	/* 0x2519: je     2977 <generic_fentry_process_event+0x2977> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2977;
	}
x86_l_251f:
	/* 0x251f: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2524:
	/* 0x2524: lea    rdx,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2528:
	/* 0x2528: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_252d:
	/* 0x252d: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2533:
	/* 0x2533: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2538:
	/* 0x2538: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_253d:
	/* 0x253d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2542:
	/* 0x2542: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2544:
	/* 0x2544: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2549:
	/* 0x2549: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_254b:
	/* 0x254b: js     28a0 <generic_fentry_process_event+0x28a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_28a0;
	}
x86_l_2551:
	/* 0x2551: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2556:
	/* 0x2556: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_255b:
	/* 0x255b: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2560:
	/* 0x2560: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_2566:
	/* 0x2566: ja     28a0 <generic_fentry_process_event+0x28a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_28a0;
	}
x86_l_256c:
	/* 0x256c: add    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2571:
	/* 0x2571: mov    QWORD PTR [rsp+0x40],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2576:
	/* 0x2576: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_2579:
	/* 0x2579: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_257f:
	/* 0x257f: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2582:
	/* 0x2582: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2587:
	/* 0x2587: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_258c:
	/* 0x258c: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2591:
	/* 0x2591: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2596:
	/* 0x2596: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2598:
	/* 0x2598: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_259d:
	/* 0x259d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_259f:
	/* 0x259f: js     28a0 <generic_fentry_process_event+0x28a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_28a0;
	}
x86_l_25a5:
	/* 0x25a5: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_25aa:
	/* 0x25aa: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_25af:
	/* 0x25af: cmp    r13,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 3ULL);
x86_l_25b3:
	/* 0x25b3: jb     2977 <generic_fentry_process_event+0x2977> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2977;
	}
x86_l_25b9:
	/* 0x25b9: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_25be:
	/* 0x25be: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_25c2:
	/* 0x25c2: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_25c7:
	/* 0x25c7: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_25cd:
	/* 0x25cd: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_25d2:
	/* 0x25d2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_25d7:
	/* 0x25d7: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_25dc:
	/* 0x25dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25de:
	/* 0x25de: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_25e3:
	/* 0x25e3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_25e5:
	/* 0x25e5: js     28a0 <generic_fentry_process_event+0x28a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_28a0;
	}
x86_l_25eb:
	/* 0x25eb: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_25f0:
	/* 0x25f0: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_25f5:
	/* 0x25f5: mov    QWORD PTR [rsp+0xe0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_25fd:
	/* 0x25fd: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_2603:
	/* 0x2603: ja     28a0 <generic_fentry_process_event+0x28a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_28a0;
	}
x86_l_2609:
	/* 0x2609: mov    rdi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_260e:
	/* 0x260e: add    rdi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_2613:
	/* 0x2613: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_2616:
	/* 0x2616: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_261c:
	/* 0x261c: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_261f:
	/* 0x261f: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2624:
	/* 0x2624: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2629:
	/* 0x2629: mov    rsi,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_2631:
	/* 0x2631: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2636:
	/* 0x2636: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2638:
	/* 0x2638: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_263d:
	/* 0x263d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_263f:
	/* 0x263f: js     28a0 <generic_fentry_process_event+0x28a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_28a0;
	}
x86_l_2645:
	/* 0x2645: mov    rax,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_264d:
	/* 0x264d: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2652:
	/* 0x2652: cmp    r13,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 3ULL);
x86_l_2656:
	/* 0x2656: je     2977 <generic_fentry_process_event+0x2977> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2977;
	}
x86_l_265c:
	/* 0x265c: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2661:
	/* 0x2661: lea    rdx,[rax+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2665:
	/* 0x2665: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_266a:
	/* 0x266a: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2670:
	/* 0x2670: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2675:
	/* 0x2675: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_267a:
	/* 0x267a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_267f:
	/* 0x267f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2681:
	/* 0x2681: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2686:
	/* 0x2686: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2688:
	/* 0x2688: js     28a0 <generic_fentry_process_event+0x28a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_28a0;
	}
x86_l_268e:
	/* 0x268e: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2693:
	/* 0x2693: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_2698:
	/* 0x2698: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_269d:
	/* 0x269d: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_26a3:
	/* 0x26a3: ja     28a0 <generic_fentry_process_event+0x28a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_28a0;
	}
x86_l_26a9:
	/* 0x26a9: mov    rdi,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_26b1:
	/* 0x26b1: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_26b4:
	/* 0x26b4: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_26b7:
	/* 0x26b7: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_26bd:
	/* 0x26bd: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_26c0:
	/* 0x26c0: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_26c5:
	/* 0x26c5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_26ca:
	/* 0x26ca: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_26cf:
	/* 0x26cf: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_26d4:
	/* 0x26d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26d6:
	/* 0x26d6: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_26db:
	/* 0x26db: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_26dd:
	/* 0x26dd: js     28a0 <generic_fentry_process_event+0x28a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_28a0;
	}
x86_l_26e3:
	/* 0x26e3: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_26e8:
	/* 0x26e8: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_26ed:
	/* 0x26ed: cmp    r13,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 5ULL);
x86_l_26f1:
	/* 0x26f1: jb     2977 <generic_fentry_process_event+0x2977> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2977;
	}
x86_l_26f7:
	/* 0x26f7: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_26fc:
	/* 0x26fc: lea    rdx,[rax+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2700:
	/* 0x2700: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2705:
	/* 0x2705: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_270b:
	/* 0x270b: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2710:
	/* 0x2710: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2715:
	/* 0x2715: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_271a:
	/* 0x271a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_271c:
	/* 0x271c: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2721:
	/* 0x2721: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2723:
	/* 0x2723: js     28a0 <generic_fentry_process_event+0x28a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_28a0;
	}
x86_l_2729:
	/* 0x2729: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_272e:
	/* 0x272e: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_2733:
	/* 0x2733: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2738:
	/* 0x2738: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_273e:
	/* 0x273e: ja     28a0 <generic_fentry_process_event+0x28a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_28a0;
	}
x86_l_2744:
	/* 0x2744: mov    rdi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2749:
	/* 0x2749: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_274c:
	/* 0x274c: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_274f:
	/* 0x274f: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2755:
	/* 0x2755: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2758:
	/* 0x2758: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_275d:
	/* 0x275d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2762:
	/* 0x2762: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2767:
	/* 0x2767: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_276c:
	/* 0x276c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_276e:
	/* 0x276e: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2773:
	/* 0x2773: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2775:
	/* 0x2775: js     28a0 <generic_fentry_process_event+0x28a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_28a0;
	}
x86_l_277b:
	/* 0x277b: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2780:
	/* 0x2780: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2785:
	/* 0x2785: cmp    r13,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 5ULL);
x86_l_2789:
	/* 0x2789: je     2977 <generic_fentry_process_event+0x2977> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2977;
	}
x86_l_278f:
	/* 0x278f: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2794:
	/* 0x2794: lea    rdx,[rax+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2798:
	/* 0x2798: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_279d:
	/* 0x279d: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_27a3:
	/* 0x27a3: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_27a8:
	/* 0x27a8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_27ad:
	/* 0x27ad: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_27b2:
	/* 0x27b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27b4:
	/* 0x27b4: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_27b9:
	/* 0x27b9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_27bb:
	/* 0x27bb: js     28a0 <generic_fentry_process_event+0x28a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_28a0;
	}
x86_l_27c1:
	/* 0x27c1: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_27c6:
	/* 0x27c6: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_27cb:
	/* 0x27cb: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_27d0:
	/* 0x27d0: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_27d6:
	/* 0x27d6: ja     28a0 <generic_fentry_process_event+0x28a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_28a0;
	}
x86_l_27dc:
	/* 0x27dc: mov    rdi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_27e1:
	/* 0x27e1: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_27e4:
	/* 0x27e4: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_27e7:
	/* 0x27e7: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_27ed:
	/* 0x27ed: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_27f0:
	/* 0x27f0: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_27f5:
	/* 0x27f5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_27fa:
	/* 0x27fa: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_27ff:
	/* 0x27ff: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2804:
	/* 0x2804: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2806:
	/* 0x2806: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_280b:
	/* 0x280b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_280d:
	/* 0x280d: js     28a0 <generic_fentry_process_event+0x28a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_28a0;
	}
x86_l_2813:
	/* 0x2813: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2818:
	/* 0x2818: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_281d:
	/* 0x281d: cmp    r13,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 7ULL);
x86_l_2821:
	/* 0x2821: jb     2977 <generic_fentry_process_event+0x2977> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2977;
	}
x86_l_2827:
	/* 0x2827: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_282c:
	/* 0x282c: add    rdx,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_2830:
	/* 0x2830: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2835:
	/* 0x2835: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_283b:
	/* 0x283b: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2840:
	/* 0x2840: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2845:
	/* 0x2845: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_284a:
	/* 0x284a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_284c:
	/* 0x284c: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2851:
	/* 0x2851: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2853:
	/* 0x2853: js     28a0 <generic_fentry_process_event+0x28a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_28a0;
	}
x86_l_2855:
	/* 0x2855: mov    r13,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_285a:
	/* 0x285a: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_285f:
	/* 0x285f: cmp    r13,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4094ULL);
x86_l_2866:
	/* 0x2866: ja     28a0 <generic_fentry_process_event+0x28a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_28a0;
	}
x86_l_2868:
	/* 0x2868: mov    rdi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_286d:
	/* 0x286d: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2870:
	/* 0x2870: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2876:
	/* 0x2876: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2879:
	/* 0x2879: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_287e:
	/* 0x287e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2883:
	/* 0x2883: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2888:
	/* 0x2888: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_288b:
	/* 0x288b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_288d:
	/* 0x288d: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2892:
	/* 0x2892: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2894:
	/* 0x2894: js     28a0 <generic_fentry_process_event+0x28a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_28a0;
	}
x86_l_2896:
	/* 0x2896: add    QWORD PTR [rsp+0x8],r13 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_289b:
	/* 0x289b: jmp    2977 <generic_fentry_process_event+0x2977> */
	goto x86_l_2977;
x86_l_28a0:
	/* 0x28a0: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_28a5:
	/* 0x28a5: mov    DWORD PTR [r12+rax*1],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_28a9:
	/* 0x28a9: jmp    2b26 <generic_fentry_process_event+0x2b26> */
	return 11046ULL;
x86_l_28ae:
	/* 0x28ae: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_28b1:
	/* 0x28b1: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_28b6:
	/* 0x28b6: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28bb:
	/* 0x28bb: test   BYTE PTR [rsp+0x40],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 274877906960ULL);
x86_l_28c0:
	/* 0x28c0: je     2977 <generic_fentry_process_event+0x2977> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2977;
	}
x86_l_28c6:
	/* 0x28c6: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_28cb:
	/* 0x28cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28cd:
	/* 0x28cd: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_28d1:
	/* 0x28d1: jne    28d7 <generic_fentry_process_event+0x28d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_28d7;
	}
x86_l_28d3:
	/* 0x28d3: mov    rax,QWORD PTR [rbx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_28d7:
	/* 0x28d7: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_28dc:
	/* 0x28dc: mov    rcx,QWORD PTR [rdx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28e0:
	/* 0x28e0: mov    rdx,QWORD PTR [rdx+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_28e4:
	/* 0x28e4: mov    QWORD PTR [rsp+0x68],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_28e9:
	/* 0x28e9: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_28ee:
	/* 0x28ee: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_28f3:
	/* 0x28f3: mov    QWORD PTR [rsp+0x78],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_28f8:
	/* 0x28f8: mov    QWORD PTR [rsp+0xa8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2900:
	/* 0x2900: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2908:
	/* 0x2908: mov    rdi,QWORD PTR [rip+0x2e6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_290f:
	/* 0x290f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2911:
	/* 0x2911: lea    rsi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2919:
	/* 0x2919: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_291e:
	/* 0x291e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2923:
	/* 0x2923: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2925:
	/* 0x2925: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2927:
	/* 0x2927: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_292a:
	/* 0x292a: je     2b13 <generic_fentry_process_event+0x2b13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11027ULL;
	}
x86_l_2930:
	/* 0x2930: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_2932:
	/* 0x2932: mov    WORD PTR [rsp+0x58],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2937:
	/* 0x2937: mov    WORD PTR [rsp+0x5a],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 386547056645ULL);
x86_l_293e:
	/* 0x293e: movabs rax,0x200000057 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934679ULL);
x86_l_2948:
	/* 0x2948: mov    QWORD PTR [rsp+0x5c],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_294d:
	/* 0x294d: mov    rdi,QWORD PTR [rip+0x2e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2954:
	/* 0x2954: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2959:
	/* 0x2959: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_295e:
	/* 0x295e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2960:
	/* 0x2960: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2963:
	/* 0x2963: je     2aef <generic_fentry_process_event+0x2aef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10991ULL;
	}
x86_l_2969:
	/* 0x2969: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_296b:
	/* 0x296b: jmp    2b13 <generic_fentry_process_event+0x2b13> */
	return 11027ULL;
x86_l_2970:
	/* 0x2970: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2972:
	/* 0x2972: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2977:
	/* 0x2977: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_297c:
	/* 0x297c: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2981:
	/* 0x2981: mov    DWORD PTR [r12+rax*1],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2985:
	/* 0x2985: mov    DWORD PTR [r12+rax*1+0x4],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 4ULL);
x86_l_298a:
	/* 0x298a: add    r15,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_298e:
	/* 0x298e: jmp    2b26 <generic_fentry_process_event+0x2b26> */
	return 11046ULL;
x86_l_2993:
	/* 0x2993: add    rbp,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_299a:
	/* 0x299a: mov    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29a1:
	/* 0x29a1: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_29a6:
	/* 0x29a6: lea    r14d,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29aa:
	/* 0x29aa: and    r14d,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_29b1:
	/* 0x29b1: add    r14,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_29b4:
	/* 0x29b4: mov    r15d,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 12ULL);
x86_l_29ba:
	/* 0x29ba: cmp    r13,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4095ULL);
x86_l_29c1:
	/* 0x29c1: mov    r12d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4095ULL);
x86_l_29c7:
	/* 0x29c7: cmovb  r12,r13 */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_R13, X86_WIDTH_64, X86_CC_B);
x86_l_29cb:
	/* 0x29cb: lea    rdi,[r14+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29cf:
	/* 0x29cf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_29d4:
	/* 0x29d4: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_29d7:
	/* 0x29d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29d9:
	/* 0x29d9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_29db:
	/* 0x29db: js     29f1 <generic_fentry_process_event+0x29f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_29f1;
	}
x86_l_29dd:
	/* 0x29dd: mov    DWORD PTR [r14],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29e0:
	/* 0x29e0: mov    DWORD PTR [r14+0x4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_29e4:
	/* 0x29e4: add    r15,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_29e7:
	/* 0x29e7: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29ec:
	/* 0x29ec: jmp    332f <generic_fentry_process_event+0x332f> */
	return 13103ULL;
x86_l_29f1:
	/* 0x29f1: mov    DWORD PTR [r14],0xfffffffe */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4294967294ULL);
x86_l_29f8:
	/* 0x29f8: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_29fe:
	/* 0x29fe: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a03:
	/* 0x2a03: jmp    332f <generic_fentry_process_event+0x332f> */
	return 13103ULL;
x86_l_2a08:
	/* 0x2a08: add    rbp,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_2a0f:
	/* 0x2a0f: mov    DWORD PTR [r12],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a17:
	/* 0x2a17: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a1c:
	/* 0x2a1c: lea    r12d,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a20:
	/* 0x2a20: and    r12d,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2a27:
	/* 0x2a27: add    r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2a2a:
	/* 0x2a2a: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2a2f:
	/* 0x2a2f: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
	return 10804ULL;
}

static __noinline __u64 tetragon_bpf_generic_fentry_v61_generic_fentry_process_event_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10804ULL: goto x86_l_2a34;
	case 10811ULL: goto x86_l_2a3b;
	case 10817ULL: goto x86_l_2a41;
	case 10821ULL: goto x86_l_2a45;
	case 10826ULL: goto x86_l_2a4a;
	case 10831ULL: goto x86_l_2a4f;
	case 10837ULL: goto x86_l_2a55;
	case 10840ULL: goto x86_l_2a58;
	case 10842ULL: goto x86_l_2a5a;
	case 10844ULL: goto x86_l_2a5c;
	case 10846ULL: goto x86_l_2a5e;
	case 10850ULL: goto x86_l_2a62;
	case 10855ULL: goto x86_l_2a67;
	case 10860ULL: goto x86_l_2a6c;
	case 10863ULL: goto x86_l_2a6f;
	case 10868ULL: goto x86_l_2a74;
	case 10873ULL: goto x86_l_2a79;
	case 10881ULL: goto x86_l_2a81;
	case 10886ULL: goto x86_l_2a86;
	case 10891ULL: goto x86_l_2a8b;
	case 10894ULL: goto x86_l_2a8e;
	case 10900ULL: goto x86_l_2a94;
	case 10903ULL: goto x86_l_2a97;
	case 10909ULL: goto x86_l_2a9d;
	case 10914ULL: goto x86_l_2aa2;
	case 10920ULL: goto x86_l_2aa8;
	case 10927ULL: goto x86_l_2aaf;
	case 10931ULL: goto x86_l_2ab3;
	case 10936ULL: goto x86_l_2ab8;
	case 10947ULL: goto x86_l_2ac3;
	case 10954ULL: goto x86_l_2aca;
	case 10956ULL: goto x86_l_2acc;
	case 10961ULL: goto x86_l_2ad1;
	case 10969ULL: goto x86_l_2ad9;
	case 10974ULL: goto x86_l_2ade;
	case 10976ULL: goto x86_l_2ae0;
	case 10978ULL: goto x86_l_2ae2;
	case 10986ULL: goto x86_l_2aea;
	case 10991ULL: goto x86_l_2aef;
	case 10999ULL: goto x86_l_2af7;
	case 11006ULL: goto x86_l_2afe;
	case 11008ULL: goto x86_l_2b00;
	case 11013ULL: goto x86_l_2b05;
	case 11018ULL: goto x86_l_2b0a;
	case 11023ULL: goto x86_l_2b0f;
	case 11025ULL: goto x86_l_2b11;
	case 11027ULL: goto x86_l_2b13;
	case 11032ULL: goto x86_l_2b18;
	case 11040ULL: goto x86_l_2b20;
	case 11046ULL: goto x86_l_2b26;
	case 11051ULL: goto x86_l_2b2b;
	case 11054ULL: goto x86_l_2b2e;
	case 11059ULL: goto x86_l_2b33;
	case 11064ULL: goto x86_l_2b38;
	case 11071ULL: goto x86_l_2b3f;
	case 11076ULL: goto x86_l_2b44;
	case 11083ULL: goto x86_l_2b4b;
	case 11085ULL: goto x86_l_2b4d;
	case 11092ULL: goto x86_l_2b54;
	case 11094ULL: goto x86_l_2b56;
	case 11101ULL: goto x86_l_2b5d;
	case 11104ULL: goto x86_l_2b60;
	case 11109ULL: goto x86_l_2b65;
	case 11117ULL: goto x86_l_2b6d;
	case 11122ULL: goto x86_l_2b72;
	case 11127ULL: goto x86_l_2b77;
	case 11132ULL: goto x86_l_2b7c;
	case 11138ULL: goto x86_l_2b82;
	case 11143ULL: goto x86_l_2b87;
	case 11145ULL: goto x86_l_2b89;
	case 11153ULL: goto x86_l_2b91;
	case 11156ULL: goto x86_l_2b94;
	case 11158ULL: goto x86_l_2b96;
	case 11165ULL: goto x86_l_2b9d;
	case 11167ULL: goto x86_l_2b9f;
	case 11175ULL: goto x86_l_2ba7;
	case 11179ULL: goto x86_l_2bab;
	case 11184ULL: goto x86_l_2bb0;
	case 11187ULL: goto x86_l_2bb3;
	case 11190ULL: goto x86_l_2bb6;
	case 11195ULL: goto x86_l_2bbb;
	case 11198ULL: goto x86_l_2bbe;
	case 11203ULL: goto x86_l_2bc3;
	case 11206ULL: goto x86_l_2bc6;
	case 11210ULL: goto x86_l_2bca;
	case 11215ULL: goto x86_l_2bcf;
	case 11220ULL: goto x86_l_2bd4;
	case 11227ULL: goto x86_l_2bdb;
	case 11235ULL: goto x86_l_2be3;
	case 11240ULL: goto x86_l_2be8;
	case 11244ULL: goto x86_l_2bec;
	case 11251ULL: goto x86_l_2bf3;
	case 11254ULL: goto x86_l_2bf6;
	case 11260ULL: goto x86_l_2bfc;
	case 11267ULL: goto x86_l_2c03;
	case 11272ULL: goto x86_l_2c08;
	case 11276ULL: goto x86_l_2c0c;
	case 11281ULL: goto x86_l_2c11;
	case 11286ULL: goto x86_l_2c16;
	case 11291ULL: goto x86_l_2c1b;
	case 11293ULL: goto x86_l_2c1d;
	case 11295ULL: goto x86_l_2c1f;
	case 11297ULL: goto x86_l_2c21;
	case 11299ULL: goto x86_l_2c23;
	case 11303ULL: goto x86_l_2c27;
	case 11308ULL: goto x86_l_2c2c;
	case 11311ULL: goto x86_l_2c2f;
	case 11316ULL: goto x86_l_2c34;
	case 11324ULL: goto x86_l_2c3c;
	case 11330ULL: goto x86_l_2c42;
	case 11335ULL: goto x86_l_2c47;
	case 11340ULL: goto x86_l_2c4c;
	case 11347ULL: goto x86_l_2c53;
	case 11352ULL: goto x86_l_2c58;
	case 11356ULL: goto x86_l_2c5c;
	case 11360ULL: goto x86_l_2c60;
	case 11365ULL: goto x86_l_2c65;
	case 11369ULL: goto x86_l_2c69;
	case 11375ULL: goto x86_l_2c6f;
	case 11385ULL: goto x86_l_2c79;
	case 11389ULL: goto x86_l_2c7d;
	case 11395ULL: goto x86_l_2c83;
	case 11399ULL: goto x86_l_2c87;
	case 11402ULL: goto x86_l_2c8a;
	case 11405ULL: goto x86_l_2c8d;
	case 11410ULL: goto x86_l_2c92;
	case 11415ULL: goto x86_l_2c97;
	case 11420ULL: goto x86_l_2c9c;
	case 11424ULL: goto x86_l_2ca0;
	case 11427ULL: goto x86_l_2ca3;
	case 11432ULL: goto x86_l_2ca8;
	case 11434ULL: goto x86_l_2caa;
	case 11437ULL: goto x86_l_2cad;
	case 11443ULL: goto x86_l_2cb3;
	case 11448ULL: goto x86_l_2cb8;
	case 11451ULL: goto x86_l_2cbb;
	case 11453ULL: goto x86_l_2cbd;
	case 11455ULL: goto x86_l_2cbf;
	case 11457ULL: goto x86_l_2cc1;
	case 11460ULL: goto x86_l_2cc4;
	case 11462ULL: goto x86_l_2cc6;
	case 11465ULL: goto x86_l_2cc9;
	case 11467ULL: goto x86_l_2ccb;
	case 11474ULL: goto x86_l_2cd2;
	case 11478ULL: goto x86_l_2cd6;
	case 11480ULL: goto x86_l_2cd8;
	case 11483ULL: goto x86_l_2cdb;
	case 11485ULL: goto x86_l_2cdd;
	case 11488ULL: goto x86_l_2ce0;
	case 11490ULL: goto x86_l_2ce2;
	case 11495ULL: goto x86_l_2ce7;
	case 11497ULL: goto x86_l_2ce9;
	case 11504ULL: goto x86_l_2cf0;
	case 11508ULL: goto x86_l_2cf4;
	case 11510ULL: goto x86_l_2cf6;
	case 11515ULL: goto x86_l_2cfb;
	case 11522ULL: goto x86_l_2d02;
	case 11527ULL: goto x86_l_2d07;
	case 11529ULL: goto x86_l_2d09;
	case 11534ULL: goto x86_l_2d0e;
	case 11539ULL: goto x86_l_2d13;
	case 11544ULL: goto x86_l_2d18;
	case 11551ULL: goto x86_l_2d1f;
	case 11556ULL: goto x86_l_2d24;
	case 11558ULL: goto x86_l_2d26;
	case 11563ULL: goto x86_l_2d2b;
	case 11567ULL: goto x86_l_2d2f;
	case 11571ULL: goto x86_l_2d33;
	case 11576ULL: goto x86_l_2d38;
	case 11580ULL: goto x86_l_2d3c;
	case 11586ULL: goto x86_l_2d42;
	case 11596ULL: goto x86_l_2d4c;
	case 11600ULL: goto x86_l_2d50;
	case 11606ULL: goto x86_l_2d56;
	case 11610ULL: goto x86_l_2d5a;
	case 11613ULL: goto x86_l_2d5d;
	case 11616ULL: goto x86_l_2d60;
	case 11621ULL: goto x86_l_2d65;
	case 11626ULL: goto x86_l_2d6a;
	case 11631ULL: goto x86_l_2d6f;
	case 11635ULL: goto x86_l_2d73;
	case 11638ULL: goto x86_l_2d76;
	case 11643ULL: goto x86_l_2d7b;
	case 11645ULL: goto x86_l_2d7d;
	case 11648ULL: goto x86_l_2d80;
	case 11654ULL: goto x86_l_2d86;
	case 11659ULL: goto x86_l_2d8b;
	case 11662ULL: goto x86_l_2d8e;
	case 11664ULL: goto x86_l_2d90;
	case 11666ULL: goto x86_l_2d92;
	case 11668ULL: goto x86_l_2d94;
	case 11671ULL: goto x86_l_2d97;
	case 11673ULL: goto x86_l_2d99;
	case 11676ULL: goto x86_l_2d9c;
	case 11678ULL: goto x86_l_2d9e;
	case 11685ULL: goto x86_l_2da5;
	case 11689ULL: goto x86_l_2da9;
	case 11691ULL: goto x86_l_2dab;
	case 11694ULL: goto x86_l_2dae;
	case 11696ULL: goto x86_l_2db0;
	case 11699ULL: goto x86_l_2db3;
	case 11701ULL: goto x86_l_2db5;
	case 11706ULL: goto x86_l_2dba;
	case 11708ULL: goto x86_l_2dbc;
	case 11715ULL: goto x86_l_2dc3;
	case 11719ULL: goto x86_l_2dc7;
	case 11721ULL: goto x86_l_2dc9;
	case 11726ULL: goto x86_l_2dce;
	case 11733ULL: goto x86_l_2dd5;
	case 11738ULL: goto x86_l_2dda;
	case 11740ULL: goto x86_l_2ddc;
	case 11745ULL: goto x86_l_2de1;
	case 11752ULL: goto x86_l_2de8;
	case 11757ULL: goto x86_l_2ded;
	case 11759ULL: goto x86_l_2def;
	case 11764ULL: goto x86_l_2df4;
	case 11768ULL: goto x86_l_2df8;
	case 11772ULL: goto x86_l_2dfc;
	case 11777ULL: goto x86_l_2e01;
	case 11781ULL: goto x86_l_2e05;
	case 11787ULL: goto x86_l_2e0b;
	case 11797ULL: goto x86_l_2e15;
	case 11801ULL: goto x86_l_2e19;
	case 11807ULL: goto x86_l_2e1f;
	case 11811ULL: goto x86_l_2e23;
	case 11814ULL: goto x86_l_2e26;
	case 11817ULL: goto x86_l_2e29;
	case 11822ULL: goto x86_l_2e2e;
	case 11827ULL: goto x86_l_2e33;
	case 11832ULL: goto x86_l_2e38;
	case 11836ULL: goto x86_l_2e3c;
	case 11839ULL: goto x86_l_2e3f;
	case 11844ULL: goto x86_l_2e44;
	case 11846ULL: goto x86_l_2e46;
	case 11849ULL: goto x86_l_2e49;
	case 11855ULL: goto x86_l_2e4f;
	case 11860ULL: goto x86_l_2e54;
	case 11863ULL: goto x86_l_2e57;
	case 11865ULL: goto x86_l_2e59;
	case 11867ULL: goto x86_l_2e5b;
	case 11869ULL: goto x86_l_2e5d;
	case 11872ULL: goto x86_l_2e60;
	case 11874ULL: goto x86_l_2e62;
	case 11877ULL: goto x86_l_2e65;
	case 11879ULL: goto x86_l_2e67;
	case 11886ULL: goto x86_l_2e6e;
	case 11890ULL: goto x86_l_2e72;
	case 11892ULL: goto x86_l_2e74;
	case 11895ULL: goto x86_l_2e77;
	case 11897ULL: goto x86_l_2e79;
	case 11900ULL: goto x86_l_2e7c;
	case 11902ULL: goto x86_l_2e7e;
	case 11907ULL: goto x86_l_2e83;
	case 11909ULL: goto x86_l_2e85;
	case 11916ULL: goto x86_l_2e8c;
	case 11920ULL: goto x86_l_2e90;
	case 11922ULL: goto x86_l_2e92;
	case 11927ULL: goto x86_l_2e97;
	case 11934ULL: goto x86_l_2e9e;
	case 11939ULL: goto x86_l_2ea3;
	case 11941ULL: goto x86_l_2ea5;
	case 11946ULL: goto x86_l_2eaa;
	case 11953ULL: goto x86_l_2eb1;
	case 11958ULL: goto x86_l_2eb6;
	case 11960ULL: goto x86_l_2eb8;
	case 11965ULL: goto x86_l_2ebd;
	case 11969ULL: goto x86_l_2ec1;
	case 11973ULL: goto x86_l_2ec5;
	case 11978ULL: goto x86_l_2eca;
	case 11982ULL: goto x86_l_2ece;
	case 11988ULL: goto x86_l_2ed4;
	case 11998ULL: goto x86_l_2ede;
	case 12002ULL: goto x86_l_2ee2;
	case 12008ULL: goto x86_l_2ee8;
	case 12012ULL: goto x86_l_2eec;
	case 12015ULL: goto x86_l_2eef;
	case 12018ULL: goto x86_l_2ef2;
	case 12023ULL: goto x86_l_2ef7;
	case 12028ULL: goto x86_l_2efc;
	case 12033ULL: goto x86_l_2f01;
	case 12037ULL: goto x86_l_2f05;
	case 12040ULL: goto x86_l_2f08;
	case 12045ULL: goto x86_l_2f0d;
	case 12047ULL: goto x86_l_2f0f;
	case 12050ULL: goto x86_l_2f12;
	case 12056ULL: goto x86_l_2f18;
	case 12061ULL: goto x86_l_2f1d;
	case 12064ULL: goto x86_l_2f20;
	case 12066ULL: goto x86_l_2f22;
	case 12068ULL: goto x86_l_2f24;
	case 12070ULL: goto x86_l_2f26;
	case 12073ULL: goto x86_l_2f29;
	case 12075ULL: goto x86_l_2f2b;
	case 12078ULL: goto x86_l_2f2e;
	case 12080ULL: goto x86_l_2f30;
	case 12087ULL: goto x86_l_2f37;
	case 12091ULL: goto x86_l_2f3b;
	case 12093ULL: goto x86_l_2f3d;
	case 12096ULL: goto x86_l_2f40;
	case 12098ULL: goto x86_l_2f42;
	case 12101ULL: goto x86_l_2f45;
	case 12103ULL: goto x86_l_2f47;
	case 12108ULL: goto x86_l_2f4c;
	case 12110ULL: goto x86_l_2f4e;
	case 12117ULL: goto x86_l_2f55;
	case 12121ULL: goto x86_l_2f59;
	case 12123ULL: goto x86_l_2f5b;
	case 12128ULL: goto x86_l_2f60;
	case 12135ULL: goto x86_l_2f67;
	case 12140ULL: goto x86_l_2f6c;
	case 12142ULL: goto x86_l_2f6e;
	case 12147ULL: goto x86_l_2f73;
	case 12154ULL: goto x86_l_2f7a;
	case 12159ULL: goto x86_l_2f7f;
	case 12161ULL: goto x86_l_2f81;
	case 12166ULL: goto x86_l_2f86;
	case 12170ULL: goto x86_l_2f8a;
	case 12174ULL: goto x86_l_2f8e;
	case 12179ULL: goto x86_l_2f93;
	case 12183ULL: goto x86_l_2f97;
	case 12189ULL: goto x86_l_2f9d;
	case 12199ULL: goto x86_l_2fa7;
	case 12203ULL: goto x86_l_2fab;
	case 12209ULL: goto x86_l_2fb1;
	case 12213ULL: goto x86_l_2fb5;
	case 12216ULL: goto x86_l_2fb8;
	case 12219ULL: goto x86_l_2fbb;
	case 12224ULL: goto x86_l_2fc0;
	case 12229ULL: goto x86_l_2fc5;
	case 12234ULL: goto x86_l_2fca;
	case 12238ULL: goto x86_l_2fce;
	case 12241ULL: goto x86_l_2fd1;
	case 12246ULL: goto x86_l_2fd6;
	case 12248ULL: goto x86_l_2fd8;
	case 12251ULL: goto x86_l_2fdb;
	case 12257ULL: goto x86_l_2fe1;
	case 12262ULL: goto x86_l_2fe6;
	case 12265ULL: goto x86_l_2fe9;
	case 12267ULL: goto x86_l_2feb;
	case 12269ULL: goto x86_l_2fed;
	case 12271ULL: goto x86_l_2fef;
	case 12274ULL: goto x86_l_2ff2;
	case 12276ULL: goto x86_l_2ff4;
	case 12279ULL: goto x86_l_2ff7;
	case 12281ULL: goto x86_l_2ff9;
	case 12288ULL: goto x86_l_3000;
	case 12292ULL: goto x86_l_3004;
	case 12294ULL: goto x86_l_3006;
	case 12297ULL: goto x86_l_3009;
	case 12299ULL: goto x86_l_300b;
	case 12302ULL: goto x86_l_300e;
	case 12304ULL: goto x86_l_3010;
	case 12309ULL: goto x86_l_3015;
	case 12311ULL: goto x86_l_3017;
	case 12318ULL: goto x86_l_301e;
	case 12322ULL: goto x86_l_3022;
	case 12324ULL: goto x86_l_3024;
	case 12329ULL: goto x86_l_3029;
	case 12336ULL: goto x86_l_3030;
	case 12341ULL: goto x86_l_3035;
	case 12343ULL: goto x86_l_3037;
	case 12348ULL: goto x86_l_303c;
	case 12355ULL: goto x86_l_3043;
	case 12360ULL: goto x86_l_3048;
	case 12362ULL: goto x86_l_304a;
	case 12367ULL: goto x86_l_304f;
	case 12371ULL: goto x86_l_3053;
	case 12375ULL: goto x86_l_3057;
	case 12380ULL: goto x86_l_305c;
	case 12384ULL: goto x86_l_3060;
	case 12390ULL: goto x86_l_3066;
	case 12400ULL: goto x86_l_3070;
	case 12404ULL: goto x86_l_3074;
	case 12410ULL: goto x86_l_307a;
	case 12414ULL: goto x86_l_307e;
	case 12417ULL: goto x86_l_3081;
	case 12420ULL: goto x86_l_3084;
	case 12425ULL: goto x86_l_3089;
	case 12430ULL: goto x86_l_308e;
	case 12435ULL: goto x86_l_3093;
	case 12439ULL: goto x86_l_3097;
	case 12442ULL: goto x86_l_309a;
	case 12447ULL: goto x86_l_309f;
	case 12449ULL: goto x86_l_30a1;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2a34:
	/* 0x2a34: cmp    r14,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 4095ULL);
x86_l_2a3b:
	/* 0x2a3b: mov    r13d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4095ULL);
x86_l_2a41:
	/* 0x2a41: cmovb  r13,r14 */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_R14, X86_WIDTH_64, X86_CC_B);
x86_l_2a45:
	/* 0x2a45: lea    rdi,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a4a:
	/* 0x2a4a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a4f:
	/* 0x2a4f: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2a55:
	/* 0x2a55: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_2a58:
	/* 0x2a58: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a5a:
	/* 0x2a5a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a5c:
	/* 0x2a5c: js     2a79 <generic_fentry_process_event+0x2a79> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2a79;
	}
x86_l_2a5e:
	/* 0x2a5e: mov    DWORD PTR [r12],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a62:
	/* 0x2a62: mov    DWORD PTR [r12+0x4],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2a67:
	/* 0x2a67: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a6c:
	/* 0x2a6c: add    r15,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2a6f:
	/* 0x2a6f: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a74:
	/* 0x2a74: jmp    332f <generic_fentry_process_event+0x332f> */
	return 13103ULL;
x86_l_2a79:
	/* 0x2a79: mov    DWORD PTR [r12],0xfffffffe */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4294967294ULL);
x86_l_2a81:
	/* 0x2a81: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a86:
	/* 0x2a86: jmp    332f <generic_fentry_process_event+0x332f> */
	return 13103ULL;
x86_l_2a8b:
	/* 0x2a8b: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2a8e:
	/* 0x2a8e: je     2c47 <generic_fentry_process_event+0x2c47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c47;
	}
x86_l_2a94:
	/* 0x2a94: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2a97:
	/* 0x2a97: je     2b33 <generic_fentry_process_event+0x2b33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b33;
	}
x86_l_2a9d:
	/* 0x2a9d: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2aa2:
	/* 0x2aa2: jne    2d09 <generic_fentry_process_event+0x2d09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2d09;
	}
x86_l_2aa8:
	/* 0x2aa8: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2aaf:
	/* 0x2aaf: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2ab3:
	/* 0x2ab3: jmp    2c58 <generic_fentry_process_event+0x2c58> */
	goto x86_l_2c58;
x86_l_2ab8:
	/* 0x2ab8: mov    DWORD PTR [rsp+0xc0],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 824633720833ULL);
x86_l_2ac3:
	/* 0x2ac3: mov    rdi,QWORD PTR [rip+0x2e6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2aca:
	/* 0x2aca: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2acc:
	/* 0x2acc: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2ad1:
	/* 0x2ad1: lea    rdx,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2ad9:
	/* 0x2ad9: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2ade:
	/* 0x2ade: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ae0:
	/* 0x2ae0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ae2:
	/* 0x2ae2: mov    DWORD PTR [r12],0xfffffffc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4294967292ULL);
x86_l_2aea:
	/* 0x2aea: jmp    2c3c <generic_fentry_process_event+0x2c3c> */
	goto x86_l_2c3c;
x86_l_2aef:
	/* 0x2aef: mov    DWORD PTR [rsp+0x48],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645313ULL);
x86_l_2af7:
	/* 0x2af7: mov    rdi,QWORD PTR [rip+0x2e6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2afe:
	/* 0x2afe: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b00:
	/* 0x2b00: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2b05:
	/* 0x2b05: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2b0a:
	/* 0x2b0a: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2b0f:
	/* 0x2b0f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b11:
	/* 0x2b11: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b13:
	/* 0x2b13: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2b18:
	/* 0x2b18: mov    DWORD PTR [r12+rax*1],0xfffffffc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 4294967292ULL);
x86_l_2b20:
	/* 0x2b20: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2b26:
	/* 0x2b26: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b2b:
	/* 0x2b2b: mov    r12,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_2b2e:
	/* 0x2b2e: jmp    3334 <generic_fentry_process_event+0x3334> */
	return 13108ULL;
x86_l_2b33:
	/* 0x2b33: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2b38:
	/* 0x2b38: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2b3f:
	/* 0x2b3f: jmp    2c53 <generic_fentry_process_event+0x2c53> */
	goto x86_l_2c53;
x86_l_2b44:
	/* 0x2b44: lea    rax,[rbp+0x5e60] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24160ULL);
x86_l_2b4b:
	/* 0x2b4b: jmp    2b5d <generic_fentry_process_event+0x2b5d> */
	goto x86_l_2b5d;
x86_l_2b4d:
	/* 0x2b4d: lea    rax,[rbp+0x5e68] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24168ULL);
x86_l_2b54:
	/* 0x2b54: jmp    2b5d <generic_fentry_process_event+0x2b5d> */
	goto x86_l_2b5d;
x86_l_2b56:
	/* 0x2b56: lea    rax,[rbp+0x5e50] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24144ULL);
x86_l_2b5d:
	/* 0x2b5d: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b60:
	/* 0x2b60: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2b65:
	/* 0x2b65: lea    rdi,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_2b6d:
	/* 0x2b6d: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2b72:
	/* 0x2b72: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2b77:
	/* 0x2b77: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b7c:
	/* 0x2b7c: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_2b82:
	/* 0x2b82: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b87:
	/* 0x2b87: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b89:
	/* 0x2b89: mov    r13,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_2b91:
	/* 0x2b91: test   bl,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBX, X86_WIDTH_8, 32ULL);
x86_l_2b94:
	/* 0x2b94: je     2bfc <generic_fentry_process_event+0x2bfc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bfc;
	}
x86_l_2b96:
	/* 0x2b96: cmp    r13,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4096ULL);
x86_l_2b9d:
	/* 0x2b9d: jb     2bd4 <generic_fentry_process_event+0x2bd4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2bd4;
	}
x86_l_2b9f:
	/* 0x2b9f: mov    DWORD PTR [r12],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2ba7:
	/* 0x2ba7: add    r12,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2bab:
	/* 0x2bab: mov    rbx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2bb0:
	/* 0x2bb0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2bb3:
	/* 0x2bb3: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2bb6:
	/* 0x2bb6: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2bbb:
	/* 0x2bbb: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_2bbe:
	/* 0x2bbe: call   0 <generic_fentry_process_event> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 11203ULL);
	__x86_sim_call_depth++;
	return 13702ULL;
x86_l_2bc3:
	/* 0x2bc3: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2bc6:
	/* 0x2bc6: add    r15,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2bca:
	/* 0x2bca: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2bcf:
	/* 0x2bcf: jmp    332f <generic_fentry_process_event+0x332f> */
	return 13103ULL;
x86_l_2bd4:
	/* 0x2bd4: add    rbp,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_2bdb:
	/* 0x2bdb: mov    DWORD PTR [r12],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2be3:
	/* 0x2be3: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2be8:
	/* 0x2be8: lea    r12d,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2bec:
	/* 0x2bec: and    r12d,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2bf3:
	/* 0x2bf3: add    r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2bf6:
	/* 0x2bf6: mov    r15d,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 12ULL);
x86_l_2bfc:
	/* 0x2bfc: cmp    r13,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4095ULL);
x86_l_2c03:
	/* 0x2c03: mov    ebx,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4095ULL);
x86_l_2c08:
	/* 0x2c08: cmovb  rbx,r13 */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_R13, X86_WIDTH_64, X86_CC_B);
x86_l_2c0c:
	/* 0x2c0c: lea    rdi,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c11:
	/* 0x2c11: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c16:
	/* 0x2c16: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c1b:
	/* 0x2c1b: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_2c1d:
	/* 0x2c1d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c1f:
	/* 0x2c1f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c21:
	/* 0x2c21: js     2c34 <generic_fentry_process_event+0x2c34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2c34;
	}
x86_l_2c23:
	/* 0x2c23: mov    DWORD PTR [r12],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c27:
	/* 0x2c27: mov    DWORD PTR [r12+0x4],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2c2c:
	/* 0x2c2c: add    r15,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2c2f:
	/* 0x2c2f: jmp    3325 <generic_fentry_process_event+0x3325> */
	return 13093ULL;
x86_l_2c34:
	/* 0x2c34: mov    DWORD PTR [r12],0xfffffffe */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4294967294ULL);
x86_l_2c3c:
	/* 0x2c3c: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2c42:
	/* 0x2c42: jmp    3325 <generic_fentry_process_event+0x3325> */
	return 13093ULL;
x86_l_2c47:
	/* 0x2c47: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2c4c:
	/* 0x2c4c: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2c53:
	/* 0x2c53: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2c58:
	/* 0x2c58: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2c5c:
	/* 0x2c5c: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c60:
	/* 0x2c60: movzx  ebp,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2c65:
	/* 0x2c65: cmp    rbp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 60ULL);
x86_l_2c69:
	/* 0x2c69: ja     3347 <generic_fentry_process_event+0x3347> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13127ULL;
	}
x86_l_2c6f:
	/* 0x2c6f: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2c79:
	/* 0x2c79: bt     rcx,rbp */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_2c7d:
	/* 0x2c7d: jae    3347 <generic_fentry_process_event+0x3347> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 13127ULL;
	}
x86_l_2c83:
	/* 0x2c83: mov    BYTE PTR [r15+0x5],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2c87:
	/* 0x2c87: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2c8a:
	/* 0x2c8a: add    rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2c8d:
	/* 0x2c8d: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2c92:
	/* 0x2c92: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c97:
	/* 0x2c97: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c9c:
	/* 0x2c9c: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2ca0:
	/* 0x2ca0: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2ca3:
	/* 0x2ca3: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2ca8:
	/* 0x2ca8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2caa:
	/* 0x2caa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2cad:
	/* 0x2cad: js     316a <generic_fentry_process_event+0x316a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12650ULL;
	}
x86_l_2cb3:
	/* 0x2cb3: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2cb8:
	/* 0x2cb8: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2cbb:
	/* 0x2cbb: jg     2cd8 <generic_fentry_process_event+0x2cd8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2cd8;
	}
x86_l_2cbd:
	/* 0x2cbd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2cbf:
	/* 0x2cbf: je     2cf6 <generic_fentry_process_event+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cf6;
	}
x86_l_2cc1:
	/* 0x2cc1: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2cc4:
	/* 0x2cc4: je     2cf6 <generic_fentry_process_event+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cf6;
	}
x86_l_2cc6:
	/* 0x2cc6: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2cc9:
	/* 0x2cc9: jne    2d26 <generic_fentry_process_event+0x2d26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2d26;
	}
x86_l_2ccb:
	/* 0x2ccb: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2cd2:
	/* 0x2cd2: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2cd6:
	/* 0x2cd6: jmp    2d2b <generic_fentry_process_event+0x2d2b> */
	goto x86_l_2d2b;
x86_l_2cd8:
	/* 0x2cd8: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2cdb:
	/* 0x2cdb: je     2d13 <generic_fentry_process_event+0x2d13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d13;
	}
x86_l_2cdd:
	/* 0x2cdd: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2ce0:
	/* 0x2ce0: je     2cf6 <generic_fentry_process_event+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cf6;
	}
x86_l_2ce2:
	/* 0x2ce2: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2ce7:
	/* 0x2ce7: jne    2d26 <generic_fentry_process_event+0x2d26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2d26;
	}
x86_l_2ce9:
	/* 0x2ce9: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2cf0:
	/* 0x2cf0: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2cf4:
	/* 0x2cf4: jmp    2d2b <generic_fentry_process_event+0x2d2b> */
	goto x86_l_2d2b;
x86_l_2cf6:
	/* 0x2cf6: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2cfb:
	/* 0x2cfb: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2d02:
	/* 0x2d02: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2d07:
	/* 0x2d07: jmp    2d2b <generic_fentry_process_event+0x2d2b> */
	goto x86_l_2d2b;
x86_l_2d09:
	/* 0x2d09: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2d0e:
	/* 0x2d0e: jmp    2c58 <generic_fentry_process_event+0x2c58> */
	goto x86_l_2c58;
x86_l_2d13:
	/* 0x2d13: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2d18:
	/* 0x2d18: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2d1f:
	/* 0x2d1f: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2d24:
	/* 0x2d24: jmp    2d2b <generic_fentry_process_event+0x2d2b> */
	goto x86_l_2d2b;
x86_l_2d26:
	/* 0x2d26: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2d2b:
	/* 0x2d2b: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2d2f:
	/* 0x2d2f: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d33:
	/* 0x2d33: movzx  ebp,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2d38:
	/* 0x2d38: cmp    rbp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 60ULL);
x86_l_2d3c:
	/* 0x2d3c: ja     3347 <generic_fentry_process_event+0x3347> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13127ULL;
	}
x86_l_2d42:
	/* 0x2d42: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2d4c:
	/* 0x2d4c: bt     rcx,rbp */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_2d50:
	/* 0x2d50: jae    3347 <generic_fentry_process_event+0x3347> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 13127ULL;
	}
x86_l_2d56:
	/* 0x2d56: mov    BYTE PTR [r15+0x5],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2d5a:
	/* 0x2d5a: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2d5d:
	/* 0x2d5d: add    rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2d60:
	/* 0x2d60: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2d65:
	/* 0x2d65: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d6a:
	/* 0x2d6a: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d6f:
	/* 0x2d6f: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2d73:
	/* 0x2d73: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2d76:
	/* 0x2d76: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2d7b:
	/* 0x2d7b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d7d:
	/* 0x2d7d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d80:
	/* 0x2d80: js     316a <generic_fentry_process_event+0x316a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12650ULL;
	}
x86_l_2d86:
	/* 0x2d86: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2d8b:
	/* 0x2d8b: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2d8e:
	/* 0x2d8e: jg     2dab <generic_fentry_process_event+0x2dab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2dab;
	}
x86_l_2d90:
	/* 0x2d90: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2d92:
	/* 0x2d92: je     2dc9 <generic_fentry_process_event+0x2dc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2dc9;
	}
x86_l_2d94:
	/* 0x2d94: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2d97:
	/* 0x2d97: je     2dc9 <generic_fentry_process_event+0x2dc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2dc9;
	}
x86_l_2d99:
	/* 0x2d99: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2d9c:
	/* 0x2d9c: jne    2def <generic_fentry_process_event+0x2def> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2def;
	}
x86_l_2d9e:
	/* 0x2d9e: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2da5:
	/* 0x2da5: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2da9:
	/* 0x2da9: jmp    2df4 <generic_fentry_process_event+0x2df4> */
	goto x86_l_2df4;
x86_l_2dab:
	/* 0x2dab: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2dae:
	/* 0x2dae: je     2ddc <generic_fentry_process_event+0x2ddc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ddc;
	}
x86_l_2db0:
	/* 0x2db0: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2db3:
	/* 0x2db3: je     2dc9 <generic_fentry_process_event+0x2dc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2dc9;
	}
x86_l_2db5:
	/* 0x2db5: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2dba:
	/* 0x2dba: jne    2def <generic_fentry_process_event+0x2def> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2def;
	}
x86_l_2dbc:
	/* 0x2dbc: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2dc3:
	/* 0x2dc3: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2dc7:
	/* 0x2dc7: jmp    2df4 <generic_fentry_process_event+0x2df4> */
	goto x86_l_2df4;
x86_l_2dc9:
	/* 0x2dc9: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2dce:
	/* 0x2dce: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2dd5:
	/* 0x2dd5: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2dda:
	/* 0x2dda: jmp    2df4 <generic_fentry_process_event+0x2df4> */
	goto x86_l_2df4;
x86_l_2ddc:
	/* 0x2ddc: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2de1:
	/* 0x2de1: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2de8:
	/* 0x2de8: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2ded:
	/* 0x2ded: jmp    2df4 <generic_fentry_process_event+0x2df4> */
	goto x86_l_2df4;
x86_l_2def:
	/* 0x2def: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2df4:
	/* 0x2df4: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2df8:
	/* 0x2df8: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2dfc:
	/* 0x2dfc: movzx  ebp,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2e01:
	/* 0x2e01: cmp    rbp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 60ULL);
x86_l_2e05:
	/* 0x2e05: ja     3347 <generic_fentry_process_event+0x3347> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13127ULL;
	}
x86_l_2e0b:
	/* 0x2e0b: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2e15:
	/* 0x2e15: bt     rcx,rbp */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_2e19:
	/* 0x2e19: jae    3347 <generic_fentry_process_event+0x3347> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 13127ULL;
	}
x86_l_2e1f:
	/* 0x2e1f: mov    BYTE PTR [r15+0x5],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2e23:
	/* 0x2e23: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2e26:
	/* 0x2e26: add    rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2e29:
	/* 0x2e29: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2e2e:
	/* 0x2e2e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e33:
	/* 0x2e33: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e38:
	/* 0x2e38: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2e3c:
	/* 0x2e3c: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2e3f:
	/* 0x2e3f: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2e44:
	/* 0x2e44: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e46:
	/* 0x2e46: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2e49:
	/* 0x2e49: js     316a <generic_fentry_process_event+0x316a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12650ULL;
	}
x86_l_2e4f:
	/* 0x2e4f: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2e54:
	/* 0x2e54: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2e57:
	/* 0x2e57: jg     2e74 <generic_fentry_process_event+0x2e74> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2e74;
	}
x86_l_2e59:
	/* 0x2e59: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2e5b:
	/* 0x2e5b: je     2e92 <generic_fentry_process_event+0x2e92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e92;
	}
x86_l_2e5d:
	/* 0x2e5d: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2e60:
	/* 0x2e60: je     2e92 <generic_fentry_process_event+0x2e92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e92;
	}
x86_l_2e62:
	/* 0x2e62: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2e65:
	/* 0x2e65: jne    2eb8 <generic_fentry_process_event+0x2eb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2eb8;
	}
x86_l_2e67:
	/* 0x2e67: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2e6e:
	/* 0x2e6e: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2e72:
	/* 0x2e72: jmp    2ebd <generic_fentry_process_event+0x2ebd> */
	goto x86_l_2ebd;
x86_l_2e74:
	/* 0x2e74: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2e77:
	/* 0x2e77: je     2ea5 <generic_fentry_process_event+0x2ea5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ea5;
	}
x86_l_2e79:
	/* 0x2e79: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2e7c:
	/* 0x2e7c: je     2e92 <generic_fentry_process_event+0x2e92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e92;
	}
x86_l_2e7e:
	/* 0x2e7e: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2e83:
	/* 0x2e83: jne    2eb8 <generic_fentry_process_event+0x2eb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2eb8;
	}
x86_l_2e85:
	/* 0x2e85: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2e8c:
	/* 0x2e8c: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2e90:
	/* 0x2e90: jmp    2ebd <generic_fentry_process_event+0x2ebd> */
	goto x86_l_2ebd;
x86_l_2e92:
	/* 0x2e92: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2e97:
	/* 0x2e97: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2e9e:
	/* 0x2e9e: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2ea3:
	/* 0x2ea3: jmp    2ebd <generic_fentry_process_event+0x2ebd> */
	goto x86_l_2ebd;
x86_l_2ea5:
	/* 0x2ea5: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2eaa:
	/* 0x2eaa: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2eb1:
	/* 0x2eb1: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2eb6:
	/* 0x2eb6: jmp    2ebd <generic_fentry_process_event+0x2ebd> */
	goto x86_l_2ebd;
x86_l_2eb8:
	/* 0x2eb8: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2ebd:
	/* 0x2ebd: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2ec1:
	/* 0x2ec1: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ec5:
	/* 0x2ec5: movzx  ebp,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2eca:
	/* 0x2eca: cmp    rbp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 60ULL);
x86_l_2ece:
	/* 0x2ece: ja     3347 <generic_fentry_process_event+0x3347> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13127ULL;
	}
x86_l_2ed4:
	/* 0x2ed4: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2ede:
	/* 0x2ede: bt     rcx,rbp */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_2ee2:
	/* 0x2ee2: jae    3347 <generic_fentry_process_event+0x3347> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 13127ULL;
	}
x86_l_2ee8:
	/* 0x2ee8: mov    BYTE PTR [r15+0x5],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2eec:
	/* 0x2eec: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2eef:
	/* 0x2eef: add    rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2ef2:
	/* 0x2ef2: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2ef7:
	/* 0x2ef7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2efc:
	/* 0x2efc: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f01:
	/* 0x2f01: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2f05:
	/* 0x2f05: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2f08:
	/* 0x2f08: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2f0d:
	/* 0x2f0d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f0f:
	/* 0x2f0f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2f12:
	/* 0x2f12: js     316a <generic_fentry_process_event+0x316a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12650ULL;
	}
x86_l_2f18:
	/* 0x2f18: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2f1d:
	/* 0x2f1d: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2f20:
	/* 0x2f20: jg     2f3d <generic_fentry_process_event+0x2f3d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2f3d;
	}
x86_l_2f22:
	/* 0x2f22: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2f24:
	/* 0x2f24: je     2f5b <generic_fentry_process_event+0x2f5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f5b;
	}
x86_l_2f26:
	/* 0x2f26: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2f29:
	/* 0x2f29: je     2f5b <generic_fentry_process_event+0x2f5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f5b;
	}
x86_l_2f2b:
	/* 0x2f2b: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2f2e:
	/* 0x2f2e: jne    2f81 <generic_fentry_process_event+0x2f81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2f81;
	}
x86_l_2f30:
	/* 0x2f30: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2f37:
	/* 0x2f37: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2f3b:
	/* 0x2f3b: jmp    2f86 <generic_fentry_process_event+0x2f86> */
	goto x86_l_2f86;
x86_l_2f3d:
	/* 0x2f3d: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2f40:
	/* 0x2f40: je     2f6e <generic_fentry_process_event+0x2f6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f6e;
	}
x86_l_2f42:
	/* 0x2f42: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2f45:
	/* 0x2f45: je     2f5b <generic_fentry_process_event+0x2f5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f5b;
	}
x86_l_2f47:
	/* 0x2f47: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2f4c:
	/* 0x2f4c: jne    2f81 <generic_fentry_process_event+0x2f81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2f81;
	}
x86_l_2f4e:
	/* 0x2f4e: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2f55:
	/* 0x2f55: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2f59:
	/* 0x2f59: jmp    2f86 <generic_fentry_process_event+0x2f86> */
	goto x86_l_2f86;
x86_l_2f5b:
	/* 0x2f5b: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2f60:
	/* 0x2f60: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2f67:
	/* 0x2f67: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2f6c:
	/* 0x2f6c: jmp    2f86 <generic_fentry_process_event+0x2f86> */
	goto x86_l_2f86;
x86_l_2f6e:
	/* 0x2f6e: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2f73:
	/* 0x2f73: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2f7a:
	/* 0x2f7a: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2f7f:
	/* 0x2f7f: jmp    2f86 <generic_fentry_process_event+0x2f86> */
	goto x86_l_2f86;
x86_l_2f81:
	/* 0x2f81: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2f86:
	/* 0x2f86: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2f8a:
	/* 0x2f8a: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f8e:
	/* 0x2f8e: movzx  ebp,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2f93:
	/* 0x2f93: cmp    rbp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 60ULL);
x86_l_2f97:
	/* 0x2f97: ja     3347 <generic_fentry_process_event+0x3347> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13127ULL;
	}
x86_l_2f9d:
	/* 0x2f9d: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2fa7:
	/* 0x2fa7: bt     rcx,rbp */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_2fab:
	/* 0x2fab: jae    3347 <generic_fentry_process_event+0x3347> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 13127ULL;
	}
x86_l_2fb1:
	/* 0x2fb1: mov    BYTE PTR [r15+0x5],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2fb5:
	/* 0x2fb5: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2fb8:
	/* 0x2fb8: add    rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2fbb:
	/* 0x2fbb: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2fc0:
	/* 0x2fc0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2fc5:
	/* 0x2fc5: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2fca:
	/* 0x2fca: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2fce:
	/* 0x2fce: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2fd1:
	/* 0x2fd1: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2fd6:
	/* 0x2fd6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fd8:
	/* 0x2fd8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2fdb:
	/* 0x2fdb: js     316a <generic_fentry_process_event+0x316a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12650ULL;
	}
x86_l_2fe1:
	/* 0x2fe1: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2fe6:
	/* 0x2fe6: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2fe9:
	/* 0x2fe9: jg     3006 <generic_fentry_process_event+0x3006> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3006;
	}
x86_l_2feb:
	/* 0x2feb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2fed:
	/* 0x2fed: je     3024 <generic_fentry_process_event+0x3024> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3024;
	}
x86_l_2fef:
	/* 0x2fef: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2ff2:
	/* 0x2ff2: je     3024 <generic_fentry_process_event+0x3024> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3024;
	}
x86_l_2ff4:
	/* 0x2ff4: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2ff7:
	/* 0x2ff7: jne    304a <generic_fentry_process_event+0x304a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_304a;
	}
x86_l_2ff9:
	/* 0x2ff9: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_3000:
	/* 0x3000: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_3004:
	/* 0x3004: jmp    304f <generic_fentry_process_event+0x304f> */
	goto x86_l_304f;
x86_l_3006:
	/* 0x3006: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_3009:
	/* 0x3009: je     3037 <generic_fentry_process_event+0x3037> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3037;
	}
x86_l_300b:
	/* 0x300b: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_300e:
	/* 0x300e: je     3024 <generic_fentry_process_event+0x3024> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3024;
	}
x86_l_3010:
	/* 0x3010: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_3015:
	/* 0x3015: jne    304a <generic_fentry_process_event+0x304a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_304a;
	}
x86_l_3017:
	/* 0x3017: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_301e:
	/* 0x301e: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_3022:
	/* 0x3022: jmp    304f <generic_fentry_process_event+0x304f> */
	goto x86_l_304f;
x86_l_3024:
	/* 0x3024: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_3029:
	/* 0x3029: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_3030:
	/* 0x3030: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_3035:
	/* 0x3035: jmp    304f <generic_fentry_process_event+0x304f> */
	goto x86_l_304f;
x86_l_3037:
	/* 0x3037: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_303c:
	/* 0x303c: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_3043:
	/* 0x3043: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_3048:
	/* 0x3048: jmp    304f <generic_fentry_process_event+0x304f> */
	goto x86_l_304f;
x86_l_304a:
	/* 0x304a: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_304f:
	/* 0x304f: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3053:
	/* 0x3053: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3057:
	/* 0x3057: movzx  ebp,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_305c:
	/* 0x305c: cmp    rbp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 60ULL);
x86_l_3060:
	/* 0x3060: ja     3347 <generic_fentry_process_event+0x3347> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13127ULL;
	}
x86_l_3066:
	/* 0x3066: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_3070:
	/* 0x3070: bt     rcx,rbp */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_3074:
	/* 0x3074: jae    3347 <generic_fentry_process_event+0x3347> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 13127ULL;
	}
x86_l_307a:
	/* 0x307a: mov    BYTE PTR [r15+0x5],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_307e:
	/* 0x307e: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_3081:
	/* 0x3081: add    rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3084:
	/* 0x3084: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3089:
	/* 0x3089: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_308e:
	/* 0x308e: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3093:
	/* 0x3093: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3097:
	/* 0x3097: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_309a:
	/* 0x309a: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_309f:
	/* 0x309f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30a1:
	/* 0x30a1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
	return 12452ULL;
}

static __noinline __u64 tetragon_bpf_generic_fentry_v61_generic_fentry_process_event_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12452ULL: goto x86_l_30a4;
	case 12458ULL: goto x86_l_30aa;
	case 12463ULL: goto x86_l_30af;
	case 12466ULL: goto x86_l_30b2;
	case 12468ULL: goto x86_l_30b4;
	case 12470ULL: goto x86_l_30b6;
	case 12472ULL: goto x86_l_30b8;
	case 12475ULL: goto x86_l_30bb;
	case 12477ULL: goto x86_l_30bd;
	case 12480ULL: goto x86_l_30c0;
	case 12482ULL: goto x86_l_30c2;
	case 12489ULL: goto x86_l_30c9;
	case 12493ULL: goto x86_l_30cd;
	case 12495ULL: goto x86_l_30cf;
	case 12498ULL: goto x86_l_30d2;
	case 12500ULL: goto x86_l_30d4;
	case 12503ULL: goto x86_l_30d7;
	case 12505ULL: goto x86_l_30d9;
	case 12510ULL: goto x86_l_30de;
	case 12512ULL: goto x86_l_30e0;
	case 12519ULL: goto x86_l_30e7;
	case 12523ULL: goto x86_l_30eb;
	case 12525ULL: goto x86_l_30ed;
	case 12530ULL: goto x86_l_30f2;
	case 12537ULL: goto x86_l_30f9;
	case 12542ULL: goto x86_l_30fe;
	case 12544ULL: goto x86_l_3100;
	case 12549ULL: goto x86_l_3105;
	case 12556ULL: goto x86_l_310c;
	case 12561ULL: goto x86_l_3111;
	case 12563ULL: goto x86_l_3113;
	case 12568ULL: goto x86_l_3118;
	case 12572ULL: goto x86_l_311c;
	case 12576ULL: goto x86_l_3120;
	case 12581ULL: goto x86_l_3125;
	case 12585ULL: goto x86_l_3129;
	case 12591ULL: goto x86_l_312f;
	case 12601ULL: goto x86_l_3139;
	case 12605ULL: goto x86_l_313d;
	case 12611ULL: goto x86_l_3143;
	case 12615ULL: goto x86_l_3147;
	case 12618ULL: goto x86_l_314a;
	case 12621ULL: goto x86_l_314d;
	case 12626ULL: goto x86_l_3152;
	case 12631ULL: goto x86_l_3157;
	case 12636ULL: goto x86_l_315c;
	case 12640ULL: goto x86_l_3160;
	case 12643ULL: goto x86_l_3163;
	case 12648ULL: goto x86_l_3168;
	case 12650ULL: goto x86_l_316a;
	case 12652ULL: goto x86_l_316c;
	case 12660ULL: goto x86_l_3174;
	case 12664ULL: goto x86_l_3178;
	case 12669ULL: goto x86_l_317d;
	case 12673ULL: goto x86_l_3181;
	case 12679ULL: goto x86_l_3187;
	case 12683ULL: goto x86_l_318b;
	case 12688ULL: goto x86_l_3190;
	case 12693ULL: goto x86_l_3195;
	case 12696ULL: goto x86_l_3198;
	case 12701ULL: goto x86_l_319d;
	case 12703ULL: goto x86_l_319f;
	case 12707ULL: goto x86_l_31a3;
	case 12711ULL: goto x86_l_31a7;
	case 12716ULL: goto x86_l_31ac;
	case 12721ULL: goto x86_l_31b1;
	case 12726ULL: goto x86_l_31b6;
	case 12729ULL: goto x86_l_31b9;
	case 12731ULL: goto x86_l_31bb;
	case 12735ULL: goto x86_l_31bf;
	case 12737ULL: goto x86_l_31c1;
	case 12741ULL: goto x86_l_31c5;
	case 12744ULL: goto x86_l_31c8;
	case 12750ULL: goto x86_l_31ce;
	case 12755ULL: goto x86_l_31d3;
	case 12764ULL: goto x86_l_31dc;
	case 12768ULL: goto x86_l_31e0;
	case 12773ULL: goto x86_l_31e5;
	case 12777ULL: goto x86_l_31e9;
	case 12782ULL: goto x86_l_31ee;
	case 12787ULL: goto x86_l_31f3;
	case 12792ULL: goto x86_l_31f8;
	case 12794ULL: goto x86_l_31fa;
	case 12798ULL: goto x86_l_31fe;
	case 12802ULL: goto x86_l_3202;
	case 12806ULL: goto x86_l_3206;
	case 12811ULL: goto x86_l_320b;
	case 12816ULL: goto x86_l_3210;
	case 12818ULL: goto x86_l_3212;
	case 12823ULL: goto x86_l_3217;
	case 12832ULL: goto x86_l_3220;
	case 12836ULL: goto x86_l_3224;
	case 12841ULL: goto x86_l_3229;
	case 12845ULL: goto x86_l_322d;
	case 12850ULL: goto x86_l_3232;
	case 12855ULL: goto x86_l_3237;
	case 12860ULL: goto x86_l_323c;
	case 12862ULL: goto x86_l_323e;
	case 12866ULL: goto x86_l_3242;
	case 12870ULL: goto x86_l_3246;
	case 12874ULL: goto x86_l_324a;
	case 12879ULL: goto x86_l_324f;
	case 12884ULL: goto x86_l_3254;
	case 12889ULL: goto x86_l_3259;
	case 12891ULL: goto x86_l_325b;
	case 12893ULL: goto x86_l_325d;
	case 12898ULL: goto x86_l_3262;
	case 12905ULL: goto x86_l_3269;
	case 12910ULL: goto x86_l_326e;
	case 12914ULL: goto x86_l_3272;
	case 12918ULL: goto x86_l_3276;
	case 12924ULL: goto x86_l_327c;
	case 12930ULL: goto x86_l_3282;
	case 12937ULL: goto x86_l_3289;
	case 12945ULL: goto x86_l_3291;
	case 12950ULL: goto x86_l_3296;
	case 12955ULL: goto x86_l_329b;
	case 12961ULL: goto x86_l_32a1;
	case 12966ULL: goto x86_l_32a6;
	case 12969ULL: goto x86_l_32a9;
	case 12971ULL: goto x86_l_32ab;
	case 12979ULL: goto x86_l_32b3;
	case 12982ULL: goto x86_l_32b6;
	case 12984ULL: goto x86_l_32b8;
	case 12988ULL: goto x86_l_32bc;
	case 12993ULL: goto x86_l_32c1;
	case 12998ULL: goto x86_l_32c6;
	case 13003ULL: goto x86_l_32cb;
	case 13011ULL: goto x86_l_32d3;
	case 13015ULL: goto x86_l_32d7;
	case 13020ULL: goto x86_l_32dc;
	case 13022ULL: goto x86_l_32de;
	case 13030ULL: goto x86_l_32e6;
	case 13035ULL: goto x86_l_32eb;
	case 13039ULL: goto x86_l_32ef;
	case 13044ULL: goto x86_l_32f4;
	case 13048ULL: goto x86_l_32f8;
	case 13053ULL: goto x86_l_32fd;
	case 13058ULL: goto x86_l_3302;
	case 13060ULL: goto x86_l_3304;
	case 13064ULL: goto x86_l_3308;
	case 13068ULL: goto x86_l_330c;
	case 13072ULL: goto x86_l_3310;
	case 13077ULL: goto x86_l_3315;
	case 13080ULL: goto x86_l_3318;
	case 13085ULL: goto x86_l_331d;
	case 13087ULL: goto x86_l_331f;
	case 13093ULL: goto x86_l_3325;
	case 13098ULL: goto x86_l_332a;
	case 13103ULL: goto x86_l_332f;
	case 13108ULL: goto x86_l_3334;
	case 13113ULL: goto x86_l_3339;
	case 13117ULL: goto x86_l_333d;
	case 13122ULL: goto x86_l_3342;
	case 13127ULL: goto x86_l_3347;
	case 13135ULL: goto x86_l_334f;
	case 13140ULL: goto x86_l_3354;
	case 13145ULL: goto x86_l_3359;
	case 13148ULL: goto x86_l_335c;
	case 13150ULL: goto x86_l_335e;
	case 13152ULL: goto x86_l_3360;
	case 13153ULL: goto x86_l_3361;
	case 13154ULL: goto x86_l_3362;
	case 13157ULL: goto x86_l_3365;
	case 13160ULL: goto x86_l_3368;
	case 13167ULL: goto x86_l_336f;
	case 13169ULL: goto x86_l_3371;
	case 13173ULL: goto x86_l_3375;
	case 13177ULL: goto x86_l_3379;
	case 13180ULL: goto x86_l_337c;
	case 13183ULL: goto x86_l_337f;
	case 13185ULL: goto x86_l_3381;
	case 13192ULL: goto x86_l_3388;
	case 13194ULL: goto x86_l_338a;
	case 13196ULL: goto x86_l_338c;
	case 13200ULL: goto x86_l_3390;
	case 13202ULL: goto x86_l_3392;
	case 13207ULL: goto x86_l_3397;
	case 13212ULL: goto x86_l_339c;
	case 13214ULL: goto x86_l_339e;
	case 13219ULL: goto x86_l_33a3;
	case 13224ULL: goto x86_l_33a8;
	case 13227ULL: goto x86_l_33ab;
	case 13231ULL: goto x86_l_33af;
	case 13234ULL: goto x86_l_33b2;
	case 13239ULL: goto x86_l_33b7;
	case 13241ULL: goto x86_l_33b9;
	case 13243ULL: goto x86_l_33bb;
	case 13248ULL: goto x86_l_33c0;
	case 13250ULL: goto x86_l_33c2;
	case 13252ULL: goto x86_l_33c4;
	case 13256ULL: goto x86_l_33c8;
	case 13258ULL: goto x86_l_33ca;
	case 13263ULL: goto x86_l_33cf;
	case 13267ULL: goto x86_l_33d3;
	case 13268ULL: goto x86_l_33d4;
	case 13270ULL: goto x86_l_33d6;
	case 13271ULL: goto x86_l_33d7;
	case 13272ULL: goto x86_l_33d8;
	case 13274ULL: goto x86_l_33da;
	case 13276ULL: goto x86_l_33dc;
	case 13278ULL: goto x86_l_33de;
	case 13280ULL: goto x86_l_33e0;
	case 13281ULL: goto x86_l_33e1;
	case 13285ULL: goto x86_l_33e5;
	case 13288ULL: goto x86_l_33e8;
	case 13292ULL: goto x86_l_33ec;
	case 13296ULL: goto x86_l_33f0;
	case 13300ULL: goto x86_l_33f4;
	case 13303ULL: goto x86_l_33f7;
	case 13305ULL: goto x86_l_33f9;
	case 13309ULL: goto x86_l_33fd;
	case 13315ULL: goto x86_l_3403;
	case 13319ULL: goto x86_l_3407;
	case 13324ULL: goto x86_l_340c;
	case 13329ULL: goto x86_l_3411;
	case 13334ULL: goto x86_l_3416;
	case 13339ULL: goto x86_l_341b;
	case 13341ULL: goto x86_l_341d;
	case 13346ULL: goto x86_l_3422;
	case 13352ULL: goto x86_l_3428;
	case 13357ULL: goto x86_l_342d;
	case 13362ULL: goto x86_l_3432;
	case 13367ULL: goto x86_l_3437;
	case 13372ULL: goto x86_l_343c;
	case 13377ULL: goto x86_l_3441;
	case 13380ULL: goto x86_l_3444;
	case 13382ULL: goto x86_l_3446;
	case 13387ULL: goto x86_l_344b;
	case 13393ULL: goto x86_l_3451;
	case 13398ULL: goto x86_l_3456;
	case 13403ULL: goto x86_l_345b;
	case 13408ULL: goto x86_l_3460;
	case 13413ULL: goto x86_l_3465;
	case 13416ULL: goto x86_l_3468;
	case 13418ULL: goto x86_l_346a;
	case 13422ULL: goto x86_l_346e;
	case 13427ULL: goto x86_l_3473;
	case 13432ULL: goto x86_l_3478;
	case 13437ULL: goto x86_l_347d;
	case 13442ULL: goto x86_l_3482;
	case 13445ULL: goto x86_l_3485;
	case 13447ULL: goto x86_l_3487;
	case 13451ULL: goto x86_l_348b;
	case 13455ULL: goto x86_l_348f;
	case 13459ULL: goto x86_l_3493;
	case 13462ULL: goto x86_l_3496;
	case 13466ULL: goto x86_l_349a;
	case 13468ULL: goto x86_l_349c;
	case 13470ULL: goto x86_l_349e;
	case 13473ULL: goto x86_l_34a1;
	case 13476ULL: goto x86_l_34a4;
	case 13481ULL: goto x86_l_34a9;
	case 13483ULL: goto x86_l_34ab;
	case 13486ULL: goto x86_l_34ae;
	case 13490ULL: goto x86_l_34b2;
	case 13492ULL: goto x86_l_34b4;
	case 13496ULL: goto x86_l_34b8;
	case 13498ULL: goto x86_l_34ba;
	case 13501ULL: goto x86_l_34bd;
	case 13503ULL: goto x86_l_34bf;
	case 13506ULL: goto x86_l_34c2;
	case 13511ULL: goto x86_l_34c7;
	case 13514ULL: goto x86_l_34ca;
	case 13520ULL: goto x86_l_34d0;
	case 13527ULL: goto x86_l_34d7;
	case 13533ULL: goto x86_l_34dd;
	case 13536ULL: goto x86_l_34e0;
	case 13538ULL: goto x86_l_34e2;
	case 13543ULL: goto x86_l_34e7;
	case 13545ULL: goto x86_l_34e9;
	case 13548ULL: goto x86_l_34ec;
	case 13552ULL: goto x86_l_34f0;
	case 13556ULL: goto x86_l_34f4;
	case 13559ULL: goto x86_l_34f7;
	case 13562ULL: goto x86_l_34fa;
	case 13567ULL: goto x86_l_34ff;
	case 13569ULL: goto x86_l_3501;
	case 13573ULL: goto x86_l_3505;
	case 13576ULL: goto x86_l_3508;
	case 13581ULL: goto x86_l_350d;
	case 13583ULL: goto x86_l_350f;
	case 13588ULL: goto x86_l_3514;
	case 13591ULL: goto x86_l_3517;
	case 13593ULL: goto x86_l_3519;
	case 13597ULL: goto x86_l_351d;
	case 13602ULL: goto x86_l_3522;
	case 13607ULL: goto x86_l_3527;
	case 13612ULL: goto x86_l_352c;
	case 13617ULL: goto x86_l_3531;
	case 13619ULL: goto x86_l_3533;
	case 13623ULL: goto x86_l_3537;
	case 13628ULL: goto x86_l_353c;
	case 13630ULL: goto x86_l_353e;
	case 13634ULL: goto x86_l_3542;
	case 13639ULL: goto x86_l_3547;
	case 13644ULL: goto x86_l_354c;
	case 13647ULL: goto x86_l_354f;
	case 13652ULL: goto x86_l_3554;
	case 13655ULL: goto x86_l_3557;
	case 13657ULL: goto x86_l_3559;
	case 13662ULL: goto x86_l_355e;
	case 13666ULL: goto x86_l_3562;
	case 13670ULL: goto x86_l_3566;
	case 13674ULL: goto x86_l_356a;
	case 13676ULL: goto x86_l_356c;
	case 13678ULL: goto x86_l_356e;
	case 13682ULL: goto x86_l_3572;
	case 13687ULL: goto x86_l_3577;
	case 13691ULL: goto x86_l_357b;
	case 13692ULL: goto x86_l_357c;
	case 13694ULL: goto x86_l_357e;
	case 13696ULL: goto x86_l_3580;
	case 13698ULL: goto x86_l_3582;
	case 13700ULL: goto x86_l_3584;
	case 13701ULL: goto x86_l_3585;
	case 13702ULL: goto x86_l_3586;
	case 13703ULL: goto x86_l_3587;
	case 13705ULL: goto x86_l_3589;
	case 13707ULL: goto x86_l_358b;
	case 13709ULL: goto x86_l_358d;
	case 13711ULL: goto x86_l_358f;
	case 13712ULL: goto x86_l_3590;
	case 13713ULL: goto x86_l_3591;
	case 13716ULL: goto x86_l_3594;
	case 13719ULL: goto x86_l_3597;
	case 13722ULL: goto x86_l_359a;
	case 13725ULL: goto x86_l_359d;
	case 13733ULL: goto x86_l_35a5;
	case 13740ULL: goto x86_l_35ac;
	case 13745ULL: goto x86_l_35b1;
	case 13750ULL: goto x86_l_35b6;
	case 13752ULL: goto x86_l_35b8;
	case 13755ULL: goto x86_l_35bb;
	case 13757ULL: goto x86_l_35bd;
	case 13760ULL: goto x86_l_35c0;
	case 13766ULL: goto x86_l_35c6;
	case 13771ULL: goto x86_l_35cb;
	case 13773ULL: goto x86_l_35cd;
	case 13776ULL: goto x86_l_35d0;
	case 13780ULL: goto x86_l_35d4;
	case 13784ULL: goto x86_l_35d8;
	case 13788ULL: goto x86_l_35dc;
	case 13790ULL: goto x86_l_35de;
	case 13795ULL: goto x86_l_35e3;
	case 13799ULL: goto x86_l_35e7;
	case 13804ULL: goto x86_l_35ec;
	case 13806ULL: goto x86_l_35ee;
	case 13810ULL: goto x86_l_35f2;
	case 13814ULL: goto x86_l_35f6;
	case 13818ULL: goto x86_l_35fa;
	case 13822ULL: goto x86_l_35fe;
	case 13826ULL: goto x86_l_3602;
	case 13829ULL: goto x86_l_3605;
	case 13832ULL: goto x86_l_3608;
	case 13835ULL: goto x86_l_360b;
	case 13838ULL: goto x86_l_360e;
	case 13843ULL: goto x86_l_3613;
	case 13845ULL: goto x86_l_3615;
	case 13847ULL: goto x86_l_3617;
	case 13854ULL: goto x86_l_361e;
	case 13857ULL: goto x86_l_3621;
	case 13859ULL: goto x86_l_3623;
	case 13861ULL: goto x86_l_3625;
	case 13865ULL: goto x86_l_3629;
	case 13868ULL: goto x86_l_362c;
	case 13870ULL: goto x86_l_362e;
	case 13872ULL: goto x86_l_3630;
	case 13874ULL: goto x86_l_3632;
	case 13876ULL: goto x86_l_3634;
	case 13883ULL: goto x86_l_363b;
	case 13885ULL: goto x86_l_363d;
	case 13887ULL: goto x86_l_363f;
	case 13890ULL: goto x86_l_3642;
	case 13893ULL: goto x86_l_3645;
	case 13898ULL: goto x86_l_364a;
	case 13902ULL: goto x86_l_364e;
	case 13903ULL: goto x86_l_364f;
	case 13905ULL: goto x86_l_3651;
	case 13907ULL: goto x86_l_3653;
	case 13909ULL: goto x86_l_3655;
	case 13911ULL: goto x86_l_3657;
	case 13912ULL: goto x86_l_3658;
	case 13913ULL: goto x86_l_3659;
	default: return 0xffffffffffffffffULL;
	}
x86_l_30a4:
	/* 0x30a4: js     316a <generic_fentry_process_event+0x316a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_316a;
	}
x86_l_30aa:
	/* 0x30aa: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_30af:
	/* 0x30af: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_30b2:
	/* 0x30b2: jg     30cf <generic_fentry_process_event+0x30cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_30cf;
	}
x86_l_30b4:
	/* 0x30b4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_30b6:
	/* 0x30b6: je     30ed <generic_fentry_process_event+0x30ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30ed;
	}
x86_l_30b8:
	/* 0x30b8: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_30bb:
	/* 0x30bb: je     30ed <generic_fentry_process_event+0x30ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30ed;
	}
x86_l_30bd:
	/* 0x30bd: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_30c0:
	/* 0x30c0: jne    3113 <generic_fentry_process_event+0x3113> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3113;
	}
x86_l_30c2:
	/* 0x30c2: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_30c9:
	/* 0x30c9: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_30cd:
	/* 0x30cd: jmp    3118 <generic_fentry_process_event+0x3118> */
	goto x86_l_3118;
x86_l_30cf:
	/* 0x30cf: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_30d2:
	/* 0x30d2: je     3100 <generic_fentry_process_event+0x3100> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3100;
	}
x86_l_30d4:
	/* 0x30d4: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_30d7:
	/* 0x30d7: je     30ed <generic_fentry_process_event+0x30ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30ed;
	}
x86_l_30d9:
	/* 0x30d9: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_30de:
	/* 0x30de: jne    3113 <generic_fentry_process_event+0x3113> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3113;
	}
x86_l_30e0:
	/* 0x30e0: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_30e7:
	/* 0x30e7: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_30eb:
	/* 0x30eb: jmp    3118 <generic_fentry_process_event+0x3118> */
	goto x86_l_3118;
x86_l_30ed:
	/* 0x30ed: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_30f2:
	/* 0x30f2: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_30f9:
	/* 0x30f9: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_30fe:
	/* 0x30fe: jmp    3118 <generic_fentry_process_event+0x3118> */
	goto x86_l_3118;
x86_l_3100:
	/* 0x3100: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_3105:
	/* 0x3105: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_310c:
	/* 0x310c: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_3111:
	/* 0x3111: jmp    3118 <generic_fentry_process_event+0x3118> */
	goto x86_l_3118;
x86_l_3113:
	/* 0x3113: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_3118:
	/* 0x3118: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_311c:
	/* 0x311c: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3120:
	/* 0x3120: movzx  ebp,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_3125:
	/* 0x3125: cmp    rbp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 60ULL);
x86_l_3129:
	/* 0x3129: ja     3347 <generic_fentry_process_event+0x3347> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3347;
	}
x86_l_312f:
	/* 0x312f: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_3139:
	/* 0x3139: bt     rcx,rbp */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_313d:
	/* 0x313d: jae    3347 <generic_fentry_process_event+0x3347> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_3347;
	}
x86_l_3143:
	/* 0x3143: mov    BYTE PTR [r15+0x5],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_3147:
	/* 0x3147: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_314a:
	/* 0x314a: add    rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_314d:
	/* 0x314d: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3152:
	/* 0x3152: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3157:
	/* 0x3157: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_315c:
	/* 0x315c: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3160:
	/* 0x3160: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3163:
	/* 0x3163: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_3168:
	/* 0x3168: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_316a:
	/* 0x316a: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_316c:
	/* 0x316c: mov    BYTE PTR [rsp+0xbc],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_3174:
	/* 0x3174: movzx  eax,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3178:
	/* 0x3178: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_317d:
	/* 0x317d: mov    WORD PTR [rbx+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_3181:
	/* 0x3181: mov    WORD PTR [rbx+0x26],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757258ULL);
x86_l_3187:
	/* 0x3187: lea    rdx,[r13+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_318b:
	/* 0x318b: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3190:
	/* 0x3190: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3195:
	/* 0x3195: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3198:
	/* 0x3198: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_319d:
	/* 0x319d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_319f:
	/* 0x319f: lea    rdi,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31a3:
	/* 0x31a3: add    r13,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_31a7:
	/* 0x31a7: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_31ac:
	/* 0x31ac: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_31b1:
	/* 0x31b1: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_31b6:
	/* 0x31b6: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_31b9:
	/* 0x31b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31bb:
	/* 0x31bb: cmp    bpl,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 17ULL);
x86_l_31bf:
	/* 0x31bf: je     3212 <generic_fentry_process_event+0x3212> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3212;
	}
x86_l_31c1:
	/* 0x31c1: movzx  eax,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_31c5:
	/* 0x31c5: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_31c8:
	/* 0x31c8: jne    325d <generic_fentry_process_event+0x325d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_325d;
	}
x86_l_31ce:
	/* 0x31ce: mov    rbx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_31d3:
	/* 0x31d3: movzx  r15d,WORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 200ULL);
x86_l_31dc:
	/* 0x31dc: lea    rdx,[rbx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_31e0:
	/* 0x31e0: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31e5:
	/* 0x31e5: lea    rdi,[r13+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_31e9:
	/* 0x31e9: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_31ee:
	/* 0x31ee: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_31f3:
	/* 0x31f3: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_31f8:
	/* 0x31f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31fa:
	/* 0x31fa: lea    rdi,[r13+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_31fe:
	/* 0x31fe: lea    rdx,[rbx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_3202:
	/* 0x3202: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_3206:
	/* 0x3206: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_320b:
	/* 0x320b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3210:
	/* 0x3210: jmp    3254 <generic_fentry_process_event+0x3254> */
	goto x86_l_3254;
x86_l_3212:
	/* 0x3212: mov    rbx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3217:
	/* 0x3217: movzx  r15d,WORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 200ULL);
x86_l_3220:
	/* 0x3220: lea    rdx,[rbx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_3224:
	/* 0x3224: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3229:
	/* 0x3229: lea    rdi,[r13+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_322d:
	/* 0x322d: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_3232:
	/* 0x3232: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3237:
	/* 0x3237: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_323c:
	/* 0x323c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_323e:
	/* 0x323e: lea    rdi,[r13+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_3242:
	/* 0x3242: lea    rdx,[rbx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_3246:
	/* 0x3246: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_324a:
	/* 0x324a: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_324f:
	/* 0x324f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3254:
	/* 0x3254: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_3259:
	/* 0x3259: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_325b:
	/* 0x325b: jmp    3269 <generic_fentry_process_event+0x3269> */
	goto x86_l_3269;
x86_l_325d:
	/* 0x325d: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3262:
	/* 0x3262: mov    DWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_3269:
	/* 0x3269: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_326e:
	/* 0x326e: movzx  eax,WORD PTR [rdx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_3272:
	/* 0x3272: movzx  ecx,WORD PTR [rdx+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_3276:
	/* 0x3276: movbe  WORD PTR [rdx+0x20],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RDX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_327c:
	/* 0x327c: movbe  WORD PTR [rdx+0x22],cx */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RDX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_3282:
	/* 0x3282: add    r12,0xe0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 224ULL);
x86_l_3289:
	/* 0x3289: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_3291:
	/* 0x3291: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3296:
	/* 0x3296: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_329b:
	/* 0x329b: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_32a1:
	/* 0x32a1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32a6:
	/* 0x32a6: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_32a9:
	/* 0x32a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32ab:
	/* 0x32ab: mov    rcx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_32b3:
	/* 0x32b3: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_32b6:
	/* 0x32b6: je     331f <generic_fentry_process_event+0x331f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_331f;
	}
x86_l_32b8:
	/* 0x32b8: add    rcx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 5ULL);
x86_l_32bc:
	/* 0x32bc: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_32c1:
	/* 0x32c1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_32c6:
	/* 0x32c6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_32cb:
	/* 0x32cb: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_32d3:
	/* 0x32d3: add    rdx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 5ULL);
x86_l_32d7:
	/* 0x32d7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32dc:
	/* 0x32dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32de:
	/* 0x32de: mov    rbx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_32e6:
	/* 0x32e6: mov    r12,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_32eb:
	/* 0x32eb: lea    rdx,[rbx+r12*8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 3), 0ULL);
x86_l_32ef:
	/* 0x32ef: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32f4:
	/* 0x32f4: lea    rdi,[r13+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_32f8:
	/* 0x32f8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_32fd:
	/* 0x32fd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3302:
	/* 0x3302: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3304:
	/* 0x3304: add    r13,0x3c */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 60ULL);
x86_l_3308:
	/* 0x3308: lea    rdx,[rbx+r12*8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 3), 0ULL);
x86_l_330c:
	/* 0x330c: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_3310:
	/* 0x3310: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3315:
	/* 0x3315: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_3318:
	/* 0x3318: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_331d:
	/* 0x331d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_331f:
	/* 0x331f: mov    r15d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 64ULL);
x86_l_3325:
	/* 0x3325: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_332a:
	/* 0x332a: mov    rbx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_332f:
	/* 0x332f: mov    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3334:
	/* 0x3334: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3339:
	/* 0x3339: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_333d:
	/* 0x333d: mov    r14,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3342:
	/* 0x3342: jmp    c66 <generic_fentry_process_event+0xc66> */
	return 3174ULL;
x86_l_3347:
	/* 0x3347: mov    WORD PTR [rsp+0xc8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_334f:
	/* 0x334f: jmp    316c <generic_fentry_process_event+0x316c> */
	goto x86_l_316c;
x86_l_3354:
	/* 0x3354: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3359:
	/* 0x3359: cmp    edi,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 9ULL);
x86_l_335c:
	/* 0x335c: ja     33d6 <extract_arg_depth+0x82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_33d6;
	}
x86_l_335e:
	/* 0x335e: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_3360:
	/* 0x3360: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_3361:
	/* 0x3361: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_3362:
	/* 0x3362: mov    r8,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3365:
	/* 0x3365: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_3368:
	/* 0x3368: cmp    WORD PTR [r8+r9*8+0x6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R9, 3), 25769803776ULL);
x86_l_336f:
	/* 0x336f: je     33cf <extract_arg_depth+0x7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33cf;
	}
x86_l_3371:
	/* 0x3371: mov    rcx,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3375:
	/* 0x3375: mov    edx,DWORD PTR [r8+r9*8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 3), 0ULL);
x86_l_3379:
	/* 0x3379: add    rdx,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_337c:
	/* 0x337c: mov    QWORD PTR [rcx],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_337f:
	/* 0x337f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3381:
	/* 0x3381: cmp    WORD PTR [r8+r9*8+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R9, 3), 17179869184ULL);
x86_l_3388:
	/* 0x3388: je     33cf <extract_arg_depth+0x7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33cf;
	}
x86_l_338a:
	/* 0x338a: mov    ebx,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_32);
x86_l_338c:
	/* 0x338c: cmp    BYTE PTR [rsi+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3390:
	/* 0x3390: je     339e <extract_arg_depth+0x4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_339e;
	}
x86_l_3392:
	/* 0x3392: mov    edi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 8ULL);
x86_l_3397:
	/* 0x3397: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_339c:
	/* 0x339c: jmp    33a8 <extract_arg_depth+0x54> */
	goto x86_l_33a8;
x86_l_339e:
	/* 0x339e: mov    edi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 8ULL);
x86_l_33a3:
	/* 0x33a3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_33a8:
	/* 0x33a8: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_33ab:
	/* 0x33ab: mov    rdi,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_33af:
	/* 0x33af: mov    rdx,QWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33b2:
	/* 0x33b2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33b7:
	/* 0x33b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33b9:
	/* 0x33b9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_33bb:
	/* 0x33bb: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_33c0:
	/* 0x33c0: jns    33cf <extract_arg_depth+0x7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_33cf;
	}
x86_l_33c2:
	/* 0x33c2: inc    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_33c4:
	/* 0x33c4: mov    rax,QWORD PTR [r14+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_33c8:
	/* 0x33c8: mov    DWORD PTR [rax],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33ca:
	/* 0x33ca: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_33cf:
	/* 0x33cf: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_33d3:
	/* 0x33d3: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_33d4:
	/* 0x33d4: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_33d6:
	/* 0x33d6: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_33d7:
	/* 0x33d7: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_33d8:
	/* 0x33d8: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_33da:
	/* 0x33da: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_33dc:
	/* 0x33dc: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_33de:
	/* 0x33de: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_33e0:
	/* 0x33e0: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_33e1:
	/* 0x33e1: sub    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 40ULL);
x86_l_33e5:
	/* 0x33e5: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_33e8:
	/* 0x33e8: mov    r12,QWORD PTR [rsi+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_33ec:
	/* 0x33ec: mov    rdx,QWORD PTR [rsi+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_33f0:
	/* 0x33f0: mov    r15,QWORD PTR [rsi+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_33f4:
	/* 0x33f4: cmp    r12,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_33f7:
	/* 0x33f7: jne    3403 <cwd_read_v61+0x2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3403;
	}
x86_l_33f9:
	/* 0x33f9: cmp    rdx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_33fd:
	/* 0x33fd: je     356e <cwd_read_v61+0x197> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_356e;
	}
x86_l_3403:
	/* 0x3403: lea    r14,[rbx+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3407:
	/* 0x3407: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_340c:
	/* 0x340c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3411:
	/* 0x3411: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3416:
	/* 0x3416: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_341b:
	/* 0x341b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_341d:
	/* 0x341d: cmp    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_3422:
	/* 0x3422: je     3519 <cwd_read_v61+0x142> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3519;
	}
x86_l_3428:
	/* 0x3428: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_342d:
	/* 0x342d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3432:
	/* 0x3432: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3437:
	/* 0x3437: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_343c:
	/* 0x343c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3441:
	/* 0x3441: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3444:
	/* 0x3444: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3446:
	/* 0x3446: cmp    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_344b:
	/* 0x344b: je     3519 <cwd_read_v61+0x142> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3519;
	}
x86_l_3451:
	/* 0x3451: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3456:
	/* 0x3456: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_345b:
	/* 0x345b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3460:
	/* 0x3460: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3465:
	/* 0x3465: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3468:
	/* 0x3468: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_346a:
	/* 0x346a: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_346e:
	/* 0x346e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3473:
	/* 0x3473: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3478:
	/* 0x3478: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_347d:
	/* 0x347d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3482:
	/* 0x3482: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3485:
	/* 0x3485: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3487:
	/* 0x3487: mov    r15,QWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_348b:
	/* 0x348b: mov    rcx,QWORD PTR [rbx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_348f:
	/* 0x348f: mov    ebp,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3493:
	/* 0x3493: sub    rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3496:
	/* 0x3496: mov    r12d,DWORD PTR [rbx+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_349a:
	/* 0x349a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_349c:
	/* 0x349c: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_349e:
	/* 0x349e: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_34a1:
	/* 0x34a1: cmovb  edx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_34a4:
	/* 0x34a4: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_34a9:
	/* 0x34a9: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_34ab:
	/* 0x34ab: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_34ae:
	/* 0x34ae: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_34b2:
	/* 0x34b2: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_34b4:
	/* 0x34b4: cmovb  esi,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_34b8:
	/* 0x34b8: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_34ba:
	/* 0x34ba: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_34bd:
	/* 0x34bd: sub    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_34bf:
	/* 0x34bf: mov    DWORD PTR [rbx+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_34c2:
	/* 0x34c2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_34c7:
	/* 0x34c7: sub    rcx,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_34ca:
	/* 0x34ca: jb     3577 <cwd_read_v61+0x1a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3577;
	}
x86_l_34d0:
	/* 0x34d0: cmp    rcx,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 4095ULL);
x86_l_34d7:
	/* 0x34d7: ja     3577 <cwd_read_v61+0x1a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3577;
	}
x86_l_34dd:
	/* 0x34dd: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_34e0:
	/* 0x34e0: jbe    34e7 <cwd_read_v61+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_34e7;
	}
x86_l_34e2:
	/* 0x34e2: mov    BYTE PTR [r15+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_34e7:
	/* 0x34e7: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_34e9:
	/* 0x34e9: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_34ec:
	/* 0x34ec: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_34f0:
	/* 0x34f0: movzx  esi,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_34f4:
	/* 0x34f4: add    r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_34f7:
	/* 0x34f7: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_34fa:
	/* 0x34fa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_34ff:
	/* 0x34ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3501:
	/* 0x3501: mov    QWORD PTR [rbx+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3505:
	/* 0x3505: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_3508:
	/* 0x3508: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_350d:
	/* 0x350d: jbe    3577 <cwd_read_v61+0x1a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3577;
	}
x86_l_350f:
	/* 0x350f: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3514:
	/* 0x3514: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3517:
	/* 0x3517: jmp    356a <cwd_read_v61+0x193> */
	goto x86_l_356a;
x86_l_3519:
	/* 0x3519: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_351d:
	/* 0x351d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3522:
	/* 0x3522: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3527:
	/* 0x3527: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_352c:
	/* 0x352c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3531:
	/* 0x3531: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3533:
	/* 0x3533: mov    rax,QWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3537:
	/* 0x3537: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_353c:
	/* 0x353c: je     356e <cwd_read_v61+0x197> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_356e;
	}
x86_l_353e:
	/* 0x353e: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_3542:
	/* 0x3542: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3547:
	/* 0x3547: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_354c:
	/* 0x354c: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_354f:
	/* 0x354f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3554:
	/* 0x3554: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3557:
	/* 0x3557: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3559:
	/* 0x3559: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_355e:
	/* 0x355e: mov    QWORD PTR [rbx+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3562:
	/* 0x3562: add    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_3566:
	/* 0x3566: mov    QWORD PTR [rbx+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_356a:
	/* 0x356a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_356c:
	/* 0x356c: jmp    3577 <cwd_read_v61+0x1a0> */
	goto x86_l_3577;
x86_l_356e:
	/* 0x356e: mov    BYTE PTR [rbx+0x3c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 257698037761ULL);
x86_l_3572:
	/* 0x3572: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3577:
	/* 0x3577: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_357b:
	/* 0x357b: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_357c:
	/* 0x357c: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_357e:
	/* 0x357e: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_3580:
	/* 0x3580: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_3582:
	/* 0x3582: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_3584:
	/* 0x3584: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_3585:
	/* 0x3585: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_3586:
	/* 0x3586: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_3587:
	/* 0x3587: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_3589:
	/* 0x3589: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_358b:
	/* 0x358b: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_358d:
	/* 0x358d: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_358f:
	/* 0x358f: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_3590:
	/* 0x3590: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_3591:
	/* 0x3591: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_3594:
	/* 0x3594: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_3597:
	/* 0x3597: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_359a:
	/* 0x359a: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_359d:
	/* 0x359d: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_35a5:
	/* 0x35a5: mov    rdi,QWORD PTR [rip+0x240] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_heap)));
x86_l_35ac:
	/* 0x35ac: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_35b1:
	/* 0x35b1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_35b6:
	/* 0x35b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35b8:
	/* 0x35b8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_35bb:
	/* 0x35bb: je     362e <data_event_bytes+0xa8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_362e;
	}
x86_l_35bd:
	/* 0x35bd: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_35c0:
	/* 0x35c0: mov    DWORD PTR [rax],0x18 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_35c6:
	/* 0x35c6: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_35cb:
	/* 0x35cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35cd:
	/* 0x35cd: mov    rbp,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_64);
x86_l_35d0:
	/* 0x35d0: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_35d4:
	/* 0x35d4: mov    QWORD PTR [r13+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35d8:
	/* 0x35d8: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_35dc:
	/* 0x35dc: jne    35e7 <data_event_bytes+0x61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_35e7;
	}
x86_l_35de:
	/* 0x35de: mov    rax,QWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_35e3:
	/* 0x35e3: mov    QWORD PTR [rbp+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35e7:
	/* 0x35e7: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_35ec:
	/* 0x35ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35ee:
	/* 0x35ee: mov    QWORD PTR [r13+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_35f2:
	/* 0x35f2: mov    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35f6:
	/* 0x35f6: mov    rcx,QWORD PTR [rbp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_35fa:
	/* 0x35fa: mov    QWORD PTR [rbx+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35fe:
	/* 0x35fe: mov    QWORD PTR [rbx+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3602:
	/* 0x3602: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3605:
	/* 0x3605: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_3608:
	/* 0x3608: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_360b:
	/* 0x360b: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_360e:
	/* 0x360e: call   3659 <do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 13843ULL);
	__x86_sim_call_depth++;
	goto x86_l_3659;
x86_l_3613:
	/* 0x3613: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3615:
	/* 0x3615: js     3632 <data_event_bytes+0xac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3632;
	}
x86_l_3617:
	/* 0x3617: mov    QWORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_361e:
	/* 0x361e: mov    edx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_32);
x86_l_3621:
	/* 0x3621: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3623:
	/* 0x3623: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3625:
	/* 0x3625: cmp    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_3629:
	/* 0x3629: cmovne ecx,edx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_32, X86_CC_NE);
x86_l_362c:
	/* 0x362c: jmp    363f <data_event_bytes+0xb9> */
	goto x86_l_363f;
x86_l_362e:
	/* 0x362e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3630:
	/* 0x3630: jmp    364a <data_event_bytes+0xc4> */
	goto x86_l_364a;
x86_l_3632:
	/* 0x3632: mov    DWORD PTR [rbx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3634:
	/* 0x3634: mov    DWORD PTR [rbx+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_363b:
	/* 0x363b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_363d:
	/* 0x363d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_363f:
	/* 0x363f: mov    DWORD PTR [rbx+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3642:
	/* 0x3642: mov    DWORD PTR [rbx+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3645:
	/* 0x3645: mov    eax,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_364a:
	/* 0x364a: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_364e:
	/* 0x364e: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_364f:
	/* 0x364f: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_3651:
	/* 0x3651: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_3653:
	/* 0x3653: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_3655:
	/* 0x3655: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_3657:
	/* 0x3657: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_3658:
	/* 0x3658: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_3659:
	/* 0x3659: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
	return 13914ULL;
}

static __noinline __u64 tetragon_bpf_generic_fentry_v61_generic_fentry_process_event_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 13914ULL: goto x86_l_365a;
	case 13916ULL: goto x86_l_365c;
	case 13918ULL: goto x86_l_365e;
	case 13920ULL: goto x86_l_3660;
	case 13922ULL: goto x86_l_3662;
	case 13923ULL: goto x86_l_3663;
	case 13924ULL: goto x86_l_3664;
	case 13927ULL: goto x86_l_3667;
	case 13930ULL: goto x86_l_366a;
	case 13933ULL: goto x86_l_366d;
	case 13936ULL: goto x86_l_3670;
	case 13941ULL: goto x86_l_3675;
	case 13943ULL: goto x86_l_3677;
	case 13949ULL: goto x86_l_367d;
	case 13952ULL: goto x86_l_3680;
	case 13959ULL: goto x86_l_3687;
	case 13962ULL: goto x86_l_368a;
	case 13965ULL: goto x86_l_368d;
	case 13971ULL: goto x86_l_3693;
	case 13975ULL: goto x86_l_3697;
	case 13978ULL: goto x86_l_369a;
	case 13981ULL: goto x86_l_369d;
	case 13986ULL: goto x86_l_36a2;
	case 13988ULL: goto x86_l_36a4;
	case 13994ULL: goto x86_l_36aa;
	case 13999ULL: goto x86_l_36af;
	case 14002ULL: goto x86_l_36b2;
	case 14005ULL: goto x86_l_36b5;
	case 14008ULL: goto x86_l_36b8;
	case 14011ULL: goto x86_l_36bb;
	case 14017ULL: goto x86_l_36c1;
	case 14021ULL: goto x86_l_36c5;
	case 14024ULL: goto x86_l_36c8;
	case 14027ULL: goto x86_l_36cb;
	case 14032ULL: goto x86_l_36d0;
	case 14034ULL: goto x86_l_36d2;
	case 14040ULL: goto x86_l_36d8;
	case 14045ULL: goto x86_l_36dd;
	case 14048ULL: goto x86_l_36e0;
	case 14051ULL: goto x86_l_36e3;
	case 14054ULL: goto x86_l_36e6;
	case 14057ULL: goto x86_l_36e9;
	case 14063ULL: goto x86_l_36ef;
	case 14067ULL: goto x86_l_36f3;
	case 14070ULL: goto x86_l_36f6;
	case 14073ULL: goto x86_l_36f9;
	case 14078ULL: goto x86_l_36fe;
	case 14080ULL: goto x86_l_3700;
	case 14086ULL: goto x86_l_3706;
	case 14091ULL: goto x86_l_370b;
	case 14094ULL: goto x86_l_370e;
	case 14097ULL: goto x86_l_3711;
	case 14100ULL: goto x86_l_3714;
	case 14103ULL: goto x86_l_3717;
	case 14109ULL: goto x86_l_371d;
	case 14113ULL: goto x86_l_3721;
	case 14116ULL: goto x86_l_3724;
	case 14119ULL: goto x86_l_3727;
	case 14124ULL: goto x86_l_372c;
	case 14126ULL: goto x86_l_372e;
	case 14132ULL: goto x86_l_3734;
	case 14137ULL: goto x86_l_3739;
	case 14140ULL: goto x86_l_373c;
	case 14143ULL: goto x86_l_373f;
	case 14146ULL: goto x86_l_3742;
	case 14149ULL: goto x86_l_3745;
	case 14155ULL: goto x86_l_374b;
	case 14159ULL: goto x86_l_374f;
	case 14162ULL: goto x86_l_3752;
	case 14165ULL: goto x86_l_3755;
	case 14170ULL: goto x86_l_375a;
	case 14172ULL: goto x86_l_375c;
	case 14178ULL: goto x86_l_3762;
	case 14183ULL: goto x86_l_3767;
	case 14186ULL: goto x86_l_376a;
	case 14189ULL: goto x86_l_376d;
	case 14192ULL: goto x86_l_3770;
	case 14195ULL: goto x86_l_3773;
	case 14201ULL: goto x86_l_3779;
	case 14205ULL: goto x86_l_377d;
	case 14208ULL: goto x86_l_3780;
	case 14211ULL: goto x86_l_3783;
	case 14216ULL: goto x86_l_3788;
	case 14218ULL: goto x86_l_378a;
	case 14224ULL: goto x86_l_3790;
	case 14229ULL: goto x86_l_3795;
	case 14232ULL: goto x86_l_3798;
	case 14235ULL: goto x86_l_379b;
	case 14238ULL: goto x86_l_379e;
	case 14241ULL: goto x86_l_37a1;
	case 14247ULL: goto x86_l_37a7;
	case 14251ULL: goto x86_l_37ab;
	case 14254ULL: goto x86_l_37ae;
	case 14257ULL: goto x86_l_37b1;
	case 14262ULL: goto x86_l_37b6;
	case 14264ULL: goto x86_l_37b8;
	case 14266ULL: goto x86_l_37ba;
	case 14271ULL: goto x86_l_37bf;
	case 14274ULL: goto x86_l_37c2;
	case 14277ULL: goto x86_l_37c5;
	case 14280ULL: goto x86_l_37c8;
	case 14283ULL: goto x86_l_37cb;
	case 14289ULL: goto x86_l_37d1;
	case 14293ULL: goto x86_l_37d5;
	case 14296ULL: goto x86_l_37d8;
	case 14299ULL: goto x86_l_37db;
	case 14304ULL: goto x86_l_37e0;
	case 14306ULL: goto x86_l_37e2;
	case 14308ULL: goto x86_l_37e4;
	case 14313ULL: goto x86_l_37e9;
	case 14316ULL: goto x86_l_37ec;
	case 14319ULL: goto x86_l_37ef;
	case 14322ULL: goto x86_l_37f2;
	case 14325ULL: goto x86_l_37f5;
	case 14331ULL: goto x86_l_37fb;
	case 14334ULL: goto x86_l_37fe;
	case 14337ULL: goto x86_l_3801;
	case 14340ULL: goto x86_l_3804;
	case 14343ULL: goto x86_l_3807;
	case 14348ULL: goto x86_l_380c;
	case 14350ULL: goto x86_l_380e;
	case 14352ULL: goto x86_l_3810;
	case 14357ULL: goto x86_l_3815;
	case 14360ULL: goto x86_l_3818;
	case 14363ULL: goto x86_l_381b;
	case 14368ULL: goto x86_l_3820;
	case 14371ULL: goto x86_l_3823;
	case 14379ULL: goto x86_l_382b;
	case 14386ULL: goto x86_l_3832;
	case 14391ULL: goto x86_l_3837;
	case 14396ULL: goto x86_l_383c;
	case 14398ULL: goto x86_l_383e;
	case 14401ULL: goto x86_l_3841;
	case 14403ULL: goto x86_l_3843;
	case 14407ULL: goto x86_l_3847;
	case 14409ULL: goto x86_l_3849;
	case 14413ULL: goto x86_l_384d;
	case 14415ULL: goto x86_l_384f;
	case 14419ULL: goto x86_l_3853;
	case 14421ULL: goto x86_l_3855;
	case 14425ULL: goto x86_l_3859;
	case 14427ULL: goto x86_l_385b;
	case 14433ULL: goto x86_l_3861;
	case 14435ULL: goto x86_l_3863;
	case 14439ULL: goto x86_l_3867;
	case 14441ULL: goto x86_l_3869;
	case 14445ULL: goto x86_l_386d;
	case 14447ULL: goto x86_l_386f;
	case 14451ULL: goto x86_l_3873;
	case 14453ULL: goto x86_l_3875;
	case 14459ULL: goto x86_l_387b;
	case 14461ULL: goto x86_l_387d;
	case 14467ULL: goto x86_l_3883;
	case 14469ULL: goto x86_l_3885;
	case 14475ULL: goto x86_l_388b;
	case 14477ULL: goto x86_l_388d;
	case 14483ULL: goto x86_l_3893;
	case 14485ULL: goto x86_l_3895;
	case 14491ULL: goto x86_l_389b;
	case 14493ULL: goto x86_l_389d;
	case 14499ULL: goto x86_l_38a3;
	case 14503ULL: goto x86_l_38a7;
	case 14506ULL: goto x86_l_38aa;
	case 14510ULL: goto x86_l_38ae;
	case 14511ULL: goto x86_l_38af;
	case 14513ULL: goto x86_l_38b1;
	case 14515ULL: goto x86_l_38b3;
	case 14517ULL: goto x86_l_38b5;
	case 14519ULL: goto x86_l_38b7;
	case 14520ULL: goto x86_l_38b8;
	case 14521ULL: goto x86_l_38b9;
	case 14523ULL: goto x86_l_38bb;
	case 14525ULL: goto x86_l_38bd;
	case 14527ULL: goto x86_l_38bf;
	case 14528ULL: goto x86_l_38c0;
	case 14529ULL: goto x86_l_38c1;
	case 14532ULL: goto x86_l_38c4;
	case 14538ULL: goto x86_l_38ca;
	case 14541ULL: goto x86_l_38cd;
	case 14544ULL: goto x86_l_38d0;
	case 14551ULL: goto x86_l_38d7;
	case 14556ULL: goto x86_l_38dc;
	case 14560ULL: goto x86_l_38e0;
	case 14564ULL: goto x86_l_38e4;
	case 14569ULL: goto x86_l_38e9;
	case 14571ULL: goto x86_l_38eb;
	case 14573ULL: goto x86_l_38ed;
	case 14575ULL: goto x86_l_38ef;
	case 14577ULL: goto x86_l_38f1;
	case 14581ULL: goto x86_l_38f5;
	case 14585ULL: goto x86_l_38f9;
	case 14593ULL: goto x86_l_3901;
	case 14600ULL: goto x86_l_3908;
	case 14605ULL: goto x86_l_390d;
	case 14610ULL: goto x86_l_3912;
	case 14612ULL: goto x86_l_3914;
	case 14615ULL: goto x86_l_3917;
	case 14617ULL: goto x86_l_3919;
	case 14621ULL: goto x86_l_391d;
	case 14623ULL: goto x86_l_391f;
	case 14630ULL: goto x86_l_3926;
	case 14635ULL: goto x86_l_392b;
	case 14640ULL: goto x86_l_3930;
	case 14643ULL: goto x86_l_3933;
	case 14648ULL: goto x86_l_3938;
	case 14651ULL: goto x86_l_393b;
	case 14654ULL: goto x86_l_393e;
	case 14656ULL: goto x86_l_3940;
	case 14658ULL: goto x86_l_3942;
	case 14660ULL: goto x86_l_3944;
	case 14662ULL: goto x86_l_3946;
	case 14669ULL: goto x86_l_394d;
	case 14671ULL: goto x86_l_394f;
	case 14678ULL: goto x86_l_3956;
	case 14680ULL: goto x86_l_3958;
	case 14685ULL: goto x86_l_395d;
	case 14688ULL: goto x86_l_3960;
	case 14691ULL: goto x86_l_3963;
	case 14693ULL: goto x86_l_3965;
	case 14695ULL: goto x86_l_3967;
	case 14697ULL: goto x86_l_3969;
	case 14699ULL: goto x86_l_396b;
	case 14702ULL: goto x86_l_396e;
	case 14705ULL: goto x86_l_3971;
	case 14709ULL: goto x86_l_3975;
	case 14710ULL: goto x86_l_3976;
	case 14712ULL: goto x86_l_3978;
	case 14714ULL: goto x86_l_397a;
	case 14716ULL: goto x86_l_397c;
	default: return 0xffffffffffffffffULL;
	}
x86_l_365a:
	/* 0x365a: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_365c:
	/* 0x365c: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_365e:
	/* 0x365e: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_3660:
	/* 0x3660: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3662:
	/* 0x3662: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_3663:
	/* 0x3663: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_3664:
	/* 0x3664: mov    rbx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_3667:
	/* 0x3667: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_366a:
	/* 0x366a: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_366d:
	/* 0x366d: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_3670:
	/* 0x3670: call   38b9 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 13941ULL);
	__x86_sim_call_depth++;
	goto x86_l_38b9;
x86_l_3675:
	/* 0x3675: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3677:
	/* 0x3677: js     3820 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3820;
	}
x86_l_367d:
	/* 0x367d: mov    r13d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_3680:
	/* 0x3680: and    r13d,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_3687:
	/* 0x3687: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_368a:
	/* 0x368a: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_368d:
	/* 0x368d: je     38a7 <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38a7;
	}
x86_l_3693:
	/* 0x3693: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_3697:
	/* 0x3697: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_369a:
	/* 0x369a: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_369d:
	/* 0x369d: call   38b9 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 13986ULL);
	__x86_sim_call_depth++;
	goto x86_l_38b9;
x86_l_36a2:
	/* 0x36a2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_36a4:
	/* 0x36a4: js     3820 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3820;
	}
x86_l_36aa:
	/* 0x36aa: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_36af:
	/* 0x36af: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_36b2:
	/* 0x36b2: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_36b5:
	/* 0x36b5: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_36b8:
	/* 0x36b8: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_36bb:
	/* 0x36bb: je     38a7 <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38a7;
	}
x86_l_36c1:
	/* 0x36c1: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_36c5:
	/* 0x36c5: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_36c8:
	/* 0x36c8: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_36cb:
	/* 0x36cb: call   38b9 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 14032ULL);
	__x86_sim_call_depth++;
	goto x86_l_38b9;
x86_l_36d0:
	/* 0x36d0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_36d2:
	/* 0x36d2: js     3820 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3820;
	}
x86_l_36d8:
	/* 0x36d8: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_36dd:
	/* 0x36dd: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_36e0:
	/* 0x36e0: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_36e3:
	/* 0x36e3: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_36e6:
	/* 0x36e6: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_36e9:
	/* 0x36e9: je     38a7 <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38a7;
	}
x86_l_36ef:
	/* 0x36ef: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_36f3:
	/* 0x36f3: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_36f6:
	/* 0x36f6: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_36f9:
	/* 0x36f9: call   38b9 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 14078ULL);
	__x86_sim_call_depth++;
	goto x86_l_38b9;
x86_l_36fe:
	/* 0x36fe: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3700:
	/* 0x3700: js     3820 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3820;
	}
x86_l_3706:
	/* 0x3706: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_370b:
	/* 0x370b: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_370e:
	/* 0x370e: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3711:
	/* 0x3711: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_3714:
	/* 0x3714: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3717:
	/* 0x3717: je     38a7 <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38a7;
	}
x86_l_371d:
	/* 0x371d: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_3721:
	/* 0x3721: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3724:
	/* 0x3724: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_3727:
	/* 0x3727: call   38b9 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 14124ULL);
	__x86_sim_call_depth++;
	goto x86_l_38b9;
x86_l_372c:
	/* 0x372c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_372e:
	/* 0x372e: js     3820 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3820;
	}
x86_l_3734:
	/* 0x3734: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_3739:
	/* 0x3739: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_373c:
	/* 0x373c: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_373f:
	/* 0x373f: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_3742:
	/* 0x3742: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3745:
	/* 0x3745: je     38a7 <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38a7;
	}
x86_l_374b:
	/* 0x374b: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_374f:
	/* 0x374f: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3752:
	/* 0x3752: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_3755:
	/* 0x3755: call   38b9 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 14170ULL);
	__x86_sim_call_depth++;
	goto x86_l_38b9;
x86_l_375a:
	/* 0x375a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_375c:
	/* 0x375c: js     3820 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3820;
	}
x86_l_3762:
	/* 0x3762: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_3767:
	/* 0x3767: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_376a:
	/* 0x376a: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_376d:
	/* 0x376d: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_3770:
	/* 0x3770: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3773:
	/* 0x3773: je     38a7 <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38a7;
	}
x86_l_3779:
	/* 0x3779: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_377d:
	/* 0x377d: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3780:
	/* 0x3780: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_3783:
	/* 0x3783: call   38b9 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 14216ULL);
	__x86_sim_call_depth++;
	goto x86_l_38b9;
x86_l_3788:
	/* 0x3788: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_378a:
	/* 0x378a: js     3820 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3820;
	}
x86_l_3790:
	/* 0x3790: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_3795:
	/* 0x3795: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_3798:
	/* 0x3798: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_379b:
	/* 0x379b: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_379e:
	/* 0x379e: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_37a1:
	/* 0x37a1: je     38a7 <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38a7;
	}
x86_l_37a7:
	/* 0x37a7: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_37ab:
	/* 0x37ab: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_37ae:
	/* 0x37ae: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_37b1:
	/* 0x37b1: call   38b9 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 14262ULL);
	__x86_sim_call_depth++;
	goto x86_l_38b9;
x86_l_37b6:
	/* 0x37b6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_37b8:
	/* 0x37b8: js     3820 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3820;
	}
x86_l_37ba:
	/* 0x37ba: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_37bf:
	/* 0x37bf: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_37c2:
	/* 0x37c2: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_37c5:
	/* 0x37c5: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_37c8:
	/* 0x37c8: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_37cb:
	/* 0x37cb: je     38a7 <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38a7;
	}
x86_l_37d1:
	/* 0x37d1: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_37d5:
	/* 0x37d5: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_37d8:
	/* 0x37d8: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_37db:
	/* 0x37db: call   38b9 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 14304ULL);
	__x86_sim_call_depth++;
	goto x86_l_38b9;
x86_l_37e0:
	/* 0x37e0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_37e2:
	/* 0x37e2: js     3820 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3820;
	}
x86_l_37e4:
	/* 0x37e4: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_37e9:
	/* 0x37e9: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_37ec:
	/* 0x37ec: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_37ef:
	/* 0x37ef: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_37f2:
	/* 0x37f2: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_37f5:
	/* 0x37f5: je     38a7 <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38a7;
	}
x86_l_37fb:
	/* 0x37fb: add    r14,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_37fe:
	/* 0x37fe: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3801:
	/* 0x3801: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_3804:
	/* 0x3804: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_3807:
	/* 0x3807: call   38b9 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 14348ULL);
	__x86_sim_call_depth++;
	goto x86_l_38b9;
x86_l_380c:
	/* 0x380c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_380e:
	/* 0x380e: js     3820 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3820;
	}
x86_l_3810:
	/* 0x3810: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_3815:
	/* 0x3815: add    rax,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3818:
	/* 0x3818: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_381b:
	/* 0x381b: jmp    38a7 <do_bytes+0x24e> */
	goto x86_l_38a7;
x86_l_3820:
	/* 0x3820: movsxd rbx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_3823:
	/* 0x3823: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_382b:
	/* 0x382b: mov    rdi,QWORD PTR [rip+0x320] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_3832:
	/* 0x3832: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3837:
	/* 0x3837: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_383c:
	/* 0x383c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_383e:
	/* 0x383e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3841:
	/* 0x3841: je     38a7 <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38a7;
	}
x86_l_3843:
	/* 0x3843: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_3847:
	/* 0x3847: jg     3863 <do_bytes+0x20a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3863;
	}
x86_l_3849:
	/* 0x3849: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_384d:
	/* 0x384d: je     387d <do_bytes+0x224> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_387d;
	}
x86_l_384f:
	/* 0x384f: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_3853:
	/* 0x3853: je     3895 <do_bytes+0x23c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3895;
	}
x86_l_3855:
	/* 0x3855: cmp    rbx,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_3859:
	/* 0x3859: jne    388d <do_bytes+0x234> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_388d;
	}
x86_l_385b:
	/* 0x385b: add    rax,0x558 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1368ULL);
x86_l_3861:
	/* 0x3861: jmp    38a3 <do_bytes+0x24a> */
	goto x86_l_38a3;
x86_l_3863:
	/* 0x3863: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_3867:
	/* 0x3867: je     3885 <do_bytes+0x22c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3885;
	}
x86_l_3869:
	/* 0x3869: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_386d:
	/* 0x386d: je     389d <do_bytes+0x244> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_389d;
	}
x86_l_386f:
	/* 0x386f: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_3873:
	/* 0x3873: jne    388d <do_bytes+0x234> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_388d;
	}
x86_l_3875:
	/* 0x3875: add    rax,0x548 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1352ULL);
x86_l_387b:
	/* 0x387b: jmp    38a3 <do_bytes+0x24a> */
	goto x86_l_38a3;
x86_l_387d:
	/* 0x387d: add    rax,0x568 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1384ULL);
x86_l_3883:
	/* 0x3883: jmp    38a3 <do_bytes+0x24a> */
	goto x86_l_38a3;
x86_l_3885:
	/* 0x3885: add    rax,0x570 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1392ULL);
x86_l_388b:
	/* 0x388b: jmp    38a3 <do_bytes+0x24a> */
	goto x86_l_38a3;
x86_l_388d:
	/* 0x388d: add    rax,0x540 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1344ULL);
x86_l_3893:
	/* 0x3893: jmp    38a3 <do_bytes+0x24a> */
	goto x86_l_38a3;
x86_l_3895:
	/* 0x3895: add    rax,0x560 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1376ULL);
x86_l_389b:
	/* 0x389b: jmp    38a3 <do_bytes+0x24a> */
	goto x86_l_38a3;
x86_l_389d:
	/* 0x389d: add    rax,0x550 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1360ULL);
x86_l_38a3:
	/* 0x38a3: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_38a7:
	/* 0x38a7: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_38aa:
	/* 0x38aa: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_38ae:
	/* 0x38ae: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_38af:
	/* 0x38af: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_38b1:
	/* 0x38b1: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_38b3:
	/* 0x38b3: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_38b5:
	/* 0x38b5: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_38b7:
	/* 0x38b7: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_38b8:
	/* 0x38b8: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_38b9:
	/* 0x38b9: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_38bb:
	/* 0x38bb: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_38bd:
	/* 0x38bd: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_38bf:
	/* 0x38bf: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_38c0:
	/* 0x38c0: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_38c1:
	/* 0x38c1: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_38c4:
	/* 0x38c4: js     3946 <__do_bytes+0x8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3946;
	}
x86_l_38ca:
	/* 0x38ca: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_38cd:
	/* 0x38cd: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_38d0:
	/* 0x38d0: cmp    rcx,0x7fe0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 32736ULL);
x86_l_38d7:
	/* 0x38d7: mov    ebx,0x7fe0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 32736ULL);
x86_l_38dc:
	/* 0x38dc: cmovb  rbx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RCX, X86_WIDTH_64, X86_CC_B);
x86_l_38e0:
	/* 0x38e0: lea    rdi,[rsi+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_38e4:
	/* 0x38e4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_38e9:
	/* 0x38e9: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_38eb:
	/* 0x38eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38ed:
	/* 0x38ed: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_38ef:
	/* 0x38ef: js     396b <__do_bytes+0xb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_396b;
	}
x86_l_38f1:
	/* 0x38f1: lea    r15d,[rbx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_38f5:
	/* 0x38f5: mov    DWORD PTR [r14+0x4],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_38f9:
	/* 0x38f9: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_3901:
	/* 0x3901: mov    rdi,QWORD PTR [rip+0x57c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_conf_map)));
x86_l_3908:
	/* 0x3908: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_390d:
	/* 0x390d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3912:
	/* 0x3912: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3914:
	/* 0x3914: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3917:
	/* 0x3917: je     394f <__do_bytes+0x96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_394f;
	}
x86_l_3919:
	/* 0x3919: cmp    BYTE PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_391d:
	/* 0x391d: je     394f <__do_bytes+0x96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_394f;
	}
x86_l_391f:
	/* 0x391f: mov    rsi,QWORD PTR [rip+0x57c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_3926:
	/* 0x3926: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_392b:
	/* 0x392b: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_3930:
	/* 0x3930: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3933:
	/* 0x3933: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_3938:
	/* 0x3938: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_393b:
	/* 0x393b: mov    r8,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R15, X86_WIDTH_64);
x86_l_393e:
	/* 0x393e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3940:
	/* 0x3940: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3942:
	/* 0x3942: js     396b <__do_bytes+0xb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_396b;
	}
x86_l_3944:
	/* 0x3944: jmp    396e <__do_bytes+0xb5> */
	goto x86_l_396e;
x86_l_3946:
	/* 0x3946: mov    rbx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_394d:
	/* 0x394d: jmp    396e <__do_bytes+0xb5> */
	goto x86_l_396e;
x86_l_394f:
	/* 0x394f: mov    rdi,QWORD PTR [rip+0x57c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_rb_events)));
x86_l_3956:
	/* 0x3956: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3958:
	/* 0x3958: mov    eax,0x82 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 130ULL);
x86_l_395d:
	/* 0x395d: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_3960:
	/* 0x3960: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3963:
	/* 0x3963: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3965:
	/* 0x3965: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3967:
	/* 0x3967: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3969:
	/* 0x3969: jns    396e <__do_bytes+0xb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_396e;
	}
x86_l_396b:
	/* 0x396b: movsxd rbx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_396e:
	/* 0x396e: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_3971:
	/* 0x3971: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3975:
	/* 0x3975: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_3976:
	/* 0x3976: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_3978:
	/* 0x3978: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_397a:
	/* 0x397a: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_397c:
	/* 0x397c: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_fentry_v61_generic_fentry_process_event_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 13204U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1806ULL)
			__x86_pc = tetragon_bpf_generic_fentry_v61_generic_fentry_process_event_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1811ULL && __x86_pc <= 3619ULL)
			__x86_pc = tetragon_bpf_generic_fentry_v61_generic_fentry_process_event_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3624ULL && __x86_pc <= 5475ULL)
			__x86_pc = tetragon_bpf_generic_fentry_v61_generic_fentry_process_event_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5480ULL && __x86_pc <= 7279ULL)
			__x86_pc = tetragon_bpf_generic_fentry_v61_generic_fentry_process_event_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7284ULL && __x86_pc <= 9037ULL)
			__x86_pc = tetragon_bpf_generic_fentry_v61_generic_fentry_process_event_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 9042ULL && __x86_pc <= 10799ULL)
			__x86_pc = tetragon_bpf_generic_fentry_v61_generic_fentry_process_event_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10804ULL && __x86_pc <= 12449ULL)
			__x86_pc = tetragon_bpf_generic_fentry_v61_generic_fentry_process_event_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12452ULL && __x86_pc <= 13913ULL)
			__x86_pc = tetragon_bpf_generic_fentry_v61_generic_fentry_process_event_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 13914ULL && __x86_pc <= 14716ULL)
			__x86_pc = tetragon_bpf_generic_fentry_v61_generic_fentry_process_event_x86_chunk_8(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

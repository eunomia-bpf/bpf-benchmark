extern char CONFIG_ITER_NUM;
extern char config_map;
extern char heap_ro_zero;
extern char sleepable_preload;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_0(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 0ULL: goto x86_l_0;
	case 1ULL: goto x86_l_1;
	case 3ULL: goto x86_l_3;
	case 10ULL: goto x86_l_a;
	case 15ULL: goto x86_l_f;
	case 20ULL: goto x86_l_14;
	case 22ULL: goto x86_l_16;
	case 29ULL: goto x86_l_1d;
	case 36ULL: goto x86_l_24;
	case 44ULL: goto x86_l_2c;
	case 49ULL: goto x86_l_31;
	case 51ULL: goto x86_l_33;
	case 54ULL: goto x86_l_36;
	case 60ULL: goto x86_l_3c;
	case 63ULL: goto x86_l_3f;
	case 70ULL: goto x86_l_46;
	case 75ULL: goto x86_l_4b;
	case 82ULL: goto x86_l_52;
	case 87ULL: goto x86_l_57;
	case 94ULL: goto x86_l_5e;
	case 99ULL: goto x86_l_63;
	case 103ULL: goto x86_l_67;
	case 108ULL: goto x86_l_6c;
	case 112ULL: goto x86_l_70;
	case 117ULL: goto x86_l_75;
	case 121ULL: goto x86_l_79;
	case 126ULL: goto x86_l_7e;
	case 130ULL: goto x86_l_82;
	case 135ULL: goto x86_l_87;
	case 139ULL: goto x86_l_8b;
	case 147ULL: goto x86_l_93;
	case 151ULL: goto x86_l_97;
	case 156ULL: goto x86_l_9c;
	case 160ULL: goto x86_l_a0;
	case 168ULL: goto x86_l_a8;
	case 172ULL: goto x86_l_ac;
	case 177ULL: goto x86_l_b1;
	case 181ULL: goto x86_l_b5;
	case 189ULL: goto x86_l_bd;
	case 193ULL: goto x86_l_c1;
	case 198ULL: goto x86_l_c6;
	case 202ULL: goto x86_l_ca;
	case 210ULL: goto x86_l_d2;
	case 214ULL: goto x86_l_d6;
	case 219ULL: goto x86_l_db;
	case 222ULL: goto x86_l_de;
	case 226ULL: goto x86_l_e2;
	case 231ULL: goto x86_l_e7;
	case 235ULL: goto x86_l_eb;
	case 240ULL: goto x86_l_f0;
	case 246ULL: goto x86_l_f6;
	case 254ULL: goto x86_l_fe;
	case 257ULL: goto x86_l_101;
	case 264ULL: goto x86_l_108;
	case 267ULL: goto x86_l_10b;
	case 269ULL: goto x86_l_10d;
	case 271ULL: goto x86_l_10f;
	case 276ULL: goto x86_l_114;
	case 279ULL: goto x86_l_117;
	case 283ULL: goto x86_l_11b;
	case 287ULL: goto x86_l_11f;
	case 293ULL: goto x86_l_125;
	case 298ULL: goto x86_l_12a;
	case 303ULL: goto x86_l_12f;
	case 305ULL: goto x86_l_131;
	case 307ULL: goto x86_l_133;
	case 309ULL: goto x86_l_135;
	case 314ULL: goto x86_l_13a;
	case 317ULL: goto x86_l_13d;
	case 323ULL: goto x86_l_143;
	case 326ULL: goto x86_l_146;
	case 332ULL: goto x86_l_14c;
	case 335ULL: goto x86_l_14f;
	case 341ULL: goto x86_l_155;
	case 344ULL: goto x86_l_158;
	case 350ULL: goto x86_l_15e;
	case 355ULL: goto x86_l_163;
	case 360ULL: goto x86_l_168;
	case 369ULL: goto x86_l_171;
	case 378ULL: goto x86_l_17a;
	case 384ULL: goto x86_l_180;
	case 387ULL: goto x86_l_183;
	case 389ULL: goto x86_l_185;
	case 392ULL: goto x86_l_188;
	case 398ULL: goto x86_l_18e;
	case 401ULL: goto x86_l_191;
	case 407ULL: goto x86_l_197;
	case 412ULL: goto x86_l_19c;
	case 415ULL: goto x86_l_19f;
	case 421ULL: goto x86_l_1a5;
	case 426ULL: goto x86_l_1aa;
	case 429ULL: goto x86_l_1ad;
	case 435ULL: goto x86_l_1b3;
	case 440ULL: goto x86_l_1b8;
	case 443ULL: goto x86_l_1bb;
	case 449ULL: goto x86_l_1c1;
	case 454ULL: goto x86_l_1c6;
	case 459ULL: goto x86_l_1cb;
	case 462ULL: goto x86_l_1ce;
	case 464ULL: goto x86_l_1d0;
	case 467ULL: goto x86_l_1d3;
	case 473ULL: goto x86_l_1d9;
	case 478ULL: goto x86_l_1de;
	case 480ULL: goto x86_l_1e0;
	case 486ULL: goto x86_l_1e6;
	case 494ULL: goto x86_l_1ee;
	case 499ULL: goto x86_l_1f3;
	case 502ULL: goto x86_l_1f6;
	case 508ULL: goto x86_l_1fc;
	case 513ULL: goto x86_l_201;
	case 515ULL: goto x86_l_203;
	case 521ULL: goto x86_l_209;
	case 524ULL: goto x86_l_20c;
	case 530ULL: goto x86_l_212;
	case 535ULL: goto x86_l_217;
	case 537ULL: goto x86_l_219;
	case 540ULL: goto x86_l_21c;
	case 546ULL: goto x86_l_222;
	case 554ULL: goto x86_l_22a;
	case 557ULL: goto x86_l_22d;
	case 563ULL: goto x86_l_233;
	case 568ULL: goto x86_l_238;
	case 573ULL: goto x86_l_23d;
	case 576ULL: goto x86_l_240;
	case 582ULL: goto x86_l_246;
	case 587ULL: goto x86_l_24b;
	case 590ULL: goto x86_l_24e;
	case 596ULL: goto x86_l_254;
	case 604ULL: goto x86_l_25c;
	case 607ULL: goto x86_l_25f;
	case 613ULL: goto x86_l_265;
	case 618ULL: goto x86_l_26a;
	case 623ULL: goto x86_l_26f;
	case 626ULL: goto x86_l_272;
	case 632ULL: goto x86_l_278;
	case 637ULL: goto x86_l_27d;
	case 642ULL: goto x86_l_282;
	case 644ULL: goto x86_l_284;
	case 649ULL: goto x86_l_289;
	case 651ULL: goto x86_l_28b;
	case 656ULL: goto x86_l_290;
	case 659ULL: goto x86_l_293;
	case 663ULL: goto x86_l_297;
	case 666ULL: goto x86_l_29a;
	case 669ULL: goto x86_l_29d;
	case 674ULL: goto x86_l_2a2;
	case 680ULL: goto x86_l_2a8;
	case 687ULL: goto x86_l_2af;
	case 690ULL: goto x86_l_2b2;
	case 693ULL: goto x86_l_2b5;
	case 696ULL: goto x86_l_2b8;
	case 700ULL: goto x86_l_2bc;
	case 704ULL: goto x86_l_2c0;
	case 706ULL: goto x86_l_2c2;
	case 712ULL: goto x86_l_2c8;
	case 715ULL: goto x86_l_2cb;
	case 717ULL: goto x86_l_2cd;
	case 722ULL: goto x86_l_2d2;
	case 727ULL: goto x86_l_2d7;
	case 730ULL: goto x86_l_2da;
	case 734ULL: goto x86_l_2de;
	case 739ULL: goto x86_l_2e3;
	case 741ULL: goto x86_l_2e5;
	case 743ULL: goto x86_l_2e7;
	case 749ULL: goto x86_l_2ed;
	case 754ULL: goto x86_l_2f2;
	case 760ULL: goto x86_l_2f8;
	case 763ULL: goto x86_l_2fb;
	case 767ULL: goto x86_l_2ff;
	case 771ULL: goto x86_l_303;
	case 776ULL: goto x86_l_308;
	case 778ULL: goto x86_l_30a;
	case 783ULL: goto x86_l_30f;
	case 788ULL: goto x86_l_314;
	case 791ULL: goto x86_l_317;
	case 795ULL: goto x86_l_31b;
	case 800ULL: goto x86_l_320;
	case 802ULL: goto x86_l_322;
	case 804ULL: goto x86_l_324;
	case 810ULL: goto x86_l_32a;
	case 815ULL: goto x86_l_32f;
	case 821ULL: goto x86_l_335;
	case 824ULL: goto x86_l_338;
	case 828ULL: goto x86_l_33c;
	case 832ULL: goto x86_l_340;
	case 837ULL: goto x86_l_345;
	case 839ULL: goto x86_l_347;
	case 844ULL: goto x86_l_34c;
	case 849ULL: goto x86_l_351;
	case 852ULL: goto x86_l_354;
	case 856ULL: goto x86_l_358;
	case 861ULL: goto x86_l_35d;
	case 863ULL: goto x86_l_35f;
	case 865ULL: goto x86_l_361;
	case 871ULL: goto x86_l_367;
	case 876ULL: goto x86_l_36c;
	case 882ULL: goto x86_l_372;
	case 885ULL: goto x86_l_375;
	case 889ULL: goto x86_l_379;
	case 893ULL: goto x86_l_37d;
	case 898ULL: goto x86_l_382;
	case 900ULL: goto x86_l_384;
	case 905ULL: goto x86_l_389;
	case 910ULL: goto x86_l_38e;
	case 913ULL: goto x86_l_391;
	case 917ULL: goto x86_l_395;
	case 922ULL: goto x86_l_39a;
	case 924ULL: goto x86_l_39c;
	case 926ULL: goto x86_l_39e;
	case 932ULL: goto x86_l_3a4;
	case 937ULL: goto x86_l_3a9;
	case 943ULL: goto x86_l_3af;
	case 946ULL: goto x86_l_3b2;
	case 950ULL: goto x86_l_3b6;
	case 954ULL: goto x86_l_3ba;
	case 959ULL: goto x86_l_3bf;
	case 961ULL: goto x86_l_3c1;
	case 966ULL: goto x86_l_3c6;
	case 971ULL: goto x86_l_3cb;
	case 974ULL: goto x86_l_3ce;
	case 978ULL: goto x86_l_3d2;
	case 983ULL: goto x86_l_3d7;
	case 985ULL: goto x86_l_3d9;
	case 987ULL: goto x86_l_3db;
	case 993ULL: goto x86_l_3e1;
	case 998ULL: goto x86_l_3e6;
	case 1004ULL: goto x86_l_3ec;
	case 1007ULL: goto x86_l_3ef;
	case 1011ULL: goto x86_l_3f3;
	case 1015ULL: goto x86_l_3f7;
	case 1020ULL: goto x86_l_3fc;
	case 1022ULL: goto x86_l_3fe;
	case 1027ULL: goto x86_l_403;
	case 1032ULL: goto x86_l_408;
	case 1035ULL: goto x86_l_40b;
	case 1039ULL: goto x86_l_40f;
	case 1044ULL: goto x86_l_414;
	case 1046ULL: goto x86_l_416;
	case 1048ULL: goto x86_l_418;
	case 1054ULL: goto x86_l_41e;
	case 1059ULL: goto x86_l_423;
	case 1065ULL: goto x86_l_429;
	case 1068ULL: goto x86_l_42c;
	case 1072ULL: goto x86_l_430;
	case 1076ULL: goto x86_l_434;
	case 1081ULL: goto x86_l_439;
	case 1083ULL: goto x86_l_43b;
	case 1088ULL: goto x86_l_440;
	case 1093ULL: goto x86_l_445;
	case 1096ULL: goto x86_l_448;
	case 1100ULL: goto x86_l_44c;
	case 1105ULL: goto x86_l_451;
	case 1107ULL: goto x86_l_453;
	case 1109ULL: goto x86_l_455;
	case 1115ULL: goto x86_l_45b;
	case 1120ULL: goto x86_l_460;
	case 1126ULL: goto x86_l_466;
	case 1129ULL: goto x86_l_469;
	case 1133ULL: goto x86_l_46d;
	case 1137ULL: goto x86_l_471;
	case 1142ULL: goto x86_l_476;
	case 1144ULL: goto x86_l_478;
	case 1149ULL: goto x86_l_47d;
	case 1154ULL: goto x86_l_482;
	case 1157ULL: goto x86_l_485;
	case 1161ULL: goto x86_l_489;
	case 1166ULL: goto x86_l_48e;
	case 1168ULL: goto x86_l_490;
	case 1170ULL: goto x86_l_492;
	case 1176ULL: goto x86_l_498;
	case 1181ULL: goto x86_l_49d;
	case 1187ULL: goto x86_l_4a3;
	case 1190ULL: goto x86_l_4a6;
	case 1194ULL: goto x86_l_4aa;
	case 1198ULL: goto x86_l_4ae;
	case 1203ULL: goto x86_l_4b3;
	case 1205ULL: goto x86_l_4b5;
	case 1210ULL: goto x86_l_4ba;
	case 1215ULL: goto x86_l_4bf;
	case 1218ULL: goto x86_l_4c2;
	case 1222ULL: goto x86_l_4c6;
	case 1227ULL: goto x86_l_4cb;
	case 1229ULL: goto x86_l_4cd;
	case 1231ULL: goto x86_l_4cf;
	case 1237ULL: goto x86_l_4d5;
	case 1241ULL: goto x86_l_4d9;
	case 1247ULL: goto x86_l_4df;
	case 1250ULL: goto x86_l_4e2;
	case 1254ULL: goto x86_l_4e6;
	case 1258ULL: goto x86_l_4ea;
	case 1263ULL: goto x86_l_4ef;
	case 1269ULL: goto x86_l_4f5;
	case 1274ULL: goto x86_l_4fa;
	case 1279ULL: goto x86_l_4ff;
	case 1282ULL: goto x86_l_502;
	case 1287ULL: goto x86_l_507;
	case 1290ULL: goto x86_l_50a;
	case 1292ULL: goto x86_l_50c;
	case 1297ULL: goto x86_l_511;
	case 1302ULL: goto x86_l_516;
	case 1305ULL: goto x86_l_519;
	case 1309ULL: goto x86_l_51d;
	case 1314ULL: goto x86_l_522;
	case 1316ULL: goto x86_l_524;
	case 1318ULL: goto x86_l_526;
	case 1324ULL: goto x86_l_52c;
	case 1329ULL: goto x86_l_531;
	case 1335ULL: goto x86_l_537;
	case 1338ULL: goto x86_l_53a;
	case 1342ULL: goto x86_l_53e;
	case 1346ULL: goto x86_l_542;
	case 1351ULL: goto x86_l_547;
	case 1353ULL: goto x86_l_549;
	case 1358ULL: goto x86_l_54e;
	case 1363ULL: goto x86_l_553;
	case 1366ULL: goto x86_l_556;
	case 1370ULL: goto x86_l_55a;
	case 1375ULL: goto x86_l_55f;
	case 1377ULL: goto x86_l_561;
	case 1379ULL: goto x86_l_563;
	case 1385ULL: goto x86_l_569;
	case 1390ULL: goto x86_l_56e;
	case 1396ULL: goto x86_l_574;
	case 1399ULL: goto x86_l_577;
	case 1403ULL: goto x86_l_57b;
	case 1407ULL: goto x86_l_57f;
	case 1412ULL: goto x86_l_584;
	case 1414ULL: goto x86_l_586;
	case 1419ULL: goto x86_l_58b;
	case 1424ULL: goto x86_l_590;
	case 1427ULL: goto x86_l_593;
	case 1431ULL: goto x86_l_597;
	case 1436ULL: goto x86_l_59c;
	case 1438ULL: goto x86_l_59e;
	case 1440ULL: goto x86_l_5a0;
	case 1446ULL: goto x86_l_5a6;
	case 1451ULL: goto x86_l_5ab;
	case 1457ULL: goto x86_l_5b1;
	case 1460ULL: goto x86_l_5b4;
	case 1464ULL: goto x86_l_5b8;
	case 1468ULL: goto x86_l_5bc;
	case 1473ULL: goto x86_l_5c1;
	case 1475ULL: goto x86_l_5c3;
	case 1480ULL: goto x86_l_5c8;
	case 1485ULL: goto x86_l_5cd;
	case 1488ULL: goto x86_l_5d0;
	case 1492ULL: goto x86_l_5d4;
	case 1497ULL: goto x86_l_5d9;
	case 1499ULL: goto x86_l_5db;
	case 1501ULL: goto x86_l_5dd;
	case 1507ULL: goto x86_l_5e3;
	case 1512ULL: goto x86_l_5e8;
	case 1518ULL: goto x86_l_5ee;
	case 1521ULL: goto x86_l_5f1;
	case 1525ULL: goto x86_l_5f5;
	case 1529ULL: goto x86_l_5f9;
	case 1534ULL: goto x86_l_5fe;
	case 1536ULL: goto x86_l_600;
	case 1541ULL: goto x86_l_605;
	case 1546ULL: goto x86_l_60a;
	case 1549ULL: goto x86_l_60d;
	case 1553ULL: goto x86_l_611;
	case 1558ULL: goto x86_l_616;
	case 1560ULL: goto x86_l_618;
	case 1562ULL: goto x86_l_61a;
	case 1568ULL: goto x86_l_620;
	case 1573ULL: goto x86_l_625;
	case 1579ULL: goto x86_l_62b;
	case 1582ULL: goto x86_l_62e;
	case 1586ULL: goto x86_l_632;
	case 1590ULL: goto x86_l_636;
	case 1595ULL: goto x86_l_63b;
	case 1597ULL: goto x86_l_63d;
	case 1602ULL: goto x86_l_642;
	case 1607ULL: goto x86_l_647;
	case 1610ULL: goto x86_l_64a;
	case 1614ULL: goto x86_l_64e;
	case 1619ULL: goto x86_l_653;
	case 1621ULL: goto x86_l_655;
	case 1623ULL: goto x86_l_657;
	case 1629ULL: goto x86_l_65d;
	case 1634ULL: goto x86_l_662;
	case 1640ULL: goto x86_l_668;
	case 1643ULL: goto x86_l_66b;
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
	/* 0xa: mov    eax,0xae */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 174ULL);
x86_l_f:
	/* 0xf: mov    QWORD PTR [rsp+0x48],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_14:
	/* 0x14: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16:
	/* 0x16: mov    DWORD PTR [rsp+0xac],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_1d:
	/* 0x1d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_24:
	/* 0x24: lea    rsi,[rsp+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_2c:
	/* 0x2c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_31:
	/* 0x31: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33:
	/* 0x33: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_36:
	/* 0x36: je     4c73 <generic_sleepable_preload+0x4c73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19571ULL;
	}
x86_l_3c:
	/* 0x3c: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_3f:
	/* 0x3f: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_46:
	/* 0x46: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4b:
	/* 0x4b: lea    rdx,[rcx+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_52:
	/* 0x52: mov    QWORD PTR [rsp+0x50],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_57:
	/* 0x57: lea    rdx,[rcx+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_5e:
	/* 0x5e: mov    QWORD PTR [rsp+0x70],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_63:
	/* 0x63: lea    rdx,[rcx+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_67:
	/* 0x67: mov    QWORD PTR [rsp+0x40],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_6c:
	/* 0x6c: lea    rdx,[rcx+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_70:
	/* 0x70: mov    QWORD PTR [rsp+0x30],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_75:
	/* 0x75: lea    rdx,[rcx+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_79:
	/* 0x79: mov    QWORD PTR [rsp+0x38],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_7e:
	/* 0x7e: lea    rdx,[rcx+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_82:
	/* 0x82: mov    QWORD PTR [rsp+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_87:
	/* 0x87: lea    rdx,[rcx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_8b:
	/* 0x8b: mov    QWORD PTR [rsp+0x98],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_93:
	/* 0x93: lea    rdx,[rcx+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_97:
	/* 0x97: mov    QWORD PTR [rsp+0x28],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_9c:
	/* 0x9c: lea    rdx,[rcx+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_a0:
	/* 0xa0: mov    QWORD PTR [rsp+0x90],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_a8:
	/* 0xa8: lea    rdx,[rcx+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_ac:
	/* 0xac: mov    QWORD PTR [rsp+0x68],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_b1:
	/* 0xb1: lea    rdx,[rcx+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b5:
	/* 0xb5: mov    QWORD PTR [rsp+0x88],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_bd:
	/* 0xbd: lea    rdx,[rcx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c1:
	/* 0xc1: mov    QWORD PTR [rsp+0x60],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_c6:
	/* 0xc6: lea    rdx,[rcx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ca:
	/* 0xca: mov    QWORD PTR [rsp+0x80],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_d2:
	/* 0xd2: lea    rdx,[rcx+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d6:
	/* 0xd6: mov    QWORD PTR [rsp+0x58],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_db:
	/* 0xdb: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_de:
	/* 0xde: lea    rax,[rcx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e2:
	/* 0xe2: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_e7:
	/* 0xe7: lea    r14,[rcx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_eb:
	/* 0xeb: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f0:
	/* 0xf0: je     ef7 <generic_sleepable_preload+0xef7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3831ULL;
	}
x86_l_f6:
	/* 0xf6: mov    QWORD PTR [rsp+0xb0],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_fe:
	/* 0xfe: mov    rbx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R12, X86_WIDTH_64);
x86_l_101:
	/* 0x101: add    rbx,0xbe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 190ULL);
x86_l_108:
	/* 0x108: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10b:
	/* 0x10b: jmp    125 <generic_sleepable_preload+0x125> */
	goto x86_l_125;
x86_l_10d:
	/* 0x10d: mov    DWORD PTR [rax],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10f:
	/* 0x10f: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_114:
	/* 0x114: inc    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_117:
	/* 0x117: add    rbx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_11b:
	/* 0x11b: cmp    r14,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 5ULL);
x86_l_11f:
	/* 0x11f: je     4c73 <generic_sleepable_preload+0x4c73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19571ULL;
	}
x86_l_125:
	/* 0x125: mov    eax,DWORD PTR [r12+r14*4+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 24ULL);
x86_l_12a:
	/* 0x12a: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_12f:
	/* 0x12f: je     114 <generic_sleepable_preload+0x114> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_114;
	}
x86_l_131:
	/* 0x131: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_133:
	/* 0x133: js     168 <generic_sleepable_preload+0x168> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_168;
	}
x86_l_135:
	/* 0x135: mov    eax,DWORD PTR [r12+r14*4+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 64ULL);
x86_l_13a:
	/* 0x13a: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13d:
	/* 0x13d: jle    201 <generic_sleepable_preload+0x201> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_201;
	}
x86_l_143:
	/* 0x143: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_146:
	/* 0x146: je     27d <generic_sleepable_preload+0x27d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27d;
	}
x86_l_14c:
	/* 0x14c: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_14f:
	/* 0x14f: je     284 <generic_sleepable_preload+0x284> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_284;
	}
x86_l_155:
	/* 0x155: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_158:
	/* 0x158: jne    297 <generic_sleepable_preload+0x297> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_297;
	}
x86_l_15e:
	/* 0x15e: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_163:
	/* 0x163: jmp    290 <generic_sleepable_preload+0x290> */
	goto x86_l_290;
x86_l_168:
	/* 0x168: movzx  eax,BYTE PTR [r12+r14*4+0x2c2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R14, 2, X86_WIDTH_8), 706ULL);
x86_l_171:
	/* 0x171: movzx  ecx,WORD PTR [r12+r14*4+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R14, 2, X86_WIDTH_16), 704ULL);
x86_l_17a:
	/* 0x17a: rorx   ecx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_180:
	/* 0x180: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_183:
	/* 0x183: jle    1cb <generic_sleepable_preload+0x1cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1cb;
	}
x86_l_185:
	/* 0x185: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_188:
	/* 0x188: jle    219 <generic_sleepable_preload+0x219> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_219;
	}
x86_l_18e:
	/* 0x18e: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_191:
	/* 0x191: jle    7c1 <generic_sleepable_preload+0x7c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 1985ULL;
	}
x86_l_197:
	/* 0x197: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_19c:
	/* 0x19c: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_19f:
	/* 0x19f: je     7da <generic_sleepable_preload+0x7da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2010ULL;
	}
x86_l_1a5:
	/* 0x1a5: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1aa:
	/* 0x1aa: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1ad:
	/* 0x1ad: je     7da <generic_sleepable_preload+0x7da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2010ULL;
	}
x86_l_1b3:
	/* 0x1b3: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_1b8:
	/* 0x1b8: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_1bb:
	/* 0x1bb: jne    7ed <generic_sleepable_preload+0x7ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2029ULL;
	}
x86_l_1c1:
	/* 0x1c1: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1c6:
	/* 0x1c6: jmp    7da <generic_sleepable_preload+0x7da> */
	return 2010ULL;
x86_l_1cb:
	/* 0x1cb: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1ce:
	/* 0x1ce: jg     24b <generic_sleepable_preload+0x24b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_24b;
	}
x86_l_1d0:
	/* 0x1d0: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1d3:
	/* 0x1d3: jg     788 <generic_sleepable_preload+0x788> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 1928ULL;
	}
x86_l_1d9:
	/* 0x1d9: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1de:
	/* 0x1de: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1e0:
	/* 0x1e0: je     7da <generic_sleepable_preload+0x7da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2010ULL;
	}
x86_l_1e6:
	/* 0x1e6: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1ee:
	/* 0x1ee: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_1f3:
	/* 0x1f3: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1f6:
	/* 0x1f6: je     7da <generic_sleepable_preload+0x7da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2010ULL;
	}
x86_l_1fc:
	/* 0x1fc: jmp    7ed <generic_sleepable_preload+0x7ed> */
	return 2029ULL;
x86_l_201:
	/* 0x201: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_203:
	/* 0x203: je     28b <generic_sleepable_preload+0x28b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28b;
	}
x86_l_209:
	/* 0x209: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_20c:
	/* 0x20c: jne    297 <generic_sleepable_preload+0x297> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_297;
	}
x86_l_212:
	/* 0x212: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_217:
	/* 0x217: jmp    290 <generic_sleepable_preload+0x290> */
	goto x86_l_290;
x86_l_219:
	/* 0x219: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_21c:
	/* 0x21c: jg     76a <generic_sleepable_preload+0x76a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 1898ULL;
	}
x86_l_222:
	/* 0x222: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_22a:
	/* 0x22a: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_22d:
	/* 0x22d: je     7da <generic_sleepable_preload+0x7da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2010ULL;
	}
x86_l_233:
	/* 0x233: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_238:
	/* 0x238: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_23d:
	/* 0x23d: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_240:
	/* 0x240: je     7da <generic_sleepable_preload+0x7da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2010ULL;
	}
x86_l_246:
	/* 0x246: jmp    7ed <generic_sleepable_preload+0x7ed> */
	return 2029ULL;
x86_l_24b:
	/* 0x24b: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_24e:
	/* 0x24e: jg     7a3 <generic_sleepable_preload+0x7a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 1955ULL;
	}
x86_l_254:
	/* 0x254: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_25c:
	/* 0x25c: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_25f:
	/* 0x25f: je     7da <generic_sleepable_preload+0x7da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2010ULL;
	}
x86_l_265:
	/* 0x265: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_26a:
	/* 0x26a: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_26f:
	/* 0x26f: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_272:
	/* 0x272: je     7da <generic_sleepable_preload+0x7da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2010ULL;
	}
x86_l_278:
	/* 0x278: jmp    7ed <generic_sleepable_preload+0x7ed> */
	return 2029ULL;
x86_l_27d:
	/* 0x27d: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_282:
	/* 0x282: jmp    290 <generic_sleepable_preload+0x290> */
	goto x86_l_290;
x86_l_284:
	/* 0x284: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_289:
	/* 0x289: jmp    290 <generic_sleepable_preload+0x290> */
	goto x86_l_290;
x86_l_28b:
	/* 0x28b: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_290:
	/* 0x290: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_293:
	/* 0x293: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_297:
	/* 0x297: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_29a:
	/* 0x29a: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_29d:
	/* 0x29d: cmp    WORD PTR [rbx-0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743764471906304ULL);
x86_l_2a2:
	/* 0x2a2: je     d28 <generic_sleepable_preload+0xd28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3368ULL;
	}
x86_l_2a8:
	/* 0x2a8: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_2af:
	/* 0x2af: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2b2:
	/* 0x2b2: mov    eax,DWORD PTR [rbx-0x4e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551538ULL);
x86_l_2b5:
	/* 0x2b5: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2b8:
	/* 0x2b8: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bc:
	/* 0x2bc: movzx  eax,WORD PTR [rbx-0x4a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551542ULL);
x86_l_2c0:
	/* 0x2c0: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_2c2:
	/* 0x2c2: je     507 <generic_sleepable_preload+0x507> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_507;
	}
x86_l_2c8:
	/* 0x2c8: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_2cb:
	/* 0x2cb: je     2ed <generic_sleepable_preload+0x2ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ed;
	}
x86_l_2cd:
	/* 0x2cd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2d2:
	/* 0x2d2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2d7:
	/* 0x2d7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2da:
	/* 0x2da: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2de:
	/* 0x2de: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e3:
	/* 0x2e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e5:
	/* 0x2e5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2e7:
	/* 0x2e7: js     75f <generic_sleepable_preload+0x75f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 1887ULL;
	}
x86_l_2ed:
	/* 0x2ed: cmp    WORD PTR [rbx-0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743798831644672ULL);
x86_l_2f2:
	/* 0x2f2: je     d28 <generic_sleepable_preload+0xd28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3368ULL;
	}
x86_l_2f8:
	/* 0x2f8: mov    ecx,DWORD PTR [rbx-0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551546ULL);
x86_l_2fb:
	/* 0x2fb: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2ff:
	/* 0x2ff: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_303:
	/* 0x303: cmp    WORD PTR [rbx-0x42],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743790241710080ULL);
x86_l_308:
	/* 0x308: je     32a <generic_sleepable_preload+0x32a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32a;
	}
x86_l_30a:
	/* 0x30a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_30f:
	/* 0x30f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_314:
	/* 0x314: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_317:
	/* 0x317: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31b:
	/* 0x31b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_320:
	/* 0x320: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_322:
	/* 0x322: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_324:
	/* 0x324: js     cc6 <generic_sleepable_preload+0xcc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3270ULL;
	}
x86_l_32a:
	/* 0x32a: cmp    WORD PTR [rbx-0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743833191383040ULL);
x86_l_32f:
	/* 0x32f: je     d28 <generic_sleepable_preload+0xd28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3368ULL;
	}
x86_l_335:
	/* 0x335: mov    ecx,DWORD PTR [rbx-0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551554ULL);
x86_l_338:
	/* 0x338: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_33c:
	/* 0x33c: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_340:
	/* 0x340: cmp    WORD PTR [rbx-0x3a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743824601448448ULL);
x86_l_345:
	/* 0x345: je     367 <generic_sleepable_preload+0x367> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_367;
	}
x86_l_347:
	/* 0x347: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_34c:
	/* 0x34c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_351:
	/* 0x351: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_354:
	/* 0x354: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_358:
	/* 0x358: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_35d:
	/* 0x35d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35f:
	/* 0x35f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_361:
	/* 0x361: js     cd8 <generic_sleepable_preload+0xcd8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3288ULL;
	}
x86_l_367:
	/* 0x367: cmp    WORD PTR [rbx-0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743867551121408ULL);
x86_l_36c:
	/* 0x36c: je     d28 <generic_sleepable_preload+0xd28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3368ULL;
	}
x86_l_372:
	/* 0x372: mov    ecx,DWORD PTR [rbx-0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551562ULL);
x86_l_375:
	/* 0x375: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_379:
	/* 0x379: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37d:
	/* 0x37d: cmp    WORD PTR [rbx-0x32],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743858961186816ULL);
x86_l_382:
	/* 0x382: je     3a4 <generic_sleepable_preload+0x3a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a4;
	}
x86_l_384:
	/* 0x384: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_389:
	/* 0x389: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_38e:
	/* 0x38e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_391:
	/* 0x391: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_395:
	/* 0x395: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_39a:
	/* 0x39a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39c:
	/* 0x39c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_39e:
	/* 0x39e: js     cea <generic_sleepable_preload+0xcea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3306ULL;
	}
x86_l_3a4:
	/* 0x3a4: cmp    WORD PTR [rbx-0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743901910859776ULL);
x86_l_3a9:
	/* 0x3a9: je     d28 <generic_sleepable_preload+0xd28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3368ULL;
	}
x86_l_3af:
	/* 0x3af: mov    ecx,DWORD PTR [rbx-0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551570ULL);
x86_l_3b2:
	/* 0x3b2: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3b6:
	/* 0x3b6: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ba:
	/* 0x3ba: cmp    WORD PTR [rbx-0x2a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743893320925184ULL);
x86_l_3bf:
	/* 0x3bf: je     3e1 <generic_sleepable_preload+0x3e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e1;
	}
x86_l_3c1:
	/* 0x3c1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3c6:
	/* 0x3c6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3cb:
	/* 0x3cb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3ce:
	/* 0x3ce: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3d2:
	/* 0x3d2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d7:
	/* 0x3d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d9:
	/* 0x3d9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3db:
	/* 0x3db: js     cfc <generic_sleepable_preload+0xcfc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3324ULL;
	}
x86_l_3e1:
	/* 0x3e1: cmp    WORD PTR [rbx-0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743936270598144ULL);
x86_l_3e6:
	/* 0x3e6: je     d28 <generic_sleepable_preload+0xd28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3368ULL;
	}
x86_l_3ec:
	/* 0x3ec: mov    ecx,DWORD PTR [rbx-0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551578ULL);
x86_l_3ef:
	/* 0x3ef: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3f3:
	/* 0x3f3: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f7:
	/* 0x3f7: cmp    WORD PTR [rbx-0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743927680663552ULL);
x86_l_3fc:
	/* 0x3fc: je     41e <generic_sleepable_preload+0x41e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_41e;
	}
x86_l_3fe:
	/* 0x3fe: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_403:
	/* 0x403: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_408:
	/* 0x408: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_40b:
	/* 0x40b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_40f:
	/* 0x40f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_414:
	/* 0x414: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_416:
	/* 0x416: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_418:
	/* 0x418: js     d0e <generic_sleepable_preload+0xd0e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3342ULL;
	}
x86_l_41e:
	/* 0x41e: cmp    WORD PTR [rbx-0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743970630336512ULL);
x86_l_423:
	/* 0x423: je     d28 <generic_sleepable_preload+0xd28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3368ULL;
	}
x86_l_429:
	/* 0x429: mov    ecx,DWORD PTR [rbx-0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551586ULL);
x86_l_42c:
	/* 0x42c: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_430:
	/* 0x430: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_434:
	/* 0x434: cmp    WORD PTR [rbx-0x1a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743962040401920ULL);
x86_l_439:
	/* 0x439: je     45b <generic_sleepable_preload+0x45b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_45b;
	}
x86_l_43b:
	/* 0x43b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_440:
	/* 0x440: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_445:
	/* 0x445: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_448:
	/* 0x448: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_44c:
	/* 0x44c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_451:
	/* 0x451: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_453:
	/* 0x453: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_455:
	/* 0x455: js     d20 <generic_sleepable_preload+0xd20> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3360ULL;
	}
x86_l_45b:
	/* 0x45b: cmp    WORD PTR [rbx-0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744004990074880ULL);
x86_l_460:
	/* 0x460: je     d28 <generic_sleepable_preload+0xd28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3368ULL;
	}
x86_l_466:
	/* 0x466: mov    ecx,DWORD PTR [rbx-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_469:
	/* 0x469: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_46d:
	/* 0x46d: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_471:
	/* 0x471: cmp    WORD PTR [rbx-0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743996400140288ULL);
x86_l_476:
	/* 0x476: je     498 <generic_sleepable_preload+0x498> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_498;
	}
x86_l_478:
	/* 0x478: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_47d:
	/* 0x47d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_482:
	/* 0x482: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_485:
	/* 0x485: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_489:
	/* 0x489: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_48e:
	/* 0x48e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_490:
	/* 0x490: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_492:
	/* 0x492: js     ebe <generic_sleepable_preload+0xebe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3774ULL;
	}
x86_l_498:
	/* 0x498: cmp    WORD PTR [rbx-0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744039349813248ULL);
x86_l_49d:
	/* 0x49d: je     d28 <generic_sleepable_preload+0xd28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3368ULL;
	}
x86_l_4a3:
	/* 0x4a3: mov    ecx,DWORD PTR [rbx-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551602ULL);
x86_l_4a6:
	/* 0x4a6: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4aa:
	/* 0x4aa: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ae:
	/* 0x4ae: cmp    WORD PTR [rbx-0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744030759878656ULL);
x86_l_4b3:
	/* 0x4b3: je     4d5 <generic_sleepable_preload+0x4d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4d5;
	}
x86_l_4b5:
	/* 0x4b5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4ba:
	/* 0x4ba: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4bf:
	/* 0x4bf: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4c2:
	/* 0x4c2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c6:
	/* 0x4c6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4cb:
	/* 0x4cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4cd:
	/* 0x4cd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4cf:
	/* 0x4cf: js     ee2 <generic_sleepable_preload+0xee2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3810ULL;
	}
x86_l_4d5:
	/* 0x4d5: cmp    WORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d9:
	/* 0x4d9: je     d28 <generic_sleepable_preload+0xd28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3368ULL;
	}
x86_l_4df:
	/* 0x4df: mov    ecx,DWORD PTR [rbx-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_4e2:
	/* 0x4e2: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4e6:
	/* 0x4e6: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ea:
	/* 0x4ea: cmp    WORD PTR [rbx-0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744065119617024ULL);
x86_l_4ef:
	/* 0x4ef: je     d28 <generic_sleepable_preload+0xd28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3368ULL;
	}
x86_l_4f5:
	/* 0x4f5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4fa:
	/* 0x4fa: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4ff:
	/* 0x4ff: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_502:
	/* 0x502: jmp    741 <generic_sleepable_preload+0x741> */
	return 1857ULL;
x86_l_507:
	/* 0x507: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_50a:
	/* 0x50a: je     52c <generic_sleepable_preload+0x52c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_52c;
	}
x86_l_50c:
	/* 0x50c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_511:
	/* 0x511: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_516:
	/* 0x516: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_519:
	/* 0x519: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_51d:
	/* 0x51d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_522:
	/* 0x522: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_524:
	/* 0x524: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_526:
	/* 0x526: js     75f <generic_sleepable_preload+0x75f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 1887ULL;
	}
x86_l_52c:
	/* 0x52c: cmp    WORD PTR [rbx-0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743798831644672ULL);
x86_l_531:
	/* 0x531: je     d28 <generic_sleepable_preload+0xd28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3368ULL;
	}
x86_l_537:
	/* 0x537: mov    ecx,DWORD PTR [rbx-0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551546ULL);
x86_l_53a:
	/* 0x53a: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_53e:
	/* 0x53e: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_542:
	/* 0x542: cmp    WORD PTR [rbx-0x42],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743790241710080ULL);
x86_l_547:
	/* 0x547: je     569 <generic_sleepable_preload+0x569> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_569;
	}
x86_l_549:
	/* 0x549: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_54e:
	/* 0x54e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_553:
	/* 0x553: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_556:
	/* 0x556: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_55a:
	/* 0x55a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_55f:
	/* 0x55f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_561:
	/* 0x561: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_563:
	/* 0x563: js     cc6 <generic_sleepable_preload+0xcc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3270ULL;
	}
x86_l_569:
	/* 0x569: cmp    WORD PTR [rbx-0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743833191383040ULL);
x86_l_56e:
	/* 0x56e: je     d28 <generic_sleepable_preload+0xd28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3368ULL;
	}
x86_l_574:
	/* 0x574: mov    ecx,DWORD PTR [rbx-0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551554ULL);
x86_l_577:
	/* 0x577: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_57b:
	/* 0x57b: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_57f:
	/* 0x57f: cmp    WORD PTR [rbx-0x3a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743824601448448ULL);
x86_l_584:
	/* 0x584: je     5a6 <generic_sleepable_preload+0x5a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5a6;
	}
x86_l_586:
	/* 0x586: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_58b:
	/* 0x58b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_590:
	/* 0x590: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_593:
	/* 0x593: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_597:
	/* 0x597: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_59c:
	/* 0x59c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_59e:
	/* 0x59e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5a0:
	/* 0x5a0: js     cd8 <generic_sleepable_preload+0xcd8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3288ULL;
	}
x86_l_5a6:
	/* 0x5a6: cmp    WORD PTR [rbx-0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743867551121408ULL);
x86_l_5ab:
	/* 0x5ab: je     d28 <generic_sleepable_preload+0xd28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3368ULL;
	}
x86_l_5b1:
	/* 0x5b1: mov    ecx,DWORD PTR [rbx-0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551562ULL);
x86_l_5b4:
	/* 0x5b4: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5b8:
	/* 0x5b8: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5bc:
	/* 0x5bc: cmp    WORD PTR [rbx-0x32],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743858961186816ULL);
x86_l_5c1:
	/* 0x5c1: je     5e3 <generic_sleepable_preload+0x5e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5e3;
	}
x86_l_5c3:
	/* 0x5c3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5c8:
	/* 0x5c8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5cd:
	/* 0x5cd: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5d0:
	/* 0x5d0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d4:
	/* 0x5d4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5d9:
	/* 0x5d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5db:
	/* 0x5db: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5dd:
	/* 0x5dd: js     cea <generic_sleepable_preload+0xcea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3306ULL;
	}
x86_l_5e3:
	/* 0x5e3: cmp    WORD PTR [rbx-0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743901910859776ULL);
x86_l_5e8:
	/* 0x5e8: je     d28 <generic_sleepable_preload+0xd28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3368ULL;
	}
x86_l_5ee:
	/* 0x5ee: mov    ecx,DWORD PTR [rbx-0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551570ULL);
x86_l_5f1:
	/* 0x5f1: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5f5:
	/* 0x5f5: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5f9:
	/* 0x5f9: cmp    WORD PTR [rbx-0x2a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743893320925184ULL);
x86_l_5fe:
	/* 0x5fe: je     620 <generic_sleepable_preload+0x620> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_620;
	}
x86_l_600:
	/* 0x600: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_605:
	/* 0x605: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_60a:
	/* 0x60a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_60d:
	/* 0x60d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_611:
	/* 0x611: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_616:
	/* 0x616: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_618:
	/* 0x618: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_61a:
	/* 0x61a: js     cfc <generic_sleepable_preload+0xcfc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3324ULL;
	}
x86_l_620:
	/* 0x620: cmp    WORD PTR [rbx-0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743936270598144ULL);
x86_l_625:
	/* 0x625: je     d28 <generic_sleepable_preload+0xd28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3368ULL;
	}
x86_l_62b:
	/* 0x62b: mov    ecx,DWORD PTR [rbx-0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551578ULL);
x86_l_62e:
	/* 0x62e: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_632:
	/* 0x632: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_636:
	/* 0x636: cmp    WORD PTR [rbx-0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743927680663552ULL);
x86_l_63b:
	/* 0x63b: je     65d <generic_sleepable_preload+0x65d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_65d;
	}
x86_l_63d:
	/* 0x63d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_642:
	/* 0x642: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_647:
	/* 0x647: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_64a:
	/* 0x64a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_64e:
	/* 0x64e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_653:
	/* 0x653: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_655:
	/* 0x655: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_657:
	/* 0x657: js     d0e <generic_sleepable_preload+0xd0e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3342ULL;
	}
x86_l_65d:
	/* 0x65d: cmp    WORD PTR [rbx-0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743970630336512ULL);
x86_l_662:
	/* 0x662: je     d28 <generic_sleepable_preload+0xd28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3368ULL;
	}
x86_l_668:
	/* 0x668: mov    ecx,DWORD PTR [rbx-0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551586ULL);
x86_l_66b:
	/* 0x66b: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
	return 1647ULL;
}

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1647ULL: goto x86_l_66f;
	case 1651ULL: goto x86_l_673;
	case 1656ULL: goto x86_l_678;
	case 1658ULL: goto x86_l_67a;
	case 1663ULL: goto x86_l_67f;
	case 1668ULL: goto x86_l_684;
	case 1671ULL: goto x86_l_687;
	case 1675ULL: goto x86_l_68b;
	case 1680ULL: goto x86_l_690;
	case 1682ULL: goto x86_l_692;
	case 1684ULL: goto x86_l_694;
	case 1690ULL: goto x86_l_69a;
	case 1695ULL: goto x86_l_69f;
	case 1701ULL: goto x86_l_6a5;
	case 1704ULL: goto x86_l_6a8;
	case 1708ULL: goto x86_l_6ac;
	case 1712ULL: goto x86_l_6b0;
	case 1717ULL: goto x86_l_6b5;
	case 1719ULL: goto x86_l_6b7;
	case 1724ULL: goto x86_l_6bc;
	case 1729ULL: goto x86_l_6c1;
	case 1732ULL: goto x86_l_6c4;
	case 1736ULL: goto x86_l_6c8;
	case 1741ULL: goto x86_l_6cd;
	case 1743ULL: goto x86_l_6cf;
	case 1745ULL: goto x86_l_6d1;
	case 1751ULL: goto x86_l_6d7;
	case 1756ULL: goto x86_l_6dc;
	case 1762ULL: goto x86_l_6e2;
	case 1765ULL: goto x86_l_6e5;
	case 1769ULL: goto x86_l_6e9;
	case 1773ULL: goto x86_l_6ed;
	case 1778ULL: goto x86_l_6f2;
	case 1780ULL: goto x86_l_6f4;
	case 1785ULL: goto x86_l_6f9;
	case 1790ULL: goto x86_l_6fe;
	case 1793ULL: goto x86_l_701;
	case 1797ULL: goto x86_l_705;
	case 1802ULL: goto x86_l_70a;
	case 1804ULL: goto x86_l_70c;
	case 1806ULL: goto x86_l_70e;
	case 1812ULL: goto x86_l_714;
	case 1816ULL: goto x86_l_718;
	case 1822ULL: goto x86_l_71e;
	case 1825ULL: goto x86_l_721;
	case 1829ULL: goto x86_l_725;
	case 1833ULL: goto x86_l_729;
	case 1838ULL: goto x86_l_72e;
	case 1844ULL: goto x86_l_734;
	case 1849ULL: goto x86_l_739;
	case 1854ULL: goto x86_l_73e;
	case 1857ULL: goto x86_l_741;
	case 1861ULL: goto x86_l_745;
	case 1866ULL: goto x86_l_74a;
	case 1868ULL: goto x86_l_74c;
	case 1870ULL: goto x86_l_74e;
	case 1876ULL: goto x86_l_754;
	case 1882ULL: goto x86_l_75a;
	case 1887ULL: goto x86_l_75f;
	case 1893ULL: goto x86_l_765;
	case 1898ULL: goto x86_l_76a;
	case 1906ULL: goto x86_l_772;
	case 1909ULL: goto x86_l_775;
	case 1911ULL: goto x86_l_777;
	case 1916ULL: goto x86_l_77c;
	case 1921ULL: goto x86_l_781;
	case 1924ULL: goto x86_l_784;
	case 1926ULL: goto x86_l_786;
	case 1928ULL: goto x86_l_788;
	case 1933ULL: goto x86_l_78d;
	case 1936ULL: goto x86_l_790;
	case 1938ULL: goto x86_l_792;
	case 1943ULL: goto x86_l_797;
	case 1948ULL: goto x86_l_79c;
	case 1951ULL: goto x86_l_79f;
	case 1953ULL: goto x86_l_7a1;
	case 1955ULL: goto x86_l_7a3;
	case 1963ULL: goto x86_l_7ab;
	case 1966ULL: goto x86_l_7ae;
	case 1968ULL: goto x86_l_7b0;
	case 1973ULL: goto x86_l_7b5;
	case 1978ULL: goto x86_l_7ba;
	case 1981ULL: goto x86_l_7bd;
	case 1983ULL: goto x86_l_7bf;
	case 1985ULL: goto x86_l_7c1;
	case 1990ULL: goto x86_l_7c6;
	case 1993ULL: goto x86_l_7c9;
	case 1995ULL: goto x86_l_7cb;
	case 2000ULL: goto x86_l_7d0;
	case 2005ULL: goto x86_l_7d5;
	case 2008ULL: goto x86_l_7d8;
	case 2010ULL: goto x86_l_7da;
	case 2013ULL: goto x86_l_7dd;
	case 2015ULL: goto x86_l_7df;
	case 2017ULL: goto x86_l_7e1;
	case 2022ULL: goto x86_l_7e6;
	case 2024ULL: goto x86_l_7e8;
	case 2029ULL: goto x86_l_7ed;
	case 2033ULL: goto x86_l_7f1;
	case 2038ULL: goto x86_l_7f6;
	case 2040ULL: goto x86_l_7f8;
	case 2043ULL: goto x86_l_7fb;
	case 2048ULL: goto x86_l_800;
	case 2054ULL: goto x86_l_806;
	case 2061ULL: goto x86_l_80d;
	case 2064ULL: goto x86_l_810;
	case 2067ULL: goto x86_l_813;
	case 2070ULL: goto x86_l_816;
	case 2074ULL: goto x86_l_81a;
	case 2078ULL: goto x86_l_81e;
	case 2080ULL: goto x86_l_820;
	case 2086ULL: goto x86_l_826;
	case 2089ULL: goto x86_l_829;
	case 2091ULL: goto x86_l_82b;
	case 2096ULL: goto x86_l_830;
	case 2101ULL: goto x86_l_835;
	case 2104ULL: goto x86_l_838;
	case 2108ULL: goto x86_l_83c;
	case 2113ULL: goto x86_l_841;
	case 2115ULL: goto x86_l_843;
	case 2117ULL: goto x86_l_845;
	case 2123ULL: goto x86_l_84b;
	case 2128ULL: goto x86_l_850;
	case 2134ULL: goto x86_l_856;
	case 2137ULL: goto x86_l_859;
	case 2141ULL: goto x86_l_85d;
	case 2145ULL: goto x86_l_861;
	case 2150ULL: goto x86_l_866;
	case 2152ULL: goto x86_l_868;
	case 2157ULL: goto x86_l_86d;
	case 2162ULL: goto x86_l_872;
	case 2165ULL: goto x86_l_875;
	case 2169ULL: goto x86_l_879;
	case 2174ULL: goto x86_l_87e;
	case 2176ULL: goto x86_l_880;
	case 2178ULL: goto x86_l_882;
	case 2184ULL: goto x86_l_888;
	case 2189ULL: goto x86_l_88d;
	case 2195ULL: goto x86_l_893;
	case 2198ULL: goto x86_l_896;
	case 2202ULL: goto x86_l_89a;
	case 2206ULL: goto x86_l_89e;
	case 2211ULL: goto x86_l_8a3;
	case 2213ULL: goto x86_l_8a5;
	case 2218ULL: goto x86_l_8aa;
	case 2223ULL: goto x86_l_8af;
	case 2226ULL: goto x86_l_8b2;
	case 2230ULL: goto x86_l_8b6;
	case 2235ULL: goto x86_l_8bb;
	case 2237ULL: goto x86_l_8bd;
	case 2239ULL: goto x86_l_8bf;
	case 2245ULL: goto x86_l_8c5;
	case 2250ULL: goto x86_l_8ca;
	case 2256ULL: goto x86_l_8d0;
	case 2259ULL: goto x86_l_8d3;
	case 2263ULL: goto x86_l_8d7;
	case 2267ULL: goto x86_l_8db;
	case 2272ULL: goto x86_l_8e0;
	case 2274ULL: goto x86_l_8e2;
	case 2279ULL: goto x86_l_8e7;
	case 2284ULL: goto x86_l_8ec;
	case 2287ULL: goto x86_l_8ef;
	case 2291ULL: goto x86_l_8f3;
	case 2296ULL: goto x86_l_8f8;
	case 2298ULL: goto x86_l_8fa;
	case 2300ULL: goto x86_l_8fc;
	case 2306ULL: goto x86_l_902;
	case 2311ULL: goto x86_l_907;
	case 2317ULL: goto x86_l_90d;
	case 2320ULL: goto x86_l_910;
	case 2324ULL: goto x86_l_914;
	case 2328ULL: goto x86_l_918;
	case 2333ULL: goto x86_l_91d;
	case 2335ULL: goto x86_l_91f;
	case 2340ULL: goto x86_l_924;
	case 2345ULL: goto x86_l_929;
	case 2348ULL: goto x86_l_92c;
	case 2352ULL: goto x86_l_930;
	case 2357ULL: goto x86_l_935;
	case 2359ULL: goto x86_l_937;
	case 2361ULL: goto x86_l_939;
	case 2367ULL: goto x86_l_93f;
	case 2372ULL: goto x86_l_944;
	case 2378ULL: goto x86_l_94a;
	case 2381ULL: goto x86_l_94d;
	case 2385ULL: goto x86_l_951;
	case 2389ULL: goto x86_l_955;
	case 2394ULL: goto x86_l_95a;
	case 2396ULL: goto x86_l_95c;
	case 2401ULL: goto x86_l_961;
	case 2406ULL: goto x86_l_966;
	case 2409ULL: goto x86_l_969;
	case 2413ULL: goto x86_l_96d;
	case 2418ULL: goto x86_l_972;
	case 2420ULL: goto x86_l_974;
	case 2422ULL: goto x86_l_976;
	case 2428ULL: goto x86_l_97c;
	case 2433ULL: goto x86_l_981;
	case 2439ULL: goto x86_l_987;
	case 2442ULL: goto x86_l_98a;
	case 2446ULL: goto x86_l_98e;
	case 2450ULL: goto x86_l_992;
	case 2455ULL: goto x86_l_997;
	case 2457ULL: goto x86_l_999;
	case 2462ULL: goto x86_l_99e;
	case 2467ULL: goto x86_l_9a3;
	case 2470ULL: goto x86_l_9a6;
	case 2474ULL: goto x86_l_9aa;
	case 2479ULL: goto x86_l_9af;
	case 2481ULL: goto x86_l_9b1;
	case 2483ULL: goto x86_l_9b3;
	case 2489ULL: goto x86_l_9b9;
	case 2494ULL: goto x86_l_9be;
	case 2500ULL: goto x86_l_9c4;
	case 2503ULL: goto x86_l_9c7;
	case 2507ULL: goto x86_l_9cb;
	case 2511ULL: goto x86_l_9cf;
	case 2516ULL: goto x86_l_9d4;
	case 2518ULL: goto x86_l_9d6;
	case 2523ULL: goto x86_l_9db;
	case 2528ULL: goto x86_l_9e0;
	case 2531ULL: goto x86_l_9e3;
	case 2535ULL: goto x86_l_9e7;
	case 2540ULL: goto x86_l_9ec;
	case 2542ULL: goto x86_l_9ee;
	case 2544ULL: goto x86_l_9f0;
	case 2550ULL: goto x86_l_9f6;
	case 2555ULL: goto x86_l_9fb;
	case 2561ULL: goto x86_l_a01;
	case 2564ULL: goto x86_l_a04;
	case 2568ULL: goto x86_l_a08;
	case 2572ULL: goto x86_l_a0c;
	case 2577ULL: goto x86_l_a11;
	case 2579ULL: goto x86_l_a13;
	case 2584ULL: goto x86_l_a18;
	case 2589ULL: goto x86_l_a1d;
	case 2592ULL: goto x86_l_a20;
	case 2596ULL: goto x86_l_a24;
	case 2601ULL: goto x86_l_a29;
	case 2603ULL: goto x86_l_a2b;
	case 2605ULL: goto x86_l_a2d;
	case 2611ULL: goto x86_l_a33;
	case 2615ULL: goto x86_l_a37;
	case 2621ULL: goto x86_l_a3d;
	case 2624ULL: goto x86_l_a40;
	case 2628ULL: goto x86_l_a44;
	case 2632ULL: goto x86_l_a48;
	case 2637ULL: goto x86_l_a4d;
	case 2643ULL: goto x86_l_a53;
	case 2648ULL: goto x86_l_a58;
	case 2653ULL: goto x86_l_a5d;
	case 2656ULL: goto x86_l_a60;
	case 2661ULL: goto x86_l_a65;
	case 2664ULL: goto x86_l_a68;
	case 2666ULL: goto x86_l_a6a;
	case 2671ULL: goto x86_l_a6f;
	case 2676ULL: goto x86_l_a74;
	case 2679ULL: goto x86_l_a77;
	case 2683ULL: goto x86_l_a7b;
	case 2688ULL: goto x86_l_a80;
	case 2690ULL: goto x86_l_a82;
	case 2692ULL: goto x86_l_a84;
	case 2698ULL: goto x86_l_a8a;
	case 2703ULL: goto x86_l_a8f;
	case 2709ULL: goto x86_l_a95;
	case 2712ULL: goto x86_l_a98;
	case 2716ULL: goto x86_l_a9c;
	case 2720ULL: goto x86_l_aa0;
	case 2725ULL: goto x86_l_aa5;
	case 2727ULL: goto x86_l_aa7;
	case 2732ULL: goto x86_l_aac;
	case 2737ULL: goto x86_l_ab1;
	case 2740ULL: goto x86_l_ab4;
	case 2744ULL: goto x86_l_ab8;
	case 2749ULL: goto x86_l_abd;
	case 2751ULL: goto x86_l_abf;
	case 2753ULL: goto x86_l_ac1;
	case 2759ULL: goto x86_l_ac7;
	case 2764ULL: goto x86_l_acc;
	case 2770ULL: goto x86_l_ad2;
	case 2773ULL: goto x86_l_ad5;
	case 2777ULL: goto x86_l_ad9;
	case 2781ULL: goto x86_l_add;
	case 2786ULL: goto x86_l_ae2;
	case 2788ULL: goto x86_l_ae4;
	case 2793ULL: goto x86_l_ae9;
	case 2798ULL: goto x86_l_aee;
	case 2801ULL: goto x86_l_af1;
	case 2805ULL: goto x86_l_af5;
	case 2810ULL: goto x86_l_afa;
	case 2812ULL: goto x86_l_afc;
	case 2814ULL: goto x86_l_afe;
	case 2820ULL: goto x86_l_b04;
	case 2825ULL: goto x86_l_b09;
	case 2831ULL: goto x86_l_b0f;
	case 2834ULL: goto x86_l_b12;
	case 2838ULL: goto x86_l_b16;
	case 2842ULL: goto x86_l_b1a;
	case 2847ULL: goto x86_l_b1f;
	case 2849ULL: goto x86_l_b21;
	case 2854ULL: goto x86_l_b26;
	case 2859ULL: goto x86_l_b2b;
	case 2862ULL: goto x86_l_b2e;
	case 2866ULL: goto x86_l_b32;
	case 2871ULL: goto x86_l_b37;
	case 2873ULL: goto x86_l_b39;
	case 2875ULL: goto x86_l_b3b;
	case 2881ULL: goto x86_l_b41;
	case 2886ULL: goto x86_l_b46;
	case 2892ULL: goto x86_l_b4c;
	case 2895ULL: goto x86_l_b4f;
	case 2899ULL: goto x86_l_b53;
	case 2903ULL: goto x86_l_b57;
	case 2908ULL: goto x86_l_b5c;
	case 2910ULL: goto x86_l_b5e;
	case 2915ULL: goto x86_l_b63;
	case 2920ULL: goto x86_l_b68;
	case 2923ULL: goto x86_l_b6b;
	case 2927ULL: goto x86_l_b6f;
	case 2932ULL: goto x86_l_b74;
	case 2934ULL: goto x86_l_b76;
	case 2936ULL: goto x86_l_b78;
	case 2942ULL: goto x86_l_b7e;
	case 2947ULL: goto x86_l_b83;
	case 2953ULL: goto x86_l_b89;
	case 2956ULL: goto x86_l_b8c;
	case 2960ULL: goto x86_l_b90;
	case 2964ULL: goto x86_l_b94;
	case 2969ULL: goto x86_l_b99;
	case 2971ULL: goto x86_l_b9b;
	case 2976ULL: goto x86_l_ba0;
	case 2981ULL: goto x86_l_ba5;
	case 2984ULL: goto x86_l_ba8;
	case 2988ULL: goto x86_l_bac;
	case 2993ULL: goto x86_l_bb1;
	case 2995ULL: goto x86_l_bb3;
	case 2997ULL: goto x86_l_bb5;
	case 3003ULL: goto x86_l_bbb;
	case 3008ULL: goto x86_l_bc0;
	case 3014ULL: goto x86_l_bc6;
	case 3017ULL: goto x86_l_bc9;
	case 3021ULL: goto x86_l_bcd;
	case 3025ULL: goto x86_l_bd1;
	case 3030ULL: goto x86_l_bd6;
	case 3032ULL: goto x86_l_bd8;
	case 3037ULL: goto x86_l_bdd;
	case 3042ULL: goto x86_l_be2;
	case 3045ULL: goto x86_l_be5;
	case 3049ULL: goto x86_l_be9;
	case 3054ULL: goto x86_l_bee;
	case 3056ULL: goto x86_l_bf0;
	case 3058ULL: goto x86_l_bf2;
	case 3064ULL: goto x86_l_bf8;
	case 3069ULL: goto x86_l_bfd;
	case 3075ULL: goto x86_l_c03;
	case 3078ULL: goto x86_l_c06;
	case 3082ULL: goto x86_l_c0a;
	case 3086ULL: goto x86_l_c0e;
	case 3091ULL: goto x86_l_c13;
	case 3093ULL: goto x86_l_c15;
	case 3098ULL: goto x86_l_c1a;
	case 3103ULL: goto x86_l_c1f;
	case 3106ULL: goto x86_l_c22;
	case 3110ULL: goto x86_l_c26;
	case 3115ULL: goto x86_l_c2b;
	case 3117ULL: goto x86_l_c2d;
	case 3119ULL: goto x86_l_c2f;
	case 3125ULL: goto x86_l_c35;
	case 3130ULL: goto x86_l_c3a;
	case 3136ULL: goto x86_l_c40;
	case 3139ULL: goto x86_l_c43;
	case 3143ULL: goto x86_l_c47;
	case 3147ULL: goto x86_l_c4b;
	case 3152ULL: goto x86_l_c50;
	case 3154ULL: goto x86_l_c52;
	case 3159ULL: goto x86_l_c57;
	case 3164ULL: goto x86_l_c5c;
	case 3167ULL: goto x86_l_c5f;
	case 3171ULL: goto x86_l_c63;
	case 3176ULL: goto x86_l_c68;
	case 3178ULL: goto x86_l_c6a;
	case 3180ULL: goto x86_l_c6c;
	case 3186ULL: goto x86_l_c72;
	case 3190ULL: goto x86_l_c76;
	default: return 0xffffffffffffffffULL;
	}
x86_l_66f:
	/* 0x66f: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_673:
	/* 0x673: cmp    WORD PTR [rbx-0x1a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743962040401920ULL);
x86_l_678:
	/* 0x678: je     69a <generic_sleepable_preload+0x69a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_69a;
	}
x86_l_67a:
	/* 0x67a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_67f:
	/* 0x67f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_684:
	/* 0x684: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_687:
	/* 0x687: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_68b:
	/* 0x68b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_690:
	/* 0x690: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_692:
	/* 0x692: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_694:
	/* 0x694: js     d20 <generic_sleepable_preload+0xd20> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3360ULL;
	}
x86_l_69a:
	/* 0x69a: cmp    WORD PTR [rbx-0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744004990074880ULL);
x86_l_69f:
	/* 0x69f: je     d28 <generic_sleepable_preload+0xd28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3368ULL;
	}
x86_l_6a5:
	/* 0x6a5: mov    ecx,DWORD PTR [rbx-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_6a8:
	/* 0x6a8: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_6ac:
	/* 0x6ac: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6b0:
	/* 0x6b0: cmp    WORD PTR [rbx-0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743996400140288ULL);
x86_l_6b5:
	/* 0x6b5: je     6d7 <generic_sleepable_preload+0x6d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6d7;
	}
x86_l_6b7:
	/* 0x6b7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_6bc:
	/* 0x6bc: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_6c1:
	/* 0x6c1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_6c4:
	/* 0x6c4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6c8:
	/* 0x6c8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6cd:
	/* 0x6cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6cf:
	/* 0x6cf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_6d1:
	/* 0x6d1: js     ebe <generic_sleepable_preload+0xebe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3774ULL;
	}
x86_l_6d7:
	/* 0x6d7: cmp    WORD PTR [rbx-0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744039349813248ULL);
x86_l_6dc:
	/* 0x6dc: je     d28 <generic_sleepable_preload+0xd28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3368ULL;
	}
x86_l_6e2:
	/* 0x6e2: mov    ecx,DWORD PTR [rbx-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551602ULL);
x86_l_6e5:
	/* 0x6e5: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_6e9:
	/* 0x6e9: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6ed:
	/* 0x6ed: cmp    WORD PTR [rbx-0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744030759878656ULL);
x86_l_6f2:
	/* 0x6f2: je     714 <generic_sleepable_preload+0x714> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_714;
	}
x86_l_6f4:
	/* 0x6f4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_6f9:
	/* 0x6f9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_6fe:
	/* 0x6fe: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_701:
	/* 0x701: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_705:
	/* 0x705: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_70a:
	/* 0x70a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_70c:
	/* 0x70c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_70e:
	/* 0x70e: js     ee2 <generic_sleepable_preload+0xee2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3810ULL;
	}
x86_l_714:
	/* 0x714: cmp    WORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_718:
	/* 0x718: je     d28 <generic_sleepable_preload+0xd28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3368ULL;
	}
x86_l_71e:
	/* 0x71e: mov    ecx,DWORD PTR [rbx-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_721:
	/* 0x721: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_725:
	/* 0x725: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_729:
	/* 0x729: cmp    WORD PTR [rbx-0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744065119617024ULL);
x86_l_72e:
	/* 0x72e: je     d28 <generic_sleepable_preload+0xd28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3368ULL;
	}
x86_l_734:
	/* 0x734: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_739:
	/* 0x739: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_73e:
	/* 0x73e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_741:
	/* 0x741: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_745:
	/* 0x745: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_74a:
	/* 0x74a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_74c:
	/* 0x74c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_74e:
	/* 0x74e: jns    d28 <generic_sleepable_preload+0xd28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 3368ULL;
	}
x86_l_754:
	/* 0x754: mov    r13d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 10ULL);
x86_l_75a:
	/* 0x75a: jmp    d26 <generic_sleepable_preload+0xd26> */
	return 3366ULL;
x86_l_75f:
	/* 0x75f: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_765:
	/* 0x765: jmp    d26 <generic_sleepable_preload+0xd26> */
	return 3366ULL;
x86_l_76a:
	/* 0x76a: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_772:
	/* 0x772: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_775:
	/* 0x775: je     7da <generic_sleepable_preload+0x7da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7da;
	}
x86_l_777:
	/* 0x777: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_77c:
	/* 0x77c: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_781:
	/* 0x781: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_784:
	/* 0x784: je     7da <generic_sleepable_preload+0x7da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7da;
	}
x86_l_786:
	/* 0x786: jmp    7ed <generic_sleepable_preload+0x7ed> */
	goto x86_l_7ed;
x86_l_788:
	/* 0x788: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_78d:
	/* 0x78d: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_790:
	/* 0x790: je     7da <generic_sleepable_preload+0x7da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7da;
	}
x86_l_792:
	/* 0x792: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_797:
	/* 0x797: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_79c:
	/* 0x79c: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_79f:
	/* 0x79f: je     7da <generic_sleepable_preload+0x7da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7da;
	}
x86_l_7a1:
	/* 0x7a1: jmp    7ed <generic_sleepable_preload+0x7ed> */
	goto x86_l_7ed;
x86_l_7a3:
	/* 0x7a3: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_7ab:
	/* 0x7ab: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_7ae:
	/* 0x7ae: je     7da <generic_sleepable_preload+0x7da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7da;
	}
x86_l_7b0:
	/* 0x7b0: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_7b5:
	/* 0x7b5: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_7ba:
	/* 0x7ba: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_7bd:
	/* 0x7bd: je     7da <generic_sleepable_preload+0x7da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7da;
	}
x86_l_7bf:
	/* 0x7bf: jmp    7ed <generic_sleepable_preload+0x7ed> */
	goto x86_l_7ed;
x86_l_7c1:
	/* 0x7c1: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_7c6:
	/* 0x7c6: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_7c9:
	/* 0x7c9: je     7da <generic_sleepable_preload+0x7da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7da;
	}
x86_l_7cb:
	/* 0x7cb: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7d0:
	/* 0x7d0: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_7d5:
	/* 0x7d5: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_7d8:
	/* 0x7d8: jne    7ed <generic_sleepable_preload+0x7ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_7ed;
	}
x86_l_7da:
	/* 0x7da: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_7dd:
	/* 0x7dd: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_7df:
	/* 0x7df: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_7e1:
	/* 0x7e1: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_7e6:
	/* 0x7e6: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_7e8:
	/* 0x7e8: bzhi   rsi,QWORD PTR [rdx],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RSI, X86_RDX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_7ed:
	/* 0x7ed: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7f1:
	/* 0x7f1: mov    r12d,DWORD PTR [r12+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 4ULL);
x86_l_7f6:
	/* 0x7f6: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7f8:
	/* 0x7f8: mov    r15b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_8, 1ULL);
x86_l_7fb:
	/* 0x7fb: cmp    WORD PTR [rbx-0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743764471906304ULL);
x86_l_800:
	/* 0x800: je     e09 <generic_sleepable_preload+0xe09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3593ULL;
	}
x86_l_806:
	/* 0x806: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_80d:
	/* 0x80d: movzx  ecx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_810:
	/* 0x810: mov    eax,DWORD PTR [rbx-0x4e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551538ULL);
x86_l_813:
	/* 0x813: add    rsi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_816:
	/* 0x816: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_81a:
	/* 0x81a: movzx  eax,WORD PTR [rbx-0x4a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551542ULL);
x86_l_81e:
	/* 0x81e: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_820:
	/* 0x820: je     a65 <generic_sleepable_preload+0xa65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a65;
	}
x86_l_826:
	/* 0x826: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_829:
	/* 0x829: je     84b <generic_sleepable_preload+0x84b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_84b;
	}
x86_l_82b:
	/* 0x82b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_830:
	/* 0x830: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_835:
	/* 0x835: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_838:
	/* 0x838: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_83c:
	/* 0x83c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_841:
	/* 0x841: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_843:
	/* 0x843: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_845:
	/* 0x845: js     cbc <generic_sleepable_preload+0xcbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3260ULL;
	}
x86_l_84b:
	/* 0x84b: cmp    WORD PTR [rbx-0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743798831644672ULL);
x86_l_850:
	/* 0x850: je     e09 <generic_sleepable_preload+0xe09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3593ULL;
	}
x86_l_856:
	/* 0x856: mov    ecx,DWORD PTR [rbx-0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551546ULL);
x86_l_859:
	/* 0x859: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_85d:
	/* 0x85d: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_861:
	/* 0x861: cmp    WORD PTR [rbx-0x42],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743790241710080ULL);
x86_l_866:
	/* 0x866: je     888 <generic_sleepable_preload+0x888> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_888;
	}
x86_l_868:
	/* 0x868: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_86d:
	/* 0x86d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_872:
	/* 0x872: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_875:
	/* 0x875: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_879:
	/* 0x879: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_87e:
	/* 0x87e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_880:
	/* 0x880: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_882:
	/* 0x882: js     cce <generic_sleepable_preload+0xcce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3278ULL;
	}
x86_l_888:
	/* 0x888: cmp    WORD PTR [rbx-0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743833191383040ULL);
x86_l_88d:
	/* 0x88d: je     e09 <generic_sleepable_preload+0xe09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3593ULL;
	}
x86_l_893:
	/* 0x893: mov    ecx,DWORD PTR [rbx-0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551554ULL);
x86_l_896:
	/* 0x896: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_89a:
	/* 0x89a: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_89e:
	/* 0x89e: cmp    WORD PTR [rbx-0x3a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743824601448448ULL);
x86_l_8a3:
	/* 0x8a3: je     8c5 <generic_sleepable_preload+0x8c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8c5;
	}
x86_l_8a5:
	/* 0x8a5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_8aa:
	/* 0x8aa: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_8af:
	/* 0x8af: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_8b2:
	/* 0x8b2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8b6:
	/* 0x8b6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8bb:
	/* 0x8bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8bd:
	/* 0x8bd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_8bf:
	/* 0x8bf: js     ce0 <generic_sleepable_preload+0xce0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3296ULL;
	}
x86_l_8c5:
	/* 0x8c5: cmp    WORD PTR [rbx-0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743867551121408ULL);
x86_l_8ca:
	/* 0x8ca: je     e09 <generic_sleepable_preload+0xe09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3593ULL;
	}
x86_l_8d0:
	/* 0x8d0: mov    ecx,DWORD PTR [rbx-0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551562ULL);
x86_l_8d3:
	/* 0x8d3: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_8d7:
	/* 0x8d7: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8db:
	/* 0x8db: cmp    WORD PTR [rbx-0x32],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743858961186816ULL);
x86_l_8e0:
	/* 0x8e0: je     902 <generic_sleepable_preload+0x902> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_902;
	}
x86_l_8e2:
	/* 0x8e2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_8e7:
	/* 0x8e7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_8ec:
	/* 0x8ec: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_8ef:
	/* 0x8ef: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8f3:
	/* 0x8f3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8f8:
	/* 0x8f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8fa:
	/* 0x8fa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_8fc:
	/* 0x8fc: js     cf2 <generic_sleepable_preload+0xcf2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3314ULL;
	}
x86_l_902:
	/* 0x902: cmp    WORD PTR [rbx-0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743901910859776ULL);
x86_l_907:
	/* 0x907: je     e09 <generic_sleepable_preload+0xe09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3593ULL;
	}
x86_l_90d:
	/* 0x90d: mov    ecx,DWORD PTR [rbx-0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551570ULL);
x86_l_910:
	/* 0x910: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_914:
	/* 0x914: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_918:
	/* 0x918: cmp    WORD PTR [rbx-0x2a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743893320925184ULL);
x86_l_91d:
	/* 0x91d: je     93f <generic_sleepable_preload+0x93f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_93f;
	}
x86_l_91f:
	/* 0x91f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_924:
	/* 0x924: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_929:
	/* 0x929: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_92c:
	/* 0x92c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_930:
	/* 0x930: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_935:
	/* 0x935: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_937:
	/* 0x937: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_939:
	/* 0x939: js     d04 <generic_sleepable_preload+0xd04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3332ULL;
	}
x86_l_93f:
	/* 0x93f: cmp    WORD PTR [rbx-0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743936270598144ULL);
x86_l_944:
	/* 0x944: je     e09 <generic_sleepable_preload+0xe09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3593ULL;
	}
x86_l_94a:
	/* 0x94a: mov    ecx,DWORD PTR [rbx-0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551578ULL);
x86_l_94d:
	/* 0x94d: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_951:
	/* 0x951: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_955:
	/* 0x955: cmp    WORD PTR [rbx-0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743927680663552ULL);
x86_l_95a:
	/* 0x95a: je     97c <generic_sleepable_preload+0x97c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_97c;
	}
x86_l_95c:
	/* 0x95c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_961:
	/* 0x961: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_966:
	/* 0x966: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_969:
	/* 0x969: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_96d:
	/* 0x96d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_972:
	/* 0x972: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_974:
	/* 0x974: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_976:
	/* 0x976: js     d16 <generic_sleepable_preload+0xd16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3350ULL;
	}
x86_l_97c:
	/* 0x97c: cmp    WORD PTR [rbx-0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743970630336512ULL);
x86_l_981:
	/* 0x981: je     e09 <generic_sleepable_preload+0xe09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3593ULL;
	}
x86_l_987:
	/* 0x987: mov    ecx,DWORD PTR [rbx-0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551586ULL);
x86_l_98a:
	/* 0x98a: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_98e:
	/* 0x98e: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_992:
	/* 0x992: cmp    WORD PTR [rbx-0x1a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743962040401920ULL);
x86_l_997:
	/* 0x997: je     9b9 <generic_sleepable_preload+0x9b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9b9;
	}
x86_l_999:
	/* 0x999: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_99e:
	/* 0x99e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_9a3:
	/* 0x9a3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_9a6:
	/* 0x9a6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9aa:
	/* 0x9aa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9af:
	/* 0x9af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9b1:
	/* 0x9b1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_9b3:
	/* 0x9b3: js     e01 <generic_sleepable_preload+0xe01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3585ULL;
	}
x86_l_9b9:
	/* 0x9b9: cmp    WORD PTR [rbx-0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744004990074880ULL);
x86_l_9be:
	/* 0x9be: je     e09 <generic_sleepable_preload+0xe09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3593ULL;
	}
x86_l_9c4:
	/* 0x9c4: mov    ecx,DWORD PTR [rbx-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_9c7:
	/* 0x9c7: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_9cb:
	/* 0x9cb: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9cf:
	/* 0x9cf: cmp    WORD PTR [rbx-0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743996400140288ULL);
x86_l_9d4:
	/* 0x9d4: je     9f6 <generic_sleepable_preload+0x9f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9f6;
	}
x86_l_9d6:
	/* 0x9d6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_9db:
	/* 0x9db: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_9e0:
	/* 0x9e0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_9e3:
	/* 0x9e3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9e7:
	/* 0x9e7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9ec:
	/* 0x9ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9ee:
	/* 0x9ee: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_9f0:
	/* 0x9f0: js     ecb <generic_sleepable_preload+0xecb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3787ULL;
	}
x86_l_9f6:
	/* 0x9f6: cmp    WORD PTR [rbx-0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744039349813248ULL);
x86_l_9fb:
	/* 0x9fb: je     e09 <generic_sleepable_preload+0xe09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3593ULL;
	}
x86_l_a01:
	/* 0xa01: mov    ecx,DWORD PTR [rbx-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551602ULL);
x86_l_a04:
	/* 0xa04: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_a08:
	/* 0xa08: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a0c:
	/* 0xa0c: cmp    WORD PTR [rbx-0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744030759878656ULL);
x86_l_a11:
	/* 0xa11: je     a33 <generic_sleepable_preload+0xa33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a33;
	}
x86_l_a13:
	/* 0xa13: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_a18:
	/* 0xa18: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_a1d:
	/* 0xa1d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_a20:
	/* 0xa20: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a24:
	/* 0xa24: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a29:
	/* 0xa29: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a2b:
	/* 0xa2b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a2d:
	/* 0xa2d: js     eed <generic_sleepable_preload+0xeed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3821ULL;
	}
x86_l_a33:
	/* 0xa33: cmp    WORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a37:
	/* 0xa37: je     e09 <generic_sleepable_preload+0xe09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3593ULL;
	}
x86_l_a3d:
	/* 0xa3d: mov    ecx,DWORD PTR [rbx-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_a40:
	/* 0xa40: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_a44:
	/* 0xa44: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a48:
	/* 0xa48: cmp    WORD PTR [rbx-0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744065119617024ULL);
x86_l_a4d:
	/* 0xa4d: je     e09 <generic_sleepable_preload+0xe09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3593ULL;
	}
x86_l_a53:
	/* 0xa53: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_a58:
	/* 0xa58: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_a5d:
	/* 0xa5d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_a60:
	/* 0xa60: jmp    c9f <generic_sleepable_preload+0xc9f> */
	return 3231ULL;
x86_l_a65:
	/* 0xa65: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_a68:
	/* 0xa68: je     a8a <generic_sleepable_preload+0xa8a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a8a;
	}
x86_l_a6a:
	/* 0xa6a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_a6f:
	/* 0xa6f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a74:
	/* 0xa74: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_a77:
	/* 0xa77: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a7b:
	/* 0xa7b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a80:
	/* 0xa80: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a82:
	/* 0xa82: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a84:
	/* 0xa84: js     cbc <generic_sleepable_preload+0xcbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3260ULL;
	}
x86_l_a8a:
	/* 0xa8a: cmp    WORD PTR [rbx-0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743798831644672ULL);
x86_l_a8f:
	/* 0xa8f: je     e09 <generic_sleepable_preload+0xe09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3593ULL;
	}
x86_l_a95:
	/* 0xa95: mov    ecx,DWORD PTR [rbx-0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551546ULL);
x86_l_a98:
	/* 0xa98: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_a9c:
	/* 0xa9c: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_aa0:
	/* 0xaa0: cmp    WORD PTR [rbx-0x42],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743790241710080ULL);
x86_l_aa5:
	/* 0xaa5: je     ac7 <generic_sleepable_preload+0xac7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ac7;
	}
x86_l_aa7:
	/* 0xaa7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_aac:
	/* 0xaac: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_ab1:
	/* 0xab1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_ab4:
	/* 0xab4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ab8:
	/* 0xab8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_abd:
	/* 0xabd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_abf:
	/* 0xabf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ac1:
	/* 0xac1: js     cce <generic_sleepable_preload+0xcce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3278ULL;
	}
x86_l_ac7:
	/* 0xac7: cmp    WORD PTR [rbx-0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743833191383040ULL);
x86_l_acc:
	/* 0xacc: je     e09 <generic_sleepable_preload+0xe09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3593ULL;
	}
x86_l_ad2:
	/* 0xad2: mov    ecx,DWORD PTR [rbx-0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551554ULL);
x86_l_ad5:
	/* 0xad5: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_ad9:
	/* 0xad9: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_add:
	/* 0xadd: cmp    WORD PTR [rbx-0x3a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743824601448448ULL);
x86_l_ae2:
	/* 0xae2: je     b04 <generic_sleepable_preload+0xb04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b04;
	}
x86_l_ae4:
	/* 0xae4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_ae9:
	/* 0xae9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_aee:
	/* 0xaee: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_af1:
	/* 0xaf1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_af5:
	/* 0xaf5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_afa:
	/* 0xafa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_afc:
	/* 0xafc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_afe:
	/* 0xafe: js     ce0 <generic_sleepable_preload+0xce0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3296ULL;
	}
x86_l_b04:
	/* 0xb04: cmp    WORD PTR [rbx-0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743867551121408ULL);
x86_l_b09:
	/* 0xb09: je     e09 <generic_sleepable_preload+0xe09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3593ULL;
	}
x86_l_b0f:
	/* 0xb0f: mov    ecx,DWORD PTR [rbx-0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551562ULL);
x86_l_b12:
	/* 0xb12: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_b16:
	/* 0xb16: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b1a:
	/* 0xb1a: cmp    WORD PTR [rbx-0x32],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743858961186816ULL);
x86_l_b1f:
	/* 0xb1f: je     b41 <generic_sleepable_preload+0xb41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b41;
	}
x86_l_b21:
	/* 0xb21: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_b26:
	/* 0xb26: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_b2b:
	/* 0xb2b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_b2e:
	/* 0xb2e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b32:
	/* 0xb32: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b37:
	/* 0xb37: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b39:
	/* 0xb39: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b3b:
	/* 0xb3b: js     cf2 <generic_sleepable_preload+0xcf2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3314ULL;
	}
x86_l_b41:
	/* 0xb41: cmp    WORD PTR [rbx-0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743901910859776ULL);
x86_l_b46:
	/* 0xb46: je     e09 <generic_sleepable_preload+0xe09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3593ULL;
	}
x86_l_b4c:
	/* 0xb4c: mov    ecx,DWORD PTR [rbx-0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551570ULL);
x86_l_b4f:
	/* 0xb4f: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_b53:
	/* 0xb53: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b57:
	/* 0xb57: cmp    WORD PTR [rbx-0x2a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743893320925184ULL);
x86_l_b5c:
	/* 0xb5c: je     b7e <generic_sleepable_preload+0xb7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b7e;
	}
x86_l_b5e:
	/* 0xb5e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_b63:
	/* 0xb63: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_b68:
	/* 0xb68: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_b6b:
	/* 0xb6b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b6f:
	/* 0xb6f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b74:
	/* 0xb74: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b76:
	/* 0xb76: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b78:
	/* 0xb78: js     d04 <generic_sleepable_preload+0xd04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3332ULL;
	}
x86_l_b7e:
	/* 0xb7e: cmp    WORD PTR [rbx-0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743936270598144ULL);
x86_l_b83:
	/* 0xb83: je     e09 <generic_sleepable_preload+0xe09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3593ULL;
	}
x86_l_b89:
	/* 0xb89: mov    ecx,DWORD PTR [rbx-0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551578ULL);
x86_l_b8c:
	/* 0xb8c: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_b90:
	/* 0xb90: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b94:
	/* 0xb94: cmp    WORD PTR [rbx-0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743927680663552ULL);
x86_l_b99:
	/* 0xb99: je     bbb <generic_sleepable_preload+0xbbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bbb;
	}
x86_l_b9b:
	/* 0xb9b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_ba0:
	/* 0xba0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_ba5:
	/* 0xba5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_ba8:
	/* 0xba8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bac:
	/* 0xbac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bb1:
	/* 0xbb1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bb3:
	/* 0xbb3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_bb5:
	/* 0xbb5: js     d16 <generic_sleepable_preload+0xd16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3350ULL;
	}
x86_l_bbb:
	/* 0xbbb: cmp    WORD PTR [rbx-0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743970630336512ULL);
x86_l_bc0:
	/* 0xbc0: je     e09 <generic_sleepable_preload+0xe09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3593ULL;
	}
x86_l_bc6:
	/* 0xbc6: mov    ecx,DWORD PTR [rbx-0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551586ULL);
x86_l_bc9:
	/* 0xbc9: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_bcd:
	/* 0xbcd: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bd1:
	/* 0xbd1: cmp    WORD PTR [rbx-0x1a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743962040401920ULL);
x86_l_bd6:
	/* 0xbd6: je     bf8 <generic_sleepable_preload+0xbf8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bf8;
	}
x86_l_bd8:
	/* 0xbd8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_bdd:
	/* 0xbdd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_be2:
	/* 0xbe2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_be5:
	/* 0xbe5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_be9:
	/* 0xbe9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bee:
	/* 0xbee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bf0:
	/* 0xbf0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_bf2:
	/* 0xbf2: js     e01 <generic_sleepable_preload+0xe01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3585ULL;
	}
x86_l_bf8:
	/* 0xbf8: cmp    WORD PTR [rbx-0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744004990074880ULL);
x86_l_bfd:
	/* 0xbfd: je     e09 <generic_sleepable_preload+0xe09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3593ULL;
	}
x86_l_c03:
	/* 0xc03: mov    ecx,DWORD PTR [rbx-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_c06:
	/* 0xc06: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_c0a:
	/* 0xc0a: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c0e:
	/* 0xc0e: cmp    WORD PTR [rbx-0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743996400140288ULL);
x86_l_c13:
	/* 0xc13: je     c35 <generic_sleepable_preload+0xc35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c35;
	}
x86_l_c15:
	/* 0xc15: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_c1a:
	/* 0xc1a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_c1f:
	/* 0xc1f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_c22:
	/* 0xc22: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c26:
	/* 0xc26: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c2b:
	/* 0xc2b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c2d:
	/* 0xc2d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c2f:
	/* 0xc2f: js     ecb <generic_sleepable_preload+0xecb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3787ULL;
	}
x86_l_c35:
	/* 0xc35: cmp    WORD PTR [rbx-0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744039349813248ULL);
x86_l_c3a:
	/* 0xc3a: je     e09 <generic_sleepable_preload+0xe09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3593ULL;
	}
x86_l_c40:
	/* 0xc40: mov    ecx,DWORD PTR [rbx-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551602ULL);
x86_l_c43:
	/* 0xc43: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_c47:
	/* 0xc47: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c4b:
	/* 0xc4b: cmp    WORD PTR [rbx-0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744030759878656ULL);
x86_l_c50:
	/* 0xc50: je     c72 <generic_sleepable_preload+0xc72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c72;
	}
x86_l_c52:
	/* 0xc52: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_c57:
	/* 0xc57: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_c5c:
	/* 0xc5c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_c5f:
	/* 0xc5f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c63:
	/* 0xc63: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c68:
	/* 0xc68: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c6a:
	/* 0xc6a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c6c:
	/* 0xc6c: js     eed <generic_sleepable_preload+0xeed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3821ULL;
	}
x86_l_c72:
	/* 0xc72: cmp    WORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c76:
	/* 0xc76: je     e09 <generic_sleepable_preload+0xe09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3593ULL;
	}
	return 3196ULL;
}

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3196ULL: goto x86_l_c7c;
	case 3199ULL: goto x86_l_c7f;
	case 3203ULL: goto x86_l_c83;
	case 3207ULL: goto x86_l_c87;
	case 3212ULL: goto x86_l_c8c;
	case 3218ULL: goto x86_l_c92;
	case 3223ULL: goto x86_l_c97;
	case 3228ULL: goto x86_l_c9c;
	case 3231ULL: goto x86_l_c9f;
	case 3235ULL: goto x86_l_ca3;
	case 3240ULL: goto x86_l_ca8;
	case 3242ULL: goto x86_l_caa;
	case 3244ULL: goto x86_l_cac;
	case 3250ULL: goto x86_l_cb2;
	case 3255ULL: goto x86_l_cb7;
	case 3260ULL: goto x86_l_cbc;
	case 3265ULL: goto x86_l_cc1;
	case 3270ULL: goto x86_l_cc6;
	case 3276ULL: goto x86_l_ccc;
	case 3278ULL: goto x86_l_cce;
	case 3283ULL: goto x86_l_cd3;
	case 3288ULL: goto x86_l_cd8;
	case 3294ULL: goto x86_l_cde;
	case 3296ULL: goto x86_l_ce0;
	case 3301ULL: goto x86_l_ce5;
	case 3306ULL: goto x86_l_cea;
	case 3312ULL: goto x86_l_cf0;
	case 3314ULL: goto x86_l_cf2;
	case 3319ULL: goto x86_l_cf7;
	case 3324ULL: goto x86_l_cfc;
	case 3330ULL: goto x86_l_d02;
	case 3332ULL: goto x86_l_d04;
	case 3337ULL: goto x86_l_d09;
	case 3342ULL: goto x86_l_d0e;
	case 3348ULL: goto x86_l_d14;
	case 3350ULL: goto x86_l_d16;
	case 3355ULL: goto x86_l_d1b;
	case 3360ULL: goto x86_l_d20;
	case 3366ULL: goto x86_l_d26;
	case 3368ULL: goto x86_l_d28;
	case 3373ULL: goto x86_l_d2d;
	case 3378ULL: goto x86_l_d32;
	case 3383ULL: goto x86_l_d37;
	case 3386ULL: goto x86_l_d3a;
	case 3391ULL: goto x86_l_d3f;
	case 3394ULL: goto x86_l_d42;
	case 3396ULL: goto x86_l_d44;
	case 3400ULL: goto x86_l_d48;
	case 3406ULL: goto x86_l_d4e;
	case 3410ULL: goto x86_l_d52;
	case 3418ULL: goto x86_l_d5a;
	case 3423ULL: goto x86_l_d5f;
	case 3425ULL: goto x86_l_d61;
	case 3430ULL: goto x86_l_d66;
	case 3438ULL: goto x86_l_d6e;
	case 3443ULL: goto x86_l_d73;
	case 3450ULL: goto x86_l_d7a;
	case 3455ULL: goto x86_l_d7f;
	case 3457ULL: goto x86_l_d81;
	case 3460ULL: goto x86_l_d84;
	case 3466ULL: goto x86_l_d8a;
	case 3469ULL: goto x86_l_d8d;
	case 3474ULL: goto x86_l_d92;
	case 3476ULL: goto x86_l_d94;
	case 3483ULL: goto x86_l_d9b;
	case 3486ULL: goto x86_l_d9e;
	case 3489ULL: goto x86_l_da1;
	case 3494ULL: goto x86_l_da6;
	case 3497ULL: goto x86_l_da9;
	case 3500ULL: goto x86_l_dac;
	case 3502ULL: goto x86_l_dae;
	case 3504ULL: goto x86_l_db0;
	case 3509ULL: goto x86_l_db5;
	case 3512ULL: goto x86_l_db8;
	case 3515ULL: goto x86_l_dbb;
	case 3517ULL: goto x86_l_dbd;
	case 3520ULL: goto x86_l_dc0;
	case 3526ULL: goto x86_l_dc6;
	case 3529ULL: goto x86_l_dc9;
	case 3535ULL: goto x86_l_dcf;
	case 3539ULL: goto x86_l_dd3;
	case 3544ULL: goto x86_l_dd8;
	case 3552ULL: goto x86_l_de0;
	case 3554ULL: goto x86_l_de2;
	case 3557ULL: goto x86_l_de5;
	case 3562ULL: goto x86_l_dea;
	case 3564ULL: goto x86_l_dec;
	case 3567ULL: goto x86_l_def;
	case 3569ULL: goto x86_l_df1;
	case 3575ULL: goto x86_l_df7;
	case 3580ULL: goto x86_l_dfc;
	case 3585ULL: goto x86_l_e01;
	case 3590ULL: goto x86_l_e06;
	case 3593ULL: goto x86_l_e09;
	case 3597ULL: goto x86_l_e0d;
	case 3603ULL: goto x86_l_e13;
	case 3607ULL: goto x86_l_e17;
	case 3615ULL: goto x86_l_e1f;
	case 3620ULL: goto x86_l_e24;
	case 3622ULL: goto x86_l_e26;
	case 3627ULL: goto x86_l_e2b;
	case 3635ULL: goto x86_l_e33;
	case 3640ULL: goto x86_l_e38;
	case 3647ULL: goto x86_l_e3f;
	case 3652ULL: goto x86_l_e44;
	case 3654ULL: goto x86_l_e46;
	case 3657ULL: goto x86_l_e49;
	case 3663ULL: goto x86_l_e4f;
	case 3666ULL: goto x86_l_e52;
	case 3671ULL: goto x86_l_e57;
	case 3673ULL: goto x86_l_e59;
	case 3680ULL: goto x86_l_e60;
	case 3683ULL: goto x86_l_e63;
	case 3686ULL: goto x86_l_e66;
	case 3691ULL: goto x86_l_e6b;
	case 3694ULL: goto x86_l_e6e;
	case 3697ULL: goto x86_l_e71;
	case 3699ULL: goto x86_l_e73;
	case 3701ULL: goto x86_l_e75;
	case 3706ULL: goto x86_l_e7a;
	case 3709ULL: goto x86_l_e7d;
	case 3712ULL: goto x86_l_e80;
	case 3714ULL: goto x86_l_e82;
	case 3717ULL: goto x86_l_e85;
	case 3723ULL: goto x86_l_e8b;
	case 3726ULL: goto x86_l_e8e;
	case 3729ULL: goto x86_l_e91;
	case 3731ULL: goto x86_l_e93;
	case 3735ULL: goto x86_l_e97;
	case 3740ULL: goto x86_l_e9c;
	case 3748ULL: goto x86_l_ea4;
	case 3750ULL: goto x86_l_ea6;
	case 3755ULL: goto x86_l_eab;
	case 3757ULL: goto x86_l_ead;
	case 3759ULL: goto x86_l_eaf;
	case 3765ULL: goto x86_l_eb5;
	case 3769ULL: goto x86_l_eb9;
	case 3774ULL: goto x86_l_ebe;
	case 3776ULL: goto x86_l_ec0;
	case 3782ULL: goto x86_l_ec6;
	case 3787ULL: goto x86_l_ecb;
	case 3790ULL: goto x86_l_ece;
	case 3795ULL: goto x86_l_ed3;
	case 3799ULL: goto x86_l_ed7;
	case 3805ULL: goto x86_l_edd;
	case 3810ULL: goto x86_l_ee2;
	case 3816ULL: goto x86_l_ee8;
	case 3821ULL: goto x86_l_eed;
	case 3826ULL: goto x86_l_ef2;
	case 3831ULL: goto x86_l_ef7;
	case 3836ULL: goto x86_l_efc;
	case 3841ULL: goto x86_l_f01;
	case 3847ULL: goto x86_l_f07;
	case 3849ULL: goto x86_l_f09;
	case 3851ULL: goto x86_l_f0b;
	case 3856ULL: goto x86_l_f10;
	case 3859ULL: goto x86_l_f13;
	case 3865ULL: goto x86_l_f19;
	case 3868ULL: goto x86_l_f1c;
	case 3874ULL: goto x86_l_f22;
	case 3877ULL: goto x86_l_f25;
	case 3883ULL: goto x86_l_f2b;
	case 3886ULL: goto x86_l_f2e;
	case 3892ULL: goto x86_l_f34;
	case 3897ULL: goto x86_l_f39;
	case 3902ULL: goto x86_l_f3e;
	case 3911ULL: goto x86_l_f47;
	case 3920ULL: goto x86_l_f50;
	case 3926ULL: goto x86_l_f56;
	case 3928ULL: goto x86_l_f58;
	case 3931ULL: goto x86_l_f5b;
	case 3933ULL: goto x86_l_f5d;
	case 3936ULL: goto x86_l_f60;
	case 3938ULL: goto x86_l_f62;
	case 3941ULL: goto x86_l_f65;
	case 3947ULL: goto x86_l_f6b;
	case 3952ULL: goto x86_l_f70;
	case 3955ULL: goto x86_l_f73;
	case 3961ULL: goto x86_l_f79;
	case 3966ULL: goto x86_l_f7e;
	case 3969ULL: goto x86_l_f81;
	case 3975ULL: goto x86_l_f87;
	case 3978ULL: goto x86_l_f8a;
	case 3984ULL: goto x86_l_f90;
	case 3989ULL: goto x86_l_f95;
	case 3994ULL: goto x86_l_f9a;
	case 3997ULL: goto x86_l_f9d;
	case 3999ULL: goto x86_l_f9f;
	case 4002ULL: goto x86_l_fa2;
	case 4008ULL: goto x86_l_fa8;
	case 4013ULL: goto x86_l_fad;
	case 4015ULL: goto x86_l_faf;
	case 4021ULL: goto x86_l_fb5;
	case 4024ULL: goto x86_l_fb8;
	case 4027ULL: goto x86_l_fbb;
	case 4033ULL: goto x86_l_fc1;
	case 4038ULL: goto x86_l_fc6;
	case 4040ULL: goto x86_l_fc8;
	case 4042ULL: goto x86_l_fca;
	case 4045ULL: goto x86_l_fcd;
	case 4047ULL: goto x86_l_fcf;
	case 4052ULL: goto x86_l_fd4;
	case 4054ULL: goto x86_l_fd6;
	case 4057ULL: goto x86_l_fd9;
	case 4063ULL: goto x86_l_fdf;
	case 4071ULL: goto x86_l_fe7;
	case 4074ULL: goto x86_l_fea;
	case 4080ULL: goto x86_l_ff0;
	case 4085ULL: goto x86_l_ff5;
	case 4088ULL: goto x86_l_ff8;
	case 4094ULL: goto x86_l_ffe;
	case 4099ULL: goto x86_l_1003;
	case 4102ULL: goto x86_l_1006;
	case 4108ULL: goto x86_l_100c;
	case 4116ULL: goto x86_l_1014;
	case 4119ULL: goto x86_l_1017;
	case 4125ULL: goto x86_l_101d;
	case 4130ULL: goto x86_l_1022;
	case 4133ULL: goto x86_l_1025;
	case 4139ULL: goto x86_l_102b;
	case 4144ULL: goto x86_l_1030;
	case 4149ULL: goto x86_l_1035;
	case 4151ULL: goto x86_l_1037;
	case 4156ULL: goto x86_l_103c;
	case 4158ULL: goto x86_l_103e;
	case 4163ULL: goto x86_l_1043;
	case 4166ULL: goto x86_l_1046;
	case 4170ULL: goto x86_l_104a;
	case 4172ULL: goto x86_l_104c;
	case 4175ULL: goto x86_l_104f;
	case 4182ULL: goto x86_l_1056;
	case 4188ULL: goto x86_l_105c;
	case 4195ULL: goto x86_l_1063;
	case 4198ULL: goto x86_l_1066;
	case 4203ULL: goto x86_l_106b;
	case 4206ULL: goto x86_l_106e;
	case 4210ULL: goto x86_l_1072;
	case 4216ULL: goto x86_l_1078;
	case 4218ULL: goto x86_l_107a;
	case 4224ULL: goto x86_l_1080;
	case 4227ULL: goto x86_l_1083;
	case 4229ULL: goto x86_l_1085;
	case 4232ULL: goto x86_l_1088;
	case 4237ULL: goto x86_l_108d;
	case 4242ULL: goto x86_l_1092;
	case 4246ULL: goto x86_l_1096;
	case 4251ULL: goto x86_l_109b;
	case 4253ULL: goto x86_l_109d;
	case 4255ULL: goto x86_l_109f;
	case 4261ULL: goto x86_l_10a5;
	case 4268ULL: goto x86_l_10ac;
	case 4274ULL: goto x86_l_10b2;
	case 4279ULL: goto x86_l_10b7;
	case 4283ULL: goto x86_l_10bb;
	case 4287ULL: goto x86_l_10bf;
	case 4294ULL: goto x86_l_10c6;
	case 4296ULL: goto x86_l_10c8;
	case 4299ULL: goto x86_l_10cb;
	case 4304ULL: goto x86_l_10d0;
	case 4309ULL: goto x86_l_10d5;
	case 4313ULL: goto x86_l_10d9;
	case 4318ULL: goto x86_l_10de;
	case 4320ULL: goto x86_l_10e0;
	case 4322ULL: goto x86_l_10e2;
	case 4328ULL: goto x86_l_10e8;
	case 4338ULL: goto x86_l_10f2;
	case 4344ULL: goto x86_l_10f8;
	case 4352ULL: goto x86_l_1100;
	case 4356ULL: goto x86_l_1104;
	case 4360ULL: goto x86_l_1108;
	case 4370ULL: goto x86_l_1112;
	case 4372ULL: goto x86_l_1114;
	case 4375ULL: goto x86_l_1117;
	case 4380ULL: goto x86_l_111c;
	case 4385ULL: goto x86_l_1121;
	case 4389ULL: goto x86_l_1125;
	case 4394ULL: goto x86_l_112a;
	case 4396ULL: goto x86_l_112c;
	case 4398ULL: goto x86_l_112e;
	case 4404ULL: goto x86_l_1134;
	case 4414ULL: goto x86_l_113e;
	case 4420ULL: goto x86_l_1144;
	case 4428ULL: goto x86_l_114c;
	case 4432ULL: goto x86_l_1150;
	case 4436ULL: goto x86_l_1154;
	case 4446ULL: goto x86_l_115e;
	case 4448ULL: goto x86_l_1160;
	case 4451ULL: goto x86_l_1163;
	case 4456ULL: goto x86_l_1168;
	case 4461ULL: goto x86_l_116d;
	case 4465ULL: goto x86_l_1171;
	case 4470ULL: goto x86_l_1176;
	case 4472ULL: goto x86_l_1178;
	case 4474ULL: goto x86_l_117a;
	case 4480ULL: goto x86_l_1180;
	case 4490ULL: goto x86_l_118a;
	case 4496ULL: goto x86_l_1190;
	case 4504ULL: goto x86_l_1198;
	case 4508ULL: goto x86_l_119c;
	case 4512ULL: goto x86_l_11a0;
	case 4522ULL: goto x86_l_11aa;
	case 4524ULL: goto x86_l_11ac;
	case 4527ULL: goto x86_l_11af;
	case 4532ULL: goto x86_l_11b4;
	case 4537ULL: goto x86_l_11b9;
	case 4541ULL: goto x86_l_11bd;
	case 4546ULL: goto x86_l_11c2;
	case 4548ULL: goto x86_l_11c4;
	case 4550ULL: goto x86_l_11c6;
	case 4556ULL: goto x86_l_11cc;
	case 4566ULL: goto x86_l_11d6;
	case 4572ULL: goto x86_l_11dc;
	case 4580ULL: goto x86_l_11e4;
	case 4584ULL: goto x86_l_11e8;
	case 4588ULL: goto x86_l_11ec;
	case 4598ULL: goto x86_l_11f6;
	case 4600ULL: goto x86_l_11f8;
	case 4603ULL: goto x86_l_11fb;
	case 4608ULL: goto x86_l_1200;
	case 4613ULL: goto x86_l_1205;
	case 4617ULL: goto x86_l_1209;
	case 4622ULL: goto x86_l_120e;
	case 4624ULL: goto x86_l_1210;
	case 4626ULL: goto x86_l_1212;
	case 4632ULL: goto x86_l_1218;
	case 4642ULL: goto x86_l_1222;
	case 4648ULL: goto x86_l_1228;
	case 4656ULL: goto x86_l_1230;
	case 4660ULL: goto x86_l_1234;
	case 4664ULL: goto x86_l_1238;
	case 4674ULL: goto x86_l_1242;
	case 4676ULL: goto x86_l_1244;
	case 4679ULL: goto x86_l_1247;
	case 4684ULL: goto x86_l_124c;
	case 4689ULL: goto x86_l_1251;
	case 4693ULL: goto x86_l_1255;
	case 4698ULL: goto x86_l_125a;
	case 4700ULL: goto x86_l_125c;
	case 4702ULL: goto x86_l_125e;
	case 4708ULL: goto x86_l_1264;
	case 4718ULL: goto x86_l_126e;
	case 4724ULL: goto x86_l_1274;
	case 4732ULL: goto x86_l_127c;
	case 4736ULL: goto x86_l_1280;
	case 4740ULL: goto x86_l_1284;
	case 4750ULL: goto x86_l_128e;
	case 4752ULL: goto x86_l_1290;
	case 4755ULL: goto x86_l_1293;
	case 4760ULL: goto x86_l_1298;
	case 4765ULL: goto x86_l_129d;
	case 4769ULL: goto x86_l_12a1;
	case 4774ULL: goto x86_l_12a6;
	case 4776ULL: goto x86_l_12a8;
	case 4778ULL: goto x86_l_12aa;
	case 4784ULL: goto x86_l_12b0;
	case 4794ULL: goto x86_l_12ba;
	case 4800ULL: goto x86_l_12c0;
	case 4808ULL: goto x86_l_12c8;
	case 4812ULL: goto x86_l_12cc;
	case 4816ULL: goto x86_l_12d0;
	case 4826ULL: goto x86_l_12da;
	case 4828ULL: goto x86_l_12dc;
	case 4831ULL: goto x86_l_12df;
	case 4836ULL: goto x86_l_12e4;
	case 4841ULL: goto x86_l_12e9;
	case 4845ULL: goto x86_l_12ed;
	case 4850ULL: goto x86_l_12f2;
	case 4852ULL: goto x86_l_12f4;
	case 4854ULL: goto x86_l_12f6;
	case 4860ULL: goto x86_l_12fc;
	case 4865ULL: goto x86_l_1301;
	case 4875ULL: goto x86_l_130b;
	case 4881ULL: goto x86_l_1311;
	case 4889ULL: goto x86_l_1319;
	case 4893ULL: goto x86_l_131d;
	case 4897ULL: goto x86_l_1321;
	case 4907ULL: goto x86_l_132b;
	case 4913ULL: goto x86_l_1331;
	case 4916ULL: goto x86_l_1334;
	case 4921ULL: goto x86_l_1339;
	case 4926ULL: goto x86_l_133e;
	case 4931ULL: goto x86_l_1343;
	case 4934ULL: goto x86_l_1346;
	case 4936ULL: goto x86_l_1348;
	default: return 0xffffffffffffffffULL;
	}
x86_l_c7c:
	/* 0xc7c: mov    ecx,DWORD PTR [rbx-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_c7f:
	/* 0xc7f: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_c83:
	/* 0xc83: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c87:
	/* 0xc87: cmp    WORD PTR [rbx-0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744065119617024ULL);
x86_l_c8c:
	/* 0xc8c: je     e09 <generic_sleepable_preload+0xe09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e09;
	}
x86_l_c92:
	/* 0xc92: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_c97:
	/* 0xc97: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_c9c:
	/* 0xc9c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_c9f:
	/* 0xc9f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ca3:
	/* 0xca3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ca8:
	/* 0xca8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_caa:
	/* 0xcaa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_cac:
	/* 0xcac: jns    e09 <generic_sleepable_preload+0xe09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_e09;
	}
x86_l_cb2:
	/* 0xcb2: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_cb7:
	/* 0xcb7: jmp    e06 <generic_sleepable_preload+0xe06> */
	goto x86_l_e06;
x86_l_cbc:
	/* 0xcbc: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_cc1:
	/* 0xcc1: jmp    e06 <generic_sleepable_preload+0xe06> */
	goto x86_l_e06;
x86_l_cc6:
	/* 0xcc6: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_ccc:
	/* 0xccc: jmp    d26 <generic_sleepable_preload+0xd26> */
	goto x86_l_d26;
x86_l_cce:
	/* 0xcce: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_cd3:
	/* 0xcd3: jmp    e06 <generic_sleepable_preload+0xe06> */
	goto x86_l_e06;
x86_l_cd8:
	/* 0xcd8: mov    r13d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 3ULL);
x86_l_cde:
	/* 0xcde: jmp    d26 <generic_sleepable_preload+0xd26> */
	goto x86_l_d26;
x86_l_ce0:
	/* 0xce0: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_ce5:
	/* 0xce5: jmp    e06 <generic_sleepable_preload+0xe06> */
	goto x86_l_e06;
x86_l_cea:
	/* 0xcea: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_cf0:
	/* 0xcf0: jmp    d26 <generic_sleepable_preload+0xd26> */
	goto x86_l_d26;
x86_l_cf2:
	/* 0xcf2: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_cf7:
	/* 0xcf7: jmp    e06 <generic_sleepable_preload+0xe06> */
	goto x86_l_e06;
x86_l_cfc:
	/* 0xcfc: mov    r13d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 5ULL);
x86_l_d02:
	/* 0xd02: jmp    d26 <generic_sleepable_preload+0xd26> */
	goto x86_l_d26;
x86_l_d04:
	/* 0xd04: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_d09:
	/* 0xd09: jmp    e06 <generic_sleepable_preload+0xe06> */
	goto x86_l_e06;
x86_l_d0e:
	/* 0xd0e: mov    r13d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 6ULL);
x86_l_d14:
	/* 0xd14: jmp    d26 <generic_sleepable_preload+0xd26> */
	goto x86_l_d26;
x86_l_d16:
	/* 0xd16: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_d1b:
	/* 0xd1b: jmp    e06 <generic_sleepable_preload+0xe06> */
	goto x86_l_e06;
x86_l_d20:
	/* 0xd20: mov    r13d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 7ULL);
x86_l_d26:
	/* 0xd26: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d28:
	/* 0xd28: mov    r15d,DWORD PTR [r12+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 4ULL);
x86_l_d2d:
	/* 0xd2d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d32:
	/* 0xd32: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_d37:
	/* 0xd37: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_d3a:
	/* 0xd3a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d3f:
	/* 0xd3f: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_d42:
	/* 0xd42: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d44:
	/* 0xd44: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_d48:
	/* 0xd48: jne    114 <generic_sleepable_preload+0x114> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 276ULL;
	}
x86_l_d4e:
	/* 0xd4e: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d52:
	/* 0xd52: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_d5a:
	/* 0xd5a: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_d5f:
	/* 0xd5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d61:
	/* 0xd61: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d66:
	/* 0xd66: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_d6e:
	/* 0xd6e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d73:
	/* 0xd73: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_d7a:
	/* 0xd7a: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_d7f:
	/* 0xd7f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d81:
	/* 0xd81: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d84:
	/* 0xd84: je     10f <generic_sleepable_preload+0x10f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 271ULL;
	}
x86_l_d8a:
	/* 0xd8a: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_d8d:
	/* 0xd8d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d92:
	/* 0xd92: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d94:
	/* 0xd94: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_d9b:
	/* 0xd9b: mov    r12d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_d9e:
	/* 0xd9e: mov    ebp,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_32);
x86_l_da1:
	/* 0xda1: lea    r13,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_da6:
	/* 0xda6: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_da9:
	/* 0xda9: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_dac:
	/* 0xdac: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_dae:
	/* 0xdae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_db0:
	/* 0xdb0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_db5:
	/* 0xdb5: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_db8:
	/* 0xdb8: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_dbb:
	/* 0xdbb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dbd:
	/* 0xdbd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_dc0:
	/* 0xdc0: je     10f <generic_sleepable_preload+0x10f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 271ULL;
	}
x86_l_dc6:
	/* 0xdc6: test   r12b,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8);
x86_l_dc9:
	/* 0xdc9: je     10d <generic_sleepable_preload+0x10d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 269ULL;
	}
x86_l_dcf:
	/* 0xdcf: lea    rdi,[rax+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_dd3:
	/* 0xdd3: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_dd8:
	/* 0xdd8: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_de0:
	/* 0xde0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_de2:
	/* 0xde2: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_de5:
	/* 0xde5: call   dea <generic_sleepable_preload+0xdea> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_dea:
	/* 0xdea: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_dec:
	/* 0xdec: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_def:
	/* 0xdef: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_df1:
	/* 0xdf1: jns    10d <generic_sleepable_preload+0x10d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 269ULL;
	}
x86_l_df7:
	/* 0xdf7: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_dfc:
	/* 0xdfc: jmp    10d <generic_sleepable_preload+0x10d> */
	return 269ULL;
x86_l_e01:
	/* 0xe01: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_e06:
	/* 0xe06: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e09:
	/* 0xe09: cmp    r12d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 6ULL);
x86_l_e0d:
	/* 0xe0d: jne    10f <generic_sleepable_preload+0x10f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 271ULL;
	}
x86_l_e13:
	/* 0xe13: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e17:
	/* 0xe17: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_e1f:
	/* 0xe1f: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_e24:
	/* 0xe24: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e26:
	/* 0xe26: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e2b:
	/* 0xe2b: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_e33:
	/* 0xe33: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e38:
	/* 0xe38: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_e3f:
	/* 0xe3f: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_e44:
	/* 0xe44: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e46:
	/* 0xe46: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e49:
	/* 0xe49: je     10f <generic_sleepable_preload+0x10f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 271ULL;
	}
x86_l_e4f:
	/* 0xe4f: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_e52:
	/* 0xe52: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_e57:
	/* 0xe57: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e59:
	/* 0xe59: mov    r13,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_e60:
	/* 0xe60: mov    r12d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_32);
x86_l_e63:
	/* 0xe63: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_e66:
	/* 0xe66: lea    rbp,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e6b:
	/* 0xe6b: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_e6e:
	/* 0xe6e: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_e71:
	/* 0xe71: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e73:
	/* 0xe73: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e75:
	/* 0xe75: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e7a:
	/* 0xe7a: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_e7d:
	/* 0xe7d: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_e80:
	/* 0xe80: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e82:
	/* 0xe82: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e85:
	/* 0xe85: je     10f <generic_sleepable_preload+0x10f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 271ULL;
	}
x86_l_e8b:
	/* 0xe8b: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_e8e:
	/* 0xe8e: test   r12b,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8);
x86_l_e91:
	/* 0xe91: je     eb5 <generic_sleepable_preload+0xeb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_eb5;
	}
x86_l_e93:
	/* 0xe93: lea    rdi,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_e97:
	/* 0xe97: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_e9c:
	/* 0xe9c: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_ea4:
	/* 0xea4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ea6:
	/* 0xea6: call   eab <generic_sleepable_preload+0xeab> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_eab:
	/* 0xeab: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ead:
	/* 0xead: jns    eb5 <generic_sleepable_preload+0xeb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_eb5;
	}
x86_l_eaf:
	/* 0xeaf: mov    r15d,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967295ULL);
x86_l_eb5:
	/* 0xeb5: mov    DWORD PTR [r13+0x0],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_eb9:
	/* 0xeb9: jmp    10f <generic_sleepable_preload+0x10f> */
	return 271ULL;
x86_l_ebe:
	/* 0xebe: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ec0:
	/* 0xec0: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_ec6:
	/* 0xec6: jmp    d28 <generic_sleepable_preload+0xd28> */
	goto x86_l_d28;
x86_l_ecb:
	/* 0xecb: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ece:
	/* 0xece: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_ed3:
	/* 0xed3: cmp    r12d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 6ULL);
x86_l_ed7:
	/* 0xed7: jne    10f <generic_sleepable_preload+0x10f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 271ULL;
	}
x86_l_edd:
	/* 0xedd: jmp    e13 <generic_sleepable_preload+0xe13> */
	goto x86_l_e13;
x86_l_ee2:
	/* 0xee2: mov    r13d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 9ULL);
x86_l_ee8:
	/* 0xee8: jmp    d26 <generic_sleepable_preload+0xd26> */
	goto x86_l_d26;
x86_l_eed:
	/* 0xeed: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_ef2:
	/* 0xef2: jmp    e06 <generic_sleepable_preload+0xe06> */
	goto x86_l_e06;
x86_l_ef7:
	/* 0xef7: mov    eax,DWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_efc:
	/* 0xefc: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_f01:
	/* 0xf01: je     1e26 <generic_sleepable_preload+0x1e26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7718ULL;
	}
x86_l_f07:
	/* 0xf07: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_f09:
	/* 0xf09: js     f3e <generic_sleepable_preload+0xf3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_f3e;
	}
x86_l_f0b:
	/* 0xf0b: mov    eax,DWORD PTR [r12+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_f10:
	/* 0xf10: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f13:
	/* 0xf13: jle    fc6 <generic_sleepable_preload+0xfc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_fc6;
	}
x86_l_f19:
	/* 0xf19: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_f1c:
	/* 0xf1c: je     1030 <generic_sleepable_preload+0x1030> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1030;
	}
x86_l_f22:
	/* 0xf22: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_f25:
	/* 0xf25: je     1037 <generic_sleepable_preload+0x1037> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1037;
	}
x86_l_f2b:
	/* 0xf2b: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f2e:
	/* 0xf2e: jne    104a <generic_sleepable_preload+0x104a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_104a;
	}
x86_l_f34:
	/* 0xf34: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f39:
	/* 0xf39: jmp    1043 <generic_sleepable_preload+0x1043> */
	goto x86_l_1043;
x86_l_f3e:
	/* 0xf3e: movzx  eax,BYTE PTR [r12+0x2c2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 706ULL);
x86_l_f47:
	/* 0xf47: movzx  ecx,WORD PTR [r12+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 704ULL);
x86_l_f50:
	/* 0xf50: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_f56:
	/* 0xf56: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f58:
	/* 0xf58: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_f5b:
	/* 0xf5b: jle    f9a <generic_sleepable_preload+0xf9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_f9a;
	}
x86_l_f5d:
	/* 0xf5d: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_f60:
	/* 0xf60: jle    fd6 <generic_sleepable_preload+0xfd6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_fd6;
	}
x86_l_f62:
	/* 0xf62: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_f65:
	/* 0xf65: jle    167e <generic_sleepable_preload+0x167e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5758ULL;
	}
x86_l_f6b:
	/* 0xf6b: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_f70:
	/* 0xf70: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_f73:
	/* 0xf73: je     1692 <generic_sleepable_preload+0x1692> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5778ULL;
	}
x86_l_f79:
	/* 0xf79: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_f7e:
	/* 0xf7e: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_f81:
	/* 0xf81: je     1692 <generic_sleepable_preload+0x1692> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5778ULL;
	}
x86_l_f87:
	/* 0xf87: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_f8a:
	/* 0xf8a: jne    16a5 <generic_sleepable_preload+0x16a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5797ULL;
	}
x86_l_f90:
	/* 0xf90: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_f95:
	/* 0xf95: jmp    1692 <generic_sleepable_preload+0x1692> */
	return 5778ULL;
x86_l_f9a:
	/* 0xf9a: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_f9d:
	/* 0xf9d: jg     1003 <generic_sleepable_preload+0x1003> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1003;
	}
x86_l_f9f:
	/* 0xf9f: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_fa2:
	/* 0xfa2: jg     164f <generic_sleepable_preload+0x164f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5711ULL;
	}
x86_l_fa8:
	/* 0xfa8: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_fad:
	/* 0xfad: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_faf:
	/* 0xfaf: je     1692 <generic_sleepable_preload+0x1692> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5778ULL;
	}
x86_l_fb5:
	/* 0xfb5: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_fb8:
	/* 0xfb8: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_fbb:
	/* 0xfbb: je     1692 <generic_sleepable_preload+0x1692> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5778ULL;
	}
x86_l_fc1:
	/* 0xfc1: jmp    16a5 <generic_sleepable_preload+0x16a5> */
	return 5797ULL;
x86_l_fc6:
	/* 0xfc6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_fc8:
	/* 0xfc8: je     103e <generic_sleepable_preload+0x103e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_103e;
	}
x86_l_fca:
	/* 0xfca: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fcd:
	/* 0xfcd: jne    104a <generic_sleepable_preload+0x104a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_104a;
	}
x86_l_fcf:
	/* 0xfcf: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fd4:
	/* 0xfd4: jmp    1043 <generic_sleepable_preload+0x1043> */
	goto x86_l_1043;
x86_l_fd6:
	/* 0xfd6: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_fd9:
	/* 0xfd9: jg     1636 <generic_sleepable_preload+0x1636> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5686ULL;
	}
x86_l_fdf:
	/* 0xfdf: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_fe7:
	/* 0xfe7: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_fea:
	/* 0xfea: je     1692 <generic_sleepable_preload+0x1692> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5778ULL;
	}
x86_l_ff0:
	/* 0xff0: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ff5:
	/* 0xff5: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_ff8:
	/* 0xff8: je     1692 <generic_sleepable_preload+0x1692> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5778ULL;
	}
x86_l_ffe:
	/* 0xffe: jmp    16a5 <generic_sleepable_preload+0x16a5> */
	return 5797ULL;
x86_l_1003:
	/* 0x1003: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1006:
	/* 0x1006: jg     1665 <generic_sleepable_preload+0x1665> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5733ULL;
	}
x86_l_100c:
	/* 0x100c: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1014:
	/* 0x1014: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1017:
	/* 0x1017: je     1692 <generic_sleepable_preload+0x1692> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5778ULL;
	}
x86_l_101d:
	/* 0x101d: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1022:
	/* 0x1022: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1025:
	/* 0x1025: je     1692 <generic_sleepable_preload+0x1692> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5778ULL;
	}
x86_l_102b:
	/* 0x102b: jmp    16a5 <generic_sleepable_preload+0x16a5> */
	return 5797ULL;
x86_l_1030:
	/* 0x1030: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1035:
	/* 0x1035: jmp    1043 <generic_sleepable_preload+0x1043> */
	goto x86_l_1043;
x86_l_1037:
	/* 0x1037: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_103c:
	/* 0x103c: jmp    1043 <generic_sleepable_preload+0x1043> */
	goto x86_l_1043;
x86_l_103e:
	/* 0x103e: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1043:
	/* 0x1043: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1046:
	/* 0x1046: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_104a:
	/* 0x104a: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_104c:
	/* 0x104c: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_104f:
	/* 0x104f: cmp    WORD PTR [r12+0x76],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 506806140928ULL);
x86_l_1056:
	/* 0x1056: je     1cf7 <generic_sleepable_preload+0x1cf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7415ULL;
	}
x86_l_105c:
	/* 0x105c: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_1063:
	/* 0x1063: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1066:
	/* 0x1066: mov    eax,DWORD PTR [r12+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_106b:
	/* 0x106b: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_106e:
	/* 0x106e: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1072:
	/* 0x1072: movzx  eax,WORD PTR [r12+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 116ULL);
x86_l_1078:
	/* 0x1078: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_107a:
	/* 0x107a: je     1343 <generic_sleepable_preload+0x1343> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1343;
	}
x86_l_1080:
	/* 0x1080: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_1083:
	/* 0x1083: je     10a5 <generic_sleepable_preload+0x10a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10a5;
	}
x86_l_1085:
	/* 0x1085: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1088:
	/* 0x1088: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_108d:
	/* 0x108d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1092:
	/* 0x1092: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1096:
	/* 0x1096: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_109b:
	/* 0x109b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_109d:
	/* 0x109d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_109f:
	/* 0x109f: js     162c <generic_sleepable_preload+0x162c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 5676ULL;
	}
x86_l_10a5:
	/* 0x10a5: cmp    WORD PTR [r12+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_10ac:
	/* 0x10ac: je     1cf7 <generic_sleepable_preload+0x1cf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7415ULL;
	}
x86_l_10b2:
	/* 0x10b2: mov    ecx,DWORD PTR [r12+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_10b7:
	/* 0x10b7: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_10bb:
	/* 0x10bb: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10bf:
	/* 0x10bf: cmp    WORD PTR [r12+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_10c6:
	/* 0x10c6: je     10e8 <generic_sleepable_preload+0x10e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10e8;
	}
x86_l_10c8:
	/* 0x10c8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_10cb:
	/* 0x10cb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_10d0:
	/* 0x10d0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_10d5:
	/* 0x10d5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10d9:
	/* 0x10d9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10de:
	/* 0x10de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10e0:
	/* 0x10e0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_10e2:
	/* 0x10e2: js     1c9a <generic_sleepable_preload+0x1c9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7322ULL;
	}
x86_l_10e8:
	/* 0x10e8: cmp    WORD PTR [r12+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_10f2:
	/* 0x10f2: je     1cf7 <generic_sleepable_preload+0x1cf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7415ULL;
	}
x86_l_10f8:
	/* 0x10f8: mov    ecx,DWORD PTR [r12+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1100:
	/* 0x1100: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1104:
	/* 0x1104: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1108:
	/* 0x1108: cmp    WORD PTR [r12+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_1112:
	/* 0x1112: je     1134 <generic_sleepable_preload+0x1134> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1134;
	}
x86_l_1114:
	/* 0x1114: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1117:
	/* 0x1117: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_111c:
	/* 0x111c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1121:
	/* 0x1121: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1125:
	/* 0x1125: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_112a:
	/* 0x112a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_112c:
	/* 0x112c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_112e:
	/* 0x112e: js     1cab <generic_sleepable_preload+0x1cab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7339ULL;
	}
x86_l_1134:
	/* 0x1134: cmp    WORD PTR [r12+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_113e:
	/* 0x113e: je     1cf7 <generic_sleepable_preload+0x1cf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7415ULL;
	}
x86_l_1144:
	/* 0x1144: mov    ecx,DWORD PTR [r12+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_114c:
	/* 0x114c: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1150:
	/* 0x1150: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1154:
	/* 0x1154: cmp    WORD PTR [r12+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_115e:
	/* 0x115e: je     1180 <generic_sleepable_preload+0x1180> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1180;
	}
x86_l_1160:
	/* 0x1160: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1163:
	/* 0x1163: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1168:
	/* 0x1168: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_116d:
	/* 0x116d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1171:
	/* 0x1171: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1176:
	/* 0x1176: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1178:
	/* 0x1178: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_117a:
	/* 0x117a: js     1cbc <generic_sleepable_preload+0x1cbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7356ULL;
	}
x86_l_1180:
	/* 0x1180: cmp    WORD PTR [r12+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_118a:
	/* 0x118a: je     1cf7 <generic_sleepable_preload+0x1cf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7415ULL;
	}
x86_l_1190:
	/* 0x1190: mov    ecx,DWORD PTR [r12+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1198:
	/* 0x1198: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_119c:
	/* 0x119c: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11a0:
	/* 0x11a0: cmp    WORD PTR [r12+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_11aa:
	/* 0x11aa: je     11cc <generic_sleepable_preload+0x11cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11cc;
	}
x86_l_11ac:
	/* 0x11ac: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_11af:
	/* 0x11af: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_11b4:
	/* 0x11b4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_11b9:
	/* 0x11b9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11bd:
	/* 0x11bd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11c2:
	/* 0x11c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11c4:
	/* 0x11c4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_11c6:
	/* 0x11c6: js     1ccd <generic_sleepable_preload+0x1ccd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7373ULL;
	}
x86_l_11cc:
	/* 0x11cc: cmp    WORD PTR [r12+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_11d6:
	/* 0x11d6: je     1cf7 <generic_sleepable_preload+0x1cf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7415ULL;
	}
x86_l_11dc:
	/* 0x11dc: mov    ecx,DWORD PTR [r12+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_11e4:
	/* 0x11e4: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_11e8:
	/* 0x11e8: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11ec:
	/* 0x11ec: cmp    WORD PTR [r12+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_11f6:
	/* 0x11f6: je     1218 <generic_sleepable_preload+0x1218> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1218;
	}
x86_l_11f8:
	/* 0x11f8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_11fb:
	/* 0x11fb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1200:
	/* 0x1200: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1205:
	/* 0x1205: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1209:
	/* 0x1209: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_120e:
	/* 0x120e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1210:
	/* 0x1210: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1212:
	/* 0x1212: js     1cde <generic_sleepable_preload+0x1cde> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7390ULL;
	}
x86_l_1218:
	/* 0x1218: cmp    WORD PTR [r12+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_1222:
	/* 0x1222: je     1cf7 <generic_sleepable_preload+0x1cf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7415ULL;
	}
x86_l_1228:
	/* 0x1228: mov    ecx,DWORD PTR [r12+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1230:
	/* 0x1230: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1234:
	/* 0x1234: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1238:
	/* 0x1238: cmp    WORD PTR [r12+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_1242:
	/* 0x1242: je     1264 <generic_sleepable_preload+0x1264> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1264;
	}
x86_l_1244:
	/* 0x1244: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1247:
	/* 0x1247: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_124c:
	/* 0x124c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1251:
	/* 0x1251: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1255:
	/* 0x1255: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_125a:
	/* 0x125a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_125c:
	/* 0x125c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_125e:
	/* 0x125e: js     1cef <generic_sleepable_preload+0x1cef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7407ULL;
	}
x86_l_1264:
	/* 0x1264: cmp    WORD PTR [r12+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_126e:
	/* 0x126e: je     1cf7 <generic_sleepable_preload+0x1cf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7415ULL;
	}
x86_l_1274:
	/* 0x1274: mov    ecx,DWORD PTR [r12+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_127c:
	/* 0x127c: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1280:
	/* 0x1280: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1284:
	/* 0x1284: cmp    WORD PTR [r12+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_128e:
	/* 0x128e: je     12b0 <generic_sleepable_preload+0x12b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12b0;
	}
x86_l_1290:
	/* 0x1290: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1293:
	/* 0x1293: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1298:
	/* 0x1298: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_129d:
	/* 0x129d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12a1:
	/* 0x12a1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12a6:
	/* 0x12a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12a8:
	/* 0x12a8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_12aa:
	/* 0x12aa: js     5bc2 <generic_sleepable_preload+0x5bc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23490ULL;
	}
x86_l_12b0:
	/* 0x12b0: cmp    WORD PTR [r12+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_12ba:
	/* 0x12ba: je     1cf7 <generic_sleepable_preload+0x1cf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7415ULL;
	}
x86_l_12c0:
	/* 0x12c0: mov    ecx,DWORD PTR [r12+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_12c8:
	/* 0x12c8: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_12cc:
	/* 0x12cc: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12d0:
	/* 0x12d0: cmp    WORD PTR [r12+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_12da:
	/* 0x12da: je     12fc <generic_sleepable_preload+0x12fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12fc;
	}
x86_l_12dc:
	/* 0x12dc: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_12df:
	/* 0x12df: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_12e4:
	/* 0x12e4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_12e9:
	/* 0x12e9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12ed:
	/* 0x12ed: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12f2:
	/* 0x12f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12f4:
	/* 0x12f4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_12f6:
	/* 0x12f6: js     5ca8 <generic_sleepable_preload+0x5ca8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23720ULL;
	}
x86_l_12fc:
	/* 0x12fc: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1301:
	/* 0x1301: cmp    WORD PTR [r12+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_130b:
	/* 0x130b: je     1cf7 <generic_sleepable_preload+0x1cf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7415ULL;
	}
x86_l_1311:
	/* 0x1311: mov    ecx,DWORD PTR [r12+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1319:
	/* 0x1319: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_131d:
	/* 0x131d: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1321:
	/* 0x1321: cmp    WORD PTR [r12+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_132b:
	/* 0x132b: je     1cf7 <generic_sleepable_preload+0x1cf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7415ULL;
	}
x86_l_1331:
	/* 0x1331: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1334:
	/* 0x1334: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1339:
	/* 0x1339: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_133e:
	/* 0x133e: jmp    160f <generic_sleepable_preload+0x160f> */
	return 5647ULL;
x86_l_1343:
	/* 0x1343: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_1346:
	/* 0x1346: je     1368 <generic_sleepable_preload+0x1368> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4968ULL;
	}
x86_l_1348:
	/* 0x1348: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
	return 4939ULL;
}

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 4939ULL: goto x86_l_134b;
	case 4944ULL: goto x86_l_1350;
	case 4949ULL: goto x86_l_1355;
	case 4953ULL: goto x86_l_1359;
	case 4958ULL: goto x86_l_135e;
	case 4960ULL: goto x86_l_1360;
	case 4962ULL: goto x86_l_1362;
	case 4968ULL: goto x86_l_1368;
	case 4975ULL: goto x86_l_136f;
	case 4981ULL: goto x86_l_1375;
	case 4986ULL: goto x86_l_137a;
	case 4990ULL: goto x86_l_137e;
	case 4994ULL: goto x86_l_1382;
	case 5001ULL: goto x86_l_1389;
	case 5003ULL: goto x86_l_138b;
	case 5006ULL: goto x86_l_138e;
	case 5011ULL: goto x86_l_1393;
	case 5016ULL: goto x86_l_1398;
	case 5020ULL: goto x86_l_139c;
	case 5025ULL: goto x86_l_13a1;
	case 5027ULL: goto x86_l_13a3;
	case 5029ULL: goto x86_l_13a5;
	case 5035ULL: goto x86_l_13ab;
	case 5045ULL: goto x86_l_13b5;
	case 5051ULL: goto x86_l_13bb;
	case 5059ULL: goto x86_l_13c3;
	case 5063ULL: goto x86_l_13c7;
	case 5067ULL: goto x86_l_13cb;
	case 5077ULL: goto x86_l_13d5;
	case 5079ULL: goto x86_l_13d7;
	case 5082ULL: goto x86_l_13da;
	case 5087ULL: goto x86_l_13df;
	case 5092ULL: goto x86_l_13e4;
	case 5096ULL: goto x86_l_13e8;
	case 5101ULL: goto x86_l_13ed;
	case 5103ULL: goto x86_l_13ef;
	case 5105ULL: goto x86_l_13f1;
	case 5111ULL: goto x86_l_13f7;
	case 5121ULL: goto x86_l_1401;
	case 5127ULL: goto x86_l_1407;
	case 5135ULL: goto x86_l_140f;
	case 5139ULL: goto x86_l_1413;
	case 5143ULL: goto x86_l_1417;
	case 5153ULL: goto x86_l_1421;
	case 5155ULL: goto x86_l_1423;
	case 5158ULL: goto x86_l_1426;
	case 5163ULL: goto x86_l_142b;
	case 5168ULL: goto x86_l_1430;
	case 5172ULL: goto x86_l_1434;
	case 5177ULL: goto x86_l_1439;
	case 5179ULL: goto x86_l_143b;
	case 5181ULL: goto x86_l_143d;
	case 5187ULL: goto x86_l_1443;
	case 5197ULL: goto x86_l_144d;
	case 5203ULL: goto x86_l_1453;
	case 5211ULL: goto x86_l_145b;
	case 5215ULL: goto x86_l_145f;
	case 5219ULL: goto x86_l_1463;
	case 5229ULL: goto x86_l_146d;
	case 5231ULL: goto x86_l_146f;
	case 5234ULL: goto x86_l_1472;
	case 5239ULL: goto x86_l_1477;
	case 5244ULL: goto x86_l_147c;
	case 5248ULL: goto x86_l_1480;
	case 5253ULL: goto x86_l_1485;
	case 5255ULL: goto x86_l_1487;
	case 5257ULL: goto x86_l_1489;
	case 5263ULL: goto x86_l_148f;
	case 5273ULL: goto x86_l_1499;
	case 5279ULL: goto x86_l_149f;
	case 5287ULL: goto x86_l_14a7;
	case 5291ULL: goto x86_l_14ab;
	case 5295ULL: goto x86_l_14af;
	case 5305ULL: goto x86_l_14b9;
	case 5307ULL: goto x86_l_14bb;
	case 5310ULL: goto x86_l_14be;
	case 5315ULL: goto x86_l_14c3;
	case 5320ULL: goto x86_l_14c8;
	case 5324ULL: goto x86_l_14cc;
	case 5329ULL: goto x86_l_14d1;
	case 5331ULL: goto x86_l_14d3;
	case 5333ULL: goto x86_l_14d5;
	case 5339ULL: goto x86_l_14db;
	case 5349ULL: goto x86_l_14e5;
	case 5355ULL: goto x86_l_14eb;
	case 5363ULL: goto x86_l_14f3;
	case 5367ULL: goto x86_l_14f7;
	case 5371ULL: goto x86_l_14fb;
	case 5381ULL: goto x86_l_1505;
	case 5383ULL: goto x86_l_1507;
	case 5386ULL: goto x86_l_150a;
	case 5391ULL: goto x86_l_150f;
	case 5396ULL: goto x86_l_1514;
	case 5400ULL: goto x86_l_1518;
	case 5405ULL: goto x86_l_151d;
	case 5407ULL: goto x86_l_151f;
	case 5409ULL: goto x86_l_1521;
	case 5415ULL: goto x86_l_1527;
	case 5425ULL: goto x86_l_1531;
	case 5431ULL: goto x86_l_1537;
	case 5434ULL: goto x86_l_153a;
	case 5442ULL: goto x86_l_1542;
	case 5446ULL: goto x86_l_1546;
	case 5450ULL: goto x86_l_154a;
	case 5460ULL: goto x86_l_1554;
	case 5462ULL: goto x86_l_1556;
	case 5465ULL: goto x86_l_1559;
	case 5470ULL: goto x86_l_155e;
	case 5475ULL: goto x86_l_1563;
	case 5479ULL: goto x86_l_1567;
	case 5484ULL: goto x86_l_156c;
	case 5486ULL: goto x86_l_156e;
	case 5488ULL: goto x86_l_1570;
	case 5494ULL: goto x86_l_1576;
	case 5499ULL: goto x86_l_157b;
	case 5509ULL: goto x86_l_1585;
	case 5512ULL: goto x86_l_1588;
	case 5518ULL: goto x86_l_158e;
	case 5526ULL: goto x86_l_1596;
	case 5530ULL: goto x86_l_159a;
	case 5534ULL: goto x86_l_159e;
	case 5544ULL: goto x86_l_15a8;
	case 5546ULL: goto x86_l_15aa;
	case 5549ULL: goto x86_l_15ad;
	case 5554ULL: goto x86_l_15b2;
	case 5559ULL: goto x86_l_15b7;
	case 5563ULL: goto x86_l_15bb;
	case 5568ULL: goto x86_l_15c0;
	case 5570ULL: goto x86_l_15c2;
	case 5572ULL: goto x86_l_15c4;
	case 5578ULL: goto x86_l_15ca;
	case 5583ULL: goto x86_l_15cf;
	case 5593ULL: goto x86_l_15d9;
	case 5596ULL: goto x86_l_15dc;
	case 5602ULL: goto x86_l_15e2;
	case 5610ULL: goto x86_l_15ea;
	case 5614ULL: goto x86_l_15ee;
	case 5618ULL: goto x86_l_15f2;
	case 5628ULL: goto x86_l_15fc;
	case 5634ULL: goto x86_l_1602;
	case 5637ULL: goto x86_l_1605;
	case 5642ULL: goto x86_l_160a;
	case 5647ULL: goto x86_l_160f;
	case 5651ULL: goto x86_l_1613;
	case 5656ULL: goto x86_l_1618;
	case 5658ULL: goto x86_l_161a;
	case 5660ULL: goto x86_l_161c;
	case 5666ULL: goto x86_l_1622;
	case 5671ULL: goto x86_l_1627;
	case 5676ULL: goto x86_l_162c;
	case 5681ULL: goto x86_l_1631;
	case 5686ULL: goto x86_l_1636;
	case 5694ULL: goto x86_l_163e;
	case 5697ULL: goto x86_l_1641;
	case 5699ULL: goto x86_l_1643;
	case 5704ULL: goto x86_l_1648;
	case 5707ULL: goto x86_l_164b;
	case 5709ULL: goto x86_l_164d;
	case 5711ULL: goto x86_l_164f;
	case 5716ULL: goto x86_l_1654;
	case 5719ULL: goto x86_l_1657;
	case 5721ULL: goto x86_l_1659;
	case 5726ULL: goto x86_l_165e;
	case 5729ULL: goto x86_l_1661;
	case 5731ULL: goto x86_l_1663;
	case 5733ULL: goto x86_l_1665;
	case 5741ULL: goto x86_l_166d;
	case 5744ULL: goto x86_l_1670;
	case 5746ULL: goto x86_l_1672;
	case 5751ULL: goto x86_l_1677;
	case 5754ULL: goto x86_l_167a;
	case 5756ULL: goto x86_l_167c;
	case 5758ULL: goto x86_l_167e;
	case 5763ULL: goto x86_l_1683;
	case 5766ULL: goto x86_l_1686;
	case 5768ULL: goto x86_l_1688;
	case 5773ULL: goto x86_l_168d;
	case 5776ULL: goto x86_l_1690;
	case 5778ULL: goto x86_l_1692;
	case 5781ULL: goto x86_l_1695;
	case 5783ULL: goto x86_l_1697;
	case 5785ULL: goto x86_l_1699;
	case 5790ULL: goto x86_l_169e;
	case 5792ULL: goto x86_l_16a0;
	case 5797ULL: goto x86_l_16a5;
	case 5801ULL: goto x86_l_16a9;
	case 5806ULL: goto x86_l_16ae;
	case 5808ULL: goto x86_l_16b0;
	case 5811ULL: goto x86_l_16b3;
	case 5818ULL: goto x86_l_16ba;
	case 5824ULL: goto x86_l_16c0;
	case 5831ULL: goto x86_l_16c7;
	case 5834ULL: goto x86_l_16ca;
	case 5839ULL: goto x86_l_16cf;
	case 5842ULL: goto x86_l_16d2;
	case 5846ULL: goto x86_l_16d6;
	case 5852ULL: goto x86_l_16dc;
	case 5854ULL: goto x86_l_16de;
	case 5860ULL: goto x86_l_16e4;
	case 5863ULL: goto x86_l_16e7;
	case 5865ULL: goto x86_l_16e9;
	case 5868ULL: goto x86_l_16ec;
	case 5873ULL: goto x86_l_16f1;
	case 5878ULL: goto x86_l_16f6;
	case 5882ULL: goto x86_l_16fa;
	case 5887ULL: goto x86_l_16ff;
	case 5889ULL: goto x86_l_1701;
	case 5891ULL: goto x86_l_1703;
	case 5897ULL: goto x86_l_1709;
	case 5904ULL: goto x86_l_1710;
	case 5910ULL: goto x86_l_1716;
	case 5915ULL: goto x86_l_171b;
	case 5919ULL: goto x86_l_171f;
	case 5923ULL: goto x86_l_1723;
	case 5930ULL: goto x86_l_172a;
	case 5932ULL: goto x86_l_172c;
	case 5935ULL: goto x86_l_172f;
	case 5940ULL: goto x86_l_1734;
	case 5945ULL: goto x86_l_1739;
	case 5949ULL: goto x86_l_173d;
	case 5954ULL: goto x86_l_1742;
	case 5956ULL: goto x86_l_1744;
	case 5958ULL: goto x86_l_1746;
	case 5964ULL: goto x86_l_174c;
	case 5974ULL: goto x86_l_1756;
	case 5980ULL: goto x86_l_175c;
	case 5988ULL: goto x86_l_1764;
	case 5992ULL: goto x86_l_1768;
	case 5996ULL: goto x86_l_176c;
	case 6006ULL: goto x86_l_1776;
	case 6008ULL: goto x86_l_1778;
	case 6011ULL: goto x86_l_177b;
	case 6016ULL: goto x86_l_1780;
	case 6021ULL: goto x86_l_1785;
	case 6025ULL: goto x86_l_1789;
	case 6030ULL: goto x86_l_178e;
	case 6032ULL: goto x86_l_1790;
	case 6034ULL: goto x86_l_1792;
	case 6040ULL: goto x86_l_1798;
	case 6050ULL: goto x86_l_17a2;
	case 6056ULL: goto x86_l_17a8;
	case 6064ULL: goto x86_l_17b0;
	case 6068ULL: goto x86_l_17b4;
	case 6072ULL: goto x86_l_17b8;
	case 6082ULL: goto x86_l_17c2;
	case 6084ULL: goto x86_l_17c4;
	case 6087ULL: goto x86_l_17c7;
	case 6092ULL: goto x86_l_17cc;
	case 6097ULL: goto x86_l_17d1;
	case 6101ULL: goto x86_l_17d5;
	case 6106ULL: goto x86_l_17da;
	case 6108ULL: goto x86_l_17dc;
	case 6110ULL: goto x86_l_17de;
	case 6116ULL: goto x86_l_17e4;
	case 6126ULL: goto x86_l_17ee;
	case 6132ULL: goto x86_l_17f4;
	case 6140ULL: goto x86_l_17fc;
	case 6144ULL: goto x86_l_1800;
	case 6148ULL: goto x86_l_1804;
	case 6158ULL: goto x86_l_180e;
	case 6160ULL: goto x86_l_1810;
	case 6163ULL: goto x86_l_1813;
	case 6168ULL: goto x86_l_1818;
	case 6173ULL: goto x86_l_181d;
	case 6177ULL: goto x86_l_1821;
	case 6182ULL: goto x86_l_1826;
	case 6184ULL: goto x86_l_1828;
	case 6186ULL: goto x86_l_182a;
	case 6192ULL: goto x86_l_1830;
	case 6202ULL: goto x86_l_183a;
	case 6208ULL: goto x86_l_1840;
	case 6216ULL: goto x86_l_1848;
	case 6220ULL: goto x86_l_184c;
	case 6224ULL: goto x86_l_1850;
	case 6234ULL: goto x86_l_185a;
	case 6236ULL: goto x86_l_185c;
	case 6239ULL: goto x86_l_185f;
	case 6244ULL: goto x86_l_1864;
	case 6249ULL: goto x86_l_1869;
	case 6253ULL: goto x86_l_186d;
	case 6258ULL: goto x86_l_1872;
	case 6260ULL: goto x86_l_1874;
	case 6262ULL: goto x86_l_1876;
	case 6268ULL: goto x86_l_187c;
	case 6278ULL: goto x86_l_1886;
	case 6284ULL: goto x86_l_188c;
	case 6292ULL: goto x86_l_1894;
	case 6296ULL: goto x86_l_1898;
	case 6300ULL: goto x86_l_189c;
	case 6310ULL: goto x86_l_18a6;
	case 6312ULL: goto x86_l_18a8;
	case 6315ULL: goto x86_l_18ab;
	case 6320ULL: goto x86_l_18b0;
	case 6325ULL: goto x86_l_18b5;
	case 6329ULL: goto x86_l_18b9;
	case 6334ULL: goto x86_l_18be;
	case 6336ULL: goto x86_l_18c0;
	case 6338ULL: goto x86_l_18c2;
	case 6344ULL: goto x86_l_18c8;
	case 6354ULL: goto x86_l_18d2;
	case 6360ULL: goto x86_l_18d8;
	case 6368ULL: goto x86_l_18e0;
	case 6372ULL: goto x86_l_18e4;
	case 6376ULL: goto x86_l_18e8;
	case 6386ULL: goto x86_l_18f2;
	case 6388ULL: goto x86_l_18f4;
	case 6391ULL: goto x86_l_18f7;
	case 6396ULL: goto x86_l_18fc;
	case 6401ULL: goto x86_l_1901;
	case 6405ULL: goto x86_l_1905;
	case 6410ULL: goto x86_l_190a;
	case 6412ULL: goto x86_l_190c;
	case 6414ULL: goto x86_l_190e;
	case 6420ULL: goto x86_l_1914;
	case 6430ULL: goto x86_l_191e;
	case 6436ULL: goto x86_l_1924;
	case 6444ULL: goto x86_l_192c;
	case 6448ULL: goto x86_l_1930;
	case 6452ULL: goto x86_l_1934;
	case 6462ULL: goto x86_l_193e;
	case 6464ULL: goto x86_l_1940;
	case 6467ULL: goto x86_l_1943;
	case 6472ULL: goto x86_l_1948;
	case 6477ULL: goto x86_l_194d;
	case 6481ULL: goto x86_l_1951;
	case 6486ULL: goto x86_l_1956;
	case 6488ULL: goto x86_l_1958;
	case 6490ULL: goto x86_l_195a;
	case 6496ULL: goto x86_l_1960;
	case 6501ULL: goto x86_l_1965;
	case 6511ULL: goto x86_l_196f;
	case 6517ULL: goto x86_l_1975;
	case 6525ULL: goto x86_l_197d;
	case 6529ULL: goto x86_l_1981;
	case 6533ULL: goto x86_l_1985;
	case 6543ULL: goto x86_l_198f;
	case 6549ULL: goto x86_l_1995;
	case 6552ULL: goto x86_l_1998;
	case 6557ULL: goto x86_l_199d;
	case 6562ULL: goto x86_l_19a2;
	case 6567ULL: goto x86_l_19a7;
	case 6570ULL: goto x86_l_19aa;
	case 6572ULL: goto x86_l_19ac;
	case 6575ULL: goto x86_l_19af;
	case 6580ULL: goto x86_l_19b4;
	case 6585ULL: goto x86_l_19b9;
	case 6589ULL: goto x86_l_19bd;
	case 6594ULL: goto x86_l_19c2;
	case 6596ULL: goto x86_l_19c4;
	case 6598ULL: goto x86_l_19c6;
	case 6604ULL: goto x86_l_19cc;
	case 6611ULL: goto x86_l_19d3;
	case 6617ULL: goto x86_l_19d9;
	case 6622ULL: goto x86_l_19de;
	case 6626ULL: goto x86_l_19e2;
	case 6630ULL: goto x86_l_19e6;
	case 6637ULL: goto x86_l_19ed;
	case 6639ULL: goto x86_l_19ef;
	case 6642ULL: goto x86_l_19f2;
	case 6647ULL: goto x86_l_19f7;
	case 6652ULL: goto x86_l_19fc;
	case 6656ULL: goto x86_l_1a00;
	case 6661ULL: goto x86_l_1a05;
	case 6663ULL: goto x86_l_1a07;
	case 6665ULL: goto x86_l_1a09;
	case 6671ULL: goto x86_l_1a0f;
	case 6681ULL: goto x86_l_1a19;
	case 6687ULL: goto x86_l_1a1f;
	case 6695ULL: goto x86_l_1a27;
	case 6699ULL: goto x86_l_1a2b;
	case 6703ULL: goto x86_l_1a2f;
	case 6713ULL: goto x86_l_1a39;
	case 6715ULL: goto x86_l_1a3b;
	case 6718ULL: goto x86_l_1a3e;
	case 6723ULL: goto x86_l_1a43;
	case 6728ULL: goto x86_l_1a48;
	case 6732ULL: goto x86_l_1a4c;
	case 6737ULL: goto x86_l_1a51;
	case 6739ULL: goto x86_l_1a53;
	case 6741ULL: goto x86_l_1a55;
	case 6747ULL: goto x86_l_1a5b;
	case 6757ULL: goto x86_l_1a65;
	case 6763ULL: goto x86_l_1a6b;
	case 6771ULL: goto x86_l_1a73;
	default: return 0xffffffffffffffffULL;
	}
x86_l_134b:
	/* 0x134b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1350:
	/* 0x1350: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1355:
	/* 0x1355: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1359:
	/* 0x1359: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_135e:
	/* 0x135e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1360:
	/* 0x1360: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1362:
	/* 0x1362: js     162c <generic_sleepable_preload+0x162c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_162c;
	}
x86_l_1368:
	/* 0x1368: cmp    WORD PTR [r12+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_136f:
	/* 0x136f: je     1cf7 <generic_sleepable_preload+0x1cf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7415ULL;
	}
x86_l_1375:
	/* 0x1375: mov    ecx,DWORD PTR [r12+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_137a:
	/* 0x137a: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_137e:
	/* 0x137e: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1382:
	/* 0x1382: cmp    WORD PTR [r12+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_1389:
	/* 0x1389: je     13ab <generic_sleepable_preload+0x13ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13ab;
	}
x86_l_138b:
	/* 0x138b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_138e:
	/* 0x138e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1393:
	/* 0x1393: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1398:
	/* 0x1398: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_139c:
	/* 0x139c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_13a1:
	/* 0x13a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13a3:
	/* 0x13a3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_13a5:
	/* 0x13a5: js     1c9a <generic_sleepable_preload+0x1c9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7322ULL;
	}
x86_l_13ab:
	/* 0x13ab: cmp    WORD PTR [r12+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_13b5:
	/* 0x13b5: je     1cf7 <generic_sleepable_preload+0x1cf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7415ULL;
	}
x86_l_13bb:
	/* 0x13bb: mov    ecx,DWORD PTR [r12+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_13c3:
	/* 0x13c3: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_13c7:
	/* 0x13c7: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13cb:
	/* 0x13cb: cmp    WORD PTR [r12+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_13d5:
	/* 0x13d5: je     13f7 <generic_sleepable_preload+0x13f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13f7;
	}
x86_l_13d7:
	/* 0x13d7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_13da:
	/* 0x13da: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_13df:
	/* 0x13df: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_13e4:
	/* 0x13e4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13e8:
	/* 0x13e8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_13ed:
	/* 0x13ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13ef:
	/* 0x13ef: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_13f1:
	/* 0x13f1: js     1cab <generic_sleepable_preload+0x1cab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7339ULL;
	}
x86_l_13f7:
	/* 0x13f7: cmp    WORD PTR [r12+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_1401:
	/* 0x1401: je     1cf7 <generic_sleepable_preload+0x1cf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7415ULL;
	}
x86_l_1407:
	/* 0x1407: mov    ecx,DWORD PTR [r12+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_140f:
	/* 0x140f: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1413:
	/* 0x1413: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1417:
	/* 0x1417: cmp    WORD PTR [r12+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_1421:
	/* 0x1421: je     1443 <generic_sleepable_preload+0x1443> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1443;
	}
x86_l_1423:
	/* 0x1423: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1426:
	/* 0x1426: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_142b:
	/* 0x142b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1430:
	/* 0x1430: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1434:
	/* 0x1434: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1439:
	/* 0x1439: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_143b:
	/* 0x143b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_143d:
	/* 0x143d: js     1cbc <generic_sleepable_preload+0x1cbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7356ULL;
	}
x86_l_1443:
	/* 0x1443: cmp    WORD PTR [r12+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_144d:
	/* 0x144d: je     1cf7 <generic_sleepable_preload+0x1cf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7415ULL;
	}
x86_l_1453:
	/* 0x1453: mov    ecx,DWORD PTR [r12+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_145b:
	/* 0x145b: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_145f:
	/* 0x145f: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1463:
	/* 0x1463: cmp    WORD PTR [r12+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_146d:
	/* 0x146d: je     148f <generic_sleepable_preload+0x148f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_148f;
	}
x86_l_146f:
	/* 0x146f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1472:
	/* 0x1472: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1477:
	/* 0x1477: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_147c:
	/* 0x147c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1480:
	/* 0x1480: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1485:
	/* 0x1485: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1487:
	/* 0x1487: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1489:
	/* 0x1489: js     1ccd <generic_sleepable_preload+0x1ccd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7373ULL;
	}
x86_l_148f:
	/* 0x148f: cmp    WORD PTR [r12+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_1499:
	/* 0x1499: je     1cf7 <generic_sleepable_preload+0x1cf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7415ULL;
	}
x86_l_149f:
	/* 0x149f: mov    ecx,DWORD PTR [r12+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_14a7:
	/* 0x14a7: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_14ab:
	/* 0x14ab: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14af:
	/* 0x14af: cmp    WORD PTR [r12+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_14b9:
	/* 0x14b9: je     14db <generic_sleepable_preload+0x14db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14db;
	}
x86_l_14bb:
	/* 0x14bb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_14be:
	/* 0x14be: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_14c3:
	/* 0x14c3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_14c8:
	/* 0x14c8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14cc:
	/* 0x14cc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14d1:
	/* 0x14d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14d3:
	/* 0x14d3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_14d5:
	/* 0x14d5: js     1cde <generic_sleepable_preload+0x1cde> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7390ULL;
	}
x86_l_14db:
	/* 0x14db: cmp    WORD PTR [r12+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_14e5:
	/* 0x14e5: je     1cf7 <generic_sleepable_preload+0x1cf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7415ULL;
	}
x86_l_14eb:
	/* 0x14eb: mov    ecx,DWORD PTR [r12+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_14f3:
	/* 0x14f3: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_14f7:
	/* 0x14f7: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14fb:
	/* 0x14fb: cmp    WORD PTR [r12+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_1505:
	/* 0x1505: je     1527 <generic_sleepable_preload+0x1527> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1527;
	}
x86_l_1507:
	/* 0x1507: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_150a:
	/* 0x150a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_150f:
	/* 0x150f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1514:
	/* 0x1514: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1518:
	/* 0x1518: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_151d:
	/* 0x151d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_151f:
	/* 0x151f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1521:
	/* 0x1521: js     1cef <generic_sleepable_preload+0x1cef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7407ULL;
	}
x86_l_1527:
	/* 0x1527: cmp    WORD PTR [r12+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_1531:
	/* 0x1531: je     1cf7 <generic_sleepable_preload+0x1cf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7415ULL;
	}
x86_l_1537:
	/* 0x1537: mov    r15,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R14, X86_WIDTH_64);
x86_l_153a:
	/* 0x153a: mov    ecx,DWORD PTR [r12+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1542:
	/* 0x1542: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1546:
	/* 0x1546: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_154a:
	/* 0x154a: cmp    WORD PTR [r12+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_1554:
	/* 0x1554: je     1576 <generic_sleepable_preload+0x1576> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1576;
	}
x86_l_1556:
	/* 0x1556: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1559:
	/* 0x1559: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_155e:
	/* 0x155e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1563:
	/* 0x1563: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1567:
	/* 0x1567: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_156c:
	/* 0x156c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_156e:
	/* 0x156e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1570:
	/* 0x1570: js     5c40 <generic_sleepable_preload+0x5c40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23616ULL;
	}
x86_l_1576:
	/* 0x1576: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_157b:
	/* 0x157b: cmp    WORD PTR [r12+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_1585:
	/* 0x1585: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_1588:
	/* 0x1588: je     1cf7 <generic_sleepable_preload+0x1cf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7415ULL;
	}
x86_l_158e:
	/* 0x158e: mov    ecx,DWORD PTR [r12+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1596:
	/* 0x1596: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_159a:
	/* 0x159a: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_159e:
	/* 0x159e: cmp    WORD PTR [r12+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_15a8:
	/* 0x15a8: je     15ca <generic_sleepable_preload+0x15ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15ca;
	}
x86_l_15aa:
	/* 0x15aa: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_15ad:
	/* 0x15ad: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_15b2:
	/* 0x15b2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_15b7:
	/* 0x15b7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15bb:
	/* 0x15bb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_15c0:
	/* 0x15c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15c2:
	/* 0x15c2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_15c4:
	/* 0x15c4: js     5d38 <generic_sleepable_preload+0x5d38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23864ULL;
	}
x86_l_15ca:
	/* 0x15ca: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15cf:
	/* 0x15cf: cmp    WORD PTR [r12+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_15d9:
	/* 0x15d9: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_15dc:
	/* 0x15dc: je     1cf7 <generic_sleepable_preload+0x1cf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7415ULL;
	}
x86_l_15e2:
	/* 0x15e2: mov    ecx,DWORD PTR [r12+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_15ea:
	/* 0x15ea: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_15ee:
	/* 0x15ee: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15f2:
	/* 0x15f2: cmp    WORD PTR [r12+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_15fc:
	/* 0x15fc: je     1cf7 <generic_sleepable_preload+0x1cf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7415ULL;
	}
x86_l_1602:
	/* 0x1602: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1605:
	/* 0x1605: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_160a:
	/* 0x160a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_160f:
	/* 0x160f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1613:
	/* 0x1613: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1618:
	/* 0x1618: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_161a:
	/* 0x161a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_161c:
	/* 0x161c: jns    1cf7 <generic_sleepable_preload+0x1cf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 7415ULL;
	}
x86_l_1622:
	/* 0x1622: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_1627:
	/* 0x1627: jmp    1cf4 <generic_sleepable_preload+0x1cf4> */
	return 7412ULL;
x86_l_162c:
	/* 0x162c: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_1631:
	/* 0x1631: jmp    1cf4 <generic_sleepable_preload+0x1cf4> */
	return 7412ULL;
x86_l_1636:
	/* 0x1636: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_163e:
	/* 0x163e: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_1641:
	/* 0x1641: je     1692 <generic_sleepable_preload+0x1692> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1692;
	}
x86_l_1643:
	/* 0x1643: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1648:
	/* 0x1648: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_164b:
	/* 0x164b: je     1692 <generic_sleepable_preload+0x1692> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1692;
	}
x86_l_164d:
	/* 0x164d: jmp    16a5 <generic_sleepable_preload+0x16a5> */
	goto x86_l_16a5;
x86_l_164f:
	/* 0x164f: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1654:
	/* 0x1654: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_1657:
	/* 0x1657: je     1692 <generic_sleepable_preload+0x1692> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1692;
	}
x86_l_1659:
	/* 0x1659: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_165e:
	/* 0x165e: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_1661:
	/* 0x1661: je     1692 <generic_sleepable_preload+0x1692> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1692;
	}
x86_l_1663:
	/* 0x1663: jmp    16a5 <generic_sleepable_preload+0x16a5> */
	goto x86_l_16a5;
x86_l_1665:
	/* 0x1665: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_166d:
	/* 0x166d: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_1670:
	/* 0x1670: je     1692 <generic_sleepable_preload+0x1692> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1692;
	}
x86_l_1672:
	/* 0x1672: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1677:
	/* 0x1677: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_167a:
	/* 0x167a: je     1692 <generic_sleepable_preload+0x1692> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1692;
	}
x86_l_167c:
	/* 0x167c: jmp    16a5 <generic_sleepable_preload+0x16a5> */
	goto x86_l_16a5;
x86_l_167e:
	/* 0x167e: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1683:
	/* 0x1683: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_1686:
	/* 0x1686: je     1692 <generic_sleepable_preload+0x1692> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1692;
	}
x86_l_1688:
	/* 0x1688: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_168d:
	/* 0x168d: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1690:
	/* 0x1690: jne    16a5 <generic_sleepable_preload+0x16a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_16a5;
	}
x86_l_1692:
	/* 0x1692: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_1695:
	/* 0x1695: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_1697:
	/* 0x1697: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1699:
	/* 0x1699: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_169e:
	/* 0x169e: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_16a0:
	/* 0x16a0: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_16a5:
	/* 0x16a5: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16a9:
	/* 0x16a9: mov    ebp,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_16ae:
	/* 0x16ae: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16b0:
	/* 0x16b0: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_16b3:
	/* 0x16b3: cmp    WORD PTR [r12+0x76],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 506806140928ULL);
x86_l_16ba:
	/* 0x16ba: je     1d82 <generic_sleepable_preload+0x1d82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7554ULL;
	}
x86_l_16c0:
	/* 0x16c0: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_16c7:
	/* 0x16c7: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_16ca:
	/* 0x16ca: mov    eax,DWORD PTR [r12+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_16cf:
	/* 0x16cf: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_16d2:
	/* 0x16d2: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16d6:
	/* 0x16d6: movzx  eax,WORD PTR [r12+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 116ULL);
x86_l_16dc:
	/* 0x16dc: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_16de:
	/* 0x16de: je     19a7 <generic_sleepable_preload+0x19a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19a7;
	}
x86_l_16e4:
	/* 0x16e4: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_16e7:
	/* 0x16e7: je     1709 <generic_sleepable_preload+0x1709> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1709;
	}
x86_l_16e9:
	/* 0x16e9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_16ec:
	/* 0x16ec: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_16f1:
	/* 0x16f1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_16f6:
	/* 0x16f6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16fa:
	/* 0x16fa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16ff:
	/* 0x16ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1701:
	/* 0x1701: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1703:
	/* 0x1703: js     1c90 <generic_sleepable_preload+0x1c90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7312ULL;
	}
x86_l_1709:
	/* 0x1709: cmp    WORD PTR [r12+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_1710:
	/* 0x1710: je     1d82 <generic_sleepable_preload+0x1d82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7554ULL;
	}
x86_l_1716:
	/* 0x1716: mov    ecx,DWORD PTR [r12+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_171b:
	/* 0x171b: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_171f:
	/* 0x171f: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1723:
	/* 0x1723: cmp    WORD PTR [r12+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_172a:
	/* 0x172a: je     174c <generic_sleepable_preload+0x174c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_174c;
	}
x86_l_172c:
	/* 0x172c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_172f:
	/* 0x172f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1734:
	/* 0x1734: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1739:
	/* 0x1739: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_173d:
	/* 0x173d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1742:
	/* 0x1742: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1744:
	/* 0x1744: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1746:
	/* 0x1746: js     1ca1 <generic_sleepable_preload+0x1ca1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7329ULL;
	}
x86_l_174c:
	/* 0x174c: cmp    WORD PTR [r12+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_1756:
	/* 0x1756: je     1d82 <generic_sleepable_preload+0x1d82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7554ULL;
	}
x86_l_175c:
	/* 0x175c: mov    ecx,DWORD PTR [r12+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1764:
	/* 0x1764: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1768:
	/* 0x1768: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_176c:
	/* 0x176c: cmp    WORD PTR [r12+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_1776:
	/* 0x1776: je     1798 <generic_sleepable_preload+0x1798> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1798;
	}
x86_l_1778:
	/* 0x1778: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_177b:
	/* 0x177b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1780:
	/* 0x1780: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1785:
	/* 0x1785: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1789:
	/* 0x1789: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_178e:
	/* 0x178e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1790:
	/* 0x1790: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1792:
	/* 0x1792: js     1cb2 <generic_sleepable_preload+0x1cb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7346ULL;
	}
x86_l_1798:
	/* 0x1798: cmp    WORD PTR [r12+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_17a2:
	/* 0x17a2: je     1d82 <generic_sleepable_preload+0x1d82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7554ULL;
	}
x86_l_17a8:
	/* 0x17a8: mov    ecx,DWORD PTR [r12+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_17b0:
	/* 0x17b0: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_17b4:
	/* 0x17b4: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17b8:
	/* 0x17b8: cmp    WORD PTR [r12+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_17c2:
	/* 0x17c2: je     17e4 <generic_sleepable_preload+0x17e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17e4;
	}
x86_l_17c4:
	/* 0x17c4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_17c7:
	/* 0x17c7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_17cc:
	/* 0x17cc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_17d1:
	/* 0x17d1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17d5:
	/* 0x17d5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17da:
	/* 0x17da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17dc:
	/* 0x17dc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_17de:
	/* 0x17de: js     1cc3 <generic_sleepable_preload+0x1cc3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7363ULL;
	}
x86_l_17e4:
	/* 0x17e4: cmp    WORD PTR [r12+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_17ee:
	/* 0x17ee: je     1d82 <generic_sleepable_preload+0x1d82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7554ULL;
	}
x86_l_17f4:
	/* 0x17f4: mov    ecx,DWORD PTR [r12+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_17fc:
	/* 0x17fc: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1800:
	/* 0x1800: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1804:
	/* 0x1804: cmp    WORD PTR [r12+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_180e:
	/* 0x180e: je     1830 <generic_sleepable_preload+0x1830> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1830;
	}
x86_l_1810:
	/* 0x1810: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1813:
	/* 0x1813: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1818:
	/* 0x1818: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_181d:
	/* 0x181d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1821:
	/* 0x1821: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1826:
	/* 0x1826: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1828:
	/* 0x1828: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_182a:
	/* 0x182a: js     1cd4 <generic_sleepable_preload+0x1cd4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7380ULL;
	}
x86_l_1830:
	/* 0x1830: cmp    WORD PTR [r12+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_183a:
	/* 0x183a: je     1d82 <generic_sleepable_preload+0x1d82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7554ULL;
	}
x86_l_1840:
	/* 0x1840: mov    ecx,DWORD PTR [r12+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1848:
	/* 0x1848: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_184c:
	/* 0x184c: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1850:
	/* 0x1850: cmp    WORD PTR [r12+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_185a:
	/* 0x185a: je     187c <generic_sleepable_preload+0x187c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_187c;
	}
x86_l_185c:
	/* 0x185c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_185f:
	/* 0x185f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1864:
	/* 0x1864: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1869:
	/* 0x1869: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_186d:
	/* 0x186d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1872:
	/* 0x1872: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1874:
	/* 0x1874: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1876:
	/* 0x1876: js     1ce5 <generic_sleepable_preload+0x1ce5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7397ULL;
	}
x86_l_187c:
	/* 0x187c: cmp    WORD PTR [r12+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_1886:
	/* 0x1886: je     1d82 <generic_sleepable_preload+0x1d82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7554ULL;
	}
x86_l_188c:
	/* 0x188c: mov    ecx,DWORD PTR [r12+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1894:
	/* 0x1894: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1898:
	/* 0x1898: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_189c:
	/* 0x189c: cmp    WORD PTR [r12+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_18a6:
	/* 0x18a6: je     18c8 <generic_sleepable_preload+0x18c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18c8;
	}
x86_l_18a8:
	/* 0x18a8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_18ab:
	/* 0x18ab: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_18b0:
	/* 0x18b0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_18b5:
	/* 0x18b5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18b9:
	/* 0x18b9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18be:
	/* 0x18be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18c0:
	/* 0x18c0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_18c2:
	/* 0x18c2: js     1d7a <generic_sleepable_preload+0x1d7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7546ULL;
	}
x86_l_18c8:
	/* 0x18c8: cmp    WORD PTR [r12+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_18d2:
	/* 0x18d2: je     1d82 <generic_sleepable_preload+0x1d82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7554ULL;
	}
x86_l_18d8:
	/* 0x18d8: mov    ecx,DWORD PTR [r12+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_18e0:
	/* 0x18e0: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_18e4:
	/* 0x18e4: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18e8:
	/* 0x18e8: cmp    WORD PTR [r12+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_18f2:
	/* 0x18f2: je     1914 <generic_sleepable_preload+0x1914> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1914;
	}
x86_l_18f4:
	/* 0x18f4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_18f7:
	/* 0x18f7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_18fc:
	/* 0x18fc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1901:
	/* 0x1901: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1905:
	/* 0x1905: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_190a:
	/* 0x190a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_190c:
	/* 0x190c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_190e:
	/* 0x190e: js     5bcf <generic_sleepable_preload+0x5bcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23503ULL;
	}
x86_l_1914:
	/* 0x1914: cmp    WORD PTR [r12+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_191e:
	/* 0x191e: je     1d82 <generic_sleepable_preload+0x1d82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7554ULL;
	}
x86_l_1924:
	/* 0x1924: mov    ecx,DWORD PTR [r12+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_192c:
	/* 0x192c: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1930:
	/* 0x1930: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1934:
	/* 0x1934: cmp    WORD PTR [r12+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_193e:
	/* 0x193e: je     1960 <generic_sleepable_preload+0x1960> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1960;
	}
x86_l_1940:
	/* 0x1940: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1943:
	/* 0x1943: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1948:
	/* 0x1948: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_194d:
	/* 0x194d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1951:
	/* 0x1951: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1956:
	/* 0x1956: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1958:
	/* 0x1958: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_195a:
	/* 0x195a: js     5cba <generic_sleepable_preload+0x5cba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23738ULL;
	}
x86_l_1960:
	/* 0x1960: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1965:
	/* 0x1965: cmp    WORD PTR [r12+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_196f:
	/* 0x196f: je     1d82 <generic_sleepable_preload+0x1d82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7554ULL;
	}
x86_l_1975:
	/* 0x1975: mov    ecx,DWORD PTR [r12+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_197d:
	/* 0x197d: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1981:
	/* 0x1981: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1985:
	/* 0x1985: cmp    WORD PTR [r12+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_198f:
	/* 0x198f: je     1d82 <generic_sleepable_preload+0x1d82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7554ULL;
	}
x86_l_1995:
	/* 0x1995: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1998:
	/* 0x1998: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_199d:
	/* 0x199d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_19a2:
	/* 0x19a2: jmp    1c73 <generic_sleepable_preload+0x1c73> */
	return 7283ULL;
x86_l_19a7:
	/* 0x19a7: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_19aa:
	/* 0x19aa: je     19cc <generic_sleepable_preload+0x19cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19cc;
	}
x86_l_19ac:
	/* 0x19ac: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_19af:
	/* 0x19af: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_19b4:
	/* 0x19b4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_19b9:
	/* 0x19b9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19bd:
	/* 0x19bd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19c2:
	/* 0x19c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19c4:
	/* 0x19c4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_19c6:
	/* 0x19c6: js     1c90 <generic_sleepable_preload+0x1c90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7312ULL;
	}
x86_l_19cc:
	/* 0x19cc: cmp    WORD PTR [r12+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_19d3:
	/* 0x19d3: je     1d82 <generic_sleepable_preload+0x1d82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7554ULL;
	}
x86_l_19d9:
	/* 0x19d9: mov    ecx,DWORD PTR [r12+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_19de:
	/* 0x19de: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_19e2:
	/* 0x19e2: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19e6:
	/* 0x19e6: cmp    WORD PTR [r12+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_19ed:
	/* 0x19ed: je     1a0f <generic_sleepable_preload+0x1a0f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a0f;
	}
x86_l_19ef:
	/* 0x19ef: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_19f2:
	/* 0x19f2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_19f7:
	/* 0x19f7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_19fc:
	/* 0x19fc: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a00:
	/* 0x1a00: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a05:
	/* 0x1a05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a07:
	/* 0x1a07: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a09:
	/* 0x1a09: js     1ca1 <generic_sleepable_preload+0x1ca1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7329ULL;
	}
x86_l_1a0f:
	/* 0x1a0f: cmp    WORD PTR [r12+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_1a19:
	/* 0x1a19: je     1d82 <generic_sleepable_preload+0x1d82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7554ULL;
	}
x86_l_1a1f:
	/* 0x1a1f: mov    ecx,DWORD PTR [r12+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1a27:
	/* 0x1a27: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1a2b:
	/* 0x1a2b: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a2f:
	/* 0x1a2f: cmp    WORD PTR [r12+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_1a39:
	/* 0x1a39: je     1a5b <generic_sleepable_preload+0x1a5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a5b;
	}
x86_l_1a3b:
	/* 0x1a3b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1a3e:
	/* 0x1a3e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1a43:
	/* 0x1a43: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1a48:
	/* 0x1a48: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a4c:
	/* 0x1a4c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a51:
	/* 0x1a51: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a53:
	/* 0x1a53: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a55:
	/* 0x1a55: js     1cb2 <generic_sleepable_preload+0x1cb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7346ULL;
	}
x86_l_1a5b:
	/* 0x1a5b: cmp    WORD PTR [r12+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_1a65:
	/* 0x1a65: je     1d82 <generic_sleepable_preload+0x1d82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7554ULL;
	}
x86_l_1a6b:
	/* 0x1a6b: mov    ecx,DWORD PTR [r12+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1a73:
	/* 0x1a73: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
	return 6775ULL;
}

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 6775ULL: goto x86_l_1a77;
	case 6779ULL: goto x86_l_1a7b;
	case 6789ULL: goto x86_l_1a85;
	case 6791ULL: goto x86_l_1a87;
	case 6794ULL: goto x86_l_1a8a;
	case 6799ULL: goto x86_l_1a8f;
	case 6804ULL: goto x86_l_1a94;
	case 6808ULL: goto x86_l_1a98;
	case 6813ULL: goto x86_l_1a9d;
	case 6815ULL: goto x86_l_1a9f;
	case 6817ULL: goto x86_l_1aa1;
	case 6823ULL: goto x86_l_1aa7;
	case 6833ULL: goto x86_l_1ab1;
	case 6839ULL: goto x86_l_1ab7;
	case 6847ULL: goto x86_l_1abf;
	case 6851ULL: goto x86_l_1ac3;
	case 6855ULL: goto x86_l_1ac7;
	case 6865ULL: goto x86_l_1ad1;
	case 6867ULL: goto x86_l_1ad3;
	case 6870ULL: goto x86_l_1ad6;
	case 6875ULL: goto x86_l_1adb;
	case 6880ULL: goto x86_l_1ae0;
	case 6884ULL: goto x86_l_1ae4;
	case 6889ULL: goto x86_l_1ae9;
	case 6891ULL: goto x86_l_1aeb;
	case 6893ULL: goto x86_l_1aed;
	case 6899ULL: goto x86_l_1af3;
	case 6909ULL: goto x86_l_1afd;
	case 6915ULL: goto x86_l_1b03;
	case 6923ULL: goto x86_l_1b0b;
	case 6927ULL: goto x86_l_1b0f;
	case 6931ULL: goto x86_l_1b13;
	case 6941ULL: goto x86_l_1b1d;
	case 6943ULL: goto x86_l_1b1f;
	case 6946ULL: goto x86_l_1b22;
	case 6951ULL: goto x86_l_1b27;
	case 6956ULL: goto x86_l_1b2c;
	case 6960ULL: goto x86_l_1b30;
	case 6965ULL: goto x86_l_1b35;
	case 6967ULL: goto x86_l_1b37;
	case 6969ULL: goto x86_l_1b39;
	case 6975ULL: goto x86_l_1b3f;
	case 6985ULL: goto x86_l_1b49;
	case 6991ULL: goto x86_l_1b4f;
	case 6999ULL: goto x86_l_1b57;
	case 7003ULL: goto x86_l_1b5b;
	case 7007ULL: goto x86_l_1b5f;
	case 7017ULL: goto x86_l_1b69;
	case 7019ULL: goto x86_l_1b6b;
	case 7022ULL: goto x86_l_1b6e;
	case 7027ULL: goto x86_l_1b73;
	case 7032ULL: goto x86_l_1b78;
	case 7036ULL: goto x86_l_1b7c;
	case 7041ULL: goto x86_l_1b81;
	case 7043ULL: goto x86_l_1b83;
	case 7045ULL: goto x86_l_1b85;
	case 7051ULL: goto x86_l_1b8b;
	case 7061ULL: goto x86_l_1b95;
	case 7067ULL: goto x86_l_1b9b;
	case 7070ULL: goto x86_l_1b9e;
	case 7078ULL: goto x86_l_1ba6;
	case 7082ULL: goto x86_l_1baa;
	case 7086ULL: goto x86_l_1bae;
	case 7096ULL: goto x86_l_1bb8;
	case 7098ULL: goto x86_l_1bba;
	case 7101ULL: goto x86_l_1bbd;
	case 7106ULL: goto x86_l_1bc2;
	case 7111ULL: goto x86_l_1bc7;
	case 7115ULL: goto x86_l_1bcb;
	case 7120ULL: goto x86_l_1bd0;
	case 7122ULL: goto x86_l_1bd2;
	case 7124ULL: goto x86_l_1bd4;
	case 7130ULL: goto x86_l_1bda;
	case 7135ULL: goto x86_l_1bdf;
	case 7145ULL: goto x86_l_1be9;
	case 7148ULL: goto x86_l_1bec;
	case 7154ULL: goto x86_l_1bf2;
	case 7162ULL: goto x86_l_1bfa;
	case 7166ULL: goto x86_l_1bfe;
	case 7170ULL: goto x86_l_1c02;
	case 7180ULL: goto x86_l_1c0c;
	case 7182ULL: goto x86_l_1c0e;
	case 7185ULL: goto x86_l_1c11;
	case 7190ULL: goto x86_l_1c16;
	case 7195ULL: goto x86_l_1c1b;
	case 7199ULL: goto x86_l_1c1f;
	case 7204ULL: goto x86_l_1c24;
	case 7206ULL: goto x86_l_1c26;
	case 7208ULL: goto x86_l_1c28;
	case 7214ULL: goto x86_l_1c2e;
	case 7219ULL: goto x86_l_1c33;
	case 7229ULL: goto x86_l_1c3d;
	case 7232ULL: goto x86_l_1c40;
	case 7238ULL: goto x86_l_1c46;
	case 7246ULL: goto x86_l_1c4e;
	case 7250ULL: goto x86_l_1c52;
	case 7254ULL: goto x86_l_1c56;
	case 7264ULL: goto x86_l_1c60;
	case 7270ULL: goto x86_l_1c66;
	case 7273ULL: goto x86_l_1c69;
	case 7278ULL: goto x86_l_1c6e;
	case 7283ULL: goto x86_l_1c73;
	case 7287ULL: goto x86_l_1c77;
	case 7292ULL: goto x86_l_1c7c;
	case 7294ULL: goto x86_l_1c7e;
	case 7296ULL: goto x86_l_1c80;
	case 7302ULL: goto x86_l_1c86;
	case 7307ULL: goto x86_l_1c8b;
	case 7312ULL: goto x86_l_1c90;
	case 7317ULL: goto x86_l_1c95;
	case 7322ULL: goto x86_l_1c9a;
	case 7327ULL: goto x86_l_1c9f;
	case 7329ULL: goto x86_l_1ca1;
	case 7334ULL: goto x86_l_1ca6;
	case 7339ULL: goto x86_l_1cab;
	case 7344ULL: goto x86_l_1cb0;
	case 7346ULL: goto x86_l_1cb2;
	case 7351ULL: goto x86_l_1cb7;
	case 7356ULL: goto x86_l_1cbc;
	case 7361ULL: goto x86_l_1cc1;
	case 7363ULL: goto x86_l_1cc3;
	case 7368ULL: goto x86_l_1cc8;
	case 7373ULL: goto x86_l_1ccd;
	case 7378ULL: goto x86_l_1cd2;
	case 7380ULL: goto x86_l_1cd4;
	case 7385ULL: goto x86_l_1cd9;
	case 7390ULL: goto x86_l_1cde;
	case 7395ULL: goto x86_l_1ce3;
	case 7397ULL: goto x86_l_1ce5;
	case 7402ULL: goto x86_l_1cea;
	case 7407ULL: goto x86_l_1cef;
	case 7412ULL: goto x86_l_1cf4;
	case 7415ULL: goto x86_l_1cf7;
	case 7420ULL: goto x86_l_1cfc;
	case 7423ULL: goto x86_l_1cff;
	case 7428ULL: goto x86_l_1d04;
	case 7433ULL: goto x86_l_1d09;
	case 7438ULL: goto x86_l_1d0e;
	case 7441ULL: goto x86_l_1d11;
	case 7443ULL: goto x86_l_1d13;
	case 7446ULL: goto x86_l_1d16;
	case 7452ULL: goto x86_l_1d1c;
	case 7455ULL: goto x86_l_1d1f;
	case 7459ULL: goto x86_l_1d23;
	case 7464ULL: goto x86_l_1d28;
	case 7466ULL: goto x86_l_1d2a;
	case 7471ULL: goto x86_l_1d2f;
	case 7479ULL: goto x86_l_1d37;
	case 7486ULL: goto x86_l_1d3e;
	case 7491ULL: goto x86_l_1d43;
	case 7496ULL: goto x86_l_1d48;
	case 7498ULL: goto x86_l_1d4a;
	case 7501ULL: goto x86_l_1d4d;
	case 7507ULL: goto x86_l_1d53;
	case 7510ULL: goto x86_l_1d56;
	case 7517ULL: goto x86_l_1d5d;
	case 7519ULL: goto x86_l_1d5f;
	case 7524ULL: goto x86_l_1d64;
	case 7529ULL: goto x86_l_1d69;
	case 7532ULL: goto x86_l_1d6c;
	case 7535ULL: goto x86_l_1d6f;
	case 7537ULL: goto x86_l_1d71;
	case 7539ULL: goto x86_l_1d73;
	case 7544ULL: goto x86_l_1d78;
	case 7546ULL: goto x86_l_1d7a;
	case 7551ULL: goto x86_l_1d7f;
	case 7554ULL: goto x86_l_1d82;
	case 7557ULL: goto x86_l_1d85;
	case 7563ULL: goto x86_l_1d8b;
	case 7566ULL: goto x86_l_1d8e;
	case 7570ULL: goto x86_l_1d92;
	case 7575ULL: goto x86_l_1d97;
	case 7577ULL: goto x86_l_1d99;
	case 7582ULL: goto x86_l_1d9e;
	case 7590ULL: goto x86_l_1da6;
	case 7597ULL: goto x86_l_1dad;
	case 7602ULL: goto x86_l_1db2;
	case 7607ULL: goto x86_l_1db7;
	case 7609ULL: goto x86_l_1db9;
	case 7612ULL: goto x86_l_1dbc;
	case 7614ULL: goto x86_l_1dbe;
	case 7617ULL: goto x86_l_1dc1;
	case 7624ULL: goto x86_l_1dc8;
	case 7626ULL: goto x86_l_1dca;
	case 7631ULL: goto x86_l_1dcf;
	case 7636ULL: goto x86_l_1dd4;
	case 7639ULL: goto x86_l_1dd7;
	case 7642ULL: goto x86_l_1dda;
	case 7644ULL: goto x86_l_1ddc;
	case 7646ULL: goto x86_l_1dde;
	case 7651ULL: goto x86_l_1de3;
	case 7654ULL: goto x86_l_1de6;
	case 7657ULL: goto x86_l_1de9;
	case 7662ULL: goto x86_l_1dee;
	case 7664ULL: goto x86_l_1df0;
	case 7667ULL: goto x86_l_1df3;
	case 7669ULL: goto x86_l_1df5;
	case 7672ULL: goto x86_l_1df8;
	case 7674ULL: goto x86_l_1dfa;
	case 7677ULL: goto x86_l_1dfd;
	case 7681ULL: goto x86_l_1e01;
	case 7686ULL: goto x86_l_1e06;
	case 7689ULL: goto x86_l_1e09;
	case 7691ULL: goto x86_l_1e0b;
	case 7694ULL: goto x86_l_1e0e;
	case 7699ULL: goto x86_l_1e13;
	case 7701ULL: goto x86_l_1e15;
	case 7704ULL: goto x86_l_1e18;
	case 7706ULL: goto x86_l_1e1a;
	case 7708ULL: goto x86_l_1e1c;
	case 7713ULL: goto x86_l_1e21;
	case 7715ULL: goto x86_l_1e23;
	case 7718ULL: goto x86_l_1e26;
	case 7723ULL: goto x86_l_1e2b;
	case 7728ULL: goto x86_l_1e30;
	case 7734ULL: goto x86_l_1e36;
	case 7736ULL: goto x86_l_1e38;
	case 7738ULL: goto x86_l_1e3a;
	case 7743ULL: goto x86_l_1e3f;
	case 7746ULL: goto x86_l_1e42;
	case 7752ULL: goto x86_l_1e48;
	case 7755ULL: goto x86_l_1e4b;
	case 7761ULL: goto x86_l_1e51;
	case 7764ULL: goto x86_l_1e54;
	case 7770ULL: goto x86_l_1e5a;
	case 7773ULL: goto x86_l_1e5d;
	case 7779ULL: goto x86_l_1e63;
	case 7784ULL: goto x86_l_1e68;
	case 7789ULL: goto x86_l_1e6d;
	case 7798ULL: goto x86_l_1e76;
	case 7807ULL: goto x86_l_1e7f;
	case 7813ULL: goto x86_l_1e85;
	case 7815ULL: goto x86_l_1e87;
	case 7818ULL: goto x86_l_1e8a;
	case 7820ULL: goto x86_l_1e8c;
	case 7823ULL: goto x86_l_1e8f;
	case 7825ULL: goto x86_l_1e91;
	case 7828ULL: goto x86_l_1e94;
	case 7834ULL: goto x86_l_1e9a;
	case 7839ULL: goto x86_l_1e9f;
	case 7842ULL: goto x86_l_1ea2;
	case 7848ULL: goto x86_l_1ea8;
	case 7853ULL: goto x86_l_1ead;
	case 7856ULL: goto x86_l_1eb0;
	case 7862ULL: goto x86_l_1eb6;
	case 7867ULL: goto x86_l_1ebb;
	case 7870ULL: goto x86_l_1ebe;
	case 7876ULL: goto x86_l_1ec4;
	case 7881ULL: goto x86_l_1ec9;
	case 7884ULL: goto x86_l_1ecc;
	case 7886ULL: goto x86_l_1ece;
	case 7889ULL: goto x86_l_1ed1;
	case 7895ULL: goto x86_l_1ed7;
	case 7897ULL: goto x86_l_1ed9;
	case 7903ULL: goto x86_l_1edf;
	case 7906ULL: goto x86_l_1ee2;
	case 7909ULL: goto x86_l_1ee5;
	case 7915ULL: goto x86_l_1eeb;
	case 7920ULL: goto x86_l_1ef0;
	case 7922ULL: goto x86_l_1ef2;
	case 7924ULL: goto x86_l_1ef4;
	case 7927ULL: goto x86_l_1ef7;
	case 7929ULL: goto x86_l_1ef9;
	case 7934ULL: goto x86_l_1efe;
	case 7936ULL: goto x86_l_1f00;
	case 7939ULL: goto x86_l_1f03;
	case 7945ULL: goto x86_l_1f09;
	case 7953ULL: goto x86_l_1f11;
	case 7956ULL: goto x86_l_1f14;
	case 7962ULL: goto x86_l_1f1a;
	case 7967ULL: goto x86_l_1f1f;
	case 7970ULL: goto x86_l_1f22;
	case 7976ULL: goto x86_l_1f28;
	case 7981ULL: goto x86_l_1f2d;
	case 7984ULL: goto x86_l_1f30;
	case 7990ULL: goto x86_l_1f36;
	case 7998ULL: goto x86_l_1f3e;
	case 8001ULL: goto x86_l_1f41;
	case 8007ULL: goto x86_l_1f47;
	case 8012ULL: goto x86_l_1f4c;
	case 8015ULL: goto x86_l_1f4f;
	case 8021ULL: goto x86_l_1f55;
	case 8026ULL: goto x86_l_1f5a;
	case 8031ULL: goto x86_l_1f5f;
	case 8033ULL: goto x86_l_1f61;
	case 8038ULL: goto x86_l_1f66;
	case 8040ULL: goto x86_l_1f68;
	case 8045ULL: goto x86_l_1f6d;
	case 8048ULL: goto x86_l_1f70;
	case 8052ULL: goto x86_l_1f74;
	case 8054ULL: goto x86_l_1f76;
	case 8057ULL: goto x86_l_1f79;
	case 8067ULL: goto x86_l_1f83;
	case 8073ULL: goto x86_l_1f89;
	case 8080ULL: goto x86_l_1f90;
	case 8083ULL: goto x86_l_1f93;
	case 8091ULL: goto x86_l_1f9b;
	case 8094ULL: goto x86_l_1f9e;
	case 8098ULL: goto x86_l_1fa2;
	case 8107ULL: goto x86_l_1fab;
	case 8109ULL: goto x86_l_1fad;
	case 8115ULL: goto x86_l_1fb3;
	case 8118ULL: goto x86_l_1fb6;
	case 8120ULL: goto x86_l_1fb8;
	case 8123ULL: goto x86_l_1fbb;
	case 8128ULL: goto x86_l_1fc0;
	case 8133ULL: goto x86_l_1fc5;
	case 8137ULL: goto x86_l_1fc9;
	case 8142ULL: goto x86_l_1fce;
	case 8144ULL: goto x86_l_1fd0;
	case 8146ULL: goto x86_l_1fd2;
	case 8152ULL: goto x86_l_1fd8;
	case 8162ULL: goto x86_l_1fe2;
	case 8168ULL: goto x86_l_1fe8;
	case 8176ULL: goto x86_l_1ff0;
	case 8180ULL: goto x86_l_1ff4;
	case 8184ULL: goto x86_l_1ff8;
	case 8194ULL: goto x86_l_2002;
	case 8196ULL: goto x86_l_2004;
	case 8199ULL: goto x86_l_2007;
	case 8204ULL: goto x86_l_200c;
	case 8209ULL: goto x86_l_2011;
	case 8213ULL: goto x86_l_2015;
	case 8218ULL: goto x86_l_201a;
	case 8220ULL: goto x86_l_201c;
	case 8222ULL: goto x86_l_201e;
	case 8228ULL: goto x86_l_2024;
	case 8238ULL: goto x86_l_202e;
	case 8244ULL: goto x86_l_2034;
	case 8252ULL: goto x86_l_203c;
	case 8256ULL: goto x86_l_2040;
	case 8260ULL: goto x86_l_2044;
	case 8270ULL: goto x86_l_204e;
	case 8272ULL: goto x86_l_2050;
	case 8275ULL: goto x86_l_2053;
	case 8280ULL: goto x86_l_2058;
	case 8285ULL: goto x86_l_205d;
	case 8289ULL: goto x86_l_2061;
	case 8294ULL: goto x86_l_2066;
	case 8296ULL: goto x86_l_2068;
	case 8298ULL: goto x86_l_206a;
	case 8304ULL: goto x86_l_2070;
	case 8314ULL: goto x86_l_207a;
	case 8320ULL: goto x86_l_2080;
	case 8328ULL: goto x86_l_2088;
	case 8332ULL: goto x86_l_208c;
	case 8336ULL: goto x86_l_2090;
	case 8346ULL: goto x86_l_209a;
	case 8348ULL: goto x86_l_209c;
	case 8351ULL: goto x86_l_209f;
	case 8356ULL: goto x86_l_20a4;
	case 8361ULL: goto x86_l_20a9;
	case 8365ULL: goto x86_l_20ad;
	case 8370ULL: goto x86_l_20b2;
	case 8372ULL: goto x86_l_20b4;
	case 8374ULL: goto x86_l_20b6;
	case 8380ULL: goto x86_l_20bc;
	case 8390ULL: goto x86_l_20c6;
	case 8396ULL: goto x86_l_20cc;
	case 8404ULL: goto x86_l_20d4;
	case 8408ULL: goto x86_l_20d8;
	case 8412ULL: goto x86_l_20dc;
	case 8422ULL: goto x86_l_20e6;
	case 8424ULL: goto x86_l_20e8;
	case 8427ULL: goto x86_l_20eb;
	case 8432ULL: goto x86_l_20f0;
	case 8437ULL: goto x86_l_20f5;
	case 8441ULL: goto x86_l_20f9;
	case 8446ULL: goto x86_l_20fe;
	case 8448ULL: goto x86_l_2100;
	case 8450ULL: goto x86_l_2102;
	case 8456ULL: goto x86_l_2108;
	case 8466ULL: goto x86_l_2112;
	case 8472ULL: goto x86_l_2118;
	case 8480ULL: goto x86_l_2120;
	case 8484ULL: goto x86_l_2124;
	case 8488ULL: goto x86_l_2128;
	case 8498ULL: goto x86_l_2132;
	case 8500ULL: goto x86_l_2134;
	case 8503ULL: goto x86_l_2137;
	case 8508ULL: goto x86_l_213c;
	case 8513ULL: goto x86_l_2141;
	case 8517ULL: goto x86_l_2145;
	case 8522ULL: goto x86_l_214a;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1a77:
	/* 0x1a77: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a7b:
	/* 0x1a7b: cmp    WORD PTR [r12+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_1a85:
	/* 0x1a85: je     1aa7 <generic_sleepable_preload+0x1aa7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1aa7;
	}
x86_l_1a87:
	/* 0x1a87: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1a8a:
	/* 0x1a8a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1a8f:
	/* 0x1a8f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1a94:
	/* 0x1a94: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a98:
	/* 0x1a98: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a9d:
	/* 0x1a9d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a9f:
	/* 0x1a9f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1aa1:
	/* 0x1aa1: js     1cc3 <generic_sleepable_preload+0x1cc3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1cc3;
	}
x86_l_1aa7:
	/* 0x1aa7: cmp    WORD PTR [r12+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_1ab1:
	/* 0x1ab1: je     1d82 <generic_sleepable_preload+0x1d82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d82;
	}
x86_l_1ab7:
	/* 0x1ab7: mov    ecx,DWORD PTR [r12+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1abf:
	/* 0x1abf: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1ac3:
	/* 0x1ac3: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ac7:
	/* 0x1ac7: cmp    WORD PTR [r12+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_1ad1:
	/* 0x1ad1: je     1af3 <generic_sleepable_preload+0x1af3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1af3;
	}
x86_l_1ad3:
	/* 0x1ad3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1ad6:
	/* 0x1ad6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1adb:
	/* 0x1adb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1ae0:
	/* 0x1ae0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ae4:
	/* 0x1ae4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ae9:
	/* 0x1ae9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aeb:
	/* 0x1aeb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1aed:
	/* 0x1aed: js     1cd4 <generic_sleepable_preload+0x1cd4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1cd4;
	}
x86_l_1af3:
	/* 0x1af3: cmp    WORD PTR [r12+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_1afd:
	/* 0x1afd: je     1d82 <generic_sleepable_preload+0x1d82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d82;
	}
x86_l_1b03:
	/* 0x1b03: mov    ecx,DWORD PTR [r12+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1b0b:
	/* 0x1b0b: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1b0f:
	/* 0x1b0f: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b13:
	/* 0x1b13: cmp    WORD PTR [r12+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_1b1d:
	/* 0x1b1d: je     1b3f <generic_sleepable_preload+0x1b3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b3f;
	}
x86_l_1b1f:
	/* 0x1b1f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1b22:
	/* 0x1b22: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1b27:
	/* 0x1b27: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1b2c:
	/* 0x1b2c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b30:
	/* 0x1b30: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b35:
	/* 0x1b35: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b37:
	/* 0x1b37: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1b39:
	/* 0x1b39: js     1ce5 <generic_sleepable_preload+0x1ce5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1ce5;
	}
x86_l_1b3f:
	/* 0x1b3f: cmp    WORD PTR [r12+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_1b49:
	/* 0x1b49: je     1d82 <generic_sleepable_preload+0x1d82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d82;
	}
x86_l_1b4f:
	/* 0x1b4f: mov    ecx,DWORD PTR [r12+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1b57:
	/* 0x1b57: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1b5b:
	/* 0x1b5b: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b5f:
	/* 0x1b5f: cmp    WORD PTR [r12+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_1b69:
	/* 0x1b69: je     1b8b <generic_sleepable_preload+0x1b8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b8b;
	}
x86_l_1b6b:
	/* 0x1b6b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1b6e:
	/* 0x1b6e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1b73:
	/* 0x1b73: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1b78:
	/* 0x1b78: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b7c:
	/* 0x1b7c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b81:
	/* 0x1b81: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b83:
	/* 0x1b83: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1b85:
	/* 0x1b85: js     1d7a <generic_sleepable_preload+0x1d7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1d7a;
	}
x86_l_1b8b:
	/* 0x1b8b: cmp    WORD PTR [r12+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_1b95:
	/* 0x1b95: je     1d82 <generic_sleepable_preload+0x1d82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d82;
	}
x86_l_1b9b:
	/* 0x1b9b: mov    r15,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R14, X86_WIDTH_64);
x86_l_1b9e:
	/* 0x1b9e: mov    ecx,DWORD PTR [r12+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1ba6:
	/* 0x1ba6: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1baa:
	/* 0x1baa: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bae:
	/* 0x1bae: cmp    WORD PTR [r12+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_1bb8:
	/* 0x1bb8: je     1bda <generic_sleepable_preload+0x1bda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bda;
	}
x86_l_1bba:
	/* 0x1bba: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1bbd:
	/* 0x1bbd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1bc2:
	/* 0x1bc2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1bc7:
	/* 0x1bc7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bcb:
	/* 0x1bcb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bd0:
	/* 0x1bd0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bd2:
	/* 0x1bd2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1bd4:
	/* 0x1bd4: js     5c4d <generic_sleepable_preload+0x5c4d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23629ULL;
	}
x86_l_1bda:
	/* 0x1bda: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bdf:
	/* 0x1bdf: cmp    WORD PTR [r12+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_1be9:
	/* 0x1be9: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_1bec:
	/* 0x1bec: je     1d82 <generic_sleepable_preload+0x1d82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d82;
	}
x86_l_1bf2:
	/* 0x1bf2: mov    ecx,DWORD PTR [r12+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1bfa:
	/* 0x1bfa: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1bfe:
	/* 0x1bfe: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c02:
	/* 0x1c02: cmp    WORD PTR [r12+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_1c0c:
	/* 0x1c0c: je     1c2e <generic_sleepable_preload+0x1c2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c2e;
	}
x86_l_1c0e:
	/* 0x1c0e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1c11:
	/* 0x1c11: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1c16:
	/* 0x1c16: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1c1b:
	/* 0x1c1b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c1f:
	/* 0x1c1f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c24:
	/* 0x1c24: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c26:
	/* 0x1c26: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c28:
	/* 0x1c28: js     5d4d <generic_sleepable_preload+0x5d4d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23885ULL;
	}
x86_l_1c2e:
	/* 0x1c2e: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c33:
	/* 0x1c33: cmp    WORD PTR [r12+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_1c3d:
	/* 0x1c3d: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_1c40:
	/* 0x1c40: je     1d82 <generic_sleepable_preload+0x1d82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d82;
	}
x86_l_1c46:
	/* 0x1c46: mov    ecx,DWORD PTR [r12+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1c4e:
	/* 0x1c4e: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1c52:
	/* 0x1c52: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c56:
	/* 0x1c56: cmp    WORD PTR [r12+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_1c60:
	/* 0x1c60: je     1d82 <generic_sleepable_preload+0x1d82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d82;
	}
x86_l_1c66:
	/* 0x1c66: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1c69:
	/* 0x1c69: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1c6e:
	/* 0x1c6e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1c73:
	/* 0x1c73: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c77:
	/* 0x1c77: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c7c:
	/* 0x1c7c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c7e:
	/* 0x1c7e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c80:
	/* 0x1c80: jns    1d82 <generic_sleepable_preload+0x1d82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_1d82;
	}
x86_l_1c86:
	/* 0x1c86: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_1c8b:
	/* 0x1c8b: jmp    1d7f <generic_sleepable_preload+0x1d7f> */
	goto x86_l_1d7f;
x86_l_1c90:
	/* 0x1c90: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_1c95:
	/* 0x1c95: jmp    1d7f <generic_sleepable_preload+0x1d7f> */
	goto x86_l_1d7f;
x86_l_1c9a:
	/* 0x1c9a: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_1c9f:
	/* 0x1c9f: jmp    1cf4 <generic_sleepable_preload+0x1cf4> */
	goto x86_l_1cf4;
x86_l_1ca1:
	/* 0x1ca1: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_1ca6:
	/* 0x1ca6: jmp    1d7f <generic_sleepable_preload+0x1d7f> */
	goto x86_l_1d7f;
x86_l_1cab:
	/* 0x1cab: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_1cb0:
	/* 0x1cb0: jmp    1cf4 <generic_sleepable_preload+0x1cf4> */
	goto x86_l_1cf4;
x86_l_1cb2:
	/* 0x1cb2: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_1cb7:
	/* 0x1cb7: jmp    1d7f <generic_sleepable_preload+0x1d7f> */
	goto x86_l_1d7f;
x86_l_1cbc:
	/* 0x1cbc: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_1cc1:
	/* 0x1cc1: jmp    1cf4 <generic_sleepable_preload+0x1cf4> */
	goto x86_l_1cf4;
x86_l_1cc3:
	/* 0x1cc3: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_1cc8:
	/* 0x1cc8: jmp    1d7f <generic_sleepable_preload+0x1d7f> */
	goto x86_l_1d7f;
x86_l_1ccd:
	/* 0x1ccd: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_1cd2:
	/* 0x1cd2: jmp    1cf4 <generic_sleepable_preload+0x1cf4> */
	goto x86_l_1cf4;
x86_l_1cd4:
	/* 0x1cd4: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_1cd9:
	/* 0x1cd9: jmp    1d7f <generic_sleepable_preload+0x1d7f> */
	goto x86_l_1d7f;
x86_l_1cde:
	/* 0x1cde: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_1ce3:
	/* 0x1ce3: jmp    1cf4 <generic_sleepable_preload+0x1cf4> */
	goto x86_l_1cf4;
x86_l_1ce5:
	/* 0x1ce5: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_1cea:
	/* 0x1cea: jmp    1d7f <generic_sleepable_preload+0x1d7f> */
	goto x86_l_1d7f;
x86_l_1cef:
	/* 0x1cef: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_1cf4:
	/* 0x1cf4: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cf7:
	/* 0x1cf7: mov    ebp,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1cfc:
	/* 0x1cfc: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1cff:
	/* 0x1cff: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1d04:
	/* 0x1d04: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d09:
	/* 0x1d09: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d0e:
	/* 0x1d0e: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_1d11:
	/* 0x1d11: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d13:
	/* 0x1d13: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_1d16:
	/* 0x1d16: jne    1e26 <generic_sleepable_preload+0x1e26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e26;
	}
x86_l_1d1c:
	/* 0x1d1c: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_1d1f:
	/* 0x1d1f: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d23:
	/* 0x1d23: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1d28:
	/* 0x1d28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d2a:
	/* 0x1d2a: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d2f:
	/* 0x1d2f: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_1d37:
	/* 0x1d37: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_1d3e:
	/* 0x1d3e: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1d43:
	/* 0x1d43: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d48:
	/* 0x1d48: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d4a:
	/* 0x1d4a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d4d:
	/* 0x1d4d: je     1e23 <generic_sleepable_preload+0x1e23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e23;
	}
x86_l_1d53:
	/* 0x1d53: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1d56:
	/* 0x1d56: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_1d5d:
	/* 0x1d5d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d5f:
	/* 0x1d5f: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d64:
	/* 0x1d64: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1d69:
	/* 0x1d69: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1d6c:
	/* 0x1d6c: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1d6f:
	/* 0x1d6f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d71:
	/* 0x1d71: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d73:
	/* 0x1d73: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d78:
	/* 0x1d78: jmp    1de3 <generic_sleepable_preload+0x1de3> */
	goto x86_l_1de3;
x86_l_1d7a:
	/* 0x1d7a: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_1d7f:
	/* 0x1d7f: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d82:
	/* 0x1d82: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_1d85:
	/* 0x1d85: jne    1e26 <generic_sleepable_preload+0x1e26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e26;
	}
x86_l_1d8b:
	/* 0x1d8b: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_1d8e:
	/* 0x1d8e: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d92:
	/* 0x1d92: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1d97:
	/* 0x1d97: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d99:
	/* 0x1d99: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d9e:
	/* 0x1d9e: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_1da6:
	/* 0x1da6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_1dad:
	/* 0x1dad: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1db2:
	/* 0x1db2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1db7:
	/* 0x1db7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1db9:
	/* 0x1db9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1dbc:
	/* 0x1dbc: je     1e23 <generic_sleepable_preload+0x1e23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e23;
	}
x86_l_1dbe:
	/* 0x1dbe: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1dc1:
	/* 0x1dc1: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_1dc8:
	/* 0x1dc8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1dca:
	/* 0x1dca: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1dcf:
	/* 0x1dcf: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1dd4:
	/* 0x1dd4: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1dd7:
	/* 0x1dd7: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1dda:
	/* 0x1dda: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ddc:
	/* 0x1ddc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dde:
	/* 0x1dde: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1de3:
	/* 0x1de3: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1de6:
	/* 0x1de6: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1de9:
	/* 0x1de9: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1dee:
	/* 0x1dee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1df0:
	/* 0x1df0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1df3:
	/* 0x1df3: je     1e23 <generic_sleepable_preload+0x1e23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e23;
	}
x86_l_1df5:
	/* 0x1df5: test   r13b,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_8);
x86_l_1df8:
	/* 0x1df8: je     1e21 <generic_sleepable_preload+0x1e21> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e21;
	}
x86_l_1dfa:
	/* 0x1dfa: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1dfd:
	/* 0x1dfd: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1e01:
	/* 0x1e01: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1e06:
	/* 0x1e06: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1e09:
	/* 0x1e09: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e0b:
	/* 0x1e0b: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_1e0e:
	/* 0x1e0e: call   1e13 <generic_sleepable_preload+0x1e13> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_1e13:
	/* 0x1e13: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1e15:
	/* 0x1e15: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_1e18:
	/* 0x1e18: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1e1a:
	/* 0x1e1a: jns    1e21 <generic_sleepable_preload+0x1e21> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_1e21;
	}
x86_l_1e1c:
	/* 0x1e1c: mov    ebx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4294967295ULL);
x86_l_1e21:
	/* 0x1e21: mov    DWORD PTR [rax],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e23:
	/* 0x1e23: mov    r14,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_64);
x86_l_1e26:
	/* 0x1e26: mov    eax,DWORD PTR [r12+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1e2b:
	/* 0x1e2b: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_1e30:
	/* 0x1e30: je     2d91 <generic_sleepable_preload+0x2d91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11665ULL;
	}
x86_l_1e36:
	/* 0x1e36: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1e38:
	/* 0x1e38: js     1e6d <generic_sleepable_preload+0x1e6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1e6d;
	}
x86_l_1e3a:
	/* 0x1e3a: mov    eax,DWORD PTR [r12+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_1e3f:
	/* 0x1e3f: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1e42:
	/* 0x1e42: jle    1ef0 <generic_sleepable_preload+0x1ef0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1ef0;
	}
x86_l_1e48:
	/* 0x1e48: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1e4b:
	/* 0x1e4b: je     1f5a <generic_sleepable_preload+0x1f5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f5a;
	}
x86_l_1e51:
	/* 0x1e51: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1e54:
	/* 0x1e54: je     1f61 <generic_sleepable_preload+0x1f61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f61;
	}
x86_l_1e5a:
	/* 0x1e5a: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e5d:
	/* 0x1e5d: jne    1f74 <generic_sleepable_preload+0x1f74> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f74;
	}
x86_l_1e63:
	/* 0x1e63: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1e68:
	/* 0x1e68: jmp    1f6d <generic_sleepable_preload+0x1f6d> */
	goto x86_l_1f6d;
x86_l_1e6d:
	/* 0x1e6d: movzx  eax,BYTE PTR [r12+0x2c6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 710ULL);
x86_l_1e76:
	/* 0x1e76: movzx  ecx,WORD PTR [r12+0x2c4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 708ULL);
x86_l_1e7f:
	/* 0x1e7f: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_1e85:
	/* 0x1e85: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e87:
	/* 0x1e87: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_1e8a:
	/* 0x1e8a: jle    1ec9 <generic_sleepable_preload+0x1ec9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1ec9;
	}
x86_l_1e8c:
	/* 0x1e8c: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_1e8f:
	/* 0x1e8f: jle    1f00 <generic_sleepable_preload+0x1f00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1f00;
	}
x86_l_1e91:
	/* 0x1e91: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1e94:
	/* 0x1e94: jle    25c3 <generic_sleepable_preload+0x25c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 9667ULL;
	}
x86_l_1e9a:
	/* 0x1e9a: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1e9f:
	/* 0x1e9f: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_1ea2:
	/* 0x1ea2: je     25e8 <generic_sleepable_preload+0x25e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9704ULL;
	}
x86_l_1ea8:
	/* 0x1ea8: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1ead:
	/* 0x1ead: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_1eb0:
	/* 0x1eb0: je     25e8 <generic_sleepable_preload+0x25e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9704ULL;
	}
x86_l_1eb6:
	/* 0x1eb6: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1ebb:
	/* 0x1ebb: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_1ebe:
	/* 0x1ebe: je     25e8 <generic_sleepable_preload+0x25e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9704ULL;
	}
x86_l_1ec4:
	/* 0x1ec4: jmp    25fb <generic_sleepable_preload+0x25fb> */
	return 9723ULL;
x86_l_1ec9:
	/* 0x1ec9: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_1ecc:
	/* 0x1ecc: jg     1f2d <generic_sleepable_preload+0x1f2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1f2d;
	}
x86_l_1ece:
	/* 0x1ece: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_1ed1:
	/* 0x1ed1: jg     2594 <generic_sleepable_preload+0x2594> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 9620ULL;
	}
x86_l_1ed7:
	/* 0x1ed7: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_1ed9:
	/* 0x1ed9: je     25e3 <generic_sleepable_preload+0x25e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9699ULL;
	}
x86_l_1edf:
	/* 0x1edf: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_1ee2:
	/* 0x1ee2: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_1ee5:
	/* 0x1ee5: je     25e8 <generic_sleepable_preload+0x25e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9704ULL;
	}
x86_l_1eeb:
	/* 0x1eeb: jmp    25fb <generic_sleepable_preload+0x25fb> */
	return 9723ULL;
x86_l_1ef0:
	/* 0x1ef0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1ef2:
	/* 0x1ef2: je     1f68 <generic_sleepable_preload+0x1f68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f68;
	}
x86_l_1ef4:
	/* 0x1ef4: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ef7:
	/* 0x1ef7: jne    1f74 <generic_sleepable_preload+0x1f74> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f74;
	}
x86_l_1ef9:
	/* 0x1ef9: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1efe:
	/* 0x1efe: jmp    1f6d <generic_sleepable_preload+0x1f6d> */
	goto x86_l_1f6d;
x86_l_1f00:
	/* 0x1f00: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_1f03:
	/* 0x1f03: jg     257b <generic_sleepable_preload+0x257b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 9595ULL;
	}
x86_l_1f09:
	/* 0x1f09: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1f11:
	/* 0x1f11: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1f14:
	/* 0x1f14: je     25e8 <generic_sleepable_preload+0x25e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9704ULL;
	}
x86_l_1f1a:
	/* 0x1f1a: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1f1f:
	/* 0x1f1f: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_1f22:
	/* 0x1f22: je     25e8 <generic_sleepable_preload+0x25e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9704ULL;
	}
x86_l_1f28:
	/* 0x1f28: jmp    25fb <generic_sleepable_preload+0x25fb> */
	return 9723ULL;
x86_l_1f2d:
	/* 0x1f2d: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1f30:
	/* 0x1f30: jg     25aa <generic_sleepable_preload+0x25aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 9642ULL;
	}
x86_l_1f36:
	/* 0x1f36: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1f3e:
	/* 0x1f3e: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1f41:
	/* 0x1f41: je     25e8 <generic_sleepable_preload+0x25e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9704ULL;
	}
x86_l_1f47:
	/* 0x1f47: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1f4c:
	/* 0x1f4c: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1f4f:
	/* 0x1f4f: je     25e8 <generic_sleepable_preload+0x25e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9704ULL;
	}
x86_l_1f55:
	/* 0x1f55: jmp    25fb <generic_sleepable_preload+0x25fb> */
	return 9723ULL;
x86_l_1f5a:
	/* 0x1f5a: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1f5f:
	/* 0x1f5f: jmp    1f6d <generic_sleepable_preload+0x1f6d> */
	goto x86_l_1f6d;
x86_l_1f61:
	/* 0x1f61: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f66:
	/* 0x1f66: jmp    1f6d <generic_sleepable_preload+0x1f6d> */
	goto x86_l_1f6d;
x86_l_1f68:
	/* 0x1f68: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1f6d:
	/* 0x1f6d: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f70:
	/* 0x1f70: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f74:
	/* 0x1f74: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f76:
	/* 0x1f76: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_1f79:
	/* 0x1f79: cmp    WORD PTR [r12+0xc6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 850403524608ULL);
x86_l_1f83:
	/* 0x1f83: je     2c61 <generic_sleepable_preload+0x2c61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11361ULL;
	}
x86_l_1f89:
	/* 0x1f89: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_1f90:
	/* 0x1f90: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1f93:
	/* 0x1f93: mov    eax,DWORD PTR [r12+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1f9b:
	/* 0x1f9b: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1f9e:
	/* 0x1f9e: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fa2:
	/* 0x1fa2: movzx  eax,WORD PTR [r12+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 196ULL);
x86_l_1fab:
	/* 0x1fab: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1fad:
	/* 0x1fad: je     227f <generic_sleepable_preload+0x227f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8831ULL;
	}
x86_l_1fb3:
	/* 0x1fb3: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_1fb6:
	/* 0x1fb6: je     1fd8 <generic_sleepable_preload+0x1fd8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fd8;
	}
x86_l_1fb8:
	/* 0x1fb8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1fbb:
	/* 0x1fbb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1fc0:
	/* 0x1fc0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1fc5:
	/* 0x1fc5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fc9:
	/* 0x1fc9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1fce:
	/* 0x1fce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fd0:
	/* 0x1fd0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1fd2:
	/* 0x1fd2: js     2571 <generic_sleepable_preload+0x2571> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9585ULL;
	}
x86_l_1fd8:
	/* 0x1fd8: cmp    WORD PTR [r12+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_1fe2:
	/* 0x1fe2: je     2c61 <generic_sleepable_preload+0x2c61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11361ULL;
	}
x86_l_1fe8:
	/* 0x1fe8: mov    ecx,DWORD PTR [r12+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1ff0:
	/* 0x1ff0: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1ff4:
	/* 0x1ff4: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ff8:
	/* 0x1ff8: cmp    WORD PTR [r12+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_2002:
	/* 0x2002: je     2024 <generic_sleepable_preload+0x2024> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2024;
	}
x86_l_2004:
	/* 0x2004: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2007:
	/* 0x2007: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_200c:
	/* 0x200c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2011:
	/* 0x2011: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2015:
	/* 0x2015: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_201a:
	/* 0x201a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_201c:
	/* 0x201c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_201e:
	/* 0x201e: js     25d9 <generic_sleepable_preload+0x25d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9689ULL;
	}
x86_l_2024:
	/* 0x2024: cmp    WORD PTR [r12+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_202e:
	/* 0x202e: je     2c61 <generic_sleepable_preload+0x2c61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11361ULL;
	}
x86_l_2034:
	/* 0x2034: mov    ecx,DWORD PTR [r12+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_203c:
	/* 0x203c: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2040:
	/* 0x2040: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2044:
	/* 0x2044: cmp    WORD PTR [r12+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_204e:
	/* 0x204e: je     2070 <generic_sleepable_preload+0x2070> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2070;
	}
x86_l_2050:
	/* 0x2050: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2053:
	/* 0x2053: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2058:
	/* 0x2058: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_205d:
	/* 0x205d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2061:
	/* 0x2061: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2066:
	/* 0x2066: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2068:
	/* 0x2068: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_206a:
	/* 0x206a: js     2c15 <generic_sleepable_preload+0x2c15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11285ULL;
	}
x86_l_2070:
	/* 0x2070: cmp    WORD PTR [r12+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_207a:
	/* 0x207a: je     2c61 <generic_sleepable_preload+0x2c61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11361ULL;
	}
x86_l_2080:
	/* 0x2080: mov    ecx,DWORD PTR [r12+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_2088:
	/* 0x2088: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_208c:
	/* 0x208c: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2090:
	/* 0x2090: cmp    WORD PTR [r12+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_209a:
	/* 0x209a: je     20bc <generic_sleepable_preload+0x20bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20bc;
	}
x86_l_209c:
	/* 0x209c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_209f:
	/* 0x209f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_20a4:
	/* 0x20a4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_20a9:
	/* 0x20a9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20ad:
	/* 0x20ad: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20b2:
	/* 0x20b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20b4:
	/* 0x20b4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20b6:
	/* 0x20b6: js     2c26 <generic_sleepable_preload+0x2c26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11302ULL;
	}
x86_l_20bc:
	/* 0x20bc: cmp    WORD PTR [r12+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_20c6:
	/* 0x20c6: je     2c61 <generic_sleepable_preload+0x2c61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11361ULL;
	}
x86_l_20cc:
	/* 0x20cc: mov    ecx,DWORD PTR [r12+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_20d4:
	/* 0x20d4: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_20d8:
	/* 0x20d8: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20dc:
	/* 0x20dc: cmp    WORD PTR [r12+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_20e6:
	/* 0x20e6: je     2108 <generic_sleepable_preload+0x2108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2108;
	}
x86_l_20e8:
	/* 0x20e8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_20eb:
	/* 0x20eb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_20f0:
	/* 0x20f0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_20f5:
	/* 0x20f5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20f9:
	/* 0x20f9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20fe:
	/* 0x20fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2100:
	/* 0x2100: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2102:
	/* 0x2102: js     2c37 <generic_sleepable_preload+0x2c37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11319ULL;
	}
x86_l_2108:
	/* 0x2108: cmp    WORD PTR [r12+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_2112:
	/* 0x2112: je     2c61 <generic_sleepable_preload+0x2c61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11361ULL;
	}
x86_l_2118:
	/* 0x2118: mov    ecx,DWORD PTR [r12+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_2120:
	/* 0x2120: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2124:
	/* 0x2124: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2128:
	/* 0x2128: cmp    WORD PTR [r12+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_2132:
	/* 0x2132: je     2154 <generic_sleepable_preload+0x2154> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8532ULL;
	}
x86_l_2134:
	/* 0x2134: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2137:
	/* 0x2137: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_213c:
	/* 0x213c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2141:
	/* 0x2141: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2145:
	/* 0x2145: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_214a:
	/* 0x214a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 8524ULL;
}

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8524ULL: goto x86_l_214c;
	case 8526ULL: goto x86_l_214e;
	case 8532ULL: goto x86_l_2154;
	case 8542ULL: goto x86_l_215e;
	case 8548ULL: goto x86_l_2164;
	case 8556ULL: goto x86_l_216c;
	case 8560ULL: goto x86_l_2170;
	case 8564ULL: goto x86_l_2174;
	case 8574ULL: goto x86_l_217e;
	case 8576ULL: goto x86_l_2180;
	case 8579ULL: goto x86_l_2183;
	case 8584ULL: goto x86_l_2188;
	case 8589ULL: goto x86_l_218d;
	case 8593ULL: goto x86_l_2191;
	case 8598ULL: goto x86_l_2196;
	case 8600ULL: goto x86_l_2198;
	case 8602ULL: goto x86_l_219a;
	case 8608ULL: goto x86_l_21a0;
	case 8618ULL: goto x86_l_21aa;
	case 8624ULL: goto x86_l_21b0;
	case 8632ULL: goto x86_l_21b8;
	case 8636ULL: goto x86_l_21bc;
	case 8640ULL: goto x86_l_21c0;
	case 8650ULL: goto x86_l_21ca;
	case 8652ULL: goto x86_l_21cc;
	case 8655ULL: goto x86_l_21cf;
	case 8660ULL: goto x86_l_21d4;
	case 8665ULL: goto x86_l_21d9;
	case 8669ULL: goto x86_l_21dd;
	case 8674ULL: goto x86_l_21e2;
	case 8676ULL: goto x86_l_21e4;
	case 8678ULL: goto x86_l_21e6;
	case 8684ULL: goto x86_l_21ec;
	case 8694ULL: goto x86_l_21f6;
	case 8700ULL: goto x86_l_21fc;
	case 8708ULL: goto x86_l_2204;
	case 8712ULL: goto x86_l_2208;
	case 8716ULL: goto x86_l_220c;
	case 8726ULL: goto x86_l_2216;
	case 8728ULL: goto x86_l_2218;
	case 8731ULL: goto x86_l_221b;
	case 8736ULL: goto x86_l_2220;
	case 8741ULL: goto x86_l_2225;
	case 8745ULL: goto x86_l_2229;
	case 8750ULL: goto x86_l_222e;
	case 8752ULL: goto x86_l_2230;
	case 8754ULL: goto x86_l_2232;
	case 8760ULL: goto x86_l_2238;
	case 8765ULL: goto x86_l_223d;
	case 8775ULL: goto x86_l_2247;
	case 8781ULL: goto x86_l_224d;
	case 8789ULL: goto x86_l_2255;
	case 8793ULL: goto x86_l_2259;
	case 8797ULL: goto x86_l_225d;
	case 8807ULL: goto x86_l_2267;
	case 8813ULL: goto x86_l_226d;
	case 8816ULL: goto x86_l_2270;
	case 8821ULL: goto x86_l_2275;
	case 8826ULL: goto x86_l_227a;
	case 8831ULL: goto x86_l_227f;
	case 8834ULL: goto x86_l_2282;
	case 8836ULL: goto x86_l_2284;
	case 8839ULL: goto x86_l_2287;
	case 8844ULL: goto x86_l_228c;
	case 8849ULL: goto x86_l_2291;
	case 8853ULL: goto x86_l_2295;
	case 8858ULL: goto x86_l_229a;
	case 8860ULL: goto x86_l_229c;
	case 8862ULL: goto x86_l_229e;
	case 8868ULL: goto x86_l_22a4;
	case 8878ULL: goto x86_l_22ae;
	case 8884ULL: goto x86_l_22b4;
	case 8892ULL: goto x86_l_22bc;
	case 8896ULL: goto x86_l_22c0;
	case 8900ULL: goto x86_l_22c4;
	case 8910ULL: goto x86_l_22ce;
	case 8912ULL: goto x86_l_22d0;
	case 8915ULL: goto x86_l_22d3;
	case 8920ULL: goto x86_l_22d8;
	case 8925ULL: goto x86_l_22dd;
	case 8929ULL: goto x86_l_22e1;
	case 8934ULL: goto x86_l_22e6;
	case 8936ULL: goto x86_l_22e8;
	case 8938ULL: goto x86_l_22ea;
	case 8944ULL: goto x86_l_22f0;
	case 8954ULL: goto x86_l_22fa;
	case 8960ULL: goto x86_l_2300;
	case 8968ULL: goto x86_l_2308;
	case 8972ULL: goto x86_l_230c;
	case 8976ULL: goto x86_l_2310;
	case 8986ULL: goto x86_l_231a;
	case 8988ULL: goto x86_l_231c;
	case 8991ULL: goto x86_l_231f;
	case 8996ULL: goto x86_l_2324;
	case 9001ULL: goto x86_l_2329;
	case 9005ULL: goto x86_l_232d;
	case 9010ULL: goto x86_l_2332;
	case 9012ULL: goto x86_l_2334;
	case 9014ULL: goto x86_l_2336;
	case 9020ULL: goto x86_l_233c;
	case 9030ULL: goto x86_l_2346;
	case 9036ULL: goto x86_l_234c;
	case 9044ULL: goto x86_l_2354;
	case 9048ULL: goto x86_l_2358;
	case 9052ULL: goto x86_l_235c;
	case 9062ULL: goto x86_l_2366;
	case 9064ULL: goto x86_l_2368;
	case 9067ULL: goto x86_l_236b;
	case 9072ULL: goto x86_l_2370;
	case 9077ULL: goto x86_l_2375;
	case 9081ULL: goto x86_l_2379;
	case 9086ULL: goto x86_l_237e;
	case 9088ULL: goto x86_l_2380;
	case 9090ULL: goto x86_l_2382;
	case 9096ULL: goto x86_l_2388;
	case 9106ULL: goto x86_l_2392;
	case 9112ULL: goto x86_l_2398;
	case 9120ULL: goto x86_l_23a0;
	case 9124ULL: goto x86_l_23a4;
	case 9128ULL: goto x86_l_23a8;
	case 9138ULL: goto x86_l_23b2;
	case 9140ULL: goto x86_l_23b4;
	case 9143ULL: goto x86_l_23b7;
	case 9148ULL: goto x86_l_23bc;
	case 9153ULL: goto x86_l_23c1;
	case 9157ULL: goto x86_l_23c5;
	case 9162ULL: goto x86_l_23ca;
	case 9164ULL: goto x86_l_23cc;
	case 9166ULL: goto x86_l_23ce;
	case 9172ULL: goto x86_l_23d4;
	case 9182ULL: goto x86_l_23de;
	case 9188ULL: goto x86_l_23e4;
	case 9196ULL: goto x86_l_23ec;
	case 9200ULL: goto x86_l_23f0;
	case 9204ULL: goto x86_l_23f4;
	case 9214ULL: goto x86_l_23fe;
	case 9216ULL: goto x86_l_2400;
	case 9219ULL: goto x86_l_2403;
	case 9224ULL: goto x86_l_2408;
	case 9229ULL: goto x86_l_240d;
	case 9233ULL: goto x86_l_2411;
	case 9238ULL: goto x86_l_2416;
	case 9240ULL: goto x86_l_2418;
	case 9242ULL: goto x86_l_241a;
	case 9248ULL: goto x86_l_2420;
	case 9258ULL: goto x86_l_242a;
	case 9264ULL: goto x86_l_2430;
	case 9272ULL: goto x86_l_2438;
	case 9276ULL: goto x86_l_243c;
	case 9280ULL: goto x86_l_2440;
	case 9290ULL: goto x86_l_244a;
	case 9292ULL: goto x86_l_244c;
	case 9295ULL: goto x86_l_244f;
	case 9300ULL: goto x86_l_2454;
	case 9305ULL: goto x86_l_2459;
	case 9309ULL: goto x86_l_245d;
	case 9314ULL: goto x86_l_2462;
	case 9316ULL: goto x86_l_2464;
	case 9318ULL: goto x86_l_2466;
	case 9324ULL: goto x86_l_246c;
	case 9334ULL: goto x86_l_2476;
	case 9340ULL: goto x86_l_247c;
	case 9343ULL: goto x86_l_247f;
	case 9351ULL: goto x86_l_2487;
	case 9355ULL: goto x86_l_248b;
	case 9359ULL: goto x86_l_248f;
	case 9369ULL: goto x86_l_2499;
	case 9371ULL: goto x86_l_249b;
	case 9374ULL: goto x86_l_249e;
	case 9379ULL: goto x86_l_24a3;
	case 9384ULL: goto x86_l_24a8;
	case 9388ULL: goto x86_l_24ac;
	case 9393ULL: goto x86_l_24b1;
	case 9395ULL: goto x86_l_24b3;
	case 9397ULL: goto x86_l_24b5;
	case 9403ULL: goto x86_l_24bb;
	case 9408ULL: goto x86_l_24c0;
	case 9418ULL: goto x86_l_24ca;
	case 9421ULL: goto x86_l_24cd;
	case 9427ULL: goto x86_l_24d3;
	case 9435ULL: goto x86_l_24db;
	case 9439ULL: goto x86_l_24df;
	case 9443ULL: goto x86_l_24e3;
	case 9453ULL: goto x86_l_24ed;
	case 9455ULL: goto x86_l_24ef;
	case 9458ULL: goto x86_l_24f2;
	case 9463ULL: goto x86_l_24f7;
	case 9468ULL: goto x86_l_24fc;
	case 9472ULL: goto x86_l_2500;
	case 9477ULL: goto x86_l_2505;
	case 9479ULL: goto x86_l_2507;
	case 9481ULL: goto x86_l_2509;
	case 9487ULL: goto x86_l_250f;
	case 9492ULL: goto x86_l_2514;
	case 9502ULL: goto x86_l_251e;
	case 9505ULL: goto x86_l_2521;
	case 9511ULL: goto x86_l_2527;
	case 9519ULL: goto x86_l_252f;
	case 9523ULL: goto x86_l_2533;
	case 9527ULL: goto x86_l_2537;
	case 9537ULL: goto x86_l_2541;
	case 9543ULL: goto x86_l_2547;
	case 9546ULL: goto x86_l_254a;
	case 9551ULL: goto x86_l_254f;
	case 9556ULL: goto x86_l_2554;
	case 9560ULL: goto x86_l_2558;
	case 9565ULL: goto x86_l_255d;
	case 9567ULL: goto x86_l_255f;
	case 9569ULL: goto x86_l_2561;
	case 9575ULL: goto x86_l_2567;
	case 9580ULL: goto x86_l_256c;
	case 9585ULL: goto x86_l_2571;
	case 9590ULL: goto x86_l_2576;
	case 9595ULL: goto x86_l_257b;
	case 9603ULL: goto x86_l_2583;
	case 9606ULL: goto x86_l_2586;
	case 9608ULL: goto x86_l_2588;
	case 9613ULL: goto x86_l_258d;
	case 9616ULL: goto x86_l_2590;
	case 9618ULL: goto x86_l_2592;
	case 9620ULL: goto x86_l_2594;
	case 9625ULL: goto x86_l_2599;
	case 9628ULL: goto x86_l_259c;
	case 9630ULL: goto x86_l_259e;
	case 9635ULL: goto x86_l_25a3;
	case 9638ULL: goto x86_l_25a6;
	case 9640ULL: goto x86_l_25a8;
	case 9642ULL: goto x86_l_25aa;
	case 9650ULL: goto x86_l_25b2;
	case 9653ULL: goto x86_l_25b5;
	case 9655ULL: goto x86_l_25b7;
	case 9660ULL: goto x86_l_25bc;
	case 9663ULL: goto x86_l_25bf;
	case 9665ULL: goto x86_l_25c1;
	case 9667ULL: goto x86_l_25c3;
	case 9672ULL: goto x86_l_25c8;
	case 9675ULL: goto x86_l_25cb;
	case 9677ULL: goto x86_l_25cd;
	case 9682ULL: goto x86_l_25d2;
	case 9685ULL: goto x86_l_25d5;
	case 9687ULL: goto x86_l_25d7;
	case 9689ULL: goto x86_l_25d9;
	case 9694ULL: goto x86_l_25de;
	case 9699ULL: goto x86_l_25e3;
	case 9704ULL: goto x86_l_25e8;
	case 9707ULL: goto x86_l_25eb;
	case 9709ULL: goto x86_l_25ed;
	case 9711ULL: goto x86_l_25ef;
	case 9716ULL: goto x86_l_25f4;
	case 9718ULL: goto x86_l_25f6;
	case 9723ULL: goto x86_l_25fb;
	case 9727ULL: goto x86_l_25ff;
	case 9732ULL: goto x86_l_2604;
	case 9734ULL: goto x86_l_2606;
	case 9737ULL: goto x86_l_2609;
	case 9747ULL: goto x86_l_2613;
	case 9753ULL: goto x86_l_2619;
	case 9760ULL: goto x86_l_2620;
	case 9763ULL: goto x86_l_2623;
	case 9771ULL: goto x86_l_262b;
	case 9774ULL: goto x86_l_262e;
	case 9778ULL: goto x86_l_2632;
	case 9787ULL: goto x86_l_263b;
	case 9789ULL: goto x86_l_263d;
	case 9795ULL: goto x86_l_2643;
	case 9798ULL: goto x86_l_2646;
	case 9800ULL: goto x86_l_2648;
	case 9803ULL: goto x86_l_264b;
	case 9808ULL: goto x86_l_2650;
	case 9813ULL: goto x86_l_2655;
	case 9817ULL: goto x86_l_2659;
	case 9822ULL: goto x86_l_265e;
	case 9824ULL: goto x86_l_2660;
	case 9826ULL: goto x86_l_2662;
	case 9832ULL: goto x86_l_2668;
	case 9842ULL: goto x86_l_2672;
	case 9848ULL: goto x86_l_2678;
	case 9856ULL: goto x86_l_2680;
	case 9860ULL: goto x86_l_2684;
	case 9864ULL: goto x86_l_2688;
	case 9874ULL: goto x86_l_2692;
	case 9876ULL: goto x86_l_2694;
	case 9879ULL: goto x86_l_2697;
	case 9884ULL: goto x86_l_269c;
	case 9889ULL: goto x86_l_26a1;
	case 9893ULL: goto x86_l_26a5;
	case 9898ULL: goto x86_l_26aa;
	case 9900ULL: goto x86_l_26ac;
	case 9902ULL: goto x86_l_26ae;
	case 9908ULL: goto x86_l_26b4;
	case 9918ULL: goto x86_l_26be;
	case 9924ULL: goto x86_l_26c4;
	case 9932ULL: goto x86_l_26cc;
	case 9936ULL: goto x86_l_26d0;
	case 9940ULL: goto x86_l_26d4;
	case 9950ULL: goto x86_l_26de;
	case 9952ULL: goto x86_l_26e0;
	case 9955ULL: goto x86_l_26e3;
	case 9960ULL: goto x86_l_26e8;
	case 9965ULL: goto x86_l_26ed;
	case 9969ULL: goto x86_l_26f1;
	case 9974ULL: goto x86_l_26f6;
	case 9976ULL: goto x86_l_26f8;
	case 9978ULL: goto x86_l_26fa;
	case 9984ULL: goto x86_l_2700;
	case 9994ULL: goto x86_l_270a;
	case 10000ULL: goto x86_l_2710;
	case 10008ULL: goto x86_l_2718;
	case 10012ULL: goto x86_l_271c;
	case 10016ULL: goto x86_l_2720;
	case 10026ULL: goto x86_l_272a;
	case 10028ULL: goto x86_l_272c;
	case 10031ULL: goto x86_l_272f;
	case 10036ULL: goto x86_l_2734;
	case 10041ULL: goto x86_l_2739;
	case 10045ULL: goto x86_l_273d;
	case 10050ULL: goto x86_l_2742;
	case 10052ULL: goto x86_l_2744;
	case 10054ULL: goto x86_l_2746;
	case 10060ULL: goto x86_l_274c;
	case 10070ULL: goto x86_l_2756;
	case 10076ULL: goto x86_l_275c;
	case 10084ULL: goto x86_l_2764;
	case 10088ULL: goto x86_l_2768;
	case 10092ULL: goto x86_l_276c;
	case 10102ULL: goto x86_l_2776;
	case 10104ULL: goto x86_l_2778;
	case 10107ULL: goto x86_l_277b;
	case 10112ULL: goto x86_l_2780;
	case 10117ULL: goto x86_l_2785;
	case 10121ULL: goto x86_l_2789;
	case 10126ULL: goto x86_l_278e;
	case 10128ULL: goto x86_l_2790;
	case 10130ULL: goto x86_l_2792;
	case 10136ULL: goto x86_l_2798;
	case 10146ULL: goto x86_l_27a2;
	case 10152ULL: goto x86_l_27a8;
	case 10160ULL: goto x86_l_27b0;
	case 10164ULL: goto x86_l_27b4;
	case 10168ULL: goto x86_l_27b8;
	case 10178ULL: goto x86_l_27c2;
	case 10180ULL: goto x86_l_27c4;
	case 10183ULL: goto x86_l_27c7;
	case 10188ULL: goto x86_l_27cc;
	case 10193ULL: goto x86_l_27d1;
	case 10197ULL: goto x86_l_27d5;
	case 10202ULL: goto x86_l_27da;
	case 10204ULL: goto x86_l_27dc;
	case 10206ULL: goto x86_l_27de;
	case 10212ULL: goto x86_l_27e4;
	case 10222ULL: goto x86_l_27ee;
	case 10228ULL: goto x86_l_27f4;
	case 10236ULL: goto x86_l_27fc;
	case 10240ULL: goto x86_l_2800;
	case 10244ULL: goto x86_l_2804;
	case 10254ULL: goto x86_l_280e;
	case 10256ULL: goto x86_l_2810;
	case 10259ULL: goto x86_l_2813;
	case 10264ULL: goto x86_l_2818;
	case 10269ULL: goto x86_l_281d;
	case 10273ULL: goto x86_l_2821;
	case 10278ULL: goto x86_l_2826;
	case 10280ULL: goto x86_l_2828;
	case 10282ULL: goto x86_l_282a;
	case 10288ULL: goto x86_l_2830;
	case 10298ULL: goto x86_l_283a;
	case 10304ULL: goto x86_l_2840;
	case 10312ULL: goto x86_l_2848;
	case 10316ULL: goto x86_l_284c;
	case 10320ULL: goto x86_l_2850;
	case 10330ULL: goto x86_l_285a;
	case 10332ULL: goto x86_l_285c;
	case 10335ULL: goto x86_l_285f;
	case 10340ULL: goto x86_l_2864;
	case 10345ULL: goto x86_l_2869;
	case 10349ULL: goto x86_l_286d;
	case 10354ULL: goto x86_l_2872;
	case 10356ULL: goto x86_l_2874;
	case 10358ULL: goto x86_l_2876;
	case 10364ULL: goto x86_l_287c;
	case 10374ULL: goto x86_l_2886;
	case 10380ULL: goto x86_l_288c;
	case 10388ULL: goto x86_l_2894;
	case 10392ULL: goto x86_l_2898;
	default: return 0xffffffffffffffffULL;
	}
x86_l_214c:
	/* 0x214c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_214e:
	/* 0x214e: js     2c48 <generic_sleepable_preload+0x2c48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11336ULL;
	}
x86_l_2154:
	/* 0x2154: cmp    WORD PTR [r12+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_215e:
	/* 0x215e: je     2c61 <generic_sleepable_preload+0x2c61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11361ULL;
	}
x86_l_2164:
	/* 0x2164: mov    ecx,DWORD PTR [r12+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_216c:
	/* 0x216c: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2170:
	/* 0x2170: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2174:
	/* 0x2174: cmp    WORD PTR [r12+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_217e:
	/* 0x217e: je     21a0 <generic_sleepable_preload+0x21a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21a0;
	}
x86_l_2180:
	/* 0x2180: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2183:
	/* 0x2183: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2188:
	/* 0x2188: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_218d:
	/* 0x218d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2191:
	/* 0x2191: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2196:
	/* 0x2196: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2198:
	/* 0x2198: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_219a:
	/* 0x219a: js     2c59 <generic_sleepable_preload+0x2c59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11353ULL;
	}
x86_l_21a0:
	/* 0x21a0: cmp    WORD PTR [r12+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_21aa:
	/* 0x21aa: je     2c61 <generic_sleepable_preload+0x2c61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11361ULL;
	}
x86_l_21b0:
	/* 0x21b0: mov    ecx,DWORD PTR [r12+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_21b8:
	/* 0x21b8: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_21bc:
	/* 0x21bc: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21c0:
	/* 0x21c0: cmp    WORD PTR [r12+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_21ca:
	/* 0x21ca: je     21ec <generic_sleepable_preload+0x21ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21ec;
	}
x86_l_21cc:
	/* 0x21cc: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_21cf:
	/* 0x21cf: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_21d4:
	/* 0x21d4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_21d9:
	/* 0x21d9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21dd:
	/* 0x21dd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21e2:
	/* 0x21e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21e4:
	/* 0x21e4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_21e6:
	/* 0x21e6: js     5bdc <generic_sleepable_preload+0x5bdc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23516ULL;
	}
x86_l_21ec:
	/* 0x21ec: cmp    WORD PTR [r12+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_21f6:
	/* 0x21f6: je     2c61 <generic_sleepable_preload+0x2c61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11361ULL;
	}
x86_l_21fc:
	/* 0x21fc: mov    ecx,DWORD PTR [r12+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_2204:
	/* 0x2204: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2208:
	/* 0x2208: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_220c:
	/* 0x220c: cmp    WORD PTR [r12+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_2216:
	/* 0x2216: je     2238 <generic_sleepable_preload+0x2238> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2238;
	}
x86_l_2218:
	/* 0x2218: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_221b:
	/* 0x221b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2220:
	/* 0x2220: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2225:
	/* 0x2225: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2229:
	/* 0x2229: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_222e:
	/* 0x222e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2230:
	/* 0x2230: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2232:
	/* 0x2232: js     5ccc <generic_sleepable_preload+0x5ccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23756ULL;
	}
x86_l_2238:
	/* 0x2238: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_223d:
	/* 0x223d: cmp    WORD PTR [r12+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_2247:
	/* 0x2247: je     2c61 <generic_sleepable_preload+0x2c61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11361ULL;
	}
x86_l_224d:
	/* 0x224d: mov    ecx,DWORD PTR [r12+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_2255:
	/* 0x2255: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2259:
	/* 0x2259: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_225d:
	/* 0x225d: cmp    WORD PTR [r12+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_2267:
	/* 0x2267: je     2c61 <generic_sleepable_preload+0x2c61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11361ULL;
	}
x86_l_226d:
	/* 0x226d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2270:
	/* 0x2270: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2275:
	/* 0x2275: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_227a:
	/* 0x227a: jmp    2554 <generic_sleepable_preload+0x2554> */
	goto x86_l_2554;
x86_l_227f:
	/* 0x227f: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_2282:
	/* 0x2282: je     22a4 <generic_sleepable_preload+0x22a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22a4;
	}
x86_l_2284:
	/* 0x2284: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2287:
	/* 0x2287: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_228c:
	/* 0x228c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2291:
	/* 0x2291: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2295:
	/* 0x2295: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_229a:
	/* 0x229a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_229c:
	/* 0x229c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_229e:
	/* 0x229e: js     2571 <generic_sleepable_preload+0x2571> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2571;
	}
x86_l_22a4:
	/* 0x22a4: cmp    WORD PTR [r12+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_22ae:
	/* 0x22ae: je     2c61 <generic_sleepable_preload+0x2c61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11361ULL;
	}
x86_l_22b4:
	/* 0x22b4: mov    ecx,DWORD PTR [r12+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_22bc:
	/* 0x22bc: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_22c0:
	/* 0x22c0: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22c4:
	/* 0x22c4: cmp    WORD PTR [r12+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_22ce:
	/* 0x22ce: je     22f0 <generic_sleepable_preload+0x22f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22f0;
	}
x86_l_22d0:
	/* 0x22d0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_22d3:
	/* 0x22d3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_22d8:
	/* 0x22d8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_22dd:
	/* 0x22dd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22e1:
	/* 0x22e1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22e6:
	/* 0x22e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22e8:
	/* 0x22e8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_22ea:
	/* 0x22ea: js     25d9 <generic_sleepable_preload+0x25d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_25d9;
	}
x86_l_22f0:
	/* 0x22f0: cmp    WORD PTR [r12+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_22fa:
	/* 0x22fa: je     2c61 <generic_sleepable_preload+0x2c61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11361ULL;
	}
x86_l_2300:
	/* 0x2300: mov    ecx,DWORD PTR [r12+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_2308:
	/* 0x2308: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_230c:
	/* 0x230c: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2310:
	/* 0x2310: cmp    WORD PTR [r12+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_231a:
	/* 0x231a: je     233c <generic_sleepable_preload+0x233c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_233c;
	}
x86_l_231c:
	/* 0x231c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_231f:
	/* 0x231f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2324:
	/* 0x2324: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2329:
	/* 0x2329: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_232d:
	/* 0x232d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2332:
	/* 0x2332: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2334:
	/* 0x2334: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2336:
	/* 0x2336: js     2c15 <generic_sleepable_preload+0x2c15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11285ULL;
	}
x86_l_233c:
	/* 0x233c: cmp    WORD PTR [r12+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_2346:
	/* 0x2346: je     2c61 <generic_sleepable_preload+0x2c61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11361ULL;
	}
x86_l_234c:
	/* 0x234c: mov    ecx,DWORD PTR [r12+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_2354:
	/* 0x2354: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2358:
	/* 0x2358: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_235c:
	/* 0x235c: cmp    WORD PTR [r12+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_2366:
	/* 0x2366: je     2388 <generic_sleepable_preload+0x2388> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2388;
	}
x86_l_2368:
	/* 0x2368: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_236b:
	/* 0x236b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2370:
	/* 0x2370: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2375:
	/* 0x2375: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2379:
	/* 0x2379: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_237e:
	/* 0x237e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2380:
	/* 0x2380: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2382:
	/* 0x2382: js     2c26 <generic_sleepable_preload+0x2c26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11302ULL;
	}
x86_l_2388:
	/* 0x2388: cmp    WORD PTR [r12+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_2392:
	/* 0x2392: je     2c61 <generic_sleepable_preload+0x2c61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11361ULL;
	}
x86_l_2398:
	/* 0x2398: mov    ecx,DWORD PTR [r12+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_23a0:
	/* 0x23a0: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_23a4:
	/* 0x23a4: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23a8:
	/* 0x23a8: cmp    WORD PTR [r12+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_23b2:
	/* 0x23b2: je     23d4 <generic_sleepable_preload+0x23d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23d4;
	}
x86_l_23b4:
	/* 0x23b4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_23b7:
	/* 0x23b7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_23bc:
	/* 0x23bc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_23c1:
	/* 0x23c1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23c5:
	/* 0x23c5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23ca:
	/* 0x23ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23cc:
	/* 0x23cc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_23ce:
	/* 0x23ce: js     2c37 <generic_sleepable_preload+0x2c37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11319ULL;
	}
x86_l_23d4:
	/* 0x23d4: cmp    WORD PTR [r12+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_23de:
	/* 0x23de: je     2c61 <generic_sleepable_preload+0x2c61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11361ULL;
	}
x86_l_23e4:
	/* 0x23e4: mov    ecx,DWORD PTR [r12+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_23ec:
	/* 0x23ec: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_23f0:
	/* 0x23f0: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23f4:
	/* 0x23f4: cmp    WORD PTR [r12+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_23fe:
	/* 0x23fe: je     2420 <generic_sleepable_preload+0x2420> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2420;
	}
x86_l_2400:
	/* 0x2400: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2403:
	/* 0x2403: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2408:
	/* 0x2408: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_240d:
	/* 0x240d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2411:
	/* 0x2411: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2416:
	/* 0x2416: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2418:
	/* 0x2418: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_241a:
	/* 0x241a: js     2c48 <generic_sleepable_preload+0x2c48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11336ULL;
	}
x86_l_2420:
	/* 0x2420: cmp    WORD PTR [r12+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_242a:
	/* 0x242a: je     2c61 <generic_sleepable_preload+0x2c61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11361ULL;
	}
x86_l_2430:
	/* 0x2430: mov    ecx,DWORD PTR [r12+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_2438:
	/* 0x2438: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_243c:
	/* 0x243c: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2440:
	/* 0x2440: cmp    WORD PTR [r12+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_244a:
	/* 0x244a: je     246c <generic_sleepable_preload+0x246c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_246c;
	}
x86_l_244c:
	/* 0x244c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_244f:
	/* 0x244f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2454:
	/* 0x2454: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2459:
	/* 0x2459: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_245d:
	/* 0x245d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2462:
	/* 0x2462: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2464:
	/* 0x2464: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2466:
	/* 0x2466: js     2c59 <generic_sleepable_preload+0x2c59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11353ULL;
	}
x86_l_246c:
	/* 0x246c: cmp    WORD PTR [r12+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_2476:
	/* 0x2476: je     2c61 <generic_sleepable_preload+0x2c61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11361ULL;
	}
x86_l_247c:
	/* 0x247c: mov    r15,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R14, X86_WIDTH_64);
x86_l_247f:
	/* 0x247f: mov    ecx,DWORD PTR [r12+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_2487:
	/* 0x2487: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_248b:
	/* 0x248b: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_248f:
	/* 0x248f: cmp    WORD PTR [r12+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_2499:
	/* 0x2499: je     24bb <generic_sleepable_preload+0x24bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24bb;
	}
x86_l_249b:
	/* 0x249b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_249e:
	/* 0x249e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_24a3:
	/* 0x24a3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_24a8:
	/* 0x24a8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24ac:
	/* 0x24ac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24b1:
	/* 0x24b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24b3:
	/* 0x24b3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24b5:
	/* 0x24b5: js     5c5a <generic_sleepable_preload+0x5c5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23642ULL;
	}
x86_l_24bb:
	/* 0x24bb: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24c0:
	/* 0x24c0: cmp    WORD PTR [r12+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_24ca:
	/* 0x24ca: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_24cd:
	/* 0x24cd: je     2c61 <generic_sleepable_preload+0x2c61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11361ULL;
	}
x86_l_24d3:
	/* 0x24d3: mov    ecx,DWORD PTR [r12+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_24db:
	/* 0x24db: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_24df:
	/* 0x24df: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24e3:
	/* 0x24e3: cmp    WORD PTR [r12+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_24ed:
	/* 0x24ed: je     250f <generic_sleepable_preload+0x250f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_250f;
	}
x86_l_24ef:
	/* 0x24ef: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_24f2:
	/* 0x24f2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_24f7:
	/* 0x24f7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_24fc:
	/* 0x24fc: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
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
	/* 0x2509: js     5d62 <generic_sleepable_preload+0x5d62> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23906ULL;
	}
x86_l_250f:
	/* 0x250f: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2514:
	/* 0x2514: cmp    WORD PTR [r12+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_251e:
	/* 0x251e: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_2521:
	/* 0x2521: je     2c61 <generic_sleepable_preload+0x2c61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11361ULL;
	}
x86_l_2527:
	/* 0x2527: mov    ecx,DWORD PTR [r12+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_252f:
	/* 0x252f: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2533:
	/* 0x2533: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2537:
	/* 0x2537: cmp    WORD PTR [r12+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_2541:
	/* 0x2541: je     2c61 <generic_sleepable_preload+0x2c61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11361ULL;
	}
x86_l_2547:
	/* 0x2547: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_254a:
	/* 0x254a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_254f:
	/* 0x254f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2554:
	/* 0x2554: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2558:
	/* 0x2558: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_255d:
	/* 0x255d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_255f:
	/* 0x255f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2561:
	/* 0x2561: jns    2c61 <generic_sleepable_preload+0x2c61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 11361ULL;
	}
x86_l_2567:
	/* 0x2567: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_256c:
	/* 0x256c: jmp    2c5e <generic_sleepable_preload+0x2c5e> */
	return 11358ULL;
x86_l_2571:
	/* 0x2571: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_2576:
	/* 0x2576: jmp    2c5e <generic_sleepable_preload+0x2c5e> */
	return 11358ULL;
x86_l_257b:
	/* 0x257b: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2583:
	/* 0x2583: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_2586:
	/* 0x2586: je     25e8 <generic_sleepable_preload+0x25e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25e8;
	}
x86_l_2588:
	/* 0x2588: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_258d:
	/* 0x258d: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_2590:
	/* 0x2590: je     25e8 <generic_sleepable_preload+0x25e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25e8;
	}
x86_l_2592:
	/* 0x2592: jmp    25fb <generic_sleepable_preload+0x25fb> */
	goto x86_l_25fb;
x86_l_2594:
	/* 0x2594: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2599:
	/* 0x2599: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_259c:
	/* 0x259c: je     25e8 <generic_sleepable_preload+0x25e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25e8;
	}
x86_l_259e:
	/* 0x259e: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_25a3:
	/* 0x25a3: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_25a6:
	/* 0x25a6: je     25e8 <generic_sleepable_preload+0x25e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25e8;
	}
x86_l_25a8:
	/* 0x25a8: jmp    25fb <generic_sleepable_preload+0x25fb> */
	goto x86_l_25fb;
x86_l_25aa:
	/* 0x25aa: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_25b2:
	/* 0x25b2: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_25b5:
	/* 0x25b5: je     25e8 <generic_sleepable_preload+0x25e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25e8;
	}
x86_l_25b7:
	/* 0x25b7: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_25bc:
	/* 0x25bc: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_25bf:
	/* 0x25bf: je     25e8 <generic_sleepable_preload+0x25e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25e8;
	}
x86_l_25c1:
	/* 0x25c1: jmp    25fb <generic_sleepable_preload+0x25fb> */
	goto x86_l_25fb;
x86_l_25c3:
	/* 0x25c3: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_25c8:
	/* 0x25c8: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_25cb:
	/* 0x25cb: je     25e8 <generic_sleepable_preload+0x25e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25e8;
	}
x86_l_25cd:
	/* 0x25cd: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_25d2:
	/* 0x25d2: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_25d5:
	/* 0x25d5: je     25e8 <generic_sleepable_preload+0x25e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25e8;
	}
x86_l_25d7:
	/* 0x25d7: jmp    25fb <generic_sleepable_preload+0x25fb> */
	goto x86_l_25fb;
x86_l_25d9:
	/* 0x25d9: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_25de:
	/* 0x25de: jmp    2c5e <generic_sleepable_preload+0x2c5e> */
	return 11358ULL;
x86_l_25e3:
	/* 0x25e3: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_25e8:
	/* 0x25e8: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_25eb:
	/* 0x25eb: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_25ed:
	/* 0x25ed: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_25ef:
	/* 0x25ef: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_25f4:
	/* 0x25f4: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_25f6:
	/* 0x25f6: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_25fb:
	/* 0x25fb: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25ff:
	/* 0x25ff: mov    ebp,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2604:
	/* 0x2604: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2606:
	/* 0x2606: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_2609:
	/* 0x2609: cmp    WORD PTR [r12+0xc6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 850403524608ULL);
x86_l_2613:
	/* 0x2613: je     2cec <generic_sleepable_preload+0x2cec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11500ULL;
	}
x86_l_2619:
	/* 0x2619: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_2620:
	/* 0x2620: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2623:
	/* 0x2623: mov    eax,DWORD PTR [r12+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_262b:
	/* 0x262b: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_262e:
	/* 0x262e: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2632:
	/* 0x2632: movzx  eax,WORD PTR [r12+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 196ULL);
x86_l_263b:
	/* 0x263b: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_263d:
	/* 0x263d: je     290f <generic_sleepable_preload+0x290f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10511ULL;
	}
x86_l_2643:
	/* 0x2643: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_2646:
	/* 0x2646: je     2668 <generic_sleepable_preload+0x2668> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2668;
	}
x86_l_2648:
	/* 0x2648: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_264b:
	/* 0x264b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2650:
	/* 0x2650: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2655:
	/* 0x2655: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2659:
	/* 0x2659: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_265e:
	/* 0x265e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2660:
	/* 0x2660: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2662:
	/* 0x2662: js     2c01 <generic_sleepable_preload+0x2c01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11265ULL;
	}
x86_l_2668:
	/* 0x2668: cmp    WORD PTR [r12+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_2672:
	/* 0x2672: je     2cec <generic_sleepable_preload+0x2cec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11500ULL;
	}
x86_l_2678:
	/* 0x2678: mov    ecx,DWORD PTR [r12+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2680:
	/* 0x2680: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2684:
	/* 0x2684: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2688:
	/* 0x2688: cmp    WORD PTR [r12+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_2692:
	/* 0x2692: je     26b4 <generic_sleepable_preload+0x26b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26b4;
	}
x86_l_2694:
	/* 0x2694: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2697:
	/* 0x2697: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_269c:
	/* 0x269c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_26a1:
	/* 0x26a1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26a5:
	/* 0x26a5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26aa:
	/* 0x26aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26ac:
	/* 0x26ac: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_26ae:
	/* 0x26ae: js     2c0b <generic_sleepable_preload+0x2c0b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11275ULL;
	}
x86_l_26b4:
	/* 0x26b4: cmp    WORD PTR [r12+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_26be:
	/* 0x26be: je     2cec <generic_sleepable_preload+0x2cec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11500ULL;
	}
x86_l_26c4:
	/* 0x26c4: mov    ecx,DWORD PTR [r12+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_26cc:
	/* 0x26cc: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_26d0:
	/* 0x26d0: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26d4:
	/* 0x26d4: cmp    WORD PTR [r12+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_26de:
	/* 0x26de: je     2700 <generic_sleepable_preload+0x2700> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2700;
	}
x86_l_26e0:
	/* 0x26e0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_26e3:
	/* 0x26e3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_26e8:
	/* 0x26e8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_26ed:
	/* 0x26ed: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26f1:
	/* 0x26f1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26f6:
	/* 0x26f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26f8:
	/* 0x26f8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_26fa:
	/* 0x26fa: js     2c1c <generic_sleepable_preload+0x2c1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11292ULL;
	}
x86_l_2700:
	/* 0x2700: cmp    WORD PTR [r12+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_270a:
	/* 0x270a: je     2cec <generic_sleepable_preload+0x2cec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11500ULL;
	}
x86_l_2710:
	/* 0x2710: mov    ecx,DWORD PTR [r12+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_2718:
	/* 0x2718: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_271c:
	/* 0x271c: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2720:
	/* 0x2720: cmp    WORD PTR [r12+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_272a:
	/* 0x272a: je     274c <generic_sleepable_preload+0x274c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_274c;
	}
x86_l_272c:
	/* 0x272c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_272f:
	/* 0x272f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2734:
	/* 0x2734: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2739:
	/* 0x2739: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_273d:
	/* 0x273d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2742:
	/* 0x2742: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2744:
	/* 0x2744: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2746:
	/* 0x2746: js     2c2d <generic_sleepable_preload+0x2c2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11309ULL;
	}
x86_l_274c:
	/* 0x274c: cmp    WORD PTR [r12+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_2756:
	/* 0x2756: je     2cec <generic_sleepable_preload+0x2cec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11500ULL;
	}
x86_l_275c:
	/* 0x275c: mov    ecx,DWORD PTR [r12+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_2764:
	/* 0x2764: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2768:
	/* 0x2768: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_276c:
	/* 0x276c: cmp    WORD PTR [r12+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_2776:
	/* 0x2776: je     2798 <generic_sleepable_preload+0x2798> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2798;
	}
x86_l_2778:
	/* 0x2778: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_277b:
	/* 0x277b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2780:
	/* 0x2780: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2785:
	/* 0x2785: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2789:
	/* 0x2789: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_278e:
	/* 0x278e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2790:
	/* 0x2790: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2792:
	/* 0x2792: js     2c3e <generic_sleepable_preload+0x2c3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11326ULL;
	}
x86_l_2798:
	/* 0x2798: cmp    WORD PTR [r12+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_27a2:
	/* 0x27a2: je     2cec <generic_sleepable_preload+0x2cec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11500ULL;
	}
x86_l_27a8:
	/* 0x27a8: mov    ecx,DWORD PTR [r12+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_27b0:
	/* 0x27b0: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_27b4:
	/* 0x27b4: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27b8:
	/* 0x27b8: cmp    WORD PTR [r12+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_27c2:
	/* 0x27c2: je     27e4 <generic_sleepable_preload+0x27e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27e4;
	}
x86_l_27c4:
	/* 0x27c4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_27c7:
	/* 0x27c7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_27cc:
	/* 0x27cc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_27d1:
	/* 0x27d1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27d5:
	/* 0x27d5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27da:
	/* 0x27da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27dc:
	/* 0x27dc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_27de:
	/* 0x27de: js     2c4f <generic_sleepable_preload+0x2c4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11343ULL;
	}
x86_l_27e4:
	/* 0x27e4: cmp    WORD PTR [r12+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_27ee:
	/* 0x27ee: je     2cec <generic_sleepable_preload+0x2cec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11500ULL;
	}
x86_l_27f4:
	/* 0x27f4: mov    ecx,DWORD PTR [r12+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_27fc:
	/* 0x27fc: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2800:
	/* 0x2800: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2804:
	/* 0x2804: cmp    WORD PTR [r12+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_280e:
	/* 0x280e: je     2830 <generic_sleepable_preload+0x2830> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2830;
	}
x86_l_2810:
	/* 0x2810: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2813:
	/* 0x2813: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2818:
	/* 0x2818: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_281d:
	/* 0x281d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2821:
	/* 0x2821: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2826:
	/* 0x2826: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2828:
	/* 0x2828: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_282a:
	/* 0x282a: js     2ce4 <generic_sleepable_preload+0x2ce4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11492ULL;
	}
x86_l_2830:
	/* 0x2830: cmp    WORD PTR [r12+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_283a:
	/* 0x283a: je     2cec <generic_sleepable_preload+0x2cec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11500ULL;
	}
x86_l_2840:
	/* 0x2840: mov    ecx,DWORD PTR [r12+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_2848:
	/* 0x2848: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_284c:
	/* 0x284c: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2850:
	/* 0x2850: cmp    WORD PTR [r12+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_285a:
	/* 0x285a: je     287c <generic_sleepable_preload+0x287c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_287c;
	}
x86_l_285c:
	/* 0x285c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_285f:
	/* 0x285f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2864:
	/* 0x2864: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2869:
	/* 0x2869: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_286d:
	/* 0x286d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2872:
	/* 0x2872: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2874:
	/* 0x2874: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2876:
	/* 0x2876: js     5be9 <generic_sleepable_preload+0x5be9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23529ULL;
	}
x86_l_287c:
	/* 0x287c: cmp    WORD PTR [r12+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_2886:
	/* 0x2886: je     2cec <generic_sleepable_preload+0x2cec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11500ULL;
	}
x86_l_288c:
	/* 0x288c: mov    ecx,DWORD PTR [r12+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_2894:
	/* 0x2894: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2898:
	/* 0x2898: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
	return 10396ULL;
}

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10396ULL: goto x86_l_289c;
	case 10406ULL: goto x86_l_28a6;
	case 10408ULL: goto x86_l_28a8;
	case 10411ULL: goto x86_l_28ab;
	case 10416ULL: goto x86_l_28b0;
	case 10421ULL: goto x86_l_28b5;
	case 10425ULL: goto x86_l_28b9;
	case 10430ULL: goto x86_l_28be;
	case 10432ULL: goto x86_l_28c0;
	case 10434ULL: goto x86_l_28c2;
	case 10440ULL: goto x86_l_28c8;
	case 10445ULL: goto x86_l_28cd;
	case 10455ULL: goto x86_l_28d7;
	case 10461ULL: goto x86_l_28dd;
	case 10469ULL: goto x86_l_28e5;
	case 10473ULL: goto x86_l_28e9;
	case 10477ULL: goto x86_l_28ed;
	case 10487ULL: goto x86_l_28f7;
	case 10493ULL: goto x86_l_28fd;
	case 10496ULL: goto x86_l_2900;
	case 10501ULL: goto x86_l_2905;
	case 10506ULL: goto x86_l_290a;
	case 10511ULL: goto x86_l_290f;
	case 10514ULL: goto x86_l_2912;
	case 10516ULL: goto x86_l_2914;
	case 10519ULL: goto x86_l_2917;
	case 10524ULL: goto x86_l_291c;
	case 10529ULL: goto x86_l_2921;
	case 10533ULL: goto x86_l_2925;
	case 10538ULL: goto x86_l_292a;
	case 10540ULL: goto x86_l_292c;
	case 10542ULL: goto x86_l_292e;
	case 10548ULL: goto x86_l_2934;
	case 10558ULL: goto x86_l_293e;
	case 10564ULL: goto x86_l_2944;
	case 10572ULL: goto x86_l_294c;
	case 10576ULL: goto x86_l_2950;
	case 10580ULL: goto x86_l_2954;
	case 10590ULL: goto x86_l_295e;
	case 10592ULL: goto x86_l_2960;
	case 10595ULL: goto x86_l_2963;
	case 10600ULL: goto x86_l_2968;
	case 10605ULL: goto x86_l_296d;
	case 10609ULL: goto x86_l_2971;
	case 10614ULL: goto x86_l_2976;
	case 10616ULL: goto x86_l_2978;
	case 10618ULL: goto x86_l_297a;
	case 10624ULL: goto x86_l_2980;
	case 10634ULL: goto x86_l_298a;
	case 10640ULL: goto x86_l_2990;
	case 10648ULL: goto x86_l_2998;
	case 10652ULL: goto x86_l_299c;
	case 10656ULL: goto x86_l_29a0;
	case 10666ULL: goto x86_l_29aa;
	case 10668ULL: goto x86_l_29ac;
	case 10671ULL: goto x86_l_29af;
	case 10676ULL: goto x86_l_29b4;
	case 10681ULL: goto x86_l_29b9;
	case 10685ULL: goto x86_l_29bd;
	case 10690ULL: goto x86_l_29c2;
	case 10692ULL: goto x86_l_29c4;
	case 10694ULL: goto x86_l_29c6;
	case 10700ULL: goto x86_l_29cc;
	case 10710ULL: goto x86_l_29d6;
	case 10716ULL: goto x86_l_29dc;
	case 10724ULL: goto x86_l_29e4;
	case 10728ULL: goto x86_l_29e8;
	case 10732ULL: goto x86_l_29ec;
	case 10742ULL: goto x86_l_29f6;
	case 10744ULL: goto x86_l_29f8;
	case 10747ULL: goto x86_l_29fb;
	case 10752ULL: goto x86_l_2a00;
	case 10757ULL: goto x86_l_2a05;
	case 10761ULL: goto x86_l_2a09;
	case 10766ULL: goto x86_l_2a0e;
	case 10768ULL: goto x86_l_2a10;
	case 10770ULL: goto x86_l_2a12;
	case 10776ULL: goto x86_l_2a18;
	case 10786ULL: goto x86_l_2a22;
	case 10792ULL: goto x86_l_2a28;
	case 10800ULL: goto x86_l_2a30;
	case 10804ULL: goto x86_l_2a34;
	case 10808ULL: goto x86_l_2a38;
	case 10818ULL: goto x86_l_2a42;
	case 10820ULL: goto x86_l_2a44;
	case 10823ULL: goto x86_l_2a47;
	case 10828ULL: goto x86_l_2a4c;
	case 10833ULL: goto x86_l_2a51;
	case 10837ULL: goto x86_l_2a55;
	case 10842ULL: goto x86_l_2a5a;
	case 10844ULL: goto x86_l_2a5c;
	case 10846ULL: goto x86_l_2a5e;
	case 10852ULL: goto x86_l_2a64;
	case 10862ULL: goto x86_l_2a6e;
	case 10868ULL: goto x86_l_2a74;
	case 10876ULL: goto x86_l_2a7c;
	case 10880ULL: goto x86_l_2a80;
	case 10884ULL: goto x86_l_2a84;
	case 10894ULL: goto x86_l_2a8e;
	case 10896ULL: goto x86_l_2a90;
	case 10899ULL: goto x86_l_2a93;
	case 10904ULL: goto x86_l_2a98;
	case 10909ULL: goto x86_l_2a9d;
	case 10913ULL: goto x86_l_2aa1;
	case 10918ULL: goto x86_l_2aa6;
	case 10920ULL: goto x86_l_2aa8;
	case 10922ULL: goto x86_l_2aaa;
	case 10928ULL: goto x86_l_2ab0;
	case 10938ULL: goto x86_l_2aba;
	case 10944ULL: goto x86_l_2ac0;
	case 10952ULL: goto x86_l_2ac8;
	case 10956ULL: goto x86_l_2acc;
	case 10960ULL: goto x86_l_2ad0;
	case 10970ULL: goto x86_l_2ada;
	case 10972ULL: goto x86_l_2adc;
	case 10975ULL: goto x86_l_2adf;
	case 10980ULL: goto x86_l_2ae4;
	case 10985ULL: goto x86_l_2ae9;
	case 10989ULL: goto x86_l_2aed;
	case 10994ULL: goto x86_l_2af2;
	case 10996ULL: goto x86_l_2af4;
	case 10998ULL: goto x86_l_2af6;
	case 11004ULL: goto x86_l_2afc;
	case 11014ULL: goto x86_l_2b06;
	case 11020ULL: goto x86_l_2b0c;
	case 11023ULL: goto x86_l_2b0f;
	case 11031ULL: goto x86_l_2b17;
	case 11035ULL: goto x86_l_2b1b;
	case 11039ULL: goto x86_l_2b1f;
	case 11049ULL: goto x86_l_2b29;
	case 11051ULL: goto x86_l_2b2b;
	case 11054ULL: goto x86_l_2b2e;
	case 11059ULL: goto x86_l_2b33;
	case 11064ULL: goto x86_l_2b38;
	case 11068ULL: goto x86_l_2b3c;
	case 11073ULL: goto x86_l_2b41;
	case 11075ULL: goto x86_l_2b43;
	case 11077ULL: goto x86_l_2b45;
	case 11083ULL: goto x86_l_2b4b;
	case 11088ULL: goto x86_l_2b50;
	case 11098ULL: goto x86_l_2b5a;
	case 11101ULL: goto x86_l_2b5d;
	case 11107ULL: goto x86_l_2b63;
	case 11115ULL: goto x86_l_2b6b;
	case 11119ULL: goto x86_l_2b6f;
	case 11123ULL: goto x86_l_2b73;
	case 11133ULL: goto x86_l_2b7d;
	case 11135ULL: goto x86_l_2b7f;
	case 11138ULL: goto x86_l_2b82;
	case 11143ULL: goto x86_l_2b87;
	case 11148ULL: goto x86_l_2b8c;
	case 11152ULL: goto x86_l_2b90;
	case 11157ULL: goto x86_l_2b95;
	case 11159ULL: goto x86_l_2b97;
	case 11161ULL: goto x86_l_2b99;
	case 11167ULL: goto x86_l_2b9f;
	case 11172ULL: goto x86_l_2ba4;
	case 11182ULL: goto x86_l_2bae;
	case 11185ULL: goto x86_l_2bb1;
	case 11191ULL: goto x86_l_2bb7;
	case 11199ULL: goto x86_l_2bbf;
	case 11203ULL: goto x86_l_2bc3;
	case 11207ULL: goto x86_l_2bc7;
	case 11217ULL: goto x86_l_2bd1;
	case 11223ULL: goto x86_l_2bd7;
	case 11226ULL: goto x86_l_2bda;
	case 11231ULL: goto x86_l_2bdf;
	case 11236ULL: goto x86_l_2be4;
	case 11240ULL: goto x86_l_2be8;
	case 11245ULL: goto x86_l_2bed;
	case 11247ULL: goto x86_l_2bef;
	case 11249ULL: goto x86_l_2bf1;
	case 11255ULL: goto x86_l_2bf7;
	case 11260ULL: goto x86_l_2bfc;
	case 11265ULL: goto x86_l_2c01;
	case 11270ULL: goto x86_l_2c06;
	case 11275ULL: goto x86_l_2c0b;
	case 11280ULL: goto x86_l_2c10;
	case 11285ULL: goto x86_l_2c15;
	case 11290ULL: goto x86_l_2c1a;
	case 11292ULL: goto x86_l_2c1c;
	case 11297ULL: goto x86_l_2c21;
	case 11302ULL: goto x86_l_2c26;
	case 11307ULL: goto x86_l_2c2b;
	case 11309ULL: goto x86_l_2c2d;
	case 11314ULL: goto x86_l_2c32;
	case 11319ULL: goto x86_l_2c37;
	case 11324ULL: goto x86_l_2c3c;
	case 11326ULL: goto x86_l_2c3e;
	case 11331ULL: goto x86_l_2c43;
	case 11336ULL: goto x86_l_2c48;
	case 11341ULL: goto x86_l_2c4d;
	case 11343ULL: goto x86_l_2c4f;
	case 11348ULL: goto x86_l_2c54;
	case 11353ULL: goto x86_l_2c59;
	case 11358ULL: goto x86_l_2c5e;
	case 11361ULL: goto x86_l_2c61;
	case 11366ULL: goto x86_l_2c66;
	case 11369ULL: goto x86_l_2c69;
	case 11374ULL: goto x86_l_2c6e;
	case 11379ULL: goto x86_l_2c73;
	case 11384ULL: goto x86_l_2c78;
	case 11387ULL: goto x86_l_2c7b;
	case 11389ULL: goto x86_l_2c7d;
	case 11392ULL: goto x86_l_2c80;
	case 11398ULL: goto x86_l_2c86;
	case 11401ULL: goto x86_l_2c89;
	case 11405ULL: goto x86_l_2c8d;
	case 11410ULL: goto x86_l_2c92;
	case 11412ULL: goto x86_l_2c94;
	case 11417ULL: goto x86_l_2c99;
	case 11425ULL: goto x86_l_2ca1;
	case 11432ULL: goto x86_l_2ca8;
	case 11437ULL: goto x86_l_2cad;
	case 11442ULL: goto x86_l_2cb2;
	case 11444ULL: goto x86_l_2cb4;
	case 11447ULL: goto x86_l_2cb7;
	case 11453ULL: goto x86_l_2cbd;
	case 11456ULL: goto x86_l_2cc0;
	case 11463ULL: goto x86_l_2cc7;
	case 11465ULL: goto x86_l_2cc9;
	case 11470ULL: goto x86_l_2cce;
	case 11475ULL: goto x86_l_2cd3;
	case 11478ULL: goto x86_l_2cd6;
	case 11481ULL: goto x86_l_2cd9;
	case 11483ULL: goto x86_l_2cdb;
	case 11485ULL: goto x86_l_2cdd;
	case 11490ULL: goto x86_l_2ce2;
	case 11492ULL: goto x86_l_2ce4;
	case 11497ULL: goto x86_l_2ce9;
	case 11500ULL: goto x86_l_2cec;
	case 11503ULL: goto x86_l_2cef;
	case 11509ULL: goto x86_l_2cf5;
	case 11512ULL: goto x86_l_2cf8;
	case 11516ULL: goto x86_l_2cfc;
	case 11521ULL: goto x86_l_2d01;
	case 11523ULL: goto x86_l_2d03;
	case 11528ULL: goto x86_l_2d08;
	case 11536ULL: goto x86_l_2d10;
	case 11543ULL: goto x86_l_2d17;
	case 11548ULL: goto x86_l_2d1c;
	case 11553ULL: goto x86_l_2d21;
	case 11555ULL: goto x86_l_2d23;
	case 11558ULL: goto x86_l_2d26;
	case 11560ULL: goto x86_l_2d28;
	case 11563ULL: goto x86_l_2d2b;
	case 11570ULL: goto x86_l_2d32;
	case 11572ULL: goto x86_l_2d34;
	case 11577ULL: goto x86_l_2d39;
	case 11582ULL: goto x86_l_2d3e;
	case 11585ULL: goto x86_l_2d41;
	case 11588ULL: goto x86_l_2d44;
	case 11590ULL: goto x86_l_2d46;
	case 11592ULL: goto x86_l_2d48;
	case 11597ULL: goto x86_l_2d4d;
	case 11600ULL: goto x86_l_2d50;
	case 11603ULL: goto x86_l_2d53;
	case 11608ULL: goto x86_l_2d58;
	case 11610ULL: goto x86_l_2d5a;
	case 11613ULL: goto x86_l_2d5d;
	case 11615ULL: goto x86_l_2d5f;
	case 11618ULL: goto x86_l_2d62;
	case 11620ULL: goto x86_l_2d64;
	case 11623ULL: goto x86_l_2d67;
	case 11627ULL: goto x86_l_2d6b;
	case 11632ULL: goto x86_l_2d70;
	case 11635ULL: goto x86_l_2d73;
	case 11637ULL: goto x86_l_2d75;
	case 11640ULL: goto x86_l_2d78;
	case 11645ULL: goto x86_l_2d7d;
	case 11647ULL: goto x86_l_2d7f;
	case 11650ULL: goto x86_l_2d82;
	case 11652ULL: goto x86_l_2d84;
	case 11657ULL: goto x86_l_2d89;
	case 11660ULL: goto x86_l_2d8c;
	case 11662ULL: goto x86_l_2d8e;
	case 11665ULL: goto x86_l_2d91;
	case 11670ULL: goto x86_l_2d96;
	case 11675ULL: goto x86_l_2d9b;
	case 11681ULL: goto x86_l_2da1;
	case 11683ULL: goto x86_l_2da3;
	case 11685ULL: goto x86_l_2da5;
	case 11690ULL: goto x86_l_2daa;
	case 11693ULL: goto x86_l_2dad;
	case 11699ULL: goto x86_l_2db3;
	case 11702ULL: goto x86_l_2db6;
	case 11708ULL: goto x86_l_2dbc;
	case 11711ULL: goto x86_l_2dbf;
	case 11717ULL: goto x86_l_2dc5;
	case 11720ULL: goto x86_l_2dc8;
	case 11726ULL: goto x86_l_2dce;
	case 11731ULL: goto x86_l_2dd3;
	case 11736ULL: goto x86_l_2dd8;
	case 11745ULL: goto x86_l_2de1;
	case 11754ULL: goto x86_l_2dea;
	case 11760ULL: goto x86_l_2df0;
	case 11762ULL: goto x86_l_2df2;
	case 11765ULL: goto x86_l_2df5;
	case 11767ULL: goto x86_l_2df7;
	case 11770ULL: goto x86_l_2dfa;
	case 11772ULL: goto x86_l_2dfc;
	case 11775ULL: goto x86_l_2dff;
	case 11781ULL: goto x86_l_2e05;
	case 11786ULL: goto x86_l_2e0a;
	case 11789ULL: goto x86_l_2e0d;
	case 11795ULL: goto x86_l_2e13;
	case 11800ULL: goto x86_l_2e18;
	case 11803ULL: goto x86_l_2e1b;
	case 11809ULL: goto x86_l_2e21;
	case 11814ULL: goto x86_l_2e26;
	case 11817ULL: goto x86_l_2e29;
	case 11823ULL: goto x86_l_2e2f;
	case 11828ULL: goto x86_l_2e34;
	case 11831ULL: goto x86_l_2e37;
	case 11833ULL: goto x86_l_2e39;
	case 11836ULL: goto x86_l_2e3c;
	case 11842ULL: goto x86_l_2e42;
	case 11844ULL: goto x86_l_2e44;
	case 11850ULL: goto x86_l_2e4a;
	case 11853ULL: goto x86_l_2e4d;
	case 11856ULL: goto x86_l_2e50;
	case 11862ULL: goto x86_l_2e56;
	case 11867ULL: goto x86_l_2e5b;
	case 11869ULL: goto x86_l_2e5d;
	case 11871ULL: goto x86_l_2e5f;
	case 11874ULL: goto x86_l_2e62;
	case 11876ULL: goto x86_l_2e64;
	case 11881ULL: goto x86_l_2e69;
	case 11883ULL: goto x86_l_2e6b;
	case 11886ULL: goto x86_l_2e6e;
	case 11892ULL: goto x86_l_2e74;
	case 11900ULL: goto x86_l_2e7c;
	case 11903ULL: goto x86_l_2e7f;
	case 11909ULL: goto x86_l_2e85;
	case 11914ULL: goto x86_l_2e8a;
	case 11917ULL: goto x86_l_2e8d;
	case 11923ULL: goto x86_l_2e93;
	case 11928ULL: goto x86_l_2e98;
	case 11931ULL: goto x86_l_2e9b;
	case 11937ULL: goto x86_l_2ea1;
	case 11945ULL: goto x86_l_2ea9;
	case 11948ULL: goto x86_l_2eac;
	case 11954ULL: goto x86_l_2eb2;
	case 11959ULL: goto x86_l_2eb7;
	case 11962ULL: goto x86_l_2eba;
	case 11968ULL: goto x86_l_2ec0;
	case 11973ULL: goto x86_l_2ec5;
	case 11978ULL: goto x86_l_2eca;
	case 11980ULL: goto x86_l_2ecc;
	case 11985ULL: goto x86_l_2ed1;
	case 11987ULL: goto x86_l_2ed3;
	case 11992ULL: goto x86_l_2ed8;
	case 11995ULL: goto x86_l_2edb;
	case 11999ULL: goto x86_l_2edf;
	case 12001ULL: goto x86_l_2ee1;
	case 12004ULL: goto x86_l_2ee4;
	case 12014ULL: goto x86_l_2eee;
	case 12020ULL: goto x86_l_2ef4;
	case 12027ULL: goto x86_l_2efb;
	case 12030ULL: goto x86_l_2efe;
	case 12038ULL: goto x86_l_2f06;
	case 12041ULL: goto x86_l_2f09;
	case 12045ULL: goto x86_l_2f0d;
	case 12054ULL: goto x86_l_2f16;
	case 12056ULL: goto x86_l_2f18;
	case 12062ULL: goto x86_l_2f1e;
	case 12065ULL: goto x86_l_2f21;
	case 12067ULL: goto x86_l_2f23;
	case 12070ULL: goto x86_l_2f26;
	case 12075ULL: goto x86_l_2f2b;
	case 12080ULL: goto x86_l_2f30;
	case 12084ULL: goto x86_l_2f34;
	case 12089ULL: goto x86_l_2f39;
	case 12091ULL: goto x86_l_2f3b;
	case 12093ULL: goto x86_l_2f3d;
	case 12099ULL: goto x86_l_2f43;
	case 12109ULL: goto x86_l_2f4d;
	case 12115ULL: goto x86_l_2f53;
	case 12123ULL: goto x86_l_2f5b;
	case 12127ULL: goto x86_l_2f5f;
	case 12131ULL: goto x86_l_2f63;
	case 12141ULL: goto x86_l_2f6d;
	case 12143ULL: goto x86_l_2f6f;
	case 12146ULL: goto x86_l_2f72;
	default: return 0xffffffffffffffffULL;
	}
x86_l_289c:
	/* 0x289c: cmp    WORD PTR [r12+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_28a6:
	/* 0x28a6: je     28c8 <generic_sleepable_preload+0x28c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28c8;
	}
x86_l_28a8:
	/* 0x28a8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_28ab:
	/* 0x28ab: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_28b0:
	/* 0x28b0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_28b5:
	/* 0x28b5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28b9:
	/* 0x28b9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28be:
	/* 0x28be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28c0:
	/* 0x28c0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_28c2:
	/* 0x28c2: js     5cde <generic_sleepable_preload+0x5cde> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23774ULL;
	}
x86_l_28c8:
	/* 0x28c8: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28cd:
	/* 0x28cd: cmp    WORD PTR [r12+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_28d7:
	/* 0x28d7: je     2cec <generic_sleepable_preload+0x2cec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cec;
	}
x86_l_28dd:
	/* 0x28dd: mov    ecx,DWORD PTR [r12+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_28e5:
	/* 0x28e5: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_28e9:
	/* 0x28e9: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28ed:
	/* 0x28ed: cmp    WORD PTR [r12+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_28f7:
	/* 0x28f7: je     2cec <generic_sleepable_preload+0x2cec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cec;
	}
x86_l_28fd:
	/* 0x28fd: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2900:
	/* 0x2900: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2905:
	/* 0x2905: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_290a:
	/* 0x290a: jmp    2be4 <generic_sleepable_preload+0x2be4> */
	goto x86_l_2be4;
x86_l_290f:
	/* 0x290f: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_2912:
	/* 0x2912: je     2934 <generic_sleepable_preload+0x2934> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2934;
	}
x86_l_2914:
	/* 0x2914: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2917:
	/* 0x2917: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_291c:
	/* 0x291c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2921:
	/* 0x2921: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2925:
	/* 0x2925: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_292a:
	/* 0x292a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_292c:
	/* 0x292c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_292e:
	/* 0x292e: js     2c01 <generic_sleepable_preload+0x2c01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2c01;
	}
x86_l_2934:
	/* 0x2934: cmp    WORD PTR [r12+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_293e:
	/* 0x293e: je     2cec <generic_sleepable_preload+0x2cec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cec;
	}
x86_l_2944:
	/* 0x2944: mov    ecx,DWORD PTR [r12+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_294c:
	/* 0x294c: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2950:
	/* 0x2950: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2954:
	/* 0x2954: cmp    WORD PTR [r12+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_295e:
	/* 0x295e: je     2980 <generic_sleepable_preload+0x2980> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2980;
	}
x86_l_2960:
	/* 0x2960: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2963:
	/* 0x2963: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2968:
	/* 0x2968: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_296d:
	/* 0x296d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2971:
	/* 0x2971: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2976:
	/* 0x2976: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2978:
	/* 0x2978: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_297a:
	/* 0x297a: js     2c0b <generic_sleepable_preload+0x2c0b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2c0b;
	}
x86_l_2980:
	/* 0x2980: cmp    WORD PTR [r12+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_298a:
	/* 0x298a: je     2cec <generic_sleepable_preload+0x2cec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cec;
	}
x86_l_2990:
	/* 0x2990: mov    ecx,DWORD PTR [r12+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_2998:
	/* 0x2998: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_299c:
	/* 0x299c: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29a0:
	/* 0x29a0: cmp    WORD PTR [r12+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_29aa:
	/* 0x29aa: je     29cc <generic_sleepable_preload+0x29cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29cc;
	}
x86_l_29ac:
	/* 0x29ac: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_29af:
	/* 0x29af: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_29b4:
	/* 0x29b4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_29b9:
	/* 0x29b9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29bd:
	/* 0x29bd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29c2:
	/* 0x29c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29c4:
	/* 0x29c4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_29c6:
	/* 0x29c6: js     2c1c <generic_sleepable_preload+0x2c1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2c1c;
	}
x86_l_29cc:
	/* 0x29cc: cmp    WORD PTR [r12+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_29d6:
	/* 0x29d6: je     2cec <generic_sleepable_preload+0x2cec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cec;
	}
x86_l_29dc:
	/* 0x29dc: mov    ecx,DWORD PTR [r12+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_29e4:
	/* 0x29e4: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_29e8:
	/* 0x29e8: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29ec:
	/* 0x29ec: cmp    WORD PTR [r12+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_29f6:
	/* 0x29f6: je     2a18 <generic_sleepable_preload+0x2a18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a18;
	}
x86_l_29f8:
	/* 0x29f8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_29fb:
	/* 0x29fb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2a00:
	/* 0x2a00: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2a05:
	/* 0x2a05: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a09:
	/* 0x2a09: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a0e:
	/* 0x2a0e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a10:
	/* 0x2a10: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a12:
	/* 0x2a12: js     2c2d <generic_sleepable_preload+0x2c2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2c2d;
	}
x86_l_2a18:
	/* 0x2a18: cmp    WORD PTR [r12+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_2a22:
	/* 0x2a22: je     2cec <generic_sleepable_preload+0x2cec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cec;
	}
x86_l_2a28:
	/* 0x2a28: mov    ecx,DWORD PTR [r12+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_2a30:
	/* 0x2a30: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2a34:
	/* 0x2a34: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a38:
	/* 0x2a38: cmp    WORD PTR [r12+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_2a42:
	/* 0x2a42: je     2a64 <generic_sleepable_preload+0x2a64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a64;
	}
x86_l_2a44:
	/* 0x2a44: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2a47:
	/* 0x2a47: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2a4c:
	/* 0x2a4c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2a51:
	/* 0x2a51: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a55:
	/* 0x2a55: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a5a:
	/* 0x2a5a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a5c:
	/* 0x2a5c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a5e:
	/* 0x2a5e: js     2c3e <generic_sleepable_preload+0x2c3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2c3e;
	}
x86_l_2a64:
	/* 0x2a64: cmp    WORD PTR [r12+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_2a6e:
	/* 0x2a6e: je     2cec <generic_sleepable_preload+0x2cec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cec;
	}
x86_l_2a74:
	/* 0x2a74: mov    ecx,DWORD PTR [r12+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_2a7c:
	/* 0x2a7c: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2a80:
	/* 0x2a80: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a84:
	/* 0x2a84: cmp    WORD PTR [r12+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_2a8e:
	/* 0x2a8e: je     2ab0 <generic_sleepable_preload+0x2ab0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ab0;
	}
x86_l_2a90:
	/* 0x2a90: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2a93:
	/* 0x2a93: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2a98:
	/* 0x2a98: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2a9d:
	/* 0x2a9d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2aa1:
	/* 0x2aa1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2aa6:
	/* 0x2aa6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2aa8:
	/* 0x2aa8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2aaa:
	/* 0x2aaa: js     2c4f <generic_sleepable_preload+0x2c4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2c4f;
	}
x86_l_2ab0:
	/* 0x2ab0: cmp    WORD PTR [r12+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_2aba:
	/* 0x2aba: je     2cec <generic_sleepable_preload+0x2cec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cec;
	}
x86_l_2ac0:
	/* 0x2ac0: mov    ecx,DWORD PTR [r12+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_2ac8:
	/* 0x2ac8: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2acc:
	/* 0x2acc: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ad0:
	/* 0x2ad0: cmp    WORD PTR [r12+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_2ada:
	/* 0x2ada: je     2afc <generic_sleepable_preload+0x2afc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2afc;
	}
x86_l_2adc:
	/* 0x2adc: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2adf:
	/* 0x2adf: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2ae4:
	/* 0x2ae4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2ae9:
	/* 0x2ae9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2aed:
	/* 0x2aed: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2af2:
	/* 0x2af2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2af4:
	/* 0x2af4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2af6:
	/* 0x2af6: js     2ce4 <generic_sleepable_preload+0x2ce4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2ce4;
	}
x86_l_2afc:
	/* 0x2afc: cmp    WORD PTR [r12+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_2b06:
	/* 0x2b06: je     2cec <generic_sleepable_preload+0x2cec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cec;
	}
x86_l_2b0c:
	/* 0x2b0c: mov    r15,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R14, X86_WIDTH_64);
x86_l_2b0f:
	/* 0x2b0f: mov    ecx,DWORD PTR [r12+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_2b17:
	/* 0x2b17: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2b1b:
	/* 0x2b1b: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b1f:
	/* 0x2b1f: cmp    WORD PTR [r12+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_2b29:
	/* 0x2b29: je     2b4b <generic_sleepable_preload+0x2b4b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b4b;
	}
x86_l_2b2b:
	/* 0x2b2b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2b2e:
	/* 0x2b2e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2b33:
	/* 0x2b33: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2b38:
	/* 0x2b38: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b3c:
	/* 0x2b3c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b41:
	/* 0x2b41: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b43:
	/* 0x2b43: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b45:
	/* 0x2b45: js     5c67 <generic_sleepable_preload+0x5c67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23655ULL;
	}
x86_l_2b4b:
	/* 0x2b4b: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b50:
	/* 0x2b50: cmp    WORD PTR [r12+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_2b5a:
	/* 0x2b5a: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_2b5d:
	/* 0x2b5d: je     2cec <generic_sleepable_preload+0x2cec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cec;
	}
x86_l_2b63:
	/* 0x2b63: mov    ecx,DWORD PTR [r12+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_2b6b:
	/* 0x2b6b: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2b6f:
	/* 0x2b6f: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b73:
	/* 0x2b73: cmp    WORD PTR [r12+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_2b7d:
	/* 0x2b7d: je     2b9f <generic_sleepable_preload+0x2b9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b9f;
	}
x86_l_2b7f:
	/* 0x2b7f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2b82:
	/* 0x2b82: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2b87:
	/* 0x2b87: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2b8c:
	/* 0x2b8c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b90:
	/* 0x2b90: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b95:
	/* 0x2b95: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b97:
	/* 0x2b97: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b99:
	/* 0x2b99: js     5d77 <generic_sleepable_preload+0x5d77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23927ULL;
	}
x86_l_2b9f:
	/* 0x2b9f: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ba4:
	/* 0x2ba4: cmp    WORD PTR [r12+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_2bae:
	/* 0x2bae: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_2bb1:
	/* 0x2bb1: je     2cec <generic_sleepable_preload+0x2cec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cec;
	}
x86_l_2bb7:
	/* 0x2bb7: mov    ecx,DWORD PTR [r12+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_2bbf:
	/* 0x2bbf: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2bc3:
	/* 0x2bc3: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bc7:
	/* 0x2bc7: cmp    WORD PTR [r12+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_2bd1:
	/* 0x2bd1: je     2cec <generic_sleepable_preload+0x2cec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cec;
	}
x86_l_2bd7:
	/* 0x2bd7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2bda:
	/* 0x2bda: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2bdf:
	/* 0x2bdf: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2be4:
	/* 0x2be4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2be8:
	/* 0x2be8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2bed:
	/* 0x2bed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bef:
	/* 0x2bef: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2bf1:
	/* 0x2bf1: jns    2cec <generic_sleepable_preload+0x2cec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_2cec;
	}
x86_l_2bf7:
	/* 0x2bf7: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_2bfc:
	/* 0x2bfc: jmp    2ce9 <generic_sleepable_preload+0x2ce9> */
	goto x86_l_2ce9;
x86_l_2c01:
	/* 0x2c01: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_2c06:
	/* 0x2c06: jmp    2ce9 <generic_sleepable_preload+0x2ce9> */
	goto x86_l_2ce9;
x86_l_2c0b:
	/* 0x2c0b: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_2c10:
	/* 0x2c10: jmp    2ce9 <generic_sleepable_preload+0x2ce9> */
	goto x86_l_2ce9;
x86_l_2c15:
	/* 0x2c15: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_2c1a:
	/* 0x2c1a: jmp    2c5e <generic_sleepable_preload+0x2c5e> */
	goto x86_l_2c5e;
x86_l_2c1c:
	/* 0x2c1c: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_2c21:
	/* 0x2c21: jmp    2ce9 <generic_sleepable_preload+0x2ce9> */
	goto x86_l_2ce9;
x86_l_2c26:
	/* 0x2c26: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_2c2b:
	/* 0x2c2b: jmp    2c5e <generic_sleepable_preload+0x2c5e> */
	goto x86_l_2c5e;
x86_l_2c2d:
	/* 0x2c2d: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_2c32:
	/* 0x2c32: jmp    2ce9 <generic_sleepable_preload+0x2ce9> */
	goto x86_l_2ce9;
x86_l_2c37:
	/* 0x2c37: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_2c3c:
	/* 0x2c3c: jmp    2c5e <generic_sleepable_preload+0x2c5e> */
	goto x86_l_2c5e;
x86_l_2c3e:
	/* 0x2c3e: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_2c43:
	/* 0x2c43: jmp    2ce9 <generic_sleepable_preload+0x2ce9> */
	goto x86_l_2ce9;
x86_l_2c48:
	/* 0x2c48: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_2c4d:
	/* 0x2c4d: jmp    2c5e <generic_sleepable_preload+0x2c5e> */
	goto x86_l_2c5e;
x86_l_2c4f:
	/* 0x2c4f: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_2c54:
	/* 0x2c54: jmp    2ce9 <generic_sleepable_preload+0x2ce9> */
	goto x86_l_2ce9;
x86_l_2c59:
	/* 0x2c59: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_2c5e:
	/* 0x2c5e: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c61:
	/* 0x2c61: mov    ebp,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c66:
	/* 0x2c66: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2c69:
	/* 0x2c69: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2c6e:
	/* 0x2c6e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c73:
	/* 0x2c73: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c78:
	/* 0x2c78: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_2c7b:
	/* 0x2c7b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c7d:
	/* 0x2c7d: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_2c80:
	/* 0x2c80: jne    2d91 <generic_sleepable_preload+0x2d91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2d91;
	}
x86_l_2c86:
	/* 0x2c86: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_2c89:
	/* 0x2c89: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c8d:
	/* 0x2c8d: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2c92:
	/* 0x2c92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c94:
	/* 0x2c94: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c99:
	/* 0x2c99: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_2ca1:
	/* 0x2ca1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2ca8:
	/* 0x2ca8: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2cad:
	/* 0x2cad: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2cb2:
	/* 0x2cb2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cb4:
	/* 0x2cb4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2cb7:
	/* 0x2cb7: je     2d8e <generic_sleepable_preload+0x2d8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d8e;
	}
x86_l_2cbd:
	/* 0x2cbd: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2cc0:
	/* 0x2cc0: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_2cc7:
	/* 0x2cc7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2cc9:
	/* 0x2cc9: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2cce:
	/* 0x2cce: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2cd3:
	/* 0x2cd3: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_2cd6:
	/* 0x2cd6: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2cd9:
	/* 0x2cd9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2cdb:
	/* 0x2cdb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cdd:
	/* 0x2cdd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ce2:
	/* 0x2ce2: jmp    2d4d <generic_sleepable_preload+0x2d4d> */
	goto x86_l_2d4d;
x86_l_2ce4:
	/* 0x2ce4: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_2ce9:
	/* 0x2ce9: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2cec:
	/* 0x2cec: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_2cef:
	/* 0x2cef: jne    2d91 <generic_sleepable_preload+0x2d91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2d91;
	}
x86_l_2cf5:
	/* 0x2cf5: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_2cf8:
	/* 0x2cf8: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cfc:
	/* 0x2cfc: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2d01:
	/* 0x2d01: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d03:
	/* 0x2d03: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d08:
	/* 0x2d08: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_2d10:
	/* 0x2d10: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2d17:
	/* 0x2d17: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2d1c:
	/* 0x2d1c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d21:
	/* 0x2d21: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d23:
	/* 0x2d23: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d26:
	/* 0x2d26: je     2d8e <generic_sleepable_preload+0x2d8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d8e;
	}
x86_l_2d28:
	/* 0x2d28: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2d2b:
	/* 0x2d2b: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_2d32:
	/* 0x2d32: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d34:
	/* 0x2d34: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d39:
	/* 0x2d39: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2d3e:
	/* 0x2d3e: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_2d41:
	/* 0x2d41: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2d44:
	/* 0x2d44: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d46:
	/* 0x2d46: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d48:
	/* 0x2d48: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d4d:
	/* 0x2d4d: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_2d50:
	/* 0x2d50: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2d53:
	/* 0x2d53: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d58:
	/* 0x2d58: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d5a:
	/* 0x2d5a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d5d:
	/* 0x2d5d: je     2d8e <generic_sleepable_preload+0x2d8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d8e;
	}
x86_l_2d5f:
	/* 0x2d5f: test   r13b,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_8);
x86_l_2d62:
	/* 0x2d62: je     2d8c <generic_sleepable_preload+0x2d8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d8c;
	}
x86_l_2d64:
	/* 0x2d64: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2d67:
	/* 0x2d67: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2d6b:
	/* 0x2d6b: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2d70:
	/* 0x2d70: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2d73:
	/* 0x2d73: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d75:
	/* 0x2d75: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_2d78:
	/* 0x2d78: call   2d7d <generic_sleepable_preload+0x2d7d> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_2d7d:
	/* 0x2d7d: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_2d7f:
	/* 0x2d7f: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_2d82:
	/* 0x2d82: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2d84:
	/* 0x2d84: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_2d89:
	/* 0x2d89: cmovs  ebx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_2d8c:
	/* 0x2d8c: mov    DWORD PTR [rax],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d8e:
	/* 0x2d8e: mov    r14,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_64);
x86_l_2d91:
	/* 0x2d91: mov    eax,DWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d96:
	/* 0x2d96: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_2d9b:
	/* 0x2d9b: je     3cfc <generic_sleepable_preload+0x3cfc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15612ULL;
	}
x86_l_2da1:
	/* 0x2da1: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_2da3:
	/* 0x2da3: js     2dd8 <generic_sleepable_preload+0x2dd8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2dd8;
	}
x86_l_2da5:
	/* 0x2da5: mov    eax,DWORD PTR [r12+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2daa:
	/* 0x2daa: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2dad:
	/* 0x2dad: jle    2e5b <generic_sleepable_preload+0x2e5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2e5b;
	}
x86_l_2db3:
	/* 0x2db3: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2db6:
	/* 0x2db6: je     2ec5 <generic_sleepable_preload+0x2ec5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ec5;
	}
x86_l_2dbc:
	/* 0x2dbc: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2dbf:
	/* 0x2dbf: je     2ecc <generic_sleepable_preload+0x2ecc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ecc;
	}
x86_l_2dc5:
	/* 0x2dc5: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2dc8:
	/* 0x2dc8: jne    2edf <generic_sleepable_preload+0x2edf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2edf;
	}
x86_l_2dce:
	/* 0x2dce: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2dd3:
	/* 0x2dd3: jmp    2ed8 <generic_sleepable_preload+0x2ed8> */
	goto x86_l_2ed8;
x86_l_2dd8:
	/* 0x2dd8: movzx  eax,BYTE PTR [r12+0x2ca] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 714ULL);
x86_l_2de1:
	/* 0x2de1: movzx  ecx,WORD PTR [r12+0x2c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 712ULL);
x86_l_2dea:
	/* 0x2dea: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_2df0:
	/* 0x2df0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2df2:
	/* 0x2df2: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_2df5:
	/* 0x2df5: jle    2e34 <generic_sleepable_preload+0x2e34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2e34;
	}
x86_l_2df7:
	/* 0x2df7: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_2dfa:
	/* 0x2dfa: jle    2e6b <generic_sleepable_preload+0x2e6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2e6b;
	}
x86_l_2dfc:
	/* 0x2dfc: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_2dff:
	/* 0x2dff: jle    352e <generic_sleepable_preload+0x352e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 13614ULL;
	}
x86_l_2e05:
	/* 0x2e05: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2e0a:
	/* 0x2e0a: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_2e0d:
	/* 0x2e0d: je     3553 <generic_sleepable_preload+0x3553> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13651ULL;
	}
x86_l_2e13:
	/* 0x2e13: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2e18:
	/* 0x2e18: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_2e1b:
	/* 0x2e1b: je     3553 <generic_sleepable_preload+0x3553> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13651ULL;
	}
x86_l_2e21:
	/* 0x2e21: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2e26:
	/* 0x2e26: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_2e29:
	/* 0x2e29: je     3553 <generic_sleepable_preload+0x3553> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13651ULL;
	}
x86_l_2e2f:
	/* 0x2e2f: jmp    3566 <generic_sleepable_preload+0x3566> */
	return 13670ULL;
x86_l_2e34:
	/* 0x2e34: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_2e37:
	/* 0x2e37: jg     2e98 <generic_sleepable_preload+0x2e98> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2e98;
	}
x86_l_2e39:
	/* 0x2e39: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_2e3c:
	/* 0x2e3c: jg     34ff <generic_sleepable_preload+0x34ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 13567ULL;
	}
x86_l_2e42:
	/* 0x2e42: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_2e44:
	/* 0x2e44: je     354e <generic_sleepable_preload+0x354e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13646ULL;
	}
x86_l_2e4a:
	/* 0x2e4a: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_2e4d:
	/* 0x2e4d: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_2e50:
	/* 0x2e50: je     3553 <generic_sleepable_preload+0x3553> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13651ULL;
	}
x86_l_2e56:
	/* 0x2e56: jmp    3566 <generic_sleepable_preload+0x3566> */
	return 13670ULL;
x86_l_2e5b:
	/* 0x2e5b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2e5d:
	/* 0x2e5d: je     2ed3 <generic_sleepable_preload+0x2ed3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ed3;
	}
x86_l_2e5f:
	/* 0x2e5f: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e62:
	/* 0x2e62: jne    2edf <generic_sleepable_preload+0x2edf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2edf;
	}
x86_l_2e64:
	/* 0x2e64: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2e69:
	/* 0x2e69: jmp    2ed8 <generic_sleepable_preload+0x2ed8> */
	goto x86_l_2ed8;
x86_l_2e6b:
	/* 0x2e6b: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_2e6e:
	/* 0x2e6e: jg     34e6 <generic_sleepable_preload+0x34e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 13542ULL;
	}
x86_l_2e74:
	/* 0x2e74: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2e7c:
	/* 0x2e7c: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2e7f:
	/* 0x2e7f: je     3553 <generic_sleepable_preload+0x3553> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13651ULL;
	}
x86_l_2e85:
	/* 0x2e85: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2e8a:
	/* 0x2e8a: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_2e8d:
	/* 0x2e8d: je     3553 <generic_sleepable_preload+0x3553> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13651ULL;
	}
x86_l_2e93:
	/* 0x2e93: jmp    3566 <generic_sleepable_preload+0x3566> */
	return 13670ULL;
x86_l_2e98:
	/* 0x2e98: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_2e9b:
	/* 0x2e9b: jg     3515 <generic_sleepable_preload+0x3515> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 13589ULL;
	}
x86_l_2ea1:
	/* 0x2ea1: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2ea9:
	/* 0x2ea9: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_2eac:
	/* 0x2eac: je     3553 <generic_sleepable_preload+0x3553> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13651ULL;
	}
x86_l_2eb2:
	/* 0x2eb2: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2eb7:
	/* 0x2eb7: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_2eba:
	/* 0x2eba: je     3553 <generic_sleepable_preload+0x3553> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13651ULL;
	}
x86_l_2ec0:
	/* 0x2ec0: jmp    3566 <generic_sleepable_preload+0x3566> */
	return 13670ULL;
x86_l_2ec5:
	/* 0x2ec5: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2eca:
	/* 0x2eca: jmp    2ed8 <generic_sleepable_preload+0x2ed8> */
	goto x86_l_2ed8;
x86_l_2ecc:
	/* 0x2ecc: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ed1:
	/* 0x2ed1: jmp    2ed8 <generic_sleepable_preload+0x2ed8> */
	goto x86_l_2ed8;
x86_l_2ed3:
	/* 0x2ed3: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2ed8:
	/* 0x2ed8: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2edb:
	/* 0x2edb: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2edf:
	/* 0x2edf: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ee1:
	/* 0x2ee1: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_2ee4:
	/* 0x2ee4: cmp    WORD PTR [r12+0x116],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1194000908288ULL);
x86_l_2eee:
	/* 0x2eee: je     3bcc <generic_sleepable_preload+0x3bcc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15308ULL;
	}
x86_l_2ef4:
	/* 0x2ef4: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_2efb:
	/* 0x2efb: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2efe:
	/* 0x2efe: mov    eax,DWORD PTR [r12+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_2f06:
	/* 0x2f06: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2f09:
	/* 0x2f09: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f0d:
	/* 0x2f0d: movzx  eax,WORD PTR [r12+0x114] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 276ULL);
x86_l_2f16:
	/* 0x2f16: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_2f18:
	/* 0x2f18: je     31ea <generic_sleepable_preload+0x31ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12778ULL;
	}
x86_l_2f1e:
	/* 0x2f1e: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_2f21:
	/* 0x2f21: je     2f43 <generic_sleepable_preload+0x2f43> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f43;
	}
x86_l_2f23:
	/* 0x2f23: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2f26:
	/* 0x2f26: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2f2b:
	/* 0x2f2b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2f30:
	/* 0x2f30: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f34:
	/* 0x2f34: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f39:
	/* 0x2f39: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f3b:
	/* 0x2f3b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2f3d:
	/* 0x2f3d: js     34dc <generic_sleepable_preload+0x34dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13532ULL;
	}
x86_l_2f43:
	/* 0x2f43: cmp    WORD PTR [r12+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_2f4d:
	/* 0x2f4d: je     3bcc <generic_sleepable_preload+0x3bcc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15308ULL;
	}
x86_l_2f53:
	/* 0x2f53: mov    ecx,DWORD PTR [r12+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_2f5b:
	/* 0x2f5b: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2f5f:
	/* 0x2f5f: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f63:
	/* 0x2f63: cmp    WORD PTR [r12+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_2f6d:
	/* 0x2f6d: je     2f8f <generic_sleepable_preload+0x2f8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12175ULL;
	}
x86_l_2f6f:
	/* 0x2f6f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2f72:
	/* 0x2f72: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
	return 12151ULL;
}

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12151ULL: goto x86_l_2f77;
	case 12156ULL: goto x86_l_2f7c;
	case 12160ULL: goto x86_l_2f80;
	case 12165ULL: goto x86_l_2f85;
	case 12167ULL: goto x86_l_2f87;
	case 12169ULL: goto x86_l_2f89;
	case 12175ULL: goto x86_l_2f8f;
	case 12185ULL: goto x86_l_2f99;
	case 12191ULL: goto x86_l_2f9f;
	case 12199ULL: goto x86_l_2fa7;
	case 12203ULL: goto x86_l_2fab;
	case 12207ULL: goto x86_l_2faf;
	case 12217ULL: goto x86_l_2fb9;
	case 12219ULL: goto x86_l_2fbb;
	case 12222ULL: goto x86_l_2fbe;
	case 12227ULL: goto x86_l_2fc3;
	case 12232ULL: goto x86_l_2fc8;
	case 12236ULL: goto x86_l_2fcc;
	case 12241ULL: goto x86_l_2fd1;
	case 12243ULL: goto x86_l_2fd3;
	case 12245ULL: goto x86_l_2fd5;
	case 12251ULL: goto x86_l_2fdb;
	case 12261ULL: goto x86_l_2fe5;
	case 12267ULL: goto x86_l_2feb;
	case 12275ULL: goto x86_l_2ff3;
	case 12279ULL: goto x86_l_2ff7;
	case 12283ULL: goto x86_l_2ffb;
	case 12293ULL: goto x86_l_3005;
	case 12295ULL: goto x86_l_3007;
	case 12298ULL: goto x86_l_300a;
	case 12303ULL: goto x86_l_300f;
	case 12308ULL: goto x86_l_3014;
	case 12312ULL: goto x86_l_3018;
	case 12317ULL: goto x86_l_301d;
	case 12319ULL: goto x86_l_301f;
	case 12321ULL: goto x86_l_3021;
	case 12327ULL: goto x86_l_3027;
	case 12337ULL: goto x86_l_3031;
	case 12343ULL: goto x86_l_3037;
	case 12351ULL: goto x86_l_303f;
	case 12355ULL: goto x86_l_3043;
	case 12359ULL: goto x86_l_3047;
	case 12369ULL: goto x86_l_3051;
	case 12371ULL: goto x86_l_3053;
	case 12374ULL: goto x86_l_3056;
	case 12379ULL: goto x86_l_305b;
	case 12384ULL: goto x86_l_3060;
	case 12388ULL: goto x86_l_3064;
	case 12393ULL: goto x86_l_3069;
	case 12395ULL: goto x86_l_306b;
	case 12397ULL: goto x86_l_306d;
	case 12403ULL: goto x86_l_3073;
	case 12413ULL: goto x86_l_307d;
	case 12419ULL: goto x86_l_3083;
	case 12427ULL: goto x86_l_308b;
	case 12431ULL: goto x86_l_308f;
	case 12435ULL: goto x86_l_3093;
	case 12445ULL: goto x86_l_309d;
	case 12447ULL: goto x86_l_309f;
	case 12450ULL: goto x86_l_30a2;
	case 12455ULL: goto x86_l_30a7;
	case 12460ULL: goto x86_l_30ac;
	case 12464ULL: goto x86_l_30b0;
	case 12469ULL: goto x86_l_30b5;
	case 12471ULL: goto x86_l_30b7;
	case 12473ULL: goto x86_l_30b9;
	case 12479ULL: goto x86_l_30bf;
	case 12489ULL: goto x86_l_30c9;
	case 12495ULL: goto x86_l_30cf;
	case 12503ULL: goto x86_l_30d7;
	case 12507ULL: goto x86_l_30db;
	case 12511ULL: goto x86_l_30df;
	case 12521ULL: goto x86_l_30e9;
	case 12523ULL: goto x86_l_30eb;
	case 12526ULL: goto x86_l_30ee;
	case 12531ULL: goto x86_l_30f3;
	case 12536ULL: goto x86_l_30f8;
	case 12540ULL: goto x86_l_30fc;
	case 12545ULL: goto x86_l_3101;
	case 12547ULL: goto x86_l_3103;
	case 12549ULL: goto x86_l_3105;
	case 12555ULL: goto x86_l_310b;
	case 12565ULL: goto x86_l_3115;
	case 12571ULL: goto x86_l_311b;
	case 12579ULL: goto x86_l_3123;
	case 12583ULL: goto x86_l_3127;
	case 12587ULL: goto x86_l_312b;
	case 12597ULL: goto x86_l_3135;
	case 12599ULL: goto x86_l_3137;
	case 12602ULL: goto x86_l_313a;
	case 12607ULL: goto x86_l_313f;
	case 12612ULL: goto x86_l_3144;
	case 12616ULL: goto x86_l_3148;
	case 12621ULL: goto x86_l_314d;
	case 12623ULL: goto x86_l_314f;
	case 12625ULL: goto x86_l_3151;
	case 12631ULL: goto x86_l_3157;
	case 12641ULL: goto x86_l_3161;
	case 12647ULL: goto x86_l_3167;
	case 12655ULL: goto x86_l_316f;
	case 12659ULL: goto x86_l_3173;
	case 12663ULL: goto x86_l_3177;
	case 12673ULL: goto x86_l_3181;
	case 12675ULL: goto x86_l_3183;
	case 12678ULL: goto x86_l_3186;
	case 12683ULL: goto x86_l_318b;
	case 12688ULL: goto x86_l_3190;
	case 12692ULL: goto x86_l_3194;
	case 12697ULL: goto x86_l_3199;
	case 12699ULL: goto x86_l_319b;
	case 12701ULL: goto x86_l_319d;
	case 12707ULL: goto x86_l_31a3;
	case 12712ULL: goto x86_l_31a8;
	case 12722ULL: goto x86_l_31b2;
	case 12728ULL: goto x86_l_31b8;
	case 12736ULL: goto x86_l_31c0;
	case 12740ULL: goto x86_l_31c4;
	case 12744ULL: goto x86_l_31c8;
	case 12754ULL: goto x86_l_31d2;
	case 12760ULL: goto x86_l_31d8;
	case 12763ULL: goto x86_l_31db;
	case 12768ULL: goto x86_l_31e0;
	case 12773ULL: goto x86_l_31e5;
	case 12778ULL: goto x86_l_31ea;
	case 12781ULL: goto x86_l_31ed;
	case 12783ULL: goto x86_l_31ef;
	case 12786ULL: goto x86_l_31f2;
	case 12791ULL: goto x86_l_31f7;
	case 12796ULL: goto x86_l_31fc;
	case 12800ULL: goto x86_l_3200;
	case 12805ULL: goto x86_l_3205;
	case 12807ULL: goto x86_l_3207;
	case 12809ULL: goto x86_l_3209;
	case 12815ULL: goto x86_l_320f;
	case 12825ULL: goto x86_l_3219;
	case 12831ULL: goto x86_l_321f;
	case 12839ULL: goto x86_l_3227;
	case 12843ULL: goto x86_l_322b;
	case 12847ULL: goto x86_l_322f;
	case 12857ULL: goto x86_l_3239;
	case 12859ULL: goto x86_l_323b;
	case 12862ULL: goto x86_l_323e;
	case 12867ULL: goto x86_l_3243;
	case 12872ULL: goto x86_l_3248;
	case 12876ULL: goto x86_l_324c;
	case 12881ULL: goto x86_l_3251;
	case 12883ULL: goto x86_l_3253;
	case 12885ULL: goto x86_l_3255;
	case 12891ULL: goto x86_l_325b;
	case 12901ULL: goto x86_l_3265;
	case 12907ULL: goto x86_l_326b;
	case 12915ULL: goto x86_l_3273;
	case 12919ULL: goto x86_l_3277;
	case 12923ULL: goto x86_l_327b;
	case 12933ULL: goto x86_l_3285;
	case 12935ULL: goto x86_l_3287;
	case 12938ULL: goto x86_l_328a;
	case 12943ULL: goto x86_l_328f;
	case 12948ULL: goto x86_l_3294;
	case 12952ULL: goto x86_l_3298;
	case 12957ULL: goto x86_l_329d;
	case 12959ULL: goto x86_l_329f;
	case 12961ULL: goto x86_l_32a1;
	case 12967ULL: goto x86_l_32a7;
	case 12977ULL: goto x86_l_32b1;
	case 12983ULL: goto x86_l_32b7;
	case 12991ULL: goto x86_l_32bf;
	case 12995ULL: goto x86_l_32c3;
	case 12999ULL: goto x86_l_32c7;
	case 13009ULL: goto x86_l_32d1;
	case 13011ULL: goto x86_l_32d3;
	case 13014ULL: goto x86_l_32d6;
	case 13019ULL: goto x86_l_32db;
	case 13024ULL: goto x86_l_32e0;
	case 13028ULL: goto x86_l_32e4;
	case 13033ULL: goto x86_l_32e9;
	case 13035ULL: goto x86_l_32eb;
	case 13037ULL: goto x86_l_32ed;
	case 13043ULL: goto x86_l_32f3;
	case 13053ULL: goto x86_l_32fd;
	case 13059ULL: goto x86_l_3303;
	case 13067ULL: goto x86_l_330b;
	case 13071ULL: goto x86_l_330f;
	case 13075ULL: goto x86_l_3313;
	case 13085ULL: goto x86_l_331d;
	case 13087ULL: goto x86_l_331f;
	case 13090ULL: goto x86_l_3322;
	case 13095ULL: goto x86_l_3327;
	case 13100ULL: goto x86_l_332c;
	case 13104ULL: goto x86_l_3330;
	case 13109ULL: goto x86_l_3335;
	case 13111ULL: goto x86_l_3337;
	case 13113ULL: goto x86_l_3339;
	case 13119ULL: goto x86_l_333f;
	case 13129ULL: goto x86_l_3349;
	case 13135ULL: goto x86_l_334f;
	case 13143ULL: goto x86_l_3357;
	case 13147ULL: goto x86_l_335b;
	case 13151ULL: goto x86_l_335f;
	case 13161ULL: goto x86_l_3369;
	case 13163ULL: goto x86_l_336b;
	case 13166ULL: goto x86_l_336e;
	case 13171ULL: goto x86_l_3373;
	case 13176ULL: goto x86_l_3378;
	case 13180ULL: goto x86_l_337c;
	case 13185ULL: goto x86_l_3381;
	case 13187ULL: goto x86_l_3383;
	case 13189ULL: goto x86_l_3385;
	case 13195ULL: goto x86_l_338b;
	case 13205ULL: goto x86_l_3395;
	case 13211ULL: goto x86_l_339b;
	case 13219ULL: goto x86_l_33a3;
	case 13223ULL: goto x86_l_33a7;
	case 13227ULL: goto x86_l_33ab;
	case 13237ULL: goto x86_l_33b5;
	case 13239ULL: goto x86_l_33b7;
	case 13242ULL: goto x86_l_33ba;
	case 13247ULL: goto x86_l_33bf;
	case 13252ULL: goto x86_l_33c4;
	case 13256ULL: goto x86_l_33c8;
	case 13261ULL: goto x86_l_33cd;
	case 13263ULL: goto x86_l_33cf;
	case 13265ULL: goto x86_l_33d1;
	case 13271ULL: goto x86_l_33d7;
	case 13281ULL: goto x86_l_33e1;
	case 13287ULL: goto x86_l_33e7;
	case 13290ULL: goto x86_l_33ea;
	case 13298ULL: goto x86_l_33f2;
	case 13302ULL: goto x86_l_33f6;
	case 13306ULL: goto x86_l_33fa;
	case 13316ULL: goto x86_l_3404;
	case 13318ULL: goto x86_l_3406;
	case 13321ULL: goto x86_l_3409;
	case 13326ULL: goto x86_l_340e;
	case 13331ULL: goto x86_l_3413;
	case 13335ULL: goto x86_l_3417;
	case 13340ULL: goto x86_l_341c;
	case 13342ULL: goto x86_l_341e;
	case 13344ULL: goto x86_l_3420;
	case 13350ULL: goto x86_l_3426;
	case 13355ULL: goto x86_l_342b;
	case 13365ULL: goto x86_l_3435;
	case 13368ULL: goto x86_l_3438;
	case 13374ULL: goto x86_l_343e;
	case 13382ULL: goto x86_l_3446;
	case 13386ULL: goto x86_l_344a;
	case 13390ULL: goto x86_l_344e;
	case 13400ULL: goto x86_l_3458;
	case 13402ULL: goto x86_l_345a;
	case 13405ULL: goto x86_l_345d;
	case 13410ULL: goto x86_l_3462;
	case 13415ULL: goto x86_l_3467;
	case 13419ULL: goto x86_l_346b;
	case 13424ULL: goto x86_l_3470;
	case 13426ULL: goto x86_l_3472;
	case 13428ULL: goto x86_l_3474;
	case 13434ULL: goto x86_l_347a;
	case 13439ULL: goto x86_l_347f;
	case 13449ULL: goto x86_l_3489;
	case 13452ULL: goto x86_l_348c;
	case 13458ULL: goto x86_l_3492;
	case 13466ULL: goto x86_l_349a;
	case 13470ULL: goto x86_l_349e;
	case 13474ULL: goto x86_l_34a2;
	case 13484ULL: goto x86_l_34ac;
	case 13490ULL: goto x86_l_34b2;
	case 13493ULL: goto x86_l_34b5;
	case 13498ULL: goto x86_l_34ba;
	case 13503ULL: goto x86_l_34bf;
	case 13507ULL: goto x86_l_34c3;
	case 13512ULL: goto x86_l_34c8;
	case 13514ULL: goto x86_l_34ca;
	case 13516ULL: goto x86_l_34cc;
	case 13522ULL: goto x86_l_34d2;
	case 13527ULL: goto x86_l_34d7;
	case 13532ULL: goto x86_l_34dc;
	case 13537ULL: goto x86_l_34e1;
	case 13542ULL: goto x86_l_34e6;
	case 13550ULL: goto x86_l_34ee;
	case 13553ULL: goto x86_l_34f1;
	case 13555ULL: goto x86_l_34f3;
	case 13560ULL: goto x86_l_34f8;
	case 13563ULL: goto x86_l_34fb;
	case 13565ULL: goto x86_l_34fd;
	case 13567ULL: goto x86_l_34ff;
	case 13572ULL: goto x86_l_3504;
	case 13575ULL: goto x86_l_3507;
	case 13577ULL: goto x86_l_3509;
	case 13582ULL: goto x86_l_350e;
	case 13585ULL: goto x86_l_3511;
	case 13587ULL: goto x86_l_3513;
	case 13589ULL: goto x86_l_3515;
	case 13597ULL: goto x86_l_351d;
	case 13600ULL: goto x86_l_3520;
	case 13602ULL: goto x86_l_3522;
	case 13607ULL: goto x86_l_3527;
	case 13610ULL: goto x86_l_352a;
	case 13612ULL: goto x86_l_352c;
	case 13614ULL: goto x86_l_352e;
	case 13619ULL: goto x86_l_3533;
	case 13622ULL: goto x86_l_3536;
	case 13624ULL: goto x86_l_3538;
	case 13629ULL: goto x86_l_353d;
	case 13632ULL: goto x86_l_3540;
	case 13634ULL: goto x86_l_3542;
	case 13636ULL: goto x86_l_3544;
	case 13641ULL: goto x86_l_3549;
	case 13646ULL: goto x86_l_354e;
	case 13651ULL: goto x86_l_3553;
	case 13654ULL: goto x86_l_3556;
	case 13656ULL: goto x86_l_3558;
	case 13658ULL: goto x86_l_355a;
	case 13663ULL: goto x86_l_355f;
	case 13665ULL: goto x86_l_3561;
	case 13670ULL: goto x86_l_3566;
	case 13674ULL: goto x86_l_356a;
	case 13679ULL: goto x86_l_356f;
	case 13681ULL: goto x86_l_3571;
	case 13684ULL: goto x86_l_3574;
	case 13694ULL: goto x86_l_357e;
	case 13700ULL: goto x86_l_3584;
	case 13707ULL: goto x86_l_358b;
	case 13710ULL: goto x86_l_358e;
	case 13718ULL: goto x86_l_3596;
	case 13721ULL: goto x86_l_3599;
	case 13725ULL: goto x86_l_359d;
	case 13734ULL: goto x86_l_35a6;
	case 13736ULL: goto x86_l_35a8;
	case 13742ULL: goto x86_l_35ae;
	case 13745ULL: goto x86_l_35b1;
	case 13747ULL: goto x86_l_35b3;
	case 13750ULL: goto x86_l_35b6;
	case 13755ULL: goto x86_l_35bb;
	case 13760ULL: goto x86_l_35c0;
	case 13764ULL: goto x86_l_35c4;
	case 13769ULL: goto x86_l_35c9;
	case 13771ULL: goto x86_l_35cb;
	case 13773ULL: goto x86_l_35cd;
	case 13779ULL: goto x86_l_35d3;
	case 13789ULL: goto x86_l_35dd;
	case 13795ULL: goto x86_l_35e3;
	case 13803ULL: goto x86_l_35eb;
	case 13807ULL: goto x86_l_35ef;
	case 13811ULL: goto x86_l_35f3;
	case 13821ULL: goto x86_l_35fd;
	case 13823ULL: goto x86_l_35ff;
	case 13826ULL: goto x86_l_3602;
	case 13831ULL: goto x86_l_3607;
	case 13836ULL: goto x86_l_360c;
	case 13840ULL: goto x86_l_3610;
	case 13845ULL: goto x86_l_3615;
	case 13847ULL: goto x86_l_3617;
	case 13849ULL: goto x86_l_3619;
	case 13855ULL: goto x86_l_361f;
	case 13865ULL: goto x86_l_3629;
	case 13871ULL: goto x86_l_362f;
	case 13879ULL: goto x86_l_3637;
	case 13883ULL: goto x86_l_363b;
	case 13887ULL: goto x86_l_363f;
	case 13897ULL: goto x86_l_3649;
	case 13899ULL: goto x86_l_364b;
	case 13902ULL: goto x86_l_364e;
	case 13907ULL: goto x86_l_3653;
	case 13912ULL: goto x86_l_3658;
	case 13916ULL: goto x86_l_365c;
	case 13921ULL: goto x86_l_3661;
	case 13923ULL: goto x86_l_3663;
	case 13925ULL: goto x86_l_3665;
	case 13931ULL: goto x86_l_366b;
	case 13941ULL: goto x86_l_3675;
	case 13947ULL: goto x86_l_367b;
	case 13955ULL: goto x86_l_3683;
	case 13959ULL: goto x86_l_3687;
	case 13963ULL: goto x86_l_368b;
	case 13973ULL: goto x86_l_3695;
	case 13975ULL: goto x86_l_3697;
	case 13978ULL: goto x86_l_369a;
	case 13983ULL: goto x86_l_369f;
	case 13988ULL: goto x86_l_36a4;
	case 13992ULL: goto x86_l_36a8;
	case 13997ULL: goto x86_l_36ad;
	case 13999ULL: goto x86_l_36af;
	case 14001ULL: goto x86_l_36b1;
	case 14007ULL: goto x86_l_36b7;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2f77:
	/* 0x2f77: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2f7c:
	/* 0x2f7c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f80:
	/* 0x2f80: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f85:
	/* 0x2f85: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f87:
	/* 0x2f87: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2f89:
	/* 0x2f89: js     3544 <generic_sleepable_preload+0x3544> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3544;
	}
x86_l_2f8f:
	/* 0x2f8f: cmp    WORD PTR [r12+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_2f99:
	/* 0x2f99: je     3bcc <generic_sleepable_preload+0x3bcc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15308ULL;
	}
x86_l_2f9f:
	/* 0x2f9f: mov    ecx,DWORD PTR [r12+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_2fa7:
	/* 0x2fa7: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2fab:
	/* 0x2fab: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2faf:
	/* 0x2faf: cmp    WORD PTR [r12+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_2fb9:
	/* 0x2fb9: je     2fdb <generic_sleepable_preload+0x2fdb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fdb;
	}
x86_l_2fbb:
	/* 0x2fbb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2fbe:
	/* 0x2fbe: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2fc3:
	/* 0x2fc3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2fc8:
	/* 0x2fc8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fcc:
	/* 0x2fcc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fd1:
	/* 0x2fd1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fd3:
	/* 0x2fd3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2fd5:
	/* 0x2fd5: js     3b80 <generic_sleepable_preload+0x3b80> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15232ULL;
	}
x86_l_2fdb:
	/* 0x2fdb: cmp    WORD PTR [r12+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_2fe5:
	/* 0x2fe5: je     3bcc <generic_sleepable_preload+0x3bcc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15308ULL;
	}
x86_l_2feb:
	/* 0x2feb: mov    ecx,DWORD PTR [r12+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_2ff3:
	/* 0x2ff3: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2ff7:
	/* 0x2ff7: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ffb:
	/* 0x2ffb: cmp    WORD PTR [r12+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_3005:
	/* 0x3005: je     3027 <generic_sleepable_preload+0x3027> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3027;
	}
x86_l_3007:
	/* 0x3007: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_300a:
	/* 0x300a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_300f:
	/* 0x300f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3014:
	/* 0x3014: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3018:
	/* 0x3018: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_301d:
	/* 0x301d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_301f:
	/* 0x301f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3021:
	/* 0x3021: js     3b91 <generic_sleepable_preload+0x3b91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15249ULL;
	}
x86_l_3027:
	/* 0x3027: cmp    WORD PTR [r12+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_3031:
	/* 0x3031: je     3bcc <generic_sleepable_preload+0x3bcc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15308ULL;
	}
x86_l_3037:
	/* 0x3037: mov    ecx,DWORD PTR [r12+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_303f:
	/* 0x303f: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3043:
	/* 0x3043: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3047:
	/* 0x3047: cmp    WORD PTR [r12+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_3051:
	/* 0x3051: je     3073 <generic_sleepable_preload+0x3073> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3073;
	}
x86_l_3053:
	/* 0x3053: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3056:
	/* 0x3056: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_305b:
	/* 0x305b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3060:
	/* 0x3060: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3064:
	/* 0x3064: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3069:
	/* 0x3069: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_306b:
	/* 0x306b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_306d:
	/* 0x306d: js     3ba2 <generic_sleepable_preload+0x3ba2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15266ULL;
	}
x86_l_3073:
	/* 0x3073: cmp    WORD PTR [r12+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_307d:
	/* 0x307d: je     3bcc <generic_sleepable_preload+0x3bcc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15308ULL;
	}
x86_l_3083:
	/* 0x3083: mov    ecx,DWORD PTR [r12+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_308b:
	/* 0x308b: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_308f:
	/* 0x308f: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3093:
	/* 0x3093: cmp    WORD PTR [r12+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_309d:
	/* 0x309d: je     30bf <generic_sleepable_preload+0x30bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30bf;
	}
x86_l_309f:
	/* 0x309f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_30a2:
	/* 0x30a2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_30a7:
	/* 0x30a7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_30ac:
	/* 0x30ac: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30b0:
	/* 0x30b0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30b5:
	/* 0x30b5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30b7:
	/* 0x30b7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_30b9:
	/* 0x30b9: js     3bb3 <generic_sleepable_preload+0x3bb3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15283ULL;
	}
x86_l_30bf:
	/* 0x30bf: cmp    WORD PTR [r12+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_30c9:
	/* 0x30c9: je     3bcc <generic_sleepable_preload+0x3bcc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15308ULL;
	}
x86_l_30cf:
	/* 0x30cf: mov    ecx,DWORD PTR [r12+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_30d7:
	/* 0x30d7: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_30db:
	/* 0x30db: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30df:
	/* 0x30df: cmp    WORD PTR [r12+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_30e9:
	/* 0x30e9: je     310b <generic_sleepable_preload+0x310b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_310b;
	}
x86_l_30eb:
	/* 0x30eb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_30ee:
	/* 0x30ee: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_30f3:
	/* 0x30f3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_30f8:
	/* 0x30f8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30fc:
	/* 0x30fc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3101:
	/* 0x3101: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3103:
	/* 0x3103: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3105:
	/* 0x3105: js     3bc4 <generic_sleepable_preload+0x3bc4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15300ULL;
	}
x86_l_310b:
	/* 0x310b: cmp    WORD PTR [r12+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_3115:
	/* 0x3115: je     3bcc <generic_sleepable_preload+0x3bcc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15308ULL;
	}
x86_l_311b:
	/* 0x311b: mov    ecx,DWORD PTR [r12+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_3123:
	/* 0x3123: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3127:
	/* 0x3127: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_312b:
	/* 0x312b: cmp    WORD PTR [r12+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_3135:
	/* 0x3135: je     3157 <generic_sleepable_preload+0x3157> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3157;
	}
x86_l_3137:
	/* 0x3137: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_313a:
	/* 0x313a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_313f:
	/* 0x313f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3144:
	/* 0x3144: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3148:
	/* 0x3148: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_314d:
	/* 0x314d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_314f:
	/* 0x314f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3151:
	/* 0x3151: js     5bf6 <generic_sleepable_preload+0x5bf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23542ULL;
	}
x86_l_3157:
	/* 0x3157: cmp    WORD PTR [r12+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_3161:
	/* 0x3161: je     3bcc <generic_sleepable_preload+0x3bcc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15308ULL;
	}
x86_l_3167:
	/* 0x3167: mov    ecx,DWORD PTR [r12+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_316f:
	/* 0x316f: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3173:
	/* 0x3173: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3177:
	/* 0x3177: cmp    WORD PTR [r12+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_3181:
	/* 0x3181: je     31a3 <generic_sleepable_preload+0x31a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31a3;
	}
x86_l_3183:
	/* 0x3183: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3186:
	/* 0x3186: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_318b:
	/* 0x318b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3190:
	/* 0x3190: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3194:
	/* 0x3194: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3199:
	/* 0x3199: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_319b:
	/* 0x319b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_319d:
	/* 0x319d: js     5cf0 <generic_sleepable_preload+0x5cf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23792ULL;
	}
x86_l_31a3:
	/* 0x31a3: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31a8:
	/* 0x31a8: cmp    WORD PTR [r12+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_31b2:
	/* 0x31b2: je     3bcc <generic_sleepable_preload+0x3bcc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15308ULL;
	}
x86_l_31b8:
	/* 0x31b8: mov    ecx,DWORD PTR [r12+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_31c0:
	/* 0x31c0: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_31c4:
	/* 0x31c4: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31c8:
	/* 0x31c8: cmp    WORD PTR [r12+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_31d2:
	/* 0x31d2: je     3bcc <generic_sleepable_preload+0x3bcc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15308ULL;
	}
x86_l_31d8:
	/* 0x31d8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_31db:
	/* 0x31db: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_31e0:
	/* 0x31e0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_31e5:
	/* 0x31e5: jmp    34bf <generic_sleepable_preload+0x34bf> */
	goto x86_l_34bf;
x86_l_31ea:
	/* 0x31ea: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_31ed:
	/* 0x31ed: je     320f <generic_sleepable_preload+0x320f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_320f;
	}
x86_l_31ef:
	/* 0x31ef: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_31f2:
	/* 0x31f2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_31f7:
	/* 0x31f7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_31fc:
	/* 0x31fc: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3200:
	/* 0x3200: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3205:
	/* 0x3205: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3207:
	/* 0x3207: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3209:
	/* 0x3209: js     34dc <generic_sleepable_preload+0x34dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_34dc;
	}
x86_l_320f:
	/* 0x320f: cmp    WORD PTR [r12+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_3219:
	/* 0x3219: je     3bcc <generic_sleepable_preload+0x3bcc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15308ULL;
	}
x86_l_321f:
	/* 0x321f: mov    ecx,DWORD PTR [r12+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_3227:
	/* 0x3227: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_322b:
	/* 0x322b: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_322f:
	/* 0x322f: cmp    WORD PTR [r12+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_3239:
	/* 0x3239: je     325b <generic_sleepable_preload+0x325b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_325b;
	}
x86_l_323b:
	/* 0x323b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_323e:
	/* 0x323e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3243:
	/* 0x3243: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3248:
	/* 0x3248: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_324c:
	/* 0x324c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3251:
	/* 0x3251: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3253:
	/* 0x3253: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3255:
	/* 0x3255: js     3544 <generic_sleepable_preload+0x3544> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3544;
	}
x86_l_325b:
	/* 0x325b: cmp    WORD PTR [r12+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_3265:
	/* 0x3265: je     3bcc <generic_sleepable_preload+0x3bcc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15308ULL;
	}
x86_l_326b:
	/* 0x326b: mov    ecx,DWORD PTR [r12+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_3273:
	/* 0x3273: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3277:
	/* 0x3277: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_327b:
	/* 0x327b: cmp    WORD PTR [r12+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_3285:
	/* 0x3285: je     32a7 <generic_sleepable_preload+0x32a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32a7;
	}
x86_l_3287:
	/* 0x3287: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_328a:
	/* 0x328a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_328f:
	/* 0x328f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3294:
	/* 0x3294: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3298:
	/* 0x3298: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_329d:
	/* 0x329d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_329f:
	/* 0x329f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_32a1:
	/* 0x32a1: js     3b80 <generic_sleepable_preload+0x3b80> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15232ULL;
	}
x86_l_32a7:
	/* 0x32a7: cmp    WORD PTR [r12+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_32b1:
	/* 0x32b1: je     3bcc <generic_sleepable_preload+0x3bcc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15308ULL;
	}
x86_l_32b7:
	/* 0x32b7: mov    ecx,DWORD PTR [r12+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_32bf:
	/* 0x32bf: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_32c3:
	/* 0x32c3: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32c7:
	/* 0x32c7: cmp    WORD PTR [r12+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_32d1:
	/* 0x32d1: je     32f3 <generic_sleepable_preload+0x32f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32f3;
	}
x86_l_32d3:
	/* 0x32d3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_32d6:
	/* 0x32d6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_32db:
	/* 0x32db: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_32e0:
	/* 0x32e0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32e4:
	/* 0x32e4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32e9:
	/* 0x32e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32eb:
	/* 0x32eb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_32ed:
	/* 0x32ed: js     3b91 <generic_sleepable_preload+0x3b91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15249ULL;
	}
x86_l_32f3:
	/* 0x32f3: cmp    WORD PTR [r12+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_32fd:
	/* 0x32fd: je     3bcc <generic_sleepable_preload+0x3bcc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15308ULL;
	}
x86_l_3303:
	/* 0x3303: mov    ecx,DWORD PTR [r12+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_330b:
	/* 0x330b: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_330f:
	/* 0x330f: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3313:
	/* 0x3313: cmp    WORD PTR [r12+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_331d:
	/* 0x331d: je     333f <generic_sleepable_preload+0x333f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_333f;
	}
x86_l_331f:
	/* 0x331f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3322:
	/* 0x3322: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3327:
	/* 0x3327: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_332c:
	/* 0x332c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3330:
	/* 0x3330: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3335:
	/* 0x3335: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3337:
	/* 0x3337: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3339:
	/* 0x3339: js     3ba2 <generic_sleepable_preload+0x3ba2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15266ULL;
	}
x86_l_333f:
	/* 0x333f: cmp    WORD PTR [r12+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_3349:
	/* 0x3349: je     3bcc <generic_sleepable_preload+0x3bcc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15308ULL;
	}
x86_l_334f:
	/* 0x334f: mov    ecx,DWORD PTR [r12+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_3357:
	/* 0x3357: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_335b:
	/* 0x335b: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_335f:
	/* 0x335f: cmp    WORD PTR [r12+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_3369:
	/* 0x3369: je     338b <generic_sleepable_preload+0x338b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_338b;
	}
x86_l_336b:
	/* 0x336b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_336e:
	/* 0x336e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3373:
	/* 0x3373: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3378:
	/* 0x3378: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_337c:
	/* 0x337c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3381:
	/* 0x3381: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3383:
	/* 0x3383: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3385:
	/* 0x3385: js     3bb3 <generic_sleepable_preload+0x3bb3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15283ULL;
	}
x86_l_338b:
	/* 0x338b: cmp    WORD PTR [r12+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_3395:
	/* 0x3395: je     3bcc <generic_sleepable_preload+0x3bcc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15308ULL;
	}
x86_l_339b:
	/* 0x339b: mov    ecx,DWORD PTR [r12+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_33a3:
	/* 0x33a3: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_33a7:
	/* 0x33a7: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33ab:
	/* 0x33ab: cmp    WORD PTR [r12+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_33b5:
	/* 0x33b5: je     33d7 <generic_sleepable_preload+0x33d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33d7;
	}
x86_l_33b7:
	/* 0x33b7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_33ba:
	/* 0x33ba: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_33bf:
	/* 0x33bf: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_33c4:
	/* 0x33c4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33c8:
	/* 0x33c8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33cd:
	/* 0x33cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33cf:
	/* 0x33cf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_33d1:
	/* 0x33d1: js     3bc4 <generic_sleepable_preload+0x3bc4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15300ULL;
	}
x86_l_33d7:
	/* 0x33d7: cmp    WORD PTR [r12+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_33e1:
	/* 0x33e1: je     3bcc <generic_sleepable_preload+0x3bcc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15308ULL;
	}
x86_l_33e7:
	/* 0x33e7: mov    r15,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R14, X86_WIDTH_64);
x86_l_33ea:
	/* 0x33ea: mov    ecx,DWORD PTR [r12+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_33f2:
	/* 0x33f2: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_33f6:
	/* 0x33f6: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33fa:
	/* 0x33fa: cmp    WORD PTR [r12+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_3404:
	/* 0x3404: je     3426 <generic_sleepable_preload+0x3426> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3426;
	}
x86_l_3406:
	/* 0x3406: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3409:
	/* 0x3409: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_340e:
	/* 0x340e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3413:
	/* 0x3413: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3417:
	/* 0x3417: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_341c:
	/* 0x341c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_341e:
	/* 0x341e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3420:
	/* 0x3420: js     5c74 <generic_sleepable_preload+0x5c74> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23668ULL;
	}
x86_l_3426:
	/* 0x3426: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_342b:
	/* 0x342b: cmp    WORD PTR [r12+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_3435:
	/* 0x3435: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_3438:
	/* 0x3438: je     3bcc <generic_sleepable_preload+0x3bcc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15308ULL;
	}
x86_l_343e:
	/* 0x343e: mov    ecx,DWORD PTR [r12+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_3446:
	/* 0x3446: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_344a:
	/* 0x344a: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_344e:
	/* 0x344e: cmp    WORD PTR [r12+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_3458:
	/* 0x3458: je     347a <generic_sleepable_preload+0x347a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_347a;
	}
x86_l_345a:
	/* 0x345a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_345d:
	/* 0x345d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3462:
	/* 0x3462: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3467:
	/* 0x3467: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_346b:
	/* 0x346b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3470:
	/* 0x3470: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3472:
	/* 0x3472: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3474:
	/* 0x3474: js     5d8c <generic_sleepable_preload+0x5d8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23948ULL;
	}
x86_l_347a:
	/* 0x347a: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_347f:
	/* 0x347f: cmp    WORD PTR [r12+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_3489:
	/* 0x3489: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_348c:
	/* 0x348c: je     3bcc <generic_sleepable_preload+0x3bcc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15308ULL;
	}
x86_l_3492:
	/* 0x3492: mov    ecx,DWORD PTR [r12+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_349a:
	/* 0x349a: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_349e:
	/* 0x349e: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34a2:
	/* 0x34a2: cmp    WORD PTR [r12+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_34ac:
	/* 0x34ac: je     3bcc <generic_sleepable_preload+0x3bcc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15308ULL;
	}
x86_l_34b2:
	/* 0x34b2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_34b5:
	/* 0x34b5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_34ba:
	/* 0x34ba: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_34bf:
	/* 0x34bf: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34c3:
	/* 0x34c3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_34c8:
	/* 0x34c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34ca:
	/* 0x34ca: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_34cc:
	/* 0x34cc: jns    3bcc <generic_sleepable_preload+0x3bcc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 15308ULL;
	}
x86_l_34d2:
	/* 0x34d2: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_34d7:
	/* 0x34d7: jmp    3bc9 <generic_sleepable_preload+0x3bc9> */
	return 15305ULL;
x86_l_34dc:
	/* 0x34dc: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_34e1:
	/* 0x34e1: jmp    3bc9 <generic_sleepable_preload+0x3bc9> */
	return 15305ULL;
x86_l_34e6:
	/* 0x34e6: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_34ee:
	/* 0x34ee: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_34f1:
	/* 0x34f1: je     3553 <generic_sleepable_preload+0x3553> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3553;
	}
x86_l_34f3:
	/* 0x34f3: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_34f8:
	/* 0x34f8: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_34fb:
	/* 0x34fb: je     3553 <generic_sleepable_preload+0x3553> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3553;
	}
x86_l_34fd:
	/* 0x34fd: jmp    3566 <generic_sleepable_preload+0x3566> */
	goto x86_l_3566;
x86_l_34ff:
	/* 0x34ff: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3504:
	/* 0x3504: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3507:
	/* 0x3507: je     3553 <generic_sleepable_preload+0x3553> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3553;
	}
x86_l_3509:
	/* 0x3509: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_350e:
	/* 0x350e: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_3511:
	/* 0x3511: je     3553 <generic_sleepable_preload+0x3553> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3553;
	}
x86_l_3513:
	/* 0x3513: jmp    3566 <generic_sleepable_preload+0x3566> */
	goto x86_l_3566;
x86_l_3515:
	/* 0x3515: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_351d:
	/* 0x351d: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_3520:
	/* 0x3520: je     3553 <generic_sleepable_preload+0x3553> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3553;
	}
x86_l_3522:
	/* 0x3522: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3527:
	/* 0x3527: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_352a:
	/* 0x352a: je     3553 <generic_sleepable_preload+0x3553> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3553;
	}
x86_l_352c:
	/* 0x352c: jmp    3566 <generic_sleepable_preload+0x3566> */
	goto x86_l_3566;
x86_l_352e:
	/* 0x352e: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3533:
	/* 0x3533: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_3536:
	/* 0x3536: je     3553 <generic_sleepable_preload+0x3553> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3553;
	}
x86_l_3538:
	/* 0x3538: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_353d:
	/* 0x353d: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_3540:
	/* 0x3540: je     3553 <generic_sleepable_preload+0x3553> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3553;
	}
x86_l_3542:
	/* 0x3542: jmp    3566 <generic_sleepable_preload+0x3566> */
	goto x86_l_3566;
x86_l_3544:
	/* 0x3544: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_3549:
	/* 0x3549: jmp    3bc9 <generic_sleepable_preload+0x3bc9> */
	return 15305ULL;
x86_l_354e:
	/* 0x354e: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3553:
	/* 0x3553: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_3556:
	/* 0x3556: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_3558:
	/* 0x3558: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_355a:
	/* 0x355a: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_355f:
	/* 0x355f: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3561:
	/* 0x3561: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_3566:
	/* 0x3566: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_356a:
	/* 0x356a: mov    ebp,DWORD PTR [r12+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_356f:
	/* 0x356f: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3571:
	/* 0x3571: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_3574:
	/* 0x3574: cmp    WORD PTR [r12+0x116],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1194000908288ULL);
x86_l_357e:
	/* 0x357e: je     3c57 <generic_sleepable_preload+0x3c57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15447ULL;
	}
x86_l_3584:
	/* 0x3584: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_358b:
	/* 0x358b: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_358e:
	/* 0x358e: mov    eax,DWORD PTR [r12+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_3596:
	/* 0x3596: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3599:
	/* 0x3599: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_359d:
	/* 0x359d: movzx  eax,WORD PTR [r12+0x114] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 276ULL);
x86_l_35a6:
	/* 0x35a6: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_35a8:
	/* 0x35a8: je     387a <generic_sleepable_preload+0x387a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14458ULL;
	}
x86_l_35ae:
	/* 0x35ae: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_35b1:
	/* 0x35b1: je     35d3 <generic_sleepable_preload+0x35d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35d3;
	}
x86_l_35b3:
	/* 0x35b3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_35b6:
	/* 0x35b6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_35bb:
	/* 0x35bb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_35c0:
	/* 0x35c0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35c4:
	/* 0x35c4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_35c9:
	/* 0x35c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35cb:
	/* 0x35cb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_35cd:
	/* 0x35cd: js     3b6c <generic_sleepable_preload+0x3b6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15212ULL;
	}
x86_l_35d3:
	/* 0x35d3: cmp    WORD PTR [r12+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_35dd:
	/* 0x35dd: je     3c57 <generic_sleepable_preload+0x3c57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15447ULL;
	}
x86_l_35e3:
	/* 0x35e3: mov    ecx,DWORD PTR [r12+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_35eb:
	/* 0x35eb: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_35ef:
	/* 0x35ef: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35f3:
	/* 0x35f3: cmp    WORD PTR [r12+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_35fd:
	/* 0x35fd: je     361f <generic_sleepable_preload+0x361f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_361f;
	}
x86_l_35ff:
	/* 0x35ff: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3602:
	/* 0x3602: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3607:
	/* 0x3607: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_360c:
	/* 0x360c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3610:
	/* 0x3610: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3615:
	/* 0x3615: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3617:
	/* 0x3617: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3619:
	/* 0x3619: js     3b76 <generic_sleepable_preload+0x3b76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15222ULL;
	}
x86_l_361f:
	/* 0x361f: cmp    WORD PTR [r12+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_3629:
	/* 0x3629: je     3c57 <generic_sleepable_preload+0x3c57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15447ULL;
	}
x86_l_362f:
	/* 0x362f: mov    ecx,DWORD PTR [r12+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_3637:
	/* 0x3637: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_363b:
	/* 0x363b: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_363f:
	/* 0x363f: cmp    WORD PTR [r12+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_3649:
	/* 0x3649: je     366b <generic_sleepable_preload+0x366b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_366b;
	}
x86_l_364b:
	/* 0x364b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_364e:
	/* 0x364e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3653:
	/* 0x3653: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3658:
	/* 0x3658: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_365c:
	/* 0x365c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3661:
	/* 0x3661: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3663:
	/* 0x3663: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3665:
	/* 0x3665: js     3b87 <generic_sleepable_preload+0x3b87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15239ULL;
	}
x86_l_366b:
	/* 0x366b: cmp    WORD PTR [r12+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_3675:
	/* 0x3675: je     3c57 <generic_sleepable_preload+0x3c57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15447ULL;
	}
x86_l_367b:
	/* 0x367b: mov    ecx,DWORD PTR [r12+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_3683:
	/* 0x3683: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3687:
	/* 0x3687: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_368b:
	/* 0x368b: cmp    WORD PTR [r12+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_3695:
	/* 0x3695: je     36b7 <generic_sleepable_preload+0x36b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36b7;
	}
x86_l_3697:
	/* 0x3697: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_369a:
	/* 0x369a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_369f:
	/* 0x369f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_36a4:
	/* 0x36a4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36a8:
	/* 0x36a8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_36ad:
	/* 0x36ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36af:
	/* 0x36af: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_36b1:
	/* 0x36b1: js     3b98 <generic_sleepable_preload+0x3b98> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15256ULL;
	}
x86_l_36b7:
	/* 0x36b7: cmp    WORD PTR [r12+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
	return 14017ULL;
}

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 14017ULL: goto x86_l_36c1;
	case 14023ULL: goto x86_l_36c7;
	case 14031ULL: goto x86_l_36cf;
	case 14035ULL: goto x86_l_36d3;
	case 14039ULL: goto x86_l_36d7;
	case 14049ULL: goto x86_l_36e1;
	case 14051ULL: goto x86_l_36e3;
	case 14054ULL: goto x86_l_36e6;
	case 14059ULL: goto x86_l_36eb;
	case 14064ULL: goto x86_l_36f0;
	case 14068ULL: goto x86_l_36f4;
	case 14073ULL: goto x86_l_36f9;
	case 14075ULL: goto x86_l_36fb;
	case 14077ULL: goto x86_l_36fd;
	case 14083ULL: goto x86_l_3703;
	case 14093ULL: goto x86_l_370d;
	case 14099ULL: goto x86_l_3713;
	case 14107ULL: goto x86_l_371b;
	case 14111ULL: goto x86_l_371f;
	case 14115ULL: goto x86_l_3723;
	case 14125ULL: goto x86_l_372d;
	case 14127ULL: goto x86_l_372f;
	case 14130ULL: goto x86_l_3732;
	case 14135ULL: goto x86_l_3737;
	case 14140ULL: goto x86_l_373c;
	case 14144ULL: goto x86_l_3740;
	case 14149ULL: goto x86_l_3745;
	case 14151ULL: goto x86_l_3747;
	case 14153ULL: goto x86_l_3749;
	case 14159ULL: goto x86_l_374f;
	case 14169ULL: goto x86_l_3759;
	case 14175ULL: goto x86_l_375f;
	case 14183ULL: goto x86_l_3767;
	case 14187ULL: goto x86_l_376b;
	case 14191ULL: goto x86_l_376f;
	case 14201ULL: goto x86_l_3779;
	case 14203ULL: goto x86_l_377b;
	case 14206ULL: goto x86_l_377e;
	case 14211ULL: goto x86_l_3783;
	case 14216ULL: goto x86_l_3788;
	case 14220ULL: goto x86_l_378c;
	case 14225ULL: goto x86_l_3791;
	case 14227ULL: goto x86_l_3793;
	case 14229ULL: goto x86_l_3795;
	case 14235ULL: goto x86_l_379b;
	case 14245ULL: goto x86_l_37a5;
	case 14251ULL: goto x86_l_37ab;
	case 14259ULL: goto x86_l_37b3;
	case 14263ULL: goto x86_l_37b7;
	case 14267ULL: goto x86_l_37bb;
	case 14277ULL: goto x86_l_37c5;
	case 14279ULL: goto x86_l_37c7;
	case 14282ULL: goto x86_l_37ca;
	case 14287ULL: goto x86_l_37cf;
	case 14292ULL: goto x86_l_37d4;
	case 14296ULL: goto x86_l_37d8;
	case 14301ULL: goto x86_l_37dd;
	case 14303ULL: goto x86_l_37df;
	case 14305ULL: goto x86_l_37e1;
	case 14311ULL: goto x86_l_37e7;
	case 14321ULL: goto x86_l_37f1;
	case 14327ULL: goto x86_l_37f7;
	case 14335ULL: goto x86_l_37ff;
	case 14339ULL: goto x86_l_3803;
	case 14343ULL: goto x86_l_3807;
	case 14353ULL: goto x86_l_3811;
	case 14355ULL: goto x86_l_3813;
	case 14358ULL: goto x86_l_3816;
	case 14363ULL: goto x86_l_381b;
	case 14368ULL: goto x86_l_3820;
	case 14372ULL: goto x86_l_3824;
	case 14377ULL: goto x86_l_3829;
	case 14379ULL: goto x86_l_382b;
	case 14381ULL: goto x86_l_382d;
	case 14387ULL: goto x86_l_3833;
	case 14392ULL: goto x86_l_3838;
	case 14402ULL: goto x86_l_3842;
	case 14408ULL: goto x86_l_3848;
	case 14416ULL: goto x86_l_3850;
	case 14420ULL: goto x86_l_3854;
	case 14424ULL: goto x86_l_3858;
	case 14434ULL: goto x86_l_3862;
	case 14440ULL: goto x86_l_3868;
	case 14443ULL: goto x86_l_386b;
	case 14448ULL: goto x86_l_3870;
	case 14453ULL: goto x86_l_3875;
	case 14458ULL: goto x86_l_387a;
	case 14461ULL: goto x86_l_387d;
	case 14463ULL: goto x86_l_387f;
	case 14466ULL: goto x86_l_3882;
	case 14471ULL: goto x86_l_3887;
	case 14476ULL: goto x86_l_388c;
	case 14480ULL: goto x86_l_3890;
	case 14485ULL: goto x86_l_3895;
	case 14487ULL: goto x86_l_3897;
	case 14489ULL: goto x86_l_3899;
	case 14495ULL: goto x86_l_389f;
	case 14505ULL: goto x86_l_38a9;
	case 14511ULL: goto x86_l_38af;
	case 14519ULL: goto x86_l_38b7;
	case 14523ULL: goto x86_l_38bb;
	case 14527ULL: goto x86_l_38bf;
	case 14537ULL: goto x86_l_38c9;
	case 14539ULL: goto x86_l_38cb;
	case 14542ULL: goto x86_l_38ce;
	case 14547ULL: goto x86_l_38d3;
	case 14552ULL: goto x86_l_38d8;
	case 14556ULL: goto x86_l_38dc;
	case 14561ULL: goto x86_l_38e1;
	case 14563ULL: goto x86_l_38e3;
	case 14565ULL: goto x86_l_38e5;
	case 14571ULL: goto x86_l_38eb;
	case 14581ULL: goto x86_l_38f5;
	case 14587ULL: goto x86_l_38fb;
	case 14595ULL: goto x86_l_3903;
	case 14599ULL: goto x86_l_3907;
	case 14603ULL: goto x86_l_390b;
	case 14613ULL: goto x86_l_3915;
	case 14615ULL: goto x86_l_3917;
	case 14618ULL: goto x86_l_391a;
	case 14623ULL: goto x86_l_391f;
	case 14628ULL: goto x86_l_3924;
	case 14632ULL: goto x86_l_3928;
	case 14637ULL: goto x86_l_392d;
	case 14639ULL: goto x86_l_392f;
	case 14641ULL: goto x86_l_3931;
	case 14647ULL: goto x86_l_3937;
	case 14657ULL: goto x86_l_3941;
	case 14663ULL: goto x86_l_3947;
	case 14671ULL: goto x86_l_394f;
	case 14675ULL: goto x86_l_3953;
	case 14679ULL: goto x86_l_3957;
	case 14689ULL: goto x86_l_3961;
	case 14691ULL: goto x86_l_3963;
	case 14694ULL: goto x86_l_3966;
	case 14699ULL: goto x86_l_396b;
	case 14704ULL: goto x86_l_3970;
	case 14708ULL: goto x86_l_3974;
	case 14713ULL: goto x86_l_3979;
	case 14715ULL: goto x86_l_397b;
	case 14717ULL: goto x86_l_397d;
	case 14723ULL: goto x86_l_3983;
	case 14733ULL: goto x86_l_398d;
	case 14739ULL: goto x86_l_3993;
	case 14747ULL: goto x86_l_399b;
	case 14751ULL: goto x86_l_399f;
	case 14755ULL: goto x86_l_39a3;
	case 14765ULL: goto x86_l_39ad;
	case 14767ULL: goto x86_l_39af;
	case 14770ULL: goto x86_l_39b2;
	case 14775ULL: goto x86_l_39b7;
	case 14780ULL: goto x86_l_39bc;
	case 14784ULL: goto x86_l_39c0;
	case 14789ULL: goto x86_l_39c5;
	case 14791ULL: goto x86_l_39c7;
	case 14793ULL: goto x86_l_39c9;
	case 14799ULL: goto x86_l_39cf;
	case 14809ULL: goto x86_l_39d9;
	case 14815ULL: goto x86_l_39df;
	case 14823ULL: goto x86_l_39e7;
	case 14827ULL: goto x86_l_39eb;
	case 14831ULL: goto x86_l_39ef;
	case 14841ULL: goto x86_l_39f9;
	case 14843ULL: goto x86_l_39fb;
	case 14846ULL: goto x86_l_39fe;
	case 14851ULL: goto x86_l_3a03;
	case 14856ULL: goto x86_l_3a08;
	case 14860ULL: goto x86_l_3a0c;
	case 14865ULL: goto x86_l_3a11;
	case 14867ULL: goto x86_l_3a13;
	case 14869ULL: goto x86_l_3a15;
	case 14875ULL: goto x86_l_3a1b;
	case 14885ULL: goto x86_l_3a25;
	case 14891ULL: goto x86_l_3a2b;
	case 14899ULL: goto x86_l_3a33;
	case 14903ULL: goto x86_l_3a37;
	case 14907ULL: goto x86_l_3a3b;
	case 14917ULL: goto x86_l_3a45;
	case 14919ULL: goto x86_l_3a47;
	case 14922ULL: goto x86_l_3a4a;
	case 14927ULL: goto x86_l_3a4f;
	case 14932ULL: goto x86_l_3a54;
	case 14936ULL: goto x86_l_3a58;
	case 14941ULL: goto x86_l_3a5d;
	case 14943ULL: goto x86_l_3a5f;
	case 14945ULL: goto x86_l_3a61;
	case 14951ULL: goto x86_l_3a67;
	case 14961ULL: goto x86_l_3a71;
	case 14967ULL: goto x86_l_3a77;
	case 14970ULL: goto x86_l_3a7a;
	case 14978ULL: goto x86_l_3a82;
	case 14982ULL: goto x86_l_3a86;
	case 14986ULL: goto x86_l_3a8a;
	case 14996ULL: goto x86_l_3a94;
	case 14998ULL: goto x86_l_3a96;
	case 15001ULL: goto x86_l_3a99;
	case 15006ULL: goto x86_l_3a9e;
	case 15011ULL: goto x86_l_3aa3;
	case 15015ULL: goto x86_l_3aa7;
	case 15020ULL: goto x86_l_3aac;
	case 15022ULL: goto x86_l_3aae;
	case 15024ULL: goto x86_l_3ab0;
	case 15030ULL: goto x86_l_3ab6;
	case 15035ULL: goto x86_l_3abb;
	case 15045ULL: goto x86_l_3ac5;
	case 15048ULL: goto x86_l_3ac8;
	case 15054ULL: goto x86_l_3ace;
	case 15062ULL: goto x86_l_3ad6;
	case 15066ULL: goto x86_l_3ada;
	case 15070ULL: goto x86_l_3ade;
	case 15080ULL: goto x86_l_3ae8;
	case 15082ULL: goto x86_l_3aea;
	case 15085ULL: goto x86_l_3aed;
	case 15090ULL: goto x86_l_3af2;
	case 15095ULL: goto x86_l_3af7;
	case 15099ULL: goto x86_l_3afb;
	case 15104ULL: goto x86_l_3b00;
	case 15106ULL: goto x86_l_3b02;
	case 15108ULL: goto x86_l_3b04;
	case 15114ULL: goto x86_l_3b0a;
	case 15119ULL: goto x86_l_3b0f;
	case 15129ULL: goto x86_l_3b19;
	case 15132ULL: goto x86_l_3b1c;
	case 15138ULL: goto x86_l_3b22;
	case 15146ULL: goto x86_l_3b2a;
	case 15150ULL: goto x86_l_3b2e;
	case 15154ULL: goto x86_l_3b32;
	case 15164ULL: goto x86_l_3b3c;
	case 15170ULL: goto x86_l_3b42;
	case 15173ULL: goto x86_l_3b45;
	case 15178ULL: goto x86_l_3b4a;
	case 15183ULL: goto x86_l_3b4f;
	case 15187ULL: goto x86_l_3b53;
	case 15192ULL: goto x86_l_3b58;
	case 15194ULL: goto x86_l_3b5a;
	case 15196ULL: goto x86_l_3b5c;
	case 15202ULL: goto x86_l_3b62;
	case 15207ULL: goto x86_l_3b67;
	case 15212ULL: goto x86_l_3b6c;
	case 15217ULL: goto x86_l_3b71;
	case 15222ULL: goto x86_l_3b76;
	case 15227ULL: goto x86_l_3b7b;
	case 15232ULL: goto x86_l_3b80;
	case 15237ULL: goto x86_l_3b85;
	case 15239ULL: goto x86_l_3b87;
	case 15244ULL: goto x86_l_3b8c;
	case 15249ULL: goto x86_l_3b91;
	case 15254ULL: goto x86_l_3b96;
	case 15256ULL: goto x86_l_3b98;
	case 15261ULL: goto x86_l_3b9d;
	case 15266ULL: goto x86_l_3ba2;
	case 15271ULL: goto x86_l_3ba7;
	case 15273ULL: goto x86_l_3ba9;
	case 15278ULL: goto x86_l_3bae;
	case 15283ULL: goto x86_l_3bb3;
	case 15288ULL: goto x86_l_3bb8;
	case 15290ULL: goto x86_l_3bba;
	case 15295ULL: goto x86_l_3bbf;
	case 15300ULL: goto x86_l_3bc4;
	case 15305ULL: goto x86_l_3bc9;
	case 15308ULL: goto x86_l_3bcc;
	case 15313ULL: goto x86_l_3bd1;
	case 15316ULL: goto x86_l_3bd4;
	case 15321ULL: goto x86_l_3bd9;
	case 15326ULL: goto x86_l_3bde;
	case 15331ULL: goto x86_l_3be3;
	case 15334ULL: goto x86_l_3be6;
	case 15336ULL: goto x86_l_3be8;
	case 15339ULL: goto x86_l_3beb;
	case 15345ULL: goto x86_l_3bf1;
	case 15348ULL: goto x86_l_3bf4;
	case 15352ULL: goto x86_l_3bf8;
	case 15357ULL: goto x86_l_3bfd;
	case 15359ULL: goto x86_l_3bff;
	case 15364ULL: goto x86_l_3c04;
	case 15372ULL: goto x86_l_3c0c;
	case 15379ULL: goto x86_l_3c13;
	case 15384ULL: goto x86_l_3c18;
	case 15389ULL: goto x86_l_3c1d;
	case 15391ULL: goto x86_l_3c1f;
	case 15394ULL: goto x86_l_3c22;
	case 15400ULL: goto x86_l_3c28;
	case 15403ULL: goto x86_l_3c2b;
	case 15410ULL: goto x86_l_3c32;
	case 15412ULL: goto x86_l_3c34;
	case 15417ULL: goto x86_l_3c39;
	case 15422ULL: goto x86_l_3c3e;
	case 15425ULL: goto x86_l_3c41;
	case 15428ULL: goto x86_l_3c44;
	case 15430ULL: goto x86_l_3c46;
	case 15432ULL: goto x86_l_3c48;
	case 15437ULL: goto x86_l_3c4d;
	case 15439ULL: goto x86_l_3c4f;
	case 15444ULL: goto x86_l_3c54;
	case 15447ULL: goto x86_l_3c57;
	case 15450ULL: goto x86_l_3c5a;
	case 15456ULL: goto x86_l_3c60;
	case 15459ULL: goto x86_l_3c63;
	case 15463ULL: goto x86_l_3c67;
	case 15468ULL: goto x86_l_3c6c;
	case 15470ULL: goto x86_l_3c6e;
	case 15475ULL: goto x86_l_3c73;
	case 15483ULL: goto x86_l_3c7b;
	case 15490ULL: goto x86_l_3c82;
	case 15495ULL: goto x86_l_3c87;
	case 15500ULL: goto x86_l_3c8c;
	case 15502ULL: goto x86_l_3c8e;
	case 15505ULL: goto x86_l_3c91;
	case 15507ULL: goto x86_l_3c93;
	case 15510ULL: goto x86_l_3c96;
	case 15517ULL: goto x86_l_3c9d;
	case 15519ULL: goto x86_l_3c9f;
	case 15524ULL: goto x86_l_3ca4;
	case 15529ULL: goto x86_l_3ca9;
	case 15532ULL: goto x86_l_3cac;
	case 15535ULL: goto x86_l_3caf;
	case 15537ULL: goto x86_l_3cb1;
	case 15539ULL: goto x86_l_3cb3;
	case 15544ULL: goto x86_l_3cb8;
	case 15547ULL: goto x86_l_3cbb;
	case 15550ULL: goto x86_l_3cbe;
	case 15555ULL: goto x86_l_3cc3;
	case 15557ULL: goto x86_l_3cc5;
	case 15560ULL: goto x86_l_3cc8;
	case 15562ULL: goto x86_l_3cca;
	case 15565ULL: goto x86_l_3ccd;
	case 15567ULL: goto x86_l_3ccf;
	case 15570ULL: goto x86_l_3cd2;
	case 15574ULL: goto x86_l_3cd6;
	case 15579ULL: goto x86_l_3cdb;
	case 15582ULL: goto x86_l_3cde;
	case 15584ULL: goto x86_l_3ce0;
	case 15587ULL: goto x86_l_3ce3;
	case 15592ULL: goto x86_l_3ce8;
	case 15594ULL: goto x86_l_3cea;
	case 15597ULL: goto x86_l_3ced;
	case 15599ULL: goto x86_l_3cef;
	case 15604ULL: goto x86_l_3cf4;
	case 15607ULL: goto x86_l_3cf7;
	case 15609ULL: goto x86_l_3cf9;
	case 15612ULL: goto x86_l_3cfc;
	case 15617ULL: goto x86_l_3d01;
	case 15622ULL: goto x86_l_3d06;
	case 15628ULL: goto x86_l_3d0c;
	case 15630ULL: goto x86_l_3d0e;
	case 15632ULL: goto x86_l_3d10;
	case 15637ULL: goto x86_l_3d15;
	case 15640ULL: goto x86_l_3d18;
	case 15646ULL: goto x86_l_3d1e;
	case 15649ULL: goto x86_l_3d21;
	case 15655ULL: goto x86_l_3d27;
	case 15658ULL: goto x86_l_3d2a;
	case 15664ULL: goto x86_l_3d30;
	case 15667ULL: goto x86_l_3d33;
	case 15673ULL: goto x86_l_3d39;
	case 15678ULL: goto x86_l_3d3e;
	case 15683ULL: goto x86_l_3d43;
	case 15692ULL: goto x86_l_3d4c;
	case 15701ULL: goto x86_l_3d55;
	case 15707ULL: goto x86_l_3d5b;
	case 15709ULL: goto x86_l_3d5d;
	case 15712ULL: goto x86_l_3d60;
	case 15714ULL: goto x86_l_3d62;
	case 15717ULL: goto x86_l_3d65;
	case 15719ULL: goto x86_l_3d67;
	case 15722ULL: goto x86_l_3d6a;
	case 15728ULL: goto x86_l_3d70;
	case 15733ULL: goto x86_l_3d75;
	case 15736ULL: goto x86_l_3d78;
	case 15742ULL: goto x86_l_3d7e;
	case 15747ULL: goto x86_l_3d83;
	case 15750ULL: goto x86_l_3d86;
	case 15756ULL: goto x86_l_3d8c;
	case 15761ULL: goto x86_l_3d91;
	case 15764ULL: goto x86_l_3d94;
	case 15770ULL: goto x86_l_3d9a;
	case 15775ULL: goto x86_l_3d9f;
	case 15778ULL: goto x86_l_3da2;
	case 15780ULL: goto x86_l_3da4;
	case 15783ULL: goto x86_l_3da7;
	case 15789ULL: goto x86_l_3dad;
	case 15791ULL: goto x86_l_3daf;
	case 15797ULL: goto x86_l_3db5;
	case 15800ULL: goto x86_l_3db8;
	default: return 0xffffffffffffffffULL;
	}
x86_l_36c1:
	/* 0x36c1: je     3c57 <generic_sleepable_preload+0x3c57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c57;
	}
x86_l_36c7:
	/* 0x36c7: mov    ecx,DWORD PTR [r12+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_36cf:
	/* 0x36cf: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_36d3:
	/* 0x36d3: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36d7:
	/* 0x36d7: cmp    WORD PTR [r12+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_36e1:
	/* 0x36e1: je     3703 <generic_sleepable_preload+0x3703> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3703;
	}
x86_l_36e3:
	/* 0x36e3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_36e6:
	/* 0x36e6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_36eb:
	/* 0x36eb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_36f0:
	/* 0x36f0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36f4:
	/* 0x36f4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_36f9:
	/* 0x36f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36fb:
	/* 0x36fb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_36fd:
	/* 0x36fd: js     3ba9 <generic_sleepable_preload+0x3ba9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3ba9;
	}
x86_l_3703:
	/* 0x3703: cmp    WORD PTR [r12+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_370d:
	/* 0x370d: je     3c57 <generic_sleepable_preload+0x3c57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c57;
	}
x86_l_3713:
	/* 0x3713: mov    ecx,DWORD PTR [r12+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_371b:
	/* 0x371b: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_371f:
	/* 0x371f: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3723:
	/* 0x3723: cmp    WORD PTR [r12+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_372d:
	/* 0x372d: je     374f <generic_sleepable_preload+0x374f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_374f;
	}
x86_l_372f:
	/* 0x372f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3732:
	/* 0x3732: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3737:
	/* 0x3737: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_373c:
	/* 0x373c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3740:
	/* 0x3740: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3745:
	/* 0x3745: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3747:
	/* 0x3747: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3749:
	/* 0x3749: js     3bba <generic_sleepable_preload+0x3bba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3bba;
	}
x86_l_374f:
	/* 0x374f: cmp    WORD PTR [r12+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_3759:
	/* 0x3759: je     3c57 <generic_sleepable_preload+0x3c57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c57;
	}
x86_l_375f:
	/* 0x375f: mov    ecx,DWORD PTR [r12+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_3767:
	/* 0x3767: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_376b:
	/* 0x376b: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_376f:
	/* 0x376f: cmp    WORD PTR [r12+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_3779:
	/* 0x3779: je     379b <generic_sleepable_preload+0x379b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_379b;
	}
x86_l_377b:
	/* 0x377b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_377e:
	/* 0x377e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3783:
	/* 0x3783: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3788:
	/* 0x3788: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_378c:
	/* 0x378c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3791:
	/* 0x3791: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3793:
	/* 0x3793: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3795:
	/* 0x3795: js     3c4f <generic_sleepable_preload+0x3c4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3c4f;
	}
x86_l_379b:
	/* 0x379b: cmp    WORD PTR [r12+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_37a5:
	/* 0x37a5: je     3c57 <generic_sleepable_preload+0x3c57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c57;
	}
x86_l_37ab:
	/* 0x37ab: mov    ecx,DWORD PTR [r12+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_37b3:
	/* 0x37b3: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_37b7:
	/* 0x37b7: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37bb:
	/* 0x37bb: cmp    WORD PTR [r12+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_37c5:
	/* 0x37c5: je     37e7 <generic_sleepable_preload+0x37e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37e7;
	}
x86_l_37c7:
	/* 0x37c7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_37ca:
	/* 0x37ca: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_37cf:
	/* 0x37cf: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_37d4:
	/* 0x37d4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37d8:
	/* 0x37d8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_37dd:
	/* 0x37dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37df:
	/* 0x37df: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_37e1:
	/* 0x37e1: js     5c03 <generic_sleepable_preload+0x5c03> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23555ULL;
	}
x86_l_37e7:
	/* 0x37e7: cmp    WORD PTR [r12+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_37f1:
	/* 0x37f1: je     3c57 <generic_sleepable_preload+0x3c57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c57;
	}
x86_l_37f7:
	/* 0x37f7: mov    ecx,DWORD PTR [r12+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_37ff:
	/* 0x37ff: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3803:
	/* 0x3803: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3807:
	/* 0x3807: cmp    WORD PTR [r12+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_3811:
	/* 0x3811: je     3833 <generic_sleepable_preload+0x3833> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3833;
	}
x86_l_3813:
	/* 0x3813: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3816:
	/* 0x3816: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_381b:
	/* 0x381b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3820:
	/* 0x3820: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3824:
	/* 0x3824: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3829:
	/* 0x3829: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_382b:
	/* 0x382b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_382d:
	/* 0x382d: js     5d02 <generic_sleepable_preload+0x5d02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23810ULL;
	}
x86_l_3833:
	/* 0x3833: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3838:
	/* 0x3838: cmp    WORD PTR [r12+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_3842:
	/* 0x3842: je     3c57 <generic_sleepable_preload+0x3c57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c57;
	}
x86_l_3848:
	/* 0x3848: mov    ecx,DWORD PTR [r12+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_3850:
	/* 0x3850: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3854:
	/* 0x3854: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3858:
	/* 0x3858: cmp    WORD PTR [r12+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_3862:
	/* 0x3862: je     3c57 <generic_sleepable_preload+0x3c57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c57;
	}
x86_l_3868:
	/* 0x3868: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_386b:
	/* 0x386b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3870:
	/* 0x3870: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3875:
	/* 0x3875: jmp    3b4f <generic_sleepable_preload+0x3b4f> */
	goto x86_l_3b4f;
x86_l_387a:
	/* 0x387a: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_387d:
	/* 0x387d: je     389f <generic_sleepable_preload+0x389f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_389f;
	}
x86_l_387f:
	/* 0x387f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3882:
	/* 0x3882: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3887:
	/* 0x3887: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_388c:
	/* 0x388c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3890:
	/* 0x3890: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3895:
	/* 0x3895: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3897:
	/* 0x3897: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3899:
	/* 0x3899: js     3b6c <generic_sleepable_preload+0x3b6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3b6c;
	}
x86_l_389f:
	/* 0x389f: cmp    WORD PTR [r12+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_38a9:
	/* 0x38a9: je     3c57 <generic_sleepable_preload+0x3c57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c57;
	}
x86_l_38af:
	/* 0x38af: mov    ecx,DWORD PTR [r12+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_38b7:
	/* 0x38b7: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_38bb:
	/* 0x38bb: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_38bf:
	/* 0x38bf: cmp    WORD PTR [r12+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_38c9:
	/* 0x38c9: je     38eb <generic_sleepable_preload+0x38eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38eb;
	}
x86_l_38cb:
	/* 0x38cb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_38ce:
	/* 0x38ce: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_38d3:
	/* 0x38d3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_38d8:
	/* 0x38d8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_38dc:
	/* 0x38dc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_38e1:
	/* 0x38e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38e3:
	/* 0x38e3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_38e5:
	/* 0x38e5: js     3b76 <generic_sleepable_preload+0x3b76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3b76;
	}
x86_l_38eb:
	/* 0x38eb: cmp    WORD PTR [r12+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_38f5:
	/* 0x38f5: je     3c57 <generic_sleepable_preload+0x3c57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c57;
	}
x86_l_38fb:
	/* 0x38fb: mov    ecx,DWORD PTR [r12+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_3903:
	/* 0x3903: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3907:
	/* 0x3907: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_390b:
	/* 0x390b: cmp    WORD PTR [r12+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_3915:
	/* 0x3915: je     3937 <generic_sleepable_preload+0x3937> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3937;
	}
x86_l_3917:
	/* 0x3917: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_391a:
	/* 0x391a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_391f:
	/* 0x391f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3924:
	/* 0x3924: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3928:
	/* 0x3928: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_392d:
	/* 0x392d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_392f:
	/* 0x392f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3931:
	/* 0x3931: js     3b87 <generic_sleepable_preload+0x3b87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3b87;
	}
x86_l_3937:
	/* 0x3937: cmp    WORD PTR [r12+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_3941:
	/* 0x3941: je     3c57 <generic_sleepable_preload+0x3c57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c57;
	}
x86_l_3947:
	/* 0x3947: mov    ecx,DWORD PTR [r12+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_394f:
	/* 0x394f: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3953:
	/* 0x3953: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3957:
	/* 0x3957: cmp    WORD PTR [r12+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_3961:
	/* 0x3961: je     3983 <generic_sleepable_preload+0x3983> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3983;
	}
x86_l_3963:
	/* 0x3963: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3966:
	/* 0x3966: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_396b:
	/* 0x396b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3970:
	/* 0x3970: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3974:
	/* 0x3974: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3979:
	/* 0x3979: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_397b:
	/* 0x397b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_397d:
	/* 0x397d: js     3b98 <generic_sleepable_preload+0x3b98> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3b98;
	}
x86_l_3983:
	/* 0x3983: cmp    WORD PTR [r12+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_398d:
	/* 0x398d: je     3c57 <generic_sleepable_preload+0x3c57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c57;
	}
x86_l_3993:
	/* 0x3993: mov    ecx,DWORD PTR [r12+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_399b:
	/* 0x399b: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_399f:
	/* 0x399f: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_39a3:
	/* 0x39a3: cmp    WORD PTR [r12+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_39ad:
	/* 0x39ad: je     39cf <generic_sleepable_preload+0x39cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_39cf;
	}
x86_l_39af:
	/* 0x39af: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_39b2:
	/* 0x39b2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_39b7:
	/* 0x39b7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_39bc:
	/* 0x39bc: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_39c0:
	/* 0x39c0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_39c5:
	/* 0x39c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39c7:
	/* 0x39c7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_39c9:
	/* 0x39c9: js     3ba9 <generic_sleepable_preload+0x3ba9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3ba9;
	}
x86_l_39cf:
	/* 0x39cf: cmp    WORD PTR [r12+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_39d9:
	/* 0x39d9: je     3c57 <generic_sleepable_preload+0x3c57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c57;
	}
x86_l_39df:
	/* 0x39df: mov    ecx,DWORD PTR [r12+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_39e7:
	/* 0x39e7: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_39eb:
	/* 0x39eb: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_39ef:
	/* 0x39ef: cmp    WORD PTR [r12+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_39f9:
	/* 0x39f9: je     3a1b <generic_sleepable_preload+0x3a1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a1b;
	}
x86_l_39fb:
	/* 0x39fb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_39fe:
	/* 0x39fe: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3a03:
	/* 0x3a03: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3a08:
	/* 0x3a08: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a0c:
	/* 0x3a0c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a11:
	/* 0x3a11: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a13:
	/* 0x3a13: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3a15:
	/* 0x3a15: js     3bba <generic_sleepable_preload+0x3bba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3bba;
	}
x86_l_3a1b:
	/* 0x3a1b: cmp    WORD PTR [r12+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_3a25:
	/* 0x3a25: je     3c57 <generic_sleepable_preload+0x3c57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c57;
	}
x86_l_3a2b:
	/* 0x3a2b: mov    ecx,DWORD PTR [r12+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_3a33:
	/* 0x3a33: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3a37:
	/* 0x3a37: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a3b:
	/* 0x3a3b: cmp    WORD PTR [r12+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_3a45:
	/* 0x3a45: je     3a67 <generic_sleepable_preload+0x3a67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a67;
	}
x86_l_3a47:
	/* 0x3a47: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3a4a:
	/* 0x3a4a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3a4f:
	/* 0x3a4f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3a54:
	/* 0x3a54: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a58:
	/* 0x3a58: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a5d:
	/* 0x3a5d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a5f:
	/* 0x3a5f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3a61:
	/* 0x3a61: js     3c4f <generic_sleepable_preload+0x3c4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3c4f;
	}
x86_l_3a67:
	/* 0x3a67: cmp    WORD PTR [r12+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_3a71:
	/* 0x3a71: je     3c57 <generic_sleepable_preload+0x3c57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c57;
	}
x86_l_3a77:
	/* 0x3a77: mov    r15,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R14, X86_WIDTH_64);
x86_l_3a7a:
	/* 0x3a7a: mov    ecx,DWORD PTR [r12+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_3a82:
	/* 0x3a82: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3a86:
	/* 0x3a86: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a8a:
	/* 0x3a8a: cmp    WORD PTR [r12+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_3a94:
	/* 0x3a94: je     3ab6 <generic_sleepable_preload+0x3ab6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ab6;
	}
x86_l_3a96:
	/* 0x3a96: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3a99:
	/* 0x3a99: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3a9e:
	/* 0x3a9e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3aa3:
	/* 0x3aa3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3aa7:
	/* 0x3aa7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3aac:
	/* 0x3aac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3aae:
	/* 0x3aae: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3ab0:
	/* 0x3ab0: js     5c81 <generic_sleepable_preload+0x5c81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23681ULL;
	}
x86_l_3ab6:
	/* 0x3ab6: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3abb:
	/* 0x3abb: cmp    WORD PTR [r12+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_3ac5:
	/* 0x3ac5: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_3ac8:
	/* 0x3ac8: je     3c57 <generic_sleepable_preload+0x3c57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c57;
	}
x86_l_3ace:
	/* 0x3ace: mov    ecx,DWORD PTR [r12+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_3ad6:
	/* 0x3ad6: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3ada:
	/* 0x3ada: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ade:
	/* 0x3ade: cmp    WORD PTR [r12+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_3ae8:
	/* 0x3ae8: je     3b0a <generic_sleepable_preload+0x3b0a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3b0a;
	}
x86_l_3aea:
	/* 0x3aea: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3aed:
	/* 0x3aed: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3af2:
	/* 0x3af2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3af7:
	/* 0x3af7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3afb:
	/* 0x3afb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b00:
	/* 0x3b00: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b02:
	/* 0x3b02: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3b04:
	/* 0x3b04: js     5da1 <generic_sleepable_preload+0x5da1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23969ULL;
	}
x86_l_3b0a:
	/* 0x3b0a: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3b0f:
	/* 0x3b0f: cmp    WORD PTR [r12+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_3b19:
	/* 0x3b19: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_3b1c:
	/* 0x3b1c: je     3c57 <generic_sleepable_preload+0x3c57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c57;
	}
x86_l_3b22:
	/* 0x3b22: mov    ecx,DWORD PTR [r12+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_3b2a:
	/* 0x3b2a: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3b2e:
	/* 0x3b2e: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3b32:
	/* 0x3b32: cmp    WORD PTR [r12+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_3b3c:
	/* 0x3b3c: je     3c57 <generic_sleepable_preload+0x3c57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c57;
	}
x86_l_3b42:
	/* 0x3b42: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3b45:
	/* 0x3b45: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3b4a:
	/* 0x3b4a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3b4f:
	/* 0x3b4f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3b53:
	/* 0x3b53: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b58:
	/* 0x3b58: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b5a:
	/* 0x3b5a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3b5c:
	/* 0x3b5c: jns    3c57 <generic_sleepable_preload+0x3c57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_3c57;
	}
x86_l_3b62:
	/* 0x3b62: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_3b67:
	/* 0x3b67: jmp    3c54 <generic_sleepable_preload+0x3c54> */
	goto x86_l_3c54;
x86_l_3b6c:
	/* 0x3b6c: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_3b71:
	/* 0x3b71: jmp    3c54 <generic_sleepable_preload+0x3c54> */
	goto x86_l_3c54;
x86_l_3b76:
	/* 0x3b76: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_3b7b:
	/* 0x3b7b: jmp    3c54 <generic_sleepable_preload+0x3c54> */
	goto x86_l_3c54;
x86_l_3b80:
	/* 0x3b80: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_3b85:
	/* 0x3b85: jmp    3bc9 <generic_sleepable_preload+0x3bc9> */
	goto x86_l_3bc9;
x86_l_3b87:
	/* 0x3b87: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_3b8c:
	/* 0x3b8c: jmp    3c54 <generic_sleepable_preload+0x3c54> */
	goto x86_l_3c54;
x86_l_3b91:
	/* 0x3b91: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_3b96:
	/* 0x3b96: jmp    3bc9 <generic_sleepable_preload+0x3bc9> */
	goto x86_l_3bc9;
x86_l_3b98:
	/* 0x3b98: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_3b9d:
	/* 0x3b9d: jmp    3c54 <generic_sleepable_preload+0x3c54> */
	goto x86_l_3c54;
x86_l_3ba2:
	/* 0x3ba2: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_3ba7:
	/* 0x3ba7: jmp    3bc9 <generic_sleepable_preload+0x3bc9> */
	goto x86_l_3bc9;
x86_l_3ba9:
	/* 0x3ba9: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_3bae:
	/* 0x3bae: jmp    3c54 <generic_sleepable_preload+0x3c54> */
	goto x86_l_3c54;
x86_l_3bb3:
	/* 0x3bb3: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_3bb8:
	/* 0x3bb8: jmp    3bc9 <generic_sleepable_preload+0x3bc9> */
	goto x86_l_3bc9;
x86_l_3bba:
	/* 0x3bba: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_3bbf:
	/* 0x3bbf: jmp    3c54 <generic_sleepable_preload+0x3c54> */
	goto x86_l_3c54;
x86_l_3bc4:
	/* 0x3bc4: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_3bc9:
	/* 0x3bc9: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3bcc:
	/* 0x3bcc: mov    ebp,DWORD PTR [r12+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3bd1:
	/* 0x3bd1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3bd4:
	/* 0x3bd4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3bd9:
	/* 0x3bd9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3bde:
	/* 0x3bde: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3be3:
	/* 0x3be3: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_3be6:
	/* 0x3be6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3be8:
	/* 0x3be8: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_3beb:
	/* 0x3beb: jne    3cfc <generic_sleepable_preload+0x3cfc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3cfc;
	}
x86_l_3bf1:
	/* 0x3bf1: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_3bf4:
	/* 0x3bf4: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3bf8:
	/* 0x3bf8: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_3bfd:
	/* 0x3bfd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3bff:
	/* 0x3bff: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3c04:
	/* 0x3c04: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_3c0c:
	/* 0x3c0c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_3c13:
	/* 0x3c13: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_3c18:
	/* 0x3c18: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3c1d:
	/* 0x3c1d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c1f:
	/* 0x3c1f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3c22:
	/* 0x3c22: je     3cf9 <generic_sleepable_preload+0x3cf9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3cf9;
	}
x86_l_3c28:
	/* 0x3c28: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_3c2b:
	/* 0x3c2b: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_3c32:
	/* 0x3c32: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3c34:
	/* 0x3c34: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3c39:
	/* 0x3c39: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3c3e:
	/* 0x3c3e: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_3c41:
	/* 0x3c41: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_3c44:
	/* 0x3c44: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3c46:
	/* 0x3c46: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c48:
	/* 0x3c48: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3c4d:
	/* 0x3c4d: jmp    3cb8 <generic_sleepable_preload+0x3cb8> */
	goto x86_l_3cb8;
x86_l_3c4f:
	/* 0x3c4f: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_3c54:
	/* 0x3c54: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3c57:
	/* 0x3c57: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_3c5a:
	/* 0x3c5a: jne    3cfc <generic_sleepable_preload+0x3cfc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3cfc;
	}
x86_l_3c60:
	/* 0x3c60: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_3c63:
	/* 0x3c63: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c67:
	/* 0x3c67: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_3c6c:
	/* 0x3c6c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c6e:
	/* 0x3c6e: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3c73:
	/* 0x3c73: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_3c7b:
	/* 0x3c7b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_3c82:
	/* 0x3c82: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_3c87:
	/* 0x3c87: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3c8c:
	/* 0x3c8c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c8e:
	/* 0x3c8e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3c91:
	/* 0x3c91: je     3cf9 <generic_sleepable_preload+0x3cf9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3cf9;
	}
x86_l_3c93:
	/* 0x3c93: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_3c96:
	/* 0x3c96: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_3c9d:
	/* 0x3c9d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3c9f:
	/* 0x3c9f: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3ca4:
	/* 0x3ca4: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3ca9:
	/* 0x3ca9: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_3cac:
	/* 0x3cac: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_3caf:
	/* 0x3caf: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3cb1:
	/* 0x3cb1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3cb3:
	/* 0x3cb3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3cb8:
	/* 0x3cb8: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_3cbb:
	/* 0x3cbb: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_3cbe:
	/* 0x3cbe: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3cc3:
	/* 0x3cc3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3cc5:
	/* 0x3cc5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3cc8:
	/* 0x3cc8: je     3cf9 <generic_sleepable_preload+0x3cf9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3cf9;
	}
x86_l_3cca:
	/* 0x3cca: test   r13b,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_8);
x86_l_3ccd:
	/* 0x3ccd: je     3cf7 <generic_sleepable_preload+0x3cf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3cf7;
	}
x86_l_3ccf:
	/* 0x3ccf: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_3cd2:
	/* 0x3cd2: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_3cd6:
	/* 0x3cd6: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3cdb:
	/* 0x3cdb: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_3cde:
	/* 0x3cde: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3ce0:
	/* 0x3ce0: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_3ce3:
	/* 0x3ce3: call   3ce8 <generic_sleepable_preload+0x3ce8> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_3ce8:
	/* 0x3ce8: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_3cea:
	/* 0x3cea: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_3ced:
	/* 0x3ced: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_3cef:
	/* 0x3cef: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_3cf4:
	/* 0x3cf4: cmovs  ebx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_3cf7:
	/* 0x3cf7: mov    DWORD PTR [rax],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3cf9:
	/* 0x3cf9: mov    r14,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_64);
x86_l_3cfc:
	/* 0x3cfc: mov    eax,DWORD PTR [r12+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_3d01:
	/* 0x3d01: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_3d06:
	/* 0x3d06: je     4c67 <generic_sleepable_preload+0x4c67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19559ULL;
	}
x86_l_3d0c:
	/* 0x3d0c: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_3d0e:
	/* 0x3d0e: js     3d43 <generic_sleepable_preload+0x3d43> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3d43;
	}
x86_l_3d10:
	/* 0x3d10: mov    eax,DWORD PTR [r12+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_3d15:
	/* 0x3d15: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3d18:
	/* 0x3d18: jle    3dc6 <generic_sleepable_preload+0x3dc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 15814ULL;
	}
x86_l_3d1e:
	/* 0x3d1e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3d21:
	/* 0x3d21: je     3e30 <generic_sleepable_preload+0x3e30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15920ULL;
	}
x86_l_3d27:
	/* 0x3d27: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_3d2a:
	/* 0x3d2a: je     3e37 <generic_sleepable_preload+0x3e37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15927ULL;
	}
x86_l_3d30:
	/* 0x3d30: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3d33:
	/* 0x3d33: jne    3e4a <generic_sleepable_preload+0x3e4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 15946ULL;
	}
x86_l_3d39:
	/* 0x3d39: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3d3e:
	/* 0x3d3e: jmp    3e43 <generic_sleepable_preload+0x3e43> */
	return 15939ULL;
x86_l_3d43:
	/* 0x3d43: movzx  eax,BYTE PTR [r12+0x2ce] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 718ULL);
x86_l_3d4c:
	/* 0x3d4c: movzx  ecx,WORD PTR [r12+0x2cc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 716ULL);
x86_l_3d55:
	/* 0x3d55: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_3d5b:
	/* 0x3d5b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3d5d:
	/* 0x3d5d: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_3d60:
	/* 0x3d60: jle    3d9f <generic_sleepable_preload+0x3d9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_3d9f;
	}
x86_l_3d62:
	/* 0x3d62: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_3d65:
	/* 0x3d65: jle    3dd6 <generic_sleepable_preload+0x3dd6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 15830ULL;
	}
x86_l_3d67:
	/* 0x3d67: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_3d6a:
	/* 0x3d6a: jle    4499 <generic_sleepable_preload+0x4499> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 17561ULL;
	}
x86_l_3d70:
	/* 0x3d70: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3d75:
	/* 0x3d75: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_3d78:
	/* 0x3d78: je     44be <generic_sleepable_preload+0x44be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17598ULL;
	}
x86_l_3d7e:
	/* 0x3d7e: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3d83:
	/* 0x3d83: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_3d86:
	/* 0x3d86: je     44be <generic_sleepable_preload+0x44be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17598ULL;
	}
x86_l_3d8c:
	/* 0x3d8c: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3d91:
	/* 0x3d91: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_3d94:
	/* 0x3d94: je     44be <generic_sleepable_preload+0x44be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17598ULL;
	}
x86_l_3d9a:
	/* 0x3d9a: jmp    44d1 <generic_sleepable_preload+0x44d1> */
	return 17617ULL;
x86_l_3d9f:
	/* 0x3d9f: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_3da2:
	/* 0x3da2: jg     3e03 <generic_sleepable_preload+0x3e03> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 15875ULL;
	}
x86_l_3da4:
	/* 0x3da4: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_3da7:
	/* 0x3da7: jg     446a <generic_sleepable_preload+0x446a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 17514ULL;
	}
x86_l_3dad:
	/* 0x3dad: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_3daf:
	/* 0x3daf: je     44b9 <generic_sleepable_preload+0x44b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17593ULL;
	}
x86_l_3db5:
	/* 0x3db5: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_3db8:
	/* 0x3db8: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
	return 15803ULL;
}

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_9(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 15803ULL: goto x86_l_3dbb;
	case 15809ULL: goto x86_l_3dc1;
	case 15814ULL: goto x86_l_3dc6;
	case 15816ULL: goto x86_l_3dc8;
	case 15818ULL: goto x86_l_3dca;
	case 15821ULL: goto x86_l_3dcd;
	case 15823ULL: goto x86_l_3dcf;
	case 15828ULL: goto x86_l_3dd4;
	case 15830ULL: goto x86_l_3dd6;
	case 15833ULL: goto x86_l_3dd9;
	case 15839ULL: goto x86_l_3ddf;
	case 15847ULL: goto x86_l_3de7;
	case 15850ULL: goto x86_l_3dea;
	case 15856ULL: goto x86_l_3df0;
	case 15861ULL: goto x86_l_3df5;
	case 15864ULL: goto x86_l_3df8;
	case 15870ULL: goto x86_l_3dfe;
	case 15875ULL: goto x86_l_3e03;
	case 15878ULL: goto x86_l_3e06;
	case 15884ULL: goto x86_l_3e0c;
	case 15892ULL: goto x86_l_3e14;
	case 15895ULL: goto x86_l_3e17;
	case 15901ULL: goto x86_l_3e1d;
	case 15906ULL: goto x86_l_3e22;
	case 15909ULL: goto x86_l_3e25;
	case 15915ULL: goto x86_l_3e2b;
	case 15920ULL: goto x86_l_3e30;
	case 15925ULL: goto x86_l_3e35;
	case 15927ULL: goto x86_l_3e37;
	case 15932ULL: goto x86_l_3e3c;
	case 15934ULL: goto x86_l_3e3e;
	case 15939ULL: goto x86_l_3e43;
	case 15942ULL: goto x86_l_3e46;
	case 15946ULL: goto x86_l_3e4a;
	case 15948ULL: goto x86_l_3e4c;
	case 15951ULL: goto x86_l_3e4f;
	case 15961ULL: goto x86_l_3e59;
	case 15967ULL: goto x86_l_3e5f;
	case 15974ULL: goto x86_l_3e66;
	case 15977ULL: goto x86_l_3e69;
	case 15985ULL: goto x86_l_3e71;
	case 15988ULL: goto x86_l_3e74;
	case 15992ULL: goto x86_l_3e78;
	case 16001ULL: goto x86_l_3e81;
	case 16003ULL: goto x86_l_3e83;
	case 16009ULL: goto x86_l_3e89;
	case 16012ULL: goto x86_l_3e8c;
	case 16014ULL: goto x86_l_3e8e;
	case 16017ULL: goto x86_l_3e91;
	case 16022ULL: goto x86_l_3e96;
	case 16027ULL: goto x86_l_3e9b;
	case 16031ULL: goto x86_l_3e9f;
	case 16036ULL: goto x86_l_3ea4;
	case 16038ULL: goto x86_l_3ea6;
	case 16040ULL: goto x86_l_3ea8;
	case 16046ULL: goto x86_l_3eae;
	case 16056ULL: goto x86_l_3eb8;
	case 16062ULL: goto x86_l_3ebe;
	case 16070ULL: goto x86_l_3ec6;
	case 16074ULL: goto x86_l_3eca;
	case 16078ULL: goto x86_l_3ece;
	case 16088ULL: goto x86_l_3ed8;
	case 16090ULL: goto x86_l_3eda;
	case 16093ULL: goto x86_l_3edd;
	case 16098ULL: goto x86_l_3ee2;
	case 16103ULL: goto x86_l_3ee7;
	case 16107ULL: goto x86_l_3eeb;
	case 16112ULL: goto x86_l_3ef0;
	case 16114ULL: goto x86_l_3ef2;
	case 16116ULL: goto x86_l_3ef4;
	case 16122ULL: goto x86_l_3efa;
	case 16132ULL: goto x86_l_3f04;
	case 16138ULL: goto x86_l_3f0a;
	case 16146ULL: goto x86_l_3f12;
	case 16150ULL: goto x86_l_3f16;
	case 16154ULL: goto x86_l_3f1a;
	case 16164ULL: goto x86_l_3f24;
	case 16166ULL: goto x86_l_3f26;
	case 16169ULL: goto x86_l_3f29;
	case 16174ULL: goto x86_l_3f2e;
	case 16179ULL: goto x86_l_3f33;
	case 16183ULL: goto x86_l_3f37;
	case 16188ULL: goto x86_l_3f3c;
	case 16190ULL: goto x86_l_3f3e;
	case 16192ULL: goto x86_l_3f40;
	case 16198ULL: goto x86_l_3f46;
	case 16208ULL: goto x86_l_3f50;
	case 16214ULL: goto x86_l_3f56;
	case 16222ULL: goto x86_l_3f5e;
	case 16226ULL: goto x86_l_3f62;
	case 16230ULL: goto x86_l_3f66;
	case 16240ULL: goto x86_l_3f70;
	case 16242ULL: goto x86_l_3f72;
	case 16245ULL: goto x86_l_3f75;
	case 16250ULL: goto x86_l_3f7a;
	case 16255ULL: goto x86_l_3f7f;
	case 16259ULL: goto x86_l_3f83;
	case 16264ULL: goto x86_l_3f88;
	case 16266ULL: goto x86_l_3f8a;
	case 16268ULL: goto x86_l_3f8c;
	case 16274ULL: goto x86_l_3f92;
	case 16284ULL: goto x86_l_3f9c;
	case 16290ULL: goto x86_l_3fa2;
	case 16298ULL: goto x86_l_3faa;
	case 16302ULL: goto x86_l_3fae;
	case 16306ULL: goto x86_l_3fb2;
	case 16316ULL: goto x86_l_3fbc;
	case 16318ULL: goto x86_l_3fbe;
	case 16321ULL: goto x86_l_3fc1;
	case 16326ULL: goto x86_l_3fc6;
	case 16331ULL: goto x86_l_3fcb;
	case 16335ULL: goto x86_l_3fcf;
	case 16340ULL: goto x86_l_3fd4;
	case 16342ULL: goto x86_l_3fd6;
	case 16344ULL: goto x86_l_3fd8;
	case 16350ULL: goto x86_l_3fde;
	case 16360ULL: goto x86_l_3fe8;
	case 16366ULL: goto x86_l_3fee;
	case 16374ULL: goto x86_l_3ff6;
	case 16378ULL: goto x86_l_3ffa;
	case 16382ULL: goto x86_l_3ffe;
	case 16392ULL: goto x86_l_4008;
	case 16394ULL: goto x86_l_400a;
	case 16397ULL: goto x86_l_400d;
	case 16402ULL: goto x86_l_4012;
	case 16407ULL: goto x86_l_4017;
	case 16411ULL: goto x86_l_401b;
	case 16416ULL: goto x86_l_4020;
	case 16418ULL: goto x86_l_4022;
	case 16420ULL: goto x86_l_4024;
	case 16426ULL: goto x86_l_402a;
	case 16436ULL: goto x86_l_4034;
	case 16442ULL: goto x86_l_403a;
	case 16450ULL: goto x86_l_4042;
	case 16454ULL: goto x86_l_4046;
	case 16458ULL: goto x86_l_404a;
	case 16468ULL: goto x86_l_4054;
	case 16470ULL: goto x86_l_4056;
	case 16473ULL: goto x86_l_4059;
	case 16478ULL: goto x86_l_405e;
	case 16483ULL: goto x86_l_4063;
	case 16487ULL: goto x86_l_4067;
	case 16492ULL: goto x86_l_406c;
	case 16494ULL: goto x86_l_406e;
	case 16496ULL: goto x86_l_4070;
	case 16502ULL: goto x86_l_4076;
	case 16512ULL: goto x86_l_4080;
	case 16518ULL: goto x86_l_4086;
	case 16526ULL: goto x86_l_408e;
	case 16530ULL: goto x86_l_4092;
	case 16534ULL: goto x86_l_4096;
	case 16544ULL: goto x86_l_40a0;
	case 16546ULL: goto x86_l_40a2;
	case 16549ULL: goto x86_l_40a5;
	case 16554ULL: goto x86_l_40aa;
	case 16559ULL: goto x86_l_40af;
	case 16563ULL: goto x86_l_40b3;
	case 16568ULL: goto x86_l_40b8;
	case 16570ULL: goto x86_l_40ba;
	case 16572ULL: goto x86_l_40bc;
	case 16578ULL: goto x86_l_40c2;
	case 16588ULL: goto x86_l_40cc;
	case 16594ULL: goto x86_l_40d2;
	case 16602ULL: goto x86_l_40da;
	case 16606ULL: goto x86_l_40de;
	case 16610ULL: goto x86_l_40e2;
	case 16620ULL: goto x86_l_40ec;
	case 16622ULL: goto x86_l_40ee;
	case 16625ULL: goto x86_l_40f1;
	case 16630ULL: goto x86_l_40f6;
	case 16635ULL: goto x86_l_40fb;
	case 16639ULL: goto x86_l_40ff;
	case 16644ULL: goto x86_l_4104;
	case 16646ULL: goto x86_l_4106;
	case 16648ULL: goto x86_l_4108;
	case 16654ULL: goto x86_l_410e;
	case 16659ULL: goto x86_l_4113;
	case 16669ULL: goto x86_l_411d;
	case 16675ULL: goto x86_l_4123;
	case 16683ULL: goto x86_l_412b;
	case 16687ULL: goto x86_l_412f;
	case 16691ULL: goto x86_l_4133;
	case 16701ULL: goto x86_l_413d;
	case 16707ULL: goto x86_l_4143;
	case 16710ULL: goto x86_l_4146;
	case 16715ULL: goto x86_l_414b;
	case 16720ULL: goto x86_l_4150;
	case 16725ULL: goto x86_l_4155;
	case 16728ULL: goto x86_l_4158;
	case 16730ULL: goto x86_l_415a;
	case 16733ULL: goto x86_l_415d;
	case 16738ULL: goto x86_l_4162;
	case 16743ULL: goto x86_l_4167;
	case 16747ULL: goto x86_l_416b;
	case 16752ULL: goto x86_l_4170;
	case 16754ULL: goto x86_l_4172;
	case 16756ULL: goto x86_l_4174;
	case 16762ULL: goto x86_l_417a;
	case 16772ULL: goto x86_l_4184;
	case 16778ULL: goto x86_l_418a;
	case 16786ULL: goto x86_l_4192;
	case 16790ULL: goto x86_l_4196;
	case 16794ULL: goto x86_l_419a;
	case 16804ULL: goto x86_l_41a4;
	case 16806ULL: goto x86_l_41a6;
	case 16809ULL: goto x86_l_41a9;
	case 16814ULL: goto x86_l_41ae;
	case 16819ULL: goto x86_l_41b3;
	case 16823ULL: goto x86_l_41b7;
	case 16828ULL: goto x86_l_41bc;
	case 16830ULL: goto x86_l_41be;
	case 16832ULL: goto x86_l_41c0;
	case 16838ULL: goto x86_l_41c6;
	case 16848ULL: goto x86_l_41d0;
	case 16854ULL: goto x86_l_41d6;
	case 16862ULL: goto x86_l_41de;
	case 16866ULL: goto x86_l_41e2;
	case 16870ULL: goto x86_l_41e6;
	case 16880ULL: goto x86_l_41f0;
	case 16882ULL: goto x86_l_41f2;
	case 16885ULL: goto x86_l_41f5;
	case 16890ULL: goto x86_l_41fa;
	case 16895ULL: goto x86_l_41ff;
	case 16899ULL: goto x86_l_4203;
	case 16904ULL: goto x86_l_4208;
	case 16906ULL: goto x86_l_420a;
	case 16908ULL: goto x86_l_420c;
	case 16914ULL: goto x86_l_4212;
	case 16924ULL: goto x86_l_421c;
	case 16930ULL: goto x86_l_4222;
	case 16938ULL: goto x86_l_422a;
	case 16942ULL: goto x86_l_422e;
	case 16946ULL: goto x86_l_4232;
	case 16956ULL: goto x86_l_423c;
	case 16958ULL: goto x86_l_423e;
	case 16961ULL: goto x86_l_4241;
	case 16966ULL: goto x86_l_4246;
	case 16971ULL: goto x86_l_424b;
	case 16975ULL: goto x86_l_424f;
	case 16980ULL: goto x86_l_4254;
	case 16982ULL: goto x86_l_4256;
	case 16984ULL: goto x86_l_4258;
	case 16990ULL: goto x86_l_425e;
	case 17000ULL: goto x86_l_4268;
	case 17006ULL: goto x86_l_426e;
	case 17014ULL: goto x86_l_4276;
	case 17018ULL: goto x86_l_427a;
	case 17022ULL: goto x86_l_427e;
	case 17032ULL: goto x86_l_4288;
	case 17034ULL: goto x86_l_428a;
	case 17037ULL: goto x86_l_428d;
	case 17042ULL: goto x86_l_4292;
	case 17047ULL: goto x86_l_4297;
	case 17051ULL: goto x86_l_429b;
	case 17056ULL: goto x86_l_42a0;
	case 17058ULL: goto x86_l_42a2;
	case 17060ULL: goto x86_l_42a4;
	case 17066ULL: goto x86_l_42aa;
	case 17076ULL: goto x86_l_42b4;
	case 17082ULL: goto x86_l_42ba;
	case 17090ULL: goto x86_l_42c2;
	case 17094ULL: goto x86_l_42c6;
	case 17098ULL: goto x86_l_42ca;
	case 17108ULL: goto x86_l_42d4;
	case 17110ULL: goto x86_l_42d6;
	case 17113ULL: goto x86_l_42d9;
	case 17118ULL: goto x86_l_42de;
	case 17123ULL: goto x86_l_42e3;
	case 17127ULL: goto x86_l_42e7;
	case 17132ULL: goto x86_l_42ec;
	case 17134ULL: goto x86_l_42ee;
	case 17136ULL: goto x86_l_42f0;
	case 17142ULL: goto x86_l_42f6;
	case 17152ULL: goto x86_l_4300;
	case 17158ULL: goto x86_l_4306;
	case 17166ULL: goto x86_l_430e;
	case 17170ULL: goto x86_l_4312;
	case 17174ULL: goto x86_l_4316;
	case 17184ULL: goto x86_l_4320;
	case 17186ULL: goto x86_l_4322;
	case 17189ULL: goto x86_l_4325;
	case 17194ULL: goto x86_l_432a;
	case 17199ULL: goto x86_l_432f;
	case 17203ULL: goto x86_l_4333;
	case 17208ULL: goto x86_l_4338;
	case 17210ULL: goto x86_l_433a;
	case 17212ULL: goto x86_l_433c;
	case 17218ULL: goto x86_l_4342;
	case 17228ULL: goto x86_l_434c;
	case 17234ULL: goto x86_l_4352;
	case 17237ULL: goto x86_l_4355;
	case 17245ULL: goto x86_l_435d;
	case 17249ULL: goto x86_l_4361;
	case 17253ULL: goto x86_l_4365;
	case 17263ULL: goto x86_l_436f;
	case 17265ULL: goto x86_l_4371;
	case 17268ULL: goto x86_l_4374;
	case 17273ULL: goto x86_l_4379;
	case 17278ULL: goto x86_l_437e;
	case 17282ULL: goto x86_l_4382;
	case 17287ULL: goto x86_l_4387;
	case 17289ULL: goto x86_l_4389;
	case 17291ULL: goto x86_l_438b;
	case 17297ULL: goto x86_l_4391;
	case 17302ULL: goto x86_l_4396;
	case 17312ULL: goto x86_l_43a0;
	case 17315ULL: goto x86_l_43a3;
	case 17321ULL: goto x86_l_43a9;
	case 17329ULL: goto x86_l_43b1;
	case 17333ULL: goto x86_l_43b5;
	case 17337ULL: goto x86_l_43b9;
	case 17347ULL: goto x86_l_43c3;
	case 17349ULL: goto x86_l_43c5;
	case 17352ULL: goto x86_l_43c8;
	case 17357ULL: goto x86_l_43cd;
	case 17362ULL: goto x86_l_43d2;
	case 17366ULL: goto x86_l_43d6;
	case 17371ULL: goto x86_l_43db;
	case 17373ULL: goto x86_l_43dd;
	case 17375ULL: goto x86_l_43df;
	case 17381ULL: goto x86_l_43e5;
	case 17386ULL: goto x86_l_43ea;
	case 17396ULL: goto x86_l_43f4;
	case 17399ULL: goto x86_l_43f7;
	case 17405ULL: goto x86_l_43fd;
	case 17413ULL: goto x86_l_4405;
	case 17417ULL: goto x86_l_4409;
	case 17421ULL: goto x86_l_440d;
	case 17431ULL: goto x86_l_4417;
	case 17437ULL: goto x86_l_441d;
	case 17440ULL: goto x86_l_4420;
	case 17445ULL: goto x86_l_4425;
	case 17450ULL: goto x86_l_442a;
	case 17454ULL: goto x86_l_442e;
	case 17459ULL: goto x86_l_4433;
	case 17461ULL: goto x86_l_4435;
	case 17463ULL: goto x86_l_4437;
	case 17469ULL: goto x86_l_443d;
	case 17474ULL: goto x86_l_4442;
	case 17479ULL: goto x86_l_4447;
	case 17484ULL: goto x86_l_444c;
	case 17489ULL: goto x86_l_4451;
	case 17497ULL: goto x86_l_4459;
	case 17500ULL: goto x86_l_445c;
	case 17502ULL: goto x86_l_445e;
	case 17507ULL: goto x86_l_4463;
	case 17510ULL: goto x86_l_4466;
	case 17512ULL: goto x86_l_4468;
	case 17514ULL: goto x86_l_446a;
	case 17519ULL: goto x86_l_446f;
	case 17522ULL: goto x86_l_4472;
	case 17524ULL: goto x86_l_4474;
	case 17529ULL: goto x86_l_4479;
	case 17532ULL: goto x86_l_447c;
	case 17534ULL: goto x86_l_447e;
	case 17536ULL: goto x86_l_4480;
	case 17544ULL: goto x86_l_4488;
	case 17547ULL: goto x86_l_448b;
	case 17549ULL: goto x86_l_448d;
	case 17554ULL: goto x86_l_4492;
	case 17557ULL: goto x86_l_4495;
	case 17559ULL: goto x86_l_4497;
	case 17561ULL: goto x86_l_4499;
	case 17566ULL: goto x86_l_449e;
	case 17569ULL: goto x86_l_44a1;
	case 17571ULL: goto x86_l_44a3;
	case 17576ULL: goto x86_l_44a8;
	case 17579ULL: goto x86_l_44ab;
	case 17581ULL: goto x86_l_44ad;
	case 17583ULL: goto x86_l_44af;
	case 17588ULL: goto x86_l_44b4;
	case 17593ULL: goto x86_l_44b9;
	case 17598ULL: goto x86_l_44be;
	case 17601ULL: goto x86_l_44c1;
	case 17603ULL: goto x86_l_44c3;
	case 17605ULL: goto x86_l_44c5;
	case 17610ULL: goto x86_l_44ca;
	case 17612ULL: goto x86_l_44cc;
	case 17617ULL: goto x86_l_44d1;
	case 17621ULL: goto x86_l_44d5;
	case 17626ULL: goto x86_l_44da;
	case 17628ULL: goto x86_l_44dc;
	case 17631ULL: goto x86_l_44df;
	case 17641ULL: goto x86_l_44e9;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3dbb:
	/* 0x3dbb: je     44be <generic_sleepable_preload+0x44be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44be;
	}
x86_l_3dc1:
	/* 0x3dc1: jmp    44d1 <generic_sleepable_preload+0x44d1> */
	goto x86_l_44d1;
x86_l_3dc6:
	/* 0x3dc6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3dc8:
	/* 0x3dc8: je     3e3e <generic_sleepable_preload+0x3e3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e3e;
	}
x86_l_3dca:
	/* 0x3dca: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3dcd:
	/* 0x3dcd: jne    3e4a <generic_sleepable_preload+0x3e4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3e4a;
	}
x86_l_3dcf:
	/* 0x3dcf: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3dd4:
	/* 0x3dd4: jmp    3e43 <generic_sleepable_preload+0x3e43> */
	goto x86_l_3e43;
x86_l_3dd6:
	/* 0x3dd6: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_3dd9:
	/* 0x3dd9: jg     4451 <generic_sleepable_preload+0x4451> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_4451;
	}
x86_l_3ddf:
	/* 0x3ddf: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_3de7:
	/* 0x3de7: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3dea:
	/* 0x3dea: je     44be <generic_sleepable_preload+0x44be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44be;
	}
x86_l_3df0:
	/* 0x3df0: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3df5:
	/* 0x3df5: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_3df8:
	/* 0x3df8: je     44be <generic_sleepable_preload+0x44be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44be;
	}
x86_l_3dfe:
	/* 0x3dfe: jmp    44d1 <generic_sleepable_preload+0x44d1> */
	goto x86_l_44d1;
x86_l_3e03:
	/* 0x3e03: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_3e06:
	/* 0x3e06: jg     4480 <generic_sleepable_preload+0x4480> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_4480;
	}
x86_l_3e0c:
	/* 0x3e0c: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3e14:
	/* 0x3e14: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_3e17:
	/* 0x3e17: je     44be <generic_sleepable_preload+0x44be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44be;
	}
x86_l_3e1d:
	/* 0x3e1d: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3e22:
	/* 0x3e22: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_3e25:
	/* 0x3e25: je     44be <generic_sleepable_preload+0x44be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44be;
	}
x86_l_3e2b:
	/* 0x3e2b: jmp    44d1 <generic_sleepable_preload+0x44d1> */
	goto x86_l_44d1;
x86_l_3e30:
	/* 0x3e30: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3e35:
	/* 0x3e35: jmp    3e43 <generic_sleepable_preload+0x3e43> */
	goto x86_l_3e43;
x86_l_3e37:
	/* 0x3e37: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3e3c:
	/* 0x3e3c: jmp    3e43 <generic_sleepable_preload+0x3e43> */
	goto x86_l_3e43;
x86_l_3e3e:
	/* 0x3e3e: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3e43:
	/* 0x3e43: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e46:
	/* 0x3e46: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e4a:
	/* 0x3e4a: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3e4c:
	/* 0x3e4c: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_3e4f:
	/* 0x3e4f: cmp    WORD PTR [r12+0x166],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1537598291968ULL);
x86_l_3e59:
	/* 0x3e59: je     4b37 <generic_sleepable_preload+0x4b37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19255ULL;
	}
x86_l_3e5f:
	/* 0x3e5f: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_3e66:
	/* 0x3e66: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_3e69:
	/* 0x3e69: mov    eax,DWORD PTR [r12+0x160] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_3e71:
	/* 0x3e71: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3e74:
	/* 0x3e74: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e78:
	/* 0x3e78: movzx  eax,WORD PTR [r12+0x164] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 356ULL);
x86_l_3e81:
	/* 0x3e81: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_3e83:
	/* 0x3e83: je     4155 <generic_sleepable_preload+0x4155> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4155;
	}
x86_l_3e89:
	/* 0x3e89: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_3e8c:
	/* 0x3e8c: je     3eae <generic_sleepable_preload+0x3eae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3eae;
	}
x86_l_3e8e:
	/* 0x3e8e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3e91:
	/* 0x3e91: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3e96:
	/* 0x3e96: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3e9b:
	/* 0x3e9b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e9f:
	/* 0x3e9f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3ea4:
	/* 0x3ea4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ea6:
	/* 0x3ea6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3ea8:
	/* 0x3ea8: js     4447 <generic_sleepable_preload+0x4447> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4447;
	}
x86_l_3eae:
	/* 0x3eae: cmp    WORD PTR [r12+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_3eb8:
	/* 0x3eb8: je     4b37 <generic_sleepable_preload+0x4b37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19255ULL;
	}
x86_l_3ebe:
	/* 0x3ebe: mov    ecx,DWORD PTR [r12+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_3ec6:
	/* 0x3ec6: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3eca:
	/* 0x3eca: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ece:
	/* 0x3ece: cmp    WORD PTR [r12+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_3ed8:
	/* 0x3ed8: je     3efa <generic_sleepable_preload+0x3efa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3efa;
	}
x86_l_3eda:
	/* 0x3eda: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3edd:
	/* 0x3edd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3ee2:
	/* 0x3ee2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3ee7:
	/* 0x3ee7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3eeb:
	/* 0x3eeb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3ef0:
	/* 0x3ef0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ef2:
	/* 0x3ef2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3ef4:
	/* 0x3ef4: js     44af <generic_sleepable_preload+0x44af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_44af;
	}
x86_l_3efa:
	/* 0x3efa: cmp    WORD PTR [r12+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_3f04:
	/* 0x3f04: je     4b37 <generic_sleepable_preload+0x4b37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19255ULL;
	}
x86_l_3f0a:
	/* 0x3f0a: mov    ecx,DWORD PTR [r12+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_3f12:
	/* 0x3f12: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3f16:
	/* 0x3f16: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f1a:
	/* 0x3f1a: cmp    WORD PTR [r12+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_3f24:
	/* 0x3f24: je     3f46 <generic_sleepable_preload+0x3f46> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3f46;
	}
x86_l_3f26:
	/* 0x3f26: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3f29:
	/* 0x3f29: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3f2e:
	/* 0x3f2e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3f33:
	/* 0x3f33: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f37:
	/* 0x3f37: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3f3c:
	/* 0x3f3c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f3e:
	/* 0x3f3e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3f40:
	/* 0x3f40: js     4aeb <generic_sleepable_preload+0x4aeb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19179ULL;
	}
x86_l_3f46:
	/* 0x3f46: cmp    WORD PTR [r12+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_3f50:
	/* 0x3f50: je     4b37 <generic_sleepable_preload+0x4b37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19255ULL;
	}
x86_l_3f56:
	/* 0x3f56: mov    ecx,DWORD PTR [r12+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_3f5e:
	/* 0x3f5e: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3f62:
	/* 0x3f62: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f66:
	/* 0x3f66: cmp    WORD PTR [r12+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_3f70:
	/* 0x3f70: je     3f92 <generic_sleepable_preload+0x3f92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3f92;
	}
x86_l_3f72:
	/* 0x3f72: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3f75:
	/* 0x3f75: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3f7a:
	/* 0x3f7a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3f7f:
	/* 0x3f7f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f83:
	/* 0x3f83: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3f88:
	/* 0x3f88: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f8a:
	/* 0x3f8a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3f8c:
	/* 0x3f8c: js     4afc <generic_sleepable_preload+0x4afc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19196ULL;
	}
x86_l_3f92:
	/* 0x3f92: cmp    WORD PTR [r12+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_3f9c:
	/* 0x3f9c: je     4b37 <generic_sleepable_preload+0x4b37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19255ULL;
	}
x86_l_3fa2:
	/* 0x3fa2: mov    ecx,DWORD PTR [r12+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_3faa:
	/* 0x3faa: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3fae:
	/* 0x3fae: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3fb2:
	/* 0x3fb2: cmp    WORD PTR [r12+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_3fbc:
	/* 0x3fbc: je     3fde <generic_sleepable_preload+0x3fde> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3fde;
	}
x86_l_3fbe:
	/* 0x3fbe: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3fc1:
	/* 0x3fc1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3fc6:
	/* 0x3fc6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3fcb:
	/* 0x3fcb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3fcf:
	/* 0x3fcf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3fd4:
	/* 0x3fd4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3fd6:
	/* 0x3fd6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3fd8:
	/* 0x3fd8: js     4b0d <generic_sleepable_preload+0x4b0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19213ULL;
	}
x86_l_3fde:
	/* 0x3fde: cmp    WORD PTR [r12+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_3fe8:
	/* 0x3fe8: je     4b37 <generic_sleepable_preload+0x4b37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19255ULL;
	}
x86_l_3fee:
	/* 0x3fee: mov    ecx,DWORD PTR [r12+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_3ff6:
	/* 0x3ff6: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3ffa:
	/* 0x3ffa: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ffe:
	/* 0x3ffe: cmp    WORD PTR [r12+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_4008:
	/* 0x4008: je     402a <generic_sleepable_preload+0x402a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_402a;
	}
x86_l_400a:
	/* 0x400a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_400d:
	/* 0x400d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4012:
	/* 0x4012: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4017:
	/* 0x4017: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_401b:
	/* 0x401b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4020:
	/* 0x4020: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4022:
	/* 0x4022: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4024:
	/* 0x4024: js     4b1e <generic_sleepable_preload+0x4b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19230ULL;
	}
x86_l_402a:
	/* 0x402a: cmp    WORD PTR [r12+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_4034:
	/* 0x4034: je     4b37 <generic_sleepable_preload+0x4b37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19255ULL;
	}
x86_l_403a:
	/* 0x403a: mov    ecx,DWORD PTR [r12+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_4042:
	/* 0x4042: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4046:
	/* 0x4046: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_404a:
	/* 0x404a: cmp    WORD PTR [r12+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_4054:
	/* 0x4054: je     4076 <generic_sleepable_preload+0x4076> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4076;
	}
x86_l_4056:
	/* 0x4056: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4059:
	/* 0x4059: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_405e:
	/* 0x405e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4063:
	/* 0x4063: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4067:
	/* 0x4067: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_406c:
	/* 0x406c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_406e:
	/* 0x406e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4070:
	/* 0x4070: js     4b2f <generic_sleepable_preload+0x4b2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19247ULL;
	}
x86_l_4076:
	/* 0x4076: cmp    WORD PTR [r12+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_4080:
	/* 0x4080: je     4b37 <generic_sleepable_preload+0x4b37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19255ULL;
	}
x86_l_4086:
	/* 0x4086: mov    ecx,DWORD PTR [r12+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_408e:
	/* 0x408e: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4092:
	/* 0x4092: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4096:
	/* 0x4096: cmp    WORD PTR [r12+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_40a0:
	/* 0x40a0: je     40c2 <generic_sleepable_preload+0x40c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40c2;
	}
x86_l_40a2:
	/* 0x40a2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_40a5:
	/* 0x40a5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_40aa:
	/* 0x40aa: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_40af:
	/* 0x40af: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_40b3:
	/* 0x40b3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_40b8:
	/* 0x40b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40ba:
	/* 0x40ba: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_40bc:
	/* 0x40bc: js     5c10 <generic_sleepable_preload+0x5c10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23568ULL;
	}
x86_l_40c2:
	/* 0x40c2: cmp    WORD PTR [r12+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_40cc:
	/* 0x40cc: je     4b37 <generic_sleepable_preload+0x4b37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19255ULL;
	}
x86_l_40d2:
	/* 0x40d2: mov    ecx,DWORD PTR [r12+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_40da:
	/* 0x40da: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_40de:
	/* 0x40de: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_40e2:
	/* 0x40e2: cmp    WORD PTR [r12+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_40ec:
	/* 0x40ec: je     410e <generic_sleepable_preload+0x410e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_410e;
	}
x86_l_40ee:
	/* 0x40ee: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_40f1:
	/* 0x40f1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_40f6:
	/* 0x40f6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_40fb:
	/* 0x40fb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_40ff:
	/* 0x40ff: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4104:
	/* 0x4104: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4106:
	/* 0x4106: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4108:
	/* 0x4108: js     5d14 <generic_sleepable_preload+0x5d14> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23828ULL;
	}
x86_l_410e:
	/* 0x410e: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4113:
	/* 0x4113: cmp    WORD PTR [r12+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_411d:
	/* 0x411d: je     4b37 <generic_sleepable_preload+0x4b37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19255ULL;
	}
x86_l_4123:
	/* 0x4123: mov    ecx,DWORD PTR [r12+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_412b:
	/* 0x412b: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_412f:
	/* 0x412f: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4133:
	/* 0x4133: cmp    WORD PTR [r12+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_413d:
	/* 0x413d: je     4b37 <generic_sleepable_preload+0x4b37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19255ULL;
	}
x86_l_4143:
	/* 0x4143: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4146:
	/* 0x4146: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_414b:
	/* 0x414b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4150:
	/* 0x4150: jmp    442a <generic_sleepable_preload+0x442a> */
	goto x86_l_442a;
x86_l_4155:
	/* 0x4155: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_4158:
	/* 0x4158: je     417a <generic_sleepable_preload+0x417a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_417a;
	}
x86_l_415a:
	/* 0x415a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_415d:
	/* 0x415d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4162:
	/* 0x4162: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4167:
	/* 0x4167: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_416b:
	/* 0x416b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4170:
	/* 0x4170: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4172:
	/* 0x4172: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4174:
	/* 0x4174: js     4447 <generic_sleepable_preload+0x4447> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4447;
	}
x86_l_417a:
	/* 0x417a: cmp    WORD PTR [r12+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_4184:
	/* 0x4184: je     4b37 <generic_sleepable_preload+0x4b37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19255ULL;
	}
x86_l_418a:
	/* 0x418a: mov    ecx,DWORD PTR [r12+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_4192:
	/* 0x4192: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4196:
	/* 0x4196: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_419a:
	/* 0x419a: cmp    WORD PTR [r12+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_41a4:
	/* 0x41a4: je     41c6 <generic_sleepable_preload+0x41c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_41c6;
	}
x86_l_41a6:
	/* 0x41a6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_41a9:
	/* 0x41a9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_41ae:
	/* 0x41ae: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_41b3:
	/* 0x41b3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_41b7:
	/* 0x41b7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_41bc:
	/* 0x41bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41be:
	/* 0x41be: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_41c0:
	/* 0x41c0: js     44af <generic_sleepable_preload+0x44af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_44af;
	}
x86_l_41c6:
	/* 0x41c6: cmp    WORD PTR [r12+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_41d0:
	/* 0x41d0: je     4b37 <generic_sleepable_preload+0x4b37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19255ULL;
	}
x86_l_41d6:
	/* 0x41d6: mov    ecx,DWORD PTR [r12+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_41de:
	/* 0x41de: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_41e2:
	/* 0x41e2: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_41e6:
	/* 0x41e6: cmp    WORD PTR [r12+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_41f0:
	/* 0x41f0: je     4212 <generic_sleepable_preload+0x4212> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4212;
	}
x86_l_41f2:
	/* 0x41f2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_41f5:
	/* 0x41f5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_41fa:
	/* 0x41fa: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_41ff:
	/* 0x41ff: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4203:
	/* 0x4203: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4208:
	/* 0x4208: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_420a:
	/* 0x420a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_420c:
	/* 0x420c: js     4aeb <generic_sleepable_preload+0x4aeb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19179ULL;
	}
x86_l_4212:
	/* 0x4212: cmp    WORD PTR [r12+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_421c:
	/* 0x421c: je     4b37 <generic_sleepable_preload+0x4b37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19255ULL;
	}
x86_l_4222:
	/* 0x4222: mov    ecx,DWORD PTR [r12+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_422a:
	/* 0x422a: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_422e:
	/* 0x422e: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4232:
	/* 0x4232: cmp    WORD PTR [r12+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_423c:
	/* 0x423c: je     425e <generic_sleepable_preload+0x425e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_425e;
	}
x86_l_423e:
	/* 0x423e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4241:
	/* 0x4241: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4246:
	/* 0x4246: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_424b:
	/* 0x424b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_424f:
	/* 0x424f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4254:
	/* 0x4254: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4256:
	/* 0x4256: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4258:
	/* 0x4258: js     4afc <generic_sleepable_preload+0x4afc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19196ULL;
	}
x86_l_425e:
	/* 0x425e: cmp    WORD PTR [r12+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_4268:
	/* 0x4268: je     4b37 <generic_sleepable_preload+0x4b37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19255ULL;
	}
x86_l_426e:
	/* 0x426e: mov    ecx,DWORD PTR [r12+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_4276:
	/* 0x4276: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_427a:
	/* 0x427a: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_427e:
	/* 0x427e: cmp    WORD PTR [r12+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_4288:
	/* 0x4288: je     42aa <generic_sleepable_preload+0x42aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_42aa;
	}
x86_l_428a:
	/* 0x428a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_428d:
	/* 0x428d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4292:
	/* 0x4292: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4297:
	/* 0x4297: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_429b:
	/* 0x429b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_42a0:
	/* 0x42a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42a2:
	/* 0x42a2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_42a4:
	/* 0x42a4: js     4b0d <generic_sleepable_preload+0x4b0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19213ULL;
	}
x86_l_42aa:
	/* 0x42aa: cmp    WORD PTR [r12+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_42b4:
	/* 0x42b4: je     4b37 <generic_sleepable_preload+0x4b37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19255ULL;
	}
x86_l_42ba:
	/* 0x42ba: mov    ecx,DWORD PTR [r12+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_42c2:
	/* 0x42c2: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_42c6:
	/* 0x42c6: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_42ca:
	/* 0x42ca: cmp    WORD PTR [r12+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_42d4:
	/* 0x42d4: je     42f6 <generic_sleepable_preload+0x42f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_42f6;
	}
x86_l_42d6:
	/* 0x42d6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_42d9:
	/* 0x42d9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_42de:
	/* 0x42de: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_42e3:
	/* 0x42e3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_42e7:
	/* 0x42e7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_42ec:
	/* 0x42ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42ee:
	/* 0x42ee: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_42f0:
	/* 0x42f0: js     4b1e <generic_sleepable_preload+0x4b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19230ULL;
	}
x86_l_42f6:
	/* 0x42f6: cmp    WORD PTR [r12+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_4300:
	/* 0x4300: je     4b37 <generic_sleepable_preload+0x4b37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19255ULL;
	}
x86_l_4306:
	/* 0x4306: mov    ecx,DWORD PTR [r12+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_430e:
	/* 0x430e: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4312:
	/* 0x4312: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4316:
	/* 0x4316: cmp    WORD PTR [r12+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_4320:
	/* 0x4320: je     4342 <generic_sleepable_preload+0x4342> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4342;
	}
x86_l_4322:
	/* 0x4322: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4325:
	/* 0x4325: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_432a:
	/* 0x432a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_432f:
	/* 0x432f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4333:
	/* 0x4333: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4338:
	/* 0x4338: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_433a:
	/* 0x433a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_433c:
	/* 0x433c: js     4b2f <generic_sleepable_preload+0x4b2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19247ULL;
	}
x86_l_4342:
	/* 0x4342: cmp    WORD PTR [r12+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_434c:
	/* 0x434c: je     4b37 <generic_sleepable_preload+0x4b37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19255ULL;
	}
x86_l_4352:
	/* 0x4352: mov    r15,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R14, X86_WIDTH_64);
x86_l_4355:
	/* 0x4355: mov    ecx,DWORD PTR [r12+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_435d:
	/* 0x435d: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4361:
	/* 0x4361: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4365:
	/* 0x4365: cmp    WORD PTR [r12+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_436f:
	/* 0x436f: je     4391 <generic_sleepable_preload+0x4391> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4391;
	}
x86_l_4371:
	/* 0x4371: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4374:
	/* 0x4374: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4379:
	/* 0x4379: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_437e:
	/* 0x437e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4382:
	/* 0x4382: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4387:
	/* 0x4387: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4389:
	/* 0x4389: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_438b:
	/* 0x438b: js     5c8e <generic_sleepable_preload+0x5c8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23694ULL;
	}
x86_l_4391:
	/* 0x4391: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4396:
	/* 0x4396: cmp    WORD PTR [r12+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_43a0:
	/* 0x43a0: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_43a3:
	/* 0x43a3: je     4b37 <generic_sleepable_preload+0x4b37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19255ULL;
	}
x86_l_43a9:
	/* 0x43a9: mov    ecx,DWORD PTR [r12+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_43b1:
	/* 0x43b1: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_43b5:
	/* 0x43b5: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_43b9:
	/* 0x43b9: cmp    WORD PTR [r12+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_43c3:
	/* 0x43c3: je     43e5 <generic_sleepable_preload+0x43e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_43e5;
	}
x86_l_43c5:
	/* 0x43c5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_43c8:
	/* 0x43c8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_43cd:
	/* 0x43cd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_43d2:
	/* 0x43d2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_43d6:
	/* 0x43d6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_43db:
	/* 0x43db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_43dd:
	/* 0x43dd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_43df:
	/* 0x43df: js     5db6 <generic_sleepable_preload+0x5db6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23990ULL;
	}
x86_l_43e5:
	/* 0x43e5: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_43ea:
	/* 0x43ea: cmp    WORD PTR [r12+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_43f4:
	/* 0x43f4: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_43f7:
	/* 0x43f7: je     4b37 <generic_sleepable_preload+0x4b37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19255ULL;
	}
x86_l_43fd:
	/* 0x43fd: mov    ecx,DWORD PTR [r12+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_4405:
	/* 0x4405: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4409:
	/* 0x4409: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_440d:
	/* 0x440d: cmp    WORD PTR [r12+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_4417:
	/* 0x4417: je     4b37 <generic_sleepable_preload+0x4b37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19255ULL;
	}
x86_l_441d:
	/* 0x441d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4420:
	/* 0x4420: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4425:
	/* 0x4425: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_442a:
	/* 0x442a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_442e:
	/* 0x442e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4433:
	/* 0x4433: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4435:
	/* 0x4435: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4437:
	/* 0x4437: jns    4b37 <generic_sleepable_preload+0x4b37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 19255ULL;
	}
x86_l_443d:
	/* 0x443d: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_4442:
	/* 0x4442: jmp    4b34 <generic_sleepable_preload+0x4b34> */
	return 19252ULL;
x86_l_4447:
	/* 0x4447: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_444c:
	/* 0x444c: jmp    4b34 <generic_sleepable_preload+0x4b34> */
	return 19252ULL;
x86_l_4451:
	/* 0x4451: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_4459:
	/* 0x4459: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_445c:
	/* 0x445c: je     44be <generic_sleepable_preload+0x44be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44be;
	}
x86_l_445e:
	/* 0x445e: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4463:
	/* 0x4463: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_4466:
	/* 0x4466: je     44be <generic_sleepable_preload+0x44be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44be;
	}
x86_l_4468:
	/* 0x4468: jmp    44d1 <generic_sleepable_preload+0x44d1> */
	goto x86_l_44d1;
x86_l_446a:
	/* 0x446a: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_446f:
	/* 0x446f: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_4472:
	/* 0x4472: je     44be <generic_sleepable_preload+0x44be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44be;
	}
x86_l_4474:
	/* 0x4474: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_4479:
	/* 0x4479: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_447c:
	/* 0x447c: je     44be <generic_sleepable_preload+0x44be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44be;
	}
x86_l_447e:
	/* 0x447e: jmp    44d1 <generic_sleepable_preload+0x44d1> */
	goto x86_l_44d1;
x86_l_4480:
	/* 0x4480: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_4488:
	/* 0x4488: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_448b:
	/* 0x448b: je     44be <generic_sleepable_preload+0x44be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44be;
	}
x86_l_448d:
	/* 0x448d: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_4492:
	/* 0x4492: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_4495:
	/* 0x4495: je     44be <generic_sleepable_preload+0x44be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44be;
	}
x86_l_4497:
	/* 0x4497: jmp    44d1 <generic_sleepable_preload+0x44d1> */
	goto x86_l_44d1;
x86_l_4499:
	/* 0x4499: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_449e:
	/* 0x449e: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_44a1:
	/* 0x44a1: je     44be <generic_sleepable_preload+0x44be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44be;
	}
x86_l_44a3:
	/* 0x44a3: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_44a8:
	/* 0x44a8: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_44ab:
	/* 0x44ab: je     44be <generic_sleepable_preload+0x44be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44be;
	}
x86_l_44ad:
	/* 0x44ad: jmp    44d1 <generic_sleepable_preload+0x44d1> */
	goto x86_l_44d1;
x86_l_44af:
	/* 0x44af: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_44b4:
	/* 0x44b4: jmp    4b34 <generic_sleepable_preload+0x4b34> */
	return 19252ULL;
x86_l_44b9:
	/* 0x44b9: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_44be:
	/* 0x44be: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_44c1:
	/* 0x44c1: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_44c3:
	/* 0x44c3: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_44c5:
	/* 0x44c5: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_44ca:
	/* 0x44ca: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_44cc:
	/* 0x44cc: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_44d1:
	/* 0x44d1: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_44d5:
	/* 0x44d5: mov    ebp,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_44da:
	/* 0x44da: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_44dc:
	/* 0x44dc: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_44df:
	/* 0x44df: cmp    WORD PTR [r12+0x166],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1537598291968ULL);
x86_l_44e9:
	/* 0x44e9: je     4bc2 <generic_sleepable_preload+0x4bc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19394ULL;
	}
	return 17647ULL;
}

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_10(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 17647ULL: goto x86_l_44ef;
	case 17654ULL: goto x86_l_44f6;
	case 17657ULL: goto x86_l_44f9;
	case 17665ULL: goto x86_l_4501;
	case 17668ULL: goto x86_l_4504;
	case 17672ULL: goto x86_l_4508;
	case 17681ULL: goto x86_l_4511;
	case 17683ULL: goto x86_l_4513;
	case 17689ULL: goto x86_l_4519;
	case 17692ULL: goto x86_l_451c;
	case 17694ULL: goto x86_l_451e;
	case 17697ULL: goto x86_l_4521;
	case 17702ULL: goto x86_l_4526;
	case 17707ULL: goto x86_l_452b;
	case 17711ULL: goto x86_l_452f;
	case 17716ULL: goto x86_l_4534;
	case 17718ULL: goto x86_l_4536;
	case 17720ULL: goto x86_l_4538;
	case 17726ULL: goto x86_l_453e;
	case 17736ULL: goto x86_l_4548;
	case 17742ULL: goto x86_l_454e;
	case 17750ULL: goto x86_l_4556;
	case 17754ULL: goto x86_l_455a;
	case 17758ULL: goto x86_l_455e;
	case 17768ULL: goto x86_l_4568;
	case 17770ULL: goto x86_l_456a;
	case 17773ULL: goto x86_l_456d;
	case 17778ULL: goto x86_l_4572;
	case 17783ULL: goto x86_l_4577;
	case 17787ULL: goto x86_l_457b;
	case 17792ULL: goto x86_l_4580;
	case 17794ULL: goto x86_l_4582;
	case 17796ULL: goto x86_l_4584;
	case 17802ULL: goto x86_l_458a;
	case 17812ULL: goto x86_l_4594;
	case 17818ULL: goto x86_l_459a;
	case 17826ULL: goto x86_l_45a2;
	case 17830ULL: goto x86_l_45a6;
	case 17834ULL: goto x86_l_45aa;
	case 17844ULL: goto x86_l_45b4;
	case 17846ULL: goto x86_l_45b6;
	case 17849ULL: goto x86_l_45b9;
	case 17854ULL: goto x86_l_45be;
	case 17859ULL: goto x86_l_45c3;
	case 17863ULL: goto x86_l_45c7;
	case 17868ULL: goto x86_l_45cc;
	case 17870ULL: goto x86_l_45ce;
	case 17872ULL: goto x86_l_45d0;
	case 17878ULL: goto x86_l_45d6;
	case 17888ULL: goto x86_l_45e0;
	case 17894ULL: goto x86_l_45e6;
	case 17902ULL: goto x86_l_45ee;
	case 17906ULL: goto x86_l_45f2;
	case 17910ULL: goto x86_l_45f6;
	case 17920ULL: goto x86_l_4600;
	case 17922ULL: goto x86_l_4602;
	case 17925ULL: goto x86_l_4605;
	case 17930ULL: goto x86_l_460a;
	case 17935ULL: goto x86_l_460f;
	case 17939ULL: goto x86_l_4613;
	case 17944ULL: goto x86_l_4618;
	case 17946ULL: goto x86_l_461a;
	case 17948ULL: goto x86_l_461c;
	case 17954ULL: goto x86_l_4622;
	case 17964ULL: goto x86_l_462c;
	case 17970ULL: goto x86_l_4632;
	case 17978ULL: goto x86_l_463a;
	case 17982ULL: goto x86_l_463e;
	case 17986ULL: goto x86_l_4642;
	case 17996ULL: goto x86_l_464c;
	case 17998ULL: goto x86_l_464e;
	case 18001ULL: goto x86_l_4651;
	case 18006ULL: goto x86_l_4656;
	case 18011ULL: goto x86_l_465b;
	case 18015ULL: goto x86_l_465f;
	case 18020ULL: goto x86_l_4664;
	case 18022ULL: goto x86_l_4666;
	case 18024ULL: goto x86_l_4668;
	case 18030ULL: goto x86_l_466e;
	case 18040ULL: goto x86_l_4678;
	case 18046ULL: goto x86_l_467e;
	case 18054ULL: goto x86_l_4686;
	case 18058ULL: goto x86_l_468a;
	case 18062ULL: goto x86_l_468e;
	case 18072ULL: goto x86_l_4698;
	case 18074ULL: goto x86_l_469a;
	case 18077ULL: goto x86_l_469d;
	case 18082ULL: goto x86_l_46a2;
	case 18087ULL: goto x86_l_46a7;
	case 18091ULL: goto x86_l_46ab;
	case 18096ULL: goto x86_l_46b0;
	case 18098ULL: goto x86_l_46b2;
	case 18100ULL: goto x86_l_46b4;
	case 18106ULL: goto x86_l_46ba;
	case 18116ULL: goto x86_l_46c4;
	case 18122ULL: goto x86_l_46ca;
	case 18130ULL: goto x86_l_46d2;
	case 18134ULL: goto x86_l_46d6;
	case 18138ULL: goto x86_l_46da;
	case 18148ULL: goto x86_l_46e4;
	case 18150ULL: goto x86_l_46e6;
	case 18153ULL: goto x86_l_46e9;
	case 18158ULL: goto x86_l_46ee;
	case 18163ULL: goto x86_l_46f3;
	case 18167ULL: goto x86_l_46f7;
	case 18172ULL: goto x86_l_46fc;
	case 18174ULL: goto x86_l_46fe;
	case 18176ULL: goto x86_l_4700;
	case 18182ULL: goto x86_l_4706;
	case 18192ULL: goto x86_l_4710;
	case 18198ULL: goto x86_l_4716;
	case 18206ULL: goto x86_l_471e;
	case 18210ULL: goto x86_l_4722;
	case 18214ULL: goto x86_l_4726;
	case 18224ULL: goto x86_l_4730;
	case 18226ULL: goto x86_l_4732;
	case 18229ULL: goto x86_l_4735;
	case 18234ULL: goto x86_l_473a;
	case 18239ULL: goto x86_l_473f;
	case 18243ULL: goto x86_l_4743;
	case 18248ULL: goto x86_l_4748;
	case 18250ULL: goto x86_l_474a;
	case 18252ULL: goto x86_l_474c;
	case 18258ULL: goto x86_l_4752;
	case 18268ULL: goto x86_l_475c;
	case 18274ULL: goto x86_l_4762;
	case 18282ULL: goto x86_l_476a;
	case 18286ULL: goto x86_l_476e;
	case 18290ULL: goto x86_l_4772;
	case 18300ULL: goto x86_l_477c;
	case 18302ULL: goto x86_l_477e;
	case 18305ULL: goto x86_l_4781;
	case 18310ULL: goto x86_l_4786;
	case 18315ULL: goto x86_l_478b;
	case 18319ULL: goto x86_l_478f;
	case 18324ULL: goto x86_l_4794;
	case 18326ULL: goto x86_l_4796;
	case 18328ULL: goto x86_l_4798;
	case 18334ULL: goto x86_l_479e;
	case 18339ULL: goto x86_l_47a3;
	case 18349ULL: goto x86_l_47ad;
	case 18355ULL: goto x86_l_47b3;
	case 18363ULL: goto x86_l_47bb;
	case 18367ULL: goto x86_l_47bf;
	case 18371ULL: goto x86_l_47c3;
	case 18381ULL: goto x86_l_47cd;
	case 18387ULL: goto x86_l_47d3;
	case 18390ULL: goto x86_l_47d6;
	case 18395ULL: goto x86_l_47db;
	case 18400ULL: goto x86_l_47e0;
	case 18405ULL: goto x86_l_47e5;
	case 18408ULL: goto x86_l_47e8;
	case 18410ULL: goto x86_l_47ea;
	case 18413ULL: goto x86_l_47ed;
	case 18418ULL: goto x86_l_47f2;
	case 18423ULL: goto x86_l_47f7;
	case 18427ULL: goto x86_l_47fb;
	case 18432ULL: goto x86_l_4800;
	case 18434ULL: goto x86_l_4802;
	case 18436ULL: goto x86_l_4804;
	case 18442ULL: goto x86_l_480a;
	case 18452ULL: goto x86_l_4814;
	case 18458ULL: goto x86_l_481a;
	case 18466ULL: goto x86_l_4822;
	case 18470ULL: goto x86_l_4826;
	case 18474ULL: goto x86_l_482a;
	case 18484ULL: goto x86_l_4834;
	case 18486ULL: goto x86_l_4836;
	case 18489ULL: goto x86_l_4839;
	case 18494ULL: goto x86_l_483e;
	case 18499ULL: goto x86_l_4843;
	case 18503ULL: goto x86_l_4847;
	case 18508ULL: goto x86_l_484c;
	case 18510ULL: goto x86_l_484e;
	case 18512ULL: goto x86_l_4850;
	case 18518ULL: goto x86_l_4856;
	case 18528ULL: goto x86_l_4860;
	case 18534ULL: goto x86_l_4866;
	case 18542ULL: goto x86_l_486e;
	case 18546ULL: goto x86_l_4872;
	case 18550ULL: goto x86_l_4876;
	case 18560ULL: goto x86_l_4880;
	case 18562ULL: goto x86_l_4882;
	case 18565ULL: goto x86_l_4885;
	case 18570ULL: goto x86_l_488a;
	case 18575ULL: goto x86_l_488f;
	case 18579ULL: goto x86_l_4893;
	case 18584ULL: goto x86_l_4898;
	case 18586ULL: goto x86_l_489a;
	case 18588ULL: goto x86_l_489c;
	case 18594ULL: goto x86_l_48a2;
	case 18604ULL: goto x86_l_48ac;
	case 18610ULL: goto x86_l_48b2;
	case 18618ULL: goto x86_l_48ba;
	case 18622ULL: goto x86_l_48be;
	case 18626ULL: goto x86_l_48c2;
	case 18636ULL: goto x86_l_48cc;
	case 18638ULL: goto x86_l_48ce;
	case 18641ULL: goto x86_l_48d1;
	case 18646ULL: goto x86_l_48d6;
	case 18651ULL: goto x86_l_48db;
	case 18655ULL: goto x86_l_48df;
	case 18660ULL: goto x86_l_48e4;
	case 18662ULL: goto x86_l_48e6;
	case 18664ULL: goto x86_l_48e8;
	case 18670ULL: goto x86_l_48ee;
	case 18680ULL: goto x86_l_48f8;
	case 18686ULL: goto x86_l_48fe;
	case 18694ULL: goto x86_l_4906;
	case 18698ULL: goto x86_l_490a;
	case 18702ULL: goto x86_l_490e;
	case 18712ULL: goto x86_l_4918;
	case 18714ULL: goto x86_l_491a;
	case 18717ULL: goto x86_l_491d;
	case 18722ULL: goto x86_l_4922;
	case 18727ULL: goto x86_l_4927;
	case 18731ULL: goto x86_l_492b;
	case 18736ULL: goto x86_l_4930;
	case 18738ULL: goto x86_l_4932;
	case 18740ULL: goto x86_l_4934;
	case 18746ULL: goto x86_l_493a;
	case 18756ULL: goto x86_l_4944;
	case 18762ULL: goto x86_l_494a;
	case 18770ULL: goto x86_l_4952;
	case 18774ULL: goto x86_l_4956;
	case 18778ULL: goto x86_l_495a;
	case 18788ULL: goto x86_l_4964;
	case 18790ULL: goto x86_l_4966;
	case 18793ULL: goto x86_l_4969;
	case 18798ULL: goto x86_l_496e;
	case 18803ULL: goto x86_l_4973;
	case 18807ULL: goto x86_l_4977;
	case 18812ULL: goto x86_l_497c;
	case 18814ULL: goto x86_l_497e;
	case 18816ULL: goto x86_l_4980;
	case 18822ULL: goto x86_l_4986;
	case 18832ULL: goto x86_l_4990;
	case 18838ULL: goto x86_l_4996;
	case 18846ULL: goto x86_l_499e;
	case 18850ULL: goto x86_l_49a2;
	case 18854ULL: goto x86_l_49a6;
	case 18864ULL: goto x86_l_49b0;
	case 18866ULL: goto x86_l_49b2;
	case 18869ULL: goto x86_l_49b5;
	case 18874ULL: goto x86_l_49ba;
	case 18879ULL: goto x86_l_49bf;
	case 18883ULL: goto x86_l_49c3;
	case 18888ULL: goto x86_l_49c8;
	case 18890ULL: goto x86_l_49ca;
	case 18892ULL: goto x86_l_49cc;
	case 18898ULL: goto x86_l_49d2;
	case 18908ULL: goto x86_l_49dc;
	case 18914ULL: goto x86_l_49e2;
	case 18917ULL: goto x86_l_49e5;
	case 18925ULL: goto x86_l_49ed;
	case 18929ULL: goto x86_l_49f1;
	case 18933ULL: goto x86_l_49f5;
	case 18943ULL: goto x86_l_49ff;
	case 18945ULL: goto x86_l_4a01;
	case 18948ULL: goto x86_l_4a04;
	case 18953ULL: goto x86_l_4a09;
	case 18958ULL: goto x86_l_4a0e;
	case 18962ULL: goto x86_l_4a12;
	case 18967ULL: goto x86_l_4a17;
	case 18969ULL: goto x86_l_4a19;
	case 18971ULL: goto x86_l_4a1b;
	case 18977ULL: goto x86_l_4a21;
	case 18982ULL: goto x86_l_4a26;
	case 18992ULL: goto x86_l_4a30;
	case 18995ULL: goto x86_l_4a33;
	case 19001ULL: goto x86_l_4a39;
	case 19009ULL: goto x86_l_4a41;
	case 19013ULL: goto x86_l_4a45;
	case 19017ULL: goto x86_l_4a49;
	case 19027ULL: goto x86_l_4a53;
	case 19029ULL: goto x86_l_4a55;
	case 19032ULL: goto x86_l_4a58;
	case 19037ULL: goto x86_l_4a5d;
	case 19042ULL: goto x86_l_4a62;
	case 19046ULL: goto x86_l_4a66;
	case 19051ULL: goto x86_l_4a6b;
	case 19053ULL: goto x86_l_4a6d;
	case 19055ULL: goto x86_l_4a6f;
	case 19061ULL: goto x86_l_4a75;
	case 19066ULL: goto x86_l_4a7a;
	case 19076ULL: goto x86_l_4a84;
	case 19079ULL: goto x86_l_4a87;
	case 19085ULL: goto x86_l_4a8d;
	case 19093ULL: goto x86_l_4a95;
	case 19097ULL: goto x86_l_4a99;
	case 19101ULL: goto x86_l_4a9d;
	case 19111ULL: goto x86_l_4aa7;
	case 19117ULL: goto x86_l_4aad;
	case 19120ULL: goto x86_l_4ab0;
	case 19125ULL: goto x86_l_4ab5;
	case 19130ULL: goto x86_l_4aba;
	case 19134ULL: goto x86_l_4abe;
	case 19139ULL: goto x86_l_4ac3;
	case 19141ULL: goto x86_l_4ac5;
	case 19143ULL: goto x86_l_4ac7;
	case 19149ULL: goto x86_l_4acd;
	case 19154ULL: goto x86_l_4ad2;
	case 19159ULL: goto x86_l_4ad7;
	case 19164ULL: goto x86_l_4adc;
	case 19169ULL: goto x86_l_4ae1;
	case 19174ULL: goto x86_l_4ae6;
	case 19179ULL: goto x86_l_4aeb;
	case 19184ULL: goto x86_l_4af0;
	case 19186ULL: goto x86_l_4af2;
	case 19191ULL: goto x86_l_4af7;
	case 19196ULL: goto x86_l_4afc;
	case 19201ULL: goto x86_l_4b01;
	case 19203ULL: goto x86_l_4b03;
	case 19208ULL: goto x86_l_4b08;
	case 19213ULL: goto x86_l_4b0d;
	case 19218ULL: goto x86_l_4b12;
	case 19220ULL: goto x86_l_4b14;
	case 19225ULL: goto x86_l_4b19;
	case 19230ULL: goto x86_l_4b1e;
	case 19235ULL: goto x86_l_4b23;
	case 19237ULL: goto x86_l_4b25;
	case 19242ULL: goto x86_l_4b2a;
	case 19247ULL: goto x86_l_4b2f;
	case 19252ULL: goto x86_l_4b34;
	case 19255ULL: goto x86_l_4b37;
	case 19260ULL: goto x86_l_4b3c;
	case 19263ULL: goto x86_l_4b3f;
	case 19268ULL: goto x86_l_4b44;
	case 19273ULL: goto x86_l_4b49;
	case 19278ULL: goto x86_l_4b4e;
	case 19281ULL: goto x86_l_4b51;
	case 19283ULL: goto x86_l_4b53;
	case 19286ULL: goto x86_l_4b56;
	case 19292ULL: goto x86_l_4b5c;
	case 19295ULL: goto x86_l_4b5f;
	case 19299ULL: goto x86_l_4b63;
	case 19304ULL: goto x86_l_4b68;
	case 19306ULL: goto x86_l_4b6a;
	case 19311ULL: goto x86_l_4b6f;
	case 19319ULL: goto x86_l_4b77;
	case 19326ULL: goto x86_l_4b7e;
	case 19331ULL: goto x86_l_4b83;
	case 19336ULL: goto x86_l_4b88;
	case 19338ULL: goto x86_l_4b8a;
	case 19341ULL: goto x86_l_4b8d;
	case 19347ULL: goto x86_l_4b93;
	case 19350ULL: goto x86_l_4b96;
	case 19357ULL: goto x86_l_4b9d;
	case 19359ULL: goto x86_l_4b9f;
	case 19364ULL: goto x86_l_4ba4;
	case 19369ULL: goto x86_l_4ba9;
	case 19372ULL: goto x86_l_4bac;
	case 19375ULL: goto x86_l_4baf;
	case 19377ULL: goto x86_l_4bb1;
	case 19379ULL: goto x86_l_4bb3;
	case 19384ULL: goto x86_l_4bb8;
	case 19386ULL: goto x86_l_4bba;
	case 19391ULL: goto x86_l_4bbf;
	case 19394ULL: goto x86_l_4bc2;
	case 19397ULL: goto x86_l_4bc5;
	case 19403ULL: goto x86_l_4bcb;
	case 19406ULL: goto x86_l_4bce;
	case 19410ULL: goto x86_l_4bd2;
	case 19415ULL: goto x86_l_4bd7;
	case 19417ULL: goto x86_l_4bd9;
	case 19422ULL: goto x86_l_4bde;
	case 19430ULL: goto x86_l_4be6;
	case 19437ULL: goto x86_l_4bed;
	case 19442ULL: goto x86_l_4bf2;
	case 19447ULL: goto x86_l_4bf7;
	case 19449ULL: goto x86_l_4bf9;
	case 19452ULL: goto x86_l_4bfc;
	case 19454ULL: goto x86_l_4bfe;
	case 19457ULL: goto x86_l_4c01;
	case 19464ULL: goto x86_l_4c08;
	case 19466ULL: goto x86_l_4c0a;
	case 19471ULL: goto x86_l_4c0f;
	case 19476ULL: goto x86_l_4c14;
	case 19479ULL: goto x86_l_4c17;
	case 19482ULL: goto x86_l_4c1a;
	case 19484ULL: goto x86_l_4c1c;
	case 19486ULL: goto x86_l_4c1e;
	case 19491ULL: goto x86_l_4c23;
	case 19494ULL: goto x86_l_4c26;
	default: return 0xffffffffffffffffULL;
	}
x86_l_44ef:
	/* 0x44ef: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_44f6:
	/* 0x44f6: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_44f9:
	/* 0x44f9: mov    eax,DWORD PTR [r12+0x160] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_4501:
	/* 0x4501: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4504:
	/* 0x4504: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4508:
	/* 0x4508: movzx  eax,WORD PTR [r12+0x164] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 356ULL);
x86_l_4511:
	/* 0x4511: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_4513:
	/* 0x4513: je     47e5 <generic_sleepable_preload+0x47e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_47e5;
	}
x86_l_4519:
	/* 0x4519: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_451c:
	/* 0x451c: je     453e <generic_sleepable_preload+0x453e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_453e;
	}
x86_l_451e:
	/* 0x451e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4521:
	/* 0x4521: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4526:
	/* 0x4526: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_452b:
	/* 0x452b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_452f:
	/* 0x452f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4534:
	/* 0x4534: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4536:
	/* 0x4536: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4538:
	/* 0x4538: js     4ad7 <generic_sleepable_preload+0x4ad7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4ad7;
	}
x86_l_453e:
	/* 0x453e: cmp    WORD PTR [r12+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_4548:
	/* 0x4548: je     4bc2 <generic_sleepable_preload+0x4bc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc2;
	}
x86_l_454e:
	/* 0x454e: mov    ecx,DWORD PTR [r12+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_4556:
	/* 0x4556: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_455a:
	/* 0x455a: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_455e:
	/* 0x455e: cmp    WORD PTR [r12+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_4568:
	/* 0x4568: je     458a <generic_sleepable_preload+0x458a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_458a;
	}
x86_l_456a:
	/* 0x456a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_456d:
	/* 0x456d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4572:
	/* 0x4572: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4577:
	/* 0x4577: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_457b:
	/* 0x457b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4580:
	/* 0x4580: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4582:
	/* 0x4582: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4584:
	/* 0x4584: js     4ae1 <generic_sleepable_preload+0x4ae1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4ae1;
	}
x86_l_458a:
	/* 0x458a: cmp    WORD PTR [r12+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_4594:
	/* 0x4594: je     4bc2 <generic_sleepable_preload+0x4bc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc2;
	}
x86_l_459a:
	/* 0x459a: mov    ecx,DWORD PTR [r12+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_45a2:
	/* 0x45a2: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_45a6:
	/* 0x45a6: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_45aa:
	/* 0x45aa: cmp    WORD PTR [r12+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_45b4:
	/* 0x45b4: je     45d6 <generic_sleepable_preload+0x45d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_45d6;
	}
x86_l_45b6:
	/* 0x45b6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_45b9:
	/* 0x45b9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_45be:
	/* 0x45be: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_45c3:
	/* 0x45c3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_45c7:
	/* 0x45c7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_45cc:
	/* 0x45cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45ce:
	/* 0x45ce: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_45d0:
	/* 0x45d0: js     4af2 <generic_sleepable_preload+0x4af2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4af2;
	}
x86_l_45d6:
	/* 0x45d6: cmp    WORD PTR [r12+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_45e0:
	/* 0x45e0: je     4bc2 <generic_sleepable_preload+0x4bc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc2;
	}
x86_l_45e6:
	/* 0x45e6: mov    ecx,DWORD PTR [r12+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_45ee:
	/* 0x45ee: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_45f2:
	/* 0x45f2: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_45f6:
	/* 0x45f6: cmp    WORD PTR [r12+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_4600:
	/* 0x4600: je     4622 <generic_sleepable_preload+0x4622> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4622;
	}
x86_l_4602:
	/* 0x4602: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4605:
	/* 0x4605: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_460a:
	/* 0x460a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_460f:
	/* 0x460f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4613:
	/* 0x4613: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4618:
	/* 0x4618: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_461a:
	/* 0x461a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_461c:
	/* 0x461c: js     4b03 <generic_sleepable_preload+0x4b03> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4b03;
	}
x86_l_4622:
	/* 0x4622: cmp    WORD PTR [r12+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_462c:
	/* 0x462c: je     4bc2 <generic_sleepable_preload+0x4bc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc2;
	}
x86_l_4632:
	/* 0x4632: mov    ecx,DWORD PTR [r12+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_463a:
	/* 0x463a: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_463e:
	/* 0x463e: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4642:
	/* 0x4642: cmp    WORD PTR [r12+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_464c:
	/* 0x464c: je     466e <generic_sleepable_preload+0x466e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_466e;
	}
x86_l_464e:
	/* 0x464e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4651:
	/* 0x4651: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4656:
	/* 0x4656: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_465b:
	/* 0x465b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_465f:
	/* 0x465f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4664:
	/* 0x4664: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4666:
	/* 0x4666: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4668:
	/* 0x4668: js     4b14 <generic_sleepable_preload+0x4b14> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4b14;
	}
x86_l_466e:
	/* 0x466e: cmp    WORD PTR [r12+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_4678:
	/* 0x4678: je     4bc2 <generic_sleepable_preload+0x4bc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc2;
	}
x86_l_467e:
	/* 0x467e: mov    ecx,DWORD PTR [r12+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_4686:
	/* 0x4686: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_468a:
	/* 0x468a: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_468e:
	/* 0x468e: cmp    WORD PTR [r12+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_4698:
	/* 0x4698: je     46ba <generic_sleepable_preload+0x46ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_46ba;
	}
x86_l_469a:
	/* 0x469a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_469d:
	/* 0x469d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_46a2:
	/* 0x46a2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_46a7:
	/* 0x46a7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_46ab:
	/* 0x46ab: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_46b0:
	/* 0x46b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46b2:
	/* 0x46b2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_46b4:
	/* 0x46b4: js     4b25 <generic_sleepable_preload+0x4b25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4b25;
	}
x86_l_46ba:
	/* 0x46ba: cmp    WORD PTR [r12+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_46c4:
	/* 0x46c4: je     4bc2 <generic_sleepable_preload+0x4bc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc2;
	}
x86_l_46ca:
	/* 0x46ca: mov    ecx,DWORD PTR [r12+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_46d2:
	/* 0x46d2: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_46d6:
	/* 0x46d6: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_46da:
	/* 0x46da: cmp    WORD PTR [r12+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_46e4:
	/* 0x46e4: je     4706 <generic_sleepable_preload+0x4706> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4706;
	}
x86_l_46e6:
	/* 0x46e6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_46e9:
	/* 0x46e9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_46ee:
	/* 0x46ee: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_46f3:
	/* 0x46f3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_46f7:
	/* 0x46f7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_46fc:
	/* 0x46fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46fe:
	/* 0x46fe: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4700:
	/* 0x4700: js     4bba <generic_sleepable_preload+0x4bba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4bba;
	}
x86_l_4706:
	/* 0x4706: cmp    WORD PTR [r12+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_4710:
	/* 0x4710: je     4bc2 <generic_sleepable_preload+0x4bc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc2;
	}
x86_l_4716:
	/* 0x4716: mov    ecx,DWORD PTR [r12+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_471e:
	/* 0x471e: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4722:
	/* 0x4722: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4726:
	/* 0x4726: cmp    WORD PTR [r12+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_4730:
	/* 0x4730: je     4752 <generic_sleepable_preload+0x4752> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4752;
	}
x86_l_4732:
	/* 0x4732: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4735:
	/* 0x4735: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_473a:
	/* 0x473a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_473f:
	/* 0x473f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4743:
	/* 0x4743: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4748:
	/* 0x4748: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_474a:
	/* 0x474a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_474c:
	/* 0x474c: js     5c1d <generic_sleepable_preload+0x5c1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23581ULL;
	}
x86_l_4752:
	/* 0x4752: cmp    WORD PTR [r12+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_475c:
	/* 0x475c: je     4bc2 <generic_sleepable_preload+0x4bc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc2;
	}
x86_l_4762:
	/* 0x4762: mov    ecx,DWORD PTR [r12+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_476a:
	/* 0x476a: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_476e:
	/* 0x476e: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4772:
	/* 0x4772: cmp    WORD PTR [r12+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_477c:
	/* 0x477c: je     479e <generic_sleepable_preload+0x479e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_479e;
	}
x86_l_477e:
	/* 0x477e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4781:
	/* 0x4781: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4786:
	/* 0x4786: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_478b:
	/* 0x478b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_478f:
	/* 0x478f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4794:
	/* 0x4794: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4796:
	/* 0x4796: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4798:
	/* 0x4798: js     5d26 <generic_sleepable_preload+0x5d26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23846ULL;
	}
x86_l_479e:
	/* 0x479e: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_47a3:
	/* 0x47a3: cmp    WORD PTR [r12+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_47ad:
	/* 0x47ad: je     4bc2 <generic_sleepable_preload+0x4bc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc2;
	}
x86_l_47b3:
	/* 0x47b3: mov    ecx,DWORD PTR [r12+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_47bb:
	/* 0x47bb: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_47bf:
	/* 0x47bf: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_47c3:
	/* 0x47c3: cmp    WORD PTR [r12+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_47cd:
	/* 0x47cd: je     4bc2 <generic_sleepable_preload+0x4bc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc2;
	}
x86_l_47d3:
	/* 0x47d3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_47d6:
	/* 0x47d6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_47db:
	/* 0x47db: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_47e0:
	/* 0x47e0: jmp    4aba <generic_sleepable_preload+0x4aba> */
	goto x86_l_4aba;
x86_l_47e5:
	/* 0x47e5: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_47e8:
	/* 0x47e8: je     480a <generic_sleepable_preload+0x480a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_480a;
	}
x86_l_47ea:
	/* 0x47ea: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_47ed:
	/* 0x47ed: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_47f2:
	/* 0x47f2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_47f7:
	/* 0x47f7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_47fb:
	/* 0x47fb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4800:
	/* 0x4800: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4802:
	/* 0x4802: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4804:
	/* 0x4804: js     4ad7 <generic_sleepable_preload+0x4ad7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4ad7;
	}
x86_l_480a:
	/* 0x480a: cmp    WORD PTR [r12+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_4814:
	/* 0x4814: je     4bc2 <generic_sleepable_preload+0x4bc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc2;
	}
x86_l_481a:
	/* 0x481a: mov    ecx,DWORD PTR [r12+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_4822:
	/* 0x4822: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4826:
	/* 0x4826: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_482a:
	/* 0x482a: cmp    WORD PTR [r12+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_4834:
	/* 0x4834: je     4856 <generic_sleepable_preload+0x4856> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4856;
	}
x86_l_4836:
	/* 0x4836: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4839:
	/* 0x4839: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_483e:
	/* 0x483e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4843:
	/* 0x4843: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4847:
	/* 0x4847: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_484c:
	/* 0x484c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_484e:
	/* 0x484e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4850:
	/* 0x4850: js     4ae1 <generic_sleepable_preload+0x4ae1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4ae1;
	}
x86_l_4856:
	/* 0x4856: cmp    WORD PTR [r12+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_4860:
	/* 0x4860: je     4bc2 <generic_sleepable_preload+0x4bc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc2;
	}
x86_l_4866:
	/* 0x4866: mov    ecx,DWORD PTR [r12+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_486e:
	/* 0x486e: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4872:
	/* 0x4872: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4876:
	/* 0x4876: cmp    WORD PTR [r12+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_4880:
	/* 0x4880: je     48a2 <generic_sleepable_preload+0x48a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_48a2;
	}
x86_l_4882:
	/* 0x4882: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4885:
	/* 0x4885: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_488a:
	/* 0x488a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_488f:
	/* 0x488f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4893:
	/* 0x4893: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4898:
	/* 0x4898: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_489a:
	/* 0x489a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_489c:
	/* 0x489c: js     4af2 <generic_sleepable_preload+0x4af2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4af2;
	}
x86_l_48a2:
	/* 0x48a2: cmp    WORD PTR [r12+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_48ac:
	/* 0x48ac: je     4bc2 <generic_sleepable_preload+0x4bc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc2;
	}
x86_l_48b2:
	/* 0x48b2: mov    ecx,DWORD PTR [r12+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_48ba:
	/* 0x48ba: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_48be:
	/* 0x48be: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_48c2:
	/* 0x48c2: cmp    WORD PTR [r12+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_48cc:
	/* 0x48cc: je     48ee <generic_sleepable_preload+0x48ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_48ee;
	}
x86_l_48ce:
	/* 0x48ce: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_48d1:
	/* 0x48d1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_48d6:
	/* 0x48d6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_48db:
	/* 0x48db: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_48df:
	/* 0x48df: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_48e4:
	/* 0x48e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48e6:
	/* 0x48e6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_48e8:
	/* 0x48e8: js     4b03 <generic_sleepable_preload+0x4b03> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4b03;
	}
x86_l_48ee:
	/* 0x48ee: cmp    WORD PTR [r12+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_48f8:
	/* 0x48f8: je     4bc2 <generic_sleepable_preload+0x4bc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc2;
	}
x86_l_48fe:
	/* 0x48fe: mov    ecx,DWORD PTR [r12+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_4906:
	/* 0x4906: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_490a:
	/* 0x490a: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_490e:
	/* 0x490e: cmp    WORD PTR [r12+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_4918:
	/* 0x4918: je     493a <generic_sleepable_preload+0x493a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_493a;
	}
x86_l_491a:
	/* 0x491a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_491d:
	/* 0x491d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4922:
	/* 0x4922: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4927:
	/* 0x4927: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_492b:
	/* 0x492b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4930:
	/* 0x4930: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4932:
	/* 0x4932: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4934:
	/* 0x4934: js     4b14 <generic_sleepable_preload+0x4b14> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4b14;
	}
x86_l_493a:
	/* 0x493a: cmp    WORD PTR [r12+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_4944:
	/* 0x4944: je     4bc2 <generic_sleepable_preload+0x4bc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc2;
	}
x86_l_494a:
	/* 0x494a: mov    ecx,DWORD PTR [r12+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_4952:
	/* 0x4952: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4956:
	/* 0x4956: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_495a:
	/* 0x495a: cmp    WORD PTR [r12+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_4964:
	/* 0x4964: je     4986 <generic_sleepable_preload+0x4986> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4986;
	}
x86_l_4966:
	/* 0x4966: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4969:
	/* 0x4969: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_496e:
	/* 0x496e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4973:
	/* 0x4973: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4977:
	/* 0x4977: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_497c:
	/* 0x497c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_497e:
	/* 0x497e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4980:
	/* 0x4980: js     4b25 <generic_sleepable_preload+0x4b25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4b25;
	}
x86_l_4986:
	/* 0x4986: cmp    WORD PTR [r12+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_4990:
	/* 0x4990: je     4bc2 <generic_sleepable_preload+0x4bc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc2;
	}
x86_l_4996:
	/* 0x4996: mov    ecx,DWORD PTR [r12+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_499e:
	/* 0x499e: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_49a2:
	/* 0x49a2: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49a6:
	/* 0x49a6: cmp    WORD PTR [r12+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_49b0:
	/* 0x49b0: je     49d2 <generic_sleepable_preload+0x49d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_49d2;
	}
x86_l_49b2:
	/* 0x49b2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_49b5:
	/* 0x49b5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_49ba:
	/* 0x49ba: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_49bf:
	/* 0x49bf: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49c3:
	/* 0x49c3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_49c8:
	/* 0x49c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49ca:
	/* 0x49ca: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_49cc:
	/* 0x49cc: js     4bba <generic_sleepable_preload+0x4bba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4bba;
	}
x86_l_49d2:
	/* 0x49d2: cmp    WORD PTR [r12+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_49dc:
	/* 0x49dc: je     4bc2 <generic_sleepable_preload+0x4bc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc2;
	}
x86_l_49e2:
	/* 0x49e2: mov    r15,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R14, X86_WIDTH_64);
x86_l_49e5:
	/* 0x49e5: mov    ecx,DWORD PTR [r12+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_49ed:
	/* 0x49ed: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_49f1:
	/* 0x49f1: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49f5:
	/* 0x49f5: cmp    WORD PTR [r12+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_49ff:
	/* 0x49ff: je     4a21 <generic_sleepable_preload+0x4a21> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4a21;
	}
x86_l_4a01:
	/* 0x4a01: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4a04:
	/* 0x4a04: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4a09:
	/* 0x4a09: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4a0e:
	/* 0x4a0e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a12:
	/* 0x4a12: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a17:
	/* 0x4a17: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a19:
	/* 0x4a19: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4a1b:
	/* 0x4a1b: js     5c9b <generic_sleepable_preload+0x5c9b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23707ULL;
	}
x86_l_4a21:
	/* 0x4a21: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a26:
	/* 0x4a26: cmp    WORD PTR [r12+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_4a30:
	/* 0x4a30: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_4a33:
	/* 0x4a33: je     4bc2 <generic_sleepable_preload+0x4bc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc2;
	}
x86_l_4a39:
	/* 0x4a39: mov    ecx,DWORD PTR [r12+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_4a41:
	/* 0x4a41: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4a45:
	/* 0x4a45: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a49:
	/* 0x4a49: cmp    WORD PTR [r12+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_4a53:
	/* 0x4a53: je     4a75 <generic_sleepable_preload+0x4a75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4a75;
	}
x86_l_4a55:
	/* 0x4a55: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4a58:
	/* 0x4a58: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4a5d:
	/* 0x4a5d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4a62:
	/* 0x4a62: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a66:
	/* 0x4a66: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a6b:
	/* 0x4a6b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a6d:
	/* 0x4a6d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4a6f:
	/* 0x4a6f: js     5dcb <generic_sleepable_preload+0x5dcb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24011ULL;
	}
x86_l_4a75:
	/* 0x4a75: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a7a:
	/* 0x4a7a: cmp    WORD PTR [r12+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_4a84:
	/* 0x4a84: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_4a87:
	/* 0x4a87: je     4bc2 <generic_sleepable_preload+0x4bc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc2;
	}
x86_l_4a8d:
	/* 0x4a8d: mov    ecx,DWORD PTR [r12+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_4a95:
	/* 0x4a95: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4a99:
	/* 0x4a99: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a9d:
	/* 0x4a9d: cmp    WORD PTR [r12+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_4aa7:
	/* 0x4aa7: je     4bc2 <generic_sleepable_preload+0x4bc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc2;
	}
x86_l_4aad:
	/* 0x4aad: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4ab0:
	/* 0x4ab0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4ab5:
	/* 0x4ab5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4aba:
	/* 0x4aba: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4abe:
	/* 0x4abe: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4ac3:
	/* 0x4ac3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ac5:
	/* 0x4ac5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4ac7:
	/* 0x4ac7: jns    4bc2 <generic_sleepable_preload+0x4bc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_4bc2;
	}
x86_l_4acd:
	/* 0x4acd: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_4ad2:
	/* 0x4ad2: jmp    4bbf <generic_sleepable_preload+0x4bbf> */
	goto x86_l_4bbf;
x86_l_4ad7:
	/* 0x4ad7: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_4adc:
	/* 0x4adc: jmp    4bbf <generic_sleepable_preload+0x4bbf> */
	goto x86_l_4bbf;
x86_l_4ae1:
	/* 0x4ae1: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_4ae6:
	/* 0x4ae6: jmp    4bbf <generic_sleepable_preload+0x4bbf> */
	goto x86_l_4bbf;
x86_l_4aeb:
	/* 0x4aeb: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_4af0:
	/* 0x4af0: jmp    4b34 <generic_sleepable_preload+0x4b34> */
	goto x86_l_4b34;
x86_l_4af2:
	/* 0x4af2: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_4af7:
	/* 0x4af7: jmp    4bbf <generic_sleepable_preload+0x4bbf> */
	goto x86_l_4bbf;
x86_l_4afc:
	/* 0x4afc: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_4b01:
	/* 0x4b01: jmp    4b34 <generic_sleepable_preload+0x4b34> */
	goto x86_l_4b34;
x86_l_4b03:
	/* 0x4b03: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_4b08:
	/* 0x4b08: jmp    4bbf <generic_sleepable_preload+0x4bbf> */
	goto x86_l_4bbf;
x86_l_4b0d:
	/* 0x4b0d: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_4b12:
	/* 0x4b12: jmp    4b34 <generic_sleepable_preload+0x4b34> */
	goto x86_l_4b34;
x86_l_4b14:
	/* 0x4b14: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_4b19:
	/* 0x4b19: jmp    4bbf <generic_sleepable_preload+0x4bbf> */
	goto x86_l_4bbf;
x86_l_4b1e:
	/* 0x4b1e: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_4b23:
	/* 0x4b23: jmp    4b34 <generic_sleepable_preload+0x4b34> */
	goto x86_l_4b34;
x86_l_4b25:
	/* 0x4b25: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_4b2a:
	/* 0x4b2a: jmp    4bbf <generic_sleepable_preload+0x4bbf> */
	goto x86_l_4bbf;
x86_l_4b2f:
	/* 0x4b2f: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_4b34:
	/* 0x4b34: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4b37:
	/* 0x4b37: mov    ebp,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b3c:
	/* 0x4b3c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4b3f:
	/* 0x4b3f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4b44:
	/* 0x4b44: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4b49:
	/* 0x4b49: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b4e:
	/* 0x4b4e: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_4b51:
	/* 0x4b51: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b53:
	/* 0x4b53: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_4b56:
	/* 0x4b56: jne    4c67 <generic_sleepable_preload+0x4c67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 19559ULL;
	}
x86_l_4b5c:
	/* 0x4b5c: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_4b5f:
	/* 0x4b5f: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4b63:
	/* 0x4b63: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_4b68:
	/* 0x4b68: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b6a:
	/* 0x4b6a: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4b6f:
	/* 0x4b6f: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_4b77:
	/* 0x4b77: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_4b7e:
	/* 0x4b7e: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_4b83:
	/* 0x4b83: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4b88:
	/* 0x4b88: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b8a:
	/* 0x4b8a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4b8d:
	/* 0x4b8d: je     4c64 <generic_sleepable_preload+0x4c64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19556ULL;
	}
x86_l_4b93:
	/* 0x4b93: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_4b96:
	/* 0x4b96: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_4b9d:
	/* 0x4b9d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4b9f:
	/* 0x4b9f: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4ba4:
	/* 0x4ba4: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4ba9:
	/* 0x4ba9: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_4bac:
	/* 0x4bac: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_4baf:
	/* 0x4baf: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4bb1:
	/* 0x4bb1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4bb3:
	/* 0x4bb3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4bb8:
	/* 0x4bb8: jmp    4c23 <generic_sleepable_preload+0x4c23> */
	goto x86_l_4c23;
x86_l_4bba:
	/* 0x4bba: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_4bbf:
	/* 0x4bbf: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4bc2:
	/* 0x4bc2: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_4bc5:
	/* 0x4bc5: jne    4c67 <generic_sleepable_preload+0x4c67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 19559ULL;
	}
x86_l_4bcb:
	/* 0x4bcb: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_4bce:
	/* 0x4bce: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4bd2:
	/* 0x4bd2: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_4bd7:
	/* 0x4bd7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4bd9:
	/* 0x4bd9: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4bde:
	/* 0x4bde: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_4be6:
	/* 0x4be6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_4bed:
	/* 0x4bed: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_4bf2:
	/* 0x4bf2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4bf7:
	/* 0x4bf7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4bf9:
	/* 0x4bf9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4bfc:
	/* 0x4bfc: je     4c64 <generic_sleepable_preload+0x4c64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19556ULL;
	}
x86_l_4bfe:
	/* 0x4bfe: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_4c01:
	/* 0x4c01: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_4c08:
	/* 0x4c08: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4c0a:
	/* 0x4c0a: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4c0f:
	/* 0x4c0f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4c14:
	/* 0x4c14: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_4c17:
	/* 0x4c17: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_4c1a:
	/* 0x4c1a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4c1c:
	/* 0x4c1c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c1e:
	/* 0x4c1e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4c23:
	/* 0x4c23: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_4c26:
	/* 0x4c26: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
	return 19497ULL;
}

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_11(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 19497ULL: goto x86_l_4c29;
	case 19502ULL: goto x86_l_4c2e;
	case 19504ULL: goto x86_l_4c30;
	case 19507ULL: goto x86_l_4c33;
	case 19509ULL: goto x86_l_4c35;
	case 19512ULL: goto x86_l_4c38;
	case 19514ULL: goto x86_l_4c3a;
	case 19517ULL: goto x86_l_4c3d;
	case 19521ULL: goto x86_l_4c41;
	case 19526ULL: goto x86_l_4c46;
	case 19529ULL: goto x86_l_4c49;
	case 19531ULL: goto x86_l_4c4b;
	case 19534ULL: goto x86_l_4c4e;
	case 19539ULL: goto x86_l_4c53;
	case 19541ULL: goto x86_l_4c55;
	case 19544ULL: goto x86_l_4c58;
	case 19546ULL: goto x86_l_4c5a;
	case 19551ULL: goto x86_l_4c5f;
	case 19554ULL: goto x86_l_4c62;
	case 19556ULL: goto x86_l_4c64;
	case 19559ULL: goto x86_l_4c67;
	case 19564ULL: goto x86_l_4c6c;
	case 19569ULL: goto x86_l_4c71;
	case 19571ULL: goto x86_l_4c73;
	case 19573ULL: goto x86_l_4c75;
	case 19580ULL: goto x86_l_4c7c;
	case 19582ULL: goto x86_l_4c7e;
	case 19583ULL: goto x86_l_4c7f;
	case 19588ULL: goto x86_l_4c84;
	case 19590ULL: goto x86_l_4c86;
	case 19592ULL: goto x86_l_4c88;
	case 19597ULL: goto x86_l_4c8d;
	case 19600ULL: goto x86_l_4c90;
	case 19606ULL: goto x86_l_4c96;
	case 19609ULL: goto x86_l_4c99;
	case 19615ULL: goto x86_l_4c9f;
	case 19618ULL: goto x86_l_4ca2;
	case 19624ULL: goto x86_l_4ca8;
	case 19627ULL: goto x86_l_4cab;
	case 19633ULL: goto x86_l_4cb1;
	case 19638ULL: goto x86_l_4cb6;
	case 19643ULL: goto x86_l_4cbb;
	case 19652ULL: goto x86_l_4cc4;
	case 19661ULL: goto x86_l_4ccd;
	case 19667ULL: goto x86_l_4cd3;
	case 19669ULL: goto x86_l_4cd5;
	case 19672ULL: goto x86_l_4cd8;
	case 19674ULL: goto x86_l_4cda;
	case 19677ULL: goto x86_l_4cdd;
	case 19679ULL: goto x86_l_4cdf;
	case 19682ULL: goto x86_l_4ce2;
	case 19688ULL: goto x86_l_4ce8;
	case 19693ULL: goto x86_l_4ced;
	case 19696ULL: goto x86_l_4cf0;
	case 19702ULL: goto x86_l_4cf6;
	case 19707ULL: goto x86_l_4cfb;
	case 19710ULL: goto x86_l_4cfe;
	case 19716ULL: goto x86_l_4d04;
	case 19721ULL: goto x86_l_4d09;
	case 19724ULL: goto x86_l_4d0c;
	case 19730ULL: goto x86_l_4d12;
	case 19735ULL: goto x86_l_4d17;
	case 19738ULL: goto x86_l_4d1a;
	case 19740ULL: goto x86_l_4d1c;
	case 19743ULL: goto x86_l_4d1f;
	case 19749ULL: goto x86_l_4d25;
	case 19751ULL: goto x86_l_4d27;
	case 19757ULL: goto x86_l_4d2d;
	case 19760ULL: goto x86_l_4d30;
	case 19763ULL: goto x86_l_4d33;
	case 19769ULL: goto x86_l_4d39;
	case 19774ULL: goto x86_l_4d3e;
	case 19776ULL: goto x86_l_4d40;
	case 19778ULL: goto x86_l_4d42;
	case 19781ULL: goto x86_l_4d45;
	case 19783ULL: goto x86_l_4d47;
	case 19788ULL: goto x86_l_4d4c;
	case 19790ULL: goto x86_l_4d4e;
	case 19793ULL: goto x86_l_4d51;
	case 19799ULL: goto x86_l_4d57;
	case 19807ULL: goto x86_l_4d5f;
	case 19810ULL: goto x86_l_4d62;
	case 19816ULL: goto x86_l_4d68;
	case 19821ULL: goto x86_l_4d6d;
	case 19824ULL: goto x86_l_4d70;
	case 19830ULL: goto x86_l_4d76;
	case 19835ULL: goto x86_l_4d7b;
	case 19838ULL: goto x86_l_4d7e;
	case 19844ULL: goto x86_l_4d84;
	case 19852ULL: goto x86_l_4d8c;
	case 19855ULL: goto x86_l_4d8f;
	case 19861ULL: goto x86_l_4d95;
	case 19866ULL: goto x86_l_4d9a;
	case 19869ULL: goto x86_l_4d9d;
	case 19875ULL: goto x86_l_4da3;
	case 19880ULL: goto x86_l_4da8;
	case 19885ULL: goto x86_l_4dad;
	case 19887ULL: goto x86_l_4daf;
	case 19892ULL: goto x86_l_4db4;
	case 19894ULL: goto x86_l_4db6;
	case 19899ULL: goto x86_l_4dbb;
	case 19902ULL: goto x86_l_4dbe;
	case 19906ULL: goto x86_l_4dc2;
	case 19909ULL: goto x86_l_4dc5;
	case 19912ULL: goto x86_l_4dc8;
	case 19917ULL: goto x86_l_4dcd;
	case 19925ULL: goto x86_l_4dd5;
	case 19931ULL: goto x86_l_4ddb;
	case 19938ULL: goto x86_l_4de2;
	case 19941ULL: goto x86_l_4de5;
	case 19947ULL: goto x86_l_4deb;
	case 19950ULL: goto x86_l_4dee;
	case 19954ULL: goto x86_l_4df2;
	case 19961ULL: goto x86_l_4df9;
	case 19963ULL: goto x86_l_4dfb;
	case 19969ULL: goto x86_l_4e01;
	case 19972ULL: goto x86_l_4e04;
	case 19974ULL: goto x86_l_4e06;
	case 19977ULL: goto x86_l_4e09;
	case 19982ULL: goto x86_l_4e0e;
	case 19987ULL: goto x86_l_4e13;
	case 19991ULL: goto x86_l_4e17;
	case 19996ULL: goto x86_l_4e1c;
	case 19998ULL: goto x86_l_4e1e;
	case 20000ULL: goto x86_l_4e20;
	case 20006ULL: goto x86_l_4e26;
	case 20011ULL: goto x86_l_4e2b;
	case 20019ULL: goto x86_l_4e33;
	case 20025ULL: goto x86_l_4e39;
	case 20031ULL: goto x86_l_4e3f;
	case 20035ULL: goto x86_l_4e43;
	case 20039ULL: goto x86_l_4e47;
	case 20047ULL: goto x86_l_4e4f;
	case 20049ULL: goto x86_l_4e51;
	case 20052ULL: goto x86_l_4e54;
	case 20057ULL: goto x86_l_4e59;
	case 20062ULL: goto x86_l_4e5e;
	case 20066ULL: goto x86_l_4e62;
	case 20071ULL: goto x86_l_4e67;
	case 20073ULL: goto x86_l_4e69;
	case 20075ULL: goto x86_l_4e6b;
	case 20081ULL: goto x86_l_4e71;
	case 20086ULL: goto x86_l_4e76;
	case 20094ULL: goto x86_l_4e7e;
	case 20100ULL: goto x86_l_4e84;
	case 20106ULL: goto x86_l_4e8a;
	case 20110ULL: goto x86_l_4e8e;
	case 20114ULL: goto x86_l_4e92;
	case 20122ULL: goto x86_l_4e9a;
	case 20124ULL: goto x86_l_4e9c;
	case 20127ULL: goto x86_l_4e9f;
	case 20132ULL: goto x86_l_4ea4;
	case 20137ULL: goto x86_l_4ea9;
	case 20141ULL: goto x86_l_4ead;
	case 20146ULL: goto x86_l_4eb2;
	case 20148ULL: goto x86_l_4eb4;
	case 20150ULL: goto x86_l_4eb6;
	case 20156ULL: goto x86_l_4ebc;
	case 20161ULL: goto x86_l_4ec1;
	case 20169ULL: goto x86_l_4ec9;
	case 20175ULL: goto x86_l_4ecf;
	case 20181ULL: goto x86_l_4ed5;
	case 20185ULL: goto x86_l_4ed9;
	case 20189ULL: goto x86_l_4edd;
	case 20197ULL: goto x86_l_4ee5;
	case 20199ULL: goto x86_l_4ee7;
	case 20202ULL: goto x86_l_4eea;
	case 20207ULL: goto x86_l_4eef;
	case 20212ULL: goto x86_l_4ef4;
	case 20216ULL: goto x86_l_4ef8;
	case 20221ULL: goto x86_l_4efd;
	case 20223ULL: goto x86_l_4eff;
	case 20225ULL: goto x86_l_4f01;
	case 20231ULL: goto x86_l_4f07;
	case 20236ULL: goto x86_l_4f0c;
	case 20244ULL: goto x86_l_4f14;
	case 20250ULL: goto x86_l_4f1a;
	case 20256ULL: goto x86_l_4f20;
	case 20260ULL: goto x86_l_4f24;
	case 20264ULL: goto x86_l_4f28;
	case 20272ULL: goto x86_l_4f30;
	case 20274ULL: goto x86_l_4f32;
	case 20277ULL: goto x86_l_4f35;
	case 20282ULL: goto x86_l_4f3a;
	case 20287ULL: goto x86_l_4f3f;
	case 20291ULL: goto x86_l_4f43;
	case 20296ULL: goto x86_l_4f48;
	case 20298ULL: goto x86_l_4f4a;
	case 20300ULL: goto x86_l_4f4c;
	case 20306ULL: goto x86_l_4f52;
	case 20311ULL: goto x86_l_4f57;
	case 20319ULL: goto x86_l_4f5f;
	case 20325ULL: goto x86_l_4f65;
	case 20331ULL: goto x86_l_4f6b;
	case 20335ULL: goto x86_l_4f6f;
	case 20339ULL: goto x86_l_4f73;
	case 20347ULL: goto x86_l_4f7b;
	case 20349ULL: goto x86_l_4f7d;
	case 20352ULL: goto x86_l_4f80;
	case 20357ULL: goto x86_l_4f85;
	case 20362ULL: goto x86_l_4f8a;
	case 20366ULL: goto x86_l_4f8e;
	case 20371ULL: goto x86_l_4f93;
	case 20373ULL: goto x86_l_4f95;
	case 20375ULL: goto x86_l_4f97;
	case 20381ULL: goto x86_l_4f9d;
	case 20386ULL: goto x86_l_4fa2;
	case 20394ULL: goto x86_l_4faa;
	case 20400ULL: goto x86_l_4fb0;
	case 20406ULL: goto x86_l_4fb6;
	case 20410ULL: goto x86_l_4fba;
	case 20414ULL: goto x86_l_4fbe;
	case 20422ULL: goto x86_l_4fc6;
	case 20424ULL: goto x86_l_4fc8;
	case 20427ULL: goto x86_l_4fcb;
	case 20432ULL: goto x86_l_4fd0;
	case 20437ULL: goto x86_l_4fd5;
	case 20441ULL: goto x86_l_4fd9;
	case 20446ULL: goto x86_l_4fde;
	case 20448ULL: goto x86_l_4fe0;
	case 20450ULL: goto x86_l_4fe2;
	case 20456ULL: goto x86_l_4fe8;
	case 20461ULL: goto x86_l_4fed;
	case 20469ULL: goto x86_l_4ff5;
	case 20475ULL: goto x86_l_4ffb;
	case 20481ULL: goto x86_l_5001;
	case 20485ULL: goto x86_l_5005;
	case 20489ULL: goto x86_l_5009;
	case 20497ULL: goto x86_l_5011;
	case 20499ULL: goto x86_l_5013;
	case 20502ULL: goto x86_l_5016;
	case 20507ULL: goto x86_l_501b;
	case 20512ULL: goto x86_l_5020;
	case 20516ULL: goto x86_l_5024;
	case 20521ULL: goto x86_l_5029;
	case 20523ULL: goto x86_l_502b;
	case 20525ULL: goto x86_l_502d;
	case 20531ULL: goto x86_l_5033;
	case 20536ULL: goto x86_l_5038;
	case 20544ULL: goto x86_l_5040;
	case 20550ULL: goto x86_l_5046;
	case 20556ULL: goto x86_l_504c;
	case 20560ULL: goto x86_l_5050;
	case 20564ULL: goto x86_l_5054;
	case 20572ULL: goto x86_l_505c;
	case 20574ULL: goto x86_l_505e;
	case 20577ULL: goto x86_l_5061;
	case 20582ULL: goto x86_l_5066;
	case 20587ULL: goto x86_l_506b;
	case 20591ULL: goto x86_l_506f;
	case 20596ULL: goto x86_l_5074;
	case 20598ULL: goto x86_l_5076;
	case 20600ULL: goto x86_l_5078;
	case 20606ULL: goto x86_l_507e;
	case 20611ULL: goto x86_l_5083;
	case 20619ULL: goto x86_l_508b;
	case 20625ULL: goto x86_l_5091;
	case 20631ULL: goto x86_l_5097;
	case 20635ULL: goto x86_l_509b;
	case 20639ULL: goto x86_l_509f;
	case 20647ULL: goto x86_l_50a7;
	case 20653ULL: goto x86_l_50ad;
	case 20656ULL: goto x86_l_50b0;
	case 20661ULL: goto x86_l_50b5;
	case 20666ULL: goto x86_l_50ba;
	case 20671ULL: goto x86_l_50bf;
	case 20674ULL: goto x86_l_50c2;
	case 20676ULL: goto x86_l_50c4;
	case 20679ULL: goto x86_l_50c7;
	case 20684ULL: goto x86_l_50cc;
	case 20689ULL: goto x86_l_50d1;
	case 20693ULL: goto x86_l_50d5;
	case 20698ULL: goto x86_l_50da;
	case 20700ULL: goto x86_l_50dc;
	case 20702ULL: goto x86_l_50de;
	case 20708ULL: goto x86_l_50e4;
	case 20713ULL: goto x86_l_50e9;
	case 20721ULL: goto x86_l_50f1;
	case 20727ULL: goto x86_l_50f7;
	case 20733ULL: goto x86_l_50fd;
	case 20737ULL: goto x86_l_5101;
	case 20741ULL: goto x86_l_5105;
	case 20749ULL: goto x86_l_510d;
	case 20751ULL: goto x86_l_510f;
	case 20754ULL: goto x86_l_5112;
	case 20759ULL: goto x86_l_5117;
	case 20764ULL: goto x86_l_511c;
	case 20768ULL: goto x86_l_5120;
	case 20773ULL: goto x86_l_5125;
	case 20775ULL: goto x86_l_5127;
	case 20777ULL: goto x86_l_5129;
	case 20783ULL: goto x86_l_512f;
	case 20788ULL: goto x86_l_5134;
	case 20796ULL: goto x86_l_513c;
	case 20802ULL: goto x86_l_5142;
	case 20808ULL: goto x86_l_5148;
	case 20812ULL: goto x86_l_514c;
	case 20816ULL: goto x86_l_5150;
	case 20824ULL: goto x86_l_5158;
	case 20826ULL: goto x86_l_515a;
	case 20829ULL: goto x86_l_515d;
	case 20834ULL: goto x86_l_5162;
	case 20839ULL: goto x86_l_5167;
	case 20843ULL: goto x86_l_516b;
	case 20848ULL: goto x86_l_5170;
	case 20850ULL: goto x86_l_5172;
	case 20852ULL: goto x86_l_5174;
	case 20858ULL: goto x86_l_517a;
	case 20863ULL: goto x86_l_517f;
	case 20871ULL: goto x86_l_5187;
	case 20877ULL: goto x86_l_518d;
	case 20883ULL: goto x86_l_5193;
	case 20887ULL: goto x86_l_5197;
	case 20891ULL: goto x86_l_519b;
	case 20899ULL: goto x86_l_51a3;
	case 20901ULL: goto x86_l_51a5;
	case 20904ULL: goto x86_l_51a8;
	case 20909ULL: goto x86_l_51ad;
	case 20914ULL: goto x86_l_51b2;
	case 20918ULL: goto x86_l_51b6;
	case 20923ULL: goto x86_l_51bb;
	case 20925ULL: goto x86_l_51bd;
	case 20927ULL: goto x86_l_51bf;
	case 20933ULL: goto x86_l_51c5;
	case 20938ULL: goto x86_l_51ca;
	case 20946ULL: goto x86_l_51d2;
	case 20952ULL: goto x86_l_51d8;
	case 20958ULL: goto x86_l_51de;
	case 20962ULL: goto x86_l_51e2;
	case 20966ULL: goto x86_l_51e6;
	case 20974ULL: goto x86_l_51ee;
	case 20976ULL: goto x86_l_51f0;
	case 20979ULL: goto x86_l_51f3;
	case 20984ULL: goto x86_l_51f8;
	case 20989ULL: goto x86_l_51fd;
	case 20993ULL: goto x86_l_5201;
	case 20998ULL: goto x86_l_5206;
	case 21000ULL: goto x86_l_5208;
	case 21002ULL: goto x86_l_520a;
	case 21008ULL: goto x86_l_5210;
	case 21013ULL: goto x86_l_5215;
	case 21021ULL: goto x86_l_521d;
	case 21027ULL: goto x86_l_5223;
	case 21033ULL: goto x86_l_5229;
	case 21037ULL: goto x86_l_522d;
	case 21041ULL: goto x86_l_5231;
	case 21049ULL: goto x86_l_5239;
	case 21051ULL: goto x86_l_523b;
	case 21054ULL: goto x86_l_523e;
	case 21059ULL: goto x86_l_5243;
	case 21064ULL: goto x86_l_5248;
	case 21068ULL: goto x86_l_524c;
	case 21073ULL: goto x86_l_5251;
	case 21075ULL: goto x86_l_5253;
	case 21077ULL: goto x86_l_5255;
	case 21083ULL: goto x86_l_525b;
	case 21088ULL: goto x86_l_5260;
	case 21096ULL: goto x86_l_5268;
	case 21102ULL: goto x86_l_526e;
	case 21108ULL: goto x86_l_5274;
	case 21112ULL: goto x86_l_5278;
	case 21116ULL: goto x86_l_527c;
	case 21124ULL: goto x86_l_5284;
	case 21126ULL: goto x86_l_5286;
	case 21129ULL: goto x86_l_5289;
	case 21134ULL: goto x86_l_528e;
	case 21139ULL: goto x86_l_5293;
	case 21143ULL: goto x86_l_5297;
	case 21148ULL: goto x86_l_529c;
	case 21150ULL: goto x86_l_529e;
	case 21152ULL: goto x86_l_52a0;
	case 21158ULL: goto x86_l_52a6;
	case 21163ULL: goto x86_l_52ab;
	case 21171ULL: goto x86_l_52b3;
	case 21177ULL: goto x86_l_52b9;
	case 21183ULL: goto x86_l_52bf;
	case 21187ULL: goto x86_l_52c3;
	case 21191ULL: goto x86_l_52c7;
	case 21199ULL: goto x86_l_52cf;
	case 21201ULL: goto x86_l_52d1;
	case 21204ULL: goto x86_l_52d4;
	case 21209ULL: goto x86_l_52d9;
	case 21214ULL: goto x86_l_52de;
	case 21218ULL: goto x86_l_52e2;
	default: return 0xffffffffffffffffULL;
	}
x86_l_4c29:
	/* 0x4c29: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c2e:
	/* 0x4c2e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c30:
	/* 0x4c30: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4c33:
	/* 0x4c33: je     4c64 <generic_sleepable_preload+0x4c64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4c64;
	}
x86_l_4c35:
	/* 0x4c35: test   r13b,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_8);
x86_l_4c38:
	/* 0x4c38: je     4c62 <generic_sleepable_preload+0x4c62> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4c62;
	}
x86_l_4c3a:
	/* 0x4c3a: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_4c3d:
	/* 0x4c3d: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_4c41:
	/* 0x4c41: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4c46:
	/* 0x4c46: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_4c49:
	/* 0x4c49: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4c4b:
	/* 0x4c4b: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_4c4e:
	/* 0x4c4e: call   4c53 <generic_sleepable_preload+0x4c53> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_4c53:
	/* 0x4c53: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_4c55:
	/* 0x4c55: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_4c58:
	/* 0x4c58: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_4c5a:
	/* 0x4c5a: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_4c5f:
	/* 0x4c5f: cmovs  ebx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_4c62:
	/* 0x4c62: mov    DWORD PTR [rax],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c64:
	/* 0x4c64: mov    r14,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_64);
x86_l_4c67:
	/* 0x4c67: mov    eax,DWORD PTR [r12+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4c6c:
	/* 0x4c6c: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_4c71:
	/* 0x4c71: jne    4c84 <generic_sleepable_preload+0x4c84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4c84;
	}
x86_l_4c73:
	/* 0x4c73: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4c75:
	/* 0x4c75: add    rsp,0xb8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 184ULL);
x86_l_4c7c:
	/* 0x4c7c: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_4c7e:
	/* 0x4c7e: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_4c7f:
	/* 0x4c7f: jmp    5de0 <generic_sleepable_preload+0x5de0> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_4c84:
	/* 0x4c84: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_4c86:
	/* 0x4c86: js     4cbb <generic_sleepable_preload+0x4cbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4cbb;
	}
x86_l_4c88:
	/* 0x4c88: mov    eax,DWORD PTR [r12+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4c8d:
	/* 0x4c8d: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4c90:
	/* 0x4c90: jle    4d3e <generic_sleepable_preload+0x4d3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_4d3e;
	}
x86_l_4c96:
	/* 0x4c96: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4c99:
	/* 0x4c99: je     4da8 <generic_sleepable_preload+0x4da8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4da8;
	}
x86_l_4c9f:
	/* 0x4c9f: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_4ca2:
	/* 0x4ca2: je     4daf <generic_sleepable_preload+0x4daf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4daf;
	}
x86_l_4ca8:
	/* 0x4ca8: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4cab:
	/* 0x4cab: jne    4dc2 <generic_sleepable_preload+0x4dc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4dc2;
	}
x86_l_4cb1:
	/* 0x4cb1: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4cb6:
	/* 0x4cb6: jmp    4dbb <generic_sleepable_preload+0x4dbb> */
	goto x86_l_4dbb;
x86_l_4cbb:
	/* 0x4cbb: movzx  eax,BYTE PTR [r12+0x2d2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 722ULL);
x86_l_4cc4:
	/* 0x4cc4: movzx  ecx,WORD PTR [r12+0x2d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 720ULL);
x86_l_4ccd:
	/* 0x4ccd: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_4cd3:
	/* 0x4cd3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4cd5:
	/* 0x4cd5: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_4cd8:
	/* 0x4cd8: jle    4d17 <generic_sleepable_preload+0x4d17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_4d17;
	}
x86_l_4cda:
	/* 0x4cda: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_4cdd:
	/* 0x4cdd: jle    4d4e <generic_sleepable_preload+0x4d4e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_4d4e;
	}
x86_l_4cdf:
	/* 0x4cdf: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_4ce2:
	/* 0x4ce2: jle    53e9 <generic_sleepable_preload+0x53e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 21481ULL;
	}
x86_l_4ce8:
	/* 0x4ce8: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4ced:
	/* 0x4ced: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_4cf0:
	/* 0x4cf0: je     540f <generic_sleepable_preload+0x540f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21519ULL;
	}
x86_l_4cf6:
	/* 0x4cf6: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4cfb:
	/* 0x4cfb: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_4cfe:
	/* 0x4cfe: je     540f <generic_sleepable_preload+0x540f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21519ULL;
	}
x86_l_4d04:
	/* 0x4d04: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4d09:
	/* 0x4d09: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_4d0c:
	/* 0x4d0c: je     540f <generic_sleepable_preload+0x540f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21519ULL;
	}
x86_l_4d12:
	/* 0x4d12: jmp    5422 <generic_sleepable_preload+0x5422> */
	return 21538ULL;
x86_l_4d17:
	/* 0x4d17: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_4d1a:
	/* 0x4d1a: jg     4d7b <generic_sleepable_preload+0x4d7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_4d7b;
	}
x86_l_4d1c:
	/* 0x4d1c: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_4d1f:
	/* 0x4d1f: jg     53ba <generic_sleepable_preload+0x53ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 21434ULL;
	}
x86_l_4d25:
	/* 0x4d25: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_4d27:
	/* 0x4d27: je     540a <generic_sleepable_preload+0x540a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21514ULL;
	}
x86_l_4d2d:
	/* 0x4d2d: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_4d30:
	/* 0x4d30: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_4d33:
	/* 0x4d33: je     540f <generic_sleepable_preload+0x540f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21519ULL;
	}
x86_l_4d39:
	/* 0x4d39: jmp    5422 <generic_sleepable_preload+0x5422> */
	return 21538ULL;
x86_l_4d3e:
	/* 0x4d3e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4d40:
	/* 0x4d40: je     4db6 <generic_sleepable_preload+0x4db6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4db6;
	}
x86_l_4d42:
	/* 0x4d42: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4d45:
	/* 0x4d45: jne    4dc2 <generic_sleepable_preload+0x4dc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4dc2;
	}
x86_l_4d47:
	/* 0x4d47: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4d4c:
	/* 0x4d4c: jmp    4dbb <generic_sleepable_preload+0x4dbb> */
	goto x86_l_4dbb;
x86_l_4d4e:
	/* 0x4d4e: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_4d51:
	/* 0x4d51: jg     53a1 <generic_sleepable_preload+0x53a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 21409ULL;
	}
x86_l_4d57:
	/* 0x4d57: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_4d5f:
	/* 0x4d5f: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4d62:
	/* 0x4d62: je     540f <generic_sleepable_preload+0x540f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21519ULL;
	}
x86_l_4d68:
	/* 0x4d68: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4d6d:
	/* 0x4d6d: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_4d70:
	/* 0x4d70: je     540f <generic_sleepable_preload+0x540f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21519ULL;
	}
x86_l_4d76:
	/* 0x4d76: jmp    5422 <generic_sleepable_preload+0x5422> */
	return 21538ULL;
x86_l_4d7b:
	/* 0x4d7b: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_4d7e:
	/* 0x4d7e: jg     53d0 <generic_sleepable_preload+0x53d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 21456ULL;
	}
x86_l_4d84:
	/* 0x4d84: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_4d8c:
	/* 0x4d8c: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_4d8f:
	/* 0x4d8f: je     540f <generic_sleepable_preload+0x540f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21519ULL;
	}
x86_l_4d95:
	/* 0x4d95: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4d9a:
	/* 0x4d9a: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_4d9d:
	/* 0x4d9d: je     540f <generic_sleepable_preload+0x540f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21519ULL;
	}
x86_l_4da3:
	/* 0x4da3: jmp    5422 <generic_sleepable_preload+0x5422> */
	return 21538ULL;
x86_l_4da8:
	/* 0x4da8: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4dad:
	/* 0x4dad: jmp    4dbb <generic_sleepable_preload+0x4dbb> */
	goto x86_l_4dbb;
x86_l_4daf:
	/* 0x4daf: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4db4:
	/* 0x4db4: jmp    4dbb <generic_sleepable_preload+0x4dbb> */
	goto x86_l_4dbb;
x86_l_4db6:
	/* 0x4db6: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4dbb:
	/* 0x4dbb: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4dbe:
	/* 0x4dbe: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4dc2:
	/* 0x4dc2: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4dc5:
	/* 0x4dc5: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_4dc8:
	/* 0x4dc8: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4dcd:
	/* 0x4dcd: cmp    WORD PTR [rsi+0x1b6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1881195675648ULL);
x86_l_4dd5:
	/* 0x4dd5: je     5a68 <generic_sleepable_preload+0x5a68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23144ULL;
	}
x86_l_4ddb:
	/* 0x4ddb: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_4de2:
	/* 0x4de2: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_4de5:
	/* 0x4de5: mov    eax,DWORD PTR [rsi+0x1b0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 432ULL);
x86_l_4deb:
	/* 0x4deb: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4dee:
	/* 0x4dee: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4df2:
	/* 0x4df2: movzx  eax,WORD PTR [rsi+0x1b4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 436ULL);
x86_l_4df9:
	/* 0x4df9: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_4dfb:
	/* 0x4dfb: je     50bf <generic_sleepable_preload+0x50bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_50bf;
	}
x86_l_4e01:
	/* 0x4e01: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_4e04:
	/* 0x4e04: je     4e26 <generic_sleepable_preload+0x4e26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4e26;
	}
x86_l_4e06:
	/* 0x4e06: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4e09:
	/* 0x4e09: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4e0e:
	/* 0x4e0e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4e13:
	/* 0x4e13: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e17:
	/* 0x4e17: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e1c:
	/* 0x4e1c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e1e:
	/* 0x4e1e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4e20:
	/* 0x4e20: js     5396 <generic_sleepable_preload+0x5396> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21398ULL;
	}
x86_l_4e26:
	/* 0x4e26: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e2b:
	/* 0x4e2b: cmp    WORD PTR [rax+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_4e33:
	/* 0x4e33: je     5a68 <generic_sleepable_preload+0x5a68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23144ULL;
	}
x86_l_4e39:
	/* 0x4e39: mov    ecx,DWORD PTR [rax+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_4e3f:
	/* 0x4e3f: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4e43:
	/* 0x4e43: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e47:
	/* 0x4e47: cmp    WORD PTR [rax+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_4e4f:
	/* 0x4e4f: je     4e71 <generic_sleepable_preload+0x4e71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4e71;
	}
x86_l_4e51:
	/* 0x4e51: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4e54:
	/* 0x4e54: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4e59:
	/* 0x4e59: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4e5e:
	/* 0x4e5e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e62:
	/* 0x4e62: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e67:
	/* 0x4e67: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e69:
	/* 0x4e69: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4e6b:
	/* 0x4e6b: js     53ff <generic_sleepable_preload+0x53ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21503ULL;
	}
x86_l_4e71:
	/* 0x4e71: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e76:
	/* 0x4e76: cmp    WORD PTR [rax+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_4e7e:
	/* 0x4e7e: je     5a68 <generic_sleepable_preload+0x5a68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23144ULL;
	}
x86_l_4e84:
	/* 0x4e84: mov    ecx,DWORD PTR [rax+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_4e8a:
	/* 0x4e8a: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4e8e:
	/* 0x4e8e: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e92:
	/* 0x4e92: cmp    WORD PTR [rax+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_4e9a:
	/* 0x4e9a: je     4ebc <generic_sleepable_preload+0x4ebc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4ebc;
	}
x86_l_4e9c:
	/* 0x4e9c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4e9f:
	/* 0x4e9f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4ea4:
	/* 0x4ea4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4ea9:
	/* 0x4ea9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ead:
	/* 0x4ead: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4eb2:
	/* 0x4eb2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4eb4:
	/* 0x4eb4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4eb6:
	/* 0x4eb6: js     5a13 <generic_sleepable_preload+0x5a13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23059ULL;
	}
x86_l_4ebc:
	/* 0x4ebc: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ec1:
	/* 0x4ec1: cmp    WORD PTR [rax+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_4ec9:
	/* 0x4ec9: je     5a68 <generic_sleepable_preload+0x5a68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23144ULL;
	}
x86_l_4ecf:
	/* 0x4ecf: mov    ecx,DWORD PTR [rax+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_4ed5:
	/* 0x4ed5: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4ed9:
	/* 0x4ed9: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4edd:
	/* 0x4edd: cmp    WORD PTR [rax+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_4ee5:
	/* 0x4ee5: je     4f07 <generic_sleepable_preload+0x4f07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4f07;
	}
x86_l_4ee7:
	/* 0x4ee7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4eea:
	/* 0x4eea: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4eef:
	/* 0x4eef: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4ef4:
	/* 0x4ef4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ef8:
	/* 0x4ef8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4efd:
	/* 0x4efd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4eff:
	/* 0x4eff: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4f01:
	/* 0x4f01: js     5a26 <generic_sleepable_preload+0x5a26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23078ULL;
	}
x86_l_4f07:
	/* 0x4f07: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f0c:
	/* 0x4f0c: cmp    WORD PTR [rax+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_4f14:
	/* 0x4f14: je     5a68 <generic_sleepable_preload+0x5a68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23144ULL;
	}
x86_l_4f1a:
	/* 0x4f1a: mov    ecx,DWORD PTR [rax+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_4f20:
	/* 0x4f20: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4f24:
	/* 0x4f24: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f28:
	/* 0x4f28: cmp    WORD PTR [rax+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_4f30:
	/* 0x4f30: je     4f52 <generic_sleepable_preload+0x4f52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4f52;
	}
x86_l_4f32:
	/* 0x4f32: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4f35:
	/* 0x4f35: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4f3a:
	/* 0x4f3a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4f3f:
	/* 0x4f3f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f43:
	/* 0x4f43: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f48:
	/* 0x4f48: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f4a:
	/* 0x4f4a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4f4c:
	/* 0x4f4c: js     5a39 <generic_sleepable_preload+0x5a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23097ULL;
	}
x86_l_4f52:
	/* 0x4f52: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f57:
	/* 0x4f57: cmp    WORD PTR [rax+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_4f5f:
	/* 0x4f5f: je     5a68 <generic_sleepable_preload+0x5a68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23144ULL;
	}
x86_l_4f65:
	/* 0x4f65: mov    ecx,DWORD PTR [rax+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_4f6b:
	/* 0x4f6b: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4f6f:
	/* 0x4f6f: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f73:
	/* 0x4f73: cmp    WORD PTR [rax+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_4f7b:
	/* 0x4f7b: je     4f9d <generic_sleepable_preload+0x4f9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4f9d;
	}
x86_l_4f7d:
	/* 0x4f7d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4f80:
	/* 0x4f80: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4f85:
	/* 0x4f85: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4f8a:
	/* 0x4f8a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f8e:
	/* 0x4f8e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f93:
	/* 0x4f93: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f95:
	/* 0x4f95: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4f97:
	/* 0x4f97: js     5a4c <generic_sleepable_preload+0x5a4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23116ULL;
	}
x86_l_4f9d:
	/* 0x4f9d: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4fa2:
	/* 0x4fa2: cmp    WORD PTR [rax+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_4faa:
	/* 0x4faa: je     5a68 <generic_sleepable_preload+0x5a68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23144ULL;
	}
x86_l_4fb0:
	/* 0x4fb0: mov    ecx,DWORD PTR [rax+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_4fb6:
	/* 0x4fb6: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4fba:
	/* 0x4fba: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4fbe:
	/* 0x4fbe: cmp    WORD PTR [rax+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_4fc6:
	/* 0x4fc6: je     4fe8 <generic_sleepable_preload+0x4fe8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4fe8;
	}
x86_l_4fc8:
	/* 0x4fc8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4fcb:
	/* 0x4fcb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4fd0:
	/* 0x4fd0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4fd5:
	/* 0x4fd5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4fd9:
	/* 0x4fd9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4fde:
	/* 0x4fde: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4fe0:
	/* 0x4fe0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4fe2:
	/* 0x4fe2: js     5a5f <generic_sleepable_preload+0x5a5f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23135ULL;
	}
x86_l_4fe8:
	/* 0x4fe8: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4fed:
	/* 0x4fed: cmp    WORD PTR [rax+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_4ff5:
	/* 0x4ff5: je     5a68 <generic_sleepable_preload+0x5a68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23144ULL;
	}
x86_l_4ffb:
	/* 0x4ffb: mov    ecx,DWORD PTR [rax+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_5001:
	/* 0x5001: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5005:
	/* 0x5005: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5009:
	/* 0x5009: cmp    WORD PTR [rax+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_5011:
	/* 0x5011: je     5033 <generic_sleepable_preload+0x5033> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5033;
	}
x86_l_5013:
	/* 0x5013: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5016:
	/* 0x5016: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_501b:
	/* 0x501b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5020:
	/* 0x5020: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5024:
	/* 0x5024: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5029:
	/* 0x5029: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_502b:
	/* 0x502b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_502d:
	/* 0x502d: js     5b9d <generic_sleepable_preload+0x5b9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23453ULL;
	}
x86_l_5033:
	/* 0x5033: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5038:
	/* 0x5038: cmp    WORD PTR [rax+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_5040:
	/* 0x5040: je     5a68 <generic_sleepable_preload+0x5a68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23144ULL;
	}
x86_l_5046:
	/* 0x5046: mov    ecx,DWORD PTR [rax+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_504c:
	/* 0x504c: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5050:
	/* 0x5050: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5054:
	/* 0x5054: cmp    WORD PTR [rax+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_505c:
	/* 0x505c: je     507e <generic_sleepable_preload+0x507e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_507e;
	}
x86_l_505e:
	/* 0x505e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5061:
	/* 0x5061: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5066:
	/* 0x5066: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_506b:
	/* 0x506b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_506f:
	/* 0x506f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5074:
	/* 0x5074: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5076:
	/* 0x5076: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5078:
	/* 0x5078: js     5c2a <generic_sleepable_preload+0x5c2a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23594ULL;
	}
x86_l_507e:
	/* 0x507e: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5083:
	/* 0x5083: cmp    WORD PTR [rax+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_508b:
	/* 0x508b: je     5a68 <generic_sleepable_preload+0x5a68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23144ULL;
	}
x86_l_5091:
	/* 0x5091: mov    ecx,DWORD PTR [rax+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_5097:
	/* 0x5097: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_509b:
	/* 0x509b: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_509f:
	/* 0x509f: cmp    WORD PTR [rax+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_50a7:
	/* 0x50a7: je     5a68 <generic_sleepable_preload+0x5a68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23144ULL;
	}
x86_l_50ad:
	/* 0x50ad: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_50b0:
	/* 0x50b0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_50b5:
	/* 0x50b5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_50ba:
	/* 0x50ba: jmp    5378 <generic_sleepable_preload+0x5378> */
	return 21368ULL;
x86_l_50bf:
	/* 0x50bf: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_50c2:
	/* 0x50c2: je     50e4 <generic_sleepable_preload+0x50e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_50e4;
	}
x86_l_50c4:
	/* 0x50c4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_50c7:
	/* 0x50c7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_50cc:
	/* 0x50cc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_50d1:
	/* 0x50d1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_50d5:
	/* 0x50d5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_50da:
	/* 0x50da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50dc:
	/* 0x50dc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_50de:
	/* 0x50de: js     5396 <generic_sleepable_preload+0x5396> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21398ULL;
	}
x86_l_50e4:
	/* 0x50e4: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_50e9:
	/* 0x50e9: cmp    WORD PTR [rax+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_50f1:
	/* 0x50f1: je     5a68 <generic_sleepable_preload+0x5a68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23144ULL;
	}
x86_l_50f7:
	/* 0x50f7: mov    ecx,DWORD PTR [rax+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_50fd:
	/* 0x50fd: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5101:
	/* 0x5101: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5105:
	/* 0x5105: cmp    WORD PTR [rax+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_510d:
	/* 0x510d: je     512f <generic_sleepable_preload+0x512f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_512f;
	}
x86_l_510f:
	/* 0x510f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5112:
	/* 0x5112: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5117:
	/* 0x5117: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_511c:
	/* 0x511c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5120:
	/* 0x5120: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5125:
	/* 0x5125: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5127:
	/* 0x5127: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5129:
	/* 0x5129: js     53ff <generic_sleepable_preload+0x53ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21503ULL;
	}
x86_l_512f:
	/* 0x512f: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5134:
	/* 0x5134: cmp    WORD PTR [rax+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_513c:
	/* 0x513c: je     5a68 <generic_sleepable_preload+0x5a68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23144ULL;
	}
x86_l_5142:
	/* 0x5142: mov    ecx,DWORD PTR [rax+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_5148:
	/* 0x5148: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_514c:
	/* 0x514c: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5150:
	/* 0x5150: cmp    WORD PTR [rax+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_5158:
	/* 0x5158: je     517a <generic_sleepable_preload+0x517a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_517a;
	}
x86_l_515a:
	/* 0x515a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_515d:
	/* 0x515d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5162:
	/* 0x5162: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5167:
	/* 0x5167: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_516b:
	/* 0x516b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5170:
	/* 0x5170: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5172:
	/* 0x5172: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5174:
	/* 0x5174: js     5a13 <generic_sleepable_preload+0x5a13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23059ULL;
	}
x86_l_517a:
	/* 0x517a: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_517f:
	/* 0x517f: cmp    WORD PTR [rax+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_5187:
	/* 0x5187: je     5a68 <generic_sleepable_preload+0x5a68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23144ULL;
	}
x86_l_518d:
	/* 0x518d: mov    ecx,DWORD PTR [rax+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_5193:
	/* 0x5193: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5197:
	/* 0x5197: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_519b:
	/* 0x519b: cmp    WORD PTR [rax+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_51a3:
	/* 0x51a3: je     51c5 <generic_sleepable_preload+0x51c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_51c5;
	}
x86_l_51a5:
	/* 0x51a5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_51a8:
	/* 0x51a8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_51ad:
	/* 0x51ad: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_51b2:
	/* 0x51b2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_51b6:
	/* 0x51b6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_51bb:
	/* 0x51bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_51bd:
	/* 0x51bd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_51bf:
	/* 0x51bf: js     5a26 <generic_sleepable_preload+0x5a26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23078ULL;
	}
x86_l_51c5:
	/* 0x51c5: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_51ca:
	/* 0x51ca: cmp    WORD PTR [rax+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_51d2:
	/* 0x51d2: je     5a68 <generic_sleepable_preload+0x5a68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23144ULL;
	}
x86_l_51d8:
	/* 0x51d8: mov    ecx,DWORD PTR [rax+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_51de:
	/* 0x51de: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_51e2:
	/* 0x51e2: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_51e6:
	/* 0x51e6: cmp    WORD PTR [rax+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_51ee:
	/* 0x51ee: je     5210 <generic_sleepable_preload+0x5210> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5210;
	}
x86_l_51f0:
	/* 0x51f0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_51f3:
	/* 0x51f3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_51f8:
	/* 0x51f8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_51fd:
	/* 0x51fd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5201:
	/* 0x5201: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5206:
	/* 0x5206: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5208:
	/* 0x5208: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_520a:
	/* 0x520a: js     5a39 <generic_sleepable_preload+0x5a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23097ULL;
	}
x86_l_5210:
	/* 0x5210: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5215:
	/* 0x5215: cmp    WORD PTR [rax+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_521d:
	/* 0x521d: je     5a68 <generic_sleepable_preload+0x5a68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23144ULL;
	}
x86_l_5223:
	/* 0x5223: mov    ecx,DWORD PTR [rax+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_5229:
	/* 0x5229: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_522d:
	/* 0x522d: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5231:
	/* 0x5231: cmp    WORD PTR [rax+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_5239:
	/* 0x5239: je     525b <generic_sleepable_preload+0x525b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_525b;
	}
x86_l_523b:
	/* 0x523b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_523e:
	/* 0x523e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5243:
	/* 0x5243: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5248:
	/* 0x5248: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_524c:
	/* 0x524c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5251:
	/* 0x5251: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5253:
	/* 0x5253: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5255:
	/* 0x5255: js     5a4c <generic_sleepable_preload+0x5a4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23116ULL;
	}
x86_l_525b:
	/* 0x525b: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5260:
	/* 0x5260: cmp    WORD PTR [rax+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_5268:
	/* 0x5268: je     5a68 <generic_sleepable_preload+0x5a68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23144ULL;
	}
x86_l_526e:
	/* 0x526e: mov    ecx,DWORD PTR [rax+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_5274:
	/* 0x5274: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5278:
	/* 0x5278: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_527c:
	/* 0x527c: cmp    WORD PTR [rax+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_5284:
	/* 0x5284: je     52a6 <generic_sleepable_preload+0x52a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_52a6;
	}
x86_l_5286:
	/* 0x5286: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5289:
	/* 0x5289: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_528e:
	/* 0x528e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5293:
	/* 0x5293: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5297:
	/* 0x5297: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_529c:
	/* 0x529c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_529e:
	/* 0x529e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_52a0:
	/* 0x52a0: js     5a5f <generic_sleepable_preload+0x5a5f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23135ULL;
	}
x86_l_52a6:
	/* 0x52a6: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52ab:
	/* 0x52ab: cmp    WORD PTR [rax+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_52b3:
	/* 0x52b3: je     5a68 <generic_sleepable_preload+0x5a68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23144ULL;
	}
x86_l_52b9:
	/* 0x52b9: mov    ecx,DWORD PTR [rax+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_52bf:
	/* 0x52bf: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_52c3:
	/* 0x52c3: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_52c7:
	/* 0x52c7: cmp    WORD PTR [rax+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_52cf:
	/* 0x52cf: je     52f1 <generic_sleepable_preload+0x52f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21233ULL;
	}
x86_l_52d1:
	/* 0x52d1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_52d4:
	/* 0x52d4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_52d9:
	/* 0x52d9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_52de:
	/* 0x52de: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_52e2:
	/* 0x52e2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
	return 21223ULL;
}

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_12(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 21223ULL: goto x86_l_52e7;
	case 21225ULL: goto x86_l_52e9;
	case 21227ULL: goto x86_l_52eb;
	case 21233ULL: goto x86_l_52f1;
	case 21238ULL: goto x86_l_52f6;
	case 21246ULL: goto x86_l_52fe;
	case 21252ULL: goto x86_l_5304;
	case 21258ULL: goto x86_l_530a;
	case 21262ULL: goto x86_l_530e;
	case 21266ULL: goto x86_l_5312;
	case 21274ULL: goto x86_l_531a;
	case 21276ULL: goto x86_l_531c;
	case 21279ULL: goto x86_l_531f;
	case 21284ULL: goto x86_l_5324;
	case 21289ULL: goto x86_l_5329;
	case 21293ULL: goto x86_l_532d;
	case 21298ULL: goto x86_l_5332;
	case 21300ULL: goto x86_l_5334;
	case 21302ULL: goto x86_l_5336;
	case 21308ULL: goto x86_l_533c;
	case 21313ULL: goto x86_l_5341;
	case 21321ULL: goto x86_l_5349;
	case 21327ULL: goto x86_l_534f;
	case 21333ULL: goto x86_l_5355;
	case 21337ULL: goto x86_l_5359;
	case 21341ULL: goto x86_l_535d;
	case 21349ULL: goto x86_l_5365;
	case 21355ULL: goto x86_l_536b;
	case 21358ULL: goto x86_l_536e;
	case 21363ULL: goto x86_l_5373;
	case 21368ULL: goto x86_l_5378;
	case 21372ULL: goto x86_l_537c;
	case 21377ULL: goto x86_l_5381;
	case 21379ULL: goto x86_l_5383;
	case 21381ULL: goto x86_l_5385;
	case 21387ULL: goto x86_l_538b;
	case 21393ULL: goto x86_l_5391;
	case 21398ULL: goto x86_l_5396;
	case 21404ULL: goto x86_l_539c;
	case 21409ULL: goto x86_l_53a1;
	case 21417ULL: goto x86_l_53a9;
	case 21420ULL: goto x86_l_53ac;
	case 21422ULL: goto x86_l_53ae;
	case 21427ULL: goto x86_l_53b3;
	case 21430ULL: goto x86_l_53b6;
	case 21432ULL: goto x86_l_53b8;
	case 21434ULL: goto x86_l_53ba;
	case 21439ULL: goto x86_l_53bf;
	case 21442ULL: goto x86_l_53c2;
	case 21444ULL: goto x86_l_53c4;
	case 21449ULL: goto x86_l_53c9;
	case 21452ULL: goto x86_l_53cc;
	case 21454ULL: goto x86_l_53ce;
	case 21456ULL: goto x86_l_53d0;
	case 21464ULL: goto x86_l_53d8;
	case 21467ULL: goto x86_l_53db;
	case 21469ULL: goto x86_l_53dd;
	case 21474ULL: goto x86_l_53e2;
	case 21477ULL: goto x86_l_53e5;
	case 21479ULL: goto x86_l_53e7;
	case 21481ULL: goto x86_l_53e9;
	case 21486ULL: goto x86_l_53ee;
	case 21489ULL: goto x86_l_53f1;
	case 21491ULL: goto x86_l_53f3;
	case 21496ULL: goto x86_l_53f8;
	case 21499ULL: goto x86_l_53fb;
	case 21501ULL: goto x86_l_53fd;
	case 21503ULL: goto x86_l_53ff;
	case 21509ULL: goto x86_l_5405;
	case 21514ULL: goto x86_l_540a;
	case 21519ULL: goto x86_l_540f;
	case 21522ULL: goto x86_l_5412;
	case 21524ULL: goto x86_l_5414;
	case 21526ULL: goto x86_l_5416;
	case 21531ULL: goto x86_l_541b;
	case 21533ULL: goto x86_l_541d;
	case 21538ULL: goto x86_l_5422;
	case 21542ULL: goto x86_l_5426;
	case 21547ULL: goto x86_l_542b;
	case 21550ULL: goto x86_l_542e;
	case 21553ULL: goto x86_l_5431;
	case 21556ULL: goto x86_l_5434;
	case 21564ULL: goto x86_l_543c;
	case 21570ULL: goto x86_l_5442;
	case 21577ULL: goto x86_l_5449;
	case 21580ULL: goto x86_l_544c;
	case 21586ULL: goto x86_l_5452;
	case 21589ULL: goto x86_l_5455;
	case 21593ULL: goto x86_l_5459;
	case 21600ULL: goto x86_l_5460;
	case 21602ULL: goto x86_l_5462;
	case 21608ULL: goto x86_l_5468;
	case 21611ULL: goto x86_l_546b;
	case 21613ULL: goto x86_l_546d;
	case 21616ULL: goto x86_l_5470;
	case 21621ULL: goto x86_l_5475;
	case 21626ULL: goto x86_l_547a;
	case 21630ULL: goto x86_l_547e;
	case 21635ULL: goto x86_l_5483;
	case 21637ULL: goto x86_l_5485;
	case 21639ULL: goto x86_l_5487;
	case 21645ULL: goto x86_l_548d;
	case 21650ULL: goto x86_l_5492;
	case 21658ULL: goto x86_l_549a;
	case 21664ULL: goto x86_l_54a0;
	case 21670ULL: goto x86_l_54a6;
	case 21674ULL: goto x86_l_54aa;
	case 21678ULL: goto x86_l_54ae;
	case 21686ULL: goto x86_l_54b6;
	case 21688ULL: goto x86_l_54b8;
	case 21691ULL: goto x86_l_54bb;
	case 21696ULL: goto x86_l_54c0;
	case 21701ULL: goto x86_l_54c5;
	case 21705ULL: goto x86_l_54c9;
	case 21710ULL: goto x86_l_54ce;
	case 21712ULL: goto x86_l_54d0;
	case 21714ULL: goto x86_l_54d2;
	case 21720ULL: goto x86_l_54d8;
	case 21725ULL: goto x86_l_54dd;
	case 21733ULL: goto x86_l_54e5;
	case 21739ULL: goto x86_l_54eb;
	case 21745ULL: goto x86_l_54f1;
	case 21749ULL: goto x86_l_54f5;
	case 21753ULL: goto x86_l_54f9;
	case 21761ULL: goto x86_l_5501;
	case 21763ULL: goto x86_l_5503;
	case 21766ULL: goto x86_l_5506;
	case 21771ULL: goto x86_l_550b;
	case 21776ULL: goto x86_l_5510;
	case 21780ULL: goto x86_l_5514;
	case 21785ULL: goto x86_l_5519;
	case 21787ULL: goto x86_l_551b;
	case 21789ULL: goto x86_l_551d;
	case 21795ULL: goto x86_l_5523;
	case 21800ULL: goto x86_l_5528;
	case 21808ULL: goto x86_l_5530;
	case 21814ULL: goto x86_l_5536;
	case 21820ULL: goto x86_l_553c;
	case 21824ULL: goto x86_l_5540;
	case 21828ULL: goto x86_l_5544;
	case 21836ULL: goto x86_l_554c;
	case 21838ULL: goto x86_l_554e;
	case 21841ULL: goto x86_l_5551;
	case 21846ULL: goto x86_l_5556;
	case 21851ULL: goto x86_l_555b;
	case 21855ULL: goto x86_l_555f;
	case 21860ULL: goto x86_l_5564;
	case 21862ULL: goto x86_l_5566;
	case 21864ULL: goto x86_l_5568;
	case 21870ULL: goto x86_l_556e;
	case 21875ULL: goto x86_l_5573;
	case 21883ULL: goto x86_l_557b;
	case 21889ULL: goto x86_l_5581;
	case 21895ULL: goto x86_l_5587;
	case 21899ULL: goto x86_l_558b;
	case 21903ULL: goto x86_l_558f;
	case 21911ULL: goto x86_l_5597;
	case 21913ULL: goto x86_l_5599;
	case 21916ULL: goto x86_l_559c;
	case 21921ULL: goto x86_l_55a1;
	case 21926ULL: goto x86_l_55a6;
	case 21930ULL: goto x86_l_55aa;
	case 21935ULL: goto x86_l_55af;
	case 21937ULL: goto x86_l_55b1;
	case 21939ULL: goto x86_l_55b3;
	case 21945ULL: goto x86_l_55b9;
	case 21950ULL: goto x86_l_55be;
	case 21958ULL: goto x86_l_55c6;
	case 21964ULL: goto x86_l_55cc;
	case 21970ULL: goto x86_l_55d2;
	case 21974ULL: goto x86_l_55d6;
	case 21978ULL: goto x86_l_55da;
	case 21986ULL: goto x86_l_55e2;
	case 21988ULL: goto x86_l_55e4;
	case 21991ULL: goto x86_l_55e7;
	case 21996ULL: goto x86_l_55ec;
	case 22001ULL: goto x86_l_55f1;
	case 22005ULL: goto x86_l_55f5;
	case 22010ULL: goto x86_l_55fa;
	case 22012ULL: goto x86_l_55fc;
	case 22014ULL: goto x86_l_55fe;
	case 22020ULL: goto x86_l_5604;
	case 22025ULL: goto x86_l_5609;
	case 22033ULL: goto x86_l_5611;
	case 22039ULL: goto x86_l_5617;
	case 22045ULL: goto x86_l_561d;
	case 22049ULL: goto x86_l_5621;
	case 22053ULL: goto x86_l_5625;
	case 22061ULL: goto x86_l_562d;
	case 22063ULL: goto x86_l_562f;
	case 22066ULL: goto x86_l_5632;
	case 22071ULL: goto x86_l_5637;
	case 22076ULL: goto x86_l_563c;
	case 22080ULL: goto x86_l_5640;
	case 22085ULL: goto x86_l_5645;
	case 22087ULL: goto x86_l_5647;
	case 22089ULL: goto x86_l_5649;
	case 22095ULL: goto x86_l_564f;
	case 22100ULL: goto x86_l_5654;
	case 22108ULL: goto x86_l_565c;
	case 22114ULL: goto x86_l_5662;
	case 22120ULL: goto x86_l_5668;
	case 22124ULL: goto x86_l_566c;
	case 22128ULL: goto x86_l_5670;
	case 22136ULL: goto x86_l_5678;
	case 22138ULL: goto x86_l_567a;
	case 22141ULL: goto x86_l_567d;
	case 22146ULL: goto x86_l_5682;
	case 22151ULL: goto x86_l_5687;
	case 22155ULL: goto x86_l_568b;
	case 22160ULL: goto x86_l_5690;
	case 22162ULL: goto x86_l_5692;
	case 22164ULL: goto x86_l_5694;
	case 22170ULL: goto x86_l_569a;
	case 22175ULL: goto x86_l_569f;
	case 22183ULL: goto x86_l_56a7;
	case 22189ULL: goto x86_l_56ad;
	case 22195ULL: goto x86_l_56b3;
	case 22199ULL: goto x86_l_56b7;
	case 22203ULL: goto x86_l_56bb;
	case 22211ULL: goto x86_l_56c3;
	case 22213ULL: goto x86_l_56c5;
	case 22216ULL: goto x86_l_56c8;
	case 22221ULL: goto x86_l_56cd;
	case 22226ULL: goto x86_l_56d2;
	case 22230ULL: goto x86_l_56d6;
	case 22235ULL: goto x86_l_56db;
	case 22237ULL: goto x86_l_56dd;
	case 22239ULL: goto x86_l_56df;
	case 22245ULL: goto x86_l_56e5;
	case 22250ULL: goto x86_l_56ea;
	case 22258ULL: goto x86_l_56f2;
	case 22264ULL: goto x86_l_56f8;
	case 22270ULL: goto x86_l_56fe;
	case 22274ULL: goto x86_l_5702;
	case 22278ULL: goto x86_l_5706;
	case 22286ULL: goto x86_l_570e;
	case 22292ULL: goto x86_l_5714;
	case 22295ULL: goto x86_l_5717;
	case 22300ULL: goto x86_l_571c;
	case 22305ULL: goto x86_l_5721;
	case 22310ULL: goto x86_l_5726;
	case 22313ULL: goto x86_l_5729;
	case 22315ULL: goto x86_l_572b;
	case 22318ULL: goto x86_l_572e;
	case 22323ULL: goto x86_l_5733;
	case 22328ULL: goto x86_l_5738;
	case 22332ULL: goto x86_l_573c;
	case 22337ULL: goto x86_l_5741;
	case 22339ULL: goto x86_l_5743;
	case 22341ULL: goto x86_l_5745;
	case 22347ULL: goto x86_l_574b;
	case 22352ULL: goto x86_l_5750;
	case 22360ULL: goto x86_l_5758;
	case 22366ULL: goto x86_l_575e;
	case 22372ULL: goto x86_l_5764;
	case 22376ULL: goto x86_l_5768;
	case 22380ULL: goto x86_l_576c;
	case 22388ULL: goto x86_l_5774;
	case 22390ULL: goto x86_l_5776;
	case 22393ULL: goto x86_l_5779;
	case 22398ULL: goto x86_l_577e;
	case 22403ULL: goto x86_l_5783;
	case 22407ULL: goto x86_l_5787;
	case 22412ULL: goto x86_l_578c;
	case 22414ULL: goto x86_l_578e;
	case 22416ULL: goto x86_l_5790;
	case 22422ULL: goto x86_l_5796;
	case 22427ULL: goto x86_l_579b;
	case 22435ULL: goto x86_l_57a3;
	case 22441ULL: goto x86_l_57a9;
	case 22447ULL: goto x86_l_57af;
	case 22451ULL: goto x86_l_57b3;
	case 22455ULL: goto x86_l_57b7;
	case 22463ULL: goto x86_l_57bf;
	case 22465ULL: goto x86_l_57c1;
	case 22468ULL: goto x86_l_57c4;
	case 22473ULL: goto x86_l_57c9;
	case 22478ULL: goto x86_l_57ce;
	case 22482ULL: goto x86_l_57d2;
	case 22487ULL: goto x86_l_57d7;
	case 22489ULL: goto x86_l_57d9;
	case 22491ULL: goto x86_l_57db;
	case 22497ULL: goto x86_l_57e1;
	case 22502ULL: goto x86_l_57e6;
	case 22510ULL: goto x86_l_57ee;
	case 22516ULL: goto x86_l_57f4;
	case 22522ULL: goto x86_l_57fa;
	case 22526ULL: goto x86_l_57fe;
	case 22530ULL: goto x86_l_5802;
	case 22538ULL: goto x86_l_580a;
	case 22540ULL: goto x86_l_580c;
	case 22543ULL: goto x86_l_580f;
	case 22548ULL: goto x86_l_5814;
	case 22553ULL: goto x86_l_5819;
	case 22557ULL: goto x86_l_581d;
	case 22562ULL: goto x86_l_5822;
	case 22564ULL: goto x86_l_5824;
	case 22566ULL: goto x86_l_5826;
	case 22572ULL: goto x86_l_582c;
	case 22577ULL: goto x86_l_5831;
	case 22585ULL: goto x86_l_5839;
	case 22591ULL: goto x86_l_583f;
	case 22597ULL: goto x86_l_5845;
	case 22601ULL: goto x86_l_5849;
	case 22605ULL: goto x86_l_584d;
	case 22613ULL: goto x86_l_5855;
	case 22615ULL: goto x86_l_5857;
	case 22618ULL: goto x86_l_585a;
	case 22623ULL: goto x86_l_585f;
	case 22628ULL: goto x86_l_5864;
	case 22632ULL: goto x86_l_5868;
	case 22637ULL: goto x86_l_586d;
	case 22639ULL: goto x86_l_586f;
	case 22641ULL: goto x86_l_5871;
	case 22647ULL: goto x86_l_5877;
	case 22652ULL: goto x86_l_587c;
	case 22660ULL: goto x86_l_5884;
	case 22666ULL: goto x86_l_588a;
	case 22672ULL: goto x86_l_5890;
	case 22676ULL: goto x86_l_5894;
	case 22680ULL: goto x86_l_5898;
	case 22688ULL: goto x86_l_58a0;
	case 22690ULL: goto x86_l_58a2;
	case 22693ULL: goto x86_l_58a5;
	case 22698ULL: goto x86_l_58aa;
	case 22703ULL: goto x86_l_58af;
	case 22707ULL: goto x86_l_58b3;
	case 22712ULL: goto x86_l_58b8;
	case 22714ULL: goto x86_l_58ba;
	case 22716ULL: goto x86_l_58bc;
	case 22722ULL: goto x86_l_58c2;
	case 22727ULL: goto x86_l_58c7;
	case 22735ULL: goto x86_l_58cf;
	case 22741ULL: goto x86_l_58d5;
	case 22747ULL: goto x86_l_58db;
	case 22751ULL: goto x86_l_58df;
	case 22755ULL: goto x86_l_58e3;
	case 22763ULL: goto x86_l_58eb;
	case 22765ULL: goto x86_l_58ed;
	case 22768ULL: goto x86_l_58f0;
	case 22773ULL: goto x86_l_58f5;
	case 22778ULL: goto x86_l_58fa;
	case 22782ULL: goto x86_l_58fe;
	case 22787ULL: goto x86_l_5903;
	case 22789ULL: goto x86_l_5905;
	case 22791ULL: goto x86_l_5907;
	case 22797ULL: goto x86_l_590d;
	case 22802ULL: goto x86_l_5912;
	case 22810ULL: goto x86_l_591a;
	case 22816ULL: goto x86_l_5920;
	case 22822ULL: goto x86_l_5926;
	case 22826ULL: goto x86_l_592a;
	case 22830ULL: goto x86_l_592e;
	case 22838ULL: goto x86_l_5936;
	case 22840ULL: goto x86_l_5938;
	case 22843ULL: goto x86_l_593b;
	case 22848ULL: goto x86_l_5940;
	case 22853ULL: goto x86_l_5945;
	case 22857ULL: goto x86_l_5949;
	case 22862ULL: goto x86_l_594e;
	case 22864ULL: goto x86_l_5950;
	case 22866ULL: goto x86_l_5952;
	case 22872ULL: goto x86_l_5958;
	case 22877ULL: goto x86_l_595d;
	case 22885ULL: goto x86_l_5965;
	case 22891ULL: goto x86_l_596b;
	case 22897ULL: goto x86_l_5971;
	case 22901ULL: goto x86_l_5975;
	case 22905ULL: goto x86_l_5979;
	case 22913ULL: goto x86_l_5981;
	case 22915ULL: goto x86_l_5983;
	case 22918ULL: goto x86_l_5986;
	case 22923ULL: goto x86_l_598b;
	case 22928ULL: goto x86_l_5990;
	case 22932ULL: goto x86_l_5994;
	case 22937ULL: goto x86_l_5999;
	case 22939ULL: goto x86_l_599b;
	case 22941ULL: goto x86_l_599d;
	case 22947ULL: goto x86_l_59a3;
	case 22952ULL: goto x86_l_59a8;
	case 22960ULL: goto x86_l_59b0;
	case 22966ULL: goto x86_l_59b6;
	case 22972ULL: goto x86_l_59bc;
	default: return 0xffffffffffffffffULL;
	}
x86_l_52e7:
	/* 0x52e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52e9:
	/* 0x52e9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_52eb:
	/* 0x52eb: js     5b9d <generic_sleepable_preload+0x5b9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23453ULL;
	}
x86_l_52f1:
	/* 0x52f1: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52f6:
	/* 0x52f6: cmp    WORD PTR [rax+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_52fe:
	/* 0x52fe: je     5a68 <generic_sleepable_preload+0x5a68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23144ULL;
	}
x86_l_5304:
	/* 0x5304: mov    ecx,DWORD PTR [rax+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_530a:
	/* 0x530a: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_530e:
	/* 0x530e: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5312:
	/* 0x5312: cmp    WORD PTR [rax+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_531a:
	/* 0x531a: je     533c <generic_sleepable_preload+0x533c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_533c;
	}
x86_l_531c:
	/* 0x531c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_531f:
	/* 0x531f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5324:
	/* 0x5324: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5329:
	/* 0x5329: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_532d:
	/* 0x532d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5332:
	/* 0x5332: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5334:
	/* 0x5334: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5336:
	/* 0x5336: js     5c2a <generic_sleepable_preload+0x5c2a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23594ULL;
	}
x86_l_533c:
	/* 0x533c: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5341:
	/* 0x5341: cmp    WORD PTR [rax+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_5349:
	/* 0x5349: je     5a68 <generic_sleepable_preload+0x5a68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23144ULL;
	}
x86_l_534f:
	/* 0x534f: mov    ecx,DWORD PTR [rax+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_5355:
	/* 0x5355: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5359:
	/* 0x5359: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_535d:
	/* 0x535d: cmp    WORD PTR [rax+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_5365:
	/* 0x5365: je     5a68 <generic_sleepable_preload+0x5a68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23144ULL;
	}
x86_l_536b:
	/* 0x536b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_536e:
	/* 0x536e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5373:
	/* 0x5373: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5378:
	/* 0x5378: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_537c:
	/* 0x537c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5381:
	/* 0x5381: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5383:
	/* 0x5383: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5385:
	/* 0x5385: jns    5a68 <generic_sleepable_preload+0x5a68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 23144ULL;
	}
x86_l_538b:
	/* 0x538b: mov    r12d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 10ULL);
x86_l_5391:
	/* 0x5391: jmp    5a65 <generic_sleepable_preload+0x5a65> */
	return 23141ULL;
x86_l_5396:
	/* 0x5396: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_539c:
	/* 0x539c: jmp    5a65 <generic_sleepable_preload+0x5a65> */
	return 23141ULL;
x86_l_53a1:
	/* 0x53a1: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_53a9:
	/* 0x53a9: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_53ac:
	/* 0x53ac: je     540f <generic_sleepable_preload+0x540f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_540f;
	}
x86_l_53ae:
	/* 0x53ae: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_53b3:
	/* 0x53b3: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_53b6:
	/* 0x53b6: je     540f <generic_sleepable_preload+0x540f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_540f;
	}
x86_l_53b8:
	/* 0x53b8: jmp    5422 <generic_sleepable_preload+0x5422> */
	goto x86_l_5422;
x86_l_53ba:
	/* 0x53ba: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_53bf:
	/* 0x53bf: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_53c2:
	/* 0x53c2: je     540f <generic_sleepable_preload+0x540f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_540f;
	}
x86_l_53c4:
	/* 0x53c4: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_53c9:
	/* 0x53c9: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_53cc:
	/* 0x53cc: je     540f <generic_sleepable_preload+0x540f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_540f;
	}
x86_l_53ce:
	/* 0x53ce: jmp    5422 <generic_sleepable_preload+0x5422> */
	goto x86_l_5422;
x86_l_53d0:
	/* 0x53d0: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_53d8:
	/* 0x53d8: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_53db:
	/* 0x53db: je     540f <generic_sleepable_preload+0x540f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_540f;
	}
x86_l_53dd:
	/* 0x53dd: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_53e2:
	/* 0x53e2: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_53e5:
	/* 0x53e5: je     540f <generic_sleepable_preload+0x540f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_540f;
	}
x86_l_53e7:
	/* 0x53e7: jmp    5422 <generic_sleepable_preload+0x5422> */
	goto x86_l_5422;
x86_l_53e9:
	/* 0x53e9: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_53ee:
	/* 0x53ee: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_53f1:
	/* 0x53f1: je     540f <generic_sleepable_preload+0x540f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_540f;
	}
x86_l_53f3:
	/* 0x53f3: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_53f8:
	/* 0x53f8: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_53fb:
	/* 0x53fb: je     540f <generic_sleepable_preload+0x540f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_540f;
	}
x86_l_53fd:
	/* 0x53fd: jmp    5422 <generic_sleepable_preload+0x5422> */
	goto x86_l_5422;
x86_l_53ff:
	/* 0x53ff: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_5405:
	/* 0x5405: jmp    5a65 <generic_sleepable_preload+0x5a65> */
	return 23141ULL;
x86_l_540a:
	/* 0x540a: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_540f:
	/* 0x540f: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_5412:
	/* 0x5412: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_5414:
	/* 0x5414: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_5416:
	/* 0x5416: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_541b:
	/* 0x541b: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_541d:
	/* 0x541d: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_5422:
	/* 0x5422: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5426:
	/* 0x5426: mov    ebx,DWORD PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_542b:
	/* 0x542b: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_542e:
	/* 0x542e: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5431:
	/* 0x5431: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_5434:
	/* 0x5434: cmp    WORD PTR [rsi+0x1b6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1881195675648ULL);
x86_l_543c:
	/* 0x543c: je     5af4 <generic_sleepable_preload+0x5af4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23284ULL;
	}
x86_l_5442:
	/* 0x5442: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_5449:
	/* 0x5449: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_544c:
	/* 0x544c: mov    eax,DWORD PTR [rsi+0x1b0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 432ULL);
x86_l_5452:
	/* 0x5452: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5455:
	/* 0x5455: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5459:
	/* 0x5459: movzx  eax,WORD PTR [rsi+0x1b4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 436ULL);
x86_l_5460:
	/* 0x5460: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_5462:
	/* 0x5462: je     5726 <generic_sleepable_preload+0x5726> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5726;
	}
x86_l_5468:
	/* 0x5468: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_546b:
	/* 0x546b: je     548d <generic_sleepable_preload+0x548d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_548d;
	}
x86_l_546d:
	/* 0x546d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5470:
	/* 0x5470: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5475:
	/* 0x5475: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_547a:
	/* 0x547a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_547e:
	/* 0x547e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5483:
	/* 0x5483: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5485:
	/* 0x5485: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5487:
	/* 0x5487: js     59fd <generic_sleepable_preload+0x59fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23037ULL;
	}
x86_l_548d:
	/* 0x548d: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5492:
	/* 0x5492: cmp    WORD PTR [rax+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_549a:
	/* 0x549a: je     5af4 <generic_sleepable_preload+0x5af4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23284ULL;
	}
x86_l_54a0:
	/* 0x54a0: mov    ecx,DWORD PTR [rax+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_54a6:
	/* 0x54a6: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_54aa:
	/* 0x54aa: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_54ae:
	/* 0x54ae: cmp    WORD PTR [rax+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_54b6:
	/* 0x54b6: je     54d8 <generic_sleepable_preload+0x54d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_54d8;
	}
x86_l_54b8:
	/* 0x54b8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_54bb:
	/* 0x54bb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_54c0:
	/* 0x54c0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_54c5:
	/* 0x54c5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_54c9:
	/* 0x54c9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_54ce:
	/* 0x54ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_54d0:
	/* 0x54d0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_54d2:
	/* 0x54d2: js     5a08 <generic_sleepable_preload+0x5a08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23048ULL;
	}
x86_l_54d8:
	/* 0x54d8: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_54dd:
	/* 0x54dd: cmp    WORD PTR [rax+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_54e5:
	/* 0x54e5: je     5af4 <generic_sleepable_preload+0x5af4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23284ULL;
	}
x86_l_54eb:
	/* 0x54eb: mov    ecx,DWORD PTR [rax+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_54f1:
	/* 0x54f1: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_54f5:
	/* 0x54f5: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_54f9:
	/* 0x54f9: cmp    WORD PTR [rax+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_5501:
	/* 0x5501: je     5523 <generic_sleepable_preload+0x5523> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5523;
	}
x86_l_5503:
	/* 0x5503: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5506:
	/* 0x5506: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_550b:
	/* 0x550b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5510:
	/* 0x5510: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5514:
	/* 0x5514: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5519:
	/* 0x5519: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_551b:
	/* 0x551b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_551d:
	/* 0x551d: js     5a1b <generic_sleepable_preload+0x5a1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23067ULL;
	}
x86_l_5523:
	/* 0x5523: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5528:
	/* 0x5528: cmp    WORD PTR [rax+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_5530:
	/* 0x5530: je     5af4 <generic_sleepable_preload+0x5af4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23284ULL;
	}
x86_l_5536:
	/* 0x5536: mov    ecx,DWORD PTR [rax+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_553c:
	/* 0x553c: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5540:
	/* 0x5540: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5544:
	/* 0x5544: cmp    WORD PTR [rax+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_554c:
	/* 0x554c: je     556e <generic_sleepable_preload+0x556e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_556e;
	}
x86_l_554e:
	/* 0x554e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5551:
	/* 0x5551: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5556:
	/* 0x5556: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_555b:
	/* 0x555b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_555f:
	/* 0x555f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5564:
	/* 0x5564: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5566:
	/* 0x5566: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5568:
	/* 0x5568: js     5a2e <generic_sleepable_preload+0x5a2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23086ULL;
	}
x86_l_556e:
	/* 0x556e: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5573:
	/* 0x5573: cmp    WORD PTR [rax+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_557b:
	/* 0x557b: je     5af4 <generic_sleepable_preload+0x5af4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23284ULL;
	}
x86_l_5581:
	/* 0x5581: mov    ecx,DWORD PTR [rax+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_5587:
	/* 0x5587: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_558b:
	/* 0x558b: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_558f:
	/* 0x558f: cmp    WORD PTR [rax+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_5597:
	/* 0x5597: je     55b9 <generic_sleepable_preload+0x55b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_55b9;
	}
x86_l_5599:
	/* 0x5599: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_559c:
	/* 0x559c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_55a1:
	/* 0x55a1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_55a6:
	/* 0x55a6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_55aa:
	/* 0x55aa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_55af:
	/* 0x55af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55b1:
	/* 0x55b1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_55b3:
	/* 0x55b3: js     5a41 <generic_sleepable_preload+0x5a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23105ULL;
	}
x86_l_55b9:
	/* 0x55b9: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_55be:
	/* 0x55be: cmp    WORD PTR [rax+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_55c6:
	/* 0x55c6: je     5af4 <generic_sleepable_preload+0x5af4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23284ULL;
	}
x86_l_55cc:
	/* 0x55cc: mov    ecx,DWORD PTR [rax+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_55d2:
	/* 0x55d2: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_55d6:
	/* 0x55d6: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_55da:
	/* 0x55da: cmp    WORD PTR [rax+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_55e2:
	/* 0x55e2: je     5604 <generic_sleepable_preload+0x5604> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5604;
	}
x86_l_55e4:
	/* 0x55e4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_55e7:
	/* 0x55e7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_55ec:
	/* 0x55ec: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_55f1:
	/* 0x55f1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_55f5:
	/* 0x55f5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_55fa:
	/* 0x55fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55fc:
	/* 0x55fc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_55fe:
	/* 0x55fe: js     5a54 <generic_sleepable_preload+0x5a54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23124ULL;
	}
x86_l_5604:
	/* 0x5604: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5609:
	/* 0x5609: cmp    WORD PTR [rax+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_5611:
	/* 0x5611: je     5af4 <generic_sleepable_preload+0x5af4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23284ULL;
	}
x86_l_5617:
	/* 0x5617: mov    ecx,DWORD PTR [rax+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_561d:
	/* 0x561d: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5621:
	/* 0x5621: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5625:
	/* 0x5625: cmp    WORD PTR [rax+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_562d:
	/* 0x562d: je     564f <generic_sleepable_preload+0x564f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_564f;
	}
x86_l_562f:
	/* 0x562f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5632:
	/* 0x5632: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5637:
	/* 0x5637: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_563c:
	/* 0x563c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5640:
	/* 0x5640: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5645:
	/* 0x5645: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5647:
	/* 0x5647: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5649:
	/* 0x5649: js     5aeb <generic_sleepable_preload+0x5aeb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23275ULL;
	}
x86_l_564f:
	/* 0x564f: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5654:
	/* 0x5654: cmp    WORD PTR [rax+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_565c:
	/* 0x565c: je     5af4 <generic_sleepable_preload+0x5af4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23284ULL;
	}
x86_l_5662:
	/* 0x5662: mov    ecx,DWORD PTR [rax+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_5668:
	/* 0x5668: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_566c:
	/* 0x566c: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5670:
	/* 0x5670: cmp    WORD PTR [rax+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_5678:
	/* 0x5678: je     569a <generic_sleepable_preload+0x569a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_569a;
	}
x86_l_567a:
	/* 0x567a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_567d:
	/* 0x567d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5682:
	/* 0x5682: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5687:
	/* 0x5687: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_568b:
	/* 0x568b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5690:
	/* 0x5690: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5692:
	/* 0x5692: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5694:
	/* 0x5694: js     5bab <generic_sleepable_preload+0x5bab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23467ULL;
	}
x86_l_569a:
	/* 0x569a: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_569f:
	/* 0x569f: cmp    WORD PTR [rax+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_56a7:
	/* 0x56a7: je     5af4 <generic_sleepable_preload+0x5af4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23284ULL;
	}
x86_l_56ad:
	/* 0x56ad: mov    ecx,DWORD PTR [rax+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_56b3:
	/* 0x56b3: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_56b7:
	/* 0x56b7: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_56bb:
	/* 0x56bb: cmp    WORD PTR [rax+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_56c3:
	/* 0x56c3: je     56e5 <generic_sleepable_preload+0x56e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_56e5;
	}
x86_l_56c5:
	/* 0x56c5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_56c8:
	/* 0x56c8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_56cd:
	/* 0x56cd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_56d2:
	/* 0x56d2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_56d6:
	/* 0x56d6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_56db:
	/* 0x56db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_56dd:
	/* 0x56dd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_56df:
	/* 0x56df: js     5c35 <generic_sleepable_preload+0x5c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23605ULL;
	}
x86_l_56e5:
	/* 0x56e5: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_56ea:
	/* 0x56ea: cmp    WORD PTR [rax+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_56f2:
	/* 0x56f2: je     5af4 <generic_sleepable_preload+0x5af4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23284ULL;
	}
x86_l_56f8:
	/* 0x56f8: mov    ecx,DWORD PTR [rax+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_56fe:
	/* 0x56fe: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5702:
	/* 0x5702: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5706:
	/* 0x5706: cmp    WORD PTR [rax+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_570e:
	/* 0x570e: je     5af4 <generic_sleepable_preload+0x5af4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23284ULL;
	}
x86_l_5714:
	/* 0x5714: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5717:
	/* 0x5717: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_571c:
	/* 0x571c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5721:
	/* 0x5721: jmp    59df <generic_sleepable_preload+0x59df> */
	return 23007ULL;
x86_l_5726:
	/* 0x5726: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_5729:
	/* 0x5729: je     574b <generic_sleepable_preload+0x574b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_574b;
	}
x86_l_572b:
	/* 0x572b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_572e:
	/* 0x572e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5733:
	/* 0x5733: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5738:
	/* 0x5738: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_573c:
	/* 0x573c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5741:
	/* 0x5741: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5743:
	/* 0x5743: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5745:
	/* 0x5745: js     59fd <generic_sleepable_preload+0x59fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23037ULL;
	}
x86_l_574b:
	/* 0x574b: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5750:
	/* 0x5750: cmp    WORD PTR [rax+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_5758:
	/* 0x5758: je     5af4 <generic_sleepable_preload+0x5af4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23284ULL;
	}
x86_l_575e:
	/* 0x575e: mov    ecx,DWORD PTR [rax+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_5764:
	/* 0x5764: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5768:
	/* 0x5768: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_576c:
	/* 0x576c: cmp    WORD PTR [rax+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_5774:
	/* 0x5774: je     5796 <generic_sleepable_preload+0x5796> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5796;
	}
x86_l_5776:
	/* 0x5776: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5779:
	/* 0x5779: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_577e:
	/* 0x577e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5783:
	/* 0x5783: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5787:
	/* 0x5787: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_578c:
	/* 0x578c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_578e:
	/* 0x578e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5790:
	/* 0x5790: js     5a08 <generic_sleepable_preload+0x5a08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23048ULL;
	}
x86_l_5796:
	/* 0x5796: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_579b:
	/* 0x579b: cmp    WORD PTR [rax+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_57a3:
	/* 0x57a3: je     5af4 <generic_sleepable_preload+0x5af4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23284ULL;
	}
x86_l_57a9:
	/* 0x57a9: mov    ecx,DWORD PTR [rax+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_57af:
	/* 0x57af: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_57b3:
	/* 0x57b3: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_57b7:
	/* 0x57b7: cmp    WORD PTR [rax+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_57bf:
	/* 0x57bf: je     57e1 <generic_sleepable_preload+0x57e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_57e1;
	}
x86_l_57c1:
	/* 0x57c1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_57c4:
	/* 0x57c4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_57c9:
	/* 0x57c9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_57ce:
	/* 0x57ce: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_57d2:
	/* 0x57d2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_57d7:
	/* 0x57d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_57d9:
	/* 0x57d9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_57db:
	/* 0x57db: js     5a1b <generic_sleepable_preload+0x5a1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23067ULL;
	}
x86_l_57e1:
	/* 0x57e1: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_57e6:
	/* 0x57e6: cmp    WORD PTR [rax+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_57ee:
	/* 0x57ee: je     5af4 <generic_sleepable_preload+0x5af4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23284ULL;
	}
x86_l_57f4:
	/* 0x57f4: mov    ecx,DWORD PTR [rax+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_57fa:
	/* 0x57fa: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_57fe:
	/* 0x57fe: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5802:
	/* 0x5802: cmp    WORD PTR [rax+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_580a:
	/* 0x580a: je     582c <generic_sleepable_preload+0x582c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_582c;
	}
x86_l_580c:
	/* 0x580c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_580f:
	/* 0x580f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5814:
	/* 0x5814: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5819:
	/* 0x5819: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_581d:
	/* 0x581d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5822:
	/* 0x5822: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5824:
	/* 0x5824: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5826:
	/* 0x5826: js     5a2e <generic_sleepable_preload+0x5a2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23086ULL;
	}
x86_l_582c:
	/* 0x582c: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5831:
	/* 0x5831: cmp    WORD PTR [rax+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_5839:
	/* 0x5839: je     5af4 <generic_sleepable_preload+0x5af4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23284ULL;
	}
x86_l_583f:
	/* 0x583f: mov    ecx,DWORD PTR [rax+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_5845:
	/* 0x5845: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5849:
	/* 0x5849: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_584d:
	/* 0x584d: cmp    WORD PTR [rax+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_5855:
	/* 0x5855: je     5877 <generic_sleepable_preload+0x5877> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5877;
	}
x86_l_5857:
	/* 0x5857: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_585a:
	/* 0x585a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_585f:
	/* 0x585f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5864:
	/* 0x5864: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5868:
	/* 0x5868: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_586d:
	/* 0x586d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_586f:
	/* 0x586f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5871:
	/* 0x5871: js     5a41 <generic_sleepable_preload+0x5a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23105ULL;
	}
x86_l_5877:
	/* 0x5877: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_587c:
	/* 0x587c: cmp    WORD PTR [rax+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_5884:
	/* 0x5884: je     5af4 <generic_sleepable_preload+0x5af4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23284ULL;
	}
x86_l_588a:
	/* 0x588a: mov    ecx,DWORD PTR [rax+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_5890:
	/* 0x5890: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5894:
	/* 0x5894: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5898:
	/* 0x5898: cmp    WORD PTR [rax+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_58a0:
	/* 0x58a0: je     58c2 <generic_sleepable_preload+0x58c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_58c2;
	}
x86_l_58a2:
	/* 0x58a2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_58a5:
	/* 0x58a5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_58aa:
	/* 0x58aa: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_58af:
	/* 0x58af: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_58b3:
	/* 0x58b3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_58b8:
	/* 0x58b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58ba:
	/* 0x58ba: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_58bc:
	/* 0x58bc: js     5a54 <generic_sleepable_preload+0x5a54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23124ULL;
	}
x86_l_58c2:
	/* 0x58c2: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_58c7:
	/* 0x58c7: cmp    WORD PTR [rax+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_58cf:
	/* 0x58cf: je     5af4 <generic_sleepable_preload+0x5af4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23284ULL;
	}
x86_l_58d5:
	/* 0x58d5: mov    ecx,DWORD PTR [rax+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_58db:
	/* 0x58db: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_58df:
	/* 0x58df: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_58e3:
	/* 0x58e3: cmp    WORD PTR [rax+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_58eb:
	/* 0x58eb: je     590d <generic_sleepable_preload+0x590d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_590d;
	}
x86_l_58ed:
	/* 0x58ed: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_58f0:
	/* 0x58f0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_58f5:
	/* 0x58f5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_58fa:
	/* 0x58fa: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_58fe:
	/* 0x58fe: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5903:
	/* 0x5903: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5905:
	/* 0x5905: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5907:
	/* 0x5907: js     5aeb <generic_sleepable_preload+0x5aeb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23275ULL;
	}
x86_l_590d:
	/* 0x590d: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5912:
	/* 0x5912: cmp    WORD PTR [rax+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_591a:
	/* 0x591a: je     5af4 <generic_sleepable_preload+0x5af4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23284ULL;
	}
x86_l_5920:
	/* 0x5920: mov    ecx,DWORD PTR [rax+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_5926:
	/* 0x5926: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_592a:
	/* 0x592a: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_592e:
	/* 0x592e: cmp    WORD PTR [rax+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_5936:
	/* 0x5936: je     5958 <generic_sleepable_preload+0x5958> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5958;
	}
x86_l_5938:
	/* 0x5938: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_593b:
	/* 0x593b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5940:
	/* 0x5940: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5945:
	/* 0x5945: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5949:
	/* 0x5949: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_594e:
	/* 0x594e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5950:
	/* 0x5950: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5952:
	/* 0x5952: js     5bab <generic_sleepable_preload+0x5bab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23467ULL;
	}
x86_l_5958:
	/* 0x5958: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_595d:
	/* 0x595d: cmp    WORD PTR [rax+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_5965:
	/* 0x5965: je     5af4 <generic_sleepable_preload+0x5af4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23284ULL;
	}
x86_l_596b:
	/* 0x596b: mov    ecx,DWORD PTR [rax+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_5971:
	/* 0x5971: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5975:
	/* 0x5975: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5979:
	/* 0x5979: cmp    WORD PTR [rax+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_5981:
	/* 0x5981: je     59a3 <generic_sleepable_preload+0x59a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_59a3;
	}
x86_l_5983:
	/* 0x5983: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5986:
	/* 0x5986: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_598b:
	/* 0x598b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5990:
	/* 0x5990: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5994:
	/* 0x5994: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5999:
	/* 0x5999: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_599b:
	/* 0x599b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_599d:
	/* 0x599d: js     5c35 <generic_sleepable_preload+0x5c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23605ULL;
	}
x86_l_59a3:
	/* 0x59a3: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_59a8:
	/* 0x59a8: cmp    WORD PTR [rax+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_59b0:
	/* 0x59b0: je     5af4 <generic_sleepable_preload+0x5af4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23284ULL;
	}
x86_l_59b6:
	/* 0x59b6: mov    ecx,DWORD PTR [rax+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_59bc:
	/* 0x59bc: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
	return 22976ULL;
}

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_13(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 22976ULL: goto x86_l_59c0;
	case 22980ULL: goto x86_l_59c4;
	case 22988ULL: goto x86_l_59cc;
	case 22994ULL: goto x86_l_59d2;
	case 22997ULL: goto x86_l_59d5;
	case 23002ULL: goto x86_l_59da;
	case 23007ULL: goto x86_l_59df;
	case 23011ULL: goto x86_l_59e3;
	case 23016ULL: goto x86_l_59e8;
	case 23018ULL: goto x86_l_59ea;
	case 23020ULL: goto x86_l_59ec;
	case 23026ULL: goto x86_l_59f2;
	case 23032ULL: goto x86_l_59f8;
	case 23037ULL: goto x86_l_59fd;
	case 23043ULL: goto x86_l_5a03;
	case 23048ULL: goto x86_l_5a08;
	case 23054ULL: goto x86_l_5a0e;
	case 23059ULL: goto x86_l_5a13;
	case 23065ULL: goto x86_l_5a19;
	case 23067ULL: goto x86_l_5a1b;
	case 23073ULL: goto x86_l_5a21;
	case 23078ULL: goto x86_l_5a26;
	case 23084ULL: goto x86_l_5a2c;
	case 23086ULL: goto x86_l_5a2e;
	case 23092ULL: goto x86_l_5a34;
	case 23097ULL: goto x86_l_5a39;
	case 23103ULL: goto x86_l_5a3f;
	case 23105ULL: goto x86_l_5a41;
	case 23111ULL: goto x86_l_5a47;
	case 23116ULL: goto x86_l_5a4c;
	case 23122ULL: goto x86_l_5a52;
	case 23124ULL: goto x86_l_5a54;
	case 23130ULL: goto x86_l_5a5a;
	case 23135ULL: goto x86_l_5a5f;
	case 23141ULL: goto x86_l_5a65;
	case 23144ULL: goto x86_l_5a68;
	case 23149ULL: goto x86_l_5a6d;
	case 23152ULL: goto x86_l_5a70;
	case 23155ULL: goto x86_l_5a73;
	case 23160ULL: goto x86_l_5a78;
	case 23165ULL: goto x86_l_5a7d;
	case 23170ULL: goto x86_l_5a82;
	case 23173ULL: goto x86_l_5a85;
	case 23175ULL: goto x86_l_5a87;
	case 23178ULL: goto x86_l_5a8a;
	case 23184ULL: goto x86_l_5a90;
	case 23188ULL: goto x86_l_5a94;
	case 23193ULL: goto x86_l_5a99;
	case 23195ULL: goto x86_l_5a9b;
	case 23200ULL: goto x86_l_5aa0;
	case 23208ULL: goto x86_l_5aa8;
	case 23215ULL: goto x86_l_5aaf;
	case 23220ULL: goto x86_l_5ab4;
	case 23225ULL: goto x86_l_5ab9;
	case 23227ULL: goto x86_l_5abb;
	case 23230ULL: goto x86_l_5abe;
	case 23236ULL: goto x86_l_5ac4;
	case 23239ULL: goto x86_l_5ac7;
	case 23246ULL: goto x86_l_5ace;
	case 23248ULL: goto x86_l_5ad0;
	case 23253ULL: goto x86_l_5ad5;
	case 23258ULL: goto x86_l_5ada;
	case 23261ULL: goto x86_l_5add;
	case 23264ULL: goto x86_l_5ae0;
	case 23266ULL: goto x86_l_5ae2;
	case 23268ULL: goto x86_l_5ae4;
	case 23273ULL: goto x86_l_5ae9;
	case 23275ULL: goto x86_l_5aeb;
	case 23281ULL: goto x86_l_5af1;
	case 23284ULL: goto x86_l_5af4;
	case 23287ULL: goto x86_l_5af7;
	case 23293ULL: goto x86_l_5afd;
	case 23297ULL: goto x86_l_5b01;
	case 23302ULL: goto x86_l_5b06;
	case 23304ULL: goto x86_l_5b08;
	case 23309ULL: goto x86_l_5b0d;
	case 23317ULL: goto x86_l_5b15;
	case 23324ULL: goto x86_l_5b1c;
	case 23329ULL: goto x86_l_5b21;
	case 23334ULL: goto x86_l_5b26;
	case 23336ULL: goto x86_l_5b28;
	case 23339ULL: goto x86_l_5b2b;
	case 23345ULL: goto x86_l_5b31;
	case 23348ULL: goto x86_l_5b34;
	case 23355ULL: goto x86_l_5b3b;
	case 23357ULL: goto x86_l_5b3d;
	case 23362ULL: goto x86_l_5b42;
	case 23367ULL: goto x86_l_5b47;
	case 23370ULL: goto x86_l_5b4a;
	case 23373ULL: goto x86_l_5b4d;
	case 23375ULL: goto x86_l_5b4f;
	case 23377ULL: goto x86_l_5b51;
	case 23382ULL: goto x86_l_5b56;
	case 23385ULL: goto x86_l_5b59;
	case 23388ULL: goto x86_l_5b5c;
	case 23390ULL: goto x86_l_5b5e;
	case 23393ULL: goto x86_l_5b61;
	case 23399ULL: goto x86_l_5b67;
	case 23402ULL: goto x86_l_5b6a;
	case 23404ULL: goto x86_l_5b6c;
	case 23407ULL: goto x86_l_5b6f;
	case 23411ULL: goto x86_l_5b73;
	case 23416ULL: goto x86_l_5b78;
	case 23419ULL: goto x86_l_5b7b;
	case 23421ULL: goto x86_l_5b7d;
	case 23424ULL: goto x86_l_5b80;
	case 23429ULL: goto x86_l_5b85;
	case 23431ULL: goto x86_l_5b87;
	case 23434ULL: goto x86_l_5b8a;
	case 23436ULL: goto x86_l_5b8c;
	case 23441ULL: goto x86_l_5b91;
	case 23445ULL: goto x86_l_5b95;
	case 23448ULL: goto x86_l_5b98;
	case 23453ULL: goto x86_l_5b9d;
	case 23456ULL: goto x86_l_5ba0;
	case 23462ULL: goto x86_l_5ba6;
	case 23467ULL: goto x86_l_5bab;
	case 23470ULL: goto x86_l_5bae;
	case 23476ULL: goto x86_l_5bb4;
	case 23479ULL: goto x86_l_5bb7;
	case 23485ULL: goto x86_l_5bbd;
	case 23490ULL: goto x86_l_5bc2;
	case 23493ULL: goto x86_l_5bc5;
	case 23498ULL: goto x86_l_5bca;
	case 23503ULL: goto x86_l_5bcf;
	case 23506ULL: goto x86_l_5bd2;
	case 23511ULL: goto x86_l_5bd7;
	case 23516ULL: goto x86_l_5bdc;
	case 23519ULL: goto x86_l_5bdf;
	case 23524ULL: goto x86_l_5be4;
	case 23529ULL: goto x86_l_5be9;
	case 23532ULL: goto x86_l_5bec;
	case 23537ULL: goto x86_l_5bf1;
	case 23542ULL: goto x86_l_5bf6;
	case 23545ULL: goto x86_l_5bf9;
	case 23550ULL: goto x86_l_5bfe;
	case 23555ULL: goto x86_l_5c03;
	case 23558ULL: goto x86_l_5c06;
	case 23563ULL: goto x86_l_5c0b;
	case 23568ULL: goto x86_l_5c10;
	case 23571ULL: goto x86_l_5c13;
	case 23576ULL: goto x86_l_5c18;
	case 23581ULL: goto x86_l_5c1d;
	case 23584ULL: goto x86_l_5c20;
	case 23589ULL: goto x86_l_5c25;
	case 23594ULL: goto x86_l_5c2a;
	case 23600ULL: goto x86_l_5c30;
	case 23605ULL: goto x86_l_5c35;
	case 23611ULL: goto x86_l_5c3b;
	case 23616ULL: goto x86_l_5c40;
	case 23619ULL: goto x86_l_5c43;
	case 23624ULL: goto x86_l_5c48;
	case 23629ULL: goto x86_l_5c4d;
	case 23632ULL: goto x86_l_5c50;
	case 23637ULL: goto x86_l_5c55;
	case 23642ULL: goto x86_l_5c5a;
	case 23645ULL: goto x86_l_5c5d;
	case 23650ULL: goto x86_l_5c62;
	case 23655ULL: goto x86_l_5c67;
	case 23658ULL: goto x86_l_5c6a;
	case 23663ULL: goto x86_l_5c6f;
	case 23668ULL: goto x86_l_5c74;
	case 23671ULL: goto x86_l_5c77;
	case 23676ULL: goto x86_l_5c7c;
	case 23681ULL: goto x86_l_5c81;
	case 23684ULL: goto x86_l_5c84;
	case 23689ULL: goto x86_l_5c89;
	case 23694ULL: goto x86_l_5c8e;
	case 23697ULL: goto x86_l_5c91;
	case 23702ULL: goto x86_l_5c96;
	case 23707ULL: goto x86_l_5c9b;
	case 23710ULL: goto x86_l_5c9e;
	case 23715ULL: goto x86_l_5ca3;
	case 23720ULL: goto x86_l_5ca8;
	case 23725ULL: goto x86_l_5cad;
	case 23728ULL: goto x86_l_5cb0;
	case 23733ULL: goto x86_l_5cb5;
	case 23738ULL: goto x86_l_5cba;
	case 23743ULL: goto x86_l_5cbf;
	case 23746ULL: goto x86_l_5cc2;
	case 23751ULL: goto x86_l_5cc7;
	case 23756ULL: goto x86_l_5ccc;
	case 23761ULL: goto x86_l_5cd1;
	case 23764ULL: goto x86_l_5cd4;
	case 23769ULL: goto x86_l_5cd9;
	case 23774ULL: goto x86_l_5cde;
	case 23779ULL: goto x86_l_5ce3;
	case 23782ULL: goto x86_l_5ce6;
	case 23787ULL: goto x86_l_5ceb;
	case 23792ULL: goto x86_l_5cf0;
	case 23797ULL: goto x86_l_5cf5;
	case 23800ULL: goto x86_l_5cf8;
	case 23805ULL: goto x86_l_5cfd;
	case 23810ULL: goto x86_l_5d02;
	case 23815ULL: goto x86_l_5d07;
	case 23818ULL: goto x86_l_5d0a;
	case 23823ULL: goto x86_l_5d0f;
	case 23828ULL: goto x86_l_5d14;
	case 23833ULL: goto x86_l_5d19;
	case 23836ULL: goto x86_l_5d1c;
	case 23841ULL: goto x86_l_5d21;
	case 23846ULL: goto x86_l_5d26;
	case 23851ULL: goto x86_l_5d2b;
	case 23854ULL: goto x86_l_5d2e;
	case 23859ULL: goto x86_l_5d33;
	case 23864ULL: goto x86_l_5d38;
	case 23869ULL: goto x86_l_5d3d;
	case 23872ULL: goto x86_l_5d40;
	case 23877ULL: goto x86_l_5d45;
	case 23880ULL: goto x86_l_5d48;
	case 23885ULL: goto x86_l_5d4d;
	case 23890ULL: goto x86_l_5d52;
	case 23893ULL: goto x86_l_5d55;
	case 23898ULL: goto x86_l_5d5a;
	case 23901ULL: goto x86_l_5d5d;
	case 23906ULL: goto x86_l_5d62;
	case 23911ULL: goto x86_l_5d67;
	case 23914ULL: goto x86_l_5d6a;
	case 23919ULL: goto x86_l_5d6f;
	case 23922ULL: goto x86_l_5d72;
	case 23927ULL: goto x86_l_5d77;
	case 23932ULL: goto x86_l_5d7c;
	case 23935ULL: goto x86_l_5d7f;
	case 23940ULL: goto x86_l_5d84;
	case 23943ULL: goto x86_l_5d87;
	case 23948ULL: goto x86_l_5d8c;
	case 23953ULL: goto x86_l_5d91;
	case 23956ULL: goto x86_l_5d94;
	case 23961ULL: goto x86_l_5d99;
	case 23964ULL: goto x86_l_5d9c;
	case 23969ULL: goto x86_l_5da1;
	case 23974ULL: goto x86_l_5da6;
	case 23977ULL: goto x86_l_5da9;
	case 23982ULL: goto x86_l_5dae;
	case 23985ULL: goto x86_l_5db1;
	case 23990ULL: goto x86_l_5db6;
	case 23995ULL: goto x86_l_5dbb;
	case 23998ULL: goto x86_l_5dbe;
	case 24003ULL: goto x86_l_5dc3;
	case 24006ULL: goto x86_l_5dc6;
	case 24011ULL: goto x86_l_5dcb;
	case 24016ULL: goto x86_l_5dd0;
	case 24019ULL: goto x86_l_5dd3;
	case 24024ULL: goto x86_l_5dd8;
	case 24027ULL: goto x86_l_5ddb;
	default: return 0xffffffffffffffffULL;
	}
x86_l_59c0:
	/* 0x59c0: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_59c4:
	/* 0x59c4: cmp    WORD PTR [rax+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_59cc:
	/* 0x59cc: je     5af4 <generic_sleepable_preload+0x5af4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5af4;
	}
x86_l_59d2:
	/* 0x59d2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_59d5:
	/* 0x59d5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_59da:
	/* 0x59da: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_59df:
	/* 0x59df: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_59e3:
	/* 0x59e3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_59e8:
	/* 0x59e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_59ea:
	/* 0x59ea: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_59ec:
	/* 0x59ec: jns    5af4 <generic_sleepable_preload+0x5af4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_5af4;
	}
x86_l_59f2:
	/* 0x59f2: mov    r12d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 10ULL);
x86_l_59f8:
	/* 0x59f8: jmp    5af1 <generic_sleepable_preload+0x5af1> */
	goto x86_l_5af1;
x86_l_59fd:
	/* 0x59fd: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_5a03:
	/* 0x5a03: jmp    5af1 <generic_sleepable_preload+0x5af1> */
	goto x86_l_5af1;
x86_l_5a08:
	/* 0x5a08: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_5a0e:
	/* 0x5a0e: jmp    5af1 <generic_sleepable_preload+0x5af1> */
	goto x86_l_5af1;
x86_l_5a13:
	/* 0x5a13: mov    r12d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 3ULL);
x86_l_5a19:
	/* 0x5a19: jmp    5a65 <generic_sleepable_preload+0x5a65> */
	goto x86_l_5a65;
x86_l_5a1b:
	/* 0x5a1b: mov    r12d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 3ULL);
x86_l_5a21:
	/* 0x5a21: jmp    5af1 <generic_sleepable_preload+0x5af1> */
	goto x86_l_5af1;
x86_l_5a26:
	/* 0x5a26: mov    r12d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4ULL);
x86_l_5a2c:
	/* 0x5a2c: jmp    5a65 <generic_sleepable_preload+0x5a65> */
	goto x86_l_5a65;
x86_l_5a2e:
	/* 0x5a2e: mov    r12d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4ULL);
x86_l_5a34:
	/* 0x5a34: jmp    5af1 <generic_sleepable_preload+0x5af1> */
	goto x86_l_5af1;
x86_l_5a39:
	/* 0x5a39: mov    r12d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 5ULL);
x86_l_5a3f:
	/* 0x5a3f: jmp    5a65 <generic_sleepable_preload+0x5a65> */
	goto x86_l_5a65;
x86_l_5a41:
	/* 0x5a41: mov    r12d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 5ULL);
x86_l_5a47:
	/* 0x5a47: jmp    5af1 <generic_sleepable_preload+0x5af1> */
	goto x86_l_5af1;
x86_l_5a4c:
	/* 0x5a4c: mov    r12d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 6ULL);
x86_l_5a52:
	/* 0x5a52: jmp    5a65 <generic_sleepable_preload+0x5a65> */
	goto x86_l_5a65;
x86_l_5a54:
	/* 0x5a54: mov    r12d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 6ULL);
x86_l_5a5a:
	/* 0x5a5a: jmp    5af1 <generic_sleepable_preload+0x5af1> */
	goto x86_l_5af1;
x86_l_5a5f:
	/* 0x5a5f: mov    r12d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 7ULL);
x86_l_5a65:
	/* 0x5a65: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5a68:
	/* 0x5a68: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a6d:
	/* 0x5a6d: mov    ebx,DWORD PTR [rax+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5a70:
	/* 0x5a70: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5a73:
	/* 0x5a73: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5a78:
	/* 0x5a78: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5a7d:
	/* 0x5a7d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5a82:
	/* 0x5a82: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_5a85:
	/* 0x5a85: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a87:
	/* 0x5a87: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_5a8a:
	/* 0x5a8a: jne    4c73 <generic_sleepable_preload+0x4c73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 19571ULL;
	}
x86_l_5a90:
	/* 0x5a90: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a94:
	/* 0x5a94: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_5a99:
	/* 0x5a99: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a9b:
	/* 0x5a9b: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5aa0:
	/* 0x5aa0: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_5aa8:
	/* 0x5aa8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_5aaf:
	/* 0x5aaf: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5ab4:
	/* 0x5ab4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5ab9:
	/* 0x5ab9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5abb:
	/* 0x5abb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5abe:
	/* 0x5abe: je     4c73 <generic_sleepable_preload+0x4c73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19571ULL;
	}
x86_l_5ac4:
	/* 0x5ac4: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_5ac7:
	/* 0x5ac7: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_5ace:
	/* 0x5ace: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5ad0:
	/* 0x5ad0: lea    r15,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5ad5:
	/* 0x5ad5: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5ada:
	/* 0x5ada: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_5add:
	/* 0x5add: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_5ae0:
	/* 0x5ae0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5ae2:
	/* 0x5ae2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ae4:
	/* 0x5ae4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5ae9:
	/* 0x5ae9: jmp    5b56 <generic_sleepable_preload+0x5b56> */
	goto x86_l_5b56;
x86_l_5aeb:
	/* 0x5aeb: mov    r12d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 7ULL);
x86_l_5af1:
	/* 0x5af1: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5af4:
	/* 0x5af4: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_5af7:
	/* 0x5af7: jne    4c73 <generic_sleepable_preload+0x4c73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 19571ULL;
	}
x86_l_5afd:
	/* 0x5afd: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b01:
	/* 0x5b01: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_5b06:
	/* 0x5b06: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b08:
	/* 0x5b08: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5b0d:
	/* 0x5b0d: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_5b15:
	/* 0x5b15: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_5b1c:
	/* 0x5b1c: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5b21:
	/* 0x5b21: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5b26:
	/* 0x5b26: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b28:
	/* 0x5b28: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5b2b:
	/* 0x5b2b: je     4c73 <generic_sleepable_preload+0x4c73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19571ULL;
	}
x86_l_5b31:
	/* 0x5b31: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_5b34:
	/* 0x5b34: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_5b3b:
	/* 0x5b3b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5b3d:
	/* 0x5b3d: lea    r15,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5b42:
	/* 0x5b42: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5b47:
	/* 0x5b47: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_5b4a:
	/* 0x5b4a: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_5b4d:
	/* 0x5b4d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5b4f:
	/* 0x5b4f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b51:
	/* 0x5b51: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5b56:
	/* 0x5b56: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_5b59:
	/* 0x5b59: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_5b5c:
	/* 0x5b5c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b5e:
	/* 0x5b5e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5b61:
	/* 0x5b61: je     4c73 <generic_sleepable_preload+0x4c73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19571ULL;
	}
x86_l_5b67:
	/* 0x5b67: test   r13b,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_8);
x86_l_5b6a:
	/* 0x5b6a: je     5b95 <generic_sleepable_preload+0x5b95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5b95;
	}
x86_l_5b6c:
	/* 0x5b6c: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_5b6f:
	/* 0x5b6f: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_5b73:
	/* 0x5b73: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5b78:
	/* 0x5b78: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_5b7b:
	/* 0x5b7b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5b7d:
	/* 0x5b7d: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_5b80:
	/* 0x5b80: call   5b85 <generic_sleepable_preload+0x5b85> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_5b85:
	/* 0x5b85: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_5b87:
	/* 0x5b87: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_5b8a:
	/* 0x5b8a: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_5b8c:
	/* 0x5b8c: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_5b91:
	/* 0x5b91: cmovs  r12d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_5b95:
	/* 0x5b95: mov    DWORD PTR [rax],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b98:
	/* 0x5b98: jmp    4c73 <generic_sleepable_preload+0x4c73> */
	return 19571ULL;
x86_l_5b9d:
	/* 0x5b9d: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5ba0:
	/* 0x5ba0: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_5ba6:
	/* 0x5ba6: jmp    5a68 <generic_sleepable_preload+0x5a68> */
	goto x86_l_5a68;
x86_l_5bab:
	/* 0x5bab: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5bae:
	/* 0x5bae: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_5bb4:
	/* 0x5bb4: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_5bb7:
	/* 0x5bb7: jne    4c73 <generic_sleepable_preload+0x4c73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 19571ULL;
	}
x86_l_5bbd:
	/* 0x5bbd: jmp    5afd <generic_sleepable_preload+0x5afd> */
	goto x86_l_5afd;
x86_l_5bc2:
	/* 0x5bc2: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5bc5:
	/* 0x5bc5: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5bca:
	/* 0x5bca: jmp    1cf7 <generic_sleepable_preload+0x1cf7> */
	return 7415ULL;
x86_l_5bcf:
	/* 0x5bcf: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5bd2:
	/* 0x5bd2: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5bd7:
	/* 0x5bd7: jmp    1d82 <generic_sleepable_preload+0x1d82> */
	return 7554ULL;
x86_l_5bdc:
	/* 0x5bdc: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5bdf:
	/* 0x5bdf: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5be4:
	/* 0x5be4: jmp    2c61 <generic_sleepable_preload+0x2c61> */
	return 11361ULL;
x86_l_5be9:
	/* 0x5be9: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5bec:
	/* 0x5bec: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5bf1:
	/* 0x5bf1: jmp    2cec <generic_sleepable_preload+0x2cec> */
	return 11500ULL;
x86_l_5bf6:
	/* 0x5bf6: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5bf9:
	/* 0x5bf9: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5bfe:
	/* 0x5bfe: jmp    3bcc <generic_sleepable_preload+0x3bcc> */
	return 15308ULL;
x86_l_5c03:
	/* 0x5c03: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c06:
	/* 0x5c06: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5c0b:
	/* 0x5c0b: jmp    3c57 <generic_sleepable_preload+0x3c57> */
	return 15447ULL;
x86_l_5c10:
	/* 0x5c10: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c13:
	/* 0x5c13: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5c18:
	/* 0x5c18: jmp    4b37 <generic_sleepable_preload+0x4b37> */
	return 19255ULL;
x86_l_5c1d:
	/* 0x5c1d: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c20:
	/* 0x5c20: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5c25:
	/* 0x5c25: jmp    4bc2 <generic_sleepable_preload+0x4bc2> */
	return 19394ULL;
x86_l_5c2a:
	/* 0x5c2a: mov    r12d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 9ULL);
x86_l_5c30:
	/* 0x5c30: jmp    5a65 <generic_sleepable_preload+0x5a65> */
	goto x86_l_5a65;
x86_l_5c35:
	/* 0x5c35: mov    r12d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 9ULL);
x86_l_5c3b:
	/* 0x5c3b: jmp    5af1 <generic_sleepable_preload+0x5af1> */
	goto x86_l_5af1;
x86_l_5c40:
	/* 0x5c40: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c43:
	/* 0x5c43: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5c48:
	/* 0x5c48: jmp    5d40 <generic_sleepable_preload+0x5d40> */
	goto x86_l_5d40;
x86_l_5c4d:
	/* 0x5c4d: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c50:
	/* 0x5c50: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5c55:
	/* 0x5c55: jmp    5d55 <generic_sleepable_preload+0x5d55> */
	goto x86_l_5d55;
x86_l_5c5a:
	/* 0x5c5a: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c5d:
	/* 0x5c5d: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5c62:
	/* 0x5c62: jmp    5d6a <generic_sleepable_preload+0x5d6a> */
	goto x86_l_5d6a;
x86_l_5c67:
	/* 0x5c67: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c6a:
	/* 0x5c6a: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5c6f:
	/* 0x5c6f: jmp    5d7f <generic_sleepable_preload+0x5d7f> */
	goto x86_l_5d7f;
x86_l_5c74:
	/* 0x5c74: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c77:
	/* 0x5c77: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5c7c:
	/* 0x5c7c: jmp    5d94 <generic_sleepable_preload+0x5d94> */
	goto x86_l_5d94;
x86_l_5c81:
	/* 0x5c81: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c84:
	/* 0x5c84: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5c89:
	/* 0x5c89: jmp    5da9 <generic_sleepable_preload+0x5da9> */
	goto x86_l_5da9;
x86_l_5c8e:
	/* 0x5c8e: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c91:
	/* 0x5c91: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5c96:
	/* 0x5c96: jmp    5dbe <generic_sleepable_preload+0x5dbe> */
	goto x86_l_5dbe;
x86_l_5c9b:
	/* 0x5c9b: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c9e:
	/* 0x5c9e: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5ca3:
	/* 0x5ca3: jmp    5dd3 <generic_sleepable_preload+0x5dd3> */
	goto x86_l_5dd3;
x86_l_5ca8:
	/* 0x5ca8: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5cad:
	/* 0x5cad: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5cb0:
	/* 0x5cb0: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5cb5:
	/* 0x5cb5: jmp    1cf7 <generic_sleepable_preload+0x1cf7> */
	return 7415ULL;
x86_l_5cba:
	/* 0x5cba: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5cbf:
	/* 0x5cbf: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5cc2:
	/* 0x5cc2: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5cc7:
	/* 0x5cc7: jmp    1d82 <generic_sleepable_preload+0x1d82> */
	return 7554ULL;
x86_l_5ccc:
	/* 0x5ccc: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5cd1:
	/* 0x5cd1: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5cd4:
	/* 0x5cd4: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5cd9:
	/* 0x5cd9: jmp    2c61 <generic_sleepable_preload+0x2c61> */
	return 11361ULL;
x86_l_5cde:
	/* 0x5cde: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5ce3:
	/* 0x5ce3: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5ce6:
	/* 0x5ce6: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ceb:
	/* 0x5ceb: jmp    2cec <generic_sleepable_preload+0x2cec> */
	return 11500ULL;
x86_l_5cf0:
	/* 0x5cf0: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5cf5:
	/* 0x5cf5: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5cf8:
	/* 0x5cf8: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5cfd:
	/* 0x5cfd: jmp    3bcc <generic_sleepable_preload+0x3bcc> */
	return 15308ULL;
x86_l_5d02:
	/* 0x5d02: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5d07:
	/* 0x5d07: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5d0a:
	/* 0x5d0a: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d0f:
	/* 0x5d0f: jmp    3c57 <generic_sleepable_preload+0x3c57> */
	return 15447ULL;
x86_l_5d14:
	/* 0x5d14: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5d19:
	/* 0x5d19: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5d1c:
	/* 0x5d1c: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d21:
	/* 0x5d21: jmp    4b37 <generic_sleepable_preload+0x4b37> */
	return 19255ULL;
x86_l_5d26:
	/* 0x5d26: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5d2b:
	/* 0x5d2b: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5d2e:
	/* 0x5d2e: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d33:
	/* 0x5d33: jmp    4bc2 <generic_sleepable_preload+0x4bc2> */
	return 19394ULL;
x86_l_5d38:
	/* 0x5d38: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5d3d:
	/* 0x5d3d: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5d40:
	/* 0x5d40: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d45:
	/* 0x5d45: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_5d48:
	/* 0x5d48: jmp    1cf7 <generic_sleepable_preload+0x1cf7> */
	return 7415ULL;
x86_l_5d4d:
	/* 0x5d4d: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5d52:
	/* 0x5d52: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5d55:
	/* 0x5d55: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d5a:
	/* 0x5d5a: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_5d5d:
	/* 0x5d5d: jmp    1d82 <generic_sleepable_preload+0x1d82> */
	return 7554ULL;
x86_l_5d62:
	/* 0x5d62: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5d67:
	/* 0x5d67: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5d6a:
	/* 0x5d6a: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d6f:
	/* 0x5d6f: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_5d72:
	/* 0x5d72: jmp    2c61 <generic_sleepable_preload+0x2c61> */
	return 11361ULL;
x86_l_5d77:
	/* 0x5d77: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5d7c:
	/* 0x5d7c: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5d7f:
	/* 0x5d7f: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d84:
	/* 0x5d84: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_5d87:
	/* 0x5d87: jmp    2cec <generic_sleepable_preload+0x2cec> */
	return 11500ULL;
x86_l_5d8c:
	/* 0x5d8c: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5d91:
	/* 0x5d91: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5d94:
	/* 0x5d94: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d99:
	/* 0x5d99: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_5d9c:
	/* 0x5d9c: jmp    3bcc <generic_sleepable_preload+0x3bcc> */
	return 15308ULL;
x86_l_5da1:
	/* 0x5da1: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5da6:
	/* 0x5da6: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5da9:
	/* 0x5da9: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5dae:
	/* 0x5dae: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_5db1:
	/* 0x5db1: jmp    3c57 <generic_sleepable_preload+0x3c57> */
	return 15447ULL;
x86_l_5db6:
	/* 0x5db6: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5dbb:
	/* 0x5dbb: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5dbe:
	/* 0x5dbe: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5dc3:
	/* 0x5dc3: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_5dc6:
	/* 0x5dc6: jmp    4b37 <generic_sleepable_preload+0x4b37> */
	return 19255ULL;
x86_l_5dcb:
	/* 0x5dcb: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5dd0:
	/* 0x5dd0: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5dd3:
	/* 0x5dd3: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5dd8:
	/* 0x5dd8: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_5ddb:
	/* 0x5ddb: jmp    4bc2 <generic_sleepable_preload+0x4bc2> */
	return 19394ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 20948U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1643ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1647ULL && __x86_pc <= 3190ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3196ULL && __x86_pc <= 4936ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 4939ULL && __x86_pc <= 6771ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 6775ULL && __x86_pc <= 8522ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8524ULL && __x86_pc <= 10392ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10396ULL && __x86_pc <= 12146ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12151ULL && __x86_pc <= 14007ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 14017ULL && __x86_pc <= 15800ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_8(__x86_state, __x86_pc);
		else if (__x86_pc >= 15803ULL && __x86_pc <= 17641ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_9(__x86_state, __x86_pc);
		else if (__x86_pc >= 17647ULL && __x86_pc <= 19494ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_10(__x86_state, __x86_pc);
		else if (__x86_pc >= 19497ULL && __x86_pc <= 21218ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_11(__x86_state, __x86_pc);
		else if (__x86_pc >= 21223ULL && __x86_pc <= 22972ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_12(__x86_state, __x86_pc);
		else if (__x86_pc >= 22976ULL && __x86_pc <= 24027ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_13(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

extern char config_map;
extern char policy_filter_maps;
extern char process_call_heap;
extern char tg_cgtracker_map;
extern char tg_conf_map;
extern char tg_errmetrics_map;
extern char tp_calls;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_generic_tracepoint_v53_generic_tracepoint_event_x86_chunk_0(
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
	case 73ULL: goto x86_l_49;
	case 78ULL: goto x86_l_4e;
	case 80ULL: goto x86_l_50;
	case 83ULL: goto x86_l_53;
	case 89ULL: goto x86_l_59;
	case 92ULL: goto x86_l_5c;
	case 95ULL: goto x86_l_5f;
	case 99ULL: goto x86_l_63;
	case 101ULL: goto x86_l_65;
	case 107ULL: goto x86_l_6b;
	case 114ULL: goto x86_l_72;
	case 119ULL: goto x86_l_77;
	case 124ULL: goto x86_l_7c;
	case 126ULL: goto x86_l_7e;
	case 129ULL: goto x86_l_81;
	case 135ULL: goto x86_l_87;
	case 138ULL: goto x86_l_8a;
	case 149ULL: goto x86_l_95;
	case 156ULL: goto x86_l_9c;
	case 164ULL: goto x86_l_a4;
	case 169ULL: goto x86_l_a9;
	case 171ULL: goto x86_l_ab;
	case 174ULL: goto x86_l_ae;
	case 176ULL: goto x86_l_b0;
	case 184ULL: goto x86_l_b8;
	case 186ULL: goto x86_l_ba;
	case 191ULL: goto x86_l_bf;
	case 193ULL: goto x86_l_c1;
	case 198ULL: goto x86_l_c6;
	case 201ULL: goto x86_l_c9;
	case 207ULL: goto x86_l_cf;
	case 212ULL: goto x86_l_d4;
	case 214ULL: goto x86_l_d6;
	case 216ULL: goto x86_l_d8;
	case 219ULL: goto x86_l_db;
	case 224ULL: goto x86_l_e0;
	case 226ULL: goto x86_l_e2;
	case 235ULL: goto x86_l_eb;
	case 242ULL: goto x86_l_f2;
	case 247ULL: goto x86_l_f7;
	case 252ULL: goto x86_l_fc;
	case 257ULL: goto x86_l_101;
	case 262ULL: goto x86_l_106;
	case 264ULL: goto x86_l_108;
	case 269ULL: goto x86_l_10d;
	case 272ULL: goto x86_l_110;
	case 274ULL: goto x86_l_112;
	case 277ULL: goto x86_l_115;
	case 279ULL: goto x86_l_117;
	case 281ULL: goto x86_l_119;
	case 285ULL: goto x86_l_11d;
	case 290ULL: goto x86_l_122;
	case 295ULL: goto x86_l_127;
	case 300ULL: goto x86_l_12c;
	case 304ULL: goto x86_l_130;
	case 309ULL: goto x86_l_135;
	case 314ULL: goto x86_l_13a;
	case 316ULL: goto x86_l_13c;
	case 321ULL: goto x86_l_141;
	case 324ULL: goto x86_l_144;
	case 326ULL: goto x86_l_146;
	case 331ULL: goto x86_l_14b;
	case 336ULL: goto x86_l_150;
	case 341ULL: goto x86_l_155;
	case 346ULL: goto x86_l_15a;
	case 351ULL: goto x86_l_15f;
	case 353ULL: goto x86_l_161;
	case 358ULL: goto x86_l_166;
	case 361ULL: goto x86_l_169;
	case 367ULL: goto x86_l_16f;
	case 376ULL: goto x86_l_178;
	case 383ULL: goto x86_l_17f;
	case 388ULL: goto x86_l_184;
	case 393ULL: goto x86_l_189;
	case 398ULL: goto x86_l_18e;
	case 403ULL: goto x86_l_193;
	case 405ULL: goto x86_l_195;
	case 410ULL: goto x86_l_19a;
	case 419ULL: goto x86_l_1a3;
	case 422ULL: goto x86_l_1a6;
	case 424ULL: goto x86_l_1a8;
	case 428ULL: goto x86_l_1ac;
	case 433ULL: goto x86_l_1b1;
	case 438ULL: goto x86_l_1b6;
	case 443ULL: goto x86_l_1bb;
	case 448ULL: goto x86_l_1c0;
	case 450ULL: goto x86_l_1c2;
	case 455ULL: goto x86_l_1c7;
	case 460ULL: goto x86_l_1cc;
	case 463ULL: goto x86_l_1cf;
	case 465ULL: goto x86_l_1d1;
	case 470ULL: goto x86_l_1d6;
	case 472ULL: goto x86_l_1d8;
	case 477ULL: goto x86_l_1dd;
	case 480ULL: goto x86_l_1e0;
	case 486ULL: goto x86_l_1e6;
	case 491ULL: goto x86_l_1eb;
	case 498ULL: goto x86_l_1f2;
	case 503ULL: goto x86_l_1f7;
	case 508ULL: goto x86_l_1fc;
	case 510ULL: goto x86_l_1fe;
	case 513ULL: goto x86_l_201;
	case 515ULL: goto x86_l_203;
	case 518ULL: goto x86_l_206;
	case 523ULL: goto x86_l_20b;
	case 526ULL: goto x86_l_20e;
	case 528ULL: goto x86_l_210;
	case 533ULL: goto x86_l_215;
	case 535ULL: goto x86_l_217;
	case 544ULL: goto x86_l_220;
	case 549ULL: goto x86_l_225;
	case 554ULL: goto x86_l_22a;
	case 557ULL: goto x86_l_22d;
	case 559ULL: goto x86_l_22f;
	case 562ULL: goto x86_l_232;
	case 568ULL: goto x86_l_238;
	case 579ULL: goto x86_l_243;
	case 582ULL: goto x86_l_246;
	case 586ULL: goto x86_l_24a;
	case 594ULL: goto x86_l_252;
	case 599ULL: goto x86_l_257;
	case 603ULL: goto x86_l_25b;
	case 606ULL: goto x86_l_25e;
	case 609ULL: goto x86_l_261;
	case 613ULL: goto x86_l_265;
	case 615ULL: goto x86_l_267;
	case 619ULL: goto x86_l_26b;
	case 625ULL: goto x86_l_271;
	case 629ULL: goto x86_l_275;
	case 635ULL: goto x86_l_27b;
	case 639ULL: goto x86_l_27f;
	case 645ULL: goto x86_l_285;
	case 649ULL: goto x86_l_289;
	case 655ULL: goto x86_l_28f;
	case 659ULL: goto x86_l_293;
	case 665ULL: goto x86_l_299;
	case 670ULL: goto x86_l_29e;
	case 674ULL: goto x86_l_2a2;
	case 680ULL: goto x86_l_2a8;
	case 684ULL: goto x86_l_2ac;
	case 690ULL: goto x86_l_2b2;
	case 694ULL: goto x86_l_2b6;
	case 700ULL: goto x86_l_2bc;
	case 704ULL: goto x86_l_2c0;
	case 710ULL: goto x86_l_2c6;
	case 714ULL: goto x86_l_2ca;
	case 720ULL: goto x86_l_2d0;
	case 725ULL: goto x86_l_2d5;
	case 730ULL: goto x86_l_2da;
	case 735ULL: goto x86_l_2df;
	case 740ULL: goto x86_l_2e4;
	case 742ULL: goto x86_l_2e6;
	case 745ULL: goto x86_l_2e9;
	case 751ULL: goto x86_l_2ef;
	case 753ULL: goto x86_l_2f1;
	case 758ULL: goto x86_l_2f6;
	case 765ULL: goto x86_l_2fd;
	case 775ULL: goto x86_l_307;
	case 780ULL: goto x86_l_30c;
	case 787ULL: goto x86_l_313;
	case 792ULL: goto x86_l_318;
	case 797ULL: goto x86_l_31d;
	case 799ULL: goto x86_l_31f;
	case 802ULL: goto x86_l_322;
	case 808ULL: goto x86_l_328;
	case 810ULL: goto x86_l_32a;
	case 815ULL: goto x86_l_32f;
	case 819ULL: goto x86_l_333;
	case 825ULL: goto x86_l_339;
	case 829ULL: goto x86_l_33d;
	case 832ULL: goto x86_l_340;
	case 838ULL: goto x86_l_346;
	case 842ULL: goto x86_l_34a;
	case 848ULL: goto x86_l_350;
	case 853ULL: goto x86_l_355;
	case 858ULL: goto x86_l_35a;
	case 863ULL: goto x86_l_35f;
	case 868ULL: goto x86_l_364;
	case 870ULL: goto x86_l_366;
	case 873ULL: goto x86_l_369;
	case 879ULL: goto x86_l_36f;
	case 881ULL: goto x86_l_371;
	case 886ULL: goto x86_l_376;
	case 893ULL: goto x86_l_37d;
	case 903ULL: goto x86_l_387;
	case 908ULL: goto x86_l_38c;
	case 915ULL: goto x86_l_393;
	case 920ULL: goto x86_l_398;
	case 925ULL: goto x86_l_39d;
	case 927ULL: goto x86_l_39f;
	case 930ULL: goto x86_l_3a2;
	case 936ULL: goto x86_l_3a8;
	case 944ULL: goto x86_l_3b0;
	case 951ULL: goto x86_l_3b7;
	case 953ULL: goto x86_l_3b9;
	case 958ULL: goto x86_l_3be;
	case 963ULL: goto x86_l_3c3;
	case 968ULL: goto x86_l_3c8;
	case 973ULL: goto x86_l_3cd;
	case 977ULL: goto x86_l_3d1;
	case 983ULL: goto x86_l_3d7;
	case 987ULL: goto x86_l_3db;
	case 993ULL: goto x86_l_3e1;
	case 997ULL: goto x86_l_3e5;
	case 1003ULL: goto x86_l_3eb;
	case 1007ULL: goto x86_l_3ef;
	case 1013ULL: goto x86_l_3f5;
	case 1018ULL: goto x86_l_3fa;
	case 1023ULL: goto x86_l_3ff;
	case 1028ULL: goto x86_l_404;
	case 1033ULL: goto x86_l_409;
	case 1035ULL: goto x86_l_40b;
	case 1038ULL: goto x86_l_40e;
	case 1044ULL: goto x86_l_414;
	case 1046ULL: goto x86_l_416;
	case 1051ULL: goto x86_l_41b;
	case 1058ULL: goto x86_l_422;
	case 1068ULL: goto x86_l_42c;
	case 1073ULL: goto x86_l_431;
	case 1080ULL: goto x86_l_438;
	case 1085ULL: goto x86_l_43d;
	case 1090ULL: goto x86_l_442;
	case 1092ULL: goto x86_l_444;
	case 1095ULL: goto x86_l_447;
	case 1101ULL: goto x86_l_44d;
	case 1103ULL: goto x86_l_44f;
	case 1109ULL: goto x86_l_455;
	case 1114ULL: goto x86_l_45a;
	case 1123ULL: goto x86_l_463;
	case 1128ULL: goto x86_l_468;
	case 1133ULL: goto x86_l_46d;
	case 1136ULL: goto x86_l_470;
	case 1138ULL: goto x86_l_472;
	case 1141ULL: goto x86_l_475;
	case 1147ULL: goto x86_l_47b;
	case 1155ULL: goto x86_l_483;
	case 1162ULL: goto x86_l_48a;
	case 1167ULL: goto x86_l_48f;
	case 1172ULL: goto x86_l_494;
	case 1174ULL: goto x86_l_496;
	case 1177ULL: goto x86_l_499;
	case 1183ULL: goto x86_l_49f;
	case 1186ULL: goto x86_l_4a2;
	case 1191ULL: goto x86_l_4a7;
	case 1196ULL: goto x86_l_4ac;
	case 1198ULL: goto x86_l_4ae;
	case 1201ULL: goto x86_l_4b1;
	case 1207ULL: goto x86_l_4b7;
	case 1212ULL: goto x86_l_4bc;
	case 1216ULL: goto x86_l_4c0;
	case 1219ULL: goto x86_l_4c3;
	case 1225ULL: goto x86_l_4c9;
	case 1230ULL: goto x86_l_4ce;
	case 1235ULL: goto x86_l_4d3;
	case 1240ULL: goto x86_l_4d8;
	case 1245ULL: goto x86_l_4dd;
	case 1247ULL: goto x86_l_4df;
	case 1250ULL: goto x86_l_4e2;
	case 1256ULL: goto x86_l_4e8;
	case 1258ULL: goto x86_l_4ea;
	case 1263ULL: goto x86_l_4ef;
	case 1270ULL: goto x86_l_4f6;
	case 1280ULL: goto x86_l_500;
	case 1285ULL: goto x86_l_505;
	case 1292ULL: goto x86_l_50c;
	case 1297ULL: goto x86_l_511;
	case 1302ULL: goto x86_l_516;
	case 1304ULL: goto x86_l_518;
	case 1307ULL: goto x86_l_51b;
	case 1313ULL: goto x86_l_521;
	case 1315ULL: goto x86_l_523;
	case 1320ULL: goto x86_l_528;
	case 1324ULL: goto x86_l_52c;
	case 1330ULL: goto x86_l_532;
	case 1334ULL: goto x86_l_536;
	case 1340ULL: goto x86_l_53c;
	case 1344ULL: goto x86_l_540;
	case 1350ULL: goto x86_l_546;
	case 1355ULL: goto x86_l_54b;
	case 1360ULL: goto x86_l_550;
	case 1365ULL: goto x86_l_555;
	case 1370ULL: goto x86_l_55a;
	case 1372ULL: goto x86_l_55c;
	case 1375ULL: goto x86_l_55f;
	case 1381ULL: goto x86_l_565;
	case 1383ULL: goto x86_l_567;
	case 1388ULL: goto x86_l_56c;
	case 1395ULL: goto x86_l_573;
	case 1405ULL: goto x86_l_57d;
	case 1410ULL: goto x86_l_582;
	case 1417ULL: goto x86_l_589;
	case 1422ULL: goto x86_l_58e;
	case 1427ULL: goto x86_l_593;
	case 1429ULL: goto x86_l_595;
	case 1432ULL: goto x86_l_598;
	case 1438ULL: goto x86_l_59e;
	case 1446ULL: goto x86_l_5a6;
	case 1453ULL: goto x86_l_5ad;
	case 1455ULL: goto x86_l_5af;
	case 1460ULL: goto x86_l_5b4;
	case 1465ULL: goto x86_l_5b9;
	case 1470ULL: goto x86_l_5be;
	case 1475ULL: goto x86_l_5c3;
	case 1479ULL: goto x86_l_5c7;
	case 1485ULL: goto x86_l_5cd;
	case 1489ULL: goto x86_l_5d1;
	case 1491ULL: goto x86_l_5d3;
	case 1496ULL: goto x86_l_5d8;
	case 1500ULL: goto x86_l_5dc;
	case 1506ULL: goto x86_l_5e2;
	case 1510ULL: goto x86_l_5e6;
	case 1516ULL: goto x86_l_5ec;
	case 1521ULL: goto x86_l_5f1;
	case 1526ULL: goto x86_l_5f6;
	case 1531ULL: goto x86_l_5fb;
	case 1536ULL: goto x86_l_600;
	case 1538ULL: goto x86_l_602;
	case 1541ULL: goto x86_l_605;
	case 1547ULL: goto x86_l_60b;
	case 1549ULL: goto x86_l_60d;
	case 1554ULL: goto x86_l_612;
	case 1561ULL: goto x86_l_619;
	case 1571ULL: goto x86_l_623;
	case 1576ULL: goto x86_l_628;
	case 1583ULL: goto x86_l_62f;
	case 1588ULL: goto x86_l_634;
	case 1593ULL: goto x86_l_639;
	case 1595ULL: goto x86_l_63b;
	case 1598ULL: goto x86_l_63e;
	case 1604ULL: goto x86_l_644;
	case 1612ULL: goto x86_l_64c;
	case 1619ULL: goto x86_l_653;
	case 1621ULL: goto x86_l_655;
	case 1626ULL: goto x86_l_65a;
	case 1631ULL: goto x86_l_65f;
	case 1636ULL: goto x86_l_664;
	case 1641ULL: goto x86_l_669;
	case 1646ULL: goto x86_l_66e;
	case 1651ULL: goto x86_l_673;
	case 1656ULL: goto x86_l_678;
	case 1661ULL: goto x86_l_67d;
	case 1663ULL: goto x86_l_67f;
	case 1666ULL: goto x86_l_682;
	case 1672ULL: goto x86_l_688;
	case 1674ULL: goto x86_l_68a;
	case 1679ULL: goto x86_l_68f;
	case 1686ULL: goto x86_l_696;
	case 1696ULL: goto x86_l_6a0;
	case 1701ULL: goto x86_l_6a5;
	case 1708ULL: goto x86_l_6ac;
	case 1713ULL: goto x86_l_6b1;
	case 1718ULL: goto x86_l_6b6;
	case 1720ULL: goto x86_l_6b8;
	case 1723ULL: goto x86_l_6bb;
	case 1729ULL: goto x86_l_6c1;
	case 1731ULL: goto x86_l_6c3;
	case 1736ULL: goto x86_l_6c8;
	case 1741ULL: goto x86_l_6cd;
	case 1749ULL: goto x86_l_6d5;
	case 1756ULL: goto x86_l_6dc;
	case 1758ULL: goto x86_l_6de;
	case 1763ULL: goto x86_l_6e3;
	case 1768ULL: goto x86_l_6e8;
	case 1773ULL: goto x86_l_6ed;
	case 1775ULL: goto x86_l_6ef;
	case 1777ULL: goto x86_l_6f1;
	case 1782ULL: goto x86_l_6f6;
	case 1786ULL: goto x86_l_6fa;
	case 1792ULL: goto x86_l_700;
	case 1797ULL: goto x86_l_705;
	default: return 0xffffffffffffffffULL;
	}
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 136ULL);
x86_l_a:
	/* 0xa: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_18:
	/* 0x18: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_1f:
	/* 0x1f: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
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
	/* 0x31: je     3300 <generic_tracepoint_event+0x3300> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13056ULL;
	}
x86_l_37:
	/* 0x37: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_3a:
	/* 0x3a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_41:
	/* 0x41: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_49:
	/* 0x49: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4e:
	/* 0x4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50:
	/* 0x50: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_53:
	/* 0x53: je     3300 <generic_tracepoint_event+0x3300> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13056ULL;
	}
x86_l_59:
	/* 0x59: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_5c:
	/* 0x5c: mov    eax,DWORD PTR [rax+0x64] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_5f:
	/* 0x5f: mov    DWORD PTR [rsp+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_63:
	/* 0x63: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_65:
	/* 0x65: je     238 <generic_tracepoint_event+0x238> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_238;
	}
x86_l_6b:
	/* 0x6b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_filter_maps)));
x86_l_72:
	/* 0x72: lea    rsi,[rsp+0x7c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_77:
	/* 0x77: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7c:
	/* 0x7c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7e:
	/* 0x7e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_81:
	/* 0x81: je     3300 <generic_tracepoint_event+0x3300> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13056ULL;
	}
x86_l_87:
	/* 0x87: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_8a:
	/* 0x8a: mov    DWORD PTR [rsp+0x84],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_95:
	/* 0x95: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_conf_map)));
x86_l_9c:
	/* 0x9c: lea    rsi,[rsp+0x84] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_a4:
	/* 0xa4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a9:
	/* 0xa9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ab:
	/* 0xab: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ae:
	/* 0xae: je     d4 <generic_tracepoint_event+0xd4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d4;
	}
x86_l_b0:
	/* 0xb0: cmp    QWORD PTR [rax+0x20],0x63677270 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 139106677360ULL);
x86_l_b8:
	/* 0xb8: jne    d8 <generic_tracepoint_event+0xd8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_d8;
	}
x86_l_ba:
	/* 0xba: mov    eax,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 80ULL);
x86_l_bf:
	/* 0xbf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c1:
	/* 0xc1: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_c6:
	/* 0xc6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c9:
	/* 0xc9: jne    1e6 <generic_tracepoint_event+0x1e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e6;
	}
x86_l_cf:
	/* 0xcf: jmp    3300 <generic_tracepoint_event+0x3300> */
	return 13056ULL;
x86_l_d4:
	/* 0xd4: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d6:
	/* 0xd6: jmp    db <generic_tracepoint_event+0xdb> */
	goto x86_l_db;
x86_l_d8:
	/* 0xd8: mov    ebp,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_db:
	/* 0xdb: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_e0:
	/* 0xe0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e2:
	/* 0xe2: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_eb:
	/* 0xeb: lea    rdx,[rax+0xf60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3936ULL);
x86_l_f2:
	/* 0xf2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f7:
	/* 0xf7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_fc:
	/* 0xfc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_101:
	/* 0x101: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_106:
	/* 0x106: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_108:
	/* 0x108: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10d:
	/* 0x10d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_110:
	/* 0x110: je     161 <generic_tracepoint_event+0x161> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_161;
	}
x86_l_112:
	/* 0x112: cmp    ebp,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 11ULL);
x86_l_115:
	/* 0x115: ja     161 <generic_tracepoint_event+0x161> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_161;
	}
x86_l_117:
	/* 0x117: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_119:
	/* 0x119: lea    rcx,[rax+rdx*8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 3), 0ULL);
x86_l_11d:
	/* 0x11d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_122:
	/* 0x122: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_127:
	/* 0x127: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_12c:
	/* 0x12c: shl    rdx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHL, 3ULL);
x86_l_130:
	/* 0x130: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_135:
	/* 0x135: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_13a:
	/* 0x13a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13c:
	/* 0x13c: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_141:
	/* 0x141: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_144:
	/* 0x144: je     161 <generic_tracepoint_event+0x161> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_161;
	}
x86_l_146:
	/* 0x146: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14b:
	/* 0x14b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_150:
	/* 0x150: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_155:
	/* 0x155: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15a:
	/* 0x15a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_15f:
	/* 0x15f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_161:
	/* 0x161: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_166:
	/* 0x166: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_169:
	/* 0x169: je     3300 <generic_tracepoint_event+0x3300> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13056ULL;
	}
x86_l_16f:
	/* 0x16f: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_178:
	/* 0x178: add    rdx,0x100 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 256ULL);
x86_l_17f:
	/* 0x17f: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_184:
	/* 0x184: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_189:
	/* 0x189: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_18e:
	/* 0x18e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_193:
	/* 0x193: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_195:
	/* 0x195: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_19a:
	/* 0x19a: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1a3:
	/* 0x1a3: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1a6:
	/* 0x1a6: je     1d6 <generic_tracepoint_event+0x1d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d6;
	}
x86_l_1a8:
	/* 0x1a8: add    rdx,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_1ac:
	/* 0x1ac: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b1:
	/* 0x1b1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1b6:
	/* 0x1b6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1bb:
	/* 0x1bb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c0:
	/* 0x1c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c2:
	/* 0x1c2: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c7:
	/* 0x1c7: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1cc:
	/* 0x1cc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1cf:
	/* 0x1cf: jne    1e6 <generic_tracepoint_event+0x1e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e6;
	}
x86_l_1d1:
	/* 0x1d1: jmp    3300 <generic_tracepoint_event+0x3300> */
	return 13056ULL;
x86_l_1d6:
	/* 0x1d6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d8:
	/* 0x1d8: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1dd:
	/* 0x1dd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e0:
	/* 0x1e0: je     3300 <generic_tracepoint_event+0x3300> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13056ULL;
	}
x86_l_1e6:
	/* 0x1e6: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1eb:
	/* 0x1eb: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_cgtracker_map)));
x86_l_1f2:
	/* 0x1f2: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f7:
	/* 0x1f7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1fc:
	/* 0x1fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fe:
	/* 0x1fe: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_201:
	/* 0x201: je     217 <generic_tracepoint_event+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_217;
	}
x86_l_203:
	/* 0x203: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_206:
	/* 0x206: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_20b:
	/* 0x20b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_20e:
	/* 0x20e: je     220 <generic_tracepoint_event+0x220> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_220;
	}
x86_l_210:
	/* 0x210: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_215:
	/* 0x215: jmp    220 <generic_tracepoint_event+0x220> */
	goto x86_l_220;
x86_l_217:
	/* 0x217: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_220:
	/* 0x220: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_225:
	/* 0x225: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_22a:
	/* 0x22a: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_22d:
	/* 0x22d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22f:
	/* 0x22f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_232:
	/* 0x232: je     45a <generic_tracepoint_event+0x45a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_45a;
	}
x86_l_238:
	/* 0x238: mov    DWORD PTR [r14+0x5ef8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104419244900352ULL);
x86_l_243:
	/* 0x243: mov    eax,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_246:
	/* 0x246: mov    QWORD PTR [r14+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_24a:
	/* 0x24a: mov    QWORD PTR [r14+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_252:
	/* 0x252: movzx  edx,WORD PTR [r15+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 44ULL);
x86_l_257:
	/* 0x257: mov    r13d,DWORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_25b:
	/* 0x25b: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_25e:
	/* 0x25e: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_261:
	/* 0x261: cmp    r13d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 11ULL);
x86_l_265:
	/* 0x265: jg     29e <generic_tracepoint_event+0x29e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_29e;
	}
x86_l_267:
	/* 0x267: cmp    r13d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 3ULL);
x86_l_26b:
	/* 0x26b: jle    32f <generic_tracepoint_event+0x32f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_32f;
	}
x86_l_271:
	/* 0x271: cmp    r13d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 6ULL);
x86_l_275:
	/* 0x275: jg     4bc <generic_tracepoint_event+0x4bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_4bc;
	}
x86_l_27b:
	/* 0x27b: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_27f:
	/* 0x27f: je     921 <generic_tracepoint_event+0x921> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2337ULL;
	}
x86_l_285:
	/* 0x285: cmp    r13d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 5ULL);
x86_l_289:
	/* 0x289: je     7c2 <generic_tracepoint_event+0x7c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1986ULL;
	}
x86_l_28f:
	/* 0x28f: cmp    r13d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 6ULL);
x86_l_293:
	/* 0x293: je     350 <generic_tracepoint_event+0x350> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_350;
	}
x86_l_299:
	/* 0x299: jmp    b84 <generic_tracepoint_event+0xb84> */
	return 2948ULL;
x86_l_29e:
	/* 0x29e: cmp    r13d,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 29ULL);
x86_l_2a2:
	/* 0x2a2: jle    3cd <generic_tracepoint_event+0x3cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_3cd;
	}
x86_l_2a8:
	/* 0x2a8: cmp    r13d,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 37ULL);
x86_l_2ac:
	/* 0x2ac: jg     528 <generic_tracepoint_event+0x528> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_528;
	}
x86_l_2b2:
	/* 0x2b2: cmp    r13d,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 30ULL);
x86_l_2b6:
	/* 0x2b6: je     980 <generic_tracepoint_event+0x980> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2432ULL;
	}
x86_l_2bc:
	/* 0x2bc: cmp    r13d,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 31ULL);
x86_l_2c0:
	/* 0x2c0: je     83f <generic_tracepoint_event+0x83f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2111ULL;
	}
x86_l_2c6:
	/* 0x2c6: cmp    r13d,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 32ULL);
x86_l_2ca:
	/* 0x2ca: jne    b84 <generic_tracepoint_event+0xb84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2948ULL;
	}
x86_l_2d0:
	/* 0x2d0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d5:
	/* 0x2d5: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2da:
	/* 0x2da: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2df:
	/* 0x2df: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_2e4:
	/* 0x2e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e6:
	/* 0x2e6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2e9:
	/* 0x2e9: je     af9 <generic_tracepoint_event+0xaf9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2809ULL;
	}
x86_l_2ef:
	/* 0x2ef: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_2f1:
	/* 0x2f1: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f6:
	/* 0x2f6: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_2fd:
	/* 0x2fd: movabs rax,0x400000073 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869299ULL);
x86_l_307:
	/* 0x307: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_30c:
	/* 0x30c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_313:
	/* 0x313: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_318:
	/* 0x318: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_31d:
	/* 0x31d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31f:
	/* 0x31f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_322:
	/* 0x322: je     ad5 <generic_tracepoint_event+0xad5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2773ULL;
	}
x86_l_328:
	/* 0x328: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_32a:
	/* 0x32a: jmp    af9 <generic_tracepoint_event+0xaf9> */
	return 2809ULL;
x86_l_32f:
	/* 0x32f: cmp    r13d,0xfffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4294967284ULL);
x86_l_333:
	/* 0x333: jle    5c3 <generic_tracepoint_event+0x5c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_5c3;
	}
x86_l_339:
	/* 0x339: lea    eax,[r13+0xb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 11ULL);
x86_l_33d:
	/* 0x33d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_340:
	/* 0x340: jb     4c9 <generic_tracepoint_event+0x4c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_4c9;
	}
x86_l_346:
	/* 0x346: cmp    r13d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 2ULL);
x86_l_34a:
	/* 0x34a: jne    b84 <generic_tracepoint_event+0xb84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2948ULL;
	}
x86_l_350:
	/* 0x350: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_355:
	/* 0x355: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_35a:
	/* 0x35a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_35f:
	/* 0x35f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_364:
	/* 0x364: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_366:
	/* 0x366: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_369:
	/* 0x369: je     b28 <generic_tracepoint_event+0xb28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2856ULL;
	}
x86_l_36f:
	/* 0x36f: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_371:
	/* 0x371: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_376:
	/* 0x376: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_37d:
	/* 0x37d: movabs rax,0x400000081 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869313ULL);
x86_l_387:
	/* 0x387: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_38c:
	/* 0x38c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_393:
	/* 0x393: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_398:
	/* 0x398: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_39d:
	/* 0x39d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39f:
	/* 0x39f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3a2:
	/* 0x3a2: jne    979 <generic_tracepoint_event+0x979> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2425ULL;
	}
x86_l_3a8:
	/* 0x3a8: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_3b0:
	/* 0x3b0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_3b7:
	/* 0x3b7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3b9:
	/* 0x3b9: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3be:
	/* 0x3be: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c3:
	/* 0x3c3: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3c8:
	/* 0x3c8: jmp    b24 <generic_tracepoint_event+0xb24> */
	return 2852ULL;
x86_l_3cd:
	/* 0x3cd: cmp    r13d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 17ULL);
x86_l_3d1:
	/* 0x3d1: jle    5d8 <generic_tracepoint_event+0x5d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_5d8;
	}
x86_l_3d7:
	/* 0x3d7: cmp    r13d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 18ULL);
x86_l_3db:
	/* 0x3db: je     7ba <generic_tracepoint_event+0x7ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1978ULL;
	}
x86_l_3e1:
	/* 0x3e1: cmp    r13d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 28ULL);
x86_l_3e5:
	/* 0x3e5: je     4c9 <generic_tracepoint_event+0x4c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4c9;
	}
x86_l_3eb:
	/* 0x3eb: cmp    r13d,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 29ULL);
x86_l_3ef:
	/* 0x3ef: jne    b84 <generic_tracepoint_event+0xb84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2948ULL;
	}
x86_l_3f5:
	/* 0x3f5: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3fa:
	/* 0x3fa: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_3ff:
	/* 0x3ff: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_404:
	/* 0x404: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_409:
	/* 0x409: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40b:
	/* 0x40b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_40e:
	/* 0x40e: je     a9b <generic_tracepoint_event+0xa9b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2715ULL;
	}
x86_l_414:
	/* 0x414: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_416:
	/* 0x416: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_41b:
	/* 0x41b: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_422:
	/* 0x422: movabs rax,0x40000006c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869292ULL);
x86_l_42c:
	/* 0x42c: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_431:
	/* 0x431: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_438:
	/* 0x438: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_43d:
	/* 0x43d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_442:
	/* 0x442: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_444:
	/* 0x444: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_447:
	/* 0x447: je     a77 <generic_tracepoint_event+0xa77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2679ULL;
	}
x86_l_44d:
	/* 0x44d: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_44f:
	/* 0x44f: movsx  r12,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_455:
	/* 0x455: jmp    b84 <generic_tracepoint_event+0xb84> */
	return 2948ULL;
x86_l_45a:
	/* 0x45a: mov    QWORD PTR [rsp+0x70],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 485331304447ULL);
x86_l_463:
	/* 0x463: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_468:
	/* 0x468: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_46d:
	/* 0x46d: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_470:
	/* 0x470: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_472:
	/* 0x472: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_475:
	/* 0x475: je     3300 <generic_tracepoint_event+0x3300> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13056ULL;
	}
x86_l_47b:
	/* 0x47b: mov    DWORD PTR [rsp+0x7c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 532575944705ULL);
x86_l_483:
	/* 0x483: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_filter_maps)));
x86_l_48a:
	/* 0x48a: lea    rsi,[rsp+0x7c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_48f:
	/* 0x48f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_494:
	/* 0x494: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_496:
	/* 0x496: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_499:
	/* 0x499: je     3300 <generic_tracepoint_event+0x3300> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13056ULL;
	}
x86_l_49f:
	/* 0x49f: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_4a2:
	/* 0x4a2: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_4a7:
	/* 0x4a7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4ac:
	/* 0x4ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ae:
	/* 0x4ae: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4b1:
	/* 0x4b1: jne    3300 <generic_tracepoint_event+0x3300> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13056ULL;
	}
x86_l_4b7:
	/* 0x4b7: jmp    238 <generic_tracepoint_event+0x238> */
	goto x86_l_238;
x86_l_4bc:
	/* 0x4bc: lea    eax,[r13-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_4c0:
	/* 0x4c0: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4c3:
	/* 0x4c3: jae    733 <generic_tracepoint_event+0x733> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 1843ULL;
	}
x86_l_4c9:
	/* 0x4c9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4ce:
	/* 0x4ce: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4d3:
	/* 0x4d3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4d8:
	/* 0x4d8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4dd:
	/* 0x4dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4df:
	/* 0x4df: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4e2:
	/* 0x4e2: je     6f1 <generic_tracepoint_event+0x6f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6f1;
	}
x86_l_4e8:
	/* 0x4e8: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_4ea:
	/* 0x4ea: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4ef:
	/* 0x4ef: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_4f6:
	/* 0x4f6: movabs rax,0x400000045 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869253ULL);
x86_l_500:
	/* 0x500: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_505:
	/* 0x505: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_50c:
	/* 0x50c: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_511:
	/* 0x511: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_516:
	/* 0x516: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_518:
	/* 0x518: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_51b:
	/* 0x51b: je     6cd <generic_tracepoint_event+0x6cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6cd;
	}
x86_l_521:
	/* 0x521: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_523:
	/* 0x523: jmp    6f1 <generic_tracepoint_event+0x6f1> */
	goto x86_l_6f1;
x86_l_528:
	/* 0x528: cmp    r13d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 38ULL);
x86_l_52c:
	/* 0x52c: je     9e5 <generic_tracepoint_event+0x9e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2533ULL;
	}
x86_l_532:
	/* 0x532: cmp    r13d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 40ULL);
x86_l_536:
	/* 0x536: je     8a4 <generic_tracepoint_event+0x8a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2212ULL;
	}
x86_l_53c:
	/* 0x53c: cmp    r13d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 41ULL);
x86_l_540:
	/* 0x540: jne    b84 <generic_tracepoint_event+0xb84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2948ULL;
	}
x86_l_546:
	/* 0x546: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_54b:
	/* 0x54b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_550:
	/* 0x550: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_555:
	/* 0x555: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_55a:
	/* 0x55a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55c:
	/* 0x55c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_55f:
	/* 0x55f: je     b28 <generic_tracepoint_event+0xb28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2856ULL;
	}
x86_l_565:
	/* 0x565: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_567:
	/* 0x567: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_56c:
	/* 0x56c: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_573:
	/* 0x573: movabs rax,0x4000000a8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869352ULL);
x86_l_57d:
	/* 0x57d: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_582:
	/* 0x582: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_589:
	/* 0x589: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
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
	/* 0x598: jne    979 <generic_tracepoint_event+0x979> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2425ULL;
	}
x86_l_59e:
	/* 0x59e: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_5a6:
	/* 0x5a6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_5ad:
	/* 0x5ad: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5af:
	/* 0x5af: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5b4:
	/* 0x5b4: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b9:
	/* 0x5b9: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5be:
	/* 0x5be: jmp    b24 <generic_tracepoint_event+0xb24> */
	return 2852ULL;
x86_l_5c3:
	/* 0x5c3: cmp    r13d,0xfffffff3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4294967283ULL);
x86_l_5c7:
	/* 0x5c7: je     669 <generic_tracepoint_event+0x669> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_669;
	}
x86_l_5cd:
	/* 0x5cd: cmp    r13d,0xfffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4294967284ULL);
x86_l_5d1:
	/* 0x5d1: je     5ec <generic_tracepoint_event+0x5ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5ec;
	}
x86_l_5d3:
	/* 0x5d3: jmp    b84 <generic_tracepoint_event+0xb84> */
	return 2948ULL;
x86_l_5d8:
	/* 0x5d8: cmp    r13d,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 12ULL);
x86_l_5dc:
	/* 0x5dc: je     669 <generic_tracepoint_event+0x669> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_669;
	}
x86_l_5e2:
	/* 0x5e2: cmp    r13d,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 13ULL);
x86_l_5e6:
	/* 0x5e6: jne    b84 <generic_tracepoint_event+0xb84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2948ULL;
	}
x86_l_5ec:
	/* 0x5ec: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f1:
	/* 0x5f1: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_5f6:
	/* 0x5f6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5fb:
	/* 0x5fb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_600:
	/* 0x600: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_602:
	/* 0x602: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_605:
	/* 0x605: je     b7f <generic_tracepoint_event+0xb7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2943ULL;
	}
x86_l_60b:
	/* 0x60b: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_60d:
	/* 0x60d: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_612:
	/* 0x612: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_619:
	/* 0x619: movabs rax,0x40000005e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869278ULL);
x86_l_623:
	/* 0x623: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_628:
	/* 0x628: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_62f:
	/* 0x62f: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_634:
	/* 0x634: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_639:
	/* 0x639: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_63b:
	/* 0x63b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_63e:
	/* 0x63e: jne    a3d <generic_tracepoint_event+0xa3d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2621ULL;
	}
x86_l_644:
	/* 0x644: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_64c:
	/* 0x64c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_653:
	/* 0x653: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_655:
	/* 0x655: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_65a:
	/* 0x65a: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_65f:
	/* 0x65f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_664:
	/* 0x664: jmp    b7b <generic_tracepoint_event+0xb7b> */
	return 2939ULL;
x86_l_669:
	/* 0x669: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_66e:
	/* 0x66e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_673:
	/* 0x673: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_678:
	/* 0x678: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_67d:
	/* 0x67d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_67f:
	/* 0x67f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_682:
	/* 0x682: je     a6d <generic_tracepoint_event+0xa6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2669ULL;
	}
x86_l_688:
	/* 0x688: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_68a:
	/* 0x68a: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_68f:
	/* 0x68f: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_696:
	/* 0x696: movabs rax,0x400000056 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869270ULL);
x86_l_6a0:
	/* 0x6a0: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_6a5:
	/* 0x6a5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_6ac:
	/* 0x6ac: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6b1:
	/* 0x6b1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6b6:
	/* 0x6b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6b8:
	/* 0x6b8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6bb:
	/* 0x6bb: je     a49 <generic_tracepoint_event+0xa49> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2633ULL;
	}
x86_l_6c1:
	/* 0x6c1: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_6c3:
	/* 0x6c3: movsxd r12,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_6c8:
	/* 0x6c8: jmp    b84 <generic_tracepoint_event+0xb84> */
	return 2948ULL;
x86_l_6cd:
	/* 0x6cd: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_6d5:
	/* 0x6d5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_6dc:
	/* 0x6dc: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6de:
	/* 0x6de: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6e3:
	/* 0x6e3: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6e8:
	/* 0x6e8: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6ed:
	/* 0x6ed: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6ef:
	/* 0x6ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6f1:
	/* 0x6f1: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6f6:
	/* 0x6f6: cmp    r13d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 28ULL);
x86_l_6fa:
	/* 0x6fa: jne    b84 <generic_tracepoint_event+0xb84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2948ULL;
	}
x86_l_700:
	/* 0x700: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_705:
	/* 0x705: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 1799ULL;
}

static __noinline __u64 tetragon_bpf_generic_tracepoint_v53_generic_tracepoint_event_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1799ULL: goto x86_l_707;
	case 1803ULL: goto x86_l_70b;
	case 1808ULL: goto x86_l_710;
	case 1813ULL: goto x86_l_715;
	case 1818ULL: goto x86_l_71a;
	case 1823ULL: goto x86_l_71f;
	case 1825ULL: goto x86_l_721;
	case 1829ULL: goto x86_l_725;
	case 1832ULL: goto x86_l_728;
	case 1835ULL: goto x86_l_72b;
	case 1838ULL: goto x86_l_72e;
	case 1843ULL: goto x86_l_733;
	case 1847ULL: goto x86_l_737;
	case 1853ULL: goto x86_l_73d;
	case 1858ULL: goto x86_l_742;
	case 1863ULL: goto x86_l_747;
	case 1868ULL: goto x86_l_74c;
	case 1873ULL: goto x86_l_751;
	case 1875ULL: goto x86_l_753;
	case 1878ULL: goto x86_l_756;
	case 1884ULL: goto x86_l_75c;
	case 1886ULL: goto x86_l_75e;
	case 1891ULL: goto x86_l_763;
	case 1898ULL: goto x86_l_76a;
	case 1908ULL: goto x86_l_774;
	case 1913ULL: goto x86_l_779;
	case 1920ULL: goto x86_l_780;
	case 1925ULL: goto x86_l_785;
	case 1930ULL: goto x86_l_78a;
	case 1932ULL: goto x86_l_78c;
	case 1935ULL: goto x86_l_78f;
	case 1941ULL: goto x86_l_795;
	case 1949ULL: goto x86_l_79d;
	case 1956ULL: goto x86_l_7a4;
	case 1958ULL: goto x86_l_7a6;
	case 1963ULL: goto x86_l_7ab;
	case 1968ULL: goto x86_l_7b0;
	case 1973ULL: goto x86_l_7b5;
	case 1978ULL: goto x86_l_7ba;
	case 1981ULL: goto x86_l_7bd;
	case 1986ULL: goto x86_l_7c2;
	case 1991ULL: goto x86_l_7c7;
	case 1996ULL: goto x86_l_7cc;
	case 2001ULL: goto x86_l_7d1;
	case 2006ULL: goto x86_l_7d6;
	case 2008ULL: goto x86_l_7d8;
	case 2011ULL: goto x86_l_7db;
	case 2017ULL: goto x86_l_7e1;
	case 2019ULL: goto x86_l_7e3;
	case 2024ULL: goto x86_l_7e8;
	case 2031ULL: goto x86_l_7ef;
	case 2041ULL: goto x86_l_7f9;
	case 2046ULL: goto x86_l_7fe;
	case 2053ULL: goto x86_l_805;
	case 2058ULL: goto x86_l_80a;
	case 2063ULL: goto x86_l_80f;
	case 2065ULL: goto x86_l_811;
	case 2068ULL: goto x86_l_814;
	case 2074ULL: goto x86_l_81a;
	case 2082ULL: goto x86_l_822;
	case 2089ULL: goto x86_l_829;
	case 2091ULL: goto x86_l_82b;
	case 2096ULL: goto x86_l_830;
	case 2101ULL: goto x86_l_835;
	case 2106ULL: goto x86_l_83a;
	case 2111ULL: goto x86_l_83f;
	case 2116ULL: goto x86_l_844;
	case 2121ULL: goto x86_l_849;
	case 2126ULL: goto x86_l_84e;
	case 2131ULL: goto x86_l_853;
	case 2133ULL: goto x86_l_855;
	case 2136ULL: goto x86_l_858;
	case 2142ULL: goto x86_l_85e;
	case 2144ULL: goto x86_l_860;
	case 2149ULL: goto x86_l_865;
	case 2156ULL: goto x86_l_86c;
	case 2166ULL: goto x86_l_876;
	case 2171ULL: goto x86_l_87b;
	case 2178ULL: goto x86_l_882;
	case 2183ULL: goto x86_l_887;
	case 2188ULL: goto x86_l_88c;
	case 2190ULL: goto x86_l_88e;
	case 2193ULL: goto x86_l_891;
	case 2199ULL: goto x86_l_897;
	case 2201ULL: goto x86_l_899;
	case 2207ULL: goto x86_l_89f;
	case 2212ULL: goto x86_l_8a4;
	case 2217ULL: goto x86_l_8a9;
	case 2222ULL: goto x86_l_8ae;
	case 2227ULL: goto x86_l_8b3;
	case 2232ULL: goto x86_l_8b8;
	case 2234ULL: goto x86_l_8ba;
	case 2237ULL: goto x86_l_8bd;
	case 2243ULL: goto x86_l_8c3;
	case 2245ULL: goto x86_l_8c5;
	case 2250ULL: goto x86_l_8ca;
	case 2257ULL: goto x86_l_8d1;
	case 2267ULL: goto x86_l_8db;
	case 2272ULL: goto x86_l_8e0;
	case 2279ULL: goto x86_l_8e7;
	case 2284ULL: goto x86_l_8ec;
	case 2289ULL: goto x86_l_8f1;
	case 2291ULL: goto x86_l_8f3;
	case 2294ULL: goto x86_l_8f6;
	case 2300ULL: goto x86_l_8fc;
	case 2308ULL: goto x86_l_904;
	case 2315ULL: goto x86_l_90b;
	case 2317ULL: goto x86_l_90d;
	case 2322ULL: goto x86_l_912;
	case 2327ULL: goto x86_l_917;
	case 2332ULL: goto x86_l_91c;
	case 2337ULL: goto x86_l_921;
	case 2342ULL: goto x86_l_926;
	case 2347ULL: goto x86_l_92b;
	case 2352ULL: goto x86_l_930;
	case 2357ULL: goto x86_l_935;
	case 2359ULL: goto x86_l_937;
	case 2362ULL: goto x86_l_93a;
	case 2368ULL: goto x86_l_940;
	case 2370ULL: goto x86_l_942;
	case 2375ULL: goto x86_l_947;
	case 2382ULL: goto x86_l_94e;
	case 2392ULL: goto x86_l_958;
	case 2397ULL: goto x86_l_95d;
	case 2404ULL: goto x86_l_964;
	case 2409ULL: goto x86_l_969;
	case 2414ULL: goto x86_l_96e;
	case 2416ULL: goto x86_l_970;
	case 2419ULL: goto x86_l_973;
	case 2425ULL: goto x86_l_979;
	case 2427ULL: goto x86_l_97b;
	case 2432ULL: goto x86_l_980;
	case 2437ULL: goto x86_l_985;
	case 2442ULL: goto x86_l_98a;
	case 2447ULL: goto x86_l_98f;
	case 2452ULL: goto x86_l_994;
	case 2454ULL: goto x86_l_996;
	case 2457ULL: goto x86_l_999;
	case 2463ULL: goto x86_l_99f;
	case 2465ULL: goto x86_l_9a1;
	case 2470ULL: goto x86_l_9a6;
	case 2477ULL: goto x86_l_9ad;
	case 2487ULL: goto x86_l_9b7;
	case 2492ULL: goto x86_l_9bc;
	case 2499ULL: goto x86_l_9c3;
	case 2504ULL: goto x86_l_9c8;
	case 2509ULL: goto x86_l_9cd;
	case 2511ULL: goto x86_l_9cf;
	case 2514ULL: goto x86_l_9d2;
	case 2520ULL: goto x86_l_9d8;
	case 2522ULL: goto x86_l_9da;
	case 2528ULL: goto x86_l_9e0;
	case 2533ULL: goto x86_l_9e5;
	case 2538ULL: goto x86_l_9ea;
	case 2543ULL: goto x86_l_9ef;
	case 2548ULL: goto x86_l_9f4;
	case 2553ULL: goto x86_l_9f9;
	case 2555ULL: goto x86_l_9fb;
	case 2558ULL: goto x86_l_9fe;
	case 2564ULL: goto x86_l_a04;
	case 2566ULL: goto x86_l_a06;
	case 2571ULL: goto x86_l_a0b;
	case 2578ULL: goto x86_l_a12;
	case 2588ULL: goto x86_l_a1c;
	case 2593ULL: goto x86_l_a21;
	case 2600ULL: goto x86_l_a28;
	case 2605ULL: goto x86_l_a2d;
	case 2610ULL: goto x86_l_a32;
	case 2612ULL: goto x86_l_a34;
	case 2615ULL: goto x86_l_a37;
	case 2621ULL: goto x86_l_a3d;
	case 2623ULL: goto x86_l_a3f;
	case 2628ULL: goto x86_l_a44;
	case 2633ULL: goto x86_l_a49;
	case 2641ULL: goto x86_l_a51;
	case 2648ULL: goto x86_l_a58;
	case 2650ULL: goto x86_l_a5a;
	case 2655ULL: goto x86_l_a5f;
	case 2660ULL: goto x86_l_a64;
	case 2665ULL: goto x86_l_a69;
	case 2667ULL: goto x86_l_a6b;
	case 2669ULL: goto x86_l_a6d;
	case 2674ULL: goto x86_l_a72;
	case 2679ULL: goto x86_l_a77;
	case 2687ULL: goto x86_l_a7f;
	case 2694ULL: goto x86_l_a86;
	case 2696ULL: goto x86_l_a88;
	case 2701ULL: goto x86_l_a8d;
	case 2706ULL: goto x86_l_a92;
	case 2711ULL: goto x86_l_a97;
	case 2713ULL: goto x86_l_a99;
	case 2715ULL: goto x86_l_a9b;
	case 2721ULL: goto x86_l_aa1;
	case 2726ULL: goto x86_l_aa6;
	case 2734ULL: goto x86_l_aae;
	case 2741ULL: goto x86_l_ab5;
	case 2743ULL: goto x86_l_ab7;
	case 2748ULL: goto x86_l_abc;
	case 2753ULL: goto x86_l_ac1;
	case 2758ULL: goto x86_l_ac6;
	case 2760ULL: goto x86_l_ac8;
	case 2762ULL: goto x86_l_aca;
	case 2768ULL: goto x86_l_ad0;
	case 2773ULL: goto x86_l_ad5;
	case 2781ULL: goto x86_l_add;
	case 2788ULL: goto x86_l_ae4;
	case 2790ULL: goto x86_l_ae6;
	case 2795ULL: goto x86_l_aeb;
	case 2800ULL: goto x86_l_af0;
	case 2805ULL: goto x86_l_af5;
	case 2807ULL: goto x86_l_af7;
	case 2809ULL: goto x86_l_af9;
	case 2815ULL: goto x86_l_aff;
	case 2820ULL: goto x86_l_b04;
	case 2828ULL: goto x86_l_b0c;
	case 2835ULL: goto x86_l_b13;
	case 2837ULL: goto x86_l_b15;
	case 2842ULL: goto x86_l_b1a;
	case 2847ULL: goto x86_l_b1f;
	case 2852ULL: goto x86_l_b24;
	case 2854ULL: goto x86_l_b26;
	case 2856ULL: goto x86_l_b28;
	case 2861ULL: goto x86_l_b2d;
	case 2863ULL: goto x86_l_b2f;
	case 2871ULL: goto x86_l_b37;
	case 2878ULL: goto x86_l_b3e;
	case 2880ULL: goto x86_l_b40;
	case 2885ULL: goto x86_l_b45;
	case 2890ULL: goto x86_l_b4a;
	case 2895ULL: goto x86_l_b4f;
	case 2897ULL: goto x86_l_b51;
	case 2899ULL: goto x86_l_b53;
	case 2905ULL: goto x86_l_b59;
	case 2907ULL: goto x86_l_b5b;
	case 2915ULL: goto x86_l_b63;
	case 2922ULL: goto x86_l_b6a;
	case 2924ULL: goto x86_l_b6c;
	case 2929ULL: goto x86_l_b71;
	case 2934ULL: goto x86_l_b76;
	case 2939ULL: goto x86_l_b7b;
	case 2941ULL: goto x86_l_b7d;
	case 2943ULL: goto x86_l_b7f;
	case 2948ULL: goto x86_l_b84;
	case 2955ULL: goto x86_l_b8b;
	case 2960ULL: goto x86_l_b90;
	case 2964ULL: goto x86_l_b94;
	case 2967ULL: goto x86_l_b97;
	case 2970ULL: goto x86_l_b9a;
	case 2974ULL: goto x86_l_b9e;
	case 2976ULL: goto x86_l_ba0;
	case 2980ULL: goto x86_l_ba4;
	case 2986ULL: goto x86_l_baa;
	case 2990ULL: goto x86_l_bae;
	case 2996ULL: goto x86_l_bb4;
	case 3000ULL: goto x86_l_bb8;
	case 3006ULL: goto x86_l_bbe;
	case 3010ULL: goto x86_l_bc2;
	case 3016ULL: goto x86_l_bc8;
	case 3020ULL: goto x86_l_bcc;
	case 3026ULL: goto x86_l_bd2;
	case 3031ULL: goto x86_l_bd7;
	case 3035ULL: goto x86_l_bdb;
	case 3041ULL: goto x86_l_be1;
	case 3045ULL: goto x86_l_be5;
	case 3051ULL: goto x86_l_beb;
	case 3055ULL: goto x86_l_bef;
	case 3061ULL: goto x86_l_bf5;
	case 3065ULL: goto x86_l_bf9;
	case 3071ULL: goto x86_l_bff;
	case 3075ULL: goto x86_l_c03;
	case 3081ULL: goto x86_l_c09;
	case 3086ULL: goto x86_l_c0e;
	case 3091ULL: goto x86_l_c13;
	case 3096ULL: goto x86_l_c18;
	case 3101ULL: goto x86_l_c1d;
	case 3103ULL: goto x86_l_c1f;
	case 3106ULL: goto x86_l_c22;
	case 3112ULL: goto x86_l_c28;
	case 3114ULL: goto x86_l_c2a;
	case 3119ULL: goto x86_l_c2f;
	case 3126ULL: goto x86_l_c36;
	case 3136ULL: goto x86_l_c40;
	case 3141ULL: goto x86_l_c45;
	case 3148ULL: goto x86_l_c4c;
	case 3153ULL: goto x86_l_c51;
	case 3158ULL: goto x86_l_c56;
	case 3160ULL: goto x86_l_c58;
	case 3163ULL: goto x86_l_c5b;
	case 3169ULL: goto x86_l_c61;
	case 3171ULL: goto x86_l_c63;
	case 3177ULL: goto x86_l_c69;
	case 3182ULL: goto x86_l_c6e;
	case 3186ULL: goto x86_l_c72;
	case 3192ULL: goto x86_l_c78;
	case 3196ULL: goto x86_l_c7c;
	case 3199ULL: goto x86_l_c7f;
	case 3205ULL: goto x86_l_c85;
	case 3209ULL: goto x86_l_c89;
	case 3215ULL: goto x86_l_c8f;
	case 3220ULL: goto x86_l_c94;
	case 3225ULL: goto x86_l_c99;
	case 3230ULL: goto x86_l_c9e;
	case 3235ULL: goto x86_l_ca3;
	case 3237ULL: goto x86_l_ca5;
	case 3240ULL: goto x86_l_ca8;
	case 3246ULL: goto x86_l_cae;
	case 3248ULL: goto x86_l_cb0;
	case 3253ULL: goto x86_l_cb5;
	case 3260ULL: goto x86_l_cbc;
	case 3270ULL: goto x86_l_cc6;
	case 3275ULL: goto x86_l_ccb;
	case 3282ULL: goto x86_l_cd2;
	case 3287ULL: goto x86_l_cd7;
	case 3292ULL: goto x86_l_cdc;
	case 3294ULL: goto x86_l_cde;
	case 3297ULL: goto x86_l_ce1;
	case 3303ULL: goto x86_l_ce7;
	case 3311ULL: goto x86_l_cef;
	case 3318ULL: goto x86_l_cf6;
	case 3320ULL: goto x86_l_cf8;
	case 3325ULL: goto x86_l_cfd;
	case 3330ULL: goto x86_l_d02;
	case 3335ULL: goto x86_l_d07;
	case 3340ULL: goto x86_l_d0c;
	case 3344ULL: goto x86_l_d10;
	case 3350ULL: goto x86_l_d16;
	case 3354ULL: goto x86_l_d1a;
	case 3360ULL: goto x86_l_d20;
	case 3364ULL: goto x86_l_d24;
	case 3370ULL: goto x86_l_d2a;
	case 3374ULL: goto x86_l_d2e;
	case 3380ULL: goto x86_l_d34;
	case 3385ULL: goto x86_l_d39;
	case 3390ULL: goto x86_l_d3e;
	case 3395ULL: goto x86_l_d43;
	case 3400ULL: goto x86_l_d48;
	case 3402ULL: goto x86_l_d4a;
	case 3405ULL: goto x86_l_d4d;
	case 3411ULL: goto x86_l_d53;
	case 3413ULL: goto x86_l_d55;
	case 3418ULL: goto x86_l_d5a;
	case 3425ULL: goto x86_l_d61;
	case 3435ULL: goto x86_l_d6b;
	case 3440ULL: goto x86_l_d70;
	case 3447ULL: goto x86_l_d77;
	case 3452ULL: goto x86_l_d7c;
	case 3457ULL: goto x86_l_d81;
	case 3459ULL: goto x86_l_d83;
	case 3462ULL: goto x86_l_d86;
	case 3468ULL: goto x86_l_d8c;
	case 3470ULL: goto x86_l_d8e;
	case 3476ULL: goto x86_l_d94;
	case 3481ULL: goto x86_l_d99;
	case 3485ULL: goto x86_l_d9d;
	case 3488ULL: goto x86_l_da0;
	case 3494ULL: goto x86_l_da6;
	case 3499ULL: goto x86_l_dab;
	case 3504ULL: goto x86_l_db0;
	case 3509ULL: goto x86_l_db5;
	case 3514ULL: goto x86_l_dba;
	case 3516ULL: goto x86_l_dbc;
	case 3519ULL: goto x86_l_dbf;
	case 3525ULL: goto x86_l_dc5;
	case 3527ULL: goto x86_l_dc7;
	case 3532ULL: goto x86_l_dcc;
	case 3539ULL: goto x86_l_dd3;
	case 3549ULL: goto x86_l_ddd;
	case 3554ULL: goto x86_l_de2;
	case 3561ULL: goto x86_l_de9;
	case 3566ULL: goto x86_l_dee;
	case 3571ULL: goto x86_l_df3;
	case 3573ULL: goto x86_l_df5;
	case 3576ULL: goto x86_l_df8;
	case 3582ULL: goto x86_l_dfe;
	case 3584ULL: goto x86_l_e00;
	case 3589ULL: goto x86_l_e05;
	case 3593ULL: goto x86_l_e09;
	case 3599ULL: goto x86_l_e0f;
	case 3603ULL: goto x86_l_e13;
	case 3609ULL: goto x86_l_e19;
	case 3613ULL: goto x86_l_e1d;
	case 3619ULL: goto x86_l_e23;
	case 3624ULL: goto x86_l_e28;
	case 3629ULL: goto x86_l_e2d;
	default: return 0xffffffffffffffffULL;
	}
x86_l_707:
	/* 0x707: lea    rdx,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_70b:
	/* 0x70b: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_710:
	/* 0x710: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_715:
	/* 0x715: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_71a:
	/* 0x71a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_71f:
	/* 0x71f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_721:
	/* 0x721: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_725:
	/* 0x725: and    eax,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_728:
	/* 0x728: shl    eax,0x1e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 30ULL);
x86_l_72b:
	/* 0x72b: or     r12,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_72e:
	/* 0x72e: jmp    b84 <generic_tracepoint_event+0xb84> */
	goto x86_l_b84;
x86_l_733:
	/* 0x733: cmp    r13d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 7ULL);
x86_l_737:
	/* 0x737: jne    b84 <generic_tracepoint_event+0xb84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b84;
	}
x86_l_73d:
	/* 0x73d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_742:
	/* 0x742: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_747:
	/* 0x747: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_74c:
	/* 0x74c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_751:
	/* 0x751: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_753:
	/* 0x753: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_756:
	/* 0x756: je     b28 <generic_tracepoint_event+0xb28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b28;
	}
x86_l_75c:
	/* 0x75c: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_75e:
	/* 0x75e: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_763:
	/* 0x763: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_76a:
	/* 0x76a: movabs rax,0x40000009a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869338ULL);
x86_l_774:
	/* 0x774: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_779:
	/* 0x779: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_780:
	/* 0x780: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_785:
	/* 0x785: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_78a:
	/* 0x78a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_78c:
	/* 0x78c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_78f:
	/* 0x78f: jne    979 <generic_tracepoint_event+0x979> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_979;
	}
x86_l_795:
	/* 0x795: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_79d:
	/* 0x79d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_7a4:
	/* 0x7a4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7a6:
	/* 0x7a6: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7ab:
	/* 0x7ab: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7b0:
	/* 0x7b0: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_7b5:
	/* 0x7b5: jmp    b24 <generic_tracepoint_event+0xb24> */
	goto x86_l_b24;
x86_l_7ba:
	/* 0x7ba: mov    r12,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_7bd:
	/* 0x7bd: jmp    b84 <generic_tracepoint_event+0xb84> */
	goto x86_l_b84;
x86_l_7c2:
	/* 0x7c2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7c7:
	/* 0x7c7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_7cc:
	/* 0x7cc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_7d1:
	/* 0x7d1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7d6:
	/* 0x7d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7d8:
	/* 0x7d8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7db:
	/* 0x7db: je     b28 <generic_tracepoint_event+0xb28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b28;
	}
x86_l_7e1:
	/* 0x7e1: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_7e3:
	/* 0x7e3: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7e8:
	/* 0x7e8: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_7ef:
	/* 0x7ef: movabs rax,0x400000093 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869331ULL);
x86_l_7f9:
	/* 0x7f9: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_7fe:
	/* 0x7fe: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_805:
	/* 0x805: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_80a:
	/* 0x80a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_80f:
	/* 0x80f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_811:
	/* 0x811: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_814:
	/* 0x814: jne    979 <generic_tracepoint_event+0x979> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_979;
	}
x86_l_81a:
	/* 0x81a: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_822:
	/* 0x822: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_829:
	/* 0x829: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_82b:
	/* 0x82b: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_830:
	/* 0x830: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_835:
	/* 0x835: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_83a:
	/* 0x83a: jmp    b24 <generic_tracepoint_event+0xb24> */
	goto x86_l_b24;
x86_l_83f:
	/* 0x83f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_844:
	/* 0x844: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_849:
	/* 0x849: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_84e:
	/* 0x84e: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_853:
	/* 0x853: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_855:
	/* 0x855: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_858:
	/* 0x858: je     aca <generic_tracepoint_event+0xaca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_aca;
	}
x86_l_85e:
	/* 0x85e: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_860:
	/* 0x860: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_865:
	/* 0x865: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_86c:
	/* 0x86c: movabs rax,0x40000007a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869306ULL);
x86_l_876:
	/* 0x876: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_87b:
	/* 0x87b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_882:
	/* 0x882: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_887:
	/* 0x887: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_88c:
	/* 0x88c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_88e:
	/* 0x88e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_891:
	/* 0x891: je     aa6 <generic_tracepoint_event+0xaa6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_aa6;
	}
x86_l_897:
	/* 0x897: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_899:
	/* 0x899: movsx  r12,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_89f:
	/* 0x89f: jmp    b84 <generic_tracepoint_event+0xb84> */
	goto x86_l_b84;
x86_l_8a4:
	/* 0x8a4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8a9:
	/* 0x8a9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_8ae:
	/* 0x8ae: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_8b3:
	/* 0x8b3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8b8:
	/* 0x8b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8ba:
	/* 0x8ba: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8bd:
	/* 0x8bd: je     b28 <generic_tracepoint_event+0xb28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b28;
	}
x86_l_8c3:
	/* 0x8c3: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_8c5:
	/* 0x8c5: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8ca:
	/* 0x8ca: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_8d1:
	/* 0x8d1: movabs rax,0x4000000a1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869345ULL);
x86_l_8db:
	/* 0x8db: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_8e0:
	/* 0x8e0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_8e7:
	/* 0x8e7: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8ec:
	/* 0x8ec: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8f1:
	/* 0x8f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8f3:
	/* 0x8f3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8f6:
	/* 0x8f6: jne    979 <generic_tracepoint_event+0x979> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_979;
	}
x86_l_8fc:
	/* 0x8fc: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_904:
	/* 0x904: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_90b:
	/* 0x90b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_90d:
	/* 0x90d: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_912:
	/* 0x912: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_917:
	/* 0x917: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_91c:
	/* 0x91c: jmp    b24 <generic_tracepoint_event+0xb24> */
	goto x86_l_b24;
x86_l_921:
	/* 0x921: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_926:
	/* 0x926: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_92b:
	/* 0x92b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_930:
	/* 0x930: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_935:
	/* 0x935: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_937:
	/* 0x937: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_93a:
	/* 0x93a: je     b28 <generic_tracepoint_event+0xb28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b28;
	}
x86_l_940:
	/* 0x940: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_942:
	/* 0x942: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_947:
	/* 0x947: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_94e:
	/* 0x94e: movabs rax,0x40000004e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869262ULL);
x86_l_958:
	/* 0x958: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_95d:
	/* 0x95d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_964:
	/* 0x964: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_969:
	/* 0x969: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_96e:
	/* 0x96e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_970:
	/* 0x970: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_973:
	/* 0x973: je     b04 <generic_tracepoint_event+0xb04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b04;
	}
x86_l_979:
	/* 0x979: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_97b:
	/* 0x97b: jmp    b28 <generic_tracepoint_event+0xb28> */
	goto x86_l_b28;
x86_l_980:
	/* 0x980: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_985:
	/* 0x985: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_98a:
	/* 0x98a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_98f:
	/* 0x98f: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_994:
	/* 0x994: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_996:
	/* 0x996: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_999:
	/* 0x999: je     b53 <generic_tracepoint_event+0xb53> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b53;
	}
x86_l_99f:
	/* 0x99f: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_9a1:
	/* 0x9a1: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9a6:
	/* 0x9a6: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_9ad:
	/* 0x9ad: movabs rax,0x400000065 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869285ULL);
x86_l_9b7:
	/* 0x9b7: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_9bc:
	/* 0x9bc: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_9c3:
	/* 0x9c3: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9c8:
	/* 0x9c8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9cd:
	/* 0x9cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9cf:
	/* 0x9cf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9d2:
	/* 0x9d2: je     b2f <generic_tracepoint_event+0xb2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b2f;
	}
x86_l_9d8:
	/* 0x9d8: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_9da:
	/* 0x9da: movzx  r12d,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_9e0:
	/* 0x9e0: jmp    b84 <generic_tracepoint_event+0xb84> */
	goto x86_l_b84;
x86_l_9e5:
	/* 0x9e5: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9ea:
	/* 0x9ea: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_9ef:
	/* 0x9ef: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_9f4:
	/* 0x9f4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_9f9:
	/* 0x9f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9fb:
	/* 0x9fb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9fe:
	/* 0x9fe: je     b7f <generic_tracepoint_event+0xb7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b7f;
	}
x86_l_a04:
	/* 0xa04: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_a06:
	/* 0xa06: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a0b:
	/* 0xa0b: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_a12:
	/* 0xa12: movabs rax,0x400000088 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869320ULL);
x86_l_a1c:
	/* 0xa1c: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_a21:
	/* 0xa21: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_a28:
	/* 0xa28: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a2d:
	/* 0xa2d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a32:
	/* 0xa32: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a34:
	/* 0xa34: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a37:
	/* 0xa37: je     b5b <generic_tracepoint_event+0xb5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b5b;
	}
x86_l_a3d:
	/* 0xa3d: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_a3f:
	/* 0xa3f: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a44:
	/* 0xa44: jmp    b84 <generic_tracepoint_event+0xb84> */
	goto x86_l_b84;
x86_l_a49:
	/* 0xa49: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_a51:
	/* 0xa51: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_a58:
	/* 0xa58: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a5a:
	/* 0xa5a: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a5f:
	/* 0xa5f: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a64:
	/* 0xa64: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_a69:
	/* 0xa69: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a6b:
	/* 0xa6b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a6d:
	/* 0xa6d: movsxd r12,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_a72:
	/* 0xa72: jmp    b84 <generic_tracepoint_event+0xb84> */
	goto x86_l_b84;
x86_l_a77:
	/* 0xa77: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_a7f:
	/* 0xa7f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_a86:
	/* 0xa86: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a88:
	/* 0xa88: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a8d:
	/* 0xa8d: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a92:
	/* 0xa92: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_a97:
	/* 0xa97: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a99:
	/* 0xa99: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a9b:
	/* 0xa9b: movsx  r12,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_aa1:
	/* 0xaa1: jmp    b84 <generic_tracepoint_event+0xb84> */
	goto x86_l_b84;
x86_l_aa6:
	/* 0xaa6: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_aae:
	/* 0xaae: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_ab5:
	/* 0xab5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ab7:
	/* 0xab7: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_abc:
	/* 0xabc: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ac1:
	/* 0xac1: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_ac6:
	/* 0xac6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ac8:
	/* 0xac8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aca:
	/* 0xaca: movsx  r12,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_ad0:
	/* 0xad0: jmp    b84 <generic_tracepoint_event+0xb84> */
	goto x86_l_b84;
x86_l_ad5:
	/* 0xad5: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_add:
	/* 0xadd: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_ae4:
	/* 0xae4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ae6:
	/* 0xae6: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_aeb:
	/* 0xaeb: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_af0:
	/* 0xaf0: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_af5:
	/* 0xaf5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_af7:
	/* 0xaf7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_af9:
	/* 0xaf9: movzx  r12d,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_aff:
	/* 0xaff: jmp    b84 <generic_tracepoint_event+0xb84> */
	goto x86_l_b84;
x86_l_b04:
	/* 0xb04: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_b0c:
	/* 0xb0c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_b13:
	/* 0xb13: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b15:
	/* 0xb15: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b1a:
	/* 0xb1a: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b1f:
	/* 0xb1f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_b24:
	/* 0xb24: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b26:
	/* 0xb26: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b28:
	/* 0xb28: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b2d:
	/* 0xb2d: jmp    b84 <generic_tracepoint_event+0xb84> */
	goto x86_l_b84;
x86_l_b2f:
	/* 0xb2f: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_b37:
	/* 0xb37: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_b3e:
	/* 0xb3e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b40:
	/* 0xb40: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b45:
	/* 0xb45: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b4a:
	/* 0xb4a: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_b4f:
	/* 0xb4f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b51:
	/* 0xb51: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b53:
	/* 0xb53: movzx  r12d,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_b59:
	/* 0xb59: jmp    b84 <generic_tracepoint_event+0xb84> */
	goto x86_l_b84;
x86_l_b5b:
	/* 0xb5b: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_b63:
	/* 0xb63: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_b6a:
	/* 0xb6a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b6c:
	/* 0xb6c: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b71:
	/* 0xb71: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b76:
	/* 0xb76: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_b7b:
	/* 0xb7b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b7d:
	/* 0xb7d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b7f:
	/* 0xb7f: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b84:
	/* 0xb84: mov    QWORD PTR [r14+0x5e50],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24144ULL);
x86_l_b8b:
	/* 0xb8b: movzx  edx,WORD PTR [r15+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_b90:
	/* 0xb90: mov    r13d,DWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b94:
	/* 0xb94: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_b97:
	/* 0xb97: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b9a:
	/* 0xb9a: cmp    r13d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 11ULL);
x86_l_b9e:
	/* 0xb9e: jg     bd7 <generic_tracepoint_event+0xbd7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_bd7;
	}
x86_l_ba0:
	/* 0xba0: cmp    r13d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 3ULL);
x86_l_ba4:
	/* 0xba4: jle    c6e <generic_tracepoint_event+0xc6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_c6e;
	}
x86_l_baa:
	/* 0xbaa: cmp    r13d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 6ULL);
x86_l_bae:
	/* 0xbae: jg     d99 <generic_tracepoint_event+0xd99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_d99;
	}
x86_l_bb4:
	/* 0xbb4: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_bb8:
	/* 0xbb8: je     11fe <generic_tracepoint_event+0x11fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4606ULL;
	}
x86_l_bbe:
	/* 0xbbe: cmp    r13d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 5ULL);
x86_l_bc2:
	/* 0xbc2: je     109f <generic_tracepoint_event+0x109f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4255ULL;
	}
x86_l_bc8:
	/* 0xbc8: cmp    r13d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 6ULL);
x86_l_bcc:
	/* 0xbcc: je     c8f <generic_tracepoint_event+0xc8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c8f;
	}
x86_l_bd2:
	/* 0xbd2: jmp    1461 <generic_tracepoint_event+0x1461> */
	return 5217ULL;
x86_l_bd7:
	/* 0xbd7: cmp    r13d,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 29ULL);
x86_l_bdb:
	/* 0xbdb: jle    d0c <generic_tracepoint_event+0xd0c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_d0c;
	}
x86_l_be1:
	/* 0xbe1: cmp    r13d,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 37ULL);
x86_l_be5:
	/* 0xbe5: jg     e05 <generic_tracepoint_event+0xe05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_e05;
	}
x86_l_beb:
	/* 0xbeb: cmp    r13d,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 30ULL);
x86_l_bef:
	/* 0xbef: je     125d <generic_tracepoint_event+0x125d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4701ULL;
	}
x86_l_bf5:
	/* 0xbf5: cmp    r13d,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 31ULL);
x86_l_bf9:
	/* 0xbf9: je     111c <generic_tracepoint_event+0x111c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4380ULL;
	}
x86_l_bff:
	/* 0xbff: cmp    r13d,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 32ULL);
x86_l_c03:
	/* 0xc03: jne    1461 <generic_tracepoint_event+0x1461> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5217ULL;
	}
x86_l_c09:
	/* 0xc09: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c0e:
	/* 0xc0e: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_c13:
	/* 0xc13: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c18:
	/* 0xc18: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_c1d:
	/* 0xc1d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c1f:
	/* 0xc1f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c22:
	/* 0xc22: je     13d6 <generic_tracepoint_event+0x13d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5078ULL;
	}
x86_l_c28:
	/* 0xc28: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_c2a:
	/* 0xc2a: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c2f:
	/* 0xc2f: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_c36:
	/* 0xc36: movabs rax,0x400000073 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869299ULL);
x86_l_c40:
	/* 0xc40: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_c45:
	/* 0xc45: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_c4c:
	/* 0xc4c: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c51:
	/* 0xc51: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c56:
	/* 0xc56: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c58:
	/* 0xc58: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c5b:
	/* 0xc5b: je     13b2 <generic_tracepoint_event+0x13b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5042ULL;
	}
x86_l_c61:
	/* 0xc61: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_c63:
	/* 0xc63: movzx  r12d,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_c69:
	/* 0xc69: jmp    1461 <generic_tracepoint_event+0x1461> */
	return 5217ULL;
x86_l_c6e:
	/* 0xc6e: cmp    r13d,0xfffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4294967284ULL);
x86_l_c72:
	/* 0xc72: jle    ea0 <generic_tracepoint_event+0xea0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3744ULL;
	}
x86_l_c78:
	/* 0xc78: lea    eax,[r13+0xb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 11ULL);
x86_l_c7c:
	/* 0xc7c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c7f:
	/* 0xc7f: jb     da6 <generic_tracepoint_event+0xda6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_da6;
	}
x86_l_c85:
	/* 0xc85: cmp    r13d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 2ULL);
x86_l_c89:
	/* 0xc89: jne    1461 <generic_tracepoint_event+0x1461> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5217ULL;
	}
x86_l_c8f:
	/* 0xc8f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c94:
	/* 0xc94: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_c99:
	/* 0xc99: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c9e:
	/* 0xc9e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ca3:
	/* 0xca3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ca5:
	/* 0xca5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ca8:
	/* 0xca8: je     1405 <generic_tracepoint_event+0x1405> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5125ULL;
	}
x86_l_cae:
	/* 0xcae: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_cb0:
	/* 0xcb0: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_cb5:
	/* 0xcb5: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_cbc:
	/* 0xcbc: movabs rax,0x400000081 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869313ULL);
x86_l_cc6:
	/* 0xcc6: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_ccb:
	/* 0xccb: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_cd2:
	/* 0xcd2: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_cd7:
	/* 0xcd7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_cdc:
	/* 0xcdc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cde:
	/* 0xcde: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ce1:
	/* 0xce1: jne    1256 <generic_tracepoint_event+0x1256> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4694ULL;
	}
x86_l_ce7:
	/* 0xce7: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_cef:
	/* 0xcef: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_cf6:
	/* 0xcf6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cf8:
	/* 0xcf8: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_cfd:
	/* 0xcfd: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d02:
	/* 0xd02: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d07:
	/* 0xd07: jmp    1401 <generic_tracepoint_event+0x1401> */
	return 5121ULL;
x86_l_d0c:
	/* 0xd0c: cmp    r13d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 17ULL);
x86_l_d10:
	/* 0xd10: jle    eb5 <generic_tracepoint_event+0xeb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3765ULL;
	}
x86_l_d16:
	/* 0xd16: cmp    r13d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 18ULL);
x86_l_d1a:
	/* 0xd1a: je     1097 <generic_tracepoint_event+0x1097> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4247ULL;
	}
x86_l_d20:
	/* 0xd20: cmp    r13d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 28ULL);
x86_l_d24:
	/* 0xd24: je     da6 <generic_tracepoint_event+0xda6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_da6;
	}
x86_l_d2a:
	/* 0xd2a: cmp    r13d,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 29ULL);
x86_l_d2e:
	/* 0xd2e: jne    1461 <generic_tracepoint_event+0x1461> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5217ULL;
	}
x86_l_d34:
	/* 0xd34: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d39:
	/* 0xd39: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_d3e:
	/* 0xd3e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d43:
	/* 0xd43: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_d48:
	/* 0xd48: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d4a:
	/* 0xd4a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d4d:
	/* 0xd4d: je     1378 <generic_tracepoint_event+0x1378> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4984ULL;
	}
x86_l_d53:
	/* 0xd53: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_d55:
	/* 0xd55: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d5a:
	/* 0xd5a: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_d61:
	/* 0xd61: movabs rax,0x40000006c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869292ULL);
x86_l_d6b:
	/* 0xd6b: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_d70:
	/* 0xd70: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_d77:
	/* 0xd77: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d7c:
	/* 0xd7c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d81:
	/* 0xd81: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d83:
	/* 0xd83: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d86:
	/* 0xd86: je     1354 <generic_tracepoint_event+0x1354> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4948ULL;
	}
x86_l_d8c:
	/* 0xd8c: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_d8e:
	/* 0xd8e: movsx  r12,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_d94:
	/* 0xd94: jmp    1461 <generic_tracepoint_event+0x1461> */
	return 5217ULL;
x86_l_d99:
	/* 0xd99: lea    eax,[r13-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_d9d:
	/* 0xd9d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_da0:
	/* 0xda0: jae    1010 <generic_tracepoint_event+0x1010> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4112ULL;
	}
x86_l_da6:
	/* 0xda6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dab:
	/* 0xdab: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_db0:
	/* 0xdb0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_db5:
	/* 0xdb5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_dba:
	/* 0xdba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dbc:
	/* 0xdbc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_dbf:
	/* 0xdbf: je     fce <generic_tracepoint_event+0xfce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4046ULL;
	}
x86_l_dc5:
	/* 0xdc5: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_dc7:
	/* 0xdc7: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_dcc:
	/* 0xdcc: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_dd3:
	/* 0xdd3: movabs rax,0x400000045 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869253ULL);
x86_l_ddd:
	/* 0xddd: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_de2:
	/* 0xde2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_de9:
	/* 0xde9: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_dee:
	/* 0xdee: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_df3:
	/* 0xdf3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_df5:
	/* 0xdf5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_df8:
	/* 0xdf8: je     faa <generic_tracepoint_event+0xfaa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4010ULL;
	}
x86_l_dfe:
	/* 0xdfe: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_e00:
	/* 0xe00: jmp    fce <generic_tracepoint_event+0xfce> */
	return 4046ULL;
x86_l_e05:
	/* 0xe05: cmp    r13d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 38ULL);
x86_l_e09:
	/* 0xe09: je     12c2 <generic_tracepoint_event+0x12c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4802ULL;
	}
x86_l_e0f:
	/* 0xe0f: cmp    r13d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 40ULL);
x86_l_e13:
	/* 0xe13: je     1181 <generic_tracepoint_event+0x1181> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4481ULL;
	}
x86_l_e19:
	/* 0xe19: cmp    r13d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 41ULL);
x86_l_e1d:
	/* 0xe1d: jne    1461 <generic_tracepoint_event+0x1461> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5217ULL;
	}
x86_l_e23:
	/* 0xe23: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e28:
	/* 0xe28: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_e2d:
	/* 0xe2d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
	return 3634ULL;
}

static __noinline __u64 tetragon_bpf_generic_tracepoint_v53_generic_tracepoint_event_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3634ULL: goto x86_l_e32;
	case 3639ULL: goto x86_l_e37;
	case 3641ULL: goto x86_l_e39;
	case 3644ULL: goto x86_l_e3c;
	case 3650ULL: goto x86_l_e42;
	case 3652ULL: goto x86_l_e44;
	case 3657ULL: goto x86_l_e49;
	case 3664ULL: goto x86_l_e50;
	case 3674ULL: goto x86_l_e5a;
	case 3679ULL: goto x86_l_e5f;
	case 3686ULL: goto x86_l_e66;
	case 3691ULL: goto x86_l_e6b;
	case 3696ULL: goto x86_l_e70;
	case 3698ULL: goto x86_l_e72;
	case 3701ULL: goto x86_l_e75;
	case 3707ULL: goto x86_l_e7b;
	case 3715ULL: goto x86_l_e83;
	case 3722ULL: goto x86_l_e8a;
	case 3724ULL: goto x86_l_e8c;
	case 3729ULL: goto x86_l_e91;
	case 3734ULL: goto x86_l_e96;
	case 3739ULL: goto x86_l_e9b;
	case 3744ULL: goto x86_l_ea0;
	case 3748ULL: goto x86_l_ea4;
	case 3754ULL: goto x86_l_eaa;
	case 3758ULL: goto x86_l_eae;
	case 3760ULL: goto x86_l_eb0;
	case 3765ULL: goto x86_l_eb5;
	case 3769ULL: goto x86_l_eb9;
	case 3775ULL: goto x86_l_ebf;
	case 3779ULL: goto x86_l_ec3;
	case 3785ULL: goto x86_l_ec9;
	case 3790ULL: goto x86_l_ece;
	case 3795ULL: goto x86_l_ed3;
	case 3800ULL: goto x86_l_ed8;
	case 3805ULL: goto x86_l_edd;
	case 3807ULL: goto x86_l_edf;
	case 3810ULL: goto x86_l_ee2;
	case 3816ULL: goto x86_l_ee8;
	case 3818ULL: goto x86_l_eea;
	case 3823ULL: goto x86_l_eef;
	case 3830ULL: goto x86_l_ef6;
	case 3840ULL: goto x86_l_f00;
	case 3845ULL: goto x86_l_f05;
	case 3852ULL: goto x86_l_f0c;
	case 3857ULL: goto x86_l_f11;
	case 3862ULL: goto x86_l_f16;
	case 3864ULL: goto x86_l_f18;
	case 3867ULL: goto x86_l_f1b;
	case 3873ULL: goto x86_l_f21;
	case 3881ULL: goto x86_l_f29;
	case 3888ULL: goto x86_l_f30;
	case 3890ULL: goto x86_l_f32;
	case 3895ULL: goto x86_l_f37;
	case 3900ULL: goto x86_l_f3c;
	case 3905ULL: goto x86_l_f41;
	case 3910ULL: goto x86_l_f46;
	case 3915ULL: goto x86_l_f4b;
	case 3920ULL: goto x86_l_f50;
	case 3925ULL: goto x86_l_f55;
	case 3930ULL: goto x86_l_f5a;
	case 3932ULL: goto x86_l_f5c;
	case 3935ULL: goto x86_l_f5f;
	case 3941ULL: goto x86_l_f65;
	case 3943ULL: goto x86_l_f67;
	case 3948ULL: goto x86_l_f6c;
	case 3955ULL: goto x86_l_f73;
	case 3965ULL: goto x86_l_f7d;
	case 3970ULL: goto x86_l_f82;
	case 3977ULL: goto x86_l_f89;
	case 3982ULL: goto x86_l_f8e;
	case 3987ULL: goto x86_l_f93;
	case 3989ULL: goto x86_l_f95;
	case 3992ULL: goto x86_l_f98;
	case 3998ULL: goto x86_l_f9e;
	case 4000ULL: goto x86_l_fa0;
	case 4005ULL: goto x86_l_fa5;
	case 4010ULL: goto x86_l_faa;
	case 4018ULL: goto x86_l_fb2;
	case 4025ULL: goto x86_l_fb9;
	case 4027ULL: goto x86_l_fbb;
	case 4032ULL: goto x86_l_fc0;
	case 4037ULL: goto x86_l_fc5;
	case 4042ULL: goto x86_l_fca;
	case 4044ULL: goto x86_l_fcc;
	case 4046ULL: goto x86_l_fce;
	case 4051ULL: goto x86_l_fd3;
	case 4055ULL: goto x86_l_fd7;
	case 4061ULL: goto x86_l_fdd;
	case 4066ULL: goto x86_l_fe2;
	case 4068ULL: goto x86_l_fe4;
	case 4072ULL: goto x86_l_fe8;
	case 4077ULL: goto x86_l_fed;
	case 4082ULL: goto x86_l_ff2;
	case 4087ULL: goto x86_l_ff7;
	case 4092ULL: goto x86_l_ffc;
	case 4094ULL: goto x86_l_ffe;
	case 4098ULL: goto x86_l_1002;
	case 4101ULL: goto x86_l_1005;
	case 4104ULL: goto x86_l_1008;
	case 4107ULL: goto x86_l_100b;
	case 4112ULL: goto x86_l_1010;
	case 4116ULL: goto x86_l_1014;
	case 4122ULL: goto x86_l_101a;
	case 4127ULL: goto x86_l_101f;
	case 4132ULL: goto x86_l_1024;
	case 4137ULL: goto x86_l_1029;
	case 4142ULL: goto x86_l_102e;
	case 4144ULL: goto x86_l_1030;
	case 4147ULL: goto x86_l_1033;
	case 4153ULL: goto x86_l_1039;
	case 4155ULL: goto x86_l_103b;
	case 4160ULL: goto x86_l_1040;
	case 4167ULL: goto x86_l_1047;
	case 4177ULL: goto x86_l_1051;
	case 4182ULL: goto x86_l_1056;
	case 4189ULL: goto x86_l_105d;
	case 4194ULL: goto x86_l_1062;
	case 4199ULL: goto x86_l_1067;
	case 4201ULL: goto x86_l_1069;
	case 4204ULL: goto x86_l_106c;
	case 4210ULL: goto x86_l_1072;
	case 4218ULL: goto x86_l_107a;
	case 4225ULL: goto x86_l_1081;
	case 4227ULL: goto x86_l_1083;
	case 4232ULL: goto x86_l_1088;
	case 4237ULL: goto x86_l_108d;
	case 4242ULL: goto x86_l_1092;
	case 4247ULL: goto x86_l_1097;
	case 4250ULL: goto x86_l_109a;
	case 4255ULL: goto x86_l_109f;
	case 4260ULL: goto x86_l_10a4;
	case 4265ULL: goto x86_l_10a9;
	case 4270ULL: goto x86_l_10ae;
	case 4275ULL: goto x86_l_10b3;
	case 4277ULL: goto x86_l_10b5;
	case 4280ULL: goto x86_l_10b8;
	case 4286ULL: goto x86_l_10be;
	case 4288ULL: goto x86_l_10c0;
	case 4293ULL: goto x86_l_10c5;
	case 4300ULL: goto x86_l_10cc;
	case 4310ULL: goto x86_l_10d6;
	case 4315ULL: goto x86_l_10db;
	case 4322ULL: goto x86_l_10e2;
	case 4327ULL: goto x86_l_10e7;
	case 4332ULL: goto x86_l_10ec;
	case 4334ULL: goto x86_l_10ee;
	case 4337ULL: goto x86_l_10f1;
	case 4343ULL: goto x86_l_10f7;
	case 4351ULL: goto x86_l_10ff;
	case 4358ULL: goto x86_l_1106;
	case 4360ULL: goto x86_l_1108;
	case 4365ULL: goto x86_l_110d;
	case 4370ULL: goto x86_l_1112;
	case 4375ULL: goto x86_l_1117;
	case 4380ULL: goto x86_l_111c;
	case 4385ULL: goto x86_l_1121;
	case 4390ULL: goto x86_l_1126;
	case 4395ULL: goto x86_l_112b;
	case 4400ULL: goto x86_l_1130;
	case 4402ULL: goto x86_l_1132;
	case 4405ULL: goto x86_l_1135;
	case 4411ULL: goto x86_l_113b;
	case 4413ULL: goto x86_l_113d;
	case 4418ULL: goto x86_l_1142;
	case 4425ULL: goto x86_l_1149;
	case 4435ULL: goto x86_l_1153;
	case 4440ULL: goto x86_l_1158;
	case 4447ULL: goto x86_l_115f;
	case 4452ULL: goto x86_l_1164;
	case 4457ULL: goto x86_l_1169;
	case 4459ULL: goto x86_l_116b;
	case 4462ULL: goto x86_l_116e;
	case 4468ULL: goto x86_l_1174;
	case 4470ULL: goto x86_l_1176;
	case 4476ULL: goto x86_l_117c;
	case 4481ULL: goto x86_l_1181;
	case 4486ULL: goto x86_l_1186;
	case 4491ULL: goto x86_l_118b;
	case 4496ULL: goto x86_l_1190;
	case 4501ULL: goto x86_l_1195;
	case 4503ULL: goto x86_l_1197;
	case 4506ULL: goto x86_l_119a;
	case 4512ULL: goto x86_l_11a0;
	case 4514ULL: goto x86_l_11a2;
	case 4519ULL: goto x86_l_11a7;
	case 4526ULL: goto x86_l_11ae;
	case 4536ULL: goto x86_l_11b8;
	case 4541ULL: goto x86_l_11bd;
	case 4548ULL: goto x86_l_11c4;
	case 4553ULL: goto x86_l_11c9;
	case 4558ULL: goto x86_l_11ce;
	case 4560ULL: goto x86_l_11d0;
	case 4563ULL: goto x86_l_11d3;
	case 4569ULL: goto x86_l_11d9;
	case 4577ULL: goto x86_l_11e1;
	case 4584ULL: goto x86_l_11e8;
	case 4586ULL: goto x86_l_11ea;
	case 4591ULL: goto x86_l_11ef;
	case 4596ULL: goto x86_l_11f4;
	case 4601ULL: goto x86_l_11f9;
	case 4606ULL: goto x86_l_11fe;
	case 4611ULL: goto x86_l_1203;
	case 4616ULL: goto x86_l_1208;
	case 4621ULL: goto x86_l_120d;
	case 4626ULL: goto x86_l_1212;
	case 4628ULL: goto x86_l_1214;
	case 4631ULL: goto x86_l_1217;
	case 4637ULL: goto x86_l_121d;
	case 4639ULL: goto x86_l_121f;
	case 4644ULL: goto x86_l_1224;
	case 4651ULL: goto x86_l_122b;
	case 4661ULL: goto x86_l_1235;
	case 4666ULL: goto x86_l_123a;
	case 4673ULL: goto x86_l_1241;
	case 4678ULL: goto x86_l_1246;
	case 4683ULL: goto x86_l_124b;
	case 4685ULL: goto x86_l_124d;
	case 4688ULL: goto x86_l_1250;
	case 4694ULL: goto x86_l_1256;
	case 4696ULL: goto x86_l_1258;
	case 4701ULL: goto x86_l_125d;
	case 4706ULL: goto x86_l_1262;
	case 4711ULL: goto x86_l_1267;
	case 4716ULL: goto x86_l_126c;
	case 4721ULL: goto x86_l_1271;
	case 4723ULL: goto x86_l_1273;
	case 4726ULL: goto x86_l_1276;
	case 4732ULL: goto x86_l_127c;
	case 4734ULL: goto x86_l_127e;
	case 4739ULL: goto x86_l_1283;
	case 4746ULL: goto x86_l_128a;
	case 4756ULL: goto x86_l_1294;
	case 4761ULL: goto x86_l_1299;
	case 4768ULL: goto x86_l_12a0;
	case 4773ULL: goto x86_l_12a5;
	case 4778ULL: goto x86_l_12aa;
	case 4780ULL: goto x86_l_12ac;
	case 4783ULL: goto x86_l_12af;
	case 4789ULL: goto x86_l_12b5;
	case 4791ULL: goto x86_l_12b7;
	case 4797ULL: goto x86_l_12bd;
	case 4802ULL: goto x86_l_12c2;
	case 4807ULL: goto x86_l_12c7;
	case 4812ULL: goto x86_l_12cc;
	case 4817ULL: goto x86_l_12d1;
	case 4822ULL: goto x86_l_12d6;
	case 4824ULL: goto x86_l_12d8;
	case 4827ULL: goto x86_l_12db;
	case 4833ULL: goto x86_l_12e1;
	case 4835ULL: goto x86_l_12e3;
	case 4840ULL: goto x86_l_12e8;
	case 4847ULL: goto x86_l_12ef;
	case 4857ULL: goto x86_l_12f9;
	case 4862ULL: goto x86_l_12fe;
	case 4869ULL: goto x86_l_1305;
	case 4874ULL: goto x86_l_130a;
	case 4879ULL: goto x86_l_130f;
	case 4881ULL: goto x86_l_1311;
	case 4884ULL: goto x86_l_1314;
	case 4890ULL: goto x86_l_131a;
	case 4892ULL: goto x86_l_131c;
	case 4897ULL: goto x86_l_1321;
	case 4902ULL: goto x86_l_1326;
	case 4910ULL: goto x86_l_132e;
	case 4917ULL: goto x86_l_1335;
	case 4919ULL: goto x86_l_1337;
	case 4924ULL: goto x86_l_133c;
	case 4929ULL: goto x86_l_1341;
	case 4934ULL: goto x86_l_1346;
	case 4936ULL: goto x86_l_1348;
	case 4938ULL: goto x86_l_134a;
	case 4943ULL: goto x86_l_134f;
	case 4948ULL: goto x86_l_1354;
	case 4956ULL: goto x86_l_135c;
	case 4963ULL: goto x86_l_1363;
	case 4965ULL: goto x86_l_1365;
	case 4970ULL: goto x86_l_136a;
	case 4975ULL: goto x86_l_136f;
	case 4980ULL: goto x86_l_1374;
	case 4982ULL: goto x86_l_1376;
	case 4984ULL: goto x86_l_1378;
	case 4990ULL: goto x86_l_137e;
	case 4995ULL: goto x86_l_1383;
	case 5003ULL: goto x86_l_138b;
	case 5010ULL: goto x86_l_1392;
	case 5012ULL: goto x86_l_1394;
	case 5017ULL: goto x86_l_1399;
	case 5022ULL: goto x86_l_139e;
	case 5027ULL: goto x86_l_13a3;
	case 5029ULL: goto x86_l_13a5;
	case 5031ULL: goto x86_l_13a7;
	case 5037ULL: goto x86_l_13ad;
	case 5042ULL: goto x86_l_13b2;
	case 5050ULL: goto x86_l_13ba;
	case 5057ULL: goto x86_l_13c1;
	case 5059ULL: goto x86_l_13c3;
	case 5064ULL: goto x86_l_13c8;
	case 5069ULL: goto x86_l_13cd;
	case 5074ULL: goto x86_l_13d2;
	case 5076ULL: goto x86_l_13d4;
	case 5078ULL: goto x86_l_13d6;
	case 5084ULL: goto x86_l_13dc;
	case 5089ULL: goto x86_l_13e1;
	case 5097ULL: goto x86_l_13e9;
	case 5104ULL: goto x86_l_13f0;
	case 5106ULL: goto x86_l_13f2;
	case 5111ULL: goto x86_l_13f7;
	case 5116ULL: goto x86_l_13fc;
	case 5121ULL: goto x86_l_1401;
	case 5123ULL: goto x86_l_1403;
	case 5125ULL: goto x86_l_1405;
	case 5130ULL: goto x86_l_140a;
	case 5132ULL: goto x86_l_140c;
	case 5140ULL: goto x86_l_1414;
	case 5147ULL: goto x86_l_141b;
	case 5149ULL: goto x86_l_141d;
	case 5154ULL: goto x86_l_1422;
	case 5159ULL: goto x86_l_1427;
	case 5164ULL: goto x86_l_142c;
	case 5166ULL: goto x86_l_142e;
	case 5168ULL: goto x86_l_1430;
	case 5174ULL: goto x86_l_1436;
	case 5176ULL: goto x86_l_1438;
	case 5184ULL: goto x86_l_1440;
	case 5191ULL: goto x86_l_1447;
	case 5193ULL: goto x86_l_1449;
	case 5198ULL: goto x86_l_144e;
	case 5203ULL: goto x86_l_1453;
	case 5208ULL: goto x86_l_1458;
	case 5210ULL: goto x86_l_145a;
	case 5212ULL: goto x86_l_145c;
	case 5217ULL: goto x86_l_1461;
	case 5224ULL: goto x86_l_1468;
	case 5229ULL: goto x86_l_146d;
	case 5233ULL: goto x86_l_1471;
	case 5236ULL: goto x86_l_1474;
	case 5239ULL: goto x86_l_1477;
	case 5243ULL: goto x86_l_147b;
	case 5245ULL: goto x86_l_147d;
	case 5249ULL: goto x86_l_1481;
	case 5255ULL: goto x86_l_1487;
	case 5259ULL: goto x86_l_148b;
	case 5265ULL: goto x86_l_1491;
	case 5269ULL: goto x86_l_1495;
	case 5275ULL: goto x86_l_149b;
	case 5279ULL: goto x86_l_149f;
	case 5285ULL: goto x86_l_14a5;
	case 5289ULL: goto x86_l_14a9;
	case 5295ULL: goto x86_l_14af;
	case 5300ULL: goto x86_l_14b4;
	case 5304ULL: goto x86_l_14b8;
	case 5310ULL: goto x86_l_14be;
	case 5314ULL: goto x86_l_14c2;
	case 5320ULL: goto x86_l_14c8;
	case 5324ULL: goto x86_l_14cc;
	case 5330ULL: goto x86_l_14d2;
	case 5334ULL: goto x86_l_14d6;
	case 5340ULL: goto x86_l_14dc;
	case 5344ULL: goto x86_l_14e0;
	case 5350ULL: goto x86_l_14e6;
	case 5355ULL: goto x86_l_14eb;
	case 5360ULL: goto x86_l_14f0;
	case 5365ULL: goto x86_l_14f5;
	case 5370ULL: goto x86_l_14fa;
	case 5372ULL: goto x86_l_14fc;
	case 5375ULL: goto x86_l_14ff;
	case 5381ULL: goto x86_l_1505;
	case 5383ULL: goto x86_l_1507;
	case 5388ULL: goto x86_l_150c;
	case 5395ULL: goto x86_l_1513;
	case 5405ULL: goto x86_l_151d;
	case 5410ULL: goto x86_l_1522;
	case 5417ULL: goto x86_l_1529;
	case 5422ULL: goto x86_l_152e;
	case 5427ULL: goto x86_l_1533;
	case 5429ULL: goto x86_l_1535;
	case 5432ULL: goto x86_l_1538;
	case 5438ULL: goto x86_l_153e;
	case 5440ULL: goto x86_l_1540;
	case 5446ULL: goto x86_l_1546;
	case 5451ULL: goto x86_l_154b;
	case 5455ULL: goto x86_l_154f;
	case 5461ULL: goto x86_l_1555;
	default: return 0xffffffffffffffffULL;
	}
x86_l_e32:
	/* 0xe32: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e37:
	/* 0xe37: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e39:
	/* 0xe39: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e3c:
	/* 0xe3c: je     1405 <generic_tracepoint_event+0x1405> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1405;
	}
x86_l_e42:
	/* 0xe42: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_e44:
	/* 0xe44: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e49:
	/* 0xe49: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_e50:
	/* 0xe50: movabs rax,0x4000000a8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869352ULL);
x86_l_e5a:
	/* 0xe5a: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_e5f:
	/* 0xe5f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_e66:
	/* 0xe66: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e6b:
	/* 0xe6b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e70:
	/* 0xe70: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e72:
	/* 0xe72: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e75:
	/* 0xe75: jne    1256 <generic_tracepoint_event+0x1256> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1256;
	}
x86_l_e7b:
	/* 0xe7b: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_e83:
	/* 0xe83: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_e8a:
	/* 0xe8a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e8c:
	/* 0xe8c: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e91:
	/* 0xe91: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e96:
	/* 0xe96: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_e9b:
	/* 0xe9b: jmp    1401 <generic_tracepoint_event+0x1401> */
	goto x86_l_1401;
x86_l_ea0:
	/* 0xea0: cmp    r13d,0xfffffff3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4294967283ULL);
x86_l_ea4:
	/* 0xea4: je     f46 <generic_tracepoint_event+0xf46> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f46;
	}
x86_l_eaa:
	/* 0xeaa: cmp    r13d,0xfffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4294967284ULL);
x86_l_eae:
	/* 0xeae: je     ec9 <generic_tracepoint_event+0xec9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ec9;
	}
x86_l_eb0:
	/* 0xeb0: jmp    1461 <generic_tracepoint_event+0x1461> */
	goto x86_l_1461;
x86_l_eb5:
	/* 0xeb5: cmp    r13d,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 12ULL);
x86_l_eb9:
	/* 0xeb9: je     f46 <generic_tracepoint_event+0xf46> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f46;
	}
x86_l_ebf:
	/* 0xebf: cmp    r13d,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 13ULL);
x86_l_ec3:
	/* 0xec3: jne    1461 <generic_tracepoint_event+0x1461> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1461;
	}
x86_l_ec9:
	/* 0xec9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ece:
	/* 0xece: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_ed3:
	/* 0xed3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ed8:
	/* 0xed8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_edd:
	/* 0xedd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_edf:
	/* 0xedf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ee2:
	/* 0xee2: je     145c <generic_tracepoint_event+0x145c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_145c;
	}
x86_l_ee8:
	/* 0xee8: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_eea:
	/* 0xeea: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_eef:
	/* 0xeef: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_ef6:
	/* 0xef6: movabs rax,0x40000005e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869278ULL);
x86_l_f00:
	/* 0xf00: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_f05:
	/* 0xf05: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_f0c:
	/* 0xf0c: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f11:
	/* 0xf11: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f16:
	/* 0xf16: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f18:
	/* 0xf18: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f1b:
	/* 0xf1b: jne    131a <generic_tracepoint_event+0x131a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_131a;
	}
x86_l_f21:
	/* 0xf21: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_f29:
	/* 0xf29: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_f30:
	/* 0xf30: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f32:
	/* 0xf32: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f37:
	/* 0xf37: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f3c:
	/* 0xf3c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_f41:
	/* 0xf41: jmp    1458 <generic_tracepoint_event+0x1458> */
	goto x86_l_1458;
x86_l_f46:
	/* 0xf46: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f4b:
	/* 0xf4b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_f50:
	/* 0xf50: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f55:
	/* 0xf55: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f5a:
	/* 0xf5a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f5c:
	/* 0xf5c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f5f:
	/* 0xf5f: je     134a <generic_tracepoint_event+0x134a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_134a;
	}
x86_l_f65:
	/* 0xf65: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_f67:
	/* 0xf67: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f6c:
	/* 0xf6c: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_f73:
	/* 0xf73: movabs rax,0x400000056 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869270ULL);
x86_l_f7d:
	/* 0xf7d: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_f82:
	/* 0xf82: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_f89:
	/* 0xf89: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f8e:
	/* 0xf8e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f93:
	/* 0xf93: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f95:
	/* 0xf95: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f98:
	/* 0xf98: je     1326 <generic_tracepoint_event+0x1326> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1326;
	}
x86_l_f9e:
	/* 0xf9e: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_fa0:
	/* 0xfa0: movsxd r12,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_fa5:
	/* 0xfa5: jmp    1461 <generic_tracepoint_event+0x1461> */
	goto x86_l_1461;
x86_l_faa:
	/* 0xfaa: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_fb2:
	/* 0xfb2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_fb9:
	/* 0xfb9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fbb:
	/* 0xfbb: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_fc0:
	/* 0xfc0: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fc5:
	/* 0xfc5: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_fca:
	/* 0xfca: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fcc:
	/* 0xfcc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fce:
	/* 0xfce: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fd3:
	/* 0xfd3: cmp    r13d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 28ULL);
x86_l_fd7:
	/* 0xfd7: jne    1461 <generic_tracepoint_event+0x1461> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1461;
	}
x86_l_fdd:
	/* 0xfdd: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_fe2:
	/* 0xfe2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fe4:
	/* 0xfe4: lea    rdx,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fe8:
	/* 0xfe8: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_fed:
	/* 0xfed: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_ff2:
	/* 0xff2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ff7:
	/* 0xff7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ffc:
	/* 0xffc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ffe:
	/* 0xffe: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1002:
	/* 0x1002: and    eax,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_1005:
	/* 0x1005: shl    eax,0x1e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 30ULL);
x86_l_1008:
	/* 0x1008: or     r12,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_100b:
	/* 0x100b: jmp    1461 <generic_tracepoint_event+0x1461> */
	goto x86_l_1461;
x86_l_1010:
	/* 0x1010: cmp    r13d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 7ULL);
x86_l_1014:
	/* 0x1014: jne    1461 <generic_tracepoint_event+0x1461> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1461;
	}
x86_l_101a:
	/* 0x101a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_101f:
	/* 0x101f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1024:
	/* 0x1024: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1029:
	/* 0x1029: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_102e:
	/* 0x102e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1030:
	/* 0x1030: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1033:
	/* 0x1033: je     1405 <generic_tracepoint_event+0x1405> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1405;
	}
x86_l_1039:
	/* 0x1039: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_103b:
	/* 0x103b: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1040:
	/* 0x1040: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_1047:
	/* 0x1047: movabs rax,0x40000009a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869338ULL);
x86_l_1051:
	/* 0x1051: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1056:
	/* 0x1056: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_105d:
	/* 0x105d: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1062:
	/* 0x1062: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1067:
	/* 0x1067: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1069:
	/* 0x1069: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_106c:
	/* 0x106c: jne    1256 <generic_tracepoint_event+0x1256> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1256;
	}
x86_l_1072:
	/* 0x1072: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_107a:
	/* 0x107a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1081:
	/* 0x1081: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1083:
	/* 0x1083: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1088:
	/* 0x1088: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_108d:
	/* 0x108d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1092:
	/* 0x1092: jmp    1401 <generic_tracepoint_event+0x1401> */
	goto x86_l_1401;
x86_l_1097:
	/* 0x1097: mov    r12,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_109a:
	/* 0x109a: jmp    1461 <generic_tracepoint_event+0x1461> */
	goto x86_l_1461;
x86_l_109f:
	/* 0x109f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10a4:
	/* 0x10a4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_10a9:
	/* 0x10a9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_10ae:
	/* 0x10ae: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10b3:
	/* 0x10b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10b5:
	/* 0x10b5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10b8:
	/* 0x10b8: je     1405 <generic_tracepoint_event+0x1405> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1405;
	}
x86_l_10be:
	/* 0x10be: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_10c0:
	/* 0x10c0: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_10c5:
	/* 0x10c5: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_10cc:
	/* 0x10cc: movabs rax,0x400000093 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869331ULL);
x86_l_10d6:
	/* 0x10d6: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_10db:
	/* 0x10db: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_10e2:
	/* 0x10e2: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_10e7:
	/* 0x10e7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10ec:
	/* 0x10ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10ee:
	/* 0x10ee: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10f1:
	/* 0x10f1: jne    1256 <generic_tracepoint_event+0x1256> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1256;
	}
x86_l_10f7:
	/* 0x10f7: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_10ff:
	/* 0x10ff: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1106:
	/* 0x1106: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1108:
	/* 0x1108: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_110d:
	/* 0x110d: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1112:
	/* 0x1112: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1117:
	/* 0x1117: jmp    1401 <generic_tracepoint_event+0x1401> */
	goto x86_l_1401;
x86_l_111c:
	/* 0x111c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1121:
	/* 0x1121: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1126:
	/* 0x1126: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_112b:
	/* 0x112b: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1130:
	/* 0x1130: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1132:
	/* 0x1132: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1135:
	/* 0x1135: je     13a7 <generic_tracepoint_event+0x13a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13a7;
	}
x86_l_113b:
	/* 0x113b: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_113d:
	/* 0x113d: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1142:
	/* 0x1142: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_1149:
	/* 0x1149: movabs rax,0x40000007a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869306ULL);
x86_l_1153:
	/* 0x1153: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1158:
	/* 0x1158: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_115f:
	/* 0x115f: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1164:
	/* 0x1164: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1169:
	/* 0x1169: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_116b:
	/* 0x116b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_116e:
	/* 0x116e: je     1383 <generic_tracepoint_event+0x1383> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1383;
	}
x86_l_1174:
	/* 0x1174: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1176:
	/* 0x1176: movsx  r12,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_117c:
	/* 0x117c: jmp    1461 <generic_tracepoint_event+0x1461> */
	goto x86_l_1461;
x86_l_1181:
	/* 0x1181: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1186:
	/* 0x1186: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_118b:
	/* 0x118b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1190:
	/* 0x1190: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1195:
	/* 0x1195: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1197:
	/* 0x1197: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_119a:
	/* 0x119a: je     1405 <generic_tracepoint_event+0x1405> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1405;
	}
x86_l_11a0:
	/* 0x11a0: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_11a2:
	/* 0x11a2: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11a7:
	/* 0x11a7: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_11ae:
	/* 0x11ae: movabs rax,0x4000000a1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869345ULL);
x86_l_11b8:
	/* 0x11b8: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_11bd:
	/* 0x11bd: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_11c4:
	/* 0x11c4: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11c9:
	/* 0x11c9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_11ce:
	/* 0x11ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11d0:
	/* 0x11d0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11d3:
	/* 0x11d3: jne    1256 <generic_tracepoint_event+0x1256> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1256;
	}
x86_l_11d9:
	/* 0x11d9: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_11e1:
	/* 0x11e1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_11e8:
	/* 0x11e8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11ea:
	/* 0x11ea: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11ef:
	/* 0x11ef: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11f4:
	/* 0x11f4: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_11f9:
	/* 0x11f9: jmp    1401 <generic_tracepoint_event+0x1401> */
	goto x86_l_1401;
x86_l_11fe:
	/* 0x11fe: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1203:
	/* 0x1203: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1208:
	/* 0x1208: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_120d:
	/* 0x120d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1212:
	/* 0x1212: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1214:
	/* 0x1214: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1217:
	/* 0x1217: je     1405 <generic_tracepoint_event+0x1405> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1405;
	}
x86_l_121d:
	/* 0x121d: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_121f:
	/* 0x121f: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1224:
	/* 0x1224: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_122b:
	/* 0x122b: movabs rax,0x40000004e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869262ULL);
x86_l_1235:
	/* 0x1235: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_123a:
	/* 0x123a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1241:
	/* 0x1241: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1246:
	/* 0x1246: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_124b:
	/* 0x124b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_124d:
	/* 0x124d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1250:
	/* 0x1250: je     13e1 <generic_tracepoint_event+0x13e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13e1;
	}
x86_l_1256:
	/* 0x1256: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1258:
	/* 0x1258: jmp    1405 <generic_tracepoint_event+0x1405> */
	goto x86_l_1405;
x86_l_125d:
	/* 0x125d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1262:
	/* 0x1262: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1267:
	/* 0x1267: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_126c:
	/* 0x126c: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1271:
	/* 0x1271: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1273:
	/* 0x1273: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1276:
	/* 0x1276: je     1430 <generic_tracepoint_event+0x1430> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1430;
	}
x86_l_127c:
	/* 0x127c: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_127e:
	/* 0x127e: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1283:
	/* 0x1283: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_128a:
	/* 0x128a: movabs rax,0x400000065 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869285ULL);
x86_l_1294:
	/* 0x1294: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1299:
	/* 0x1299: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_12a0:
	/* 0x12a0: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_12a5:
	/* 0x12a5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12aa:
	/* 0x12aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12ac:
	/* 0x12ac: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12af:
	/* 0x12af: je     140c <generic_tracepoint_event+0x140c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_140c;
	}
x86_l_12b5:
	/* 0x12b5: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_12b7:
	/* 0x12b7: movzx  r12d,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_12bd:
	/* 0x12bd: jmp    1461 <generic_tracepoint_event+0x1461> */
	goto x86_l_1461;
x86_l_12c2:
	/* 0x12c2: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12c7:
	/* 0x12c7: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_12cc:
	/* 0x12cc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12d1:
	/* 0x12d1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_12d6:
	/* 0x12d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12d8:
	/* 0x12d8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12db:
	/* 0x12db: je     145c <generic_tracepoint_event+0x145c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_145c;
	}
x86_l_12e1:
	/* 0x12e1: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_12e3:
	/* 0x12e3: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_12e8:
	/* 0x12e8: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_12ef:
	/* 0x12ef: movabs rax,0x400000088 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869320ULL);
x86_l_12f9:
	/* 0x12f9: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_12fe:
	/* 0x12fe: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1305:
	/* 0x1305: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_130a:
	/* 0x130a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_130f:
	/* 0x130f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1311:
	/* 0x1311: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1314:
	/* 0x1314: je     1438 <generic_tracepoint_event+0x1438> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1438;
	}
x86_l_131a:
	/* 0x131a: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_131c:
	/* 0x131c: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1321:
	/* 0x1321: jmp    1461 <generic_tracepoint_event+0x1461> */
	goto x86_l_1461;
x86_l_1326:
	/* 0x1326: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_132e:
	/* 0x132e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1335:
	/* 0x1335: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1337:
	/* 0x1337: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_133c:
	/* 0x133c: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1341:
	/* 0x1341: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1346:
	/* 0x1346: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1348:
	/* 0x1348: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_134a:
	/* 0x134a: movsxd r12,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_134f:
	/* 0x134f: jmp    1461 <generic_tracepoint_event+0x1461> */
	goto x86_l_1461;
x86_l_1354:
	/* 0x1354: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_135c:
	/* 0x135c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1363:
	/* 0x1363: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1365:
	/* 0x1365: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_136a:
	/* 0x136a: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_136f:
	/* 0x136f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1374:
	/* 0x1374: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1376:
	/* 0x1376: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1378:
	/* 0x1378: movsx  r12,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_137e:
	/* 0x137e: jmp    1461 <generic_tracepoint_event+0x1461> */
	goto x86_l_1461;
x86_l_1383:
	/* 0x1383: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_138b:
	/* 0x138b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1392:
	/* 0x1392: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1394:
	/* 0x1394: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1399:
	/* 0x1399: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_139e:
	/* 0x139e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_13a3:
	/* 0x13a3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13a5:
	/* 0x13a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13a7:
	/* 0x13a7: movsx  r12,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_13ad:
	/* 0x13ad: jmp    1461 <generic_tracepoint_event+0x1461> */
	goto x86_l_1461;
x86_l_13b2:
	/* 0x13b2: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_13ba:
	/* 0x13ba: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_13c1:
	/* 0x13c1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13c3:
	/* 0x13c3: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_13c8:
	/* 0x13c8: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13cd:
	/* 0x13cd: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_13d2:
	/* 0x13d2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13d4:
	/* 0x13d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13d6:
	/* 0x13d6: movzx  r12d,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_13dc:
	/* 0x13dc: jmp    1461 <generic_tracepoint_event+0x1461> */
	goto x86_l_1461;
x86_l_13e1:
	/* 0x13e1: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_13e9:
	/* 0x13e9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_13f0:
	/* 0x13f0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13f2:
	/* 0x13f2: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_13f7:
	/* 0x13f7: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13fc:
	/* 0x13fc: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1401:
	/* 0x1401: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1403:
	/* 0x1403: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1405:
	/* 0x1405: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_140a:
	/* 0x140a: jmp    1461 <generic_tracepoint_event+0x1461> */
	goto x86_l_1461;
x86_l_140c:
	/* 0x140c: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_1414:
	/* 0x1414: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_141b:
	/* 0x141b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_141d:
	/* 0x141d: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1422:
	/* 0x1422: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1427:
	/* 0x1427: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_142c:
	/* 0x142c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_142e:
	/* 0x142e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1430:
	/* 0x1430: movzx  r12d,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_1436:
	/* 0x1436: jmp    1461 <generic_tracepoint_event+0x1461> */
	goto x86_l_1461;
x86_l_1438:
	/* 0x1438: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_1440:
	/* 0x1440: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1447:
	/* 0x1447: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1449:
	/* 0x1449: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_144e:
	/* 0x144e: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1453:
	/* 0x1453: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1458:
	/* 0x1458: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_145a:
	/* 0x145a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_145c:
	/* 0x145c: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1461:
	/* 0x1461: mov    QWORD PTR [r14+0x5e58],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24152ULL);
x86_l_1468:
	/* 0x1468: movzx  edx,WORD PTR [r15+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 52ULL);
x86_l_146d:
	/* 0x146d: mov    r13d,DWORD PTR [r15+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1471:
	/* 0x1471: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1474:
	/* 0x1474: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1477:
	/* 0x1477: cmp    r13d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 11ULL);
x86_l_147b:
	/* 0x147b: jg     14b4 <generic_tracepoint_event+0x14b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_14b4;
	}
x86_l_147d:
	/* 0x147d: cmp    r13d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 3ULL);
x86_l_1481:
	/* 0x1481: jle    154b <generic_tracepoint_event+0x154b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_154b;
	}
x86_l_1487:
	/* 0x1487: cmp    r13d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 6ULL);
x86_l_148b:
	/* 0x148b: jg     1676 <generic_tracepoint_event+0x1676> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5750ULL;
	}
x86_l_1491:
	/* 0x1491: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_1495:
	/* 0x1495: je     1adb <generic_tracepoint_event+0x1adb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6875ULL;
	}
x86_l_149b:
	/* 0x149b: cmp    r13d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 5ULL);
x86_l_149f:
	/* 0x149f: je     197c <generic_tracepoint_event+0x197c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6524ULL;
	}
x86_l_14a5:
	/* 0x14a5: cmp    r13d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 6ULL);
x86_l_14a9:
	/* 0x14a9: je     156c <generic_tracepoint_event+0x156c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5484ULL;
	}
x86_l_14af:
	/* 0x14af: jmp    1d3e <generic_tracepoint_event+0x1d3e> */
	return 7486ULL;
x86_l_14b4:
	/* 0x14b4: cmp    r13d,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 29ULL);
x86_l_14b8:
	/* 0x14b8: jle    15e9 <generic_tracepoint_event+0x15e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5609ULL;
	}
x86_l_14be:
	/* 0x14be: cmp    r13d,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 37ULL);
x86_l_14c2:
	/* 0x14c2: jg     16e2 <generic_tracepoint_event+0x16e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5858ULL;
	}
x86_l_14c8:
	/* 0x14c8: cmp    r13d,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 30ULL);
x86_l_14cc:
	/* 0x14cc: je     1b3a <generic_tracepoint_event+0x1b3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6970ULL;
	}
x86_l_14d2:
	/* 0x14d2: cmp    r13d,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 31ULL);
x86_l_14d6:
	/* 0x14d6: je     19f9 <generic_tracepoint_event+0x19f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6649ULL;
	}
x86_l_14dc:
	/* 0x14dc: cmp    r13d,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 32ULL);
x86_l_14e0:
	/* 0x14e0: jne    1d3e <generic_tracepoint_event+0x1d3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7486ULL;
	}
x86_l_14e6:
	/* 0x14e6: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14eb:
	/* 0x14eb: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_14f0:
	/* 0x14f0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14f5:
	/* 0x14f5: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_14fa:
	/* 0x14fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14fc:
	/* 0x14fc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14ff:
	/* 0x14ff: je     1cb3 <generic_tracepoint_event+0x1cb3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7347ULL;
	}
x86_l_1505:
	/* 0x1505: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1507:
	/* 0x1507: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_150c:
	/* 0x150c: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_1513:
	/* 0x1513: movabs rax,0x400000073 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869299ULL);
x86_l_151d:
	/* 0x151d: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1522:
	/* 0x1522: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1529:
	/* 0x1529: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_152e:
	/* 0x152e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1533:
	/* 0x1533: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1535:
	/* 0x1535: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1538:
	/* 0x1538: je     1c8f <generic_tracepoint_event+0x1c8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7311ULL;
	}
x86_l_153e:
	/* 0x153e: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1540:
	/* 0x1540: movzx  r12d,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_1546:
	/* 0x1546: jmp    1d3e <generic_tracepoint_event+0x1d3e> */
	return 7486ULL;
x86_l_154b:
	/* 0x154b: cmp    r13d,0xfffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4294967284ULL);
x86_l_154f:
	/* 0x154f: jle    177d <generic_tracepoint_event+0x177d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 6013ULL;
	}
x86_l_1555:
	/* 0x1555: lea    eax,[r13+0xb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 11ULL);
	return 5465ULL;
}

static __noinline __u64 tetragon_bpf_generic_tracepoint_v53_generic_tracepoint_event_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5465ULL: goto x86_l_1559;
	case 5468ULL: goto x86_l_155c;
	case 5474ULL: goto x86_l_1562;
	case 5478ULL: goto x86_l_1566;
	case 5484ULL: goto x86_l_156c;
	case 5489ULL: goto x86_l_1571;
	case 5494ULL: goto x86_l_1576;
	case 5499ULL: goto x86_l_157b;
	case 5504ULL: goto x86_l_1580;
	case 5506ULL: goto x86_l_1582;
	case 5509ULL: goto x86_l_1585;
	case 5515ULL: goto x86_l_158b;
	case 5517ULL: goto x86_l_158d;
	case 5522ULL: goto x86_l_1592;
	case 5529ULL: goto x86_l_1599;
	case 5539ULL: goto x86_l_15a3;
	case 5544ULL: goto x86_l_15a8;
	case 5551ULL: goto x86_l_15af;
	case 5556ULL: goto x86_l_15b4;
	case 5561ULL: goto x86_l_15b9;
	case 5563ULL: goto x86_l_15bb;
	case 5566ULL: goto x86_l_15be;
	case 5572ULL: goto x86_l_15c4;
	case 5580ULL: goto x86_l_15cc;
	case 5587ULL: goto x86_l_15d3;
	case 5589ULL: goto x86_l_15d5;
	case 5594ULL: goto x86_l_15da;
	case 5599ULL: goto x86_l_15df;
	case 5604ULL: goto x86_l_15e4;
	case 5609ULL: goto x86_l_15e9;
	case 5613ULL: goto x86_l_15ed;
	case 5619ULL: goto x86_l_15f3;
	case 5623ULL: goto x86_l_15f7;
	case 5629ULL: goto x86_l_15fd;
	case 5633ULL: goto x86_l_1601;
	case 5639ULL: goto x86_l_1607;
	case 5643ULL: goto x86_l_160b;
	case 5649ULL: goto x86_l_1611;
	case 5654ULL: goto x86_l_1616;
	case 5659ULL: goto x86_l_161b;
	case 5664ULL: goto x86_l_1620;
	case 5669ULL: goto x86_l_1625;
	case 5671ULL: goto x86_l_1627;
	case 5674ULL: goto x86_l_162a;
	case 5680ULL: goto x86_l_1630;
	case 5682ULL: goto x86_l_1632;
	case 5687ULL: goto x86_l_1637;
	case 5694ULL: goto x86_l_163e;
	case 5704ULL: goto x86_l_1648;
	case 5709ULL: goto x86_l_164d;
	case 5716ULL: goto x86_l_1654;
	case 5721ULL: goto x86_l_1659;
	case 5726ULL: goto x86_l_165e;
	case 5728ULL: goto x86_l_1660;
	case 5731ULL: goto x86_l_1663;
	case 5737ULL: goto x86_l_1669;
	case 5739ULL: goto x86_l_166b;
	case 5745ULL: goto x86_l_1671;
	case 5750ULL: goto x86_l_1676;
	case 5754ULL: goto x86_l_167a;
	case 5757ULL: goto x86_l_167d;
	case 5763ULL: goto x86_l_1683;
	case 5768ULL: goto x86_l_1688;
	case 5773ULL: goto x86_l_168d;
	case 5778ULL: goto x86_l_1692;
	case 5783ULL: goto x86_l_1697;
	case 5785ULL: goto x86_l_1699;
	case 5788ULL: goto x86_l_169c;
	case 5794ULL: goto x86_l_16a2;
	case 5796ULL: goto x86_l_16a4;
	case 5801ULL: goto x86_l_16a9;
	case 5808ULL: goto x86_l_16b0;
	case 5818ULL: goto x86_l_16ba;
	case 5823ULL: goto x86_l_16bf;
	case 5830ULL: goto x86_l_16c6;
	case 5835ULL: goto x86_l_16cb;
	case 5840ULL: goto x86_l_16d0;
	case 5842ULL: goto x86_l_16d2;
	case 5845ULL: goto x86_l_16d5;
	case 5851ULL: goto x86_l_16db;
	case 5853ULL: goto x86_l_16dd;
	case 5858ULL: goto x86_l_16e2;
	case 5862ULL: goto x86_l_16e6;
	case 5868ULL: goto x86_l_16ec;
	case 5872ULL: goto x86_l_16f0;
	case 5878ULL: goto x86_l_16f6;
	case 5882ULL: goto x86_l_16fa;
	case 5888ULL: goto x86_l_1700;
	case 5893ULL: goto x86_l_1705;
	case 5898ULL: goto x86_l_170a;
	case 5903ULL: goto x86_l_170f;
	case 5908ULL: goto x86_l_1714;
	case 5910ULL: goto x86_l_1716;
	case 5913ULL: goto x86_l_1719;
	case 5919ULL: goto x86_l_171f;
	case 5921ULL: goto x86_l_1721;
	case 5926ULL: goto x86_l_1726;
	case 5933ULL: goto x86_l_172d;
	case 5943ULL: goto x86_l_1737;
	case 5948ULL: goto x86_l_173c;
	case 5955ULL: goto x86_l_1743;
	case 5960ULL: goto x86_l_1748;
	case 5965ULL: goto x86_l_174d;
	case 5967ULL: goto x86_l_174f;
	case 5970ULL: goto x86_l_1752;
	case 5976ULL: goto x86_l_1758;
	case 5984ULL: goto x86_l_1760;
	case 5991ULL: goto x86_l_1767;
	case 5993ULL: goto x86_l_1769;
	case 5998ULL: goto x86_l_176e;
	case 6003ULL: goto x86_l_1773;
	case 6008ULL: goto x86_l_1778;
	case 6013ULL: goto x86_l_177d;
	case 6017ULL: goto x86_l_1781;
	case 6023ULL: goto x86_l_1787;
	case 6027ULL: goto x86_l_178b;
	case 6029ULL: goto x86_l_178d;
	case 6034ULL: goto x86_l_1792;
	case 6038ULL: goto x86_l_1796;
	case 6044ULL: goto x86_l_179c;
	case 6048ULL: goto x86_l_17a0;
	case 6054ULL: goto x86_l_17a6;
	case 6059ULL: goto x86_l_17ab;
	case 6064ULL: goto x86_l_17b0;
	case 6069ULL: goto x86_l_17b5;
	case 6074ULL: goto x86_l_17ba;
	case 6076ULL: goto x86_l_17bc;
	case 6079ULL: goto x86_l_17bf;
	case 6085ULL: goto x86_l_17c5;
	case 6087ULL: goto x86_l_17c7;
	case 6092ULL: goto x86_l_17cc;
	case 6099ULL: goto x86_l_17d3;
	case 6109ULL: goto x86_l_17dd;
	case 6114ULL: goto x86_l_17e2;
	case 6121ULL: goto x86_l_17e9;
	case 6126ULL: goto x86_l_17ee;
	case 6131ULL: goto x86_l_17f3;
	case 6133ULL: goto x86_l_17f5;
	case 6136ULL: goto x86_l_17f8;
	case 6142ULL: goto x86_l_17fe;
	case 6150ULL: goto x86_l_1806;
	case 6157ULL: goto x86_l_180d;
	case 6159ULL: goto x86_l_180f;
	case 6164ULL: goto x86_l_1814;
	case 6169ULL: goto x86_l_1819;
	case 6174ULL: goto x86_l_181e;
	case 6179ULL: goto x86_l_1823;
	case 6184ULL: goto x86_l_1828;
	case 6189ULL: goto x86_l_182d;
	case 6194ULL: goto x86_l_1832;
	case 6199ULL: goto x86_l_1837;
	case 6201ULL: goto x86_l_1839;
	case 6204ULL: goto x86_l_183c;
	case 6210ULL: goto x86_l_1842;
	case 6212ULL: goto x86_l_1844;
	case 6217ULL: goto x86_l_1849;
	case 6224ULL: goto x86_l_1850;
	case 6234ULL: goto x86_l_185a;
	case 6239ULL: goto x86_l_185f;
	case 6246ULL: goto x86_l_1866;
	case 6251ULL: goto x86_l_186b;
	case 6256ULL: goto x86_l_1870;
	case 6258ULL: goto x86_l_1872;
	case 6261ULL: goto x86_l_1875;
	case 6267ULL: goto x86_l_187b;
	case 6269ULL: goto x86_l_187d;
	case 6274ULL: goto x86_l_1882;
	case 6279ULL: goto x86_l_1887;
	case 6287ULL: goto x86_l_188f;
	case 6294ULL: goto x86_l_1896;
	case 6296ULL: goto x86_l_1898;
	case 6301ULL: goto x86_l_189d;
	case 6306ULL: goto x86_l_18a2;
	case 6311ULL: goto x86_l_18a7;
	case 6313ULL: goto x86_l_18a9;
	case 6315ULL: goto x86_l_18ab;
	case 6320ULL: goto x86_l_18b0;
	case 6324ULL: goto x86_l_18b4;
	case 6330ULL: goto x86_l_18ba;
	case 6335ULL: goto x86_l_18bf;
	case 6337ULL: goto x86_l_18c1;
	case 6341ULL: goto x86_l_18c5;
	case 6346ULL: goto x86_l_18ca;
	case 6351ULL: goto x86_l_18cf;
	case 6356ULL: goto x86_l_18d4;
	case 6361ULL: goto x86_l_18d9;
	case 6363ULL: goto x86_l_18db;
	case 6367ULL: goto x86_l_18df;
	case 6370ULL: goto x86_l_18e2;
	case 6373ULL: goto x86_l_18e5;
	case 6376ULL: goto x86_l_18e8;
	case 6381ULL: goto x86_l_18ed;
	case 6385ULL: goto x86_l_18f1;
	case 6391ULL: goto x86_l_18f7;
	case 6396ULL: goto x86_l_18fc;
	case 6401ULL: goto x86_l_1901;
	case 6406ULL: goto x86_l_1906;
	case 6411ULL: goto x86_l_190b;
	case 6413ULL: goto x86_l_190d;
	case 6416ULL: goto x86_l_1910;
	case 6422ULL: goto x86_l_1916;
	case 6424ULL: goto x86_l_1918;
	case 6429ULL: goto x86_l_191d;
	case 6436ULL: goto x86_l_1924;
	case 6446ULL: goto x86_l_192e;
	case 6451ULL: goto x86_l_1933;
	case 6458ULL: goto x86_l_193a;
	case 6463ULL: goto x86_l_193f;
	case 6468ULL: goto x86_l_1944;
	case 6470ULL: goto x86_l_1946;
	case 6473ULL: goto x86_l_1949;
	case 6479ULL: goto x86_l_194f;
	case 6487ULL: goto x86_l_1957;
	case 6494ULL: goto x86_l_195e;
	case 6496ULL: goto x86_l_1960;
	case 6501ULL: goto x86_l_1965;
	case 6506ULL: goto x86_l_196a;
	case 6511ULL: goto x86_l_196f;
	case 6516ULL: goto x86_l_1974;
	case 6519ULL: goto x86_l_1977;
	case 6524ULL: goto x86_l_197c;
	case 6529ULL: goto x86_l_1981;
	case 6534ULL: goto x86_l_1986;
	case 6539ULL: goto x86_l_198b;
	case 6544ULL: goto x86_l_1990;
	case 6546ULL: goto x86_l_1992;
	case 6549ULL: goto x86_l_1995;
	case 6555ULL: goto x86_l_199b;
	case 6557ULL: goto x86_l_199d;
	case 6562ULL: goto x86_l_19a2;
	case 6569ULL: goto x86_l_19a9;
	case 6579ULL: goto x86_l_19b3;
	case 6584ULL: goto x86_l_19b8;
	case 6591ULL: goto x86_l_19bf;
	case 6596ULL: goto x86_l_19c4;
	case 6601ULL: goto x86_l_19c9;
	case 6603ULL: goto x86_l_19cb;
	case 6606ULL: goto x86_l_19ce;
	case 6612ULL: goto x86_l_19d4;
	case 6620ULL: goto x86_l_19dc;
	case 6627ULL: goto x86_l_19e3;
	case 6629ULL: goto x86_l_19e5;
	case 6634ULL: goto x86_l_19ea;
	case 6639ULL: goto x86_l_19ef;
	case 6644ULL: goto x86_l_19f4;
	case 6649ULL: goto x86_l_19f9;
	case 6654ULL: goto x86_l_19fe;
	case 6659ULL: goto x86_l_1a03;
	case 6664ULL: goto x86_l_1a08;
	case 6669ULL: goto x86_l_1a0d;
	case 6671ULL: goto x86_l_1a0f;
	case 6674ULL: goto x86_l_1a12;
	case 6680ULL: goto x86_l_1a18;
	case 6682ULL: goto x86_l_1a1a;
	case 6687ULL: goto x86_l_1a1f;
	case 6694ULL: goto x86_l_1a26;
	case 6704ULL: goto x86_l_1a30;
	case 6709ULL: goto x86_l_1a35;
	case 6716ULL: goto x86_l_1a3c;
	case 6721ULL: goto x86_l_1a41;
	case 6726ULL: goto x86_l_1a46;
	case 6728ULL: goto x86_l_1a48;
	case 6731ULL: goto x86_l_1a4b;
	case 6737ULL: goto x86_l_1a51;
	case 6739ULL: goto x86_l_1a53;
	case 6745ULL: goto x86_l_1a59;
	case 6750ULL: goto x86_l_1a5e;
	case 6755ULL: goto x86_l_1a63;
	case 6760ULL: goto x86_l_1a68;
	case 6765ULL: goto x86_l_1a6d;
	case 6770ULL: goto x86_l_1a72;
	case 6772ULL: goto x86_l_1a74;
	case 6775ULL: goto x86_l_1a77;
	case 6781ULL: goto x86_l_1a7d;
	case 6783ULL: goto x86_l_1a7f;
	case 6788ULL: goto x86_l_1a84;
	case 6795ULL: goto x86_l_1a8b;
	case 6805ULL: goto x86_l_1a95;
	case 6810ULL: goto x86_l_1a9a;
	case 6817ULL: goto x86_l_1aa1;
	case 6822ULL: goto x86_l_1aa6;
	case 6827ULL: goto x86_l_1aab;
	case 6829ULL: goto x86_l_1aad;
	case 6832ULL: goto x86_l_1ab0;
	case 6838ULL: goto x86_l_1ab6;
	case 6846ULL: goto x86_l_1abe;
	case 6853ULL: goto x86_l_1ac5;
	case 6855ULL: goto x86_l_1ac7;
	case 6860ULL: goto x86_l_1acc;
	case 6865ULL: goto x86_l_1ad1;
	case 6870ULL: goto x86_l_1ad6;
	case 6875ULL: goto x86_l_1adb;
	case 6880ULL: goto x86_l_1ae0;
	case 6885ULL: goto x86_l_1ae5;
	case 6890ULL: goto x86_l_1aea;
	case 6895ULL: goto x86_l_1aef;
	case 6897ULL: goto x86_l_1af1;
	case 6900ULL: goto x86_l_1af4;
	case 6906ULL: goto x86_l_1afa;
	case 6908ULL: goto x86_l_1afc;
	case 6913ULL: goto x86_l_1b01;
	case 6920ULL: goto x86_l_1b08;
	case 6930ULL: goto x86_l_1b12;
	case 6935ULL: goto x86_l_1b17;
	case 6942ULL: goto x86_l_1b1e;
	case 6947ULL: goto x86_l_1b23;
	case 6952ULL: goto x86_l_1b28;
	case 6954ULL: goto x86_l_1b2a;
	case 6957ULL: goto x86_l_1b2d;
	case 6963ULL: goto x86_l_1b33;
	case 6965ULL: goto x86_l_1b35;
	case 6970ULL: goto x86_l_1b3a;
	case 6975ULL: goto x86_l_1b3f;
	case 6980ULL: goto x86_l_1b44;
	case 6985ULL: goto x86_l_1b49;
	case 6990ULL: goto x86_l_1b4e;
	case 6992ULL: goto x86_l_1b50;
	case 6995ULL: goto x86_l_1b53;
	case 7001ULL: goto x86_l_1b59;
	case 7003ULL: goto x86_l_1b5b;
	case 7008ULL: goto x86_l_1b60;
	case 7015ULL: goto x86_l_1b67;
	case 7025ULL: goto x86_l_1b71;
	case 7030ULL: goto x86_l_1b76;
	case 7037ULL: goto x86_l_1b7d;
	case 7042ULL: goto x86_l_1b82;
	case 7047ULL: goto x86_l_1b87;
	case 7049ULL: goto x86_l_1b89;
	case 7052ULL: goto x86_l_1b8c;
	case 7058ULL: goto x86_l_1b92;
	case 7060ULL: goto x86_l_1b94;
	case 7066ULL: goto x86_l_1b9a;
	case 7071ULL: goto x86_l_1b9f;
	case 7076ULL: goto x86_l_1ba4;
	case 7081ULL: goto x86_l_1ba9;
	case 7086ULL: goto x86_l_1bae;
	case 7091ULL: goto x86_l_1bb3;
	case 7093ULL: goto x86_l_1bb5;
	case 7096ULL: goto x86_l_1bb8;
	case 7102ULL: goto x86_l_1bbe;
	case 7104ULL: goto x86_l_1bc0;
	case 7109ULL: goto x86_l_1bc5;
	case 7116ULL: goto x86_l_1bcc;
	case 7126ULL: goto x86_l_1bd6;
	case 7131ULL: goto x86_l_1bdb;
	case 7138ULL: goto x86_l_1be2;
	case 7143ULL: goto x86_l_1be7;
	case 7148ULL: goto x86_l_1bec;
	case 7150ULL: goto x86_l_1bee;
	case 7153ULL: goto x86_l_1bf1;
	case 7159ULL: goto x86_l_1bf7;
	case 7161ULL: goto x86_l_1bf9;
	case 7166ULL: goto x86_l_1bfe;
	case 7171ULL: goto x86_l_1c03;
	case 7179ULL: goto x86_l_1c0b;
	case 7186ULL: goto x86_l_1c12;
	case 7188ULL: goto x86_l_1c14;
	case 7193ULL: goto x86_l_1c19;
	case 7198ULL: goto x86_l_1c1e;
	case 7203ULL: goto x86_l_1c23;
	case 7205ULL: goto x86_l_1c25;
	case 7207ULL: goto x86_l_1c27;
	case 7212ULL: goto x86_l_1c2c;
	case 7217ULL: goto x86_l_1c31;
	case 7225ULL: goto x86_l_1c39;
	case 7232ULL: goto x86_l_1c40;
	case 7234ULL: goto x86_l_1c42;
	case 7239ULL: goto x86_l_1c47;
	case 7244ULL: goto x86_l_1c4c;
	case 7249ULL: goto x86_l_1c51;
	case 7251ULL: goto x86_l_1c53;
	case 7253ULL: goto x86_l_1c55;
	case 7259ULL: goto x86_l_1c5b;
	case 7264ULL: goto x86_l_1c60;
	case 7272ULL: goto x86_l_1c68;
	case 7279ULL: goto x86_l_1c6f;
	case 7281ULL: goto x86_l_1c71;
	case 7286ULL: goto x86_l_1c76;
	case 7291ULL: goto x86_l_1c7b;
	case 7296ULL: goto x86_l_1c80;
	case 7298ULL: goto x86_l_1c82;
	case 7300ULL: goto x86_l_1c84;
	case 7306ULL: goto x86_l_1c8a;
	case 7311ULL: goto x86_l_1c8f;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1559:
	/* 0x1559: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_155c:
	/* 0x155c: jb     1683 <generic_tracepoint_event+0x1683> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1683;
	}
x86_l_1562:
	/* 0x1562: cmp    r13d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 2ULL);
x86_l_1566:
	/* 0x1566: jne    1d3e <generic_tracepoint_event+0x1d3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7486ULL;
	}
x86_l_156c:
	/* 0x156c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1571:
	/* 0x1571: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1576:
	/* 0x1576: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_157b:
	/* 0x157b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1580:
	/* 0x1580: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1582:
	/* 0x1582: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1585:
	/* 0x1585: je     1ce2 <generic_tracepoint_event+0x1ce2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7394ULL;
	}
x86_l_158b:
	/* 0x158b: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_158d:
	/* 0x158d: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1592:
	/* 0x1592: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_1599:
	/* 0x1599: movabs rax,0x400000081 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869313ULL);
x86_l_15a3:
	/* 0x15a3: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_15a8:
	/* 0x15a8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_15af:
	/* 0x15af: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15b4:
	/* 0x15b4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15b9:
	/* 0x15b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15bb:
	/* 0x15bb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15be:
	/* 0x15be: jne    1b33 <generic_tracepoint_event+0x1b33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1b33;
	}
x86_l_15c4:
	/* 0x15c4: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_15cc:
	/* 0x15cc: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_15d3:
	/* 0x15d3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15d5:
	/* 0x15d5: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15da:
	/* 0x15da: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15df:
	/* 0x15df: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_15e4:
	/* 0x15e4: jmp    1cde <generic_tracepoint_event+0x1cde> */
	return 7390ULL;
x86_l_15e9:
	/* 0x15e9: cmp    r13d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 17ULL);
x86_l_15ed:
	/* 0x15ed: jle    1792 <generic_tracepoint_event+0x1792> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1792;
	}
x86_l_15f3:
	/* 0x15f3: cmp    r13d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 18ULL);
x86_l_15f7:
	/* 0x15f7: je     1974 <generic_tracepoint_event+0x1974> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1974;
	}
x86_l_15fd:
	/* 0x15fd: cmp    r13d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 28ULL);
x86_l_1601:
	/* 0x1601: je     1683 <generic_tracepoint_event+0x1683> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1683;
	}
x86_l_1607:
	/* 0x1607: cmp    r13d,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 29ULL);
x86_l_160b:
	/* 0x160b: jne    1d3e <generic_tracepoint_event+0x1d3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7486ULL;
	}
x86_l_1611:
	/* 0x1611: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1616:
	/* 0x1616: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_161b:
	/* 0x161b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1620:
	/* 0x1620: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1625:
	/* 0x1625: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1627:
	/* 0x1627: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_162a:
	/* 0x162a: je     1c55 <generic_tracepoint_event+0x1c55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c55;
	}
x86_l_1630:
	/* 0x1630: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1632:
	/* 0x1632: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1637:
	/* 0x1637: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_163e:
	/* 0x163e: movabs rax,0x40000006c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869292ULL);
x86_l_1648:
	/* 0x1648: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_164d:
	/* 0x164d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1654:
	/* 0x1654: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1659:
	/* 0x1659: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_165e:
	/* 0x165e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1660:
	/* 0x1660: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1663:
	/* 0x1663: je     1c31 <generic_tracepoint_event+0x1c31> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c31;
	}
x86_l_1669:
	/* 0x1669: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_166b:
	/* 0x166b: movsx  r12,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_1671:
	/* 0x1671: jmp    1d3e <generic_tracepoint_event+0x1d3e> */
	return 7486ULL;
x86_l_1676:
	/* 0x1676: lea    eax,[r13-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_167a:
	/* 0x167a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_167d:
	/* 0x167d: jae    18ed <generic_tracepoint_event+0x18ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_18ed;
	}
x86_l_1683:
	/* 0x1683: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1688:
	/* 0x1688: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_168d:
	/* 0x168d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1692:
	/* 0x1692: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1697:
	/* 0x1697: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1699:
	/* 0x1699: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_169c:
	/* 0x169c: je     18ab <generic_tracepoint_event+0x18ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18ab;
	}
x86_l_16a2:
	/* 0x16a2: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_16a4:
	/* 0x16a4: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_16a9:
	/* 0x16a9: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_16b0:
	/* 0x16b0: movabs rax,0x400000045 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869253ULL);
x86_l_16ba:
	/* 0x16ba: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_16bf:
	/* 0x16bf: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_16c6:
	/* 0x16c6: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_16cb:
	/* 0x16cb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16d0:
	/* 0x16d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16d2:
	/* 0x16d2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16d5:
	/* 0x16d5: je     1887 <generic_tracepoint_event+0x1887> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1887;
	}
x86_l_16db:
	/* 0x16db: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_16dd:
	/* 0x16dd: jmp    18ab <generic_tracepoint_event+0x18ab> */
	goto x86_l_18ab;
x86_l_16e2:
	/* 0x16e2: cmp    r13d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 38ULL);
x86_l_16e6:
	/* 0x16e6: je     1b9f <generic_tracepoint_event+0x1b9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b9f;
	}
x86_l_16ec:
	/* 0x16ec: cmp    r13d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 40ULL);
x86_l_16f0:
	/* 0x16f0: je     1a5e <generic_tracepoint_event+0x1a5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a5e;
	}
x86_l_16f6:
	/* 0x16f6: cmp    r13d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 41ULL);
x86_l_16fa:
	/* 0x16fa: jne    1d3e <generic_tracepoint_event+0x1d3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7486ULL;
	}
x86_l_1700:
	/* 0x1700: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1705:
	/* 0x1705: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_170a:
	/* 0x170a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_170f:
	/* 0x170f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1714:
	/* 0x1714: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1716:
	/* 0x1716: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1719:
	/* 0x1719: je     1ce2 <generic_tracepoint_event+0x1ce2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7394ULL;
	}
x86_l_171f:
	/* 0x171f: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1721:
	/* 0x1721: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1726:
	/* 0x1726: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_172d:
	/* 0x172d: movabs rax,0x4000000a8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869352ULL);
x86_l_1737:
	/* 0x1737: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_173c:
	/* 0x173c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1743:
	/* 0x1743: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1748:
	/* 0x1748: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_174d:
	/* 0x174d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_174f:
	/* 0x174f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1752:
	/* 0x1752: jne    1b33 <generic_tracepoint_event+0x1b33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1b33;
	}
x86_l_1758:
	/* 0x1758: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_1760:
	/* 0x1760: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1767:
	/* 0x1767: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1769:
	/* 0x1769: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_176e:
	/* 0x176e: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1773:
	/* 0x1773: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1778:
	/* 0x1778: jmp    1cde <generic_tracepoint_event+0x1cde> */
	return 7390ULL;
x86_l_177d:
	/* 0x177d: cmp    r13d,0xfffffff3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4294967283ULL);
x86_l_1781:
	/* 0x1781: je     1823 <generic_tracepoint_event+0x1823> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1823;
	}
x86_l_1787:
	/* 0x1787: cmp    r13d,0xfffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4294967284ULL);
x86_l_178b:
	/* 0x178b: je     17a6 <generic_tracepoint_event+0x17a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17a6;
	}
x86_l_178d:
	/* 0x178d: jmp    1d3e <generic_tracepoint_event+0x1d3e> */
	return 7486ULL;
x86_l_1792:
	/* 0x1792: cmp    r13d,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 12ULL);
x86_l_1796:
	/* 0x1796: je     1823 <generic_tracepoint_event+0x1823> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1823;
	}
x86_l_179c:
	/* 0x179c: cmp    r13d,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 13ULL);
x86_l_17a0:
	/* 0x17a0: jne    1d3e <generic_tracepoint_event+0x1d3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7486ULL;
	}
x86_l_17a6:
	/* 0x17a6: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17ab:
	/* 0x17ab: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_17b0:
	/* 0x17b0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17b5:
	/* 0x17b5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_17ba:
	/* 0x17ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17bc:
	/* 0x17bc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_17bf:
	/* 0x17bf: je     1d39 <generic_tracepoint_event+0x1d39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7481ULL;
	}
x86_l_17c5:
	/* 0x17c5: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_17c7:
	/* 0x17c7: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_17cc:
	/* 0x17cc: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_17d3:
	/* 0x17d3: movabs rax,0x40000005e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869278ULL);
x86_l_17dd:
	/* 0x17dd: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_17e2:
	/* 0x17e2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_17e9:
	/* 0x17e9: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_17ee:
	/* 0x17ee: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_17f3:
	/* 0x17f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17f5:
	/* 0x17f5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_17f8:
	/* 0x17f8: jne    1bf7 <generic_tracepoint_event+0x1bf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1bf7;
	}
x86_l_17fe:
	/* 0x17fe: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_1806:
	/* 0x1806: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_180d:
	/* 0x180d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_180f:
	/* 0x180f: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1814:
	/* 0x1814: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1819:
	/* 0x1819: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_181e:
	/* 0x181e: jmp    1d35 <generic_tracepoint_event+0x1d35> */
	return 7477ULL;
x86_l_1823:
	/* 0x1823: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1828:
	/* 0x1828: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_182d:
	/* 0x182d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1832:
	/* 0x1832: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1837:
	/* 0x1837: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1839:
	/* 0x1839: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_183c:
	/* 0x183c: je     1c27 <generic_tracepoint_event+0x1c27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c27;
	}
x86_l_1842:
	/* 0x1842: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1844:
	/* 0x1844: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1849:
	/* 0x1849: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_1850:
	/* 0x1850: movabs rax,0x400000056 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869270ULL);
x86_l_185a:
	/* 0x185a: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_185f:
	/* 0x185f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1866:
	/* 0x1866: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_186b:
	/* 0x186b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1870:
	/* 0x1870: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1872:
	/* 0x1872: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1875:
	/* 0x1875: je     1c03 <generic_tracepoint_event+0x1c03> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c03;
	}
x86_l_187b:
	/* 0x187b: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_187d:
	/* 0x187d: movsxd r12,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_1882:
	/* 0x1882: jmp    1d3e <generic_tracepoint_event+0x1d3e> */
	return 7486ULL;
x86_l_1887:
	/* 0x1887: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_188f:
	/* 0x188f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1896:
	/* 0x1896: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1898:
	/* 0x1898: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_189d:
	/* 0x189d: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18a2:
	/* 0x18a2: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_18a7:
	/* 0x18a7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18a9:
	/* 0x18a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18ab:
	/* 0x18ab: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18b0:
	/* 0x18b0: cmp    r13d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 28ULL);
x86_l_18b4:
	/* 0x18b4: jne    1d3e <generic_tracepoint_event+0x1d3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7486ULL;
	}
x86_l_18ba:
	/* 0x18ba: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_18bf:
	/* 0x18bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18c1:
	/* 0x18c1: lea    rdx,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18c5:
	/* 0x18c5: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_18ca:
	/* 0x18ca: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_18cf:
	/* 0x18cf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18d4:
	/* 0x18d4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18d9:
	/* 0x18d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18db:
	/* 0x18db: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_18df:
	/* 0x18df: and    eax,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_18e2:
	/* 0x18e2: shl    eax,0x1e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 30ULL);
x86_l_18e5:
	/* 0x18e5: or     r12,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_18e8:
	/* 0x18e8: jmp    1d3e <generic_tracepoint_event+0x1d3e> */
	return 7486ULL;
x86_l_18ed:
	/* 0x18ed: cmp    r13d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 7ULL);
x86_l_18f1:
	/* 0x18f1: jne    1d3e <generic_tracepoint_event+0x1d3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7486ULL;
	}
x86_l_18f7:
	/* 0x18f7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18fc:
	/* 0x18fc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1901:
	/* 0x1901: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1906:
	/* 0x1906: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_190b:
	/* 0x190b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_190d:
	/* 0x190d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1910:
	/* 0x1910: je     1ce2 <generic_tracepoint_event+0x1ce2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7394ULL;
	}
x86_l_1916:
	/* 0x1916: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1918:
	/* 0x1918: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_191d:
	/* 0x191d: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_1924:
	/* 0x1924: movabs rax,0x40000009a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869338ULL);
x86_l_192e:
	/* 0x192e: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1933:
	/* 0x1933: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_193a:
	/* 0x193a: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_193f:
	/* 0x193f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1944:
	/* 0x1944: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1946:
	/* 0x1946: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1949:
	/* 0x1949: jne    1b33 <generic_tracepoint_event+0x1b33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1b33;
	}
x86_l_194f:
	/* 0x194f: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_1957:
	/* 0x1957: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_195e:
	/* 0x195e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1960:
	/* 0x1960: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1965:
	/* 0x1965: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_196a:
	/* 0x196a: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_196f:
	/* 0x196f: jmp    1cde <generic_tracepoint_event+0x1cde> */
	return 7390ULL;
x86_l_1974:
	/* 0x1974: mov    r12,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_1977:
	/* 0x1977: jmp    1d3e <generic_tracepoint_event+0x1d3e> */
	return 7486ULL;
x86_l_197c:
	/* 0x197c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1981:
	/* 0x1981: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1986:
	/* 0x1986: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_198b:
	/* 0x198b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1990:
	/* 0x1990: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1992:
	/* 0x1992: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1995:
	/* 0x1995: je     1ce2 <generic_tracepoint_event+0x1ce2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7394ULL;
	}
x86_l_199b:
	/* 0x199b: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_199d:
	/* 0x199d: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_19a2:
	/* 0x19a2: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_19a9:
	/* 0x19a9: movabs rax,0x400000093 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869331ULL);
x86_l_19b3:
	/* 0x19b3: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_19b8:
	/* 0x19b8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_19bf:
	/* 0x19bf: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_19c4:
	/* 0x19c4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_19c9:
	/* 0x19c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19cb:
	/* 0x19cb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_19ce:
	/* 0x19ce: jne    1b33 <generic_tracepoint_event+0x1b33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1b33;
	}
x86_l_19d4:
	/* 0x19d4: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_19dc:
	/* 0x19dc: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_19e3:
	/* 0x19e3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19e5:
	/* 0x19e5: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_19ea:
	/* 0x19ea: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19ef:
	/* 0x19ef: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_19f4:
	/* 0x19f4: jmp    1cde <generic_tracepoint_event+0x1cde> */
	return 7390ULL;
x86_l_19f9:
	/* 0x19f9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19fe:
	/* 0x19fe: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1a03:
	/* 0x1a03: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a08:
	/* 0x1a08: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1a0d:
	/* 0x1a0d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a0f:
	/* 0x1a0f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a12:
	/* 0x1a12: je     1c84 <generic_tracepoint_event+0x1c84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c84;
	}
x86_l_1a18:
	/* 0x1a18: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1a1a:
	/* 0x1a1a: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a1f:
	/* 0x1a1f: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_1a26:
	/* 0x1a26: movabs rax,0x40000007a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869306ULL);
x86_l_1a30:
	/* 0x1a30: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1a35:
	/* 0x1a35: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1a3c:
	/* 0x1a3c: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a41:
	/* 0x1a41: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a46:
	/* 0x1a46: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a48:
	/* 0x1a48: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a4b:
	/* 0x1a4b: je     1c60 <generic_tracepoint_event+0x1c60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c60;
	}
x86_l_1a51:
	/* 0x1a51: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1a53:
	/* 0x1a53: movsx  r12,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_1a59:
	/* 0x1a59: jmp    1d3e <generic_tracepoint_event+0x1d3e> */
	return 7486ULL;
x86_l_1a5e:
	/* 0x1a5e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a63:
	/* 0x1a63: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a68:
	/* 0x1a68: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a6d:
	/* 0x1a6d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a72:
	/* 0x1a72: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a74:
	/* 0x1a74: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a77:
	/* 0x1a77: je     1ce2 <generic_tracepoint_event+0x1ce2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7394ULL;
	}
x86_l_1a7d:
	/* 0x1a7d: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1a7f:
	/* 0x1a7f: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a84:
	/* 0x1a84: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_1a8b:
	/* 0x1a8b: movabs rax,0x4000000a1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869345ULL);
x86_l_1a95:
	/* 0x1a95: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1a9a:
	/* 0x1a9a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1aa1:
	/* 0x1aa1: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1aa6:
	/* 0x1aa6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1aab:
	/* 0x1aab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aad:
	/* 0x1aad: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ab0:
	/* 0x1ab0: jne    1b33 <generic_tracepoint_event+0x1b33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1b33;
	}
x86_l_1ab6:
	/* 0x1ab6: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_1abe:
	/* 0x1abe: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1ac5:
	/* 0x1ac5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ac7:
	/* 0x1ac7: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1acc:
	/* 0x1acc: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ad1:
	/* 0x1ad1: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1ad6:
	/* 0x1ad6: jmp    1cde <generic_tracepoint_event+0x1cde> */
	return 7390ULL;
x86_l_1adb:
	/* 0x1adb: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ae0:
	/* 0x1ae0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1ae5:
	/* 0x1ae5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1aea:
	/* 0x1aea: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1aef:
	/* 0x1aef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1af1:
	/* 0x1af1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1af4:
	/* 0x1af4: je     1ce2 <generic_tracepoint_event+0x1ce2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7394ULL;
	}
x86_l_1afa:
	/* 0x1afa: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1afc:
	/* 0x1afc: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b01:
	/* 0x1b01: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_1b08:
	/* 0x1b08: movabs rax,0x40000004e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869262ULL);
x86_l_1b12:
	/* 0x1b12: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1b17:
	/* 0x1b17: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1b1e:
	/* 0x1b1e: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
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
	/* 0x1b2d: je     1cbe <generic_tracepoint_event+0x1cbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7358ULL;
	}
x86_l_1b33:
	/* 0x1b33: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1b35:
	/* 0x1b35: jmp    1ce2 <generic_tracepoint_event+0x1ce2> */
	return 7394ULL;
x86_l_1b3a:
	/* 0x1b3a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b3f:
	/* 0x1b3f: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1b44:
	/* 0x1b44: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b49:
	/* 0x1b49: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1b4e:
	/* 0x1b4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b50:
	/* 0x1b50: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b53:
	/* 0x1b53: je     1d0d <generic_tracepoint_event+0x1d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7437ULL;
	}
x86_l_1b59:
	/* 0x1b59: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1b5b:
	/* 0x1b5b: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b60:
	/* 0x1b60: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_1b67:
	/* 0x1b67: movabs rax,0x400000065 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869285ULL);
x86_l_1b71:
	/* 0x1b71: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1b76:
	/* 0x1b76: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1b7d:
	/* 0x1b7d: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b82:
	/* 0x1b82: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b87:
	/* 0x1b87: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b89:
	/* 0x1b89: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b8c:
	/* 0x1b8c: je     1ce9 <generic_tracepoint_event+0x1ce9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7401ULL;
	}
x86_l_1b92:
	/* 0x1b92: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1b94:
	/* 0x1b94: movzx  r12d,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_1b9a:
	/* 0x1b9a: jmp    1d3e <generic_tracepoint_event+0x1d3e> */
	return 7486ULL;
x86_l_1b9f:
	/* 0x1b9f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ba4:
	/* 0x1ba4: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1ba9:
	/* 0x1ba9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1bae:
	/* 0x1bae: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1bb3:
	/* 0x1bb3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bb5:
	/* 0x1bb5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1bb8:
	/* 0x1bb8: je     1d39 <generic_tracepoint_event+0x1d39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7481ULL;
	}
x86_l_1bbe:
	/* 0x1bbe: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1bc0:
	/* 0x1bc0: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1bc5:
	/* 0x1bc5: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_1bcc:
	/* 0x1bcc: movabs rax,0x400000088 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869320ULL);
x86_l_1bd6:
	/* 0x1bd6: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1bdb:
	/* 0x1bdb: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1be2:
	/* 0x1be2: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1be7:
	/* 0x1be7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1bec:
	/* 0x1bec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bee:
	/* 0x1bee: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1bf1:
	/* 0x1bf1: je     1d15 <generic_tracepoint_event+0x1d15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7445ULL;
	}
x86_l_1bf7:
	/* 0x1bf7: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1bf9:
	/* 0x1bf9: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bfe:
	/* 0x1bfe: jmp    1d3e <generic_tracepoint_event+0x1d3e> */
	return 7486ULL;
x86_l_1c03:
	/* 0x1c03: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_1c0b:
	/* 0x1c0b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1c12:
	/* 0x1c12: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c14:
	/* 0x1c14: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c19:
	/* 0x1c19: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c1e:
	/* 0x1c1e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1c23:
	/* 0x1c23: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c25:
	/* 0x1c25: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c27:
	/* 0x1c27: movsxd r12,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_1c2c:
	/* 0x1c2c: jmp    1d3e <generic_tracepoint_event+0x1d3e> */
	return 7486ULL;
x86_l_1c31:
	/* 0x1c31: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_1c39:
	/* 0x1c39: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1c40:
	/* 0x1c40: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c42:
	/* 0x1c42: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c47:
	/* 0x1c47: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c4c:
	/* 0x1c4c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1c51:
	/* 0x1c51: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c53:
	/* 0x1c53: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c55:
	/* 0x1c55: movsx  r12,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_1c5b:
	/* 0x1c5b: jmp    1d3e <generic_tracepoint_event+0x1d3e> */
	return 7486ULL;
x86_l_1c60:
	/* 0x1c60: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_1c68:
	/* 0x1c68: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1c6f:
	/* 0x1c6f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c71:
	/* 0x1c71: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c76:
	/* 0x1c76: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c7b:
	/* 0x1c7b: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1c80:
	/* 0x1c80: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c82:
	/* 0x1c82: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c84:
	/* 0x1c84: movsx  r12,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_1c8a:
	/* 0x1c8a: jmp    1d3e <generic_tracepoint_event+0x1d3e> */
	return 7486ULL;
x86_l_1c8f:
	/* 0x1c8f: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
	return 7319ULL;
}

static __noinline __u64 tetragon_bpf_generic_tracepoint_v53_generic_tracepoint_event_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7319ULL: goto x86_l_1c97;
	case 7326ULL: goto x86_l_1c9e;
	case 7328ULL: goto x86_l_1ca0;
	case 7333ULL: goto x86_l_1ca5;
	case 7338ULL: goto x86_l_1caa;
	case 7343ULL: goto x86_l_1caf;
	case 7345ULL: goto x86_l_1cb1;
	case 7347ULL: goto x86_l_1cb3;
	case 7353ULL: goto x86_l_1cb9;
	case 7358ULL: goto x86_l_1cbe;
	case 7366ULL: goto x86_l_1cc6;
	case 7373ULL: goto x86_l_1ccd;
	case 7375ULL: goto x86_l_1ccf;
	case 7380ULL: goto x86_l_1cd4;
	case 7385ULL: goto x86_l_1cd9;
	case 7390ULL: goto x86_l_1cde;
	case 7392ULL: goto x86_l_1ce0;
	case 7394ULL: goto x86_l_1ce2;
	case 7399ULL: goto x86_l_1ce7;
	case 7401ULL: goto x86_l_1ce9;
	case 7409ULL: goto x86_l_1cf1;
	case 7416ULL: goto x86_l_1cf8;
	case 7418ULL: goto x86_l_1cfa;
	case 7423ULL: goto x86_l_1cff;
	case 7428ULL: goto x86_l_1d04;
	case 7433ULL: goto x86_l_1d09;
	case 7435ULL: goto x86_l_1d0b;
	case 7437ULL: goto x86_l_1d0d;
	case 7443ULL: goto x86_l_1d13;
	case 7445ULL: goto x86_l_1d15;
	case 7453ULL: goto x86_l_1d1d;
	case 7460ULL: goto x86_l_1d24;
	case 7462ULL: goto x86_l_1d26;
	case 7467ULL: goto x86_l_1d2b;
	case 7472ULL: goto x86_l_1d30;
	case 7477ULL: goto x86_l_1d35;
	case 7479ULL: goto x86_l_1d37;
	case 7481ULL: goto x86_l_1d39;
	case 7486ULL: goto x86_l_1d3e;
	case 7493ULL: goto x86_l_1d45;
	case 7498ULL: goto x86_l_1d4a;
	case 7502ULL: goto x86_l_1d4e;
	case 7505ULL: goto x86_l_1d51;
	case 7508ULL: goto x86_l_1d54;
	case 7512ULL: goto x86_l_1d58;
	case 7514ULL: goto x86_l_1d5a;
	case 7518ULL: goto x86_l_1d5e;
	case 7524ULL: goto x86_l_1d64;
	case 7528ULL: goto x86_l_1d68;
	case 7534ULL: goto x86_l_1d6e;
	case 7538ULL: goto x86_l_1d72;
	case 7544ULL: goto x86_l_1d78;
	case 7548ULL: goto x86_l_1d7c;
	case 7554ULL: goto x86_l_1d82;
	case 7558ULL: goto x86_l_1d86;
	case 7564ULL: goto x86_l_1d8c;
	case 7569ULL: goto x86_l_1d91;
	case 7573ULL: goto x86_l_1d95;
	case 7579ULL: goto x86_l_1d9b;
	case 7583ULL: goto x86_l_1d9f;
	case 7589ULL: goto x86_l_1da5;
	case 7593ULL: goto x86_l_1da9;
	case 7599ULL: goto x86_l_1daf;
	case 7603ULL: goto x86_l_1db3;
	case 7609ULL: goto x86_l_1db9;
	case 7613ULL: goto x86_l_1dbd;
	case 7619ULL: goto x86_l_1dc3;
	case 7624ULL: goto x86_l_1dc8;
	case 7629ULL: goto x86_l_1dcd;
	case 7634ULL: goto x86_l_1dd2;
	case 7639ULL: goto x86_l_1dd7;
	case 7641ULL: goto x86_l_1dd9;
	case 7644ULL: goto x86_l_1ddc;
	case 7650ULL: goto x86_l_1de2;
	case 7652ULL: goto x86_l_1de4;
	case 7657ULL: goto x86_l_1de9;
	case 7664ULL: goto x86_l_1df0;
	case 7674ULL: goto x86_l_1dfa;
	case 7679ULL: goto x86_l_1dff;
	case 7686ULL: goto x86_l_1e06;
	case 7691ULL: goto x86_l_1e0b;
	case 7696ULL: goto x86_l_1e10;
	case 7698ULL: goto x86_l_1e12;
	case 7701ULL: goto x86_l_1e15;
	case 7707ULL: goto x86_l_1e1b;
	case 7709ULL: goto x86_l_1e1d;
	case 7715ULL: goto x86_l_1e23;
	case 7720ULL: goto x86_l_1e28;
	case 7724ULL: goto x86_l_1e2c;
	case 7730ULL: goto x86_l_1e32;
	case 7734ULL: goto x86_l_1e36;
	case 7737ULL: goto x86_l_1e39;
	case 7743ULL: goto x86_l_1e3f;
	case 7747ULL: goto x86_l_1e43;
	case 7753ULL: goto x86_l_1e49;
	case 7758ULL: goto x86_l_1e4e;
	case 7763ULL: goto x86_l_1e53;
	case 7768ULL: goto x86_l_1e58;
	case 7773ULL: goto x86_l_1e5d;
	case 7775ULL: goto x86_l_1e5f;
	case 7778ULL: goto x86_l_1e62;
	case 7784ULL: goto x86_l_1e68;
	case 7786ULL: goto x86_l_1e6a;
	case 7791ULL: goto x86_l_1e6f;
	case 7798ULL: goto x86_l_1e76;
	case 7808ULL: goto x86_l_1e80;
	case 7813ULL: goto x86_l_1e85;
	case 7820ULL: goto x86_l_1e8c;
	case 7825ULL: goto x86_l_1e91;
	case 7830ULL: goto x86_l_1e96;
	case 7832ULL: goto x86_l_1e98;
	case 7835ULL: goto x86_l_1e9b;
	case 7841ULL: goto x86_l_1ea1;
	case 7849ULL: goto x86_l_1ea9;
	case 7856ULL: goto x86_l_1eb0;
	case 7858ULL: goto x86_l_1eb2;
	case 7863ULL: goto x86_l_1eb7;
	case 7868ULL: goto x86_l_1ebc;
	case 7873ULL: goto x86_l_1ec1;
	case 7878ULL: goto x86_l_1ec6;
	case 7882ULL: goto x86_l_1eca;
	case 7888ULL: goto x86_l_1ed0;
	case 7892ULL: goto x86_l_1ed4;
	case 7898ULL: goto x86_l_1eda;
	case 7902ULL: goto x86_l_1ede;
	case 7908ULL: goto x86_l_1ee4;
	case 7912ULL: goto x86_l_1ee8;
	case 7918ULL: goto x86_l_1eee;
	case 7923ULL: goto x86_l_1ef3;
	case 7928ULL: goto x86_l_1ef8;
	case 7933ULL: goto x86_l_1efd;
	case 7938ULL: goto x86_l_1f02;
	case 7940ULL: goto x86_l_1f04;
	case 7943ULL: goto x86_l_1f07;
	case 7949ULL: goto x86_l_1f0d;
	case 7951ULL: goto x86_l_1f0f;
	case 7956ULL: goto x86_l_1f14;
	case 7963ULL: goto x86_l_1f1b;
	case 7973ULL: goto x86_l_1f25;
	case 7978ULL: goto x86_l_1f2a;
	case 7985ULL: goto x86_l_1f31;
	case 7990ULL: goto x86_l_1f36;
	case 7995ULL: goto x86_l_1f3b;
	case 7997ULL: goto x86_l_1f3d;
	case 8000ULL: goto x86_l_1f40;
	case 8006ULL: goto x86_l_1f46;
	case 8008ULL: goto x86_l_1f48;
	case 8014ULL: goto x86_l_1f4e;
	case 8019ULL: goto x86_l_1f53;
	case 8023ULL: goto x86_l_1f57;
	case 8026ULL: goto x86_l_1f5a;
	case 8032ULL: goto x86_l_1f60;
	case 8037ULL: goto x86_l_1f65;
	case 8042ULL: goto x86_l_1f6a;
	case 8047ULL: goto x86_l_1f6f;
	case 8052ULL: goto x86_l_1f74;
	case 8054ULL: goto x86_l_1f76;
	case 8057ULL: goto x86_l_1f79;
	case 8063ULL: goto x86_l_1f7f;
	case 8065ULL: goto x86_l_1f81;
	case 8070ULL: goto x86_l_1f86;
	case 8077ULL: goto x86_l_1f8d;
	case 8087ULL: goto x86_l_1f97;
	case 8092ULL: goto x86_l_1f9c;
	case 8099ULL: goto x86_l_1fa3;
	case 8104ULL: goto x86_l_1fa8;
	case 8109ULL: goto x86_l_1fad;
	case 8111ULL: goto x86_l_1faf;
	case 8114ULL: goto x86_l_1fb2;
	case 8120ULL: goto x86_l_1fb8;
	case 8122ULL: goto x86_l_1fba;
	case 8127ULL: goto x86_l_1fbf;
	case 8131ULL: goto x86_l_1fc3;
	case 8137ULL: goto x86_l_1fc9;
	case 8141ULL: goto x86_l_1fcd;
	case 8147ULL: goto x86_l_1fd3;
	case 8151ULL: goto x86_l_1fd7;
	case 8157ULL: goto x86_l_1fdd;
	case 8162ULL: goto x86_l_1fe2;
	case 8167ULL: goto x86_l_1fe7;
	case 8172ULL: goto x86_l_1fec;
	case 8177ULL: goto x86_l_1ff1;
	case 8179ULL: goto x86_l_1ff3;
	case 8182ULL: goto x86_l_1ff6;
	case 8188ULL: goto x86_l_1ffc;
	case 8190ULL: goto x86_l_1ffe;
	case 8195ULL: goto x86_l_2003;
	case 8202ULL: goto x86_l_200a;
	case 8212ULL: goto x86_l_2014;
	case 8217ULL: goto x86_l_2019;
	case 8224ULL: goto x86_l_2020;
	case 8229ULL: goto x86_l_2025;
	case 8234ULL: goto x86_l_202a;
	case 8236ULL: goto x86_l_202c;
	case 8239ULL: goto x86_l_202f;
	case 8245ULL: goto x86_l_2035;
	case 8253ULL: goto x86_l_203d;
	case 8260ULL: goto x86_l_2044;
	case 8262ULL: goto x86_l_2046;
	case 8267ULL: goto x86_l_204b;
	case 8272ULL: goto x86_l_2050;
	case 8277ULL: goto x86_l_2055;
	case 8282ULL: goto x86_l_205a;
	case 8286ULL: goto x86_l_205e;
	case 8292ULL: goto x86_l_2064;
	case 8296ULL: goto x86_l_2068;
	case 8298ULL: goto x86_l_206a;
	case 8303ULL: goto x86_l_206f;
	case 8307ULL: goto x86_l_2073;
	case 8313ULL: goto x86_l_2079;
	case 8317ULL: goto x86_l_207d;
	case 8323ULL: goto x86_l_2083;
	case 8328ULL: goto x86_l_2088;
	case 8333ULL: goto x86_l_208d;
	case 8338ULL: goto x86_l_2092;
	case 8343ULL: goto x86_l_2097;
	case 8345ULL: goto x86_l_2099;
	case 8348ULL: goto x86_l_209c;
	case 8354ULL: goto x86_l_20a2;
	case 8356ULL: goto x86_l_20a4;
	case 8361ULL: goto x86_l_20a9;
	case 8368ULL: goto x86_l_20b0;
	case 8378ULL: goto x86_l_20ba;
	case 8383ULL: goto x86_l_20bf;
	case 8390ULL: goto x86_l_20c6;
	case 8395ULL: goto x86_l_20cb;
	case 8400ULL: goto x86_l_20d0;
	case 8402ULL: goto x86_l_20d2;
	case 8405ULL: goto x86_l_20d5;
	case 8411ULL: goto x86_l_20db;
	case 8419ULL: goto x86_l_20e3;
	case 8426ULL: goto x86_l_20ea;
	case 8428ULL: goto x86_l_20ec;
	case 8433ULL: goto x86_l_20f1;
	case 8438ULL: goto x86_l_20f6;
	case 8443ULL: goto x86_l_20fb;
	case 8448ULL: goto x86_l_2100;
	case 8453ULL: goto x86_l_2105;
	case 8458ULL: goto x86_l_210a;
	case 8463ULL: goto x86_l_210f;
	case 8468ULL: goto x86_l_2114;
	case 8470ULL: goto x86_l_2116;
	case 8473ULL: goto x86_l_2119;
	case 8479ULL: goto x86_l_211f;
	case 8481ULL: goto x86_l_2121;
	case 8486ULL: goto x86_l_2126;
	case 8493ULL: goto x86_l_212d;
	case 8503ULL: goto x86_l_2137;
	case 8508ULL: goto x86_l_213c;
	case 8515ULL: goto x86_l_2143;
	case 8520ULL: goto x86_l_2148;
	case 8525ULL: goto x86_l_214d;
	case 8527ULL: goto x86_l_214f;
	case 8530ULL: goto x86_l_2152;
	case 8536ULL: goto x86_l_2158;
	case 8538ULL: goto x86_l_215a;
	case 8543ULL: goto x86_l_215f;
	case 8548ULL: goto x86_l_2164;
	case 8556ULL: goto x86_l_216c;
	case 8563ULL: goto x86_l_2173;
	case 8565ULL: goto x86_l_2175;
	case 8570ULL: goto x86_l_217a;
	case 8575ULL: goto x86_l_217f;
	case 8580ULL: goto x86_l_2184;
	case 8582ULL: goto x86_l_2186;
	case 8584ULL: goto x86_l_2188;
	case 8589ULL: goto x86_l_218d;
	case 8593ULL: goto x86_l_2191;
	case 8599ULL: goto x86_l_2197;
	case 8604ULL: goto x86_l_219c;
	case 8606ULL: goto x86_l_219e;
	case 8610ULL: goto x86_l_21a2;
	case 8615ULL: goto x86_l_21a7;
	case 8620ULL: goto x86_l_21ac;
	case 8625ULL: goto x86_l_21b1;
	case 8630ULL: goto x86_l_21b6;
	case 8632ULL: goto x86_l_21b8;
	case 8636ULL: goto x86_l_21bc;
	case 8639ULL: goto x86_l_21bf;
	case 8642ULL: goto x86_l_21c2;
	case 8645ULL: goto x86_l_21c5;
	case 8650ULL: goto x86_l_21ca;
	case 8654ULL: goto x86_l_21ce;
	case 8660ULL: goto x86_l_21d4;
	case 8665ULL: goto x86_l_21d9;
	case 8670ULL: goto x86_l_21de;
	case 8675ULL: goto x86_l_21e3;
	case 8680ULL: goto x86_l_21e8;
	case 8682ULL: goto x86_l_21ea;
	case 8685ULL: goto x86_l_21ed;
	case 8691ULL: goto x86_l_21f3;
	case 8693ULL: goto x86_l_21f5;
	case 8698ULL: goto x86_l_21fa;
	case 8705ULL: goto x86_l_2201;
	case 8715ULL: goto x86_l_220b;
	case 8720ULL: goto x86_l_2210;
	case 8727ULL: goto x86_l_2217;
	case 8732ULL: goto x86_l_221c;
	case 8737ULL: goto x86_l_2221;
	case 8739ULL: goto x86_l_2223;
	case 8742ULL: goto x86_l_2226;
	case 8748ULL: goto x86_l_222c;
	case 8756ULL: goto x86_l_2234;
	case 8763ULL: goto x86_l_223b;
	case 8765ULL: goto x86_l_223d;
	case 8770ULL: goto x86_l_2242;
	case 8775ULL: goto x86_l_2247;
	case 8780ULL: goto x86_l_224c;
	case 8785ULL: goto x86_l_2251;
	case 8788ULL: goto x86_l_2254;
	case 8793ULL: goto x86_l_2259;
	case 8798ULL: goto x86_l_225e;
	case 8803ULL: goto x86_l_2263;
	case 8808ULL: goto x86_l_2268;
	case 8813ULL: goto x86_l_226d;
	case 8815ULL: goto x86_l_226f;
	case 8818ULL: goto x86_l_2272;
	case 8824ULL: goto x86_l_2278;
	case 8826ULL: goto x86_l_227a;
	case 8831ULL: goto x86_l_227f;
	case 8838ULL: goto x86_l_2286;
	case 8848ULL: goto x86_l_2290;
	case 8853ULL: goto x86_l_2295;
	case 8860ULL: goto x86_l_229c;
	case 8865ULL: goto x86_l_22a1;
	case 8870ULL: goto x86_l_22a6;
	case 8872ULL: goto x86_l_22a8;
	case 8875ULL: goto x86_l_22ab;
	case 8881ULL: goto x86_l_22b1;
	case 8889ULL: goto x86_l_22b9;
	case 8896ULL: goto x86_l_22c0;
	case 8898ULL: goto x86_l_22c2;
	case 8903ULL: goto x86_l_22c7;
	case 8908ULL: goto x86_l_22cc;
	case 8913ULL: goto x86_l_22d1;
	case 8918ULL: goto x86_l_22d6;
	case 8923ULL: goto x86_l_22db;
	case 8928ULL: goto x86_l_22e0;
	case 8933ULL: goto x86_l_22e5;
	case 8938ULL: goto x86_l_22ea;
	case 8940ULL: goto x86_l_22ec;
	case 8943ULL: goto x86_l_22ef;
	case 8949ULL: goto x86_l_22f5;
	case 8951ULL: goto x86_l_22f7;
	case 8956ULL: goto x86_l_22fc;
	case 8963ULL: goto x86_l_2303;
	case 8973ULL: goto x86_l_230d;
	case 8978ULL: goto x86_l_2312;
	case 8985ULL: goto x86_l_2319;
	case 8990ULL: goto x86_l_231e;
	case 8995ULL: goto x86_l_2323;
	case 8997ULL: goto x86_l_2325;
	case 9000ULL: goto x86_l_2328;
	case 9006ULL: goto x86_l_232e;
	case 9008ULL: goto x86_l_2330;
	case 9014ULL: goto x86_l_2336;
	case 9019ULL: goto x86_l_233b;
	case 9024ULL: goto x86_l_2340;
	case 9029ULL: goto x86_l_2345;
	case 9034ULL: goto x86_l_234a;
	case 9039ULL: goto x86_l_234f;
	case 9041ULL: goto x86_l_2351;
	case 9044ULL: goto x86_l_2354;
	case 9050ULL: goto x86_l_235a;
	case 9052ULL: goto x86_l_235c;
	case 9057ULL: goto x86_l_2361;
	case 9064ULL: goto x86_l_2368;
	case 9074ULL: goto x86_l_2372;
	case 9079ULL: goto x86_l_2377;
	case 9086ULL: goto x86_l_237e;
	case 9091ULL: goto x86_l_2383;
	case 9096ULL: goto x86_l_2388;
	case 9098ULL: goto x86_l_238a;
	case 9101ULL: goto x86_l_238d;
	case 9107ULL: goto x86_l_2393;
	case 9115ULL: goto x86_l_239b;
	case 9122ULL: goto x86_l_23a2;
	case 9124ULL: goto x86_l_23a4;
	case 9129ULL: goto x86_l_23a9;
	case 9134ULL: goto x86_l_23ae;
	case 9139ULL: goto x86_l_23b3;
	case 9144ULL: goto x86_l_23b8;
	case 9149ULL: goto x86_l_23bd;
	case 9154ULL: goto x86_l_23c2;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1c97:
	/* 0x1c97: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1c9e:
	/* 0x1c9e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ca0:
	/* 0x1ca0: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ca5:
	/* 0x1ca5: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1caa:
	/* 0x1caa: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1caf:
	/* 0x1caf: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cb1:
	/* 0x1cb1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cb3:
	/* 0x1cb3: movzx  r12d,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_1cb9:
	/* 0x1cb9: jmp    1d3e <generic_tracepoint_event+0x1d3e> */
	goto x86_l_1d3e;
x86_l_1cbe:
	/* 0x1cbe: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_1cc6:
	/* 0x1cc6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1ccd:
	/* 0x1ccd: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ccf:
	/* 0x1ccf: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1cd4:
	/* 0x1cd4: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cd9:
	/* 0x1cd9: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1cde:
	/* 0x1cde: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ce0:
	/* 0x1ce0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ce2:
	/* 0x1ce2: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ce7:
	/* 0x1ce7: jmp    1d3e <generic_tracepoint_event+0x1d3e> */
	goto x86_l_1d3e;
x86_l_1ce9:
	/* 0x1ce9: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_1cf1:
	/* 0x1cf1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1cf8:
	/* 0x1cf8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cfa:
	/* 0x1cfa: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1cff:
	/* 0x1cff: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d04:
	/* 0x1d04: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1d09:
	/* 0x1d09: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d0b:
	/* 0x1d0b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d0d:
	/* 0x1d0d: movzx  r12d,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_1d13:
	/* 0x1d13: jmp    1d3e <generic_tracepoint_event+0x1d3e> */
	goto x86_l_1d3e;
x86_l_1d15:
	/* 0x1d15: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_1d1d:
	/* 0x1d1d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1d24:
	/* 0x1d24: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d26:
	/* 0x1d26: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d2b:
	/* 0x1d2b: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d30:
	/* 0x1d30: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1d35:
	/* 0x1d35: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d37:
	/* 0x1d37: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d39:
	/* 0x1d39: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d3e:
	/* 0x1d3e: mov    QWORD PTR [r14+0x5e60],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24160ULL);
x86_l_1d45:
	/* 0x1d45: movzx  edx,WORD PTR [r15+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_1d4a:
	/* 0x1d4a: mov    r13d,DWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d4e:
	/* 0x1d4e: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1d51:
	/* 0x1d51: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d54:
	/* 0x1d54: cmp    r13d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 11ULL);
x86_l_1d58:
	/* 0x1d58: jg     1d91 <generic_tracepoint_event+0x1d91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1d91;
	}
x86_l_1d5a:
	/* 0x1d5a: cmp    r13d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 3ULL);
x86_l_1d5e:
	/* 0x1d5e: jle    1e28 <generic_tracepoint_event+0x1e28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1e28;
	}
x86_l_1d64:
	/* 0x1d64: cmp    r13d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 6ULL);
x86_l_1d68:
	/* 0x1d68: jg     1f53 <generic_tracepoint_event+0x1f53> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1f53;
	}
x86_l_1d6e:
	/* 0x1d6e: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_1d72:
	/* 0x1d72: je     23b8 <generic_tracepoint_event+0x23b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23b8;
	}
x86_l_1d78:
	/* 0x1d78: cmp    r13d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 5ULL);
x86_l_1d7c:
	/* 0x1d7c: je     2259 <generic_tracepoint_event+0x2259> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2259;
	}
x86_l_1d82:
	/* 0x1d82: cmp    r13d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 6ULL);
x86_l_1d86:
	/* 0x1d86: je     1e49 <generic_tracepoint_event+0x1e49> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e49;
	}
x86_l_1d8c:
	/* 0x1d8c: jmp    261b <generic_tracepoint_event+0x261b> */
	return 9755ULL;
x86_l_1d91:
	/* 0x1d91: cmp    r13d,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 29ULL);
x86_l_1d95:
	/* 0x1d95: jle    1ec6 <generic_tracepoint_event+0x1ec6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1ec6;
	}
x86_l_1d9b:
	/* 0x1d9b: cmp    r13d,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 37ULL);
x86_l_1d9f:
	/* 0x1d9f: jg     1fbf <generic_tracepoint_event+0x1fbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1fbf;
	}
x86_l_1da5:
	/* 0x1da5: cmp    r13d,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 30ULL);
x86_l_1da9:
	/* 0x1da9: je     2417 <generic_tracepoint_event+0x2417> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9239ULL;
	}
x86_l_1daf:
	/* 0x1daf: cmp    r13d,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 31ULL);
x86_l_1db3:
	/* 0x1db3: je     22d6 <generic_tracepoint_event+0x22d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22d6;
	}
x86_l_1db9:
	/* 0x1db9: cmp    r13d,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 32ULL);
x86_l_1dbd:
	/* 0x1dbd: jne    261b <generic_tracepoint_event+0x261b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9755ULL;
	}
x86_l_1dc3:
	/* 0x1dc3: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1dc8:
	/* 0x1dc8: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1dcd:
	/* 0x1dcd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1dd2:
	/* 0x1dd2: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1dd7:
	/* 0x1dd7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dd9:
	/* 0x1dd9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ddc:
	/* 0x1ddc: je     2590 <generic_tracepoint_event+0x2590> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9616ULL;
	}
x86_l_1de2:
	/* 0x1de2: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1de4:
	/* 0x1de4: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1de9:
	/* 0x1de9: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_1df0:
	/* 0x1df0: movabs rax,0x400000073 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869299ULL);
x86_l_1dfa:
	/* 0x1dfa: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1dff:
	/* 0x1dff: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1e06:
	/* 0x1e06: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e0b:
	/* 0x1e0b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1e10:
	/* 0x1e10: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e12:
	/* 0x1e12: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e15:
	/* 0x1e15: je     256c <generic_tracepoint_event+0x256c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9580ULL;
	}
x86_l_1e1b:
	/* 0x1e1b: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1e1d:
	/* 0x1e1d: movzx  r12d,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_1e23:
	/* 0x1e23: jmp    261b <generic_tracepoint_event+0x261b> */
	return 9755ULL;
x86_l_1e28:
	/* 0x1e28: cmp    r13d,0xfffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4294967284ULL);
x86_l_1e2c:
	/* 0x1e2c: jle    205a <generic_tracepoint_event+0x205a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_205a;
	}
x86_l_1e32:
	/* 0x1e32: lea    eax,[r13+0xb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 11ULL);
x86_l_1e36:
	/* 0x1e36: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1e39:
	/* 0x1e39: jb     1f60 <generic_tracepoint_event+0x1f60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1f60;
	}
x86_l_1e3f:
	/* 0x1e3f: cmp    r13d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 2ULL);
x86_l_1e43:
	/* 0x1e43: jne    261b <generic_tracepoint_event+0x261b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9755ULL;
	}
x86_l_1e49:
	/* 0x1e49: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e4e:
	/* 0x1e4e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1e53:
	/* 0x1e53: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e58:
	/* 0x1e58: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e5d:
	/* 0x1e5d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e5f:
	/* 0x1e5f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e62:
	/* 0x1e62: je     25bf <generic_tracepoint_event+0x25bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9663ULL;
	}
x86_l_1e68:
	/* 0x1e68: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1e6a:
	/* 0x1e6a: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e6f:
	/* 0x1e6f: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_1e76:
	/* 0x1e76: movabs rax,0x400000081 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869313ULL);
x86_l_1e80:
	/* 0x1e80: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1e85:
	/* 0x1e85: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1e8c:
	/* 0x1e8c: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e91:
	/* 0x1e91: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1e96:
	/* 0x1e96: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e98:
	/* 0x1e98: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e9b:
	/* 0x1e9b: jne    2410 <generic_tracepoint_event+0x2410> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9232ULL;
	}
x86_l_1ea1:
	/* 0x1ea1: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_1ea9:
	/* 0x1ea9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1eb0:
	/* 0x1eb0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1eb2:
	/* 0x1eb2: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1eb7:
	/* 0x1eb7: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ebc:
	/* 0x1ebc: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1ec1:
	/* 0x1ec1: jmp    25bb <generic_tracepoint_event+0x25bb> */
	return 9659ULL;
x86_l_1ec6:
	/* 0x1ec6: cmp    r13d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 17ULL);
x86_l_1eca:
	/* 0x1eca: jle    206f <generic_tracepoint_event+0x206f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_206f;
	}
x86_l_1ed0:
	/* 0x1ed0: cmp    r13d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 18ULL);
x86_l_1ed4:
	/* 0x1ed4: je     2251 <generic_tracepoint_event+0x2251> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2251;
	}
x86_l_1eda:
	/* 0x1eda: cmp    r13d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 28ULL);
x86_l_1ede:
	/* 0x1ede: je     1f60 <generic_tracepoint_event+0x1f60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f60;
	}
x86_l_1ee4:
	/* 0x1ee4: cmp    r13d,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 29ULL);
x86_l_1ee8:
	/* 0x1ee8: jne    261b <generic_tracepoint_event+0x261b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9755ULL;
	}
x86_l_1eee:
	/* 0x1eee: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ef3:
	/* 0x1ef3: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1ef8:
	/* 0x1ef8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1efd:
	/* 0x1efd: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1f02:
	/* 0x1f02: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f04:
	/* 0x1f04: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f07:
	/* 0x1f07: je     2532 <generic_tracepoint_event+0x2532> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9522ULL;
	}
x86_l_1f0d:
	/* 0x1f0d: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1f0f:
	/* 0x1f0f: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f14:
	/* 0x1f14: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_1f1b:
	/* 0x1f1b: movabs rax,0x40000006c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869292ULL);
x86_l_1f25:
	/* 0x1f25: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1f2a:
	/* 0x1f2a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1f31:
	/* 0x1f31: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f36:
	/* 0x1f36: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f3b:
	/* 0x1f3b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f3d:
	/* 0x1f3d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f40:
	/* 0x1f40: je     250e <generic_tracepoint_event+0x250e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9486ULL;
	}
x86_l_1f46:
	/* 0x1f46: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1f48:
	/* 0x1f48: movsx  r12,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_1f4e:
	/* 0x1f4e: jmp    261b <generic_tracepoint_event+0x261b> */
	return 9755ULL;
x86_l_1f53:
	/* 0x1f53: lea    eax,[r13-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_1f57:
	/* 0x1f57: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1f5a:
	/* 0x1f5a: jae    21ca <generic_tracepoint_event+0x21ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_21ca;
	}
x86_l_1f60:
	/* 0x1f60: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f65:
	/* 0x1f65: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1f6a:
	/* 0x1f6a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f6f:
	/* 0x1f6f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f74:
	/* 0x1f74: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f76:
	/* 0x1f76: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f79:
	/* 0x1f79: je     2188 <generic_tracepoint_event+0x2188> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2188;
	}
x86_l_1f7f:
	/* 0x1f7f: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1f81:
	/* 0x1f81: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f86:
	/* 0x1f86: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_1f8d:
	/* 0x1f8d: movabs rax,0x400000045 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869253ULL);
x86_l_1f97:
	/* 0x1f97: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1f9c:
	/* 0x1f9c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1fa3:
	/* 0x1fa3: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1fa8:
	/* 0x1fa8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1fad:
	/* 0x1fad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1faf:
	/* 0x1faf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1fb2:
	/* 0x1fb2: je     2164 <generic_tracepoint_event+0x2164> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2164;
	}
x86_l_1fb8:
	/* 0x1fb8: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1fba:
	/* 0x1fba: jmp    2188 <generic_tracepoint_event+0x2188> */
	goto x86_l_2188;
x86_l_1fbf:
	/* 0x1fbf: cmp    r13d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 38ULL);
x86_l_1fc3:
	/* 0x1fc3: je     247c <generic_tracepoint_event+0x247c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9340ULL;
	}
x86_l_1fc9:
	/* 0x1fc9: cmp    r13d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 40ULL);
x86_l_1fcd:
	/* 0x1fcd: je     233b <generic_tracepoint_event+0x233b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_233b;
	}
x86_l_1fd3:
	/* 0x1fd3: cmp    r13d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 41ULL);
x86_l_1fd7:
	/* 0x1fd7: jne    261b <generic_tracepoint_event+0x261b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9755ULL;
	}
x86_l_1fdd:
	/* 0x1fdd: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fe2:
	/* 0x1fe2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1fe7:
	/* 0x1fe7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1fec:
	/* 0x1fec: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ff1:
	/* 0x1ff1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ff3:
	/* 0x1ff3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ff6:
	/* 0x1ff6: je     25bf <generic_tracepoint_event+0x25bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9663ULL;
	}
x86_l_1ffc:
	/* 0x1ffc: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1ffe:
	/* 0x1ffe: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2003:
	/* 0x2003: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_200a:
	/* 0x200a: movabs rax,0x4000000a8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869352ULL);
x86_l_2014:
	/* 0x2014: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2019:
	/* 0x2019: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2020:
	/* 0x2020: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2025:
	/* 0x2025: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_202a:
	/* 0x202a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_202c:
	/* 0x202c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_202f:
	/* 0x202f: jne    2410 <generic_tracepoint_event+0x2410> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9232ULL;
	}
x86_l_2035:
	/* 0x2035: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_203d:
	/* 0x203d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2044:
	/* 0x2044: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2046:
	/* 0x2046: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_204b:
	/* 0x204b: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2050:
	/* 0x2050: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2055:
	/* 0x2055: jmp    25bb <generic_tracepoint_event+0x25bb> */
	return 9659ULL;
x86_l_205a:
	/* 0x205a: cmp    r13d,0xfffffff3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4294967283ULL);
x86_l_205e:
	/* 0x205e: je     2100 <generic_tracepoint_event+0x2100> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2100;
	}
x86_l_2064:
	/* 0x2064: cmp    r13d,0xfffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4294967284ULL);
x86_l_2068:
	/* 0x2068: je     2083 <generic_tracepoint_event+0x2083> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2083;
	}
x86_l_206a:
	/* 0x206a: jmp    261b <generic_tracepoint_event+0x261b> */
	return 9755ULL;
x86_l_206f:
	/* 0x206f: cmp    r13d,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 12ULL);
x86_l_2073:
	/* 0x2073: je     2100 <generic_tracepoint_event+0x2100> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2100;
	}
x86_l_2079:
	/* 0x2079: cmp    r13d,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 13ULL);
x86_l_207d:
	/* 0x207d: jne    261b <generic_tracepoint_event+0x261b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9755ULL;
	}
x86_l_2083:
	/* 0x2083: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2088:
	/* 0x2088: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_208d:
	/* 0x208d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2092:
	/* 0x2092: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2097:
	/* 0x2097: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2099:
	/* 0x2099: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_209c:
	/* 0x209c: je     2616 <generic_tracepoint_event+0x2616> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9750ULL;
	}
x86_l_20a2:
	/* 0x20a2: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_20a4:
	/* 0x20a4: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_20a9:
	/* 0x20a9: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_20b0:
	/* 0x20b0: movabs rax,0x40000005e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869278ULL);
x86_l_20ba:
	/* 0x20ba: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_20bf:
	/* 0x20bf: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_20c6:
	/* 0x20c6: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_20cb:
	/* 0x20cb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_20d0:
	/* 0x20d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20d2:
	/* 0x20d2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_20d5:
	/* 0x20d5: jne    24d4 <generic_tracepoint_event+0x24d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9428ULL;
	}
x86_l_20db:
	/* 0x20db: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_20e3:
	/* 0x20e3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_20ea:
	/* 0x20ea: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20ec:
	/* 0x20ec: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_20f1:
	/* 0x20f1: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20f6:
	/* 0x20f6: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_20fb:
	/* 0x20fb: jmp    2612 <generic_tracepoint_event+0x2612> */
	return 9746ULL;
x86_l_2100:
	/* 0x2100: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2105:
	/* 0x2105: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_210a:
	/* 0x210a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_210f:
	/* 0x210f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2114:
	/* 0x2114: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2116:
	/* 0x2116: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2119:
	/* 0x2119: je     2504 <generic_tracepoint_event+0x2504> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9476ULL;
	}
x86_l_211f:
	/* 0x211f: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_2121:
	/* 0x2121: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2126:
	/* 0x2126: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_212d:
	/* 0x212d: movabs rax,0x400000056 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869270ULL);
x86_l_2137:
	/* 0x2137: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_213c:
	/* 0x213c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2143:
	/* 0x2143: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2148:
	/* 0x2148: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_214d:
	/* 0x214d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_214f:
	/* 0x214f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2152:
	/* 0x2152: je     24e0 <generic_tracepoint_event+0x24e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9440ULL;
	}
x86_l_2158:
	/* 0x2158: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_215a:
	/* 0x215a: movsxd r12,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_215f:
	/* 0x215f: jmp    261b <generic_tracepoint_event+0x261b> */
	return 9755ULL;
x86_l_2164:
	/* 0x2164: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_216c:
	/* 0x216c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2173:
	/* 0x2173: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2175:
	/* 0x2175: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_217a:
	/* 0x217a: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_217f:
	/* 0x217f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2184:
	/* 0x2184: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2186:
	/* 0x2186: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2188:
	/* 0x2188: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_218d:
	/* 0x218d: cmp    r13d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 28ULL);
x86_l_2191:
	/* 0x2191: jne    261b <generic_tracepoint_event+0x261b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9755ULL;
	}
x86_l_2197:
	/* 0x2197: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_219c:
	/* 0x219c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_219e:
	/* 0x219e: lea    rdx,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21a2:
	/* 0x21a2: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_21a7:
	/* 0x21a7: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_21ac:
	/* 0x21ac: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_21b1:
	/* 0x21b1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_21b6:
	/* 0x21b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21b8:
	/* 0x21b8: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_21bc:
	/* 0x21bc: and    eax,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_21bf:
	/* 0x21bf: shl    eax,0x1e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 30ULL);
x86_l_21c2:
	/* 0x21c2: or     r12,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_21c5:
	/* 0x21c5: jmp    261b <generic_tracepoint_event+0x261b> */
	return 9755ULL;
x86_l_21ca:
	/* 0x21ca: cmp    r13d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 7ULL);
x86_l_21ce:
	/* 0x21ce: jne    261b <generic_tracepoint_event+0x261b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9755ULL;
	}
x86_l_21d4:
	/* 0x21d4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21d9:
	/* 0x21d9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_21de:
	/* 0x21de: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_21e3:
	/* 0x21e3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21e8:
	/* 0x21e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21ea:
	/* 0x21ea: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_21ed:
	/* 0x21ed: je     25bf <generic_tracepoint_event+0x25bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9663ULL;
	}
x86_l_21f3:
	/* 0x21f3: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_21f5:
	/* 0x21f5: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_21fa:
	/* 0x21fa: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_2201:
	/* 0x2201: movabs rax,0x40000009a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869338ULL);
x86_l_220b:
	/* 0x220b: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2210:
	/* 0x2210: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2217:
	/* 0x2217: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_221c:
	/* 0x221c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2221:
	/* 0x2221: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2223:
	/* 0x2223: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2226:
	/* 0x2226: jne    2410 <generic_tracepoint_event+0x2410> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9232ULL;
	}
x86_l_222c:
	/* 0x222c: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_2234:
	/* 0x2234: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_223b:
	/* 0x223b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_223d:
	/* 0x223d: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2242:
	/* 0x2242: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2247:
	/* 0x2247: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_224c:
	/* 0x224c: jmp    25bb <generic_tracepoint_event+0x25bb> */
	return 9659ULL;
x86_l_2251:
	/* 0x2251: mov    r12,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_2254:
	/* 0x2254: jmp    261b <generic_tracepoint_event+0x261b> */
	return 9755ULL;
x86_l_2259:
	/* 0x2259: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_225e:
	/* 0x225e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2263:
	/* 0x2263: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2268:
	/* 0x2268: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_226d:
	/* 0x226d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_226f:
	/* 0x226f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2272:
	/* 0x2272: je     25bf <generic_tracepoint_event+0x25bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9663ULL;
	}
x86_l_2278:
	/* 0x2278: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_227a:
	/* 0x227a: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_227f:
	/* 0x227f: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_2286:
	/* 0x2286: movabs rax,0x400000093 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869331ULL);
x86_l_2290:
	/* 0x2290: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2295:
	/* 0x2295: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_229c:
	/* 0x229c: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_22a1:
	/* 0x22a1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_22a6:
	/* 0x22a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22a8:
	/* 0x22a8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_22ab:
	/* 0x22ab: jne    2410 <generic_tracepoint_event+0x2410> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9232ULL;
	}
x86_l_22b1:
	/* 0x22b1: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_22b9:
	/* 0x22b9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_22c0:
	/* 0x22c0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_22c2:
	/* 0x22c2: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_22c7:
	/* 0x22c7: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22cc:
	/* 0x22cc: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_22d1:
	/* 0x22d1: jmp    25bb <generic_tracepoint_event+0x25bb> */
	return 9659ULL;
x86_l_22d6:
	/* 0x22d6: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22db:
	/* 0x22db: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_22e0:
	/* 0x22e0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22e5:
	/* 0x22e5: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_22ea:
	/* 0x22ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22ec:
	/* 0x22ec: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_22ef:
	/* 0x22ef: je     2561 <generic_tracepoint_event+0x2561> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9569ULL;
	}
x86_l_22f5:
	/* 0x22f5: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_22f7:
	/* 0x22f7: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_22fc:
	/* 0x22fc: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_2303:
	/* 0x2303: movabs rax,0x40000007a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869306ULL);
x86_l_230d:
	/* 0x230d: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2312:
	/* 0x2312: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2319:
	/* 0x2319: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_231e:
	/* 0x231e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2323:
	/* 0x2323: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2325:
	/* 0x2325: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2328:
	/* 0x2328: je     253d <generic_tracepoint_event+0x253d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9533ULL;
	}
x86_l_232e:
	/* 0x232e: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2330:
	/* 0x2330: movsx  r12,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_2336:
	/* 0x2336: jmp    261b <generic_tracepoint_event+0x261b> */
	return 9755ULL;
x86_l_233b:
	/* 0x233b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2340:
	/* 0x2340: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2345:
	/* 0x2345: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_234a:
	/* 0x234a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_234f:
	/* 0x234f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2351:
	/* 0x2351: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2354:
	/* 0x2354: je     25bf <generic_tracepoint_event+0x25bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9663ULL;
	}
x86_l_235a:
	/* 0x235a: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_235c:
	/* 0x235c: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2361:
	/* 0x2361: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_2368:
	/* 0x2368: movabs rax,0x4000000a1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869345ULL);
x86_l_2372:
	/* 0x2372: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2377:
	/* 0x2377: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_237e:
	/* 0x237e: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2383:
	/* 0x2383: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2388:
	/* 0x2388: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_238a:
	/* 0x238a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_238d:
	/* 0x238d: jne    2410 <generic_tracepoint_event+0x2410> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9232ULL;
	}
x86_l_2393:
	/* 0x2393: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_239b:
	/* 0x239b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_23a2:
	/* 0x23a2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_23a4:
	/* 0x23a4: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_23a9:
	/* 0x23a9: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23ae:
	/* 0x23ae: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_23b3:
	/* 0x23b3: jmp    25bb <generic_tracepoint_event+0x25bb> */
	return 9659ULL;
x86_l_23b8:
	/* 0x23b8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23bd:
	/* 0x23bd: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_23c2:
	/* 0x23c2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
	return 9159ULL;
}

static __noinline __u64 tetragon_bpf_generic_tracepoint_v53_generic_tracepoint_event_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9159ULL: goto x86_l_23c7;
	case 9164ULL: goto x86_l_23cc;
	case 9166ULL: goto x86_l_23ce;
	case 9169ULL: goto x86_l_23d1;
	case 9175ULL: goto x86_l_23d7;
	case 9177ULL: goto x86_l_23d9;
	case 9182ULL: goto x86_l_23de;
	case 9189ULL: goto x86_l_23e5;
	case 9199ULL: goto x86_l_23ef;
	case 9204ULL: goto x86_l_23f4;
	case 9211ULL: goto x86_l_23fb;
	case 9216ULL: goto x86_l_2400;
	case 9221ULL: goto x86_l_2405;
	case 9223ULL: goto x86_l_2407;
	case 9226ULL: goto x86_l_240a;
	case 9232ULL: goto x86_l_2410;
	case 9234ULL: goto x86_l_2412;
	case 9239ULL: goto x86_l_2417;
	case 9244ULL: goto x86_l_241c;
	case 9249ULL: goto x86_l_2421;
	case 9254ULL: goto x86_l_2426;
	case 9259ULL: goto x86_l_242b;
	case 9261ULL: goto x86_l_242d;
	case 9264ULL: goto x86_l_2430;
	case 9270ULL: goto x86_l_2436;
	case 9272ULL: goto x86_l_2438;
	case 9277ULL: goto x86_l_243d;
	case 9284ULL: goto x86_l_2444;
	case 9294ULL: goto x86_l_244e;
	case 9299ULL: goto x86_l_2453;
	case 9306ULL: goto x86_l_245a;
	case 9311ULL: goto x86_l_245f;
	case 9316ULL: goto x86_l_2464;
	case 9318ULL: goto x86_l_2466;
	case 9321ULL: goto x86_l_2469;
	case 9327ULL: goto x86_l_246f;
	case 9329ULL: goto x86_l_2471;
	case 9335ULL: goto x86_l_2477;
	case 9340ULL: goto x86_l_247c;
	case 9345ULL: goto x86_l_2481;
	case 9350ULL: goto x86_l_2486;
	case 9355ULL: goto x86_l_248b;
	case 9360ULL: goto x86_l_2490;
	case 9362ULL: goto x86_l_2492;
	case 9365ULL: goto x86_l_2495;
	case 9371ULL: goto x86_l_249b;
	case 9373ULL: goto x86_l_249d;
	case 9378ULL: goto x86_l_24a2;
	case 9385ULL: goto x86_l_24a9;
	case 9395ULL: goto x86_l_24b3;
	case 9400ULL: goto x86_l_24b8;
	case 9407ULL: goto x86_l_24bf;
	case 9412ULL: goto x86_l_24c4;
	case 9417ULL: goto x86_l_24c9;
	case 9419ULL: goto x86_l_24cb;
	case 9422ULL: goto x86_l_24ce;
	case 9428ULL: goto x86_l_24d4;
	case 9430ULL: goto x86_l_24d6;
	case 9435ULL: goto x86_l_24db;
	case 9440ULL: goto x86_l_24e0;
	case 9448ULL: goto x86_l_24e8;
	case 9455ULL: goto x86_l_24ef;
	case 9457ULL: goto x86_l_24f1;
	case 9462ULL: goto x86_l_24f6;
	case 9467ULL: goto x86_l_24fb;
	case 9472ULL: goto x86_l_2500;
	case 9474ULL: goto x86_l_2502;
	case 9476ULL: goto x86_l_2504;
	case 9481ULL: goto x86_l_2509;
	case 9486ULL: goto x86_l_250e;
	case 9494ULL: goto x86_l_2516;
	case 9501ULL: goto x86_l_251d;
	case 9503ULL: goto x86_l_251f;
	case 9508ULL: goto x86_l_2524;
	case 9513ULL: goto x86_l_2529;
	case 9518ULL: goto x86_l_252e;
	case 9520ULL: goto x86_l_2530;
	case 9522ULL: goto x86_l_2532;
	case 9528ULL: goto x86_l_2538;
	case 9533ULL: goto x86_l_253d;
	case 9541ULL: goto x86_l_2545;
	case 9548ULL: goto x86_l_254c;
	case 9550ULL: goto x86_l_254e;
	case 9555ULL: goto x86_l_2553;
	case 9560ULL: goto x86_l_2558;
	case 9565ULL: goto x86_l_255d;
	case 9567ULL: goto x86_l_255f;
	case 9569ULL: goto x86_l_2561;
	case 9575ULL: goto x86_l_2567;
	case 9580ULL: goto x86_l_256c;
	case 9588ULL: goto x86_l_2574;
	case 9595ULL: goto x86_l_257b;
	case 9597ULL: goto x86_l_257d;
	case 9602ULL: goto x86_l_2582;
	case 9607ULL: goto x86_l_2587;
	case 9612ULL: goto x86_l_258c;
	case 9614ULL: goto x86_l_258e;
	case 9616ULL: goto x86_l_2590;
	case 9622ULL: goto x86_l_2596;
	case 9627ULL: goto x86_l_259b;
	case 9635ULL: goto x86_l_25a3;
	case 9642ULL: goto x86_l_25aa;
	case 9644ULL: goto x86_l_25ac;
	case 9649ULL: goto x86_l_25b1;
	case 9654ULL: goto x86_l_25b6;
	case 9659ULL: goto x86_l_25bb;
	case 9661ULL: goto x86_l_25bd;
	case 9663ULL: goto x86_l_25bf;
	case 9668ULL: goto x86_l_25c4;
	case 9670ULL: goto x86_l_25c6;
	case 9678ULL: goto x86_l_25ce;
	case 9685ULL: goto x86_l_25d5;
	case 9687ULL: goto x86_l_25d7;
	case 9692ULL: goto x86_l_25dc;
	case 9697ULL: goto x86_l_25e1;
	case 9702ULL: goto x86_l_25e6;
	case 9704ULL: goto x86_l_25e8;
	case 9706ULL: goto x86_l_25ea;
	case 9712ULL: goto x86_l_25f0;
	case 9714ULL: goto x86_l_25f2;
	case 9722ULL: goto x86_l_25fa;
	case 9729ULL: goto x86_l_2601;
	case 9731ULL: goto x86_l_2603;
	case 9736ULL: goto x86_l_2608;
	case 9741ULL: goto x86_l_260d;
	case 9746ULL: goto x86_l_2612;
	case 9748ULL: goto x86_l_2614;
	case 9750ULL: goto x86_l_2616;
	case 9755ULL: goto x86_l_261b;
	case 9762ULL: goto x86_l_2622;
	case 9767ULL: goto x86_l_2627;
	case 9771ULL: goto x86_l_262b;
	case 9774ULL: goto x86_l_262e;
	case 9777ULL: goto x86_l_2631;
	case 9781ULL: goto x86_l_2635;
	case 9783ULL: goto x86_l_2637;
	case 9787ULL: goto x86_l_263b;
	case 9793ULL: goto x86_l_2641;
	case 9797ULL: goto x86_l_2645;
	case 9803ULL: goto x86_l_264b;
	case 9807ULL: goto x86_l_264f;
	case 9813ULL: goto x86_l_2655;
	case 9817ULL: goto x86_l_2659;
	case 9823ULL: goto x86_l_265f;
	case 9827ULL: goto x86_l_2663;
	case 9833ULL: goto x86_l_2669;
	case 9838ULL: goto x86_l_266e;
	case 9842ULL: goto x86_l_2672;
	case 9848ULL: goto x86_l_2678;
	case 9852ULL: goto x86_l_267c;
	case 9858ULL: goto x86_l_2682;
	case 9862ULL: goto x86_l_2686;
	case 9868ULL: goto x86_l_268c;
	case 9872ULL: goto x86_l_2690;
	case 9878ULL: goto x86_l_2696;
	case 9882ULL: goto x86_l_269a;
	case 9888ULL: goto x86_l_26a0;
	case 9893ULL: goto x86_l_26a5;
	case 9898ULL: goto x86_l_26aa;
	case 9903ULL: goto x86_l_26af;
	case 9908ULL: goto x86_l_26b4;
	case 9910ULL: goto x86_l_26b6;
	case 9913ULL: goto x86_l_26b9;
	case 9919ULL: goto x86_l_26bf;
	case 9921ULL: goto x86_l_26c1;
	case 9926ULL: goto x86_l_26c6;
	case 9933ULL: goto x86_l_26cd;
	case 9943ULL: goto x86_l_26d7;
	case 9948ULL: goto x86_l_26dc;
	case 9955ULL: goto x86_l_26e3;
	case 9960ULL: goto x86_l_26e8;
	case 9965ULL: goto x86_l_26ed;
	case 9967ULL: goto x86_l_26ef;
	case 9970ULL: goto x86_l_26f2;
	case 9976ULL: goto x86_l_26f8;
	case 9978ULL: goto x86_l_26fa;
	case 9984ULL: goto x86_l_2700;
	case 9989ULL: goto x86_l_2705;
	case 9993ULL: goto x86_l_2709;
	case 9999ULL: goto x86_l_270f;
	case 10004ULL: goto x86_l_2714;
	case 10007ULL: goto x86_l_2717;
	case 10013ULL: goto x86_l_271d;
	case 10017ULL: goto x86_l_2721;
	case 10023ULL: goto x86_l_2727;
	case 10028ULL: goto x86_l_272c;
	case 10033ULL: goto x86_l_2731;
	case 10038ULL: goto x86_l_2736;
	case 10043ULL: goto x86_l_273b;
	case 10045ULL: goto x86_l_273d;
	case 10048ULL: goto x86_l_2740;
	case 10054ULL: goto x86_l_2746;
	case 10056ULL: goto x86_l_2748;
	case 10061ULL: goto x86_l_274d;
	case 10068ULL: goto x86_l_2754;
	case 10078ULL: goto x86_l_275e;
	case 10083ULL: goto x86_l_2763;
	case 10090ULL: goto x86_l_276a;
	case 10095ULL: goto x86_l_276f;
	case 10100ULL: goto x86_l_2774;
	case 10102ULL: goto x86_l_2776;
	case 10105ULL: goto x86_l_2779;
	case 10111ULL: goto x86_l_277f;
	case 10119ULL: goto x86_l_2787;
	case 10126ULL: goto x86_l_278e;
	case 10128ULL: goto x86_l_2790;
	case 10133ULL: goto x86_l_2795;
	case 10138ULL: goto x86_l_279a;
	case 10143ULL: goto x86_l_279f;
	case 10148ULL: goto x86_l_27a4;
	case 10152ULL: goto x86_l_27a8;
	case 10158ULL: goto x86_l_27ae;
	case 10162ULL: goto x86_l_27b2;
	case 10168ULL: goto x86_l_27b8;
	case 10172ULL: goto x86_l_27bc;
	case 10178ULL: goto x86_l_27c2;
	case 10182ULL: goto x86_l_27c6;
	case 10188ULL: goto x86_l_27cc;
	case 10193ULL: goto x86_l_27d1;
	case 10198ULL: goto x86_l_27d6;
	case 10203ULL: goto x86_l_27db;
	case 10208ULL: goto x86_l_27e0;
	case 10210ULL: goto x86_l_27e2;
	case 10213ULL: goto x86_l_27e5;
	case 10219ULL: goto x86_l_27eb;
	case 10221ULL: goto x86_l_27ed;
	case 10226ULL: goto x86_l_27f2;
	case 10233ULL: goto x86_l_27f9;
	case 10243ULL: goto x86_l_2803;
	case 10248ULL: goto x86_l_2808;
	case 10255ULL: goto x86_l_280f;
	case 10260ULL: goto x86_l_2814;
	case 10265ULL: goto x86_l_2819;
	case 10267ULL: goto x86_l_281b;
	case 10270ULL: goto x86_l_281e;
	case 10276ULL: goto x86_l_2824;
	case 10278ULL: goto x86_l_2826;
	case 10284ULL: goto x86_l_282c;
	case 10289ULL: goto x86_l_2831;
	case 10294ULL: goto x86_l_2836;
	case 10297ULL: goto x86_l_2839;
	case 10303ULL: goto x86_l_283f;
	case 10308ULL: goto x86_l_2844;
	case 10313ULL: goto x86_l_2849;
	case 10318ULL: goto x86_l_284e;
	case 10323ULL: goto x86_l_2853;
	case 10325ULL: goto x86_l_2855;
	case 10328ULL: goto x86_l_2858;
	case 10334ULL: goto x86_l_285e;
	case 10336ULL: goto x86_l_2860;
	case 10341ULL: goto x86_l_2865;
	case 10348ULL: goto x86_l_286c;
	case 10358ULL: goto x86_l_2876;
	case 10363ULL: goto x86_l_287b;
	case 10370ULL: goto x86_l_2882;
	case 10375ULL: goto x86_l_2887;
	case 10380ULL: goto x86_l_288c;
	case 10382ULL: goto x86_l_288e;
	case 10385ULL: goto x86_l_2891;
	case 10391ULL: goto x86_l_2897;
	case 10393ULL: goto x86_l_2899;
	case 10398ULL: goto x86_l_289e;
	case 10402ULL: goto x86_l_28a2;
	case 10408ULL: goto x86_l_28a8;
	case 10412ULL: goto x86_l_28ac;
	case 10418ULL: goto x86_l_28b2;
	case 10422ULL: goto x86_l_28b6;
	case 10428ULL: goto x86_l_28bc;
	case 10433ULL: goto x86_l_28c1;
	case 10438ULL: goto x86_l_28c6;
	case 10443ULL: goto x86_l_28cb;
	case 10448ULL: goto x86_l_28d0;
	case 10450ULL: goto x86_l_28d2;
	case 10453ULL: goto x86_l_28d5;
	case 10459ULL: goto x86_l_28db;
	case 10461ULL: goto x86_l_28dd;
	case 10466ULL: goto x86_l_28e2;
	case 10473ULL: goto x86_l_28e9;
	case 10483ULL: goto x86_l_28f3;
	case 10488ULL: goto x86_l_28f8;
	case 10495ULL: goto x86_l_28ff;
	case 10500ULL: goto x86_l_2904;
	case 10505ULL: goto x86_l_2909;
	case 10507ULL: goto x86_l_290b;
	case 10510ULL: goto x86_l_290e;
	case 10516ULL: goto x86_l_2914;
	case 10524ULL: goto x86_l_291c;
	case 10531ULL: goto x86_l_2923;
	case 10533ULL: goto x86_l_2925;
	case 10538ULL: goto x86_l_292a;
	case 10543ULL: goto x86_l_292f;
	case 10548ULL: goto x86_l_2934;
	case 10553ULL: goto x86_l_2939;
	case 10557ULL: goto x86_l_293d;
	case 10563ULL: goto x86_l_2943;
	case 10567ULL: goto x86_l_2947;
	case 10569ULL: goto x86_l_2949;
	case 10574ULL: goto x86_l_294e;
	case 10578ULL: goto x86_l_2952;
	case 10584ULL: goto x86_l_2958;
	case 10588ULL: goto x86_l_295c;
	case 10594ULL: goto x86_l_2962;
	case 10599ULL: goto x86_l_2967;
	case 10604ULL: goto x86_l_296c;
	case 10609ULL: goto x86_l_2971;
	case 10614ULL: goto x86_l_2976;
	case 10616ULL: goto x86_l_2978;
	case 10619ULL: goto x86_l_297b;
	case 10625ULL: goto x86_l_2981;
	case 10627ULL: goto x86_l_2983;
	case 10632ULL: goto x86_l_2988;
	case 10639ULL: goto x86_l_298f;
	case 10649ULL: goto x86_l_2999;
	case 10654ULL: goto x86_l_299e;
	case 10661ULL: goto x86_l_29a5;
	case 10666ULL: goto x86_l_29aa;
	case 10671ULL: goto x86_l_29af;
	case 10673ULL: goto x86_l_29b1;
	case 10676ULL: goto x86_l_29b4;
	case 10682ULL: goto x86_l_29ba;
	case 10690ULL: goto x86_l_29c2;
	case 10697ULL: goto x86_l_29c9;
	case 10699ULL: goto x86_l_29cb;
	case 10704ULL: goto x86_l_29d0;
	case 10709ULL: goto x86_l_29d5;
	case 10714ULL: goto x86_l_29da;
	case 10719ULL: goto x86_l_29df;
	case 10724ULL: goto x86_l_29e4;
	case 10729ULL: goto x86_l_29e9;
	case 10734ULL: goto x86_l_29ee;
	case 10739ULL: goto x86_l_29f3;
	case 10741ULL: goto x86_l_29f5;
	case 10744ULL: goto x86_l_29f8;
	case 10750ULL: goto x86_l_29fe;
	case 10752ULL: goto x86_l_2a00;
	case 10757ULL: goto x86_l_2a05;
	case 10764ULL: goto x86_l_2a0c;
	case 10774ULL: goto x86_l_2a16;
	case 10779ULL: goto x86_l_2a1b;
	case 10786ULL: goto x86_l_2a22;
	case 10791ULL: goto x86_l_2a27;
	case 10796ULL: goto x86_l_2a2c;
	case 10798ULL: goto x86_l_2a2e;
	case 10801ULL: goto x86_l_2a31;
	case 10807ULL: goto x86_l_2a37;
	case 10809ULL: goto x86_l_2a39;
	case 10814ULL: goto x86_l_2a3e;
	case 10819ULL: goto x86_l_2a43;
	case 10827ULL: goto x86_l_2a4b;
	case 10834ULL: goto x86_l_2a52;
	case 10836ULL: goto x86_l_2a54;
	case 10841ULL: goto x86_l_2a59;
	case 10846ULL: goto x86_l_2a5e;
	case 10851ULL: goto x86_l_2a63;
	case 10853ULL: goto x86_l_2a65;
	case 10855ULL: goto x86_l_2a67;
	case 10860ULL: goto x86_l_2a6c;
	case 10864ULL: goto x86_l_2a70;
	case 10870ULL: goto x86_l_2a76;
	case 10875ULL: goto x86_l_2a7b;
	case 10877ULL: goto x86_l_2a7d;
	case 10881ULL: goto x86_l_2a81;
	case 10886ULL: goto x86_l_2a86;
	case 10891ULL: goto x86_l_2a8b;
	case 10896ULL: goto x86_l_2a90;
	case 10901ULL: goto x86_l_2a95;
	case 10903ULL: goto x86_l_2a97;
	case 10907ULL: goto x86_l_2a9b;
	case 10910ULL: goto x86_l_2a9e;
	case 10913ULL: goto x86_l_2aa1;
	case 10916ULL: goto x86_l_2aa4;
	case 10921ULL: goto x86_l_2aa9;
	case 10925ULL: goto x86_l_2aad;
	case 10931ULL: goto x86_l_2ab3;
	case 10936ULL: goto x86_l_2ab8;
	case 10941ULL: goto x86_l_2abd;
	case 10946ULL: goto x86_l_2ac2;
	case 10951ULL: goto x86_l_2ac7;
	case 10953ULL: goto x86_l_2ac9;
	case 10956ULL: goto x86_l_2acc;
	case 10962ULL: goto x86_l_2ad2;
	case 10964ULL: goto x86_l_2ad4;
	case 10969ULL: goto x86_l_2ad9;
	case 10976ULL: goto x86_l_2ae0;
	default: return 0xffffffffffffffffULL;
	}
x86_l_23c7:
	/* 0x23c7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23cc:
	/* 0x23cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23ce:
	/* 0x23ce: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_23d1:
	/* 0x23d1: je     25bf <generic_tracepoint_event+0x25bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25bf;
	}
x86_l_23d7:
	/* 0x23d7: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_23d9:
	/* 0x23d9: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_23de:
	/* 0x23de: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_23e5:
	/* 0x23e5: movabs rax,0x40000004e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869262ULL);
x86_l_23ef:
	/* 0x23ef: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_23f4:
	/* 0x23f4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_23fb:
	/* 0x23fb: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2400:
	/* 0x2400: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2405:
	/* 0x2405: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2407:
	/* 0x2407: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_240a:
	/* 0x240a: je     259b <generic_tracepoint_event+0x259b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_259b;
	}
x86_l_2410:
	/* 0x2410: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2412:
	/* 0x2412: jmp    25bf <generic_tracepoint_event+0x25bf> */
	goto x86_l_25bf;
x86_l_2417:
	/* 0x2417: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_241c:
	/* 0x241c: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2421:
	/* 0x2421: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2426:
	/* 0x2426: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_242b:
	/* 0x242b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_242d:
	/* 0x242d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2430:
	/* 0x2430: je     25ea <generic_tracepoint_event+0x25ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25ea;
	}
x86_l_2436:
	/* 0x2436: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_2438:
	/* 0x2438: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_243d:
	/* 0x243d: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_2444:
	/* 0x2444: movabs rax,0x400000065 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869285ULL);
x86_l_244e:
	/* 0x244e: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2453:
	/* 0x2453: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_245a:
	/* 0x245a: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_245f:
	/* 0x245f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2464:
	/* 0x2464: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2466:
	/* 0x2466: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2469:
	/* 0x2469: je     25c6 <generic_tracepoint_event+0x25c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25c6;
	}
x86_l_246f:
	/* 0x246f: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2471:
	/* 0x2471: movzx  r12d,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_2477:
	/* 0x2477: jmp    261b <generic_tracepoint_event+0x261b> */
	goto x86_l_261b;
x86_l_247c:
	/* 0x247c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2481:
	/* 0x2481: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2486:
	/* 0x2486: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_248b:
	/* 0x248b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2490:
	/* 0x2490: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2492:
	/* 0x2492: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2495:
	/* 0x2495: je     2616 <generic_tracepoint_event+0x2616> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2616;
	}
x86_l_249b:
	/* 0x249b: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_249d:
	/* 0x249d: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_24a2:
	/* 0x24a2: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_24a9:
	/* 0x24a9: movabs rax,0x400000088 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869320ULL);
x86_l_24b3:
	/* 0x24b3: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_24b8:
	/* 0x24b8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_24bf:
	/* 0x24bf: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_24c4:
	/* 0x24c4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_24c9:
	/* 0x24c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24cb:
	/* 0x24cb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_24ce:
	/* 0x24ce: je     25f2 <generic_tracepoint_event+0x25f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25f2;
	}
x86_l_24d4:
	/* 0x24d4: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_24d6:
	/* 0x24d6: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24db:
	/* 0x24db: jmp    261b <generic_tracepoint_event+0x261b> */
	goto x86_l_261b;
x86_l_24e0:
	/* 0x24e0: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_24e8:
	/* 0x24e8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_24ef:
	/* 0x24ef: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_24f1:
	/* 0x24f1: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_24f6:
	/* 0x24f6: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24fb:
	/* 0x24fb: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2500:
	/* 0x2500: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2502:
	/* 0x2502: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2504:
	/* 0x2504: movsxd r12,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_2509:
	/* 0x2509: jmp    261b <generic_tracepoint_event+0x261b> */
	goto x86_l_261b;
x86_l_250e:
	/* 0x250e: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_2516:
	/* 0x2516: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_251d:
	/* 0x251d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_251f:
	/* 0x251f: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2524:
	/* 0x2524: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2529:
	/* 0x2529: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_252e:
	/* 0x252e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2530:
	/* 0x2530: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2532:
	/* 0x2532: movsx  r12,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_2538:
	/* 0x2538: jmp    261b <generic_tracepoint_event+0x261b> */
	goto x86_l_261b;
x86_l_253d:
	/* 0x253d: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_2545:
	/* 0x2545: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_254c:
	/* 0x254c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_254e:
	/* 0x254e: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2553:
	/* 0x2553: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2558:
	/* 0x2558: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_255d:
	/* 0x255d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_255f:
	/* 0x255f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2561:
	/* 0x2561: movsx  r12,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_2567:
	/* 0x2567: jmp    261b <generic_tracepoint_event+0x261b> */
	goto x86_l_261b;
x86_l_256c:
	/* 0x256c: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_2574:
	/* 0x2574: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_257b:
	/* 0x257b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_257d:
	/* 0x257d: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2582:
	/* 0x2582: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2587:
	/* 0x2587: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_258c:
	/* 0x258c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_258e:
	/* 0x258e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2590:
	/* 0x2590: movzx  r12d,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_2596:
	/* 0x2596: jmp    261b <generic_tracepoint_event+0x261b> */
	goto x86_l_261b;
x86_l_259b:
	/* 0x259b: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_25a3:
	/* 0x25a3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_25aa:
	/* 0x25aa: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_25ac:
	/* 0x25ac: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_25b1:
	/* 0x25b1: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25b6:
	/* 0x25b6: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_25bb:
	/* 0x25bb: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_25bd:
	/* 0x25bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25bf:
	/* 0x25bf: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25c4:
	/* 0x25c4: jmp    261b <generic_tracepoint_event+0x261b> */
	goto x86_l_261b;
x86_l_25c6:
	/* 0x25c6: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_25ce:
	/* 0x25ce: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_25d5:
	/* 0x25d5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_25d7:
	/* 0x25d7: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_25dc:
	/* 0x25dc: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25e1:
	/* 0x25e1: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_25e6:
	/* 0x25e6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_25e8:
	/* 0x25e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25ea:
	/* 0x25ea: movzx  r12d,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_25f0:
	/* 0x25f0: jmp    261b <generic_tracepoint_event+0x261b> */
	goto x86_l_261b;
x86_l_25f2:
	/* 0x25f2: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_25fa:
	/* 0x25fa: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2601:
	/* 0x2601: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2603:
	/* 0x2603: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2608:
	/* 0x2608: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_260d:
	/* 0x260d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2612:
	/* 0x2612: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2614:
	/* 0x2614: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2616:
	/* 0x2616: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_261b:
	/* 0x261b: mov    QWORD PTR [r14+0x5e68],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24168ULL);
x86_l_2622:
	/* 0x2622: movzx  edx,WORD PTR [r15+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 60ULL);
x86_l_2627:
	/* 0x2627: mov    r12d,DWORD PTR [r15+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_262b:
	/* 0x262b: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_262e:
	/* 0x262e: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2631:
	/* 0x2631: cmp    r12d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 11ULL);
x86_l_2635:
	/* 0x2635: jg     266e <generic_tracepoint_event+0x266e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_266e;
	}
x86_l_2637:
	/* 0x2637: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_263b:
	/* 0x263b: jle    2705 <generic_tracepoint_event+0x2705> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2705;
	}
x86_l_2641:
	/* 0x2641: cmp    r12d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 6ULL);
x86_l_2645:
	/* 0x2645: jg     2831 <generic_tracepoint_event+0x2831> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2831;
	}
x86_l_264b:
	/* 0x264b: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_264f:
	/* 0x264f: je     2c97 <generic_tracepoint_event+0x2c97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11415ULL;
	}
x86_l_2655:
	/* 0x2655: cmp    r12d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 5ULL);
x86_l_2659:
	/* 0x2659: je     2b38 <generic_tracepoint_event+0x2b38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11064ULL;
	}
x86_l_265f:
	/* 0x265f: cmp    r12d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 6ULL);
x86_l_2663:
	/* 0x2663: je     2727 <generic_tracepoint_event+0x2727> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2727;
	}
x86_l_2669:
	/* 0x2669: jmp    2efa <generic_tracepoint_event+0x2efa> */
	return 12026ULL;
x86_l_266e:
	/* 0x266e: cmp    r12d,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 29ULL);
x86_l_2672:
	/* 0x2672: jle    27a4 <generic_tracepoint_event+0x27a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_27a4;
	}
x86_l_2678:
	/* 0x2678: cmp    r12d,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 37ULL);
x86_l_267c:
	/* 0x267c: jg     289e <generic_tracepoint_event+0x289e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_289e;
	}
x86_l_2682:
	/* 0x2682: cmp    r12d,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 30ULL);
x86_l_2686:
	/* 0x2686: je     2cf6 <generic_tracepoint_event+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11510ULL;
	}
x86_l_268c:
	/* 0x268c: cmp    r12d,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 31ULL);
x86_l_2690:
	/* 0x2690: je     2bb5 <generic_tracepoint_event+0x2bb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11189ULL;
	}
x86_l_2696:
	/* 0x2696: cmp    r12d,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 32ULL);
x86_l_269a:
	/* 0x269a: jne    2efa <generic_tracepoint_event+0x2efa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12026ULL;
	}
x86_l_26a0:
	/* 0x26a0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26a5:
	/* 0x26a5: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_26aa:
	/* 0x26aa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_26af:
	/* 0x26af: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_26b4:
	/* 0x26b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26b6:
	/* 0x26b6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_26b9:
	/* 0x26b9: je     2e6f <generic_tracepoint_event+0x2e6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11887ULL;
	}
x86_l_26bf:
	/* 0x26bf: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_26c1:
	/* 0x26c1: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_26c6:
	/* 0x26c6: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_26cd:
	/* 0x26cd: movabs rax,0x400000073 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869299ULL);
x86_l_26d7:
	/* 0x26d7: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_26dc:
	/* 0x26dc: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_26e3:
	/* 0x26e3: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_26e8:
	/* 0x26e8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_26ed:
	/* 0x26ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26ef:
	/* 0x26ef: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_26f2:
	/* 0x26f2: je     2e4b <generic_tracepoint_event+0x2e4b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11851ULL;
	}
x86_l_26f8:
	/* 0x26f8: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_26fa:
	/* 0x26fa: movzx  r15d,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_2700:
	/* 0x2700: jmp    2efa <generic_tracepoint_event+0x2efa> */
	return 12026ULL;
x86_l_2705:
	/* 0x2705: cmp    r12d,0xfffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4294967284ULL);
x86_l_2709:
	/* 0x2709: jle    2939 <generic_tracepoint_event+0x2939> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2939;
	}
x86_l_270f:
	/* 0x270f: lea    eax,[r12+0xb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 11ULL);
x86_l_2714:
	/* 0x2714: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2717:
	/* 0x2717: jb     283f <generic_tracepoint_event+0x283f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_283f;
	}
x86_l_271d:
	/* 0x271d: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_2721:
	/* 0x2721: jne    2efa <generic_tracepoint_event+0x2efa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12026ULL;
	}
x86_l_2727:
	/* 0x2727: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_272c:
	/* 0x272c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2731:
	/* 0x2731: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2736:
	/* 0x2736: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_273b:
	/* 0x273b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_273d:
	/* 0x273d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2740:
	/* 0x2740: je     2e9e <generic_tracepoint_event+0x2e9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11934ULL;
	}
x86_l_2746:
	/* 0x2746: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_2748:
	/* 0x2748: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_274d:
	/* 0x274d: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_2754:
	/* 0x2754: movabs rax,0x400000081 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869313ULL);
x86_l_275e:
	/* 0x275e: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2763:
	/* 0x2763: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_276a:
	/* 0x276a: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_276f:
	/* 0x276f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2774:
	/* 0x2774: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2776:
	/* 0x2776: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2779:
	/* 0x2779: jne    2cef <generic_tracepoint_event+0x2cef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11503ULL;
	}
x86_l_277f:
	/* 0x277f: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_2787:
	/* 0x2787: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_278e:
	/* 0x278e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2790:
	/* 0x2790: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2795:
	/* 0x2795: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_279a:
	/* 0x279a: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_279f:
	/* 0x279f: jmp    2e9a <generic_tracepoint_event+0x2e9a> */
	return 11930ULL;
x86_l_27a4:
	/* 0x27a4: cmp    r12d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 17ULL);
x86_l_27a8:
	/* 0x27a8: jle    294e <generic_tracepoint_event+0x294e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_294e;
	}
x86_l_27ae:
	/* 0x27ae: cmp    r12d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 18ULL);
x86_l_27b2:
	/* 0x27b2: je     2b30 <generic_tracepoint_event+0x2b30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11056ULL;
	}
x86_l_27b8:
	/* 0x27b8: cmp    r12d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 28ULL);
x86_l_27bc:
	/* 0x27bc: je     283f <generic_tracepoint_event+0x283f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_283f;
	}
x86_l_27c2:
	/* 0x27c2: cmp    r12d,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 29ULL);
x86_l_27c6:
	/* 0x27c6: jne    2efa <generic_tracepoint_event+0x2efa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12026ULL;
	}
x86_l_27cc:
	/* 0x27cc: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27d1:
	/* 0x27d1: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_27d6:
	/* 0x27d6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_27db:
	/* 0x27db: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_27e0:
	/* 0x27e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27e2:
	/* 0x27e2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_27e5:
	/* 0x27e5: je     2e11 <generic_tracepoint_event+0x2e11> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11793ULL;
	}
x86_l_27eb:
	/* 0x27eb: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_27ed:
	/* 0x27ed: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_27f2:
	/* 0x27f2: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_27f9:
	/* 0x27f9: movabs rax,0x40000006c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869292ULL);
x86_l_2803:
	/* 0x2803: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2808:
	/* 0x2808: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_280f:
	/* 0x280f: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2814:
	/* 0x2814: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2819:
	/* 0x2819: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_281b:
	/* 0x281b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_281e:
	/* 0x281e: je     2ded <generic_tracepoint_event+0x2ded> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11757ULL;
	}
x86_l_2824:
	/* 0x2824: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2826:
	/* 0x2826: movsx  r15,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_282c:
	/* 0x282c: jmp    2efa <generic_tracepoint_event+0x2efa> */
	return 12026ULL;
x86_l_2831:
	/* 0x2831: lea    eax,[r12-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_2836:
	/* 0x2836: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2839:
	/* 0x2839: jae    2aa9 <generic_tracepoint_event+0x2aa9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2aa9;
	}
x86_l_283f:
	/* 0x283f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2844:
	/* 0x2844: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2849:
	/* 0x2849: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_284e:
	/* 0x284e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2853:
	/* 0x2853: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2855:
	/* 0x2855: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2858:
	/* 0x2858: je     2a67 <generic_tracepoint_event+0x2a67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a67;
	}
x86_l_285e:
	/* 0x285e: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_2860:
	/* 0x2860: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2865:
	/* 0x2865: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_286c:
	/* 0x286c: movabs rax,0x400000045 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869253ULL);
x86_l_2876:
	/* 0x2876: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_287b:
	/* 0x287b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2882:
	/* 0x2882: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2887:
	/* 0x2887: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_288c:
	/* 0x288c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_288e:
	/* 0x288e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2891:
	/* 0x2891: je     2a43 <generic_tracepoint_event+0x2a43> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a43;
	}
x86_l_2897:
	/* 0x2897: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2899:
	/* 0x2899: jmp    2a67 <generic_tracepoint_event+0x2a67> */
	goto x86_l_2a67;
x86_l_289e:
	/* 0x289e: cmp    r12d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 38ULL);
x86_l_28a2:
	/* 0x28a2: je     2d5b <generic_tracepoint_event+0x2d5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11611ULL;
	}
x86_l_28a8:
	/* 0x28a8: cmp    r12d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 40ULL);
x86_l_28ac:
	/* 0x28ac: je     2c1a <generic_tracepoint_event+0x2c1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11290ULL;
	}
x86_l_28b2:
	/* 0x28b2: cmp    r12d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 41ULL);
x86_l_28b6:
	/* 0x28b6: jne    2efa <generic_tracepoint_event+0x2efa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12026ULL;
	}
x86_l_28bc:
	/* 0x28bc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28c1:
	/* 0x28c1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_28c6:
	/* 0x28c6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_28cb:
	/* 0x28cb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28d0:
	/* 0x28d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28d2:
	/* 0x28d2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_28d5:
	/* 0x28d5: je     2e9e <generic_tracepoint_event+0x2e9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11934ULL;
	}
x86_l_28db:
	/* 0x28db: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_28dd:
	/* 0x28dd: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_28e2:
	/* 0x28e2: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_28e9:
	/* 0x28e9: movabs rax,0x4000000a8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869352ULL);
x86_l_28f3:
	/* 0x28f3: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_28f8:
	/* 0x28f8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_28ff:
	/* 0x28ff: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2904:
	/* 0x2904: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2909:
	/* 0x2909: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_290b:
	/* 0x290b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_290e:
	/* 0x290e: jne    2cef <generic_tracepoint_event+0x2cef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11503ULL;
	}
x86_l_2914:
	/* 0x2914: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_291c:
	/* 0x291c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2923:
	/* 0x2923: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2925:
	/* 0x2925: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_292a:
	/* 0x292a: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_292f:
	/* 0x292f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2934:
	/* 0x2934: jmp    2e9a <generic_tracepoint_event+0x2e9a> */
	return 11930ULL;
x86_l_2939:
	/* 0x2939: cmp    r12d,0xfffffff3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4294967283ULL);
x86_l_293d:
	/* 0x293d: je     29df <generic_tracepoint_event+0x29df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29df;
	}
x86_l_2943:
	/* 0x2943: cmp    r12d,0xfffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4294967284ULL);
x86_l_2947:
	/* 0x2947: je     2962 <generic_tracepoint_event+0x2962> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2962;
	}
x86_l_2949:
	/* 0x2949: jmp    2efa <generic_tracepoint_event+0x2efa> */
	return 12026ULL;
x86_l_294e:
	/* 0x294e: cmp    r12d,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 12ULL);
x86_l_2952:
	/* 0x2952: je     29df <generic_tracepoint_event+0x29df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29df;
	}
x86_l_2958:
	/* 0x2958: cmp    r12d,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 13ULL);
x86_l_295c:
	/* 0x295c: jne    2efa <generic_tracepoint_event+0x2efa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12026ULL;
	}
x86_l_2962:
	/* 0x2962: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2967:
	/* 0x2967: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_296c:
	/* 0x296c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2971:
	/* 0x2971: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2976:
	/* 0x2976: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2978:
	/* 0x2978: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_297b:
	/* 0x297b: je     2ef5 <generic_tracepoint_event+0x2ef5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12021ULL;
	}
x86_l_2981:
	/* 0x2981: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_2983:
	/* 0x2983: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2988:
	/* 0x2988: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_298f:
	/* 0x298f: movabs rax,0x40000005e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869278ULL);
x86_l_2999:
	/* 0x2999: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_299e:
	/* 0x299e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_29a5:
	/* 0x29a5: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_29aa:
	/* 0x29aa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_29af:
	/* 0x29af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29b1:
	/* 0x29b1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_29b4:
	/* 0x29b4: jne    2db3 <generic_tracepoint_event+0x2db3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11699ULL;
	}
x86_l_29ba:
	/* 0x29ba: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_29c2:
	/* 0x29c2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_29c9:
	/* 0x29c9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_29cb:
	/* 0x29cb: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_29d0:
	/* 0x29d0: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29d5:
	/* 0x29d5: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_29da:
	/* 0x29da: jmp    2ef1 <generic_tracepoint_event+0x2ef1> */
	return 12017ULL;
x86_l_29df:
	/* 0x29df: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29e4:
	/* 0x29e4: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_29e9:
	/* 0x29e9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_29ee:
	/* 0x29ee: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_29f3:
	/* 0x29f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29f5:
	/* 0x29f5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_29f8:
	/* 0x29f8: je     2de3 <generic_tracepoint_event+0x2de3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11747ULL;
	}
x86_l_29fe:
	/* 0x29fe: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_2a00:
	/* 0x2a00: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a05:
	/* 0x2a05: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_2a0c:
	/* 0x2a0c: movabs rax,0x400000056 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869270ULL);
x86_l_2a16:
	/* 0x2a16: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2a1b:
	/* 0x2a1b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2a22:
	/* 0x2a22: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a27:
	/* 0x2a27: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a2c:
	/* 0x2a2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a2e:
	/* 0x2a2e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2a31:
	/* 0x2a31: je     2dbf <generic_tracepoint_event+0x2dbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11711ULL;
	}
x86_l_2a37:
	/* 0x2a37: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2a39:
	/* 0x2a39: movsxd r15,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_2a3e:
	/* 0x2a3e: jmp    2efa <generic_tracepoint_event+0x2efa> */
	return 12026ULL;
x86_l_2a43:
	/* 0x2a43: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_2a4b:
	/* 0x2a4b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2a52:
	/* 0x2a52: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a54:
	/* 0x2a54: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a59:
	/* 0x2a59: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a5e:
	/* 0x2a5e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2a63:
	/* 0x2a63: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a65:
	/* 0x2a65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a67:
	/* 0x2a67: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a6c:
	/* 0x2a6c: cmp    r12d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 28ULL);
x86_l_2a70:
	/* 0x2a70: jne    2efa <generic_tracepoint_event+0x2efa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12026ULL;
	}
x86_l_2a76:
	/* 0x2a76: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_2a7b:
	/* 0x2a7b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a7d:
	/* 0x2a7d: lea    rdx,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a81:
	/* 0x2a81: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a86:
	/* 0x2a86: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2a8b:
	/* 0x2a8b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a90:
	/* 0x2a90: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2a95:
	/* 0x2a95: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a97:
	/* 0x2a97: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a9b:
	/* 0x2a9b: and    eax,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_2a9e:
	/* 0x2a9e: shl    eax,0x1e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 30ULL);
x86_l_2aa1:
	/* 0x2aa1: or     r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2aa4:
	/* 0x2aa4: jmp    2efa <generic_tracepoint_event+0x2efa> */
	return 12026ULL;
x86_l_2aa9:
	/* 0x2aa9: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_2aad:
	/* 0x2aad: jne    2efa <generic_tracepoint_event+0x2efa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12026ULL;
	}
x86_l_2ab3:
	/* 0x2ab3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ab8:
	/* 0x2ab8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2abd:
	/* 0x2abd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ac2:
	/* 0x2ac2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ac7:
	/* 0x2ac7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ac9:
	/* 0x2ac9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2acc:
	/* 0x2acc: je     2e9e <generic_tracepoint_event+0x2e9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11934ULL;
	}
x86_l_2ad2:
	/* 0x2ad2: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_2ad4:
	/* 0x2ad4: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ad9:
	/* 0x2ad9: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_2ae0:
	/* 0x2ae0: movabs rax,0x40000009a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869338ULL);
	return 10986ULL;
}

static __noinline __u64 tetragon_bpf_generic_tracepoint_v53_generic_tracepoint_event_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10986ULL: goto x86_l_2aea;
	case 10991ULL: goto x86_l_2aef;
	case 10998ULL: goto x86_l_2af6;
	case 11003ULL: goto x86_l_2afb;
	case 11008ULL: goto x86_l_2b00;
	case 11010ULL: goto x86_l_2b02;
	case 11013ULL: goto x86_l_2b05;
	case 11019ULL: goto x86_l_2b0b;
	case 11027ULL: goto x86_l_2b13;
	case 11034ULL: goto x86_l_2b1a;
	case 11036ULL: goto x86_l_2b1c;
	case 11041ULL: goto x86_l_2b21;
	case 11046ULL: goto x86_l_2b26;
	case 11051ULL: goto x86_l_2b2b;
	case 11056ULL: goto x86_l_2b30;
	case 11059ULL: goto x86_l_2b33;
	case 11064ULL: goto x86_l_2b38;
	case 11069ULL: goto x86_l_2b3d;
	case 11074ULL: goto x86_l_2b42;
	case 11079ULL: goto x86_l_2b47;
	case 11084ULL: goto x86_l_2b4c;
	case 11086ULL: goto x86_l_2b4e;
	case 11089ULL: goto x86_l_2b51;
	case 11095ULL: goto x86_l_2b57;
	case 11097ULL: goto x86_l_2b59;
	case 11102ULL: goto x86_l_2b5e;
	case 11109ULL: goto x86_l_2b65;
	case 11119ULL: goto x86_l_2b6f;
	case 11124ULL: goto x86_l_2b74;
	case 11131ULL: goto x86_l_2b7b;
	case 11136ULL: goto x86_l_2b80;
	case 11141ULL: goto x86_l_2b85;
	case 11143ULL: goto x86_l_2b87;
	case 11146ULL: goto x86_l_2b8a;
	case 11152ULL: goto x86_l_2b90;
	case 11160ULL: goto x86_l_2b98;
	case 11167ULL: goto x86_l_2b9f;
	case 11169ULL: goto x86_l_2ba1;
	case 11174ULL: goto x86_l_2ba6;
	case 11179ULL: goto x86_l_2bab;
	case 11184ULL: goto x86_l_2bb0;
	case 11189ULL: goto x86_l_2bb5;
	case 11194ULL: goto x86_l_2bba;
	case 11199ULL: goto x86_l_2bbf;
	case 11204ULL: goto x86_l_2bc4;
	case 11209ULL: goto x86_l_2bc9;
	case 11211ULL: goto x86_l_2bcb;
	case 11214ULL: goto x86_l_2bce;
	case 11220ULL: goto x86_l_2bd4;
	case 11222ULL: goto x86_l_2bd6;
	case 11227ULL: goto x86_l_2bdb;
	case 11234ULL: goto x86_l_2be2;
	case 11244ULL: goto x86_l_2bec;
	case 11249ULL: goto x86_l_2bf1;
	case 11256ULL: goto x86_l_2bf8;
	case 11261ULL: goto x86_l_2bfd;
	case 11266ULL: goto x86_l_2c02;
	case 11268ULL: goto x86_l_2c04;
	case 11271ULL: goto x86_l_2c07;
	case 11277ULL: goto x86_l_2c0d;
	case 11279ULL: goto x86_l_2c0f;
	case 11285ULL: goto x86_l_2c15;
	case 11290ULL: goto x86_l_2c1a;
	case 11295ULL: goto x86_l_2c1f;
	case 11300ULL: goto x86_l_2c24;
	case 11305ULL: goto x86_l_2c29;
	case 11310ULL: goto x86_l_2c2e;
	case 11312ULL: goto x86_l_2c30;
	case 11315ULL: goto x86_l_2c33;
	case 11321ULL: goto x86_l_2c39;
	case 11323ULL: goto x86_l_2c3b;
	case 11328ULL: goto x86_l_2c40;
	case 11335ULL: goto x86_l_2c47;
	case 11345ULL: goto x86_l_2c51;
	case 11350ULL: goto x86_l_2c56;
	case 11357ULL: goto x86_l_2c5d;
	case 11362ULL: goto x86_l_2c62;
	case 11367ULL: goto x86_l_2c67;
	case 11369ULL: goto x86_l_2c69;
	case 11372ULL: goto x86_l_2c6c;
	case 11378ULL: goto x86_l_2c72;
	case 11386ULL: goto x86_l_2c7a;
	case 11393ULL: goto x86_l_2c81;
	case 11395ULL: goto x86_l_2c83;
	case 11400ULL: goto x86_l_2c88;
	case 11405ULL: goto x86_l_2c8d;
	case 11410ULL: goto x86_l_2c92;
	case 11415ULL: goto x86_l_2c97;
	case 11420ULL: goto x86_l_2c9c;
	case 11425ULL: goto x86_l_2ca1;
	case 11430ULL: goto x86_l_2ca6;
	case 11435ULL: goto x86_l_2cab;
	case 11437ULL: goto x86_l_2cad;
	case 11440ULL: goto x86_l_2cb0;
	case 11446ULL: goto x86_l_2cb6;
	case 11448ULL: goto x86_l_2cb8;
	case 11453ULL: goto x86_l_2cbd;
	case 11460ULL: goto x86_l_2cc4;
	case 11470ULL: goto x86_l_2cce;
	case 11475ULL: goto x86_l_2cd3;
	case 11482ULL: goto x86_l_2cda;
	case 11487ULL: goto x86_l_2cdf;
	case 11492ULL: goto x86_l_2ce4;
	case 11494ULL: goto x86_l_2ce6;
	case 11497ULL: goto x86_l_2ce9;
	case 11503ULL: goto x86_l_2cef;
	case 11505ULL: goto x86_l_2cf1;
	case 11510ULL: goto x86_l_2cf6;
	case 11515ULL: goto x86_l_2cfb;
	case 11520ULL: goto x86_l_2d00;
	case 11525ULL: goto x86_l_2d05;
	case 11530ULL: goto x86_l_2d0a;
	case 11532ULL: goto x86_l_2d0c;
	case 11535ULL: goto x86_l_2d0f;
	case 11541ULL: goto x86_l_2d15;
	case 11543ULL: goto x86_l_2d17;
	case 11548ULL: goto x86_l_2d1c;
	case 11555ULL: goto x86_l_2d23;
	case 11565ULL: goto x86_l_2d2d;
	case 11570ULL: goto x86_l_2d32;
	case 11577ULL: goto x86_l_2d39;
	case 11582ULL: goto x86_l_2d3e;
	case 11587ULL: goto x86_l_2d43;
	case 11589ULL: goto x86_l_2d45;
	case 11592ULL: goto x86_l_2d48;
	case 11598ULL: goto x86_l_2d4e;
	case 11600ULL: goto x86_l_2d50;
	case 11606ULL: goto x86_l_2d56;
	case 11611ULL: goto x86_l_2d5b;
	case 11616ULL: goto x86_l_2d60;
	case 11621ULL: goto x86_l_2d65;
	case 11626ULL: goto x86_l_2d6a;
	case 11631ULL: goto x86_l_2d6f;
	case 11633ULL: goto x86_l_2d71;
	case 11636ULL: goto x86_l_2d74;
	case 11642ULL: goto x86_l_2d7a;
	case 11644ULL: goto x86_l_2d7c;
	case 11649ULL: goto x86_l_2d81;
	case 11656ULL: goto x86_l_2d88;
	case 11666ULL: goto x86_l_2d92;
	case 11671ULL: goto x86_l_2d97;
	case 11678ULL: goto x86_l_2d9e;
	case 11683ULL: goto x86_l_2da3;
	case 11688ULL: goto x86_l_2da8;
	case 11690ULL: goto x86_l_2daa;
	case 11693ULL: goto x86_l_2dad;
	case 11699ULL: goto x86_l_2db3;
	case 11701ULL: goto x86_l_2db5;
	case 11706ULL: goto x86_l_2dba;
	case 11711ULL: goto x86_l_2dbf;
	case 11719ULL: goto x86_l_2dc7;
	case 11726ULL: goto x86_l_2dce;
	case 11728ULL: goto x86_l_2dd0;
	case 11733ULL: goto x86_l_2dd5;
	case 11738ULL: goto x86_l_2dda;
	case 11743ULL: goto x86_l_2ddf;
	case 11745ULL: goto x86_l_2de1;
	case 11747ULL: goto x86_l_2de3;
	case 11752ULL: goto x86_l_2de8;
	case 11757ULL: goto x86_l_2ded;
	case 11765ULL: goto x86_l_2df5;
	case 11772ULL: goto x86_l_2dfc;
	case 11774ULL: goto x86_l_2dfe;
	case 11779ULL: goto x86_l_2e03;
	case 11784ULL: goto x86_l_2e08;
	case 11789ULL: goto x86_l_2e0d;
	case 11791ULL: goto x86_l_2e0f;
	case 11793ULL: goto x86_l_2e11;
	case 11799ULL: goto x86_l_2e17;
	case 11804ULL: goto x86_l_2e1c;
	case 11812ULL: goto x86_l_2e24;
	case 11819ULL: goto x86_l_2e2b;
	case 11821ULL: goto x86_l_2e2d;
	case 11826ULL: goto x86_l_2e32;
	case 11831ULL: goto x86_l_2e37;
	case 11836ULL: goto x86_l_2e3c;
	case 11838ULL: goto x86_l_2e3e;
	case 11840ULL: goto x86_l_2e40;
	case 11846ULL: goto x86_l_2e46;
	case 11851ULL: goto x86_l_2e4b;
	case 11859ULL: goto x86_l_2e53;
	case 11866ULL: goto x86_l_2e5a;
	case 11868ULL: goto x86_l_2e5c;
	case 11873ULL: goto x86_l_2e61;
	case 11878ULL: goto x86_l_2e66;
	case 11883ULL: goto x86_l_2e6b;
	case 11885ULL: goto x86_l_2e6d;
	case 11887ULL: goto x86_l_2e6f;
	case 11893ULL: goto x86_l_2e75;
	case 11898ULL: goto x86_l_2e7a;
	case 11906ULL: goto x86_l_2e82;
	case 11913ULL: goto x86_l_2e89;
	case 11915ULL: goto x86_l_2e8b;
	case 11920ULL: goto x86_l_2e90;
	case 11925ULL: goto x86_l_2e95;
	case 11930ULL: goto x86_l_2e9a;
	case 11932ULL: goto x86_l_2e9c;
	case 11934ULL: goto x86_l_2e9e;
	case 11939ULL: goto x86_l_2ea3;
	case 11941ULL: goto x86_l_2ea5;
	case 11949ULL: goto x86_l_2ead;
	case 11956ULL: goto x86_l_2eb4;
	case 11958ULL: goto x86_l_2eb6;
	case 11963ULL: goto x86_l_2ebb;
	case 11968ULL: goto x86_l_2ec0;
	case 11973ULL: goto x86_l_2ec5;
	case 11975ULL: goto x86_l_2ec7;
	case 11977ULL: goto x86_l_2ec9;
	case 11983ULL: goto x86_l_2ecf;
	case 11985ULL: goto x86_l_2ed1;
	case 11993ULL: goto x86_l_2ed9;
	case 12000ULL: goto x86_l_2ee0;
	case 12002ULL: goto x86_l_2ee2;
	case 12007ULL: goto x86_l_2ee7;
	case 12012ULL: goto x86_l_2eec;
	case 12017ULL: goto x86_l_2ef1;
	case 12019ULL: goto x86_l_2ef3;
	case 12021ULL: goto x86_l_2ef5;
	case 12026ULL: goto x86_l_2efa;
	case 12033ULL: goto x86_l_2f01;
	case 12037ULL: goto x86_l_2f05;
	case 12044ULL: goto x86_l_2f0c;
	case 12052ULL: goto x86_l_2f14;
	case 12057ULL: goto x86_l_2f19;
	case 12059ULL: goto x86_l_2f1b;
	case 12063ULL: goto x86_l_2f1f;
	case 12071ULL: goto x86_l_2f27;
	case 12079ULL: goto x86_l_2f2f;
	case 12084ULL: goto x86_l_2f34;
	case 12086ULL: goto x86_l_2f36;
	case 12090ULL: goto x86_l_2f3a;
	case 12094ULL: goto x86_l_2f3e;
	case 12105ULL: goto x86_l_2f49;
	case 12116ULL: goto x86_l_2f54;
	case 12127ULL: goto x86_l_2f5f;
	case 12138ULL: goto x86_l_2f6a;
	case 12149ULL: goto x86_l_2f75;
	case 12160ULL: goto x86_l_2f80;
	case 12168ULL: goto x86_l_2f88;
	case 12173ULL: goto x86_l_2f8d;
	case 12175ULL: goto x86_l_2f8f;
	case 12178ULL: goto x86_l_2f92;
	case 12185ULL: goto x86_l_2f99;
	case 12190ULL: goto x86_l_2f9e;
	case 12195ULL: goto x86_l_2fa3;
	case 12200ULL: goto x86_l_2fa8;
	case 12204ULL: goto x86_l_2fac;
	case 12210ULL: goto x86_l_2fb2;
	case 12215ULL: goto x86_l_2fb7;
	case 12217ULL: goto x86_l_2fb9;
	case 12222ULL: goto x86_l_2fbe;
	case 12227ULL: goto x86_l_2fc3;
	case 12232ULL: goto x86_l_2fc8;
	case 12237ULL: goto x86_l_2fcd;
	case 12242ULL: goto x86_l_2fd2;
	case 12247ULL: goto x86_l_2fd7;
	case 12249ULL: goto x86_l_2fd9;
	case 12254ULL: goto x86_l_2fde;
	case 12259ULL: goto x86_l_2fe3;
	case 12262ULL: goto x86_l_2fe6;
	case 12267ULL: goto x86_l_2feb;
	case 12272ULL: goto x86_l_2ff0;
	case 12277ULL: goto x86_l_2ff5;
	case 12280ULL: goto x86_l_2ff8;
	case 12285ULL: goto x86_l_2ffd;
	case 12287ULL: goto x86_l_2fff;
	case 12291ULL: goto x86_l_3003;
	case 12296ULL: goto x86_l_3008;
	case 12301ULL: goto x86_l_300d;
	case 12304ULL: goto x86_l_3010;
	case 12309ULL: goto x86_l_3015;
	case 12314ULL: goto x86_l_301a;
	case 12319ULL: goto x86_l_301f;
	case 12324ULL: goto x86_l_3024;
	case 12326ULL: goto x86_l_3026;
	case 12330ULL: goto x86_l_302a;
	case 12335ULL: goto x86_l_302f;
	case 12339ULL: goto x86_l_3033;
	case 12344ULL: goto x86_l_3038;
	case 12349ULL: goto x86_l_303d;
	case 12354ULL: goto x86_l_3042;
	case 12358ULL: goto x86_l_3046;
	case 12363ULL: goto x86_l_304b;
	case 12365ULL: goto x86_l_304d;
	case 12374ULL: goto x86_l_3056;
	case 12381ULL: goto x86_l_305d;
	case 12386ULL: goto x86_l_3062;
	case 12391ULL: goto x86_l_3067;
	case 12396ULL: goto x86_l_306c;
	case 12401ULL: goto x86_l_3071;
	case 12403ULL: goto x86_l_3073;
	case 12408ULL: goto x86_l_3078;
	case 12411ULL: goto x86_l_307b;
	case 12417ULL: goto x86_l_3081;
	case 12425ULL: goto x86_l_3089;
	case 12429ULL: goto x86_l_308d;
	case 12434ULL: goto x86_l_3092;
	case 12439ULL: goto x86_l_3097;
	case 12444ULL: goto x86_l_309c;
	case 12448ULL: goto x86_l_30a0;
	case 12453ULL: goto x86_l_30a5;
	case 12455ULL: goto x86_l_30a7;
	case 12460ULL: goto x86_l_30ac;
	case 12465ULL: goto x86_l_30b1;
	case 12469ULL: goto x86_l_30b5;
	case 12472ULL: goto x86_l_30b8;
	case 12479ULL: goto x86_l_30bf;
	case 12484ULL: goto x86_l_30c4;
	case 12489ULL: goto x86_l_30c9;
	case 12494ULL: goto x86_l_30ce;
	case 12499ULL: goto x86_l_30d3;
	case 12504ULL: goto x86_l_30d8;
	case 12508ULL: goto x86_l_30dc;
	case 12511ULL: goto x86_l_30df;
	case 12518ULL: goto x86_l_30e6;
	case 12523ULL: goto x86_l_30eb;
	case 12525ULL: goto x86_l_30ed;
	case 12529ULL: goto x86_l_30f1;
	case 12534ULL: goto x86_l_30f6;
	case 12538ULL: goto x86_l_30fa;
	case 12543ULL: goto x86_l_30ff;
	case 12548ULL: goto x86_l_3104;
	case 12552ULL: goto x86_l_3108;
	case 12557ULL: goto x86_l_310d;
	case 12559ULL: goto x86_l_310f;
	case 12561ULL: goto x86_l_3111;
	case 12569ULL: goto x86_l_3119;
	case 12573ULL: goto x86_l_311d;
	case 12578ULL: goto x86_l_3122;
	case 12582ULL: goto x86_l_3126;
	case 12587ULL: goto x86_l_312b;
	case 12592ULL: goto x86_l_3130;
	case 12597ULL: goto x86_l_3135;
	case 12601ULL: goto x86_l_3139;
	case 12606ULL: goto x86_l_313e;
	case 12608ULL: goto x86_l_3140;
	case 12612ULL: goto x86_l_3144;
	case 12617ULL: goto x86_l_3149;
	case 12622ULL: goto x86_l_314e;
	case 12625ULL: goto x86_l_3151;
	case 12630ULL: goto x86_l_3156;
	case 12635ULL: goto x86_l_315b;
	case 12640ULL: goto x86_l_3160;
	case 12645ULL: goto x86_l_3165;
	case 12647ULL: goto x86_l_3167;
	case 12651ULL: goto x86_l_316b;
	case 12656ULL: goto x86_l_3170;
	case 12660ULL: goto x86_l_3174;
	case 12665ULL: goto x86_l_3179;
	case 12670ULL: goto x86_l_317e;
	case 12675ULL: goto x86_l_3183;
	case 12679ULL: goto x86_l_3187;
	case 12684ULL: goto x86_l_318c;
	case 12686ULL: goto x86_l_318e;
	case 12690ULL: goto x86_l_3192;
	case 12695ULL: goto x86_l_3197;
	case 12699ULL: goto x86_l_319b;
	case 12704ULL: goto x86_l_31a0;
	case 12709ULL: goto x86_l_31a5;
	case 12714ULL: goto x86_l_31aa;
	case 12718ULL: goto x86_l_31ae;
	case 12723ULL: goto x86_l_31b3;
	case 12725ULL: goto x86_l_31b5;
	case 12729ULL: goto x86_l_31b9;
	case 12734ULL: goto x86_l_31be;
	case 12738ULL: goto x86_l_31c2;
	case 12743ULL: goto x86_l_31c7;
	case 12748ULL: goto x86_l_31cc;
	case 12753ULL: goto x86_l_31d1;
	case 12757ULL: goto x86_l_31d5;
	case 12762ULL: goto x86_l_31da;
	case 12764ULL: goto x86_l_31dc;
	case 12773ULL: goto x86_l_31e5;
	case 12780ULL: goto x86_l_31ec;
	case 12785ULL: goto x86_l_31f1;
	case 12790ULL: goto x86_l_31f6;
	case 12795ULL: goto x86_l_31fb;
	case 12800ULL: goto x86_l_3200;
	case 12802ULL: goto x86_l_3202;
	case 12807ULL: goto x86_l_3207;
	case 12812ULL: goto x86_l_320c;
	case 12815ULL: goto x86_l_320f;
	case 12820ULL: goto x86_l_3214;
	case 12825ULL: goto x86_l_3219;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2aea:
	/* 0x2aea: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2aef:
	/* 0x2aef: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2af6:
	/* 0x2af6: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2afb:
	/* 0x2afb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b00:
	/* 0x2b00: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b02:
	/* 0x2b02: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b05:
	/* 0x2b05: jne    2cef <generic_tracepoint_event+0x2cef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2cef;
	}
x86_l_2b0b:
	/* 0x2b0b: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_2b13:
	/* 0x2b13: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2b1a:
	/* 0x2b1a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b1c:
	/* 0x2b1c: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2b21:
	/* 0x2b21: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b26:
	/* 0x2b26: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2b2b:
	/* 0x2b2b: jmp    2e9a <generic_tracepoint_event+0x2e9a> */
	goto x86_l_2e9a;
x86_l_2b30:
	/* 0x2b30: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_2b33:
	/* 0x2b33: jmp    2efa <generic_tracepoint_event+0x2efa> */
	goto x86_l_2efa;
x86_l_2b38:
	/* 0x2b38: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b3d:
	/* 0x2b3d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2b42:
	/* 0x2b42: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b47:
	/* 0x2b47: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b4c:
	/* 0x2b4c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b4e:
	/* 0x2b4e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b51:
	/* 0x2b51: je     2e9e <generic_tracepoint_event+0x2e9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e9e;
	}
x86_l_2b57:
	/* 0x2b57: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_2b59:
	/* 0x2b59: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2b5e:
	/* 0x2b5e: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_2b65:
	/* 0x2b65: movabs rax,0x400000093 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869331ULL);
x86_l_2b6f:
	/* 0x2b6f: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2b74:
	/* 0x2b74: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2b7b:
	/* 0x2b7b: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2b80:
	/* 0x2b80: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b85:
	/* 0x2b85: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b87:
	/* 0x2b87: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b8a:
	/* 0x2b8a: jne    2cef <generic_tracepoint_event+0x2cef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2cef;
	}
x86_l_2b90:
	/* 0x2b90: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_2b98:
	/* 0x2b98: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2b9f:
	/* 0x2b9f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ba1:
	/* 0x2ba1: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ba6:
	/* 0x2ba6: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2bab:
	/* 0x2bab: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2bb0:
	/* 0x2bb0: jmp    2e9a <generic_tracepoint_event+0x2e9a> */
	goto x86_l_2e9a;
x86_l_2bb5:
	/* 0x2bb5: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2bba:
	/* 0x2bba: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2bbf:
	/* 0x2bbf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2bc4:
	/* 0x2bc4: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_2bc9:
	/* 0x2bc9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bcb:
	/* 0x2bcb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2bce:
	/* 0x2bce: je     2e40 <generic_tracepoint_event+0x2e40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e40;
	}
x86_l_2bd4:
	/* 0x2bd4: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_2bd6:
	/* 0x2bd6: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2bdb:
	/* 0x2bdb: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_2be2:
	/* 0x2be2: movabs rax,0x40000007a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869306ULL);
x86_l_2bec:
	/* 0x2bec: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2bf1:
	/* 0x2bf1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2bf8:
	/* 0x2bf8: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2bfd:
	/* 0x2bfd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c02:
	/* 0x2c02: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c04:
	/* 0x2c04: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c07:
	/* 0x2c07: je     2e1c <generic_tracepoint_event+0x2e1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e1c;
	}
x86_l_2c0d:
	/* 0x2c0d: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2c0f:
	/* 0x2c0f: movsx  r15,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_2c15:
	/* 0x2c15: jmp    2efa <generic_tracepoint_event+0x2efa> */
	goto x86_l_2efa;
x86_l_2c1a:
	/* 0x2c1a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c1f:
	/* 0x2c1f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2c24:
	/* 0x2c24: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c29:
	/* 0x2c29: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c2e:
	/* 0x2c2e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c30:
	/* 0x2c30: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c33:
	/* 0x2c33: je     2e9e <generic_tracepoint_event+0x2e9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e9e;
	}
x86_l_2c39:
	/* 0x2c39: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_2c3b:
	/* 0x2c3b: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c40:
	/* 0x2c40: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_2c47:
	/* 0x2c47: movabs rax,0x4000000a1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869345ULL);
x86_l_2c51:
	/* 0x2c51: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2c56:
	/* 0x2c56: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2c5d:
	/* 0x2c5d: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c62:
	/* 0x2c62: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c67:
	/* 0x2c67: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c69:
	/* 0x2c69: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c6c:
	/* 0x2c6c: jne    2cef <generic_tracepoint_event+0x2cef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2cef;
	}
x86_l_2c72:
	/* 0x2c72: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_2c7a:
	/* 0x2c7a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2c81:
	/* 0x2c81: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c83:
	/* 0x2c83: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c88:
	/* 0x2c88: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c8d:
	/* 0x2c8d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2c92:
	/* 0x2c92: jmp    2e9a <generic_tracepoint_event+0x2e9a> */
	goto x86_l_2e9a;
x86_l_2c97:
	/* 0x2c97: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c9c:
	/* 0x2c9c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2ca1:
	/* 0x2ca1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ca6:
	/* 0x2ca6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2cab:
	/* 0x2cab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cad:
	/* 0x2cad: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2cb0:
	/* 0x2cb0: je     2e9e <generic_tracepoint_event+0x2e9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e9e;
	}
x86_l_2cb6:
	/* 0x2cb6: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_2cb8:
	/* 0x2cb8: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2cbd:
	/* 0x2cbd: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_2cc4:
	/* 0x2cc4: movabs rax,0x40000004e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869262ULL);
x86_l_2cce:
	/* 0x2cce: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2cd3:
	/* 0x2cd3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2cda:
	/* 0x2cda: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2cdf:
	/* 0x2cdf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ce4:
	/* 0x2ce4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ce6:
	/* 0x2ce6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ce9:
	/* 0x2ce9: je     2e7a <generic_tracepoint_event+0x2e7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e7a;
	}
x86_l_2cef:
	/* 0x2cef: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2cf1:
	/* 0x2cf1: jmp    2e9e <generic_tracepoint_event+0x2e9e> */
	goto x86_l_2e9e;
x86_l_2cf6:
	/* 0x2cf6: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2cfb:
	/* 0x2cfb: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2d00:
	/* 0x2d00: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d05:
	/* 0x2d05: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2d0a:
	/* 0x2d0a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d0c:
	/* 0x2d0c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d0f:
	/* 0x2d0f: je     2ec9 <generic_tracepoint_event+0x2ec9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ec9;
	}
x86_l_2d15:
	/* 0x2d15: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_2d17:
	/* 0x2d17: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d1c:
	/* 0x2d1c: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_2d23:
	/* 0x2d23: movabs rax,0x400000065 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869285ULL);
x86_l_2d2d:
	/* 0x2d2d: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2d32:
	/* 0x2d32: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2d39:
	/* 0x2d39: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d3e:
	/* 0x2d3e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d43:
	/* 0x2d43: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d45:
	/* 0x2d45: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d48:
	/* 0x2d48: je     2ea5 <generic_tracepoint_event+0x2ea5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ea5;
	}
x86_l_2d4e:
	/* 0x2d4e: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2d50:
	/* 0x2d50: movzx  r15d,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_2d56:
	/* 0x2d56: jmp    2efa <generic_tracepoint_event+0x2efa> */
	goto x86_l_2efa;
x86_l_2d5b:
	/* 0x2d5b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d60:
	/* 0x2d60: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2d65:
	/* 0x2d65: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d6a:
	/* 0x2d6a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2d6f:
	/* 0x2d6f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d71:
	/* 0x2d71: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d74:
	/* 0x2d74: je     2ef5 <generic_tracepoint_event+0x2ef5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ef5;
	}
x86_l_2d7a:
	/* 0x2d7a: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_2d7c:
	/* 0x2d7c: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d81:
	/* 0x2d81: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_2d88:
	/* 0x2d88: movabs rax,0x400000088 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869320ULL);
x86_l_2d92:
	/* 0x2d92: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2d97:
	/* 0x2d97: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2d9e:
	/* 0x2d9e: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2da3:
	/* 0x2da3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2da8:
	/* 0x2da8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2daa:
	/* 0x2daa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2dad:
	/* 0x2dad: je     2ed1 <generic_tracepoint_event+0x2ed1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ed1;
	}
x86_l_2db3:
	/* 0x2db3: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2db5:
	/* 0x2db5: mov    r15d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2dba:
	/* 0x2dba: jmp    2efa <generic_tracepoint_event+0x2efa> */
	goto x86_l_2efa;
x86_l_2dbf:
	/* 0x2dbf: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_2dc7:
	/* 0x2dc7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2dce:
	/* 0x2dce: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2dd0:
	/* 0x2dd0: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2dd5:
	/* 0x2dd5: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2dda:
	/* 0x2dda: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2ddf:
	/* 0x2ddf: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2de1:
	/* 0x2de1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2de3:
	/* 0x2de3: movsxd r15,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_2de8:
	/* 0x2de8: jmp    2efa <generic_tracepoint_event+0x2efa> */
	goto x86_l_2efa;
x86_l_2ded:
	/* 0x2ded: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_2df5:
	/* 0x2df5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2dfc:
	/* 0x2dfc: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2dfe:
	/* 0x2dfe: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e03:
	/* 0x2e03: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e08:
	/* 0x2e08: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2e0d:
	/* 0x2e0d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e0f:
	/* 0x2e0f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e11:
	/* 0x2e11: movsx  r15,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_2e17:
	/* 0x2e17: jmp    2efa <generic_tracepoint_event+0x2efa> */
	goto x86_l_2efa;
x86_l_2e1c:
	/* 0x2e1c: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_2e24:
	/* 0x2e24: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2e2b:
	/* 0x2e2b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e2d:
	/* 0x2e2d: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e32:
	/* 0x2e32: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e37:
	/* 0x2e37: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2e3c:
	/* 0x2e3c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e3e:
	/* 0x2e3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e40:
	/* 0x2e40: movsx  r15,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_2e46:
	/* 0x2e46: jmp    2efa <generic_tracepoint_event+0x2efa> */
	goto x86_l_2efa;
x86_l_2e4b:
	/* 0x2e4b: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_2e53:
	/* 0x2e53: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2e5a:
	/* 0x2e5a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e5c:
	/* 0x2e5c: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e61:
	/* 0x2e61: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e66:
	/* 0x2e66: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2e6b:
	/* 0x2e6b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e6d:
	/* 0x2e6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e6f:
	/* 0x2e6f: movzx  r15d,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_2e75:
	/* 0x2e75: jmp    2efa <generic_tracepoint_event+0x2efa> */
	goto x86_l_2efa;
x86_l_2e7a:
	/* 0x2e7a: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_2e82:
	/* 0x2e82: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2e89:
	/* 0x2e89: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e8b:
	/* 0x2e8b: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e90:
	/* 0x2e90: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e95:
	/* 0x2e95: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2e9a:
	/* 0x2e9a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e9c:
	/* 0x2e9c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e9e:
	/* 0x2e9e: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ea3:
	/* 0x2ea3: jmp    2efa <generic_tracepoint_event+0x2efa> */
	goto x86_l_2efa;
x86_l_2ea5:
	/* 0x2ea5: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_2ead:
	/* 0x2ead: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2eb4:
	/* 0x2eb4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2eb6:
	/* 0x2eb6: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ebb:
	/* 0x2ebb: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ec0:
	/* 0x2ec0: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2ec5:
	/* 0x2ec5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ec7:
	/* 0x2ec7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ec9:
	/* 0x2ec9: movzx  r15d,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_2ecf:
	/* 0x2ecf: jmp    2efa <generic_tracepoint_event+0x2efa> */
	goto x86_l_2efa;
x86_l_2ed1:
	/* 0x2ed1: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_2ed9:
	/* 0x2ed9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2ee0:
	/* 0x2ee0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ee2:
	/* 0x2ee2: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ee7:
	/* 0x2ee7: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2eec:
	/* 0x2eec: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2ef1:
	/* 0x2ef1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ef3:
	/* 0x2ef3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ef5:
	/* 0x2ef5: mov    r15d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2efa:
	/* 0x2efa: mov    QWORD PTR [r14+0x5e70],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24176ULL);
x86_l_2f01:
	/* 0x2f01: mov    BYTE PTR [r14],0xe */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_2f05:
	/* 0x2f05: mov    WORD PTR [r14+0x2],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934592ULL);
x86_l_2f0c:
	/* 0x2f0c: mov    DWORD PTR [r14+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_2f14:
	/* 0x2f14: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_2f19:
	/* 0x2f19: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f1b:
	/* 0x2f1b: mov    QWORD PTR [r14+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f1f:
	/* 0x2f1f: mov    QWORD PTR [r14+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_2f27:
	/* 0x2f27: mov    DWORD PTR [r14+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_2f2f:
	/* 0x2f2f: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2f34:
	/* 0x2f34: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f36:
	/* 0x2f36: mov    DWORD PTR [r14+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_2f3a:
	/* 0x2f3a: mov    BYTE PTR [r14],0xe */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_2f3e:
	/* 0x2f3e: mov    QWORD PTR [r14+0x5efc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104436424769536ULL);
x86_l_2f49:
	/* 0x2f49: mov    QWORD PTR [r14+0x5eb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104144366993408ULL);
x86_l_2f54:
	/* 0x2f54: mov    QWORD PTR [r14+0x5ec0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104178726731776ULL);
x86_l_2f5f:
	/* 0x2f5f: mov    QWORD PTR [r14+0x5ec8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104213086470144ULL);
x86_l_2f6a:
	/* 0x2f6a: mov    QWORD PTR [r14+0x5ed0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104247446208512ULL);
x86_l_2f75:
	/* 0x2f75: mov    QWORD PTR [r14+0x5ed8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104281805946880ULL);
x86_l_2f80:
	/* 0x2f80: mov    BYTE PTR [r14+0x5ee0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104316165685248ULL);
x86_l_2f88:
	/* 0x2f88: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_2f8d:
	/* 0x2f8d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f8f:
	/* 0x2f8f: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2f92:
	/* 0x2f92: lea    rdx,[rax+0xd48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3400ULL);
x86_l_2f99:
	/* 0x2f99: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f9e:
	/* 0x2f9e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2fa3:
	/* 0x2fa3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2fa8:
	/* 0x2fa8: lea    r12,[r14+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2fac:
	/* 0x2fac: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_2fb2:
	/* 0x2fb2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fb7:
	/* 0x2fb7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fb9:
	/* 0x2fb9: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fbe:
	/* 0x2fbe: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2fc3:
	/* 0x2fc3: mov    edx,0x48 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 72ULL);
x86_l_2fc8:
	/* 0x2fc8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2fcd:
	/* 0x2fcd: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fd2:
	/* 0x2fd2: mov    esi,0x48 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 72ULL);
x86_l_2fd7:
	/* 0x2fd7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fd9:
	/* 0x2fd9: mov    edx,0x1a8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 424ULL);
x86_l_2fde:
	/* 0x2fde: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2fe3:
	/* 0x2fe3: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2fe6:
	/* 0x2fe6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2feb:
	/* 0x2feb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ff0:
	/* 0x2ff0: add    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_2ff5:
	/* 0x2ff5: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2ff8:
	/* 0x2ff8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2ffd:
	/* 0x2ffd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fff:
	/* 0x2fff: lea    rdi,[r14+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_3003:
	/* 0x3003: mov    edx,0x470 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1136ULL);
x86_l_3008:
	/* 0x3008: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_300d:
	/* 0x300d: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3010:
	/* 0x3010: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3015:
	/* 0x3015: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_301a:
	/* 0x301a: add    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_301f:
	/* 0x301f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3024:
	/* 0x3024: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3026:
	/* 0x3026: lea    rdi,[r14+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_302a:
	/* 0x302a: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_302f:
	/* 0x302f: add    rcx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3033:
	/* 0x3033: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_3038:
	/* 0x3038: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_303d:
	/* 0x303d: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3042:
	/* 0x3042: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3046:
	/* 0x3046: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_304b:
	/* 0x304b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_304d:
	/* 0x304d: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_3056:
	/* 0x3056: lea    rdx,[r15+0xb38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2872ULL);
x86_l_305d:
	/* 0x305d: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3062:
	/* 0x3062: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3067:
	/* 0x3067: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_306c:
	/* 0x306c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3071:
	/* 0x3071: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3073:
	/* 0x3073: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3078:
	/* 0x3078: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_307b:
	/* 0x307b: je     3111 <generic_tracepoint_event+0x3111> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3111;
	}
x86_l_3081:
	/* 0x3081: mov    DWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_3089:
	/* 0x3089: add    rcx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_308d:
	/* 0x308d: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3092:
	/* 0x3092: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3097:
	/* 0x3097: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_309c:
	/* 0x309c: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_30a0:
	/* 0x30a0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_30a5:
	/* 0x30a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30a7:
	/* 0x30a7: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_30ac:
	/* 0x30ac: movsxd rcx,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 112ULL);
x86_l_30b1:
	/* 0x30b1: shl    rcx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_30b5:
	/* 0x30b5: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_30b8:
	/* 0x30b8: add    rcx,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_30bf:
	/* 0x30bf: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_30c4:
	/* 0x30c4: mov    edx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_30c9:
	/* 0x30c9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_30ce:
	/* 0x30ce: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_30d3:
	/* 0x30d3: movsxd rdx,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 112ULL);
x86_l_30d8:
	/* 0x30d8: shl    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_30dc:
	/* 0x30dc: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_30df:
	/* 0x30df: add    rdx,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_30e6:
	/* 0x30e6: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_30eb:
	/* 0x30eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30ed:
	/* 0x30ed: lea    rdi,[r14+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_30f1:
	/* 0x30f1: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_30f6:
	/* 0x30f6: sub    rcx,0xffffffffffffff80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SUB, 18446744073709551488ULL);
x86_l_30fa:
	/* 0x30fa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_30ff:
	/* 0x30ff: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3104:
	/* 0x3104: sub    rdx,0xffffffffffffff80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SUB, 18446744073709551488ULL);
x86_l_3108:
	/* 0x3108: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_310d:
	/* 0x310d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_310f:
	/* 0x310f: jmp    3119 <generic_tracepoint_event+0x3119> */
	goto x86_l_3119;
x86_l_3111:
	/* 0x3111: mov    DWORD PTR [r14+0x2c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_3119:
	/* 0x3119: lea    rdi,[r14+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_311d:
	/* 0x311d: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3122:
	/* 0x3122: sub    rcx,0xffffffffffffff80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SUB, 18446744073709551488ULL);
x86_l_3126:
	/* 0x3126: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_312b:
	/* 0x312b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3130:
	/* 0x3130: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3135:
	/* 0x3135: sub    rdx,0xffffffffffffff80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SUB, 18446744073709551488ULL);
x86_l_3139:
	/* 0x3139: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_313e:
	/* 0x313e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3140:
	/* 0x3140: lea    rdi,[r14+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_3144:
	/* 0x3144: mov    edx,0xa8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 168ULL);
x86_l_3149:
	/* 0x3149: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_314e:
	/* 0x314e: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3151:
	/* 0x3151: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3156:
	/* 0x3156: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_315b:
	/* 0x315b: add    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_3160:
	/* 0x3160: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3165:
	/* 0x3165: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3167:
	/* 0x3167: lea    rdi,[r14+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_316b:
	/* 0x316b: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3170:
	/* 0x3170: add    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_3174:
	/* 0x3174: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_3179:
	/* 0x3179: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_317e:
	/* 0x317e: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3183:
	/* 0x3183: add    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_3187:
	/* 0x3187: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_318c:
	/* 0x318c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_318e:
	/* 0x318e: lea    rdi,[r14+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_3192:
	/* 0x3192: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3197:
	/* 0x3197: add    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_319b:
	/* 0x319b: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_31a0:
	/* 0x31a0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_31a5:
	/* 0x31a5: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_31aa:
	/* 0x31aa: add    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_31ae:
	/* 0x31ae: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_31b3:
	/* 0x31b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31b5:
	/* 0x31b5: lea    rdi,[r14+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_31b9:
	/* 0x31b9: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_31be:
	/* 0x31be: add    rcx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_31c2:
	/* 0x31c2: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_31c7:
	/* 0x31c7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_31cc:
	/* 0x31cc: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_31d1:
	/* 0x31d1: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_31d5:
	/* 0x31d5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_31da:
	/* 0x31da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31dc:
	/* 0x31dc: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_31e5:
	/* 0x31e5: lea    rdx,[r15+0xa50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2640ULL);
x86_l_31ec:
	/* 0x31ec: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31f1:
	/* 0x31f1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_31f6:
	/* 0x31f6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_31fb:
	/* 0x31fb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3200:
	/* 0x3200: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3202:
	/* 0x3202: mov    edx,0x4a0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1184ULL);
x86_l_3207:
	/* 0x3207: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_320c:
	/* 0x320c: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_320f:
	/* 0x320f: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3214:
	/* 0x3214: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3219:
	/* 0x3219: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
	return 12830ULL;
}

static __noinline __u64 tetragon_bpf_generic_tracepoint_v53_generic_tracepoint_event_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12830ULL: goto x86_l_321e;
	case 12835ULL: goto x86_l_3223;
	case 12840ULL: goto x86_l_3228;
	case 12842ULL: goto x86_l_322a;
	case 12846ULL: goto x86_l_322e;
	case 12851ULL: goto x86_l_3233;
	case 12856ULL: goto x86_l_3238;
	case 12859ULL: goto x86_l_323b;
	case 12864ULL: goto x86_l_3240;
	case 12869ULL: goto x86_l_3245;
	case 12874ULL: goto x86_l_324a;
	case 12879ULL: goto x86_l_324f;
	case 12881ULL: goto x86_l_3251;
	case 12885ULL: goto x86_l_3255;
	case 12892ULL: goto x86_l_325c;
	case 12897ULL: goto x86_l_3261;
	case 12902ULL: goto x86_l_3266;
	case 12907ULL: goto x86_l_326b;
	case 12912ULL: goto x86_l_3270;
	case 12915ULL: goto x86_l_3273;
	case 12917ULL: goto x86_l_3275;
	case 12922ULL: goto x86_l_327a;
	case 12926ULL: goto x86_l_327e;
	case 12930ULL: goto x86_l_3282;
	case 12935ULL: goto x86_l_3287;
	case 12940ULL: goto x86_l_328c;
	case 12945ULL: goto x86_l_3291;
	case 12947ULL: goto x86_l_3293;
	case 12950ULL: goto x86_l_3296;
	case 12954ULL: goto x86_l_329a;
	case 12958ULL: goto x86_l_329e;
	case 12963ULL: goto x86_l_32a3;
	case 12968ULL: goto x86_l_32a8;
	case 12973ULL: goto x86_l_32ad;
	case 12975ULL: goto x86_l_32af;
	case 12979ULL: goto x86_l_32b3;
	case 12984ULL: goto x86_l_32b8;
	case 12989ULL: goto x86_l_32bd;
	case 12992ULL: goto x86_l_32c0;
	case 12997ULL: goto x86_l_32c5;
	case 13000ULL: goto x86_l_32c8;
	case 13002ULL: goto x86_l_32ca;
	case 13007ULL: goto x86_l_32cf;
	case 13018ULL: goto x86_l_32da;
	case 13029ULL: goto x86_l_32e5;
	case 13036ULL: goto x86_l_32ec;
	case 13041ULL: goto x86_l_32f1;
	case 13046ULL: goto x86_l_32f6;
	case 13049ULL: goto x86_l_32f9;
	case 13054ULL: goto x86_l_32fe;
	case 13056ULL: goto x86_l_3300;
	case 13058ULL: goto x86_l_3302;
	case 13065ULL: goto x86_l_3309;
	case 13067ULL: goto x86_l_330b;
	case 13068ULL: goto x86_l_330c;
	default: return 0xffffffffffffffffULL;
	}
x86_l_321e:
	/* 0x321e: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3223:
	/* 0x3223: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3228:
	/* 0x3228: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_322a:
	/* 0x322a: lea    rdi,[r14+0x44] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_322e:
	/* 0x322e: mov    edx,0xe8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 232ULL);
x86_l_3233:
	/* 0x3233: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3238:
	/* 0x3238: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_323b:
	/* 0x323b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3240:
	/* 0x3240: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3245:
	/* 0x3245: add    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 104ULL);
x86_l_324a:
	/* 0x324a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_324f:
	/* 0x324f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3251:
	/* 0x3251: lea    r12,[r14+0x48] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3255:
	/* 0x3255: add    r15,0xce0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 3296ULL);
x86_l_325c:
	/* 0x325c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3261:
	/* 0x3261: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3266:
	/* 0x3266: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_326b:
	/* 0x326b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3270:
	/* 0x3270: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3273:
	/* 0x3273: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3275:
	/* 0x3275: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_327a:
	/* 0x327a: lea    rdi,[r14+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_327e:
	/* 0x327e: lea    rdx,[r15+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3282:
	/* 0x3282: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3287:
	/* 0x3287: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_328c:
	/* 0x328c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3291:
	/* 0x3291: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3293:
	/* 0x3293: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_3296:
	/* 0x3296: add    rdi,0x58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 88ULL);
x86_l_329a:
	/* 0x329a: lea    rdx,[r15+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_329e:
	/* 0x329e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_32a3:
	/* 0x32a3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_32a8:
	/* 0x32a8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32ad:
	/* 0x32ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32af:
	/* 0x32af: add    r15,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_32b3:
	/* 0x32b3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_32b8:
	/* 0x32b8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_32bd:
	/* 0x32bd: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_32c0:
	/* 0x32c0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32c5:
	/* 0x32c5: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_32c8:
	/* 0x32c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32ca:
	/* 0x32ca: mov    BYTE PTR [r14+0x1],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4294967296ULL);
x86_l_32cf:
	/* 0x32cf: mov    QWORD PTR [r14+0x5ee8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104350525423616ULL);
x86_l_32da:
	/* 0x32da: mov    QWORD PTR [r14+0x5ef0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104384885161984ULL);
x86_l_32e5:
	/* 0x32e5: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tp_calls)));
x86_l_32ec:
	/* 0x32ec: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_32f1:
	/* 0x32f1: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_32f6:
	/* 0x32f6: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_32f9:
	/* 0x32f9: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_32fe:
	/* 0x32fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3300:
	/* 0x3300: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3302:
	/* 0x3302: add    rsp,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_3309:
	/* 0x3309: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_330b:
	/* 0x330b: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_330c:
	/* 0x330c: jmp    3311 <generic_tracepoint_event+0x3311> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_tracepoint_v53_generic_tracepoint_event_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 10972U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1797ULL)
			__x86_pc = tetragon_bpf_generic_tracepoint_v53_generic_tracepoint_event_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1799ULL && __x86_pc <= 3629ULL)
			__x86_pc = tetragon_bpf_generic_tracepoint_v53_generic_tracepoint_event_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3634ULL && __x86_pc <= 5461ULL)
			__x86_pc = tetragon_bpf_generic_tracepoint_v53_generic_tracepoint_event_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5465ULL && __x86_pc <= 7311ULL)
			__x86_pc = tetragon_bpf_generic_tracepoint_v53_generic_tracepoint_event_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7319ULL && __x86_pc <= 9154ULL)
			__x86_pc = tetragon_bpf_generic_tracepoint_v53_generic_tracepoint_event_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 9159ULL && __x86_pc <= 10976ULL)
			__x86_pc = tetragon_bpf_generic_tracepoint_v53_generic_tracepoint_event_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10986ULL && __x86_pc <= 12825ULL)
			__x86_pc = tetragon_bpf_generic_tracepoint_v53_generic_tracepoint_event_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12830ULL && __x86_pc <= 13068ULL)
			__x86_pc = tetragon_bpf_generic_tracepoint_v53_generic_tracepoint_event_x86_chunk_7(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
